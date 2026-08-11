#!/usr/bin/env python3
"""Present an MWCCPS2-shaped command line but build with ee-gcc 3.2 + Ps2EeAs.

Part of P4's source is not Metrowerks code.  Functions whose retail prologue
saves callee-saved `$s` registers with `sd` rather than `sq` were compiled with
GCC, and MWCCPS2 cannot reproduce them at any optimisation level or in any of
its builds.  Those functions are byte-exact under:

    ee-gcc 3.2-030926   -O2 -G0
    Ps2EeAs             (Sony's EE assembler)

The assembler matters as much as the compiler.  GNU `as` expands the `move`
macro to `or` (0x00808025) while retail has `daddu` (0x0080802d); Ps2EeAs
expands it to `daddu`.  No compiler flag reaches this: cc1 rejects `-mabi`
and `-mgp64`, and `.set gp=64` does not change GNU as.

`mwccgap` invokes a compiler as `<path> -c <flags> -o <out.o> <in.c>`, so this
shim can be dropped in as that path with no changes to mwccgap itself.

Two environment quirks are handled here:
  * ee-gcc 3.2 is a Linux binary.  It runs under WSL, but cc1 fails with
    "Value too large for defined data type" when reading source across the
    DrvFs `/mnt/c` mount, so sources and the toolchain are staged inside the
    WSL filesystem.
  * The repository path contains spaces, which a
    `cmd.exe -> wsl.exe -> bash -c` command line cannot survive.  All quoting
    is kept inside a generated script placed at a space-free path.

Configure with, in `tools/build_config.local.json`:

    "eegcc_root":  "<dir containing bin/ and lib/ from ee-gcc3.2-030926>"
    "ps2eeas":     "<path to Ps2EeAs.exe>"

or the environment variables `P4_EEGCC_ROOT` and `P4_PS2EEAS`.
"""
from pathlib import Path
import json
import os
import shutil
import subprocess
import sys
import tempfile

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent

# A staging root without spaces, reachable from both Windows and WSL.
STAGE_WIN = Path(os.environ.get("P4_GCC_STAGE", "C:/tmp/p4gcc_shim"))
STAGE_WSL = "/mnt/" + str(STAGE_WIN).replace(":", "").replace("\\", "/").lower()[0] \
            + str(STAGE_WIN).replace("\\", "/")[2:]

# GCC needs -G0 so that small objects are not placed in .sdata; retail's
# addressing depends on it.  Flags MWCCPS2 understands but GCC does not are
# dropped rather than translated.
GCC_FLAGS = ["-O2", "-G0"]
DROP_PREFIXES = ("-lang", "-msgstyle", "-maxerrors", "-enum", "-char", "-str")


def _config() -> dict:
    cfg: dict = {}
    for name in ("build_config.json", "build_config.local.json"):
        path = TOOLS / name
        if path.is_file():
            try:
                cfg.update({k: v for k, v in json.loads(path.read_text()).items()
                            if v is not None})
            except json.JSONDecodeError:
                pass
    for key, env in (("eegcc_root", "P4_EEGCC_ROOT"), ("ps2eeas", "P4_PS2EEAS")):
        if os.environ.get(env):
            cfg[key] = os.environ[env]
    return cfg


def _die(message: str) -> "NoReturn":
    sys.stderr.write("eegcc_shim: %s\n" % message)
    raise SystemExit(1)


def _parse(argv: list[str]) -> tuple[Path, Path, list[str]]:
    out: Path | None = None
    source: Path | None = None
    includes: list[str] = []
    i = 0
    while i < len(argv):
        arg = argv[i]
        if arg == "-o":
            i += 1
            out = Path(argv[i])
        elif arg == "-c":
            pass
        elif arg.startswith("-I"):
            includes.append(arg[2:] if len(arg) > 2 else argv[i + 1])
            if len(arg) == 2:
                i += 1
        elif arg.startswith(DROP_PREFIXES):
            pass
        elif arg.endswith(".c"):
            source = Path(arg)
        i += 1
    if out is None or source is None:
        _die("expected `-c <flags> -o <out.o> <in.c>`, got: %s" % " ".join(argv))
    return source, out, includes


def _stage_toolchain(root: Path) -> None:
    """Copy the compiler to the space-free staging root once."""
    target = STAGE_WIN / "toolchain"
    if (target / "lib").is_dir():
        return
    target.mkdir(parents=True, exist_ok=True)
    for part in ("bin", "lib"):
        src = root / part
        if src.is_dir():
            shutil.copytree(src, target / part, dirs_exist_ok=True)


def _compile_to_asm(source: Path, includes: list[str], work: Path) -> Path:
    """Run ee-gcc under WSL and return the generated assembly."""
    shutil.copyfile(source, work / "in.c")
    script = work / "run.sh"
    inc = " ".join('-I"%s"' % p for p in ["/tmp/p4gcc_shim/include", *includes])
    script.write_text(
        "#!/bin/bash\n"
        "set -e\n"
        "STAGE=/tmp/p4gcc_shim\n"
        "TOOLS={wsl}/toolchain\n"
        "if [ ! -x \"$STAGE/lib/gcc-lib/ee/3.2-ee-030926/cc1\" ]; then\n"
        "    mkdir -p \"$STAGE\"\n"
        "    cp -r \"$TOOLS/bin\" \"$TOOLS/lib\" \"$STAGE/\" 2>/dev/null || true\n"
        "    chmod -R +x \"$STAGE/bin\" \"$STAGE/lib\" 2>/dev/null || true\n"
        "fi\n"
        # Headers must live inside the WSL filesystem too: cc1 cannot read
        # them across the DrvFs mount.
        "if [ ! -d \"$STAGE/include\" ]; then\n"
        "    cp -r {wsl}/include \"$STAGE/include\"\n"
        "fi\n"
        "cp {wsl}/{work}/in.c \"$STAGE/in.c\"\n"
        "cd \"$STAGE\"\n"
        "./bin/ee-gcc {flags} {inc} -S in.c -o out.s\n"
        "cp out.s {wsl}/{work}/out.s\n".format(
            wsl=STAGE_WSL, work=work.name, flags=" ".join(GCC_FLAGS), inc=inc),
        newline="\n",
    )
    proc = subprocess.run(
        ["cmd.exe", "/c", "wsl.exe", "-d", "Debian", "-e", "bash",
         "%s/%s/run.sh" % (STAGE_WSL, work.name)],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
    )
    asm = work / "out.s"
    if proc.returncode != 0 or not asm.is_file():
        _die("ee-gcc failed for %s:\n%s" % (source, proc.stdout))
    return asm


def main() -> int:
    cfg = _config()
    root = cfg.get("eegcc_root")
    ps2eeas = cfg.get("ps2eeas")
    if not root or not ps2eeas:
        _die("set eegcc_root and ps2eeas in tools/build_config.local.json "
             "(or P4_EEGCC_ROOT / P4_PS2EEAS)")

    source, out, includes = _parse(sys.argv[1:])
    STAGE_WIN.mkdir(parents=True, exist_ok=True)
    _stage_toolchain(Path(root))

    # The repo's headers must be visible from inside WSL; copy them next to the
    # staged toolchain so no DrvFs path is needed during compilation.
    staged_inc = STAGE_WIN / "include"
    if not staged_inc.is_dir():
        shutil.copytree(REPO / "include", staged_inc, dirs_exist_ok=True)

    with tempfile.TemporaryDirectory(dir=STAGE_WIN) as tmp:
        work = Path(tmp)
        asm = _compile_to_asm(source, [], work)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.unlink(missing_ok=True)
        proc = subprocess.run(
            [str(ps2eeas), str(asm), "-o", str(out)],
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
        )
        if proc.returncode != 0 or not out.is_file():
            _die("Ps2EeAs failed for %s:\n%s" % (source, proc.stdout))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

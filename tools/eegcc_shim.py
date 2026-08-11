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
import re
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
# -ffunction-sections mirrors MWCC's one-section-per-function output, which
# build.py's per-function placement depends on.
GCC_FLAGS = ["-O2", "-G0", "-ffunction-sections"]
DROP_PREFIXES = ("-lang", "-msgstyle", "-maxerrors", "-enum", "-char", "-str")
INCLUDE_REGEX = re.compile(r'\s*(INCLUDE_ASM|INCLUDE_RODATA)\("([^"]+)",\s*([^)]+)\)')


def _config() -> dict:
    cfg: dict = {}
    for name in ("verify_config.json", "verify_config.local.json",
                 "build_config.json", "build_config.local.json"):
        path = TOOLS / name
        if path.is_file():
            try:
                cfg.update({k: v for k, v in json.loads(path.read_text()).items()
                            if v is not None})
            except json.JSONDecodeError:
                pass
    for key, env in (("eegcc_root", "P4_EEGCC_ROOT"), ("as_path", "P4_AS")):
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


# asm/macro.inc is written for the GNU assembler's .macro facility.  Rather
# than rely on Ps2EeAs implementing it, the handful of macros are expanded
# here.  `glabel` additionally gains a `.size`: verify.py locates a function by
# symbol size, and a bare `.global`/label pair leaves it zero.
LABEL_MACROS = re.compile(r"^\s*(glabel|dlabel|alabel|jlabel|endlabel)\s+(\S+)")
DROP_MACROS = re.compile(r"^\s*(nonmatching|matching)\b")
SIZE_REGEX = re.compile(r"^\s*\.size\s+(\S+?)\s*,", re.M)
TEXT_SECTION = re.compile(r"^\s*\.section\s+\.text\s*$")


def _expand_asm(text: str) -> str:
    out: list[str] = []
    current: str | None = None

    def close() -> None:
        # Some extracted files carry their own explicit `.size`; only supply
        # one where it is missing, or the symbol ends up declared twice.
        nonlocal current
        if current is not None and not SIZE_OF.get(current):
            out.append(".size %s, .-%s" % (current, current))
        current = None

    SIZE_OF = {name: True for name in SIZE_REGEX.findall(text)}
    for line in text.splitlines():
        if DROP_MACROS.match(line) or TEXT_SECTION.match(line):
            continue
        match = LABEL_MACROS.match(line)
        if not match:
            out.append(line)
            continue
        macro, label = match.group(1), match.group(2)
        if macro == "endlabel":
            continue
        if macro in ("glabel", "dlabel"):
            close()
            # One section per function, matching what MWCC emits and what
            # build.py's placement requires: it addresses each function
            # individually in the linker command file, so two functions
            # sharing a section cannot be placed.
            out.append(".section .text.%s, \"ax\", @progbits" % label)
            out.append(".global %s" % label)
            if macro == "glabel":
                current = label
        out.append("%s:" % label)
    close()
    return "\n".join(out)


def _wrap(body: list[str]) -> list[str]:
    """Wrap assembly text as a file-scope GCC asm statement.

    File-scope asm is emitted verbatim, in source order, into the assembly
    ee-gcc produces -- so the object keeps retail's function layout.
    """
    lines = ["__asm__("]
    for line in body:
        lines.append('"%s\\n"' % line.replace("\\", "\\\\").replace('"', '\\"'))
    # Hand-written assembly manages delay slots and $at itself; the compiler's
    # own output does not, so the assembler defaults are put back afterwards.
    lines += ['".set reorder\\n"', '".set at\\n"', ");"]
    return lines


def _asm_block(path: Path) -> list[str]:
    """One INCLUDE_ASM body, spliced in place of the macro.

    mwccgap cannot be used for these units: it splices through MWCC's
    `asm void f() {}` extension, which GCC does not accept.
    """
    return _wrap(_expand_asm(path.read_text(encoding="utf-8")).splitlines())


# MWCC's inline-assembly function definition, used in this codebase for
# syscall wrappers and other hand-written ABI code.  GCC has no equivalent
# construct, so the body is re-emitted as file-scope assembly.
ASM_FUNCTION = re.compile(r"^asm\s+(?:\w+\s+)*?\**(\w+)\s*\(")


def _asm_function(name: str, body: list[str]) -> list[str]:
    return _wrap([
        '.section .text.%s, "ax", @progbits' % name,
        ".global %s" % name,
        "%s:" % name,
        *body,
        ".size %s, .-%s" % (name, name),
    ])


def _splice(source: Path) -> str:
    """Rewrite the constructs GCC cannot read: INCLUDE_ASM and `asm` bodies."""
    out: list[str] = []
    lines = source.read_text(encoding="utf-8").splitlines()
    index = 0
    while index < len(lines):
        line = lines[index]
        index += 1
        match = INCLUDE_REGEX.match(line)
        if match:
            path = REPO / match.group(2) / (match.group(3) + ".s")
            if not path.is_file():
                _die("%s:%d includes missing assembly %s" % (source, index, path))
            out += _asm_block(path)
            continue
        function = ASM_FUNCTION.match(line)
        if not function:
            out.append(line)
            continue
        while index < len(lines) and lines[index].strip() != "{":
            index += 1
        body, depth = [], 1
        index += 1
        while index < len(lines) and depth:
            if lines[index].strip() == "}":
                depth -= 1
            else:
                body.append(lines[index])
            index += 1
        if depth:
            _die("%s: unterminated asm function %s" % (source, function.group(1)))
        out += _asm_function(function.group(1), body)
    return "\n".join(out) + "\n"


def _compile_to_asm(source: Path, includes: list[str], work: Path) -> Path:
    """Run ee-gcc under WSL and return the generated assembly.

    Everything the compiler reads is staged inside the WSL filesystem: this
    cc1 fails with "Value too large for defined data type" reading source
    across the /mnt/c DrvFs mount.
    """
    (work / "in.c").write_text(_splice(source), encoding="utf-8", newline="\n")
    staged = []
    for index, directory in enumerate(includes):
        path = Path(directory)
        if not path.is_absolute():
            path = REPO / path
        if not path.is_dir():
            _die("include directory does not exist: %s" % directory)
        target = work / ("inc%d" % index)
        shutil.copytree(path, target, dirs_exist_ok=True)
        staged.append(index)
    script = work / "run.sh"
    here = "%s/%s" % (STAGE_WSL, work.name)
    lines = [
        "#!/bin/bash",
        "set -e",
        "STAGE=/tmp/p4gcc_shim",
        "if [ ! -x \"$STAGE/bin/ee-gcc\" ]; then",
        "    mkdir -p \"$STAGE\"",
        "    cp -r %s/toolchain/bin %s/toolchain/lib \"$STAGE/\"" % (
            STAGE_WSL, STAGE_WSL),
        "    chmod -R +x \"$STAGE/bin\" \"$STAGE/lib\"",
        "fi",
    ]
    for index in staged:
        lines += ["rm -rf \"$STAGE/inc%d\"" % index,
                  "cp -r %s/inc%d \"$STAGE/inc%d\"" % (here, index, index)]
    lines += [
        "cp %s/in.c \"$STAGE/in.c\"" % here,
        "cd \"$STAGE\"",
        "./bin/ee-gcc %s %s -S in.c -o out.s" % (
            " ".join(GCC_FLAGS),
            " ".join("-I$STAGE/inc%d" % index for index in staged)),
        "cp out.s %s/out.s" % here,
    ]
    script.write_text("\n".join(lines) + "\n", newline="\n")
    proc = subprocess.run(
        ["cmd.exe", "/c", "wsl.exe", "-d", "Debian", "-e", "bash",
         "%s/%s/run.sh" % (STAGE_WSL, work.name)],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
    )
    asm = work / "out.s"
    if proc.returncode != 0 or not asm.is_file():
        _die("ee-gcc failed for %s:\n%s" % (source, proc.stdout))
    return asm


# The one place GNU as and Sony's Ps2EeAs disagree on this codebase: `move`.
# GNU expands it to `or rd, rs, $0` (0x00808025); retail has `daddu rd, rs, $0`
# (0x0080802d), which is what Ps2EeAs emits.  Rewriting the macro here keeps a
# single assembler for the whole file.  Ps2EeAs cannot take its place: it pads
# R5900 branch-after-jump hazards a second time in already-padded extracted
# assembly, displacing every branch that follows.
MOVE_REGEX = re.compile(r"^(\s*)move\s+(\$\w+)\s*,\s*(\$\w+)\s*$")


def _rewrite_moves(asm: Path) -> None:
    text = asm.read_text(encoding="utf-8", errors="replace")
    out = [MOVE_REGEX.sub(r"\1daddu\t\2,\3,$0", line)
           for line in text.splitlines()]
    asm.write_text("\n".join(out) + "\n", encoding="utf-8", newline="\n")


# MWCC objects carry none of these, and mwldps2 rejects an object whose
# sections the linker command file does not place.  The empty .text/.data/.bss
# placeholders and GCC's own metadata are dropped so a GCC unit presents the
# same shape to the linker as a Metrowerks one.
GCC_ONLY_SECTIONS = (".text", ".data", ".bss", ".reginfo", ".MIPS.abiflags",
                     ".pdr", ".mdebug.eabi64", ".gnu.attributes")
GCC_ONLY_SYMBOLS = ("gcc2_compiled.", "__gnu_compiled_c")


def _strip_gcc_metadata(objcopy: str, obj: Path) -> None:
    argv = [str(objcopy)]
    argv += ["--remove-section=%s" % name for name in GCC_ONLY_SECTIONS]
    argv += ["--strip-symbol=%s" % name for name in GCC_ONLY_SYMBOLS]
    proc = subprocess.run([*argv, str(obj)], stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT, text=True)
    if proc.returncode != 0:
        _die("objcopy failed for %s:\n%s" % (obj, proc.stdout))


def main() -> int:
    cfg = _config()
    root = cfg.get("eegcc_root")
    as_path = cfg.get("as_path") or cfg.get("p4_as")
    objcopy = cfg.get("objcopy") or cfg.get("p4_objcopy")
    if not root or not as_path or not objcopy:
        _die("set eegcc_root in tools/build_config.local.json "
             "(or P4_EEGCC_ROOT), and as_path / objcopy alongside it")

    source, out, includes = _parse(sys.argv[1:])
    STAGE_WIN.mkdir(parents=True, exist_ok=True)
    _stage_toolchain(Path(root))

    with tempfile.TemporaryDirectory(dir=STAGE_WIN) as tmp:
        work = Path(tmp)
        asm = _compile_to_asm(source, includes, work)
        _rewrite_moves(asm)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.unlink(missing_ok=True)
        proc = subprocess.run(
            [str(as_path), "-EL", "-march=r5900", str(asm), "-o", str(out)],
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
        )
        if proc.returncode != 0 or not out.is_file():
            _die("assembler failed for %s:\n%s" % (source, proc.stdout))
        _strip_gcc_metadata(objcopy, out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

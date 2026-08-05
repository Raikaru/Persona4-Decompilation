#!/usr/bin/env python3
"""Dump a retail function as assembly and optionally upload it to decomp.me.

Two uses:

  * `--asm` prints the retail window as decomp.me-ready MIPS assembly, which is
    also the fastest way to read what a function actually does.
  * `--upload` creates a scratch so a stuck function can be shared, and so OTHER
    compilers can be tried against it. That second part turned out to matter a
    lot: two families this repo had documented as MWCCPS2 "compiler floors" are
    byte-exact under **ee-gcc**, which means they were never Metrowerks code.
    P4 is a mixed-toolchain build.

Notes that cost time to find:
  * decomp.me sits behind Cloudflare. A `User-Agent: decomp-permuter` header gets
    through; a default urllib or curl UA does not.
  * The API is Django REST Framework, so it returns the browsable HTML page unless
    the URL carries `?format=json`. An `Accept` header is not enough.
  * `PATCH` on an unclaimed scratch is 403, so the source has to be correct at
    creation time.
  * objdump prints bare register names and numeric branch targets; decomp.me's
    assembler needs `$`-prefixed registers and real labels.
  * A RELOCATED reference comes out as a raw immediate here (`lui $v1,0x71` plus
    `lw $v0,19516($v1)`) because the retail bytes carry no relocation. A compiler
    emits `%hi(sym)`/`%lo(sym)` against a symbol instead, and decomp.me scores that
    pair as a small difference: an otherwise byte-exact answer lands on 10, not 0.
    Rewrite those two lines symbolically by hand when you want a clean zero.

Usage:
  python tools/decompme.py --asm 004c3410
  python tools/decompme.py --upload 004c3410 --source my_body.c --context ctx.h
  python tools/decompme.py --compilers ps2
  python tools/decompme.py --try 004c3410 --source body.c --context ctx.h \
      --against ee-gcc2.96,ee-gcc2.9-991111,mwcps2-3.0.1b210-060308
"""
from pathlib import Path
import argparse
import json
import re
import subprocess
import sys
import urllib.parse
import urllib.request

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import verify  # noqa: E402

API = "https://decomp.me"
UA = {"User-Agent": "decomp-permuter"}
OUR_COMPILER = "mwcps2-3.0.1b210-060308"

REGS = (["zero", "at", "v0", "v1"] + [f"a{i}" for i in range(4)] +
        [f"t{i}" for i in range(8)] + [f"s{i}" for i in range(8)] +
        ["t8", "t9", "k0", "k1", "gp", "sp", "fp", "s8", "ra"] +
        [f"f{i}" for i in range(32)] + [f"vf{i}" for i in range(32)] + ["hi", "lo"])
REG_RE = re.compile(r"(?<![\w$.])(" + "|".join(sorted(REGS, key=len, reverse=True)) + r")(?![\w])")


def _retail():
    cfg = verify.load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    target = json.loads((REPO / "config" / "target.json").read_text())
    return verify.RetailElf(cfg["retail_elf"], target, sizes["sha1"]), sizes


def retail_asm(addr):
    """Return the retail window at `addr` as decomp.me-ready assembly."""
    retail, sizes = _retail()
    window = sizes["windows"].get(addr)
    if not window:
        sys.exit(f"decompme: no canonical window for {addr}")
    data = retail.bytes_at(int(addr, 16), window)
    while len(data) > 4 and data[-4:] == b"\0\0\0\0":
        data = data[:-4]                      # drop inter-function padding
    tmp = Path(REPO / "build" / f"decompme_{addr}.bin")
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_bytes(data)
    wsl = "/mnt/" + str(tmp).replace(":", "").replace("\\", "/").replace("C", "c", 1)
    out = subprocess.run(["wsl", "mipsel-linux-gnu-objdump", "-D", "-b", "binary",
                          "-m", "mips:5900", "-EL", f"--adjust-vma=0x{addr}", wsl],
                         capture_output=True, text=True).stdout
    rows = []
    for line in out.splitlines():
        if ":\t" not in line:
            continue
        parts = line.split("\t")
        if len(parts) < 3:
            continue
        rows.append([int(parts[0].strip().rstrip(":"), 16),
                     " ".join(x.strip() for x in parts[2:])])
    if not rows:
        sys.exit("decompme: objdump produced nothing (is WSL binutils present?)")
    # ONLY a branch or jump has a code target. `lui $v1,0x71` also ends in hex, and
    # treating that as a label turns the immediate into garbage.
    BRANCH = re.compile(r"^(b|beq|bne|beqz|bnez|blez|bgtz|bltz|bgez|bc\w*|"
                        r"beql|bnel|blezl|bgtzl|bltzl|bgezl|j|jal)\b")
    def _target(text):
        if not BRANCH.match(text.strip()):
            return None
        m = re.search(r"0x([0-9a-f]+)\s*$", text)
        return int(m.group(1), 16) if m else None
    targets = {t for _, text in rows for t in [_target(text)] if t is not None}
    lines = [f"glabel func_{addr}"]
    for off, text in rows:
        if off in targets:
            lines.append(f".L{off:08X}:")
        tgt = _target(text)
        if tgt is not None and tgt in targets:
            m = re.search(r"0x([0-9a-f]+)\s*$", text)
            text = text[:m.start()] + f".L{tgt:08X}"
        lines.append("  " + REG_RE.sub(r"$\1", text))
    for t in sorted(targets):
        if t > rows[-1][0]:
            lines.append(f".L{t:08X}:")
    return "\n".join(lines) + "\n"


def _get(path):
    req = urllib.request.Request(f"{API}{path}", headers=UA)
    with urllib.request.urlopen(req) as f:
        return json.loads(f.read())


def compilers(platform=None):
    comps = _get("/api/compiler?format=json")["compilers"]
    if platform:
        comps = {k: v for k, v in comps.items()
                 if str(v.get("platform", "")).lower() == platform.lower()}
    return sorted(comps)


def create(name, asm, source, context, compiler=OUR_COMPILER, flags="-O2", label=None):
    post = urllib.parse.urlencode({
        "name": name, "target_asm": asm, "context": context, "source_code": source,
        "compiler": compiler, "compiler_flags": flags, "diff_label": label or name,
    }).encode("ascii")
    req = urllib.request.Request(f"{API}/api/scratch?format=json", data=post, headers=UA)
    with urllib.request.urlopen(req) as f:
        return json.loads(f.read())


def score(slug, source, context, compiler, flags="-O2"):
    """Compile `source` in an existing scratch; return (score, errors)."""
    body = json.dumps({"compiler": compiler, "compiler_flags": flags,
                       "source_code": source, "context": context}).encode()
    req = urllib.request.Request(f"{API}/api/scratch/{slug}/compile?format=json",
                                 data=body,
                                 headers={**UA, "Content-Type": "application/json"})
    try:
        with urllib.request.urlopen(req) as f:
            d = json.loads(f.read())
    except Exception as e:
        return (None, f"{type(e).__name__}: {e}")
    return ((d.get("diff_output") or {}).get("current_score"),
            (d.get("errors") or "").strip())


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--asm", metavar="ADDR")
    ap.add_argument("--upload", metavar="ADDR")
    ap.add_argument("--try", dest="probe", metavar="ADDR")
    ap.add_argument("--source", type=Path)
    ap.add_argument("--context", type=Path)
    ap.add_argument("--compilers", metavar="PLATFORM", nargs="?", const="ps2")
    ap.add_argument("--against", help="comma-separated compiler ids")
    ap.add_argument("--flags", default="-O2")
    ap.add_argument("--name")
    args = ap.parse_args()

    if args.compilers:
        for c in compilers(args.compilers):
            print(c)
        return 0
    if args.asm:
        print(retail_asm(args.asm.lower()), end="")
        return 0

    addr = (args.upload or args.probe)
    if not addr:
        ap.error("one of --asm, --upload, --try, --compilers is required")
    addr = addr.lower()
    if not args.source:
        ap.error("--source is required for --upload/--try")
    source = args.source.read_text()
    context = args.context.read_text() if args.context else ""
    asm = retail_asm(addr)
    d = create(args.name or f"P4 func_{addr}", asm, source, context,
               flags=args.flags, label=f"func_{addr}")
    slug = d.get("slug")
    if not slug:
        print("server error:", d)
        return 1
    print(f"scratch: {API}/scratch/{slug}")
    if d.get("claim_token"):
        print(f"claim:   {API}/scratch/{slug}/claim?token={d['claim_token']}")
    against = ([c.strip() for c in args.against.split(",")] if args.against
               else [OUR_COMPILER])
    for c in against:
        sc, err = score(slug, source, context, c, args.flags)
        note = "  MATCH" if sc == 0 else ""
        print(f"  {c:28} score={sc}{note}  {err[:70]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

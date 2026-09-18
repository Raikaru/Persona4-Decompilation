#!/usr/bin/env python3
"""Second-opinion decompiler: run romwright's native p-code decompiler.

`tools/m2c_decompile.py` stays the primary source for a first reconstruction --
it emits MIPS-flavoured C with the project's own declarations in scope.  It has
two blind spots that have each cost a session:

  * it gives up on some jump tables (`m2c single fails on jr/jtbl`), and
  * it does not recover stack aggregate sizes, so an unexplained retail stack
    gap reads as noise instead of as a declared array.

romwright is a native Rust port of the Ghidra decompiler and fails in different
places, which is what makes it useful as a second opinion.  Its `export-c`
mode emits **m2c-shaped C**: gp-relative globals already spelled the way this
tree spells them (`fGpffff82b4`), `extern` declarations for every callee, and
`temp_vN` locals.  It also recovers the whole stack frame with array extents
(`float afStack_bb0 [192]`), which is direct evidence for the "an unexplained
retail stack gap is a real declared object" rule.

Read it alongside m2c; do not transcribe it.  Its type widths are inferred,
not observed: on three functions whose real signatures are known from MATCHes
it got the arity right every time and the exact widths wrong more often than
not, so retail evidence always wins.

The program must be imported once before any query:

    python tools/romwright_decompile.py --import

That takes about three minutes and writes to the project directory (default
`build/romwright`, which is gitignored).  Afterwards:

    python tools/romwright_decompile.py func_0016a110            # m2c-shaped C
    python tools/romwright_decompile.py func_0016a110 --raw      # Ghidra-shaped
    python tools/romwright_decompile.py func_0016a110 --types    # signature only
    python tools/romwright_decompile.py func_0016a110 -o /var/tmp/x/rw.c

`--types` prints the inferred signature and the structural field layout of each
pointer parameter (`*struct{+0x0: float32, +0x4: float32, +0x8: float32}` is an
`RwV3d *`), which feeds the declare-at-retail's-width rule in section 7g of the
matching handoff.

Set `ROMWRIGHT_CLI` if the binary is not on PATH and not at the default
location.  The tool is optional: nothing in the build or the gate depends on
it, and it exits with an explanation when the binary is missing.
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import tempfile
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
DEFAULT_PROJECT = REPO / "build" / "romwright"
PROGRAM = "p4usa"
DEFAULT_CLI = Path.home() / "ventris" / "target" / "release" / "romwright-cli"


def _cli() -> str:
    override = os.environ.get("ROMWRIGHT_CLI")
    if override:
        return override
    found = shutil.which("romwright-cli")
    if found:
        return found
    if DEFAULT_CLI.is_file():
        return str(DEFAULT_CLI)
    sys.exit(
        "romwright-cli not found. Build it (cargo build --release -p romwright-cli\n"
        "in the ventris checkout), put it on PATH, or set ROMWRIGHT_CLI to its path.\n"
        "This tool is optional; tools/m2c_decompile.py does not need it."
    )


def _retail_elf() -> str:
    sys.path.insert(0, str(TOOLS))
    from verify import load_config  # noqa: PLC0415 - optional dependency path

    return load_config()["retail_elf"]


def _address(target: str) -> str:
    text = target[5:] if target.startswith("func_") else target
    return f"0x{int(text, 16):08x}"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("function", nargs="?", help="func_<addr> or a hex address")
    parser.add_argument("--import", dest="do_import", action="store_true",
                        help="import the retail image (run once, ~3 minutes)")
    parser.add_argument("--raw", action="store_true",
                        help="Ghidra-shaped output instead of the m2c-shaped export")
    parser.add_argument("--types", action="store_true",
                        help="print inferred signature and parameter field layouts")
    parser.add_argument("--project", default=str(DEFAULT_PROJECT))
    parser.add_argument("-o", "--output", help="write the decompilation here")
    args = parser.parse_args()

    cli, elf = _cli(), _retail_elf()
    project = Path(args.project)
    project.mkdir(parents=True, exist_ok=True)

    if args.do_import:
        completed = subprocess.run(
            [cli, "import", elf, "--name", PROGRAM, "--project", str(project)],
            text=True, capture_output=True)
        sys.stdout.write(completed.stdout)
        sys.stderr.write(completed.stderr)
        sys.exit(completed.returncode)

    if not args.function:
        parser.error("give a function, or --import to build the program database")
    if not any(project.iterdir()):
        sys.exit(f"{project} is empty; run: {sys.argv[0]} --import")

    address = _address(args.function)

    if args.types:
        completed = subprocess.run(
            [cli, "infer-types", elf, PROGRAM, address, "--project", str(project), "--json"],
            text=True, capture_output=True)
        if completed.returncode != 0:
            sys.stderr.write(completed.stderr)
            sys.exit(completed.returncode)
        inferred = json.loads(completed.stdout)
        print(f"signature: {inferred.get('signature')}")
        print(f"instructions: {inferred.get('instructions')}  returns: {inferred.get('returns')}")
        floats = [value for value in inferred.get("float_parameters", []) if value != "unknown"]
        if floats:
            print(f"float parameters: {', '.join(floats)}")
        for index, shape in enumerate(inferred.get("structural", [])):
            if shape != "unknown":
                print(f"  arg{index}: {shape}")
        return

    if args.raw:
        completed = subprocess.run(
            [cli, "decompile", elf, address, "--name", PROGRAM, "--project", str(project)],
            text=True, capture_output=True)
        if completed.returncode != 0:
            sys.stderr.write(completed.stderr)
            sys.exit(completed.returncode)
        text = completed.stdout
    else:
        # export-c writes <SYMBOL>.c into a directory and prints a JSON report
        # naming every callee whose prototype it had to guess; that list is
        # worth reading before trusting an argument.
        with tempfile.TemporaryDirectory() as outdir:
            completed = subprocess.run(
                [cli, "export-c", elf, PROGRAM, outdir, "--address", address.removeprefix("0x"),
                 "--project", str(project)],
                text=True, capture_output=True)
            if completed.returncode != 0:
                sys.stderr.write(completed.stderr)
                sys.exit(completed.returncode)
            produced = sorted(Path(outdir).glob("*.c"))
            if not produced:
                sys.stderr.write(completed.stdout)
                sys.exit(f"export-c produced no file for {address}")
            text = produced[0].read_text()
        for note in _supplied_declaration_notes(completed.stdout):
            print(f"/* romwright could not type {note}; check its prototype */")

    if args.output:
        Path(args.output).write_text(text)
        print(f"wrote {args.output} ({len(text.splitlines())} lines)")
    else:
        sys.stdout.write(text)


def _supplied_declaration_notes(report: str) -> list[str]:
    try:
        parsed = json.loads(report)
    except json.JSONDecodeError:
        return []
    notes = []
    for entry in parsed.get("diagnostics", []) or []:
        message = entry.get("message", "")
        if "needs a supplied function prototype" in message:
            notes.append(message.split()[1])
    return notes


if __name__ == "__main__":
    main()

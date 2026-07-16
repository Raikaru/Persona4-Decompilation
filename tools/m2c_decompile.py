#!/usr/bin/env python3
"""Run pinned m2c on one retail function with project C context."""
from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
LABEL_RE = re.compile(r"^\s*(?:glabel|dlabel)\s+(\S+)")


def find_m2c(explicit: Path | None) -> Path:
    candidates: list[Path] = []
    if explicit is not None:
        candidates.append(explicit)
    if os.environ.get("M2C"):
        candidates.append(Path(os.environ["M2C"]))
    candidates.append(REPO / "tools" / "vendor" / "m2c" / "m2c.py")
    executable = shutil.which("m2c")
    if executable:
        candidates.append(Path(executable))
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    raise SystemExit(
        "m2c is not installed; run `make m2c-setup`, or set M2C to m2c.py"
    )


def preprocess_context(c_file: Path, output: Path, explicit: str | None) -> None:
    preprocessor = explicit or os.environ.get("M2C_CPP")
    if preprocessor is None:
        preprocessor = shutil.which("clang") or shutil.which("cpp")
    if preprocessor is None:
        raise SystemExit(
            "no C preprocessor found; install clang/cpp or set M2C_CPP"
        )
    command = [
        preprocessor,
        "-E",
        "-P",
        "-nostdinc",
        "-I",
        str(REPO / "include"),
        "-I",
        str(REPO),
        str(c_file),
        "-o",
        str(output),
    ]
    subprocess.run(command, cwd=REPO, check=True)
    context = output.read_text(errors="replace")
    context = re.sub(r"\(\s*\.\.\.\s*\)", "()", context)
    output.write_text(context)


def extract_function(function: str, asm_files: list[Path], output: Path) -> Path:
    body: list[str] = []
    found = False
    for asm_file in asm_files:
        with asm_file.open(errors="replace") as source:
            for line in source:
                label = LABEL_RE.match(line)
                if not found:
                    if label and label.group(1) == function:
                        found = True
                        body.append(line)
                    continue
                if label:
                    break
                body.append(line)
        if found:
            break
    if not found:
        searched = ", ".join(
            str(path.relative_to(REPO)) if path.is_relative_to(REPO) else str(path)
            for path in asm_files
        )
        raise SystemExit(f"function {function!r} was not found in {searched}")

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(".set noat\n.set noreorder\n.text\n" + "".join(body))
    return output


def run(args: argparse.Namespace) -> Path:
    c_file = args.c_file.resolve()
    if not c_file.is_file():
        raise SystemExit(f"C source does not exist: {c_file}")

    asm_files = [path.resolve() for path in args.asm]
    if not asm_files:
        asm_files = sorted((REPO / "asm").glob("code*.s"))
    if not asm_files:
        raise SystemExit("no split assembly found; run `make split` first")

    work_dir = REPO / "build" / "m2c"
    work_dir.mkdir(parents=True, exist_ok=True)
    context = work_dir / f"{args.function}.ctx.c"
    assembly = work_dir / f"{args.function}.s"
    output = args.output.resolve() if args.output else work_dir / f"{args.function}.c"

    preprocess_context(c_file, context, args.cpp)
    extract_function(args.function, asm_files, assembly)

    m2c = find_m2c(args.m2c)
    command = [
        sys.executable if m2c.suffix == ".py" else str(m2c),
        *([str(m2c)] if m2c.suffix == ".py" else []),
        "--target",
        "mipsee-mwcc-c",
        "--context",
        str(context),
        "--globals=used",
        "-f",
        args.function,
    ]
    if args.stack_structs:
        command.append("--stack-structs")
    command.append(str(assembly))

    result = subprocess.run(
        command,
        cwd=REPO,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    if result.returncode:
        sys.stderr.write(result.stdout)
        sys.stderr.write(result.stderr)
        raise SystemExit(result.returncode)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(result.stdout)
    if result.stderr:
        sys.stderr.write(result.stderr)
    print(f"wrote {output}")
    return output


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("c_file", type=Path, help="source file supplying declarations")
    parser.add_argument("function", help="assembly label to decompile")
    parser.add_argument("-o", "--output", type=Path)
    parser.add_argument("--asm", type=Path, action="append", default=[])
    parser.add_argument("--m2c", type=Path, help="path to an external m2c.py or executable")
    parser.add_argument("--cpp", help="C preprocessor command (or set M2C_CPP)")
    parser.add_argument("--stack-structs", action="store_true")
    run(parser.parse_args())


if __name__ == "__main__":
    main()

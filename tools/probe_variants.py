#!/usr/bin/env python3
"""Try source spellings in isolated translation-unit copies.

Matching a function is a search over source spellings that all mean the same
thing but compile differently.  This runs the candidates in one go and prints
the reloc-masked differing-word count for each, so the choice is measured
rather than argued.

Candidates are whole function definitions (the marker line is supplied by the
source file).  The complete translation unit is copied to a temporary file
beside the source before each candidate is measured.  That keeps quoted local
includes and file-scope/static declarations in the same context as the real
unit, while the source file itself is never written.

    python tools/probe_variants.py src/cmmMisc.c func_00246940 \
        --candidate a=/tmp/a.c --candidate b=/tmp/b.c

The exit status is 0 if at least one candidate reached zero differing words,
otherwise 1.  A matching candidate is reported but never installed.
"""

from __future__ import annotations
import argparse
from contextlib import contextmanager, redirect_stderr, redirect_stdout
import io
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))

import verify  # noqa: E402


MARKER_RE = re.compile(r"^[ \t]*//\s*(FUN_[0-9A-Fa-f]{8})\b")
INCLUDE_CODE_RE = re.compile(
    r"^[ \t]*INCLUDE_ASM\s*\(\s*.*,\s*"
    r"(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*\)\s*;"
)
SCORE_RE = re.compile(r"differing words \(reloc-masked\):\s*(\d+)")

# `differing_words` intentionally keeps a two-argument surface: callers and
# tests have historically replaced it with a small scoring stub.  The logical
# source used for compiler selection is carried out-of-band while a probe runs.
_COMPILE_CONTEXT: Path | None = None


def _line_offsets(text: str) -> tuple[list[str], list[int]]:
    lines = text.splitlines(keepends=True)
    offsets, cursor = [], 0
    for line in lines:
        offsets.append(cursor)
        cursor += len(line)
    return lines, offsets


def _target_name(address: str, function: str | None) -> str:
    if function:
        return function
    match = re.fullmatch(r"FUN_([0-9A-Fa-f]{8})", address.strip())
    if match is None:
        raise SystemExit(f"invalid FUN_ marker {address!r}")
    return "func_" + match.group(1).lower()


def _matching_endif(lines: list[str], code_lines: list[str], start: int) -> int:
    depth = 0
    for index in range(start, len(lines)):
        directive = code_lines[index].strip()
        if directive.startswith("#if"):
            depth += 1
        elif directive.startswith("#endif"):
            depth -= 1
            if depth == 0:
                return index
    raise SystemExit("unterminated #ifdef NON_MATCHING guard")


def _header_start(
    lines: list[str],
    code_lines: list[str],
    marker_index: int,
    open_line: int,
    name_line: int | None,
) -> int:
    """Find a definition's first header line without consuming declarations."""
    if name_line is None:
        for index in range(marker_index + 1, open_line + 1):
            if code_lines[index].strip() and not code_lines[index].lstrip().startswith("#"):
                return index
        return open_line

    start = name_line
    index = name_line - 1
    while index > marker_index:
        code = code_lines[index].strip()
        if not code or code.startswith("#") or ";" in code or "}" in code:
            break
        start = index
        index -= 1
    return start


def region_for(
    text: str,
    address: str,
    function: str | None = None,
) -> tuple[int, int]:
    """Return the exact source span owned by one marked function.

    The old implementation replaced everything from a marker to the next
    marker.  That is unsafe: a file-scope declaration or a measured note
    between those markers disappeared with the candidate.  This parser keeps
    the marker and surrounding context, replacing only an INCLUDE_ASM row, a
    guarded NON_MATCHING block, or the target definition through its matching
    closing brace.
    """
    wanted = address.upper()
    lines, offsets = _line_offsets(text)
    marker_index = next(
        (
            index
            for index, line in enumerate(lines)
            if (match := MARKER_RE.match(line))
            and match.group(1).upper() == wanted
        ),
        None,
    )
    if marker_index is None:
        raise SystemExit(f"no // {wanted} marker in the file")

    code_lines = verify.sanitize_c_lines(lines)
    name = _target_name(address, function)
    name_re = re.compile(r"\b" + re.escape(name) + r"\b")
    guard_line: int | None = None
    open_line: int | None = None
    name_line: int | None = None
    target_seen = False

    for index in range(marker_index + 1, len(lines)):
        if MARKER_RE.match(lines[index]):
            break
        code = code_lines[index]
        stripped = code.strip()
        if not stripped:
            continue
        if stripped == "#ifdef NON_MATCHING":
            guard_line = index
            break
        include = INCLUDE_CODE_RE.match(code)
        if include is not None and include.group("name") == name:
            return offsets[index], offsets[index] + len(lines[index])
        if name_re.search(code.split("{", 1)[0]) and ";" not in code.split("{", 1)[0]:
            name_line = index
            target_seen = True
        if "{" in code and (
            target_seen or (name_line is None and stripped.startswith("{"))
        ):
            open_line = index
            break
    if guard_line is not None:
        end_line = _matching_endif(lines, code_lines, guard_line)
        return offsets[guard_line], offsets[end_line] + len(lines[end_line])


    if open_line is None:
        raise SystemExit(f"could not find a definition or INCLUDE_ASM row for {name}")

    depth, seen = 0, False
    end_line: int | None = None
    end_column: int | None = None
    for index in range(open_line, len(lines)):
        if MARKER_RE.match(lines[index]) and index != open_line:
            break
        code = code_lines[index]
        for column, char in enumerate(code):
            if char == "{":
                depth += 1
                seen = True
            elif char == "}":
                depth -= 1
                if seen and depth <= 0:
                    end_line, end_column = index, column
                    break
        if end_line is not None:
            break
    if end_line is None or end_column is None:
        raise SystemExit(f"unterminated definition for {name}")

    start_line = _header_start(lines, code_lines, marker_index, open_line, name_line)
    return offsets[start_line], offsets[end_line] + end_column + 1


def _read_text(path: Path) -> str:
    with path.open("r", encoding="utf-8", errors="surrogateescape", newline="") as handle:
        return handle.read()


def _newline_for(raw: bytes) -> str:
    return "\r\n" if b"\r\n" in raw else "\n"


@contextmanager
def scratch_source(source: Path):
    """Yield a temporary TU path in SOURCE's directory, then remove it."""
    descriptor, name = tempfile.mkstemp(
        prefix=f".{source.stem}.probe_",
        suffix=source.suffix,
        dir=str(source.parent),
    )
    os.close(descriptor)
    path = Path(name)
    try:
        yield path
    finally:
        path.unlink(missing_ok=True)


def _normalise_candidate(body: str, newline: str) -> str:
    body = body.replace("\r\n", "\n").replace("\r", "\n")
    body = "".join(
        line
        for line in body.splitlines(keepends=True)
        if not MARKER_RE.match(line)
    )
    if body and not body.endswith("\n"):
        body += "\n"
    return body if newline == "\n" else body.replace("\n", newline)


def splice_region(text: str, start: int, end: int, body: str, newline: str) -> str:
    """Replace a span without duplicating its original line ending."""
    suffix = text[end:]
    if body.endswith(newline) and suffix.startswith(newline):
        suffix = suffix[len(newline):]
    return text[:start] + body + suffix


def _has_include_fallback(text: str, function: str) -> bool:
    for line in verify.sanitize_c_lines(text.splitlines(keepends=True)):
        match = INCLUDE_CODE_RE.match(line)
        if match is not None and match.group("name") == function:
            return True
    return False


def _compile_in_context(
    candidate: Path,
    logical_source: Path,
    cfg: dict,
    output: Path,
) -> tuple[bool, str]:
    """Compile CANDIDATE with flags selected for LOGICAL_SOURCE."""
    logical_source = logical_source.resolve()
    candidate = candidate.resolve()
    if verify.is_gcc_unit(logical_source):
        return verify._compile_gcc(candidate, cfg, output)

    command = verify._mwccgap_command(logical_source, cfg, output)
    # `_mwccgap_command` deliberately receives the original path so compiler
    # version/speed-unit flags stay attached to the owning TU.  Only its input
    # path is redirected to the isolated copy.
    command[2] = str(candidate)
    process = subprocess.run(
        command,
        cwd=REPO,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    return process.returncode == 0 and output.is_file(), process.stdout


def run_fndiff(
    source: Path,
    function: str,
    context: Path | None = None,
) -> tuple[int | None, str]:
    """Run fndiff against SOURCE while compiling with CONTEXT's TU settings."""
    import fndiff

    source = Path(source).resolve()
    logical_source = Path(context or source).resolve()
    output, errors = io.StringIO(), io.StringIO()
    saved_argv = sys.argv
    saved_compile = fndiff._compile
    failure: str | None = None

    def compile_candidate(cpath: Path, cfg: dict, obj: Path) -> tuple[bool, str]:
        return _compile_in_context(cpath, logical_source, cfg, obj)

    fndiff._compile = compile_candidate
    try:
        sys.argv = ["fndiff.py", str(source), function]
        with redirect_stdout(output), redirect_stderr(errors):
            try:
                fndiff.main()
            except SystemExit as error:
                failure = str(error)
            except Exception as error:  # compiler/configuration diagnostics
                failure = f"{type(error).__name__}: {error}"
    finally:
        fndiff._compile = saved_compile
        sys.argv = saved_argv

    diagnostics = output.getvalue() + errors.getvalue()
    if failure:
        if failure not in diagnostics:
            diagnostics += ("" if diagnostics.endswith("\n") else "\n") + failure
        return None, diagnostics
    match = SCORE_RE.search(diagnostics)
    if match is None:
        diagnostics += (
            ("" if diagnostics.endswith("\n") else "\n")
            + "fndiff produced no differing-word score"
        )
        return None, diagnostics
    return int(match.group(1)), diagnostics


def differing_words(source: Path, function: str) -> int | None:
    """Reloc-masked differing-word count, or None if it did not compile."""
    score, diagnostics = run_fndiff(source, function, _COMPILE_CONTEXT)
    if score is None:
        print(f"    fndiff failed for {function}:")
        if diagnostics.strip():
            print(diagnostics.rstrip())
    return score


def address_of(function: str) -> str:
    digits = re.search(r"([0-9A-Fa-f]{8})", function)
    if not digits:
        raise SystemExit(f"cannot derive an address from {function!r}")
    return "FUN_" + digits.group(1).upper()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", help="C source file containing the function")
    parser.add_argument("function", help="object symbol, e.g. func_00246940")
    parser.add_argument(
        "--candidate",
        action="append",
        default=[],
        metavar="NAME=PATH",
        help="a replacement function definition to try; repeatable",
    )
    parser.add_argument("--marker", help="override the FUN_ marker to replace")
    args = parser.parse_args()

    source = Path(args.file).resolve()
    if not source.is_file():
        parser.error(f"source file does not exist: {args.file}")
    marker = args.marker or address_of(args.function)
    original = source.read_bytes()
    text = original.decode("utf-8", errors="surrogateescape")
    start, end = region_for(text, marker, args.function)
    newline = _newline_for(original)

    candidates: list[tuple[str, str]] = [("baseline", text[start:end])]
    for spec in args.candidate:
        name, separator, path_value = spec.partition("=")
        if not separator or not name or not path_value:
            raise SystemExit(f"--candidate wants NAME=PATH, got {spec!r}")
        path = Path(path_value)
        try:
            body = _read_text(path)
        except OSError as error:
            raise SystemExit(f"cannot read candidate {path}: {error}") from error
        candidates.append((name, _normalise_candidate(body, newline)))

    if not _has_include_fallback(candidates[0][1], args.function):
        print(
            f"  NOTE: {source} does not currently hold an INCLUDE_ASM fallback for\n"
            f"        {args.function}; the baseline and candidates are measured in\n"
            "        isolated copies and the source is never installed.\n"
        )

    results: list[tuple[str, int | None]] = []
    winner: str | None = None
    global _COMPILE_CONTEXT
    previous_context = _COMPILE_CONTEXT
    _COMPILE_CONTEXT = source
    try:
        try:
            with scratch_source(source) as scratch:
                for name, body in candidates:
                    scratch.write_bytes(
                        splice_region(text, start, end, body, newline).encode(
                            "utf-8", errors="surrogateescape"
                        )
                    )
                    if _has_include_fallback(body, args.function):
                        results.append((name, None))
                        print(
                            f"  {name:<18}     -- "
                            "(INCLUDE_ASM fallback, not a score)",
                            flush=True,
                        )
                        continue
                    score = differing_words(scratch, args.function)
                    results.append((name, score))
                    shown = "COMPILE ERROR" if score is None else f"{score:5d}"
                    print(f"  {name:<18} {shown}", flush=True)
                    if score == 0 and winner is None:
                        winner = name
        except OSError as error:
            print(f"cannot create or write isolated probe copy: {error}")
            return 1
    finally:
        _COMPILE_CONTEXT = previous_context
    scored = [(name, score) for name, score in results if score is not None]
    if scored:
        best_name, best = min(scored, key=lambda row: row[1])
        print(f"\nbest: {best_name} ({best} differing words)")
    if winner:
        print(f"match: {winner} (not installed; source unchanged)")
    else:
        print("no candidate matched (source unchanged)")
    return 0 if winner else 1


if __name__ == "__main__":
    raise SystemExit(main())

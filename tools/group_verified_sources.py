#!/usr/bin/env python3
"""Group verified guarded P4 source units into unguarded module files.

A guarded source unit is moved only when every function marker in that guard is
reported MATCH in a verifier report.  The generated module is independently
compiled before applying it; this tool only performs source movement after that
verification step.  Units that fail grouped compilation remain in their
original guarded module.
"""
from __future__ import annotations

import argparse
from collections import defaultdict
import json
from pathlib import Path
import re

REPO = Path(__file__).resolve().parents[1]
GUARD_RE = re.compile(
    r"^\s*#if\s+defined\(P4_UNIT_([0-9A-Fa-f]{8})\)\s*$", re.MULTILINE
)
MARKER_RE = re.compile(
    r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\b[^\n]*$", re.MULTILINE
)
FUNCTION_DECL_RE = re.compile(
    r"^\s*(?:(?:extern|static|asm)\s+)*"
    r"[^;{}\n]*\bfunc_([0-9A-Fa-f]{8})\s*"
    r"\([^;{}\n]*\)\s*;\s*(?:/\*.*\*/)?\s*$",
    re.MULTILINE,
)
FUNCTION_DEF_RE = re.compile(
    r"^(?P<signature>\s*(?:(?:asm|static)\s+)*"
    r"[A-Za-z_][^\n{};]*\b(?P<name>func_[0-9A-Fa-f]{8})\s*"
    r"\([^;\n]*\))\s*\{",
    re.MULTILINE,
)


def normalize_path(value: object) -> str:
    return str(value).replace("\\", "/")


def row_address(row: dict) -> int | None:
    try:
        raw = row["addr"]
        return raw if isinstance(raw, int) else int(str(raw), 16)
    except (KeyError, TypeError, ValueError):
        return None


def load_matches(report_path: Path, prefix: str) -> dict[str, set[int]]:
    report = json.loads(report_path.read_text(encoding="utf-8"))
    matches: dict[str, set[int]] = defaultdict(set)
    for row in report.get("results", []):
        file = normalize_path(row.get("file", ""))
        if prefix and not file.startswith(prefix):
            continue
        if row.get("status") != "MATCH" or row.get("normalized_diff") != 0:
            continue
        address = row_address(row)
        if address is not None:
            matches[file].add(address)
    return matches


def guarded_blocks(text: str) -> tuple[str, list[tuple[int, set[int], str]]]:
    guards = list(GUARD_RE.finditer(text))
    if not guards:
        return text, []
    header = text[: guards[0].start()]
    blocks: list[tuple[int, set[int], str]] = []
    for guard in guards:
        end_match = re.search(
            r"^\s*#endif\b[^\n]*$",
            text[guard.end() :],
            re.MULTILINE,
        )
        if end_match is None:
            raise RuntimeError(f"unterminated guard at {guard.group(1)}")
        end = guard.end() + end_match.end()
        body = text[guard.end() : guard.end() + end_match.start()].strip("\n")
        addresses = {int(match.group(1), 16) for match in MARKER_RE.finditer(body)}
        blocks.append((guard.start(), addresses, body))
        if end <= guard.start():
            raise RuntimeError("invalid guarded block range")
    return header, blocks


def _preamble_lines(combined: str) -> list[str]:
    lines: list[str] = []
    seen: set[str] = set()
    for line in combined.splitlines():
        stripped = line.strip()
        if stripped.startswith("#include") or stripped.startswith("typedef "):
            if stripped not in seen:
                lines.append(stripped)
                seen.add(stripped)
    return lines


def canonical_group(header: str, blocks: list[str]) -> str:
    combined = "\n\n".join(blocks)
    preamble = _preamble_lines(combined)
    combined = re.sub(r"(?m)^\s*#include[^\n]*\n?", "", combined)
    combined = re.sub(r"(?m)^\s*typedef [^\n]*\n?", "", combined)
    combined = FUNCTION_DECL_RE.sub("", combined)

    prototypes: list[str] = []
    seen: set[str] = set()
    for match in FUNCTION_DEF_RE.finditer(combined):
        name = match.group("name")
        if name in seen:
            continue
        signature = match.group("signature").strip()
        signature = re.sub(r"^(?:asm|static)\s+", "", signature)
        prototypes.append(signature + ";")
        seen.add(name)

    lines = [
        "/* Grouped verified Persona 4 source units. */",
        "/* The original guards were independently verified before grouping. */",
        *preamble,
        "",
        "/* Canonical grouped function declarations. */",
        *prototypes,
        "",
        combined.strip(),
        "",
    ]
    return "\n".join(lines)


def selected_blocks(source_path: Path, addresses: set[int]) -> tuple[str, list[str], set[int]]:
    text = source_path.read_text(encoding="utf-8", errors="replace")
    header, blocks = guarded_blocks(text)
    chosen: list[str] = []
    moved: set[int] = set()
    for _start, block_addresses, body in blocks:
        if block_addresses and block_addresses <= addresses:
            chosen.append(body)
            moved.update(block_addresses)
    return header, chosen, moved


def prune_source(source_path: Path, addresses: set[int]) -> int:
    text = source_path.read_text(encoding="utf-8", errors="replace")
    _header, blocks = guarded_blocks(text)
    removals: list[tuple[int, int]] = []
    for start, block_addresses, _body in blocks:
        if not block_addresses or not block_addresses <= addresses:
            continue
        guard = GUARD_RE.search(text, start)
        if guard is None or guard.start() != start:
            continue
        end_match = re.search(
            r"^\s*#endif\b[^\n]*$",
            text[guard.end() :],
            re.MULTILINE,
        )
        if end_match is None:
            continue
        end = guard.end() + end_match.end()
        if end < len(text) and text[end] == "\n":
            end += 1
        removals.append((start, end))
    for start, end in reversed(removals):
        text = text[:start] + text[end:]
    if removals:
        source_path.write_text(text, encoding="utf-8", newline="\n")
    return sum(1 for _ in removals)


def render_probes(
    report_path: Path,
    source_root: Path,
    output_dir: Path,
    prefix: str,
) -> tuple[int, int]:
    matches = load_matches(report_path, prefix)
    output_dir.mkdir(parents=True, exist_ok=True)
    manifest: dict[str, dict[str, object]] = {}
    files = 0
    units = 0
    for file, addresses in sorted(matches.items()):
        relative = Path(file)
        if relative.parts[:1] == ("src",):
            source_path = source_root.parent / relative
        else:
            source_path = source_root / relative
        if not source_path.is_file():
            continue
        header, blocks, moved = selected_blocks(source_path, addresses)
        if not blocks:
            continue
        output_name = "_".join(relative.with_suffix("").parts) + ".c"
        output_path = output_dir / output_name
        output_path.write_text(canonical_group(header, blocks), encoding="utf-8", newline="\n")
        manifest[output_name] = {
            "source": relative.as_posix(),
            "addresses": sorted(moved),
        }
        files += 1
        units += len(moved)
    (output_dir / "manifest.json").write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    return files, units


def apply_group_report(
    report_path: Path,
    manifest_path: Path,
    output_root: Path,
) -> tuple[int, int]:
    report = json.loads(report_path.read_text(encoding="utf-8"))
    grouped_matches: dict[str, set[int]] = defaultdict(set)
    for row in report.get("results", []):
        if row.get("status") != "MATCH" or row.get("normalized_diff") != 0:
            continue
        address = row_address(row)
        if address is None:
            continue
        grouped_matches[Path(normalize_path(row.get("file", ""))).name].add(address)

    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    files = 0
    units = 0
    for output_name, entry in sorted(manifest.items()):
        source_path = REPO / entry["source"]
        addresses = grouped_matches.get(output_name, set())
        if not addresses:
            continue
        header, blocks, moved = selected_blocks(source_path, addresses)
        if not moved:
            continue
        output_path = output_root / source_path.relative_to(REPO / "src")
        output_path = output_path.with_name(output_path.stem + "_grouped.c")
        if output_path.exists():
            continue
        output_path.write_text(canonical_group(header, blocks), encoding="utf-8", newline="\n")
        prune_source(source_path, moved)
        files += 1
        units += len(moved)
    return files, units


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--prefix", default="", help="verifier file prefix to group")
    parser.add_argument("--source-root", type=Path, default=REPO / "src")
    parser.add_argument("--probe-output", type=Path)
    parser.add_argument("--apply-manifest", type=Path)
    parser.add_argument("--apply-report", type=Path)
    args = parser.parse_args()
    if args.probe_output is not None:
        files, units = render_probes(
            args.report.resolve(), args.source_root.resolve(), args.probe_output.resolve(), args.prefix
        )
        print(f"rendered grouped probes: {units} units in {files} C files")
        return 0
    if args.apply_manifest is not None and args.apply_report is not None:
        files, units = apply_group_report(
            args.apply_report.resolve(), args.apply_manifest.resolve(), args.source_root.resolve()
        )
        print(f"applied grouped sources: {units} units in {files} C files")
        return 0
    parser.error("provide --probe-output or both --apply-manifest and --apply-report")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())

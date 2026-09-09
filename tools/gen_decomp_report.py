"""Write the decomp.dev progress report directly from the verifier's own data.

decomp.dev ingests a `report.json` (schema version 2) published as a GitHub
Actions artifact. Until now this repository produced that file indirectly:
`gen_objdiff.py` emitted ~26,000 per-function target/base object files and
`objdiff-cli report generate` diffed them pairwise to derive the measures. That
path has three problems this tool exists to remove.

1. It measured the wrong thing. Base objects are built with `--skip-asm`, so
   every function still on an `INCLUDE_ASM` fallback has NO base object and
   contributes zero to `matched_code`, while its retail bytes still count toward
   `total_code`. The published figure therefore tracked object-emission coverage
   rather than the project's actual byte-exact function count.
2. It was fragile. The config, the emitted objects and the report had to agree;
   a unit whose object failed to emit silently dropped out, and one such failure
   took CI down entirely.
3. It could not express what this project actually claims. The strongest claim
   here is a byte-exact LINKED image, which is a property of the build, not
   something recoverable by diffing isolated objects.

`tools/verify.py` already computes, per function, the retail window, the
compiled object size and a reloc-masked byte difference against retail. That is
strictly better evidence than a pairwise object diff, so this tool consumes it
and writes the report itself. `objdiff.json` remains for interactive diffing in
the objdiff GUI; it is no longer on the publishing path.

Grouping: source-file units are split by function origin where an owner mixes
game code, Sony SDK and other vendor code. Attribution categories are `main`,
`sony_sdk`, `third_party` and `unclassified`; `linked` is additive.

`matched_*` measures compiled C matching retail. `complete_*` measures proven
linkage. A retail-backed SDK object can be 100% linked and 0% C-matched; it
never contributes invented decompilation progress.

    python tools/gen_decomp_report.py --report build/verify_report.json \
        --output build/report.json
"""

import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import gen_objdiff  # noqa: E402  (path set above)
import verify as V  # noqa: E402


def f32(value: float) -> float:
    """Round to float32 the way objdiff-cli's report does, so historical rows
    and newly written ones compare equal instead of differing in the last bits."""
    import struct

    return struct.unpack("<f", struct.pack("<f", float(value)))[0]


def similarity(row: dict) -> float:
    """Percentage of this function's retail window that is byte-identical.

    MATCH is exactly 100. A row with no compiled C body (an `INCLUDE_ASM`
    fallback) is 0 even though its object trivially equals retail: crediting the
    spliced assembly would report the extraction as progress. Anything else is
    scored from the verifier's reloc-masked differing byte count, which is the
    only similarity figure in this tree backed by a measurement.
    """
    if row.get("status") == "MATCH":
        return 100.0
    window = row.get("window") or 0
    if window <= 0:
        return 0.0
    if row.get("status") == "ASM":
        return 0.0
    differing = row.get("normalized_diff")
    if not isinstance(differing, int) or differing < 0:
        return 0.0
    return f32(max(0.0, (window - min(differing, window)) / window * 100.0))


def measures(rows: list[dict], total_units: int = 1, complete_units: int = 0) -> dict:
    """Aggregate one population of functions into decomp.dev's measure set.

    The `matched_*` and `complete_*` families mean DIFFERENT things, following the
    convention every other decomp.dev project uses and objdiff's own schema, where
    `complete` is documented as "complete (or linked)":

      matched_*   byte-exact against retail. This is the "perfect match" figure,
                  and `measure=code` on a badge is an alias for
                  matched_code_percent.
      complete_*  shipped in the byte-exact linked image. Gauntlet: Dark Legacy
                  labels `measure=complete_code` "Linked Code" for exactly this.
      fuzzy_*     size-weighted partial credit, so it is always >= matched.

    Conflating the two is what produced a badge reading "0 / 0" here: the repo had
    `complete` meaning byte-exact-in-isolation, so the standard linked measure had
    nothing behind it and a nonstandard category had to be invented to carry it.
    A row is linked when it carries `_linked`, set by the caller.
    """
    total_code = sum(row.get("window") or 0 for row in rows)
    matched = [row for row in rows if row.get("status") == "MATCH"]
    matched_code = sum(row.get("window") or 0 for row in matched)
    linked_code = sum(row.get("window") or 0 for row in rows if row.get("_linked"))
    weighted = sum(similarity(row) * (row.get("window") or 0) for row in rows)
    out = {"total_units": total_units, "complete_units": complete_units}
    if total_code:
        out.update(
            total_code=str(total_code),
            matched_code=str(matched_code),
            matched_code_percent=f32(matched_code / total_code * 100.0),
            complete_code=str(linked_code),
            complete_code_percent=f32(linked_code / total_code * 100.0),
            fuzzy_match_percent=f32(weighted / total_code),
            # No data symbols are tracked, so data is vacuously complete. Emitted
            # because omitting it makes decomp.dev render an empty data column.
            matched_data_percent=100.0,
            complete_data_percent=100.0,
        )
    if rows:
        out.update(
            total_functions=len(rows),
            matched_functions=len(matched),
            matched_functions_percent=f32(len(matched) / len(rows) * 100.0),
        )
    return out


def unit_name(file_rel: str) -> str:
    stem = file_rel
    if stem.startswith("src/"):
        stem = stem[len("src/"):]
    return stem[:-2] if stem.endswith(".c") else stem


def build_report(report_path: Path, linked_report: str | None) -> dict:
    results = json.loads(report_path.read_text(encoding="utf-8"))["results"]
    linked = gen_objdiff.linked_addresses(linked_report)

    # The verifier only reports functions a source file claims. Every OTHER
    # canonical function still occupies a retail window, so leaving them out
    # would shrink the denominator and inflate every published percentage - the
    # exact dishonesty the category split exists to prevent. They are added as
    # zero-similarity rows, attributed by their recovered `__FILE__` translation
    # unit where one exists and left unclassified otherwise.
    windows = V._read_json(V.FUNCTION_WINDOWS)["windows"]
    tu_names = gen_objdiff.tu_name_by_address(windows)
    covered = {_address(row) for row in results}
    for addr_hex, size in sorted(windows.items()):
        address = int(addr_hex, 16)
        if address in covered:
            continue
        tu = tu_names.get(address)
        results.append({
            "file": "(unattributed)/%s" % (tu or "unknown"),
            "name": "func_%08x" % address,
            "addr": "%08x" % address,
            "status": "ABSENT",
            "window": size or 0,
            "line": address,
            "_tu": tu,
        })

    by_file: dict[tuple[str, str], list[dict]] = defaultdict(list)
    file_categories: dict[str, set[str]] = defaultdict(set)
    for row in results:
        file_rel = row["file"].replace("\\", "/")
        category = gen_objdiff.progress_category(
            None if file_rel.startswith("(unattributed)/") else file_rel,
            row.get("_tu"), _address(row),
        )
        by_file[file_rel, category].append(row)
        file_categories[file_rel].add(category)

    units, per_category = [], defaultdict(list)
    for (file_rel, category), rows in sorted(by_file.items()):
        rows = sorted(rows, key=lambda r: r.get("line") or 0)
        for row in rows:
            row["_linked"] = _address(row) in linked
        complete = all(row["_linked"] for row in rows)
        categories = [category]
        if any(row["_linked"] for row in rows):
            categories.append("linked")
            per_category["linked"].extend(row for row in rows if row["_linked"])
        per_category[category].extend(rows)
        units.append({
            "name": unit_name(file_rel) + (f":{category}" if len(file_categories[file_rel]) > 1 else ""),
            "measures": measures(rows, 1, 1 if complete else 0),
            "sections": [],
            "functions": [{
                "name": row.get("name") or "",
                "size": str(row.get("window") or 0),
                "fuzzy_match_percent": similarity(row),
                "address": str(_address(row)),
                "metadata": {},
            } for row in rows],
            "metadata": {
                "complete": complete,
                "progress_categories": categories,
                "source_path": file_rel,
            },
        })

    complete_units = sum(1 for unit in units if unit["metadata"]["complete"])
    return {
        "version": 2,
        "measures": measures(results, len(units), complete_units),
        "categories": [
            dict(id=cat["id"], name=cat["name"], measures=measures(
                per_category[cat["id"]],
                sum(1 for u in units if cat["id"] in u["metadata"]["progress_categories"]),
                sum(1 for u in units if cat["id"] in u["metadata"]["progress_categories"]
                    and u["metadata"]["complete"]),
            ))
            for cat in gen_objdiff.PROGRESS_CATEGORIES
        ],
        "units": units,
    }


def _address(row: dict) -> int:
    addr = row.get("addr")
    try:
        return int(addr, 16) if isinstance(addr, str) else int(addr or 0)
    except ValueError:
        return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", default="build/verify_report.json", metavar="PATH",
                        help="tools/verify.py --json report to derive measures from")
    parser.add_argument("--linked-report", metavar="PATH",
                        help="tools/build.py --progress-report output; falls back to "
                             "the committed progress/metrics.json when absent")
    parser.add_argument("--output", default="build/report.json", metavar="PATH")
    args = parser.parse_args()

    report_path = Path(args.report)
    if not report_path.is_file():
        sys.exit(f"gen_decomp_report: no verifier report at {report_path}")
    report = build_report(report_path, args.linked_report)

    out = Path(args.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    top = report["measures"]
    print("%s/%s byte-exact (%.2f%%), fuzzy %.2f%%, linked code %.2f%%, %s/%s units linked -> %s"
          % (top["matched_functions"], top["total_functions"],
             top["matched_functions_percent"], top["fuzzy_match_percent"],
             top["complete_code_percent"], top["complete_units"],
             top["total_units"], out))
    for cat in report["categories"]:
        m = cat["measures"]
        if m.get("total_functions"):
            print("  %-13s %5s/%-5s C-matched functions, fuzzy %6.2f%%, linked code %6.2f%%"
                  % (cat["id"], m["matched_functions"], m["total_functions"],
                     m["fuzzy_match_percent"], m["complete_code_percent"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())

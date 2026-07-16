#!/usr/bin/env python3
"""Report decompilation progress and generate validated progress endpoints.

Usage:
  python tools/progress.py                 # run verify.py and report
  python tools/progress.py --report build/verify_report.json
  python tools/progress.py --json          # machine-readable progress summary
  python tools/progress.py --report REPORT --linked-report REPORT --write-dir progress
  python tools/progress.py --validate-dir progress
"""
from __future__ import annotations

import argparse
import collections
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Any

REPO = Path(__file__).resolve().parents[1]
METADATA = REPO / "tools" / "slus21782_functions.json"
SCHEMA_VERSION = 1
CACHE_SECONDS = 3600


class ProgressError(ValueError):
    """Raised for invalid progress inputs or generated endpoint files."""


def load_json(path: Path, description: str) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except FileNotFoundError as exc:
        raise ProgressError(f"{description} is missing: {path}") from exc
    except OSError as exc:
        raise ProgressError(f"cannot read {description}: {path}: {exc}") from exc
    except json.JSONDecodeError as exc:
        raise ProgressError(f"malformed {description}: {path}: {exc}") from exc


def load_windows(path: Path = METADATA) -> dict[int, int | None]:
    metadata = load_json(path, "function metadata")
    if not isinstance(metadata, dict):
        raise ProgressError("malformed function metadata: top level must be an object")
    windows = metadata.get("windows")
    if not isinstance(windows, dict) or not windows:
        raise ProgressError("malformed function metadata: 'windows' must be a non-empty object")
    parsed: dict[int, int | None] = {}
    for address, size in windows.items():
        if not isinstance(address, str):
            raise ProgressError("malformed function metadata: window addresses must be strings")
        try:
            numeric_address = int(address, 16)
        except ValueError as exc:
            raise ProgressError(f"malformed function metadata: invalid window address {address!r}") from exc
        if numeric_address in parsed:
            raise ProgressError(f"malformed function metadata: duplicate window address {address!r}")
        if size is not None and (not isinstance(size, int) or isinstance(size, bool) or size < 0):
            raise ProgressError(f"malformed function metadata: invalid window size for {address!r}")
        parsed[numeric_address] = size
    return parsed


def load_report(path: Path | None) -> tuple[dict[str, Any], str]:
    if path is not None:
        return load_json(path, "verifier report"), str(path)
    output = REPO / "build" / "verify_report.json"
    output.parent.mkdir(exist_ok=True)
    subprocess.run([sys.executable, str(REPO / "tools" / "verify.py"), "--json", str(output)],
                   cwd=REPO, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT, check=False)
    return load_json(output, "verifier report"), str(output)


def canonical_address(address: Any) -> int:
    if isinstance(address, int) and not isinstance(address, bool):
        return address
    if isinstance(address, str) and address and all(c in "0123456789abcdefABCDEF" for c in address):
        return int(address, 16)
    raise ProgressError("malformed verifier report: every result needs an integer or hexadecimal string addr")


def canonical_linked_address(address: Any) -> int:
    if not isinstance(address, str) or len(address) != 8 or any(c not in "0123456789abcdef" for c in address):
        raise ProgressError("malformed linked report: linked function address must be an 8-digit lowercase hexadecimal string")
    return int(address, 16)


def report_results(report: Any) -> list[dict[str, Any]]:
    if not isinstance(report, dict) or not isinstance(report.get("results"), list):
        raise ProgressError("malformed verifier report: 'results' must be a list")
    results = report["results"]
    for row in results:
        if not isinstance(row, dict) or not isinstance(row.get("status"), str):
            raise ProgressError("malformed verifier report: every result needs a string status")
        canonical_address(row.get("addr"))
    return results


def matching_diagnostics(results: list[dict[str, Any]], windows: dict[int, int | None]) -> tuple[set[int], int, int, int, int]:
    known, matched = set(), set()
    known_rows = duplicate_rows = ignored_unknown_rows = 0
    for row in results:
        address = canonical_address(row["addr"])
        if address not in windows:
            ignored_unknown_rows += 1
            continue
        known_rows += 1
        if address in known:
            duplicate_rows += 1
        known.add(address)
        if row["status"] == "MATCH":
            matched.add(address)
    return matched, known_rows, len(known), duplicate_rows, ignored_unknown_rows


def percentage(count: int, total: int) -> float:
    return round(100 * count / total, 3) if total else 0.0


def progress_color(percent: float) -> str:
    if percent == 0:
        return "red"
    if percent < 25:
        return "orange"
    if percent < 50:
        return "yellow"
    if percent < 75:
        return "yellowgreen"
    if percent < 100:
        return "green"
    return "brightgreen"


def badge(label: str, count: int, total: int) -> dict[str, Any]:
    percent = percentage(count, total)
    return {"schemaVersion": SCHEMA_VERSION, "label": label,
            "message": f"{count}/{total} ({percent:.3f}%)", "color": progress_color(percent),
            "cacheSeconds": CACHE_SECONDS}


def validate_linked_report(report: Any, windows: dict[int, int | None]) -> dict[str, Any]:
    if not isinstance(report, dict):
        raise ProgressError("malformed linked report: top level must be an object")
    required = ("schema_version", "build_succeeded", "image_sha1", "retail_sha1", "function_total",
                "linked_tu_count", "linked_function_count", "linked_functions")
    missing = [field for field in required if field not in report]
    if missing:
        raise ProgressError(f"malformed linked report: missing {', '.join(missing)}")
    if report["schema_version"] != SCHEMA_VERSION:
        raise ProgressError(f"unsupported linked report schema_version: {report['schema_version']!r}")
    if report["build_succeeded"] is not True:
        raise ProgressError("linked report says build_succeeded is not true")
    if any(not isinstance(report[field], str) or not report[field] for field in ("image_sha1", "retail_sha1")):
        raise ProgressError("malformed linked report: image_sha1 and retail_sha1 must be non-empty strings")
    if report["function_total"] != len(windows):
        raise ProgressError("linked report function_total does not match function metadata")
    functions = report["linked_functions"]
    if not isinstance(functions, list):
        raise ProgressError("malformed linked report: linked_functions must be a list")
    addresses, units = set(), set()
    for row in functions:
        if not isinstance(row, dict):
            raise ProgressError("malformed linked report: linked_functions entries must be objects")
        address = canonical_linked_address(row.get("address"))
        if address in addresses:
            raise ProgressError(f"malformed linked report: duplicate linked address 0x{address:08x}")
        if address not in windows:
            raise ProgressError(f"malformed linked report: unknown linked address 0x{address:08x}")
        if not isinstance(row.get("name"), str) or not row["name"]:
            raise ProgressError("malformed linked report: linked function name must be a non-empty string")
        if not isinstance(row.get("file"), str) or not row["file"]:
            raise ProgressError("malformed linked report: linked function file must be a non-empty string")
        unit = row.get("unit")
        if unit is not None and (
            not isinstance(unit, str) or len(unit) != 8
            or any(c not in "0123456789abcdef" for c in unit)
        ):
            raise ProgressError(
                "malformed linked report: linked function unit must be an 8-digit "
                "lowercase hexadecimal string or null"
            )
        addresses.add(address)
        units.add((row["file"], unit))
    if report["linked_function_count"] != len(addresses):
        raise ProgressError("linked report linked_function_count does not agree with linked_functions")
    if report["linked_tu_count"] != len(units):
        raise ProgressError("linked report linked_tu_count does not agree with linked function units")
    return report


def make_metrics(report: Any, windows: dict[int, int | None], linked_report: dict[str, Any] | None,
                 verifier_source: str, linked_source: str | None) -> tuple[dict[str, Any], dict[str, Any], dict[str, Any]]:
    results = report_results(report)
    status_counts = dict(sorted(collections.Counter(row["status"] for row in results).items()))
    matched, known_rows, unique_known, duplicate_rows, ignored = matching_diagnostics(results, windows)
    sizes: dict[int, int] = {}
    for row in results:
        address, size = canonical_address(row["addr"]), row.get("object_size")
        if address in matched and row["status"] == "MATCH" and isinstance(size, int) and not isinstance(size, bool) and size >= 0:
            sizes[address] = max(sizes.get(address, 0), size)
    matching_addresses = [f"{address:08x}" for address in sorted(matched)]
    linked_addresses: list[str] = []
    hashes: dict[str, str | None] = {"retail_sha1": None, "image_sha1": None}
    build_succeeded = False
    if linked_report is not None:
        linked = {canonical_linked_address(row["address"]) for row in linked_report["linked_functions"]}
        for address in linked:
            if address not in matched:
                raise ProgressError(f"linked address {address:08x} is not in the matching address set")
        linked_addresses = [f"{address:08x}" for address in sorted(linked)]
        hashes = {"retail_sha1": linked_report["retail_sha1"], "image_sha1": linked_report["image_sha1"]}
        build_succeeded = True
    total = len(windows)
    metrics = {"schema_version": SCHEMA_VERSION,
               "source": {"verifier_report": verifier_source, "linked_report": linked_source,
                          "raw_rows": len(results), "ignored_unknown_rows": ignored},
               "total": total,
               "matching": {"count": len(matching_addresses), "percent": percentage(len(matching_addresses), total),
                            "addresses": matching_addresses, "matched_body_bytes": sum(sizes.values()),
                            "known_rows": known_rows, "unique_known_addresses": unique_known, "duplicate_rows": duplicate_rows},
               "linked": {"count": len(linked_addresses), "percent": percentage(len(linked_addresses), total), "addresses": linked_addresses},
               "status_counts": status_counts, "hashes": hashes, "build_succeeded": build_succeeded}
    return metrics, badge("matching", len(matching_addresses), total), badge("linked", len(linked_addresses), total)


def atomic_write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=f".{path.name}.", suffix=".tmp", dir=path.parent, text=True)
    try:
        with os.fdopen(fd, "w", encoding="utf-8", newline="\n") as handle:
            json.dump(payload, handle, indent=2, sort_keys=True); handle.write("\n")
        os.replace(temporary, path)
    except BaseException:
        try: os.unlink(temporary)
        except FileNotFoundError: pass
        raise


def write_endpoints(directory: Path, metrics: dict[str, Any], matching_badge: dict[str, Any], linked_badge: dict[str, Any]) -> None:
    atomic_write_json(directory / "metrics.json", metrics)
    atomic_write_json(directory / "matching.json", matching_badge)
    atomic_write_json(directory / "linked.json", linked_badge)


def validate_address_list(value: Any, name: str, windows: dict[int, int | None]) -> set[str]:
    if not isinstance(value, list):
        raise ProgressError(f"malformed metrics endpoint: {name} addresses must be a list")
    addresses: set[str] = set()
    for address in value:
        if not isinstance(address, str) or len(address) != 8 or any(c not in "0123456789abcdef" for c in address):
            raise ProgressError(f"invalid metrics endpoint: {name} address must be canonical lowercase 8-digit hex")
        if address in addresses:
            raise ProgressError(f"invalid metrics endpoint: duplicate {name} address {address}")
        if int(address, 16) not in windows:
            raise ProgressError(f"invalid metrics endpoint: unknown {name} address {address}")
        addresses.add(address)
    return addresses


def validate_endpoints(directory: Path, windows: dict[int, int | None]) -> None:
    metrics = load_json(directory / "metrics.json", "metrics endpoint")
    matching_badge = load_json(directory / "matching.json", "matching endpoint")
    linked_badge = load_json(directory / "linked.json", "linked endpoint")
    if not isinstance(metrics, dict):
        raise ProgressError("malformed metrics endpoint: top level must be an object")
    required = {"schema_version", "source", "total", "matching", "linked", "status_counts", "hashes", "build_succeeded"}
    if missing := sorted(required - metrics.keys()):
        raise ProgressError(f"malformed metrics endpoint: missing {', '.join(missing)}")
    if metrics["schema_version"] != SCHEMA_VERSION or metrics["total"] != len(windows):
        raise ProgressError("invalid metrics endpoint schema or total")
    source, hashes = metrics["source"], metrics["hashes"]
    if not isinstance(source, dict) or not all(isinstance(source.get(k), str) and source[k] for k in ("verifier_report", "linked_report")):
        raise ProgressError("malformed metrics endpoint: invalid source report provenance")
    raw_rows, ignored = source.get("raw_rows"), source.get("ignored_unknown_rows")
    if any(not isinstance(v, int) or isinstance(v, bool) or v < 0 for v in (raw_rows, ignored)) or ignored > raw_rows:
        raise ProgressError("invalid metrics endpoint: source row diagnostics")
    counts = metrics["status_counts"]
    if not isinstance(counts, dict) or any(not isinstance(k, str) or not isinstance(v, int) or isinstance(v, bool) or v < 0 for k, v in counts.items()) or sum(counts.values()) != raw_rows:
        raise ProgressError("invalid metrics endpoint: status counts")
    if not isinstance(hashes, dict) or any(not isinstance(hashes.get(k), str) or not hashes[k] for k in ("retail_sha1", "image_sha1")) or metrics["build_succeeded"] is not True:
        raise ProgressError("malformed metrics endpoint: invalid successful build evidence")
    if not isinstance(metrics["matching"], dict) or not isinstance(metrics["linked"], dict):
        raise ProgressError("malformed metrics endpoint: matching and linked must be objects")
    matched_bytes = metrics["matching"].get("matched_body_bytes")
    known, unique, duplicates = (metrics["matching"].get(k) for k in ("known_rows", "unique_known_addresses", "duplicate_rows"))
    if not isinstance(matched_bytes, int) or isinstance(matched_bytes, bool) or matched_bytes < 0 or any(not isinstance(v, int) or isinstance(v, bool) or v < 0 for v in (known, unique, duplicates)):
        raise ProgressError("invalid metrics endpoint: matching diagnostics")
    if known + ignored != raw_rows or unique > known or duplicates != known - unique or unique > len(windows):
        raise ProgressError("invalid metrics endpoint: inconsistent matching row diagnostics")
    address_sets: dict[str, set[str]] = {}
    for name in ("matching", "linked"):
        value, count = metrics[name], metrics[name].get("count")
        if not isinstance(count, int) or isinstance(count, bool) or not 0 <= count <= len(windows) or value.get("percent") != percentage(count, len(windows)):
            raise ProgressError(f"invalid metrics endpoint: {name} count or percent")
        address_sets[name] = validate_address_list(value.get("addresses"), name, windows)
        if count != len(address_sets[name]):
            raise ProgressError(f"invalid metrics endpoint: {name} count does not agree with addresses")
    if metrics["matching"]["count"] > unique or not address_sets["linked"].issubset(address_sets["matching"]):
        raise ProgressError("invalid metrics endpoint: linked addresses must be a matching subset")
    if matching_badge != badge("matching", metrics["matching"]["count"], len(windows)) or linked_badge != badge("linked", metrics["linked"]["count"], len(windows)):
        raise ProgressError("invalid badge endpoint: schema, message, or color disagrees with metrics")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", type=Path); parser.add_argument("--linked-report", type=Path)
    parser.add_argument("--write-dir", type=Path); parser.add_argument("--validate-dir", type=Path)
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args()
    try:
        windows = load_windows()
        if args.validate_dir is not None:
            if args.report or args.linked_report or args.write_dir or args.json:
                raise ProgressError("--validate-dir cannot be combined with report, write, or json options")
            validate_endpoints(args.validate_dir, windows); return
        report, verifier_source = load_report(args.report)
        linked_report = validate_linked_report(load_json(args.linked_report, "linked report"), windows) if args.linked_report else None
        if args.write_dir and linked_report is None:
            raise ProgressError("--write-dir requires a successful --linked-report")
        metrics, matching_badge, linked_badge = make_metrics(report, windows, linked_report, verifier_source, str(args.linked_report) if args.linked_report else None)
        if args.write_dir: write_endpoints(args.write_dir, metrics, matching_badge, linked_badge)
        if args.json:
            json.dump({"functions_total": metrics["total"], "functions_scanned": metrics["source"]["raw_rows"], "functions_matched": metrics["matching"]["count"], "functions_nonmatching": metrics["status_counts"].get("NONMATCHING", 0), "matched_code_bytes": metrics["matching"]["matched_body_bytes"], "matched_pct_of_known": metrics["matching"]["percent"], "matched_pct_of_scanned": round(100 * metrics["matching"]["count"] / metrics["source"]["raw_rows"], 2) if metrics["source"]["raw_rows"] else 0}, sys.stdout, indent=2); sys.stdout.write("\n")
        else: print(f"Persona 4 decompilation progress: {metrics['matching']['count']}/{metrics['total']} matching; {metrics['linked']['count']} C-linked")
    except ProgressError as exc:
        print(f"progress: error: {exc}", file=sys.stderr); raise SystemExit(2) from exc


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Port real function names from the Persona 3 FES decomp onto Persona 4.

Every P4 canonical function with a UNIQUE compiled-function counterpart in
Persona 3 FES inherits the P3 name for that counterpart, if P3 has one. The
P4<->P3 mapping report (build/shared_p3.json, or the prebuilt copy at
C:/tmp/shared.json) supplies the correspondence; P3 names come from
``config/symbol_addrs.txt`` in the P3 checkout.

Only UNIQUE mappings are trusted: when several P3 functions normalize to the
same P4 function, the ported name is not determined and the candidate is
counted and skipped, never guessed.

Junk names are rejected with per-class counts:

* placeholders (``func_<hex>`` / ``FUN_<hex>``) carry no information;
* address-suffixed pseudo-names are placeholders wearing a prefix
  (``datPersona00173340``, ``kwln00197fb0``). The rule: reject a name that
  ends in a run of 6+ hex digits (catches truncated 6-digit suffixes) or that
  contains a run of 8+ hex digits anywhere (a full 32-bit address embedded in
  the identifier, e.g. ``btlUnitUpdate00285d30Packet``). Measured over P3's
  1,059 human-named functions, legitimate trailing hex runs top out at 5
  (``...StateDead``) and legitimate embedded runs at 6 (``...eFaceButton``),
  so both thresholds sit above the real-word ceiling with margin;
* names for addresses that are not canonical P4 boundaries;
* names whose P4 target is third-party middleware (verify.is_third_party
  against the owning source file, where one exists);
* duplicate names across candidates (a name is kept at its lowest address;
  the later duplicates would hard-fail the symbol-name reconciliation).

Each accepted name records its evidence strength tier in the note:

* tier 1: P3 counterpart is decompiled and verifier-matched (per the mapping
  report's embedded P3 verify snapshot);
* tier 2: not matched, but the P3 address is in P3's symbols_recovered.txt
  (recover_symbols.py's retail-relocation-consistent recovered addresses);
* tier 3: not matched/recovered, but the P3 function exists in P3 source;
* tier 4: none of the above — a Ghidra-exported guess, and the note says so.

The output file config/symbol_names.p3.txt is rewritten wholesale on every
run (idempotent) and is validated by tools/reconcile_function_boundaries.py
together with the other symbol_names*.txt producers.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))
from verify import is_third_party  # noqa: E402
from reconcile_function_boundaries import source_markers  # noqa: E402

MAPPING_DEFAULT = Path("C:/tmp/shared.json")  # orchestrator-prebuilt P4<->P3 report
REGENERATED_REPORT = REPO / "build" / "shared_p3.json"
P3_ROOT_DEFAULT = Path("../Persona3-FES-Decompilation")
OUTPUT_DEFAULT = REPO / "config" / "symbol_names.p3.txt"
CANONICAL_MAP = REPO / "tools" / "slus21782_functions.json"

# A P3 function-name entry: `Name = 0xADDR; // type:func`. Non-func entries
# (e.g. `_gp`) are skipped; the header comment explains the format.
SYMBOL_LINE = re.compile(
    r"^\s*(?P<name>[A-Za-z_]\w*)\s*=\s*0x(?P<addr>[0-9A-Fa-f]{8})\s*;"
    r"\s*//\s*type:func\b"
)
IDENTIFIER = re.compile(r"^[A-Za-z_]\w*$")
# Generated placeholder space; a recovered name must not collide with it.
PLACEHOLDER = re.compile(r"^(?:FUN|func)_[0-9A-Fa-f]+$")
# Address-bearing pseudo-names: a trailing 6+ hex-digit run (the orchestrator's
# rule; P3 shows datPersona00173340 / kwln00197fb0) or an 8+ run anywhere (a
# full 32-bit address embedded, e.g. btlUnitUpdate00285d30Packet). Real-word
# hex tails measured over P3's human-named set never exceed 5 trailing / 6
# embedded digits, so these thresholds cannot clip a legitimate name.
SUFFIXED = re.compile(r"[0-9A-Fa-f]{6,}$")
EMBEDDED = re.compile(r"[0-9A-Fa-f]{8,}")

# Evidence tiers, strongest first; see the module docstring.
TIER_DESCRIPTORS = {
    1: "P3 verifier-matched",
    2: "P3 recovered-symbol address; not verifier-matched",
    3: "P3 source present; not verifier-matched/recovered",
    4: "P3 Ghidra-exported guess; no verifier/source/recovered evidence",
}


def parse_p3_symbols(path: Path) -> dict[int, str]:
    """Parse P3 config/symbol_addrs.txt into {address: name} for type:func rows."""
    symbols: dict[int, str] = {}
    for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        match = SYMBOL_LINE.match(line)
        if not match:
            continue
        name, address = match["name"], int(match["addr"], 16)
        symbols[address] = name
    return symbols


def parse_recovered(path: Path) -> set[int]:
    """Parse P3 config/symbols_recovered.txt into the recovered function-address set.

    recover_symbols.py attests ADDRESSES (every matched reference agrees on the
    same value), so only the address matters for tiering; the name at that
    address still comes from symbol_addrs.txt.
    """
    recovered: set[int] = set()
    for line in path.read_text(encoding="utf-8").splitlines():
        match = SYMBOL_LINE.match(line)
        if match:
            recovered.add(int(match["addr"], 16))
    return recovered


def name_junk(name: str) -> str | None:
    """Classify a P3 name as junk, or None when it is a real recoverable name."""
    if PLACEHOLDER.match(name):
        return "placeholder"
    if SUFFIXED.search(name) or EMBEDDED.search(name):
        return "address_suffixed"
    if not IDENTIFIER.match(name):
        return "invalid_identifier"
    return None


def tier_for(
    p3_address: int, match: dict, p3_recovered: set[int]
) -> tuple[int, list[str]]:
    evidence = (match.get("p3_evidence") or [{}])[0]
    if evidence.get("verifier_match"):
        return 1, evidence.get("sources") or []
    if p3_address in p3_recovered:
        return 2, evidence.get("sources") or []
    if evidence.get("sources"):
        return 3, evidence.get("sources") or []
    return 4, []


def classify(
    matches: list[dict],
    p3_names: dict[int, str],
    p3_recovered: set[int],
    canonical: set[int],
    owners: dict[int, str],
) -> tuple[list[dict], dict[str, int]]:
    """Apply every rejection rule; return accepted entries and per-class counts.

    Accepted entries are dicts with keys p4_address, p3_address, name, tier,
    and sources; rejection classes are counted under the documented names.
    """
    accepted: list[dict] = []
    counts = {
        "non_unique": 0,
        "p3_name_missing": 0,
        "placeholder": 0,
        "address_suffixed": 0,
        "invalid_identifier": 0,
        "not_canonical": 0,
        "third_party": 0,
        "duplicate_name": 0,
    }
    used_names: dict[str, int] = {}
    for match in matches:
        if not match.get("unique"):
            counts["non_unique"] += 1
            continue
        p4_address = int(match["p4_address"], 16)
        if p4_address not in canonical:
            counts["not_canonical"] += 1
            continue
        p3_address = int(match["p3_addresses"][0], 16)
        name = p3_names.get(p3_address)
        if name is None:
            counts["p3_name_missing"] += 1
            continue
        junk = name_junk(name)
        if junk == "placeholder":
            counts["placeholder"] += 1
            continue
        if junk == "address_suffixed":
            counts["address_suffixed"] += 1
            continue
        if junk == "invalid_identifier":
            counts["invalid_identifier"] += 1
            continue
        owner = owners.get(p4_address)
        if owner is not None and is_third_party(owner):
            counts["third_party"] += 1
            continue
        if name in used_names:
            counts["duplicate_name"] += 1
            continue
        tier, sources = tier_for(p3_address, match, p3_recovered)
        accepted.append(
            {
                "p4_address": p4_address,
                "p3_address": p3_address,
                "name": name,
                "tier": tier,
                "sources": sources,
            }
        )
        used_names[name] = p4_address
    accepted.sort(key=lambda entry: entry["p4_address"])
    return accepted, counts


def evidence_note(entry: dict) -> str:
    """Build the `evidence:` note for an accepted name (contract vocabulary)."""
    note = f"p3:{entry['name']}@0x{entry['p3_address']:08x} tier:{entry['tier']}"
    if entry["tier"] == 1 and not entry["sources"]:
        note += " (P3 verifier-matched)"
    else:
        note += f" ({TIER_DESCRIPTORS[entry['tier']]})"
    if entry["sources"]:
        note += f" file:{entry['sources'][0]}"
    return note


def build_lines(accepted: list[dict], total: int) -> list[str]:
    """Render the output file lines (header plus one entry per accepted name)."""
    lines = [
        "// Recovered Persona 4 function names ported from the Persona 3 FES decomp.",
        "// Generated by tools/port_p3_names.py; rewritten wholesale each run. Do not hand-edit.",
        f"// {len(accepted)} of {total} unique P4<->P3 mappings carry a ported name.",
        "",
    ]
    for entry in accepted:
        lines.append(
            f"{entry['name']} = 0x{entry['p4_address']:08X}; // type:func  "
            f"evidence: {evidence_note(entry)}"
        )
    return lines


def write_output(path: Path, lines: list[str]) -> None:
    """Atomically rewrite the producer file (binary write: no CRLF translation)."""
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_bytes(("\n".join(lines) + "\n").encode("utf-8"))
    temporary.replace(path)


def owners_by_address() -> dict[int, str]:
    """Map each marker address to its owning src/ file (reconcile's ownership).

    Only real (non-generated) source files count; functions owned by generated
    retail-asm units have no source owner, so is_third_party never sees them.
    """
    return {
        address: str(entries[0][0])
        for address, entries in source_markers().items()
    }


def load_mapping(path: Path) -> dict:
    try:
        report = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"port_p3_names: cannot read mapping {path}: {error}") from error
    if report.get("schema_version") != 1 or not isinstance(report.get("matches"), list):
        raise SystemExit(
            f"port_p3_names: {path} is not a schema_version-1 P4<->P3 mapping report"
        )
    return report


def regenerate_mapping(args: argparse.Namespace) -> Path:
    """Re-run tools/map_shared_p3.py and use its fresh report."""
    command = [
        sys.executable,
        str(TOOLS / "map_shared_p3.py"),
        "--p3-root",
        str(args.p3_root),
        "--with-source-evidence",
        "--output",
        str(REGENERATED_REPORT),
    ]
    if args.p3_report is not None:
        command += ["--p3-report", str(args.p3_report)]
    result = subprocess.run(command, cwd=REPO)
    if result.returncode != 0:
        raise SystemExit(f"port_p3_names: map_shared_p3.py failed with {result.returncode}")
    return REGENERATED_REPORT


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--mapping",
        type=Path,
        default=MAPPING_DEFAULT,
        help=f"P4<->P3 mapping report (default: {MAPPING_DEFAULT})",
    )
    parser.add_argument(
        "--regenerate",
        action="store_true",
        help="regenerate the mapping with tools/map_shared_p3.py into build/shared_p3.json "
        "instead of reading --mapping",
    )
    parser.add_argument(
        "--p3-root",
        type=Path,
        default=P3_ROOT_DEFAULT,
        help="Persona3-FES-Decompilation checkout (default: relative to this repo)",
    )
    parser.add_argument(
        "--p3-report",
        type=Path,
        default=None,
        help="live P3 verify.py --json report, passed through to map_shared_p3.py "
        "with --regenerate for fresher verifier-match evidence",
    )
    parser.add_argument(
        "--p3-symbols",
        type=Path,
        default=None,
        help="P3 config/symbol_addrs.txt (default: <p3-root>/config/symbol_addrs.txt)",
    )
    parser.add_argument(
        "--p3-recovered",
        type=Path,
        default=None,
        help="P3 config/symbols_recovered.txt (default: <p3-root>/config/symbols_recovered.txt)",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=OUTPUT_DEFAULT,
        help=f"producer file to write (default: {OUTPUT_DEFAULT.relative_to(REPO)})",
    )
    args = parser.parse_args()

    if args.regenerate and args.mapping != MAPPING_DEFAULT:
        parser.error("--mapping and --regenerate are mutually exclusive")
    if args.p3_report is not None and not args.regenerate:
        parser.error("--p3-report only applies together with --regenerate")

    p3_root = args.p3_root.resolve()
    p3_symbols = (args.p3_symbols or p3_root / "config" / "symbol_addrs.txt").resolve()
    p3_recovered_path = (
        args.p3_recovered or p3_root / "config" / "symbols_recovered.txt"
    ).resolve()

    mapping_path = regenerate_mapping(args) if args.regenerate else args.mapping
    report = load_mapping(mapping_path)
    matches = report["matches"]
    unique = sum(1 for match in matches if match.get("unique"))
    print(f"mapping {mapping_path}: {len(matches)} matches ({unique} unique)")

    p3_names = parse_p3_symbols(p3_symbols)
    p3_recovered = parse_recovered(p3_recovered_path)
    canonical = {
        int(address, 16)
        for address in json.loads(CANONICAL_MAP.read_text(encoding="utf-8"))["windows"]
    }
    owners = owners_by_address()
    accepted, counts = classify(matches, p3_names, p3_recovered, canonical, owners)

    for label in ("non_unique", "p3_name_missing", "placeholder", "address_suffixed",
                  "invalid_identifier", "not_canonical", "third_party", "duplicate_name"):
        print(f"rejected {label}: {counts[label]}")
    tiers = sorted({entry["tier"] for entry in accepted})
    tier_counts = ", ".join(
        f"tier {tier}: {sum(1 for entry in accepted if entry['tier'] == tier)}"
        for tier in tiers
    )
    print(f"accepted: {len(accepted)} ({tier_counts})")

    output = args.output.resolve()
    write_output(output, build_lines(accepted, unique))
    try:
        display_path = output.relative_to(REPO)
    except ValueError:
        display_path = output
    print(f"wrote {display_path} with {len(accepted)} names")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

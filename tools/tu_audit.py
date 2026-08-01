#!/usr/bin/env python3
"""Propose original translation-unit boundaries for Persona 4 (SLUS_217.82).

Why this exists
---------------
The P4 source tree groups functions by MODULE NAME, not by the original
translation unit: ``tools/verify.py`` can compile each function as its own
unit via ``#if defined(P4_UNIT_<addr>)`` guards (mwccgap is blind to them, so
``INCLUDE_ASM`` and cross-unit inlining break under that scheme), and the
per-unit scheme is currently load-bearing.  A real translation unit emits one
contiguous ``.text`` region, so recovering the original boundaries matters for
two reasons: (1) it tells us which existing module files could be re-arranged
into true TUs, and (2) it quantifies how much of the per-unit scheme is
actually needed.

Address gaps carry almost no signal here: the canonical function map is a
single contiguous run (one real ~1.9 MB hole at 0x52da00-0x70c850), so
boundaries must come from other evidence.

Evidence signals (strongest first)
----------------------------------
1. P3 cross-reference.  ``map_shared_p3.py`` maps P4 functions to byte-identical
   Persona 3 FES counterparts, and P3's source files ARE real translation
   units.  Adjacent P4 functions whose P3 counterparts live in the same P3 file
   are almost certainly the same original TU.  This tool runs ``map_shared_p3``
   in-process (no writes) with a fresh P3 ``verify.py --json`` report.
2. Owned data.  Functions referencing the same ``.rodata``/``.bss``/``.sdata``
   address (decoded directly from retail: ``lui``/``addiu`` pairs and
   GP-relative accesses) belong together.  Shared references that are rare
   (few functions use them) are stronger evidence than hot shared globals.
3. Codegen-flag homogeneity.  MWCC compiled with the instruction scheduler on
   fills ``jr $ra`` delay slots; with it off the delay slot is a ``nop``.  The
   flag was per-file, so a maximal stretch sharing it is TU evidence -- but
   calibration against P3 (whose files are real TUs) shows it carries almost no
   discriminative power at pair level (98%+ of adjacent pairs share the flag
   whether or not they are one file), so it is weighted weakly and also
   reported separately as "scheduler stretches".
4. Call locality.  A function called only from a tight address neighbourhood is
   likely file-local to it.  Reported as a per-group support statistic
   (fraction of members whose direct callers all lie within the group's span
   plus a margin), not as a merge criterion.

Pair-level calibration (measured on P3 ground truth, 13,890 adjacent pairs
where both functions are decompiled): the base rate of an adjacent pair being
same-file is ~98.4%; a direct call between the pair raises it to 99.2%; a
shared *rare* data reference (used by <= 4 functions) to 99.6%; a shared hot
global is 97.9% (below base rate) and a shared scheduler flag is 98.3%
(indistinguishable from base rate).  The P3-file signal is the workhorse; call
plus rare-data is the only non-P3 combination that earns a HIGH tier.

Conservative by design: a boundary is closed only on evidence (never on
absence of evidence), and the default report lists only HIGH-confidence groups
(every internal boundary score >= 4).  We would rather propose 40
high-confidence groups than 400 speculative ones.

This tool is read-only: it writes nothing except the optional ``--json``
report.  ``map_shared_p3.py`` is imported and run in-process so no intermediate
file is produced or consumed.

Usage:  python tools/tu_audit.py [--json PATH] [--min-score N] [--shared-report PATH]
"""
from __future__ import annotations

import argparse
import collections
import json
import struct
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent

P4_FUNCTIONS = TOOLS / "slus21782_functions.json"
P4_IMAGE = REPO / "image.bin"
P4_TARGET = REPO / "config" / "target.json"
DEFAULT_SHARED = REPO / "build" / "shared_p3.json"
DEFAULT_P3_ROOT = REPO.parent / "Persona3-FES-Decompilation"
DEFAULT_P3_REPORT = Path("C:/tmp/p3_full.json")
FULL_P3_REPORT = Path("C:/tmp/full_verify.json")
# A scoped P3 verify report (a handful of files) carries almost no source
# evidence; below this many rows we treat the default report as scoped and
# upgrade to the known full P3 report.
MIN_REPORT_ROWS = 1000

BASE = 0x00100000
JR_RA = 0x03E00008
LUI_LOOKAHEAD = 8
DATA_RARE_FREQ = 4
CALLER_MARGIN = 0x4000
MIN_GROUP_SIZE = 2

# Per-signal boundary scores.  A boundary (adjacent pair of functions) closes
# when its score reaches MEDIUM_MIN; tiers are HIGH / MEDIUM by the weakest
# internal boundary.  Weights come from P3 ground-truth calibration (13,890
# adjacent pairs where both functions are decompiled; base rate of an adjacent
# pair being same-file is 98.4%):
#   p3_file     5  P3 counterparts in one P3 file -- near-certain
#   call        2  direct jal between the pair -- 99.2% same-file on P3
#   data_rare   2  shared data address referenced by <= 4 functions -- 99.6%
#   data_common 0  hot shared globals -- 97.9%, *below* base rate, so it is
#                  recorded as information but never closes a boundary
#   sched       0  same scheduler flag -- 98.3%, indistinguishable from base
#                  rate; reported separately as scheduler stretches
SCORE_P3_FILE = 5
SCORE_CALL = 2
SCORE_DATA_RARE = 2
SCORE_DATA_COMMON = 0
SCORE_SCHED = 0
HIGH_MIN = 4
MEDIUM_MIN = 2

# MIPS opcode ranges used by the retail decoder.
_LOAD_STORE_OPS = frozenset(
    (0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x31, 0x39)
)
GP_REG = 28


def _sign16(value: int) -> int:
    return value - 0x10000 if value & 0x8000 else value


def load_windows(path: Path) -> tuple[dict, list[int]]:
    """Return (windows, sorted addresses) from the canonical function map."""
    data = json.loads(path.read_text(encoding="utf-8"))
    windows = {int(address, 16): size for address, size in data["windows"].items()}
    return windows, sorted(windows)


def load_image(path: Path) -> bytes:
    return path.read_bytes()


def decode_functions(
    image: bytes, windows: dict[int, int], gp: int, base: int = BASE
) -> dict[int, dict]:
    """Decode every retail function window into evidence.

    Returns {address: {"calls": set[int], "refs": set[int], "sched": float|None}}
    where ``calls`` holds direct ``jal`` targets that land on a known function,
    ``refs`` holds referenced data addresses (GP-relative or ``lui``/``addiu``
    pairs, restricted to the data region of the image), and ``sched`` is the
    fraction of ``jr $ra`` delay slots that are filled with real work (None
    when the function contains no ``jr $ra``).
    """
    order = sorted(windows)
    ends: dict[int, int] = {}
    for index, address in enumerate(order):
        size = windows[address]
        next_address = order[index + 1] if index + 1 < len(order) else None
        end = address + size
        if next_address is not None and next_address < end:
            # A window overlapping its successor would corrupt decoding; trust
            # the map's contiguity instead.
            end = next_address
        ends[address] = end
    data_start = max(ends.values()) if ends else base
    image_end = base + len(image)

    decoded: dict[int, dict] = {}
    for address in order:
        size = ends[address] - address
        if size <= 0:
            decoded[address] = {"calls": set(), "refs": set(), "sched": None}
            continue
        words = struct.unpack_from("<%dI" % (size // 4), image, address - base)
        calls: set[int] = set()
        refs: set[int] = set()
        jr_total = jr_filled = 0
        for k, word in enumerate(words):
            op = word >> 26
            if word == JR_RA:
                jr_total += 1
                if k + 1 < len(words) and words[k + 1] != 0:
                    jr_filled += 1
                continue
            if op == 3:  # jal
                target = ((address + 4 * k + 4) & 0xF0000000) | (
                    (word & 0x03FFFFFF) << 2
                )
                if target in ends:
                    calls.add(target)
            elif op == 0x0F:  # lui rt, hi
                rt = (word >> 16) & 0x1F
                hi = word & 0xFFFF
                for j in range(1, LUI_LOOKAHEAD + 1):
                    if k + j >= len(words):
                        break
                    follow = words[k + j]
                    if ((follow >> 21) & 0x1F) != rt:
                        continue
                    follow_op = follow >> 26
                    if follow_op in (0x09, 0x0D):  # addiu/ori rt, rt, lo
                        lo = follow & 0xFFFF
                        if follow_op == 0x09:
                            lo = _sign16(lo)
                        refs.add((hi << 16) + lo)
                        break
                    if follow_op in _LOAD_STORE_OPS:  # lw/sw/... lo(rt)
                        refs.add((hi << 16) + _sign16(follow & 0xFFFF))
                        break
            elif op in (0x09, 0x0D) or op in _LOAD_STORE_OPS:
                if ((word >> 21) & 0x1F) == GP_REG:  # GP-relative data access
                    lo = word & 0xFFFF
                    if op != 0x0D:
                        lo = _sign16(lo)
                    refs.add(gp + lo)
        refs = {r for r in refs if data_start <= r < image_end}
        decoded[address] = {
            "calls": calls,
            "refs": refs,
            "sched": None if jr_total == 0 else jr_filled / jr_total,
            "end": ends[address],
        }
    return decoded


def compute_callers(decoded: dict[int, dict]) -> dict[int, set[int]]:
    """Invert the call graph: target -> set of caller addresses."""
    callers: dict[int, set[int]] = collections.defaultdict(set)
    for caller, info in decoded.items():
        for target in info["calls"]:
            callers[target].add(caller)
    return dict(callers)


def build_pair_evidence(
    order: list[int],
    decoded: dict[int, dict],
    p3_files: dict[int, set[str]],
) -> tuple[list[dict], dict[int, int]]:
    """Score every adjacent boundary.

    Returns (boundaries, ref_frequency) where ``boundaries[i]`` describes the
    pair (order[i], order[i+1]): signals that fired, the total score, whether
    the boundary is closed, and a P3 conflict flag (both sides sourced to
    *different* P3 files -- evidence for a boundary that vetoes closure).
    """
    frequency: collections.Counter = collections.Counter()
    for info in decoded.values():
        for ref in info["refs"]:
            frequency[ref] += 1

    boundaries: list[dict] = []
    for index in range(len(order) - 1):
        a, b = order[index], order[index + 1]
        da, db = decoded[a], decoded[b]
        if da["end"] != b:
            # The canonical map has one real hole (~1.9 MB); windows across it
            # are not adjacent in memory and can never share a translation
            # unit, so no evidence may close this boundary.
            boundaries.append(
                {"a": a, "b": b, "signals": {"gap": True}, "score": 0,
                 "closed": False, "conflict": False}
            )
            continue
        signals: dict[str, object] = {}
        score = 0
        conflict = False

        src_a, src_b = p3_files.get(a, set()), p3_files.get(b, set())
        if src_a and src_b:
            shared = src_a & src_b
            if shared:
                signals["p3_file"] = sorted(shared)
                score += SCORE_P3_FILE
            else:
                conflict = True
                signals["p3_conflict"] = [sorted(src_a), sorted(src_b)]

        if (db["calls"] and a in db["calls"]) or (da["calls"] and b in da["calls"]):
            signals["call"] = True
            score += SCORE_CALL

        shared_refs = da["refs"] & db["refs"]
        if shared_refs:
            rarest = min(frequency[ref] for ref in shared_refs)
            rare = rarest <= DATA_RARE_FREQ
            signals["data"] = {
                "refs": sorted(shared_refs),
                "rarest_frequency": rarest,
                "rare": rare,
            }
            score += SCORE_DATA_RARE if rare else SCORE_DATA_COMMON

        if da["sched"] is not None and da["sched"] == db["sched"]:
            signals["sched"] = da["sched"]
            score += SCORE_SCHED

        closed = (not conflict) and score >= MEDIUM_MIN
        boundaries.append(
            {
                "a": a,
                "b": b,
                "signals": signals,
                "score": score,
                "closed": closed,
                "conflict": conflict,
            }
        )
    return boundaries, dict(frequency)


def extract_groups(
    order: list[int], boundaries: list[dict], min_size: int = MIN_GROUP_SIZE
) -> list[dict]:
    """Maximal runs of closed boundaries, as group records.

    Group records carry the member addresses, the per-boundary evidence, the
    weakest-boundary score, and the tier (HIGH if every boundary scores >=
    HIGH_MIN, MEDIUM otherwise -- all closed boundaries score >= MEDIUM_MIN).
    """
    groups: list[dict] = []
    run: list[int] = []
    run_boundaries: list[dict] = []
    for boundary in boundaries:
        if not boundary["closed"]:
            if len(run) >= min_size:
                groups.append(_finish_group(run, run_boundaries))
            run, run_boundaries = [], []
            continue
        if not run:
            run.append(boundary["a"])
        run.append(boundary["b"])
        run_boundaries.append(boundary)
    if len(run) >= min_size:
        groups.append(_finish_group(run, run_boundaries))
    return groups


def _finish_group(run: list[int], run_boundaries: list[dict]) -> dict:
    scores = [b["score"] for b in run_boundaries]
    return {
        "members": list(run),
        "start": run[0],
        "end": run[-1],
        "size": len(run),
        "boundaries": list(run_boundaries),
        "min_score": min(scores),
        "tier": "HIGH" if min(scores) >= HIGH_MIN else "MEDIUM",
    }


def group_p3_files(group: dict, p3_files: dict[int, set[str]]) -> list[tuple[str, int]]:
    """Most common P3 source files among the group's members, by member count."""
    counts: collections.Counter = collections.Counter()
    for member in group["members"]:
        for source in p3_files.get(member, ()):
            counts[source] += 1
    return counts.most_common()


def annotate_groups(
    groups: list[dict],
    decoded: dict[int, dict],
    callers: dict[int, set[int]],
    current_files: dict[int, list[str]],
    p3_files: dict[int, set[str]],
) -> list[dict]:
    """Attach per-group reporting fields (current files, call locality, P3 files)."""
    for group in groups:
        members = group["members"]
        span_start = members[0]
        span_end = max(decoded[m]["end"] for m in members)
        group["span_end"] = span_end
        member_set = set(members)

        file_counts: collections.Counter = collections.Counter()
        for member in members:
            for source in current_files.get(member, ()):
                file_counts[source] += 1
        group["current_files"] = file_counts.most_common()

        local = total = 0
        for member in members:
            cs = callers.get(member)
            if not cs:
                continue
            total += 1
            if all(span_start - CALLER_MARGIN <= c <= span_end + CALLER_MARGIN for c in cs):
                local += 1
        group["callers_local"] = f"{local}/{total}"
        group["internal_calls"] = sum(
            1 for member in members for target in decoded[member]["calls"]
            if target in member_set
        )
        group["p3_files"] = group_p3_files(group, p3_files)
    return groups


def scan_current_files() -> dict[int, list[str]]:
    """Address -> non-generated src files containing its ``// FUN_`` marker.

    Mirrors ``verify.py``'s own scan (same regex, same generated-file rule) so
    the report's "current source file" claims match the tracked state.
    """
    sys.path.insert(0, str(TOOLS))
    import verify  # noqa: PLC0415  (stdlib-only module; reused for consistency)

    out: dict[int, set[str]] = collections.defaultdict(set)
    for path in sorted((REPO / "src").rglob("*.c")):
        if verify.is_generated(path):
            continue
        relative = path.relative_to(REPO).as_posix()
        try:
            markers = verify.scan_markers(path)
        except ValueError:
            continue
        for marker in markers:
            out[marker["addr"]].add(relative)
    return {address: sorted(files) for address, files in out.items()}


def choose_p3_report(explicit: Path | None) -> Path | None:
    """Pick the fresh P3 verify report to feed map_shared_p3.

    Defaults to ``C:/tmp/p3_full.json`` (the agreed location); if that file is
    a scoped run (too few rows to carry source evidence), upgrades to the known
    full P3 report ``C:/tmp/full_verify.json`` and says so in the report.
    """
    if explicit is not None:
        return explicit
    for candidate in (DEFAULT_P3_REPORT, FULL_P3_REPORT):
        if not candidate.is_file():
            continue
        try:
            rows = json.loads(candidate.read_text(encoding="utf-8")).get("results")
            count = len(rows) if isinstance(rows, list) else 0
        except (OSError, json.JSONDecodeError):
            count = 0
        if count >= MIN_REPORT_ROWS:
            return candidate
    if DEFAULT_P3_REPORT.is_file():
        return DEFAULT_P3_REPORT
    if FULL_P3_REPORT.is_file():
        return FULL_P3_REPORT
    return None


def load_p3_files(
    p3_report: Path | None,
    p3_root: Path,
    shared_report: Path | None,
) -> tuple[dict[int, set[str]], dict]:
    """P4 address -> P3 source files, plus provenance for the report.

    Prefers a prebuilt ``map_shared_p3.py`` JSON report (``--shared-report``);
    otherwise runs ``map_shared_p3.build_report`` in-process against the P3
    checkout -- no files are written either way.
    """
    provenance: dict = {}
    if shared_report is not None:
        data = json.loads(shared_report.read_text(encoding="utf-8"))
        provenance["shared_report"] = str(shared_report)
        provenance["shared_report_sha1"] = None
    else:
        sys.path.insert(0, str(TOOLS))
        import map_shared_p3  # noqa: PLC0415

        if not p3_root.is_dir():
            if DEFAULT_SHARED.is_file():
                return load_p3_files(None, p3_root, DEFAULT_SHARED)
            raise FileNotFoundError(
                f"P3 checkout not found at {p3_root}; pass --p3-root, "
                "--shared-report, or place the report at {DEFAULT_SHARED}"
            )
        args = argparse.Namespace(
            p3_root=p3_root,
            p3_base=0x00100000,
            with_source_evidence=True,
            p3_report=p3_report,
            output=None,
        )
        data = map_shared_p3.build_report(args)
        provenance["shared_report"] = "in-process map_shared_p3.build_report"
        provenance["p3_root"] = str(p3_root)
        provenance["p3_report"] = str(p3_report) if p3_report is not None else None

    provenance["mapped_p4_functions"] = sum(
        1 for match in data.get("matches", []) if match.get("p3_evidence")
    )
    provenance["schema_version"] = data.get("schema_version")
    inputs = data.get("inputs", {})
    if isinstance(inputs, dict) and isinstance(inputs.get("p3"), dict):
        provenance["p3_metrics_sha1"] = inputs["p3"].get("metrics_sha1")
        provenance["p3_image_sha1"] = inputs["p3"].get("image_sha1")

    p3_files: dict[int, set[str]] = {}
    for match in data.get("matches", []):
        try:
            address = int(match["p4_address"], 16)
        except (KeyError, ValueError):
            continue
        sources: set[str] = set()
        for evidence in match.get("p3_evidence", []):
            sources.update(evidence.get("sources") or [])
        if sources:
            p3_files[address] = sources
    return p3_files, provenance


def scheduler_stretches(
    order: list[int], decoded: dict[int, dict]
) -> list[dict]:
    """Maximal runs of >= 2 functions sharing one non-None scheduler flag."""
    stretches: list[dict] = []
    run: list[int] = []
    for index in range(len(order) - 1):
        flag = decoded[order[index]]["sched"]
        next_flag = decoded[order[index + 1]]["sched"]
        run.append(order[index])
        if flag is None or flag != next_flag:
            if len(run) >= MIN_GROUP_SIZE:
                stretches.append({"members": list(run), "flag": flag})
            run = []
    flag = decoded[order[-1]]["sched"]
    run.append(order[-1])
    if len(run) >= MIN_GROUP_SIZE:
        stretches.append({"members": list(run), "flag": flag})
    return stretches


def file_agreement(
    groups: list[dict], current_files: dict[int, list[str]]
) -> tuple[int, list[str], int]:
    """(single-file groups, split files, files with grouped markers)."""
    group_ids: dict[int, int] = {}
    for group_index, group in enumerate(groups):
        for member in group["members"]:
            group_ids[member] = group_index
    file_groups: dict[str, set[int]] = collections.defaultdict(set)
    for address, files in current_files.items():
        group_index = group_ids.get(address)
        if group_index is None:
            continue
        for source in files:
            file_groups[source].add(group_index)
    single = 0
    for group in groups:
        files = set()
        for member in group["members"]:
            files.update(current_files.get(member, ()))
        if len(files) == 1:
            single += 1
    split = sorted(
        (source for source, gs in file_groups.items() if len(gs) > 1),
        key=lambda s: -len(file_groups[s]),
    )
    return single, split, len(file_groups)


def summarize(
    groups: list[dict],
    order: list[int],
    current_files: dict[int, list[str]],
    boundaries: list[dict],
    stretches: list[dict],
) -> dict:
    """Headline numbers plus the existing-file agreement / split analysis."""
    in_group: set[int] = set()
    for group in groups:
        in_group.update(group["members"])

    single_file_groups, split_files, with_markers = file_agreement(groups, current_files)

    boundary_counts: collections.Counter = collections.Counter()
    for boundary in boundaries:
        for signal in boundary["signals"]:
            boundary_counts[signal] += 1

    stretch_members = {m for s in stretches for m in s["members"]}
    uncovered_stretches = [
        s for s in stretches if not (set(s["members"]) & in_group)
    ]
    return {
        "groups": {
            "high": sum(1 for g in groups if g["tier"] == "HIGH"),
            "medium": sum(1 for g in groups if g["tier"] == "MEDIUM"),
            "total": len(groups),
            "members": len(in_group),
            "functions": len(order),
            "unassigned": len(order) - len(in_group),
            "single_file_groups": single_file_groups,
        },
        "files": {
            "with_grouped_markers": with_markers,
            "split_across_groups": len(split_files),
            "split_files": split_files,
        },
        "boundary_signal_counts": dict(sorted(boundary_counts.items())),
        "scheduler_stretches": {
            "total": len(stretches),
            "covering_functions": len(stretch_members),
            "uncovered_by_groups": len(uncovered_stretches),
            "uncovered_functions": sum(len(s["members"]) for s in uncovered_stretches),
        },
    }


def is_first_party_source(source: str) -> bool:
    return not (
        source.startswith("src/rw/")
        or source.startswith("src/cri/")
        or source.startswith("src/sce/")
        or source in ("src/crt0.c", "src/libc_core.c", "src/libcdvd.c")
    )


def build_audit(
    windows: dict[int, int],
    image: bytes,
    gp: int,
    p3_files: dict[int, set[str]],
    current_files: dict[int, list[str]],
    base: int = BASE,
) -> dict:
    """Assemble the full audit from raw inputs (pure; unit-testable)."""
    order = sorted(windows)
    decoded = decode_functions(image, windows, gp, base)
    callers = compute_callers(decoded)
    boundaries, frequency = build_pair_evidence(order, decoded, p3_files)
    groups = extract_groups(order, boundaries)
    annotate_groups(groups, decoded, callers, current_files, p3_files)
    stretches = scheduler_stretches(order, decoded)
    summary = summarize(groups, order, current_files, boundaries, stretches)

    p3_member_count = sum(1 for m in order if p3_files.get(m))
    first_party_p3 = sum(
        1 for sources in p3_files.values() if any(is_first_party_source(s) for s in sources)
    )
    return {
        "schema_version": 1,
        "functions": len(order),
        "code_bytes": sum(windows.values()),
        "gp": f"0x{gp:08x}",
        "p3_evidence": {
            "functions_with_sources": p3_member_count,
            "first_party_functions_with_sources": first_party_p3,
        },
        "summary": summary,
        "groups": groups,
        "current_files": current_files,
        "scheduler_stretches": stretches,
        "data_ref_frequency": {
            str(ref): count for ref, count in sorted(frequency.items())
        },
    }


def render_text(audit: dict, min_score: int) -> str:
    """Human-readable report."""
    lines: list[str] = []
    add = lines.append
    summary = audit["summary"]
    add("Persona 4 translation-unit audit (SLUS_217.82)")
    add("=" * 46)
    add(f"functions: {audit['functions']}  code bytes: {audit['code_bytes']}  gp: {audit['gp']}")
    add(
        f"P3 cross-reference: {audit['p3_evidence']['functions_with_sources']} functions "
        f"inherit a P3 source file "
        f"({audit['p3_evidence']['first_party_functions_with_sources']} first-party)"
    )
    add("")
    groups = summary["groups"]
    listed = [g for g in audit["groups"] if g["min_score"] >= min_score]
    add(
        f"PROPOSED TRANSLATION UNITS (boundary score >= {min_score}, "
        f"size >= {MIN_GROUP_SIZE}): {len(listed)} groups, "
        f"{sum(g['size'] for g in listed)} members "
        f"({groups['unassigned']} functions unassigned)"
    )
    add("-" * 46)
    if not listed:
        add("  (none at this confidence; lower --min-score to see more)")
    for rank, group in enumerate(listed, 1):
        files = ", ".join(
            f"{source} ({count}/{group['size']})" for source, count in group["current_files"]
        ) or "(no decompiled source)"
        p3 = ", ".join(f"{source} x{count}" for source, count in group["p3_files"][:2]) or "-"
        signals = " ".join(sorted(group["boundaries"][0]["signals"])) or "-"
        add(
            f"  {rank:>4}  {group['start']:08x}-{group['span_end']:08x}  "
            f"n={group['size']:>3}  {group['tier']:<6} score={group['min_score']}  "
            f"p3=[{p3}]  signals={signals}  callers_local={group['callers_local']}  "
            f"internal_calls={group['internal_calls']}"
        )
        add(f"       current files: {files}")
    add("")
    single, split, with_markers = file_agreement(listed, audit["current_files"])
    add(
        f"Existing-file agreement (over the {len(listed)} listed groups): "
        f"{single} groups lie entirely inside one current source file; "
        f"{len(split)} current files are split across multiple proposed TUs:"
    )
    for source in split:
        add(f"  SPLIT  {source}")
    add("")
    add(
        f"Boundary evidence tallies: {summary['boundary_signal_counts']}"
    )
    stretches = summary["scheduler_stretches"]
    add(
        f"Scheduler-homogeneous stretches: {stretches['total']} covering "
        f"{stretches['covering_functions']} functions; "
        f"{stretches['uncovered_by_groups']} stretches "
        f"({stretches['uncovered_functions']} functions) have no other support "
        f"and are NOT proposed (weakest signal)."
    )
    return "\n".join(lines)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__.split("Usage:")[1] if "Usage:" in __doc__ else None,
    )
    parser.add_argument(
        "--shared-report",
        type=Path,
        default=None,
        help="prebuilt map_shared_p3.py JSON report to read instead of running "
        "map_shared_p3 in-process",
    )
    parser.add_argument(
        "--p3-root",
        type=Path,
        default=DEFAULT_P3_ROOT,
        help=f"P3 FES checkout (default: {DEFAULT_P3_ROOT})",
    )
    parser.add_argument(
        "--p3-report",
        type=Path,
        default=None,
        help="fresh P3 verify.py --json report (default: C:/tmp/p3_full.json, "
        "upgrading to C:/tmp/full_verify.json when the default is a scoped run)",
    )
    parser.add_argument(
        "--min-score",
        type=int,
        default=HIGH_MIN,
        help=f"minimum internal boundary score for listed groups (default: {HIGH_MIN}, HIGH)",
    )
    parser.add_argument(
        "--json",
        type=Path,
        default=None,
        metavar="PATH",
        help="write the machine-readable report to PATH (the only file this tool writes)",
    )
    parser.add_argument(
        "--no-p3",
        action="store_true",
        help="skip the P3 cross-reference signal entirely (debug)",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    windows, _order = load_windows(P4_FUNCTIONS)
    image = load_image(P4_IMAGE)
    target = json.loads(P4_TARGET.read_text(encoding="utf-8"))
    gp = int(target["elf"]["gp"], 0)

    if args.no_p3:
        p3_files: dict[int, set[str]] = {}
        provenance: dict = {"skipped": True}
    else:
        p3_report = choose_p3_report(args.p3_report)
        if args.p3_report is None and p3_report == FULL_P3_REPORT:
            print(
                f"NOTE: default P3 report {DEFAULT_P3_REPORT} is a scoped run; "
                f"using the full report {FULL_P3_REPORT} for source evidence.",
                file=sys.stderr,
            )
        try:
            p3_files, provenance = load_p3_files(p3_report, args.p3_root, args.shared_report)
        except (OSError, ValueError, RuntimeError, json.JSONDecodeError) as error:
            print(f"tu_audit: cannot load P3 evidence: {error}", file=sys.stderr)
            return 2

    current_files = scan_current_files()
    audit = build_audit(windows, image, gp, p3_files, current_files)
    audit["inputs"] = provenance
    print(render_text(audit, args.min_score))
    if args.json:
        args.json.write_text(
            json.dumps(audit, indent=1) + "\n", encoding="utf-8"
        )
        print(f"report: {args.json}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

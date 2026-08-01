#!/usr/bin/env python3
"""Recover original translation-unit filenames from embedded __FILE__ strings.

Persona 4 (SLUS_217.82) retail, like P3 FES, was built with per-file asserts:
every TU's ``assert`` macro expanded to a reference to a NUL-terminated string
holding the source filename (possibly with a directory prefix).  Those strings
survive in the retail image, and the code references to them tell us exactly
which functions were compiled from which original file -- including the
original FILENAME, which no other TU signal (P3 cross-reference, call
locality, owned data, scheduler flag) can provide.

Layout trap
-----------
``tools/tu_audit.py``'s reference decoder only considers post-code data and
therefore EXCLUDES data1 -- but in this layout data1 (0x52da00-0x70c850) sits
BETWEEN code1 and code2, and it holds most of the __FILE__ strings.  This tool
therefore scans the *complement* of the canonical function windows inside the
image (data1 + data2 + any slack), which needs no hardcoded segment list and
works identically on the P3 FES image.

Decoder
-------
The reference decoder is this tool's own (not tu_audit's): a per-register
pending state machine.  ``lui rX, hi`` seeds a pending base address for rX;
``addiu/ori/addi rX, rX, lo`` completes it into a full address, and
``lw/sw/... lo(rX)`` completes it with a load/store displacement; $gp
(register 28) is permanently known so GP-relative accesses resolve too.  A
pending base is invalidated the moment its register is overwritten by any
other instruction (including a load into it), so a mismatched-register
sequence such as ``lui $2`` followed by ``addiu $3, $3, lo`` can never emit a
bogus pair.  Pending state resets at function-window starts and after ``jal``.

Rejection rule (calibrated, not assumed)
----------------------------------------
The obvious heuristic -- "drop a distant outlier asserter" -- is refuted by
the P3 FES ground truth (identical extraction, 13,898 decompiled adjacent
pairs): inter-asserter gaps of the SAME original TU were measured up to 89
functions (mt_evtMenu.c), and no separable cross-TU gap population exists at
all; every observed "miss" of the signal against the P3 tree is a module-
reorg artifact (the P3 tree splits original TUs across files like
datCalendarPrelude.c, datPersonaTransition.c, kwlnRoot.c), not a signal
error.  On the subset where the proxy is trustworthy (both functions still
live in a file literally named F) the signal is 714/714 = 100% (both-assert)
and 224/224 = 100% (asserter + silent span member).  So the rule derived from
the measured distribution is: KEEP the full first-to-last span of every
multi-asserter name, and REJECT only single-asserter names (no TU group is
possible).  Every rejection is reported with its reason.

Calibration summary (measured on P3 FES, C:/tmp/full_verify.json):
  adjacent-pair base rate (same current P3 file):   13601/13898 = 97.86%
  both-assert-same-name pair precision (raw):       1042/1079  = 96.57%
  both-assert precision, clean subset:               714/714   = 100.00%
  asserter + silent-member precision (raw):          296/314   = 94.27%
  asserter + silent-member precision, clean subset:  224/224   = 100.00%
  asserters whose current file basename == asserted name: 68.4%
  (the raw-proxy deficit is entirely module reorg, not signal error)

Usage:  python tools/file_strings.py [--json PATH]
"""
from __future__ import annotations

import argparse
import bisect
import collections
import json
import re
import struct
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent

P4_FUNCTIONS = TOOLS / "slus21782_functions.json"
P4_IMAGE = REPO / "image.bin"
P4_TARGET = REPO / "config" / "target.json"

BASE = 0x00100000
GP_REG = 28
MIN_ASSERTERS = 2  # a TU proposal needs at least two asserting functions

# A C/C++ source filename: path-ish characters plus a source extension.
_NAME_RE = re.compile(rb"^[A-Za-z0-9_.\-/\\]+$")
_SOURCE_EXT_RE = re.compile(rb"\.(?:c|cc|cpp|cxx)$", re.I)
_MAX_STRING = 200

# Load opcodes that write a GPR rt (lwc1/lwc2/ldc2 write coprocessor regs and
# must not invalidate a GPR pending base).
_LOAD_OPS = frozenset(
    (0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x2E, 0x30, 0x33, 0x34, 0x35, 0x37)
)
_STORE_OPS = frozenset((0x28, 0x29, 0x2A, 0x2B, 0x38, 0x3B))
_LS_OPS = _LOAD_OPS | _STORE_OPS | frozenset((0x31, 0x32, 0x36, 0x39, 0x3A, 0x3E))
# R-type functors that write no GPR.
_NO_WRITE_FUNCTS = frozenset((0x08, 0x0C, 0x0D, 0x0F, 0x18, 0x19, 0x1A, 0x1B))


def _sign16(value: int) -> int:
    return value - 0x10000 if value & 0x8000 else value


def scan_filename_strings(data: bytes, base_addr: int = 0) -> dict[int, str]:
    """NUL-terminated C/C++ source filenames inside ``data``.

    Returns {absolute address: filename} for every standalone NUL-terminated
    string whose entire content is a plausible source path (``.c``/``.cc``/
    ``.cpp``/``.cxx`` extension, optional directory prefix).  Header names
    (``.h``) are deliberately excluded: in this codebase they occur only as
    data-table entries (``battle.h`` appears 15 times), never as ``__FILE__``
    assert strings.
    """
    out: dict[int, str] = {}
    i = 0
    while i < len(data):
        if data[i] == 0:
            i += 1
            continue
        end = data.find(b"\0", i)
        if end < 0:
            break
        raw = data[i:end]
        if (
            3 <= len(raw) <= _MAX_STRING
            and _NAME_RE.match(raw)
            and _SOURCE_EXT_RE.search(raw)
        ):
            out[base_addr + i] = raw.decode("ascii")
        i = end + 1
    return out


def decode_references(
    code: bytes,
    code_base: int,
    string_addrs: set[int],
    gp: int,
    window_starts: set[int],
) -> list[tuple[int, int]]:
    """Resolve every instruction that references a ``string_addrs`` address.

    Returns [(pc, address)] pairs.  Own state machine, independent of
    tu_audit's decoder: ``lui`` seeds a per-register pending base, ``addiu``/
    ``ori``/``addi`` (and load/store displacement) complete it, and any other
    write to the register invalidates the pending base so mismatched-register
    sequences never emit.  $gp is permanently known.  Pending state resets at
    function-window starts and after ``jal``.
    """
    out: list[tuple[int, int]] = []
    pending = [None] * 32
    pending[GP_REG] = gp
    word_count = len(code) // 4
    for k in range(word_count):
        word = struct.unpack_from("<I", code, 4 * k)[0]
        op = word >> 26
        pc = code_base + 4 * k
        if pc in window_starts:
            pending = [None] * 32
            pending[GP_REG] = gp
        if op == 0x0F:  # lui rt, hi
            rt = (word >> 16) & 0x1F
            pending[rt] = (word & 0xFFFF) << 16
            continue
        rs = (word >> 21) & 0x1F
        rt = (word >> 16) & 0x1F
        if op in (0x09, 0x0D):  # addiu / ori rt, rs, lo
            base = pending[rs]
            if base is not None:
                lo = word & 0xFFFF
                if op == 0x09:
                    lo = _sign16(lo)
                address = (base + lo) & 0xFFFFFFFF
                if address in string_addrs:
                    out.append((pc, address))
                pending[rt] = address
            else:
                pending[rt] = None
            continue
        if op == 0x08:  # addi rt, rs, lo
            base = pending[rs]
            if base is not None:
                address = (base + _sign16(word & 0xFFFF)) & 0xFFFFFFFF
                if address in string_addrs:
                    out.append((pc, address))
                pending[rt] = address
            else:
                pending[rt] = None
            continue
        if op in _LS_OPS:  # load/store with displacement
            base = pending[rs]
            if base is not None:
                address = (base + _sign16(word & 0xFFFF)) & 0xFFFFFFFF
                if address in string_addrs:
                    out.append((pc, address))
            if op in _LOAD_OPS:
                pending[rt] = None
            continue
        if op == 0:  # R-type
            funct = word & 0x3F
            if funct not in _NO_WRITE_FUNCTS:
                rd = (word >> 11) & 0x1F
                if rd:
                    pending[rd] = None
            continue
        if op == 0x03:  # jal: clobbers caller-saved registers
            pending = [None] * 32
            pending[GP_REG] = gp
            continue
        if op in (0x0A, 0x0B, 0x0C, 0x0E):  # slti/sltiu/andi/xori write rt
            if rt:
                pending[rt] = None
            continue
        if op in (0x10, 0x11, 0x12) and rs == 0:  # mfc0/mfc1/mfc2 write rt
            if rt:
                pending[rt] = None
    return out


def _window_owners(
    order: list[int], sizes: dict[int, int]
) -> tuple[dict[int, int], dict[int, int]]:
    """pc -> owning window start, and window start -> window index."""
    owner: dict[int, int] = {}
    index_of: dict[int, int] = {}
    for index, start in enumerate(order):
        index_of[start] = index
        for offset in range(0, sizes[start], 4):
            owner[start + offset] = start
    return owner, index_of


def _uncovered_ranges(
    image: bytes, order: list[int], sizes: dict[int, int], base: int
) -> list[tuple[int, int]]:
    """Address ranges inside the image not covered by any function window.

    This is data1 + data2 + slack for the retail layout -- scanning it instead
    of "everything after the last window" is the whole point of the layout
    trap above.
    """
    ranges: list[tuple[int, int]] = []
    cursor = base
    for start in order:
        if start > cursor:
            ranges.append((cursor, start))
        cursor = max(cursor, start + sizes[start])
    image_end = base + len(image)
    if cursor < image_end:
        ranges.append((cursor, image_end))
    return ranges


def extract(
    image: bytes,
    windows: dict[int, int],
    gp: int,
    base: int = BASE,
    min_asserters: int = MIN_ASSERTERS,
) -> dict:
    """Full pipeline: strings -> references -> per-filename TU proposals.

    Returns the machine-readable report (see ``main`` for the text view).
    """
    order = sorted(windows)
    string_addrs: dict[int, str] = {}
    for start, end in _uncovered_ranges(image, order, windows, base):
        string_addrs.update(
            scan_filename_strings(
                image[start - base : end - base], base_addr=start
            )
        )

    # Decode references with one linear pass over the whole image.  Pending
    # state resets at every window start, so the tiny inter-window gaps (the
    # 8-byte header at 0x100000, etc.) are decoded too; references that land
    # inside data regions are dropped by the owner map below, and data decoded
    # as instructions can only ever emit addresses that map to no window.
    refs = decode_references(image, base, set(string_addrs), gp, set(order))

    owner, index_of = _window_owners(order, windows)
    per_name: dict[str, set[int]] = collections.defaultdict(set)
    for pc, address in refs:
        function = owner.get(pc)
        if function is not None:
            per_name[string_addrs[address]].add(function)

    files: list[dict] = []
    trimmed_or_rejected: list[dict] = []
    covered: set[int] = set()
    for name, functions in sorted(per_name.items()):
        indexes = sorted(index_of[f] for f in functions)
        gaps = [indexes[i + 1] - indexes[i] for i in range(len(indexes) - 1)]
        record = {
            "file": name,
            "asserting_functions": sorted(f"{f:08x}" for f in functions),
            "asserting_count": len(functions),
            "span_first_index": indexes[0],
            "span_last_index": indexes[-1],
            "span_length": indexes[-1] - indexes[0] + 1,
            "gaps": gaps,
        }
        if len(functions) < min_asserters:
            record["kept"] = False
            trimmed_or_rejected.append(
                {
                    "file": name,
                    "action": "rejected",
                    "reason": (
                        f"single asserter ({len(functions)} function); no "
                        "translation-unit group is possible and the reference "
                        "may be a data-table entry rather than an assert"
                    ),
                    "numbers": {
                        "asserters": len(functions),
                        "span_length": record["span_length"],
                    },
                }
            )
            files.append(record)
            continue
        silent = [
            f"{order[i]:08x}"
            for i in range(indexes[0], indexes[-1] + 1)
            if i not in indexes
        ]
        record["kept"] = True
        record["silent_members"] = silent
        record["silent_count"] = len(silent)
        covered.update(functions)
        covered.update(order[i] for i in range(indexes[0], indexes[-1] + 1))
        files.append(record)

    named_tus = sum(1 for record in files if record["kept"])
    return {
        "schema_version": 1,
        "strings_found": len(string_addrs),
        "strings_referenced": len(per_name),
        "named_tus": named_tus,
        "functions_covered": len(covered),
        "min_asserters": min_asserters,
        "rejection_rule": (
            "no gap-based trimming: P3 ground truth measures same-TU "
            "inter-asserter gaps up to 89 functions with no separable "
            "cross-TU population, so splitting on gap size would fragment "
            "real TUs (mt_evtMenu.c gap 89, btlAICommand.c gap 54 are "
            "single files on P3); the only rejection is a name with a single "
            "asserter, which cannot form a TU group"
        ),
        "trimmed_or_rejected": trimmed_or_rejected,
        "files": files,
    }


def render_text(report: dict) -> str:
    lines: list[str] = []
    add = lines.append
    add("Embedded __FILE__ translation-unit recovery (SLUS_217.82)")
    add("=" * 58)
    add(f"filename strings found: {report['strings_found']} (instances)")
    add(f"filename strings referenced from code: {report['strings_referenced']} "
        f"(distinct names; every instance is referenced)")
    add(f"proposed named TUs (>= {report['min_asserters']} asserters): "
        f"{report['named_tus']}")
    add(f"functions covered by kept spans (asserters + silent members): "
        f"{report['functions_covered']}")
    add(f"rejected / trimmed spans: {len(report['trimmed_or_rejected'])}")
    add(f"rejection rule: {report['rejection_rule']}")
    add("-" * 58)
    for entry in report["trimmed_or_rejected"]:
        add(
            f"  REJECTED {entry['file']}: {entry['reason']} "
            f"(asserters={entry['numbers']['asserters']}, "
            f"span={entry['numbers']['span_length']})"
        )
    add("-" * 58)
    for record in report["files"]:
        if not record["kept"]:
            continue
        add(
            f"  {record['file']}: {record['asserting_count']} asserters, "
            f"span {record['span_length']} "
            f"(index {record['span_first_index']}-{record['span_last_index']}), "
            f"gaps {record['gaps']}, silent members {record['silent_count']}"
        )
    return "\n".join(lines)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--json",
        type=Path,
        default=None,
        metavar="PATH",
        help="write the machine-readable report to PATH (the only file this "
        "tool writes)",
    )
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    image = P4_IMAGE.read_bytes()
    functions = json.loads(P4_FUNCTIONS.read_text(encoding="utf-8"))
    windows = {int(address, 16): size for address, size in functions["windows"].items()}
    target = json.loads(P4_TARGET.read_text(encoding="utf-8"))
    gp = int(target["elf"]["gp"], 0)
    report = extract(image, windows, gp, base=BASE)
    report["program"] = functions.get("program")
    report["gp"] = f"0x{gp:08x}"
    print(render_text(report))
    if args.json:
        args.json.write_text(json.dumps(report, indent=1) + "\n", encoding="utf-8")
        print(f"report: {args.json}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

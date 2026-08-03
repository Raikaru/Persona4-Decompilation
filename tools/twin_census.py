#!/usr/bin/env python3
"""Find P4 functions whose retail code has a structural twin in a donor tree.

Persona 3 FES and Persona 4 share large amounts of source, built with the same
compiler.  Where a P4 function is still ``INCLUDE_ASM`` but the donor tree has a
byte-exact match for the same function, the donor's C *is* the answer -- only
symbol names, data addresses and literal constants need adapting.  Porting it
beats rediscovering the shape by permutation.

The join key is a *structural fingerprint*: every instruction word keeps its
opcode and register fields but drops the fields that legitimately differ between
the two games -- 16-bit immediates (data addresses, struct offsets, constants),
branch displacements and jump targets.  Two functions of identical size whose
fingerprints agree have the same control flow, the same register allocation and
the same instruction selection, which is exactly the part that is hard to
recover.

``raw_similarity`` (the fraction of *whole* words that are bit-identical) is
reported so a caller can tell a confirmed twin from a shape coincidence; short
accessors are easy to match by shape alone, so prefer high similarity and, as
independent corroboration, a donor file with the same name.

Donor location comes from ``--donor-repo`` / ``--donor-elf`` or the
``P4_DONOR_REPO`` / ``P4_DONOR_ELF`` environment variables; nothing
machine-local is committed.
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import json
import os
import pathlib
import re
import struct
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import verify  # noqa: E402  (local tool module)

# Opcode groups whose 16-bit field is a branch displacement.
_BRANCH_OPS = frozenset({0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17})
# SPECIAL and MMI keep every field: they are pure register operations.
_REGISTER_OPS = frozenset({0x00, 0x1C})
_COP_OPS = frozenset({0x11, 0x12})
_JUMP_OPS = frozenset({0x02, 0x03})
# COP1/COP2 sub-opcode 8 is BC1x/BC2x -- a branch, so its displacement goes.
_COP_BRANCH_SUB = 0x08


def structural_word(word: int) -> int:
    """Mask the fields of one instruction that may differ between games."""
    op = word >> 26
    if op in _REGISTER_OPS:
        return word
    if op in _JUMP_OPS:
        return op << 26
    if op in _BRANCH_OPS:
        return word & 0xFFFF0000
    if op in _COP_OPS:
        sub = (word >> 21) & 0x1F
        body = 0 if sub == _COP_BRANCH_SUB else word & 0x1FFFFF
        return (op << 26) | (sub << 21) | body
    return word & 0xFFFF0000


def fingerprint(code: bytes) -> str:
    """Structural hash of a function body."""
    masked = bytearray()
    for offset in range(0, len(code) & ~3, 4):
        (word,) = struct.unpack_from("<I", code, offset)
        masked += struct.pack("<I", structural_word(word))
    return hashlib.sha1(bytes(masked)).hexdigest()


def raw_similarity(a: bytes, b: bytes) -> float:
    """Fraction of whole words that are bit-identical."""
    words = min(len(a), len(b)) // 4
    if not words:
        return 0.0
    same = sum(1 for i in range(0, words * 4, 4) if a[i : i + 4] == b[i : i + 4])
    return same / words


def load_segment(elf_path: str) -> tuple[bytes, int, int]:
    """Return (image, file_offset, vaddr) for the lowest loadable segment."""
    buf = pathlib.Path(elf_path).read_bytes()
    ph_off = struct.unpack_from("<I", buf, 0x1C)[0]
    ph_size = struct.unpack_from("<H", buf, 0x2A)[0]
    count = struct.unpack_from("<H", buf, 0x2C)[0]
    best: tuple[int, int] | None = None
    for i in range(count):
        base = ph_off + i * ph_size
        p_type, p_offset, p_vaddr, _p_paddr, p_filesz = struct.unpack_from(
            "<IIIII", buf, base
        )
        if p_type == 1 and p_filesz and (best is None or p_vaddr < best[1]):
            best = (p_offset, p_vaddr)
    if best is None:
        raise SystemExit(f"{elf_path}: no loadable segment")
    return buf, best[0], best[1]


class Image:
    """Retail bytes addressed by virtual address."""

    def __init__(self, elf_path: str) -> None:
        self.buf, self.offset, self.vaddr = load_segment(elf_path)

    def code(self, addr: int, size: int) -> bytes:
        start = addr - self.vaddr + self.offset
        if start < 0:
            return b""
        return self.buf[start : start + size]


def load_windows(path: pathlib.Path) -> dict[int, int]:
    data = json.loads(path.read_text(encoding="utf-8"))
    return {int(k, 16): v for k, v in data["windows"].items()}


def statuses(report_path: pathlib.Path) -> list[dict]:
    return json.loads(report_path.read_text(encoding="utf-8"))["results"]


# A donor "match" is only portable if it is actually C. The donor tree also
# matches functions by writing them as MWCC `asm` functions or by dropping
# inline asm into an otherwise-C body; neither can be copied here, because
# decomp_lint permits inline asm only for COP2/VU0 (H009) and an asm function
# is just the retail bytes again -- exactly what INCLUDE_ASM already gives us.
_ASM_FUNCTION = re.compile(r"^\s*(static\s+)?asm\s+\w")
_ASM_DIRECTIVE = re.compile(r"^\s*\.(set|word|globl|align|ent|end)\b", re.M)
# The donor spells inline asm at least four ways: `__asm__`, `asm volatile`,
# `asm __volatile__` (the form in rw/rwplcore.c) and a bare `asm (`. Missing a
# spelling sends an agent off to port a body it is not allowed to copy, so match
# the keyword plus any volatile decoration rather than one fixed phrase.
_INLINE_ASM = re.compile(r"__asm__|\basm\b\s*(__volatile__|volatile)?\s*[({]")
# Assembler directives also appear inside the string operands of such a body
# (".word 0x00451818 ;"), where the leading quote defeats a line-anchored match.
_QUOTED_DIRECTIVE = re.compile(r"[\"']\s*\.(set|word|globl|align|ent|end)\b")
_VU0 = re.compile(
    r"\b(lqc2|sqc2|qmtc2|qmfc2|"
    r"v(add|sub|mul|madd|mula|msub|opmula|opmsub|rsqrt|itof|ftoi|clip|div|"
    r"sqrt|move|mr32|abs|max|mini|iadd|isub|iand|ilw|isw)\w*)\b"
)


def donor_body(lines: list[str], line: int) -> tuple[str, str]:
    """Return (declaration, body) for the donor function starting near `line`."""
    index = line - 1
    declaration = ""
    for probe in range(max(0, line - 2), min(len(lines), line + 3)):
        text = lines[probe]
        if "(" in text and not text.lstrip().startswith(("//", "/*", "*")):
            declaration = text
            break
    while index < len(lines) and "{" not in lines[index]:
        index += 1
    depth = 0
    body: list[str] = []
    while index < len(lines):
        body.append(lines[index])
        depth += lines[index].count("{") - lines[index].count("}")
        if depth <= 0 and len(body) > 1:
            break
        index += 1
    return declaration, "\n".join(body)


def classify_donor(declaration: str, body: str) -> str:
    """How the donor achieved its match, and therefore whether we can copy it."""
    if (
        _ASM_FUNCTION.match(declaration)
        or _ASM_DIRECTIVE.search(body)
        or _QUOTED_DIRECTIVE.search(body)
    ):
        return "asm_function"
    if _INLINE_ASM.search(body):
        return "vu0_asm" if _VU0.search(body) else "banned_asm"
    return "portable"


def _kind_of(
    donor_root: pathlib.Path | None,
    cache: dict[str, list[str]],
    donor_file: str,
    line: int,
) -> str:
    """Classify a donor function, or "unknown" when its source is unavailable."""
    if donor_root is None:
        return "unknown"
    if donor_file not in cache:
        path = donor_root / donor_file
        try:
            cache[donor_file] = path.read_text(
                encoding="utf-8", errors="replace"
            ).splitlines()
        except OSError:
            cache[donor_file] = []
    lines = cache[donor_file]
    if not lines:
        return "unknown"
    return classify_donor(*donor_body(lines, line))


def find_twins(
    *,
    report: pathlib.Path,
    windows: pathlib.Path,
    elf: str,
    donor_report: pathlib.Path,
    donor_windows: pathlib.Path,
    donor_elf: str,
    min_size: int = 16,
    donor_root: pathlib.Path | None = None,
) -> list[dict]:
    """P4 first-party ASM functions whose twin is MATCHED in the donor tree."""
    own = Image(elf)
    donor = Image(donor_elf)
    own_windows = load_windows(windows)
    donor_windows_map = load_windows(donor_windows)

    donor_matched = {
        int(r["addr"], 16): r
        for r in statuses(donor_report)
        if r.get("status") == "MATCH"
    }

    # Fingerprint every donor function that has usable C.
    index: dict[tuple[int, str], list[int]] = collections.defaultdict(list)
    for addr, meta in donor_matched.items():
        size = donor_windows_map.get(addr)
        if not size or size < min_size:
            continue
        code = donor.code(addr, size)
        if len(code) < size:
            continue
        index[(size, fingerprint(code))].append(addr)

    donor_sources: dict[str, list[str]] = {}
    rows: list[dict] = []
    for entry in statuses(report):
        if entry.get("status") != "ASM":
            continue
        if verify.is_third_party(pathlib.Path(entry["file"])):
            continue
        addr = int(entry["addr"], 16)
        size = own_windows.get(addr)
        if not size or size < min_size:
            continue
        code = own.code(addr, size)
        if len(code) < size:
            continue
        for donor_addr in index.get((size, fingerprint(code)), ()):
            meta = donor_matched[donor_addr]
            own_file = entry["file"].replace("\\", "/")
            donor_file = meta["file"].replace("\\", "/")
            rows.append(
                {
                    "addr": "%08x" % addr,
                    "name": entry["name"],
                    "file": own_file,
                    "size": size,
                    "donor_addr": "%08x" % donor_addr,
                    "donor_name": meta["name"],
                    "donor_file": donor_file,
                    "donor_line": meta["line"],
                    "raw_similarity": round(
                        raw_similarity(code, donor.code(donor_addr, size)), 4
                    ),
                    "same_filename": pathlib.PurePosixPath(own_file).name
                    == pathlib.PurePosixPath(donor_file).name,
                    "donor_kind": _kind_of(
                        donor_root, donor_sources, donor_file, meta["line"]
                    ),
                }
            )

    # A shape can recur across many donor functions (short accessors especially).
    # Keep the best-corroborated donor per target and count the alternatives, so
    # the census counts functions to port rather than candidate pairs.
    best: dict[str, dict] = {}
    for row in rows:
        prior = best.get(row["addr"])
        rank = (row["same_filename"], row["raw_similarity"])
        if prior is None or rank > (prior["same_filename"], prior["raw_similarity"]):
            row["donor_alternatives"] = prior["donor_alternatives"] + 1 if prior else 0
            best[row["addr"]] = row
        else:
            prior["donor_alternatives"] += 1
    deduped = sorted(
        best.values(),
        key=lambda r: (-r["same_filename"], -r["raw_similarity"], -r["size"]),
    )
    return deduped


def _resolve(value: str | None, env: str, label: str) -> str:
    found = value or os.environ.get(env)
    if not found:
        raise SystemExit(f"{label} not set: pass the flag or export {env}")
    return found


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", required=True, help="verify.py --json report")
    parser.add_argument("--donor-repo", help="donor decomp checkout (P4_DONOR_REPO)")
    parser.add_argument("--donor-elf", help="donor retail ELF (P4_DONOR_ELF)")
    parser.add_argument("--donor-report", help="donor verify.py --json report")
    parser.add_argument("--json", help="write the census here")
    parser.add_argument(
        "--min-similarity",
        type=float,
        default=0.0,
        help="drop twins below this raw-word identity",
    )
    parser.add_argument(
        "--all-kinds",
        action="store_true",
        help="also list twins whose donor is hand-written asm or uses banned asm",
    )
    parser.add_argument("--limit", type=int, default=40, help="rows to print")
    args = parser.parse_args(argv)

    repo = pathlib.Path(__file__).resolve().parent.parent
    donor_repo = pathlib.Path(_resolve(args.donor_repo, "P4_DONOR_REPO", "donor repo"))
    donor_elf = _resolve(args.donor_elf, "P4_DONOR_ELF", "donor ELF")
    donor_report = args.donor_report or os.environ.get("P4_DONOR_REPORT")
    if not donor_report:
        raise SystemExit("--donor-report not set (or export P4_DONOR_REPORT)")

    donor_windows = next(donor_repo.glob("tools/slus*_functions.json"), None)
    if donor_windows is None:
        raise SystemExit(f"{donor_repo}: no tools/slus*_functions.json")

    rows = find_twins(
        report=pathlib.Path(args.report),
        windows=repo / "tools" / "slus21782_functions.json",
        elf=verify.load_config()["retail_elf"],
        donor_report=pathlib.Path(donor_report),
        donor_windows=donor_windows,
        donor_elf=donor_elf,
        donor_root=donor_repo,
    )
    rows = [r for r in rows if r["raw_similarity"] >= args.min_similarity]

    kinds = collections.Counter(r["donor_kind"] for r in rows)
    print("structural twins: %d" % len(rows))
    for kind in ("portable", "asm_function", "banned_asm", "vu0_asm", "unknown"):
        if kinds[kind]:
            print("  %-13s %d" % (kind, kinds[kind]))
    if not args.all_kinds:
        rows = [r for r in rows if r["donor_kind"] == "portable"]

    per_file = collections.Counter(r["file"] for r in rows)
    print(
        "\nlisted: %d functions, %d retail bytes, %d destination files"
        % (len(rows), sum(r["size"] for r in rows), len(per_file))
    )
    confirmed = sum(1 for r in rows if r["same_filename"])
    print("  donor file has the same name (independent corroboration): %d" % confirmed)
    for name, count in per_file.most_common(args.limit):
        print("  %-46s %d" % (name, count))

    if args.json:
        pathlib.Path(args.json).write_text(
            json.dumps({"twins": rows}, indent=2), encoding="utf-8"
        )
        print("report: %s" % args.json)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

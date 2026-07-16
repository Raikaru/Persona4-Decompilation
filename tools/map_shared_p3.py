#!/usr/bin/env python3
"""Map compiled functions shared by Persona 3 FES and Persona 4.

The comparison is deliberately conservative. Raw matches require identical
function bytes. Address-normalized matches additionally ignore only MIPS fields
owned by linkage or executable layout: J/JAL targets, LUI immediates,
GP-relative immediates, and low halves paired with a recent LUI. Opcodes,
registers, constants, branches, and instruction order otherwise remain exact.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
P4_TARGET = REPO / "config" / "target.json"
P4_FUNCTIONS = REPO / "tools" / "slus21782_functions.json"
P4_IMAGE = REPO / "image.bin"
DEFAULT_OUTPUT = REPO / "build" / "shared_p3.json"
P3_PROGRAM = "SLUS_216.21"
P4_PROGRAM = "SLUS_217.82"
MARKER_RE = re.compile(r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\b", re.MULTILINE)
GP_RE = re.compile(r"^\s*_gp\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;", re.MULTILINE)
ADDRESS_IMMEDIATE_OPS = {
    8, 9, 13, 24, 25, 26, 27,
    *range(32, 64),
}
NON_WRITING_RT_OPS = {
    9, 13, 15, 25,
    40, 41, 42, 43, 44, 45, 46, 47,
    49, 50, 51, 53, 54, 57, 58, 61, 62, 63,
}


class MappingError(RuntimeError):
    pass


def sha1_bytes(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def sha1_file(path: Path) -> str:
    digest = hashlib.sha1()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(4 * 1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def load_json(path: Path) -> dict:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise MappingError(f"cannot read {path}: {error}") from error


def load_windows(path: Path, expected_program: str) -> tuple[dict, dict[int, int]]:
    metadata = load_json(path)
    if metadata.get("program") != expected_program:
        raise MappingError(
            f"{path} describes {metadata.get('program')!r}, expected {expected_program}"
        )
    raw_windows = metadata.get("windows")
    if not isinstance(raw_windows, dict):
        raise MappingError(f"{path} has no function-window map")
    try:
        windows = {int(address, 16): int(size) for address, size in raw_windows.items()}
    except (TypeError, ValueError) as error:
        raise MappingError(f"{path} contains an invalid function window: {error}") from error
    if metadata.get("function_count") != len(windows):
        raise MappingError(
            f"{path} function_count is {metadata.get('function_count')}, found {len(windows)} windows"
        )
    for address, size in windows.items():
        if address % 4 or size <= 0 or size % 4:
            raise MappingError(f"invalid function window {address:#x}+{size:#x} in {path}")
    return metadata, dict(sorted(windows.items()))


def validate_image(image: bytes, windows: dict[int, int], base: int, label: str) -> None:
    if not windows:
        raise MappingError(f"{label} function map is empty")
    for address, size in windows.items():
        offset = address - base
        if offset < 0 or offset + size > len(image):
            raise MappingError(
                f"{label} window {address:#x}+{size:#x} is outside image "
                f"{base:#x}-{base + len(image):#x}"
            )


def function_bytes(image: bytes, base: int, address: int, size: int) -> bytes:
    offset = address - base
    return image[offset : offset + size]


def words(data: bytes) -> list[int]:
    aligned = len(data) // 4 * 4
    return list(struct.unpack("<" + "I" * (aligned // 4), data[:aligned]))


def normalize_mips(data: bytes) -> bytes:
    """Mask address-bearing MIPS fields while preserving instruction shape."""
    active_hi: dict[int, int] = {}
    output: list[int] = []
    for word in words(data):
        opcode = word >> 26
        source = (word >> 21) & 31
        target = (word >> 16) & 31
        active_hi = {register: age + 1 for register, age in active_hi.items() if age < 8}

        normalized = word
        if opcode in (2, 3):
            normalized = word & 0xFC000000
        elif opcode == 15:
            normalized = word & 0xFFFF0000
            active_hi[target] = 0
        elif opcode in ADDRESS_IMMEDIATE_OPS and (source == 28 or source in active_hi):
            normalized = word & 0xFFFF0000
        output.append(normalized)

        if target in active_hi and opcode not in NON_WRITING_RT_OPS:
            active_hi.pop(target, None)

    packed = struct.pack("<" + "I" * len(output), *output) if output else b""
    return packed + data[len(output) * 4 :]


def index_functions(
    image: bytes, base: int, windows: dict[int, int], normalized: bool
) -> dict[tuple[int, bytes], list[int]]:
    index: dict[tuple[int, bytes], list[int]] = defaultdict(list)
    for address, size in windows.items():
        body = function_bytes(image, base, address, size)
        key_body = normalize_mips(body) if normalized else body
        index[(size, key_body)].append(address)
    return dict(index)


def sign_extend_16(value: int) -> int:
    return value - 0x10000 if value & 0x8000 else value


def jump_target(pc: int, word: int) -> int:
    return ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)


def in_image(address: int, base: int, image: bytes) -> bool:
    return base <= address < base + len(image)


def relocated_references(
    p3_body: bytes,
    p4_body: bytes,
    p3_address: int,
    p4_address: int,
    p3_base: int,
    p4_base: int,
    p3_image: bytes,
    p4_image: bytes,
    p3_functions: set[int],
    p4_functions: set[int],
    p3_gp: int | None,
    p4_gp: int | None,
) -> list[dict]:
    """Decode corresponding direct calls and relocated address constructions."""
    p3_words, p4_words = words(p3_body), words(p4_body)
    references: list[dict] = []
    active_hi: dict[int, tuple[int, int, int]] = {}

    def add(kind: str, offset: int, p3_target: int, p4_target: int) -> None:
        references.append(
            {
                "kind": kind,
                "offset": offset,
                "p3_address": f"{p3_target:08x}",
                "p4_address": f"{p4_target:08x}",
            }
        )

    for index, (p3_word, p4_word) in enumerate(zip(p3_words, p4_words)):
        offset = index * 4
        p3_opcode, p4_opcode = p3_word >> 26, p4_word >> 26
        p3_source, p4_source = (p3_word >> 21) & 31, (p4_word >> 21) & 31
        p3_target_reg, p4_target_reg = (p3_word >> 16) & 31, (p4_word >> 16) & 31
        active_hi = {
            register: (p3_high, p4_high, age + 1)
            for register, (p3_high, p4_high, age) in active_hi.items()
            if age < 8
        }

        if p3_opcode == p4_opcode and p3_opcode in (2, 3):
            p3_target = jump_target(p3_address + offset, p3_word)
            p4_target = jump_target(p4_address + offset, p4_word)
            if p3_target in p3_functions and p4_target in p4_functions:
                add("jal" if p3_opcode == 3 else "j", offset, p3_target, p4_target)

        if (
            p3_opcode == p4_opcode == 15
            and p3_target_reg == p4_target_reg
        ):
            active_hi[p3_target_reg] = (p3_word & 0xFFFF, p4_word & 0xFFFF, 0)
        elif (
            p3_opcode == p4_opcode
            and p3_opcode != 0
            and p3_source == p4_source
            and p3_source in active_hi
        ):
            p3_high, p4_high, _age = active_hi[p3_source]
            if p3_opcode == 13:
                p3_value = (p3_high << 16) | (p3_word & 0xFFFF)
                p4_value = (p4_high << 16) | (p4_word & 0xFFFF)
            else:
                p3_value = (p3_high << 16) + sign_extend_16(p3_word & 0xFFFF)
                p4_value = (p4_high << 16) + sign_extend_16(p4_word & 0xFFFF)
            if in_image(p3_value, p3_base, p3_image) and in_image(p4_value, p4_base, p4_image):
                add("hi_lo", offset, p3_value, p4_value)

        if (
            p3_gp is not None
            and p4_gp is not None
            and p3_opcode == p4_opcode
            and p3_opcode != 0
            and p3_source == p4_source == 28
        ):
            p3_value = p3_gp + sign_extend_16(p3_word & 0xFFFF)
            p4_value = p4_gp + sign_extend_16(p4_word & 0xFFFF)
            if in_image(p3_value, p3_base, p3_image) and in_image(p4_value, p4_base, p4_image):
                add("gp_relative", offset, p3_value, p4_value)

        if p3_target_reg in active_hi and p3_opcode not in NON_WRITING_RT_OPS:
            active_hi.pop(p3_target_reg, None)

    return references


def load_gp(path: Path) -> int | None:
    if not path.is_file():
        return None
    match = GP_RE.search(path.read_text(encoding="utf-8", errors="replace"))
    return int(match.group(1), 0) if match else None


def load_source_evidence(p3_root: Path) -> tuple[set[int], dict[int, list[str]], str]:
    metrics_path = p3_root / "progress" / "metrics.json"
    metrics = load_json(metrics_path)
    try:
        matched = {int(address, 16) for address in metrics["matching"]["addresses"]}
    except (KeyError, TypeError, ValueError) as error:
        raise MappingError(f"invalid matching addresses in {metrics_path}: {error}") from error

    sources: dict[int, set[str]] = defaultdict(set)
    source_root = p3_root / "src"
    if not source_root.is_dir():
        raise MappingError(f"P3 source directory does not exist: {source_root}")
    for path in sorted(source_root.rglob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        relative = path.relative_to(p3_root).as_posix()
        for match in MARKER_RE.finditer(text):
            address = int(match.group(1), 16)
            if address in matched:
                sources[address].add(relative)
    return matched, {address: sorted(paths) for address, paths in sources.items()}, sha1_file(metrics_path)


def compare_functions(
    p3_image: bytes,
    p3_windows: dict[int, int],
    p4_image: bytes,
    p4_windows: dict[int, int],
    *,
    p3_base: int = 0x00100000,
    p4_base: int = 0x00100000,
    p3_gp: int | None = None,
    p4_gp: int | None = None,
    p3_verified: set[int] | None = None,
    p3_sources: dict[int, list[str]] | None = None,
) -> tuple[dict, list[dict]]:
    validate_image(p3_image, p3_windows, p3_base, "P3")
    validate_image(p4_image, p4_windows, p4_base, "P4")
    exact_index = index_functions(p3_image, p3_base, p3_windows, normalized=False)
    normalized_index = index_functions(p3_image, p3_base, p3_windows, normalized=True)
    p3_function_set, p4_function_set = set(p3_windows), set(p4_windows)
    verified = p3_verified or set()
    sources = p3_sources or {}

    matches: list[dict] = []
    exact_count = exact_bytes = exact_unique_count = exact_unique_bytes = 0
    normalized_count = normalized_bytes = normalized_unique_count = normalized_unique_bytes = 0
    verified_count = verified_bytes = 0

    for p4_address, size in p4_windows.items():
        p4_body = function_bytes(p4_image, p4_base, p4_address, size)
        exact_hits = exact_index.get((size, p4_body), [])
        normalized_hits = normalized_index.get((size, normalize_mips(p4_body)), [])
        if exact_hits:
            exact_count += 1
            exact_bytes += size
            if len(exact_hits) == 1:
                exact_unique_count += 1
                exact_unique_bytes += size
        if not normalized_hits:
            continue

        normalized_count += 1
        normalized_bytes += size
        unique = len(normalized_hits) == 1
        if unique:
            normalized_unique_count += 1
            normalized_unique_bytes += size
        evidence = [
            {
                "address": f"{address:08x}",
                "verifier_match": address in verified,
                "sources": sources.get(address, []),
            }
            for address in normalized_hits
        ]
        if unique and normalized_hits[0] in verified:
            verified_count += 1
            verified_bytes += size

        entry = {
            "p4_address": f"{p4_address:08x}",
            "size": size,
            "match_type": "exact" if exact_hits else "address_normalized",
            "unique": unique,
            "p3_addresses": [f"{address:08x}" for address in normalized_hits],
            "exact_p3_addresses": [f"{address:08x}" for address in exact_hits],
            "p3_evidence": evidence,
            "references": [],
        }
        if unique:
            p3_address = normalized_hits[0]
            p3_body = function_bytes(p3_image, p3_base, p3_address, size)
            entry["references"] = relocated_references(
                p3_body,
                p4_body,
                p3_address,
                p4_address,
                p3_base,
                p4_base,
                p3_image,
                p4_image,
                p3_function_set,
                p4_function_set,
                p3_gp,
                p4_gp,
            )
        matches.append(entry)

    p4_code_bytes = sum(p4_windows.values())

    def stats(count: int, byte_count: int, unique_count: int, unique_byte_count: int) -> dict:
        return {
            "functions": count,
            "function_percent": round(count * 100 / len(p4_windows), 6),
            "bytes": byte_count,
            "byte_percent": round(byte_count * 100 / p4_code_bytes, 6),
            "unique_functions": unique_count,
            "unique_bytes": unique_byte_count,
        }

    summary = {
        "p3_functions": len(p3_windows),
        "p4_functions": len(p4_windows),
        "p4_code_bytes": p4_code_bytes,
        "exact": stats(exact_count, exact_bytes, exact_unique_count, exact_unique_bytes),
        "address_normalized": stats(
            normalized_count,
            normalized_bytes,
            normalized_unique_count,
            normalized_unique_bytes,
        ),
        "p3_verifier_matched_unique": {
            "functions": verified_count,
            "bytes": verified_bytes,
        },
    }
    return summary, matches


def build_report(args: argparse.Namespace) -> dict:
    p3_root = args.p3_root.resolve()
    p3_image_path = p3_root / "image.bin"
    p3_functions_path = p3_root / "tools" / "slus21621_functions.json"
    p3_symbols_path = p3_root / "config" / "symbols_recovered.txt"

    target = load_json(P4_TARGET)
    p4_metadata, p4_windows = load_windows(P4_FUNCTIONS, P4_PROGRAM)
    p3_metadata, p3_windows = load_windows(p3_functions_path, P3_PROGRAM)
    if p4_metadata.get("sha1") != target["elf"]["sha1"]:
        raise MappingError("P4 function map does not describe config/target.json")
    try:
        p4_image = P4_IMAGE.read_bytes()
        p3_image = p3_image_path.read_bytes()
    except OSError as error:
        raise MappingError(f"cannot read executable image: {error}") from error
    if sha1_bytes(p4_image) != target["image"]["sha1"]:
        raise MappingError("P4 image.bin SHA-1 does not match config/target.json")

    verified: set[int] = set()
    sources: dict[int, list[str]] = {}
    metrics_sha1: str | None = None
    if args.with_source_evidence:
        verified, sources, metrics_sha1 = load_source_evidence(p3_root)
        metrics = load_json(p3_root / "progress" / "metrics.json")
        expected_image_sha1 = metrics.get("hashes", {}).get("image_sha1")
        if expected_image_sha1 and sha1_bytes(p3_image) != expected_image_sha1:
            raise MappingError("P3 image.bin SHA-1 does not match progress/metrics.json")

    p3_base, p4_base = args.p3_base, int(target["elf"]["load_vram"], 0)
    p3_gp = load_gp(p3_symbols_path)
    p4_gp = int(target["elf"]["gp"], 0)
    summary, matches = compare_functions(
        p3_image,
        p3_windows,
        p4_image,
        p4_windows,
        p3_base=p3_base,
        p4_base=p4_base,
        p3_gp=p3_gp,
        p4_gp=p4_gp,
        p3_verified=verified,
        p3_sources=sources,
    )
    return {
        "schema_version": 1,
        "normalization": {
            "masked_fields": [
                "J/JAL target",
                "LUI immediate",
                "GP-relative immediate",
                "low immediate paired with a LUI in the preceding eight instructions",
            ],
            "preserved_fields": [
                "opcode",
                "register operands",
                "non-address constants",
                "branch displacements",
                "instruction order",
            ],
        },
        "inputs": {
            "p3": {
                "program": p3_metadata["program"],
                "elf_sha1": p3_metadata["sha1"],
                "image_sha1": sha1_bytes(p3_image),
                "function_map_sha1": sha1_file(p3_functions_path),
                "metrics_sha1": metrics_sha1,
                "load_vram": f"0x{p3_base:08x}",
                "gp": f"0x{p3_gp:08x}" if p3_gp is not None else None,
            },
            "p4": {
                "program": p4_metadata["program"],
                "elf_sha1": p4_metadata["sha1"],
                "image_sha1": sha1_bytes(p4_image),
                "function_map_sha1": sha1_file(P4_FUNCTIONS),
                "load_vram": f"0x{p4_base:08x}",
                "gp": f"0x{p4_gp:08x}",
            },
        },
        "summary": summary,
        "matches": matches,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--p3-root",
        type=Path,
        required=True,
        help="Persona3-FES-Decompilation checkout containing image.bin and its canonical function map",
    )
    parser.add_argument(
        "--p3-base",
        type=lambda value: int(value, 0),
        default=0x00100000,
        help="P3 image load address (default: 0x00100000)",
    )
    parser.add_argument(
        "--with-source-evidence",
        action="store_true",
        help="annotate P3 verifier matches and source locations from progress/metrics.json and src/",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=DEFAULT_OUTPUT,
        help="JSON report path (default: build/shared_p3.json)",
    )
    args = parser.parse_args()
    try:
        report = build_report(args)
    except MappingError as error:
        parser.error(str(error))

    output = args.output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    temporary = output.with_name(output.name + ".tmp")
    temporary.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    temporary.replace(output)

    summary = report["summary"]
    exact = summary["exact"]
    normalized = summary["address_normalized"]
    verified = summary["p3_verifier_matched_unique"]
    print(f"P3 functions: {summary['p3_functions']}")
    print(f"P4 functions: {summary['p4_functions']} ({summary['p4_code_bytes']} code bytes)")
    print(
        f"exact: {exact['functions']} functions ({exact['function_percent']:.3f}%), "
        f"{exact['bytes']} bytes ({exact['byte_percent']:.3f}%)"
    )
    print(
        f"address-normalized: {normalized['functions']} functions "
        f"({normalized['function_percent']:.3f}%), {normalized['bytes']} bytes "
        f"({normalized['byte_percent']:.3f}%), {normalized['unique_functions']} unique"
    )
    if args.with_source_evidence:
        print(
            f"unique mappings with verifier-matched P3 source: "
            f"{verified['functions']} functions, {verified['bytes']} bytes"
        )
    try:
        display_path = output.relative_to(REPO)
    except ValueError:
        display_path = output
    print(f"report: {display_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

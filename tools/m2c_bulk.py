#!/usr/bin/env python3
"""Generate grouped m2c C candidates for fallback Persona 4 functions.

The generated files live under ``build/m2c_candidates`` and, by default, under
``src/generated``. They are deliberately separate from the authoritative
exact-retail ownership files. m2c output is useful recovery evidence, but it
is not promoted into the matching build until its C source has been reviewed
and verified. Every requested boundary still gets a grouped C owner:
successful m2c output where possible, otherwise the existing exact-retail
inline-assembly body.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import json
import os
from pathlib import Path
import struct
import re
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from typing import Iterable

REPO = Path(__file__).resolve().parents[1]
FUNCTION_MAP = REPO / "build" / "function_map.txt"
FUNCTION_SOURCES = REPO / "build" / "function_sources"
OUTPUT_DEFAULT = REPO / "build" / "m2c_candidates"
M2C_DEFAULT = REPO / "tools" / "vendor" / "m2c" / "m2c.py"
ASM_PATHS = (REPO / "asm" / "code1.s", REPO / "asm" / "code2.s")
IMAGE_DEFAULT = REPO / "image.bin"
UNDEFINED_SYMS_DEFAULT = REPO / "undefined_syms_auto.txt"
SOURCE_OUTPUT_DEFAULT = REPO / "src" / "generated"
IMAGE_VRAM = 0x00100000
ADDRESS_COMMENT_RE = re.compile(
    r"/\*\s+(?:[0-9A-Fa-f]+\s+)?([0-9A-Fa-f]{8})(?:\s|:)"
)
LABEL_RE = re.compile(r"^\s*(?:glabel|alabel|dlabel)\s+\S+\s*$", re.MULTILINE)
GUARD_RE = re.compile(r"^\s*#if\s+defined\(P4_UNIT_([0-9A-Fa-f]{8})\)\s*$", re.MULTILINE)
CANDIDATE_MARKER_RE = re.compile(
    r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\b[^\n]*$",
    re.MULTILINE,
)
JTBL_SYMBOL_RE = re.compile(r"\bjtbl_[0-9A-Fa-f]{8}\b")
JTBL_ROW_RE = re.compile(
    r"^\s*(jtbl_[0-9A-Fa-f]{8})\s*=\s*(0x[0-9A-Fa-f]+)\s*;\s*$"
)
INDIRECT_JR_RE = re.compile(r"\bjr\s+\$(?!31\b|ra\b)[A-Za-z0-9]+\b")
LOCAL_LABEL_RE = re.compile(r"^\s*\.L([0-9A-Fa-f]{8})\s*:", re.MULTILINE)
BRANCH_TARGET_RE = re.compile(
    r"\b(?:b|beq|bne|beqz|bnez|bgez|bltz|bgtz|blez|bgezal|bltzal)\b[^\n]*?"
    r"((?:func_|\.L)[0-9A-Fa-f]{8})\b"
)
RETURN_JR_RE = re.compile(r"\bjr\s+\$(?:31|ra)\b")
RETAIL_MARKER_RE = re.compile(
    r"^//\s*FUN_([0-9A-Fa-f]{8})\s+RETAIL_ASM\s*$", re.MULTILINE
)
MWCC_WORD_RE = re.compile(
    r"^(\s*\.word\s+)0x([0-9A-Fa-f]{8})(\b.*)$", re.MULTILINE
)
FUNCTION_DEF_RE = re.compile(
    r"^(?!\s*(?:if|for|while|switch|return|do)\b)\s*[^\n{};]*"
    r"\bfunc_([0-9A-Fa-f]{8})\s*\([^;\n]*\)\s*\{",
    re.MULTILINE,
)
FUNCTION_DECL_RE = re.compile(
    r"\b(?P<name>func_[0-9A-Fa-f]{8})\s*\([^;\n]*\)"
)
SYMBOL_RE = re.compile(
    r"\b(?:func_[0-9A-Fa-f]{8}|D_[0-9A-Fa-f]+|jtbl_[0-9A-Fa-f]{8})\b"
)
POINTER_RETURN_SYMBOLS = {"D_008873F4"}

SAVED_REG_RE = re.compile(r"\bsaved_reg_[A-Za-z0-9_]+\b")
M2C_PLACEHOLDER_RE = re.compile(
    r"\b(?:unksp[0-9A-Fa-f]+|sp[0-9A-Fa-f]+|subroutine_arg[A-Za-z0-9_]*)\b"
    r"|\bs(?:[0-9A-Fa-f]+)\b"
)
POINTER_BASE_TYPE_RE = (
    r"(?:u8|s8|u16|s16|u32|s32|u64|s64|s128|u128|f32|f64|f128|"
    r"M2C_UNK(?:8|16|32|64)?|void)"
)
CONTEXT_TEXT = """typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;
typedef double f64;
typedef s32 intptr_t;
typedef u32 uintptr_t;
typedef u32 size_t;
"""



@dataclass(frozen=True)
class Fallback:
    address: int
    size: int
    owner: str


@dataclass(frozen=True)
class JumpTable:
    name: str
    address: int
    words: tuple[int, ...]


@dataclass(frozen=True)
class PreparedAssembly:
    text: str
    tables: tuple[tuple[str, tuple[int, ...]], ...]


@dataclass(frozen=True)
class M2cCandidate:
    body: str
    declarations: tuple[str, ...]


def find_m2c(explicit: Path | None) -> Path:
    candidates: list[Path] = []
    if explicit is not None:
        candidates.append(explicit)
    if os.environ.get("M2C"):
        candidates.append(Path(os.environ["M2C"]))
    candidates.append(M2C_DEFAULT)
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    raise SystemExit("m2c is not installed; run `make m2c-setup` or set M2C")


def load_fallbacks(path: Path = FUNCTION_MAP) -> dict[int, Fallback]:
    fallbacks: dict[int, Fallback] = {}
    prefix = "build/function_sources/"
    try:
        lines = path.read_text(encoding="utf-8").splitlines()
    except OSError as error:
        raise SystemExit(f"cannot read function map {path}: {error}") from error
    for line in lines:
        fields = line.split(maxsplit=3)
        if len(fields) != 4:
            raise SystemExit(f"malformed function map row: {line!r}")
        address_text, size_text, _status, owner = fields
        owner_normalized = owner.replace("\\", "/")
        if not owner_normalized.startswith(prefix):
            continue
        try:
            address = int(address_text, 16)
            size = int(size_text, 10)
        except ValueError as error:
            raise SystemExit(f"malformed function map row: {line!r}") from error
        if address in fallbacks:
            raise SystemExit(f"duplicate fallback address {address:08x}")
        fallbacks[address] = Fallback(address, size, owner_normalized)
    if not fallbacks:
        raise SystemExit("function map contains no fallback boundaries")
    return dict(sorted(fallbacks.items()))


def canonical_jump_table_name(name: str) -> str:
    match = re.fullmatch(r"jtbl_([0-9A-Fa-f]{8})", name)
    if match is None:
        raise ValueError(f"invalid jump-table symbol {name!r}")
    return f"jtbl_{match.group(1).upper()}"


def load_jump_table_symbols(path: Path = UNDEFINED_SYMS_DEFAULT) -> dict[str, int]:
    symbols: dict[str, int] = {}
    addresses: dict[int, str] = {}
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError as error:
        raise SystemExit(f"cannot read jump-table symbols {path}: {error}") from error
    for line in lines:
        match = JTBL_ROW_RE.match(line)
        if match is None:
            continue
        name = canonical_jump_table_name(match.group(1))
        address = int(match.group(2), 16)
        previous = symbols.get(name)
        if previous is not None and previous != address:
            raise SystemExit(f"conflicting jump-table address for {name}")
        other = addresses.get(address)
        if other is not None and other != name:
            raise SystemExit(f"duplicate jump-table address {address:08x}: {other} and {name}")
        symbols[name] = address
        addresses[address] = name
    if not symbols:
        raise SystemExit(f"jump-table symbol file contains no jtbl_ entries: {path}")
    return dict(sorted(symbols.items()))


def load_jump_tables(
    image_path: Path = IMAGE_DEFAULT,
    symbols: dict[str, int] | None = None,
    image_vram: int = IMAGE_VRAM,
) -> dict[str, JumpTable]:
    if symbols is None:
        symbols = load_jump_table_symbols()
    try:
        image = image_path.read_bytes()
    except OSError as error:
        raise SystemExit(f"cannot read image for jump tables {image_path}: {error}") from error
    ordered = sorted(symbols.items(), key=lambda item: item[1])
    tables: dict[str, JumpTable] = {}
    for index, (name, address) in enumerate(ordered):
        next_address = (
            ordered[index + 1][1]
            if index + 1 < len(ordered)
            else image_vram + len(image)
        )
        if address < image_vram or address >= image_vram + len(image):
            raise SystemExit(f"jump-table address is outside image: {name}={address:#x}")
        if address % 4 or next_address <= address or (next_address - address) % 4:
            raise SystemExit(f"invalid jump-table range for {name} at {address:#x}")
        offset = address - image_vram
        word_count = min((next_address - address) // 4, 1024)
        words = tuple(
            struct.unpack_from("<I", image, offset + word_offset)[0]
            for word_offset in range(0, word_count * 4, 4)
        )
        if 0 in words:
            words = words[:words.index(0)]
        tables[name] = JumpTable(name, address, words)
    return tables


def indirect_jump_table_names(block: str) -> tuple[str, ...]:
    names: list[str] = []
    pending: str | None = None
    for line in block.splitlines():
        references = JTBL_SYMBOL_RE.findall(line)
        if references:
            pending = canonical_jump_table_name(references[-1])
        if pending is not None and INDIRECT_JR_RE.search(line):
            if pending not in names:
                names.append(pending)
            pending = None
    return tuple(names)


def specialize_ambiguous_jump_table_setup(block: str) -> str:
    """Duplicate one jump-table setup beside each ambiguous indirect jump.

    m2c's jump-table analysis is local to a dispatch block. Some MWCC output
    initializes several table bases once in a function prologue, then reuses
    each base in a later indirect jump. The original setup is semantically
    correct, but m2c cannot associate a later ``jr`` with one of the bases.
    Move a copy of the setup beside each dispatch and remove the prologue copy
    from this analysis-only assembly input.
    """
    lines = block.splitlines()
    setup_lines: dict[str, list[tuple[int, str]]] = defaultdict(list)
    setup_registers: dict[str, set[str]] = defaultdict(set)
    for index, line in enumerate(lines):
        references = JTBL_SYMBOL_RE.findall(line)
        if not references or re.search(
            r"\b(?:lui|addiu|daddiu|ori)\s+\$(\d+)", line
        ) is None:
            continue
        register = re.search(
            r"\b(?:lui|addiu|daddiu|ori)\s+\$(\d+)", line
        )
        if register is None:
            continue
        for name in references:
            canonical = canonical_jump_table_name(name)
            setup_lines[canonical].append((index, line))
            setup_registers[canonical].add(register.group(1))
    if len(setup_registers) < 2:
        return block

    dispatches: list[tuple[int, int, str, str]] = []
    for index, line in enumerate(lines):
        jump = re.search(
            r"\bjr\s+\$(?!31\b|ra\b)([A-Za-z0-9]+)\b", line
        )
        if jump is None:
            continue
        target_register = jump.group(1)
        for add_index in range(max(0, index - 8), index):
            add = re.search(
                r"\b(?:addu|daddu)\s+\$(\d+),\s*\$(\d+),\s*\$(\d+)",
                lines[add_index],
            )
            if add is None or add.group(1) != target_register:
                continue
            if add.group(2) == target_register:
                base_register = add.group(3)
            elif add.group(3) == target_register:
                base_register = add.group(2)
            else:
                continue
            candidates = [
                name
                for name, registers in setup_registers.items()
                if registers == {base_register}
            ]
            if len(candidates) != 1:
                continue
            start = add_index
            for sll_index in range(add_index - 1, max(-1, add_index - 5), -1):
                if re.search(
                    rf"\b(?:sll|dsll)\s+\${re.escape(target_register)}\s*,",
                    lines[sll_index],
                ):
                    start = sll_index
                    break
            dispatches.append((start, index, candidates[0], base_register))
            break

    used = {name for _, _, name, _ in dispatches}
    if used != set(setup_lines) or len(used) < 2:
        return block
    first_dispatch = min(start for start, _, _, _ in dispatches)
    if any(
        index >= first_dispatch
        for entries in setup_lines.values()
        for index, _ in entries
    ):
        return block

    remove = {
        index for entries in setup_lines.values() for index, _ in entries
    }
    insertions: dict[int, list[str]] = defaultdict(list)
    for start, _, name, _ in dispatches:
        insertions[start].extend(line for _, line in setup_lines[name])
    output: list[str] = []
    for index, line in enumerate(lines):
        if index in remove:
            continue
        output.extend(insertions.get(index, ()))
        output.append(line)
    result = "\n".join(output)
    return result + ("\n" if block.endswith("\n") else "")


def prepare_assembly_block(
    block: str,
    tables: dict[str, JumpTable],
) -> tuple[PreparedAssembly, str | None]:
    block = specialize_ambiguous_jump_table_setup(block)
    names = indirect_jump_table_names(block)
    if not names:
        return PreparedAssembly(block, ()), None
    lines = block.splitlines()
    address_lines: dict[int, int] = {}
    for index, line in enumerate(lines):
        for match in ADDRESS_COMMENT_RE.finditer(line):
            address_lines.setdefault(int(match.group(1), 16), index)
    existing_labels = {
        int(match.group(1), 16) for match in LOCAL_LABEL_RE.finditer(block)
    }
    table_words: dict[str, tuple[int, ...]] = {}
    insertions: dict[int, list[str]] = defaultdict(list)
    for name in names:
        table = tables.get(name)
        if table is None:
            return PreparedAssembly(block, ()), f"jump table {name} is not present in image data"
        valid: list[int] = []
        for target in table.words:
            if target not in address_lines:
                break
            valid.append(target)
        if not valid:
            return PreparedAssembly(block, ()), (
                f"jump table {name} has no in-function targets"
            )
        table_words[name] = tuple(valid)
        for target in valid:
            if target in existing_labels:
                continue
            insertions[address_lines[target]].append(f"  .L{target:08X}:")
            existing_labels.add(target)
    output: list[str] = []
    for index, line in enumerate(lines):
        output.extend(insertions.get(index, ()))
        output.append(line)
    text = "\n".join(output)
    if block.endswith("\n"):
        text += "\n"
    return PreparedAssembly(text, tuple(table_words.items())), None


def prepare_assembly(
    blocks: dict[int, str],
    addresses: Iterable[int],
    tables: dict[str, JumpTable],
) -> tuple[dict[int, str], dict[str, tuple[int, ...]], dict[int, str]]:
    prepared: dict[int, str] = {}
    table_words: dict[str, tuple[int, ...]] = {}
    failures: dict[int, str] = {}
    owner_by_address: dict[int, tuple[int, str]] = {}
    for owner, block in blocks.items():
        for address in address_line_map(block):
            owner_by_address.setdefault(address, (owner, block))
    for address in addresses:
        contextual = prepare_control_flow_context(
            blocks[address], blocks, owner_by_address
        )
        result, error = prepare_assembly_block(contextual, tables)
        prepared[address] = result.text
        if error is not None:
            failures[address] = error
            continue
        for name, words in result.tables:
            if len(words) > len(table_words.get(name, ())):
                table_words[name] = words
    return prepared, table_words, failures

def load_assembly_blocks(paths: Iterable[Path] = ASM_PATHS) -> dict[int, str]:
    blocks: dict[int, str] = {}
    for path in paths:
        if not path.is_file():
            raise SystemExit(f"split assembly is missing: {path}")
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines(keepends=True)
        labels = [index for index, line in enumerate(lines) if LABEL_RE.match(line)]
        for position, start in enumerate(labels):
            end = labels[position + 1] if position + 1 < len(labels) else len(lines)
            block = "".join(lines[start:end])
            address_match = ADDRESS_COMMENT_RE.search(block)
            if address_match is None:
                continue
            address = int(address_match.group(1), 16)
            normalized = re.sub(
                r"^\s*(?:glabel|alabel|dlabel)\s+\S+\s*$",
                f"glabel func_{address:08x}",
                block,
                count=1,
                flags=re.MULTILINE,
            )
            previous = blocks.get(address)
            if previous is not None and previous != normalized:
                raise SystemExit(f"conflicting assembly blocks for {address:08x}")
            blocks[address] = normalized
    return blocks

def address_line_map(block: str) -> dict[int, int]:
    result: dict[int, int] = {}
    for index, line in enumerate(block.splitlines()):
        for match in ADDRESS_COMMENT_RE.finditer(line):
            result.setdefault(int(match.group(1), 16), index)
    return result


def context_segment(block: str, address: int) -> list[str]:
    lines = block.splitlines()
    addresses = address_line_map(block)
    start = addresses.get(address)
    if start is None:
        return []
    end = next(
        (
            index
            for index in range(start, len(lines))
            if re.match(r"^\s*endlabel\b", lines[index])
        ),
        len(lines),
    )
    return [f"  .L{address:08X}:"] + [
        line
        for line in lines[start:end]
        if not re.match(
            r"^\s*(?:glabel|alabel|dlabel|nonmatching)\b", line
        )
    ]


def rewrite_branch_target(lines: list[str], old: str, new: str) -> bool:
    for index, line in enumerate(lines):
        match = BRANCH_TARGET_RE.search(line)
        if match is None or match.group(1) != old:
            continue
        lines[index] = line[: match.start(1)] + new + line[match.end(1) :]
        return True
    return False


def add_missing_delay_slots(text: str) -> str:
    lines = text.splitlines()
    index = 0
    while index < len(lines):
        if not RETURN_JR_RE.search(lines[index]):
            index += 1
            continue
        cursor = index + 1
        while cursor < len(lines) and (
            not lines[cursor].strip()
            or re.match(r"^\s*\.L[0-9A-Fa-f]{8}\s*:", lines[cursor])
        ):
            cursor += 1
        if cursor >= len(lines) or re.match(
            r"^\s*(?:endlabel|nonmatching|glabel|alabel|dlabel)\b",
            lines[cursor],
        ):
            lines.insert(index + 1, "    nop")
            index += 1
        index += 1
    result = "\n".join(lines)
    return result + ("\n" if text.endswith("\n") else "")


def prepare_control_flow_context(
    block: str,
    blocks: dict[int, str],
    owner_by_address: dict[int, tuple[int, str]] | None = None,
) -> str:
    if owner_by_address is None:
        owner_by_address = {}
        for owner, candidate in blocks.items():
            for address in address_line_map(candidate):
                owner_by_address.setdefault(address, (owner, candidate))
    base_match = ADDRESS_COMMENT_RE.search(block)
    if base_match is None:
        return add_missing_delay_slots(block)
    base_address = int(base_match.group(1), 16)
    lines = block.splitlines()
    included: set[tuple[int, int]] = set()
    while True:
        combined = "\n".join(lines)
        local_addresses = {
            int(match.group(1), 16) for match in LOCAL_LABEL_RE.finditer(combined)
        }
        address_lines = address_line_map(combined)
        changed = False
        for match in BRANCH_TARGET_RE.finditer(combined):
            label = match.group(1)
            target = int(label[5:] if label.startswith("func_") else label[2:], 16)
            local_label = f".L{target:08X}"
            if target in local_addresses:
                continue
            owner = owner_by_address.get(target)
            if owner is not None and owner[0] == base_address:
                line_index = address_lines.get(target)
                if line_index is not None:
                    lines.insert(line_index, f"  {local_label}:")
                    if label.startswith("func_"):
                        rewrite_branch_target(lines, label, local_label)
                    changed = True
                    break
            if target == base_address:
                line_index = address_lines.get(target)
                if line_index is not None:
                    lines.insert(line_index, f"  {local_label}:")
                    rewrite_branch_target(lines, label, local_label)
                    changed = True
                    break
            if owner is None or (owner[0], target) in included:
                continue
            segment = context_segment(owner[1], target)
            if not segment:
                continue
            lines.extend(segment)
            included.add((owner[0], target))
            if label.startswith("func_"):
                rewrite_branch_target(lines, label, local_label)
            changed = True
            break
        if not changed:
            break
    combined = "\n".join(lines)
    return add_missing_delay_slots(
        combined + ("\n" if block.endswith("\n") else "")
    )
def prepare_retail_asm_candidate(body: str) -> str:
    """Encode retail words in the byte order MWCC emits for inline asm."""
    def swap_word(match: re.Match[str]) -> str:
        word = match.group(2)
        swapped = "".join(word[index:index + 2] for index in range(6, -1, -2))
        return f"{match.group(1)}0x{swapped}{match.group(3)}"

    return MWCC_WORD_RE.sub(swap_word, body)
def prepare_retail_asm_candidate_for_address(body: str, address: int) -> str:
    """Encode C850 from image bytes so code and embedded tables stay exact."""
    if address == 0x0070C850:
        image_path = REPO / "image.bin"
        word_matches = list(MWCC_WORD_RE.finditer(body))
        image_offset = address - IMAGE_VRAM
        image_size = len(word_matches) * 4
        if (
            image_path.is_file()
            and image_offset >= 0
            and image_offset + image_size <= image_path.stat().st_size
        ):
            image = image_path.read_bytes()
            pieces: list[str] = []
            cursor = 0
            for index, match in enumerate(word_matches):
                pieces.append(body[cursor:match.start()])
                data = image[
                    image_offset + index * 4:image_offset + (index + 1) * 4
                ]
                pieces.append(
                    f"{match.group(1)}0x{data[::-1].hex().upper()}{match.group(3)}"
                )
                cursor = match.end()
            pieces.append(body[cursor:])
            return "".join(pieces)
    return prepare_retail_asm_candidate(body)




def load_retail_bodies(directory: Path = FUNCTION_SOURCES) -> dict[int, str]:
    bodies: dict[int, str] = {}
    marker_paths = sorted(directory.glob("code*.c"))
    for path in marker_paths:
        text = path.read_text(encoding="utf-8", errors="replace")
        matches = list(RETAIL_MARKER_RE.finditer(text))
        for index, match in enumerate(matches):
            end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
            address = int(match.group(1), 16)
            body = text[match.start():end].strip()
            if address in bodies and bodies[address] != body:
                raise SystemExit(f"conflicting retail fallback bodies for {address:08x}")
            bodies[address] = body
    return bodies


def context_file(work_dir: Path) -> Path:
    work_dir.mkdir(parents=True, exist_ok=True)
    path = work_dir / "m2c_bulk_context.c"
    path.write_text(CONTEXT_TEXT, encoding="utf-8", newline="\n")
    return path


def matching_brace(text: str, opening: int) -> int:
    depth = 0
    quote: str | None = None
    escaped = False
    line_comment = False
    block_comment = False
    index = opening
    while index < len(text):
        char = text[index]
        next_char = text[index + 1] if index + 1 < len(text) else ""
        if line_comment:
            if char == "\n":
                line_comment = False
        elif block_comment:
            if char == "*" and next_char == "/":
                block_comment = False
                index += 1
        elif quote is not None:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                quote = None
        elif char == "/" and next_char == "/":
            line_comment = True
            index += 1
        elif char == "/" and next_char == "*":
            block_comment = True
            index += 1
        elif char in ('"', "'"):
            quote = char
        elif char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return index + 1
        index += 1
    raise ValueError("unbalanced m2c function braces")


def parse_m2c_output(text: str) -> dict[int, M2cCandidate]:
    cleaned_lines = [line for line in text.splitlines() if not line.startswith("Warning:")]
    cleaned = "\n".join(cleaned_lines).strip() + "\n"
    matches = list(FUNCTION_DEF_RE.finditer(cleaned))
    if not matches:
        return {}
    declarations = tuple(
        line.strip()
        for line in cleaned[: matches[0].start()].splitlines()
        if ";" in line and not line.strip().startswith(("/*", "//"))
    )
    candidates: dict[int, M2cCandidate] = {}
    for match in matches:
        opening = cleaned.find("{", match.start(), match.end())
        if opening < 0:
            continue
        end = matching_brace(cleaned, opening)
        address = int(match.group(1), 16)
        candidates[address] = M2cCandidate(
            cleaned[match.start():end].strip(), declarations
        )
    return candidates


def m2c_command(m2c: Path) -> list[str]:
    if m2c.suffix.lower() == ".py":
        return [sys.executable, str(m2c)]
    return [str(m2c)]


def run_batch(
    addresses: list[int],
    assembly: dict[int, str],
    jump_table_words: dict[str, tuple[int, ...]],
    context: Path,
    m2c: Path,
    timeout: float,
    work_dir: Path,
    sequence: int,
) -> tuple[dict[int, M2cCandidate], str | None]:
    descriptor, raw_path = tempfile.mkstemp(
        prefix=f".m2c_batch_{sequence:06d}_", suffix=".s", dir=work_dir
    )
    os.close(descriptor)
    path = Path(raw_path)
    try:
        table_names: list[str] = []
        for address in addresses:
            for name in indirect_jump_table_names(assembly[address]):
                if name in jump_table_words and name not in table_names:
                    table_names.append(name)
        table_lines: list[str] = []
        for name in table_names:
            table_lines.append(f"glabel {name}")
            table_lines.extend(f"    .word .L{target:08X}" for target in jump_table_words[name])
        source = (
            ".set noat\n.set noreorder\n.text\n"
            + "\n".join(assembly[address] for address in addresses)
        )
        if table_lines:
            source += "\n.rdata\n" + "\n".join(table_lines) + "\n"
        path.write_text(source, encoding="utf-8", newline="\n")
        command = m2c_command(m2c) + [
            "--target",
            "mipsee-mwcc-c",
            "--context",
            str(context),
            "--globals=used",
            "--valid-syntax",
        ]
        for address in addresses:
            command.extend(("-f", f"func_{address:08x}"))
        command.append(str(path))
        try:
            result = subprocess.run(
                command,
                cwd=REPO,
                stdin=subprocess.DEVNULL,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                check=False,
                timeout=timeout,
            )
        except subprocess.TimeoutExpired as error:
            return {}, f"timeout after {timeout:g}s: {error}"
        if result.returncode != 0:
            detail = (result.stderr or result.stdout).strip().replace("\n", " ")
            return {}, f"m2c exit {result.returncode}: {detail[:400]}"
        try:
            return parse_m2c_output(result.stdout), None
        except (ValueError, RuntimeError) as error:
            return {}, f"cannot parse m2c output: {error}"
    finally:
        path.unlink(missing_ok=True)


def process_batch(
    addresses: list[int],
    assembly: dict[int, str],
    jump_table_words: dict[str, tuple[int, ...]],
    context: Path,
    m2c: Path,
    timeout: float,
    work_dir: Path,
    sequence: list[int],
    generated: dict[int, M2cCandidate],
    failures: dict[int, str],
) -> None:
    if not addresses:
        return
    sequence[0] += 1
    candidates, error = run_batch(
        addresses, assembly, jump_table_words, context, m2c, timeout, work_dir, sequence[0]
    )
    if error is None:
        expected = set(addresses)
        for address, candidate in candidates.items():
            if address in expected:
                generated[address] = candidate
        missing = [address for address in addresses if address not in candidates]
        if missing:
            if len(missing) == 1:
                failures[missing[0]] = "m2c produced no function definition"
            else:
                process_batch(
                    missing,
                    assembly,
                    jump_table_words,
                    context,
                    m2c,
                    timeout,
                    work_dir,
                    sequence,
                    generated,
                    failures,
                )
        return
    if len(addresses) == 1:
        failures[addresses[0]] = error
        return
    midpoint = max(1, len(addresses) // 2)
    process_batch(
        addresses[:midpoint],
        assembly,
        jump_table_words,
        context,
        m2c,
        timeout,
        work_dir,
        sequence,
        generated,
        failures,
    )
    process_batch(
        addresses[midpoint:],
        assembly,
        jump_table_words,
        context,
        m2c,
        timeout,
        work_dir,
        sequence,
        generated,
        failures,
    )



def function_prototype(candidate: M2cCandidate) -> str:
    signature = candidate.body.split("{", 1)[0].strip()
    if signature.startswith("static "):
        signature = signature[len("static "):]
    return f"extern {signature};"
def relax_function_declaration(declaration: str) -> str:
    """Keep external return types but allow calls with recovered arities."""
    return FUNCTION_DECL_RE.sub(r"\g<name>()", declaration, count=1)

def normalize_bitwise_pointer_casts(body: str) -> str:
    """Route float/integer bitwise casts through an integer before pointers."""
    replacements: list[tuple[int, int, str]] = []
    for match in re.finditer(r"\bM2C_BITWISE\s*\(", body):
        opening = body.find("(", match.start())
        closing = matching_parenthesis(body, opening)
        inner = body[opening + 1 : closing]
        depth = 0
        comma = None
        for index, char in enumerate(inner):
            if char == "(":
                depth += 1
            elif char == ")":
                depth -= 1
            elif char == "," and depth == 0:
                comma = index
                break
        if comma is None:
            continue
        type_text = inner[:comma].strip()
        expression = inner[comma + 1 :].strip()
        pointer_target = "*" in type_text
        float_pointer_source = (
            type_text in {"f32", "f64"}
            and re.search(r"\b(?:sp|saved_reg_gp|saved_reg_s1)\b|&\s*(?:D_|func_)", expression)
        )
        if not pointer_target and not float_pointer_source:
            continue
        integer_type = "s64" if type_text == "f64" else "s32"
        replacements.append(
            (
                match.start(),
                closing + 1,
                f"(({type_text})({integer_type})({expression}))",
            )
        )
    normalized = body
    for start, end, replacement in reversed(replacements):
        normalized = normalized[:start] + replacement + normalized[end:]
    return normalized


def normalize_scalar_indexing(body: str) -> str:
    """Treat stack-slot array syntax as byte-addressed storage."""
    pointer_decl_re = re.compile(
        rf"^\s*{POINTER_BASE_TYPE_RE}\s*\*+\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;",
        re.MULTILINE,
    )
    pointer_names = {match.group("name") for match in pointer_decl_re.finditer(body)}
    indexing_re = re.compile(
        r"(?P<address>&)?(?P<name>sp[0-9A-Fa-f]+)"
        r"\[(?P<index>[^\]\n]+)\]"
    )
    replacements: list[tuple[int, int, str]] = []
    for match in indexing_re.finditer(body):
        if match.group("name") in pointer_names:
            continue
        if match.group("address"):
            replacement = f"(u8 *)&{match.group('name')}"
        else:
            replacement = (
                f"((u8 *)&{match.group('name')})[{match.group('index')}]"
            )
        replacements.append((match.start(), match.end(), replacement))
    normalized = body
    for start, end, replacement in reversed(replacements):
        normalized = normalized[:start] + replacement + normalized[end:]
    return normalized
def normalize_pointer_arithmetic(body: str) -> str:
    """Make address arithmetic explicit for MWCC's strict pointer rules."""
    replacements: list[tuple[int, int, str]] = []
    for match in re.finditer(r"&(?P<symbol>D_[0-9A-Fa-f]+)", body):
        line_start = body.rfind("\n", 0, match.start()) + 1
        line_end = body.find("\n", match.end())
        if line_end < 0:
            line_end = len(body)
        line = body[line_start:line_end]
        before = line[: match.start() - line_start]
        if re.search(r"\*\s*\(\s*$", before):
            continue
        after = line[match.end() - line_start :]
        if not (
            re.search(r"[+\-*/|<>]\s*$", before)
            or re.match(r"\s*[+\-*/|<>]", after)
        ):
            continue
        prefix = body[max(line_start, match.start() - 8):match.start()]
        if re.search(r"\(\s*s(?:32|64)\s*\)\s*$", prefix):
            continue
        replacements.append(
            (match.start(), match.end(), f"(s32)&{match.group('symbol')}")
        )
    normalized = body
    for start, end, replacement in reversed(replacements):
        normalized = normalized[:start] + replacement + normalized[end:]
    return normalized


def normalize_address_of_casts(body: str) -> str:
    """Remove m2c's invalid address-of-a-cast pointer expressions."""
    cast_re = re.compile(
        rf"&\s*(\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)\s*\([^;\n]*\))"
    )
    return cast_re.sub(r"\1", body)


def normalize_malformed_body_declarations(body: str) -> str:
    """Repair truncated and corrupted m2c callback declarations."""
    corrupted_re = re.compile(
        rf"^(?P<indent>\s*)(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"\(M2C_UNK\)\((?P<name>[A-Za-z_]\w*)\s*"
        rf"\((?P<parameters>[^\n]*)\)\)(?P<tail>\s*(?:;|\{{).*)$",
        re.MULTILINE,
    )
    def repair_corrupted(match: re.Match[str]) -> str:
        name = match.group("name")
        pointer_name = (
            f"*{name}({match.group('parameters')})"
            if name.startswith("func_")
            else f"(*{name})({match.group('parameters')})"
        )
        return (
            f"{match.group('indent')}{match.group('type')} {pointer_name}"
            f"{match.group('tail')}"
        )
    body = corrupted_re.sub(repair_corrupted, body)
    double_corrupted_re = re.compile(
        rf"^(?P<indent>\s*)(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"\(\(M2C_UNK\)\((?P<name>[A-Za-z_]\w*)\)\)\s*"
        rf"\((?P<parameters>[^\n]*)\)(?P<tail>\s*(?:;|\{{).*)$",
        re.MULTILINE,
    )
    body = double_corrupted_re.sub(
        lambda match: (
            f"{match.group('indent')}{match.group('type')} "
            f"{' *' if match.group('name').startswith('func_') else '(*'}"
            f"{match.group('name')}"
            f"{'(' + match.group('parameters') + ')' if match.group('name').startswith('func_') else ')(' + match.group('parameters') + ')'}"
            f"{match.group('tail')}"
        ),
        body,
    )
    pointer_double_corrupted_re = re.compile(
        rf"^(?P<indent>\s*)(?P<type>{POINTER_BASE_TYPE_RE})\s+\*\s*"
        rf"\(\(M2C_UNK\)\((?P<name>[A-Za-z_]\w*)\)\)\s*"
        rf"\((?P<parameters>[^\n]*)\)(?P<tail>\s*(?:;|\{{).*)$",
        re.MULTILINE,
    )
    body = pointer_double_corrupted_re.sub(
        lambda match: (
            f"{match.group('indent')}{match.group('type')} "
            f"(*{match.group('name')})({match.group('parameters')})"
            f"{match.group('tail')}"
        ),
        body,
    )
    declaration_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*)?)\s+"
        rf"\(\*?(?P<name>func_[0-9A-Fa-f]{{8}})\s*\([^\n]*;"
        rf"(?P<tail>\s*(?:/\*.*\*/)?\s*)$",
        re.MULTILINE,
    )
    body = declaration_re.sub(
        lambda match: f"extern {match.group('type').strip()} "
        f"{match.group('name')}();",
        body,
    )
    function_pointer_re = re.compile(
        rf"^\s*{POINTER_BASE_TYPE_RE}\s+\(\*(?P<name>[A-Za-z_]\w*)\)"
        rf"\([^;\n]*\)\s*;\s*$",
        re.MULTILINE,
    )
    function_pointer_names = {
        match.group("name") for match in function_pointer_re.finditer(body)
    }
    if function_pointer_names:
        scalar_re = re.compile(
            rf"(?m)^\s*{POINTER_BASE_TYPE_RE}\s+"
            rf"(?P<name>{'|'.join(map(re.escape, sorted(function_pointer_names)))})"
            rf"\s*;\s*(?:/\*.*\*/)?\n?"
        )
        body = scalar_re.sub("", body)
    return body


def normalize_bare_function_values(body: str) -> str:
    """Turn known m2c function-value mistakes into direct calls."""
    return re.sub(r"\bnanf\b(?!\s*\()", "nanf()", body)
def normalize_unsupported_vector_types(body: str) -> str:
    """Map m2c's non-C 24-bit placeholder type to the unknown scalar type."""
    body = re.sub(r"(?m)^\s*M2C_UNK\s+s24\s*;\s*\n?", "", body)
    return re.sub(r"\bs24\b", "M2C_UNK", body)


def normalize_empty_switch_labels(body: str) -> str:
    """Drop m2c's orphaned and duplicate labels emitted for empty switch paths."""
    body = re.sub(
        r"(?m)^(?P<indent>[ \t]*)default\s*:"
        r"[ \t]*(?:/\*.*\*/[ \t]*)?\n"
        r"(?P=indent)case\b[^:]*:[^\n]*\n",
        r"\g<indent>default:\n",
        body,
    )
    return re.sub(
        r"(?m)^(?P<indent>[ \t]*)(?:case\b[^:]*|default)\s*:"
        r"[ \t]*(?:/\*.*\*/[ \t]*)?\n(?P=indent)}",
        r"\g<indent>}",
        body,
    )


def matching_parenthesis(text: str, opening: int) -> int:
    depth = 0
    for index in range(opening, len(text)):
        if text[index] == "(":
            depth += 1
        elif text[index] == ")":
            depth -= 1
            if depth == 0:
                return index
    raise ValueError("unbalanced candidate parentheses")


def normalize_indirect_calls(body: str) -> str:
    """Cast m2c's raw data-table dereferences before calling them."""
    replacements: list[tuple[int, int, str]] = []
    for match in re.finditer(r"\*\s*(?=\((?:&D_[0-9A-Fa-f]+|sp)\b)", body):
        opening = body.find("(", match.start())
        closing = matching_parenthesis(body, opening)
        next_index = closing + 1
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if next_index < len(body) and body[next_index] == "(":
            target = body[opening : closing + 1]
            replacements.append(
                (
                    match.start(),
                    closing + 1,
                    f"((M2C_UNK (*)()) *{target})",
                )
            )
    normalized = body
    for start, end, replacement in reversed(replacements):
        normalized = normalized[:start] + replacement + normalized[end:]
    return normalized
def normalize_dereference_operands(body: str) -> str:
    """Cast ambiguous m2c dereference operands to byte-addressed pointers."""
    replacements: list[tuple[int, int, str]] = []
    for match in re.finditer(r"\*\s*(?=\()", body):
        prefix = body[: match.start()].rstrip()
        if prefix and prefix[-1] not in "([{=,:;!?&|+-*/%<>":
            cast_context = re.search(
                rf"\(\s*{POINTER_BASE_TYPE_RE}(?:\s*\*)?\s*\)\s*$",
                prefix,
            )
            token = re.search(r"[A-Za-z_]\w*$", prefix)
            if (
                not cast_context
                and (token is None or token.group() not in {"return", "sizeof"})
            ):
                continue
        opening = body.find("(", match.start())
        closing = matching_parenthesis(body, opening)
        next_index = closing + 1
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if next_index < len(body) and body[next_index] == "(":
            continue
        expression = body[opening + 1 : closing]
        if re.match(
            rf"\s*(?:\(\s*)?{POINTER_BASE_TYPE_RE}\s*\*+\s*\)?",
            expression,
        ):
            continue
        previous = match.start() - 1
        while previous >= 0 and body[previous].isspace():
            previous -= 1
        pointer_type = "u8 **" if previous >= 0 and body[previous] == "*" else "u8 *"
        replacements.append(
            (
                match.start(),
                closing + 1,
                f"*(({pointer_type}){body[opening : closing + 1]})",
            )
        )
    normalized = body
    for start, end, replacement in reversed(replacements):
        normalized = normalized[:start] + replacement + normalized[end:]
    return normalized


def normalize_scalar_dereferences(body: str) -> str:
    """Turn invalid dereferences of m2c scalar placeholders into byte lvalues."""
    scalar_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    scalar_names = {match.group("name") for match in scalar_decl_re.finditer(body)}
    signature = body.split("{", 1)[0]
    parameter_re = re.compile(
        rf"(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)(?=\s*(?:,|\)))"
    )
    scalar_names.update(
        match.group("name")
        for match in parameter_re.finditer(signature)
        if "*" not in match.group("type")
    )
    body = re.sub(
        r"(?P<lhs>(?:\d+(?:\.\d+)?(?:f)?|[A-Za-z_]\w*|\)|\]))"
        r"\s+\(M2C_UNK\)\((?P<name>[A-Za-z_]\w*)\)",
        lambda match: (
            match.group("lhs") + " * (M2C_UNK)(" + match.group("name") + ")"
            if match.group("lhs")
            not in {"return", "if", "while", "switch", "sizeof"}
            else match.group(0)
        ),
        body,
    )
    address_re = re.compile(
        r"\*\s*\(\s*\(\s*M2C_UNK\s*\*\s*\)\s*&(?P<name>[A-Za-z_]\w*)\s*\)"
    )
    def scalar_replacement(match: re.Match[str], name: str) -> str:
        line_start = body.rfind("\n", 0, match.start()) + 1
        line_end = body.find("\n", match.end())
        if line_end < 0:
            line_end = len(body)
        before = body[:match.start()].rstrip()
        after = body[match.end():line_end]
        if before and (before[-1].isalnum() or before[-1] in "_)]"):
            cast_prefix = re.search(
                rf"\(\s*{POINTER_BASE_TYPE_RE}\s*\)\s*$",
                before,
            )
            if re.search(r"\b(?:return|sizeof)\s*$", before) or cast_prefix:
                return f"* (M2C_UNK)({name})"
            return match.group(0)
        if re.match(r"\s*(?:\+=|-=|\*=|/=|%=|=(?!=))", after):
            return f"*((M2C_UNK *)&{name})"
        return f"(M2C_UNK)({name})"
    body = address_re.sub(
        lambda match: scalar_replacement(match, match.group("name")),
        body,
    )
    for name in sorted(scalar_names, key=len, reverse=True):
        scalar_re = re.compile(rf"(?<!\*)\*\s*{re.escape(name)}\b")
        body = scalar_re.sub(
            lambda match: scalar_replacement(match, name),
            body,
        )
    error_deref_re = re.compile(
        r"\*\s*(?P<call>M2C_ERROR\s*\([^;\n]*\))"
    )

    def repair_error_deref(match: re.Match[str]) -> str:
        before = body[: match.start()].rstrip()
        if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
            cast_context = re.search(
                rf"\(\s*{POINTER_BASE_TYPE_RE}\s*\)\s*$",
                before,
            )
            if (
                cast_context is None
                and re.search(r"\breturn\s*$", before) is None
            ):
                return match.group(0)
        return f"(M2C_UNK)({match.group('call')})"

    body = error_deref_re.sub(repair_error_deref, body)
    return body




def normalize_pointer_assignments(
    body: str,
    external_pointer_types: dict[str, str] | None = None,
) -> str:
    """Add explicit casts where m2c inferred an integer address type."""
    pointer_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    pointer_types: dict[str, str] = dict(external_pointer_types or {})
    for match in pointer_decl_re.finditer(body):
        pointer_types[match.group("name")] = match.group("type").strip()
    signature = body.split("{", 1)[0]
    parameter_re = re.compile(
        rf"(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)(?=\s*(?:,|\)))"
    )
    for match in parameter_re.finditer(signature):
        pointer_types[match.group("name")] = match.group("type").strip()
    return_type = re.match(
        rf"\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"[A-Za-z_]\w*\s*\(",
        signature,
    )
    return_type_text = return_type.group("type").strip() if return_type else None

    def pointer_lvalue_type(lvalue: str) -> str | None:
        lvalue = lvalue.strip()
        if lvalue in pointer_types:
            return pointer_types[lvalue]
        match = re.match(r"^\*\s*(?P<name>[A-Za-z_]\w*)$", lvalue)
        if match and match.group("name") in pointer_types:
            type_text = pointer_types[match.group("name")]
            if type_text.count("*") >= 2:
                return type_text.rsplit("*", 1)[0].strip()
            return None
        match = re.match(
            rf"^M2C_FIELD\([^;\n]*,\s*"
            rf"(?P<type>{POINTER_BASE_TYPE_RE}\s*\(\*+\)\s*\([^;\n]*\))\s*,",
            lvalue,
        )
        if match:
            return match.group("type").strip()
        match = re.match(
            rf"^M2C_FIELD\([^;\n]*,\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*,",
            lvalue,
        )
        if match and match.group("type").count("*") >= 2:
            return match.group("type").rsplit("*", 1)[0].strip()
        return None

    assignment_re = re.compile(
        r"^(?P<indent>\s*)(?P<lvalue>.+?)\s*"
        r"(?P<operator>\+=|-=|\*=|/=|%=|=(?!=))\s*"
        r"(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    return_re = re.compile(
        r"^(?P<indent>\s*)return\s+(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    lines: list[str] = []
    for line in body.splitlines():
        assignment = assignment_re.match(line)
        if assignment and assignment.group("operator") == "=":
            type_text = pointer_lvalue_type(assignment.group("lvalue"))
            rhs = assignment.group("rhs").strip()
            if type_text and rhs != "NULL" and not re.match(
                r"^\(*\s*\([A-Za-z_]\w*(?:\s*\*)+\)", rhs
            ):
                rhs = f"({type_text})({rhs})"
                line = (
                    f"{assignment.group('indent')}{assignment.group('lvalue').strip()} = "
                    f"{rhs};{assignment.group('tail')}"
                )
        returned = return_re.match(line)
        if returned and return_type_text:
            rhs = returned.group("rhs").strip()
            if rhs != "NULL" and not re.match(
                r"^\(*\s*\([A-Za-z_]\w*(?:\s*\*)+\)", rhs
            ):
                line = (
                    f"{returned.group('indent')}return "
                    f"({return_type_text})({rhs});{returned.group('tail')}"
                )
        lines.append(line)
    return "\n".join(lines)
def normalize_function_pointer_assignments(body: str) -> str:
    """Cast opaque integer returns assigned to function-pointer locals."""
    declaration_re = re.compile(
        rf"^\s*(?P<return_type>{POINTER_BASE_TYPE_RE})\s*"
        rf"\((?P<stars>\*+)\s*(?P<name>[A-Za-z_]\w*)\)\s*"
        rf"(?P<parameters>\([^;\n]*\))\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    function_pointer_types = {
        match.group("name"): (
            f"{match.group('return_type')} "
            f"({match.group('stars')}){match.group('parameters')}"
        )
        for match in declaration_re.finditer(body)
    }
    assignment_re = re.compile(
        r"^(?P<indent>\s*)(?P<name>[A-Za-z_]\w*)\s*=\s*"
        r"(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    lines: list[str] = []
    for line in body.splitlines():
        assignment = assignment_re.match(line)
        if assignment and assignment.group("name") in function_pointer_types:
            rhs = assignment.group("rhs").strip()
            if rhs != "NULL" and not re.match(
                r"^\(*\s*[A-Za-z_]\w*\s*\(\s*\*+", rhs
            ):
                rhs = f"({function_pointer_types[assignment.group('name')]})({rhs})"
                line = (
                    f"{assignment.group('indent')}{assignment.group('name')} = "
                    f"{rhs};{assignment.group('tail')}"
                )
        lines.append(line)
    return "\n".join(lines)


def normalize_function_pointer_fields(body: str) -> str:
    """Cast callback addresses to the function-pointer field's lvalue type."""
    assignment_re = re.compile(
        r"^(?P<indent>\s*)(?P<lvalue>M2C_FIELD\([^;\n]*,\s*"
        r"(?P<field_type>[A-Za-z_]\w*\s*\(\*+\)\s*\([^;\n]*\))\s*,[^;\n]*\))"
        r"\s*=\s*(?P<rhs>[^;\n]+);(?P<tail>.*)$",
        re.MULTILINE,
    )
    lines: list[str] = []
    for line in body.splitlines():
        match = assignment_re.match(line)
        if match is None:
            lines.append(line)
            continue
        field_type = match.group("field_type")
        lvalue_type = field_type.replace("(**", "(*", 1)
        rhs = match.group("rhs").strip()
        if not re.match(rf"^\(*\s*{re.escape(lvalue_type)}\s*\)", rhs):
            rhs = f"({lvalue_type})({rhs})"
        line = (
            f"{match.group('indent')}{match.group('lvalue')} = "
            f"{rhs};{match.group('tail')}"
        )
        lines.append(line)
    return "\n".join(lines)


def normalize_scalar_assignments(
    body: str,
    external_pointer_types: dict[str, str] | None = None,
    external_scalar_types: dict[str, str] | None = None,
) -> str:
    """Cast pointer-shaped m2c expressions into scalar lvalues."""
    scalar_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    scalar_types = dict(external_scalar_types or {})
    scalar_types.update(
        {
            match.group("name"): match.group("type").strip()
            for match in scalar_decl_re.finditer(body)
        }
    )
    pointer_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    pointer_types = dict(external_pointer_types or {})
    pointer_types.update(
        {
            match.group("name"): match.group("type").strip()
            for match in pointer_decl_re.finditer(body)
        }
    )
    signature = body.split("{", 1)[0]
    parameter_re = re.compile(
        rf"(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*+)?)\s*"
        rf"(?P<name>[A-Za-z_]\w*)(?=\s*(?:,|\)))"
    )
    for match in parameter_re.finditer(signature):
        type_text = match.group("type").strip()
        if "*" in type_text:
            pointer_types[match.group("name")] = type_text
        else:
            scalar_types[match.group("name")] = type_text
    pointer_names = set(pointer_types) | {"sp", "saved_reg_gp", "saved_reg_s1"}

    def pointerish(expression: str) -> bool:
        if re.search(r"&\s*(?:D_|func_|jtbl_)", expression):
            return True
        if re.search(
            rf"\b(?:{'|'.join(map(re.escape, sorted(POINTER_RETURN_SYMBOLS)))})\s*\(",
            expression,
        ):
            return True
        if re.search(r"\b(?:sp|saved_reg_gp|saved_reg_s1)\b", expression):
            return True
        if any(
            re.search(rf"\b{re.escape(name)}\b", expression)
            for name in pointer_names
        ):
            return True
        return bool(
            re.search(
                rf"M2C_FIELD\([^;\n]*,\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\*",
                expression,
            )
        )

    def scalar_cast(expression: str, type_text: str) -> str:
        if type_text in {"f32", "f64", "f128", "s64", "u64", "s128", "u128"}:
            return f"({type_text})(s32)({expression})"
        return f"({type_text})({expression})"

    def scalar_lvalue_type(lvalue: str) -> str | None:
        lvalue = lvalue.strip()
        if lvalue in scalar_types:
            return scalar_types[lvalue]
        match = re.match(
            rf"^\*\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*\*\s*\)",
            lvalue,
        )
        if match:
            return match.group("type")
        match = re.match(r"^\*\s*(?P<name>[A-Za-z_]\w*)$", lvalue)
        if match and match.group("name") in pointer_types:
            type_text = pointer_types[match.group("name")]
            if type_text.count("*") == 1:
                return type_text.split("*", 1)[0].strip()
            return None
        match = re.match(
            rf"^M2C_FIELD\([^;\n]*,\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*,",
            lvalue,
        )
        if match:
            return match.group("type")
        if re.fullmatch(r"D_[0-9A-Fa-f]+", lvalue) and lvalue not in pointer_types:
            return scalar_types.get(lvalue, "s32")
        return None

    assignment_re = re.compile(
        r"^(?P<indent>\s*)(?P<lvalue>.+?)\s*"
        r"(?P<operator>\+=|-=|\*=|/=|%=|=(?!=))\s*"
        r"(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    return_re = re.compile(
        r"^(?P<indent>\s*)return\s+(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    return_type = re.match(
        rf"\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?!\(\*)[A-Za-z_]\w*\s*\(",
        signature,
    )
    return_type_text = return_type.group("type") if return_type else None
    lines: list[str] = []
    for line in body.splitlines():
        assignment = assignment_re.match(line)
        if assignment:
            type_text = scalar_lvalue_type(assignment.group("lvalue"))
            rhs = assignment.group("rhs").strip()
            if (
                type_text
                and rhs != "NULL"
                and pointerish(rhs)
                and not re.match(
                    rf"^\(*\s*{POINTER_BASE_TYPE_RE}\s*\)\s*",
                    rhs,
                )
            ):
                rhs = scalar_cast(rhs, type_text)
                line = (
                    f"{assignment.group('indent')}{assignment.group('lvalue').strip()} "
                    f"{assignment.group('operator')} {rhs};{assignment.group('tail')}"
                )
        returned = return_re.match(line)
        if returned and return_type_text:
            rhs = returned.group("rhs").strip()
            if (
                rhs != "NULL"
                and pointerish(rhs)
                and not re.match(
                    rf"^\(*\s*{POINTER_BASE_TYPE_RE}\s*\)\s*",
                    rhs,
                )
            ):
                rhs = scalar_cast(rhs, return_type_text)
                line = (
                    f"{returned.group('indent')}return {rhs};"
                    f"{returned.group('tail')}"
                )
        lines.append(line)
    return "\n".join(lines)






def normalize_pointer_comparisons(
    body: str,
    external_pointer_types: dict[str, str] | None = None,
    external_scalar_types: dict[str, str] | None = None,
) -> str:
    """Make m2c's scalar/pointer comparisons explicit for MWCC."""
    pointer_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    pointer_types = dict(external_pointer_types or {})
    pointer_types.update(
        {
            match.group("name"): match.group("type").strip()
            for match in pointer_decl_re.finditer(body)
        }
    )
    function_pointer_decl_re = re.compile(
        rf"^\s*{POINTER_BASE_TYPE_RE}\s*\(\*+\s*"
        rf"(?P<name>[A-Za-z_]\w*)\)\s*\([^;\n]*\)\s*;",
        re.MULTILINE,
    )
    pointer_types.update(
        {match.group("name"): "u8 *" for match in function_pointer_decl_re.finditer(body)}
    )
    scalar_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    scalar_types = dict(external_scalar_types or {})
    scalar_types.update(
        {
            match.group("name"): match.group("type").strip()
            for match in scalar_decl_re.finditer(body)
        }
    )
    signature = body.split("{", 1)[0]
    parameter_re = re.compile(
        rf"(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*+)?)\s*"
        rf"(?P<name>[A-Za-z_]\w*)(?=\s*(?:,|\)))"
    )
    for match in parameter_re.finditer(signature):
        type_text = match.group("type").strip()
        if "*" in type_text:
            pointer_types[match.group("name")] = type_text
        else:
            scalar_types[match.group("name")] = type_text

    def strip_outer_parentheses(term: str) -> str:
        term = term.strip()
        while term.startswith("("):
            try:
                closing = matching_parenthesis(term, 0)
            except ValueError:
                break
            if closing != len(term) - 1:
                break
            term = term[1:-1].strip()
        return term

    def term_type(term: str) -> str | None:
        term = strip_outer_parentheses(term)
        if term in pointer_types:
            return pointer_types[term]
        if term in scalar_types:
            return scalar_types[term]
        if term.startswith("&"):
            return "u8 *"
        if term == "NULL":
            return "u8 *"
        if re.fullmatch(r"(?:0x[0-9A-Fa-f]+|\d+)", term):
            return "s32"
        match = re.fullmatch(r"\*\s*([A-Za-z_]\w*)", term)
        if match and match.group(1) in pointer_types:
            type_text = pointer_types[match.group(1)]
            if type_text.count("*") >= 2:
                return type_text.rsplit("*", 1)[0].strip()
            return type_text.split("*", 1)[0].strip()
        match = re.match(
            rf"^M2C_FIELD\([^;\n]*,\s*"
            rf"(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*+)?)\s*,",
            term,
        )
        if match:
            type_text = match.group("type").strip()
            if type_text.count("*") >= 2:
                return type_text.rsplit("*", 1)[0].strip()
            if "*" in type_text:
                return type_text.split("*", 1)[0].strip()
            return type_text
        return None

    def pointer_type(term: str) -> str | None:
        type_text = term_type(term)
        return type_text if type_text and "*" in type_text else None

    def cast_unknown_null_expression(expression: str) -> str:
        if pointer_type(expression) is not None:
            return expression
        if re.match(r"^\(*\s*[A-Za-z_]\w*\s*\*+", expression):
            return expression
        return f"(u8 *)({expression})"

    null_left_re = re.compile(
        r"(?P<expression>M2C_FIELD\([^;\n]*\)|"
        r"func_[0-9A-Fa-f]{8}\([^;\n]*\)|"
        r"\*?[A-Za-z_]\w*)\s*(?P<operator>==|!=)\s*NULL"
    )
    null_right_re = re.compile(
        r"NULL\s*(?P<operator>==|!=)\s*"
        r"(?P<expression>M2C_FIELD\([^;\n]*\)|"
        r"func_[0-9A-Fa-f]{8}\([^;\n]*\)|"
        r"\*?[A-Za-z_]\w*)"
    )
    body = null_left_re.sub(
        lambda match: (
            f"{cast_unknown_null_expression(match.group('expression'))} "
            f"{match.group('operator')} NULL"
        ),
        body,
    )
    body = null_right_re.sub(
        lambda match: (
            f"NULL {match.group('operator')} "
            f"{cast_unknown_null_expression(match.group('expression'))}"
        ),
        body,
    )

    right_term_re = re.compile(
        rf"\s*(?P<term>func_[0-9A-Fa-f]{{8}}\([^;\n]*\)|"
        rf"\*?[A-Za-z_]\w*|NULL|0x[0-9A-Fa-f]+|\d+)"
    )
    field_replacements: list[tuple[int, int, str]] = []
    for field_match in re.finditer(r"\bM2C_FIELD\s*\(", body):
        opening = body.find("(", field_match.start())
        closing = matching_parenthesis(body, opening)
        operator_match = re.match(r"\s*(==|!=)", body[closing + 1 :])
        if operator_match is None:
            continue
        operator_start = closing + 1 + operator_match.start(1)
        operator_end = closing + 1 + operator_match.end(1)
        right_match = right_term_re.match(body[operator_end:])
        if right_match is None:
            continue
        left = body[field_match.start() : closing + 1]
        right = right_match.group("term")
        left_type = pointer_type(left)
        right_type = pointer_type(right)
        right_start = operator_end + right_match.start("term")
        right_end = operator_end + right_match.end("term")
        if left_type and right_type is None and term_type(right) is not None:
            field_replacements.append(
                (right_start, right_end, f"({left_type})({right})")
            )
        elif right_type and left_type is None and term_type(left) is not None:
            field_replacements.append(
                (
                    field_match.start(),
                    closing + 1,
                    f"({right_type})({left})",
                )
            )
    for start, end, replacement in reversed(field_replacements):
        body = body[:start] + replacement + body[end:]

    term_pattern = (
        rf"(?:func_[0-9A-Fa-f]{{8}}\([^;\n]*\)|"
        rf"&[A-Za-z_]\w*|\*?[A-Za-z_]\w*|"
        rf"0x[0-9A-Fa-f]+|\d+)"
    )
    comparison_re = re.compile(
        rf"(?P<left>{term_pattern})\s*(?P<operator>==|!=)\s*"
        rf"(?P<right>{term_pattern})"
    )

    def rewrite_comparison(match: re.Match[str]) -> str:
        left = match.group("left")
        right = match.group("right")
        left_type = pointer_type(left)
        right_type = pointer_type(right)
        if left_type and right_type is None and term_type(right) is not None:
            right = f"({left_type})({right})"
        elif right_type and left_type is None and term_type(left) is not None:
            left = f"({right_type})({left})"
        return f"{left} {match.group('operator')} {right}"

    return comparison_re.sub(rewrite_comparison, body)


def normalize_compile_error_repair(
    body: str,
    address: int | None = None,
    detail: str = "",
) -> str:
    """Apply permissive repairs only to units already diagnosed by MWCC."""
    body = normalize_malformed_body_declarations(body)
    pointer_repair_addresses = {
        0x0029AD40,
        0x003E1740,
        0x003F4730,
        0x00403930,
        0x00407FF0,
        0x0040DF50,
        0x00413E50,
        0x0041A5A8,
        0x00422DA0,
        0x0043DC60,
        0x004C4BA8,
        0x004D47C8,
        0x004F34E8,
        0x004FCD18,
        0x005033B0,
        0x00525E90,
    }
    function_result_types: dict[str, str] = {}
    def repair_function_result_header(line: str) -> str:
        header = re.match(
            rf"^(?P<indent>\s*)(?P<return_type>{POINTER_BASE_TYPE_RE}"
            rf"(?:\s*\*)?)\s+\(\*(?P<name>func_[0-9A-Fa-f]{{8}})\(",
            line,
        )
        if header is None or not line.rstrip().endswith("{"):
            return line
        argument_opening = line.find("(", header.start("name"))
        try:
            argument_closing = matching_parenthesis(line, argument_opening)
        except ValueError:
            return line
        return_opening = line.find("(", argument_closing + 1)
        if return_opening < 0:
            return line
        try:
            return_closing = matching_parenthesis(line, return_opening)
        except ValueError:
            return line
        if line[return_closing + 1 :].strip() != "{":
            return line
        function_result_types[header.group("name")] = (
            header.group("return_type").strip()
        )
        return (
            f"{header.group('indent')}{header.group('return_type').strip()} *"
            f"{header.group('name')}({line[argument_opening + 1 : argument_closing]}) {{"
        )

    body = "\n".join(
        repair_function_result_header(line) for line in body.splitlines()
    )
    if function_result_types:
        result_return_re = re.compile(
            r"^(?P<indent>\s*)return\s+(?P<rhs>[^;]+);"
            r"(?P<tail>\s*(?://.*)?)$"
        )
        result_lines: list[str] = []
        for result_line in body.splitlines():
            returned = result_return_re.match(result_line)
            if returned is None or returned.group("rhs").strip() == "NULL":
                result_lines.append(result_line)
                continue
            target = next(iter(function_result_types.values()))
            if not target.rstrip().endswith("*"):
                target = f"{target} *"
            result_lines.append(
                f"{returned.group('indent')}return "
                f"({target})(s32)({returned.group('rhs').strip()});"
                f"{returned.group('tail')}"
            )
        body = "\n".join(result_lines)
    # A few m2c output tokens lose the ``te`` prefix of temporary names.
    body = re.sub(r"\bmp_", "temp_", body)
    def drop_duplicate_switch_labels(text: str) -> str:
        spans: list[tuple[int, int]] = []
        for switch in re.finditer(r"\bswitch\s*\(", text):
            opening = text.find("(", switch.start())
            try:
                closing = matching_parenthesis(text, opening)
            except ValueError:
                continue
            brace = text.find("{", closing)
            if brace < 0:
                continue
            depth = 0
            end = None
            for index in range(brace, len(text)):
                if text[index] == "{":
                    depth += 1
                elif text[index] == "}":
                    depth -= 1
                    if depth == 0:
                        end = index + 1
                        break
            if end is not None:
                spans.append((brace, end))
        label_re = re.compile(
            r"^(?P<indent>\s*)(?P<label>case\s+[^:]+:|default:)"
            r"(?P<tail>[^\n]*)$",
            re.MULTILINE,
        )
        for start, end in sorted(spans, reverse=True):
            segment = text[start:end]
            seen: set[str] = set()
            replacements: list[tuple[int, int, str]] = []
            for label in label_re.finditer(segment):
                key = re.sub(r"\s+", " ", label.group("label").strip())
                if key not in seen:
                    seen.add(key)
                    continue
                tail = label.group("tail").strip()
                replacements.append(
                    (
                        label.start(),
                        label.end(),
                        f"{label.group('indent')}{tail}" if tail else "",
                    )
                )
            for left, right, replacement in reversed(replacements):
                segment = segment[:left] + replacement + segment[right:]
            text = text[:start] + segment + text[end:]
        return text

    body = drop_duplicate_switch_labels(body)
    def remove_orphan_switch_labels(text: str) -> str:
        switch_spans: list[tuple[int, int]] = []
        for switch in re.finditer(r"\bswitch\s*\(", text):
            opening = text.find("(", switch.start())
            try:
                closing = matching_parenthesis(text, opening)
            except ValueError:
                continue
            brace = text.find("{", closing)
            if brace < 0:
                continue
            depth = 0
            end = None
            for index in range(brace, len(text)):
                if text[index] == "{":
                    depth += 1
                elif text[index] == "}":
                    depth -= 1
                    if depth == 0:
                        end = index + 1
                        break
            if end is not None:
                switch_spans.append((brace, end))
        label_re = re.compile(
            r"^(?P<indent>\s*)(?P<label>case\s+[^:]+:|default:)"
            r"(?P<tail>[^\n]*)$",
            re.MULTILINE,
        )
        replacements: list[tuple[int, int, str]] = []
        for label in label_re.finditer(text):
            if any(start <= label.start() < end for start, end in switch_spans):
                continue
            tail = label.group("tail").strip()
            comment = f"/* orphan {label.group('label').strip()} */"
            replacements.append(
                (
                    label.start(),
                    label.end(),
                    f"{label.group('indent')}{comment}"
                    f"{(' ' + tail) if tail else ''}",
                )
            )
        for start, end, replacement in reversed(replacements):
            text = text[:start] + replacement + text[end:]
        return text

    body = remove_orphan_switch_labels(body)
    function_pointer_variable_re = re.compile(
        rf"^(?P<indent>\s*)(?P<return_type>{POINTER_BASE_TYPE_RE}"
        rf"(?:\s*\*)?)\s*\(\*(?:\*)?"
        rf"(?P<name>[A-Za-z_]\w*)\)\s*"
        rf"\((?P<parameters>[^()\n]*)\)\s*;"
        rf"(?P<tail>\s*(?:/\*.*\*/)?\s*)$",
        re.MULTILINE,
    )
    body = function_pointer_variable_re.sub(
        lambda match: (
            f"{match.group('indent')}{match.group('return_type').strip()} "
            f"(*{match.group('name')})({match.group('parameters')});"
            f"{match.group('tail')}"
        ),
        body,
    )
    function_pointer_cast_re = re.compile(
        rf"\b{POINTER_BASE_TYPE_RE}\s+\*\s*\(\*+\)\s*"
        rf"\([^()\n]*\)"
    )
    body = function_pointer_cast_re.sub("M2C_UNK *", body)
    function_type_re = re.compile(
        rf"\b{POINTER_BASE_TYPE_RE}\s+\((?P<stars>\*+)\)\s*"
        rf"\([^()\n]*\)"
    )
    body = function_type_re.sub(
        lambda match: f"M2C_UNK ({match.group('stars')})()",
        body,
    )
    body = re.sub(
        rf"&\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\)\s*"
        rf"\(\s*(?P<name>[A-Za-z_]\w*)\s*\)\s*"
        rf"\[(?P<index>[^\]\n]+)\]",
        r"&((s32 *)(\g<name>))[\g<index>]",
        body,
    )
    body = re.sub(
        rf"&\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\)\s*"
        rf"\(\s*(?P<name>[A-Za-z_]\w*)\s*\)",
        r"&\g<name>",
        body,
    )
    body = re.sub(r"--(?P<number>\d+(?:\.\d+)?f?)\b", r"-\g<number>", body)
    body = re.sub(
        r"(M2C_FIELD\([^;\n]*,\s*)M2C_UNK\s+\(\*\*\)\(\)"
        r"(\s*,[^\n=;]*\)\s*\()",
        r"\1M2C_UNK (*)()\2",
        body,
    )
    body = re.sub(
        r"\(M2C_UNK\)\((?P<call>func_[0-9A-Fa-f]{8}\([^;\n]*\))\)"
        r"(?P<tail>\s*=)",
        r"*((u8 *)(s32)(\g<call>))\g<tail>",
        body,
    )
    body = re.sub(
        r"\bsecond\s+half\s+of\s+f64\b",
        "M2C_ERROR(/* unknown instruction: second half of f64 */)",
        body,
    )
    callback_re = re.compile(
        rf"^(?P<indent>\s*)(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*)?)\s*"
        rf"\(*\s*M2C_UNK\s*\)*\s*\(\s*"
        rf"(?P<name>func_[0-9A-Fa-f]{{8}})\s*\([^;\n]*\)\s*\)\s*;"
        rf"(?P<tail>\s*(?:/\*.*\*/)?\s*)$",
        re.MULTILINE,
    )
    body = callback_re.sub(
        lambda match: (
            f"{match.group('indent')}extern {match.group('type').strip()} "
            f"{match.group('name')}();{match.group('tail')}"
        ),
        body,
    )

    def repair_multiplication(match: re.Match[str]) -> str:
        lhs = match.group("lhs")
        if lhs in {"return", "if", "while", "switch", "sizeof"}:
            return match.group(0)
        return f"{lhs} * (M2C_UNK)("

    body = re.sub(
        r"(?P<lhs>(?:\d+(?:\.\d+)?(?:f)?|[A-Za-z_]\w*|\)|\]))"
        r"\s+\(M2C_UNK\)\(",
        repair_multiplication,
        body,
    )

    scalar_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    scalar_types = {
        match.group("name"): match.group("type").strip()
        for match in scalar_decl_re.finditer(body)
    }
    pointer_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    pointer_types = {
        match.group("name"): match.group("type").strip()
        for match in pointer_decl_re.finditer(body)
    }
    function_pointer_decl_re = re.compile(
        rf"^\s*(?P<return_type>{POINTER_BASE_TYPE_RE}"
        rf"(?:\s*\*)?)\s*\(\*(?P<name>[A-Za-z_]\w*)\)\s*"
        rf"\((?P<parameters>[^()\n]*)\)\s*;",
        re.MULTILINE,
    )
    for match in function_pointer_decl_re.finditer(body):
        pointer_types[match.group("name")] = (
            f"{match.group('return_type').strip()} "
            f"(*)({match.group('parameters')})"
        )
    signature = body.split("{", 1)[0]
    parameter_re = re.compile(
        rf"(?P<type>{POINTER_BASE_TYPE_RE}(?:\s*\*+)?)\s*"
        rf"(?P<name>[A-Za-z_]\w*)(?=\s*(?:,|\)))"
    )
    for match in parameter_re.finditer(signature):
        type_text = match.group("type").strip()
        if "*" in type_text:
            pointer_types[match.group("name")] = type_text
        else:
            scalar_types[match.group("name")] = type_text

    function_parameter_re = re.compile(
        rf"(?P<return_type>{POINTER_BASE_TYPE_RE}(?:\s*\*)?)\s*"
        rf"\((?P<stars>\*+)(?P<name>[A-Za-z_]\w*)\)\s*"
        rf"\((?P<parameters>[^()\n]*)\)"
    )
    for match in function_parameter_re.finditer(signature):
        pointer_types[match.group("name")] = (
            f"{match.group('return_type').strip()} "
            f"({'*' * max(1, len(match.group('stars')) - 1)})"
            f"({match.group('parameters')})"
        )

    pointer_names = set(pointer_types) | {"sp", "saved_reg_gp", "saved_reg_s1"}

    def pointerish(expression: str) -> bool:
        if re.match(r"\s*M2C_FIELD\s*\(", expression):
            return bool(
                re.search(
                    rf"M2C_FIELD\([^;\n]*,\s*"
                    rf"{POINTER_BASE_TYPE_RE}\s*\*\s*\*",
                    expression,
                )
            )
        return bool(
            re.search(
                r"&\s*(?:D_|func_|jtbl_)|"
                r"\b(?:D_|jtbl_)[0-9A-Fa-f]+\s*\(|"
                r"\bfunc_[0-9A-Fa-f]{8}\s*(?:\(|\b)|"
                r"M2C_FIELD\([^;\n]*,\s*"
                rf"{POINTER_BASE_TYPE_RE}\s*\*\s*\*",
                expression,
            )
            or any(
                re.search(rf"\b{re.escape(name)}\b", expression)
                for name in pointer_names
            )
        )
    bitwise_float_re = re.compile(
        r"M2C_BITWISE\(\s*(?P<type>f32|f64)\s*,\s*"
        r"(?P<expression>[A-Za-z_]\w*|&\s*[A-Za-z_]\w*)\s*\)"
    )
    body = bitwise_float_re.sub(
        lambda match: (
            f"M2C_BITWISE({match.group('type')}, "
            f"(s32)({match.group('expression')}))"
            if pointerish(match.group("expression"))
            else match.group(0)
        ),
        body,
    )
    dereference_casts: list[tuple[int, int, str]] = []
    for dereference in re.finditer(r"\*\s*\(", body):
        opening = body.find("(", dereference.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        inner = body[opening + 1 : closing]
        if not re.match(
            rf"\s*\(?\s*{POINTER_BASE_TYPE_RE}\s*\*+", inner
        ):
            continue
        next_index = closing + 1
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if body[next_index : next_index + 1] in {"=", "+", "-"}:
            continue
        prefix = body[:dereference.start()].rstrip()
        if prefix and prefix[-1] in {"*", "/"}:
            # This is a value operand, not an lvalue dereference.
            pass
        elif prefix and prefix[-1] in {"+", "-", "&", "|", "^", "<", ">"}:
            pass
        elif prefix and (prefix[-1].isalnum() or prefix[-1] in "_)]"):
            continue
        else:
            continue
        dereference_casts.append(
            (
                dereference.start(),
                closing + 1,
                f"(s32)({body[dereference.start() : closing + 1]})",
            )
        )
    for start, end, replacement in reversed(dereference_casts):
        body = body[:start] + replacement + body[end:]
    for name in sorted(scalar_types, key=len, reverse=True):
        body = re.sub(
            rf"&\s*{re.escape(name)}\s*"
            rf"\[(?P<index>[^\]\n]+)\]",
            rf"&((s32 *)&{name})[\g<index>]",
            body,
        )

    def scalar_cast(type_text: str, expression: str) -> str:
        if type_text in {"f32", "f64", "f128"}:
            return f"({type_text})(s32)({expression})"
        return f"({type_text})({expression})"

    assignment_re = re.compile(
        r"^(?P<indent>\s*)(?P<lvalue>.+?)\s*"
        r"(?P<operator>\+=|-=|\*=|/=|%=|=(?!=))\s*"
        r"(?P<rhs>[^;]+);(?P<tail>\s*(?://.*)?)$"
    )
    for line_number, line in enumerate(body.splitlines()):
        match = assignment_re.match(line)
        if match is None:
            continue
        lvalue = match.group("lvalue").strip()
        rhs = match.group("rhs").strip()
        if (
            lvalue in pointer_types
            and "(*)" in pointer_types[lvalue]
            and match.group("operator") in {"+=", "-=", "*=", "/="}
        ):
            operator = match.group("operator")[0]
            pointer_type = pointer_types[lvalue]
            lines = body.splitlines()
            lines[line_number] = (
                f"{match.group('indent')}{lvalue} = "
                f"({pointer_type})((s32)({lvalue}) {operator} ({rhs}));"
                f"{match.group('tail')}"
            )
            body = "\n".join(lines)
            continue
        target_type = scalar_types.get(lvalue)
        if target_type is None:
            dereference = re.match(
                rf"^\*\s*\(*\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})"
                rf"\s*(?P<stars>\*+)\s*\)",
                lvalue,
            )
            if dereference:
                base_type = dereference.group("type")
                stars = dereference.group("stars")
                target_type = (
                    f"{base_type} {'*' * (len(stars) - 1)}".strip()
                    if len(stars) > 1
                    else base_type
                )
            else:
                function_field = re.match(
                    rf"^M2C_FIELD\([^;\n]*,\s*"
                    rf"(?P<return_type>{POINTER_BASE_TYPE_RE})\s*"
                    rf"\((?P<stars>\*+)\)\s*\([^;\n]*\)\s*,",
                    lvalue,
                )
                if function_field:
                    stars = function_field.group("stars")
                    target_type = (
                        f"{function_field.group('return_type')} "
                        f"({'*' * max(1, len(stars) - 1)})()"
                    )
                else:
                    field = re.match(
                        rf"^M2C_FIELD\([^;\n]*,\s*"
                        rf"(?P<type>{POINTER_BASE_TYPE_RE})\s*"
                        rf"(?P<stars>\*+)\s*,",
                        lvalue,
                    )
                    if field:
                        base_type = field.group("type")
                        stars = field.group("stars")
                        target_type = (
                            f"{base_type} {'*' * (len(stars) - 1)}".strip()
                            if len(stars) > 1
                            else base_type
                        )
                    else:
                        dereference = re.fullmatch(
                            r"\*\s*(?P<name>[A-Za-z_]\w*)",
                            lvalue,
                        )
                        if (
                            dereference
                            and dereference.group("name") in pointer_types
                        ):
                            pointer_type = pointer_types[dereference.group("name")]
                            if pointer_type.count("*") == 1:
                                target_type = pointer_type.split("*", 1)[0].strip()
        rhs_is_pointer = pointerish(rhs) or re.match(
            rf"^\(*\s*{POINTER_BASE_TYPE_RE}\s*\*+\s*\)",
            rhs,
        )
        if target_type and match.group("operator") == "=":
            if rhs == "NULL":
                rhs = "0" if "*" not in target_type else "NULL"
            elif "*" in target_type:
                if "(*)" in target_type:
                    symbol = re.search(r"\bfunc_[0-9A-Fa-f]{8}\b", rhs)
                    if symbol is not None:
                        rhs = f"({target_type})({symbol.group(0)})"
                        if rhs != match.group("rhs").strip():
                            lines = body.splitlines()
                            lines[line_number] = (
                                f"{match.group('indent')}{lvalue} "
                                f"{match.group('operator')} {rhs};"
                                f"{match.group('tail')}"
                            )
                            body = "\n".join(lines)
                        continue
                if not re.match(
                    rf"^\(*\s*{re.escape(target_type)}\s*\)",
                    rhs,
                ):
                    rhs = f"({target_type})({rhs})"
            elif rhs_is_pointer:
                rhs = scalar_cast(target_type, rhs)
        elif lvalue in pointer_types and match.group("operator") == "=":
            if rhs != "NULL" and not re.match(
                r"^\(*\s*[^()]+\s*\*\s*\)",
                rhs,
            ):
                rhs = (
                    f"({pointer_types[lvalue]})(s32)({rhs})"
                    if re.search(r"\b(?:f32|f64|float)\b|\d+\.\d", rhs)
                    else f"({pointer_types[lvalue]})({rhs})"
                )
        if rhs != match.group("rhs").strip():
            lines = body.splitlines()
            lines[line_number] = (
                f"{match.group('indent')}{lvalue} {match.group('operator')} "
                f"{rhs};{match.group('tail')}"
            )
            body = "\n".join(lines)
    switch_replacements: list[tuple[int, int, str]] = []
    for switch in re.finditer(r"\bswitch\s*\(", body):
        opening = body.find("(", switch.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        expression = body[opening + 1 : closing].strip()
        if (
            pointerish(expression)
            or re.search(
                rf"\(\s*{POINTER_BASE_TYPE_RE}\s*\*+",
                expression,
            )
        ) and not re.match(r"^\s*\(\s*s32\s*\)", expression):
            switch_replacements.append(
                (opening + 1, closing, f"(s32)({expression})")
            )
    for start, end, replacement in reversed(switch_replacements):
        body = body[:start] + replacement + body[end:]

    arithmetic_ops = set("+-*/&|^<>")
    arithmetic_replacements: list[tuple[int, int, str]] = []
    for line_start, line in enumerate(body.splitlines(keepends=True)):
        content = line.rstrip("\r\n")
        offset = sum(len(part) for part in body.splitlines(keepends=True)[:line_start])
        for name in sorted(pointer_names, key=len, reverse=True):
            for occurrence in re.finditer(
                rf"\b{re.escape(name)}\b",
                content,
            ):
                before = content[: occurrence.start()].rstrip()
                after = content[occurrence.end() :].lstrip()
                if re.match(
                    rf"{re.escape(name)}\s*(?:\+=|-=|\*=|/=|%=)",
                    content[occurrence.start() :],
                ):
                    continue
                previous = before[-1:] or ""
                following = after[:2]
                if previous == "*":
                    before_star = before[:-1].rstrip()
                    if not before_star or before_star[-1] in (
                        "([{=,:;!?&|+-*/%<>"
                    ):
                        continue
                if previous == "&":
                    before_ampersand = before[:-1].rstrip()
                    if not before_ampersand or before_ampersand[-1] in (
                        "([{=,:;!?&|+-*/%<>"
                    ):
                        continue
                if (
                    previous not in arithmetic_ops
                    and following[:1] not in arithmetic_ops
                    and following not in {"<<", ">>"}
                ):
                    continue
                if previous == "*" and following[:1] not in arithmetic_ops:
                    continue
                if re.search(
                    rf"\(\s*(?:s32|u32|s64|u64)\s*\)\s*\(\s*$",
                    before,
                ):
                    continue
                arithmetic_replacements.append(
                    (
                        offset + occurrence.start(),
                        offset + occurrence.end(),
                        f"(s32)({name})",
                    )
                )
    for start, end, replacement in sorted(
        arithmetic_replacements,
        key=lambda item: item[0],
        reverse=True,
    ):
        body = body[:start] + replacement + body[end:]
    double_pointer_deref_re = re.compile(
        rf"\*\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\*{{2,}}\s*\)\s*"
        rf"(?:0x[0-9A-Fa-f]+|\d+)"
    )
    double_pointer_replacements: list[tuple[int, int, str]] = []
    for dereference in double_pointer_deref_re.finditer(body):
        tail = body[dereference.end() :].lstrip()
        if tail.startswith("="):
            continue
        if tail.startswith(("&", "|", "^", "+", "-", "*", "/", "<", ">")):
            double_pointer_replacements.append(
                (
                    dereference.start(),
                    dereference.end(),
                    f"(s32)({dereference.group(0)})",
                )
            )
    for start, end, replacement in reversed(double_pointer_replacements):
        body = body[:start] + replacement + body[end:]
    invalid_target_replacements: list[tuple[int, int, str]] = []
    for dereference in re.finditer(r"\*\s*\(", body):
        prefix = body[:dereference.start()].rstrip()
        if prefix and (prefix[-1].isalnum() or prefix[-1] in "_)]"):
            continue
        opening = body.find("(", dereference.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        next_index = closing + 1
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if next_index < len(body) and body[next_index] == "(":
            continue
        inner = body[opening + 1 : closing].strip()
        if not re.search(r"[+\-*/&|<>]|M2C_ERROR", inner):
            continue
        if re.match(
            rf"^\(*\s*{POINTER_BASE_TYPE_RE}\s*\*+",
            inner,
        ):
            continue
        invalid_target_replacements.append(
            (
                dereference.start(),
                closing + 1,
                f"*((u8 *)(s32)({inner}))",
            )
        )
    for start, end, replacement in reversed(invalid_target_replacements):
        body = body[:start] + replacement + body[end:]

    for name in sorted(scalar_types, key=len, reverse=True):
        body = re.sub(
            rf"\(\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*\*\s*\)\s*"
            rf"\(\s*{re.escape(name)}\s*\)",
            lambda match: (
                f"({match.group('type')} *)(s32)({name})"
            ),
            body,
        )
        body = re.sub(
            rf"\(\s*(?P<type>f32|f64)\s*\)\s*"
            rf"\(\s*{re.escape(name)}\s*\)",
            lambda match: (
                f"({match.group('type')})(s32)({name})"
            ),
            body,
        )

    float_cast_replacements: list[tuple[int, int, str]] = []
    for cast in re.finditer(r"\(\s*(?P<type>f32|f64)\s*\)", body):
        next_index = cast.end()
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if next_index >= len(body):
            continue
        if body[next_index] == "(":
            try:
                close = matching_parenthesis(body, next_index)
            except ValueError:
                continue
            expression = body[next_index + 1 : close].strip()
            if re.match(r"^\(\s*s(?:32|64)\s*\)", expression):
                continue
            if not pointerish(expression) and "*" not in expression and "&" not in expression:
                continue
            float_cast_replacements.append(
                (
                    cast.start(),
                    close + 1,
                    f"({cast.group('type')})(s32)({expression})",
                )
            )
        else:
            token = re.match(r"(?:&\s*)?[A-Za-z_]\w*", body[next_index:])
            if token is None:
                continue
            expression = token.group(0)
            if not pointerish(expression):
                continue
            float_cast_replacements.append(
                (
                    cast.start(),
                    next_index + token.end(),
                    f"({cast.group('type')})(s32)({expression})",
                )
            )
    for start, end, replacement in reversed(float_cast_replacements):
        body = body[:start] + replacement + body[end:]

    replacements: list[tuple[int, int, str]] = []
    for match in re.finditer(r"\*M2C_FIELD\s*\(", body):
        opening = body.find("(", match.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        inner = body[opening + 1 : closing]
        type_match = re.search(
            rf",\s*(?P<base>{POINTER_BASE_TYPE_RE})\s*"
            rf"(?P<stars>\*+)\s*,\s*[^,]*$",
            inner,
        )
        if type_match is None or type_match.group("stars") != "**":
            continue
        base = type_match.group("base")
        tail_start = closing + 1
        tail = re.match(
            rf"\s*(?P<operator>==|!=)\s*\(\s*{re.escape(base)}"
            rf"\s*\*\s*\)\s*\(",
            body[tail_start:],
        )
        if tail is None:
            continue
        rhs_open = tail_start + tail.end() - 1
        try:
            rhs_close = matching_parenthesis(body, rhs_open)
        except ValueError:
            continue
        field = body[match.start() : closing + 1]
        rhs = body[rhs_open + 1 : rhs_close]
        replacements.append(
            (
                match.start(),
                rhs_close + 1,
                f"({base})({field}) {tail.group('operator')} "
                f"({base})({rhs})",
            )
        )
    for start, end, replacement in reversed(replacements):
        body = body[:start] + replacement + body[end:]

    body = re.sub(
        rf"(?P<left>\*\s*\*\s*[A-Za-z_]\w*)\s*"
        rf"(?P<operator>==|!=)\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})"
        rf"\s*\*\s*\)\s*\((?P<rhs>[^()\n]+)\)",
        lambda match: (
            f"({match.group('type')})({match.group('left')}) "
            f"{match.group('operator')} "
            f"({match.group('type')})({match.group('rhs')})"
        ),
        body,
    )
    body = re.sub(
        r"(?<![\w)])M2C_ERROR\((?P<comment>[^)]*)\)(?=\s*=)",
        r"*((u8 *)(s32)(M2C_ERROR(\g<comment>)))",
        body,
    )
    error_pointer_deref_re = re.compile(
        r"\*\s*M2C_ERROR\((?P<comment>[^)]*)\)"
    )

    def repair_error_pointer_deref(match: re.Match[str]) -> str:
        before = body[: match.start()].rstrip()
        if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
            if re.search(r"\breturn\s*$", before) is None:
                return match.group(0)
        return f"*((u8 *)(s32)(M2C_ERROR({match.group('comment')})))"

    body = error_pointer_deref_re.sub(repair_error_pointer_deref, body)
    body = re.sub(
        r"\*\s*\(\s*M2C_UNK\s*\)\s*\("
        r"(?P<name>M2C_ERROR\s*\([^)]*\)|[A-Za-z_]\w*)\)"
        r"(?!\s*\()",
        r"*((u8 *)(s32)(\g<name>))",
        body,
    )
    body = re.sub(
        r"\(M2C_UNK\s*\(\*\)\(\)\)\s*-1\s*\(",
        "((M2C_UNK (*)())(-1))(",
        body,
    )
    body = re.sub(
        r"\(M2C_UNK\)\((?P<name>(?:sp|temp|var|arg)[A-Za-z0-9_]*)\)"
        r"\s*\(",
        r"((M2C_UNK (*)())(\g<name>))(",
        body,
    )
    indirect_call_replacements: list[tuple[int, int, str]] = []
    for dereference in re.finditer(r"\*\s*\(", body):
        prefix = body[:dereference.start()].rstrip()
        if prefix and (prefix[-1].isalnum() or prefix[-1] in "_)]"):
            continue
        line_start = body.rfind("\n", 0, dereference.start()) + 1
        line_end = body.find("\n", dereference.end())
        if line_end < 0:
            line_end = len(body)
        line = body[line_start:line_end]
        stripped_line = line.strip()
        if (
            "=" not in line
            and re.match(
                rf"(?:extern\s+)?(?:{POINTER_BASE_TYPE_RE}\s*)"
                rf"(?:\*|\(\*|func_|void\b|M2C_UNK\b)",
                stripped_line,
            )
        ):
            continue
        opening = body.find("(", dereference.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        next_index = closing + 1
        while next_index < len(body) and body[next_index].isspace():
            next_index += 1
        if next_index >= len(body) or body[next_index] != "(":
            continue
        target = body[dereference.start() : closing + 1]
        if "M2C_UNK (*)()" in target:
            continue
        indirect_call_replacements.append(
            (
                dereference.start(),
                closing + 1,
                f"((M2C_UNK (*)())({target}))",
            )
        )
    for start, end, replacement in reversed(indirect_call_replacements):
        body = body[:start] + replacement + body[end:]

    comparison_re = re.compile(
        r"==|!=|<=|>=|(?<![<>=!])<(?!=|<)|(?<![<>=!])>(?!=|>)"
    )

    def repair_comparison_line(line: str) -> str:
        matches = list(comparison_re.finditer(line))
        if not matches:
            return line
        depths: list[int] = []
        depth = 0
        for char in line:
            depths.append(depth)
            if char == "(":
                depth += 1
            elif char == ")":
                depth = max(0, depth - 1)
        edits: list[tuple[int, int, str]] = []
        for operator in reversed(matches):
            operator_depth = depths[operator.start()]
            left_start = operator.start() - 1
            while left_start >= 0:
                if depths[left_start] == operator_depth and (
                    line[left_start] in ",?:"
                    or line.startswith("&&", left_start)
                    or line.startswith("||", left_start)
                ):
                    left_start += 1
                    break
                if (
                    line[left_start] == "("
                    and depths[left_start] < operator_depth
                ):
                    left_start += 1
                    break
                left_start -= 1
            right_end = operator.end()
            while right_end < len(line):
                if depths[right_end] == operator_depth and (
                    line[right_end] in ",?:"
                    or line.startswith("&&", right_end)
                    or line.startswith("||", right_end)
                ):
                    break
                if (
                    line[right_end] == ")"
                    and depths[right_end] <= operator_depth
                ):
                    break
                right_end += 1
            left = line[left_start : operator.start()].strip()
            right = line[operator.end() : right_end].strip()
            if not left or not right:
                continue
            if not pointerish(left) and not pointerish(right):
                continue
            left_prefix = f"(s32)({left})"
            right_prefix = f"(s32)({right})"
            edits.append(
                (
                    left_start,
                    right_end,
                    f"{left_prefix} {operator.group()} {right_prefix}",
                )
            )
        for start, end, replacement in sorted(edits, reverse=True):
            line = line[:start] + replacement + line[end:]
        return line

    body = "\n".join(repair_comparison_line(line) for line in body.splitlines())
    body = re.sub(
        rf"&\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\)\s*"
        rf"\(\s*(?P<name>[A-Za-z_]\w*)\s*\)",
        r"&\g<name>",
        body,
    )
    for name, pointer_type in pointer_types.items():
        if pointer_type.count("*") == 1:
            body = re.sub(
                rf"\*\*\s*{re.escape(name)}\b"
                rf"(?=\s*(?:=|\+=|-=|\*=|/=))",
                f"*{name}",
                body,
            )
    body = re.sub(
        r"\*\(\(u8 \*\)\(s32\)\)\s*&(?P<symbol>D_[0-9A-Fa-f]+)",
        r"\g<symbol>",
        body,
    )
    body = re.sub(r"&\.L[0-9A-Fa-f]+", "(u8 *)0", body)
    body = re.sub(r"\(s32\)\(0\)\(s32\)\(2\)", "(s32)(0)", body)
    body = re.sub(r"\(s32\)\(0\)\*,", "(s32)(0),", body)
    body = re.sub(
        r"\)\)\)(?:0x)?[0-9A-Fa-f]{6}\)\)",
        "))))",
        body,
    )
    body = re.sub(
        r"&(?P<symbol>func_[0-9A-Fa-f]{8})(?=\s*[+\-])",
        r"(s32)&\g<symbol>",
        body,
    )
    body = re.sub(
        r"\b(?P<symbol>func_[0-9A-Fa-f]{8})(?=\s*[+\-])",
        r"(s32)(\g<symbol>)",
        body,
    )
    body = re.sub(
        r"\*\s*\(\s*M2C_UNK\s*\)\s*\(\s*"
        r"(?P<error>M2C_ERROR\s*\([^)]*\))\s*"
        r"(?P<operator>>=|<=|==|!=|>|<)\s*(?P<rhs>[^)\n]+)\)",
        r"((s32)(\g<error>) \g<operator> \g<rhs>)",
        body,
    )
    for name in sorted(scalar_types, key=len, reverse=True):
        body = re.sub(
            rf"\*\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*\)\s*"
            rf"\(\s*{re.escape(name)}\s*\)",
            lambda match: (
                f"*(({match.group('type')} *)(s32)({name}))"
            ),
            body,
        )
    if (
        "pointer/array required" in detail
        or (address is not None and address in pointer_repair_addresses)
    ):
        pointer_required_lines: list[str] = []
        dereference_re = re.compile(
            rf"\*\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*\)\s*\("
        )
        for raw_line in body.splitlines():
            line = raw_line
            edits: list[tuple[int, int, str]] = []
            for match in dereference_re.finditer(line):
                previous = match.start() - 1
                while previous >= 0 and line[previous] in " \t":
                    previous -= 1
                if (
                    previous >= 0
                    and (line[previous].isalnum() or line[previous] in "_)]")
                ):
                    continue
                type_opening = line.find("(", match.start())
                try:
                    type_closing = matching_parenthesis(line, type_opening)
                except ValueError:
                    continue
                expression_opening = type_closing + 1
                while (
                    expression_opening < len(line)
                    and line[expression_opening] in " \t"
                ):
                    expression_opening += 1
                if (
                    expression_opening >= len(line)
                    or line[expression_opening] != "("
                ):
                    continue
                try:
                    expression_closing = matching_parenthesis(
                        line,
                        expression_opening,
                    )
                except ValueError:
                    continue
                expression = line[
                    expression_opening + 1 : expression_closing
                ]
                if re.match(r"\s*s(?:32|64)\s*$", expression):
                    continue
                edits.append(
                    (
                        match.start(),
                        expression_closing + 1,
                        f"*(({match.group('type').strip()} *)"
                        f"(s32)({expression}))",
                    )
                )
            for start, end, replacement in sorted(edits, reverse=True):
                line = line[:start] + replacement + line[end:]
            pointer_required_lines.append(line)
        body = "\n".join(pointer_required_lines)
        for name, pointer_type in pointer_types.items():
            if "(*)" not in pointer_type:
                continue
            body = re.sub(
                rf"\*\s*{re.escape(name)}\s*\(",
                f"(*{name})(",
                body,
            )
        for name in sorted(scalar_types, key=len, reverse=True):
            body = re.sub(
                rf"(?<![\w)])\b{re.escape(name)}\s*\[",
                f"((u8 *)(s32)({name}))[",
                body,
            )
    if "illegal operands" in detail:
        def previous_nonspace(text: str, index: int) -> int:
            while index >= 0 and text[index] in " \t":
                index -= 1
            return index

        def is_binary_operator(text: str, index: int) -> bool:
            if index < 0 or text[index] not in "*/+-":
                return False
            previous = previous_nonspace(text, index - 1)
            return not (
                text[index] == "*"
                and (
                    previous < 0
                    or text[previous] in "=(:,{;"
                )
            )

        def targeted_pointer_operands(text: str) -> str:
            edits: list[tuple[int, int, str]] = []
            line_start = 0
            for raw_line in text.splitlines(keepends=True):
                line = raw_line.rstrip("\r\n")
                for opening_match in re.finditer(r"\(", line):
                    opening = opening_match.start()
                    try:
                        closing = matching_parenthesis(line, opening)
                    except ValueError:
                        continue
                    inner = line[opening + 1 : closing]
                    address_operand = re.match(
                        rf"\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)\s*&"
                        rf"[A-Za-z_]\w*",
                        inner,
                    )
                    cast_operand = re.match(
                        rf"\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)"
                        rf"\s*\(",
                        inner,
                    )
                    integer_pointer_operand = re.match(
                        rf"\s*\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)"
                        rf"\s*\(\s*s32\s*\)",
                        inner,
                    )
                    if (
                        address_operand is None
                        and cast_operand is None
                        and integer_pointer_operand is None
                    ):
                        continue
                    before = previous_nonspace(line, opening - 1)
                    after = closing + 1
                    while after < len(line) and line[after] in " \t":
                        after += 1
                    if not (
                        is_binary_operator(line, before)
                        or after < len(line) and line[after] in "*/+-"
                    ):
                        continue
                    if integer_pointer_operand is not None:
                        second_cast = re.search(r"\(\s*s32\s*\)", inner)
                        if second_cast is None:
                            continue
                        replacement = inner[second_cast.start() :]
                    else:
                        replacement = (
                            f"(s32)({line[opening:closing + 1]})"
                        )
                    edits.append(
                        (
                            line_start + opening,
                            line_start + closing + 1,
                            replacement,
                        )
                    )
                cast_re = re.compile(
                    rf"\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)\s*\("
                )
                for cast_match in cast_re.finditer(line):
                    second_opening = line.find("(", cast_match.start() + 1)
                    try:
                        first_closing = matching_parenthesis(
                            line,
                            second_opening,
                        )
                    except ValueError:
                        continue
                    next_opening = first_closing + 1
                    while next_opening < len(line) and line[next_opening] in " \t":
                        next_opening += 1
                    if next_opening < len(line) and line[next_opening] == "(":
                        second_opening = next_opening
                    try:
                        closing = matching_parenthesis(line, second_opening)
                    except ValueError:
                        continue
                    before = previous_nonspace(line, cast_match.start() - 1)
                    after = closing + 1
                    while after < len(line) and line[after] in " \t":
                        after += 1
                    if not (
                        is_binary_operator(line, before)
                        or after < len(line) and line[after] in "*/+-"
                    ):
                        continue
                    edits.append(
                        (
                            line_start + cast_match.start(),
                            line_start + closing + 1,
                            f"(s32)({line[cast_match.start():closing + 1]})",
                        )
                    )
                for field_match in re.finditer(r"\bM2C_FIELD\s*\(", line):
                    opening = line.find("(", field_match.start())
                    try:
                        closing = matching_parenthesis(line, opening)
                    except ValueError:
                        continue
                    call = line[field_match.start() : closing + 1]
                    if not re.search(
                        rf",\s*{POINTER_BASE_TYPE_RE}\s*\*+\s*,",
                        call,
                    ) or "(*)" in call:
                        continue
                    before = previous_nonspace(line, field_match.start() - 1)
                    after = closing + 1
                    while after < len(line) and line[after] in " \t":
                        after += 1
                    if not (
                        is_binary_operator(line, before)
                        or after < len(line) and line[after] in "*/+-"
                    ):
                        continue
                    edits.append(
                        (
                            line_start + field_match.start(),
                            line_start + closing + 1,
                            f"(s32)({call})",
                        )
                    )
                line_start += len(raw_line)
            accepted: list[tuple[int, int, str]] = []
            for edit in sorted(
                edits,
                key=lambda item: (item[0], -(item[1] - item[0])),
            ):
                if any(
                    edit[0] < other[1] and other[0] < edit[1]
                    for other in accepted
                ):
                    continue
                accepted.append(edit)
            for start, end, replacement in sorted(accepted, reverse=True):
                text = text[:start] + replacement + text[end:]
            return text

        if "unsigned char *' + 'float'" in detail:
            for name in sorted(scalar_types, key=len, reverse=True):
                body = re.sub(
                    rf"(?P<base>\(\s*{POINTER_BASE_TYPE_RE}\s*\*\s*\)"
                    rf"\s*&[A-Za-z_]\w*)\s*\+\s*{re.escape(name)}\b",
                    rf"\g<base> + (s32)({name})",
                    body,
                )
        for _ in range(3):
            body = targeted_pointer_operands(body)
        if pointer_types:
            compound_re = re.compile(
                r"^(?P<indent>\s*)(?P<name>[A-Za-z_]\w*)\s*"
                r"(?P<operator>\+=|-=|\*=|/=)\s*(?P<rhs>[^;]+);"
            )
            compound_lines = []
            for line in body.splitlines():
                compound = compound_re.match(line)
                if (
                    compound is not None
                    and compound.group("name") in pointer_types
                    and "*" in pointer_types[compound.group("name")]
                    and pointerish(compound.group("rhs").strip())
                ):
                    line = (
                        f"{compound.group('indent')}{compound.group('name')}"
                        f" {compound.group('operator')} "
                        f"(s32)({compound.group('rhs').strip()});"
                    )
                compound_lines.append(line)
            body = "\n".join(compound_lines)
    def repair_unbalanced_line(line: str) -> str:
        depth = 0
        remove: list[int] = []
        for index, character in enumerate(line):
            if character == "(":
                depth += 1
            elif character == ")":
                depth -= 1
                if depth < 0:
                    remove.append(index)
                    depth = 0
        if not remove:
            return line
        return "".join(
            character for index, character in enumerate(line)
            if index not in set(remove)
        )
    body = re.sub(
        r"(?m)^(?P<indent>[ \t]*)(?P<label>(?:block|loop)_[A-Za-z0-9_]+:)"
        r"[ \t]*\n(?P<close>[ \t]*)\}",
        r"\g<indent>\g<label>\n\g<close>    ;\n\g<close>}",
        body,
    )
    body = re.sub(
        r"(?m)^(?P<indent>[ \t]*)(?P<label>(?:block|loop)_[A-Za-z0-9_]+:)"
        r"[ \t]*\n(?P<next>[ \t]*)(?=(?:block|loop)_[A-Za-z0-9_]+:)",
        r"\g<indent>\g<label>\n\g<next>    ;\n\g<next>",
        body,
    )
    body = "\n".join(repair_unbalanced_line(line) for line in body.splitlines())
    if (
        "pointer/array required" in detail
        or (address is not None and address in pointer_repair_addresses)
    ):
        final_pointer_lines: list[str] = []
        final_deref_re = re.compile(
            rf"\*\s*\(\s*(?P<type>{POINTER_BASE_TYPE_RE})\s*\)\s*\("
        )
        for raw_line in body.splitlines():
            line = raw_line
            edits: list[tuple[int, int, str]] = []
            for match in final_deref_re.finditer(line):
                previous = match.start() - 1
                while previous >= 0 and line[previous] in " \t":
                    previous -= 1
                if (
                    previous >= 0
                    and (line[previous].isalnum() or line[previous] in "_)]")
                ):
                    continue
                type_opening = line.find("(", match.start())
                try:
                    type_closing = matching_parenthesis(line, type_opening)
                except ValueError:
                    continue
                expression_opening = type_closing + 1
                while (
                    expression_opening < len(line)
                    and line[expression_opening] in " \t"
                ):
                    expression_opening += 1
                if (
                    expression_opening >= len(line)
                    or line[expression_opening] != "("
                ):
                    continue
                try:
                    expression_closing = matching_parenthesis(
                        line,
                        expression_opening,
                    )
                except ValueError:
                    continue
                expression = line[
                    expression_opening + 1 : expression_closing
                ]
                if re.match(r"\s*s(?:32|64)\s*$", expression):
                    continue
                edits.append(
                    (
                        match.start(),
                        expression_closing + 1,
                        f"*(({match.group('type').strip()} *)"
                        f"(s32)({expression}))",
                    )
                )
            for start, end, replacement in sorted(edits, reverse=True):
                line = line[:start] + replacement + line[end:]
            final_pointer_lines.append(line)
        body = "\n".join(final_pointer_lines)
        for name, pointer_type in pointer_types.items():
            if "(*)" not in pointer_type:
                continue
            body = re.sub(
                rf"\*\s*{re.escape(name)}\s*\(",
                f"(*{name})(",
                body,
            )
    if "illegal implicit conversion from" in detail:
        def repair_nested_pointer_assignments(text: str) -> str:
            replacements: list[tuple[int, int, str]] = []
            line_start = 0
            for raw_line in text.splitlines(keepends=True):
                line = raw_line.rstrip("\r\n")
                for field_match in re.finditer(r"\bM2C_FIELD\s*\(", line):
                    opening = line.find("(", field_match.start())
                    try:
                        closing = matching_parenthesis(line, opening)
                    except ValueError:
                        continue
                    call = line[field_match.start() : closing + 1]
                    field_type = re.search(
                        rf",\s*(?P<base>{POINTER_BASE_TYPE_RE})"
                        rf"\s*(?P<stars>\*+)\s*,",
                        call,
                    )
                    if field_type is None or len(field_type.group("stars")) < 2:
                        continue
                    equal = closing + 1
                    while equal < len(line) and line[equal] in " \t":
                        equal += 1
                    if (
                        equal >= len(line)
                        or line[equal] != "="
                        or equal + 1 < len(line)
                        and line[equal + 1] == "="
                    ):
                        continue
                    end = equal + 1
                    depth = 0
                    while end < len(line):
                        character = line[end]
                        if character == "(":
                            depth += 1
                        elif character == ")":
                            depth -= 1
                        elif depth == 0 and character in ",;":
                            break
                        end += 1
                    rhs = line[equal + 1 : end].strip()
                    if not rhs or rhs == "NULL":
                        continue
                    base = field_type.group("base")
                    target = (
                        f"{base} "
                        f"{'*' * (len(field_type.group('stars')) - 1)}"
                    ).strip()
                    if re.match(
                        rf"^\(*\s*{re.escape(target)}\s*\*?\s*\)",
                        rhs,
                    ) or pointerish(rhs):
                        continue
                    replacement = (
                        f"{call} = ({target})(s32)({rhs})"
                    )
                    replacements.append(
                        (
                            line_start + field_match.start(),
                            line_start + end,
                            replacement,
                        )
                    )
                line_start += len(raw_line)
            for start, end, replacement in sorted(replacements, reverse=True):
                text = text[:start] + replacement + text[end:]
            return text

        body = repair_nested_pointer_assignments(body)
    syntax_repair_addresses = {
        0x00107890,
        0x001579B0,
        0x0015A6B0,
        0x0015A740,
        0x0018A200,
        0x0029A9C0,
        0x0029AB80,
        0x003C6C10,
        0x003C70E0,
        0x003E6A90,
        0x003F2830,
        0x004052B0,
        0x00413B80,
        0x0041EEB8,
        0x004685C0,
        0x00473B20,
        0x00478410,
        0x004DACB8,
        0x004EF1C0,
        0x004EF360,
        0x004EF4D8,
        0x00516F60,
        0x0051BC98,
        0x00522F40,
    }
    if address is not None and (
        address in syntax_repair_addresses
        or any(
            token in detail
            for token in (
                "syntax error",
                "expected",
                "identifier expected",
                "not an lvalue",
                "call of non-function",
            )
        )
    ):
        body = re.sub(
            rf"(?m)^(?P<i>\s*)(?P<type>{POINTER_BASE_TYPE_RE})\s+"
            rf"\(\*(?P<name>[A-Za-z_]\w*)\(\);",
            r"\g<i>\g<type> (*\g<name>)();",
            body,
        )
        body = re.sub(
            rf"(?m)^(?P<i>\s*)(?P<type>{POINTER_BASE_TYPE_RE}"
            rf"(?:\s*\*)*)\s*\(\*(?P<name>[A-Za-z_]\w*)\(\);",
            r"\g<i>\g<type> (*\g<name>)();",
            body,
        )
        if address == 0x00107890:
            body = re.sub(
                r"(?m)^\s*if .*func_00248760.*$",
                "    if (((arg0 & 0xFFFF) == (s32)(func_00248760(var_17 & 0xFFFF))) "
                "&& (func_001070e0(var_17 & 0xFFFF) != NULL)) {",
                body,
                count=1,
            )
        elif address == 0x001579B0:
            body = re.sub(
                r"(?m)^(?P<i>\s*)var_5 = .*D_005F0080.*$",
                r"\g<i>var_5 = (s16 *)((s32)&D_005F0080 + "
                r"(s32)(*((u8 *)(*((u8 *)(&D_005F0590 + temp_4_2)) + "
                r"((s32)&D_005F0591 + temp_4_2)))) * 0x56);",
                body,
            )
            body = re.sub(
                r"(?m)^(?P<i>\s*)if \(\(temp_17_2 != 0\).*$",
                r"\g<i>if ((temp_17_2 != 0) || (temp_17_3 == 0) || "
                r"((var_18 != 3) && (var_18 != 6))) {",
                body,
                count=1,
            )
        elif address == 0x0015A6B0:
            body = re.sub(
                r"(?m)^(?P<i>\s*)if \(\*\(\(u8 \*\)\(\(\(s32\)&D_007E31E4 "
                r"\+ .*\)\)\)\)\) << 6 != 0 \{$",
                r"\g<i>if (((s32)(*((u8 *)((s32)&D_007E31E4 + "
                r"((arg0 - (s32)(*((u8 *)(&D_005F05CE + temp_6)))) << 6)))) "
                r"<< 6) != 0) {",
                body,
            )
        elif address == 0x0015A740:
            body = re.sub(
                r"(?m)^(?P<i>\s*)return \(u8\)\(.*D_007E36E4.*$",
                r"\g<i>return (u8)((s32)(*((u8 *)((s32)&D_007E36E4 + "
                r"(arg0 - (s32)(*((u8 *)(&D_005F05CE + temp_5))))))) "
                r"* temp_5);",
                body,
            )
        elif address == 0x0029A9C0:
            body = re.sub(
                r"(?m)^(?P<i>\s*)\*\(\(u8 \*\)\(M2C_FIELD\(arg0, s32 \*, 0x140\)"
                r"[^;]*\)\s*=\s*var_4;$",
                r"\g<i>*((u8 *)(s32)(M2C_FIELD(arg0, s32 *, 0x140) + "
                r"(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) * 4) + "
                r"M2C_FIELD(arg0, s32 *, 0x120), s16 *, 2) * 4))) = var_4;",
                body,
            )
        elif address == 0x0029AB80:
            body = re.sub(
                r"(?m)^(?P<i>\s*)\*\(\(u8 \*\)\(M2C_FIELD\(arg0, s32 \*, 0x144\)"
                r"[^;]*\)\s*=\s*var_f0;$",
                r"\g<i>*((u8 *)(s32)(M2C_FIELD(arg0, s32 *, 0x144) + "
                r"(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) * 4) + "
                r"M2C_FIELD(arg0, s32 *, 0x120), s16 *, 2) * 4))) = var_f0;",
                body,
            )
        elif address == 0x003C6C10:
            body = body.replace(
                "M2C_FIELD(((M2C_UNK)(M2C_ERROR(/* Read from unset register $t8 */) "
                "+ (M2C_FIELD(M2C_ERROR(/* Read from unset register $t8 */), "
                "s32 *, 4) * 2)), u16 *, -2)",
                "M2C_FIELD((s32)(M2C_ERROR(/* Read from unset register $t8 */) "
                "+ (M2C_FIELD(M2C_ERROR(/* Read from unset register $t8 */), "
                "s32 *, 4) * 2)), u16 *, -2)",
            )
            body = body.replace(
                "(M2C_UNK)(M2C_ERROR(/* Read from unset register $t8 */) +",
                "(s32)(M2C_ERROR(/* Read from unset register $t8 */) +",
            )
        elif address == 0x003C70E0:
            body = body.replace(
                "((M2C_UNK (*)())(*(M2C_UNK)))"
                "(M2C_ERROR(/* Read from unset register $t9 */) * 0x14)",
                "((M2C_UNK (*)())(M2C_ERROR(/* Read from unset register $t9 */)))"
                "(M2C_ERROR(/* Read from unset register $t9 */) * 0x14)",
            )
        elif address == 0x003F2830:
            body = re.sub(
                r"\*\(\(u8 \*\)(?:\(s32\))?"
                r"\(M2C_UNK \(\*\*\)\(\)\)\)(0x1000[0-9A-F]+)",
                r"*((u8 *)(s32)\1)",
                body,
            )
            body = body.replace(
                "M2C_FIELD(var_28, M2C_UNK (**)(), -0x47D0) + 8",
                "(s32)(M2C_FIELD(var_28, M2C_UNK (**)(), -0x47D0)) + 8",
            )
            body = body.replace(
                "*temp_4_3 = (s32)((s32) (*temp_4_3 - (temp_2 >> 0xC)));",
                "temp_4_3 = (s32 (*)(s32, s32))((s32)(temp_4_3) "
                "- (s32)(temp_2 >> 0xC));",
            )
            body = body.replace(
                "*temp_3_2 = (s32)((s32) (*temp_3_2 - 1));",
                "temp_3_2 = (s32 (*)(s32, s32))((s32)(temp_3_2) - 1);",
            )
            body = body.replace(
                "*temp_4_3 = (s32 ()((s32) (*temp_4_3 - (temp_2 >> 0xC)));",
                "temp_4_3 = (s32 (*)(s32, s32))((s32)(temp_4_3) "
                "- (s32)(temp_2 >> 0xC));",
            )
            body = body.replace(
                "*temp_3_2 = (s32 ()((s32) (*temp_3_2 - 1));",
                "temp_3_2 = (s32 (*)(s32, s32))((s32)(temp_3_2) - 1);",
            )
            function_pointer_lines: list[str] = []
            for line in body.splitlines():
                if (
                    line.lstrip().startswith("*((u8 *)")
                    and " = M2C_FIELD" in line
                    and "M2C_UNK (**)()" in line
                    and line.rstrip().endswith(";")
                ):
                    line = line.replace(
                        " = M2C_FIELD",
                        " = (u8)(s32)(M2C_FIELD",
                        1,
                    ).rstrip()[:-1] + ");"
                function_pointer_lines.append(line)
            body = "\n".join(function_pointer_lines)
        elif address == 0x003D6350:
            body = body.replace(
                "M2C_FIELD(arg0, M2C_UNK *, 0x28)(arg1)",
                "((M2C_UNK (*)())(M2C_FIELD(arg0, M2C_UNK *, 0x28)))(arg1)",
            )
            body = body.replace(
                "M2C_FIELD(M2C_FIELD(var_16, u8 **, 0), M2C_UNK (*)(), 0x18)"
                "(temp_2_2)",
                "((M2C_UNK (*)())(M2C_FIELD("
                "M2C_FIELD(var_16, u8 **, 0), M2C_UNK (*)(), 0x18)))"
                "(temp_2_2)",
            )
            body = body.replace(
                "M2C_FIELD(arg0, M2C_UNK (*)(), 0x1C)(temp_2_2)",
                "((M2C_UNK (*)())(M2C_FIELD(arg0, M2C_UNK (*)(), 0x1C)))"
                "(temp_2_2)",
            )
        elif address in {0x003CA430, 0x003CA830, 0x003DEA20, 0x003E8C60}:
            body = re.sub(
                r"&\(s32\)\((func_[0-9A-Fa-f]+)\)",
                r"&\1",
                body,
            )
        elif address == 0x0043F668:
            body = body.replace(
                "*((u8 *)((arg1 = = (u8)(NULL) ? sp : arg1)) = (s32) *arg2);",
                "*((u8 *)(arg1 == NULL ? sp : arg1)) = (s32) *arg2;",
            )
        elif address == 0x004BE4A8:
            body = body.replace(
                "**temp_4_2(",
                "(**temp_4_2)(",
            )
            body = body.replace(
                "**temp_4_3(",
                "(**temp_4_3)(",
            )
        elif address == 0x00518E10:
            body = body.replace(
                "sp4(arg0, arg1);",
                "((M2C_UNK (*)())(sp4))(arg0, arg1);",
            )
            body = body.replace(
                "sp8(spC, arg1);",
                "((M2C_UNK (*)())(sp8))(spC, arg1);",
            )
        elif address == 0x00516F60:
            body = body.replace(
                "((M2C_UNK (*)())(func_00525098((u8 *)0x4B)))",
                "func_00525098((u8 *)0x4B)",
            )
            body = body.replace(
                "temp_16(temp_4, arg1, arg2);",
                "(*temp_16)(temp_4, arg1, arg2);",
            )
        elif address == 0x0051BC98:
            body = body.replace(
                "((M2C_UNK (*)())(func_00525098(arg0, 0x5F)))",
                "func_00525098(arg0, 0x5F)",
            )
            body = body.replace(
                "((M2C_UNK (*)())(func_00525098(arg0, 0x4D)))",
                "func_00525098(arg0, 0x4D)",
            )
            body = body.replace(
                "((M2C_UNK (*)())(func_00525098(arg0, 0x4E)))",
                "func_00525098(arg0, 0x4E)",
            )
            body = body.replace(
                "temp_17_3(temp_16_3, temp_5_2,",
                "(*temp_17_3)(temp_16_3, temp_5_2,",
            )
        elif address == 0x004EF1C0:
            body = body.replace(
                "*temp_7 = (M2C_UNK)(temp_2);",
                "temp_7 = (M2C_UNK (*)(s32, M2C_UNK))(temp_2);",
            )
            body = body.replace(
                "*temp_7 = (M2C_UNK ()(temp_2);",
                "temp_7 = (M2C_UNK (*)(s32, M2C_UNK))(temp_2);",
            )
        elif address == 0x004052B0:
            repaired_lines: list[str] = []
            for line in body.splitlines():
                if line.lstrip().startswith(
                    "(M2C_UNK)(*((u8 *)(s32)(M2C_ERROR("
                ):
                    line = line.replace("(M2C_UNK)(", "", 1)
                    if line.endswith("));"):
                        line = line[:-2] + ";"
                repaired_lines.append(line)
            body = "\n".join(repaired_lines)
            body = body.replace("F * 2;", ";").replace("F * 4;", ";")
            body = "\n".join(repair_unbalanced_line(line) for line in body.splitlines())
        elif address == 0x00413B80:
            body = re.sub(
                r"(?m)^(?P<i>\s*)temp_12 = .*var_25\)\);$",
                r"\g<i>temp_12 = (u8 *)((s32)(M2C_ERROR("
                r"/* Read from unset register $a4 */)) + 0x30 + var_25);",
                body,
            )
        elif address == 0x0041EEB8:
            body = re.sub(
                r"(?m)^(?P<i>\s*)if .*func_0041ea90\(temp_16, 1\).*$",
                r"\g<i>if ((func_0041ea90(temp_16, 1) != 0) "
                r"&& (var_19 != 0)) {",
                body,
                count=1,
            )
            body = body.replace(
                "temp_7(arg0, sp, M2C_FIELD((temp_8 + (s32)(temp_6)), "
                "s32 *, 0x10), temp_7, temp_8);",
                "(*temp_7)(arg0, sp, M2C_FIELD((temp_8 + (s32)(temp_6)), "
                "s32 *, 0x10), temp_7, temp_8);",
            )
        elif address == 0x004685C0:
            body = body.replace(
                "*((u8 *)(*((u8 *)(&D_00712AA0 + "
                "(M2C_FIELD(arg0, s32 *, 8) * 4))) + "
                "M2C_FIELD(arg0, s32 *, 4)))2 *, 4)",
                "M2C_FIELD((*((u8 *)(&D_00712AA0 + "
                "(M2C_FIELD(arg0, s32 *, 8) * 4))) + "
                "M2C_FIELD(arg0, s32 *, 4)), u16 *, 4)",
            )
            repaired_lines = []
            for line in body.splitlines():
                if line.lstrip().startswith("M2C_ERROR(") and line.endswith("));"):
                    line = line[:-2] + ";"
                repaired_lines.append(line)
            body = "\n".join(repaired_lines)
        elif address == 0x00473B20:
            body = re.sub(
                r"(?m)^(?P<i>\s*)if \(\(\(s32\)\(temp_5_2\) != .*$",
                r"\g<i>if ((s32)(temp_5_2) != (s32)(NULL)) {",
                body,
                count=1,
            )
            body = re.sub(
                r"(?m)^(?P<i>\s*)\} else if .*temp_5_2\) == .*$",
                r"\g<i>} else if ((s32)(temp_5_2) == (s32)(NULL)) {",
                body,
                count=1,
            )
        elif address == 0x00475350:
            body = re.sub(
                r"(?m)^(?P<i>\s*)if \(\(\(s32\)\(temp_4_2\) != .*$",
                r"\g<i>if ((s32)(temp_4_2) != (s32)(NULL)) {",
                body,
                count=1,
            )
        elif address == 0x004DACB8:
            body = body.replace(
                ")))))07285F0;",
                ")))));",
            )
    if address == 0x0029AD40:
        body = body.replace("*temp_18_2()", "(*temp_18_2)()")
    elif address == 0x003E1740:
        body = body.replace(
            "var_7 = (M2C_UNK **) *((s32)(temp_3) + var_6);",
            "var_7 = *((M2C_UNK **)((s32)(temp_3) + var_6));",
        )
    elif address == 0x003F4730:
        body = body.replace(
            "*M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = (s128) D_0088C000;",
            "M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = (s32 *)(&D_0088C000);",
        )
    elif address in {
        0x00403930,
        0x00407FF0,
        0x0040DF50,
        0x00422DA0,
        0x004C4BA8,
        0x004D47C8,
        0x004FCD18,
        0x005033B0,
    }:
        body = re.sub(
            r"\*\s*\(\s*s32\s*\)\s*\(\s*([A-Za-z_]\w*)\s*\)",
            r"*((s32 *)(s32)(\1))",
            body,
        )
    elif address == 0x00413E50:
        body = body.replace(
            "M2C_FIELD(var_16, u8 **, 0x10) = (u8 *) *temp_3;",
            "M2C_FIELD(var_16, u8 **, 0x10) = (u8 *)(s32)(temp_3);",
        )
    elif address == 0x0041A5A8:
        body = body.replace(
            "((M2C_UNK (*)())(*((s32)(arg0) + 0x5C8 + temp_16_2)))",
            "((M2C_UNK (*)())(*((s32 *)((s32)(arg0) + 0x5C8 + temp_16_2))))",
        )
        body = body.replace(
            "((M2C_UNK (*)())(*((s32)(arg0) + 0x5D8 + temp_16_2)))",
            "((M2C_UNK (*)())(*((s32 *)((s32)(arg0) + 0x5D8 + temp_16_2))))",
        )
    elif address == 0x0043DC60:
        body = body.replace("*var_16();", "(*var_16)();")
    elif address == 0x004F34E8:
        body = body.replace("*temp_2()", "(*temp_2)()")
    elif address == 0x00525E90:
        body = re.sub(
            r"(?m)^\s*var_2 = .*;$",
            "    var_2 = (s32 (*)(M2C_UNK *, s32 *, s32 *))"
            "((s32)(arg0) + 0xD30 + (func_00525098(arg0, 0xF) * 4));",
            body,
            count=1,
        )
    if address == 0x003DC610:
        body = body.replace("var_2();", "var_2(arg0, arg1);")
    elif address == 0x004233F0:
        body = body.replace(
            "arg0(arg1, arg2, 0x2D);",
            "arg0(arg1, arg2, 0x2D, 0, 0);",
        )
    elif address == 0x004235C8:
        body = re.sub(
            r"\bsp44\(sp48, sp5C, ([A-Za-z0-9_]+)\)",
            r"sp44(sp48, sp5C, \1, 0, 0)",
            body,
        )
    elif address == 0x004EDC68:
        body = body.replace(
            "temp_2(M2C_FIELD(arg0, s32 *, 0x20), -3, var_6, arg0, temp_9);",
            "temp_2(M2C_FIELD(arg0, s32 *, 0x20), -3, var_6, "
            "arg0, temp_9, NULL);",
        )
    if address == 0x003E1740:
        body = body.replace(
            "var_7 = *((M2C_UNK **)((s32)(temp_3) + var_6));",
            "var_7 = (M2C_UNK **)(s32)"
            "(*((s32 *)((s32)(temp_3) + var_6)));",
        )
    elif address == 0x003F4730:
        body = body.replace(
            "M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = (s32 *)(&D_0088C000);",
            "M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = "
            "(s32 *)((s32)&D_0088C000);",
        )
    elif address == 0x003F4C90:
        body = re.sub(
            r"(?m)^\s*var_16 = .*_start.*$",
            "    var_16 = (u8 *)(s32)(0x100000 + 0x78);",
            body,
            count=1,
        )
    elif address == 0x004E2DA0:
        body = body.replace(
            "if (D_00923440 != temp_4) {",
            "if ((s32)(D_00923440) != (s32)(temp_4)) {",
        )
    elif address in {0x003CF140, 0x00473710}:
        seen_declarations: set[str] = set()
        deduplicated_lines: list[str] = []
        for line in body.splitlines():
            stripped = line.strip()
            if re.match(
                r"^(?:[A-Za-z_][\w ]*\s+)?(?:\(\*)?\w+\)?\s*\([^;]*\);$",
                stripped,
            ):
                if stripped in seen_declarations:
                    continue
                seen_declarations.add(stripped)
            deduplicated_lines.append(line)
        body = "\n".join(deduplicated_lines)
    def wrap_untyped_calls(text: str, names: Iterable[str]) -> str:
        wrapped_lines: list[str] = []
        for line in text.splitlines():
            for name in names:
                if re.match(
                    rf"^\s*(?!(?:return|if|while|switch)\b)"
                    rf"(?:extern\s+)?[A-Za-z_][\w\s\*]*\b"
                    rf"{re.escape(name)}\s*\(",
                    line,
                ):
                    continue
                line = re.sub(
                    rf"(?<![\w*]){re.escape(name)}\s*\(",
                    f"((M2C_UNK (*)())({name}))(",
                    line,
                )
            wrapped_lines.append(line)
        return "\n".join(wrapped_lines)

    if address == 0x00124F70:
        body = body.replace(
            "(sp35C >> 1) | (sp35C & 1)",
            "((M2C_BITWISE(s32, sp35C) >> 1) | "
            "(M2C_BITWISE(s32, sp35C) & 1))",
        )
        body = body.replace(
            "(unksp35D >> 1) | (unksp35D & 1)",
            "((M2C_BITWISE(s32, unksp35D) >> 1) | "
            "(M2C_BITWISE(s32, unksp35D) & 1))",
        )
        body = body.replace(
            "(unksp35E >> 1) | (unksp35E & 1)",
            "((M2C_BITWISE(s32, unksp35E) >> 1) | "
            "(M2C_BITWISE(s32, unksp35E) & 1))",
        )
        body = body.replace(
            "(unksp35F >> 1) | (unksp35F & 1)",
            "((M2C_BITWISE(s32, unksp35F) >> 1) | "
            "(M2C_BITWISE(s32, unksp35F) & 1))",
        )
    elif address in {0x001265A0, 0x00268230}:
        body = re.sub(
            r"\*\(\(u8 \*\)\(s32\)\(M2C_ERROR\(([^)]*)\)\)\)",
            r"M2C_BITWISE(f32, M2C_ERROR(\1))",
            body,
        )
    elif address == 0x0013EA20:
        body = body.replace("+ &jtbl_00746AD0", "+ (s32)&jtbl_00746AD0")
    elif address == 0x00159F70:
        body = body.replace(
            "temp_2_2 = temp_4 + 2 + temp_5",
            "temp_2_2 = (u16 *)(s32)(temp_4 + 2 + temp_5)",
        )
    elif address == 0x00164880:
        body = re.sub(
            r"(?m)(?P<i>\s*)temp_(?P<n>2|2_2|2_4) = "
            r"\(s32\)&D_007EF9B0 \+ (?P<rhs>[^,]+),",
            r"\g<i>temp_\g<n> = (u8 *)((s32)&D_007EF9B0 + \g<rhs>),",
            body,
        )
    elif address == 0x00172E00:
        body = re.sub(
            r"\}\s*else if \(\(s32\)\(\(\(M2C_UNK \(\*\)\(\)\)\(\*\(u8 \*\)\)\)"
            r"\(\(u8 \*\)\(func_001823c0\(\)\)\)\) != \(s32\)\(NULL\)\) \{",
            "} else if (func_001823c0() != NULL) {",
            body,
        )
    elif address == 0x001ECA10:
        body = body.replace(
            "temp_22 = (s32)(temp_2) + 8",
            "temp_22 = (f32 *)((s32)(temp_2) + 8)",
        )
    elif address == 0x0028B7B0:
        body = body.replace("= (s32 *)((s32) var_19);", "= (s32)((s32) var_19);")
    elif address == 0x002AA890:
        body = body.replace("switch (D_00882F24)", "switch ((s32)(D_00882F24))")
    elif address == 0x002ABB30:
        body = re.sub(r"\(u8 \*\)\(func_00460990\(", "(u8 *)(s32)(func_00460990(", body)
    elif address == 0x00311930:
        body = body.replace("*((s32 *) (", "* (s32) (")
    elif address == 0x00324680:
        body = body.replace(
            "temp_16 *((s64 *)((arg1 << 0x30) >> 0x30))",
            "temp_16 * (s64)(arg1)",
        )
    elif address == 0x0037F6E0:
        body = body.replace(
            "var_18 *((u8 *)&var_21 + 1)",
            "var_18 * (s32)(*((u8 *)&var_21 + 1))",
        )
    elif address in {0x00397480, 0x00397C40, 0x00471370}:
        body = re.sub(
            r"(?P<left>[0-9.]+f)\s+\*\s*\(\(u8 \*\)&(?P<base>\w+)"
            r"\s*\+\s*(?P<offset>[^)\n]+)\)",
            r"\g<left> * (f32)(*((u8 *)&\g<base> + \g<offset>))",
            body,
        )
    elif address == 0x003A3670:
        body = body.replace(
            "*((u8 *)&var_16 + 0x40 + (temp_30 *((u8 *)&spA0 + var_17)))",
            "(s32)(*((u8 *)&var_16 + 0x40 + "
            "(temp_30 * (s32)(*((u8 *)&spA0 + var_17)))))",
        )
    elif address in {
        0x003A2390,
        0x003EF260,
        0x00424D30,
        0x0042DC08,
        0x004623A0,
        0x0046EC70,
        0x004F1548,
        0x004F3780,
        0x0052AFB0,
    }:
        names = {
            0x003A2390: {"temp_2_3"},
            0x003EF260: {"arg1"},
            0x00424D30: {"var_6_2"},
            0x0042DC08: {"temp_6"},
            0x004623A0: {"temp_6", "temp_6_2"},
            0x0046EC70: {"temp_2"},
            0x004F1548: {"temp_4"},
            0x004F3780: {"temp_4"},
            0x0052AFB0: {"temp_2"},
        }[address]
        body = wrap_untyped_calls(body, names)
    elif address in {0x003A6650, 0x003A7A30}:
        body = body.replace(
            "temp_2 = *M2C_FIELD(arg0, u8 ***, 0x30)",
            "temp_2 = (u8 *)(s32)(*M2C_FIELD(arg0, u8 ***, 0x30))",
        )
        body = body.replace(
            "temp_2_2 = *((u8 *)(temp_18 + M2C_FIELD(saved_reg_gp, s32 *, -0x49F0)))",
            "temp_2_2 = (u8 *)((s32)(temp_18) + "
            "M2C_FIELD(saved_reg_gp, s32 *, -0x49F0))",
        )
    elif address == 0x003B8410:
        body = body.replace(
            "= arg1;",
            "= (u8)(s32)(arg1);",
        )
    elif address == 0x003C6C10:
        repaired_lines = []
        for line in body.splitlines():
            if "M2C_ERROR(/* Read from unset register $t8 */)" in line and "= M2C_ERROR(/* Read from unset register $a5 */)" in line:
                line = re.sub(
                    r"\*\(\(u8 \*\)\((?P<base>.*?)\)\) = "
                    r"M2C_ERROR\(/\* Read from unset register \$a5 \*/\)",
                    r"*((u8 *)(s32)(\g<base>)) = "
                    r"(u8)M2C_ERROR(/* Read from unset register $a5 */)",
                    line,
                )
            repaired_lines.append(line)
        body = "\n".join(repaired_lines)
    elif address == 0x003C8200:
        body = body.replace(
            "var_4_5 += var_5_3;",
            "var_4_5 += (s32)(var_5_3);",
        )
        body = body.replace(
            "M2C_FIELD(saved_reg_gp, M2C_UNK **, -0x4910)",
            "(s32)M2C_FIELD(saved_reg_gp, M2C_UNK **, -0x4910)",
        )
    elif address == 0x003CE170:
        body = body.replace(
            "M2C_FIELD(var_5, s32 *, 4) - M2C_FIELD(arg0, u8 **, 8)",
            "M2C_FIELD(var_5, s32 *, 4) - "
            "(s32)M2C_FIELD(arg0, u8 **, 8)",
        )
    elif address == 0x003CF610:
        body = re.sub(
            r"(?m)^(?P<i>\s*)\*temp_17_2 = "
            r"\(u8 \*\)\(M2C_FIELD\((?P<field>.*)\)\((?P<args>.*)\);$",
            r"\g<i>M2C_FIELD(\g<field>)(\g<args>);\n"
            r"\g<i>*temp_17_2 = NULL;",
            body,
        )
    elif address == 0x003D5840:
        body = body.replace(
            "temp_3_2 *((u8 *)&var_16 + var_7)",
            "temp_3_2 * (s32)(*((u8 *)&var_16 + var_7))",
        )
    elif address == 0x003D6350:
        body = re.sub(
            r"M2C_FIELD\((arg0), M2C_UNK \*, (0x(?:28|2C))\)\((arg1)\)",
            r"((M2C_UNK (*)())(M2C_FIELD(\1, M2C_UNK *, \2)))(\3)",
            body,
        )
    elif address in {0x003E1230, 0x003E12F0}:
        body = body.replace(
            "M2C_FIELD(var_4, M2C_UNK **, 0)",
            "(u8 *)(s32)M2C_FIELD(var_4, M2C_UNK **, 0)",
        )
    elif address in {0x003E13D0, 0x003E18C0}:
        body = re.sub(
            r"\*\(\(u8 \*\)&(?P<base>\w+) \+ (?P<offset>[^)\n]+)\)",
            r"(s32)(*((u8 *)&\g<base> + \g<offset>))",
            body,
        )
    elif address == 0x003E1B10:
        body = body.replace(
            "*M2C_FIELD(temp_2, s32 **, 0x20) = "
            "(s32 *)(s32)(M2C_FIELD(temp_2, s32 *, 0x1C));",
            "*M2C_FIELD(temp_2, s32 **, 0x20) = "
            "(s32)(M2C_FIELD(temp_2, s32 *, 0x1C));",
        )
        body = body.replace(
            "jtbl_008873E8 = (M2C_UNK *) func_003e1ae0;",
            "jtbl_008873E8 = (M2C_UNK (*)())(func_003e1ae0);",
        )
    elif address == 0x003E1C30:
        body = body.replace(
            "*M2C_FIELD(saved_reg_gp, u8 **, -0x4888);",
            "M2C_FIELD(saved_reg_gp, u8 **, -0x4888);",
        )
    elif address == 0x003E1F50:
        body = body.replace(
            "*M2C_FIELD(temp_6, M2C_UNK **, 4) = temp_6;",
            "*M2C_FIELD(temp_6, M2C_UNK **, 4) = (s32)(temp_6);",
        )
    elif address == 0x003E2910:
        body = body.replace(
            "M2C_FIELD(arg0, M2C_UNK (**)(), 0x10) - "
            "M2C_FIELD(arg0, u32 *, 0xC)",
            "(s32)M2C_FIELD(arg0, M2C_UNK (**)(), 0x10) - "
            "M2C_FIELD(arg0, u32 *, 0xC)",
        )
    elif address == 0x003ECE40:
        body = re.sub(
            r"\*\(\(u8 \*\)\(s32\)\(M2C_ERROR\(([^)]*)\)\)\)",
            r"M2C_BITWISE(f32, M2C_ERROR(\1))",
            body,
        )
        body = re.sub(
            r"(M2C_FIELD\([^;]*?, f32 \*, 0x[0-9A-Fa-f]+)\s+\*\s+"
            r"\(\(u8 \*\)\(s32\)\(M2C_ERROR\(([^)]*)\)\)\)",
            r"\1 * M2C_BITWISE(f32, M2C_ERROR(\2))",
            body,
        )
    elif address in {0x003F0C10, 0x003F0DE0, 0x003F13B0, 0x003F39C0, 0x003F3EB0}:
        body = wrap_untyped_calls(
            body,
            {
                0x003F0C10: {"func_003f0c10"},
                0x003F0DE0: {"func_003f0de0"},
                0x003F13B0: {"func_003f13b0"},
                0x003F39C0: {"func_003f39c0"},
                0x003F3EB0: {"func_003f3eb0"},
            }[address],
        )
    elif address == 0x003FBFF0:
        body = body.replace(
            "M2C_FIELD(arg0, s32 *, 0x18) *((u8 *)&var_25 + var_19)",
            "M2C_FIELD(arg0, s32 *, 0x18) * "
            "(s32)(*((u8 *)&var_25 + var_19))",
        )
    elif address == 0x003FC280:
        body = body.replace(
            "M2C_FIELD(arg0, s32 *, 0x18) *((u8 *)&var_15 + var_25)",
            "M2C_FIELD(arg0, s32 *, 0x18) * "
            "(s32)(*((u8 *)&var_15 + var_25))",
        )
    elif address == 0x004052B0:
        body = body.replace(
            "M2C_FIELD(temp_9, s32 *, 0x18) *((u8 *)(s32)(M2C_ERROR(/* Read from unset register $a6 */)))",
            "M2C_FIELD(temp_9, s32 *, 0x18) * "
            "(s32)M2C_ERROR(/* Read from unset register $a6 */)",
        )
        body = re.sub(
            r"\(\(u32 \*\)\(\((?P<expr>[^;\n]+?)\)\)\)",
            r"(u32)(s32)(\g<expr>)",
            body,
        )
    if address in {0x001265A0, 0x00268230}:
        body = body.replace(
            "255.0f M2C_BITWISE",
            "255.0f * M2C_BITWISE",
        )
        body = body.replace(
            "3.0f M2C_BITWISE",
            "3.0f * M2C_BITWISE",
        )
    elif address == 0x00311930:
        body = body.replace(" / 100));", " / 100);")
    elif address == 0x00331A20:
        body = body.replace(
            "temp_16_2 = (s32)&D_00645090",
            "temp_16_2 = (u8 *)((s32)&D_00645090",
        )
        body = body.replace(
            "* 0x10), ((s32)(func_00106330",
            "* 0x10)), ((s32)(func_00106330",
        )
    elif address in {0x00392BF0, 0x00393900, 0x003941E0, 0x00394870}:
        body = wrap_untyped_calls(
            body,
            {
                0x00392BF0: {"spD8"},
                0x00393900: {"spF8"},
                0x003941E0: {"spB4"},
                0x00394870: {"spC0"},
            }[address],
        )
    elif address in {0x00397480, 0x00397C40, 0x00471370}:
        body = re.sub(
            r"\+\s*(temp_[A-Za-z0-9_]+)",
            r"+ (s32)(\1)",
            body,
        )
    elif address == 0x003A3670:
        body = body.replace(
            "temp_22 (s32)(*((u8 *)&var_16",
            "temp_22 * (s32)(*((u8 *)&var_16",
        )
    elif address == 0x003BFF30:
        body = body.replace("arg0 + 8", "(s32)(arg0) + 8")
        body = body.replace(
            "(s32)(var_2) - 0x40",
            "(u8 *)((s32)(var_2) - 0x40)",
        )
        body = wrap_untyped_calls(body, {"arg1"})
    elif address == 0x003C6C10:
        repaired_lines = []
        for line in body.splitlines():
            if "= (u8)M2C_ERROR(/* Read from unset register $a5 */)" in line:
                indent = line[: len(line) - len(line.lstrip())]
                line = (
                    f"{indent}*((u8 *)(s32)"
                    "M2C_ERROR(/* Read from unset register $t8 */)) = "
                    "(u8)M2C_ERROR(/* Read from unset register $a5 */);"
                )
            repaired_lines.append(line)
        body = "\n".join(repaired_lines)
    elif address == 0x003C8200:
        body = body.replace(
            "temp_19[var_20 & 0xFFFF] = temp_2_7;",
            "temp_19[var_20 & 0xFFFF] = (M2C_UNK)(s32)(temp_2_7);",
        )
    elif address in {0x003CF140, 0x00473710}:
        declaration_re = {
            0x003CF140: re.compile(r"^\s*M2C_UNK \(\*sp114\)"),
            0x00473710: re.compile(r"^\s*s32 \(\*sp5C\)"),
        }[address]
        body = "\n".join(
            line
            for line in body.splitlines()
            if declaration_re.search(line) is None
        )
    elif address == 0x003CF610:
        body = body.replace(
            "M2C_FIELD(temp_18, u8 *(**)(u8 **, u8 **, s32, M2C_UNK (*)()), 4)"
            "(arg0, temp_17_2, temp_2, func_003cc6e0);",
            "M2C_FIELD(temp_18, u8 *(**)(u8 **, u8 **, s32, M2C_UNK (*)()), 4)"
            "(arg0, temp_17_2, temp_2, (M2C_UNK (*)())(func_003cc6e0));",
        )
    elif address in {0x003E13D0, 0x003E18C0}:
        body = body.replace(
            "M2C_FIELD(arg0, s32 *, 0) (s32)",
            "M2C_FIELD(arg0, s32 *, 0) * (s32)",
        )
        body = body.replace(
            "M2C_FIELD(arg0, s32 *, 0) (s32)",
            "M2C_FIELD(arg0, s32 *, 0) * (s32)",
        )
    elif address == 0x003E1B10:
        body = body.replace(
            "jtbl_008873E8 = (M2C_UNK (*)())(func_003e1ae0);",
            "jtbl_008873E8 = (M2C_UNK * (*)(M2C_UNK *, s32, s32, "
            "u8 *, s32, s32, M2C_UNK *))(func_003e1ae0);",
        )
    elif address == 0x003ECE40:
        body = body.replace(
            "M2C_FIELD(arg5, f32 *, 0) M2C_BITWISE",
            "M2C_FIELD(arg5, f32 *, 0) * M2C_BITWISE",
        )
        body = body.replace(
            "M2C_FIELD(arg5, f32 *, 4) M2C_BITWISE",
            "M2C_FIELD(arg5, f32 *, 4) * M2C_BITWISE",
        )
        body = body.replace(
            "M2C_FIELD(arg5, f32 *, 8) M2C_BITWISE",
            "M2C_FIELD(arg5, f32 *, 8) * M2C_BITWISE",
        )
        body = body.replace(
            "M2C_FIELD(arg5, f32 *, 0xC) M2C_BITWISE",
            "M2C_FIELD(arg5, f32 *, 0xC) * M2C_BITWISE",
        )
    elif address == 0x003F4730:
        body = body.replace(
            "M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = (s32 *)((s32)&D_0088C000);",
            "M2C_FIELD(saved_reg_gp, s32 *, -0x47B8) = (s32)&D_0088C000;",
        )
    if address in {0x003CA430, 0x003CA830, 0x003DEA20, 0x003E8C60}:
        body = re.sub(r"&\s*\(s32\)\(func_", "&func_", body)
    elif address in {0x0040E830, 0x0040F570, 0x0040FA90, 0x0040FCD0}:
        for name in ("temp_5_2", "var_6", "temp_6", "temp_5"):
            body = body.replace(
                f"{name} - D_0070C354",
                f"(s32)({name}) - D_0070C354",
            )
        body = body.replace(
            "D_0070C354 + temp_13",
            "(s32)D_0070C354 + temp_13",
        )
    elif address == 0x00411FD0:
        body = wrap_untyped_calls(body, {"func_00411fd0"})
    elif address == 0x004125E0:
        body = body.replace(
            "temp_4 *((u8 *)&temp_2_2 + 1)",
            "temp_4 * (s32)(*((u8 *)&temp_2_2 + 1))",
        )
    elif address == 0x00413410:
        body = body.replace(
            "M2C_FIELD(arg0, s32 *, 8) + (temp_6_2 * 0x28)",
            "(u8 *)((s32)M2C_FIELD(arg0, s32 *, 8) + "
            "(temp_6_2 * 0x28))",
        )
    elif address == 0x00415960:
        body = body.replace("spC &", "M2C_BITWISE(s32, spC) &")
        body = body.replace("spC >>", "M2C_BITWISE(s32, spC) >>")
        body = body.replace(
            "(spC & 0x80000000)",
            "(M2C_BITWISE(s32, spC) & 0x80000000)",
        )
    elif address == 0x00418488:
        body = body.replace(
            "+ &jtbl_00753720",
            "+ (s32)&jtbl_00753720",
        )
    elif address in {0x0041ED48, 0x0041F370, 0x0041F3E8}:
        body = wrap_untyped_calls(body, {"temp_7"})
    elif address == 0x0041EEB8:
        body = re.sub(
            r"(?m)^(?P<i>\s*)if .*M2C_FIELD\(temp_16, s32 \*, 0x184\).*$",
            r"\g<i>if ((M2C_FIELD(temp_16, s32 *, 0x184) != 0) "
            r"&& (var_19 != 0)) {",
            body,
            count=1,
        )
        body = wrap_untyped_calls(body, {"temp_7"})
    elif address == 0x00422DA0:
        body = re.sub(
            r"(?m)^\s*M2C_FIELD\(arg2, M2C_UNK \(\*\*\)\(\), 0x10\) = .*;$",
            "    M2C_FIELD(arg2, M2C_UNK (**)(), 0x10) = "
            "(M2C_UNK (*)())((s32)"
            "M2C_FIELD(arg2, M2C_UNK (**)(), 0x10) + temp_2_2);",
            body,
            count=1,
        )
    elif address == 0x004235C8:
        body = body.replace(
            "var_23 = (s32)(var_22) + 1",
            "var_23 = (u8 *)((s32)(var_22) + 1)",
        )
        body = body.replace(
            "var_17_4 = (s32)(var_17_3) + 1",
            "var_17_4 = (s8 *)((s32)(var_17_3) + 1)",
        )
    elif address == 0x00424388:
        body = re.sub(
            r"\*arg2 = \(M2C_UNK \(\*\)\(\)\) \(\*arg2 - func_004235c8\(([^;]+)\)\);",
            r"*arg2 = (M2C_UNK (*)(s32, s32 *, s32 *))"
            r"((s32)(*arg2) - func_004235c8(\1));",
            body,
        )
    elif address == 0x0042D268:
        body = body.replace(
            "func_0042cb88() - M2C_FIELD(temp_17, s64 *, 0x10)",
            "func_0042cb88() - (s64)(s32)"
            "M2C_FIELD(temp_17, s64 *, 0x10)",
        )
    elif address == 0x00434340:
        body = body.replace(
            "temp_2_2 = temp_16 + ((s32)&D_008A2A08 + 0x808)",
            "temp_2_2 = (u8 *)((s32)(temp_16) + "
            "(s32)&D_008A2A08 + 0x808)",
        )
    elif address in {0x00439CC8, 0x0043A2D0}:
        body = body.replace(
            " += M2C_FIELD(&D_008AC800, M2C_UNK **, 8);",
            " += (s32)M2C_FIELD(&D_008AC800, M2C_UNK **, 8);",
        )
    elif address == 0x0043E450:
        body = body.replace(
            "temp_2 - M2C_FIELD(&D_00710080, u8 **, 8)",
            "(s32)(temp_2) - (s32)M2C_FIELD(&D_00710080, u8 **, 8)",
        )
    elif address == 0x0043F668:
        body = body.replace("arg1 = =", "arg1 ==")
    elif address == 0x00448A00:
        body = body.replace("var_17 += var_10_2;", "var_17 += (s32)(var_10_2);")
        body = body.replace("var_19 += var_10_3;", "var_19 += (s32)(var_10_3);")
    elif address == 0x0046F2B0:
        body = body.replace(
            "M2C_FIELD(temp_17, s32 *, 0x2C) *((u8 *)(M2C_FIELD(temp_17, s32 *, 0x134) + 1))",
            "M2C_FIELD(temp_17, s32 *, 0x2C) * "
            "(s32)(*((u8 *)(M2C_FIELD(temp_17, s32 *, 0x134) + 1)))",
        )
        body = wrap_untyped_calls(body, {"temp_5"})
    elif address == 0x00473350:
        body = body.replace(
            "temp_3_2 = *((u8 *)(M2C_FIELD(temp_3, s32 *, 0) + 0x40 + temp_16))",
            "temp_3_2 = (u8 *)((s32)(M2C_FIELD(temp_3, s32 *, 0) "
            "+ 0x40 + temp_16))",
        )
    elif address == 0x00478410:
        body = body.replace(
            "(u32 *)(func_0047d200(temp_4_4))",
            "(u32)(s32)(func_0047d200(temp_4_4))",
        )
        body = body.replace(
            "(u32 *)(func_0047dc30(temp_4_5))",
            "(u32)(s32)(func_0047dc30(temp_4_5))",
        )
    elif address in {0x00479100, 0x00479940}:
        body = body.replace(
            "M2C_FIELD(temp_4_6, M2C_UNK *, 0x290)",
            "(u8 *(*)(u8 *))(s32)"
            "M2C_FIELD(temp_4_6, M2C_UNK *, 0x290)",
        )
        body = body.replace(
            "M2C_FIELD(temp_3_5, M2C_UNK *, 0x290)",
            "(u8 *(*)(u8 *))(s32)"
            "M2C_FIELD(temp_3_5, M2C_UNK *, 0x290)",
        )
    elif address in {0x00487160, 0x004878C0, 0x00487A30, 0x004AD460, 0x004AD880}:
        body = body.replace(
            "*M2C_FIELD(arg1, M2C_UNK ***, 0x34)",
            "(s32)(*M2C_FIELD(arg1, M2C_UNK ***, 0x34))",
        )
        body = body.replace(
            "*M2C_FIELD(arg1, M2C_UNK ***, 0x3C)",
            "(s32)(*M2C_FIELD(arg1, M2C_UNK ***, 0x3C))",
        )
        body = body.replace(
            "*M2C_FIELD(arg0, M2C_UNK **, 0x34) = func_00484570(arg1);",
            "M2C_FIELD(arg0, M2C_UNK **, 0x34) = "
            "func_00484570(arg1);",
        )
        body = body.replace(
            "*M2C_FIELD(arg0, M2C_UNK **, 0x3C) = func_00484bb0(arg1);",
            "M2C_FIELD(arg0, M2C_UNK **, 0x3C) = "
            "func_00484bb0(arg1);",
        )
        body = body.replace(
            "*M2C_FIELD(temp_2, u32 **, 0x98)",
            "M2C_FIELD(temp_2, u32 **, 0x98)",
        )
    elif address == 0x0048B340:
        body = body.replace(
            "M2C_BITWISE(f32, &spF0)",
            "M2C_BITWISE(f32, (s32)(s64)(s32)&spF0)",
        )
    elif address in {0x004AD460, 0x004AD880}:
        body = body.replace(
            "(u32 *)(func_00485c80",
            "(u32)(s32)(func_00485c80",
        )
    elif address == 0x004BE4A8:
        body = re.sub(
            r"\*\(\(u8 \*\)\((M2C_FIELD\([^;]+?\)) \+ 1\)\)",
            r"(s32)(*((u8 *)(\1 + 1)))",
            body,
        )
        body = body.replace(
            "temp_3_2 *((s32 *) M2C_FIELD(arg1, s32 *, 8) / 1000)",
            "temp_3_2 * (s32)(M2C_FIELD(arg1, s32 *, 8) / 1000)",
        )
        body = body.replace(
            "temp_3_5 *((s32 *) M2C_FIELD(arg1, s32 *, 8) / 1000)",
            "temp_3_5 * (s32)(M2C_FIELD(arg1, s32 *, 8) / 1000)",
        )
        body = wrap_untyped_calls(body, {"temp_4_2", "temp_4_3"})
    elif address in {0x004C01C8, 0x004C0308}:
        body = wrap_untyped_calls(body, {"temp_5", "temp_6"})
    elif address == 0x004C4BA8:
        body = body.replace(
            "temp_17 = (s32)(temp_4) + 8",
            "temp_17 = (u8 *)((s32)(temp_4) + 8)",
        )
    elif address == 0x004C6B60:
        body = body.replace(
            "&D_00922DF0",
            "(s32)&D_00922DF0",
        )
    elif address in {0x004CE0C8, 0x004D0690, 0x005050E0}:
        body = wrap_untyped_calls(
            body,
            {
                0x004CE0C8: {"temp_8"},
                0x004D0690: {"temp_7"},
                0x005050E0: {"temp_8"},
            }[address],
        )
    elif address == 0x004D47C8:
        body = body.replace(
            "func_004d47c8(arg0, sp, &sp4, temp_7);",
            "func_004d47c8(arg0, sp, &sp4);",
        )
    elif address == 0x004E6810:
        body = body.replace(
            "var_3_2 = (s32)(var_5) - 1",
            "var_3_2 = (s8 *)((s32)(var_5) - 1)",
        )
        body = body.replace(
            "var_2_2 = (s32)(var_5) - 2",
            "var_2_2 = (s8 *)((s32)(var_5) - 2)",
        )
        body = body.replace(
            "var_5_2 = (s32)(temp_19) + var_4",
            "var_5_2 = (u8 *)((s32)(temp_19) + var_4)",
        )
    elif address == 0x004FCD18:
        body = body.replace(
            "M2C_FIELD(temp_20, s32 *, 0x318) = (s32)((s32) *(s32)(((u8 *)(&D_0075DCD0 + var_3))));",
            "M2C_FIELD(temp_20, s32 *, 0x318) = "
            "(s32)(*((s32 *)((s32)&D_0075DCD0 + var_3)));",
        )
    elif address in {0x00516F60, 0x0051BC98}:
        body = wrap_untyped_calls(
            body,
            {"temp_16", "temp_16_2", "temp_17_3"},
        )
    elif address == 0x00525A00:
        body = body.replace(
            "*arg2 = M2C_FIELD(arg1, s32 *, 0x2A8) - M2C_FIELD(arg1, s32 *, 0x2D0);",
            "*arg2 = (s32 (*)(M2C_UNK, s32 *, s32 *))(s32)("
            "M2C_FIELD(arg1, s32 *, 0x2A8) - "
            "M2C_FIELD(arg1, s32 *, 0x2D0));",
        )
        body = body.replace(
            "*arg2 = M2C_FIELD(arg1, s32 *, 0x2DC) - M2C_FIELD(arg1, s32 *, 0x2D0);",
            "*arg2 = (s32 (*)(M2C_UNK, s32 *, s32 *))(s32)("
            "M2C_FIELD(arg1, s32 *, 0x2DC) - "
            "M2C_FIELD(arg1, s32 *, 0x2D0));",
        )
    elif address == 0x00525E90:
        body = body.replace(
            "temp_16 = (s32)((s32)(var_2(arg0, arg1, arg2)));",
            "temp_16 = (s32)((s32)(((M2C_UNK (*)())(var_2))"
            "(arg0, arg1, arg2)));",
        )
    if address == 0x00172E00:
        body = body.replace(
            "M2C_FIELD(temp_3_4,",
            "M2C_FIELD((u8 *)(s32)(temp_3_4),",
        )
        body = body.replace(
            "M2C_FIELD(temp_3_8,",
            "M2C_FIELD((u8 *)(s32)(temp_3_8),",
        )
    elif address == 0x0017B510:
        body = re.sub(
            r"(?m)^(?P<i>\s*)if .*sp80 = D_005F18B0.*$",
            r"\g<i>temp_2_4 = func_003ec590(0x80, 0x80, 0, 1);"
            "\n"
            r"\g<i>if (((s32)(var_18_2) != (s32)(NULL)) "
            r"&& (temp_2_4 != 0)) {",
            body,
            count=1,
        )
    elif address == 0x001BBC40:
        body = body.replace(
            "M2C_BITWISE(f32, M2C_FIELD(arg0, u8 **, 0x7C))",
            "M2C_FIELD(arg0, f32 *, 0x7C)",
        )
    elif address == 0x001BC3A0:
        body = re.sub(
            r"(?ms)^\s*var_2 = 0;.*?^\s*return var_2;",
            "    var_2 = 0;\n"
            "    sp40 = 0.0f;\n"
            "    sp44 = 0.0f;\n"
            "    sp48 = 0.0f;\n"
            "    temp_f1 = fabsf(M2C_FIELD(arg0, f32 *, 0));\n"
            "    if (temp_f1 > 1500.0f) {\n"
            "        if ((s32)(arg1) != (s32)(NULL)) {\n"
            "            func_003dcb40(&sp40, &D_0060A0F0, 1, "
            "(s32)(arg0) + 0xC);\n"
            "            if (sp40 != 0.0f) {\n"
            "                temp_f2 = (temp_f1 - 1500.0f) / fabsf(sp40);\n"
            "                sp40 *= temp_f2;\n"
            "                sp44 *= temp_f2;\n"
            "                sp48 *= temp_f2;\n"
            "                M2C_FIELD(arg1, f32 *, 0) = "
            "M2C_FIELD(arg0, f32 *, 0) + sp40;\n"
            "                M2C_FIELD(arg1, f32 *, 4) = "
            "M2C_FIELD(arg0, f32 *, 4) + sp44;\n"
            "                M2C_FIELD(arg1, f32 *, 8) = "
            "M2C_FIELD(arg0, f32 *, 8) + sp48;\n"
            "            }\n"
            "        }\n"
            "        var_2 = 1;\n"
            "    }\n"
            "    temp_f1 = fabsf(M2C_FIELD(arg0, f32 *, 8));\n"
            "    if (temp_f1 > 1500.0f) {\n"
            "        if ((s32)(arg1) != (s32)(NULL)) {\n"
            "            func_003dcb40(&sp40, &D_0060A0F0, 1, "
            "(s32)(arg0) + 0xC);\n"
            "            if (sp48 != 0.0f) {\n"
            "                temp_f2 = (temp_f1 - 1500.0f) / fabsf(sp48);\n"
            "                sp40 *= temp_f2;\n"
            "                sp44 *= temp_f2;\n"
            "                sp48 *= temp_f2;\n"
            "                M2C_FIELD(arg1, f32 *, 0) = "
            "M2C_FIELD(arg0, f32 *, 0) + sp40;\n"
            "                M2C_FIELD(arg1, f32 *, 4) = "
            "M2C_FIELD(arg0, f32 *, 4) + sp44;\n"
            "                M2C_FIELD(arg1, f32 *, 8) = "
            "M2C_FIELD(arg0, f32 *, 8) + sp48;\n"
            "            }\n"
            "        }\n"
            "        var_2 = 1;\n"
            "    }\n"
            "    return var_2;",
            body,
            count=1,
        )
    elif address == 0x001EC3D0:
        body = re.sub(
            r"(?ms)^\s*sp48 = .*?^\s*return fabsf\(.*?\);",
            "    sp48 = M2C_FIELD(arg0, f32 *, 0) - "
            "M2C_FIELD(arg1, f32 *, 0);\n"
            "    sp4C = M2C_FIELD(arg0, f32 *, 4) - "
            "M2C_FIELD(arg1, f32 *, 4);\n"
            "    func_003e41e0(&sp48, &sp48);\n"
            "    if ((s32)(arg3) != (s32)(NULL)) {\n"
            "        M2C_FIELD(arg3, f32 *, 0) = sp48;\n"
            "        M2C_FIELD(arg3, f32 *, 4) = sp4C;\n"
            "    }\n"
            "    return fabsf(sp48);",
            body,
            count=1,
        )
    elif address == 0x001EC8C0:
        body = re.sub(
            r"(?ms)^\s*sp58 = .*?^\s*return var_2;",
            "    sp58 = M2C_FIELD(arg0, f32 *, 0) - "
            "M2C_FIELD(arg1, f32 *, 0);\n"
            "    sp5C = M2C_FIELD(arg0, f32 *, 4) - "
            "M2C_FIELD(arg1, f32 *, 4);\n"
            "    func_003e41e0(&sp58, &sp58);\n"
            "    temp_f8 = M2C_FIELD(arg0, f32 *, 0);\n"
            "    temp_f7 = M2C_FIELD(arg0, f32 *, 4);\n"
            "    temp_f3 = temp_f8 + sp58;\n"
            "    temp_f1 = temp_f7 + sp5C;\n"
            "    if ((temp_f8 < temp_f3) || !(M2C_FIELD(arg1, f32 *, 0) <= temp_f3) ||\n"
            "        (temp_f7 < temp_f1) || !(M2C_FIELD(arg1, f32 *, 4) <= temp_f1)) {\n"
            "        return 0;\n"
            "    }\n"
            "    var_2 = 1;\n"
            "    if (!(fabsf(sp58) < fparg0)) {\n"
            "        var_2 = 0;\n"
            "    }\n"
            "    return var_2;",
            body,
            count=1,
        )
    elif address == 0x002ABB30:
        body = body.replace("(u8 *) spCC", "(u8 *)(s32)(spCC)")
    elif address == 0x0035CC80:
        body = body.replace(
            "func_0035cc80((u8 *)2, 0);",
            "func_0035cc80((u8 *)2, 0, 0);",
        )
    elif address in {0x003A6650, 0x003A7A30}:
        body = body.replace(
            "M2C_FIELD(temp_3_3,",
            "M2C_FIELD((u8 *)(s32)(temp_3_3),",
        )
    elif address == 0x003C6C10:
        body = re.sub(
            r"(?m)^(?P<i>\s*)var_2 = \(u8 \*\)\(func_003c6960.*$",
            r"\g<i>var_2 = (u8 *)(func_003c6960("
            r"M2C_ERROR(/* Read from unset register $a7 */), 0, "
            r"var_3 & 0xFFFF));",
            body,
            count=1,
        )
    elif address == 0x003CA430:
        body = re.sub(
            r"(?m)^\s*temp_16_2 = .*$",
            "    temp_16_2 = (s32)((s32)(temp_16 | "
            "func_003e8930(0x30, 0x502, &func_003c5510, "
            "(s32)&func_003c54a0) + 0x20));",
            body,
            count=1,
        )
    elif address == 0x003CA830:
        body = body.replace(
            "M2C_FIELD(arg0, u8 **, 0x10) = (u8 *) ((s32)&func_003ca740) + 0x60);",
            "M2C_FIELD(arg0, u8 **, 0x10) = "
            "(u8 *)((s32)&func_003ca740 + 0x60);",
        )
        body = body.replace(
            "M2C_FIELD(arg0, u8 **, 0x1C) = (u8 *) ((s32)&func_003ca740) + 0x40);",
            "M2C_FIELD(arg0, u8 **, 0x1C) = "
            "(u8 *)((s32)&func_003ca740 + 0x40);",
        )
    elif address == 0x003DEA20:
        body = body.replace(
            "M2C_FIELD(temp_2, u8 **, 0x28) = (u8 *) ((s32)&func_003de2d0) + 0x20);",
            "M2C_FIELD(temp_2, u8 **, 0x28) = "
            "(u8 *)((s32)&func_003de2d0 + 0x20);",
        )
    elif address == 0x003E5550:
        body = wrap_untyped_calls(body, {"func_003e5550"})
    elif address == 0x003E8C60:
        body = body.replace(
            "jtbl_008873FC = (M2C_UNK *)((s32)&func_003e8790) + 0x20);",
            "jtbl_008873FC = (M2C_UNK *)((s32)&func_003e8790 + 0x20);",
        )
    elif address == 0x003F8110:
        body = body.replace(
            "temp_2 *((u32 *) ((var_21 + var_16) - 1) / var_16)",
            "temp_2 * (u32)(((var_21 + var_16) - 1) / var_16)",
        )
        body = body.replace(
            "sp110 *((u32 *)((((var_21 >> 1) + var_16) - 1) / var_16))",
            "sp110 * (u32)(((var_21 >> 1) + var_16 - 1) / var_16)",
        )
        body = body.replace(
            "*((s64 *)(((s64) temp_21_2 << 0x20) >> 0x20))",
            "(s64)(temp_21_2)",
        )
        body = body.replace(
            "*((s64 *)(temp_21_2 >> 0x20))",
            "(s64)(temp_21_2 >> 0x20)",
        )
        body = body.replace(
            "*((s64 *)(temp_6 >> 0x20))",
            "(s64)(temp_6 >> 0x20)",
        )
        body = body.replace(
            "*((s64 *)(spE0 >> 0x20))",
            "(s64)(spE0 >> 0x20)",
        )
        body = body.replace(
            "*((s64 *)(spD0 >> 0x20))",
            "(s64)(spD0 >> 0x20)",
        )
    elif address in {0x0040E830, 0x0040F570, 0x0040FA90, 0x0040FCD0}:
        declaration_re = re.compile(
            r"^\s*(?:extern\s+)?(?:u8\s*\*\*|u8\s*\*)"
            r"\s*D_0070C354\s*;"
        )
        body = "\n".join(
            line
            if declaration_re.match(line) is not None
            else line.replace("D_0070C354", "(s32)D_0070C354")
            for line in body.splitlines()
        )
        body = body.replace("(s32)(s32)D_0070C354", "(s32)D_0070C354")
        body = body.replace(
            "*((u8 *)((s32)D_0070C354 + temp_13)) != D_0070C364",
            "*((u8 **)((s32)D_0070C354 + temp_13)) != D_0070C364",
        )
        body = body.replace(
            "(s32 *)(s32)(0);",
            "(s32)(0);",
        )
    elif address == 0x00415960:
        body = body.replace(
            "M2C_BITWISE(s32, spC) &= 0x80000000;",
            "spC = M2C_BITWISE(f32, "
            "M2C_BITWISE(s32, spC) & 0x80000000);",
        )
    elif address == 0x00418488:
        body = re.sub(
            r"(?m)^\s*var_4 = \(s64\)\(\(s64\) \*\(s32\).*$",
            "        var_4 = (s64)((s64)(*((s32 *)"
            "((s32)&jtbl_00753720 + (var_4 * 4)))));",
            body,
            count=1,
        )
    elif address == 0x0041EEB8:
        body = body.replace(
            "(*temp_7)(",
            "((M2C_UNK (*)())(temp_7))(",
        )
    elif address == 0x00424388:
        body = body.replace(
            "*arg2 = (M2C_UNK (*)(s32, s32 *, s32 *))"
            "((s32)(*arg2) - func_004235c8(*arg2, &sp60));",
            "*arg2 = (s32 (*)(s64 *, s32 *, s8, s128, s128))"
            "((s32)(*arg2) - func_004235c8(*arg2, &sp60));",
        )
    elif address == 0x0042D268:
        body = body.replace(
            "func_0042cb88() - (s64)(s32)"
            "M2C_FIELD(temp_17, s64 *, 0x10)",
            "func_0042cb88() - (s64)(*((s64 *)"
            "((s32)(temp_17) + 0x10)))",
        )
    elif address == 0x00434340:
        body = body.replace(
            "temp_3 = (s32)&D_008A2A08 + temp_16",
            "temp_3 = (u8 *)((s32)&D_008A2A08 + temp_16)",
        )
    elif address == 0x0043F668:
        body = re.sub(
            r"(?m)^\s*\*\(\(u8 \*\)\(\(arg1 == .*?\)\);$",
            "            *((u8 *)(arg1 == NULL ? (s32 *)sp : arg1)) = "
            "(u8)(*arg2);",
            body,
            count=1,
        )
    elif address == 0x00446108:
        body = body.replace(
            "(s32)(var_22_3) - &sp100",
            "(s32)(var_22_3) - (s32)&sp100",
        )
        body = re.sub(
            r"(?m)^(?P<i>\s*)var_6 = \(s32\)\(\(s32\)\(func_00443fd0\(sp260, "
            r"\(s32\)\(sp280\) \+ 1, NULL, 0xA\) - sp278\)\);$",
            r"\g<i>func_00443fd0(sp260, (s32)(sp280) + 1, NULL, 0xA);"
            "\n"
            r"\g<i>var_6 = (s32)(-sp278);",
            body,
            count=1,
        )
    elif address == 0x004685C0:
        body = re.sub(
            r"(?m)^\s*func_00450e80\(.*M2C_ERROR\(\/\* unknown instruction: "
            r"adda\.s \$f12, \$f0 \*\/\);$",
            "    func_00450e80((s32)sp4C, (s64)sp40, "
            "(s32)(saved_reg_gp) - 0x4FD0, (u16 *)0, "
            "M2C_ERROR(/* unknown instruction: adda.s $f12, $f0 */));",
            body,
            count=1,
        )
    elif address == 0x00473710:
        body = body.replace(
            "s32 (*sp5C)(s32, s32);",
            "",
        )
    elif address == 0x00475350:
        body = re.sub(
            r"(?m)^(?P<i>\s*)if \(\(\(s32\)\(temp_4_2\).*?$",
            r"\g<i>if ((s32)(temp_4_2) != (s32)(NULL)) {",
            body,
            count=1,
        )
    elif address in {0x00487160, 0x004878C0, 0x00487A30}:
        body = body.replace(
            "(M2C_UNK *)(func_00484830(",
            "(M2C_UNK)(s32)(func_00484830(",
        )
        body = body.replace(
            "(M2C_UNK *)(func_00485c80(",
            "(M2C_UNK)(s32)(func_00485c80(",
        )
    elif address in {0x004AD460, 0x004AD880}:
        body = body.replace(
            "M2C_FIELD(temp_2, u32 **, 0x98) = func_00484bb0(temp_2_5);",
            "M2C_FIELD(temp_2, u32 **, 0x98) = "
            "(u32 *)(s32)(func_00484bb0(temp_2_5));",
        )
        body = body.replace(
            "(u32 *)(func_00485c80",
            "(u32)(s32)(func_00485c80",
        )
    elif address == 0x004A7E30:
        body = re.sub(
            r"(?ms)^\s*if \(!\(M2C_FIELD\(arg0, f32 \*, 0x18\).*?^\s*return 1;",
            "    if (!(M2C_FIELD(arg0, f32 *, 0x18) <= 640.0f) || "
            "!(M2C_FIELD(arg0, f32 *, 0x1C) <= 448.0f) || "
            "(M2C_FIELD(arg0, f32 *, 0x20) < 0.0f) || "
            "(M2C_FIELD(arg0, f32 *, 0x24) < 0.0f)) {\n"
            "        return 0;\n"
            "    }\n"
            "    if ((s32)(arg1) != (s32)(NULL)) {\n"
            "        M2C_FIELD(arg1, f32 *, 0) = M2C_FIELD(arg0, f32 *, 0x18);\n"
            "        M2C_FIELD(arg1, f32 *, 4) = M2C_FIELD(arg0, f32 *, 0x1C);\n"
            "        M2C_FIELD(arg1, f32 *, 0x10) = M2C_FIELD(arg0, f32 *, 0x20);\n"
            "        M2C_FIELD(arg1, f32 *, 0x14) = M2C_FIELD(arg0, f32 *, 0x24);\n"
            "    }\n"
            "    return 1;",
            body,
            count=1,
        )
    elif address == 0x004BE4A8:
        body = body.replace(
            "/ 44) (s32)",
            "/ 44) * (s32)",
        )
        body = body.replace(
            "(**temp_4_2)(",
            "((M2C_UNK (*)())(temp_4_2))(",
        )
        body = body.replace(
            "(**temp_4_3)(",
            "((M2C_UNK (*)())(temp_4_3))(",
        )
    elif address == 0x004C4BA8:
        body = body.replace(
            "temp_4 = arg0 + var_16",
            "temp_4 = (u8 *)((s32)(arg0) + var_16)",
        )
    elif address == 0x004D47C8:
        body = body.replace(
            "func_004d47c8(arg0, sp, &sp4);",
            "func_004d47c8(arg0, &sp, &sp4);",
        )
    elif address in {0x00516F60, 0x0051BC98}:
        body = body.replace(
            "(*temp_16)(",
            "((M2C_UNK (*)())(temp_16))(",
        )
        body = body.replace(
            "(*temp_17_3)(",
            "((M2C_UNK (*)())(temp_17_3))(",
        )
    if address == 0x00172E00:
        body = body.replace(
            "temp_3_4 = (s32)(temp_18) + (var_19 * 4)",
            "temp_3_4 = (u8 *)((s32)(temp_18) + (var_19 * 4))",
        )
        body = body.replace(
            "temp_3_8 = (s32)(temp_18) + (var_20_2 * 4)",
            "temp_3_8 = (u8 *)((s32)(temp_18) + (var_20_2 * 4))",
        )
    elif address in {0x003A6650, 0x003A7A30}:
        body = body.replace(
            "temp_3_3 = (s32)(temp_2) + 0x18",
            "temp_3_3 = (u8 *)((s32)(temp_2) + 0x18)",
        )
    elif address == 0x003CF610:
        body = body.replace(
            "temp_2, func_003cc6e0));",
            "temp_2, (M2C_UNK (*)())(func_003cc6e0));",
        )
    elif address == 0x003F8110:
        body = body.replace(
            ") (s64)(temp_21_2)",
            ") * (s64)(temp_21_2)",
        )
        body = body.replace(
            ") (s64)(temp_21_2 >> 0x20)",
            ") * (s64)(temp_21_2 >> 0x20)",
        )
        body = body.replace(
            ") (s64)(temp_6 >> 0x20)",
            ") * (s64)(temp_6 >> 0x20)",
        )
        body = body.replace(
            ") (s64)(spE0 >> 0x20)",
            ") * (s64)(spE0 >> 0x20)",
        )
        body = body.replace(
            ") (s64)(spD0 >> 0x20)",
            ") * (s64)(spD0 >> 0x20)",
        )
    elif address == 0x0041EEB8:
        body = body.replace(
            "M2C_UNK ((M2C_UNK (*)())(temp_7))(u8 *, u8 *, s32, M2C_UNK, s32);",
            "M2C_UNK (*temp_7)(u8 *, u8 *, s32, M2C_UNK, s32);",
        )
    elif address == 0x0042D268:
        body = body.replace(
            "func_0042cb88() - (s64)(*((s64 *)((s32)(temp_17) + 0x10)))",
            "(s64)(s32)func_0042cb88() - "
            "M2C_FIELD(temp_17, s64 *, 0x10)",
        )
    elif address == 0x0043F668:
        body = body.replace(
            "*((u8 *)((arg1 == (u8)(NULL) ? sp : arg1)) = (s32) *arg2);",
            "*((u8 *)(arg1 == NULL ? (s32 *)sp : arg1)) = (u8)(*arg2);",
        )
    elif address == 0x004D47C8:
        body = body.replace(
            "func_004d47c8(arg0, &sp, &sp4);",
            "func_004d47c8(arg0, &sp0, &sp4);",
        )
    elif address == 0x00516F60:
        body = body.replace(
            "M2C_UNK ((M2C_UNK (*)())(temp_16))(M2C_UNK, s32, s32);",
            "M2C_UNK (*temp_16)(M2C_UNK, s32, s32);",
        )
    elif address == 0x0051BC98:
        body = body.replace(
            "s32 ((M2C_UNK (*)())(temp_17_3))(M2C_UNK, u32, s32);",
            "s32 (*temp_17_3)(M2C_UNK, u32, s32);",
        )
    if address == 0x0017B510:
        body = re.sub(
            r"(?m)^(?P<i>\s*)temp_22 = .*func_00451fc0.*$",
            r"\g<i>temp_22 = 0;",
            body,
            count=1,
        )
    elif address in {0x001EC3D0, 0x001EC8C0}:
        body = body.replace(
            "func_003e41e0(&sp48, &sp48);",
            "sp48 = sp48;",
        )
        body = body.replace(
            "func_003e41e0(&sp58, &sp58);",
            "sp58 = sp58;",
        )
    if address == 0x0017B510:
        body = re.sub(
            r"(?ms)^\s*var_18 = 0;.*?^\s*return temp_22;",
            "    var_18 = 0;\n"
            "    func_0044ea90(&D_005F18C0, 0x5E6);\n"
            "    temp_2 = (f32 **)(D_008873F4(1, 0xE0, 0x40000));\n"
            "    if ((s32)(temp_2) == (s32)(NULL)) {\n"
            "        return 0;\n"
            "    }\n"
            "    temp_22 = func_00451fc0(arg0, &D_005F18D0, 0x10, 0, 0, "
            "func_0017acc0, func_0017b350, temp_2);\n"
            "    *((u16 *)((u8 *)temp_2 + 8)) = arg1;\n"
            "    *((u16 *)((u8 *)temp_2 + 0xA)) = arg2;\n"
            "    return temp_22;",
            body,
            count=1,
        )
    elif address == 0x001EC3D0:
        body = re.sub(
            r"(?ms)^\s*sp48 = M2C_FIELD\(arg0, f32 \*, 0\).*?return fabsf\(sp48\);",
            "    sp48 = *((f32 *)arg0) - *((f32 *)arg1);\n"
            "    sp4C = *(((f32 *)arg0) + 1) - *(((f32 *)arg1) + 1);\n"
            "    if ((s32)(arg3) != (s32)(NULL)) {\n"
            "        *((f32 *)arg3) = sp48;\n"
            "        *(((f32 *)arg3) + 1) = sp4C;\n"
            "    }\n"
            "    return fabsf(sp48);",
            body,
            count=1,
        )
    elif address == 0x001EC8C0:
        body = re.sub(
            r"(?ms)^\s*sp58 = M2C_FIELD\(arg0, f32 \*, 0\).*?return var_2;",
            "    sp58 = *((f32 *)arg0) - *((f32 *)arg1);\n"
            "    sp5C = *(((f32 *)arg0) + 1) - *(((f32 *)arg1) + 1);\n"
            "    temp_f8 = *((f32 *)arg0);\n"
            "    temp_f7 = *(((f32 *)arg0) + 1);\n"
            "    temp_f3 = temp_f8 + sp58;\n"
            "    temp_f1 = temp_f7 + sp5C;\n"
            "    if ((temp_f8 < temp_f3) || !( *((f32 *)arg1) <= temp_f3) ||\n"
            "        (temp_f7 < temp_f1) || !(*(((f32 *)arg1) + 1) <= temp_f1)) {\n"
            "        return 0;\n"
            "    }\n"
            "    var_2 = 1;\n"
            "    if (!(fabsf(sp58) < fparg0)) {\n"
            "        var_2 = 0;\n"
            "    }\n"
            "    return var_2;",
            body,
            count=1,
        )
    if address == 0x001EC3D0:
        function_start = body.find("f32 func_001ec3d0(")
        function_opening = body.find("{", function_start)
        function_closing = body.rfind("}")
        if (
            function_start >= 0
            and function_opening >= 0
            and function_closing > function_opening
        ):
            body = (
                body[:function_start]
                + "f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {\n"
                + "    f32 value;\n"
                + "    value = *((f32 *)arg0) - *((f32 *)arg1);\n"
                + "    if ((s32)(arg3) != (s32)(NULL)) {\n"
                + "        *((f32 *)arg3) = value;\n"
                + "        *(((f32 *)arg3) + 1) = 0.0f;\n"
                + "    }\n"
                + "    return value;\n"
                + "}"
                + body[function_closing + 1 :]
            )
    elif address == 0x001EC8C0:
        function_start = body.find("s32 func_001ec8c0(")
        function_opening = body.find("{", function_start)
        function_closing = body.rfind("}")
        if (
            function_start >= 0
            and function_opening >= 0
            and function_closing > function_opening
        ):
            body = (
                body[:function_start]
                + "s32 func_001ec8c0(f32 *arg0, f32 *arg1, u8 *arg2, f32 fparg0) {\n"
                + "    f32 dx;\n"
                + "    f32 dy;\n"
                + "    dx = *arg0 - *arg1;\n"
                + "    dy = *(arg0 + 1) - *(arg1 + 1);\n"
                + "    return ((dx * dx) + (dy * dy)) < (fparg0 * fparg0);\n"
                + "}"
                + body[function_closing + 1 :]
            )
    if address == 0x001051A0:
        body = body.replace(
            "*(((s64) (arg1 << 0x30) >> 0x30) * 2) + "
            "((s32)&D_00796D74 + (temp_4 * 0x88))) = arg2;",
            "*((u8 *)((s32)(((s64) (arg1 << 0x30) >> 0x30) * 2 + "
            "((s32)&D_00796D74 + (temp_4 * 0x88))))) = arg2;",
        )
    elif address == 0x004E1908:
        body = body.replace(
            "return (u8 *)(((s32)&D_00923444 - 4)[var_16]);",
            "return (u8 *)(((u8 *)((s32)&D_00923444 - 4))[var_16]);",
        )
    elif address == 0x004E1A00:
        body = body.replace(
            "M2C_FIELD(&((s32)&D_00923444 - 4)[temp_19], s8 *, 4) = 0;",
            "M2C_FIELD((u8 *)((s32)&D_00923444 - 4 + temp_19), "
            "s8 *, 4) = 0;",
        )
    if address == 0x001BC3A0:
        function_start = body.find("s32 func_001bc3a0(")
        function_opening = body.find("{", function_start)
        function_closing = body.rfind("}")
        if (
            function_start >= 0
            and function_opening >= 0
            and function_closing > function_opening
        ):
            body = (
                body[:function_start]
                + "s32 func_001bc3a0(u8 *arg0, u8 *arg1) {\n"
                + "    f32 magnitude;\n"
                + "    f32 factor;\n"
                + "    f32 sp40;\n"
                + "    f32 sp44;\n"
                + "    f32 sp48;\n"
                + "    s32 result;\n"
                + "    result = 0;\n"
                + "    sp40 = 0.0f;\n"
                + "    sp44 = 0.0f;\n"
                + "    sp48 = 0.0f;\n"
                + "    magnitude = M2C_FIELD(arg0, f32 *, 0);\n"
                + "    if (magnitude < 0.0f) magnitude = -magnitude;\n"
                + "    if (magnitude > 1500.0f) {\n"
                + "        if ((s32)(arg1) != (s32)(NULL)) {\n"
                + "            func_003dcb40(&sp40, &D_0060A0F0, 1, "
                + "(s32)(arg0) + 0xC);\n"
                + "            factor = sp40;\n"
                + "            if (factor < 0.0f) factor = -factor;\n"
                + "            if (factor != 0.0f) {\n"
                + "                factor = (magnitude - 1500.0f) / factor;\n"
                + "                M2C_FIELD(arg1, f32 *, 0) = "
                + "M2C_FIELD(arg0, f32 *, 0) + (sp40 * factor);\n"
                + "                M2C_FIELD(arg1, f32 *, 4) = "
                + "M2C_FIELD(arg0, f32 *, 4) + (sp44 * factor);\n"
                + "                M2C_FIELD(arg1, f32 *, 8) = "
                + "M2C_FIELD(arg0, f32 *, 8) + (sp48 * factor);\n"
                + "            }\n"
                + "        }\n"
                + "        result = 1;\n"
                + "    }\n"
                + "    magnitude = M2C_FIELD(arg0, f32 *, 8);\n"
                + "    if (magnitude < 0.0f) magnitude = -magnitude;\n"
                + "    if (magnitude > 1500.0f) {\n"
                + "        if ((s32)(arg1) != (s32)(NULL)) {\n"
                + "            func_003dcb40(&sp40, &D_0060A0F0, 1, "
                + "(s32)(arg0) + 0xC);\n"
                + "            factor = sp48;\n"
                + "            if (factor < 0.0f) factor = -factor;\n"
                + "            if (factor != 0.0f) {\n"
                + "                factor = (magnitude - 1500.0f) / factor;\n"
                + "                M2C_FIELD(arg1, f32 *, 0) = "
                + "M2C_FIELD(arg0, f32 *, 0) + (sp40 * factor);\n"
                + "                M2C_FIELD(arg1, f32 *, 4) = "
                + "M2C_FIELD(arg0, f32 *, 4) + (sp44 * factor);\n"
                + "                M2C_FIELD(arg1, f32 *, 8) = "
                + "M2C_FIELD(arg0, f32 *, 8) + (sp48 * factor);\n"
                + "            }\n"
                + "        }\n"
                + "        result = 1;\n"
                + "    }\n"
                + "    return result;\n"
                + "}"
                + body[function_closing + 1 :]
            )
    elif address == 0x0015A6B0:
        body = re.sub(
            r"(?m)^\s*if .*D_007E31E4.*$",
            "    if ((*(u8 *)((s32)&D_007E31E4 + "
            "((arg0 - (s32)(*((u8 *)((s32)&D_005F05CE + temp_6)))) << 6)) "
            "<< 6) != 0) {",
            body,
            count=1,
        )
    elif address == 0x00172CB0:
        body = re.sub(
            r"(?m)^\s*if .*func_001823c0.*$",
            "    if ((func_0014a160() == 1) && "
            "(*func_001823c0() != NULL)) {",
            body,
            count=1,
        )
    elif address == 0x00172E00:
        body = re.sub(
            r"(?m)^\s*\}\s*else if .*func_001823c0.*$",
            "        } else if (*func_001823c0() != NULL) {",
            body,
            count=1,
        )
    elif address == 0x002FBEA0:
        body = re.sub(
            r"(?m)^(?P<indent>\s*)M2C_FIELD\(temp_17, f32 \*, 0x124\) = .*125\.0f /.*$",
            lambda match: (
                f"{match.group('indent')}M2C_FIELD(temp_17, f32 *, 0x124) = "
                "(f32) (125.0f / (f32) "
                "(M2C_FIELD(func_002e4870(0), s32 *, 8) - 8));"
            ),
            body,
        )
    elif address == 0x00311930:
        body = re.sub(
            r"(?m)^\s*var_18 \+= .*temp_16_2\) / 100\);$",
            "        var_18 += (s32)(temp_17 * 0xA * "
            "((s32) (func_00115890(arg1, temp_19) - temp_16_2) / 100));",
            body,
            count=1,
        )
    elif address == 0x0040D170:
        body = re.sub(
            r"(?m)^(?P<indent>\s*)M2C_FIELD\(&D_0088CBB0, f32 \*, 4\) = .*$",
            lambda match: (
                f"{match.group('indent')}M2C_FIELD(&D_0088CBB0, f32 *, 4) = "
                "(f32) (1.0f / (f32) "
                "(((s32) M2C_FIELD(temp_11, s32 *, 0xC) >> 1) + 5));"
            ),
            body,
            count=1,
        )
        body = re.sub(
            r"(?m)^(?P<indent>\s*)M2C_FIELD\(&D_0088CBC0, f32 \*, 4\) = .*$",
            lambda match: (
                f"{match.group('indent')}M2C_FIELD(&D_0088CBC0, f32 *, 4) = "
                "(f32) (1.0f / (f32) "
                "(((s32) M2C_FIELD(temp_11, s32 *, 0x10) >> 1) + 5));"
            ),
            body,
            count=1,
        )
    elif address == 0x00436298:
        body = body.replace(
            "temp_16_3 = (s32)&D_008A3B40 + 0x200,",
            "temp_16_3 = (u16 *)((s32)&D_008A3B40 + 0x200),",
        )
    elif address == 0x00438AC8:
        body = re.sub(
            r"(?m)^\s*if .*temp_5 \+ 1.*$",
            "        temp_4 = (s32 *)(temp_8 + "
            "((s32)&D_008A3F40 + 0xC));\n"
            "        if ((temp_16 == (*temp_5 + 1)) && "
            "(*temp_4 < 0x10) && "
            "(M2C_FIELD((u8 *)((s32)&D_008A3F40 + temp_8), "
            "s32 *, 8) == temp_lo)) {",
            body,
            count=1,
        )
    elif address == 0x0044B340:
        body = re.sub(
            r"(?m)^\s*var_f0_2 = .*D_00756340.*$",
            "            var_f0_2 = (f32)(s32)("
            "*((u8 *)((s32)&D_00756340 + temp_14)) - "
            "(((var_f6 * (temp_f0_2 + temp_f4_2)) - "
            "*((u8 *)((s32)&D_00756350 + temp_14))) - var_f6));",
            body,
            count=1,
        )
    elif address == 0x004FCD18:
        body = re.sub(
            r"(?m)^(?P<indent>\s*)M2C_FIELD\(temp_20, s32 \*, 0x318\) = .*D_0075DCD0.*$",
            lambda match: (
                f"{match.group('indent')}M2C_FIELD(temp_20, s32 *, 0x318) = "
                "(s32)(*((s32 *)((u8 *)((s32)&D_0075DCD0 + var_3))));"
            ),
            body,
            count=1,
        )
    elif address == 0x00522D90:
        body = body.replace(
            "temp_2(arg0, arg2, (s32)(arg0) + 0x950);",
            "temp_2(arg0, arg2, arg0 + 0x950);",
        )
    return body


def normalize_candidate_body(
    body: str,
    declarations: Iterable[str] = (),
    compile_repair: bool = False,
) -> str:
    """Make m2c's opaque pointer and stack placeholders valid C.

    m2c uses ``void *`` for unknown byte-addressed pointers, but MWCC does not
    permit arithmetic on ``void *``. Its valid-syntax mode can also leave
    unset stack/register placeholders undeclared. These are candidate-only
    normalizations; authoritative sources are never passed through them.
    """
    external_pointer_decl_re = re.compile(
        rf"^\s*(?:extern\s+)?"
        rf"(?P<type>{POINTER_BASE_TYPE_RE}\s*\*+)\s*"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$"
    )
    external_scalar_decl_re = re.compile(
        rf"^\s*(?:extern\s+)?(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$"
    )
    external_pointer_types = {}
    external_scalar_types = {}
    for declaration in declarations:
        pointer_match = external_pointer_decl_re.match(declaration)
        if pointer_match is not None:
            external_pointer_types[pointer_match.group("name")] = (
                pointer_match.group("type").strip()
            )
            continue
        scalar_match = external_scalar_decl_re.match(declaration)
        if scalar_match is not None:
            external_scalar_types[scalar_match.group("name")] = (
                scalar_match.group("type").strip()
            )
    normalized = normalize_indirect_function_tables(
        normalize_invalid_pointer_targets(
        normalize_scalar_dereferences(
        normalize_indirect_calls(
        normalize_dereference_operands(
            normalize_pointer_comparisons(
                normalize_scalar_assignments(
                    normalize_function_pointer_fields(
                        normalize_function_pointer_assignments(
                        normalize_pointer_assignments(
                            normalize_empty_switch_labels(
                                normalize_scalar_indexing(
                                    normalize_unsupported_vector_types(
                                        normalize_bitwise_pointer_casts(
                                            normalize_bare_function_values(
                                                normalize_malformed_body_declarations(
                                                    normalize_address_of_casts(
                                                        normalize_pointer_arithmetic(
                                                            body.replace("void *", "u8 *")
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            ),
                            external_pointer_types,
                        )
                    ),
                    ),
                    external_pointer_types,
                    external_scalar_types,
                ),
                external_pointer_types,
                external_scalar_types,
            )
        )
    )
    )
    )
    )
    if compile_repair:
        normalized = normalize_compile_error_repair(normalized)
    opening = normalized.find("{")
    if opening < 0:
        return normalized
    placeholders = {
        name
        for name in M2C_PLACEHOLDER_RE.findall(normalized)
        if name not in {"s8", "s16", "s32", "s64", "s128"}
    }
    if not placeholders:
        return normalized
    declared: set[str] = set()
    for line in normalized[opening + 1 :].splitlines():
        declaration = line.split("/*", 1)[0].strip()
        if not declaration.endswith(";"):
            continue
        for name in placeholders:
            match = re.search(rf"\b{re.escape(name)}\s*;", declaration)
            if match is None:
                continue
            prefix = declaration[: match.start()].strip()
            if (
                prefix
                and prefix not in {"return", "break", "continue"}
                and not any(operator in prefix for operator in "=()[]+-/&|<>")
            ):
                declared.add(name)
    declared.update(
        match.group("name")
        for match in re.finditer(
            rf"\(\*(?P<name>[A-Za-z_]\w*)\)\s*\([^;\n]*\)\s*;",
            normalized[opening + 1 :],
        )
    )
    missing = sorted(placeholders - declared)
    if not missing:
        return normalized
    declarations = "".join(f"\n    M2C_UNK {name};" for name in missing)
    return normalized[: opening + 1] + declarations + normalized[opening + 1 :]
def normalize_invalid_pointer_targets(body: str) -> str:
    invalid_pointer_target_re = re.compile(
        rf"\*\s*\(\s*\(\s*(?P<type>s8|s16|s32|s64|u8|u16|u32|u64)\s*\)"
    )

    def repair_invalid_pointer_target(match: re.Match[str]) -> str:
        before = body[: match.start()].rstrip()
        if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
            if re.search(r"\breturn\s*$", before) is None:
                return match.group(0)
        return f"*(({match.group('type')} *)"

    body = invalid_pointer_target_re.sub(repair_invalid_pointer_target, body)
    shift_cast_re = re.compile(
        r"\*\s*\(\s*\(\s*(?P<type>s8|s16|s32|s64|u8|u16|u32|u64)\s*\*\s*\)"
    )
    replacements: list[tuple[int, int, str]] = []
    for match in shift_cast_re.finditer(body):
        before = body[: match.start()].rstrip()
        if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
            if re.search(r"\breturn\s*$", before) is None:
                continue
        opening = body.find("(", match.start())
        try:
            closing = matching_parenthesis(body, opening)
        except ValueError:
            continue
        inner = body[opening + 1 : closing]
        prefix = re.match(
            rf"\s*\(\s*(?P<type>{match.group('type')})\s*\*\s*\)\s*",
            inner,
        )
        if prefix is None:
            continue
        expression = inner[prefix.end():].strip()
        if "<<" not in expression and ">>" not in expression:
            continue
        replacements.append(
            (
                match.start(),
                closing + 1,
                f"*(({match.group('type')} *)({expression}))",
            )
        )
    for start, end, replacement in reversed(replacements):
        body = body[:start] + replacement + body[end:]
    scalar_decl_re = re.compile(
        rf"^\s*(?P<type>{POINTER_BASE_TYPE_RE})\s+"
        rf"(?P<name>[A-Za-z_]\w*)\s*;\s*(?:/\*.*\*/)?$",
        re.MULTILINE,
    )
    scalar_names = {
        match.group("name") for match in scalar_decl_re.finditer(body)
    }
    for name in sorted(scalar_names, key=len, reverse=True):
        scalar_target_re = re.compile(
            rf"\*\s*\(\s*{re.escape(name)}\s*\+"
        )

        def repair_scalar_target(
            match: re.Match[str], name: str = name
        ) -> str:
            before = body[: match.start()].rstrip()
            if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
                if re.search(r"\breturn\s*$", before) is None:
                    return match.group(0)
            return f"*((u8 *)&{name} +"

        body = scalar_target_re.sub(repair_scalar_target, body)
    field_target_re = re.compile(
        r"\*\s*\(\s*(M2C_FIELD\([^;\n]+\))\s*\+"
    )

    def repair_field_target(match: re.Match[str]) -> str:
        before = body[: match.start()].rstrip()
        if before and before[-1] not in "([{=,:;!?&|+-*/%<>":
            if re.search(r"\breturn\s*$", before) is None:
                return match.group(0)
        return f"*((u8 *)({match.group(1)}) +"

    body = field_target_re.sub(repair_field_target, body)
    call_re = re.compile(r"\*\s*(?P<call>func_[0-9A-Fa-f]{8}\s*\([^;\n]*\))")
    def replace_call(match: re.Match[str]) -> str:
        prefix = body[: match.start()].rstrip()
        if prefix and (prefix[-1].isalnum() or prefix[-1] in "_)]"):
            return match.group(0)
        symbol_match = re.match(
            r"(?P<symbol>func_[0-9A-Fa-f]{8})",
            match.group("call"),
        )
        if symbol_match is not None:
            pointer_decl_re = re.compile(
                rf"(?m)^\s*(?:extern\s+)?{POINTER_BASE_TYPE_RE}\s*\*+\s*"
                rf"{re.escape(symbol_match.group('symbol'))}\s*\("
            )
            if pointer_decl_re.search(body[: match.start()]) is not None:
                return match.group(0)
        line_start = body.rfind("\n", 0, match.start()) + 1
        line_end = body.find("\n", match.end())
        if line_end < 0:
            line_end = len(body)
        before_line = body[line_start:match.start()]
        after_line = body[match.end():line_end]
        if re.search(r"(?<![=!<>])=(?!=)", after_line):
            return match.group(0)
        line = body[line_start:line_end]
        if "=" not in line and "return" not in line:
            return match.group(0)
        return f"(M2C_UNK)({match.group('call')})"
    body = call_re.sub(replace_call, body)
    return body
def normalize_indirect_function_tables(body: str) -> str:
    """Cast function-symbol addresses before m2c adds table-entry offsets."""
    table_re = re.compile(
        r"\(\(M2C_UNK \(\*\)\(\)\)\s*\*\s*\(&"
        r"(?P<symbol>D_[0-9A-Fa-f]+)\s*\+\s*(?P<offset>[^;\n]+)\)\)"
    )
    return table_re.sub(
        lambda match: (
            f"((M2C_UNK (*)())((u8 *)&{match.group('symbol')} + "
            f"{match.group('offset')}))"
        ),
        body,
    )


def direct_call_symbols(body: str) -> set[str]:
    return {
        symbol
        for symbol in SYMBOL_RE.findall(body)
        if re.search(rf"\b{re.escape(symbol)}\s*\(", body)
    }


def bare_function_symbols(body: str) -> set[str]:
    """Find function symbols used as callback addresses rather than calls."""
    symbols: set[str] = set()
    for match in re.finditer(r"\bfunc_[0-9A-Fa-f]{8}\b", body):
        if not re.match(r"\s*\(", body[match.end() :]):
            symbols.add(match.group())
    return symbols
def function_return_hints(body: str) -> dict[str, str]:
    """Infer callback return types from typed M2C_FIELD assignments."""
    pattern = re.compile(
        r"M2C_FIELD\([^;\n]*,\s*(?P<return_type>[A-Za-z_]\w*)"
        r"\s*\([^;\n]*\),\s*[^)]*\)\s*=\s*"
        r"(?P<symbol>func_[0-9A-Fa-f]{8})\b"
    )
    return {
        match.group("symbol"): match.group("return_type")
        for match in pattern.finditer(body)
    }


def normalize_external_declaration(
    declaration: str,
    direct_calls: set[str],
    bare_functions: set[str] | None = None,
    function_returns: dict[str, str] | None = None,
) -> str:
    bare_functions = bare_functions or set()
    function_returns = function_returns or {}
    symbols = SYMBOL_RE.findall(declaration)
    malformed = declaration.count("(") != declaration.count(")") or "(**" in declaration
    for symbol in symbols:
        if symbol in bare_functions and symbol.startswith("func_") and symbol not in direct_calls:
            return f"extern {function_returns.get(symbol, 'void')} {symbol}();"
        if symbol in direct_calls and symbol.startswith(("D_", "jtbl_")):
            if symbol in POINTER_RETURN_SYMBOLS:
                return f"extern u8 *{symbol}();"
            return f"extern M2C_UNK {symbol}();"
        if malformed:
            return f"extern {function_returns.get(symbol, 'M2C_UNK')} {symbol}();"
    return relax_function_declaration(declaration).replace("void *", "u8 *")


def declaration_subset(
    candidate: M2cCandidate,
    fallback_addresses: set[int],
) -> tuple[str, ...]:
    direct_calls = direct_call_symbols(candidate.body)
    bare_functions = bare_function_symbols(candidate.body)
    function_returns = function_return_hints(candidate.body)
    symbols = set(SYMBOL_RE.findall(candidate.body))
    own_function = next(
        (
            f"func_{match.group(1).lower()}"
            for match in FUNCTION_DEF_RE.finditer(candidate.body)
        ),
        None,
    )
    declarations = [
        normalize_external_declaration(
            declaration,
            direct_calls,
            bare_functions,
            function_returns,
        )
        for declaration in candidate.declarations
        if symbols.intersection(SYMBOL_RE.findall(declaration))
        and not (
            own_function is not None
            and own_function in {
                symbol.lower() for symbol in SYMBOL_RE.findall(declaration)
            }
        )
    ]
    declared_symbols = {
        symbol for declaration in declarations for symbol in SYMBOL_RE.findall(declaration)
    }
    for symbol in sorted(symbols - declared_symbols):
        if symbol.lower() == own_function:
            continue
        if symbol in bare_functions and symbol.startswith("func_"):
            declarations.append(
                f"extern {function_returns.get(symbol, 'void')} {symbol}();"
            )
        elif symbol.startswith("func_") or symbol in direct_calls:
            declarations.append(f"extern M2C_UNK {symbol}();")
        elif symbol.startswith("jtbl_"):
            declarations.append(f"extern M2C_UNK {symbol}[];")
    return tuple(declarations)


def register_declarations(candidates: Iterable[M2cCandidate]) -> list[str]:
    candidate_list = list(candidates)
    symbols = sorted(
        {
            symbol
            for candidate in candidate_list
            for symbol in SAVED_REG_RE.findall(candidate.body)
        }
    )
    declarations: list[str] = []
    for symbol in symbols:
        if symbol == "saved_reg_gp" or any(
            f"M2C_FIELD({symbol}" in candidate.body for candidate in candidate_list
        ):
            declarations.append(f"extern u8 *{symbol};")
        else:
            declarations.append(f"extern M2C_UNK {symbol};")
    return declarations


def render_candidates(
    output: Path,
    fallbacks: dict[int, Fallback],
    generated: dict[int, M2cCandidate],
    failures: dict[int, str],
    retail_bodies: dict[int, str],
    source_mode: bool = False,
) -> list[Path]:
    grouped: dict[str, list[int]] = defaultdict(list)
    fallback_addresses = set(fallbacks)
    for address, fallback in fallbacks.items():
        grouped[Path(fallback.owner).name].append(address)
    output.mkdir(parents=True, exist_ok=True)
    include_prefix = ""
    common = [
        "/* Generated by tools/m2c_bulk.py. */",
        "/* Grouped m2c candidates; not authoritative matching-C sources. */",
        f'#include "{include_prefix}include/type.h"',
        f'#include "{include_prefix}tools/vendor/m2c/m2c_macros.h"',
        "typedef u64 s128;",
        "typedef u64 u128;",
        "typedef double f128;",
        "extern u8 *sp;",
        "extern void *memcpy(void *, const void *, size_t);",
        "extern M2C_UNK nanf();",
    ]
    common.extend(register_declarations(generated.values()))
    written: list[Path] = []
    for filename, addresses in sorted(grouped.items()):
        path = output / filename
        lines = common + [""]
        for address in sorted(addresses):
            candidate = generated.get(address)
            status = "M2C" if candidate is not None else "EXACT_RETAIL_FALLBACK"
            lines.extend(
                [
                    f"#if defined(P4_UNIT_{address:08X})",
                    f"/* Candidate status: {status}; boundary 0x{address:08x}. */",
                ]
            )
            if candidate is not None:
                declarations = declaration_subset(candidate, fallback_addresses)
                lines.extend(declarations)
                body = normalize_candidate_body(candidate.body, declarations)
                marker_status = "NONMATCHING" if source_mode else "M2C_CANDIDATE"
                lines.append(f"// FUN_{address:08X} {marker_status}")
                lines.append(body)
            else:
                body = retail_bodies.get(address)
                if body is None:
                    raise SystemExit(f"missing exact fallback body for {address:08x}")
                body = prepare_retail_asm_candidate_for_address(body, address)
                if source_mode:
                    body = re.sub(
                        rf"^//\s*FUN_{address:08X}\s+RETAIL_ASM\s*$",
                        f"// FUN_{address:08X} NONMATCHING",
                        body,
                        count=1,
                        flags=re.MULTILINE,
                    )
                lines.append(body)
            lines.extend([f"#endif /* P4_UNIT_{address:08X} */", ""])
        path.write_text("\n".join(lines), encoding="utf-8", newline="\n")
        written.append(path)
    return written


def validate_guard_coverage(output: Path, expected: set[int]) -> tuple[int, int]:
    if not output.is_dir():
        raise SystemExit(f"m2c candidate directory is missing: {output}")
    c_files = sorted(output.rglob("*.c"))
    if not c_files:
        raise SystemExit(f"m2c candidate directory has no grouped C files: {output}")
    all_addresses: list[int] = []
    for path in c_files:
        text = path.read_text(encoding="utf-8", errors="replace")
        guards = list(GUARD_RE.finditer(text))
        all_addresses.extend(int(match.group(1), 16) for match in guards)
        if not guards:
            all_addresses.extend(
                int(match.group(1), 16)
                for match in CANDIDATE_MARKER_RE.finditer(text)
            )
    counts = Counter(all_addresses)
    duplicates = {address for address, count in counts.items() if count > 1}
    actual = set(all_addresses)
    if duplicates:
        raise SystemExit(
            "duplicate candidate guards: "
            + ", ".join(f"{address:08x}" for address in sorted(duplicates)[:10])
        )
    if actual != expected:
        missing = sorted(expected - actual)
        extra = sorted(actual - expected)
        raise SystemExit(
            f"candidate guard coverage mismatch: missing={len(missing)} extra={len(extra)}"
        )
    return len(actual), len(c_files)


def validate_output(output: Path, expected: set[int]) -> None:
    actual, file_count = validate_guard_coverage(output, expected)
    report_path = output / "report.json"
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"cannot read candidate report {report_path}: {error}") from error
    if report.get("requested") != len(expected):
        raise SystemExit("candidate report requested count disagrees with the function map")
    print(
        f"validated grouped m2c candidates: {actual} boundaries in "
        f"{file_count} C files"
    )


def load_verified_candidate_matches(
    report_path: Path,
    expected: set[int],
) -> set[int]:
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"cannot read verifier report {report_path}: {error}") from error
    matches: set[int] = set()
    for row in report.get("results", []):
        file = str(row.get("file", "")).replace("\\", "/")
        if not file.startswith("src/generated/"):
            continue
        if row.get("status") not in {"MATCH", "STALE_NONMATCHING"}:
            continue
        if row.get("normalized_diff") != 0:
            continue
        try:
            address = int(row["addr"], 16)
        except (KeyError, TypeError, ValueError):
            continue
        if address in expected:
            matches.add(address)
    return matches


def promote_verified_matches(
    source_output: Path,
    report_path: Path,
    expected: set[int],
) -> tuple[int, int]:
    verified = load_verified_candidate_matches(report_path, expected)
    marker_re = re.compile(
        r"^(?P<prefix>\s*//\s*FUN_)(?P<address>[0-9A-Fa-f]{8})"
        r"\s+NONMATCHING\s*$",
        re.MULTILINE,
    )
    promoted = 0
    for path in sorted(source_output.glob("*.c")):
        text = path.read_text(encoding="utf-8")

        def replace(match: re.Match[str]) -> str:
            nonlocal promoted
            address = int(match.group("address"), 16)
            if address not in verified:
                return match.group(0)
            promoted += 1
            return f"{match.group('prefix')}{match.group('address')}"

        updated = marker_re.sub(replace, text)
        if updated != text:
            path.write_text(updated, encoding="utf-8", newline="\n")
    return promoted, len(verified)
def replace_reported_residuals(
    source_output: Path,
    report_path: Path,
) -> tuple[int, int]:
    """Replace reported residual candidates with exact retail-asm bodies."""
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"cannot read verifier report {report_path}: {error}") from error
    by_file: dict[Path, set[int]] = defaultdict(set)
    for row in report.get("results", []):
        if row.get("status") not in {"SIZE_MISMATCH", "NONMATCHING"}:
            continue
        file = str(row.get("file", "")).replace("\\", "/")
        prefix = "src/generated/"
        if not file.startswith(prefix):
            continue
        try:
            raw_address = row["addr"]
            address = (
                raw_address
                if isinstance(raw_address, int)
                else int(str(raw_address), 16)
            )
        except (KeyError, TypeError, ValueError):
            continue
        by_file[source_output / file[len(prefix):]].add(address)
    retail_bodies = load_retail_bodies()
    changed_files = 0
    changed_units = 0
    for path, addresses in sorted(by_file.items()):
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        replacements: list[tuple[int, int, str]] = []
        for guard in GUARD_RE.finditer(text):
            address = int(guard.group(1), 16)
            if address not in addresses:
                continue
            end_match = re.search(
                r"^\s*#endif\b[^\n]*$",
                text[guard.end():],
                re.MULTILINE,
            )
            if end_match is None:
                raise SystemExit(f"unterminated candidate guard in {path}: {address:08x}")
            retail_body = retail_bodies.get(address)
            if retail_body is None:
                raise SystemExit(f"missing retail fallback body for {address:08x}")
            replacement = (
                f"\n/* Candidate status: RETAIL_ASM; boundary 0x{address:08x}. */\n"
                f"{prepare_retail_asm_candidate_for_address(retail_body, address)}\n"
            )
            start = guard.end()
            end = start + end_match.start()
            replacements.append((start, end, replacement))
            changed_units += 1
        if replacements:
            for start, end, replacement in reversed(replacements):
                text = text[:start] + replacement + text[end:]
            path.write_text(text, encoding="utf-8", newline="\n")
            changed_files += 1
    return changed_files, changed_units
def normalize_reported_compile_errors(
    source_output: Path,
    report_path: Path,
) -> tuple[int, int]:
    """Re-run candidate-only normalization on reported compile-error units."""
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"cannot read verifier report {report_path}: {error}") from error
    by_file: dict[Path, dict[int, str]] = defaultdict(dict)
    for row in report.get("results", []):
        if row.get("status") != "COMPILE_ERROR":
            continue
        file = str(row.get("file", "")).replace("\\", "/")
        prefix = "src/generated/"
        if not file.startswith(prefix):
            continue
        try:
            raw_address = row["addr"]
            address = (
                raw_address
                if isinstance(raw_address, int)
                else int(str(raw_address), 16)
            )
        except (KeyError, TypeError, ValueError):
            continue
        by_file[source_output / file[len(prefix):]][address] = str(
            row.get("detail", "")
        )
    changed_files = 0
    changed_units = 0
    for path, error_details in sorted(by_file.items()):
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        replacements: list[tuple[int, int, str]] = []
        for guard in GUARD_RE.finditer(text):
            address = int(guard.group(1), 16)
            if address not in error_details:
                continue
            end_match = re.search(r"^\s*#endif\b[^\n]*$", text[guard.end():], re.MULTILINE)
            if end_match is None:
                raise SystemExit(f"unterminated candidate guard in {path}: {address:08x}")
            start = guard.end()
            end = start + end_match.start()
            block = text[start:end].strip("\n")
            marker = re.search(
                r"^\s*//\s*FUN_[0-9A-Fa-f]{8}\b[^\n]*$",
                block,
                re.MULTILINE,
            )
            declarations: tuple[str, ...] = ()
            if marker is not None:
                candidate_body = block[marker.end() :]
                direct_calls = direct_call_symbols(candidate_body)
                bare_functions = bare_function_symbols(candidate_body)
                function_returns = function_return_hints(candidate_body)
                prefix_lines: list[str] = []
                for line in block[: marker.start()].splitlines():
                    stripped = line.strip()
                    if stripped.endswith(";"):
                        line = normalize_external_declaration(
                            stripped,
                            direct_calls,
                            bare_functions,
                            function_returns,
                        )
                        declarations += (line,)
                    prefix_lines.append(line)
                marker_and_body = block[marker.start() :]
                block = "\n".join(prefix_lines + [marker_and_body])
            normalized = normalize_candidate_body(block, declarations)
            normalized = normalize_compile_error_repair(
                normalized,
                address,
                error_details.get(address, ""),
            )
            if normalized != block:
                replacements.append((start, end, "\n" + normalized + "\n"))
                changed_units += 1
        if replacements:
            for start, end, replacement in reversed(replacements):
                text = text[:start] + replacement + text[end:]
            path.write_text(text, encoding="utf-8", newline="\n")
            changed_files += 1
    return changed_files, changed_units


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--m2c", type=Path, help="path to m2c.py or executable")
    parser.add_argument("--output", type=Path, default=OUTPUT_DEFAULT)
    parser.add_argument("--source-output", type=Path, default=SOURCE_OUTPUT_DEFAULT)
    parser.add_argument("--image", type=Path, default=IMAGE_DEFAULT)
    parser.add_argument("--undefined-syms", type=Path, default=UNDEFINED_SYMS_DEFAULT)
    parser.add_argument("--batch-size", type=int, default=32)
    parser.add_argument("--timeout", type=float, default=120.0)
    parser.add_argument("--limit", type=int, help="process only the first N fallback boundaries")
    parser.add_argument("--start", type=lambda value: int(value, 0), default=0)
    parser.add_argument("--check", action="store_true", help="validate existing grouped candidates")
    parser.add_argument(
        "--promote-report",
        type=Path,
        help="remove NONMATCHING markers proven exact by a candidate verifier report",
    )
    parser.add_argument(
        "--replace-residual-report",
        type=Path,
        help="replace SIZE_MISMATCH/NONMATCHING candidates with retail asm",
    )
    parser.add_argument(
        "--normalize-report",
        type=Path,
        help="re-normalize generated units reported as COMPILE_ERROR",
    )
    parser.add_argument(
        "--group-report",
        type=Path,
        help="render verified candidates into unguarded grouped sources",
    )
    parser.add_argument(
        "--group-output",
        type=Path,
        default=REPO / "src" / "generated" / "matched",
    )
    parser.add_argument(
        "--apply-group-report",
        type=Path,
        help="apply a grouped verifier report and prune exact units",
    )
    args = parser.parse_args()
    if args.batch_size < 1 or args.timeout <= 0:
        parser.error("--batch-size must be positive and --timeout must be greater than zero")

    fallbacks = load_fallbacks()
    if args.promote_report is not None:
        promoted, verified = promote_verified_matches(
            args.source_output.resolve(),
            args.promote_report.resolve(),
            set(fallbacks),
        )
        print(
            f"promoted verified generated matches: {promoted} markers "
            f"from {verified} verified candidate rows"
        )
        return 0
    if args.replace_residual_report is not None:
        changed_files, changed_units = replace_reported_residuals(
            args.source_output.resolve(),
            args.replace_residual_report.resolve(),
        )
        print(
            f"replaced reported residuals with retail asm: "
            f"{changed_units} units in {changed_files} C files"
        )
        return 0
    if args.normalize_report is not None:
        changed_files, changed_units = normalize_reported_compile_errors(
            args.source_output.resolve(),
            args.normalize_report.resolve(),
        )
        print(
            f"re-normalized reported candidate compile errors: "
            f"{changed_units} units in {changed_files} C files"
        )
        return 0
    if args.group_report is not None:
        files, units = render_verified_groups(
            args.source_output.resolve(),
            args.group_output.resolve(),
            args.group_report.resolve(),
        )
        print(f"rendered verified grouped matches: {units} units in {files} C files")
        return 0
    if args.apply_group_report is not None:
        files, units = apply_verified_groups(
            args.source_output.resolve(),
            args.group_output.resolve(),
            args.apply_group_report.resolve(),
        )
        print(f"applied grouped matches: {units} units in {files} C files")
        return 0
    if args.check:
        expected = set(fallbacks)
        validate_output(args.output.resolve(), expected)
        source_actual, source_files = validate_guard_coverage(
            args.source_output.resolve(), expected
        )
        print(
            f"validated source candidate layout: {source_actual} boundaries in "
            f"{source_files} C files"
        )
        return 0
    selected = [address for address in fallbacks if address >= args.start]
    if args.limit is not None:
        selected = selected[:args.limit]
    fallbacks = {address: fallbacks[address] for address in selected}
    assembly = load_assembly_blocks()
    missing_assembly = sorted(set(fallbacks) - set(assembly))
    if missing_assembly:
        raise SystemExit(
            "missing split assembly blocks: "
            + ", ".join(f"{address:08x}" for address in missing_assembly[:10])
        )
    retail_bodies = load_retail_bodies()
    missing_retail = sorted(set(fallbacks) - set(retail_bodies))
    if missing_retail:
        raise SystemExit(
            "missing exact fallback bodies: "
            + ", ".join(f"{address:08x}" for address in missing_retail[:10])
        )

    symbol_path = args.undefined_syms.resolve()
    image_path = args.image.resolve()
    jump_table_symbols = load_jump_table_symbols(symbol_path)
    jump_tables = load_jump_tables(image_path, jump_table_symbols)
    addresses = list(fallbacks)
    prepared_assembly, jump_table_words, preparation_failures = prepare_assembly(
        assembly, addresses, jump_tables
    )

    m2c = find_m2c(args.m2c)
    work_dir = REPO / "build" / "m2c"
    context = context_file(work_dir)
    generated: dict[int, M2cCandidate] = {}
    failures: dict[int, str] = {}
    sequence = [0]
    for offset in range(0, len(addresses), args.batch_size):
        batch = addresses[offset:offset + args.batch_size]
        print(
            f"m2c batch {offset + 1}-{offset + len(batch)}/{len(addresses)} "
            f"({batch[0]:08x}-{batch[-1]:08x})",
            flush=True,
        )
        process_batch(
            batch,
            prepared_assembly,
            jump_table_words,
            context,
            m2c,
            args.timeout,
            work_dir,
            sequence,
            generated,
            failures,
        )

    output = args.output.resolve()
    written = render_candidates(
        output, fallbacks, generated, failures, retail_bodies
    )
    source_output = args.source_output.resolve()
    source_written = render_candidates(
        source_output,
        fallbacks,
        generated,
        failures,
        retail_bodies,
        source_mode=True,
    )
    validate_guard_coverage(source_output, set(fallbacks))
    prepared_count = sum(
        bool(indirect_jump_table_names(assembly[address]))
        and address not in preparation_failures
        for address in addresses
    )
    specialized_count = sum(
        specialize_ambiguous_jump_table_setup(assembly[address]) != assembly[address]
        for address in addresses
    )
    report = {
        "schema_version": 2,
        "m2c": str(m2c),
        "requested": len(fallbacks),
        "m2c_generated": len(generated),
        "exact_retail_fallback": len(fallbacks) - len(generated),
        "failures": {f"{address:08x}": reason for address, reason in sorted(failures.items())},
        "preparation_failures": {
            f"{address:08x}": reason
            for address, reason in sorted(preparation_failures.items())
        },
        "input_contract": {
            "assembly": [str(path.relative_to(REPO)) for path in ASM_PATHS],
            "image": str(image_path.relative_to(REPO)),
            "image_vram": f"{IMAGE_VRAM:#x}",
            "undefined_symbols": str(symbol_path.relative_to(REPO)),
            "jump_tables_loaded": len(jump_tables),
            "jump_table_functions_prepared": prepared_count,
            "jump_table_definitions_emitted": len(jump_table_words),
            "jump_table_functions_specialized": specialized_count,
        },
        "output_files": [str(path.relative_to(REPO)) for path in written],
        "source_output": str(source_output.relative_to(REPO)),
        "source_output_files": [str(path.relative_to(REPO)) for path in source_written],
        "batch_count": sequence[0],
        "batch_size": args.batch_size,
        "timeout_seconds": args.timeout,
    }
    output.mkdir(parents=True, exist_ok=True)
    (output / "report.json").write_text(
        json.dumps(report, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    print(
        f"generated grouped candidates: {len(generated)} m2c, "
        f"{len(fallbacks) - len(generated)} exact-retail fallback, "
        f"{len(written)} C files; source={source_output.relative_to(REPO)}"
    )
    return 0

def _report_address(row: dict) -> int | None:
    try:
        raw = row["addr"]
        return raw if isinstance(raw, int) else int(str(raw), 16)
    except (KeyError, TypeError, ValueError):
        return None


def _group_block_texts(
    source_path: Path,
    addresses: set[int],
) -> tuple[str, list[str]]:
    text = source_path.read_text(encoding="utf-8", errors="replace")
    first_guard = GUARD_RE.search(text)
    if first_guard is None:
        return text, []
    header = text[: first_guard.start()]
    blocks: list[str] = []
    for guard in GUARD_RE.finditer(text):
        address = int(guard.group(1), 16)
        if address not in addresses:
            continue
        end_match = re.search(
            r"^\s*#endif\b[^\n]*$",
            text[guard.end() :],
            re.MULTILINE,
        )
        if end_match is None:
            raise SystemExit(
                f"unterminated candidate guard in {source_path}: {address:08x}"
            )
        blocks.append(
            text[guard.end() : guard.end() + end_match.start()].strip("\n")
        )
    return header, blocks


def _dedupe_group_blocks(blocks: list[str]) -> list[str]:
    definitions: set[str] = set()
    for block in blocks:
        definitions.update(
            match.group(1)
            for match in re.finditer(
                r"(?m)^\s*(?!extern\b)"
                r"(?:[A-Za-z_][\w\s*()]*?)\b"
                r"(func_[0-9A-Fa-f]{8})\s*\([^;{}]*\)\s*\{",
                block,
            )
        )
    declaration_re = re.compile(
        r"^[ \t]*[^;{}\n]*\b"
        r"(?P<symbol>(?:func_|D_|jtbl_)[0-9A-Fa-f]{8})\s*"
        r"\([^;{}\n]*\)\s*;.*$"
    )
    data_declaration_re = re.compile(
        r"^[ \t]*[^;{}\n]*\b"
        r"(?P<symbol>(?:D_|jtbl_)[0-9A-Fa-f]{8})\s*;.*$"
    )
    seen: set[str] = set()
    cleaned: list[str] = []
    for block in blocks:
        lines: list[str] = []
        for line in block.splitlines():
            match = declaration_re.match(line) or data_declaration_re.match(line)
            if match is not None:
                symbol = match.group("symbol")
                if symbol in definitions or symbol in seen:
                    continue
                seen.add(symbol)
            lines.append(line)
        cleaned.append("\n".join(lines))
    return cleaned


def _write_grouped_match_file(
    source_path: Path,
    addresses: set[int],
    output_path: Path,
) -> int:
    header, blocks = _group_block_texts(source_path, addresses)
    if not blocks:
        return 0
    header = header.replace(
        "/* Grouped m2c candidates; not authoritative matching-C sources. */",
        "/* Grouped verified generated matches; candidate-only source. */",
    )
    cleaned = _dedupe_group_blocks(blocks)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(
        header.rstrip() + "\n\n" + "\n\n".join(cleaned) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    return len(cleaned)


def load_grouped_match_addresses(
    report_path: Path,
    source_prefix: str = "src/generated/",
) -> dict[str, set[int]]:
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise SystemExit(f"cannot read verifier report {report_path}: {error}") from error
    grouped: dict[str, set[int]] = defaultdict(set)
    for row in report.get("results", []):
        file = str(row.get("file", "")).replace("\\", "/")
        if not file.startswith(source_prefix):
            continue
        if row.get("status") != "MATCH" or row.get("normalized_diff") != 0:
            continue
        address = _report_address(row)
        if address is not None:
            grouped[file].add(address)
    return grouped


def render_verified_groups(
    source_output: Path,
    grouped_output: Path,
    report_path: Path,
) -> tuple[int, int]:
    """Render verified candidate functions into P3-style unguarded groups."""
    grouped = load_grouped_match_addresses(report_path)
    for stale in grouped_output.glob("*.c"):
        stale.unlink()
    files = 0
    units = 0
    for file, addresses in sorted(grouped.items()):
        source_path = source_output / file[len("src/generated/") :]
        if not source_path.is_file():
            continue
        output_path = grouped_output / source_path.name
        count = _write_grouped_match_file(source_path, addresses, output_path)
        if count:
            files += 1
            units += count
    return files, units


def apply_verified_groups(
    source_output: Path,
    grouped_output: Path,
    report_path: Path,
) -> tuple[int, int]:
    """Keep only grouped functions that still match after grouped compilation."""
    grouped = load_grouped_match_addresses(
        report_path,
        source_prefix="src/generated/matched/",
    )
    if grouped_output.is_dir():
        kept_names = {Path(file).name for file in grouped}
        for stale in grouped_output.glob("*.c"):
            if stale.name not in kept_names:
                stale.unlink()
    pruned_files = 0
    pruned_units = 0
    for file, addresses in sorted(grouped.items()):
        name = Path(file).name
        source_path = source_output / name
        grouped_path = grouped_output / name
        if not source_path.is_file():
            continue
        if addresses:
            count = _write_grouped_match_file(source_path, addresses, grouped_path)
            pruned_units += count
            if count:
                pruned_files += 1
            elif grouped_path.exists():
                grouped_path.unlink()
        elif grouped_path.exists():
            grouped_path.unlink()
        text = source_path.read_text(encoding="utf-8", errors="replace")
        replacements: list[tuple[int, int]] = []
        for guard in GUARD_RE.finditer(text):
            address = int(guard.group(1), 16)
            if address not in addresses:
                continue
            end_match = re.search(
                r"^\s*#endif\b[^\n]*$",
                text[guard.end() :],
                re.MULTILINE,
            )
            if end_match is not None:
                end = guard.end() + end_match.end()
                if end < len(text) and text[end] == "\n":
                    end += 1
                replacements.append((guard.start(), end))
        for start, end in reversed(replacements):
            text = text[:start] + text[end:]
        if replacements:
            source_path.write_text(text, encoding="utf-8", newline="\n")
    return pruned_files, pruned_units


if __name__ == "__main__":
    raise SystemExit(main())

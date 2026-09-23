#!/usr/bin/env python3
"""Instruction-level alignment of one Persona 4 USA function against retail.

``fndiff.py`` compares word N of the object with word N of retail. That is the
right measure of "how far is this from matching", but it is the wrong report
when a candidate is one instruction short: every later word is then counted as
different and the real edit - a single missing instruction - is buried under a
few hundred shifted rows.

This tool aligns the two instruction streams instead and prints the edit
script: which retail instructions are missing, which extra ones the object has,
and which are genuinely different. Relocated operands are linker-owned, so a
difference that consists only of a relocated immediate is reported separately
and excluded from the edit count.

Usage:
  python tools/fnalign.py src/foo.c func_00123456
  python tools/fnalign.py src/foo.c func_00123456 --candidate /tmp/body.c
  python tools/fnalign.py src/foo.c func_00123456 --addr 00123456

``--candidate`` measures a body without writing the tracked source: the file
replaces that function's definition (or its INCLUDE_ASM row) in a temporary
copy of the whole translation unit, exactly as ``probe_variants.py`` does.
"""
from __future__ import annotations

import argparse
import difflib
from pathlib import Path
import re
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (FUNCTION_WINDOWS, REPO, TARGET, ObjectFile, RetailElf,
                    _compile, _die, _read_json, load_config, scan_markers,
                    window_for)
import probe_variants as probe

import eedis

try:
    from capstone import Cs, CS_ARCH_MIPS, CS_MODE_LITTLE_ENDIAN, CS_MODE_MIPS64
    _DISASSEMBLER = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)

    def _capstone(word: bytes, pc: int) -> str:
        for instruction in _DISASSEMBLER.disasm(word, pc):
            return f"{instruction.mnemonic} {instruction.op_str}"
        return "??"

    # capstone has no lq/sq, and an undecoded word becomes "??" - which
    # compares equal to every other "??", hiding whole prologues.
    disassemble = eedis.build(_capstone)
except ImportError:  # pragma: no cover - capstone is a hard requirement here
    def disassemble(word: bytes, pc: int) -> str:
        return ""


BRANCH_RE = re.compile(r"^(b|beq|beqz|bne|bnez|bgez|bgtz|blez|bltz|bgezal|bltzal|"
                       r"beql|bnel|beqzl|bnezl|bgezl|bgtzl|blezl|bltzl|bc1t|bc1f)$")
JUMP_RE = re.compile(r"^(j|jal)$")
HEX_RE = re.compile(r"^0x[0-9a-f]+$", re.IGNORECASE)


def normalise(text: str, pc: int) -> str:
    """Instruction text with position-dependent targets made comparable.

    Branch targets become instruction-relative (`b .+7`), so the same loop in
    two objects at different addresses reads the same, while a branch that
    really goes somewhere else still differs. Jump targets are relocated in the
    object and absolute in retail, so only the mnemonic survives.
    """
    text = text.strip()
    if not text:
        return "??"
    mnemonic, _, operands = text.partition(" ")
    mnemonic, operands = mnemonic.strip(), operands.strip()
    if JUMP_RE.match(mnemonic):
        return mnemonic
    if BRANCH_RE.match(mnemonic) and operands:
        parts = [part.strip() for part in operands.split(",")]
        if HEX_RE.match(parts[-1]):
            delta = (int(parts[-1], 16) - pc) // 4
            parts[-1] = f".{delta:+d}"
        return f"{mnemonic} {','.join(parts)}"
    return f"{mnemonic} {operands}" if operands else mnemonic


def decode(data: bytes, base: int) -> list[str]:
    return [normalise(disassemble(data[offset:offset + 4], base + offset), base + offset)
            for offset in range(0, len(data) - len(data) % 4, 4)]


def strip_immediates(text: str) -> str:
    """Instruction text without numeric operands, for reloc-only comparison.

    A relocated field reaches the operand as a bare immediate (`addiu $a0,
    $a0, 0x1234`) or as a load/store displacement (`lwc1 $f2, 0x42d8($v0)`);
    both are linker-owned, so both are dropped here.
    """
    mnemonic, _, operands = text.partition(" ")
    kept = []
    for part in operands.split(","):
        part = part.strip()
        if not part:
            continue
        if re.fullmatch(r"-?(0x[0-9a-fA-F]+|\d+)", part):
            continue
        kept.append(re.sub(r"^-?(0x[0-9a-fA-F]+|\d+)\(", "(", part))
    return f"{mnemonic} {','.join(kept)}"


def align(retail: list[str], candidate: list[str],
          relocated: set[int]) -> tuple[list[tuple], int, int]:
    """Edit script between the two streams, plus (edits, reloc-only replacements).

    `relocated` holds candidate instruction indices whose operand the linker
    owns; a one-for-one replacement that differs only there is not an edit.
    """
    matcher = difflib.SequenceMatcher(None, retail, candidate, autojunk=False)
    script: list[tuple] = []
    edits = reloc_only = 0
    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        if tag == "equal":
            continue
        pairs = (i2 - i1) == (j2 - j1)
        if tag == "replace" and pairs and all(
                index in relocated and strip_immediates(retail[i1 + step]) ==
                strip_immediates(candidate[index])
                for step, index in enumerate(range(j1, j2))):
            reloc_only += i2 - i1
            script.append(("reloc", i1, i2, j1, j2))
            continue
        edits += max(i2 - i1, j2 - j1)
        script.append((tag, i1, i2, j1, j2))
    return script, edits, reloc_only


def _object_for(source: Path, function: str, candidate: Path | None,
                cfg: dict) -> tuple[bytes, list[dict]]:
    """Compile `source` (with `candidate` spliced in, if given) and cut the function out."""
    with tempfile.TemporaryDirectory(prefix="p4fnalign_") as directory:
        output = Path(directory) / "out.o"
        if candidate is None:
            compiled, log = _compile(source, cfg, output)
            if not compiled:
                _die(log.strip() or "compiler did not produce an object")
        else:
            text = probe._read_text(source)
            newline = probe._newline_for(source.read_bytes())
            start, end = probe.region_for(text, probe.address_of(function, source), function)
            body = probe._normalise_candidate(candidate.read_text(), newline)
            patched = probe.splice_region(text, start, end, body, newline)
            with probe.scratch_source(source) as scratch:
                scratch.write_text(patched)
                compiled, log = probe._compile_in_context(scratch, source, cfg, output)
                if not compiled:
                    _die(log.strip() or "compiler did not produce an object")
        try:
            return ObjectFile(output).function(function)
        except KeyError:
            _die(f"symbol not present in object: {function}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("file", help="C source file containing the function")
    parser.add_argument("function", help="object symbol to compare")
    parser.add_argument("--addr", help="retail address in hex; defaults to its FUN_ marker")
    parser.add_argument("--candidate", help="body to splice in place of the definition")
    parser.add_argument("--quiet", action="store_true", help="print only the summary")
    args = parser.parse_args()

    source = Path(args.file).resolve()
    if not source.is_file():
        _die(f"source file does not exist: {args.file}")
    candidate = Path(args.candidate).resolve() if args.candidate else None
    if candidate is not None and not candidate.is_file():
        _die(f"candidate file does not exist: {args.candidate}")

    # Reject a fallback-only measurement before requiring private build inputs.
    # The source alone establishes that it would compare retail with itself.
    if candidate is None and probe._has_include_fallback(
        probe._read_text(source), probe.address_of(args.function, source), args.function
    ):
        _die(f"{args.function} still has an INCLUDE_ASM fallback in {args.file}, so "
             f"without --candidate the object IS the retail assembly and every number "
             f"below would be meaningless.\n"
             f"  To measure a guarded body, extract it first:\n"
             f"    python3 -E -s tools/measure_guarded.py {args.file} {args.function} "
             f"--save-candidate /var/tmp/body.c\n"
             f"    python3 -E -s tools/fnalign.py {args.file} {args.function} "
             f"--candidate /var/tmp/body.c")

    cfg, target, windows = load_config(), _read_json(TARGET), _read_json(FUNCTION_WINDOWS)
    if windows.get("program") != "SLUS_217.82" or windows.get("sha1") != target["elf"]["sha1"]:
        _die("slus21782_functions.json does not describe the configured P4 USA target")
    retail_elf = RetailElf(cfg["retail_elf"], target, windows["sha1"])

    if args.addr:
        try:
            address = int(args.addr, 16)
        except ValueError:
            _die(f"invalid hexadecimal address: {args.addr}")
    else:
        marker = next((item for item in scan_markers(source) if item["name"] == args.function), None)
        if marker is None:
            address = int(probe.address_of(args.function, source)[4:], 16)
            if not any(item["addr"] == address for item in scan_markers(source)):
                _die(f"no // FUN_ marker found for {args.function} in {args.file}; use --addr")
        else:
            address = marker["addr"]

    boundaries = {int(item, 16) for item in windows["windows"]}
    boundaries.update(int(item, 16) + size for item, size in windows["windows"].items() if size)
    for path in (REPO / "src").rglob("*.c"):
        try:
            boundaries.update(marker["addr"] for marker in scan_markers(path))
        except OSError:
            continue
    window = window_for(address, sorted(boundaries))
    if window is None or window > 0x10000:
        _die(f"no plausible function window at {address:#010x}")

    body, relocations = _object_for(source, args.function, candidate, cfg)
    retail_bytes = retail_elf.bytes_at(address, window)
    # Retail pads each function up to its window with zero words; verify.py
    # treats that tail as alignment, so it is not part of the instruction stream.
    while len(retail_bytes) >= 4 and not any(retail_bytes[-4:]) and len(retail_bytes) > len(body):
        retail_bytes = retail_bytes[:-4]

    retail_text, candidate_text = decode(retail_bytes, address), decode(body, 0)
    relocated = {relocation["offset"] // 4 for relocation in relocations}
    script, edits, reloc_only = align(retail_text, candidate_text, relocated)

    print(f"{args.function} @ {address:#010x}  retail {len(retail_text)} instrs  "
          f"object {len(candidate_text)} instrs")
    if not args.quiet:
        for tag, i1, i2, j1, j2 in script:
            label = "reloc-only" if tag == "reloc" else tag
            print(f"{label:<10} retail[{i1}:{i2}] object[{j1}:{j2}]")
            for text in retail_text[i1:i2]:
                print(f"   retail  {text}")
            for text in candidate_text[j1:j2]:
                print(f"   object  {text}")
    print(f"\nedit instructions: {edits}"
          f"{f' (plus {reloc_only} reloc-only)' if reloc_only else ''}")


if __name__ == "__main__":
    main()

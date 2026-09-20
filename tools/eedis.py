#!/usr/bin/env python3
"""Disassemble one EE instruction, including the ones capstone does not know.

Capstone's MIPS64 mode has no `lq`/`sq` - the PlayStation 2's 128-bit
load/store, major opcodes 0x1E and 0x1F.  It returns NOTHING for those words,
and both `fnalign` and `fndiff` turned an empty decode into the literal string
`"??"`.

That is worse than a wrong mnemonic, because every `??` compares EQUAL to
every other `??`.  MWCC spills callee-saved registers with `sq`, so on any
function with four or more saved registers the entire prologue and epilogue
were invisible to the aligner: a body that saved the wrong registers, or a
different number of them, scored exactly as well as one that saved the right
ones.  `func_001ee610` is the case that exposed it - retail opens

    addiu $sp, $sp, -0x4e0
    sd    $ra, 0x70($sp)
    sq    $s5, 0x60($sp)
    sq    $s4, 0x50($sp)

and the two `sq` rows were being compared as `??` against whatever the object
happened to have there.

Both opcodes are I-type:

    31   26 25  21 20  16 15             0
    +------+------+------+----------------+
    | 0x1E |  base|  rt  |     offset     |   lq  rt, offset(base)
    | 0x1F |  base|  rt  |     offset     |   sq  rt, offset(base)

The offset is a signed 16-bit displacement; the hardware ignores the low four
bits because the access is quadword-aligned, but the field is printed whole so
that a mis-set displacement still shows up as a difference.
"""
from __future__ import annotations

import struct

# Capstone's own register spelling, so an `sq` row reads like the `sd` above it.
REGISTERS = (
    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
    "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra",
)

# Major opcodes 0x36 and 0x3E are LDC2/SDC2 in the MIPS64 map, which on the
# EE are the VU quadword transfers `lqc2`/`sqc2`.  Capstone reads them as
# Octeon's `bbit0`/`bbit1` - branch-on-bit - and renders the 16-bit
# displacement as a BRANCH TARGET computed from the pc.  That is worse than
# the `??` it gives `lq`/`sq`: two byte-identical `lqc2` rows at different
# addresses disassemble to different text and compare UNEQUAL, so every VU
# load and store in a function counted as an alignment edit.  On
# `func_00485870` all ten of its remaining edits were this.
QUADWORD = {0x1E: "lq", 0x1F: "sq", 0x36: "lqc2", 0x3E: "sqc2"}
VECTOR_DESTINATION = {"lqc2", "sqc2"}


def quadword_access(word: bytes) -> str | None:
    """`lq`/`sq`/`lqc2`/`sqc2` text for WORD, or None for anything else."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    mnemonic = QUADWORD.get(value >> 26)
    if mnemonic is None:
        return None
    base = REGISTERS[(value >> 21) & 0x1F]
    index = (value >> 16) & 0x1F
    rt = f"$vf{index}" if mnemonic in VECTOR_DESTINATION else REGISTERS[index]
    offset = value & 0xFFFF
    if offset >= 0x8000:
        offset -= 0x10000
    sign = "-" if offset < 0 else ""
    return f"{mnemonic} {rt}, {sign}{abs(offset):#x}({base})"


# COP1 with fmt=S, function 0x18-0x1F: the EE's floating-point
# multiply-accumulate family.  Capstone knows none of them, so all six
# returned "??" - and every "??" compares equal to every other, which meant
# `adda.s`, `madd.s`, `mula.s`, `msub.s` and `madda.s` were INDISTINGUISHABLE
# from each other and from every undecoded VU op in the same function.  An
# entire session of accumulator work was measured through that.
FPU_ACCUMULATE = {
    0x18: ("adda.s", "fs,ft"), 0x19: ("suba.s", "fs,ft"),
    0x1A: ("mula.s", "fs,ft"), 0x1B: ("msuba.s", "fs,ft"),
    0x1C: ("madd.s", "fd,fs,ft"), 0x1D: ("msub.s", "fd,fs,ft"),
    0x1E: ("madda.s", "fs,ft"), 0x1F: ("msuba.s", "fs,ft"),
}


def fpu_accumulate(word: bytes) -> str | None:
    """`adda.s`/`madd.s` and friends, which capstone does not know."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    if value >> 26 != 0x11 or ((value >> 21) & 0x1F) != 0x10:
        return None
    entry = FPU_ACCUMULATE.get(value & 0x3F)
    if entry is None:
        return None
    mnemonic, shape = entry
    ft, fs, fd = (value >> 16) & 0x1F, (value >> 11) & 0x1F, (value >> 6) & 0x1F
    operands = {"fs,ft": f"$f{fs}, $f{ft}",
                "fd,fs,ft": f"$f{fd}, $f{fs}, $f{ft}"}[shape]
    return f"{mnemonic} {operands}"


def build(capstone_disassemble):
    """Wrap a capstone-backed decoder with the EE forms it does not know.

    The wrappers are tried FIRST, not as a fallback: capstone returns nothing
    for these words today, but a future capstone that decodes them as some
    MIPS DSP instruction would otherwise silently win.

    Anything still undecoded becomes its own raw word rather than a shared
    `"??"`.  That matters more than the pretty name: two DIFFERENT unknown
    instructions must not compare equal.  A tree-wide audit against the
    repository's own listings found 136 distinct forms capstone cannot read -
    the MMI integer ops, the VU macro-mode ops, the EE three-operand `mult` -
    and collapsing all of them to one token made every pair of them look
    identical to the aligner.
    """

    def disassemble(word: bytes, pc: int) -> str:
        for decoder in (quadword_access, fpu_accumulate):
            text = decoder(word)
            if text is not None:
                return text
        text = capstone_disassemble(word, pc)
        if text and text != "??":
            return text
        if len(word) < 4:
            return "??"
        return f".word {struct.unpack('<I', word[:4])[0]:#010x}"

    return disassemble

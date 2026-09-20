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

QUADWORD = {0x1E: "lq", 0x1F: "sq"}


def quadword_access(word: bytes) -> str | None:
    """`lq`/`sq` text for WORD, or None when it is some other instruction."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    mnemonic = QUADWORD.get(value >> 26)
    if mnemonic is None:
        return None
    base = REGISTERS[(value >> 21) & 0x1F]
    rt = REGISTERS[(value >> 16) & 0x1F]
    offset = value & 0xFFFF
    if offset >= 0x8000:
        offset -= 0x10000
    sign = "-" if offset < 0 else ""
    return f"{mnemonic} {rt}, {sign}{abs(offset):#x}({base})"


def build(capstone_disassemble):
    """Wrap a capstone-backed decoder so it also handles `lq` and `sq`.

    The wrapper is tried FIRST, not as a fallback: capstone returns nothing for
    these words today, but a future capstone that decodes them as some MIPS DSP
    instruction would otherwise silently win.
    """

    def disassemble(word: bytes, pc: int) -> str:
        text = quadword_access(word)
        if text is not None:
            return text
        return capstone_disassemble(word, pc)

    return disassemble

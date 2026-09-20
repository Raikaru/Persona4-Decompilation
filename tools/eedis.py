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


# Opcode 0x1C is MMI, the EE's 128-bit multimedia set.  Capstone knows none
# of it - 2000-odd instructions across the tree - and a few words it names as
# something else entirely (`psraw` as `sdbbp`, `mthi1` as `v3mulu`).  The
# encoding is regular: the primary function is the low six bits, and the four
# sub-classes MMI0/1/2/3 put a secondary opcode in the shift-amount field.
MMI_DIRECT = {
    0x10: ("mfhi1", "d"), 0x11: ("mthi1", "s"),
    0x12: ("mflo1", "d"), 0x13: ("mtlo1", "s"),
    0x18: ("mult1", "dst"), 0x19: ("multu1", "dst"),
    0x1A: ("div1", "st"), 0x1B: ("divu1", "st"),
    0x20: ("madd1", "dst"), 0x21: ("maddu1", "dst"),
    0x28: ("mmi1", "dst"), 0x29: ("pcpyh", "dt"),
    0x30: ("pmfhl", "d"), 0x31: ("pmthl", "s"),
    0x34: ("psllh", "dta"), 0x36: ("psrlh", "dta"), 0x37: ("psrah", "dta"),
    0x3C: ("psllw", "dta"), 0x3E: ("psrlw", "dta"), 0x3F: ("psraw", "dta"),
}
MMI0 = {0x01: "psubw", 0x02: "pcgtw", 0x03: "pmaxw", 0x16: "pextlh",
        0x1A: "pextlb", 0x00: "paddw", 0x04: "paddh", 0x05: "psubh",
        0x09: "psubb", 0x08: "paddb", 0x1E: "pext5", 0x1F: "ppac5"}
MMI2 = {0x0E: "pcpyld", 0x12: "pand", 0x13: "pxor", 0x1F: "prot3w",
        0x0A: "pmsubw", 0x00: "pmaddw", 0x09: "pmfhi", 0x1A: "pmflo"}
MMI3 = {0x0E: "pcpyud", 0x12: "por", 0x13: "pnor", 0x1B: "pcpyh",
        0x00: "pmadduw", 0x09: "pmthi", 0x1A: "pmtlo"}
# Function 0x28 is MMI1, not MMI0.  Getting that wrong named 18 `pextub` as
# `pextlb` - the two differ only in which half is extended, and the audit
# caught it immediately because the listing disagreed.
MMI1 = {0x01: "pabsw", 0x02: "pceqw", 0x03: "pminw", 0x04: "padsbh",
        0x05: "pabsh", 0x06: "pceqh", 0x07: "pminh", 0x0A: "pceqb",
        0x10: "padduw", 0x11: "psubuw", 0x12: "pextuw", 0x14: "padduh",
        0x15: "psubuh", 0x16: "pextuh", 0x18: "paddub", 0x19: "psubub",
        0x1A: "pextub", 0x1B: "qfsrv"}
MMI_SUB = {0x08: MMI0, 0x09: MMI2, 0x28: MMI1, 0x29: MMI3}

# `pmfhl`/`pmthl` carry the half-selector in the shift-amount field.
PMFHL = {0x00: ".lw", 0x01: ".uw", 0x02: ".slw", 0x03: ".lh", 0x04: ".sh"}


def multimedia(word: bytes) -> str | None:
    """MMI text for WORD, or None when it is some other instruction."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    if value >> 26 != 0x1C:
        return None
    rs, rt = REGISTERS[(value >> 21) & 0x1F], REGISTERS[(value >> 16) & 0x1F]
    rd, sa = REGISTERS[(value >> 11) & 0x1F], (value >> 6) & 0x1F
    function = value & 0x3F
    table = MMI_SUB.get(function)
    if table is not None:
        mnemonic = table.get(sa)
        return f"{mnemonic} {rd}, {rs}, {rt}" if mnemonic else None
    entry = MMI_DIRECT.get(function)
    if entry is None:
        return None
    mnemonic, shape = entry
    if function in (0x30, 0x31):
        suffix = PMFHL.get(sa)
        if suffix is None:
            return None
        mnemonic += suffix
    return {"d": f"{mnemonic} {rd}",
            "s": f"{mnemonic} {rs}",
            "st": f"{mnemonic} {rs}, {rt}",
            "dt": f"{mnemonic} {rd}, {rt}",
            "dst": f"{mnemonic} {rd}, {rs}, {rt}",
            "dta": f"{mnemonic} {rd}, {rt}, {sa}"}[shape]


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
        for decoder in (quadword_access, fpu_accumulate, multimedia):
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

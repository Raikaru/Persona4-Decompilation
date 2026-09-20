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
    0x00: ("madd", "dst"), 0x01: ("maddu", "dst"),
    0x28: ("mmi1", "dst"), 0x29: ("pcpyh", "dt"),
    0x30: ("pmfhl", "d"), 0x31: ("pmthl", "s"),
    0x34: ("psllh", "dta"), 0x36: ("psrlh", "dta"), 0x37: ("psrah", "dta"),
    0x3C: ("psllw", "dta"), 0x3E: ("psrlw", "dta"), 0x3F: ("psraw", "dta"),
}
MMI0 = {0x01: "psubw", 0x02: "pcgtw", 0x03: "pmaxw", 0x16: "pextlh",
        0x1A: "pextlb", 0x00: "paddw", 0x04: "paddh", 0x05: "psubh",
        0x09: "psubb", 0x08: "paddb", 0x1E: "pext5", 0x1F: "ppac5",
        0x06: "pcgth", 0x07: "pmaxh", 0x0A: "pcgtb", 0x10: "paddsw",
        0x11: "psubsw", 0x12: "pextlw", 0x13: "ppacw", 0x14: "paddsh",
        0x15: "psubsh", 0x17: "ppach", 0x18: "paddsb", 0x19: "psubsb",
        0x1B: "ppacb"}
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


# COP2 macro mode: opcode 0x12 with the CO bit set.  This is how EE code
# drives VU0 from the main pipeline, and capstone decodes none of it - 4000
# instructions across the tree, every one of them opaque.  The encoding is
# regular: bits 24-21 are the xyzw destination mask, and functions 0x3C-0x3F
# escape to a second table whose opcode is `(fd << 2) | (function & 3)`.
BROADCAST = "xyzw"
VU_BASE = {
    0x00: "vadd", 0x04: "vsub", 0x08: "vmadd", 0x0C: "vmsub",
    0x10: "vmax", 0x14: "vmini", 0x18: "vmul",
}
VU_DIRECT = {
    0x1C: "vmulq", 0x1D: "vmaxi", 0x1E: "vmuli", 0x1F: "vminii",
    0x20: "vaddq", 0x21: "vmaddq", 0x22: "vaddi", 0x23: "vmaddi",
    0x24: "vsubq", 0x25: "vmsubq", 0x26: "vsubi", 0x27: "vmsubi",
    0x28: "vadd", 0x29: "vmadd", 0x2A: "vmul", 0x2B: "vmax",
    0x2C: "vsub", 0x2D: "vmsub", 0x2E: "vopmsub", 0x2F: "vmini",
    0x30: "viadd", 0x31: "visub", 0x32: "viaddi", 0x34: "viand",
    0x35: "vior", 0x38: "vcallms", 0x39: "vcallmsr",
}
VU_SPECIAL = {
    0x00: "vadda", 0x04: "vsuba", 0x08: "vmadda", 0x0C: "vmsuba",
    0x10: "vitof0", 0x11: "vitof4", 0x12: "vitof12", 0x13: "vitof15",
    0x14: "vftoi0", 0x15: "vftoi4", 0x16: "vftoi12", 0x17: "vftoi15",
    0x18: "vmula", 0x1C: "vmulaq", 0x1D: "vabs", 0x1E: "vmulai",
    0x1F: "vclipw", 0x20: "vaddaq", 0x21: "vmaddaq", 0x22: "vaddai",
    0x23: "vmaddai", 0x24: "vsubaq", 0x25: "vmsubaq", 0x26: "vsubai",
    0x27: "vmsubai", 0x28: "vadda", 0x29: "vmadda", 0x2A: "vmula",
    0x2C: "vsuba", 0x2D: "vmsuba", 0x2E: "vopmula", 0x2F: "vnop",
    0x30: "vmove", 0x31: "vmr32", 0x34: "vlqi", 0x35: "vsqi",
    0x36: "vlqd", 0x37: "vsqd", 0x38: "vdiv", 0x39: "vsqrt",
    0x3A: "vrsqrt", 0x3B: "vwaitq", 0x3C: "vmtir", 0x3D: "vmfir",
    0x3E: "vilwr", 0x3F: "viswr", 0x40: "vrnext", 0x41: "vrget",
    0x42: "vrinit", 0x43: "vrxor",
}
# The broadcast families occupy four consecutive slots each, one per field.
for _base, _name in VU_BASE.items():
    for _i in range(4):
        VU_DIRECT.setdefault(_base + _i, _name + BROADCAST[_i])
for _base, _name in ((0x00, "vadda"), (0x04, "vsuba"), (0x08, "vmadda"),
                     (0x0C, "vmsuba"), (0x18, "vmula")):
    for _i in range(4):
        VU_SPECIAL[_base + _i] = _name + BROADCAST[_i]


# These reuse the dest field for other purposes (the `fsf`/`ftf` component
# selectors, or nothing at all), so printing an xyzw suffix on them invents a
# distinction the hardware does not make - which the audit caught as 245
# disagreements the moment the VU table went in.
VU_NO_DEST = {
    "vnop", "vwaitq", "vdiv", "vsqrt", "vrsqrt", "vmtir", "vmfir",
    "vilwr", "viswr", "vrnext", "vrget", "vrinit", "vrxor", "vclipw",
    "viadd", "visub", "viaddi", "viand", "vior", "vcallms", "vcallmsr",
}


def _mask(dest: int) -> str:
    return "".join(c for c, bit in zip(BROADCAST, (8, 4, 2, 1)) if dest & bit)


def vector_unit(word: bytes) -> str | None:
    """COP2 macro-mode text for WORD, or None when it is something else."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    if value >> 26 != 0x12 or not (value >> 25) & 1:
        return None
    dest, function = (value >> 21) & 0xF, value & 0x3F
    ft, fs, fd = (value >> 16) & 0x1F, (value >> 11) & 0x1F, (value >> 6) & 0x1F
    if function >= 0x3C:
        mnemonic = VU_SPECIAL.get((fd << 2) | (function & 3))
        if mnemonic is None:
            return None
        if mnemonic in VU_NO_DEST:
            return f"{mnemonic} $vf{ft}, $vf{fs}".rstrip(", $vf0") \
                if mnemonic in ("vmtir", "vmfir", "vilwr", "viswr") else mnemonic
        return f"{mnemonic}.{_mask(dest)} $vf{ft}, $vf{fs}"
    mnemonic = VU_DIRECT.get(function)
    if mnemonic is None:
        return None
    if mnemonic in VU_NO_DEST:
        return f"{mnemonic} $vf{fd}, $vf{fs}, $vf{ft}"
    suffix = f".{_mask(dest)}" if dest else ""
    return f"{mnemonic}{suffix} $vf{fd}, $vf{fs}, $vf{ft}"


# Three more families capstone will not take.  `mult`/`multu`/`madd`/`maddu`
# on the EE write a THIRD register as well as hi/lo, and capstone rejects the
# encoding whenever that field is non-zero - 719 instructions.  `ei`/`di` are
# COP0 interrupt-enable.  `cfc2`/`ctc2` move to and from VU control registers.
SPECIAL_MULTIPLY = {0x18: "mult", 0x19: "multu", 0x1C: "madd", 0x1D: "maddu"}
COP0_INTERRUPT = {0x38: "ei", 0x39: "di"}
COP2_CONTROL = {0x02: "cfc2.ni", 0x06: "ctc2.ni"}


def extended_forms(word: bytes) -> str | None:
    """EE forms capstone rejects or does not know, outside MMI and COP2 macro."""
    if len(word) < 4:
        return None
    value = struct.unpack("<I", word[:4])[0]
    opcode, rs = value >> 26, (value >> 21) & 0x1F
    rt, rd = (value >> 16) & 0x1F, (value >> 11) & 0x1F
    if opcode == 0x00 and rd:
        mnemonic = SPECIAL_MULTIPLY.get(value & 0x3F)
        if mnemonic is not None:
            return (f"{mnemonic} {REGISTERS[rd]}, {REGISTERS[rs]}, "
                    f"{REGISTERS[rt]}")
    if opcode == 0x10 and rs == 0x10:
        mnemonic = COP0_INTERRUPT.get(value & 0x3F)
        if mnemonic is not None:
            return mnemonic
    if opcode == 0x12 and not (value >> 25) & 1:
        mnemonic = COP2_CONTROL.get(rs)
        if mnemonic is not None:
            return f"{mnemonic} {REGISTERS[rt]}, ${rd}"
    return None


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
        for decoder in (quadword_access, fpu_accumulate, multimedia,
                        vector_unit, extended_forms):
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

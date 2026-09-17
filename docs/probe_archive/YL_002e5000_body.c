// func_002e5000 (0x002e5000-0x002e5270, 624B) — clean floor at 90 differing words.
// Retail 152 instrs, object 151 instrs (604B/624B); fnalign 46 edits plus 6 reloc-only.
// Retail relocs 15: 4x D_00882F70 HI16/LO16 pairs, 3x jtbl HI16/LO16
// (jtbl_00748C50/00748C20/00748BF0), 1x func_003129b0 R_MIPS_26. Frame 0x80 with
// s16-s22 plus ra matches; production stays INCLUDE_ASM (no TU regression).
// Source is the 108-line P4_UNIT_002E5000 M2C block de-noised: M2C_FIELD/M2C_UNK,
// s64 shift guards, s128 stack slots, loop gotos and the spurious 4th call arg
// removed; file idiom kept (u8*, *(u8 **)(...+0x38), *(s32 *)(...+4/8),
// *(u16 *)(...+2), &D_00882F70[(s8)(i+1)], 0/2/7/8 -> +0x14 / 1/5/6/10 -> +0xA4).
// Wins: saved-order dst,nextp,i,j,base,row,outer_offset (reverse-assigns to retail
// s6..s0) 103 -> 90; outer-invariant order row,nextp,outer_offset; for-loop form
// (explicit-goto variant scores 131); active temp retained (removing it scores 137).
// Neutral: ((i*3)*0x10) vs i*0x30 and ((j*3)*0x10) vs j*0x30; opt_loop_invariants on;
// temp-declaration permutations. Prior best W8 107 words (goto, split active/base2),
// IoG archive MISMATCH-nd288, WT16 shape reference. Walls: $a1/$a2 slot-base colour,
// $a3/$t0 outer colour, $v1/$a3 slot2 colour, inner-bound reload addiu, scheduling.
// Semantic gate: D_00882F70[0] is correct per retail HI16/LO16 (iGpffffb58c would be
// GPREL and is the wrong symbol); func_003129b0 takes 3 args (u8*,s32,s32) per
// src/Event/Fcl/fclCombineMisc.c — M2C's 4th arg is the dead $a3 (outer) leftover,
// not a parameter; three switches must stay switches (all three jtbl_ present);
// s16 i/j for the dsll32/dsra32 guards, u16 loads for the lhu pair. Non-goals
// func_002e2a10 / func_002e3560 untouched with their own measured notes.
extern s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2);
void func_002e5000(void) {
    u8 *dst;
    u8 **nextp;
    s16 i;
    s16 j;
    u8 *base;
    u8 *row;
    s32 outer_offset;
    s32 inner_offset;
    u8 *active;
    u8 *active2;
    u8 *slot;
    u8 *inner;
    u8 *outer;
    u8 *slot2;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    active = base;
    for (i = 0; i < *(s32 *)(active + 8); i++) {
        j = 0;
        row = base + i * 0xC;
        nextp = &D_00882F70[(s8)(i + 1)];
        outer_offset = i * 0x30;
        for (; (active = *(u8 **)(D_00882F70[0] + 0x38)), j < *(s32 *)(active + 8); j++) {
            dst = row + j + 0x14;
            *dst = 0;
            slot = *(u8 **)(*nextp + 0x38);
            switch (*(s32 *)(slot + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0xA4;
                break;
            default:
                inner_offset = j * 0x30;
                inner = slot + inner_offset + 0x14;
                break;
            }
            active2 = *(u8 **)(D_00882F70[0] + 0x38);
            switch (*(s32 *)(active2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                outer = active2 + outer_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                outer = active2 + outer_offset + 0xA4;
                break;
            default:
                outer = active2 + outer_offset + 0x14;
                break;
            }
            switch (*(s32 *)(active2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                slot2 = active2 + inner_offset + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                slot2 = active2 + inner_offset + 0xA4;
                break;
            default:
                slot2 = active2 + inner_offset + 0x14;
                break;
            }
            if (func_003129b0(inner, *(u16 *)(outer + 2), *(u16 *)(slot2 + 2)) == 1) {
                *dst = 1;
            }
        }
    }
}

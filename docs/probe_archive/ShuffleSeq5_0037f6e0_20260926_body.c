/* func_0037f6e0 (src/Battle/btlShuffleSeqShuffle5.c), 2026-09-26, round 2.
 * Fresh rewrite from the retail asm on the matched deal-state-machine twins
 * (code1_0037.c func_00379f90/0037ad10/0037bc80, and btlShuffleSeqShuffle4.c
 * func_0037da60 which matched this round). Measured with tools/fndiff.py:
 * 127 reloc-masked differing words, 4760B of code in the 4768B window (two
 * zero words), every instruction and branch aligned; the old guarded draft
 * measured ~1000 words.
 *
 * Needs the file-scope declarations fixed to the definitions (u8 * deck
 * handles, func_0036dc60(unit, src, scale, dst), func_00375d50 float-first,
 * func_003717e0 returning s32, func_00378930 / func_0045af60 prototypes), and
 * relies on the u16 frame-number contract of func_00376070 committed with
 * func_0037da60: with s32 frame parameters LICM hoists the (u16) masks
 * (794 words); with the u16 prototype the masks stay at the call like retail.
 *
 * Levers that were load-bearing: `opt_loop_invariants on` (1066 without);
 * the row-bit switch and the listed-card scan as static inline helpers
 * (retail repeats the 0x8C assert and the 1/0 joins); `bit` as u16; the tail
 * reading the speed through arg0 + 0x1F1D2 (hoisted pointer); case 4 building
 * each slot position inside the column loop so LICM produces retail's
 * preheader order.
 *
 * Residual (all 127 words) is callee-saved colouring: retail gives $s0 to
 * arg0, $s1 to the case-local group (speed, the case 0 sub pointer, deck,
 * the case 3/5/9/10/11 loop counters), $s2 to cols and $s3 to sbase; this
 * body keeps arg0 in $s0 but rotates the other three (cols $s1, sbase $s2,
 * locals $s3). Loop-variable naming hill-climb (5 names x 11 loops) went
 * 147 -> 127; declaration order and merging speed/mask or sbase2/deck do not
 * move it (one retail-order declaration list gives 140).
 */
static inline u16 shuffle5RowBit(s32 row)
{
    switch (row) {
    case 0:
        return 2;
    case 1:
        return 4;
    case 2:
        return 8;
    default:
        func_0046d730(&D_0064EB40[0], 0x8C);
        return 0;
    }
}

static inline s32 shuffle5IsListed(u8 *sbase, s32 card)
{
    s32 j;

    for (j = 0; j < *(s32 *)(sbase + 0x28); j++) {
        if (card == *(s32 *)(sbase + j * 4 + 0xC)) {
            return 1;
        }
    }
    return 0;
}

#pragma opt_loop_invariants on
// FUN_0037F6E0
s32 func_0037f6e0(u8 *arg0)
{
    f32 pos[2];
    f32 zero[3];
    f32 outA[3];
    f32 outB[3];
    f32 slide[2];
    f32 fromA[3];
    f32 fromB[3];
    f32 rot[4];
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    u8 *rec;
    u8 *card;
    s32 count;
    s32 cols;
    s32 total;
    s32 rowCols;
    s32 row;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 r;
    u16 speed;
    u16 mask;
    u16 bit;

    sbase = arg0 + 0x1F1D0;
    count = *(s32 *)(arg0 + 0x1F304);
    if (count < 6) {
        cols = count * 2;
    } else {
        cols = count;
    }
    total = func_00378530(count, *(s32 *)(arg0 + 0x1F2FC));
    speed = *(u16 *)(sbase + 2);
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        sbase2 = arg0 + 0x1F1D0;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)sbase2 |= 0x70;
            break;
        case 1:
            r = 3.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
            *(u16 *)sbase2 |= 0x70;
            *(u16 *)sbase2 &= ~(0x10 << r);
            break;
        case 2:
            r = 3.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
            *(u16 *)sbase2 |= (u16)(0x10 << r);
            break;
        default:
            func_0046d730(&D_0064EB40[0], 0x41);
            break;
        }
        *(u16 *)(sbase2 + 2) = 5;
        if (func_00379240(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2:
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
                func_00373750(j, *(s32 *)(arg0 + 0x1F304), pos);
                pos[1] -= 400.0f;
                func_0036dc60(arg0 + j * 0xFB0, pos, 84.0f, zero);
                func_00375d50(arg0, j, (u16)j, (u16)(j + 8), NULL, zero);
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 4);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0x10;
        }
        break;
    case 4:
        if (func_00378930(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        zero[0] = 0.0f;
        zero[1] = 0.0f;
        zero[2] = 0.0f;
        rot[3] = 0.0f;
        rot[0] = 0.0f;
        rot[1] = 1.0f;
        rot[2] = 0.0f;
        for (k = 0; k < total; k++) {
            func_00375d50(arg0, k, 0.0f, 0.0f, zero, zero);
            func_003760f0(arg0, k, 0, 0, rot, rot);
            func_00376290(arg0, k, 0, 0xFF, 0xFF);
        }
        func_0037ef40(arg0);
        *(u16 *)(arg0 + 0x1F2F4) |= 1;
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(s32 *)(sbase + 8) = 0;
        for (row = 0; row < 3; row++) {
            for (j = 0; j < cols; j++) {
                pos[0] = 314.0f + (f32)(((row * 3) / 3 - 1) * 0x6B);
                pos[1] = 236.0f + 120.0f * (f32)((row * 3) % 3 - 1);
                pos[1] = pos[1] - 120.0f * (f32)(cols + 1 - j % cols);
                k = j + row * cols;
                rec = arg0 + k * 0xFB0;
                func_0036dc60(rec, pos, 84.0f, outA);
                pos[1] += 600.0f;
                func_0036dc60(rec, pos, 84.0f, outB);
                func_00376070(arg0, k, row * 7, speed * 2 + row * 7, outA, outB,
                              5.0f * ((outB[1] - outA[1]) / speed));
            }
            func_003762e0(arg0, row * cols, (u16)(row * 7 + 1), 0, 4);
        }
    case 5:
        for (k = 0; k < 3; k++) {
            bit = shuffle5RowBit(k);
            if (!(*(u16 *)sbase & bit) && func_00375970(arg0 + k * cols * 0xE8 + 0x1D6A0) != 0) {
                *(u16 *)sbase |= bit;
                (*(s32 *)(sbase + 8))++;
            }
        }
        if (*(s32 *)(sbase + 8) == 3) {
            *(u32 *)(arg0 + 0x1F2F8) = 6;
        }
        break;
    case 6:
        if (datGetFlag(0x1433) == 0) {
            func_003798d0(arg0, 3);
            *(u32 *)(arg0 + 0x1F2F8) = 0x11;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) |= 2;
            break;
        }
        func_00389110(*(u8 **)(arg0 + 0x1F294));
        func_00388fd0(*(u8 **)(arg0 + 0x1F294));
        func_0038d2c0(*(u8 **)(arg0 + 0x1F298));
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    case 7:
        if (func_00389160(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        func_0038d1f0(*(u8 **)(arg0 + 0x1F298));
        func_00388f60(*(u8 **)(arg0 + 0x1F294));
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 2);
        func_00389040(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        *(u16 *)sbase &= ~shuffle5RowBit(*(u16 *)(sbase + 4));
        func_0045af60(1, 2, 5, 5);
        if (++*(u16 *)(sbase + 4) == 3) {
            func_003890f0(*(u8 **)(arg0 + 0x1F294));
            func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
            *(u32 *)(arg0 + 0x1F2F8) = 9;
        } else if (*(u16 *)(sbase + 4) == 2) {
            func_0037f430(arg0);
        }
        break;
    case 9:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        func_00389020(*(u8 **)(arg0 + 0x1F294));
        func_0038d280(*(u8 **)(arg0 + 0x1F298));
        func_00388fb0(*(u8 **)(arg0 + 0x1F294));
        if (func_0037f550(arg0) != 0) {
            for (i = 0; i < total; i++) {
                if (!shuffle5IsListed(sbase, i)) {
                    func_00378f90(arg0, i, 0x14);
                }
            }
            *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        } else {
            func_00379c70(arg0, -1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 10:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        for (i = 0; i < total; i++) {
            if (!shuffle5IsListed(sbase, i)) {
                func_00375890(arg0, i, 0);
            }
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        for (i = 0; i < *(s32 *)(sbase + 0x28); i++) {
            func_00379090(arg0, *(s32 *)(sbase + i * 4 + 0xC), 0xA, 1);
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
    case 12:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        for (m = 1; m < *(s32 *)(sbase + 0x28); m++) {
            *(u16 *)(arg0 + *(s32 *)(sbase + m * 4 + 0xC) * 0xE8 + 0x1D6A0) &= 0xFFFD;
        }
        func_00378ec0(arg0, *(s32 *)(sbase + 0xC));
        *(u16 *)sbase |= 0x80;
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        if (func_00375910(arg0 + *(s32 *)(sbase + 0xC) * 0xE8 + 0x1D6A0) != 0) {
            break;
        }
        func_00379c70(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xE;
    case 14:
        if (func_00379d70(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xF;
    case 15:
        return 1;
    case 16:
        if (func_00379a70(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 17:
        if (func_00379920(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0x1E) {
            break;
        }
        func_00106390(0x1433, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 6;
        break;
    default:
        func_0046d730(&D_0064EB40[0], 0x295);
        break;
    }
    for (row = 0; row < 3; row++) {
        if (*(u16 *)sbase & shuffle5RowBit(row)) {
            for (j = cols * row; j < cols * (row + 1); j++) {
                mask = *(u16 *)(arg0 + 0x1F1D2);
                rowCols = *(s32 *)(arg0 + 0x1F304);
                if (rowCols < 6) {
                    rowCols *= 2;
                }
                card = arg0 + j * 0xE8;
                if (func_00375910(card + 0x1D6A0) != 0) {
                    func_003717e0(card + 0x1D6B8, (u8 *)slide);
                    if (!(slide[1] < 508.0f)) {
                        slide[1] = slide[1] - 120.0f * (f32)rowCols;
                    }
                    rec = arg0 + j * 0xFB0;
                    func_0036dc60(rec, slide, 84.0f, fromA);
                    slide[1] += 120.0f;
                    func_0036dc60(rec, slide, 84.0f, fromB);
                    func_00375d50(arg0, j, 0.0f, mask, fromA, fromB);
                }
            }
        }
    }
    return 0;
}
#pragma opt_loop_invariants off

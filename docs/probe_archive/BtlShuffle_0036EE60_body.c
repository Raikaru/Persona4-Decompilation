/* Target: func_0036ee60 @ 0x0036ee60, owner src/promoted/btlShuffle.c.
 * Retail window 1456B (0x5B0). Compiler: MWCCPS2 3.0.1 b210 -O2 (repo standard).
 * Evidence read: asm/nonmatchings/btlShuffle/func_0036ee60.s (full, 404 lines),
 *   docs/ghidra_headstart/src/promoted/btlShuffle.c FUN_0036ee60,
 *   docs/ida_headstart/src/promoted/btlShuffle.c sub_36EE60,
 *   src/generated/code1_0036.c P4_UNIT_0036EE60 (m2c draft, 226 lines),
 *   caller asm/nonmatchings/code1_001b/func_001b3a00.s (passes (u8*, s16) plus a
 *   dead third arg the callee never reads; 2-param signature is truthful).
 * Score (probe_variants, 2026-09-16): obj 1448B / window 1456B, nd 292, 362 vs
 *   363 retail instrs. Control flow, call sequence (14 jal sites: 104c70,
 *   10aa80, 231d70 x8, e920/eb50/ea00/eda0), branch polarity, and the i*14
 *   record scaling (sll/subu/sll) all reproduce retail. Relocations emitted at
 *   the same sites (D_0064E76F HI16/LO16 pair, gp-relative table base,
 *   R_MIPS_26 per call); production stays INCLUDE_ASM so none of this links.
 * Semantics: party level (func_00104c70 & 0xFF) picks a monster-level window
 *   [lo, hi] (table D_0064E76F when 1..9 else min(level, arg1) -5/-10, clamped
 *   >= 0; cap = min(level + 3, 99)); scan of 256 x14-byte records keeps those
 *   with (flags & 0xDB) == 0, level <= cap, and (level < mlvl || mlvl in
 *   window) into three s16[256] buckets (10aa80-hit / above-level / window);
 *   each bucket randomly swapped, draw count from e920/eb50/ea00/eda0 capped
 *   by the total, output preferring the window bucket then the hit bucket.
 * Truthful residual (fnalign v3c): frame 0x6D0 vs 0x6F0 shifts every stack
 *   offset (arrays at 0xD0/0x2D0/0x4D0 vs 0xF0/0x2F0/0x4F0); 8 quadword rows
 *   (hi/lo spilled with sq/lq at sp+0xC0/0xD0, two shuffle rands at
 *   sp+0xA0/0xB0); the dead B draw arm F2F0-F318 (10 instrs after the
 *   unconditional `b` at F2E8); spill victims arg1@0xCE + nA@0xB0 instead of
 *   hi/lo; downstream register colors (draw/shuffle/epilogue) follow the
 *   victims. Remaining slt-dest and stack-offset rows are consequences.
 * Decisive levers (all measured): B/C/A arm order with shared emit tail;
 *   `lvl >= arg1` (retail keeps the arg1 path inline, bnez to the level path);
 *   `> K-1` for `>= K` at four sites (cap > 99, counts > 1) to get slti $at;
 *   `((u32)lvl < 10)` for sltiu with no extra andi; `(s16)func_0010aa80((s16)i)`
 *   per the file's own idiom for the sign-extended call/result; block-scope
 *   rec/item temps and inline store/reload around the e920/eb50/ea00 calls.
 * Levers tried, neutral/regressed: C/B/A and 2-arm (drop B) draw orders (nd
 *   302/302 vs 302 baseline -- order does not move nd, the dead skip
 *   dominates); hi/lo declaration first vs last (spill victims immobile:
 *   arg1@0xCE + nA@0xB0 in all three orders); volatile hi/lo (address
 *   recomputed per access, worse; also banned steering).
 * Floors (each micro-measured on b210 -O2, 2026-09-16):
 *   (a) interior GPR lq/sq unreachable from C: 16B struct copy lowers to
 *   ld/sd, `__int128` is rejected ("illegal data size"), struct members are
 *   scalar-replaced into regs -- no spelling produces sq/lq outside the
 *   prologue save/restore this compiler owns.
 *   (b) the dead B arm is unemittable: b210 deletes a goto-skipped block
 *   outright (micro-test), so no C shape keeps 10 instrs behind an
 *   unconditional `b`.
 * Production: INCLUDE_ASM retained (this floor). Re-measure with
 *   probe_variants before any new attempt; fnalign separates color-only
 *   churn from the floor rows above.
 */
// FUN_0036EE60
s32 func_0036ee60(u8 *arg0, s16 arg1)
{
    extern s32 func_00104c70(s32);
    extern u8 D_0064E76F[];
    extern u8 *iGpffffb3d4;
    s16 listA[256];
    s16 listB[256];
    s16 listC[256];
    s16 cap;
    s16 hi;
    s16 lo;
    u16 nC;
    u16 nB;
    u16 nA;
    s16 mlvl;
    s32 i;
    s16 lvl;
    s32 total;
    s32 nDraw;
    s32 k;
    u16 r1;
    u16 r2;
    s16 tmp;
    u16 cIdx;
    u16 aIdx;
    u16 e;
    u16 bIdx;
    s32 w;
    s32 i2;

    lvl = (s16)(func_00104c70(1) & 0xFF);
    if ((lvl > 0) && ((u32)lvl < 10)) {
        hi = D_0064E76F[lvl];
        lo = 1;
    } else if (lvl >= arg1) {
        hi = arg1 - 5;
        lo = arg1 - 10;
    } else {
        hi = lvl - 5;
        lo = lvl - 10;
    }
    cap = lvl + 3;
    if (cap > 99) {
        cap = 99;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    nC = 0;
    nB = 0;
    nA = 0;
    i = 0;
    while (i < 256) {
        u8 *rec = (u8 *)((s32)iGpffffb3d4 + i * 14);
        if ((*(u16 *)rec & 0xDB) == 0) {
            mlvl = *(u8 *)(rec + 3);
            if ((cap >= mlvl) && ((lvl < mlvl) || ((hi >= mlvl) && (mlvl >= lo)))) {
                if ((s16)func_0010aa80((s16)i) != -1) {
                    listA[nA] = (s16)i;
                    nA = (nA + 1) & 0xFFFF;
                } else if (lvl < mlvl) {
                    listB[nB] = (s16)i;
                    nB = (nB + 1) & 0xFFFF;
                } else {
                    listC[nC] = (s16)i;
                    nC = (nC + 1) & 0xFFFF;
                }
            }
        }
        i++;
    }
    {
        s32 bCount = nB & 0xFFFF;
        s32 cCount = nC & 0xFFFF;
        s32 aCount = nA & 0xFFFF;
        total = aCount + (cCount + bCount);
        if (total == 0) {
            return 0;
        }
        if (cCount > 1) {
            for (k = 0; k < cCount; k++) {
                r1 = func_00231d70(cCount) & 0xFFFF;
                r2 = func_00231d70(cCount) & 0xFFFF;
                if (r1 != r2) {
                    tmp = listC[r1];
                    listC[r1] = listC[r2];
                    listC[r2] = tmp;
                }
            }
        }
        if (bCount > 1) {
            for (k = 0; k < bCount; k++) {
                r1 = func_00231d70(bCount) & 0xFFFF;
                r2 = func_00231d70(bCount) & 0xFFFF;
                if (r1 != r2) {
                    tmp = listB[r1];
                    listB[r1] = listB[r2];
                    listB[r2] = tmp;
                }
            }
        }
        if (aCount > 1) {
            for (k = 0; k < aCount; k++) {
                r1 = func_00231d70(aCount) & 0xFFFF;
                r2 = func_00231d70(aCount) & 0xFFFF;
                if (r1 != r2) {
                    tmp = listA[r1];
                    listA[r1] = listA[r2];
                    listA[r2] = tmp;
                }
            }
        }
        *(s32 *)(arg0 + 0x10) = func_0036e920(arg1 & 0xFF);
        *(s32 *)(arg0 + 0x14) = func_0036eb50(*(s32 *)(arg0 + 0x10), arg1 & 0xFF);
        w = func_0036ea00(*(s32 *)(arg0 + 0x10), arg1 & 0xFF);
        *(s32 *)(arg0 + 0xC) = w;
        nDraw = func_0036eda0(w);
        if (total < nDraw) {
            nDraw = total;
        }
        cIdx = 0;
        aIdx = 0;
        e = 0;
        bIdx = 0;
        for (i2 = 0; i2 < nDraw; i2++) {
            s16 item;
            func_00231d70(0x64);
            if (bIdx < bCount) {
                item = listB[bIdx++];
            } else if (cIdx < cCount) {
                item = listC[cIdx++];
            } else if (aIdx < aCount) {
                item = listA[aIdx++];
            } else {
                continue;
            }
            *(s16 *)(arg0 + (s32)e * 2) = item;
            e++;
        }
        if (e == 0) {
            return 0;
        }
        *(s32 *)(arg0 + 8) = e;
        if ((aIdx != e) || (func_00231d70(0x64) < 0x14)) {
            return 1;
        }
        return 0;
    }
}

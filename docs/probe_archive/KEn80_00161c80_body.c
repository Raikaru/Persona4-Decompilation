/* Cold reconstruction of func_00161c80 (window 1184B) from the m2c draft in
 * src/generated/code1_0016.c plus the matched sibling func_00161bb0 idioms in
 * this TU (((s16 *)D_005F1260)[i] scan, D_007E80A0 slot scan, encSlot-free
 * direct chains).
 * Measured 2026-09-17 in this TU: probe/fndiff reloc-masked nd 243
 * (verify normalized_diff ~730; the two scales are linear on this body),
 * object ~1132B/window 1184B, fnalign retail 295 vs object ~283-287 instrs.
 * Lever tally on this exact body: hoisted (s16) sign-extend local, saved cond
 * mask, temp idx mask, narrowed loop temps, decl-order/color variants: flat at
 * 243. opt_loop_invariants on: catastrophic (~741). opt_propagation off:
 * catastrophic (~753). Literal absolute table addresses: flat (~738).
 * No-held-entry recompute: 223-class (chains rematerialize per site).
 * Open walls (fnalign): gp-base spill/found-reg coloring (retail sq/lq base
 * at sp+0xB0, found in $fp), sunk base computation vs retail pinned loads,
 * pervasive saved-register rotation downstream. Production stays ASM. */
u8 *func_00161c80(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    extern s32 func_00106600(s16 id);
    u8 *base;
    s32 cond;
    u32 total;
    s32 i;
    s32 acc;
    s32 hit;
    u8 *found;
    u32 rnd;

    found = NULL;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        s32 m = arg2 & 0xFFFF;
        base = iGpffffb424 + *(u16 *)(iGpffffb41c + m * 10 + 6) * 0x15C;
        if (m == 0) {
            return NULL;
        }
        cond = arg3 & 0xFFFF;
        total = 0;
        for (i = 0; i < 0x1D; i++) {
            u8 *rec = base + i * 0xC;
            u16 ucode = *(u16 *)(rec + 2);
            if (ucode != 0) {
                s32 scode = (s16)ucode;
                hit = 0;
                {
                    s32 j;
                    for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                        if (scode == ((s16 *)D_005F1260)[j] && ((func_00106600((s16)scode) & 0xFF) > 0)) {
                            hit = 1;
                            break;
                        }
                    }
                }
                if (hit == 0 && func_00161bb0((s16)scode) == 0) {
                    s32 present = 0;
                    s32 one = 1;
                    {
                        s32 k;
                        for (k = 0; k < 8; k++) {
                            u8 *slot = D_007E80A0 + k * 0x168;
                            u8 *cand = *(u8 **)(slot + 0x160);
                            if (*(s32 *)(slot + 0) != 0 && cand != NULL && *(s32 *)(slot + 8) != one && scode == (s16)*(u16 *)(cand + 2)) {
                                present = 1;
                                break;
                            }
                        }
                    }
                    if (present == 0) {
                        if (*(u8 *)(rec + 7) & 1) {
                            if (cond == 1 || cond == 2) {
                                total += ucode;
                            }
                        } else if (cond == 0 || cond == 2) {
                            total += ucode;
                        }
                    }
                }
            }
        }
        if (total == 0) {
            func_0046d730(D_005F12C8, 0x166);
        }
        rnd = func_003b7060() % total;
        acc = 0;
        for (i = 0; i < 0x1D; i++) {
            u8 *rec = base + i * 0xC;
            u16 ucode = *(u16 *)(rec + 2);
            if (ucode != 0) {
                s32 scode = (s16)ucode;
                hit = 0;
                {
                    s32 j;
                    for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                        if (scode == ((s16 *)D_005F1260)[j] && ((func_00106600((s16)scode) & 0xFF) > 0)) {
                            hit = 1;
                            break;
                        }
                    }
                }
                if (hit == 0 && func_00161bb0((s16)scode) == 0) {
                    s32 present = 0;
                    s32 one = 1;
                    {
                        s32 k;
                        for (k = 0; k < 8; k++) {
                            u8 *slot = D_007E80A0 + k * 0x168;
                            u8 *cand = *(u8 **)(slot + 0x160);
                            if (*(s32 *)(slot + 0) != 0 && cand != NULL && *(s32 *)(slot + 8) != one && scode == (s16)*(u16 *)(cand + 2)) {
                                present = 1;
                                break;
                            }
                        }
                    }
                    if (present == 0) {
                        if (*(u8 *)(rec + 7) & 1) {
                            if (cond == 1 || cond == 2) {
                                acc += ucode;
                            }
                        } else if (cond == 0 || cond == 2) {
                            acc += ucode;
                        }
                        if (rnd < acc) {
                            found = rec;
                        }
                    }
                }
            }
        }
        return found;
    }
    return NULL;
}

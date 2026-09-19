// Floor for func_00275d80 @0x00275d80 window 1136B
// fnalign retail 284 / object 288 instrs (+1.4%, inside 272-288 band); edits 124 +6 reloc-only.
// guarded obj 1152B/window 1136B, normalized_diff 140 (prior floor 844B/nd 246).
// Frame -448 exact (320B locals: 32 xy at sp+0x80 +32 copy at sp+0xA0 +256 render at sp+0xC0).
// Calls 5 jal +2 jalr complete: 457120, 46d730, 271f50 (u32*,u32), 271310 (1-arg), 43f9c8 + 887300/887310 via absolute slots.
// D_00881750 via DAT_00881750_abs (absolute lui, not GP-relative); D_0063BCC0/D_0063BC88/D_008872F8 via TU externs (no invented prototypes; fr_font_internal.h 11-arg 275680 not called here).
// Shape: IDA stack layout (xy/copy/render direct indexing) + IDA doubling int->float + retail per-lane color branches (4x bltz/cvt/b/srl+or/mtc1/cvt/add) + hoisted f5 + all four &1 hoisted.
// Fixes prior floor: 32B zero loop restored (was absent); sp80 block kept via xy[] aliasing (was dead stores, -50); render/copy via separate arrays (was single stk+wrong offsets, incl. t33+0xC0 bug); temp_19 early; conv4/conv5 split (saves 2 adds); no pragmas (schedule/invariants defaults keep band).
// Walls: s-reg colors rotated (s4/s3/s5/s1/s2 vs s2/s1/s5/s4/s0); FPU f5 in f1 vs f5; copy/xy reads folded (lwc1 offset) vs materialized (addiu+lwc1 0); color srl/andi interleaved vs grouped; 4 trailing nops absent (+4 instrs over window).
s32 func_00275d80(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, u32 arg6, f32 fparg0) {
    f32 render[64];
    f32 copy[8];
    f32 xy[8];
    f32 f22;
    f32 f21;
    f32 f20;
    f32 f5;
    f32 x2tmp;
    f32 x5tmp;
    f32 conv4;
    f32 conv5;
    s32 temp_19;
    u8 *temp_17;
    u8 *var_20;
    s32 v22;
    s32 sh24;
    s32 sh16;
    s32 sh8;
    s32 t10;
    s32 t9;
    s32 t8;
    s32 t7;
    s32 t6;
    s32 t5;
    s32 t4;

    f22 = (f32)arg0 / 16.0f;
    f21 = (f32)arg1 / 8.0f;
    f20 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    temp_19 = arg6 & 0xFF;
    {
        u8 *v7 = D_0063BCC0;
        u8 *v6 = (u8 *)copy;
        s32 v4 = 4;
        s32 t3;
        s32 t2;
        do {
            t3 = *(s32 *)v7;
            t2 = *(s32 *)(v7 + 4);
            v7 += 8;
            v4 -= 1;
            *(s32 *)v6 = t3;
            *(s32 *)(v6 + 4) = t2;
            v6 += 8;
        } while (v4 > 0);
    }
    {
        f32 *p = xy;
        s32 n = 0x20;
        if (p != (f32 *)0) {
            do {
                *(u8 *)p = 0;
                p = (f32 *)((u8 *)p + 1);
                n -= 1;
            } while (n != 0);
        }
    }
    xy[0] = f22;
    xy[1] = f21;
    if (arg4 >= 0) {
        conv4 = (f32)arg4;
    } else {
        s32 uu = ((u32)arg4 >> 1) | (arg4 & 1);
        f32 vf0 = (f32)uu;
        vf0 += vf0;
        conv4 = vf0;
    }
    x2tmp = f22 + conv4;
    xy[2] = x2tmp;
    xy[3] = f21;
    xy[4] = f22;
    if (arg5 >= 0) {
        conv5 = (f32)arg5;
    } else {
        s32 uu2 = ((u32)arg5 >> 1) | (arg5 & 1);
        f32 vf02 = (f32)uu2;
        vf02 += vf02;
        conv5 = vf02;
    }
    x5tmp = f21 + conv5;
    xy[5] = x5tmp;
    xy[6] = x2tmp;
    xy[7] = x5tmp;
    if (*(u8 **)(arg2 + 0x1C) == NULL) {
        func_0046d730(&D_0063BC88, 0x9B);
    }
    var_20 = *(u8 **)(*(u8 **)(arg2 + 0x1C) + 0x0C);
    if (*(s16 *)(var_20 + 8) != arg3) {
        temp_17 = (u8 *)func_00271f50((u32 *)arg2, *(s32 *)(var_20 + 4));
        *(u16 *)((*(u8 **)(arg2 + 0x1C)) + 4) -= 1;
        {
            u8 *t5b = *(u8 **)(arg2 + 0x1C);
            if ((t5b != NULL) && (*(u16 *)(t5b + 4) == 0)) {
                u8 *t4b = *(u8 **)(t5b + 0x0C);
                if (t4b != NULL) {
                    *(s32 *)(t4b + 0) &= ~1;
                    *(s32 *)(t4b + 0x10) = 0;
                }
                func_00271310(*(s32 *)(t5b + 8));
                DAT_00881750_abs[0] -= 1;
            }
        }
        *(u8 **)(arg2 + 0x1C) = temp_17;
        var_20 = *(u8 **)(temp_17 + 0x0C);
    }
    *(s32 *)(var_20 + 0) |= 1;
    if (temp_19 == 0) {
        return 0;
    }
    func_0043f9c8(render, 0, 0x100);
    f5 = D_008872F8[0] - fparg0;
    sh24 = arg6 >> 24;
    sh16 = arg6 >> 16;
    sh8 = arg6 >> 8;
    t10 = sh24 & 0xFF;
    t9 = t10 & 1;
    t8 = sh16 & 0xFF;
    t7 = t8 & 1;
    t6 = sh8 & 0xFF;
    t5 = t6 & 1;
    t4 = temp_19 & 1;
    v22 = 0;
    while (v22 < 4) {
        f32 *dst = &render[v22 * 16];
        f32 *pCopy = &copy[v22 * 2];
        f32 *pXy = &xy[v22 * 2];
        dst[2] = f5;
        dst[6] = f20;
        dst[4] = *pCopy;
        dst[5] = *(pCopy + 1);
        if (t10 >= 0) {
            dst[8] = (f32)t10;
        } else {
            s32 q10 = ((u32)t10 >> 1) | t9;
            f32 g10 = (f32)q10;
            g10 += g10;
            dst[8] = g10;
        }
        if (t8 >= 0) {
            dst[9] = (f32)t8;
        } else {
            s32 q8 = ((u32)t8 >> 1) | t7;
            f32 g8 = (f32)q8;
            g8 += g8;
            dst[9] = g8;
        }
        if (t6 >= 0) {
            dst[10] = (f32)t6;
        } else {
            s32 q6 = ((u32)t6 >> 1) | t5;
            f32 g6 = (f32)q6;
            g6 += g6;
            dst[10] = g6;
        }
        if (temp_19 >= 0) {
            dst[11] = (f32)temp_19;
        } else {
            s32 q19 = ((u32)temp_19 >> 1) | t4;
            f32 g19 = (f32)q19;
            g19 += g19;
            dst[11] = g19;
        }
        dst[0] = *pXy;
        dst[1] = *(pXy + 1);
        v22 += 1;
    }
    D_00887300[0](1, *(s32 *)(var_20 + 0x14));
    D_00887310[0](4, render, 4);
    return 0;
}

// Wins: zero loop; sp80 kept; render/copy/xy layout; f5 hoisted; 4x &1 hoisted; absolute 881750; 5+2 calls; frame exact.
// Walls: 124 edits mostly reg colors + addressing modes, no bulk delete (largest delete 3 trailing nops); +4 instrs over window (288 vs 284) from extra lw + lane scheduling.

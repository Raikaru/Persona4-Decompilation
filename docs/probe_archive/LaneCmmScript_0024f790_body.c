/* Closest clean-C probe for func_0024f790; probe 184 reloc-masked words (v1 432 -> v2 253 -> v3 200 -> v4 184); fnalign retail 496 / object 493 (gap -3), 51 edits + 26 reloc-only. Frame 0x70 vs retail 0x80. Residual is $s1/$s3 swap, extra dsll32/dsra32, FPU ld+ld over-read vs ld+lwc1, sltu, and MAC colouring. Two unproductive rounds (v5 185, v6 tie 184), stop. Production stays ASM; guarded body banked verbatim in src/promoted/cmmScript.c. */

// FUN_0024F790
s32 func_0024f790(u8 *arg0)
{
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 i;
    s32 handle;
    s32 handle2;
    s32 rec;
    s32 tmp;
    s32 res;
    s16 s16a;
    s16 s16b;
    s16 s16c;
    s16 s16d;
    s16 s16e;
    s32 var5;
    s32 randTmp;
    f32 var_f0;
    f32 tmp_f0;
    u32 conv;
    f32 t;
    s64 sa_q;
    f32 sa_f;
    s64 sb_q;
    f32 sb_f;
    f32 out[3];
    u8 *entry;

    switch (*(s32 *)(arg0 + 8)) {
    case 0:
        *(s32 *)(arg0 + 8) = 1;
        *(s32 *)arg0 &= ~8;
        *(s32 *)arg0 &= ~0x80;
        for (i = 0; i < 5; i++) {
            func_0024ba60(i);
        }
        func_0024bb00(0);
        func_0024f080(1, 1);
        randTmp = func_003b7060();
        var_f0 = (f32)(u32)randTmp;
        tmp_f0 = 360.0f * (var_f0 / 2147483648.0f);
        conv = (u32)tmp_f0;
        *(s16 *)(arg0 + 0x1C) = (s16)(conv + 90);
    case 1:
        break;
    default:
        goto done;
    }

    rec = func_00452560(func_00452380(D_00635A78));
    if (rec == 0) {
        func_0046d730(D_006359F0, 0x41B);
    }
    entry = func_00246e90(*(u16 *)(rec + 0x20));
    if ((*(s16 *)(arg0 + 0xC) % 60) == 0) {
        func_0045aeb0(2, D_00635B90);
    }
    s16a = *(s16 *)(arg0 + 0xC) + 1;
    *(s16 *)(arg0 + 0xC) = s16a;
    if ((s16a % 20) == 0) {
        func_00113480(1, 0x50, 1, 0);
    }
    if (*(s16 *)(arg0 + 0x1C) == 0) {
        randTmp = func_003b7060();
        var_f0 = (f32)(u32)randTmp;
        tmp_f0 = 360.0f * (var_f0 / 2147483648.0f);
        conv = (u32)tmp_f0;
        *(s16 *)(arg0 + 0x1C) = (s16)(conv + 90);
        randTmp = func_003b7060();
        var_f0 = (f32)(u32)randTmp;
        tmp_f0 = 3.0f * (var_f0 / 2147483648.0f);
        conv = (u32)tmp_f0;
        s16b = (s16)(conv + 1);
        *(s16 *)(arg0 + 0x1E) = s16b;
        handle = func_00452380(D_00635B38);
        if (handle == 0) {
            func_0046d730(D_006359F0, 0x696);
        }
        *(s32 *)(func_00452560(handle) + 0x28) = s16b;
        *(s32 *)arg0 |= 0x10;
        *(s16 *)(arg0 + 0x22) = 0x19;
    } else {
        *(s16 *)(arg0 + 0x1C) = *(s16 *)(arg0 + 0x1C) - 1;
    }
    if ((*(s32 *)arg0 & 0x10) != 0) {
        var5 = 0;
        s16c = *(s16 *)(arg0 + 0x1E);
        if (s16c == 3) {
            goto case3_24f790;
        }
        if (s16c == 2) {
            goto case2_24f790;
        }
        if (s16c == 1) {
            goto case1_24f790;
        }
        goto join_24f790;
case1_24f790:
        if ((D_008C024E[0] & 0x10) != 0) {
            var5 = 1;
        }
        goto join_24f790;
case2_24f790:
        if ((D_008C024E[0] & 0x80) != 0) {
            var5 = 1;
        }
        goto join_24f790;
case3_24f790:
        if ((D_008C024E[0] & 0x40) != 0) {
            var5 = 1;
        }
join_24f790:
        if (var5 != 0) {
            func_0045af60(0, 0, 4, 3);
            handle = func_00452380(D_00635B38);
            if (handle == 0) {
                func_0046d730(D_006359F0, 0x6A2);
            }
            *(s32 *)(func_00452560(handle) + 0x18) |= 0x10;
            tmp = *(s32 *)arg0 & ~0x10;
            *(s32 *)arg0 = tmp;
            *(s32 *)arg0 = tmp | 0x20;
            *(s16 *)(arg0 + 0x20) = 0;
            *(s16 *)(arg0 + 0x22) = 0;
        } else {
            *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) - 1;
        }
        if (*(s16 *)(arg0 + 0x22) <= 0) {
            *(s32 *)arg0 &= ~0x10;
        }
    }
    if ((*(s32 *)arg0 & 0x20) != 0) {
        s16d = *(s16 *)(arg0 + 0x20) + 1;
        *(s16 *)(arg0 + 0x20) = s16d;
        if (s16d >= 10) {
            *(s32 *)arg0 &= ~0x20;
            *(s16 *)(arg0 + 0x20) = 0;
        }
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) + 2;
    }
    sa_q = *(s64 *)D_00635B68;
    sa_f = *(f32 *)((u8 *)D_00635B68 + 8);
    sb_q = *(s64 *)D_00635B78;
    sb_f = *(f32 *)((u8 *)D_00635B78 + 8);
    t = (f32)*(s32 *)(arg0 + 0x14) / (f32)*(s16 *)(entry + 8);
    out[0] = (*(f32 *)&sb_q - *(f32 *)&sa_q) * t + *(f32 *)&sa_q;
    out[1] = (*(f32 *)((u8 *)&sb_q + 4) - *(f32 *)((u8 *)&sa_q + 4)) * t + *(f32 *)((u8 *)&sa_q + 4);
    out[2] = (sb_f - sa_f) * t + sa_f;
    handle = func_00452380(D_00635A78);
    handle2 = func_00452380(D_00635A78);
    if (handle2 == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    if ((*(s32 *)func_00452560(handle2) & 1) == 0) {
        func_0046d730(D_006359F0, 0x3A6);
    }
    rec = func_00452560(handle);
    if (*(s32 *)(rec + 0xC) != 0) {
        res = func_0025ff60(*(s32 *)(rec + 0xC));
    } else {
        res = 0;
    }
    func_004b1250(res, out);
    if ((D_008C024E[0] & 0x20) != 0) {
        func_00113480(3, 0x79, 3, 0);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) + 1;
    }
    if ((*(s16 *)(arg0 + 0xC) % *(s16 *)(entry + 0xA)) == 0) {
        *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) - 1;
    }
    s16e = *(s16 *)(arg0 + 0xC);
    if (s16e >= 0x1E && *(s32 *)(arg0 + 0x14) >= *(s16 *)(entry + 8)) {
        func_00113480(5, 0xC9, 5, 0);
        *(s32 *)(arg0 + 4) = 2;
        tmp = *(s32 *)arg0 | 8;
        *(s32 *)arg0 = tmp;
        *(s32 *)arg0 = tmp | 0x80;
        func_0024f080(1, 0);
    } else if (s16e >= *(s16 *)(entry + 0xC) || *(s32 *)(arg0 + 0x14) < -10) {
        *(s32 *)(arg0 + 4) = 2;
        *(s32 *)arg0 |= 8;
        func_0024f080(1, 0);
    }
done:
    return 0;
}

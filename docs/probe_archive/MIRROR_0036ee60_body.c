// Best body for func_0036ee60 @0x0036ee60 window 1456B
// probe honest_v1: obj 1400/1456 nd 867 MISMATCH (s16[256]x3 lists + s16 temp/var + u16 counters + s32 locals, honest u16/s16 idioms, for-loops)
// Status: ASM retained; archived per nd>25 gate. Do NOT touch other funcs.
// Notes: obj -56B (14 words) short; frame 0x6D0 vs retail 0x6F0 (-32B, 8 words). Prev s128 attempt 1360B (-96B) worse; honest improves 40B but still short.
// First diffs: word 0 frame (6D0 vs 6F0), 12 arg1 spill (sw 0xCC vs move s6), 17-19 temp_16 coloring (s1 vs s0), 24-25 D_0064E76F lui/addiu (0 vs 0x65: no symbol_data entry for 0x0064E76F, only m2c M2C_UNK), 33+ gp order (offset-first then lw base vs retail base-first lw -0x4C2C then offset; loop-head table local would fix order only), 78+ quadword spills (sq 0xD0/0xC0/lq vs sw/lhu/sh at wrong offsets; no honest C emits lq/sq, banned), plus pervasive s0-s7 rotation (saved-register-count floor like 0036F880) and dead 8-insn 2F0 block at 0x36F2F0-0x36F318 skipped by unconditional b at 0x36F2E8 (m2c also drops; C cannot emit dead bytes past goto, DCEs). Retail shape verified: temp_16 range + var_5/var_3/var_4, 0x100 loop over iGpffffb3d4 (gp-0x4C2C) stride 0xE with &0xDB + lvl + (s16)func_0010aa80==-1 filling 3 lists, 3 Fisher-Yates shuffles via (u16)func_00231d70, tail 0036e920/eb50/ea00/eda0 + min(total,lim) + final 4F0/F0 selection loop. Lint clean, no volatile, no lq/sq in C.
// Live file keeps INCLUDE_ASM + ShuffleCard2 typedef (recon_probe drops inter-marker typedef, so probe bodies must re-append it to compile; archive stores pure func).
s32 func_0036ee60(u8 *arg0, s32 arg1)
{
    extern u8 D_0064E76F[];
    extern u8 *iGpffffb3d4;
    extern s32 func_00104c70(s32);
    s16 list0[256];
    s16 list1[256];
    s16 list2[256];
    s16 temp_16;
    s16 var_5;
    s16 var_3;
    s16 var_4;
    s32 lim_hi;
    s32 lim_lo;
    s32 lvl;
    u16 n0;
    u16 n1;
    u16 n2;
    s32 i;
    s32 n0s;
    s32 n1s;
    s32 n2s;
    s32 total;
    s32 k;
    u16 a;
    u16 b;
    s16 tmp;
    s32 t0;
    s32 t1;
    s32 lim;
    u16 pos;
    u16 idx0;
    s32 out;
    s32 loop;
    s16 v;

    temp_16 = (s16)(func_00104c70(1) & 0xFF);
    if (temp_16 > 0 && (u32)temp_16 < 0xA) {
        var_5 = (s16)D_0064E76F[temp_16];
        var_3 = 1;
    } else {
        s16 aa = (s16)arg1;
        if (temp_16 >= aa) {
            var_5 = (s16)(aa - 5);
            var_3 = (s16)(aa - 10);
        } else {
            var_5 = (s16)(temp_16 - 5);
            var_3 = (s16)(temp_16 - 10);
        }
    }
    var_4 = (s16)(temp_16 + 3);
    if (var_4 >= 0x64) {
        var_4 = 0x63;
    }
    if (var_3 < 0) {
        var_3 = 0;
    }
    if (var_5 < 0) {
        var_5 = 0;
    }
    n0 = 0;
    n1 = 0;
    n2 = 0;
    lim_hi = var_5;
    lim_lo = var_3;
    lvl = var_4;
    for (i = 0; i < 0x100; i++) {
        u8 *e = iGpffffb3d4 + i * 0xE;
        s16 entry;
        if ((*(u16 *)e & 0xDB) != 0) {
            continue;
        }
        entry = (s16)*(e + 3);
        if (lvl < entry) {
            continue;
        }
        if (!((temp_16 < entry) || ((lim_hi >= entry) && (entry >= lim_lo)))) {
            continue;
        }
        if ((s16)func_0010aa80((s16)i) != -1) {
            list0[n0] = (s16)i;
            n0 = (u16)(n0 + 1);
        } else if (temp_16 < entry) {
            list1[n1] = (s16)i;
            n1 = (u16)(n1 + 1);
        } else {
            list2[n2] = (s16)i;
            n2 = (u16)(n2 + 1);
        }
    }
    n1s = n1 & 0xFFFF;
    n2s = n2 & 0xFFFF;
    n0s = n0 & 0xFFFF;
    total = n0s + (n2s + n1s);
    if (total == 0) {
        return 0;
    }
    if (n2s >= 2) {
        for (k = 0; k < n2s; k++) {
            a = (u16)func_00231d70((u32)n2s);
            b = (u16)func_00231d70((u32)n2s);
            if (a != b) {
                tmp = list2[a];
                list2[a] = list2[b];
                list2[b] = tmp;
            }
        }
    }
    if (n1s >= 2) {
        for (k = 0; k < n1s; k++) {
            a = (u16)func_00231d70((u32)(n1 & 0xFFFF));
            b = (u16)func_00231d70((u32)(n1 & 0xFFFF));
            if (a != b) {
                tmp = list1[a];
                list1[a] = list1[b];
                list1[b] = tmp;
            }
        }
    }
    if (n0s >= 2) {
        for (k = 0; k < n0s; k++) {
            a = (u16)func_00231d70((u32)(n0 & 0xFFFF));
            b = (u16)func_00231d70((u32)(n0 & 0xFFFF));
            if (a != b) {
                tmp = list0[a];
                list0[a] = list0[b];
                list0[b] = tmp;
            }
        }
    }
    t0 = func_0036e920((u32)(arg1 & 0xFF));
    *(s32 *)(arg0 + 0x10) = t0;
    t1 = func_0036eb50(t0, arg1 & 0xFF);
    *(s32 *)(arg0 + 0x14) = t1;
    t1 = func_0036ea00(*(s32 *)(arg0 + 0x10), arg1 & 0xFF);
    *(s32 *)(arg0 + 0xC) = t1;
    lim = func_0036eda0(t1);
    if (total < lim) {
        lim = total;
    }
    pos = 0;
    idx0 = 0;
    out = 0;
    for (loop = 0; loop < lim; loop++) {
        (void)func_00231d70(0x64);
        if (pos < (u16)n2s) {
            v = list2[pos];
            pos = (u16)(pos + 1);
        } else if ((u16)(idx0 & 0xFFFF) < (u16)n0s) {
            u16 cur = (u16)(idx0 & 0xFFFF);
            idx0 = (u16)(idx0 + 1);
            v = list0[cur];
        } else {
            continue;
        }
        *(s16 *)(arg0 + out * 2) = v;
        out = out + 1;
    }
    if (out == 0) {
        return 0;
    }
    *(s32 *)(arg0 + 8) = out;
    if (((idx0 & 0xFFFF) == out) && (func_00231d70(0x64) >= 0x14)) {
        return 0;
    }
    return 1;
}

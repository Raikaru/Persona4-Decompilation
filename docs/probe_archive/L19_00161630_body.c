/* BANKED floor func_00161630: obj ~860B vs window 896B (size-under), nd 195.
   See guard note in src/Kosaka/k_encount.c for wins/walls/resume. */
u32 func_00161630(u32 arg1, u32 arg0, u32 arg2, u32 arg3)
{
    u32 result;
    f32 f;
    u16 u2;
    s16 st;
    s8 c;
    u32 u13;
    u32 u11;
    s32 i16;
    s32 i17;
    s32 i12;
    s32 i6;
    s32 i;
    s32 sum;
    u32 m;
    u32 acc;
    u8 b;
    s32 i15;
    u8 *q;
    s32 ret28;

    u32 t = 0xFFFF;
    result = t & 0xFFFF;
    f = 1.0f;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        u2 = *(u16 *)(iGpffffb41c + ((arg2 & 0xFFFF) * 10));
        st = (s16)func_001060b0();
        c = (s8)func_00110960(st, func_001060c0() & 0xFF);
        u13 = (c == 1);
        if (func_00106330(0x1411) == 1) {
            f = 100.0f;
        }
        if (((arg0 & 0xFFFF) == 0x28) || ((arg0 & 0xFFFF) == 0x3C)) {
            if ((arg0 & 0xFFFF) != 0x28) {
                ret28 = func_00106330(0xC0F);
            }
            if (ret28 == 0) {
                f = 0.0f;
            }
        }
        i16 = u2 * 0xF8;
        u11 = *(u8 *)(iGpffffb418 + i16 + u13);
        if (func_00106330(0x1410) == 0) {
            if ((arg3 & 0xFFFF) > 0) {
                u11 += (s32)f * *(u8 *)(iGpffffb418 + i16 + u13 + 2);
            }
            if ((arg3 & 0xFFFF) >= 2) {
                u11 += *(u8 *)(iGpffffb418 + i16 + u13 + 4);
            }
        }
        if (u11 == 0) {
            func_0046d730(D_005F12C8, 0x69);
        }
        m = func_003b7060() % u11;
        b = *(u8 *)(iGpffffb418 + i16 + u13);
        if ((s32)m < (s32)b) {
            i17 = 1;
            i12 = 0;
            i6 = 0x14;
        } else if ((s32)m < (s32)(b + (s32)f * *(u8 *)(iGpffffb418 + i16 + u13 + 2))) {
            i17 = 2;
            i12 = 0x14;
            i6 = 0x19;
        } else {
            i17 = 4;
            i12 = 0x19;
            i6 = 0x1E;
        }
        sum = 0;
        i15 = u13 * 0x78;
        q = iGpffffb418 + i16 + i15;
        for (i = i12; i < i6; i++) {
            if (*(s16 *)(q + i * 4 + 8) != 0) {
                sum += *(u16 *)(q + i * 4 + 10);
            }
        }
        if (sum == 0) {
            return 0xFFFFFFFF;
        }
        m = func_003b7060() % sum;
        acc = 0;
        for (; i12 < i6; i12++) {
            acc += *(u16 *)(iGpffffb418 + i16 + i15 + i12 * 4 + 10);
            if ((s32)m < (s32)acc) {
                result = *(u16 *)(iGpffffb418 + i16 + i15 + i12 * 4 + 8);
                break;
            }
        }
        return (i17 << 16) | (result & 0xFFFF);
    }
    return 0xFFFFFFFF;
}

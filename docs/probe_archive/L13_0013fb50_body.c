/* Closest tested candidate before reverting to INCLUDE_ASM: object 1088B, retail window 1072B, normalized_diff 712. */
void func_0013fb50(u8 *arg0) {
    s16 i;
    s16 j;
    s16 k;
    s16 value;
    f32 f;
    s32 resource0;
    s32 resource1;
    s32 resource2;
    s32 *slot;
    u8 *src;
    u8 *dst;

    func_0043f9c8(arg0, 0, 0x18B0);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)(arg0 + 0) = 0xFF;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = -1;

    i = 0;
    while (i <= 0) {
        *(s16 *)(arg0 + i * 2 + 0x34) = 0;
        i++;
    }

    j = 0;
    while (j < 0x29) {
        src = D_005EDEA0 + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x50) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x54) = *(f32 *)(src + 4);
        f = *(f32 *)(src + 8);
        if (f >= 2147483648.0f) {
            value = (s16)((s32)(f - 2147483648.0f) | 0x80000000);
        } else {
            value = (s16)(s32)f;
        }
        *(s16 *)(dst + 0x60) = value;
        f = *(f32 *)(src + 0xC);
        if (f >= 2147483648.0f) {
            value = (s16)((s32)(f - 2147483648.0f) | 0x80000000);
        } else {
            value = (s16)(s32)f;
        }
        *(s16 *)(dst + 0x66) = value;
        *(u8 *)(dst + 0x5A) = *(u8 *)(src + 0x10);
        j++;
    }

    k = 0;
    while (k < 0x6C) {
        slot = (s32 *)(arg0 + k * 0x14 + 0xFA4);
        *slot = k % 9;
        *(s32 *)((u8 *)slot + 8) = 9;
        *(s32 *)((u8 *)slot + 4) = k / 9;
        *(s32 *)((u8 *)slot + 0xC) = 0xC;
        k++;
    }

    *(s16 *)(arg0 + 0x32) = func_00353c10((s16 *)(arg0 + 0x22));
    resource0 = func_0046a770(D_005E5830);
    if (resource0 == 0) {
        func_0046d730(D_005EF6C8, 0x1EB);
    }
    resource1 = func_0046a770(D_005E5850);
    if (resource1 == 0) {
        func_0046d730(D_005EF6C8, 0x1ED);
    }
    resource2 = func_0046a770(D_005E57F0);
    *(s32 *)(arg0 + 0x1874) = resource2;
    if (resource2 == 0) {
        func_0046d730(D_005EF6C8, 0x1EF);
    }
    if (func_0046a770(D_005E5810) == 0) {
        func_0046d730(D_005EF6C8, 0x1F1);
    }

    k = 0;
    while (k < 0x19) {
        if (k < 3) {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource0, *(u8 *)(D_005EDA00 + k));
        } else if (k < 0x18) {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource1, *(u8 *)(D_005EDA00 + k));
        } else {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource2, *(u8 *)(D_005EDA00 + k));
        }
        if (*slot == 0) {
            func_0046d730(D_005EF6C8, 0x1FD);
        }
        k++;
    }
    *(s32 *)(arg0 + 0x3C) = func_00354a50(0, 1);
    func_00141d80(arg0, 0);
}

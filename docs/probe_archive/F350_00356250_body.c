/* object_size=1376B; window=1488B; normalized_diff=872; first_diffs=136,137,138,139,141-152; candidate short by 112B and archived after index-split/table-base/trampoline probes. */
/* Retail's first 124 bytes match exactly; remaining residual begins at the table-loop preheader (constant materialization/branch shape) and remains broad. */
void func_00356250(u8 *arg0)
{
    extern s32 func_00107180(s16 arg0);
    extern u16 func_00107ac0(s32 arg0);
    extern s32 func_00107c80(s32 arg0);
    extern s32 func_00107ea0(s32 arg0);
    extern s8 func_00248760(s32 arg0);
    extern s32 func_00246970(void);
    extern s32 func_002bc010(s32 arg0, s32 arg1);
    extern void *func_0046a770(const char *arg0);
    extern void func_00359400(u8 *arg0, s32 arg1);
    extern u8 *func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
    extern u8 *func_0035bf10(s32 arg0, u16 arg1, s32 arg2);
    extern u8 D_0064BDA0[];
    extern u8 D_0064CBE0[];
    extern char D_005E57F0[];
    extern char D_005E5810[];
    extern char D_005E5830[];
    extern char D_005E5850[];
    s16 table_idx;
    s16 div_idx;
    s16 input_idx;
    s16 resource_idx;
    s16 count;
    s16 handle_idx;
    s32 id;
    s32 handle0;
    s32 handle1;
    s32 handle2;
    s32 handle3;
    f32 limit;
    u8 *table_base;
    s32 sign_bit;

    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)arg0 = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x14) = 0;
    {
        s16 init_idx;
        for (init_idx = 0; init_idx < 3; init_idx++) {
            *(s16 *)(arg0 + init_idx * 2 + 0x24) = 0;
        }
    }
    table_idx = 0;
    table_base = D_0064BDA0;
    limit = 2147483648.0f;
    sign_bit = 0x80000000;
    goto table_test;
table_body:
    {
        u8 *dst = arg0 + table_idx * 0x30;
        u8 *src = table_base + table_idx * 0x1C;
        f32 x;
        s32 value;
        *(f32 *)(dst + 0x160) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x164) = *(f32 *)(src + 4);
        x = *(f32 *)(src + 8);
        if (x >= limit) {
            value = (s32)(x - limit);
            value |= sign_bit;
        } else {
            value = (s32)x;
        }
        *(u16 *)(dst + 0x170) = (u16)value;
        x = *(f32 *)(src + 0xC);
        if (x >= limit) {
            value = (s32)(x - limit);
            value |= sign_bit;
        } else {
            value = (s32)x;
        }
        *(u16 *)(dst + 0x176) = (u16)value;
        *(u8 *)(dst + 0x16A) = *(u8 *)(src + 0x10);
    }
    table_idx++;
table_test:
    if (table_idx < 43) {
        goto table_body;
    }
    for (div_idx = 0; div_idx < 108; div_idx++) {
        u8 *dst = arg0 + div_idx * 0x14;
        *(s32 *)(dst + 0x964) = div_idx % 9;
        *(s32 *)(dst + 0x96C) = 9;
        *(s32 *)(dst + 0x968) = div_idx / 9;
        *(s32 *)(dst + 0x970) = 12;
    }
    input_idx = 0;
    count = 0;
    while (input_idx < 21) {
        id = func_00107180(input_idx) & 0xFFFF;
        if (id > 0) {
            u8 *dst = arg0 + count * 0xC;
            *(s8 *)(dst + 0x38) = func_00248760(id);
            *(s16 *)(dst + 0x3A) = id;
            *(u16 *)(dst + 0x3C) = func_00107ac0(id);
            if (*(u16 *)(dst + 0x3C) == 10) {
                *(s32 *)(dst + 0x40) = 1;
            } else if (func_00107ea0(id) != 0) {
                *(s32 *)(dst + 0x40) = 3;
            } else if (func_00107c80(id) != 0) {
                *(s32 *)(dst + 0x40) = 2;
            } else {
                *(s32 *)(dst + 0x40) = 0;
            }
            count++;
        }
        input_idx++;
    }
    *(s16 *)(arg0 + 0x134) = count;
    if (count >= 22) {
        func_0046d730(D_0064CC98, 0x1E2);
    }
    handle0 = (s32)func_0046a770(D_005E5830);
    if (handle0 == 0) {
        func_0046d730(D_0064CC98, 0x1E6);
    }
    handle1 = (s32)func_0046a770(D_005E5850);
    if (handle1 == 0) {
        func_0046d730(D_0064CC98, 0x1E8);
    }
    handle2 = (s32)func_0046a770(D_005E5810);
    if (handle2 == 0) {
        func_0046d730(D_0064CC98, 0x1EA);
    }
    handle3 = (s32)func_0046a770(D_005E57F0);
    *(s32 *)(arg0 + 0x1304) = handle3;
    if (handle3 == 0) {
        func_0046d730(D_0064CC98, 0x1EC);
    }
    for (resource_idx = 0; resource_idx < 77; resource_idx++) {
        u8 *dst = arg0 + resource_idx * 4;
        u8 key = D_0064CBE0[resource_idx];
        if (resource_idx < 2) {
            *(s32 *)(dst + 0x11D0) = func_0046d200(handle0, key);
        } else if (resource_idx < 51) {
            *(s32 *)(dst + 0x11D0) = func_0046d200(handle1, key);
        } else if (resource_idx < 52) {
            *(s32 *)(dst + 0x11D0) = func_0046d200(handle3, key);
        } else {
            *(s32 *)(dst + 0x11D0) = func_0046d200(handle2, key);
        }
        if (*(s32 *)(dst + 0x11D0) == 0) {
            func_0046d730(D_0064CC98, 0x1FC);
        }
    }
    func_00359400(arg0, 0);
    func_002bc010(11, func_00246970());
    *(s32 *)(arg0 + 0x1308) = (s32)func_00354a50(0, 1);
    *(u8 **)(arg0 + 0x130C) = func_0035adc0(0, 0, 0);
    *(u8 **)(arg0 + 0x1310) = func_0035bf10(0, 0, 0);
}

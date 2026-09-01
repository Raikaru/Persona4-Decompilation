// FUN_0036D3E0
// Measured source shape preserves the retail callee-saved register allocation.
s32 func_0036d3e0(u8 *arg0) {
    s32 var_17;
    u8 *src1;
    s32 var_19;
    void *temp_20;
    u8 *p0;
    u8 *dst;
    u8 *dst2;
    s32 var_20;
    s32 i;
    s32 i2;
    s32 r;
    s32 c;
    s32 r2;
    s32 c2;
    s32 r3;
    s32 c3;
    s32 r4;
    s32 c4;

    var_17 = 0;
    p0 = arg0;
    var_19 = 0;
    switch (arg0[0x16]) {
    case 0:
        var_19 = 0x20;
        break;
    case 1:
        var_19 = 0x18;
        break;
    case 2:
    case 10:
        var_19 = 0x10;
        break;
    case 19:
    case 27:
        var_19 = 8;
        break;
    case 20:
    case 36:
    case 44:
        var_19 = 4;
        break;
    }
    if (var_19 == 0) {
        func_0046d730(D_0064E4E0, 0x409);
    }
    arg0 += 0x40;
    switch (var_19) {
    case 8:
        src1 = arg0;
        arg0 += (u32)p0[0x10] << 10;
        var_17 |= 1;
        break;
    case 4:
        src1 = arg0;
        arg0 += (u32)p0[0x10] << 6;
        var_17 |= 1;
        break;
    }
    var_20 = 0;
    var_20 |= 4;
    switch (var_19) {
    case 0x20:
        var_20 |= 0x500;
        break;
    case 0x18:
        var_20 |= 0x600;
        break;
    case 8:
        var_20 |= 0x2500;
        break;
    case 4:
        var_20 |= 0x4500;
        break;
    default:
        func_0046d730(D_0064E4E0, 0x431);
        break;
    }
    temp_20 = func_003ec590(*(u16 *)(p0 + 0x12), *(u16 *)(p0 + 0x14), var_19, var_20);
    if (var_17 & 1) {
        dst = func_003ec3d0(temp_20, 1);
        switch (var_19) {
        case 8:
            for (i = 0; i < 0x100; i++) {
                *(s32 *)dst = *(s32 *)src1;
                src1 += 4;
                dst += 4;
            }
            break;
        case 4:
            for (i2 = 0; i2 < 0x10; i2++) {
                *(s32 *)dst = *(s32 *)src1;
                src1 += 4;
                dst += 4;
            }
            break;
        }
        func_003ec2e0(temp_20);
    }
    dst2 = func_003ec6a0(temp_20, 0, 1);
    switch (var_19) {
    case 0x20:
        for (r = 0; r < (s32)*(u16 *)(p0 + 0x14); r++) {
            for (c = 0; c < (s32)*(u16 *)(p0 + 0x12); c++) {
                *(s32 *)dst2 = *(s32 *)arg0;
                arg0 += 4;
                dst2 += 4;
            }
        }
        break;
    case 0x18:
        for (r2 = 0; r2 < (s32)*(u16 *)(p0 + 0x14); r2++) {
            for (c2 = 0; c2 < (s32)*(u16 *)(p0 + 0x12) * 3; c2++) {
                *dst2 = *arg0;
                arg0 += 1;
                dst2 += 1;
            }
        }
        break;
    case 8:
        for (r3 = 0; r3 < (s32)*(u16 *)(p0 + 0x14); r3++) {
            for (c3 = 0; c3 < (s32)*(u16 *)(p0 + 0x12); c3++) {
                *dst2 = *arg0;
                arg0 += 1;
                dst2 += 1;
            }
        }
        break;
    case 4:
        for (r4 = 0; r4 < (s32)*(u16 *)(p0 + 0x14); r4++) {
            for (c4 = 0; c4 < (s32)*(u16 *)(p0 + 0x12) >> 3; c4++) {
                *(s32 *)dst2 = *(s32 *)arg0;
                arg0 += 4;
                dst2 += 4;
            }
        }
        break;
    }
    func_003ec2a0(temp_20);
    return (s32)temp_20;
}

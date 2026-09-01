/* object 688B; retail window 688B; normalized_diff 84; differing offsets 0xDC,0xEC,0xF0,0xF4,0x104,0x108,0x110,0x114,0x118,0x11C,0x120,0x124,0x128,0x12C,0x130,0x140,0x144,0x148,0x14C,0x150,0x154,0x158,0x15C,0x160,0x164,0x168,0x16C,0x170,0x174,0x178,0x17C,0x180,0x184,0x1AC,0x1B0,0x1BC,0x1C4,0x1D0,0x1D8,0x1DC,0x1E0,0x1E8,0x1EC,0x1F0,0x1F4,0x1F8,0x1FC,0x200,0x204,0x208,0x20C,0x210,0x214,0x218,0x21C,0x220,0x224,0x228,0x22C,0x230,0x234,0x238,0x23C,0x240,0x244,0x248,0x24C,0x250,0x254,0x258,0x25C,0x260,0x264,0x268,0x26C,0x270,0x274,0x278,0x27C,0x280,0x284,0x288,0x28C,0x290,0x294,0x298,0x29C,0x2A0,0x2A4; casts at retail 0x40 and 0x1C4: (f32)(u32)t; no signed conversion sites; ruled out packed u32 table, named entry/low pointers, loop/goto reshapes, pointer reuse, declaration-order/type variants, guard/pragma and callee declaration changes. */
s32 func_0011e490(u8 *arg0)
{
    u8 *q;
    u8 *r;
    u8 *p16;
    u16 *work;
    s32 stack[8];
    f32 f;
    s32 t;
    s32 i;
    s32 count;
    s32 found1;
    s32 found2;
    s32 j;
    s32 idx;

    q = *(u8 **)(arg0 + 0x1C);
    r = *(u8 **)(q + 0x38);
    p16 = *(u8 **)r;
    if (!(*(u16 *)p16 & 4)) {
        return 0;
    }
    t = func_003b7060() & 0x1000;
    f = (f32)(u32)t;
    f = 100.0f * f / 4096.0f;
    if (!(f < 0.0f)) {
        return 0;
    }
    work = (u16 *)func_001094d0((s32)p16);
    i = 0;
    count = 0;
    for (; iGpffffb3ec[2 * i] != 0; i++) {
        found1 = 0;
        for (j = 0; j < 8; j++) {
            if (work[j] != 0 && iGpffffb3ec[2 * i] == work[j]) {
                found1 = 1;
                break;
            }
        }
        if (found1 == 0) {
            continue;
        }
        found2 = 0;
        for (j = 0; j < 8; j++) {
            if (work[j] != 0 && iGpffffb3ec[2 * i + 1] == work[j]) {
                found2 = 1;
                break;
            }
        }
        if (found2 != 0) {
            continue;
        }
        stack[count] = i;
        count++;
    }
    if (count <= 0) {
        return 0;
    }
    t = func_003b7060() & 0xFFF;
    f = (f32)(u32)t;
    f = (f32)count * f / 4096.0f;
    idx = (s32)f;
    if (!(idx < count)) {
        func_0046d730(D_005E4868, 0x12CF);
    }
    i = stack[idx];
    *(u16 *)(arg0 + 6) = iGpffffb3ec[2 * i];
    *(u16 *)(arg0 + 8) = iGpffffb3ec[2 * i + 1];
    return 1;
}

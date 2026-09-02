// FUN_002B6340 archive (wave Io lane IoB cut off mid-work; body is the live state at cutoff, status MISMATCH-nd132).
extern f32 fGpffff84f4;
/* measured: probe target local propagation ordering. */
#pragma push
/* measured: probe schedule off. */
#pragma schedule off
s32 func_002b6340(u8 *arg0) {
    u8 *p;
    u8 *q;
    s32 color;
    u8 alpha;
    s16 x;
    s32 base;
    s32 mode;
    s16 y;
    s16 z;
    u8 *table;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;

    p = *(u8 **)(arg0 + 0x38);
    func_0043f810(p + 0x10, func_002b89a0(p + 0x10), 0xF0);
    if (*(u8 *)(p + 0x6E) <= 0) {
        return 0;
    }
    if (*(f32 *)(p + 0xA0) <= fGpffff84f4) {
        return 0;
    }
    if (*(f32 *)(p + 0xAC) <= fGpffff84f4) {
        return 0;
    }
    if (func_002b6820(arg0, 0) == 1) {
        if (func_002b6820(arg0, 0xD) == 1) {
            q = func_00460990();
            *(void **)(q + 8) = (void *)func_002b6180;
            *(s32 *)(q + 0x10) = 0;
            func_00460ac0(D_00793E80 + *(s32 *)(p + 8) * 0x30, q);
            func_0025ecd0(
                (color = func_002b2a30(0xFF, *(u8 *)(p + 0x85),
                                        *(u8 *)(p + 0x86), *(u8 *)(p + 0x87))),
                (alpha = *(u8 *)(p + 0x6E)), (x = *(s16 *)(p + 4)),
                (base = *(s32 *)(p + 0)), (mode = 0), (y = *(s16 *)(p + 0xC)),
                (z = *(s16 *)(p + 0xE)),
                (table = D_00793E80 + *(s32 *)(p + 8) * 0x30),
                (f0 = *(f32 *)(p + 0x38)), (f1 = *(f32 *)(p + 0x3C)),
                (f2 = *(f32 *)(p + 0x14)), (f3 = *(f32 *)(p + 0xD0)),
                (f4 = *(f32 *)(p + 0xA0)), (f5 = *(f32 *)(p + 0xAC)));
        } else {
            func_0025ecd0(
                (color = func_002b2a30(0xFF, *(u8 *)(p + 0x85),
                                        *(u8 *)(p + 0x86), *(u8 *)(p + 0x87))),
                (alpha = *(u8 *)(p + 0x6E)), (x = *(s16 *)(p + 4)),
                (base = *(s32 *)(p + 0)), (mode = 1), (y = *(s16 *)(p + 0xC)),
                (z = *(s16 *)(p + 0xE)),
                (table = D_00793E80 + *(s32 *)(p + 8) * 0x30),
                (f0 = *(f32 *)(p + 0x38)), (f1 = *(f32 *)(p + 0x3C)),
                (f2 = *(f32 *)(p + 0x14)), (f3 = *(f32 *)(p + 0xD0)),
                (f4 = *(f32 *)(p + 0xA0)), (f5 = *(f32 *)(p + 0xAC)));
        }
    }
    return 0;
}
#pragma pop

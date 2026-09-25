/* func_00324680 draft: 15 differing words reloc-masked (2304-byte window, size exact).
   Residual: second-loop counter and its (s16) copy take swapped saved registers
   (retail counter $s0 / copy $s3).  Expects the unit's file-scope
   func_00316470(u8 *, s64, s64).  See FclDraw_0031c2b0_0031cce0_20260925.md. */
// FUN_00324680
void func_00324680(u8 *arg0, s64 arg1, s64 arg2) {
    extern FclVec2 func_002b2970(f32, f32);
    typedef union { FclByte4 channels; u32 word; } PackedColor;
    extern f32 D_006443D8[];
    extern void func_002b6c30(s16, FclVec2, f32, s32);
    extern void func_0031e5b0(u8 *, FclVec2, s32, s64, s32, s32, s32);
    extern void func_003191c0(u8 *, FclVec2, s32, s32, s32, s32, s64, s32);
    extern void func_0031ac10(u8 *, FclVec2, s8, u16, s32, s32, s32, s64, s8, u8);
    FclByte4 c11C;
    FclByte4 c118;
    PackedColor c114;
    FclByte4 c110;
    FclByte4 c10C;
    FclByte4 c108;
    FclByte4 c104;
    FclByte4 c100;
    FclByte4 cFC;
    FclByte4 cF8;
    s16 a;
    s16 k;
    s16 i;
    s32 m;
    u8 *p;
    u8 *t;
    FclVec2 *v;

    t = *(u8 **)(arg0 + 0x38);
    func_00316470(arg0, 0, arg2);
    func_0031e5b0(arg0, func_002b2970(6.0f, 104.0f), 0, arg2, 0, 1, 2);
    func_0031e5b0(arg0, func_002b2970((f32)315, 104.0f), 0, arg2, 1, 0, 0);
    i = 0;
    m = (s16)arg1;
    for (; i < 12; i++) {
        func_003191c0(arg0, func_002b2970((f32)315, 128.0f), (s8)i, *(u16 *)(func_002e48a0(0, i) + 2),
                      *(u8 *)(func_002e48a0(0, i) + 4), (s16)(i * m), arg2,
                      *(s8 *)(func_002e4870(0) + 8));
    }
    func_0031ac10(arg0, func_002b2970(6.0f, 195.0f), 0, 0, *(u16 *)(func_002e48a0(1, 0) + 2),
                  *(u8 *)(func_002e48a0(1, 0) + 4), 0, arg2, 0, 0xCC);
    if ((s8)arg2 == 0) {
        u8 *p297;
        u8 *p28B;
        u8 *p27D;
        c11C = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        p297 = func_002b6150(0x297);
        *(FclByte4 *)(p297 + 0x85) = c11C;
        p28B = func_002b6150(0x28B);
        *(FclByte4 *)(p28B + 0x85) = *(FclByte4 *)(p297 + 0x85);
        p27D = func_002b6150(0x27D);
        *(FclByte4 *)(p27D + 0x85) = *(FclByte4 *)(p28B + 0x85);
        p = func_002b6150(0x270);
        *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
        c118 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2A3);
        *(FclByte4 *)(p + 0x85) = c118;
        c114.channels = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s16)(i + 0xC), c114.word);
    }
    v = (FclVec2 *)D_006440F8;
    func_002b6c30(0x71, func_002b2970(v->x, v->y), 138.0f, 0x41);
    c110 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0x71) + 0x85) = c110;
    {
        s32 off = (1 - (s8)arg2) * 0xFF;
        s32 on = (s8)arg2 * 0xFF;
        func_002b6a70(0x71, on, off, 0, 0, 0);
        v = (FclVec2 *)D_006440F0;
        func_002b6c30(0x70, func_002b2970(v->x, v->y), 139.0f, 0x41);
        c10C = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x70) + 0x85) = c10C;
        func_002b6a70(0x70, on, off, 0, 0, 0);
        for (k = 0; k < 2; k++) {
            v = (FclVec2 *)D_00644290;
            a = k + 0x2BB;
            func_002b6c30(a, func_002b2970(v->x + (f32)(k * 0x139), v->y), 140.0f, 0x41);
            c108 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
            *(FclByte4 *)(func_002b6150(a) + 0x85) = c108;
            func_002b6a70(a, on, off, 0, 0, 0);
            v = (FclVec2 *)D_00644298;
            a = k + 0x2BD;
            func_002b6c30(a, func_002b2970(v->x + (f32)(k * 0x14A), v->y), 141.0f, 0x41);
            c104 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
            *(FclByte4 *)(func_002b6150(a) + 0x85) = c104;
            func_002b6a70(a, on, off, 0, 0, 0);
            v = (FclVec2 *)D_00644350;
            a = k + 0x2BF;
            func_002b6c30(a, func_002b2970(v->x + (f32)(k * 0xE), v->y), 142.0f, 0x41);
            c100 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
            *(FclByte4 *)(func_002b6150(a) + 0x85) = c100;
            func_002b6a70(a, on, off, 0, 0, 0);
        }
    }
    {
        v = (FclVec2 *)D_00644350;
        func_002b6c30(0xBC, func_002b2970(28.0f + v->x, v->y), 142.0f, 0x41);
        cFC = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0xBC) + 0x85) = cFC;
        func_002b6a70(0xBC, (s8)arg2 * 0xFF, (1 - (s8)arg2) * 0xFF, 0, 0, 0);
        v = (FclVec2 *)D_006443D8;
        func_002b6c30(0xCD, func_002b2970(v->x, v->y), 143.0f, 0x41);
        func_002b6a70(0xCD, (s8)arg2 * 0xFF, (1 - (s8)arg2) * 0xFF, 1, 0xF, 0);
    }
    cF8 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0xCD) + 0x85) = cF8;
}

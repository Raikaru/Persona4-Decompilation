/* Research only; production func_002fbea0 remains INCLUDE_ASM (see
 * FclCombine_002fbea0_20260925.md). The guarded draft did not compile;
 * this body compiles and its cases are in retail layout order. Object 7079
 * vs retail 6580 instrs; per-case aligned edits 2963. */
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA9];
    s8 fB7;
    u8 padB8[0x66];
    s16 f11E;
    s16 f120;
    s8 f122;
    s8 f123;
    f32 f124;
    s8 f128;
    s8 f129;
    u8 pad12A[0x10];
    s8 f13A;
    u8 pad13B[0xD];
    u8 * f148;
    u8 pad14C[0x108];
    s32 f254;
    u8 pad258[0x34];
    s32 f28C;
    s32 f290;
    u8 pad294[0x18];
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    u8 pad2C0[0x60];
} FclCombineSel;

void func_002fbea0(u8 *arg0) {
    extern void func_00315600(u8 *, s32);
    extern void func_002e4610(s32, s8);
    extern s32 datGetFlag(s32);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s64);
    extern u8 *func_002b6150(s16);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b68d0(s16, s32, s32);
    extern void func_002ba970(s32, s8, s32);
    extern s8 func_002bab80(void *);
    extern void func_002badc0(s8, s32);
    extern s32 func_00331660(void);
    extern void func_0032b770(u8 *, s32, s32, s32);
    extern void func_0032b9d0(u8 *, s32, s32, s32);
    extern void func_002e68b0(s32);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_00314560(u8 *, u16 *, s32, s32);
    extern u8 *func_003147d0(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011d140(u8 *, s32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern void func_002bb550(s8);
    extern void func_00314670(u8 *, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern void func_0032f4d0(u8 *);
    extern void func_003205f0(u8 *, s32, s32);
    extern s32 func_00302570(u8 *);
    extern s8 func_00314660(u8 *);
    extern void func_002b2970(s64 *, f32, f32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern void func_0045af60(s32, s32, s32, s32);
    extern void func_0032c480(u8 *);
    extern s8 *func_0034a630(s32);
    extern void func_0011d1d0(u8 *, f32);
    extern s8 func_002bb1c0(s8);
    extern void func_0010fd40(void *);
    extern void func_00314750(u8 *, s32);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_00275820(s32, s32, s32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern u8 *iGpffffb440;
    extern u8 D_00795E60[];
    extern s32 func_0010b190(u8 *);
    extern s32 func_001099f0(u16 *, s32);
    extern s32 func_003026c0(s32, s32);
    extern s32 func_002e7a60(void);
    extern void func_002e7a80(s32);
    extern void func_002bbd80(s8, s32, void *);
    extern s32 func_00349290(u8 *, s8);
    extern void func_002cacd0(u64, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32);
    extern void *func_0046a770(void *);
    extern s32 func_00331560(void);
    extern u8 D_00641B30[];
    extern u8 func_00109280(s32);
    extern void func_002ba5d0(u8 *, s32, s32, s64, s32, s64, f32);
    extern void func_0032c0c0(u8 *, s32);
    extern void func_002bafc0(s8, s32);
    extern void func_002bb0a0(s8, s32);
    extern void func_002bbf60(void);
    extern void func_0031ac10(u8 *, s64, s8, s8, u16, u8, s32, s32, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_00324f80(u8 *arg0, s64, s32, s32);
    extern void func_003297f0(u8 *, s32, s32, f32, f32);
    extern u16 D_008C0276[];
    extern u16 D_008C027A[];
    extern s32 func_0011c610(u8 *);
    extern void func_0011caf0(u8 *);
    extern u16 *func_0010fcb0();
    extern s32 func_0011ba00(u8 *);
    extern void func_00314740(u8 *, s8);
    extern void sprintf(void *dst, void *fmt, s32 value);
    extern char iGpffffa8a4;
    extern u16 D_008C0252[];
    extern void func_0032a960(u8 *, s32);
    extern void func_002b5e90(s32, s64, s64, s32);
    extern void func_002b5ef0(s32, s64, s64, void *, void *, s32);
    extern void func_002b60f0(s32, s32, s32, s32);
    extern void func_00317320(u8 *, s32, s32);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00317240(u8 *, s64, s32);
    extern void func_0034a890(s32);
    extern void func_0034a840(s32);

    FclCombineSel *p;
    u8 slotByte;
    s8 partyCount;
    u8 state;
    s16 var_16;
    s16 var_16_2;
    s16 var_16_5;
    s16 base;
    s8 tmp8;
    u8 *r2;
    u8 *r3;
    u8 *r4;
    u8 *r5;
    u8 *r6;
    u8 *ps;
    u8 col0;
    u8 col1;
    u8 col2;
    u8 col3;
    u8 colB0;
    u8 colB1;
    u8 colB2;
    u8 colB3;
    u8 colC0;
    u8 colC1;
    u8 colC2;
    u8 colC3;
    u8 c0;
    u8 c1;
    s64 sp440;
    s64 sp438;
    s64 var_16_6;
    s16 var_18;
    s16 var_19;
    s64 var_22;
    s64 temp_16;
    s64 temp_21;
    f32 temp_f20;
    f32 temp_f0;
    s32 var_3;
    s32 temp_7;
    s32 var_21;
    s32 sumA;
    s32 sumB;
    s32 total;
    s32 saved;
    u16 bitSav;
    s64 sp308;
    s32 colW1;
    s64 sp300;
    s32 colW2;
    s32 tmpe;
    s32 tmpv;
    s64 tmp22;
    s64 tmp21F;
    u8 d0;
    u8 d1;
    u8 d2;
    u8 d3;
    s64 sp318;
    s32 colW3;
    s64 sp310;
    s32 colW4;
    u8 w498[4];
    u8 w494[4];
    s32 w490;
    u8 w48C[4];
    u8 w488[4];
    u8 w484[4];
    s32 w480;
    u8 w47C[4];
    u8 w478[4];
    s64 sp460;
    s32 colW5;
    s32 tmpu8;
    u8 w4E0[4];
    u8 w4DC[4];
    s32 w4D8;
    u8 w4D4[4];
    u8 w4D0[4];
    u8 w4CC[4];
    s32 w4C8;
    s64 sp458;
    s64 sp450;
    s64 sp448;

    s64 sp430;
    s64 sp428;
    u8 sp2A0[64];
    s64 sp3C8;
    s64 sp3C0;
    s64 sp3B8;
    s64 sp3B0;
    s64 sp3A8;
    s64 sp3A0;
    s64 sp398;
    s64 sp390;
    s64 sp210;
    s64 sp200;
    s64 sp388;
    s64 sp380;
    s64 sp378;
    s64 sp370;
    s64 sp368;
    s64 sp360;
    s64 sp358;
    s64 sp350;
    s64 sp1F0;
    s64 sp1E0;
    s64 sp348;
    s64 sp340;
    s64 sp338;
    s64 sp330;
    s64 sp328;
    s64 sp320;
    s64 sp1D0;
    s64 sp1C0;
    u8 sp220[64];
    s64 sp420;
    s32 colW6;
    s64 sp418;
    s32 colW7;
    s64 sp410;
    s16 sp1B0;
    u8 w4C0[4];
    u8 w4BC[4];
    s32 w4B8;
    u8 w4B4[4];
    u8 w4B0[4];
    u8 w4AC[4];
    s32 w4A8;
    u8 w4A4[4];
    u8 w4A0[4];
    s64 sp3E8;
    s64 sp3E0;
    s64 sp3D8;
    s64 sp3D0;
    p = *(FclCombineSel **)(arg0 + 0x38);
    state = p->f1;
    switch (state) {
    case 0x8A:
        func_00315600(arg0, 1);
        if (p->f0 == 0x10) {
            func_002e4610(6, 0);
        } else if (p->f0 == 0xF) {
            if (datGetFlag(0x1460) != 0) {
                func_002e4610(8, 0);
            } else {
                func_002e4610(2, 0);
            }
        }
        p->f11E = 0;
        p->f120 = 0;
        p->f129 = -1;
        p->f128 = -1;
        p->f123 = 0;
        p->f1 = 0x8B;
        return;
    case 0x8B:
        if (*(s8 *)func_002e4870(0) == 0) {
            return;
        }
        var_16 = 0;
        while ((s16)(var_16) < (s64)(p->fB7)) {
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(var_16 * 2 + 0x1F8)) + 0x10), 1) == 1) {
                return;
            }
            var_16 = (s64)((var_16 + 1) << 0x30) >> 0x30;
        }
        var_16_2 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_2 = 8;
            p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
        }
        if (p->f0 == 0x10) {
            if (*(s32 *)(func_002e4870(0) + 8) == 0) {
                tmp8 = func_002bab80((void *)func_00331660());
                p->fD = tmp8;
                func_002badc0(tmp8, 0xE);
                p->f1 = 0x93;
            } else {
                func_0032b770(arg0, 2, var_16_2, 0);
                p->f1 = 0x8D;
            }
        } else if (p->f0 == 0xF) {
            p->f123 = 0;
            if (datGetFlag(0x1460) == 0) {
                func_002e68b0(0);
            }
            func_0032b9d0(arg0, 2, var_16_2, 0);
            p->f1 = 0x98;
        }
        base = p->f11E;
        *(s8 *)(func_002b6150((s16)(base + 0x27D)) + 0x6E) = -1;
        *(s8 *)(func_002b6150((s16)(base + 0x270)) + 0x6E) = -1;
        func_002b68d0(0x270, 2, 1);
        func_002b68d0(0x27D, 2, 1);
        fclWriteColorBytes((u8 *)(&col0), 0xCC, 0xFF, 0x33, 0xFF);
        r2 = func_002b6150((s16)(base + 0x297));
        *(r2 + 0x85) = col0;
        *(r2 + 0x86) = col1;
        *(r2 + 0x87) = col2;
        *(r2 + 0x88) = col3;
        r3 = func_002b6150((s16)(base + 0x28B));
        c0 = *(r2 + 0x85);
        c1 = *(r2 + 0x86);
        *(r3 + 0x85) = c0;
        *(r3 + 0x86) = c1;
        *(r3 + 0x87) = *(r2 + 0x87);
        *(r3 + 0x88) = *(r2 + 0x88);
        r4 = func_002b6150((s16)(base + 0x27D));
        c0 = *(r3 + 0x85);
        c1 = *(r3 + 0x86);
        *(r4 + 0x85) = c0;
        *(r4 + 0x86) = c1;
        *(r4 + 0x87) = *(r3 + 0x87);
        *(r4 + 0x88) = *(r3 + 0x88);
        r5 = func_002b6150((s16)(base + 0x270));
        *(r5 + 0x85) = *(r4 + 0x85);
        *(r5 + 0x86) = *(r4 + 0x86);
        *(r5 + 0x87) = *(r4 + 0x87);
        *(r5 + 0x88) = *(r4 + 0x88);
        fclWriteColorBytes((u8 *)(&colB0), 0x2D, 0x2D, 0x2D, 0xFF);
        r6 = func_002b6150((s16)(base + 0x2A3));
        *(r6 + 0x85) = colB0;
        *(r6 + 0x86) = colB1;
        *(r6 + 0x87) = colB2;
        *(r6 + 0x88) = colB3;
        fclWriteColorBytes((u8 *)(&colC0), 0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(p->f2BC, (s8)(base + 0xC), (s32)colC0);
        return;
    case 0x8D:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW5, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW5, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            tmpu8 = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
            func_002b2970(&sp460, 146.0f, 111.0f + 23.0f * (f32)var_19);
            func_002ba5d0((u8 *)p->f2BC, (s8)(temp_16 + 0xC), tmpu8, sp460, colW5, 0x59, 46.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(tmp22)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s16)(tmp22)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x10), 1) == 0) {
                if (p->f11E == var_19) {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x27D))) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -1;
                    fclWriteColorBytes(w4E0, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w4E0[0];
                    d1 = w4E0[1];
                    d2 = w4E0[2];
                    d3 = w4E0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)(temp_21));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4DC, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w4DC[0];
                    d1 = w4DC[1];
                    d2 = w4DC[2];
                    d3 = w4DC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4D8, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w4D8);
                } else {
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -128;
                    fclWriteColorBytes(w4D4, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = w4D4[0];
                    d1 = w4D4[1];
                    d2 = w4D4[2];
                    d3 = w4D4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(temp_21));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w4D0, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w4D0[0];
                    d1 = w4D0[1];
                    d2 = w4D0[2];
                    d3 = w4D0[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4CC, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w4CC[0];
                    d1 = w4CC[1];
                    d2 = w4CC[2];
                    d3 = w4CC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4C8, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w4C8);
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((s16)((var_16_6 + 0x26F))) + 0x10), 1) == 1) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0032c0c0(arg0, 1);
            return;
        } else if (D_008C0276[0] & 0x4000) {
            if (p->f13A != 0) {
                break;
            }
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 3);
            return;
        } else if (D_008C024E[0] & 0x40) {
            if (p->f11E < *(s32 *)(func_002e4870(0) + 8)) {
                p->f122 = 0;
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b770(arg0, 0, var_16_2, 1);
                p->f1 = 0x8E;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                tmp8 = func_002bab80((void *)func_00331660());
                p->fD = tmp8;
                func_002bafc0(tmp8, 0);
                func_002badc0(p->fD, 0xC);
                func_002bb0a0(p->fD, 0);
                func_002bbf60();
                p->f1 = 0x96;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            var_19 = (s64)(p->f11E - p->f120);
            var_18 = 0;
            var_22 = var_16_6 + var_19;
            while ((s16)(var_19) < var_22) {
                func_002b2970(&sp458, 162.0f, 111.0f);
                slotByte = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
                func_0031ac10(arg0, sp458, -1, var_18, *(u16 *)((u8 *)func_002e48a0(0, var_19) + 2), slotByte, 0, 1, 0, 0xCC);
                var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
                var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
            }
            func_002b2970(&sp450, 156.0f, 87.0f);
            func_0031e5b0(arg0, sp450, 0, 1, 0, 1, 1);
            func_002b2970(&sp448, 472.0f, 112.0f);
            func_00324f80(arg0, sp448, 0, 1);
            func_003297f0(arg0, 0, 1, (f32)0x1A1, 220.0f);
            p->f1 = 0x94;
            func_0045af60(0, 0, 0, 2);
        }
        p->f13A = 0;
        break;
    case 0x95:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            var_16_2 = *func_002e48a0(0, p->f11E);
            if (*func_002e48a0(0, p->f11E) & 4) {
                *func_002e48a0(0, p->f11E) = 0;
                *func_002e48a0(0, p->f11E) |= 1;
                func_0010fd40(func_002e48a0(0, p->f11E));
                *func_002e48a0(0, p->f11E) = var_16_2;
            } else {
                func_0010fd40(func_002e48a0(0, p->f11E));
            }
            func_002bb550(p->fD);
            tmp8 = func_002bab80((void *)func_00331660());
            p->fD = tmp8;
            func_002badc0(tmp8, 0xD);
            p->f1 = 0x91;
            return;
        }
        p->f1 = 0x8F;
        func_002bb550(p->fD);
        return;
    case 0x96:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            var_18 = 0;
            while ((s16)(var_18) < *(s32 *)(func_002e4870(0) + 8)) {
                bitSav = *func_002e48a0(0, var_18);
                if (*func_002e48a0(0, var_18) & 4) {
                    *func_002e48a0(0, var_18) = 0;
                    *func_002e48a0(0, var_18) |= 1;
                    func_0010fd40(func_002e48a0(0, var_18));
                    *func_002e48a0(0, var_18) = bitSav;
                } else {
                    func_0010fd40(func_002e48a0(0, var_18));
                }
                var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
            }
            func_002bb550(p->fD);
            tmp8 = func_002bab80((void *)func_00331660());
            p->fD = tmp8;
            func_002badc0(tmp8, 0xD);
            p->f1 = 0x92;
            func_0032b770(arg0, 0, var_16_6, 1);
            return;
        }
        p->f1 = 0x8D;
        func_002bb550(p->fD);
        return;
    case 0x8E:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_002b6140((u8 *)(p->f28C), 1);
            func_002b6140((u8 *)(p->f290), 1);
            func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
            func_0011c6e0(func_003147d0(p->f148), 1);
            func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 0, 0);
            p->f1 = 0x8F;
            return;
        }
        break;
    case 0x8F:
        if ((s8)func_00314660(p->f148) != 5) {
            break;
        }
        if (func_0011c610(func_003147d0(p->f148)) == 1) {
            func_0011caf0(func_003147d0(p->f148));
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 5);
                if (p->f122 == 0) {
                    func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                if (p->f11E != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 1);
                if (p->f122 == 0) {
                    func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0276[0] & 1) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 5);
            if (p->f122 == 0) {
                func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 4);
                if (p->f122 == 0) {
                    func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 0);
                if (p->f122 == 0) {
                    func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0252[0] & 2) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 4);
            if (p->f122 == 0) {
                func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            if (p->f122 == 0) {
                func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if (D_008C024E[0] & 8) {
            if (p->f122 == 1) {
                p->f122 = 0;
                ps = func_002b6150(0x150);
                func_002b2970(&sp440, (f32)0x141, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp440, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp438, (f32)0x141, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp438, 1, 4, 0);
                func_00314560(p->f148, func_002e48a0(0, p->f11E), 0, 1);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 4) {
            if (p->f122 == 0) {
                p->f122 = 1;
                ps = func_002b6150(0x150);
                func_002b2970(&sp430, 107.0f, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp430, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp428, 107.0f, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp428, 1, 4, 0);
                func_00314560(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 0);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 0x40) {
            tmp8 = func_002bab80((void *)func_00331660());
            p->fD = tmp8;
            sprintf(&sp2A0, &iGpffffa8a4, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11));
            func_002bbd80(p->fD, 0, &sp2A0);
            func_002bafc0(tmp8, 0);
            func_002badc0(p->fD, 0xB);
            func_002bb0a0(p->fD, 0);
            func_002bbf60();
            p->f1 = 0x95;
            func_0045af60(0, 0, 0, 1);
            goto conv8F;
        } else if (D_008C024E[0] & 0x20) {
            if (func_0011ba00(func_003147d0(p->f148)) == 1) {
                break;
            }
            if (func_0011c610(func_003147d0(p->f148)) == 1) {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(func_003147d0(p->f148), 1);
            } else {
                func_00314670(p->f148, 3);
                func_00325450(arg0, 0, 1);
                p->f1 = 0x90;
                func_0045af60(0, 0, 0, 2);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                func_0011c630(func_003147d0(p->f148));
                func_00314740(func_003147d0(p->f148), 0);
            } else {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(func_003147d0(p->f148), 1);
            }
        }
    conv8F:
        p->f13A = 0;
        break;
    case 0x90:
        if (((s8)func_00314660(p->f148) < 0 || (s8)func_00314660(p->f148) >= 6) && *(s8 *)func_002e4870(0) != 0) {
            var_16_5 = *(s16 *)(func_002e4870(0) + 8);
            if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                var_16_5 = 8;
            }
            if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
            }
            func_002b6140((u8 *)(p->f28C), 0);
            func_002b6140((u8 *)(p->f290), 0);
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                func_0032b770(arg0, 0, var_16_5, 0);
                p->f11E = 0;
                p->f120 = 0;
                p->f1 = 0x8B;
                return;
            }
            tmp8 = func_002bab80((void *)func_00331660());
            p->fD = tmp8;
            func_002badc0(tmp8, 0xE);
            p->f1 = 0x93;
            return;
        }
        break;
    case 0x91:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_00314670(p->f148, 3);
        func_00325450(arg0, 0, 1);
        func_002e4610(6, 0);
        p->f1 = 0x90;
        return;
    case 0x92:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x93:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x97:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        if (func_00302570(arg0) == 0) {
            if ((s8)func_00314660(p->f148) == 5) {
                func_00314670(p->f148, 3);
                func_00325450(arg0, 0, 1);
            }
            p->f1 = 0x8D;
            return;
        }
        break;
    case 0x94:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == temp_16) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x118);
            func_00315600(arg0, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x98:
        func_002b2970(&sp420, 250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW6, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp420, colW6, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW7, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW7, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(tmp22)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s16)(tmp22)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            sp1B0 = (s8)(temp_16 + 0xC);
            tmpu8 = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
            func_002b2970(&sp418, 74.0f, 151.0f + 23.0f * (f32)var_18);
            func_002ba5d0((u8 *)p->f2BC, sp1B0, tmpu8, sp418, colW7, 0x59, 46.0f);
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp410, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp410, colW7, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x10), 1) == 0) {
                if (p->f11E == var_19) {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x27D))) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -1;
                    fclWriteColorBytes(w4C0, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w4C0[0];
                    d1 = w4C0[1];
                    d2 = w4C0[2];
                    d3 = w4C0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)(temp_21));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4BC, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w4BC[0];
                    d1 = w4BC[1];
                    d2 = w4BC[2];
                    d3 = w4BC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4B8, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w4B8);
                } else {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x27D))) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -128;
                    fclWriteColorBytes(w4B4, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = w4B4[0];
                    d1 = w4B4[1];
                    d2 = w4B4[2];
                    d3 = w4B4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(temp_21));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w4B0, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w4B0[0];
                    d1 = w4B0[1];
                    d2 = w4B0[2];
                    d3 = w4B0[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4AC, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w4AC[0];
                    d1 = w4AC[1];
                    d2 = w4AC[2];
                    d3 = w4AC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4A8, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w4A8);
                }
            }
            tmp21F = temp_16 + 0x21F;
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(tmp21F)) + 0x10), 1) == 0) {
                if (p->f11E == var_19) {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x2C5))) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s16)(tmp21F)) + 0x6E) = -1;
                    fclWriteColorBytes(w4A4, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x2C5)));
                    d0 = w4A4[0];
                    d1 = w4A4[1];
                    d2 = w4A4[2];
                    d3 = w4A4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(tmp21F));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                } else {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x2C5))) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s16)(tmp21F)) + 0x6E) = -128;
                    fclWriteColorBytes(w4A0, 0, 0, 0x99, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x2C5)));
                    d0 = w4A0[0];
                    d1 = w4A0[1];
                    d2 = w4A0[2];
                    d3 = w4A0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(tmp21F));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((s16)((var_16_6 + 0x26F))) + 0x10), 1) != 1) {
            if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
                func_0045af60(0, 0, 0, 0);
                func_0032c0c0(arg0, 5);
                return;
            } else if (D_008C027A[0] & 0x1000) {
                if (p->f11E != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 1);
                return;
            } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
                func_0045af60(0, 0, 0, 0);
                func_0032c0c0(arg0, 4);
                return;
            } else if (D_008C027A[0] & 0x4000) {
                if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 0);
                return;
            } else if (D_008C027A[0] & 0x2000) {
                if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 2);
                return;
            } else if (D_008C027A[0] & 0x8000) {
                if (p->f11E != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 3);
                return;
            } else if (D_008C0276[0] & 8) {
                if (p->f123 == 0) {
                    if (datGetFlag(0x1460) == 0) {
                        func_002e68b0(0);
                    }
                    p->f123 = 1;
                    func_0045af60(0, 0, 0, 5);
                }
                return;
            } else if (D_008C0276[0] & 4) {
                if (p->f123 == 1) {
                    if (datGetFlag(0x1460) == 0) {
                        func_002e68b0(0);
                    }
                    p->f123 = 0;
                    ps = func_002b6150(0x2EA);
                    func_002b2970(&sp458, 79.0f, *(f32 *)(func_002b6150(0x2EA) + 0x3C));
                    func_002b69f0(0x2EA, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp458, 1, 8, 0);
                    ps = func_002b6150(0x2EB);
                    func_002b2970(&sp450, (f32)0x12B, *(f32 *)(func_002b6150(0x2EB) + 0x3C));
                    func_002b69f0(0x2EB, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp450, 1, 8, 0);
                    ps = func_002b6150(0x2E2);
                    func_002b2970(&sp448, 79.0f, *(f32 *)(func_002b6150(0x2E2) + 0x3C));
                    func_002b69f0(0x2E2, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp448, 1, 8, 0);
                    ps = func_002b6150(0x2E3);
                    func_002b2970(&sp3D8, (f32)0x12B, *(f32 *)(func_002b6150(0x2E3) + 0x3C));
                    func_002b69f0(0x2E3, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3D8, 1, 8, 0);
                    func_0045af60(0, 0, 0, 5);
                }
                return;
            } else if (D_008C024E[0] & 0x40) {
                p->f122 = 0;
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b9d0(arg0, 0, var_16_2, 1);
                p->f1 = 0x99;
                func_0045af60(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x20) {
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b9d0(arg0, 0, var_16_2, 1);
                p->f1 = 0x9C;
                func_0045af60(0, 0, 0, 2);
            }
        }
        p->f13A = 0;
        break;
    case 0x9D:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9E:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            func_0010b190((u8 *)func_002e48a0(0, p->f11E));
            sumA = func_001099f0(func_002e48a0(0, p->f11E), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, p->f11E), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, p->f11E), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, p->f11E), 3) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, p->f11E), 4) & 0xFF;
            sumB = func_001099f0(func_002e48a0(0, p->f11E), 0) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, p->f11E), 1) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, p->f11E), 2) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, p->f11E), 3) & 0xFF;
            total = sumA * (sumB + (func_001099f0(func_002e48a0(0, p->f11E), 4) & 0xFF)) + 0x7D0;
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2), total);
            func_002e7a80(func_002e7a60() - saved);
            func_002bb550(p->fD);
            tmp8 = func_002bab80((void *)func_00331660());
            p->fD = tmp8;
            func_002bbd80(p->fD, 0, (void *)(((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11)));
            func_002badc0(p->fD, 0x10);
            p->f1 = 0x9F;
            func_0045af60(1, 0, 2, 6);
            if (p->f2B8 != 0) {
                p->f2B8 = 0;
            }
            p->f2B8 = func_00349290(arg0, p->f122);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9F:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x99:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_00314750(p->f148, 0);
            func_00314450(p->f148, func_002e48a0(0, p->f11E), 0, 1);
            func_0011c6e0(func_003147d0(p->f148), 1);
            func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 1, 0);
            p->f1 = 0x9A;
            return;
        }
        break;
    case 0x9A:
        if ((s8)func_00314660(p->f148) < 0 || (s8)func_00314660(p->f148) >= 6) {
            break;
        }
        func_002b6140((u8 *)p->f28C, 1);
        func_002b6140((u8 *)p->f290, 1);
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        func_002b68d0(0x80, 0, 1);
        func_002b68d0(0x20C, 0, 1);
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if ((s8)func_00314660(p->f148) == 5) {
            if (func_0011c610(func_003147d0(p->f148)) == 1) {
                func_0011caf0(func_003147d0(p->f148));
            }
            if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
                if (func_0011c610(func_003147d0(p->f148)) == 0) {
                    func_0045af60(0, 2, 0, 5);
                    func_0032c0c0(arg0, 5);
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C027A[0] & 0x1000) {
                if (func_0011c610(func_003147d0(p->f148)) == 0) {
                    if (p->f11E != 0) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    func_0032c0c0(arg0, 1);
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C0252[0] & 1) {
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 5);
                func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                return;
            } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
                if (func_0011c610(func_003147d0(p->f148)) == 0) {
                    func_0045af60(0, 2, 0, 5);
                    func_0032c0c0(arg0, 4);
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C027A[0] & 0x4000) {
                if (func_0011c610(func_003147d0(p->f148)) == 0) {
                    if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    func_0032c0c0(arg0, 0);
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C0252[0] & 2) {
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 4);
                func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                goto conv9A;
            } else if (D_008C024E[0] & 0x80) {
                if (p->f122 != 1) {
                    if (func_0011c610(func_003147d0(p->f148)) == 0) {
                        func_0011c630(func_003147d0(p->f148));
                        func_00314740(func_003147d0(p->f148), 0);
                    } else {
                        func_0011c6e0(func_003147d0(p->f148), 1);
                        func_00314740(func_003147d0(p->f148), 1);
                    }
                    goto conv9A;
                }
            } else if (D_008C024E[0] & 8) {
                if (p->f122 == 1) {
                    p->f122 = 0;
                    ps = func_002b6150(0x150);
                    func_002b2970(&sp3C8, (f32)0x141, 16.0f);
                    func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3C8, 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp3C0, (f32)0x141, 16.0f);
                    func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3C0, 1, 4, 0);
                    func_00314750(p->f148, 0);
                    func_0032a960(arg0, 1);
                    func_002b2970(&sp3B8, 0.0f, 0.0f);
                    func_002b2970(&sp3B0, 0.0f, -7.0f);
                    func_002b5e90(p->f2AC, sp3B8, sp3B0, 4);
                    func_002b2970(&sp3A8, 0.0f, 432.0f);
                    func_002b2970(&sp3A0, 0.0f, 480.0f);
                    func_002b5e90(p->f2B0, sp3A8, sp3A0, 6);
                    func_002b2970(&sp398, 0.0f, 69.0f);
                    func_002b2970(&sp390, 0.0f, 93.0f);
                    func_002b29e0((u8 *)&sp210, 640.0f, (f32)0x157);
                    func_002b29e0((u8 *)&sp200, 640.0f, 294.0f);
                    func_002b5ef0(p->f2B4, sp398, sp390, &sp210, &sp200, 5);
                    func_002b60f0(p->f2B4, 0xE5, 0, 5);
                    func_00317320(arg0, 0, 0);
                    func_00314450(p->f148, func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0045af60(0, 0, 0, 5);
                }
                goto conv9A;
            } else if (D_008C024E[0] & 4) {
                if (p->f122 == 0) {
                    p->f122 = 1;
                    ps = func_002b6150(0x150);
                    func_002b2970(&sp388, 107.0f, 16.0f);
                    func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp388, 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp380, 107.0f, 16.0f);
                    func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp380, 1, 4, 0);
                    func_00314750(p->f148, 1);
                    func_0032a960(arg0, 0);
                    func_0045af60(0, 0, 0, 5);
                    func_002b2970(&sp378, 0.0f, -10.0f);
                    func_002b2970(&sp370, 0.0f, 0.0f);
                    func_002b5e90(p->f2AC, sp378, sp370, 4);
                    func_002b2970(&sp368, 0.0f, 480.0f);
                    func_002b2970(&sp360, 0.0f, 432.0f);
                    func_002b5e90(p->f2B0, sp368, sp360, 6);
                    func_002b2970(&sp358, 0.0f, 93.0f);
                    func_002b2970(&sp350, 0.0f, 69.0f);
                    func_002b29e0((u8 *)&sp1F0, 640.0f, 294.0f);
                    func_002b29e0((u8 *)&sp1E0, 640.0f, (f32)0x157);
                    func_002b5ef0(p->f2B4, sp358, sp350, &sp1F0, &sp1E0, 5);
                    func_002b60f0(p->f2B4, 0, 0xE5, 5);
                    func_00317240(arg0, 1, 0);
                }
                goto conv9A;
            } else if (D_008C024E[0] & 0x40) {
                func_0045af60(0, 0, 0, 1);
                if (func_0010ac10(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)) != 0) {
                    func_00310960(arg0, 0x12, 0);
                    p->f1 = 0x9D;
                    return;
                }
                if ((func_0010b6f0() & 0xFFFF) >= (func_0010b5b0() & 0xFFFF)) {
                    func_00310960(arg0, 0x14, 0);
                    p->f1 = 0x9D;
                    return;
                }
                sumA = func_001099f0(func_002e48a0(0, p->f11E), 0) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, p->f11E), 1) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, p->f11E), 2) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, p->f11E), 3) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, p->f11E), 4) & 0xFF;
                sumB = func_001099f0(func_002e48a0(0, p->f11E), 0) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, p->f11E), 1) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, p->f11E), 2) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, p->f11E), 3) & 0xFF;
                total = sumA * (sumB + (func_001099f0(func_002e48a0(0, p->f11E), 4) & 0xFF)) + 0x7D0;
                saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2), total);
                if (func_002e7a60() >= saved) {
                    tmp8 = func_002bab80((void *)func_00331660());
                    p->fD = tmp8;
                    sprintf(&sp2A0, &iGpffffa8a4, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11));
                    func_002bbd80(p->fD, 0, &sp2A0);
                    sprintf(&sp220, &iGpffffa8a4 - 4, saved);
                    func_002bbd80(p->fD, 1, &sp220);
                    func_002bafc0(p->fD, 0);
                    func_002badc0(p->fD, 0xF);
                    func_002bb0a0(p->fD, 0);
                    func_002bbf60();
                    p->f1 = 0x9E;
                    goto conv9A;
                } else {
                    func_00310960(arg0, 0x11, 0);
                    p->f1 = 0x9D;
                    goto conv9A;
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011ba00(func_003147d0(p->f148)) != 1) {
                    if (func_0011c610(func_003147d0(p->f148)) == 1 && p->f122 == 0) {
                        func_0011c6e0(func_003147d0(p->f148), 1);
                        func_00314740(func_003147d0(p->f148), 1);
                    } else {
                        func_0045af60(0, 0, 0, 2);
                        func_00314670(p->f148, 3);
                        func_00325450(arg0, 1, 1);
                        if (p->f122 == 1) {
                            func_0032a960(arg0, 1);
                            func_002b2970(&sp348, 0.0f, 0.0f);
                            func_002b2970(&sp340, 0.0f, -7.0f);
                            func_002b5e90(p->f2AC, sp348, sp340, 5);
                            func_002b2970(&sp338, 0.0f, 432.0f);
                            func_002b2970(&sp330, 0.0f, 480.0f);
                            func_002b5e90(p->f2B0, sp338, sp330, 5);
                            func_002b2970(&sp328, 0.0f, 69.0f);
                            func_002b2970(&sp320, 0.0f, 239.0f);
                            func_002b29e0((u8 *)&sp1D0, 640.0f, (f32)0x157);
                            func_002b29e0((u8 *)&sp1C0, 640.0f, 0.0f);
                            func_002b5ef0(p->f2B4, sp328, sp320, &sp1D0, &sp1C0, 5);
                        } else {
                            func_00317240(arg0, 1, 0);
                        }
                        func_0034a890(p->f254);
                        var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                            var_16_2 = 8;
                        }
                        func_0032b9d0(arg0, 0, var_16_2, 0);
                        p->f1 = 0x9B;
                        *(s8 *)(func_0034a630(p->f254) + 1) = 1;
                        func_0034a840(p->f254);
                        func_002b68d0(0x80, 0, 0);
                        func_002b68d0(0x20C, 0, 0);
                        func_002b6140((u8 *)p->f28C, 0);
                        func_002b6140((u8 *)p->f290, 0);
                        func_002b68d0(0x84, 0, 0);
                        func_002b68d0(0x85, 0, 0);
                        func_002b68d0(0x1C6, 0, 0);
                    }
                    goto conv9A;
                }
            }
        }
    conv9A:
        p->f13A = 0;
        return;
    case 0x9B:
        func_002b2970(&sp318, 250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW3, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp318, colW3, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW4, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW4, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(tmp22)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s16)(tmp22)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp310, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp310, colW4, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x10), 1) == 0) {
                if (p->f11E == var_19) {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x27D))) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -1;
                    fclWriteColorBytes(w498, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w498[0];
                    d1 = w498[1];
                    d2 = w498[2];
                    d3 = w498[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)(temp_21));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w494, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w494[0];
                    d1 = w494[1];
                    d2 = w494[2];
                    d3 = w494[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w490, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w490);
                } else {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x27D))) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s16)(temp_21)) + 0x6E) = -128;
                    fclWriteColorBytes(w48C, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x27D)));
                    d0 = w48C[0];
                    d1 = w48C[1];
                    d2 = w48C[2];
                    d3 = w48C[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(temp_21));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w488, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s16)((temp_16 + 0x297)));
                    d0 = w488[0];
                    d1 = w488[1];
                    d2 = w488[2];
                    d3 = w488[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s16)((temp_16 + 0x28B)));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w484, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s16)(tmp22));
                    d0 = w484[0];
                    d1 = w484[1];
                    d2 = w484[2];
                    d3 = w484[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w480, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(p->f2BC, (s8)(temp_16 + 0xC), w480);
                }
            }
            tmp21F = temp_16 + 0x21F;
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(tmp21F)) + 0x10), 1) == 0) {
                if (p->f11E == var_19) {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x2C5))) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s16)(tmp21F)) + 0x6E) = -1;
                    fclWriteColorBytes(w47C, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x2C5)));
                    d0 = w47C[0];
                    d1 = w47C[1];
                    d2 = w47C[2];
                    d3 = w47C[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(tmp21F));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                } else {
                    *(s8 *)(func_002b6150((s16)((temp_16 + 0x2C5))) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s16)(tmp21F)) + 0x6E) = -128;
                    fclWriteColorBytes(w478, 0, 0, 0x99, 0xFF);
                    r2 = func_002b6150((s16)((temp_16 + 0x2C5)));
                    d0 = w478[0];
                    d1 = w478[1];
                    d2 = w478[2];
                    d3 = w478[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s16)(tmp21F));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if ((s8)func_00314660(p->f148) == 6) {
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
            p->f1 = 0x98;
            return;
        }
        break;
    case 0x9C:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(p->f11E - p->f120);
        func_002b2970(&sp308, 254.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW1, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp308, colW1, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s16)(var_19) < var_22) {
            temp_16 = (s16)(var_18);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s16)(temp_21)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW2, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW2, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp300, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp300, colW2, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x117);
            func_00315600(arg0, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x8C:
        break;
    default:
        return;
    }
}

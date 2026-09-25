/* Research only; production func_002ed430 remains INCLUDE_ASM (see
 * FclCombine_002ed430_20260925.md). MWCCPS2 b210 -O2: object 3755 vs retail
 * 3761 instrs; fnalign 529 edits (guarded draft 2298); per-case aligned
 * edits 272 (casealign). Remaining: case 0x2A spill/CSE (see note). */
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA4];
    s8 fB2;
    u8 padB3[0x6B];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    u8 *f148;
    u8 pad14C[0x3C];
    s32 f188;
    u8 pad18C[0x100];
    u8 *f28C;
    u8 *f290;
    u8 pad294[0x28];
    s32 f2BC;
    u8 pad2C0[0x39];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineWork;

typedef struct {
    u8 pad0[0x2E4];
    s8 f2E4;
} FclPartySlot;

void func_002ed430(u8 *arg0) {
    extern s32 func_00104c70(s32);
    extern s32 func_0010b5b0(void);
    extern void func_0010cc20(u8 *, u16);
    extern s32 func_0010ce10(u8 *, u16);
    extern u32 func_0010ceb0(void *);
    extern s32 datGetFlag(s32);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern void func_0011d140(u8 *, s32);
    extern s32 func_0011c610(u8 *);
    extern s32 func_00122720(void);
    extern void func_00122520(s32, s32);
    extern s32 func_00275820(s32, s32, s32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern void func_002b2970(void *, f32, f32);
    extern void func_002b68d0(s16, s32, s32);
    extern u8 *func_002b6150(s16);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern s32 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002bb680(s8);
    extern void func_002e4610(s32, s8);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern s32 func_002e53b0(s32, s32);
    extern void func_002e5ae0(s32, void *, s64);
    extern void func_002e6280(s32, void *, s64);
    extern s64 func_00247770(s32);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern void func_002ba970(s32, s8, s32);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00310a10(u8 *, s32);
    extern s32 func_00311930(s32, u8 *, s8);
    extern s32 func_00312bc0(s32);
    extern void func_00313800(s8);
    extern void func_00314670(u8 *, s8);
    extern void func_00314680(u8 *);
    extern void func_003146f0(u8 *, u16 *, s8);
    extern s8 func_00314660(u8 *);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_003144d0(u8 *, u16 *, s32, s32, s32);
    extern void func_00315600(u8 *, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00317240(u8 *, s32, f32);
    extern s32 func_003190d0(u8 *);
    extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s8, u16, u8, s32, s32, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00321e60(u8 *, s32, s32, s32);
    extern void func_00324410(u8 *, s32, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern u32 RpRandom(void);
    extern void memset(void *, s32, u32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern f32 D_00640C10[];
    extern f32 D_00640E70[];
    extern u8 D_00795E60[];
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
    s16 var_19_3;
    u8 *ps;
    FclDrawColor col25C;
    FclDrawColor col258;
    FclDrawColor col254;
    FclDrawColor col250;
    FclDrawColor col24C;
    FclDrawColor col248;
    FclDrawColor col244;
    FclDrawColor col240;
    FclDrawColor col23C;
    FclDrawColor col238;
    FclDrawColor col234;
    s64 sp228;
    s64 sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    s64 sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    FclVec2f sp158;
    FclVec2f sp150;
    FclVec2f sp148;
    FclVec2f sp140;
    FclVec2f sp138;
    u16 sp110[16];
    u16 spF0[16];
    u8 spE0;
    s32 spD0;
    s32 var_16_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_2_3;
    s16 *temp_2;
    s16 temp_16_8;
    s16 temp_2_21;
    s32 temp_16_12;
    s32 temp_16_13;
    s32 temp_16_14;
    s32 temp_16_18;
    s32 temp_16_21;
    s32 temp_16_23;
    s32 temp_16_24;
    s32 temp_16_25;
    s32 temp_16_26;
    s32 temp_16_28;
    s32 temp_16_2;
    s32 temp_16_31;
    s32 temp_16_32;
    s32 temp_16_33;
    s32 temp_16_35;
    s32 temp_16_39;
    s32 temp_16_4;
    s32 var_17;
    s32 var_21;
    s32 var_3;
    s32 var_3_2;
    s32 temp_16;
    s32 temp_16_19;
    s32 temp_16_46;
    s32 temp_16_52;
    s32 temp_16_5;
    s32 temp_17;
    s32 temp_17_14;
    s32 temp_17_15;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_19_5;
    s32 temp_19_6;
    s32 temp_19_7;
    s16 temp_19_9;
    s32 temp_20;
    s32 temp_20_3;
    s32 temp_21;
    s32 temp_21_2;
    s32 temp_21_3;
    s32 temp_22;
    s32 temp_22_2;
    s32 temp_23;
    s32 temp_30;
    s16 var_16;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_5;
    s16 var_16_6;
    s16 var_17_2;
    s16 var_17_3;
    s16 var_17_4;
    s16 var_17_5;
    s16 var_17_6;
    s16 var_17_7;
    s16 var_17_8;
    s16 temp_19_10;
    s16 var_17_9;
    s16 var_19;
    s16 var_19_2;
    s8 temp_16_29;
    s8 temp_16_36;
    s8 temp_2_17;
    s8 temp_4;
    s8 temp_4_2;
    s8 var_4;
    u16 *temp_16_48;
    u16 *temp_16_54;
    u16 *temp_17_10;
    u16 *temp_17_11;
    u16 *temp_17_9;
    u16 temp_16_11;
    u16 temp_16_15;
    u16 temp_16_41;
    s32 temp_16_42;
    u16 temp_16_43;
    u16 temp_16_47;
    u16 temp_16_49;
    u16 temp_16_53;
    u16 temp_16_6;
    u16 temp_16_9;
    u16 temp_19;
    u16 temp_19_2;
    u16 temp_19_3;
    u16 temp_19_4;
    u16 temp_19_8;
    u32 temp_16_44;
    u32 temp_16_45;
    u8 temp_16_10;
    u8 temp_16_16;
    u8 temp_16_17;
    s32 temp_16_22;
    s32 temp_16_27;
    s32 temp_16_34;
    u8 temp_16_38;
    u8 temp_16_3;
    u8 temp_16_40;
    u8 temp_16_50;
    s32 temp_16_51;
    u8 temp_16_7;
    s32 temp_17_13;
    u8 temp_17_2;
    s32 temp_20_2;
    u8 temp_3;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_7;
    FclPartySlot *temp_16_20;
    FclPartySlot *temp_16_30;
    FclPartySlot *temp_16_37;
    FclCombineWork *temp_17_12;
    FclCombineWork *temp_17_3;
    FclCombineWork *temp_17_8;
    FclCombineWork *temp_18;
    u8 slotByte;
    s32 slotMode;
    FclVec2f *basePos;
    s8 partyCount;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_22;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_18 = *(FclCombineWork **)(arg0 + 0x38);
    temp_3 = (u8)((u8)((u8)(temp_18->f1)));
    switch (temp_3) {                               /* switch 1 */
    case 0x23:                                      /* switch 1 */
        func_002e4610(1, 0);
        func_002e4610(0xA, 1);
        func_002e4610(0xA, 2);
        func_002e4610(0xA, 3);
        func_002e4610(0xA, 4);
        func_002e4610(0xA, 5);
        func_002e4610(0xA, 6);
        func_002e4610(0xA, 7);
        func_002e4610(0xA, 8);
        func_002e4610(0xA, 9);
        func_002e4610(0xA, 0xA);
        func_002e4610(0xA, 0xB);
        func_002e4610(0xA, 0xC);
        func_002e4610(0, 0xD);
        func_00315600(arg0, 1);
        temp_18->f1 = 0x24U;
        return;
    case 0x24:
        if (func_003190d0(arg0) != 1 && *(s8 *)func_002e4870(0) == 1 && *(s8 *)func_002e4870(1) == 1
            && *(s8 *)func_002e4870(2) == 1 && *(s8 *)func_002e4870(0xD) == 1) {
            for (var_16 = 0; var_16 < (func_0010b5b0() & 0xFFFF); var_16++) {
                col25C = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)temp_18->f188, var_16) + 0x75) = col25C;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00320b80(arg0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_18->f129 = -1;
            temp_18->f1 = 0x25;
        }
        break;
    case 0x25:                                      /* switch 1 */
        func_003212e0(arg0, 0x27, 0);
        return;
    case 0x26:
        for (var_19 = 0; var_19 < (func_0010b5b0() & 0xFFFF); var_19++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(var_19 + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)*(s16 *)(func_002b6150(var_19 + 0x21C) + 0x40));
            if (temp_18->f11E == var_19) {
                var_17 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_17 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (var_19 < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(var_19 * 0x17 + 0x80);
                func_00275820(var_17, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, var_19)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 113.0f, temp_f20, 43.0f);
            }
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 0
            && (s16)func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_003205f0(arg0, 0x96, 0x93);
            func_002eb270(arg0, 0);
            func_00315600(arg0, 0);
            temp_18->f0 = 0;
            temp_18->f1 = 0x1A;
        }
        break;
    case 0x27:                                      /* switch 1 */
        if (((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) < (s32)((s32)(0))) || ((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) >= (s32)((s32)(6)))) {
            func_00321e60(arg0, 0, 0x2A, 0x26);
            return;
        }
        break;
    case 0x28:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1))))) != (s32)((s32)(1))) {
            func_00314450(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0);
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            temp_16_2 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
            func_0011d140((u8 *)temp_16_2, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_18->f1 = 0x29U;
            return;
        }
        break;
    case 0x29:
        if ((s8)func_00314660(temp_18->f148) == 5) {
            if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 0) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                } else {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                } else {
                    if ((s8)func_00314660(temp_18->f148) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(temp_18->f148, 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) >= 6) {
            for (var_16_2 = 0; var_16_2 < (func_0010b5b0() & 0xFFFF); var_16_2++) {
                func_002b2970(&sp228, 16.0f, 128.0f);
                temp_19 = func_002e48a0(0, var_16_2)[1];
                temp_17_2 = *(u8 *)((u8 *)func_002e48a0(0, var_16_2) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp228, var_16_2, temp_19, temp_17_2, 0, 0, partyCount);
            }
            func_002b2970(&sp220, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp220, 0, 0, 0, 0, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_003218a0(arg0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x27;
        }
        break;
    case 0x2A:
        temp_16_3 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_3 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_2 = func_002b6150(0x7C);
        sp158 = *(FclVec2f *)(temp_2_2 + 0x38);
        temp_16_4 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_3);
        func_00275820(temp_16_4, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, temp_17_3->f128)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp158.x, sp158.y, 43.0f);
        for (var_19_2 = 0; var_19_2 < (func_0010b5b0() & 0xFFFF); var_19_2++) {
            func_0031d630(arg0, var_19_2, temp_18->f128, temp_18->f129, 0);
            if (temp_18->f128 != var_19_2 && *(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) > 0) {
                temp_23 = var_19_2 + 0x270;
                temp_f20_2 = (f32)*(s16 *)(func_002b6150(temp_23) + 0x42);
                spE0 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20_2, (f32)*(s16 *)(func_002b6150(temp_23) + 0x40));
                if (var_19_2 == temp_18->f11E) {
                    temp_30 = var_19_2 + 0x27D;
                    spD0 = var_19_2 + 0x270;
                    *(u8 *)(func_002b6150(spD0) + 0x6E) = *(u8 *)(func_002b6150(temp_30) + 0x6E) = 0xFF;
                    col258 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    temp_2_4 = func_002b6150(var_19_2 + 0x297);
                    *(FclDrawColor *)(temp_2_4 + 0x85) = col258;
                    temp_2_5 = func_002b6150(var_19_2 + 0x28B);
                    *(FclDrawColor *)(temp_2_5 + 0x85) = *(FclDrawColor *)(temp_2_4 + 0x85);
                    temp_2_6 = func_002b6150(temp_30);
                    *(FclDrawColor *)(temp_2_6 + 0x85) = *(FclDrawColor *)(temp_2_5 + 0x85);
                    *(FclDrawColor *)(func_002b6150(spD0) + 0x85) = *(FclDrawColor *)(temp_2_6 + 0x85);
                    col254 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col254;
                    col250 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col250);
                    var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, spE0);
                    if (*(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) == 2) {
                        func_002b68d0(0xCF, 0, 1);
                        func_002b68d0(0xD2, 0, 1);
                        func_002b68d0(temp_23, 0, 0);
                        func_002b68d0(temp_30, 0, 0);
                    }
                } else if (*(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) == 2) {
                    temp_21_2 = var_19_2 + 0x27D;
                    temp_22 = var_19_2 + 0x270;
                    *(u8 *)(func_002b6150(temp_22) + 0x6E) = *(u8 *)(func_002b6150(temp_21_2) + 0x6E) = 0;
                    col24C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
                    temp_2_9 = func_002b6150(temp_21_2);
                    *(FclDrawColor *)(temp_2_9 + 0x85) = col24C;
                    *(FclDrawColor *)(func_002b6150(temp_22) + 0x85) = *(FclDrawColor *)(temp_2_9 + 0x85);
                    col248 = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col248;
                    col244 = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col244);
                    var_21 = func_002b2a30(0xFF, 0xCC, 0xFA, spE0);
                    func_002b68d0(0xCF, 0, 0);
                    func_002b68d0(0xD2, 0, 0);
                } else {
                    temp_21_3 = var_19_2 + 0x27D;
                    temp_22_2 = var_19_2 + 0x270;
                    *(u8 *)(func_002b6150(temp_22_2) + 0x6E) = *(u8 *)(func_002b6150(temp_21_3) + 0x6E) = 0xCC;
                    col240 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_12 = func_002b6150(temp_21_3);
                    *(FclDrawColor *)(temp_2_12 + 0x85) = col240;
                    *(FclDrawColor *)(func_002b6150(temp_22_2) + 0x85) = *(FclDrawColor *)(temp_2_12 + 0x85);
                    col23C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_14 = func_002b6150(var_19_2 + 0x297);
                    *(FclDrawColor *)(temp_2_14 + 0x85) = col23C;
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x28B) + 0x85) = *(FclDrawColor *)(temp_2_14 + 0x85);
                    col238 = func_002b2a60(0, 0, 0x66, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col238;
                    col234 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col234);
                    var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, spE0);
                }
                temp_f20_2 = (f32)(var_19_2 * 0x17 + 0x80);
                func_00275820(var_21, 0, 2, (s32)iGpffffb440 + func_002e48a0(temp_18->f128 + 1, var_19_2)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, (f32)0x195, temp_f20_2, 43.0f);
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) >= 6) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1C7) + 0x10), 0) == 1) {
                func_00324410(arg0, 0x1C7, 0);
                func_00324410(arg0, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                temp_18->f11E = (s8)func_002b2d00(temp_18->f11E, 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
                func_0045af60(0, 0, 0, 0);
            } else if (D_008C027A[0] & 0x4000) {
                temp_18->f11E = (s8)func_002b2cb0(temp_18->f11E, 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 2);
                func_0045af60(0, 0, 0, 0);
            } else if (D_008C024E[0] & 0x40) {
                if (temp_18->f128 != temp_18->f11E && *(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + temp_18->f11E + 0x14) > 0) {
                    func_0045af60(0, 0, 0, 1);
                    for (var_17_2 = 0; var_17_2 < (func_0010b5b0() & 0xFFFF); var_17_2++) {
                        func_002b2970(&sp218, (f32)0x149, 128.0f);
                        temp_16_6 = func_002e48a0(temp_18->f128 + 1, var_17_2)[1];
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_2) + 4);
                        func_0031ac10(arg0, sp218, temp_18->f128, var_17_2, temp_16_6, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp210, 16.0f, 128.0f);
                        temp_19_2 = func_002e48a0(0, var_17_2)[1];
                        temp_16_7 = *(u8 *)((u8 *)func_002e48a0(0, var_17_2) + 4);
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp210, var_17_2, temp_19_2, temp_16_7, 0, 1, partyCount);
                    }
                    func_002b2970(&sp208, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp208, 0, 1, 0, 0, 0);
                    func_002b2970(&sp200, (f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp200, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0.0f);
                    func_002b6140(temp_18->f28C, 1);
                    func_002b6140(temp_18->f290, 1);
                    temp_18->f1 = 0x2E;
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (D_008C024C[0] & 0x80) {
                if (temp_18->f11E < *(s32 *)(func_002e4870(0) + 8)) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_17_3 = 0; var_17_3 < (func_0010b5b0() & 0xFFFF); var_17_3++) {
                        func_002b2970(&sp1F8, (f32)0x149, 128.0f);
                        temp_16_9 = func_002e48a0(temp_18->f128 + 1, var_17_3)[1];
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_3) + 4);
                        func_0031ac10(arg0, sp1F8, temp_18->f128, var_17_3, temp_16_9, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp1F0, 16.0f, 128.0f);
                        temp_19_3 = func_002e48a0(0, var_17_3)[1];
                        temp_16_10 = *(u8 *)((u8 *)func_002e48a0(0, var_17_3) + 4);
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp1F0, var_17_3, temp_19_3, temp_16_10, 0, 1, partyCount);
                    }
                    func_002b2970(&sp1E8, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1E8, 0, 1, 0, 0, 0);
                    func_002b2970(&sp1E0, (f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp1E0, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140(temp_18->f28C, 1);
                    func_002b6140(temp_18->f290, 1);
                    temp_18->f1 = 0x2B;
                }
            } else if (D_008C024E[0] & 0x20) {
                func_0031ddf0(arg0, (s8)temp_18->f11E, 0, 0xFF);
                func_0031ddf0(arg0, temp_18->f11E = temp_18->f128, 1, 0xFF);
                func_0045af60(0, 0, 0, 2);
                func_003205f0(arg0, 0x93, 0x94);
                basePos = (FclVec2f *)D_00640C10;
                func_002b2970(&sp1D8, basePos->x, basePos->y);
                func_002b2970(&sp1D0, -380.0f, basePos->y);
                func_0031c2b0(arg0, temp_18->f128, sp1D8, sp1D0);
                func_002b2970(&sp1C8, (f32)0x149, 104.0f);
                func_0031fa20(arg0, sp1C8, 0, 1);
                for (var_17_4 = 0; var_17_4 < (func_0010b5b0() & 0xFFFF); var_17_4++) {
                    func_002b2970(&sp1C0, (f32)0x149, 128.0f);
                    temp_16_11 = func_002e48a0(temp_18->f128 + 1, var_17_4)[1];
                    slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_4) + 4);
                    func_0031ac10(arg0, sp1C0, temp_18->f128, var_17_4, temp_16_11, slotByte, 0, 1, 1, 0xCC);
                }
                func_003218a0(arg0, 3);
                temp_18->f1 = 0x27;
            }
        }
        break;
    case 0x2B:
        temp_2_18 = func_002b6150(0x7C);
        sp150 = *(FclVec2f *)(temp_2_18 + 0x38);
        temp_16_12 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
        func_00275820(temp_16_12, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, temp_18->f128)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp150.x, sp150.y, 43.0f);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            func_00314450(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0);
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            temp_16_13 = (s32)func_003147d0(temp_18->f148);
            func_0011d140((u8 *)temp_16_13, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            temp_18->f1 = 0x2C;
        }
        break;
    case 0x2C:
        temp_2_19 = func_002b6150(0x7C);
        sp148 = *(FclVec2f *)(temp_2_19 + 0x38);
        temp_16_14 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
        func_00275820(temp_16_14, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, temp_18->f128)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp148.x, sp148.y, 43.0f);
        if ((s8)func_00314660(temp_18->f148) == 5) {
            if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 0) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                } else {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                } else {
                    if ((s8)func_00314660(temp_18->f148) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(temp_18->f148, 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) >= 6) {
            for (var_17_5 = 0; var_17_5 < (func_0010b5b0() & 0xFFFF); var_17_5++) {
                func_002b2970(&sp1B8, (f32)0x149, 128.0f);
                temp_16_15 = func_002e48a0(temp_18->f128 + 1, var_17_5)[1];
                slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_5) + 4);
                func_0031ac10(arg0, sp1B8, temp_18->f128, var_17_5, temp_16_15, slotByte, 0, 0, 1, 0xCC);
                func_002b2970(&sp1B0, 16.0f, 128.0f);
                temp_19_4 = func_002e48a0(0, var_17_5)[1];
                temp_16_16 = *(u8 *)((u8 *)func_002e48a0(0, var_17_5) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp1B0, var_17_5, temp_19_4, temp_16_16, 0, 0, partyCount);
            }
            func_002b2970(&sp1A8, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1A8, 0, 0, 0, 0, 0);
            func_002b2970(&sp1A0, (f32)0x149, 104.0f);
            func_0031fa20(arg0, sp1A0, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x2A;
        }
        break;
    case 0x2E:
        temp_16_17 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_8 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_20 = func_002b6150(0x7C);
        sp140 = *(FclVec2f *)(temp_2_20 + 0x38);
        temp_16_18 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_17);
        func_00275820(temp_16_18, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, temp_17_8->f128)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp140.x, sp140.y, 43.0f);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_16_19 = temp_18->f2FA = temp_18->f11E;
            temp_17_9 = func_002e48a0(temp_18->f2F9, temp_16_19);
            temp_16_20 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_19);
            temp_19_5 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
            slotMode = func_00311930(temp_19_5, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
            func_003144d0(temp_18->f148, temp_17_9, temp_16_20->f2E4, slotMode, 1);
            temp_16_21 = (s32)func_003147d0(temp_18->f148);
            func_0011d140((u8 *)temp_16_21, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            temp_16_22 = *(u8 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 4);
            if ((func_00104c70(1) & 0xFF) < temp_16_22) {
                temp_16_23 = (s32)func_003147d0(temp_18->f148);
                func_0011d140((u8 *)temp_16_23, func_002b2a30(0x14, 0x14, 0x14, 0xFF));
            }
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            func_00325450(arg0, 3, 0);
            temp_18->f1 = 0x2D;
        }
        break;
    case 0x2D:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) == (s32)((s32)(0xD))) {
            if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x40) {
                temp_18->f1 = 0x2FU;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                    return;
                }
                func_0011c6e0(func_003147d0(temp_18->f148), 1);
                func_00314740(temp_18->f148, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                    return;
                }
                temp_18->f1 = 0x35U;
                func_00314670(temp_18->f148, 0xB);
                func_00325450(arg0, 3, 1);
                func_00317240(arg0, 1, 0.0f);
                func_0045af60(0, 0, 0, 2);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (temp_18->f122 != 2) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_18->f122 = (s8)((s8)(func_002b2cb0(temp_18->f122, 1, 2, 0, 1)));
                ps = func_002b6150(0x151);
                func_002b2970(&sp198, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp198), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp190, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp190), 1, 4, 0);
                temp_4 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    temp_16_24 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_24, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f128), 0, 0, 1);
                    return;
                case 1:                             /* switch 2 */
                    temp_16_25 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_25, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0, 1);
                    return;
                case 2:                             /* switch 2 */
                    temp_16_26 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_26, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_27 = (u8)((u8)((u8)((*(u8 *)((u8 *)(func_002e48a0(temp_18->f2F9, temp_18->f2FA))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_27))) {
                        temp_16_28 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_28, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_29 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_10 = (u16 *)(func_002e48a0(temp_18->f2F9, temp_16_29));
                    temp_16_30 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_29);
                    temp_19_6 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_6, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
                    func_003144d0(temp_18->f148, temp_17_10, temp_16_30->f2E4, slotMode, 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (temp_18->f122 != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_18->f122 = (s8)((s8)(func_002b2d00(temp_18->f122, 1, 0, 2, 1)));
                ps = func_002b6150(0x151);
                func_002b2970(&sp188, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp188), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp180, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp180), 1, 4, 0);
                temp_4_2 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4_2) {                 /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_31 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_31, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f128), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_32 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_33 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_34 = (u8)((u8)((u8)((*(u8 *)((u8 *)(func_002e48a0(temp_18->f2F9, temp_18->f2FA))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_34))) {
                        temp_16_35 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_35, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_36 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_11 = (u16 *)(func_002e48a0(temp_18->f2F9, temp_16_36));
                    temp_16_37 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_36);
                    temp_19_7 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_7, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
                    func_003144d0(temp_18->f148, temp_17_11, temp_16_37->f2E4, slotMode, 1);
                    return;
                }
            }
        }
        break;
    case 0x35:
        temp_16_38 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_12 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_22 = func_002b6150(0x7C);
        sp138 = *(FclVec2f *)(temp_2_22 + 0x38);
        temp_16_39 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_38);
        func_00275820(temp_16_39, 0, 2, (s32)iGpffffb440 + func_002e48a0(0, temp_17_12->f128)[1] * 0x11, 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp138.x, sp138.y, 43.0f);
        if ((s8)func_00314660(temp_18->f148) == 0xE) {
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_18->f129 = -1;
            for (var_17_6 = 0; var_17_6 < (func_0010b5b0() & 0xFFFF); var_17_6++) {
                func_002b2970(&sp178, 16.0f, 128.0f);
                temp_19_8 = func_002e48a0(0, var_17_6)[1];
                temp_16_40 = *(u8 *)((u8 *)func_002e48a0(0, var_17_6) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp178, var_17_6, temp_19_8, temp_16_40, 0, 0, partyCount);
                func_002b2970(&sp170, (f32)0x149, 128.0f);
                temp_16_41 = func_002e48a0(temp_18->f128 + 1, var_17_6)[1];
                slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_6) + 4);
                func_0031ac10(arg0, sp170, temp_18->f128, var_17_6, temp_16_41, slotByte, 0, 0, 1, 0xCC);
            }
            func_002b2970(&sp168, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp168, 0, 0, 0, 0, 0);
            func_002b2970(&sp160, (f32)0x149, 104.0f);
            func_0031fa20(arg0, sp160, 0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x2A;
        }
        break;
    case 0x2F:
        temp_16_42 = func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1];
        temp_17_13 = *(u8 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 4);
        if ((func_00104c70(1) & 0xFF) < temp_17_13) {
            func_00310960(arg0, 0x26, 0);
            temp_18->f1 = 0x31;
        } else if (func_002e53b0(0, *(s16 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 2)) == 1) {
            func_00310960(arg0, 0x27, 0);
            temp_18->f1 = 0x31;
        } else {
            if (func_00105f50(temp_16_42) == 0) {
                func_00310a10(arg0, temp_16_42);
            } else {
                func_00310960(arg0, (s8)(func_00105f50(temp_16_42) + 0x2E), 1);
            }
            temp_18->f1 = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680(temp_18->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_18->fD);
            return;
        }
        if ((s32)((s32)(func_002bb1c0(temp_18->fD))) == (s32)((s32)(0))) {
            temp_18->f1 = 0x33U;
            func_00122520(1, 0xA);
        } else {
            temp_18->f1 = 0x2DU;
        }
        func_002bb550(temp_18->fD);
        return;
    case 0x31:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680(temp_18->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_18->fD);
            return;
        }
        func_002bb550(temp_18->fD);
        temp_18->f1 = 0x2DU;
        return;
    case 0x33:                                      /* switch 1 */
        if ((s32)((s32)(func_00122720())) != (s32)((s32)(0))) {
            func_00314670(temp_18->f148, 0xB);
            func_00314680(temp_18->f148);
            func_00325450(arg0, 3, 1);
            for (var_16_3 = 0; var_16_3 < 0x30C; var_16_3++) {
                func_002b68d0(var_16_3, 0, 1);
            }
            temp_18->f1 = 0x32U;
            return;
        }
        break;
    case 0x32:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) == (s32)((s32)(0xE))) {
            temp_18->f1 = 0x34U;
            return;
        }
        break;
    case 0x34:                                      /* switch 1 */
        var_16_4 = 2;
        if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18->f128 * 0xC) + temp_18->f11E))+(0x14))) == 2) {
            var_16_4 = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(func_00312bc0(var_16_4))) == (s32)((s32)(1))) {
                if ((s32)((s32)((u32) (RpRandom() % 1000U))) < (s32)((s32)(0x1F4U))) {
                    temp_18->f1 = 0x36U;
                    temp_18->fB2 = 1;
                    return;
                }
                temp_18->f1 = 0x37U;
                temp_18->fB2 = 2;
                return;
            }
            temp_18->fB2 = 0;
            temp_18->f0 = 0xD;
            temp_18->f1 = 0xC5U;
            return;
        }
        temp_18->f1 = 0x36U;
        temp_18->fB2 = 1;
        return;
    case 0x36:
        memset(&sp110, 0, 0x1A);
        for (var_16_5 = 0; var_16_5 < *(s32 *)(func_002e4870(0) + 8); var_16_5++) {
            sp110[var_16_5] = func_002e48a0(0, var_16_5)[1];
        }
        temp_16_43 = func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1];
        sp110[*(s32 *)(func_002e4870(0) + 8)] = temp_16_43;
        func_002e5ae0(0xD, &sp110, (s8)func_00104c70(1));
        temp_16_44 = *(u32 *)(func_002e4870(0xD) + 8);
        temp_16_45 = (RpRandom() % temp_16_44) * 0xA;
        temp_19_9 = (s8)(temp_16_45 % *(u32 *)(func_002e4870(0xD) + 8));
        temp_18->f2F9 = temp_18->f128 + 1;
        temp_18->f2FA = temp_18->f11E;
        for (var_17_7 = 0; var_17_7 < 8; var_17_7++) {
            if ((((1 << var_17_7) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f2FA + 0x2E4)) >> var_17_7) == 1
                && (s32)func_0010ceb0(func_002e48a0(0xD, temp_19_9)) < 8) {
                temp_16_47 = func_002e48a0(temp_18->f128 + 1, temp_18->f11E)[var_17_7 + 6];
                if (func_0010ce10((u8 *)func_002e48a0(0xD, temp_19_9), temp_16_47) == -1) {
                    func_0010cc20((u8 *)func_002e48a0(0xD, temp_19_9), temp_16_47);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_18->f2FA = temp_19_9;
        temp_16_48 = func_002e48a0(temp_18->f2F9, (s8)temp_19_9);
        func_003146f0(temp_18->f148, temp_16_48, *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    case 0x37:
        var_19_3 = 0x63;
        memset(&spF0, 0, 0x1A);
        for (var_16_6 = 0; var_16_6 < *(s32 *)(func_002e4870(0) + 8); var_16_6++) {
            spF0[var_16_6] = func_002e48a0(0, var_16_6)[1];
        }
        temp_16_49 = func_002e48a0(temp_18->f128 + 1, temp_18->f11E)[1];
        spF0[*(s32 *)(func_002e4870(0) + 8)] = temp_16_49;
        func_002e6280(0xD, &spF0, (s8)func_00104c70(1));
        if (*(s32 *)(func_002e4870(0xD) + 8) == 0) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_18->f2FA = temp_18->f11E;
            temp_18->f1 = 0x36;
            temp_18->fB2 = 1;
            break;
        }
        temp_18->f2F9 = 0xD;
        for (var_17_8 = 0; var_17_8 < *(s32 *)(func_002e4870(0xD) + 8); var_17_8++) {
            temp_16_50 = *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4);
            if (temp_16_50 >= (func_00104c70(1) & 0xFF)) {
                temp_18->f2FA = var_17_8;
                break;
            }
            if (var_19_3 > (func_00104c70(1) & 0xFF) - *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4)) {
                temp_16_51 = *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4);
                var_19_3 = (func_00104c70(1) & 0xFF) - temp_16_51;
                temp_18->f2FA = var_17_8;
            }
        }
        temp_19_10 = temp_18->f2FA;
        temp_18->f2F9 = temp_18->f128 + 1;
        for (var_17_9 = 0; var_17_9 < 8; var_17_9++) {
            if ((((1 << var_17_9) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f11E + 0x2E4)) >> var_17_9) == 1
                && (s32)func_0010ceb0(func_002e48a0(0xD, temp_19_10)) < 8) {
                temp_16_53 = func_002e48a0(temp_18->f2F9, temp_18->f11E)[var_17_9 + 6];
                if (func_0010ce10((u8 *)func_002e48a0(0xD, temp_19_10), temp_16_53) == -1) {
                    func_0010cc20((u8 *)func_002e48a0(0xD, temp_19_10), temp_16_53);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_16_54 = func_002e48a0(0xD, temp_18->f2FA);
        func_003146f0(temp_18->f148, temp_16_54, *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    }
}

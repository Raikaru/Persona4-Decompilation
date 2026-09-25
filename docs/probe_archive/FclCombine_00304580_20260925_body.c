/* Research only; production func_00304580 remains INCLUDE_ASM (see
 * FclCombine_00304580_20260925.md). Object 4563 vs retail 4560 instrs;
 * per-case aligned edits 472 (earlier archives 796, 706). */
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xE];
    s16 f1C;
    u8 pad1E[0x98];
    s8 fB6;
    u8 padB7[0x5];
    s16 fBC;
    u8 padBE[0x60];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    s32 f148;
    u8 pad14C[0x38];
    s32 f184;
    s32 f188;
    u8 pad18C[0x100];
    s32 f28C;
    s32 f290;
    u8 pad294[0x28];
    s32 f2BC;
    u8 pad2C0[0x18];
    s16 f2D8;
    u8 pad2DA[0x1F];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x11];
    u8 f30C[5];
    u8 pad311[0xF];
} FclCombineMenu;

typedef struct {
    u8 pad0[0x154];
    u8 *list;
} FclRowList;

#pragma push
#pragma opt_loop_invariants on
void func_00304580(u8 *arg0) {
    FclDrawColor col2FC;
    FclDrawColor col2F8;
    FclDrawColor col2F4;
    FclDrawColor col2F0;
    FclDrawColor col2EC;
    FclDrawColor col2E8;
    FclDrawColor col2E4;
    FclDrawColor col2E0;
    FclDrawColor col2DC;
    FclDrawColor col2D8;
    FclDrawColor col2D4;
    FclDrawColor col2D0;
    u8 *ps;

    extern s32 datGetFlag(s32);
    extern void func_00106390(s32, s32);
    extern s32 func_0010b5b0(void);
    extern s32 func_0010b6f0(void);
    extern void func_0011b8f0(u8 *, s32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern s32 func_0011cc00(u8 *, u16, u16);
    extern void func_0011d140(u8 *, s32);
    extern void *func_00243840(u16);
    extern int func_00275520(f32, f32, f32, int, s8, int, const char *, int, int, void *);
    extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
    extern void func_002b2970(s64 *, f32, f32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern u8 *func_002b6150(s16);
    extern void func_002b68d0(s16, s32, s32);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern void func_002b6a70(s16, u8, u32, u32, u32, s32);

    extern void func_002ba970(s32, s8, s32);
    extern s8 func_002bab80(void *);
    extern void func_002badc0(s8, s32);
    extern void func_002bafc0(s8, s32);
    extern void func_002bb0a0(s8, s32);
    extern s8 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern void func_002bbd80(s8, s32, void *);
    extern void func_002bbf60(void);
    extern void func_002e4610(s32, s8);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern void func_002e5000(void);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_003144d0(u8 *, u16 *, s32, s32, s32);
    extern s8 func_00314660(u8 *);
    extern void func_00314670(u8 *, s8);
    extern void func_003146f0(u8 *, u16 *, s8);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00315600(u8 *, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00317240(u8 *, s64, s32);
    extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s8, u16, u8, s32, s32, s32, s32);
    extern void func_0031c2b0(u8 *, s16, FclVec2f, FclVec2f);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern void func_0032f4d0(u8 *);
    extern void func_0032fbc0(u8 *);
    extern s32 func_00331560(void);
    extern s32 func_00331660(void);
    extern u32 RpRandom(void);
    extern void sprintf(void *, void *, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern f32 func_0046b2f0(s32);
    extern s32 func_0046d200(s32, s32);
    extern void func_0046d280(s32);
    extern f32 D_00640C10[];
    extern u8 D_00749350[];
    extern u8 D_00795E60[];
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
    extern u16 D_008C027A[];
    extern s8 D_007490F8[];
    extern f32 iGpffff8504;

    extern u16 *func_00308cc0(u8 *);
    extern s32 func_00308dc0(u8 *);
    extern s32 func_00308e50(u8 *);
    extern s32 func_003095f0(void);
    extern s32 func_00309630(u16);
    extern s32 func_003096d0(u8 *);
    extern s32 func_0010cd70(u8 *, s32, u16);
    extern void func_00110270(u8 *, u16);
    extern void func_001102c0(s16);
    extern s32 func_001102d0(void);
    extern u16 *func_001102e0(void);
    extern u16 *func_0010ace0(s16);
    extern s32 func_0010ad80(s32);
    extern void func_0010cad0(u8 *, u16);
    extern char iGpffffa8a4;


    u8 sp2C8[8];
    u8 sp2C0[8];
    u8 sp2B8[8];
    u8 sp2B0[8];
    u8 sp2A8[8];
    u8 sp2A0[8];
    s64 sp298;
    s64 sp290;
    s64 sp288;
    s64 sp280;
    s64 sp278;
    s64 sp270;
    s64 sp268;
    s64 sp260;
    s64 sp258;
    s64 sp250;
    s64 sp248;
    s64 sp240;
    s64 sp238;
    s64 sp230;
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
    FclVec2f sp160;
    FclVec2f sp158;
    FclVec2f sp150;
    FclVec2f sp148;
    FclVec2f sp140;
    s32 sp120;
    s32 sp11C;
    u8 *sp100;
    u8 *spF0;
    s32 spE0;
    u8 *spD0;
    f32 temp_f0;
    f32 temp_f20;
    s16 *temp_18_2;
    s16 *temp_21;
    s16 *temp_21_5;
    s16 *temp_22;
    s16 *temp_22_2;
    s16 *temp_23;
    s16 *temp_23_2;
    s16 *temp_2_3;
    s16 *temp_30;
    s16 *temp_30_2;
    s16 temp_16_5;
    s16 temp_2_46;
    s16 temp_2_47;
    s32 temp_16;
    s32 temp_16_10;
    s32 temp_16_13;
    s32 temp_16_16;
    s32 temp_16_21;
    s32 temp_16_22;
    s32 temp_16_24;
    s32 temp_16_28;
    s32 temp_16_32;
    s32 temp_16_33;
    s32 temp_16_35;
    s32 temp_16_38;
    s32 temp_18_4;
    s32 temp_19_3;
    s32 temp_21_2;
    s32 temp_21_3;
    s32 temp_21_6;
    u16 temp_3_2;
    s32 temp_4_3;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_21;
    s32 var_21_2;
    s32 var_3;
    s32 temp_16_11;
    s32 temp_16_14;
    s32 temp_16_29;
    s32 temp_16_2;
    s32 temp_16_36;
    s64 temp_16_37;
    s16 temp_16_4;
    s16 temp_16_7;
    s16 temp_16_9;
    s8 temp_18_14;
    s32 temp_18_16;
    s64 temp_18_17;
    s16 temp_18_3;
    s64 temp_18_6;
    s64 temp_18_8;
    s64 temp_18_9;
    s16 temp_19_2;
    s32 temp_21_4;
    s64 temp_21_7;
    s64 temp_21_8;
    s64 temp_22_3;
    s64 temp_23_3;
    s8 temp_2_2;
    s64 temp_30_3;
    s64 temp_3_10;
    s64 temp_3_11;
    s64 temp_3_12;
    s64 temp_3_14;
    s64 temp_3_16;
    s64 temp_3_17;
    s16 temp_3_18;
    s64 temp_3_19;
    s64 temp_3_20;
    s64 temp_3_3;
    s64 temp_3_4;
    s64 temp_3_9;
    s8 temp_4;
    s64 temp_4_2;
    s16 var_16;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_4;
    s16 var_16_5;
    s16 var_18;
    s16 var_18_2;
    s16 var_18_5;
    s16 var_18_6;
    s16 var_18_7;
    s16 var_18_8;
    s16 var_18_9;
    s16 var_19;
    u8 *posSrc;
    FclVec2f *basePos;
    s32 rowX;
    s32 rowY;
    s16 var_19_2;
    s16 var_19_3;
    s16 var_19_4;
    s32 id27D;
    s32 id270;
    s32 id27D_2;
    s32 id270_2;
    s16 var_19_5;
    s16 var_19_6;
    s16 var_4;
    s16 var_4_2;
    s16 var_4_3;
    s16 var_4_4;
    s16 var_4_5;
    s16 var_4_6;
    s16 var_4_7;
    s8 var_5;
    s16 var_6;
    s32 limit;
    s16 idx;
    u8 *table;
    s8 temp_2;
    s8 temp_2_23;
    s8 temp_2_27;
    s32 temp_2_37;
    s8 temp_3_13;
    s8 temp_3_15;
    u16 *temp_16_39;
    u16 *temp_2_15;
    u16 *temp_2_16;
    u16 *temp_2_17;
    u16 *temp_2_18;
    u16 *temp_2_19;
    u16 *temp_2_20;
    u16 *temp_2_21;
    u16 *temp_2_22;
    u16 *temp_2_28;
    u16 *temp_2_29;
    u16 *temp_2_30;
    u16 *temp_2_31;
    u16 *temp_2_32;
    u16 *temp_2_33;
    u16 *temp_2_34;
    u16 *temp_2_35;
    u16 *temp_2_38;
    u16 *temp_2_39;
    u16 *temp_2_40;
    u16 *temp_2_41;
    u16 *temp_2_42;
    u16 *temp_2_43;
    u16 *temp_2_44;
    u16 *temp_2_45;
    u16 temp_16_15;
    u16 temp_16_17;
    u16 temp_16_19;
    u16 temp_16_25;
    u16 temp_16_31;
    u16 temp_16_6;
    u16 temp_19;
    u16 temp_19_4;
    u16 temp_19_5;
    u16 temp_19_6;
    u16 temp_19_7;
    u16 temp_19_8;
    u8 temp_16_12;
    u8 temp_16_18;
    u8 temp_16_20;
    u8 temp_16_23;
    u8 temp_16_26;
    u8 temp_16_27;
    u8 temp_16_30;
    u8 temp_16_34;
    u8 temp_18;
    u8 temp_18_10;
    u8 temp_18_5;
    u8 temp_3;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_7;
    FclRowList *temp_16_3;
    u8 *temp_16_40;
    FclRowList *temp_16_8;
    FclCombineMenu *temp_17;
    u8 slotByte;
    s8 partyCount;
    FclCombineMenu *temp_18_11;
    FclCombineMenu *temp_18_12;
    FclCombineMenu *temp_18_13;
    FclCombineMenu *temp_18_15;
    FclCombineMenu *temp_18_7;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_36;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_17 = *(FclCombineMenu **)(arg0 + 0x38);
    temp_3 = (u8)(temp_17->f1);
    switch (temp_3) {                               /* switch 1 */
    case 0x75:
        if (datGetFlag(0x131C) == 0) {
            temp_2 = func_002bab80((void *)func_00331660());
            temp_17->fD = temp_2;
            func_002badc0(temp_2, 0x50);
            func_00106390(0x131C, 1);
            temp_17->f1 = 0x76;
        } else {
            temp_17->f1 = 0x77;
        }
        break;
    case 0x76:
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
        } else {
            func_002bb550(temp_17->fD);
            temp_17->f1 = 0x77;
        }
        break;
    case 0x77:
        func_00315600(arg0, 1);
        if (datGetFlag(0x1306) != 0) {
            func_00314740((u8 *)temp_17->f148, 1);
            func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
            temp_16 = (s32)func_003147d0((u8 *)temp_17->f148);
            func_0011d140((u8 *)temp_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_003146f0((u8 *)temp_17->f148, func_001102e0(), 0);
            func_00314670((u8 *)temp_17->f148, 1);
            if (datGetFlag(0x1307) == 0) {
                temp_3_2 = func_001102d0() & 0xFFFF;
                var_5 = temp_3_2 & 0xF;
                temp_4 = (temp_3_2 >> 0xC) & 0xF;
                for (var_6 = 0; var_6 < 5; var_6++) {
                    temp_17->f30C[var_6] = 0;
                }
                switch (var_5) {
                case 0:
                    for (idx = 0; idx < temp_4 + 1; idx++) {
                        temp_17->f30C[0] += D_00749350[idx];
                        temp_17->f30C[1] += D_00749350[idx];
                    }
                    break;
                case 1:
                    for (idx = 0; idx < temp_4 + 1; idx++) {
                        temp_17->f30C[2] += D_00749350[idx];
                        temp_17->f30C[3] += D_00749350[idx];
                    }
                    break;
                case 2:
                    for (idx = 0; idx < temp_4 + 1; idx++) {
                        temp_17->f30C[4] += D_00749350[idx];
                        temp_17->f30C[0] += D_00749350[idx];
                    }
                    break;
                case 3:
                    for (idx = 0; idx < temp_4 + 1; idx++) {
                        temp_17->f30C[1] += D_00749350[idx];
                        temp_17->f30C[2] += D_00749350[idx];
                    }
                    break;
                }
                func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)temp_17->f30C);
            } else {
                func_00310960(arg0, 0x22, 0);
                temp_17->f1 = 0x85;
                break;
            }
            temp_2_2 = (s8)(((func_001102d0() & 0xFFFF) >> 0xC) & 0xF);
            if (temp_2_2 < 4) {
                func_00310960(arg0, 0x1F, 0);
            } else if (temp_2_2 < 7) {
                func_00310960(arg0, 0x20, 0);
            } else {
                func_00310960(arg0, 0x21, 0);
            }
            temp_17->f1 = 0x85;
        } else {
            for (var_16 = 0; var_16 < (func_0010b5b0() & 0xFFFF); var_16++) {
                col2FC = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)temp_17->f188, var_16) + 0x75) = col2FC;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00314740((u8 *)temp_17->f148, 0);
            func_002e4610(5, 0);
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
            temp_17->f1 = 0x78;
        }
        break;
    case 0x78:
        if (*(s8 *)func_002e4870(0) != 0) {
            func_002e5000();
            temp_17->f11E = 0;
            func_00320b80(arg0, 1);
            temp_17->f1 = 0x79;
        }
        break;
    case 0x79:
        func_003212e0(arg0, 0x7B, 0);
        break;
    case 0x7B:                                      /* switch 1 */
        for (var_16_2 = 0; var_16_2 < (func_0010b5b0() & 0xFFFF); var_16_2++) {
            func_0031d630(arg0, (s8)(var_16_2), -1, -1, 0);
        }
        if ((((s8)(func_00314660((u8 *)temp_17->f148))) < 0) || (((s8)(func_00314660((u8 *)temp_17->f148))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = func_002b2d00(temp_17->f11E, 1, 0, (func_0010b5b0() & 0xFFFF) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = func_002b2cb0(temp_17->f11E, 1, (func_0010b5b0() & 0xFFFF) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                func_0045af60(0, 1, 0, 3);
                for (var_16_3 = 0; var_16_3 < (func_0010b5b0() & 0xFFFF); var_16_3++) {
                    func_002b2970(&sp298, 16.0f, 128.0f);
                    temp_19 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_3))+(2)));
                    temp_18 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_3))+(4)));
                    partyCount = *(s8 *)(func_002e4870(0) + 8);
                    func_003191c0(arg0, sp298, var_16_3, temp_19, temp_18, 0, 1, partyCount);
                }
                func_002b2970(&sp290, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp290, 0, 1, 0, 0, 0);
                for (var_18 = 0; var_18 < (func_0010b5b0() & 0xFFFF); var_18++) {
                    sp11C = func_0046d200(func_00331560(), 0x77);
                    temp_16_2 = (s16)var_18;
                    rowX = temp_16_2 * 0x17;
                    rowY = rowX + 0x7F;
                    temp_21 = (s16 *)(func_0034ae50((u8 *)temp_17->f184, (s8)(var_18)));
                    func_002b2970(&sp288, (f32) (rowX + 0x149), 104.0f);
                    col2F8 = func_002b2a60(0, 0, 0x99, 0xFF);
                    col2F4 = func_002b2a60(0, 0, 0x99, 0xFF);
                    func_002b83e0((u8 *)temp_21, *(FclDrawPosition *)&sp288, col2F8, col2F4, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                    temp_16_3 = (FclRowList *)((u8 *)temp_17 + temp_16_2 * 4);
                    for (var_19 = 0; var_19 < (func_0010b5b0() & 0xFFFF); var_19++) {
                        temp_30 = (s16 *)(func_0034ae50(temp_16_3->list, (s8)(var_19)));
                        posSrc = func_0034ae50(temp_16_3->list, (s8)(var_19));
                        temp_22 = (s16 *)(func_0034ae50(temp_16_3->list, (s8)(var_19)));
                        temp_23 = (s16 *)(func_0034ae50(temp_16_3->list, (s8)(var_19)));
                        sp100 = func_0034ae50(temp_16_3->list, (s8)(var_19));
                        spF0 = func_0034ae50(temp_16_3->list, (s8)(var_19));
                        func_002b83e0((u8 *)temp_30, *(FclDrawPosition *)(posSrc + 0x28), *(FclDrawColor *)((u8 *)temp_22 + 0x75), *(FclDrawColor *)((u8 *)temp_23 + 0x75), (*(u8 *)(sp100+0x5E)), (*(u8 *)(spF0+0x5E)), 32.0f, (*(f32 *)((u8 *)(func_0034ae50(temp_16_3->list, (s8)(var_19)))+(4))), 3, 0, 1, 0);
                    }
                    func_0046d280(sp11C);
                    temp_19_2 = (s16)(var_18);
                    temp_16_4 = (s16)((temp_19_2 + 0x25E));
                    temp_21_2 = func_0046d200(func_00331560(), 0x39);
                    func_002b6a70(temp_16_4, 0xFFU, 0, 0, 3, 0);
                    func_002b6af0(temp_16_4, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    temp_19_3 = (temp_19_2 * 0x17) + 0x14E;
                    func_002b2970(&sp280, (f32) temp_19_3, 110.0f);
                    func_002b2970(&sp278, (f32) temp_19_3, 110.0f + (func_0046b2f0(temp_21_2) / 2.0f));
                    func_002b69f0(temp_16_4, (*(FclVec2f *)&sp280), (*(FclVec2f *)&sp278), 0, 3, 0);
                    func_0046d280(temp_21_2);
                }
                func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                func_002b6140((u8 *)(temp_17->f28C), 1);
                func_002b6140((u8 *)(temp_17->f290), 1);
                temp_17->f1 = 0x7CU;
                return;
            }
            if (D_008C024E[0] & 0x40) {
                temp_16_5 = (s16)(temp_17->f11E);
                if (temp_16_5 < (*(s32 *)((u8 *)(func_002e4870(0))+(8)))) {
                    func_0045af60(0, 0, 0, 1);
                    temp_17->f128 = (s8) temp_17->f11E;
                    temp_17->f129 = -1;
                    basePos = (FclVec2f *)D_00640C10;
                    func_002b2970(&sp270, -380.0f, basePos->y);
                    func_002b2970(&sp268, basePos->x, basePos->y);
                    func_0031c2b0(arg0, temp_17->f11E, *(FclVec2f *)&sp270, *(FclVec2f *)&sp268);
                    for (var_19_2 = 0; var_19_2 < (func_0010b5b0() & 0xFFFF); var_19_2++) {
                        func_002b2970(&sp260, (f32) 0x149, 128.0f);
                        temp_16_6 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_19_2))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_19_2) + 4);
                        func_0031ac10(arg0, sp260, temp_17->f128, var_19_2, temp_16_6, slotByte, 3, 0, 1, 0xCC);
                        temp_16_7 = (s16)(var_19_2);
                        temp_21_3 = temp_16_7 * 0x17;
                        temp_18_2 = (s16 *)(func_0034ae50((u8 *)temp_17->f184, (s8)(var_19_2)));
                        func_002b2970(&sp258, (f32) (temp_21_3 + 0x149), 104.0f);
                        col2F0 = func_002b2a60(0, 0, 0x99, 0xFF);
                        col2EC = func_002b2a60(0, 0, 0x99, 0xFF);
                        func_002b83e0((u8 *)temp_18_2, *(FclDrawPosition *)&sp258, col2F0, col2EC, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                        temp_16_8 = (FclRowList *)((u8 *)temp_17 + temp_16_7 * 4);
                        spE0 = temp_21_3 + 0x7F;
                        for (var_18_2 = 0; var_18_2 < (func_0010b5b0() & 0xFFFF); var_18_2++) {
                            temp_21_4 = var_18_2;
                            spD0 = func_0034ae50(temp_16_8->list, (s8)(var_18_2));
                            func_002b2970(&sp250, (f32) ((temp_21_4 * 0x17) + 0x149), (f32) spE0);
                            temp_21_5 = (s16 *)(func_0034ae50(temp_16_8->list, (s8)(var_18_2)));
                            temp_22_2 = (s16 *)(func_0034ae50(temp_16_8->list, (s8)(var_18_2)));
                            temp_23_2 = (s16 *)(func_0034ae50(temp_16_8->list, (s8)(var_18_2)));
                            temp_30_2 = (s16 *)(func_0034ae50(temp_16_8->list, (s8)(var_18_2)));
                            func_002b83e0(spD0, *(FclDrawPosition *)&sp250, *(FclDrawColor *)((u8 *)temp_21_5 + 0x75), *(FclDrawColor *)((u8 *)temp_22_2 + 0x75), (*(u8 *)((u8 *)(temp_23_2)+(0x5E))), (*(u8 *)((u8 *)(temp_30_2)+(0x5E))), 32.0f, (*(f32 *)((u8 *)(func_0034ae50(temp_16_8->list, (s8)(var_18_2)))+(4))), 3, 0, 1, 0);
                        }
                        temp_18_3 = (s16)(var_19_2);
                        temp_16_9 = (s16)((temp_18_3 + 0x25E));
                        temp_21_6 = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(temp_16_9, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_9, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_4 = (temp_18_3 * 0x17) + 0x14E;
                        func_002b2970(&sp248, (f32) temp_18_4, 110.0f);
                        func_002b2970(&sp240, (f32) temp_18_4, 110.0f + (func_0046b2f0(temp_21_6) / 2.0f));
                        func_002b69f0(temp_16_9, (*(FclVec2f *)&sp248), (*(FclVec2f *)&sp240), 0, 3, 0);
                        func_0046d280(temp_21_6);
                    }
                    func_002b2970(&sp238, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp238, 3, 0);
                    func_003205f0(arg0, 0x94, 0x93);
                    func_0031e320(arg0, temp_17->f128);
                    temp_17->f1 = 0x7EU;
                    return;
                }
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                func_0032fbc0(arg0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                func_00316470(arg0, 1, 1);
                func_0032f4d0(arg0);
                temp_17->f1 = 0x7AU;
                return;
            }
        }
        break;
    case 0x7C:                                      /* switch 1 */
        if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1))) != 1) {
            func_00314450((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f11E), 0, 0);
            temp_16_10 = (s32)(func_003147d0((u8 *)temp_17->f148));
            func_0011d140((u8 *)temp_16_10, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
            temp_17->f1 = 0x7DU;
            return;
        }
        break;
    case 0x7D:                                      /* switch 1 */
        if ((((s8)(func_00314660((u8 *)temp_17->f148))) < 0) || (((s8)(func_00314660((u8 *)temp_17->f148))) > 5)) {
            for (var_16_4 = 0; var_16_4 < (func_0010b5b0() & 0xFFFF); var_16_4++) {
                func_002b2970(&sp230, 16.0f, 128.0f);
                temp_19_4 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_4))+(2)));
                temp_18_5 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_4))+(4)));
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp230, var_16_4, temp_19_4, temp_18_5, 0, 0, partyCount);
            }
            func_002b2970(&sp228, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp228, 0, 0, 0, 0, 0);
            func_003218a0(arg0, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_002b6140((u8 *)(temp_17->f28C), 1);
            func_002b6140((u8 *)(temp_17->f290), 1);
            temp_17->f1 = 0x7BU;
            return;
        }
        break;
    case 0x7A:
        for (var_19_3 = 0; var_19_3 < (func_0010b5b0() & 0xFFFF); var_19_3++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(var_19_3 + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)*(s16 *)(func_002b6150(var_19_3 + 0x21C) + 0x40));
            if (temp_17->f11E == var_19_3) {
                var_18_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_18_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (var_19_3 < *(s32 *)(func_002e4870(0) + 8) - 1) {
                temp_f20 = (f32)(var_19_3 * 0x17 + 0x80);
                func_00275520(113.0f, temp_f20, 43.0f, var_18_3, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, var_19_3)[1] * 0x11), 0, 0, D_00795E60);
            }
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 0
            && (s16)func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_003205f0(arg0, 0x96, 0x93);
            func_00315600(arg0, 0);
            temp_17->f0 = 0;
            temp_17->f1 = 0x1B;
        }
        break;
    case 0x7E:                                      /* switch 1 */
        temp_17->f129 = -1;
        temp_16_12 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_7 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp160 = *(FclVec2f *)(temp_2_4 + 0x38);
        temp_16_13 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_12);
        func_00275820(111.0f + sp160.x, sp160.y, 43.0f, temp_16_13, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_7->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_4 = 0; var_19_4 < (func_0010b5b0() & 0xFFFF); var_19_4++) {
            func_0031d630(arg0, (s8)(var_19_4), temp_17->f128, temp_17->f129, 0);
            if ((((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150((s16)((var_19_4 + 0x270))))+(0x10))), 1))) == 0) && (temp_17->f128 != var_19_4) && ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_17->f128 * 0xC) + var_19_4))+(0x14))) > 0)) {
                if (var_19_4 == temp_17->f11E) {
                    id27D = var_19_4 + 0x27D;
                    id270 = var_19_4 + 0x270U;
                    *(u8 *)(func_002b6150(id270) + 0x6E) = *(u8 *)(func_002b6150(id27D) + 0x6E) = 0xFF;
                    col2E8 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    temp_2_5 = func_002b6150(var_19_4 + 0x297);
                    *(FclDrawColor *)(temp_2_5 + 0x85) = col2E8;
                    temp_2_6 = func_002b6150(var_19_4 + 0x28B);
                    *(FclDrawColor *)(temp_2_6 + 0x85) = *(FclDrawColor *)(temp_2_5 + 0x85);
                    temp_2_7 = func_002b6150(id27D);
                    *(FclDrawColor *)(temp_2_7 + 0x85) = *(FclDrawColor *)(temp_2_6 + 0x85);
                    *(FclDrawColor *)(func_002b6150(id270) + 0x85) = *(FclDrawColor *)(temp_2_7 + 0x85);
                    col2E4 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x2A3) + 0x85) = col2E4;
                    col2E0 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(temp_17->f2BC, var_19_4 + 0xC, *(s32 *)&col2E0);
                    var_18_4 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
                } else {
                    id27D_2 = var_19_4 + 0x27D;
                    id270_2 = var_19_4 + 0x270U;
                    *(u8 *)(func_002b6150(id270_2) + 0x6E) = *(u8 *)(func_002b6150(id27D_2) + 0x6E) = 0xCC;
                    col2DC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_10 = func_002b6150(id27D_2);
                    *(FclDrawColor *)(temp_2_10 + 0x85) = col2DC;
                    *(FclDrawColor *)(func_002b6150(id270_2) + 0x85) = *(FclDrawColor *)(temp_2_10 + 0x85);
                    col2D8 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_12 = func_002b6150(var_19_4 + 0x297);
                    *(FclDrawColor *)(temp_2_12 + 0x85) = col2D8;
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x28B) + 0x85) = *(FclDrawColor *)(temp_2_12 + 0x85);
                    col2D4 = func_002b2a60(0, 0, 0x66, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x2A3) + 0x85) = col2D4;
                    col2D0 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(temp_17->f2BC, var_19_4 + 0xC, *(s32 *)&col2D0);
                    var_18_4 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
                }
                temp_f20 = (f32) ((var_19_4 * 0x17) + 0x80);
                func_00275520((f32) 0x195, temp_f20, 43.0f, var_18_4, 0, 2, (const char *)(iGpffffb440 + ((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_19_4))+(2))) * 0x11)), 0, 0, D_00795E60);
            }
        }
        if ((((s8)(func_00314660((u8 *)temp_17->f148))) < 0) || (((s8)(func_00314660((u8 *)temp_17->f148))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = func_002b2d00(temp_17->f11E, 1, 0, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = func_002b2cb0(temp_17->f11E, 1, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                if ((temp_17->f128 != temp_17->f11E) && ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_17->f128 * 0xC) + temp_17->f11E))+(0x14))) > 0)) {
                    func_0045af60(0, 0, 0, 1);
                    for (var_18_5 = 0; var_18_5 < (func_0010b5b0() & 0xFFFF); var_18_5++) {
                        func_002b2970(&sp220, (f32) 0x149, 128.0f);
                        temp_16_15 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_18_5))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_18_5) + 4);
                        func_0031ac10(arg0, sp220, temp_17->f128, var_18_5, temp_16_15, slotByte, 3, 1, 1, 0xCC);
                    }
                    temp_17->f2F9 = (s8) (temp_17->f128 + 1);
                    temp_17->f2FA = (s8) temp_17->f11E;
                    temp_17->f129 = (s8) temp_17->f11E;
                    for (var_4 = 0; var_4 < 5; var_4++) {
                        temp_17->f30C[var_4] = 0;
                    }
                    temp_3_10 = (s8)(func_00308e50(arg0));
                    switch (temp_3_10) {            /* switch 3; irregular */
                    case 0:                         /* switch 3 */
                        temp_2_15 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_15)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_15)+(0x1C))) + 6);
                        temp_2_16 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_16)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_16)+(0x1D))) + 6);
                        temp_17->f30C[0] = 6;
                        temp_17->f30C[1] = 6;
                        break;
                    case 1:                         /* switch 3 */
                        temp_2_17 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_17)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_17)+(0x1E))) + 6);
                        temp_2_18 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_18)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_18)+(0x1F))) + 6);
                        temp_17->f30C[2] = 6;
                        temp_17->f30C[3] = 6;
                        break;
                    case 2:                         /* switch 3 */
                        temp_2_19 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_19)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_19)+(0x20))) + 6);
                        temp_2_20 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_20)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_20)+(0x1C))) + 6);
                        temp_17->f30C[4] = 6;
                        temp_17->f30C[0] = 6;
                        break;
                    case 3:                         /* switch 3 */
                        temp_2_21 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_21)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_21)+(0x1D))) + 6);
                        temp_2_22 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                        (*(u8 *)((u8 *)(temp_2_22)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_22)+(0x1E))) + 6);
                        temp_17->f30C[1] = 6;
                        temp_17->f30C[2] = 6;
                        break;
                    }
                    func_003144d0((u8 *)temp_17->f148, func_002e48a0(temp_17->f2F9, temp_17->f2FA), 0, 0, 1);
                    temp_16_16 = (s32)(func_003147d0((u8 *)temp_17->f148));
                    func_0011d140((u8 *)temp_16_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
                    temp_17->f1 = 0x81U;
                    for (var_16_5 = 0; var_16_5 < (func_0010b5b0() & 0xFFFF); var_16_5++) {
                        func_002b2970(&sp218, 16.0f, 128.0f);
                        temp_19_5 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_5))+(2)));
                        temp_18_10 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_5))+(4)));
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp218, var_16_5, temp_19_5, temp_18_10, 0, 1, partyCount);
                    }
                    func_002b2970(&sp210, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp210, 0, 1, 0, 0, 0);
                    func_002b2970(&sp208, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp208, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0);
                    func_00325450(arg0, 3, 0);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    return;
                }
            } else {
                if (D_008C024C[0] & 0x80) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_18_6 = 0; var_18_6 < (func_0010b5b0() & 0xFFFF); var_18_6++) {
                        func_002b2970(&sp200, (f32) 0x149, 128.0f);
                        temp_16_17 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_18_6))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_18_6) + 4);
                        func_0031ac10(arg0, sp200, temp_17->f128, var_18_6, temp_16_17, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp1F8, 16.0f, 128.0f);
                        temp_19_6 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_6))+(2)));
                        temp_16_18 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_6))+(4)));
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp1F8, var_18_6, temp_19_6, temp_16_18, 0, 1, partyCount);
                    }
                    func_002b2970(&sp1F0, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1F0, 0, 1, 0, 0, 0);
                    func_002b2970(&sp1E8, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1E8, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    temp_17->f1 = 0x7FU;
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) temp_17->f11E, 0, 0xFF);
                    temp_2_23 = (s8)(temp_17->f128);
                    temp_17->f11E = (s16) temp_2_23;
                    func_0031ddf0(arg0, temp_2_23, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    basePos = (FclVec2f *)D_00640C10;
                    func_002b2970(&sp1E0, basePos->x, basePos->y);
                    func_002b2970(&sp1D8, -380.0f, basePos->y);
                    func_0031c2b0(arg0, temp_17->f128, *(FclVec2f *)&sp1E0, *(FclVec2f *)&sp1D8);
                    func_002b2970(&sp1D0, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1D0, 0, 1);
                    for (var_18_7 = 0; var_18_7 < (func_0010b5b0() & 0xFFFF); var_18_7++) {
                        func_002b2970(&sp1C8, (f32) 0x149, 128.0f);
                        temp_16_19 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_18_7))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_18_7) + 4);
                        func_0031ac10(arg0, sp1C8, temp_17->f128, var_18_7, temp_16_19, slotByte, 0, 1, 1, 0xCC);
                    }
                    func_003218a0(arg0, 3);
                    temp_17->f1 = 0x7BU;
                    return;
                }
            }
        }
        break;
    case 0x7F:                                      /* switch 1 */
        temp_16_20 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_11 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_24 = (u8 *)(func_002b6150(0x7C));
        sp158 = *(FclVec2f *)(temp_2_24 + 0x38);
        temp_16_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_20);
        func_00275820(111.0f + sp158.x, sp158.y, 43.0f, temp_16_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_11->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x270))+(0x10))), 1))) != 1) {
            func_00314450((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f11E), 0, 0);
            temp_16_22 = (s32)(func_003147d0((u8 *)temp_17->f148));
            func_0011d140((u8 *)temp_16_22, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
            temp_17->f1 = 0x80U;
            return;
        }
        break;
    case 0x80:                                      /* switch 1 */
        temp_16_23 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_12 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_25 = (u8 *)(func_002b6150(0x7C));
        sp150 = *(FclVec2f *)(temp_2_25 + 0x38);
        temp_16_24 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_23);
        func_00275820(111.0f + sp150.x, sp150.y, 43.0f, temp_16_24, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_12->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((((s8)(func_00314660((u8 *)temp_17->f148))) < 0) || (((s8)(func_00314660((u8 *)temp_17->f148))) > 5)) {
            for (var_18_8 = 0; var_18_8 < (func_0010b5b0() & 0xFFFF); var_18_8++) {
                func_002b2970(&sp1C0, (f32) 0x149, 128.0f);
                temp_16_25 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_18_8))+(2))));
                slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_18_8) + 4);
                func_0031ac10(arg0, sp1C0, temp_17->f128, var_18_8, temp_16_25, slotByte, 0, 0, 1, 0xCC);
                func_002b2970(&sp1B8, 16.0f, 128.0f);
                temp_19_7 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_8))+(2)));
                temp_16_26 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_8))+(4)));
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp1B8, var_18_8, temp_19_7, temp_16_26, 0, 0, partyCount);
            }
            func_002b2970(&sp1B0, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1B0, 0, 0, 0, 0, 0);
            func_002b2970(&sp1A8, (f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1A8, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_17->f1 = 0x7EU;
            return;
        }
        break;
    case 0x81:                                      /* switch 1 */
        temp_16_27 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_13 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_26 = (u8 *)(func_002b6150(0x7C));
        sp148 = *(FclVec2f *)(temp_2_26 + 0x38);
        temp_16_28 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27);
        func_00275820(111.0f + sp148.x, sp148.y, 43.0f, temp_16_28, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_13->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_5 = 0; var_19_5 < (func_0010b5b0() & 0xFFFF); var_19_5++) {
            func_0031d630(arg0, (s8)(var_19_5), temp_17->f128, temp_17->f129, 0);
            if (var_19_5 == temp_17->f11E) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
            }
            temp_2_27 = (s8)(temp_17->f128);
            if (temp_2_27 != var_19_5) {
                temp_18_14 = (s8)(temp_2_27);
                if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_14 * 0xC) + var_19_5))+(0x14))) > 0) {
                    temp_f20 = (f32) ((var_19_5 * 0x17) + 0x80);
                    func_00275520((f32) 0x195, temp_f20, 43.0f, var_21, 0, 2, (const char *)(iGpffffb440 + ((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_18_14 + 1)), var_19_5))+(2))) * 0x11)), 0, 0, D_00795E60);
                }
            }
        }
        if (temp_17->f122 == 2) {
            func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)temp_17->f30C);
        }
        if (((s8)(func_00314660((u8 *)temp_17->f148))) == 0xD) {
            if (func_0011c610(func_003147d0((u8 *)temp_17->f148)) == 1) {
                func_0011caf0(func_003147d0((u8 *)temp_17->f148));
            }
            if (D_008C024E[0] & 0x40) {
                func_00310960(arg0, 0x1B, 1);
                temp_17->f1 = 0x83U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0((u8 *)temp_17->f148)) == 1) {
                    func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
                    func_00314740((u8 *)temp_17->f148, 1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                temp_17->f1 = 0x82U;
                func_00314670((u8 *)temp_17->f148, 0xB);
                func_00325450(arg0, 3, 1);
                func_00316470(arg0, 1, 0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                temp_17->f129 = -1;
                for (var_18_9 = 0; var_18_9 < (func_0010b5b0() & 0xFFFF); var_18_9++) {
                    func_002b2970(&sp1A0, 16.0f, 128.0f);
                    temp_19_8 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_9))+(2)));
                    temp_16_30 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_9))+(4)));
                    partyCount = *(s8 *)(func_002e4870(0) + 8);
                    func_003191c0(arg0, sp1A0, var_18_9, temp_19_8, temp_16_30, 0, 0, partyCount);
                    func_002b2970(&sp198, (f32) 0x149, 128.0f);
                    temp_16_31 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f128 + 1)), var_18_9))+(2))));
                    slotByte = *(u8 *)((u8 *)func_002e48a0(temp_17->f128 + 1, var_18_9) + 4);
                    func_0031ac10(arg0, sp198, temp_17->f128, var_18_9, temp_16_31, slotByte, 0, 0, 1, 0xCC);
                }
                func_002b2970(&sp190, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp190, 0, 0, 0, 0, 0);
                func_002b2970(&sp188, (f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp188, 0, 0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_00317240(arg0, 1, 0);
                for (var_4_2 = 0; var_4_2 < 5; var_4_2++) {
                    sp2C8[var_4_2] = 0;
                }
                func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2C8);
                temp_4_2 = (s8)(func_00308e50(arg0));
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_2_28 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_28)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_28)+(0x1C))) - 6);
                    temp_2_29 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_29)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_29)+(0x1D))) - 6);
                    return;
                case 1:                             /* switch 4 */
                    temp_2_30 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_30)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_30)+(0x1E))) - 6);
                    temp_2_31 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_31)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_31)+(0x1F))) - 6);
                    return;
                case 2:                             /* switch 4 */
                    temp_2_32 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_32)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_32)+(0x20))) - 6);
                    temp_2_33 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_33)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_33)+(0x1C))) - 6);
                    return;
                case 3:                             /* switch 4 */
                    temp_2_34 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_34)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_34)+(0x1D))) - 6);
                    temp_2_35 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                    (*(u8 *)((u8 *)(temp_2_35)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_35)+(0x1E))) - 6);
                    return;
                }
            } else {
                if (D_008C024E[0] & 8) {
                    if (temp_17->f122 != 2) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    temp_17->f122 = func_002b2cb0((u8) temp_17->f122, 1, 2, 0, 1);
                    ps = func_002b6150(0x151);
                    func_002b2970(&sp180, (f32) ((temp_17->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp180), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp178, (f32) ((temp_17->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp178), 1, 4, 0);
                    for (var_4_3 = 0; var_4_3 < 5; var_4_3++) {
                        sp2C0[var_4_3] = 0;
                    }
                    func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2C0);
                    temp_3_13 = (s8)(temp_17->f122);
                    switch (temp_3_13) {            /* switch 5; irregular */
                    case 0:                         /* switch 5 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 5 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 5 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(temp_17->f2F9, temp_17->f2FA), 0, 0, 1);
                        break;
                    }
                    temp_16_32 = (s32)(func_003147d0((u8 *)temp_17->f148));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 4) {
                    if (temp_17->f122 != 0) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    temp_17->f122 = func_002b2d00(temp_17->f122, 1, 0, 2, 1);
                    ps = func_002b6150(0x151);
                    func_002b2970(&sp170, (f32) ((temp_17->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp170), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp168, (f32) ((temp_17->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp168), 1, 4, 0);
                    for (var_4_4 = 0; var_4_4 < 5; var_4_4++) {
                        sp2B8[var_4_4] = 0;
                    }
                    func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2B8);
                    temp_3_15 = (s8)(temp_17->f122);
                    switch (temp_3_15) {            /* switch 6; irregular */
                    case 0:                         /* switch 6 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 6 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(0, temp_17->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 6 */
                        func_003144d0((u8 *)temp_17->f148, func_002e48a0(temp_17->f2F9, temp_17->f2FA), 0, 0, 1);
                        break;
                    }
                    temp_16_33 = (s32)(func_003147d0((u8 *)temp_17->f148));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 0x80) {
                    if (func_0011c610(func_003147d0((u8 *)temp_17->f148)) == 0) {
                        func_0011c630(func_003147d0((u8 *)temp_17->f148));
                        func_00314740((u8 *)temp_17->f148, 0);
                        return;
                    }
                    func_0011c6e0(func_003147d0((u8 *)temp_17->f148), 1);
                    func_00314740((u8 *)temp_17->f148, 1);
                    return;
                }
            }
        }
        break;
    case 0x82:                                      /* switch 1 */
        temp_16_34 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_15 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_36 = (u8 *)(func_002b6150(0x7C));
        sp140 = *(FclVec2f *)(temp_2_36 + 0x38);
        temp_16_35 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_34);
        func_00275820(111.0f + sp140.x, sp140.y, 43.0f, temp_16_35, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_15->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_6 = 0; var_19_6 < (func_0010b5b0() & 0xFFFF); var_19_6++) {
            func_0031d630(arg0, (s8)(var_19_6), temp_17->f128, temp_17->f129, 0);
            if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150((s16)((var_19_6 + 0x270))))+(0x10))), 1))) == 0) {
                if (var_19_6 == temp_17->f11E) {
                    var_21_2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
                } else {
                    var_21_2 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
                }
                temp_2_37 = (s8)(temp_17->f128);
                if (temp_2_37 != var_19_6) {
                    temp_18_16 = (s8)(temp_2_37);
                    if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_16 * 0xC) + var_19_6))+(0x14))) > 0) {
                        temp_f20 = (f32)(var_19_6 * 0x17 + 0x80);
                        func_00275520((f32)0x195, temp_f20, 43.0f, var_21_2, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(temp_18_16 + 1, var_19_6)[1] * 0x11), 0, 0, D_00795E60);
                    }
                }
            }
        }
        if (((s8)(func_00314660((u8 *)temp_17->f148))) == 0xE) {
            func_002b6140((u8 *)(temp_17->f28C), 0);
            func_002b6140((u8 *)(temp_17->f290), 0);
            temp_17->f1 = 0x7EU;
            return;
        }
        break;
    case 0x83:                                      /* switch 1 */
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        if (func_002bb1c0(temp_17->fD) == 0) {
            func_00106390(0x1306, 1);
            func_00314670((u8 *)temp_17->f148, 0xB);
            func_00325450(arg0, 3, 1);
            func_002b68d0(0x7C, 0, 1);
            func_002b68d0(0x228, 0, 1);
            func_002b68d0(0x1A2, 0, 1);
            func_002b68d0(0x25C, 0, 1);
            func_002b68d0(0x54, 0, 1);
            func_002b68d0(0x26A, 0, 1);
            func_002b68d0(0x26B, 0, 1);
            func_002b68d0(0x74, 0, 1);
            func_00317240(arg0, 1, 0);
            for (var_4_5 = 0; var_4_5 < 5; var_4_5++) {
                sp2B0[var_4_5] = 0;
            }
            func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2B0);
            temp_3_17 = (s8)(func_00308e50(arg0));
            switch (temp_3_17) {                    /* switch 7; irregular */
            case 0:                                 /* switch 7 */
                temp_2_38 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_38)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_38)+(0x1C))) - 6);
                temp_2_39 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_39)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_39)+(0x1D))) - 6);
                break;
            case 1:                                 /* switch 7 */
                temp_2_40 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_40)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_40)+(0x1E))) - 6);
                temp_2_41 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_41)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_41)+(0x1F))) - 6);
                break;
            case 2:                                 /* switch 7 */
                temp_2_42 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_42)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_42)+(0x20))) - 6);
                temp_2_43 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_43)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_43)+(0x1C))) - 6);
                break;
            case 3:                                 /* switch 7 */
                temp_2_44 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_44)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_44)+(0x1D))) - 6);
                temp_2_45 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA));
                (*(u8 *)((u8 *)(temp_2_45)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_45)+(0x1E))) - 6);
                break;
            }
            temp_18_17 = (s8)(func_00308dc0(arg0));
            temp_16_37 = (s8)(func_00308e50(arg0));
            func_00110270((u8 *)func_00308cc0(arg0), ((((s8)(temp_18_17)) << 8) | (((s8)(temp_16_37)) | 0x30)) & 0xFFFF);
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, temp_17->f128))+(2))));
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, temp_17->f129))+(2))));
            func_003205f0(arg0, 0x96, 0x94);
            temp_17->f1 = 0x84U;
        } else {
            temp_17->f1 = 0x81U;
        }
        func_002bb550(temp_17->fD);
        return;
    case 0x84:                                      /* switch 1 */
        if (((s8)(func_00314660((u8 *)temp_17->f148))) == 0xE) {
            func_00315600(arg0, 0);
            func_002b6140((u8 *)(temp_17->f28C), 0);
            func_002b6140((u8 *)(temp_17->f290), 0);
            temp_17->fB6 = 0;
            func_0032f4d0(arg0);
            temp_17->f0 = 0;
            temp_17->f1 = 0x1BU;
            return;
        }
        break;
    case 0x85:                                      /* switch 1 */
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        temp_17->f1 = 0x86U;
        func_002bb550(temp_17->fD);
        temp_16_38 = func_0010b6f0() & 0xFFFF;
        if (temp_16_38 == (func_0010b5b0() & 0xFFFF)) {
            func_00310960(arg0, 0x23, 0);
            temp_17->f1 = 0x87U;
            return;
        }
        if (func_00309630((*(u16 *)((u8 *)(func_001102e0())+(2)))) == 1) {
            func_00310960(arg0, 0x27, 0);
            temp_17->f1 = 0x87U;
            return;
        }
        func_00310960(arg0, 0x1E, 1);
        return;
    case 0x86:                                      /* switch 1 */
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        if (func_002bb1c0(temp_17->fD) == 0) {
            temp_4_3 = func_001102d0() & 0xFFFF;
            if ((((s8)(((temp_4_3 >> 0xC) & 0xF))) >= ((s8)(((temp_4_3 >> 4) & 0xF)))) && (datGetFlag(0x1307) == 0)) {
                temp_2_46 = (s16)(func_003096d0(arg0));
                temp_17->f1C = temp_2_46;
                temp_3_18 = (s16)(temp_2_46);
                if (temp_3_18 == -1) {
                    func_0010b190((u8 *)func_001102e0());
                    func_00106390(0x1306, 0);
                    func_00106390(0x1307, 0);
                    temp_17->fBC = 0x16B;
                    goto block_274;
                }
                temp_16_39 = (u16 *)(iGpffffb3ec + (temp_3_18 * 4));
                temp_17->fD = func_002bab80((void *)func_00331660());
                sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840(*temp_16_39));
                func_002bbd80(temp_17->fD, 0, &sp120);
                func_002bafc0(temp_17->fD, 0);
                func_002badc0(temp_17->fD, 0x24);
                func_002bb0a0(temp_17->fD, 0);
                func_002bbf60();
                temp_17->f1 = 0x88U;
                return;
            }
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            temp_17->fBC = 0x16B;
            for (var_4_6 = 0; var_4_6 < 5; var_4_6++) {
                sp2A8[var_4_6] = 0;
            }
            func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2A8);
            goto block_274;
        }
block_274:
        func_00314670((u8 *)temp_17->f148, 0xB);
        temp_17->f1 = 0x84U;
        func_002bb550(temp_17->fD);
        return;
    case 0x88:                                      /* switch 1 */
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        if (func_002bb1c0(temp_17->fD) == 0) {
            func_002bb550(temp_17->fD);
            temp_17->f2D8 = 0;
            temp_17->f1 = 0x89U;
            return;
        }
        func_002bb550(temp_17->fD);
        func_00314670((u8 *)temp_17->f148, 0xB);
        temp_17->f1 = 0x84U;
        func_0010b190((u8 *)func_001102e0());
        func_00106390(0x1306, 0);
        func_00106390(0x1307, 0);
        temp_17->fBC = 0x16B;
        return;
    case 0x89:                                      /* switch 1 */
        temp_16_40 = (u8 *)(iGpffffb3ec + (temp_17->f1C * 4));
        temp_2_47 = (s16)(func_002b2cb0((u8) temp_17->f2D8, 1, 0x28, 0, 1));
        temp_17->f2D8 = temp_2_47;
        if (((s16)(temp_2_47)) == 0x14) {
            func_0011cc00(func_003147d0((u8 *)temp_17->f148), (s16)(*(u16 *)((u8 *)(temp_16_40)+(0))), (*(u16 *)((u8 *)(temp_16_40)+(2))));
            func_0010cd70((u8 *)func_001102e0(), (s16)(*(u16 *)((u8 *)(temp_16_40)+(0))), (*(u16 *)((u8 *)(temp_16_40)+(2))));
            func_0045af60(1, 3, 3, 2);
        }
        if (temp_17->f2D8 >= 0x28) {
            temp_17->fD = func_002bab80((void *)func_00331660());
            sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840((*(u16 *)((u8 *)(temp_16_40)+(0)))));
            func_002bbd80(temp_17->fD, 0, &sp120);
            sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840((*(u16 *)((u8 *)(temp_16_40)+(2)))));
            func_002bbd80(temp_17->fD, 1, &sp120);
            func_002badc0(temp_17->fD, 0x57);
            temp_17->f1 = 0x87U;
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            temp_17->fBC = 0x16B;
            return;
        }
        break;
    case 0x87:                                      /* switch 1 */
        if (func_002bb680(temp_17->fD) != 0) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        func_00314670((u8 *)temp_17->f148, 0xB);
        temp_17->f1 = 0x84U;
        func_002bb550(temp_17->fD);
        for (var_4_7 = 0; var_4_7 < 5; var_4_7++) {
            sp2A0[var_4_7] = 0;
        }
        func_0011b8f0(func_003147d0((u8 *)temp_17->f148), (s32)&sp2A0);
        break;
    }
}
#pragma pop

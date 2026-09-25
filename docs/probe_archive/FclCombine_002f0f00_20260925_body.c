/* Research only; production func_002f0f00 remains INCLUDE_ASM (see
 * FclCombine_002f0f00_20260925.md). Object 6009 vs retail 6012 instrs;
 * per-case aligned edits 865 (earlier archive 1461). */
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
    s32 f148;
    u8 pad14C[0x8];
    s32 f154;
    u8 pad158[0x2C];
    s32 f184;
    s32 f188;
    u8 pad18C[0x100];
    s32 f28C;
    s32 f290;
    u8 pad294[0x65];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineCtl;

typedef struct {
    u8 pad0[0x154];
    u8 *list;
} FclRowList;

void func_002f0f00(u8 *arg0) {
    u8 *posSrc;
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_00104c70(s32);
    extern void func_002e4610(s32, s8);
    extern void func_00315600(u8 *, s32);
    extern s32 func_003190d0(u8 *);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern s32 func_0010b5b0(void);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
    extern void func_002b2970(void *, f32, f32);
    extern s32 func_0046d200(s32, s32);
    extern s32 func_00331560(void);
    extern f32 func_0046b260(s32);
    extern f32 func_0046b2f0(s32);
    extern void func_0046d280(s32);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);

    extern void func_00314450(u8 *,  u16 *,  s32,  s32);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011d140(u8 *,  s32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011caf0(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_00314740(u8 *,  s32);
    extern u8 *func_003147d0(u8 *);
    extern void func_0045af60(s32, s32, s32, s32);
    extern void func_00314670(u8 *,  s32);
    extern void func_00317240(u8 *, s32, f32);
    extern void func_00325450(u8 *, s32, s32);
    extern s8 func_00314660(u8 *);
    extern void func_00314680(u8 *);
    extern s32 func_002b6970(s16, s32);
    extern u8 *func_002b6150(s16);
    extern void func_00321e60(u8 *, s32, s32, s32);
    extern void func_003233d0(u8 *);
    extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s8, u16, u8, s32, s32, s32, s32);
    extern void func_0031c2b0(u8 *, s64, s32, s32);
    extern void func_0031cce0(u8 *, s64, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00324410(u8 *, s32, s32);
    extern u32 RpRandom(void);
    extern void func_002b68d0(s16, s32, s32);
    extern void func_002bb550(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002e53b0(s32, s32);
    extern void func_002eb270(u8 *, s32);
    extern s32 func_00105f50(s16);
    extern s32 datGetFlag(s32);
    extern void memset(void *, s32, u32);
    extern void func_002e5ae0(s32, void *, s64);
    extern void func_002e6280(s32, void *, s64);
    extern s32 func_0010ce10(u8 *,  u32);
    extern s32 func_0010ceb0(void *);
    extern void func_0010cc20(u8 *,  u16);
    extern s32 func_002bb680(s8);
    extern s32 func_00122720();
    extern void func_00122520(s32, s32);
    extern s64 func_00247770(s32);
    extern s32 func_00312bc0(s32);
    extern void func_003144d0(u8 *,  u16 *,  s32,  s32,  s32);
    extern s32 func_00311930(s32,  u8 *,  s8);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern f32 D_00640C10[];
    extern f32 D_00640C18[];
    extern u8 D_00795E60[];
    extern u16 D_008C024E[];
    extern u16 D_008C024C[];
    extern u16 D_008C027A[];
    extern u8 *iGpffffb440;
    extern u8 *iGpffffb3d4;
    extern f32 iGpffff8504;
    extern void func_002f9c30(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00310a10(u8 *, s32);

    u8 *s0;
    f32 unksp3BC;
    f32 unksp3C4;
    f32 unksp3CC;
    FclDrawColor sp3FC;
    FclDrawColor sp3F8;
    FclDrawColor sp3F4;
    FclDrawColor sp3F0;
    FclDrawColor sp3EC;
    FclDrawColor sp3E8;
    FclDrawColor sp3E4;
    FclDrawColor sp3E0;
    FclDrawColor sp3DC;
    FclDrawColor sp3D8;
    FclVec2f base3A;
    FclVec2f sp3C8;
    FclVec2f sp3C0;
    s64 sp3B8;
    s64 sp3B0;
    s64 sp3A8;
    s64 sp3A0;
    s64 sp398;
    s64 sp390;
    s64 sp388;
    s64 sp380;
    s64 sp378;
    s64 sp370;
    s64 sp368;
    s64 sp360;
    s64 sp358;
    s64 sp350;
    s64 sp348;
    s64 sp340;
    s64 sp338;
    s64 sp330;
    s64 sp328;
    s64 sp320;
    s64 sp318;
    s64 sp310;
    s64 sp308;
    s64 sp300;
    s64 sp2F8;
    s64 sp2F0;
    s64 sp2E8;
    s64 sp2E0;
    s64 sp2D8;
    s64 sp2D0;
    s64 sp2C8;
    s64 sp2C0;
    s64 sp2B8;
    s64 sp2B0;
    s64 sp2A8;
    s64 sp2A0;
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
    FclVec2f sp1E8;
    FclVec2f sp1E0;
    FclVec2f sp1D8;
    FclVec2f sp1D0;
    FclVec2f sp1C8;
    FclVec2f sp1C0;
    FclVec2f sp1B8;
    FclVec2f sp1B0;
    FclVec2f sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    FclVec2f sp180;
    FclVec2f sp178;
    u16 sp150[16];
    u16 sp130[16];
    u8 *sp120;
    u8 *sp110;
    u8 *sp100;
    s32 spF0;
    u8 *spE0;
    u8 *spD0;
    s32 var_16_10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f21;
    f32 var_f1;
    s16 *temp_16_20;
    s16 *temp_16_6;
    s16 *temp_18_14;
    s16 *temp_20_3;
    s16 *temp_21_10;
    s16 *temp_21_12;
    s16 *temp_21_2;
    s16 *temp_21_3;
    s16 *temp_21_7;
    s16 *temp_22;
    s16 *temp_22_2;
    s16 *temp_22_3;
    s16 *temp_22_6;
    s16 *temp_22_7;
    s16 *temp_23;
    s16 *temp_23_2;
    s16 *temp_23_3;
    s16 *temp_23_4;
    s16 *temp_2;
    s16 *temp_30;
    s16 *temp_30_2;
    s16 *temp_30_3;
    s16 temp_16_10;
    s16 temp_16_19;
    s16 temp_16_29;
    s16 temp_2_18;
    s16 temp_3_4;
    s16 temp_5;
    s32 temp_16_22;
    s32 temp_16_23;
    s32 temp_16_24;
    s32 temp_16_26;
    s32 temp_16_28;
    s32 temp_16_35;
    s32 temp_16_36;
    s32 temp_16_37;
    s32 temp_16_38;
    s32 temp_16_39;
    s32 temp_16_3;
    s32 temp_16_43;
    s32 temp_16_45;
    s32 temp_16_48;
    s32 temp_16_4;
    s32 temp_16_50;
    s32 temp_16_52;
    s32 temp_16_54;
    s32 temp_16_55;
    s32 temp_16_56;
    s32 temp_16_57;
    s32 temp_16_58;
    s32 temp_16_60;
    s32 temp_16_63;
    s32 temp_16_64;
    s32 temp_16_65;
    s32 temp_16_66;
    s32 temp_16_68;
    s32 temp_16_72;
    s32 temp_16_74;
    s32 temp_16_7;
    s32 temp_16_9;
    s32 temp_18_11;
    s32 temp_18_20;
    s32 temp_19_7;
    s32 temp_20_5;
    s32 temp_21_4;
    s32 temp_21_5;
    s32 temp_21_8;
    s32 temp_22_4;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 var_18;
    s32 var_19;
    s32 var_19_3;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 temp_16_11;
    s32 temp_16_13;
    s32 temp_16_15;
    s32 temp_16_17;
    s32 temp_16_21;
    s32 temp_16_2;
    s32 temp_16_40;
    s32 temp_16_46;
    s32 temp_16_5;
    s32 temp_16_75;
    s32 temp_16_81;
    s32 temp_16_87;
    s32 temp_18;
    s32 temp_18_10;
    s32 temp_18_12;
    s32 temp_18_15;
    s32 temp_18_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_18_41;
    s32 temp_18_42;
    s32 temp_18_43;
    s32 temp_18_5;
    s32 temp_18_7;
    s32 temp_19;
    s32 temp_19_11;
    s32 temp_19_12;
    s32 temp_19_13;
    s32 temp_19_14;
    s32 temp_19_2;
    s32 temp_19_6;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_4;
    s32 temp_20_6;
    s32 temp_20_8;
    s32 temp_21;
    s32 temp_21_11;
    s32 temp_21_6;
    s32 temp_3_3;
    s16 var_16;
    s16 var_16_11;
    s16 var_16_12;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_4;
    s16 var_16_5;
    s16 var_16_6;
    s16 var_16_7;
    s16 var_16_8;
    s16 var_16_9;
    s32 var_18_2;
    s32 var_18_3;
    s16 var_18_4;
    s16 var_18_5;
    s16 var_18_6;
    s32 var_18_7;
    s32 var_18_8;
    s16 var_18_9;
    s16 var_19_10;
    s32 var_19_11;
    s16 var_19_2;
    s16 var_19_4;
    s16 var_19_5;
    s16 var_19_6;
    s32 var_19_7;
    s32 var_19_8;
    s16 var_19_9;
    s32 var_20;
    s16 var_20_2;
    s16 var_20_3;
    s32 var_21;
    s8 temp_16_14;
    s8 temp_16_61;
    s8 temp_16_69;
    s8 temp_18_16;
    s8 temp_18_28;
    s8 temp_18_39;
    s8 temp_18_44;
    s8 temp_19_15;
    s8 temp_2_10;
    s8 temp_2_11;
    s8 temp_2_5;
    s8 temp_4;
    s8 temp_4_2;
    s8 var_4;
    u16 *temp_16_18;
    u16 *temp_16_83;
    u16 *temp_16_89;
    u16 *temp_18_31;
    u16 *temp_18_34;
    u16 *temp_18_35;
    u16 *temp_21_9;
    u16 *temp_22_5;
    u16 temp_16_30;
    u16 temp_16_32;
    u16 temp_16_34;
    u16 temp_16_41;
    u16 temp_16_76;
    u16 temp_16_77;
    u16 temp_16_78;
    u16 temp_16_82;
    u16 temp_16_84;
    u16 temp_16_88;
    u16 temp_18_13;
    u16 temp_19_10;
    u16 temp_19_3;
    u16 temp_19_4;
    u16 temp_19_5;
    u16 temp_19_8;
    u16 temp_19_9;
    u16 temp_21_13;
    u16 temp_21_14;
    u32 temp_16_79;
    u32 temp_16_80;
    u8 temp_16_25;
    u8 temp_16_27;
    u8 temp_16_31;
    u8 temp_16_33;
    u8 temp_16_42;
    u8 temp_16_44;
    u8 temp_16_49;
    u8 temp_16_51;
    u8 temp_16_53;
    u8 temp_16_59;
    u8 temp_16_67;
    u8 temp_16_71;
    u8 temp_16_73;
    u8 temp_16_85;
    u8 temp_16_86;
    u8 temp_16_8;
    u8 temp_18_17;
    u8 temp_18_22;
    u8 temp_18_27;
    u8 temp_18_38;
    u8 temp_18_40;
    u8 temp_18_4;
    u8 temp_18_9;
    u8 temp_20_7;
    u8 temp_3;
    u8 temp_7;
    u8 temp_7_2;
    u8 temp_7_3;
    u8 *temp_16;
    FclRowList *temp_16_12;
    FclRowList *temp_16_16;
    u8 *temp_16_47;
    u8 *temp_16_62;
    u8 *temp_16_70;
    FclCombineCtl *temp_17;
    u8 slotByte;
    s8 partyCount;
    FclRowList *temp_18_19;
    FclRowList *temp_18_21;
    FclCombineCtl *temp_18_23;
    FclCombineCtl *temp_18_24;
    FclCombineCtl *temp_18_25;
    FclCombineCtl *temp_18_26;
    FclCombineCtl *temp_18_29;
    FclCombineCtl *temp_18_30;
    FclCombineCtl *temp_18_32;
    FclCombineCtl *temp_18_33;
    FclCombineCtl *temp_18_36;
    FclCombineCtl *temp_18_37;
    FclRowList *temp_18_6;
    FclCombineCtl *temp_18_8;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_17 = *(FclCombineCtl **)(arg0 + 0x38);
    temp_3 = (u8)((u8)((u8)(temp_17->f1)));
    switch (temp_3) {                               /* switch 1 */
    case 0x38:                                      /* switch 1 */
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
        temp_17->f1 = 0x39U;
        return;
    case 0x39:                                      /* switch 1 */
        if (func_003190d0(arg0) != 1 && *(s8 *)func_002e4870(0) == 1) {
            for (var_16 = 0; var_16 < (func_0010b5b0() & 0xFFFF); var_16++) {
                sp3FC = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)temp_17->f188, var_16) + 0x75) = sp3FC;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00320b80(arg0, 1);
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_17->f1 = 0x3AU;
            return;
        }
        break;
    case 0x3A:                                      /* switch 1 */
        for (var_16_2 = 0; var_16_2 < (func_0010b5b0() & 0xFFFF); var_16_2++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(var_16_2 + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 0, 255.0f, temp_f20, (f32)*(s16 *)(func_002b6150(var_16_2 + 0x21C) + 0x40));
            if (temp_17->f11E == var_16_2) {
                var_19 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_19 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (var_16_2 < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(var_16_2 * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_19, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, var_16_2)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
            }
        }
        temp_16 = (func_0010b5b0() & 0xFFFF) * 4 + (u8 *)temp_17;
        if (((*(s16 *)func_0034ae50(*(u8 **)(temp_16 + 0x150), (func_0010b5b0() & 0xFFFF) - 1) & 4) >> 2) == 0) {
            temp_f20_2 = (f32)(u32)func_0010b5b0() / 12.0f;
            func_002b2970(&sp3B8, (f32)0x149, 128.0f);
            base3A = *(FclVec2f *)&sp3B8;
            temp_f1 = (f32)((func_0010b5b0() & 0xFFFF) * 0x17) / 2.0f;
            func_002b2970(&sp3C8, base3A.x + temp_f1, base3A.y + temp_f1);
            temp_2_3 = func_0046d200(func_00331560(), 0x7E);
            temp_f22 = temp_f20_2 * func_0046b260(temp_2_3) / 2.0f;
            temp_f21 = temp_f20_2 * func_0046b2f0(temp_2_3) / 2.0f;
            func_0046d280(temp_2_3);
            func_002b2970(&sp3C0, sp3C8.x - temp_f22, sp3C8.y - temp_f21);
            func_002b6c30(0x7E, sp3C0, 156.0f, 0x56);
            func_002b6a70(0x7E, 0, 0xFF, 0, 2, 0);
            *(f32 *)(func_002b6150(0x7E) + 0xAC) = temp_f20_2;
            *(f32 *)(func_002b6150(0x7E) + 0xA0) = temp_f20_2;
            switch (func_0010b5b0() & 0xFFFF) {
            case 12:
                func_002b2970(&sp3B0, sp3C0.x, sp3C0.y - 20.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3B0, 1, 8, 0);
                break;
            case 10:
                func_002b2970(&sp3A8, sp3C0.x, sp3C0.y - 16.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3A8, 1, 8, 0);
                break;
            case 8:
                func_002b2970(&sp3A0, sp3C0.x, sp3C0.y - 13.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3A0, 1, 8, 0);
                break;
            case 6:
                func_002b2970(&sp398, sp3C0.x, sp3C0.y - 10.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp398, 1, 8, 0);
                break;
            }
            *(s8 *)(func_002b6150(0x7E) + 0x47) = 1;
            func_002b6af0(0x7E, temp_f20_2, temp_f20_2, temp_f20_2 - iGpffff8504, temp_f20_2, 0, 4, 4);
            if (temp_17->f128 == -1) {
                temp_17->f11E = 0;
            }
            temp_17->f1 = 0x3DU;
            return;
        }
        break;
    case 0x3B:                                      /* switch 1 */
        for (var_19_2 = 0; var_19_2 < (func_0010b5b0() & 0xFFFF); var_19_2++) {
            temp_f20_3 = (f32)*(s16 *)(func_002b6150(var_19_2 + 0x21C) + 0x42);
            temp_7_2 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20_3, (f32)*(s16 *)(func_002b6150(var_19_2 + 0x21C) + 0x40));
            if (temp_17->f11E == var_19_2) {
                var_18 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_2);
            } else {
                var_18 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_2);
            }
            if (var_19_2 < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(var_19_2 * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_18, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, var_19_2)[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if (((s32)((s32)(((s32) (*func_0034ae50((u8 *)(temp_17->f154),  0) & 4) >> 2))) == (s32)((s32)(0))) && ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) == (s32)((s32)(0)))) {
            func_003205f0(arg0, 0x96, 0x93);
            func_002eb270(arg0, 0U);
            func_00315600(arg0, 0);
            temp_17->f0 = 0;
            temp_17->f1 = 0x1AU;
            return;
        }
        break;
    case 0x3D:                                      /* switch 1 */
        var_21 = -1;
        for (var_16_3 = 0; var_16_3 < (func_0010b5b0() & 0xFFFF); var_16_3++) {
            temp_f20_4 = (f32)*(s16 *)(func_002b6150(var_16_3 + 0x21C) + 0x42);
            temp_7_3 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20_4, (f32)*(s16 *)(func_002b6150(var_16_3 + 0x21C) + 0x40));
            if (temp_17->f11E == var_16_3) {
                var_19_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_3);
            } else {
                var_19_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_3);
            }
            if (var_16_3 < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(var_16_3 * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_19_3, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, var_16_3)[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(var_16_3 + 0x21C) + 0x10), 1) == 1) {
                var_21 = 1;
            }
        }
        if (((s16)(var_21)) == -1) {
            temp_17->f1 = 0x3CU;
            return;
        }
        break;
    case 0x3C:                                      /* switch 1 */
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            func_00321e60(arg0, 1, 0x40, 0x3B);
            return;
        }
        break;
    case 0x3E:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148),  func_002e48a0(0, temp_17->f11E),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_3 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_3,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x3FU;
            return;
        }
        break;
    case 0x3F:                                      /* switch 1 */
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_83;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_83;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_83;
                }
            } else {
                goto block_83;
            }
        } else {
block_83:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                for (var_16_4 = 0; var_16_4 < (func_0010b5b0() & 0xFFFF); var_16_4++) {
                    func_002b2970(&sp390, 16.0f, 128.0f);
                    temp_19_3 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_4)) + (2))));
                    temp_18_4 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_4)) + (4))));
                    partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                    func_003191c0(arg0, sp390, var_16_4, temp_19_3, temp_18_4, 0, 0, partyCount);
                }
                func_002b2970(&sp388, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp388, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (var_19_4 = 0; var_19_4 < (func_0010b5b0() & 0xFFFF); var_19_4++) {
                    temp_18_5 = (s16)(var_19_4);
                    temp_16_4 = temp_18_5 * 0x17;
                    temp_20_3 = (s16 *)(func_0034ae50((u8 *)(temp_17->f184),  (s8)(var_19_4)));
                    func_002b2970(&sp380, (f32) (temp_16_4 + 0x149), 104.0f);
                    sp3F8 = func_002b2a60(0, 0, 0x99, 0xFF);
                    sp3F4 = func_002b2a60(0, 0, 0x99, 0xFF);
                    func_002b83e0((u8 *)temp_20_3, *(FclDrawPosition *)&sp380, sp3F8, sp3F4, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 0, 0);
                    var_20 = 0;
                    temp_18_6 = (FclRowList *)((u8 *)temp_17 + temp_18_5 * 4);
                    for (; (s32)((s32)(((s16)(var_20)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                    temp_16_5 = (s16)(var_20);
                        sp120 = (u8*)((u8*)((u8*)(s32)(func_0034ae50(temp_18_6->list,  (s8)(var_20)))));
                        func_002b2970(&sp378, (f32)((temp_16_5 * 0x17) + 0x149), (f32) (temp_16_4 + 0x7F));
                        temp_16_6 = (s16 *)(func_0034ae50(temp_18_6->list,  (s8)(var_20)));
                        temp_21_2 = (s16 *)(func_0034ae50(temp_18_6->list,  (s8)(var_20)));
                        temp_22 = (s16 *)(func_0034ae50(temp_18_6->list,  (s8)(var_20)));
                        temp_23 = (s16 *)(func_0034ae50(temp_18_6->list,  (s8)(var_20)));
                        func_002b83e0((u8 *)((s16 *) sp120), *(FclDrawPosition *)&sp378, *(FclDrawColor *)((u8 *)temp_16_6 + 0x75), *(FclDrawColor *)((u8 *)temp_21_2 + 0x75), (*(u8 *)((u8 *)(temp_22)+(0x5E))), (*(u8 *)((u8 *)(temp_23)+(0x5E))), 32.0f, (*((f32 *)((u8 *)(func_0034ae50(temp_18_6->list,  (s8)(var_20))) + (4)))), 3, 0, 0, 0);
                        var_20 = (s16)((var_20 + 1));
                    }
                    temp_20_4 = (s16)(var_19_4);
                    temp_18_7 = (s16)((temp_20_4 + 0x25E));
                    temp_16_7 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                    func_002b6a70(temp_18_7, 0U, 0xFF, 0, 3, 0);
                    func_002b6af0(temp_18_7, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, 0);
                    temp_20_5 = (temp_20_4 * 0x17) + 0x14E;
                    func_002b2970(&sp370, (f32) temp_20_5, 110.0f + (func_0046b2f0(temp_16_7) / 2.0f));
                    func_002b2970(&sp368, (f32) temp_20_5, 110.0f);
                    func_002b69f0(temp_18_7, (*(FclVec2f *)&sp370), (*(FclVec2f *)&sp368),  0,  3,  0);
                    func_0046d280(temp_16_7);
                }
                func_002b6140((u8 *)(temp_17->f28C), 0);
                func_002b6140((u8 *)(temp_17->f290), 0);
                temp_17->f1 = 0x3CU;
                return;
            }
        }
        break;
    case 0x40:                                      /* switch 1 */
        temp_17->f129 = -1;
        for (var_16_5 = 0; var_16_5 < (func_0010b5b0() & 0xFFFF); var_16_5++) {
            func_0031d630(arg0, (s8)(var_16_5), temp_17->f128, temp_17->f129, 0);
        }
        temp_16_8 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_8 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp1E8 = *(FclVec2f *)(temp_2_4 + 0x38);
        temp_16_9 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_8)));
        func_00275820(111.0f + sp1E8.x, sp1E8.y, 43.0f, temp_16_9, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_8->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = (s16)((s16)(func_002b2d00(temp_17->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = (s16)((s16)(func_002b2cb0(temp_17->f11E, 1, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_10 = (s16)((s16)((s16)(temp_17->f11E)));
                if (temp_16_10 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_16_6 = 0; var_16_6 < (func_0010b5b0() & 0xFFFF); var_16_6++) {
                        func_002b2970(&sp360, 16.0f, 128.0f);
                        temp_19_4 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_6)) + (2))));
                        temp_18_9 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_6)) + (4))));
                        partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                        func_003191c0(arg0, sp360, var_16_6, temp_19_4, temp_18_9, 0, 1, partyCount);
                    }
                    func_002b2970(&sp358, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp358, 0, 1, 0, 0, 0);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    for (var_19_5 = 0; var_19_5 < (func_0010b5b0() & 0xFFFF); var_19_5++) {
                        temp_16_11 = (s16)(var_19_5);
                        temp_21_3 = (s16 *)(func_0034ae50((u8 *)(temp_17->f184),  (s8)(var_19_5)));
                        func_002b2970(&sp350, (f32)((temp_16_11 * 0x17) + 0x149), 104.0f);
                        sp3F0 = func_002b2a60(0, 0, 0x99, 0xFF);
                        sp3EC = func_002b2a60(0, 0, 0x99, 0xFF);
                        func_002b83e0((u8 *)temp_21_3, *(FclDrawPosition *)&sp350, sp3F0, sp3EC, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                        var_18_2 = 0;
                        temp_16_12 = (FclRowList *)((u8 *)temp_17 + temp_16_11 * 4);
                        for (; (s32)((s32)(((s16)(var_18_2)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            temp_30 = (s16 *)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2)));
                            posSrc = func_0034ae50(temp_16_12->list,  (s8)(var_18_2));
                            temp_22_2 = (s16 *)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2)));
                            temp_23_2 = (s16 *)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2)));
                            sp110 = (u8*)((u8*)((u8*)(s32)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2)))));
                            sp100 = (u8*)((u8*)((u8*)(s32)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2)))));
                            0;
                            func_002b83e0((u8 *)temp_30, *(FclDrawPosition *)(posSrc + 0x28), *(FclDrawColor *)((u8 *)temp_22_2 + 0x75), *(FclDrawColor *)((u8 *)temp_23_2 + 0x75), (*(u8 *)((u8 *)(sp110)+(0x5E))), (*(u8 *)((u8 *)(sp100)+(0x5E))), 32.0f, (*((f32 *)((u8 *)(func_0034ae50(temp_16_12->list,  (s8)(var_18_2))) + (4)))), 3, 0, 1, 0);
                            var_18_2 = (s16)((var_18_2 + 1));
                        }
                        temp_18_10 = (s16)(var_19_5);
                        temp_16_13 = (s16)((temp_18_10 + 0x25E));
                        temp_21_4 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                        func_002b6a70(temp_16_13, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_13, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_11 = (temp_18_10 * 0x17) + 0x14E;
                        func_002b2970(&sp348, (f32) temp_18_11, 110.0f);
                        func_002b2970(&sp340, (f32) temp_18_11, 110.0f + (func_0046b2f0(temp_21_4) / 2.0f));
                        func_002b69f0(temp_16_13, (*(FclVec2f *)&sp348), (*(FclVec2f *)&sp340),  0,  3,  0);
                        func_0046d280(temp_21_4);
                    }
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    temp_17->f1 = 0x41U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_5 = (s16)((s16)((s16)(temp_17->f11E)));
                    if ((temp_17->f128 != temp_5) && ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) temp_5)) + (2)))) != 0)) {
                        func_0045af60(0, 0, 0, 1);
                        temp_17->f129 = (s8)((s8)((s8) temp_17->f11E));
                        func_002b2970(&sp338, -380.0f, 81.0f);
                        func_002b2970(&sp330, (*((f32 *)((u8 *)(&D_00640C18) + (0)))), (*((f32 *)((u8 *)(&D_00640C18) + (4)))));
                        func_0031cce0(arg0, temp_17->f129, sp338, sp330);
                        for (var_19_6 = 0; var_19_6 < (func_0010b5b0() & 0xFFFF); var_19_6++) {
                        temp_18_12 = (s16)(var_19_6);
                            temp_16_14 = (s8)((s8)((s8)(temp_17->f129)));
                            if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_16_14 + 1)))) + (temp_16_14 * 0xC) + temp_18_12)) + (0x14)))) > 0) {
                                func_002b2970(&sp328, (f32) 0x149, 128.0f);
                                temp_18_13 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_19_6)) + (2)))))));
                                slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_16_14 + 1)), var_19_6)) + (4))));
                                func_0031ac10(arg0, sp328, temp_17->f129, var_19_6, temp_18_13, slotByte, 3, 0, 1, 0xCC);
                            }
                            temp_16_15 = (s16)(var_19_6);
                            temp_21_5 = temp_16_15 * 0x17;
                            temp_18_14 = (s16 *)(func_0034ae50((u8 *)(temp_17->f184),  (s8)(var_19_6)));
                            func_002b2970(&sp320, (f32) (temp_21_5 + 0x149), 104.0f);
                            sp3E8 = func_002b2a60(0, 0, 0x99, 0xFF);
                            sp3E4 = func_002b2a60(0, 0, 0x99, 0xFF);
                            func_002b83e0((u8 *)temp_18_14, *(FclDrawPosition *)&sp320, sp3E8, sp3E4, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                            var_18_3 = 0;
                            temp_16_16 = (FclRowList *)((u8 *)temp_17 + temp_16_15 * 4);
                            spF0 = temp_21_5 + 0x7F;
                            for (; (s32)((s32)(((s16)(var_18_3)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            temp_21_6 = (s16)(var_18_3);
                                spE0 = (u8*)((u8*)((u8*)(s32)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3)))));
                                func_002b2970(&sp318, (f32)((temp_21_6 * 0x17) + 0x149), (f32) spF0);
                                temp_21_7 = (s16 *)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3)));
                                temp_22_3 = (s16 *)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3)));
                                temp_23_3 = (s16 *)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3)));
                                temp_30_2 = (s16 *)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3)));
                                func_002b83e0((u8 *)((s16 *) spE0), *(FclDrawPosition *)&sp318, *(FclDrawColor *)((u8 *)temp_21_7 + 0x75), *(FclDrawColor *)((u8 *)temp_22_3 + 0x75), (*(u8 *)((u8 *)(temp_23_3)+(0x5E))), (*(u8 *)((u8 *)(temp_30_2)+(0x5E))), 32.0f, (*((f32 *)((u8 *)(func_0034ae50(temp_16_16->list,  (s8)(var_18_3))) + (4)))), 3, 0, 1, 0);
                                var_18_3 = (s16)((var_18_3 + 1));
                            }
                            temp_16_17 = (s16)(var_19_6);
                            temp_18_15 = (s16)((temp_16_17 + 0x25E));
                            temp_21_8 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                            func_002b6a70(temp_18_15, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_18_15, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_22_4 = (temp_16_17 * 0x17) + 0x14E;
                            func_002b2970(&sp310, (f32) temp_22_4, 110.0f);
                            func_002b2970(&sp308, (f32) temp_22_4, 110.0f + (func_0046b2f0(temp_21_8) / 2.0f));
                            func_002b69f0(temp_18_15, (*(FclVec2f *)&sp310), (*(FclVec2f *)&sp308),  0,  3,  0);
                            func_0046d280(temp_21_8);
                            temp_18_16 = (s8)((s8)((s8)(temp_17->f129)));
                            if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_18_16 + 1)))) + (temp_18_16 * 0xC) + temp_16_17)) + (0x14)))) > 0) {
                                temp_16_18 = (u16 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_19_6));
                                temp_21_9 = (u16 *)(func_002e48a0(0, temp_17->f128));
                                temp_22_5 = (u16 *)(func_002e48a0(0, temp_17->f129));
                                func_002f9c30(temp_16_18, (u8 *)temp_21_9, (u8 *)temp_22_5, (u8 *)func_002e48a0(0, var_19_6), NULL, NULL, NULL, 3, (s8)((temp_18_16 + 1)), (s8)(var_19_6));
                            }
                        }
                        func_002b2970(&sp300, (f32) 0x149, 104.0f);
                        func_0031fa20(arg0, sp300, 3, 0);
                        func_003205f0(arg0, 0x95, 0x94);
                        func_0031e320(arg0, temp_17->f129);
                        temp_17->f1 = 0x43U;
                        return;
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024C[0] & 0x80) {
                    temp_16_19 = (s16)((s16)((s16)(temp_17->f11E)));
                    if (temp_16_19 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                        func_0045af60(0, 1, 0, 3);
                        for (var_16_7 = 0; var_16_7 < (func_0010b5b0() & 0xFFFF); var_16_7++) {
                            func_002b2970(&sp2F8, 16.0f, 128.0f);
                            temp_19_5 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_7)) + (2))));
                            temp_18_17 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_7)) + (4))));
                            partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                            func_003191c0(arg0, sp2F8, var_16_7, temp_19_5, temp_18_17, 0, 1, partyCount);
                        }
                        func_002b2970(&sp2F0, 16.0f, 104.0f);
                        func_0031e5b0(arg0, sp2F0, 0, 1, 0, 0, 0);
                        for (var_20_2 = 0; var_20_2 < (func_0010b5b0() & 0xFFFF); var_20_2++) {
                            temp_18_18 = (s16)(var_20_2);
                            temp_16_20 = (s16 *)(func_0034ae50((u8 *)(temp_17->f184),  (s8)(var_20_2)));
                            func_002b2970(&sp2E8, (f32)((temp_18_18 * 0x17) + 0x149), 104.0f);
                            sp3E0 = func_002b2a60(0, 0, 0x99, 0xFF);
                            sp3DC = func_002b2a60(0, 0, 0x99, 0xFF);
                            func_002b83e0((u8 *)temp_16_20, *(FclDrawPosition *)&sp2E8, sp3E0, sp3DC, 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                            var_19_7 = 0;
                            temp_18_19 = (FclRowList *)((u8 *)temp_17 + temp_18_18 * 4);
                            for (; (s32)((s32)(((s16)(var_19_7)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                                temp_23_4 = (s16 *)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7)));
                                posSrc = func_0034ae50(temp_18_19->list,  (s8)(var_19_7));
                                temp_21_10 = (s16 *)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7)));
                                temp_22_6 = (s16 *)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7)));
                                temp_30_3 = (s16 *)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7)));
                                spD0 = (u8*)((u8*)((u8*)(s32)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7)))));
                                0;
                                func_002b83e0((u8 *)temp_23_4, *(FclDrawPosition *)(posSrc + 0x28), *(FclDrawColor *)((u8 *)temp_21_10 + 0x75), *(FclDrawColor *)((u8 *)temp_22_6 + 0x75), (*(u8 *)((u8 *)(temp_30_3)+(0x5E))), (*((u8 *)((u8 *)(spD0) + (0x5E)))), 32.0f, (*((f32 *)((u8 *)(func_0034ae50(temp_18_19->list,  (s8)(var_19_7))) + (4)))), 3, 0, 1, 0);
                                var_19_7 = (s16)((var_19_7 + 1));
                            }
                            temp_19_6 = (s16)(var_20_2);
                            temp_16_21 = (s16)((((s8)((temp_19_6 + 0x6A))) + 0x1F4));
                            temp_18_20 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                            func_002b6a70(temp_16_21, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_16_21, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_19_7 = (temp_19_6 * 0x17) + 0x14E;
                            func_002b2970(&sp2E0, (f32) temp_19_7, 110.0f);
                            func_002b2970(&sp2D8, (f32) temp_19_7, 110.0f + (func_0046b2f0(temp_18_20) / 2.0f));
                            func_002b69f0(temp_16_21, (*(FclVec2f *)&sp2E0), (*(FclVec2f *)&sp2D8),  0,  3,  0);
                            func_0046d280(temp_18_20);
                        }
                        temp_17->f1 = 0x41U;
                        return;
                    }
                } else if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) temp_17->f11E, 0, 0xFF);
                    temp_2_5 = (s8)((s8)((s8)(temp_17->f128)));
                    temp_17->f11E = (s16) temp_2_5;
                    func_0031ddf0(arg0, temp_2_5, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    func_002b2970(&sp2D0, (*((f32 *)((u8 *)(&D_00640C10) + (0)))), (*((f32 *)((u8 *)(&D_00640C10) + (4)))));
                    func_002b2970(&sp2C8, -380.0f, (*((f32 *)((u8 *)(&D_00640C10) + (4)))));
                    func_0031c2b0(arg0, temp_17->f128, sp2D0, sp2C8);
                    func_0010b5b0();
                    for (var_20_3 = 0; var_20_3 < (func_0010b5b0() & 0xFFFF); var_20_3++) {
                        var_19_8 = 0;
                        temp_3_3 = (s16)(var_20_3);
                        temp_18_21 = (FclRowList *)((u8 *)temp_17 + temp_3_3 * 4);
                        for (; (s32)((s32)(((s16)(var_19_8)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        temp_21_11 = (s16)(var_19_8);
                            temp_22_7 = (s16 *)(func_0034ae50(temp_18_21->list,  (s8)(var_19_8)));
                            func_002b2970(&sp2C0, (f32)((temp_21_11 * 0x17) + 0x149), (f32)((temp_3_3 * 0x17) + 0x7F));
                            temp_21_12 = (s16 *)(func_0034ae50(temp_18_21->list,  (s8)(var_19_8)));
                            sp3D8 = func_002b2a60(0, 0, 0x99, 0xA5);
                            func_002b83e0((u8 *)temp_22_7, *(FclDrawPosition *)&sp2C0, *(FclDrawColor *)((u8 *)temp_21_12 + 0x75), sp3D8, 0xA5U, 0xA5U, 32.0f, (*((f32 *)((u8 *)(func_0034ae50(temp_18_21->list,  (s8)(var_19_8))) + (4)))), 6, 0, 1, 1);
                            var_19_8 = (s16)((var_19_8 + 1));
                        }
                    }
                    func_002b6a70(0x7E, 0U, 0xFF, 0, 3, 3);
                    func_002b68d0(0x7E, 0, 0);
                    temp_17->f1 = 0x3CU;
                    return;
                }
            }
        }
        break;
    case 0x41:                                      /* switch 1 */
        temp_2_6 = (u8 *)(func_002b6150(0x7C));
        sp1E0 = *(FclVec2f *)(temp_2_6 + 0x38);
        temp_16_22 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1E0.x, sp1E0.y, 43.0f, temp_16_22, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_17->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148),  func_002e48a0(0, temp_17->f11E),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_23 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_23,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x42U;
            return;
        }
        break;
    case 0x42:                                      /* switch 1 */
        temp_2_7 = (u8 *)(func_002b6150(0x7C));
        sp1D8 = *(FclVec2f *)(temp_2_7 + 0x38);
        temp_16_24 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1D8.x, sp1D8.y, 43.0f, temp_16_24, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_17->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_166;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_166;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_166;
                }
            } else {
                goto block_166;
            }
        } else {
block_166:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                for (var_16_8 = 0; var_16_8 < (func_0010b5b0() & 0xFFFF); var_16_8++) {
                    func_002b2970(&sp2B8, 16.0f, 128.0f);
                    temp_19_8 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_8)) + (2))));
                    temp_18_22 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_8)) + (4))));
                    partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                    func_003191c0(arg0, sp2B8, var_16_8, temp_19_8, temp_18_22, 0, 0, partyCount);
                }
                func_002b2970(&sp2B0, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp2B0, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_003218a0(arg0, 0);
                func_002b6140((u8 *)(temp_17->f28C), 0);
                func_002b6140((u8 *)(temp_17->f290), 0);
                temp_17->f1 = 0x40U;
                return;
            }
        }
        break;
    case 0x43:                                      /* switch 1 */
        func_003233d0(arg0);
        temp_16_25 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_23 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_8 = (u8 *)(func_002b6150(0x7C));
        sp1D0 = *(FclVec2f *)(temp_2_8 + 0x38);
        temp_16_26 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_25)));
        func_00275820(111.0f + sp1D0.x, sp1D0.y, 43.0f, temp_16_26, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_23->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_27 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_24 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_9 = (u8 *)(func_002b6150(0x7D));
        sp1C8 = *(FclVec2f *)(temp_2_9 + 0x38);
        temp_16_28 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27)));
        func_00275820(111.0f + sp1C8.x, sp1C8.y, 43.0f, temp_16_28, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_24->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1C7)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                func_00324410(arg0, 0x1C7, 0);
                func_00324410(arg0, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = (s16)((s16)(func_002b2d00(temp_17->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = (s16)((s16)(func_002b2cb0(temp_17->f11E, 1, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_29 = (s16)((s16)((s16)(temp_17->f11E)));
                if (temp_16_29 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_18_4 = 0; var_18_4 < (func_0010b5b0() & 0xFFFF); var_18_4++) {
                        func_002b2970(&sp2A8, (f32) 0x149, 128.0f);
                        temp_16_30 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_4)) + (2)))))));
                        slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_4)) + (4))));
                        func_0031ac10(arg0, sp2A8, temp_17->f129, var_18_4, temp_16_30, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp2A0, 16.0f, 128.0f);
                        temp_19_9 = (*((u16 *)((u8 *)(func_002e48a0(0, var_18_4)) + (2))));
                        temp_16_31 = (*((u8 *)((u8 *)(func_002e48a0(0, var_18_4)) + (4))));
                        partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                        func_003191c0(arg0, sp2A0, var_18_4, temp_19_9, temp_16_31, 0, 1, partyCount);
                    }
                    func_002b2970(&sp298, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp298, 0, 1, 0, 0, 0);
                    func_002b2970(&sp290, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp290, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    temp_17->f1 = 0x44U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_3_4 = (s16)((s16)((s16)(temp_17->f11E)));
                    if (temp_17->f128 != temp_3_4) {
                        temp_2_10 = (s8)((s8)((s8)(temp_17->f129)));
                        if ((temp_2_10 != temp_3_4) && ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_2_10 + 1)))) + (temp_17->f129 * 0xC) + temp_17->f11E)) + (0x14)))) > 0)) {
                            func_0045af60(0, 0, 0, 1);
                            for (var_18_5 = 0; var_18_5 < (func_0010b5b0() & 0xFFFF); var_18_5++) {
                                func_002b2970(&sp288, (f32) 0x149, 128.0f);
                                temp_16_32 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_5)) + (2)))))));
                                slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_5)) + (4))));
                                func_0031ac10(arg0, sp288, temp_17->f129, var_18_5, temp_16_32, slotByte, 0, 1, 1, 0xCC);
                                func_002b2970(&sp280, 16.0f, 128.0f);
                                temp_19_10 = (*((u16 *)((u8 *)(func_002e48a0(0, var_18_5)) + (2))));
                                temp_16_33 = (*((u8 *)((u8 *)(func_002e48a0(0, var_18_5)) + (4))));
                                partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                                func_003191c0(arg0, sp280, var_18_5, temp_19_10, temp_16_33, 0, 1, partyCount);
                            }
                            func_002b2970(&sp278, 16.0f, 104.0f);
                            func_0031e5b0(arg0, sp278, 0, 1, 0, 0, 0);
                            func_002b2970(&sp270, (f32) 0x149, 104.0f);
                            func_0031fa20(arg0, sp270, 0, 1);
                            func_00316470(arg0, 1, 1);
                            func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                            func_00317240(arg0, 0, 0);
                            func_002b6140((u8 *)(temp_17->f28C), 1);
                            func_002b6140((u8 *)(temp_17->f290), 1);
                            temp_17->f1 = 0x47U;
                            return;
                        }
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) temp_17->f11E, 0, 0xFF);
                    temp_2_11 = (s8)((s8)((s8)(temp_17->f129)));
                    temp_17->f11E = (s16) temp_2_11;
                    func_0031ddf0(arg0, temp_2_11, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_002b2970(&sp268, (*((f32 *)((u8 *)(&D_00640C18) + (0)))), (*((f32 *)((u8 *)(&D_00640C18) + (4)))));
                    func_002b2970(&sp260, -380.0f, 81.0f);
                    func_0031cce0(arg0, temp_17->f129, sp268, sp260);
                    func_002b2970(&sp258, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp258, 0, 1);
                    for (var_18_6 = 0; var_18_6 < (func_0010b5b0() & 0xFFFF); var_18_6++) {
                        func_002b2970(&sp250, (f32) 0x149, 128.0f);
                        temp_16_34 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_6)) + (2)))))));
                        slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_18_6)) + (4))));
                        func_0031ac10(arg0, sp250, temp_17->f129, var_18_6, temp_16_34, slotByte, 0, 1, 1, 0xCC);
                    }
                    func_003218a0(arg0, 3);
                    func_003205f0(arg0, 0x94, 0x95);
                    temp_17->f1 = 0x40U;
                    return;
                }
            }
        }
        break;
    case 0x44:                                      /* switch 1 */
        temp_2_12 = (u8 *)(func_002b6150(0x7C));
        sp1C0 = *(FclVec2f *)(temp_2_12 + 0x38);
        temp_16_35 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1C0.x, sp1C0.y, 43.0f, temp_16_35, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_17->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_18_25 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_13 = (u8 *)(func_002b6150(0x7D));
        sp1B8 = *(FclVec2f *)(temp_2_13 + 0x38);
        temp_16_36 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1B8.x, sp1B8.y, 43.0f, temp_16_36, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_25->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148),  func_002e48a0(0, temp_17->f11E),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_37 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_37,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x45U;
            return;
        }
        break;
    case 0x45:                                      /* switch 1 */
        temp_2_14 = (u8 *)(func_002b6150(0x7C));
        sp1B0 = *(FclVec2f *)(temp_2_14 + 0x38);
        temp_16_38 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1B0.x, sp1B0.y, 43.0f, temp_16_38, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_17->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_18_26 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_15 = (u8 *)(func_002b6150(0x7D));
        sp1A8 = *(FclVec2f *)(temp_2_15 + 0x38);
        temp_16_39 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1A8.x, sp1A8.y, 43.0f, temp_16_39, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_26->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_215;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_215;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_215;
                }
            } else {
                goto block_215;
            }
        } else {
block_215:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                func_00316470(arg0, 1, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (var_19_9 = 0; var_19_9 < (func_0010b5b0() & 0xFFFF); var_19_9++) {
                temp_16_40 = (s16)(var_19_9);
                    func_002b2970(&sp248, 16.0f, 128.0f);
                    temp_21_13 = (*((u16 *)((u8 *)(func_002e48a0(0, var_19_9)) + (2))));
                    temp_18_27 = (*((u8 *)((u8 *)(func_002e48a0(0, var_19_9)) + (4))));
                    partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                    func_003191c0(arg0, sp248, var_19_9, temp_21_13, temp_18_27, 0, 0, partyCount);
                    temp_18_28 = (s8)((s8)((s8)(temp_17->f129)));
                    if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_18_28 + 1)))) + (temp_18_28 * 0xC) + temp_16_40)) + (0x14)))) > 0) {
                        func_002b2970(&sp240, (f32) 0x149, 128.0f);
                        temp_16_41 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_19_9)) + (2)))))));
                        slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_18_28 + 1)), var_19_9)) + (4))));
                        func_0031ac10(arg0, sp240, temp_17->f129, var_19_9, temp_16_41, slotByte, 0, 0, 1, 0xCC);
                    }
                }
                func_002b2970(&sp238, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp238, 0, 0, 0, 0, 0);
                func_002b2970(&sp230, (f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp230, 0, 0);
                temp_17->f1 = 0x43U;
                return;
            }
        }
        break;
    case 0x47:                                      /* switch 1 */
        temp_16_42 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_29 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_16 = (u8 *)(func_002b6150(0x7C));
        sp1A0 = *((f32 *)((u8 *)(temp_2_16) + (0x38)));
        sp1A4 = *((f32 *)((u8 *)(temp_2_16) + (0x3C)));
        temp_16_43 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_42)));
        func_00275820(111.0f + sp1A0, sp1A4, 43.0f, temp_16_43, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_29->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_44 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_30 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_17 = (u8 *)(func_002b6150(0x7D));
        sp198 = *((f32 *)((u8 *)(temp_2_17) + (0x38)));
        sp19C = *((f32 *)((u8 *)(temp_2_17) + (0x3C)));
        temp_16_45 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_44)));
        func_00275820(111.0f + sp198, sp19C, 43.0f, temp_16_45, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_30->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
            temp_2_18 = (s16)((s16)((s16)(temp_17->f11E)));
            temp_17->f2FA = (s8) temp_2_18;
            temp_16_46 = (s8)(temp_2_18);
            temp_18_31 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_16_46));
            temp_16_47 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_46)));
            temp_19_11 = (s64)((s64)((s16)(func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))))));
            func_003144d0((u8 *)(temp_17->f148),  temp_18_31,  (*(s8 *)((u8 *)(temp_16_47)+(0x2E4))),  func_00311930(temp_19_11, (u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)),  0),  1);
            temp_16_48 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_48,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_16_49 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (4)))))));
            if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_49))) {
                temp_16_50 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                func_0011d140((u8 *)temp_16_50,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
            }
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            func_00325450(arg0, 4, 0);
            temp_17->f1 = 0x46U;
            return;
        }
        break;
    case 0x46:                                      /* switch 1 */
        temp_16_51 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_32 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_19 = (u8 *)(func_002b6150(0x7C));
        sp190 = *((f32 *)((u8 *)(temp_2_19) + (0x38)));
        sp194 = *((f32 *)((u8 *)(temp_2_19) + (0x3C)));
        temp_16_52 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_51)));
        func_00275820(111.0f + sp190, sp194, 43.0f, temp_16_52, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_32->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_53 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_33 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_20 = (u8 *)(func_002b6150(0x7D));
        sp188 = *((f32 *)((u8 *)(temp_2_20) + (0x38)));
        sp18C = *((f32 *)((u8 *)(temp_2_20) + (0x3C)));
        temp_16_54 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_53)));
        func_00275820(111.0f + sp188, sp18C, 43.0f, temp_16_54, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_33->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s8)func_00314660((u8 *)(temp_17->f148))) == (s32)(0xD)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x40) {
                temp_17->f1 = 0x48U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            temp_17 = *(FclCombineCtl **)(arg0 + 0x38);
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148), 0);
                    return;
                }
                func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                func_00314740((u8 *)(temp_17->f148), 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                temp_17->f1 = 0x4EU;
                func_00314670((u8 *)(temp_17->f148),  0xB);
                func_00317240(arg0, 1, 0);
                func_00325450(arg0, 4, 1);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (temp_17->f122 != 3) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_17->f122 = (s8)((s8)(func_002b2cb0((u8) temp_17->f122, 1, 3, 0, 1)));
                s0 = s0 = func_002b6150(0x152);
                func_002b2970(&sp228, (f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp228),  1,  4,  0);
                s0 = s0 = func_002b6150(0x2E0);
                func_002b2970(&sp220, (f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp220),  1,  4,  0);
                temp_4 = (s8)((s8)((s8)(temp_17->f122)));
                switch (temp_4) {                   /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_55 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_55,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f128),  0,  0,  1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_56 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_56,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f129),  0,  0,  1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_57 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_57,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f11E),  0,  0,  1);
                    return;
                case 3:                             /* switch 3 */
                    temp_16_58 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_58,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_59 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_59))) {
                        temp_16_60 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                        func_0011d140((u8 *)temp_16_60,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_61 = (s8)((s8)((s8)(temp_17->f2FA)));
                    temp_18_34 = (u16 *)(func_002e48a0(temp_17->f2F9, (s64) temp_16_61));
                    temp_16_62 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_61)));
                    temp_19_12 = (s64)((s64)((s16)(func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))))));
                    func_003144d0((u8 *)(temp_17->f148),  temp_18_34,  (*(s8 *)((u8 *)(temp_16_62)+(0x2E4))),  func_00311930(temp_19_12, (u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)),  0),  1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (temp_17->f122 != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_17->f122 = (s8)((s8)(func_002b2d00(temp_17->f122, 1, 0, 3, 1)));
                s0 = s0 = func_002b6150(0x152);
                func_002b2970(&sp218, (f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp218),  1,  4,  0);
                s0 = s0 = func_002b6150(0x2E0);
                func_002b2970(&sp210, (f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp210),  1,  4,  0);
                temp_4_2 = (s8)((s8)((s8)(temp_17->f122)));
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_16_63 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_63,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f128),  0,  0,  1);
                    return;
                case 1:                             /* switch 4 */
                    temp_16_64 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_64,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f129),  0,  0,  1);
                    return;
                case 2:                             /* switch 4 */
                    temp_16_65 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_65,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, temp_17->f11E),  0,  0,  1);
                    return;
                case 3:                             /* switch 4 */
                    temp_16_66 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_66,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_67 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_67))) {
                        temp_16_68 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                        func_0011d140((u8 *)temp_16_68,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_69 = (s8)((s8)((s8)(temp_17->f2FA)));
                    temp_18_35 = (u16 *)(func_002e48a0(temp_17->f2F9, (s64) temp_16_69));
                    temp_16_70 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_69)));
                    temp_19_13 = (s64)((s64)((s16)(func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))))));
                    func_003144d0((u8 *)(temp_17->f148),  temp_18_35,  (*(s8 *)((u8 *)(temp_16_70)+(0x2E4))),  func_00311930(temp_19_13, (u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)),  0),  1);
                    return;
                }
            }
        }
        break;
    case 0x4E:                                      /* switch 1 */
        temp_16_71 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_36 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_21 = (u8 *)(func_002b6150(0x7C));
        sp180 = *(FclVec2f *)(temp_2_21 + 0x38);
        temp_16_72 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_71)));
        func_00275820(111.0f + sp180.x, sp180.y, 43.0f, temp_16_72, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_36->f128)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_73 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_37 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_22 = (u8 *)(func_002b6150(0x7D));
        sp178 = *(FclVec2f *)(temp_2_22 + 0x38);
        temp_16_74 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_73)));
        func_00275820(111.0f + sp178.x, sp178.y, 43.0f, temp_16_74, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, temp_18_37->f129)) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(0xE)) {
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            for (var_19_10 = 0; var_19_10 < (func_0010b5b0() & 0xFFFF); var_19_10++) {
            temp_16_75 = (s16)(var_19_10);
                func_002b2970(&sp208, 16.0f, 128.0f);
                temp_21_14 = (*((u16 *)((u8 *)(func_002e48a0(0, var_19_10)) + (2))));
                temp_18_38 = (*((u8 *)((u8 *)(func_002e48a0(0, var_19_10)) + (4))));
                partyCount = (*((s8 *)((u8 *)(func_002e4870(0)) + (8))));
                func_003191c0(arg0, sp208, var_19_10, temp_21_14, temp_18_38, 0, 0, partyCount);
                temp_18_39 = (s8)((s8)((s8)(temp_17->f129)));
                if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_18_39 + 1)))) + (temp_18_39 * 0xC) + temp_16_75)) + (0x14)))) > 0) {
                    func_002b2970(&sp200, (f32) 0x149, 128.0f);
                    temp_16_76 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), var_19_10)) + (2)))))));
                    slotByte = (*((u8 *)((u8 *)(func_002e48a0((s8)((temp_18_39 + 1)), var_19_10)) + (4))));
                    func_0031ac10(arg0, sp200, temp_17->f129, var_19_10, temp_16_76, slotByte, 0, 0, 1, 0xCC);
                }
            }
            func_002b2970(&sp1F8, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1F8, 0, 0, 0, 0, 0);
            func_002b2970(&sp1F0, (f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1F0, 0, 0);
            temp_17->f1 = 0x43U;
            return;
        }
        break;
    case 0x48:                                      /* switch 1 */
        temp_16_77 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2)))))));
        temp_18_40 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (4)))))));
        if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_18_40))) {
            func_00310960(arg0, 0x26, 0);
            temp_17->f1 = 0x4AU;
            return;
        }
        if ((s32)((s32)(func_002e53b0(0, (*((s16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2))))))) == (s32)((s32)(1))) {
            func_00310960(arg0, 0x27, 0);
            temp_17->f1 = 0x4AU;
            return;
        }
        if ((s32)((s32)(((s8)(func_00105f50(temp_16_77))))) == (s32)((s32)(0))) {
            func_00310a10(arg0, temp_16_77);
        } else {
            func_00310960(arg0, (s8)((((s8)(func_00105f50(temp_16_77))) + 0x2E)), 1);
        }
        temp_17->f1 = 0x49U;
        return;
    case 0x49:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680(temp_17->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        if ((s32)((s32)(func_002bb1c0(temp_17->fD))) == (s32)((s32)(0))) {
            temp_17->f1 = 0x4CU;
            func_00122520(1, 0xA);
        } else {
            temp_17->f1 = 0x46U;
        }
        func_002bb550(temp_17->fD);
        return;
    case 0x4A:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680(temp_17->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_17->fD);
            return;
        }
        func_002bb550(temp_17->fD);
        temp_17->f1 = 0x46U;
        return;
    case 0x4C:                                      /* switch 1 */
        if ((s32)((s32)(func_00122720())) != (s32)((s32)(0))) {
            func_00314670((u8 *)(temp_17->f148),  0xB);
            func_00314680((u8 *)(temp_17->f148));
            func_00325450(arg0, 4, 1);
            for (var_16_9 = 0; var_16_9 < 0x30C; var_16_9++) {
                func_002b68d0(var_16_9, 0, 1);
            }
            temp_17->f1 = 0x4BU;
            return;
        }
        break;
    case 0x4B:                                      /* switch 1 */
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(0xE)) {
            temp_17->f1 = 0x4DU;
            return;
        }
        break;
    case 0x4D:                                      /* switch 1 */
        var_16_10 = 3;
        if ((*((s8 *)((u8 *)((func_002e4870(0) + (temp_17->f129 * 0xC) + temp_17->f11E)) + (0x14)))) == 2) {
            var_16_10 = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(func_00312bc0(var_16_10))) == (s32)((s32)(1))) {
                if ((s32)((s32)((u32) (RpRandom() % 1000U))) < (s32)((s32)(0x1F4U))) {
                    temp_17->f1 = 0x4FU;
                    temp_17->fB2 = 1;
                    return;
                }
                temp_17->f1 = 0x50U;
                temp_17->fB2 = 2;
                return;
            }
            temp_17->fB2 = 0;
            temp_17->f0 = 0xD;
            temp_17->f1 = 0xC5U;
            return;
        }
        if ((s32)((s32)((u32) (RpRandom() % 1000U))) < (s32)((s32)(0x1F4U))) {
            temp_17->f1 = 0x4FU;
            temp_17->fB2 = 1;
            return;
        }
        temp_17->f1 = 0x50U;
        temp_17->fB2 = 2;
        return;
    case 0x4F:                                      /* switch 1 */
        memset(&sp150, 0, 0x1A);
        for (var_16_11 = 0; var_16_11 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8)))); var_16_11++) {
            sp150[var_16_11] = (u16)((u16)((u16) (*((u16 *)((u8 *)(func_002e48a0(0, var_16_11)) + (2))))));
        }
        temp_16_78 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA)) + (2)))))));
        sp150[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_78;
        func_002e5ae0(0xD, &sp150, (s8)(func_00104c70(1)));
        temp_16_79 = (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))));
        temp_16_80 = (u32)((u32)((RpRandom() % temp_16_79) * 0xA));
        temp_19_14 = (s64)((s64)((s8)((temp_16_80 % (u32) (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))))))));
        temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
        temp_17->f2FA = (s8)((s8)((s8) temp_17->f11E));
        var_18_7 = 0;
        do {
            temp_16_81 = (s16)(var_18_7);
            if (((s32)((s32)(((s32) ((1 << temp_16_81) & 0xFF & (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + temp_17->f2FA)) + (0x2E4))))) >> temp_16_81))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0(func_002e48a0(0xD, temp_19_14)))) < (s32)((s32)(8)))) {
                temp_16_82 = (u16)((u16)((u16)((*((u16 *)((u8 *)((func_002e48a0((s8)((temp_17->f129 + 1)), temp_17->f11E) + (temp_16_81 * 2))) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(func_002e48a0(0xD, temp_19_14)),  temp_16_82))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(func_002e48a0(0xD, temp_19_14)),  temp_16_82);
                }
            }
            var_18_7 = (s16)((var_18_7 + 1));
        } while ((s32)((s32)(((s16)(var_18_7)))) < (s32)((s32)(8)));
        temp_17->f2F9 = 0xD;
        temp_17->f2FA = (s8) temp_19_14;
        temp_18_42 = (s8)(temp_19_14);
        temp_16_83 = (u16 *)(func_002e48a0(temp_17->f2F9, temp_18_42));
        func_003146f0(temp_17->f148, temp_16_83, (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + ((s8)(temp_18_42)))) + (0x2E4)))));
        temp_17->f0 = 0xD;
        temp_17->f1 = 0xC5U;
        return;
    case 0x50:                                      /* switch 1 */
        var_19_11 = 0x63;
        memset(&sp130, 0, 0x1A);
        for (var_16_12 = 0; var_16_12 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8)))); var_16_12++) {
            sp130[var_16_12] = (u16)((u16)((u16) (*((u16 *)((u8 *)(func_002e48a0(0, var_16_12)) + (2))))));
        }
        temp_16_84 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s8)((temp_17->f129 + 1)), temp_17->f11E)) + (2)))))));
        sp130[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_84;
        func_002e6280(0xD, &sp130, (s8)(func_00104c70(1)));
        if ((*((s32 *)((u8 *)(func_002e4870(0xD)) + (8)))) == 0) {
            temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
            temp_17->f2FA = (s8)((s8)((s8) temp_17->f11E));
            temp_17->f1 = 0x4FU;
            temp_17->fB2 = 1;
            return;
        }
        temp_17->f2F9 = 0xD;
        var_18_8 = 0;
loop_332:
        if (((s16)(var_18_8)) < (*((s32 *)((u8 *)(func_002e4870(0xD)) + (8))))) {
            temp_16_85 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
            if ((s32)((s32)((s32) temp_16_85)) >= (s32)((s32)((func_00104c70(1) & 0xFF)))) {
                temp_17->f2FA = (s8) var_18_8;
            } else {
                temp_20_7 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
                if ((s32)((s32)(((s8)(((func_00104c70(1) & 0xFF) - temp_20_7))))) < (s32)((s32)(((s16)(var_19_11))))) {
                    temp_16_86 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
                    var_19_11 = (s64)((s64)((s8)(((func_00104c70(1) & 0xFF) - temp_16_86))));
                    temp_17->f2FA = (s8) var_18_8;
                }
                var_18_8 = (s16)((var_18_8 + 1));
                goto loop_332;
            }
        }
        temp_19_15 = (s8)((s8)((s8)(temp_17->f2FA)));
        temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
        for (var_18_9 = 0; var_18_9 < 8; var_18_9++) {
            temp_16_87 = (s16)(var_18_9);
            if (((s32)((s32)(((s32) ((1 << temp_16_87) & 0xFF & (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + temp_17->f11E)) + (0x2E4))))) >> temp_16_87))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0(func_002e48a0(0xD, (s64) temp_19_15)))) < (s32)((s32)(8)))) {
                temp_16_88 = (u16)((u16)((u16)((*((u16 *)((u8 *)((func_002e48a0(temp_17->f2F9, temp_17->f11E) + (var_18_9 * 2))) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(func_002e48a0(0xD, (s64) temp_19_15)),  temp_16_88))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(func_002e48a0(0xD, (s64) temp_19_15)),  temp_16_88);
                }
            }
        }
        temp_17->f2F9 = 0xD;
        temp_18_44 = (s8)((s8)((s8)(temp_17->f2FA)));
        temp_16_89 = (u16 *)(func_002e48a0(0xD, (s64) temp_18_44));
        func_003146f0(temp_17->f148, temp_16_89, (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + ((s8)(temp_18_44)))) + (0x2E4)))));
        temp_17->f0 = 0xD;
        temp_17->f1 = 0xC5U;
        break;
    }

}

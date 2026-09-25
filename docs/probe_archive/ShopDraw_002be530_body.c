/* Research only; production func_002be530 (src/Event/Fcl/y_fclShopDraw.c) remains ASM.
 * Rebuilt 2026-09-25 from a fresh m2c run on the retail asm (with both jump
 * tables staged) and mechanically/hand converted; see ShopDraw_002be530_20260925.md.
 * Measured against branch head b3ad114 (MWCCPS2 b210 -O2), spliced with
 * tools/fnalign.py --candidate semantics:
 *   retail 12429 instrs, object 12415 instrs, jal 1525/1525 (every call target
 *   count equal), frame -0x790, $fp + $s0-$s7 + $f20/$f21 saved,
 *   arg0 $s4 / work $s1 (retail), 302 anchored edits (+166 reloc-only),
 *   9959 differing words.
 * REQUIRES these file-scope declaration changes (verified: the file still
 * reports 28 MATCH / 10 ASM with them, same as without):
 *   void func_002e0660(void *, u8, u8, u8, s16, s16);   (was s64 last)
 *   s32 func_002e2830(void *, s32);                      (was s16 return)
 *   s32 func_00106600(s32 id);                           (was s16 param)
 *   s32 func_002e26a0(void);                             (was s16 return)
 *   s32 func_002b2cb0/func_002b2d00/func_002b2d50(...)   (were s16 returns)
 *   s32 func_002e2700(void *);                           (was void)
 *   extern u16 D_008C024E[], D_008C0276[], D_008C027A[]; (were scalars: gp)
 *   s32 func_00106cd0(s16, s16);                         (was s16 return)
 *   u32 func_00106a90(s32);
 * plus, so that matched func_002de5a0 still matches after the func_00106cd0
 * change, its six func_001067f0(func_00106cd0(...)) calls become
 * func_001067f0((s16)func_00106cd0(...)). */
s32 func_002be530(u8 *arg0)
{
    typedef struct { s32 v0; s32 v1; } ShopArgPair;
    extern s32 func_00106330(s32);
    extern u8 func_00110830(s32);
    extern void func_002d8a60(void *, s8, f32, f32);
    extern void func_002dd3b0(void *);
    extern s8 func_002e05a0(void *);
    extern s32 func_002e2740(s16);
    extern s32 func_00442088(char *, const char *, ...);
    extern s32 func_004553c0(void *);
    extern void func_0045af60(s32, s32, s32, s32);
    extern s32 func_0046a750(s32);
    extern u8 D_0063FAA0[];
    extern u8 D_0063FAD0[];
    extern u8 D_00795FE0[];
    extern char iGpffffa878[8];
    extern char iGpffffa880[8];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    extern f32 fGpffff8170;
    extern f32 fGpffff852C;
    extern u8 D_0063F7C8[];
    extern u8 D_0063F7D0[];
    extern u8 D_0063F9F0[];
    extern u8 D_0063F688[];
    extern u8 D_0063F690[];
    extern u8 D_0063FAF0[];
    extern u8 D_0063FB10[];
    extern void func_002be4a0(void);
    extern s32 func_0046aea0(void *);
    extern void func_00440b68(const void *, const void *, s32);
    extern void *func_00454a60(const void *, s32);
    extern s32 H_Cdvd_IsFileLoaded(void *);
    extern s32 datGetFlag(s32);
    extern void func_00106390(s32, s32);
    extern void func_00106620(s32, s32);
    extern u32 func_00106850(s32);
    extern s32 func_00106b50(s16);
    extern void func_00106d40(s16, s16, s16);
    extern void func_00110810(s32, u8);
    extern s64 func_00110a60(s32, s32);
    extern s32 func_002b32a0(s32, s32, s32, s32);
    extern s32 func_002bae80(s64, s32);
    extern s32 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002be160(s32, s32);
    extern void func_002e24a0(s32, s32, s32, s32);
    extern s32 func_002e28f0(void *, s32);
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern void func_002e7a80(s32);
    extern void func_00331fc0(u8 *);
    extern void sprintf(void *, void *, s32);
    extern s32 func_00452380(void *);
    extern u8 func_0045aeb0(s16, const char *);
    extern void func_002e3560(void *, s32, s32, s32, s32);
    extern void func_002dfe00(void *arg0);
    extern s32 func_002dfd00(u16 arg0);
    extern void func_002e02d0(u8 *task);
    extern void func_002caef0(void *arg0);
    extern void func_002cb6c0(void *arg0, s8 arg1);
    extern void func_002cdf80(void *arg0, s8 arg1);
    extern s32 func_002d1590(void *arg0);
    extern void func_002d3ee0(void *arg0);
    extern s8 func_002d4760(void *arg0, s8 arg1);
    extern s32 func_002d4f30(s16 arg0);
    extern void func_002d5040(void *arg0);
    extern void func_002d6190(void *arg0);
    extern void func_002d7300(void *arg0);
    extern void func_002d7f90(void *arg0);
    extern void func_002d8600(void *arg0);
    extern void func_002da0a0(register u8 *root);
    extern void func_002db400(void *arg0);
    extern void func_002dd230(void *arg0);
    extern void func_002de5a0(void *arg0);
    extern void func_002df020(void *arg0, s32 arg1, s32 arg2);
    extern void func_002df4c0(void *arg0);
    extern s32 func_002e0300(s32 arg0, s16 arg1, u32 arg2);
    FclDrawColor sp78C;
    FclDrawColor sp788;
    FclDrawColor sp784;
    FclDrawColor sp780;
    FclDrawColor sp77C;
    FclDrawColor sp778;
    FclDrawColor sp774;
    FclDrawColor sp770;
    FclDrawColor sp76C;
    FclDrawColor sp768;
    FclDrawColor sp764;
    FclDrawColor sp760;
    FclDrawColor sp75C;
    FclDrawColor sp758;
    FclDrawColor sp754;
    FclDrawColor sp750;
    FclDrawColor sp74C;
    FclDrawColor sp748;
    FclDrawColor sp744;
    FclDrawColor sp740;
    FclDrawColor sp73C;
    FclDrawColor sp738;
    FclDrawColor sp734;
    FclDrawColor sp730;
    FclDrawColor sp72C;
    FclDrawColor sp728;
    FclDrawColor sp724;
    FclDrawColor sp720;
    FclDrawColor sp71C;
    FclDrawColor sp718;
    FclDrawColor sp714;
    FclDrawColor sp710;
    FclDrawColor sp70C;
    FclDrawColor sp708;
    FclDrawColor sp704;
    FclDrawColor sp700;
    FclDrawColor sp6FC;
    FclDrawColor sp6F8;
    FclDrawColor sp6F4;
    FclDrawColor sp6F0;
    FclDrawColor sp6EC;
    FclDrawColor sp6E8;
    FclDrawColor sp6E4;
    FclDrawColor sp6E0;
    FclDrawColor sp6DC;
    FclDrawColor sp6D8;
    FclDrawColor sp6D4;
    FclDrawColor sp6D0;
    FclDrawColor sp6CC;
    FclDrawColor sp6C8;
    FclDrawColor sp6C4;
    FclDrawColor sp6C0;
    FclDrawColor sp6BC;
    FclDrawColor sp6B8;
    FclDrawColor sp6B4;
    FclDrawColor sp6B0;
    FclDrawColor sp6AC;
    FclDrawColor sp6A8;
    ShopArgPair sp6A0;
    ShopArgPair sp698;
    ShopArgPair sp690;
    ShopArgPair sp688;
    ShopArgPair sp680;
    ShopArgPair sp678;
    ShopArgPair sp670;
    ShopArgPair sp668;
    Vec2f sp660;
    Vec2f sp658;
    f32 sp654;
    Vec2f sp650;
    Vec2f sp648;
    Vec2f sp640;
    Vec2f sp638;
    Vec2f sp630;
    Vec2f sp628;
    Vec2f sp620;
    Vec2f sp618;
    Vec2f sp610;
    Vec2f sp608;
    Vec2f sp600;
    Vec2f sp5F8;
    Vec2f sp5F0;
    Vec2f sp5E8;
    Vec2f sp5E0;
    Vec2f sp5D8;
    Vec2f sp5D0;
    Vec2f sp5C8;
    Vec2f sp5C0;
    Vec2f sp5B8;
    Vec2f sp5B0;
    Vec2f sp5A8;
    Vec2f sp5A0;
    Vec2f sp598;
    Vec2f sp590;
    Vec2f sp588;
    Vec2f sp580;
    Vec2f sp578;
    Vec2f sp570;
    Vec2f sp568;
    Vec2f sp560;
    Vec2f sp558;
    Vec2f sp550;
    Vec2f sp548;
    Vec2f sp540;
    Vec2f sp538;
    Vec2f sp530;
    Vec2f sp528;
    Vec2f sp520;
    Vec2f sp518;
    Vec2f sp510;
    Vec2f sp508;
    Vec2f sp500;
    Vec2f sp4F8;
    Vec2f sp4F0;
    Vec2f sp4E8;
    Vec2f sp4E0;
    Vec2f sp4D8;
    Vec2f sp4D0;
    Vec2f sp4C8;
    Vec2f sp4C0;
    Vec2f sp4B8;
    Vec2f sp4B0;
    Vec2f sp4A8;
    Vec2f sp4A0;
    Vec2f sp498;
    Vec2f sp490;
    Vec2f sp488;
    Vec2f sp480;
    Vec2f sp478;
    Vec2f sp470;
    Vec2f sp468;
    Vec2f sp460;
    Vec2f sp458;
    Vec2f sp450;
    Vec2f sp448;
    Vec2f sp440;
    Vec2f sp438;
    Vec2f sp430;
    Vec2f sp428;
    Vec2f sp420;
    Vec2f sp418;
    Vec2f sp410;
    Vec2f sp408;
    Vec2f sp400;
    Vec2f sp3F8;
    Vec2f sp3F0;
    Vec2f sp3E8;
    Vec2f sp3E0;
    Vec2f sp3D8;
    Vec2f sp3D0;
    Vec2f sp3C8;
    Vec2f sp3C0;
    Vec2f sp3B8;
    Vec2f sp3B0;
    Vec2f sp3A8;
    Vec2f sp3A0;
    Vec2f sp398;
    Vec2f sp390;
    Vec2f sp388;
    Vec2f sp380;
    Vec2f sp378;
    Vec2f sp370;
    Vec2f sp368;
    Vec2f sp360;
    Vec2f sp358;
    Vec2f sp350;
    Vec2f sp348;
    Vec2f sp340;
    Vec2f sp338;
    Vec2f sp330;
    Vec2f sp328;
    Vec2f sp320;
    Vec2f sp318;
    Vec2f sp310;
    Vec2f sp308;
    Vec2f sp300;
    Vec2f sp2F8;
    Vec2f sp2F0;
    Vec2f sp2E8;
    Vec2f sp2E0;
    Vec2f sp2D8;
    Vec2f sp2D0;
    Vec2f sp2C8;
    Vec2f sp2C0;
    Vec2f sp2B8;
    Vec2f sp2B0;
    Vec2f sp2A8;
    Vec2f sp2A0;
    Vec2f sp298;
    Vec2f sp290;
    Vec2f sp288;
    Vec2f sp280;
    Vec2f sp278;
    Vec2f sp270;
    Vec2f sp268;
    Vec2f sp260;
    Vec2f sp258;
    Vec2f sp250;
    Vec2f sp248;
    Vec2f sp240;
    Vec2f sp238;
    Vec2f sp230;
    Vec2f sp228;
    Vec2f sp220;
    Vec2f sp218;
    Vec2f sp210;
    Vec2f sp208;
    Vec2f sp200;
    Vec2f sp1F8;
    Vec2f sp1F0;
    Vec2f sp1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    Vec2f sp1B0;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    f32 sp154;
    Vec2f sp150;
    char spD0[0x80];
    char spC0[0x10];
    s32 temp_30;
    s32 temp_23_2;
    s32 temp_22_2;
    s32 var_22;
    s32 temp_21_3;
    s32 temp_21_4;
    s32 var_21_2;
    s32 temp_21_5;
    s16 var_21;
    s16 var_21_3;
    s16 var_21_4;
    u32 temp_21_2;
    s32 temp_20;
    s16 var_20;
    s16 var_20_2;
    s16 var_20_3;
    s32 temp_19_8;
    s32 temp_19_3;
    s32 var_19_4;
    s32 temp_19;
    s32 temp_19_11;
    s32 temp_19_2;
    s32 temp_19_5;
    s32 temp_19_7;
    s32 var_19;
    s16 var_19_2;
    s16 var_19_3;
    s16 var_19_5;
    u32 temp_19_4;
    void *temp_19_10;
    void *temp_19_6;
    void *temp_19_9;
    s32 temp_18_52;
    s32 temp_18_53;
    s32 temp_18_57;
    s32 temp_18_51;
    s32 temp_18_54;
    s32 temp_18_55;
    s32 temp_18_56;
    s32 temp_18;
    s32 temp_18_10;
    s32 temp_18_12;
    s32 temp_18_13;
    s32 temp_18_14;
    s32 temp_18_15;
    s32 temp_18_16;
    s32 temp_18_17;
    s32 temp_18_18;
    s32 temp_18_19;
    s32 temp_18_21;
    s32 temp_18_22;
    s32 temp_18_25;
    s32 temp_18_26;
    s32 temp_18_27;
    s32 temp_18_28;
    s32 temp_18_2;
    s32 temp_18_30;
    s32 temp_18_31;
    s32 temp_18_32;
    s32 temp_18_33;
    s32 temp_18_34;
    s32 temp_18_35;
    s32 temp_18_36;
    s32 temp_18_38;
    s32 temp_18_3;
    s32 temp_18_40;
    s32 temp_18_41;
    s32 temp_18_5;
    s32 temp_18_60;
    s32 temp_18_61;
    s32 temp_18_62;
    s32 temp_18_6;
    s32 temp_18_7;
    s32 temp_18_8;
    s32 temp_18_9;
    s16 var_18;
    s16 var_18_2;
    s16 var_18_3;
    s16 var_18_4;
    s16 var_18_5;
    s16 var_18_6;
    u32 temp_18_42;
    u32 temp_18_44;
    u32 temp_18_45;
    u32 temp_18_46;
    u32 temp_18_47;
    u32 temp_18_49;
    void *temp_18_11;
    void *temp_18_20;
    void *temp_18_29;
    f32 *temp_18_37;
    void *temp_18_43;
    void *temp_18_48;
    f32 *temp_18_4;
    void *temp_18_50;
    void *temp_18_58;
    void *temp_18_59;
    f32 *temp_18_63;
    u8 *work;
    u8 temp_3_flag;
    u32 temp_17_2;
    f32 *temp_16_12;
    f32 *temp_16_7;
    s32 temp_16_55;
    s32 temp_16_58;
    s32 temp_16_60;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_83;
    s32 temp_16_85;
    s32 temp_16_86;
    s32 temp_16_91;
    s32 temp_16_93;
    s32 temp_16_29;
    s32 temp_16_39;
    s32 temp_16_43;
    s32 temp_16_44;
    s32 temp_16_4;
    s32 temp_16_52;
    s32 temp_16_57;
    s32 temp_16_59;
    s32 temp_16_5;
    s32 temp_16_65;
    s32 temp_16_6;
    s32 temp_16_74;
    s32 temp_16_75;
    s32 temp_16_76;
    s32 temp_16_78;
    s32 temp_16_79;
    s32 temp_16_81;
    s32 temp_16_82;
    s32 temp_16_87;
    s32 temp_16_94;
    s16 var_16;
    s16 var_16_10;
    s16 var_16_11;
    s16 var_16_12;
    s16 var_16_13;
    s16 var_16_14;
    s16 var_16_15;
    s16 var_16_16;
    s16 var_16_17;
    s16 var_16_18;
    s16 var_16_19;
    s16 var_16_20;
    s16 var_16_21;
    s16 var_16_22;
    s16 var_16_23;
    s16 var_16_24;
    s16 var_16_25;
    s16 var_16_26;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_4;
    s16 var_16_5;
    s16 var_16_6;
    s16 var_16_7;
    s16 var_16_8;
    s16 var_16_9;
    s8 temp_16_90;
    s8 temp_16_92;
    u32 temp_16_50;
    u32 temp_16_54;
    u32 temp_16_61;
    u32 temp_16_63;
    u32 temp_16_77;
    u32 temp_16_80;
    u32 temp_16_84;
    void *temp_16_10;
    void *temp_16_11;
    void *temp_16_13;
    void *temp_16_14;
    void *temp_16_15;
    void *temp_16_16;
    void *temp_16_18;
    void *temp_16_19;
    void *temp_16_20;
    void *temp_16_21;
    void *temp_16_22;
    void *temp_16_23;
    void *temp_16_24;
    void *temp_16_25;
    void *temp_16_26;
    void *temp_16_27;
    void *temp_16_28;
    void *temp_16_30;
    void *temp_16_31;
    void *temp_16_32;
    void *temp_16_33;
    void *temp_16_34;
    void *temp_16_35;
    void *temp_16_36;
    void *temp_16_37;
    f32 *temp_16_38;
    f32 *temp_16_3;
    void *temp_16_41;
    void *temp_16_45;
    void *temp_16_46;
    void *temp_16_47;
    void *temp_16_49;
    void *temp_16_51;
    void *temp_16_53;
    void *temp_16_56;
    void *temp_16_62;
    void *temp_16_64;
    void *temp_16_66;
    void *temp_16_67;
    void *temp_16_68;
    void *temp_16_69;
    void *temp_16_70;
    void *temp_16_71;
    void *temp_16_72;
    void *temp_16_73;
    void *temp_16_8;
    void *temp_16_9;
    void **temp_hp;
    f32 *tbl;
    void *pos;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f0_18;
    f32 temp_f0_19;
    f32 temp_f0_20;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f20_10;
    f32 temp_f20_11;
    f32 temp_f20_12;
    f32 temp_f20_13;
    f32 temp_f20_14;
    f32 temp_f20_15;
    f32 temp_f20_16;
    f32 temp_f20_17;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 temp_f20;
    f32 var_f12;
    f32 var_f12_10;
    f32 var_f12_11;
    f32 var_f12_12;
    f32 var_f12_13;
    f32 var_f12_14;
    f32 var_f12_15;
    f32 var_f12_16;
    f32 var_f12_17;
    f32 var_f12_18;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f12_5;
    f32 var_f12_6;
    f32 var_f12_7;
    f32 var_f12_8;
    f32 var_f12_9;
    s32 temp_2_129;
    s32 temp_2_130;
    s32 temp_2_76;
    s32 temp_2_77;
    s32 temp_2_98;
    s32 temp_4_10;
    s32 temp_4_15;
    s32 temp_4_16;
    s32 temp_4_3;
    s32 temp_4_6;
    s32 temp_4_7;
    s32 temp_4_8;
    s32 temp_4_9;
    s32 temp_4_12;
    s32 temp_4_5;
    s64 temp_2_85;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_13;
    s32 temp_3_14;
    s32 temp_3_21;
    s32 temp_3_22;
    s32 temp_3_24;
    s32 temp_3_25;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_8;
    s32 temp_3_9;
    s32 temp_4;
    s32 temp_4_11;
    s32 temp_4_13;
    s32 temp_4_14;
    s32 temp_4_2;
    s32 temp_4_4;
    s16 var_5;
    s8 temp_2_2;
    s8 temp_2_44;
    s8 temp_2_5;
    s8 temp_2_65;
    s8 temp_2_78;
    s8 temp_2_79;
    s8 temp_2_97;
    s8 temp_3_18;
    s8 temp_3_19;
    s8 var_3;
    s8 var_3_10;
    s8 var_3_11;
    s8 var_3_12;
    s8 var_3_13;
    s8 var_3_14;
    s8 var_3_15;
    s8 var_3_16;
    s8 var_3_17;
    s8 var_3_18;
    s8 var_3_19;
    s8 var_3_20;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_6;
    s8 var_3_7;
    s8 var_3_8;
    s8 var_3_9;
    u32 temp_2_yen;
    u8 temp_2_100;
    u8 temp_2_101;
    u8 temp_2_106;
    u8 temp_2_107;
    u8 temp_2_108;
    u8 temp_2_35;
    u8 temp_2_36;
    u8 temp_2_37;
    u8 temp_2_53;
    u8 temp_2_54;
    u8 temp_2_55;
    u8 temp_2_66;
    u8 temp_2_67;
    u8 temp_2_68;
    u8 temp_2_80;
    u8 temp_2_81;
    u8 temp_2_82;
    u8 temp_2_99;
    u8 temp_5_2;
    u8 temp_6;
    u8 var_3_4;
    u8 var_3_5;
    void *temp_2;
    void *temp_2_102;
    void *temp_2_103;
    void *temp_2_104;
    void *temp_2_105;
    void *temp_2_109;
    void *temp_2_10;
    void *temp_2_110;
    void *temp_2_111;
    void *temp_2_112;
    void *temp_2_113;
    void *temp_2_114;
    void *temp_2_115;
    void *temp_2_116;
    void *temp_2_117;
    void *temp_2_118;
    void *temp_2_119;
    void *temp_2_11;
    void *temp_2_120;
    void *temp_2_121;
    void *temp_2_122;
    void *temp_2_123;
    void *temp_2_124;
    void *temp_2_125;
    void *temp_2_126;
    void *temp_2_127;
    void *temp_2_128;
    void *temp_2_12;
    void *temp_2_131;
    void *temp_2_132;
    void *temp_2_133;
    void *temp_2_134;
    void *temp_2_136;
    void *temp_2_13;
    void *temp_2_14;
    void *temp_2_15;
    void *temp_2_16;
    void *temp_2_17;
    void *temp_2_18;
    void *temp_2_19;
    void *temp_2_20;
    void *temp_2_21;
    void *temp_2_22;
    void *temp_2_23;
    void *temp_2_24;
    void *temp_2_25;
    void *temp_2_26;
    void *temp_2_27;
    void *temp_2_28;
    void *temp_2_29;
    void *temp_2_30;
    void *temp_2_31;
    void *temp_2_32;
    void *temp_2_38;
    void *temp_2_39;
    void *temp_2_3;
    void *temp_2_40;
    void *temp_2_41;
    void *temp_2_46;
    void *temp_2_47;
    void *temp_2_48;
    void *temp_2_49;
    void *temp_2_4;
    void *temp_2_51;
    void *temp_2_56;
    void *temp_2_57;
    void *temp_2_58;
    void *temp_2_59;
    void *temp_2_60;
    void *temp_2_61;
    void *temp_2_62;
    void *temp_2_63;
    void *temp_2_64;
    void *temp_2_69;
    void *temp_2_6;
    void *temp_2_70;
    void *temp_2_71;
    void *temp_2_72;
    void *temp_2_73;
    void *temp_2_74;
    void *temp_2_75;
    void *temp_2_7;
    void *temp_2_83;
    void *temp_2_84;
    void *temp_2_86;
    void *temp_2_87;
    void *temp_2_88;
    void *temp_2_89;
    void *temp_2_8;
    void *temp_2_90;
    void *temp_2_91;
    void *temp_2_92;
    void *temp_2_93;
    void *temp_2_94;
    void *temp_2_95;
    void *temp_2_96;

    work = (*(void * *)(arg0 + 0x38));
    var_19 = 0;
    temp_2 = func_00460990();
    (*(void * *)((u8 *)temp_2 + 8)) = func_002be4a0;
    (*(void * *)((u8 *)temp_2 + 0x10)) = work;
    func_00460ac0(D_00795FE0, temp_2);
    temp_2_2 = (*(s8 *)(work + 0));
    switch (temp_2_2) {                             /* switch 1 */
    case 0x9:                                       /* switch 1 */
        (*(s32 *)(work + 0xF28)) = func_0046aea0(&D_0063FAA0);
        func_00440b68(iGpffffa878, D_0063FAC0, 0x147);
        (*(void * *)(work + 0xF2C)) = func_00454a60(D_0063FAD0, 0);
        (*(s8 *)(work + 0)) = 0xA;
        /* fallthrough */
    case 0xA:                                       /* switch 1 */
        if ((func_0046a750((*(s32 *)(work + 0xF28))) != 0) && (func_004553c0((*(void * *)(work + 0xF2C))) != 0)) {
            (*(s8 *)(work + 0)) = 0xB;
            (*(s8 *)(work + 0xF30)) = 1;
            for (var_16 = 0; var_16 < 0x91; var_16++) {
                (*(s32 *)((u8 *)((work + (var_16 * 4))) + 0xC38)) = func_002e0300((s32) arg0, var_16, (*(u32 *)(work + 0xF28)));
            }
            (*(s32 *)(work + 0xE7C)) = func_002e0300((s32) arg0, 6, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xE80)) = func_002e0300((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xE84)) = func_002e0300((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            for (var_16_2 = 0; var_16_2 < 3; var_16_2++) {
                (*(s32 *)((u8 *)((work + (var_16_2 * 4))) + 0xE88)) = func_002e0300((s32) arg0, (s16) ((s16) ((var_16_2 + 0x61))), (*(u32 *)(work + 0xF28)));
            }
            for (var_16_3 = 0; var_16_3 < 4; var_16_3++) {
                (*(s32 *)((u8 *)((work + (var_16_3 * 4))) + 0xE94)) = func_002e0300((s32) arg0, (s16) ((s16) ((var_16_3 + 0x19))), (*(u32 *)(work + 0xF28)));
            }
            (*(s32 *)(work + 0xEA4)) = func_002e0300((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEA8)) = func_002e0300((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEAC)) = func_002e0300((s32) arg0, 0x20, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB0)) = func_002e0300((s32) arg0, 0x21, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB4)) = func_002e0300((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB8)) = func_002e0300((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEBC)) = func_002e0300((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC0)) = func_002e0300((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC4)) = func_002e0300((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC8)) = func_002e0300((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED4)) = func_002e0300((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED8)) = func_002e0300((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xECC)) = func_002e0300((s32) arg0, 5, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEDC)) = func_002e0300((s32) arg0, 0x2B, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE0)) = func_002e0300((s32) arg0, 0x2C, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED0)) = func_002e0300((s32) arg0, 0x5F, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF14)) = func_002e0300((s32) arg0, 0x5F, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE4)) = func_002e0300((s32) arg0, 0x65, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE8)) = func_002e0300((s32) arg0, 0x66, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEEC)) = func_002e0300((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF0)) = func_002e0300((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF4)) = func_002e0300((s32) arg0, 0x12, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF8)) = func_002e0300((s32) arg0, 0xE, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEFC)) = func_002e0300((s32) arg0, 0x13, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF00)) = func_002e0300((s32) arg0, 0xF, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF04)) = func_002e0300((s32) arg0, 0x10, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF08)) = func_002e0300((s32) arg0, 0x8C, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF0C)) = func_002e0300((s32) arg0, 0x8D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF10)) = func_002e0300((s32) arg0, 0x8E, (*(u32 *)(work + 0xF28)));
            temp_2_3 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x48);
            temp_f21 = 632.0f + func_0046b260(temp_2_3);
            func_0046d280(temp_2_3);
            temp_2_4 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x47);
            temp_f20 = 136.0f + func_0046b2f0(temp_2_4);
            func_0046d280(temp_2_4);
            temp_f1 = (f32) 0x1A3;
            (*(f32 *)(work + 0xF34)) = (f32) (temp_f1 + ((temp_f21 - temp_f1) / 2.0f));
            (*(f32 *)(work + 0xF38)) = (f32) (65.0f + ((temp_f20 - 65.0f) / 2.0f));
            (*(s8 *)(work + 0xF73)) = 1;
            (*(s8 *)(work + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0(1, 0)))));
            (*(s8 *)(work + 9)) = 1;
            if (func_00106330(0x30) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 2;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (func_00106330(0x31) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 3;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (func_00106330(0x32) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 4;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (func_00106330(0x33) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 6;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (func_00106330(0x35) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 8;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (func_00106330(0x36) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 7;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = func_002d4f30((s16) ((s16) (func_00106880(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            for (var_5 = 0; var_5 < 9; var_5++) {
                (*(s16 *)(work + (var_5 * 2) + 0xF46)) = (s16) (var_5 * 3);
                (*(s16 *)(work + (var_5 * 2) + 0xF58)) = 0;
                (*(s8 *)((u8 *)((work + var_5)) + 0xF6A)) = 0;
            }
            (*(s8 *)(work + 8)) = 0;
        }
        break;
    case 0xC:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            func_002bb550((*(s8 *)(work + 0x10)));
            func_00106390(0x1324, 1);
            (*(s8 *)(work + 0)) = 0xD;
        }
        break;
    case 0xD:                                       /* switch 1 */
        if ((func_002e26f0((*(void * *)(work + 0xF18))) > D_00748908[0]) && (func_00106330(0x1324) == 0)) {
            temp_2_5 = func_002bab80((*(void * *)((u8 *)((*(void * *)(work + 0xF2C))) + 0x110)));
            (*(s8 *)(work + 0x10)) = temp_2_5;
            func_002bae80((*(s8 *)(work + 0x10)), 0xB);
            (*(s8 *)(work + 0)) = 0xC;
            return 0;
        }
        temp_16 = func_002e78a0() & 0xFF;
        if (((s8) (func_00110a60(temp_16, func_002e78e0() & 0xFF))) == 1) {
            temp_16_2 = func_002e78e0() & 0xFF;
            temp_3_2 = (s16) ((temp_16_2 + ((func_002e78a0() & 0xFF) * 0x64)));
            if ((temp_3_2 >= 0x190) && (temp_3_2 < 0x207)) {
                (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 0xC, (*(void * *)((u8 *)((*(void * *)(work + 0xF2C))) + 0x110)), 0);
            } else {
                (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 0xD, (*(void * *)((u8 *)((*(void * *)(work + 0xF2C))) + 0x110)), 0);
            }
        } else {
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 0xC, (*(void * *)((u8 *)((*(void * *)(work + 0xF2C))) + 0x110)), 0);
        }
        (*(s8 *)(work + 0)) = 0xF;
        break;
    case 0xF:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            func_002bb550((*(s8 *)(work + 0x10)));
            (*(s8 *)(work + 0)) = 0xE;
        }
        break;
    case 0xE:                                       /* switch 1 */
        (*(s8 *)(work + 7)) = 0;
        temp_16_3 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
        func_002e09e0((*(void * *)(work + 0xC44)), 0x41, 126.0f);
        temp_f20_2 = temp_16_3[0];
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_2;
        temp_f20_3 = temp_16_3[1];
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_3;
        sp78C = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
        temp_2_6 = func_002e04e0((*(void * *)(work + 0xC44)));
        *(FclDrawColor *)((u8 *)temp_2_6 + 0x79) = sp78C;
        sp648 = func_002b2970(temp_16_3[0] - 80.0f, temp_16_3[1]);
        sp640 = func_002b2970(temp_16_3[0], temp_16_3[1]);
        func_002e0620((*(void * *)(work + 0xC44)), *(u64 *)&sp648, *(u64 *)&sp640, 0, 3, (s16) ((s16) (((*(s8 *)(work + 7)) + 1))));
        func_002e0660((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 3, (s16) (((*(s8 *)(work + 7)) + 1)));
        func_002e09e0((*(void * *)(work + 0xC48)), 0x41, 127.0f);
        temp_f20_4 = temp_16_3[0] + temp_16_3[2];
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_4;
        temp_f20_5 = temp_16_3[1];
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_5;
        sp788 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
        temp_2_7 = func_002e04e0((*(void * *)(work + 0xC48)));
        *(FclDrawColor *)((u8 *)temp_2_7 + 0x79) = sp788;
        sp638 = func_002b2970((temp_16_3[0] + temp_16_3[2]) - 80.0f, temp_16_3[1]);
        sp630 = func_002b2970(temp_16_3[0] + temp_16_3[2], temp_16_3[1]);
        func_002e0620((*(void * *)(work + 0xC48)), *(u64 *)&sp638, *(u64 *)&sp630, 0, 3, (s16) ((s16) (((*(s8 *)(work + 7)) + 1))));
        func_002e0660((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 3, (s16) (((*(s8 *)(work + 7)) + 1)));
        func_002d7f90(arg0);
        for (var_20 = 0; var_20 < 7; var_20++) {
            temp_18_4 = (f32 *)(D_0063F560 + ((var_20 + 0x3A) * 8));
            func_002e09e0((*(void * *)(work + (var_20 * 4) + 0xD20)), 0x56, (f32) (var_20 + 0x64));
            if (var_20 > 0) {
                sp784 = func_002b2a60(0xED, 0x80, 0, 0xFF);
                temp_2_8 = func_002e04e0((*(void * *)(work + (var_20 * 4) + 0xD20)));
                *(FclDrawColor *)((u8 *)temp_2_8 + 0x79) = sp784;
            }
            sp628 = func_002b2970(80.0f + temp_18_4[0], temp_18_4[1]);
            sp620 = func_002b2970(temp_18_4[0], temp_18_4[1]);
            func_002e0620((*(void * *)(work + ((var_20) * 4) + 0xD20)), *(u64 *)&sp628, *(u64 *)&sp620, 0, 3, var_20);
            func_002e0660((*(void * *)(work + ((var_20) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_20);
        }
        sp780 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        temp_2_10 = func_002e04e0((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))]));
        *(FclDrawColor *)((u8 *)temp_2_10 + 0x79) = sp780;
        func_002e09e0((*(void * *)(work + 0xC3C)), 0x41, 184.0f);
        sp77C = func_002b2a60(0x5A, 0, 2, 0xFF);
        temp_2_11 = func_002e04e0((*(void * *)(work + 0xC3C)));
        *(FclDrawColor *)((u8 *)temp_2_11 + 0x79) = sp77C;
        func_002e09e0((*(void * *)(work + 0xC38)), 0x56, 182.0f);
        func_002e09e0((*(void * *)(work + 0xC40)), 0x56, 183.0f);
        sp778 = func_002b2a60(0xFE, 0xBE, 0x1E, 0xFF);
        temp_2_12 = func_002e04e0((*(void * *)(work + 0xC40)));
        *(FclDrawColor *)((u8 *)temp_2_12 + 0x79) = sp778;
        temp_2_13 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 2);
        temp_18_5 = (s16) (((func_0046b260(temp_2_13) / 2.0f)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC40)))) + 0x100)) = (s16) temp_18_5;
        temp_18_6 = (s16) (((func_0046b2f0(temp_2_13) / 2.0f)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC40)))) + 0x102)) = (s16) temp_18_6;
        func_0046d280(temp_2_13);
        func_002e0940((*(void * *)(work + 0xC40)), -90.0f, -90.0f, 0, 0, 0);
        func_002e09e0((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
        sp774 = func_002b2a60(0, 0, 0, 0xFF);
        temp_2_14 = func_002e04e0((*(void * *)(work + 0xC4C)));
        *(FclDrawColor *)((u8 *)temp_2_14 + 0x79) = sp774;
        temp_2_15 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 5);
        temp_18_7 = (s16) ((func_0046b260(temp_2_15)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) temp_18_7;
        temp_18_8 = (s16) ((func_0046b2f0(temp_2_15)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) temp_18_8;
        func_0046d280(temp_2_15);
        func_002e0660((*(void * *)(work + 0xC4C)), 0U, 0xA0U, 0U, 4, 4);
        func_002e0940((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
        sp618 = func_002b2970(-240.0f, 400.0f);
        sp610 = func_002b2970(-240.0f, 310.0f);
        func_002e0620((*(void * *)(work + 0xC4C)), *(u64 *)&sp618, *(u64 *)&sp610, 0, 4, 4);
        func_002e09e0((*(void * *)(work + 0xC50)), 0x40, 192.0f);
        sp770 = func_002b2a60(0xFF, 0xBE, 0x22, 0xFF);
        temp_2_16 = func_002e04e0((*(void * *)(work + 0xC50)));
        *(FclDrawColor *)((u8 *)temp_2_16 + 0x79) = sp770;
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
        temp_2_17 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
        temp_16_4 = (s16) ((func_0046b260(temp_2_17)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) temp_16_4;
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
        func_002e0940((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 0);
        func_0046d280(temp_2_17);
        func_002e0660((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 0);
        func_002e09e0((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
        (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
        sp76C = func_002b2a60(0xED, 0x81, 3, 0xFF);
        temp_2_18 = func_002e04e0((void *) (*(s32 *)(work + 0xE7C)));
        *(FclDrawColor *)((u8 *)temp_2_18 + 0x79) = sp76C;
        temp_2_19 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
        temp_16_5 = (s16) ((func_0046b260(temp_2_19)));
        (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) temp_16_5;
        (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
        func_0046d280(temp_2_19);
        func_002e0940((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
        func_002e0660((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
        func_002e09e0((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
        func_002e0660((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x2C)) = 198.0f;
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x30)) = (f32) 0x151;
        func_002e09e0((*(void * *)(work + 0xDEC)), 0x41, 146.0f);
        func_002e0660((*(void * *)(work + 0xDEC)), 0U, 0xFFU, 0U, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDEC)))) + 0x2C)) = 216.0f;
        (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDEC)))) + 0x30)) = 368.0f;
        func_002e09e0((*(void * *)(work + 0xD8C)), 0x3F, 207.0f);
        sp768 = func_002b2a60(0xFF, 0xAE, 0, 0xFF);
        temp_2_20 = func_002e04e0((*(void * *)(work + 0xD8C)));
        *(FclDrawColor *)((u8 *)temp_2_20 + 0x79) = sp768;
        func_002e0940((*(void * *)(work + 0xD8C)), 0.0f, 360.0f, 0, 0x708, 0);
        func_002e04f0((*(void * *)(work + 0xD8C)), 6, 0);
        func_002e09e0((*(void * *)(work + 0xD90)), 0x3D, 209.0f);
        sp764 = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
        temp_2_21 = func_002e04e0((*(void * *)(work + 0xD90)));
        *(FclDrawColor *)((u8 *)temp_2_21 + 0x79) = sp764;
        temp_2_22 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x56);
        temp_18_9 = (s16) ((func_0046b260(temp_2_22)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD90)))) + 0x100)) = (s16) temp_18_9;
        temp_18_10 = (s16) (((func_0046b2f0(temp_2_22) / 2.0f)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD90)))) + 0x102)) = (s16) temp_18_10;
        func_0046d280(temp_2_22);
        func_002e0940((*(void * *)(work + 0xD90)), 0.0f, 360.0f, 0, 0x5A0, 0);
        func_002e04f0((*(void * *)(work + 0xD90)), 6, 0);
        func_002e0660((*(void * *)(work + 0xD90)), 0U, 0xFFU, 0U, 0xA, 0);
        func_002e09e0((*(void * *)(work + 0xD94)), 0x3D, 210.0f);
        sp760 = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
        temp_2_23 = func_002e04e0((*(void * *)(work + 0xD94)));
        *(FclDrawColor *)((u8 *)temp_2_23 + 0x79) = sp760;
        temp_18_11 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x57);
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD94)))) + 0x100)) = 0;
        temp_16_6 = (s16) (((func_0046b2f0(temp_18_11) / 2.0f)));
        (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD94)))) + 0x102)) = (s16) temp_16_6;
        func_0046d280(temp_18_11);
        func_002e0940((*(void * *)(work + 0xD94)), 0.0f, 360.0f, 0, 0x5A0, 0);
        func_002e04f0((*(void * *)(work + 0xD94)), 6, 0);
        func_002e0660((*(void * *)(work + 0xD94)), 0U, 0xFFU, 0U, 0xA, 0);
        for (var_16_4 = 0x59; var_16_4 < 0x60; var_16_4++) {
            sp75C = func_002b2a60(0xFF, 0xAE, 0, 0xFF);
            temp_2_24 = func_002e04e0((*(void * *)((u8 *)((work + (var_16_4 * 4))) + 0xC38)));
            *(FclDrawColor *)((u8 *)temp_2_24 + 0x79) = sp75C;
        }
        for (var_16_5 = 0x64; var_16_5 < 0x67; var_16_5++) {
            sp758 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
            temp_2_25 = func_002e04e0((*(void * *)((u8 *)((work + (var_16_5 * 4))) + 0xC38)));
            *(FclDrawColor *)((u8 *)temp_2_25 + 0x79) = sp758;
        }
        (*(s8 *)(work + 0)) = 0x10;
        (*(s16 *)(work + 0xC26)) = 1;
        break;
    case 0x10:                                      /* switch 1 */
        if (D_008C027A[0] & 0x4000) {
            (*(s8 *)(work + 7)) = func_002b2cb0((s32) (*(s8 *)(work + 7)), 1, 5, 0, 2);
            func_002d7f90(arg0);
            temp_16_7 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
            temp_f20_6 = temp_16_7[0];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_6;
            temp_f20_7 = temp_16_7[1];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_7;
            temp_f20_8 = temp_16_7[0] + temp_16_7[2];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_8;
            temp_f20_9 = temp_16_7[1];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_9;
            temp_16_8 = func_002e04e0((*(void * *)(work + 0xC44)));
            sp608 = func_002b2970((*(f32 *)((u8 *)temp_16_8 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)) - 4.0f);
            temp_16_9 = func_002e04e0((*(void * *)(work + 0xC44)));
            sp600 = func_002b2970((*(f32 *)((u8 *)temp_16_9 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xC44)), *(u64 *)&sp608, *(u64 *)&sp600, 1, 2, 0);
            temp_16_10 = func_002e04e0((*(void * *)(work + 0xC48)));
            sp5F8 = func_002b2970((*(f32 *)((u8 *)temp_16_10 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)) - 4.0f);
            temp_16_11 = func_002e04e0((*(void * *)(work + 0xC48)));
            sp5F0 = func_002b2970((*(f32 *)((u8 *)temp_16_11 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xC48)), *(u64 *)&sp5F8, *(u64 *)&sp5F0, 1, 2, 0);
            for (var_16_6 = 0; var_16_6 < 6; var_16_6++) {
                sp754 = func_002b2a60(0xED, 0x80, 0, 0xFF);
                temp_2_26 = func_002e04e0((*(void * *)((u8 *)((work + (var_16_6 * 4))) + 0xD24)));
                *(FclDrawColor *)((u8 *)temp_2_26 + 0x79) = sp754;
            }
            sp750 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            temp_2_27 = func_002e04e0((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))]));
            *(FclDrawColor *)((u8 *)temp_2_27 + 0x79) = sp750;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            (*(s8 *)(work + 7)) = func_002b2d00((s32) (*(s8 *)(work + 7)), 1, 0, 5, 2);
            func_002d7f90(arg0);
            temp_16_12 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
            temp_f20_10 = temp_16_12[0];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_10;
            temp_f20_11 = temp_16_12[1];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_11;
            temp_f20_12 = temp_16_12[0] + temp_16_12[2];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_12;
            temp_f20_13 = temp_16_12[1];
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_13;
            temp_16_13 = func_002e04e0((*(void * *)(work + 0xC44)));
            sp5E8 = func_002b2970((*(f32 *)((u8 *)temp_16_13 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)) - 4.0f);
            temp_16_14 = func_002e04e0((*(void * *)(work + 0xC44)));
            sp5E0 = func_002b2970((*(f32 *)((u8 *)temp_16_14 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xC44)), *(u64 *)&sp5E8, *(u64 *)&sp5E0, 1, 2, 0);
            temp_16_15 = func_002e04e0((*(void * *)(work + 0xC48)));
            sp5D8 = func_002b2970((*(f32 *)((u8 *)temp_16_15 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)) - 4.0f);
            temp_16_16 = func_002e04e0((*(void * *)(work + 0xC48)));
            sp5D0 = func_002b2970((*(f32 *)((u8 *)temp_16_16 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xC48)), *(u64 *)&sp5D8, *(u64 *)&sp5D0, 1, 2, 0);
            for (var_16_7 = 0; var_16_7 < 6; var_16_7++) {
                sp74C = func_002b2a60(0xED, 0x80, 0, 0xFF);
                temp_2_28 = func_002e04e0((*(void * *)((u8 *)((work + (var_16_7 * 4))) + 0xD24)));
                *(FclDrawColor *)((u8 *)temp_2_28 + 0x79) = sp74C;
            }
            sp748 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            temp_2_29 = func_002e04e0((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))]));
            *(FclDrawColor *)((u8 *)temp_2_29 + 0x79) = sp748;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            func_002e0940((*(void * *)(work + 0xC44)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC44)))) + 0xC4)), 0.0f, 0, 2, 0);
            func_002e0940((*(void * *)(work + 0xC48)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC48)))) + 0xC4)), 0.0f, 0, 2, 0);
            for (var_18 = 0; var_18 < 2; var_18++) {
                (*(u8 *)(work + ((var_18) * 4) + 0xF3E)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x79));
                (*(u8 *)(work + ((var_18) * 4) + 0xF3F)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x7A));
                (*(u8 *)(work + ((var_18) * 4) + 0xF40)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x7B));
            }
            (*(s16 *)(work + 0xF3C)) = 0;
            (*(s8 *)(work + 0)) = 0x12;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            for (var_16_8 = 0; var_16_8 < 7; var_16_8++) {
                func_002e0660((*(void * *)((u8 *)((work + (var_16_8 * 4))) + 0xD20)), 0xFFU, 0U, 0U, 5, (s16) ((var_16_8 * 2)));
            }
            func_002e0660((*(void * *)(work + 0xC44)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            func_002e0660((*(void * *)(work + 0xC48)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            func_002e09e0((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_30 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 5);
            temp_18_16 = (s16) (((func_0046b260(temp_2_30) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) temp_18_16;
            temp_18_17 = (s16) (((func_0046b2f0(temp_2_30) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) temp_18_17;
            func_0046d280(temp_2_30);
            temp_16_18 = func_002e04e0((*(void * *)(work + 0xC4C)));
            func_002e0940((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)temp_16_18 + 0xC4)), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0xC4)), 0, 0xA, 0);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x2C)) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x30)) = 164.0f;
            func_002e09e0((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x30)) = 130.0f;
            temp_2_31 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_18_18 = (s16) (((func_0046b260(temp_2_31) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) temp_18_18;
            temp_18_19 = (s16) (((func_0046b2f0(temp_2_31) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x102)) = (s16) temp_18_19;
            temp_18_20 = func_002e04e0((*(void * *)(work + 0xC50)));
            func_002e0940((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)temp_18_20 + 0xC4)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            func_0046d280(temp_2_31);
            func_002e09e0((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 187.0f;
            temp_2_32 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_18_21 = (s16) (((func_0046b260(temp_2_32) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) temp_18_21;
            temp_18_22 = (s16) (((func_0046b2f0(temp_2_32) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = (s16) temp_18_22;
            func_0046d280(temp_2_32);
            temp_16_19 = func_002e04e0((void *) (*(s32 *)(work + 0xE7C)));
            func_002e0940((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)temp_16_19 + 0xC4)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            for (var_16_9 = 0; var_16_9 < 3; var_16_9++) {
                func_002e0660((*(void * *)((u8 *)((work + (var_16_9 * 4))) + 0xC38)), 0xFFU, 0U, 0U, 0xA, 0);
            }
            (*(s8 *)(work + 7)) = 5;
            (*(s8 *)(work + 0)) = 0x13;
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 0x11:                                      /* switch 1 */
        for (var_16_10 = 0x55; var_16_10 < 0x58; var_16_10++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_10 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_10 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_11 = 0x59; var_16_11 < 0x60; var_16_11++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_11 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_11 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (func_002e0570((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD94)), 1))) == 0)) {
            (*(s8 *)(work + 0)) = 0x10;
        }
        break;
    case 0x12:                                      /* switch 1 */
        while (((s16) (var_19)) < 2) {
            temp_16_20 = func_002e04e0((*(void * *)(work + (((s16) (var_19)) * 4) + 0xC44)));
            temp_2_35 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3E));
            var_f12 = (f32) temp_2_35;
            temp_f0 = func_002b2aa0(1, var_f12, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3 = (u8) temp_f0;
            (*(s8 *)((u8 *)temp_16_20 + 0x79)) = var_3;
            temp_2_36 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3F));
            var_f12_2 = (f32) temp_2_36;
            temp_f0_2 = func_002b2aa0(1, var_f12_2, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_2 = (u8) temp_f0_2;
            (*(s8 *)((u8 *)temp_16_20 + 0x7A)) = var_3_2;
            temp_2_37 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF40));
            var_f12_3 = (f32) temp_2_37;
            temp_f0_3 = func_002b2aa0(1, var_f12_3, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_3 = (u8) temp_f0_3;
            (*(s8 *)((u8 *)temp_16_20 + 0x7B)) = var_3_3;
            var_19 = (s16) ((var_19 + 1));
        }
        temp_4_3 = (*(s16 *)(work + 0xF3C));
        if (temp_4_3 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_3, 1, 6, 0, 1);
        } else {
            for (var_16_12 = 0; var_16_12 < 2; var_16_12++) {
                temp_2_38 = func_002e04e0((*(void * *)(work + ((var_16_12) * 4) + 0xC44)));
                *(FclDrawColor *)((u8 *)temp_2_38 + 0x79) = *(FclDrawColor *)(work + ((var_16_12) * 4) + 0xF3E);
            }
            for (var_16_13 = 0; var_16_13 < 7; var_16_13++) {
                func_002e0660((*(void * *)((u8 *)((work + (var_16_13 * 4))) + 0xD20)), 0xFFU, 0U, 0U, 5, (s16) ((var_16_13 * 2)));
            }
            func_002e0660((*(void * *)(work + 0xC44)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            func_002e0660((*(void * *)(work + 0xC48)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            func_002e09e0((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_39 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 5);
            temp_18_25 = (s16) (((func_0046b260(temp_2_39) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) temp_18_25;
            temp_18_26 = (s16) (((func_0046b2f0(temp_2_39) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) temp_18_26;
            func_0046d280(temp_2_39);
            temp_16_21 = func_002e04e0((*(void * *)(work + 0xC4C)));
            func_002e0940((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)temp_16_21 + 0xC4)), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0xC4)), 0, 0xA, 0);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x2C)) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x30)) = 164.0f;
            func_002e09e0((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x30)) = 130.0f;
            temp_2_40 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_18_27 = (s16) (((func_0046b260(temp_2_40) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) temp_18_27;
            temp_18_28 = (s16) (((func_0046b2f0(temp_2_40) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x102)) = (s16) temp_18_28;
            temp_18_29 = func_002e04e0((*(void * *)(work + 0xC50)));
            func_002e0940((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)temp_18_29 + 0xC4)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            func_0046d280(temp_2_40);
            func_002e09e0((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 187.0f;
            temp_2_41 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_18_30 = (s16) (((func_0046b260(temp_2_41) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) temp_18_30;
            temp_18_31 = (s16) (((func_0046b2f0(temp_2_41) / 2.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = (s16) temp_18_31;
            func_0046d280(temp_2_41);
            temp_16_22 = func_002e04e0((void *) (*(s32 *)(work + 0xE7C)));
            func_002e0940((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)temp_16_22 + 0xC4)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            if ((*(s8 *)(work + 7)) != 5) {
                pos = func_002e04e0((*(void * *)(work + 0xD90)));
                sp5C8 = func_002b2970(-262.0f, -56.0f);
                func_002e0620((*(void * *)(work + 0xD90)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5C8, 0, 0xA, 0);
                pos = func_002e04e0((*(void * *)(work + 0xD94)));
                sp5C0 = func_002b2970(-9.0f, -56.0f);
                func_002e0620((*(void * *)(work + 0xD94)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5C0, 0, 0xA, 0);
                pos = func_002e04e0((*(void * *)(work + 0xD8C)));
                sp5B8 = func_002b2970(312.0f, -141.0f);
                func_002e0620((*(void * *)(work + 0xD8C)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5B8, 0, 0xA, 0);
                func_002e0940((*(void * *)(work + 0xD8C)), 0.0f, 360.0f, 0, 0x708, 0);
                func_002e04f0((*(void * *)(work + 0xD8C)), 6, 0);
            }
            for (var_16_14 = 0; var_16_14 < 3; var_16_14++) {
                func_002e0660((*(void * *)((u8 *)((work + (var_16_14 * 4))) + 0xC38)), 0xFFU, 0U, 0U, 0xA, 0);
            }
            (*(s8 *)(work + 0)) = 0x13;
        }
        break;
    case 0x13:                                      /* switch 1 */
        for (var_16_15 = 0x55; var_16_15 < 0x58; var_16_15++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_15 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_15 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_16 = 0x59; var_16_16 < 0x60; var_16_16++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_16 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_16 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (func_002e05a0((*(void * *)(work + 0xC4C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC50))))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD94)), 1))) == 0) && (((s8) (func_002e05a0((void *) (*(s32 *)(work + 0xE7C))))) == 0)) {
            func_002e0940((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0xC4)), 0.0f, 0, 7, 6);
            pos = func_002e04e0((*(void * *)(work + 0xC4C)));
            sp5B0 = func_002b2970(-400.0f, 450.0f);
            func_002e0620((*(void * *)(work + 0xC4C)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5B0, 0, 7, 6);
            func_002e0660((*(void * *)(work + 0xC4C)), 0xFFU, 0U, 0U, 7, 6);
            temp_16_23 = func_002e04e0((*(void * *)(work + 0xC50)));
            func_002e0940((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)temp_16_23 + 0xC4)), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0xC4)), 0, 7, 5);
            pos = func_002e04e0((*(void * *)(work + 0xC50)));
            sp5A8 = func_002b2970(700.0f, (f32) 0x2EE);
            func_002e0620((*(void * *)(work + 0xC50)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5A8, 0, 7, 5);
            func_002e0660((*(void * *)(work + 0xC50)), 0xFFU, 0U, 0U, 7, 5);
            pos = func_002e04e0((void *) (*(s32 *)(work + 0xE7C)));
            sp5A0 = func_002b2970(700.0f, (f32) 0x2EE);
            func_002e0620((void *) (*(s32 *)(work + 0xE7C)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp5A0, 0, 7, 3);
            temp_16_24 = func_002e04e0((void *) (*(s32 *)(work + 0xE7C)));
            func_002e0940((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)temp_16_24 + 0xC4)), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)), 0, 7, 3);
            func_002e0660((void *) (*(s32 *)(work + 0xE7C)), 0xFFU, 0U, 0U, 7, 3);
            temp_2_44 = (*(s8 *)(work + 7));
            switch (temp_2_44) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                func_002da0a0(arg0);
                break;
            case 3:                                 /* switch 2 */
                func_002db400(arg0);
                (*(s32 *)(work + 0xC20)) = 0;
                for (var_16_17 = 1; var_16_17 < func_002e26f0((*(void * *)(work + 0xF18))); var_16_17++) {
                    temp_18_32 = (s16) (func_002e2830((*(void * *)(work + 0xF18)), (s32) var_16_17));
                    func_002e28f0((*(void * *)(work + 0xF18)), (s32) var_16_17);
                    temp_20 = (s16) (temp_18_32);
                    temp_19_3 = func_00110830(temp_20) & 0xFF;
                    func_002b2cb0(temp_19_3, func_00106600(temp_18_32) & 0xFF, 0xFF, 0, 1);
                    temp_19_4 = func_00106a90((s16) ((s16) (temp_20))) / 5U;
                    temp_4_5 = (*(s32 *)(work + 0xC20)) + (temp_19_4 * (func_00106600(temp_18_32) & 0xFF));
                    (*(s32 *)(work + 0xC20)) = temp_4_5;
                    (*(s32 *)(work + 0xC20)) = func_002b2cb0(temp_4_5, 0, 0x98967F, 0, 1);
                }
                break;
            case 4:                                 /* switch 2 */
                func_002e04f0((*(void * *)(work + 0xDE8)), 0, 1);
                func_002e04f0((*(void * *)(work + 0xDEC)), 0, 1);
                func_002e0660((*(void * *)(work + 0xD8C)), 0xFFU, 0U, 0U, 0xA, 0);
                func_002e0660((*(void * *)(work + 0xD90)), 0xFFU, 0U, 0U, 0xA, 0);
                func_002e0660((*(void * *)(work + 0xD94)), 0xFFU, 0U, 0U, 0xA, 0);
                func_00331fc0(arg0);
                (*(s8 *)(work + 0)) = 0x35;
                break;
            case 5:                                 /* switch 2 */
                func_002e04f0((*(void * *)(work + 0xDE8)), 0, 1);
                func_002e04f0((*(void * *)(work + 0xDEC)), 0, 1);
                func_002e0660((*(void * *)(work + 0xD8C)), 0xFFU, 0U, 0U, 0xA, 0);
                func_002e0660((*(void * *)(work + 0xD90)), 0xFFU, 0U, 0U, 0xA, 0);
                func_002e0660((*(void * *)(work + 0xD94)), 0xFFU, 0U, 0U, 0xA, 0);
                (*(s8 *)(work + 0)) = 0x37;
                break;
            }
        }
        break;
    case 0x14:                                      /* switch 1 */
        if (((s8) (func_002e05a0((void *) (*(s32 *)(work + 0xED4))))) == 0) {
            temp_16_25 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
            sp598 = func_002b2970((*(f32 *)((u8 *)temp_16_25 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f);
            temp_16_26 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
            sp590 = func_002b2970((*(f32 *)((u8 *)temp_16_26 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)));
            func_002e0620((void *) (*(s32 *)(work + 0xED4)), *(u64 *)&sp598, *(u64 *)&sp590, 1, 4, 0);
            temp_16_27 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
            sp588 = func_002b2970((*(f32 *)((u8 *)temp_16_27 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f);
            temp_16_28 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
            sp580 = func_002b2970((*(f32 *)((u8 *)temp_16_28 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)));
            func_002e0620((void *) (*(s32 *)(work + 0xED8)), *(u64 *)&sp588, *(u64 *)&sp580, 1, 4, 0);
            (*(s8 *)(work + 0)) = 0x15;
        }
        /* fallthrough */
    case 0x15:                                      /* switch 1 */
        if (((s8) (func_002e05a0((*(void * *)(work + 0xD60))))) == 0) {
            func_002de5a0(arg0);
        }
        if (((s8) (func_002e05a0((*(void * *)(work + 0xC58))))) == 0) {
            if (((s8) (func_002e05a0((*(void * *)(work + 0xC4C))))) != 0) {
                var_19 = 1;
            }
            if (((s8) (func_002e05a0((*(void * *)(work + 0xC50))))) != 0) {
                var_19 = 1;
            }
            if (((s8) (func_002e05a0((void *) (*(s32 *)(work + 0xE7C))))) != 0) {
                var_19 = 1;
            }
            if ((*(s8 *)(work + 0)) == 0x14) {
                var_19 = 1;
            }
            for (var_18_2 = 0; var_18_2 < ((*(s8 *)(work + 9))); var_18_2++) {
                if ((*(s16 *)(work + var_18_2 * 2 + 0xF46)) != 0) {
                    (*(s16 *)(work + var_18_2 * 2 + 0xF46)) = func_002b2d00((*(s16 *)(work + var_18_2 * 2 + 0xF46)), 1, 0, 0, 1);
                    var_19 = 1;
                } else {
                    temp_16_29 = var_18_2;
                    temp_f0_4 = func_002b2aa0(0, 0.0f, 255.0f, (f32) (*(s16 *)(work + (temp_16_29 * 2) + 0xF58)), 6.0f);
                    var_3_4 = (u8) temp_f0_4;
                    (*(u8 *)(work + temp_16_29 + 0xF6A)) = var_3_4;
                    (*(s16 *)(work + (temp_16_29 * 2) + 0xF58)) = func_002b2cb0((s32) (*(s16 *)(work + (temp_16_29 * 2) + 0xF58)), 1, 6, 0, 1);
                    var_22 = func_002b2a30(0xECU, 0x7FU, 0U, (*(u8 *)(work + temp_16_29 + 0xF6A)));
                    if ((*(s8 *)(work + 8)) == temp_16_29) {
                        var_22 = func_002b2a30(0x2DU, 0x2DU, 0x2DU, (*(u8 *)(work + temp_16_29 + 0xF6A)));
                    }
                    sp578 = func_002b2970(71.0f,  86.0f + 35.0f * (f32) var_18_2);
                    func_002e0080(arg0, (*(s8 *)(work + temp_16_29 + 0xF73)), sp578, (void *) var_22);
                }
            }
            if (((s16) (var_19)) == 0) {
                if (D_008C027A[0] & 0x4000) {
                    (*(s8 *)(work + 8)) = func_002b2cb0((s32) (*(s8 *)(work + 8)), 1, (*(s8 *)(work + 9)) - 1, 0, 2);
                    func_002d83c0(arg0);
                    temp_f20_14 =  78.0f + 35.0f * (f32) (*(s8 *)(work + 8));
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) = temp_f20_14;
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) = temp_f20_14;
                    temp_16_30 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
                    sp570 = func_002b2970((*(f32 *)((u8 *)temp_16_30 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f);
                    temp_16_31 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
                    sp568 = func_002b2970((*(f32 *)((u8 *)temp_16_31 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)));
                    func_002e0620((void *) (*(s32 *)(work + 0xED4)), *(u64 *)&sp570, *(u64 *)&sp568, 1, 2, 0);
                    temp_16_32 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
                    sp560 = func_002b2970((*(f32 *)((u8 *)temp_16_32 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f);
                    temp_16_33 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
                    sp558 = func_002b2970((*(f32 *)((u8 *)temp_16_33 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)));
                    func_002e0620((void *) (*(s32 *)(work + 0xED8)), *(u64 *)&sp560, *(u64 *)&sp558, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C027A[0] & 0x1000) {
                    (*(s8 *)(work + 8)) = func_002b2d00((s32) (*(s8 *)(work + 8)), 1, 0, (*(s8 *)(work + 9)) - 1, 2);
                    func_002d83c0(arg0);
                    temp_f20_15 =  78.0f + 35.0f * (f32) (*(s8 *)(work + 8));
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) = temp_f20_15;
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) = temp_f20_15;
                    temp_16_34 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
                    sp550 = func_002b2970((*(f32 *)((u8 *)temp_16_34 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f);
                    temp_16_35 = func_002e04e0((void *) (*(s32 *)(work + 0xED4)));
                    sp548 = func_002b2970((*(f32 *)((u8 *)temp_16_35 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0x30)));
                    func_002e0620((void *) (*(s32 *)(work + 0xED4)), *(u64 *)&sp550, *(u64 *)&sp548, 1, 2, 0);
                    temp_16_36 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
                    sp540 = func_002b2970((*(f32 *)((u8 *)temp_16_36 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f);
                    temp_16_37 = func_002e04e0((void *) (*(s32 *)(work + 0xED8)));
                    sp538 = func_002b2970((*(f32 *)((u8 *)temp_16_37 + 0x2C)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0x30)));
                    func_002e0620((void *) (*(s32 *)(work + 0xED8)), *(u64 *)&sp540, *(u64 *)&sp538, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C024E[0] & 0x20) {
                    func_0045af60(0, 0, 0, 2);
                    tbl = (f32 *) D_0063F5A0;
                    sp530 = func_002b2970(tbl[0], tbl[1]);
                    sp528 = func_002b2970(tbl[0], 500.0f + tbl[1]);
                    func_002e0620((*(void * *)(work + 0xC58)), *(u64 *)&sp530, *(u64 *)&sp528, 0, 4, 0);
                    func_002e0660((*(void * *)(work + 0xC58)), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F5A8;
                    sp520 = func_002b2970(tbl[0], tbl[1]);
                    sp518 = func_002b2970(tbl[0], 500.0f + tbl[1]);
                    func_002e0620((*(void * *)(work + 0xC5C)), *(u64 *)&sp520, *(u64 *)&sp518, 0, 4, 0);
                    func_002e0660((*(void * *)(work + 0xC5C)), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F7B0;
                    sp510 = func_002b2970(tbl[0], tbl[1]);
                    sp508 = func_002b2970(tbl[0], 400.0f + tbl[1]);
                    func_002e0620((*(void * *)(work + 0xD60)), *(u64 *)&sp510, *(u64 *)&sp508, 2, 4, 0);
                    tbl = (f32 *) D_0063F7B8;
                    sp500 = func_002b2970(tbl[0], tbl[1]);
                    sp4F8 = func_002b2970(tbl[0], 400.0f + tbl[1]);
                    func_002e0620((*(void * *)(work + 0xD64)), *(u64 *)&sp500, *(u64 *)&sp4F8, 2, 4, 0);
                    func_002e04f0((*(void * *)(work + 0xDE8)), 0, 1);
                    func_002e04f0((*(void * *)(work + 0xDF0)), 0, 1);
                    func_002e04f0((*(void * *)(work + 0xD3C)), 0, 1);
                    for (var_19_2 = 0; var_19_2 < 6; var_19_2++) {
                        temp_16_38 = (f32 *)(D_0063F560 + ((var_19_2 + 0x43) * 8));
                        sp4F0 = func_002b2970(temp_16_38[0], temp_16_38[1]);
                        sp4E8 = func_002b2970(temp_16_38[0], 700.0f);
                        func_002e0620((*(void * *)((u8 *)((work + (var_19_2 * 4))) + 0xD44)), *(u64 *)&sp4F0, *(u64 *)&sp4E8, 2, 5, 0);
                    }
                    func_002e04f0((void *) (*(s32 *)(work + 0xED4)), 0, 1);
                    func_002e04f0((void *) (*(s32 *)(work + 0xED8)), 0, 1);
                    func_002dd230(arg0);
                    for (var_16_18 = 0; var_16_18 < 7; var_16_18++) {
                        func_002e04f0((*(void * *)((u8 *)((work + (var_16_18 * 4))) + 0xD20)), 0, 0);
                    }
                    func_002e04f0((*(void * *)(work + 0xC44)), 0, 0);
                    func_002e04f0((*(void * *)(work + 0xC48)), 0, 0);
                    func_002e09e0((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
                    func_002e0660((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x2C)) = 198.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x30)) = (f32) 0x151;
                    func_002e09e0((*(void * *)(work + 0xDEC)), 0x41, 146.0f);
                    func_002e0660((*(void * *)(work + 0xDEC)), 0U, 0xFFU, 0U, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDEC)))) + 0x2C)) = 216.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDEC)))) + 0x30)) = 368.0f;
                    func_002e09e0((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
                    temp_2_46 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 5);
                    temp_18_34 = (s16) ((func_0046b260(temp_2_46)));
                    (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) temp_18_34;
                    temp_18_35 = (s16) ((func_0046b2f0(temp_2_46)));
                    (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) temp_18_35;
                    func_0046d280(temp_2_46);
                    func_002e0660((*(void * *)(work + 0xC4C)), 0U, 0xCCU, 0U, 4, 4);
                    func_002e0940((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
                    sp4E0 = func_002b2970(-240.0f, 400.0f);
                    sp4D8 = func_002b2970(-240.0f, 310.0f);
                    func_002e0620((*(void * *)(work + 0xC4C)), *(u64 *)&sp4E0, *(u64 *)&sp4D8, 0, 4, 4);
                    func_002e09e0((*(void * *)(work + 0xC50)), 0x40, 192.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
                    temp_2_47 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
                    temp_18_36 = (s16) ((func_0046b260(temp_2_47)));
                    (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) temp_18_36;
                    (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
                    func_002e0940((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 4);
                    func_002e0660((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 4);
                    func_0046d280(temp_2_47);
                    func_002e09e0((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
                    temp_2_48 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
                    temp_16_39 = (s16) ((func_0046b260(temp_2_48)));
                    (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) temp_16_39;
                    (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
                    func_0046d280(temp_2_48);
                    func_002e0940((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
                    func_002e0660((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
                    for (var_21 = 0; var_21 < 7; var_21++) {
                        temp_18_37 = (f32 *)(D_0063F560 + ((var_21 + 0x3A) * 8));
                        func_002e09e0((*(void * *)(work + (var_21 * 4) + 0xD20)), 0x56, (f32) (var_21 + 0x64));
                        if (var_21 > 0) {
                            sp744 = func_002b2a60(0xED, 0x80, 0, 0xFF);
                            temp_2_49 = func_002e04e0((*(void * *)(work + (var_21 * 4) + 0xD20)));
                            *(FclDrawColor *)((u8 *)temp_2_49 + 0x79) = sp744;
                        }
                        sp4D0 = func_002b2970(80.0f + temp_18_37[0], temp_18_37[1]);
                        sp4C8 = func_002b2970(temp_18_37[0], temp_18_37[1]);
                        func_002e0620((*(void * *)(work + ((var_21) * 4) + 0xD20)), *(u64 *)&sp4D0, *(u64 *)&sp4C8, 0, 3, var_21);
                        func_002e0660((*(void * *)(work + ((var_21) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_21);
                    }
                    sp740 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    temp_2_51 = func_002e04e0((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))]));
                    *(FclDrawColor *)((u8 *)temp_2_51 + 0x79) = sp740;
                    func_002e0660((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
                    func_002e0660((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
                    for (var_16_19 = 0; var_16_19 < 3; var_16_19++) {
                        func_002e0660((*(void * *)((u8 *)((work + (var_16_19 * 4))) + 0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
                    }
                    func_002d7f90(arg0);
                    (*(s8 *)(work + 0)) = 0x11;
                } else if (D_008C024E[0] & 0x40) {
                    func_002e0940((void *) (*(s32 *)(work + 0xED4)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED4)))) + 0xC4)), 0.0f, 0, 2, 0);
                    func_002e0940((void *) (*(s32 *)(work + 0xED8)), (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xED8)))) + 0xC4)), 0.0f, 0, 2, 0);
                    for (var_18_3 = 0; var_18_3 < 2; var_18_3++) {
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF3E)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x79));
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF3F)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x7A));
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF40)) = (u8) (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x7B));
                    }
                    (*(s16 *)(work + 0xF3C)) = 0;
                    (*(s8 *)(work + 0)) = 0x16;
                    func_0045af60(0, 0, 0, 1);
                }
            }
        }
        break;
    case 0x16:                                      /* switch 1 */
        func_002de5a0(arg0);
        while (((s16) (var_19)) < (*(s8 *)(work + 9))) {
            if ((*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)) != 0) {
                (*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)) = func_002b2d00((*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)), 1, 0, 0, 1);
            } else {
                temp_18_38 = (s16) (var_19);
                temp_f0_5 = func_002b2aa0(0, 0.0f, 255.0f, (f32) (*(s16 *)(work + (temp_18_38 * 2) + 0xF58)), 6.0f);
                var_3_5 = (u8) temp_f0_5;
                (*(u8 *)(work + temp_18_38 + 0xF6A)) = var_3_5;
                (*(s16 *)(work + (temp_18_38 * 2) + 0xF58)) = func_002b2cb0((s32) (*(s16 *)(work + (temp_18_38 * 2) + 0xF58)), 1, 6, 0, 1);
                var_21_2 = func_002b2a30(0xECU, 0x7FU, 0U, (*(u8 *)(work + temp_18_38 + 0xF6A)));
                if ((*(s8 *)(work + 8)) == temp_18_38) {
                    var_21_2 = func_002b2a30(0x2DU, 0x2DU, 0x2DU, (*(u8 *)(work + temp_18_38 + 0xF6A)));
                }
                sp4C0 = func_002b2970(71.0f,  86.0f + 35.0f * (f32) var_19);
                func_002e0080(arg0, (*(s8 *)(work + temp_18_38 + 0xF73)), sp4C0, (void *) var_21_2);
            }
            var_19 = (s16) ((var_19 + 1));
        }
        for (var_19_3 = 0; var_19_3 < 2; var_19_3++) {
            temp_16_41 = func_002e04e0((*(void * *)(work + ((var_19_3) * 4) + 0xED4)));
            temp_2_53 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF3E));
            var_f12_4 = (f32) temp_2_53;
            temp_f0_6 = func_002b2aa0(1, var_f12_4, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_6 = (u8) temp_f0_6;
            (*(s8 *)((u8 *)temp_16_41 + 0x79)) = var_3_6;
            temp_2_54 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF3F));
            var_f12_5 = (f32) temp_2_54;
            temp_f0_7 = func_002b2aa0(1, var_f12_5, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_7 = (u8) temp_f0_7;
            (*(s8 *)((u8 *)temp_16_41 + 0x7A)) = var_3_7;
            temp_2_55 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF40));
            var_f12_6 = (f32) temp_2_55;
            temp_f0_8 = func_002b2aa0(1, var_f12_6, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_8 = (u8) temp_f0_8;
            (*(s8 *)((u8 *)temp_16_41 + 0x7B)) = var_3_8;
        }
        temp_4_8 = (*(s16 *)(work + 0xF3C));
        if (temp_4_8 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_8, 1, 6, 0, 1);
        } else {
            for (var_18_4 = 0; var_18_4 < 2; var_18_4++) {
                temp_2_56 = func_002e04e0((*(void * *)(work + ((var_18_4) * 4) + 0xED4)));
                *(FclDrawColor *)((u8 *)temp_2_56 + 0x79) = *(FclDrawColor *)(work + ((var_18_4) * 4) + 0xF3E);
            }
            tbl = (f32 *) D_0063F7C8;
            func_002e09e0((*(void * *)(work + 0xD6C)), 0x41, 38.0f);
            func_002e0940((*(void * *)(work + 0xD6C)), -105.0f, 27.0f, 0, 5, 0);
            sp73C = func_002b2a60(0x97, 0xF, 0, 0xFF);
            temp_2_57 = func_002e04e0((*(void * *)(work + 0xD6C)));
            *(FclDrawColor *)((u8 *)temp_2_57 + 0x79) = sp73C;
            temp_18_40 = (s16) (((173.0f - tbl[0])));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD6C)))) + 0x100)) = (s16) temp_18_40;
            temp_16_43 = (s16) ((((f32) 0x223 - tbl[1])));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD6C)))) + 0x102)) = (s16) temp_16_43;
            tbl = (f32 *) D_0063F780;
            sp4B8 = func_002b2970(tbl[0], tbl[1]);
            sp4B0 = func_002b2970(-130.0f, tbl[1] - 50.0f);
            func_002e0620((*(void * *)(work + 0xD48)), *(u64 *)&sp4B8, *(u64 *)&sp4B0, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD48)), 0.0f, -20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F778;
            sp4A8 = func_002b2970(tbl[0], tbl[1]);
            sp4A0 = func_002b2970(tbl[0] - 200.0f, -130.0f);
            func_002e0620((*(void * *)(work + 0xD44)), *(u64 *)&sp4A8, *(u64 *)&sp4A0, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD44)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F788;
            sp498 = func_002b2970(tbl[0], tbl[1]);
            sp490 = func_002b2970(tbl[0] - 40.0f, (f32) 0x226);
            func_002e0620((*(void * *)(work + 0xD4C)), *(u64 *)&sp498, *(u64 *)&sp490, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD4C)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F798;
            sp488 = func_002b2970(tbl[0], tbl[1]);
            sp480 = func_002b2970(40.0f + tbl[0], (f32) 0x226);
            func_002e0620((*(void * *)(work + 0xD54)), *(u64 *)&sp488, *(u64 *)&sp480, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD54)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F790;
            sp478 = func_002b2970(tbl[0], tbl[1]);
            sp470 = func_002b2970(40.0f + tbl[0], -150.0f);
            func_002e0620((*(void * *)(work + 0xD50)), *(u64 *)&sp478, *(u64 *)&sp470, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD50)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7A0;
            sp468 = func_002b2970(tbl[0], tbl[1]);
            sp460 = func_002b2970(40.0f + tbl[0], -200.0f);
            func_002e0620((*(void * *)(work + 0xD58)), *(u64 *)&sp468, *(u64 *)&sp460, 0, 7, 3);
            func_002e0940((*(void * *)(work + 0xD58)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7B0;
            sp458 = func_002b2970(tbl[0], tbl[1]);
            sp450 = func_002b2970((f32) 0x29E + tbl[0], tbl[1] - 300.0f);
            func_002e0620((*(void * *)(work + 0xD60)), *(u64 *)&sp458, *(u64 *)&sp450, 1, 0xA, 3);
            func_002e0940((*(void * *)(work + 0xD60)), fGpffff852C, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F7B8;
            sp448 = func_002b2970(tbl[0], tbl[1]);
            sp440 = func_002b2970((f32) 0x29E + tbl[0], tbl[1] - 300.0f);
            func_002e0620((*(void * *)(work + 0xD64)), *(u64 *)&sp448, *(u64 *)&sp440, 1, 4, 3);
            func_002e0940((*(void * *)(work + 0xD64)), fGpffff852C, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F5A0;
            sp438 = func_002b2970(tbl[0], tbl[1]);
            sp430 = func_002b2970(tbl[0], 500.0f + tbl[1]);
            func_002e0620((*(void * *)(work + 0xC58)), *(u64 *)&sp438, *(u64 *)&sp430, 0, 4, 0);
            func_002e0660((*(void * *)(work + 0xC58)), 0xCCU, 0U, 0U, 2, 0);
            tbl = (f32 *) D_0063F5A8;
            sp428 = func_002b2970(tbl[0], tbl[1]);
            sp420 = func_002b2970(tbl[0], 500.0f + tbl[1]);
            func_002e0620((*(void * *)(work + 0xC5C)), *(u64 *)&sp428, *(u64 *)&sp420, 0, 4, 0);
            func_002e0660((*(void * *)(work + 0xC5C)), 0xCCU, 0U, 0U, 2, 0);
            func_002e04f0((*(void * *)(work + 0xD3C)), 0, 1);
            func_002e04f0((void *) (*(s32 *)(work + 0xED4)), 0, 1);
            func_002e04f0((void *) (*(s32 *)(work + 0xED8)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xDE8)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xDF0)), 0, 1);
            (*(s8 *)(work + 0)) = 0x17;
        }
        break;
    case 0x17:                                      /* switch 1 */
        if (((s8) (func_002e0570((*(void * *)(work + 0xD6C)), 3))) == 0) {
            func_002e0940((*(void * *)(work + 0xD6C)), 27.0f, -14.0f, 0, 3, 0);
            tbl = (f32 *) D_0063F5B8;
            func_002e09e0((*(void * *)(work + 0xC64)), 0x41, 157.0f);
            sp418 = func_002b2970(tbl[0], -300.0f + tbl[1]);
            sp410 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC64)), *(u64 *)&sp418, *(u64 *)&sp410, 0, 7, 0);
            func_002e0660((*(void * *)(work + 0xC64)), 0U, 0xCCU, 0U, 7, 0);
            sp738 = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_58 = func_002e04e0((*(void * *)(work + 0xC64)));
            *(FclDrawColor *)((u8 *)temp_2_58 + 0x79) = sp738;
            func_002e0940((*(void * *)(work + 0xC64)), 0.0f, -4.0f, 0, 0, 0);
            temp_18_41 = (s16) (((320.0f - tbl[0])));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC64)))) + 0x100)) = (s16) temp_18_41;
            temp_16_44 = (s16) (((tbl[1] - 83.0f)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC64)))) + 0x102)) = (s16) temp_16_44;
            func_002e06d0((*(void * *)(work + 0xC64)), 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
            (*(s8 *)(work + 0)) = 0x18;
        }
        break;
    case 0x18:                                      /* switch 1 */
        if (((s8) (func_002e05a0((*(void * *)(work + 0xC64))))) == 0) {
            func_002e09e0((*(void * *)(work + 0xE2C)), 0x41, 152.0f);
            func_002e0660((*(void * *)(work + 0xE2C)), 0U, 0xCCU, 0U, 5, 0);
            sp734 = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_59 = func_002e04e0((*(void * *)(work + 0xE2C)));
            *(FclDrawColor *)((u8 *)temp_2_59 + 0x79) = sp734;
            func_002e09e0((*(void * *)(work + 0xE30)), 0x41, 152.0f);
            func_002e0660((*(void * *)(work + 0xE30)), 0U, 0xCCU, 0U, 5, 0);
            sp730 = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_60 = func_002e04e0((*(void * *)(work + 0xE30)));
            *(FclDrawColor *)((u8 *)temp_2_60 + 0x79) = sp730;
            func_002e09e0((*(void * *)(work + 0xD70)), 0x41, 7.0f);
            func_002e0660((*(void * *)(work + 0xD70)), 0U, 0xFFU, 0U, 0xA, 0);
            sp408 = func_002b2970(46.0f, 294.0f);
            temp_2_61 = func_002e04e0((*(void * *)(work + 0xD70)));
            *(Vec2f *)((u8 *)temp_2_61 + 0x2C) = sp408;
            func_002e09e0((*(void * *)(work + 0xD7C)), 0x41, 8.0f);
            func_002e0660((*(void * *)(work + 0xD7C)), 0U, 0xFFU, 0U, 0xA, 0);
            func_002e09e0((*(void * *)(work + 0xDD8)), 0x41, 45.0f);
            func_002e0660((*(void * *)(work + 0xDD8)), 0U, 0xFFU, 0U, 6, 0);
            func_002e09e0((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
            func_002e0660((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x2C)) = (f32) 0x17F;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE8)))) + 0x30)) = 404.0f;
            func_002e09e0((*(void * *)(work + 0xDF0)), 0x41, 47.0f);
            func_002e0660((*(void * *)(work + 0xDF0)), 0U, 0xFFU, 0U, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDF0)))) + 0x2C)) = 446.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDF0)))) + 0x30)) = 404.0f;
            func_002e09e0((*(void * *)(work + 0xDE4)), 0x41, 47.0f);
            func_002e0660((*(void * *)(work + 0xDE4)), 0U, 0xFFU, 0U, 6, 0);
            func_002e09e0((*(void * *)(work + 0xDE0)), 0x41, 47.0f);
            temp_16_45 = func_002e04e0((*(void * *)(work + 0xDE4)));
            temp_2_62 = func_002e04e0((*(void * *)(work + 0xDE0)));
            *(Vec2f *)((u8 *)temp_2_62 + 0x2C) = *(Vec2f *)((u8 *)temp_16_45 + 0x2C);
            (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDE0)))) + 0x62)) = 0xFF;
            func_002e04f0((*(void * *)(work + 0xDE0)), 0, 1);
            func_002e09e0((*(void * *)(work + 0xC8C)), 0x41, 139.0f);
            func_002e0660((*(void * *)(work + 0xC8C)), 0U, 0xFFU, 0U, 6, 0);
            sp72C = func_002b2a60(0xCE, 0x71, 2, 0xFF);
            temp_2_63 = func_002e04e0((*(void * *)(work + 0xC8C)));
            *(FclDrawColor *)((u8 *)temp_2_63 + 0x79) = sp72C;
            func_002e09e0((*(void * *)(work + 0xC90)), 0x41, 140.0f);
            func_002e0660((*(void * *)(work + 0xC90)), 0U, 0xFFU, 0U, 6, 0);
            sp728 = func_002b2a60(0xCE, 0x71, 2, 0xFF);
            temp_2_64 = func_002e04e0((*(void * *)(work + 0xC90)));
            *(FclDrawColor *)((u8 *)temp_2_64 + 0x79) = sp728;
            (*(s16 *)(work + 4)) = 0;
            (*(s16 *)(work + 2)) = 0;
            temp_2_65 = (*(s8 *)(work + 7));
            switch (temp_2_65) {                    /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                func_002e24a0(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                break;
            case 1:                                 /* switch 3 */
                func_002e24a0(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                break;
            case 2:                                 /* switch 3 */
                func_002e24a0(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                break;
            }
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x1B:                                      /* switch 1 */
        func_002cb6c0(arg0, 0);
        sp400 = func_002b2970((f32) 0x24E, 61.0f);
        sp724 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_17_2 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_46 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp400, 1.0f, sp724, 0x11, 5, temp_17_2, 0x70, 0x7A, (s32) temp_16_46, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        break;
    case 0x1C:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        sp3F8 = func_002b2970((f32) 0x24E, 61.0f);
        sp720 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_42 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_47 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp3F8, 1.0f, sp720, 0x11, 5, temp_18_42, 0x70, 0x7A, (s32) temp_16_47, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        for (var_21_3 = 0; var_21_3 < 2; var_21_3++) {
            temp_19_6 = func_002e04e0((*(void * *)(work + 0xDC8)));
            temp_18_43 = func_002e04e0((*(void * *)(work + 0xDD0)));
            temp_2_66 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF3E));
            var_f12_7 = (f32) temp_2_66;
            temp_f0_9 = func_002b2aa0(1, var_f12_7, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_9 = (u8) temp_f0_9;
            (*(s8 *)((u8 *)temp_18_43 + 0x79)) = var_3_9;
            (*(s8 *)((u8 *)temp_19_6 + 0x79)) = var_3_9;
            temp_2_67 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF3F));
            var_f12_8 = (f32) temp_2_67;
            temp_f0_10 = func_002b2aa0(1, var_f12_8, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_10 = (u8) temp_f0_10;
            (*(s8 *)((u8 *)temp_18_43 + 0x7A)) = var_3_10;
            (*(s8 *)((u8 *)temp_19_6 + 0x7A)) = var_3_10;
            temp_2_68 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF40));
            var_f12_9 = (f32) temp_2_68;
            temp_f0_11 = func_002b2aa0(1, var_f12_9, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_11 = (u8) temp_f0_11;
            (*(s8 *)((u8 *)temp_18_43 + 0x7B)) = var_3_11;
            (*(s8 *)((u8 *)temp_19_6 + 0x7B)) = var_3_11;
        }
        temp_4_9 = (*(s16 *)(work + 0xF3C));
        if (temp_4_9 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_9, 1, 6, 0, 1);
        } else {
            temp_2_69 = func_002e04e0((*(void * *)(work + 0xDC8)));
            *(FclDrawColor *)((u8 *)temp_2_69 + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            temp_2_70 = func_002e04e0((*(void * *)(work + 0xDD0)));
            *(FclDrawColor *)((u8 *)temp_2_70 + 0x79) = *(FclDrawColor *)(work + 0xF42);
            sp6A0.v0 = func_002e2740((*(s16 *)(work + 2)));
            sp6A0.v1 = 0;
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 1, &sp6A0, 1);
            (*(s8 *)(work + 0)) = 0x1D;
            func_002d6190(arg0);
            func_002e04f0((*(void * *)(work + 0xDC8)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xDD0)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 1);
        }
        break;
    case 0x1D:                                      /* switch 1 */
        func_002d5040(arg0);
        sp3F0 = func_002b2970((f32) 0x24E, 61.0f);
        sp71C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_44 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_49 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp3F0, 1.0f, sp71C, 0x11, 5, temp_18_44, 0x70, 0x7A, (s32) temp_16_49, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        sp3E8 = func_002b2970(51.0f, 48.0f);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), sp3E8, (void *) func_002b2a30(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)(work + 0x10)));
            temp_16_50 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
            func_002e7a80(func_002e7a60() - temp_16_50);
            sp698.v0 = func_002e2740((*(s16 *)(work + 2)));
            sp698.v1 = 0;
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 4, &sp698, 1);
            (*(s8 *)(work + 0)) = 0x1E;
        } else {
            func_002d7300(arg0);
            func_002bb550((*(s8 *)(work + 0x10)));
            (*(s8 *)(work + 0)) = 0x1B;
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 0);
        }
        break;
    case 0x1E:                                      /* switch 1 */
        func_002d5040(arg0);
        sp3E0 = func_002b2970(51.0f, 48.0f);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), sp3E0, (void *) func_002b2a30(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        sp3D8 = func_002b2970((f32) 0x24E, 61.0f);
        sp718 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_45 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_51 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp3D8, 1.0f, sp718, 0x11, 5, temp_18_45, 0x70, 0x7A, (s32) temp_16_51, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
                func_0045af60(0, 0, 0, 7);
                func_002bb550((*(s8 *)(work + 0x10)));
                sp690.v0 = (s32) ((s16) (func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))));
                sp690.v1 = 0;
                (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 5, &sp690, 1);
                (*(s8 *)(work + 0)) = 0x1F;
            } else {
                func_002bb550((*(s8 *)(work + 0x10)));
                temp_16_52 = (s16) (func_002e2740((*(s16 *)(work + 2))));
                func_00106620(temp_16_52, ((func_00106600((s16) ((s16) (func_002e2740((*(s16 *)(work + 2)))))) & 0xFF) + 1) & 0xFF);
                (*(s8 *)(work + 0)) = 0x1B;
            }
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 0);
            if (func_002e2670() > 5) {
                func_002e04f0((*(void * *)(work + 0xDC8)), 0, 0);
                func_002e04f0((*(void * *)(work + 0xDD0)), 0, 0);
            }
            func_002d7300(arg0);
        }
        break;
    case 0x1F:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002cb6c0(arg0, 1);
        sp3D0 = func_002b2970((f32) 0x24E, 61.0f);
        sp714 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_46 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_53 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp3D0, 1.0f, sp714, 0x11, 5, temp_18_46, 0x70, 0x7A, (s32) temp_16_53, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
                temp_16_54 = func_00106a90(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))) >> 2;
                func_002e7a80(func_002e7a60() + temp_16_54);
                func_0045af60(0, 0, 0, 6);
            } else {
                temp_16_55 = func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)));
                func_00106620(temp_16_55, ((func_00106600(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))) & 0xFF) + 1) & 0xFF);
            }
            func_00106d40((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)), (s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
            func_002bb550((*(s8 *)(work + 0x10)));
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x20:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        sp3C8 = func_002b2970((f32) 0x24E, 61.0f);
        sp710 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_47 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_56 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp3C8, 1.0f, sp710, 0x11, 5, temp_18_47, 0x70, 0x7A, (s32) temp_16_56, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        if ((((s8) (func_002e0570((*(void * *)(work + 0xDC8)), 9))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xDD0)), 9))) == 0)) {
            func_002e0940((*(void * *)(work + 0xD6C)), -14.0f, 110.0f, 0, 4, 0);
            tbl = (f32 *) D_0063F7D0;
            func_002e0690((*(void * *)(work + 0xD70)), 1.0f, 1.5f, 0, 5, 0);
            func_002e0660((*(void * *)(work + 0xD70)), (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD70)))) + 0x62)), 0U, 0U, 5, 0);
            temp_18_48 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x4E);
            sp3C0 = func_002b2970(tbl[0], tbl[1]);
            sp3B8 = func_002b2970(tbl[0] - 2.5f * (func_0046b260(temp_18_48) / 10.0f), tbl[1] - 2.5f * (func_0046b2f0(temp_18_48) / 10.0f));
            func_002e0620((*(void * *)(work + 0xD70)), *(u64 *)&sp3C0, *(u64 *)&sp3B8, 0, 5, 0);
            func_0046d280(temp_18_48);
            func_002e0660((*(void * *)(work + 0xD7C)), (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xD7C)))) + 0x62)), 0U, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xC8C)), (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC8C)))) + 0x62)), 0U, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xC90)), (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC90)))) + 0x62)), 0U, 0U, 5, 0);
            pos = func_002e04e0((*(void * *)(work + 0xDC8)));
            temp_f20_16 = (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDC8)))) + 0x2C)) - 1000.0f;
            sp3B0 = func_002b2970(temp_f20_16, (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDC8)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xDC8)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp3B0, 2, 3, 0);
            pos = func_002e04e0((*(void * *)(work + 0xDD0)));
            temp_f20_17 = (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDD0)))) + 0x2C)) - 1000.0f;
            sp3A8 = func_002b2970(temp_f20_17, (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xDD0)))) + 0x30)));
            func_002e0620((*(void * *)(work + 0xDD0)), *(u64 *)((u8 *)pos + 0x2C), *(u64 *)&sp3A8, 2, 3, 0);
            func_002e04f0((*(void * *)(work + 0xDE4)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xDE0)), 0, 0);
            func_002e0660((*(void * *)(work + 0xC64)), (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC64)))) + 0x62)), 0U, 0U, 0xA, 0);
            tbl = (f32 *) D_0063F5B0;
            func_002e09e0((*(void * *)(work + 0xC60)), 0x41, 109.0f);
            sp3A0 = func_002b2970(660.0f + tbl[0], tbl[1]);
            sp398 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC60)), *(u64 *)&sp3A0, *(u64 *)&sp398, 0, 4, 6);
            (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC60)))) + 0x62)) = 0xCC;
            sp70C = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_71 = func_002e04e0((*(void * *)(work + 0xC60)));
            *(FclDrawColor *)((u8 *)temp_2_71 + 0x79) = sp70C;
            tbl = (f32 *) D_0063F5F0;
            func_002e09e0((*(void * *)(work + 0xC80)), 0x41, 109.0f);
            sp390 = func_002b2970(660.0f + tbl[0], tbl[1]);
            sp388 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC80)), *(u64 *)&sp390, *(u64 *)&sp388, 0, 4, 6);
            (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC80)))) + 0x62)) = 0xCC;
            sp708 = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_72 = func_002e04e0((*(void * *)(work + 0xC80)));
            *(FclDrawColor *)((u8 *)temp_2_72 + 0x79) = sp708;
            tbl = (f32 *) D_0063F5D0;
            func_002e09e0((*(void * *)(work + 0xC70)), 0x41, 111.0f);
            sp380 = func_002b2970(660.0f + tbl[0], tbl[1]);
            sp378 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC70)), *(u64 *)&sp380, *(u64 *)&sp378, 0, 4, 6);
            (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC70)))) + 0x62)) = 0xCC;
            sp704 = func_002b2a60(0, 0, 0, 0xFF);
            temp_2_73 = func_002e04e0((*(void * *)(work + 0xC70)));
            *(FclDrawColor *)((u8 *)temp_2_73 + 0x79) = sp704;
            func_002e09e0((void *) (*(s32 *)(work + 0xE80)), 0x41, 109.0f);
            sp370 = func_002b2970((f32) -0x266, 242.0f);
            sp368 = func_002b2970(86.0f, 242.0f);
            func_002e0620((void *) (*(s32 *)(work + 0xE80)), *(u64 *)&sp370, *(u64 *)&sp368, 0, 4, 6);
            sp700 = func_002b2a60(0xFF, 0xCB, 0x35, 0xFF);
            temp_2_74 = func_002e04e0((void *) (*(s32 *)(work + 0xE80)));
            *(FclDrawColor *)((u8 *)temp_2_74 + 0x79) = sp700;
            tbl = (f32 *) D_0063F5F8;
            func_002e09e0((*(void * *)(work + 0xC84)), 0x41, 112.0f);
            sp360 = func_002b2970(tbl[0] - 700.0f, tbl[1]);
            sp358 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC84)), *(u64 *)&sp360, *(u64 *)&sp358, 0, 4, 6);
            sp6FC = func_002b2a60(0xFF, 0xCB, 0x35, 0xFF);
            temp_2_75 = func_002e04e0((*(void * *)(work + 0xC84)));
            *(FclDrawColor *)((u8 *)temp_2_75 + 0x79) = sp6FC;
            tbl = (f32 *) D_0063F5D8;
            func_002e09e0((*(void * *)(work + 0xC74)), 0x41, 113.0f);
            sp350 = func_002b2970(tbl[0] - 700.0f, tbl[1]);
            sp348 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC74)), *(u64 *)&sp350, *(u64 *)&sp348, 0, 4, 6);
            tbl = (f32 *) D_0063F5E0;
            func_002e09e0((*(void * *)(work + 0xC78)), 0x41, 114.0f);
            sp340 = func_002b2970(tbl[0] - 700.0f, tbl[1]);
            sp338 = func_002b2970(tbl[0], tbl[1]);
            func_002e0620((*(void * *)(work + 0xC78)), *(u64 *)&sp340, *(u64 *)&sp338, 0, 4, 6);
            (*(s8 *)(work + 0)) = 0x21;
        }
        break;
    case 0x21:                                      /* switch 1 */
        if (func_002d1590(arg0) == 1) {
            if ((D_008C0276[0] & 0x1000) && ((*(s8 *)(work + 0x14)) == 0)) {
                func_0045af60(0, 0, 0, 0);
                if ((*(s16 *)(work + 2)) == 0) {
                    temp_2_76 = func_002e26a0();
                    (*(s16 *)(work + 2)) = temp_2_76;
                    (*(s16 *)(work + 4)) = func_002b2cb0(0, (s32) ((s16) ((s64) temp_2_76)), 4, 0, 1);
                } else {
                    (*(s16 *)(work + 2)) = func_002b2d00((s32) (*(s16 *)(work + 2)), 1, 0, func_002e2670(), 2);
                    (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (func_002e2670())), 5, -1);
                }
                (*(s8 *)(work + 0x14)) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x1000) {
                if (func_002e2670() > 0) {
                    if ((*(s16 *)(work + 2)) != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)(work + 2)) = func_002b2d00((s32) (*(s16 *)(work + 2)), 1, 0, 0, 1);
                    (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (func_002e2670())), 5, -1);
                    (*(s8 *)(work + 0x14)) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C0276[0] & 0x4000) && ((*(s8 *)(work + 0x14)) == 0)) {
                func_0045af60(0, 0, 0, 0);
                temp_2_77 = func_002b2cb0((s32) (*(s16 *)(work + 2)), 1, func_002e26a0(), 0, 2);
                (*(s16 *)(work + 2)) = temp_2_77;
                if (((s16) ((s64) temp_2_77)) == 0) {
                    (*(s16 *)(work + 4)) = 0;
                } else if (func_002e26a0() >= 5) {
                    (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (func_002e26a0())), 5, 1);
                } else {
                    temp_16_57 = (s16) (func_002e26a0());
                    (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) temp_16_57, (s32) ((s16) (func_002e2670())), 1);
                }
                (*(s8 *)(work + 0x14)) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x4000) {
                if (func_002e2670() > 0) {
                    temp_16_58 = (*(s16 *)(work + 2));
                    if (temp_16_58 != func_002e26a0()) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)(work + 2)) = func_002b2cb0((s32) (*(s16 *)(work + 2)), 1, func_002e26a0(), 0, 1);
                    if (func_002e26a0() >= 5) {
                        (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (func_002e26a0())), 5, 1);
                    } else {
                        temp_16_59 = (s16) (func_002e26a0());
                        (*(s16 *)(work + 4)) = func_002b2d50((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) temp_16_59, (s32) ((s16) (func_002e2670())), 1);
                    }
                    (*(s8 *)(work + 0x14)) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
                temp_16_60 = (*(s16 *)(work + 2));
                if (temp_16_60 != func_002e26a0()) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), func_002e2670(), 5, work + 2, work + 4);
            } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
                if ((*(s16 *)(work + 2)) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2f90((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), func_002e2670(), 5, work + 2, work + 4);
            } else if (D_008C027A[0] & 8) {
                (*(s16 *)(work + 2)) = 0;
                (*(s16 *)(work + 4)) = 0;
                (*(s8 *)(work + 8)) = func_002b2cb0((s32) (*(s8 *)(work + 8)), 1, (*(s8 *)(work + 9)) - 1, 0, 2);
                temp_2_78 = (*(s8 *)(work + 7));
                switch (temp_2_78) {                /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    func_002e2a10(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                    break;
                case 1:                             /* switch 4 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                case 2:                             /* switch 4 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C027A[0] & 4) {
                (*(s16 *)(work + 2)) = 0;
                (*(s16 *)(work + 4)) = 0;
                (*(s8 *)(work + 8)) = func_002b2d00((s32) (*(s8 *)(work + 8)), 1, 0, (*(s8 *)(work + 9)) - 1, 2);
                temp_2_79 = (*(s8 *)(work + 7));
                switch (temp_2_79) {                /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    func_002e2a10(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                    break;
                case 1:                             /* switch 5 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                case 2:                             /* switch 5 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C024E[0] & 0x20) {
                func_002d3ee0(arg0);
                (*(s8 *)(work + 0)) = 0x22;
                func_002e0940((*(void * *)(work + 0xE2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xE2C)))) + 0xC4)), 0.0f, 0, 2, 0);
                func_002e0940((*(void * *)(work + 0xE30)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xE30)))) + 0xC4)), 0.0f, 0, 2, 0);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x80) {
                func_002d3ee0(arg0);
                (*(s8 *)(work + 0)) = 0x22;
                func_002e0940((*(void * *)(work + 0xE2C)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xE2C)))) + 0xC4)), 0.0f, 0, 2, 0);
                func_002e0940((*(void * *)(work + 0xE30)), (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xE30)))) + 0xC4)), 0.0f, 0, 2, 0);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (func_002e2670() > 0) {
                    temp_16_61 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
                    if ((func_002e7a60() >= temp_16_61) && ((func_00106600((s16) ((s16) (func_002e2740((*(s16 *)(work + 2)))))) & 0xFF) < 0x63)) {
                        sp688.v0 = func_002e2740((*(s16 *)(work + 2)));
                        sp688.v1 = 0;
                        (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 1, &sp688, 1);
                        (*(s8 *)(work + 0)) = 0x23;
                        func_0045af60(0, 0, 0, 1);
                    } else {
                        func_0045af60(0, 0, 0, 8);
                    }
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            }
block_368:
            (*(s8 *)(work + 0x14)) = 0;
            break;
        }
        break;
    case 0x22:                                      /* switch 1 */
        sp330 = func_002b2970((f32) 0x24E, 61.0f);
        sp6F8 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
        temp_18_49 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
        temp_16_62 = func_0046a770(&D_0063FAA0);
        func_002cacd0(sp330, 1.0f, sp6F8, 0x11, 5, temp_18_49, 0x70, 0x7A, (s32) temp_16_62, (s32) func_0046a770(&D_0063FAA0), 0xAA);
        func_002cb6c0(arg0, 0);
        if ((((s8) (func_002e05a0((*(void * *)(work + 0xD70))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xD7C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC8C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC90))))) == 0)) {
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x23:                                      /* switch 1 */
        func_002d1590(arg0);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)(work + 0x10)));
            func_002d3ee0(arg0);
            func_002e04f0((*(void * *)(work + 0xDC8)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xDD0)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 1);
            sp680.v0 = func_002e2740((*(s16 *)(work + 2)));
            sp680.v1 = 0;
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 4, &sp680, 1);
            func_002d6190(arg0);
            temp_16_63 = func_00106a90((s16) ((s16) (func_002e2740((*(s16 *)(work + 2))))));
            func_002e7a80(func_002e7a60() - temp_16_63);
            (*(s8 *)(work + 0)) = 0x1E;
        } else {
            func_002bb550((*(s8 *)(work + 0x10)));
            (*(s8 *)(work + 0)) = 0x21;
        }
        break;
    case 0x24:                                      /* switch 1 */
        (*(s16 *)(work + 0x12)) = 1;
        if (((s8) (func_002e05a0((*(void * *)(work + 0xC64))))) == 0) {
            func_002cdf80(arg0, 0);
        }
        break;
    case 0x25:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        while (((s16) (var_19)) < 2) {
            temp_18_50 = func_002e04e0((*(void * *)(work + 0xDCC)));
            temp_16_64 = func_002e04e0((*(void * *)(work + 0xDD0)));
            temp_2_80 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3E));
            var_f12_10 = (f32) temp_2_80;
            temp_f0_12 = func_002b2aa0(1, var_f12_10, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_12 = (u8) temp_f0_12;
            (*(s8 *)((u8 *)temp_16_64 + 0x79)) = var_3_12;
            (*(s8 *)((u8 *)temp_18_50 + 0x79)) = var_3_12;
            temp_2_81 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3F));
            var_f12_11 = (f32) temp_2_81;
            temp_f0_13 = func_002b2aa0(1, var_f12_11, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_13 = (u8) temp_f0_13;
            (*(s8 *)((u8 *)temp_16_64 + 0x7A)) = var_3_13;
            (*(s8 *)((u8 *)temp_18_50 + 0x7A)) = var_3_13;
            temp_2_82 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF40));
            var_f12_12 = (f32) temp_2_82;
            temp_f0_14 = func_002b2aa0(1, var_f12_12, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_14 = (u8) temp_f0_14;
            (*(s8 *)((u8 *)temp_16_64 + 0x7B)) = var_3_14;
            (*(s8 *)((u8 *)temp_18_50 + 0x7B)) = var_3_14;
            var_19 = (s16) ((var_19 + 1));
        }
        temp_4_10 = (*(s16 *)(work + 0xF3C));
        if (temp_4_10 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_10, 1, 6, 0, 1);
        } else {
            temp_2_83 = func_002e04e0((*(void * *)(work + 0xDCC)));
            *(FclDrawColor *)((u8 *)temp_2_83 + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            temp_2_84 = func_002e04e0((*(void * *)(work + 0xDD0)));
            *(FclDrawColor *)((u8 *)temp_2_84 + 0x79) = *(FclDrawColor *)(work + 0xF42);
            temp_3_18 = (*(s8 *)(work + 0x11));
            if ((temp_3_18 == 0) && ((*(s16 *)(work + 2)) == 0)) {
                var_19_4 = 0;
                for (var_18_5 = 1; var_18_5 < func_002e26f0((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_18_5++) {
                    temp_2_85 = func_002e2830((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_5);
                    temp_21_2 = func_00106a90((s16) ((s16) (temp_2_85))) / 5U;
                    var_19_4 += temp_21_2 * (func_00106600((s16) ((s16) (temp_2_85))) & 0xFF);
                }
                func_00442088(spD0, iGpffffa880, func_002b2cb0(var_19_4, 0, 0x98967F, 0, 1));
                (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 6, spD0, 1);
                (*(s8 *)(work + 0)) = 0x2E;
            } else if (func_002e26f0((((void**)(work + 0xF18))[temp_3_18])) > 0) {
                func_002e0660((*(void * *)(work + 0xDCC)), 0xFFU, 0U, 0U, 5, 0);
                func_002e0660((*(void * *)(work + 0xDD0)), 0xFFU, 0U, 0U, 5, 0);
                if ((*(s8 *)(work + 0xC24)) == 0) {
                    temp_16_66 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x2A);
                    func_002e09e0((*(void * *)(work + 0xCE0)), 0x56, 16.0f);
                    sp6F4 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
                    temp_2_86 = func_002e04e0((*(void * *)(work + 0xCE0)));
                    *(FclDrawColor *)((u8 *)temp_2_86 + 0x79) = sp6F4;
                    func_002e06d0((*(void * *)(work + 0xCE0)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    sp328 = func_002b2970(63.0f, 143.0f + 2.5f * (func_0046b2f0(temp_16_66) / 10.0f));
                    sp320 = func_002b2970(63.0f, 143.0f);
                    func_002e0620((*(void * *)(work + 0xCE0)), *(u64 *)&sp328, *(u64 *)&sp320, 0, 5, 0);
                    func_002e0660((*(void * *)(work + 0xCE0)), 0U, 0xFFU, 0U, 0, 0);
                    func_002e09b0((*(void * *)(work + 0xCE0)), 3, 6.0f);
                    func_0046d280(temp_16_66);
                    temp_16_67 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x2C);
                    func_002e09e0((*(void * *)(work + 0xCE8)), 0x56, 18.0f);
                    sp6F0 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
                    temp_2_87 = func_002e04e0((*(void * *)(work + 0xCE8)));
                    *(FclDrawColor *)((u8 *)temp_2_87 + 0x79) = sp6F0;
                    func_002e06d0((*(void * *)(work + 0xCE8)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    sp318 = func_002b2970((f32) 0x222, 143.0f + 2.5f * (func_0046b2f0(temp_16_67) / 10.0f));
                    sp310 = func_002b2970((f32) 0x222, 143.0f);
                    func_002e0620((*(void * *)(work + 0xCE8)), *(u64 *)&sp318, *(u64 *)&sp310, 0, 5, 0);
                    func_002e0660((*(void * *)(work + 0xCE8)), 0U, 0xFFU, 0U, 0, 0);
                    func_002e09b0((*(void * *)(work + 0xCE8)), 3, 6.0f);
                    func_0046d280(temp_16_67);
                    temp_16_68 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x27);
                    func_002e09e0((*(void * *)(work + 0xCD4)), 0x41, 20.0f);
                    sp6EC = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                    temp_2_88 = func_002e04e0((*(void * *)(work + 0xCD4)));
                    *(FclDrawColor *)((u8 *)temp_2_88 + 0x79) = sp6EC;
                    func_002e06d0((*(void * *)(work + 0xCD4)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    func_002e0660((*(void * *)(work + 0xCD4)), 0U, 0xFFU, 0U, 4, 0);
                    sp308 = func_002b2970(46.0f, 132.0f + 2.0f * (func_0046b2f0(temp_16_68) / 10.0f));
                    sp300 = func_002b2970(46.0f, 132.0f);
                    func_002e0620((*(void * *)(work + 0xCD4)), *(u64 *)&sp308, *(u64 *)&sp300, 2, 4, 0);
                    func_002e09b0((*(void * *)(work + 0xCD4)), 3, 6.0f);
                    func_0046d280(temp_16_68);
                    temp_16_69 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x29);
                    func_002e09e0((*(void * *)(work + 0xCDC)), 0x41, 21.0f);
                    sp6E8 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                    temp_2_89 = func_002e04e0((*(void * *)(work + 0xCDC)));
                    *(FclDrawColor *)((u8 *)temp_2_89 + 0x79) = sp6E8;
                    func_002e06d0((*(void * *)(work + 0xCDC)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    func_002e0660((*(void * *)(work + 0xCDC)), 0U, 0xFFU, 0U, 4, 0);
                    sp2F8 = func_002b2970((f32) 0x232, 132.0f + 2.0f * (func_0046b2f0(temp_16_69) / 10.0f));
                    sp2F0 = func_002b2970((f32) 0x232, 132.0f);
                    func_002e0620((*(void * *)(work + 0xCDC)), *(u64 *)&sp2F8, *(u64 *)&sp2F0, 2, 4, 0);
                    func_002e09b0((*(void * *)(work + 0xCDC)), 3, 6.0f);
                    func_0046d280(temp_16_69);
                } else {
                    temp_16_70 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x2B);
                    func_002e09e0((*(void * *)(work + 0xCE4)), 0x56, 16.0f);
                    sp6E4 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
                    temp_2_90 = func_002e04e0((*(void * *)(work + 0xCE4)));
                    *(FclDrawColor *)((u8 *)temp_2_90 + 0x79) = sp6E4;
                    func_002e06d0((*(void * *)(work + 0xCE4)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    sp2E8 = func_002b2970(67.0f, 140.0f + 2.5f * (func_0046b2f0(temp_16_70) / 10.0f));
                    sp2E0 = func_002b2970(67.0f, 140.0f);
                    func_002e0620((*(void * *)(work + 0xCE4)), *(u64 *)&sp2E8, *(u64 *)&sp2E0, 0, 5, 0);
                    func_002e0660((*(void * *)(work + 0xCE4)), 0U, 0xFFU, 0U, 0, 0);
                    func_002e09b0((*(void * *)(work + 0xCE4)), 3, 6.0f);
                    func_0046d280(temp_16_70);
                    temp_16_71 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x2C);
                    func_002e09e0((*(void * *)(work + 0xCE8)), 0x56, 18.0f);
                    sp6E0 = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
                    temp_2_91 = func_002e04e0((*(void * *)(work + 0xCE8)));
                    *(FclDrawColor *)((u8 *)temp_2_91 + 0x79) = sp6E0;
                    func_002e06d0((*(void * *)(work + 0xCE8)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    sp2D8 = func_002b2970((f32) 0x22F, 140.0f + 2.5f * (func_0046b2f0(temp_16_71) / 10.0f));
                    sp2D0 = func_002b2970((f32) 0x22F, 140.0f);
                    func_002e0620((*(void * *)(work + 0xCE8)), *(u64 *)&sp2D8, *(u64 *)&sp2D0, 0, 5, 0);
                    func_002e0660((*(void * *)(work + 0xCE8)), 0U, 0xFFU, 0U, 0, 0);
                    func_002e09b0((*(void * *)(work + 0xCE8)), 3, 6.0f);
                    func_0046d280(temp_16_71);
                    temp_16_72 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x28);
                    func_002e09e0((*(void * *)(work + 0xCD8)), 0x41, 20.0f);
                    sp6DC = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                    temp_2_92 = func_002e04e0((*(void * *)(work + 0xCD8)));
                    *(FclDrawColor *)((u8 *)temp_2_92 + 0x79) = sp6DC;
                    func_002e06d0((*(void * *)(work + 0xCD8)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    func_002e0660((*(void * *)(work + 0xCD8)), 0U, 0xFFU, 0U, 4, 0);
                    sp2C8 = func_002b2970(48.0f, 127.0f + 2.0f * (func_0046b2f0(temp_16_72) / 10.0f));
                    sp2C0 = func_002b2970(48.0f, 127.0f);
                    func_002e0620((*(void * *)(work + 0xCD8)), *(u64 *)&sp2C8, *(u64 *)&sp2C0, 2, 4, 0);
                    func_002e09b0((*(void * *)(work + 0xCD8)), 3, 6.0f);
                    func_0046d280(temp_16_72);
                    temp_16_73 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 0x29);
                    func_002e09e0((*(void * *)(work + 0xCDC)), 0x41, 21.0f);
                    sp6D8 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                    temp_2_93 = func_002e04e0((*(void * *)(work + 0xCDC)));
                    *(FclDrawColor *)((u8 *)temp_2_93 + 0x79) = sp6D8;
                    func_002e06d0((*(void * *)(work + 0xCDC)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    func_002e0660((*(void * *)(work + 0xCDC)), 0U, 0xFFU, 0U, 4, 0);
                    sp2B8 = func_002b2970(584.0f, 127.0f + 2.0f * (func_0046b2f0(temp_16_73) / 10.0f));
                    sp2B0 = func_002b2970(584.0f, 127.0f);
                    func_002e0620((*(void * *)(work + 0xCDC)), *(u64 *)&sp2B8, *(u64 *)&sp2B0, 2, 4, 0);
                    func_002e09b0((*(void * *)(work + 0xCDC)), 3, 6.0f);
                    func_0046d280(temp_16_73);
                tbl = (f32 *) D_0063F688;
                }
                func_002e09e0((*(void * *)(work + 0xCCC)), 0x57, 14.0f);
                sp2A8 = func_002b2970(tbl[0], tbl[1]);
                sp2A0 = func_002b2970(tbl[0], tbl[1] - 7.0f);
                func_002e0620((*(void * *)(work + 0xCCC)), *(u64 *)&sp2A8, *(u64 *)&sp2A0, 1, 0xA, 2);
                func_002e0660((*(void * *)(work + 0xCCC)), 0U, 0xFFU, 0U, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCCC)))) + 0x3B)) = 1;
                sp6D4 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                temp_2_94 = func_002e04e0((*(void * *)(work + 0xCCC)));
                *(FclDrawColor *)((u8 *)temp_2_94 + 0x79) = sp6D4;
                (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
                tbl = (f32 *) D_0063F690;
                func_002e09e0((*(void * *)(work + 0xCD0)), 0x57, 15.0f);
                sp298 = func_002b2970(tbl[0], tbl[1]);
                sp290 = func_002b2970(tbl[0], 7.0f + tbl[1]);
                func_002e0620((*(void * *)(work + 0xCD0)), *(u64 *)&sp298, *(u64 *)&sp290, 1, 0xA, 2);
                func_002e0660((*(void * *)(work + 0xCD0)), 0U, 0xFFU, 0U, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCD0)))) + 0x3B)) = 1;
                sp6D0 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                temp_2_95 = func_002e04e0((*(void * *)(work + 0xCD0)));
                *(FclDrawColor *)((u8 *)temp_2_95 + 0x79) = sp6D0;
                (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
                func_002e09e0((*(void * *)(work + 0xCC8)), 0x57, 15.0f);
                sp6CC = func_002b2a60(0xDF, 0x6C, 0, 0xFF);
                temp_2_96 = func_002e04e0((*(void * *)(work + 0xCC8)));
                *(FclDrawColor *)((u8 *)temp_2_96 + 0x79) = sp6CC;
                func_002e0660((*(void * *)(work + 0xCC8)), 0U, 0xFFU, 0U, 4, 2);
                (*(s8 *)(work + 0)) = 0x27;
            }
        }
        break;
    case 0x27:                                      /* switch 1 */
        temp_16_74 = (s16) (func_002e2830((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))));
        temp_18_51 = func_002e28f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))) & 0xFF;
        func_002cdf80(arg0, 2);
        func_002df020(arg0, temp_16_74, temp_18_51);
        func_002dd3b0(arg0);
        if (D_008C027A[0] & 0x1000) {
            temp_18_52 = (*(s16 *)(work + 0x12));
            if (temp_18_52 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = func_002b2cb0((s32) (*(s16 *)(work + 0x12)), 1, func_00106600(temp_16_74) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            sp288 = func_002b2970(tbl[0], tbl[1]);
            sp280 = func_002b2970(tbl[0], tbl[1] - 7.0f);
            func_002e0620((*(void * *)(work + 0xCCC)), *(u64 *)&sp288, *(u64 *)&sp280, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x2000) {
            temp_18_53 = (*(s16 *)(work + 0x12));
            if (temp_18_53 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = func_002b2cb0((s32) (*(s16 *)(work + 0x12)), 0xA, func_00106600(temp_16_74) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            sp278 = func_002b2970(tbl[0], tbl[1]);
            sp270 = func_002b2970(tbl[0], tbl[1] - 7.0f);
            func_002e0620((*(void * *)(work + 0xCCC)), *(u64 *)&sp278, *(u64 *)&sp270, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if ((*(s16 *)(work + 0x12)) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = func_002b2d00((s32) (*(s16 *)(work + 0x12)), 1, 1, func_00106600(temp_16_74) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            sp268 = func_002b2970(tbl[0], tbl[1]);
            sp260 = func_002b2970(tbl[0], 7.0f + tbl[1]);
            func_002e0620((*(void * *)(work + 0xCD0)), *(u64 *)&sp268, *(u64 *)&sp260, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x8000) {
            if ((*(s16 *)(work + 0x12)) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = func_002b2d00((s32) (*(s16 *)(work + 0x12)), 0xA, 1, func_00106600(temp_16_74) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            sp258 = func_002b2970(tbl[0], tbl[1]);
            sp250 = func_002b2970(tbl[0], 7.0f + tbl[1]);
            func_002e0620((*(void * *)(work + 0xCD0)), *(u64 *)&sp258, *(u64 *)&sp250, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
        } else if (D_008C024E[0] & 0x40) {
            sp678.v0 = (s32) ((s16) (temp_16_74));
            sp678.v1 = 0;
            func_00442088(spC0, iGpffffa880, (*(s16 *)(work + 0x12)));
            (*(s8 *)(work + 0x10)) = func_002dff90(arg0, 2, &sp678, spC0, 1);
            (*(s8 *)(work + 0)) = 0x28;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            func_0045af60(0, 0, 0, 2);
            func_002df4c0(arg0);
            func_002e0660((*(void * *)(work + 0xCCC)), 0xFFU, 0U, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xCD0)), 0xFFU, 0U, 0U, 5, 0);
            func_002e04f0((*(void * *)(work + 0xCC8)), 0, 1);
            func_002e0660((*(void * *)(work + 0xDCC)), 0U, 0xFFU, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xDD0)), 0U, 0xFFU, 0U, 5, 0);
            (*(s8 *)(work + 0)) = 0x24;
            if ((*(s8 *)(work + 0xC24)) == 1) {
                (*(s8 *)(work + 0)) = 0x31;
            }
        }
        break;
    case 0x28:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        temp_19_7 = (s16) (func_002e2830((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))));
        temp_16_75 = (s16) (func_002e28f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))));
        temp_18_54 = func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]));
        temp_23_2 = (*(s16 *)(work + 2));
        temp_30 = (*(s16 *)(work + 4));
        func_002df020(arg0, temp_19_7, temp_16_75 & 0xFF);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            (*(s16 *)(work + 0xC16)) = 0;
            (*(s16 *)(work + 0xC18)) = 0;
            if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
                func_0045af60(0, 0, 0, 6);
                if (func_00106850(temp_19_7) == 5) {
                    temp_16_76 = (s16) (temp_19_7);
                    func_00110810(temp_16_76, func_002b2cb0(func_00110830(temp_16_76) & 0xFF, (s32) (*(s16 *)(work + 0x12)), 0xFF, 0, 1) & 0xFF);
                    for (var_16_20 = 0; var_16_20 < 0x2FF; var_16_20++) {
                        if (!(func_00110830(var_16_20) & 0xFF)) {
                            temp_21_3 = (s32) (func_00106b20(var_16_20) & 0xFFF00) >> 8;
                            if (func_002be160(temp_21_3, func_00106b20(var_16_20) & 0xFF) == 1) {
                                temp_21_4 = (s32) (func_00106b50(var_16_20) & 0xFFF00) >> 8;
                                if (func_002be160(temp_21_4, func_00106b50(var_16_20) & 0xFF) == 1) {
                                    (*(s16 *)((u8 *)((work + ((*(s16 *)(work + 0xC16)) * 2))) + 0x16)) = var_16_20;
                                    (*(s16 *)(work + 0xC16)) = (s16) ((*(s16 *)(work + 0xC16)) + 1);
                                }
                            }
                        }
                    }
                }
                temp_16_77 = func_00106a90((s16) ((s16) (temp_19_7))) / 5U;
                temp_2_yen = func_002e7a60();
                func_002e7a80(temp_2_yen + ((*(s16 *)(work + 0x12)) * temp_16_77));
                func_00106620(temp_19_7, ((func_00106600(temp_19_7) & 0xFF) - (*(s16 *)(work + 0x12))) & 0xFF);
                temp_3_19 = (*(s8 *)(work + 0x11));
                switch (temp_3_19) {                /* switch 6; irregular */
                case 0:                             /* switch 6 */
                    func_002e3560((((void**)(work + 0xF18))[temp_3_19]), 0x40000, 0, 4, 0);
                    (*(s32 *)(work + 0xC20)) = 0;
                    for (var_19_5 = 1; var_19_5 < func_002e26f0((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_19_5++) {
                        temp_21_5 = (s16) (func_002e2830((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_19_5));
                        func_002e28f0((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_19_5);
                        temp_16_79 = (s16) (temp_21_5);
                        temp_22_2 = func_00110830(temp_16_79) & 0xFF;
                        func_002b2cb0(temp_22_2, func_00106600(temp_21_5) & 0xFF, 0xFF, 0, 1);
                        temp_16_80 = func_00106a90((s16) ((s16) (temp_16_79))) / 5U;
                        temp_4_12 = (*(s32 *)(work + 0xC20)) + (temp_16_80 * (func_00106600(temp_21_5) & 0xFF));
                        (*(s32 *)(work + 0xC20)) = temp_4_12;
                        (*(s32 *)(work + 0xC20)) = func_002b2cb0(temp_4_12, 0, 0x98967F, 0, 1);
                    }
                    break;
                case 1:                             /* switch 6 */
                    func_002e3560((((void**)(work + 0xF18))[temp_3_19]), 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:                             /* switch 6 */
                    func_002e3560((((void**)(work + 0xF18))[temp_3_19]), 0x10000, 0, 1, 0);
                    break;
                }
                if (temp_18_54 != func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]))) {
                    temp_4_13 = (s16) ((s64) temp_23_2);
                    if ((temp_4_13 - ((s16) ((s64) temp_30))) > 0) {
                        temp_16_81 = (s16) (func_002b2d00((s32) temp_4_13, 1, 0, 0, 1));
                        (*(s16 *)(work + 2)) = 0;
                        (*(s16 *)(work + 2)) = func_002b2cb0((s32) (*(s16 *)(work + 2)), (s32) ((s16) (temp_16_81)), func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                    } else {
                        (*(s16 *)(work + 2)) = func_002b2cb0((s32) (*(s16 *)(work + 2)), 0, func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                    }
                    (*(s16 *)(work + 4)) = func_002b2cb0((s32) (*(s16 *)(work + 4)), 0, func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                }
                func_002d4760(arg0, (*(s8 *)(work + 0x11)));
            }
            func_002df4c0(arg0);
            func_002bb550((*(s8 *)(work + 0x10)));
            func_002e0660((*(void * *)(work + 0xCCC)), 0xFFU, 0U, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xCD0)), 0xFFU, 0U, 0U, 5, 0);
            func_002e04f0((*(void * *)(work + 0xCC8)), 0, 1);
            func_002e0660((*(void * *)(work + 0xDCC)), 0U, 0xFFU, 0U, 5, 0);
            func_002e0660((*(void * *)(work + 0xDD0)), 0U, 0xFFU, 0U, 5, 0);
            (*(s8 *)(work + 0)) = 0x24;
            if ((*(s8 *)(work + 0xC24)) == 1) {
                if (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) <= D_00748908[(*(s8 *)(work + 0x11))]) {
                    func_002d8600(arg0);
                } else {
                    (*(s8 *)(work + 0)) = 0x31;
                }
            }
            if ((*(s16 *)(work + 0xC16)) > 0) {
                (*(s8 *)(work + 0xC1A)) = 0;
                func_002dfe00(arg0);
                (*(s8 *)(work + 0)) = 0x29;
            }
        }
        break;
    case 0x2E:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            (*(s16 *)(work + 0xC16)) = 0;
            (*(s16 *)(work + 0xC18)) = 0;
            if (func_002bb1c0((*(s8 *)(work + 0x10))) == 0) {
                func_002bb550((*(s8 *)(work + 0x10)));
                func_0045af60(0, 0, 0, 6);
                for (var_18_6 = 1; var_18_6 < func_002e26f0((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_18_6++) {
                    temp_19_8 = func_002e2830((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_6);
                    func_002e28f0((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_6);
                    temp_16_83 = func_00110830(temp_19_8) & 0xFF;
                    func_00110810(temp_19_8, func_002b2cb0(temp_16_83, func_00106600((s16) ((s16) ((s64) temp_19_8))) & 0xFF, 0xFF, 0, 1) & 0xFF);
                    temp_16_84 = func_00106a90((s16) ((s16) ((s64) temp_19_8))) / 5U;
                    temp_16_85 = temp_16_84 * (func_00106600((s16) ((s16) ((s64) temp_19_8))) & 0xFF);
                    func_002e7a80(func_002e7a60() + temp_16_85);
                    func_00106620((s16) ((s16) ((s64) temp_19_8)), 0);
                }
                (*(s32 *)(work + 0xC20)) = 0;
                for (var_16_21 = 0; var_16_21 < 0x2FF; var_16_21++) {
                    if (!(func_00110830(var_16_21) & 0xFF)) {
                        temp_18_55 = (s32) (func_00106b20(var_16_21) & 0xFFF00) >> 8;
                        if (func_002be160(temp_18_55, func_00106b20(var_16_21) & 0xFF) == 1) {
                            temp_18_56 = (s32) (func_00106b50(var_16_21) & 0xFFF00) >> 8;
                            if (func_002be160(temp_18_56, func_00106b50(var_16_21) & 0xFF) == 1) {
                                (*(s16 *)((u8 *)((work + ((*(s16 *)(work + 0xC16)) * 2))) + 0x16)) = var_16_21;
                                (*(s16 *)(work + 0xC16)) = (s16) ((*(s16 *)(work + 0xC16)) + 1);
                            }
                        }
                    }
                }
                func_002e3560((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), 0x40000, 0, 4, 0);
                (*(s32 *)(work + 0xC20)) = 0;
                (*(s16 *)(work + 2)) = func_002b2cb0((s32) (*(s16 *)(work + 2)), 0, func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                temp_18_57 = (*(s16 *)(work + 4));
                temp_16_86 = func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]));
                if (func_002b32a0((s32) (*(s16 *)(work + 4)), 5, temp_16_86, func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]))) < temp_18_57) {
                    temp_16_87 = (s16) (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])));
                    (*(s16 *)(work + 4)) = func_002b32a0((s32) (*(s16 *)(work + 4)), 5, (s32) temp_16_87, (s32) ((s16) (func_002e2700((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])))));
                }
                func_002e04f0((*(void * *)(work + 0xE40)), 0, 1);
                func_002e04f0((*(void * *)(work + 0xE44)), 0, 1);
                func_002e04f0((*(void * *)(work + 0xE48)), 0, 1);
                func_002d4760(arg0, (*(s8 *)(work + 0x11)));
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    func_002d8600(arg0);
                }
                if ((*(s16 *)(work + 0xC16)) > 0) {
                    (*(s8 *)(work + 0xC1A)) = 0;
                    func_002dfe00(arg0);
                    (*(s8 *)(work + 0)) = 0x29;
                }
            } else {
                func_002bb550((*(s8 *)(work + 0x10)));
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    func_002d8600(arg0);
                }
            }
        }
        break;
    case 0x29:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            func_002bb550((*(s8 *)(work + 0x10)));
            func_0045aeb0(2, (const char *) D_0063FAF0);
            (*(s8 *)(work + 0)) = 0x2A;
        }
        break;
    case 0x2A:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        (*(s8 *)(work + 0xC1A)) = func_002b2cb0((s32) (*(s8 *)(work + 0xC1A)), 1, 0x3C, 0, 1);
        if ((*(s8 *)(work + 0xC1A)) >= 0x3C) {
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 0xA, NULL, 0);
            (*(s8 *)(work + 0)) = 0x2B;
            (*(s8 *)(work + 0xC1A)) = 0;
        }
        break;
    case 0x2B:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            func_002bb550((*(s8 *)(work + 0x10)));
            sp670.v0 = (s32) (((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]);
            sp670.v1 = 0;
            (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 3, &sp670, 0);
            (*(s8 *)(work + 0)) = 0x2D;
        }
        break;
    case 0x2C:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        sp668.v0 = (s32) (((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]);
        sp668.v1 = 0;
        (*(s8 *)(work + 0x10)) = func_002dfec0(arg0, 3, &sp668, 0);
        (*(s8 *)(work + 0)) = 0x2D;
        break;
    case 0x2D:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)(work + 0x10))) != 0) {
            func_002bbcf0((*(s8 *)(work + 0x10)));
        } else {
            temp_3_flag = func_00110830((((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]));
            func_00110810((((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]), temp_3_flag | 1);
            func_002bb550((*(s8 *)(work + 0x10)));
            temp_2_98 = (*(s16 *)(work + 0xC18)) + 1;
            (*(s16 *)(work + 0xC18)) = temp_2_98;
            if (((s16) ((s64) temp_2_98)) >= (*(s16 *)(work + 0xC16))) {
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    (*(s8 *)(work + 0)) = 0x31;
                }
            } else {
                func_002dfe00(arg0);
                (*(s8 *)(work + 0)) = 0x29;
            }
        }
        break;
    case 0x26:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        for (var_20_2 = 0; var_20_2 < 2; var_20_2++) {
            temp_19_9 = func_002e04e0((*(void * *)(work + 0xDCC)));
            temp_18_58 = func_002e04e0((*(void * *)(work + 0xDD0)));
            temp_2_99 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF3E));
            var_f12_13 = (f32) temp_2_99;
            temp_f0_15 = func_002b2aa0(1, var_f12_13, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_15 = (u8) temp_f0_15;
            (*(s8 *)((u8 *)temp_18_58 + 0x79)) = var_3_15;
            (*(s8 *)((u8 *)temp_19_9 + 0x79)) = var_3_15;
            temp_2_100 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF3F));
            var_f12_14 = (f32) temp_2_100;
            temp_f0_16 = func_002b2aa0(1, var_f12_14, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_16 = (u8) temp_f0_16;
            (*(s8 *)((u8 *)temp_18_58 + 0x7A)) = var_3_16;
            (*(s8 *)((u8 *)temp_19_9 + 0x7A)) = var_3_16;
            temp_2_101 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF40));
            var_f12_15 = (f32) temp_2_101;
            temp_f0_17 = func_002b2aa0(1, var_f12_15, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_17 = (u8) temp_f0_17;
            (*(s8 *)((u8 *)temp_18_58 + 0x7B)) = var_3_17;
            (*(s8 *)((u8 *)temp_19_9 + 0x7B)) = var_3_17;
        }
        temp_4_15 = (*(s16 *)(work + 0xF3C));
        if (temp_4_15 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_15, 1, 6, 0, 1);
        } else {
            temp_2_102 = func_002e04e0((*(void * *)(work + 0xDCC)));
            *(FclDrawColor *)((u8 *)temp_2_102 + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            temp_2_103 = func_002e04e0((*(void * *)(work + 0xDD0)));
            *(FclDrawColor *)((u8 *)temp_2_103 + 0x79) = *(FclDrawColor *)(work + 0xF42);
            temp_2_104 = func_002e04e0((*(void * *)(work + 0xDCC)));
            sp660 = *(Vec2f *)((u8 *)temp_2_104 + 0x2C);
            sp248 = func_002b2970(sp660.x - 1000.0f, sp660.y);
            func_002e0620((*(void * *)(work + 0xDCC)), *(u64 *)&sp660, *(u64 *)&sp248, 1, 3, 0);
            temp_2_105 = func_002e04e0((*(void * *)(work + 0xDD0)));
            sp160 = *(Vec2f *)((u8 *)temp_2_105 + 0x2C);
            sp240 = func_002b2970(sp160.x - 1000.0f, sp160.y);
            func_002e0620((*(void * *)(work + 0xDD0)), *(u64 *)&sp160, *(u64 *)&sp240, 1, 3, 0);
            (*(s8 *)(work + 0)) = 0x2F;
        }
        break;
    case 0x2F:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        for (var_20_3 = 0; var_20_3 < 2; var_20_3++) {
            temp_19_10 = func_002e04e0((*(void * *)(work + 0xDCC)));
            temp_18_59 = func_002e04e0((*(void * *)(work + 0xDD0)));
            temp_2_106 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF3E));
            var_f12_16 = (f32) temp_2_106;
            temp_f0_18 = func_002b2aa0(1, var_f12_16, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_18 = (u8) temp_f0_18;
            (*(s8 *)((u8 *)temp_18_59 + 0x79)) = var_3_18;
            (*(s8 *)((u8 *)temp_19_10 + 0x79)) = var_3_18;
            temp_2_107 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF3F));
            var_f12_17 = (f32) temp_2_107;
            temp_f0_19 = func_002b2aa0(1, var_f12_17, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_19 = (u8) temp_f0_19;
            (*(s8 *)((u8 *)temp_18_59 + 0x7A)) = var_3_19;
            (*(s8 *)((u8 *)temp_19_10 + 0x7A)) = var_3_19;
            temp_2_108 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF40));
            var_f12_18 = (f32) temp_2_108;
            temp_f0_20 = func_002b2aa0(1, var_f12_18, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_20 = (u8) temp_f0_20;
            (*(s8 *)((u8 *)temp_18_59 + 0x7B)) = var_3_20;
            (*(s8 *)((u8 *)temp_19_10 + 0x7B)) = var_3_20;
        }
        temp_4_16 = (*(s16 *)(work + 0xF3C));
        if (temp_4_16 < 6) {
            (*(s16 *)(work + 0xF3C)) = func_002b2cb0((s32) temp_4_16, 1, 6, 0, 1);
        } else {
            temp_2_109 = func_002e04e0((*(void * *)(work + 0xDCC)));
            *(FclDrawColor *)((u8 *)temp_2_109 + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            temp_2_110 = func_002e04e0((*(void * *)(work + 0xDD0)));
            *(FclDrawColor *)((u8 *)temp_2_110 + 0x79) = *(FclDrawColor *)(work + 0xF42);
            temp_2_111 = func_002e04e0((*(void * *)(work + 0xDCC)));
            sp658 = *(Vec2f *)((u8 *)temp_2_111 + 0x2C);
            sp238 = func_002b2970(sp658.x - 1000.0f, sp658.y);
            func_002e0620((*(void * *)(work + 0xDCC)), *(u64 *)&sp658, *(u64 *)&sp238, 1, 3, 0);
            temp_2_112 = func_002e04e0((*(void * *)(work + 0xDD0)));
            sp158 = *(Vec2f *)((u8 *)temp_2_112 + 0x2C);
            sp230 = func_002b2970(sp158.x - 1000.0f, sp158.y);
            func_002e0620((*(void * *)(work + 0xDD0)), *(u64 *)&sp158, *(u64 *)&sp230, 1, 3, 0);
            func_002e09e0((*(void * *)(work + 0xE50)), 0x41, 109.0f);
            sp228 = func_002b2970((f32) -0x271, 124.0f);
            sp220 = func_002b2970(75.0f, 124.0f);
            func_002e0620((*(void * *)(work + 0xE50)), *(u64 *)&sp228, *(u64 *)&sp220, 0, 4, 5);
            sp6C8 = func_002b2a60(0xFF, 0xCB, 0x35, 0xFF);
            temp_2_113 = func_002e04e0((*(void * *)(work + 0xE50)));
            *(FclDrawColor *)((u8 *)temp_2_113 + 0x79) = sp6C8;
            func_002e09e0((*(void * *)(work + 0xE54)), 0x41, 112.0f);
            sp218 = func_002b2970((f32) -0x271, (f32) 0x11D);
            sp210 = func_002b2970(75.0f, (f32) 0x11D);
            func_002e0620((*(void * *)(work + 0xE54)), *(u64 *)&sp218, *(u64 *)&sp210, 0, 4, 5);
            sp6C4 = func_002b2a60(0xFF, 0xCB, 0x35, 0xFF);
            temp_2_114 = func_002e04e0((*(void * *)(work + 0xE54)));
            *(FclDrawColor *)((u8 *)temp_2_114 + 0x79) = sp6C4;
            func_002e09e0((*(void * *)(work + 0xE58)), 0x41, 113.0f);
            sp208 = func_002b2970(-117.0f, 128.0f);
            sp200 = func_002b2970((f32) 0x247, 128.0f);
            func_002e0620((*(void * *)(work + 0xE58)), *(u64 *)&sp208, *(u64 *)&sp200, 0, 4, 5);
            func_002e09e0((*(void * *)(work + 0xE5C)), 0x41, 114.0f);
            sp1F8 = func_002b2970((f32) -0x2FD, 128.0f);
            sp1F0 = func_002b2970(-65.0f, 128.0f);
            func_002e0620((*(void * *)(work + 0xE5C)), *(u64 *)&sp1F8, *(u64 *)&sp1F0, 0, 4, 5);
            (*(s8 *)(work + 0xC24)) = 1;
            (*(s8 *)(work + 0)) = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if ((((s8) (func_002e0570((*(void * *)(work + 0xDCC)), 9))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xDD0)), 9))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xE50))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xE54))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xE58))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xE5C))))) == 0)) {
            for (var_16_22 = 0; var_16_22 < 3; var_16_22++) {
                func_002e09e0((*(void * *)(work + ((var_16_22) * 4) + 0xDBC)), 0x41, 95.0f);
                sp6C0 = func_002b2a60(0xFF, 0xEF, 0x80, 0xFF);
                temp_2_115 = func_002e04e0((*(void * *)(work + ((var_16_22) * 4) + 0xDBC)));
                *(FclDrawColor *)((u8 *)temp_2_115 + 0x79) = sp6C0;
            }
            sp1E8 = func_002b2970(89.0f, 163.0f);
            temp_2_116 = func_002e04e0((*(void * *)(work + 0xDBC)));
            *(Vec2f *)((u8 *)temp_2_116 + 0x2C) = sp1E8;
            sp1E0 = func_002b2970((f32) 0x1D1, 163.0f);
            temp_2_117 = func_002e04e0((*(void * *)(work + 0xDC0)));
            *(Vec2f *)((u8 *)temp_2_117 + 0x2C) = sp1E0;
            sp1D8 = func_002b2970((f32) 0x22E, 163.0f);
            temp_2_118 = func_002e04e0((*(void * *)(work + 0xDC4)));
            *(Vec2f *)((u8 *)temp_2_118 + 0x2C) = sp1D8;
            func_002e09e0((*(void * *)(work + 0xCAC)), 0x56, 91.0f);
            sp1D0 = func_002b2970((f32) 0x1DF, 167.0f);
            temp_2_119 = func_002e04e0((*(void * *)(work + 0xCAC)));
            *(Vec2f *)((u8 *)temp_2_119 + 0x2C) = sp1D0;
            sp6BC = func_002b2a60(0xFE, 0xC7, 0x31, 0xFF);
            temp_2_120 = func_002e04e0((*(void * *)(work + 0xCAC)));
            *(FclDrawColor *)((u8 *)temp_2_120 + 0x79) = sp6BC;
            func_002e09e0((void *) (*(s32 *)(work + 0xE84)), 0x56, 91.0f);
            sp6B8 = func_002b2a60(0xFE, 0xC7, 0x31, 0xFF);
            temp_2_121 = func_002e04e0((void *) (*(s32 *)(work + 0xE84)));
            *(FclDrawColor *)((u8 *)temp_2_121 + 0x79) = sp6B8;
            sp1C8 = func_002b2970((f32) 0x1DF, 217.0f);
            temp_2_122 = func_002e04e0((void *) (*(s32 *)(work + 0xE84)));
            *(Vec2f *)((u8 *)temp_2_122 + 0x2C) = sp1C8;
            if (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) >= 2) {
                func_002e09e0((*(void * *)(work + 0xC94)), 0x41, 88.0f);
                sp6B4 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                temp_2_123 = func_002e04e0((*(void * *)(work + 0xC94)));
                *(FclDrawColor *)((u8 *)temp_2_123 + 0x79) = sp6B4;
                sp1C0 = func_002b2970((f32) 0x247, 136.0f);
                temp_2_124 = func_002e04e0((*(void * *)(work + 0xC94)));
                *(Vec2f *)((u8 *)temp_2_124 + 0x2C) = sp1C0;
                func_002e09e0((*(void * *)(work + 0xC98)), 0x41, 89.0f);
                sp6B0 = func_002b2a60(0xFF, 0x96, 0, 0xFF);
                temp_2_125 = func_002e04e0((*(void * *)(work + 0xC98)));
                *(FclDrawColor *)((u8 *)temp_2_125 + 0x79) = sp6B0;
                sp1B8 = func_002b2970((f32) 0x247, 272.0f);
                temp_2_126 = func_002e04e0((*(void * *)(work + 0xC98)));
                *(Vec2f *)((u8 *)temp_2_126 + 0x2C) = sp1B8;
            }
            (*(s8 *)(work + 0)) = 0x31;
        }
        break;
    case 0x31:                                      /* switch 1 */
        func_002e04f0((*(void * *)(work + 0xCA0)), 0, 1);
        func_002e04f0((*(void * *)(work + 0xCA8)), 0, 1);
        func_002e04f0((*(void * *)(work + 0xC9C)), 0, 1);
        func_002e04f0((*(void * *)(work + 0xCA4)), 0, 1);
        func_002e04f0((*(void * *)(work + 0xCB8)), 0, 1);
        func_002e04f0((void *) (*(s32 *)(work + 0xEAC)), 0, 1);
        func_002cdf80(arg0, 1);
        func_002dd3b0(arg0);
        if ((((s8) (func_002e0570((*(void * *)(work + 0xE38)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xCC4)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xCC0)), 1))) == 0) && ((D_008C0276[0] & 0x80) || (D_008C0276[0] & 0x20))) {
            func_0045af60(0, 1, 0, 4);
            func_002d8600(arg0);
            func_002e04f0((*(void * *)(work + 0xDE4)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xDE0)), 0, 1);
            temp_2_127 = func_002e04e0((*(void * *)(work + 0xDCC)));
            sp650 = *(Vec2f *)((u8 *)temp_2_127 + 0x2C);
            tbl = (f32 *) D_0063F888;
            sp1B0 = func_002b2970(700.0f + tbl[0], sp650.y);
            sp1A8 = func_002b2970(tbl[0], sp650.y);
            func_002e0620((*(void * *)(work + 0xDCC)), *(u64 *)&sp1B0, *(u64 *)&sp1A8, 1, 3, 2);
            temp_2_128 = func_002e04e0((*(void * *)(work + 0xDD0)));
            sp150 = *(Vec2f *)((u8 *)temp_2_128 + 0x2C);
            tbl = (f32 *) D_0063F890;
            sp1A0 = func_002b2970(700.0f + tbl[0], sp150.y);
            sp198 = func_002b2970(tbl[0], sp150.y);
            func_002e0620((*(void * *)(work + 0xDD0)), *(u64 *)&sp1A0, *(u64 *)&sp198, 1, 3, 2);
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x32:                                      /* switch 1 */
        (*(s8 *)(work + 0)) = 0x24;
        break;
    case 0x33:                                      /* switch 1 */
        if (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) > 5) {
            temp_16_90 = (*(s8 *)(work + 0x11));
            if (func_002e26f0((((void**)(work + 0xF18))[temp_16_90])) > D_00748908[temp_16_90]) {
                if (func_002e26f0((((void**)(work + 0xF18))[temp_16_90])) > 5) {
                    (*(f32 *)(work + 0xC)) = (f32) (104.0f / (f32) (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) - 5));
                }
                sp190 = func_002b2970((f32) 0x221,  142.0f + (*(f32 *)(work + 0xC)) * (f32) ((*(s16 *)(work + 2)) - (*(s16 *)(work + 4))));
                temp_16_91 = func_002b2a30(0xFFU, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36, sp190, 138.0f, temp_16_91, (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC8C)))) + 0x62)), 0, D_00794EA0);
            }
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 0);
        } else {
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)(work + 0x116E)), 80.0f, (f32) 0x352);
        func_002d8a60(arg0, (*(s8 *)(work + 0x11)), (f32) -0x352, 80.0f);
        temp_2_129 = func_002b2d00((s32) (*(s16 *)(work + 0x1170)), 1, 0, 0, 1);
        (*(s16 *)(work + 0x1170)) = temp_2_129;
        if (((s16) ((s64) temp_2_129)) == 0) {
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x34:                                      /* switch 1 */
        if (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) > 5) {
            temp_16_92 = (*(s8 *)(work + 0x11));
            if (func_002e26f0((((void**)(work + 0xF18))[temp_16_92])) > D_00748908[temp_16_92]) {
                if (func_002e26f0((((void**)(work + 0xF18))[temp_16_92])) > 5) {
                    (*(f32 *)(work + 0xC)) = (f32) (104.0f / (f32) (func_002e26f0((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) - 5));
                }
                sp188 = func_002b2970((f32) 0x221,  142.0f + (*(f32 *)(work + 0xC)) * (f32) ((*(s16 *)(work + 2)) - (*(s16 *)(work + 4))));
                temp_16_93 = func_002b2a30(0xFFU, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36, sp188, 138.0f, temp_16_93, (*(u8 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC8C)))) + 0x62)), 0, D_00794EA0);
            }
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 0);
        } else {
            func_002e04f0((*(void * *)(work + 0xC8C)), 0, 1);
            func_002e04f0((*(void * *)(work + 0xC90)), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)(work + 0x116E)), 80.0f, (f32) -0x352);
        func_002d8a60(arg0, (*(s8 *)(work + 0x11)), (f32) 0x352, 80.0f);
        temp_2_130 = func_002b2d00((s32) (*(s16 *)(work + 0x1170)), 1, 0, 0, 1);
        (*(s16 *)(work + 0x1170)) = temp_2_130;
        if (((s16) ((s64) temp_2_130)) == 0) {
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x35:                                      /* switch 1 */
        if (func_00452380(D_0063FB10) == 0) {
            for (var_16_23 = 0; var_16_23 < 7; var_16_23++) {
                func_002e04f0((*(void * *)((u8 *)((work + (var_16_23 * 4))) + 0xD20)), 0, 0);
            }
            func_002e04f0((*(void * *)(work + 0xC44)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xC48)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xDEC)), 0, 0);
            for (var_16_24 = 0; var_16_24 < 3; var_16_24++) {
                func_002e0660((*(void * *)((u8 *)((work + (var_16_24 * 4))) + 0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
            }
            func_002e0660((*(void * *)(work + 0xD8C)), 0U, 0xFFU, 0U, 0xA, 0);
            func_002e0660((*(void * *)(work + 0xD90)), 0U, 0xFFU, 0U, 0xA, 0);
            func_002e0660((*(void * *)(work + 0xD94)), 0U, 0xFFU, 0U, 0xA, 0);
            func_002e09e0((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_131 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 5);
            temp_18_60 = (s16) ((func_0046b260(temp_2_131)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) temp_18_60;
            temp_18_61 = (s16) ((func_0046b2f0(temp_2_131)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) temp_18_61;
            func_0046d280(temp_2_131);
            func_002e0660((*(void * *)(work + 0xC4C)), 0U, 0xCCU, 0U, 4, 4);
            func_002e0940((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
            sp180 = func_002b2970(-240.0f, 400.0f);
            sp178 = func_002b2970(-240.0f, 310.0f);
            func_002e0620((*(void * *)(work + 0xC4C)), *(u64 *)&sp180, *(u64 *)&sp178, 0, 4, 4);
            func_002e09e0((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
            (*(f32 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
            temp_2_132 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_18_62 = (s16) ((func_0046b260(temp_2_132)));
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) temp_18_62;
            (*(s16 *)((u8 *)(func_002e04e0((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
            func_002e0940((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 4);
            func_002e0660((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 4);
            func_0046d280(temp_2_132);
            func_002e09e0((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
            temp_2_133 = func_0046d200((void *) (*(s32 *)(work + 0xF28)), 6);
            temp_16_94 = (s16) ((func_0046b260(temp_2_133)));
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) temp_16_94;
            (*(s16 *)((u8 *)(func_002e04e0((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
            func_0046d280(temp_2_133);
            func_002e0940((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
            func_002e0660((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
            for (var_21_4 = 0; var_21_4 < 7; var_21_4++) {
                temp_18_63 = (f32 *)(D_0063F560 + ((var_21_4 + 0x3A) * 8));
                func_002e09e0((*(void * *)(work + (var_21_4 * 4) + 0xD20)), 0x56, (f32) (var_21_4 + 0x64));
                if (var_21_4 > 0) {
                    sp6AC = func_002b2a60(0xED, 0x80, 0, 0xFF);
                    temp_2_134 = func_002e04e0((*(void * *)(work + (var_21_4 * 4) + 0xD20)));
                    *(FclDrawColor *)((u8 *)temp_2_134 + 0x79) = sp6AC;
                }
                sp170 = func_002b2970(80.0f + temp_18_63[0], temp_18_63[1]);
                sp168 = func_002b2970(temp_18_63[0], temp_18_63[1]);
                func_002e0620((*(void * *)(work + ((var_21_4) * 4) + 0xD20)), *(u64 *)&sp170, *(u64 *)&sp168, 0, 3, var_21_4);
                func_002e0660((*(void * *)(work + ((var_21_4) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_21_4);
            }
            sp6A8 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            temp_2_136 = func_002e04e0((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))]));
            *(FclDrawColor *)((u8 *)temp_2_136 + 0x79) = sp6A8;
            func_002e0660((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
            func_002e0660((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
            func_002d7f90(arg0);
            func_002dd230(arg0);
            func_002e04f0((*(void * *)(work + 0xDE8)), 0, 0);
            func_002e04f0((*(void * *)(work + 0xDEC)), 0, 0);
            (*(s8 *)(work + 0)) = 0x36;
        }
        break;
    case 0x36:                                      /* switch 1 */
        for (var_16_25 = 0x55; var_16_25 < 0x58; var_16_25++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_25 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_25 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_26 = 0x59; var_16_26 < 0x60; var_16_26++) {
            if (((s8) (func_002e0570((*(void * *)(work + (var_16_26 * 4) + 0xC38)), 1))) == 0) {
                func_002e04f0((*(void * *)(work + (var_16_26 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (func_002e0570((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xD94)), 1))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xC4C)), 2))) == 0) && (((s8) (func_002e0570((*(void * *)(work + 0xC50)), 2))) == 0)) {
            (*(s8 *)(work + 0)) = 0x10;
        }
        break;
    case 0x37:                                      /* switch 1 */
        if ((((s8) (func_002e05a0((*(void * *)(work + 0xC4C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC50))))) == 0) && (((s8) (func_002e05a0((void *) (*(s32 *)(work + 0xE7C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC38))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC3C))))) == 0) && (((s8) (func_002e05a0((*(void * *)(work + 0xC40))))) == 0)) {
            return -1;
        }
        break;
    }
    return 0;
}

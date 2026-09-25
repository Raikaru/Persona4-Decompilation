/* Research only; production func_002be530 (src/Event/Fcl/y_fclShopDraw.c) remains ASM.
 * Measured 2026-09-25 with tools/fnalign.py --candidate: retail 12429 instrs,
 * this body 8565 instrs, 14608 edits (+16 reloc-only). Derived from the
 * guarded NON_MATCHING draft in the source (12378 instrs, 20381 edits) by
 * dropping every (u8) cast on func_002b2970 float arguments (120 lines) and
 * indexing D_0063F888/D_0063F890 with [0]. See ShopDraw_002be530_20260925.md. */
#pragma opt_common_subs off
s32 func_002be530(u8 *arg0)
{
    extern u8 D_0063FAA0[];
    extern u8 D_0063FAD0[];
    extern u8 D_00795FE0[];
    extern u8 D_00713908[];
    extern u8 D_00713910[];
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
    extern void func_00460ac0(void *, void *);
    extern s32 func_0046aea0(void *);
    extern void func_00440b68(const void *, const void *, s32);
    extern void *func_00454a60(const void *, s32);
    extern s32 H_Cdvd_IsFileLoaded(void *);
    extern s32 datGetFlag(s32);
    extern void func_00106390(s32, s32);
    extern void func_00106620(s16, s32);
    extern u32 func_00106850(s32);
    extern s32 func_00106b50(s16);
    extern void func_00106d40(s16, s16, s16);
    extern void func_00110810(s32, u8);
    extern s64 func_00110a60(s32, s32);
    extern s32 func_002b32a0(s32, s32, s32, s32);
    extern s32 func_002bae80(s64, s32);
    extern s8 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002be160(s32, s32);
    extern void func_002e24a0(s32, s32, s32, s32);
    extern s16 func_002e28f0(void *, s32);
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
    extern s32 func_002dfec0(void *arg0, s32 arg1, void *arg2, s8 arg3);
    extern s32 func_002dff90(void *arg0, s32 arg1, void *arg2, void *arg3, s8 arg4);
    extern void func_002e0080(void *arg0, s8 arg1, Vec2f arg2, void *arg3);
extern s32 func_002e0100(u8 *task);
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
    extern void func_002d8200(void *arg0, s8 arg1);
    extern void func_002d83c0(void *arg0);
    extern void func_002d8600(void *arg0);
    extern void func_002da0a0(register u8 *root);
    extern void func_002db400(void *arg0);
    extern void func_002dd230(void *arg0);
    extern void func_002de5a0(void *arg0);
    extern void func_002df020(void *arg0, s64 arg1, s32 arg2);
    extern void func_002df4c0(void *arg0);
    extern s32 func_002e0300(s32 arg0, s16 arg1, u32 arg2);
    extern void func_002cacd0(u64 arg0, f32 fparg0, RGBA arg1, s32 arg2, s16 arg3, u32 arg4_, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
extern void func_002ca770(u8 *task);


    s32 s0;
    s32 sp6A9;
    s32 sp6AA;
    s32 sp6AB;
    s32 sp6AD;
    s32 sp6AE;
    s32 sp6AF;
    s32 sp6B1;
    s32 sp6B2;
    s32 sp6B3;
    s32 sp6B5;
    s32 sp6B6;
    s32 sp6B7;
    s32 sp6B9;
    s32 sp6BA;
    s32 sp6BB;
    s32 sp6BD;
    s32 sp6BE;
    s32 sp6BF;
    s32 sp6C1;
    s32 sp6C2;
    s32 sp6C3;
    s32 sp6C5;
    s32 sp6C6;
    s32 sp6C7;
    s32 sp6C9;
    s32 sp6CA;
    s32 sp6CB;
    s32 sp6CD;
    s32 sp6CE;
    s32 sp6CF;
    s32 sp6D1;
    s32 sp6D2;
    s32 sp6D3;
    s32 sp6D5;
    s32 sp6D6;
    s32 sp6D7;
    s32 sp6D9;
    s32 sp6DA;
    s32 sp6DB;
    s32 sp6DD;
    s32 sp6DE;
    s32 sp6DF;
    s32 sp6E1;
    s32 sp6E2;
    s32 sp6E3;
    s32 sp6E5;
    s32 sp6E6;
    s32 sp6E7;
    s32 sp6E9;
    s32 sp6EA;
    s32 sp6EB;
    s32 sp6ED;
    s32 sp6EE;
    s32 sp6EF;
    s32 sp6F1;
    s32 sp6F2;
    s32 sp6F3;
    s32 sp6F5;
    s32 sp6F6;
    s32 sp6F7;
    s32 sp6FD;
    s32 sp6FE;
    s32 sp6FF;
    s32 sp701;
    s32 sp702;
    s32 sp703;
    s32 sp705;
    s32 sp706;
    s32 sp707;
    s32 sp709;
    s32 sp70A;
    s32 sp70B;
    s32 sp70D;
    s32 sp70E;
    s32 sp70F;
    s32 sp729;
    s32 sp72A;
    s32 sp72B;
    s32 sp72D;
    s32 sp72E;
    s32 sp72F;
    s32 sp731;
    s32 sp732;
    s32 sp733;
    s32 sp735;
    s32 sp736;
    s32 sp737;
    s32 sp739;
    s32 sp73A;
    s32 sp73B;
    s32 sp73D;
    s32 sp73E;
    s32 sp73F;
    s32 sp741;
    s32 sp742;
    s32 sp743;
    s32 sp745;
    s32 sp746;
    s32 sp747;
    s32 sp749;
    s32 sp74A;
    s32 sp74B;
    s32 sp74D;
    s32 sp74E;
    s32 sp74F;
    s32 sp751;
    s32 sp752;
    s32 sp753;
    s32 sp755;
    s32 sp756;
    s32 sp757;
    s32 sp759;
    s32 sp75A;
    s32 sp75B;
    s32 sp75D;
    s32 sp75E;
    s32 sp75F;
    s32 sp761;
    s32 sp762;
    s32 sp763;
    s32 sp765;
    s32 sp766;
    s32 sp767;
    s32 sp769;
    s32 sp76A;
    s32 sp76B;
    s32 sp76D;
    s32 sp76E;
    s32 sp76F;
    s32 sp771;
    s32 sp772;
    s32 sp773;
    s32 sp775;
    s32 sp776;
    s32 sp777;
    s32 sp779;
    s32 sp77A;
    s32 sp77B;
    s32 sp77D;
    s32 sp77E;
    s32 sp77F;
    s32 sp781;
    s32 sp782;
    s32 sp783;
    s32 sp785;
    s32 sp786;
    s32 sp787;
    s32 sp789;
    s32 sp78A;
    s32 sp78B;
    s32 sp78D;
    s32 sp78E;
    s32 sp78F;
    s32 unksp1BC;
    s32 unksp1C4;
    s32 unksp1CC;
    s32 unksp1D4;
    s32 unksp1DC;
    s32 unksp1E4;
    s32 unksp1EC;
    u8 sp78C;
    u8 sp788;
    u8 sp784;
    u8 sp780;
    u8 sp77C;
    u8 sp778;
    u8 sp774;
    u8 sp770;
    u8 sp76C;
    u8 sp768;
    u8 sp764;
    u8 sp760;
    u8 sp75C;
    u8 sp758;
    u8 sp754;
    u8 sp750;
    u8 sp74C;
    u8 sp748;
    u8 sp744;
    u8 sp740;
    u8 sp73C;
    u8 sp738;
    u8 sp734;
    u8 sp730;
    u8 sp72C;
    u8 sp728;
    u8 sp724;
    u8 sp720;
    u8 sp71C;
    u8 sp718;
    u8 sp714;
    u8 sp710;
    u8 sp70C;
    u8 sp708;
    u8 sp704;
    u8 sp700;
    u8 sp6FC;
    u8 sp6F8;
    u8 sp6F4;
    u8 sp6F0;
    u8 sp6EC;
    u8 sp6E8;
    u8 sp6E4;
    u8 sp6E0;
    u8 sp6DC;
    u8 sp6D8;
    u8 sp6D4;
    u8 sp6D0;
    u8 sp6CC;
    u8 sp6C8;
    u8 sp6C4;
    u8 sp6C0;
    u8 sp6BC;
    u8 sp6B8;
    u8 sp6B4;
    u8 sp6B0;
    u8 sp6AC;
    u8 sp6A8;
    s32 sp6A4;
    s32 sp6A0;
    s32 sp69C;
    s32 sp698;
    s32 sp694;
    s32 sp690;
    s32 sp68C;
    s32 sp688;
    s32 sp684;
    s32 sp680;
    s32 sp67C;
    s32 sp678;
    s32 sp674;
    s32 sp670;
    s32 sp66C;
    s32 sp668;
    f32 sp664;
    f32 sp660;
    f32 sp65C;
    f32 sp658;
    f32 sp654;
    f32 sp650;
    s64 sp648;
    s64 sp640;
    s64 sp638;
    s64 sp630;
    s64 sp628;
    s64 sp620;
    s64 sp618;
    s64 sp610;
    s64 sp608;
    s64 sp600;
    s64 sp5F8;
    s64 sp5F0;
    s64 sp5E8;
    s64 sp5E0;
    s64 sp5D8;
    s64 sp5D0;
    s64 sp5C8;
    s64 sp5C0;
    s64 sp5B8;
    s64 sp5B0;
    s64 sp5A8;
    s64 sp5A0;
    s64 sp598;
    s64 sp590;
    s64 sp588;
    s64 sp580;
    s64 sp578;
    s64 sp570;
    s64 sp568;
    s64 sp560;
    s64 sp558;
    s64 sp550;
    s64 sp548;
    s64 sp540;
    s64 sp538;
    s64 sp530;
    s64 sp528;
    s64 sp520;
    s64 sp518;
    s64 sp510;
    s64 sp508;
    s64 sp500;
    s64 sp4F8;
    s64 sp4F0;
    s64 sp4E8;
    s64 sp4E0;
    s64 sp4D8;
    s64 sp4D0;
    s64 sp4C8;
    s64 sp4C0;
    s64 sp4B8;
    s64 sp4B0;
    s64 sp4A8;
    s64 sp4A0;
    s64 sp498;
    s64 sp490;
    s64 sp488;
    s64 sp480;
    s64 sp478;
    s64 sp470;
    s64 sp468;
    s64 sp460;
    s64 sp458;
    s64 sp450;
    s64 sp448;
    s64 sp440;
    s64 sp438;
    s64 sp430;
    s64 sp428;
    s64 sp420;
    s64 sp418;
    s64 sp410;
    s64 sp408;
    s64 sp400;
    s64 sp3F8;
    s64 sp3F0;
    s64 sp3E8;
    s64 sp3E0;
    s64 sp3D8;
    s64 sp3D0;
    s64 sp3C8;
    s64 sp3C0;
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
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    s32 spD0;
    s32 spC0;
    f32 *temp_16_12;
    f32 *temp_16_7;
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
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
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
    s16 temp_16_58;
    s16 temp_16_60;
    s16 temp_18_52;
    s16 temp_18_53;
    s16 temp_18_57;
    s16 temp_23_2;
    s16 temp_2_129;
    s16 temp_2_130;
    s16 temp_2_76;
    s16 temp_2_77;
    s16 temp_2_98;
    s16 temp_30;
    s16 temp_4_10;
    s16 temp_4_15;
    s16 temp_4_16;
    s16 temp_4_3;
    s16 temp_4_6;
    s16 temp_4_7;
    s16 temp_4_8;
    s16 temp_4_9;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_66;
    s32 temp_16_67;
    s32 temp_16_68;
    s32 temp_16_69;
    s32 temp_16_70;
    s32 temp_16_71;
    s32 temp_16_72;
    s32 temp_16_73;
    s32 temp_16_85;
    s32 temp_16_91;
    s32 temp_16_93;
    s32 temp_18_11;
    s32 temp_18_48;
    s32 temp_18_51;
    s32 temp_18_55;
    s32 temp_18_56;
    s32 temp_21_3;
    s32 temp_21_4;
    s32 temp_2_131;
    s32 temp_2_132;
    s32 temp_2_133;
    s32 temp_2_13;
    s32 temp_2_15;
    s32 temp_2_17;
    s32 temp_2_19;
    s32 temp_2_22;
    s32 temp_2_30;
    s32 temp_2_31;
    s32 temp_2_32;
    s32 temp_2_39;
    s32 temp_2_3;
    s32 temp_2_40;
    s32 temp_2_41;
    s32 temp_2_46;
    s32 temp_2_47;
    s32 temp_2_48;
    s32 temp_2_4;
    s32 temp_4_12;
    s32 temp_4_5;
    s32 var_21_2;
    s32 var_22;
    s64 temp_16_29;
    s64 temp_16_39;
    s64 temp_16_43;
    s32 temp_16_44;
    s64 temp_16_46;
    s64 temp_16_47;
    s64 temp_16_49;
    s64 temp_16_4;
    s64 temp_16_51;
    s64 temp_16_52;
    s64 temp_16_53;
    s64 temp_16_55;
    s64 temp_16_56;
    s64 temp_16_57;
    s64 temp_16_59;
    s64 temp_16_5;
    s64 temp_16_62;
    s64 temp_16_65;
    s64 temp_16_6;
    s64 temp_16_74;
    s64 temp_16_75;
    s64 temp_16_76;
    s64 temp_16_78;
    s64 temp_16_79;
    s64 temp_16_81;
    s64 temp_16_82;
    s64 temp_16_86;
    s64 temp_16_87;
    s64 temp_16_94;
    s64 temp_18;
    s64 temp_18_10;
    s64 temp_18_12;
    s64 temp_18_13;
    s64 temp_18_14;
    s64 temp_18_15;
    s64 temp_18_16;
    s64 temp_18_17;
    s64 temp_18_18;
    s64 temp_18_19;
    s64 temp_18_21;
    s64 temp_18_22;
    s64 temp_18_25;
    s64 temp_18_26;
    s64 temp_18_27;
    s64 temp_18_28;
    s64 temp_18_2;
    s64 temp_18_30;
    s64 temp_18_31;
    s64 temp_18_32;
    s64 temp_18_33;
    s64 temp_18_34;
    s64 temp_18_35;
    s64 temp_18_36;
    s64 temp_18_38;
    s64 temp_18_3;
    s64 temp_18_40;
    s32 temp_18_41;
    s64 temp_18_54;
    s64 temp_18_5;
    s64 temp_18_60;
    s64 temp_18_61;
    s64 temp_18_62;
    s64 temp_18_6;
    s64 temp_18_7;
    s64 temp_18_8;
    s64 temp_18_9;
    s64 temp_19;
    s64 temp_19_11;
    s64 temp_19_2;
    s64 temp_19_5;
    s64 temp_19_7;
    s64 temp_19_8;
    s64 temp_20;
    s64 temp_21_5;
    s64 temp_2_85;
    s64 temp_3_10;
    s64 temp_3_11;
    s64 temp_3_13;
    s64 temp_3_14;
    s64 temp_3_21;
    s64 temp_3_22;
    s64 temp_3_24;
    s64 temp_3_25;
    s64 temp_3_2;
    s64 temp_3_4;
    s64 temp_3_5;
    s64 temp_3_6;
    s64 temp_3_7;
    s64 temp_3_8;
    s64 temp_3_9;
    s64 temp_4;
    s64 temp_4_11;
    s64 temp_4_13;
    s64 temp_4_14;
    s64 temp_4_2;
    s64 temp_4_4;
    s64 var_16;
    s64 var_16_10;
    s64 var_16_11;
    s32 var_16_12;
    s32 var_16_13;
    s32 var_16_14;
    s32 var_16_15;
    s32 var_16_16;
    s32 var_16_17;
    s32 var_16_18;
    s32 var_16_19;
    s32 var_16_20;
    s32 var_16_21;
    s32 var_16_22;
    s32 var_16_23;
    s32 var_16_24;
    s32 var_16_25;
    s32 var_16_26;
    s64 var_16_2;
    s64 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_16_7;
    s32 var_16_8;
    s32 var_16_9;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_18_5;
    s32 var_18_6;
    s32 var_19;
    s32 var_19_2;
    s32 var_19_3;
    s32 var_19_5;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_21;
    s32 var_21_3;
    s32 var_21_4;
    s32 var_5;
    s8 temp_16_83;
    s8 temp_16_90;
    s8 temp_16_92;
    s8 temp_19_3;
    s8 temp_22_2;
    s8 temp_2_2;
    s8 temp_2_44;
    s8 temp_2_5;
    s8 temp_2_65;
    s8 temp_2_78;
    s8 temp_2_79;
    s8 temp_2_97;
    s8 temp_3_18;
    s8 temp_3_19;
    s8 temp_5;
    s8 var_19_4;
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
    u32 temp_16_50;
    u32 temp_16_54;
    u32 temp_16_61;
    u32 temp_16_63;
    u32 temp_16_77;
    u32 temp_16_80;
    u32 temp_16_84;
    u32 temp_17_2;
    u32 temp_18_42;
    u32 temp_18_44;
    u32 temp_18_45;
    u32 temp_18_46;
    u32 temp_18_47;
    u32 temp_18_49;
    u32 temp_19_4;
    u32 temp_21_2;
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
    u8 temp_5_3;
    u8 temp_5_4;
    u8 temp_5_5;
    u8 temp_5_6;
    u8 temp_5_7;
    u8 temp_5_8;
    u8 temp_5_9;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_6_3;
    u8 temp_6_4;
    u8 temp_6_5;
    u8 temp_6_6;
    u8 temp_6_7;
    u8 temp_6_8;
    u8 var_3_4;
    u8 var_3_5;
    u8 *temp_16_10;
    u8 *temp_16_11;
    u8 *temp_16_13;
    u8 *temp_16_14;
    u8 *temp_16_15;
    u8 *temp_16_16;
    u8 *temp_16_17;
    u8 *temp_16_18;
    u8 *temp_16_19;
    u8 *temp_16_20;
    u8 *temp_16_21;
    u8 *temp_16_22;
    u8 *temp_16_23;
    u8 *temp_16_24;
    u8 *temp_16_25;
    u8 *temp_16_26;
    u8 *temp_16_27;
    u8 *temp_16_28;
    u8 *temp_16_30;
    u8 *temp_16_31;
    u8 *temp_16_32;
    u8 *temp_16_33;
    u8 *temp_16_34;
    u8 *temp_16_35;
    u8 *temp_16_36;
    u8 *temp_16_37;
    u8 *temp_16_38;
    u8 *temp_16_3;
    u8 *temp_16_40;
    u8 *temp_16_41;
    u8 *temp_16_42;
    u8 *temp_16_45;
    u8 *temp_16_48;
    u8 *temp_16_64;
    u8 *temp_16_88;
    u8 *temp_16_89;
    u8 *temp_16_8;
    u8 *temp_16_9;
    u8 *temp_17;
    u8 *temp_18_20;
    u8 *temp_18_23;
    u8 *temp_18_24;
    u8 *temp_18_29;
    u8 *temp_18_37;
    u8 *temp_18_39;
    u8 *temp_18_43;
    u8 *temp_18_4;
    u8 *temp_18_50;
    u8 *temp_18_58;
    u8 *temp_18_59;
    u8 *temp_18_63;
    u8 *temp_19_10;
    u8 *temp_19_6;
    u8 *temp_19_9;
    u8 *temp_21;
    u8 *temp_22;
    u8 *temp_23;
    u8 *temp_2;
    u8 *temp_2_102;
    u8 *temp_2_103;
    u8 *temp_2_104;
    u8 *temp_2_105;
    u8 *temp_2_109;
    u8 *temp_2_10;
    u8 *temp_2_110;
    u8 *temp_2_111;
    u8 *temp_2_112;
    u8 *temp_2_113;
    u8 *temp_2_114;
    u8 *temp_2_115;
    u8 *temp_2_116;
    u8 *temp_2_117;
    u8 *temp_2_118;
    u8 *temp_2_119;
    u8 *temp_2_11;
    u8 *temp_2_120;
    u8 *temp_2_121;
    u8 *temp_2_122;
    u8 *temp_2_123;
    u8 *temp_2_124;
    u8 *temp_2_125;
    u8 *temp_2_126;
    u8 *temp_2_127;
    u8 *temp_2_128;
    u8 *temp_2_12;
    u8 *temp_2_134;
    u8 *temp_2_135;
    u8 *temp_2_136;
    u8 *temp_2_137;
    u8 *temp_2_138;
    u8 *temp_2_14;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_27;
    u8 *temp_2_28;
    u8 *temp_2_29;
    u8 *temp_2_33;
    u8 *temp_2_34;
    u8 *temp_2_38;
    u8 *temp_2_42;
    u8 *temp_2_43;
    u8 *temp_2_45;
    u8 *temp_2_49;
    u8 *temp_2_50;
    u8 *temp_2_51;
    u8 *temp_2_52;
    u8 *temp_2_56;
    u8 *temp_2_57;
    u8 *temp_2_58;
    u8 *temp_2_59;
    u8 *temp_2_60;
    u8 *temp_2_61;
    u8 *temp_2_62;
    u8 *temp_2_63;
    u8 *temp_2_64;
    u8 *temp_2_69;
    u8 *temp_2_6;
    u8 *temp_2_70;
    u8 *temp_2_71;
    u8 *temp_2_72;
    u8 *temp_2_73;
    u8 *temp_2_74;
    u8 *temp_2_75;
    u8 *temp_2_7;
    u8 *temp_2_83;
    u8 *temp_2_84;
    u8 *temp_2_86;
    u8 *temp_2_87;
    u8 *temp_2_88;
    u8 *temp_2_89;
    u8 *temp_2_8;
    u8 *temp_2_90;
    u8 *temp_2_91;
    u8 *temp_2_92;
    u8 *temp_2_93;
    u8 *temp_2_94;
    u8 *temp_2_95;
    u8 *temp_2_96;
    u8 *temp_2_9;
    u8 *temp_3;
    u8 *temp_3_12;
    u8 *temp_3_15;
    u8 *temp_3_16;
    u8 *temp_3_17;
    u8 *temp_3_20;
    u8 *temp_3_23;
    u8 *temp_3_3;

    temp_17 = (u8 *)((*(u8 **)((u8 *)(arg0) + (0x38))));
    var_19 = 0;
    temp_2 = (u8 *)(func_00460990());
    (*(void (**)())((u8 *)(temp_2) + (8))) = (void (*)())((void (**)())(func_002be4a0));
    (*(u8 **)((u8 *)(temp_2) + (0x10))) = (u8 *)(temp_17);
    func_00460ac0(&D_00795FE0, temp_2);
    temp_2_2 = (s8)((*(s8 *)((u8 *)(temp_17) + (0))));
    switch (temp_2_2) {                             /* switch 1 */
    case 0x9:                                       /* switch 1 */
        (*(s32 *)((u8 *)(temp_17) + (0xF28))) = func_0046aea0(&D_0063FAA0);
        func_00440b68(D_00713908, &D_0063FAC0, 0x147);
        (*(u8 **)((u8 *)(temp_17) + (0xF2C))) = (u8 *)(func_00454a60(&D_0063FAD0, 0));
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0xA;
        /* fallthrough */
    case 0xA:                                       /* switch 1 */
        if ((func_0046a750((*(s32 *)((u8 *)(temp_17) + (0xF28)))) != 0) && (H_Cdvd_IsFileLoaded((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) != 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xB;
            (*(s8 *)((u8 *)(temp_17) + (0xF30))) = 1;
            var_16 = 0;
loop_7:
            temp_18 = (s64) (var_16 << 0x30) >> 0x30;
            if (temp_18 < 0x91) {
                (*(s32 *)((u8 *)((temp_17 + (temp_18 * 4))) + (0xC38))) = func_002e0300((s32)arg0, var_16, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16 = (s64) ((var_16 + 1) << 0x30) >> 0x30;
                goto loop_7;
            }
            (*(s32 *)((u8 *)(temp_17) + (0xE7C))) = func_002e0300((s32)arg0, 6, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xE80))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xE84))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            var_16_2 = 0;
loop_10:
            if (((s64) (var_16_2 << 0x30) >> 0x30) < 3) {
                temp_18_2 = (s64) (var_16_2 << 0x30) >> 0x30;
                (*(s32 *)((u8 *)((temp_17 + (temp_18_2 * 4))) + (0xE88))) = func_002e0300((s32)arg0, (s64) ((temp_18_2 + 0x61) << 0x30) >> 0x30, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16_2 = (s64) ((var_16_2 + 1) << 0x30) >> 0x30;
                goto loop_10;
            }
            var_16_3 = 0;
loop_13:
            if (((s64) (var_16_3 << 0x30) >> 0x30) < 4) {
                temp_18_3 = (s64) (var_16_3 << 0x30) >> 0x30;
                (*(s32 *)((u8 *)((temp_17 + (temp_18_3 * 4))) + (0xE94))) = func_002e0300((s32)arg0, (s64) ((temp_18_3 + 0x19) << 0x30) >> 0x30, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
                var_16_3 = (s64) ((var_16_3 + 1) << 0x30) >> 0x30;
                goto loop_13;
            }
            (*(s32 *)((u8 *)(temp_17) + (0xEA4))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEA8))) = func_002e0300((s32)arg0, 0x1D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEAC))) = func_002e0300((s32)arg0, 0x20, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB0))) = func_002e0300((s32)arg0, 0x21, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEB8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEBC))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC0))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEC8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED4))) = func_002e0300((s32)arg0, 3, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED8))) = func_002e0300((s32)arg0, 4, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xECC))) = func_002e0300((s32)arg0, 5, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEDC))) = func_002e0300((s32)arg0, 0x2B, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE0))) = func_002e0300((s32)arg0, 0x2C, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xED0))) = func_002e0300((s32)arg0, 0x5F, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF14))) = func_002e0300((s32)arg0, 0x5F, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE4))) = func_002e0300((s32)arg0, 0x65, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEE8))) = func_002e0300((s32)arg0, 0x66, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEEC))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF0))) = func_002e0300((s32)arg0, 0xA, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF4))) = func_002e0300((s32)arg0, 0x12, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEF8))) = func_002e0300((s32)arg0, 0xE, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xEFC))) = func_002e0300((s32)arg0, 0x13, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF00))) = func_002e0300((s32)arg0, 0xF, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF04))) = func_002e0300((s32)arg0, 0x10, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF08))) = func_002e0300((s32)arg0, 0x8C, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF0C))) = func_002e0300((s32)arg0, 0x8D, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            (*(s32 *)((u8 *)(temp_17) + (0xF10))) = func_002e0300((s32)arg0, 0x8E, (*(s32 *)((u8 *)(temp_17) + (0xF28))));
            temp_2_3 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x48));
            temp_f21 = 632.0f + func_0046b260((void *)(temp_2_3));
            func_0046d280((void *)(temp_2_3));
            temp_2_4 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x47));
            temp_f20 = 136.0f + func_0046b2f0((void *)(temp_2_4));
            func_0046d280((void *)(temp_2_4));
            temp_f1 = (f32) 0x1A3;
            (*(f32 *)((u8 *)(temp_17) + (0xF34))) = (f32) (temp_f1 + ((temp_f21 - temp_f1) / 2.0f));
            (*(f32 *)((u8 *)(temp_17) + (0xF38))) = (f32) (65.0f + ((temp_f20 - 65.0f) / 2.0f));
            (*(s8 *)((u8 *)(temp_17) + (0xF73))) = 1;
            (*(s8 *)((u8 *)(temp_17) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0(1, 0)) << 0x30) >> 0x30);
            (*(s8 *)((u8 *)(temp_17) + (9))) = 1;
            if (datGetFlag(0x30) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 2;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (datGetFlag(0x31) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 3;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (datGetFlag(0x32) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 4;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (datGetFlag(0x33) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 6;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (datGetFlag(0x35) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 8;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            if (datGetFlag(0x36) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))) = 7;
                (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF7C))) = func_002d4f30((s64) (func_00106880(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (9))) + temp_17)) + (0xF73))), 0)) << 0x30) >> 0x30);
                (*(s8 *)((u8 *)(temp_17) + (9))) = (s8) ((*(s8 *)((u8 *)(temp_17) + (9))) + 1);
            }
            var_5 = 0;
loop_28:
            if (((s64) (var_5 << 0x30) >> 0x30) < 9) {
                temp_4 = (s64) (var_5 << 0x30) >> 0x30;
                temp_3 = (u8 *)(temp_17 + (temp_4 * 2));
                (*(s16 *)((u8 *)(temp_3) + (0xF46))) = (s16) (temp_4 * 3);
                (*(s16 *)((u8 *)(temp_3) + (0xF58))) = 0;
                (*(s8 *)((u8 *)((temp_17 + temp_4)) + (0xF6A))) = 0;
                var_5 = (s64) ((var_5 + 1) << 0x30) >> 0x30;
                goto loop_28;
            }
            (*(s8 *)((u8 *)(temp_17) + (8))) = 0;
        }
    default:                                        /* switch 1 */
block_626:
        return 0;
    case 0xC:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_00106390(0x1324, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xD;
        }
        goto block_626;
    case 0xD:                                       /* switch 1 */
        if ((D_00748908[0] < func_002e26f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))))) && (datGetFlag(0x1324) == 0)) {
            temp_2_5 = (s8)(func_002bab80((*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110)))));
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = temp_2_5;
            func_002bae80((s64) ((s64) temp_2_5 << 0x38) >> 0x38, 0xB);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xC;
            return 0;
        }
        temp_16 = func_002e78a0() & 0xFF;
        if (((s64) (func_00110a60(temp_16, func_002e78e0() & 0xFF) << 0x38) >> 0x38) == 1) {
            temp_16_2 = func_002e78e0() & 0xFF;
            temp_3_2 = (s64) ((temp_16_2 + ((func_002e78a0() & 0xFF) * 0x64)) << 0x30) >> 0x30;
            if ((temp_3_2 >= 0x190) && (temp_3_2 < 0x207)) {
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xC, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
            } else {
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xD, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
            }
        } else {
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xC, (*(s32 **)((u8 *)((*(u8 **)((u8 *)(temp_17) + (0xF2C)))) + (0x110))), 0);
        }
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0xF;
        goto block_626;
    case 0xF:                                       /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0xE;
        }
        goto block_626;
    case 0xE:                                       /* switch 1 */
        (*(s8 *)((u8 *)(temp_17) + (7))) = 0;
        temp_16_3 = (u8 *)((s32)&D_0063F9F0 + (((s64) (0 << 0x38) >> 0x38) * 0xC));
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0x41, 126.0f);
        temp_f20_2 = (*(f32 *)((u8 *)(temp_16_3) + (0)));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_2;
        temp_f20_3 = (*(f32 *)((u8 *)(temp_16_3) + (4)));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_3;
        fclWriteColorBytes(&sp78C, 0xFE, 0xC6, 0x31, 0xFFU);
        temp_2_6 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
        (*(u8 *)((u8 *)(temp_2_6) + (0x79))) = sp78C;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7A))) = sp78D;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7B))) = sp78E;
        (*(u8 *)((u8 *)(temp_2_6) + (0x7C))) = sp78F;
        func_002b2970(&sp648, (*(f32 *)((u8 *)(temp_16_3) + (0))) - 80.0f, (*(f32 *)((u8 *)(temp_16_3) + (4))));
        func_002b2970(&sp640, (*(f32 *)((u8 *)(temp_16_3) + (0))), (*(f32 *)((u8 *)(temp_16_3) + (4))));
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp648, sp640, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0x41, 127.0f);
        temp_f20_4 = (*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8)));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_4;
        temp_f20_5 = (*(f32 *)((u8 *)(temp_16_3) + (4)));
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_5;
        fclWriteColorBytes(&sp788, 0xFE, 0xC6, 0x31, 0xFFU);
        temp_2_7 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
        (*(u8 *)((u8 *)(temp_2_7) + (0x79))) = sp788;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7A))) = sp789;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7B))) = sp78A;
        (*(u8 *)((u8 *)(temp_2_7) + (0x7C))) = sp78B;
        func_002b2970(&sp638, ((*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8)))) - 80.0f, (*(f32 *)((u8 *)(temp_16_3) + (4))));
        func_002b2970(&sp630, ((((*(f32 *)((u8 *)(temp_16_3) + (0))) + (*(f32 *)((u8 *)(temp_16_3) + (8)))))), (((*(f32 *)((u8 *)(temp_16_3) + (4))))));
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp638, sp630, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 3, (s64) (((*(s8 *)((u8 *)(temp_17) + (7))) + 1) << 0x30) >> 0x30);
        func_002d7f90(arg0);
        var_20 = 0;
loop_50:
        if (((s64) (var_20 << 0x30) >> 0x30) < 7) {
            temp_19 = (s64) (var_20 << 0x30) >> 0x30;
            temp_18_4 = (u8 *)((s32)&D_0063F560 + ((temp_19 + 0x3A) * 8));
            temp_3_3 = (u8 *)(temp_17 + (temp_19 * 4));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_3) + (0xD20)))), 0x56, (f32) (temp_19 + 0x64));
            if (temp_19 > 0) {
                fclWriteColorBytes(&sp784, 0xED, 0x80, 0, 0xFFU);
                temp_2_8 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_3) + (0xD20))))));
                (*(u8 *)((u8 *)(temp_2_8) + (0x79))) = sp784;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7A))) = sp785;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7B))) = sp786;
                (*(u8 *)((u8 *)(temp_2_8) + (0x7C))) = sp787;
            }
            temp_2_9 = (u8 *)(temp_17 + (((s64) (var_20 << 0x30) >> 0x30) * 4));
            func_002b2970(&sp628, (((80.0f + (*(f32 *)((u8 *)(temp_18_4) + (0)))))), (*(f32 *)((u8 *)(temp_18_4) + (4))));
            func_002b2970(&sp620, (((*(f32 *)((u8 *)(temp_18_4) + (0))))), (*(f32 *)((u8 *)(temp_18_4) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_9) + (0xD20)))), sp628, sp620, 0, 3, var_20);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_9) + (0xD20)))), 0U, 0xFF, 0, 3, var_20);
            var_20 = (s64) ((var_20 + 1) << 0x30) >> 0x30;
            goto loop_50;
        }
        fclWriteColorBytes(&sp780, 0x2D, 0x2D, 0x2D, 0xFFU);
        temp_2_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
        (*(u8 *)((u8 *)(temp_2_10) + (0x79))) = sp780;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7A))) = sp781;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7B))) = sp782;
        (*(u8 *)((u8 *)(temp_2_10) + (0x7C))) = sp783;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C)))), 0x41, ((f32)(sp780)));
        fclWriteColorBytes(&sp77C, 0x5A, 0, 2, 0xFFU);
        temp_2_11 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C))))));
        (*(u8 *)((u8 *)(temp_2_11) + (0x79))) = sp77C;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7A))) = sp77D;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7B))) = sp77E;
        (*(u8 *)((u8 *)(temp_2_11) + (0x7C))) = sp77F;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC38)))), 0x56, ((f32)(sp77C)));
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))), 0x56, 183.0f);
        fclWriteColorBytes(&sp778, 0xFE, 0xBE, 0x1E, 0xFFU);
        temp_2_12 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40))))));
        (*(u8 *)((u8 *)(temp_2_12) + (0x79))) = sp778;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7A))) = sp779;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7B))) = sp77A;
        (*(u8 *)((u8 *)(temp_2_12) + (0x7C))) = sp77B;
        temp_2_13 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 2));
        temp_18_5 = (s64) (((s64)((func_0046b260((void *)(temp_2_13)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))))) + (0x100))) = (s16) temp_18_5;
        temp_18_6 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_13)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))))) + (0x102))) = (s16) temp_18_6;
        func_0046d280((void *)(temp_2_13));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40)))), 0, 0, 0, -90.0f, -90.0f);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
        fclWriteColorBytes(&sp774, 0, 0, 0, 0xFFU);
        temp_2_14 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
        (*(u8 *)((u8 *)(temp_2_14) + (0x79))) = sp774;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7A))) = sp775;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7B))) = sp776;
        (*(u8 *)((u8 *)(temp_2_14) + (0x7C))) = sp777;
        temp_2_15 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
        temp_18_7 = (s64) (((s64)(func_0046b260((void *)(temp_2_15)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_7;
        temp_18_8 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_15)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_8;
        func_0046d280((void *)(temp_2_15));
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xA0, 0, 4, 4);
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
        func_002b2970(&sp618, 0xC3700000U, 0x43C80000U);
        func_002b2970(&sp610, 0xC3700000U, 0x439B0000U);
        func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp618, sp610, 0, 4, 4);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
        fclWriteColorBytes(&sp770, 0xFF, 0xBE, 0x22, 0xFFU);
        temp_2_16 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
        (*(u8 *)((u8 *)(temp_2_16) + (0x79))) = sp770;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7A))) = sp771;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7B))) = sp772;
        (*(u8 *)((u8 *)(temp_2_16) + (0x7C))) = sp773;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
        temp_2_17 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
        temp_16_4 = (s64) (((s64)(func_0046b260((void *)(temp_2_17)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_16_4;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 0, -90.0f, fGpffff8524);
        func_0046d280((void *)(temp_2_17));
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
        fclWriteColorBytes(&sp76C, 0xED, 0x81, 3, 0xFFU);
        temp_2_18 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
        (*(u8 *)((u8 *)(temp_2_18) + (0x79))) = sp76C;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7A))) = sp76D;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7B))) = sp76E;
        (*(u8 *)((u8 *)(temp_2_18) + (0x7C))) = sp76F;
        temp_2_19 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
        temp_16_5 = (s64) (((s64)(func_0046b260((void *)(temp_2_19)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_5;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
        func_0046d280((void *)(temp_2_19));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = 198.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = (f32) 0x151;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0x41, 146.0f);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0U, 0xFF, 0, 6, 0);
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x2C))) = 216.0f;
        (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x30))) = 368.0f;
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0x3F, 207.0f);
        fclWriteColorBytes(&sp768, 0xFF, 0xAE, 0, 0xFFU);
        temp_2_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C))))));
        (*(u8 *)((u8 *)(temp_2_20) + (0x79))) = sp768;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7A))) = sp769;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7B))) = sp76A;
        (*(u8 *)((u8 *)(temp_2_20) + (0x7C))) = sp76B;
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, 0x708, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 6, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0x3D, 209.0f);
        fclWriteColorBytes(&sp764, 0xE4, 0xFF, 0, 0xFFU);
        temp_2_21 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90))))));
        (*(u8 *)((u8 *)(temp_2_21) + (0x79))) = sp764;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7A))) = sp765;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7B))) = sp766;
        (*(u8 *)((u8 *)(temp_2_21) + (0x7C))) = sp767;
        temp_2_22 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x56));
        temp_18_9 = (s64) (((s64)(func_0046b260((void *)(temp_2_22)))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))))) + (0x100))) = (s16) temp_18_9;
        temp_18_10 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_22)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))))) + (0x102))) = (s16) temp_18_10;
        func_0046d280((void *)(temp_2_22));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0, 0x5A0, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 6, 0);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0U, 0xFF, 0, 0xA, 0);
        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0x3D, 210.0f);
        fclWriteColorBytes(&sp760, 0xE4, 0xFF, 0, 0xFFU);
        temp_2_23 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94))))));
        (*(u8 *)((u8 *)(temp_2_23) + (0x79))) = sp760;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7A))) = sp761;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7B))) = sp762;
        (*(u8 *)((u8 *)(temp_2_23) + (0x7C))) = sp763;
        temp_18_11 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x57));
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))))) + (0x100))) = 0;
        temp_16_6 = (s64) (((s64)((func_0046b2f0((void *)(temp_18_11)) / 2.0f))) << 0x30) >> 0x30;
        (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))))) + (0x102))) = (s16) temp_16_6;
        func_0046d280((void *)(temp_18_11));
        func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0, 0x5A0, 0, 0.0f, 360.0f);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 6, 0);
        func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0U, 0xFF, 0, 0xA, 0);
        var_16_4 = 0x59;
loop_53:
        temp_18_12 = (s64) (var_16_4 << 0x30) >> 0x30;
        if (temp_18_12 < 0x60) {
            fclWriteColorBytes(&sp75C, 0xFF, 0xAE, 0, 0xFFU);
            temp_2_24 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_12 * 4))) + (0xC38))))));
            (*(u8 *)((u8 *)(temp_2_24) + (0x79))) = sp75C;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7A))) = sp75D;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7B))) = sp75E;
            (*(u8 *)((u8 *)(temp_2_24) + (0x7C))) = sp75F;
            var_16_4 = (s64) ((var_16_4 + 1) << 0x30) >> 0x30;
            goto loop_53;
        }
        var_16_5 = 0x64;
loop_56:
        temp_18_13 = (s64) (var_16_5 << 0x30) >> 0x30;
        if (temp_18_13 < 0x67) {
            fclWriteColorBytes(&sp758, 0xFE, 0xC6, 0x31, 0xFFU);
            temp_2_25 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_13 * 4))) + (0xC38))))));
            (*(u8 *)((u8 *)(temp_2_25) + (0x79))) = sp758;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7A))) = sp759;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7B))) = sp75A;
            (*(u8 *)((u8 *)(temp_2_25) + (0x7C))) = sp75B;
            var_16_5 = (s64) ((var_16_5 + 1) << 0x30) >> 0x30;
            goto loop_56;
        }
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        (*(s16 *)((u8 *)(temp_17) + (0xC26))) = 1;
        goto block_626;
    case 0x10:                                      /* switch 1 */
        if (D_008C027A & 0x4000) {
            (*(s8 *)((u8 *)(temp_17) + (7))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (7))), 1, 5, 0, 2);
            func_002d7f90(arg0);
            temp_16_7 = (f32 *)((s32)&D_0063F9F0 + ((*(s8 *)((u8 *)(temp_17) + (7))) * 0xC));
            temp_f20_6 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (0))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_6;
            temp_f20_7 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_7;
            temp_f20_8 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (0))) + (*(f32 *)((u8 *)(temp_16_7) + (8))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_8;
            temp_f20_9 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_7) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_9;
            temp_16_8 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp608, (*(f32 *)((u8 *)(temp_16_8) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) - 4.0f))));
            temp_16_9 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp600, (*(f32 *)((u8 *)(temp_16_9) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp608, sp600, 1, 2, 0);
            temp_16_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5F8, (*(f32 *)((u8 *)(temp_16_10) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) - 4.0f))));
            temp_16_11 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5F0, (*(f32 *)((u8 *)(temp_16_11) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp5F8, sp5F0, 1, 2, 0);
            var_16_6 = 0;
loop_61:
            temp_18_14 = (s64) (var_16_6 << 0x30) >> 0x30;
            if (temp_18_14 < 6) {
                fclWriteColorBytes(&sp754, 0xED, 0x80, 0, 0xFFU);
                temp_2_26 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_14 * 4))) + (0xD24))))));
                (*(u8 *)((u8 *)(temp_2_26) + (0x79))) = sp754;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7A))) = sp755;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7B))) = sp756;
                (*(u8 *)((u8 *)(temp_2_26) + (0x7C))) = sp757;
                var_16_6 = (s64) ((var_16_6 + 1) << 0x30) >> 0x30;
                goto loop_61;
            }
            fclWriteColorBytes(&sp750, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_27 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_27) + (0x79))) = sp750;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7A))) = sp751;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7B))) = sp752;
            (*(u8 *)((u8 *)(temp_2_27) + (0x7C))) = sp753;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C027A & 0x1000) {
            (*(s8 *)((u8 *)(temp_17) + (7))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (7))), 1, 0, 5, 2);
            func_002d7f90(arg0);
            temp_16_12 = (f32 *)((s32)&D_0063F9F0 + ((*(s8 *)((u8 *)(temp_17) + (7))) * 0xC));
            temp_f20_10 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (0))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x2C))) = temp_f20_10;
            temp_f20_11 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) = temp_f20_11;
            temp_f20_12 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (0))) + (*(f32 *)((u8 *)(temp_16_12) + (8))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x2C))) = temp_f20_12;
            temp_f20_13 = (f32)(s32)((*(f32 *)((u8 *)(temp_16_12) + (4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) = temp_f20_13;
            temp_16_13 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp5E8, (*(f32 *)((u8 *)(temp_16_13) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))) - 4.0f))));
            temp_16_14 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44))))));
            func_002b2970(&sp5E0, (*(f32 *)((u8 *)(temp_16_14) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), sp5E8, sp5E0, 1, 2, 0);
            temp_16_15 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5D8, (*(f32 *)((u8 *)(temp_16_15) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))) - 4.0f))));
            temp_16_16 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48))))));
            func_002b2970(&sp5D0, (*(f32 *)((u8 *)(temp_16_16) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), sp5D8, sp5D0, 1, 2, 0);
            var_16_7 = 0;
loop_66:
            temp_18_15 = (s64) (var_16_7 << 0x30) >> 0x30;
            if (temp_18_15 < 6) {
                fclWriteColorBytes(&sp74C, 0xED, 0x80, 0, 0xFFU);
                temp_2_28 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_15 * 4))) + (0xD24))))));
                (*(u8 *)((u8 *)(temp_2_28) + (0x79))) = sp74C;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7A))) = sp74D;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7B))) = sp74E;
                (*(u8 *)((u8 *)(temp_2_28) + (0x7C))) = sp74F;
                var_16_7 = (s64) ((var_16_7 + 1) << 0x30) >> 0x30;
                goto loop_66;
            }
            fclWriteColorBytes(&sp748, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_29 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_29) + (0x79))) = sp748;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7A))) = sp749;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7B))) = sp74A;
            (*(u8 *)((u8 *)(temp_2_29) + (0x7C))) = sp74B;
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C024E & 0x40) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))))) + (0xC4))), 0.0f);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))))) + (0xC4))), 0.0f);
            var_18 = 0;
loop_71:
            if (((s64) (var_18 << 0x30) >> 0x30) < 2) {
                temp_16_17 = (u8 *)(temp_17 + (((s64) (var_18 << 0x30) >> 0x30) * 4));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF3E))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x79)));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF3F))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x7A)));
                (*(u8 *)((u8 *)(temp_16_17) + (0xF40))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_17) + (0xC44)))))) + (0x7B)));
                var_18 = (s64) ((var_18 + 1) << 0x30) >> 0x30;
                goto loop_71;
            }
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = 0;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x12;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E & 0x20) {
            var_16_8 = 0;
loop_76:
            if (((s64) (var_16_8 << 0x30) >> 0x30) < 7) {
                temp_4_2 = (s64) (var_16_8 << 0x30) >> 0x30;
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_4_2 * 4))) + (0xD20)))), 0xFFU, 0, 0, 5, (s64) ((temp_4_2 * 2) << 0x30) >> 0x30);
                var_16_8 = (s64) ((var_16_8 + 1) << 0x30) >> 0x30;
                goto loop_76;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_30 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_16 = (s64) (((s64)((func_0046b260((void *)(temp_2_30)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_16;
            temp_18_17 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_30)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_17;
            func_0046d280((void *)(temp_2_30));
            temp_16_18 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_18) + (0xC4))), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x2C))) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x30))) = 164.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = 130.0f;
            temp_2_31 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_18 = (s64) (((s64)((func_0046b260((void *)(temp_2_31)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_18;
            temp_18_19 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_31)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = (s16) temp_18_19;
            temp_18_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_18_20) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))) - 5.0f);
            func_0046d280((void *)(temp_2_31));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 187.0f;
            temp_2_32 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_21 = (s64) (((s64)((func_0046b260((void *)(temp_2_32)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_18_21;
            temp_18_22 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_32)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = (s16) temp_18_22;
            func_0046d280((void *)(temp_2_32));
            temp_16_19 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_19) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))) - 5.0f);
            var_16_9 = 0;
loop_79:
            temp_3_4 = (s64) (var_16_9 << 0x30) >> 0x30;
            if (temp_3_4 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_4 * 4))) + (0xC38)))), 0xFFU, 0, 0, 0xA, 0);
                var_16_9 = (s64) ((var_16_9 + 1) << 0x30) >> 0x30;
                goto loop_79;
            }
            (*(s8 *)((u8 *)(temp_17) + (7))) = 5;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x13;
            func_0045af60(0, 0, 0, 2);
        }
        goto block_626;
    case 0x11:                                      /* switch 1 */
        var_16_10 = 0x55;
loop_85:
        temp_3_5 = (s64) (var_16_10 << 0x30) >> 0x30;
        if (temp_3_5 < 0x58) {
            temp_2_33 = (u8 *)(temp_17 + (temp_3_5 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_33) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_33) + (0xC38)))), 3, 0);
            }
            var_16_10 = (s64) ((var_16_10 + 1) << 0x30) >> 0x30;
            goto loop_85;
        }
        var_16_11 = 0x59;
loop_90:
        temp_3_6 = (s64) (var_16_11 << 0x30) >> 0x30;
        if (temp_3_6 < 0x60) {
            temp_2_34 = (u8 *)(temp_17 + (temp_3_6 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_34) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_34) + (0xC38)))), 3, 0);
            }
            var_16_11 = (s64) ((var_16_11 + 1) << 0x30) >> 0x30;
            goto loop_90;
        }
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        }
        goto block_626;
    case 0x12:                                      /* switch 1 */
loop_115:
        if (((s64) (var_19 << 0x30) >> 0x30) < 2) {
            temp_18_23 = (u8 *)(temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 4));
            temp_16_20 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_23) + (0xC44))))));
            temp_2_35 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF3E))));
            if ((s32) temp_2_35 >= 0) {
                var_f12 = (f32) temp_2_35;
            } else {
                var_f12 = 2.0f * (f32) ((temp_2_35 >> 1) | (temp_2_35 & 1));
            }
            temp_f0 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x79))) = var_3;
            temp_2_36 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF3F))));
            if ((s32) temp_2_36 >= 0) {
                var_f12_2 = (f32) temp_2_36;
            } else {
                var_f12_2 = 2.0f * (f32) ((temp_2_36 >> 1) | (temp_2_36 & 1));
            }
            temp_f0_2 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_2)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_2 >= 2.1474836e9f)) {
                var_3_2 = ((s32)(temp_f0_2)) & 0xFF;
            } else {
                var_3_2 = (((s32)((temp_f0_2 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x7A))) = var_3_2;
            temp_2_37 = (u8)((*(u8 *)((u8 *)(temp_18_23) + (0xF40))));
            if ((s32) temp_2_37 >= 0) {
                var_f12_3 = (f32) temp_2_37;
            } else {
                var_f12_3 = 2.0f * (f32) ((temp_2_37 >> 1) | (temp_2_37 & 1));
            }
            temp_f0_3 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_3)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_3 >= 2.1474836e9f)) {
                var_3_3 = ((s32)(temp_f0_3)) & 0xFF;
            } else {
                var_3_3 = (((s32)((temp_f0_3 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_20) + (0x7B))) = var_3_3;
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_115;
        }
        temp_4_3 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_3 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_3, 1, 6, 0, 1);
        } else {
            var_16_12 = 0;
loop_120:
            if (((s64) (var_16_12 << 0x30) >> 0x30) < 2) {
                temp_18_24 = (u8 *)(temp_17 + (((s64) (var_16_12 << 0x30) >> 0x30) * 4));
                temp_2_38 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_24) + (0xC44))))));
                (*(u8 *)((u8 *)(temp_2_38) + (0x79))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF3E)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7A))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF3F)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF40)));
                (*(u8 *)((u8 *)(temp_2_38) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_18_24) + (0xF41)));
                var_16_12 = (s64) ((var_16_12 + 1) << 0x30) >> 0x30;
                goto loop_120;
            }
            var_16_13 = 0;
loop_123:
            if (((s64) (var_16_13 << 0x30) >> 0x30) < 7) {
                temp_4_4 = (s64) (var_16_13 << 0x30) >> 0x30;
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_4_4 * 4))) + (0xD20)))), 0xFFU, 0, 0, 5, (s64) ((temp_4_4 * 2) << 0x30) >> 0x30);
                var_16_13 = (s64) ((var_16_13 + 1) << 0x30) >> 0x30;
                goto loop_123;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0xFFU, 0, 0, 0, (s64) ((((*(s8 *)((u8 *)(temp_17) + (7))) * 2) + 2) << 0x30) >> 0x30);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_39 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_25 = (s64) (((s64)((func_0046b260((void *)(temp_2_39)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_25;
            temp_18_26 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_39)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_26;
            func_0046d280((void *)(temp_2_39));
            temp_16_21 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_21) + (0xC4))), 5.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))));
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x2C))) = 14.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x30))) = 164.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = 130.0f;
            temp_2_40 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_27 = (s64) (((s64)((func_0046b260((void *)(temp_2_40)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_27;
            temp_18_28 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_40)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = (s16) temp_18_28;
            temp_18_29 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_18_29) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))) - 5.0f);
            func_0046d280((void *)(temp_2_40));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 320.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 187.0f;
            temp_2_41 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_30 = (s64) (((s64)((func_0046b260((void *)(temp_2_41)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_18_30;
            temp_18_31 = (s64) (((s64)((func_0046b2f0((void *)(temp_2_41)) / 2.0f))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = (s16) temp_18_31;
            func_0046d280((void *)(temp_2_41));
            temp_16_22 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 0xA, 0, (*(f32 *)((u8 *)(temp_16_22) + (0xC4))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))) - 5.0f);
            if ((*(s8 *)((u8 *)(temp_17) + (7))) != 5) {
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))));
                func_002b2970(&sp5C8, 0xC3830000U, 0xC2600000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0, sp5C8, 0, 0xA, 0);
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))));
                func_002b2970(&sp5C0, 0xC1100000U, 0xC2600000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0, sp5C0, 0, 0xA, 0);
                func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))));
                func_002b2970(&sp5B8, 0x439C0000U, 0xC30D0000U);
                0;
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, sp5B8, 0, 0xA, 0);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0, 0x708, 0, 0.0f, 360.0f);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 6, 0);
            }
            var_16_14 = 0;
loop_128:
            temp_3_7 = (s64) (var_16_14 << 0x30) >> 0x30;
            if (temp_3_7 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_7 * 4))) + (0xC38)))), 0xFFU, 0, 0, 0xA, 0);
                var_16_14 = (s64) ((var_16_14 + 1) << 0x30) >> 0x30;
                goto loop_128;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x13;
        }
        goto block_626;
    case 0x13:                                      /* switch 1 */
        var_16_15 = 0x55;
loop_134:
        temp_3_8 = (s64) (var_16_15 << 0x30) >> 0x30;
        if (temp_3_8 < 0x58) {
            temp_2_42 = (u8 *)(temp_17 + (temp_3_8 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_42) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_42) + (0xC38)))), 3, 0);
            }
            var_16_15 = (s64) ((var_16_15 + 1) << 0x30) >> 0x30;
            goto loop_134;
        }
        var_16_16 = 0x59;
loop_139:
        temp_3_9 = (s64) (var_16_16 << 0x30) >> 0x30;
        if (temp_3_9 < 0x60) {
            temp_2_43 = (u8 *)(temp_17 + (temp_3_9 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_43) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_43) + (0xC38)))), 3, 0);
            }
            var_16_16 = (s64) ((var_16_16 + 1) << 0x30) >> 0x30;
            goto loop_139;
        }
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) == 0)) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 7, 6, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0xC4))), 0.0f);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))));
            func_002b2970(&sp5B0, 0xC3C80000U, 0x43E10000U);
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, sp5B0, 0, 7, 6);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0xFFU, 0, 0, 7, 6);
            temp_16_23 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 7, 5, (*(f32 *)((u8 *)(temp_16_23) + (0xC4))), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0xC4))));
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))));
            func_002b2970(&sp5A8, 0x442F0000U, (((f32) 0x2EE)));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, sp5A8, 0, 7, 5);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0xFFU, 0, 0, 7, 5);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))));
            func_002b2970(&sp5A0, 0x442F0000U, (((f32) 0x2EE)));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, sp5A0, 0, 7, 3);
            temp_16_24 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 7, 3, (*(f32 *)((u8 *)(temp_16_24) + (0xC4))), 30.0f + (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0xC4))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0xFFU, 0, 0, 7, 3);
            temp_2_44 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
            switch (temp_2_44) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                func_002da0a0(arg0);
                break;
            case 3:                                 /* switch 2 */
                func_002db400(arg0);
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                var_16_17 = 1;
loop_151:
                if (((s64) (var_16_17 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))))) {
                    temp_19_2 = (s64) (var_16_17 << 0x30) >> 0x30;
                    temp_18_32 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))), temp_19_2) << 0x30) >> 0x30;
                    func_002e28f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xF18)))), temp_19_2);
                    temp_20 = (s64) (temp_18_32 << 0x30) >> 0x30;
                    temp_19_3 = clndGetMoonPhase(temp_20) & 0xFF;
                    func_002b2cb0(temp_19_3, func_00106600(temp_18_32) & 0xFF, 0xFF, 0, 1);
                    temp_19_4 = func_00106a90((s64) (temp_20 << 0x30) >> 0x30) / 5U;
                    temp_4_5 = (s32)((*(s32 *)((u8 *)(temp_17) + (0xC20))) + (temp_19_4 * (func_00106600(temp_18_32) & 0xFF)));
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = temp_4_5;
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = func_002b2cb0((s8) temp_4_5, 0, 0x98967F, 0, 1);
                    var_16_17 = (s64) ((var_16_17 + 1) << 0x30) >> 0x30;
                    goto loop_151;
                }
                break;
            case 4:                                 /* switch 2 */
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 1);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0xFFU, 0, 0, 0xA, 0);
                func_00331fc0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x35;
                break;
            case 5:                                 /* switch 2 */
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 1);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0xFFU, 0, 0, 0xA, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0xFFU, 0, 0, 0xA, 0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x37;
                break;
            }
        }
        goto block_626;
    case 0x14:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))) << 0x38) >> 0x38) == 0) {
            temp_16_25 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
            func_002b2970(&sp598, (*(f32 *)((u8 *)(temp_16_25) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
            temp_16_26 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
            func_002b2970(&sp590, (*(f32 *)((u8 *)(temp_16_26) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp598, sp590, 1, 4, 0);
            temp_16_27 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
            func_002b2970(&sp588, (*(f32 *)((u8 *)(temp_16_27) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
            temp_16_28 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
            func_002b2970(&sp580, (*(f32 *)((u8 *)(temp_16_28) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp588, sp580, 1, 4, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x15;
        }
        /* fallthrough */
    case 0x15:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60))))) << 0x38) >> 0x38) == 0) {
            func_002de5a0(arg0);
        }
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58))))) << 0x38) >> 0x38) == 0) {
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) != 0) {
                var_19 = 1;
            }
            if ((*(s8 *)((u8 *)(temp_17) + (0))) == 0x14) {
                var_19 = 1;
            }
            var_18_2 = 0;
loop_178:
            temp_5 = (s8)((*(s8 *)((u8 *)(temp_17) + (9))));
            temp_3_10 = (s64) (var_18_2 << 0x30) >> 0x30;
            if (temp_3_10 < temp_5) {
                temp_4_6 = (s16)((*(s16 *)((u8 *)((temp_17 + (temp_3_10 * 2))) + (0xF46))));
                if (temp_4_6 != 0) {
                    (*(s16 *)((u8 *)((temp_17 + (((s64) (var_18_2 << 0x30) >> 0x30) * 2))) + (0xF46))) = func_002b2d00((s8) temp_4_6, 1, 0, 0, 1);
                    var_19 = 1;
                } else {
                    temp_16_29 = (s64) (var_18_2 << 0x30) >> 0x30;
                    temp_2_45 = (u8 *)(temp_17 + (temp_16_29 * 2));
                    temp_23 = (u8 *)(temp_17 + temp_16_29);
                    temp_f0_4 = (f32)(s32)(func_002b2aa0(0, temp_5, 0.0f, 255.0f, (f32) (*(s16 *)((u8 *)(temp_2_45) + (0xF58)))));
                    if (!(temp_f0_4 >= 2.1474836e9f)) {
                        var_3_4 = ((s32)(temp_f0_4)) & 0xFF;
                    } else {
                        var_3_4 = (((s32)((temp_f0_4 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                    }
                    (*(u8 *)((u8 *)(temp_23) + (0xF6A))) = var_3_4;
                    (*(s16 *)((u8 *)(temp_2_45) + (0xF58))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_2_45) + (0xF58))), 1, 6, 0, 1);
                    var_22 = (s32)(func_002b2a30(0xEC, 0x7FU, 0U, (*(u8 *)((u8 *)(temp_23) + (0xF6A)))));
                    if ((*(s8 *)((u8 *)(temp_17) + (8))) == temp_16_29) {
                        var_22 = (s32)(func_002b2a30(0x2D, 0x2DU, 0x2DU, (*(u8 *)((u8 *)(temp_23) + (0xF6A)))));
                    }
                    0;
                    func_002b2970(&sp578, 0x428E0000U, 0);
                    func_002e0080(arg0, (*(s8 *)((u8 *)(temp_23) + (0xF73))),(*(Vec2f *)&sp578),((void *)(s32)var_22));
                }
                var_18_2 = (s64) ((var_18_2 + 1) << 0x30) >> 0x30;
                goto loop_178;
            }
            if (((s64) (var_19 << 0x30) >> 0x30) == 0) {
                if (D_008C027A & 0x4000) {
                    (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (8))), 1, temp_5 - 1, 0, 2);
                    func_002d83c0(arg0);
                    0;
                    temp_f20_14 = 0;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) = temp_f20_14;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) = temp_f20_14;
                    temp_16_30 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp570, (*(f32 *)((u8 *)(temp_16_30) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
                    temp_16_31 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp568, (*(f32 *)((u8 *)(temp_16_31) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp570, sp568, 1, 2, 0);
                    temp_16_32 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp560, (*(f32 *)((u8 *)(temp_16_32) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
                    temp_16_33 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp558, (*(f32 *)((u8 *)(temp_16_33) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp560, sp558, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C027A & 0x1000) {
                    (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (8))), 1, 0, temp_5 - 1, 2);
                    func_002d83c0(arg0);
                    0;
                    temp_f20_15 = 0;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) = temp_f20_15;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) = temp_f20_15;
                    temp_16_34 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp550, (*(f32 *)((u8 *)(temp_16_34) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))) - 4.0f))));
                    temp_16_35 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4))))));
                    func_002b2970(&sp548, (*(f32 *)((u8 *)(temp_16_35) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), sp550, sp548, 1, 2, 0);
                    temp_16_36 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp540, (*(f32 *)((u8 *)(temp_16_36) + (0x2C))), ((((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))) - 4.0f))));
                    temp_16_37 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8))))));
                    func_002b2970(&sp538, (*(f32 *)((u8 *)(temp_16_37) + (0x2C))), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0x30))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), sp540, sp538, 1, 2, 0);
                    func_0045af60(0, 0, 0, 0);
                } else if (D_008C024E & 0x20) {
                    func_0045af60(0, 0, 0, 2);
                    func_002b2970(&sp530, (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), (((*(f32 *)((u8 *)(&D_0063F5A0) + (4))))));
                    func_002b2970(&sp528, (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), (((500.0f + (*(f32 *)((u8 *)(&D_0063F5A0) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), sp530, sp528, 0, 4, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), 0xCCU, 0, 0, 2, 0);
                    func_002b2970(&sp520, (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), (((*(f32 *)((u8 *)(&D_0063F5A8) + (4))))));
                    func_002b2970(&sp518, (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), (((500.0f + (*(f32 *)((u8 *)(&D_0063F5A8) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), sp520, sp518, 0, 4, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), 0xCCU, 0, 0, 2, 0);
                    func_002b2970(&sp510, (((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), (((*(f32 *)((u8 *)(&D_0063F7B0) + (4))))));
                    func_002b2970(&sp508, (((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), (((400.0f + (*(f32 *)((u8 *)(&D_0063F7B0) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), sp510, sp508, 2, 4, 0);
                    func_002b2970(&sp500, (((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), (((*(f32 *)((u8 *)(&D_0063F7B8) + (4))))));
                    func_002b2970(&sp4F8, (((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), (((400.0f + (*(f32 *)((u8 *)(&D_0063F7B8) + (4)))))));
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), sp500, sp4F8, 2, 4, 0);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD3C)))), 0, 1);
                    var_19_2 = 0;
loop_187:
                    if (((s64) (var_19_2 << 0x30) >> 0x30) < 6) {
                        temp_18_33 = (s64) (var_19_2 << 0x30) >> 0x30;
                        temp_16_38 = (u8 *)((s32)&D_0063F560 + ((temp_18_33 + 0x43) * 8));
                        func_002b2970(&sp4F0, (*(f32 *)((u8 *)(temp_16_38) + (0))), (*(f32 *)((u8 *)(temp_16_38) + (4))));
                        func_002b2970(&sp4E8, (*(f32 *)((u8 *)(temp_16_38) + (0))), 0x442F0000U);
                        func_002e0620((void *)((*(s32 *)((u8 *)((temp_17 + (temp_18_33 * 4))) + (0xD44)))), sp4F0, sp4E8, 2, 5, 0);
                        var_19_2 = (s64) ((var_19_2 + 1) << 0x30) >> 0x30;
                        goto loop_187;
                    }
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 1);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 1);
                    func_002dd230(arg0);
                    var_16_18 = 0;
loop_190:
                    temp_3_11 = (s64) (var_16_18 << 0x30) >> 0x30;
                    if (temp_3_11 < 7) {
                        func_002e04f0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_11 * 4))) + (0xD20)))), 0, 0);
                        var_16_18 = (s64) ((var_16_18 + 1) << 0x30) >> 0x30;
                        goto loop_190;
                    }
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 0);
                    func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 0);
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = 198.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = (f32) 0x151;
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0x41, 146.0f);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0U, 0xFF, 0, 6, 0);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x2C))) = 216.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))))) + (0x30))) = 368.0f;
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
                    temp_2_46 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
                    temp_18_34 = (s64) (((s64)(func_0046b260((void *)(temp_2_46)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_34;
                    temp_18_35 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_46)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_35;
                    func_0046d280((void *)(temp_2_46));
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xCC, 0, 4, 4);
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
                    func_002b2970(&sp4E0, 0xC3700000U, 0x43C80000U);
                    func_002b2970(&sp4D8, 0xC3700000U, 0x439B0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp4E0, sp4D8, 0, 4, 4);
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
                    temp_2_47 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
                    temp_18_36 = (s64) (((s64)(func_0046b260((void *)(temp_2_47)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_36;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 4, -90.0f, fGpffff8524);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 4);
                    func_0046d280((void *)(temp_2_47));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
                    (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
                    temp_2_48 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
                    temp_16_39 = (s64) (((s64)(func_0046b260((void *)(temp_2_48)))) << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_39;
                    (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
                    func_0046d280((void *)(temp_2_48));
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
                    var_21 = 0;
loop_195:
                    if (((s64) (var_21 << 0x30) >> 0x30) < 7) {
                        temp_19_5 = (s64) (var_21 << 0x30) >> 0x30;
                        temp_18_37 = (u8 *)((s32)&D_0063F560 + ((temp_19_5 + 0x3A) * 8));
                        temp_3_12 = (u8 *)(temp_17 + (temp_19_5 * 4));
                        func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_12) + (0xD20)))), 0x56, (f32) (temp_19_5 + 0x64));
                        if (temp_19_5 > 0) {
                            fclWriteColorBytes(&sp744, 0xED, 0x80, 0, 0xFFU);
                            temp_2_49 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_12) + (0xD20))))));
                            (*(u8 *)((u8 *)(temp_2_49) + (0x79))) = sp744;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7A))) = sp745;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7B))) = sp746;
                            (*(u8 *)((u8 *)(temp_2_49) + (0x7C))) = sp747;
                        }
                        temp_2_50 = (u8 *)(temp_17 + (((s64) (var_21 << 0x30) >> 0x30) * 4));
                        func_002b2970(&sp4D0, (((80.0f + (*(f32 *)((u8 *)(temp_18_37) + (0)))))), (*(f32 *)((u8 *)(temp_18_37) + (4))));
                        func_002b2970(&sp4C8, (((*(f32 *)((u8 *)(temp_18_37) + (0))))), (*(f32 *)((u8 *)(temp_18_37) + (4))));
                        func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_50) + (0xD20)))), sp4D0, sp4C8, 0, 3, var_21);
                        func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_50) + (0xD20)))), 0U, 0xFF, 0, 3, var_21);
                        var_21 = (s64) ((var_21 + 1) << 0x30) >> 0x30;
                        goto loop_195;
                    }
                    fclWriteColorBytes(&sp740, 0x2D, 0x2D, 0x2D, 0xFFU);
                    temp_2_51 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
                    (*(u8 *)((u8 *)(temp_2_51) + (0x79))) = sp740;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7A))) = sp741;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7B))) = sp742;
                    (*(u8 *)((u8 *)(temp_2_51) + (0x7C))) = sp743;
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
                    var_16_19 = 0;
loop_198:
                    temp_3_13 = (s64) (var_16_19 << 0x30) >> 0x30;
                    if (temp_3_13 < 3) {
                        func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_13 * 4))) + (0xC38)))), 0U, 0xFF, 0, 0xA, 0);
                        var_16_19 = (s64) ((var_16_19 + 1) << 0x30) >> 0x30;
                        goto loop_198;
                    }
                    func_002d7f90(arg0);
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x11;
                } else if (D_008C024E & 0x40) {
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))))) + (0xC4))), 0.0f);
                    func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))))) + (0xC4))), 0.0f);
                    var_18_3 = 0;
loop_203:
                    if (((s64) (var_18_3 << 0x30) >> 0x30) < 2) {
                        temp_16_40 = (u8 *)(temp_17 + (((s64) (var_18_3 << 0x30) >> 0x30) * 4));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF3E))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x79)));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF3F))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x7A)));
                        (*(u8 *)((u8 *)(temp_16_40) + (0xF40))) = (u8) (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_40) + (0xED4)))))) + (0x7B)));
                        var_18_3 = (s64) ((var_18_3 + 1) << 0x30) >> 0x30;
                        goto loop_203;
                    }
                    (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = 0;
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x16;
                    func_0045af60(0, 0, 0, 1);
                }
            }
        }
        goto block_626;
    case 0x16:                                      /* switch 1 */
        func_002de5a0(arg0);
loop_215:
        temp_3_14 = (s64) (var_19 << 0x30) >> 0x30;
        if (temp_3_14 < (*(s8 *)((u8 *)(temp_17) + (9)))) {
            temp_4_7 = (s16)((*(s16 *)((u8 *)((temp_17 + (temp_3_14 * 2))) + (0xF46))));
            if (temp_4_7 != 0) {
                (*(s16 *)((u8 *)((temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 2))) + (0xF46))) = func_002b2d00((s8) temp_4_7, 1, 0, 0, 1);
            } else {
                temp_18_38 = (s64) (var_19 << 0x30) >> 0x30;
                temp_2_52 = (u8 *)(temp_17 + (temp_18_38 * 2));
                temp_22 = (u8 *)(temp_17 + temp_18_38);
                temp_f0_5 = (f32)(s32)(func_002b2aa0(0, 0, 255.0f, (f32) (*(s16 *)((u8 *)(temp_2_52) + (0xF58))), 6.0f));
                if (!(temp_f0_5 >= 2.1474836e9f)) {
                    var_3_5 = ((s32)(temp_f0_5)) & 0xFF;
                } else {
                    var_3_5 = (((s32)((temp_f0_5 - 2.1474836e9f))) | 0x80000000) & 0xFF;
                }
                (*(u8 *)((u8 *)(temp_22) + (0xF6A))) = var_3_5;
                (*(s16 *)((u8 *)(temp_2_52) + (0xF58))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_2_52) + (0xF58))), 1, 6, 0, 1);
                var_21_2 = (s32)(func_002b2a30(0xEC, 0x7FU, 0U, (*(u8 *)((u8 *)(temp_22) + (0xF6A)))));
                if ((*(s8 *)((u8 *)(temp_17) + (8))) == temp_18_38) {
                    var_21_2 = (s32)(func_002b2a30(0x2D, 0x2DU, 0x2DU, (*(u8 *)((u8 *)(temp_22) + (0xF6A)))));
                }
                0;
                func_002b2970(&sp4C0, 0x428E0000U, 0);
                func_002e0080(arg0, (*(s8 *)((u8 *)(temp_22) + (0xF73))),(*(Vec2f *)&sp4C0),((void *)(s32)var_21_2));
            }
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_215;
        }
        var_19_3 = 0;
loop_236:
        if (((s64) (var_19_3 << 0x30) >> 0x30) < 2) {
            temp_18_39 = (u8 *)(temp_17 + (((s64) (var_19_3 << 0x30) >> 0x30) * 4));
            temp_16_41 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_18_39) + (0xED4))))));
            temp_2_53 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF3E))));
            if ((s32) temp_2_53 >= 0) {
                var_f12_4 = (f32) temp_2_53;
            } else {
                var_f12_4 = 2.0f * (f32) ((temp_2_53 >> 1) | (temp_2_53 & 1));
            }
            temp_f0_6 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_4)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_6 >= 2.1474836e9f)) {
                var_3_6 = ((s32)(temp_f0_6)) & 0xFF;
            } else {
                var_3_6 = (((s32)((temp_f0_6 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x79))) = var_3_6;
            temp_2_54 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF3F))));
            if ((s32) temp_2_54 >= 0) {
                var_f12_5 = (f32) temp_2_54;
            } else {
                var_f12_5 = 2.0f * (f32) ((temp_2_54 >> 1) | (temp_2_54 & 1));
            }
            temp_f0_7 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_5)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_7 >= 2.1474836e9f)) {
                var_3_7 = ((s32)(temp_f0_7)) & 0xFF;
            } else {
                var_3_7 = (((s32)((temp_f0_7 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x7A))) = var_3_7;
            temp_2_55 = (u8)((*(u8 *)((u8 *)(temp_18_39) + (0xF40))));
            if ((s32) temp_2_55 >= 0) {
                var_f12_6 = (f32) temp_2_55;
            } else {
                var_f12_6 = 2.0f * (f32) ((temp_2_55 >> 1) | (temp_2_55 & 1));
            }
            temp_f0_8 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_6)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_8 >= 2.1474836e9f)) {
                var_3_8 = ((s32)(temp_f0_8)) & 0xFF;
            } else {
                var_3_8 = (((s32)((temp_f0_8 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_41) + (0x7B))) = var_3_8;
            var_19_3 = (s64) ((var_19_3 + 1) << 0x30) >> 0x30;
            goto loop_236;
        }
        temp_4_8 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_8 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_8, 1, 6, 0, 1);
        } else {
            var_18_4 = 0;
loop_241:
            if (((s64) (var_18_4 << 0x30) >> 0x30) < 2) {
                temp_16_42 = (u8 *)(temp_17 + (((s64) (var_18_4 << 0x30) >> 0x30) * 4));
                temp_2_56 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_16_42) + (0xED4))))));
                (*(u8 *)((u8 *)(temp_2_56) + (0x79))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF3E)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7A))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF3F)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF40)));
                (*(u8 *)((u8 *)(temp_2_56) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_16_42) + (0xF41)));
                var_18_4 = (s64) ((var_18_4 + 1) << 0x30) >> 0x30;
                goto loop_241;
            }
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0x41, 38.0f);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 5, 0, -105.0f, 27.0f);
            fclWriteColorBytes(&sp73C, 0x97, 0xF, 0, 0xFFU);
            temp_2_57 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C))))));
            (*(u8 *)((u8 *)(temp_2_57) + (0x79))) = sp73C;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7A))) = sp73D;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7B))) = sp73E;
            (*(u8 *)((u8 *)(temp_2_57) + (0x7C))) = sp73F;
            temp_18_40 = (s64) (((s64)((173.0f - (*(f32 *)((u8 *)(&D_0063F7C8) + (0)))))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))))) + (0x100))) = (s16) temp_18_40;
            temp_16_43 = (s64) (((s64)(((f32) 0x223 - (*(f32 *)((u8 *)(&D_0063F7C8) + (4)))))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))))) + (0x102))) = (s16) temp_16_43;
            func_002b2970(&sp4B8, (*(f32 *)((u8 *)(&D_0063F780) + (0))), (((*(f32 *)((u8 *)(&D_0063F780) + (4))))));
            func_002b2970(&sp4B0, 0xC3020000U, ((((*(f32 *)((u8 *)(&D_0063F780) + (4))) - 50.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD48)))), sp4B8, sp4B0, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD48)))), 0, 7, 3, 0.0f, -20.0f);
            func_002b2970(&sp4A8, (((*(f32 *)((u8 *)(&D_0063F778) + (0))))), (*(f32 *)((u8 *)(&D_0063F778) + (4))));
            func_002b2970(&sp4A0, ((((*(f32 *)((u8 *)(&D_0063F778) + (0))) - 200.0f))), 0xC3020000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD44)))), sp4A8, sp4A0, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD44)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp498, (((*(f32 *)((u8 *)(&D_0063F788) + (0))))), (*(f32 *)((u8 *)(&D_0063F788) + (4))));
            func_002b2970(&sp490, ((((*(f32 *)((u8 *)(&D_0063F788) + (0))) - 40.0f))), (((f32) 0x226)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD4C)))), sp498, sp490, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD4C)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp488, (((*(f32 *)((u8 *)(&D_0063F798) + (0))))), (*(f32 *)((u8 *)(&D_0063F798) + (4))));
            func_002b2970(&sp480, (((40.0f + (*(f32 *)((u8 *)(&D_0063F798) + (0)))))), (((f32) 0x226)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD54)))), sp488, sp480, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD54)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp478, (((*(f32 *)((u8 *)(&D_0063F790) + (0))))), (*(f32 *)((u8 *)(&D_0063F790) + (4))));
            func_002b2970(&sp470, (((40.0f + (*(f32 *)((u8 *)(&D_0063F790) + (0)))))), 0xC3160000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD50)))), sp478, sp470, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD50)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp468, (((*(f32 *)((u8 *)(&D_0063F7A0) + (0))))), (*(f32 *)((u8 *)(&D_0063F7A0) + (4))));
            func_002b2970(&sp460, (((40.0f + (*(f32 *)((u8 *)(&D_0063F7A0) + (0)))))), 0xC3480000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD58)))), sp468, sp460, 0, 7, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD58)))), 0, 7, 3, 0.0f, 20.0f);
            func_002b2970(&sp458, (((*(f32 *)((u8 *)(&D_0063F7B0) + (0))))), (((*(f32 *)((u8 *)(&D_0063F7B0) + (4))))));
            func_002b2970(&sp450, ((((f32) 0x29E + (*(f32 *)((u8 *)(&D_0063F7B0) + (0)))))), ((((*(f32 *)((u8 *)(&D_0063F7B0) + (4))) - 300.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), sp458, sp450, 1, 0xA, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD60)))), 1, 4, 3, fGpffff852C, 60.0f);
            func_002b2970(&sp448, (((*(f32 *)((u8 *)(&D_0063F7B8) + (0))))), (((*(f32 *)((u8 *)(&D_0063F7B8) + (4))))));
            func_002b2970(&sp440, ((((f32) 0x29E + (*(f32 *)((u8 *)(&D_0063F7B8) + (0)))))), ((((*(f32 *)((u8 *)(&D_0063F7B8) + (4))) - 300.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), sp448, sp440, 1, 4, 3);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD64)))), 1, 4, 3, fGpffff852C, 60.0f);
            func_002b2970(&sp438, (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), (((*(f32 *)((u8 *)(&D_0063F5A0) + (4))))));
            func_002b2970(&sp430, (*(f32 *)((u8 *)(&D_0063F5A0) + (0))), (((500.0f + (*(f32 *)((u8 *)(&D_0063F5A0) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), sp438, sp430, 0, 4, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC58)))), 0xCCU, 0, 0, 2, 0);
            func_002b2970(&sp428, (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), (((*(f32 *)((u8 *)(&D_0063F5A8) + (4))))));
            func_002b2970(&sp420, (*(f32 *)((u8 *)(&D_0063F5A8) + (0))), (((500.0f + (*(f32 *)((u8 *)(&D_0063F5A8) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), sp428, sp420, 0, 4, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC5C)))), 0xCCU, 0, 0, 2, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD3C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED4)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xED8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x17;
        }
        goto block_626;
    case 0x17:                                      /* switch 1 */
        if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 3) << 0x38) >> 0x38) == 0) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 3, 0, 27.0f, -14.0f);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0x41, 157.0f);
            func_002b2970(&sp418, (((*(f32 *)((u8 *)(&D_0063F5B8) + (0))))), (((-300.0f + (*(f32 *)((u8 *)(&D_0063F5B8) + (4)))))));
            func_002b2970(&sp410, (((*(f32 *)((u8 *)(&D_0063F5B8) + (0))))), (((*(f32 *)((u8 *)(&D_0063F5B8) + (4))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), sp418, sp410, 0, 7, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0U, 0xCC, 0, 7, 0);
            fclWriteColorBytes(&sp738, 0, 0, 0, 0xFFU);
            temp_2_58 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))));
            (*(u8 *)((u8 *)(temp_2_58) + (0x79))) = sp738;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7A))) = sp739;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7B))) = sp73A;
            (*(u8 *)((u8 *)(temp_2_58) + (0x7C))) = sp73B;
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0, 0, 0, 0.0f, -4.0f);
            temp_18_41 = (s32)(320.0f - (*(f32 *)((u8 *)(&D_0063F5B8) + (0))));
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x100))) = (s16) temp_18_41;
            temp_16_44 = (s32)(((*(f32 *)((u8 *)(&D_0063F5B8) + (4))) - 83.0f));
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x102))) = (s16) temp_16_44;
            func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), 0, 0, 0, 0x3F800000, 0x3FC00000, 1.0f, 0x3F800000);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x18;
        }
        goto block_626;
    case 0x18:                                      /* switch 1 */
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))) << 0x38) >> 0x38) == 0) {
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0x41, 152.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0U, 0xCC, 0, 5, 0);
            fclWriteColorBytes(&sp734, 0, 0, 0, 0xFFU);
            temp_2_59 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C))))));
            (*(u8 *)((u8 *)(temp_2_59) + (0x79))) = sp734;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7A))) = sp735;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7B))) = sp736;
            (*(u8 *)((u8 *)(temp_2_59) + (0x7C))) = sp737;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0x41, ((f32)(sp734)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0U, 0xCC, 0, 5, 0);
            fclWriteColorBytes(&sp730, 0, 0, 0, 0xFFU);
            temp_2_60 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30))))));
            (*(u8 *)((u8 *)(temp_2_60) + (0x79))) = sp730;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7A))) = sp731;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7B))) = sp732;
            (*(u8 *)((u8 *)(temp_2_60) + (0x7C))) = sp733;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0x41, ((f32)(sp730)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0U, 0xFF, 0, 0xA, 0);
            func_002b2970(&sp408, 0x42380000U, 0x43930000U);
            temp_2_61 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70))))));
            (*(f32 *)((u8 *)(temp_2_61) + (0x2C))) = *(f32 *)&sp408;
            (*(f32 *)((u8 *)(temp_2_61) + (0x30))) = *(f32 *)((u8 *)&sp408 + 4);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), 0x41, 8.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD8)))), 0x41, 45.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD8)))), 0U, 0xFF, 0, 6, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0x41, 46.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0U, 0xFF, 0, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x2C))) = (f32) 0x17F;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))))) + (0x30))) = 404.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0x41, 47.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))), 0U, 0xFF, 0, 6, 0);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))))) + (0x2C))) = 446.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDF0)))))) + (0x30))) = 404.0f;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0x41, 47.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0U, 0xFF, 0, 6, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0x41, 47.0f);
            temp_16_45 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4))))));
            temp_2_62 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0))))));
            (*(f32 *)((u8 *)(temp_2_62) + (0x2C))) = (f32) (*(f32 *)((u8 *)(temp_16_45) + (0x2C)));
            (*(f32 *)((u8 *)(temp_2_62) + (0x30))) = (f32) (*(f32 *)((u8 *)(temp_16_45) + (0x30)));
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))))) + (0x62))) = 0xFF;
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 1);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0x41, 139.0f);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0U, 0xFF, 0, 6, 0);
            fclWriteColorBytes(&sp72C, 0xCE, 0x71, 2, 0xFFU);
            temp_2_63 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C))))));
            (*(u8 *)((u8 *)(temp_2_63) + (0x79))) = sp72C;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7A))) = sp72D;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7B))) = sp72E;
            (*(u8 *)((u8 *)(temp_2_63) + (0x7C))) = sp72F;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0x41, ((f32)(sp72C)));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0U, 0xFF, 0, 6, 0);
            fclWriteColorBytes(&sp728, 0xCE, 0x71, 2, 0xFFU);
            temp_2_64 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90))))));
            (*(u8 *)((u8 *)(temp_2_64) + (0x79))) = sp728;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7A))) = sp729;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7B))) = sp72A;
            (*(u8 *)((u8 *)(temp_2_64) + (0x7C))) = sp72B;
            (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
            temp_2_65 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
            switch (temp_2_65) {                    /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                temp_3_15 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                func_002e24a0(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_15) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_15) + (0xF73))) + 4), 2, 2);
                break;
            case 1:                                 /* switch 3 */
                func_002e24a0(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                break;
            case 2:                                 /* switch 3 */
                func_002e24a0(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                break;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x1B:                                      /* switch 1 */
        func_002cb6c0(arg0, 0);
        func_002b2970(&sp400, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp724, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_17_2 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_46 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp400, (s32) sp724, (*(RGBA *)&(u32){0x11}), 5, temp_17_2, 0x70, 0x7A, temp_16_46, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        goto block_626;
    case 0x1C:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3F8, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp720, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_42 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_47 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3F8, (s32) sp720, (*(RGBA *)&(u32){0x11}), 5, temp_18_42, 0x70, 0x7A, temp_16_47, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        var_21_3 = 0;
loop_275:
        if (((s64) (var_21_3 << 0x30) >> 0x30) < 2) {
            temp_19_6 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8))))));
            temp_18_43 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_48 = (u8 *)(temp_17 + (((s64) (var_21_3 << 0x30) >> 0x30) * 4));
            temp_2_66 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF3E))));
            if ((s32) temp_2_66 >= 0) {
                var_f12_7 = (f32) temp_2_66;
            } else {
                var_f12_7 = 2.0f * (f32) ((temp_2_66 >> 1) | (temp_2_66 & 1));
            }
            temp_f0_9 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_7)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_9 >= 2.1474836e9f)) {
                var_3_9 = ((s32)(temp_f0_9)) & 0xFF;
            } else {
                var_3_9 = (((s32)((temp_f0_9 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x79))) = var_3_9;
            (*(s8 *)((u8 *)(temp_19_6) + (0x79))) = var_3_9;
            temp_2_67 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF3F))));
            if ((s32) temp_2_67 >= 0) {
                var_f12_8 = (f32) temp_2_67;
            } else {
                var_f12_8 = 2.0f * (f32) ((temp_2_67 >> 1) | (temp_2_67 & 1));
            }
            temp_f0_10 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_8)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_10 >= 2.1474836e9f)) {
                var_3_10 = ((s32)(temp_f0_10)) & 0xFF;
            } else {
                var_3_10 = (((s32)((temp_f0_10 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x7A))) = var_3_10;
            (*(s8 *)((u8 *)(temp_19_6) + (0x7A))) = var_3_10;
            temp_2_68 = (u8)((*(u8 *)((u8 *)(temp_16_48) + (0xF40))));
            if ((s32) temp_2_68 >= 0) {
                var_f12_9 = (f32) temp_2_68;
            } else {
                var_f12_9 = 2.0f * (f32) ((temp_2_68 >> 1) | (temp_2_68 & 1));
            }
            temp_f0_11 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_9)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_11 >= 2.1474836e9f)) {
                var_3_11 = ((s32)(temp_f0_11)) & 0xFF;
            } else {
                var_3_11 = (((s32)((temp_f0_11 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_43) + (0x7B))) = var_3_11;
            (*(s8 *)((u8 *)(temp_19_6) + (0x7B))) = var_3_11;
            var_21_3 = (s64) ((var_21_3 + 1) << 0x30) >> 0x30;
            goto loop_275;
        }
        temp_4_9 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_9 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_9, 1, 6, 0, 1);
        } else {
            temp_2_69 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8))))));
            temp_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_2 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_69) + (0x79))) = temp_6;
            (*(u8 *)((u8 *)(temp_2_69) + (0x7A))) = temp_5_2;
            (*(u8 *)((u8 *)(temp_2_69) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_69) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_70 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_2 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_3 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_70) + (0x79))) = temp_6_2;
            (*(u8 *)((u8 *)(temp_2_70) + (0x7A))) = temp_5_3;
            (*(u8 *)((u8 *)(temp_2_70) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_70) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            sp6A0 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2))), temp_5_3, temp_6_2));
            sp6A4 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 1, &sp6A0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1D;
            func_002d6190(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        goto block_626;
    case 0x1D:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002b2970(&sp3F0, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp71C, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_44 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_49 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3F0, (s32) sp71C, (*(RGBA *)&(u32){0x11}), 5, temp_18_44, 0x70, 0x7A, temp_16_49, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        func_002b2970(&sp3E8, 0x424C0000U, 0x42400000U);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))),(*(Vec2f *)&sp3E8), (void *)func_002b2a30(0xFF, 0xFFU, 0xFFU, 0xFFU));
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            temp_16_50 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
            func_002e7a80(func_002e7a60() - temp_16_50);
            sp698 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
            sp69C = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 4, &sp698, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1E;
        } else {
            func_002d7300(arg0);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        }
        goto block_626;
    case 0x1E:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002b2970(&sp3E0, 0x424C0000U, 0x42400000U);
        func_002e0080(arg0, (*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))),(*(Vec2f *)&sp3E0), (void *)func_002b2a30(0xFF, 0xFFU, 0xFFU, 0xFFU));
        func_002b2970(&sp3D8, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp718, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_45 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_51 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3D8, (s32) sp718, (*(RGBA *)&(u32){0x11}), 5, temp_18_45, 0x70, 0x7A, temp_16_51, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_0045af60(0, 0, 0, 7);
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                sp690 = (s32) ((s64) (func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7)))) << 0x30) >> 0x30);
                sp694 = 0;
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 5, &sp690, 1);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1F;
            } else {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                temp_16_52 = (s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
                func_00106620(temp_16_52, ((func_00106600((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30) & 0xFF) + 1) & 0xFF);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
            if (func_002e2670() >= 6) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 0);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 0);
            }
            func_002d7300(arg0);
        }
        goto block_626;
    case 0x1F:                                      /* switch 1 */
        func_002d5040(arg0);
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3D0, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp714, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_46 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_53 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3D0, (s32) sp714, (*(RGBA *)&(u32){0x11}), 5, temp_18_46, 0x70, 0x7A, temp_16_53, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                temp_16_54 = (u32)(func_00106a90(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))))) >> 2);
                func_002e7a80(func_002e7a60() + temp_16_54);
                func_0045af60(0, 0, 0, 6);
            } else {
                temp_16_55 = (s64)(s32)(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7)))));
                func_00106620(temp_16_55, ((func_00106600(func_00106cd0((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))))) & 0xFF) + 1) & 0xFF);
            }
            func_00106d40((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))), (*(s8 *)((u8 *)(temp_17) + (7))), (s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x20:                                      /* switch 1 */
        func_002cb6c0(arg0, 1);
        func_002b2970(&sp3C8, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp710, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_47 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_56 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp3C8, (s32) sp710, (*(RGBA *)&(u32){0x11}), 5, temp_18_47, 0x70, 0x7A, temp_16_56, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 9) << 0x38) >> 0x38) == 0)) {
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xD6C)))), 0, 4, 0, -14.0f, 110.0f);
            func_002e0690((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), 0, 5, 0, 0x3F800000, 0x3FC00000);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))))) + (0x62))), 0, 0, 5, 0);
            temp_18_48 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x4E));
            func_002b2970(&sp3C0, (*(f32 *)((u8 *)(&D_0063F7D0) + (0))), (*(f32 *)((u8 *)(&D_0063F7D0) + (4))));
            func_0046b260((void *)(temp_18_48));
            0;
            func_0046b2f0((void *)(temp_18_48));
            0;
            func_002b2970(&sp3B8, 0, 0);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70)))), sp3C0, sp3B8, 0, 5, 0);
            func_0046d280((void *)(temp_18_48));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C)))))) + (0x62))), 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))))) + (0x62))), 0, 0, 5, 0);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))));
            temp_f20_16 = (f32)(s32)((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))))) + (0x2C))) - 1000.0f);
            func_002b2970(&sp3B0, ((temp_f20_16)), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))))) + (0x30))));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, sp3B0, 2, 3, 0);
            func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))));
            temp_f20_17 = (f32)(s32)((*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))))) + (0x2C))) - 1000.0f);
            func_002b2970(&sp3A8, ((temp_f20_17)), (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))))) + (0x30))));
            0;
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, sp3A8, 2, 3, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))), (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64)))))) + (0x62))), 0, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))), 0x41, 109.0f);
            func_002b2970(&sp3A0, (((660.0f + (*(f32 *)((u8 *)(&D_0063F5B0) + (0)))))), (*(f32 *)((u8 *)(&D_0063F5B0) + (4))));
            func_002b2970(&sp398, (((*(f32 *)((u8 *)(&D_0063F5B0) + (0))))), (*(f32 *)((u8 *)(&D_0063F5B0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))), sp3A0, sp398, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60)))))) + (0x62))) = 0xCC;
            fclWriteColorBytes(&sp70C, 0, 0, 0, 0xFFU);
            temp_2_71 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC60))))));
            (*(u8 *)((u8 *)(temp_2_71) + (0x79))) = sp70C;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7A))) = sp70D;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7B))) = sp70E;
            (*(u8 *)((u8 *)(temp_2_71) + (0x7C))) = sp70F;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))), 0x41, ((f32)(sp70C)));
            func_002b2970(&sp390, (((660.0f + (*(f32 *)((u8 *)(&D_0063F5F0) + (0)))))), (*(f32 *)((u8 *)(&D_0063F5F0) + (4))));
            func_002b2970(&sp388, (((*(f32 *)((u8 *)(&D_0063F5F0) + (0))))), (*(f32 *)((u8 *)(&D_0063F5F0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))), sp390, sp388, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80)))))) + (0x62))) = 0xCC;
            fclWriteColorBytes(&sp708, 0, 0, 0, 0xFFU);
            temp_2_72 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC80))))));
            (*(u8 *)((u8 *)(temp_2_72) + (0x79))) = sp708;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7A))) = sp709;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7B))) = sp70A;
            (*(u8 *)((u8 *)(temp_2_72) + (0x7C))) = sp70B;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))), 0x41, ((f32)(sp708)));
            func_002b2970(&sp380, (((660.0f + (*(f32 *)((u8 *)(&D_0063F5D0) + (0)))))), (*(f32 *)((u8 *)(&D_0063F5D0) + (4))));
            func_002b2970(&sp378, (((*(f32 *)((u8 *)(&D_0063F5D0) + (0))))), (*(f32 *)((u8 *)(&D_0063F5D0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))), sp380, sp378, 0, 4, 6);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70)))))) + (0x62))) = 0xCC;
            fclWriteColorBytes(&sp704, 0, 0, 0, 0xFFU);
            temp_2_73 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC70))))));
            (*(u8 *)((u8 *)(temp_2_73) + (0x79))) = sp704;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7A))) = sp705;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7B))) = sp706;
            (*(u8 *)((u8 *)(temp_2_73) + (0x7C))) = sp707;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80)))), 0x41, ((f32)(sp704)));
            func_002b2970(&sp370, (((f32) -0x266)), 0x43720000U);
            func_002b2970(&sp368, 0x42AC0000U, 0x43720000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80)))), sp370, sp368, 0, 4, 6);
            fclWriteColorBytes(&sp700, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_74 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE80))))));
            (*(u8 *)((u8 *)(temp_2_74) + (0x79))) = sp700;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7A))) = sp701;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7B))) = sp702;
            (*(u8 *)((u8 *)(temp_2_74) + (0x7C))) = sp703;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84)))), 0x41, ((f32)(sp700)));
            func_002b2970(&sp360, ((((*(f32 *)((u8 *)(&D_0063F5F8) + (0))) - 700.0f))), (*(f32 *)((u8 *)(&D_0063F5F8) + (4))));
            func_002b2970(&sp358, (((*(f32 *)((u8 *)(&D_0063F5F8) + (0))))), (*(f32 *)((u8 *)(&D_0063F5F8) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84)))), sp360, sp358, 0, 4, 6);
            fclWriteColorBytes(&sp6FC, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_75 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC84))))));
            (*(u8 *)((u8 *)(temp_2_75) + (0x79))) = sp6FC;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7A))) = sp6FD;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7B))) = sp6FE;
            (*(u8 *)((u8 *)(temp_2_75) + (0x7C))) = sp6FF;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC74)))), 0x41, ((f32)(sp6FC)));
            func_002b2970(&sp350, ((((*(f32 *)((u8 *)(&D_0063F5D8) + (0))) - 700.0f))), (*(f32 *)((u8 *)(&D_0063F5D8) + (4))));
            func_002b2970(&sp348, (((*(f32 *)((u8 *)(&D_0063F5D8) + (0))))), (*(f32 *)((u8 *)(&D_0063F5D8) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC74)))), sp350, sp348, 0, 4, 6);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC78)))), 0x41, 114.0f);
            func_002b2970(&sp340, ((((*(f32 *)((u8 *)(&D_0063F5E0) + (0))) - 700.0f))), (*(f32 *)((u8 *)(&D_0063F5E0) + (4))));
            func_002b2970(&sp338, (((*(f32 *)((u8 *)(&D_0063F5E0) + (0))))), (*(f32 *)((u8 *)(&D_0063F5E0) + (4))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC78)))), sp340, sp338, 0, 4, 6);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x21;
        }
        goto block_626;
    case 0x21:                                      /* switch 1 */
        if (func_002d1590(arg0) == 1) {
            if ((D_008C0276 & 0x1000) && ((*(s8 *)((u8 *)(temp_17) + (0x14))) == 0)) {
                func_0045af60(0, 0, 0, 0);
                if ((*(s16 *)((u8 *)(temp_17) + (2))) == 0) {
                    temp_2_76 = func_002e26a0();
                    (*(s16 *)((u8 *)(temp_17) + (2))) = temp_2_76;
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2cb0(0, (s64) ((s64) temp_2_76 << 0x30) >> 0x30, 4, 0, 1);
                } else {
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, 0, func_002e2670(), 2);
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e2670() << 0x30) >> 0x30, 5, -1);
                }
                (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                return 0;
            }
            if (D_008C027A & 0x1000) {
                if (func_002e2670() > 0) {
                    if ((*(s16 *)((u8 *)(temp_17) + (2))) != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, 0, 0, 1);
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e2670() << 0x30) >> 0x30, 5, -1);
                    (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C0276 & 0x4000) && ((*(s8 *)((u8 *)(temp_17) + (0x14))) == 0)) {
                func_0045af60(0, 0, 0, 0);
                temp_2_77 = (s16)(func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, func_002e26a0(), 0, 2));
                (*(s16 *)((u8 *)(temp_17) + (2))) = temp_2_77;
                if (((s64) ((s64) temp_2_77 << 0x30) >> 0x30) == 0) {
                    (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                } else if (func_002e26a0() >= 5) {
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e26a0() << 0x30) >> 0x30, 5, 1);
                } else {
                    temp_16_57 = (s64) (func_002e26a0() << 0x30) >> 0x30;
                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), temp_16_57, (s64) (func_002e2670() << 0x30) >> 0x30, 1);
                }
                (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                return 0;
            }
            if (D_008C027A & 0x4000) {
                if (func_002e2670() > 0) {
                    temp_16_58 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
                    if (temp_16_58 != func_002e26a0()) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 1, func_002e26a0(), 0, 1);
                    if (func_002e26a0() >= 5) {
                        (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), (s64) (func_002e26a0() << 0x30) >> 0x30, 5, 1);
                    } else {
                        temp_16_59 = (s64) (func_002e26a0() << 0x30) >> 0x30;
                        (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2d50((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), temp_16_59, (s64) (func_002e2670() << 0x30) >> 0x30, 1);
                    }
                    (*(s8 *)((u8 *)(temp_17) + (0x14))) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C027A & 2) || (D_008C027A & 0x2000)) {
                temp_16_60 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
                if (temp_16_60 != func_002e26a0()) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), func_002e2670(), 5, temp_17 + 2, temp_17 + 4);
            } else if ((D_008C027A & 1) || (D_008C027A & 0x8000)) {
                if ((*(s16 *)((u8 *)(temp_17) + (2))) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2f90((*(s16 *)((u8 *)(temp_17) + (2))), (*(s16 *)((u8 *)(temp_17) + (4))), func_002e2670(), 5, temp_17 + 2, temp_17 + 4);
            } else if (D_008C027A & 8) {
                (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
                (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (8))), 1, (*(s8 *)((u8 *)(temp_17) + (9))) - 1, 0, 2);
                temp_2_78 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
                switch (temp_2_78) {                /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_3_16 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                    func_002e2a10(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_16) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_16) + (0xF73))) + 4), 2, 2);
                    break;
                case 1:                             /* switch 4 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                case 2:                             /* switch 4 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C027A & 4) {
                (*(s16 *)((u8 *)(temp_17) + (2))) = 0;
                (*(s16 *)((u8 *)(temp_17) + (4))) = 0;
                (*(s8 *)((u8 *)(temp_17) + (8))) = func_002b2d00((*(s8 *)((u8 *)(temp_17) + (8))), 1, 0, (*(s8 *)((u8 *)(temp_17) + (9))) - 1, 2);
                temp_2_79 = (s8)((*(s8 *)((u8 *)(temp_17) + (7))));
                switch (temp_2_79) {                /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    temp_3_17 = (u8 *)((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17);
                    func_002e2a10(1 << ((s64) (((*(s8 *)((u8 *)(temp_3_17) + (0xF7C))) - 0x14) << 0x30) >> 0x30), 1 << ((*(s8 *)((u8 *)(temp_3_17) + (0xF73))) + 4), 2, 2);
                    break;
                case 1:                             /* switch 5 */
                    func_002e2a10(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                case 2:                             /* switch 5 */
                    func_002e2a10(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)((u8 *)(temp_17) + (8))) + temp_17)) + (0xF73))) + 4), 2, 2);
                    break;
                }
                func_002caef0(arg0);
                func_002d8200(arg0, 0);
                func_0045af60(0, 0, 0, 5);
            } else if (D_008C024E & 0x20) {
                func_002d3ee0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x22;
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))))) + (0xC4))), 0.0f);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))))) + (0xC4))), 0.0f);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E & 0x80) {
                func_002d3ee0(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x22;
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE2C)))))) + (0xC4))), 0.0f);
                func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))), 0, 2, 0, (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE30)))))) + (0xC4))), 0.0f);
                func_0045af60(0, 1, 0, 4);
            } else if (D_008C024E & 0x40) {
                if (func_002e2670() > 0) {
                    temp_16_61 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
                    if ((func_002e7a60() >= temp_16_61) && ((func_00106600((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30) & 0xFF) < 0x63)) {
                        sp688 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
                        sp68C = 0;
                        (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 1, &sp688, 1);
                        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x23;
                        func_0045af60(0, 0, 0, 1);
                    } else {
                        func_0045af60(0, 0, 0, 8);
                    }
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            }
block_368:
            (*(s8 *)((u8 *)(temp_17) + (0x14))) = 0;
            goto block_626;
        }
        goto block_626;
    case 0x22:                                      /* switch 1 */
        func_002b2970(&sp330, (((f32) 0x24E)), 0x42740000U);
        fclWriteColorBytes(&sp6F8, 0xFF, 0xFF, 0xFF, 0xFFU);
        temp_18_49 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
        temp_16_62 = (s64)(s32)(func_0046a770(&D_0063FAA0));
        func_002cacd0(sp330, (s32) sp6F8, (*(RGBA *)&(u32){0x11}), 5, temp_18_49, 0x70, 0x7A, temp_16_62, 1.0f, (s32)func_0046a770(&D_0063FAA0), 0xAA);
        func_002cb6c0(arg0, 0);
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD70))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xD7C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90))))) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1B;
        }
        goto block_626;
    case 0x23:                                      /* switch 1 */
        func_002d1590(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
            func_0045af60(0, 0, 0, 6);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_002d3ee0(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC8)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
            sp680 = (s32)(func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))));
            sp684 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 4, &sp680, 1);
            func_002d6190(arg0);
            temp_16_63 = (u32)(func_00106a90((s64) (func_002e2740((*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30));
            func_002e7a80(func_002e7a60() - temp_16_63);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x1E;
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x21;
        }
        goto block_626;
    case 0x24:                                      /* switch 1 */
        (*(s16 *)((u8 *)(temp_17) + (0x12))) = 1;
        if (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC64))))) << 0x38) >> 0x38) == 0) {
            func_002cdf80(arg0, 0);
        }
        goto block_626;
    case 0x25:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
loop_401:
        if (((s64) (var_19 << 0x30) >> 0x30) < 2) {
            temp_18_50 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_16_64 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_21 = (u8 *)(temp_17 + (((s64) (var_19 << 0x30) >> 0x30) * 4));
            temp_2_80 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF3E))));
            if ((s32) temp_2_80 >= 0) {
                var_f12_10 = (f32) temp_2_80;
            } else {
                var_f12_10 = 2.0f * (f32) ((temp_2_80 >> 1) | (temp_2_80 & 1));
            }
            temp_f0_12 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_10)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_12 >= 2.1474836e9f)) {
                var_3_12 = ((s32)(temp_f0_12)) & 0xFF;
            } else {
                var_3_12 = (((s32)((temp_f0_12 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x79))) = var_3_12;
            (*(s8 *)((u8 *)(temp_18_50) + (0x79))) = var_3_12;
            temp_2_81 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF3F))));
            if ((s32) temp_2_81 >= 0) {
                var_f12_11 = (f32) temp_2_81;
            } else {
                var_f12_11 = 2.0f * (f32) ((temp_2_81 >> 1) | (temp_2_81 & 1));
            }
            temp_f0_13 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_11)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_13 >= 2.1474836e9f)) {
                var_3_13 = ((s32)(temp_f0_13)) & 0xFF;
            } else {
                var_3_13 = (((s32)((temp_f0_13 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x7A))) = var_3_13;
            (*(s8 *)((u8 *)(temp_18_50) + (0x7A))) = var_3_13;
            temp_2_82 = (u8)((*(u8 *)((u8 *)(temp_21) + (0xF40))));
            if ((s32) temp_2_82 >= 0) {
                var_f12_12 = (f32) temp_2_82;
            } else {
                var_f12_12 = 2.0f * (f32) ((temp_2_82 >> 1) | (temp_2_82 & 1));
            }
            temp_f0_14 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_12)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_14 >= 2.1474836e9f)) {
                var_3_14 = ((s32)(temp_f0_14)) & 0xFF;
            } else {
                var_3_14 = (((s32)((temp_f0_14 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_16_64) + (0x7B))) = var_3_14;
            (*(s8 *)((u8 *)(temp_18_50) + (0x7B))) = var_3_14;
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_401;
        }
        temp_4_10 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_10 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_10, 1, 6, 0, 1);
        } else {
            temp_2_83 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_3 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_4 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_83) + (0x79))) = temp_6_3;
            (*(u8 *)((u8 *)(temp_2_83) + (0x7A))) = temp_5_4;
            (*(u8 *)((u8 *)(temp_2_83) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_83) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_84 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_4 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_5 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_84) + (0x79))) = temp_6_4;
            (*(u8 *)((u8 *)(temp_2_84) + (0x7A))) = temp_5_5;
            (*(u8 *)((u8 *)(temp_2_84) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_84) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_3_18 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if ((temp_3_18 == 0) && ((*(s16 *)((u8 *)(temp_17) + (2))) == 0)) {
                var_19_4 = 0;
                var_18_5 = 1;
loop_408:
                temp_16_65 = (s64) (var_18_5 << 0x30) >> 0x30;
                if (temp_16_65 < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                    temp_2_85 = (s64)(s32)(func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_65));
                    temp_21_2 = func_00106a90((s64) (temp_2_85 << 0x30) >> 0x30) / 5U;
                    var_19_4 += temp_21_2 * (func_00106600((s64) (temp_2_85 << 0x30) >> 0x30) & 0xFF);
                    var_18_5 = (s64) ((var_18_5 + 1) << 0x30) >> 0x30;
                    goto loop_408;
                }
                sprintf(&spD0, D_00713910, func_002b2cb0(var_19_4, 0, 0x98967F, 0, 1));
                (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 6, &spD0, 1);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2E;
            } else if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_3_18 * 4) + temp_17)) + (0xF18))))) > 0) {
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0xFFU, 0, 0, 5, 0);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0xFFU, 0, 0, 5, 0);
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 0) {
                    temp_16_66 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2A));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0x56, 16.0f);
                    fclWriteColorBytes(&sp6F4, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_86 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0))))));
                    (*(u8 *)((u8 *)(temp_2_86) + (0x79))) = sp6F4;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7A))) = sp6F5;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7B))) = sp6F6;
                    (*(u8 *)((u8 *)(temp_2_86) + (0x7C))) = sp6F7;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_66));
                    0;
                    func_002b2970(&sp328, 0x427C0000U, 0);
                    func_002b2970(&sp320, 0x427C0000U, 0x430F0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), sp328, sp320, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE0)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_66));
                    temp_16_67 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2C));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0x56, 18.0f);
                    fclWriteColorBytes(&sp6F0, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_87 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8))))));
                    (*(u8 *)((u8 *)(temp_2_87) + (0x79))) = sp6F0;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7A))) = sp6F1;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7B))) = sp6F2;
                    (*(u8 *)((u8 *)(temp_2_87) + (0x7C))) = sp6F3;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_67));
                    0;
                    func_002b2970(&sp318, (((f32) 0x222)), 0);
                    func_002b2970(&sp310, (((f32) 0x222)), 0x430F0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), sp318, sp310, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_67));
                    temp_16_68 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x27));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 0x41, 20.0f);
                    fclWriteColorBytes(&sp6EC, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_88 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4))))));
                    (*(u8 *)((u8 *)(temp_2_88) + (0x79))) = sp6EC;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7A))) = sp6ED;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7B))) = sp6EE;
                    (*(u8 *)((u8 *)(temp_2_88) + (0x7C))) = sp6EF;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_68));
                    0;
                    func_002b2970(&sp308, 0x42380000U, 0);
                    func_002b2970(&sp300, 0x42380000U, 0x43040000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), sp308, sp300, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD4)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_68));
                    temp_16_69 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x29));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0x41, 21.0f);
                    fclWriteColorBytes(&sp6E8, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_89 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC))))));
                    (*(u8 *)((u8 *)(temp_2_89) + (0x79))) = sp6E8;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7A))) = sp6E9;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7B))) = sp6EA;
                    (*(u8 *)((u8 *)(temp_2_89) + (0x7C))) = sp6EB;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_69));
                    0;
                    func_002b2970(&sp2F8, (((f32) 0x232)), 0);
                    func_002b2970(&sp2F0, (((f32) 0x232)), 0x43040000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), sp2F8, sp2F0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_69));
                } else {
                    temp_16_70 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2B));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0x56, 16.0f);
                    fclWriteColorBytes(&sp6E4, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_90 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4))))));
                    (*(u8 *)((u8 *)(temp_2_90) + (0x79))) = sp6E4;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7A))) = sp6E5;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7B))) = sp6E6;
                    (*(u8 *)((u8 *)(temp_2_90) + (0x7C))) = sp6E7;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_70));
                    0;
                    func_002b2970(&sp2E8, 0x42860000U, 0);
                    func_002b2970(&sp2E0, 0x42860000U, 0x430C0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), sp2E8, sp2E0, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE4)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_70));
                    temp_16_71 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x2C));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0x56, 18.0f);
                    fclWriteColorBytes(&sp6E0, 0xFE, 0xC6, 0x31, 0xFFU);
                    temp_2_91 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8))))));
                    (*(u8 *)((u8 *)(temp_2_91) + (0x79))) = sp6E0;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7A))) = sp6E1;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7B))) = sp6E2;
                    (*(u8 *)((u8 *)(temp_2_91) + (0x7C))) = sp6E3;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0, 5, 0, 0x3F800000, 0x3F800000, 0.5f, 0x3F800000);
                    func_0046b2f0((void *)(temp_16_71));
                    0;
                    func_002b2970(&sp2D8, (((f32) 0x22F)), 0);
                    func_002b2970(&sp2D0, (((f32) 0x22F)), 0x430C0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), sp2D8, sp2D0, 0, 5, 0);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 0U, 0xFF, 0, 0, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCE8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_71));
                    temp_16_72 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x28));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 0x41, 20.0f);
                    fclWriteColorBytes(&sp6DC, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_92 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8))))));
                    (*(u8 *)((u8 *)(temp_2_92) + (0x79))) = sp6DC;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7A))) = sp6DD;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7B))) = sp6DE;
                    (*(u8 *)((u8 *)(temp_2_92) + (0x7C))) = sp6DF;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_72));
                    0;
                    func_002b2970(&sp2C8, 0x42400000U, 0);
                    func_002b2970(&sp2C0, 0x42400000U, 0x42FE0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), sp2C8, sp2C0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD8)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_72));
                    temp_16_73 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 0x29));
                    func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0x41, 21.0f);
                    fclWriteColorBytes(&sp6D8, 0xFF, 0x96, 0, 0xFFU);
                    temp_2_93 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC))))));
                    (*(u8 *)((u8 *)(temp_2_93) + (0x79))) = sp6D8;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7A))) = sp6D9;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7B))) = sp6DA;
                    (*(u8 *)((u8 *)(temp_2_93) + (0x7C))) = sp6DB;
                    func_002e06d0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 2, 4, 0, 0x3F800000, 0x3F800000, fGpffff8170, 0x3F800000);
                    func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 0U, 0xFF, 0, 4, 0);
                    func_0046b2f0((void *)(temp_16_73));
                    0;
                    func_002b2970(&sp2B8, 0x44120000U, 0);
                    func_002b2970(&sp2B0, 0x44120000U, 0x42FE0000U);
                    func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), sp2B8, sp2B0, 2, 4, 0);
                    func_002e09b0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCDC)))), 3, 6.0f);
                    func_0046d280((void *)(temp_16_73));
                }
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0x57, 14.0f);
                func_002b2970(&sp2A8, (*(f32 *)((u8 *)(&D_0063F688) + (0))), (((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
                func_002b2970(&sp2A0, (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp2A8, sp2A0, 1, 0xA, 2);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0U, 0xFF, 0, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x3B))) = 1;
                fclWriteColorBytes(&sp6D4, 0xFF, 0x96, 0, 0xFFU);
                temp_2_94 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC))))));
                (*(u8 *)((u8 *)(temp_2_94) + (0x79))) = sp6D4;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7A))) = sp6D5;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7B))) = sp6D6;
                (*(u8 *)((u8 *)(temp_2_94) + (0x7C))) = sp6D7;
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0x57, 15.0f);
                func_002b2970(&sp298, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
                func_002b2970(&sp290, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp298, sp290, 1, 0xA, 2);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0U, 0xFF, 0, 0xA, 2);
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x3B))) = 1;
                fclWriteColorBytes(&sp6D0, 0xFF, 0x96, 0, 0xFFU);
                temp_2_95 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0))))));
                (*(u8 *)((u8 *)(temp_2_95) + (0x79))) = sp6D0;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7A))) = sp6D1;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7B))) = sp6D2;
                (*(u8 *)((u8 *)(temp_2_95) + (0x7C))) = sp6D3;
                (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0x57, 15.0f);
                fclWriteColorBytes(&sp6CC, 0xDF, 0x6C, 0, 0xFFU);
                temp_2_96 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8))))));
                (*(u8 *)((u8 *)(temp_2_96) + (0x79))) = sp6CC;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7A))) = sp6CD;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7B))) = sp6CE;
                (*(u8 *)((u8 *)(temp_2_96) + (0x7C))) = sp6CF;
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0U, 0xFF, 0, 4, 2);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x27;
            }
        }
        goto block_626;
    case 0x27:                                      /* switch 1 */
        temp_16_74 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_18_51 = (s32)(func_002e28f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) & 0xFF);
        func_002cdf80(arg0, 2);
        func_002df020(arg0, temp_16_74, temp_18_51);
        func_002dd3b0(arg0);
        if (D_008C027A & 0x1000) {
            temp_18_52 = (s16)((*(s16 *)((u8 *)(temp_17) + (0x12))));
            if (temp_18_52 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 1, func_00106600(temp_16_74) & 0xFF, 1, 1);
            func_002b2970(&sp288, (*(f32 *)((u8 *)(&D_0063F688) + (0))), (((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
            func_002b2970(&sp280, (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp288, sp280, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x2000) {
            temp_18_53 = (s16)((*(s16 *)((u8 *)(temp_17) + (0x12))));
            if (temp_18_53 != (func_00106600(temp_16_74) & 0xFF)) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xA, func_00106600(temp_16_74) & 0xFF, 1, 1);
            func_002b2970(&sp278, (*(f32 *)((u8 *)(&D_0063F688) + (0))), (((*(f32 *)((u8 *)(&D_0063F688) + (4))))));
            func_002b2970(&sp270, (*(f32 *)((u8 *)(&D_0063F688) + (0))), ((((*(f32 *)((u8 *)(&D_0063F688) + (4))) - 7.0f))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), sp278, sp270, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x4000) {
            if ((*(s16 *)((u8 *)(temp_17) + (0x12))) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 1, 1, func_00106600(temp_16_74) & 0xFF, 1);
            func_002b2970(&sp268, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
            func_002b2970(&sp260, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp268, sp260, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
        } else if (D_008C027A & 0x8000) {
            if ((*(s16 *)((u8 *)(temp_17) + (0x12))) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            (*(s16 *)((u8 *)(temp_17) + (0x12))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xA, 1, func_00106600(temp_16_74) & 0xFF, 1);
            func_002b2970(&sp258, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((*(f32 *)((u8 *)(&D_0063F690) + (4))))));
            func_002b2970(&sp250, (*(f32 *)((u8 *)(&D_0063F690) + (0))), (((7.0f + (*(f32 *)((u8 *)(&D_0063F690) + (4)))))));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), sp258, sp250, 1, 0xA, 0);
            (*(s8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))))) + (0x85))) = 1;
        } else if (D_008C024E & 0x40) {
            sp678 = (s32) ((s64) (temp_16_74 << 0x30) >> 0x30);
            sp67C = 0;
            sprintf(&spC0, D_00713910, (s8) (*(s16 *)((u8 *)(temp_17) + (0x12))));
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dff90(arg0, 2, &sp678, &spC0, 1);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x28;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E & 0x20) {
            func_0045af60(0, 0, 0, 2);
            func_002df4c0(arg0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0xFFU, 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0xFFU, 0, 0, 5, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0, 1);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0U, 0xFF, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0U, 0xFF, 0, 5, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
            if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
            }
        }
        goto block_626;
    case 0x28:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        temp_19_7 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_16_75 = (s64) (func_002e28f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), (s64) (*(s16 *)((u8 *)(temp_17) + (2)))) << 0x30) >> 0x30;
        temp_18_54 = (s64)(s32)(func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))));
        temp_23_2 = (s16)((*(s16 *)((u8 *)(temp_17) + (2))));
        temp_30 = (s16)((*(s16 *)((u8 *)(temp_17) + (4))));
        func_002df020(arg0, temp_19_7, temp_16_75 & 0xFF);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            (*(s16 *)((u8 *)(temp_17) + (0xC16))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = 0;
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_0045af60(0, 0, 0, 6);
                if (func_00106850(temp_19_7) == 5) {
                    temp_16_76 = (s64) (temp_19_7 << 0x30) >> 0x30;
                    func_00110810(temp_16_76, func_002b2cb0(clndGetMoonPhase(temp_16_76) & 0xFF, (s64) (*(s16 *)((u8 *)(temp_17) + (0x12))), 0xFF, 0, 1) & 0xFF);
                    var_16_20 = 0;
loop_446:
                    temp_4_11 = (s64) (var_16_20 << 0x30) >> 0x30;
                    if (temp_4_11 < 0x2FF) {
                        if (!(clndGetMoonPhase(temp_4_11) & 0xFF)) {
                            temp_21_3 = (s32) (func_00106b20(var_16_20) & 0xFFF00) >> 8;
                            if (func_002be160(temp_21_3, func_00106b20(var_16_20) & 0xFF) == 1) {
                                temp_21_4 = (s32) (func_00106b50(var_16_20) & 0xFFF00) >> 8;
                                if (func_002be160(temp_21_4, func_00106b50(var_16_20) & 0xFF) == 1) {
                                    (*(s16 *)((u8 *)((temp_17 + ((*(s16 *)((u8 *)(temp_17) + (0xC16))) * 2))) + (0x16))) = (s16) var_16_20;
                                    (*(s16 *)((u8 *)(temp_17) + (0xC16))) = (s16) ((*(s16 *)((u8 *)(temp_17) + (0xC16))) + 1);
                                }
                            }
                        }
                        var_16_20 = (s64) ((var_16_20 + 1) << 0x30) >> 0x30;
                        goto loop_446;
                    }
                }
                temp_16_77 = func_00106a90((s64) (temp_19_7 << 0x30) >> 0x30) / 5U;
                func_002e7a80(func_002e7a60() + ((*(s16 *)((u8 *)(temp_17) + (0x12))) * temp_16_77));
                func_00106620(temp_19_7, ((func_00106600(temp_19_7) & 0xFF) - (*(s16 *)((u8 *)(temp_17) + (0x12)))) & 0xFF);
                temp_3_19 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
                switch (temp_3_19) {                /* switch 6; irregular */
                case 0:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0x40000, 0, 4, 0);
                    (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                    var_19_5 = 1;
loop_453:
                    if (((s64) (var_19_5 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                        temp_16_78 = (s64) (var_19_5 << 0x30) >> 0x30;
                        temp_21_5 = (s64) (func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_78) << 0x30) >> 0x30;
                        func_002e28f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_78);
                        temp_16_79 = (s64) (temp_21_5 << 0x30) >> 0x30;
                        temp_22_2 = clndGetMoonPhase(temp_16_79) & 0xFF;
                        func_002b2cb0(temp_22_2, func_00106600(temp_21_5) & 0xFF, 0xFF, 0, 1);
                        temp_16_80 = func_00106a90((s64) (temp_16_79 << 0x30) >> 0x30) / 5U;
                        temp_4_12 = (s32)((*(s32 *)((u8 *)(temp_17) + (0xC20))) + (temp_16_80 * (func_00106600(temp_21_5) & 0xFF)));
                        (*(s32 *)((u8 *)(temp_17) + (0xC20))) = temp_4_12;
                        (*(s32 *)((u8 *)(temp_17) + (0xC20))) = func_002b2cb0((s8) temp_4_12, 0, 0x98967F, 0, 1);
                        var_19_5 = (s64) ((var_19_5 + 1) << 0x30) >> 0x30;
                        goto loop_453;
                    }
                    break;
                case 1:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:                             /* switch 6 */
                    func_002e3560((void *)((*(s32 *)((u8 *)(((temp_3_19 * 4) + temp_17)) + (0xF18)))), 0x10000, 0, 1, 0);
                    break;
                }
                if (temp_18_54 != func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))))) {
                    temp_4_13 = (s64) ((s64) temp_23_2 << 0x30) >> 0x30;
                    if ((temp_4_13 - ((s64) ((s64) temp_30 << 0x30) >> 0x30)) > 0) {
                        temp_16_81 = (s64) (func_002b2d00((s8) temp_4_13, 1, 0, 0, 1) << 0x30) >> 0x30;
                        (*(s16 *)((u8 *)(temp_17) + (2))) = 0;                        func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                        (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), (s64) (temp_16_81 << 0x30) >> 0x30,0, 0, 1);
                    } else {                        func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                        (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 0,0, 0, 1);
                    }                    func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (4))), 0,0, 0, 1);
                }
                func_002d4760(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))));
            }
            func_002df4c0(arg0);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCCC)))), 0xFFU, 0, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xCD0)))), 0xFFU, 0, 0, 5, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC8)))), 0, 1);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 0U, 0xFF, 0, 5, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 0U, 0xFF, 0, 5, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
            if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                if (D_00748908[(*(s8 *)((u8 *)(temp_17) + (0x11)))] >= func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))))) {
                    func_002d8600(arg0);
                } else {
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
                }
            }
            if ((*(s16 *)((u8 *)(temp_17) + (0xC16))) > 0) {
                (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
                func_002dfe00(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
            }
        }
        goto block_626;
    case 0x2E:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            (*(s16 *)((u8 *)(temp_17) + (0xC16))) = 0;
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = 0;
            if (func_002bb1c0((*(s8 *)((u8 *)(temp_17) + (0x10)))) == 0) {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                func_0045af60(0, 0, 0, 6);
                var_18_6 = 1;
loop_474:
                if (((s64) (var_18_6 << 0x30) >> 0x30) < func_002e26f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))))) {
                    temp_16_82 = (s64) (var_18_6 << 0x30) >> 0x30;
                    temp_19_8 = (s64)(s32)(func_002e2830((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_82));
                    func_002e28f0((void *)((*(s32 *)((u8 *)((temp_17 + ((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4))) + (0xF18)))), temp_16_82);
                    temp_16_83 = clndGetMoonPhase(temp_19_8) & 0xFF;
                    func_00110810(temp_19_8, func_002b2cb0(temp_16_83, func_00106600((s64) (temp_19_8 << 0x30) >> 0x30) & 0xFF, 0xFF, 0, 1) & 0xFF);
                    temp_16_84 = func_00106a90((s64) (temp_19_8 << 0x30) >> 0x30) / 5U;
                    temp_16_85 = temp_16_84 * (func_00106600((s64) (temp_19_8 << 0x30) >> 0x30) & 0xFF);
                    func_002e7a80(func_002e7a60() + temp_16_85);
                    func_00106620((s64) (temp_19_8 << 0x30) >> 0x30, 0);
                    var_18_6 = (s64) ((var_18_6 + 1) << 0x30) >> 0x30;
                    goto loop_474;
                }
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;
                var_16_21 = 0;
loop_481:
                temp_4_14 = (s64) (var_16_21 << 0x30) >> 0x30;
                if (temp_4_14 < 0x2FF) {
                    if (!(clndGetMoonPhase(temp_4_14) & 0xFF)) {
                        temp_18_55 = (s32) (func_00106b20(var_16_21) & 0xFFF00) >> 8;
                        if (func_002be160(temp_18_55, func_00106b20(var_16_21) & 0xFF) == 1) {
                            temp_18_56 = (s32) (func_00106b50(var_16_21) & 0xFFF00) >> 8;
                            if (func_002be160(temp_18_56, func_00106b50(var_16_21) & 0xFF) == 1) {
                                (*(s16 *)((u8 *)((temp_17 + ((*(s16 *)((u8 *)(temp_17) + (0xC16))) * 2))) + (0x16))) = (s16) var_16_21;
                                (*(s16 *)((u8 *)(temp_17) + (0xC16))) = (s16) ((*(s16 *)((u8 *)(temp_17) + (0xC16))) + 1);
                            }
                        }
                    }
                    var_16_21 = (s64) ((var_16_21 + 1) << 0x30) >> 0x30;
                    goto loop_481;
                }
                func_002e3560((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18)))), 0x40000, 0, 4, 0);
                (*(s32 *)((u8 *)(temp_17) + (0xC20))) = 0;                func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                (*(s16 *)((u8 *)(temp_17) + (2))) = func_002b2cb0((s8) (*(s16 *)((u8 *)(temp_17) + (2))), 0,0, 0, 1);
                temp_18_57 = (s16)((*(s16 *)((u8 *)(temp_17) + (4))));
                temp_16_86 = (s64)(s32)(func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))));                func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                if (func_002b32a0((*(s16 *)((u8 *)(temp_17) + (4))), 5, temp_16_86,0) < temp_18_57) {
                    temp_16_87 = (s64) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) << 0x30) >> 0x30;                    func_002e2700((*(void **)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))));

                    (*(s16 *)((u8 *)(temp_17) + (4))) = func_002b32a0((*(s16 *)((u8 *)(temp_17) + (4))), 5, temp_16_87,0);
                }
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE40)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE44)))), 0, 1);
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE48)))), 0, 1);
                func_002d4760(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))));
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    func_002d8600(arg0);
                }
                if ((*(s16 *)((u8 *)(temp_17) + (0xC16))) > 0) {
                    (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
                    func_002dfe00(arg0);
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
                }
            } else {
                func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    func_002d8600(arg0);
                }
            }
        }
        goto block_626;
    case 0x29:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            func_0045aeb0(2, (const char *)&D_0063FAF0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2A;
        }
        goto block_626;
    case 0x2A:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        temp_2_97 = (s8)(func_002b2cb0((*(s8 *)((u8 *)(temp_17) + (0xC1A))), 1, 0x3C, 0, 1));
        (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = temp_2_97;
        if (((s64) ((s64) temp_2_97 << 0x38) >> 0x38) >= 0x3C) {
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 0xA, NULL, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2B;
            (*(s8 *)((u8 *)(temp_17) + (0xC1A))) = 0;
        }
        goto block_626;
    case 0x2B:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            sp670 = (s32) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)));
            sp674 = 0;
            (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 3, &sp670, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2D;
        }
        goto block_626;
    case 0x2C:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        sp668 = (s32) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)));
        sp66C = 0;
        (*(s8 *)((u8 *)(temp_17) + (0x10))) = func_002dfec0(arg0, 3, &sp668, 0);
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2D;
        goto block_626;
    case 0x2D:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        func_002dd3b0(arg0);
        if (func_002bb680((*(s8 *)((u8 *)(temp_17) + (0x10)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17) + (0x10))));
        } else {
            func_00110810((s64) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16))), ((clndGetMoonPhase((s64) (*(s16 *)((u8 *)((((*(s16 *)((u8 *)(temp_17) + (0xC18))) * 2) + temp_17)) + (0x16)))) & 0xFF) | 1) & 0xFF);
            func_002bb550((*(s8 *)((u8 *)(temp_17) + (0x10))));
            temp_2_98 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xC18))) + 1);
            (*(s16 *)((u8 *)(temp_17) + (0xC18))) = temp_2_98;
            if (((s64) ((s64) temp_2_98 << 0x30) >> 0x30) >= (*(s16 *)((u8 *)(temp_17) + (0xC16)))) {
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
                if ((*(s8 *)((u8 *)(temp_17) + (0xC24))) == 1) {
                    (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
                }
            } else {
                func_002dfe00(arg0);
                (*(s8 *)((u8 *)(temp_17) + (0))) = 0x29;
            }
        }
        goto block_626;
    case 0x26:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        var_20_2 = 0;
loop_525:
        if (((s64) (var_20_2 << 0x30) >> 0x30) < 2) {
            temp_19_9 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_18_58 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_88 = (u8 *)(temp_17 + (((s64) (var_20_2 << 0x30) >> 0x30) * 4));
            temp_2_99 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF3E))));
            if ((s32) temp_2_99 >= 0) {
                var_f12_13 = (f32) temp_2_99;
            } else {
                var_f12_13 = 2.0f * (f32) ((temp_2_99 >> 1) | (temp_2_99 & 1));
            }
            temp_f0_15 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_13)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_15 >= 2.1474836e9f)) {
                var_3_15 = ((s32)(temp_f0_15)) & 0xFF;
            } else {
                var_3_15 = (((s32)((temp_f0_15 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x79))) = var_3_15;
            (*(s8 *)((u8 *)(temp_19_9) + (0x79))) = var_3_15;
            temp_2_100 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF3F))));
            if ((s32) temp_2_100 >= 0) {
                var_f12_14 = (f32) temp_2_100;
            } else {
                var_f12_14 = 2.0f * (f32) ((temp_2_100 >> 1) | (temp_2_100 & 1));
            }
            temp_f0_16 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_14)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_16 >= 2.1474836e9f)) {
                var_3_16 = ((s32)(temp_f0_16)) & 0xFF;
            } else {
                var_3_16 = (((s32)((temp_f0_16 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x7A))) = var_3_16;
            (*(s8 *)((u8 *)(temp_19_9) + (0x7A))) = var_3_16;
            temp_2_101 = (u8)((*(u8 *)((u8 *)(temp_16_88) + (0xF40))));
            if ((s32) temp_2_101 >= 0) {
                var_f12_15 = (f32) temp_2_101;
            } else {
                var_f12_15 = 2.0f * (f32) ((temp_2_101 >> 1) | (temp_2_101 & 1));
            }
            temp_f0_17 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_15)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_17 >= 2.1474836e9f)) {
                var_3_17 = ((s32)(temp_f0_17)) & 0xFF;
            } else {
                var_3_17 = (((s32)((temp_f0_17 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_58) + (0x7B))) = var_3_17;
            (*(s8 *)((u8 *)(temp_19_9) + (0x7B))) = var_3_17;
            var_20_2 = (s64) ((var_20_2 + 1) << 0x30) >> 0x30;
            goto loop_525;
        }
        temp_4_15 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_15 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_15, 1, 6, 0, 1);
        } else {
            temp_2_102 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_5 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_102) + (0x79))) = temp_6_5;
            (*(u8 *)((u8 *)(temp_2_102) + (0x7A))) = temp_5_6;
            (*(u8 *)((u8 *)(temp_2_102) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_102) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_103 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_6 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_7 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_103) + (0x79))) = temp_6_6;
            (*(u8 *)((u8 *)(temp_2_103) + (0x7A))) = temp_5_7;
            (*(u8 *)((u8 *)(temp_2_103) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_103) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_2_104 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_f1_2 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_104) + (0x2C))));
            sp660 = temp_f1_2;
            sp664 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_104) + (0x30))));
            func_002b2970(&sp248, (((temp_f1_2 - 1000.0f))), sp664);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), ((s64)(sp660)), sp248, 1, 3, 0);
            temp_2_105 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_f1_3 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_105) + (0x2C))));
            sp160 = temp_f1_3;
            sp164 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_105) + (0x30))));
            func_002b2970(&sp240, (((temp_f1_3 - 1000.0f))), sp164);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), ((s64)(sp160)), sp240, 1, 3, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x2F;
        }
        goto block_626;
    case 0x2F:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        var_20_3 = 0;
loop_549:
        if (((s64) (var_20_3 << 0x30) >> 0x30) < 2) {
            temp_19_10 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_18_59 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_16_89 = (u8 *)(temp_17 + (((s64) (var_20_3 << 0x30) >> 0x30) * 4));
            temp_2_106 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF3E))));
            if ((s32) temp_2_106 >= 0) {
                var_f12_16 = (f32) temp_2_106;
            } else {
                var_f12_16 = 2.0f * (f32) ((temp_2_106 >> 1) | (temp_2_106 & 1));
            }
            temp_f0_18 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_16)), 255.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_18 >= 2.1474836e9f)) {
                var_3_18 = ((s32)(temp_f0_18)) & 0xFF;
            } else {
                var_3_18 = (((s32)((temp_f0_18 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x79))) = var_3_18;
            (*(s8 *)((u8 *)(temp_19_10) + (0x79))) = var_3_18;
            temp_2_107 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF3F))));
            if ((s32) temp_2_107 >= 0) {
                var_f12_17 = (f32) temp_2_107;
            } else {
                var_f12_17 = 2.0f * (f32) ((temp_2_107 >> 1) | (temp_2_107 & 1));
            }
            temp_f0_19 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_17)), 226.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_19 >= 2.1474836e9f)) {
                var_3_19 = ((s32)(temp_f0_19)) & 0xFF;
            } else {
                var_3_19 = (((s32)((temp_f0_19 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x7A))) = var_3_19;
            (*(s8 *)((u8 *)(temp_19_10) + (0x7A))) = var_3_19;
            temp_2_108 = (u8)((*(u8 *)((u8 *)(temp_16_89) + (0xF40))));
            if ((s32) temp_2_108 >= 0) {
                var_f12_18 = (f32) temp_2_108;
            } else {
                var_f12_18 = 2.0f * (f32) ((temp_2_108 >> 1) | (temp_2_108 & 1));
            }
            temp_f0_20 = (f32)(s32)(func_002b2aa0(1, ((s8)(var_f12_18)), 145.0f, (f32) (*(s16 *)((u8 *)(temp_17) + (0xF3C))), 3.0f));
            if (!(temp_f0_20 >= 2.1474836e9f)) {
                var_3_20 = ((s32)(temp_f0_20)) & 0xFF;
            } else {
                var_3_20 = (((s32)((temp_f0_20 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            (*(s8 *)((u8 *)(temp_18_59) + (0x7B))) = var_3_20;
            (*(s8 *)((u8 *)(temp_19_10) + (0x7B))) = var_3_20;
            var_20_3 = (s64) ((var_20_3 + 1) << 0x30) >> 0x30;
            goto loop_549;
        }
        temp_4_16 = (s16)((*(s16 *)((u8 *)(temp_17) + (0xF3C))));
        if (temp_4_16 < 6) {
            (*(s16 *)((u8 *)(temp_17) + (0xF3C))) = func_002b2cb0((s8) temp_4_16, 1, 6, 0, 1);
        } else {
            temp_2_109 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_6_7 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3E))));
            temp_5_8 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF3F))));
            (*(u8 *)((u8 *)(temp_2_109) + (0x79))) = temp_6_7;
            (*(u8 *)((u8 *)(temp_2_109) + (0x7A))) = temp_5_8;
            (*(u8 *)((u8 *)(temp_2_109) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF40)));
            (*(u8 *)((u8 *)(temp_2_109) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF41)));
            temp_2_110 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_6_8 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF42))));
            temp_5_9 = (u8)((*(u8 *)((u8 *)(temp_17) + (0xF43))));
            (*(u8 *)((u8 *)(temp_2_110) + (0x79))) = temp_6_8;
            (*(u8 *)((u8 *)(temp_2_110) + (0x7A))) = temp_5_9;
            (*(u8 *)((u8 *)(temp_2_110) + (0x7B))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF44)));
            (*(u8 *)((u8 *)(temp_2_110) + (0x7C))) = (u8) (*(u8 *)((u8 *)(temp_17) + (0xF45)));
            temp_2_111 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            temp_f1_4 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_111) + (0x2C))));
            sp658 = temp_f1_4;
            sp65C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_111) + (0x30))));
            func_002b2970(&sp238, (((temp_f1_4 - 1000.0f))), sp65C);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), ((s64)(sp658)), sp238, 1, 3, 0);
            temp_2_112 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            temp_f1_5 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_112) + (0x2C))));
            sp158 = temp_f1_5;
            sp15C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_112) + (0x30))));
            func_002b2970(&sp230, (((temp_f1_5 - 1000.0f))), sp15C);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), ((s64)(sp158)), sp230, 1, 3, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50)))), 0x41, 109.0f);
            func_002b2970(&sp228, (((f32) -0x271)), 0x42F80000U);
            func_002b2970(&sp220, 0x42960000U, 0x42F80000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50)))), sp228, sp220, 0, 4, 5);
            fclWriteColorBytes(&sp6C8, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_113 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50))))));
            (*(u8 *)((u8 *)(temp_2_113) + (0x79))) = sp6C8;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7A))) = sp6C9;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7B))) = sp6CA;
            (*(u8 *)((u8 *)(temp_2_113) + (0x7C))) = sp6CB;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54)))), 0x41, ((f32)(sp6C8)));
            func_002b2970(&sp218, (((f32) -0x271)), (((f32) 0x11D)));
            func_002b2970(&sp210, 0x42960000U, (((f32) 0x11D)));
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54)))), sp218, sp210, 0, 4, 5);
            fclWriteColorBytes(&sp6C4, 0xFF, 0xCB, 0x35, 0xFFU);
            temp_2_114 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54))))));
            (*(u8 *)((u8 *)(temp_2_114) + (0x79))) = sp6C4;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7A))) = sp6C5;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7B))) = sp6C6;
            (*(u8 *)((u8 *)(temp_2_114) + (0x7C))) = sp6C7;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58)))), 0x41, ((f32)(sp6C4)));
            func_002b2970(&sp208, 0xC2EA0000U, 0x43000000U);
            func_002b2970(&sp200, (((f32) 0x247)), 0x43000000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58)))), sp208, sp200, 0, 4, 5);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C)))), 0x41, 114.0f);
            func_002b2970(&sp1F8, (((f32) -0x2FD)), 0x43000000U);
            func_002b2970(&sp1F0, 0xC2820000U, 0x43000000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C)))), sp1F8, sp1F0, 0, 4, 5);
            (*(s8 *)((u8 *)(temp_17) + (0xC24))) = 1;
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x30;
        }
        goto block_626;
    case 0x30:                                      /* switch 1 */
        func_002cdf80(arg0, 2);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), 9) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE54))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE58))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE5C))))) << 0x38) >> 0x38) == 0)) {
            var_16_22 = 0;
loop_561:
            if (((s64) (var_16_22 << 0x30) >> 0x30) < 3) {
                temp_3_20 = (u8 *)(temp_17 + (((s64) (var_16_22 << 0x30) >> 0x30) * 4));
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_20) + (0xDBC)))), 0x41, 95.0f);
                fclWriteColorBytes(&sp6C0, 0xFF, 0xEF, 0x80, 0xFFU);
                temp_2_115 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_20) + (0xDBC))))));
                (*(u8 *)((u8 *)(temp_2_115) + (0x79))) = sp6C0;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7A))) = sp6C1;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7B))) = sp6C2;
                (*(u8 *)((u8 *)(temp_2_115) + (0x7C))) = sp6C3;
                var_16_22 = (s64) ((var_16_22 + 1) << 0x30) >> 0x30;
                goto loop_561;
            }
            func_002b2970(&sp1E8, 0x42B20000U, 0x43230000U);
            temp_2_116 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDBC))))));
            (*(f32 *)((u8 *)(temp_2_116) + (0x2C))) = (f32) sp1E8;
            (*(f32 *)((u8 *)(temp_2_116) + (0x30))) = unksp1EC;
            func_002b2970(&sp1E0, (((f32) 0x1D1)), 0x43230000U);
            temp_2_117 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC0))))));
            (*(f32 *)((u8 *)(temp_2_117) + (0x2C))) = (f32) sp1E0;
            (*(f32 *)((u8 *)(temp_2_117) + (0x30))) = unksp1E4;
            func_002b2970(&sp1D8, (((f32) 0x22E)), 0x43230000U);
            temp_2_118 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDC4))))));
            (*(f32 *)((u8 *)(temp_2_118) + (0x2C))) = (f32) sp1D8;
            (*(f32 *)((u8 *)(temp_2_118) + (0x30))) = unksp1DC;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC)))), 0x56, 91.0f);
            func_002b2970(&sp1D0, (((f32) 0x1DF)), 0x43270000U);
            temp_2_119 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC))))));
            (*(f32 *)((u8 *)(temp_2_119) + (0x2C))) = (f32) sp1D0;
            (*(f32 *)((u8 *)(temp_2_119) + (0x30))) = unksp1D4;
            fclWriteColorBytes(&sp6BC, 0xFE, 0xC7, 0x31, 0xFFU);
            temp_2_120 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCAC))))));
            (*(u8 *)((u8 *)(temp_2_120) + (0x79))) = sp6BC;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7A))) = sp6BD;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7B))) = sp6BE;
            (*(u8 *)((u8 *)(temp_2_120) + (0x7C))) = sp6BF;
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84)))), 0x56, ((f32)(sp6BC)));
            fclWriteColorBytes(&sp6B8, 0xFE, 0xC7, 0x31, 0xFFU);
            temp_2_121 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84))))));
            (*(u8 *)((u8 *)(temp_2_121) + (0x79))) = sp6B8;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7A))) = sp6B9;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7B))) = sp6BA;
            (*(u8 *)((u8 *)(temp_2_121) + (0x7C))) = sp6BB;
            func_002b2970(&sp1C8, (f32) 0x1DF, 217.0f);
            temp_2_122 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE84))))));
            (*(f32 *)((u8 *)(temp_2_122) + (0x2C))) = (f32) sp1C8;
            (*(f32 *)((u8 *)(temp_2_122) + (0x30))) = unksp1CC;
            if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 2) {
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94)))), 0x41, 88.0f);
                fclWriteColorBytes(&sp6B4, 0xFF, 0x96, 0, 0xFFU);
                temp_2_123 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94))))));
                (*(u8 *)((u8 *)(temp_2_123) + (0x79))) = sp6B4;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7A))) = sp6B5;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7B))) = sp6B6;
                (*(u8 *)((u8 *)(temp_2_123) + (0x7C))) = sp6B7;
                func_002b2970(&sp1C0, (f32) 0x247, 136.0f);
                temp_2_124 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC94))))));
                (*(f32 *)((u8 *)(temp_2_124) + (0x2C))) = (f32) sp1C0;
                (*(f32 *)((u8 *)(temp_2_124) + (0x30))) = unksp1C4;
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98)))), 0x41, 89.0f);
                fclWriteColorBytes(&sp6B0, 0xFF, 0x96, 0, 0xFFU);
                temp_2_125 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98))))));
                (*(u8 *)((u8 *)(temp_2_125) + (0x79))) = sp6B0;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7A))) = sp6B1;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7B))) = sp6B2;
                (*(u8 *)((u8 *)(temp_2_125) + (0x7C))) = sp6B3;
                func_002b2970(&sp1B8, (f32) 0x247, 272.0f);
                temp_2_126 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC98))))));
                (*(f32 *)((u8 *)(temp_2_126) + (0x2C))) = (f32) sp1B8;
                (*(f32 *)((u8 *)(temp_2_126) + (0x30))) = unksp1BC;
            }
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x31;
        }
        goto block_626;
    case 0x31:                                      /* switch 1 */
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA0)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA8)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC9C)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCA4)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xCB8)))), 0, 1);
        func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xEAC)))), 0, 1);
        func_002cdf80(arg0, 1);
        func_002dd3b0(arg0);
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xE38)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC4)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xCC0)))), 1) << 0x38) >> 0x38) == 0) && ((D_008C0276 & 0x80) || (D_008C0276 & 0x20))) {
            func_0045af60(0, 1, 0, 4);
            func_002d8600(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE4)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE0)))), 0, 1);
            temp_2_127 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC))))));
            sp650 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_127) + (0x2C))));
            sp654 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_127) + (0x30))));
            func_002b2970(&sp1B0, (700.0f + D_0063F888[0]), sp654);
            func_002b2970(&sp1A8, (D_0063F888[0]), sp654);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDCC)))), sp1B0, sp1A8, 1, 3, 2);
            temp_2_128 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0))))));
            sp150 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_128) + (0x2C))));
            sp154 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_128) + (0x30))));
            func_002b2970(&sp1A0, (700.0f + D_0063F890[0]), sp154);
            func_002b2970(&sp198, (D_0063F890[0]), sp154);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xDD0)))), sp1A0, sp198, 1, 3, 2);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x32:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        goto block_626;
    case 0x33:                                      /* switch 1 */
        if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 6) {
            temp_16_90 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if (D_00748908[temp_16_90] < func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_90 * 4) + temp_17)) + (0xF18)))))) {
                if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_90 * 4) + temp_17)) + (0xF18))))) >= 6) {
                    (*(f32 *)((u8 *)(temp_17) + (0xC))) = (f32) (104.0f / (f32) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) - 5));
                }
                0;
                func_002b2970(&sp190, (((f32) 0x221)), 0);
                temp_16_91 = func_002b2a30(0xFF, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36,(*(Vec2f *)&sp190), temp_16_91, (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, D_00794EA0);
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        } else {
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x116E))), 80.0f, (f32) 0x352);
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))), (f32) -0x352, 80.0f);
        temp_2_129 = (s16)(func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x1170))), 1, 0, 0, 1));
        (*(s16 *)((u8 *)(temp_17) + (0x1170))) = temp_2_129;
        if (((s64) ((s64) temp_2_129 << 0x30) >> 0x30) == 0) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x34:                                      /* switch 1 */
        if (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) >= 6) {
            temp_16_92 = (s8)((*(s8 *)((u8 *)(temp_17) + (0x11))));
            if (D_00748908[temp_16_92] < func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_92 * 4) + temp_17)) + (0xF18)))))) {
                if (func_002e26f0((void *)((*(s32 *)((u8 *)(((temp_16_92 * 4) + temp_17)) + (0xF18))))) >= 6) {
                    (*(f32 *)((u8 *)(temp_17) + (0xC))) = (f32) (104.0f / (f32) (func_002e26f0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (0x11))) * 4) + temp_17)) + (0xF18))))) - 5));
                }
                0;
                func_002b2970(&sp188, (((f32) 0x221)), 0);
                temp_16_93 = func_002b2a30(0xFF, 0xFEU, 0xC6U, 0x31U);
                func_002e0b20(0x36,(*(Vec2f *)&sp188), temp_16_93, (*(u8 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))))) + (0x62))), 0, 0, D_00794EA0);
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 0);
        } else {
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC8C)))), 0, 1);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC90)))), 0, 1);
        }
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x116E))), 80.0f, (f32) -0x352);
        func_002d8a60(arg0, (*(s8 *)((u8 *)(temp_17) + (0x11))), (f32) 0x352, 80.0f);
        temp_2_130 = (s16)(func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17) + (0x1170))), 1, 0, 0, 1));
        (*(s16 *)((u8 *)(temp_17) + (0x1170))) = temp_2_130;
        if (((s64) ((s64) temp_2_130 << 0x30) >> 0x30) == 0) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x24;
        }
        goto block_626;
    case 0x35:                                      /* switch 1 */
        if (func_00452380(&D_0063FB10) == 0) {
            var_16_23 = 0;
loop_593:
            temp_3_21 = (s64) (var_16_23 << 0x30) >> 0x30;
            if (temp_3_21 < 7) {
                func_002e04f0((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_21 * 4))) + (0xD20)))), 0, 0);
                var_16_23 = (s64) ((var_16_23 + 1) << 0x30) >> 0x30;
                goto loop_593;
            }
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 0);
            var_16_24 = 0;
loop_596:
            temp_3_22 = (s64) (var_16_24 << 0x30) >> 0x30;
            if (temp_3_22 < 3) {
                func_002e0660((void *)((*(s32 *)((u8 *)((temp_17 + (temp_3_22 * 4))) + (0xC38)))), 0U, 0xFF, 0, 0xA, 0);
                var_16_24 = (s64) ((var_16_24 + 1) << 0x30) >> 0x30;
                goto loop_596;
            }
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 0U, 0xFF, 0, 0xA, 0);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0x40, 191.0f);
            temp_2_131 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 5));
            temp_18_60 = (s64) (((s64)(func_0046b260((void *)(temp_2_131)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x100))) = (s16) temp_18_60;
            temp_18_61 = (s64) (((s64)(func_0046b2f0((void *)(temp_2_131)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))))) + (0x102))) = (s16) temp_18_61;
            func_0046d280((void *)(temp_2_131));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0U, 0xCC, 0, 4, 4);
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 0, 4, 4, 0.0f, fGpffff8520);
            func_002b2970(&sp180, 0xC3700000U, 0x43C80000U);
            func_002b2970(&sp178, 0xC3700000U, 0x439B0000U);
            func_002e0620((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), sp180, sp178, 0, 4, 4);
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0x40, 192.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x2C))) = 110.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x30))) = -50.0f;
            temp_2_132 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_18_62 = (s64) (((s64)(func_0046b260((void *)(temp_2_132)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x100))) = (s16) temp_18_62;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))))) + (0x102))) = 0;
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0, 4, 4, -90.0f, fGpffff8524);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 0U, 0xFF, 0, 4, 4);
            func_0046d280((void *)(temp_2_132));
            func_002e09e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0x40, 190.0f);
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x2C))) = 180.0f;
            (*(f32 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x30))) = 30.0f;
            temp_2_133 = (s32)(func_0046d200((void *)((*(s32 *)((u8 *)(temp_17) + (0xF28)))), 6));
            temp_16_94 = (s64) (((s64)(func_0046b260((void *)(temp_2_133)))) << 0x30) >> 0x30;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x100))) = (s16) temp_16_94;
            (*(s16 *)((u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))))) + (0x102))) = 0;
            func_0046d280((void *)(temp_2_133));
            func_002e0940((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0, 4, 2, -85.0f, fGpffff8528);
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C)))), 0U, 0xFF, 0, 4, 2);
            var_21_4 = 0;
loop_601:
            if (((s64) (var_21_4 << 0x30) >> 0x30) < 7) {
                temp_19_11 = (s64) (var_21_4 << 0x30) >> 0x30;
                temp_18_63 = (u8 *)((s32)&D_0063F560 + ((temp_19_11 + 0x3A) * 8));
                temp_3_23 = (u8 *)(temp_17 + (temp_19_11 * 4));
                func_002e09e0((void *)((*(s32 *)((u8 *)(temp_3_23) + (0xD20)))), 0x56, (f32) (temp_19_11 + 0x64));
                if (temp_19_11 > 0) {
                    fclWriteColorBytes(&sp6AC, 0xED, 0x80, 0, 0xFFU);
                    temp_2_134 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)(temp_3_23) + (0xD20))))));
                    (*(u8 *)((u8 *)(temp_2_134) + (0x79))) = sp6AC;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7A))) = sp6AD;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7B))) = sp6AE;
                    (*(u8 *)((u8 *)(temp_2_134) + (0x7C))) = sp6AF;
                }
                temp_2_135 = (u8 *)(temp_17 + (((s64) (var_21_4 << 0x30) >> 0x30) * 4));
                func_002b2970(&sp170, (((80.0f + (*(f32 *)((u8 *)(temp_18_63) + (0)))))), (*(f32 *)((u8 *)(temp_18_63) + (4))));
                func_002b2970(&sp168, (((*(f32 *)((u8 *)(temp_18_63) + (0))))), (*(f32 *)((u8 *)(temp_18_63) + (4))));
                func_002e0620((void *)((*(s32 *)((u8 *)(temp_2_135) + (0xD20)))), sp170, sp168, 0, 3, var_21_4);
                func_002e0660((void *)((*(s32 *)((u8 *)(temp_2_135) + (0xD20)))), 0U, 0xFF, 0, 3, var_21_4);
                var_21_4 = (s64) ((var_21_4 + 1) << 0x30) >> 0x30;
                goto loop_601;
            }
            fclWriteColorBytes(&sp6A8, 0x2D, 0x2D, 0x2D, 0xFFU);
            temp_2_136 = (u8 *)(func_002e04e0((void *)((*(s32 *)((u8 *)((((*(s8 *)((u8 *)(temp_17) + (7))) * 4) + temp_17)) + (0xD24))))));
            (*(u8 *)((u8 *)(temp_2_136) + (0x79))) = sp6A8;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7A))) = sp6A9;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7B))) = sp6AA;
            (*(u8 *)((u8 *)(temp_2_136) + (0x7C))) = sp6AB;
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC44)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
            func_002e0660((void *)((*(s32 *)((u8 *)(temp_17) + (0xC48)))), 0U, 0xFF, 0, 0, (s64) (*(s8 *)((u8 *)(temp_17) + (7))));
            func_002d7f90(arg0);
            func_002dd230(arg0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDE8)))), 0, 0);
            func_002e04f0((void *)((*(s32 *)((u8 *)(temp_17) + (0xDEC)))), 0, 0);
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x36;
        }
        goto block_626;
    case 0x36:                                      /* switch 1 */
        var_16_25 = 0x55;
loop_607:
        temp_3_24 = (s64) (var_16_25 << 0x30) >> 0x30;
        if (temp_3_24 < 0x58) {
            temp_2_137 = (u8 *)(temp_17 + (temp_3_24 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_137) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_137) + (0xC38)))), 3, 0);
            }
            var_16_25 = (s64) ((var_16_25 + 1) << 0x30) >> 0x30;
            goto loop_607;
        }
        var_16_26 = 0x59;
loop_612:
        temp_3_25 = (s64) (var_16_26 << 0x30) >> 0x30;
        if (temp_3_25 < 0x60) {
            temp_2_138 = (u8 *)(temp_17 + (temp_3_25 * 4));
            if (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_2_138) + (0xC38)))), 1) << 0x38) >> 0x38) == 0) {
                func_002e04f0((void *)((*(s32 *)((u8 *)(temp_2_138) + (0xC38)))), 3, 0);
            }
            var_16_26 = (s64) ((var_16_26 + 1) << 0x30) >> 0x30;
            goto loop_612;
        }
        if ((((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD8C)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD90)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xD94)))), 1) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C)))), 2) << 0x38) >> 0x38) == 0) && (((s64) (func_002e0570((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50)))), 2) << 0x38) >> 0x38) == 0)) {
            (*(s8 *)((u8 *)(temp_17) + (0))) = 0x10;
        }
        goto block_626;
    case 0x37:                                      /* switch 1 */
        if ((((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC4C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC50))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xE7C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC38))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC3C))))) << 0x38) >> 0x38) == 0) && (((s64) (func_002e05a0((void *)((*(s32 *)((u8 *)(temp_17) + (0xC40))))) << 0x38) >> 0x38) == 0)) {
            return -1;
        }
        goto block_626;
    }
}
#pragma opt_common_subs on


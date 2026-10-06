#include "fcl_scale_transition.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_smap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "fcl_draw_types.h"
extern void (*D_00887304[])(s32, void *);

extern void (*D_00887300[])(s32 state, s32 value);

extern void (*jtbl_008873EC[])(void *);

extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 D_00764640;   /* gp-relative, -0x4AB0 */
extern s32 D_00764644;   /* gp-relative, -0x4AAC */
extern s32 D_00764648;   /* gp-relative, -0x4AA8 */
extern s32 D_0076464C;   /* gp-relative, -0x4AA4 */
extern s32 D_00764650;   /* gp-relative, -0x4AA0 */
extern s16 *D_00764658;  /* gp-relative, -0x4A98 */
extern u8 D_00763928;    /* gp-relative, -0x57C8 */

extern u8 D_0063EF60[];
extern u8 D_0063EF70[];
extern u8 D_0063EF90[];
extern char D_0063EFB0[];
extern u8 D_0063EFC8[];
extern u8 D_00794C90[];
extern char D_0063F0F0[];

extern u8 *func_00457120(void);
extern u8 *func_00461390(void *a, s32 b, void *c, s32 d);
extern u8 *func_0046d200(u32 a, u32 b);
extern void memset(void *dst, s32 value, u32 size);
extern char D_0063EFD8[];
extern void RpSkyRenderStateSet(s32 a, s32 b);
extern s32 sprintf(void *dst, const char *fmt, s32 value);
extern u8 *func_003ef6d0(void);
extern s32 *func_003ef650(u8 *a, void *b);
extern char D_0063EFF0[];
extern char D_0063F010[];
extern char D_0063F030[];
extern char D_0063F050[];
extern char D_0063F070[];
extern char D_0063F090[];
extern char D_0063F0B0[];
extern char D_0063F0D0[];
extern f32 D_008872F8[];
extern u8 D_00794D50[];
extern void func_002b1520(s32, u8 *);
extern void func_002b2500(void);
extern void func_0044ea90(void *msg, s32 id);


extern void func_00460ac0(void *param, void *work);
extern void func_00440b68();
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void H_Cdvd_Destroy(u8 *ptr);
extern s32 H_Cdvd_IsFileLoaded(u8 *ptr);
extern s32 func_0046a750(s32 param);
extern s32 func_0046aea0(const u8 *name);
extern void func_0046d280(void *node);
extern void func_0046d730(void *msg, s32 id);
extern s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern s32 func_004669d0(s32, s32 *, s32);
extern s32 func_002ac400(u8 *arg0);
extern s32 func_002b25d0(u8 *arg0);
extern void func_002b2800(u8 *arg0);
extern void func_002ac600(u8 *arg0);
extern void func_001687f0(u8 *arg0, u8 *arg1);
extern s32 func_001687d0(u8 *arg0);
extern s32 func_001687e0(u8 *arg0);

typedef struct YVec3f { f32 x, y, z; } YVec3f;
typedef FclVec2 YVec2f;
typedef struct YRGBA { u8 a, b, c, d; } YRGBA;

/* func_002afbc0 callees */
extern s32 func_002b2a30(u8, u8, u8, u8);
extern void func_002b2bd0(f32 *, s64, f32, f32, f32, f32);
extern s32 datGetFlag(s32);
extern u8 *func_00155280(void);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void func_002b0b10(u8 *arg0, YVec2f arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, f32 fparg3, s32 arg3, s8 arg4, s32 arg5);
extern u8 D_00794DB0[];
extern u8 D_00794CF0[];
extern u8 D_0076465C;   /* gp-relative, -0x4A94 */
extern u8 D_00764660;   /* gp-relative, -0x4A90 */

/* func_002b1520 callees */
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern void func_0046b380(u8 *, s32);
extern void func_002b3c60(u8 *, u8);
extern u8 *func_002b2940(u8 *);
extern s64 iGpffffa840;  /* gp-relative, -0x57C0 */
extern s64 iGpffffa848;  /* gp-relative, -0x57B8 */
extern f32 iGpffff84f8;
extern f32 iGpffff84f4;  /* gp-relative, -0x7B0C */
/* Map update and symbol-task providers. */
extern u8 *D_007EFA04[];
extern u8 D_007E8C00[];
extern u8 D_00794C30[];
extern u8 D_00794E10[];
extern u8 *func_00460990(void);
extern void func_002b2290(u8 *);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s32 func_002b6850(u8 *);
extern void func_002b67a0(u8 *, u32, s8);
extern s32 func_002b4a10(s32, s32);
extern void func_002ac750(u8, u8);
extern void func_002b31a0(u8 *, u8 *, u8 *);
extern s32 func_00452490(void *);
extern void func_002b10a0(u8 *, YVec2f);
extern void func_002b10e0(u8 *, s8);
extern void func_002b2240(u8 *);
extern int func_002B11C0(YVec3f);
extern int func_002B1210(YVec3f);
/* func_002af3e0 callees */
extern u8 D_007E80A0[];
extern s32 D_00764654;
extern void func_002b3c50(u8 *);
extern void func_002b4ac0(u8 *, s8);
extern void func_002b5100(u8 *, s8);
extern void func_002b4240(u8 *, s8);
extern void func_002b69b0(u8 *, YVec2f, YVec2f, u32, u32, s16);
extern void func_002b6a40(u8 *, u8, u8, u8, s32, s16);
extern void func_002b6be0(u8 *, YVec2f, u32, f32);
extern f32 func_0046b2f0(u8 *);
extern void func_002b10d0(u8 *, s8);
extern void func_002b10f0(u8 *, s8);

typedef YVec3f RwV3d;





// FUN_002AC400
s32 func_002ac400(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 x;

    switch (*(s8 *)(p + 4)) {
    case 0:
        D_00764640 = func_0046aea0(D_0063EF70);
        if (D_00764640 == 0) {
            func_0046d730(D_0063EF60, 0x93);
        }
        D_00764644 = func_0046aea0(D_0063EF90);
        if (D_00764644 == 0) {
            func_0046d730(D_0063EF60, 0x95);
        }
        *(s8 *)(p + 4) += 1;
        break;
    case 1:
        if (func_0046a750(D_00764640) != 0 && func_0046a750(D_00764644) != 0) {
            *(s8 *)(p + 4) += 1;
        }
        break;
    case 2:
        func_00440b68(&D_00763928, D_0063EF60, 0xA0);
        *(s32 *)p = (s32)func_00454a60((u8 *)D_0063EFB0, 0);
        *(s8 *)(p + 4) += 1;
        break;
    case 3:
        if (H_Cdvd_IsFileLoaded(*(u8 **)p) != 0) {
            *(s32 *)(p + 8) = func_004667d0(0, D_0063EFB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s8 *)(p + 4) += 1;
        }
        break;
    case 4:
        D_00764648 = func_004669d0(*(s32 *)(p + 8), &x, 0);
        if (x != 0) {
            *(s32 *)(p + 8) = 0;
            H_Cdvd_Destroy(*(u8 **)p);
            return -1;
        }
        break;
    }
    return 0;
}

// FUN_002AC600
void func_002ac600(u8 *arg0) {
    s16 i;

    func_0044ea90(D_0063EF60, 0x44);
    D_00764658 = (s16 *)D_008873F4[0](1, 0x30, 0x40000);
    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    D_00764650 = 0;
}

// FUN_002AC6B0
void func_002ac6b0(void) {
    u8 *p;

    func_0044ea90(D_0063EF60, 0xD5);
    p = D_008873F4[0](1, 0xC, 0x40000);
    D_00764650 = (s32)(s32)func_00451de0((const void *)(D_0063EFC8), 0xF, 0, 0, func_002ac400, func_002ac600, (u8 *)(p));
    *(u8 *)(p + 4) = 0;
}

// FUN_002AC740
s32 func_002ac740(void) {
    return D_00764644;
}

/* measured: full transcription of the M2C_ERROR-free 574-line draft
   (nd 1239 -> 1255). All branch structure, func_00155280 re-call sites,
   func_002adcf0/002b2d00/002b2cb0 calls, the 0x58<7/<9/>=9 dispatch, the
   0x59 sub-switches, and the search loops are right. Residuals:
   (1) the prologue arg-save pattern — retail saves raw arg0/arg1 into
   $s4/$s3 first and re-derives (arg0&0xFF)/(arg1&0xFF) at every later
   site; mwcc CSEs my masked temps and rotates the saved registers
   (t18=$s4 vs $s2, t17=$s1, t16=$s0, t20=$s3 vs $s0) — rotation floor
   family; (2) the u16 bit-sets on D_00764658 — retail emits lhu/or/shu
   with the &0xFFFF mask at the first use only, then re-masks per
   later site; mwcc emits lh or adds dsll32/dsra32 extension dances
   depending on the local's type (tried u16 and s32 forms, nd 1239 and
   1255). Remaining ~1240 differing words are these two families
   cascading through 1384 words. */
/* measured: banked v5 (m2c transcription, s32 temps, M2C_FIELD expanded, block-scope externs, func_00155280() fixed, s8/s16 casts): fnalign retail 1380 obj 1356 (-24, -1.7% inside 1338-1421), 916 edits +5 reloc-only; frame 0x140 vs 0x190 count-neutral. Residuals: saved-reg rotation + u16 bit-set families. */
/* measured: 2026-09-19 switch-order + default-place (this session): jtbl_007487E0 6 entries share pairwise (0,1->0x2ad2d4 9/10; 2,3->0x2ad4f0 11/12; 4,5->0x2ada3c 13/14) so case9:case10: stacked is correct, no real fallthrough; 9/10->default fallthrough is artefact (different targets, both return via epilogue) so break + default-at-end. Switch1/3 irregular 2,0/3,1 -> ascending 0,2/1,3. fnalign retail 1380: base 916+5 obj1356 -> default-end 915+5 obj1354 (-1) -> sw1-asc 879+5 (-37) -> sw1+sw3-asc 843+5 (-73) -> +default-end 842+5 obj1354 (-74 total). Pointer-walk trial on loop_102 D-table (p_102++) 844+5 (+2 vs 842, reject; retail also index*2). Raw-save prologue trial neutral 842. Frame still 0x140 vs 0x190, saved-reg rotation + u16 families remain. verify 28MATCH/8ASM, lint 0e/1w (pre-existing H003), fnalign object compiles. TU C-linked unverified (prod stays ASM), image hashes unverified. */
/* Row displacements are byte offsets. Cast the visibility-table base to
   u8 * before adding them; adding to s16 * doubles each row displacement.
   Both retail stores add the two byte offsets before their halfword load. */
// FUN_002AC750 NONMATCHING
#ifdef NON_MATCHING
void func_002ac750(u8 arg0, u8 arg1) {
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern s64 func_002adcf0(u8);
    s32 sp180;
    s32 sp170;
    s32 sp160;
    s32 sp150;
    s32 sp140;
    s32 sp130;
    s32 sp120;
    s32 sp110;
    s32 sp100;
    s32 spF0;
    s32 spE0;
    s32 spD0;
    s32 spC0;
    s32 spB0;
    s32 spA0;
    s32 temp_2_3;
    s32 temp_2_8;
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_18_4;
    s32 temp_18_6;
    s32 temp_18_7;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_19_3;
    s32 temp_20;
    s32 temp_21;
    s32 temp_21_3;
    s32 temp_21_4;
    s32 temp_22;
    s32 temp_22_3;
    s32 temp_23;
    s32 temp_23_3;
    s32 temp_23_4;
    s32 temp_23_5;
    s32 temp_23_6;
    s32 temp_30;
    s32 temp_3_4;
    s32 temp_3_9;
    s32 temp_4_14;
    s32 temp_4_19;
    s32 temp_4_29;
    s32 temp_4_36;
    s32 temp_4_40;
    s32 temp_5_10;
    s32 temp_5_5;
    s32 temp_5_6;
    s32 temp_5_7;
    s32 temp_5_9;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_6_3;
    s32 temp_6_4;
    s32 temp_7;
    s32 temp_7_2;
    s32 temp_7_3;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_6;
    s32 temp_16_7;
    s32 temp_18_3;
    s32 temp_18_5;
    s32 temp_18_8;
    s32 temp_18_9;
    s32 temp_19_4;
    s32 temp_19_5;
    s32 temp_19_6;
    s32 temp_19_7;
    s32 temp_20_3;
    s32 temp_20_4;
    s32 temp_20_5;
    s32 temp_20_6;
    s32 temp_21_5;
    s32 temp_22_2;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_4_10;
    s32 temp_4_34;
    s32 temp_4_38;
    s32 temp_5;
    s32 temp_5_11;
    s32 temp_5_12;
    s32 temp_5_2;
    s32 temp_5_4;
    s32 temp_5_8;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_17_4;
    s32 var_17_5;
    s32 var_18;
    s32 var_18_2;
    s32 var_21;
    s32 var_21_2;
    s32 var_22;
    s32 var_22_2;
    s32 var_23;
    s32 var_30;
    s32 var_4;
    s32 var_4_2;
    u16 *temp_3;
    u16 *temp_3_10;
    u16 *temp_3_11;
    u16 *temp_3_12;
    u16 *temp_3_13;
    u16 *temp_3_2;
    u16 *temp_3_3;
    u16 *temp_3_5;
    u16 *temp_3_7;
    u16 *temp_3_8;
    u16 *temp_4_11;
    u16 *temp_4_12;
    u16 *temp_4_13;
    u16 *temp_4_15;
    u16 *temp_4_16;
    u16 *temp_4_20;
    u16 *temp_4_21;
    u16 *temp_4_24;
    u16 *temp_4_25;
    u16 *temp_4_28;
    u16 *temp_4_2;
    u16 *temp_4_30;
    u16 *temp_4_35;
    u16 *temp_4_37;
    u16 *temp_4_39;
    u16 *temp_4_3;
    u16 *temp_4_4;
    u16 *temp_4_5;
    u16 *temp_4_7;
    u16 *temp_4_8;
    u16 *temp_5_13;
    u16 *temp_5_3;
    u8 temp_20_2;
    u8 temp_21_2;
    u8 temp_21_6;
    u8 temp_22_4;
    u8 temp_22_5;
    u8 temp_23_2;
    u8 temp_2_4;
    u8 temp_2_5;
    u8 temp_2_9;
    u8 temp_3_6;
    u8 temp_4;
    u8 temp_4_33;
    u8 temp_4_6;
    u8 temp_4_9;
    u8 *temp_4_17;
    u8 *temp_4_18;
    u8 *temp_4_22;
    u8 *temp_4_23;
    u8 *temp_4_26;
    u8 *temp_4_27;
    u8 *temp_4_31;
    u8 *temp_4_32;

    temp_18 = arg1 & 0xFF;
    temp_17 = temp_18 << 8;
    temp_16 = (arg0 & 0xFF) * 0x10;
    if ((s32) (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x58))) < 7) {
        temp_4 = (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x58)));
        if (temp_4 == 2) {
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 1) {
                if (((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55))) & 0xF) == 1) {
                    temp_20 = arg0 & 0xFF;
                    temp_21 = (1 << temp_20) & 0xFFFF;
                    temp_18_2 = temp_18 * 2;
                    temp_3 = (u16 *)((u8 *)D_00764658 + temp_18_2);
                    *temp_3 |= temp_21;
                    temp_19 = arg1 & 0xFF;
                    temp_22 = temp_19 << 8;
                    if (((*( u8 * )((u8*)((func_00155280() + temp_22 + temp_16)) + (-0xA8))) == 2) && ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5E))) & 1)) {
                        if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 1) {
                            if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 0x10) {
                                temp_4_2 = (u16 *)((u8 *)D_00764658 + (((temp_19 - 1) & 0xFF) * 2));
                                *temp_4_2 |= temp_21 & 0xFFFF;
                            }
                        } else {
                            temp_4_3 = (u16 *)((u8 *)D_00764658 + (((temp_19 - 1) & 0xFF) * 2));
                            *temp_4_3 |= temp_21 & 0xFFFF;
                        }
                    }
                    if (((*( u8 * )((u8*)((func_00155280() + temp_22 + temp_16)) + (0x158))) == 2) && ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5E))) & 4)) {
                        if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 4) {
                            if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 0x40) {
                                temp_4_4 = (u16 *)((u8 *)D_00764658 + (((temp_19 + 1) & 0xFF) * 2));
                                *temp_4_4 |= temp_21 & 0xFFFF;
                            }
                        } else {
                            temp_4_5 = (u16 *)((u8 *)D_00764658 + (((temp_19 + 1) & 0xFF) * 2));
                            *temp_4_5 |= temp_21 & 0xFFFF;
                        }
                    }
                    temp_19_2 = temp_20 * 0x10;
                    if (((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_19_2)) + (0x68))) == 2) && ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5E))) & 8)) {
                        if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 8) {
                            if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 0x80) {
                                temp_3_2 = (u16 *)((u8 *)D_00764658 + temp_18_2);
                                *temp_3_2 |= (1 << ((temp_20 + 1) & 0xFF)) & 0xFFFF;
                            }
                        } else {
                            temp_3_3 = (u16 *)((u8 *)D_00764658 + temp_18_2);
                            *temp_3_3 |= (1 << ((temp_20 + 1) & 0xFF)) & 0xFFFF;
                        }
                    }
                    temp_4_6 = (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_19_2)) + (0x48)));
                    if ((temp_4_6 == 2) && ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5E))) & 2)) {
                        if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 2) {
                            if ((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x5F))) & 0x20) {
                                temp_4_7 = (u16 *)((u8 *)D_00764658 + temp_18_2);
                                *temp_4_7 |= (1 << ((temp_20 - 1) & 0xFF)) & 0xFFFF;
                            }
                        } else {
                            temp_4_8 = (u16 *)((u8 *)D_00764658 + temp_18_2);
                            *temp_4_8 |= (1 << ((temp_20 - 1) & 0xFF)) & 0xFFFF;
                        }
                    }
                } else {
                    var_18 = 0;
                    sp160 = arg1 & 0xFF;
                    sp150 = arg0 & 0xFF;
                    temp_23 = temp_17 + temp_16;
loop_36:
                    temp_5 = ((s16)(var_18));
                    if (temp_5 < 2) {
                        temp_2 = ((s8)(func_002b2d00(sp160, temp_5, 1, 0x18, 1)));
                        sp140 = (s32) temp_2;
                        var_22 = 0;
                        sp130 = temp_2 << 8;
loop_34:
                        temp_5_2 = ((s16)(var_22));
                        if (temp_5_2 < 2) {
                            temp_2_2 = ((s8)(func_002b2d00(sp150, temp_5_2, 1, 0x10, 1)));
                            sp120 = (s32) temp_2_2;
                            temp_2_3 = temp_2_2 * 0x10;
                            sp110 = temp_2_3;
                            if ((((*( u8 * )((u8*)((sp130 + func_00155280() + temp_2_3)) + (0x55))) & 0xF) == 1) && (temp_2_4 = (*( u8 * )((u8*)((sp130 + func_00155280() + sp110)) + (0x58))), sp100 = (s32) temp_2_4, (temp_2_4 == (*( u8 * )((u8*)((temp_23 + func_00155280())) + (0x58)))))) {
                                var_30 = ((s8)((s64) sp120));
                                var_21 = ((s8)((s64) sp140));
                            } else {
                                var_22 = ((s16)((var_22 + 1)));
                                goto loop_34;
                            }
                        }
                        var_18 = ((s16)((var_18 + 1)));
                        goto loop_36;
                    }
                    temp_4_9 = (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x59)));
                    switch (temp_4_9) {             /* switch 1; irregular */
                    case 0:                         /* switch 1 */
                    case 2:                         /* switch 1 */
                        var_17 = 0;
                        temp_16_2 = ((s8)(var_21));
loop_46:
                        temp_18_3 = ((s16)(var_17));
                        if (temp_18_3 < 2) {
                            temp_21_2 = (*( u8 * )((u8*)((((arg0 & 0xFF) * 0x10) + func_00155280() + ((temp_16_2 + temp_18_3) << 8))) + (0x58)));
                            if (temp_21_2 == (*( u8 * )((u8*)((temp_23 + func_00155280())) + (0x58)))) {
                                temp_5_3 = (u16 *)((temp_16_2 * 2) + (u8 *)D_00764658 + (temp_18_3 * 2));
                                *temp_5_3 |= (1 << sp150) & 0xFFFF & 0xFFFF;
                            }
                            var_17 = ((s16)((var_17 + 1)));
                            goto loop_46;
                        }
                        return;
                    case 1:                         /* switch 1 */
                    case 3:                         /* switch 1 */
                        var_16 = 0;
                        temp_3_4 = arg1 & 0xFF;
loop_52:
                        temp_4_10 = ((s16)(var_16));
                        if (temp_4_10 < 2) {
                            temp_17_2 = ((s8)(var_30)) + temp_4_10;
                            temp_20_2 = (*( u8 * )((u8*)(((temp_3_4 << 8) + func_00155280() + (temp_17_2 * 0x10))) + (0x58)));
                            if (temp_20_2 == (*( u8 * )((u8*)((temp_23 + func_00155280())) + (0x58)))) {
                                temp_4_11 = (u16 *)((u8 *)D_00764658 + (temp_3_4 * 2));
                                *temp_4_11 |= (1 << temp_17_2) & 0xFFFF;
                            }
                            var_16 = ((s16)((var_16 + 1)));
                            goto loop_52;
                        }
                        return;
                    }
                }
            } else if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 2) {
                temp_4_12 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_4_12 |= (1 << (arg0 & 0xFF)) & 0xFFFF;
            }
        } else {
            temp_4_13 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
            *temp_4_13 |= (1 << (arg0 & 0xFF)) & 0xFFFF;
        }
    } else if ((s32) (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x58))) < 9) {
        temp_4_14 = arg0 & 0xFF;
        temp_3_5 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
        *temp_3_5 |= (1 << temp_4_14) & 0xFFFF;
        temp_30 = temp_4_14 + 2;
        temp_22_2 = ((s8)(func_002b2d00(temp_4_14, 1, 1, temp_30, 1)));
        temp_18_4 = temp_18 << 8;
        temp_21_3 = temp_22_2 * 0x10;
        temp_23_2 = (*( u8 * )((u8*)((func_00155280() + temp_18_4 + temp_21_3)) + (0x58)));
        if ((temp_23_2 == (*( u8 * )((u8*)((func_00155280() + temp_18_4 + temp_16)) + (0x58)))) && (((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_21_3)) + (0x55))) & 0xF) == 1)) {
            temp_5_4 = ((s8)(temp_22_2));
            temp_7 = (1 << temp_5_4) & 0xFFFF;
            temp_6 = (arg1 & 0xFF) * 2;
            temp_4_15 = (u16 *)((u8 *)D_00764658 + temp_6);
            *temp_4_15 |= temp_7;
            temp_5_5 = (1 << (temp_5_4 + 1)) & 0xFFFF;
            temp_4_16 = (u16 *)((u8 *)D_00764658 + temp_6);
            *temp_4_16 |= temp_5_5;
            temp_4_17 = (u8 *)((u8 *)D_00764658 + (temp_6));
            (*( u16 * )((u8*)(temp_4_17) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_17) + (2))) | temp_7);
            temp_4_18 = (u8 *)((u8 *)D_00764658 + (temp_6));
            (*( u16 * )((u8*)(temp_4_18) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_18) + (2))) | temp_5_5);
            return;
        }
        temp_4_19 = arg1 & 0xFF;
        temp_23_3 = temp_4_19 + 2;
        temp_18_5 = ((s8)(func_002b2d00(temp_4_19, 1, 1, temp_23_3, 1)));
        temp_21_4 = (arg0 & 0xFF) * 0x10;
        temp_22_3 = temp_18_5 << 8;
        temp_2_5 = (*( u8 * )((u8*)((func_00155280() + temp_22_3 + temp_21_4)) + (0x58)));
        spF0 = (s32) temp_2_5;
        if ((temp_2_5 == (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_21_4)) + (0x58)))) && (((*( u8 * )((u8*)((func_00155280() + temp_22_3 + temp_16)) + (0x55))) & 0xF) == 1)) {
            temp_5_6 = arg0 & 0xFF;
            temp_7_2 = (1 << temp_5_6) & 0xFFFF;
            temp_6_2 = ((s8)(temp_18_5)) * 2;
            temp_4_20 = (u16 *)((u8 *)D_00764658 + temp_6_2);
            *temp_4_20 |= temp_7_2;
            temp_5_7 = (1 << (temp_5_6 + 1)) & 0xFFFF;
            temp_4_21 = (u16 *)((u8 *)D_00764658 + temp_6_2);
            *temp_4_21 |= temp_5_7;
            temp_4_22 = (u8 *)((u8 *)D_00764658 + (temp_6_2));
            (*( u16 * )((u8*)(temp_4_22) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_22) + (2))) | temp_7_2);
            temp_4_23 = (u8 *)((u8 *)D_00764658 + (temp_6_2));
            (*( u16 * )((u8*)(temp_4_23) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_23) + (2))) | temp_5_7);
            return;
        }
        temp_21_5 = ((s8)(func_002b2d00(arg0 & 0xFF, 1, 1, temp_30, 1)));
        temp_20_3 = ((s8)(func_002b2d00(arg1 & 0xFF, 1, 1, temp_23_3, 1)));
        temp_19_3 = temp_20_3 << 8;
        temp_18_6 = ((s8)(temp_21_5)) * 0x10;
        temp_22_4 = (*( u8 * )((u8*)((func_00155280() + temp_19_3 + temp_18_6)) + (0x58)));
        if ((temp_22_4 == (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x58)))) && (((*( u8 * )((u8*)((func_00155280() + temp_19_3 + temp_18_6)) + (0x55))) & 0xF) == 1)) {
            temp_5_8 = ((s8)(temp_21_5));
            temp_7_3 = (1 << temp_5_8) & 0xFFFF;
            temp_6_3 = ((s8)(temp_20_3)) * 2;
            temp_4_24 = (u16 *)((u8 *)D_00764658 + temp_6_3);
            *temp_4_24 |= temp_7_3;
            temp_5_9 = (1 << (temp_5_8 + 1)) & 0xFFFF;
            temp_4_25 = (u16 *)((u8 *)D_00764658 + temp_6_3);
            *temp_4_25 |= temp_5_9;
            temp_4_26 = (u8 *)((u8 *)D_00764658 + (temp_6_3));
            (*( u16 * )((u8*)(temp_4_26) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_26) + (2))) | temp_7_3);
            temp_4_27 = (u8 *)((u8 *)D_00764658 + (temp_6_3));
            (*( u16 * )((u8*)(temp_4_27) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_27) + (2))) | temp_5_9);
        }
    } else {
        temp_3_6 = (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x58)));
        switch (temp_3_6) {                         /* switch 2 */
        case 9:                                     /* switch 2 */
        case 10:                                    /* switch 2 */
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 1) {
                temp_4_28 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_4_28 |= (1 << (arg0 & 0xFF)) & 0xFFFF;
                return;
            }
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 2) {
                temp_4_29 = arg0 & 0xFF;
                temp_3_7 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_3_7 |= (1 << temp_4_29) & 0xFFFF;
                temp_16_3 = ((s8)(func_002b2d00(temp_4_29, 1, 0, 0, 1)));
                var_21_2 = ((s8)(func_002b2d00(temp_18, 1, 0, 0, 1)));
                var_18_2 = 0;
                temp_16_4 = ((s8)(temp_16_3));
loop_79:
                if (((s16)(var_18_2)) < 3) {
                    var_17_2 = 0;
                    temp_20_4 = ((s8)(var_21_2));
loop_77:
                    temp_19_4 = ((s16)(var_17_2));
                    if (temp_19_4 < 3) {
                        temp_23_4 = func_002b2cb0(temp_16_4, temp_19_4, 0x10, 0, 1) * 0x10;
                        if (((s8)(func_002adcf0((*( u8 * )((u8*)(((temp_20_4 << 8) + func_00155280() + temp_23_4)) + (0x55)))))) == 2) {
                            temp_3_8 = (u16 *)((u8 *)D_00764658 + (temp_20_4 * 2));
                            *temp_3_8 |= (1 << func_002b2cb0(temp_16_4, temp_19_4, 0x10, 0, 1)) & 0xFFFF;
                        }
                        var_17_2 = ((s16)((var_17_2 + 1)));
                        goto loop_77;
                    }
                    var_21_2 = ((s8)(func_002b2cb0(temp_20_4, 1, 0x18, 0, 1)));
                    var_18_2 = ((s16)((var_18_2 + 1)));
                    goto loop_79;
                }
                return;
            }
            break;
        case 11:                                    /* switch 2 */
        case 12:                                    /* switch 2 */
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 1) {
                if (((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55))) & 0xF) == 1) {
                    temp_6_4 = (1 << (arg0 & 0xFF)) & 0xFFFF;
                    temp_4_30 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                    *temp_4_30 |= temp_6_4;
                    temp_5_10 = temp_18 * 2;
                    temp_4_31 = (u8 *)((u8 *)D_00764658 + (temp_5_10));
                    (*( u16 * )((u8*)(temp_4_31) + (2))) = (u16) ((*( u16 * )((u8*)(temp_4_31) + (2))) | temp_6_4);
                    temp_4_32 = (u8 *)((u8 *)D_00764658 + (temp_5_10));
                    (*( u16 * )((u8*)(temp_4_32) + (4))) = (u16) ((*( u16 * )((u8*)(temp_4_32) + (4))) | temp_6_4);
                    return;
                }
                var_22_2 = 0;
                sp180 = temp_18;
                sp170 = arg0 & 0xFF;
                temp_18_7 = temp_17 + temp_16;
loop_92:
                temp_5_11 = ((s16)(var_22_2));
                if (temp_5_11 < 3) {
                    temp_2_6 = ((s8)(func_002b2d00(sp180, temp_5_11, 1, 0x18, 1)));
                    spE0 = (s32) temp_2_6;
                    var_23 = 0;
                    spD0 = temp_2_6 << 8;
loop_90:
                    temp_5_12 = ((s16)(var_23));
                    if (temp_5_12 < 3) {
                        temp_2_7 = ((s8)(func_002b2d00(sp170, temp_5_12, 1, 0x10, 1)));
                        spC0 = (s32) temp_2_7;
                        temp_2_8 = temp_2_7 * 0x10;
                        spB0 = temp_2_8;
                        if ((((*( u8 * )((u8*)((spD0 + func_00155280() + temp_2_8)) + (0x55))) & 0xF) == 1) && (temp_2_9 = (*( u8 * )((u8*)((spD0 + func_00155280() + spB0)) + (0x58))), spA0 = (s32) temp_2_9, (temp_2_9 == (*( u8 * )((u8*)((temp_18_7 + func_00155280())) + (0x58)))))) {
                            var_30 = ((s8)((s64) spC0));
                            var_21 = ((s8)((s64) spE0));
                        } else {
                            var_23 = ((s16)((var_23 + 1)));
                            goto loop_90;
                        }
                    }
                    var_22_2 = ((s16)((var_22_2 + 1)));
                    goto loop_92;
                }
                temp_4_33 = (*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x59)));
                switch (temp_4_33) {                /* switch 3; irregular */
                case 0:                             /* switch 3 */
                case 2:                             /* switch 3 */
                    var_17_3 = 0;
                    temp_16_5 = ((s8)(var_21));
loop_102:
                    temp_19_5 = ((s16)(var_17_3));
                    if (temp_19_5 < 3) {
                        temp_22_5 = (*( u8 * )((u8*)((((arg0 & 0xFF) * 0x10) + func_00155280() + ((temp_16_5 + temp_19_5) << 8))) + (0x58)));
                        if (temp_22_5 == (*( u8 * )((u8*)((temp_18_7 + func_00155280())) + (0x58)))) {
                            temp_5_13 = (u16 *)((temp_16_5 * 2) + (u8 *)D_00764658 + (temp_19_5 * 2));
                            *temp_5_13 |= (1 << sp170) & 0xFFFF & 0xFFFF;
                        }
                        var_17_3 = ((s16)((var_17_3 + 1)));
                        goto loop_102;
                    }
                    return;
                case 1:                             /* switch 3 */
                case 3:                             /* switch 3 */
                    var_16_2 = 0;
                    temp_3_9 = arg1 & 0xFF;
loop_108:
                    temp_4_34 = ((s16)(var_16_2));
                    if (temp_4_34 < 3) {
                        temp_17_3 = ((s8)(var_30)) + temp_4_34;
                        temp_21_6 = (*( u8 * )((u8*)(((temp_3_9 << 8) + func_00155280() + (temp_17_3 * 0x10))) + (0x58)));
                        if (temp_21_6 == (*( u8 * )((u8*)((temp_18_7 + func_00155280())) + (0x58)))) {
                            temp_4_35 = (u16 *)((u8 *)D_00764658 + (temp_3_9 * 2));
                            *temp_4_35 |= (1 << temp_17_3) & 0xFFFF;
                        }
                        var_16_2 = ((s16)((var_16_2 + 1)));
                        goto loop_108;
                    }
                    return;
                }
            } else if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 2) {
                temp_4_36 = arg0 & 0xFF;
                temp_3_10 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_3_10 |= (1 << temp_4_36) & 0xFFFF;
                temp_16_6 = ((s8)(func_002b2d00(temp_4_36, 1, 0, 0, 1)));
                var_4 = ((s8)(func_002b2d00(temp_18, 1, 0, 0, 1)));
                var_17_4 = 0;
                temp_20_5 = ((s8)(temp_16_6));
loop_118:
                if (((s16)(var_17_4)) < 3) {
                    var_16_3 = 0;
                    temp_19_6 = ((s8)(var_4));
loop_116:
                    temp_18_8 = ((s16)(var_16_3));
                    if (temp_18_8 < 3) {
                        temp_23_5 = func_002b2cb0(temp_20_5, temp_18_8, 0x10, 0, 1) * 0x10;
                        if (((s8)(func_002adcf0((*( u8 * )((u8*)(((temp_19_6 << 8) + func_00155280() + temp_23_5)) + (0x55)))))) == 2) {
                            temp_3_11 = (u16 *)((u8 *)D_00764658 + (temp_19_6 * 2));
                            *temp_3_11 |= (1 << func_002b2cb0(temp_20_5, temp_18_8, 0x10, 0, 1)) & 0xFFFF;
                        }
                        var_16_3 = ((s16)((var_16_3 + 1)));
                        goto loop_116;
                    }
                    var_4 = ((s8)(func_002b2cb0(temp_19_6, 1, 0x18, 0, 1)));
                    var_17_4 = ((s16)((var_17_4 + 1)));
                    goto loop_118;
                }
                return;
            }
            break;
        case 13:                                    /* switch 2 */
        case 14:                                    /* switch 2 */
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 1) {
                temp_4_37 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_4_37 |= (1 << (arg0 & 0xFF)) & 0xFFFF;
                return;
            }
            temp_4_38 = ((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55))))));
            if (temp_4_38 == 3) {
                temp_4_39 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_4_39 |= (1 << (arg0 & 0xFF)) & 0xFFFF;
                return;
            }
            if (((s8)(func_002adcf0((*( u8 * )((u8*)((func_00155280() + temp_17 + temp_16)) + (0x55)))))) == 2) {
                temp_4_40 = arg0 & 0xFF;
                temp_3_12 = (u16 *)((u8 *)D_00764658 + (temp_18 * 2));
                *temp_3_12 |= (1 << temp_4_40) & 0xFFFF;
                temp_16_7 = ((s8)(func_002b2d00(temp_4_40, 1, 0, 0, 1)));
                var_4_2 = ((s8)(func_002b2d00(temp_18, 1, 0, 0, 1)));
                var_17_5 = 0;
                temp_20_6 = ((s8)(temp_16_7));
loop_132:
                if (((s16)(var_17_5)) < 3) {
                    var_16_4 = 0;
                    temp_19_7 = ((s8)(var_4_2));
loop_130:
                    temp_18_9 = ((s16)(var_16_4));
                    if (temp_18_9 < 3) {
                        temp_23_6 = func_002b2cb0(temp_20_6, temp_18_9, 0x10, 0, 1) * 0x10;
                        if (((s8)(func_002adcf0((*( u8 * )((u8*)(((temp_19_7 << 8) + func_00155280() + temp_23_6)) + (0x55)))))) == 2) {
                            temp_3_13 = (u16 *)((u8 *)D_00764658 + (temp_19_7 * 2));
                            *temp_3_13 |= (1 << func_002b2cb0(temp_20_6, temp_18_9, 0x10, 0, 1)) & 0xFFFF;
                        }
                        var_16_4 = ((s16)((var_16_4 + 1)));
                        goto loop_130;
                    }
                    var_4_2 = ((s8)(func_002b2cb0(temp_19_7, 1, 0x18, 0, 1)));
                    var_17_5 = ((s16)((var_17_5 + 1)));
                    goto loop_132;
                }
            }
            break;
        default:
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ac750);
#endif
// FUN_002ADCF0
s64 func_002adcf0(u8 arg0) {
    return (s64)(s8)((arg0 & 0xFF) >> 4);
}



/* measured: re-tested wave 4 (nd 4, unchanged) — call 1 arg setup is the
   only diff: retail materialises addiu $a0,$0,0xE before the addiu
   $a1,$a1,0xB4; mwcc b210 emits the arithmetic arg first (call 2 (0xE,0)
   already matches). Tried old-style () fn-ptr local, dual s32 temps,
   s32 arg1 typing, cached fn-ptr — all nd 4. Matched sibling
   func_002add60 emits const-first because its 2nd arg is a load.
   Argument-scheduling floor. */
// FUN_002ADD10
void func_002add10(s32 arg0, u8 *arg1) {
    D_00887304[0](0xE, arg1 + 0xB4);
    D_00887300[0](0xE, 0);
}

// FUN_002ADD60
void func_002add60(u8 *arg0, u8 *arg1) {
    D_00887300[0](0xE, *(s32 *)(arg1 + 0xB4));
}



/* Map cells occupy 0x10 bytes in rows of 0x100 bytes. Read from the
 * complete map allocation so a neighboring cell can cross a logical row.
 * Signed neighbor offsets preserve integer promotion before +/- 1; ordinary
 * byte coordinates use unsigned offsets. Both stay in the same byte domain.
 */
#define SMAP_FIELD(row, column, offset) \
    (*((u8 *)func_00155280() + (row) * 0x100 + (column) * 0x10 + (offset)))

// FUN_002ADD90
s32 func_002add90(u8 *arg0)
{
    YVec2f scale;
    YVec3f pos;
    YVec3f positionSnapshot;
    YVec3f horizontalOffset;
    YVec3f verticalOffset;
    u8 *work;
    u8 *task;
    s32 tileY;
    s32 tileX;
    u8 y;
    s32 unitIndex;
    u8 x;

    work = *(u8 **)(arg0 + 0x38);
    func_001687f0((u8 *)&positionSnapshot, *(u8 **)(D_007EFA04[0] + 0x220));
    /* The provider always writes all three floats, including the no-model path. */
    pos = *(YVec3f *)(u8 *)&positionSnapshot;
    task = func_00460990();
    *(void **)(task + 8) = func_002add10;
    *(u8 **)(task + 0x10) = work;
    func_00460ac0(D_00794C30, task);
    task = func_00460990();
    *(void **)(task + 8) = func_002add60;
    *(u8 **)(task + 0x10) = work;
    func_00460ac0(D_00794E10, task);
    switch ((s8)work[4]) {
    case 0:
        func_002b2290(arg0);
        (*(s8 *)(work + 4))++;
        break;
    case 2:
        *(s16 *)(work + 0x766) = func_002b2cb0(*(s16 *)(work + 0x766), 1, 5, 0, 1);
        if ((s8)func_002b6850(*(u8 **)(work + 0x748)) == 0) {
            func_002b67a0(*(u8 **)(work + 0x748), 0, 1);
        }
        if ((s8)func_002b6850(*(u8 **)(work + 0x74C)) == 0) {
            func_002b67a0(*(u8 **)(work + 0x74C), 0, 1);
        }
        /* fall through */
    case 5:
        *(s16 *)(work + 0x764) = func_002b2cb0(*(s16 *)(work + 0x764), 1, 10, 0, 1);
        /* fall through */
    case 1:
        work[0xB8] = 0;
        for (unitIndex = 0; unitIndex < 15; unitIndex++) {
            s32 live = 0;
            u8 *unit = D_007E8C00 + unitIndex * 0x750;

            if ((*(s32 *)(unit + 0x48) != 0) && (*(s32 *)(unit + 0x54) != 0)) {
                live = 1;
            }
            if ((u8)(live != 0) == 1) {
                u8 **slot = (u8 **)(work + unitIndex * 4 + 0xD8);

                if (*slot == NULL) {
                    *slot = (u8 *)func_002b4a10((s32)arg0, (s8)unitIndex);
                }
            }
        }
        x = func_002B11C0(pos);
        y = func_002B1210(pos);
        func_002ac750(x, y);
        if (SMAP_FIELD((u32)y, (s32)x, 0x64) == 1 && (SMAP_FIELD((u32)y, (u32)x, 0x5E) & 8)) {
            if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 8) {
                if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 0x80) {
                    func_002ac750((u8)(x + 1), y);
                }
            } else {
                func_002ac750((u8)(x + 1), y);
            }
        }
        if (SMAP_FIELD((u32)y, (s32)x, 0x44) == 1 && (SMAP_FIELD((u32)y, (u32)x, 0x5E) & 2)) {
            if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 2) {
                if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 0x20) {
                    func_002ac750((u8)(x - 1), y);
                }
            } else {
                func_002ac750((u8)(x - 1), y);
            }
        }
        if (SMAP_FIELD((s32)y, (u32)x, -0xAC) == 1 && (SMAP_FIELD((u32)y, (u32)x, 0x5E) & 1)) {
            if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 1) {
                if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 0x10) {
                    func_002ac750(x, (u8)(y - 1));
                }
            } else {
                func_002ac750(x, (u8)(y - 1));
            }
        }
        if (SMAP_FIELD((s32)y, (u32)x, 0x154) == 1 && (SMAP_FIELD((u32)y, (u32)x, 0x5E) & 4)) {
            if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 4) {
                if (SMAP_FIELD((u32)y, (u32)x, 0x5F) & 0x40) {
                    func_002ac750(x, (u8)(y + 1));
                }
            } else {
                func_002ac750(x, (u8)(y + 1));
            }
        }
        func_002b31a0((u8 *)&horizontalOffset, work + 8, (u8 *)&pos);
        scale.x = (s32)(horizontalOffset.x / 66.666664f);
        func_002b31a0((u8 *)&verticalOffset, work + 8, (u8 *)&pos);
        scale.y = (s32)(verticalOffset.z / 66.666664f);
        for (tileX = 0; tileX < 13; tileX++) {
            for (tileY = 0; tileY < 13; tileY++) {
                s16 tx = tileX + (func_001687d0(*(u8 **)(D_007EFA04[0] + 0x220)) - 6);
                s16 ty = tileY + (func_001687e0(*(u8 **)(D_007EFA04[0] + 0x220)) - 6);

                if ((tx > 0) && (ty > 0) && (tx < 16) && (ty < 24)) {
                    u8 **tile = (u8 **)(work + ty * 64 + tx * 4 + 0x148);

                    if (func_00452490(*tile) == 1) {
                        u16 mask = (1 << tx) & 0xFFFF;
                        if (((mask & ((u16 *)D_00764658)[ty]) >> tx) == 1) {
                            func_002b10e0(*tile, 1);
                        }
                        func_002b10a0(*tile, scale);
                    }
                }
            }
        }
        func_002b2240(arg0);
        break;
    case 3:
        *(s16 *)(work + 0x766) = func_002b2cb0(*(s16 *)(work + 0x766), 1, 5, 0, 1);
        /* fall through */
    case 6:
        *(s16 *)(work + 0x764) = func_002b2cb0(*(s16 *)(work + 0x764), 1, 5, 0, 1);
        /* fall through */
    case 4:
        func_002b2240(arg0);
        break;
    case 7:
        return -1;
    }
    return 0;
}

#undef SMAP_FIELD
// FUN_002AE520
void func_002ae520(u8 *arg0) {
    u8 *p;
    s16 i;

    p = *(u8 **)(arg0 + 0x38);
    i = 0;
    while (i < 4) {
        func_0046d280(*(void **)(p + i * 4 + 0x24));
        i++;
    }
    i = 0;
    while (i < 6) {
        func_0046d280(*(void **)(p + i * 4 + 0x34));
        func_0046d280(*(void **)(p + i * 4 + 0x4C));
        func_0046d280(*(void **)(p + i * 4 + 0x64));
        i++;
    }
    func_0046d280(*(void **)(p + 0x7C));
    func_0046d280(*(void **)(p + 0x80));
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* Each map query remains independent. The native row address and byte
 * column/field offsets refer to the complete allocation, while neighbor
 * tables contain signed byte pairs for each orientation.
 */
#define SMAP_SCAN_FIELD(rowOffset, column, field) \
    (*((u8 *)((rowOffset) + (u32)func_00155280()) + (u32)(column) * 0x10 + (field)))
#define SMAP_NEIGHBOR_OFFSET(table, direction, field) \
    (*(s8 *)((u32)(table) + (direction) * 2 + (field)))

#pragma push
/* Retain each selected offset table and issue screen constants at their uses. */
#pragma opt_propagation off
#pragma opt_pulloutconstants off
// FUN_002AE630
u8 *func_002ae630(u8 *arg0)
{
    extern s8 D_0063EEE0[];
    extern s8 D_0063EF00[];
    extern s8 D_0063EF20[];
    extern s8 D_0063EF40[];
    extern u8 *func_002b0250(u8 *, u8, u8, u8, u8, u8, u8, u8);
    extern u8 *func_002b2830(u8 *, YVec2f, f32, f32, u32);
    extern void func_002B1100(void *, u32, u32);
    extern f32 func_002b13e0(f32, YVec3f *);
    extern f32 func_002b1480(f32, YVec3f *);
    extern s32 func_002b3990(s32);
    extern s32 func_002b4140(s32, s32, YVec3f *);
    extern s32 func_002b4fe0(s32, YVec2f, s32);
    extern s32 func_002b6590(s32, s16, s32);
    extern void *mdlGetMatrix(void *);
    extern u8 *func_001452b0(s32);
    u8 *task;
    u8 *work;
    s32 originX;
    s32 originY;
    YVec2f foePosition;
    YVec3f origin;
    YVec2f framePosition1;
    YVec2f framePosition2;
    YVec2f framePosition3;
    YVec2f framePosition4;
    union { FclDrawColor color; u32 packed; } frameColor1;
    union { FclDrawColor color; u32 packed; } frameColor2;
    union { FclDrawColor color; u32 packed; } frameColor3;
    union { FclDrawColor color; u32 packed; } frameColor4;
    s32 rowIndex;
    s32 columnIndex;
    s32 unitIndex;
    u8 *sceneNode;
    s32 nodeIndex;
    u8 *nodeMatrix;

    func_0044ea90(D_0063EF60, 0x389);
    work = D_008873F4[0](1, 0x768, 0x40000);
    task = func_00451fc0(arg0, D_0063EFD8, 0xF, 0, 0,
                        func_002add90, func_002ae520, work);
    *(u8 **)work = work;
    *(work + 4) = 0;
    originX = func_001687d0(*(u8 **)(D_007EFA04[0] + 0x220)) & 0xFF;
    originY = func_001687e0(*(u8 **)(D_007EFA04[0] + 0x220)) & 0xFF;
    func_002B1100(&origin, (u32)originX, (u32)originY);
    *(YVec3f *)(work + 8) = origin;
    D_00764660 = (u8)func_002B11C0(*(RwV3d *)(work + 8));
    D_0076465C = (u8)func_002B1210(*(RwV3d *)(work + 8));
    *(work + 0x20) = 0x12;
    for (rowIndex = 0; rowIndex < 0x18; rowIndex++) {
        u8 *taskRow;
        s32 mapRowOffset;
        columnIndex = 0;
        mapRowOffset = rowIndex << 8;
        taskRow = work + (rowIndex << 6);
        for (; columnIndex < 0x10; columnIndex++) {
            if (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x54) != 0 &&
                (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x55) & 0xF) == 1) {
                if (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58) >= 9) {
                    switch (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58)) {
                    case 9:
                    case 10: {
                        const s8 *orientation;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        orientation = D_0063EEE0 + (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59)) * 2;
                        offsetX = orientation[0];
                        orientation = D_0063EEE0 + (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59)) * 2;
                        offsetY = orientation[1];
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 1, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        orientation = D_0063EEE0 + (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59)) * 2;
                        offsetX = orientation[8];
                        orientation = D_0063EEE0 + (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59)) * 2;
                        offsetY = orientation[9];
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 2, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    case 11:
                    case 12: {
                        const s8 *neighborTable = D_0063EF00;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 1, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 2, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    case 13:
                    case 14: {
                        const s8 *neighborTable = D_0063EF20;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 1, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 2, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 0x10);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 0x11);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 3, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    }
                } else {
                    if (SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58) == 2) {
                        const s8 *neighborTable = D_0063EF40;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 1, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59), 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        *(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148) =
                            func_002b0250(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 2, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                    } else {
                        *(u8 **)(taskRow + columnIndex * 4 + 0x148) =
                            func_002b0250(task, (columnIndex & 0xFF), (rowIndex & 0xFF),
                                SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x58), 1, SMAP_SCAN_FIELD(mapRowOffset, columnIndex, 0x59),
                                (u8)columnIndex, (u8)rowIndex);
                    }
                }
            }
        }
    }
    framePosition1 = func_002b2970(17.0f, 150.0f);
    frameColor1.color = func_002b2a60(0x80, 0x80, 0x80, 0);
    *(u8 **)(work + 0xBC) = func_002b2830(task, framePosition1, 240.0f, 120.0f, frameColor1.packed);
    framePosition2 = func_002b2970(148.0f, 249.0f);
    frameColor2.color = func_002b2a60(0x80, 0, 0, 0);
    *(u8 **)(work + 0xC0) = func_002b2830(task, framePosition2, 150.0f, 231.0f, frameColor2.packed);
    framePosition3 = func_002b2970(0.0f, 395.0f);
    frameColor3.color = func_002b2a60(0, 0x80, 0, 0);
    *(u8 **)(work + 0xC4) = func_002b2830(task, framePosition3, 151.0f, 121.0f, frameColor3.packed);
    framePosition4 = func_002b2970(0.0f, 150.0f);
    frameColor4.color = func_002b2a60(0, 0, 0x80, 0);
    *(u8 **)(work + 0xC8) = func_002b2830(task, framePosition4, 23.0f, 395.0f, frameColor4.packed);
    *(s32 *)(work + 0xCC) = func_002b3990((s32)task);
    for (unitIndex = 0; unitIndex < 0xF; unitIndex++) {
        s32 unitPresent;
        u8 *entry;
        unitPresent = 0;
        entry = D_007E8C00 + unitIndex * 0x750;
        if (*(s32 *)(entry + 0x48) != 0 && *(s32 *)(entry + 0x54) != 0) {
            unitPresent = 1;
        }
        if ((u32)(unitPresent != 0) == 1) {
            *(s32 *)(work + unitIndex * 4 + 0xD8) = func_002b4a10((s32)task, (s8)unitIndex);
        }
    }
    {
        u8 *sprite;
        YVec3f *enemyPosition;
        s32 enemyIndex;
        sprite = func_0046d200(D_00764644, 0x12);
        for (enemyIndex = 0; enemyIndex < 8; enemyIndex++) {
            u8 *entry;
            entry = D_007E80A0 + enemyIndex * 0x168;
            if (*(s32 *)entry != 0) {
                f32 screenX;
                f32 screenY;
                f32 relativeX;
                f32 relativeY;
                enemyPosition = (YVec3f *)(entry + 0x150);
                screenX = (f32)func_002B11C0(*(RwV3d *)enemyPosition) * 18.0f + 172.0f;
                relativeX = func_002b13e0(18.0f, enemyPosition);
                foePosition.x = (screenX - relativeX) - 2.0f;
                screenY = (f32)func_002B1210(*(RwV3d *)enemyPosition) * 18.0f + 9.0f;
                relativeY = func_002b1480(18.0f, enemyPosition);
                foePosition.y = (screenY - relativeY) - 2.0f;
                *(s32 *)(work + enemyIndex * 4 + 0x114) = func_002b4fe0((s32)task, foePosition, (enemyIndex & 0xFF));
            }
        }
        func_0046d280(sprite);
    }
    *(s32 *)(work + 0x748) = func_002b6590((s32)task, 0xC, D_00764644);
    *(s32 *)(work + 0x74C) = func_002b6590((s32)task, 0xD, D_00764644);
    sceneNode = func_001452b0(3);
    nodeIndex = 0;
    *(s32 *)(work + 0xD4) = 0;
    *(s32 *)(work + 0xD0) = 0;
    while (sceneNode != NULL) {
        nodeMatrix = mdlGetMatrix(*(void **)(sceneNode + 0x164));
        *(s32 *)(work + nodeIndex * 4 + 0xD0) = func_002b4140((s32)task, (s8)nodeIndex, (YVec3f *)(nodeMatrix + 0x30));
        nodeIndex++;
        sceneNode = *(u8 **)(sceneNode + 0x138);
    }
    return task;
}

#pragma pop

#undef SMAP_NEIGHBOR_OFFSET
#undef SMAP_SCAN_FIELD
/* Value initialization preserves the constructor's temporary before the label
   position is reused. Loop invariants hoist the final grid row's coordinates. */
// FUN_002AF3E0
#pragma push
#pragma opt_loop_invariants on
void func_002af3e0(u8 *arg0, s8 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x38);
    s16 i;
    s16 z;
    s16 y;
    s16 x;

    func_002b3c50(*(u8 **)(p + 0xCC));
    for (i = 0; i < 15; i++) {
        s32 valid = 0;
        u8 *entry = D_007E8C00 + i * 0x750;
        if (*(s32 *)(entry + 0x48) != 0 && *(s32 *)(entry + 0x54) != 0)
            valid = 1;
        if ((u8)(valid != 0) == 1)
            func_002b4ac0(*(u8 **)(p + i * 4 + 0xD8), arg1);
    }
    for (i = 0; i < 8; i++) {
        if (*(s32 *)(D_007E80A0 + i * 0x168) != 0)
            func_002b5100(*(u8 **)(p + i * 4 + 0x114), arg1);
    }
    for (i = 0; i < 2; i++) {
        u8 *task = *(u8 **)(p + i * 4 + 0xD0);
        if (task != NULL)
            func_002b4240(task, arg1);
    }
    D_00764654 = 0;
    *(s16 *)(p + 0x764) = 0;
    *(s16 *)(p + 0x766) = 0;
    for (x = 0; x < 24; x++) {
        for (y = 0; y < 16; y++) {
            if (func_00452490(*(u8 **)(p + x * 64 + y * 4 + 0x148)) == 1) {
                func_002b10f0(*(u8 **)(p + x * 64 + y * 4 + 0x148), arg1);
                func_002b10d0(*(u8 **)(p + x * 64 + y * 4 + 0x148), 0);
            }
        }
    }
    if (arg1 == 0) {
        u8 *resource;
        *(s8 *)(p + 4) = 2;
        *(s8 *)(p + 0xB8) = 0;
        {
            YVec2f pos = func_002b2970(15.0f, 406.0f);
            resource = func_0046d200(D_00764644, 12);
            func_002b6ac0(*(u8 **)(p + 0x748), 1.0f, 1.0f, 1.0f, 0.1f, 0, 3, 0);
            func_002b69b0(*(u8 **)(p + 0x748), pos,
                func_002b2970(pos.x, pos.y + func_0046b2f0(resource) / 2.0f), 0, 3, 0);
            func_002b6a40(*(u8 **)(p + 0x748), 255, 0, 0, 0, 3);
            func_0046d280(resource);
            pos = func_002b2970(104.0f, 406.0f);
            resource = func_0046d200(D_00764644, 13);
            func_002b6ac0(*(u8 **)(p + 0x74C), 1.0f, 1.0f, 1.0f, 0.1f, 0, 3, 0);
            func_002b69b0(*(u8 **)(p + 0x74C), pos,
                func_002b2970(pos.x, pos.y + func_0046b2f0(resource) / 2.0f), 0, 3, 0);
            func_002b6a40(*(u8 **)(p + 0x74C), 255, 0, 0, 0, 3);
            func_0046d280(resource);
        }
    } else {
        u8 *resource;
        *(s8 *)(p + 4) = 3;
        *(s8 *)(p + 0xB8) = 1;
        {
            YVec2f pos = func_002b2970(15.0f, 406.0f);
            resource = func_0046d200(D_00764644, 12);
            func_002b6be0(*(u8 **)(p + 0x748), pos, 0x4D, 60008);
            func_002b6ac0(*(u8 **)(p + 0x748), 1.0f, 1.0f, 0.1f, 1.0f, 0, 5, 0);
            func_002b69b0(*(u8 **)(p + 0x748),
                func_002b2970(pos.x, pos.y + func_0046b2f0(resource) / 2.0f), pos, 0, 5, 0);
            func_002b6a40(*(u8 **)(p + 0x748), 0, 255, 0, 0, 0);
            func_0046d280(resource);
            pos = func_002b2970(104.0f, 406.0f);
            resource = func_0046d200(D_00764644, 13);
            func_002b6be0(*(u8 **)(p + 0x74C), pos, 0x4D, 60008);
            func_002b6ac0(*(u8 **)(p + 0x74C), 1.0f, 1.0f, 0.1f, 1.0f, 0, 5, 0);
            func_002b69b0(*(u8 **)(p + 0x74C),
                func_002b2970(pos.x, pos.y + func_0046b2f0(resource) / 2.0f), pos, 0, 5, 0);
            func_002b6a40(*(u8 **)(p + 0x74C), 0, 255, 0, 0, 0);
            func_0046d280(resource);
        }
        for (z = 0; z < 24; z++) {
            for (y = 0; y < 16; y++) {
                u8 **slot = (u8 **)(p + z * 64 + y * 4 + 0x148);
                if (func_00452490(*slot) == 1) {
                    if ((((u16)(1 << y) & ((u16 *)D_00764658)[z]) >> y) == 1)
                        func_002b10e0(*slot, 1);
                    func_002b10a0(*slot, func_002b2970(18.0f * z, 18.0f * y));
                }
            }
        }
    }
}
#pragma pop

// FUN_002AFB70
void func_002afb70(u8 *arg0, s8 arg1) {
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x38);
    if (arg1 == 0) {
        *(s8 *)(temp_6 + 4) = 5;
    } else if (arg1 == 1) {
        *(s8 *)(temp_6 + 4) = 6;
    }
    *(s16 *)(temp_6 + 0x764) = 0;
}



/* The cell constructor allocates 0x160 bytes. The renderer owns the
 * position, visibility and icon fields below; the four queued vertices
 * occupy the existing 0x100-byte region beginning at 0x40. */
typedef struct SMapCell {
    void *self;
    u8 type;
    s8 variant;
    u8 reserved06[2];
    YVec2f position;
    YVec2f offset;
    u8 origin;
    u8 reserved19[3];
    f32 textureBounds[4];
    f32 width;
    f32 height;
    f32 scale;
    f32 reciprocalZ;
    u8 reserved3C[4];
    u8 renderVertices[0x100];
    u8 column;
    u8 row;
    s8 orientation;
    s8 visible;
    s8 mode;
    u8 reserved145[7];
    s8 hasIcon;
    u8 reserved14D[3];
    YVec2f iconOffset;
    s8 visibilityColumnOffset;
    s8 visibilityRowOffset;
    s8 pendingDraw;
    u8 reserved15B[5];
} SMapCell;
typedef char SMapCellStorageSize[(sizeof(SMapCell) == 0x160) ? 1 : -1];

/* Draw a visible map cell and its optional icon in scrolling or fixed mode.
 * The scrolling draw request is consumed after rendering. Native b210 -O2:
 * 1624/1632 bytes with all 28 relocations resolved and eight zero tail bytes.
 * See docs/probe_archive/Small_map_cell_002afbc0_20260924.md. */
// FUN_002AFBC0
s32 func_002afbc0(u8 *arg0) {
    u8 *task;
    SMapCell *cell;
    s32 color;
    s32 visibilityRow;
    s32 visibilityColumn;
    YVec2f origin[2];
    s32 showIcon;
    task = arg0;
    cell = *(SMapCell **)(arg0 + 0x38);
    color = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    func_002b2bd0((f32 *)&origin[0], 0, 126.0f, 126.0f, 21.0f, 22.0f);
    origin[1] = origin[0];
    if (D_0076464C == 0) {
        return 0;
    }
    if (datGetFlag(0x1417) != 0) {
        return 0;
    }
    if (cell->mode == 0) {
        if (datGetFlag(0x1416) == 0) {
            if (cell->visible == 0) {
                return 0;
            }
        }
        if (cell->pendingDraw == 0) {
            return 0;
        }
        cell->position.x = 7.0f + 18.0f * (f32)(u32)cell->column + origin[1].x - (f32)(D_00764660 * 18) + 15.0f + cell->offset.x - 10.0f;
        cell->position.y = 227.0f + 18.0f * (f32)(u32)cell->row + origin[1].y - (f32)(D_0076465C * 18) + 15.0f + cell->offset.y + 16.0f;
        if (cell->hasIcon == 1) {
            visibilityRow = ((*(u8 *)(func_00155280() + 0x47) + cell->visibilityRowOffset) & 0xFF);
            visibilityColumn = ((*(u8 *)(func_00155280() + 0x46) + cell->visibilityColumnOffset) & 0xFF);
            if (datGetFlag(0x1416) == 0) {
                showIcon = (s8)(((1 << (visibilityColumn & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[visibilityRow & 0xFF]) >> (visibilityColumn & 0xFF));
            } else {
                showIcon = 1;
            }
            if ((s8)showIcon == 1) {
                func_0025ecd0(cell->position.x + cell->iconOffset.x, cell->position.y + cell->iconOffset.y, 60007.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (void *)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
        func_002b0b10(task, cell->position, cell->width, cell->height, 60008.0f, cell->origin, cell->scale, color, cell->orientation, 0x50);
        cell->pendingDraw = 0;
    } else if (cell->mode == 1) {
        if (datGetFlag(0x1416) == 0) {
            if (cell->visible == 0) {
                return 0;
            }
        }
        cell->position.x = 172.0f + 18.0f * (f32)(u32)cell->column;
        cell->position.y = 9.0f + 18.0f * (f32)(u32)cell->row;
        if (cell->hasIcon == 1) {
            visibilityRow = ((*(u8 *)(func_00155280() + 0x47) + cell->visibilityRowOffset) & 0xFF);
            visibilityColumn = ((*(u8 *)(func_00155280() + 0x46) + cell->visibilityColumnOffset) & 0xFF);
            if (datGetFlag(0x1416) == 0) {
                showIcon = (s8)(((1 << (visibilityColumn & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[visibilityRow & 0xFF]) >> (visibilityColumn & 0xFF));
            } else {
                showIcon = 1;
            }
            if ((s8)showIcon == 1) {
                func_0025ecd0(cell->position.x + cell->iconOffset.x, cell->position.y + cell->iconOffset.y, 60007.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (void *)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
        func_002b0b10(task, cell->position, cell->width, cell->height, 60008.0f, cell->origin, cell->scale, color, cell->orientation, 0x4C);
    }
    return 0;
}

// FUN_002B0220
void func_002b0220(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


#pragma push


/* func_002b0250: `arg3 == -1` is a u8 compared with -1 (retail keeps the never-true test). The 9..14
   dispatch is a real switch inside `if (arg3 >= 9)`; 7..8, 2 and the default arm are the if/else chain
   that follows. arg4 is u8 (andi, not a sign extension). opt_loop_invariants on hoists the per-row
   (arg7 + i) << 8 out of the tile scan's inner loop as retail does (measured: 8 -> 3 differing words;
   writing `j = 0` before the row offset, as retail emits it, then gives 0). */
// FUN_002B0250
#pragma push
#pragma opt_loop_invariants on
u8 *func_002b0250(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    u8 buf[8];
    u8 *ret;
    u8 *blk;
    s16 i;
    s16 j;
    s32 rowOfs;
    s8 kind;
    u8 *q;
    func_002b2bd0((f32 *)buf, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    if (arg3 == -1) {
        return NULL;
    }
    func_0044ea90(D_0063EF60, 0x5C4);
    blk = D_008873F4[0](1, 0x160, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0063EFD8), 0xF, 0, 0, func_002afbc0, func_002b0220, blk);
    *(u8 **)blk = blk;
    *(blk + 4) = arg3;
    *(blk + 5) = arg4;
    *(blk + 0x18) = arg5;
    *(f32 *)(blk + 0x34) = 1.0f;
    *(blk + 0x140) = arg1;
    *(blk + 0x141) = arg2;
    *(blk + 0x142) = 0;
    *(blk + 0x143) = 0;
    *(blk + 0x144) = 0;
    *(s32 *)(blk + 0x14) = 0;
    *(s32 *)(blk + 0x10) = 0;
    if (arg3 >= 9) {
        switch (arg3) {
        case 9:
        case 10:
            if (arg4 == 1) {
                *(f32 *)(blk + 0x28) = 0.03125f;
                *(f32 *)(blk + 0x24) = 0.03125f;
                *(f32 *)(blk + 0x20) = 0.59375f;
                *(f32 *)(blk + 0x1C) = 0.59375f;
                *(f32 *)(blk + 0x30) = 19.0f;
                *(f32 *)(blk + 0x2C) = 19.0f;
            } else if (arg4 == 2) {
                *(f32 *)(blk + 0x24) = 0.296875f;
                *(f32 *)(blk + 0x28) = 0.015625f;
                *(f32 *)(blk + 0x1C) = *(f32 *)(blk + 0x24) + 0.578125f;
                *(f32 *)(blk + 0x20) = *(f32 *)(blk + 0x28) + 0.578125f;
                *(f32 *)(blk + 0x30) = 37.0f;
                *(f32 *)(blk + 0x2C) = 37.0f;
            }
            break;
        case 11:
        case 12:
            if (arg4 == 1) {
                *(f32 *)(blk + 0x28) = 0.015625f;
                *(f32 *)(blk + 0x24) = 0.015625f;
                *(f32 *)(blk + 0x1C) = 0.296875f;
                *(f32 *)(blk + 0x20) = 0.859375f;
                *(f32 *)(blk + 0x2C) = 19.0f;
                *(f32 *)(blk + 0x30) = 55.0f;
                *(blk + 0x142) = 1;
            } else if (arg4 == 2) {
                *(f32 *)(blk + 0x24) = 0.296875f;
                *(f32 *)(blk + 0x28) = 0.015625f;
                *(f32 *)(blk + 0x1C) = *(f32 *)(blk + 0x24) + 0.578125f;
                *(f32 *)(blk + 0x20) = *(f32 *)(blk + 0x28) + 0.578125f;
                *(f32 *)(blk + 0x30) = 37.0f;
                *(f32 *)(blk + 0x2C) = 37.0f;
            }
            break;
        case 13:
        case 14:
            if (arg4 == 1 || arg4 == 3) {
                *(f32 *)(blk + 0x28) = 0.03125f;
                *(f32 *)(blk + 0x24) = 0.03125f;
                *(f32 *)(blk + 0x20) = 0.59375f;
                *(f32 *)(blk + 0x1C) = 0.59375f;
                *(f32 *)(blk + 0x30) = 19.0f;
                *(f32 *)(blk + 0x2C) = 19.0f;
            } else if (arg4 == 2) {
                *(f32 *)(blk + 0x24) = 0.296875f;
                *(f32 *)(blk + 0x28) = 0.296875f;
                *(f32 *)(blk + 0x1C) = 0.859375f;
                *(f32 *)(blk + 0x20) = 0.859375f;
                *(f32 *)(blk + 0x30) = 37.0f;
                *(f32 *)(blk + 0x2C) = 37.0f;
            }
            break;
        }
    } else if (arg3 >= 7) {
        *(f32 *)(blk + 0x24) = 0.015625f;
        *(f32 *)(blk + 0x28) = 0.015625f;
        *(f32 *)(blk + 0x20) = 0.578125f;
        *(f32 *)(blk + 0x1C) = 0.578125f;
        *(f32 *)(blk + 0x30) = 37.0f;
        *(f32 *)(blk + 0x2C) = 37.0f;
    } else if (arg3 == 2) {
        if (arg4 == 1) {
            *(f32 *)(blk + 0x24) = 0.015625f;
            *(f32 *)(blk + 0x28) = 0.015625f;
            *(f32 *)(blk + 0x1C) = 0.578125f;
            *(f32 *)(blk + 0x20) = 0.578125f;
            *(f32 *)(blk + 0x2C) = 37.0f;
            *(f32 *)(blk + 0x30) = 37.0f;
            if (arg5 == 2 || arg5 == 1) {
                *(blk + 0x142) = 2;
            }
        } else if (arg4 == 2) {
            *(f32 *)(blk + 0x28) = 0.296875f;
            *(f32 *)(blk + 0x24) = 0.296875f;
            *(f32 *)(blk + 0x20) = 0.578125f;
            *(f32 *)(blk + 0x1C) = 0.578125f;
            *(f32 *)(blk + 0x30) = 19.0f;
            *(f32 *)(blk + 0x2C) = 19.0f;
        }
    } else {
        *(f32 *)(blk + 0x24) = 0.03125f;
        *(f32 *)(blk + 0x28) = 0.03125f;
        *(f32 *)(blk + 0x20) = 0.59375f;
        *(f32 *)(blk + 0x1C) = 0.59375f;
        *(f32 *)(blk + 0x30) = 19.0f;
        *(f32 *)(blk + 0x2C) = 19.0f;
    }
    *(blk + 0x14C) = 0;
    if (arg4 == 2 && arg6 == *(u8 *)(func_00155280() + 0x46) && arg7 == *(u8 *)(func_00155280() + 0x47)) {
        for (i = 0; i < 2; i++) {
            j = 0;
            rowOfs = (arg7 + i) << 8;
            for (; j < 2; j++) {
                q = func_00155280();
                kind = *(u8 *)(rowOfs + (u32)q + (arg6 + j) * 0x10 + 0x55) >> 4;
                if (kind == 2) {
                    *(f32 *)(blk + 0x150) = 9.0f;
                    *(f32 *)(blk + 0x154) = 9.0f;
                    *(blk + 0x158) = (u8)j;
                    *(blk + 0x159) = (u8)i;
                    *(blk + 0x14C) = 1;
                    return ret;
                }
            }
        }
    }
    return ret;
}
#pragma pop

// FUN_002B07A0
void func_002b07a0(u8 *arg0, u8 *arg1) {
    u8 *fp;
    u8 buf[0x80];
    u8 v;

    fp = (u8 *)D_00887300;
    ((void (**)(s32, s32))fp)[0](6, 1);
    ((void (**)(s32, s32))fp)[0](7, 2);
    ((void (**)(s32, s32))fp)[0](8, 1);
    ((void (**)(s32, s32))fp)[0](9, 2);
    ((void (**)(s32, s32))fp)[0](0xC, 1);
    ((void (**)(s32, s32))fp)[0](2, 3);
    ((void (**)(s32, s32))fp)[0](0xB, 6);
    ((void (**)(s32, s32))fp)[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    if (*(u8 *)(arg1 + 5) == 3) {
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x110) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x114) = *(f32 *)(arg1 + 0x28);
    } else {
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x110) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x114) = *(f32 *)(arg1 + 0x20);
    }
    v = *(u8 *)(arg1 + 4);
    if (v >= 9) {
        if (*(u8 *)(arg1 + 5) == 1) {
            switch (v) {
            case 9:
            case 10:
                sprintf(buf, D_0063EFF0, v);
                break;
            case 11:
            case 12:
                sprintf(buf, D_0063F010, v);
                break;
            case 13:
            case 14:
                sprintf(buf, D_0063EFF0, v);
                break;
            }
        } else if (*(u8 *)(arg1 + 5) == 3) {
            sprintf(buf, D_0063EFF0, v);
        } else {
            switch (v) {
            case 9:
            case 10:
                sprintf(buf, D_0063F030, v);
                break;
            case 11:
            case 12:
                sprintf(buf, D_0063F050, v);
                break;
            case 13:
            case 14:
                sprintf(buf, D_0063F070, v);
                break;
            }
        }
    } else if (v == 2) {
        if (*(u8 *)(arg1 + 5) == 1) {
            sprintf(buf, D_0063F090, v);
        } else {
            sprintf(buf, D_0063F0B0, v);
        }
    } else {
        sprintf(buf, D_0063F0D0, v);
    }
    ((void (**)(s32, s32))fp)[0](1, *(s32 *)func_003ef650(func_003ef6d0(), buf));
}

extern u8 D_00793E80[];

#pragma push
#pragma opt_loop_invariants on
/* Four map-cell corners are stored as complete X/Y/Z vectors, then copied
 * into the existing 0x40-byte screen-vertex records. Unsigned color conversion
 * and the render-device depth field preserve the original invariant placement.
 * Native b210 -O2: 1412/1424 bytes; all relocations and twelve zero tail bytes.
 * See docs/probe_archive/Map_shape_002b0b10_20260924.md. */
// FUN_002B0B10
void func_002b0b10(u8 *task, YVec2f position, f32 width, f32 height, f32 depth, u8 origin, f32 scale, s32 color, s8 orientation, s32 layer) {
    YVec3f corners[4];
    typedef struct SMapRenderDevice {
        f32 gamma;
        s32 (*system)(s32, void *, void *, s32);
        f32 nearDepth;
        f32 farDepth;
        s32 (*setState)(s32, void *);
        s32 (*getState)(s32, void *);
        u32 renderCallbacks[8];
    } SMapRenderDevice;
    extern SMapRenderDevice D_008872F0;
    f32 reciprocalZ;
    f32 scaledWidth;
    f32 scaledHeight;
    f32 baseY;
    u8 *cell;
    s32 cornerMode;
    cell = *(u8 **)(task + 0x38);
    reciprocalZ = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    *(f32 *)(cell + 0x38) = reciprocalZ;
    scaledWidth = width * scale;
    scaledHeight = height * scale;
    cornerMode = origin & 0xFF;
    baseY = position.y;
    switch (cornerMode) {
    case 0:
        corners[0].x = position.x;
        corners[0].y = 0.0f;
        corners[0].z = baseY;
        corners[1].x = position.x + scaledWidth;
        corners[1].y = 0.0f;
        corners[1].z = baseY;
        corners[2].x = position.x;
        corners[2].y = 0.0f;
        corners[2].z = baseY + scaledHeight;
        corners[3].x = position.x + scaledWidth;
        corners[3].y = 0.0f;
        corners[3].z = baseY + scaledHeight;
        break;
    case 1: {
        s32 v = orientation;
        if (v == 0) {
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY + scaledHeight;
            corners[3].x = position.x + scaledWidth;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
        } else if (v == 1) {
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledWidth;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY;
            corners[2].x = position.x + scaledHeight;
            corners[2].y = 0.0f;
            corners[2].z = baseY + scaledWidth;
            corners[3].x = position.x + scaledHeight;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
        } else if (v == 2) {
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY - 18.0f;
            corners[3].x = (position.x + scaledWidth);
            corners[3].y = 0.0f;
            corners[3].z = baseY - 18.0f;
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = (baseY + scaledHeight) - 18.0f;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = (baseY + scaledHeight) - 18.0f;
        }
        break;
    }
    case 2: {
        s32 v = orientation;
        if (v == 0) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        } else if (v == 1) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        } else if (v == 2) {
            corners[3].x = position.x - 18.0f;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = (position.x + scaledWidth) - 18.0f;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x - 18.0f;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = (position.x + scaledWidth) - 18.0f;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        }
        break;
    }
    case 3: {
        s32 v = orientation;
        if (v == 0) {
            corners[2].x = position.x;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY;
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY + scaledHeight;
            corners[1].x = position.x + scaledWidth;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
        } else if (v == 1) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY + scaledWidth;
            corners[2].x = position.x;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x + scaledHeight;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledWidth;
            corners[0].x = position.x + scaledHeight;
            corners[0].y = 0.0f;
            corners[0].z = baseY;
        }
        break;
    }
    }
    {
        u32 red;
        u32 green;
        u32 blue;
        u32 alpha;
        s32 i;
        red = ((u32)(color & 0xFF000000) >> 24) & 0xFF;
        green = ((u32)(color & 0xFF0000) >> 16) & 0xFF;
        blue = ((u32)(color & 0xFF00) >> 8) & 0xFF;
        alpha = color & 0xFF;
        i = 0;
        while (i < 4) {
            u8 *record = cell + (i << 6);
            YVec3f *point;
            *(f32 *)(record + 0x48) = D_008872F0.nearDepth - depth;
            *(f32 *)(record + 0x58) = reciprocalZ;
            *(f32 *)(record + 0x60) = (f32)red;
            *(f32 *)(record + 0x64) = (f32)green;
            *(f32 *)(record + 0x68) = (f32)blue;
            *(f32 *)(record + 0x6C) = (f32)alpha;
            point = &corners[i];
            *(f32 *)(record + 0x40) = point->x;
            *(f32 *)(record + 0x44) = point->z;
            i++;
        }
    }
    {
        u8 *packet = (u8 *)func_00461390((u8 *)&D_00793E80 + ((s16)layer * 0x30), 4, cell + 0x40, 4);
        *(void (**)(u8 *, u8 *))(packet + 8) = func_002b07a0;
        *(u8 **)(packet + 0x10) = cell;
    }
}
#pragma pop


// FUN_002B10A0
void func_002b10a0(u8 *arg0, YVec2f arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(YVec2f *)(p + 0x10) = arg1;
    *(s8 *)(p + 0x15A) = 1;
}

// FUN_002B10D0
void func_002b10d0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x15A) = arg1;
}

// FUN_002B10E0
void func_002b10e0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x143) = arg1;
}

// FUN_002B10F0
void func_002b10f0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x144) = arg1;
}
// FUN_002B1100
void func_002B1100(void *param_1,u32 param_2,u32 param_3)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 1200.0f * (float)param_2;
  vector.z = 1200.0f * (float)param_3;
  *(YVec3f *)param_1 = vector;
}

#pragma pop


#pragma push


/* Return-width audit: retail callers of func_002b11c0 and func_002b1210
   consume the result directly with andi, sb, or mtc1 and emit no
   dsll32/dsra32 sign-extension pair. Keep both returns wide (int): changing
   either to s8 introduces the pair and regresses the caller by two words.
   A missing pair means a callee return was declared too wide; an extra pair
   means it was declared too narrow. */
// FUN_002B11C0
int func_002B11C0(RwV3d param_1)

{
  return (int)((param_1.x + 600.0f) / 1200.0f);
}

#pragma pop


#pragma push


// FUN_002B1210
int func_002B1210(RwV3d param_1)

{
  return (int)((param_1.z + 600.0f) / 1200.0f);
}

#pragma pop

/* measured: re-tested wave 4 (nd 11, was recorded nd 1). The lwc1-copy
   shape is the u8 buf[0xC] + `v2 = *(YVec3f *)buf` spelling (local-to-local
   struct copies compile to ld/sd, pointer/buf-source copies to lwc1 x3);
   with that copy the mul.s $f1,$f2,$f0 (const-in-fs) MATCHES retail — the
   old note's "mul canonicalization floor" is wrong. The residual is the
   p-load: retail lwc1 0x40($sp) sits after sub.s $f1,$f1,$f0, mwcc b210
   hoists it into the post-cvt nop slot (obj 188B vs window 192B), which
   also rotates the two subs (sub.s $f0,$f1,$f0 / sub.s $f3,$f3,$f0 vs
   retail $f1/$f0). Tried 6 orderings (q-before-p, k-split, x-local,
   reversed decls, buf-indexed read, computed ptr) — all nd 11-38.
   Load-hoist/schedule floor. */
// FUN_002B1260
f32 func_002b1260(u8 *arg0, f32 arg1) {
    YVec3f v2;
    u8 buf[0xC];
    f32 t, p, q;

    func_001687f0(buf, arg0);
    v2 = *(YVec3f *)buf;
    t = (s32)func_001687d0(arg0);
    p = t * 1200.0f;
    p -= 600.0f;
    p = v2.x - p;
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}

/* measured: re-tested wave 4 (nd 11, was recorded nd 1) — same result as
   func_002b1260: u8 buf[0xC] + `v2 = *(YVec3f *)buf` reproduces the lwc1
   copy and the mul.s $f1,$f2,$f0 (const-in-fs) matches retail; the residual
   is mwcc b210 hoisting the p-load (lwc1 0x48($sp)) into the FP-latency
   nop (obj 188B vs window 192B) with the two sub.s registers rotated
   ($f0/$f3 vs retail $f1/$f0). Self-referential t = t*1200.0f sinks the
   load to mid-chain but flips const to $f4/result $f2 (nd 10); const-first
   and named-m variants stay nd 11. Load-hoist/schedule floor, same as
   func_002b1260. */
// FUN_002B1320
f32 func_002b1320(u8 *arg0, f32 arg1) {
    YVec3f v2;
    u8 buf[0xC];
    f32 t, p, q;

    func_001687f0(buf, arg0);
    v2 = *(YVec3f *)buf;
    t = (s32)func_001687e0(arg0);
    p = t * 1200.0f;
    p -= 600.0f;
    p = v2.z - p;
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}
// FUN_002B13E0
f32 func_002b13e0(f32 arg1, YVec3f *arg0) {
    YVec3f v1, v2;
    f32 t, p, q;

    v1 = *arg0;
    v2 = v1;
    t = (s32)((v2.x + 600.0f) / 1200.0f);
    p = v1.x - (t * 1200.0f - 600.0f);
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}

// FUN_002B1480
f32 func_002b1480(f32 arg1, YVec3f *arg0) {
    YVec3f v2, v3, v1;
    f32 t, p, q;

    v1 = *arg0;
    v2 = v1;
    v3 = v1;
    t = (s32)((v3.z + 600.0f) / 1200.0f);
    p = v2.z - (t * 1200.0f - 600.0f);
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}

/* MATCH: 3356B of the 3360B retail window, including resolved relocations and
   owned data. The final sprite loop uses a size_t slot index beside its signed
   16-bit counter; these separate conversions reproduce retail's index lifetime.
   The float->byte guards are plain casts here (`(u8)t4n`, `(u16)sa`; b210 emits the
   c.le.s/or 0x80000000 unsigned conversion itself), the fill/clear loops are ordinary `for` loops with the
   entry branch to the test (not do-while), the 255.0f-t and 4096.0f*a results go to fresh locals (t3n/t4n/sa:
   reusing t3/t4/a picks different $f registers and mul operand order), a is declared before b (retail $f21/$f20),
   `i1 = 0` and `k = 0` are written before the value they precede in retail (`i1 = 0; t4n = ...`), and the two
   ld/sd prologue copies write sp+8 from iGpffffa840 then sp+0 from iGpffffa848.
   opt_loop_invariants on hoists the guard compare/lui out of the loops. */
// FUN_002B1520
#pragma push
#pragma opt_loop_invariants on
void func_002b1520(s32 arg0, u8 *q) {
    u32 base;
    u8 sp[0x10];
    f32 a;
    f32 b;
    f32 c;
    f32 sa;
    s16 i1;
    s16 j1;
    s16 i2;
    s16 j2;
    s16 i3;
    s16 j3;
    s16 i4;
    s16 j4;
    s16 k;
    (void)arg0;
    a = 1.0f;
    *(s64 *)(sp + 8) = iGpffffa840;
    *(s64 *)(sp + 0) = iGpffffa848;
    b = 120.0f;
    c = (f32)395;
    base = (u32)D_00887300;
    ((void (*)(s32, s32))*(u32 *)base)(6, 1);
    ((void (*)(s32, s32))*(u32 *)base)(7, 2);
    ((void (*)(s32, s32))*(u32 *)base)(8, 1);
    ((void (*)(s32, s32))*(u32 *)base)(9, 2);
    ((void (*)(s32, s32))*(u32 *)base)(0xC, 1);
    ((void (*)(s32, s32))*(u32 *)base)(0xB, 6);
    ((void (*)(s32, s32))*(u32 *)base)(0xA, 5);
    ((void (*)(s32, s32))*(u32 *)base)(2, 4);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    switch (*(s8 *)(q + 4)) {
    case 0:
    case 1:
        break;
    case 2: {
        f32 t1;
        f32 t2;
        f32 t3;
        f32 t4;
        f32 t3n;
        f32 t4n;
        u8 bv;
        t1 = func_002b2aa0(0, 179.0f, 312.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t2 = func_002b2aa0(0, (f32)443, 312.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t3 = func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t4 = func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s16 *)(q + 0x766), 5.0f);
        *(f32 *)(*(u8 **)(q + 0x7C) + 8) = t1;
        *(f32 *)(*(u8 **)(q + 0x80) + 8) = t2;
        t3n = 255.0f - t3;
        bv = (u8)t3n;
        *(u8 *)(*(u8 **)(q + 0x80) + 0x10) = bv;
        *(u8 *)(*(u8 **)(q + 0x7C) + 0x10) = bv;
        i1 = 0;
        t4n = 255.0f - t4;
        for (; i1 < 3; i1++) {
            for (j1 = 0; j1 < 6; j1++) {
                u8 vv;
                vv = (u8)t4n;
                *(u8 *)(*(u8 **)(q + (s32)i1 * 0x18 + (s32)j1 * 4 + 0x34) + 0x10) = vv;
            }
        }
        func_0046b380(*(u8 **)(q + 0x7C), 0);
        func_0046b380(*(u8 **)(q + 0x80), 0);
        for (i2 = 0; i2 < 3; i2++) {
            for (j2 = 0; j2 < 6; j2++) {
                func_0046b380(*(u8 **)(q + (s32)i2 * 0x18 + (s32)j2 * 4 + 0x34), 0);
            }
        }
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)327, 264.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)327, (f32)341, (f32)*(s16 *)(q + 0x764), 10.0f);
        a = func_002b2aa0(0, iGpffff84f4, 1.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        b = func_002b2aa0(0, 183.0f, 120.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        c = func_002b2aa0(0, 332.0f, (f32)395, (f32)*(s16 *)(q + 0x764), 10.0f);
        break;
    }
    case 3: {
        f32 t1;
        f32 t2;
        f32 t3;
        f32 t4;
        f32 t3n;
        f32 t4n;
        u8 bv;
        t1 = func_002b2aa0(0, 312.0f, 179.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        t2 = func_002b2aa0(0, 312.0f, (f32)443, (f32)*(s16 *)(q + 0x764), 5.0f);
        t3 = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        t4 = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s16 *)(q + 0x766), 5.0f);
        *(f32 *)(*(u8 **)(q + 0x7C) + 8) = t1;
        *(f32 *)(*(u8 **)(q + 0x80) + 8) = t2;
        t3n = 255.0f - t3;
        bv = (u8)t3n;
        *(u8 *)(*(u8 **)(q + 0x80) + 0x10) = bv;
        *(u8 *)(*(u8 **)(q + 0x7C) + 0x10) = bv;
        i3 = 0;
        t4n = 255.0f - t4;
        for (; i3 < 3; i3++) {
            for (j3 = 0; j3 < 6; j3++) {
                u8 vv;
                vv = (u8)t4n;
                *(u8 *)(*(u8 **)(q + (s32)i3 * 0x18 + (s32)j3 * 4 + 0x34) + 0x10) = vv;
            }
        }
        *(f32 *)(sp + 12) = func_002b2aa0(0, 264.0f, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)341, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        a = func_002b2aa0(0, 1.0f, iGpffff84f4, (f32)*(s16 *)(q + 0x764), 5.0f);
        b = func_002b2aa0(0, 120.0f, 183.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        c = func_002b2aa0(0, (f32)395, 332.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        /* fallthrough */
    }
    case 4:
        func_0046b380(*(u8 **)(q + 0x7C), 0);
        func_0046b380(*(u8 **)(q + 0x80), 0);
        for (i4 = 0; i4 < 3; i4++) {
            for (j4 = 0; j4 < 6; j4++) {
                func_0046b380(*(u8 **)(q + (s32)i4 * 0x18 + (s32)j4 * 4 + 0x34), 0);
            }
        }
        break;
    case 5:
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)327, 264.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)327, (f32)341, (f32)*(s16 *)(q + 0x764), 10.0f);
        a = func_002b2aa0(0, iGpffff84f4, 1.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        b = func_002b2aa0(0, 183.0f, 120.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        c = func_002b2aa0(0, 332.0f, (f32)395, (f32)*(s16 *)(q + 0x764), 10.0f);
        func_002b3c60(*(u8 **)(q + 0xCC), 0);
        break;
    case 6:
        *(f32 *)(sp + 12) = func_002b2aa0(0, 264.0f, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)341, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        a = func_002b2aa0(0, 1.0f, iGpffff84f4, (f32)*(s16 *)(q + 0x764), 5.0f);
        b = func_002b2aa0(0, 120.0f, 183.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        c = func_002b2aa0(0, (f32)395, 332.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        func_002b3c60(*(u8 **)(q + 0xCC), 1);
        break;
    default:
        break;
    }
    if (a > iGpffff84f4) {
        *(f32 *)(*(u8 **)(q + 0x28) + 0xC) = *(f32 *)(sp + 12);
        *(f32 *)(*(u8 **)(q + 0x24) + 0xC) = *(f32 *)(sp + 12);
        *(f32 *)(*(u8 **)(q + 0x30) + 0xC) = *(f32 *)(sp + 4);
        *(f32 *)(*(u8 **)(q + 0x2C) + 0xC) = *(f32 *)(sp + 4);
        k = 0;
        sa = a * 4096.0f;
        for (; k < 4; k++) {
            size_t slotIndex = k;
            u8 **pp = (u8 **)(q + slotIndex * 4 + 0x24);
            u16 ww;
            ww = (u16)sa;
            *(u16 *)(*pp + 0x22) = ww;
            func_0046b380(*pp, 0);
        }
    }
    *(f32 *)(func_002b2940(*(u8 **)(q + 0xBC)) + 0x10) = b;
    *(f32 *)(func_002b2940(*(u8 **)(q + 0xC4)) + 8) = c;
}
#pragma opt_loop_invariants off
#pragma pop

// FUN_002B2240
void func_002b2240(u8 *arg0) {
    u8 *q = *(u8 **)(arg0 + 0x38);

    if (D_0076464C != 0) {
        *(s32 *)(q + 0x84) = 0;
        *(s32 *)(q + 0x88) = 0;
        func_00460ac0(&D_00794C90[0], q + 0x84);
    }
}

/* measured: object 620B/window 624B, normalized_diff 0. Levers: (1) the
   slot pointer is `p = &q->b[j]` (struct-member address), which makes the
   compiler redo the s16 sign-extension at the loop head instead of reusing
   the tail's copy; (2) `opt_loop_invariants on` hoists the two loop-3 float
   constants into `$a0`/`$v1` and fixes loop 1's commutative `addu`; (3) the
   unfused `add.s $f20,$f0,$f1` is `y = t; z = -99.0f + y;` - the copy stops
   b210 fusing `c + a*b` into `adda.s`/`madd.s`, and the fresh name `z`
   gives the constant-first operand order (a self-update `y = -99.0f + y`
   is variable-first). Prior archive: build/WBYList_y_smap_2290_candidate.c
   (nd 409). */
// FUN_002B2290
/* measured: opt_loop_invariants on hoists the loop-3 float constants into
   $a0/$v1 and fixes loop 1 addu operand order (nd 18 -> 0 with it). */
#pragma opt_loop_invariants on
void func_002b2290(u8 *arg0)
{
    typedef struct {
        u8 pad0[0x8];
        f32 x;
        f32 y;
    } SmapItem;
    typedef struct {
        u8 pad0[0x24];
        SmapItem *a[4];
        SmapItem *b[6];
        SmapItem *c[6];
        SmapItem *d[6];
        SmapItem *e[2];
        u8 tail[0x30];
    } SmapWork;
    s16 i;
    SmapWork *q;
    s16 j;
    SmapItem **p;
    s16 k;
    f32 y;
    f32 t;
    f32 z;

    q = *(SmapWork **)(arg0 + 0x38);
    for (i = 0; i < 4; i++) {
        /* sdkSpr consumes the resource handle as an unsigned storage word. */
        q->a[i] = (SmapItem *)func_0046d200(*(u32 *)&D_00764644, i + 3);
    }
    q->a[0]->x = 17.0f;
    q->a[0]->y = 264.0f;
    q->a[1]->x = 94.0f;
    q->a[1]->y = 264.0f;
    q->a[2]->x = 17.0f;
    q->a[2]->y = 341.0f;
    q->a[3]->x = 94.0f;
    q->a[3]->y = 341.0f;
    for (j = 0; j < 6; j++) {
        p = &q->b[j];
        *p = (SmapItem *)func_0046d200(D_00764644, 8);
        (*p)->x = 190.0f;
        t = 108.0f * (f32)j;
        y = t;
        z = -99.0f + y;
        (*p)->y = z;
        p = &q->c[j];
        *p = (SmapItem *)func_0046d200(D_00764644, 8);
        (*p)->x = 298.0f;
        (*p)->y = z;
        p = &q->d[j];
        *p = (SmapItem *)func_0046d200(D_00764644, 9);
        (*p)->x = 406.0f;
        (*p)->y = z;
    }
    q->e[0] = (SmapItem *)func_0046d200(D_00764644, 0xA);
    q->e[1] = (SmapItem *)func_0046d200(D_00764644, 0xB);
    for (k = 0; k < 2; k++) {
        q->e[k]->x = 312.0f;
        q->e[k]->y = -10.0f;
    }
    memset(q->tail, 0, 0x30);
    *(void (**)(s32, u8 *))(q->tail + 0x8) = func_002b1520;
    *(SmapWork **)(q->tail + 0x10) = q;
}
/* measured: closes the loop-invariant bracket; the file default is off. */
#pragma opt_loop_invariants off

// FUN_002B2500
void func_002b2500(void) {
    u8 *fp = (u8 *)D_00887300;

    ((void (**)(s32, s32))fp)[0](6, 1);
    ((void (**)(s32, s32))fp)[0](7, 2);
    ((void (**)(s32, s32))fp)[0](8, 1);
    ((void (**)(s32, s32))fp)[0](9, 2);
    ((void (**)(s32, s32))fp)[0](0xC, 1);
    ((void (**)(s32, s32))fp)[0](0xB, 6);
    ((void (**)(s32, s32))fp)[0](0xA, 5);
    ((void (**)(s32, s32))fp)[0](1, 0);
}

/* measured: four unsigned-byte-to-float sites use plain `(f32)(u32)` casts;
   spelling the compiler's sign-fixup by hand left the candidate at nd 45.
   The final body is object 552B/window 560B and verifier MATCH (normalized
   diff 0). `opt_loop_invariants on`, `schedule off`, and `opt_propagation off`
   keep the global base hoist, loop reload, and retail load order. */
// measured: probe loop invariant placement for the target's global load.
// measured: isolate the target's optimizer probes from following siblings.
#pragma push
#pragma opt_loop_invariants on
// measured: probe scheduler-off load ordering.
#pragma schedule off
// measured: probe propagation-off load ordering.
#pragma opt_propagation off
// FUN_002B25D0
s32 func_002b25d0(u8 *arg0) {
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    s32 var_6;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_5;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f2 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    *(f32 *)(temp_16 + 0x1C) = temp_f2;
    if (D_0076464C == 0) {
        return 0;
    }
    for (var_6 = 0; var_6 < 4; var_6++) {
        temp_5 = temp_16 + (var_6 << 6);
        temp_f1 = *(f32 *)D_008872F8;
        temp_f0 = *(f32 *)(temp_16 + 0x18);
        *(f32 *)(temp_5 + 0x28) = temp_f1 - temp_f0;
        *(f32 *)(temp_5 + 0x38) = temp_f2;
        *(f32 *)(temp_5 + 0x40) =
            (f32)(u32)*(u8 *)(temp_16 + 0x14);
        *(f32 *)(temp_5 + 0x44) =
            (f32)(u32)*(u8 *)(temp_16 + 0x15);
        *(f32 *)(temp_5 + 0x48) =
            (f32)(u32)*(u8 *)(temp_16 + 0x16);
        *(f32 *)(temp_5 + 0x4C) =
            (f32)(u32)*(u8 *)(temp_16 + 0x17);
    }
    *(f32 *)(temp_16 + 0x20) = *(f32 *)(temp_16 + 4);
    *(f32 *)(temp_16 + 0x24) = *(f32 *)(temp_16 + 8);
    *(f32 *)(temp_16 + 0x60) =
        *(f32 *)(temp_16 + 4) + *(f32 *)(temp_16 + 0xC);
    *(f32 *)(temp_16 + 0x64) = *(f32 *)(temp_16 + 8);
    *(f32 *)(temp_16 + 0xA0) = *(f32 *)(temp_16 + 4);
    *(f32 *)(temp_16 + 0xA4) =
        *(f32 *)(temp_16 + 8) + *(f32 *)(temp_16 + 0x10);
    *(f32 *)(temp_16 + 0xE0) =
        *(f32 *)(temp_16 + 4) + *(f32 *)(temp_16 + 0xC);
    *(f32 *)(temp_16 + 0xE4) =
        *(f32 *)(temp_16 + 8) + *(f32 *)(temp_16 + 0x10);
    temp_2 = func_00461390(D_00794D50, 4, temp_16 + 0x20, 4);
    *(void (**)(void))(temp_2 + 8) = func_002b2500;
    *(u8 **)(temp_2 + 0x10) = temp_16;
    return 0;
}
// measured: restore the file optimizer state after the target.
#pragma pop

// FUN_002B2800
void func_002b2800(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
/* The returned task owns the rectangle work. Retail retains this pointer in
   v0 through the work initialization: 260B/272B, twelve resolved references
   exact, and every sibling body, reference and owned data section preserved.
   Proof: build/cos20814/worker3-ui/rectangle_relocation_proof.json. */
// FUN_002B2830
u8 *func_002b2830(u8 *arg0, YVec2f arg1, f32 arg2, f32 arg3, u32 arg4) {
    u8 *p;
    u8 *task;

    func_0044ea90(D_0063EF60, 0x97A);
    p = D_008873F4[0](1, 0x120, 0x40000);
    task = func_00451fc0((void *)((s32)arg0), (const void *)(D_0063F0F0), 0xF, 0, 0, func_002b25d0, func_002b2800, (u8 *)(p));
    *(u32 *)p = (u32)p;
    *(YVec2f *)(p + 4) = arg1;
    *(f32 *)(p + 0xC) = arg2;
    *(f32 *)(p + 0x10) = arg3;
    *(YRGBA *)(p + 0x14) = *(YRGBA *)&arg4;
    *(f32 *)(p + 0x18) = 60000.0f;
    return task;
}

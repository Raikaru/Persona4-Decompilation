#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_smap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
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
extern u8 *func_0046d200(s32 a, s32 b);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern char D_0063EFD8[];
extern void func_003f6440(s32 a, s32 b);
extern s32 func_00442088(void *dst, const char *fmt, s32 value);
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
extern void func_00454bd0(u8 *ptr);
extern s32 func_004553c0(u8 *ptr);
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
extern s32 func_001687d0(void *arg0);
extern s32 func_001687e0(void *arg0);

typedef struct YVec3f { f32 x, y, z; } YVec3f;
typedef struct YVec2f { f32 x, y; } YVec2f;
typedef struct YRGBA { u8 a, b, c, d; } YRGBA;

/* func_002afbc0 callees */
extern s32 func_002b2a30(u8, u8, u8, u8);
extern void func_002b2bd0(f32 *, s32, f32, f32, f32, f32);
extern s32 func_00106330(s32);
extern u8 *func_00155280(void);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void func_002b0b10(u8 *, YVec2f, u8, s32, s8, s32, f32, f32, f32, f32);
extern u8 D_00794DB0[];
extern u8 D_00794CF0[];
extern u8 D_0076465C;   /* gp-relative, -0x4A94 */
extern u8 D_00764660;   /* gp-relative, -0x4A90 */

/* func_002b1520 callees */
extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
extern void func_0046b380(u8 *, s32);
extern void func_002b3c60(s32, s32);
extern u8 *func_002b2940(s32);
extern s64 iGpffffa840;  /* gp-relative, -0x57C0 */
extern s64 iGpffffa848;  /* gp-relative, -0x57B8 */
extern f32 iGpffff84f4;  /* gp-relative, -0x7B0C */
/* func_002add90 callees (re-derived v2, probe nd 354) */
extern u8 *D_007EFA04;
extern u8 D_007E8C00[];
extern u8 D_00794C30[];
extern u8 D_00794E10[];
extern u8 *func_00460990(void);
extern void func_002b2290(u8 *);
extern s16 func_002b2cb0(s32, s32, s32, s32, s32);
extern s32 func_002b6850(u8 *);
extern void func_002b67a0(u8 *, s32, s32);
extern s32 func_002b4a10(u8 *, s8);
extern void func_002ac750(s32, s32);
extern void func_002b31a0(u8 *, u8 *, u8 *);
extern s32 func_00452490(u8 *);
extern void func_002b10a0(u8 *, YVec2f);
extern void func_002b10e0(u8 *, s8);
extern void func_002b2240(u8 *);
extern int func_002B11C0();
extern int func_002B1210();
/* func_002af3e0 callees (re-derived v1, probe nd 410) */
extern u8 D_007E80A0[];
extern s32 D_00764654;
extern void func_002b3c50(u8 *);
extern void func_002b4ac0(u8 *, s8);
extern void func_002b5100(u8 *, s8);
extern void func_002b4240(u8 *, s8);
extern void func_002b2970(void *, f32, f32);
extern void func_002b69b0(u8 *, YVec2f, YVec2f, u32, u32, s16);
extern void func_002b6a40(u8 *, u32, u32, u32, u32, s32);
extern void func_002b6ac0(u8 *, u32, u32, s32, f32, f32, f32, f32);
extern void func_002b6be0(u8 *, YVec2f, u32, f32);
extern f32 func_0046b2f0(u8 *);
extern void func_002b10d0(u8 *, s8);
extern void func_002b10f0(u8 *, s8);

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};





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
        if (func_004553c0(*(u8 **)p) != 0) {
            *(s32 *)(p + 8) = func_004667d0(0, D_0063EFB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s8 *)(p + 4) += 1;
        }
        break;
    case 4:
        D_00764648 = func_004669d0(*(s32 *)(p + 8), &x, 0);
        if (x != 0) {
            *(s32 *)(p + 8) = 0;
            func_00454bd0(*(u8 **)p);
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
// FUN_002AC750 NONMATCHING
#ifdef NON_MATCHING
void func_002ac750(s32 arg0, s32 arg1) {
    extern s16 func_002b2d00(s32, s32, s32, s32, s32);
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
                                temp_5_3 = (u16 *)((temp_16_2 * 2) + D_00764658 + (temp_18_3 * 2));
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
                            temp_5_13 = (u16 *)((temp_16_5 * 2) + D_00764658 + (temp_19_5 * 2));
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



/* measured: re-derived v2 (probe_variants v1 386 -> v2 354; measure_guarded obj 1928B/window 1936B GUARDED_SCORE 354; fnalign retail 482 obj 482, 203 edits +8 reloc-only). 3% check: window 1936B range 1878-1994B, obj 1928B within (0.4% under) — bankable floor. pragma_sweep singles (incl. optimization_level 0/1/3/4): base 354; loop_invariants on 354 tie, propagation off 354 tie, strength off 354 tie, unroll off 354 tie; dead_assign off 366, level4 400, schedule on 402, level3 404, common_subs off 450, level1 450, peephole off 451, level0 549 — all regress/tie, keep base (level 2, no pragma). TU-strict: (u8 *)(u32)/ (s8)/(s16)/YVec2f-by-value/u8 buf[0xC]+v. Residuals: saved-reg rotation, i-loop folding, ok-beqz vs sltu, D_EFA04 gp-vs-abs. Prior 315 body lost, history. verify ASM (prod stays ASM), lint 0e/1w (pre-existing 2290 H003), -DNON_MATCHING compiles. */
// FUN_002ADD90 NONMATCHING
#ifdef NON_MATCHING
s32 func_002add90(u8 *arg0) {
    u8 buf[0xC];
    YVec3f v;
    f32 spA8;
    f32 sp98;
    f32 spD8;
    f32 spDC;
    u8 *p;
    u8 *tmp;
    u8 *tmp2;
    u8 *q;
    s32 t16;
    s32 t18;
    s32 t19;
    s32 t20;
    s32 t22;
    s32 t23;
    s32 t182;
    s32 t192;
    s32 t222;
    s32 ok;
    s32 var16;
    s16 var18;
    s16 var19;
    s16 tt;
    s16 tt2;
    p = *(u8 **)(arg0 + 0x38);
    func_001687f0(buf, *(u8 **)(D_007EFA04 + 0x220));
    v = *(YVec3f *)buf;
    tmp = (u8 *)func_00460990();
    *(void (**)(s32, u8 *))((u8 *)tmp + 8) = (void (*)(s32, u8 *))func_002add10;
    *(u8 **)((u8 *)tmp + 0x10) = p;
    func_00460ac0(D_00794C30, tmp);
    tmp2 = (u8 *)func_00460990();
    *(void (**)(u8 *, u8 *))((u8 *)tmp2 + 8) = (void (*)(u8 *, u8 *))func_002add60;
    *(u8 **)((u8 *)tmp2 + 0x10) = p;
    func_00460ac0(D_00794E10, tmp2);
    switch (*(s8 *)(p + 4)) {
    case 0:
        func_002b2290(arg0);
        *(s8 *)(p + 4) = (s8)(*(s8 *)(p + 4) + 1);
        return 0;
    case 2:
        *(s16 *)(p + 0x766) = func_002b2cb0((s32)*(s16 *)(p + 0x766), 1, 5, 0, 1);
        if ((s8)func_002b6850(*(u8 **)(p + 0x748)) == 0) {
            func_002b67a0(*(u8 **)(p + 0x748), 0, 1);
        }
        if ((s8)func_002b6850(*(u8 **)(p + 0x74C)) == 0) {
            func_002b67a0(*(u8 **)(p + 0x74C), 0, 1);
        }
        /* fallthrough */
    case 5:
        *(s16 *)(p + 0x764) = func_002b2cb0((s32)*(s16 *)(p + 0x764), 1, 0xA, 0, 1);
        /* fallthrough */
    case 1:
        *(s8 *)(p + 0xB8) = 0;
        var16 = 0;
        while (var16 < 0xF) {
            ok = 0;
            q = (u8 *)((u8 *)&D_007E8C00 + var16 * 0x750);
            if (*(s32 *)(q + 0x48) != 0 && *(s32 *)(q + 0x54) != 0) {
                ok = 1;
            }
            if ((ok != 0) == 1) {
                if (*(s32 *)((u8 *)p + var16 * 4 + 0xD8) == 0) {
                    *(s32 *)((u8 *)p + var16 * 4 + 0xD8) = func_002b4a10(arg0, (s8)var16);
                }
            }
            var16 += 1;
        }
        t18 = func_002B11C0(v) & 0xFF;
        t20 = func_002B1210(v) & 0xFF;
        func_002ac750(t18, t20);
        t16 = (t20 & 0xFF) << 8;
        t19 = t18 & 0xFF;
        t23 = t19 * 0x10;
        if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t23 + 0x64) == 1) {
            if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t23 + 0x5E) & 8) {
                if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t23 + 0x5F) & 8) {
                    if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t23 + 0x5F) & 0x80) {
                        func_002ac750((t19 + 1) & 0xFF, t20);
                    }
                } else {
                    func_002ac750((t19 + 1) & 0xFF, t20);
                }
            }
        }
        if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t23 + 0x44) == 1) {
            t22 = (t18 & 0xFF) * 0x10;
            if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t22 + 0x5E) & 2) {
                if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t22 + 0x5F) & 2) {
                    if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t22 + 0x5F) & 0x20) {
                        func_002ac750((t19 - 1) & 0xFF, t20);
                    }
                } else {
                    func_002ac750((t19 - 1) & 0xFF, t20);
                }
            }
        }
        t182 = t20 & 0xFF;
        t222 = t182 << 8;
        t192 = (t18 & 0xFF) * 0x10;
        if (*(u8 *)((u8 *)(u32)func_00155280() + t222 + t192 - 0xAC) == 1) {
            if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5E) & 1) {
                if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5F) & 1) {
                    if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5F) & 0x10) {
                        func_002ac750(t18, (t182 - 1) & 0xFF);
                    }
                } else {
                    func_002ac750(t18, (t182 - 1) & 0xFF);
                }
            }
        }
        if (*(u8 *)((u8 *)(u32)func_00155280() + t222 + t192 + 0x154) == 1) {
            if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5E) & 4) {
                if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5F) & 4) {
                    if (*(u8 *)((u8 *)(u32)func_00155280() + t16 + t192 + 0x5F) & 0x40) {
                        func_002ac750(t18, (t182 + 1) & 0xFF);
                    }
                } else {
                    func_002ac750(t18, (t182 + 1) & 0xFF);
                }
            }
        }
        func_002b31a0((u8 *)&spA8, p + 8, (u8 *)&v);
        spD8 = (f32)(spA8 / *(f32 *)((u8 *)&iGpffff84f4 + 4));
        func_002b31a0((u8 *)&sp98, p + 8, (u8 *)&v);
        spDC = (f32)(sp98 / *(f32 *)((u8 *)&iGpffff84f4 + 4));
        var18 = 0;
        while (var18 < 0xD) {
            var19 = 0;
            while (var19 < 0xD) {
                tt = (s16)(var18 + (s16)((s32)func_001687d0(*(u8 **)(D_007EFA04 + 0x220)) - 6));
                tt2 = (s16)(var19 + (s16)((s32)func_001687e0(*(u8 **)(D_007EFA04 + 0x220)) - 6));
                if ((s32)tt > 0) {
                    if ((s32)tt2 > 0 && (s32)tt < 0x10 && (s32)tt2 < 0x18) {
                        q = (u8 *)p + ((s32)tt2 << 6) + ((s32)tt * 4);
                        if (func_00452490(*(u8 **)(q + 0x148)) == 1) {
                            if ((((1 << ((s32)tt & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[(s32)tt2 & 0xFF]) >> ((s32)tt & 0xFF)) == 1) {
                                func_002b10e0(*(u8 **)(q + 0x148), 1);
                            }
                            {
                                YVec2f vv;
                                *(s64 *)&vv = *(s64 *)&spD8;
                                func_002b10a0(*(u8 **)(q + 0x148), vv);
                            }
                        }
                    }
                }
                var19 = (s16)(var19 + 1);
            }
            var18 = (s16)(var18 + 1);
        }
        func_002b2240(arg0);
        return 0;
    case 3:
        *(s16 *)(p + 0x766) = func_002b2cb0((s32)*(s16 *)(p + 0x766), 1, 5, 0, 1);
        /* fallthrough */
    case 6:
        *(s16 *)(p + 0x764) = func_002b2cb0((s32)*(s16 *)(p + 0x764), 1, 5, 0, 1);
        /* fallthrough */
    case 4:
        func_002b2240(arg0);
        return 0;
    case 7:
        return -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002add90);
#endif

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

/* measured: skipped — the m2c draft hits M2C_ERROR at the two FPU
   multiply-accumulate sites in the D_007E80A0 loop (adda.s $f0,$f1;
   madd.s $f20,$f12,$f2 wrapping the func_002b11c0/func_002b13e0 and
   func_002b1210/func_002b1480 call pairs), so the operand structure of
   those two sp1F8/sp1FC expressions is unrecoverable from the draft;
   the madd.s family is the same canonicalization floor as func_002b13e0/
   002b1480 (recorded above). Rest of the draft (func_002b0250 8-arg tile
   loop, func_002b2970/2a60/2830/3990 calls, D_007E8C00/D_007E80A0 loops)
   is intact but untestable without the two expressions. */
/* measured: cold2ae630 first reconstruction (876 instrs). m2c fails outright on jr/jtbl at line 129 (jtbl_00748820 6 entries 0:1f0,2:380,4:50c) so romwright carried it (299 lines, arity 1 pointer, 43 tile-loop 00155280 sites matching retail 43). De-noised to file idiom reusing YVec3f/YVec2f/D_007E80A0/D_007E8C00/D_007EFA04/D_00764644/5C/60/00155280/002b2970/00451fc0. v0 783 (single hoisted q, 677/874 -22% short, missing jals). v1 expanded to 43 calls 810 but 916/876 +4.6% over. Free pragmas on v1: common_off 831, loop_on 813, unroll/sched tie 810 (none kept). Subscript ((u8**)(blk+0x148))[tny*16+tnx] 810->777 (-33, kept) and 916->888. s16 counters 777->842 regress. Minloc drop dead dx/dy/nx/ny tie 777. loop_on on minloc 777->791 regress. Two colourings (blk/res swap, f1/f2 swap) tie 777. Best minloc 777, obj 888/retail 876 +1.4% inside gate (850-902), fnalign 729 edits+22 reloc-only. Residuals: 4 missing 2830 stores (void callee, cannot use return without breaking its MATCH), FPU madd adda/madd canonicalization in D_007E80A0 loop, callee-saved spill choices, s128 staging. */
/* 2026-09-18 `tools/solve_signedness.py`: the read at +0x58 was spelled
   `s8` at one site and `u8` at twelve others; retail loads that offset only
   with `lbu`, so every site is now `u8`.  Census mismatch 22 -> 20 with the
   instruction count unchanged; the differing-word score stays 777 because
   those positions already differ for other reasons, but the type claim is
   now correct and is asserted back through the feedback path.
   The four `D_0063EExx` tables are recorded as free: flipping their element
   type between `s8` and `u8` produces byte-identical code, because each
   loaded byte is immediately assigned to an `s8` local, so the signedness is
   unobservable at those sites.  Do not churn them. */
/* 2026-09-19 caller prototype fix (this session): func_002b0250's local extern
   said (s8,s8,..,s8,s8,..) but retail's caller zero-extends all four masked
   args (andi, no lb/dsll32/dsra32), and both the generated m2c and the def
   body (byte-stores only) agree the params are u8 except arg4. Extern and def
   now (u8,u8,u8,s8,u8,u8,u8); the nine (s8)(tnx&0xFF)/(s8)(tny&0xFF) casts
   dropped, (s8)j/(s8)i spelled (j&0xFF)/(i&0xFF). 729 -> 708 fnalign edits,
   words 777 -> 766, object 888 -> 850 instrs. Neighbor floor func_002b0250
   itself is byte-near-neutral (279 -> 280 words, 275 -> 274 edits). */
/* 2026-09-19 assignment (f20 recovery): split f1/f2 Dome computation to hold the */
/* 18.0f-scaled base across the 002b13e0/002b1480 calls in fbase (single reused */
/* local, matching retail madd.s $f20). floor_distance 730->697 edits (-33), */
/* words 854->831 (-23), object 850->849/retail 874 (both inside 848-900 gate); */
/* regsave_scan now 0 differ (retail 0x210/frame and $f20 match; was 0xE0 vs 0x210 */
/* missing $f20). Commands: floor_distance src/promoted/y_smap.c, regsave_scan */
/* src/promoted/y_smap.c func_002ae630. */
// FUN_002AE630 NONMATCHING
#ifdef NON_MATCHING
u8 *func_002ae630(u8 *arg0) {
    extern s8 D_0063EEE0[];
    extern s8 D_0063EF00[];
    extern s8 D_0063EF20[];
    extern s8 D_0063EF40[];
    extern u8 *func_002b0250(u8 *, u8, u8, u8, s8, u8, u8, u8);
    extern void func_002b2830(u8 *, YVec2f, f32, f32, u32);
    extern void func_002B1100(void *, u32, u32);
    extern f32 func_002b13e0(YVec3f *, f32);
    extern f32 func_002b1480(YVec3f *, f32);
    extern s32 func_002b3990(s32);
    extern s32 func_002b4140(s32, s8, u8 *);
    extern s32 func_002b4fe0(s32, s64, s32);
    extern s32 func_002b6590(s32, s16, s32);
    extern void *func_0047a2f0(s32);
    extern u8 *func_001452b0(s32);
    extern void func_002b2a60(u8 *, s32, s32, s32, s32);
    extern s32 func_002add90(u8 *);
    extern void func_002ae520(u8 *);
    u8 *blk;
    u8 *res;
    s32 t1;
    s32 t2;
    YVec3f v0;
    YVec2f w1;
    YVec2f w2;
    YVec2f w3;
    YVec2f w4;
    u32 c1;
    u32 c2;
    u32 c3;
    u32 c4;
    union { YVec2f v; s64 s; } fv;
    f32 fbase;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u8 *node;
    s32 idx;
    u8 *tmp;
    u8 *v2;
    func_0044ea90(D_0063EF60, 0x389);
    blk = D_008873F4[0](1, 0x768, 0x40000);
    res = (u8 *)(s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0063EFD8), 0xF, 0, 0, func_002add90, func_002ae520, (u8 *)(blk));
    *(u8 **)blk = blk;
    *(blk + 4) = 0;
    t1 = func_001687d0(*(u8 **)(D_007EFA04 + 0x220)) & 0xFF;
    t2 = func_001687e0(*(u8 **)(D_007EFA04 + 0x220)) & 0xFF;
    func_002B1100(&v0, (u32)t1, (u32)t2);
    *(YVec3f *)(blk + 8) = v0;
    D_00764660 = (u8)func_002B11C0(*(RwV3d *)(blk + 8));
    D_0076465C = (u8)func_002B1210(*(RwV3d *)(blk + 8));
    *(blk + 0x20) = 0x12;
    for (i = 0; i < 0x18; i++) {
        u8 *row;
        s32 base;
        row = blk + (i << 6);
        base = i << 8;
        for (j = 0; j < 0x10; j++) {
            s32 col;
            col = j * 0x10;
            if (*(u8 *)(base + (u32)func_00155280() + col + 0x54) != 0 && ((*(u8 *)(base + (u32)func_00155280() + col + 0x55) & 0xF) == 1)) {
                if (*(u8 *)(base + (u32)func_00155280() + col + 0x58) < 9) {
                    if (*(u8 *)(base + (u32)func_00155280() + col + 0x58) == 2) {
                        s8 tdx;
                        u8 tdy;
                        s32 tnx;
                        s32 tny;
                        tdx = D_0063EF40[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2];
                        tdy = D_0063EF40[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 1];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 1, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        tdx = D_0063EF40[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 8];
                        tdy = D_0063EF40[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 9];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 2, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                    } else {
                        ((u8 **)(blk + 0x148))[i * 16 + j] = func_002b0250(res, (j & 0xFF), (i & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 1, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                    }
                } else {
                    switch (*(u8 *)(base + (u32)func_00155280() + col + 0x58)) {
                    case 9:
                    case 10: {
                        s8 tdx;
                        u8 tdy;
                        s32 tnx;
                        s32 tny;
                        tdx = D_0063EEE0[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2];
                        tdy = D_0063EEE0[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 1];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 1, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        tdx = D_0063EEE0[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 8];
                        tdy = D_0063EEE0[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 9];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 2, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        break;
                    }
                    case 11:
                    case 12: {
                        s8 tdx;
                        u8 tdy;
                        s32 tnx;
                        s32 tny;
                        tdx = D_0063EF00[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2];
                        tdy = D_0063EF00[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 1];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 1, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        tdx = D_0063EF00[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 8];
                        tdy = D_0063EF00[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 9];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 2, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        break;
                    }
                    case 13:
                    case 14: {
                        s8 tdx;
                        u8 tdy;
                        s32 tnx;
                        s32 tny;
                        tdx = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2];
                        tdy = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 1];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 1, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        tdx = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 8];
                        tdy = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 9];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 2, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        tdx = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 0x10];
                        tdy = D_0063EF20[*(u8 *)(base + (u32)func_00155280() + col + 0x59) * 2 + 0x11];
                        tnx = j + (s32)tdx;
                        tny = i + (s32)tdy;
                        ((u8 **)(blk + 0x148))[tny * 16 + tnx] = func_002b0250(res, (tnx & 0xFF), (tny & 0xFF), *(u8 *)(base + (u32)func_00155280() + col + 0x58), 3, *(u8 *)(base + (u32)func_00155280() + col + 0x59), (u8)j, (u8)i);
                        break;
                    }
                    }
                }
            }
        }
    }
    func_002b2970(&w1, 17.0f, 150.0f);
    func_002b2a60((u8 *)&c1, 0x80, 0x80, 0x80, 0);
    func_002b2830(res, w1, 240.0f, 120.0f, c1);
    func_002b2970(&w2, 148.0f, 249.0f);
    func_002b2a60((u8 *)&c2, 0x80, 0, 0, 0);
    func_002b2830(res, w2, 150.0f, 231.0f, c2);
    func_002b2970(&w3, 0.0f, 395.0f);
    func_002b2a60((u8 *)&c3, 0, 0x80, 0, 0);
    func_002b2830(res, w3, 151.0f, 121.0f, c3);
    func_002b2970(&w4, 0.0f, 150.0f);
    func_002b2a60((u8 *)&c4, 0, 0, 0x80, 0);
    func_002b2830(res, w4, 23.0f, 395.0f, c4);
    *(s32 *)(blk + 0xCC) = func_002b3990((s32)res);
    for (k = 0; k < 0xF; k++) {
        s32 ok;
        u8 *e;
        ok = 0;
        e = D_007E8C00 + k * 0x750;
        if (*(s32 *)(e + 0x48) != 0 && *(s32 *)(e + 0x54) != 0) {
            ok = 1;
        }
        if (ok == 1) {
            *(s32 *)(blk + k * 4 + 0xD8) = func_002b4a10(res, (s8)k);
        }
    }
    tmp = func_0046d200(D_00764644, 0x12);
    for (m = 0; m < 8; m++) {
        u8 *e;
        e = D_007E80A0 + m * 0x168;
        if (*(s32 *)e != 0) {
            YVec3f *p;
            s32 ti;
            f32 tf;
            p = (YVec3f *)(e + 0x150);
            ti = func_002B11C0(*(RwV3d *)p);
            fbase = (f32)ti * 18.0f + 172.0f;
            tf = func_002b13e0(p, 18.0f);
            fv.v.x = (fbase - tf) - 2.0f;
            ti = func_002B1210(*(RwV3d *)p);
            fbase = (f32)ti * 18.0f + 9.0f;
            tf = func_002b1480(p, 18.0f);
            fv.v.y = (fbase - tf) - 2.0f;
            *(s32 *)(blk + m * 4 + 0x114) = func_002b4fe0((s32)res, fv.s, (m & 0xFF));
        }
    }
    func_0046d280(tmp);
    *(s32 *)(blk + 0x748) = func_002b6590((s32)res, 0xC, D_00764644);
    *(s32 *)(blk + 0x74C) = func_002b6590((s32)res, 0xD, D_00764644);
    node = func_001452b0(3);
    idx = 0;
    *(s32 *)(blk + 0xD4) = 0;
    *(s32 *)(blk + 0xD0) = 0;
    while (node != NULL) {
        v2 = func_0047a2f0(*(s32 *)(node + 0x164));
        *(s32 *)(blk + idx * 4 + 0xD0) = func_002b4140((s32)res, (s8)idx, (u8 *)(v2 + 0x30));
        idx++;
        node = *(u8 **)(node + 0x138);
    }
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ae630);
#endif

/* measured: re-derived v1 (probe_variants 410 base; prior 414->405->408 history stands; measure_guarded base obj 1916B/window 1936B 410; fnalign base retail 482 obj 479, 266 edits). 3% check base: 1916B in 1878-1994B (1.0% under) — bankable. pragma_sweep singles (incl. level 0/1/3/4): dead_assign off 406 + loop_invariants on 406 (both -4, best), strength/unroll 410 tie, schedule on 416, propagation off/level4 423, level3 428, peephole 434, common/level1 466, level0 532. Banked with opt_loop_invariants on (one of the three gated singles): measure_guarded obj 1944B/window 1936B GUARDED_SCORE 406 (0.4% over, 1878-1994B within); fnalign retail 484 obj 486, 254 edits. TU-strict: (s32)/(s8)/(s16)/(f32)/(u8 *)(u32)/YVec2f-by-value/(s32)46d200 casts. Residuals: j/k/row rotation + ok-beqz vs sltu. verify ASM (prod ASM), lint 0e/1w (pre-existing 2290 H003; guarded pragma hidden), -DNON_MATCHING compiles (28K). */
// FUN_002AF3E0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_002af3e0(u8 *arg0, s32 arg1) {
    u8 *p;
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    s16 o;
    s32 ok;
    u8 *q;
    u8 *r;
    u8 *s;
    s32 t;
    YVec2f v1;
    YVec2f v2;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    s32 h1;
    s32 h2;
    p = *(u8 **)(arg0 + 0x38);
    func_002b3c50(*(u8 **)(p + 0xCC));
    i = 0;
    while (i < 0xF) {
        ok = 0;
        q = (u8 *)((u8 *)&D_007E8C00 + (s32)i * 0x750);
        if (*(s32 *)(q + 0x48) != 0 && *(s32 *)(q + 0x54) != 0) {
            ok = 1;
        }
        if ((ok != 0) == 1) {
            func_002b4ac0(*(u8 **)((u8 *)p + (s32)i * 4 + 0xD8), (s8)arg1);
        }
        i = (s16)(i + 1);
    }
    j = 0;
    while (j < 8) {
        if (*(u8 *)((u8 *)&D_007E80A0 + (s32)j * 0x168) != 0) {
            func_002b5100(*(u8 **)((u8 *)p + (s32)j * 4 + 0x114), (s8)arg1);
        }
        j = (s16)(j + 1);
    }
    k = 0;
    while (k < 2) {
        t = *(s32 *)((u8 *)p + (s32)k * 4 + 0xD0);
        if (t != 0) {
            func_002b4240((u8 *)t, (s8)arg1);
        }
        k = (s16)(k + 1);
    }
    D_00764654 = 0;
    *(s16 *)(p + 0x764) = 0;
    *(s16 *)(p + 0x766) = 0;
    m = 0;
    while (m < 0x18) {
        n = 0;
        r = (u8 *)p + ((s32)m << 6);
        while (n < 0x10) {
            if (func_00452490(*(u8 **)(r + (s32)n * 4 + 0x148)) == 1) {
                s = r + (s32)n * 4;
                func_002b10f0(*(u8 **)(s + 0x148), (s8)arg1);
                func_002b10d0(*(u8 **)(s + 0x148), 0);
            }
            n = (s16)(n + 1);
        }
        m = (s16)(m + 1);
    }
    if ((s8)arg1 == 0) {
        *(s8 *)(p + 4) = 2;
        *(s8 *)(p + 0xB8) = 0;
        func_002b2970((u8 *)&v1, 15.0f, 406.0f);
        f1 = *(f32 *)&v1;
        f2 = *((f32 *)&v1 + 1);
        h1 = (s32)func_0046d200(D_00764644, 0xC);
        func_002b6ac0(*(u8 **)(p + 0x748), 0, 3, 0, 1.0f, 1.0f, 1.0f, *(f32 *)((u8 *)&iGpffff84f4 + 0x10));
        func_002b2970((u8 *)&v2, f1, f2 + func_0046b2f0((u8 *)h1) / 2.0f);
        func_002b69b0(*(u8 **)(p + 0x748), v1, v2, 0, 3, 0);
        func_002b6a40(*(u8 **)(p + 0x748), 0xFF, 0, 0, 0, 3);
        func_0046d280((u8 *)h1);
        func_002b2970((u8 *)&v1, 104.0f, 406.0f);
        f3 = *(f32 *)&v1;
        f4 = *((f32 *)&v1 + 1);
        h2 = (s32)func_0046d200(D_00764644, 0xD);
        func_002b6ac0(*(u8 **)(p + 0x74C), 0, 3, 0, 1.0f, 1.0f, 1.0f, *(f32 *)((u8 *)&iGpffff84f4 + 0x10));
        func_002b2970((u8 *)&v2, f3, f4 + func_0046b2f0((u8 *)h2) / 2.0f);
        func_002b69b0(*(u8 **)(p + 0x74C), v1, v2, 0, 3, 0);
        func_002b6a40(*(u8 **)(p + 0x74C), 0xFF, 0, 0, 0, 3);
        func_0046d280((u8 *)h2);
        return;
    }
    *(s8 *)(p + 4) = 3;
    *(s8 *)(p + 0xB8) = 1;
    {
        YVec2f a1;
        YVec2f a2;
        YVec2f b1;
        YVec2f b2;
        s32 ha;
        s32 hb;
        f32 fa1;
        f32 fa2;
        f32 fb1;
        f32 fb2;
        s16 o1;
        s16 o2;
        func_002b2970((u8 *)&a1, 15.0f, 406.0f);
        fa1 = *(f32 *)&a1;
        fa2 = *((f32 *)&a1 + 1);
        ha = (s32)func_0046d200(D_00764644, 0xC);
        *(s64 *)&b1 = *(s64 *)&a1;
        func_002b6be0(*(u8 **)(p + 0x748), b1, 0x4D, (f32)60000.0f);
        func_002b6ac0(*(u8 **)(p + 0x748), 0, 5, 0, 1.0f, 1.0f, *(f32 *)((u8 *)&iGpffff84f4 + 0x10), 1.0f);
        func_002b2970((u8 *)&a2, fa1, fa2 + func_0046b2f0((u8 *)ha) / 2.0f);
        func_002b69b0(*(u8 **)(p + 0x748), a2, *(YVec2f *)&a1, 0, 5, 0);
        func_002b6a40(*(u8 **)(p + 0x748), 0, 0xFF, 0, 0, 0);
        func_0046d280((u8 *)ha);
        func_002b2970((u8 *)&b1, 104.0f, 406.0f);
        fb1 = *(f32 *)&b1;
        fb2 = *((f32 *)&b1 + 1);
        hb = (s32)func_0046d200(D_00764644, 0xD);
        *(s64 *)&b2 = *(s64 *)&b1;
        func_002b6be0(*(u8 **)(p + 0x74C), b2, 0x4D, (f32)60000.0f);
        func_002b6ac0(*(u8 **)(p + 0x74C), 0, 5, 0, 1.0f, 1.0f, *(f32 *)((u8 *)&iGpffff84f4 + 0x10), 1.0f);
        func_002b2970((u8 *)&b2, fb1, fb2 + func_0046b2f0((u8 *)hb) / 2.0f);
        func_002b69b0(*(u8 **)(p + 0x74C), b2, *(YVec2f *)&b1, 0, 5, 0);
        func_002b6a40(*(u8 **)(p + 0x74C), 0, 0xFF, 0, 0, 0);
        func_0046d280((u8 *)hb);
        o = 0;
        while (o < 0x18) {
            o1 = 0;
            while (o1 < 0x10) {
                q = (u8 *)p + ((s32)o << 6) + (s32)o1 * 4;
                if (func_00452490(*(u8 **)(q + 0x148)) == 1) {
                    if ((((1 << ((s32)o1 & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[(s32)o & 0xFF]) >> ((s32)o1 & 0xFF)) == 1) {
                        func_002b10e0(*(u8 **)(q + 0x148), 1);
                    }
                    func_002b2970((u8 *)&a1, 18.0f * (f32)o, 18.0f * (f32)o1);
                    func_002b10a0(*(u8 **)(q + 0x148), a1);
                }
                o1 = (s16)(o1 + 1);
            }
            o = (s16)(o + 1);
        }
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002af3e0);
#endif

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



/* measured: re-derived if-chain variant (probe_variants v2 nd 199; measure_guarded obj 1640B/window 1632B nd 199 within 3% 1583-1681B; fnalign 46 edits +9 reloc-only retail 408 obj 410). ldr/ldl via YVec2f-by-value at disp 0x8, frame 0x70, bltz guard; prior note nd349/obj1644 retained as history, re-derived same shape without permuting spellings. Residuals: buf copy load-store vs load-load; doubled-arm $v0/$f0 vs $v1/$f3; if-chain move $v1,$v0; t3 before mov.s f17; GPR-grouped vs interleaved FP args. Repro: `python3 tools/probe_variants.py src/promoted/y_smap.c func_002afbc0 --candidate v2=/tmp/cand_afbc0_v2.c` -> 199; `python3 tools/measure_guarded.py src/promoted/y_smap.c func_002afbc0` -> obj 1640B/window 1632B GUARDED_SCORE 199; `python3 tools/fnalign.py src/promoted/y_smap.c func_002afbc0 --candidate /tmp/guarded_afbc0.c --quiet` -> 46 edits; `python3 tools/verify.py src/promoted/y_smap.c` -> 28 MATCH/8 ASM unchanged (production stays ASM via #else INCLUDE_ASM, no pragma); `python3 tools/decomp_lint.py src/promoted/y_smap.c` -> clean. */
// FUN_002AFBC0 NONMATCHING
#ifdef NON_MATCHING
s32 func_002afbc0(u8 *arg0) {
    u8 *s3;
    u8 *s1;
    s32 s2;
    s32 s0;
    s32 s4;
    f32 buf[4];
    s32 flag;
    s3 = arg0;
    s1 = *(u8 **)(arg0 + 0x38);
    s2 = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    func_002b2bd0(buf, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    buf[2] = buf[0];
    buf[3] = buf[1];
    if (D_0076464C == 0) {
        return 0;
    }
    if (func_00106330(0x1417) != 0) {
        return 0;
    }
    if (*(s8 *)(s1 + 0x144) == 0) {
        if (func_00106330(0x1416) == 0) {
            if (*(s8 *)(s1 + 0x143) == 0) {
                return 0;
            }
        }
        if (*(s8 *)(s1 + 0x15A) == 0) {
            return 0;
        }
        *(f32 *)(s1 + 8) = 7.0f + 18.0f * (f32)(u32)*(u8 *)(s1 + 0x140) + buf[2] - (f32)(D_00764660 * 18) + 15.0f + *(f32 *)(s1 + 0x10) - 10.0f;
        *(f32 *)(s1 + 0xC) = 227.0f + 18.0f * (f32)(u32)*(u8 *)(s1 + 0x141) + buf[3] - (f32)(D_0076465C * 18) + 15.0f + *(f32 *)(s1 + 0x14) + 16.0f;
        if (*(s8 *)(s1 + 0x14C) == 1) {
            s0 = ((*(u8 *)(func_00155280() + 0x47) + *(s8 *)(s1 + 0x159)) & 0xFF);
            s4 = ((*(u8 *)(func_00155280() + 0x46) + *(s8 *)(s1 + 0x158)) & 0xFF);
            if (func_00106330(0x1416) != 0) {
                flag = 1;
            } else {
                flag = (s8)(((1 << (s4 & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[s0 & 0xFF]) >> (s4 & 0xFF));
            }
            if ((s8)flag == 1) {
                func_0025ecd0(*(f32 *)(s1 + 8) + *(f32 *)(s1 + 0x150), *(f32 *)(s1 + 0xC) + *(f32 *)(s1 + 0x154), 60007.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (u8 *)(u32)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
        func_002b0b10(s3, *(YVec2f *)(s1 + 8), *(u8 *)(s1 + 0x18), s2, *(s8 *)(s1 + 0x142), 0x50, *(f32 *)(s1 + 0x2C), *(f32 *)(s1 + 0x30), 60008.0f, *(f32 *)(s1 + 0x34));
        *(u8 *)(s1 + 0x15A) = 0;
        return 0;
    } else {
        if (*(s8 *)(s1 + 0x144) != 1) {
            return 0;
        }
        if (func_00106330(0x1416) == 0) {
            if (*(s8 *)(s1 + 0x143) == 0) {
                return 0;
            }
        }
        *(f32 *)(s1 + 8) = 172.0f + 18.0f * (f32)(u32)*(u8 *)(s1 + 0x140);
        *(f32 *)(s1 + 0xC) = 9.0f + 18.0f * (f32)(u32)*(u8 *)(s1 + 0x141);
        if (*(s8 *)(s1 + 0x14C) == 1) {
            s0 = ((*(u8 *)(func_00155280() + 0x47) + *(s8 *)(s1 + 0x159)) & 0xFF);
            s4 = ((*(u8 *)(func_00155280() + 0x46) + *(s8 *)(s1 + 0x158)) & 0xFF);
            if (func_00106330(0x1416) != 0) {
                flag = 1;
            } else {
                flag = (s8)(((1 << (s4 & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[s0 & 0xFF]) >> (s4 & 0xFF));
            }
            if ((s8)flag == 1) {
                func_0025ecd0(*(f32 *)(s1 + 8) + *(f32 *)(s1 + 0x150), *(f32 *)(s1 + 0xC) + *(f32 *)(s1 + 0x154), 60007.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (u8 *)(u32)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
        func_002b0b10(s3, *(YVec2f *)(s1 + 8), *(u8 *)(s1 + 0x18), s2, *(s8 *)(s1 + 0x142), 0x4C, *(f32 *)(s1 + 0x2C), *(f32 *)(s1 + 0x30), 60008.0f, *(f32 *)(s1 + 0x34));
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002afbc0);
#endif

// FUN_002B0220
void func_002b0220(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


#pragma push


/* measured: 4 attempts (nd 284 -> 272 -> 180 -> 178) got everything but
   four source-drivable residuals: (1) the case 13/14 dispatch — retail tests
   (arg4&0xFF)==1 then !=3 with shared fallthrough body, mwcc b210 emits a
   switch chain testing 2,3,1 (8B longer); (2) saved-reg order ret/$s7 vs
   arg1/$s6 swapped; (3) the &f8/u8 stack locals land 4B higher; (4) the
   (a7+j)<<8 loop-invariant needs the opt_loop_invariants pragma to hoist at
   retail's position. All switch bodies, the v>=7/v==2/default chains, and
   the nested byte-scan loop match when aligned. */
/* measured: first full C body for this function (guard below) scores nd 279
   (obj 1372B/window 1360B; fnalign 275 edits over retail 340 instrs).
   Prologue, frame, all call sites, float immediates and the tile loop match;
   the gap to the prior nd-178 best (unarchived body, stands) is the prologue
   saved-register rotation (a1-a5 to $s6/$s7/$s3/$s2/$s1 vs retail
   $s7/$fp/$s4/$s3/$s2, arg6 saved to $fp vs spilled to stack) cascading
   through every later use. Pragma sweep on this exact body (loop-invariant
   on/off, schedule off, opt_propagation off, declaration-order swap) is
   neutral at 279-281, and
   the masked ==1/!=3 shared-fallthrough spelling of the 13/14 arm is neutral
   (279 -> 280), so the dispatch shape is second-order. Rotation plus
   callee-saved-spill-choice floor. */
// FUN_002B0250 NONMATCHING
#ifdef NON_MATCHING
s32 func_002afbc0(u8 *arg0);
u8 *func_002b0250(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    u8 buf[8];
    u8 *ret;
    u8 *blk;
    s32 v;
    s16 i;
    s16 j;
    u8 *q;
    func_002b2bd0((f32 *)buf, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    v = arg3 & 0xFF;
    if (v == 0xFF) {
        return NULL;
    }
    func_0044ea90(D_0063EF60, 0x5C4);
    blk = D_008873F4[0](1, 0x160, 0x40000);
    ret = (u8 *)(s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0063EFD8), 0xF, 0, 0, func_002afbc0, func_002b0220, (u8 *)(blk));
    *(u8 **)blk = blk;
    *(blk + 4) = arg3;
    *(blk + 5) = (u8)arg4;
    *(blk + 0x18) = (u8)arg5;
    *(s32 *)(blk + 0x34) = 0x3F800000;
    *(blk + 0x140) = (u8)arg1;
    *(blk + 0x141) = (u8)arg2;
    *(blk + 0x142) = 0;
    *(blk + 0x143) = 0;
    *(blk + 0x144) = 0;
    *(s32 *)(blk + 0x14) = 0;
    *(s32 *)(blk + 0x10) = 0;
    if (v < 9) {
        if (v < 7) {
            if (v == 2) {
                if (arg4 == 1) {
                    *(s32 *)(blk + 0x24) = 0x3C800000;
                    *(s32 *)(blk + 0x28) = 0x3C800000;
                    *(s32 *)(blk + 0x1C) = 0x3F140000;
                    *(s32 *)(blk + 0x20) = 0x3F140000;
                    *(s32 *)(blk + 0x2C) = 0x42140000;
                    *(s32 *)(blk + 0x30) = 0x42140000;
                    if (arg5 == 2 || arg5 == 1) {
                        *(blk + 0x142) = 2;
                    }
                } else if (arg4 == 2) {
                    *(s32 *)(blk + 0x28) = 0x3E980000;
                    *(s32 *)(blk + 0x24) = 0x3E980000;
                    *(s32 *)(blk + 0x20) = 0x3F140000;
                    *(s32 *)(blk + 0x1C) = 0x3F140000;
                    *(s32 *)(blk + 0x30) = 0x41980000;
                    *(s32 *)(blk + 0x2C) = 0x41980000;
                }
            } else {
                *(s32 *)(blk + 0x24) = 0x3D000000;
                *(s32 *)(blk + 0x28) = 0x3D000000;
                *(s32 *)(blk + 0x20) = 0x3F180000;
                *(s32 *)(blk + 0x1C) = 0x3F180000;
                *(s32 *)(blk + 0x30) = 0x41980000;
                *(s32 *)(blk + 0x2C) = 0x41980000;
            }
        } else {
            *(s32 *)(blk + 0x24) = 0x3C800000;
            *(s32 *)(blk + 0x28) = 0x3C800000;
            *(s32 *)(blk + 0x20) = 0x3F140000;
            *(s32 *)(blk + 0x1C) = 0x3F140000;
            *(s32 *)(blk + 0x30) = 0x42140000;
            *(s32 *)(blk + 0x2C) = 0x42140000;
        }
    } else if (v == 9 || v == 10) {
        if (arg4 == 1) {
            *(s32 *)(blk + 0x28) = 0x3D000000;
            *(s32 *)(blk + 0x24) = 0x3D000000;
            *(s32 *)(blk + 0x20) = 0x3F180000;
            *(s32 *)(blk + 0x1C) = 0x3F180000;
            *(s32 *)(blk + 0x30) = 0x41980000;
            *(s32 *)(blk + 0x2C) = 0x41980000;
        } else if (arg4 == 2) {
            *(s32 *)(blk + 0x24) = 0x3E980000;
            *(s32 *)(blk + 0x28) = 0x3C800000;
            *(f32 *)(blk + 0x1C) = *(f32 *)(blk + 0x24) + 0.578125f;
            *(f32 *)(blk + 0x20) = *(f32 *)(blk + 0x28) + 0.578125f;
            *(s32 *)(blk + 0x30) = 0x42140000;
            *(s32 *)(blk + 0x2C) = 0x42140000;
        }
    } else if (v == 11 || v == 12) {
        if (arg4 == 1) {
            *(s32 *)(blk + 0x28) = 0x3C800000;
            *(s32 *)(blk + 0x24) = 0x3C800000;
            *(s32 *)(blk + 0x1C) = 0x3E980000;
            *(s32 *)(blk + 0x20) = 0x3F5C0000;
            *(s32 *)(blk + 0x2C) = 0x41980000;
            *(s32 *)(blk + 0x30) = 0x425C0000;
            *(blk + 0x142) = 1;
        } else if (arg4 == 2) {
            *(s32 *)(blk + 0x24) = 0x3E980000;
            *(s32 *)(blk + 0x28) = 0x3C800000;
            *(f32 *)(blk + 0x1C) = *(f32 *)(blk + 0x24) + 0.578125f;
            *(f32 *)(blk + 0x20) = *(f32 *)(blk + 0x28) + 0.578125f;
            *(s32 *)(blk + 0x30) = 0x42140000;
            *(s32 *)(blk + 0x2C) = 0x42140000;
        }
    } else if (v == 13 || v == 14) {
        if (arg4 == 1 || arg4 == 3) {
            *(s32 *)(blk + 0x28) = 0x3D000000;
            *(s32 *)(blk + 0x24) = 0x3D000000;
            *(s32 *)(blk + 0x20) = 0x3F180000;
            *(s32 *)(blk + 0x1C) = 0x3F180000;
            *(s32 *)(blk + 0x30) = 0x41980000;
            *(s32 *)(blk + 0x2C) = 0x41980000;
        } else if (arg4 == 2) {
            *(s32 *)(blk + 0x24) = 0x3E980000;
            *(s32 *)(blk + 0x28) = 0x3E980000;
            *(s32 *)(blk + 0x1C) = 0x3F5C0000;
            *(s32 *)(blk + 0x20) = 0x3F5C0000;
            *(s32 *)(blk + 0x30) = 0x42140000;
            *(s32 *)(blk + 0x2C) = 0x42140000;
        }
    }
    *(blk + 0x14C) = 0;
    if (arg4 == 2 && arg6 == *(u8 *)(func_00155280() + 0x46) && arg7 == *(u8 *)(func_00155280() + 0x47)) {
        for (i = 0; i < 2; i = (s16)(i + 1)) {
            for (j = 0; j < 2; j = (s16)(j + 1)) {
                q = func_00155280();
                if ((*(u8 *)(((arg7 + i) << 8) + (u32)q + (arg6 + j) * 0x10 + 0x55) >> 4) == 2) {
                    *(s32 *)(blk + 0x150) = 0x41100000;
                    *(s32 *)(blk + 0x154) = 0x41100000;
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
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b0250);
#endif

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
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
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
                func_00442088(buf, D_0063EFF0, v);
                break;
            case 11:
            case 12:
                func_00442088(buf, D_0063F010, v);
                break;
            case 13:
            case 14:
                func_00442088(buf, D_0063EFF0, v);
                break;
            }
        } else if (*(u8 *)(arg1 + 5) == 3) {
            func_00442088(buf, D_0063EFF0, v);
        } else {
            switch (v) {
            case 9:
            case 10:
                func_00442088(buf, D_0063F030, v);
                break;
            case 11:
            case 12:
                func_00442088(buf, D_0063F050, v);
                break;
            case 13:
            case 14:
                func_00442088(buf, D_0063F070, v);
                break;
            }
        }
    } else if (v == 2) {
        if (*(u8 *)(arg1 + 5) == 1) {
            func_00442088(buf, D_0063F090, v);
        } else {
            func_00442088(buf, D_0063F0B0, v);
        }
    } else {
        func_00442088(buf, D_0063F0D0, v);
    }
    ((void (**)(s32, s32))fp)[0](1, *(s32 *)func_003ef650(func_003ef6d0(), buf));
}

/* measured: full structure matches (nd 345 -> 99): the 4-case switch, all
   mode sub-cases, the mask-first byte extraction, the byte-to-float idiom
   loop, and the final func_00461390 call. Residuals: (1) the documented
   D_008872F8 lui-hoist floor (retail hoists to the preheader, b210 keeps it
   in the loop); (2) arg3/arg4 saved-register order swapped ($s2/$s3) with the
   prologue move order (GPRs-then-FPs vs retail's interleave), which cascades
   register names through the loop body. Tried param types u32/s32/s8 and
   statement orders — all nd 99. Register-allocation + invariant-hoist floor. */
extern u8 D_00793E80[];
/* measured: YS clean 322 differing words (obj 940B/window 1424B under-484, frame -144 vs -192); pragma sweep schedule on 329 (+7), common off 328 (+6), loop on 324 (+2) — all regress, keep base; condensed switches/loop, frame under; inferior to prior documented 99-floor (YVec2f+s8/s32, 4-arg 461390, D_008872F8-hoist + s2/s3 walls) whose body is lost; TU explicit (u8 *)(u32)/(s16)/(s64)/(f32) casts applied, compiles; production stays ASM. */
/* measured: Tri-array + y-split + if-chain restores the missing third (probe_variants 322 -> 123; fnalign retail 356 obj 358, 97 edits +4 reloc-only, 0.6% over, bankable; task band 341-363 for retail 352 holds at 358). Root causes: (1) `&sp90 + v6*12` over 12 separate f32/s32 locals is UB, so b210 DCE'd 11 stores/arm (88 stores, 117 instrs, frame 0x90 vs 0xC0, 235 vs 352); struct Tri {f32 a; s32 b; f32 c;} t[4] with t[v6].a/c makes the 8 floats + 4 zeros observable and holds the frame at 0xC0 with 5 FPU saves. (2) switch conflated YVec2f.y (f20, 0x8C stack) with fparg2 (f14, DAT-60008 loop term); by = arg1.y split, arg1.x reloaded per arm like retail lwc1 0x88. (3) inner switch codegen is descending (beq 2,1,0) vs retail ascending (bnez 0, bne 1, bne 2); if (v==0)/else if (v==1)/else if (v==2) in ascending order matches. jal counts equal (00457120 + 00461390 both sides), so missing code holds no calls. m2c succeeds on this unit (no jr/jtbl; sibling 2ae630 note does not apply) but its loop drops the bltz sign-fixup else arms; romwright likewise warns away 4 unreachable blocks and simplifies to plain (f32) casts. Residuals: prologue GPR-then-FP move order vs retail interleave; byte-setup regs ($t1/$t0/$a3/$a2 vs $a1/$a0/$v1/$v0, missing mtc1/lui hoist); loop t13/offset/counter regs ($v0/$t3/$t2 vs $t5/$t0/$a2); D_008872F8 lui-hoist floor. TU-strict YVec2f-by-value/(u8 *)(u32)/(f32) casts, compiles -DNON_MATCHING, verify ASM, lint clean. */
// FUN_002B0B10 NONMATCHING
#ifdef NON_MATCHING
void func_002b0b10(u8 *arg0, YVec2f arg1, u8 arg2, s32 arg3, s8 arg4, s32 arg5, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    struct Tri { f32 a; s32 b; f32 c; };
    struct Tri t[4];
    f32 temp_f0;
    f32 temp_f6;
    f32 temp_f5;
    f32 by;
    u8 *temp_16;
    s32 temp_5;
    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f0 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    *(f32 *)(temp_16 + 0x38) = temp_f0;
    temp_f6 = fparg0 * fparg3;
    temp_f5 = fparg1 * fparg3;
    temp_5 = arg2 & 0xFF;
    by = arg1.y;
    switch (temp_5) {
    case 0:
        t[0].a = arg1.x;
        t[0].b = 0;
        t[0].c = by;
        t[1].a = arg1.x + temp_f6;
        t[1].b = 0;
        t[1].c = by;
        t[2].a = arg1.x;
        t[2].b = 0;
        t[2].c = by + temp_f5;
        t[3].a = arg1.x + temp_f6;
        t[3].b = 0;
        t[3].c = by + temp_f5;
        break;
    case 1: {
        s32 v = arg4;
        if (v == 0) {
            t[0].a = arg1.x;
            t[0].b = 0;
            t[0].c = by + temp_f5;
            t[1].a = arg1.x;
            t[1].b = 0;
            t[1].c = by;
            t[2].a = arg1.x + temp_f6;
            t[2].b = 0;
            t[2].c = by + temp_f5;
            t[3].a = arg1.x + temp_f6;
            t[3].b = 0;
            t[3].c = by;
        } else if (v == 1) {
            t[0].a = arg1.x;
            t[0].b = 0;
            t[0].c = by + temp_f6;
            t[1].a = arg1.x;
            t[1].b = 0;
            t[1].c = by;
            t[2].a = arg1.x + temp_f5;
            t[2].b = 0;
            t[2].c = by + temp_f6;
            t[3].a = arg1.x + temp_f5;
            t[3].b = 0;
            t[3].c = by;
        } else if (v == 2) {
            t[1].a = arg1.x;
            t[1].b = 0;
            t[1].c = by - 18.0f;
            t[3].a = (arg1.x + temp_f6);
            t[3].b = 0;
            t[3].c = by - 18.0f;
            t[0].a = arg1.x;
            t[0].b = 0;
            t[0].c = (by + temp_f5) - 18.0f;
            t[2].a = arg1.x + temp_f6;
            t[2].b = 0;
            t[2].c = (by + temp_f5) - 18.0f;
        }
        break;
    }
    case 2: {
        s32 v = arg4;
        if (v == 0) {
            t[3].a = arg1.x;
            t[3].b = 0;
            t[3].c = by;
            t[2].a = arg1.x + temp_f6;
            t[2].b = 0;
            t[2].c = by;
            t[1].a = arg1.x;
            t[1].b = 0;
            t[1].c = by + temp_f5;
            t[0].a = arg1.x + temp_f6;
            t[0].b = 0;
            t[0].c = by + temp_f5;
        } else if (v == 1) {
            t[3].a = arg1.x;
            t[3].b = 0;
            t[3].c = by;
            t[2].a = arg1.x + temp_f6;
            t[2].b = 0;
            t[2].c = by;
            t[1].a = arg1.x;
            t[1].b = 0;
            t[1].c = by + temp_f5;
            t[0].a = arg1.x + temp_f6;
            t[0].b = 0;
            t[0].c = by + temp_f5;
        } else if (v == 2) {
            t[3].a = arg1.x - 18.0f;
            t[3].b = 0;
            t[3].c = by;
            t[2].a = (arg1.x + temp_f6) - 18.0f;
            t[2].b = 0;
            t[2].c = by;
            t[1].a = arg1.x - 18.0f;
            t[1].b = 0;
            t[1].c = by + temp_f5;
            t[0].a = (arg1.x + temp_f6) - 18.0f;
            t[0].b = 0;
            t[0].c = by + temp_f5;
        }
        break;
    }
    case 3: {
        s32 v = arg4;
        if (v == 0) {
            t[2].a = arg1.x;
            t[2].b = 0;
            t[2].c = by;
            t[0].a = arg1.x + temp_f6;
            t[0].b = 0;
            t[0].c = by;
            t[3].a = arg1.x;
            t[3].b = 0;
            t[3].c = by + temp_f5;
            t[1].a = arg1.x + temp_f6;
            t[1].b = 0;
            t[1].c = by + temp_f5;
        } else if (v == 1) {
            t[3].a = arg1.x;
            t[3].b = 0;
            t[3].c = by + temp_f6;
            t[2].a = arg1.x;
            t[2].b = 0;
            t[2].c = by;
            t[1].a = arg1.x + temp_f5;
            t[1].b = 0;
            t[1].c = by + temp_f6;
            t[0].a = arg1.x + temp_f5;
            t[0].b = 0;
            t[0].c = by;
        }
        break;
    }
    }
    {
        s32 t52 = ((u32)(arg3 & 0xFF000000) >> 24) & 0xFF;
        s32 t4 = ((u32)(arg3 & 0xFF0000) >> 16) & 0xFF;
        s32 t33 = ((u32)(arg3 & 0xFF00) >> 8) & 0xFF;
        s32 t22 = arg3 & 0xFF;
        s32 v6 = 0;
        s32 tt11 = t4 & 1;
        s32 tt10 = t33 & 1;
        s32 tt9 = t22 & 1;
        while (v6 < 4) {
            u8 *t13 = temp_16 + (v6 << 6);
            *(f32 *)(t13 + 0x48) = D_008872F8[0] - fparg2;
            *(f32 *)(t13 + 0x58) = temp_f0;
            if (t52 >= 0) {
                *(f32 *)(t13 + 0x60) = (f32)t52;
            } else {
                s32 q52 = ((u32)t52 >> 1) | (t52 & 1);
                f32 g52 = (f32)q52;
                g52 += g52;
                *(f32 *)(t13 + 0x60) = g52;
            }
            if (t4 >= 0) {
                *(f32 *)(t13 + 0x64) = (f32)t4;
            } else {
                s32 q4 = ((u32)t4 >> 1) | tt11;
                f32 g4 = (f32)q4;
                g4 += g4;
                *(f32 *)(t13 + 0x64) = g4;
            }
            if (t33 >= 0) {
                *(f32 *)(t13 + 0x68) = (f32)t33;
            } else {
                s32 q33 = ((u32)t33 >> 1) | tt10;
                f32 g33 = (f32)q33;
                g33 += g33;
                *(f32 *)(t13 + 0x68) = g33;
            }
            if (t22 >= 0) {
                *(f32 *)(t13 + 0x6C) = (f32)t22;
            } else {
                s32 q22 = ((u32)t22 >> 1) | tt9;
                f32 g22 = (f32)q22;
                g22 += g22;
                *(f32 *)(t13 + 0x6C) = g22;
            }
            *(f32 *)(t13 + 0x40) = t[v6].a;
            *(f32 *)(t13 + 0x44) = t[v6].c;
            v6 += 1;
        }
    }
    {
        u8 *t23 = (u8 *)func_00461390((u8 *)&D_00793E80 + (arg5 * 0x30), 4, temp_16 + 0x40, 4);
        *(void (**)())(t23 + 8) = (void (*)())func_002b07a0;
        *(u8 **)(t23 + 0x10) = temp_16;
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b0b10);
#endif

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
f32 func_002b13e0(YVec3f *arg0, f32 arg1) {
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
f32 func_002b1480(YVec3f *arg0, f32 arg1) {
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

/* measured: recipe B re-test with the u32-cast base form (4 attempts, nd
   699 -> 632 -> 612 -> 603; best body below, nd 603, obj 3320B/window 3360B).
   The u32 base = (u32)D_00887300 + ((void (*)(s32,s32))*(u32 *)base)(a,b)
   spelling reproduces retail's single lui/addiu hoist into $17 with lw/jalr
   per call; the one-array sp[0x10] + cast accesses keep retail's two dead
   prologue s64 gp-relative ld/sd pairs (separate s64 locals get DCE'd), and
   the case-0/1 empty labels make mwcc emit the jtbl_007488A0 jump table
   (sltiu 7/beqz/lui/addiu/sll/addu/lw/jr). The (u8)(s32) saturation guard
   needs the explicit `if (2.1474836e9f > x) {plain} else {overflow}` spelling
   to emit c.ole.s $f1,$f2 + bc1t (the plain (u8)(s32)x form alone lets the
   range analysis drop the guard; `x < 2^31` emits c.olt.s + bc1f instead).
   Residuals: (1) the guard conversions allocate mfc1 $v0/andi $v1,$v0 (and
   or $v0,$v1,$v0) where retail uses $v1 throughout — 4 words per guard;
   (2) the fill-loop guard (2^31 const + c.ole.s + lui 0x8000) is NOT hoisted
   out of the loop by b210 here (retail hoists it before the loop-entry
   branch); (3) the clear-loop counters land in $s2/$s1 vs retail $s3/$s2. */
/* measured: cold2b1520 first reconstruction (bare INCLUDE_ASM, recipe-B 603 lost, no archived body). */
/* Target: src/promoted/y_smap.c func_002b1520 retail 0x002b1520 window 3360B (840 instrs). */
/* Candidate: /var/tmp/cold2b1520/v_minloc_loopon.c sha256 10aa44ed3ab051af (6666B). */
/* Compiler: mwccps2 3.0.1 b210 -O2 -Iinclude, scoped #pragma opt_loop_invariants on/off (624->619). */
/* Commands: m2c single fails on jr/jtbl (no m2c.c); romwright body+--types saved 175 lines; */
/*   probe_variants v0 714, common_off 796, loop_on 713, unroll_off 714, sched_off 714, subscript 713, */
/*   fresh 701, col1 700, minloc 624, loopon 619 best, sub 625, loopon+sub 639 (two non-improving, stop). */
/*   fnalign retail 838 obj 831 (3324B/window 3360B, 1.1% under, bankable) 172 edits+8 reloc-only. */
/* TU: guarded floor, prod stays ASM; verify ASM, lint clean, -DNON_MATCHING compiles. */
/* Semantic: switch 0/1 empty + default for jtbl_007488A0 (2..6, 3->4 fallthrough); u32 base hoist; */
/*   u8 sp[0x10] s64 dead loads + high-word spills; (f32)327/341/395/443 via int cvt; */
/*   explicit if (2.1474836e9f > x) u8/u16 guards; 9 fresh s16 counters; tail pp double-deref reload. */
/* Residuals: guard mfc1 $v0 vs $v1 (4w/guard), fill-loop hoist, clear $s2/$s1 vs $s3/$s2. */
/* measured 002b1520 (owner, 2026-09-19): fnalign **172 -> 163 edits**, count
   831 -> 830 against retail 838, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
/* measured 002b1520 (owner, 2026-09-19): fnalign **163 -> 154 edits**, count
   830 -> 829 against retail 838, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
// FUN_002B1520 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_002b1520(s32 arg0, u8 *q) {
    u32 base;
    u8 sp[0x10];
    f32 b;
    f32 a;
    f32 c;
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
    *(s64 *)(sp + 0) = iGpffffa840;
    *(s64 *)(sp + 8) = iGpffffa848;
    a = 1.0f;
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
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    switch (*(s8 *)(q + 4)) {
    case 0:
    case 1:
        break;
    case 2: {
        f32 t1;
        f32 t2;
        f32 t3;
        f32 t4;
        u8 bv;
        t1 = func_002b2aa0(0, 179.0f, 312.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t2 = func_002b2aa0(0, (f32)443, 312.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t3 = func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        t4 = func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s16 *)(q + 0x766), 5.0f);
        *(f32 *)(*(u8 **)(q + 0x7C) + 8) = t1;
        *(f32 *)(*(u8 **)(q + 0x80) + 8) = t2;
        t3 = 255.0f - t3;
        if (2.1474836e9f > t3) {
            bv = (u8)(s32)t3;
        } else {
            bv = (u8)(s32)(t3 - 2.1474836e9f);
        }
        *(u8 *)(*(u8 **)(q + 0x80) + 0x10) = bv;
        *(u8 *)(*(u8 **)(q + 0x7C) + 0x10) = bv;
        t4 = 255.0f - t4;
        for (i1 = 0; i1 < 3; i1++) {
            j1 = 0;
            do {
                u8 vv;
                if (2.1474836e9f > t4) {
                    vv = (u8)(s32)t4;
                } else {
                    vv = (u8)(s32)(t4 - 2.1474836e9f);
                }
                *(u8 *)(*(u8 **)(q + (s32)i1 * 0x18 + (s32)j1 * 4 + 0x34) + 0x10) = vv;
                j1++;
            } while (j1 < 6);
        }
        func_0046b380(*(u8 **)(q + 0x7C), 0);
        func_0046b380(*(u8 **)(q + 0x80), 0);
        for (i2 = 0; i2 < 3; i2++) {
            for (j2 = 0; j2 < 6; j2++) {
                func_0046b380(*(u8 **)(q + (s32)i2 * 0x18 + (s32)j2 * 4 + 0x34), 0);
            }
        }
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)327, 264.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)327, (f32)341, (f32)*(s16 *)(q + 0x764), 10.0f);
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
        u8 bv;
        t1 = func_002b2aa0(0, 312.0f, 179.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        t2 = func_002b2aa0(0, 312.0f, (f32)443, (f32)*(s16 *)(q + 0x764), 5.0f);
        t3 = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        t4 = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s16 *)(q + 0x766), 5.0f);
        *(f32 *)(*(u8 **)(q + 0x7C) + 8) = t1;
        *(f32 *)(*(u8 **)(q + 0x80) + 8) = t2;
        t3 = 255.0f - t3;
        if (2.1474836e9f > t3) {
            bv = (u8)(s32)t3;
        } else {
            bv = (u8)(s32)(t3 - 2.1474836e9f);
        }
        *(u8 *)(*(u8 **)(q + 0x80) + 0x10) = bv;
        *(u8 *)(*(u8 **)(q + 0x7C) + 0x10) = bv;
        t4 = 255.0f - t4;
        for (i3 = 0; i3 < 3; i3++) {
            j3 = 0;
            do {
                u8 vv;
                if (2.1474836e9f > t4) {
                    vv = (u8)(s32)t4;
                } else {
                    vv = (u8)(s32)(t4 - 2.1474836e9f);
                }
                *(u8 *)(*(u8 **)(q + (s32)i3 * 0x18 + (s32)j3 * 4 + 0x34) + 0x10) = vv;
                j3++;
            } while (j3 < 6);
        }
        *(f32 *)(sp + 4) = func_002b2aa0(0, 264.0f, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)341, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
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
        *(f32 *)(sp + 4) = func_002b2aa0(0, (f32)327, 264.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)327, (f32)341, (f32)*(s16 *)(q + 0x764), 10.0f);
        a = func_002b2aa0(0, iGpffff84f4, 1.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        b = func_002b2aa0(0, 183.0f, 120.0f, (f32)*(s16 *)(q + 0x764), 10.0f);
        c = func_002b2aa0(0, 332.0f, (f32)395, (f32)*(s16 *)(q + 0x764), 10.0f);
        func_002b3c60((s32)*(u8 **)(q + 0xCC), 0);
        break;
    case 6:
        *(f32 *)(sp + 4) = func_002b2aa0(0, 264.0f, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        *(f32 *)(sp + 12) = func_002b2aa0(0, (f32)341, (f32)327, (f32)*(s16 *)(q + 0x764), 5.0f);
        a = func_002b2aa0(0, 1.0f, iGpffff84f4, (f32)*(s16 *)(q + 0x764), 5.0f);
        b = func_002b2aa0(0, 120.0f, 183.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        c = func_002b2aa0(0, (f32)395, 332.0f, (f32)*(s16 *)(q + 0x764), 5.0f);
        func_002b3c60((s32)*(u8 **)(q + 0xCC), 1);
        break;
    default:
        break;
    }
    if (iGpffff84f4 < a) {
        f32 se = *(f32 *)(sp + 4);
        f32 sf = *(f32 *)(sp + 12);
        *(f32 *)(*(u8 **)(q + 0x28) + 0xC) = se;
        *(f32 *)(*(u8 **)(q + 0x24) + 0xC) = se;
        *(f32 *)(*(u8 **)(q + 0x30) + 0xC) = sf;
        *(f32 *)(*(u8 **)(q + 0x2C) + 0xC) = sf;
        a = a * 4096.0f;
        for (k = 0; k < 4; k++) {
            u8 **pp = (u8 **)(q + (s32)k * 4 + 0x24);
            u16 ww;
            if (2.1474836e9f > a) {
                ww = (u16)(s32)a;
            } else {
                ww = (u16)(s32)(a - 2.1474836e9f);
            }
            *(u16 *)(*pp + 0x22) = ww;
            func_0046b380(*pp, 0);
        }
    }
    *(f32 *)(func_002b2940((s32)*(u8 **)(q + 0xBC)) + 0x10) = b;
    *(f32 *)(func_002b2940((s32)*(u8 **)(q + 0xC4)) + 8) = c;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1520);
#endif

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
        q->a[i] = (SmapItem *)func_0046d200(D_00764644, i + 3);
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
    func_0043f9c8(q->tail, 0, 0x30);
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
// FUN_002B2830
void func_002b2830(u8 *arg0, YVec2f arg1, f32 arg2, f32 arg3, u32 arg4) {
    u8 *p;

    func_0044ea90(D_0063EF60, 0x97A);
    p = D_008873F4[0](1, 0x120, 0x40000);
    (s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0063F0F0), 0xF, 0, 0, func_002b25d0, func_002b2800, (u8 *)(p));
    *(u32 *)p = (u32)p;
    *(YVec2f *)(p + 4) = arg1;
    *(f32 *)(p + 0xC) = arg2;
    *(f32 *)(p + 0x10) = arg3;
    *(YRGBA *)(p + 0x14) = *(YRGBA *)&arg4;
    *(f32 *)(p + 0x18) = 60000.0f;
}

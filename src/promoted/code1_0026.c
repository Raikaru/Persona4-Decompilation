#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern s32 func_00106330(s32 arg0);
extern s32 func_00273970(u8 *arg0);
extern void func_0026d810();
extern s32 func_00451fc0(s32 arg0, const void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void (*arg5)(void), void (*arg6)(void),
                         s32 arg7);
extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 func_0026db60(void);
extern void func_0026c960(f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern void func_0026c860(f32 *arg0, f32 *arg1);
extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
extern void func_0026dc30(void);
extern s32 func_0026dee0(void);
extern u8 *func_001452b0(s32 arg0);
extern void func_0026dd60(u8 *arg0);
extern void func_0026d440(void);
extern void func_0026a020(u8 *arg0);
extern void func_0026c310(u8 *arg0);
extern void func_004b11d0(void *arg0, s32 arg1);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void func_00440bb8(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *func_0043f810(void *arg0, const void *arg1, u32 arg2);
extern void func_0043f9c8(void *arg0, void *arg1, s32 arg2);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;
static inline f32 func_00263220_mul(f32 left, f32 right)
{
    return left * right;
}
extern void func_00267b20(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s64 arg4, s64 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
extern char iGpffffa6c4;
extern void (*D_00887300[])(u32 state, u32 value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, s32, s8 *, s32, s32, u8 *);
static inline u32 *func_0026e010_add_offset(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *func_0026f1e0_add(u8 *base, u32 index)
{
    return base + index;
}

extern u8 *func_00452560();
extern s32 func_00452490();

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(s32 arg0, s32 arg1);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern void func_0046d730(void *arg0, s32 arg1);
extern s32 func_00266ba0(u8 *arg0);
extern s32 func_0045a8d0(s32 arg0, s32 arg1);
extern s32 func_004598e0(s32 arg0);
extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_0025f110(u8 *arg0);
extern u8 D_00638F90[];
extern void func_002674b0(s32 arg0, u8 *arg1);
extern char D_00637348[];
extern s32 func_00452380(void *arg0);
extern void func_00452080(s32 arg0);
extern void func_00263cb0(s32 arg0, u8 *arg1);
extern void func_00274660(u32 param_1, int param_2);
extern s32 func_00266950(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00266a40(u32 arg0, s32 arg1);
extern void func_00266a90(u8 *arg0);
extern s32 func_00266ae0(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00108e10(void);
extern s32 func_00107ce0(s32 arg0);
extern s32 func_00107dc0(s32 arg0);
extern void func_00108290(s32 arg0, s32 arg1);
extern void func_00264cb0(s32 arg0, s32 arg1);
extern s32 func_00110c50(s32 arg0, s32 arg1);
extern s32 func_0043c6a0(s32 arg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00262de0(s32 arg0, s32 arg1, f32 fparg0, s32 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern u32 func_002746a0(void);
extern void func_00273cc0(u8 *text, u8 *context);
extern u32 func_001067f0(s16 id);
extern s64 func_0010d660(s32 arg0);
extern s64 func_0010d6d0(s32 arg0);
extern s32 func_00442088(char *dst, const char *fmt, ...);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0045aeb0(s16 arg0, const char *arg1);
extern s32 D_008815B0[];
extern void func_00273f70(u8 *arg0);
extern void func_002739e0(s32 arg0, u8 *arg1);
extern u8 iGpffffa734;
extern f32 func_003e4180(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern u8 *func_00457120(void);
extern void func_004b1470(s32 arg0, f32 *arg1);
extern void func_00106620(s32 arg0, s32 arg1);

extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0045d6e0(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0048a000(void);
extern s32 func_0025f2c0(s32 arg0, s32 arg1, u8 *arg2);
extern void func_0025f620(f32, f32, f32, s32, s32, const char *, s32, s16, s16, Code1_0026Callback, u8 *);
// FUN_00260510
void func_00260510(void)
{
    s32 temp_2;
    u8 *temp_2_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        temp_2_2 = func_00452560(temp_2);
        *(s32 *)(temp_2_2 + 8) |= 1;
    }
}
// FUN_00260560
void func_00260560(void)
{
    s32 temp_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        func_00452080(temp_2);
    }
}
/* measured: declaring func_0025f430's halfword parameters as s16 reproduces
   retail's zero/pointer/constant/halfword setup order; object 88B, retail
   window 96B with zero tail, normalized_diff 0. */
// FUN_002605A0
void func_002605a0(f32 fparg0, f32 fparg1, f32 fparg2,
                   s32 arg0, s32 arg1, s8 *arg2, s32 arg3, s32 arg4, u8 *arg5)
{
    extern void func_0025f430(s32, s32, s32, s32, u8 *, s32, s16, s16,
                              f32, f32, f32, f32, f32, f32);
    s8 temp_7;

    temp_7 = *(s8 *)(arg2 + arg3);
    if (temp_7 != 0xA) {
        func_0025f430(arg0, arg1, 0, temp_7, *(u8 **)(arg5 + 0x10), 1,
                      *(s16 *)(arg5 + 0), *(s16 *)(arg5 + 2), fparg0, fparg1, fparg2,
                      *(f32 *)(arg5 + 4), *(f32 *)(arg5 + 8), *(f32 *)(arg5 + 0xC));
    }
}
/* floor (within 3%): probe_variants 474wd via `python3 tools/probe_variants.py src/promoted/code1_0026.c func_00260600 --candidate V5outer=/var/tmp/cold260600/v5_outer.c`; fnalign retail 533 vs object 525 instrs (722 edits) via `python3 tools/fnalign.py src/promoted/code1_0026.c func_00260600 --candidate /var/tmp/cold260600/v5_outer.c --quiet`; -8 short (1.5% within 3% rule). m2c+romwright agree on 2x0x18 copies + 3x0xC loops; denoised to file idiom with true s32 func_0025f430(s32x8+f32x6) from shdSprite + f32 func_0044b610/7b0 + u8 D_00637440/500 + f32 fGpffff811c/iGpffff81d0/D_007612C4; signature s32x7+f32x3 per 00260e60 caller + retail prologue daddu; per-case 14/16/41/29/12 biases + 18/13 cos/sin + 47/52/57/48 + 22.0/180.0 s16 truncations + 34/36/52/38 epilogues; opt_loop_invariants on -25wd (499->474). Wall remains save-set/colour/scheduling. No volatile/asm. */
/* measured 00260600: retail checks 2,1,0 descending but handlers 0,1,2 ascending (H0 at R61 14.0f first) vs C 2,1,0 descending handlers descending - one block move to `switch (arg4) {case 0:..;case 1:..;case 2:..;}`: fnalign 525/533,722 -> 527/533,317 (-405, -56%), words 474 -> 478 (GUARDED_SCORE via `python3 tools/measure_guarded.py src/promoted/code1_0026.c func_00260600`); -6 short (1.1% within gate, was -8/1.5%). if/else ascending 0,1,2 gives 525/329/482, switch wins on all three. */
// FUN_00260600 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00260600(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg0, f32 fparg1, f32 fparg2)
{
    extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
    extern f32 func_0044b610(f32);
    extern f32 func_0044b7b0(f32);
    extern u8 D_00637440[];
    extern u8 D_00637500[];
    extern f32 fGpffff811c;
    extern f32 iGpffff81d0;
    extern f32 D_007612C4;
    f32 fstack[96];
    u8 *src;
    u8 *dst;
    s32 n;
    s32 tmpa;
    s32 tmpb;
    s32 biasA;
    s32 biasB;
    f32 halfThird;
    f32 halfFiveThird;
    f32 gpThird;
    f32 gpFiveThird;
    u32 i;
    f32 entry0;
    f32 entry1;
    f32 entry2;
    f32 entry3;
    f32 angle;
    f32 cosv;
    f32 sinv;
    f32 cosS;
    f32 sinS;
    f32 fx;
    f32 fy;
    f32 fmid;
    f32 fhalf;
    s32 sx;
    s32 sy;
    src = D_00637440;
    dst = (u8 *)&fstack[48];
    n = 0x18;
    do {
        tmpa = *(s32 *)src;
        tmpb = *(s32 *)(src + 4);
        src += 8;
        n -= 1;
        *(s32 *)dst = tmpa;
        *(s32 *)(dst + 4) = tmpb;
        dst += 8;
    } while (n > 0);
    src = D_00637500;
    dst = (u8 *)&fstack[0];
    n = 0x18;
    do {
        tmpa = *(s32 *)src;
        tmpb = *(s32 *)(src + 4);
        src += 8;
        n -= 1;
        *(s32 *)dst = tmpa;
        *(s32 *)(dst + 4) = tmpb;
        dst += 8;
    } while (n > 0);
    switch (arg4) {
    case 0:
        biasA = (int)((float)arg0 - 14.0f * fparg1);
        biasB = (int)((float)arg1 - 16.0f * fparg2);
        halfThird = 0.5f * fparg2;
        halfFiveThird = 0.5f * (5.0f * fparg2);
        for (i = 0; i < 0xC; i++) {
            entry2 = fstack[48 + i * 4 + 2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosv = func_0044b610(angle);
            cosS = 18.0f * cosv;
            sinv = func_0044b7b0(angle);
            sinS = 18.0f * (-sinv);
            entry0 = fstack[48 + i * 4 + 0];
            entry1 = fstack[48 + i * 4 + 1];
            entry3 = fstack[48 + i * 4 + 3];
            fx = (cosS + entry0 + 47.0f) * fparg1 + (float)biasA;
            fy = (sinS + entry1 + 52.0f) * fparg2 + (float)biasB;
            sx = (s16)(int)(0.5f * fparg1 * (22.0f * entry3));
            sy = (s16)(int)halfFiveThird;
            fmid = entry2 - 180.0f;
            fhalf = 0.5f * fparg1 * entry3;
            func_0025f430(arg2, arg3, 0x13, 0, (u8 *)arg5, arg6, sx, sy, fx, fy, fparg0, fmid, fhalf, halfThird);
        }
        func_0025f430(arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, fparg1 * 34.0f + (float)biasA, fparg2 * 36.0f + (float)biasB, fparg0, 0.0f, fparg1, fparg2);
        break;
    case 1:
        biasA = (int)((float)arg0 - 41.0f * fparg1);
        biasB = (int)((float)arg1 - 29.0f * fparg2);
        gpThird = fGpffff811c * fparg2;
        gpFiveThird = fGpffff811c * fparg2 * 5.0f;
        for (i = 0; i < 0xC; i++) {
            entry2 = fstack[i * 4 + 2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosv = func_0044b610(angle);
            cosS = 13.0f * cosv;
            sinv = func_0044b7b0(angle);
            sinS = 13.0f * (-sinv);
            entry0 = fstack[i * 4 + 0];
            entry1 = fstack[i * 4 + 1];
            entry3 = fstack[i * 4 + 3];
            fx = (cosS + entry0 + 57.0f) * fparg1 + (float)biasA;
            fy = (sinS + entry1 + 48.0f) * fparg2 + (float)biasB;
            sx = (s16)(int)(0.5f * fparg1 * (22.0f * entry3));
            sy = (s16)(int)gpFiveThird;
            fmid = entry2 - 180.0f;
            fhalf = 0.5f * fparg1 * entry3;
            func_0025f430(arg2, arg3, 0x13, 0, (u8 *)arg5, arg6, sx, sy, fx, fy, fparg0, fmid, fhalf, gpThird);
        }
        func_0025f430(arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, fparg1 * 52.0f + (float)biasA, fparg2 * 38.0f + (float)biasB, fparg0, 0.0f, D_007612C4 * fparg1, D_007612C4 * fparg2);
        break;
    case 2:
        biasA = (int)((float)arg0 - 12.0f * fparg1);
        biasB = (int)((float)arg1 + fparg2);
        gpThird = fGpffff811c * fparg2;
        gpFiveThird = fGpffff811c * fparg2 * 5.0f;
        for (i = 0; i < 0xC; i++) {
            entry2 = fstack[i * 4 + 2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosv = func_0044b610(angle);
            cosS = 13.0f * cosv;
            sinv = func_0044b7b0(angle);
            sinS = 13.0f * (-sinv);
            entry0 = fstack[i * 4 + 0];
            entry1 = fstack[i * 4 + 1];
            entry3 = fstack[i * 4 + 3];
            fx = (cosS + entry0 + 57.0f) * fparg1 + (float)biasA;
            fy = (sinS + entry1 + 48.0f) * fparg2 + (float)biasB;
            sx = (s16)(int)(0.5f * fparg1 * (22.0f * entry3));
            sy = (s16)(int)gpFiveThird;
            fmid = entry2 - 180.0f;
            fhalf = 0.5f * fparg1 * entry3;
            func_0025f430(arg2, arg3, 0x13, 0, (u8 *)arg5, arg6, sx, sy, fx, fy, fparg0, fmid, fhalf, gpThird);
        }
        func_0025f430(arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, fparg1 * 52.0f + (float)biasA, fparg2 * 38.0f + (float)biasB, fparg0, 0.0f, D_007612C4 * fparg1, D_007612C4 * fparg2);
        break;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260600);
#endif
extern f32 D_007612C4;
extern u8 D_006375C0[];
/* measured (2026-09-18): probe_variants 401 differing words reloc-masked via `python3 tools/probe_variants.py src/promoted/code1_0026.c func_00260e60 --candidate V2=/tmp/cand60e60_v2.c`; fnalign retail 448 vs object 451 instrs (127 edits) via `python3 tools/fnalign.py src/promoted/code1_0026.c func_00260e60 --candidate /tmp/cand60e60_v2.c --quiet`; +3 over (0.7% within 3% rule). Signature all-s32 8 ints + 3 floats per prologue daddu (no dsll/dsra); local externs for 0025f430 (s32 x8 + f32 x6) + 00260600 (s32 x7 + f32 x3) fix 416B overrun; 3.0f/23.0f msub/madd + D_007612C4 muls for FMA; duplicated 00260600/0025f430 blocks match retail triplication; 0x1E copy + 0x1E draw loops. Wall remains FMA ACC scheduling + call/setup ordering. No volatile/asm. */
// FUN_00260E60 NONMATCHING
#ifdef NON_MATCHING
void func_00260e60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 fparg0, f32 fparg1, f32 fparg2) {
    extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
    extern void func_00260600(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    u8 spB0[240];
    s32 var_16;
    s32 var_4;
    u8 *var_5;
    u8 *var_6;
    s32 var_17;
    var_16 = 0x919191;
    switch (arg5) {
    case 1:
        var_16 = 0xFFF000;
        break;
    case 2:
        var_16 = 0x52BDFF;
        break;
    case 3:
        var_16 = 0xFF296B;
        break;
    }
    if (arg7 != 0) {
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 1);
        D_00887300[0](7, 2);
        D_00887300[0](8, 1);
        D_00887300[0](9, 2);
        D_00887300[0](0x0C, 1);
        D_00887300[0](2, 4);
        D_00887300[0](0x0E, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x44);
    }
    switch (arg3) {
    case 0:
        if (arg5 != 0) {
            var_16 = 0xFF9000;
        }
        switch (arg4) {
        case 0:
            func_00260600(arg0, arg1, var_16, arg2, arg4, arg6, 0, fparg0, fparg1, fparg2);
            return;
        case 1:
            func_00260600(arg0, arg1, var_16, arg2, arg4, arg6, 0, fparg0, fparg1, fparg2);
            return;
        case 2:
            func_00260600(arg0, arg1, var_16, arg2, arg4, arg6, 0, fparg0, fparg1, fparg2);
            return;
        }
        break;
    case 1:
        if (arg5 != 0) {
            var_16 = 0x4C85EF;
        }
        switch (arg4) {
        case 0:
            func_0025f430(var_16, arg2, 8, 0, (u8 *)arg6, 0, 0, 0, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        case 1: {
            f32 tf0 = D_007612C4;
            f32 madd1 = 3.0f * fparg1;
            f32 res1 = (f32)arg0 - madd1;
            func_0025f430(var_16, arg2, 7, 0, (u8 *)arg6, 0, 0, 0, res1, (f32)(arg1 - 4), fparg0, (f32)arg0, tf0 * fparg1, tf0 * fparg2);
            return;
        }
        case 2: {
            f32 tf02 = D_007612C4;
            f32 madd2 = 23.0f * fparg1;
            f32 res2 = (f32)arg0 + madd2;
            func_0025f430(var_16, arg2, 7, 0, (u8 *)arg6, 0, 0, 0, res2, (f32)(arg1 + 0x1B), fparg0, (f32)arg0, tf02 * fparg1, tf02 * fparg2);
            return;
        }
        }
        break;
    case 2:
        if (arg5 != 0) {
            var_16 = 0x949494;
        }
        switch (arg4) {
        case 0:
            func_0025f430(var_16, arg2, 6, 0, (u8 *)arg6, 0, 0, 0, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        case 1:
            func_0025f430(var_16, arg2, 6, 0, (u8 *)arg6, 0, 0, 0, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            return;
        case 2:
            func_0025f430(var_16, arg2, 6, 0, (u8 *)arg6, 0, 0, 0, (f32)(arg0 - 5), (f32)(arg1 + 0x19), fparg0, 0.0f, fparg1, fparg2);
            return;
        }
        break;
    case 4:
        if (arg5 != 0) {
            var_16 = 0xFFFFFF;
        }
        switch (arg4) {
        case 0: {
            u8 *v6 = D_006375C0;
            u8 *v5 = spB0;
            s32 v4 = 0x1E;
            s32 t3;
            s32 t2;
            do {
                t3 = *(s32 *)v6;
                t2 = *(s32 *)(v6 + 4);
                v6 += 8;
                v4 -= 1;
                *(s32 *)v5 = t3;
                *(s32 *)(v5 + 4) = t2;
                v5 += 8;
            } while (v4 > 0);
            func_0025f430(var_16, arg2, 0x0A, 0, (u8 *)arg6, 0, 0, 0, (f32)arg0, (f32)arg1, fparg0, 0.0f, fparg1, fparg2);
            var_17 = 0;
            while (var_17 < 0x1E) {
                s32 off = var_17 * 8;
                u8 *t22 = (u8 *)((s32)spB0 + off);
                func_0025f430(var_16, arg2, 9, 0, (u8 *)arg6, 0, 0, 0, (f32)(arg0 - 0x0A + *(s32 *)((s32)t22 + 0xB0)), (f32)(arg1 - 0x0C + *(s32 *)((s32)t22 + 0xB0 + 4)), fparg0, 0.0f, fparg1, fparg2);
                var_17 += 1;
            }
        }
        case 3:
        case 2:
        case 1:
            return;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260e60);
#endif
/* measured: GUARDED_SCORE 1357 via `python3 tools/measure_guarded.py src/promoted/code1_0026.c func_00261560` with scoped `#pragma optimization_level 3` (baseline v1e 1804I/1591wd -> 1558I/1357wd, -246I/-234wd, count and words both improve so not inflation); obj 1558I / retail 1568I (-10, -0.64% PASS, band 1521-1615). fnalign 2970 edits. 12-arg float ABI from prologue (a0->s0,a1->s4,a2->s3,a3->s8,t0->stack0xCC,f13->f22,f14->f21,t1->s6,t2->s7,t3->s2); handoff-7r entry MAC shaped as (s32)((float)arg0+47.0f*(1.0f-fparg1)), remaining 10 MAC sites stubbed 0.0f for count (same 1I float const); D_00887300[0], D_00637430, s128 aligned(16), base-first. */
/* decomposition for func_00261560 (banked vC 1611 inside, s32 spB0 saves 6 — same call as func_0035aff0):
   Retail 0x00261560-0x00262DDF 6272B 1568I, band 1521-1615. Banked vC 1611I/1429wd/2998ed (+43/+2.74% PASS, headroom 4) with handoff-7r entry (s32)((float)arg0+47.0f*(1.0f-fparg1)) and four 0xE 9th-args ((float)arg0+70/69*fparg1, 70,69,70,69 per c.lt.s/bc1t), s0 reuse via arg0, s32 spB0 (was s128, saves 6I/1wd/4ed vs v1d 1617I/1430wd/3002ed +2 over max), opt_level3 scoped (dummy v1e 1558I/1357wd/2970ed inside but 10x0.0f placeholders, correctly reverted). 12-arg ABI: a0->s0(arg0),a1->s4(arg1),a2->s3(arg2 u8),a3->s8(arg3 &0xF,>>4),t0->stack0xCC(arg4),f13->f22(fparg1),f14->f21(fparg2),t1->s6(arg5),t2->s7(arg6),t3->s2(arg7). MAC addrs 0x00261614/18,0x002619EC/F0,0x00261A5C/60,0x00261D00/04,0x00261D70/74,0x00261FDC/E0 (plain a+b*c). 12th-arg f15 0.0f correct literal. Caveat: no block prototypes for 0025f430/00260e60 (untyped calls keep sd bloat); adding s32/u8* prototypes drops to 1403I/1566 (-163 outside below, needs +~165 real logic) — bloat compensates missing blocks, gate passes but composition still 2998ed; honest typed version needs block recovery. */
// FUN_00261560 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma optimization_level 3
void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0) {
    typedef signed __int128 s128;
    extern s128 D_00637430;
    extern void (*D_00887300[])(u32, u32);
    extern void func_003f6440(s32, s32);
    extern void func_0045d6e0(void *, void *, f32, s32);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    s32 unksp134;
    s32 unksp174;
    s32 unksp1B4;
    s32 unksp1F4;
    s32 unksp234;
    s32 unkspF4;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    s128 sp240;
    s128 sp230;                                     /* compiler-managed */
    s128 sp220;
    s32 sp21C;
    s32 sp218;
    s32 sp214;
    s32 sp210;
    s128 sp200;
    s128 sp1F0;                                     /* compiler-managed */
    s128 sp1E0;
    s32 sp1DC;
    s32 sp1D8;
    s32 sp1D4;
    s32 sp1D0;
    s128 sp1C0;
    s128 sp1B0;                                     /* compiler-managed */
    s128 sp1A0;
    s32 sp19C;
    s32 sp198;
    s32 sp194;
    s32 sp190;
    s128 sp180;
    s128 sp170;                                     /* compiler-managed */
    s128 sp160;
    s32 sp15C;
    s32 sp158;
    s32 sp154;
    s32 sp150;
    s128 sp140;
    s128 sp130;                                     /* compiler-managed */
    s128 sp120;
    s32 sp11C;
    s32 sp118;
    s32 sp114;
    s32 sp110;
    s128 sp100;
    s128 spF0;                                      /* compiler-managed */
    s128 spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spB0;
    u8 *var_3;
    u8 *var_3_10;
    u8 *var_3_11;
    u8 *var_3_13;
    u8 *var_3_14;
    u8 *var_3_16;
    u8 *var_3_17;
    u8 *var_3_2;
    u8 *var_3_4;
    u8 *var_3_5;
    u8 *var_3_7;
    u8 *var_3_8;
    f32 temp_f20;
    u8 *var_3_12;
    u8 *var_3_15;
    u8 *var_3_18;
    u8 *var_3_3;
    u8 *var_3_6;
    u8 *var_3_9;
    s32 temp_2;
    s32 temp_30;
    s32 var_17;
    s32 var_2;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;

    spCC = arg4;
    var_17 = 0x242424;
    if (arg4 != 0) {
        var_17 = 0;
    }
    temp_30 = arg3 & 0xF;
    temp_2 = arg3 >> 4;
    spB0 = temp_2;
    if (temp_2 == temp_30) {
        arg0 = (s32)((float)arg0 + 47.0f * (1.0f - fparg1));
        var_3 = (u8 *)(&sp2A8);
        var_2 = 4;
        if (var_3 != NULL) {
            do {
                *var_3 = 0;
                var_3 += 1;
            } while (--var_2 != 0);
        }
        sp2AC = sp2A8;
        sp230 = D_00637430;
        sp230 = arg0 - 0x40;
        unksp234 = arg1 - 0x40;
        sp240 = (s128) sp230;
        D_00887300[0](0xE, 0);
        D_00887300[0](0xC, 1);
        D_00887300[0](7, 2);
        D_00887300[0](9, 1);
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 0);
        D_00887300[0](8, 1);
        func_003f6440(3, 0x71003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp2AC, &sp240, 0, 10.0f);
        func_0048a000();
        var_3_2 = (u8 *)(&sp2A0);
        var_2_2 = 4;
        if (var_3_2 != NULL) {
            do {
                *var_3_2 = 0;
                var_3_2 += 1;
            } while (--var_2_2 != 0);
        }
        sp2A4 = sp2A0;
        var_3_3 = (u8 *)(&sp210);
        var_2_3 = 0x10;
        if (var_3_3 != NULL) {
            do {
                *var_3_3 = 0;
                var_3_3 += 1;
            } while (--var_2_3 != 0);
        }
        sp210 = arg5;
        sp214 = 0;
        sp218 = arg6;
        sp21C = 0x1E0;
        sp220 = (s128) sp210;
        D_00887300[0](0xE, 0);
        D_00887300[0](0xC, 1);
        D_00887300[0](7, 2);
        D_00887300[0](9, 1);
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 0);
        D_00887300[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp2A4, &sp220, 0, 1.0f);
        func_0048a000();
        D_00887300[0](6, 1);
        D_00887300[0](7, 2);
        func_003f6440(3, 0x7000D);
        func_0025f430(var_17, arg2, 3, 0, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        temp_f20 = (f32) arg0 + (9.0f * fparg1);
        func_0025f430(var_17, arg2, 0xD, 0, arg7, 0, 0.0f, 0.0f, temp_f20, (f32) (arg1 + 4), 10.0f, 0.0f, fparg1, fparg2);
        if (!(fparg1 < 1.0f)) {
            func_0025f430(var_17, arg2, 0xE, 0, arg7, 0, 0.0f, 0.0f, ((float)arg0 + 70.0f * fparg1), (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        } else {
            func_0025f430(var_17, arg2, 0xE, 0, arg7, 0, 0.0f, 0.0f, ((float)arg0 + 69.0f * fparg1), (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        }
        var_3_4 = (u8 *)(&sp298);
        var_2_4 = 4;
        if (var_3_4 != NULL) {
            do {
                *var_3_4 = 0;
                var_3_4 += 1;
            } while (--var_2_4 != 0);
        }
        sp29C = sp298;
        sp1F0 = D_00637430;
        sp1F0 = arg0 - 0x40;
        unksp1F4 = arg1 - 0x40;
        sp200 = (s128) sp1F0;
        D_00887300[0](0xE, 0);
        D_00887300[0](0xC, 1);
        D_00887300[0](7, 2);
        D_00887300[0](9, 1);
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 0);
        D_00887300[0](8, 1);
        func_003f6440(3, 0x71003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp29C, &sp200, 0, 5.0f);
        func_0048a000();
        D_00887300[0](6, 0);
        D_00887300[0](7, 2);
        func_003f6440(3, 0x7000D);
        func_00489f80();
        func_0025f430(var_17, arg2, 3, 0, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        func_0025f430(var_17, arg2, 0xD, 0, arg7, 0, 0.0f, 0.0f, temp_f20, (f32) (arg1 + 4), 10.0f, 0.0f, fparg1, fparg2);
        if (!(fparg1 < 1.0f)) {
            func_0025f430(var_17, arg2, 0xE, 0, arg7, 0, 0.0f, 0.0f, ((float)arg0 + 70.0f * fparg1), (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        } else {
            func_0025f430(var_17, arg2, 0xE, 0, arg7, 0, 0.0f, 0.0f, ((float)arg0 + 69.0f * fparg1), (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
        }
        func_0048a000();
        var_3_5 = (u8 *)(&sp290);
        var_2_5 = 4;
        if (var_3_5 != NULL) {
            do {
                *var_3_5 = 0;
                var_3_5 += 1;
            } while (--var_2_5 != 0);
        }
        sp294 = sp290;
        var_3_6 = (u8 *)(&sp1D0);
        var_2_6 = 0x10;
        if (var_3_6 != NULL) {
            do {
                *var_3_6 = 0;
                var_3_6 += 1;
            } while (--var_2_6 != 0);
        }
        sp1D0 = arg5;
        sp1D4 = 0;
        sp1D8 = arg6;
        sp1DC = 0x1E0;
        sp1E0 = (s128) sp1D0;
        D_00887300[0](0xE, 0);
        D_00887300[0](0xC, 1);
        D_00887300[0](7, 2);
        D_00887300[0](9, 1);
        D_00887300[0](0x14, 1);
        D_00887300[0](6, 0);
        D_00887300[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp294, &sp1E0, 0, 1.0f);
        func_0048a000();
        if (arg_sp0 != 0) {
            func_00260e60(arg0, arg1, arg2, temp_30, 0, arg_sp0, arg7, 1, 10.0f, fparg1, fparg2);
            return;
        }
        func_00260e60(arg0, arg1, arg2, temp_30, 0, spCC, arg7, 1, 10.0f, fparg1, fparg2);
        return;
    }
    0.0f;
    arg0 = (s32)((float)arg0 + 47.0f * (1.0f - fparg1));
    var_3_7 = (u8 *)(&sp288);
    var_2_7 = 4;
    if (var_3_7 != NULL) {
        do {
            *var_3_7 = 0;
            var_3_7 += 1;
        } while (--var_2_7 != 0);
    }
    sp28C = sp288;
    sp1B0 = D_00637430;
    sp1B0 = arg0 - 0x40;
    unksp1B4 = arg1 - 0x40;
    sp1C0 = (s128) sp1B0;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp28C, &sp1C0, 0, 10.0f);
    func_0048a000();
    var_3_8 = (u8 *)(&sp280);
    var_2_8 = 4;
    if (var_3_8 != NULL) {
        do {
            *var_3_8 = 0;
            var_3_8 += 1;
        } while (--var_2_8 != 0);
    }
    sp284 = sp280;
    var_3_9 = (u8 *)(&sp190);
    var_2_9 = 0x10;
    if (var_3_9 != NULL) {
        do {
            *var_3_9 = 0;
            var_3_9 += 1;
        } while (--var_2_9 != 0);
    }
    sp190 = arg5;
    sp194 = 0;
    sp198 = arg6;
    sp19C = 0x1E0;
    sp1A0 = (s128) sp190;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp284, &sp1A0, 0, 1.0f);
    func_0048a000();
    D_00887300[0](6, 1);
    D_00887300[0](7, 2);
    func_003f6440(3, 0x3000D);
    func_0025f430(var_17, arg2, 0xF, 0, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
    var_3_10 = (u8 *)(&sp278);
    var_2_10 = 4;
    if (var_3_10 != NULL) {
        do {
            *var_3_10 = 0;
            var_3_10 += 1;
        } while (--var_2_10 != 0);
    }
    sp27C = sp278;
    sp170 = D_00637430;
    sp170 = arg0 - 0x40;
    unksp174 = arg1 - 0x40;
    sp180 = (s128) sp170;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp27C, &sp180, 0, 5.0f);
    func_0048a000();
    D_00887300[0](6, 0);
    D_00887300[0](7, 2);
    func_003f6440(3, 0x7000D);
    func_00489f80();
    func_0025f430(var_17, arg2, 0xF, 0, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
    func_0048a000();
    var_3_11 = (u8 *)(&sp270);
    var_2_11 = 4;
    if (var_3_11 != NULL) {
        do {
            *var_3_11 = 0;
            var_3_11 += 1;
        } while (--var_2_11 != 0);
    }
    sp274 = sp270;
    var_3_12 = (u8 *)(&sp150);
    var_2_12 = 0x10;
    if (var_3_12 != NULL) {
        do {
            *var_3_12 = 0;
            var_3_12 += 1;
        } while (--var_2_12 != 0);
    }
    sp150 = arg5;
    sp154 = 0;
    sp158 = arg6;
    sp15C = 0x1E0;
    sp160 = (s128) sp150;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp274, &sp160, 0, 1.0f);
    func_0048a000();
    if (arg_sp0 != 0) {
        func_00260e60(arg0, arg1, arg2, temp_30, 1, arg_sp0, arg7, 1, 10.0f, fparg1, fparg2);
    } else {
        func_00260e60(arg0, arg1, arg2, temp_30, 1, spCC, arg7, 1, 10.0f, fparg1, fparg2);
    }
    var_3_13 = (u8 *)(&sp268);
    var_2_13 = 4;
    if (var_3_13 != NULL) {
        do {
            *var_3_13 = 0;
            var_3_13 += 1;
        } while (--var_2_13 != 0);
    }
    sp26C = sp268;
    sp130 = D_00637430;
    sp130 = arg0 - 0x40;
    unksp134 = arg1 - 0x40;
    sp140 = (s128) sp130;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp26C, &sp140, 0, 10.0f);
    func_0048a000();
    var_3_14 = (u8 *)(&sp260);
    var_2_14 = 4;
    if (var_3_14 != NULL) {
        do {
            *var_3_14 = 0;
            var_3_14 += 1;
        } while (--var_2_14 != 0);
    }
    sp264 = sp260;
    var_3_15 = (u8 *)(&sp110);
    var_2_15 = 0x10;
    if (var_3_15 != NULL) {
        do {
            *var_3_15 = 0;
            var_3_15 += 1;
        } while (--var_2_15 != 0);
    }
    sp110 = arg5;
    sp114 = 0;
    sp118 = arg6;
    sp11C = 0x1E0;
    sp120 = (s128) sp110;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp264, &sp120, 0, 1.0f);
    func_0048a000();
    D_00887300[0](6, 1);
    D_00887300[0](7, 2);
    func_003f6440(3, 0x3000D);
    func_0025f430(var_17, arg2, 3, 1, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
    var_3_16 = (u8 *)(&sp258);
    var_2_16 = 4;
    if (var_3_16 != NULL) {
        do {
            *var_3_16 = 0;
            var_3_16 += 1;
        } while (--var_2_16 != 0);
    }
    sp25C = sp258;
    spF0 = D_00637430;
    spF0 = arg0 - 0x40;
    unkspF4 = arg1 - 0x40;
    sp100 = (s128) spF0;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp25C, &sp100, 0, 5.0f);
    func_0048a000();
    D_00887300[0](6, 0);
    D_00887300[0](7, 2);
    func_003f6440(3, 0x7000D);
    func_00489f80();
    func_0025f430(var_17, arg2, 3, 1, arg7, 0, 0.0f, 0.0f, (f32) arg0, (f32) arg1, 10.0f, 0.0f, fparg1, fparg2);
    func_0048a000();
    var_3_17 = (u8 *)(&sp250);
    var_2_17 = 4;
    if (var_3_17 != NULL) {
        do {
            *var_3_17 = 0;
            var_3_17 += 1;
        } while (--var_2_17 != 0);
    }
    sp254 = sp250;
    var_3_18 = (u8 *)(&spD0);
    var_2_18 = 0x10;
    if (var_3_18 != NULL) {
        do {
            *var_3_18 = 0;
            var_3_18 += 1;
        } while (--var_2_18 != 0);
    }
    spD0 = arg5;
    spD4 = 0;
    spD8 = arg6;
    spDC = 0x1E0;
    spE0 = (s128) spD0;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp254, &spE0, 0, 1.0f);
    func_0048a000();
    if (arg_sp0 != 0) {
        func_00260e60(arg0, arg1, arg2, (spB0 & 0xF), 2, arg_sp0, arg7, 1, 10.0f, fparg1, fparg2);
        return;
    }
    func_00260e60(arg0, arg1, arg2, (spB0 & 0xF), 2, spCC, arg7, 1, 10.0f, fparg1, fparg2);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00261560);
#endif
#pragma opt_propagation off
static inline void calendarZeroBytes(void *memory, s32 count)
{
    u8 *cursor;
    s32 remaining;
    cursor = memory;
    remaining = count;
    if (cursor != NULL) {
        do {
            *cursor++ = 0;
            remaining--;
        } while (remaining != 0);
    }
}
// FUN_00262DE0
void func_00262de0(s32 x, s32 y, f32 depth, s32 alpha,
                    s32 date, s32 enabled, f32 scaleX, f32 scaleY,
                    s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite)
{
    extern s32 func_0025f430(f32, f32, f32, s32, s32, s32, s32, u8 *,
                             s32, s32, s32, f32, f32, f32);
    struct CalendarGlyphContext {
        s16 offsetX, offsetY;
        f32 depthOffset, scaleX, scaleY;
        u8 *font;
    };
    char number[4];
    s32 month;
    s32 day;
    struct CalendarColor { u8 r, g, b, a; } depthValue;
    struct CalendarColor depthScratch;
    Quad4 clip;
    Quad4 clipScratch;
    struct CalendarGlyphContext glyphContext;
    s32 weekday;
    s32 color;
    s32 glyphWidth;
    f32 drawDepth;
    void (**states)(u32 state, u32 value);

    func_001104d0(date, &month, &day);
    weekday = func_00110580(date);
    color = enabled ? 0 : 0x686868;
    if (enabled) {
        if (weekday == 0 || func_00110d30(date) != 0) color = 0x860113;
        else if (weekday == 6) color = 0x35081;
    } else {
        if (weekday == 0 || func_00110d30(date) != 0) color = 0x885C62;
        else if (weekday == 6) color = 0x4D626F;
    }
    if (forceWhite == 1 && (weekday == 6 || weekday == 0 || func_00110d30(date) != 0))
        color = 0xFFFFFF;

    calendarZeroBytes(&depthScratch, sizeof(depthScratch));
    depthValue = depthScratch;
    calendarZeroBytes(&clipScratch, sizeof(clipScratch));
    clipScratch.a = clipLeft;
    clipScratch.b = 0;
    clipScratch.c = clipRight;
    clipScratch.d = 480;
    clip = clipScratch;
    states = D_00887300;
    states[0](14, 0);
    states[0](12, 1);
    states[0](7, 2);
    states[0](9, 1);
    states[0](20, 1);
    states[0](6, 0);
    states[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&depthValue, &clip, depth, 0);
    func_0048a000();
    glyphWidth = func_0025f2c0(1, 0, (u8 *)fontWord);
    drawDepth = 1.0f + depth;
    func_0025f430(((f32)x + 0.0f) + ((f32)glyphWidth / 2.0f) * (1.0f - scaleX),
                  (f32)y, drawDepth, color, alpha, 1, weekday, (u8 *)fontWord, 1, 0, 0,
                  0.0f, scaleX, scaleY);
    func_00442088(number, &iGpffffa6c4, day);
    glyphContext.offsetX = 0;
    glyphContext.offsetY = 0;
    glyphContext.depthOffset = 0.0f;
    glyphContext.scaleX = scaleX;
    glyphContext.scaleY = scaleY;
    glyphContext.font = (u8 *)fontWord;
    func_0025f620((f32)(x + 20), ((f32)y + 0.0f) + 19.0f * scaleY, drawDepth,
                  color, alpha, number, 2, 31, 0, func_002605a0, (u8 *)&glyphContext);
}
#pragma opt_propagation on
// FUN_00263220
/* measured: optimization-level probe for 00263220 register colouring */
#pragma optimization_level 1
s32 func_00263220(Code1_00263220State *arg0, s32 arg1, s32 arg2)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_2;
    s32 temp_17;
    s32 temp_3;
    s32 var_16;

    temp_17 = arg0->field20 + 1;
    arg0->field20 = temp_17;
    temp_3 = arg2 - arg1;
    if (temp_3 == 1) {
        temp_f0 = func_0044b7b0((fGpffff84a4 * (f32)temp_17) /
                                15.0f);
        temp_f1 = temp_f0 * (f32)(arg2 - arg1);
        temp_f0 = (f32)arg1;
        temp_f0 = temp_f0 + temp_f1;
        temp_2 = (s32)temp_f0;
        arg0->field18 = temp_2;
        arg0->field1C =
            (s32)(94.0f * (temp_f1 - (f32)(temp_2 - arg1)));
        if (temp_17 >= 0xF) {
            arg0->field18 = arg2;
            arg0->field1C = 0;
            return 1;
        }
            goto block_8;
        }
    if (arg1 < arg2) {
        var_16 = temp_3 * 3;
    } else {
        var_16 = (arg1 - arg2) * 3;
    }
    temp_f1_2 =
        (1.0f + func_0044b7b0(fGpffff8574 +
                               (fGpffff82fc * (f32)temp_17) /
                               (f32)var_16)) /
        2.0f;
    temp_f1_2 = temp_f1_2 * (f32)(arg2 - arg1);
    temp_f0_2 = (f32)arg1;
    temp_f0_2 = temp_f0_2 + temp_f1_2;
    temp_2 = (s32)temp_f0_2;
    arg0->field18 = temp_2;
    arg0->field1C =
        (s32)(94.0f * (temp_f1_2 - (f32)(temp_2 - arg1)));
    if (temp_17 >= var_16) {
        arg0->field18 = arg2;
        arg0->field1C = 0;
        return 1;
    }
block_8:
    return 0;
}
/* measured: closes optimization-level probe for 00263220 */
#pragma optimization_level 2
// FUN_00263460
s32 func_00263460(s32 arg0)
{
    s32 sp3C;
    s32 sp38;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    u8 *temp_2;

    temp_2 = func_00452560();
    func_001104d0(*(s32 *)(temp_2 + 0xC), &sp3C, &sp38);
    switch (*(u32 *)temp_2) {
    case 0:
        *(s32 *)(temp_2 + 4) = func_0025ef20(D_00637420);
        *(u32 *)temp_2 = 1;
        goto block_25;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(temp_2 + 4)) != 0) {
            *(u32 *)temp_2 = 2;
            *(s32 *)(temp_2 + 0x14) =
                func_00266950(arg0, *(s32 *)(temp_2 + 4),
                              *(s32 *)(temp_2 + 8));
            if (func_00106330(0x1471) != 0) {
                func_00106390(0x1471, 0);
                return -1;
            }
        }
        goto block_25;
    case 2:
        *(u32 *)temp_2 = 3;
        *(s32 *)(temp_2 + 0x20) = 0;
        *(s32 *)(temp_2 + 0x18) = *(s32 *)(temp_2 + 0xC);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        /* fall through */
    case 3:
        temp_2_3 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_3;
        if (temp_2_3 > 0xA) {
            *(u32 *)temp_2 = 4;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 8:
        temp_2_4 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_4;
        if (temp_2_4 > 0x1E) {
            func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
            *(u32 *)temp_2 = 0xA;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 4:
        temp_2_5 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_5;
        if (temp_2_5 > 5) {
            *(u32 *)temp_2 = 5;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 9:
        temp_2_6 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_6;
        if (temp_2_6 > 0xA) {
            *(u32 *)temp_2 = 8;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 5:
        if (func_00263220((Code1_00263220State *)temp_2, *(s32 *)(temp_2 + 0xC),
                          *(s32 *)(temp_2 + 0x10)) != 0) {
            *(u32 *)temp_2 = 6;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        func_001104d0(*(s32 *)(temp_2 + 0x18), &sp3C, &sp38);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        goto block_25;
    case 7:
        temp_2_7 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_7;
        if (temp_2_7 > 0xA) {
            *(u32 *)temp_2 = 9;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 6:
        temp_2_8 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_8;
        if (temp_2_8 > 5) {
            *(u32 *)temp_2 = 7;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 10:
        func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
        /* fall through */
    case 11:
        if (func_00266ae0(*(s32 *)(temp_2 + 0x14)) != 0) {
            return -1;
        }
    default:
        goto block_25;
    }
block_25:
    func_00264cb0(arg0, *(s32 *)(temp_2 + 8));
    return 0;
}
/* measured this session: fresh probe 285wd (was ~289 stale) / obj1372B/window1408B (36B under, 2.6% short, within 3% gate); slti inclusive (i<8 to <=7) neutral 285 tie; opt_loop_invariants on worse 314wd (+29, ruled out); short-by-N hunt checked (9 short, not 1-4 trailing dead-arm per top-down fnalign; stack/frame wall). Honest s-map rotation + slot/OR/GPREL walls per archive header; banked. No volatile/asm. */
/* 285 -> 274 (2026-09-18): the hand-written float-to-unsigned conversion(s)
   replaced by the plain cast.  b210 generates the same compare / subtract /
   or-0x80000000 sequence for the cast and colours its temporaries the way
   retail does; the m2c-expanded copy colours them the other way.  Same lever
   as func_00348330 in src/promoted/y_CmbCardEff.c. */
// FUN_00263730 NONMATCHING
#ifdef SKIP_ASM
void func_00263730(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 *arg5, f32 fparg0)
{
    typedef signed __int128 s128;
    s128 spC0;
    u8 sp110;
    u8 sp100;
    s32 spF0;
    s32 spE0;
    s32 spD0;
    s32 sp12C;
    s32 i;
    s32 t22;
    s32 s7v;
    s32 v22;
    s32 s8v;
    f32 f1;
    s32 cv;

    sp12C = arg4;
    spC0 = arg2 & 0xFF;
    for (i = 0; i < 8; i++) {
        t22 = arg3 - 1 + i;
        if (t22 < 0) {
            continue;
        }
        if (sp12C != 0) {
            s7v = func_00110c50(t22, arg3) & 0xFFFF;
            if (s7v != (func_00110c50(t22, arg3 + 1) & 0xFFFF)) {
                f1 = (f32)func_0043c6a0(arg0) / 94.0f;
                f1 = 255.0f - f1;
                cv = (u8)f1;
                sp110 = cv & 0xFF;
                s8v = arg0 + i * 0x5E;
                v22 = s8v + 15;
                func_00262de0(v22, arg1 + 245, fparg0, sp110, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
                spF0 = *(s32 *)((u8 *)arg5 + 4);
                func_00261560(s8v, arg1 + 295, fparg0, sp110, func_00110c50(s7v, arg3) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spF0, 0);
                f1 = (f32)func_0043c6a0(arg0) / 94.0f;
                cv = (u8)f1;
                sp100 = cv & 0xFF;
                func_00262de0(v22, arg1 + 245, fparg0, sp100, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
                spE0 = *(s32 *)((u8 *)arg5 + 4);
                func_00261560(s8v, arg1 + 295, fparg0, sp100, func_00110c50(s7v, arg3 + 1) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spE0, 0);
            }
        } else {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
            spD0 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spD0, 0);
        }
        if (i == 1) {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)((u8 *)arg5 + 4), 0);
            v22 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, v22, 0);
        } else if (i == 2) {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 1, 1.0f, 1.0f, 0xB2, 0x5E, *(s32 *)((u8 *)arg5 + 4), 0);
            v22 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 1, 1.0f, 1.0f, 0xB2, 0x5E, v22, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263730);
#endif
/* measured 00263cb0: object 3232B vs retail 4084B; retail 1021 vs object 808 instrs (-20.9%, gate needs 990-1052); differing words 914 reloc-masked, fnalign 695 edits +2 reloc-only. Archive 262 lines compiles after truthful s128 typedef+aligned(16) and (s32,u8*) per prologue daddu $4,$5 + callee deref; Ghidra/IDA 2-arg agree. Frame retail 0xF0; JAL retail 61 vs object ~39. */
/* shortfall: VU lq 0xC0->0xD0/0xA0->0xB0 + float adda/madd chains + scheduling across 8 switch arms; excluded folded switch (jump table intact), omitted-call as sole cause, unsigned/narrow bloat (signed, per-field). Production stays ASM. */
/* round2 2026-09-18 (scratch /var/tmp/cold263cb0b/NOTE_263cb0_round2.md): pragma round 13 variants best opt_common_subs off 909 (-5; 831 instrs/733 edits, size/edit cost, not bankable), rest tie/regress (schedule 920, prop 929, dead 928, peephole 912, L0 951/L1 920/L3-4 917); subscript N/A (no P[i]; stride i*0x5E hoisted both sides per retail 0x1640F4-104, inline probe ties 914); 7r: 2 accumulator sites both sides (mul.s 4=4, ?? 9v8, prime colour only; mtc1 95->40 is missing calls + lwc1/sd const builds, not spelling). BLOCKER: candidate lacks entire case 7 (Ghidra/IDA agree; retail .L00264238-4474; ~14-15 JAL of the jal 61->46 delta + ~200 of 213 missing instrs); prior shortfall line incomplete on this point (JAL recount 46, not ~39). Production stays ASM. */
/* banked 2026-09-18 B2: emitted 1028 vs retail 1021 (+0.7%, gate 991-1052), 915wd reloc-masked, fnalign 1091 edits +2 reloc-only, jal 63 vs 61. Restored missing case 7 (retail 0x164850-0x164B5C; loop skips 1 and 4, const-0xFF color, quotient staging in temp_f21 across calls); shared else48 via default-label goto (retail .L00264C10 shared by case 5 and 7; also fixes case-5-else arg4 0 to 1); call-idiom fix fparg0 0.0f and arg5 0 at 8 case-8 sites per retail f12 0 and the in-file 00263730 idiom; temp_20 s64 to s32 per retail addu. Baseline was archive262 at 914wd 695ed 808in. Recipe log: /var/tmp/cold263cb0b/NOTE_263cb0_round2.md. */
/* 2026-09-18 opcode census: 915 -> 908.  The census showed `sd +42`, which
   is not a wide local - it is fourteen stack arguments stored 64 bits wide
   because `func_0025f430` had no visible prototype here.  Every other caller
   in this file declares it at block scope; this body did not, so the
   arguments went through the default promotion.  Declaring
   `extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32,
   f32, f32, f32, f32, f32)` - the signature `src/Event/Fcl/shdSprite.c`
   defines - is worth seven words.  Adding prototypes for `func_00263730`
   and `func_0025f2c0` alongside does not compile; their block-scope
   declarations elsewhere in this file disagree, which is its own finding. */
/* 2026-09-19 hole/lump (fnalign without --quiet, opclass.py handoff 7t): before retail 1021 vs object 1000
   (inside 991-1052), fnalign 1014 edits +2 reloc-only, score 908wd (obj 4000B/window 4096B),
   pure hole delete retail[185:218] (33) vs pure lump insert retail[478:478] object[729:850] (121, ~4x hole).
   Lump makeup before: sd 5, dsll32 2, lui 7, move 20, mtc1 6, mov.s 3, jal 9, addiu 28;
   hole wants mtc1 5, mov.s 3, jal 2. Opclass before 38: mtc1 -22, lui +10, move +10,
   addiu -9, mov.s -7, dsll32 +6, sw -6, sd +6. Characterised as sign/zero-extension cascade
   from a too-wide local (f32 args promoted to f64: sd/dsll32/lui where retail wants mtc1/mov.s/sw),
   not a switch chain, table-arithmetic, or struct copy. Fix: block-scope extern s32 func_0025f3f0
   (s32x6+f32x3) per src/Event/Fcl/shdSprite.c and extern void func_00263730(s32x5+u8*+f32) with u8*
   (not u32*) to match call sites without casts; prior note on non-compiling prototypes was file-scope,
   block-scope here does not conflict. After: same 1021 vs 1000, 999 edits +2 (-15), score 908 unchanged,
   hole gone (no delete >=20), lump still 121 but dsll32 0, sd 5->3, mtc1 6->11, mov.s 3->5;
   opclass 13: lui +10, addiu -9, sw -6, mtc1 -3 (dsll32/sd/mov.s gone). Case-7 recovery untouched. */
/* 2026-09-19 reg-alloc collapse (Main handoff: lui+10/addiu-9/sw-6 address fold + mtc1-3 check).
   Before (prototype fix banked): retail 1021 vs object 1000, 999 edits +2, score 908, opclass 13
   (lui +10, addiu -9, sw -6, mtc1 -3), hole gone, pure lump 121 at retail[478:478] object[729:850].
   Relocs in 729:850 are only R_MIPS_26 (jal: 2x110C50, 2x25f3f0/263730, loop 262de0/261560 tails);
   no HI16/LO16/GPREL16 there, so the lump's 7 lui are float consts, not global addresses.
   Overall lui+10 is D_00887300 base rebuild (object lui $v0,0 + lw per site x14 vs retail
   lui $s1,0x88 + addiu hoisted + lw per site); writing D_00887300[0] for (*D_00887300) ties
   (999/908 unchanged), so no preamble of the ((u32)SYM & 0xFFFF0000)-with-negative-offset kind here.
   Root cause of the pure 121/33 pair was a swapped saved-reg pair: object kept temp_2 in $s1
   (move $s1,$v0; lw $s0,0x18($s1)) where retail keeps it in $s0, throwing every later anchor
   (277 vs 398 + 121 + 398 vs 1). Fix: declare u8 *temp_2 + s32 temp_3 first (after externs),
   choosing $s0 (now move $s0,$v0; lw $s1,0x18($s0), matching retail). After: same 1021 vs 1000
   (inside 991-1052), 297 edits +2 (-702), score 905 (-3), opclass 13 unchanged (opcodes same,
   regs fixed), no delete/insert >=20 (largest delete 10 at 205:215, largest inserts 5-6).
   missing_prototypes.py is clean for this body (all calls declared), so mtc1 -3 is not an
   undeclared call but const/scheduling residue. Case-7 recovery untouched. */
// FUN_00263CB0 NONMATCHING
#ifdef NON_MATCHING
void func_00263cb0(s32 arg0, u8 *arg1)
{
    typedef signed __int128 s128;
    extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
    extern s32 func_0025f3f0(s32, s32, s32, s32, u8 *, s32, f32, f32, f32);
    extern void func_00263730(s32, s32, s32, s32, s32, u8 *, f32);
    u8 *temp_2;
    s32 temp_3;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    s128 spD0 __attribute__((aligned(16)));
s32 spCC;
s32 spC8;
s32 spC4;
s32 spC0;
    s128 spB0 __attribute__((aligned(16)));
s32 spAC;
s32 spA8;
s32 spA4;
s32 spA0;
    f32 *var_3;
    f32 *var_3_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f20;
    f32 temp_f21;
    u8 *var_3_2;
    u8 *var_3_4;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_17;
    s32 temp_17_10;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_17_8;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_18_4;
    s32 temp_18_5;
    s32 temp_18_6;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 var_17;
    s32 var_18;
    s32 var_21;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_20;
    s64 temp_20_2;

    temp_2 = func_00452560(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 3:
        temp_17 = *(s32 *)(temp_2 + 0x18);
        temp_2_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_2_2 < 5) {
            temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)temp_2_2) / 5.0f);
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 1.0f - temp_f20;
            temp_f13_2 = 88.0f + temp_f0 * temp_f13;
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, temp_f13_2, 0.0f, 0.0f, 0.0f,
                          temp_f20, 1.0f);
        } else {
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
        temp_3_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_2 >= 2) {
            temp_f0 = 255.0f * ((f32)(temp_3_2 - 1) / 9.0f);
            func_00263730(0, 0, (s32)temp_f0 & 0xFF, temp_17, 0,
                          temp_2, 0.0f);
        }
        break;
    case 4:
    case 9:
        temp_17_2 = *(s32 *)(temp_2 + 0x18);
        func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 88.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_00263730(0, 0, 0xFF, temp_17_2, 0, temp_2, 0.0f);
        break;
    case 5:
        temp_17_3 = *(s32 *)(temp_2 + 0xC);
        temp_3_4 = *(s32 *)(temp_2 + 0x10);
        if (temp_3_4 - temp_17_3 == 1) {
            if (*(s32 *)(temp_2 + 0x18) == temp_3_4) {
                var_18 = -0x5E;
            } else {
                var_18 = -*(s32 *)(temp_2 + 0x1C);
            }
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            func_00263730(var_18, 0, 0xFF, temp_17_3, 0, temp_2, 0.0f);
        } else {
            goto else48;
        }
        break;
    case 8:
        temp_18_2 = *(s32 *)(temp_2 + 0x18);
        temp_3_3 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_3 < 0xA) {
            temp_f0 = 255.0f * (1.0f - (f32)temp_3_3 / 10.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            var_21 = 0;
            while (var_21 < 7) {
                temp_20 = temp_18_2 - 1 + var_21;
                if ((temp_20 >= 0) && (var_21 != 1)) {
                    temp_19 = var_21 * 0x5E;
                    func_00262de0(temp_19 + 0xF, 0xF5, 0.0f, (s32)temp_f0 & 0xFF, (s32)temp_20, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(temp_2 + 4), 0);
                    temp_22 = *(s32 *)(temp_2 + 4);
                    func_00261560(temp_19, 0x127, 0.0f, (s32)temp_f0 & 0xFF, func_00110c50((s32)temp_20, temp_18_2) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, temp_22, 0);
                }
                var_21 += 1;
            }
            func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_18_2, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16, 0);
        } else if (temp_3_3 < 0x19) {
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            var_3 = &spE8;
            var_2 = 4;
            if (var_3 != NULL) {
                do {
                    *(u8 *)var_3 = 0;
                    var_3 = (f32 *)((u8 *)var_3 + 1);
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            spEC = spE8;
            var_3_2 = (u8 *)&spC0;
            var_2_2 = 0x10;
            if (var_3_2 != NULL) {
                do {
                    *var_3_2 = 0;
                    var_3_2 += 1;
                    var_2_2 -= 1;
                } while (var_2_2 != 0);
            }
            spC0 = 0;
            spC4 = 0;
            spC8 = 0x280;
            spCC = 0x1E0;
            spD0 = *(s128 *)&spC0;
            (*D_00887300)(0xE, 0);
            (*D_00887300)(0xC, 1);
            (*D_00887300)(7, 2);
            (*D_00887300)(9, 1);
            (*D_00887300)(0x14, 1);
            (*D_00887300)(6, 0);
            (*D_00887300)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x44);
            func_00489f80();
            func_0045d6e0(&spEC, &spD0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_18_2, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16_2 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16_2, 0);
        } else if (temp_3_3 < 0x1E) {
            temp_f20 = (f32)(temp_3_3 - 0x19) / 5.0f;
            temp_f0_2 = 1.0f - temp_f20;
            temp_f13_2 = 255.0f * temp_f0_2;
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 88.0f + temp_f0 * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, temp_f13, 0.0f, 0.0f, 0.0f,
                          temp_f0_2, 1.0f);
            var_3_3 = &spE0;
            var_2_3 = 4;
            if (var_3_3 != NULL) {
                do {
                    *(u8 *)var_3_3 = 0;
                    var_3_3 = (f32 *)((u8 *)var_3_3 + 1);
                    var_2_3 -= 1;
                } while (var_2_3 != 0);
            }
            spE4 = spE0;
            var_3_4 = (u8 *)&spA0;
            var_2_4 = 0x10;
            if (var_3_4 != NULL) {
                do {
                    *var_3_4 = 0;
                    var_3_4 += 1;
                    var_2_4 -= 1;
                } while (var_2_4 != 0);
            }
            spA0 = 0;
            spA4 = 0;
            spA8 = 0x280;
            spAC = 0x1E0;
            spB0 = *(s128 *)&spA0;
            (*D_00887300)(0xE, 0);
            (*D_00887300)(0xC, 1);
            (*D_00887300)(7, 2);
            (*D_00887300)(9, 1);
            (*D_00887300)(0x14, 1);
            (*D_00887300)(6, 0);
            (*D_00887300)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x44);
            func_00489f80();
            func_0045d6e0(&spE4, &spB0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, 0.0f, (s32)temp_f13_2 & 0xFF, temp_18_2, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16_3 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, (s32)temp_f13_2 & 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16_3, 0);
        }
        break;
    case 6:
        temp_17_5 = *(s32 *)(temp_2 + 0xC);
        if (*(s32 *)(temp_2 + 0x10) - temp_17_5 == 1) {
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
            func_00263730(-0x5E, 0, 0xFF, temp_17_5, 0, temp_2, 0.0f);
        } else {
            temp_17_6 = *(s32 *)(temp_2 + 0x18);
            temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
            func_00263730(temp_18_3, 0, 0xFF, temp_17_6, 0, temp_2, 0.0f);
        }
        break;
    case 7:
        temp_17_7 = *(s32 *)(temp_2 + 0x10);
        if (temp_17_7 - *(s32 *)(temp_2 + 0xC) == 1) {
            temp_18_4 = func_00110c50(temp_17_7 + 3, temp_17_7) & 0xFFFF;
            temp_18_5 = func_00110c50(temp_17_7 + 3, temp_17_7 + 1) & 0xFFFF;
            if (temp_18_4 == temp_18_5) {
                temp_17_8 = *(s32 *)(temp_2 + 0x18);
                func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                              88.0f, 0.0f, 0.0f);
                func_00263730(0, 0, 0xFF, temp_17_8, 0, temp_2, 0.0f);
            } else {
                temp_17_9 = *(s32 *)(temp_2 + 0xC);
                func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                              88.0f, 0.0f, 0.0f);
                var_21 = 0;
                while (var_21 < 7) {
                    if ((var_21 != 1) && (var_21 != 4)) {
                        temp_19_2 = temp_17_9 + var_21;
                        temp_19 = var_21 * 0x5E;
                        func_00262de0(temp_19 + 0xF, 0xF5, 0.0f, 0xFF, temp_19_2, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(temp_2 + 4), 0);
                        temp_22 = *(s32 *)(temp_2 + 4);
                        func_00261560(temp_19, 0x127, 0.0f, 0xFF, func_00110c50(temp_19_2, temp_17_9) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, temp_22, 0);
                    }
                    var_21 += 1;
                }
                func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_17_9 + 1, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                temp_16 = *(s32 *)(temp_2 + 4);
                func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 1, temp_17_9) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16, 0);
                temp_3_2 = *(s32 *)(temp_2 + 0x20);
                if (temp_3_2 < 5) {
                    temp_f21 = (f32)temp_3_2 / 5.0f;
                    func_00262de0(0x187, 0xF5, 0.0f, 0xFF, temp_17_9 + 4, 0, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                    temp_18_6 = *(s32 *)(temp_2 + 4);
                    func_00261560(0x178, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 4, temp_17_9) & 0xFFFF, 0, 1.0f - temp_f21, 1.0f, 0, 0x58, temp_18_6, 0);
                } else {
                    temp_f21 = ((f32)temp_3_2 - 5.0f) / 5.0f;
                    func_00262de0(0x187, 0xF5, 0.0f, 0xFF, temp_17_9 + 4, 0, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                    temp_18_6 = *(s32 *)(temp_2 + 4);
                    func_00261560(0x178, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 4, temp_17_9 + 1) & 0xFFFF, 0, temp_f21, 1.0f, 0, 0x58, temp_18_6, 0);
                }
            }
        } else {
            goto else48;
        }
        break;
    case 0:
    case 1:
    case 2:
        break;
    default:
        break;
    else48:
        temp_17_10 = *(s32 *)(temp_2 + 0x18);
        temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
        func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                      88.0f, 0.0f, 0.0f);
        func_00263730(temp_18_3, 0, 0xFF, temp_17_10, 1, temp_2, 0.0f);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263cb0);
#endif
// FUN_00264CB0
void func_00264cb0(s32 arg0, s32 arg1)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32, u8 *))(temp_2 + 8) = func_00263cb0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0((u8 *)arg1, temp_2);
}
// FUN_00264D10
void func_00264d10(void)
{
    s32 temp_4;
    u8 *temp_2;

    temp_2 = func_00452560();
    if (func_00452490((u8 *)*(s32 *)(temp_2 + 0x14)) != 0) {
        func_00452080(*(s32 *)(temp_2 + 0x14));
    }
    temp_4 = *(s32 *)(temp_2 + 4);
    if (temp_4 != 0) {
        func_0025f230((void *)temp_4);
    }
    (*jtbl_008873EC)(temp_2);
}
// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266A90
void func_00266a90(u8 *arg0) {
    u8 *p;

    if (func_00452490(arg0) != 0) {
        p = func_00452560(arg0);
        *(s32 *)(p + 4) |= 2;
    }
}

// FUN_00266AE0
s32 func_00266ae0(s32 arg0)
{
    u8 *temp_2;
    s32 temp_4;

    if (func_00452490() != 0) {
        temp_2 = func_00452560(arg0);
        temp_4 = *(s32 *)(temp_2 + 4);
        if ((temp_4 & 1) && !(temp_4 & 4)) {
            return 0;
        }
        if (*(s32 *)temp_2 == 1) {
            return 1;
        }
        return 0;
    }
    return 1;
}
// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}



// FUN_00266BA0
s32 func_00266ba0(u8 *arg0)
{
    s32 sp3C;
    s32 sp38;
    u8 *work;
    s32 temp;
    s32 state;

    work = func_00452560();
    func_001104d0(*(s32 *)(work + 0xC), &sp3C, &sp38);
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = func_0025ef20(D_00638F90);
        *(s32 *)(work + 0) = 1;
        break;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(work + 4)) != 0) {
            *(s32 *)(work + 0) = 2;
            *(s32 *)(work + 0x14) = 0;
        }
        break;
    case 2:
        temp = *(s32 *)(work + 0x14) + 1;
        *(s32 *)(work + 0x14) = temp;
        if (temp >= 0x3C) {
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
    case 4:
        return -1;
    default:
        break;
    }
    func_002674b0((s32)arg0, (u8 *)*(s32 *)(work + 8));
    return 0;
}
/* measured (2026-09-18): probe_variants 429 differing words reloc-masked via `python3 tools/probe_variants.py src/promoted/code1_0026.c func_00266cc0 --candidate FIX2=/tmp/cand66cc_fix2.c`; fnalign retail 506 vs object 495 instrs (273 edits +3 reloc) via `python3 tools/fnalign.py src/promoted/code1_0026.c func_00266cc0 --candidate /tmp/cand66cc_fix2.c --quiet`; -11 short (2.2% within 3% rule). Signature (s32,s32) per top extern (u8*->s32 cast for 00452560); s16 temp_date dsll16/dsra16 per prologue; fGpffff84a4 mul/div + 0044b7b0 sin chains; 255/5.0f/15.0f/20.0f scales; float-to-int overflow c.le/bc1t checks per retail (direct (s32) omits 21, 455->495); local externs for 0025f430 (s32 x8+f32 x6)/0025f2c0/0044b7b0 fix 416B-style overrun. Wall remains call/setup + FPU scheduling. No volatile/asm. */
/* 2026-09-18: the three hand-written float-to-unsigned conversions replaced by
   plain `(u32)` casts.  Measured a tie at 429 words but the edit-group count
   drops 273 -> 263, so the remaining residual is elsewhere; the expanded form
   was an m2c artifact, not evidence. */
// FUN_00266CC0 NONMATCHING
#ifdef NON_MATCHING
void func_00266cc0(s32 arg0, s32 arg1)
{
    extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
    extern s32 func_0025f2c0(s32, s32, u8 *);
    extern f32 func_0044b7b0(f32);
    u8 *temp_2;
    u8 *temp_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 var_17;
    s32 var_18;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s16 temp_date;

    temp_2 = func_00452560((u8 *)arg1);
    var_18 = *(s32 *)(temp_2 + 0xC);
    var_17 = *(s32 *)(temp_2 + 0x10);
    temp_date = (s16)func_001060b0();
    if (func_00110d30(temp_date) != 0) {
        if (*(s32 *)(temp_2 + 0xC) == 3) {
            var_18 = 6;
        }
        if (*(s32 *)(temp_2 + 0x10) == 3) {
            var_17 = 6;
        }
    }
    if (*(s32 *)temp_2 != 2) {
        return;
    }
    temp_3 = *(s32 *)(temp_2 + 0x14);
    if (temp_3 < 0xF) {
        temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)temp_3) / 15.0f);
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 200.0f * (1.0f - temp_f20), 0.0f, 0.0f,
                      0.0f, temp_f20, 1.0f);
        temp_3_2 = *(s32 *)(temp_2 + 0x14);
        if (temp_3_2 >= 0xB) {
            temp_f1 = 255.0f * ((f32)(temp_3_2 - 0xA) / 5.0f);
            var_3 = (u32)temp_f1;
            func_0025f430(0, var_3 & 0xFF, var_18 + 1, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
        return;
    }
    if (temp_3 < 0x14) {
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_0025f430(0, 0xFF, var_18 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    if (temp_3 < 0x19) {
        temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x14)) / 5.0f);
        temp_f21 = 1.0f - temp_f20;
        temp_3_2 = func_0025f2c0(0, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20,
                      0.0f, 0.0f, 0.0f, temp_f21, 1.0f);
        temp_3_2 = func_0025f2c0(var_18 + 1, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0, 0xFF, var_18 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20,
                      0.0f, 0.0f, 0.0f, temp_f21, 1.0f);
        return;
    }
    if (temp_3 < 0x1E) {
        temp_f20_2 = 1.0f -
                     func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x19)) / 5.0f);
        temp_f21_2 = 1.0f - temp_f20_2;
        temp_3_2 = func_0025f2c0(0, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20_2,
                      0.0f, 0.0f, 0.0f, temp_f21_2, 1.0f);
        temp_3_2 = func_0025f2c0(var_17 + 1, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0, 0xFF, var_17 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20_2,
                      0.0f, 0.0f, 0.0f, temp_f21_2, 1.0f);
        return;
    }
    if (temp_3 < 0x28) {
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_0025f430(0, 0xFF, var_17 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    if (temp_3 < 0x3C) {
        temp_f0_2 = func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x28)) / 20.0f);
        temp_f16 = 1.0f - temp_f0_2;
        temp_f2 = 255.0f * temp_f16;
        var_3_2 = (u32)temp_f2;
        func_0025f430(0xFFFFFF, var_3_2 & 0xFF, 0, 0,
                      *(u8 **)(temp_2 + 4), 1,
                      0, 0, -200.0f * temp_f0_2, 0.0f, 0.0f, 0.0f,
                      temp_f16, 1.0f);
        temp_3_3 = *(s32 *)(temp_2 + 0x14);
        if (temp_3_3 < 0x2D) {
            temp_f1_2 = 255.0f *
                        (1.0f - (f32)(temp_3_3 - 0x28) / 5.0f);
            var_3_3 = (u32)temp_f1_2;
            func_0025f430(0, var_3_3 & 0xFF, var_17 + 1, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266cc0);
#endif
// FUN_002674B0
void func_002674b0(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266cc0;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_00267510
void func_00267510(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0025f230((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00267570
s32 func_00267570(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *work;
    s32 result;

    if (arg3 == 0) {
        func_0046d730(D_00638FA0, 0xF2);
    }
    func_0044ea90(D_00638FA0, 0xF3);
    work = D_008873F4[0](1, 0x18, 0x40000);
    *(s32 *)(work + 0) = 0;
    *(s32 *)(work + 8) = arg3;
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x10) = arg2;
    result = func_00451fc0(arg0, D_00638FB0, 0xF, 0, 0,
                           (void (*)(void))func_00266ba0,
                           (void (*)(void))func_00267510, (s32)work);
    func_0045a8d0(3, 0);
    func_004598e0(0xA);
    return result;
}
static inline f32 func_0026_div_140(f32 value)
{
    return value / 140.0f;
}
// FUN_00267670
void func_00267670(u8 **arg0)
{
    u8 *base;
    u8 *var_18;
    u8 *temp_17;
    f32 old;
    f32 result;
    u8 *temp_4;
    f32 temp_f12;
    extern void func_002e2240(void *arg0, void *arg1, void *arg2);
    extern f32 D_00761514;
    extern f32 D_00761658;
    extern f32 D_0076165C;
    extern f32 D_00761260;
    extern s32 func_00267800(u8 **arg0, u8 *arg1);
    extern f32 func_002677a0(f32 arg0, f32 arg1, f32 arg2, f32 arg3,
                              f32 arg4);

    base = (u8 *)arg0;
    *(s32 *)(base + 0xC) = 0xFF;
    var_18 = *(u8 **)(*(u8 **)base + 8);
    goto loop_test;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0xC);
    if (func_00267800(arg0, *(u8 **)(var_18 + 0x14)) != 0) {
        temp_4 = *(u8 **)base;
        func_002e2240(temp_4, temp_4 + 4, var_18);
    }
    var_18 = temp_17;
loop_test:
    if (var_18 != NULL) {
        goto loop_body;
    }
    if ((*(f32 *)(base + 4) > 0.0f) ||
        (*(u16 *)(*(u8 **)base + 0x10) != 0)) {
        *(f32 *)(base + 4) += 1.0f;
        if (*(f32 *)(base + 8) == 0.0f) {
            *(f32 *)(base + 8) = D_00761514;
            return;
        }
        temp_f12 = func_0026_div_140(*(f32 *)(base + 4));
        result = func_002677a0(D_00761658, D_00761658,
                               D_0076165C, D_00761260, temp_f12);
        old = *(f32 *)(base + 8);
        *(f32 *)(base + 8) = result * old + old;
    }
}
/* measured: optimization_level 1 and the right-associated first two terms produce the retail FPU chain; exact match nd 0 (obj 88B/window 96B). */
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
#pragma optimization_level 1
// FUN_002677A0
f32 func_002677a0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}
/* measured: closes the optimization_level bracket (nd 0). */
#pragma optimization_level 2

/* Copy complete table objects; renderer callbacks may change the item index. */
#pragma optimization_level 1
static inline f32 func_00267800_threshold(void)
{
    return fGpffff8218;
}
static inline s32 *func_00267800_shape_at(s32 *values, s32 index)
{
    return values + index;
}
#pragma optimization_level 2
#pragma opt_common_subs off
// FUN_00267800
s32 func_00267800(u8 **arg0, u8 *arg1)
{
    f32 position[4];
    Code1_00267800ShapeTable shapes;
    Code1_00267800ScaleTable scales;
    s32 alpha;
    s32 shape;
    f32 scale;
    f32 threshold;
    f32 renderScale;
    s32 *shapeSrc;
    s32 *shapeDst;
    u32 *scaleSrc;
    u32 *scaleDst;
    s32 count;

    func_0043f810(position, arg1 + 0x28, sizeof(position));
    position[2] += -136.0f + (150.0f * *(f32 *)((u8 *)arg0 + 4)) / 120.0f;
    position[0] += 288.0f;
    position[1] += 222.0f;
    shapeSrc = D_00638FD0.value;
    shapeDst = shapes.value;
    count = 19;
    do {
        s32 value = *shapeSrc++;
        count--;
        *shapeDst++ = value;
    } while (count > 0);
    scaleSrc = D_00639020.words;
    scaleDst = scales.words;
    count = 19;
    do {
        u32 value = *scaleSrc++;
        count--;
        *scaleDst++ = value;
    } while (count > 0);
    alpha = 0xFF;
    scale = *(f32 *)((u8 *)arg0 + 8) * scales.value[*(s32 *)(arg1 + 4)];
    position[3] = scale;
    if (scale < (threshold = fGpffff8218)) {
        alpha = (s32)((255.0f * scale) / threshold);
    }
    alpha = (s32)((f32)alpha * ((f32)*(s32 *)((u8 *)arg0 + 0xC) / 255.0f));
    shape = *func_00267800_shape_at(shapes.value, *(s32 *)(arg1 + 4));
    if (shape != 9) {
        if (!(scale <= func_00267800_threshold())) {
            renderScale = position[3];
            func_00267b20(position[0], position[1], 0.0f, 0x76BF48, alpha, 1, shape, 0, 0,
                           4.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            func_00267b20(position[0], position[1], 0.0f, 0x4883BF, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           2.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            func_00267b20(position[0], position[1], 0.0f, 0xBF4848, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[2] - 2.0f, renderScale, renderScale);
        }
        renderScale = position[3];
        func_00267b20(position[0], position[1], 0.0f, 0x292929, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[2], renderScale, renderScale);
    }
    if (!(position[3] < 7.0f)) {
        return 1;
    }
    return 0;
}
#pragma opt_common_subs reset
#pragma optimization_level 2
/* Floor: 304 differing words, 445 emitted instructions against retail's
   452 (1780 bytes in a 1808-byte window), frame -0xDB0 exact.  The
   twelve-argument signature is six ints and six floats with two $t
   registers live on entry, so ints five and six ride $t0/$t1; the s64
   width for those two comes from the caller-side declaration above and
   scores 8 words better than s32.  The frame is one struct so the
   0x100/0x150/0x1A0/0x5A0/0xDA8 offsets fall out of the layout, and the
   two 0x13-word table copies are u32 do-while loops, which is what gives
   retail's lw/sw pairs; the DA8/DAC lwc1/swc1, the E0 zero/sw/lq-sq and
   the D_0063A9E0/D_0063AA30 lui/lo blocks all match.  Loop counters,
   pointers and unpacked colour bytes are split per phase; the fourth loop
   and the final call use count/count-1; (s16) narrowing gives the
   dsll32/dsra32 pairs.
   WALL: callee-saved allocation shift (combined in $s4 vs $s0, the args in
   $s3-$s0 vs $s5-$s2, the table base in $v0 vs $s1), the destination
   addu order in the four point/colour loops (base+index vs index+sp+off
   with the lwc1/addu pair reordered) and the func_0045e6a0 move order. On propagated base 2026-09-17: schedule 392 worse, cse_off 417 worse, loopinv 309 worse; propagation alone best. */
/* measured 00267b20: `opt_propagation off` inside the guard is worth 40 words (304 -> 264). */
// FUN_00267B20 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_00267b20(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg4, s64 arg5,
                   f32 fparg3, f32 fparg4, f32 fparg5)
{
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    extern u32 D_0063A9E0[];
    extern u32 D_0063AA30[];
    extern void func_00364c70(void);
    extern void func_0045e6a0(void *arg0, void *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg1, f32 fparg2, f32 fparg3);
    struct {
        u_long128 c0;
        s32 d0;
        u8 padD4[12];
        u_long128 e0;
        u_long128 f0;
        u32 arr100[0x13];
        u8 pad100[4];
        u32 arr150[0x13];
        u8 pad150[4];
        u8 colors[256][4];
        f32 points[257][2];
        f32 da8;
        f32 dac;
    } frame;
    s32 i9;
    s32 iA;
    s32 iB;
    s32 iC;
    s32 count9;
    s32 countA;
    s32 countB;
    u8 *ptr9;
    u8 *ptrA;
    u8 *ptrB;
    u8 b0_9;
    u8 b1_9;
    u8 b2_9;
    u8 b3_9;
    u8 b0;
    u8 b1;
    u8 b3;
    u32 tmp;
    u32 *src;
    u32 *dst;
    s32 n;
    u8 *p;
    s32 m;
    void (**tbl)(u32, u32);
    u32 tbl2;
    u32 combined;
    combined = ((u32)arg0 << 8) | (u32)arg1;
    src = D_0063A9E0;
    dst = frame.arr150;
    n = 0x13;
    do {
        tmp = *src;
        src++;
        n--;
        *dst = tmp;
        dst++;
    } while (n > 0);
    src = D_0063AA30;
    dst = frame.arr100;
    n = 0x13;
    do {
        tmp = *src;
        src++;
        n--;
        *dst = tmp;
        dst++;
    } while (n > 0);
    if (!(fparg4 < 7.0f) || !(fparg5 < 7.0f)) {
        return;
    }
    if (arg3 == 9) {
        count9 = frame.arr150[arg3 * 2];
        ptr9 = (u8 *)frame.arr100[arg3 * 2];
        i9 = 0;
        b0_9 = (combined >> 24) & 0xFF;
        b1_9 = (combined >> 16) & 0xFF;
        b2_9 = (combined >> 8) & 0xFF;
        b3_9 = combined & 0xFF;
        while (i9 < count9) {
            frame.points[i9][0] = (fparg0 + ((f32 *)ptr9)[i9 * 2]) - ((f32 *)ptr9)[0];
            frame.points[i9][1] = (fparg1 + ((f32 *)ptr9)[i9 * 2 + 1]) - ((f32 *)ptr9)[1];
            frame.colors[i9][0] = b0_9;
            frame.colors[i9][1] = b1_9;
            frame.colors[i9][2] = b2_9;
            frame.colors[i9][3] = b3_9;
            i9++;
        }
        func_00364c50();
        func_0045e6a0(frame.colors, frame.points, fparg2, count9, 5, 1, arg4, arg5, fparg3, fparg4, fparg5);
        func_00364c70();
        return;
    }
    p = (u8 *)&frame.da8;
    m = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            m--;
        } while (m != 0);
    }
    frame.dac = frame.da8;
    p = (u8 *)&frame.e0;
    m = 0x10;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            m--;
        } while (m != 0);
    }
    ((s32 *)&frame.e0)[0] = 0;
    ((s32 *)&frame.e0)[1] = 0;
    ((s32 *)&frame.e0)[2] = 0x280;
    ((s32 *)&frame.e0)[3] = 0x1E0;
    frame.f0 = frame.e0;
    tbl = D_00887300;
    tbl[0](0xE, 0);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](0x14, 1);
    tbl[0](6, 0);
    tbl[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&frame.dac, &frame.f0, 10.0f, 0);
    func_0048a000();
    countA = frame.arr150[arg3 * 2 + 1];
    ptrA = (u8 *)frame.arr100[arg3 * 2 + 1];
    iA = 0;
    b0 = (combined >> 24) & 0xFF;
    b1 = (combined >> 16) & 0xFF;
    frame.d0 = (combined >> 8) & 0xFF;
    b3 = combined & 0xFF;
    while (iA < countA) {
        frame.points[iA][0] = (fparg0 + ((f32 *)ptrA)[iA * 2]) - ((f32 *)ptrA)[0];
        frame.points[iA][1] = (fparg1 + ((f32 *)ptrA)[iA * 2 + 1]) - ((f32 *)ptrA)[1];
        frame.colors[iA][0] = b0;
        frame.colors[iA][1] = b1;
        frame.colors[iA][2] = (u8)frame.d0;
        frame.colors[iA][3] = b3;
        iA++;
    }
    func_00364c50();
    tbl2 = (u32)D_00887300;
    frame.c0 = (u_long128)tbl2;
    ((void (**)(u32, u32))tbl2)[0](6, 0);
    ((void (**)(u32, u32))&frame.c0)[0](8, 1);
    func_003f6440(3, 0x30003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045e6a0(frame.colors, frame.points, fparg2, countA, 5, 0, arg4, arg5, fparg3, fparg4, fparg5);
    func_0048a000();
    func_00364c70();
    countB = frame.arr150[arg3 * 2];
    ptrB = (u8 *)frame.arr100[arg3 * 2];
    iB = 0;
    while (iB < countB) {
        frame.points[iB][0] = (fparg0 + ((f32 *)ptrB)[iB * 2]) - ((f32 *)ptrB)[0];
        frame.points[iB][1] = (fparg1 + ((f32 *)ptrB)[iB * 2 + 1]) - ((f32 *)ptrB)[1];
        frame.colors[iB][0] = b0;
        frame.colors[iB][1] = b1;
        frame.colors[iB][2] = (u8)frame.d0;
        frame.colors[iB][3] = b3;
        iB++;
    }
    if (arg1 == 0xFF) {
        func_00364c50();
    }
    func_0045e6a0(frame.colors, frame.points, 1.0f + fparg2, countB, 5, 1, arg4, arg5, fparg3, fparg4, fparg5);
    if (arg1 == 0xFF) {
        func_00364c70();
    }
    iC = 1;
    while (iC < countA) {
        frame.points[iC - 1][0] = (fparg0 + ((f32 *)ptrA)[iC * 2]) - ((f32 *)ptrA)[0];
        frame.points[iC - 1][1] = (fparg1 + ((f32 *)ptrA)[iC * 2 + 1]) - ((f32 *)ptrA)[1];
        frame.colors[iC - 1][0] = b0;
        frame.colors[iC - 1][1] = b1;
        frame.colors[iC - 1][2] = (u8)frame.d0;
        frame.colors[iC - 1][3] = b3;
        iC++;
    }
    if (arg1 == 0xFF) {
        func_00364c50();
    }
    {
        s32 v0;
        s32 v1;
        v0 = (s32)(s16)(s32)(fparg0 + ((f32)arg4 - frame.points[0][0]));
        v1 = (s32)(s16)(s32)(fparg1 + ((f32)arg5 - frame.points[0][1]));
        func_0045e6a0(frame.colors, frame.points, fparg2, countA - 1, 4, 1, v0, v1, fparg3, fparg4, fparg5);
    }
    if (arg1 == 0xFF) {
        func_00364c70();
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267b20);
#endif
// FUN_00268A70
s32 func_00268a70(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_16 - 1;
    *(s32 *)temp_16 = temp_2;
    if (temp_2 < 0) {
        func_004b1150((u8 *)*(s32 *)(temp_16 + 4));
        *(s32 *)(temp_16 + 4) = 0;
        return -1;
    }
    return 0;
}

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

/* measured 0026cef0: L26 277wd/obj1088B/window1296B (208B short, 16% short, fails 3% gate >=1257B) + gap-zero 287wd + array[4]->[8] 276wd/frame-0x160 still short; frame-struct explicit 0x80-0x16C pads (0xF0 size) whole-window 324v325/obj1300B/window1296B (4B over, 0.3%, within gate), fnalign 75 edits (+3 reloc-only): earliest mtc1/div/mov FPR (f23/f21/f20 coloring), sll/addu *36 with var_5 hoist, s0/s1 (var_17/var_16), addu order, lwc1/swc1 scheduling, MAC FPR; tried float honesty (1.0f/20.0f, s8 lb, f32), branch polarity (<=/< with !< for bc1f/bc1t), bottom-test while, cached base (base/base2, fixed lb + whole-window), MAC second-addend (delta*weight+first), interleaved sig (arg0/fparg0/arg1/arg2 for mov.s order), declaration reorder (75 vs 87), block V3 (71 edits but +1 instr, kept per-field donor-style). Remaining are register/scheduling/FPU floors per matching.md; banked. No volatile/asm. */
// FUN_0026CEF0 NONMATCHING
#ifdef NON_MATCHING
f32 func_0026cef0(s8 *arg0, f32 fparg0, f32 *arg1, f32 *arg2,
                  f32 fparg1)
{
    struct Cef0Frame {
        f32 v80[4];
        f32 v90[4];
        f32 vA0[4];
        u8 padB0[8];
        f32 vB8;
        f32 vBC;
        f32 vC0;
        u8 padC4[4];
        f32 vC8;
        f32 vCC;
        f32 vD0;
        u8 padD4[4];
        f32 vD8;
        f32 vDC;
        f32 vE0;
        u8 padE4[4];
        f32 vE8[4];
        f32 vF8;
        f32 vFC;
        f32 v100;
        u8 pad104[4];
        f32 v108;
        f32 v10C;
        f32 v110;
        u8 pad114[4];
        f32 v118;
        f32 v11C;
        f32 v120;
        u8 pad124[4];
        f32 v128[6];
        f32 v140[6];
        f32 v158[6];
    } frame;
    f32 var_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f23;
    f32 temp_f0;
    f32 temp_f21_2;
    f32 temp_f3;
    f32 temp_f4;
    s32 var_17;
    s32 var_16;
    s32 var_5;
    s32 var_5_2;
    s8 temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;

    var_f23 = 0.0f;
    temp_3 = *arg0;
    temp_f21 = (1.0f / (f32)temp_3) / 20.0f;
    var_f20 = 0.0f;
    if (fparg1 <= fparg0) {
        u8 *base;
        base = (u8 *)arg0 + (temp_3 - 1) * 0x24;
        var_5 = 0;
        while (var_5 < 4) {
            temp_3_2 = base + var_5 * 0xC;
            frame.vA0[var_5] = *(f32 *)(temp_3_2 + 4);
            frame.v90[var_5] = *(f32 *)(temp_3_2 + 8);
            frame.v80[var_5] = *(f32 *)(temp_3_2 + 0xC);
            var_5 += 1;
        }
        func_0026c960(fGpffff82d4, frame.vA0, frame.v90, frame.v80, &frame.v158[5], &frame.v158[3], &frame.v158[1]);
        func_0026c960(1.0f, frame.vA0, frame.v90, frame.v80, &frame.v158[4], &frame.v158[2], &frame.v158[0]);
        frame.vD8 = frame.v158[4] - frame.v158[5];
        frame.vDC = frame.v158[2] - frame.v158[3];
        frame.vE0 = frame.v158[0] - frame.v158[1];
        func_003e4180(&frame.vD8);
        frame.v118 = frame.v158[4];
        frame.v11C = frame.v158[2];
        frame.v120 = frame.v158[0];
        arg1[0] = frame.v118;
        arg1[1] = frame.v11C;
        arg1[2] = frame.v120;
        frame.v108 = frame.v158[4] - frame.v158[5];
        frame.v10C = frame.v158[2] - frame.v158[3];
        frame.v110 = frame.v158[0] - frame.v158[1];
        func_003e40b0(frame.vE8, &frame.v108);
        func_0026c860(frame.vE8, arg2);
        return 1.0f;
    }
    var_17 = 0;
    while (var_17 < *arg0) {
        u8 *base2;
        base2 = (u8 *)arg0 + var_17 * 0x24;
        var_5_2 = 0;
        while (var_5_2 < 4) {
            temp_3_3 = base2 + var_5_2 * 0xC;
            frame.vA0[var_5_2] = *(f32 *)(temp_3_3 + 4);
            frame.v90[var_5_2] = *(f32 *)(temp_3_3 + 8);
            frame.v80[var_5_2] = *(f32 *)(temp_3_3 + 0xC);
            var_5_2 += 1;
        }
        var_16 = 0;
        while (var_16 < 0x14) {
            temp_f22 = (f32)var_16 * fGpffff83d0;
            func_0026c960(temp_f22, frame.vA0, frame.v90, frame.v80, &frame.v140[5], &frame.v140[3], &frame.v140[1]);
            func_0026c960((f32)(var_16 + 1) * fGpffff83d0, frame.vA0, frame.v90, frame.v80, &frame.v140[4], &frame.v140[2], &frame.v140[0]);
            frame.vC8 = frame.v140[4] - frame.v140[5];
            frame.vCC = frame.v140[2] - frame.v140[3];
            frame.vD0 = frame.v140[0] - frame.v140[1];
            temp_f0 = func_003e4180(&frame.vC8);
            frame.v118 = frame.v140[4];
            frame.v11C = frame.v140[2];
            frame.v120 = frame.v140[0];
            var_f23 += temp_f0;
            if (!(var_f23 < fparg0)) {
                temp_f4 = 1.0f - ((var_f23 - fparg0) / temp_f0);
                temp_f3 = temp_f21 * temp_f4;
                frame.v108 = frame.v140[4] - frame.v140[5];
                frame.v10C = frame.v140[2] - frame.v140[3];
                frame.v110 = frame.v140[0] - frame.v140[1];
                arg1[0] = frame.v108 * temp_f4 + frame.v140[5];
                arg1[1] = frame.v10C * temp_f4 + frame.v140[3];
                arg1[2] = frame.v110 * temp_f4 + frame.v140[1];
                temp_f21_2 = temp_f22 + temp_f3;
                func_0026c960(temp_f21_2, frame.vA0, frame.v90, frame.v80, &frame.v128[5], &frame.v128[3], &frame.v128[1]);
                func_0026c960(temp_f21_2 - fGpffff842c, frame.vA0, frame.v90, frame.v80, &frame.v128[4], &frame.v128[2], &frame.v128[0]);
                frame.vB8 = frame.v128[4] - frame.v128[5];
                frame.vBC = frame.v128[2] - frame.v128[3];
                frame.vC0 = frame.v128[0] - frame.v128[1];
                func_003e4180(&frame.vB8);
                frame.vF8 = frame.v128[5] - frame.v128[4];
                frame.vFC = frame.v128[3] - frame.v128[2];
                frame.v100 = frame.v128[1] - frame.v128[0];
                func_003e40b0(frame.vE8, &frame.vF8);
                func_0026c860(frame.vE8, arg2);
                return var_f20 + temp_f3;
            }
            var_f20 += temp_f21;
            var_16 += 1;
        }
        var_17 += 1;
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026cef0);
#endif
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 1
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
#pragma opt_propagation off
// FUN_0026DB60
s32 func_0026db60(void)
{
    s32 var_17;
    u8 *var_16;
    s32 temp_4;
    s32 temp_3;
    u8 *var_2;
    func_0026d440();
    var_17 = 1;
    goto outer_test;
outer_body:
    var_16 = func_001452b0(var_17);
    goto inner_test;
inner_body:
    func_0026a020(var_16);
    var_16 = *(u8 **)(var_16 + 0x138);
inner_test:
    if (var_16 != NULL) {
        goto inner_body;
    }
    var_17 += 1;
outer_test:
    if (var_17 < 0x16) {
        goto outer_body;
    }
    var_2 = func_001452b0(7);
    temp_3 = 1;
    goto second_test;
second_body:
    temp_4 = *(s32 *)(var_2 + 0x148);
    if (temp_4 == temp_3) {
        func_0026c310(var_2);
        goto second_exit;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
second_test:
    if (var_2 != NULL) {
        goto second_body;
    }
second_exit:
    return 0;
}
/* measured: closes opt_propagation off probe for func_0026db60. */
#pragma opt_propagation on
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 2
// FUN_0026DC30
void func_0026dc30(void)
{
    func_0026d810();
}

/* measured: opt_propagation off probe for func_0026dc50 float load scheduling. */
#pragma opt_propagation off
// FUN_0026DC50
s32 func_0026dc50(u8 **arg0, u8 **arg1)
{
    struct DC50Frame {
        f32 v40[3];
        u8 pad4C[0x24];
        f32 v70[3];
        u8 pad7C[4];
        f32 v80[3];
        u8 pad8C[0x24];
        f32 vB0[3];
        u8 padBC[4];
        f32 vC0[3];
        u8 padCC[4];
        f32 vD0[3];
        u8 padDC[4];
        f32 vE0[3];
        u8 padEC[4];
    } frame;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 *temp_B0;
    f32 *temp_70;
    f32 temp_c1;
    f32 temp_c2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = func_00457120();
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f0 = *(f32 *)(temp_2 + 0x30);
    temp_f2 = *(f32 *)(temp_2 + 0x34);
    temp_f1 = *(f32 *)(temp_2 + 0x38);
    frame.vC0[0] = temp_f0;
    frame.vC0[1] = temp_f2;
    frame.vC0[2] = temp_f1;
    temp_16 = *arg1;
    temp_2 = *arg0;
    func_004b1470(*(s32 *)(temp_2 + 0x144), frame.v80);
    func_004b1470(*(s32 *)(temp_16 + 0x144), frame.v40);
    temp_B0 = frame.vB0;
    temp_70 = frame.v70;
    frame.vE0[0] = temp_B0[0] - frame.vC0[0];
    temp_c1 = frame.vC0[1];
    frame.vE0[1] = temp_B0[1] - temp_c1;
    temp_c2 = frame.vC0[2];
    frame.vE0[2] = temp_B0[2] - temp_c2;
    frame.vD0[0] = temp_70[0] - frame.vC0[0];
    frame.vD0[1] = temp_70[1] - frame.vC0[1];
    frame.vD0[2] = temp_70[2] - frame.vC0[2];
    temp_f20 = func_003e4180(frame.vE0);
    return (s32)(temp_f20 - func_003e4180(frame.vD0));
}
/* measured: closes opt_propagation off probe for func_0026dc50. */
#pragma opt_propagation on
// FUN_0026DD60
void func_0026dd60(u8 *arg0)
{
    s32 output_index;
    u32 *result;
    s32 count;
    u8 *base;
    s32 index;

    count = 0;
    base = arg0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(arg0 + 0x28) & 2) {
        if (*(s32 *)(arg0 + 0x144) != 0) {
            switch (*(s8 *)(arg0 + 0x140)) {
            case 0:
                count += 1;
                break;
            }
        }
    }
loop_7_next:
    arg0 = *(u8 **)(arg0 + 0x138);
loop_7_test:
    if (arg0 != NULL) {
        goto loop_7_body;
    }
    if (count != 0) {
        func_0044ea90(D_0063B580, 0x96);
        result = (u32 *)jtbl_008873E8[0](count * 4, 0x40000);
        index = 0;
        arg0 = base;
        goto loop_16_test;
loop_16_body:
        if (*(s32 *)(arg0 + 0x28) & 2) {
            if (*(s32 *)(arg0 + 0x144) != 0) {
                switch (*(s8 *)(arg0 + 0x140)) {
                case 0:
                    result[index] = (u32)arg0;
                    index += 1;
                    break;
                }
            }
        }
loop_16_next:
        arg0 = *(u8 **)(arg0 + 0x138);
        goto loop_16_test;
loop_16_test:
        if (arg0 != NULL) {
            goto loop_16_body;
        }
        func_00440bb8(result, count, 4, func_0026dc50);
        output_index = 0;
        goto loop_19_test;
loop_19_body:
        func_004b11d0(D_005DC7D0,
                      *(s32 *)((u8 *)result[output_index] + 0x144));
        output_index += 1;
loop_19_test:
        if (output_index < count) {
            goto loop_19_body;
        }
        jtbl_008873EC[0]((u8 *)result);
    }
}
// FUN_0026DEE0
s32 func_0026dee0(void)
{
    s32 temp_5;
    s8 temp_3;
    u8 *var_16;

    var_16 = func_001452b0(6);
    func_0026dd60(var_16);
    goto loop_test;
loop_body:
    if (*(s32 *)(var_16 + 0x28) & 2) {
        temp_5 = *(s32 *)(var_16 + 0x144);
        if (temp_5 != 0) {
            temp_3 = *(s8 *)(var_16 + 0x140);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                func_004b11d0(D_005DC824, temp_5);
                break;
            }
        }
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_test:
    if (var_16 != NULL) {
        goto loop_body;
    }
    return 0;
}
// FUN_0026DF80
s32 func_0026df80(void)
{
    s32 temp_2;

    temp_2 = func_00451fc0(0, D_0063B5A0, 0x10, 0, 0,
                           (void (*)(void))func_0026db60, func_0026dc30, 0);
    func_00451fc0(temp_2, D_0063B5C0, 0x10, 0, 0,
                  (void (*)(void))func_0026dee0, NULL, 0);
    return temp_2;
}
/* Allocate a header and count+1 linked records, including the wrap record.
   measured: a u32 allocation base expresses the header as one word and
   gives retail's saved-register assignment without pragmas. Keep the
   pointer-value copy call and byte-stride helper. Exact 204B plus 4B zero tail. */
// FUN_0026E010
s32 func_0026e010(s32 size, s32 count)
{
    u8 *allocated;
    u32 *base;
    u32 *node;
    u32 *next;
    s32 i;

    func_0044ea90(D_0063B5D8, 0x36);
    allocated = jtbl_008873E8[0]((size + 8) * (count + 1) + 4, 0x40000);
    base = (u32 *)allocated;
    func_0043f810(base, &allocated, 4);
    node = base + 1;
    i = 0;
    while (i < count) {
        node[0] = i;
        next = func_0026e010_add_offset(size, node);
        node[1] = (u32)next;
        node = next;
        i++;
    }
    node[0] = count;
    node[1] = (u32)(base + 1);
    return (s32)(base + 1);
}
// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

/* measured: opt_propagation off probe for func_0026e4c0 field-load order. */
#pragma opt_propagation off
// FUN_0026E4C0
s32 func_0026e4c0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xD) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off probe for func_0026e4c0. */
#pragma opt_propagation on
// FUN_0026E560
s32 func_0026e560(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off forces func_0026e590 field-load order. */
#pragma opt_propagation off
// FUN_0026E590
s32 func_0026e590(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xC) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e590. */
#pragma opt_propagation on
/* measured: opt_propagation off forces func_0026e630 field-load order. */
#pragma opt_propagation off
// FUN_0026E630
s32 func_0026e630(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e630. */
#pragma opt_propagation on
// FUN_0026E6D0
s32 func_0026e6d0(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off preserves field-load order for func_0026e700. */
#pragma opt_propagation off
// FUN_0026E700
s32 func_0026e700(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s16 *)(arg1 + 0x1E) = (s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e700. */
#pragma opt_propagation on
/* measured: opt_common_subs off forces func_0026e7f0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves field-load order for func_0026e7f0. */
#pragma opt_propagation off
// FUN_0026E7F0
s32 func_0026e7f0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    s32 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_5;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_5 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() == 0) {
        goto success;
    }
    if (func_002746a0() != 1) {
        return 0;
    }
success:
    *(s32 *)arg1 = temp_4 << 4;
    *(s32 *)(arg1 + 4) = temp_5 << 3;
    return 0;
}
/* measured: closing opt_common_subs off for func_0026e7f0. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026e7f0. */
#pragma opt_propagation on
// FUN_0026E910
s32 func_0026e910(void)
{
    func_00274660(1, 1);
    return 1;
}
/* measured: opt_propagation off preserves decode and field-store order for func_0026e940. */
#pragma opt_propagation off
// FUN_0026E940
s32 func_0026e940(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    func_00274660(0x20, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e940. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ea50. */
#pragma opt_propagation off
// FUN_0026EA50
s32 func_0026ea50(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    s32 temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (func_00106330(0x3B) == 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (iGpffffa730 != 0) {
        goto direct_store;
    }
    temp_6 = func_00273970(*(u8 **)(arg1 + 0x14));
    temp_7 = temp_6 << 4;
    temp_6 = temp_7 - temp_6;
    temp_7 = temp_6 << 2;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = temp_7;
    goto after_store;
direct_store:
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
after_store:
    iGpffffa730 = -1;
    iGpffffb4bc = 1;
    func_00274660(0x10, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026ea50. */
#pragma opt_propagation on
// FUN_0026EBA0
s32 func_0026eba0(void)
{
    func_00274660(1, 1);
    func_00274660(2, 1);
    return 1;
}
/* measured: opt_propagation off preserves target scan preheader ordering. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on hoists the decode mask assignment to the target preheader. */
#pragma opt_loop_invariants on
// FUN_0026EBE0
s32 func_0026ebe0(s32 arg0, u8 *arg1)
{
    s32 temp_3;
    s32 var_16;
    s32 temp_3_5;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_6;
    u8 *temp_3_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_16 = 0;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_5 + temp_3_4);
    goto scan_loop;
decode:
    if ((temp_3_2 & 0xF0) == (temp_3_6 = 0xF0)) {
        var_16 += (((temp_3_2 & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)temp_3_2 < 0x80U) {
        goto scan_loop;
    }
    var_16 += 1;
    goto scan_loop;
scan_loop:
    temp_3 = var_16;
    var_16 += 1;
    temp_3_2 = *(s8 *)(temp_3_3 + temp_3);
    temp_3_5 = 0xA;
    if (temp_3_2 != temp_3_5) {
        goto decode;
    }
    func_0043f9c8(&D_00881530, 0, 0x80);
    func_0043f810(&D_00881530,
                  (void *)(*(s32 *)(arg1 + 0x10) + *(s32 *)(arg1 + 0x18)),
                  var_16);
    *((u8 *)((s32)&D_0088152F + var_16)) = 0;
    func_00274660(4, 1);
    *(s32 *)(arg1 + 0x18) = *(s32 *)(arg1 + 0x18) + var_16;
    return 0;
}
/* measured: closes the opt_loop_invariants and opt_propagation probes at the file baseline. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ed00. */
#pragma opt_propagation off
// FUN_0026ED00
s32 func_0026ed00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (func_00106330(0x3A) == 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = 0x23;
    } else {
        temp_3_4 = *(s32 *)(arg1 + 0x18);
        temp_3_5 = *(s32 *)(arg1 + 0x10);
        temp_3 = (u8 *)(temp_3_5 + temp_3_4);
        temp_3_3 = (temp_3[0] - 1) & 0xFF;
        temp_3_2 = temp_3[1];
        if (temp_3_2 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3_2 - 1) & 0xFF;
        }
        var_2 &= 0xFF;
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) =
            (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    }
    return 0;
}
/* measured: closing opt_propagation off for func_0026ed00. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ee00. */
#pragma opt_propagation off
// FUN_0026EE00
s32 func_0026ee00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    return 0;
}
/* measured: closing opt_propagation off for func_0026ee00. */
#pragma opt_propagation on
// FUN_0026EF00
s32 func_0026ef00(s32 arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    *(s8 *)(arg1 + 0xF) = 0x14;
    *(s16 *)(arg1 + 0x1E) = 0x20;
    iGpffffb4bc = 0;
    return 0;
}
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026ef60. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026ef60. */
#pragma opt_propagation off
// FUN_0026EF60
s32 func_0026ef60(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    func_00106390(temp_18 + sp30[temp_17], 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026ef60. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026ef60. */
#pragma opt_common_subs on
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026f0a0. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026f0a0. */
#pragma opt_propagation off
// FUN_0026F0A0
s32 func_0026f0a0(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    func_00106390(temp_18 + sp30[temp_17], 0);
    return 0;
}
/* measured: closing opt_propagation off for func_0026f0a0. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026f0a0. */
#pragma opt_common_subs on
// FUN_0026F1E0
s32 func_0026f1e0(s32 arg0, u32 arg1, s32 arg2)
{
    s32 temp_16;
    s32 temp_4;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *self;

    self = (u8 *)arg1;
    temp_3_4 = *(s32 *)(self + 0x18);
    temp_3_5 = *(s32 *)(self + 0x10);
    temp_3 = func_0026f1e0_add((u8 *)temp_3_5, (u32)temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (u16)(s16)((var_2 << 8) | (u8)temp_4);
    temp_16 &= 0xFFFF;
    if (func_002746a0() != 0) {
        return 0;
    }
    if (D_008815B0[temp_16 & 0xFFFF] != 0) {
        func_00273f70(self);
        func_002739e0(temp_16 & 0xFF, self);
    }
    return 0;
}
// FUN_0026F2C0
/* measured: MWCCPS2 b210 -O2, 724B/window 736B, 16 relocations,
 * 12 zero alignment bytes. Ghidra/IDA and retail agree on the three-byte
 * glyph at sp+0x68: align the real buffer to eight, without enlarging it.
 * The scoped options preserve operand reloads and decode scheduling. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0026f2c0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s64 third;
    s32 *slot;
    u8 previous_character;
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;
    s32 character_code;
    s8 glyph[3] __attribute__((aligned(8)));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = func_0026f1e0_add((u8 *)stream_base, (u32)stream_offset);
    low = (stream[0] - 1) & 0xFF;
    high_byte = stream[1];
    if (high_byte == 0xFF) {
        high_first = 0;
    } else {
        high_first = (high_byte - 1) & 0xFF;
    }
    first = (u16)(s16)(((high_first & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[2] - 1) & 0xFF;
    high_byte = stream[3];
    if (high_byte == 0xFF) {
        high_second = 0;
    } else {
        high_second = (high_byte - 1) & 0xFF;
    }
    second = (u16)(s16)(((high_second & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[4] - 1) & 0xFF;
    high_byte = stream[5];
    if (high_byte == 0xFF) {
        high_third = 0;
    } else {
        high_third = (high_byte - 1) & 0xFF;
    }
    third = (u16)(s16)(((high_third & 0xFF) << 8) | (low & 0xFF));

    if (func_002746a0() != 0) {
        return 0;
    }
    slot = &D_008815B0[(u16)third];
    if (*slot != 0) {
        previous_character = arg1[0xD];
        /* Retail compares a zero-extended halfword with signed -1. */
        if ((first & 0xFFFF) != -1) {
            arg1[0xD] = first;
        }
        character_code = second & 0xFFFF;
        if (character_code != 0xFFFF) {
            glyph[0] = -0x7D;
            glyph[1] = character_code + 0xC7;
            glyph[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)glyph, arg1);
            func_00273f70(arg1);
            func_002739e0((u8)third, arg1);
            arg1[0xD] = previous_character;
        } else {
            third = *(s32 *)*slot;
            switch (func_0026e360(third)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 9:
            case 11:
                force_character = 1;
                break;
            default:
                force_character = 0;
                break;
            }
            if (force_character != 0) {
                arg1[0xD] = 4;
            }
            glyph[0] = -0x7D;
            glyph[1] = func_0026e360(third) + 0xC7;
            glyph[2] = 0;
            func_00273f70(arg1);
            func_00273cc0((u8 *)glyph, arg1);
            func_00273f70(arg1);
            func_00273cc0((u8 *)func_001067f0((s16)third), arg1);
            arg1[0xD] = previous_character;
        }
    }
    return 0;
}
#pragma pop
/* measured: optimization_level 0 probe for the retail redundant return branch. */
#pragma optimization_level 0
// FUN_0026F5A0
s32 func_0026f5a0(void)
{
    if (func_002746a0() != 2) {
        return 0;
    }
    return 0;
}
/* measured: closes optimization_level 0 around func_0026f5a0. */
#pragma optimization_level 2
/* measured: opt_common_subs off preserves the per-decode pointer recompute for func_0026f5e0. */
/* measured: opt_propagation off preserves the byte-decode temporary liveness for func_0026f5e0. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_0026F5E0
s32 func_0026f5e0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 sp20[5];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_2;
    s32 *src;
    s32 *dst;
    s32 i;
    u8 *temp_3;

    if (func_002746a0() != 3) {
        return 0;
    }

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    switch (first) {
    case 0:
        src = (s32 *)&D_0063BA30[0];
        dst = &sp20[0];
        i = 5;
        do {
            temp_2 = *src;
            src += 1;
            i -= 1;
            *dst = temp_2;
            dst += 1;
        } while (i > 0);
        func_00106390(third + sp20[second], fourth);
        break;
    case 1:
        if (fourth != 0) {
            func_00107ce0(func_00108e10());
        } else {
            func_00107dc0(func_00108e10());
        }
        break;
    case 2:
    case 3:
        func_00108290(func_00108e10(), fourth & 0xFFFF);
        break;
    case 6:
    default:
        break;
    }
    return 0;
}
/* measured: closing opt_common_subs off for func_0026f5e0. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026f5e0. */
#pragma opt_propagation on
#pragma pop
/* measured: MWCCPS2 b210 -O2, 832B/window 832B, 16 relocations.
 * Ghidra gives the descending dispatch; IDA gives the 64-byte path buffer.
 * Named action/channel values survive their comparisons into case one.
 * The final switch preserves retail's explicit zero/default branches.
 * The sound provider narrows the fourth operand at its halfword store. */
// FUN_0026F860
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0026f860(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s8 sp50[0x40];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 action;
    s32 channel;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    iGpffffa730 = -1;
    if (func_002746a0() == 0) {
        if (first == 1) {
            iGpffffa730 = fourth;
        }
    }
    if (func_002746a0() != 1) {
        return 0;
    }
    if (func_00106330(0x3A) == 0) {
        return 0;
    }

    if (first == 4) goto L4;
    if (first == 3) goto L3;
    action = 2;
    if (first == action) goto L2;
    channel = 1;
    if (first == channel) goto L1;
    switch (first) {
    case 0:
        goto L0;
    default:
        goto Lend;
    }

L0:
    if ((second >= 0) && (second < 0x191)) {
        func_00442088((char *)sp50, D_0063BA50, second, third, second, third, fourth);
    } else if ((second >= 0x191) && (second < 0x1F5)) {
        func_00442088((char *)sp50, D_0063BA80, second, third / 0x14, second, third, fourth);
    }
    func_0045aeb0(1, (const char *)sp50);
    goto Lend;

L1:
    if (fourth != 0) {
        func_0045ae10(action, channel, fourth);
    }
    goto Lend;

L2:
    func_0045ae10(third, 1, fourth);
    goto Lend;

L3:
    func_0045ae10(third, 1, fourth);
    goto Lend;

L4:
    func_0045ae10(third, 1, fourth);
    goto Lend;

Lend:
    return 0;
}
#pragma pop
// FUN_0026FBA0
s32 func_0026fba0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088((char *)sp20, (const char *)&iGpffffa734, func_0010d660(1));
    func_00273f70(arg1);
    func_00273cc0((u8 *)sp20, arg1);
    return 0;
}
// FUN_0026FC20
s32 func_0026fc20(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088((char *)sp20, (const char *)&iGpffffa734, func_0010d6d0(1));
    func_00273f70(arg1);
    func_00273cc0((u8 *)sp20, arg1);
    return 0;
}
// FUN_0026FCA0
s32 func_0026fca0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x23];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088((char *)sp20, (const char *)&iGpffffa734, func_0010d6d0(1));
    func_00273f70(arg1);
    func_00273cc0((u8 *)sp20, arg1);
    sp20[0] = -0x7D;
    sp20[1] = -0xA;
    sp20[2] = 0;
    func_00273f70(arg1);
    func_00273cc0((u8 *)sp20, arg1);
    func_00442088((char *)sp20, (const char *)&iGpffffa734, func_0010d660(1));
    func_00273f70(arg1);
    func_00273cc0((u8 *)sp20, arg1);
    return 0;
}
// FUN_0026FD90
/* measured: MWCCPS2 b210 -O2, 596B/window 608B, 10 relocations,
 * 12 zero alignment bytes. Ghidra/IDA and retail agree on the three-byte
 * glyph at sp+0x68: align the real buffer to eight, without enlarging it.
 * The scoped options preserve operand reloads and decode scheduling. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_0026fd90(s32 arg0, u8 *arg1)
{
    u8 previous_character;
    s32 first;
    s64 second;
    s32 third;
    s8 glyph[3] __attribute__((aligned(8)));
    s32 stream_offset;
    s32 stream_base;
    u8 *stream;
    s32 low;
    s32 high_byte;
    s32 high_first;
    s32 high_second;
    s32 high_third;
    s32 force_character;
    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = func_0026f1e0_add((u8 *)stream_base, (u32)stream_offset);
    low = (stream[0] - 1) & 0xFF;
    high_byte = stream[1];
    if (high_byte == 0xFF) {
        high_first = 0;
    } else {
        high_first = (high_byte - 1) & 0xFF;
    }
    first = (u16)(s16)(((high_first & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[2] - 1) & 0xFF;
    high_byte = stream[3];
    if (high_byte == 0xFF) {
        high_second = 0;
    } else {
        high_second = (high_byte - 1) & 0xFF;
    }
    second = (u16)(s16)(((high_second & 0xFF) << 8) | (low & 0xFF));

    stream_offset = *(s32 *)(arg1 + 0x18);
    stream_base = *(s32 *)(arg1 + 0x10);
    stream = (u8 *)((u32)stream_offset + (u32)stream_base);
    low = (stream[4] - 1) & 0xFF;
    high_byte = stream[5];
    if (high_byte == 0xFF) {
        high_third = 0;
    } else {
        high_third = (high_byte - 1) & 0xFF;
    }
    third = (u16)(s16)(((high_third & 0xFF) << 8) | (low & 0xFF));

    if (func_002746a0() != 0) {
        return 0;
    }
    if ((first & 0xFFFF) != -1) {
        previous_character = arg1[0xD];
        arg1[0xD] = first;
    }
    if ((u16)second != 0) {
        second = (u16)third;
        switch (func_0026e360(second)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
        case 11:
            force_character = 1;
            break;
        default:
            force_character = 0;
            break;
        }
        if (force_character != 0) {
            arg1[0xD] = 4;
        }
        glyph[0] = -0x7D;
        glyph[1] = func_0026e360(second) + 0xC7;
        glyph[2] = 0;
        func_00273f70(arg1);
        func_00273cc0((u8 *)glyph, arg1);
    }
    func_00273f70(arg1);
    func_00273cc0((u8 *)func_001067f0((s16)third), arg1);
    arg1[0xD] = previous_character;
    return 0;
}
#pragma pop
/* measured: opt_common_subs off forces func_0026fff0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fff0 decode scheduling. */
#pragma opt_propagation off
// FUN_0026FFF0
s32 func_0026fff0(s32 arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_2;
    s32 temp_3_4b;
    u8 *temp_3;
    u8 *temp_3_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (s32)(s16)((var_2 << 8) | (u8)temp_4);
    temp_3_6 = *(s32 *)(arg1 + 0x18);
    temp_3_7 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_6 + temp_3_7);
    temp_4 = (temp_3_3[2] - 1) & 0xFF;
    temp_3_4b = temp_3_3[3];
    if ((u8)temp_3_4b == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_4b - 1) & 0xFF;
    }
    var_2_2 &= 0xFF;
    temp_17 = (s32)(s16)((var_2_2 << 8) | (u8)temp_4);
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00106620((s16)temp_16, temp_17 & 0xFF);
    return 0;
}
/* measured: closing opt_propagation off for func_0026fff0. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026fff0. */
#pragma opt_common_subs on

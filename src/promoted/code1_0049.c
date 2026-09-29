#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void (*D_00713E70[])(u8 *object);
extern void (*D_00713E78[])(u8 *object);
extern void (*D_00713E7C[])(u8 *object);
extern void (*D_00713E80[])(u8 *object);
extern void (*D_00713F18[])(void *state);
extern void (*D_00713F10[])(u8 *object);
extern void (*D_00713F1C[])(u8 *object);
extern void (*D_00713F20[])(u8 *object);
extern void (*D_00713D54[])(u8 *emitter, f32 scale);
extern u32 effMiscRand(u32 arg0);
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void memcpy(void *dst, const void *src, u32 size);
extern void func_0046d730(const void *file, s32 line);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;

extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

extern void func_004841c0(void *arg0);
extern void func_0048a1f0(u8 *arg0);

extern void func_00484280(u8 *object, s32 resource);



// FUN_00490360
void func_00490360(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490360_check;
loop_00490360_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490360_check:
    if (var_7 < 3U) {
        goto loop_00490360_body;
    }
}
/* Floor v3 (measured 2026-09-18, authoritative tree): probe_variants 465 words with opt_loop_invariants on */
/* (bare v2 494; v1 492), obj 514 vs retail 508 instrs (6 over, 1.2% over, banks per 3% rule 493-523); */
/* fnalign 344 edits (bare v2 405, v1 477), frame/values/CFG per retail; VU normalize + scale blocks as */
/* genuine VU0 inline asm (each <=5 ordinary vs >=5 hardware, H009-clean); COP1 lerp/add/sub/cvt stays plain C */
/* with (f32)(u32) casts per 7a-quinquies. Re-measured commands (pwd source/Persona4-Decompilation): */
/* python3 -E -s tools/pragma_sweep.py src/promoted/code1_0049.c func_004903c0 (singles: loopinv 465 wins) */
/* python3 -E -s tools/probe_variants.py src/promoted/code1_0049.c func_004903c0 --candidate loopinv=/tmp/cand_loopinv.c */
/* python3 -E -s tools/fnalign.py src/promoted/code1_0049.c func_004903c0 --candidate /tmp/cand_loopinv.c --quiet */
/* python3 tools/measure_guarded.py src/promoted/code1_0049.c func_004903c0 (after install) */
/* Bare v2 (/var/tmp/cold4903c0/cand_v2.c): 494w 522 instrs 405ed, fixes out[1] writeback + nodes+4 check, drops */
/* dummy qmfc2/prot3w. Bare v1 (/var/tmp/cold4903c0/cand_v1.c): 492w 523 instrs 477ed (missing store). */
/* Other cold in this owner still ASM, NOT claimed here: func_00490c40, func_004916f0, func_00492100, func_00494740. */
// FUN_004903C0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_004903c0(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    u_long128 b220buf;
    f32 vec110[4] __attribute__((aligned(16)));
    f32 vec120[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 vE8;
    f32 vF4;
    f32 vE4;
    f32 vD8;
    s32 v15;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    vE8 = *(f32 *)(config + 232);
    vF4 = *(f32 *)(config + 244);
    vE4 = *(f32 *)(config + 228);
    vD8 = *(f32 *)(config + 216);
    idx = 0;
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (*(u8 *)(config + 189) == 0)) {
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        goto main_check;
    } else {
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    effMiscRandFloat(0);
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 208) * ((1.0f - a) + a * b);
    vec120[0] = c * (2.0f * (effMiscRandFloat(0) - 0.5f));
    vec120[1] = -(1.0f - c);
    vec120[2] = c * (2.0f * (effMiscRandFloat(0) - 0.5f));
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec120) : "r"(vec120) : "$vf10", "memory");
    out[0] = vec120[0];
    out[1] = vec120[1];
    out[2] = vec120[2];
    a = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    out[3] = *(f32 *)(config + 220) * ((1.0f - a) + a * b);
    if (out[3] < 0.0f) {
        out[3] = -out[3];
    }
    a = *(f32 *)(config + 240);
    b = effMiscRandFloat(0);
    out[4] = -*(f32 *)(config + 236) * ((1.0f - a) + a * b);
    a = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec110[0] = *(f32 *)(config + 200) * ((1.0f - a) + a * b);
    vec110[1] = vec110[0];
    vec110[2] = vec110[0];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    if (*(f32 *)(config + 220) < 0.0f) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec110), "m"(*(u_long128 *)vec110) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec110), "m"(*(u_long128 *)vec110) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[5] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[6] = 0.0f;
        out[7] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[7] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[6] = fGpffff8080 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[7] = out[7] * -1.0f;
            }
        } else {
            out[6] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    func_0048b220(nodes, config, 0, (u_long128 *)nodes);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[5];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[7];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[6];
    v15 -= 1;
    goto next_iter;
else_branch:
    b220buf = *(u_long128 *)nodes;
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
    ftmp1 = out[3] + vE4 * (f32)node10;
    if (ftmp1 < 0.0f) {
        ftmp1 = 0.0f;
    }
    out[1] = out[1] - vE8;
    vec120[0] = ftmp1 * out[0];
    vec120[1] = out[1];
    vec120[2] = ftmp1 * out[2];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    if (*(f32 *)(nodes + 4) < vD8) {
        out[4] = out[4] * vF4;
        out[1] = out[1] * out[4];
        *(f32 *)(nodes + 4) = vD8 + out[4] * (*(f32 *)(nodes + 4) - vD8);
    }
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[5];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[7];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[6];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter:
    idx += 1;
    out += 8;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004903c0);
#endif
// FUN_00490BB0
void func_00490bb0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490bb0_check;
loop_00490bb0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490bb0_check:
    if (var_7 < 3U) {
        goto loop_00490bb0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xE8) = *(f32 *)(temp_5 + 0xE8) * fparg0;
}
/* Floor v1 (measured 2026-09-18, authoritative tree): probe_variants 533 words with opt_loop_invariants on */
/* (bare v1 628), obj 645 vs retail 646 instrs (1 short, 0.2% short, banks per 3% rule 627-665); */
/* fnalign 423 edits, frame/values/CFG per retail; VU normalize/scale/dot/vsqrt blocks as */
/* genuine VU0 inline asm (each <=5 ordinary vs >=5 hardware, H009-clean); COP1 lerp/add/sub/div/cvt stays plain C */
/* with (f32)(u32) casts per 7a-quinquies. Re-measured commands (pwd source/Persona4-Decompilation): */
/* python3 -E -s tools/pragma_sweep.py src/promoted/code1_0049.c func_00490c40 (singles: loopinv 533 wins, lvl3/4 600, prop-off 609, sched 617) */
/* python3 -E -s tools/probe_variants.py src/promoted/code1_0049.c func_00490c40 --candidate loopinv=/tmp/cand_loopinv_490c40.c */
/* python3 -E -s tools/fnalign.py src/promoted/code1_0049.c func_00490c40 --candidate /tmp/cand_loopinv_490c40.c --quiet */
/* python3 tools/measure_guarded.py src/promoted/code1_0049.c func_00490c40 (after install) */
/* Decompilers (into /var/tmp/cold490c40/): m2c src/promoted/code1_0049.c func_00490c40 -o m2c.c (322 lines, VU as M2C_ERROR); */
/* romwright --raw -o rw_raw.c (457 lines, p-code VU intrinsics) + -o rw.c (503 lines, m2c-shaped) + --types (float, 576 instrs). Counted 648 retail first. */
/* Other cold in this owner still ASM, NOT claimed here: func_004903c0, func_004916f0, func_00492100, func_00494740. */
// FUN_00490C40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00490c40(u8 *arg0)
{
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8088;
    extern f32 fGpffff808c;
    extern u_long128 D_00922D70;
    u_long128 b220buf;
    u_long128 baseQuad;
    f32 vec110[4] __attribute__((aligned(16)));
    f32 vec120[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    s32 divD8;
    u8 mode9C;
    f32 vE4;
    f32 one;
    s32 v15;
    s32 flagBD;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    f32 temp;
    f32 ftmp;
    f32 clipF;
    f32 dot;
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    if ((flags & 1) == 0) {
        baseQuad = *(u_long128 *)config;
    } else {
        baseQuad = D_00922D70;
    }
    saved20 = *(s32 *)(config + 32);
    divD8 = *(s32 *)(config + 216);
    mode9C = *(u8 *)(config + 156);
    vE4 = *(f32 *)(config + 228);
    one = 1.0f;
    idx = 0;
    vec120[3] = 0.0f;
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        flagBD = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (*(u8 *)(config + 189) == 0)) {
        flagBD = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        goto main_check;
    } else {
        flagBD = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    vec120[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[1] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec120) : "r"(vec120) : "$vf10", "memory");
    out[0] = vec120[0];
    out[1] = vec120[1];
    out[2] = vec120[2];
    a = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    c = (one - a) + a * b;
    out[5] = *(f32 *)(config + 220) * c;
    if (out[5] < 0.0f) {
        out[5] = -out[5];
    }
    a = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    c = (one - a) + a * b;
    out[3] = *(f32 *)(config + 200) * c;
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    c = (one - a) + a * b;
    temp = *(f32 *)(config + 208) * c;
    out[4] = (temp - out[3]) / (f32)divD8;
    if (flagBD != 0) {
        tmp = (s32)((u32)effMiscRand(0) % (u32)limitB8);
        *(s32 *)(nodes + 16) = tmp;
        ftmp1 = out[4];
        a = out[3] + ftmp1 * (f32)tmp;
        out[3] = a;
        if ((out[4] > 0.0f && out[3] > temp) || (out[4] < 0.0f && out[3] < temp)) {
            out[3] = temp;
        }
    } else {
        *(s32 *)(nodes + 16) = 0;
    }
    vec120[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[1] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    {
        u32 bits;
        __asm__ volatile("mfc1 %0, %1" : "=r"(bits) : "f"(out[3]));
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(bits) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "$vf2", "memory");
    }
    if ((flags & 1) == 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&baseQuad), "m"(baseQuad) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[6] = (one - a) + a * b;
    if (mode9C == 2) {
        out[7] = 0.0f;
        out[8] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[8] = (one - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[7] = fGpffff8080 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[8] = out[8] * -1.0f;
            }
        } else {
            out[7] = 0.0f;
        }
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), (u_long128 *)nodes);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
    if (flagBD != 0) {
        c0 = *(s32 *)(config + 192);
        c4 = *(s32 *)(config + 196);
        nmult = c0 * c4;
        if (nmult != 0) {
            clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = out[3];
    if (node10 < divD8) {
        out[3] = ftmp1 + out[4];
    }
    ftmp = out[5] + vE4 * (f32)node10;
    if (ftmp < 0.0f) {
        ftmp = 0.0f;
    }
    vec120[0] = out[0];
    vec120[1] = out[1];
    vec120[2] = out[2];
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf12", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    {
        u32 bits;
        __asm__ volatile("mfc1 %0, %1" : "=r"(bits) : "f"(ftmp));
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(bits) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "$vf2", "memory");
    }
    __asm__ volatile("vadd.xyzw $vf11, $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&baseQuad), "m"(baseQuad) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        ".word 0x4A0203BD \n"
        "vwaitq \n"
        : : : "$vf2", "$vf10", "$vf11", "memory");
    {
        f32 tmpF;
        __asm__ volatile(
            "cfc2 $2, $vi22 \n"
            "mtc1 $2, %0 \n"
            : "=f"(tmpF) : : "$2", "memory");
        clipF = tmpF;
    }
    if (clipF <= ftmp1) {
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(nodes) : "$vf11", "memory");
    } else {
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10 \n"
            "vmulax.w $ACC, $vf0, $vf2x \n"
            "vmadday.w $ACC, $vf0, $vf2y \n"
            "vmaddz.w $vf2, $vf0, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf10, $vf10, $Q \n"
            : : : "$vf2", "$vf10", "ACC", "Q", "memory");
        __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf11 \n"
            "vaddy.x $vf2, $vf2, $vf2y \n"
            "vaddz.x $vf2, $vf2, $vf2z \n"
            : : : "$vf2", "$vf10", "$vf11", "memory");
        {
            u32 bits;
            __asm__ volatile("qmfc2 $2, $vf2 \n mtc1 $2, %0" : "=f"(dot) : : "$2", "$vf2", "memory");
        }
        b = effMiscRandFloat(0);
        c = fGpffff808c + fGpffff8088 * b;
        c = dot * c * 2.0f;
        {
            u32 bits;
            __asm__ volatile("mfc1 %0, %1" : "=r"(bits) : "f"(c));
            __asm__ volatile("qmtc2 %0, $vf2" : : "r"(bits) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "$vf2", "memory");
        }
        __asm__ volatile("vsub.xyzw $vf11, $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(vec110) : "$vf11", "memory");
        out[0] = vec110[0];
        out[1] = vec110[1];
        out[2] = vec110[2];
        ftmp1 = clipF - ftmp1;
        ftmp2 = ftmp - ftmp1;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf10", "memory");
        {
            u32 bits;
            __asm__ volatile("mfc1 %0, %1" : "=r"(bits) : "f"(ftmp2));
            __asm__ volatile("qmtc2 %0, $vf2" : : "r"(bits) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf12, $vf12, $vf2x" : : : "$vf12", "$vf2", "memory");
        }
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
        {
            u32 bits;
            __asm__ volatile("mfc1 %0, %1" : "=r"(bits) : "f"(ftmp1));
            __asm__ volatile("qmtc2 %0, $vf2" : : "r"(bits) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
        }
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
    }
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter:
    idx += 1;
    out += 9;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00490c40);
#endif
// FUN_00491660
void func_00491660(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00491660_check;
loop_00491660_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00491660_check:
    if (var_7 < 3U) {
        goto loop_00491660_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
/* Floor v1 (measured 2026-09-18, authoritative tree): probe_variants 549 words bare (loopinv 550, neutral); obj 606 vs retail 609 instrs (3 short, 0.5% short, banks per 3% rule 591-627); */
/* fnalign 467 edits, frame/values/CFG per retail; VU matrix blocks as genuine VU0 inline asm (each <=5 ordinary vs >=5 hardware, H009-clean); COP1 lerp/sin/cos/add/sub/div/cvt stays plain C */
/* with (f32)(u32) casts per 7a-quinquies. Re-measured commands (pwd source/Persona4-Decompilation): */
/* python3 -E -s tools/pragma_sweep.py src/promoted/code1_0049.c func_004916f0 (singles: bare 549 wins, dead-off/strength-off/unroll-off 549 tie, loopinv 550, prop-off 571, peephole 573, lvl3/4 574, sched 577, lvl1 587, common-off 588, lvl0 611) */
/* python3 -E -s tools/probe_variants.py src/promoted/code1_0049.c func_004916f0 --candidate v1=/var/tmp/cold4916f0/cand_v1.c */
/* python3 -E -s tools/fnalign.py src/promoted/code1_0049.c func_004916f0 --candidate /var/tmp/cold4916f0/cand_v1.c --quiet */
/* python3 tools/measure_guarded.py src/promoted/code1_0049.c func_004916f0 (after install) */
/* Decompilers (into /var/tmp/cold4916f0/): m2c src/promoted/code1_0049.c func_004916f0 -o m2c.c (306 lines, VU as M2C_ERROR); */
/* romwright --raw -o rw_raw.c (390 lines, p-code VU intrinsics) + -o rw.c (432 lines, m2c-shaped) + --types (4 args, float return, 537 instrs). Counted 609 retail first. */
/* Other cold in this owner still ASM, NOT claimed here: func_00490c40. */
// FUN_004916F0 NONMATCHING
#ifdef NON_MATCHING
void func_004916f0(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    u_long128 b220buf;
    f32 vec110[4] __attribute__((aligned(16)));
    f32 vec120[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 vD8;
    f32 vDC;
    f32 g84;
    f32 g80;
    f32 one;
    f32 half;
    s32 v15;
    s32 flagBD;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 aD4;
    f32 b;
    f32 c;
    f32 f27;
    f32 s25;
    f32 c25;
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    vDC = *(f32 *)(config + 220);
    vD8 = *(f32 *)(config + 216);
    g84 = fGpffff8084;
    g80 = fGpffff8080;
    one = 1.0f;
    half = 0.5f;
    idx = 0;
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        flagBD = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (*(u8 *)(config + 189) == 0)) {
        flagBD = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        goto main_check;
    } else {
        flagBD = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    a = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    f27 = (g84 * a) * b + half * (g84 * (one - a));
    s25 = sinf(f27);
    a = *(f32 *)(config + 200);
    b = *(f32 *)(config + 204);
    out[0] = a * s25;
    out[1] = (b * s25 - a * s25) / (f32)limitB8;
    if ((*(u8 *)(config + 228) == 0) || ((idx & 1) != 0)) {
        aD4 = *(f32 *)(config + 212);
        b = effMiscRandFloat(0);
        out[2] = *(f32 *)(config + 208) * ((one - aD4) + aD4 * b);
    } else {
        aD4 = *(f32 *)(config + 212);
        b = effMiscRandFloat(0);
        out[2] = -*(f32 *)(config + 208) * ((one - aD4) + aD4 * b);
    }
    b = effMiscRandFloat(0);
    out[3] = g80 * b;
    c25 = cosf(f27);
    a = *(f32 *)(config + 200);
    b = *(f32 *)(config + 204);
    out[4] = a * c25;
    out[5] = (b * c25 - a * c25) / (f32)limitB8;
    ftmp1 = out[0];
    vec120[0] = ftmp1 * cosf(out[3]);
    vec120[1] = out[4];
    vec120[2] = ftmp1 * sinf(out[3]);
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[6] = (one - a) + a * b;
    if (mode9C == 2) {
        out[7] = 0.0f;
        out[8] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[8] = (one - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[7] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[8] = out[8] * -1.0f;
            }
        } else {
            out[7] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (flagBD != 0) {
        tmp = (s32)((u32)effMiscRand(0) % (u32)limitB8);
        ftmp1 = (f32)(u32)tmp;
        out[4] = out[4] - half * (vDC * ftmp1) * ftmp1;
        out[0] = out[0] + out[1] * ftmp1;
        ftmp1 = out[0];
        vec110[0] = ftmp1 * cosf(out[3]);
        vec110[1] = out[4];
        vec110[2] = ftmp1 * sinf(out[3]);
        vec110[3] = 0.0f;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec110), "m"(*(u_long128 *)vec110) : "$vf10", "memory");
        if ((flags & 1) == 0) {
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
                : : : "$vf10", "ACC", "memory");
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = tmp;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
    if (flagBD != 0) {
        c0 = *(s32 *)(config + 192);
        c4 = *(s32 *)(config + 196);
        nmult = c0 * c4;
        if (nmult != 0) {
            clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = (f32)node10;
    if ((*(u8 *)(config + 228) == 0) || ((idx & 1) != 0)) {
        ftmp2 = vD8 * ftmp1 * half + out[2];
    } else {
        ftmp2 = out[2] - vD8 * ftmp1 * half;
    }
    c = ftmp1 * ftmp2 + out[3];
    out[4] = out[4] - vDC * ftmp1;
    out[0] = out[0] + out[1];
    out[4] = out[4] + out[5];
    ftmp1 = out[0];
    vec120[0] = ftmp1 * cosf(c);
    vec120[1] = out[4];
    vec120[2] = ftmp1 * sinf(c);
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter:
    idx += 1;
    out += 9;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004916f0);
#endif
// FUN_00492080
void func_00492080(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492080_check;
loop_00492080_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492080_check:
    if (var_7 < 3U) {
        goto loop_00492080_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}
/* Floor v1 (measured 2026-09-18, authoritative tree): probe_variants 543 words with opt_loop_invariants on */
/* (bare v2 592), obj 606 vs retail 606 instrs (exact, banks per 3% rule 588-624); window 2432B (608 words, .size 0x980); */
/* fnalign 392 edits (bare 472), frame/values/CFG per retail; VU matrix/normalize/scale blocks as */
/* genuine VU0 inline asm (each <=5 ordinary vs >=5 hardware, H009-clean); COP1 lerp/add/sub/div/cvt stays plain C */
/* with (f32)(u32) casts per 7a-quinquies. Re-measured commands (pwd source/Persona4-Decompilation): */
/* python3 -E -s tools/pragma_sweep.py src/promoted/code1_0049.c func_00492100 (singles: loopinv 543 wins, sched 572, prop-off 559, lvl3/4 553) */
/* python3 -E -s tools/probe_variants.py src/promoted/code1_0049.c func_00492100 --candidate loopinv=/tmp/cand_loopinv_492100.c */
/* python3 -E -s tools/fnalign.py src/promoted/code1_0049.c func_00492100 --candidate /tmp/cand_loopinv_492100.c --quiet */
/* python3 tools/measure_guarded.py src/promoted/code1_0049.c func_00492100 (after install) */
/* Decompilers (into /var/tmp/cold492100/): m2c src/promoted/code1_0049.c func_00492100 -o m2c.c (312 lines, VU as M2C_ERROR); */
/* romwright --raw -o rw_raw.c (516 lines, p-code VU intrinsics) + --types (4 args? float return, 542 instrs). Counted 608 retail first. */
/* Other cold in this owner still ASM, NOT claimed here: func_00490c40, func_004916f0. */
// FUN_00492100 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00492100(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 sinf(f32 arg0);
    extern u_long128 D_00713D40;
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    u_long128 b220buf;
    f32 vec110[4] __attribute__((aligned(16)));
    f32 vec120[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 vD4;
    f32 vFC;
    f32 vF0;
    f32 one;
    s32 v15;
    s32 flagBD;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    f32 cD8;
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    vD4 = *(f32 *)(config + 212);
    vFC = *(f32 *)(config + 252);
    vF0 = *(f32 *)(config + 240);
    one = 1.0f;
    idx = 0;
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        flagBD = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (*(u8 *)(config + 189) == 0)) {
        flagBD = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        goto main_check;
    } else {
        flagBD = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    if ((flags & 1) == 0) {
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D40), "m"(D_00713D40) : "$vf10", "memory");
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec120) : "r"(vec120) : "$vf10", "memory");
        out[0] = vec120[0];
        out[1] = vec120[1];
        out[2] = vec120[2];
    } else {
        out[0] = 0.0f;
        out[1] = 1.0f;
        out[2] = 0.0f;
    }
    vec120[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[1] = 0.0f;
    vec120[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec120) : "r"(vec120) : "$vf10", "memory");
    out[3] = vec120[0];
    out[4] = vec120[1];
    out[5] = vec120[2];
    a = *(f32 *)(config + 208);
    b = effMiscRandFloat(0);
    out[11] = *(f32 *)(config + 204) * ((one - a) + a * b);
    a = *(f32 *)(config + 248);
    b = effMiscRandFloat(0);
    out[12] = -*(f32 *)(config + 244) * ((one - a) + a * b);
    a = *(f32 *)(config + 220);
    b = effMiscRandFloat(0);
    cD8 = *(f32 *)(config + 216) * ((one - a) + a * b);
    a = *(f32 *)(config + 228);
    b = effMiscRandFloat(0);
    ftmp1 = *(f32 *)(config + 224) * ((one - a) + a * b);
    out[8] = cD8;
    out[9] = (ftmp1 - cD8) / (f32)limitB8;
    a = *(f32 *)(config + 236);
    b = effMiscRandFloat(0);
    out[10] = *(f32 *)(config + 232) * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    out[6] = fGpffff8080 * b;
    out[7] = sinf(out[6]);
    b = effMiscRandFloat(0);
    c = 2.0f * (b - 0.5f);
    vec110[0] = *(f32 *)(config + 200) * c;
    vec110[1] = vec110[0];
    vec110[2] = vec110[0];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf10", "memory");
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec110), "m"(*(u_long128 *)vec110) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec110), "m"(*(u_long128 *)vec110) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[13] = (one - a) + a * b;
    if (mode9C == 2) {
        out[14] = 0.0f;
        out[15] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[15] = (one - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[14] = fGpffff8080 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[15] = out[15] * -1.0f;
            }
        } else {
            out[14] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    func_0048b220(nodes, config, 0, (u_long128 *)nodes);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    if (flagBD != 0) {
        c0 = *(s32 *)(config + 192);
        c4 = *(s32 *)(config + 196);
        nmult = c0 * c4;
        if (nmult != 0) {
            clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = sinf(out[6]);
    ftmp2 = ftmp1 - out[7];
    c = out[8] * ftmp2;
    *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[3] * c;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[4] * c;
    *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[5] * c;
    out[11] = out[11] - vD4;
    c = out[11];
    *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[0] * c;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[1] * c;
    *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[2] * c;
    out[6] = out[6] + out[10];
    out[8] = out[8] + out[9];
    out[7] = ftmp1;
    if (*(f32 *)(nodes + 4) < vF0) {
        out[12] = out[12] * vFC;
        out[11] = out[11] * out[12];
        *(f32 *)(nodes + 4) = vF0 + out[12] * (*(f32 *)(nodes + 4) - vF0);
    }
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter:
    idx += 1;
    out += 16;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492100);
#endif
// FUN_00492A80
void func_00492a80(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492a80_check;
loop_00492a80_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492a80_check:
    if (var_7 < 3U) {
        goto loop_00492a80_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}
// FUN_00492B20
u8 *func_00492b20(u16 arg0, s32 arg1, u8 *arg2)
{
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_16;
    s32 temp_22;
    s32 temp_17;
    s32 temp_18;

    if ((arg0 & 0xFFFF) >= 0xC) {
        func_0046d730(D_00713E10, 0xD66);
    }
    temp_16 = arg1 * (*(s32 *)(arg2 + 0xC4) * *(s32 *)(arg2 + 0xC0) + 1);
    temp_22 = temp_16 << 5;
    temp_17 = arg1 * D_00713D58[(arg0 & 0xFFFF) * 4];
    temp_18 = D_00713D5C[(arg0 & 0xFFFF) * 4];
    temp_17 += temp_22 + 0x30;
    temp_17 += temp_18 * 2;
    func_0044ea90(D_00713E10, 0xD73);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00713E10, 0xD74);
    }
    temp_2_2 = temp_2 + 0x30;
    *(u8 **)(temp_2 + 0x18) = temp_2_2;
    temp_2_2 += temp_22;
    *(u8 **)(temp_2 + 0x20) = temp_2_2;
    temp_2_2 += temp_18;
    *(u8 **)(temp_2 + 0x24) = temp_2_2;
    temp_2_2 += temp_18;
    *(u8 **)(temp_2 + 0x1C) = temp_2_2;
    *(u16 *)(temp_2 + 0x00) = arg0;
    *(s32 *)(temp_2 + 0x04) = arg1;
    *(s32 *)(temp_2 + 0x08) = temp_16;
    *(s32 *)(temp_2 + 0x0C) = 0;
    *(s32 *)(temp_2 + 0x10) = 0;
    *(s32 *)(temp_2 + 0x14) = 0;
    *(u8 **)(temp_2 + 0x28) = temp_2;
    memcpy(*(void **)(temp_2 + 0x20), arg2, temp_18);
    memcpy(*(void **)(temp_2 + 0x24), arg2, temp_18);
    temp_2_2 = *(u8 **)(temp_2 + 0x20);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2_2) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(temp_2_2) : "memory");
    if (*(u8 *)(temp_2_2 + 0xBC) != 0) {
        *(s32 *)(temp_2 + 0x0C) |= 1;
    }
    return temp_2;
}
// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}



// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
#pragma opt_loop_invariants on
// FUN_00492D10
void func_00492d10(void *object) {
    u8 *arg0 = object;
    extern void (*D_00713D50[])(u8 *emitter);
    u32 count;
    u32 var_6;
    u8 *var_5;

    if (*(s32 *)(arg0 + 0x10) == 0) {
        count = *(u32 *)(arg0 + 8);
        var_5 = *(u8 **)(arg0 + 0x18);
        var_6 = 0;
        goto loop_00492d10_check;
loop_00492d10_body:
        *(s32 *)(var_5 + 0x10) = -1;
        var_5 += 0x20;
        var_6 += 1;
loop_00492d10_check:
        if (var_6 < count) {
            goto loop_00492d10_body;
        }
    }
    D_00713D50[*(u16 *)arg0 * 4](arg0);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) + 1;
}
/* measured: closes opt_loop_invariants at its prior file baseline. */
#pragma opt_loop_invariants off
// FUN_00492E30
void func_00492e30(u16 *arg0, f32 scale) {
    D_00713D54[*arg0 * 4]((u8 *)arg0, scale);
}
/* measured: probing opt_propagation off for func_004940d0 load and branch order. */
#pragma opt_propagation off
/* measured: probing opt_common_subs off for color byte reloads. */
#pragma opt_common_subs off
// FUN_004940D0
void func_004940d0(u8 *arg0, u16 arg1, Code1_0049Color *arg2)
{
    u32 var_3;
    u32 max_1;
    u32 max_2;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u8 *temp_10;
    u8 *temp_10_2;
    u8 *temp_5;
    u8 *temp_7;
    u8 *temp_8;
    u8 *temp_8_2;

    temp_7 = *(u8 **)(arg0 + 0x10);
    c3 = arg2->c3;
    max_1 = 0xFF;
    if (c3 != max_1) {
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10[4] = c0;
        temp_10[5] = c1;
        temp_10[6] = c2;
        temp_10[7] = c3;
    } else {
        arg2->c3 = 0xFE;
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10_2 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10_2[4] = c0;
        temp_10_2[5] = c1;
        temp_10_2[6] = c2;
        temp_10_2[7] = c3;
        arg2->c3 = max_1;
    }
    temp_5 = *(u8 **)(arg0 + 0x14);
    c3 = arg2->c3;
    max_2 = 0xFF;
    if (c3 != max_2) {
        temp_8 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_8[4] = c0;
        temp_8[5] = c1;
        temp_8[6] = c2;
        temp_8[7] = c3;
        return;
    }
    arg2->c3 = 0xFE;
    temp_8_2 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
    c0 = arg2->c0;
    c1 = arg2->c1;
    c2 = arg2->c2;
    c3 = arg2->c3;
    temp_8_2[4] = c0;
    temp_8_2[5] = c1;
    temp_8_2[6] = c2;
    temp_8_2[7] = c3;
    arg2->c3 = max_2;
}
/* measured: closing opt_common_subs after func_004940d0 probe. */
#pragma opt_common_subs on
/* measured: closing opt_propagation after func_004940d0 probe. */
#pragma opt_propagation on
/* Draft (measured 2026-09-17, source-repo only): probe_variants p_cseoff 263 words BEST (s_v2 278, sched 276, nobl 278, levers neutral), fnalign 253/291/203 (87% emitted, 38 instrs short). Four-pragma sweep measured; words-best cseoff vs edits-best s_v2/nobl (189). wscan dsll32 2 vs 0 + MMI pextlb/pextlh wall. More than 3% short of retail instruction count, so left as plain INCLUDE_ASM draft, not a floor. See docs/probe_archive/CMsgWin_004941f0_body.c. */
/* Fresh 2026-09-17 plain-C (no MMI asm, f32 quads + guarded (u8)(s32)f lerp per y_CmbCardEff 00348330 idiom, same CFG/gotos): probe_variants 528w, fnalign 431ed retail292/object541 (bloated, not short) vs draft 263w/203ed 253/291. Plain C without pextlb/pextlh/qmtc2/vitof0/vmulx/sqc2/lqc2/vadd/vftoi0/ppach doubles the word distance and bloats the object, confirming the wall is genuine VU0+MMI transfer shape, not a shortfall artifact or CFG defect. Draft 263w keeps MMI asm so still H009-unsafe for src/; both stay as docs/probe_archive drafts, production stays INCLUDE_ASM. */
/* Floor (measured 2026-09-18, authoritative tree): probe_variants port 273 words, obj 1136B / window 1168B */
/* (284 vs 291 retail instrs, 7 short, 2.4% short, banks per 3% rule); fnalign 149 edits, */
/* frame/values/CFG per retail; VU scale + lerp blocks as genuine VU0 inline asm (each <=5 ordinary */
/* vs >=5 hardware, H009-clean); COP1 div/add/sub/cvt stays plain C. Re-measured commands (pwd */
/* source/Persona4-Decompilation, no hardware-asm): */
/* python3 tools/probe_variants.py src/promoted/code1_0049.c func_004941f0 --candidate port=/tmp/cmsgwin_v1.c */
/* python3 -E -s tools/fnalign.py src/promoted/code1_0049.c func_004941f0 --candidate /tmp/cmsgwin_v1.c --quiet */
/* python3 tools/measure_guarded.py src/promoted/code1_0049.c func_004941f0 (after install) */
/* Prior drafts retained: docs/probe_archive/CMsgWin_004941f0_body.c (263w 253/291 short); plain-C 528w */
/* 541-vs-292 bloat confirming VU wall. This floor is /tmp/cmsgwin_v1.c (239 lines), banked. */
/* Other cold in this owner still ASM, NOT claimed here: func_004903c0, func_00490c40, func_004916f0, func_00492100, func_00494740. */
// FUN_004941F0 NONMATCHING
#ifdef NON_MATCHING
void func_004941f0(u8 *arg0, u32 *arg1)
{
    extern void RpGeometryLock(void *arg0, s32 arg1);
    extern void func_003c22f0(void *arg0);
    extern void memcpy(void *dst, void *src, s32 size);
    extern f32 fGpffff8044;
    u8 *work;
    u8 *dst;
    u8 *dstBase;
    s32 count2;
    s32 wdiv;
    s32 n;
    f32 fn;
    f32 step;
    f32 t;
    u32 c0w;
    u32 c1w;
    u32 c2w;
    u32 c3w;
    f32 scale;
    u_long128 q0;
    u_long128 q1;
    u_long128 q2;
    u_long128 q3;
    u32 k255 = 0x437F0000;

    work = *(u8 **)(arg0 + 0x10);
    RpGeometryLock(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 8);
    count2 = *(s16 *)(work + 0x48);
    wdiv = *(s16 *)(work + 8);
    n = wdiv / 3;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x30);
    dstBase = dst;
    fn = (f32)n;
    step = 1.0f / fn;
    t = 0.0f;
    c0w = arg1[0];
    scale = fGpffff8044;
    __asm__ volatile (
        ".set noreorder\n"
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2 $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "sqc2 $vf10, 0(%1)\n"
        ".set reorder"
        :
        : "r"(&c0w), "r"(&q0), "f"(scale)
        : "$2", "memory");
    c1w = arg1[1];
    __asm__ volatile (
        ".set noreorder\n"
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2 $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "sqc2 $vf10, 0(%1)\n"
        ".set reorder"
        :
        : "r"(&c1w), "r"(&q1), "f"(scale)
        : "$2", "memory");
    c2w = arg1[2];
    __asm__ volatile (
        ".set noreorder\n"
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2 $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "sqc2 $vf10, 0(%1)\n"
        ".set reorder"
        :
        : "r"(&c2w), "r"(&q2), "f"(scale)
        : "$2", "memory");
    c3w = arg1[3];
    __asm__ volatile (
        ".set noreorder\n"
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2 $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "sqc2 $vf10, 0(%1)\n"
        ".set reorder"
        :
        : "r"(&c3w), "r"(&q3), "f"(scale)
        : "$2", "memory");
    if (n != 0) {
        s32 i_lerp = 0;
        f32 one = 1.0f;
        while (i_lerp < n) {
            f32 oneMinusT = one - t;
            u32 packed0;
            u32 packed1;
            __asm__ volatile (
                ".set noreorder\n"
                "lqc2 $vf11, 0(%0)\n"
                "lqc2 $vf10, 0(%1)\n"
                "mfc1 $2, %3\n"
                "nop\n"
                "qmtc2 $2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "mfc1 $2, %4\n"
                "nop\n"
                "qmtc2 $2, $vf2\n"
                "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                "vadd.xyzw $vf10, $vf10, $vf11\n"
                "qmtc2 %5, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2 $2, $vf10\n"
                "ppach $2, $zero, $2\n"
                "ppacb $2, $zero, $2\n"
                "sw $2, 0(%2)\n"
                ".set reorder"
                :
                : "r"(&q0), "r"(&q2), "r"(&packed0), "f"(t), "f"(oneMinusT), "r"(k255)
                : "$2", "memory");
            *(u32 *)(dst + 4) = packed0;
            __asm__ volatile (
                ".set noreorder\n"
                "lqc2 $vf11, 0(%0)\n"
                "lqc2 $vf10, 0(%1)\n"
                "mfc1 $2, %3\n"
                "nop\n"
                "qmtc2 $2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "mfc1 $2, %4\n"
                "nop\n"
                "qmtc2 $2, $vf2\n"
                "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                "vadd.xyzw $vf10, $vf10, $vf11\n"
                "qmtc2 %5, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2 $2, $vf10\n"
                "ppach $2, $zero, $2\n"
                "ppacb $2, $zero, $2\n"
                "sw $2, 0(%2)\n"
                ".set reorder"
                :
                : "r"(&q1), "r"(&q3), "r"(&packed1), "f"(t), "f"(oneMinusT), "r"(k255)
                : "$2", "memory");
            *(u32 *)dst = packed1;
            dst[8] = dst[0];
            dst[9] = dst[1];
            dst[10] = dst[2];
            dst[11] = dst[3];
            t = t + step;
            dst += 12;
            i_lerp++;
        }
    }
    {
        s32 j_copy = 1;
        s32 copySize = wdiv * 4;
        while (j_copy < count2) {
            memcpy(dst, dstBase, copySize);
            dst += copySize;
            j_copy++;
        }
    }
    {
        u8 *model;
        model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
        func_003c22f0(model);
        if (*(u16 *)work & 4) {
            *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
        }
    }
    {
        u8 *work2;
        u8 *dst2;
        work2 = *(u8 **)(arg0 + 0x14);
        RpGeometryLock(*(u8 **)(*(u8 **)(work2 + 0x10) + 0x18), 8);
        dst2 = *(u8 **)(*(u8 **)(*(u8 **)(work2 + 0x10) + 0x18) + 0x30);
        *(u32 *)(dst2 + 0) = arg1[0];
        *(u32 *)(dst2 + 4) = arg1[1];
        dst2[8] = dst2[4];
        dst2[9] = dst2[5];
        dst2[10] = dst2[6];
        dst2[11] = dst2[7];
        dst2[12] = dst2[4];
        dst2[13] = dst2[5];
        dst2[14] = dst2[6];
        dst2[15] = dst2[7];
        dst2[16] = dst2[4];
        dst2[17] = dst2[5];
        dst2[18] = dst2[6];
        dst2[19] = dst2[7];
        dst2[20] = dst2[4];
        dst2[21] = dst2[5];
        dst2[22] = dst2[6];
        dst2[23] = dst2[7];
        dst2[24] = dst2[4];
        dst2[25] = dst2[5];
        dst2[26] = dst2[6];
        dst2[27] = dst2[7];
        dst2[28] = dst2[4];
        dst2[29] = dst2[5];
        dst2[30] = dst2[6];
        dst2[31] = dst2[7];
        {
            s32 k_rep = 1;
            u8 *repDst = dst2 + 0x20;
            while (k_rep < count2) {
                memcpy(repDst, dst2, 0x20);
                repDst += 0x20;
                k_rep++;
            }
        }
        {
            u8 *model2;
            model2 = *(u8 **)(*(u8 **)(work2 + 0x10) + 0x18);
            func_003c22f0(model2);
            if (*(u16 *)work2 & 4) {
                *(u16 *)(model2 + 0xC) = *(u16 *)(model2 + 0xC) | 1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004941f0);
#endif
// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}



/* Expand the stored halfword index separately at each primitive lookup. */
static inline u32 track_index(u16 value)
{
    return value;
}
#pragma push
#pragma opt_loop_invariants on
/* The geometry contains left/center/right rows of three 12-byte vertices. */
typedef struct TrackVertex
{
    f32 x, y, z;
} TrackVertex;
/* Advance one track's center history, build the tapered ribbon, and mirror
 * the cap vertices from the retained head tangent and side vector.
 * measured: b210 -O2, 2120/2128 bytes with eight zero tail bytes; all 104
 * relocations resolve to retail. Loop invariants retain the narrowed tail
 * bound. The scalar width expression preserves the cap width and VU input
 * as distinct lifetimes; all vector transfers declare their memory operands. */
// FUN_00494740
void func_00494740(u8 *track, u16 trackIndex, u8 *point, f32 width) {
    extern void func_0048a340(f32 angle);
    extern u_long128 D_00713D00;
    extern f32 D_00713D10[4];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    extern f32 fGpffff8094;
    extern f32 fGpffff80bc;
    extern f32 fGpffff80c0;
    extern f32 fGpffff80c8;
    extern f32 fGpffff80cc;
    u_long128 headTangent;
    u_long128 headSide;
    u8 *followingCenter;
    u8 *previousCenter;
    s32 vertexCount;
    u16 shiftedVertex;
    s32 rowCount;
    u32 lastRow;
    u8 *countSlot;
    u32 activeRows;
    u8 *row;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 headWidth;
    f32 rotation;
    u16 rowIndex;
    u16 lastActiveRow;
    u8 *cap;
    f32 capLength;
    f32 capWidth;

    {
        u8 *t10 = *(u8 **)(track + 0x10);
        vertexCount = *(u16 *)(t10 + 8);
        {
            u8 *t1 = *(u8 **)(t10 + 0x10);
            u8 *t2 = *(u8 **)(t1 + 0x18);
            u8 *t3 = *(u8 **)(t2 + 0x5C);
            u8 *tab = *(u8 **)(t3 + 0x14);
            row = tab + (u32)vertexCount * track_index(trackIndex) * 12;
        }
        previousCenter = row + (vertexCount - 5) * 12;
        followingCenter = row + (vertexCount - 2) * 12;
    }
    shiftedVertex = 3;
    goto shift_check;
shift_center:
    *(TrackVertex *)(followingCenter) = *(const TrackVertex *)(previousCenter);
    previousCenter -= 0x24;
    followingCenter -= 0x24;
    shiftedVertex += 3;
shift_check:
    if (shiftedVertex < vertexCount) {
        goto shift_center;
    }
    *(TrackVertex *)(row + 0xc) = *(const TrackVertex *)(point);
    rowCount = (s32)vertexCount / 3 - 1;
    lastRow = (u16)rowCount;
    countSlot = *(u8 **)(track + 0x18) + (track_index(trackIndex) * 2);
    activeRows = *(u16 *)countSlot;
    if ((s32)activeRows <= (s32)lastRow) {
        u32 nv = activeRows + 1;
        activeRows = (u16)nv;
        *(u16 *)countSlot = (u16)nv;
    }
    firstRow = row;
    headWidth = 0.0f;
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    rowIndex = 0;
    if ((s32)(u16)activeRows <= 1) {
        goto collapse_tail;
    }
    {
        fraction = (f32)(u32)activeRows / (f32)(u32)lastRow;
        fractionStep = fraction / (f32)(u32)activeRows;
        headWidth = width * fraction;
    }
    lastActiveRow = activeRows - 1;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D00), "m"(D_00713D00) : "$vf10", "memory");
    __asm__ volatile(
        "vmove.xyzw $vf24, $vf10 \n"
        : : : "$vf24", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(track), "m"(*(u_long128 *)track) : "$vf11", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf11 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        : : : "$vf2", "memory");
    {
        f32 dot;
        __asm__ volatile(
            "qmfc2 %0, $vf2 \n"
            : "=r"(dot) : : "memory");
        rotation = fGpffff8094 * dot;
    }
    D_00713D10[0] = *(f32 *)(row + 12);
    D_00713D14[0] = *(f32 *)(row + 16);
    D_00713D18[0] = *(f32 *)(row + 20);
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = *(f32 *)(row + 48);
    D_00713D14[0] = *(f32 *)(row + 52);
    D_00713D18[0] = *(f32 *)(row + 56);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    func_0048a340(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    {
            /* The unmodified inputs describe this row's width independently of
         * the retained cap width. Both are the same product at the head. */
        f32 rowWidth = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(rowWidth) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)row = D_00713D10[0];
    *(f32 *)(row + 4) = D_00713D14[0];
    *(f32 *)(row + 8) = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)(row + 24) = D_00713D10[0];
    *(f32 *)(row + 28) = D_00713D14[0];
    *(f32 *)(row + 32) = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
    goto ribbon_check;
ribbon_row:
    D_00713D10[0] = *(f32 *)(row + 12);
    D_00713D14[0] = *(f32 *)(row + 16);
    D_00713D18[0] = *(f32 *)(row + 20);
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = *(f32 *)(row + 48);
    D_00713D14[0] = *(f32 *)(row + 52);
    D_00713D18[0] = *(f32 *)(row + 56);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    func_0048a340(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    {
        f32 t = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    {
        u8 *dst = row;
        *(f32 *)dst = D_00713D10[0];
        *(f32 *)(dst + 4) = D_00713D14[0];
        *(f32 *)(dst + 8) = D_00713D18[0];
    }
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)(row + 24) = D_00713D10[0];
    *(f32 *)(row + 28) = D_00713D14[0];
    *(f32 *)(row + 32) = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
ribbon_check:
    if (rowIndex < lastActiveRow) {
        goto ribbon_row;
    }
collapse_tail:
    *(TrackVertex *)(row) = *(const TrackVertex *)(row + 0xc);
    *(TrackVertex *)(row + 0x18) = *(const TrackVertex *)(row + 0xc);
    {
        u8 *nxt = row + 0x24;
        goto tail_check;
tail_row:
        *(TrackVertex *)(nxt) = *(const TrackVertex *)(row);
        *(TrackVertex *)(nxt + 0xc) = *(const TrackVertex *)(row + 0xc);
        *(TrackVertex *)(nxt + 0x18) = *(const TrackVertex *)(row + 0x18);
        nxt += 0x24;
        rowIndex++;
tail_check:
        if (rowIndex < (s32)(u16)lastRow) {
            goto tail_row;
        }
        {
            u8 *t = *(u8 **)(track + 0x14);
            u32 c2 = *(u16 *)(t + 8);
            u8 *t1 = *(u8 **)(t + 0x10);
            u8 *t2 = *(u8 **)(t1 + 0x18);
            u8 *t3 = *(u8 **)(t2 + 0x5C);
            u8 *tab2 = *(u8 **)(t3 + 0x14);
            cap = tab2 + (u32)c2 * track_index(trackIndex) * 12;
            *(TrackVertex *)cap = *(const TrackVertex *)(firstRow + 12);
            *(TrackVertex *)(cap + 0xc) = *(const TrackVertex *)(firstRow);
            *(TrackVertex *)(cap + 0x54) = *(const TrackVertex *)(firstRow + 0x18);
        }
        {
            f32 wide;
            f32 inner;
            f32 blendWide;
            f32 blendInner;
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&headTangent), "m"(headTangent) : "$vf11", "memory");
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11", "memory");
            capLength = 2.0f * headWidth;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capLength) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "memory");
            }
            D_00713D10[0] = *(f32 *)(firstRow + 12);
            D_00713D14[0] = *(f32 *)(firstRow + 16);
            D_00713D18[0] = *(f32 *)(firstRow + 20);
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            wide = fGpffff80bc * headWidth;
            capWidth = wide;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendWide = fGpffff80c0;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 24) = D_00713D10[0];
            *(f32 *)(cap + 28) = D_00713D14[0];
            *(f32 *)(cap + 32) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            inner = 1.7f * headWidth;
            capWidth = inner;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendInner = fGpffff80c8;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 36) = D_00713D10[0];
            *(f32 *)(cap + 40) = D_00713D14[0];
            *(f32 *)(cap + 44) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(wide) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 72) = D_00713D10[0];
            *(f32 *)(cap + 76) = D_00713D14[0];
            *(f32 *)(cap + 80) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                f32 t2 = inner;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t2) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 60) = D_00713D10[0];
            *(f32 *)(cap + 64) = D_00713D14[0];
            *(f32 *)(cap + 68) = D_00713D18[0];
            {
                f32 endpoint = fGpffff80cc;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(endpoint) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    "vadd.xyzw $vf11, $vf11, $vf12 \n"
                    : : : "$vf11", "memory");
            }
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 48) = D_00713D10[0];
            *(f32 *)(cap + 52) = D_00713D14[0];
            *(f32 *)(cap + 56) = D_00713D18[0];
        }
    }
}

#pragma pop
// FUN_00494F90
void func_00494f90(u8 *arg0) {
    func_0048a1f0(arg0);
    RpGeometryLock(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    RpGeometryLock(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}

// FUN_00494FF0
void func_00494ff0(u8 *arg0) {
    extern void func_003c22f0(void *);
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_18;

    temp_18 = *(u8 **)(arg0 + 0x14);
    temp_17 = *(u8 **)(*(u8 **)(temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17);
    if (*(u16 *)temp_18 & 4) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    temp_17_2 = *(u8 **)(arg0 + 0x10);
    temp_16 = *(u8 **)(*(u8 **)(temp_17_2 + 0x10) + 0x18);
    func_003c22f0(temp_16);
    if (*(u16 *)temp_17_2 & 4) {
        *(u16 *)(temp_16 + 0xC) = *(u16 *)(temp_16 + 0xC) | 1;
    }
}
// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(u8 **)(arg0 + 0x10), (s32)arg1);
    func_00484280(*(u8 **)(arg0 + 0x14), (s32)arg1);
}

// FUN_004950E0
void func_004950e0(u8 *arg0) {
    u32 temp_16;
    u8 *var_18;
    u32 var_17;

    var_18 = *(u8 **)(*(u8 ***)(arg0 + 0x30));
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    var_17 = 0;
    goto loop_004950e0_check;
loop_004950e0_body:
    *(s32 *)(var_18 + 4) = -1 - (effMiscRand(0) & 3);
    var_17 += 1;
    var_18 += 0x10;
loop_004950e0_check:
    if (var_17 < temp_16) {
        goto loop_004950e0_body;
    }
}
// FUN_00498AC0
void func_00498ac0(u8 *arg0) {
    D_00713E78[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    jtbl_008873EC[0](arg0);
}
// FUN_00498B20
void *func_00498b20(void *source) {
    u8 *arg0 = source;

    return func_004988c0(*(u16 *)(arg0 + 0x2C), *(u8 **)(arg0 + 0x34));
}
// FUN_00498B50
void func_00498b50(u8 *arg0) {
    D_00713E70[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = 0;
}
// FUN_00498BA0
void func_00498ba0(u8 *arg0) {
    D_00713E7C[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x28) + 1;
}
// FUN_00498C00
void func_00498c00(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x28) > 0) {
        D_00713E80[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    }
}
// FUN_00498CE0
u_long128 func_00498ce0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_00498CF0
u_long128 func_00498cf0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_00498D00
void func_00498d00(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}
// FUN_00498D10
void func_00498d10(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
}
// FUN_00498D20
void func_00498d20(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_7;
    u8 *temp_7_2;

    temp_4 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    if (iGpffffbb64.c3 != 0xFF) {
        temp_7 = *(u8 **)(temp_4 + 0x14);
        *(Code1_0049Color *)(temp_7 + 4) = iGpffffbb64;
        return;
    }
    iGpffffbb64.c3 = 0xFE;
    temp_7_2 = *(u8 **)(temp_4 + 0x14);
    *(Code1_0049Color *)(temp_7_2 + 4) = iGpffffbb64;
    iGpffffbb64.c3 = 0xFF;
}
// FUN_0049A570
void func_0049a570(u8 *arg0) {
    D_00713F18[*(s32 *)(arg0 + 0x38) * 6](*(void **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
// FUN_0049A5E0
void *func_0049a5e0(void *source) {
    u8 *arg0 = source;

    return func_0049a370(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
}
// FUN_0049A610
void func_0049a610(u8 *arg0) {
    D_00713F10[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = 0;
}
// FUN_0049A660
void func_0049a660(u8 *arg0) {
    D_00713F1C[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}
// FUN_0049A6C0
void func_0049a6c0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        D_00713F20[*(s32 *)(arg0 + 0x38) * 6](arg0);
    }
}
// FUN_0049A7A0
u_long128 func_0049a7a0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_0049A7B0
u_long128 func_0049a7b0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_0049A7C0
void func_0049a7c0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}
// FUN_0049A7D0
void func_0049a7d0(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
    *(f32 *)(arg0 + 0x24) = fparg0;
    *(f32 *)(arg0 + 0x28) = fparg0;
}
// FUN_0049A7F0
void func_0049a7f0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}
/* measured: the sibling 0049b470 body matches this routine's control-flow and
   call sequence; target entries are 0x18 bytes, so the fill stride is six words. */
#pragma opt_loop_invariants on
// FUN_0049A810
void func_0049a810(u8 *arg0)
{
    extern void RpGeometryLock(void *, s32);
    extern void func_003c22f0(void *);
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    RpGeometryLock(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    memset((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
/* measured: closes the opt_loop_invariants scope for 0049a810 at the file baseline. */
#pragma opt_loop_invariants off

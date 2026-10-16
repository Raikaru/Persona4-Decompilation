#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern u8 *func_004a6c00(u8 *arg0);
extern u8 D_0071413C[];
extern f32 iGpffff8080;

extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern s32 kwlnGetCamera(void);
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];



extern void func_003f6690(s32 param, void *out);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u8 D_00714368[];
extern void mdlEffectEmitValuePacket(s64 arg);
extern void mdlEffectEmitSlotPacket(void);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes func_004a1950 MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *);

/* Source unit: src/promoted/code1_004a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004a7e30-004a8890 */

/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: close loop-invariant hoisting after func_004a6c00. */
#pragma push
#pragma tailcall off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
/* measured: the byte->float sites are `(f32)(u32)x`; the eight rotated-corner stores add the
   centre offset inside the store expression (`*(f32 *)(arg1 + 0x10) = temp_f26 + temp_f1;`):
   assigning back into temp_f1 makes mwcc put the coalesced operand first (add.s f1,f1,f26),
   a fresh destination keeps retail's add.s f1,f26,f1. */
/* measured: loop-invariant conversion preloads for func_004a7e30. */
/* measured: func_004a7e30 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_004A7E30
s32 func_004a7e30(u8 *arg0, u8 *arg1)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern f32 fabsf(f32 arg0);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    s32 temp_6;
    s32 temp_5;
    s32 temp_4;
    s32 temp_3;
    u32 var_8;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u8 *temp_7;

    if (*(f32 *)(arg0 + 0x18) > 640.0f ||
        *(f32 *)(arg0 + 0x1C) > 448.0f ||
        *(f32 *)(arg0 + 0x20) < 0.0f ||
        *(f32 *)(arg0 + 0x24) < 0.0f) {
        return 0;
    }
    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80);
    temp_f5 = D_008872F8[0];
    var_8 = 0;
    goto loop_004a7e30_check;
loop_004a7e30_body:
    temp_7 = arg1 + (var_8 << 6);
    *(f32 *)(temp_7 + 0x18) = temp_f6;
    *(f32 *)(temp_7 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_7 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_7 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_7 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_7 + 8) = temp_f5;
    var_8 += 1;
loop_004a7e30_check:
    if (var_8 < 4U) {
        goto loop_004a7e30_body;
    }
    temp_f26 = *(f32 *)(arg0 + 0x10) / D_00922D94[0];
    temp_f25 = *(f32 *)(arg0 + 0x14) / D_00922D98[0];
    temp_f6 = *(f32 *)(arg0 + 0x0C);
    temp_f5 = *(f32 *)(arg0 + 0x18);
    temp_f4 = temp_f5 / D_00922D94[0];
    temp_f3 = *(f32 *)(arg0 + 0x1C) / D_00922D98[0];
    temp_f2 = *(f32 *)(arg0 + 0x20) / D_00922D94[0];
    temp_f1 = *(f32 *)(arg0 + 0x24) / D_00922D98[0];
    temp_f0 = temp_f4 - temp_f26;
    temp_f24 = temp_f6 * temp_f0;
    temp_f0 = temp_f3 - temp_f25;
    temp_f23 = temp_f6 * temp_f0;
    temp_f0 = temp_f2 - temp_f26;
    temp_f22 = temp_f6 * temp_f0;
    temp_f0 = temp_f1 - temp_f25;
    temp_f21 = temp_f6 * temp_f0;
    temp_f0 = temp_f24 - temp_f22;
    temp_f3 = fabsf(temp_f0);
    temp_f0 = temp_f23 - temp_f21;
    temp_f2 = fabsf(temp_f0);
    if (!(temp_f3 > 0.0f &&
          temp_f2 > 0.0f &&
          temp_f3 < 7.0f &&
          temp_f2 < 7.0f)) {
        return 0;
    }
    *(f32 *)(arg1 + 0) = temp_f5;
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    if (*(f32 *)(arg0 + 8) == 0.0f) {
        temp_f3 = temp_f24 + temp_f26;
        temp_f2 = temp_f22 + temp_f26;
        temp_f1 = temp_f23 + temp_f25;
        temp_f0 = temp_f21 + temp_f25;
        *(f32 *)(arg1 + 0x10) = temp_f3;
        *(f32 *)(arg1 + 0x14) = temp_f1;
        *(f32 *)(arg1 + 0x50) = temp_f3;
        *(f32 *)(arg1 + 0x54) = temp_f0;
        *(f32 *)(arg1 + 0x90) = temp_f2;
        *(f32 *)(arg1 + 0x94) = temp_f0;
        *(f32 *)(arg1 + 0xD0) = temp_f2;
        *(f32 *)(arg1 + 0xD4) = temp_f1;
    } else {
        temp_f20 = cosf(*(f32 *)(arg0 + 8));
        temp_f0_2 = sinf(*(f32 *)(arg0 + 8));
        temp_f6 = temp_f23 * temp_f0_2;
        temp_f3 = temp_f24 * temp_f20;
        temp_f1 = temp_f3 - temp_f6;
                *(f32 *)(arg1 + 0x10) = temp_f26 + temp_f1;
        temp_f5 = temp_f23 * temp_f20;
        temp_f2 = temp_f24 * temp_f0_2;
        temp_f1 = temp_f2 + temp_f5;
                *(f32 *)(arg1 + 0x14) = temp_f25 + temp_f1;
        temp_f4 = temp_f21 * temp_f0_2;
        temp_f1 = temp_f3 - temp_f4;
                *(f32 *)(arg1 + 0x50) = temp_f26 + temp_f1;
        temp_f3 = temp_f21 * temp_f20;
        temp_f1 = temp_f2 + temp_f3;
                *(f32 *)(arg1 + 0x54) = temp_f25 + temp_f1;
        temp_f2 = temp_f22 * temp_f20;
        temp_f1 = temp_f2 - temp_f4;
                *(f32 *)(arg1 + 0x90) = temp_f26 + temp_f1;
        temp_f1 = temp_f22 * temp_f0_2;
        temp_f0 = temp_f1 + temp_f3;
                *(f32 *)(arg1 + 0x94) = temp_f25 + temp_f0;
        temp_f0 = temp_f2 - temp_f6;
                *(f32 *)(arg1 + 0xD0) = temp_f26 + temp_f0;
        temp_f0 = temp_f1 + temp_f5;
                *(f32 *)(arg1 + 0xD4) = temp_f25 + temp_f0;
    }
    return 1;
}

/* measured: close the loop-invariant bracket after func_004a7e30. */
// FUN_004A8250
/* measured: loop-invariant conversion preloads for func_004a8250. */
void func_004a8250(u8 *arg0, u8 *arg1)
{
    f32 temp_f6;
    f32 temp_f5;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 var_9;
    u8 *temp_8;

    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a8250_check;
loop_004a8250_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a8250_check:
    if (var_9 < 4U) {
        goto loop_004a8250_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    *(s32 *)(arg1 + 0x10) = 0;
    *(s32 *)(arg1 + 0x14) = 0;
    *(s32 *)(arg1 + 0x50) = 0;
    *(s32 *)(arg1 + 0x54) = 0x3F800000;
    *(s32 *)(arg1 + 0x90) = 0x3F800000;
    *(s32 *)(arg1 + 0x94) = 0x3F800000;
    *(s32 *)(arg1 + 0xD0) = 0x3F800000;
    *(s32 *)(arg1 + 0xD4) = 0;
}

/* measured: close loop-invariant conversion scope for func_004a8250. */
// FUN_004A8440
/* measured: loop-invariant conversion preloads for func_004a8440. */
void func_004a8440(u8 *arg0, u8 *arg1)
{
    extern f32 fGpffff8090;
    extern f32 sinf(f32 arg0);
    extern f32 cosf(f32 arg0);
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    u32 var_9;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 temp_21;
    u8 *temp_8;

    temp_18 = *(u8 *)(arg0 + 0);
    temp_17 = *(u8 *)(arg0 + 1);
    temp_16 = *(u8 *)(arg0 + 2);
    temp_21 = *(u8 *)(arg0 + 3);
    temp_f22 = fGpffff8090 * *(f32 *)(arg0 + 8);
    temp_f20 = *(f32 *)(arg0 + 0xC);
    temp_f21 = temp_f20 * sinf(temp_f22);
    temp_f20 = temp_f20 * cosf(temp_f22);
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a8440_check;
loop_004a8440_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_21;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a8440_check:
    if (var_9 < 4U) {
        goto loop_004a8440_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    temp_f4 = (*(f32 *)(arg0 + 0x18) + temp_f21) / D_00922D94[0];
    temp_f2 = (*(f32 *)(arg0 + 0x1C) + temp_f20) / D_00922D98[0];
    temp_f1 = (*(f32 *)(arg0 + 0x20) + temp_f21) / D_00922D94[0];
    temp_f0 = (*(f32 *)(arg0 + 0x24) + temp_f20) / D_00922D98[0];
    *(f32 *)(arg1 + 0x10) = temp_f4;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x50) = temp_f4;
    *(f32 *)(arg1 + 0x54) = temp_f0;
    *(f32 *)(arg1 + 0x90) = temp_f1;
    *(f32 *)(arg1 + 0x94) = temp_f0;
    *(f32 *)(arg1 + 0xD0) = temp_f1;
    *(f32 *)(arg1 + 0xD4) = temp_f2;
}

/* measured: close loop-invariant conversion scope for func_004a8440. */
// FUN_004A86C0
/* measured: loop-invariant conversion preloads for func_004a86c0. */
void func_004a86c0(u8 *arg0, u8 *arg1)
{
    f32 temp_f6;
    f32 temp_f5;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 var_9;
    u8 *temp_8;

    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a86c0_check;
loop_004a86c0_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a86c0_check:
    if (var_9 < 4U) {
        goto loop_004a86c0_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 8);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0xC);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 8);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x14);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x14);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0xC);
}

/* measured: close loop-invariant conversion scope for func_004a86c0. */
// FUN_004A8890
void func_004a8890(u8 *arg0, s32 *arg1) {
    s32 sp24C;
    s32 sp248;
    u8 sp140[0xFC];
    u8 sp40[0x100];
    s32 *temp_16;
    u8 *temp_18;
    u8 *temp_3;
    void (**setState)(u32, u32);
    void (**sendPacket)(s32, void *, s32, void *, s32);

    temp_16 = arg1;
    func_003f6690(2, &sp24C);
    func_003f6690(3, &sp248);
    setState = (void (**)(u32, u32))D_00887300;
    (*setState)((u32)1, *(u32 *)temp_16);
    mdlEffectEmitMaskedTagPair();
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x31001);
    func_004a8250(arg0 + 4, sp140);
    sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
    (*sendPacket)(3, sp140, 4, D_00714368, 6);
    mdlEffectEmitTagPair();
    RpSkyRenderStateSet(2, sp24C | 0x10);
    if (func_004a7e30(arg0 + 4, sp40) != 0) {
        (*setState)(1, D_00922D90[0]);
        RpSkyRenderStateSet(3, 0x31001);
        mdlEffectEmitValuePacket(0x9FC00A | ((s64)0x6FC << 0x20));
        (*sendPacket)(3, sp40, 4, D_00714368, 6);
        mdlEffectEmitSlotPacket();
    }
    (*setState)(1, 0);
    RpSkyRenderStateSet(3, sp248);
    RpSkyRenderStateSet(2, sp24C);
}


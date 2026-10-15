#include "mt_scene_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern void func_0015a630();
extern void FldEvent_StepGridCell();
extern s32 func_0015f660();
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern s32 func_00102980(void);
extern void func_00145080(void);
extern void func_00260510(void);
extern void *memset(void *dst, s32 value, s32 size);
extern s32 func_00110e80(void);
extern s32 *func_00155280(void);
extern s32 datGetFlag(s32 arg0);
extern s32 func_0016fd00(void);
extern s32 func_00162510(u16 arg0, u16 arg1);
extern u32 RpRandom(void);
extern s32 func_0015a160(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level);
extern void func_00182310(s32 arg0);
extern void func_0018e030(s32 arg0, s32 arg1);
extern s32 func_0029da90(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00452490(s32 arg0);
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);
extern s32 func_00170f60(u8 *arg0, s32 arg1);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern s32 func_0014a160(void);
extern s32 func_0015a100(void);
extern s32 func_0015a130(void);
extern void func_0015a7c0(s32 arg0);
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
extern void func_0018a000(s32 arg0, s32 arg1);
extern void func_002af3e0(u8 *arg0, s8 arg1);
extern void func_002afb70(s32 arg0, s32 arg1);
extern s32 func_0012d000(s32 arg0, s32 arg1);
extern void func_00106390(s32 arg0, s32 arg1);
s32 FldShadow_CasterStep(u8 *arg0);
void FldShadow_CasterDestroy(u8 *arg0);
void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern s32 func_0017cd60(u8 *arg0);
extern void func_0044ea90(const void *msg, s32 id);

extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sinf(f32 arg0);
extern f32 cosf(f32 arg0);
extern f32 iGpffff8304;
extern struct RpGeometry *func_003c22f0(struct RpGeometry *geometry);
extern u8 *func_0046a770(char *arg0);
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];

extern void (*jtbl_008873EC[])(void *);

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern s32 K_FldFrame_IsPointInTriangle(void *arg0, void *arg1, void *arg2);
extern void scrSetReturnInt(s32 arg0);
extern s32 func_00110fc0(void);
extern s32 FldEvent_BeginEncounter(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0018ced0(void);
extern void func_0018c7e0(void);
extern s32 func_00159f70(s32 arg0);
extern s32 func_00155290(void);
extern s32 func_0014ec50(s32 arg0, s32 arg1);
extern s32 func_0029d050(void);
extern void func_0029dfe0(s32 arg0, s32 arg1);
extern s32 func_00452490(s32 arg0);

extern s32 scrGetParamInt(s32 arg0);
extern s64 datGetPartyId(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 *func_00457120(void);
extern void *mdlGetMatrix(void *arg0);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern s32 RwEngineGetMatrixTolerances(f32 *arg0);
extern u8 *RwMatrixOptimize(void *arg0, f32 *arg1);
extern u8 *RwMatrixUpdate(void *arg0);
extern void func_004789c0(void *arg0);
extern void func_0047a320(void *arg0);
extern s32 func_00179fc0(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         f32 farg0, f32 farg1, s32 arg4, u8 *arg5);
extern S_00178590 *FldEvent_GetNearestEntry(void);
extern void RwV3dNormalize(void *arg0, void *arg1);
extern void func_003e42a0(void *dst, void *src, u8 *arg2);
extern u8 D_007EFA00[];
extern void sprintf(void *dst, const void *src);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 arg0, void *arg1);
extern void func_0014def0(u8 *arg0, u8 *arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern void *SceneDraw_GetList4Matrix(void);
extern u8 *func_003e81c0(u8 *, f32);
extern u8 *func_003e8180(u8 *, f32);
extern u8 *RwCameraSetViewWindow(u8 *, const f32 *);
extern u8 *func_003e9c10(u8 *, const f32 *, s32);
extern u8 *func_003e9700(u8 *);
extern u8 *func_003e0670(u8 *, u8 *);
extern u8 *RwCameraClear(u8 *, void *, s32);
extern u32 func_003e8120(u32);
extern void *mdlGetColor(void *);
extern void mdlSetColor(u8 *, const void *);
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern void func_0046d730(const void *, s32);
extern s32 D_005F1930[];
extern s32 D_005F1934[];
extern void func_002bd410(void);
extern void func_002bd3c0(void);

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;

extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003cbc60(s32 arg0, u8 *arg1);
extern void func_003e8440(u8 *arg0);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void *func_003ef080(void *texture, void *raster);
extern void func_003ef3a0(u8 *arg0);
extern void func_003efd20(u8 *camera, u8 *frame);
extern s32 func_00457190(void);

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);



/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */


// FUN_00170960
s32 func_00170960(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)((u8 *)func_00155280() + 0x18) != 0) && (D_008C024E[0] & 0x800)) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_001709C0
s32 func_001709c0(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_00182310(1);
        func_002bd410();
        func_002bd3c0();
        temp_2 = (u8 *)func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        func_0045af60(0, 0, 0, 3);
        temp_2 = (u8 *)func_00155280();
        func_0018a000(*(s32 *)(temp_2 + 0x30), 1);
        temp_2 = (u8 *)func_00155280();
        func_002af3e0(*(u8 **)(temp_2 + 0x18), 1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x820) {
            func_00182310(0);
            temp_2 = (u8 *)func_00155280();
            func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
            temp_2 = (u8 *)func_00155280();
            func_0018a000(*(s32 *)(temp_2 + 0x30), 0);
            temp_2 = (u8 *)func_00155280();
            func_002af3e0(*(u8 **)(temp_2 + 0x18), 0);
            func_0045af60(0, 0, 0, 4);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00170B50
s32 func_00170b50(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (datGetFlag(0x37) == 1) {
        return 0;
    }
    if (D_008C024E[0] & 0x10) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170BC0
s32 func_00170bc0(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (*(s32 *)((u8 *)func_00155280() + 0x30) != 0)
            func_0018a000(*(s32 *)((u8 *)func_00155280() + 0x30), 1);
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0012d000((s32)arg0, 1);
        if (*(s32 *)((u8 *)func_00155280() + 0x18) != 0)
            func_002afb70(*(s32 *)((u8 *)func_00155280() + 0x18), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            if (*(s32 *)((u8 *)func_00155280() + 0x30) != 0)
                func_0018a000(*(s32 *)((u8 *)func_00155280() + 0x30), 0);
            if (datGetFlag(0x1401) != 0) {
                func_0015a7c0(func_0015a160());
                func_00106390(0x1401, 0);
                temp_17 = func_0015a100();
                func_0029db50(0xF, temp_17, func_0015a130(), 5);
                *(s32 *)(temp_16 + 4) = 3;
            } else {
                if (*(s32 *)((u8 *)func_00155280() + 0x18) != 0)
                    func_002afb70(*(s32 *)((u8 *)func_00155280() + 0x18), 0);
                func_00182310(0);
                func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 0);
                *(s32 *)(temp_16 + 0x10) = 0;
                *(s32 *)(temp_16 + 4) += 1;
            }
        }
        break;
    case 2:
        return 0;
    case 3:
        break;
    default:
        break;
    }
    return 1;
}

// FUN_00170E10
s32 func_00170e10(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (D_008C024E[0] & 0x80) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170E50
s32 func_00170e50(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        temp_2 = (u8 *)func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0029da90(0xF, iGpffffb284, 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) == 1)
            break;
        temp_2 = (u8 *)func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
        func_00182310(0);
        *(s32 *)(temp_16 + 4) += 1;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* measured: the 12-byte D_005F1758 origin is a plain Vec3 struct assignment
   (retail ld + lwc1 with separate lui pairs, then sd + swc1); spelling it as
   an s64/f32 pair through separate globals is what cost the archived nd 8, and
   it also made a dead `sp60[0] = &sp50` necessary to hoist $a2. */
// FUN_00170F60
s32 func_00170f60(u8 *arg0, s32 arg1)
{
    Vec3_00178590 sp70;
    u8 *sp60[3];
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f3_2;
    s32 var_17;
    u8 *temp_2;
    u8 *var_16;

    var_17 = 0;
    var_16 = MT_Scene_GetResListHead(0xD);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    temp_2 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
    sp70 = *(Vec3_00178590 *)(temp_2 + 0x30);
    goto loop_21_cond;
loop_21_body:
    {
        extern Vec3_00178590 D_005F1758;
        Vec3_00178590 sp50;

        sp50 = D_005F1758;
        sp60[0] = var_16 + 0x15C;
        sp60[1] = var_16 + 0x168;
        sp60[2] = var_16 + 0x174;
        if ((K_FldFrame_IsPointInTriangle(&sp70, sp60, &sp50) == 1) &&
            (temp_f3 = *(f32 *)(sp60[0] + 4), (sp70.y < (200.0f + temp_f3))) &&
            !(sp70.y <= (temp_f3 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found1;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found1:
            var_17 = 1;
            goto loop_21_done;
        }
        sp60[0] = var_16 + 0x168;
        sp60[1] = var_16 + 0x174;
        sp60[2] = var_16 + 0x180;
        if ((K_FldFrame_IsPointInTriangle(&sp70, sp60, &sp50) == 1) &&
            (temp_f3_2 = *(f32 *)(sp60[0] + 4),
             (sp70.y < (200.0f + temp_f3_2))) &&
            !(sp70.y <= (temp_f3_2 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found2;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found2:
            var_17 = 1;
            goto loop_21_done;
        }
        var_16 = *(u8 **)(var_16 + 0x138);
    }
loop_21_cond:
    if (var_16 != NULL)
        goto loop_21_body;
loop_21_done:
    return var_17;
}

// FUN_001711B0
s32 func_001711b0(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (func_00170f60(D_007EF9B0, 0) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00171280
s32 func_00171280(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (func_0014a160() == 1)
            func_0015a7c0(func_0015a160());
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 0);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 0);
            func_00182310(0);
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_001713E0
s32 func_001713e0(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (func_00170f60(D_007EF9B0, 1) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_001714B0
s32 func_001714b0(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (func_0014a160() == 1)
            func_0015a7c0(func_0015a160());
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)((u8 *)func_00155280() + 0x1C), 0);
            func_00182310(0);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* 608/608 bytes; eight fully resolved GP relocations.
 * Aggregate matrix assignment preserves all 64 bytes. */
typedef struct { Vec3_00178590 right; u32 flags; Vec3_00178590 up; u32 pad1; Vec3_00178590 at; u32 pad2; Vec3_00178590 position; u32 pad3; } FieldMatrix_0017;
// FUN_00175F70
s32 func_00175f70(const u8 *arg0, const FieldMatrix_0017 *arg1, f32 arg2, f32 arg3)
{
    extern f32 fGpffff8558;
    extern f32 fabsf(f32);
    s32 state;
    u8 *work;
    s32 count;
    s32 descending;
    f32 first;
    f32 second;
    f32 direct;
    f32 wrapped;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    state = *(s32 *)(work + 0x40);
    if (state == 1)
        return 0;
    first = arg2;
    second = arg3;
    *(FieldMatrix_0017 *)work = *arg1;
    if (!(first <= 360.0f))
        first -= 360.0f;
    *(f32 *)(work + 0x4C) = first;
    if (!(second <= 360.0f))
        second -= 360.0f;
    *(f32 *)(work + 0x50) = second;
    if (first < second) {
        if (!(first <= fGpffff8558))
            first = 0.0f;
        if (!(second <= *(const f32 *)&fGpffff8558))
            second = 360.0f;
        if (first < iGpffff8214)
            first = 0.0f;
        if (second < *(const f32 *)&iGpffff8214)
            second = 360.0f;
        direct = second - first;
        wrapped = first + (360.0f - second);
        descending = 0;
    } else {
        if (!(first <= fGpffff8558))
            first = 360.0f;
        if (!(second <= *(const f32 *)&fGpffff8558))
            second = 0.0f;
        if (first < iGpffff8214)
            first = 360.0f;
        if (second < *(const f32 *)&iGpffff8214)
            second = 0.0f;
        direct = first - second;
        wrapped = second + (360.0f - first);
        descending = 1;
    }
    if (fabsf(direct) < fabsf(wrapped)) {
        *(f32 *)(work + 0x54) = direct;
        if (descending == 1)
            *(f32 *)(work + 0x54) = *(f32 *)(work + 0x54) * -1.0f;
    } else {
        *(f32 *)(work + 0x54) = wrapped;
        if (descending == 0)
            *(f32 *)(work + 0x54) = *(f32 *)(work + 0x54) * -1.0f;
    }
    if (!(fabsf(*(f32 *)(work + 0x54)) <= 45.0f)) {
        count = (s32)fabsf(*(f32 *)(work + 0x54)) / 30;
        if (count <= 0)
            count = 1;
        *(s32 *)(work + 0x5C) = count;
        *(s32 *)(work + 0x58) = 0;
        *(f32 *)(work + 0x54) =
            *(f32 *)(work + 0x54) / (f32) *(s32 *)(work + 0x5C);
        *(s32 *)(work + 0x40) = 1;
        return 1;
    }
    return 0;
}


// FUN_001761D0
s32 func_001761d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40) == 1;
}

// FUN_001761F0
s32 func_001761f0(void)
{
    func_00110e80();
    return 1;
}
// FUN_00176220
s32 func_00176220(void)
{
    if (func_0029d020() > 3) {
        scrSetReturnInt(func_00110f00());
        return 1;
    }
    scrSetReturnInt(0);
    return 0;
}

// FUN_00176280
void func_00176280(void)
{
    func_0015f660();
}

// FUN_001762A0
s32 func_001762a0(void)
{
    if (func_0018ced0() == 0) {
        func_0018c7e0();
    }
    return 1;
}
// FUN_001762E0
s32 func_001762e0(void)
{
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00110fc0();
    return 1;
}
// FUN_00176320
s32 func_00176320(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_001029a0(0x19, NULL, 0, 0);
    return 1;
}

// FUN_00176370
s32 func_00176370(void) {
    s32 sp1C;

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    memset(&sp1C, 0, 4);
    sp1C = scrGetParamInt(0);
    func_001029a0(0xC, &sp1C, 4, 2);
    return 1;
}

// FUN_001763F0
s32 func_001763f0(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_001029a0(0xD, NULL, 0, 2);
    return 1;
}

// FUN_00176450
s32 func_00176450(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    memset(sp10, 0, 0x1C);
    sp10[0] = (s16)scrGetParamInt(0);
    sp10[1] = (s16)scrGetParamInt(1);
    sp10[2] = (s16)scrGetParamInt(2);
    sp10[4] = (s16)scrGetParamInt(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_00176500
s32 func_00176500(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    *(s16 *)(iGpffff9db0 + 0x10) = -1;
    memset(sp10, 0, 0x1C);
    sp10[0] = (s16)scrGetParamInt(0);
    sp10[1] = (s16)scrGetParamInt(1);
    sp10[2] = (s16)scrGetParamInt(2);
    sp10[4] = (s16)scrGetParamInt(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_001765C0
s32 func_001765c0(void)
{
    s32 sp30[7];
    s32 temp_17;
    s32 temp_3;
    s32 var_16;


    var_16 = 0;
    temp_17 = func_0029d020();
    if (func_0015f660() == 0) {
        iGpffffb304 = func_0029d020();
        return 0;
    }
    if ((temp_17 == 0) || ((temp_17 - 1) == iGpffffb304))
        iGpffffb300 = 0;
    sp30[3] = scrGetParamInt(0);
    sp30[4] = scrGetParamInt(1);
    sp30[5] = scrGetParamInt(2);
    temp_3 = iGpffffb300;
    if (temp_3 == 3) {
        func_001029a0(0xA, sp30, 0x1C, 2);
    } else if (temp_3 > 0xA) {
        if (func_00102980() == -1) {
            iGpffffb300 = 0;
            var_16 = 1;
        } else {
            var_16 = 0;
        }
    }
    iGpffffb300 += 1;
    return var_16;
}
// FUN_001766E0
s32 func_001766e0(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    sp18[0] = scrGetParamInt(0);
    sp18[1] = 0xFFFF;
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176770
s32 func_00176770(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    func_00260510();
    sp18[0] = scrGetParamInt(0);
    sp18[1] = scrGetParamInt(1);
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176810
s32 func_00176810(void)
{
    func_00159f70(scrGetParamInt(0));
    return 1;
}
// FUN_00176850
s32 func_00176850(void)
{
    func_0015a630();
    return 1;
}

// FUN_00176880
s32 func_00176880(void)
{
    scrSetReturnInt(func_0015a160());
    return 1;
}
// FUN_001768B0
s32 func_001768b0(void)
{
    scrSetReturnInt(func_00155290());
    return 1;
}







/* measured: best plain-C body is 108B in the 112B retail window (112B),
   normalized_diff 4; the sole residual bytes at offset 56 are retail
   `andi $a3,$s1,0xffff` versus candidate `move $a3,$s1`. The file-scope
   Encount_PickEncounter declaration remains (u16, u16, u16, s32) for matching
   FldUnit_SpawnEncounter. Probed a block-scope fourth-parameter u16 prototype at
   the function top, after locals, in an inner block, unnamed, and with
   explicit narrowed locals/casts: each moved the mask before the two lhu
   loads (nd 10); mixed third s32/fourth u16 gave nd 6. O1, schedule off,
   and function-pointer casts did not improve it. Best body remains archived
   at build/D178_00178870_body.c; committed form is bare INCLUDE_ASM. */






// FUN_001789D0
s32 func_001789d0(void)
{
    func_002bd410();
    func_002bd3c0();
    return 1;
}
// FUN_00178A00
s32 func_00178a00(void)
{
    scrSetReturnInt(*(u16 *)(D_007643D0 + 0xC));
    return 1;
}
// FUN_00178A30
s32 func_00178a30(void)
{
    u16 temp_3_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(D_007643D0 + 0x160);
    if (*(s32 *)(temp_3 + 8) != 0) {
        scrSetReturnInt(4);
    } else {
        temp_3_2 = *(u16 *)(temp_3 + 2);
        if ((s32)temp_3_2 >= 0x500) {
            scrSetReturnInt(3);
        } else if ((s32)temp_3_2 >= 0x400) {
            scrSetReturnInt(2);
        } else if ((s32)temp_3_2 >= 0x300) {
            scrSetReturnInt(1);
        } else {
            scrSetReturnInt(0);
        }
    }
    return 1;
}
// FUN_00178AF0
s32 func_00178af0(void)
{
    scrSetReturnInt((*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 7) & 1) != 0);
    return 1;
}
/* measured: plain C body is object 64B in a 64B window; only the retail
   GP load versus zero-argument materialisation order remains (nd 6).
   Committed at nd 6. */
// FUN_00178B30
s32 func_00178b30(void)
{
  s32 value;
  s32 result;
  u8 *state = D_007643D0;
  if (value && value) {}
  result = 0;
  value = *(s32 *)(*(u8 **)(state + 0x160) + 8);
  if (value)
    result = value;
  scrSetReturnInt(result);
  return 1;
}
// FUN_00178B70
s32 func_00178b70(void)
{
    scrSetReturnInt(*(u16 *)(*(u8 **)(D_007643D0 + 0x160) + 2));
    return 1;
}
// FUN_00178BA0
s32 func_00178ba0(void)
{
    scrSetReturnInt((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 6));
    return 1;
}
// FUN_00178BD0
s32 func_00178bd0(void)
{
    scrSetReturnInt((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 4));
    return 1;
}
// FUN_00178C00
/* Returns the stored constant: retail materializes the 1 in $v0 and stores
   from there, which only happens when it is also the return value. */
s32 func_00178c00(void)
{
    *(s32 *)(D_007643D0 + 8) = 1;
    D_007643D0 = 0;
    return 1;
}



/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). That span and its helpers
   0x0017ACC0 and 0x0017B350 now live in src/Kosaka/k_shadow.c. The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0 and is not merged with it. */

typedef struct RwV3d { f32 x, y, z; } RwV3d;
struct RwMatrixTag;
struct RpWorld;
struct RpWorldSector;
struct RpIntersection;
struct RpCollisionTriangle;
struct Resrc;
typedef struct FldShadowProjectionWork FldShadowProjectionWork;
typedef struct FldShadowAtomicContext {
    void *geometry;
    FldShadowProjectionWork *work;
    void *atomic;
} FldShadowAtomicContext;
enum RwOpCombineType
{
    rwCOMBINEREPLACE = 0,   /**<Replace -
                                all previous transformations are lost */
    rwCOMBINEPRECONCAT,     /**<Pre-concatenation -
                                the given transformation is applied
                                before all others */
    rwCOMBINEPOSTCONCAT,    /**<Post-concatenation -
                                the given transformation is applied
                                after all others */
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7fffffff
};
enum RwPrimitiveType
{
    rwPRIMTYPENAPRIMTYPE = 0,   /**<Invalid primative type */
    rwPRIMTYPELINELIST = 1,     /**<Unconnected line segments, each line is specified by
                                 * both its start and end index, independently of other lines
                                 * (for example, 3 segments specified as 0-1, 2-3, 4-5) */
    rwPRIMTYPEPOLYLINE = 2,     /**<Connected line segments, each line's start index
                                 * (except the first) is specified by the index of the end of
                                 * the previous segment (for example, 3 segments specified as
                                 * 0-1, 1-2, 2-3) */
    rwPRIMTYPETRILIST = 3,      /**<Unconnected triangles: each triangle is specified by
                                 * three indices, independently of other triangles (for example,
                                 * 3 triangles specified as 0-1-2, 3-4-5, 6-7-8) */
    rwPRIMTYPETRISTRIP = 4,     /**<Connected triangles sharing an edge with, at most, one
                                 * other forming a series (for example, 3 triangles specified
                                 * as 0-2-1, 1-2-3-, 2-4-3) */
    rwPRIMTYPETRIFAN = 5 ,      /**<Connected triangles sharing an edge with, at most,
                                 * two others forming a fan (for example, 3 triangles specified
                                 * as 0-2-1, 0-3-2, 0-4-3) */
    rwPRIMTYPEPOINTLIST = 6,    /**<Points 1, 2, 3, etc. This is not
                                 * supported by the default RenderWare
                                 * immediate or retained-mode pipelines
                                 * (except on PlayStation 2), it is intended
                                 * for use by user-created pipelines */
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7fffffff
};
struct _RxObjSpace3DVertex;
/* Retain the source's existing function-scoped propagation setting. */
#pragma opt_propagation off
// FUN_00179FC0
s32 func_00179fc0(u8 *arg0, s32 arg1, s32 arg2, void *arg3, f32 farg0, f32 farg1, s32 arg4, u8 *arg5) {
    extern struct RwMatrixTag *func_003e0960(struct RwMatrixTag *, const struct RwMatrixTag *);
    extern struct RwMatrixTag *RwMatrixScale(struct RwMatrixTag *, const RwV3d *, enum RwOpCombineType);
    extern struct RwMatrixTag *RwMatrixTranslate(struct RwMatrixTag *, const RwV3d *, enum RwOpCombineType);
    extern s32 FldFrameTask_GetTileX(u8 *);
    extern s32 FldFrameTask_GetTileZ(u8 *);
    extern void *func_00410420(struct _RxObjSpace3DVertex *, u32, struct RwMatrixTag *, u32);
    extern s32 func_004106a0(enum RwPrimitiveType);
    extern s32 func_004104d0(void);
    RwV3d scale;
    RwV3d translation;
    FldShadowAtomicContext ctx;
    u16 ids[8];
    u8 *allocs[8];
    f32 f21;
    u8 *tmp;
    u8 *p;
    s32 v1;
    s32 v2;
    s32 gp_val;
    u8 *alloc;
    void *v;
    FieldRenderStateSetFunction *base;
    s32 outerIndex;
    s32 count;
    tmp = MT_Scene_GetResListHead(0xC);
    base = D_00887300;
    base[0]((RwRenderState)(1), (void *)(arg1));
    base[0]((RwRenderState)(2), (void *)(3));
    base[0]((RwRenderState)(0xC), (void *)(1));
    base[0]((RwRenderState)(9), (void *)(2));
    base[0]((RwRenderState)(0xA), (void *)(5));
    if (farg0 < 0.0f) {
        farg0 = -farg0;
        base[0]((RwRenderState)(0xB), (void *)(5));
    } else {
        base[0]((RwRenderState)(0xB), (void *)(6));
    }
    p = *(u8 **)(arg0 + 4) + 0x10;
    *(RwV3d *)(arg5 + 0x5470) = *(RwV3d *)(p + 0x20);
    f21 = *(f32 *)(arg0 + 0x68);
    func_003e0960((struct RwMatrixTag *)(arg5 + 0x5480), (struct RwMatrixTag *)p);
    scale.y = -0.5f / f21;
    scale.x = scale.y;
    scale.z = 1.0f / (farg1 + f21);
    RwMatrixScale((struct RwMatrixTag *)(arg5 + 0x5480), &scale, rwCOMBINEPOSTCONCAT);
    translation.y = 0.5f;
    translation.x = 0.5f;
    translation.z = 0.0f;
    RwMatrixTranslate((struct RwMatrixTag *)(arg5 + 0x5480), &translation, rwCOMBINEPOSTCONCAT);
    *(s32 *)(arg5 + 0x54C4) = arg4;
    {
        const u8 alpha = (u8)(255.0f * farg0);
        *(u8 *)(arg5 + 0x54C0) = alpha;
    }
    *(s32 *)(arg5 + 0x54C8) = 0;
    *(u32 *)(arg5 + 0x5460) = 0;
    if (arg2 == 0) {
        p = *(u8 **)(tmp + 0x1A0);
        {
            void *preferred = *(void **)(p + 0x10);
            if (preferred != NULL)
                v = preferred;
            else
                v = *(void **)(p + 8);
        }
        func_00394d70(v, arg3, func_001791d0, arg5);
    } else if (arg2 == 1) {
        count = 0;
        ctx.geometry = arg3;
        ctx.work = (FldShadowProjectionWork *)arg5;
        if (func_0014a200() == 1) goto alloc_path;
        gp_val = *(s32 *)iGpffff9db0;
        if (gp_val < 0x33) goto check_second;
        if (gp_val <= 0x3A) goto alloc_path;
check_second:
        if (gp_val < 0x47) goto else_path;
        if (gp_val >= 0x4F) goto else_path;
        goto alloc_path;
alloc_path:
        {
            alloc = (u8 *)MT_Scene_GetRes(0x400);
            if (alloc == NULL) {
                return 0;
            }
            v1 = FldFrameTask_GetTileX(*(u8 **)(alloc + 0x220));
            v2 = FldFrameTask_GetTileZ(*(u8 **)(alloc + 0x220));
            v2 = v2 * 0x100;
            v1 = v1 * 0x10;
            ids[0] = *(u16 *)((u8 *)func_00155280() + v2 + v1 + 0x56);
            allocs[0] = (u8 *)MT_Scene_GetRes(ids[0]);
            if (allocs[0] != NULL) {
                count++;
            }
            ids[1] = *(u16 *)((u8 *)func_00155280() + v2 + v1 + 0x66);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[1];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[1]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[2] = *(u16 *)((u8 *)func_00155280() + v2 + v1 + 0x46);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[2];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[2]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[3] = *(u16 *)((u8 *)func_00155280() + v2 + v1 + 0x156);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[3];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[3]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[4] = *(u16 *)((u8 *)func_00155280() + v2 + v1 - 0xAA);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[4];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[4]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            goto join_path;
        }
else_path:
        allocs[0] = tmp;
        count++;
join_path:;
        {
            for (outerIndex = 0; outerIndex < count; outerIndex++) {
                u8 **entry = &allocs[outerIndex];
                u8 *object = *entry;
                void *clump = *(void **)(*(u8 **)(object + 0x1A0) + 0x10);
                if (clump != NULL) {
                    RpClumpForAllAtomics(clump, func_00179f70, &ctx);
                } else {
                    u32 k;
                    for (k = 0; k < *(u32 *)(*(u8 **)(object + 0x1A0) + 0x18); k++) {
                        RpClumpForAllAtomics(*(void **)(*(u8 **)(*entry + 0x1A0) + k * 4 + 0x1C),
                                             func_00179f70, &ctx);
                    }
                }
            }
        }
    }
    *(u32 *)(arg5 + 0x5464) = (*(u32 *)(arg5 + 0x5460) + *(u32 *)(arg5 + 0x54C8) * 600) / 3U;
    if (*(u32 *)(arg5 + 0x5460) != 0) {
        FieldRenderStateSetFunction *drawBase = D_00887300;
        drawBase[0]((RwRenderState)(1), (void *)(arg1));
        drawBase[0]((RwRenderState)(0xE), (void *)(0));
        drawBase[0]((RwRenderState)(6), (void *)(1));
        drawBase[0]((RwRenderState)(8), (void *)(0));
        if (func_00410420((struct _RxObjSpace3DVertex *)arg5, *(u32 *)(arg5 + 0x5460), 0, 0x19) != 0) {
            func_004106a0(rwPRIMTYPETRILIST);
            func_004104d0();
        }
        if (iGpffffba48 == 1) {
            base[0]((RwRenderState)(0xE), (void *)(1));
        }
        *(u32 *)(arg5 + 0x5460) = 0;
    }
    base = D_00887300;
    base[0]((RwRenderState)(0xB), (void *)(6));
    base[0]((RwRenderState)(0xA), (void *)(5));
    return 1;
}
#pragma opt_propagation on
// FUN_0017A700
/* measured: opt_propagation off preserves the second-branch descriptor
   pointer materialisation and grouped float-load order; object matches
   the 464-byte retail window. */
#pragma opt_propagation off
void func_0017a700(u8 *arg0, u8 *arg1)
{
    struct
    {
        f32 values[6];
        s32 type;
    } sp40;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f0;
    f32 *temp_3;
    u8 *temp_17;
    u8 *temp_2;

    temp_17 = MT_Scene_GetResListHead(0xC);
    sp40.type = 4;
    temp_f20 = *(f32 *)(arg1 + 0x18);
    sp40.values[0] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x30);
    sp40.values[1] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x34);
    sp40.values[2] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x38);
    sp40.values[3] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x30) - temp_f20;
    sp40.values[4] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x34) - temp_f20;
    sp40.values[5] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x38) - temp_f20;
    if (temp_17 != NULL) {
        if ((*(s32 *)(*(u8 **)(temp_17 + 0x1A0)) & 1) != 0) {
            func_00179fc0(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          0,
                          &sp40,
                          1.0f,
                          *(f32 *)(arg1 + 0x18) / 2.0f,
                          0,
                          *(u8 **)(arg1 + 0x4C));
        } else {
            sp40.type = 3;
            temp_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
            temp_3 = sp40.values;
            temp_f2 = *(f32 *)(temp_2 + 0x30);
            temp_f1 = *(f32 *)(temp_2 + 0x34);
            temp_f0 = *(f32 *)(temp_2 + 0x38);
            sp40.values[0] = temp_f2;
            sp40.values[1] = temp_f1;
            sp40.values[2] = temp_f0;
            temp_f1 = *(f32 *)(arg1 + 0x18);
            sp40.values[3] = temp_f1;
            func_00179fc0(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          1,
                          temp_3,
                          1.0f,
                          temp_f1 / 2.0f,
                          0,
                          *(u8 **)(arg1 + 0x4C));
        }
        if (iGpffffba48 == 1)
            D_00887300[0]((RwRenderState)0xE, (void *)1);
    }
}
#pragma opt_propagation on
// FUN_0017A8D0
void func_0017a8d0(u8 *arg0, u8 *arg1)
{
    u8 stack[0x6C];
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s8 *var_3;
    s32 var_2;
    s32 var_4_2;
    u8 *var_6;
    s32 var_5;
    u8 *temp_2_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *var_2_2;
    u8 *var_6_2;
    u8 *var_5_2;
    s32 var_4;

    var_3 = (s8 *)(stack + 0x60);
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    var_2_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    var_6 = arg1 + 0x80;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_2_2 + 0);
        temp_3 = *(s32 *)(var_2_2 + 4);
        var_2_2 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    var_6_2 = arg1 + 0x80;
    var_5_2 = stack;
    var_4 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4 -= 1;
        *(s32 *)(var_5_2 + 0) = temp_3_2;
        *(s32 *)(var_5_2 + 4) = temp_2;
        var_5_2 += 8;
    } while (var_4 > 0);
    if (!(*(f32 *)(arg1 + 0xCC) <= *(f32 *)(arg1 + 0xD4))) {
        *(s32 *)(stack + 0x50) = 0x3F800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0xBF800000;
        temp_f0 = *(f32 *)(arg1 + 0xC8);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x38);
        *(f32 *)(stack + 0x38) = temp_f1 - temp_f0;
    } else {
        *(s32 *)(stack + 0x50) = 0xBF800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0x3F800000;
        temp_f0 = *(f32 *)(arg1 + 0xC0);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x30);
        *(f32 *)(stack + 0x30) = temp_f1 - temp_f0;
    }
    var_4_2 = 0;
    goto loop_11_cond;
loop_11_body:
    temp_3_3 = *(u8 **)(arg1 + 0x10) + (var_4_2 * 0xC);
    *(u8 *)(temp_3_3 + 0x28C) &= ~1;
    var_4_2 += 1;
loop_11_cond:
    if (var_4_2 < 5)
        goto loop_11_body;
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 4;
    mdlScale(*(u8 **)(arg1 + 0x10), stack + 0x50, 2);
    temp_2_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    temp_f1 = *(f32 *)(stack + 0x30);
    temp_f0 = *(f32 *)(stack + 0x34);
    temp_f2 = *(f32 *)(stack + 0x38);
    *(f32 *)(temp_2_2 + 0x30) = temp_f1;
    *(f32 *)(temp_2_2 + 0x34) = temp_f0;
    *(f32 *)(temp_2_2 + 0x38) = temp_f2;
    RwEngineGetMatrixTolerances((f32 *)(stack + 0x40));
    RwMatrixOptimize(mdlGetMatrix(*(u8 **)(arg1 + 0x10)),
                  (f32 *)(stack + 0x40));
    RwMatrixUpdate(mdlGetMatrix(*(u8 **)(arg1 + 0x10)));
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 0x40;
    func_004789c0(*(u8 **)(arg1 + 0x10));
    func_0047a320(*(u8 **)(arg1 + 0x10));
}
// FUN_0017AAE0
void func_0017aae0(u8 *arg0, u8 *arg1)
{
    u8 *var_5;
    s32 temp_3;
    s32 temp_4_2;
    s32 var_6;
    s32 var_5_2;
    u8 *temp_4;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *var_2;

    temp_4 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4 + 0xD8) &= ~0x40;
    D_00887300[0]((RwRenderState)0x14, (void *)2);
    var_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    var_5 = arg1 + 0x80;
    var_5_2 = 8;
    do {
        temp_4_2 = *(s32 *)var_5;
        temp_3 = *(s32 *)(var_5 + 4);
        var_5 += 8;
        var_5_2 -= 1;
        *(s32 *)var_2 = temp_4_2;
        *(s32 *)(var_2 + 4) = temp_3;
        var_2 += 8;
    } while (var_5_2 > 0);
    temp_4_3 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4_3 + 0xD8) &= ~4;
    func_004789c0(*(u8 **)(arg1 + 0x10));
    func_0047a320(*(u8 **)(arg1 + 0x10));
    var_5_2 = 0;
    goto loop_4_cond;
loop_4_body:
    temp_4_4 = *(u8 **)(arg1 + 0x10) + (var_5_2 * 0xC);
    *(u8 *)(temp_4_4 + 0x28C) |= 1;
    var_5_2 += 1;
loop_4_cond:
    if (var_5_2 < 5)
        goto loop_4_body;
}
// FUN_0017ABD0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
#pragma opt_propagation off
void func_0017abd0(u8 *arg0, u8 *arg1)
{
    FieldRenderStateSetFunction *base;
    u8 *temp_4;

    base = D_00887300;
    base[0]((RwRenderState)7, (void *)2);
    base[0]((RwRenderState)6, (void *)1);
    base[0]((RwRenderState)8, (void *)0);
    if (iGpffffba48 == 1) {
        base[0]((RwRenderState)0xE, (void *)1);
    }
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    temp_4 = *(u8 **)(*(u8 **)(arg1 + 0x50) + 4);
    (*(void (**)(u8 *))(temp_4 + 0x48))(temp_4);
    if (iGpffffba48 == 1) {
        base[0]((RwRenderState)0xE, (void *)1);
    }
}
/* measured: closing opt_propagation bracket for func_0017abd0. */
#pragma opt_propagation on
typedef struct RwSphere { RwV3d center; f32 radius; } RwSphere;
struct RpGeometry;
struct RpTriangle;
struct RpMorphTarget;

extern u8 D_005F18D0[];
extern const u64 D_005F18B0;
extern const f32 D_005F18B8;
extern u8 *func_003ef2e0(void *raster);
extern u8 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003e84a0(void);
extern struct RwFrame *func_003e9320(void);
extern struct RwFrame *func_003e9df0(struct RwFrame *frame);
extern void *RwCameraSetProjectionType(void *camera, s32 projection);
extern void func_001790a0(void *camera);
extern void *func_003cbc10(s32 world, void *camera);
extern f32 fabsf(f32 x);



#pragma opt_propagation on
#pragma opt_loop_invariants off
/* 764/768 bytes; fourteen resolved relocations; four zero alignment bytes.
 * Preserve unsigned frame updates and the three ordered sprite draws. */
// FUN_0017CD60
s32 func_0017cd60(u8 *arg0)
{
    u8 *work;
    f32 easing;
    f32 inverse;
    f32 frame;
    s32 opacity;
    u16 counter;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 8) = (s32)func_0046a770(D_005E5850);
        *(u16 *)(work + 0xC) = 320;
        *(u16 *)(work + 0xE) = 240;
        *(s32 *)work = *(s32 *)work + 1;
        goto done;
    case 1:
        counter = *(u16 *)(work + 0x10);
        frame = (f32)(u16)counter;
        easing = sinf((iGpffff82fc * frame) / 15.0f);
        inverse = 1.0f - easing;
        func_0025ecd0((f32)(*(u16 *)(work + 0xC) + 10),
                      (f32)(*(u16 *)(work + 0xE) + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        opacity = (s32)(128.0f * easing) + 0x80;
        x = (f32)(*(u16 *)(work + 0xC) + 0x6E);
        y = (f32)(*(u16 *)(work + 0xE) + 0x22);
        opacity = (0xFF < opacity) ? 0xFF : opacity;
        func_0025ecd0(x, y, 1000.0f,
                      0xFFFFFF, opacity & 0xFF, 0xC6, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0((f32)(*(u16 *)(work + 0xC) + 0x6E),
                      (f32)(*(u16 *)(work + 0xE) + 0xF +
                            (s32)(3.0f * inverse)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        counter = *(u16 *)(work + 0x10) + 1;
        *(u16 *)(work + 0x10) = counter;
        if (0xF < *(u16 *)(work + 0x10)) {
            *(u16 *)(work + 0x10) = 0;
        }
        goto done;
    case 2:
        return -1;
    default:
        goto done;
    }
done:
    return 0;
}
// FUN_0017D060
void func_0017d060(u8 *arg0)
{
}
// FUN_0017D070
s32 func_0017d070(u8 *arg0)
{
    memset(D_007F1740, 0, 0x20);
    return (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F1950), 0x12, 0, 0, func_0017cd60, func_0017d060, (u8 *)(D_007F1740));
}
// FUN_0017D0F0
void func_0017d0f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017D100
void func_0017d100(u8 *arg0)
{
    F2_0017 sp30;
    f32 temp_f1;
    s32 temp_17;
    s32 temp_4;
    s32 var_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = (s32)(func_00457120() + 0x20);
    func_003e42a0(&sp30, (u8 *)mdlGetMatrix(*(u8 **)D_007EFA00) + 0x30, (u8 *)temp_17);
    temp_f1 = 640.0f * (sp30.first / sp30.second);
    if (temp_f1 <= 100.0f) {
        var_3 = 0;
    } else if (temp_f1 < 540.0f) {
        var_3 = 1;
    } else {
        var_3 = 2;
    }
    temp_4 = var_3 * 8;
    *(s16 *)(temp_16 + 0xC) = *(s32 *)((u8 *)D_005F1930 + temp_4);
    *(s16 *)(temp_16 + 0xE) = *(s32 *)((u8 *)D_005F1934 + temp_4);
}
// FUN_0017D1F0
void func_0017d1f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                   f32 arg5, f32 arg6, f32 arg7, s32 arg4)
{
    s32 temp_3;

    temp_3 = arg2 * 8;
    func_0017d240(arg0, arg1, arg2, arg3,
                  *(s32 *)(D_005F1A60 + temp_3) + 1,
                  *(s32 *)(D_005F1A64 + temp_3) + 1, arg4,
                  arg5, arg6, arg7);
}
/* measured: optimization_level 1 is required for func_0017d240 codegen. */
#pragma optimization_level 1
// FUN_0017D240
void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9)
{
    struct {
        u8 data[0x10];
        u8 tail[0x10];
    } spA0;
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_6;
    s32 local_5;
    s32 local_4;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21 = (f32)arg4;
    f32 temp_f20 = (f32)arg5;
    f32 *temp_9;
    s32 temp_2;
    s32 temp_1;
    s32 temp_18;
    local_0 = arg0;
    local_1 = arg1;
    local_2 = arg2;
    temp_f24 = arg7;
    temp_f23 = arg8;
    temp_f22 = arg9;
    local_6 = arg4;
    local_5 = arg5;
    local_4 = arg6;
    if (arg3 == 0) {
        sprintf(spA0.data, D_005F1AE0);
    } else {
        sprintf(spA0.data, D_005F1B00);
    }
    temp_18 = local_2 * 0x10;
    temp_f21 = (f32)local_6;
    temp_f20 = (f32)local_5;
    temp_1 = func_003ef6d0();
    temp_2 = func_003ef650(temp_1, spA0.data);
    func_0014def0(local_0, local_1,
                  temp_f24, temp_f23, temp_f22, temp_f21, temp_f20,
                  (void *)&iGpffff9f54, temp_2,
                  *(f32 *)(temp_9 = (f32 *)(D_005F1970 + temp_18)),
                  *(f32 *)(D_005F1974 + temp_18),
                  *(f32 *)(D_005F1978 + temp_18),
                  local_4, temp_9,
                  *(f32 *)(D_005F197C + temp_18));
}
/* measured: restore optimization_level 2 after func_0017d240. */
#pragma optimization_level 2

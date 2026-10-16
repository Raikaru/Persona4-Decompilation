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
extern void func_004a5fc0(u8 *arg0);
extern u8 *func_004a6c00(u8 *arg0);
extern u8 *WindAllocKindEntry(u16 arg0, u8 *arg1);
extern u8 D_0071413C[];
extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
extern void func_00492e30(u16 *emitter, f32 scale);
extern s32 TnGetOffset38(u16 arg0);
extern void func_004ad030();
extern void func_004adb50();
extern void func_004ade80(u8 *arg0);
extern void func_00460ac0();
extern void ObjectParticleUpdateRecords();
extern f32 iGpffff8080;
extern void mdlDestroyModelObject();

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern void kAssertFail(u8 *arg0, s32 arg1);
extern s32 func_003e9320(void);
extern s32 func_00457120(void);
extern void func_003e9830(s32 arg0, s32 arg1);
extern f32 D_00922D80[];
extern u8 *func_00401b80(void);
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
extern u8 *func_003e9c10(u8 *arg0, const f32 *translation, s32 combineOp);

extern void func_004a7c00(u8 *arg0, s32 arg1);

extern void mdlSetLayerTime(u8 *arg0, s32 arg1, f32 arg2);

extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void memcpy(void *dst, void *src, u32 size);
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
 
extern void primQuad3D(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void primAxisLine3D(f32 *arg0, s32 arg1, f32 arg2);
extern s32 mdlCopyIndexedMatrix(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00485870(s32 arg0);
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void memset(void *dst, s32 value, u32 size);
extern void func_003c22f0();
extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern void func_003c42b0(void *arg0, s32 arg1);
extern void func_004a5ef0(u8 *arg0, u8 *arg1);
extern u8 *GeometryCloneBlock(s32 arg0);
extern s32 TnSlotObject(u16 arg0);
extern s32 func_00481d80(u16 *arg0);
extern s32 TlpCreate(u16 *arg0);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void TlpRelease(s32 arg0);
extern s32 TlpAddRef(s32 arg0);
extern void mdlInitIdentityMatrix(void *arg0);
extern s32 mdlLayerIsPresent(void *arg0, s32 arg1);
extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
extern void mdlSetResetCallback(void *arg0, void (*arg1)(void), void *arg2);
extern void EffModelResetCallback(void);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes func_004a1950 MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.
extern u8 *FlashQuadCopyAlloc(u16 arg0, s32 arg1);

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
extern void *mdlCreateModelObjectFromMemory(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern void func_00485fe0(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *);




// FUN_004A18E0
void func_004a18e0(u8 *arg0) {
    (*(void (**)(u8 *))(D_00714018 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(*(u8 **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
// FUN_004A1AA0
void func_004a1aa0(u8 *arg0) {
    (*(void (**)(void))(D_00714010 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}
// FUN_004A1AF0
void func_004a1af0(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
}
// FUN_004A1B50
void func_004a1b50(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}
// FUN_004A1BA0
void func_004a1ba0(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(u8 *))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}
// FUN_004A1C30
u_long128 func_004a1c30(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A1C40
u_long128 func_004a1c40(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A1C50
void func_004a1c50(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}
// FUN_004A1C60
void func_004a1c60(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}
// FUN_004A1C80
void func_004a1c80(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
/* measured: restores the file's O2 loop-invariant baseline. */
#pragma opt_loop_invariants off
// FUN_004A58B0
void func_004a58b0(u8 *arg0)
{
    (*(void (**)(u8 *))(D_00714138 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    jtbl_008873EC[0](arg0);
}

// FUN_004A5910
void *func_004a5910(void *source)
{
    u8 *arg0 = (u8 *)source;
    u8 *temp_16;

    temp_16 = WindAllocKindEntry(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
    *(s32 *)(temp_16 + 0x3C) =
        (*(s32 (**)(u8 *))(D_0071413C + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    (*(void (**)(u8 *))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(temp_16);
    return temp_16;
}
// FUN_004A59B0
void func_004a59b0(u8 *arg0)
{
    (*(void (**)(void))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}

// FUN_004A5A00
void func_004a5a00(u8 *arg0)
{
    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}

// FUN_004A5A60
void func_004a5a60(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}

// FUN_004A5AB0
void func_004a5ab0(u8 *arg0)
{
    s32 temp_3;

    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    temp_3 = *(s32 *)(arg0 + 0x34) + 1;
    *(s32 *)(arg0 + 0x34) = temp_3;
    if (temp_3 > 0) {
        (*(void (**)(u8 *))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}
// FUN_004A5B40
u_long128 func_004a5b40(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A5B50
u_long128 func_004a5b50(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A5B60
void func_004a5b60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x30) = arg1;
}

/* measured: the jump table must be called through the pointer -- `jtbl_x(a)` is
   an implicit function call to the table SYMBOL, which links and runs wrong. */

// FUN_004A5B70
void func_004a5b70(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}

// FUN_004A5B90
void func_004a5b90(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}

extern void *func_004a5bb0(void *source);

// FUN_004A5DE0
void func_004a5de0(u8 *arg0) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = (s32)(*(s32 *)((u8 *)(arg0) + 0xCC));
    if (temp_4 != 0) {
        TlpRelease(temp_4);
    }
    temp_4_2 = (s32)(*(s32 *)((u8 *)(arg0) + 0xD0));
    if (temp_4_2 != 0) {
        func_00481ee0(temp_4_2);
    }
    GeometryBlockDestroy(*(s32 *)((u8 *)(arg0) + 0xC8));
    (*jtbl_008873EC)(arg0);
}

// FUN_004A5E50
void *func_004a5e50(void *source)
{
    u8 *arg0 = (u8 *)source;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_3;

    temp_16 = func_004a5bb0(NULL);
    temp_2 = GeometryCloneBlock(*(s32 *)(arg0 + 0xC8));
    *(u8 **)(temp_16 + 0xC8) = temp_2;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x10) + 0x18) + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    memcpy(temp_16 + 0x30, arg0 + 0x30, 0x98);
    func_004a5ef0(temp_16, arg0);
    return temp_16;
}
// FUN_004A5EF0
void func_004a5ef0(u8 *arg0, u8 *arg1)
{
    s32 temp_4;
    s32 temp_4_2;

    if (*(s32 *)(arg1 + 0xD0) != 0) {
        temp_4 = *(s32 *)(arg0 + 0xD0);
        if (temp_4 != 0) {
            func_00481ee0(temp_4);
        }
        *(s32 *)(arg0 + 0xD0) = func_00481e30(*(s32 *)(arg1 + 0xD0));
        return;
    }
    if (*(s32 *)(arg1 + 0xCC) != 0) {
        temp_4_2 = *(s32 *)(arg0 + 0xCC);
        if (temp_4_2 != 0) {
            TlpRelease(temp_4_2);
        }
        *(s32 *)(arg0 + 0xCC) = TlpAddRef(*(s32 *)(arg1 + 0xCC));
    }
}
// FUN_004A5F90
void func_004a5f90(u8 *arg0)
{
    *(s32 *)(arg0 + 0x2C) = 0;
}

// FUN_004A5FA0
void func_004a5fa0(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
}
/* Billboard sprite update. The particle colour is the base colour times the
 * animated tint, packed by the COP2 block. Its store to the packed slot is
 * part of that asm; b210 forwards any compiler-side store, and retail reloads
 * the slot. The UV corner/rect/size block is one frame-info struct, as the
 * retail frame layout shows. GeometryBlockBindResource is declared with an int
 * second parameter because retail loads the halfword before setting up $a0.
 * GeometryBlockSetFrameMatrix takes four arguments here: retail sets $a1, $a2
 * and $f12, which its one-parameter definition forwards untouched to
 * GeometryMatrixBuild. */
typedef struct EffSpriteFrame {
    f32 rect[4];
    u32 size[2];
    u16 corner[8];
} EffSpriteFrame;

typedef struct EffSpriteRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} EffSpriteRGBA;

// FUN_004A6B90
void func_004a6b90(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
    func_004a5fc0(arg0);
}
// FUN_004A6BC0
u_long128 func_004a6bc0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A6BD0
u_long128 func_004a6bd0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A6BE0
void func_004a6be0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004A6BF0
void func_004a6bf0(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}
#pragma opt_loop_invariants on
/* measured: close loop-invariant hoisting after func_004a6c00. */
#pragma opt_loop_invariants off
// FUN_004A6D90
void *func_004a6d90(void *source) {
    u8 *temp;
    temp = mdlEffectResolveRelPtrA(source);
    return func_004a6c00(temp);
}
// FUN_004A6DC0
void func_004a6dc0(u8 *arg0)
{
    func_004841c0(*(s32 *)(arg0 + 0x58));
    jtbl_008873EC[0](arg0);
}

// FUN_004A6E10
void *func_004a6e10(void *source) {
    u8 *arg0 = (u8 *)source;
    return func_004a6c00(arg0 + 0x18);
}
// FUN_004A6E40
void func_004a6e40(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}


#pragma push
#pragma optimization_level 3
#pragma schedule off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma tailcall off
#pragma opt_common_subs off
#pragma opt_propagation off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}




// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}





// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}






// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
// FUN_004A8A50
void func_004a8a50(u8 *arg0, u8 *arg1)
{
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    u8 *temp_16;

    *(u32 *)arg1 = effMiscRand(0) % (u32)(*(s32 *)(arg0 + 4) + 1);
    *(f32 *)(arg1 + 4) = fGpffff80f4;
    temp_16 = arg1 + 8;
    *(s32 *)(arg1 + 0x10) = *(s32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(s32 *)(arg1 + 0xC) = *(s32 *)(arg0 + 0xC);
    temp_f20 = 0.5f * (f32)*(s32 *)(arg0 + 0x28);
    temp_f21 = *(f32 *)(arg0 + 0x24);
    temp_f22 = *(f32 *)(arg0 + 0x1C) +
               temp_f21 * (2.0f * (effMiscRandFloat(0) - 0.5f));
    temp_f1 = *(f32 *)(arg0 + 0x20) +
              temp_f21 * (2.0f * (effMiscRandFloat(0) - 0.5f));
    *(f32 *)(temp_16 + 0x14) = temp_f22;
    *(f32 *)(temp_16 + 0x18) = temp_f1;
    *(f32 *)(temp_16 + 0x1C) = temp_f22 - temp_f20;
    *(f32 *)(temp_16 + 0x20) = temp_f1 - temp_f20;
    *(f32 *)(temp_16 + 0x24) = temp_f22 + temp_f20;
    *(f32 *)(temp_16 + 0x28) = temp_f1 + temp_f20;
}
// FUN_004ABB60
void func_004abb60(void)
{
    u8 *temp_2;

    temp_2 = func_00401b80();
    *(u8 **)&D_00922D90[0] = temp_2;
    D_00922D94[0] = (f32)*(s32 *)(temp_2 + 0xC);
    D_00922D98[0] = (f32)*(s32 *)(temp_2 + 0x10);
}

#pragma push
#pragma opt_propagation off
#pragma pop


// FUN_004ADAB0
void func_004adab0(u8 *arg0)
{
    s32 *var_18;
    u32 temp_16;
    u32 var_17;

    if (*(s32 *)(arg0 + 0x9C) != 0) {
        temp_16 = *(u32 *)(arg0 + 0x28);
        var_18 = *(s32 **)(arg0 + 0x98);
        var_17 = 0;
        goto loop_004adab0_check;
loop_004adab0_body:
        func_00485fe0(*var_18);
        var_18++;
        var_17 += 1;
loop_004adab0_check:
        if (var_17 < temp_16) {
            goto loop_004adab0_body;
        }
    }
    mdlSetLayerTime((u8 *)*(s32 *)(arg0 + 0xA0), 0, 0.0f);
    *(s32 *)(arg0 + 0x2C) = 0;
}
// FUN_004ADE80
void func_004ade80(u8 *arg0)
{
    u8 frame[0x50];
    s32 *var_16_2;
    s32 temp_4;
    u32 temp_18;
    u32 var_16;
    u32 var_17;

    if (*(s32 *)(arg0 + 0x9C) == 0) {
        *(u8 *)(frame + 0x4C) = 0xFF;
        *(u8 *)(frame + 0x4D) = 0xFF;
        *(u8 *)(frame + 0x4E) = 0;
        *(u8 *)(frame + 0x4F) = 0xFF;
        var_16 = 0;
        goto loop_004ade80_a_check;
loop_004ade80_a_body:
        if (mdlCopyIndexedMatrix(*(u8 **)(arg0 + 0xA0), var_16, frame) != 0) {
            primQuad3D((f32 *)(frame + 0x30), frame + 0x4C, 1, 4.0f);
            primAxisLine3D((f32 *)frame, 1, 30.0f);
        }
        var_16 += 1;
loop_004ade80_a_check:
        if (var_16 < (u32)*(u32 *)(arg0 + 0x28)) {
            goto loop_004ade80_a_body;
        }
        return;
    }
    temp_4 = *(s32 *)(arg0 + 0x90);
    temp_18 = *(u32 *)(arg0 + 0x28);
    var_16_2 = *(s32 **)(arg0 + 0x98);
    if ((*(s32 *)(arg0 + 0x2C) < temp_4) || (temp_4 == 0)) {
        var_17 = 0;
        goto loop_004ade80_b_check;
loop_004ade80_b_body:
        func_00485870(*var_16_2);
        var_16_2++;
        var_17 += 1;
loop_004ade80_b_check:
        if (var_17 < temp_18) {
            goto loop_004ade80_b_body;
        }
    }
}
// FUN_004ADFA0
void func_004adfa0(u8 *arg0) {
    func_004adb50();
    func_004ade80(arg0);
}
// FUN_004ADFE0
u_long128 func_004adfe0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004ADFF0
u_long128 func_004adff0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004AE000
void func_004ae000(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}
// FUN_004AE010
void func_004ae010(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}
// FUN_004AE0A0
void func_004ae0a0(u8 *arg0, u8 *arg1)
{
    f32 sp40[4];
    f32 temp_f0;
    s32 temp_4;

    if (*(u8 *)(arg0 + 0x10) == 0) {
        sp40[0] = *(f32 *)(arg0 + 0x14);
        sp40[1] = *(f32 *)(arg0 + 0x18);
        sp40[2] = *(f32 *)(arg0 + 0x1C);
    } else {
        sp40[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        sp40[1] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        sp40[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    }
    __asm__ volatile(
        "lqc2 $vf10, 0(%1) \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        ".word 0x4A0203BD \n"
        "vwaitq \n"
        "cfc2.ni $2, $vi22 \n"
        "mtc1 $2, %0 \n"
        : "=f"(temp_f0)
        : "r"(sp40)
        : "$2", "$vf2", "$vf10", "Q", "memory");
    if (temp_f0 == 0.0f) {
        goto normalized_zero;
    }
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(sp40)
        : "$vf0", "$vf2", "$vf10", "ACC", "Q", "memory");
    *(f32 *)(arg1 + 0) = sp40[0];
    *(f32 *)(arg1 + 4) = sp40[1];
    *(f32 *)(arg1 + 8) = sp40[2];
    goto normalized_done;
normalized_zero:
    *(f32 *)(arg1 + 0) = 0.0f;
    *(f32 *)(arg1 + 4) = 1.0f;
    *(f32 *)(arg1 + 8) = 0.0f;
normalized_done:
    temp_f0 = *(f32 *)(arg0 + 0x28);
    temp_f0 = (1.0f - temp_f0) + temp_f0 * effMiscRandFloat(0);
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg0 + 0x24) * temp_f0;
    *(f32 *)(arg1 + 0x0C) = iGpffff8080 * effMiscRandFloat(0);
    temp_4 = *(s32 *)(arg0 + 0x34);
    switch (temp_4) {
    case 1:
        *(u8 *)(arg1 + 0x14) = (u8)(effMiscRand(0) % 6);
        break;
    case 2:
        *(u8 *)(arg1 + 0x14) =
            (u8)(((u32)((u8 *)arg1 - *(u8 **)(arg0 + 0x5C)) / 0x18) % 6);
        break;
    default:
        *(s8 *)(arg1 + 0x14) = -1;
        break;
    }
}

// FUN_004AF5E0
void func_004af5e0(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(*(s32 *)(instance + 0x58), position);
}
// FUN_004AF610
void func_004af610(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(*(s32 *)(instance + 0x58), rotation);
}
// FUN_004AF640
void func_004af640(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x4) = arg1;
}
// FUN_004AF650
void func_004af650(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x8) = arg1;
    func_00492e30(*(u16 **)(arg0 + 0x58), arg1);
}

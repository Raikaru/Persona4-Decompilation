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
extern void EffSpriteUpdate(u8 *arg0);
extern u8 *func_004a6c00(u8 *arg0);
extern u8 *WindAllocKindEntry(u16 arg0, u8 *arg1);
extern u8 D_0071413C[];
extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
extern void func_00492e30(u16 *emitter, f32 scale);
extern s32 TnGetOffset38(u16 arg0);
extern void EffModelDrawableUpdate();
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
extern s32 kwlnGetCamera(void);
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




#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off





/* measured: the jump table must be called through the pointer -- `jtbl_x(a)` is
   an implicit function call to the table SYMBOL, which links and runs wrong. */



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


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
// FUN_004A6DC0
void func_004a6dc0(u8 *arg0)
{
    func_004841c0(*(s32 *)(arg0 + 0x58));
    jtbl_008873EC[0](arg0);
}



#pragma push
#pragma optimization_level 3
#pragma schedule off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma tailcall off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop


















#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

#pragma push
#pragma opt_propagation off
#pragma pop


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


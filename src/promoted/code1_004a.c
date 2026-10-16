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
extern u_long128 func_00492dd0(s32 emitter, u32 *position);
extern u_long128 func_00492e10(s32 emitter, u32 *rotation);
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
extern void func_0048a070(s64 arg);
extern void func_0048a0e0(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
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
extern s32 func_00482800(u16 *arg0);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void func_004829c0(s32 arg0);
extern s32 func_00482a70(s32 arg0);
extern void mdlInitIdentityMatrix(void *arg0);
extern s32 mdlLayerIsPresent(void *arg0, s32 arg1);
extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
extern void mdlSetResetCallback(void *arg0, void (*arg1)(void), void *arg2);
extern void func_004abe60(void);
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
        func_004829c0(temp_4);
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
            func_004829c0(temp_4_2);
        }
        *(s32 *)(arg0 + 0xCC) = func_00482a70(*(s32 *)(arg1 + 0xCC));
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
    temp = func_00484490(source);
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



// FUN_004A7DE0
void func_004a7de0(void) {
}



// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



/* measured: the byte->float sites are `(f32)(u32)x`; the eight rotated-corner stores add the
   centre offset inside the store expression (`*(f32 *)(arg1 + 0x10) = temp_f26 + temp_f1;`):
   assigning back into temp_f1 makes mwcc put the coalesced operand first (add.s f1,f1,f26),
   a fresh destination keeps retail's add.s f1,f26,f1. */
/* measured: loop-invariant conversion preloads for func_004a7e30. */
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
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
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
#pragma opt_loop_invariants off
// FUN_004A8250
/* measured: loop-invariant conversion preloads for func_004a8250. */
#pragma opt_loop_invariants on
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
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
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
#pragma opt_loop_invariants off
// FUN_004A8440
/* measured: loop-invariant conversion preloads for func_004a8440. */
#pragma opt_loop_invariants on
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
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
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
#pragma opt_loop_invariants off
// FUN_004A86C0
/* measured: loop-invariant conversion preloads for func_004a86c0. */
#pragma opt_loop_invariants on
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
    temp_f6 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
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
#pragma opt_loop_invariants off
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
    func_00489f80();
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x31001);
    func_004a8250(arg0 + 4, sp140);
    sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
    (*sendPacket)(3, sp140, 4, D_00714368, 6);
    func_0048a000();
    RpSkyRenderStateSet(2, sp24C | 0x10);
    if (func_004a7e30(arg0 + 4, sp40) != 0) {
        (*setState)(1, D_00922D90[0]);
        RpSkyRenderStateSet(3, 0x31001);
        func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
        (*sendPacket)(3, sp40, 4, D_00714368, 6);
        func_0048a0e0();
    }
    (*setState)(1, 0);
    RpSkyRenderStateSet(3, sp248);
    RpSkyRenderStateSet(2, sp24C);
}
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

// FUN_004ABBB0
void func_004abbb0(u8 *arg0)
{
    mdlInitIdentityMatrix(arg0);
    if (mdlLayerIsPresent(arg0, 0) != 0) {
        mdlDispatchAnimIfPresent(arg0, 0, 0, 0, 0);
        mdlSetLayerWeight(arg0, 0, 1.0f);
    }
    *(s32 *)(arg0 + 0xD8) &= ~2;
    mdlSetResetCallback(arg0, func_004abe60, arg0);
}
/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
#pragma opt_propagation off
// FUN_004ABC50
u8 *func_004abc50(u8 *arg0, s32 arg1)
{
    u8 *temp_2;
    u32 lookupType;

    goto loop_004abc50_check;
loop_004abc50_body:
    iGpffffbb90 += 1;
loop_004abc50_check:
    lookupType = 6;
    if (mdlFindModelObject(lookupType, iGpffffbb90, 0) != 0) {
        goto loop_004abc50_body;
    }
    temp_2 = mdlCreateModelObjectFromMemory(6, iGpffffbb90, arg0, (u32)arg1, 1);
    mdlInitIdentityMatrix(temp_2);
    if (mdlLayerIsPresent(temp_2, 0) != 0) {
        mdlDispatchAnimIfPresent(temp_2, 0, 0, 0, 0);
        mdlSetLayerWeight(temp_2, 0, 1.0f);
    }
    *(s32 *)(temp_2 + 0xD8) &= ~2;
    mdlSetResetCallback(temp_2, func_004abe60, temp_2);
    iGpffffbb90 += 1;
    return temp_2;
}
#pragma pop
// FUN_004ABD60
void func_004abd60(void)
{
    mdlDestroyModelObject();
}

// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}

// FUN_004ACB80
void func_004acb80(u8 *arg0)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 temp_3;
    u32 temp_3_2;
    u32 temp_4;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    temp_4 = (u32)temp_f0 + 1;
    temp_3 = *(u32 *)(arg0 + 0x9C);
    if (temp_3 >= temp_4 || temp_3 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= temp_4) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= temp_4) {
            temp_3_2 = *(u32 *)(arg0 + 0x74);
            if (temp_4 < temp_3_2) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_3_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
}
/* measured: an s64-aligned union gives retail's ld/lwc1 Vec3 copies; the
   three-argument helper signature keeps frame_index/frame_count in a1/a2. */
// FUN_004ACCC0
void func_004accc0(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    union BasisConst {
        struct Vec3 value;
        s64 align;
    };
    struct Frame {
        f32 matrix[16];
        struct Vec3 transformed;
        s32 pad4c;
        struct Vec3 scale;
        s32 pad5c;
    };
    struct Vec3 basis1;
    struct Vec3 basis2;
    struct Vec3 basis3;
    struct Frame frame;
    extern union BasisConst D_007144C8[];
    extern union BasisConst D_007144D8[];
    extern union BasisConst D_007144E8[];
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
    extern u8 *func_003e9700(s32 arg0);
    extern u8 *mdlGetMatrix(s32 arg0);
    extern u8 *RwMatrixMultiply(void *arg0, void *arg1, void *arg2);
    extern void RwMatrixRotate(void *arg0, void *arg1, f32 fparg0, s32 arg2);
    extern void RwMatrixScale(void *arg0, void *arg1, s32 arg2);
    extern void func_003e4320(void *arg0, void *arg1, void *arg2);
    extern void mdlUpdateModelMatrix(s32 arg0);
    extern void func_0047a320(s32 arg0);
    s32 frame_count;
    u32 frame_index;
    u8 *node;
    u8 *camera;
    u8 *matrix;
    u8 *object;
    f32 depth;
    f32 width;
    f32 near_height;
    f32 scale;
    f32 far_z;
    f32 temp;

    basis1 = D_007144C8[0].value;
    basis2 = D_007144D8[0].value;
    basis3 = D_007144E8[0].value;
    frame_index = (u32)mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    frame_count = *(s32 *)(arg0 + 0x9C);
    if (frame_count >= (s32)frame_index || frame_count == 0) {
        scale = func_0048aff0(arg0 + 0x44, frame_index, frame_count) / 10.0f;
        node = ((u8 *)(u32)func_00457120()) + 0x68;
        camera = ((u8 *)(u32)func_00457120());
        near_height = *(f32 *)(camera + 0x80);
        camera = ((u8 *)(u32)func_00457120());
        far_z = *(f32 *)(camera + 0x84);
        depth = (((f32)-0xFFFF * near_height) * far_z) /
                (((f32)-0xFFFF * far_z) -
                 (-31.0f * (far_z - near_height)));
        width = 2.0f * (*(f32 *)(node + 0) * depth);
        near_height = 2.0f * (*(f32 *)(node + 4) * depth);
        camera = ((u8 *)(u32)func_00457120());
        matrix = func_003e9700(*(s32 *)(camera + 4));
        RwMatrixRotate(frame.matrix, &basis1,
                      *(f32 *)(arg0 + 0x90), 0);
        if (*(f32 *)(arg0 + 0x94) != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis2,
                          *(f32 *)(arg0 + 0x94), 2);
        }
        if (*(f32 *)(arg0 + 0x98) != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis3,
                          *(f32 *)(arg0 + 0x98), 2);
        }
        temp = (width / 640.0f) * scale;
        frame.scale.z = temp;
        frame.scale.y = temp;
        frame.scale.x = temp;
        RwMatrixScale(frame.matrix, &frame.scale, 2);
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        RwMatrixMultiply(object, frame.matrix, matrix);
        frame.scale.x =
            width * (0.5f + (-(f32)(*(f32 *)(arg0 + 0) +
                                    *(f32 *)(arg0 + 0x84)) /
                              640.0f));
        frame.scale.y =
            near_height * (0.5f + (-(f32)(*(f32 *)(arg0 + 4) +
                                          *(f32 *)(arg0 + 0x88)) /
                                    448.0f));
        frame.scale.z = *(f32 *)(arg0 + 0x8C) + depth;
        func_003e4320(&frame.transformed, &frame.scale, matrix);
        scale = *(f32 *)(matrix + 0x30) + frame.transformed.x;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x30) = scale;
        scale = *(f32 *)(matrix + 0x34) + frame.transformed.y;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x34) = scale;
        scale = *(f32 *)(matrix + 0x38) + frame.transformed.z;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x38) = scale;
        mdlUpdateModelMatrix(*(s32 *)(arg0 + 0xB4));
        func_0047a320(*(s32 *)(arg0 + 0xB4));
    }
}
/* measured: effModel func_004ac300 VU0 colour-pack idiom with D_00761134 (1/255) scale; */
/* measured: plain `(u32)temp_f0` gives retail's `lui $3,0x8000; or` (no D_80000001, unlike */
/* measured: the `+1` siblings); `sp5C = *(s32 *)&sp50` forces the packed word back through */
/* measured: memory so the `lw $2,0x50; sw $2,0x5C` copy survives and the saved ranking stays */
/* measured: arg0 $s3, arg1 $s2, frame_index $s1, frame_count $s0 with frame 0x60. */
/* measured: probe c: 0 differing words, object 528B/window 528B. */
// FUN_004AD030
void func_004ad030(s32 arg0, u8 *arg1)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    extern s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern void mdlSetColor(void *arg0, s32 *arg1);
    extern f32 func_0048aff0(void *arg0, u32 arg1, u32 arg2);
    extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
    extern s32 TnGetTableBase(void);
    extern void mdlSetAttachedOwner(void *arg0, s32 arg1);
    extern void mdlQueueModelForDraw(s32 arg0, void *arg1);
    extern f32 D_00761134;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 temp_f0;
    u32 frame_index;
    u32 frame_count;
    s32 color;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg1 + 0xB4), 0);
    frame_index = (u32)temp_f0;
    frame_count = *(u32 *)(arg1 + 0x9C);
    if ((frame_count >= frame_index) || (frame_count == 0)) {
        color = func_0048abd0(arg1 + 0x10, arg1 + 0x34, frame_index, frame_count);
        sp58 = *(s32 *)(arg1 + 0xC);
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(&sp58), "f"(D_00761134)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp54 = color;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 80($sp)        \n"
            :
            : "r"(&sp54), "f"(D_00761134)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp5C = *(s32 *)&sp50;
        mdlSetColor(*(u8 **)(arg1 + 0xB4), &sp5C);
        func_0048aff0(arg1 + 0x44, frame_index, frame_count);
        *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) &= ~0x100;
        if ((*(u8 *)(arg1 + 0xA1) != 0) && (*(s32 *)(arg1 + 0xA4) == 0)) {
            *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) |= 0x18;
        } else {
            *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) &= ~0x18;
        }
        mdlSetLayerWeight(*(u8 **)(arg1 + 0xB4), 0, *(f32 *)(arg1 + 8));
        mdlSetAttachedOwner(*(u8 **)(arg1 + 0xB4), TnGetTableBase());
        mdlQueueModelForDraw(arg0, *(u8 **)(arg1 + 0xB4));
        *(s32 *)(arg1 + 8) = 0;
    }
}
// FUN_004AD240
void func_004ad240(u8 *arg0) {
    func_004ad030(TnGetOffset38(*(u16 *)(arg0 + 0x38)), arg0);
}
// FUN_004AD280
void func_004ad280(u8 *arg0)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 var_3;
    u32 temp_2;
    u32 temp_2_2;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    var_3 = (u32)temp_f0 + 1;
    temp_2 = *(u32 *)(arg0 + 0x9C);
    if (temp_2 >= var_3 || temp_2 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= var_3) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= var_3) {
            temp_2_2 = *(u32 *)(arg0 + 0x74);
            if (var_3 < temp_2_2) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_2_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
    func_004ad030(TnGetOffset38(*(u16 *)(arg0 + 0x38)), arg0);
}
// FUN_004AD3E0
void func_004ad3e0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x0) = arg1[0];
    *(f32 *)(arg0 + 0x4) = arg1[1];
}
// FUN_004AD400
void func_004ad400(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0xC) = arg1;
}
// FUN_004AD410
s32 func_004ad410(u8 *arg0) {
    u8 *p;
    s32 result;
    p = *(u8 **)(arg0 + 0xB4);
    if (p != NULL) {
        result = (*(u8 *)(p + 0xEE) ^ 1U) < 1U;
    } else {
        result = 1;
    }
    return result;
}
// FUN_004AD440
s32 func_004ad440(u8 *arg0) {
    return *(u8 *)(arg0 + 0xB8) != 0;
}
// FUN_004AD450
void func_004ad450(u8 *arg0) {
    *(u8 *)(arg0 + 0xB8) = 0;
}
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
// FUN_004ADB50
/* measured: object 816B/window 816B, nd 0. K&R definition so the unprototyped
   caller func_004adfa0 stays byte-exact. The VU0 colour-pack island and the
   `color = *(s32 *)&sp134` read are the effModel.c func_004ac300 idiom - reading
   the packed word through its address is what makes b210 reload it into $s5
   right after the island and, with it, rank the saved registers as retail does
   (n $s4, arg0 $s3, objs $s2, count $s1, total $s0; a plain `color = sp134`
   read left the load floating and flipped the whole ranking). Locals in
   declaration order; the loop is a goto loop with `objs++`; `zero` is a hoisted
   0.0f local ($f20); `t = call / 10.0f; speed = t * field` for the mul.s order. */
void func_004adb50(arg0)
u8 *arg0;
{
    extern void func_0048a150(void *arg0, void *arg1);
    extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
    extern void mdlScale(void *arg0, void *arg1, s32 arg2);
    extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void mdlAdvanceModelFromFlags(void *arg0);
    extern s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern f32 func_0048aff0(void *arg0, u32 arg1, u32 arg2);
    extern void func_004861f0(void *arg0, f32 *arg1);
    extern void func_0048a980(f32 *arg0);
    extern void func_00486330(void *arg0, void *arg1);
    extern void func_00486400(void *arg0, f32 arg1);
    extern void func_004865c0(u8 *arg0, s32 arg1);
    extern void func_00485630(void *arg0);
    extern f32 D_00761134;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 vec[3];
    f32 pos[4];
    u8 out[0x10];
    u8 frame[0x40];
    f32 mat[16];
    u32 n;
    s32 *objs;
    s32 count;
    s32 total;
    u32 i;
    f32 temp_f0;
    f32 speed;
    s32 color;
    f32 scale;
    f32 zero;
    f32 t;
    s32 *pt;

    count = *(s32 *)(arg0 + 0x2C);
    total = *(s32 *)(arg0 + 0x90);
    n = *(u32 *)(arg0 + 0x28);
    objs = *(s32 **)(arg0 + 0x98);
    if (count < total || total == 0) {
        func_0048a150(frame, arg0 + 0x10);
        mdlApplyModelMatrix(*(void **)(arg0 + 0xA0), frame, 0);
        temp_f0 = *(f32 *)(arg0 + 0x20);
        vec[2] = temp_f0;
        vec[1] = temp_f0;
        vec[0] = temp_f0;
        mdlScale(*(void **)(arg0 + 0xA0), vec, 2);
        vec[0] = *(f32 *)(arg0 + 0);
        vec[1] = *(f32 *)(arg0 + 4);
        vec[2] = *(f32 *)(arg0 + 8);
        mdlTranslateMatrix((RwMatrix *)*(void **)(arg0 + 0xA0), (const RwV3d *)vec, 2);
        mdlSetLayerWeight(*(void **)(arg0 + 0xA0), 0, *(f32 *)(arg0 + 0x94));
        mdlAdvanceModelFromFlags(*(void **)(arg0 + 0xA0));
        if (*(s32 *)(arg0 + 0x9C) != 0) {
            color = func_0048abd0(arg0 + 0x30, arg0 + 0x54, count, total);
            sp13C = *(s32 *)(arg0 + 0x24);
            pt = &sp13C;
            scale = D_00761134;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10   \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmove.xyzw $vf11, $vf10 \n"
                :
                : "r"(pt), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            sp138 = color;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10   \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                "lui $2, 0x437F        \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vftoi0.xyzw $vf10, $vf10 \n"
                "qmfc2.ni $2, $vf10    \n"
                "ppach $2, $0, $2      \n"
                "ppacb $2, $0, $2      \n"
                "sw $2, 0x134($sp)     \n"
                :
                : "r"(&sp138), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            color = *(s32 *)&sp134;
            t = func_0048aff0(arg0 + 0x64, count, total) / 10.0f;
            speed = t * *(f32 *)(arg0 + 0x20);
            i = 0;
            zero = 0.0f;
            goto loop_check;
loop_body:

                if (mdlCopyIndexedMatrix(*(u8 **)(arg0 + 0xA0), i, frame) != 0) {
                    pos[0] = *(f32 *)(frame + 0x30);
                    pos[1] = *(f32 *)(frame + 0x34);
                    pos[2] = *(f32 *)(frame + 0x38);
                    pos[3] = zero;
                    func_004861f0((void *)*objs, pos);
                    mat[0] = *(f32 *)(frame + 0x00);
                    mat[1] = *(f32 *)(frame + 0x04);
                    mat[2] = *(f32 *)(frame + 0x08);
                    mat[3] = zero;
                    mat[4] = *(f32 *)(frame + 0x10);
                    mat[5] = *(f32 *)(frame + 0x14);
                    mat[6] = *(f32 *)(frame + 0x18);
                    mat[7] = zero;
                    mat[8] = *(f32 *)(frame + 0x20);
                    mat[9] = *(f32 *)(frame + 0x24);
                    mat[10] = *(f32 *)(frame + 0x28);
                    mat[11] = zero;
                    mat[12] = *(f32 *)(frame + 0x30);
                    mat[13] = *(f32 *)(frame + 0x34);
                    mat[14] = *(f32 *)(frame + 0x38);
                    mat[15] = zero;
                    func_0048a980(mat);
                    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(out) : "$vf10", "memory");
                    func_00486330((void *)*objs, out);
                    func_00486400((void *)*objs, speed);
                    func_004865c0((void *)*objs, color);
                    func_00485630((void *)*objs);
                }
                i += 1;
                objs += 1;
loop_check:
                if (i < n) {
                    goto loop_body;
                }
        }
    }
    *(s32 *)(arg0 + 0x2C) += 1;
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

// FUN_004AE2F0
void func_004ae2f0(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 temp_hi;
    s32 temp_lo;
    s32 quotient;
    s32 remainder;
    f32 temp_f1;

    temp_lo = *(s32 *)(arg0 + 0x38) / 6;
    if (temp_lo > 0) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf12, $vf10\n"
            ".set reorder\n"
            :
            :
            : "$vf12", "memory");
        quotient = arg2 / temp_lo;
        remainder = arg2 % temp_lo;
        temp_f1 = (f32)remainder / (f32)temp_lo;
        temp_hi = (*(s8 *)(arg1 + 0x14) + quotient) % 6;
        spC = ((s32 *)p4_add_u32(((temp_hi + 1) % 6) * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lwc1 $f0, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 $2, $f0\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&spC)
            : "$2", "$vf2", "$vf11", "memory");
        sp8 = ((s32 *)p4_add_u32(temp_hi * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $3, $f0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&sp8)
            : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile(
            ".set noreorder\n"
            "mfc1 $3, %0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 $3, %1\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            "vmove.xyzw $vf11, $vf12\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "f"(1.0f - temp_f1), "f"(temp_f1)
            : "$3", "$vf2", "$vf10", "$vf11", "$vf12", "memory");
    } else {
        sp4 = ((s32 *)p4_add_u32(*(s8 *)(arg1 + 0x14) * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $3, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "r"(&sp4)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
    }
}
// FUN_004AF520
void func_004af520(u8 *arg0) {
    u8 *temp;
    u8 *inner;
    temp = *(u8 **)(arg0 + 0x58);
    if (temp != NULL) {
        inner = *(u8 **)(temp + 0x20);
        *(s32 *)(arg0 + 0x64) = 0;
        *(s32 *)(arg0 + 0x68) = 0;
        func_00460ac0(TnGetOffset1C(*(u16 *)(inner + 0x54)), arg0 + 0x64);
    }
}
// FUN_004AF580
void func_004af580(u8 *arg0) {
    u8 *temp;
    u8 *inner;
    ObjectParticleUpdateRecords();
    temp = *(u8 **)(arg0 + 0x58);
    if (temp != NULL) {
        inner = *(u8 **)(temp + 0x20);
        *(s32 *)(arg0 + 0x64) = 0;
        *(s32 *)(arg0 + 0x68) = 0;
        func_00460ac0(TnGetOffset1C(*(u16 *)(inner + 0x54)), arg0 + 0x64);
    }
}
// FUN_004AF5E0
void func_004af5e0(u8 *instance, u32 *position)
{
    func_00492dd0(*(s32 *)(instance + 0x58), position);
}
// FUN_004AF610
void func_004af610(u8 *instance, u32 *rotation)
{
    func_00492e10(*(s32 *)(instance + 0x58), rotation);
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

#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void hFadeTaskStart(s16 arg0);
extern s32 mcIconTaskCreate(u8 *parent, s32 mode);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void *SceneDraw_GetList4FirstColor(void);
extern void *SceneDraw_GetList4SecondColor(void);
extern void btlMainLoadBattleFieldScene();
extern void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 btlMainSkillColorDefault(s32 arg0);
extern s32 btlMainSkillTintDefault(s32 arg0);
extern void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_00144f60(void);
extern void func_004833f0(void *arg0);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern s32 btlCurrentUnitId(void);
extern s32 func_002aa3f0(void);
extern void btlResetEffectSlots(void);
extern void func_00145080();
extern void func_001b69c0(void);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u32 iGpffffa0b8;
extern void btlMainSetupCameraAndEffects(void);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void btlMainApplyUnitBaseColors(u8 *arg0);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *SceneDraw_GetList4Matrix(void);
extern u8 *resrcMngGetColorValue(void);
extern u8 *resrcMngGetColorTarget(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void btlUnitSetColor(u8 *arg0, s32 arg1);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern s32 func_00457120(void);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001b5ec0-001b7520 */

/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
/* Retail allocates the scan as found=v1, base=v0, i=a3. The second scan walks
   a `table` copy of `base`; that copy use keeps `base` a declared local
   instead of folding into its gp load temporary. `found` declared first and
   `base` second give retail's v1/v0 pair. In the owner, the measured
   `opt_common_subs off` keeps the scan's offset and table reloads separate. */
#pragma push
#pragma pop
/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma pop
// FUN_001B5EC0
void btlMainTestInit(void)
{
}

// FUN_001B5ED0
s32 btlMainTestUpdate(void)
{
    hFadeTaskStart(0);
    return 2;
}

// FUN_001B5F00
void btlMainMcInit(void)
{
    *(s32 *)(D_0076449C + 0xDCC) = mcIconTaskCreate(0, 0);
}

// FUN_001B5F30
s32 btlMainMcUpdate(void)
{
    if (func_002aa3f0() != 0) {
        btlResetEffectSlots();
        return 0x12;
    }
    return 0;
}

// FUN_001B5F70
void btlMainSetPhase(s32 arg0)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = arg0;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
}

// FUN_001B5FD0
s32 btlMainGetPhase(void)
{
    return *(s32 *)(iGpffffb3ac + 0x2FC);
}

// FUN_001B5FE0
void btlMainUpdate(void)
{
    u8 *temp_2;
    s32 temp_3;

    if (*(s32 *)((u8 *)iGpffffb3ac + 0x300) != 0) {
        *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) =
            *(s32 *)((u8 *)iGpffffb3ac + 0x300);
        *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
        temp_2 = (u8 *)iGpffffb3ac;
        (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
            temp_2 + 0x2FC);
        *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    temp_3 = (*(s32 (**)(u8 *))(D_005F7184 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    if (temp_3 != 0) {
        temp_2 = (u8 *)iGpffffb3ac;
        *(s32 *)(temp_2 + 0x300) = temp_3;
    }
    temp_2 = (u8 *)iGpffffb3ac;
    *(s32 *)(temp_2 + 0x304) = *(s32 *)(temp_2 + 0x304) + 1;
}

// FUN_001B60A0
void btlMainReset(void)
{
    u8 *temp_2;

    *(s32 *)((u8 *)iGpffffb3ac + 0x2FC) = 1;
    *(s32 *)((u8 *)iGpffffb3ac + 0x304) = 0;
    temp_2 = (u8 *)iGpffffb3ac;
    (*(void (**)(u8 *))(D_005F7180 + (*(s32 *)(temp_2 + 0x2FC) * 0xC)))(
        temp_2 + 0x2FC);
    *(s32 *)((u8 *)iGpffffb3ac + 0x300) = 0;
}

// FUN_001B6110
void func_001b6110(void)
{
}

/* Camera snapshots, quaternion conversion and effect geometry setup.
 * Shared geometry and complete palette contracts match their providers.
 * Native proof and the retail matrix-padding omission are documented in
 * docs/probe_archive/Battle_camera_setup_001b6120_20260922_worker7.md.
 */
// FUN_001B6120
#pragma push
/* measured: func_001b6120 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlMainSetupCameraAndEffects(void)
{
    extern u8 *func_004571a0(void);
    extern u8 *func_004571c0(void);
    extern u8 *resrcMngGetTransform(void);
    extern s32 RtQuatConvertFromMatrix(void *quat, const void *matrix);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern s32 sprintf(char *dst, const char *fmt, ...);
    typedef struct RwTexDictionary RwTexDictionary;
    typedef struct RwTexture RwTexture;
    extern RwTexture *func_003ef650(RwTexDictionary *dictionary, const char *name);
    extern RwTexDictionary *func_003ef6d0(void);
    extern void *func_003c42b0(void *material, void *texture);
    extern void *func_003c22f0(void *geometry);
    extern u8 *func_003e9c10(u8 *a0, const f32 *a1, s32 a2);
    extern char D_005F7270[];
    extern u8 D_0060A140[];
    extern f32 D_0060A410[];
    extern f32 D_0060A840[];
    extern u8 iGpffffa4d8;
    extern u8 iGpffffa4d9;
    extern u8 iGpffffa4da;
    extern u8 iGpffffa4db;
    extern f32 fGpffff81f4;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } Matrix __attribute__((aligned(16)));
    extern Matrix D_00922C60;
    u8 *base;
    u8 *cam;
    u8 *vec;
    u8 *tmp;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 qw;
    f32 inv;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 t10;
    f32 t9;
    f32 t8;
    f32 t7;
    f32 t6;
    f32 t5;
    f32 t4_2;
    f32 t3_2;
    f32 t2_2;
    Matrix matrix;
    char buf[0x80];
    u8 *handle;
    u8 *work;
    u8 *p;
    u8 *dstPos;
    u8 *dstUv;
    u8 *dstCol;
    f32 *tblA;
    f32 *tblB;
    u32 i;
    f32 uvScale;
    u8 white;
    f32 pos[3];
    typedef BtlCameraPalette Rgba;
    typedef struct { f32 r, g, b, a; } RgbaReal;
    cam = (u8 *)func_004571a0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x270) = *(RgbaReal *)(cam + 0x18);
    cam = (u8 *)func_004571c0();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x280) = *(RgbaReal *)(cam + 0x18);
    vec = resrcMngGetColorValue();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1BC) = *(RgbaReal *)(vec + 0x0);
    vec = resrcMngGetColorTarget();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1CC) = *(RgbaReal *)(vec + 0x0);
    tmp = resrcMngGetTransform();
    base = D_0076449C;
    RtQuatConvertFromMatrix(base + 0x1DC, tmp);
    base = D_0076449C;
    *(f32 *)(base + 0x24C) = fGpffff81f4 * (f32)iGpffffa4d8;
    base = D_0076449C;
    *(f32 *)(base + 0x250) = fGpffff81f4 * (f32)iGpffffa4d9;
    base = D_0076449C;
    *(f32 *)(base + 0x254) = fGpffff81f4 * (f32)iGpffffa4da;
    base = D_0076449C;
    *(f32 *)(base + 0x258) = fGpffff81f4 * (f32)iGpffffa4db;
    vec = (u8 *)SceneDraw_GetList4FirstColor();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1EC) = *(RgbaReal *)(vec + 0x0);
    vec = (u8 *)SceneDraw_GetList4SecondColor();
    base = D_0076449C;
    *(RgbaReal *)(base + 0x1FC) = *(RgbaReal *)(vec + 0x0);
    tmp = (u8 *)SceneDraw_GetList4Matrix();
    base = D_0076449C;
    RtQuatConvertFromMatrix(base + 0x20C, tmp);
    base = D_0076449C;
    memcpy(base + 0x21C, base + 0x1EC, 0x30);
    base = D_0076449C;
    *(RgbaReal *)D_00922CA0 = *(RgbaReal *)(base + 0x1BC);
    *(RgbaReal *)D_00922CB0 = *(RgbaReal *)(base + 0x1CC);
    base = D_0076449C;
    qy = *(f32 *)(base + 0x1E0);
    qx = *(f32 *)(base + 0x1DC);
    qz = *(f32 *)(base + 0x1E4);
    qw = *(f32 *)(base + 0x1E8);
    inv = 2.0f / ((qx * qx) + (qy * qy) + (qz * qz) + (qw * qw));
    sx = qx * inv;
    sy = qy * inv;
    sz = qz * inv;
    t10 = sx * qw;
    t9 = sy * qw;
    t8 = sz * qw;
    t7 = qx * sx;
    t6 = qy * sy;
    t5 = qz * sz;
    t4_2 = qy * sz;
    t3_2 = qz * sx;
    t2_2 = qx * sy;
    matrix.right.x = 1.0f - (t6 + t5);
    matrix.right.y = t2_2 + t8;
    matrix.right.z = t3_2 - t9;
    matrix.up.x = t2_2 - t8;
    matrix.up.y = 1.0f - (t5 + t7);
    matrix.up.z = t4_2 + t10;
    matrix.at.x = t3_2 + t9;
    matrix.at.y = t4_2 - t10;
    matrix.at.z = 1.0f - (t7 + t6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    /* Retail copies all 64 bytes here without writing the SDK pad1,
     * pad2 or pad3 words (stack offsets 0xCC, 0xDC and 0xEC). */
    D_00922C60 = matrix;
    D_00922CC0[0] = 1;
    *(f32 *)(D_0076449C + 0x25C) = fGpffff81f4 * (f32)iGpffffb45c.red;
    *(f32 *)(D_0076449C + 0x260) = fGpffff81f4 * (f32)iGpffffb45c.green;
    *(f32 *)(D_0076449C + 0x264) = fGpffff81f4 * (f32)iGpffffb45c.blue;
    *(f32 *)(D_0076449C + 0x268) = fGpffff81f4 * (f32)iGpffffb45c.alpha;
    if (btlCurrentUnitId() != 0x20B) {
        func_003e8180(((u8 *)func_00457120()), 35.0f);
    } else {
        func_003e8180(((u8 *)func_00457120()), 100.0f);
    }
    base = D_0076449C;
    *(u32 *)(base + 0xC) |= 0x2000002;
    base = D_0076449C;
    sprintf(buf, D_005F7270, *(u16 *)(base + 0x26C), *(u16 *)(base + 0x26E));
    *(u8 **)(D_0076449C + 0xE78) = (u8 *)func_003ef650(func_003ef6d0(), buf);
    if (*(u32 *)(D_0076449C + 0xE78) != 0) {
        *(u32 *)(D_0076449C + 0xE80) = 0;
        *(u8 **)(D_0076449C + 0xE7C) = (u8 *)func_00482f70(1, 0x76, 0x59, D_0060A140, 0x4C);
        base = D_0076449C;
        func_003c42b0(*(void **)(*(u8 **)(base + 0xE7C) + 0x14), *(void **)(base + 0xE78));
        base = D_0076449C;
        RpGeometryLock(*(RpGeometry **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18), 0xFF2);
        base = D_0076449C;
        p = *(u8 **)(*(u8 **)(*(u8 **)(base + 0xE7C) + 0x10) + 0x18);
        dstPos = *(u8 **)(*(u8 **)(p + 0x5C) + 0x14);
        dstUv = *(u8 **)(p + 0x34);
        dstCol = *(u8 **)(p + 0x30);
        i = 0;
        tblA = D_0060A410;
        tblB = D_0060A840;
        uvScale = 8.0f;
        white = 0xFF;
        for (; i < 0x59; i++) {
            *(f32 *)(dstPos + 0) = tblA[i * 3 + 0];
            *(f32 *)(dstPos + 4) = tblA[i * 3 + 1];
            *(f32 *)(dstPos + 8) = tblA[i * 3 + 2];
            *(f32 *)(dstUv + 0) = tblB[i * 2 + 0];
            *(f32 *)(dstUv + 4) = uvScale * tblB[i * 2 + 1];
            dstCol[0] = white;
            dstCol[1] = white;
            dstCol[2] = white;
            dstCol[3] = white;
            dstPos += 0xC;
            dstUv += 8;
            dstCol += 4;
        }
        base = D_0076449C;
        work = *(u8 **)(base + 0xE7C);
        p = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
        func_003c22f0(p);
        if ((*(u16 *)work & 4) != 0) {
            *(u16 *)(p + 0xC) |= 1;
        }
        base = D_0076449C;
        handle = *(u8 **)(base + 0xE7C);
        work = *(u8 **)(handle + 0x14);
        *(Rgba *)(work + 4) = D_007635C8;
        pos[0] = 0.0f;
        pos[1] = 5.0f;
        pos[2] = 0.0f;
        base = D_0076449C;
        func_003e9c10(*(u8 **)(*(u8 **)(base + 0xE7C) + 0xC), pos, 0);
    }
}

#pragma pop
// FUN_001B68D0
/* measured: opt_propagation off probes the retail ordered second float load group. */
/* measured: func_001b68d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void func_001b68d0(void)
{
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    s32 value;

    a = *(f32 *)(D_0076449C + 0x270);
    b = *(f32 *)(D_0076449C + 0x274);
    c = *(f32 *)(D_0076449C + 0x278);
    d = *(f32 *)(D_0076449C + 0x27C);
    D_00922CA0[0] = a;
    D_00922CA4[0] = b;
    D_00922CA8[0] = c;
    D_00922CAC[0] = d;
    d = *(f32 *)(D_0076449C + 0x280);
    c = *(f32 *)(D_0076449C + 0x284);
    b = *(f32 *)(D_0076449C + 0x288);
    a = *(f32 *)(D_0076449C + 0x28C);
    D_00922CB0[0] = d;
    D_00922CB4[0] = c;
    D_00922CB8[0] = b;
    D_00922CBC[0] = a;
    D_00922CC0[0] = 1;
    *(s32 *)(D_0076449C + 0xE78) = 0;
    value = *(s32 *)(D_0076449C + 0xE7C);
    if (value != 0) {
        func_004833f0((void *)(u32)value);
        *(s32 *)(D_0076449C + 0xE7C) = 0;
    }
    func_00145080();
}

/* measured: closes opt_propagation probe for func_001b68d0. */
/* measured: func_001b6ab0, func_001b73f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_001B6990
void btlMainLoadBattleFieldScene(void)
{
    fieldSceneLoad(*(u16 *)(D_0076449C + 0x26C),
                  *(u16 *)(D_0076449C + 0x26E));
}

// FUN_001B69C0
void func_001b69c0(void)
{
    u8 *p;

    *(s32 *)(D_0076449C + 0xE78) = 0;
    p = D_0076449C;
    *(s32 *)(p + 0xC) &= ~2;
    func_00145080(p);
}

// FUN_001B6A00
void func_001b6a00(void)
{
    func_00144f60();
}

// FUN_001B6A20
void btlMainSyncSceneDrawColors(void)
{
    struct P4Vec4 {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
    };
    u8 *base;
    struct P4Vec4 *dst;
    struct P4Vec4 *src;

    base = D_0076449C;
    if ((*(s32 *)(base + 0xC) & 2) != 0) {
        dst = (struct P4Vec4 *)SceneDraw_GetList4FirstColor();
        src = (struct P4Vec4 *)(base + 0x1EC);
        *dst = *src;
        base = D_0076449C;
        dst = (struct P4Vec4 *)SceneDraw_GetList4SecondColor();
        src = (struct P4Vec4 *)(base + 0x1FC);
        *dst = *src;
    }
}

/* measured (this session): cold reconstruction v2 object 380/retail 348 instrs (9% over, not short); probe_variants 357 words/79 edits; probe_search 120 orders flat (propagation/rebuild/no_branch/dead/loop/lifetimes/strength/size/unroll all 357, common_subs worse 397); fnalign $at none (float/bltz tail, slti $at lever N/A); residual is stack layout (0x160 frame pads) and u32->float halving (bltz) vs dead-store elimination; banked guarded floor. */
/* measured 001b6ab0 2026-09-19: invented f60/f64 pair removed (retail has constants at buf+0x40, not floats; 18 -> 16 float stores) and schedule pragmas removed (retail is unscheduled with nop after every branch/jal); object 350/retail 348 +0.6% INSIDE, 328 words, 48 edits (+3 reloc-only) via fnalign --candidate (was 311/347 -10.4%, 332 words, 228 edits with schedule on). Remaining pure deletes: 0x1b6afc lui $s0,0x88 + addiu $s0,$s0,0x7300 (table-base copy; candidate materialises per site) and 0x1b6c0c sw $zero,0x24($sp) + sw $zero,0x60($sp) (frame 0x120 vs 0x160 offset shift, same 8 constant stores). Frame offsets differ but counts match. */
// FUN_001B6AB0
void btlMainDrawSkyOverlay(void) {
    extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void (*D_00887300[])(u32 arg0, u32 arg1);
    typedef struct {
        u32 h0;
        u32 h1;
        u8 gap08[24];
        f32 f[4];
        u8 gap30[16];
    } Blk40;
    struct {
        Blk40 b0;
        Blk40 b1;
        Blk40 b2;
        Blk40 b3;
        u8 tail[64];
    } buf;
    u8 **tbl;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;

    if (*(f32 *)(D_0076449C + 0x268) <= 0.0f) {
        return;
    }
    RpSkyRenderStateSet(2, 0x48);
    RpSkyRenderStateSet(3, 0x71801);
    tbl = (u8 **)D_00887300;
    ((void (*)(u32, u32))tbl[0])(0xC, 1);
    ((void (*)(u32, u32))tbl[0])(0xE, 0);
    ((void (*)(u32, u32))tbl[0])(1, 0);
    ((void (*)(u32, u32))tbl[0])(6, 0);
    ((void (*)(u32, u32))tbl[0])(8, 0);
    ((void (*)(u32, u32))tbl[0])(7, 2);
    c0 = (u32)(s32)(*(f32 *)(D_0076449C + 0x25C) * 255.0f + 0.5f) & 0xFF;
    c1 = (u32)(s32)(*(f32 *)(D_0076449C + 0x260) * 255.0f + 0.5f) & 0xFF;
    c2 = (u32)(s32)(*(f32 *)(D_0076449C + 0x264) * 255.0f + 0.5f) & 0xFF;
    c3 = (u32)(s32)(*(f32 *)(D_0076449C + 0x268) * 255.0f + 0.5f) & 0xFF;
    buf.b0.h0 = 0;
    buf.b0.h1 = 0;
    buf.b1.h0 = 0;
    buf.b1.h1 = 0x43E00000;
    buf.b2.h0 = 0x44200000;
    buf.b2.h1 = 0;
    buf.b3.h0 = 0x44200000;
    buf.b3.h1 = 0x43E00000;
    buf.b0.f[0] = (f32)c0;
    buf.b0.f[1] = (f32)c1;
    buf.b0.f[2] = (f32)c2;
    buf.b0.f[3] = (f32)c3;
    buf.b1.f[0] = (f32)c0;
    buf.b1.f[1] = (f32)c1;
    buf.b1.f[2] = (f32)c2;
    buf.b1.f[3] = (f32)c3;
    buf.b2.f[0] = (f32)c0;
    buf.b2.f[1] = (f32)c1;
    buf.b2.f[2] = (f32)c2;
    buf.b2.f[3] = (f32)c3;
    buf.b3.f[0] = (f32)c0;
    buf.b3.f[1] = (f32)c1;
    buf.b3.f[2] = (f32)c2;
    buf.b3.f[3] = (f32)c3;
    ((void (*)(u32, u8 *, u32))D_00887300[4])(4, (u8 *)&buf, 4);
}

// FUN_001B7020
s32 func_001b7020(void)
{
    return iGpffffb3ac + 0x1BC;
}

// FUN_001B7030
s32 func_001b7030(void)
{
    return iGpffffb3ac + 0x1EC;
}

// FUN_001B7040
s32 func_001b7040(void)
{
    return iGpffffb3ac + 0x21C;
}

// FUN_001B7050
s32 func_001b7050(void)
{
    return iGpffffb3ac + 0x24C;
}

// FUN_001B7060
void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}

// FUN_001B7080
s32 btlMainSkillColorDefault(s32 arg0)
{
    return 0xFF808080;
}

// FUN_001B7090
s32 btlMainSkillTintDefault(s32 arg0)
{
    return 0;
}

/* Identical body to btlMainSkillColorPairDefaults; a separate retail
 * function at its own address. */
// FUN_001B70A0
void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = 0xFF808080;
    *arg2 = -1;
}

/* Native b210: 812/816 bytes, unmasked relocations and zero tail proved.
 * Scene getters return void * from u16 IDs; matrix copies use SDK values.
 * Evidence: build/continue-first-party-20260922/battle-after-rebase/light-native.
 */
// FUN_001B70C0
#pragma push
/* Preserve the position/color snapshots and the two cross-product phases. */
void btlUnitUpdateModelLight(u8 *arg0)
{
    extern void *SceneDraw_GetLightColorA(u16 resTypeId);
    extern void *SceneDraw_GetLightTint(u16 resTypeId);
    extern void *SceneDraw_GetLightMatrixB(u16 resTypeId);
    extern f32 RwV3dNormalize(f32 *dst, const f32 *src);
    extern void *RwMatrixRotate(void *matrix, const void *axis, f32 angle, s32 combine);
    extern u8 D_005F7290[];
    extern u8 D_005F7294[];
    extern u8 D_005F7298[];
    extern u8 D_005F729C[];
    extern u8 D_005F72A0[];
    extern u8 D_005F72A4[];
    extern u8 D_005F72A8[];
    extern u8 D_005F72AC[];
    extern u8 D_0060A0D0[];
    extern u8 D_0060A0E4[];
    extern u8 D_0060A0E8[];

    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 right;
        u32 flags;
        Vec3 up;
        u32 pad1;
        Vec3 at;
        u32 pad2;
        Vec3 pos;
        u32 pad3;
    } Matrix;
    /* Independent vector locals preserve the native aggregate-copy alignment. */
    Matrix light;
    Vec3 at;
    Vec3 right;
    Vec3 up;
    Vec3 position;
    Vec3 center;
    f32 red, green, blue, alpha;
    f32 adjusted;
    f32 output_y;
    f32 cross_x;
    f32 cross_y;
    f32 cross_z;
    f32 axis_x;
    f32 axis_y;
    f32 axis_z;
    f32 cross2_y;
    f32 cross2_z;
    f32 cross2_normz;
    f32 cross2_dy;
    u8 mode;

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 2) != 0) &&
        (*(u16 *)(arg0 + 0x9FE) != 0)) {
        mode = *(u8 *)(arg0 + 0xA2);
        switch (mode) {
        case 0:
        case 1: {
            f32 *dstf;
            red = *(f32 *)(arg0 + 0x54);
            green = *(f32 *)(arg0 + 0x58);
            blue = *(f32 *)(arg0 + 0x5C);
            position.x = red;
            position.y = green;
            position.z = blue;
            btlUnitGetSphereWorldCenter(arg0, (f32 *)&center);
            output_y = center.y;
            adjusted = output_y + 5.0f;
            if (!(adjusted < position.y)) {
                position.y = adjusted;
            }
            light.pos = position;
            at.x = center.x - position.x;
            at.y = output_y - position.y;
            at.z = center.z - position.z;
            RwV3dNormalize(&at.x, &at.x);
            light.at = at;
            cross_y = at.y;
            axis_z = *(f32 *)D_0060A0E8;
            cross_z = at.z;
            axis_y = *(f32 *)D_0060A0E4;
            right.x = axis_y * cross_z - axis_z * cross_y;
            axis_x = *(f32 *)(u8 *)D_0060A0E0;
            cross_x = at.x;
            right.y = axis_z * cross_x - axis_x * cross_z;
            right.z = axis_x * cross_y - axis_y * cross_x;
            RwV3dNormalize(&right.x, &right.x);
            light.right = right;
            cross2_y = right.y;
            cross2_z = at.z;
            cross2_normz = right.z;
            cross2_dy = at.y;
            up.x = cross2_dy * cross2_normz - cross2_z * cross2_y;
            up.y = at.z * right.x - at.x * right.z;
            up.z = at.x * right.y - at.y * right.x;
            light.up = up;
            dstf = (f32 *)SceneDraw_GetLightTint(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)(arg0 + 0x70);
            green = *(f32 *)(arg0 + 0x74);
            blue = *(f32 *)(arg0 + 0x78);
            alpha = *(f32 *)(arg0 + 0x7C);
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            *(Matrix *)SceneDraw_GetLightMatrixB(*(u16 *)(arg0 + 0x9FE)) = light;
            break;
        }
        case 2: {
            f32 *dstf;

            RwMatrixRotate(&light, D_0060A0D0, -90.0f, 0);
            dstf = (f32 *)SceneDraw_GetLightColorA(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)D_005F7290;
            green = *(f32 *)D_005F7294;
            blue = *(f32 *)D_005F7298;
            alpha = *(f32 *)D_005F729C;
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            dstf = (f32 *)SceneDraw_GetLightTint(*(u16 *)(arg0 + 0x9FE));
            red = *(f32 *)D_005F72A0;
            green = *(f32 *)D_005F72A4;
            blue = *(f32 *)D_005F72A8;
            alpha = *(f32 *)D_005F72AC;
            dstf[0] = red;
            dstf[1] = green;
            dstf[2] = blue;
            dstf[3] = alpha;
            *(Matrix *)SceneDraw_GetLightMatrixB(*(u16 *)(arg0 + 0x9FE)) = light;
            break;
        }
        default:
            break;
        }
    }
}

#pragma pop
// FUN_001B73F0
void btlMainApplyUnitBaseColors(u8 *arg0)
{
    s32 index;
    u16 masked;
    u8 color[4];

    if (((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x400000) != 0) &&
        ((*(u16 *)((u8 *)iGpffffb3ac + 0x18) & 0x10) != 0)) {
        goto done;
    }
    if (arg0 != NULL) {
        color[0] = *(u8 *)(arg0 + 0x30);
        color[1] = *(u8 *)(arg0 + 0x31);
        color[2] = *(u8 *)(arg0 + 0x32);
        color[3] = 0xFF;
        btlUnitSetColor(arg0, *(s32 *)color);
        goto done;
    }
    index = 0;
    goto outer_check;
outer_loop:
    masked = (u16)index;
    arg0 = *(u8 **)((u8 *)iGpffffb3ac + ((u32)masked << 3) + 0x178);
    goto inner_check;
inner_loop:
    if (*(u16 *)(arg0 + 0x9FE) == 0) goto next;
    if ((*(s32 *)(arg0 + 0x9C) & 1) != 0) goto next;
    color[0] = *(u8 *)(arg0 + 0x30);
    color[1] = *(u8 *)(arg0 + 0x31);
    color[2] = *(u8 *)(arg0 + 0x32);
    color[3] = 0xFF;
    btlUnitSetColor(arg0, *(s32 *)color);
next:
    arg0 = *(u8 **)(arg0 + 0xA6C);
inner_check:
    if (arg0 != NULL) goto inner_loop;
    index = (index + 1) & 0xFFFF;
outer_check:
    if ((index & 0xFFFF) < 2) goto outer_loop;
done:
    ;
}

/* 860/864 bytes; seven resolved relocations; four zero alignment bytes.
 * Snapshot both field colors once, then interpolate to their products.
 * The packet callback keeps its u32(void *) contract and unsigned timer. */
#pragma push
/* measured: func_001b7520 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001B7520
u32 btlMainFieldColorFadePacketUpdate(void *arg0)
{
    typedef struct { f32 x; f32 y; f32 z; f32 w; } FadeV4;
    typedef struct {
        FadeV4 colorA;
        FadeV4 colorB;
        FadeV4 prodA;
        FadeV4 prodB;
        FadeV4 snapA;
        FadeV4 snapB;
        u32 totalFrames;
        u32 currentFrame;
    } FadeWork;
    FadeWork *work;
    u32 flags;
    u32 totalFrames;
    u32 currentFrame;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    FadeV4 result;
    FadeV4 *tmp;

    work = (FadeWork *)arg0;
    flags = *(u32 *)(iGpffffb3ac + 0xC);
    if ((flags & 2) == 0) {
        return 1;
    }
    if ((flags & 0x2000000) == 0) {
        return 1;
    }
    if (work->currentFrame == 0) {
        tmp = (FadeV4 *)resrcMngGetColorValue();
        work->snapA = *tmp;
        tmp = (FadeV4 *)resrcMngGetColorTarget();
        work->snapB = *tmp;
        work->prodA.x = work->snapA.x * work->colorA.x;
        work->prodA.y = work->snapA.y * work->colorA.y;
        work->prodA.z = work->snapA.z * work->colorA.z;
        work->prodA.w = work->snapA.w * work->colorA.w;
        work->prodB.x = work->snapB.x * work->colorB.x;
        work->prodB.y = work->snapB.y * work->colorB.y;
        work->prodB.z = work->snapB.z * work->colorB.z;
        work->prodB.w = work->snapB.w * work->colorB.w;
    }
    totalFrames = work->totalFrames;
    currentFrame = work->currentFrame;
    if (currentFrame < totalFrames) {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        firstX = work->snapA.x * inverse;
        firstY = work->snapA.y * inverse;
        firstZ = work->snapA.z * inverse;
        firstW = work->snapA.w * inverse;
        secondX = work->prodA.x * ratio;
        secondY = work->prodA.y * ratio;
        secondZ = work->prodA.z * ratio;
        secondW = work->prodA.w * ratio;
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ;
        result.w = firstW + secondW;
        *(FadeV4 *)resrcMngGetColorValue() = result;
        result.x = work->snapB.x * inverse + work->prodB.x * ratio;
        result.y = work->snapB.y * inverse + work->prodB.y * ratio;
        result.z = work->snapB.z * inverse + work->prodB.z * ratio;
        result.w = work->snapB.w * inverse + work->prodB.w * ratio;
        *(FadeV4 *)resrcMngGetColorTarget() = result;
    } else {
        tmp = (FadeV4 *)resrcMngGetColorValue();
        *tmp = work->prodA;
        tmp = (FadeV4 *)resrcMngGetColorTarget();
        *tmp = work->prodB;
        return 1;
    }
    work->currentFrame = work->currentFrame + 1;
    return 0;
}


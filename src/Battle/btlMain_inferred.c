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
#include "btl_camera_sequence_internal.h"

#include "rw_types_internal.h"
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
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void (*jtbl_008873EC[])(void *);
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
extern s32 btlColorBlendPacketUpdate(struct ColorBlendWork *work);
extern u8 *btlPacketAlloc(s32 size, s32 align);
extern s32 btlQuatMatrixPacketUpdate(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 iGpffffa0b8;
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
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
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






#pragma push
#pragma pop

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001ba0e0-001ba710 */

typedef struct { u8 r; u8 g; u8 b; u8 a; } BlendColor;
typedef struct ColorBlendWork {
    BlendColor target;
    BlendColor start;
    u32 frames;
    u32 frame;
} ColorBlendWork;
static inline u8 blendChannel(u8 start, u8 target, f32 t, f32 inv)
{
    f32 s = (1.0f / 255.0f) * (f32)start;
    f32 e = (1.0f / 255.0f) * (f32)target;
    f32 m = s * inv + e * t;
    return ((s32)(m * 255.0f + 0.5f)) & 0xFF;
}
struct RwV3d;
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
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: MATCH. The 1/255 scale is the pooled literal, not a global;
   with it written as a literal no pragmas are needed. The start colour is
   one struct copy (retail loads all four bytes, then stores them). */
// FUN_001BA0E0
s32 btlColorBlendPacketUpdate(ColorBlendWork *work)
{
    extern u8 *kwlnGetColorRgb(void);
    extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
    f32 t;
    f32 inv;
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    if (work->frame == 0) {
        work->start = *(BlendColor *)kwlnGetColorRgb();
    }
    if (work->frame < work->frames) {
        t = (f32)work->frame / (f32)work->frames;
        inv = 1.0f - t;
        r = blendChannel(work->start.r, work->target.r, t, inv);
        g = blendChannel(work->start.g, work->target.g, t, inv);
        b = blendChannel(work->start.b, work->target.b, t, inv);
        a = blendChannel(work->start.a, work->target.a, t, inv);
        kwlnSetColorRgba(r, g, b, a);
    } else {
        kwlnSetColorRgba(work->target.r, work->target.g, work->target.b, work->target.a);
        return 1;
    }
    work->frame++;
    return 0;
}

// FUN_001BA530
u8 *btlColorBlendPacketCreate(s32 arg0, s32 arg1) {
    u8 *o = btlPacketAlloc(0x608, 0x10);
    u8 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))btlColorBlendPacketUpdate;
    p = *(u8 **)(o + 0x78);
    *(s32 *)p = arg0;
    *(s32 *)(p + 8) = arg1;
    return o;
}

// FUN_001BA590
s32 btlQuatMatrixPacketUpdate(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Ba590Vec3;
    typedef struct {
        Ba590Vec3 right;
        u32 flags;
        Ba590Vec3 up;
        u32 pad1;
        Ba590Vec3 at;
        u32 pad2;
        Ba590Vec3 pos;
        u32 pad3;
    } Ba590Matrix;
    Ba590Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    u32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *var_6;
    s32 var_5;
    u8 *var_2;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        var_2 = (u8 *)iGpffffb3ac;
        temp_f3 = *(f32 *)(var_2 + 0x20C);
        temp_f2 = *(f32 *)(var_2 + 0x210);
        temp_f1 = *(f32 *)(var_2 + 0x214);
        temp_f0 = *(f32 *)(var_2 + 0x218);
        *(f32 *)(arg0 + 0x10) = temp_f3;
        *(f32 *)(arg0 + 0x14) = temp_f2;
        *(f32 *)(arg0 + 0x18) = temp_f1;
        *(f32 *)(arg0 + 0x1C) = temp_f0;
    }
    temp_3 = *(s32 *)(arg0 + 0x24);
    if (temp_3 >= *(u32 *)(arg0 + 0x20)) {
    temp_f4 = *(f32 *)(arg0 + 4);
    temp_f12 = *(f32 *)(arg0 + 0);
    temp_f11 = *(f32 *)(arg0 + 8);
    temp_f3 = *(f32 *)(arg0 + 0xC);
    temp_f0 =
        2.0f / ((temp_f12 * temp_f12) +
                (temp_f4 * temp_f4) +
                (temp_f11 * temp_f11) +
                (temp_f3 * temp_f3));
    temp_f2 = temp_f12 * temp_f0;
    temp_f1 = temp_f4 * temp_f0;
    temp_f0_2 = temp_f11 * temp_f0;
    temp_f10 = temp_f2 * temp_f3;
    temp_f9 = temp_f1 * temp_f3;
    temp_f8 = temp_f0_2 * temp_f3;
    temp_f7 = temp_f12 * temp_f2;
    temp_f6 = temp_f4 * temp_f1;
    temp_f5 = temp_f11 * temp_f0_2;
    temp_f4_2 = temp_f4 * temp_f0_2;
    temp_f3_2 = temp_f11 * temp_f2;
    temp_f2_2 = temp_f12 * temp_f1;
    matrix.right.x = 1.0f - (temp_f6 + temp_f5);
    matrix.right.y = temp_f2_2 + temp_f8;
    matrix.right.z = temp_f3_2 - temp_f9;
    matrix.up.x = temp_f2_2 - temp_f8;
    matrix.up.y = 1.0f - (temp_f5 + temp_f7);
    matrix.up.z = temp_f4_2 + temp_f10;
    matrix.at.x = temp_f3_2 + temp_f9;
    matrix.at.y = temp_f4_2 - temp_f10;
    matrix.at.z = 1.0f - (temp_f7 + temp_f6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    var_2 = SceneDraw_GetList4Matrix();
    var_6 = (u8 *)&matrix;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_6 + 0);
        temp_3_2 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_5 -= 1;
        *(s32 *)(var_2 + 0) = temp_4;
        *(s32 *)(var_2 + 4) = temp_3_2;
        var_2 += 8;
    } while (var_5 > 0);
    return 1;
    }
    *(s32 *)(arg0 + 0x24) = temp_3 + 1;
    return 0;
}

// FUN_001BA710
u8 *btlQuatMatrixPacketCreate(f32 *arg0, s32 arg1) {
    struct F4 {
        f32 x0;
        f32 x1;
        f32 x2;
        f32 x3;
    } value;
    u8 *o = btlPacketAlloc(0x60A, 0x28);
    f32 *p;

    *(void (**)(void))(o + 0x6C) = (void (*)(void))btlQuatMatrixPacketUpdate;
    p = *(f32 **)(o + 0x78);
    value = *(struct F4 *)arg0;
    *(struct F4 *)p = value;
    *(s32 *)(p + 8) = arg1;
    return o;
}


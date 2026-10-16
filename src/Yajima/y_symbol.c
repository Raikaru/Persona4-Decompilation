#include "mt_scene_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - y_symbol.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "g_data_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef struct
{
    f32 x;
    f32 y;
} Vec2;

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct YVec3f { f32 x, y, z; } YVec3f;

extern u8 D_0063F120[];
extern u8 D_0063F130[];
extern u8 D_0063F140[];
extern u8 D_0063F150[];
extern u8 D_0063F160[];
extern u8 D_00794CF0[];
extern u8 D_00794D20[];
extern u8 D_00794DB0[];
extern u8 D_00794DE0[];
extern u8 D_007E80A0[];
extern u8 D_007E80A8[];
extern u8 D_007E8C50[];
extern u8 D_007E8C54[];

extern u32 D_007EFA00[];
extern u8 D_007EFA04[];

extern void chkmemAllocSiteTag(void *msg, s32 id);

extern s32 K_FldEvent_ArePosWithinDist(u8 *arg0, u8 *arg1, f32 arg2);
extern f32 KDraw_MatrixYawDeg(u8 *arg0);
extern void *mdlGetMatrix(void *arg0);
extern s32 smapGetSpriteHandle(void);
extern s64 smapRevealTestBit(s32 arg0, s32 arg1);
extern s32 smapWorldToColumn(RwV3d arg0);
extern s32 smapWorldToRow(RwV3d arg0);
extern f32 smapPlayerOffsetX(u8 *arg0, f32 arg1);
extern f32 smapPlayerOffsetZ(u8 *arg0, f32 arg1);
extern f32 smapPositionOffsetX(f32 arg1, YVec3f *arg0);
extern f32 smapPositionOffsetZ(f32 arg1, YVec3f *arg0);
extern s32 func_002b2960(void);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern void fclAnchorOffset(f32 *arg0, s64 arg1, f32 arg2, f32 arg3, f32 arg4,
                          f32 arg5);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sdkSpriteScaledWidth(u8 *arg0);
extern f32 sdkSpriteScaledHeight(u8 *arg0);
extern u8 *sdkSpriteNewNode(s32 arg0, s32 arg1);
extern void sdkSpriteFreeNode(void *node);

extern s32 mapSymbolTaskUpdate(u8 *arg0);
extern void func_002b3960(u8 *arg0);
extern s32 mapSymbolPointUpdate(u8 *arg0);
extern s32 mapSymbolEntityUpdate(u8 *arg0);
extern s32 mapSymbolTargetUpdate(u8 *arg0);

// FUN_002B3990
s32 mapSymbolMarkerCreate(s32 arg0)
{
    s32 ret;
    u8 *work;
    u8 *t;

    chkmemAllocSiteTag(D_0063F120, 0x98);
    work = D_008873F4[0](1, 0x24, 0x40000);
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0063F130), 0xF, 0, 0, mapSymbolTaskUpdate, func_002b3960, (u8 *)(work));
    *(u32 *)(work + 4) = (u32)MT_Scene_GetRes(0x400);
    *(u32 *)(work + 0) = (u32)work;
    *(u32 *)(work + 8) = 0x3F400000;
    *(u32 *)(work + 0xC) = 0x3F400000;
    *(u32 *)(work + 0x10) = 0;
    work[0x20] = 0;
    t = sdkSpriteNewNode(smapGetSpriteHandle(), 0x10);
    *(s16 *)(work + 0x14) = (s16)(s32)(sdkSpriteScaledWidth(t) / 2.0f);
    *(s16 *)(work + 0x16) = (s16)(s32)(sdkSpriteScaledHeight(t) / 2.0f);
    sdkSpriteFreeNode(t);
    return ret;
}
/* Re-derived body: the prior nd118 candidate is retained in
   build/WBHygiene_func_002b3ae0_archive.txt for provenance; this body is
   verified MATCH after correcting the callee ABI and arithmetic statement
   order. */
// FUN_002B3AE0
void mapSymbolMarkerDraw(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2)
{
    f32 fparg0_saved;
    u8 *p;
    f32 angle;
    f32 temp;

    fparg0_saved = fparg0;
    p = *(u8 **)(arg0 + 0x38);
    angle = KDraw_MatrixYawDeg((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]));
    if (angle >= 0.0f) {
        temp = angle - 180.0f;
    } else {
        temp = angle;
        temp += 180.0f;
    }
    temp += *(f32 *)(p + 0x10);
    temp *= -1.0f;
    if (*(s8 *)(p + 0x20) == 1) {
        sdkSpriteDrawQueued(*(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, arg2, 0xFF, 0x10, (void *)(u32)smapGetSpriteHandle(), 1, *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), temp, 1.0f, 1.0f, D_00794D20);
        return;
    }
    sdkSpriteDrawQueued(*(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, arg2, 0xFF, 0x10, (void *)(u32)smapGetSpriteHandle(), 1, *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), temp, 1.0f, 1.0f, D_00794DE0);
}
// FUN_002B3C50
void mapSymbolMarkerSetHighlight(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0x20] = arg1;
}

// FUN_002B3C60
void mapSymbolMarkerSetVariant(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0x21] = arg1;
}

// FUN_002B3C70
s32 mapSymbolPointUpdate(u8 *arg0)
{
    u8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord0;
    s64 coord1;
    f32 keep;
    f32 ty;
    f32 tx;
    s32 dx;
    s32 dy;

    p = *(u8 **)(arg0 + 0x38);
    fclAnchorOffset((f32 *)&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s8 *)p == 0) {
        if (K_FldEvent_ArePosWithinDist(p + 0xC,
                          (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30,
                          4800.0f) == 1 &&
            (s8)smapRevealTestBit(p[0x18], p[0x19]) == 1) {
            dx = (s8)(p[0x18] -
                      smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
            dy = (s8)(p[0x19] -
                      smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
            *(f32 *)(base + 0) += 17.0f;
            *(f32 *)(base + 4) += 264.0f;
            keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                   smapPositionOffsetX(18.0f, (YVec3f *)(p + 0xC));
            keep +=
                smapPlayerOffsetX(
                    *(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 10.0f;
            *(f32 *)&out = keep;
            keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                   smapPositionOffsetZ(18.0f, (YVec3f *)(p + 0xC));
            keep +=
                smapPlayerOffsetZ(
                    *(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 10.0f;
            *((f32 *)&out + 1) = keep;
            coord0 = out;
            sdkSpriteDrawQueued(*(f32 *)&coord0, *((f32 *)&coord0 + 1), (f32)0xEA63, fclPackRgba(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
        }
    } else if (*(s8 *)p == 1 &&
               (s8)smapRevealTestBit(p[0x18], p[0x19]) == 1) {
        keep = 172.0f + 18.0f * (f32)p[0x18] -
               smapPositionOffsetX(18.0f, (YVec3f *)(p + 0xC));
        keep -= 2.0f;
        *(f32 *)&out = keep;
        keep = 9.0f + 18.0f * (f32)p[0x19] -
               smapPositionOffsetZ(18.0f, (YVec3f *)(p + 0xC));
        keep -= 2.0f;
        *((f32 *)&out + 1) = keep;
        coord1 = out;
        sdkSpriteDrawQueued(*(f32 *)&coord1, *((f32 *)&coord1 + 1), (f32)0xEA63, fclPackRgba(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
    }
    return 0;
}
// FUN_002B4110
void mapSymbolPointDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4140
s32 mapSymbolPointCreate(s32 arg0, s32 arg1, Vec3 *arg2)
{
    s32 ret;
    u8 *work;
    Vec3 v;

    v = *arg2;
    chkmemAllocSiteTag(D_0063F120, 0x18D);
    work = D_008873F4[0](1, 0x1C, 0x40000);
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0063F140), 0xF, 0, 0, mapSymbolPointUpdate, mapSymbolPointDestroy, (u8 *)(work));
    *(Vec3 *)(work + 0xC) = v;
    work[1] = arg1;
    work[0x18] = smapWorldToColumn(*(RwV3d *)&v);
    work[0x19] = smapWorldToRow(*(RwV3d *)&v);
    return ret;
}

// FUN_002B4240
void mapSymbolPointSetState(u8 *arg0, s8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0] = arg1;
}

// FUN_002B4250
s32 mapSymbolEntityUpdate(u8 *arg0)
{
    s8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord0;
    s64 coord1;
    f32 keep;
    f32 tx;
    f32 ty;
    s32 dx;
    s32 dy;
    s32 a;
    s32 b;
    s32 f;
    s32 e;
    s32 var_3;
    u8 *o;
    u8 *h;

    p = *(s8 **)(arg0 + 0x38);
    fclAnchorOffset((f32 *)&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*p == 0) {
        h = (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30;
        o = (u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30;
        if (datGetFlag(0x1012) == 0) {
            if (K_FldEvent_ArePosWithinDist(o, h, 2400.0f) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        } else {
            if (K_FldEvent_ArePosWithinDist(o, h, (f32)0x1770) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        }
        var_3 = 0;
vtest1:
        if (var_3 == 1) {
            a = smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) & 0xFF;
            b = smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) & 0xFF;
            if (datGetFlag(0x1012) == 0) {
                if ((s8)smapRevealTestBit(a, b) == 1) {
                    var_3 = 1;
                    goto vtest2;
                }
            } else {
                var_3 = 1;
                goto vtest2;
            }
            var_3 = 0;
vtest2:
            if (var_3 == 1) {
                dx = (s8)((a & 0xFF) - smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
                dy = (s8)((b & 0xFF) - smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
                *(f32 *)(base + 0) += 17.0f;
                *(f32 *)(base + 4) += 264.0f;
                keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                       smapPlayerOffsetX(*(u8 **)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep += smapPlayerOffsetX(*(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
                keep -= 10.0f;
                *(f32 *)&out = keep;
                keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                       smapPlayerOffsetZ(*(u8 **)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep += smapPlayerOffsetZ(*(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
                keep -= 10.0f;
                *((f32 *)&out + 1) = keep;
                coord0 = out;
                sdkSpriteDrawQueued(*(f32 *)&coord0, *((f32 *)&coord0 + 1), (f32)0xEA64, fclPackRgba(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
    } else if (*p == 1) {
        h = (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30;
        o = (u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30;
        if (datGetFlag(0x1012) == 0) {
            if (K_FldEvent_ArePosWithinDist(o, h, 2400.0f) == 1) {
                var_3 = 1;
                goto vtest3;
            }
        } else {
            if (K_FldEvent_ArePosWithinDist(o, h, (f32)0x1770) == 1) {
                var_3 = 1;
                goto vtest3;
            }
        }
        var_3 = 0;
vtest3:
        if (var_3 == 1) {
            f = smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) & 0xFF;
            e = smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) & 0xFF;
            if (datGetFlag(0x1012) == 0) {
                if ((s8)smapRevealTestBit(f, e) == 1) {
                    var_3 = 1;
                    goto vtest4;
                }
            } else {
                var_3 = 1;
                goto vtest4;
            }
            var_3 = 0;
vtest4:
            if (var_3 == 1) {
                keep = 172.0f + 18.0f * (f32)smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) -
                       smapPlayerOffsetX(*(u8 **)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep -= 2.0f;
                *(f32 *)&out = keep;
                keep = 9.0f + 18.0f * (f32)smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30)) -
                       smapPlayerOffsetZ(*(u8 **)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep -= 2.0f;
                *((f32 *)&out + 1) = keep;
                coord1 = out;
                sdkSpriteDrawQueued(*(f32 *)&coord1, *((f32 *)&coord1 + 1), (f32)0xEA64, fclPackRgba(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
    }
    return 0;
}
// FUN_002B49E0
void mapSymbolEntityDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4A10
s32 mapSymbolEntityCreate(s32 arg0, s32 arg1)
{
    u8 *work;
    s32 ret;

    chkmemAllocSiteTag(D_0063F120, 0x215);
    work = D_008873F4[0](1, 0xC, 0x40000);
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0063F150), 0xF, 0, 0, mapSymbolEntityUpdate, mapSymbolEntityDestroy, (u8 *)(work));
    work[1] = arg1;
    return ret;
}

// FUN_002B4AC0
void mapSymbolTargetSetState(u8 *arg0, s8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0] = arg1;
}

/* Native b210 O2: 1236/1248 bytes, 38 resolved relocations and
 * twelve zero alignment bytes. Preserve complete coordinate
 * snapshots and the providers' float-first argument order.
 * See docs/probe_archive/Map_symbol_002b4ad0_20260924.md. */
// FUN_002B4AD0
s32 mapSymbolTargetUpdate(u8 *arg0)
{
    u8 *p;
    union { u8 bytes[8]; f32 values[2]; } base;
    union { Vec2 point; s64 packed; } out;
    Vec2 temp;
    union { f32 values[2]; s64 packed; } coord;
    f32 keep;
    f32 tx;
    f32 ty;
    s32 dx;
    s32 dy;
    s32 a;
    s32 b;
    s8 p8;
    s32 var_3;
    Vec2 v;

    p = *(u8 **)(arg0 + 0x38);
    fclAnchorOffset((f32 *)&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base.bytes + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base.bytes + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s32 *)((u8 *)&D_007E80A8 + p[0xB] * 0x168) == 1) {
        return 0;
    }
    p8 = p[8];
    if (p8 == 0) {
        b = p[0xA];
        a = p[9];
        if (datGetFlag(0x1013) == 0) {
            if ((s8)smapRevealTestBit(a, b) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        } else {
            var_3 = 1;
            goto vtest1;
        }
        var_3 = 0;
vtest1:
        if (var_3 == 1) {
            dx = (s8)(p[9] - smapWorldToColumn(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
            dy = (s8)(p[0xA] - smapWorldToRow(*(RwV3d *)((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30)));
            *(f32 *)(base.bytes + 0) += 17.0f;
            *(f32 *)(base.bytes + 4) += 264.0f;
            keep = *(f32 *)(base.bytes + 0) + 18.0f * (f32)dx -
                   smapPositionOffsetX(18.0f, (YVec3f *)((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150));
            keep += smapPlayerOffsetX(*(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            out.point.x = keep;
            keep = *(f32 *)(base.bytes + 4) + 18.0f * (f32)dy -
                   smapPositionOffsetZ(18.0f, (YVec3f *)((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150));
            keep += smapPlayerOffsetZ(*(u8 **)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            out.point.y = keep;
            if (!(out.point.x < 1.0f) &&
                (out.point.x <= 164.0f) &&
                !(out.point.y < 248.0f) &&
                (out.point.y <= (f32)0x19B)) {
                coord.packed = out.packed;
                sdkSpriteDrawQueued(
                    coord.values[0], coord.values[1], (f32)0xEA65,
                    fclPackRgba(255, 255, 255, 255), 0xFF, 0x12,
                    (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                    D_00794DB0);
            }
        }
    } else if (p8 == 1) {
        b = p[0xA];
        a = p[9];
        if (datGetFlag(0x1013) == 0) {
            if ((s8)smapRevealTestBit(a, b) == 1) {
                var_3 = 1;
                goto vtest2;
            }
        } else {
            var_3 = 1;
            goto vtest2;
        }
        var_3 = 0;
vtest2:
        if (var_3 == 1) {
            v = *(Vec2 *)p;
            sdkSpriteDrawQueued(
                v.x, v.y, (f32)0xEA65,
                fclPackRgba(255, 255, 255, 255), 0xFF, 0x12,
                (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                D_00794CF0);
        }
    }
end:
    return 0;
}
// FUN_002B4FB0
void mapSymbolTargetDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4FE0
s32 mapSymbolTargetCreate(s32 arg0, Vec2 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;
    u8 *e;

    chkmemAllocSiteTag(D_0063F120, 0x28A);
    work = D_008873F4[0](1, 0xC, 0x40000);
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0063F160), 0xF, 0, 0, mapSymbolTargetUpdate, mapSymbolTargetDestroy, (u8 *)(work));
    *(Vec2 *)work = arg1;
    work[8] = 0;
    e = (u8 *)&D_007E80A0 + (arg2 & 0xFF) * 0x168 + 0x150;
    work[9] = smapWorldToColumn(*(RwV3d *)e);
    work[0xA] = smapWorldToRow(*(RwV3d *)e);
    work[0xB] = arg2;
    return ret;
}

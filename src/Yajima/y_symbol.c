#include "mt_scene_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - y_symbol.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "g_data_internal.h"
#include "kwln_task_internal.h"
#include "member_access.h"
#include "rw_camera_internal.h"
#include "resrc_manager_internal.h"

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

#include "rw_types_internal.h"
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
/* +8 interior alias of the 0x168-byte target slots; one disables its marker. */
typedef struct MapSymbolTargetState {
    s32 state;
    u8 pad04[0x164];
} MapSymbolTargetState;
extern MapSymbolTargetState D_007E80A8[];
/* Linker aliases start at the model and resource words of 0x750-byte actor slots. */
typedef struct MapSymbolActorHandles {
    u32 model;
    u8 *resource;
    u8 pad08[0x748];
} MapSymbolActorHandles;
typedef struct MapSymbolActorResource {
    u8 *resource;
    u8 pad04[0x74C];
} MapSymbolActorResource;
extern MapSymbolActorHandles D_007E8C50[];
extern MapSymbolActorResource D_007E8C54[];

extern u32 D_007EFA00[];
extern u8 *D_007EFA04[];

extern void chkmemAllocSiteTag(void *file, s32 line);

extern s32 K_FldEvent_ArePosWithinDist(u8 *posA, u8 *posB, f32 maxDist);
extern f32 KDraw_MatrixYawDeg(u8 *matrix);
extern void *mdlGetMatrix(void *model);
extern s32 smapGetSpriteHandle(void);
extern s64 smapRevealTestBit(s32 column, s32 row);
extern s32 smapWorldToColumn(RwV3d position);
extern s32 smapWorldToRow(RwV3d position);
extern f32 smapPlayerOffsetX(u8 *task, f32 cellSize);
extern f32 smapPlayerOffsetZ(u8 *task, f32 cellSize);
extern f32 smapPositionOffsetX(f32 cellSize, YVec3f *position);
extern f32 smapPositionOffsetZ(f32 cellSize, YVec3f *position);
extern s32 ySymbolIsEnabled(void);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern void fclAnchorOffset(f32 *destination, s64 mode, f32 width, f32 height, f32 referenceWidth,
                          f32 referenceHeight);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sdkSpriteScaledWidth(u8 *sprite);
extern f32 sdkSpriteScaledHeight(u8 *sprite);
extern u8 *sdkSpriteNewNode(s32 packAddress, s32 recordIndex);
extern void sdkSpriteFreeNode(void *node);

extern s32 mapSymbolTaskUpdate(u8 *task);
extern void mapSymbolMarkerDestroy(u8 *task);
extern s32 mapSymbolPointUpdate(u8 *task);
extern s32 mapSymbolEntityUpdate(u8 *task);
extern s32 mapSymbolTargetUpdate(u8 *task);

/* Allocations in the four constructors establish these independent work records. */
typedef union MapSymbolValue {
    f32 value;
    u32 bits;
} MapSymbolValue;

typedef struct MapSymbolMarker {
    u32 self;
    u32 resource;
    MapSymbolValue unk08, unk0C, angle;
    s16 centerX, centerY;
    u8 pad18[8];
    u8 mode, hidden; /* mapSymbolTaskUpdate selects fixed mode and suppresses hidden markers. */
    u8 pad22[2];
} MapSymbolMarker;

typedef struct MapSymbolPoint {
    s8 mode;
    u8 index;
    u8 pad02[10];
    Vec3 position;
    u8 column, row;
    u8 pad1A[2];
} MapSymbolPoint;

typedef struct MapSymbolEntity {
    s8 mode, actorIndex;
    u8 pad02[10];
} MapSymbolEntity;

typedef struct MapSymbolTarget {
    Vec2 position;
    s8 mode;
    u8 column, row, targetIndex;
} MapSymbolTarget;
/* Create the player-direction marker and cache the sprite half-size used as its rotation center. */
// FUN_002B3990
s32 mapSymbolMarkerCreate(s32 parent)
{
    s32 taskHandle;
    u8 *work;
    u8 *sprite;

    chkmemAllocSiteTag(D_0063F120, 0x98);
    work = D_008873F4[0](1, 0x24, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063F130), 0xF, 0, 0, mapSymbolTaskUpdate, mapSymbolMarkerDestroy, (u8 *)(work));
    ((MapSymbolMarker *)work)->resource = (u32)MT_Scene_GetRes(0x400);
    ((MapSymbolMarker *)work)->self = (u32)work;
    ((MapSymbolMarker *)work)->unk08.bits = 0x3F400000;
    ((MapSymbolMarker *)work)->unk0C.bits = 0x3F400000;
    ((MapSymbolMarker *)work)->angle.bits = 0;
    ((MapSymbolMarker *)work)->mode = 0;
    sprite = sdkSpriteNewNode(smapGetSpriteHandle(), 0x10);
    ((MapSymbolMarker *)work)->centerX = (s16)(s32)(sdkSpriteScaledWidth(sprite) / 2.0f);
    ((MapSymbolMarker *)work)->centerY = (s16)(s32)(sdkSpriteScaledHeight(sprite) / 2.0f);
    sdkSpriteFreeNode(sprite);
    return taskHandle;
}
/* Re-derived body: the prior nd118 candidate is retained in
   build/WBHygiene_func_002b3ae0_archive.txt for provenance; this body is
   verified MATCH after correcting the callee ABI and arithmetic statement
   order. */
/* Rotate the player marker relative to model yaw, with the selected highlight palette. */
// FUN_002B3AE0
void mapSymbolMarkerDraw(u8 *task, s64 position, f32 depth, s32 color)
{
    f32 savedDepth;
    u8 *marker;
    f32 angle;
    f32 drawAngle;

    savedDepth = depth;
    marker = ((KwlnTask *)task)->work;
    angle = KDraw_MatrixYawDeg((u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]));
    if (angle >= 0.0f) {
        drawAngle = angle - 180.0f;
    } else {
        drawAngle = angle;
        drawAngle += 180.0f;
    }
    drawAngle += ((MapSymbolMarker *)marker)->angle.value;
    drawAngle *= -1.0f;
    if ((s8)((MapSymbolMarker *)marker)->mode == 1) {
        sdkSpriteDrawQueued(*(f32 *)&position, *((f32 *)&position + 1), savedDepth, color, 0xFF, 0x10, (void *)(u32)smapGetSpriteHandle(), 1, ((MapSymbolMarker *)marker)->centerX, ((MapSymbolMarker *)marker)->centerY, drawAngle, 1.0f, 1.0f, D_00794D20);
        return;
    }
    sdkSpriteDrawQueued(*(f32 *)&position, *((f32 *)&position + 1), savedDepth, color, 0xFF, 0x10, (void *)(u32)smapGetSpriteHandle(), 1, ((MapSymbolMarker *)marker)->centerX, ((MapSymbolMarker *)marker)->centerY, drawAngle, 1.0f, 1.0f, D_00794DE0);
}
/* Select the directional marker palette without changing its hidden state. */
// FUN_002B3C50
void mapSymbolMarkerSetHighlight(u8 *task, u8 mode)
{
    u8 *marker;

    marker = ((KwlnTask *)task)->work;
    ((MapSymbolMarker *)marker)->mode = mode;
}

/* Set the player marker suppression byte consumed by the marker task callback. */
// FUN_002B3C60
void mapSymbolMarkerSetVariant(u8 *task, u8 hidden)
{
    u8 *marker;

    marker = ((KwlnTask *)task)->work;
    ((MapSymbolMarker *)marker)->hidden = hidden;
}

/* Packed float pairs preserve sprite ABI snapshots; typed interior aliases retain native actor/target strides. */
// FUN_002B3C70
/* Draw a revealed scene point in the scrolling minimap or fixed full-map coordinate system. */
s32 mapSymbolPointUpdate(u8 *task)
{
    MapSymbolPoint *pointData;
    u8 *point;
    u8 origin[8];
    s64 position;
    Vec2 anchor;
    s64 scrollPosition;
    s64 fixedPosition;
    f32 coordinate;
    f32 anchorY;
    f32 anchorX;
    s32 columnDelta;
    s32 rowDelta;

    point = ((KwlnTask *)task)->work;
    pointData = (MapSymbolPoint *)point;
    fclAnchorOffset((f32 *)&anchor, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    ((Vec2 *)origin)->x = (anchorX = anchor.x, anchorY = anchor.y, anchorX);
    ((Vec2 *)origin)->y = anchorY;
    if (ySymbolIsEnabled() == 0) {
        return 0;
    }
    if (((MapSymbolPoint *)point)->mode == 0) {
        if (K_FldEvent_ArePosWithinDist(point + 0xC,
                          (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30,
                          4800.0f) == 1 &&
            (s8)smapRevealTestBit(((MapSymbolPoint *)point)->column, ((MapSymbolPoint *)point)->row) == 1) {
            columnDelta = (s8)(pointData->column -
                      smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
            rowDelta = (s8)(pointData->row -
                      smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
            ((Vec2 *)origin)->x += 17.0f;
            MEMBER(f32, origin, Vec2, y) += 264.0f;
            coordinate = ((Vec2 *)origin)->x + 18.0f * (f32)columnDelta -
                   smapPositionOffsetX(18.0f, (YVec3f *)(point + 0xC));
            coordinate +=
                smapPlayerOffsetX(
                    (u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
            coordinate -= 10.0f;
            *(f32 *)&position = coordinate;
            coordinate = MEMBER(f32, origin, Vec2, y) + 18.0f * (f32)rowDelta -
                   smapPositionOffsetZ(18.0f, (YVec3f *)(point + 0xC));
            coordinate +=
                smapPlayerOffsetZ(
                    (u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
            coordinate -= 10.0f;
            *((f32 *)&position + 1) = coordinate;
            scrollPosition = position;
            sdkSpriteDrawQueued(*(f32 *)&scrollPosition, *((f32 *)&scrollPosition + 1), (f32)0xEA63, fclPackRgba(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
        }
    } else if (((MapSymbolPoint *)point)->mode == 1 &&
               (s8)smapRevealTestBit(((MapSymbolPoint *)point)->column, ((MapSymbolPoint *)point)->row) == 1) {
        coordinate = 172.0f + 18.0f * (f32)pointData->column -
               smapPositionOffsetX(18.0f, (YVec3f *)(point + 0xC));
        coordinate -= 2.0f;
        *(f32 *)&position = coordinate;
        coordinate = 9.0f + 18.0f * (f32)pointData->row -
               smapPositionOffsetZ(18.0f, (YVec3f *)(point + 0xC));
        coordinate -= 2.0f;
        *((f32 *)&position + 1) = coordinate;
        fixedPosition = position;
        sdkSpriteDrawQueued(*(f32 *)&fixedPosition, *((f32 *)&fixedPosition + 1), (f32)0xEA63, fclPackRgba(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
    }
    return 0;
}
// FUN_002B4110
void mapSymbolPointDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create a scene-point marker and cache its world position and minimap coordinates. */
// FUN_002B4140
s32 mapSymbolPointCreate(s32 parent, s32 index, Vec3 *position)
{
    s32 taskHandle;
    u8 *work;
    Vec3 positionCopy;

    positionCopy = *position;
    chkmemAllocSiteTag(D_0063F120, 0x18D);
    work = D_008873F4[0](1, 0x1C, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063F140), 0xF, 0, 0, mapSymbolPointUpdate, mapSymbolPointDestroy, (u8 *)(work));
    ((MapSymbolPoint *)work)->position = positionCopy;
    ((MapSymbolPoint *)work)->index = index;
    ((MapSymbolPoint *)work)->column = smapWorldToColumn(*(RwV3d *)&positionCopy);
    ((MapSymbolPoint *)work)->row = smapWorldToRow(*(RwV3d *)&positionCopy);
    return taskHandle;
}

/* Choose scrolling or fixed-map coordinates for a scene-point marker task. */
// FUN_002B4240
void mapSymbolPointSetState(u8 *task, s8 mode)
{
    u8 *point;

    point = ((KwlnTask *)task)->work;
    ((MapSymbolPoint *)point)->mode = mode;
}

/* Packed float pairs preserve sprite ABI snapshots; typed interior aliases retain native actor/target strides. */
// FUN_002B4250
/* Draw an active actor marker when it is in range and its map cell is revealed. */
s32 mapSymbolEntityUpdate(u8 *task)
{
    MapSymbolEntity *entityData;
    s8 *entity;
    u8 origin[8];
    s64 position;
    Vec2 anchor;
    s64 scrollPosition;
    s64 fixedPosition;
    f32 coordinate;
    f32 anchorX;
    f32 anchorY;
    s32 columnDelta;
    s32 rowDelta;
    s32 column;
    s32 row;
    s32 fixedColumn;
    s32 fixedRow;
    s32 visible;
    u8 *actorPosition;
    u8 *playerPosition;

    entity = (s8 *)((KwlnTask *)task)->work;
    entityData = (MapSymbolEntity *)entity;
    fclAnchorOffset((f32 *)&anchor, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    ((Vec2 *)origin)->x = (anchorX = anchor.x, anchorY = anchor.y, anchorX);
    ((Vec2 *)origin)->y = anchorY;
    if (ySymbolIsEnabled() == 0) {
        return 0;
    }
    if (((MapSymbolEntity *)entity)->mode == 0) {
        playerPosition = (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30;
        actorPosition = (u8 *)mdlGetMatrix((void *)(u32)D_007E8C50[((MapSymbolEntity *)entity)->actorIndex].model) + 0x30;
        if (datGetFlag(0x1012) == 0) {
            if (K_FldEvent_ArePosWithinDist(actorPosition, playerPosition, 2400.0f) == 1) {
                visible = 1;
                goto vtest1;
            }
        } else {
            if (K_FldEvent_ArePosWithinDist(actorPosition, playerPosition, (f32)0x1770) == 1) {
                visible = 1;
                goto vtest1;
            }
        }
        visible = 0;
vtest1:
        if (visible == 1) {
            column = smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) & 0xFF;
            row = smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) & 0xFF;
            if (datGetFlag(0x1012) == 0) {
                if ((s8)smapRevealTestBit(column, row) == 1) {
                    visible = 1;
                    goto vtest2;
                }
            } else {
                visible = 1;
                goto vtest2;
            }
            visible = 0;
vtest2:
            if (visible == 1) {
                columnDelta = (s8)((column & 0xFF) - smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
                rowDelta = (s8)((row & 0xFF) - smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
                ((Vec2 *)origin)->x += 17.0f;
                MEMBER(f32, origin, Vec2, y) += 264.0f;
                coordinate = ((Vec2 *)origin)->x + 18.0f * (f32)columnDelta -
                       smapPlayerOffsetX((u8 *)((ResrcRecord *)D_007E8C54[entityData->actorIndex].resource)->handle220, 18.0f);
                coordinate += smapPlayerOffsetX((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
                coordinate -= 10.0f;
                *(f32 *)&position = coordinate;
                coordinate = MEMBER(f32, origin, Vec2, y) + 18.0f * (f32)rowDelta -
                       smapPlayerOffsetZ((u8 *)((ResrcRecord *)D_007E8C54[entityData->actorIndex].resource)->handle220, 18.0f);
                coordinate += smapPlayerOffsetZ((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
                coordinate -= 10.0f;
                *((f32 *)&position + 1) = coordinate;
                scrollPosition = position;
                sdkSpriteDrawQueued(*(f32 *)&scrollPosition, *((f32 *)&scrollPosition + 1), (f32)0xEA64, fclPackRgba(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
    } else if (((MapSymbolEntity *)entity)->mode == 1) {
        playerPosition = (u8 *)mdlGetMatrix((void *)(u32)D_007EFA00[0]) + 0x30;
        actorPosition = (u8 *)mdlGetMatrix((void *)(u32)D_007E8C50[((MapSymbolEntity *)entity)->actorIndex].model) + 0x30;
        if (datGetFlag(0x1012) == 0) {
            if (K_FldEvent_ArePosWithinDist(actorPosition, playerPosition, 2400.0f) == 1) {
                visible = 1;
                goto vtest3;
            }
        } else {
            if (K_FldEvent_ArePosWithinDist(actorPosition, playerPosition, (f32)0x1770) == 1) {
                visible = 1;
                goto vtest3;
            }
        }
        visible = 0;
vtest3:
        if (visible == 1) {
            fixedColumn = smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) & 0xFF;
            fixedRow = smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) & 0xFF;
            if (datGetFlag(0x1012) == 0) {
                if ((s8)smapRevealTestBit(fixedColumn, fixedRow) == 1) {
                    visible = 1;
                    goto vtest4;
                }
            } else {
                visible = 1;
                goto vtest4;
            }
            visible = 0;
vtest4:
            if (visible == 1) {
                coordinate = 172.0f + 18.0f * (f32)smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) -
                       smapPlayerOffsetX((u8 *)((ResrcRecord *)D_007E8C54[entityData->actorIndex].resource)->handle220, 18.0f);
                coordinate -= 2.0f;
                *(f32 *)&position = coordinate;
                coordinate = 9.0f + 18.0f * (f32)smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007E8C50[entityData->actorIndex].model))->pos) -
                       smapPlayerOffsetZ((u8 *)((ResrcRecord *)D_007E8C54[entityData->actorIndex].resource)->handle220, 18.0f);
                coordinate -= 2.0f;
                *((f32 *)&position + 1) = coordinate;
                fixedPosition = position;
                sdkSpriteDrawQueued(*(f32 *)&fixedPosition, *((f32 *)&fixedPosition + 1), (f32)0xEA64, fclPackRgba(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
    }
    return 0;
}
// FUN_002B49E0
void mapSymbolEntityDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create a minimap marker bound to an actor-slot index. */
// FUN_002B4A10
s32 mapSymbolEntityCreate(s32 parent, s32 actorIndex)
{
    u8 *work;
    s32 taskHandle;

    chkmemAllocSiteTag(D_0063F120, 0x215);
    work = D_008873F4[0](1, 0xC, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063F150), 0xF, 0, 0, mapSymbolEntityUpdate, mapSymbolEntityDestroy, (u8 *)(work));
    ((MapSymbolEntity *)work)->actorIndex = actorIndex;
    return taskHandle;
}

/* Set an actor-marker coordinate mode through the entity work record. */
// FUN_002B4AC0
void mapSymbolTargetSetState(u8 *task, s8 mode)
{
    u8 *entity;

    entity = ((KwlnTask *)task)->work;
    ((MapSymbolEntity *)entity)->mode = mode;
}

/* Native b210 O2: 1236/1248 bytes, 38 resolved relocations and
 * twelve zero alignment bytes. Preserve complete coordinate
 * snapshots and the providers' float-first argument order.
 * See docs/probe_archive/Map_symbol_002b4ad0_20260924.md. */
/* Packed float pairs preserve sprite ABI snapshots; typed interior aliases retain native actor/target strides. */
// FUN_002B4AD0
/* Draw a revealed target marker; scrolling mode clips it to the minimap rectangle. */
s32 mapSymbolTargetUpdate(u8 *task)
{
    MapSymbolTarget *targetData;
    u8 *target;
    union { u8 bytes[8]; f32 values[2]; Vec2 point; } origin;
    union { Vec2 point; s64 packed; } position;
    Vec2 anchor;
    union { f32 values[2]; s64 packed; } drawPosition;
    f32 coordinate;
    f32 anchorX;
    f32 anchorY;
    s32 columnDelta;
    s32 rowDelta;
    s32 column;
    s32 row;
    s8 mode;
    s32 visible;
    Vec2 fixedPosition;

    target = ((KwlnTask *)task)->work;
    targetData = (MapSymbolTarget *)target;
    fclAnchorOffset((f32 *)&anchor, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    ((Vec2 *)origin.bytes)[0].x = (anchorX = anchor.x, anchorY = anchor.y, anchorX);
    origin.values[1] = anchorY;
    if (ySymbolIsEnabled() == 0) {
        return 0;
    }
    if (D_007E80A8[((MapSymbolTarget *)target)->targetIndex].state == 1) {
        return 0;
    }
    mode = MEMBER(u8, target, MapSymbolTarget, mode);
    if (mode == 0) {
        row = ((MapSymbolTarget *)target)->row;
        column = ((MapSymbolTarget *)target)->column;
        if (datGetFlag(0x1013) == 0) {
            if ((s8)smapRevealTestBit(column, row) == 1) {
                visible = 1;
                goto vtest1;
            }
        } else {
            visible = 1;
            goto vtest1;
        }
        visible = 0;
vtest1:
        if (visible == 1) {
            columnDelta = (s8)(targetData->column - smapWorldToColumn(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
            rowDelta = (s8)(targetData->row - smapWorldToRow(((RwMatrixTag *)mdlGetMatrix((void *)(u32)D_007EFA00[0]))->pos));
            origin.values[0] += 17.0f;
            origin.values[1] += 264.0f;
            coordinate = origin.values[0] + 18.0f * (f32)columnDelta -
                   smapPositionOffsetX(18.0f, (YVec3f *)((u8 *)&D_007E80A0 + targetData->targetIndex * 0x168 + 0x150));
            coordinate += smapPlayerOffsetX((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
            coordinate -= 13.0f;
            position.point.x = coordinate;
            coordinate = origin.values[1] + 18.0f * (f32)rowDelta -
                   smapPositionOffsetZ(18.0f, (YVec3f *)((u8 *)&D_007E80A0 + targetData->targetIndex * 0x168 + 0x150));
            coordinate += smapPlayerOffsetZ((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220, 18.0f);
            coordinate -= 13.0f;
            position.point.y = coordinate;
            if (!(position.point.x < 1.0f) &&
                (position.point.x <= 164.0f) &&
                !(position.point.y < 248.0f) &&
                (position.point.y <= (f32)0x19B)) {
                drawPosition.packed = position.packed;
                sdkSpriteDrawQueued(
                    drawPosition.values[0], drawPosition.values[1], (f32)0xEA65,
                    fclPackRgba(255, 255, 255, 255), 0xFF, 0x12,
                    (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                    D_00794DB0);
            }
        }
    } else if (mode == 1) {
        row = ((MapSymbolTarget *)target)->row;
        column = ((MapSymbolTarget *)target)->column;
        if (datGetFlag(0x1013) == 0) {
            if ((s8)smapRevealTestBit(column, row) == 1) {
                visible = 1;
                goto vtest2;
            }
        } else {
            visible = 1;
            goto vtest2;
        }
        visible = 0;
vtest2:
        if (visible == 1) {
            fixedPosition = ((MapSymbolTarget *)target)->position;
            sdkSpriteDrawQueued(
                fixedPosition.x, fixedPosition.y, (f32)0xEA65,
                fclPackRgba(255, 255, 255, 255), 0xFF, 0x12,
                (void *)(u32)smapGetSpriteHandle(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                D_00794CF0);
        }
    }
end:
    return 0;
}
// FUN_002B4FB0
void mapSymbolTargetDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create a target marker with a fixed-map position and cached reveal-cell coordinates. */
// FUN_002B4FE0
s32 mapSymbolTargetCreate(s32 parent, Vec2 position, s32 targetIndex)
{
    s32 taskHandle;
    u8 *work;
    u8 *targetPosition;

    chkmemAllocSiteTag(D_0063F120, 0x28A);
    work = D_008873F4[0](1, 0xC, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063F160), 0xF, 0, 0, mapSymbolTargetUpdate, mapSymbolTargetDestroy, (u8 *)(work));
    ((MapSymbolTarget *)work)->position = position;
    ((MapSymbolTarget *)work)->mode = 0;
    targetPosition = (u8 *)&D_007E80A0 + (targetIndex & 0xFF) * 0x168 + 0x150;
    ((MapSymbolTarget *)work)->column = smapWorldToColumn(*(RwV3d *)targetPosition);
    ((MapSymbolTarget *)work)->row = smapWorldToRow(*(RwV3d *)targetPosition);
    ((MapSymbolTarget *)work)->targetIndex = targetIndex;
    return taskHandle;
}

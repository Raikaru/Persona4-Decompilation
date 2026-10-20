#ifndef BTL_TARGET_INTERNAL_H
#define BTL_TARGET_INTERNAL_H

#include "btl_action_internal.h"
#include "btl_ai_internal.h"
#include "btl_effect_internal.h"
#include "btl_sound_internal.h"

/* The angle helper consumes the nested quaternion; the arc builder passes the
 * endpoint pair, angle and mode to the existing quaternion interpolator. */
typedef struct BtlTargetQuaternionHolder { BtlCameraQuaternion quat; } BtlTargetQuaternionHolder;
typedef struct BtlTargetRotationInterpolation {
    BtlCameraQuaternion first, second;
    f32 angle;
    s32 mode;
} BtlTargetRotationInterpolation;

/* Cleared as 0x5C bytes; the AI selectors and procedure commands share this work. */
typedef struct BtlTargetRecord {
    u32 targets[12];
    u8 procedureActive;
    u8 pad31;
    u16 count;
    u16 kind;
    u16 command;
    u16 skill;
    u8 pad3A[4];
    u16 plan[3];
    u8 pad44[0x0C];
    u32 unk50;
    u32 unk54;
    u32 unk58;
} BtlTargetRecord;

/* Packet 0xD00 allocates 0x10 bytes, consumed by btlTargetSpawnActionProc. */
typedef struct BtlTargetProcedure {
    s32 action;
    s32 procedure;
    s32 started;
    s32 script;
} BtlTargetProcedure;

/* Two packet UIDs written by the formation script and polled together.
 * They occupy the 0x10-byte boss-work gap at battle +0xBD0. */
typedef struct BtlTargetFormationPackets { s64 firstUID, secondUID; } BtlTargetFormationPackets;

/* Script variable storage is the 0x40-byte gap at battle +0xDD8..0xE17. */
typedef struct BtlTargetScriptGlobals { s32 values[16]; } BtlTargetScriptGlobals;

/* Community assistance selection occupies action +0x444..0x44B. */
typedef struct BtlTargetAssistance {
    u8 *action;
    s16 kind;
    u8 pad06[2];
} BtlTargetAssistance;

/* Five 32-bit words shared by InitSpring and SmoothStep. */
typedef struct BtlTargetSpring {
    f32 duration;
    f32 remaining;
    f32 curvature;
    union { f32 value; s32 bits; } slope;
    union { f32 value; s32 bits; } result;
} BtlTargetSpring;

/* Route builders write 128 XZ pairs followed by count/cursor/state. */
typedef struct BtlTargetPoint { f32 x, z; } BtlTargetPoint;
typedef struct BtlTargetRoute {
    BtlTargetPoint points[128];
    u16 count;
    u16 cursor;
    u8 state;
} BtlTargetRoute;

/* Obstacle corners have a 0x130-byte stride. Group list links follow four
 * corners at 0x4C8/0x4CC; positions and link metrics are written by radius setup. */
typedef struct BtlTargetCorner {
    BtlTargetPoint position;
    BtlTargetPoint midpoint;
    BtlTargetPoint *link;
    f32 linkDistance;
    f32 clearance;
    f32 cost;
    f32 score;
    struct BtlTargetCorner *openNext;
    struct BtlTargetCorner *closedNext;
    struct BtlTargetCorner *parent;
    struct BtlTargetCorner *neighbors[32];
    f32 distances[32];
} BtlTargetCorner;
typedef struct BtlTargetObstacle {
    s16 cellX, cellZ;
    f32 radius;
    BtlTargetCorner corners[4];
    struct BtlTargetObstacle *previous;
    struct BtlTargetObstacle *next;
} BtlTargetObstacle;

/* Search nodes use the same stride but reserve their first eight bytes.
 * RouteNode in the path finder establishes these cost/list/neighbor offsets. */
typedef struct BtlTargetPathNode {
    u8 pad00[8];
    BtlTargetPoint position;
    u8 pad10[4];
    union { f32 value; s32 bits; } unk14;
    u8 pad18[4];
    f32 cost;
    f32 score;
    struct BtlTargetPathNode *openNext;
    struct BtlTargetPathNode *closedNext;
    struct BtlTargetPathNode *parent;
    struct BtlTargetPathNode *neighbors[32];
    f32 distances[32];
} BtlTargetPathNode;

/* Navigation work embedded in the battle allocation at +0x318. The boundary
 * coordinates start at +0x31C; start/goal search nodes start at +0x7DC/+0x90C. */
typedef struct BtlTargetNavigation {
    BtlTargetObstacle *obstacles;
    BtlTargetCorner boundary[4];
    BtlTargetPathNode start;
    BtlTargetPathNode goal;
    BtlTargetPathNode *open;
    BtlTargetPathNode *closed;
} BtlTargetNavigation;

typedef char BtlTargetRecordSizeCheck[sizeof(BtlTargetRecord) == 0x5C ? 1 : -1];
typedef char BtlTargetProcedureSizeCheck[sizeof(BtlTargetProcedure) == 0x10 ? 1 : -1];
typedef char BtlTargetCornerSizeCheck[sizeof(BtlTargetCorner) == 0x130 ? 1 : -1];
typedef char BtlTargetPathNodeSizeCheck[sizeof(BtlTargetPathNode) == 0x130 ? 1 : -1];
typedef char BtlTargetObstacleSizeCheck[sizeof(BtlTargetObstacle) == 0x4D0 ? 1 : -1];
typedef char BtlTargetRouteCountOffsetCheck[
    (u32)&((BtlTargetRoute *)0)->count == 0x400 ? 1 : -1];

#endif

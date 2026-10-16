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
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern s32 func_001b0d70(u8 *arg0);
extern s32 btlOrderRemoveActionAll(u8 *arg0);
extern u32 datCalcIsDead(s32 arg0, s32 arg1);
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
extern s32 btlUnitIsMoving(u8 *arg0);
extern void func_00194ff0(u8 *unit, u8 *position, f32 *rotation, f32 *direction);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *direction, u32 flags);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlActionSetState(BtlAction *arg0, u16 arg1);

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void btlBossCollectTargets(u8 *arg0);
extern u32 iGpffffa0b8;
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern void btlUnitUnlinkAndFree(u8 *arg0);
extern void func_001b08f0(void *arg0);
extern void btlCameraReleaseActionRefs(u8 *arg0);
extern void datUnitRemoveEncounterUnit(DatUnitEc *arg0, DatUnit *arg1);
extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
extern void datCalcClearAllBuffs(u8 *arg0);
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

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001b0020-001b07c0 */

/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
/* measured: func_001b0020 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001B0020
void btlActionEndHomeInit(u8 *arg0)
{
    extern s32 btlActionGetActiveOrQueueFront(void);
    extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
    typedef struct RwV3d { f32 x, y, z; } RwV3d;
    extern f32 btlTargetVectorDistance(const RwV3d *first, const RwV3d *second);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *position, f32 speed, u32 flags);
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    RwV3d position;
    u8 *unit;
    u8 *packet;
    u16 speed;
    u16 side;
    u16 id;
    u8 kind;
    u32 table;
    u32 offset;
    u32 record;
    u32 selector;

    unit = *(u8 **)(arg0 + 0x30);
    *(s32 *)(arg0 + 0x41C) = 0;
    if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
        if ((*(u32 *)(unit + 0x9C) & 0x40) != 0) {
            *(u32 *)(iGpffffb3ac + 0xC) |= 0x400000;
            *(u16 *)(iGpffffb3ac + 0x18) |= 6;
        }
        btlActionSetState((BtlAction *)arg0, 1);
        return;
    }
    if (arg0 == (u8 *)btlActionGetActiveOrQueueFront()) {
        btlActionSetState((BtlAction *)arg0, 1);
        return;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x400000) != 0 &&
        (*(u16 *)(iGpffffb3ac + 0x18) & 2) != 0) return;
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180001) != 0) return;
    func_00194ff0(unit, (u8 *)&position, NULL, NULL);
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0) {
        *(s32 *)(arg0 + 0x41C) = 1;
    }
    if (!(btlTargetVectorDistance((const RwV3d *)(unit + 4), &position) <= 75.0f)) {
        speed = 2;
        side = !(iGpffffb3b8[*(u16 *)(arg0 + 0x6E) * 0x28] & 2);
        id = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 2);
        kind = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
        switch (kind) {
        case 0: break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)id * 0xE8;
            record = offset + table;
            selector = side * 4;
            speed = *(u16 *)(selector + record + 0x24);
            break;
        }
        packet = (u8 *)btlUnitCreateMovePacket(*(BtlUnit **)(arg0 + 0x30), &position, D_005F6D20[speed], 0);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 1);
        *(s32 *)(arg0 + 0x41C) = 1;
    }
}

// FUN_001B0260
void btlActionEndHomeUpdate(u8 *arg0)
{
    f32 sp20[3];
    u8 *temp_2;

    if (btlUnitIsMoving(*(u8 **)(arg0 + 0x30)) == 0) {
        if (*(s32 *)(arg0 + 0x41C) == 1) {
            func_00194ff0(*(u8 **)(arg0 + 0x30), NULL, NULL, sp20);
            temp_2 = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)(*(u8 **)(arg0 + 0x30)), (const RwV3d *)(sp20), (u32)(0));
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(temp_2, 1);
        }
        btlActionSetState((BtlAction *)arg0, 1);
    }
}

// FUN_001B0300
void btlActionDeadInit(u8 *arg0)
{
    u8 *p;
    u8 status;
    u8 *work;
    s32 flags;
    s32 flags2;

    p = *(u8 **)(arg0 + 0x30);
    btlOrderRemoveActionAll(arg0);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        datCalcClearAllBuffs(*(u8 **)(p + 0xA64));
        return;
    case 1:
        func_001f2cc0(arg0);
        flags = *(s32 *)(p + 0x9C);
        if ((flags & 0x20) == 0 && (flags & 0x100) == 0) {
            work = (u8 *)func_0019bbe0((BtlUnit *)p, 0xFFFFFF, 6, 0, 4, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(work, 1);
            work = (u8 *)btlFormationCreatePacket((u32)*(s32 *)(iGpffffb3ac + 0xD48), (u32)p, (u32)p, 0, 0);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(work, 2);
            work = (u8 *)btlSoundCreateChannelCuePacket(0xA, 2, 0xA);
            *(s64 *)(work + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(work, 1);
        }
        flags2 = *(s32 *)(p + 0x9C);
        if ((flags2 & 0x40) == 0 && (flags2 & 8) != 0) {
            *(s32 *)(p + 0x9C) = flags2 & ~8;
        }
        return;
    default:
        return;
    }
}

// FUN_001B0460
void btlActionDeadUpdate(u8 *arg0)
{
    u8 status;
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    status = *(u8 *)(p + 0xA2);
    switch (status) {
    case 0:
        if (datCalcIsDead(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
                btlBossCollectTargets((u8 *)btlActionGetQueueFront());
            }
            btlActionSetState((BtlAction *)arg0, 1);
        }
        break;
    case 1:
        if ((*(s32 *)(p + 0x9C) & 0x40) == 0) {
            btlActionSetState((BtlAction *)arg0, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)(p + 0xA64), 0) == 0) {
            *(s32 *)(p + 0x9C) &= ~1;
            func_001b0d70(arg0);
            btlActionSetState((BtlAction *)arg0, 1);
        }
        break;
    default:
        break;
    }
}

// FUN_001B0590
void btlActionExitInit(u8 *arg0)
{
    s32 temp;
    u8 *p;
    s32 *field;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        field = (s32 *)(p + 0x9C);
        temp = *field;
        if (temp & 8) {
            *field = temp & ~8;
        }
    }
}

/* Retail allocates the scan as found=v1, base=v0, i=a3. The second scan walks
   a `table` copy of `base`; that copy use keeps `base` a declared local
   instead of folding into its gp load temporary. `found` declared first and
   `base` second give retail's v1/v0 pair. In the owner, the measured
   `opt_common_subs off` keeps the scan's offset and table reloads separate. */
#pragma push
/* measured: func_001b05d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_001B05D0
void btlActionExitUpdate(u8 *arg0)
{
    u8 *found;
    u8 *base;
    u8 *p;
    u8 *temp;
    u16 i;
    s32 offset;
    u8 status;
    u8 *table;

    if (*(u16 *)(arg0 + 0x1A) & 1) {
        p = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(p + 0xA0) != 0) {
            return;
        }
        status = *(u8 *)(p + 0xA2);
        switch (status) {
        case 0:
            if (*(u16 *)(arg0 + 0x18) & 0x20) {
                found = NULL;
                i = 0;
                base = (u8 *)iGpffffb3ac;
                while (i < 4U) {
                    offset = i * 4;
                    temp = *(u8 **)(base + offset + 0xC74);
                    if (temp != NULL) {
                        if (*(DatUnit **)(temp + 4) ==
                            *(DatUnit **)(p + 0xA64)) {
                            found = *(u8 **)(func_001bf3a0_add(offset, base) + 0xC74);
                            break;
                        }
                    }
                    i++;
                }
                if (found == NULL) {
                    table = base;
                    i = 0;
                    while (i < 3U) {
                        offset = i * 8;
                        temp = *(u8 **)(table + offset + 0xC94);
                        if (temp != NULL &&
                            *(DatUnit **)(temp + 4) == *(DatUnit **)(p + 0xA64)) {
                            found = temp;
                            break;
                        }
                        i++;
                    }
                }
                if (found != NULL) {
                    *(u16 *)(found + 0xA) &= 0xFFFE;
                }
                datCalcClearBadStatus(*(s32 *)(p + 0xA64), 0xFFF7FFFF);
                datCalcClearAllBuffs(*(u8 **)(p + 0xA64));
            }
            break;
        case 1:
            if (datCalcIsDead(*(s32 *)(p + 0xA64), 0) != 0) {
                datUnitRemoveEncounterUnit(*(DatUnitEc **)((u8 *)iGpffffb3ac + 0xC68),
                              *(DatUnit **)(*(u8 **)(arg0 + 0x30) + 0xA64));
            }
            break;
        }
        btlUnitUnlinkAndFree(*(u8 **)(arg0 + 0x30));
        *(u8 **)(arg0 + 0x30) = NULL;
        *(u16 *)(arg0 + 0x1A) &= 0xFFFE;
    }
    func_001b08f0(arg0);
    btlCameraReleaseActionRefs(arg0);
    *(u16 *)(arg0 + 0x1A) |= 2;
}

#pragma pop
// FUN_001B07C0
void btlActionTestInit(void)
{
}


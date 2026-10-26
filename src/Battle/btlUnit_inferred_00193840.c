#include "byte_address_internal.h"
#include "member_access.h"
#include "h_cdvd_request_internal.h"
#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "rw_types_internal.h"
typedef RwV3d P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;
typedef struct DatUnit DatUnit;

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;
extern s64 btlGetUID(void);


extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern void memcpy(void *dst, void *src, s32 size);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern void func_00440b68(void *msg, const void *file, s32 line);
extern s32 H_Cdvd_AcquireDirectory(s32 path, s32 flags);
extern void H_Cdvd_ReadSync(s32 cdvd);
extern s32 H_Cdvd_IsFileLoaded(s32 cdvd);
extern void H_Cdvd_Destroy(s32 cdvd);
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);
extern void btlPacketInitNoop(void);
extern s32 btlUnitLoadStep(u8 *unusedTask);

extern s32 btlUnitLoadBlocksFromFile(u8 *loadTable, s32 synchronous);
extern void datBattleUnitLoadCompleteNoop(void);
extern void memset(void *, s32, s32);

/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */


extern u8 iGpffffa4d8;
extern void btlPacketStep(u8 *context);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern void btlPacketFlushAll(void);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlEffectLoadFilesSync(void);
extern void btlUiRegisterAvailability(void);
extern void btlSoundLoadBanks(void);
extern void btlPanelLoadSync(void);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Find a flagged packet with the supplied UID, ignoring its two high tag bits. */
static inline u8 *btlPacketFindFlaggedByUid(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (node != NULL) {
            if (uid == (((BtlPacket *)node)->uid & mask) && (((BtlPacket *)node)->flags & 0x20) != 0) {
                return node;
            }
            node = ((BtlPacket *)node)->previous;
        }
        i++;
    }
    return NULL;
}
/* Find a flagged packet whose action UID matches after removing high tag bits. */
static inline u8 *btlPacketFindFlaggedByActionUid(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (node != NULL) {
            if (uid == (((BtlPacket *)node)->actionUID & mask) && (((BtlPacket *)node)->flags & 0x20) != 0) {
                return node;
            }
            node = ((BtlPacket *)node)->previous;
        }
        i++;
    }
    return NULL;
}
/* This id search intentionally reads the low halfword of the 32-bit packet type. */
static inline u8 *btlPacketFindFlaggedByType(u16 key)
{
    u8 *node;
    u8 *btl;
    u32 i;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (node != NULL) {
            if ((u16)((BtlPacket *)node)->type == key && (((BtlPacket *)node)->flags & 0x20) != 0) {
                return node;
            }
            node = ((BtlPacket *)node)->previous;
        }
        i++;
    }
    return NULL;
}

typedef struct {
    u8 *head;
    u8 *tail;
} PacketList;
extern s32 btlPacketWaitConditionMet(u8 *context, s32 argument);
/* Eight-byte entries in a load descriptor; only the first leading word is
 * passed to the directory loader. Each destination slot receives one block. */
typedef struct BtlUnitLoadBlock {
    u32 unk00;
    u8 **destination;
} BtlUnitLoadBlock;

/* The save-table reset clears ten records of exactly 0x14 bytes. */
typedef struct BtlUnitSavedRecord {
    u16 unk00;
    u16 unk02;
    u8 pad04[0x10];
} BtlUnitSavedRecord;

/* Load packed blocks, align each source/destination span to sixteen bytes, and publish their
 * pointers. */
// FUN_00193840
s32 btlUnitLoadBlocksFromFile(u8 *loadTable, s32 synchronous)
{
    u8 *block;
    s32 blockIndex;
    u32 blockSize;
    u32 offset;
    u8 **destination;

    if (iGpffffb434 == 0) {
        func_00440b68(&iGpffffa0a0, D_005F6BE0, 0x4B1);
        iGpffffb434 = H_Cdvd_AcquireDirectory(*(s32 *)loadTable, 0);
    }
    if (synchronous != 0) {
        H_Cdvd_ReadSync(iGpffffb434);
        goto block_6;
    }
    if (H_Cdvd_IsFileLoaded(iGpffffb434) == 0) {
        return 0;
    }
block_6:
    block = (u8 *)((HCdvdRequest *)(u8 *)iGpffffb434)->data;
    blockIndex = 0;
    goto loop_8_check;
loop_8_body:
    blockSize = *(u32 *)block;
    offset = iGpffffb430;
    *destination = (u8 *)((s32)D_007F17B0 + offset);
    iGpffffb430 +=
        (((blockSize >> 4) + ((blockSize & 0xF) != 0)) * 0x10);
    memcpy(*destination, block + 4, blockSize);
    offset = blockSize + 4;
    block +=
        (((offset >> 4) + ((offset & 0xF) != 0)) * 0x10);
    blockIndex += 1;
loop_8_check:
    destination = ((BtlUnitLoadBlock *)loadTable)[blockIndex].destination;
    if (destination != NULL) {
        goto loop_8_body;
    }
    H_Cdvd_Destroy(iGpffffb434);
    iGpffffb434 = 0;
    return 1;
}

/* Synchronously load the effect, UI, sound, and panel assets used by battle units. */
// FUN_001939A0
void btlUnitLoadSyncedAssets(void) {
    btlEffectLoadFilesSync();
    btlUiRegisterAvailability();
    btlSoundLoadBanks();
    btlPanelLoadSync();
}

/* Poll the eight load descriptors in order and finish the load task after the final descriptor. */
// FUN_001939E0
s32 btlUnitLoadStep(u8 *unusedTask)
{
    s32 result;

    result = btlUnitLoadBlocksFromFile((u8 *)D_005F66C0 + iGpffffb438 * 0xA4, 0);
    if (result == 0) {
        goto clear;
    }
    iGpffffb438 = iGpffffb438 + 1;
    if (iGpffffb438 != 8) {
        goto clear;
    }
    result = 1;
    goto check;
clear:
    result = 0;
check:
    if (result == 0) {
        goto done;
    }
    datBattleUnitLoadCompleteNoop();
    result = -1;
    goto end;
done:
    result = 0;
end:
    return result;
}

/* Reset load cursors and create the child task that polls battle-unit assets; ctx is passed through
 * as the parent task. */
// FUN_00193A80
void btlUnitStartLoad(u8 *ctx) {
    iGpffffb430 = 0;
    iGpffffb434 = 0;
    iGpffffb438 = 0;
    (s32)kwlnTaskCreateChild((void *)(ctx), (const void *)(D_005F6BF0), 0x10, 0, 0, btlUnitLoadStep, 0, (u8 *)(NULL));
}

/* Resets the ten 20-byte unit-record slots of save chunk 40 (D_0079BE2C) and initializes their
 * leading halfwords; called from func_0010f4c0, which owns the chunk's save/load copy. */
// FUN_00193AD0
void btlUnitRecordResetSaveTable(u8 *context)
{
    s16 i;
    s64 index;
    s32 offset;
    u8 *entry;

    i = 0;
    while ((u32)i < 10U) {
        index = i;
        offset = (s32)index * 0x14;
        entry = context + offset;
        memset(entry, 0, 0x14);
        ((BtlUnitSavedRecord *)entry)->unk00 = 0;
        ((BtlUnitSavedRecord *)entry)->unk02 = 3;
        i++;
    }
}

/* Find a flagged packet by its masked packet UID across all four lists. The battle state goes
 * through a separate local alias because typing the list heads at each access changed the code. */
// FUN_00193B70
u8 *btlUnitRecordFindByUID(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (packet != NULL) {
            if (uid == (((BtlPacket *)packet)->uid & mask) &&
                (((BtlPacket *)packet)->flags & 0x20) != 0) {
                return packet;
            }
            packet = ((BtlPacket *)packet)->previous;
        }
        i++;
    }
    return NULL;
}

/* Find a flagged packet by its masked action UID across all four lists; same walk as
 * btlUnitRecordFindByUID but this packet stores the UID at a different offset. */
// FUN_00193BF0
u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (packet != NULL) {
            if (uid == (((BtlPacket *)packet)->actionUID & mask) &&
                (((BtlPacket *)packet)->flags & 0x20) != 0) {
                return packet;
            }
            packet = ((BtlPacket *)packet)->previous;
        }
        i++;
    }
    return NULL;
}

/* Count packets across the four battle lists. */
// FUN_00193C70
u32 btlCountUnitRecords(void)
{
    u32 total;
    u32 i;
    u8 *btl;
    u8 *packet;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    for (; i < 4; i++) {
        packet = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (packet != NULL) {
            total++;
            packet = ((BtlPacket *)packet)->previous;
        }
    }
    return total;
}

/* Count packets whose type matches the low halfword of the supplied id. */
// FUN_00193CD0
u32 btlCountUnitRecordsById(u32 id)
{
    u8 *packet;
    u8 *btl;
    u32 total;
    u32 i;

    total = 0;
    i = 0;
    btl = iGpffffb3ac;
    id = (u16)id;
    for (; i < 4; i++) {
        packet = ((BtlBattleState *)btl)->packetLists[i].tail;
        while (packet != NULL) {
            if (((BtlPacket *)packet)->type == id) {
                total++;
            }
            packet = ((BtlPacket *)packet)->previous;
        }
    }
    return total;
}

/* Unit-record flag bits; battle end promotes each pending record to committed (see
 * btlUnitRecordCommitPending). */
#define BTLUNIT_RECORD_FLAG_PENDING   0x01
#define BTLUNIT_RECORD_FLAG_COMMITTED 0x04

/* Promote pending unit-record flags to committed while walking the forward links. */
// FUN_00193D30
void btlUnitRecordCommitPending(void)
{
    BtlPacket *packetFields;
    u8 *packet;
    u32 i;
    u32 flags;

    i = 0;
    for (; i < 4; i++) {
        packet = ((BtlBattleState *)iGpffffb3ac)->packetLists[i].tail;
        packetFields = (BtlPacket *)packet;
        while (packet != NULL) {
            flags = ((BtlPacket *)packet)->flags;
            if ((flags & BTLUNIT_RECORD_FLAG_PENDING) != 0) {
                packetFields->flags = flags | BTLUNIT_RECORD_FLAG_COMMITTED;
            }
            packet = ((BtlPacket *)packet)->next;
            packetFields = (BtlPacket *)packet;
        }
    }
}

/* measured: retail hoists loop-invariant loads out of the dependency checks in this function. */
#pragma opt_loop_invariants on
/* Evaluate a packet dependency by elapsed frame, packet/action UID, id, or optional condition callback. */
// FUN_00193D90
s32 btlPacketWaitConditionMet(u8 *context, s32 argument)
{
    s32 result;
    u64 uid;
    u16 key;
    u8 *node;
    s32 (*cb)(u8 *);
    result = 0;
    switch (*(u8 *)context) {
    case 1:
        result = 1;
        break;
    case 2:
        if (((BtlPacketCondition *)context)->value.frame <= argument) {
            result = 1;
        }
        break;
    case 3:
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByUid(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 4:
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByUid(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 5:
        result = 1;
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByUid(uid);
        if (node != NULL && ((BtlPacket *)node)->phase != 2) {
            result = 0;
        }
        break;
    case 6:
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByActionUid(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 7:
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByActionUid(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 8:
        result = 1;
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByActionUid(uid);
        if (node != NULL && ((BtlPacket *)node)->phase != 2) {
            result = 0;
        }
        break;
    case 9:
        key = ((BtlPacketCondition *)context)->value.id;
        node = btlPacketFindFlaggedByType(key);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 10:
        key = ((BtlPacketCondition *)context)->value.id;
        node = btlPacketFindFlaggedByType(key);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 11:
        result = 1;
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByUid(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb((u8 *)((BtlPacket *)node)->workData);
            } else {
                result = 0;
            }
        }
        break;
    case 12:
        result = 1;
        uid = ((BtlPacketCondition *)context)->value.uid;
        node = btlPacketFindFlaggedByActionUid(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb((u8 *)((BtlPacket *)node)->workData);
            } else {
                result = 0;
            }
        }
        break;
    }
    return result;
}

/* measured: optimization_level 1 keeps the retail initialization order with the index and value
 * locals declared before the loop; -O2 reorders it. */
#pragma optimization_level 1
/* Allocate the packet header and inline work, then initialize its four dependency conditions, each
 * a discriminator byte in a 0x10-byte record. */
// FUN_00194470
u8 *btlPacketAlloc(s32 packetType, s32 workSize)
{
    s32 allocationSize;
    s32 startConditionIndex;
    s32 endConditionIndex;
    s32 value;
    u8 *packet;

    allocationSize = workSize + 0x90;
    chkmemAllocSiteTag(D_005F6C00, 0x51);
    packet = D_008873E8[0](allocationSize, 0x40000);
    memset(packet, 0, allocationSize);
    ((BtlPacket *)packet)->type = packetType;
    startConditionIndex = 0;
    value = 1;
    goto loop1_check;
loop1_body:
    ((BtlPacket *)packet)->conditions[(startConditionIndex & 0xFFFF)].kind = value;
    startConditionIndex = (startConditionIndex + 1) & 0xFFFF;
loop1_check:
    if ((startConditionIndex & 0xFFFF) < 2) {
        goto loop1_body;
    }
    endConditionIndex = 0;
    value = 1;
    goto loop2_check;
loop2_body:
    ((BtlPacket *)packet)->conditions[(endConditionIndex & 0xFFFF) + 2].kind = value;
    endConditionIndex = (endConditionIndex + 1) & 0xFFFF;
loop2_check:
    if ((endConditionIndex & 0xFFFF) < 2) {
        goto loop2_body;
    }
    if (workSize > 0) {
        ((BtlPacket *)packet)->workData = packet + 0x90;
    }
    ((BtlPacket *)packet)->flags =
        (u8)(((BtlPacket *)packet)->flags | 0x31);
    return packet;
}

/* measured: the enqueue and step functions need full level-2 scheduling to follow retail. */
#pragma optimization_level 2
/* Assign a UID, initialize packet counters, invoke init, and link into the selected list. */
// FUN_00194590
s64 btlPacketEnqueue(u8 *context, u32 value)
{
    BtlPacketList *selectedPacketList;
    BtlPacket *contextFields = (BtlPacket *)context;
    u32 index;
    u8 *next;
    void (*callback)(u8 *);

    ((BtlPacket *)context)->uid = btlGetUID();
    ((BtlPacket *)context)->elapsed = 0;
    ((BtlPacket *)context)->updateFrames = 0;
    ((BtlPacket *)context)->phase = 0;
    ((BtlPacket *)context)->listIndex = value;
    ((BtlPacket *)context)->flags |= 8;
    callback = (void (*)(u8 *))((BtlPacket *)context)->initFunc;
    if (callback != NULL) {
        callback((u8 *)((BtlPacket *)context)->workData);
    }
    ((BtlPacket *)context)->previous = 0;
    index = ((u8)value) * 8;
    selectedPacketList = (BtlPacketList *)((u8 *)((s32 *)((s32)((s32 *)iGpffffb3ac) + (0x198))) + index);
    next = selectedPacketList->head;
    if (next != NULL) {
        ((BtlPacket *)next)->previous = context;
        ((BtlPacket *)context)->next =
            ((BtlBattleState *)(u8 *)((index) + ((s32)iGpffffb3ac)))->packetLists[0].head;
    } else {
        ((BtlBattleState *)(u8 *)((index) + ((s32)iGpffffb3ac)))->packetLists[0].tail = context;
        ((BtlPacket *)context)->next = NULL;
    }
    ((BtlBattleState *)(u8 *)((index) + ((s32)iGpffffb3ac)))->packetLists[0].head = context;
    return (s64)contextFields->uid;
}

/* Empty packet initialization hook called during battle subsystem setup. */
// FUN_00194660
void btlPacketInitNoop(void)
{
}

/* Advances packet conditions, delays, update and teardown; states fall through only once their
 * conditions complete, and links are reloaded after callbacks. */
// FUN_00194670
void btlPacketStep(u8 *context)
{
    BtlPacket *contextFields = (BtlPacket *)context;
    u8 flags;
    u8 index;
    u8 *next;
    u8 *prev;
    void (*callback)(u8 *);
    s32 count;
    s32 ok;
    s32 i;

    if (((BtlPacket *)context)->paused != 0) {
        return;
    }
    flags = ((BtlPacket *)context)->flags;
    if ((flags & 8) == 0) {
        return;
    }
    if ((flags & 4) != 0) {
        callback = (void (*)(u8 *))((BtlPacket *)context)->destroyFunc;
        if (callback != NULL) {
            callback((u8 *)((BtlPacket *)context)->workData);
        }
        if ((contextFields->flags & 8) != 0) {
            index = ((BtlPacket *)context)->listIndex;
            next = ((BtlPacket *)context)->next;
            if (next != NULL) {
                ((BtlPacket *)next)->previous = ((BtlPacket *)context)->previous;
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = ((BtlPacket *)context)->previous;
            }
            prev = contextFields->previous;
            if (prev != NULL) {
                ((BtlPacket *)prev)->next = contextFields->next;
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = contextFields->next;
            }
        }
        jtbl_008873EC[0](context);
    } else {
        count = ((BtlPacket *)context)->elapsed;
        ((BtlPacket *)context)->elapsed = (s32)((u32)count + 1U);
        switch (((BtlPacket *)context)->phase) {
        case 0:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (btlPacketWaitConditionMet(context + (((u16)i) << 4), count) == 0) {
                    ok = 0;
                    goto state0_done;
                }
            }
            ok = 1;
        state0_done:
            if (ok == 0) {
                return;
            }
            contextFields->phase = 1;
        case 1:
            if ((s16)contextFields->delay <= 0) {
                contextFields->phase = 2;
            } else {
                ((BtlPacket *)context)->delay = (s16)((s16)((BtlPacket *)context)->delay - 1);
                return;
            }
        case 2:
            if ((((BtlPacket *)context)->updateFunc)(((BtlPacket *)context)->workData) != 0) {
                contextFields->phase = 3;
            } else {
                ((BtlPacket *)context)->updateFrames += 1U;
                return;
            }
        case 3:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (btlPacketWaitConditionMet((u8 *)((((u16)i) << 4) + (u32)context) + 0x20, count) == 0) {
                    ok = 0;
                    goto state3_done;
                }
            }
            ok = 1;
        state3_done:
            if (ok == 0) {
                return;
            }
            contextFields->phase = 4;
        case 4:
            if ((s16)contextFields->duration <= 0) {
                callback = (void (*)(u8 *))((BtlPacket *)context)->destroyFunc;
                if (callback != NULL) {
                    callback((u8 *)((BtlPacket *)context)->workData);
                }
                if ((contextFields->flags & 8) != 0) {
                    index = ((BtlPacket *)context)->listIndex;
                    next = ((BtlPacket *)context)->next;
                    if (next != NULL) {
                        ((BtlPacket *)next)->previous = ((BtlPacket *)context)->previous;
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = ((BtlPacket *)context)->previous;
                    }
                    prev = contextFields->previous;
                    if (prev != NULL) {
                        ((BtlPacket *)prev)->next = contextFields->next;
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = contextFields->next;
                    }
                }
                jtbl_008873EC[0](context);
            } else {
                ((BtlPacket *)context)->duration = (s16)((s16)((BtlPacket *)context)->duration - 1);
            }
            break;
        }
    }
}

/* measured: retail keeps values in separate temporaries instead of propagating copies in this list
 * step. */
#pragma opt_propagation off
/* Step one packet list, saving the preceding link before a callback can free the packet. */
// FUN_001949D0
void btlPacketStepSide(s32 side)
{
    u8 *btl;
    u8 *next;
    u8 *packet;

    btl = iGpffffb3ac;
    packet = ((BtlBattleState *)(u8 *)(u32)byteAddressAdd((side & 0xFF) * 8, (u8 *)((u32)btl)))->packetLists[0].tail;
    while (packet != NULL) {
        next = ((BtlPacket *)packet)->previous;
        btlPacketStep(packet);
        packet = next;
    }
}

/* Destroy and unlink every packet, invoking each destroy callback before releasing memory. */
// FUN_00194A30
void btlPacketFlushAll(void)
{
    u8 *entry;
    u8 *next;
    u8 *link;
    void (*callback)(u8 *);
    u8 index;
    u32 i;

    i = 0;
    goto outer_check;
outer:
    entry = ((BtlBattleState *)iGpffffb3ac)->packetLists[i].tail;
    goto inner_check;
inner:
    next = ((BtlPacket *)entry)->next;
    callback = (void (*)(u8 *))((BtlPacket *)entry)->destroyFunc;
    if (callback != NULL) {
        callback((u8 *)((BtlPacket *)entry)->workData);
    }
    if ((((BtlPacket *)entry)->flags & 8) != 0) {
        index = ((BtlPacket *)entry)->listIndex;
        link = MEMBER(u8 *, entry, BtlPacket, next);
        if (link != NULL) {
            ((BtlPacket *)link)->previous = ((BtlPacket *)entry)->previous;
        } else {
            ((BtlBattleState *)iGpffffb3ac)->packetLists[index & 0xFF].tail =
                ((BtlPacket *)entry)->previous;
        }
        link = MEMBER(u8 *, entry, BtlPacket, previous);
        if (link != NULL) {
            ((BtlPacket *)link)->next = MEMBER(u8 *, entry, BtlPacket, next);
        } else {
            ((BtlBattleState *)iGpffffb3ac)->packetLists[index & 0xFF].head =
                MEMBER(u8 *, entry, BtlPacket, next);
        }
    }
    jtbl_008873EC[0](entry);
    entry = next;
inner_check:
    if (entry != NULL) {
        goto inner;
    }
    i++;
outer_check:
    if (i < 4) {
        goto outer;
    }
}

// FUN_00194B50
s32 btlPacketConditionAlwaysMet(void)
{
    return 1;
}

/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma optimization_level 1
/* Create a header-only packet whose update callback completes immediately. */
/* Typed discriminator arrays retain the two-loop initialization; the named callback word retains its integer-address store contract. */
// FUN_00194B60
u8 *btlPacketCreateImmediate(void)
{
    u8 *packet;
    s32 j;
    s32 i;
    u8 *base;
    s32 value;

    chkmemAllocSiteTag(D_005F6C00, 0x51);
    packet = (u8 *)D_008873E8[0](0x90, 0x40000);
    memset(packet, 0, 0x90);
    ((BtlPacket *)packet)->type = 0xFF00;
    i = 0;
    value = 1;
    goto first_check;
first_body:
    ((BtlPacket *)packet)->conditions[(i & 0xFFFF)].kind = (u8)value;
    i = (i + 1) & 0xFFFF;
first_check:
    if ((i & 0xFFFF) < 2) {
        goto first_body;
    }
    base = packet + 0x20;
    j = 0;
    value = 1;
    goto second_check;
second_body:
    ((BtlPacketCondition *)base)[j & 0xFFFF].kind = (u8)value;
    j = (j + 1) & 0xFFFF;
second_check:
    if ((j & 0xFFFF) < 2) {
        goto second_body;
    }
    ((BtlPacket *)packet)->flags =
        (u8)(((BtlPacket *)packet)->flags | 0x31);
    *(s32 *)&((BtlPacket *)packet)->updateFunc = (s32)btlPacketConditionAlwaysMet;
    return packet;
}


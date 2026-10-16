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
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} P4_95730_Vec3;
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
extern s32 func_00454a60(s32 arg0, s32 arg1);
extern void H_Cdvd_ReadSync(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
typedef struct RwV3d RwV3d;
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
extern void func_00194660(void);
extern s32 btlUnitLoadStep(u8 *task);

extern s32 btlUnitLoadBlocksFromFile(u8 *arg0, s32 arg1);
extern void func_0010d480(void);
extern void memset(void *arg0, s32 arg1, s32 arg2);

/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    func_00198920(arg0, arg1, arg2, arg3, arg4);
}
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    func_0029db50(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern void btlPacketStep(u8 *arg0);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern s32 iGpffffb444;

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlPacketFlushAll(void);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
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

/* Source unit: src/promoted/code1_0019.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0019.c; members 00193840-00194b60 */

static inline u8 *search_58_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x58) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_60_10(u64 uid)
{
    u8 *node;
    u8 *btl;
    u32 i;
    u64 mask = (1ULL << 62) - 1;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (uid == (*(u64 *)(node + 0x60) & mask) && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u8 *search_40_10(u16 key)
{
    u8 *node;
    u8 *btl;
    u32 i;
    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        node = *(u8 **)(btl + i * 8 + 0x19C);
        while (node != NULL) {
            if (*(u16 *)(node + 0x40) == key && (*(u8 *)(node + 0x47) & 0x20) != 0) {
                return node;
            }
            node = *(u8 **)(node + 0x7C);
        }
        i++;
    }
    return NULL;
}
static inline u32 packetListOffset(u32 offset, u32 base)
{
    return offset + base;
}
typedef struct {
    u8 *head;
    u8 *tail;
} PacketList;
extern s32 btlPacketWaitConditionMet(u8 *arg0, s32 arg1);
// FUN_00193840
s32 btlUnitLoadBlocksFromFile(u8 *arg0, s32 arg1)
{
    u8 *var_18;
    s32 var_17;
    u32 temp_16;
    u32 temp_4;
    u8 **temp_2;

    if (iGpffffb434 == 0) {
        func_00440b68(&iGpffffa0a0, D_005F6BE0, 0x4B1);
        iGpffffb434 = func_00454a60(*(s32 *)arg0, 0);
    }
    if (arg1 != 0) {
        H_Cdvd_ReadSync(iGpffffb434);
        goto block_6;
    }
    if (H_Cdvd_IsFileLoaded(iGpffffb434) == 0) {
        return 0;
    }
block_6:
    var_18 = *(u8 **)((u8 *)iGpffffb434 + 0x110);
    var_17 = 0;
    goto loop_8_check;
loop_8_body:
    temp_16 = *(u32 *)var_18;
    temp_4 = iGpffffb430;
    *temp_2 = (u8 *)((s32)D_007F17B0 + temp_4);
    iGpffffb430 +=
        (((temp_16 >> 4) + ((temp_16 & 0xF) != 0)) * 0x10);
    memcpy(*temp_2, var_18 + 4, temp_16);
    temp_4 = temp_16 + 4;
    var_18 +=
        (((temp_4 >> 4) + ((temp_4 & 0xF) != 0)) * 0x10);
    var_17 += 1;
loop_8_check:
    temp_2 = *(u8 ***)((u8 *)arg0 + (var_17 * 8) + 4);
    if (temp_2 != NULL) {
        goto loop_8_body;
    }
    H_Cdvd_Destroy(iGpffffb434);
    iGpffffb434 = 0;
    return 1;
}

// FUN_001939A0
void btlUnitLoadSyncedAssets(void) {
    btlEffectLoadFilesSync();
    btlUiRegisterAvailability();
    btlSoundLoadBanks();
    btlPanelLoadSync();
}

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
    func_0010d480();
    result = -1;
    goto end;
done:
    result = 0;
end:
    return result;
}

/* 80/80 bytes; eight resolved relocations. Retail forwards the incoming
 * a0 to the task constructor as the parent; it is not an uninitialized
 * local left in an incidental register. */
// FUN_00193A80
void btlUnitStartLoad(u8 *ctx) {
    iGpffffb430 = 0;
    iGpffffb434 = 0;
    iGpffffb438 = 0;
    (s32)kwlnTaskCreateChild((void *)(ctx), (const void *)(D_005F6BF0), 0x10, 0, 0, btlUnitLoadStep, 0, (u8 *)(NULL));
}

// FUN_00193AD0
void func_00193ad0(u8 *arg0)
{
    s16 i;
    s64 index;
    s32 offset;
    u8 *entry;

    i = 0;
    while ((u32)i < 10U) {
        index = i;
        offset = (s32)index * 0x14;
        entry = arg0 + offset;
        memset(entry, 0, 0x14);
        *(u16 *)(entry + 0x0) = 0;
        *(u16 *)(entry + 0x2) = 3;
        i++;
    }
}

// FUN_00193B70
u8 *btlUnitRecordFindByUID(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x58) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

// FUN_00193BF0
/* Same packet-list walk as btlUnitRecordFindByUID; this P4 packet stores the
 * UID at offset 0x60 instead of 0x58. */
u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask)
{
    u8 *packet;
    u8 *btl;
    u32 i;

    i = 0;
    btl = iGpffffb3ac;
    while (i < 4) {
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (uid == (*(u64 *)(packet + 0x60) & mask) &&
                (*(u8 *)(packet + 0x47) & 0x20) != 0) {
                return packet;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
        i++;
    }
    return NULL;
}

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
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            total++;
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}

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
        packet = *(u8 **)(btl + i * 8 + 0x19C);
        while (packet != NULL) {
            if (*(u32 *)(packet + 0x40) == id) {
                total++;
            }
            packet = *(u8 **)(packet + 0x7C);
        }
    }
    return total;
}

// FUN_00193D30
void func_00193d30(void)
{
    u8 *packet;
    u32 i;
    u32 flags;

    i = 0;
    for (; i < 4; i++) {
        packet = *(u8 **)(iGpffffb3ac + i * 8 + 0x19C);
        while (packet != NULL) {
            flags = *(u8 *)(packet + 0x47);
            if ((flags & 1) != 0) {
                *(u8 *)(packet + 0x47) = flags | 4;
            }
            packet = *(u8 **)(packet + 0x80);
        }
    }
}

/* measured: func_00193d90 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_00193D90
s32 btlPacketWaitConditionMet(u8 *arg0, s32 arg1)
{
    s32 result;
    u64 uid;
    u16 key;
    u8 *node;
    s32 (*cb)(u8 *);
    result = 0;
    switch (*(u8 *)arg0) {
    case 1:
        result = 1;
        break;
    case 2:
        if (*(s32 *)(arg0 + 8) <= arg1) {
            result = 1;
        }
        break;
    case 3:
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 4:
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 5:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL && *(u8 *)(node + 0x45) != 2) {
            result = 0;
        }
        break;
    case 6:
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 7:
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 8:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL && *(u8 *)(node + 0x45) != 2) {
            result = 0;
        }
        break;
    case 9:
        key = *(u16 *)(arg0 + 8);
        node = search_40_10(key);
        if (node != NULL) {
            result = 1;
        }
        break;
    case 10:
        key = *(u16 *)(arg0 + 8);
        node = search_40_10(key);
        if (node == NULL) {
            result = 1;
        }
        break;
    case 11:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_58_10(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb(*(u8 **)(node + 0x78));
            } else {
                result = 0;
            }
        }
        break;
    case 12:
        result = 1;
        uid = *(u64 *)(arg0 + 8);
        node = search_60_10(uid);
        if (node != NULL) {
            cb = *(s32 (**)(u8 *))(node + 0x74);
            if (cb != NULL) {
                result = cb(*(u8 **)(node + 0x78));
            } else {
                result = 0;
            }
        }
        break;
    }
    return result;
}

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: func_00194470 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_00194470
u8 *btlPacketAlloc(s32 arg0, s32 arg1)
{
    s32 temp_18;
    s32 var_4;
    s32 var_4_2;
    s32 value;
    u8 *temp_2;

    temp_18 = arg1 + 0x90;
    chkmemAllocSiteTag(D_005F6C00, 0x51);
    temp_2 = D_008873E8[0](temp_18, 0x40000);
    memset(temp_2, 0, temp_18);
    *(s32 *)(temp_2 + 0x40) = arg0;
    var_4 = 0;
    value = 1;
    goto loop1_check;
loop1_body:
    *(u8 *)(temp_2 + ((var_4 & 0xFFFF) << 4)) = value;
    var_4 = (var_4 + 1) & 0xFFFF;
loop1_check:
    if ((var_4 & 0xFFFF) < 2) {
        goto loop1_body;
    }
    var_4_2 = 0;
    value = 1;
    goto loop2_check;
loop2_body:
    *(u8 *)(temp_2 + ((var_4_2 & 0xFFFF) << 4) + 0x20) = value;
    var_4_2 = (var_4_2 + 1) & 0xFFFF;
loop2_check:
    if ((var_4_2 & 0xFFFF) < 2) {
        goto loop2_body;
    }
    if (arg1 > 0) {
        *(u8 **)(temp_2 + 0x78) = temp_2 + 0x90;
    }
    *(u8 *)(temp_2 + 0x47) =
        (u8)(*(u8 *)(temp_2 + 0x47) | 0x31);
    return temp_2;
}

/* measured: func_00194590, func_00194670 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_00194590
/* measured: opt_propagation off is scoped to func_00194590. */
s64 btlPacketEnqueue(u8 *arg0, u32 arg1)
{
    u32 index;
    u8 *next;
    void (*callback)(u8 *);

    *(s64 *)(arg0 + 0x58) = btlGetUID();
    *(s32 *)(arg0 + 0x4C) = 0;
    *(s32 *)(arg0 + 0x50) = 0;
    *(u8 *)(arg0 + 0x45) = 0;
    *(u8 *)(arg0 + 0x44) = arg1;
    *(u8 *)(arg0 + 0x47) |= 8;
    callback = *(void (**)(u8 *))(arg0 + 0x68);
    if (callback != NULL) {
        callback(*(u8 **)(arg0 + 0x78));
    }
    *(s32 *)(arg0 + 0x7C) = 0;
    index = ((u8)arg1) * 8;
    next = *(u8 **)((u8 *)p4_entries_001900a0(0x198, (s32 *)iGpffffb3ac) + index);
    if (next != NULL) {
        *(u8 **)(next + 0x7C) = arg0;
        *(u8 **)(arg0 + 0x80) =
            *(u8 **)((u8 *)p4_base_add_00194590(index,
                                                 (s32)iGpffffb3ac) + 0x198);
    } else {
        *(u8 **)((u8 *)p4_base_add_00194590(index,
                                             (s32)iGpffffb3ac) + 0x19C) = arg0;
        *(u8 **)(arg0 + 0x80) = NULL;
    }
    *(u8 **)((u8 *)p4_base_add_00194590(index,
                                         (s32)iGpffffb3ac) + 0x198) = arg0;
    return *(s64 *)(arg0 + 0x58);
}

/* measured: closes opt_propagation around func_00194590. */
// FUN_00194660
void func_00194660(void)
{
}

/* 852/864 bytes; ten resolved relocations; twelve zero alignment bytes.
 * States fall through only after their conditions complete. Destruction
 * reloads the list flag and links after the callback; counters wrap as u32. */
// FUN_00194670
void btlPacketStep(u8 *arg0)
{
    u8 flags;
    u8 index;
    u8 *next;
    u8 *prev;
    void (*callback)(u8 *);
    s32 count;
    s32 ok;
    s32 i;

    if (*(u8 *)(arg0 + 0x46) != 0) {
        return;
    }
    flags = *(u8 *)(arg0 + 0x47);
    if ((flags & 8) == 0) {
        return;
    }
    if ((flags & 4) != 0) {
        callback = *(void (**)(u8 *))(arg0 + 0x70);
        if (callback != NULL) {
            callback(*(u8 **)(arg0 + 0x78));
        }
        if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
            index = *(u8 *)(arg0 + 0x44);
            next = *(u8 **)(arg0 + 0x80);
            if (next != NULL) {
                *(u8 **)(next + 0x7C) = *(u8 **)(arg0 + 0x7C);
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = *(u8 **)(arg0 + 0x7C);
            }
            prev = *(u8 **)(arg0 + 0x7C);
            if (prev != NULL) {
                *(u8 **)(prev + 0x80) = *(u8 **)(arg0 + 0x80);
            } else {
                ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = *(u8 **)(arg0 + 0x80);
            }
        }
        jtbl_008873EC[0](arg0);
    } else {
        count = *(s32 *)(arg0 + 0x4C);
        *(s32 *)(arg0 + 0x4C) = (s32)((u32)count + 1U);
        switch (*(u8 *)(arg0 + 0x45)) {
        case 0:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (btlPacketWaitConditionMet(arg0 + (((u16)i) << 4), count) == 0) {
                    ok = 0;
                    goto state0_done;
                }
            }
            ok = 1;
        state0_done:
            if (ok == 0) {
                return;
            }
            *(u8 *)(arg0 + 0x45) = 1;
        case 1:
            if (*(s16 *)(arg0 + 0x48) <= 0) {
                *(u8 *)(arg0 + 0x45) = 2;
            } else {
                *(s16 *)(arg0 + 0x48) = (s16)(*(s16 *)(arg0 + 0x48) - 1);
                return;
            }
        case 2:
            if ((*(u32 (**)(void *))(arg0 + 0x6C))(*(void **)(arg0 + 0x78)) != 0) {
                *(u8 *)(arg0 + 0x45) = 3;
            } else {
                *(u32 *)(arg0 + 0x50) += 1U;
                return;
            }
        case 3:
            for (i = 0; (i & 0xFFFF) < 2; i = (i + 1) & 0xFFFF) {
                if (btlPacketWaitConditionMet((u8 *)((((u16)i) << 4) + (u32)arg0) + 0x20, count) == 0) {
                    ok = 0;
                    goto state3_done;
                }
            }
            ok = 1;
        state3_done:
            if (ok == 0) {
                return;
            }
            *(u8 *)(arg0 + 0x45) = 4;
        case 4:
            if (*(s16 *)(arg0 + 0x4A) <= 0) {
                callback = *(void (**)(u8 *))(arg0 + 0x70);
                if (callback != NULL) {
                    callback(*(u8 **)(arg0 + 0x78));
                }
                if ((*(u8 *)(arg0 + 0x47) & 8) != 0) {
                    index = *(u8 *)(arg0 + 0x44);
                    next = *(u8 **)(arg0 + 0x80);
                    if (next != NULL) {
                        *(u8 **)(next + 0x7C) = *(u8 **)(arg0 + 0x7C);
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].tail = *(u8 **)(arg0 + 0x7C);
                    }
                    prev = *(u8 **)(arg0 + 0x7C);
                    if (prev != NULL) {
                        *(u8 **)(prev + 0x80) = *(u8 **)(arg0 + 0x80);
                    } else {
                        ((PacketList *)(iGpffffb3ac + 0x198))[index & 0xFF].head = *(u8 **)(arg0 + 0x80);
                    }
                }
                jtbl_008873EC[0](arg0);
            } else {
                *(s16 *)(arg0 + 0x4A) = (s16)(*(s16 *)(arg0 + 0x4A) - 1);
            }
            break;
        }
    }
}

/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: func_001949d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001949D0
void btlPacketStepSide(s32 arg0)
{
    u8 *btl;
    u8 *temp_16;
    u8 *var_4;

    btl = iGpffffb3ac;
    var_4 = *(u8 **)((u8 *)packetListOffset((arg0 & 0xFF) * 8, (u32)btl) + 0x19C);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x7C);
        btlPacketStep(var_4);
        var_4 = temp_16;
    }
}

/* measured: closes opt_propagation for func_001949d0. */
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
    entry = *(u8 **)(iGpffffb3ac + i * 8 + 0x19C);
    goto inner_check;
inner:
    next = *(u8 **)(entry + 0x80);
    callback = *(void (**)(u8 *))(entry + 0x70);
    if (callback != NULL) {
        callback(*(u8 **)(entry + 0x78));
    }
    if ((*(u8 *)(entry + 0x47) & 8) != 0) {
        index = *(u8 *)(entry + 0x44);
        link = *(u8 **)(entry + 0x80);
        if (link != NULL) {
            *(u8 **)(link + 0x7C) = *(u8 **)(entry + 0x7C);
        } else {
            *(u8 **)(iGpffffb3ac + ((index & 0xFF) * 8) + 0x19C) =
                *(u8 **)(entry + 0x7C);
        }
        link = *(u8 **)(entry + 0x7C);
        if (link != NULL) {
            *(u8 **)(link + 0x80) = *(u8 **)(entry + 0x80);
        } else {
            *(u8 **)(iGpffffb3ac + ((index & 0xFF) * 8) + 0x198) =
                *(u8 **)(entry + 0x80);
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
/* measured: func_00194b60 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_00194B60
u8 *btlPacketCreateImmediate(void)
{
    u8 *temp_16;
    s32 j;
    s32 i;
    u8 *base;
    s32 value;

    chkmemAllocSiteTag(D_005F6C00, 0x51);
    temp_16 = (u8 *)D_008873E8[0](0x90, 0x40000);
    memset(temp_16, 0, 0x90);
    *(s32 *)(temp_16 + 0x40) = 0xFF00;
    i = 0;
    value = 1;
    goto first_check;
first_body:
    *(u8 *)(temp_16 + ((i & 0xFFFF) << 4)) = (u8)value;
    i = (i + 1) & 0xFFFF;
first_check:
    if ((i & 0xFFFF) < 2) {
        goto first_body;
    }
    base = temp_16 + 0x20;
    j = 0;
    value = 1;
    goto second_check;
second_body:
    *(u8 *)(base + ((j & 0xFFFF) << 4)) = (u8)value;
    j = (j + 1) & 0xFFFF;
second_check:
    if ((j & 0xFFFF) < 2) {
        goto second_body;
    }
    *(u8 *)(temp_16 + 0x47) =
        (u8)(*(u8 *)(temp_16 + 0x47) | 0x31);
    *(s32 *)(temp_16 + 0x6C) = (s32)btlPacketConditionAlwaysMet;
    return temp_16;
}



/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_loop_invariants off

#include "field_transition_internal.h"
#include "member_access.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
#include "scene_resource_internal.h"
/* Tail table populated by evtLoadEventTables: count then an array of owned blocks. */
typedef struct EvtHandleTable {
    s32 count;
    union { s32 address; s32 *words; u8 **blocks; u8 *bytes; } entries;
} EvtHandleTable;
typedef struct EvtResourceKey { s16 packed; u8 pad02[3]; s8 kind; } EvtResourceKey;

extern u32 kwlnTaskGetWork(void *task);
extern void MT_Scene_SetExclusiveRes(s32 );
extern s32 evtEnsureEventTask(void); /* lint: allow H011 -- caller stores the returned value; the definition is void */
extern s32 evtGetEventTaskWork(u8 *);
extern void evtLoadEventTables(u8 *);
typedef signed __int128 s128;

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *MT_Scene_GetResListHead(s32 );
extern void evtMemAccount(s32 , s32 );
// Returns nonzero when the current event's noiseTask handle is set.
// FUN_0028B650
s32 evtHasTaskHandle(void) {
    s32 h = evtEnsureEventTask();

    if (h == 0) {
        return 0;
    }
    return (s32)((EvtEventWork *)evtGetEventTaskWork((u8 *)kwlnTaskGetWork((void *)h)))->noiseTask != 0;
}

// Frees every handle in the event's handle table and clears it.
// FUN_0028B6B0
/* measured: the table local read at the loop-body head gives retail's body instruction order. */
void evtClearHandles(u8 *work)
{
    /* measured: table fields are accessed through byte offsets so loads keep retail's reload order. */
    s32 count;
    s32 i;
    s32 *table;
    s32 tail;

    if (((EvtHandleTable *)(work + 0x7A0))->entries.address == 0) {
        ((EvtHandleTable *)(work + 0x7A0))->count = 0;
        return;
    }
    count = ((EvtHandleTable *)(work + 0x7A0))->count;
    i = 0;
    while (i < count) {
        table = ((EvtEventWork *)(work))->handles.words;
        if (table[i] != 0) {
            if (table[i] != 0) {
                jtbl_008873EC[0]((void *)table[i]);
                evtMemAccount(0xC, 0);
                ((s32 *)MEMBER(s32, work, EvtEventWork, handles.address))[i] = 0;
            }
        }
        i++;
    }
    tail = ((EvtHandleTable *)(work + 0x7A0))->count * 4;
    jtbl_008873EC[0]((void *)((EvtEventWork *)(work))->handles.address);
    evtMemAccount(0xC, -tail);
    MEMBER(s32, work, EvtEventWork, handles.address) = 0;
    ((EvtHandleTable *)(work + 0x7A0))->count = 0;
}

// Loads the event's tables: allocates the working area, copies the table entries and records their
// memory.
// FUN_0028B7B0
void evtLoadEventTables(u8 *work) {
    /* measured: table fields are accessed through byte offsets so loads keep retail's reload order. */
    u8 *count_node;
    u8 *copy;
    u8 *array;
    u32 allocator;
    s128 *src128;
    s128 *dst128;
    s32 *src32;
    s32 *dst32;
    s128 *src128_one;
    s128 *dst128_one;
    s128 q_one;
    s32 n_one;
    s32 n32;
    s32 n;
    s128 q0;
    s128 q1;
    s32 word0;
    s32 word1;
    s32 count;
    s32 index;
    s32 i;
    s32 type;
    s32 valid;
    s32 size;

    count = 0;
    index = 0;
    evtClearHandles(work);
    for (i = 1; i < 0x16; i++) {
        count_node = MT_Scene_GetResListHead(i);
        if (count_node != NULL) {
            type = (*(u16 *)count_node & 0xFFC00) >> 10;
            if (type == 12) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 7) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 6) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 5) {
                goto func_0028b7b0_count_valid;
            }
            if (type == 3) {
                goto func_0028b7b0_count_valid;
            }
            switch (type) {
            case 1:
                goto func_0028b7b0_count_valid;
            default:
                goto func_0028b7b0_count_invalid;
            }
func_0028b7b0_count_valid:
            valid = 1;
            goto func_0028b7b0_count_valid_done;
func_0028b7b0_count_invalid:
            valid = 0;
func_0028b7b0_count_valid_done:
            if (valid != 0) {
                while (count_node != NULL) {
                    count++;
                    count_node = (u8 *)((ResrcHeader *)count_node)->next;
                }
            }
        }
    }
    if (count != 0) {
        ((EvtHandleTable *)(work + 0x7A0))->count = count;
        chkmemAllocSiteTag(D_00748340, 0x52);
        size = count * 4;
        allocator = (u32)D_008873F4;
        array = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, size, 0x40000);
        evtMemAccount(12, size);
        ((EvtHandleTable *)(work + 0x7A0))->entries.bytes = array;
        for (i = 1; i < 0x16; i++) {
            array = MT_Scene_GetResListHead(i);
            if (array != NULL) {
                type = (*(u16 *)array & 0xFFC00) >> 10;
                if (type == 12) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 7) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 6) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 5) {
                    goto func_0028b7b0_copy_valid;
                }
                if (type == 3) {
                    goto func_0028b7b0_copy_valid;
                }
                switch (type) {
                case 1:
                    goto func_0028b7b0_copy_valid;
                default:
                    goto func_0028b7b0_copy_invalid;
                }
func_0028b7b0_copy_valid:
                valid = 1;
                goto func_0028b7b0_copy_valid_done;
func_0028b7b0_copy_invalid:
                valid = 0;
func_0028b7b0_copy_valid_done:
                if (valid != 0) {
                    while (array != NULL) {
                        copy = NULL;
                        type = (*(u16 *)array & 0xFFC00) >> 10;
                        switch (type) {
                        case 1:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x230, 0x40000);
                            evtMemAccount(12, 0x230);
                            n_one = 0x23;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        case 3:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x370, 0x40000);
                            evtMemAccount(12, 0x370);
                            n_one = 0x37;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        case 5:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x200, 0x40000);
                            evtMemAccount(12, 0x200);
                            n = 0x10;
                            src128 = (s128 *)array;
                            dst128 = (s128 *)copy;
                            do {
                                q0 = src128[0];
                                q1 = src128[1];
                                src128 += 2;
                                n--;
                                dst128[0] = q0;
                                dst128[1] = q1;
                                dst128 += 2;
                            } while (n > 0);
                            break;
                        case 6:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x148, 0x40000);
                            evtMemAccount(12, 0x148);
                            n32 = 0x29;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 7:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x150, 0x40000);
                            evtMemAccount(12, 0x150);
                            n32 = 0x2A;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 8:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x140, 0x40000);
                            evtMemAccount(12, 0x140);
                            n32 = 0x28;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 9:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x148, 0x40000);
                            evtMemAccount(12, 0x148);
                            n32 = 0x29;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 10:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x170, 0x40000);
                            evtMemAccount(12, 0x170);
                            n32 = 0x2E;
                            src32 = (s32 *)array;
                            dst32 = (s32 *)copy;
                            do {
                                word0 = src32[0];
                                word1 = src32[1];
                                src32 += 2;
                                n32--;
                                dst32[0] = word0;
                                dst32[1] = word1;
                                dst32 += 2;
                            } while (n32 > 0);
                            break;
                        case 12:
                            chkmemAllocSiteTag(D_00748340, 0x52);
                            copy = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, 0x1B0, 0x40000);
                            evtMemAccount(12, 0x1B0);
                            n_one = 0x1B;
                            src128_one = (s128 *)array;
                            dst128_one = (s128 *)copy;
                            do {
                                q_one = *src128_one;
                                src128_one++;
                                n_one--;
                                *dst128_one = q_one;
                                dst128_one++;
                            } while (n_one > 0);
                            break;
                        }
                        ((EvtEventWork *)work)->handles.blocks[index] = copy;
                        array = (u8 *)((ResrcHeader *)array)->next;
                        index++;
                    }
                }
            }
        }
    }
}

// Sets the exclusive scene resource for kind 0 or 1, then stores the kind in the event work.
// FUN_0028BE70
void evtSetKindExclusiveRes(u8 *work, s32 kind)
{
    if (kind < 2) {
        switch (kind) {
        case 0:
            MT_Scene_SetExclusiveRes(0x1E58);
            break;
        case 1:
            MT_Scene_SetExclusiveRes(0x1E59);
            break;
        default:
            break;
        }
        ((EvtEventWork *)(work))->exclusiveKind = kind;
    }
}

// Decodes a node key: low 12 bits become resourceId, bits 12-15 become variant, and the table entry
// for the node kind is returned.
// FUN_0028BEF0
s32 evtDecodeNodeKey(s32 workAddress, u8 *key, s32 *resourceId, s32 *variant) {
    /* measured: key fields are accessed through byte offsets so loads keep retail's reload order. */
    s32 baseKey;
    s8 kind;

    *resourceId = (s32)((s16)((EvtResourceKey *)(key + 0x10))->packed & 0xFFF);
    *variant = (((s16)((EvtResourceKey *)(key + 0x10))->packed >> 0xC) & 0xF);
    kind = ((EvtResourceKey *)(key + 0x10))->kind;
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        baseKey = MEMBER(s32, (u8 *)(kind * 4) + workAddress, EvtEventWork, messageControl.unk694);
        if (baseKey == -1) {
            return 0;
        }
        *resourceId += baseKey;
        goto block_6;
    case 6:
        return 0;
    default:
block_6:
        return 1;
    }
}

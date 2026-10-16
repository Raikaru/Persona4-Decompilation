/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0028b650-0028bef0 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
extern u32 kwlnTaskGetWork(void *task);
extern void MT_Scene_SetExclusiveRes(s32 arg0);
extern s32 evtEnsureEventTask(void); /* lint: allow H011 -- caller stores the returned value; the definition is void */
extern s32 evtGetEventTaskWork(u8 *arg0);
extern void evtLoadEventTables(u8 *arg0);
typedef signed __int128 s128;

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void evtMemAccount(s32 arg0, s32 arg1);
#pragma push
#pragma opt_loop_invariants off
// Event task-handle check: nonzero when the current event's +0x768 task handle is set.
// FUN_0028B650
s32 evtHasTaskHandle(void) {
    s32 h = evtEnsureEventTask();

    if (h == 0) {
        return 0;
    }
    return *(s32 *)((u8 *)evtGetEventTaskWork((u8 *)kwlnTaskGetWork((void *)h)) + 0x768) != 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event handle table: frees every handle in the table at +0x7A4 and clears it.
// FUN_0028B6B0
/* measured: the table local at the loop-body head reproduces retail's
   sll-before-lw body order; nd 0, object 244B / window 256B. */
void evtClearHandles(u8 *arg0)
{
    s32 count;
    s32 i;
    s32 *table;
    s32 tail;

    if (*(s32 *)(arg0 + 0x7A4) == 0) {
        *(s32 *)(arg0 + 0x7A0) = 0;
        return;
    }
    count = *(s32 *)(arg0 + 0x7A0);
    i = 0;
    while (i < count) {
        table = *(s32 **)(arg0 + 0x7A4);
        if (table[i] != 0) {
            if (table[i] != 0) {
                jtbl_008873EC[0]((void *)table[i]);
                evtMemAccount(0xC, 0);
                *(s32 *)(*(s32 *)(arg0 + 0x7A4) + i * 4) = 0;
            }
        }
        i++;
    }
    tail = *(s32 *)(arg0 + 0x7A0) * 4;
    jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0x7A4));
    evtMemAccount(0xC, -tail);
    *(s32 *)(arg0 + 0x7A4) = 0;
    *(s32 *)(arg0 + 0x7A0) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Loads the event's tables: allocates the working area, copies the table entries and records their memory [inferred].
// FUN_0028B7B0
void evtLoadEventTables(u8 *arg0) {
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
    evtClearHandles(arg0);
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
                    count_node = *(u8 **)(count_node + 0x138);
                }
            }
        }
    }
    if (count != 0) {
        *(s32 *)(arg0 + 0x7A0) = count;
        chkmemAllocSiteTag(D_00748340, 0x52);
        size = count * 4;
        allocator = (u32)D_008873F4;
        array = ((u8 *(*)(s32, s32, s32))*(u32 *)allocator)(1, size, 0x40000);
        evtMemAccount(12, size);
        *(u8 **)(arg0 + 0x7A4) = array;
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
                        *(u8 **)(*(u8 **)(arg0 + 0x7A4) + index * 4) = copy;
                        array = *(u8 **)(array + 0x138);
                        index++;
                    }
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Sets the exclusive resource for kind 0 or 1 and stores the kind on the event [inferred].
// FUN_0028BE70
void evtSetKindExclusiveRes(u8 *arg0, s32 arg1)
{
    if (arg1 < 2) {
        switch (arg1) {
        case 0:
            MT_Scene_SetExclusiveRes(0x1E58);
            break;
        case 1:
            MT_Scene_SetExclusiveRes(0x1E59);
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0x524) = arg1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Decodes a node's key: low 12 bits of the node word become arg2, bits 12 to 15 become arg3, and the table entry for the node type is returned [inferred].
// FUN_0028BEF0
s32 evtDecodeNodeKey(s32 arg0, u8 *arg1, s32 *arg2, s32 *arg3) {
    s32 temp_3_2;
    s8 temp_3;

    *arg2 = (s32)((s16)*(s16 *)(arg1 + 0x10) & 0xFFF);
    *arg3 = (((s16)*(s16 *)(arg1 + 0x10) >> 0xC) & 0xF);
    temp_3 = *(s8 *)(arg1 + 0x15);
    switch (temp_3) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        temp_3_2 = *(s32 *)((u8 *)(temp_3 * 4) + arg0 + 0x694);
        if (temp_3_2 == -1) {
            return 0;
        }
        *arg2 += temp_3_2;
        goto block_6;
    case 6:
        return 0;
    default:
block_6:
        return 1;
    }
}
#pragma pop

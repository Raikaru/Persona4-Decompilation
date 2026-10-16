/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00331980-00331f90 */

#include "fcl_object_internal.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 arg0);
extern void datSetFlag(s32 arg0, s32 arg1);
extern u8 *kwlnTaskGetTaskByName(s8 *arg0);
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 func_002be100(u8 arg0);
extern u16 cmmCommunityRecordValue(s32 arg0);
extern s8 nmMesWindowAcquire(void *arg0);
extern s32 nmMesWindowShowSlotRecord(s8 arg0, s32 arg1);
extern s32 datItemCount(s16 arg0);
extern s32 nmMesWindowSlotStatus(s8 arg0);
extern void nmMesWindowStepSlotRelease(s32 arg0);
extern void nmMesWindowDestroySlot(s8 arg0);
extern void wshopMaterialTalkCreate(u8 *arg0);
extern u8 D_00644ED0[];
extern u8 D_00645090[];
extern u8 D_00645240[];
extern u8 D_0064A000[];
// FUN_00331980
s32 fclScriptFlagIsSet(void)
{
    return datGetFlag(scrGetParamInt(0)) != 0;
}

// FUN_003319C0
s32 fclScriptSetFlagOnButton(void) {
    s32 r;

    if ((D_008C024E[0] & 0x800) != 0) {
        datSetFlag(scrGetParamInt(0), 1);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00331A20
s32 weaponShopTalkUpdate(u8 *arg0)
{
    s8 *work;
    s8 i;
    s8 j;
    s16 level_value;
    s16 min;
    s16 max;
    u8 *entry;
    u8 *e;

    work = *(s8 **)(arg0 + 0x38);
    level_value = (s16)(100 * (func_002be100(fclCalendarMonth()) & 0xFF) + (fclCalendarDay() & 0xFF));
    switch (*work) {
    case 0:
        if (datGetFlag(0x1C0) == 0) {
            work[1] = nmMesWindowAcquire(D_00645240);
            nmMesWindowShowSlotRecord(work[1], 0);
            (*work)++;
            datSetFlag(0x1C0, 1);
            return 0;
        }
        if ((cmmCommunityRecordValue(0x13) & 0xFFFF) == 6 || (cmmCommunityRecordValue(0x13) & 0xFFFF) == 7) {
            e = D_00645090 + ((cmmCommunityRecordValue(0x13) & 0xFFFF) - 6) * 0x10;
            if (datGetFlag(*(s32 *)(e + 12)) != 0 || *(s32 *)(e + 12) == 0) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)e);
                datItemSetCount(*(s16 *)(e + 2), ((datItemCount(*(s16 *)(e + 2)) & 0xFF) + 1) & 0xFF);
                datSetFlag(*(s32 *)(e + 4), 1);
                datSetFlag(*(s32 *)(e + 8), 0);
                (*work)++;
                return 0;
            }
        }
        i = 0;
        do {
            entry = D_00644ED0 + (i * 0x10);
            min = (s16)(entry[9] + 100 * (func_002be100(entry[8]) & 0xFF));
            max = (s16)(entry[11] + 100 * (func_002be100(entry[10]) & 0xFF));
            if (*(s16 *)entry != -1 && datGetFlag(*(s32 *)(entry + 12)) == 0 &&
                (datGetFlag(*(s32 *)(entry + 4)) != 0 || *(s32 *)(entry + 4) == 0) && !(min > level_value) &&
                !(max < level_value)) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                datSetFlag(*(s32 *)(entry + 12), 1);
                (*work)++;
                return 0;
            }
            i++;
        } while (*(s16 *)entry != -1);
        if (datGetFlag(0x1324) != 0) {
            *work = 2;
            wshopMaterialTalkCreate(arg0);
            return 0;
        }
        j = 0;
        do {
            entry = D_00644ED0 + (j * 0x10);
            min = (s16)(entry[9] + 100 * (func_002be100(entry[8]) & 0xFF));
            max = (s16)(entry[11] + 100 * (func_002be100(entry[10]) & 0xFF));
            if (*(s16 *)entry != -1 && (datGetFlag(*(s32 *)(entry + 4)) != 0 || *(s32 *)(entry + 4) == 0) &&
                !(min > level_value) && !(max < level_value)) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                (*work)++;
                return 0;
            }
            j++;
        } while (*(s16 *)entry != -1);
        return -1;
    case 1:
        if (nmMesWindowSlotStatus(work[1]) != 0) {
            nmMesWindowStepSlotRelease(work[1]);
            break;
        }
        nmMesWindowDestroySlot(work[1]);
        return -1;
    case 2:
        if (kwlnTaskGetTaskByName((s8 *)D_0064A000) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}
#pragma pop

// FUN_00331F90
void weaponShopTalkDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

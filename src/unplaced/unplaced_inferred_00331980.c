/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00331980-00331f90 */

#include "fcl_object_internal.h"
#include "member_access.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
typedef struct WeaponShopTalkWork { s8 state, slot; } WeaponShopTalkWork;
typedef struct WeaponShopGift {
    s16 message, item;
    s32 setFlag, clearFlag, requiredFlag;
} WeaponShopGift;
typedef struct WeaponShopTalk {
    s16 message;
    u8 pad02[2];
    s32 requiredFlag;
    u8 startMonth, startDay, endMonth, endDay;
    s32 seenFlag;
} WeaponShopTalk;

extern void (*jtbl_008873EC[])(void *);
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 );
extern void datSetFlag(s32 , s32 );
extern u8 *kwlnTaskGetTaskByName(s8 *);
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 fclCalendarMonthOrder(u8 );
extern u16 cmmCommunityRecordValue(s32 );
extern s8 nmMesWindowAcquire(void *);
extern s32 nmMesWindowShowSlotRecord(s8 , s32 );
extern s32 datItemCount(s16 );
extern s32 nmMesWindowSlotStatus(s8 );
extern void nmMesWindowStepSlotRelease(s32 );
extern void nmMesWindowDestroySlot(s8 );
extern void wshopMaterialTalkCreate(u8 *);
extern u8 D_00644ED0[];
extern u8 D_00645090[];
extern u8 D_00645240[];
extern u8 D_0064A000[];
// FUN_00331980
s32 fclScriptFlagIsSet(void)
{
    return datGetFlag(scrGetParamInt(0)) != 0;
}

/* Set the script-selected flag only while the confirmation button bit is set. */
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

/* Choose shop dialogue from first-visit, community-gift and date-gated records, then wait for the message or material-talk task. */
#pragma push
#pragma opt_loop_invariants on
/* measured: cached table base and pointer-first scans do not match; baseline retains 133 differing words. */
// FUN_00331A20
s32 weaponShopTalkUpdate(u8 *task)
{
    /* measured: remaining talk/task fields preserve b210 reload and state-update ordering; individual typed substitutions lose MATCH. */
    s8 *work;
    s8 i;
    s8 j;
    s16 dateCode;
    s16 startDate;
    s16 endDate;
    u8 *entry;
    u8 *gift;

    work = (s8 *)((struct KwlnTask *)task)->work;
    dateCode = (s16)(100 * (fclCalendarMonthOrder(fclCalendarMonth()) & 0xFF) + (fclCalendarDay() & 0xFF));
    switch (((WeaponShopTalkWork *)work)->state) {
    case 0:
        if (datGetFlag(0x1C0) == 0) {
            ((WeaponShopTalkWork *)work)->slot = nmMesWindowAcquire(D_00645240);
            nmMesWindowShowSlotRecord(work[1], 0);
            (((WeaponShopTalkWork *)work)->state)++;
            datSetFlag(0x1C0, 1);
            return 0;
        }
        if ((cmmCommunityRecordValue(0x13) & 0xFFFF) == 6 || (cmmCommunityRecordValue(0x13) & 0xFFFF) == 7) {
            gift = D_00645090 + ((cmmCommunityRecordValue(0x13) & 0xFFFF) - 6) * 0x10;
            if (datGetFlag(((WeaponShopGift *)(gift))->requiredFlag) != 0 || MEMBER(s32, gift, WeaponShopGift, requiredFlag) == 0) {
                ((WeaponShopTalkWork *)work)->slot = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)gift);
                datItemSetCount(((WeaponShopGift *)(gift))->item, ((datItemCount(MEMBER(s16, gift, WeaponShopGift, item)) & 0xFF) + 1) & 0xFF);
                datSetFlag(((WeaponShopGift *)gift)->setFlag, 1);
                datSetFlag(((WeaponShopGift *)gift)->clearFlag, 0);
                (((WeaponShopTalkWork *)work)->state)++;
                return 0;
            }
        }
        i = 0;
        do {
            entry = D_00644ED0 + (i * 0x10);
            startDate = (s16)(((WeaponShopTalk *)entry)->startDay + 100 * (fclCalendarMonthOrder(((WeaponShopTalk *)entry)->startMonth) & 0xFF));
            endDate = (s16)(((WeaponShopTalk *)entry)->endDay + 100 * (fclCalendarMonthOrder(((WeaponShopTalk *)entry)->endMonth) & 0xFF));
            if (*(s16 *)entry != -1 && datGetFlag(MEMBER(s32, entry, WeaponShopTalk, seenFlag)) == 0 &&
                (datGetFlag(((WeaponShopTalk *)(entry))->requiredFlag) != 0 || MEMBER(s32, entry, WeaponShopTalk, requiredFlag) == 0) && !(startDate > dateCode) &&
                !(endDate < dateCode)) {
                ((WeaponShopTalkWork *)work)->slot = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                datSetFlag(((WeaponShopTalk *)entry)->seenFlag, 1);
                (((WeaponShopTalkWork *)work)->state)++;
                return 0;
            }
            i++;
        } while (*(s16 *)entry != -1);
        if (datGetFlag(0x1324) != 0) {
            ((WeaponShopTalkWork *)work)->state = 2;
            wshopMaterialTalkCreate(task);
            return 0;
        }
        j = 0;
        do {
            entry = D_00644ED0 + (j * 0x10);
            startDate = (s16)(((WeaponShopTalk *)entry)->startDay + 100 * (fclCalendarMonthOrder(((WeaponShopTalk *)entry)->startMonth) & 0xFF));
            endDate = (s16)(((WeaponShopTalk *)entry)->endDay + 100 * (fclCalendarMonthOrder(((WeaponShopTalk *)entry)->endMonth) & 0xFF));
            if (*(s16 *)entry != -1 && (datGetFlag(((WeaponShopTalk *)(entry))->requiredFlag) != 0 || MEMBER(s32, entry, WeaponShopTalk, requiredFlag) == 0) &&
                !(startDate > dateCode) && !(endDate < dateCode)) {
                ((WeaponShopTalkWork *)work)->slot = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                (((WeaponShopTalkWork *)work)->state)++;
                return 0;
            }
            j++;
        } while (*(s16 *)entry != -1);
        return -1;
    case 1:
        if (nmMesWindowSlotStatus(((WeaponShopTalkWork *)work)->slot) != 0) {
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
void weaponShopTalkDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}

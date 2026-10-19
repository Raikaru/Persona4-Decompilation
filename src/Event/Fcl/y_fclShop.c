/* Whole-file translation unit: src/Event/Fcl/y_fclShop.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "list_item_internal.h"
#include "type.h"
#include "sdk_task_registration.h"

/* Constructor stores prove this prefix of the 0x1840-byte shop work block.
   Unknown interpolation words retain their integer representation here. */
typedef struct FclShopWork {
    u8 state;
    u8 mode;
    u8 pad02[2];
    s32 drawTask;
    u8 pad08[8];
    s32 unk10;
    s32 unk14;
    s16 unk18;
    u8 pad1A[2];
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    u8 pad28[2];
    s16 unk2A;
    u8 pad2C[0x1814];
} FclShopWork;

extern char D_0063F3C8[];
extern char D_0063F3E0[];
extern char D_0063F550[];
extern s32 D_0063F520[];
extern char iGpffffa870;
extern void *(*D_008873F4[])(size_t, size_t, u32);

s32 fclShopDrawCreate(s32);
s32 fclCalendarMonthOrder(s32);
s32 datItemMoonGateFirst(s16);
s32 datItemMoonGateSecond(s16);

void chkmemAllocSiteTag(const void *, u32);
void sdkSndFadeOutChannelFrames(s16, s32, s32);
void func_00440b68();
s32 H_Cdvd_AcquireDirectory();
void H_Cdvd_ReadSync();
s32 H_Cdvd_LookupRequest();
void nmMesWindowInstallHandle();
void datLoadEntryTable();
s32 fclShopMainUpdate(u8 *task);
void fclShopMainDestroy(u8 *);

/* Create the shop controller and mark items available from their gate/date data.
   The initial 0x19 state store and repeated field resets are retained from retail. */
// FUN_002BDB50
s32 fclShopCreate(s32 parentTask, s8 mode)
{
    FclShopWork *work;
    s32 taskHandle;
    s16 itemId;

    chkmemAllocSiteTag(D_0063F3C8, 0xB0);
    work = D_008873F4[0](1, 0x1840, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063F3E0), 0xF, 0, 0, fclShopMainUpdate, fclShopMainDestroy, (u8 *)(work));
    work->state = 1;
    work->mode = 0;
    if (mode == 1) {
        work->state = 0x19;
        work->state = 3;
        work->mode = 1;
    }
    work->drawTask = fclShopDrawCreate(parentTask);
    work->unk18 = 0;
    work->unk24 = 0;
    work->unk26 = 0;
    work->unk2A = 0;
    work->unk10 = 0x41000000;
    work->unk14 = 0x41200000;
    work->unk18 = 0;
    work->unk1C = 0x41000000;
    work->unk20 = 0x41200000;
    work->unk24 = 0;
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);
    for (itemId = 0; itemId < 0x2FF; itemId++) {
        if (((datItemMoonGateFirst(itemId) & 0xFFF00) >> 8) == 0 &&
            ((datItemMoonGateSecond(itemId) & 0xFFF00) >> 8) == 0) {
            datSetStateTableEntry(itemId, clndGetMoonPhase(itemId) | 4);
        } else if (!(datItemMoonGateFirst(itemId) & 0xFF) && !(datItemMoonGateSecond(itemId) & 0xFF)) {
            datSetStateTableEntry(itemId, clndGetMoonPhase(itemId) | 4);
        }
    }
    for (itemId = 0x300; itemId < 0x3FF; itemId++) {
        if ((fclCalendarMonthOrder((u8)datItemAvailableMonth(itemId)) & 0xFF) <
            (fclCalendarMonthOrder(4) & 0xFF)) {
            datSetStateTableEntry(itemId, clndGetMoonPhase(itemId) | 4);
        } else if ((fclCalendarMonthOrder((u8)datItemAvailableMonth(itemId)) & 0xFF) ==
                   (fclCalendarMonthOrder(4) & 0xFF) && (s8)datItemAvailableDay(itemId) < 2) {
            datSetStateTableEntry(itemId, clndGetMoonPhase(itemId) | 4);
        }
    }
    return taskHandle;
}

/* Entries carrying bit 1 are reset to the availability bit (bit 2). */
// FUN_002BDEA0
void fclClearMoonFlagEntries(void)
{
    s32 itemId;

    for (itemId = 0; itemId < 0x3FF; itemId++) {
        u8 flags;

        flags = clndGetMoonPhase(itemId);
        if (flags & 2) {
            datSetStateTableEntry(itemId, 0);
            datSetStateTableEntry(itemId, 4);
        }
    }
}

/* Load the shop's nine message resources, then load the item entry table. */
// FUN_002BDF20
void fclShopLoadMessageResources(void)
{
    s32 resourceIds[9];
    s32 requestSize;
    s32 *source;
    s32 *destination;
    s32 count;
    s32 slot;
    s32 resourceId;

    source = D_0063F520;
    destination = resourceIds;
    count = 9;
    do {
        resourceId = *source;
        source++;
        count--;
        *destination = resourceId;
        destination++;
    } while (count > 0);
    func_00440b68(&iGpffffa870, D_0063F3C8, 0x179);
    H_Cdvd_ReadSync(H_Cdvd_AcquireDirectory(D_0063F550, 1));
    for (slot = 0; slot < 9; slot++) {
        nmMesWindowInstallHandle(slot, H_Cdvd_LookupRequest(resourceIds[slot], &requestSize));
    }
    datLoadEntryTable();
}

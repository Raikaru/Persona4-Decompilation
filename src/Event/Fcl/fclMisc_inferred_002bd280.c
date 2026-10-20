#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fcl_assist_internal.h"
#include "message_handle.h"
#include "shd_misc_internal.h"


extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void kAssertFail(const void *file, s32 line);
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern u8 *nmListAppendNode(u8 *manager, s32 owner, s32 payloadSize);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];


extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];


/* Retail digit RGBA occupies the four unaligned bytes at draw+0x75; these packed views keep the
 * FclDrawColor call interface. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif


extern void fclFadeRectSetRenderStates(s32 unusedQueue, u8 *work);
/* measured: retail hoists the D_00887300 address once, which needs a typed vtable base local with
 * propagation disabled. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Append a 0x30-byte message entry using the manager's current source. */
// FUN_002BD280
s32 fclMiscAddRecord(s32 slotIndex, s32 record, s32 value, s16 entryFlags)
{
    s32 source;
    FclAssistManager *manager;
    FclAssistNode *node;
    FclAssistEntry *entry;
    FclAssistList *list;

    manager = (FclAssistManager *)iGpffffb57c;
    if (manager->source == 0) {
        kAssertFail(&D_0063F2A0, 0x668);
    }
    source = manager->source;
    list = manager->entries;
    node = (FclAssistNode *)nmListAppendNode((u8 *)list, list->count + 1, 0x30);
    entry = (FclAssistEntry *)node->data;
    entry->node = node;
    entry->slotIndex = slotIndex;
    entry->record = record;
    entry->unk24 = value;
    entry->source = source;
    entry->unk0e = entryFlags;
    return 0;
}


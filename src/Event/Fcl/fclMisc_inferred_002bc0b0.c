#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "fcl_assist_internal.h"
#include "message_handle.h"
#include "shd_misc_internal.h"



extern s32 fclMesWindowDrawItemEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32, s32, s32, s32, s32, s32);
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
extern void itfMesWindowDrawEntry(s32, s32, s32, s32, s32, s32);
extern s32 itfMesWindowQueueEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex, u8 *queue);
extern u32 datEntryGetFlags(s16 itemId);
extern u8 *nmListAppendNode(u8 *manager, s32 owner, s32 payloadSize);
extern void sprintf();
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s16 day);
extern s32 sdkSpriteRequestLoad(void *name);
extern s32 hMaestroDecodeIsReady(s32 state);
extern void sdkSpriteRelease(void *node);
extern void comuDataRemoveAndReleaseNode(void *owner, void *source, void *nodeStorage);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];



extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bc0b0-002bcbc0 */

extern void fclFadeRectSetRenderStates(s32 unusedQueue, u8 *work);
/* measured: opt_rebuildconditionals off probe for min/max */
/* measured: close opt_rebuildconditionals after min/max */
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: close opt_loop_invariants after 3170. */
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
/* measured: closes the loop-invariant bracket; the unit default is off. */
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
/* Row and value are signed halfwords; retail discards incoming row high bits.
   Rewritten on the matched nmMesWindowSetNumber pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in nmMesWindowSetNumber:
   retail copies $f12 before $t3 in the prologue, and both callers still
   match. opt_dead_assignments off reproduces retail's late argument loads. */
#pragma push
#pragma pop
/* Keep the two positions, colors, and character-representation bounds
   snapshots separate across writes to the draw slots. The depth precedes
   the layer in the recovered signature. See the worker3 digit-pair archive. */
#pragma push
#pragma pop
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
/* Draw an item with the standard single-entry flag. */
// FUN_002BC0B0
void fclMesWindowDrawItem(f32 x, f32 y, f32 depth, u32 color, u32 font, u32 mode,
                   s32 table, s32 item)
{
    fclMesWindowDrawItemEntry(x, y, depth, color, font, mode, 1, table, item);
}

/* Select item message tables and draw one entry or an item/count pair after bounds checks. */
// FUN_002BC0E0
 s32 fclMesWindowDrawItemEntry(f32 x, f32 y, f32 depth, s32 color, s32 font, s32 mode, s32 flags, s32 kind, s32 item)
{
    extern s32 datItemCount(s16 itemId);
    extern u32 datEntryGetFlags(s16 itemId);
    extern s32 itfMesWindowRecordCount(s32 handle);
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex);
    extern s32 itfMesWindowDrawPair(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex, s32 secondHandle, s32 secondRecordIndex);
    extern s32 D_0063F2F0[];
    extern s32 D_0063F310[];
    extern s32 D_0063F2C0[];
    s32 itemTables[6];
    s32 entryTables[9];
    s32 *src;
    s32 *dst;
    u32 recordCount;
    s32 *src2;
    s32 *dst2;
    s32 loop;
    s32 loop2;
    s32 firstWord;
    s32 secondWord;
    s32 category;
    s32 tableIndex;
    s32 messageTable;
    s32 itemLevel;
    u32 itemId;
    s32 entryIndex;

    src = D_0063F2F0;
    dst = itemTables;
    loop = 3;
    do {
        firstWord = src[0];
        secondWord = src[1];
        src += 2;
        loop -= 1;
        dst[0] = firstWord;
        dst[1] = secondWord;
        dst += 2;
    } while (loop > 0);
    src2 = D_0063F310;
    dst2 = entryTables;
    loop2 = 9;
    do {
        firstWord = *src2;
        src2 += 1;
        loop2 -= 1;
        *dst2 = firstWord;
        dst2 += 1;
    } while (loop2 > 0);
    switch (kind) {
    case 0:
        if (item >= 0x400) {
            category = 5;
        } else {
            category = (s32)datEntryGetFlags((s16)item);
        }
        tableIndex = itemTables[category];
        item = (s16)datItemBankOffset((s16)item);
        goto block_23;
    case 1:
        itemId = item & 0xFFFF;
        tableIndex = itemTables[datEntryGetFlags((s16)itemId)];
        messageTable = D_0063F2B0[tableIndex];
        entryIndex = (s16)datItemBankOffset((s16)itemId);
        if ((u32)itfMesWindowRecordCount(messageTable) < (u32)entryIndex) {
            return 0;
        }
        itemLevel = item >> 16;
        if ((u32)itfMesWindowRecordCount(D_0063F2C0[0]) < (u32)itemLevel) {
            return 0;
        }
        itfMesWindowDrawPair(x, y, depth,
                      color, font, mode, 1, messageTable, entryIndex,
                      D_0063F2C0[0], itemLevel);
        return 0;
    case 2:
        itemId = datItemCount((s16)item) & 0xFF;
        tableIndex = itemTables[datEntryGetFlags((s16)itemId)];
        messageTable = D_0063F2B0[tableIndex];
        entryIndex = (s16)datItemBankOffset((s16)itemId);
        if ((u32)itfMesWindowRecordCount(messageTable) < (u32)entryIndex) {
            return 0;
        }
        recordCount = itfMesWindowRecordCount(D_0063F2C0[0]);
        if (recordCount < (u32)(datItemCount((s16)item) & 0xFF)) {
            return 0;
        }
        itfMesWindowDrawPair(x, y, depth,
                      color, font, mode, 1, messageTable, entryIndex,
                      D_0063F2C0[0], datItemCount((s16)item) & 0xFF);
        return 0;
    default:
        tableIndex = entryTables[kind];
        goto block_23;
    }
block_23:
    messageTable = D_0063F2B0[tableIndex];
    if ((u32)itfMesWindowRecordCount(messageTable) < (u32)item) {
        return 0;
    }
    itfMesWindowDrawEntry(x, y, depth,
                  color, font, mode, flags, messageTable, item);
    return 0;
}

/* Both metadata queries share the signed halfword item ID. Capture the
 * remaining inputs before those calls; scoped propagation preserves their
 * retail entry order, all 740 code bytes, and the six-way table. */
#pragma push
/* measured: func_002bc4b0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Draw the message entry selected by the item category. */
// FUN_002BC4B0
void fclMesWindowDrawItemCategory(f32 inputDepth, s16 item, s32 x, s32 y,
                    s32 inputColor, s32 inputFont, s32 inputMode)
{
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex);
    u32 category;
    f32 depth;
    s32 color;
    s32 font;
    s32 mode;

    depth = inputDepth;
    color = inputColor;
    font = inputFont;
    mode = inputMode;
    category = datEntryGetKind(item);
    switch (category) {
    case 0:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[0],
                      (s16)datItemBankOffset(item));
        return;
    case 1:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[1],
                      (s16)datItemBankOffset(item));
        return;
    case 2:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[2],
                      (s16)datItemBankOffset(item));
        return;
    case 3:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[4],
                      (s16)datItemBankOffset(item));
        return;
    case 4:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[5],
                      (s16)datItemBankOffset(item));
        return;
    case 5:
        itfMesWindowDrawEntry((f32)x, (f32)y, depth,
                      color, font, mode, 1, D_0063F2B0[7],
                      (s16)datItemBankOffset(item));
    default:
        return;
    }
}

#pragma pop
/* Draw an item using the signed-byte table selector and standard entry flag. */
// FUN_002BC7A0
void fclMesWindowDrawTableItem(s32 item, f32 x, f32 y, f32 depth,
                    s32 color, s32 font, s32 mode, s32 table)
{
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex,
                            s32 effect, s32 flags, s32 handle, s32 recordIndex);
    itfMesWindowDrawEntry(x, y, depth, color, font, mode, 1, D_0063F2B0[(s8)table], item);
}

/* Queue an entry on the selected 0x30-byte primitive list. */
// FUN_002BC7F0
void fclMesWindowDraw(s32 item, s32 color, s32 font, s32 mode, s32 table, s32 listIndex, f32 x, f32 y, f32 depth) {
    itfMesWindowQueueEntry(x, y, depth, color, font, mode, 1, D_0063F2B0[(s8)table], item, &D_00793E80[listIndex * 0x30]);
}

// Intent: Draw a message-window entry at the given position using the default table entry and mode 1 [inferred]
// FUN_002BC860
void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                    s32 color, s32 font, s32 mode, s32 item)
{
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex,
                            s32 effect, s32 flags, s32 handle, s32 recordIndex);
    itfMesWindowDrawEntry(x, y, depth, color, font, mode, 1, D_0063F2C8[0], item);
}

/* Queue an unloaded slot unless it already has a pending request; cancel a pending release. */
/* Typed slot/list rewrite changed code generation (attach: nd143; update: nd317).
 * Retain byte accesses: slots are 0x0C bytes at manager+0x1C, links +0x10, payload +0x14. */
// FUN_002BC890
s32 fclMiscAttachSlot(u8 *manager, s32 slotIndex)
{
    FclAssistManager *managerFields = (FclAssistManager *)manager;
    s32 flags;
    u8 *slot;
    u8 *indexedSlot;
    u8 *newNode;
    u8 *list;
    u8 *owner;
    u8 *node;
    u8 *entry;

    if (manager == NULL) kAssertFail(&D_0063F2A0, 0x541);
    if (slotIndex < 0) goto invalid_arg;
    if (slotIndex > 0xB) goto invalid_arg;
    goto valid_arg;
invalid_arg:
    kAssertFail(&D_0063F2A0, 0x542);
valid_arg:
    indexedSlot = manager + (slotIndex * 0xC);
    slot = indexedSlot + 0x1C;
    flags = ((FclAssistSlot *)slot)->flags;
    if (!(flags & 2)) {
        node = (u8 *)((FclAssistManager *)manager)->pending->head;
        goto loop_test;
loop_body:
        entry = ((FclAssistNode *)node)->data;
        if (((FclAssistSlot *)entry)->index == slotIndex) {
            owner = entry;
        } else {
            node = (u8 *)((FclAssistNode *)node)->next;
loop_test:
            if (node != NULL) {
                goto loop_body;
            }
            owner = NULL;
        }
        goto loop_done;
loop_done:
        if (owner == NULL) {
            ((FclAssistSlot *)slot)->index = slotIndex;
            list = (u8 *)managerFields->pending;
            newNode = nmListAppendNode(list, ((FclAssistList *)list)->count + 1, 0);
            if (newNode == NULL) kAssertFail(&D_007488E8, 0x52);
            ((FclAssistNode *)newNode)->data = slot;
            return 1;
        }
    }
    if (flags & 4) ((FclAssistSlot *)slot)->flags = flags & ~4;
    return 0;
}

/* Load the head sprite request, publish readiness, and release slots marked with flag 4. */
/* Typed slot/list rewrite changed code generation (attach: nd143; update: nd317).
 * Retain byte accesses: slots are 0x0C bytes at manager+0x1C, links +0x10, payload +0x14. */
// FUN_002BC9E0
s32 fclMiscUpdateSlots(u8 *manager)
{
    FclAssistManager *managerFields = (FclAssistManager *)manager;
    FclAssistSlot *pendingSlotFields;
    u8 path[0x20];
    s32 flags;
    s32 retiringFlags;
    s32 emptyFlags;
    s32 sprite;
    s32 loadedSprite;
    s32 slotIndex;
    u8 *pendingSlot;
    u8 *pendingNode;
    u8 *list;
    u8 *slot;

    if (manager == NULL) {
        kAssertFail(&D_0063F2A0, 0x558);
    }
    pendingNode = (u8 *)((FclAssistManager *)manager)->pending->head;
    if (pendingNode != NULL) {
        pendingSlot = ((FclAssistNode *)pendingNode)->data;
    pendingSlotFields = (FclAssistSlot *)pendingSlot;
        sprite = ((FclAssistSlot *)pendingSlot)->sprite;
        if (sprite == 0) {
            if (((FclAssistSlot *)pendingSlot)->index == 0) {
                sprintf(path, &D_0063F340);
            } else if ((calGetDayWindowFlags((s16)datGetDateIndex()) & 1) != 0) {
                sprintf(path, &D_0063F360, pendingSlotFields->index);
            } else {
                sprintf(path, &D_0063F380, MEMBER(s32, pendingSlot, FclAssistSlot, index));
            }
            MEMBER(s32, pendingSlot, FclAssistSlot, sprite) = sdkSpriteRequestLoad(path);
        } else if (hMaestroDecodeIsReady(sprite) != 0) {
            ((FclAssistSlot *)pendingSlot)->flags = ((FclAssistSlot *)pendingSlot)->flags | 2;
            list = (u8 *)managerFields->pending;
            comuDataRemoveAndReleaseNode(list, list + 4, pendingNode);
        }
    }
    slot = manager + 0x1C;
    slotIndex = 0;
    goto loop_19;
loop_20:
    flags = ((FclAssistSlot *)slot)->flags;
    if (flags & 4) {
        loadedSprite = ((FclAssistSlot *)slot)->sprite;
        if (loadedSprite != 0) {
            if (hMaestroDecodeIsReady(loadedSprite) != 0) {
                retiringFlags = ((FclAssistSlot *)slot)->flags & ~4;
                ((FclAssistSlot *)slot)->flags = retiringFlags;
                ((FclAssistSlot *)slot)->flags = retiringFlags & ~2;
                sdkSpriteRelease(MEMBER(void *, slot, FclAssistSlot, sprite));
                MEMBER(s32, slot, FclAssistSlot, sprite) = 0;
            }
        } else {
            emptyFlags = flags & ~4;
            ((FclAssistSlot *)slot)->flags = emptyFlags;
            ((FclAssistSlot *)slot)->flags = emptyFlags & ~2;
        }
    }
    slot += 0xC;
    slotIndex += 1;
loop_19:
    if (slotIndex < 0xB) {
        goto loop_20;
    }
    return 0;
}

/* Mark a slot for deferred sprite release (flag 4). */
// FUN_002BCBC0
s32 fclMiscRequestSlotRelease(u8 *manager, s32 slotIndex)
{
    FclAssistSlot *slot;

    if (manager == 0) {
        kAssertFail(D_0063F2A0, 0x58F);
    }
    if (slotIndex < 0) {
        goto error;
    }
    if (slotIndex <= 0xB) {
        goto done;
    }
error:
    kAssertFail(D_0063F2A0, 0x590);
done:
    slot = &((FclAssistManager *)manager)->slots[slotIndex];
    slot->flags |= 4;
    return 0;
}


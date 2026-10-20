#include "nm_message_record.h"
#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
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
extern s8 nmMesWindowFindFreeSlot(void);
extern s32 iGpffffb57c;
extern s32 *nmMesWindowCurrent();
extern s32 nmMesWindowCurrentAnim(void);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bab80-002bafc0 */

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
/* Allocate a free slot record and install its message; return the slot or -1 when full. */
// FUN_002BAB80
s64 nmMesWindowAcquire(void *message)
{
    s32 **recordSlot;
    s32 *recordWords;
    s64 freeSlot;
    s32 index;
    s64 result;
    extern s32 itfMesWindowInstall(s32 record);
    extern s32 nmMesWindowApplyStyle(s32 *record, s32 style);
    extern void chkmemAllocSiteTag(const void *file, s32 line);

    freeSlot = nmMesWindowFindFreeSlot();
    if (freeSlot == -1) {
        return -1;
    }
    chkmemAllocSiteTag(&D_0063F2A0, 0x90);
    recordWords = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
    {
        s32 **newSlot;

        newSlot = (s32 **)&D_00882F40[(s8)freeSlot];
        *newSlot = recordWords;
        if (recordWords != NULL) {
            ((NmMesWindowRecord *)recordWords)->handle = -1;
            ((NmMesWindowRecord *)recordWords)->state = 0;
            ((NmMesWindowRecord *)recordWords)->paused = 0;
            ((NmMesWindowRecord *)recordWords)->pendingRecord = -1;
            ((NmMesWindowRecord *)recordWords)->cursor = 1;
            ((NmMesWindowRecord *)recordWords)->result = 1;
        }
        index = (s32)freeSlot;
        (&D_00764670)[(s8)index] = -1;
        result = -1;
        if (**newSlot < 0) {
            recordSlot = (s32 **)&D_00882F40[(s8)index];
            **recordSlot = itfMesWindowInstall((s32)message);
            nmMesWindowApplyStyle(*recordSlot, 0);
            result = freeSlot;
        }
    }
    return result;
}

/* Find the first unallocated entry of the five-slot command table. */
// FUN_002BACB0
s8 nmMesWindowFindFreeSlot(void) {
    s32 slotIndex = 0;
    u8 **slots = D_00882F40;

    while (slotIndex < 5) {
        if (slots[slotIndex] == NULL) {
            return (s8)slotIndex;
        }
        slotIndex++;
    }
    return -1;
}

/* Bind a record to the current window and enter the opening state. */
// FUN_002BAD10
s32 nmMesWindowShowCurrentRecord(s32 recordIndex)
{
    s32 *recordWords;
    s32 handle;

    recordWords = nmMesWindowCurrent();
    if (recordWords == NULL) {
        return 0;
    }
    handle = ((NmMesWindowRecord *)recordWords)->handle;
    if (handle < 0) {
        return 0;
    }
    itfMesWindowSetStyle(handle, 0);
    itfMesWindowSetFlagBits(((NmMesWindowRecord *)recordWords)->handle, 0x200000);
    itfMesWindowBindRecord(((NmMesWindowRecord *)recordWords)->handle, recordIndex, 0);
    itfMesWindowSetAnim(((NmMesWindowRecord *)recordWords)->handle, -1);
    ((NmMesWindowRecord *)recordWords)->state = 1;
    return 1;
}

/* Bind a record to a slot window using the default style. */
// FUN_002BADC0
s32 nmMesWindowShowSlotRecord(s8 slotIndex, s32 recordIndex)
{
    s32 handle;
    u8 **slot;

    slot = &D_00882F40[(s8)slotIndex];
    handle = *(s32 *)*slot;
    if (handle < 0) {
        return 0;
    }
    itfMesWindowSetStyle(handle, 0);
    itfMesWindowSetFlagBits(*(s32 *)*slot, 0x200000);
    itfMesWindowBindRecord(*(s32 *)*slot, recordIndex, 0);
    itfMesWindowSetAnim(*(s32 *)*slot, -1);
    ((NmMesWindowRecord *)*slot)->state = 1;
    return 1;
}

/* Bind a record to a slot window using style 1. */
// FUN_002BAE80
s32 nmMesWindowShowSlotRecordStyle1(s64 slotIndex, s32 recordIndex)
{
    s32 handle;
    u8 **slot;

    slot = &D_00882F40[(s8)slotIndex];
    handle = *(s32 *)*slot;
    if (handle < 0) {
        return 0;
    }
    itfMesWindowSetStyle(handle, 1);
    itfMesWindowSetFlagBits(*(s32 *)*slot, 0x200000);
    itfMesWindowBindRecord(*(s32 *)*slot, recordIndex, 0);
    itfMesWindowSetAnim(*(s32 *)*slot, -1);
    ((NmMesWindowRecord *)*slot)->state = 1;
    return 1;
}

/* Queue a record change and snapshot the current animation result. */
// FUN_002BAF40
s32 nmMesWindowSetCurrentParam(s32 recordIndex) {
    s32 *recordWords;

    recordWords = nmMesWindowCurrent();
    if (recordWords == NULL) {
        return 0;
    }
    if (*recordWords < 0) {
        return 0;
    }
    ((NmMesWindowRecord *)recordWords)->pendingRecord = recordIndex;
    ((NmMesWindowRecord *)recordWords)->result = nmMesWindowCurrentAnim();
    iGpffffb578 = 0;
    return 1;
}

/* Queue a slot record change; the result snapshot deliberately comes from the current window. */
// FUN_002BAFC0
s32 nmMesWindowSetSlotParam(s64 slotIndex, s32 recordIndex)
{
    u8 **slot;
    u8 *record;

    slot = &D_00882F40[(s8)slotIndex];
    record = *slot;
    if (record == NULL) {
        return 0;
    }
    if (*(s32 *)record < 0) {
        return 0;
    }
    ((NmMesWindowRecord *)record)->pendingRecord = recordIndex;
    ((NmMesWindowRecord *)*slot)->result = nmMesWindowCurrentAnim();
    iGpffffb578 = 0;
    return 1;
}


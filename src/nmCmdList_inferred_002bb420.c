#include "nm_message_record.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(void *);



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
extern s32 iGpffffb57c;
extern s32 *nmMesWindowCurrent();
extern void (*D_00887300[])(s32 slotIndex, s32 arg1);
extern void itfMesWindowSetState(s32 slotIndex, s8 arg1);
extern void itfMesWindowRelease(s32 slotIndex);
extern void itfMesWindowClear(s32 slotIndex, s32 arg1);
extern void nmMesWindowSetSlotRunning(s64 slotIndex, s32 arg1);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bb420-002bb550 */

extern void fclFadeRectSetRenderStates(s32 slotIndex, u8 *arg1);
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
// Intent: stops, releases and clears the window in slot `arg0`, then marks the slot running again. Returns 1 when restarted.
// FUN_002BB420
s32 nmMesWindowRestartSlot(s64 slotIndex)
{
    s32 handle;
    u8 **slot;
    u8 *record;

    slot = &D_00882F40[(s8)slotIndex];
    record = *slot;
    if (record == NULL) {
        return 0;
    }
    handle = ((NmMesWindowRecord *)record)->handle;
    if (handle < 0) {
        return 0;
    }
    itfMesWindowSetState(handle, 0);
    itfMesWindowRelease(((NmMesWindowRecord *)*slot)->handle);
    itfMesWindowClear(((NmMesWindowRecord *)*slot)->handle, 0);
    nmMesWindowSetSlotRunning(slotIndex, 1);
    ((NmMesWindowRecord *)*slot)->state = 0;
    return 1;
}

// Intent: releases the current message window, resets its record and tears down the window state.
// FUN_002BB4E0
s32 nmMesWindowResetCurrent(void) {
    s32 *record;
    s32 handle;

    record = (s32 *)(nmMesWindowCurrent());
    if (record == NULL) {
        return 0;
    }
    handle = (s32)(((NmMesWindowRecord *)record)->handle);
    if (handle >= 0) {
        itfMesWindowReleaseIfActive(handle);
        ((NmMesWindowRecord *)record)->handle = -1;
        ((NmMesWindowRecord *)record)->state = 0;
        ((NmMesWindowRecord *)record)->paused = 0;
    }
    fclBankCancelPending();
    return 1;
}

// Intent: releases the window in slot `arg0`, frees its record and empties the slot. Returns 1 when the slot was live.
// FUN_002BB550
s32 nmMesWindowDestroySlot(s64 slotIndex)
{
    s32 handle;
    u8 **slot;
    u8 *record;

    slot = D_00882F40 + (s8)slotIndex;
    record = *slot;
    if (record == NULL) {
        return 0;
    }
    handle = ((NmMesWindowRecord *)record)->handle;
    if (handle >= 0) {
        itfMesWindowReleaseIfActive(handle);
        ((NmMesWindowRecord *)*slot)->handle = -1;
        ((NmMesWindowRecord *)*slot)->state = 0;
        ((NmMesWindowRecord *)*slot)->paused = 0;
        jtbl_008873EC[0](*slot);
        *slot = NULL;
    }
    fclBankCancelPending();
    return 1;
}


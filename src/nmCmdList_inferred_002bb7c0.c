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
extern void nmMesWindowStepCurrent(s32 release);



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
extern void itfMesWindowSetState(s32 handle, s8 state);
extern void itfMesWindowRelease(s32 handle);
extern void itfMesWindowClear(s32 handle, s32 clearLabel);
extern s32 itfMesWindowState();
extern s32 itfMesWindowGetAnim(s32 handle);
extern void itfMesWindowLayout(s32 handle, s32 recordIndex);
extern void itfMesWindowSetCursor(s32 handle, s32 entryIndex);
extern u32 itfMesWindowSetParam(s32 handle, s32 button, s32 entryIndex);
extern void nmMesWindowSetCurrentRunning(s32 running);
extern void nmMesWindowSetSlotRunning(s64 slotIndex, s32 running);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bb7c0-002bbcf0 */

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
// Intent: advances the state machine of the current message window; `arg0` releases the window once it closes.
// FUN_002BB7C0
void nmMesWindowStepCurrent(s32 release)
{
    s32 handle;
    s8 state;
    NmMesWindowRecord *record;

    record = (NmMesWindowRecord *)nmMesWindowCurrent();
    if ((record != NULL) && (handle = record->handle, handle >= 0)) {
        state = record->state;
        switch (state) {
        case 0:
            return;
        case 1:
            if (itfMesWindowState(handle, state) < 0) {
                record->state = 2;
                break;
            }
            break;
        case 2:
        {
            s32 *currentWords;
            s32 *resultWords;
            s32 animationHandle;
            s32 latched;
            s32 result;

            if (record->pendingRecord >= 0) {
                if (iGpffffb578 == 1) {
                    itfMesWindowSetParam(handle, 6, 1);
                }
                itfMesWindowSetCursor(record->handle, record->cursor);
                itfMesWindowLayout(record->handle, record->pendingRecord);
                record->pendingRecord = -1;
            }
            if (record->paused == 0) {
                currentWords = nmMesWindowCurrent();
                if (currentWords == NULL) {
                    latched = 0;
                } else {
                    animationHandle = currentWords[0];
                    if (animationHandle < 0) {
                        latched = 0;
                    } else if (itfMesWindowGetAnim(animationHandle) < 0) {
                        latched = 0;
                    } else {
                        resultWords = nmMesWindowCurrent();
                        if (resultWords == NULL) {
                            result = -1;
                        } else {
                            animationHandle = resultWords[0];
                            if (animationHandle < 0) {
                                result = -1;
                            } else {
                                result = itfMesWindowGetAnimAux(animationHandle);
                            }
                        }
                        ((NmMesWindowRecord *)currentWords)->result = result;
                        latched = 1;
                    }
                }
                if (latched == 0) {
                    record->state = 3;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            NmMesWindowRecord *closingRecord;

            closingRecord = (NmMesWindowRecord *)nmMesWindowCurrent();
            if (closingRecord != NULL) {
                handle = closingRecord->handle;
                if (handle >= 0) {
                    itfMesWindowSetState(handle, 0);
                    if (release != 0) {
                        itfMesWindowRelease(closingRecord->handle);
                    }
                    itfMesWindowClear(closingRecord->handle, 0);
                    nmMesWindowSetCurrentRunning(1);
                    closingRecord->state = 0;
                }
            }
            break;
        }
        }
    }
}

// Intent: advances the state machine of slot `release`; `arg1` releases the window once it closes.
// FUN_002BB9E0
void nmMesWindowStepSlot(s32 slotIndex, s32 release)
{
    extern void nmMesWindowSetSlotRunning();
    s32 handle;
    s32 releaseMessage;
    s32 animationHandle;
    s32 resultHandle;
    s32 closingHandle;
    s32 latched;
    s64 index;
    s8 state;
    s32 result;
    s32 closingResult;
    NmMesWindowRecord **layoutSlot;
    NmMesWindowRecord **closingSlot;
    NmMesWindowRecord **slot;
    NmMesWindowRecord **resultSlot;
    NmMesWindowRecord *layoutRecord;
    NmMesWindowRecord *pendingRecord;
    NmMesWindowRecord *resultRecord;
    NmMesWindowRecord *closingRecord;
    NmMesWindowRecord *animationRecord;
    NmMesWindowRecord *record;
    releaseMessage = release;
    index = (s8)slotIndex;
    slot = &((NmMesWindowRecord **)D_00882F40)[(s8)index];
    record = *slot;
    if ((record != NULL) && (handle = record->handle, handle >= 0)) {
        state = record->state;
        switch (state) {
        case 0:
            return;
        case 1:
            if (itfMesWindowState(handle, state, record) < 0) {
                (*slot)->state = 2;
                return;
            }
            break;
        case 2:
            if (record->pendingRecord >= 0) {
                if (iGpffffb578 == 1) {
                    itfMesWindowSetParam(handle, 6, 1);
                }
                layoutSlot = &((NmMesWindowRecord **)D_00882F40)[(s8)slotIndex];
                layoutRecord = *layoutSlot;
                itfMesWindowSetCursor(layoutRecord->handle, layoutRecord->cursor);
                pendingRecord = *layoutSlot;
                itfMesWindowLayout(pendingRecord->handle, pendingRecord->pendingRecord);
                (*layoutSlot)->pendingRecord = -1;
            }
            animationRecord = *slot;
            if (animationRecord->paused == 0) {
                if (animationRecord == NULL) {
                    latched = 0;
                } else {
                    animationHandle = animationRecord->handle;
                    if (animationHandle < 0) {
                        latched = 0;
                    } else if (itfMesWindowGetAnim(animationHandle) < 0) {
                        latched = 0;
                    } else {
                        resultRecord = *slot;
                        if (resultRecord == NULL) {
                            result = -1;
                        } else {
                            resultHandle = resultRecord->handle;
                            if (resultHandle < 0) {
                                result = -1;
                            } else {
                                result = itfMesWindowGetAnimAux(resultHandle);
                            }
                        }
                        (*slot)->result = result;
                        latched = 1;
                    }
                }
                if (latched == 0) {
                    resultSlot = &((NmMesWindowRecord **)D_00882F40)[(s8)slotIndex];
                    (*resultSlot)->state = 3;
                    closingRecord = *resultSlot;
                    if (closingRecord == NULL) {
                        closingResult = -1;
                    } else {
                        closingHandle = closingRecord->handle;
                        if (closingHandle < 0) {
                            closingResult = -1;
                        } else {
                            closingResult = itfMesWindowGetAnimAux(closingHandle);
                        }
                    }
                    (&iGpffffb580)[(s8)index] = closingResult;
                    return;
                }
            }
            break;
        case 3:
            if ((record != NULL) && (handle = record->handle, handle >= 0)) {
                itfMesWindowSetState(handle, 0);
                if (releaseMessage != 0) {
                    itfMesWindowRelease((*slot)->handle);
                }
                closingSlot = &((NmMesWindowRecord **)D_00882F40)[(s8)slotIndex];
                itfMesWindowClear((*closingSlot)->handle, 0);
                nmMesWindowSetSlotRunning(slotIndex, 1);
                (*closingSlot)->state = 0;
            }
            break;
        }
    }
}

// Intent: steps the current message window with release enabled.
// FUN_002BBCC0
void nmMesWindowStepCurrentRelease(void)
{
    nmMesWindowStepCurrent(1);
}

// Intent: steps the window in slot `arg0` with release enabled.
// FUN_002BBCF0
void nmMesWindowStepSlotRelease(s32 slotIndex) {
    nmMesWindowStepSlot(slotIndex, 1);
}


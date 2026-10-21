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
extern void itfMesWindowSetState(s32 handle, s8 state);
extern void itfMesWindowRelease(s32 handle);
extern void itfMesWindowClear(s32 handle, s32 clearLabel);
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


/* Retail digit RGBA occupies the four bytes at draw+0x75; these guarded packed views keep the
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
#pragma push
#pragma pop
/* Row and value are signed halfwords; retail discards the row's high bits and passes both colours
 * as words, so the callee declaration takes u32 colours. */
#pragma push
#pragma pop
/* Keep the two positions, colors, and character-representation bounds
   snapshots separate across writes to the draw slots. The depth precedes
   the layer in the recovered signature. See the worker3 digit-pair archive. */
#pragma push
#pragma pop
/* Stops, releases and clears the window in slot slotIndex, then marks the slot as running again.
 * Returns 1 when it restarts. */
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

// Releases the current message window, resets its record and tears down the window state.
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

// Releases the window in slot slotIndex, frees its record and empties the slot; returns 1 when the
// slot was live.
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


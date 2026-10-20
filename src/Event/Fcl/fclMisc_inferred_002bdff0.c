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
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}



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
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern s32 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 fclCalendarMonthOrder(s32 month);
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










/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002b; members 002bdff0-002be160 */

extern void fclFadeRectSetRenderStates(s32 item, u8 *work);
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Test category-3 item availability against the current month and day. */
// FUN_002BDFF0
s32 fclItemIsDateAvailable(s16 item)
{
    s32 availableMonth;
    s32 availableMonthAgain;
    s32 availableDay;

    if (datEntryGetKind(item) != 3) {
        goto false_result;
    }
    availableMonth = fclCalendarMonthOrder((u8)datItemAvailableMonth(item)) & 0xFF;
    if (availableMonth < (fclCalendarMonthOrder(fclCalendarMonth()) & 0xFF)) {
        return 1;
    }
    availableMonthAgain = fclCalendarMonthOrder((u8)datItemAvailableMonth(item)) & 0xFF;
    if (availableMonthAgain != (fclCalendarMonthOrder(fclCalendarMonth()) & 0xFF)) {
        goto false_result;
    }
    availableDay = (s8)datItemAvailableDay(item);
    if (availableDay <= (fclCalendarDay() & 0xFF)) {
        return 1;
    }
false_result:
    return 0;
}

/* Map a month to its position in the twelve-entry calendar ordering; unknown months return zero. */
// FUN_002BE100
s32 fclCalendarMonthOrder(s32 month) {
    s32 i = 0;
    s32 key = month & 0xFF;
    s8 *t = D_007488F8;

    while ((i & 0xFF) < 0xC) {
        if (key == t[i & 0xFF]) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
    return 0;
}

/* Compare the moon phase with a halfword threshold; zero imposes no requirement. */
// FUN_002BE160
s32 fclMoonPhaseAtLeast(s32 dateIndex, s32 requiredPhase) {
    s32 n = requiredPhase & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase(dateIndex) & 0xFF) >= n;
}


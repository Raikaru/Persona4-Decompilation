/* Original translation unit sdkListState.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

#include "sdk_list_state.h"

extern void kAssertFail(void* file, u32 line);
extern s32 sdkListStateSeek(u8* state, s32 value);
extern void sdkListStateSetCount(u8* state, s32 value);
extern void memset(void* dst, s32 value, u32 size);
extern void sdkListStateConfigure(u8* state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern void sdkListStateSetActive(u8* state, s32 value);
extern void sdkListStateSetRefresh(u8* state, s32 value);
extern void sdkListStateEnableClamp(u8* state);
extern void sdkListStateDisableClamp(u8* state);
extern s32 sdkListStateStepForward(u8* state);
extern s32 sdkListStateStepBack(u8* state);
extern s32 sdkListStateRepeatForward(u8* state);
extern s32 sdkListStateRepeatBack(u8* state);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0274[];
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u32 D_007105E8[];



// Intent: zeroes the 0x2C-byte list state and sets its visible row count (arg1) and item count (arg2).
// FUN_004535C0
void sdkListStateInit(u8* state, s32 value, s32 itemCount)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x45);
    }
    if (value <= 0) {
        kAssertFail(D_007105E8, 0x46);
    }
    memset(state, 0, 0x2C);
    sdkListStateConfigure(state, value, itemCount, 0, 0);
}

// Intent: fully configures the list state: visible rows, item count, cursor and scroll offset, then sets the active and refresh flags.
/* measured: access-site state fields lose MATCH; a typed local state alias retains all original instructions. */
// FUN_00453670
void sdkListStateConfigure(u8* state, s32 value, s32 itemCount, s32 cursor, s32 scroll)
{
    SdkListState *typedState = (SdkListState *)state;
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x4F);
    }
    if (value <= 0) {
        kAssertFail(D_007105E8, 0x50);
    }
    memset(state, 0, 0x2C);
    ((SdkListState *)state)->visibleRows = value;
    ((SdkListState *)state)->reservedRows = 2;
    ((SdkListState *)state)->itemCount = itemCount;
    ((SdkListState *)state)->cursor = cursor;
    ((SdkListState *)state)->scroll = scroll;
    typedState->unk1C = value;
    if (value < 0) {
        ((SdkListState *)state)->unk1C = 0;
    }
    sdkListStateSetActive(state, 1);
    sdkListStateSetRefresh(state, 1);
}

// Intent: sets or clears the active flag (bit 1) of the list state.
// FUN_00453760
void sdkListStateSetActive(u8* state, s32 value)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x62);
    }
    if (value) {
        ((SdkListState *)state)->flags |= 2;
    } else {
        ((SdkListState *)state)->flags &= ~2;
    }
}

// Intent: sets or clears the refresh flag (bit 2) that the input handler reads.
// FUN_004537E0
void sdkListStateSetRefresh(u8* state, s32 value)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x6F);
    }
    if (value) {
        ((SdkListState *)state)->flags |= 4;
    } else {
        ((SdkListState *)state)->flags &= ~4;
    }
}

// Intent: stores the four primary button masks at +0x04..+0x0A.
// FUN_00453860
void sdkListStateSetPrimaryMasks(u8* state, s32 value, s32 itemCount, s32 cursor, s32 scroll)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x7A);
    }
    ((SdkListState *)state)->primaryForward = value;
    ((SdkListState *)state)->primaryBack = itemCount;
    ((SdkListState *)state)->primaryRepeatForward = cursor;
    ((SdkListState *)state)->primaryRepeatBack = scroll;
}

// Intent: stores the four secondary button masks at +0x0C..+0x12.
// FUN_004538E0
void sdkListStateSetSecondaryMasks(u8* state, s32 value, s32 itemCount, s32 cursor, s32 scroll)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x85);
    }
    ((SdkListState *)state)->secondaryForward = value;
    ((SdkListState *)state)->secondaryBack = itemCount;
    ((SdkListState *)state)->secondaryRepeatForward = cursor;
    ((SdkListState *)state)->secondaryRepeatBack = scroll;
}

// Intent: reads the pressed-button masks and moves the cursor. Returns 1 or 2 for a forward or back step, 3 or 4 for the other two directions, 0 when nothing moved.
// FUN_00453960
s32 sdkListStateHandleInput(u8* state)
{
    s32 result;
    s32 primaryForwardMask;
    s32 secondaryForwardMask;
    s32 primaryBackMask;
    s32 secondaryBackMask;
    s32 repeatForwardMask;
    s32 repeatBackMask;
    result = 0;
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x91);
    }
    if (((SdkListState *)state)->flags & 2) {
        sdkListStateEnableClamp(state);
    }
    primaryForwardMask = ((SdkListState *)state)->primaryForward;
    if ((D_008C024E[0] & primaryForwardMask) || (secondaryForwardMask = ((SdkListState *)state)->secondaryForward, (D_008C0276[0] & secondaryForwardMask) != 0)) {
        if ((((SdkListState *)state)->flags & 4) || (((SdkListState *)state)->itemCount - 1 != ((SdkListState *)state)->scroll + ((SdkListState *)state)->cursor)) {
            sdkListStateDisableClamp(state);
        }
        if (sdkListStateStepForward(state) != 0) {
            result = 1;
        }
        goto done;
    }
    primaryBackMask = ((SdkListState *)state)->primaryBack;
    if ((D_008C024E[0] & primaryBackMask) || (secondaryBackMask = ((SdkListState *)state)->secondaryBack, (D_008C0276[0] & secondaryBackMask) != 0)) {
        if ((((SdkListState *)state)->flags & 4) || (((SdkListState *)state)->scroll + ((SdkListState *)state)->cursor != 0)) {
            sdkListStateDisableClamp(state);
        }
        if (sdkListStateStepBack(state) != 0) {
            result = 2;
        }
        goto done;
    }
    repeatForwardMask = ((SdkListState *)state)->primaryRepeatForward;
    if ((D_008C024C[0] & repeatForwardMask) || (D_008C0274[0] & ((SdkListState *)state)->secondaryRepeatForward)) {
        if (((D_008C0252[0] & repeatForwardMask) || (D_008C027A[0] & ((SdkListState *)state)->secondaryRepeatForward)) && sdkListStateRepeatForward(state) != 0) {
            result = 3;
        }
        goto done;
    }
    repeatBackMask = ((SdkListState *)state)->primaryRepeatBack;
    if ((D_008C024C[0] & repeatBackMask) || (D_008C0274[0] & ((SdkListState *)state)->secondaryRepeatBack)) {
        if (((D_008C0252[0] & repeatBackMask) || (D_008C027A[0] & ((SdkListState *)state)->secondaryRepeatBack)) && sdkListStateRepeatBack(state) != 0) {
            result = 4;
        }
        goto done;
    }
    if ((D_008C024C[0] & primaryForwardMask) || (D_008C0274[0] & secondaryForwardMask)) {
        if (((D_008C0252[0] & primaryForwardMask) || (D_008C027A[0] & secondaryForwardMask)) && sdkListStateStepForward(state) != 0) {
            result = 1;
        }
        goto done;
    }
    if ((D_008C024C[0] & primaryBackMask) || (D_008C0274[0] & secondaryBackMask)) {
        if (((D_008C0252[0] & primaryBackMask) || (D_008C027A[0] & secondaryBackMask)) && sdkListStateStepBack(state) != 0) {
            result = 2;
        }
        goto done;
    }
    return 0;
done:
    return result;
}

// Intent: appends one item by raising the count by one.
// FUN_00453C80
void sdkListStateAddItem(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0xD7);
    }
    sdkListStateSetCount(state, ((SdkListState *)state)->itemCount + 1);
}
// Intent: sets the item count; if the count shrinks, re-seeks the cursor inside the new range.
/* measured: access-site state fields lose MATCH; a typed local state alias retains all original instructions. */
// FUN_00453CE0
void sdkListStateSetCount(u8* state, s32 value)
{
    SdkListState *typedState = (SdkListState *)state;
    if (state == NULL) {
        kAssertFail(D_007105E8, 0xF4);
    }
    if (value < typedState->itemCount) {
        ((SdkListState *)state)->itemCount = value;
        sdkListStateSeek(state, ((SdkListState *)state)->scroll + ((SdkListState *)state)->cursor);
        return;
    }
    ((SdkListState *)state)->itemCount = value;
}



// Intent: returns the scroll offset (+0x28).
// FUN_00453D70
s32 sdkListStateGetScroll(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x101);
    }
    return ((SdkListState *)state)->scroll;
}



// Intent: returns the cursor's offset within the visible window (+0x24).
// FUN_00453DC0
s32 sdkListStateGetCursor(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x108);
    }
    return ((SdkListState *)state)->cursor;
}



// Intent: returns the item count (+0x20).
// FUN_00453E10
s32 sdkListStateGetCount(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x10F);
    }
    return ((SdkListState *)state)->itemCount;
}



// Intent: returns the visible row count (+0x14).
// FUN_00453E60
s32 sdkListStateGetVisible(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x116);
    }
    return ((SdkListState *)state)->visibleRows;
}

// Intent: moves the cursor to the given item index, clamped to the valid range, and recomputes the scroll offset.
/* measured: access-site state fields lose MATCH; a typed local state alias retains all original instructions. */
// FUN_00453EB0
s32 sdkListStateSeek(u8* state, s32 value)
{
    SdkListState *typedState = (SdkListState *)state;
    s32 hi;
    s32 diff;
    s32 remainingRows;
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x125);
    }
    if (typedState->itemCount == 0) {
        ((SdkListState *)state)->scroll = 0;
        ((SdkListState *)state)->cursor = 0;
        return 1;
    }
    if (value <= 0) {
        value = 0;
    } else if (((SdkListState *)state)->itemCount < value) {
        value = ((SdkListState *)state)->itemCount - 1;
    }
    if (value - typedState->cursor >= 0) {
        hi = ((SdkListState *)state)->visibleRows;
        if (typedState->itemCount < hi) {
            hi = typedState->itemCount;
        }
        diff = value - typedState->cursor;
        typedState->scroll = diff;
        remainingRows = ((SdkListState *)state)->itemCount - hi;
        if (remainingRows < diff) {
            ((SdkListState *)state)->scroll = remainingRows;
            ((SdkListState *)state)->cursor = value - remainingRows;
        }
    } else {
        ((SdkListState *)state)->scroll = 0;
        ((SdkListState *)state)->cursor = value;
    }
    return 1;
}

// Intent: sets the visible row count (+0x14).
// FUN_00453FA0
void sdkListStateSetVisible(u8* state, s32 value)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x144);
    }
    ((SdkListState *)state)->visibleRows = value;
}

// Intent: sets the rows reserved at the top (+0x18) that the cursor cannot use.
// FUN_00453FF0
void sdkListStateSetReservedRows(u8* state, s32 value)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x14C);
    }
    ((SdkListState *)state)->reservedRows = value;
}

// Intent: sets the clamp flag (bit 0) so the cursor stops at the ends instead of wrapping.
// FUN_00454040
void sdkListStateEnableClamp(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x154);
    }
    ((SdkListState *)state)->flags |= 1;
}

// Intent: clears the clamp flag (bit 0) so the cursor wraps at the ends.
// FUN_00454090
void sdkListStateDisableClamp(u8* state)
{
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x15B);
    }
    ((SdkListState *)state)->flags &= ~1;
}

// Intent: steps the cursor forward one row, scrolling when it reaches the bottom of the window. Returns 1 when it moved.
/* measured: access-site state fields lose MATCH; a typed local state alias retains all original instructions. */
// FUN_004540E0
s32 sdkListStateStepForward(u8* state)
{
    SdkListState *typedState = (SdkListState *)state;
    s32 cur;
    s32 hi;
    s32 pos;
    s32 remainingRows;
    s32 nextCursor;
    s32 scrollOffset;
    s32 flag;
    cur = ((SdkListState *)state)->itemCount;
    if (cur < 2) {
        return 0;
    }
    hi = ((SdkListState *)state)->visibleRows;
    remainingRows = hi - ((SdkListState *)state)->reservedRows;
    if (remainingRows <= 0) {
        remainingRows = 1;
    }
    pos = typedState->cursor;
    nextCursor = pos + 1;
    if (nextCursor < remainingRows) {
        if (nextCursor < cur) {
            ((SdkListState *)state)->cursor = nextCursor;
            goto done;
        }
        if (state == NULL) {
            kAssertFail(D_007105E8, 0x163);
        }
        flag = (((SdkListState *)state)->flags & 1) != 0;
        if (!flag) {
            ((SdkListState *)state)->cursor = 0;
            ((SdkListState *)state)->scroll = 0;
            goto done;
        }
        return 0;
    }
    scrollOffset = typedState->scroll;
    if (scrollOffset + hi < cur) {
        ((SdkListState *)state)->scroll = scrollOffset + 1;
        goto done;
    }
    if (scrollOffset + pos < cur - 1) {
        ((SdkListState *)state)->cursor = nextCursor;
        goto done;
    }
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x163);
    }
    flag = (((SdkListState *)state)->flags & 1) != 0;
    if (!flag) {
        ((SdkListState *)state)->cursor = 0;
        ((SdkListState *)state)->scroll = 0;
        goto done;
    }
    return 0;
done:
    return 1;
}
// Intent: steps the cursor back one row, scrolling when it reaches the top of the window. Returns 1 when it moved.
/* measured: access-site state fields lose MATCH; a typed local state alias retains all original instructions. */
// FUN_00454250
s32 sdkListStateStepBack(u8* state)
{
    SdkListState *typedState = (SdkListState *)state;
    s32 cur;
    s32 hi;
    s32 lo;
    s32 pos;
    s32 nextCursor;
    s32 scrollOffset;
    s32 previousScroll;
    s32 flag;
    cur = typedState->itemCount;
    if (cur < 2) {
        return 0;
    }
    hi = ((SdkListState *)state)->visibleRows;
    if (cur < hi) {
        hi = cur;
    }
    lo = ((SdkListState *)state)->reservedRows;
    if (lo <= 0) {
        lo = 0;
    }
    pos = typedState->cursor;
    nextCursor = pos - 1;
    if (nextCursor >= lo) {
        if (pos > 0) {
            ((SdkListState *)state)->cursor = nextCursor;
            goto ret1;
        }
        if (state == NULL) {
            kAssertFail(D_007105E8, 0x163);
        }
        flag = (((SdkListState *)state)->flags & 1) != 0;
        if (!flag) {
            ((SdkListState *)state)->cursor = hi - 1;
            ((SdkListState *)state)->scroll = ((SdkListState *)state)->itemCount - hi;
            goto ret1;
        }
        return 0;
    }
    scrollOffset = typedState->scroll;
    previousScroll = scrollOffset - 1;
    if (previousScroll >= 0) {
        ((SdkListState *)state)->scroll = previousScroll;
        goto ret1;
    }
    if (scrollOffset + pos > 0) {
        ((SdkListState *)state)->cursor = nextCursor;
        goto ret1;
    }
    if (state == NULL) {
        kAssertFail(D_007105E8, 0x163);
    }
    flag = (((SdkListState *)state)->flags & 1) != 0;
    if (!flag) {
        ((SdkListState *)state)->cursor = hi - 1;
        ((SdkListState *)state)->scroll = ((SdkListState *)state)->itemCount - hi;
        goto ret1;
    }
    return 0;
ret1:
    return 1;
}


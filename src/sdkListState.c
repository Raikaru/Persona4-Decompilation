/* Original translation unit sdkListState.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void kAssertFail(void* message, u32 code);
extern s32 sdkListStateSeek(u8* obj, s32 value);
extern void sdkListStateSetCount(u8* arg0, s32 arg1);
extern void memset(void* dst, s32 value, u32 size);
extern void sdkListStateConfigure(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetActive(u8* arg0, s32 arg1);
extern void sdkListStateSetRefresh(u8* arg0, s32 arg1);
extern void sdkListStateEnableClamp(u8* arg0);
extern void sdkListStateDisableClamp(u8* arg0);
extern s32 sdkListStateStepForward(u8* arg0);
extern s32 sdkListStateStepBack(u8* arg0);
extern s32 sdkListStateRepeatForward(u8* arg0);
extern s32 sdkListStateRepeatBack(u8* arg0);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0274[];
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u32 D_007105E8[];



// Intent: zeroes the 0x2C-byte list state and sets its visible row count (arg1) and item count (arg2).
// FUN_004535C0
void sdkListStateInit(u8* arg0, s32 arg1, s32 arg2)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x45);
    }
    if (arg1 <= 0) {
        kAssertFail(D_007105E8, 0x46);
    }
    memset(arg0, 0, 0x2C);
    sdkListStateConfigure(arg0, arg1, arg2, 0, 0);
}

// Intent: fully configures the list state: visible rows, item count, cursor and scroll offset, then sets the active and refresh flags.
// FUN_00453670
void sdkListStateConfigure(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x4F);
    }
    if (arg1 <= 0) {
        kAssertFail(D_007105E8, 0x50);
    }
    memset(arg0, 0, 0x2C);
    *(s32*)(arg0 + 0x14) = arg1;
    *(s32*)(arg0 + 0x18) = 2;
    *(s32*)(arg0 + 0x20) = arg2;
    *(s32*)(arg0 + 0x24) = arg3;
    *(s32*)(arg0 + 0x28) = arg4;
    *(s32*)(arg0 + 0x1C) = arg1;
    if (arg1 < 0) {
        *(s32*)(arg0 + 0x1C) = 0;
    }
    sdkListStateSetActive(arg0, 1);
    sdkListStateSetRefresh(arg0, 1);
}

// Intent: sets or clears the active flag (bit 1) of the list state.
// FUN_00453760
void sdkListStateSetActive(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x62);
    }
    if (arg1) {
        *(s32*)(arg0 + 0x0) |= 2;
    } else {
        *(s32*)(arg0 + 0x0) &= ~2;
    }
}

// Intent: sets or clears the refresh flag (bit 2) that the input handler reads.
// FUN_004537E0
void sdkListStateSetRefresh(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x6F);
    }
    if (arg1) {
        *(s32*)(arg0 + 0x0) |= 4;
    } else {
        *(s32*)(arg0 + 0x0) &= ~4;
    }
}

// Intent: stores the four primary button masks at +0x04..+0x0A.
// FUN_00453860
void sdkListStateSetPrimaryMasks(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x7A);
    }
    *(s16*)(arg0 + 0x4) = arg1;
    *(s16*)(arg0 + 0x6) = arg2;
    *(s16*)(arg0 + 0x8) = arg3;
    *(s16*)(arg0 + 0xA) = arg4;
}

// Intent: stores the four secondary button masks at +0x0C..+0x12.
// FUN_004538E0
void sdkListStateSetSecondaryMasks(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x85);
    }
    *(s16*)(arg0 + 0xC) = arg1;
    *(s16*)(arg0 + 0xE) = arg2;
    *(s16*)(arg0 + 0x10) = arg3;
    *(s16*)(arg0 + 0x12) = arg4;
}

// Intent: reads the pressed-button masks and moves the cursor. Returns 1 or 2 for a forward or back step, 3 or 4 for the other two directions, 0 when nothing moved.
// FUN_00453960
s32 sdkListStateHandleInput(u8* arg0)
{
    s32 result;
    s32 f4;
    s32 fC;
    s32 f6;
    s32 fE;
    s32 f8;
    s32 fA;
    result = 0;
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x91);
    }
    if (*(s32*)(arg0 + 0x0) & 2) {
        sdkListStateEnableClamp(arg0);
    }
    f4 = *(u16*)(arg0 + 0x4);
    if ((D_008C024E[0] & f4) || (fC = *(u16*)(arg0 + 0xC), (D_008C0276[0] & fC) != 0)) {
        if ((*(s32*)(arg0 + 0x0) & 4) || (*(s32*)(arg0 + 0x20) - 1 != *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24))) {
            sdkListStateDisableClamp(arg0);
        }
        if (sdkListStateStepForward(arg0) != 0) {
            result = 1;
        }
        goto done;
    }
    f6 = *(u16*)(arg0 + 0x6);
    if ((D_008C024E[0] & f6) || (fE = *(u16*)(arg0 + 0xE), (D_008C0276[0] & fE) != 0)) {
        if ((*(s32*)(arg0 + 0x0) & 4) || (*(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24) != 0)) {
            sdkListStateDisableClamp(arg0);
        }
        if (sdkListStateStepBack(arg0) != 0) {
            result = 2;
        }
        goto done;
    }
    f8 = *(u16*)(arg0 + 0x8);
    if ((D_008C024C[0] & f8) || (D_008C0274[0] & *(u16*)(arg0 + 0x10))) {
        if (((D_008C0252[0] & f8) || (D_008C027A[0] & *(u16*)(arg0 + 0x10))) && sdkListStateRepeatForward(arg0) != 0) {
            result = 3;
        }
        goto done;
    }
    fA = *(u16*)(arg0 + 0xA);
    if ((D_008C024C[0] & fA) || (D_008C0274[0] & *(u16*)(arg0 + 0x12))) {
        if (((D_008C0252[0] & fA) || (D_008C027A[0] & *(u16*)(arg0 + 0x12))) && sdkListStateRepeatBack(arg0) != 0) {
            result = 4;
        }
        goto done;
    }
    if ((D_008C024C[0] & f4) || (D_008C0274[0] & fC)) {
        if (((D_008C0252[0] & f4) || (D_008C027A[0] & fC)) && sdkListStateStepForward(arg0) != 0) {
            result = 1;
        }
        goto done;
    }
    if ((D_008C024C[0] & f6) || (D_008C0274[0] & fE)) {
        if (((D_008C0252[0] & f6) || (D_008C027A[0] & fE)) && sdkListStateStepBack(arg0) != 0) {
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
void sdkListStateAddItem(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0xD7);
    }
    sdkListStateSetCount(arg0, *(s32*)(arg0 + 0x20) + 1);
}
// Intent: sets the item count; if the count shrinks, re-seeks the cursor inside the new range.
// FUN_00453CE0
void sdkListStateSetCount(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0xF4);
    }
    if (arg1 < *(s32*)(arg0 + 0x20)) {
        *(s32*)(arg0 + 0x20) = arg1;
        sdkListStateSeek(arg0, *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24));
        return;
    }
    *(s32*)(arg0 + 0x20) = arg1;
}



// Intent: returns the scroll offset (+0x28).
// FUN_00453D70
s32 sdkListStateGetScroll(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x101);
    }
    return *(s32*)(arg0 + 0x28);
}



// Intent: returns the cursor's offset within the visible window (+0x24).
// FUN_00453DC0
s32 sdkListStateGetCursor(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x108);
    }
    return *(s32*)(arg0 + 0x24);
}



// Intent: returns the item count (+0x20).
// FUN_00453E10
s32 sdkListStateGetCount(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x10F);
    }
    return *(s32*)(arg0 + 0x20);
}



// Intent: returns the visible row count (+0x14).
// FUN_00453E60
s32 sdkListStateGetVisible(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x116);
    }
    return *(s32*)(arg0 + 0x14);
}

// Intent: moves the cursor to the given item index, clamped to the valid range, and recomputes the scroll offset.
// FUN_00453EB0
s32 sdkListStateSeek(u8* arg0, s32 arg1)
{
    s32 hi;
    s32 diff;
    s32 v2;
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x125);
    }
    if (*(s32*)(arg0 + 0x20) == 0) {
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        return 1;
    }
    if (arg1 <= 0) {
        arg1 = 0;
    } else if (*(s32*)(arg0 + 0x20) < arg1) {
        arg1 = *(s32*)(arg0 + 0x20) - 1;
    }
    if (arg1 - *(s32*)(arg0 + 0x24) >= 0) {
        hi = *(s32*)(arg0 + 0x14);
        if (*(s32*)(arg0 + 0x20) < hi) {
            hi = *(s32*)(arg0 + 0x20);
        }
        diff = arg1 - *(s32*)(arg0 + 0x24);
        *(s32*)(arg0 + 0x28) = diff;
        v2 = *(s32*)(arg0 + 0x20) - hi;
        if (v2 < diff) {
            *(s32*)(arg0 + 0x28) = v2;
            *(s32*)(arg0 + 0x24) = arg1 - v2;
        }
    } else {
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = arg1;
    }
    return 1;
}

// Intent: sets the visible row count (+0x14).
// FUN_00453FA0
void sdkListStateSetVisible(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x144);
    }
    *(s32*)(arg0 + 0x14) = arg1;
}

// Intent: sets the rows reserved at the top (+0x18) that the cursor cannot use.
// FUN_00453FF0
void sdkListStateSetReservedRows(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x14C);
    }
    *(s32*)(arg0 + 0x18) = arg1;
}

// Intent: sets the clamp flag (bit 0) so the cursor stops at the ends instead of wrapping.
// FUN_00454040
void sdkListStateEnableClamp(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x154);
    }
    *(s32*)(arg0 + 0x0) |= 1;
}

// Intent: clears the clamp flag (bit 0) so the cursor wraps at the ends.
// FUN_00454090
void sdkListStateDisableClamp(u8* arg0)
{
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x15B);
    }
    *(s32*)(arg0 + 0x0) &= ~1;
}

// Intent: steps the cursor forward one row, scrolling when it reaches the bottom of the window. Returns 1 when it moved.
// FUN_004540E0
s32 sdkListStateStepForward(u8* arg0)
{
    s32 cur;
    s32 hi;
    s32 pos;
    s32 v2;
    s32 v4;
    s32 v3;
    s32 flag;
    cur = *(s32*)(arg0 + 0x20);
    if (cur < 2) {
        return 0;
    }
    hi = *(s32*)(arg0 + 0x14);
    v2 = hi - *(s32*)(arg0 + 0x18);
    if (v2 <= 0) {
        v2 = 1;
    }
    pos = *(s32*)(arg0 + 0x24);
    v4 = pos + 1;
    if (v4 < v2) {
        if (v4 < cur) {
            *(s32*)(arg0 + 0x24) = v4;
            goto done;
        }
        if (arg0 == NULL) {
            kAssertFail(D_007105E8, 0x163);
        }
        flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
        if (!flag) {
            *(s32*)(arg0 + 0x24) = 0;
            *(s32*)(arg0 + 0x28) = 0;
            goto done;
        }
        return 0;
    }
    v3 = *(s32*)(arg0 + 0x28);
    if (v3 + hi < cur) {
        *(s32*)(arg0 + 0x28) = v3 + 1;
        goto done;
    }
    if (v3 + pos < cur - 1) {
        *(s32*)(arg0 + 0x24) = v4;
        goto done;
    }
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x163);
    }
    flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
    if (!flag) {
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        goto done;
    }
    return 0;
done:
    return 1;
}
// Intent: steps the cursor back one row, scrolling when it reaches the top of the window. Returns 1 when it moved.
// FUN_00454250
s32 sdkListStateStepBack(u8* arg0)
{
    s32 cur;
    s32 hi;
    s32 lo;
    s32 pos;
    s32 v4;
    s32 v3;
    s32 v31;
    s32 flag;
    cur = *(s32*)(arg0 + 0x20);
    if (cur < 2) {
        return 0;
    }
    hi = *(s32*)(arg0 + 0x14);
    if (cur < hi) {
        hi = cur;
    }
    lo = *(s32*)(arg0 + 0x18);
    if (lo <= 0) {
        lo = 0;
    }
    pos = *(s32*)(arg0 + 0x24);
    v4 = pos - 1;
    if (v4 >= lo) {
        if (pos > 0) {
            *(s32*)(arg0 + 0x24) = v4;
            goto ret1;
        }
        if (arg0 == NULL) {
            kAssertFail(D_007105E8, 0x163);
        }
        flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
        if (!flag) {
            *(s32*)(arg0 + 0x24) = hi - 1;
            *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x20) - hi;
            goto ret1;
        }
        return 0;
    }
    v3 = *(s32*)(arg0 + 0x28);
    v31 = v3 - 1;
    if (v31 >= 0) {
        *(s32*)(arg0 + 0x28) = v31;
        goto ret1;
    }
    if (v3 + pos > 0) {
        *(s32*)(arg0 + 0x24) = v4;
        goto ret1;
    }
    if (arg0 == NULL) {
        kAssertFail(D_007105E8, 0x163);
    }
    flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
    if (!flag) {
        *(s32*)(arg0 + 0x24) = hi - 1;
        *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x20) - hi;
        goto ret1;
    }
    return 0;
ret1:
    return 1;
}


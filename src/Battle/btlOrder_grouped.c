/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct BtlAction BtlAction;
extern s32 iGpffffb3ac;
extern u8 *D_0076449C;

/* Canonical grouped function declarations. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action);

/* Source unit: src/Battle/btlOrder_001b0d00.c */

// FUN_001B0D00
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action)
{
    BtlAction* curr;
    s32 i;

    for (i = 0; i < arrSize; i++)
    {
        curr = *actions;
        if (curr != action)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (i == arrSize)
    {
        return 0;
    }

    for (; i < arrSize - 1; i++)
    {
        *actions = *(actions + 1);
        actions++;
    }

    *actions = NULL;

    return 1;
}

// FUN_001B0D70
s32 func_001b0d70(u8 *arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = (s32)arg0;
    return 1;
}
/* Same-TU helper knowledge preserves a2/a3/t0 across removal calls.
   Measured: object 84B/window 96B, no instruction differences; 12B zero tail. */
// FUN_001B0DD0
s32 func_001b0dd0(u8 *arg0)
{
    BtlAction **actions;
    s32 result;

    actions = (BtlAction **)((u8 *)iGpffffb3ac + 0x29C);
    result = 0;
    while (btlOrderRemoveAction(actions, 0xC, (BtlAction *)arg0) == 1) {
        result = 1;
    }
    return result;
}
// FUN_001B0E30
s32 func_001b0e30(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x2CC);
    i = 0;
    goto check;
loop:
    if (*p == 0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto store;
    }
    return 0;
store:
    *p = arg0;
    return 1;
}
/* measured: opt_rebuildconditionals off probe for 0e90 guard polarity. */
#pragma opt_rebuildconditionals off
// FUN_001B0E90
s32 func_001b0e90(u8 *arg0)
{
    s32 temp;
    u8 *p;

    if (*(u8 *)(arg0 + 0x28) != 0) {
        goto ret1;
    }
    if (*(u8 *)(arg0 + 0x29) == 0) {
        goto check;
    }
ret1:
    return 1;
check:
    p = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(p + 0xC) & 8) == 0) {
        return 1;
    }
    if ((*(u16 *)(arg0 + 0x18) & 4) == 0) {
        temp = *(s32 *)(p + 0x2CC);
        if ((temp != 0) && ((u8 *)temp == arg0)) {
            return 1;
        }
    }
    return *(s32 *)(p + 0x2A0) == (s32)arg0;
}
/* measured: close opt_rebuildconditionals off for func_001b0e90. */
#pragma opt_rebuildconditionals on
// FUN_001B0F20
s32 func_001b0f20(s32 arg0)
{
    s32 *p;
    u32 i;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto shift;
    }
    return 0;
shift:
    while ((s32)i > 0) {
        *p = *(p - 1);
        p--;
        i--;
    }
    *p = arg0;
    return 1;
}
// FUN_001B0FA0
s32 func_001b0fa0(u8 *arg0)
{
    s32 *p;
    u32 i;
    s32 temp;

    p = (s32 *)(D_0076449C + 0x29C);
    i = 0;
    goto check;
loop:
    if (*p == (s32)arg0) {
        goto after;
    }
    p++;
    i++;
check:
    if (i < 0xC) {
        goto loop;
    }
after:
    if (i != 0xC) {
        goto limit;
    }
    return 0;
compact:
    temp = *(p + 1);
    if (temp == 0) {
        goto store;
    }
    *p = temp;
    p++;
    i++;
limit:
    if (i < 0xB) {
        goto compact;
    }
store:
    *p = (s32)arg0;
    return 1;
}
// FUN_001B1020
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b1020);
/* Best faithful probe: docs/probe_archive/F1B0_001b11c0_body.c.
   Object/window 192B/192B; five differing words swap the key/index registers. */
// FUN_001B11C0
INCLUDE_ASM("asm/nonmatchings/code1_001b", func_001b11c0);
// FUN_001B1280
void func_001b1280(s32 arg0)
{
    u8 *base;
    u8 **scan;
    u8 *obj;
    u8 **start;
    s32 key;
    u32 i;
    s32 count;
    s32 reverse_count;
    u32 j;

    key = arg0 & 0xFFFF;
    if (key != 1) {
        return;
    }
    base = D_0076449C;
    scan = (u8 **)(base + 0x29C);
    for (count = 0, i = 0; i < 0xCU; i++) {
        obj = *scan;
        if (obj == NULL) {
            break;
        }
        if ((*(u8 *)(*(u8 **)(obj + 0x30) + 0xA2) != key)) {
            break;
        }
        count++;
        scan++;
    }
    reverse_count = 2;
    switch (count) {
    case 5:
        reverse_count = 2;
        break;
    case 4:
        reverse_count = 2;
        break;
    case 3:
        reverse_count = 1;
        break;
    case 2:
        reverse_count = 1;
        break;
    case 1:
    default:
        return;
    }
    start = (u8 **)(base + (count - 1) * 4 + 0x29C);
    for (j = 0; j < (u32)reverse_count; j++) {
        func_001b0fa0(*start);
        start--;
    }
}
/* Auto-inlining preserves the externally called 13c0 body as well as its
   expansion in 1450. Plain inline drops that required standalone symbol.
   Measured: 13c0 132B/144B, 1450 188B/192B; only retail zero tails remain. */
#pragma auto_inline on
// FUN_001B13C0
void func_001b13c0(u8 *arg0)
{
    u8 *ptr;
    u8 *global;

    ptr = arg0;
    if ((*(u16 *)(ptr + 0x18) & 4) != 0) {
        btlOrderRemoveAction((BtlAction **)((u8 *)iGpffffb3ac + 0x2CC), 0xC, (BtlAction *)ptr);
        *(u16 *)(ptr + 0x18) &= 0xFFFB;
        goto done;
    }
    global = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(global + 0xC) & 8) != 0) {
        *(u8 **)(global + 0x298) = ptr;
        func_001b0fa0(ptr);
    }
done:
    global = (u8 *)iGpffffb3ac;
    *(u16 *)(global + 0x290) |= 8;
}
// FUN_001B1450
void func_001b1450(u8 *arg0)
{
    u8 *global;
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        func_001b13c0(arg0);
    } else {
        global = (u8 *)iGpffffb3ac;
        if ((*(s32 *)(global + 0xC) & 8) != 0) {
            *(u8 **)(global + 0x298) = arg0;
        }
        global = (u8 *)iGpffffb3ac;
        *(u16 *)(global + 0x290) |= 8;
    }
}
#pragma auto_inline off

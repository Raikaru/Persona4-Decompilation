/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u16 func_00231ed0(int unit);
u16 func_00231ee0(int unit);
void func_00231f20(int unit, u16 hp);
void func_00231f50(int unit, u16 sp);
u32 func_00232680(int unit, u32 badStatus);
u32 func_002326c0(int unit);
u32 func_002326e0(int unit);
u32 func_002326f0(int unit, u32 badStatus);
u32 func_00232710(int unit, u32 badStatus);
void func_00233bb0(int object);
u32 func_0023e130(void);
u32 func_002428f0(int unit, s32 hpDelta);

/* Source unit: src/datCalc/datCalc_00231ed0.c (1 function markers) */

// FUN_00231ED0
u16 func_00231ed0(int unit)
{
    return *(u16*)(unit + 8);
}

/* Source unit: src/datCalc/datCalc_00231ee0.c (1 function markers) */

// FUN_00231EE0
u16 func_00231ee0(int unit)
{
    return *(u16*)(unit + 0xa);
}

/* Source unit: src/datCalc/datCalc_00231f20.c (1 function markers) */

// FUN_00231F20
void func_00231f20(int unit, u16 hp)
{
    if (hp > 999 && !(*(u16*)unit & 4))
    {
        hp = 999;
    }

    *(u16*)(unit + 8) = hp;
}

/* Source unit: src/datCalc/datCalc_00231f50.c (1 function markers) */

// FUN_00231F50
void func_00231f50(int unit, u16 sp)
{
    if (sp > 999 && !(*(u16*)unit & 4))
    {
        sp = 999;
    }

    *(u16*)(unit + 0xa) = sp;
}

/* Source unit: src/datCalc/datCalc_00232680.c (1 function markers) */

// FUN_00232680
u32 func_00232680(int unit, u32 badStatus)
{
    u32 low;

    low = badStatus & 0x000fffff;
    if (low != 0)
    {
        *(u32*)(unit + 0xc) = (*(u32*)(unit + 0xc) & 0xfff00000) | low;
    }

    return *(u32*)(unit + 0xc) |= badStatus & 0xfff00000;
}

/* Source unit: src/datCalc/datCalc_002326c0.c (1 function markers) */

// FUN_002326C0
u32 func_002326c0(int unit)
{
    return *(u32*)(unit + 0xc) & 0x000fffff;
}

/* Source unit: src/datCalc/datCalc_002326e0.c (1 function markers) */

// FUN_002326E0
u32 func_002326e0(int unit)
{
    return *(u32*)(unit + 0xc);
}

/* Source unit: src/datCalc/datCalc_002326f0.c (1 function markers) */

// FUN_002326F0
u32 func_002326f0(int unit, u32 badStatus)
{
    return *(u32*)(unit + 0xc) &= ~badStatus;
}

/* Source unit: src/datCalc/datCalc_00232710.c (1 function markers) */

// FUN_00232710
u32 func_00232710(int unit, u32 badStatus)
{
    return (*(u32*)(unit + 0xc) & badStatus) != 0;
}

/* Source unit: src/datCalc/datCalc_00233bb0.c (1 function markers) */

// FUN_00233BB0
void func_00233bb0(int object)
{
    *(u32*)(object + 0x18) = 0;
}

/* Source unit: src/datCalc/datCalc_0023df20.c (1 function markers) */

// FUN_0023DF20
u32 datCalcIsSpecialItem(u16 itemId)
{
    u32 result;

    switch (itemId)
    {
    case 0xc0:
    case 0xc1:
    case 0xc2:
    case 0xc3:
    case 0xc4:
    case 0xc5:
        result = 1;
        break;
    default:
        result = 0;
    }

    return result;
}

/* Source unit: src/datCalc/datCalc_0023e130.c (1 function markers) */

// FUN_0023E130
u32 func_0023e130(void)
{
    return 8;
}

/* Source unit: src/datCalc/datCalc_002428f0.c (1 function markers) */

// FUN_002428F0
u32 func_002428f0(int unit, s32 hpDelta)
{
    if (*(u32*)(unit + 0xc) & 0x80000 ? 1 : 0)
    {
        return 1;
    }

    return (*(u16*)(unit + 8) + hpDelta) <= 0;
}

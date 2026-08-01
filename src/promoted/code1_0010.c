/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00100220)
#include "type.h"

// FUN_00100220
asm void func_00100220(void)
{
    addiu $3, $0, 0x23
    syscall 0
}
#endif /* P4_UNIT_00100220 */

#if defined(P4_UNIT_00102980)
#include "type.h"

extern u8 *D_00764298;

// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}
#endif /* P4_UNIT_00102980 */

#if defined(P4_UNIT_00105330)
#include "type.h"

extern s16 D_00797F88[];

// FUN_00105330
s16 func_00105330(void)
{
    return D_00797F88[0];
}
#endif /* P4_UNIT_00105330 */

#if defined(P4_UNIT_00105ED0)
#include "type.h"

extern u32 D_0079B68C[];

// FUN_00105ED0
u32 func_00105ed0(void)
{
    return D_0079B68C[0];
}
#endif /* P4_UNIT_00105ED0 */

#if defined(P4_UNIT_001060B0)
#include "type.h"

extern s16 D_00797B7A[];

// FUN_001060B0
s16 func_001060b0(void)
{
    return D_00797B7A[0];
}
#endif /* P4_UNIT_001060B0 */

#if defined(P4_UNIT_001060C0)
#include "type.h"

extern u8 D_00797B7C[];

// FUN_001060C0
u8 func_001060c0(void)
{
    return D_00797B7C[0];
}
#endif /* P4_UNIT_001060C0 */

#if defined(P4_UNIT_001060D0)
#include "type.h"

extern s16 D_00797B84[];

// FUN_001060D0
s16 func_001060d0(void)
{
    return D_00797B84[0];
}
#endif /* P4_UNIT_001060D0 */

#if defined(P4_UNIT_001060E0)
#include "type.h"

extern u8 D_00797B86[];

// FUN_001060E0
u8 func_001060e0(void)
{
    return D_00797B86[0];
}
#endif /* P4_UNIT_001060E0 */

#if defined(P4_UNIT_00106B80)
#include "type.h"

// FUN_00106B80
s64 func_00106b80(s64 arg0)
{
    s16 temp_2;

    temp_2 = (s16)arg0;
    if (temp_2 < 0x100) {
        return temp_2;
    }
    if (temp_2 < 0x200) {
        return (s16)(temp_2 - 0x100);
    }
    if (temp_2 < 0x300) {
        return (s16)(temp_2 - 0x200);
    }
    if (temp_2 < 0x400) {
        return (s16)(temp_2 - 0x300);
    }
    if (temp_2 < 0x500) {
        return (s16)(temp_2 - 0x400);
    }
    return (s16)(temp_2 - 0x500);
}
#endif /* P4_UNIT_00106B80 */

/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004C3400)
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3
// FUN_004C3400
u32 func_004c3400(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x4C3C) = arg0;
    return segment;
}
#endif /* P4_UNIT_004C3400 */

#if defined(P4_UNIT_004C3410)
#include "type.h"

/* measured: retail unit compiled with scheduling on (load in jr $ra delay
   slot); -O3 reproduces the schedule; residual is the lui/lw base register. */
#pragma optimization_level 3
// FUN_004C3410 NONMATCHING
u32 func_004c3410(void)
{
    u32 segment = 0x00710000;

    return *(u32 *)(segment + 0x4C3C);
}
#endif /* P4_UNIT_004C3410 */

#if defined(P4_UNIT_004C9BD0)
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3
// FUN_004C9BD0
u32 func_004c9bd0(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x65F0) = arg0;
    return segment;
}
#endif /* P4_UNIT_004C9BD0 */

#if defined(P4_UNIT_004CA648)
#include "type.h"

extern s32 D_00758688[];

/* measured: retail unit compiled with scheduling on (addiu in jr $ra delay
   slot); -O3 reproduces it; -O2 emits addiu, jr, nop. */
#pragma optimization_level 3
// FUN_004CA648
s32 *func_004ca648(void)
{
    return D_00758688;
}
#endif /* P4_UNIT_004CA648 */

#if defined(P4_UNIT_004CA658)
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3
// FUN_004CA658
u32 func_004ca658(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x7754) = arg0;
    return segment;
}
#endif /* P4_UNIT_004CA658 */

#if defined(P4_UNIT_004CB2C0)
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3
// FUN_004CB2C0
u32 func_004cb2c0(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x6680) = arg0;
    return segment;
}
#endif /* P4_UNIT_004CB2C0 */

#if defined(P4_UNIT_004CC1E0)
#include "type.h"

/* measured: retail unit compiled with scheduling on (load in jr $ra delay
   slot); -O3 reproduces the schedule; residual is the lui/lw base register. */
#pragma optimization_level 3
// FUN_004CC1E0 NONMATCHING
u32 func_004cc1e0(void)
{
    u32 segment = 0x00710000;

    return *(u32 *)(segment + 0x9998);
}
#endif /* P4_UNIT_004CC1E0 */

#if defined(P4_UNIT_004CF7E0)
#include "type.h"

/* measured: retail unit compiled with scheduling on (second sh in jr $ra
   delay slot); -O3 reproduces it; -O2 emits sh, sh, jr, nop. */
#pragma optimization_level 3
// FUN_004CF7E0
void func_004cf7e0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}
#endif /* P4_UNIT_004CF7E0 */

#if defined(P4_UNIT_004CF9C0)
#include "type.h"

/* measured: retail unit compiled with scheduling on (second sh in jr $ra
   delay slot); -O3 reproduces it; -O2 emits sh, sh, jr, nop. */
#pragma optimization_level 3
// FUN_004CF9C0
void func_004cf9c0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}
#endif /* P4_UNIT_004CF9C0 */

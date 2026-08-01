/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00185120)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00185120 */

#if defined(P4_UNIT_00186610)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00186610 */

#if defined(P4_UNIT_00186C90)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00186C90
void func_00186c90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00186C90 */

#if defined(P4_UNIT_00188EF0)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00188EF0
void func_00188ef0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00188EF0 */

#if defined(P4_UNIT_00189520)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00189520
void func_00189520(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00189520 */

#if defined(P4_UNIT_00189E90)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00189E90 */

#if defined(P4_UNIT_0018C550)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_0018C550
void func_0018c550(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0018C550 */

#if defined(P4_UNIT_0018DF30)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0018DF30 */

#if defined(P4_UNIT_0018E030)
#include "type.h"

extern s32 D_0076428C;

// FUN_0018E030
void func_0018e030(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}
#endif /* P4_UNIT_0018E030 */

#if defined(P4_UNIT_0018E450)
#include "type.h"

void func_0018e780(s32 arg0);

// FUN_0018E450
s32 func_0018e450(u8 *arg0)
{
    s32 *p;
    s32 state;

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
        func_0018e780(0);
        *p += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}
#endif /* P4_UNIT_0018E450 */

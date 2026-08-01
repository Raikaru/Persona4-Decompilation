/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004688D0)
#include "type.h"

extern void strcpy(s8 *arg0, s32 *arg1);
extern void func_00452080(u8 *arg0);

// FUN_004688D0
s32 func_004688d0(u8 *arg0, s8 *arg1)
{
    s32 *temp_16 = *(s32 **)(arg0 + 0x38);

    strcpy(arg1, (s32 *)((u8 *)temp_16 + 0x10));
    if (*temp_16 == 2) {
        func_00452080(arg0);
        return 1;
    }
    return 0;
}
#endif /* P4_UNIT_004688D0 */

#if defined(P4_UNIT_0046AB40)
#include "type.h"

extern void func_0046ab90(u8 *arg0);
extern u8 *D_00724C08;

// FUN_0046AB40
void func_0046ab40(void)
{
    u8 *var_16 = D_00724C08;

loop_1:
    if (var_16 != NULL) {
        func_0046ab90(var_16);
        var_16 = *(u8 **)(var_16 + 0x238);
        goto loop_1;
    }
}
#endif /* P4_UNIT_0046AB40 */

#if defined(P4_UNIT_00460A50)
#include "type.h"

extern void (*jtbl_008873FC[])(s32, s32);
extern s32 D_00724B8C;

// FUN_00460A50
void func_00460a50(s32 arg0)
{
    jtbl_008873FC[0](D_00724B8C, arg0);
}
#endif /* P4_UNIT_00460A50 */

#if defined(P4_UNIT_0046D6B0)
#include "type.h"

extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;

// FUN_0046D6B0
void func_0046d6b0(s32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}
#endif /* P4_UNIT_0046D6B0 */

#if defined(P4_UNIT_00460990)
#include "type.h"

extern u8 *(*D_008873F8[])(s32, s32);
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B88;

// FUN_00460990
u8 *func_00460990(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B88, 0x41002);

    memset(temp_2, 0, 0x30);
    return temp_2;
}
#endif /* P4_UNIT_00460990 */

#if defined(P4_UNIT_004609F0)
#include "type.h"

extern u8 *(*D_008873F8[])(s32, s32);
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B8C;

// FUN_004609F0
u8 *func_004609f0(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B8C, 0x41003);

    memset(temp_2, 0, 0x30);
    return temp_2;
}
#endif /* P4_UNIT_004609F0 */

#if defined(P4_UNIT_0046A2D0)
#include "type.h"

extern s32 D_00724BEC;
extern s32 D_00724BF0;

// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}
#endif /* P4_UNIT_0046A2D0 */

#if defined(P4_UNIT_00460A80)
#include "type.h"

extern void memset(void *dst, s32 value, s32 size);
extern void func_00452730(s32 arg0);
extern s32 D_00724B88;

// FUN_00460A80
void func_00460a80(s32 arg0, s32 arg1)
{
    memset((void *)arg0, 0, arg1 * 0x30);
    func_00452730(D_00724B88);
}
#endif /* P4_UNIT_00460A80 */

#if defined(P4_UNIT_00467290)
#include "type.h"

extern void (*jtbl_008873EC[])(s32);

// FUN_00467290
void func_00467290(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}
#endif /* P4_UNIT_00467290 */

#if defined(P4_UNIT_004680C0)
#include "type.h"

extern void (*jtbl_008873EC[])(s32);

// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}
#endif /* P4_UNIT_004680C0 */

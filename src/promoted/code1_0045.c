/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00451CA0)
#include "type.h"

extern s32 func_003e1220(u32 a0, u32 a1, u32 a2, u32 a3, void* a4, u32 a5);
/* GP-relative scalar at gp -0x45E8 (absolute 0x00764B08). */
extern s32 iGpffffba18;
extern u32 D_008BFFB0[];

// FUN_00451CA0
void func_00451ca0(s32 arg0)
{
    iGpffffba18 = func_003e1220(0x54, arg0, 4, 1, D_008BFFB0, 0x41001);
}
#endif /* P4_UNIT_00451CA0 */

#if defined(P4_UNIT_004526F0)
#include "type.h"

extern void (*D_008873FC[])(s32 param, u8* arg);

// FUN_004526F0
void func_004526f0(u8* arg0, s32 arg1)
{
    (*D_008873FC)(arg1, arg0);
}
#endif /* P4_UNIT_004526F0 */

#if defined(P4_UNIT_00453CE0)
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern s32 func_00453eb0(u8* obj, s32 value);
extern u32 D_007105E8[];

// FUN_00453CE0
void func_00453ce0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0xF4);
    }
    if (arg1 < *(s32*)(arg0 + 0x20)) {
        *(s32*)(arg0 + 0x20) = arg1;
        func_00453eb0(arg0, *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24));
        return;
    }
    *(s32*)(arg0 + 0x20) = arg1;
}
#endif /* P4_UNIT_00453CE0 */

#if defined(P4_UNIT_00453D70)
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern u32 D_007105E8[];

// FUN_00453D70
s32 func_00453d70(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x101);
    }
    return *(s32*)(arg0 + 0x28);
}
#endif /* P4_UNIT_00453D70 */

#if defined(P4_UNIT_00453DC0)
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern u32 D_007105E8[];

// FUN_00453DC0
s32 func_00453dc0(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x108);
    }
    return *(s32*)(arg0 + 0x24);
}
#endif /* P4_UNIT_00453DC0 */

#if defined(P4_UNIT_00453E10)
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern u32 D_007105E8[];

// FUN_00453E10
s32 func_00453e10(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x10F);
    }
    return *(s32*)(arg0 + 0x20);
}
#endif /* P4_UNIT_00453E10 */

#if defined(P4_UNIT_00453E60)
#include "type.h"

extern void func_0046d730(void* message, u32 code);
extern u32 D_007105E8[];

// FUN_00453E60
s32 func_00453e60(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x116);
    }
    return *(s32*)(arg0 + 0x14);
}
#endif /* P4_UNIT_00453E60 */

#if defined(P4_UNIT_004556B0)
#include "type.h"

// FUN_004556B0
s32 func_004556b0(u8* arg0, u32 arg1)
{
    if (arg1 < *(u32*)(arg0 + 4)) {
        return (s32)(*(u8**)(arg0 + 0x58) + arg1 * 0x110);
    }
    return 0;
}
#endif /* P4_UNIT_004556B0 */

#if defined(P4_UNIT_00459760)
#include "type.h"

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}
#endif /* P4_UNIT_00459760 */

#if defined(P4_UNIT_0045B400)
#include "type.h"

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];

// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}
#endif /* P4_UNIT_0045B400 */

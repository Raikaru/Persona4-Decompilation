/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00354230)
#include "type.h"

extern void func_002bb550(s8 arg0);
extern void (*D_008873EC[])(...);

// FUN_00354230
void func_00354230(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002bb550(*(s8 *)(temp_16 + 8));
    (*D_008873EC)(temp_16);
}
#endif /* P4_UNIT_00354230 */

#if defined(P4_UNIT_003547C0)
#include "type.h"

extern void func_003549d0(void);
extern void func_00442de8(void *dst, const void *src, u32 size);

// FUN_003547C0
void func_003547c0(s32 *arg0, u8 *arg1)
{
    func_003549d0();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    func_00442de8((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}
#endif /* P4_UNIT_003547C0 */

#if defined(P4_UNIT_00355370)
#include "type.h"

// FUN_00355370
void func_00355370(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(temp_4 + 0x38) = 0x3F800000;
        *(u32 *)(temp_4 + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(temp_4 + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(temp_4 + 0x3C) = *(f32 *)(arg1 + 4);
    }
}
#endif /* P4_UNIT_00355370 */

#if defined(P4_UNIT_003553B0)
#include "type.h"

extern void func_0046d730(const void *module, u32 line);
extern u32 D_0064B310[];

// FUN_003553B0
void func_003553b0(u8 *arg0, f32 *arg1)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(temp_16 + 0x38);
    arg1[1] = *(f32 *)(temp_16 + 0x3C);
}
#endif /* P4_UNIT_003553B0 */

#if defined(P4_UNIT_00356140)
#include "type.h"

extern void (*D_008873EC[])(...);

// FUN_00356140
void func_00356140(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00356140 */

#if defined(P4_UNIT_003593B0)
#include "type.h"

// FUN_003593B0
void func_003593b0(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}
#endif /* P4_UNIT_003593B0 */

#if defined(P4_UNIT_003599A0)
#include "type.h"

extern f32 D_00761260;

// FUN_003599A0
void func_003599a0(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}
#endif /* P4_UNIT_003599A0 */

#if defined(P4_UNIT_0035AF10)
#include "type.h"

extern void func_003549d0(u8 *arg0);
extern void (*D_008873EC[])(...);

// FUN_0035AF10
void func_0035af10(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}
#endif /* P4_UNIT_0035AF10 */

#if defined(P4_UNIT_0035BEC0)
#include "type.h"

extern void func_003549d0(u8 *arg0);
extern void (*D_008873EC[])(...);

// FUN_0035BEC0
void func_0035bec0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}
#endif /* P4_UNIT_0035BEC0 */

#if defined(P4_UNIT_0035C670)
#include "type.h"

typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;

// FUN_0035C670
void func_0035c670(u8 *arg0, f32 *arg1)
{
    *(Float2 *)arg1 = *(Float2 *)(*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0035C670 */

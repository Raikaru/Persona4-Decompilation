/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00121170)
#include "type.h"

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

// FUN_00121170
void func_00121170(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}
#endif /* P4_UNIT_00121170 */

#if defined(P4_UNIT_00121660)
#include "type.h"

extern s32 D_007242B4;
extern void (*jtbl_008873EC[])(void *);

// FUN_00121660
void func_00121660(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B4 = 0;
    jtbl_008873EC[0](p);
}
#endif /* P4_UNIT_00121660 */

#if defined(P4_UNIT_00122A10)
#include "type.h"

extern s32 D_007242CC;
extern void (*jtbl_008873EC[])(void *);

// FUN_00122A10
void func_00122a10(void *arg0)
{
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
    D_007242CC = 0;
}
#endif /* P4_UNIT_00122A10 */

#if defined(P4_UNIT_00123810)
#include "type.h"

extern u8 *D_007242CC;

// FUN_00123810
s16 func_00123810(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 6);
    }
    return var_2;
}
#endif /* P4_UNIT_00123810 */

#if defined(P4_UNIT_00123830)
#include "type.h"

extern u8 *D_007242CC;

// FUN_00123830
s16 func_00123830(void)
{
    s16 var_2;
    u8 *temp_3;

    var_2 = 0;
    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        var_2 = *(s16 *)(temp_3 + 4);
    }
    return var_2;
}
#endif /* P4_UNIT_00123830 */

#if defined(P4_UNIT_00122820)
#include "type.h"

extern void func_00264d90();
extern s32 D_00796670[];

// FUN_00122820
void func_00122820(s32 arg0, s32 arg1)
{
    func_00264d90(0, arg0, arg1, D_00796670);
}
#endif /* P4_UNIT_00122820 */

#if defined(P4_UNIT_00122860)
#include "type.h"

extern void func_00267570();
extern s32 D_00796670[];

// FUN_00122860
void func_00122860(s32 arg0, s32 arg1)
{
    func_00267570(0, arg0, arg1, D_00796670);
}
#endif /* P4_UNIT_00122860 */

#if defined(P4_UNIT_00123A80)
#include "type.h"

extern u8 *D_007242CC;

// FUN_00123A80
void func_00123a80(void)
{
    u8 *temp_3;

    temp_3 = D_007242CC;
    if (temp_3 != NULL) {
        *(s32 *)(temp_3 + 0x14) = 0;
        *(s32 *)(temp_3 + 0xC) = 0;
    }
}
#endif /* P4_UNIT_00123A80 */

#if defined(P4_UNIT_0012B810)
#include "type.h"

typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

// FUN_0012B810
s32 func_0012b810(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(func_00452560(arg0));
    if (temp_2->field_18 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_18;
}
#endif /* P4_UNIT_0012B810 */

#if defined(P4_UNIT_0012C1A0)
#include "type.h"

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;

extern s32 func_00452490();
extern void *func_00452560();
extern void func_00452080();

// FUN_0012C1A0
s32 func_0012c1a0(s32 arg0)
{
    C1A0Obj *temp_2;

    if ((arg0 == 0) || (func_00452490() == 0)) {
        return -1;
    }
    temp_2 = (C1A0Obj *)(func_00452560(arg0));
    if (temp_2->field_4 != 0) {
        func_00452080(arg0);
    }
    return temp_2->field_4;
}
#endif /* P4_UNIT_0012C1A0 */

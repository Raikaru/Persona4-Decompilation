/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00201280)
#include "type.h"

extern void func_00213ab0();
extern void func_0021ae60(u8 *arg0, u8 *arg1);

// FUN_00201280
void func_00201280(u8 *arg0, u8 *arg1) {
    func_00213ab0();
    func_0021ae60(arg0, arg1 + 0x18);
}
#endif /* P4_UNIT_00201280 */

#if defined(P4_UNIT_00202C60)
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);
extern void func_00202e00(u8 *arg0, s16 *arg1);

// FUN_00202C60
void func_00202c60(u8 *arg0, s16 arg1, s16 arg2, void *arg3, void *arg4, void *arg5, void *arg6, u8 *arg7) {
    memset(arg0, 0, 0x34);
    *(s16 *)(arg0 + 6) = arg1;
    *(s16 *)(arg0 + 8) = arg2;
    *(void **)(arg0 + 0xC) = arg3;
    *(void **)(arg0 + 0x10) = arg4;
    *(void **)(arg0 + 0x14) = arg5;
    *(void **)(arg0 + 0x1C) = arg6;
    *(u8 **)(arg0 + 0x28) = arg7;
    *(u16 *)(arg0 + 0) |= 8;
    func_00202e00(arg0, NULL);
}
#endif /* P4_UNIT_00202C60 */

#if defined(P4_UNIT_00203360)
#include "type.h"

// FUN_00203360
void func_00203360(u8 *arg0, u8 *arg1) {
    u8 *temp_16;
    u8 *var_4;

    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(u8 **)(arg0 + 0xC) = arg1;
    *(u8 **)(arg0 + 8) = arg1;
    var_4 = arg1;
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0xC))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
}
#endif /* P4_UNIT_00203360 */

#if defined(P4_UNIT_002033C0)
#include "type.h"

// FUN_002033C0
void func_002033c0(u8 *arg0) {
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(arg0 + 8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0x1C))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
    *(u8 **)(arg0 + 8) = NULL;
}
#endif /* P4_UNIT_002033C0 */

#if defined(P4_UNIT_002035A0)
#include "type.h"

// FUN_002035A0
void func_002035a0(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        (*(void (**)(u8 *, s32, u8 *))(var_16 + 0x14))(var_16, *(s32 *)(var_16 + 0x28), arg0);
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}
#endif /* P4_UNIT_002035A0 */

#if defined(P4_UNIT_00203600)
#include "type.h"

// FUN_00203600
void func_00203600(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        void (*fn)(u8 *, s32, u8 *) = *(void (**)(u8 *, s32, u8 *))(var_16 + 0x18);
        if (fn != NULL) {
            fn(var_16, *(s32 *)(var_16 + 0x28), arg0);
        }
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}
#endif /* P4_UNIT_00203600 */

#if defined(P4_UNIT_0020AD80)
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);

// FUN_0020AD80
void func_0020ad80(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x5B4);
    *(s32 *)(arg0 + 0x5B0) = arg1;
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 0x5AC) = -1;
}
#endif /* P4_UNIT_0020AD80 */

#if defined(P4_UNIT_0020BB20)
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);

// FUN_0020BB20
void func_0020bb20(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x1C);
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 2) = 3;
}
#endif /* P4_UNIT_0020BB20 */

#if defined(P4_UNIT_0020E1D0)
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

// FUN_0020E1D0
void func_0020e1d0(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 3;
    *(u16 *)(arg0 + 0x10) &= 0xFFFE;
    *(u16 *)(arg0 + 0x10) &= 0xFFFD;
    *(s16 *)(arg1 + 4) = 0;
    *(s16 *)(arg1 + 2) = 2;
    *(u16 *)(arg1 + 0x10) &= 0xFFF7;
    *(u16 *)(arg1 + 0x10) &= 0xFFFB;
    *(u16 *)(arg1 + 0x10) &= 0xFFFD;
    *(u16 *)(arg1 + 0x10) |= 1;
    *(Vec2f *)(arg1 + 8) = *(Vec2f *)(arg0 + 8);
}
#endif /* P4_UNIT_0020E1D0 */

#if defined(P4_UNIT_0020E3F0)
#include "type.h"

extern u8 *func_00452560();
extern void func_002119a0(u8 *arg0);

// FUN_0020E3F0
void func_0020e3f0(void) {
    func_002119a0(func_00452560() + 0x75C);
}
#endif /* P4_UNIT_0020E3F0 */

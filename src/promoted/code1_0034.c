/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00348130)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00348130
void func_00348130(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00348130 */

#if defined(P4_UNIT_00349260)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00349260
void func_00349260(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00349260 */

#if defined(P4_UNIT_00349380)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_00349380
void func_00349380(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00349380 */

#if defined(P4_UNIT_0034AD40)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_0034AD40
void func_0034ad40(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0034AD40 */

#if defined(P4_UNIT_0034B710)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_0034B710
void func_0034b710(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0034B710 */

#if defined(P4_UNIT_0034C120)
#include "type.h"

// FUN_0034C120
void func_0034c120(u8 *arg0) {
    f32 temp_f2 = *(f32 *)(arg0 + 8);

    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 0) += 640.0f;
        *(f32 *)(arg0 + 0x18) += 640.0f;
    } else if (!(temp_f2 < 640.0f)) {
        *(f32 *)(arg0 + 0) -= 640.0f;
        *(f32 *)(arg0 + 0x18) -= 640.0f;
    }
    temp_f2 = *(f32 *)(arg0 + 0xC);
    if (temp_f2 < 0.0f) {
        *(f32 *)(arg0 + 4) += 448.0f;
        *(f32 *)(arg0 + 0x1C) += 448.0f;
        return;
    }
    if (!(temp_f2 < 448.0f)) {
        *(f32 *)(arg0 + 4) -= 448.0f;
        *(f32 *)(arg0 + 0x1C) -= 448.0f;
    }
}
#endif /* P4_UNIT_0034C120 */

#if defined(P4_UNIT_0034C820)
#include "type.h"

extern void (*D_00887310[])(s32, void *, s32);

// FUN_0034C820
void func_0034c820(u8 *arg0) {
    D_00887310[0](5, arg0, 4);
}
#endif /* P4_UNIT_0034C820 */

#if defined(P4_UNIT_0034D040)
#include "type.h"

void func_0034e0b0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);

// FUN_0034D040
void func_0034d040(u8 *arg0) {
    func_0034e0b0(arg0, 0.0f, 0.0f, 1.0f);
}
#endif /* P4_UNIT_0034D040 */

#if defined(P4_UNIT_0034F2E0)
#include "type.h"

void func_0034f320(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, s16 arg5,
                   s16 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0);

// FUN_0034F2E0
void func_0034f2e0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, f32 fparg0,
                   f32 fparg1) {
    func_0034f320(arg0, arg1, arg2, arg3, arg4, 0x1000, 0x1000, 0, fparg0,
                  fparg1, 0.0f, 0.0f, 0);
}
#endif /* P4_UNIT_0034F2E0 */

#if defined(P4_UNIT_0034F460)
#include "type.h"

void func_0034f4a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   s64 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8);

// FUN_0034F460
void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   f32 fparg0, f32 fparg1) {
    func_0034f4a0(arg0, arg1, arg2, arg3, arg4, arg5, 0x1000, 0x1000, fparg0,
                  fparg1, 0.0f, 0.0f, 0, 0);
}
#endif /* P4_UNIT_0034F460 */

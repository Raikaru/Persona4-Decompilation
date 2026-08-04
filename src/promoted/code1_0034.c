#include "type.h"

extern void (*jtbl_008873EC[])(void *);

void func_0034f320(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, s16 arg5,
                   s16 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0);

void func_0034f4a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   s64 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8);



// FUN_00349380
void func_00349380(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0034AD40
void func_0034ad40(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0034B8C0
void func_0034b8c0(void)
{
}

// FUN_0034F2E0
void func_0034f2e0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, f32 fparg0,
                   f32 fparg1) {
    func_0034f320(arg0, arg1, arg2, arg3, arg4, 0x1000, 0x1000, 0, fparg0,
                  fparg1, 0.0f, 0.0f, 0);
}



// FUN_0034F460
void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   f32 fparg0, f32 fparg1) {
    func_0034f4a0(arg0, arg1, arg2, arg3, arg4, arg5, 0x1000, 0x1000, fparg0,
                  fparg1, 0.0f, 0.0f, 0, 0);
}

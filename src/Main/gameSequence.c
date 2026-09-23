/* Whole-file translation unit: src/Main/gameSequence.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "sdk_task_registration.h"

extern void func_0046a2d0(const void *file, u32 line);
extern s32 H_Calloc(s32, s32);

extern void func_0046d730(const void *file, u32 line);
extern s32 func_00452380(void *path);
extern void func_00452080(s32 handle);
extern char D_005E51C0[];
extern char D_005E51D0[];
extern void func_00123a80(void);
extern s32 func_00123e80(u8 *task);
extern void func_00124210(u8 *task);

// FUN_00124240
void func_00124240(void)
{
    s32 temp_2;

    func_0046a2d0(D_005E51C0, 0x178);
    temp_2 = H_Calloc(1, 0x10);
    if (temp_2 != 0) {
        (s32)func_00451de0((const void *)(D_005E51D0), 0x100, 0, 0, func_00123e80, func_00124210, (u8 *)(temp_2));
        func_00123a80();
    }
}

// FUN_001242C0
s32 func_001242c0(void)
{
    return (s32)(func_00452380(D_005E51D0) != 0);
}

// FUN_001242F0
void func_001242f0(void)
{
    s32 temp_2;

    temp_2 = func_00452380(D_005E51D0);
    if (temp_2 == 0) {
        func_0046d730(D_005E51C0, 0x1CC);
    }
    func_00452080(temp_2);
}

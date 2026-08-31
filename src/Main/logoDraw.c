#include "include_asm.h"
/* Source unit: src/Main/logoDraw_0012bbb0.c */
#include "type.h"


extern void func_00440b68(...);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, u32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00454bd0(void *handle);
extern s32 func_004553c0(void *handle);
extern s32 func_00451de0();
extern s32 func_00452490(s32);
extern void func_00452080(s32 handle);
extern s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void func_00122520(s32, s32);
extern void func_00122640(s32, s32);
extern s32 func_00122720(void);
extern void func_0012b890(void);
extern void func_0012b940(void);
extern void func_0012b9a0(void);
extern void *func_00452560();
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(s32, s32, u32);

extern char D_00762D88;
extern char D_00762D98;
extern char D_005E5730[];
extern char D_005E5760[];
extern char D_005E5770[];
extern char D_005E5790[];
extern char D_005E57A8[];
extern char D_00795E60[];
extern s32 func_0012bbb0(s32);
extern void func_0012bfb0(void);


/* Keep the allocator table base as a u32 local so MWCCPS2 hoists its
 * address into $s2 and reuses it at both allocation call sites. */
typedef struct {
    s32 state;
    s32 index;
    s32 counter;
    s32 handle;
    s32 task10;
    s32 task14;
} LogoWork;

// FUN_0012BBB0

s32 func_0012bbb0(s32 arg0)
{
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 var_2;
    s32 var_2_2;
    s32 *temp_18;
    s32 *temp_18_2;
    LogoWork *temp_2;
    s32 temp_2_2;
    s32 *temp_2_3;
    s32 *temp_2_4;
    u32 allocator;
    void *temp_2_7;

    temp_2 = (LogoWork *)func_00452560();
    temp_2_2 = temp_2->state;
    switch (temp_2_2) {
    case 0:
        temp_2->state = 1;
    case 1:
        temp_2->state = 2;
        func_00440b68(&D_00762D88, &D_005E5730, 0xB5);
        temp_2->handle = (s32)func_00454a60(D_005E5760, 1);
    case 2:
        if (func_004553c0((void *)temp_2->handle) != 0) {
            temp_2->state = 3;
            func_0044ea90(&D_005E5730, 0x4D);
            allocator = (u32)D_008873F4;
            temp_2_3 = (s32 *)((void *(*)(s32, s32, u32))*(u32 *)allocator)(1, 0xC, 0x40000);
            temp_2_3[0] = 0;
            temp_2_3[1] = (s32)func_004667d0(0, D_005E5770, 0, 0, 0, 0, 0, 0, 0, 0);
            temp_2->task10 = func_00451de0(&D_00762D98, 0x100, 0, 0, func_0012b890, func_0012b940, temp_2_3);
            func_0044ea90(&D_005E5730, 0x4D);
            temp_2_4 = (s32 *)((void *(*)(s32, s32, u32))*(u32 *)allocator)(1, 0xC, 0x40000);
            temp_2_4[0] = 0;
            temp_2_4[1] = (s32)func_004667d0(0, D_005E5790, 0, 0, 0, 0, 0, 0, 0, 0);
            temp_2->task14 = func_00451de0(&D_00762D98, 0x100, 0, 0, func_0012b890, func_0012b940, temp_2_4);
        }
        break;
    case 3:
        temp_19 = temp_2->task10;
        temp_18 = (s32 *)func_00452560(temp_19);
        if (func_00452490(temp_19) == 0) {
            var_2 = 0;
        } else if (*temp_18 == 3) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
        if (var_2 != 0) {
            temp_19_2 = temp_2->task14;
            temp_18_2 = (s32 *)func_00452560(temp_19_2);
            if (func_00452490(temp_19_2) == 0) {
                var_2_2 = 0;
            } else if (*temp_18_2 == 3) {
                var_2_2 = 1;
            } else {
                var_2_2 = 0;
            }
            if (var_2_2 != 0) {
                temp_2->state = 4;
            }
        }
        break;
    case 4:
        temp_2->state = 5;
        temp_2->counter = 0;
        func_00122640(0, 0xA);
    case 5:
        temp_2_5 = temp_2->counter + 1;
        temp_2->counter = temp_2_5;
        if (temp_2_5 >= 0x46) {
            temp_2->state = 6;
            func_00122520(1, 0xA);
        }
        break;
    case 6:
        if (func_00122720() != 0) {
            temp_2->state = 7;
        case 7:
            temp_2->state = 8;
            temp_2->counter = 0;
            func_00122640(0, 0xA);
        case 8:
            temp_2_6 = temp_2->counter + 1;
            temp_2->counter = temp_2_6;
            if (temp_2_6 >= 0x46) {
                temp_2->state = 9;
                func_00122520(1, 0xA);
            }
        }
        break;
    case 9:
        if (func_00122720() != 0) {
            temp_2->state = 0xA;
        case 10:
            if (func_00122720() != 0) {
                temp_2->index = 1;
            }
        }
        break;
    }
    temp_2_7 = func_00460990();
    *(s32 *)((u8 *)temp_2_7 + 8) = (s32)func_0012b9a0;
    *(s32 **)((u8 *)temp_2_7 + 0x10) = (s32 *)arg0;
    func_00460ac0(&D_00795E60, temp_2_7);
    return 0;
}



// FUN_0012BFB0
void func_0012bfb0(void)
{
    typedef struct LogoWork LogoWork;
    struct LogoWork
    {
        s32 state;
        s32 index;
        s32 counter;
        void *handle;
        s32 task10;
        s32 task14;
    };
    LogoWork *temp_2;
    s32 *temp_17;
    s32 *temp_17_2;
    s32 temp_18;
    s32 temp_18_2;
    s32 var_2;
    s32 var_2_2;

    temp_2 = func_00452560();
    temp_18 = temp_2->task10;
    temp_17 = func_00452560(temp_18);
    if (func_00452490(temp_18) == 0) {
        var_2 = 0;
    } else if (*temp_17 == 3) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if (var_2 == 0) {
        func_0046d730(&D_005E5730, 0xF8);
    }
    temp_18_2 = temp_2->task14;
    temp_17_2 = func_00452560(temp_18_2);
    if (func_00452490(temp_18_2) == 0) {
        var_2_2 = 0;
    } else if (*temp_17_2 == 3) {
        var_2_2 = 1;
    } else {
        var_2_2 = 0;
    }
    if (var_2_2 == 0) {
        func_0046d730(&D_005E5730, 0xF9);
    }
    func_00452080(temp_2->task10);
    func_00452080(temp_2->task14);
    func_00454bd0(temp_2->handle);
    jtbl_008873EC[0](temp_2);
}



// FUN_0012C110
s32 func_0012c110(void)
{
    void *temp_2;

    func_0044ea90(&D_005E5730, 0x107);
    temp_2 = D_008873F4[0](1, 0x18, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)((u8 *)temp_2 + 4) = 0;
    return func_00451de0(&D_005E57A8, 0xF, 0, 0, func_0012bbb0, func_0012bfb0, temp_2);
}


/* Source unit: src/rw/rpworld_003d4d70.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern int func_003cc0d0(int);

extern int func_003cc010(int);

extern int func_003cc070(int);


#pragma optimization_level 3

// FUN_003D4D70
int func_003d4d70(void)
{
    return func_003cc0d0(0);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_003D4D80
s32 func_003d4d80(void)
{
    extern s32 func_0039b6e0(s32 arg0);
    extern s32 func_003df590(s32 arg0, void *arg1);
    extern s32 func_003df4d0(s32 *arg0);
    extern u8 D_008872E0[];
    extern s32 iGpffffb9b8;
    extern u8 D_0070B590[];
    s32 stack[2];
    s32 temp_2;

    temp_2 = func_0039b6e0(0x1001);
    *(s32 *)(D_008872E0 + iGpffffb9b8 + 0x5C) = temp_2;
    if (temp_2 != 0) {
        func_003cc0d0(temp_2);
        return 1;
    }
    func_003cc0d0(0);
    stack[0] = 2;
    stack[1] = func_003df590(0x80000006, D_0070B590);
    func_003df4d0(stack);
    return 1;
}
// FUN_003D4E00
int func_003d4e00(void)
{
    return func_003cc010(0);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_003D4E10
s32 func_003d4e10(void)
{
    extern s32 func_0039b6e0(s32 arg0);
    extern s32 func_003df590(s32 arg0, void *arg1);
    extern s32 func_003df4d0(s32 *arg0);
    extern u8 D_008872E0[];
    extern s32 iGpffffb9b8;
    extern u8 D_0070B5B0[];
    s32 stack[2];
    s32 temp_2;

    temp_2 = func_0039b6e0(0x1003);
    *(s32 *)(D_008872E0 + iGpffffb9b8 + 0x58) = temp_2;
    if (temp_2 != 0) {
        func_003cc010(temp_2);
        return 1;
    }
    func_003cc010(0);
    stack[0] = 2;
    stack[1] = func_003df590(0x80000006, D_0070B5B0);
    func_003df4d0(stack);
    return 1;
}
// FUN_003D4E90
int func_003d4e90(void)
{
    return func_003cc070(0);
}
#pragma optimization_level 2

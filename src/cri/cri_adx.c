/* Source unit: src/cri/cri_adx_004e7798.c (1 function markers) */
#include "type.h"

int func_004e77c0(void);

u64 func_004e8058(void);

void func_004f9a88(void);

void func_004f54a0(void);

u32 func_00527960(int param_1,int param_2);


#pragma optimization_level 3

// FUN_004E7798
long func_004e7798(void)
{
    return func_004e77c0();
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_004E80C0
long func_004e80c0(void)
{
    long result;

    result = func_004e8058();
    return result >> 0x20;
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_004F1F58
void func_004f1f58(void)
{
    func_004f9a88();
    func_004f9a88();
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_004F2648
u32 func_004f2648(void)
{
    func_004f54a0();
    return 0x800;
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_00524580
u8 func_00524580(int param_1)
{
    return func_00527960(param_1,1) != 0;
}
#pragma optimization_level 2

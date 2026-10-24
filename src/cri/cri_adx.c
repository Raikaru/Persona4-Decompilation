/* Source unit: src/cri/cri_adx_004e7798.c (1 function markers) */
#include "type.h"

s64 htCiGetFileSize(const char *filename);

s64 func_004e8058(const char *filename);

void RFTGT_Wait100MicroSec(void);

void func_004f54a0(void);

u32 func_00527960(int param_1,int param_2);


#pragma optimization_level 3

// FUN_004E7798
s32 func_004e7798(const char *filename)
{
    return (s32)htCiGetFileSize(filename);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_004E80C0
s32 htci_filesize_upper(const char *filename)
{
    s64 result;

    result = func_004e8058(filename);
    return (s32)(result >> 0x20);
}
#pragma optimization_level 2


#pragma optimization_level 3

// FUN_004F1F58
void waitRetrial(void)
{
    RFTGT_Wait100MicroSec();
    RFTGT_Wait100MicroSec();
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
u8 sfsee_IsMpsStream(int param_1)
{
    return func_00527960(param_1,1) != 0;
}
#pragma optimization_level 2

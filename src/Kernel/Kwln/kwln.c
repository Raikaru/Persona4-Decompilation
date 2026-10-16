/* Source unit: src/Kernel/Kwln/kwln_002519b0.c (1 function markers) */
#include "type.h"

extern void kwlnTaskGetWork(void* a0);

extern void itfMesFlushPending(void* a0);

extern void func_002a1fa0(void* a0);

extern void mcDrawDispatch(void* a0);

extern void pscModelDraw(void* a0);



// FUN_002519B0
void func_002519b0(void* param_1, void* param_2)
{
    kwlnTaskGetWork(param_2);
}



// FUN_0027B5A0
void func_0027b5a0(void* param_1, void* param_2)
{
    itfMesFlushPending(param_2);
}



// FUN_002A1EF0
void func_002a1ef0(void* param_1, void* param_2)
{
    func_002a1fa0(param_2);
}



// FUN_002A6650
void func_002a6650(void* param_1, void* param_2)
{
    mcDrawDispatch(param_2);
}



// FUN_00369440
void func_00369440(void* param_1, void* param_2)
{
    pscModelDraw(param_2);
}

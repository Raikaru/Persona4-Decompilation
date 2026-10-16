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
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern void (*D_008873FC[])(s32 param, u8* arg);
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on
// Intent: sets the four bytes of the kwln RGBA colour record (the one kwlnGetColorRgb returns).
// FUN_00457140
void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    iGpffffba88 = arg0;
    iGpffffba89 = arg1;
    iGpffffba8a = arg2;
    iGpffffba8b = arg3;
}


// Intent: sets the four bytes of the kwln colour record that kwlnGetColorBytes returns.
// FUN_00457170
void kwlnSetColorBytes(s8 arg0, s8 arg1, s8 arg2, s8 arg3)
{
    iGpffffba84 = arg0;
    iGpffffba85 = arg1;
    iGpffffba86 = arg2;
    iGpffffba87 = arg3;
}



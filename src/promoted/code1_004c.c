#include "include_asm.h"
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3

extern s32 D_00758688[];


// FUN_004C3400
u32 func_004c3400(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x4C3C) = arg0;
    return segment;
}




// FUN_004C9BD0
u32 func_004c9bd0(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x65F0) = arg0;
    return segment;
}


// FUN_004CA648
s32 *func_004ca648(void)
{
    return D_00758688;
}


// FUN_004CA658
u32 func_004ca658(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x7754) = arg0;
    return segment;
}


// FUN_004CB2C0
u32 func_004cb2c0(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x6680) = arg0;
    return segment;
}




// FUN_004CF7E0
void func_004cf7e0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}


// FUN_004CF9C0
void func_004cf9c0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}

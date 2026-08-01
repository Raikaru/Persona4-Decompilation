#include "type.h"

extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];



// FUN_004526F0
void func_004526f0(u8* arg0, s32 arg1)
{
    (*D_008873FC)(arg1, arg0);
}



// FUN_004556B0
s32 func_004556b0(u8* arg0, u32 arg1)
{
    if (arg1 < *(u32*)(arg0 + 4)) {
        return (s32)(*(u8**)(arg0 + 0x58) + arg1 * 0x110);
    }
    return 0;
}



// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}



// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}

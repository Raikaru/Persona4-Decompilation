#include "type.h"

extern u8 *(*D_008873F8[])(...);
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])(...);
extern void func_00452730(s32 arg0);

extern void (*jtbl_008873EC[])(...);

extern s32 D_00724BEC;
extern s32 D_00724BF0;

extern void func_0046ab90(u8 *arg0);
extern u8 *D_00724C08;

extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;



// FUN_00460990
u8 *func_00460990(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B88, 0x41002);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_004609F0
u8 *func_004609f0(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B8C, 0x41003);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_00460A50
void func_00460a50(s32 arg0)
{
    jtbl_008873FC[0](D_00724B8C, arg0);
}



// FUN_00460A80
void func_00460a80(s32 arg0, s32 arg1)
{
    memset((void *)arg0, 0, arg1 * 0x30);
    func_00452730(D_00724B88);
}



// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}



// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}



// FUN_0046AB40
void func_0046ab40(void)
{
    u8 *var_16 = D_00724C08;

loop_1:
    if (var_16 != NULL) {
        func_0046ab90(var_16);
        var_16 = *(u8 **)(var_16 + 0x238);
        goto loop_1;
    }
}



// FUN_0046D6B0
void func_0046d6b0(s32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}

#include "include_asm.h"
#include "type.h"
extern s32 iGpffff9ef8;

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);

typedef struct E9F0Vec3
{
    f32 x;
    f32 y;
    f32 z;
} E9F0Vec3;



// FUN_00160440
void func_00160440(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x1854) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x1854));
        *(s32 *)((u8 *)func_00155280() + 0x1854) = 0;
    }
}



// FUN_00161500
void func_00161500(s32 arg0)
{
    iGpffff9ef8 = arg0;
}

// FUN_001622D0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001622d0);

// FUN_00162330
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00162330);

// FUN_00162390
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00162390);

// FUN_00168030
void func_00168030(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00168470
void func_00168470(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00168780
void func_00168780(u8 *arg0, f32 fparg0) {
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(f32 *)(temp_5 + 0x24) = fparg0;
    if (fparg0 == 0.0f) {
        *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) | 0x10000000);
        return;
    }
    *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) & 0xEFFFFFFF);
}

// FUN_001687D0
s32 func_001687d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40);
}

// FUN_001687E0
s32 func_001687e0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44);
}

// FUN_0016E580
s32 func_0016e580(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x8);
}

// FUN_0016E9F0
void func_0016e9f0(u8 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    *(E9F0Vec3 *)(temp_3 + 0x14) = *(E9F0Vec3 *)(arg1 + 0x00);
}



// FUN_0016EA40
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016ea40);

// FUN_0016EAA0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016eaa0);

// FUN_0016EAF0
s32 func_0016eaf0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x2BC);
}

// FUN_0016F100
void func_0016f100(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

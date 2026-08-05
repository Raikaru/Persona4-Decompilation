#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_004841c0(void *arg0);

extern void func_00484280();



// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}



// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}



// FUN_00494F90
void func_00494f90(u8 *arg0) {
    func_0048a1f0();
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}

// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(void **)(arg0 + 0x10));
    func_00484280(*(void **)(arg0 + 0x14), arg1);
}

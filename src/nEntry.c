#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern void *func_0043f9c8(void *dst, s32 value, s32 size);
extern u8 D_0063E8E0[];
extern u8 D_0063E918[];
extern void func_002a2420(u8 *arg0);

// FUN_002A2420
INCLUDE_ASM("asm/nonmatchings/nEntry", func_002a2420);

// FUN_002A2600
void func_002a2600(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(b + 0x8) != 0) {
        func_0046b0d0(*(s32 *)(b + 0x8));
        *(s32 *)(b + 0x8) = 0;
    }
    jtbl_008873EC[0](b);
}

// FUN_002A2650
s32 func_002a2650(u8 *arg0)
{
    u8 *mem;

    func_0044ea90(D_0063E8E0, 0xB03);
    mem = D_008873F4[0](1, 0x18, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    func_0043f9c8(mem, 0, 0x18);
    return func_00451fc0(arg0, D_0063E918, 0xF, 0, 0, func_002a2420,
                         func_002a2600, mem);
}


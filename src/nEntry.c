#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern void *func_0043f9c8(void *dst, s32 value, s32 size);
extern u8 D_0063E8E0[];
extern u8 D_0063E918[];
extern void func_002a2340(void);
extern void func_004599a0(s32 arg0, s32 arg1);
extern s32 func_0046aea0(u8 *name);
extern s32 func_0046a750(s32 handle);
extern s32 func_004522d0(s32 handle);
extern s32 func_002a1f20(u8 *arg0);
extern void func_002a2310(u8 *arg0);
extern u8 D_0063E900[];
extern u8 D_0063E8F0[];
extern s32 D_00764630;
extern s32 func_002a2420(u8 *arg0);

// FUN_002A2420
/* Case values decoded from jtbl_007486C0 with tools/jtbl.py: a 0/1/2/3/5/6
   state machine with case 4 and the out-of-range default both falling to the
   shared `return 0`, declared in that object order.
   Two prototypes had to be widened for this: func_00451fc0's `init` callback
   returns s32 (retail's func_002a2420 leaves 0 or -1 in $v0 and the window
   manager takes it), and func_002a1f20 is one of those callbacks. */
s32 func_002a2420(u8 *arg0) {
    u8 *st;
    u8 *mem;
    s32 r;

    st = *(u8 **)(arg0 + 0x38);
    switch ((u32)*(s32 *)st) {
    case 0:
        func_002a2340();
        *(s32 *)st = 1;
        func_004599a0(0x14, 0x1E);
        break;
    case 1:
        *(s32 *)(st + 8) = func_0046aea0(D_0063E900);
        *(s32 *)st = 2;
        break;
    case 2:
        if (func_0046a750(*(s32 *)(st + 8)) != 1) {
            break;
        }
        D_00764630 = *(s32 *)(st + 8);
        func_0044ea90(D_0063E8E0, 0xA5E);
        mem = D_008873F4[0](1, 0x1C6C, 0x40000);
        if (mem == NULL) {
            r = 0;
        } else {
            func_0043f9c8(mem, 0, 0x1C6C);
            r = func_00451fc0(arg0, D_0063E8F0, 0xF, 0, 0, func_002a1f20, func_002a2310, mem);
        }
        *(s32 *)(st + 0x10) = r;
        *(s32 *)st = 3;
        break;
    case 3:
        *(s32 *)(st + 0xC) = 0;
        *(s32 *)st = 5;
        break;
    case 5:
        if (func_004522d0(*(s32 *)(st + 0x10)) != 3) {
            if (func_004522d0(*(s32 *)(st + 0x10)) != 0) {
                break;
            }
        }
        *(s32 *)(st + 0x10) = 0;
        *(s32 *)st = 6;
        break;
    case 6:
        D_00764630 = 0;
        return -1;
    case 4:
        break;
    }
    return 0;
}

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


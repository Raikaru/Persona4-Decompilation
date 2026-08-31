#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldMipmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_005F5370[];
extern u8 D_005F5420[];
extern s32 func_0018bfb0(u8 *arg0);
extern u8 iGpffff9f88;
extern u8 D_005F5360[];
extern u8 D_005F5380[];
extern u8 D_005F53A0[];
extern u8 D_005F53C0[];
extern u8 D_005F53E0[];
extern u8 D_005F5400[];
extern void *func_003ef6d0(void);
extern void *func_003ef650(void *arg0, const void *arg1);
extern void func_003ef3a0(void *arg0);
extern void func_00440b68(void *arg0, const void *arg1, s32 arg2);
extern void *func_00454a60(void *arg0, s32 arg1);
extern s32 func_004553c0(void *arg0);
extern s32 func_004667d0(s32, const void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void *func_003ec590(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void func_00454bd0(void *arg0);
extern void func_003ec6a0(void *arg0, s32 arg1, s32 arg2);
extern void func_003ec180(void *arg0, void *arg1);
extern void func_003ec2a0(void *arg0);
extern void *func_003ef2e0(void *arg0);
extern void func_003ef470(void *arg0, const void *arg1);
extern void func_003ef5b0(void *arg0, void *arg1);
extern void func_003ea370(void *arg0);





// FUN_0018BFB0
s32 func_0018bfb0(u8 *arg0)
{
    u8 *work;
    s32 state;
    s32 i;
    s32 out;
    u8 *tmp;
    u32 flags;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        tmp = func_003ef650(func_003ef6d0(), D_005F5360);
        if (tmp != NULL) {
            func_003ef3a0(tmp);
        }
        func_00440b68(&iGpffff9f88, D_005F5370, 0x54);
        *(u8 **)(work + 0x4) = func_00454a60(D_005F5380, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x55);
        *(u8 **)(work + 0x8) = func_00454a60(D_005F53A0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x56);
        *(u8 **)(work + 0xC) = func_00454a60(D_005F53C0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x57);
        *(u8 **)(work + 0x10) = func_00454a60(D_005F53E0, 0);
        func_00440b68(&iGpffff9f88, D_005F5370, 0x58);
        *(u8 **)(work + 0x14) = func_00454a60(D_005F5400, 0);
        *(s32 *)work += 1;
        break;
    case 1:
        if (func_004553c0(*(u8 **)(work + 0x4)) != 0 &&
            func_004553c0(*(u8 **)(work + 0x8)) != 0 &&
            func_004553c0(*(u8 **)(work + 0xC)) != 0 &&
            func_004553c0(*(u8 **)(work + 0x10)) != 0 &&
            func_004553c0(*(u8 **)(work + 0x14)) != 0) {
            *(u8 **)(work + 0x34) =
                (u8 *)func_004667d0(0xA, D_005F5380, 0, 0, 0, 0, 0, 0, 0, 0);
            *(u8 **)(work + 0x38) =
                (u8 *)func_004667d0(0xA, D_005F53A0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(u8 **)(work + 0x3C) =
                (u8 *)func_004667d0(0xA, D_005F53C0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(u8 **)(work + 0x40) =
                (u8 *)func_004667d0(0xA, D_005F53E0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(u8 **)(work + 0x44) =
                (u8 *)func_004667d0(0xA, D_005F5400, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)work += 1;
        }
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            u8 *entry;
            u8 *resource;

            entry = work + i * 4;
            resource = entry + 0x34;
            if (*(u8 **)resource != NULL) {
                *(u8 **)(entry + 0x18) =
                    (u8 *)func_004669d0((s32)*(u8 **)resource, &out, 0);
                if (out != 0) {
                    *(u8 **)resource = NULL;
                } else {
                    return 0;
                }
            }
        }
        *(u8 **)(work + 0x2C) = (u8 *)func_003ec590(0x80, 0x80, 8, 0xA504);
        func_003ec6a0(*(u8 **)(work + 0x2C), 0, 5);
        func_003ec180(*(u8 **)(work + 0x2C), *(u8 **)(work + 0x18));
        func_003ec2a0(*(u8 **)(work + 0x2C));
        func_003ec6a0(*(u8 **)(work + 0x2C), 1, 5);
        func_003ec180(*(u8 **)(work + 0x2C), *(u8 **)(work + 0x1C));
        func_003ec2a0(*(u8 **)(work + 0x2C));
        func_003ec6a0(*(u8 **)(work + 0x2C), 2, 5);
        func_003ec180(*(u8 **)(work + 0x2C), *(u8 **)(work + 0x20));
        func_003ec2a0(*(u8 **)(work + 0x2C));
        func_003ec6a0(*(u8 **)(work + 0x2C), 3, 5);
        func_003ec180(*(u8 **)(work + 0x2C), *(u8 **)(work + 0x24));
        func_003ec2a0(*(u8 **)(work + 0x2C));
        func_003ec6a0(*(u8 **)(work + 0x2C), 4, 5);
        func_003ec180(*(u8 **)(work + 0x2C), *(u8 **)(work + 0x28));
        func_003ec2a0(*(u8 **)(work + 0x2C));
        *(u8 **)(work + 0x30) =
            (u8 *)func_003ef2e0(*(u8 **)(work + 0x2C));
        func_003ef470(*(u8 **)(work + 0x30), D_005F5360);
        flags = *(u32 *)(*(u8 **)(work + 0x30) + 0x50);
        *(u32 *)(*(u8 **)(work + 0x30) + 0x50) = (flags & ~0xFFU) | 6;
        func_003ef5b0(func_003ef6d0(), *(u8 **)(work + 0x30));
        *(s32 *)work += 1;
        break;
    case 3:
        func_003ea370(*(u8 **)(work + 0x18));
        func_003ea370(*(u8 **)(work + 0x1C));
        func_003ea370(*(u8 **)(work + 0x20));
        func_003ea370(*(u8 **)(work + 0x24));
        func_003ea370(*(u8 **)(work + 0x28));
        func_00454bd0(*(u8 **)(work + 0x4));
        func_00454bd0(*(u8 **)(work + 0x8));
        func_00454bd0(*(u8 **)(work + 0xC));
        func_00454bd0(*(u8 **)(work + 0x10));
        func_00454bd0(*(u8 **)(work + 0x14));
        return -1;
    default:
        break;
    }
    return 0;
}
// FUN_0018C550
void func_0018c550(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018C580
s32 func_0018c580(void)
{
    u8 *mem;

    func_0044ea90(D_005F5370, 0xC3);
    mem = D_008873F4[0](1, 0x48, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    return func_00451de0(D_005F5420, 0xF, 0, 0, func_0018bfb0, func_0018c550, mem);
}


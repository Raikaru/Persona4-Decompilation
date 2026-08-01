/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

extern void (*jtbl_008873EC[])(...);
extern void *(*D_008873F4[])(...);
extern u16 D_008C024E[];

extern u8 D_005F5990[];
extern u8 D_005F59A0[];
extern u8 D_005F59F0[];
extern u8 D_005F5AB0[];
extern s32 D_00764304;
extern s32 D_00764344;
extern s32 D_00764348;
extern s32 D_0076434C;
extern s32 D_00764350;
extern s32 D_00764494;

extern void func_0015a630(void);
extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern s32 func_00470250(u8 *window, s32 size, s32 align);
extern void func_00470810(s32 buf, void *file, s32 flags);
extern s32 *func_00470bd0(s32 buf, s32 index);
extern void func_004703c0(s32 buf, s32 flags);
extern void func_004703d0(s32 buf, s32 flags);
extern s32 func_00102980(void);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);

extern s32 func_0018efe0(u8 *arg0);
extern void func_0018f390(u8 *arg0);

// FUN_0018F3C0
s32 func_0018f3c0(s32 arg0)
{
    s32 *buf;
    s32 ret;

    func_0044ea90(D_005F5990, 0xFB);
    buf = D_008873F4[0](1, 0x10, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005F59A0, 0xF, 0, 0, func_0018efe0,
                        func_0018f390, buf);
    func_0015a630();
    D_00764304 = 0;
    return ret;
}

// FUN_0018F470
s32 func_0018f470(u8 *arg0)
{
    s32 *p;
    s32 state;
    s32 value;
    s32 sp[2];

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
    {
        s32 buf;

        buf = func_00470250(arg0, 0xDC, 0xA0);
        *(s32 *)(p + 1) = buf;
        func_00470810(buf, D_005F59F0, 6);
        value = D_00764344;
        *func_00470bd0(*(s32 *)(p + 1), 2) = value;
        value = D_00764348;
        *func_00470bd0(*(s32 *)(p + 1), 3) = value;
        value = D_0076434C;
        *func_00470bd0(*(s32 *)(p + 1), 4) = value;
        value = D_00764350;
        *func_00470bd0(*(s32 *)(p + 1), 5) = value;
        func_004703c0(*(s32 *)(p + 1), 4);
        func_004703d0(*(s32 *)(p + 1), 1);
        *(s32 *)p = *(s32 *)p + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            D_00764304 = *func_00470bd0(*(s32 *)(p + 1), 1);
            D_00764344 = *func_00470bd0(*(s32 *)(p + 1), 2);
            D_00764348 = *func_00470bd0(*(s32 *)(p + 1), 3);
            D_0076434C = *func_00470bd0(*(s32 *)(p + 1), 4);
            D_00764350 = *func_00470bd0(*(s32 *)(p + 1), 5);
            sp[0] = *func_00470bd0(*(s32 *)(p + 1), 0);
            sp[1] = 0xFFFF;
            func_001029a0(0xB, sp, 8, 0);
            func_004703d0(*(s32 *)(p + 1), 0);
            *(s32 *)p = 2;
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)p = 3;
        }
        break;
    case 2:
        if (func_00102980() == 0) {
            D_00764494 = 0;
            func_004703d0(*(s32 *)(p + 1), 1);
            *(s32 *)p = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0018F6D0
void func_0018f6d0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018F700
s32 func_0018f700(s32 arg0)
{
    s32 *buf;
    s32 ret;

    func_0044ea90(D_005F5990, 0x183);
    buf = D_008873F4[0](1, 0x10, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = func_00451fc0(arg0, D_005F5AB0, 0xF, 0, 0, func_0018f470,
                        func_0018f6d0, buf);
    func_0015a630();
    D_00764304 = 0;
    return ret;
}

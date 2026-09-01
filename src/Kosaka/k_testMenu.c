/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

extern void (*jtbl_008873EC[])();
extern void *(*D_008873F4[])();
extern u16 D_008C024E[];

extern u8 D_005F55B0[];
extern u8 D_005F56F0[];
extern u8 D_005F5700[];
extern f32 D_00761624;
extern f32 D_0076151C;

extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00470250(u8 *window, s32 size, s32 align);
extern void func_00470810(s32 buf, void *file, s32 flags);
extern void func_00470430(s32 buf, s32 size);
extern void func_004703c0(s32 buf, s32 flags);
extern void func_004703d0(s32 buf, s32 flags);
extern u32 func_00470e20(s32 buf);
extern void func_0046d730(void *msg, s32 id);
extern s32 func_00452490(s32 buf);
extern s32 func_00452380(void *buf);
extern void func_00452080(s32 handle);
extern void func_00451de0(void *data, s32 a, s32 b, s32 c,
                          s32 (*init)(u8 *), void (*close)(u8 *), void *buf);

extern s32 func_0018ef50(u8 *arg0);
extern s32 func_0018e520(u8 *arg0);
extern void func_00190600(void);
extern s32 func_001838d0(f32 f0, u8 *arg0, s32 arg1, f32 f1, f32 f2, f32 f3,
                          s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00186640(u8 *arg0);
extern s32 func_0017d070(u8 *arg0);
extern s32 func_001924d0(s32 arg0);
extern s32 func_00191610(s32 arg0);
extern s32 func_00191bc0(s32 arg0);
extern s32 func_00191d90(s32 arg0);

// FUN_0018E050
s32 func_0018e050(u8 *arg0)
{
    u8 *p;
    s32 state;

    p = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)p;
    switch (state) {
    case 0:
    {
        s32 buf;

        buf = func_00470250(arg0, 0x100, 0x40);
        *(s32 *)(p + 4) = buf;
        func_00470810(buf, D_005F55B0, 0xA);
        func_00470430(*(s32 *)(p + 4), 0x14);
        func_004703c0(*(s32 *)(p + 4), 4);
        func_004703d0(*(s32 *)(p + 4), 1);
        *(s32 *)p = *(s32 *)p + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            switch (func_00470e20(*(s32 *)(p + 4))) {
            case 0:
                *(s32 *)(p + 8) = func_0018ef50(arg0);
                break;
            case 1:
                *(s32 *)(p + 8) = func_0018e520(arg0);
                break;
            case 2:
                func_00190600();
                break;
            case 3:
                *(s32 *)(p + 8) = func_001838d0(200.0f, arg0, 0, D_00761624,
                                                  D_0076151C, 30.0f, 0x30, 8,
                                                  0xA);
                break;
            case 4:
                *(s32 *)(p + 8) = func_00186640(arg0);
                break;
            case 5:
                *(s32 *)(p + 8) = func_0017d070(arg0);
                break;
            case 6:
                *(s32 *)(p + 8) = func_001924d0(0);
                break;
            case 7:
                *(s32 *)(p + 8) = func_00191610(0);
                break;
            case 8:
                *(s32 *)(p + 8) = func_00191bc0(0);
                break;
            case 9:
                *(s32 *)(p + 8) = func_00191d90(0);
                break;
            default:
                func_0046d730(D_005F56F0, 0xA1);
                break;
            }
            func_004703d0(*(s32 *)(p + 4), 0);
            *(s32 *)p = 2;
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)p = 3;
        }
        break;
    case 2:
        if (func_00452490(*(s32 *)(p + 8)) != 1) {
            func_004703d0(*(s32 *)(p + 4), 1);
            *(s32 *)p = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0018E310
void func_0018e310(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018E340
void func_0018e340(void)
{
    func_0044ea90(D_005F56F0, 0xCB);
    func_00451de0(D_005F5700, 0xF, 0, 0, func_0018e050, func_0018e310,
                  D_008873F4[0](1, 0xC, 0x40000));
}

// FUN_0018E3C0
s32 func_0018e3c0(void)
{
    return func_00452380(D_005F5700) != 0;
}

// FUN_0018E3F0
void func_0018e3f0(void)
{
    s32 result;

    result = func_00452380(D_005F5700);
    if (result == 0) {
        func_0046d730(D_005F56F0, 0xF2);
    }
    func_00452080(result);
}

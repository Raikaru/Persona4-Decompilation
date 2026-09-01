/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

extern void (*jtbl_008873EC[])();
extern void *(*D_008873F4[])();

extern u8 D_005F5718[];
extern u8 D_00763098;

extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern void func_004787e0(s32 handle);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern s32 *func_00155280(void);
extern s32 func_00156140(s32 handle);
extern s32 func_0015f660(void);

extern s32 func_0018e450(u8 *arg0);
extern void func_0018e4d0(u8 *arg0);

typedef struct
{
    u16 field0;    // 0x00
    u16 field1;    // 0x02
    s16 field2;    // 0x04
    s16 field3;    // 0x06
    s16 field4;    // 0x08
    u8 pad[0x12];  // 0x0A
} TestMenuMsg;

// FUN_0018E520
void func_0018e520(s32 arg0)
{
    func_0044ea90(D_005F5718, 0x7A);
    func_00451fc0(arg0, &D_00763098, 0xF, 0, 0, func_0018e450, func_0018e4d0,
                  D_008873F4[0](1, 0x1C, 0x40000));
}

// FUN_0018E5B0
s32 func_0018e5b0(u8 *arg0)
{
    u32 *p;
    u32 state;
    TestMenuMsg msg;

    p = *(u32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
    case 2:
    case 3:
        *p = state + 1;
        break;
    case 4:
        if (func_00156140(*func_00155280()) != 0 && func_0015f660() != 0) {
            func_0043f9c8(&msg, 0, 0x1C);
            msg.field0 = 6;
            msg.field1 = 6;
            msg.field2 = 0;
            msg.field4 = 0;
            func_001029a0(9, &msg, 0x1C, 3);
            *p += 1;
        }
        break;
    case 5:
    case 6:
    case 7:
        *p = state + 1;
        break;
    case 8:
        if (func_00156140(*func_00155280()) != 0 && func_0015f660() != 0) {
            func_0043f9c8(&msg, 0, 0x1C);
            msg.field0 = 6;
            msg.field1 = 2;
            msg.field2 = 5;
            msg.field4 = 0;
            func_001029a0(9, &msg, 0x1C, 3);
            *p = 1;
        }
        break;
    }
    return 0;
}

// FUN_0018E730
void func_0018e730(u8 *arg0)
{
    u8 *p;
    s32 v;

    p = *(u8 **)(arg0 + 0x38);
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_004787e0(v);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018E780
void func_0018e780(s32 arg0)
{
    func_0044ea90(D_005F5718, 0xE0);
    func_00451fc0(arg0, &D_00763098, 0x12, 0, 0, func_0018e5b0, func_0018e730,
                  D_008873F4[0](1, 0x1C, 0x40000));
}

/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombineEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_0045aac0();
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0044ea90(u8 *file, s32 line);
extern u8 D_0064A400[];
extern u8 D_0064A420[];
extern u8 D_0064A440[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern void func_0033d9d0(u8 *arg0);
extern void func_0033dc60(u8 *arg0);
extern s32 func_0033dd40(u8 *arg0);
extern s32 func_0033df40(u8 *arg0);
extern s32 func_00285b30(void);
extern void func_00106390(s32 a, s32 b);
extern u16 D_008C024E[];
extern s32 func_00293ed0(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00293fc0(s32 arg0);
extern s32 func_002940a0(s32 arg0, s32 *a, s32 *b, s32 *c, s32 *d);
extern void func_00144c90(s32 a, s32 b);
extern void func_00144e10(s32 a);
extern void func_00144ed0(s32 a);
extern s32 func_00144f60(void);
extern s32 func_002859e0(s32 a, s32 b, s32 c);
extern s32 func_00452490(s32 handle);
extern void func_00452080(s32 handle);
extern void func_00145080(void);


// FUN_0033DC90
void func_0033dc90(u8 *arg0, s8 arg1)
{
    u8 *work;

    func_0044ea90(D_0064A400, 0xAF);
    work = D_008873F4[0](1, 0x14, 0x40000);
    func_00451fc0(arg0, D_0064A420, 0xF, 0, 0, func_0033d9d0, func_0033dc60, work);
    work[0] = 0;
    *(s8 *)(work + 0x10) = arg1;
}


// FUN_0033DD40
s32 func_0033dd40(u8 *arg0)
{
    s32 *temp_16;

    temp_16 = *(s32 **)(arg0 + 0x38);
    if (func_00285b30() >= 4) {
        if ((func_00285b30() >= 0x11D) && (func_00285b30() < 0x12C)) {
            return 0;
        }
        if ((func_00285b30() >= 0x1A5) && (func_00285b30() < 0x1BD)) {
            return 0;
        }
        if (D_008C024E[0] & 0x800) {
            func_00106390(*temp_16, 1);
            return -1;
        }
        if (D_008C024E[0] & 0x40) {
            func_00106390(*temp_16, 1);
            return -1;
        }
    }
    return 0;
}


// FUN_0033DE40
void func_0033de40(u8 *arg0) {
    func_0045aac0(2, 0, 0);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}


// FUN_0033DE90
void func_0033de90(u8 *arg0, s32 arg1)
{
    u8 *work;

    func_0044ea90(D_0064A400, 0x10A);
    work = D_008873F4[0](1, 4, 0x40000);
    func_00451fc0(arg0, D_0064A440, 0xF, 0, 0, (void (*)(u8 *))func_0033dd40, func_0033de40, work);
    *(s32 *)work = arg1;
}


// FUN_0033DF40
s32 func_0033df40(u8 *arg0)
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 temp_4_2;
    s8 temp_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = (s8)temp_16[0];
    switch (temp_4) {
    case 0:
        *(s32 *)(temp_16 + 0x10) = func_00293ed0(*(s32 *)(temp_16 + 4), *(s32 *)(temp_16 + 8), 0, 0);
        temp_16[0] = (s8)((s8)temp_16[0] + 1);
        /* fallthrough */
    case 1:
        if ((func_00293fc0(*(s32 *)(temp_16 + 0x10)) != 0) && (func_002940a0(*(s32 *)(temp_16 + 0x10), &sp2C, &sp28, &sp24, &sp20) == 1)) {
            if (*(s32 *)(temp_16 + 8) == 0xA) {
                func_00144c90(sp2C, sp28);
            }
            func_00144e10((s16)sp24);
            func_00144ed0(3);
            temp_16[0] = (s8)((s8)temp_16[0] + 1);
        }
        goto out;
    case 2:
        if (func_00144f60() != 0) {
            *(s32 *)(temp_16 + 0xC) = func_002859e0(*(s32 *)(temp_16 + 4), *(s32 *)(temp_16 + 8), 0);
            temp_16[0] = (s8)((s8)temp_16[0] + 1);
        case 3:
            if (func_00452490(*(s32 *)(temp_16 + 0xC)) != 1) {
                temp_4_2 = *(s32 *)(temp_16 + 0x10);
                if (temp_4_2 != 0) {
                    func_00452080(temp_4_2);
                }
                if (*(s32 *)(temp_16 + 8) == 0xA) {
                    func_00145080();
                }
                temp_16[0] = (s8)((s8)temp_16[0] + 1);
            }
        }
        goto out;
    case 4:
    case 5:
        temp_16[0] = (s8)(temp_4 + 1);
        goto out;
    case 6:
        return -1;
    default:
    out:
        return 0;
    }
}


// FUN_0033E0F0
void func_0033e0f0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


// FUN_0033E120
void func_0033e120(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *work;

    func_0044ea90(D_0064A400, 0x192);
    work = D_008873F4[0](1, 0x14, 0x40000);
    func_00451fc0(arg0, D_0064A440, 0xF, 0, 0, (void (*)(u8 *))func_0033df40, (void (*)(u8 *))func_0033e0f0, work);
    *(s32 *)(work + 4) = arg1;
    *(s32 *)(work + 8) = arg2;
    work[0] = 0;
}

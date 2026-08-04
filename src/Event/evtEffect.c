#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern void func_002852a0(s32 arg0, s32 arg1);
extern void func_00454bd0(u8 *arg0);
extern void func_00291470(u8 *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_00748340[];
extern u8 D_0063C830[];

// FUN_00290F00
u8 *func_00290f00(void)
{
    u8 *work;

    func_0044ea90(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x190, 0x40000);
    func_002852a0(0xB, 0x190);
    if (work == 0) {
        func_0046d730(D_0063C830, 0x69);
    }
    func_0043f9c8(work, 0, 0x190);
    *(s32 *)work = 0;
    return work;
}

// FUN_00290FA0
void func_00290fa0(u8 *arg0)
{
    s32 i;
    u8 *e;

    if (arg0 != NULL) {
        for (i = 0; i < *(s32 *)(arg0 + 4); i++) {
            e = arg0 + i * 0x2C;
            if (*(s32 *)(e + 0x10) == 1) {
                func_00454bd0(*(u8 **)(e + 0x38));
            }
        }
        func_00291470(arg0);
        jtbl_008873EC[0](arg0);
        func_002852a0(0xB, -0x190);
    }
}
// FUN_00291060
void func_00291060(u32 *param_1)
{
    *param_1 = 1;
    param_1[2] = 0;

    return;
}

// FUN_00291080
INCLUDE_ASM("asm/nonmatchings/evtEffect", func_00291080);

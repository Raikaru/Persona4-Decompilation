/* Consolidated Persona 4 source units. */
/* Original translation unit sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(u8 *file, s32 line);
extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_00451de0(u8 *name, s32 prio, s32 a2, s32 a3,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern void func_00102780(u8 *arg0);
extern void func_0043f810(void *dst, const void *src, s32 size);
extern u8 D_005DCC64[];
extern u8 D_005DCC68[];
extern u8 D_005DCC6C[];
extern void func_00102890(u8 *arg0);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005DCB28[];
extern u8 D_005DCB40[];
extern u8 *iGpffffb1a8;


// FUN_001028C0
s32 func_001028c0(void)
{
    u8 *mem;
    s32 handle;

    if (iGpffffb1a8 != 0) {
        func_0046d730(D_005DCB28, 0x7B);
    }
    func_0044ea90(D_005DCB28, 0x7D);
    mem = D_008873F4[0](1, 0x18, 0x40000);
    handle = func_00451de0(D_005DCB40, 0xF, 0, 0, func_00102780,
                             func_00102890, mem);
    *(s32 *)(mem + 4) = -1;
    *(s32 *)(mem + 8) = -1;
    iGpffffb1a8 = (u8 *)(u32)handle;
}
// FUN_001029A0
void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *work;
    u8 *work2;
    s32 type;
    u8 *temp;

    work = *(u8 **)((u8 *)iGpffffb1a8 + 0x38);
    if (arg0 < 0) {
        func_0046d730(D_005DCB28, 0xFE);
    }
    if ((*(s32 *)work & 1) != 0) {
        func_0046d730(D_005DCB28, 0xFF);
    }
    *(s32 *)(work + 8) = *(s32 *)(work + 4);
    work2 = *(u8 **)((u8 *)iGpffffb1a8 + 0x38);
    type = *(s32 *)(work2 + 4);
    if (type >= 0) {
        if ((*(s32 (**)(void))((u8 *)D_005DCC68 + type * 0x50))() == 1) {
            (*(s32 (**)(void))((u8 *)D_005DCC6C + *(s32 *)(work2 + 4) * 0x50))();
        }
        *(s32 *)(work2 + 4) = -1;
        *(s32 *)(work2 + 0x10) = 0;
    }
    *(s32 *)(work + 4) = arg0;
    if (arg3 != 0) {
        *(s32 *)work |= 1;
        if (arg2 != 0) {
            func_0044ea90(D_005DCB28, 0x10A);
            temp = D_008873F4[0](1, arg2, 0x40000);
            *(u8 **)(work + 0x14) = temp;
            func_0043f810(temp, (const void *)arg1, arg2);
        } else {
            *(u8 **)(work + 0x14) = NULL;
        }
        *(s32 *)(work + 0xC) = arg3;
        return;
    }
    *(s32 *)work &= ~1;
    *(s32 *)(work + 0xC) = 0;
    *(u8 **)(work + 0x14) = NULL;
    (*(void (**)(s32))((u8 *)D_005DCC64 + *(s32 *)(work + 4) * 0x50)) (arg1);
}





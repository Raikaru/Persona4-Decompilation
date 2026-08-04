/* Consolidated Persona 4 source units. */
/* Original translation unit sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(u8 *file, s32 line);
extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_00451de0(u8 *name, s32 prio, s32 a2, s32 a3,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern void func_00102780(u8 *arg0);
extern void func_00102890(u8 *arg0);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005DCB28[];
extern u8 D_005DCB40[];
extern s32 iGpffffb1a8;


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
    iGpffffb1a8 = handle;
}
// FUN_001029A0
INCLUDE_ASM("asm/nonmatchings/sequence", func_001029a0);

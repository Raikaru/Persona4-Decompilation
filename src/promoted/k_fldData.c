/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldData.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*DAT_008873EC[])();

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_005F0A88[];
extern u8 D_005F1050[];
extern void func_0015d730(u8 *arg0);



// FUN_0015D730
INCLUDE_ASM("asm/nonmatchings/k_fldData", func_0015d730);

// FUN_0015E7A0
void func_0015e7a0(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
// FUN_0015E7D0
s32 func_0015e7d0(void)
{
    u8 *mem;
    s32 result;

    func_0044ea90(D_005F0A88, 0x1ED);
    mem = D_008873F4[0](1, 0xF4, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    result = func_00451de0(D_005F1050, 0xF, 0, 0, func_0015d730, func_0015e7a0,
                           mem);
    *(s32 *)(mem + 4) = 0;
    return result;
}


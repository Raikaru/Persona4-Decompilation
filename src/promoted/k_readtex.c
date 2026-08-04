/* Consolidated Persona 4 source units. */
/* Original translation unit k_readtex.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(u8 *);

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_005F60B8[];
extern u8 D_005F6150[];
extern void func_001901d0(u8 *arg0);
extern void func_001905d0(u8 *arg0);





// FUN_001901D0
INCLUDE_ASM("asm/nonmatchings/k_readtex", func_001901d0);

// FUN_001905D0
void func_001905d0(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_00190600
void func_00190600(void)
{
    u8 *mem;

    func_0044ea90(D_005F60B8, 0x91);
    mem = D_008873F4[0](1, 0x24, 0x40000);
    if (mem != NULL) {
        func_00451de0(D_005F6150, 0xF, 0, 0, func_001901d0, func_001905d0, mem);
    }
}


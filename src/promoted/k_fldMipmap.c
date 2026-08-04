#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldMipmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_005F5370[];
extern u8 D_005F5420[];
extern void func_0018bfb0(u8 *arg0);




// FUN_0018BFB0
INCLUDE_ASM("asm/nonmatchings/k_fldMipmap", func_0018bfb0);
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


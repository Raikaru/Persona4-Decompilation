/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldFoodCourt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_00454bd0(void *arg0);
extern void func_003e0f40(void *arg0);
extern void func_00145080(void);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0044ea90(const void *msg, s32 id);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005F5450[];
extern u8 D_005F54C8[];
extern void func_0018d950(u8 *arg0);
extern void func_0018dcd0(u8 *arg0);


// FUN_0018D950
INCLUDE_ASM("asm/nonmatchings/k_fldFoodCourt", func_0018d950);

// FUN_0018DCD0
void func_0018dcd0(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    func_00454bd0(*(void **)(work + 8));
    func_003e0f40(*(void **)(work + 4));
    func_00145080();
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018DD40
s32 func_0018dd40(u8 *arg0)
{
    u8 *mem;

    func_0044ea90(D_005F5450, 0xBF);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    return func_00451fc0(arg0, D_005F54C8, 0xF, 0, 0, func_0018d950,
                         func_0018dcd0, mem);
}


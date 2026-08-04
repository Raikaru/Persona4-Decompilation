/* Consolidated Persona 4 source units. */
/* Original translation unit sdkWrap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(s32);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern void func_00440b68(const void *a, void *b);
extern u8 D_00712978[];
extern u8 D_007129E0[];
extern u8 D_00712A00[];
extern u8 D_004671C0[];

// FUN_00466C60
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_00466c60);
// FUN_00466E80
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_00466e80);




// FUN_00467290
void func_00467290(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}

/* measured: `handle` must be declared BEFORE `mem`. With `mem` first, b210
   colours mem into $s1 and handle into $s0 -- the exact mirror of retail --
   and every one of the 9 differing words is that swap. Declaration order is
   the whole fix here (9 -> 1, the remaining word being window padding). */
// FUN_004672C0
s32 func_004672c0(s32 arg0, u8 *arg1)
{
    s32 handle;
    u8 *mem;

    func_0044ea90(D_00712978, 0x3C4);
    mem = D_008873F4[0](1, 8, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    handle = func_00451fc0(NULL, D_007129E0, 0, 2, 2,
                           (void (*)(u8 *))D_004671C0, func_00467290, mem);
    if (handle == 0) {
        return 0;
    }
    if (arg1 != NULL) {
        func_00440b68(D_00712A00, arg1 + 0x10);
    }
    *(s32 *)(mem + 0) = arg0;
    *(u8 **)(mem + 4) = arg1;
    return handle;
}


/* Original translation unit sdkLbox.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_00453fa0();
extern s32 func_00453e60();
extern void func_004704d0();
extern void func_0046ea50();
extern void func_0046ea60();

// FUN_00470280
INCLUDE_ASM("asm/nonmatchings/sdkLbox", func_00470280);

// FUN_004703C0
void func_004703c0(u8 *arg0, s32 arg1) {
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}

// FUN_004703D0
void func_004703d0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    u8 *q;

    func_004704d0(arg0);
    *(s32 *)(p + 0xC) = arg1;
    *(s32 *)(p + 0x10) = 2;
    q = *(u8 **)(p + 0x130);
    if (q != NULL) {
        func_0046ea50(q, arg1);
    }
}

// FUN_00470430
void func_00470430(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_00453fa0(p + 0x164);
    *(s32 *)(p + 0x13C) = func_00453e60(p + 0x164);
    func_004704d0(arg0);
}

// FUN_00470490
void func_00470490(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    u8 *q;

    *(s32 *)(p + 0x18) = arg1;
    *(s32 *)(p + 0x1C) = arg2;
    q = *(u8 **)(p + 0x130);
    if (q != NULL) {
        func_0046ea60(q, p + 0x18);
    }
}

// FUN_004704D0
INCLUDE_ASM("asm/nonmatchings/sdkLbox", func_004704d0);

// FUN_00470970
INCLUDE_ASM("asm/nonmatchings/sdkLbox", func_00470970);


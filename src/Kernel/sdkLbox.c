/* Original translation unit sdkLbox.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_00453fa0();
extern s32 func_00453e60();
extern void func_004704d0();
extern void func_0046ea50();
extern void func_0046ea60();
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern void func_004535c0(u8 *a, s32 b, s32 c);
extern void func_00453860(u8 *a, s32 b, s32 c, s32 d, s32 e);
extern u8 D_00713118[];
extern void func_00442830(u8 *dst, u8 *src);
extern void func_00453c80(u8 *arg0);
extern s32 func_00453e10(u8 *arg0);
extern u8 D_00713128[];
extern void func_0046f2b0(u8 *arg0);
extern void func_00470210(u8 *arg0);

/* measured: `handle` must be declared before `mem`, exactly as in sdkWrap
   func_004672c0. With `mem` first, b210 colours arg0 into $s0 and mem into
   $s1 -- the mirror of retail -- and all 20 differing words are that swap
   (20 -> 3, the rest being window padding). Any order that puts `handle`
   ahead of `mem` works; the relative position of `vec` does not matter. */
// FUN_00470280
s32 func_00470280(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 handle;
    u8 *mem;
    u8 *vec;

    func_0044ea90(D_00713118, 0x299);
    mem = D_008873F4[0](1, 0x190, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    handle = func_00451fc0(arg0, D_00713128, 0x102, 0, 0, func_0046f2b0,
                           func_00470210, mem);
    *(s32 *)(mem + 0x18) = arg1;
    *(s32 *)(mem + 0x1C) = arg2;
    *(s32 *)(mem + 0x20) = 0x80;
    *(s32 *)(mem + 0x24) = 0x80;
    *(s32 *)(mem + 0x28) = 0xC;
    *(s32 *)(mem + 0x2C) = 0xC;
    *(s32 *)(mem + 0x13C) = 0xA;
    *(s32 *)(mem + 8) = arg3;
    vec = mem + 0x164;
    func_004535c0(vec, *(s32 *)(mem + 0x13C), 0);
    func_00453860(vec, 0x4000, 0x1000, 0, 0);
    return handle;
}

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

/* measured: nd 18, obj 288B == window 288B, and every one of those words is the
   SAME $s0/$s1 swap -- retail colours `work` into $s0 and the allocation into
   $s1, b210 does the reverse. Logic, frame, call sequence and the list-walk loop
   all match exactly.

   Unlike func_00470280 above (and sdkWrap func_004672c0, sdkUttmx func_00463d60),
   this mirror is NOT declaration-order drivable: node-first, p-first,
   work-last, and the initialised-declaration idiom this file uses elsewhere
   (`u8 *work = *(u8 **)(arg0 + 0x38);`) all score 18. Retail gives $s0 to the
   more heavily used of the two pointers; b210 gives it to whichever is assigned
   first, and no source ordering flips that here. Seven spellings.

   Note: do NOT #include "sdktask.h" in this file to reach `((SdkTask *)arg0)->work`
   -- it conflicts with the local declarations and breaks the whole TU.
   Saved-register colouring floor. */
// FUN_00470970 NONMATCHING
#ifdef NON_MATCHING
s32 func_00470970(u8 *arg0, u8 *arg1)
{
    u8 *work;
    u8 *node;
    s32 *p;

    work = *(u8 **)(arg0 + 0x38);
    func_0044ea90(D_00713118, 0x37D);
    node = D_008873F4[0](1, 0x22C, 0x40000);
    if (node == NULL) {
        func_0046d730(D_00713118, 0x37F);
    }
    func_00442830(node + 8, arg1);
    *(s32 *)(node + 4) = 0;
    *(s32 *)node = *(s32 *)(work + 0x148);
    *(s32 *)(work + 0x148) = *(s32 *)(work + 0x148) + 1;
    p = (s32 *)(work + 0x144);
    while (*p != 0) {
        *(s32 *)(node + 0x224) = *p;
        p = (s32 *)(*p + 0x228);
    }
    *p = (s32)node;
    *(s32 *)(work + 0x140) = *(s32 *)(work + 0x140) + 1;
    func_004704d0(arg0);
    func_00453c80(work + 0x164);
    *(s32 *)(work + 0x140) = func_00453e10(work + 0x164);
    return *(s32 *)node;
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkLbox", func_00470970);
#endif


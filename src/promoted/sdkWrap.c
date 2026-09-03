/* Consolidated Persona 4 source units. */
/* Original translation unit sdkWrap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(s32);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern void func_00440b68(const void *, ...);
extern u8 D_00712978[];
extern u8 D_007129E0[];
extern u8 D_00712A00[];
extern u8 D_007129A0[];
extern u8 D_007129C0[];
extern s32 func_004671c0(u8 *arg0);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void func_003ef3a0(s32 arg0);
extern void func_00454bd0(u8 *arg0);
extern void func_00466c60(void);
extern void func_00466e80(u8 *);

// FUN_00466C60
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_00466c60);
// FUN_00466E80
void func_00466e80(u8 *arg0)
{
    extern void func_00421700(void);
    extern void func_003eaa80(u8 *arg0);
    extern s32 func_003ef740(u8 *arg0, s32 arg1);
    extern u8 iGpffffb01c;
    extern u8 *func_003be180(s32 arg0);
    extern void func_003d60e0(u8 *arg0, s32 arg1);
    extern u8 D_0070B610[];
    extern s32 func_003c0f20(s32 arg0);
    extern s32 func_003d5330(u8 *arg0);
    extern s32 func_003e2910(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_00395290(s32 arg0);
    extern s32 func_003bba90(u8 *arg0);
    extern s32 func_003d6350(s32 arg0, s32 arg1);
    extern u8 *func_003e6a90(s32 arg0);
    extern s32 func_00464100(s32 arg0, s32 arg1);
    extern s32 func_003eaf60(u8 *arg0);
    extern s32 func_003bb210(s32 arg0);
    extern s32 func_0042ba20(void);
    extern void func_0042ba70(void);
    u8 *work;
    u8 *next;
    s32 lock;
    s16 status;

wait_start:
    for (;;) {
        func_00421700();
        status = *(s16 *)(arg0 + 0);
        switch (status) {
        case 0:
            goto wait;
        case 1:
            goto process;
        default:
            goto wait;
        }
    wait:
        ;
    }
process:
    for (;;) {
        work = *(u8 **)(arg0 + 4);
        switch (*(s32 *)(work + 0x1AC)) {
        case 0:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B4) =
                func_003ef740(*(u8 **)(arg0 + 4) + 0x24, 0);
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 1:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            *(u8 **)(*(u8 **)(arg0 + 4) + 0x10) =
                func_003be180(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 2:
            if (*(s8 *)(work + 0x124) != 0) {
                func_003eaa80(work + 0x124);
            }
            if (*(s32 *)(*(u8 **)(arg0 + 4) + 0x1CC) != 0) {
                func_003d60e0(D_0070B610, *(s32 *)(*(u8 **)(arg0 + 4) + 0x1CC));
            }
            *(s32 *)(*(u8 **)(arg0 + 4) + 0xC) =
                (s32)func_003c0f20(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 3:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x14) =
                func_003d5330(work + 0x24);
            break;
        case 4:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1BC) =
                func_003e2910(*(s32 *)(work + 8),
                              *(s32 *)(work + 0x1C4),
                              *(s32 *)(work + 0x1C0));
        case 5:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x18) =
                (s32)func_00395290(*(s32 *)(*(u8 **)(arg0 + 4) + 8));
            break;
        case 6:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C) =
                func_003bba90(work + 0x24);
            break;
        case 7:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C8) =
                func_003d6350(*(s32 *)(work + 0x20), *(s32 *)(work + 8));
            break;
        case 8:
            *(u8 **)(*(u8 **)(arg0 + 4) + 0x1D0) =
                func_003e6a90(*(s32 *)(work + 8));
            break;
        case 9:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B8) =
                func_00464100(*(s32 *)(work + 0x1C4), 0);
            break;
        case 10:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C4) =
                func_003eaf60(work + 0x24);
            break;
        case 11:
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1C) =
                func_003bb210(*(s32 *)(work + 8));
            break;
        }
        if (*(s32 *)(*(u8 **)(arg0 + 4) + 0x1B0) != 0) {
            lock = func_0042ba20();
            func_00454bd0(*(u8 **)(*(u8 **)(arg0 + 4) + 0x1B0));
            *(s32 *)(*(u8 **)(arg0 + 4) + 0x1B0) = 0;
            if (lock != 0) {
                func_0042ba70();
            }
        }
        lock = func_0042ba20();
        *(s32 *)(*(u8 **)(arg0 + 4) + 0x1A4) = 3;
        work = *(u8 **)(arg0 + 4);
        if (*(s32 *)(work + 0x1AC) != 8 &&
            *(s32 *)(work + 0x1AC) != 2) {
            next = *(u8 **)(work + 0);
            if (next != NULL &&
                *(s32 *)(next + 0x1A4) == 0 &&
                *(s8 *)(next + 0xA4) == 0) {
                *(s32 *)(next + 0x1A4) = 2;
                *(u8 **)(arg0 + 4) = next;
                if (lock != 0) {
                    func_0042ba70();
                }
                continue;
            }
        }
        *(s16 *)(arg0 + 0) = 0;
        if (lock == 0) {
            goto wait_start;
        }
        func_0042ba70();
        goto wait_start;
    }
}
/* The stream-close callback registered by func_004672c0. It sits inside the
   func_00466e80 verify window and is not in the retail function table, so its
   marker splits the window: 820B + padding, then this 200B callback. */
// FUN_004671C0
s32 func_004671c0(u8 *arg0)
{
    s32 count;
    u8 *work;
    s32 handle;

    work = *(u8 **)(arg0 + 0x38);
    handle = func_004669d0(*(s32 *)work, &count, 0);
    if (count != 0) {
        if (*(u8 **)(work + 4) != NULL) {
            func_00440b68(D_007129A0, *(u8 **)(work + 4) + 0x10);
        } else {
            func_00440b68(D_007129C0);
        }
        if (handle != 0) {
            func_003ef3a0(handle);
        }
        if (*(u8 **)(work + 4) != NULL) {
            func_00454bd0(*(u8 **)(work + 4));
        }
        *(s32 *)work = 0;
        *(u8 **)(work + 4) = NULL;
        return -1;
    }
    return 0;
}




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
                           (void (*)(u8 *))func_004671c0, func_00467290, mem);
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


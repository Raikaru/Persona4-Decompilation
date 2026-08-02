/* Consolidated Persona 4 source units. */
/* Original translation unit k_sequence.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern s32 func_00159e90(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00764334;

extern u8 *func_00155280(void);
extern s32 func_00155e10(s32 arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4,
                         s16 arg5, s32 arg6, u8 arg7, s64 arg8, s64 arg9,
                         s64 arg10, s64 arg11, s64 arg12, s64 arg13);
extern void func_0046d730(const char *file, s32 line);
extern s32 func_00452380(void *path);
extern void func_00452080(s32 handle);
extern s32 func_00452490(s32 buf);
extern void func_00187e80(s32 arg0, s32 arg1, s32 arg2);
extern void func_0018f3c0(s32 arg0);
extern void func_0018f700(s32 arg0);
extern void func_00190130(s32 arg0);
extern void func_0018dd40(s32 arg0);

extern char D_005F16F8[];
extern u8 D_005F1708[];
extern u8 D_005F1718[];
extern u8 D_005F1730[];
extern u8 D_005F1748[];
extern s32 D_00763028;
extern s32 D_00764434;

// FUN_00170220
void func_00170220(u8 *arg0)
{
    s32 temp;

    if (*(u16 *)(arg0 + 0) == 0) {
        func_0046d730(D_005F16F8, 0x38);
    }
    temp = func_00155e10(0, *(u16 *)(arg0 + 0), *(u16 *)(arg0 + 2),
                         *(u16 *)(arg0 + 4), *(s16 *)(arg0 + 6),
                         *(s16 *)(arg0 + 8), 0, 6, 0x80, 0, -1, -1, -1, -1);
    *(s32 *)func_00155280() = temp;
}

// FUN_001702C0
void func_001702c0(void)
{
    if (*(s32 *)func_00155280() != 0) {
        func_00452080(*(s32 *)func_00155280());
        *(s32 *)func_00155280() = 0;
    }
}

// FUN_00170310
s32 func_00170310(void)
{
    return func_00452490(*(s32 *)func_00155280()) == 1;
}

// FUN_00170350
void func_00170350(u8 *arg0)
{
    s32 temp;

    if (*(s32 *)(arg0 + 0xC) == 0) {
        func_0046d730(D_005F16F8, 0x69);
    }
    temp = func_00155e10(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, *(s32 *)(arg0 + 0xC),
                         *(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x14), 0);
    *(s32 *)func_00155280() = temp;
}

// FUN_001703F0
void func_001703f0(void)
{
    if (*(s32 *)func_00155280() != 0) {
        func_00452080(*(s32 *)func_00155280());
        *(s32 *)func_00155280() = 0;
    }
}

// FUN_00170440
s32 func_00170440(void)
{
    if (func_00452490(*(s32 *)func_00155280()) == 1) {
        return 1;
    }
    *(s32 *)func_00155280() = 0;
    return 0;
}

// FUN_001704A0
void func_001704a0(u8 *arg0)
{
    D_00764334 = func_00159e90(0, *(s32 *)(arg0 + 0), *(s32 *)(arg0 + 4));
}

// FUN_001704E0
void func_001704e0(void)
{
    if (D_00764434 != 0) {
        func_00452080(D_00764434);
        D_00764434 = 0;
        *(s32 *)func_00155280() = 0;
    }
}

// FUN_00170520
s32 func_00170520(void)
{
    if (func_00452490(D_00764434) == 1) {
        return 1;
    }
    D_00764434 = 0;
    return 0;
}

// FUN_00170570
void func_00170570(void)
{
    func_0018f3c0(0);
}

// FUN_001705A0
s32 func_001705a0(void)
{
    return func_00452380(D_005F1708) != 0;
}

// FUN_001705D0
void func_001705d0(void)
{
    s32 temp;

    temp = func_00452380(D_005F1708);
    if (temp == 0) {
        func_0046d730(D_005F16F8, 0xCB);
    }
    func_00452080(temp);
}

// FUN_00170630
void func_00170630(void)
{
    func_0018f700(0);
}

// FUN_00170660
s32 func_00170660(void)
{
    return func_00452380(D_005F1718) != 0;
}

// FUN_00170690
void func_00170690(void)
{
    s32 temp;

    temp = func_00452380(D_005F1718);
    if (temp == 0) {
        func_0046d730(D_005F16F8, 0xE8);
    }
    func_00452080(temp);
}

// FUN_001706F0
void func_001706f0(void)
{
    func_00190130(0);
}

// FUN_00170720
s32 func_00170720(void)
{
    return func_00452380(D_005F1730) != 0;
}

// FUN_00170750
void func_00170750(void)
{
    s32 temp;

    temp = func_00452380(D_005F1730);
    if (temp == 0) {
        func_0046d730(D_005F16F8, 0x105);
    }
    func_00452080(temp);
}

// FUN_001707B0
void func_001707b0(s32 *arg0)
{
    func_00187e80(0, *arg0, 0);
}

// FUN_001707E0
void func_001707e0(void)
{
    func_00187e80(0, 0, 1);
}

// FUN_00170810
s32 func_00170810(void)
{
    return func_00452380(&D_00763028) != 0;
}

// FUN_00170840
void func_00170840(void)
{
    s32 temp;

    temp = func_00452380(&D_00763028);
    if (temp == 0) {
        func_0046d730(D_005F16F8, 0x12B);
    }
    func_00452080(temp);
}

// FUN_001708A0
void func_001708a0(void)
{
    func_0018dd40(0);
}

// FUN_001708D0
s32 func_001708d0(void)
{
    return func_00452380(D_005F1748) != 0;
}

// FUN_00170900
void func_00170900(void)
{
    s32 temp;

    temp = func_00452380(D_005F1748);
    if (temp == 0) {
        func_0046d730(D_005F16F8, 0x14A);
    }
    func_00452080(temp);
}

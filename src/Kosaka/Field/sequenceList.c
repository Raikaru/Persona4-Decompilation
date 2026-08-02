#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit sequenceList.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00192e90(void);
extern void func_00193730(void);

extern s32 func_00103590(void);
extern s32 func_001039e0(void);
extern void func_0012c460(s32);
extern s32 func_00193700(void);
extern void func_002853b0(void);
extern s32 func_002853c0(void);
extern void func_0029e8d0(void *);
extern void func_002ac2a0(void);
extern s32 func_002bdb50(s32, s8);
extern s32 func_002e7510(s32);
extern s32 func_00311260(s32);
extern void func_0034b8c0(void);
extern s32 func_00452380(void *);
extern void func_00452080(s32);
extern void func_0046d730(const void *, u32);
extern s32 func_0046a110(s32, s16, void *);
extern void *func_0046a1e0(void);

extern char D_005DCB58[];
extern char D_005DCB68[];
extern char D_005DCB80[];
extern char D_005DCB98[];
extern char D_005DCBB0[];
extern char D_005DCBC0[];
extern char D_005DCBD0[];
extern char D_005DCBE8[];
extern char D_005DCC00[];
extern char D_00763A30[];
extern char D_007963A0[];
extern char D_007616B0;



// FUN_00102BE0
void func_00102be0(void)
{
    s32 handle = func_00452380(D_005DCB58);

    if (handle != 0) {
        if (handle == 0) {
            func_0046d730(D_005DCB68, 0x56);
        }
        func_00452080(handle);
    }
}

// FUN_00102C50
void func_00102c50(void)
{
    func_0012c460(0);
}

// FUN_00102C80
s32 func_00102c80(void)
{
    return (s32)(func_00452380(D_005DCB80) != 0);
}

// FUN_00102CB0
void func_00102cb0(void)
{
    s32 handle = func_00452380(D_005DCB80);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x74);
    }
    func_00452080(handle);
}

// FUN_00102D10
void func_00102d10(void)
{
    func_00103590();
}

// FUN_00102D30
s32 func_00102d30(void)
{
    return (s32)(func_00452380(D_005DCB98) != 0);
}

// FUN_00102D60
void func_00102d60(void)
{
    s32 handle = func_00452380(D_005DCB98);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x95);
    }
    func_00452080(handle);
}

// FUN_00102DC0
void func_00102dc0(void)
{
    func_001039e0();
}

// FUN_00102DE0
s32 func_00102de0(void)
{
    return (s32)(func_00452380(&D_007616B0) != 0);
}

// FUN_00102E10
void func_00102e10(void)
{
    s32 handle = func_00452380(&D_007616B0);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0xB2);
    }
    func_00452080(handle);
}

// FUN_00102E70
void K_Fldrc_DestroyArchives(void)
{
    func_00192e90();
    func_00193730();
}

// FUN_00102EA0
s32 func_00102ea0(void)
{
    return (s32)(func_00193700() != 0);
}

// FUN_00102ED0
void func_00102ed0(void)
{
    s32 handle = func_00193700();

    if (handle != 0) {
        func_00452080(handle);
    }
}

// FUN_00102F10
void func_00102f10(void)
{
    if (func_00452380(D_005DCBB0) == 0) {
        func_0029e8d0(0);
    }
}

// FUN_00102F50
s32 func_00102f50(void)
{
    return (s32)(func_00452380(D_005DCBB0) != 0);
}

// FUN_00102F80
void func_00102f80(void)
{
    s32 handle = func_00452380(D_005DCBB0);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x145);
    }
    func_00452080(handle);
}

// FUN_00102FE0
void func_00102fe0(void)
{
    if (func_002853c0() == 0) {
        func_002853b0();
    }
}

// FUN_00103010
s32 func_00103010(void)
{
    return (s32)(func_002853c0() != 0);
}

// FUN_00103040
void func_00103040(void)
{
    s32 handle = func_002853c0();

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x165);
    }
    func_00452080(handle);
}

// FUN_001030A0
void func_001030a0(void)
{
    func_002ac2a0();
}

// FUN_001030C0
s32 func_001030c0(void)
{
    return (s32)(func_00452380(D_005DCBC0) != 0);
}

// FUN_001030F0
void func_001030f0(void)
{
    s32 handle = func_00452380(D_005DCBC0);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x180);
    }
    func_00452080(handle);
}

// FUN_00103150
void func_00103150(void)
{
    func_0034b8c0();
}

// FUN_00103170
s32 func_00103170(void)
{
    return (s32)(func_00452380(D_00763A30) != 0);
}

// FUN_001031A0
void func_001031a0(void)
{
    s32 handle = func_00452380(D_00763A30);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x19B);
    }
    func_00452080(handle);
}

// FUN_00103200
void func_00103200(void)
{
    func_002bdb50(0, 0);
}

// FUN_00103230
s32 func_00103230(void)
{
    return (s32)(func_00452380(D_005DCBD0) != 0);
}

// FUN_00103260
void func_00103260(void)
{
    s32 handle = func_00452380(D_005DCBD0);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x1B8);
    }
    func_00452080(handle);
}

// FUN_001032C0
void func_001032c0(void)
{
    func_002e7510(0);
}

// FUN_001032F0
s32 func_001032f0(void)
{
    return (s32)(func_00452380(D_005DCBE8) != 0);
}

// FUN_00103320
void func_00103320(void)
{
    s32 handle = func_00452380(D_005DCBE8);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x1D7);
    }
    func_00452080(handle);
}

// FUN_00103380
void func_00103380(void)
{
    func_00311260(0);
}

// FUN_001033B0
s32 func_001033b0(void)
{
    return (s32)(func_00452380(D_005DCC00) != 0);
}

// FUN_001033E0
void func_001033e0(void)
{
    s32 handle = func_00452380(D_005DCC00);

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x1F3);
    }
    func_00452080(handle);
}

// FUN_00103440
void func_00103440(s16 *arg0)
{
    func_0046a110(0, *arg0, &D_007963A0);
}

// FUN_00103480
s32 func_00103480(void)
{
    return (s32)(func_00452380(func_0046a1e0()) != 0);
}

// FUN_001034B0
void func_001034b0(void)
{
    s32 handle = func_00452380(func_0046a1e0());

    if (handle == 0) {
        func_0046d730(D_005DCB68, 0x20F);
    }
    func_00452080(handle);
}

#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit calendar.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00452380();
extern u8 D_005E4FE8[];
extern u8 D_005E4FD8[];

extern s32 D_007242B4;
extern s32 D_007242B0;
extern s32 D_007242B8;
extern u8 D_005E4FF8[];
extern u8 D_005E5038[];
extern u8 D_005E5050[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern s32 func_00451fc0(s32 a, void *b, s32 c, s32 d, s32 e, void *init, void *close, void *buf);
extern void func_00120f70();
extern void func_00121170();
extern void func_001211a0();
extern s32 func_00121690(void);
extern s32 func_001104a0(s32 arg0);
extern void func_001104d0(s32 arg0, void *arg1, void *arg2);
extern s32 func_001060c0(void);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern void func_00122520(s32 a, s32 b);
extern void func_00106100(s32 a);
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern void func_00123850(void);
extern s32 func_00144af0(s32 a);
extern s32 func_004522d0(s32 a);
extern void func_001062f0(s32 a);



// FUN_001211B0
void func_001211b0(void)
{
    u8 *work;
    s32 handle;

    D_007242B8 = 0;
    func_0044ea90(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = func_00451de0(D_005E4FE8, 0x100, 0, 0, func_00120f70, func_00121170, work);
        D_007242B0 = (s32)work;
        func_00451fc0(handle, D_005E4FF8, 0x101, 0, 0, func_001211a0, NULL, NULL);
    }
}

// FUN_00121280
s32 func_00121280(void)
{
    return (s32)(func_00452380(D_005E4FE8) != 0);
}

// FUN_001212B0
void func_001212b0(void)
{
    s32 handle = func_00452380(D_005E4FE8);

    if (handle == 0) {
        func_0046d730(D_005E4FD8, 0xA8);
    }
    func_00452080(handle);
}

// FUN_00121310
s32 func_00121310(void *arg0)
{
    s32 sp3C;
    s32 sp38;
    u8 *work;
    s32 state;
    s32 v;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)(work + 8) = 0;
        *(s32 *)(work + 4) = 1;
        *(s32 *)(work + 0) = 1;
        break;
    case 1:
        if (D_008C0276[0] & 0x40) {
            func_00122520(1, 1);
            func_00106100((s16)*(s32 *)(work + 8));
            func_001029a0(0x1A, NULL, 0, 0);
            return -1;
        }
        if (D_008C0276[0] & 0x800) {
            func_00106100((s16)*(s32 *)(work + 8));
            func_00123850();
            *(s32 *)(work + 0xC) = func_00144af0((s32)arg0);
            *(s32 *)(work + 0) = 4;
        } else if (D_008C027A[0] & 0x1000) {
            v = *(s32 *)(work + 8);
            if (v < 7) {
                *(s32 *)(work + 8) = 0;
            } else {
                *(s32 *)(work + 8) = v - 7;
            }
        } else if (D_008C027A[0] & 0x4000) {
            v = *(s32 *)(work + 8);
            if (v > 0x165) {
                *(s32 *)(work + 8) = 0x16C;
            } else {
                *(s32 *)(work + 8) = v + 7;
            }
        } else if (D_008C027A[0] & 0x8000) {
            v = *(s32 *)(work + 8);
            if (v != 0) {
                *(s32 *)(work + 8) = v - 1;
            }
        } else if (D_008C027A[0] & 0x2000) {
            v = *(s32 *)(work + 8);
            if (v != 0x16C) {
                *(s32 *)(work + 8) = v + 1;
            }
        } else if (D_008C027A[0] & 0x4) {
            if ((func_001060c0() & 0xFF) == 0) {
                func_001062f0(5);
            } else {
                func_001062f0(((func_001060c0() & 0xFF) - 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x8) {
            if ((func_001060c0() & 0xFF) == 5) {
                func_001062f0(0);
            } else {
                func_001062f0(((func_001060c0() & 0xFF) + 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x1) {
            func_001104d0(*(s32 *)(work + 8), &sp3C, &sp38);
            if (sp3C != 4) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) - (func_001104a0(sp3C) - 1);
            }
        } else if (D_008C027A[0] & 0x2) {
            func_001104d0(*(s32 *)(work + 8), &sp3C, &sp38);
            if (sp3C != 3) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) + func_001104a0(sp3C);
            }
        }
        break;
    case 4:
        if (func_004522d0(*(s32 *)(work + 0xC)) == 3) {
            *(s32 *)(work + 0) = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00121660
void func_00121660(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B4 = 0;
    jtbl_008873EC[0](p);
}

/* measured: retail calendar func_00121690. Frame/stack layout (0x80, color@0x74,
   dim@0x50, pos@0x68) matched exactly via a union{ f32 f[2]; s64 x; } for the
   sp68/sp6C pair (the `ld $a0,0x68` 8-byte read forces 8-byte alignment; separate
   f32s or a struct put it at 0x60). nd 117->62. Residual: persistent saved-register
   rotation (work=$s2 vs retail $s1, var_18=$s3 vs $s2, temp_2=$s1 vs $s0,
   var_19=$s0 vs $s3) that no declaration-order permutation fixes, plus the func_
   00450dd0 loop call emits an extra $a3 (4-arg vs 5-arg signature) and the
   var_18+=1 / slti order in the loop. func_00450dd0 is (s64,void*,s32,s32,f32). */
// FUN_00121690
INCLUDE_ASM("asm/nonmatchings/calendar", func_00121690);

// FUN_00121940
s32 func_00121940(void)
{
    s32 handle;
    u8 *work;

    func_0044ea90(D_005E4FD8, 0x164);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = func_00451de0(D_005E5038, 0x100, 0, 0, func_00121310, func_00121660, work);
    D_007242B4 = (s32)work;
    func_00451fc0(handle, D_005E5050, 0x101, 0, 0, func_00121690, NULL, NULL);
    return handle;
}

// FUN_00121A20
void func_00121a20(void)
{
    u8 *work;
    s32 handle;

    D_007242B8 = 1;
    func_0044ea90(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = func_00451de0(D_005E4FE8, 0x100, 0, 0, func_00120f70, func_00121170, work);
        D_007242B0 = (s32)work;
        func_00451fc0(handle, D_005E4FF8, 0x101, 0, 0, func_001211a0, NULL, NULL);
    }
}
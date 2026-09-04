/* Original translation unit k_field.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

extern s32 iGpffffb20c;
extern s32 iGpffffb2e4;
extern u8 *iGpffff9db0;
extern s32 D_007E8060[];
extern u8 D_007E80A0[];
extern s32 D_007D2510[];

#define KFIELD_D_007D2540 (*(s32 *)0x007D2540)
#define KFIELD_D_007E8060 (D_007E8060)
#define KFIELD_D_007E80A0 (D_007E80A0)
#define KFIELD_D_007D2510 (D_007D2510)
#define KFIELD_JTBL_008873EC (*(void (**)(s32))((u8 *)0x00880000 + 0x73EC))

extern void func_00123ac0(void);
extern void func_00167530(void);
extern void func_002bd410(void);
extern void func_002bd3e0(void);
extern void func_00149690(s32);
extern void func_00452080(s32);
extern void func_00151f80(s32);
extern s32 func_00102980(void);
extern void func_001622d0(void);
extern void func_00164170(void);
extern void func_001641d0(void);
extern void func_0043f9c8(void *, s32, s32);
extern void func_00156750(u8 *);
extern u8 *func_00457120(void);
extern void func_003e9df0(s32);

// FUN_00155360
INCLUDE_ASM("asm/nonmatchings/k_field", func_00155360);

/* measured: func_00155bf0 now matches at normalized_diff 0 (object 540B/window 544B); spelling the second range as <= 0x1E makes MWCCPS2 use the retail $at branch temporary, with the same trailing window nop. */
// Committed at nd 0.
// FUN_00155BF0
void func_00155bf0(u8 *arg0)
{
    u8 *temp_17;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_16;
    s32 *temp_20;
    s32 *temp_2;
    s32 var_18;

    temp_17 = *(u8 **)(arg0 + 0x38);
    if (iGpffffb20c == 1) {
        func_00123ac0();
    }
    func_00167530();
    func_002bd410();
    func_002bd3e0();
    KFIELD_D_007D2540 = 0;
    func_00149690(0);
    temp_4 = *(s32 *)(temp_17 + 0x3C);
    if (temp_4 != 0) {
        func_00452080(temp_4);
        var_18 = 0;
        while (var_18 < 0x10) {
            temp_16 = var_18 * 4;
            temp_20 = (s32 *)KFIELD_D_007E8060 + var_18;
            temp_4_2 = *temp_20;
            if (temp_4_2 != 0) {
                func_00151f80(temp_4_2);
                *temp_20 = 0;
                *(s32 *)(iGpffff9db0 + temp_16 + 0x28) = 0;
            }
            var_18 += 1;
        }
    }
    if (func_00102980() != 9 &&
        func_00102980() != 0xB &&
        func_00102980() != 0xA) {
        func_001622d0();
    }
    if ((u16)*(u16 *)(temp_17 + 0x18) < 0x15) {
        goto field_special;
    }
    if (*(u16 *)(temp_17 + 0x18) <= 0x1E) {
        goto field_call;
    }
field_special:
    if (*(u16 *)(temp_17 + 0x18) != 6) {
        goto field_done;
    }
    if (*(u16 *)(temp_17 + 0x1A) != 1) {
        goto field_done;
    }
field_call:
    func_001622d0();
field_done:
    func_00164170();
    func_001641d0();
    func_0043f9c8(KFIELD_D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    func_00156750(arg0);
    temp_16 = 0;
    while (temp_16 < 3) {
        temp_2 = (s32 *)KFIELD_D_007D2510 + temp_16;
        temp_4_3 = *(s32 *)((u8 *)temp_2 + 0x34);
        if (temp_4_3 != 0) {
            func_00452080(temp_4_3);
            *(s32 *)((u8 *)temp_2 + 0x34) = 0;
        }
        temp_16 += 1;
    }
    func_003e9df0(*(s32 *)(func_00457120() + 4));
    KFIELD_JTBL_008873EC(*(s32 *)(arg0 + 0x38));
}

extern void func_00451b70(void);
extern u8 *D_007D3D64[];
extern u8 D_005EFF10[];
extern u8 D_005EFF48[];
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern void func_00149680(s32 arg0);
extern s32 func_00293ed0(s32 a, s32 b, s32 c, s32 d);
extern void func_0029ddb0(s32 arg0);
extern void func_0014eed0(u16 arg0, u16 arg1);
extern u8 D_007D255A[];
extern u8 D_007D255B[];
extern s32 D_007D255C[];
typedef struct { f32 x; f32 y; f32 z; } KFieldVec3;
extern s64 D_005EFF38[];
extern f32 D_005EFF40[];
extern void func_003e0380(f32 *arg0);
extern void func_003e03e0(void *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern void func_00155360(u8 *arg0);
/* measured: object 648B/window 656B, nd 0. The six stack parameters are s64
   slots read in place through `*(s32 *)&argN` / `*(u8 *)&arg8`: an s32
   stack parameter with several uses gets homed into $s2 at entry and pushes
   the u8 register parameter out to a byte spill, while the address-taken
   slot reads are plain lw/lbu every time exactly as retail reloads them.
   Register parameters colour $s1,$s4,$s3,$s2,$s5-$s8 with the work pointer in
   $s0 and the handle reusing $s1. The camera position constant is copied as
   an s64 + f32 scalar pair (two lui, both loads before both stores, which
   needs opt_propagation off) into a Vec3 local that is then assigned as a
   12-byte aggregate (three lwc1 then three swc1). func_0014eed0 takes the
   two u16 parameters unmasked. */
// FUN_00155E10
/* measured: opt_propagation off keeps the scalar-pair copy's two loads ahead
   of its two stores. */
#pragma opt_propagation off
s32 func_00155e10(u8 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, s32 arg6, u8 arg7,
                  s64 arg8, s64 arg9, s64 arg10, s64 arg11, s64 arg12, s64 arg13)
{
    f32 matrix[4];
    KFieldVec3 pos;
    s32 handle;
    u8 *work;
    s64 copy_s64;
    f32 copy_f32;
    u8 *cam;

    func_00451b70();
    if (D_007D3D64[0] != NULL) {
        KFIELD_JTBL_008873EC((s32)D_007D3D64[0]);
    }
    func_0043f9c8(D_007D2510, 0, 0x18DC);
    func_0044ea90(D_005EFF10, 0x2AF);
    work = D_008873F4[0](1, 0xF4, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = func_00451fc0(arg0, D_005EFF48, 0xF, 0, 0, func_00155360, func_00155bf0, work);
    D_007D2510[0] = handle;
    func_00149680(0);
    if (*(s32 *)&arg10 > 0) {
        *(s32 *)(work + 0x3C) = func_00293ed0(*(s32 *)&arg10, *(s32 *)&arg11, *(s32 *)&arg12, *(s32 *)&arg13);
        *(s32 *)(work + 0) = 0;
        *(s32 *)(work + 0xC) = *(s32 *)&arg10;
        *(s32 *)(work + 0x10) = *(s32 *)&arg11;
        *(s32 *)(work + 0x14) = *(s32 *)&arg12;
    } else {
        func_0029ddb0(*(s32 *)&arg10);
        *(u16 *)(work + 0x18) = arg1;
        *(u16 *)(work + 0x1A) = arg2;
        *(s16 *)(work + 0x20) = arg4;
        *(s16 *)(work + 0x22) = arg5;
        *(u16 *)(work + 0x1C) = arg3;
        *(s32 *)(iGpffff9db0 + 0x88) = arg6;
        D_007D255A[0] = arg7;
        D_007D255B[0] = *(u8 *)&arg8;
        D_007D255C[0] = *(s32 *)&arg9;
        func_0014eed0(arg1, arg2);
        *(s32 *)(work + 0) = 1;
    }
    copy_s64 = D_005EFF38[0];
    copy_f32 = D_005EFF40[0];
    *(s64 *)&pos.x = copy_s64;
    pos.z = copy_f32;
    func_003e9df0(*(s32 *)(func_00457120() + 4));
    cam = *(u8 **)(func_00457120() + 4);
    *(KFieldVec3 *)(cam + 0x40) = pos;
    func_003e0380(matrix);
    func_003e03e0(*(u8 **)(func_00457120() + 4) + 0x10, matrix);
    func_003e9680(*(u8 **)(func_00457120() + 4));
    return handle;
}

/* measured: closes the propagation bracket; the unit default is on. */
#pragma opt_propagation on

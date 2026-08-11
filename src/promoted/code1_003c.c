#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])();
extern void *(*D_008873F8[])(s32 arg0, s32 arg1);
extern void func_003e3b70(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern void func_003bf320();
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003c5760(u8 *arg0);
extern s32 func_003c2bd0(u8 *arg0);
extern s32 func_003c4c00(u8 *arg0);
extern s32 func_003c4a80(u8 *arg0, s32 arg1);
extern s32 func_003c4bc0(u8 *arg0, s32 arg1);
extern u8 *func_003c2290(u8 *arg0, s32 arg1);
extern u8 *func_003c49a0(u8 *arg0);
extern void func_003ce2e0(u8 *arg0);
extern s32 func_003c2c90(u8 *arg0);
extern s32 func_003e3370(u8 *desc, u8 *arg1);
extern s32 func_003e1220();
extern s32 func_003e3c20(u8 *desc, u8 *arg1);
extern s32 func_003e3070(u8 *desc, s32 arg0, s32 arg1);
extern s32 func_003e30c0(u8 *desc, s32 arg0, s32 arg1);
extern s32 func_003e3830(u8 *desc, s32 arg0);
extern s32 func_003c3cc0(u8 *arg0);
extern u8 *func_003c8200(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_003c5fd0(u8 *arg0, u8 *arg1);
extern void func_003ce840(u8 *arg0);
extern s32 func_003ce3a0(s32 arg0, u8 *arg1);
extern s32 func_003ce9e0(s32 arg0, u8 *arg1);
extern s32 func_003ceeb0(u8 *arg0);
/* gp - 0x5568 = 0x00763B88 */
extern s32 iGpffffaa98;
/* gp - 0x5564 = 0x00763B8C */
extern s32 iGpffffaa9c;
extern u8 D_00886550[];

typedef struct { f32 x, y, z, w; } Vec4f;
typedef struct { u8 pad[0x54]; s32 field; } Cb720Obj;

extern u16 D_008872E8[];
extern u8 func_003cac30[];
extern u8 func_003caef0[];
extern u8 D_0070AFB0[];
extern u8 D_008872E0[];
/* gp - 0x4648 = 0x00764aa8 */
extern u8 D_0070B020[];
extern u8 *(*D_0070B030)(u8 *arg0, s32 arg1);
extern s32 D_0070B034;
extern u8 *func_003c8920(u8 *arg0, s32 arg1);
extern s32 iGpffffb9b8;
extern s32 iGpffffb9b0;
extern s32 func_00410a40(s32 arg0);
extern s32 func_00410ab0(s32 arg0, s32 arg1);
extern void func_00411670(s32 arg0);
/* gp - 0x48F8 = 0x007647f8 */
extern s32 iGpffffb708;
extern s64 iGpffffb8f0;
/* gp - 0x48F4 = 0x007647fc */
extern s32 iGpffffb70c;
/* gp - 0x4938 = 0x007647b8 */
extern s32 iGpffffb6c8;
/* gp - 0x4934 = 0x007647bc */
extern s32 iGpffffb6cc;
/* gp - 0x494C = 0x007647A4 */
extern s32 iGpffffb6b4;
/* gp - 0x4950 = 0x007647A0 */
extern s32 iGpffffb6b0;
/* gp - 0x48EC = 0x00764804 */
extern s32 iGpffffb714;
/* gp - 0x48E4 = 0x0076480C */
extern s32 iGpffffb71c;
/* gp - 0x4910 = 0x007647e0 */
extern u8 *iGpffffb6f0;
/* gp - 0x4940 = 0x007647B0 */
extern s32 iGpffffb6c0;
extern void func_003e9680(u8 *arg0);
extern u8 func_003ca740[];
extern u8 func_003ca780[];
extern u8 func_003ca7a0[];
u8 *func_003cbc10(u8 *arg0, u8 *arg1);
void func_003f32d0();
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern void (*jtbl_008873E8[])(u8 *arg0, s32 arg1);
/* gp - 0x4930 = 0x007647c0 */
extern s32 iGpffffb6d0;
/* gp - 0x492C = 0x007647c4 */
extern s32 iGpffffb6d4;
/* gp - 0x4920 = 0x007647d0 */
extern s32 iGpffffb6e0;
/* gp - 0x491C = 0x007647d4 */
extern s32 iGpffffb6e4;
/* gp - 0x4918 = 0x007647d8 */
extern u8 *iGpffffb6e8;
/* gp - 0x48e8 = 0x00764808 */
extern u8 *iGpffffb718;
/* gp - 0x490C = 0x007647e4 */
extern s32 iGpffffb6f4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern s32 func_003c3890(u8 *arg0);
extern u8 D_0070AFD0[];
extern u8 D_0070AFF0[];
extern u8 *func_003c9c20(u32 arg0);
extern u8 *func_003c9640(u8 *arg0);
extern u8 D_0070AF70[];
extern u8 D_0070B040[];
extern u8 D_008872E4[];
extern s32 func_003c5a90(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3);
extern void func_003cbde0(u8 *arg0, void (*arg1)(u8 *), u8 *arg2);
extern void func_003c8dd0(u8 *arg0);
extern u8 *func_003cbc90(u8 *arg0, u8 *arg1);
extern void func_003cbe80(u8 *arg0, u8 *arg1);
extern u8 D_0070AF90[];
extern u8 D_0070B060[];
extern s32 func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_003efd20(u8 *arg0, u8 *arg1);
extern s32 func_003e3020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern s32 D_007647CC;
extern s32 D_007647C8;


extern s32 D_007647BC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */


// FUN_003C0050
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0050);
// FUN_003C00E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c00e0);
// FUN_003C0210
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0210);
// FUN_003C02E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c02e0);
// FUN_003C03A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c03a0);
// FUN_003C0520
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0520);
/* measured: schedule on preserves the allocator and initializer delay slots. */
#pragma schedule on
/* measured: no_branch_likely on preserves the plain allocator null branch. */
#pragma no_branch_likely on
// FUN_003C0640
u8 *func_003c0640(void) {
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_6;
    u8 *temp_7;

    temp_2 = (u8 *)D_008873F8[0](*(s32 *)(D_008872E0 + iGpffffb6c0 + 4), 0x30010);
    if (temp_2 != NULL) {
        *(s8 *)(temp_2 + 0) = 2;
        temp_7 = temp_2 + 8;
        *(s8 *)(temp_2 + 1) = 0;
        *(s8 *)(temp_2 + 2) = 0;
        temp_6 = temp_2 + 0x10;
        *(s8 *)(temp_2 + 3) = 0;
        temp_3 = temp_2 + 0x18;
        *(s32 *)(temp_2 + 4) = 0;
        *(u8 **)(temp_2 + 8) = temp_7;
        *(u8 **)(temp_2 + 0xC) = temp_7;
        *(u8 **)(temp_2 + 0x10) = temp_6;
        *(u8 **)(temp_2 + 0x14) = temp_6;
        *(u8 **)(temp_2 + 0x18) = temp_3;
        *(u8 **)(temp_2 + 0x1C) = temp_3;
        *(s32 *)(temp_2 + 0x24) = 0;
        *(s32 *)(temp_2 + 0x20) = 0;
        *(u8 **)(temp_2 + 0x28) = (u8 *)func_003bf320;
        func_003e3b70(D_0070AF90, temp_2, temp_6, temp_7);
        return temp_2;
    }
    return temp_2;
}
/* measured: no_branch_likely off closes allocator null-branch probe. */
#pragma no_branch_likely off
/* measured: schedule off closes allocator and initializer delay-slot probe. */
#pragma schedule off
// FUN_003C0700
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0700);
/* measured: schedule on probes retail's load/store order for the linked node. */
#pragma schedule on
// FUN_003C0850
u8 *func_003c0850(u8 *arg0, u8 *arg1) {
    u8 *result;
    u8 *next;
    u8 *link;
    u8 *temp_6;

    result = arg0;
    next = *(u8 **)(arg0 + 8);
    link = arg0 + 8;
    temp_6 = arg1 + 0x40;
    *(u8 **)(arg1 + 0x40) = next;
    *(u8 **)(arg1 + 0x44) = link;
    next = *(u8 **)(arg0 + 8);
    *(u8 **)(next + 4) = temp_6;
    *(u8 **)(arg0 + 8) = temp_6;
    *(u8 **)(arg1 + 0x3C) = arg0;
    return result;
}
/* measured: schedule off closes the linked-node order probe. */
#pragma schedule off
/* measured: schedule on places the linked-list clear in the jr delay slot. */
#pragma schedule on
// FUN_003C0880
s32 func_003c0880(s32 arg0, s32 arg1) {
    u8 *temp;
    u8 *next;
    u8 *prev;

    temp = (u8 *)(arg1 + iGpffffb6b4);
    next = *(u8 **)(temp + 4);
    prev = *(u8 **)(temp + 8);
    *(u8 **)(prev + 0) = next;
    next = *(u8 **)(temp + 8);
    prev = *(u8 **)(temp + 4);
    *(u8 **)(prev + 4) = next;
    *(s32 *)(temp + 8) = 0;
    *(s32 *)(temp + 4) = 0;
    *(s32 *)(temp + 0) = 0;
    return arg0;
}
/* measured: schedule off closes the linked-list clear probe. */
#pragma schedule off
/* measured: schedule on places the linked-list clear in the jr delay slot. */
#pragma schedule on
// FUN_003C08C0
s32 func_003c08c0(s32 arg0, s32 arg1) {
    u8 *temp;
    u8 *next;
    u8 *prev;

    temp = (u8 *)(arg1 + iGpffffb6b0);
    next = *(u8 **)(temp + 4);
    prev = *(u8 **)(temp + 8);
    *(u8 **)(prev + 0) = next;
    next = *(u8 **)(temp + 8);
    prev = *(u8 **)(temp + 4);
    *(u8 **)(prev + 4) = next;
    *(s32 *)(temp + 8) = 0;
    *(s32 *)(temp + 4) = 0;
    *(s32 *)(temp + 0) = 0;
    return arg0;
}
/* measured: schedule off closes the linked-list clear probe. */
#pragma schedule off
/* measured: schedule on probes the two-call saved-register order. */
#pragma schedule on
// FUN_003C0900
s32 func_003c0900(u8 *arg0) {
    s32 total;
    u8 *self;

    total = 0x1C;
    self = arg0;
    total += func_003c2c90(*(u8 **)(arg0 + 0x18)) + 0xC;
    return total + (func_003e3370(D_0070AF70, self) + 0xC);
}
/* measured: schedule off closes the two-call saved-register probe. */
#pragma schedule off
// FUN_003C0960
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0960);
// FUN_003C0F20
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c0f20);
// FUN_003C1AB0
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c1ab0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070AF70, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
#pragma schedule off
// FUN_003C1AE0
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c1ae0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070AF90, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c1ae0; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003C1B10
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c1b10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070AF70, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c1b10; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003C1B40
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c1b40(s32 arg0, s32 arg1) {
    return func_003e3070(D_0070AF70, arg0, arg1);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C1B60
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c1b60(s32 arg0, s32 arg1) {
    return func_003e30c0(D_0070AF70, arg0, arg1);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C1B80
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c1b80(s32 arg0) {
    return func_003e3830(D_0070AF70, arg0);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C1B90
/* measured: schedule moves the saved object into the call delay slot. */
#pragma schedule on
u8 *func_003c1b90(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    u8 flag;
    p = arg0;
    func_003efd20(p, arg1);
    flag = p[3];
    flag |= 1;
    p[3] = flag;
    return p;
}
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C1BD0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c1bd0);
/* measured: schedule on and no_branch_likely on reproduce the saved self,
   plain null branch, and final callback order. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C1C70
s32 func_003c1c70(u8 *arg0) {
    u8 *self;
    u8 *temp;

    self = arg0;
    *(s16 *)(arg0 + 0xE) += 1;
    func_003c2290(arg0, 0xFFF);
    func_003e3c20(D_0070AFB0, self);
    temp = *(u8 **)(self + 0x5C);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(self + 0x5C) = NULL;
    }
    func_003c49a0(self + 0x20);
    *(s16 *)(self + 0xE) -= 1;
    jtbl_008873EC[0](self);
    return 1;
}
/* measured: no_branch_likely off closes the callback null-test probe. */
#pragma no_branch_likely off
/* measured: schedule off closes the saved-self callback probe. */
#pragma schedule off
// FUN_003C1D00
/* measured: schedule places the increment store in the return delay slot. */
#pragma schedule on
s32 func_003c1d00(s32 arg0, s32 arg1) {
    iGpffffb6c8 = arg1;
    iGpffffb6cc += 1;
    return arg0;
}
#pragma schedule off
// FUN_003C1D20
#pragma schedule on
s32 func_003c1d20(s32 arg0) {
    D_007647BC--;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 13 -> 0). */

// FUN_003C1D40
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c1d40);
// FUN_003C1EA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c1ea0);
// FUN_003C2130
#pragma schedule on
s32 func_003c2130(s32 arg0, u8 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    ((s16 *)arg1)[0] = arg2;
    ((s16 *)arg1)[1] = arg3;
    ((s16 *)arg1)[2] = arg4;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colors the halfword scratch $v0; retail fills the slot
   with the final store and colors it $v1 (nd 15 -> 0). */

/* measured: schedule on fills the jr $ra delay slot (nd 6 without it), and
   no_branch_likely on stops b210 emitting beql where retail has a plain
   beqz on the null test. */

/* measured: schedule on and no_branch_likely on reproduce the saved
   arguments, plain sign branches, and shared store/return path. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C2150
s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 result;
    u16 value;

    if (arg2 == 0) {
        goto noarg;
    }
    result = func_003c4bc0(arg0 + 0x20, arg2);
    if (result < 0) {
        goto fallback;
    }
store:
    *(s16 *)(arg1 + 6) = result;
return_path:
    return (s32)arg0;
fallback:
    result = func_003c4a80(arg0 + 0x20, arg2);
    if (result >= 0) {
        goto store;
    }
    return 0;
noarg:
    value = 0xFFFFu;
    *(u16 *)(arg1 + 6) = value;
    goto return_path;
}
/* measured: no_branch_likely off closes the signed-result branch probe. */
#pragma no_branch_likely off
/* measured: schedule off closes the saved-arguments probe. */
#pragma schedule off
// FUN_003C21E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c21e0);
// FUN_003C2290
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c2290(u8 *arg0, s32 arg1) {
    u8 *temp;

    *(u16 *)(arg0 + 0xC) |= (u16)(arg1 & 0xFFFF);
    if (arg1 & 1) {
        temp = *(u8 **)(arg0 + 0x54);
        if (temp != NULL) {
            func_003c5760(temp);
            *(s32 *)(arg0 + 0x54) = 0;
        }
    }
    return arg0;
}
#pragma no_branch_likely off
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled and drops the store out of it: MISMATCH nd 15, object 24 bytes in
   a 32-byte window. With it the function matches. */

// FUN_003C22F0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c22f0);

// FUN_003C2630
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2630);
// FUN_003C2A60
#pragma schedule on
u8 *func_003c2a60(u8 *arg0) {
    ((s16 *)arg0)[7] = (s16)(((s16 *)arg0)[7] + 1);
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 11 -> 0). */

// FUN_003C2A80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2a80);
// FUN_003C2B70
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c2b70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070AFB0, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
#pragma schedule off
// FUN_003C2BA0
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c2ba0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070AFB0, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c2ba0; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003C2BD0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2bd0);
// FUN_003C2C90
/* measured: schedule on fills the four jal/jr delay slots; without it the
   object is 104 bytes against a 96-byte window (nd 58). */
#pragma schedule on
s32 func_003c2c90(u8 *arg0) {
    s32 total;

    total = func_003c2bd0(arg0) + 0xC;
    total += func_003c4c00(arg0 + 0x20) + 0xC;
    return total + (func_003e3370(D_0070AFB0, arg0) + 0xC);
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003C2CF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2cf0);
// FUN_003C30B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c30b0);
// FUN_003C3890
/* measured: tailcall on reproduces the direct helper jump. */
#pragma tailcall on
s32 func_003c3890(u8 *arg0) {
    return func_003c3cc0(arg0);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
// FUN_003C38B0
/* The four floats are copied as one Vec4f assignment because retail loads all
   four before storing any; per-field assignments interleave lwc1/swc1 (nd 8).
   The result blocks are reached by goto so the zero case lands before the
   shared return, as retail lays them out. schedule on plus no_branch_likely
   on are needed for the delay slots and the plain bc1t/bc1f (nd 53 -> 17). */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c38b0(u8 *arg0, Vec4f *arg1) {
    *(Vec4f *)(arg0 + 0x18) = *arg1;
    if (*(f32 *)(arg0 + 0x18) == *(f32 *)(arg0 + 0x1C)) {
        goto chk;
    }
zero:
    arg0[3] = 0;
out:
    return arg0;
chk:
    if (*(f32 *)(arg0 + 0x18) != *(f32 *)(arg0 + 0x20)) {
        goto zero;
    }
    arg0[3] = 1;
    goto out;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above func_003c38b0's marker. */
#pragma schedule off

// FUN_003C3920
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c3920(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070AFD0, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
#pragma schedule off
// FUN_003C3950
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c3950(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070AFD0, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c3950; explicit opposite state restores the file default. */
#pragma schedule off
/* measured: schedule on keeps the saved constant live across func_003e3370. */
#pragma schedule on
// FUN_003C3980
s32 func_003c3980(u8 *arg0) {
    s32 total;

    total = 0x24;
    total += func_003e3370(D_0070AFD0, arg0) + 0xC;
    return total;
}
/* measured: schedule off closes the saved-constant probe. */
#pragma schedule off
// FUN_003C39C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c39c0);
// FUN_003C3AE0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3ae0);
// FUN_003C3CC0
#pragma schedule on
s32 func_003c3cc0(u8 *arg0) {
    func_003e3c20(D_0070AFD0, arg0);
    func_003efda0(arg0);
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + iGpffffb6d0), arg0);
    return 1;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: swapping the NULL-store and count decrement makes b210 assign
   the tail count to $v1 and the table offset to $a1, matching retail.
   Object/window 128/128, normalized_diff 0. Committed at nd 0. */

// FUN_003C3D20
#pragma schedule on
#pragma no_branch_likely on
extern void func_003c38a0(void);
u8 *func_003c3d20(s8 arg0) {
    u8 *temp;

    temp = ((u8 *(*)(s32, s32, s32))D_008873F8[0])(*(s32 *)(D_008872E0 + iGpffffb6d0), 0x30012, iGpffffb6d0);
    if (temp == NULL)
        goto null_result;
    *(s8 *)(temp + 0) = 3;
    *(s8 *)(temp + 1) = arg0;
    *(s8 *)(temp + 2) = 0;
    *(s8 *)(temp + 3) = 0;
    *(s32 *)(temp + 4) = 0;
    *(void **)(temp + 0x10) = (void *)func_003c38a0;
    *(s32 *)(temp + 0x14) = 0;
    *(s32 *)(temp + 0x28) = 0;
    *(s32 *)(temp + 0x18) = 0x3F800000;
    *(s32 *)(temp + 0x1C) = 0x3F800000;
    *(s32 *)(temp + 0x20) = 0x3F800000;
    *(s32 *)(temp + 0x24) = 0x3F800000;
    *(s8 *)(temp + 3) = 1;
    *(u8 **)(temp + 0x2C) = temp + 0x2C;
    *(u8 **)(temp + 0x30) = temp + 0x2C;
    *(s32 *)(temp + 0x38) = 0;
    *(s32 *)(temp + 0x34) = 0;
    *(s16 *)(temp + 0x3C) = (s16)(D_008872E8[1] - 1);
    *(s8 *)(temp + 2) = 3;
    func_003e3b70(D_0070AFD0, temp, (u8 *)1, (u8 *)0x3F800000);
    goto done;
done:
    return temp;
null_result:
    return NULL;
}
#pragma no_branch_likely off
#pragma schedule off
// FUN_003C3E10
#pragma schedule on
u8 *func_003c3e10(u8 *arg0) {
    func_003e18c0(*(u8 **)(D_008872E0 + iGpffffb6d0), (void *)func_003c3890, 0);
    func_003e12f0(*(u8 **)(D_008872E0 + iGpffffb6d0));
    *(u8 **)(D_008872E0 + iGpffffb6d0) = NULL;
    iGpffffb6d4 -= 1;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: explicit-label block order and the six-argument helper setup
   remain a compiler residual at this 144-byte window; no real C body was
   retained, so the bare INCLUDE_ASM fallback remains. */
// FUN_003C3E90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3e90);
/* measured: schedule on and no_branch_likely on are required for the retail
   jal/jr delay slots and plain branch forms. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C3F20
s32 func_003c3f20(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647CC, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_007647C8, 4) != 0) {
        goto retarg;
    }
    return 0;
}
/* measured: closes the branch and schedule pragmas above at the file baseline. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: typed three-argument helper and schedule probes reached
   normalized_diff 15 with object 112B/window 112B; pre-prologue load and
   final movz remained compiler residuals. No real C body was retained, so
   the bare INCLUDE_ASM fallback remains. */
// FUN_003C3FA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3fa0);


// FUN_003C4010
/* measured: schedule places the successful result in the branch delay slot. */
#pragma schedule on
/* measured: no_branch_likely keeps both null checks as ordinary branches. */
#pragma no_branch_likely on
s32 func_003c4010(u8 *arg0) {
    u8 *p;
    s32 result;
    p = *(u8 **)(arg0 + 8);
    if (p == NULL)
        goto zero;
    if (*(s32 *)(p + 0x2C) == 0)
        goto zero;
    result = 8;
    goto done;
zero:
    result = 0;
done:
    return result;
}
/* measured: no_branch_likely off closes this function's bracket. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: typed six-argument helper reconstruction reaches object 124B/window
   144B and nd 17; retail's store/reload and branch ordering remain a compiler
   residual. No real C body was retained, so the bare INCLUDE_ASM fallback
   remains. */
// FUN_003C4040
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4040);
// FUN_003C40D0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c40d0(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb6e0);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + iGpffffb6e0) = NULL;
    }
    iGpffffb6e4 -= 1;
    return arg0;
}
#pragma no_branch_likely off
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003C4140
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4140);
/* measured: typed helper reconstruction reaches object 128B/window 144B
   and nd 74; saved-self branch placement, callback address ordering, and
   the callback branch layout remain residuals. No real C body was retained,
   so the bare INCLUDE_ASM fallback remains. */
// FUN_003C4220
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4220);
// FUN_003C42B0
/* measured: schedule on fills the branch and jr delay slots (nd 53 -> 4) and
   no_branch_likely on stops b210 emitting beql on the two null tests. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c42b0(u8 **arg0, u8 *arg1) {
    if (arg1 != NULL) {
        *(s32 *)(arg1 + 0x54) += 1;
    }
    if (*arg0 != NULL) {
        func_003ef3a0(*arg0);
    }
    *arg0 = arg1;
    return (u8 *)arg0;
}
/* measured: closes the no_branch_likely bracket for func_003c42b0. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket for func_003c42b0; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003C4310
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c4310(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070AFF0, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c4310; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003C4340
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c4340(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070AFF0, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c4340; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003C4370
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c4370(s32 arg0, s32 arg1) {
    return func_003e30c0(D_0070AFF0, arg0, arg1);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off

// FUN_003C4390
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4390);
/* measured: schedule on takes this from nd 71 (obj 104B/window 96B)
   to nd 8 (obj 92B/window 96B), with every instruction right; the residual
   is three prologue words -- retail interleaves `move $s1,$a0` between the
   two saved-register stores while b210 emits both stores first. Measured
   identical at nd 8: naming the inner pointer in a local before the guard;
   folding the 0x28 into both arms of an if/else is much worse (nd 42).
   Prologue scheduling floor. Committed at nd 8. */
/* measured: direct two-call sum shape reaches object 92B/window 96B and
   normalized_diff 3; retail interleaves `move $s1,$a0` between the saved
   register stores while b210 emits both stores first. No real C body was
   retained, so the bare INCLUDE_ASM fallback remains. */
// FUN_003C47C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c47c0);



// FUN_003C4820
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4820);

/* measured: generated-shape list teardown reaches nd 76 with object/window
   148B/160B; the entry slt/beq guard and resulting block layout remain a
   compiler residual. No real C body was retained, so the bare INCLUDE_ASM
   fallback remains. */
// FUN_003C49A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c49a0);
// FUN_003C4A40
#pragma schedule on
u8 *func_003c4a40(u8 *arg0) {
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_007647EC;

/* measured: the indexed table accessor is reproduced by a direct scaled
   pointer load; schedule on places its final load in the jr delay slot. */

// FUN_003C4A60
/* measured: schedule on places the final indexed load in the jr delay slot. */
#pragma schedule on
s32 func_003c4a60(s32 *arg0, s32 arg1) {
    return ((s32 *)*arg0)[arg1];
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off

// FUN_003C4A80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4a80);

/* measured: hidden s32 return recovered the retail index; schedule on yields
   object 60B/window 64B and normalized_diff 8. The final return alignment
   remains a compiler residual. Committed at nd 8. */
// FUN_003C4BC0
/* measured: schedule on preserves the compact loop body. */
#ifdef NON_MATCHING
#pragma schedule on
s32 func_003c4bc0(u8 *arg0, s32 arg1) {
    s32 count;
    s32 index;
    s32 *p;

    count = *(s32 *)(arg0 + 4);
    index = count - 1;
    if (count > 0) {
        p = *(s32 **)(arg0 + 0) + index;
        do {
            if (*p == arg1) {
                goto done;
            }
            p -= 1;
        } while (index-- > 0);
    }
done:
    ;
    return index;
}
/* measured: schedule on closes 003C4BC0. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4bc0);
#endif

// FUN_003C4C00
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4c00);

// FUN_003C4CF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4cf0);

// FUN_003C4FA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c4fa0);
/* measured: tailcall preserves the callback jump and constant 0x30502 setup. */
#pragma tailcall on
// FUN_003C54A0
void func_003c54a0(u8 *arg0) {
    jtbl_008873E8[0](arg0, 0x30502);
}
/* measured: tailcall off closes the c54a0 probe. */
#pragma tailcall off

/* measured: schedule fills the counter branch delay and preserves self across
   the conditional teardown call. */
#pragma schedule on
/* measured: no_branch_likely keeps the null teardown test as beqz. */
#pragma no_branch_likely on
// FUN_003C54C0
u8 *func_003c54c0(u8 *arg0) {
    u8 *self;

    self = arg0;
    iGpffffb6f4 -= 1;
    if (iGpffffb6f4 != 0)
        goto done;
    if (iGpffffb6e8 == NULL)
        goto done;
    func_003e12f0(iGpffffb6e8);
    iGpffffb6e8 = NULL;
done:
    return self;
}
/* measured: no_branch_likely off closes the c54c0 probe. */
#pragma no_branch_likely off
/* measured: schedule off closes the c54c0 probe. */
#pragma schedule off

// FUN_003C5510
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5510);
// FUN_003C55F0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c55f0);
// FUN_003C5700
#pragma schedule on
s32 func_003c5700(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 8);
    if (p != NULL) {
        jtbl_008873EC[0](p);
        *(s32 *)(arg0 + 8) = 0;
    }
    jtbl_008873FC[0](iGpffffb6e8, arg0);
    return 1;
}
/* measured: without schedule on the jalr and jr delay slots stay empty and
   the object misses its window; with it func_003c5700 matches. */
#pragma schedule off

/* measured: the OR chain's five tests all branch POSITIVELY to a shared call
   block placed after the return path, so each test needs its own
   `if (...) goto call;` - written as one `if (a || b || ...)` the last test is
   inverted and the body goes inline (nd 22). The jal delay slot and the
   table's lui/lw need schedule on. The table must also be called through the
   pointer: `jtbl_008873EC()` is an implicit call to the SYMBOL. */
// FUN_003C5760
#pragma schedule on
s32 func_003c5760(u8 *arg0)
{
    if (*(s32 *)arg0 != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 4) != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 6) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto call;
    }
ret:
    return 1;
call:
    (*jtbl_008873EC)();
    goto ret;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: without schedule on, b210 leaves the jr $ra delay slot unfilled
   and colours the increment $v0; retail fills the slot with the store. */

// FUN_003C57D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c57d0);

/* measured: direct callback-loop reconstruction reaches nd 34 with
   object/window 140B/160B; the saved-argument coloring and branch layout
   remain residuals. No real C body was retained, so the bare INCLUDE_ASM
   fallback remains. */
// FUN_003C59F0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c59f0);

// FUN_003C5A90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5a90);

// FUN_003C5D10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5d10);

// FUN_003C5FD0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5fd0);
// FUN_003C6060
/* measured: a returned old value selects retail v0/v1 coloring. */
#pragma schedule on
s16 func_003c6060(void) {
    s32 offset;
    u8 *base;
    u8 *p;
    s16 old;
    offset = (s32)iGpffffb6f0;
    base = D_008872E0;
    p = base + offset;
    old = *(s16 *)p;
    *(s16 *)p = old + 1;
    return old;
}
#pragma schedule off

// FUN_003C6080
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c6080);

// FUN_003C6280
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c6280);

// FUN_003C65B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c65b0);

// FUN_003C66C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c66c0);

// FUN_003C67B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c67b0);

// FUN_003C6960
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c6960);

// FUN_003C6A40
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c6a40);

// FUN_003C6C10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c6c10);

// FUN_003C70E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c70e0);

// FUN_003C7D90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c7d90);

// FUN_003C8200
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c8200);

// FUN_003C8910
/* measured: schedule on places the constant in the jump delay slot. */
#pragma schedule on
/* measured: tailcall on preserves the helper's frameless jump. */
#pragma tailcall on
u8 *func_003c8910(u8 *arg0) {
    return func_003c8200(arg0, 0, 1);
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003C8920
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c8920);

// FUN_003C8BF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c8bf0);
// FUN_003C8CA0
#pragma schedule on
s32 func_003c8ca0(s32 arg0) {
    D_007647EC++;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003cc460();
void func_003d4e00();
void func_003d4e90();
void func_003d4d70();

/* measured: schedule on is required for the direct decrement return. */
// FUN_003C8CC0
/* measured: schedule on places the returned argument move in the jr delay slot. */
#pragma schedule on
s32 func_003c8cc0(s32 arg0) {
    D_007647EC -= 1;
    return arg0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003C8CE0
/* measured: tailcall on preserves the indirect dispatch jump. */
#pragma tailcall on
void func_003c8ce0(void) {
    ((void (*)(void))(*(void **)(*(u8 **)D_008872E4 + 0x68)))();
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off
// FUN_003C8D00
/* measured: schedule and tailcall reproduce the six-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c8d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070B040, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
#pragma schedule off
// FUN_003C8D30
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003c8d30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070B040, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003c8d30; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003C8D60
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c8d60(s32 arg0, s32 arg1) {
    return func_003e3070(D_0070B040, arg0, arg1);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C8D80
/* measured: schedule and tailcall reproduce the direct shared-helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003c8d80(s32 arg0, s32 arg1) {
    return func_003e30c0(D_0070B040, arg0, arg1);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
// FUN_003C8DA0
/* measured: schedule fills the branch and return delay slots. */
#pragma schedule on
/* measured: no_branch_likely keeps the equality test as an ordinary branch. */
#pragma no_branch_likely on
s32 func_003c8da0(s32 arg0, u8 *arg1) {
    if (*(s32 *)arg1 == arg0)
        goto equal;
    return arg0;
equal:
    *(s32 *)(arg1 + 4) = 1;
    return 0;
}
#pragma no_branch_likely off
#pragma schedule off
// FUN_003C8DD0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c8dd0);
// FUN_003C8EB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c8eb0);
// FUN_003C91D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c91d0);
// FUN_003C9300
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9300);
// FUN_003C9530
extern s32 iGpffffb700;
extern s32 iGpffffb704;
extern void func_003cc130(void);
/* measured: probe schedule */
#pragma schedule on
s32 func_003c9530(s32 arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb700);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + iGpffffb700) = NULL;
    }
    func_003cc130();
    iGpffffb704 -= 1;
    return arg0;
}
/* measured: close schedule */
#pragma schedule off

/* measured: typed allocator reconstruction reaches normalized_diff 37 with
   object 152B/window 160B; the store/load check still folds before the
   retail branch block, so the bare INCLUDE_ASM fallback remains. */
// FUN_003C95A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c95a0);
/* measured: reordered dispatch reconstruction reaches normalized_diff 30 with
   object 136B/window 144B; the conditional-move branch and entry targets
   remain residuals, so the bare INCLUDE_ASM fallback remains. */
// FUN_003C9640
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9640);
// FUN_003C96D0
extern u8 D_008872E4[];
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003c96d0(s32 (*arg0)(u8 *, s32), s32 arg1) {
    u8 *base;
    u8 *p;
    u8 *end;
    u8 *item;

    base = *(u8 **)(D_008872E4);
    end = base + 0x3C;
    p = *(u8 **)(base + 0x3C);
    if (p == end)
        goto finish;
loop:
    item = p - 0x34;
    p = *(u8 **)(p);
    if (item == NULL)
        goto check;
    if (arg0(item, arg1) == 0)
        return 1;
check:
    if (p != end)
        goto loop;
finish:
    return 1;
}
// FUN_003C9750
/* measured: schedule and no_branch_likely reproduce the callback loop layout.
   Candidate object 132B/window 144B, normalized_diff 11; residual is
   register coloring between the cursor and next-node values.
   Committed at nd 11. */
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003c9750(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    u8 *end;
    u8 *node;
    u8 *next;
    s32 value;

    end = arg0 + 0x40;
    node = *(u8 **)(arg0 + 0x40);
    if (node != end) {
        do {
            value = *(s32 *)(node + 8);
            next = *(u8 **)node;
            if ((value != 0) && (arg1(value, arg2) == 0))
                return arg0;
            node = next;
        } while (node != end);
    }
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9750);
#endif

// FUN_003C97E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c97e0);

// FUN_003C9940
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9940);

/* measured: schedule fills the key-test and found-exit delay slots. */
#pragma schedule on
// FUN_003C99F0
void func_003c99f0(u8 *arg0) {
    u8 **temp_6_2;
    u8 *temp_3;
    u8 *temp_6;
    u8 *temp_5;
    u8 *var_7;

    temp_3 = D_008872E0 + iGpffffb700;
    var_7 = *(u8 **)(temp_3 + 4);
    temp_6 = temp_3 + 4;
    if (var_7 != temp_6) {
loop:
        temp_5 = var_7 - 8;
        if (*(u8 **)(var_7 - 8) == arg0) {
            *(u8 **)(*(u8 **)(temp_5 + 0xC)) =
                *(u8 **)(temp_5 + 8);
            temp_6_2 = (u8 **)(*(u8 **)(temp_5 + 0xC));
            *(u8 **)(*(u8 **)(temp_5 + 8) + 4) = (u8 *)temp_6_2;
            jtbl_008873FC[0](
                *(u8 **)(D_008872E0 + iGpffffb700), temp_5);
            goto done;
        }
        var_7 = *(u8 **)var_7;
        if (var_7 == temp_6)
            goto done;
        goto loop;
    }
done:
    return;
}
/* measured: schedule off closes the c99f0 probe. */
#pragma schedule off
// FUN_003C9A80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9a80);
// FUN_003C9B30
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9b30);

// FUN_003C9C20
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9c20);

// FUN_003C9D00
/* measured: schedule preserves the saved argument across the callback helper. */
#pragma schedule on
s32 func_003c9d00(u8 *arg0) {
    u8 *self;
    self = arg0;
    func_003cbde0(*(u8 **)D_008872E0, func_003c8dd0, self);
    return (s32)self;
}
/* measured: closes the schedule bracket for func_003c9d00; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003C9D40
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9d40);

// FUN_003C9E80
/* measured: schedule places store and callback-address materialization in retail delay slots. */
#pragma schedule on
/* measured: no_branch_likely keeps the null callback test as retail beqz. */
#pragma no_branch_likely on
u8 *func_003c9e80(u8 *arg0, u8 *(*arg1)(u8 *)) {
    if (arg1 == NULL)
        goto default_callback;
store:
    *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
    return arg0;
default_callback:
    arg1 = func_003c9640;
    goto store;
}
/* measured: no_branch_likely off closes this function's bracket. */
#pragma no_branch_likely off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off

// FUN_003C9EB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9eb0);

// FUN_003CA270
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca270);
// FUN_003CA320
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca320);
// FUN_003CA3D0
#pragma schedule on
#pragma tailcall on
s32 func_003ca3d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_003e3870(D_0070B060, arg0, arg1, arg2, arg3, arg4);
}
#pragma tailcall off
#pragma schedule off

// FUN_003CA400
/* measured: schedule and tailcall reproduce the five-argument shared-helper jump. */
#pragma schedule on
#pragma tailcall on
s32 func_003ca400(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003e3020(D_0070B060, arg0, arg1, arg2, arg3);
}
#pragma tailcall off
/* measured: closes the schedule bracket for func_003ca400; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003CA430
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca430);

// FUN_003CA5A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca5a0);

// FUN_003CA6A0
/* measured: no_branch_likely before schedule preserves retail ordinary null
   branches without changing the scheduled prologue. */
#pragma no_branch_likely on
#pragma schedule on
u8 *func_003ca6a0(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + (s32)iGpffffb718 + 4);
    if (p == NULL)
        goto second;
    func_003e12f0(p);
    *(u8 **)(D_008872E0 + (s32)iGpffffb718 + 4) = NULL;
second:
    p = *(u8 **)(D_008872E0 + (s32)iGpffffb718);
    if (p == NULL)
        goto done;
    func_003e12f0(p);
    *(u8 **)(D_008872E0 + (s32)iGpffffb718) = NULL;
done:
    iGpffffb71c -= 1;
    return arg0;
}
#pragma schedule off
#pragma no_branch_likely off

// FUN_003CA740
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca740);

/* measured: closes the no_branch_likely bracket opened above FUN_003C0640. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket opened above FUN_003C0640; the explicit
   opposite state restores this unit's `schedule off` file default. */
#pragma schedule off


/* measured: nd 14 at the retail's 96B window (candidate obj 92B/window 96B).
   Retail materializes the handlers directly as lui/addiu references to
   func_003ca740 + 0, +0x40, and +0x60; it does not load them through a
   function-pointer table. Direct-symbol C is nd 14; table-base/lw probes
   scored nd 64 and nd 59 with object 88B. The remaining three words are the
   order of `move $v0,$a0`, `addu $t0,$a0,$a3`, and the first store; all
   returned-value, pointer/record-local, offset, and schedule variants remain
   nd 14. Committed at nd 14. */

// FUN_003CA830 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
u8 *func_003ca830(u8 *arg0) {
    u8 *f60 = func_003ca7a0;
    u8 *f00 = func_003ca740;
    u8 *f40 = func_003ca780;
    u8 *node = arg0 + iGpffffb708;

    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(node + 0x10) = *(s32 *)(arg0 + 0x18);
    *(s32 *)(node + 0x14) = *(s32 *)(arg0 + 0x1C);
    *(s32 *)(node + 0x18) = *(s32 *)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = f60;
    *(u8 **)(arg0 + 0x18) = f00;
    *(u8 **)(arg0 + 0x1C) = f40;
    *(s32 *)(node + 0xC) = 0;
    return arg0;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca830);
#endif
// FUN_003CA890
#pragma schedule on
u8 *func_003ca890(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb708;
    u8 *node0 = arg0 + iGpffffb708;
    s32 guard = *(s32 *)(node + 0xC);
    *(s32 *)(node0 + 0) = 0;
    *(s32 *)(node0 + 4) = 0;
    *(s32 *)(node0 + 8) = 0;
    if (guard != 0)
        func_003cbc10((u8 *)guard, arg0);
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003CA8E0
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003ca8e0(u8 *arg0) {
    u8 *node;
    u8 *p;

    node = arg0 + iGpffffb708;
    p = *(u8 **)node;
    if (p != NULL)
        jtbl_008873EC[0](p);
    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(arg0 + 0x18) = *(s32 *)(node + 0x10);
    *(s32 *)(arg0 + 0x1C) = *(s32 *)(node + 0x14);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(node + 0x18);
    return arg0;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off

// FUN_003CA960
/* measured: probe schedule */
#pragma schedule on
s32 func_003ca960(u8 *arg0) {
    u8 *x;
    u8 *y;

    x = *(u8 **)(arg0 + 0xC);
    y = *(u8 **)(arg0 + 0x10);
    *(u8 **)(y + 0) = x;
    x = *(u8 **)(arg0 + 0x10);
    y = *(u8 **)(arg0 + 0xC);
    *(u8 **)(y + 4) = x;
    x = *(u8 **)(arg0 + 0);
    y = *(u8 **)(arg0 + 4);
    *(u8 **)(y + 0) = x;
    y = *(u8 **)(arg0 + 4);
    x = *(u8 **)(arg0 + 0);
    *(u8 **)(x + 4) = y;
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb718 + 4), arg0);
    return 1;
}
/* measured: close schedule */
#pragma schedule off

// FUN_003CA9D0
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003ca9d0(u8 *arg0) {
    u8 *obj;
    u8 *x;
    u8 *y;

    obj = arg0;
    if (*(s32 *)(obj + 8) != 0 && *(s32 *)(obj + 0x14) != 0) {
        x = *(u8 **)(obj + 0xC);
        y = *(u8 **)(obj + 0x10);
        *(u8 **)(y + 0) = x;
        x = *(u8 **)(obj + 0x10);
        y = *(u8 **)(obj + 0xC);
        *(u8 **)(y + 4) = x;
        x = *(u8 **)(obj + 0);
        y = *(u8 **)(obj + 4);
        *(u8 **)(y + 0) = x;
        y = *(u8 **)(obj + 4);
        x = *(u8 **)(obj + 0);
        *(u8 **)(x + 4) = y;
        jtbl_008873FC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb718), obj);
    }
    return 1;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off

/* measured: best plain-C reconstruction with schedule/goto is nd 34,
   object 76B versus the 80B window; call-argument ordering and final
   conditional-move code remain; no real C body was retained, so the bare
   INCLUDE_ASM fallback remains. */

// FUN_003CAA50
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003caa50);

// FUN_003CAC30
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cac30);

/* measured: schedule on places the callback store in the jr delay slot. */
#pragma schedule on
// FUN_003CAD40
u8 *func_003cad40(u8 *arg0) {
    u8 *temp;

    temp = (u8 *)(arg0 + iGpffffb70c);
    *(s32 *)(temp + 0) = 0;
    *(s16 *)(arg0 + 0x60) = (s16)(D_008872E8[0] - 1);
    *(u8 **)(temp + 4) = *(u8 **)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = func_003cac30;
    return arg0;
}
/* measured: schedule off closes the callback-store probe. */
#pragma schedule off

// FUN_003CAEF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003caef0);

/* measured: schedule on places the callback store in the jr delay slot. */
#pragma schedule on
// FUN_003CB1E0
u8 *func_003cb1e0(u8 *arg0) {
    u8 *temp;

    temp = (u8 *)(arg0 + iGpffffb714);
    *(s32 *)(temp + 0) = 0;
    *(u8 **)(temp + 4) = *(u8 **)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = func_003caef0;
    return arg0;
}
/* measured: schedule off closes the callback-store probe. */
#pragma schedule off

/* measured: schedule on preserves the saved self across func_003cbe80. */
#pragma schedule on
/* measured: no_branch_likely on keeps the null test as retail's plain beqz. */
#pragma no_branch_likely on
// FUN_003CB210
u8 *func_003cb210(u8 *arg0, u8 *arg1) {
    u8 *self;
    u8 *temp;

    self = arg0;
    temp = (u8 *)(arg1 + iGpffffb714);
    if (*(u8 **)(temp + 0) != NULL) {
        func_003cbe80(*(u8 **)(temp + 0), self);
    }
    return self;
}
/* measured: no_branch_likely off closes the null-test probe. */
#pragma no_branch_likely off
/* measured: schedule off closes the saved-self probe. */
#pragma schedule off

// FUN_003CB250
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb250);

// FUN_003CB300
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb300);

// FUN_003CB670
/* measured: schedule places the saved object in the helper call delay slot. */
#pragma schedule on
s32 func_003cb670(u8 *arg0, u8 *arg1) {
    u8 *self;
    self = arg0;
    func_003cbc90(arg1, self);
    return (s32)self;
}
#pragma schedule off

// FUN_003CB6A0
/* measured: schedule places the saved object in the helper call delay slot. */
#pragma schedule on
s32 func_003cb6a0(u8 *arg0, u8 *arg1) {
    u8 *self;
    self = arg0;
    func_003cbe80(arg1, self);
    return (s32)self;
}
/* measured: closes the schedule bracket for func_003cb6a0; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003CB6D0
/* measured: schedule places the saved object in the helper call delay slot. */
#pragma schedule on
s32 func_003cb6d0(u8 *arg0, u8 *arg1) {
    u8 *self;
    self = arg0;
    func_003cbc10(arg1, self);
    return (s32)self;
}
/* measured: closes the schedule bracket for func_003cb6d0; explicit opposite state restores the file default. */
#pragma schedule off

// FUN_003CB700
/* measured: schedule and tailcall reproduce the four-argument helper jump. */
#pragma schedule on
/* measured: tailcall on preserves the frameless helper jump. */
#pragma tailcall on
s32 func_003cb700(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *self;
    self = arg2;
    return func_003c5a90(*(u8 **)(self + 0x54), self, arg0, self + 0x20);
}
/* measured: tailcall off closes func_003cb700's bracket and restores the file default. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off
/* measured: schedule on and the stored-field result yield object 72B/window
   80B and normalized_diff 6; retail's movz conditional move remains a
   compiler residual. Committed at nd 6. */
// FUN_003CB720 NONMATCHING
#ifdef NON_MATCHING
extern s32 func_003c5d10(s32 arg0, u8 *arg1, u8 *arg2);
#pragma schedule on
s32 func_003cb720(s32 arg0, s32 arg1, u8 *arg2) {
    Cb720Obj *obj;

    obj = (Cb720Obj *)arg2;
    obj->field = func_003c5d10(arg0, arg2, arg2 + 0x20);
    return (obj->field == 0) ? 0 : arg0;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb720);
#endif
// FUN_003CB770
/* measured: schedule on places the field load in the jump delay slot. */
#pragma schedule on
/* measured: tailcall on preserves the helper's frameless jump. */
#pragma tailcall on
s32 func_003cb770(u8 *arg0) {
    return func_003c5fd0(*(u8 **)(arg0 + 0x54), arg0);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off

// FUN_003CB780
/* measured: schedule on places the selected move in the jump delay slot. */
#pragma schedule on
/* measured: tailcall on preserves the helper's frameless jump. */
#pragma tailcall on
s32 func_003cb780(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003ce3a0(arg0, arg2);
}
/* measured: tailcall off closes this function's bracket. */
#pragma tailcall off
/* measured: schedule off closes this function's bracket. */
#pragma schedule off

// FUN_003CB790
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb790);
// FUN_003CB7C0
/* measured: tailcall on preserves the helper jump. */
#pragma tailcall on
void func_003cb7c0(u8 *arg0) {
    func_003ce840(arg0);
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off

// FUN_003CB7D0
/* measured: schedule on places the selected argument move in the jump delay slot. */
#pragma schedule on
/* measured: tailcall on preserves the helper's selected argument jump. */
#pragma tailcall on
s32 func_003cb7d0(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003ce9e0(arg0, arg2);
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off
/* measured: closes the schedule bracket for func_003cb7d0; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003CB7E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb7e0);
// FUN_003CB810
/* measured: tailcall on preserves the helper jump. */
#pragma tailcall on
s32 func_003cb810(u8 *arg0) {
    return func_003ceeb0(arg0);
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off

/* measured: retail takes THREE parameters and ignores the second -- arg0
   arrives in $a0 and the object pointer in $a2. With the third parameter
   restored and #pragma schedule on (without it b210 leaves the jal delay slot
   empty, nd 45, and the object overflows the window at 84 bytes) everything
   matches except the order of the last two argument materialisations: retail
   emits `move $a1,$v0` then puts `addiu $a3,$v0,0x10` in the jal delay slot,
   b210 emits the addiu first and the move in the slot (fndiff rows 40/48,
   checklist 9; nd 8, obj 72B/window 80B). The exact raw callee types are
   now represented (`func_003c9c20` returns a pointer and `func_003c5a90`
   takes pointer, pointer, s32, s32). Naming temp_2 + 0x10 in a local,
   pointer-typed temp with pointer arithmetic, a named local for the 0x78
   load, `0x10 + temp_2`, casts, pointer-return variants, and all-s32 or
   old-style callee prototypes were all measured at nd 8. Committed at nd 8. */

// FUN_003CB820
/* measured: schedule on places the second call in the jr delay slot as retail
   does; the fourth argument to func_003c5a90 is a u8 *, and casting it to s32
   was what kept this body from compiling under NON_MATCHING and from matching. */
#pragma schedule on
void func_003cb820(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp_2;

    temp_2 = func_003c9c20((u32)arg2);
    func_003c5a90((u8 *)*(s32 *)(arg2 + 0x78), temp_2, arg0, temp_2 + 0x10);
}
/* measured: closes the schedule bracket opened above func_003cb820. */
#pragma schedule off

/* measured: best C reconstruction with schedule/goto is nd 37,
   object 88B versus the 96B window; call/conditional-move residuals
   remain; no real C body was retained, so the bare INCLUDE_ASM fallback
   remains. */
// FUN_003CB870
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb870);

// FUN_003CB8D0
/* measured: schedule preserves the object across both helper calls. */
#pragma schedule on
void func_003cb8d0(u8 *arg0) {
    u8 *self;
    u8 *temp;
    self = arg0;
    temp = func_003c9c20((u32)self);
    func_003c5fd0(*(u8 **)(self + 0x78), temp);
}
#pragma schedule off
// FUN_003CB900
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb900);
// FUN_003CBC10
#pragma schedule on
u8 *func_003cbc10(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb708;
    u8 *v = *(u8 **)(arg1 + 4);
    if (v != 0)
        func_003e9680(v);
    *(s32 *)(node + 0xC) = (s32)arg0;
    return arg0;
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

// FUN_003CBC60
/* measured: schedule places the zero return and final store in retail delay slots. */
#pragma schedule on
/* measured: no_branch_likely keeps the node test as an ordinary branch. */
#pragma no_branch_likely on
s32 func_003cbc60(s32 arg0, u8 *arg1) {
    u8 *node;
    node = arg1 + iGpffffb708;
    if (*(s32 *)(node + 0xC) != 0)
        goto active;
    return 0;
active:
    *(s32 *)(node + 0xC) = 0;
    *(s32 *)(node + 8) = 0;
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off
// FUN_003CBC90
#pragma schedule on
u8 *func_003cbc90(u8 *arg0, u8 *arg1) {
    u8 *node = arg1 + iGpffffb70c;
    u8 *v = *(u8 **)(arg1 + 4);
    if (v != 0)
        func_003e9680(v);
    *(s32 *)(node + 0x0) = (s32)arg0;
    return arg0;
}
// FUN_003CBCE0
/* measured: schedule on places the GP-derived field load in the jr delay slot. */
#pragma schedule on
s32 func_003cbce0(s32 arg0) {
    return *(s32 *)(arg0 + iGpffffb70c);
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off

// FUN_003CBCF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbcf0);
// FUN_003CBDE0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbde0);

// FUN_003CBE80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbe80);

// FUN_003CBF30
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbf30);

// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off

/* measured: these three functions are one setter/lookup template. The
   explicit four-block gotos plus schedule on, no_branch_likely on, and
   opt_common_subs off give nd 6 with object 88B/window 96B. fndiff's only
   reloc-masked residual rows are offsets 16 and 20: retail emits
   `addiu $v1,$v1,%lo(D_008872E0)` then `move $v0,$a0`, while b210 emits
   those two words in the opposite order (checklist 9, preheader order).
   The GP/global rows at offsets 8, 12, 36, 40, 44, and 68 are relocation
   differences, not instruction residuals. Named base pointers at store,
   reload, before the guard, lookup-only, initialized, and path-local forms;
   array and `&D_008872E0` forms; base plus loop-invariants; and a separate
   walker/result shared-exit form were all measured without improvement.
   The split-store form grew to nd 40, object 100B/window 96B; the best
   separate walker/result form was nd 25, object 84B/window 96B. Committed at nd 6. */

// FUN_003CC010 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc010(u8 *arg0) {
    s32 off;
    u8 *base;
    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x40) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x58);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc010);
#endif

/* measured: sibling of func_003cc010; the same template and probes leave
   only the offset-16/20 preheader order residual, nd 6, object 88B/window
   96B. Checklist 9. Committed at nd 6. */
// FUN_003CC070 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc070(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x3C) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x54);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc070);
#endif

/* measured: sibling of func_003cc010; the same template and probes leave
   only the offset-16/20 preheader order residual, nd 6, object 88B/window
   96B. Checklist 9. Committed at nd 6. */
// FUN_003CC0D0 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe CSE */
#pragma opt_common_subs off
/* measured: probe branch form */
#pragma no_branch_likely on
u8 *func_003cc0d0(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x44) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x5C);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close CSE */
#pragma opt_common_subs on
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc0d0);
#endif


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled: MISMATCH nd 6, object 56 bytes in a 64-byte window. */
// FUN_003CC130
#pragma schedule on
void func_003cc130(void) {
    func_003cc460();
    func_003d4e00();
    func_003d4e90();
    func_003d4d70();
}
// measured: closes the schedule bracket opened above and restores the -O2
// baseline for the rest of the file.
#pragma schedule off


/* measured: without #pragma schedule on, MWCC emits addiu $v0, 1 before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CC170
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc170);
// FUN_003CC240
#pragma schedule on
s32 func_003cc240(void) {
    return 1;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003f32d0();

/* measured (merged TU): schedule on was load-bearing per-unit for the
   jal/jr $ra delay slots, but in the merged TU it worsens the near-miss
   (nd 17 with vs nd 15 without), so the pragma was removed.
   NONMATCHING: retail sinks the if-body out of line (bnez/ b exit; ld ra /
   body / b back / jr ra; addiu sp, 15 instr); b210 compiles every honest
   form of this if inline as a beql skip (13 instr) across 30+ probe
   shapes, so the layout is not reproducible.  Residual: nd 15. */

/* measured: explicit out-of-line labels, schedule on, no_branch_likely on,
   and two-argument signature reproduce the complete 112-byte body except
   retail hoists `lw $v1,($a1)` before saving $ra while b210 saves $ra first.
   Prologue scheduling residual is nd 4, obj 104B/window 112B. Moving the
   first pointer use into a nested load, assignment expression, direct
   expression, or positive-branch form did not alter nd 4; the comparison
   `<= 0` versus `< 1` also stayed nd 4. The base body remains the lowest
   park. Committed at nd 4. */
// FUN_003CC250 NONMATCHING
#ifdef NON_MATCHING
extern void (*D_00887300[])(u32, u32);
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003cc250(s32 arg0, u8 **arg1) {
    u8 *p = *arg1;
    if ((s32)*(u16 *)(p + 0) <= 0)
        goto retzero;
    *(s32 *)(p + 0x18) = *(s32 *)(p + 4);
    if ((*(s32 *)(p + 0xC) & 1) == 0)
        goto call;
retone:
    return 1;
retzero:
    return 0;
call:
    D_00887300[0](1, 0);
    goto retone;
}
/* measured: close branch form */
#pragma no_branch_likely off
/* measured: close schedule */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc250);
#endif

// FUN_003CC2C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc2c0);

// FUN_003CC370
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc370);
/* measured: schedule-on probe for cc460 call delay-slot setup. */
#pragma schedule on
// FUN_003CC460
void func_003cc460(void) {
    u8 *temp_2;

    func_00410ab0(0, 2);
    func_00410ab0(0, 1);
    func_00410ab0(0, 4);
    func_00410ab0(0, 5);
    func_00410ab0(0, 3);
    func_00410a40(0);
    temp_2 = D_008872E0 + iGpffffb9b0;
    *(s32 *)(temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 0x38) = 0;
    *(s32 *)(temp_2 + 0x30) = 0;
    *(s32 *)(temp_2 + 0x2C) = 0;
    *(s32 *)(temp_2 + 0x24) = 0;
    *(s32 *)(temp_2 + 0x28) = 0;
    *(s32 *)(temp_2 + 0x20) = 0;
    func_00411670(*(s32 *)(temp_2 + 0x1C));
    *(s32 *)(D_008872E0 + iGpffffb9b0 + 0x1C) = 0;
}
/* measured: closes schedule-on probe for cc460 and restores file default. */
#pragma schedule off
// FUN_003CC500
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc500);
/* measured: retail uses standalone pexew/ppacw MMI instructions; no plain-C
   equivalent is permitted. Window 96B; no real C body was retained; the bare
   INCLUDE_ASM fallback remains. */

// FUN_003CC560
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc560);
// FUN_003CC680
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc680);

/* measured: the null-first `block_body`/`block_null` graph plus
   no_branch_likely and schedule reproduce retail's out-of-line null branch,
   the ld $ra delay-slot fill, and the backward body branch. Compiled C MATCH,
   object 60B/window 64B. Committed at nd 0. */
// FUN_003CC6E0
/* measured: schedule on for func_003cc6e0. */
#pragma schedule on
/* measured: no_branch_likely on for func_003cc6e0. */
#pragma no_branch_likely on
void func_003cc6e0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x18) != 0)
        goto block_body;
block_null:
    return;
block_body:
    func_003f32d0();
    func_003f32d0();
    goto block_null;
}
/* measured: no_branch_likely off for func_003cc6e0. */
#pragma no_branch_likely off
/* measured: schedule off for func_003cc6e0. */
#pragma schedule off

extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CC720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc720);
// FUN_003CCF80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ccf80);
// FUN_003CD720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cd720);
// FUN_003CDFA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cdfa0);
// FUN_003CE050
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce050);
// FUN_003CE170
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce170);
// FUN_003CE230
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce230);
// FUN_003CE2E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce2e0);
// FUN_003CE3A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce3a0);
// FUN_003CE560
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce560);
// FUN_003CE840
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce840);
// FUN_003CE9E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ce9e0);
// FUN_003CEBB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cebb0);
// FUN_003CEEB0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ceeb0);
// FUN_003CF070
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf070);
// FUN_003CF140
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf140);
// FUN_003CF610
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf610);
// FUN_003CF9B0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *sub;

    if (arg0 == NULL)
        goto outer_none;
    sub = *(u8 **)(arg0 + 0x14);
    if (sub == NULL)
        goto sub_none;
    switch (arg1) {
    case 1:
        if (arg2 == 0)
            goto none;
        *(s32 *)(sub + 0x10) = arg2;
        return arg0;
    case 2:
        *(s32 *)(sub + 0x14) = arg2;
        return arg0;
    default:
        return NULL;
    }
outer_none:
    return NULL;
sub_none:
    return NULL;
none:
    return NULL;
}
#pragma no_branch_likely off
#pragma schedule off

// FUN_003CFA30
/* measured: schedule reproduces the shared exits and return delay slots. */
#pragma schedule on
/* measured: no_branch_likely keeps the two null tests as ordinary branches. */
#pragma no_branch_likely on
u8 *func_003cfa30(u8 *arg0, u8 *arg1) {
    u8 *p;
    if (arg0 == NULL)
        goto no_result;
    p = *(u8 **)(arg0 + 0x14);
    if (p == NULL)
        goto no_result2;
    *(u8 **)(p + 0x18) = arg1;
    return arg0;
no_result:
    return NULL;
no_result2:
    return NULL;
}
#pragma no_branch_likely off
/* measured: closes the schedule bracket for func_003cfa30; explicit opposite state restores the file default. */
#pragma schedule off
// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

// FUN_003CFA80
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cfa80);
/* measured: schedule on places saved self and helper argument delay slots. */
#pragma schedule on
// FUN_003CFFA0
u8 *func_003cffa0(u8 *arg0, u8 *arg1) {
    if ((*(u8 *)(arg0 + 2) & 1) != 0)
        goto call;
return_value:
    return arg0;
call:
    func_003cfa80(arg0, (s32)(arg1 + 0x10),
                  *(f32 *)(arg1 + 0x50), *(f32 *)(arg1 + 0x54));
    goto return_value;
}
/* measured: schedule off closes cffa0's delay-slot probe. */
#pragma schedule off
// FUN_003CFFF0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cfff0);
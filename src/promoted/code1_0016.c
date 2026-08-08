#include "include_asm.h"
#include "type.h"
extern s32 iGpffff9ef8;

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);
extern u8 *func_00145270(u16 arg0);
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007E8C00[];

typedef struct E9F0Vec3
{
    f32 x;
    f32 y;
    f32 z;
} E9F0Vec3;



// FUN_00160440
void func_00160440(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x1854) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x1854));
        *(s32 *)((u8 *)func_00155280() + 0x1854) = 0;
    }
}



// FUN_00161500
void func_00161500(s32 arg0)
{
    iGpffff9ef8 = arg0;
}

/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the 0x750 stride and exact table bases (nd 14 -> 0).
   Committed at nd 0. */
// FUN_001622D0
#pragma opt_loop_invariants on
void func_001622d0(void) {
    s32 i = 0;
    s32 one = 1;
    s32 stride = 0x750;

    while (i < 4) {
        *(s32 *)(D_007EF9B0 + i * stride + 0x44) = one;
        *(s32 *)(D_007F16F0 + i * 8 + 4) = 0;
        *(s16 *)(D_007F16F0 + i * 8) = 0;
        *(s16 *)(D_007F16F0 + i * 8 + 2) = 0;
        i++;
    }
}
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
#pragma opt_loop_invariants off

// FUN_00162330
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *func_00162330(void) {
    u8 *r = NULL;
    s32 i = 0;
    u8 *e;

    while (i < 4) {
        e = D_007EF9B0 + i * 0x750;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_00162390
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *func_00162390(void) {
    u8 *r = NULL;
    s32 i = 0;
    s32 stride = 0x750;
    u8 *e;

    while (i < 0xF) {
        e = D_007E8C00 + i * stride;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_00168030
void func_00168030(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00168470
void func_00168470(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00168780
void func_00168780(u8 *arg0, f32 fparg0) {
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(f32 *)(temp_5 + 0x24) = fparg0;
    if (fparg0 == 0.0f) {
        *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) | 0x10000000);
        return;
    }
    *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) & 0xEFFFFFFF);
}

// FUN_001687D0
s32 func_001687d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40);
}

// FUN_001687E0
s32 func_001687e0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44);
}

// FUN_0016E580
s32 func_0016e580(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x8);
}

// FUN_0016E9F0
void func_0016e9f0(u8 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    *(E9F0Vec3 *)(temp_3 + 0x14) = *(E9F0Vec3 *)(arg1 + 0x00);
}



// FUN_0016EA40
void func_0016ea40(u8 *arg0, u16 arg1)
{
    u8 *temp_16;
    s32 type;

    temp_16 = *(u8 **)(arg0 + 0x38);
    type = (arg1 & 0xFFC00) >> 10;
    if (type == 1)
        *(u8 **)(temp_16 + 0x288) = func_00145270(arg1);
}

// FUN_0016EAA0
/* The scaled offset is named in an s32 local and the base added TO it so the
   final addu comes out `index + base` as retail has it; folding the multiply
   into the pointer expression emits `base + index` (nd 1). The three floats
   are one E9F0Vec3 assignment because retail loads all three before storing
   any. */
void func_0016eaa0(u8 *arg0, s32 arg1, E9F0Vec3 *arg2) {
    u8 *base;
    s32 i;
    s32 off;

    base = *(u8 **)(arg0 + 0x38);
    i = (s8)arg1;
    base[i + 0xE8] = 1;
    off = i * 12;
    *(E9F0Vec3 *)(off + (s32)base + 0x108) = *arg2;
}

// FUN_0016EAF0
s32 func_0016eaf0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x2BC);
}

// FUN_0016F100
void func_0016f100(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

#include "include_asm.h"
#include "type.h"

extern void func_0034f5d0(u8 *arg0);

extern void func_002bb550(s8 arg0);
extern void (*D_008873EC[])(...);

extern void func_003549d0();
extern void func_00442de8(void *dst, const void *src, u32 size);

extern void func_0046d730(const void *module, u32 line);
extern u32 D_0064B310[];

extern f32 D_00761260;

typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;

typedef struct S64u
{
    s32 lo;
    s32 hi;
} S64u;



extern s32 func_0034c210(void);

extern void FUN_0046d730(const char *file, s32 line);
extern u32 D_0064B1E0[];

extern void func_004672c0(s32 arg0, s32 arg1);
extern void func_00454bd0(u8 *arg0);
extern void func_003ef3a0(void *arg0);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern void func_00365f00(f32 f0, f32 f1, f32 f2, f32 f3, s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 f4);
extern f32 iGpffff83d4;
extern f32 iGpffff8544;

// FUN_00353B50
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353b50);
// FUN_00353C10
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353c10);
// FUN_00353CE0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353ce0);
// FUN_00353DC0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353dc0);
// FUN_00353F50
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353f50);
// FUN_00353FB0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353fb0);
// FUN_00353FE0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00353fe0);
// FUN_00354010
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354010);
// FUN_00354030
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354030);
// FUN_00354080
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354080);
// FUN_003540F0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003540f0);
// FUN_00354230
void func_00354230(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002bb550(*(s8 *)(temp_16 + 8));
    (*D_008873EC)(temp_16);
}



// FUN_00354280
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354280);
// FUN_00354490
u32 func_00354490(s32 arg0)
{
    if (!(arg0 < 0x40)) {
        FUN_0046d730(__FILE__, 0x3D6);
    }
    return D_0064B1E0[arg0];
}

// FUN_003544F0
s32 func_003544f0(void)
{
    return 50;
}

// FUN_00354500
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354500);
// FUN_00354660
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354660);
// FUN_003547C0
void func_003547c0(s32 *arg0, u8 *arg1)
{
    func_003549d0();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    func_00442de8((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}



// FUN_00354830
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354830);
// FUN_003549D0
void func_003549d0(u8 *arg0)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_004672c0(temp_4, *(s32 *)(arg0 + 8));
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 8) = 0;
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        func_00454bd0(*(u8 **)(arg0 + 8));
        *(s32 *)(arg0 + 8) = 0;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        func_003ef3a0(*(u8 **)(arg0 + 0xC));
        *(s32 *)(arg0 + 0xC) = 0;
    }
}

// FUN_00354A50
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354a50);
// FUN_00354BA0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354ba0);
// FUN_00355070
void func_00355070(u8 *arg0, u8 *arg1) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(temp_3 + 0x18) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(temp_3 + 0x1C) = (f32) *(f32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x20) = (f32) *(f32 *)(arg1 + 0);
        *(f32 *)(temp_3 + 0x24) = (f32) *(f32 *)(arg1 + 4);
    } else {
        *(f32 *)(temp_3 + 0x10) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x14) = (f32) *(f32 *)(temp_3 + 0x1C);
        *(f32 *)(temp_3 + 0x30) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x34) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    *(s32 *)(temp_3 + 4) = 0;
}

// FUN_003550D0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003550d0);
// FUN_00355190
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355190);
// FUN_003552D0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003552d0);
// FUN_00355300
void func_00355300(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = arg1;
}

// FUN_00355310
void func_00355310(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(arg1 + 4) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    if (arg2 != NULL) {
        *(f32 *)(arg2 + 0) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(arg2 + 4) = (f32) *(f32 *)(temp_3 + 0x14);
    }
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = (f32) *(f32 *)(temp_3 + 0x20);
        *(f32 *)(arg3 + 4) = (f32) *(f32 *)(temp_3 + 0x24);
    }
}

// FUN_00355370
void func_00355370(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(temp_4 + 0x38) = 0x3F800000;
        *(u32 *)(temp_4 + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(temp_4 + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(temp_4 + 0x3C) = *(f32 *)(arg1 + 4);
    }
}



// FUN_003553B0
void func_003553b0(u8 *arg0, f32 *arg1)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(temp_16 + 0x38);
    arg1[1] = *(f32 *)(temp_16 + 0x3C);
}



/* measured: the read and the write of the same field must use DIFFERENT
   spellings. Written identically both times, b210 CSEs the address into a
   callee-saved register (addiu $s0, $v1, 0x40 then sw at 0) and leaves the
   struct pointer in a caller-saved one; retail keeps the POINTER in $s0 and
   stores at 0x40($s0). Reading through the array index and writing through the
   cast-and-offset breaks the CSE and the function matches exactly. Same shape
   in func_0035aec0 and func_0035be70. */

// FUN_00355410
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355410);

// FUN_00355430
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355430);
// FUN_00355460
s32 func_00355460(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[16] == 0) && (*(u16 *)(p + 8) != 0)) {
        *(s32 *)(p + 0x40) = func_00354830(p + 0x144);
    }
    return 0;
}

// FUN_003554B0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003554b0);
// FUN_00355550
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355550);
// FUN_003556A0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003556a0);
// FUN_00355740
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355740);
// FUN_003558A0
s32 func_003558a0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_16 + 0x1F8) = 0;
    *(s32 *)(temp_16 + 0x1FC) = 0;
    func_00460ac0((u8 *)&D_00793E80 + (*(s32 *)(temp_16 + 0x228) * 0x30), temp_16 + 0x1F8);
    if (!(*(s32 *)(temp_16 + 8) & 4)) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}

// FUN_00355920
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355920);
// FUN_00356140
void func_00356140(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}



/* measured: retail's missing sd/ld pair for the 64-bit first argument requires
   a stack array plus the direct pointer-dereference call expression. The
   full callee prototype is retained; its two explicit 0.0f tail arguments
   account for the remaining f-register residual. Best candidate nd 19,
   object 96B/window 96B; archive
   build/WBCode1_0035_func_00356170_nd19_archive.txt. Ruled out scalar saved0
   (nd58,obj88/96), no-saved/full-call variants (nd59/58), three-float casts
   and pragma/order variants (nd61/27/63/76). Committed at nd 19. */
// FUN_00356170 NONMATCHING
#ifdef NON_MATCHING
void func_00356170(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 f0, f32 f1) {
    s64 saved0[1];
    s32 saved1;
    s32 var8;
    u8 sel;
    saved0[0] = arg0;
    saved1 = arg1;
    var8 = arg3;
    sel = ((u8 *)&saved1)[3];
    if (sel != 0xFF)
        var8 = 0;
    func_00365f00(f0, f1, 1.0f, 0.0f, *(s64 *)((u8 *)saved0), saved1, saved1, arg2, var8, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356170);
#endif
/* measured: stack-frame and mixed-ABI call body reaches nd 7 in isolation at
   object 116B/window 128B; residual call-setup order remains at offsets
   0x40-0x4C. nd_audit compiles the whole file with NON_MATCHING defined, which
   activates func_00356170's preserved body alongside this one and shifts it to
   nd 15. Committed at nd 15. */
// FUN_003561D0 NONMATCHING
#ifdef NON_MATCHING
void func_003561d0(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 dummy, f32 f0, f32 f1)
{
    struct Frame { s64 saved0; s32 saved1; f32 temp; } frame;
    s32 var8;
    u8 sel;
    f32 scaled;
    f32 one;
    f32 shifted;
    s64 call0;
    s32 call1;

    frame.saved0 = arg0;
    frame.saved1 = arg1;
    scaled = f0 / iGpffff83d4;
    shifted = iGpffff8544 + f1;
    var8 = arg2;
    frame.temp = *(f32 *)((u8 *)&frame.saved1);
    sel = ((u8 *)&frame.temp)[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    one = 1.0f;
    call0 = *(s64 *)((u8 *)&frame.saved0);
    call1 = frame.saved1;
    func_00365f00(dummy, scaled, shifted, one, call0, call1, call1, 4, var8, one);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003561d0);
#endif

// FUN_00356250
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356250);
// FUN_00356820
s32 func_00356820(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00356870
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356870);
// FUN_00356A10
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356a10);
// FUN_00359340
void func_00359340(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x960);
    }
}

// FUN_003593B0
void func_003593b0(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}



// FUN_003593E0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003593e0);
// FUN_00359400
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00359400);
// FUN_003596A0
s32 func_003596a0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 43) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x17C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00359720
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00359720);
// FUN_003597F0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003597f0);
// FUN_003598D0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003598d0);
// FUN_003599A0
void func_003599a0(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}



// FUN_003599C0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003599c0);
// FUN_0035AC60
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035ac60);
// FUN_0035ADC0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035adc0);
// FUN_0035AEC0
s32 func_0035aec0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(s8 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035AF10
void func_0035af10(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035AF60
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035af60);
// FUN_0035AFA0
s32 func_0035afa0(u8 *arg0) {
    s32 var_2;
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if ((*(s32 *)(temp_3 + 0x2C) == 0) || (*(s8 *)(temp_3 + 0x20) == 0)) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return (s32)(**(s32 **)(temp_3 + 0x3C));
    }
    return 0;
}

// FUN_0035AFF0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035aff0);
// FUN_0035BAD0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bad0);
// FUN_0035BC10
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bc10);
// FUN_0035BD20
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bd20);
// FUN_0035BE70
s32 func_0035be70(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(u16 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035BEC0
void func_0035bec0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035BF10
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bf10);
// FUN_0035C040
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035c040);
// FUN_0035C480
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035c480);
// FUN_0035C670
void func_0035c670(u8 *arg0, f32 *arg1)
{
    *(Float2 *)arg1 = *(Float2 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_0035E820
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035e820);
// FUN_0035E8B0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035e8b0);
// FUN_0035EF80
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035ef80);
// FUN_0035F020
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035f020);
// FUN_0035F0C0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035f0c0);
// FUN_0035FC40
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035fc40);
// FUN_0035FC90
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035fc90);
// FUN_0035FD60
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035fd60);
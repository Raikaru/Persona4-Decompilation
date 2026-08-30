#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldEnvironment.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00161460(s32 arg0, s32 arg1, s32 arg2);
extern void func_00161500(s32 arg0);

extern s16 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s64 arg0, s32 arg1);
extern s32 func_00154720(u16 arg0, u16 arg1, s64 arg2);
extern s32 func_00106330(s32 arg0);
extern u8 *func_0015a0c0(void);

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern char D_005EFE50[];
extern char D_005EFE68[];
extern void func_00153a00();
extern void func_00153a30();
extern s32 func_00451fc0();

extern s32 func_0014eec0(void);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442088();
extern s32 func_00454570(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern char D_005EFE78[];
extern char D_005EFED0[];
extern char D_005EFE90[];
extern s32 func_0014a2a0();
extern u8 *iGpffff9db0;
extern char iGpffff9e18;
extern char iGpffff9e20;
extern s32 func_004553c0(u8 *arg0);
extern u8 *func_00455f70(void *arg0, void *arg1);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_0043f9c8(void *arg0, s32 arg1, u32 arg2);
extern u8 *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 *func_00155280(void);
extern void func_0016e590();
extern void func_0016e9f0(s32 arg0, void *arg1);
extern void func_0016ea20(s32 arg0, f32 arg1);
extern void func_0016ea30(s32 arg0, f32 arg1);
extern void func_0016eaa0(s32 arg0, s32 arg1, void *arg2);
extern u8 *func_0016eaf0(s32 arg0);
extern void func_0016eb00(s32 arg0);
extern void func_0046d700(const char *arg0, s32 arg1, void *arg2, void *arg3);
extern void func_00454bd0(u8 *arg0);
extern char D_005EFEF0[];

typedef struct CmrVec3 {
    f32 x;
    f32 y;
    f32 z;
} CmrVec3;



// FUN_00153A60
s32 func_00153a60(s32 arg0) {
    u8 *p;
    s32 result;

    func_0044ea90(&D_005EFE50[0], 0x58);
    p = D_008873F4[0](1, 0x14, 0x40000);
    if (p == NULL) {
        return 0;
    }
    result = func_00451fc0(arg0, &D_005EFE68[0], 0xF, 0, 0, func_00153a00, func_00153a30, p);
    *(s32 *)(p + 0x8) = 1;
    *(s32 *)(p + 0xC) = 0xC8;
    return result;
}

// FUN_00153B20
void func_00153b20(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 0x4) = arg1;
    func_00161460(arg1, *(s32 *)(p + 0x8), *(s32 *)(p + 0x10));
}
// FUN_00153B60
void func_00153b60(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 8) = arg1;
    func_00161460(*(s32 *)(work + 4), arg1, *(s32 *)(work + 0x10));
}



// FUN_00153B90
void func_00153b90(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0x10) = arg1;
    func_00161460(*(s32 *)(work + 4), *(s32 *)(work + 8), arg1);
}

// FUN_00153BD0
void func_00153bd0(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0xC) = arg1;
    func_00161500(arg1);
}

// FUN_00153C00
s32 func_00153c00(s32 arg0) {
    char spA0[0x80];
    char sp20[0x80];
    s32 g;

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        func_00442830(&spA0, D_005EFE78);
        if (func_0014a2a0(*(u16 *)iGpffff9db0, arg0 & 0xFFFF) != 0) {
            func_00442088(&sp20, D_005EFE90, *(s32 *)iGpffff9db0 - 0x14, arg0);
        } else {
            func_00442088(&sp20, D_005EFE90, *(s32 *)iGpffff9db0, arg0);
        }
        g = *(s32 *)iGpffff9db0;
        if ((g >= 0x33) && (g < 0x3B)) {
            func_00442088(&sp20, D_005EFE90, g - 0x1E, 0);
        }
        if (func_00454570(&sp20) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x1A1);
        return (s32)func_00454a60(&sp20, 0);
    }
    return 1;
}

/* measured: func_00153d60 (nd 547). ~30 locals -> mwcc spills to frame -0x110
   vs retail -0xB0 (0x60 extra), so the whole function diverges. Retail save
   set is $31/$19/$18/$17/$16/$f20; sp60=0x4C@0x60, spAC=0x4@0xAC. Complex
   batched float copies (var_16+0x80..0x9C, 0x13C..0x158 etc. load-all-then-
   store-all) need struct assignments (brief lever 5); the 0x10001..0x10008
   version guards are `x < N` (sltu $at + bnez, brief lever 2). m2c's
   (f32)(s32) casts on float fields are wrong (plain lwc1/swc1). Data globals
   at gp-0x45B8..-0x4594 are iGpffffba48..ba6c. func_0047a310/00452080 take
   pointer args loaded from [off] (need void* casts). */
// FUN_00153D60
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153d60);
// FUN_001546A0
void func_001546a0(u16 arg0, u16 arg1)
{
    func_00154720(arg0, arg1, func_00110960(func_001060b0(), func_001060c0() & 0xFF));
}

/* measured: block-3 func_0015a0c0 handling. Retail places the non-NULL load
   OUT OF LINE (bnez $v0, load; b return; load: lbu; move; b return) spanning
   8 instructions; the plain if/else and empty-if+else both compile the load
   inline (beqz skip; lbu inline), shrinking the block by 8B and shifting the
   switch dispatch + every later branch target by one word (nd 142). switch
   form over the boolean adds a jump table (nd 196). Return type is s32
   (retail does move $v0,$sN, no dsll32/dsra32 truncation; m2c's s16 is wrong).
   var_18=$s2, var_19=$s3 (declare var_18 second). Case 5 of the jtbl_00746C20
   switch goes straight to block_42 (own empty case needed). */
/* measured: discarded positive-branch candidate object 980B/window 1008B, normalized_diff 232; restored to bare INCLUDE_ASM. */
// FUN_00154720
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00154720);

// FUN_00154B10
s32 func_00154b10(void) {
    char sp90[0x80];
    char sp10[0x80];

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        func_00442830(&sp90, D_005EFE78);
        func_00442088(&sp10, D_005EFED0, *(s32 *)(iGpffff9db0 + 0), *(s32 *)(iGpffff9db0 + 4));
        if (func_00454570(&sp10) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x571);
        return (s32)func_00454a60(&sp10, 0);
    }
    return 1;
}

/* measured: func_00154be0 (nd 110, obj 1188B vs window 1168B). Frame -0xF0
   correct once spA0=0x4C@0xA0, spEC=0x4@0xEC (declared spEC first). Residuals:
   (1) copy-loop source ptr colored $a2 instead of retail $a1 -- register alloc;
   (2) the 3-float store at var_16+0x54..0x5C to arg5 needs ONE struct assignment
   (retail loads $f2,$f1,$f0 then stores all three; per-field statements
   interleave) -- brief lever 5;
   (3) the 0x10001/0x10002 guards must be written `x < 0x10001` (sltu $at +
   bnez) not `x >= 0x10001` -- brief lever 2 comparison form;
   (4) 20 extra bytes of body code. The double `if (var_16==NULL){return 1}
   if(var_16==NULL){func_0046d700...}` mirrors retail's dead func_0046d700 block.
   func_003e9cb0 first arg is a pointer loaded from [4] (cast to void*). */
// FUN_00154BE0
s32 func_00154be0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, s32 *arg4,
                  u8 *arg5, f32 *arg6, f32 *arg7, s32 *arg_sp0, s32 *arg_sp8)
{
    char spEC[4];
    char spA0[0x4C];
    u8 *data;

    if (arg0 == 0) {
        return 1;
    }
    if ((func_0014eec0() == 0) && (func_004553c0(arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        data = *(u8 **)(arg0 + 0x110);
    } else {
        func_00442088(&spA0, D_005EFEF0,
                      *(s32 *)iGpffff9db0, *(s32 *)(iGpffff9db0 + 4));
        data = func_00455f70(&spA0, &spEC);
        if (data == 0) {
            return 1;
        }
        if (data == 0) {
            func_0046d700(D_005EFE50, 0x5A1, &iGpffff9e20, &spA0);
        }
    }
    if (arg1 != 0) {
        s32 *src;
        s32 count;
        s32 first;
        s32 second;

        src = (s32 *)(data + 0x10);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)arg1 = first;
            *(s32 *)(arg1 + 4) = second;
            arg1 += 8;
        } while (count > 0);
        *arg3 = *(f32 *)(data + 8);
        *arg4 = *(u16 *)(data + 0x50);
        *(CmrVec3 *)arg5 = *(CmrVec3 *)(data + 0x54);
        *arg6 = *(f32 *)(data + 0x60);
        *arg7 = *(f32 *)(data + 0x64);
        if (*(u32 *)(data + 4) > 0x10000U) {
            func_0043f810(arg_sp0, data + 0x68, 0x20);
            func_0043f810(arg_sp8, data + 0x88, 0x180);
        } else {
            func_0043f9c8(arg_sp0, 0, 0x20);
            func_0043f9c8(arg_sp8, 0, 0x180);
        }
        if (*(u32 *)(data + 4) > 0x10001U) {
            src = (s32 *)(data + 0x210);
            count = 8;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)arg2 = first;
                *(s32 *)(arg2 + 4) = second;
                arg2 += 8;
            } while (count > 0);
        } else {
            *(f32 *)(arg2 + 0x28) = 1.0f;
            *(f32 *)(arg2 + 0x14) = 1.0f;
            *(f32 *)(arg2 + 0) = 1.0f;
            *(f32 *)(arg2 + 0x10) = 0.0f;
            *(f32 *)(arg2 + 8) = 0.0f;
            *(f32 *)(arg2 + 4) = 0.0f;
            *(f32 *)(arg2 + 0x24) = 0.0f;
            *(f32 *)(arg2 + 0x20) = 0.0f;
            *(f32 *)(arg2 + 0x18) = 0.0f;
            *(f32 *)(arg2 + 0x38) = 0.0f;
            *(f32 *)(arg2 + 0x34) = 0.0f;
            *(f32 *)(arg2 + 0x30) = 0.0f;
            *(s32 *)(arg2 + 0xC) |= 0x20003;
        }
    } else {
        s32 i;
        s16 id;
        s32 *src;
        s32 count;
        u8 *dst;
        s32 first;
        s32 second;

        func_004577d0(func_00457120(), *(f32 *)(data + 8));
        func_003e9cb0((void *)*(s32 *)(func_00457120() + 4),
                      data + 0x10, 0);
        func_0016e590(func_00155280()[1], *(u16 *)(data + 0x50));
        func_0016e9f0(func_00155280()[1], data + 0x54);
        func_0016ea20(func_00155280()[1], *(f32 *)(data + 0x60));
        func_0016ea30(func_00155280()[1], *(f32 *)(data + 0x64));
        for (i = 0; i < 0x20; i++) {
            id = *(s8 *)(data + 0x68 + i);
            if (id <= -1) {
                goto CMR_loop_skip;
            }
            func_0016eaa0(func_00155280()[1], id,
                          data + i * 0xC + 0x88);
CMR_loop_skip:
            ;
        }
        if ((u32)*(s32 *)(data + 4) < 0x10002U) {
            *(f32 *)(arg2 + 0x28) = 1.0f;
            *(f32 *)(arg2 + 0x14) = 1.0f;
            *(f32 *)(arg2 + 0) = 1.0f;
            *(f32 *)(arg2 + 0x10) = 0.0f;
            *(f32 *)(arg2 + 8) = 0.0f;
            *(f32 *)(arg2 + 4) = 0.0f;
            *(f32 *)(arg2 + 0x24) = 0.0f;
            *(f32 *)(arg2 + 0x20) = 0.0f;
            *(f32 *)(arg2 + 0x18) = 0.0f;
            *(f32 *)(arg2 + 0x38) = 0.0f;
            *(f32 *)(arg2 + 0x34) = 0.0f;
            *(f32 *)(arg2 + 0x30) = 0.0f;
            *(s32 *)(arg2 + 0xC) |= 0x20003;
        }
        dst = func_0016eaf0(func_00155280()[1]);
        src = (s32 *)(data + 0x210);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)dst = first;
            *(s32 *)(dst + 4) = second;
            dst += 8;
        } while (count > 0);
        func_0016eb00(func_00155280()[1]);
    }
    if (func_0014eec0() == 0) {
        func_00454bd0(arg0);
    }
    return 1;
}
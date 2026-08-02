/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u16 *func_001102e0(void);
extern s32 func_00106330(s32);
extern void func_00145080(void);
extern s32 func_00452380(void *);
extern void func_003315a0(void);
extern void func_00454bd0(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern u32 func_003b7060(void);
extern s8 D_007490F8[];
extern u16 *func_0010ace0(s16);
extern s32 func_0010b6f0(void);
extern u8 func_00109280(s32);
extern s32 func_00331660(void);
extern s8 func_002bab80(void *);
extern void func_002badc0(s8, s32);
extern void func_002bbd80(s8, s32, void *);
extern s32 func_00110140(void);
extern void *func_001067f0(s16);
extern s16 D_00749040[];
extern s16 D_00749060[];
extern s16 D_00749080[];
extern s16 D_007490A0[];
extern s16 D_007490C0[];
extern s16 D_007490E0[];
extern s8 D_00749100[];
extern void func_002bafc0(s8, s32);
extern void func_002bb0a0(s8, s32);
extern void func_002bbf60(void);
extern u16 *func_002e48a0(s32, s32);
extern u32 func_0010ceb0(void *);
extern s32 func_0010cf40(void *, s16);
extern u16 *iGpffffb3ec;
extern u8 *iGpffffb594;
extern void func_0010fd40(void *);
extern void func_00106620(s16, s32);
extern void func_00106390(s32, s32);
extern void func_0044ea90(const void *, s32);
extern void func_0043f9c8(void *, s32, u32);
extern void func_0043f810(void *, void *, u32);
extern u8 *func_0010fcb0();
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00641B00[];
extern s32 func_0010b460(void);
extern void func_0010ad80(s32);
extern void func_0010b190(s16 *);
extern void func_0010b300(s32);
extern void func_0010b7f0(void);


// FUN_002E8410
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e8410);

// FUN_002E90D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e90d0);

// FUN_002EB270
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002eb270);

// FUN_002ECFC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002ecfc0);

// FUN_002ED430
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002ed430);

// FUN_002F0F00
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f0f00);

// FUN_002F6CF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f6cf0);

// FUN_002F9C30
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f9c30);

// FUN_002F9D90
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f9d90);

// FUN_002FBEA0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002fbea0);

/* measured: retail re-emits the s8->s32 promotion of the loop counter in
   place (dsll32/dsra32 $s2,24) right after func_002badc0 and uses it for
   (s16)(i + 0x464); mwcc b210 CSEs the loop-head extension into $s3 and
   skips the redundant re-promotion (2 words shorter, nd 36). Tried: natural
   C, explicit s32 iv local, schedule on (70), opt_propagation off (36),
   opt_common_subs off (74), declaration order p,key,i (40). */
// FUN_00302570
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00302570);

// FUN_003026C0
s32 func_003026c0(s32 arg0, s32 arg1)
{
    s16 i;

    func_00109280(arg0);
    for (i = 0; i < 4; i++) {
        if (func_00106330(0x130C - i) != 0) {
            return arg1 - (arg1 / 100) * (0x19 - i * 5);
        }
    }
    return arg1;
}

// FUN_00302770
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00302770);

// FUN_00303610
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303610);

// FUN_00303A20
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303a20);

// FUN_00303DE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303de0);

// FUN_003040D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003040d0);

// FUN_003042F0
s32 func_003042f0(s32 arg0, s32 arg1)
{
    switch ((s8)arg1) {
    case 1:
        return D_00749040[(s8)arg0];
    case 2:
        return D_00749060[(s8)arg0];
    case 3:
        return D_00749080[(s8)arg0];
    case 4:
        return D_007490A0[(s8)arg0];
    case 5:
        return D_007490C0[(s8)arg0];
    case 6:
        return D_007490E0[(s8)arg0];
    }
    return -1;
}

// FUN_00304410
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00304410);

// FUN_00304580
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00304580);

/* measured: same stack-lookup-table floor as func_00308e50 — retail loads
   tbl[i] via sll/addu($sp)/addiu(0x48)/lh ($v0); mwcc b210 folds the 0x48
   into the load displacement in every spelling (array-index nd 42,
   byte-offset arithmetic nd 42), shifting all following words by one. */
// FUN_00308CC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00308cc0);

// FUN_00308DC0
s32 func_00308dc0(void)
{
    s16 i;
    s32 temp;
    s8 *p;

    temp = (u8)(func_003b7060() % 100U);
    i = 0;
    p = D_007490F8;
    while (i < 6) {
        if (temp < p[i]) {
            return (s8)i;
        }
        i++;
    }
    return 5;
}
/* measured: retail loads the stack lookup table via sll/addu($sp)/addiu(0x48)
   then lh ($v0); mwcc b210 folds the 0x48 into the load displacement
   (sll/addu/lh 0x48($v0)) no matter the spelling — probed array-index,
   named pointer, byte-offset arithmetic, for-loop, initializer-list, and
   #pragma schedule on (nd 56); best nd 40. Same floor family as func_00308f40. */
// FUN_00308E50
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00308e50);

/* floor (above marker kept clear for the verifier): the array-address
   sequence sll/addu(sp)/addiu(0x48) vs mwcc's sll/addiu/addu with swapped
   $v0/$v1 coloring — probed array, pointer, named-temp, separate-locals,
   byte-offset forms and schedule/opt_* pragmas; best nd 4 (scheduling). */
// FUN_00308F40
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00308f40);

// FUN_003095F0
s32 func_003095f0(void)
{
    if (func_001102e0()[1] == 0xB3) {
        return 0xBA;
    }
    return 0xB3;
}

// FUN_00309630
s32 func_00309630(u16 arg0)
{
    s16 i;
    s32 key;

    i = 0;
    key = arg0;
    while (i < (u16)func_0010b6f0()) {
        if (key == *(u16 *)((u8 *)func_0010ace0(i) + 2)) {
            return 1;
        }
        i++;
    }
    return 0;
}
// FUN_003096D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003096d0);
/* floor (above marker kept clear for the verifier): pure saved-register
   coloring cycle — mwcc keeps the loop-head s16 mask in a 6th saved
   register for the return, pushing rem to $s5 and swapping inner/outer vs
   retail ($s4/$s3); probed declaration orders, do-while/while(1)+break
   shapes, ret-local, explicit casts — all nd 61 (retail 5 saved regs). */

// FUN_003097E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003097e0);

// FUN_0030B060
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b060);

// FUN_0030B7B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b7b0);

// FUN_0030C3C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030c3c0);

// FUN_0030F4F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030f4f0);

// FUN_0030F650
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030f650);

// FUN_00310480
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00310480);

// FUN_00310700
void func_00310700(void)
{
    s16 i;
    s16 j;

    func_0044ea90(&D_00641B00[0], 0x2ABD);
    iGpffffb594 = D_008873F4[0](1, 0x3004, 0x40000);
    func_0043f9c8(iGpffffb594, 0, 0x3000);
    i = 0;
    while (i < 0x100) {
        if (func_0010fcb0(i) != 0) {
            j = (s16)i;
            func_0043f810(iGpffffb594 + (s32)j * 0x30, func_0010fcb0(j), 0x30);
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 0;
        if (func_00106330((s16)i + 0x1309) != 0) {
            *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 1;
        }
        i++;
    }
}

// FUN_00310850
void func_00310850(void)
{
    s16 i;

    if (iGpffffb594 == NULL) {
        return;
    }
    i = 0;
    while (i < 0x100) {
        func_0010fd40(iGpffffb594 + i * 0x30);
        i++;
    }
    i = 0;
    while (i < 4) {
        if (*(s8 *)((u32)iGpffffb594 + i + 0x3000) == 1) {
            func_00106620((s16)(i + 0x464), 1);
            func_00106390(i + 0x1309, 1);
        }
        i++;
    }
    jtbl_008873EC[0](iGpffffb594);
    iGpffffb594 = NULL;
}

// FUN_00310960
void func_00310960(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *p;
    s8 t;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
    t = *(s8 *)(p + 0xD);
    func_002badc0(t, (s8)arg1);
    if ((s8)arg2 == 1) {
        func_002bafc0(*(s8 *)(p + 0xD), 0);
        func_002bb0a0(*(s8 *)(p + 0xD), 0);
        func_002bbf60();
    }
}
// FUN_00310A10
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00310a10);

// FUN_00310BF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00310bf0);

// FUN_003111D0
void func_003111d0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if (func_00106330(0x1459) == 0) {
        func_00145080();
    }
    if (func_00452380(D_00641BC8) != 0) {
        func_003315a0();
    }
    func_00454bd0(*(void **)(p + 0x10));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00311260
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00311260);

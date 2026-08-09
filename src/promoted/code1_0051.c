#include "include_asm.h"
#include "type.h"


extern u8 *D_00745888[];

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and retail fills it with the final addiu (nd 6 -> 0). */

// FUN_00510740
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510740);
// FUN_005107A8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005107a8);
// FUN_00510808
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510808);
// FUN_00510870
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510870);
// FUN_005108C8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005108c8);
// FUN_00510910
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510910);
// FUN_00510968
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510968);
// FUN_005109C0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005109c0);
// FUN_00510A28
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510a28);
// FUN_00510A98
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510a98);
// FUN_00510AF8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510af8);
// FUN_00510B58
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510b58);
// FUN_00510BC0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510bc0);
// FUN_00510CE0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510ce0);
// FUN_00510D90
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510d90);
// FUN_00510E30
#pragma schedule on
u8 **func_00510e30(void) {
    return (u8 **)D_00745888;
}
/* measured: closes the schedule bracket for func_00510e30. */
#pragma schedule off


extern u8 *D_00745888[];

/* measured: mwcc b210 coalesces the global base into $v0 (lui $v0 / lw $v0, 0($v0));
   retail 2.4.1.01 keeps the base in $v1 (lui $v1 / lw $v0, %lo($v1)). nd 2 (the two
   rt-register bytes). Tried typed pointer local, (u32) integer base, scalar-extern,
   result locals, single-expression chains, no-pragma (nd 6); best nd 2. This is the
   brief's corroborated "$v0/$v1 coalescing in tiny accessors" floor. */



extern u8 *D_00745AC0[];

/* measured: mwcc b210 coalesces the global base into $v0 (lui $v0 / lw $v0, 0($v0));
   retail 2.4.1.01 keeps the base in $v1 (lui $v1 / lw $v0, %lo($v1)). nd 2 (the two
   rt-register bytes). Tried typed pointer local, (u32) integer base, scalar-extern,
   result locals, single-expression chains, no-pragma (nd 6); best nd 2. This is the
   brief's corroborated "$v0/$v1 coalescing in tiny accessors" floor. */



extern u8 *D_00745AC0[];

/* measured: mwcc b210 emits lui $v0 / sw / jr / daddu $v0,$0,$0 (return const in
   the delay slot), base in $v0; retail 2.4.1.01 emits lui $v1 / daddu $v0,$0,$0 /
   jr / sw (store in the delay slot), base in $v1. nd 7 (rt byte + sw/daddu
   ordering). Tried pointer-local, (u32)-base, return-local, no-pragma (nd 6);
   best nd 7. $v0/$v1 coalescing floor (brief) + delay-slot preference. */

/* measured: schedule on is paired with opt_common_subs off for func_00513a40. */
#pragma schedule on

// FUN_00512760
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512760);

// FUN_005127E8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005127e8);

// FUN_005128A0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005128a0);

// FUN_00512B08
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512b08);

// FUN_00512B90
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512b90);

// FUN_00512BB0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512bb0);

// FUN_00512C70
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512c70);

// FUN_00512D90
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512d90);

// FUN_00512EA8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512ea8);

// FUN_00512EF8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512ef8);

// FUN_00512FA0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512fa0);

// FUN_00512FC8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00512fc8);

// FUN_00513168
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513168);

// FUN_005131B0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005131b0);

// FUN_005131D0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005131d0);

// FUN_00513278
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513278);

// FUN_00513290
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513290);

// FUN_005132A8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005132a8);

// FUN_005132C8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005132c8);

// FUN_00513380
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513380);

// FUN_005133A8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005133a8);

// FUN_00513410
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513410);

// FUN_00513568
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513568);

// FUN_00513720
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513720);

// FUN_005137A0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005137a0);

// FUN_005137E0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005137e0);

// FUN_005138A0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005138a0);

// FUN_00513948
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513948);

// FUN_00513A20
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513a20);
// FUN_00513A40
/* measured: retail materialises the global's address once and keeps it live
   across the store; b210 shares that address with the returned constant
   unless common-subexpression sharing is off (nd 7 -> byte-exact). */
#pragma opt_common_subs off
s32 func_00513a40(u8 *arg0) {
    D_00745AC0[0] = arg0;
    return 0;
}
// FUN_005178C0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005178c0);

// FUN_00517928
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517928);

/* measured: closes the opt_common_subs bracket for func_00513a40. */
#pragma opt_common_subs on
/* measured: closes the schedule bracket for func_00513a40. */
#pragma schedule off



/* Direct stores matched the retail values but not its address-materialisation
   and delay-slot order: active direct C was nd 6 (obj 12B/window 16B), with
   fndiff rows 0 sw $zero,0x200($a0) vs addiu $a0,$a0,0x1fc; 4 jr $ra vs
   sw $zero,4($a0); 8 sw $zero,0x1fc($a0) vs jr $ra; 12 retail-only sw
   $zero,($a0). Pointer-local, store-order, and scheduler probes were ruled
   out. Committed at nd 6. */

// FUN_005179E8 NONMATCHING
#ifdef NON_MATCHING
void func_005179e8(u8 *arg0) {
    *(s32 *)(arg0 + 0x1FC) = 0;
    *(s32 *)(arg0 + 0x200) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005179e8);
#endif


typedef struct {
    s32 unk_0; /* 0 */
    s32 unk_4; /* 4 */
} Unit17C18;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 6 -> 0). */

// FUN_005179F8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_005179f8);
// FUN_00517AA0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517aa0);
// FUN_00517AB8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517ab8);
// FUN_00517AD0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517ad0);
// FUN_00517B80
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517b80);
// FUN_00517C18
#pragma schedule on
void func_00517c18(Unit17C18 *arg0, s32 arg1, s32 arg2) {
    arg0->unk_4 = arg2;
    arg0->unk_0 = arg1;
}
/* measured: closes the schedule bracket for func_00517c18. */
#pragma schedule off


/* measured: exhaustive C spellings (direct chain; u8/s32/u32/void pointer locals;
   base/result locals; typed argument variants; explicit assignments and casts)
   all produce object 12B/16B at nd 2; schedule-off and O1 both worsen to nd 7
   with a 16B object. The intermediate pointer remains in $v0 instead of retail's
   $v1; this is the irreducible tiny-accessor coloring floor. Committed at nd 2. */

#pragma schedule on

// FUN_00517C28
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517c28);

// FUN_00517CF0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517cf0);

// FUN_00517D18
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d18);

// FUN_00517D30
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d30);

// FUN_00517D48
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d48);

// FUN_00517D68
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d68);

// FUN_00517D80
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d80);

// FUN_00517D88
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d88);

// FUN_00517D90
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517d90);

// FUN_00517DA8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00517da8);

// FUN_00519CC0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519cc0);

// FUN_00519CE0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519ce0);

// FUN_00519D00
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519d00);

// FUN_00519D20
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519d20);

// FUN_00519D40
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519d40);

// FUN_00519DE8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519de8);

// FUN_00519DF0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519df0);

// FUN_00519E90
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519e90);
// FUN_00519EE0 NONMATCHING
/* measured: exhaustive C spellings (direct chain; u8/s32/u32/void pointer locals;
   base/result locals; typed argument variants; explicit assignments and casts)
   all produce object 12B/16B at nd 2; schedule-off and O1 both worsen to nd 7
   with a 16B object. Retail words: 0 7c1f838c lw $3, 0x1f7c($4); 4 0800e003
   jr $31; 8 2000628c lw $2, 0x20($3) in the delay slot; 12 00000000 nop.
   The intermediate pointer remains in $v0 instead of retail's $v1; this is
   the irreducible tiny-accessor coloring floor. Committed at nd 2. */
#ifdef NON_MATCHING
s32 func_00519ee0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1F7C);
    return *(s32 *)(p + 0x20);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519ee0);
#endif
/* measured: closes the schedule bracket above and restores the -O2 baseline. */
#pragma schedule off


/* measured: exhaustive C spellings (direct chain; u8/s32/u32/void pointer locals;
   base/result locals; typed argument variants; explicit assignments and casts)
   all produce object 12B/16B at nd 2; schedule-off and O1 both worsen to nd 7
   with a 16B object. Retail words: 0 c01f838c lw $3, 0x1fc0($4); 4 0800e003
   jr $31; 8 7c00628c lw $2, 0x7c($3) in the delay slot; 12 00000000 nop.
   The intermediate pointer remains in $v0 instead of retail's $v1; this is
   the irreducible tiny-accessor coloring floor. Committed at nd 2. */

// FUN_00519EF0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519ef0);

// FUN_00519FA0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00519fa0);

// FUN_0051A090
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051a090);

#pragma schedule on

// FUN_0051F5E8 NONMATCHING
#ifdef NON_MATCHING
s32 func_0051f5e8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    return *(s32 *)(p + 0x7C);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051f5e8);
#endif
/* measured: closes the schedule bracket for func_0051f5e8. */
#pragma schedule off


/* measured: without #pragma schedule on, the sw does not fill the jr $ra
   delay slot (nd 2 -> 0); the function returns the loaded pointer, which is
   what keeps it in $v0. */

// FUN_0051F5F8
#pragma schedule on
u8 *func_0051f5f8(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x1FC0);
    *(s32 *)(p + 0x80) = arg1;
    return p;
}
/* measured: closes the schedule bracket for func_0051f5f8. */
#pragma schedule off

// FUN_0051F608
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051f608);
// FUN_0051F6A8
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051f6a8);
// FUN_0051FDC0
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051fdc0);
// FUN_0051FE38
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051fe38);
// FUN_0051FF78
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_0051ff78);
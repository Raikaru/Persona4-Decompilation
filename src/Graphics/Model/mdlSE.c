/* Consolidated Persona 4 source units. */
/* Original translation unit mdlSE.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90();
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007241D8;
extern s32 func_00477c40(u16 arg0, u16 arg1, s32 arg2);
extern s32 iGpffffbb40;
extern u8 D_00922C10[];
extern u8 D_00922C14[];
extern u8 D_00922C16[];
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_0045a570(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 func_004553c0(void *arg0);
extern void func_00454bd0(void *arg0);
extern s32 func_00455ea0(void *arg0, s32 arg1, s32 *arg2);
extern s32 func_0045a890(s16 arg0);
extern s32 func_003b7060(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0047df40(s32 arg0, s32 arg1);


// FUN_0047DEA0
void *func_0047dea0(s16 arg0, s16 arg1, s16 arg2)
{
    void *temp_2;

    func_0044ea90(&D_007241D8, 0x2B);
    temp_2 = jtbl_008873E8[0](0x28, 0x40000);
    func_0043f9c8(temp_2, 0, 0x28);
    *(s32 *)((u8 *)temp_2 + 8) = 1;
    *(s16 *)((u8 *)temp_2 + 0xC) = arg0;
    *(s16 *)((u8 *)temp_2 + 0xE) = arg1;
    *(s16 *)((u8 *)temp_2 + 0x10) = arg2;
    return temp_2;
}


/* measured: retail recomputes the D_00922C10 + index*8 base twice in the first
   loop (once for the == check, once for the func_00477c40 arg) and uses a
   bottom-of-loop sltiu/bnez test; mwcc b210 CSEs the base into one register and
   reuses it across the if/else, so the object is 24B short (408B vs 432B).
   Tried hoisted masks, u32 params, integer-domain (u32)D_00922C10 cast, and
   loop restructures -- all nd 90. CSE-of-base floor. */
// FUN_0047DF40
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047df40);


/* measured: nd 160. Modulo fixed (divu not __moddi3) and object size is right
   (840-844B vs 848B window), but the saved-register allocation is rotated:
   retail keeps arg0 in $s1, arg2 in $s0, (s16)arg1 in $s5, temp_20 in $s4,
   temp_19 in $s3, count in $s2; mwcc b210 keeps arg0 in $s2, arg2 in $s1,
   (s16)arg1 in $s0, temp_20 in $s5, temp_19 in $s4, count in $s3. Tried the
   temp_20 operand order both ways (arg1*0xC first vs arg2*0x60 first) and the
   m2c declaration order -- arg0 stays in $s2. Saved-register rotation floor. */
// FUN_0047E0F0
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e0f0);


// FUN_0047E440
s64 func_0047e440(void) {
    return 0;
}


/* measured: archived best C body remains nd 5, object 668/window 672.
   Retail's five-byte cluster is ordinary integer align-up materialisation,
   not COP2/VU0 or COP1 MAC: retail keeps the pre-shift sum in $v1 and the
   shifted result in $v0, while b210 coalesces both through $v0. Tested the
   >>6 correction and additional lifetime/declaration/type/register spellings;
   none changed the nd or closed the register-class residual. */
// FUN_0047E450 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e450);


/* measured: nd 128. All structure matches (frame 0x60, switch, case 1/2 bodies,
   func_00455ea0/0045a570 arg grouping) but the saved-register allocation is
   rotated: retail keeps arg0 in $s0, node in $s1, temp_18 in $s2, temp_19 in
   $s3; mwcc b210 keeps node in $s0, temp_19 in $s1, temp_18 in $s2, arg0 in $s3.
   Tried every declaration order (sp-locals first, temp_17 after temp_18/19,
   *arg0 in place of temp_4 in the case bodies) -- arg0 stays in $s3. Saved-
   register rotation floor. */
// FUN_0047E6F0
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e6f0);

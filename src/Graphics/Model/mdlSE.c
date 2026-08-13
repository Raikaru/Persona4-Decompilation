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


/* measured: archive nd 5. Frame, case dispatch/allocation, calls, stack copies,
   and loop body match retail. Remaining five words are the align-up temporary
   and result register pair: retail uses $v1/$v0 while b210 emits the opposite
   pair at offsets 0x1FE, 0x200, 0x202, 0x206, and 0x20E. Previous probes
   exhausted declaration/order/type/liveness/pragma/permuter variants. */
/* object 668 / window 672 / normalized_diff 5 / differing offsets 0x1FE, 0x200, 0x202, 0x206, 0x20E. Probe list: corrected func_0044ea90 declaration from typed (u8 *, s32) to old-style extern void func_0044ea90(); measured no change; archive body retained as best result. Prior lane exhausted signed/unsigned parameter and align-local widths, declaration order, pointer-slot and array forms, loop/guard polarity, arithmetic/cast spellings, local reuse/liveness, argument types, pragmas, and a 600-second permuter run. */
// FUN_0047E450 NONMATCHING
#ifdef NON_MATCHING
void func_0047e450(void **arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4)
{
    s32 arg3_p = arg3;
    void ** arg0_p = arg0;
    s32 sp16C;
    u8 sp70[0x100];
    s32 sp180[3];
    s32 sp170[3];
    void *temp_16;
    void *temp_2;
    void *temp_2_2;
    void *temp_2_3;
    void *temp_4_2;
    void *temp_4_3;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_5;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_4_4;
    s32 var_16;
    s32 var_17;
    s32 var_2;

    var_17 = arg3_p;
    temp_5 = *arg0;
    if ((temp_5 == NULL) || ((*(u16 *)((u8 *)temp_5 + 0x12) & 1) == 0)) {
        temp_4 = (u16)arg1;
        switch (temp_4) {
        case 1:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2, 0, 0x28);
                *(s32 *)((u8 *)temp_2 + 8) = 1;
                *(s16 *)((u8 *)temp_2 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2 + 0x10) = 1;
                *arg0 = temp_2;
            }
            temp_16 = *arg0_p;
            func_0044ea90(&D_007241D8, 0x49);
            temp_2_2 = jtbl_008873E8[0](arg4, 0x40000);
            *(void **)((u8 *)temp_16 + 0) = temp_2_2;
            func_0043f810(temp_2_2, (void *)var_17, arg4);
            temp_4_2 = *arg0_p;
            *(u16 *)((u8 *)temp_4_2 + 0x12) &= 0xFFFD;
            temp_4_3 = *arg0_p;
            *(u16 *)((u8 *)temp_4_3 + 0x12) |= 1;
            return;
        case 2:
            if (temp_5 == NULL) {
                func_0044ea90(&D_007241D8, 0x2B);
                temp_2_3 = jtbl_008873E8[0](0x28, 0x40000);
                func_0043f9c8(temp_2_3, 0, 0x28);
                *(s32 *)((u8 *)temp_2_3 + 8) = 1;
                *(s16 *)((u8 *)temp_2_3 + 0xC) = (s16)arg1;
                *(s16 *)((u8 *)temp_2_3 + 0xE) = (s16)arg2;
                *(s16 *)((u8 *)temp_2_3 + 0x10) = 2;
                *arg0 = temp_2_3;
            }
            *(s32 *)((u8 *)(*arg0_p) + 0x14) = 0;
            *(s32 *)((u8 *)(*arg0_p) + 4) = func_0047df40(arg1, arg2);
            var_16 = 0;
            while (var_16 < 3) {
                func_0043f810(sp70, (void *)var_17, 0x100);
                temp_4_4 = var_17 + 0x100;
                sp180[var_16] = temp_4_4;
                sp16C = *(s32 *)(sp70 + 0xFC);
                sp170[var_16] = sp16C;
                var_2 = sp16C + 0x3F;
                temp_3_2 = var_2 >>= 7;
                if (var_2 < 0) {
                    temp_3_2 = (var_2 + 0x3F) >> 6;
                }
                var_17 = temp_4_4 + (temp_3_2 << 6);
                var_16 += 1;
            }
            func_0045a570((s16)*(s32 *)((u8 *)(*arg0) + 4), sp180[0], sp170[0], sp180[1], sp170[1], sp180[2], sp170[2]);
            temp_4_5 = *arg0_p;
            *(u16 *)((u8 *)temp_4_5 + 0x12) |= 8;
            temp_4_6 = *arg0_p;
            *(u16 *)((u8 *)temp_4_6 + 0x12) |= 2;
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e450);
#endif


/* measured: nd 128. All structure matches (frame 0x60, switch, case 1/2 bodies,
   func_00455ea0/0045a570 arg grouping) but the saved-register allocation is
   rotated: retail keeps arg0 in $s0, node in $s1, temp_18 in $s2, temp_19 in
   $s3; mwcc b210 keeps node in $s0, temp_19 in $s1, temp_18 in $s2, arg0 in $s3.
   Tried every declaration order (sp-locals first, temp_17 after temp_18/19,
   *arg0 in place of temp_4 in the case bodies) -- arg0 stays in $s3. Saved-
   register rotation floor. */
// FUN_0047E6F0
INCLUDE_ASM("asm/nonmatchings/mdlSE", func_0047e6f0);

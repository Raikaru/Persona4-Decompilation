/* Original translation unit fclCombineMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
extern s32 func_003124a0();
extern s32 func_003127e0();
extern u32 func_003b7060();
extern s16 func_002e54c0(s8 arg0, s16 arg1);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0046d730(const char *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0010cad0();
extern u8 *iGpffffb3d4;
extern char D_00642F30[];
extern s32 func_00312220(u16 *arg0, s32 arg1, u16 *arg2, s32 arg3);
extern u8 func_00311ea0(u8 *arg0, u8 *arg1, u8 *arg2);
extern s32 func_003130e0(u32 arg0, s32 arg1, u16 *arg2);
extern s32 func_00106330(s32 id);
extern u8 D_006420A0[];
extern u8 D_00642F00[];
extern u8 D_00642F04[];

/* measured: structure fully recovered (16B ptr[4] zero loop, 3-pair s8 copy
   from iGpffffa8d0 to sp58, 3-iteration bubble sort by ptr[][4] then
   iGpffffb3d4[ptr[][2]*14+2] tiebreak into sp4C, the t18/t16/t17 loads and
   D_00642727/D_00642967 min*24+max lookups) but mwcc b210 allocates the
   s16 sort-loop counter to $a3 (retail $a0) and reorders the D_00642727
   index computation (t17*24 before +t16; retail t16*24 before +t17), and
   the object is 836B vs 896B window (15 words short). Tried s16/s32 loop,
   indexed vs pointer-increment sp58 copy, named sp4C swap temp; nd 193.
   Register-allocation + tail-order floor. */
// FUN_00311EA0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00311ea0);

/* measured: 128-bit-slot wall (same as FUN_003130E0): retail loads spA0 from
   D_00642F04+arg1*8 into a quadword slot (lw $2; sq $2,0xA0) and tests the
   0x18-iteration loop with `lq $2,0xA0; slt $2,$18,$2` (raw quadword
   compare, no narrowing). The full C probe was 664B vs the 640B retail
   window (normalized_diff 381); mwcc b210's `u_long128` read-back still
   lowers through a scalar load, so the slot/compare floor remains. Probe
   discarded. */
// FUN_00312220
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312220);

/* measured: structure fully recovered (sp8C/sp8E pair, func_00312220 gate,
   temp_16/temp_20 from iGpffffb3d4+arg*14+2, func_002ac350() branch into
   D_00642147 vs D_00642387 min*24+max lookups, the sp70 zero+pair, the
   (base[arg1*14+3]+base[arg2*14+3])/2 rounding into temp_5_2, and the
   func_003133b0-vs-func_003130e0 dispatch on temp_16==base[arg*14+2]) but
   the measured C probe was 804B vs the 832B retail window (nd 539).
   mwcc b210 keeps temp_21 (arg2*14) in $s6 (retail frame 0x90 vs 0xA0
   candidate) and flips both result-table index add orders. Register-allocation
   + index-order floor; probe discarded. */
// FUN_003124A0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003124a0);

// FUN_003127E0
s32 func_003127e0(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u16 sp78[3];
    u8 sp60[0x18];
    s32 t;
    u16 ret;
    u8 *p;

    sp78[0] = *(u16 *)(arg1 + 2);
    sp78[1] = *(u16 *)(arg2 + 2);
    sp78[2] = *(u16 *)(arg3 + 2);
    if (arg0 == NULL || arg1 == NULL || arg2 == NULL || arg3 == NULL) {
        func_0046d730(D_00642F30, 0x1CC);
    }
    if (func_00312220(arg0, 1, sp78, 3) & 0xFF) {
        return 2;
    }
    t = func_00311ea0(arg1, arg2, arg3) & 0xFF;
    if (t == 0) {
        func_0043f9c8(arg0, 0, 0x30);
        return 0;
    }
    func_0043f9c8(sp60, 0, 0x18);
    *(u16 *)&sp60[0] = *(u16 *)(arg1 + 2);
    *(u16 *)&sp60[2] = *(u16 *)(arg2 + 2);
    *(u16 *)&sp60[4] = *(u16 *)(arg3 + 2);
    p = iGpffffb3d4 + 3;
    ret = func_003130e0(t, (((s32)p[*(u16 *)(arg1 + 2) * 0xE] + (s32)p[*(u16 *)(arg2 + 2) * 0xE] + (s32)p[*(u16 *)(arg3 + 2) * 0xE]) / 3 + 5) & 0xFF, (u16 *)sp60) & 0xFFFF;
    if (ret == 0) {
        return 0;
    }
    func_0010cad0(arg0, ret);
    return 1;
}

// FUN_003129B0
s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2) {
    s16 tbl[4];
    s16 i;
    s16 j;
    s32 a1;
    s32 a2;

    tbl[0] = 0xD;
    tbl[1] = 0x35;
    tbl[2] = 0x49;
    tbl[3] = 0x66;
    i = 0;
    a1 = arg1 & 0xFFFF;
    a2 = arg2 & 0xFFFF;
    while (i < 4) {
        if (a1 == tbl[i]) {
            j = 0;
            while (j < 4) {
                if (a2 == tbl[j]) {
                    return 0;
                }
                j++;
            }
        }
        i++;
    }
    j = 0;
    while (j < 4) {
        if (a1 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg2)), 0x30);
            return 1;
        }
        if (a2 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg1)), 0x30);
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_00312B60
s32 func_00312b60(s32 arg0, s32 arg1, s32 arg2) {
    return func_003124a0(arg0, arg1 & 0xFFFF, arg2 & 0xFFFF) & 0xFF;
}

// FUN_00312B90
s32 func_00312b90(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    return func_003127e0(arg0, arg1, arg2, arg3) & 0xFF;
}

// FUN_00312BC0
#pragma opt_rebuildconditionals off
/* measured: without this, mwcc b210 booleanizes `if (v < 0x40) return 1; return 0;`
   into slti $v0 + unconditional branch (return value = condition); retail keeps
   beqz $at -> shared return-0 + addiu $v0,1. Both branch orientations and the
   if/else forms tried (nd 24); with the pragma the switch body matches exactly. */
s32 func_00312bc0(s8 arg0) {
    s32 v;
    switch (arg0) {
    case 2:
        v = (s32)(func_003b7060() & 0x3F) << 6;
        if (v < 0x40) {
            return 1;
        }
        break;
    case 3:
        v = (s32)(func_003b7060() & 0x1F) << 5;
        if (v < 0x20) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
#pragma opt_rebuildconditionals on

/* measured: raw C reconstruction compiles to 1264B against the 1152B retail
   window with normalized_diff 924. Retail keeps a 0xA0 frame and maps the
   input/table locals to $s3/$fp/$s0/$s6; the straightforward typed loops
   grew a 0xB0 frame and rotated those saved registers. Probe discarded. */
// FUN_00312C60
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312c60);

/* measured: retail sq's arg0&0xFF into spA0 (0xA0) and lq's it back in the
   0xC0 i-loop, comparing via raw bne (lq $2,0xA0 / bne $2,$3). A full C
   probe with `u_long128 spA0` and aliased scalar read-back compiled to 772B
   against the 720B retail window (normalized_diff 528); mwcc b210 lowers the
   read-back through lw (not lq), and the full-value compare has no legal C
   data-size spelling. 128-bit-slot read floor; probe discarded. */
// FUN_003130E0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003130e0);

/* measured: identical 128-bit-slot wall to func_003130e0 (retail sq's
   arg0&0xFF into spA0 at 0xA0 and lq's it back in the 0xC0 i-loop, raw bne
   compare). A full C probe with the same aliased scalar read-back compiled
   to 788B against the 736B retail window (normalized_diff 541); mwcc b210
   lowers the read-back through lw (not lq), and the full-value compare has
   no legal C data-size spelling. The 0x43A tail assert is also retained.
   128-bit-slot read floor; probe discarded. */
// FUN_003133B0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003133b0);


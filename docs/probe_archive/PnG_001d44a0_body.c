/*
 * func_001d44a0 best candidate and final reconstruction.
 * object_size=732B; retail_window=736B; normalized_diff=0 differing words (reloc-masked).
 * differing_offsets=none (the four-byte retail tail is zero padding beyond the object symbol).
 * COP1 chain: both retail accumulator-chain operations (adda.s at 0xAC and madd.s at 0xB0)
 * reproduced naturally from compliant C; no intrinsic or inline asm was used for scalar arithmetic.
 * Ruled out: field-by-field Vec4 copy with the original (s32,f32) declaration (nd43),
 * aggregate copy with that declaration (nd7), inverted comparison spelling (nd19),
 * explicit dispatch goto (nd1), COP1 expressiveness floor, scalar inline asm/intrinsics/volatile,
 * whole-function asm, and the text permuter.
 * Closure used an aggregate Vec4 copy, an ABI-visible f32-before-s32 declaration for
 * func_003dc740, and the ternary condition spelling.
 * No new data references; all D_006094B0/D_006094D0/D_0060A0E0/D_0060A0F0 and callee
 * references are existing, real, placeable symbols.
 */
// FUN_001D44A0
void func_001d44a0(f32 fparg0, f32 fparg1, f32 *arg0, s32 *arg1, u8 *arg2, u8 *arg3)
{
    struct Vec4 {
        f32 value[4];
    };
    f32 fStack_10[4];
    f32 uStack_20[4];
    f32 vectorWork[4];
    f32 origin[4];
    f32 var_f20;
    f32 neg_limit;
    s32 var_16;
    u8 temp_6;
    u8 temp_7;

    temp_6 = *(u8 *)(arg2 + 1);
    temp_7 = *(u8 *)(arg2 + 2);
    if (temp_6 == 4) {
        var_16 = temp_7 & 0xFF;
        if (var_16 == 8) {
            var_f20 = (*(u16 *)(arg2 + 4) == 0) ? 2.0f : fparg0;
        } else {
            var_f20 = 2.0f;
        }
    } else {
        var_f20 = *(f32 *)((u8 *)arg0 + 4) + fparg1 * D_006094B0[temp_6];
        var_16 = temp_7 & 0xFF;
        if ((var_16 == 8) && (*(u16 *)(arg2 + 4) != 0)) {
            var_f20 += fparg0;
        }
    }
    switch (var_16) {
    case 8:
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0);
        *(f32 *)((u8 *)arg3 + 4) = var_f20;
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8);
        break;
    case 9:
    case 10:
        func_0048a250((u8 *)origin);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            :
            : "r"(origin)
            : "$vf10", "memory");
        if (fparg0 < fparg1) {
            fparg1 = fparg1;
        } else {
            fparg1 = fparg0;
        }
        neg_limit = -fparg1;
        if (var_16 == 9) {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = *(f32 *)((u8 *)arg0 + 4);
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        } else {
            origin[0] = *(f32 *)((u8 *)arg0 + 0);
            origin[1] = var_f20;
            origin[2] = *(f32 *)((u8 *)arg0 + 8);
        }
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vsub.xyzw $vf11, $vf11, $vf10 \n"
            :
            : "r"(origin)
            : "$vf10", "$vf11", "memory");
        if (var_16 == 10) {
            __asm__ volatile(
                "sqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
            vectorWork[1] = 0.0f;
            __asm__ volatile(
                "lqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2, $vf11, $vf11 \n"
            "vmulax.w $ACC, $vf0, $vf2x \n"
            "vmadday.w $ACC, $vf0, $vf2y \n"
            "vmaddz.w $vf2, $vf0, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf11, $vf11, $Q \n"
            :
            :
            : "$vf2", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile(
            "mfc1 $3, %0 \n"
            "nop \n"
            "qmtc2 $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(neg_limit)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vadd.xyzw $vf10, $vf10, $vf11 \n"
            "sqc2 $vf10, 0(%1) \n"
            :
            : "r"(origin), "r"(arg3)
            : "$vf10", "$vf11", "memory");
        break;
    default:
        *(struct Vec4 *)uStack_20 = *(struct Vec4 *)arg1;
        func_003dc740(uStack_20, D_0060A0E0, D_006094D0[temp_7], 2);
        func_003dcb40(fStack_10, (f32 *)D_0060A0F0, 1, (u8 *)uStack_20);
        fStack_10[0] = fStack_10[0] * fparg0;
        fStack_10[1] = fStack_10[1] * fparg0;
        fStack_10[2] = fStack_10[2] * fparg0;
        *(f32 *)((u8 *)arg3 + 0) = *(f32 *)((u8 *)arg0 + 0) + fStack_10[0];
        *(f32 *)((u8 *)arg3 + 4) = var_f20 + fStack_10[1];
        *(f32 *)((u8 *)arg3 + 8) = *(f32 *)((u8 *)arg0 + 8) + fStack_10[2];
        break;
    }
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}

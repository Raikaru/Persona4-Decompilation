/* func_0011ae90; best candidate before rollback.
   Object 632B; retail window 640B; normalized_diff 5 (relocation-masked).
   Differing byte offsets: 0x160, 0x168, 0x184, 0x188, 0x18C. The
   relocation-owned GPREL word at 0x08C is iGpffff8094 and resolves to real,
   placeable data; func_0044b7b0 is a real one-argument callee. All six retail
   COP1 accumulator operations (two adda.s/madd.s lerp chains and the byte
   adda.s/madd.s chain) reproduce byte-for-byte; the chain is not residual.
   The five-word residual is the known shdPersona output-GPR floor: retail's
   closing mfc1/andi/or/andi/sb tail uses $a0 while MWCC uses $v1. No call
   consumes the packed byte and the following load/next-use pressure is the
   allocator cause. The candidate used a scoped #pragma opt_propagation off to
   reproduce retail's top-of-loop lh/lwc1 ordering.

   Target-specific probes: reversing the final byte-flag condition to
   `if (value == 0) ... else ...` corrected the post-loop branch layout and
   reduced nd 12 to nd 5. The known family floor probes are not repeated here:
   direct branch stores; u8/s8 output locals; block-scoped output; integer vs
   pointer parameter; output declaration order; named output/base aliases;
   comparison/guard polarity; ternary/goto/shared-tail forms; signedness and
   explicit byte casts; and permitted pragma variants. Hoisting the immediately
   following halfword/next-use load is also ruled out by the characterized
   family (it expands the residual substantially). */
#pragma push
/* measured: #pragma opt_propagation off reproduces the retail loop's
   halfword/float load order; scoped to this target only. */
#pragma opt_propagation off
void func_0011ae90(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 base;
    f32 delta;
    s32 i;
    s32 a;
    s32 b;
    s32 total;
    s16 raw2;

    for (i = 0; i < 0xA; i++) {
        {
            s16 raw;
            raw = *(s16 *)(arg0 + 0x508);
            if ((f32)raw < *(f32 *)(arg0 + i * 36 + 0x2E8)) {
                ratio = 0.0f;
            } else {
                if ((f32)raw > *(f32 *)(arg0 + i * 36 + 0x2EC)) {
                    ratio = 1.0f;
                } else {
                    ratio = func_0044b7b0(iGpffff8094 * (((f32)raw - *(f32 *)(arg0 + i * 36 + 0x2E8)) / (*(f32 *)(arg0 + i * 36 + 0x2EC) - *(f32 *)(arg0 + i * 36 + 0x2E8))));
                }
            }
        }
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2CC);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D4) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2DC) = base + ratio * delta;
        base = *(f32 *)((s32)arg0 + i * 36 + 0x2D0);
        delta = *(f32 *)((s32)arg0 + i * 36 + 0x2D8) - base;
        *(f32 *)((s32)arg0 + i * 36 + 0x2E0) = base + ratio * delta;
        a = *(u8 *)((s32)arg0 + i * 36 + 0x2E4);
        b = *(u8 *)((s32)arg0 + i * 36 + 0x2E5);
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        {
            s32 n;
            if (2147483648.0f > acc) {
                n = (s32)acc;
                n &= 0xFF;
            } else {
                n = (s32)(acc - 2147483648.0f);
                n |= 0x80000000;
                n &= 0xFF;
            }
            *(u8 *)((s32)arg0 + i * 36 + 0x2E6) = (u8)n;
        }
    }
    total = *(s32 *)(arg0 + 0x510);
    raw2 = *(s16 *)(arg0 + 0x508);
    if (raw2 < total) {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x504) +
            (raw2 * (*(u8 *)(arg0 + 0x506) - *(u8 *)(arg0 + 0x504))) / total;
    } else {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x506);
        *(s32 *)(arg0 + 0x534) &= ~4;
        *(s32 *)(arg0 + 0x534) &= ~0x80000;
        *(s32 *)(arg0 + 0x534) &= ~0x200000;
        *(s32 *)(arg0 + 0x534) &= ~0x800000;
        if (*(u8 *)(arg0 + 0x505) == 0) {
            *(s32 *)(arg0 + 0x534) &= ~1;
        } else {
            *(s32 *)(arg0 + 0x534) |= 0x400000;
        }
    }
}
#pragma pop

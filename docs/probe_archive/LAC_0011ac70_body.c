/* func_0011ac70; archived best residual after rollback to INCLUDE_ASM.
   Candidate object 532B; retail window 544B; normalized_diff 5 (fndiff
   differing words after relocation masking); differing word offsets
   0x160, 0x168, 0x184, 0x188, 0x18C (decimal 352, 360, 388, 392, 396).
   Relocation-owned global at 0x08C is iGpffff8094 and resolves to real
   placeable data; func_0044b7b0 is a real one-argument callee. All six
   COP1 accumulator operations (two adda.s/madd.s lerp chains and the
   byte adda.s/madd.s chain) reproduced exactly; the chain is not the
   residual. The only remaining instructions are retail's mfc1/andi/or/
   andi/sb using $a0 versus the candidate's $v1 in the shared output tail.
   Re-measured and ruled out for this target: direct branch stores, u8 and
   s8 output locals, block-scoping the output local, integer versus pointer
   parameter type, output declaration order, named output-pointer/dst and
   base-pointer aliases; prior family probes also ruled out comparison,
   mask, compound-assignment, signedness, declaration-order, and pragma
   variants. Best body was restored to the exact bare INCLUDE_ASM form.
*/
/* Follow-up probe: retail has no byte-consuming call after `sb $a0`; after
   the store it increments the loop and computes `slti $v1` before the next
   iteration's `lh $a0, 0x508($s1)`. Prefetching that next-iteration halfword
   before the current packed-byte tail produced object 540B/window 544B and
   83 differing words. Cache aliases were coalesced; the best body above
   remains nd5 after relocation masking, with all six accumulator operations
   still reproduced. */
void func_0011ac70(u8 *arg0)
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
    total = *(s32 *)(arg0 + 0x50C);
    raw2 = *(s16 *)(arg0 + 0x508);
    if (raw2 < total) {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x504) +
            (raw2 * (*(u8 *)(arg0 + 0x506) - *(u8 *)(arg0 + 0x504))) / total;
    } else {
        *(u8 *)(arg0 + 0x505) = *(u8 *)(arg0 + 0x506);
        *(s32 *)(arg0 + 0x534) &= ~2;
    }
}

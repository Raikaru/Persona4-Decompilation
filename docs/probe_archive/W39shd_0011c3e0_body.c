/* W39shd_0011c3e0_body.c
 * Measured candidate for func_0011c3e0 in src/promoted/shdPersona.c.
 * object 540B / retail window 560B / normalized_diff 118 (fndiff differing words).
 * Differing-offset summary:
 *   0x00-0x24: prologue constant/loop counter register allocation (move $v1 vs $t1,
 *              lui $a1/$a2 vs $v1/$a1 for 1.0/0x4F000000/0x80000000).
 *   0x24-0x88: first loop body is missing retail's second `arg0 + i*36` address
 *              recomputation; the compiler CSEs it to one `t1` base pointer.
 *              This shifts the two FMA blocks and the byte-lerp by 16 bytes.
 *   0x10C-0x110: second loop counter in $v1 vs retail $t0.
 *   0x1A8-0x1B0: D_005E4950 base address loaded into $t0 with reloc 0 vs
 *                retail $a3 with immediate 0x5E/0x4950.
 * Levers tried:
 *   - #pragma opt_loop_invariants on (needed to fuse adda.s/madd.s pairs).
 *   - Reordering loop top (raw_s load before/after lo load) — lo before raw cvt
 *     reproduces retail's v-load/e1 order but keeps CSE'd base pointer.
 *   - Splitting `arg0 + i*0x24` into two named locals (e/p) — compiler CSEs.
 *   - #pragma opt_propagation off / opt_common_subs off — worse (125/140).
 *   - Declaration order of loop counter — no effect.
 * Verdict: the remaining residual is the documented CSE/address-colouring
 * family in this FMA loop; best measured nd remains 118, not a MATCH.
 */
#pragma opt_loop_invariants on
void func_0011c3e0(u8 *arg0)
{
    s32 i;
    u8 *t;
    u8 *src;
    u8 *dst;
    s16 raw_s;
    f32 raw;
    f32 lo;
    f32 hi;
    f32 ratio;
    f32 base;
    f32 end;
    f32 diff;
    f32 f_abs;
    f32 acc;
    s32 a;
    s32 b;
    u8 c;
    f32 f0;
    f32 f1;

    for (i = 0; i < 10; i++) {
        raw_s = *(s16 *)(arg0 + 0x516);
        t = arg0 + i * 0x24;
        lo = *(f32 *)(t + 0x2E8);
        raw = (f32)raw_s;
        if (raw < lo) {
            ratio = 0.0f;
        } else {
            hi = *(f32 *)(t + 0x2EC);
            if (raw > hi) {
                ratio = 1.0f;
            } else {
                ratio = (raw - lo) / (hi - lo);
            }
        }
        base = *(f32 *)(t + 0x2CC);
        end = *(f32 *)(t + 0x2D4);
        *(f32 *)(t + 0x2DC) = base + ratio * (end - base);
        base = *(f32 *)(t + 0x2D0);
        end = *(f32 *)(t + 0x2D8);
        *(f32 *)(t + 0x2E0) = base + ratio * (end - base);
        a = *(u8 *)(t + 0x2E4);
        b = *(u8 *)(t + 0x2E5);
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        *(u8 *)(t + 0x2E6) = (u8)acc;
    }
    if (!((f32)(*(s16 *)(arg0 + 0x516)) <= 4.0f)) {
        *(s32 *)(arg0 + 0x534) &= ~0x4000;
        for (i = 0; i < 10; i++) {
            src = &D_005E4950[i * 0x14];
            dst = arg0 + i * 0x24;
            f0 = *(f32 *)src;
            f1 = *(f32 *)(src + 4);
            c = *(u8 *)(src + 8);
            *(f32 *)(dst + 0x2DC) = f0;
            *(f32 *)(dst + 0x2CC) = f0;
            *(f32 *)(dst + 0x2D4) = f0;
            *(f32 *)(dst + 0x2E0) = f1;
            *(f32 *)(dst + 0x2D0) = f1;
            *(f32 *)(dst + 0x2D8) = f1;
            *(u8 *)(dst + 0x2E6) = c;
            *(u8 *)(dst + 0x2E4) = c;
            *(u8 *)(dst + 0x2E5) = c;
            *(s32 *)(dst + 0x2E8) = 0;
            *(s32 *)(dst + 0x2EC) = 0;
        }
    }
}
/* measured: closes opt_loop_invariants scope for func_0011c3e0. */
#pragma opt_loop_invariants off

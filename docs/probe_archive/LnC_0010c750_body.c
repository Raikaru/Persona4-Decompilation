/* func_0010c750 near-match archive; production remains ASM.
 * MWCCPS2 b210 -O2: 556B/560B, normalized_diff 32, twenty differing emitted
 * words plus one omitted zero-tail word at +0x22C (21 raw fndiff words).
 * Emitted differing offsets: 52,56,64; 188,192,200,204; 380,384; 428;
 *   444,448; 488,492,496,500,504,508,512; 524.
 *
 * Corrected coefficients: fGpffff8208 at 0x007612F8 (GP displacement 0x8208,
 * retail bytes e3a59b3c), fGpffff820c at 0x007612FC (0x820c, cdcc6c40).
 * The previous 8218/821c symbols named different data despite a relocation-
 * masked instruction score. fGpffff8150 at 0x00761240 remains correct.
 * Typed element indexing removes integer-address casts without worsening
 * the residual. Named pointer helpers gave 27 differing emitted words;
 * direct typed indexing stays at twenty. Remaining differences concern
 * conditional temporaries, clamp addiu/daddiu, conversion registers,
 * commutative address addition, and final curve-table scheduling/coloring.
 *
 * Native C under undefined/function sanitizers: 93,673 cases passed. Covers
 * low-halfword early return before pointer access; clamp boundaries; every
 * growth byte and persona ID; all scenario records; diagnostic continuation;
 * unsigned result wrapping. Diagnostic cases use valid fixture backing rows.
 * High-bit polynomial levels use zero coefficients to keep float-to-s32 in
 * range; malformed levels with ordinary coefficients are not claimed safe.
 * This checks C behavior, not EE COP1 rounding/fused-operation equivalence.
 */
extern f32 fGpffff8208;
extern f32 fGpffff820c;

u32 func_0010c750(u8 *arg0, s32 arg1)
{
    u32 scenario;
    s32 growthOff;
    s32 t;
    f32 levelF;
    f32 growthF;
    f32 prod;
    u16 scenarioLevel;
    s32 result;

    if ((arg1 & 0xFFFF) < 2) {
        result = 0;
    } else {
        if ((arg1 & 0xFFFF) >= 0x64) {
            arg1 = 0x63;
        }

        if ((*(u16 *)(arg0 + 2) >= 0xC0) &&
            (*(u16 *)(arg0 + 2) < 0xD8)) {
            scenario = 1;
        } else {
            scenario = 0;
        }
        if (scenario == 0) {
            if (*(u16 *)(arg0 + 2) >= 0x100) {
                func_0046d730(D_005E4318, 0x673);
            }
            if (arg1 >= 0) {
                levelF = (f32)arg1;
            } else {
                t = (u32)arg1 >> 1;
                t |= arg1 & 1;
                levelF = (f32)t;
                levelF = levelF + levelF;
            }
            growthOff = (s32)*(u16 *)(arg0 + 2) * 0xE;
            growthF = (f32)iGpffffb3d4[growthOff + 3];
            prod = fGpffff8150 * levelF;
            result = (s32)((0.0f + 10.0f) +
                           ((fGpffff820c + 0.0f - fGpffff8208 * growthF) *
                            (prod * levelF * levelF)));
        } else {
            if ((*(u16 *)(arg0 + 2) < 0xC0) ||
                (*(u16 *)(arg0 + 2) >= 0xD8)) {
                func_0046d730(D_005E4318, 0x67B);
            }
            scenarioLevel = ((u16 *)iGpffffb3e4)[(s32)*(u16 *)(arg0 + 2) * 311 - 59712];
            if ((scenarioLevel < 2) || (scenarioLevel >= 0xB)) {
                func_0046d730(D_005E4318, 0x67D);
            }
            result = ((s32 (*)[98])iGpffffb3e8)[scenarioLevel - 2][(arg1 & 0xFFFF) - 2];
        }
    }
    return (u32)result;
}

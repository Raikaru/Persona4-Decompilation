/* func_0010c750 near-match archive
 * object/window: 556B/560B
 * normalized_diff: 32
 * differing offsets (fndiff): 52,56,64; 188,192,200,204; 380,384; 428;
 *   444,448; 488,492,496,500,504,508,512; 524 (fndiff differing-word count 21)
 * ruled out: natural polynomial association variants; cubic temporary variants;
 *   signed-conversion casts/temporary types/scopes; float declaration orders;
 *   comparison polarity/operand swaps; optimization pragmas; s64 parameter.
 * COP1 chain reproduced: yes (adda.s, msub.s, adda.s, madd.s and all 3 mul.s
 *   words match); residual is ordinary GPR/register coloring and table-load order.
 */
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
            growthF = (f32)*(u8 *)(growthOff + (s32)iGpffffb3d4 + 3);
            prod = fGpffff8150 * levelF;
            result = (s32)((0.0f + 10.0f) +
                           ((fGpffff821c + 0.0f - fGpffff8218 * growthF) *
                            (prod * levelF * levelF)));
        } else {
            if ((*(u16 *)(arg0 + 2) < 0xC0) ||
                (*(u16 *)(arg0 + 2) >= 0xD8)) {
                func_0046d730(D_005E4318, 0x67B);
            }
            scenarioLevel = *(u16 *)((u8 *)iGpffffb3e4 +
                                     (s32)*(u16 *)(arg0 + 2) * 0x26E -
                                     0x1D280);
            if ((scenarioLevel < 2) || (scenarioLevel >= 0xB)) {
                func_0046d730(D_005E4318, 0x67D);
            }
            result = *(s32 *)((u8 *)iGpffffb3e8 +
                              (s32)scenarioLevel * 0x188 +
                              ((arg1 & 0xFFFF) * 4) - 0x318);
        }
    }
    return (u32)result;
}

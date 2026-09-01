/* object: 528 bytes; retail window: 544 bytes; normalized_diff: 109. */
/* differing offsets (reloc-masked): 28-40, 48, 92, 108-188, 192-384, 392-488, 492-524. */
/* ruled out: opt_propagation off (frame/register regression); opt_common_subs off (frame regression); opt_loop_invariants on (nd 94 but wrong loop address); optimization_level 1 (frame regression); separate arrays/struct layouts; pointer-hoisting (saved-register/frame regression). */
/* COP1 chain: reproduced all six retail accumulator operations (MULA/MADD, ADDA/MADD, ADDA/MADD) from plain natural C; no intrinsic or inline assembly. */
/* dependencies during probe: fabsf and fGpffff80f0 extern declarations, iGpffffbb68 as u8. */
void func_004a7830(void)
{
    f32 work[8];
    f32 *slot;
    f32 current;
    f32 delta;
    s32 i;
    s32 offset;
    u8 *state;

    work[4] = *((f32 *)&iGpffffb10c + 1);
    work[5] = *((f32 *)&iGpffffb10c + 2);
    if (iGpffffbb68 != 0) {
        iGpffffbb68 = 0;
        work[6] = fGpffff80f0 * fGpffffbb70;
        work[7] = fGpffff80f0 * fGpffffbb74;
        for (i = 0; i < 2; i++) {
            offset = i * 4;
            current = work[i + 6];
            if (current != 0.0f) {
                delta = 0.5f * current +
                        current * func_004bd0b0(0) * 0.5f;
                slot = (f32 *)((u8 *)&D_00724C78 + offset);
                if (!(fabsf(*slot) < current * work[i + 4])) {
                    if (*slot <= 0.0f) {
                        *slot = *slot + delta;
                    } else {
                        *slot = *slot - delta;
                    }
                } else {
                    *slot = (*slot + 0.0f) +
                            2.0f * (delta *
                                    (func_004bd0b0(0) - 0.5f));
                }
                if (*slot < -current) {
                    *slot = -current;
                }
                if (*slot > current) {
                    *slot = current;
                }
            }
        }
        state = *(u8 **)(func_00457120() + 4);
        work[0] = iGpffffb10c *
                  (*(f32 *)(state + 0x10) * *(f32 *)&D_00724C78);
        work[1] = iGpffffb10c *
                  (*(f32 *)(state + 0x14) * *(f32 *)&D_00724C78 +
                   *(f32 *)&D_00724C7C + 0.0f);
        work[2] = iGpffffb10c *
                  (*(f32 *)(state + 0x18) * *(f32 *)&D_00724C78);
        func_003e9c10(D_00724C70, work, 0);
    }
}

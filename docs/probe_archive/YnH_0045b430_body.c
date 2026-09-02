/* Fresh remeasure 2026-09-01 (YnH_b430_1): object 532B/window 544B, normalized_diff 8; differing byte offsets 234, 238, 249, 253, 254, 258, 262, 270 (word rows 232, 236, 248, 252, 256, 260, 268; relocation fields masked). The clean-C body below is the best candidate. A scoped opt_propagation-off probe worsened the residual to normalized_diff 340 and was reverted. Retail keeps D_008E4090 in $v1 while this body uses $a0, and retail's loop sign-extension uses $a0 while this body uses $v1; pointer-construction/declaration/type/prototype variants remain unclosed. Temporary-rule probe predicted making the address use first could assign it $v1 while preserving the hoisted address; a base-first split (`temp_2 = (u8 *)var_3` before `slot_index`) kept the address/index colouring unchanged but drifted the later count loop (nd 15), so it was reverted. Retail materialises D_008E4090 once before the loop; this candidate also remains hoisted in this probe. A body-first address probe moved `var_3 = D_008E4090` into the loop before `slot_index`; it recomputed the address each iteration, remained in $a0 while the index stayed $v1, and worsened the branch/layout residual (nd 13), so it was reverted. This confirms the retail address is hoisted, not loop-body recomputed. An address-before-index initialization probe (`var_3 = D_008E4090; var_5 = 0`) left the loop colours unchanged, shifted setup order, and scored nd 11, so it was reverted; the required address hoist remains the original post-index initialization. A function-granular `opt_propagation off` probe expanded the frame to 0x20/object 536B and changed 115 fndiff words (normalised residual worsened well beyond nd8), while also drifting propagation-sensitive calls; it was reverted, and no pragma is retained. A direct `temp_2 = (u8 *)D_008E4090` before `slot_index` was optimised away; object/nd remained 532B/8 with the same reverse colours, so it was reverted. Making that direct global the actual pointer base (`temp_2 = D_008E4090; ... temp_2 += slot_index * 0x44`) recomputed the address per iteration, kept it in $a0 and the index in $v1, and scored fndiff nd 13; it was reverted. A separate `u8 *base` alias initialized from `var_3` before the loop was optimized/coalesced away; object/nd remained 532B/8 and colours stayed reversed, so it was reverted. An address-first offset split (`temp_2 = var_3 + 0x44; slot_index = ...; temp_2 += (slot_index - 1) * 0x44`) added arithmetic/branch drift (object 540B, fndiff 70) and did not reach the requested colouring, so it was reverted. Splitting the reused `var_3` into separate `base` and `count` locals was coalesced back to the same live ranges; object/nd remained 532B/8 and the first-loop colours stayed reversed, so it was reverted. Inlining the slot index cast into the pointer expression removed the named s64 conversion and shrank the object to 524B (fndiff 71); it did not preserve the retail dsll32/dsra32 sequence and was reverted. Using a direct `(s64)(s16)var_5` assignment instead of `(s32)(s16)var_5` retained object/nd 532B/8 and the reverse colours, so it was reverted. The function-granular `opt_lifetimes off` pragma was also inert for this loop: object/nd stayed 532B/8 with unchanged register colours; it was reverted. Combining `var_5 = 0` and `var_3 = D_008E4090` in one comma expression retained object/nd 532B/8 and the reverse colours; it was reverted. Splitting the pointer offset into a named `u32 offset` local retained object/nd 532B/8 and the same reverse colours; it was reverted. A declaration initializer (`s32 var_3 = D_008E4090`) made the address live from entry, forced an $s0 save/frame 0x20, and expanded the object to 540B (fndiff 116); it was reverted. Changing `var_5` from s32 to s64 added an extra sign-extension pair/branch-layout drift (object 540B, fndiff 65) and left the base/index colours reversed; it was reverted. Changing `var_5` to s16 moved the loop counter into $a2 and altered the stores/increment sequence (fndiff 17); it was reverted. A direct-global `u8 *base` initialized before `var_5` and used for the indexed pointer kept the address hoisted but still assigned it $a0 (index remained $v1); it shifted the setup order and scored fndiff 11, so it was reverted. `#pragma opt_loop_invariants on` was inert: object/nd remained 532B/8 and the address/index colours stayed reversed, so it was reverted. A direct global pointer expression in the indexed address left the global materialisation in the loop body (object 532B, fndiff 14), and adding `#pragma opt_loop_invariants on` did not hoist it (nd 10); both probes were reverted. `#pragma opt_propagation off` with that direct expression did hoist a $v1 global materialisation but introduced the same broad frame/prologue/tail drift (object 536B, fndiff 114), so it was reverted. Using `&D_008E4090` instead of the array decay left the address in the loop body and scored fndiff 14; it was reverted. Recasting the first loop as a `for` or `while` with the original hoisted local changed no target colours (fndiff 10), so both loop-shape probes were reverted.
*/
void func_0045b430(void) {
    s32 var_3;
    s32 var_5;
    s64 slot_index;
    s32 next;
    u8 *temp_2;

    func_00430e28();
    func_0043c008(0);
    func_0043c010(0x20);
    func_0043bb70(D_008E4230, 0x20, 0);
    func_0043c0c0(0, 0x8F, 0);
    func_0043c0c0(3, 0x83, 0x105, 0x3C, 0);
    func_0043c0c0(3, 0x84, 0x3C, 0x3C);
    func_0043c0c0(3, 0x82, 1);
    func_00430f80(1, 0x8010, 0x800, 0xFC0);
    func_00430f80(1, 0x8010, 0x801, 0xFCC);
    func_0043c0c0(3, 0x80, 0x7F, 0x7F);
    var_5 = 0;
    var_3 = (s32)D_008E4090;
    goto loop_0045b430_slot_test;
loop_0045b430_slot_body:
    slot_index = (s32)(s16)var_5;
    temp_2 = (u8 *)((u32)var_3 + (u32)((s32)slot_index * 0x44));
    *(s16 *)(temp_2 + 0) = 0;
    *(s32 *)(temp_2 + 4) = 0;
    *(s32 *)(temp_2 + 0x18) = 0;
    *(s16 *)(temp_2 + 0xA) = (s16)var_5;
    next = (s32)var_5 + 1;
    var_5 = (s64)(s16)next;
loop_0045b430_slot_test:
    if ((s16)var_5 < 6) {
        goto loop_0045b430_slot_body;
    }
    var_3 = 0;
    D_008E4018_abs[0] = 0;
    goto loop_0045b430_count_test;
loop_0045b430_count_body:
    next = (s32)var_3 + 1;
    var_3 = (s64)(s16)next;
loop_0045b430_count_test:
    if ((s16)var_3 < 0x10) {
        goto loop_0045b430_count_body;
    }
    D_008E40B4_abs[0] = func_0043bcb8(0x64000, var_5);
    D_008E40F8_abs[0] = func_0043bcb8(0xE1000);
    D_008E413C_abs[0] = func_0043bcb8(0x19000);
    D_008E4180_abs[0] = func_0043bcb8(0x19000);
    D_008E41C4_abs[0] = func_0043bcb8(0x19000);
    D_008E4208_abs[0] = func_0043bcb8(0x19000);
}

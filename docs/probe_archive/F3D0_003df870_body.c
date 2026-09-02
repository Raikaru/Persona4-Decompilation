// Main 2026-09-02: under the unit's -O2,p (config/speed_units.txt) + schedule on, the jr delay slot IS filled with the addu
// but the scheduler also hoists the second lw above the mult (lw lw mult jr addu vs retail lw mult lw jr addu). No level
// or pragma combination (13 tried) gives fill-without-hoist. Open.
/* object_size 24B, window 32B, normalized_diff 8, differing offsets 12,13,14,15,16,17,18,19 (retail tail words at +12 = jr $ra 0x0800e003 and +16 = addu $v0,$v0,$v1 0x21104300; candidate reverses them at +12/+16, with nop at +20). Classification: scheduler/epilogue ORDER residual, not an rd-form multiply floor: plain C emits the same retail raw mult word 0x00451818 (mult $v1,$v0,$a1) and matches the preceding lw/mult/lw sequence exactly. Re-measured after declaration changes. Direct-expression and opposite named-result forms both remain 24B/nd8; schedule-on produces 20B/nd9 and reorders earlier loads. Local-product, pointer, declaration, opt_propagation, optimization, and explicit schedule-off probes were ruled out. No inline asm or volatile. */
s32 func_003df870(s32 *arg0, s32 arg1) {
    s32 product = arg0[3] * arg1;
    return arg0[0] + product;
}

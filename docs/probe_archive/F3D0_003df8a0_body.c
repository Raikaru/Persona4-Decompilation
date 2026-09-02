// Main 2026-09-02: under the unit's -O2,p (config/speed_units.txt) + schedule on, the jr delay slot IS filled with the addu
// but the scheduler also hoists the second lw above the mult (lw lw mult jr addu vs retail lw mult lw jr addu). No level
// or pragma combination (13 tried) gives fill-without-hoist. Open.
/* object_size 28B, window 32B, normalized_diff 8, differing offsets 16,17,18,19,20,21,22,23 (retail tail words at +16 = jr $ra 0x0800e003 and +20 = addu $v0,$v0,$v1 0x21104300; candidate reverses them at +16/+20, with nop at +24). Classification: scheduler/epilogue ORDER residual, not an rd-form multiply floor: plain C emits the same retail raw mult word 0x00621818 (mult $v1,$v1,$v0) and matches the preceding lw/lw/mult/lw sequence exactly. Re-measured after declaration changes. Direct-expression and opposite named-result forms both remain 28B/nd8; schedule-on produces 24B/nd10 and reorders earlier loads. Local-product, pointer, declaration, optimization, explicit schedule-off, and opt_serializeassignments probes were ruled out. No inline asm or volatile. */
s32 func_003df8a0(s32 *arg0) {
    s32 product = arg0[3] * arg0[1];
    return arg0[0] + product;
}

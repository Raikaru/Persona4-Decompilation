/* object_size 52B, window 64B, normalized_diff 5, differing offsets 12 and 16 (reloc-masked; verifier first_diffs 12-19). */
/* Best measured body is the initialized pointer form below. It improves the prior nd8 state to nd5 but still emits an extra addiu/lw address-materialization pair instead of retail's direct lw at offset 16. Probed before this lane: direct pointer base plus named u32 offset (nd8); direct scalar result/base forms (nd13); schedule off (nd32); no_branch_likely/schedule on (required for structural body); opt_propagation off and opt_serializeassignments on/off (no improvement); default knob_sweep pragmas (no improvement); 60s permuter (586 compiles, no match); guard forms >= and positive-body (nd25/nd8); inner block and comma evaluation forms (nd8). Focused pointer-index probes in this lane: u64/aggregate Elem pointer address indexing, inline indexed-base casts, fixed Elem-field subscripts, nested pointer-field indexing, and explicit scalar/compound-assignment ordering; these retained the opposite shift/lw order (nd8 or worse) and did not improve nd5. New direct folded-load, typed-field, named-base, array-index, pointer-expression, reversed-helper-operand, register-local, optimization-level-1, intra-function schedule, comma-sequencing, and block-boundary probes remove the extra pair but retain the ORDER residual: retail lw $v0,0x58($a0) at offset 16 then sll $v1,$a1,3 at 20, while candidates emit the sll at 16 then lw at 20 (nd5/reloc-masked). No volatile, inline asm, or scheduler barrier was used. */
/* NMX 2026-08-21: this body reproduces nd5 ONLY inside a `#pragma schedule on`
   bracket; code1_003d.c drifted to `schedule off` at this site and the bare
   form scores nd35 there. Direct-load spellings hit an nd22 wall (b210 fills
   the beq delay slot with the zero-path move and sinks the lw below shifts). */
s32 func_003de280(u8 *arg0, u32 arg1) {
    u32 *base = (u32 *)(arg0 + 0x58);
    u32 offset;
    if (!(arg1 < *(u32 *)(arg0 + 4))) {
        goto zero;
    }
    offset = arg1 << 3;
    offset -= arg1;
    offset <<= 4;
    return *base + offset;
zero:
    return 0;
}

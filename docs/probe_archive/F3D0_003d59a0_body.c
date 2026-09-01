/* object_size 56B, window 48B, normalized_diff 17, differing offsets 24,25,26,27,34,35,40,42,43,48,49,50,51,52,53,54. Classification: ORDER plus oversized object. Retail emits jal at +24 with arg1 addiu in the delay slot; this schedule-off pointer-typed candidate emits arg1 addiu before jal and leaves extra tail words. Re-measured after declaration changes. Freshly ruled out: integer arg1 form is a compile error under the current func_0043f810 prototype; prior ruled out: three-parameter prototype, casted argument form, schedule on, local size/dst temporaries, opt_propagation off, optimization_level 1, and comma-order probe. No volatile or inline asm. */
s32 func_003d59a0(u8 *arg0, u8 *arg1) {
    func_0043f810(arg0 + 0x4C, arg1 + 0x4C,
        *(s32 *)(arg0 + 0x24) * *(s32 *)(arg0 + 0x2C));
    return 1;
}

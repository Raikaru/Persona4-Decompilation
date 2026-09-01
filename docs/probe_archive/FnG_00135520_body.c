/* Fresh remeasurement: object 432B, retail window 432B, normalized_diff 2;
   fndiff differing word offset: 0xE4 (decimal 228).
   Residual: candidate add.s $f21,$f21,$f0 versus retail add.s
   $f21,$f0,$f21. The pointer self-use shape fixed the four-word third-draw
   load/constant schedule; only this commutative FP operand orientation remains.
   Ruled out: Hex-Rays/Ghidra source-shape disagreement (both corpora agree);
   local-union versus by-value union staging; s8/u8 third-parameter forms;
   pointer staging and direct-load forms; s32/u32/s16/u16/s8/u8 mask-local
   widths; all 7! permutations of the seven local declarations; dead float
   locals, aliases, separate post-add temporaries, stack-update forms, and
   constant spellings; every permitted function-scoped pragma and balanced
   combination (opt_propagation, opt_common_subs, opt_loop_invariants,
   schedule, no_branch_likely, opt_rebuildconditionals, tailcall, and
   optimization_level 0/1/3); reverse/helper-based add forms; plain-local
   fresh-value copy modeled on mwccps2-debugger's commutative_mul_s experiment
   (the corpus version's volatile qualifier is banned here); and the
   577-compilation textual permuter run (base score 16, no match). The two
   earlier archives were remeasured: V013 scored normalized_diff 19 and W
   scored 16 before the pointer self-use improvement. No comparison or
   shared-result lever applies: both branches are independent bitmask tests
   and the function is void. */
void func_00135520(u8 *arg0,
                   union {
                       s64 raw;
                       f32 f[2];
                   } arg1,
                   u8 arg2, s32 arg3)
{
    f32 temp_f21;
    f32 temp_f20;
    u16 temp_16;
    u8 temp_17;
    u8 temp_18;
    u8 temp_19;
    void *temp_p;
    temp_17 = D_0064B2E8[0];
    temp_18 = D_0064B2E8[1];
    temp_19 = D_0064B2E8[2];
    temp_f21 = code13Add(arg1.f[1], 26.0f);
    arg1.f[1] = temp_f21;
    temp_16 = (u16)arg3;
    if (temp_16 & 2) {
        func_0034f2e0(*(void **)(arg0 + 0x1538),
                      (temp_f20 = arg1.f[0]), temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x153C);
        temp_f20 = 467.0f + arg1.f[0];
        func_0034f2e0(temp_p,
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x1540);
        temp_p = temp_p;
        temp_f21 += 130.0f;
        func_0034f2e0(temp_p,
                      arg1.f[0], temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        func_0034f2e0(*(void **)(arg0 + 0x1544),
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
    }
    if (temp_16 & 1) {
        arg1.f[0] -= 2.0f;
        arg1.f[1] -= 26.0f;
        func_00134f40(arg0, arg1.raw, 1, arg2);
    }
}

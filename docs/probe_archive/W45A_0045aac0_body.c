/* object size 260B; retail window 272B; normalized_diff 12; differing offsets [40,44,48,52,116,120,136]. */
/* Probes: m2c prelude expansion; direct plain-C; dependency expressions; named locals and local reuse; helper wrappers; opt_propagation off; schedule/optimization pragma permutations; address-of and pointer casts; guard no-ops; handle locals; callee parameter width probes; 64-bit s64 arg1 narrowing probe (no change); permuter 120s and 180s. Best observed nd8 with opt_propagation-off dependency expression, not retained. */
s32 func_0045aac0(s16 arg0, s16 arg1, s32 arg2)
{
    func_00440b68((s32)&D_007122F0, arg0, arg1, arg2);
    if (arg0 < 5)
    {
        if (D_008D2B90[arg0].f00 != 0)
        {
            func_004d8eb0(LD32(D_008D2BA0, SND_IDX(arg0)), arg2);
            if (D_008D2B90[arg0].f00 != 0)
            {
                func_004d8d90(LD32(D_008D2BA0, SND_IDX(arg0)));
                LD16(D_008D2B9C, SND_IDX(arg0)) = 0;
                D_008D2B90[arg0].f00 = 0;
                LD16(D_008D2B98, SND_IDX(arg0)) = -1;
            }
        }
    }
    return 1;
}

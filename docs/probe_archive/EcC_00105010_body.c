/*
 * func_00105010 attempted body archive (EcC)
 * object_size: 396 bytes
 * retail_window: 400 bytes
 * normalized_diff: 50
 * differing_offsets: 60, 68, 76-360 (word-level residual spans; the
 * residual is dominated by call-result register coloring, loop placement,
 * and tail expression scheduling)
 * corpora: IDA and Ghidra agree on the low-16-bit table lookup, five-step
 * loop, signed-short subtraction, i>=5 clamp, and two-stage float result.
 * ruled out: s16/s32/s64 call-result local forms, bottom-tested goto and
 * structured while/for loop forms, v4<v5 and v5>v4 comparison spellings,
 * local declaration orders, named tail temporaries, explicit s16/s32 casts,
 * if/else-break restructure, named argument temporary, and copying the
 * comparison local. The best prior source spelling measured nd50 (object
 * 396/window 400); the source comment in g_data.c records the later nd31
 * register-coloring/scheduling floor from additional probes.
 */
s64 func_00105010(s64 arg0, f32 arg1)
{
    s16 v4;
    s64 v5;
    s32 i;

    v4 = D_007973F4[(s16)arg0];
    v5 = 0;
    i = 0;
    while (i < 5)
    {
        v5 = (s16)func_00246a50((s16)arg0, (s16)(i + 1));
        if (v4 < v5)
        {
            break;
        }
        v4 -= v5;
        i++;
    }
    if (i >= 5)
    {
        i = 4;
    }
    return (s16)(s32)(100.0f *
        (f32)((s32)(100 * (s16)((100 * (i + 1)) +
            (s32)((f32)(100 * v4) / (f32)(s32)v5))) / arg1));
}

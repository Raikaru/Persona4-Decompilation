/* object_size=488B window=496B normalized_diff=15 differing_byte_offsets=0xFA-0xFF,0x102-0x104,0x106-0x10B; levers ruled out: first-argument hoist/local forms (nd8/111), declaration reversal, direct global load, comma assignment (nd202), scheduler-off pragma, inline evtMulScale/evtRamp helpers (nd15), and reversed multiply operand order (nd17). */
void func_00298990(s32 unused, s32 arg1) {
    f32 temp_f2;
    f32 temp_f0;
    s32 var_5;
    s32 temp_16;
    s32 temp_19;
    s32 temp_4;
    s32 temp_5;
    s32 var_18;
    u8 *temp_17;

    temp_17 = (u8 *)func_00452560(arg1);
    temp_19 = *(s32 *)((u8 *)func_00285480(func_00452560(func_00285af0())) + 0x680);
    var_18 = 0;
    while (var_18 < 0xF) {
        temp_5 = var_18 * 0x28;
        temp_4 = *(s32 *)(temp_17 + 4);
        if ((temp_5 < temp_4) && (temp_4 < (temp_5 + 0x12C))) {
            temp_16 = temp_4 - temp_5;
            if (temp_16 < 0xB4) {
                var_5 = (s32)(255.0f * func_0044b7b0((iGpffff8094 * (f32)temp_16) / 180.0f));
            } else if (temp_16 > 0x10E) {
                temp_f0 = (f32)(temp_16 - 0x10E);
                temp_f2 = iGpffff8094;
                var_5 = (s32)(255.0f * func_0044b7b0(temp_f2 + ((temp_f2 * temp_f0) / 30.0f)));
            } else {
                var_5 = 255;
            }
            func_002987d0(320.0f, 300.0f - ((230.0f * (f32)temp_16) / 300.0f), 0.0f,
                          0xFFFFFF, var_5, 0, 0, 0, temp_19, 0, var_18);
        }
        var_18 += 1;
    }
}

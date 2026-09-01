/* object 604 bytes, retail window 592 bytes, normalized_diff 206; first differing offsets 42,44,46,47,50,51,54,55,56,57,58,59,62,63,66,67; retail int-to-float sequence is bltz/mtc1/cvt.s.w or srl/andi/or/mtc1/cvt.s.w/add.s, written as (f32)(u32)arg1; retail float-to-unsigned sequence is c.le.s/trunc.w.s/mfc1/andi or sub.s/trunc.w.s/mfc1/lui 0x8000/or/andi, written as (u16)temp_f1. Corrected block-scope func_0046d730(void *,s32) and func_0026bc10(u32,u32). Direct/aggregate layouts, aliases, parameter mutation, O1, loop forms, floating guard polarity, explicit branch labels, and callee declaration variants were ruled out; object remained oversized, archive immediately per lane budget. */
u16 func_00108590(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_0046d730(void *file, s32 line);
    extern s32 func_0026bc10(u32 resourceId, u32 value);
    f32 vals[12];
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f1;
    s32 *temp_2;
    s32 *temp_2_2;
    s32 temp_16;
    s32 var_3;
    u32 var_4;

    vals[8] = D_005E42D8[0];
    vals[9] = D_005E42DC[0];
    vals[10] = D_005E42E0[0];
    vals[4] = D_005E42E8[0];
    vals[5] = D_005E42EC[0];
    vals[6] = D_005E42F0[0];
    vals[0] = D_005E42F8[0];
    vals[1] = D_005E42FC[0];
    vals[2] = D_005E4300[0];
    if (!(arg0 & 0xFFFF)) {
        arg0 = func_00108e10() & 0xFFFF;
    }
    if (!(arg0 & 0xFFFF)) {
        func_0046d730(&D_005E42C8[0], 0x21F);
    }
    temp_2_2 = (s32 *)func_001070e0(arg0);
    if (temp_2_2 == NULL) {
        var_3 = 0;
    } else {
        temp_f0 = func_001080c0(arg0);
        var_f1 = (f32)(u32)arg1;
        temp_f1 = var_f1 * temp_f0;
        var_3 = (u16)temp_f1;
        *(u16 *)((u8 *)temp_2_2 + 8) =
            (u16)(*(u16 *)((u8 *)temp_2_2 + 8) + var_3);
    }
    var_4 = 0;
    while (var_4 < 3U) {
        if (vals[8 + var_4] < (var_3 & 0xFFFF)) {
            var_4 += 1;
            continue;
        }
        break;
    }
    temp_16 = var_4 * 4;
    func_0045af60(0, 0, 4, *(s16 *)((u8 *)vals + 0x10 + temp_16));
    if (arg2 != -1) {
        func_0026bc10(((arg2 & 0x3FF) | 0xC00) & 0xFFFF,
                      *(u8 *)((u8 *)vals + temp_16));
    }
    temp_2 = (s32 *)func_001070e0(arg0);
    if (temp_2 == NULL) {
        return 0U;
    }
    return *(u16 *)((u8 *)temp_2 + 8);
}

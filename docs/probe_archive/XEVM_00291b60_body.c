/* object_size=1092 window=1088 normalized_diff=632 differing_offsets=28,60,132-172,180-216,228-240,248-252,264-284,292-296,308-332,344-380,388,400,412-416,424-436,444-448,456-460,468-472,480-488,496-500,508-512,520-524,532-536,544-644,652-660,676-724,732-768,776-780,788-796,804-868,880,888-892,900-904,912-916,928-936,944-976,984-1044,1052-1088; cast=(u32)rec->timer2; ruled_out=callee signatures (all verified declarations), guard polarity, hidden return, argument staging, mixed parameter order, global addressing, lifetime, optimization pragma, switch declaration order; automatic archive because object exceeded window. */
// Candidate archived from func_00291b60; restore as a live body only after further source correction.
s32 func_00291b60(s32 arg0, u8 *arg1) {
    EvtModelRec *rec = (EvtModelRec *)arg1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f21;
    f32 var_f12;
    f32 var_f12_2;
    s16 temp_2_3;
    s16 temp_2_4;
    s32 handle;
    s32 temp_3;
    s32 var_2;
    s32 var_2_2;
    u32 var_3;
    u8 *temp_2_2;

    temp_f21 = rec->speed;
    handle = func_00291a60(rec->id);
    if (handle == 0) {
        return 1;
    }
    var_3 = (u32)rec->timer2;
    switch (var_3) {
    case 0:
        if (func_0047a9d0(handle) == 0) {
            rec->flags |= 1;
        }
        func_0047a950(handle, 30.0f, 0.0f);
        var_f12 = fGpffff8218 * temp_f21;
        if (!(var_f12 <= 1.0f)) {
            var_f12 = 1.0f;
        } else if (var_f12 < 0.0f) {
            var_f12 = 0.0f;
        }
        func_0047a890(handle, var_f12);
        rec->timer2 += 1.0f;
    default:
block_41:
        temp_2_2 = (u8 *)func_0047a980(handle);
        *(F32x4 *)(arg1 + 0x34) = *(F32x4 *)temp_2_2;
        return 0;
    case 1:
        temp_f0 = func_004bd4a0(
            func_0047a980(func_00291a60(rec->id)),
            (f32 *)(arg1 + 0x34));
        if ((temp_f0 < -1.0f) || !(temp_f0 <= 1.0f)) {
            func_0046d730(D_0063C948, 374);
        }
        if (func_0044b920(func_0044e7d8(func_0044b310(func_0044dcd8(temp_f0)))) < fGpffff8478) {
            temp_2_3 = (s16)(rec->counterA + 1);
            rec->counterA = temp_2_3;
            if (((s64)((s64)temp_2_3 << 0x30) >> 0x30) >= 2) {
                rec->counterA = 0;
                var_2 = 1;
            } else {
                goto block_21;
            }
        } else {
            rec->counterA = 0;
block_21:
            var_2 = 0;
        }
        if (var_2 != 0) {
            func_0047a950(handle, 0.0f, 0.0f);
            var_f12_2 = fGpffff8218 * temp_f21;
            if (!(var_f12_2 <= 1.0f)) {
                var_f12_2 = 1.0f;
            } else if (var_f12_2 < 0.0f) {
                var_f12_2 = 0.0f;
            }
            func_0047a890(handle, var_f12_2);
            rec->timer2 += 1.0f;
        }
        goto block_41;
    case 2:
        temp_f0_2 = func_004bd4a0(
            func_0047a980(func_00291a60(rec->id)),
            (f32 *)(arg1 + 0x34));
        if ((temp_f0_2 < -1.0f) || !(temp_f0_2 <= 1.0f)) {
            func_0046d730(D_0063C948, 374);
        }
        if (func_0044b920(func_0044e7d8(func_0044b310(func_0044dcd8(temp_f0_2)))) < fGpffff8514) {
            temp_2_4 = (s16)(rec->counterB + 1);
            rec->counterB = temp_2_4;
            if (((s64)((s64)temp_2_4 << 0x30) >> 0x30) >= 2) {
                rec->counterA = 0;
                var_2_2 = 1;
            } else {
                goto block_36;
            }
        } else {
            rec->counterB = 0;
block_36:
            var_2_2 = 0;
        }
        if (var_2_2 != 0) {
            temp_3 = rec->flags;
            if (temp_3 & 1) {
                rec->flags = temp_3 & ~1;
                func_0047a990(handle);
            }
            return 1;
        }
        goto block_41;
    }
}

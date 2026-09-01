/* Closest candidate archive; reverted because lverify normalized_diff was 817 (object 1140B, window 1104B). */
s32 func_001ba0e0(u8 *arg0)
{
    u32 temp_2_2, temp_4, temp_2;
    s32 temp_3;
    f32 temp_f0, temp_f1, temp_f2, temp_f3, temp_f5;
    s32 out0, out1, out2, out3;
    u8 *temp_16;
    if (*(u32 *)(arg0 + 0xC) == 0) {
        temp_16 = func_00457130();
        temp_2 = temp_16[0]; temp_3 = temp_16[1]; out0 = temp_16[2]; out1 = temp_16[3];
        arg0[4] = temp_2; arg0[5] = temp_3; arg0[6] = out0; arg0[7] = out1;
    }
    temp_4 = *(u32 *)(arg0 + 8); temp_2_2 = *(u32 *)(arg0 + 0xC);
    if (temp_2_2 < temp_4) {
        if ((s32)temp_2_2 < 0) goto time_cur_neg;
        temp_f1 = (f32)(s32)temp_2_2; goto time_cur_done;
 time_cur_neg: temp_f1 = (f32)((temp_2_2 >> 1) | (temp_2_2 & 1)); temp_f1 += temp_f1;
 time_cur_done:
        if ((s32)temp_4 < 0) goto time_end_neg;
        temp_f0 = (f32)(s32)temp_4; goto time_end_done;
 time_end_neg: temp_f0 = (f32)((temp_4 >> 1) | (temp_4 & 1)); temp_f0 += temp_f0;
 time_end_done: temp_f1 /= temp_f0; temp_f0 = 1.0f - temp_f1;
#define BYTE_FLOAT(n, neg, done) temp_2 = arg0[n]; if (temp_2 < 0) goto neg; temp_f3 = (f32)temp_2; goto done; neg: temp_f3 = (f32)((temp_2 >> 1) | (temp_2 & 1)); temp_f3 += temp_f3; done:
        BYTE_FLOAT(4,c0_start_neg,c0_start_done) temp_f5 = iGpffff81f4 * temp_f3;
        BYTE_FLOAT(0,c0_end_neg,c0_end_done) temp_f2 = iGpffff81f4 * temp_f3; temp_f5 = temp_f5 * temp_f0 + temp_f2 * temp_f1; out0 = (s32)(temp_f5 * 255.0f + 0.5f);
        BYTE_FLOAT(5,c1_start_neg,c1_start_done) temp_f5 = iGpffff81f4 * temp_f3;
        BYTE_FLOAT(1,c1_end_neg,c1_end_done) temp_f2 = iGpffff81f4 * temp_f3; temp_f5 = temp_f5 * temp_f0 + temp_f2 * temp_f1; out1 = (s32)(temp_f5 * 255.0f + 0.5f);
        BYTE_FLOAT(6,c2_start_neg,c2_start_done) temp_f5 = iGpffff81f4 * temp_f3;
        BYTE_FLOAT(2,c2_end_neg,c2_end_done) temp_f2 = iGpffff81f4 * temp_f3; temp_f5 = temp_f5 * temp_f0 + temp_f2 * temp_f1; out2 = (s32)(temp_f5 * 255.0f + 0.5f);
        BYTE_FLOAT(7,c3_start_neg,c3_start_done) temp_f5 = iGpffff81f4 * temp_f3;
        BYTE_FLOAT(3,c3_end_neg,c3_end_done) temp_f2 = iGpffff81f4 * temp_f3; temp_f5 = temp_f5 * temp_f0 + temp_f2 * temp_f1; out3 = (s32)(temp_f5 * 255.0f + 0.5f);
        func_00457140(out0 & 0xFF, out1 & 0xFF, out2 & 0xFF, out3 & 0xFF); *(u32 *)(arg0 + 0xC) += 1; return 0;
    }
    func_00457140(arg0[0], arg0[1], arg0[2], arg0[3]); return 1;
}

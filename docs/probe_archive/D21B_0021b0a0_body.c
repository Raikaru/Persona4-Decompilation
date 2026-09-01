/* object 240B; retail window 240B; normalized_diff 0; exact live MATCH. */
typedef struct DatUnit DatUnit;
extern s32 func_00231ed0(DatUnit *arg0);
extern s32 func_00231f80(DatUnit *arg0);

f32 func_0021b0a0(u8 *arg0)
{
    f32 var_f20;
    f32 var_f0;
    u32 temp_2;
    u32 temp_2_2;

    if (*(s32 *)(arg0 + 0xA64) == 0) {
        return 0.0f;
    }
    temp_2 = (u32)func_00231f80((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f20 = (f32)temp_2;
    if (var_f20 == 0.0f) {
        return 0.0f;
    }
    temp_2_2 = (u32)func_00231ed0((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f0 = (f32)temp_2_2;
    return var_f0 / var_f20;
}

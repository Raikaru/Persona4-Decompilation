/* Best body so far for func_00108590: object 592 bytes, normalized diff 14 (AoB08590restoredecl). Remaining +224 and +380/+388 register differences are move a1 vs v1: candidate keeps named u16 var_3 separate from conversion v1, while retail appears to carry the conversion result in v1 through the update/loop, i.e. one extra simultaneously-live value. */
// FUN_00108590
u16 func_00108590(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_0046d730(void *file, s32 line);
    extern s32 func_0026bc10(u32 resourceId, u32 value);
    typedef struct { f32 x; f32 y; f32 z; } Vec3;
    typedef struct {
        f32 bytes[3];
        s32 pad0;
        f32 durations[3];
        s32 pad1;
        f32 thresholds[3];
        s32 pad2;
    } Table;
    Table vals;
    u16 var_3;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f1;
    s32 *temp_2;
    s32 temp_16;
    u32 var_4;
    *(Vec3 *)vals.thresholds = *(Vec3 *)D_005E42D8;
    *(Vec3 *)vals.durations = *(Vec3 *)D_005E42E8;
    *(Vec3 *)vals.bytes = *(Vec3 *)D_005E42F8;
    if (!(arg0 & 0xFFFF)) {
        arg0 = func_00108e10() & 0xFFFF;
    }
    if (!(arg0 & 0xFFFF)) {
        func_0046d730(&D_005E42C8[0], 0x21F);
    }
    {
        s32 *temp_2_2;
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
    }
    var_4 = 0;
    while (var_4 < 3U) {
        if (var_3 > *(s32 *)&vals.thresholds[var_4]) {
            var_4 += 1;
            continue;
        }
        break;
    }
    temp_16 = var_4 * 4;
    func_0045af60(0, 0, 4, *(s16 *)((u8 *)vals.durations + temp_16));
    if (arg2 != -1) {
        func_0026bc10(((arg2 & 0x3FF) | 0xC00) & 0xFFFF,
                      *(u8 *)((u8 *)vals.bytes + temp_16));
    }
    temp_2 = (s32 *)func_001070e0(arg0);
    if (temp_2 == NULL) {
        return 0U;
    }
    return *(u16 *)((u8 *)temp_2 + 8);
}

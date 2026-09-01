/*
 * func_001f5bd0 archive (2026-08-14)
 * object_size=736 bytes; retail_window=720 bytes; normalized_diff=171
 * differing_offsets: every reloc-masked word in the 0x000..0x2dc body span
 * (171 offsets; fndiff output recorded the complete list).
 * int-to-float sites: four func_001ef5f0 results and func_00231d70(0xf)+5,
 * each rewritten as (f32)(u32)value.
 * float-to-unsigned site: final 100.0f/ratio rewritten as (u16)f1.
 * callee declaration corrected at file scope: func_001ef5f0(s32,s32,s32).
 * ruled out by this measurement: the direct-cast body shape; because the
 * object exceeded the retail window it was archived before further probes.
 */
void func_001f5bd0(s32 arg0) {
    s32 value = arg0;
    u32 index = (u16)value;
    f32 ratio;
    f32 f0;
    f32 f1;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 temp;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    s32 count;
    u32 offset;

    *(u16 *)((u8 *)iGpffffb3ac + 0xA48) =
        (u16)(*(u16 *)((u8 *)iGpffffb3ac + 0xA48) |
              ((1 << index) & 0xFFFF));
    if (index != 0) {
        return;
    }

    temp = func_001ef5f0(1, 3, 0x80000);
    f21 = (f32)(u32)temp;
    temp2 = func_001ef5f0(2, 3, 0x80000);
    f20 = (f32)(u32)temp2;
    temp3 = func_001ef5f0(1, 4, 0x80000);
    f23 = (f32)(u32)temp3;
    temp4 = func_001ef5f0(2, 4, 0x80000);
    f22 = (f32)(u32)temp4;
    count = (s32)func_00231d70(0xF) + 5;
    f0 = (f32)(u32)count;
    ratio = (f0 / 10.0f) * (30.0f * ((f21 / f20) * (f23 / f22)));
    if (!(ratio <= 50.0f)) {
        ratio = 50.0f;
    } else if (ratio < 10.0f) {
        ratio = 10.0f;
    }
    offset = index * 4;
    *(u16 *)((u8 *)iGpffffb3ac + offset + 0xA44) = 0;
    f1 = 100.0f / ratio;
    *(u16 *)((u8 *)iGpffffb3ac + offset + 0xA46) = (u16)f1;
}

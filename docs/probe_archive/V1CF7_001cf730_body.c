// FUN_001CF730
void func_001cf730(u8 *camera)
{
    struct {
        f32 sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64;
        RtQuat_001c sp68;
        u8 pad_to_80[8];
        RwMatrix_001c sp80;
        u8 pad_to_C8[8];
        f32 spC8, spCC, spD0, spD4, spD8;
        f32 pad_to_E0_2;
        f32 spE0, spE4, spE8;
        f32 pad_to_F0;
        f32 spF0, spF4, spF8;
        f32 pad_to_100;
        f32 sp100, sp104, sp108;
        f32 pad_to_110;
        f32 sp110, sp114, sp118;
        f32 pad_tail;
    } stack;
    f32 var_f21, temp_f0, temp_f0_2, temp_f1, temp_f1_2, temp_f1_3;
    f32 temp_f1_4, temp_f1_5, temp_f20, temp_f2, temp_f2_2, temp_f3, temp_f3_2;
    f32 temp_f5, temp_f6, temp_e4;
    u8 *work;

#define sp40 stack.sp40
#define sp44 stack.sp44
#define sp48 stack.sp48
#define sp4C stack.sp4C
#define sp50 stack.sp50
#define sp54 stack.sp54
#define sp58 stack.sp58
#define sp5C stack.sp5C
#define sp60 stack.sp60
#define sp64 stack.sp64
#define sp68 stack.sp68
#define sp80 stack.sp80
#define spC8 stack.spC8
#define spCC stack.spCC
#define spD0 stack.spD0
#define spD4 stack.spD4
#define spD8 stack.spD8
#define spE0 stack.spE0
#define spE4 stack.spE4
#define spE8 stack.spE8
#define spF0 stack.spF0
#define spF4 stack.spF4
#define spF8 stack.spF8
#define sp100 stack.sp100
#define sp104 stack.sp104
#define sp108 stack.sp108
#define sp110 stack.sp110
#define sp114 stack.sp114
#define sp118 stack.sp118
    work = *(u8 **)(*(s32 *)(iGpffffb3ac + 0x148) + 0x30);
    var_f21 = func_00196040(2, 1, (u8 *)&spD0, 0, 0, 1);
    func_001958f0(work, &sp110);
    sp100 = sp110 - spD0;
    sp104 = sp114 - spD4;
    sp108 = sp118 - spD8;
    temp_f1 = fGpffff819c * RwV3dNormalize((RwV3d_001c *)&sp100,
                                            (RwV3d_001c *)&sp100);
    temp_f3 = sp100 * temp_f1;
    spF0 = temp_f3;
    temp_f2 = sp104 * temp_f1;
    spF4 = temp_f2;
    temp_f1_2 = sp108 * temp_f1;
    spF8 = temp_f1_2;
    spE0 = spD0 + temp_f3;
    spE4 = spD4 + temp_f2;
    spE8 = spD8 + temp_f1_2;
    if (var_f21 < 450.0f)
        var_f21 = 450.0f;
    temp_f20 = var_f21 / tanf(fGpffff819c * (0.5f * *(f32 *)(camera + 0xB8)));
    RwMatrixRotate(&sp80, (RwV3d_001c *)D_0060A0E0, 35.0f, 0);
    func_003e4320((RwV3d_001c *)&spF0, (RwV3d_001c *)D_0060A0F0, &sp80);
    func_003dcb40((s64 *)&sp100, (s64 *)&spF0, 1, (u8 *)(work + 0x1c));
    sp110 = sp100 * var_f21;
    sp114 = sp104 * var_f21;
    sp118 = sp108 * var_f21;
    func_001bd780(&sp68, &sp110, &spE0, D_0060A0D0);
    func_003dcb40((s64 *)&spF0, (s64 *)D_0060A0F0, 1, (u8 *)&sp68);
    temp_f1_3 = 50.0f + temp_f20;
    temp_f0 = spF0 * temp_f1_3;
    sp100 = temp_f0;
    sp104 = spF4 * temp_f1_3;
    temp_f0_2 = spF8 * temp_f1_3;
    sp108 = temp_f0_2;
    temp_f1_4 = temp_f20 * tanf(fGpffff819c * (0.5f * *(f32 *)(camera + 0xB8)));
    temp_f1_4 *= 0.21875f;
    temp_f1_4 *= fGpffff80fc;
    spC8 = sp100;
    spCC = sp108;
    func_003e4320((RwV3d_001c *)&spC8, (RwV3d_001c *)D_0060A0F0, &sp80);
    temp_f6 = spE0 + spCC * temp_f1_4;
    spE0 = temp_f6;
    temp_f5 = spE8 - spC8 * temp_f1_4;
    spE8 = temp_f5;
    sp5C = temp_f6 + sp100;
    temp_e4 = spE4;
    sp60 = temp_e4 + sp104;
    sp64 = temp_f5 + sp108;
    *(RtQuat_001c *)&sp4C = sp68;
    temp_f1_5 = temp_f20 - 50.0f;
    temp_f3_2 = spF0 * temp_f1_5;
    sp100 = temp_f3_2;
    temp_f2_2 = spF4 * temp_f1_5;
    sp104 = temp_f2_2;
    temp_f0_2 = spF8 * temp_f1_5;
    sp108 = temp_f0_2;
    sp40 = temp_f6 + temp_f3_2;
    sp44 = temp_e4 + temp_f2_2;
    sp48 = temp_f5 + temp_f0_2;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x40);
    func_001bac20(camera, (f32 *)&sp40, (f32 *)&sp5C, 1);
    func_001bbef0(camera, 3.5f);
#undef sp40
#undef sp44
#undef sp48
#undef sp4C
#undef sp50
#undef sp54
#undef sp58
#undef sp5C
#undef sp60
#undef sp64
#undef sp68
#undef sp80
#undef spC8
#undef spCC
#undef spD0
#undef spD4
#undef spD8
#undef spE0
#undef spE4
#undef spE8
#undef spF0
#undef spF4
#undef spF8
#undef sp100
#undef sp104
#undef sp108
#undef sp110
#undef sp114
#undef sp118
}

/* object_size=796; window=800; normalized_diff=527; differing_offsets=48,64,72,88,100-112,160,216,248,272,276,328,356,372,384,432,448,460,480,548,576,604,620,680,696,748; status=MISMATCH; levers tried: while(1)+break (condition at top, 4-byte shorter), while cond with arg0 (saves s3, condition at top), goto loop_8 with var_4 reload (condition at top, 4-byte shorter); unresolved: loop not inverted by MWCC, branch targets off by 4, GPREL lwc1 immediates differ from retail even with same symbol; ruled out: COP1 accumulator chain, no MMI; remains an ex-"COP1 floor" archive with no source probing. */

void func_002258b0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    u8 *var_4;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;
    u16 temp_2;
    f32 var_f20;
    f32 var_f12;

    var_4 = *(u8 **)(arg0 + 0xE0);
    if ((var_4 != NULL) && ((*(u16 *)(var_4 + 0x1A) & 1) != 0)) {
        if (var_4 != NULL) {
            temp_16 = *(u8 **)(var_4 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2)) == 0) {
                var_17 = 0;
loop_8:
                var_4 = *(u8 **)(arg0 + 0xE0);
                if ((var_17 & 0xFFFF) < *(u16 *)(var_4 + 0x6A)) {
                    temp_4 = *(u8 **)(*(u8 **)(var_4 + 0x38 + ((var_17 & 0xFFFF) * 4)) + 0x30);
                    if ((*(u8 *)(temp_4 + 0xA2)) == 1) {
                        func_00195590(temp_4, temp_16 + 4);
                    }
                    var_17 = (var_17 + 1) & 0xFFFF;
                    goto loop_8;
                }
            }
        }
        temp_3 = *(u8 **)(var_4 + 0x30);
        if ((*(u8 *)(temp_3 + 0xA2)) == 0) {
            func_001c9820(arg0, 0, 1, 0.0f);
            return;
        }
        temp_4_2 = *(u8 **)(*(u8 **)(var_4 + 0x38) + 0x30);
        var_f20 = 1.5f;
        var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0xC);
        temp_2 = *(u16 *)(temp_3 + 0xA4);
        switch (temp_2) {
        case 0x100:
            var_f20 = 1.75f;
            var_f12 = 0.0f;
            break;
        case 0x101:
            var_f20 = 3.5f;
            var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x68);
            break;
        case 0x102:
            var_f20 = 3.75f;
            if (func_00232710(*(u8 **)(temp_4_2 + 0xA64), 0x100000) == 0) {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x144);
            } else {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x148);
            }
            break;
        case 0x103:
            var_f20 = 3.0f;
            var_f12 = 0.0f;
            break;
        case 0x104:
            var_f20 = 4.5f;
            if (func_00232710(*(u8 **)(temp_4_2 + 0xA64), 0x100000) == 0) {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0);
            } else {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x148);
            }
            break;
        case 0x105:
            var_f20 = 3.5f;
            var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x68);
            break;
        case 0x106:
            var_f20 = 2.25f;
            var_f12 = 0.0f;
            break;
        case 0x107:
            var_f20 = 3.0f;
            var_f12 = 0.0f;
            break;
        case 0x108:
            var_f20 = 3.5f;
            if (func_00232710(*(u8 **)(temp_4_2 + 0xA64), 0x100000) == 0) {
                var_f12 = 0.0f;
            } else {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0x14C);
            }
            break;
        case 0x10A:
            var_f20 = 3.5f;
            if (func_00232710(*(u8 **)(temp_4_2 + 0xA64), 0x100000) == 0) {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0xE8);
            } else {
                var_f12 = 0.0f;
            }
            break;
        case 0x10B:
            var_f20 = 3.5f;
            var_f12 = 0.0f;
            break;
        case 0x10F:
            var_f20 = 3.5f;
            if (func_00232710(*(u8 **)(temp_4_2 + 0xA64), 0x100000) == 0) {
                var_f12 = *(f32 *)((u8 *)&fGpffff8030 + 0xE8);
            } else {
                var_f12 = 0.0f;
            }
            break;
        case 0x112:
            var_f20 = 3.0f;
            var_f12 = 0.0f;
            break;
        }
        func_002266b0(arg0, var_f12, var_f20, fparg0, fparg1);
    }
}

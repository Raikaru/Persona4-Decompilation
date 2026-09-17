/* MATCH: b210 -O2, opt_loop_invariants on; 764 emitted bytes plus one
 * linker-supplied zero word exactly reproduce the 768-byte retail window.
 * All three call relocations resolve to the retail targets.
 *
 * The final allocation lever is source-level lifetime reuse: arg1 is no
 * longer dereferenced after the first loop, so its register becomes the
 * replica index. Retail consequently uses s4 for that index and s6/s5 for
 * the two row sizes. A separate replica-index local rotates those registers.
 *
 * Alpha remains unsigned: 255 << 24 through a signed value fails UBSan on a
 * valid solid row. Eight 32-bit SSE/UBSan raw-layout scenarios cover segments
 * 0/8, replicas 0/1/2/4, lock-replaced buffers, exact copy ranges, complete
 * color/coordinate images, and canaries. No EE/FCSR runtime claim is made. */
#pragma push
#pragma opt_loop_invariants on
void func_004a30e0(u8 *arg0, u8 *arg1)
{
    u8 *var_19;
    u8 *temp_18;
    u8 *temp_3;
    u8 *var_17;
    u8 *temp_16;
    u32 var_9;
    u32 temp_23;
    u32 var_10;
    s32 temp_4;
    s32 temp_5;
    s32 temp_6;
    s32 temp_7;
    s32 temp_8;
    s32 temp_10;
    f32 var_f0_3;
    f32 var_f0_2;
    f32 var_f0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;

    temp_23 = *(u32 *)(arg1 + 0x38);
    if (temp_23 != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF8);
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        temp_18 = *(u8 **)(temp_3 + 0x30);
        var_19 = temp_18;
        temp_16 = *(u8 **)(temp_3 + 0x34);
        var_17 = temp_16;
        temp_f2 = 3.0f;
        temp_f8 = *(f32 *)(arg1 + 0x90) / temp_f2;
        temp_8 = *(s32 *)(arg1 + 0x8C);
        temp_f1 = (f32)temp_8;
        temp_7 = (s32)(*(f32 *)(arg1 + 0x78) * temp_f1);
        temp_6 = (s32)(*(f32 *)(arg1 + 0x7C) * temp_f1);
        temp_5 = temp_8 + 1;
        temp_4 = temp_5 * 4;
        temp_f2 = 255.0f;
        var_9 = 0;
        while (var_9 < (u32)temp_5) {
            if (var_9 < (u32)temp_7) {
                var_f0 = (f32)(u32)var_9;
                var_f0_2 = var_f0 / (f32)temp_7;
            } else if ((u32)temp_6 < var_9) {
                temp_10 = temp_8 - var_9;
                var_f0_3 = (f32)(u32)temp_10;
                var_f0_2 = var_f0_3 / (f32)(temp_8 - temp_6);
            } else {
                var_f0_2 = 1.0f;
            }
            *(s32 *)var_19 = 0xFFFFFF;
            temp_f0 = temp_f2 * var_f0_2;
            var_10 = (u32)temp_f0;
            *(s32 *)(var_19 + 4) = (var_10 << 24) | 0xFFFFFF;
            *(PolygonWindColor *)(var_19 + 8) = *(PolygonWindColor *)(var_19 + 4);
            *(s32 *)(var_19 + 0xC) = 0xFFFFFF;
            var_19 += 0x10;
            *(s32 *)var_17 = 0;
            temp_f7 = 2.0f * temp_f8;
            temp_f6 = 3.0f * temp_f8;
            *(f32 *)(var_17 + 8) = temp_f8;
            *(f32 *)(var_17 + 0x10) = temp_f7;
            *(f32 *)(var_17 + 0x18) = temp_f6;
            var_17 += 0x20;
            var_9 += 1;
        }
        arg1 = (u8 *)1;
        temp_6 = temp_4 * 4;
        temp_7 = temp_4 * 8;
        while ((uintptr_t)arg1 < temp_23) {
            func_0043f810(var_19, temp_18, (u32)temp_6);
            var_19 += temp_6;
            func_0043f810(var_17, temp_16, (u32)temp_7);
            var_17 += temp_7;
            arg1 = (u8 *)((uintptr_t)arg1 + 1);
        }
    }
}
#pragma pop


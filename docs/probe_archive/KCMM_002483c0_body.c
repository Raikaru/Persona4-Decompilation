/* BEST BODY archive for func_002483c0.
 * Measured object/window: 544B / 544B.
 * normalized_diff_words: 0 (reloc-masked exact MATCH).
 * Exact with scoped #pragma opt_propagation off and declaration-order colouring.
 * Retail saved-register list:
 *   $s6=temp_20 offset, $s5=var_20 counter (initialized 1),
 *   $s4=temp_17 table value, $s3=temp_18 loop mask,
 *   $s2=temp_19 masked arg, $s1=temp_2 result pointer,
 *   $s0=temp_16 table base.
 * MWCC b210 produced that exact $s6..$s2 assignment after the measured
 * opt_propagation-off rule. u16 call_idx conversions keep each retail
 * per-call andi immediate without introducing a saved constant register.
 */
/* measured: scoped opt_propagation off is required for the parameter-derived
   temp_19 local to rank below temp_18; push/pop restores TU state. */
#pragma push
#pragma opt_propagation off
void func_002483c0(u16 arg0) {
    s32 temp_20;
    s32 var_20;
    s32 temp_17;
    s32 temp_18;
    u32 temp_19;
    u8 *temp_2;
    u32 *temp_16;
    u32 *temp_16_2;
    s32 var_3;
    u16 call_idx;

    var_20 = 1;
    temp_19 = arg0;
    while (var_20 < 0x1F) {
        if (temp_19 == var_20) {
            goto block_15;
        }
        if (func_001077f0((u16)var_20) == 0) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (((u16)func_00107ac0(call_idx)) != 0xA) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (func_00248a60(call_idx) == 0) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (func_00107a00(call_idx, 3) != 0) {
            goto block_15;
        }
        {
            u8 *p;
            s32 count;
            s32 i;

            temp_16 = (u32 *)D_00881494[0];
            p = (u8 *)temp_16 + 8;
            count = *(s32 *)(temp_16 + 1);
            i = 0;
            temp_18 = (u16)var_20;
            while (i < count) {
                if (*(u16 *)p == temp_18) {
                    if (*(u16 *)(p + 2) == temp_19) {
                        temp_17 = *(s32 *)(p + 4);
                        goto block_14;
                    }
                }
                p += 8;
                i += 1;
            }
            temp_17 = 0;
block_14:
            call_idx = (u16)var_20;
            temp_2 = (u8 *)func_001070e0(call_idx);
            if (temp_2 == NULL) {
                var_3 = 0;
                goto block_13;
            }
            temp_16 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            call_idx = (u16)var_20;
            temp_20 = call_idx * 0x64;
            if (*(u16 *)((u32)temp_20 + (u32)temp_16 + 0x12) == 0) {
                goto block_12;
            }
            *(u16 *)(temp_2 + 0xA) += temp_17 & 0xFFFF;
            temp_16_2 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16_2[1]) {
                func_0046d730(D_006359D0, 0x4C);
            }
            if (*(u16 *)(temp_2 + 0xA) >= *(u16 *)((u32)temp_20 + (u32)temp_16_2 + 0x12)) {
                var_3 = 1;
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            var_3 = 0;
block_13:
            if (var_3 != 0) {
                call_idx = (u16)var_20;
                func_00107ce0(call_idx);
            }
        }
block_15:
        var_20 += 1;
    }
}
/* measured: restore pragma state after func_002483c0. */
#pragma pop

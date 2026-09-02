/* Best probe for func_00170f60 (not installed).
 * Retail: 0x80-byte frame; saved $s3=arg0, $s2=arg1, $s1=result var_17,
 * $s0=list var_16; 12 bytes of trailing window padding.
 * Best measured: DoF170F60W, object 580B/window 592B, normalized diff 8.
 * Residual: global D_005F1758 load/store ordering and $v0 versus retail $v1
 * coloring. The dead sp60[0] address assignment correctly forced the retail
 * early addiu $a2,$sp,0x50 without changing the emitted body size.
 * Trials: fieldwise coordinates nd54; Vec3 aggregate nd42; named pointer
 * locals nd306-312 with saved-register swaps; opt_propagation/schedule
 * pragmas caused collateral mismatches; declaration-order nd53; comma/global
 * evaluation nd41-42; compound struct initializer nd398; scalar locals nd295;
 * frame aggregate nd42; byte-array pair nd42; split global temporaries nd8;
 * global-struct copy nd318. No trial reached MATCH.
 */

s32 func_00170f60(u8 *arg0, s32 arg1)
{
    Vec3_00178590 sp70;
    u8 *sp60[3];
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f3_2;
    s32 var_17;
    u8 *temp_2;
    u8 *var_16;

    var_17 = 0;
    var_16 = func_001452b0(0xD);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    temp_2 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    sp70 = *(Vec3_00178590 *)(temp_2 + 0x30);
    goto loop_21_cond;
loop_21_body:
    {
        struct {
            s64 first;
            f32 second;
        } sp50;

        sp60[0] = (u8 *)&sp50;
        sp50.first = D_005F1758[0];
        sp50.second = D_005F1760[0];
        sp60[0] = var_16 + 0x15C;
        sp60[1] = var_16 + 0x168;
        sp60[2] = var_16 + 0x174;
        if ((func_00168ec0(&sp70, sp60, &sp50) == 1) &&
            (temp_f3 = *(f32 *)(sp60[0] + 4), (sp70.y < (200.0f + temp_f3))) &&
            !(sp70.y <= (temp_f3 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found1;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found1:
            var_17 = 1;
            goto loop_21_done;
        }
        sp60[0] = var_16 + 0x168;
        sp60[1] = var_16 + 0x174;
        sp60[2] = var_16 + 0x180;
        if ((func_00168ec0(&sp70, sp60, &sp50) == 1) &&
            (temp_f3_2 = *(f32 *)(sp60[0] + 4),
             (sp70.y < (200.0f + temp_f3_2))) &&
            !(sp70.y <= (temp_f3_2 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found2;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found2:
            var_17 = 1;
            goto loop_21_done;
        }
        var_16 = *(u8 **)(var_16 + 0x138);
    }
loop_21_cond:
    if (var_16 != NULL)
        goto loop_21_body;
loop_21_done:
    return var_17;
}

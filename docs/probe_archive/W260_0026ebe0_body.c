/* object 288B, retail window 288B, normalized_diff 17; differing offsets: 0x40,0x44,0x50,0x54,0x5C,0x60,0x64,0x68,0x6C,0x78,0x7C,0x88,0x90,0x94,0x98; casts written: none. */
/* Probes ruled out: explicit labels/persistent base; opt_propagation off; schedule/schedule-off; O1/O3; declaration permutations; register hints; local width/signedness; constant-vs-local materialization; loop for/while/do forms; pointer/base/load-order and operand-order variants; parameter types; alternate pragmas; selective constants and argument-register reuse; masked-result locals; corrected func_00274660(u32, int) prototype; generated-loop shape; scoped local-reuse variants; permute.py 1269 plus bounded rerun. */
/* Common factor: retail reuses $v0 for the 0xA sentinel and $v1 for the decoded byte/index; candidate uses $a0/$v0. No global or callee occurs at the differing words. opt_propagation off preserves target scan preheader ordering. */
#pragma opt_propagation off
s32 func_0026ebe0(s32 arg0, u8 *arg1)
{
    s32 temp_3;
    s32 var_16;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    u8 *temp_3_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_16 = 0;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_6 = 0xF0;
    temp_3_5 = 0xA;
    goto scan_loop;
decode:
    if ((temp_3_2 & 0xF0) == temp_3_6) {
        var_16 += (((temp_3_2 & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)temp_3_2 < 0x80U) {
        goto scan_loop;
    }
    var_16 += 1;
    goto scan_loop;
scan_loop:
    temp_3 = var_16;
    var_16 += 1;
    temp_3_2 = *(s8 *)(temp_3_3 + temp_3);
    if (temp_3_2 != temp_3_5) {
        goto decode;
    }
    func_0043f9c8(&D_00881530, 0, 0x80);
    func_0043f810(&D_00881530,
                  (void *)(*(s32 *)(arg1 + 0x10) + *(s32 *)(arg1 + 0x18)),
                  var_16);
    *((u8 *)((s32)&D_0088152F + var_16)) = 0;
    func_00274660(4, 1);
    *(s32 *)(arg1 + 0x18) = *(s32 *)(arg1 + 0x18) + var_16;
    return 0;
}
/* measured: closes the opt_propagation probe above at the file baseline. */
#pragma opt_propagation on

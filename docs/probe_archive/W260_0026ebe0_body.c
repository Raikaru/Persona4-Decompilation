/* object 288B, retail window 288B, normalized_diff 17 for the archived pre-close body; differing offsets: 0x40,0x44,0x50,0x54,0x5C,0x60,0x64,0x68,0x6C,0x78,0x7C,0x88,0x90,0x94,0x98; casts written: none. */
/* Probes ruled out: explicit labels/persistent base; schedule/schedule-off; O1/O3; declaration permutations; register hints; local width/signedness; constant-vs-local materialization; loop for/while/do forms; pointer/base/load-order and operand-order variants; parameter types; alternate pragmas; selective constants and argument-register reuse; masked-result locals; corrected func_00274660(u32, int) prototype; generated-loop shape; scoped local-reuse variants; permute.py 1269 plus bounded rerun. */
/* Temporary-rule record (fresh): at the mask-test window retail carries four scalar values in role/register order decoded byte or index=$v1, sentinel 0xA=$v0, mask 0xF0=$a0, and masked result=$a1; the archived candidate carried decoded/index=$v0, sentinel=$a0, mask=$a1, and masked result=$v1. Moving sentinel materialization into scan_loop, moving mask materialization into decode, and folding the mask assignment into its compare changed the liveness order; normalized_diff went 15 -> 3 -> 0 at 288B. */
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

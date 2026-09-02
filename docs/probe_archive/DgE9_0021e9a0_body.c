/*
 * Probe archive for func_0021e9a0 (448B window).
 * Best measured body: object_size=448, window=448, normalized_diff=6,
 * first differing word indices 353, 358, 366, 370, 378, 386
 * (lane DgE9ResultS32). It is archived rather than left live because it
 * is not a MATCH.
 *
 * Retail saved-register list: $s3, $s2, $s1, $s0, in that order.
 * Retail residual sequence is the final halfword sign-extension/clamp
 * register coloring: retail uses $v0 for dsll32/dsra32, $at for slti/bnez,
 * $v0 for the clamp constant, and $v0 for the final andi; this body uses
 * the alternate $v1/$v0 coloring at those six words.
 *
 * Tried: split s32/s16 temporaries; s16 and u16 result declarations;
 * s32 result temporary with direct (s16) comparison; union overlay;
 * explicit narrow operand cast; repeated direct sum in the comparison;
 * opt_propagation off and opt_common_subs off; helper value prototype
 * narrowing. None produced a MATCH. The helper prototype was restored
 * before source restoration.
 */
void func_0021e9a0(u8 *arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 var_16;
    s32 var_17;
    u8 *temp_19;
    u8 *temp_20;
    s32 temp_21;
    s32 temp_22;
    temp_17 = (s32)func_00105510(1);
    temp_2 = (s32)func_00105210(1);
    if ((func_001059e0(temp_2) & 0xFF) < 0x63) {
        temp_16 = temp_2 + *(s32 *)(arg0 + 4);
        func_00105990(1, temp_16);
        func_00231ef0((u8 *)temp_17, func_001059e0(temp_16));
    }
    var_16 = *(s32 *)(arg1 + 8);
    if (var_16 <= 0) {
        var_16 = 0;
    } else if ((*(u16 *)arg1 & 8) == 0 && func_00106330(0x1403) != 0) {
        if (func_00106330(0x1420) != 0) {
            var_16 = (s32)(2.0f * (f32)var_16);
        } else if (func_00106330(0x1421) != 0) {
            var_16 = 1;
        }
    }
    func_00106020(var_16);
    var_17 = 0;
    while (var_17 < *(s32 *)(arg1 + 0x30)) {
        temp_19 = arg1 + var_17 * 4;
        temp_20 = temp_19 + 0x24;
        temp_21 = (s16)(func_00106600(*(s16 *)(temp_19 + 0x24)) & 0xFF);
        temp_22 = temp_21 + *(s16 *)(temp_19 + 0x26);
        if (!((s16)temp_22 < 0x64)) {
            temp_22 = 0x63;
        }
        func_00106620(*(s16 *)temp_20, (u8)temp_22);
        var_17 += 1;
    }
}

/* object 244B/window 256B, normalized_diff 174, differing offsets 0x004-0x0C4 (58 differing words); classification: MWCC near-miss, exact six `$s` saves/frame but retail pre-save count load and branch/call layout remain wrong. Retail prologue: addiu $sp,-128; lw $v0,4($a0); sd $ra,96($sp); sq $s5..$s0 at 80..0. Block-scope old-style callee declarations: func_003df1a0, func_003df240, func_003df270. Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; schedule-on goto shape measured, no further probe. */
#pragma schedule on
// FUN_00416CF0
s32 func_00416cf0(u8 *arg0, s32 arg1)
{
    extern s32 func_003df1a0();
    extern s32 func_003df240();
    extern s32 func_003df270();
    s32 sp7C;
    s32 *temp_16;
    s32 *var_17;
    s32 temp_18;
    s32 var_19;

    temp_16 = *(s32 **)(arg0 + 0x10);
    temp_18 = (s32)(*(s32 **)(arg0 + 0x14));
    var_19 = 0;
    if (*(s32 *)(arg0 + 4) > 0) {
        var_17 = temp_16;
loop_2:
        if (func_003df1a0(arg1, (s32 *)((u8 *)var_17 + 4), 4) == 0)
            goto block_10;
        if (func_003df270(arg1, (s32 *)((u8 *)var_17 + 8), 0xE) != 0) {
            sp7C = *var_17 - (s32)temp_16;
            if (func_003df240(arg1, &sp7C, 4) != 0) {
                var_19 += 1;
                var_17 = (s32 *)((u8 *)var_17 + 24);
                if (var_19 < *(s32 *)(arg0 + 4))
                    goto loop_2;
                goto block_8;
            }
        }
    }
block_10:
    return 0;
block_8:
    return func_003df1a0(arg1, (s32 *)temp_18, 0x18) != 0;
}
#pragma schedule off

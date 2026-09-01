/* object 204B, window 224B, normalized_diff 141; fndiff differing offsets 0x00-0xDC except relocation-masked helper-call words; casts written: explicit byte-pointer field arithmetic; levers ruled out: schedule+no_branch_likely-on (188B/39), direct versus saved arg0, and old-style helper declaration. Compiler check: sq $s2/$s1/$s0 prologue => MWCCPS2 workable. Corrected source includes the post-loop sentinel reload (`var_17 = *(arg0 + 4)`) evidenced by retail's `lw $s1,4($s0)`; frame/register allocation remains nonmatching. */
s32 func_00414ef0(u8 **arg0)
{
    u8 *var_17;
    u8 *var_18;
    s32 func_00414930();

    var_18 = NULL;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    var_17 = *(u8 **)(*(u8 **)((u8 *)arg0 + 4) + 8);
    if (var_17 != NULL) {
        do {
            if (func_00414930(var_17, var_18, arg0) == 0) {
                return 0;
            }
            if (var_18 == NULL) {
                *(u8 **)((u8 *)arg0 + 8) = *(u8 **)var_17;
            }
            var_18 = var_17;
            var_17 = *(u8 **)(var_17 + 8);
        } while (var_17 != NULL);
    }
    var_17 = *(u8 **)((u8 *)arg0 + 4);
    if (func_00414930(var_17, var_18, arg0) != 0) {
        if (var_18 == NULL) {
            *(u8 **)((u8 *)arg0 + 8) = *(u8 **)var_17;
        }
        *(s32 *)((u8 *)arg0 + 0x18) = 0;
        return 1;
    }
    return 0;
}

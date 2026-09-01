/* object 176B / window 176B / normalized_diff 31 / differing offsets 20,24,32,36,40,44,48,64,72,76,80,88,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172; casts written: none; levers ruled out: parameter u8*/u32* forms, integer-domain pointer arithmetic, self/base locals, signed/unsigned loop index, declaration-order permutations, optimization_level 1/3. */
void func_003cdfa0(u32 *arg0) {
    extern void func_003cc6e0(u8 *arg0);
    extern void func_003e1ea0(s32 arg0);
    extern void (*jtbl_008873EC[])(u8 *arg0);
    s32 var_17;
    u32 temp_2;
    u8 *temp_19;
    u32 *var_16;

    temp_2 = *arg0;
    var_17 = (s32)temp_2 - 1;
    if (temp_2 == 0)
        goto done;
    var_16 = arg0 + var_17;
loop:
    temp_19 = *(u8 **)((u8 *)var_16 + 4);
    if (temp_19 == NULL)
        goto next;
    if (*(s32 *)(temp_19 + 0) != 0)
        goto clear;
    if (*(s32 *)(temp_19 + 4) != 0)
        goto clear;
    func_003cc6e0(temp_19);
    func_003e1ea0((s32)temp_19);
    goto next;
clear:
    *(s32 *)(temp_19 + 0x10) = 0;
next:
    if (var_17 != 0) {
        var_16 -= 1;
        var_17 -= 1;
        goto loop;
    }
done:
    jtbl_008873EC[0]((u8 *)arg0);
}

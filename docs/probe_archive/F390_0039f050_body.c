/* object 132B / window 144B / normalized_diff 10 / differing bytes 0x48-0x4F and 0x50-0x53 (global-table addiu/addu and saved-field load order); retail logic, pointer-chain loads, delay slots, callback arguments, stores and epilogue all match. Ruled out direct field expansion, holder->8 ordering, declaration reordering, named handler/base locals, typed/old-style callback calls, callback-table typing, O1/O3, opt_propagation off and schedule off/on. */
void func_0039f050(u8 *arg0)
{
    s32 temp_17;
    s32 temp_5;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_6;

    temp_2 = *(u8 **)(*(s32 *)(*(u8 **)(arg0 + 0x2C) + 8) + iGpffffb5e0);
    if (temp_2 != NULL) {
        var_2 = *(s32 *)(temp_2 + 0x80);
    } else {
        var_2 = 0;
    }
    temp_6 = *(u8 **)(arg0 + 4);
    temp_5 = var_2 * 0x10;
    temp_17 = *(s32 *)(temp_6 + 0x18);
    *(s32 *)(temp_6 + 0x18) = temp_17 + temp_5;
    ((s32 (*)())(*(void **)(D_0064F2B4 + (var_2 * 4))))(arg0, temp_5, temp_6);
    *(s32 *)(*(u8 **)(arg0 + 4) + 0x18) = temp_17;
}

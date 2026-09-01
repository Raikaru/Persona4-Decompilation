/* object_size=164; window=176; normalized_diff=72; differing_offsets=0x04-0x20,0x50-0x88; classification: exact helper-call sequence and tail after declaration/order probes, but retail preserves the post-zero reload and a distinct 0x4C materialization/register map that plain MWCC folds; tried pointer-width/signature variants, reverse global-plus-field order, split constant updates, local aggregate/pointer temporaries, opt_propagation off, opt_common_subs off, and correctly scoped optimization_level 1; live source restored to INCLUDE_ASM. */
s32 func_003fdd10(u8 *arg0, u8 *arg1)
{
    extern s32 func_003e4ad0(char *arg0);
    s32 *out;
    u8 *temp_4;

    *(u32 *)arg0 = 0;
    out = (s32 *)arg0;
    *out += 0x14;
    *out += func_003e4ad0((char *)(arg1 + 0x10)) + 0xC;
    *out += func_003e4ad0((char *)(arg1 + 0x30)) + 0xC;
    temp_4 = (u8 *)(iGpffffb938 + *(s32 *)arg1);
    *out += *(s32 *)(temp_4 + 0x28) + *(s32 *)(temp_4 + 0x2C) + 0xC;
    *out += 0x4C;
    *out += 0xC;
    return 1;
}

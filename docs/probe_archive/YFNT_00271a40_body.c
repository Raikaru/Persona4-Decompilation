/* object 292B, window 304B, normalized_diff 18; differing offsets 0xA0,0xA4,0xA8,0xAC,0xC0,0xC4,0xC8,0xCC,0xD4 (reloc-masked); casts written: none (no mtc1/mfc1 conversion sites); ruled out: par-delta baseline variants, direct-base and array-index forms, post-call par/idx reassignment forms, pointer/integer offset locals, pointer declaration-order permutations, optimization_level 1 with and without opt_common_subs off; fresh probes: pointer-difference forms (both sites and store-only), distributed scaling (both sites and store-only), integer-domain cast forms (both sites and store-only), u32-par pointer-difference form, idx aliases, and shifted par scaling either reproduced baseline or exceeded window. */
void func_00271a40(void)
{
    s32 i;
    s32 mask;
    s32 idx;
    u32 tmp;
    u8 *slot;
    u8 *par;
    for (i = 0; i < 9; i++) {
        if (*(u32 *)((u8 *)DAT_00881630_abs + i * 0x20 + 0x1c) == 0)
            continue;
        mask = i & 0xff;
        if (mask >= 9)
            func_0046d740(D_0063BBB0, D_0063BAE8, 0x319);
        idx = i & 0xff;
        slot = (u8 *)DAT_00881630_abs + idx * 0x20;
        if (*(u32 *)(slot + 0x1c) == 0)
            func_0046d730(D_0063BAE8, 0x31D);
        par = (u8 *)DAT_00881630_abs + idx * 4;
        tmp = *(u32 *)(par + 0x180);
        if (tmp == 0)
            continue;
        *(u32 *)(par + ((u8)i - idx) * 4 + 0x180) = 0;
        func_00454bd0(tmp);
        func_00440b68(D_0063BBF0, mask);
        *(u32 *)slot = 0;
        *(u32 *)(slot + 0x1c) = 0;
    }
}

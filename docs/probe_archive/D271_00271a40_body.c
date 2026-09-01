/* object_size=292 window=304 normalized_diff=18 differing_words=12 differing_word_offsets=160,164,168,172,192,196,200,204,212; first_diff_bytes=161,166,170,174,192,194,196,198,200,201,202,203,204,205,206,207; retail_tail=12 bytes */
/* corrected declarations before probe: func_0046d740(void), func_0046d730(void); helper calls retained as func_00454bd0(u8 *) and func_00440b68(const void *, ...). */
/* measured: nd18. retail keeps the par-load base in $a1 and reuses it for the
   free-slot store at +0x180 (`addu $v0,$a1,$v0; addiu $s1,$v0,0x180` before).
   Expressing the store as `par + ((u8)i - idx)*4` forces b210 to reuse the
   live par temp (call-clobbered) so the address is computed before the jal
   instead of re-materialising the base (nd67); the residual 18 is the subu
   from the (u8)i-idx delta plus the par-load temp register names
   ($a0/$v1 vs retail $v1/$a1). opt_common_subs off is required for the three
   re-issued andi masks (retail andi $s2/$s1/$v0 from $s3). A measured
   optimization_level 1 bracket (with and without opt_common_subs off) leaves
   nd18 unchanged; the load-sinking family remains a floor. Committed at nd
   18. */
#pragma opt_common_subs off
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
        func_00454bd0((u8 *)tmp);
        func_00440b68(D_0063BBF0, mask);
        *(u32 *)slot = 0;
        *(u32 *)(slot + 0x1c) = 0;
    }
}
/* measured: restore the translation unit's default common-subexpression mode. */
#pragma opt_common_subs on

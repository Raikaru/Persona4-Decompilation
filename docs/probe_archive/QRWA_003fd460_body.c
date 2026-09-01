/* object_size=184; window=192; normalized_diff=64; differing_offsets=0x1C,0x28-0x40,0x5C-0xB8; classification: exact frame/saved-register count and core field/callback operations, but retail saves arg2 in $s1 and delays arg1 into $s0 while plain b210 colors the saved parameters oppositely; branch/layout and flag-store residuals remain; tried no_branch_likely, explicit goto guard layout, saved-argument/base-pointer locals, declaration-order swap, signed/unsigned parameter variants, and typed outer-field aggregate; live source restored to INCLUDE_ASM. */
s32 func_003fd460(s32 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_0040fa90(u8 *arg0);
    typedef struct {
        u8 pad[0x23];
        u8 flags23;
    } Rec;
    u8 *p;
    s32 saved_arg2;
    s32 temp_19;
    u8 temp_3;

    saved_arg2 = arg2;
    if ((((Rec *)arg1)->flags23 & 0x60) == 0)
        goto done;
    p = arg1;
    temp_3 = *(u8 *)(p + 0x21);
    if ((temp_3 & 0x80) != 0)
        goto done;
    temp_19 = saved_arg2 & 1;
    if ((temp_19 != 0) && ((temp_3 & 0x40) == 0)) {
        func_0040fa90(p);
    }
    *arg0 = *(s32 *)(p + 8);
    if (temp_19 != 0) {
        *(u8 *)(p + 0x22) |= 0x10;
    }
    if ((saved_arg2 & 2) != 0) {
        *(u8 *)(p + 0x22) |= 8;
    }
    return 1;
done:
    return 0;
}

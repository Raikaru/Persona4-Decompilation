/* object_size=328B; window=336B; normalized_diff=33; differing_offsets=0x2C-0x44,0xDC-0xF4,0xFC-0x100,0x10C-0x140. */
/* Retail-derived body. Corrected local declarations: func_00451de0 uses its
   verified seven-argument callback shape; func_003556a0 uses (u8 *, s16,
   s32). The residual is argument/register staging and local color-byte
   extraction; no conversion idiom is present. This body is archived and is
   not live in src/. */
s32 func_00355550(s16 arg0, s32 arg1, s16 arg2, s16 arg3,
                  s64 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 result;
    u8 *temp_2;
    s32 color[1];
    extern u8 D_0064B410[];
    extern s32 func_003558a0(u8 *);
    extern void func_00356140(u8 *);
    extern s32 func_00451de0(void *, s32, s32, s32, void *, void *, void *);
    extern void func_003556a0(u8 *, s16, s32);

    color[0] = arg1;
    func_0044ea90(&D_0064B310, 0x63D);
    temp_2 = D_008873F4[0](1, 0x22C, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064B310, 0x63E);
    }
    result = func_00451de0(&D_0064B410, arg6, 0, 0,
                           (void *)func_003558a0, (void *)func_00356140,
                           temp_2);
    *(s16 *)(temp_2 + 0x0) = arg0;
    *(s32 *)(temp_2 + 0x4) = arg5;
    *(s16 *)(temp_2 + 0xC) = arg2;
    *(s16 *)(temp_2 + 0xE) = arg3;
    *(u8 *)(temp_2 + 0x14) = ((u8 *)color)[0];
    *(u8 *)(temp_2 + 0x15) = ((u8 *)color)[1];
    *(u8 *)(temp_2 + 0x16) = ((u8 *)color)[2];
    *(u8 *)(temp_2 + 0x17) = ((u8 *)color)[3];
    func_003556a0(temp_2, (s16)arg4, arg7);
    return result;
}

/* object_size=716, window=688, normalized_diff=453; differing offsets=0x0000 onward (prologue/frame divergence). Oversized; archived after stack-buffer probe. Ruled out: sp60 sizes 0x100/0xF0/0xE0, s16/s32/u8 temp_5, declaration-order swaps, s32-pointee vs address typing, temp_6 intermediate, pointer pin, typed/old-style helper prototypes, func_001060b0 s64 return correction, frame 0x160/0x170/0x180, ordinary-C local reorder. */
void func_001f9cf0(u8 *arg0)
{
    s16 temp_17;
    s16 temp_6;
    s16 temp_6_2;
    s16 temp_6_3;
    s16 temp_6_4;
    s32 *temp_18;
    s32 temp_16;
    s32 temp_5;
    s32 var_19;
    u16 temp_4;
    u8 sp60[0x100];

    temp_5 = (func_00110d60((s16)func_001060b0()) & 1) != 0;
    temp_4 = *(u16 *)arg0;
    switch (temp_4) {
    case 0:
        temp_17 = *(s16 *)(arg0 + 8);
        temp_18 = (s32 *)(&iGpffffa520 + temp_5 * 4);
        temp_6 = temp_17 + 1;
        func_00442088(sp60, D_00625060, temp_6, temp_6, *temp_18);
        func_00440b68(&iGpffffa528, D_00625090, 0x26);
        *(s32 *)(iGpffffb3ac + 0xB6C) = func_00454a60(sp60, 0);
        var_19 = 0;
        while (var_19 < temp_17) {
            temp_16 = var_19 * 4;
            temp_6_2 = temp_17 + 1;
            func_00442088(sp60, D_006250A0, temp_6_2, temp_6_2,
                          *(s32 *)(D_00625050 + temp_16),
                          *(s16 *)(arg0 + var_19 * 2 + 2), *temp_18);
            func_00440b68(&iGpffffa528, D_00625090, 0x2C);
            *(s32 *)(iGpffffb3ac + temp_16 + 0xB70) = func_00454a60(sp60, 0);
            var_19++;
        }
        temp_6_3 = temp_17 + 1;
        func_00442088(sp60, D_006250D0, temp_6_3, temp_6_3);
        func_00440b68(&iGpffffa528, D_00625090, 0x2F);
        *(s32 *)(iGpffffb3ac + 0xB58) = func_00454a60(sp60, 0);
        break;
    case 2:
        func_00442088(sp60, D_00625100, *(s16 *)(arg0 + 2),
                      *(s32 *)(&iGpffffa520 + temp_5 * 4));
        func_00440b68(&iGpffffa528, D_00625090, 0x35);
        *(s32 *)(iGpffffb3ac + 0xB58) = func_00454a60(sp60, 0);
        break;
    case 4:
        temp_6_4 = *(s16 *)(arg0 + 2);
        if (temp_6_4 < 0xB) {
            func_00442088(sp60, D_00625130, temp_6_4);
        } else {
            func_00442088(sp60, D_00625160, temp_6_4);
        }
        func_00440b68(&iGpffffa528, D_00625090, 0x40);
        *(s32 *)(iGpffffb3ac + 0xB58) = func_00454a60(sp60, 0);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB50) = temp_4;
}

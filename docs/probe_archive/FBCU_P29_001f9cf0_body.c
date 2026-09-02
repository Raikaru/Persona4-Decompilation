/* Best near-match body from FBCU_P20 (object_size=688, window=688, normalized_diff=8).
 * Retail saved-register list: arg0->$s4, var_19->$s3, temp_18->$s2,
 * temp_17->$s1, temp_16->$s0. Candidate retained temp_17->$s2 and
 * temp_18->$s1; the eight residual words were the corresponding register
 * swaps at offsets 0x6c, 0x79, 0x7e, 0x92, 0xde, 0x10e, 0x152, 0x15e.
 * Tried: s32 temp_17, pointer and declaration permutations, pointer
 * initializer/alias split, temp_17 split, pointer-first scheduling and
 * dependency forms, permitted optimization pragmas, and pointer/type variants.
 */
void func_001f9cf0(u8 *arg0) {
    s32 temp_17;
    s32 *temp_18;
    s32 temp_16;
    s32 temp_5;
    s32 var_19;
    u8 sp60[0x100];

    temp_5 = (func_00110d60((s16)func_001060b0()) & 1) != 0;
    switch (*(u16 *)arg0) {
    case 0:
        temp_17 = *(s16 *)(arg0 + 8);
        temp_18 = (s32 *)(&iGpffffa520 + temp_5 * 4);
        func_00442088(sp60, D_00625060, temp_17 + 1, temp_17 + 1, *temp_18);
        func_00440b68(&iGpffffa528, D_00625090, 0x26);
        *(s32 *)(iGpffffb3ac + 0xB6C) = func_00454a60(sp60, 0);
        var_19 = 0;
        while (var_19 < temp_17) {
            temp_16 = var_19 * 4;
            func_00442088(sp60, D_006250A0, temp_17 + 1, temp_17 + 1,
                          *(s32 *)(D_00625050 + temp_16),
                          *(s16 *)(arg0 + var_19 * 2 + 2), *temp_18);
            func_00440b68(&iGpffffa528, D_00625090, 0x2C);
            *(s32 *)(iGpffffb3ac + temp_16 + 0xB70) = func_00454a60(sp60, 0);
            var_19++;
        }
        func_00442088(sp60, D_006250D0, temp_17 + 1, temp_17 + 1);
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
        if (*(s16 *)(arg0 + 2) < 0xB) {
            func_00442088(sp60, D_00625130, *(s16 *)(arg0 + 2));
        } else {
            func_00442088(sp60, D_00625160, *(s16 *)(arg0 + 2));
        }
        func_00440b68(&iGpffffa528, D_00625090, 0x40);
        *(s32 *)(iGpffffb3ac + 0xB58) = func_00454a60(sp60, 0);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB50) = *(u16 *)arg0;
}

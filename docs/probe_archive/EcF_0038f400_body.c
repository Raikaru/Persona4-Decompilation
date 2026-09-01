/* object 396B / window 400B / normalized_diff 17.
 * Differing word offsets (relocations masked): 0x94, 0xA4,0xA8,0xAC,
 * 0xB4,0xB8,0xBC,0xC0,0xC4,0xC8,0xCC,0xD0,0xD8,0xDC,0xE0,0xE4;
 * the final normalized difference at 0x18C is the 4-byte object-size tail.
 * Prologue, allocation setup, memcpy calls, loop and epilogue all otherwise
 * match; residual is pointer-layout register scheduling.
 * Ruled out: scalar return/pointer temporaries (larger object/register drift),
 * u32-pointer and split-pointer-arithmetic forms, declaration reordering,
 * split accumulators, array-index stores, and available loop/propagation
 * pragma probes. Explicit loop byte indexing did close the three loop words
 * but did not move this remaining layout residual.
 */ 
u8 *func_0038f400(u8 *arg0)
{
    s32 temp_16;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    u8 *var_2;
    u8 *var_2_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;
    s32 var_16_2;
    s32 var_6;
    u32 var_5;
    u8 *var_4;
    u32 ret;
    u8 *temp_2;

    temp_16 = 0x14;
    temp_16 += *(s32 *)(arg0 + 0xC) * 4;
    temp_3 = temp_16 & 3;
    if (temp_3 != 0) {
        temp_16 += 4 - temp_3;
    }
    temp_16 += *(s32 *)(arg0 + 0x18);
    temp_3_2 = temp_16 & 3;
    if (temp_3_2 != 0) {
        temp_16 += 4 - temp_3_2;
    }
    temp_16 += *(s32 *)(arg0 + 8);
    func_0044ea90(D_0064F240, 0x36);
    ret = (u32)jtbl_008873E8[0](temp_16, 0x40000);
    *(s32 *)(ret + 8) = ret + 0x14;
    temp_2 = (u8 *)ret;
    var_2 = temp_2 + 0x14;
    var_2 += *(s32 *)(arg0 + 0xC) * 4;
    temp_4 = (s32)var_2 & 3;
    if (temp_4 != 0) {
        var_2 += 4 - temp_4;
    }
    *(s32 *)(temp_2 + 0xC) = (s32)var_2;
    var_2_2 = var_2 + *(s32 *)(arg0 + 0x18);
    temp_4_2 = (s32)var_2_2 & 3;
    if (temp_4_2 != 0) {
        var_2_2 += 4 - temp_4_2;
    }
    *(s32 *)(temp_2 + 0x10) = (s32)var_2_2;
    *(s32 *)(temp_2 + 4) = *(u16 *)(arg0 + 0xC);
    *(s32 *)temp_2 = *(u16 *)arg0;
    func_0043f810(*(s32 *)(temp_2 + 0xC),
                  arg0 + *(s32 *)(arg0 + 0x14),
                  *(s32 *)(arg0 + 0x18));
    func_0043f810(*(s32 *)(temp_2 + 0x10),
                  arg0 + *(s32 *)(arg0 + 4),
                  *(s32 *)(arg0 + 8));
    var_4 = arg0 + *(s32 *)(arg0 + 0x10);
    var_6 = *(s32 *)(temp_2 + 0xC);
    var_5 = 0;
    while (var_5 < (u32)*(s32 *)(arg0 + 0xC)) {
        temp_16 = var_5 * 4;
        *(s32 *)(*(s32 *)(temp_2 + 8) + temp_16) = var_6;
        var_6 += *var_4;
        var_5 += 1;
        var_4 += 1;
    }
    return (u8 *)temp_2;
}

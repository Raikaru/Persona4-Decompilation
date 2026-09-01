object_size=432 bytes; retail_window=432 bytes; normalized_diff=130; first_diffs=154,156,158,159,160,161,162,163,164,165,166,167,254,257,260,261; classification=stale archived near-match after declaration-environment change; current residual is a large prologue/pointer-evaluation and second-loop layout/register mismatch, not the archived nd 11 two-value exchange.
u8 *func_00482230(s32 *arg0)
{
    u8 *temp_2;
    s32 *var_18;
    s32 temp_17;
    s32 temp_16;
    s32 temp_4_2;
    s32 var_17;
    s32 var_7;
    u8 *temp_17_2;
    u8 *temp_2_3;
    s32 var_8;
    s32 var_9;
    u8 *scratch;
    extern void func_0043f810(void *dst, void *src, u32 size);

    {
        s32 offset;
        s32 *temp_2_2;
        offset = *(s32 *)arg0;
        temp_2_2 = (s32 *)((u8 *)arg0 + offset);
        temp_16 = *temp_2_2;
        var_18 = temp_2_2 + 1;
        temp_17 = offset + 0x1C;
        temp_17 += temp_16 * 4;
    }
    func_0044ea90(D_007132F0, 0x114);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0x18) = temp_2;
    temp_17_2 = temp_2 + 0x1C;
    func_0043f810(temp_17_2, arg0, *arg0);
    *(u8 **)(temp_2 + 0) = temp_17_2;
    *(u8 **)(temp_2 + 4) = temp_17_2 + 8;
    *(s32 *)(temp_2 + 0xC) = temp_16;
    temp_2_3 = *(u8 **)(temp_2 + 0);
    scratch = temp_2_3 + 8;
    *(u8 **)(temp_2 + 0x14) = scratch + *(s32 *)temp_2_3;

    var_17 = 0;
    while (var_17 < temp_16) {
        s32 temp_3;
        temp_3 = func_00481390((s32)((u8 *)arg0 + *var_18));
        *(s32 *)(*(u8 **)(temp_2 + 0x14) + (var_17 * 4)) = temp_3;
        var_18 += 1;
        var_17 += 1;
    }
    *(s32 *)(temp_2 + 0x10) = 1;
    *(s32 *)(temp_2 + 8) = 1;
    var_8 = *(s32 *)(*(u8 **)(temp_2 + 0) + 4);
    var_7 = 0;
    var_9 = 0x10000000;
    {
        u8 *temp_4;
        s32 var_10;
        var_10 = 2;
    while (var_7 < var_8) {
        temp_4 = *(u8 **)(temp_2 + 4) + (var_7 * 0x14);
        if ((*(s32 *)(temp_4 + 0x10) & var_9) != 0) {
            *(s32 *)(temp_2 + 8) = *(s32 *)(temp_4 + 0xC);
        } else {
            temp_4_2 = *(s32 *)(temp_4 + 8);
            if ((temp_4_2 & 0x40) != 0) {
                *(s32 *)(temp_2 + 8) = var_10;
            } else if ((temp_4_2 & 0x80) != 0) {
                *(s32 *)(temp_2 + 8) = var_10;
            }
        }
        var_7 += 1;
    }
    }
    return temp_2;
}

/* Fresh 2026-08-14 remeasurement: scoped verify produced obj 432B/window 432B/nd 130.
   Newly ruled out in this environment: file-scope static-const constant 2,
   swapped pointer/scratch declaration order, and explicit loaded-offset staging;
   these retained nd 129-130 or worse. Historical local/order/pragma/loop-shape
   exclusions remain in the archived classification above. */

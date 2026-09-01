/* object_size=256 window=256 normalized_diff=54; differing offsets=0x0008-0x00F0 (register allocation/base-register cascade); levers tried: raw C expansion, pointer declaration order, pointer-vs-s32 locals, pointer argument type, m2c pointer spelling, typed aggregate root, and distinct pointer locals assigned before first use. Retail first touches $a1/$a2/$a3 with writes (addiu/sltiu/sll), so no hidden arguments. Three pointer roots were assigned up front; declaration/lifetime reorder changed residual but no exact match. iGpffffb610 remains scalar GP-offset addressing matching retail relocation. */
s32 func_003a5180(u8 *arg0)
{
    u8 *temp_4;
    u8 *var_5;
    u8 *temp_2;
    s32 temp_7;
    s32 var_2;
    u32 var_3;

    temp_2 = (u8 *)(*((s32 *)(arg0 + iGpffffb610)));
    temp_4 = (u8 *)(*(u8 **)(temp_2 + 0x9C));
    var_5 = (u8 *)(temp_2 + 0x50);
    if (*(s32 *)(temp_4 + 0xD8) != 0) {
        if (*(s32 *)(temp_4 + 0xE4) < *(s32 *)(temp_4 + 0xE8)) {
            *(s32 *)(temp_4 + 0xE4) = *(s32 *)(temp_4 + 0xE4) + 1;
        } else {
            *(s32 *)(temp_4 + 0xE4) = 0;
        }
        if (*(s32 *)(temp_4 + 0xE8) != 0) {
            var_3 = 0;
            var_2 = 0;
            do {
                var_3 += 3;
                *(s32 *)(var_5 + 4) =
                    *(s32 *)(temp_4 + *(s32 *)(temp_4 + 0xE4) * 0x24 + var_2 + 0x140);
                *(s32 *)(var_5 + 0xC) =
                    *(s32 *)(temp_4 + *(s32 *)(temp_4 + 0xE4) * 0x24 + var_2 + 0x144);
                temp_7 =
                    *(s32 *)(temp_4 + *(s32 *)(temp_4 + 0xE4) * 0x24 + var_2 + 0x148);
                var_2 += 0xC;
                *(s32 *)(var_5 + 0x14) = temp_7;
                var_5 += 0x18;
            } while (var_3 < 9U);
        }
        return *(s32 *)(temp_4 + (*(s32 *)(temp_4 + 0xE4) << 5) + 0x10) == 0;
    }
    return 1;
}

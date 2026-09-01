/*
 * LaneMdlSE target 0047df40.
 * object_size=424B, window=432B, normalized_diff=212.
 * differing_offsets=0x3c,0x74,0x80,0x88,0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4,0xa8,0xb4,0xb8,0xbc,0xc0,0xc4,0xc8,0xcc,0xd0,0xd4,0xd8,0xdc,0xe0,0xe4,0xe8,0xec,0xf0,0xf4,0xf8,0xfc,0x100,0x104,0x108,0x10c,0x110,0x114,0x118,0x11c,0x120,0x124,0x128,0x12c,0x130,0x134,0x138,0x13c,0x140,0x144,0x148,0x14c,0x150,0x154,0x158,0x15c,0x160,0x164,0x168,0x16c,0x170,0x174,0x178,0x17c,0x180,0x184,0x188,0x18c,0x190,0x194,0x198,0x19c,0x1a0.
 * Residual is a non-closed probe; source was reverted to INCLUDE_ASM after archiving.
 * Corpora agree on the three-entry lookup, the func_00477c40 fallback, and the
 * minimum-counter replacement path.
 * Ruled out by scoped probes: s16/u16 parameter declarations; direct and typed
 * table indexing; explicit pointer/base temporaries; alternate index widths and
 * masks; reversed address arithmetic; D_00922C14/D_00922C16 alias bases;
 * opt_common_subs and opt_propagation toggles; while/for/bottom-tested loop
 * restructures; and integer-domain address casts.
 */

s32 func_0047df40(s32 arg0, s32 arg1)
{
    s32 var_18;
    s32 var_17;
    u16 temp_4;
    s32 temp_16;
    u32 temp_2_2;
    u32 temp_5;
    u32 var_6;
    u8 *temp_2;
    s32 index_offset;
    u32 key0;
    u32 key1;

    var_18 = -1;
    var_17 = 0;
    key0 = arg0 & 0xFFFF;
    key1 = arg1 & 0xFFFF;
    for (; (temp_16 = var_17 & 0xFFFF) < 3; var_17 = (var_17 + 1) & 0xFFFF) {
        temp_2 = (u8 *)D_00922C10 + (u16)var_17 * 8;
        temp_4 = *(u16 *)(temp_2 + 4);
        if ((key0 == temp_4) &&
            (key1 == *(u16 *)(temp_2 + 6))) {
            var_18 = temp_16;
            break;
        } else if (((s32)temp_4 < 0xC) &&
                   (func_00477c40(temp_4, *(u16 *)((u8 *)D_00922C14 - 4 + (u16)(var_17 + 0x10000) * 8 + 6), 0) == 0)) {
            var_18 = temp_16;
            break;
        }
    }
    var_6 = -1;
    if (var_18 == -1) {
        var_17 = 0;
        temp_2 = (u8 *)D_00922C10;
        for (; (temp_5 = var_17 & 0xFFFF) < 3; var_17 = (var_17 + 1) & 0xFFFF) {
            temp_2_2 = *(u32 *)(temp_2 + ((var_17 & 0xFFFF) * 8));
            if (var_6 >= temp_2_2) {
                var_6 = temp_2_2;
                var_18 = temp_5;
            }
        }
    }
    temp_16 = var_18 * 8;
    iGpffffbb40 = iGpffffbb40 + 1;
    *(s32 *)((s32)D_00922C10 + temp_16) = iGpffffbb40;
    *(u16 *)((s32)D_00922C14 + temp_16) = arg0;
    *(u16 *)((s32)D_00922C16 + temp_16) = arg1;
    return var_18 + 3;
}

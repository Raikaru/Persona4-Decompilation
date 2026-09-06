/*
 * Fresh b210 replay: object 396B/window 432B, 77 differing words.
 * The preceding archive replays at 424B/432B, 74 words; its inverse alias
 * and +0x10000 truncation expression were redundant code-generation steering.
 * This body uses the real base, an unsigned loop bound and a wrapping clock.
 * The historical source comment's 408B/432B floor is not reproduced here.
 *
 * CSE still removes the second first-loop address calculation. A private
 * inline slot accessor emits an identical diff and is not retained.
 * The unsigned bound changes slti to the retail sltiu; the clock correction
 * changes no instructions. The old INT_MAX + 1 fails UBSan.
 * Forty 32-bit raw-layout/UBSan cases pass: existing matches, first-free
 * precedence, live predicates, unsigned minima and last-equal ties, raw
 * key truncation, clock boundaries, and complete guarded record/clock images.
 * The host proof disables strict aliasing for the raw views, not overflow
 * checking. This remains a nonmatching source archive, not a promotion.
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
    for (; (temp_16 = var_17 & 0xFFFF) < 3U; var_17 = (var_17 + 1) & 0xFFFF) {
        temp_2 = (u8 *)D_00922C10 + (u16)var_17 * 8;
        temp_4 = *(u16 *)(temp_2 + 4);
        if ((key0 == temp_4) &&
            (key1 == *(u16 *)(temp_2 + 6))) {
            var_18 = temp_16;
            break;
        } else if (((s32)temp_4 < 0xC) &&
                   (func_00477c40(temp_4, *(u16 *)((u8 *)D_00922C10 + (u16)var_17 * 8 + 6), 0) == 0)) {
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
    iGpffffbb40 = (u32)iGpffffbb40 + 1;
    *(s32 *)((s32)D_00922C10 + temp_16) = iGpffffbb40;
    *(u16 *)((s32)D_00922C14 + temp_16) = arg0;
    *(u16 *)((s32)D_00922C16 + temp_16) = arg1;
    return var_18 + 3;
}

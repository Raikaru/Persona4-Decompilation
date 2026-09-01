// FUN_00198DD0
void func_00198dd0(u8 *arg0, s32 arg1)
{
    extern s32 func_00232710();
    extern s32 func_00479d10();
    extern s32 func_00479dd0();
    s64 var_18;
    u8 var_17;
    u16 var_16;
    s16 var_3_4;
    u8 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s64 temp_16;
    s64 temp_16_2;
    s64 temp_5;
    u8 temp_4;

    var_18 = 0;
    if (func_00242930(*(u8 **)(arg0 + 0xA64)) != 0) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp_16 = (s64)((func_001990d0(arg0, 0x12) & 0xFFFF) << 0x30) >> 0x30;
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp_16) == 0) {
                var_3 = 0;
            } else {
                var_3 = 1;
                if (func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp_16) == 1) {
                    var_3 = 0;
                }
            }
        } else {
            var_3 = 0;
        }
        if (var_3 != 0) {
            var_18 = 0x12;
        }
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0xFFFFF) != 0) {
        var_18 = 3;
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0x100000) != 0) {
        var_18 = 0xA;
    }
    if (func_00243e30(*(s32 *)(arg0 + 0xA64)) != 0) {
        var_18 = 0x18;
    }
    if (func_00232710(*(s32 *)(arg0 + 0xA64), 0x100) != 0) {
        var_18 = 0;
    }
    if ((func_002428f0(*(u8 **)(arg0 + 0xA64), 0) != 0) &&
        ((*(s32 *)(arg0 + 0x9C) & 0x20) != 0)) {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            temp_16_2 = (s64)((func_001990d0(arg0, 0x13) & 0xFFFF) << 0x30) >> 0x30;
            if (func_00479d10(*(u8 **)(arg0 + 0xA00), 0, temp_16_2) == 0) {
                var_3_2 = 0;
            } else {
                var_3_2 = 1;
                if (func_00479dd0(*(u8 **)(arg0 + 0xA00), 0, temp_16_2) == 1) {
                    var_3_2 = 0;
                }
            }
        } else {
            var_3_2 = 0;
        }
        if (var_3_2 != 0) {
            var_18 = 0x13;
        }
    }
    temp_5 = (s64)(var_18 << 0x30) >> 0x30;
    if (temp_5 != 0x13) {
        var_17 = 1;
        var_16 = *(u16 *)(arg0 + 0x9EE);
    } else {
        var_17 = 2;
        var_16 = 0;
    }
    temp_4 = *(u8 *)(arg0 + 0xA2);
    if ((temp_4 != 1) && (temp_4 != 0)) {
        var_3_3 = 0;
    } else {
        if ((*(s32 *)(arg0 + 0x98) & 2) != 0) {
            var_3_4 = *(s16 *)(arg0 + 0x9DA);
        } else {
            var_3_4 = 0;
        }
        var_3_3 = (s32)(*(s16 *)(arg0 + 0x9EC) == (s16)var_3_4);
    }
    if ((var_3_3 != 0) && (*(s16 *)(arg0 + 0x9EC) != (s16)temp_5)) {
        func_00198920(arg0, (s16)var_18, (u16)arg1, 1.0f, var_17);
    }
    *(s16 *)(arg0 + 0x9EC) = (s16)var_18;
    *(u16 *)(arg0 + 0x9EE) = var_16;
    *(s32 *)(arg0 + 0x9F0) = 0x3F800000;
    *(u8 *)(arg0 + 0x9F4) = var_17;
}
/*
 * Best measured candidate: object 764B, window 768B, 74 reloc-masked
 * differing words. Differing offsets (object bytes): 68, 96, 100, 132,
 * 136, 144, 148, 152, 156, 164, 168, 172, 176, 180, 184, 188, 192,
 * 196, 200, 340, 356, 372, 400, 404, 436, 440, 448, 452, 456, 460,
 * 468, 472, 476, 480, 484, 488, 492, 496, 500, 504, 508, 512, 516,
 * 520, 524, 528, 532, 536, 540, 544, 548, 552, 556, 560, 564, 568,
 * 572, 576, 580, 584, 644, 652, 656, 660, 664, 668, 672, 676, 680,
 * 684, 688, 692, 696.
 * Ruled out: direct predicates, explicit gotos, shared bool/index locals,
 * u8/s8/s16/s32/s64 predicate types, narrowed companion booleans, scoped
 * predicate/output locals, and constant-cache selection changes.
 */

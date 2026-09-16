/* FUN_002E4AC0 floor (v3, fndiff 295, obj 1292B/window 1344B, UNDER-52B).
 * Nested loops + 7 jtbl switches + 2 calls, void(s32,s32). Frame -240,
 * saves ra+s0-s8 (ALL MATCH frame/saves!). s128 spill slots (sq/lq).
 * Template: MATCHED neighbor 002e4960 (same switch case-groups +0x14/+0xA4).
 *
 * WINS:
 * - Counters are s16 (addiu + dsll32/dsra32 0x10 extend on ++).
 * - Args are s32 with (s64)(s8) extends for temp_30/22 (dsll32/dsra32 0x18).
 * - All 7 switches emit jtbl (sltiu-11/jr) via switch stmt.
 * - 312b60 takes 3 args (m2c 4th arg phantom — retail no stack arg).
 * - s128 locals (function-scope typedef) reproduce sq/lq slots.
 *
 * WALLS (types/allocation, stop):
 * - 64/32-bit systematic (dsll/daddu vs sll/addu on ptr/int chains);
 *   blanket s32-ify worsened (307), use-cast inert.
 * - Switch discriminant v0-vs-a2 + jtbl base t0-vs-a3 (7 sites);
 *   inlining discriminants inert.
 * - 9-save coloring (s0-s8 count right, identities rotated).
 * - Stop: three orthogonal levers inert; frame/saves/jtbl/calls all right.
 */
// FUN_002E4AC0 floor body (v3, fndiff 295, obj 1292B/window 1344B)
void func_002e4ac0(s32 arg0, s32 arg1) {
    typedef signed __int128 s128;
    s128 spE0;
    s128 spD0;
    s128 spC0;
    s128 spB0;
    s128 spA0;
    s64 var_4;
    s64 temp_30;
    s64 temp_22;
    s64 temp_23;
    s16 var_20;
    s16 var_19;
    s16 temp_18;
    s16 temp_16;
    s32 temp_7;
    s32 temp_17;
    s32 var_2;
    s32 var_2_3;
    s32 temp_2;
    u8 *temp_21;
    u8 *var_3;
    u8 *temp_5;
    u8 *var_4_2;
    u8 *var_7;
    u8 *var_2_2;
    u8 *var_4_3;
    u8 *var_5;
    u8 *var_6;
    u8 *var_7_2;

    var_4 = arg0;
    temp_21 = *(u8 **)(D_00882F70[0] + 0x38);
    var_3 = temp_21;
    temp_7 = *(s32 *)(temp_21 + 4);
    if ((temp_7 != 6) && (temp_7 != 10) && (temp_7 != 1)) {
        return;
    }
    var_20 = 0;
    temp_30 = (s64)(s8)var_4;
    temp_22 = (s64)(s8)arg1;
    temp_23 = temp_22 * 0x30;
loop_58:
    if (var_20 < *(s32 *)(var_3 + 8)) {
        temp_18 = var_20;
        *(s8 *)(temp_21 + temp_18 + 0x2E4) = 0;
        var_19 = 0;
        spE0 = (s128)(temp_18 * 12);
        spD0 = (s128)(temp_21 + temp_18 * 12);
        spC0 = (s128)&D_00882F70[temp_18 + 1];
        temp_17 = temp_18 * 0x30;
        spB0 = (s128)&D_00882F70[temp_18];
loop_56:
        var_3 = *(u8 **)(D_00882F70[0] + 0x38);
        temp_16 = var_19;
        if (temp_16 < *(s32 *)(var_3 + 8)) {
            temp_5 = (u8 *)((s32)spD0 + temp_16);
            *(s128 *)&spA0 = (s128)(s32)(temp_5 + 0x14);
            *(s8 *)(temp_5 + 0x14) = 0;
            if (temp_18 != var_19) {
                if (temp_30 == 0) {
                    u8 *temp_4 = *(u8 **)((u8 *)spC0 + 0x38);
                    switch (*(u32 *)(temp_4 + 4)) {
                    case 0: case 2: case 7: case 8:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0x14;
                        break;
                    case 1: case 5: case 6: case 10:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0xA4;
                        break;
                    default:
                        var_2 = temp_16 * 0x30;
                        var_4_2 = temp_4 + var_2 + 0x14;
                        break;
                    }
                    {
                        u8 *t32 = *(u8 **)(D_00882F70[0] + 0x38);
                        switch (*(u32 *)(t32 + 4)) {
                        case 0: case 2: case 7: case 8:
                            var_7 = t32 + temp_17 + 0x14;
                            break;
                        case 1: case 5: case 6: case 10:
                            var_7 = t32 + temp_17 + 0xA4;
                            break;
                        default:
                            var_7 = t32 + temp_17 + 0x14;
                            break;
                        }
                        {
                            switch (*(u32 *)(t32 + 4)) {
                            case 0: case 2: case 7: case 8:
                                var_2_2 = t32 + var_2 + 0x14;
                                break;
                            case 1: case 5: case 6: case 10:
                                var_2_2 = t32 + var_2 + 0xA4;
                                break;
                            default:
                                var_2_2 = t32 + var_2 + 0x14;
                                break;
                            }
                        }
                    }
                    var_4 = (s64)(s8)func_00312b60((s32)var_4_2, *(s16 *)(var_7 + 2), *(s16 *)(var_4_2 + 2));
                } else if (temp_30 == 1) {
                    if ((temp_22 == temp_18) || (temp_22 == temp_16)) {
                        var_4 = 0;
                    } else {
                        u8 *temp_42 = *(u8 **)((u8 *)spC0 + 0x38);
                        switch (*(u32 *)(temp_42 + 4)) {
                        case 0: case 2: case 7: case 8:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0x14;
                            break;
                        case 1: case 5: case 6: case 10:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0xA4;
                            break;
                        default:
                            var_2_3 = temp_16 * 0x30;
                            var_4_3 = temp_42 + var_2_3 + 0x14;
                            break;
                        }
                        {
                            u8 *t33 = *(u8 **)(D_00882F70[0] + 0x38);
                            switch (*(u32 *)(t33 + 4)) {
                            case 0: case 2: case 7: case 8:
                                var_5 = t33 + temp_23 + 0x14;
                                break;
                            case 1: case 5: case 6: case 10:
                                var_5 = t33 + temp_23 + 0xA4;
                                break;
                            default:
                                var_5 = t33 + temp_23 + 0x14;
                                break;
                            }
                            {
                                switch (*(u32 *)(t33 + 4)) {
                                case 0: case 2: case 7: case 8:
                                    var_6 = t33 + temp_17 + 0x14;
                                    break;
                                case 1: case 5: case 6: case 10:
                                    var_6 = t33 + temp_17 + 0xA4;
                                    break;
                                default:
                                    var_6 = t33 + temp_17 + 0x14;
                                    break;
                                }
                            }
                            {
                                switch (*(u32 *)(t33 + 4)) {
                                case 0: case 2: case 7: case 8:
                                    var_7_2 = t33 + var_2_3 + 0x14;
                                    break;
                                case 1: case 5: case 6: case 10:
                                    var_7_2 = t33 + var_2_3 + 0xA4;
                                    break;
                                default:
                                    var_7_2 = t33 + var_2_3 + 0x14;
                                    break;
                                }
                            }
                        }
                        var_4 = (s64)(s8)func_00312b90((u16 *)var_4_3, var_5, var_6, var_7_2);
                    }
                }
            }
            {
                u8 *t34 = (u8 *)((s32)spE0 + *(s32 *)(*(u8 **)((u8 *)spB0 + 4) + 0x38) + temp_16);
                *(s8 *)(t34 + 0x14) = 0;
                if (((s64)(s8)var_4) != 0) {
                    *(s8 *)(t34 + 0x14) = 1;
                    if (((s64)(s8)var_4) == 2) {
                        *(s8 *)(t34 + 0x14) = 2;
                    }
                }
            }
            {
                if (((s64)(s8)var_4) != 0) {
                    *(s32 *)&spA0 = 1;
                    if (((s64)(s8)var_4) == 2) {
                        *(s32 *)&spA0 = 2;
                    }
                }
            }
            var_19++;
            goto loop_56;
        }
        var_20++;
        goto loop_58;
    }
}

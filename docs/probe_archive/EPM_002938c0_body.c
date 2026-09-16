/* FUN_002938C0 floor (v2, fndiff 234, obj 1132B/window 1136B, UNDER-4B).
 * State-machine switch + calls, 35 calls exact, 1 save (s0). Frame -304
 * (u8[64] buffers match layout). Lint clean.
 * WINS: 9 decls + 2 symbols (D_007638B0, D_0063C990); 290710 s32-casts;
 *   2a9f50 o32 order with 5.0f; 2a66d0/25f3f0 floats-first (Wave-14);
 *   452560 K&R void-call; 440b68 (char*) casts; u8[64] buffers fix frame.
 * WALLS: scattered coloring (211 rows); s? rotation. Complete, near-parity floor.
 */
// FUN_002938C0 floor body (v2, fndiff 234, obj 1132B/window 1136B)
s32 func_002938c0(void) {
    s32 sp12C;
    u8 spE0[64];
    u8 spA0[64];
    u8 sp60[64];
    u8 sp20[64];
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    u16 temp_4;
    u8 **temp_2;
    u8 *temp_3;

    temp_2 = (u8 **)func_00452560();
    func_00290710(*(s32 *)(temp_2 + 0x0C), *(s32 *)(temp_2 + 0x10), (s32)spE0, (s32)spA0, (s32)sp60, (s32)sp20);
    if (*(s32 *)(temp_2 + 8) != 0) {
        temp_3 = *(temp_2 + 0);
        switch ((s32)temp_3) {
        case 7:
            break;
        case 0:
            *(s32 *)(temp_2 + 0x28) = 0;
            *(s32 *)(temp_2 + 0x2C) = 0;
            *(s32 *)(temp_2 + 0x30) = 0;
            *(s32 *)(temp_2 + 0x34) = 0;
            *(s32 *)(temp_2 + 0x38) = 0;
            *(s32 *)(temp_2 + 0x3C) = 0;
            func_00440b68((char *)D_007638B0, D_0063C970, 0x3F);
            *(s32 *)(temp_2 + 0x1C) = (s32)func_00454a60(sp20, 1);
            *(temp_2 + 0) = (u8 *)1;
            break;
        case 1:
            if (func_004553c0(*(u8 **)(temp_2 + 0x1C)) == 1) {
                temp_2_2 = func_00455f70(spE0, &sp12C);
                *(s32 *)(temp_2 + 0x34) = temp_2_2;
                if (temp_2_2 == 0) {
                    *(s32 *)(temp_2 + 0x28) = (s32)func_002904f0((s32 **)((s32)temp_2 + 0x34));
                }
                func_002852a0(4, sp12C);
                temp_2_3 = func_00455f70(spA0, &sp12C);
                *(s32 *)(temp_2 + 0x38) = temp_2_3;
                if (temp_2_3 == 0) {
                    *(s32 *)(temp_2 + 0x2C) = (s32)func_002905a0((s32 **)((s32)temp_2 + 0x38));
                }
                func_002852a0(5, sp12C);
                temp_2_4 = func_00455f70(sp60, &sp12C);
                *(s32 *)(temp_2 + 0x3C) = temp_2_4;
                if (temp_2_4 == 0) {
                    *(s32 *)(temp_2 + 0x30) = (s32)func_00290660((s32 **)((s32)temp_2 + 0x3C));
                }
                func_002852a0(6, sp12C);
                *(temp_2 + 0) = (u8 *)7;
            }
            break;
        }
    } else {
        temp_3 = *(temp_2 + 0);
        switch ((s32)temp_3) {
        case 0:
            func_00440b68((char *)D_007638B0, D_0063C990, 0x6C);
            *(s32 *)(temp_2 + 0x1C) = (s32)func_00454a60(spE0, 0);
            *(temp_2 + 0) = (u8 *)1;
            break;
        case 1:
            if (func_004553c0(*(u8 **)(temp_2 + 0x1C)) == 1) {
                *(s32 *)(temp_2 + 0x28) = 0;
                *(s32 *)(temp_2 + 0x34) = func_00455f70(spE0, &sp12C);
                func_002852a0(4, sp12C);
                *(temp_2 + 0) = (u8 *)2;
            }
            break;
        case 2:
            if (*(s32 *)(temp_2 + 4) == 1) {
                *(s32 *)(temp_2 + 0x2C) = (s32)func_002905a0((s32 **)((s32)temp_2 + 0x38));
                if (*(s32 *)(temp_2 + 0x38) == 0) {
                    func_0046d730(D_0063C970, 0x88);
                }
                *(temp_2 + 0) = (u8 *)4;
            } else {
                func_00440b68((char *)D_007638B0, D_0063C990, 0x8C);
                *(s32 *)(temp_2 + 0x20) = (s32)func_00454a60(spA0, 0);
                *(temp_2 + 0) = (u8 *)3;
            }
            break;
        case 3:
            if (func_004553c0(*(u8 **)(temp_2 + 0x20)) == 1) {
                *(temp_2 + 0) = (u8 *)4;
                *(s32 *)(temp_2 + 0x2C) = 0;
                *(s32 *)(temp_2 + 0x38) = func_00455f70(spA0, &sp12C);
                func_002852a0(5, sp12C);
            }
            break;
        case 4:
            if (*(s32 *)(temp_2 + 4) == 1) {
                *(s32 *)(temp_2 + 0x30) = (s32)func_00290660((s32 **)((s32)temp_2 + 0x3C));
                if (*(s32 *)(temp_2 + 0x3C) == 0) {
                    func_0046d730(D_0063C970, 0xA4);
                }
                *(temp_2 + 0) = (u8 *)6;
            } else {
                func_00440b68((char *)D_007638B0, D_0063C990, 0xA8);
                *(s32 *)(temp_2 + 0x24) = (s32)func_00454a60(sp60, 0);
                *(temp_2 + 0) = (u8 *)5;
            }
            break;
        case 5:
            if (func_004553c0(*(u8 **)(temp_2 + 0x24)) == 1) {
                *(temp_2 + 0) = (u8 *)6;
                *(s32 *)(temp_2 + 0x30) = 0;
                *(s32 *)(temp_2 + 0x3C) = func_00455f70(sp60, &sp12C);
                func_002852a0(6, sp12C);
            }
            break;
        case 6:
            *(u16 *)(temp_2 + 0x18) = 0;
            temp_4 = *(u16 *)(temp_2 + 0x18);
            if ((s32)temp_4 > 0) {
                func_00106390(temp_4, 1);
            }
            *(temp_2 + 0) = (u8 *)7;
            func_00440b68((char *)D_0063C990);
            break;
        }
    }
    return 0;
}

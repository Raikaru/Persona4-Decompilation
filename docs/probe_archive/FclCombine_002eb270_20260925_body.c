/* One 12-byte slot of the combine layout tables at D_00640760 / D_006407C0. */
typedef struct {
    f32 x;
    f32 y;
    s16 col;
    s16 row;
} FclCombineLayoutSlot;

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes on
void func_002eb270(u8 *arg0, s32 arg1) {
    extern u8 D_006407F0[];
    FclPackedPosition pos[70];
    FclCombineLayoutSlot *slot;
    u8 *p;
    s16 i1;
    s16 i2;
    s16 i3;
    s16 i4;
    s16 i5;
    s16 i6;
    s32 mode1;
    s8 mode2;
    s8 mode3;
    s8 mode4;
    s8 mode5;
    s16 jitter;
    u8 *q;
    s32 idx;

    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(p + 0xB5) % 2 == 0) {
        if (*(s8 *)(p + 0xB5) == 6) {
            for (i1 = 0, mode1 = (s8)arg1; i1 < 3; i1++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (i1 + 1);
                if (mode1 == 0) {
                    idx = (s16)(i1 + 0);
                    func_002b2970((u8 *)&pos[69], -200.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[68], slot->x, slot->y);
                    func_00317900(arg0, pos[69].bits, pos[68].bits, i1, idx * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + idx * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[67], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[66], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[67].bits, pos[66].bits, i1, i1 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407A8;
            if (mode1 == 0) {
                func_002b2970((u8 *)&pos[65], 700.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[64], slot->x, slot->y);
                func_00317900(arg0, pos[65].bits, pos[64].bits, 8, 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xFC) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xFE) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_002b2970((u8 *)&pos[63], slot->x, slot->y);
                func_002b2970((u8 *)&pos[62], 700.0f, slot->y + jitter);
                func_00317900(arg0, pos[63].bits, pos[62].bits, 8, 1, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_0064079C;
            if (mode1 == 0) {
                func_002b2970((u8 *)&pos[61], 700.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[60], slot->x, slot->y);
                func_00317900(arg0, pos[61].bits, pos[60].bits, 7, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_002b2970((u8 *)&pos[59], slot->x, slot->y);
                func_002b2970((u8 *)&pos[58], 700.0f, slot->y + jitter);
                func_00317900(arg0, pos[59].bits, pos[58].bits, 7, 3, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (mode1 == 0) {
                func_002b2970((u8 *)&pos[57], 700.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[56], slot->x, slot->y);
                func_00317900(arg0, pos[57].bits, pos[56].bits, 6, 0xA, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_002b2970((u8 *)&pos[55], slot->x, slot->y);
                func_002b2970((u8 *)&pos[54], 700.0f, slot->y + jitter);
                func_00317900(arg0, pos[55].bits, pos[54].bits, 6, 5, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        } else if (*(s8 *)(p + 0xB5) == 8) {
            mode2 = arg1;
            for (i2 = 0; i2 < 4; i2++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + i2;
                if (mode2 == 0) {
                    func_002b2970((u8 *)&pos[53], -200.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[52], slot->x, slot->y);
                    func_00317900(arg0, pos[53].bits, pos[52].bits, i2, i2 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + i2 * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[51], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[50], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[51].bits, pos[50].bits, i2, i2 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            for (i3 = 0; i3 < 3; i3++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (7 - i3);
                if (mode2 == 0) {
                    func_002b2970((u8 *)&pos[49], 700.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[48], slot->x, slot->y);
                    func_00317900(arg0, pos[49].bits, pos[48].bits, 8 - i3, i3 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + (7 - i3) * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[47], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[46], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[47].bits, pos[46].bits, 8 - i3, i3 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (mode2 == 0) {
                func_002b2970((u8 *)&pos[45], 700.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[44], slot->x, slot->y);
                func_00317900(arg0, pos[45].bits, pos[44].bits, 4, 0xE, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_002b2970((u8 *)&pos[43], slot->x, slot->y);
                func_002b2970((u8 *)&pos[42], 700.0f, slot->y + jitter);
                func_00317900(arg0, pos[43].bits, pos[42].bits, 4, 7, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        }
    } else {
        switch (*(s8 *)(p + 0xB5)) {
        case 5:
            mode3 = arg1;
            for (i4 = 0; i4 < 2; i4++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (i4 + 2);
                if (mode3 == 0) {
                    func_002b2970((u8 *)&pos[41], -200.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[40], slot->x, slot->y);
                    func_00317900(arg0, pos[41].bits, pos[40].bits, i4, i4 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + i4 * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[39], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[38], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[39].bits, pos[38].bits, i4, i4 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (6 - i4);
                if (mode3 == 0) {
                    func_002b2970((u8 *)&pos[37], 700.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[36], slot->x, slot->y);
                    func_00317900(arg0, pos[37].bits, pos[36].bits, 8 - i4, i4 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + (4 - i4) * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[35], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[34], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[35].bits, pos[34].bits, 8 - i4, i4 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode3 == 0) {
                func_002b2970((u8 *)&pos[33], -200.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[32], slot->x, slot->y);
                func_00317900(arg0, pos[33].bits, pos[32].bits, 6, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xDE) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xE0) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_002b2970((u8 *)&pos[31], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[30], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[31].bits, pos[30].bits, 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_002b2970((u8 *)&pos[29], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[28], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[29].bits, pos[28].bits, 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            break;
        case 7:
            mode4 = arg1;
            for (i5 = 0; i5 < 3; i5++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (i5 + 1);
                if (mode4 == 0) {
                    func_002b2970((u8 *)&pos[27], -200.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[26], slot->x, slot->y);
                    func_00317900(arg0, pos[27].bits, pos[26].bits, i5, i5 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + i5 * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[25], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[24], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[25].bits, pos[24].bits, i5, i5 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (7 - i5);
                if (mode4 == 0) {
                    func_002b2970((u8 *)&pos[23], 700.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[22], slot->x, slot->y);
                    func_00317900(arg0, pos[23].bits, pos[22].bits, 8 - i5, i5 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + (6 - i5) * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[21], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[20], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[21].bits, pos[20].bits, 8 - i5, i5 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode4 == 0) {
                func_002b2970((u8 *)&pos[19], -200.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[18], slot->x, slot->y);
                func_00317900(arg0, pos[19].bits, pos[18].bits, 3, 0xC, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_002b2970((u8 *)&pos[17], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[16], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[17].bits, pos[16].bits, 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_002b2970((u8 *)&pos[15], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[14], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[15].bits, pos[14].bits, 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            break;
        case 9:
            mode5 = arg1;
            for (i6 = 0; i6 < 4; i6++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + i6;
                if (mode5 == 0) {
                    func_002b2970((u8 *)&pos[13], -200.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[12], slot->x, slot->y);
                    func_00317900(arg0, pos[13].bits, pos[12].bits, i6, i6 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + i6 * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[11], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[10], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[11].bits, pos[10].bits, i6, i6 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (8 - i6);
                if (mode5 == 0) {
                    func_002b2970((u8 *)&pos[9], 700.0f, 100.0f + slot->y);
                    func_002b2970((u8 *)&pos[8], slot->x, slot->y);
                    func_00317900(arg0, pos[9].bits, pos[8].bits, 8 - i6, i6 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    q = p + (8 - i6) * 10;
                    *(s16 *)(q + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(q + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_002b2970((u8 *)&pos[7], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[6], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[7].bits, pos[6].bits, 8 - i6, i6 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode5 == 0) {
                func_002b2970((u8 *)&pos[5], -200.0f, 100.0f + slot->y);
                func_002b2970((u8 *)&pos[4], slot->x, slot->y);
                func_00317900(arg0, pos[5].bits, pos[4].bits, 4, 0x10, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_002b2970((u8 *)&pos[3], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[2], -300.0f, slot->y + jitter);
                    func_00317900(arg0, pos[3].bits, pos[2].bits, 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_002b2970((u8 *)&pos[1], slot->x, slot->y);
                    func_002b2970((u8 *)&pos[0], 700.0f, slot->y + jitter);
                    func_00317900(arg0, pos[1].bits, pos[0].bits, 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            break;
        }
    }
    if ((s8)arg1 == 1) {
        func_002b6150(0x216)[0x73] = 0;
        func_002b6150(0x216);
        func_002b6150(0x217)[0x73] = 0;
        func_002b6150(0x217);
        func_002b6150(0x218)[0x73] = 0;
        func_002b6150(0x218);
        func_002b6150(0x219)[0x73] = 0;
        func_002b6150(0x219);
        func_002b6150(0x21A)[0x73] = 0;
        func_002b6150(0x21A);
        func_002b6150(0x21B)[0x73] = 0;
        func_002b6150(0x21B);
    }
}
#pragma pop

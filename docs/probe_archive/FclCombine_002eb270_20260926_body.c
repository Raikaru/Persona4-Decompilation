/* func_002eb270 draft, 2026-09-26: 48 differing words (fndiff), object size
   equal to retail.  Every layout except 0xB5 == 8 matches; there the mode
   and the slot pointer take $s1/$s0 where retail has $s0/$s1.  The
   contracts it needs have landed:
       FclVec2 func_002b2970(f32 x, f32 y);
       void func_00317900(u8 *, FclVec2, FclVec2, s8, s16, s16, s16);
   The same body is the NON_MATCHING draft in y_fclCombine.c.  See
   FclCombine_002eb270_20260925.md. */
/* One 12-byte slot of the combine layout tables at D_00640760 / D_006407C0. */
typedef struct {
    f32 x;
    f32 y;
    s16 col;
    s16 row;
} FclCombineLayoutSlot;

void func_002eb270(u8 *arg0, s32 arg1) {
    extern u8 D_006407F0[];
    FclCombineLayoutSlot *slot;
    u8 *p;
    s16 i1;
    s16 i2;
    s16 i3;
    s16 i4;
    s16 i5;
    s16 i6;
    s32 mode1;
    s32 mode2;
    s32 mode3;
    s32 mode4;
    s32 mode5;
    s16 jitter;

    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(p + 0xB5) % 2 == 0) {
        if (*(s8 *)(p + 0xB5) == 6) {
            for (i1 = 0, mode1 = (s8)arg1; i1 < 3; i1++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (i1 + 1);
                if (mode1 == 0) {
                    func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 i1, i1 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + i1 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + i1 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 i1, i1 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407A8;
            if (mode1 == 0) {
                func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             8, 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xFC) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xFE) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             8, 1, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_0064079C;
            if (mode1 == 0) {
                func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             7, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             7, 3, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (mode1 == 0) {
                func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             6, 0xA, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             6, 5, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        } else if (*(s8 *)(p + 0xB5) == 8) {
            for (i2 = 0, mode2 = (s8)arg1; i2 < 4; i2++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + i2;
                if (mode2 == 0) {
                    func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 i2, i2 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + i2 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + i2 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 i2, i2 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            for (i3 = 0; i3 < 3; i3++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (7 - i3);
                if (mode2 == 0) {
                    func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - i3, i3 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + (7 - i3) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + (7 - i3) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - i3, i3 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (mode2 == 0) {
                func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             4, 0xE, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             4, 7, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        }
    } else {
        if (*(s8 *)(p + 0xB5) == 5) {
            for (i4 = 0, mode3 = (s8)arg1; i4 < 2; i4++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (i4 + 2);
                if (mode3 == 0) {
                    func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 i4, i4 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + i4 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + i4 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 i4, i4 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (6 - i4);
                if (mode3 == 0) {
                    func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - i4, i4 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + (4 - i4) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + (4 - i4) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - i4, i4 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode3 == 0) {
                func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             6, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xDE) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xE0) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (*(s8 *)(p + 0xB5) == 7) {
            for (i5 = 0, mode4 = (s8)arg1; i5 < 3; i5++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (i5 + 1);
                if (mode4 == 0) {
                    func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 i5, i5 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + i5 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + i5 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 i5, i5 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (7 - i5);
                if (mode4 == 0) {
                    func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - i5, i5 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + (6 - i5) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + (6 - i5) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - i5, i5 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode4 == 0) {
                func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             3, 0xC, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (*(s8 *)(p + 0xB5) == 9) {
            for (i6 = 0, mode5 = (s8)arg1; i6 < 4; i6++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + i6;
                if (mode5 == 0) {
                    func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 i6, i6 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + i6 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + i6 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 i6, i6 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (8 - i6);
                if (mode5 == 0) {
                    func_00317900(arg0, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - i6, i6 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(p + (8 - i6) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(p + (8 - i6) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - i6, i6 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (mode5 == 0) {
                func_00317900(arg0, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             4, 0x10, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(p + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(p + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(arg0, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
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

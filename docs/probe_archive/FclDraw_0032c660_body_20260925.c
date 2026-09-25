/* func_0032c660 best draft (2026-09-25): 168 differing words from the fastprobe
   scorer. Opcodes and the whole stack frame match retail (opcode distance 0,
   plus one pad nop), so every remaining word is a callee-saved register
   rename. See FclDraw_0032c660_20260925.md.
   Probe it by replacing the NON_MATCHING arm under // FUN_0032C660. */
void func_0032c660(u8 *arg0, s32 arg1, FclVec2 arg2, FclVec2 arg3, s32 arg4, s32 arg5) {
    extern FclVec2 func_002b2970(f32, f32);
    extern void func_002b6c30(s16, FclVec2, f32, s32);
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s32);
    FclByte4 c34C;
    FclByte4 c348;
    FclByte4 c344;
    FclByte4 c340;
    FclByte4 c33C;
    FclByte4 c338;
    FclByte4 c334;
    FclByte4 c330;
    FclByte4 c32C;
    FclByte4 c328;
    FclByte4 c324;
    FclByte4 c320;
    u8 *t = *(u8 **)(arg0 + 0x38);
    FclVec2 pos = func_002b2970(57.0f, 72.0f);
    FclVec2 cur0;
    FclVec2 row[11];
    FclBoundsPacket spD0;
    FclBoundsPacket spC0;
    s16 order0;
    s16 order1;
    f32 span;
    s16 id0;
    s16 id1;
    s16 id2;
    s16 id3;
    s16 id4;
    s16 id5;
    s16 id6;
    s16 id7;
    s16 id8;
    s16 id9;
    s16 id10;
    s16 id11;
    u8 *h;
    u8 **slot;

    span = 600.0f;
    order0 = 0x66;
    if ((s8)arg1 == 1) {
        order0 = 0x70;
    }
    id0 = 0x1CA;
    if ((s8)arg1 == 1) {
        id0 = 0x2E4;
    }
    func_002b7750(id0, 0x1CA);
    cur0 = *(FclVec2 *)(func_002b6150(id0) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id0) + 0x10) = 0;
        func_002b6c30(id0, pos, 112.0f, order0 + 2);
        c34C = func_002b2a60(0x38, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(id0) + 0x85) = c34C;
        func_002b6d60(id0);
        func_002b69f0(id0, func_002b2970(pos.x + span, pos.y), arg2, 0, 0xA, 0);
    } else {
        func_002b68d0(id0, 0, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id0, cur0, pos, 0, 4, 0);
        } else {
            func_002b69f0(id0, cur0, arg3, 0, 4, 0);
        }
    }
    id1 = 0x1CB;
    if ((s8)arg1 == 1) {
        id1 = 0x2E5;
    }
    func_002b7750(id1, 0x1CB);
    row[0] = *(FclVec2 *)(func_002b6150(id1) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id1) + 0x10) = 0;
        func_002b6c30(id1, func_002b2970(387 + pos.x, pos.y), 113.0f, order0 + 2);
        c348 = func_002b2a60(0x38, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(id1) + 0x85) = c348;
        func_002b6d60(id1);
        func_002b69f0(id1, func_002b2970(387 + pos.x + span, pos.y), func_002b2970(387 + arg2.x, arg2.y), 0, 0xA, 0);
    } else {
        func_002b68d0(id1, 0, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id1, row[0], func_002b2970(387 + pos.x, pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id1, row[0], func_002b2970(387 + arg3.x, arg3.y), 0, 4, 0);
        }
    }
    id2 = 0x1CC;
    if ((s8)arg1 == 1) {
        id2 = 0x2E6;
    }
    func_002b7750(id2, 0x1CC);
    row[1] = *(FclVec2 *)(func_002b6150(id2) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id2) + 0x10) = 0;
        func_002b6c30(id2, func_002b2970(70.0f + pos.x, 6.0f + pos.y), 108.0f, 0x56);
        c344 = func_002b2a60(0x26, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(id2) + 0x85) = c344;
        func_002b6d60(id2);
        func_002b69f0(id2, func_002b2970(70.0f + pos.x + span, 6.0f + pos.y), func_002b2970(70.0f + arg2.x, 6.0f + arg2.y), 0, 0xA, 0);
    } else {
        func_002b68d0(id2, 0, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id2, row[1], func_002b2970(70.0f + pos.x, 6.0f + pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id2, row[1], func_002b2970(70.0f + arg3.x, 6.0f + arg3.y), 0, 4, 0);
        }
    }
    id3 = 0x1CD;
    if ((s8)arg1 == 1) {
        id3 = 0x2E7;
    }
    func_002b7750(id3, 0x1CD);
    row[2] = *(FclVec2 *)(func_002b6150(id3) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id3) + 0x10) = 0;
        func_002b6c30(id3, func_002b2970(382.0f + pos.x, 6.0f + pos.y), 109.0f, 0x56);
        c340 = func_002b2a60(0x26, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(id3) + 0x85) = c340;
        func_002b6d60(id3);
        func_002b69f0(id3, func_002b2970(382.0f + pos.x + span, 6.0f + pos.y), func_002b2970(382.0f + arg2.x, 6.0f + arg2.y), 0, 0xA, 0);
    } else {
        func_002b68d0(id3, 0, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id3, row[2], func_002b2970(382.0f + pos.x, 6.0f + pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id3, row[2], func_002b2970(382.0f + arg3.x, 6.0f + arg3.y), 0, 4, 0);
        }
    }
    id4 = 0x1D6;
    if ((s8)arg1 == 1) {
        id4 = 0x2E8;
    }
    func_002b7750(id4, 0x1D6);
    row[3] = *(FclVec2 *)(func_002b6150(id4) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id4) + 0x10) = 0;
        func_002b6c30(id4, func_002b2970(8.0f + pos.x, 8.0f + pos.y), 107.0f, order0 + 4);
        c33C = func_002b2a60(0x95, 0x7C, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(id4) + 0x85) = c33C;
        func_002b6d60(id4);
        func_002b69f0(id4, func_002b2970(8.0f + pos.x + span, 6.0f + pos.y), func_002b2970(8.0f + arg2.x, 8.0f + arg2.y), 0, 0xA, 0);
        if ((s8)arg1 == 1) {
            *(u8 *)(func_002b6150(id4) + 0x6E) = 0;
        }
    } else {
        func_002b68d0(id4, 0, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id4, row[3], func_002b2970(8.0f + pos.x, 8.0f + pos.y), 0, 4, 0);
            func_002b6a70(id4, 0, 0xFF, 0, 4, 0);
        } else {
            func_002b69f0(id4, row[3], func_002b2970(8.0f + arg3.x, 8.0f + arg3.y), 0, 4, 0);
            func_002b6a70(id4, 0xFF, 0, 0, 4, 0);
        }
    }
    id5 = 0x2E3;
    if ((s8)arg1 == 1) {
        id5 = 0x2E9;
    }
    func_002b7750(id5, 0x80);
    row[4] = *(FclVec2 *)(func_002b6150(id5) + 0x38);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id5) + 0x10) = 0;
        func_002b6c30(id5, func_002b2970(pos.x - 120.0f + span, pos.y - 40.0f), 111.0f, order0 + 3);
        c338 = func_002b2a60(0x18, 2, 0x67, 0xFF);
        *(FclByte4 *)(func_002b6150(id5) + 0x85) = c338;
        func_002b69f0(id5, func_002b2970(pos.x - 120.0f + span, pos.y - 40.0f), func_002b2970(arg2.x - 120.0f, arg2.y - 40.0f), 0, 0xA, 0);
        func_002b6d60(id5);
        func_002b68d0(id5, 0xE, 0);
    } else {
        func_002b68d0(id5, 0, 0);
        func_002b68d0(id5, 0xE, 0);
        if ((s8)arg5 == 0) {
            func_002b69f0(id5, row[4], func_002b2970(pos.x - 120.0f, pos.y - 40.0f), 0, 4, 0);
        } else {
            func_002b69f0(id5, row[4], func_002b2970(arg3.x - 120.0f, arg3.y - 40.0f), 0, 4, 0);
        }
    }
    if ((s8)arg4 == 1) {
        h = func_0046d200(func_00331560(), 0x80);
        slot = (u8 **)(t + 0x258) + (s8)(u32)arg1 * 2;
        *(FclVec2 *)func_002b81f0(*slot) = func_002b2970(arg2.x - 120.0f, arg2.y - 40.0f);
        func_002b29e0((u8 *)&spD0, 250.0f, 250.0f);
        ((FclBoundsPacket *)(func_002b81f0(*slot) + 8))->representation = spD0.representation;
        *(s32 *)(func_002b81f0(*slot) + 0x120) = order0;
        *(f32 *)(func_002b81f0(*slot) + 0x18) = 110.0f;
        *(u8 *)(func_002b81f0(*slot) + 0x124) = 0;
        func_0046d280(h);
    }
    pos = func_002b2970(pos.x, 99.0f + pos.y);
    order1 = 0x6B;
    if ((s8)arg1 == 1) {
        order1 = 0x75;
    }
    id6 = 0x1CE;
    if ((s8)arg1 == 1) {
        id6 = 0x2EA;
    }
    func_002b7750(id6, 0x1CE);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id6) + 0x10) = 0;
        func_002b6c30(id6, func_002b2970(pos.x + span, pos.y), 112.0f, order1 + 2);
        c334 = func_002b2a60(0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(id6) + 0x85) = c334;
        func_002b69f0(id6, func_002b2970(pos.x + span, pos.y), func_002b2970(arg2.x, 99.0f + arg2.y), 0, 0xA, 0);
        func_002b6d60(id6);
    } else {
        func_002b68d0(id6, 0, 0);
        row[5] = *(FclVec2 *)(func_002b6150(id6) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id6, row[5], func_002b2970(pos.x, pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id6, row[5], func_002b2970(arg3.x, 99.0f + arg3.y), 0, 4, 0);
        }
    }
    id7 = 0x1CF;
    if ((s8)arg1 == 1) {
        id7 = 0x2EB;
    }
    func_002b7750(id7, 0x1CF);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id7) + 0x10) = 0;
        func_002b6c30(id7, func_002b2970(387 + pos.x + span, pos.y), 113.0f, order1 + 2);
        c330 = func_002b2a60(0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(id7) + 0x85) = c330;
        func_002b69f0(id7, func_002b2970(387 + pos.x + span, pos.y), func_002b2970(387 + arg2.x, 99.0f + arg2.y), 0, 0xA, 0);
        func_002b6d60(id7);
    } else {
        func_002b68d0(id7, 0, 0);
        row[6] = *(FclVec2 *)(func_002b6150(id7) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id7, row[6], func_002b2970(387 + pos.x, pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id7, row[6], func_002b2970(387 + arg3.x, 99.0f + arg3.y), 0, 4, 0);
        }
    }
    id8 = 0x1D0;
    if ((s8)arg1 == 1) {
        id8 = 0x2EC;
    }
    func_002b7750(id8, 0x1D0);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id8) + 0x10) = 0;
        func_002b6c30(id8, func_002b2970(70.0f + pos.x + span, 6.0f + pos.y), 108.0f, 0x56);
        c32C = func_002b2a60(0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(id8) + 0x85) = c32C;
        func_002b69f0(id8, func_002b2970(70.0f + pos.x + span, 6.0f + pos.y), func_002b2970(70.0f + arg2.x, 99.0f + (6.0f + arg2.y)), 0, 0xA, 0);
        func_002b6d60(id8);
    } else {
        func_002b68d0(id8, 0, 0);
        row[7] = *(FclVec2 *)(func_002b6150(id8) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id8, row[7], func_002b2970(70.0f + pos.x, 6.0f + pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id8, row[7], func_002b2970(70.0f + arg3.x, 99.0f + (6.0f + arg3.y)), 0, 4, 0);
        }
    }
    id9 = 0x1D1;
    if ((s8)arg1 == 1) {
        id9 = 0x2ED;
    }
    func_002b7750(id9, 0x1D1);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id9) + 0x10) = 0;
        func_002b6c30(id9, func_002b2970(382.0f + pos.x + span, 6.0f + pos.y), 109.0f, 0x56);
        c328 = func_002b2a60(0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(id9) + 0x85) = c328;
        func_002b69f0(id9, func_002b2970(382.0f + pos.x + span, 6.0f + pos.y), func_002b2970(382.0f + arg2.x, 99.0f + (6.0f + arg2.y)), 0, 0xA, 0);
        func_002b6d60(id9);
    } else {
        func_002b68d0(id9, 0, 0);
        row[8] = *(FclVec2 *)(func_002b6150(id9) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id9, row[8], func_002b2970(382.0f + pos.x, 6.0f + pos.y), 0, 4, 0);
        } else {
            func_002b69f0(id9, row[8], func_002b2970(382.0f + arg3.x, 99.0f + (6.0f + arg3.y)), 0, 4, 0);
        }
    }
    id10 = 0x1D7;
    if ((s8)arg1 == 1) {
        id10 = 0x2EE;
    }
    func_002b7750(id10, 0x1D7);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id10) + 0x10) = 0;
        func_002b6c30(id10, func_002b2970(8.0f + pos.x + span, 8.0f + pos.y), 107.0f, order1 + 4);
        c324 = func_002b2a60(0x95, 0x7C, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(id10) + 0x85) = c324;
        func_002b69f0(id10, func_002b2970(8.0f + pos.x + span, 8.0f + pos.y), func_002b2970(8.0f + arg2.x, 99.0f + (8.0f + arg2.y)), 0, 0xA, 0);
        func_002b6d60(id10);
        if ((s8)arg1 == 1) {
            *(u8 *)(func_002b6150(id10) + 0x6E) = 0;
        }
    } else {
        func_002b68d0(id10, 0, 0);
        row[9] = *(FclVec2 *)(func_002b6150(id10) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id10, row[9], func_002b2970(8.0f + pos.x, 8.0f + pos.y), 0, 4, 0);
            func_002b6a70(id10, 0, 0xFF, 0, 4, 0);
        } else {
            func_002b69f0(id10, row[9], func_002b2970(8.0f + arg3.x, 99.0f + (8.0f + arg3.y)), 0, 4, 0);
            func_002b6a70(id10, 0xFF, 0, 0, 4, 0);
        }
    }
    id11 = 0x2E2;
    if ((s8)arg1 == 1) {
        id11 = 0x2EF;
    }
    func_002b7750(id11, 0x80);
    if ((s8)arg4 == 1) {
        *(s16 *)(func_002b6150(id11) + 0x10) = 0;
        func_002b6c30(id11, func_002b2970(pos.x - 120.0f + span, pos.y - 27.0f), 111.0f, order1 + 3);
        c320 = func_002b2a60(0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(id11) + 0x85) = c320;
        func_002b69f0(id11, func_002b2970(pos.x - 120.0f + span, pos.y - 27.0f), func_002b2970(arg2.x - 120.0f, 99.0f + (arg2.y - 27.0f)), 0, 0xA, 0);
        func_002b6d60(id11);
        func_002b68d0(id11, 0xE, 0);
    } else {
        func_002b68d0(id11, 0, 0);
        func_002b68d0(id11, 0xE, 0);
        row[10] = *(FclVec2 *)(func_002b6150(id11) + 0x38);
        if ((s8)arg5 == 0) {
            func_002b69f0(id11, row[10], func_002b2970(pos.x - 120.0f, pos.y - 27.0f), 0, 4, 0);
        } else {
            func_002b69f0(id11, row[10], func_002b2970(arg3.x - 120.0f, 99.0f + (arg3.y - 27.0f)), 0, 4, 0);
        }
    }
    if ((s8)arg4 == 1) {
        h = func_0046d200(func_00331560(), 0x80);
        slot = (u8 **)(t + 0x25C) + (s8)(u32)arg1 * 2;
        *(FclVec2 *)func_002b81f0(*slot) = func_002b2970(arg2.x - 120.0f, 99.0f + (arg2.y - 27.0f));
        func_002b29e0((u8 *)&spC0, 250.0f, 250.0f);
        ((FclBoundsPacket *)(func_002b81f0(*slot) + 8))->representation = spC0.representation;
        *(s32 *)(func_002b81f0(*slot) + 0x120) = order1;
        *(f32 *)(func_002b81f0(*slot) + 0x18) = 110.0f;
        *(u8 *)(func_002b81f0(*slot) + 0x124) = 0;
        func_0046d280(h);
    }
}

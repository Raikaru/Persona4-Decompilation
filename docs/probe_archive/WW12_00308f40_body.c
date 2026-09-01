void func_00308f40(void) {
    s64 raw;
    s64 n0;
    s64 n1;
    s64 n2;
    s64 n3;
    s64 i;
    s64 j;
    s64 k;
    s64 total;
    s64 packed;
    u16 *p;

    raw = (s32)func_001102d0() & 0xFFFF;
    n0 = (s8)((raw & 0xF));
    n1 = (s8)(((raw >> 4) & 0xF));
    n2 = (s8)(((raw >> 8) & 0xF));
    n3 = (s8)(((raw >> 0xC) & 0xF));
    total = 0;
    i = 0;
    while (i < (func_0010b6f0() & 0xFFFF)) {
        if ((func_00109470((u16)i) & 4) != 0) {
            if ((func_00109470((u16)i) & 0x80) != 0) {
                *(u16 *)func_0010ace0((s16)i) ^= 4;
                *(u16 *)func_0010ace0((s16)i) ^= 0x20;
                *(u16 *)func_0010ace0((s16)i) ^= 0x40;
                *(u16 *)func_0010ace0((s16)i) ^= 0x80;
            } else if ((func_00109470((u16)i) & 0x40) != 0) {
                *(u16 *)func_0010ace0((s16)i) |= 0x80;
            } else if ((func_00109470((u16)i) & 0x20) != 0) {
                *(u16 *)func_0010ace0((s16)i) |= 0x40;
            } else {
                *(u16 *)func_0010ace0((s16)i) |= 0x20;
            }
        }
        i++;
    }
    if ((func_00106330(0x1307) == 0) && (func_00106330(0x1306) != 0)) {
        n3 = (s8)((raw >> 0xC) & 0xF);
        n2 = (s8)((raw >> 8) & 0xF);
        n1 = (s8)((raw >> 4) & 0xF);
        n0 = (s8)(raw & 0xF);
        n3 = (s8)func_002b2cb0((s32)n3, 1, 6, 0, 1);
        packed = ((n3 & 0xF) << 0xC) | ((n2 & 0xF) << 8) |
                 ((n1 & 0xF) << 4) | (n0 & 0xF);
        j = 0;
        total = 0;
        while (j < 5) {
            total += (s8)*((u8 *)func_001102e0() + j + 0x26);
            j++;
        }
        if ((n3 >= n2) || (n3 == 6)) {
            p = func_001102e0();
            func_0010cad0(p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), (u16)packed);
            func_00106390(0x1307, 1);
            return;
        }
        if (total >= 0x1E) {
            p = func_001102e0();
            func_0010cad0(p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), (u16)packed);
            func_00106390(0x1307, 1);
            return;
        }
        func_001102c0((s16)packed);
        switch ((s8)n2) {
        case 0:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1C) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x26) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x27) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 1:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x28) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x28),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1F) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x29) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x29),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 2:
            if (*(u8 *)((u8 *)func_001102e0() + 0x20) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x2A) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x2A),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1C) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x26) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 3:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x27) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x28) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x28),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            break;
        }
    }
}

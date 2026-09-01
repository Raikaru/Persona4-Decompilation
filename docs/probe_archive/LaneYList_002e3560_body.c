/* Closest clean-C probe for func_002e3560; object 2780B over a 2864B window,
   normalized diff 639. Rejected: frame 0x3090 (retail 0x3070) and saved-register
   allocation remain different. */
void func_002e3560(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s64 arg4) {
    s32 reorder[0x600];
    s32 sortbuf[0x600];
    u8 *p;
    u8 *entry;
    s32 flags_a;
    s32 flags_b;
    s32 ok;
    s32 value;
    s16 type;
    s16 count;
    s16 i;
    s16 j;
    s16 k;
    s16 n;
    s16 mode;
    s16 out_count;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 4) = arg1;
    *(s32 *)(p + 8) = arg2;
    *(s8 *)(p + 1) = arg3;
    *(s16 *)(p + 2) = 0;
    type = *(s8 *)(p + 1);
    count = 0;
    switch (type) {
    case 1:
        for (i = 0; i < 0x600; i++) {
            entry = p + ((s32)i * 4);
            *(s16 *)(entry + 0x10) = 0;
            *(s16 *)(entry + 0x0E) = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                p = *(u8 **)(arg0 + 0x38);
                flags_a = *(s32 *)(p + 4);
                flags_b = *(s32 *)(p + 8);
                if ((flags_a == 0) && (flags_b == 0)) {
                    ok = 1;
                } else if ((flags_a == 0) && (flags_b & func_00106a60(i))) {
                    ok = 1;
                } else if ((flags_b == 0) && (flags_a & func_00106880(i))) {
                    ok = 1;
                } else if ((flags_a & func_00106880(i)) &&
                           (flags_b & func_00106a60(i))) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if ((ok == 1) && !(func_00106a60(i) & 0x2000)) {
                    entry = p + ((s32)*(s16 *)(p + 2) * 4);
                    *(s16 *)(entry + 0x0E) = i;
                    *(s16 *)(entry + 0x10) = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                    *(s16 *)(p + 2) = count;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < 0x600; i++) {
            p = *(u8 **)(arg0 + 0x38);
            flags_a = *(s32 *)(p + 4);
            flags_b = *(s32 *)(p + 8);
            if ((flags_a == 0) && (flags_b == 0)) {
                ok = 1;
            } else if ((flags_a == 0) && (flags_b & func_00106a60(i))) {
                ok = 1;
            } else if ((flags_b == 0) && (flags_a & func_00106880(i))) {
                ok = 1;
            } else if ((flags_a & func_00106880(i)) &&
                       (flags_b & func_00106a60(i))) {
                ok = 1;
            } else {
                ok = 0;
            }
            if (ok == 1) {
                type = (s16)func_002be1b0(i);
                if ((type != 0x10) && (type != 0x11) && (type != 0x12)) {
                    if (func_00106330(0x1462) == 0) {
                        value = (func_00106b20(i) & 0xFFF00) >> 8;
                        if (func_002be160(value, func_00106b20(i) & 0xFF) == 1) {
                            value = (func_00106b50(i) & 0xFFF00) >> 8;
                            if (func_002be160(value, func_00106b50(i) & 0xFF) == 1) {
                                entry = p + ((s32)i * 4);
                                *(s16 *)(entry + 0x10) = 0;
                                entry = p + ((s32)*(s16 *)(p + 2) * 4);
                                *(s16 *)(entry + 0x0E) = i;
                                count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                                *(s16 *)(p + 2) = count;
                            }
                        }
                    } else {
                        entry = p + ((s32)i * 4);
                        *(s16 *)(entry + 0x10) = 0;
                        entry = p + ((s32)*(s16 *)(p + 2) * 4);
                        *(s16 *)(entry + 0x0E) = i;
                        count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                        *(s16 *)(p + 2) = count;
                    }
                } else if (func_00106330(0x1462) == 0) {
                    if (func_002bdff0(i) == 1) {
                        entry = p + ((s32)i * 4);
                        *(s16 *)(entry + 0x10) = 0;
                        entry = p + ((s32)*(s16 *)(p + 2) * 4);
                        *(s16 *)(entry + 0x0E) = i;
                        count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                        *(s16 *)(p + 2) = count;
                    }
                } else {
                    entry = p + ((s32)i * 4);
                    *(s16 *)(entry + 0x10) = 0;
                    entry = p + ((s32)*(s16 *)(p + 2) * 4);
                    *(s16 *)(entry + 0x0E) = i;
                    count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                    *(s16 *)(p + 2) = count;
                }
            }
        }
        break;
    case 3:
        for (i = 0; i < 0x600; i++) {
            entry = p + ((s32)i * 2);
            *(s16 *)(entry + 0x0E) = 0;
            p = *(u8 **)(arg0 + 0x38);
            flags_a = *(s32 *)(p + 4);
            flags_b = *(s32 *)(p + 8);
            if ((flags_a == 0) && (flags_b == 0)) {
                ok = 1;
            } else if ((flags_a == 0) && (flags_b & func_00106a60(i))) {
                ok = 1;
            } else if ((flags_b == 0) && (flags_a & func_00106880(i))) {
                ok = 1;
            } else if ((flags_a & func_00106880(i)) &&
                       (flags_b & func_00106a60(i))) {
                ok = 1;
            } else {
                ok = 0;
            }
            if (ok == 1) {
                entry = p + ((s32)*(s16 *)(p + 2) * 2);
                *(s16 *)(entry + 0x0E) = i;
                count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                *(s16 *)(p + 2) = count;
            }
        }
        break;
    case 4:
        count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
        *(s16 *)(p + 2) = count;
        for (i = 0; i < 0x600; i++) {
            entry = p + ((s32)i * 4);
            *(s16 *)(entry + 0x10) = 0;
            *(s16 *)(entry + 0x0E) = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                p = *(u8 **)(arg0 + 0x38);
                flags_a = *(s32 *)(p + 4);
                flags_b = *(s32 *)(p + 8);
                if ((flags_a == 0) && (flags_b == 0)) {
                    ok = 1;
                } else if ((flags_a == 0) && (flags_b & func_00106a60(i))) {
                    ok = 1;
                } else if ((flags_b == 0) && (flags_a & func_00106880(i))) {
                    ok = 1;
                } else if ((flags_a & func_00106880(i)) &&
                           (flags_b & func_00106a60(i))) {
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok == 1) {
                    entry = p + ((s32)*(s16 *)(p + 2) * 4);
                    *(s16 *)(entry + 0x0E) = i;
                    *(s16 *)(entry + 0x10) = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(*(s16 *)(p + 2), 1, 0, 0, 0);
                    *(s16 *)(p + 2) = count;
                }
            }
        }
        break;
    default:
        break;
    }

    mode = (s8)arg4;
    if (mode == 1) {
        out_count = 0;
        for (n = 0; n < 0x600; n++) {
            reorder[n] = -1;
        }
        for (i = 0; i < *(s16 *)(p + 2); i++) {
            entry = p + ((s32)i * 4);
            if ((func_00110830(*(s16 *)(entry + 0x0E)) & 0xFF) & 1) {
                reorder[out_count] = *(s16 *)(entry + 0x0E);
                value = func_00110830(reorder[out_count]);
                func_00110810(*(s16 *)(entry + 0x0E), (value | 2) & 0xFF);
                *(s16 *)(entry + 0x0E) = -1;
                *(s16 *)(entry + 0x10) = 1;
                out_count += 1;
            }
        }
        for (j = 0; j < *(s16 *)(p + 2); j++) {
            entry = p + ((s32)j * 4);
            if (*(s16 *)(entry + 0x0E) != -1) {
                reorder[out_count] = *(s16 *)(entry + 0x0E);
                *(s16 *)(entry + 0x10) = 0;
                out_count += 1;
            }
        }
        for (k = 0; k < *(s16 *)(p + 2); k++) {
            entry = p + ((s32)k * 4);
            *(s16 *)(entry + 0x0E) = (s16)reorder[k];
        }
    }
    if (mode == 2) {
        for (n = 0; n < *(s16 *)(p + 2); n++) {
            sortbuf[n] = *(s16 *)(p + ((s32)n * 4) + 0x0E);
        }
        func_00440bb8(sortbuf, *(s16 *)(p + 2), 4, func_002b3230);
        for (n = 0; n < *(s16 *)(p + 2); n++) {
            entry = p + ((s32)n * 4);
            *(s16 *)(entry + 0x0E) = (s16)sortbuf[n];
            *(s16 *)(entry + 0x10) = 0;
            if ((func_00110830(*(s16 *)(entry + 0x0E)) & 0xFF) & 1) {
                *(s16 *)(entry + 0x10) = 1;
                value = func_00110830(*(s16 *)(entry + 0x0E));
                func_00110810(*(s16 *)(entry + 0x0E), (value | 2) & 0xFF);
            }
        }
    }
}

s32 func_002b6ec0(u8 *arg0) {
    u8 *table;
    s32 off;
    s16 i;
    s32 count;
    s16 bit;
    s16 found;
    s32 flags;
    s32 color;
    s32 animation;
    u8 *w;
    table = *(u8 **)(arg0 + 0x38);
    i = 0;
    *(s16 *)(table + 0x30C04) = 0;
    while (i < 0x30C) {
        s16 fl;
        u8 *e;
        *(s16 *)(table + (s32)i * 2 + 0x30C06) = 0;
        off = (s32)i << 8;
        e = *(u8 **)(iGpffffb574 + 0x38) + off;
        if (((*(s16 *)(e + 0x14)) & 1) == 1) {
            /* Animation may replace the work table used for the copy. */
            animation = func_002b89a0(e + 0x14);
            e = *(u8 **)(iGpffffb574 + 0x38) + off;
            memcpy(e + 0x14, animation, 0xF0);
            e = *(u8 **)(iGpffffb574 + 0x38) + off;
            func_002b7cd0(arg0, i, *(s16 *)(e + 8));
            e = *(u8 **)(iGpffffb574 + 0x38) + off;
            fl = *(s16 *)(e + 0x14);
            if ((s16)((fl & 0x4000) >> 0xE) == 1) {
                w = func_00460990();
                *(void (**)(void))(w + 8) = func_002b6260;
                *(s32 *)(w + 0x10) = 0;
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                func_00460ac0(D_00793E80 + *(s32 *)(e + 0xC) * 0x30, w);
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                if (*(f32 *)(e + 0xA4) <= fGpffff8504 || *(f32 *)(e + 0xB0) <= fGpffff8504) {
                    goto bs0;
                } else {
                    e = *(u8 **)(iGpffffb574 + 0x38) + off;
                    color = func_002b2a30(0xFF, e[0x89], e[0x8A], e[0x8B]);
                    func_0025ecd0(*(f32 *)(e + 0x3C), *(f32 *)(e + 0x40), *(f32 *)(e + 0x18), color, e[0x72], *(s16 *)(e + 8), *(void **)(table + 0), 0, *(s16 *)(e + 0x10), *(s16 *)(e + 0x12), *(f32 *)(e + 0xD4), *(f32 *)(e + 0xA4), *(f32 *)(e + 0xB0), D_00793E80 + *(s32 *)(e + 0xC) * 0x30);
                    goto tail;
                }
bs0:
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                flags = *(s16 *)(e + 0x14);
                for (bit = 1; bit < 13; bit++) {
                    if (((flags & (u16)(1 << bit)) >> bit) == 1) { found = 1; goto bs0out; }
                }
                found = 0;
bs0out:
                if (found == 0) { *(s16 *)(e + 0x14) &= ~1; }
                goto tail;
            } else if ((s16)((fl & 0x2000) >> 0xD) == 1) {
                w = func_00460990();
                *(void (**)(void))(w + 8) = func_002b6180;
                *(s32 *)(w + 0x10) = 0;
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                func_00460ac0(D_00793E80 + *(s32 *)(e + 0xC) * 0x30, w);
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                if (*(f32 *)(e + 0xA4) <= fGpffff8504 || *(f32 *)(e + 0xB0) <= fGpffff8504) {
                    goto bs1;
                } else {
                    e = *(u8 **)(iGpffffb574 + 0x38) + off;
                    color = func_002b2a30(0xFF, e[0x89], e[0x8A], e[0x8B]);
                    func_0025ecd0(*(f32 *)(e + 0x3C), *(f32 *)(e + 0x40), *(f32 *)(e + 0x18), color, e[0x72], *(s16 *)(e + 8), *(void **)(table + 0), 0, *(s16 *)(e + 0x10), *(s16 *)(e + 0x12), *(f32 *)(e + 0xD4), *(f32 *)(e + 0xA4), *(f32 *)(e + 0xB0), D_00793E80 + *(s32 *)(e + 0xC) * 0x30);
                    goto tail;
                }
bs1:
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                flags = *(s16 *)(e + 0x14);
                for (bit = 1; bit < 13; bit++) {
                    if (((flags & (u16)(1 << bit)) >> bit) == 1) { found = 1; goto bs1out; }
                }
                found = 0;
bs1out:
                if (found == 0) { *(s16 *)(e + 0x14) &= ~1; }
                goto tail;
            } else if (e[0x72] != 0 && !(*(f32 *)(e + 0xA4) <= fGpffff8504) && !(*(f32 *)(e + 0xB0) <= fGpffff8504)) {
                color = func_002b2a30(0xFF, e[0x89], e[0x8A], e[0x8B]);
                func_0025ecd0(*(f32 *)(e + 0x3C), *(f32 *)(e + 0x40), *(f32 *)(e + 0x18), color, e[0x72], *(s16 *)(e + 8), *(void **)(table + 0), 1, *(s16 *)(e + 0x10), *(s16 *)(e + 0x12), *(f32 *)(e + 0xD4), *(f32 *)(e + 0xA4), *(f32 *)(e + 0xB0), D_00793E80 + *(s32 *)(e + 0xC) * 0x30);
                goto tail;
            } else {
                e = *(u8 **)(iGpffffb574 + 0x38) + off;
                fl = *(s16 *)(e + 0x14);
                if (fl == 1) {
                    if (*(s8 *)(e + 0x77) == 0) {
                        if (*(s8 *)(e + 0x4B) == 0) {
                            *(s16 *)(e + 0x14) = fl & ~1;
                        }
                    }
                }
            }
tail:
            /* Only entries active on loop entry belong in this list. */
            count = *(s16 *)(table + 0x30C04);
            *(s16 *)(table + count * 2 + 0x30C06) = i;
            (*(s16 *)(table + 0x30C04))++;
        }
        i++;
    }
    return 0;
}

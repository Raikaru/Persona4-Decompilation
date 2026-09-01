/* Closest attempt for func_00285dd0; retained for future reconstruction. */
s32 func_00285dd0(s32 arg0)
{
    u8 sp30[0x40];
    s32 *p;
    s32 i;
    s32 result;
    s32 high;
    u8 *iter;
    u8 *item;

    p = func_00452560();
    switch (p[0x76C / 4]) {
    case 0:
        p[0x76C / 4] = 1;
        p[0x770 / 4] |= 2;
    case 1:
        if ((p[0x770 / 4] & 2) && (p[0x770 / 4] & 1)) {
            p[0x76C / 4] = 2;
            p[0x770 / 4] &= ~2;
        }
        break;
    case 2:
        p[0x76C / 4] = 3;
        if (p[0x77C / 4] == 0) {
            func_0028ad90((u8 *)p, (p[0] & 0x80000000) != 0);
            func_002865e0((UnkStruct_002865E0 *)p);
            p[0] |= 1;
            *(f32 *)((u8 *)p + 0x750) = func_00457850(func_00457120());
            p[0x77C / 4] = func_00293ed0(
                p[0x78C / 4], p[0x790 / 4], p[0x794 / 4], p[0x788 / 4]);
        }
    case 3:
        if (func_00293fc0(p[0x77C / 4]) != 0) {
            high = (p[0] & 0x80000000) != 0;
            if (high != 0) {
                p[0x76C / 4] = 4;
            } else {
                p[0x76C / 4] = 8;
            }
            item = func_00294040(p[0x77C / 4]);
            p[1] = (s32)func_0028fb90();
            func_0028fc40(p + 0x678 / 4, p[1],
                          *(s32 *)(item + 0x34), *(s32 *)(item + 0x38),
                          *(s32 *)(item + 0x3C));
        }
        break;
    case 4:
        if (func_00285cc0((u8 *)p[1]) != 0) {
            p[0x76C / 4] = 5;
        } else {
            p[0x76C / 4] = 8;
            break;
        }
    case 5:
        if (func_00144f60() != 0) {
            p[0x76C / 4] = 8;
        }
        break;
    case 8:
        p[0x76C / 4] = 9;
        for (iter = (u8 *)func_001452b0(3); iter != NULL;
             iter = *(u8 **)(iter + 0x138)) {
        }
    case 9:
        p[0x76C / 4] = 10;
        p[0x5D0 / 4] = func_00290f00();
        i = 0;
        while (i < *(s32 *)((u8 *)p[1] + 0x44)) {
            item = *(u8 **)((u8 *)p[1] + 0x40) + i * 0x10;
            if (*(s32 *)(item + 8) == 4) {
                func_00290ec0(p[0x5D0 / 4],
                              *(s32 *)((u8 *)p[1] + 0x10) +
                              *(s32 *)(item + 4));
            }
            i++;
        }
        func_00291060(p[0x5D0 / 4]);
    case 10:
        if (func_00291080(p[0x5D0 / 4]) != 0) {
            p[0x76C / 4] = 0xB;
        }
        break;
    case 0xB:
        p[0x76C / 4] = 0xC;
        func_00296850(p[1], (u8 *)p);
    case 0xC:
        p[0x76C / 4] = 0xD;
        if ((p[0x44 / 4] & 1) == 0) {
            p[0x76C / 4] = 0xE;
        } else {
            if (p[0x78C / 4] < 0x1F4) {
                func_00442088(sp30, D_0063C350,
                               p[0x78C / 4], p[0x790 / 4]);
            } else {
                func_00442088(sp30, D_0063C340);
            }
            p[0x780 / 4] = func_0045b1c0(arg0, 2, 0, sp30);
    case 0xD:
            if (func_0045b170(p[0x780 / 4]) != 0) {
                p[0x76C / 4] = 0xE;
            }
        }
        break;
    case 0xE:
        p[0x76C / 4] = 0;
        p[0x770 / 4] &= ~1;
        result = func_00298250(p[0x78C / 4], p[0x790 / 4]);
        if ((result != 1) && (result != 2)) {
            func_00294040(arg0);
            result = func_00248d00(p[0x78C / 4], p[0x790 / 4],
                                   p[0x794 / 4]);
            if (result > 0) {
                func_00298100(result);
            }
        }
        high = (p[0] & 0x80000000) != 0;
        if (high != 0) {
            func_0028b7b0((u8 *)p);
        }
        func_0028b320((u8 *)p, 0);
        func_0028b550((u8 *)p);
        break;
    }
    return 0;
}

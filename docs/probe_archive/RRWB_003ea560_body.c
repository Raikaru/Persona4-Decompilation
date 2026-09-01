/* object_size=284 window=304 normalized_diff=193 differing_offsets=8,40,44,45,46,48,50,51,52,54,55,57,60,61,62,63 classification=undersized switch/body-layout and register/byte-width residual; prologue=leaf frame 0, $a0 incoming pointer and $a1-$a3 scratch; measured explicit switch declaration order case4/case8/case32 with no_branch_likely on/off; no confirmed compiler floor */
u8 *func_003ea560(u8 *arg0)
{
    s32 kind;

    kind = *(s32 *)(arg0 + 0xc);
    switch (kind) {
    case 4:
    case 8: {
        u8 *p;
        s32 count;
        s32 i;
        u8 max;

        p = *(u8 **)(arg0 + 0x18);
        count = 1 << kind;
        i = 0;
        if (count > 0) {
            do {
                max = p[0];
                if (max < p[1]) {
                    max = p[1];
                }
                if (max < p[2]) {
                    max = p[2];
                }
                i++;
                p[3] = max;
                p += 4;
            } while (i < count);
        }
        break;
    }
    case 32: {
        u8 *p;
        s32 row;
        s32 col;

        p = *(u8 **)(arg0 + 0x14);
        row = 0;
        if (*(s32 *)(arg0 + 8) > 0) {
            do {
                col = 0;
                if (*(s32 *)(arg0 + 4) > 0) {
                    u8 *q;

                    q = p;
                    do {
                        u8 value;

                        value = q[0];
                        if (value < q[1]) {
                            value = q[1];
                        }
                        if (value < q[2]) {
                            value = q[2];
                        }
                        q[3] = value;
                        col++;
                        q += 4;
                    } while (col < *(s32 *)(arg0 + 4));
                }
                row++;
                p += *(s32 *)(arg0 + 0x10);
            } while (row < *(s32 *)(arg0 + 8));
        }
        break;
    }
    }
    return arg0;
}

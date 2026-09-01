/* Candidate reconstruction archived: path-loop/control-flow sequence remained a MISMATCH in scoped lverify; reverted per lane policy. */
void func_00468d10(void)
{
    u8 *node;
    char *p;
    s8 ch;
    s32 state;
    s32 i0;
    s32 i1;
    s32 i2;
    s32 slash;
    char path[0x100];

    node = (u8 *)D_00922930;
    do {
        state = *(s32 *)(node + 0xC);
        switch (state) {
        case 0:
            node = *(u8 **)(node + 4);
            break;
        case 1:
            *(s32 *)(node + 0x44) = 0;
            i1 = 0;
            goto state1_test;
state1_body:
            if (func_00468bf0(node, i1) == 0) {
                goto state1_done;
            }
            i1++;
state1_test:
            if (i1 < 10) {
                goto state1_body;
            }
state1_done:
            *(s32 *)(node + 0xC) = 2;
            /* fall through */
        case 2:
            i1 = 1;
            i0 = 0;
            goto state2_test;
state2_body:
            if (*(s32 *)(node + 0x10 + i0 * 4) != 0) {
                if (func_004c9820(
                        *(s32 *)(node + 0x10 + i0 * 4)) == 3) {
                    func_004c8a60(
                            *(s32 *)(node + 0x10 + i0 * 4));
                    *(s32 *)(node + 0x10 + i0 * 4) = 0;
                    if (func_00468bf0(node, i0) == 1) {
                        i1 = 0;
                    }
                } else {
                    i1 = 0;
                }
            }
            i0++;
state2_test:
            if (i0 < 10) {
                goto state2_body;
            }
            if (i1 != 0) {
                *(s32 *)(node + 0xC) = 3;
            } else {
                node = NULL;
                break;
            }
        case 3:
            func_0043f9c8(path, 0, 0x100);
            i2 = 0;
            slash = 0x5C;
            goto path_test;
path_body:
            ch = *(s8 *)(*(u8 **)(node + 8) + i2 + 0x118);
            if (ch != 0) {
                path[i2] = ch;
            } else {
                p = path + i2 - 1;
                while (p[-1] != (s8)slash) {
                    p--;
                }
                *p = 0;
            }
            i2++;
path_test:
            if (i2 < 0x100) {
                goto path_body;
            }
            i1 = 0;
            goto res_test;
res_body:
            if (*(s32 *)(*(u8 **)(node + 0x38) + i1 * 4) != 0) {
                func_00456530(
                        path,
                        *(s32 *)(*(u8 **)(node + 0x38) + i1 * 4), 1);
                *(s32 *)(*(u8 **)(node + 0x38) + i1 * 4) += 0x100;
            }
            i1++;
res_test:
            if (i1 < *(s32 *)(node + 0x40) -
                      *(s32 *)(node + 0x3C)) {
                goto res_body;
            }
            *(s32 *)(node + 0xC) = 4;
            break;
        case 4:
            node = *(u8 **)(node + 4);
            break;
        }
    } while (node != NULL);
}

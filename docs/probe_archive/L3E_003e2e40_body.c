/* Closest compliant plain-C probe for func_003e2e40; not an exact match. */
s32 func_003e2e40(u8 *arg0, u8 *arg1) {
    s32 type;
    s32 result;
    s32 callback;
    s32 frame[2];

    type = *(s32 *)arg0;
    if (type == 4) {
        goto case4;
    }
    if (type == 3) {
        goto case3;
    }
    if (type == 2) {
        goto case2;
    }
    result = 1;
    if (type != 1) {
        goto bad;
    }
    goto common;

case2:
    result = func_003ddf20((void *)*(s32 *)(arg0 + 0xC)) == 0;
    goto common;

case3:
    if (*(s32 *)(arg0 + 4) != 1 && arg1 != NULL) {
        *(s32 *)arg1 = *(s32 *)(arg0 + 0x14);
        *(s32 *)(arg1 + 4) = *(s32 *)(arg0 + 0xC);
    }
    result = 1;
    goto common;

case4:
    callback = *(s32 *)(arg0 + 0xC);
    if (callback != 0) {
        ((void (*)(s32))callback)(*(s32 *)(arg0 + 0x1C));
    }
    result = 1;

common:
    if (*(s32 *)(arg0 + 0x20) != 0) {
        goto callback2;
    }
    goto finish;

finish:
    return result;

bad:
    frame[0] = 1;
    frame[1] = func_003df590(0xE);
    func_003df4d0(frame);
    result = 0;
    goto finish;

callback2:
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb788), arg0);
    goto finish;
}

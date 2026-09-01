/* func_003cc0d0 near-match archive: object 88 bytes, window 96 bytes, normalized_diff 6. */
u8 *func_003cc0d0(u8 *arg0) {
    s32 off;
    u8 *base;

    if (arg0 == NULL)
        goto nullcase;
reload:
    off = iGpffffb9b8;
store:
    base = D_008872E0 + off;
    *(u8 **)(base + 0x44) = arg0;
    return arg0;
nullcase:
    arg0 = *(u8 **)(D_008872E0 + iGpffffb9b8 + 0x5C);
    if (arg0 == NULL)
        goto setnull;
    off = iGpffffb9b8;
    goto store;
setnull:
    arg0 = NULL;
    goto reload;
}

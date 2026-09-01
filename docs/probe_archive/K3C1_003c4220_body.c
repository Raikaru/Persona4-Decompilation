/* func_003c4220 archive: current object 148B/window 144B, normalized_diff 81; first differing offsets 4,6-15,20,22-26. The object is oversized, so the stale nd 28 reconstruction was archived without further probes. */
s32 func_003c4220(u8 *arg0) {
    extern u8 *func_003c42b0(u8 **arg0, u8 *arg1);
    if (*(s16 *)(arg0 + 0x18) != 1) {
        *(s16 *)(arg0 + 0x18) -= 1;
        return 1;
    }
    func_003e3c20(D_0070AFF0, arg0);
    func_003c42b0((u8 **)arg0, NULL);
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + iGpffffb6c0), arg0);
    return 1;
}
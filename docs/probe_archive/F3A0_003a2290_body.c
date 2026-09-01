/* object_size=164B window=176B normalized_diff=27; differing offsets=0x10-0x18,0x20-0x30,0x34-0x84,0x88-0xA0; best direct-switch reconstruction, exact signed slt guard and callback flow but saved-register coloring differs; ruled out natural if, boolean temporary, condition-result switch, and opt_rebuildconditionals/schedule/no-branch-likely-only probes. */
u8 *func_003a2290(u8 *arg0)
{
    s32 count;
    u8 *node;
    u8 *saved_arg0;
    s32 result;
    s32 (*callback1)(u8 *, u8 *, s32, s32);
    s32 (*callback2)(u8 *, u8 *, s32);

    result = 1;
    saved_arg0 = arg0;
    node = *(u8 **)(saved_arg0 + iGpffffb610);
    count = *(s32 *)(node + 4);
    switch (count > 0) {
    case 0:
        break;
    default:
        callback1 = *(s32 (**)(u8 *, u8 *, s32, s32))(node + 0x1C);
        if (callback1 != NULL) {
            callback1(saved_arg0, node + 0x50, count, *(s32 *)(node + 0x40));
            *(s32 *)(node + 0x40) = 0;
        }
        callback2 = *(s32 (**)(u8 *, u8 *, s32))(node + 0x20);
        if (callback2 != NULL) {
            result = callback2(saved_arg0, node + 0x50, *(s32 *)(node + 4));
        }
        if (result == 1) {
            (*(void (**)(u8 *))(node + 0x10))(saved_arg0);
        }
        break;
    }
    return saved_arg0;
}

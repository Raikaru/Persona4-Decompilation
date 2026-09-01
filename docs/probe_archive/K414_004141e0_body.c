/* object_size=200B window=208B normalized_diff=119; MWCC sq-prologue candidate. */
u8 ***func_004141e0(u8 *arg0, void (*arg1)(u8 *, u8 ***, s32 **), s32 **arg2) {
    u8 ***var_17;
    u8 *var_16;
    u8 *var_4;

    var_17 = NULL;
    var_16 = (u8 *)(arg0);
    if ((s32)(arg0) != (s32)(NULL)) {
        do {
            var_4 = (u8 *)(arg0);
            if ((s32)(arg0) != (s32)(var_16)) {
loop_3:
                if ((s32)(*(u8 **)(*(u8 **)(var_4 + 0))) != (s32)(*(u8 **)(*(u8 **)(var_16 + 0)))) {
                    var_4 = *(u8 **)(var_4 + 8);
                    if ((s32)(var_4) == (s32)(var_16)) {
                    } else {
                        goto loop_3;
                    }
                }
            }
            if ((s32)(var_4) == (s32)(var_16)) {
                if ((s32)((u8 *)(arg1)) != (s32)(NULL)) {
                    arg1(*(u8 **)(*(u8 **)(var_16 + 0)), var_17, arg2);
                }
                var_17 += 1;
            }
            var_16 = *(u8 **)(var_16 + 8);
        } while ((s32)(var_16) != (s32)(NULL));
    }
    return (u8 ***)(var_17);
}

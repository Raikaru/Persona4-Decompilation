/* object 180B/window 320B, normalized_diff 272 (fndiff 72 differing words); classification severe undersize/residual in hundreds, archive immediately. Retail frame is 0x60 with ra+s0..s3 saves and two distinct error pairs at sp+0x50/+0x58; candidate collapsed to a 0x20 frame with no saved-register set. Corrected declarations: existing iGpffffb654 (gp -0x49AC) counter; block-scope absolute u8 *D_008864C0[]/D_008864D0[], func_003b8e50(void), func_003b90b0(s32). Retail cleanup and initialization logic was reconstructed but frame/control-flow/register lifetimes remain divergent. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
s32 func_003bb0d0(s32 arg0) {
    extern u8 *D_008864C0[];
    extern u8 *D_008864D0[];
    extern s32 func_003b8e50(void);
    extern u8 *func_003b90b0(s32 arg0);
    s32 error_id1;
    s32 error_value1;
    s32 error_id2;
    s32 error_value2;
    s32 slot;
    s32 cleanup_index;
    s32 success;
    u8 **table;
    u8 **cleanup;
    u8 *item;

    if (iGpffffb654 != 0) {
        goto ready;
    }
    if (func_003b8e50() != 0) {
        slot = 4;
        table = D_008864D0;
        do {
            item = func_003b90b0(slot);
            *table = item;
            if (item == NULL) {
                cleanup_index = slot - 1;
                if (cleanup_index >= 4) {
                    cleanup = &D_008864C0[cleanup_index];
                    do {
                        jtbl_008873EC[0](*cleanup);
                        cleanup_index -= 1;
                        *cleanup = NULL;
                        cleanup -= 1;
                    } while (cleanup_index >= 4);
                }
                success = 0;
            } else {
                slot += 1;
                table += 1;
                if (slot >= 11) {
                    success = 1;
                } else {
                    continue;
                }
            }
            if (success != 0) {
                goto ready;
            }
            error_id1 = 0x102;
            error_value1 = func_003df590(3);
            func_003df4d0(&error_id1);
            return 0;
        } while (0);
    }
    error_id2 = 0x102;
    error_value2 = func_003df590(3);
    func_003df4d0(&error_id2);
    return 0;
ready:
    iGpffffb654 += 1;
    return arg0;
}

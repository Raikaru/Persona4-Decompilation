/* object 188B, window 176B, normalized_diff 38; oversized reconstruction; differing offsets 24,32,36,40,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,144,148,152,156,160,164,168,172,176,180,184; casts written: none; levers ruled out: corrected block-scope func_003ddc20 return type, typed D_008873AC/D_008873D4 callback declarations, array callback calls, direct field access, and branch layout. Archive required because object exceeded retail window. */
s32 func_003dd620(u8 *arg0, u8 *arg1) {
    extern s32 *func_003ddc20(u8 *arg0);
    extern void (*D_008873AC[])(u8 *arg0, u8 *arg1);
    extern s32 (*D_008873D4[])(u8 *arg0);

    if (func_003ddc20(arg1) != NULL) {
        return 7;
    }
    if (*(u8 **)(arg0 + 0xC) != NULL) {
        (*jtbl_008873EC)(*(u8 **)(arg0 + 0xC));
    }
    *(u8 **)(arg0 + 0xC) = (*jtbl_008873E8)(D_008873D4[0](arg1) + 1, 0x401BE);
    D_008873AC[0](*(u8 **)(arg0 + 0xC), arg1);
    return 1;
}

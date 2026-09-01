/* object 252B/window 272B, normalized_diff 157; differing byte offsets begin 16-23,36-43 and continue through the switch/call/epilogue; classification residual in hundreds, archive immediately. Corrected file-scope func_003b8d40 return declaration from void to u8 *, and used block-scope declarations func_003c1b80(s32) and func_0039b6e0(s32). Retail switch/case logic and frame were reconstructed, but saved-register move ordering, flag/value materialization, case branch layout, callback setup, and epilogue remained divergent. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
u8 *func_003b8d40(u8 *arg0, s32 arg1) {
    extern s32 func_0039b6e0(s32 arg0);
    extern s32 func_003c1b80(s32 arg0);
    s32 flag;
    s32 id;
    u8 value;

    flag = (*(s32 *)(*(u8 **)(arg0 + 0x18) + 8) & 0x80) != 0;
    value = *(u8 *)(arg0 + func_003c1b80(0x120));
    switch (arg1) {
    case 1:
    default:
block_11:
        id = 0x11002;
        break;
    case 2:
        if (flag == 1) {
            id = 0x11014;
        } else {
            id = 0x11013;
        }
        break;
    case 3:
        goto block_11;
    case 0:
        id = 0x11002;
        if (value != 0) {
            if (flag == 1) {
                id = 0x11014;
            } else {
                id = 0x11013;
            }
        }
        break;
    }
    *(s32 *)(arg0 + 0x6C) = func_0039b6e0(id);
    return arg0;
}

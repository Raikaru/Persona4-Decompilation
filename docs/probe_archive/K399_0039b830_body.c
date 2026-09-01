/* object 160B / window 160B / normalized_diff 65. */
/* differing offsets: 0x10-0x17, 0x1c-0x24, 0x48-0x90, 0x98. */
/* Ruled out: direct m2c field expansion; declaration order swaps; named base pointer; inverted and explicit unsigned entry guards; goto loop shape; scoped schedule-on probe. */
void func_0039b830(u8 *arg0) {
    s32 temp_4;
    u32 var_17;
    s32 var_16;
    u8 *base;

    if (0 < *(u32 *)(arg0 + 4))
        goto loop_start;
    goto after_loop;
loop_start:
    var_17 = 0;
    var_16 = 0;
loop_items:
    base = *(u8 **)arg0;
    temp_4 = *(s32 *)(base + var_16 + 0x10);
    if (temp_4 != 0) {
        func_00411670(temp_4);
    }
    var_17 += 1;
    var_16 += 0x14;
    if (var_17 < *(u32 *)(arg0 + 4))
        goto loop_items;
after_loop:
    jtbl_008873EC[0](*(void **)arg0);
    *(s32 *)(arg0 + 8) = 0;
    *(u32 *)(arg0 + 4) = 0;
    *(u8 **)arg0 = NULL;
    *(s32 *)(arg0 + 0xC) = 0;
}

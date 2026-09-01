/* object 180B / window 192B / normalized_diff 64; differing offsets 60 and 88-106 (reloc-masked 25 words). Variants ruled out: temp, direct, reload, self, chain, typed allocator argument, schedule on, optimization level 3; residual branch/body layout and delayed tail sequence remained. */
void func_004936d0(u8 *arg0, u8 *arg1) {
    u8 *temp_2;
    s32 temp_4;

    if (*(u8 **)(arg1 + 0x2C) == NULL) {
        func_0046d730(D_00713E30, 0x115);
    }
    if (*(u8 **)(arg0 + 0x2C) == NULL) {
        temp_2 = func_00486a50(*(s32 *)(arg0 + 0));
        *(u8 **)(arg0 + 0x2C) = temp_2;
        *(s32 *)(temp_2 + 0x4C) = *(s32 *)(arg0 + 0x30);
        temp_2 = temp_2;
    }
    temp_4 = *(s32 *)(*(u8 **)(arg1 + 0x2C) + 0x50);
    if (temp_4 != 0) {
        *(s32 *)(*(u8 **)(arg0 + 0x2C) + 0x50) = (s32)func_00483270((u8 *)temp_4);
    }
    func_00487160(*(u8 **)(arg0 + 0x2C), *(u8 **)(arg1 + 0x2C));
    *(u16 *)(*(u8 **)(arg0 + 0x2C) + 0xC) = *(u16 *)(*(u8 **)(arg1 + 0x2C) + 0xC);
}

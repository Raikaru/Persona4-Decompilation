/* R049 00492b20: object 428/window 432/normalized_diff 65; undersized by 4 bytes; classification register-coloring/table-address and downstream scheduling residual after exact 128-byte frame with saved s6-s0 plus ra and incoming a0-a2; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, and sd-saved-register floors; first differing offsets 113,126,133,137,141,145,149,153,157,161,165,169,173,177,181,185. */
u8 *func_00492b20(u16 arg0, s32 arg1, void *arg2) {
    extern void func_0046d730();
    extern void func_0044ea90();
    extern void func_0043f810(void *dst, const void *src, u32 size);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    typedef struct {
        u32 value;
        u8 pad[12];
    } Code1_0049Table;
    extern Code1_0049Table D_00713D58[];
    extern Code1_0049Table D_00713D5C[];
    extern u8 D_00713E10[];
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_22;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;

    if ((arg0 & 0xFFFF) >= 0xC) {
        func_0046d730(D_00713E10, 0xD66);
    }
    temp_16 = arg1 * (*(u32 *)((u8 *)arg2 + 0xC4) *
                     *(u32 *)((u8 *)arg2 + 0xC0) + 1);
    temp_22 = temp_16 << 5;
    temp_18 = arg1 * D_00713D58[arg0 & 0xFFFF].value;
    temp_17 = D_00713D5C[arg0 & 0xFFFF].value;
    temp_18 += temp_22 + 0x30 + temp_17 * 2;
    func_0044ea90(D_00713E10, 0xD73);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_18, 0x40000);
    if (temp_2 != NULL) {
        goto allocation_done_00492b20;
    }
    func_0046d730(D_00713E10, 0xD74);
allocation_done_00492b20:
    temp_2_2 = temp_2 + 0x30;
    *(u16 *)(temp_2 + 0) = arg0;
    *(u32 *)(temp_2 + 4) = arg1;
    *(u32 *)(temp_2 + 8) = temp_16;
    *(u32 *)(temp_2 + 0xC) = 0;
    *(u32 *)(temp_2 + 0x10) = 0;
    *(u32 *)(temp_2 + 0x14) = 0;
    *(u8 **)(temp_2 + 0x18) = temp_2_2;
    temp_2_3 = temp_2_2 + temp_22;
    *(u8 **)(temp_2 + 0x20) = temp_2_3;
    temp_2_4 = temp_2_3 + temp_17;
    *(u8 **)(temp_2 + 0x24) = temp_2_4;
    temp_2_4 += temp_17;
    *(u8 **)(temp_2 + 0x1C) = temp_2_4;
    *(u8 **)(temp_2 + 0x28) = temp_2;
    func_0043f810(*(void **)(temp_2 + 0x20), arg2, temp_17);
    func_0043f810(*(void **)(temp_2 + 0x24), arg2, temp_17);
    temp_2_3 = *(u8 **)(temp_2 + 0x20);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2_3) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(temp_2_3) : "memory");
    if (*(u8 *)(temp_2_3 + 0xBC) == 0) {
        goto data_done_00492b20;
    }
    *(u32 *)(temp_2 + 0xC) |= 1;
data_done_00492b20:
    return temp_2;
}

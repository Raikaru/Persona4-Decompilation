/* object 312B/window 272B/normalized_diff 215; differing offsets 16-40; classification OVERSIZED; confirmed signature is func_003df5d0(s32,s32) from retail first touches; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode; allocator/base and aggregate-local reconstruction is a different oversized body and was discarded immediately. */
u8 *func_003df5d0(s32 arg0, s32 arg1) {
    extern void (*jtbl_008873EC[])();
    u8 *temp_2;
    u32 base;
    struct {
        s32 flag_data;
        s32 result_data;
        s32 flag_alloc;
        s32 result_alloc;
    } frame;

    temp_2 = (u8 *)(base = (u32)jtbl_008873E8,
        ((u8 *(*)(s32, s32))*(u32 *)base)(0x10, 0x30000));
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 0;
        *(s32 *)(temp_2 + 8) = 0x14;
        *(s32 *)(temp_2 + 12) = arg0;
        *(u8 **)(temp_2 + 0) =
            ((u8 *(*)(s32, s32))*(u32 *)base)(
                *(s32 *)(temp_2 + 8) * *(s32 *)(temp_2 + 12),
                arg1 | 0x01000000);
        if (*(u8 **)(temp_2 + 0) != NULL) {
            return temp_2;
        }
        frame.flag_data = 1;
        frame.result_data = func_003df590(
            0x80000013, *(s32 *)(temp_2 + 8) * *(s32 *)(temp_2 + 12));
        func_003df4d0(&frame.flag_data);
        jtbl_008873EC[0](temp_2);
        return NULL;
    }
    frame.flag_alloc = 1;
    frame.result_alloc = func_003df590(0x80000013, 0x10);
    func_003df4d0(&frame.flag_alloc);
    return NULL;
}

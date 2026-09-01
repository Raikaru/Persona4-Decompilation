/* object 332B/window 320B/normalized_diff 240; differing offsets 0,4,8,10,12,14-29; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; direct table scan plus allocator reconstruction emitted a different prologue/branch shape and exceeded the window, discarded immediately. */
u8 *func_003d51c0(s32 arg0, s32 *arg1, s32 arg2, f32 fparg0) {
    struct { u8 pad[8]; s32 code; s32 result; } frame;
    u8 *base; u8 *entry; u8 *temp; s32 count; s32 index; s32 stride;
    count = iGpffffb734; base = NULL; index = 0;
    if (count > 0) {
        entry = (u8 *)D_00886E50;
        do { if (arg0 == *(s32 *)entry) { base = (u8 *)D_00886E50 + index * 0x30; break; }
             index += 1; entry += 0x30; } while (index < count);
    }
    if (base == NULL) { frame.code = 0x1B7; frame.result = func_003df590(2); func_003df4d0(&frame.code); return NULL; }
    stride = *(s32 *)(base + 8);
    temp = ((u8 *(*)(s32,s32,s32))jtbl_008873E8[0])(*(s32 *)(base + 0x2C) + arg2 + 0x18, 0x3001B, arg2 * stride);
    *(s32 *)(temp + 4) = (s32)arg1; *(f32 *)(temp + 0xC) = fparg0; *(s32 *)(temp + 8) = arg2;
    *(u8 **)(temp + 0) = base; *(u8 **)(temp + 0x10) = temp + 0x18;
    if (*(s32 *)(base + 0x2C) > 0) *(u8 **)(temp + 0x14) = *(u8 **)(temp + 0x10) + arg2 * stride;
    else *(u8 **)(temp + 0x14) = NULL;
    return temp;
}

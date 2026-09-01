/* object 296B/window 320B/normalized_diff 194; differing offsets 4,6-8,10-12,14,16,18,20-23,26-27; classification UNDERSIZED_REGISTER_COLORING; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed; aggregate buffer padding fixed frame and buffer offsets (0xe0/sp+0x70), but b210 retained only s0-s2 versus retail's s0-s5 and the instruction layout remained materially different. */
u8 *func_003ddca0(u8 *arg0) {
    extern void func_00442de8(void *dst, const void *src, s32 size);
    extern s32 (*D_008873D0[])(u8 *arg0, s32 arg1);
    extern s32 (*D_008873D4)(u8 *arg0);
    struct { u8 pad[48]; u8 buffer[112]; } frame;
    u32 length; u8 *cursor; u8 *node; u32 index; u8 *self; u8 *table;
    self = arg0;
    if (D_00887188[0] == 0) goto fallback;
    length = D_008873D4(self); index = 0;
    if (length != 0) { table = (u8 *)D_008873D0; cursor = frame.buffer;
scan: if (*(s8 *)(self + index) == ':') goto found; index += 1;
        if (index < length) { cursor += 1; goto scan; } }
    if (iGpffffb760 == 0) goto fallback;
    return (u8 *)iGpffffb760;
found:
    func_00442de8(frame.buffer, self, index + 1);
    node = (u8 *)D_00887180[0]; cursor[1] = 0;
    if (node != NULL) { do { if (((s32 (**)(u8 *, s32))table)[0](frame.buffer, *(s32 *)(node + 0xC)) == 0) return node; node = *(u8 **)node; } while (node != NULL); }
fallback:
    if (D_00887194[0] != NULL) ((void (*)(s32))D_00887194[0])(6);
    return NULL;
}

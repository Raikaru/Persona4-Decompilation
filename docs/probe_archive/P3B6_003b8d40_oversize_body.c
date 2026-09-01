/* object 332B/window 272B, normalized_diff 248; differing byte offsets begin 0,4,8,10-20 and continue through 328; classification object oversized, archive immediately. Candidate used corrected func_003e2910(s32,void *,s32), func_003df300(s32,s32,s32), func_003bbbe0(s32,s32,void *), func_003df590(s32,...), func_003df4d0(s32 *), jtbl_008873E8 and D_008873B0 pointer declarations. Retail frame is 0x40 while local scratch array forced 0x80; frame/stack placement is the decisive mismatch. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
u8 *func_003b8d40(u8 *arg0, s32 arg1) {
    extern s32 func_003e2910(s32 arg0, void *arg1, s32 arg2);
    extern s32 func_003df300(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
    extern s32 func_003df590(s32 arg0, ...);
    extern void func_003df4d0(s32 *arg0);
    extern void *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    extern void (*D_008873B0)(void *arg0, void *arg1, s32 arg2);
    u8 frame[0x30];
    void *scratch;
    u8 *table_obj;
    s32 index;

    if (func_003e2910((s32)arg0, frame, 0x28) != 0x28) {
        return NULL;
    }
    scratch = (void *)(u32)*(s32 *)(frame + 0x20);
    index = (s32)(u32)scratch * 0xC;
    table_obj = (u8 *)jtbl_008873E8[0](index, 0x10102);
    if (table_obj != NULL) {
        if (func_003df300((s32)arg0, (s32)table_obj, index) == 0) {
            return NULL;
        }
        scratch = func_003bbbe0((s32)(u32)scratch, *(s32 *)(frame + 0x24), table_obj);
        D_008873B0((u8 *)scratch + 0x18, frame, 0x20);
        *(u8 *)scratch = 0xC;
        jtbl_008873EC[0](table_obj);
        return (u8 *)scratch;
    }
    *(s32 *)(frame + 0x28) = 0x102;
    *(s32 *)(frame + 0x2C) = func_003df590(0x80000013, index);
    func_003df4d0((s32 *)(frame + 0x28));
    return NULL;
}

/* object 336B/window 288B, normalized_diff 267; differing byte offsets 4-328; classification object oversized, archive immediately. Retail frame 0x80 and stack scratch layout were reconstructed, with block-scope declarations for func_003e2910(s32,void *,s32), func_003df300(s32,s32,s32), func_003bbbe0(s32,s32,u8 *), func_003df590(s32,...), func_003df4d0(s32 *), jtbl_008873E8 and D_008873B0. Candidate still emitted call/prologue ordering and a substantially longer error/success path than retail. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
u8 *func_003bb210(u8 *arg0) {
    extern s32 func_003e2910(s32 arg0, void *arg1, s32 arg2);
    extern s32 func_003df300(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_003bbbe0(s32 arg0, s32 arg1, u8 *arg2);
    extern s32 func_003df590(s32 arg0, ...);
    extern void func_003df4d0(s32 *arg0);
    extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    extern void (*D_008873B0[])(void *arg0, void *arg1, s32 arg2);
    struct {
        u8 work[0x28];
        s32 error_id;
        s32 error_value;
    } frame;
    void *scratch;
    u8 *table_obj;
    s32 index;

    if (func_003e2910((s32)arg0, frame.work, 0x28) != 0x28) {
        return NULL;
    }
    scratch = (void *)(u32)*(s32 *)(frame.work + 0x20);
    index = (s32)(u32)scratch * 0xC;
    table_obj = jtbl_008873E8[0](index, 0x10102);
    if (table_obj != NULL) {
        if (func_003df300((s32)arg0, (s32)table_obj, index) == 0) {
            return NULL;
        }
        scratch = func_003bbbe0((s32)(u32)scratch, *(s32 *)(frame.work + 0x24), table_obj);
        D_008873B0[0]((u8 *)scratch + 0x18, frame.work, 0x20);
        *(u8 *)scratch = 0xC;
        jtbl_008873EC[0](table_obj);
        return (u8 *)scratch;
    }
    frame.error_id = 0x102;
    frame.error_value = func_003df590(0x80000013, index);
    func_003df4d0(&frame.error_id);
    return NULL;
}

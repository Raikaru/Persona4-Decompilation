/* object_size=424; window=432; normalized_diff=277; differing_offsets(first16)=0,4,8,10,12,14,16,18,20,22,24,26,28,29,30,31; classification=AUTOMATIC_ARCHIVE_HUNDREDS_AFTER_ALL_CALLEE_DECLARATIONS_CORRECTED; ruled_out=no movz/movn, no COP1 accumulator chain, no standalone MMI, no framed tail-j forwarder, no ee-gcc sd sN signature; corrected block-scope declarations=func_0010d740(s16)->s32, func_00278450(s32,s32,s32)->void, func_0029da90(s32,u8*,s32)->s32, func_0029dfe0(void*,u8*)->void, func_00452560(void*)->u32, func_00452570(KwlnTask*,KwlnTask*)->void, iGpffffb444=u8*; residual remained in the hundreds after declaration correction, so no further probe was run. */
/* Attempted plain-C body retained for analysis; target restored to INCLUDE_ASM. */
s32 func_0022bad0(u8 *arg0, u16 arg1)
{
    s32 task;
    u8 *self;
    u8 *work;
    u8 *base;
    u8 *entry;
    u8 *script;
    s32 parent_index;

    entry = DAT_0076449c + ((arg1 & 0xFFFF) * 4);
    base = DAT_0076449c;
    if ((*(s32 *)(entry + 0xBA8) == *(s32 *)(arg0 + 8)) &&
        (*(s32 *)(entry + 0xBBC) == *(s32 *)(arg0 + 0x20))) {
        return 0;
    }
    if (arg0 == NULL) {
        self = *(u8 **)(base + 0x170);
    } else {
        self = arg0;
    }
    script = func_0022ced0(0);
    parent_index = *(s32 *)(*(u8 **)(DAT_0076449c + 0xDC8) + 0x20) - 1;
    task = func_0029da90(parent_index, script, arg1 & 0xFFFF);
    func_0029dfe0((void *)task, self);
    work = (u8 *)func_00452560((void *)task);
    if (*(s32 *)(work + 0x130) >= 0) {
        u8 *info;

        info = *(u8 **)(self + 0x30);
        if (*(u8 *)(info + 0xA2) == 0) {
            func_00278450(*(s32 *)(work + 0x130), 0,
                          func_0010d740(*(s16 *)(info + 0xA4)));
        } else {
            parent_index = *(u16 *)(info + 0xA4);
            parent_index = (parent_index << 3) - parent_index;
            parent_index = (parent_index << 2) - parent_index;
            func_00278450(*(s32 *)(work + 0x130), 0,
                          (s32)iGpffffb444 + parent_index);
        }
    }
    func_00452570(*(KwlnTask **)(DAT_0076449c + 0xDC8), (KwlnTask *)task);
    *(s32 *)(DAT_0076449c + 0xBA0) = task;
    *(s16 *)(DAT_0076449c + 0xBA4) = arg1;
    {
        s32 write_index;

        write_index = (arg1 & 0xFFFF) * 4;
        *(s32 *)(DAT_0076449c + write_index + 0xBA8) = *(s32 *)(arg0 + 8);
        *(s32 *)(DAT_0076449c + write_index + 0xBBC) = *(s32 *)(arg0 + 0x20);
    }
    return 1;
}

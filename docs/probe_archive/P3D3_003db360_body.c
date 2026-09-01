/* object 212B / window 224B / normalized_diff 154 / differing offsets 4,6,7,8,10,11,12,14,16,18,20,21,22,23,24,26 / classification undersized near-miss; candidate exact frame and saved-register set, but retail has pre-save lhu, sltu bool branch, delayed sq s0, callback/table load order and jalr delay load, two extra nops, and an uninitialized s1 offset read. block-scope func_003db190 declaration: void(s32,s32,u16,u16,u16,u8*); corrected file-scope func_003db360 return from void to u8* to match retail v0 and caller declaration. ruled out movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor. */
u8 *func_003db360(u8 *arg0, u8 *arg1) {
    extern void func_003db190(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4, u8 *arg5);
    typedef s32 (*Callback)(s32 *, s32);
    s32 index;
    s32 offset;
    u8 *entry;
    u8 *base;
    u8 *table;
    Callback callback;
    u16 field0;
    u16 field1;
    u16 field2;
    u16 count;

    count = *(u16 *)(arg0 + 0x84);
    if ((u32)0 < (u32)count) {
        index = 0;
        goto loop;
    }
    goto done;
loop:
    base = *(u8 **)(arg0 + 4);
    table = *(u8 **)(arg1 + 4);
    callback = *(Callback *)(arg1 + 0x18);
    entry = base + offset;
    if (callback(
            *(s32 **)(*(u8 **)(table + 0x10) + (*(u16 *)(entry + 6) << 2)),
            *(s32 *)(arg1 + 8)) != 0) {
        field0 = *(u16 *)(entry + 0);
        field1 = *(u16 *)(entry + 2);
        field2 = *(u16 *)(entry + 4);
        func_003db190(
            *(s32 *)(arg0 + 0x10),
            *(s32 *)(arg0 + 8),
            field0,
            field1,
            field2,
            arg1);
    }
    if (*(u16 *)(arg0 + 0x84) > ++index) {
        offset += 8;
        goto loop;
    }
done:
    return arg0;
}

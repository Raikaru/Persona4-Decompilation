/* object_size=256 window=256 normalized_diff=6 differing_offsets=0xC8,0xCC; retail sh $0,8($v0) then daddu $a0,$v0,$0, candidate reverses those words (STORE-vs-ARGUMENT ORDER). Newly ruled out: named pointer assigned before the store, store destination expressions through that local, comma-sequenced store in the free-call argument, typed s16-pointer/u8-pointer free-call prototypes, void-pointer/s16-pointer return-type forms for func_0044e920, and separate integer/call-result locals. */
void func_0044ee70(u8 *arg0) {
    s32 lock;
    u8 *block;
    u8 *pool;
    u8 *pool2;
    u8 *result;
    s32 size;
    s32 delta;
    u16 payload;
    s32 block_size;
    u32 offset;

    lock = func_0042ba20();
    if (arg0 == NULL) {
        func_0046d730(D_007104E0, 0x670);
    }
    block = *(u8 **)(arg0 - 4);
    pool = (u8 *)D_00763D1C;
    *(s32 *)(pool + 0x18) = *(s32 *)(pool + 0x18) - 1;
    pool2 = (u8 *)D_00763D1C;
    *(s32 *)(pool2 + 0x1C) = *(s32 *)(pool2 + 0x1C) - *(s32 *)block;
    if ((s32)*(u8 *)(block + 8) < 8) {
        pool = (u8 *)D_00763D1C;
        offset = *(u8 *)(block + 8) * 4;
        pool2 = (u8 *)(offset + (u32)pool);
        *(s32 *)(pool2 + 0x38) = *(s32 *)(pool2 + 0x38) - *(s32 *)block;
        payload = *(u16 *)(block + 4);
        size = payload + 0x18;
        block_size = *(s32 *)block;
        size = block_size - size;
        offset = *(u8 *)(block + 8) * 4;
        pool2 = (u8 *)(offset + (u32)D_00763D1C);
        delta = *(s32 *)(pool2 + 0x58) - size;
        *(s32 *)(pool2 + 0x58) = delta;
    }
    result = func_0044e920(block + 0xC);
    *(s16 *)(result + 8) = 0;
    func_0043ed08(result);
    if (lock != 0) {
        func_0042ba70();
    }
}

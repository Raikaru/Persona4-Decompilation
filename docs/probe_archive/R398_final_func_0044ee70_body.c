/* object 256 / window 256 / normalized_diff 6; differing offsets 0xC8 and 0xCC (retail sh $0,8($v0) then daddu $a0,$v0,$0; candidate reverses those words). Best candidate retained after clause-1 audit: func_0046d730 receives D_007104E0 in $a0 and 0x670 in $a1; func_0044e920 uses only the block+0xC $a0 argument. Clause 2 does not apply (no constant is both stored and passed). Typed/old-style prototypes, u16 store, and post-store pointer split remained nd 6; classify as independent-instruction hazard scheduling. */
void func_0044ee70(u8 *arg0)
{
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
    result = func_0044e920((E8Node *)(block + 0xC));
    *(s16 *)(result + 8) = 0;
    func_0043ed08(result);
    if (lock != 0) {
        func_0042ba70();
    }
}

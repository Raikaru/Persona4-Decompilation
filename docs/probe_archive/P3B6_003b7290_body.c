/* object 440B/window 448B, normalized_diff 316; first differing byte offsets 0,4,6,7,8,10,11,12,14,16,18,20,22,24,26,28 (residual in hundreds; archive immediately). Classification: plain-C reconstruction with severe frame/prologue and control-flow mismatch; retail frame 0xC0 with s0-s8 saves, candidate frame 0x70 with only s3/s4. Corrected first three func_003df360 calls to (arg0, destination, 4), declared block-scope allocator jtbl_008873E8 and func_003e2910, used the established file-scope jtbl_008873EC. Reconstructed fields at arg1+0x2C..0x40 and allocator/callback flow from retail. Ruled out: no conditional-move, COP1 accumulator, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor in retail; no pragma probe performed. Automatic residual-in-hundreds condition; restored fallback. */
// FUN_003B7290
s32 func_003b7290(s32 arg0, u8 *arg1) {
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern s32 func_003e2910(s32 arg0, s32 arg1, s32 arg2);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    s32 value;
    s32 count;
    s32 offset;
    s32 base;
    s32 size;
    u8 *work;
    u8 *entry;
    s32 saved;

    if (func_003df360(arg0, &value, 4) == 0) {
        return 0;
    }
    if (func_003df360(arg0, &count, 4) == 0) {
        return 0;
    }
    if (func_003df360(arg0, &offset, 4) == 0) {
        return 0;
    }
    if (count <= 0) {
        return arg0;
    }
    base = *(s32 *)arg1;
    saved = value;
    func_003b7150(arg1);
    *(s32 *)(arg1 + 0x2C) = saved;
    *(s32 *)(arg1 + 0x30) = count;
    *(s32 *)(arg1 + 0x34) = offset;
    size = base + (count << 1) + (offset << 1);
    work = (u8 *)(*jtbl_008873E8)((u32)size, 0x30116);
    *(u8 **)(arg1 + 0x38) = work;
    if (work == NULL) {
        return 0;
    }
    func_0043f9c8(work, 0, size);
    entry = work + base;
    *(u8 **)(arg1 + 0x3C) = entry;
    *(u8 **)(arg1 + 0x40) = entry + (count << 1);
    if (func_003e2910(arg0, (s32)work, size) != 0) {
        return arg0;
    }
    jtbl_008873EC[0](arg1 + 0x2C);
    return 0;
}

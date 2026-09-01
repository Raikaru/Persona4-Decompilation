/* object 92 bytes, retail window 96 bytes, normalized_diff 14; differing offsets 24, 28, 32, 36 (retail order is addiu v1, move v0, addu t0, first sw versus candidate addu, addiu, sw, move). Schedule-on is required to reach the archived 92-byte candidate; schedule-off, direct address/table/function-pointer, result-local, pointer/record-local, offset, return-value, named-initializer, separate-assignment, comma-assignment, declaration-order, register-local, opt_common_subs, and optimization_level probes were ruled out. No conversion casts. */
u8 *func_003ca830(u8 *arg0) {
    u8 *f60 = func_003ca7a0;
    u8 *f00 = func_003ca740;
    u8 *f40 = func_003ca780;
    u8 *node = arg0 + iGpffffb708;

    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(node + 0x10) = *(s32 *)(arg0 + 0x18);
    *(s32 *)(node + 0x14) = *(s32 *)(arg0 + 0x1C);
    *(s32 *)(node + 0x18) = *(s32 *)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = f60;
    *(u8 **)(arg0 + 0x18) = f00;
    *(u8 **)(arg0 + 0x1C) = f40;
    *(s32 *)(node + 0xC) = 0;
    return arg0;
}

/* object 212B, window 192B, normalized_diff 51; oversized reconstruction; differing offsets: every 4-byte offset from 0 through 208 except 4 and 16; casts written: explicit s64 sign-extension for signed 8-bit value; levers ruled out: corrected initial field offsets, callback-free control-flow reconstruction, inverted status guard, goto compare/transform layout, pointer reloads for second comparison, declaration-order probes, and opt_propagation off. Archive required because object exceeded retail window. */
 s32 func_003d0790(u8 *arg0) {
    s32 *entry;
    u8 *node;
    u8 *status;
    s32 status_value;
    s32 value;
    entry = *(s32 **)(arg0 + 0xC);
    node = *(u8 **)(arg0 + 0x30);
    status = *(u8 **)(arg0 + 0x2C);
    status_value = *entry;
    node = *(u8 **)node;
    value = *(s32 *)(status + 4);
    if ((status_value & 2) != 0) {
        goto transform;
    }
compare:
    if ((s32)(((s64)value << 0x20) >> 0x20) != *(s32 *)(node + 0x24)) {
        goto mark_first;
    }
check_flags:
    if ((*(s32 *)(arg0 + 0x34) & 8) != 0) {
        return 1;
    }
    *(s32 *)(arg0 + 0x38) = *(s32 *)*(u8 **)(arg0 + 0xC);
    if (*(s32 *)(arg0 + 0x38) !=
        *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30)) + 0x2C)) {
        *(s32 *)(arg0 + 0x34) |= 8;
    }
    return 1;
transform:
    value = (s32)(((s64)value << 0x20) >> 0x20);
    value = (value - 2) * 3;
    goto compare;
mark_first:
    *(s32 *)(arg0 + 0x34) |= 8;
    goto check_flags;
}

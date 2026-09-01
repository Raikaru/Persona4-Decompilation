/* N3B best: object 84B/window 96B, normalized_diff 7 (exact Z3BF archive text, reproduced under current TU). Requires #pragma schedule on + #pragma opt_propagation off, and the head store must go through the D_00885A90 symbol, not the base local (base-local store = nd45). Residual 2 words: retail puts jr $ra in the beqz delay slot and pads nop;nop;nop after the loop vs our nop;jr;nop — b210 will not place an epilogue instruction in that delay slot. All 156 archived 84B shapes measure nd>=7; dead-multiply spellings nd44-53. */
#pragma schedule on
#pragma opt_propagation off
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffb680 = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    *(s32 *)D_00885A90 = value;
    if (count == 0) {
        goto done;
    }
    factor = 0x10DCD;
    do {
        value *= factor;
        count -= 1;
        *ptr = value;
        ptr += 1;
    } while (count != 0);
done:
    return;
}
#pragma opt_propagation on
#pragma schedule off

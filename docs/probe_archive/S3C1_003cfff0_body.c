/* object 332B/window 336B normalized_diff 164; first differing instruction offsets 2,4-14,18,24-28,32-40,44-84,92-96,100-164,168-172,176,184-228,232-320; instruction deficit 1. Classification NEAR_MISS: full retail logic transcribed, leaf prologue and signature match (0 saved $s; args u8 *arg0, u8 *arg1), but MWCC register allocation/evaluation order differs throughout; no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or sd/sq mixed-unit floor. Direct field widths u32/u16/u8 and explicit branch labels measured; body not retained. */
// FUN_003CFFF0
void func_003cfff0(u8 *arg0, u8 *arg1) {
    u8 *desc;
    u8 *item;
    u8 *item_data;
    u8 *tail;
    u32 flags;
    u32 packed;
    u32 item_packed;

    desc = *(u8 **)(arg0 + 0x18);
    flags = *(u32 *)(desc + 8);
    if ((flags & 0x01000000U) != 0)
        goto done;
    packed = ((u32)(flags & 0x9FU) << 16) |
             ((u32)*(u8 *)(desc + 0x18) << 24) |
             (u32)*(u16 *)(*(u8 **)(arg1 + 0xC) + 6);
    *(u32 *)(arg1 + 0x18) = packed;
    *(u32 *)(arg1 + 0x14) &= ~1U;
    item = *(u8 **)(arg1 + 0x10);
    item = *(u8 **)(item + 4);
    if (item == NULL)
        goto done;
    tail = arg0 + 0x4C;
    item_data = item + 0x18;
    if (packed != *(u32 *)(item + 0x28)) {
        if ((((packed >> 16) & 0xFFU) == ((*(u32 *)(item + 0x28) >> 16) & 0xFFU)) &&
            (((packed >> 24) & 0xFFU) == ((*(u32 *)(item + 0x28) >> 24) & 0xFFU)))
            *(u32 *)(arg1 + 0x14) |= 4;
        else
            *(u32 *)(arg1 + 0x14) |= 8;
    }
    if (*(u16 *)(desc + 0xC) != 0) {
        if ((*(u16 *)(desc + 0xC) & 1U) != 0) {
            *(u32 *)(arg1 + 0x14) |= 8;
        } else {
            *(u32 *)(arg1 + 0x14) |= 2;
            *(u32 *)(arg1 + 0x14) |= (u32)(*(u16 *)(desc + 0xC) << 3);
        }
    }
    if ((*(u32 *)tail & 1U) == 0)
        goto done;
    if (*(s32 *)(item_data + 0x28) != (s32)*(s16 *)(tail + 6))
        goto set_changed;
    if (*(s32 *)(item_data + 0x24) == (s32)*(s16 *)(tail + 4))
        goto done;
set_changed:
    *(u32 *)(arg1 + 0x14) |= 4;
done:
    return;
}

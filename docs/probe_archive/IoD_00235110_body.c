/* Installed exact in datCalc.c: b210 owner profile, 524B/528B, zero differing
 * emitted words; one omitted zero tail word. Shares P4CalcLevel with 00235320.
 * Native32 actual-source smoke: 1,053,696 cases under undefined/function
 * sanitizers, all status/level nibbles, both parities, surrounding-byte
 * preservation, inactive encodings 0/15, and repeated saturation at 15.
 */
static inline s8 P4CalcLevel(u8 *unit, u8 index)
{
    u16 offset;
    s32 level;
    if ((s32)index >= 24)
        func_0046d730(D_00635938, 0x42A);
    offset = index >> 1;
    if (index & 1)
        level = (s8)(*(u8 *)(unit + offset + 0x24) >> 4);
    else
        level = (s8)(*(u8 *)(unit + offset + 0x24) & 15);
    return (s8)level;
}

static inline void P4CalcSetLevel(u8 *unit, u8 index, s8 level)
{
    u16 offset;
    u8 *ptr;
    if ((s32)index >= 24)
        func_0046d730(D_00635938, 0x45E);
    if (level < 0)
        func_0046d730(D_00635938, 0x45F);
    offset = index >> 1;
    if (index & 1) {
        ptr = unit + offset;
        ptr[0x24] = (ptr[0x24] & 15) | ((level & 15) << 4);
    } else {
        ptr = unit + offset;
        ptr[0x24] = (ptr[0x24] & 240) | (level & 15);
    }
}

void func_00235110(u8 *unit)
{
    s32 checked;
    u32 index;
    s8 active;
    s8 level;
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            func_0046d730(D_00635938, 0x4C1);
        if (checked < 16)
            active = func_002332a0(unit, index % 256U);
        else {
            u8 result = (*(u32 *)(unit + 0x14) & (1U << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel(unit, index);
        if (active != 0 && level < 15)
            P4CalcSetLevel(unit, index, level + 1);
    }
}

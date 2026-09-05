/* Candidate for func_00279780: object 768B/window 768B; fndiff 9 words.
   Uses the canonical pointer-returning constructor prototype. Unsigned
   index-first address arithmetic fixes both commutative ADDU residuals.
   Remaining: four byte argument loads precede the two zero argument moves,
   and the global address is materialized before the first argument move.
   The list walk and both signed count checks already match. Retain ASM. */
// FUN_00279780
void func_00279780(u8 *arg0)
{
    u8 *base;
    u8 *table;
    u8 *slot;
    u8 *obj;
    u8 *node;
    s32 index;
    s32 count;
    s32 flags;
    s32 found;

    base = arg0 + 0x1C;
    if (*(s32 *)(arg0 + 0x20) != 0) {
        func_00271b70(*(s32 *)(arg0 + 0x20));
        *(s32 *)(base + 4) = 0;
    }
    index = *(s16 *)(base + 0x10);
    table = *(u8 **)base;
    count = *(s16 *)(table + 0x18);
    if (index < 0 || index >= count)
        slot = NULL;
    else
        slot = *(u8 **)(((u32)index << 2) + (s32)table + 0x1C);
    if (slot == NULL)
        func_0046d730(D_0063BE10, 0xC82);
    iGpffffb4b0 = 0x7B;
    obj = func_00274570(
        0, 0, *(u8 *)(base + 0xA), *(u8 *)(base + 0xB),
        *(u8 *)(base + 0xC), *(u8 *)(base + 0xD), (u32)slot, 0);
    iGpffffb4b0 = 0;
    if (obj == NULL)
        func_0046d730(D_0063BE10, 0xCAA);
    *(u8 **)(base + 4) = obj;
    if (obj != NULL)
        *(s16 *)(base + 0xE) = func_0027a2d0((u8 *)func_00272bf0((s32)obj), obj);
    flags = func_00274650(3);
    *(u8 *)(base + 9) = (u8)flags;
    if (*(u8 *)(base + 9) & 2U)
        *(s32 *)arg0 |= 0x10000;
    else
        *(s32 *)arg0 &= ~0x10000;
    flags = func_00274650(0x30);
    if (flags != 0)
        *(s32 *)arg0 |= 0x08000000;
    else
        *(s32 *)arg0 &= ~0x08000000;
    if (flags & 0x20)
        *(s32 *)arg0 |= 0x04000000;
    else
        *(s32 *)arg0 &= ~0x04000000;
    func_0027a340(obj, *(s32 *)(arg0 + 0xC));
    if (func_00274650(4) != 0)
        func_00279dd0(arg0, (s32)D_00881530);
    node = *(u8 **)DAT_008817EC_abs;
    goto list_test;
list_body:
    if (*(u8 **)(node + 0xC) == arg0) {
        found = *(s32 *)(node + 8);
        goto list_done;
    }
    node = *(u8 **)(node + 4);
list_test:
    if (node != NULL)
        goto list_body;
    found = -1;
list_done:
    func_0027bb00(found);
    if ((*(s32 *)arg0 & 0x400000) == 0 &&
        (*(u16 *)D_008817E8_abs & 1U) != 0)
        func_0027a580((s32)obj);
    func_0027a2a0((s32)obj, (s32)base);
    if ((*(s32 *)arg0 & 0x300) == 0x200) {
        s32 value;

        index = *(s16 *)(arg0 + 0x2C);
        table = *(u8 **)(arg0 + 0x1C);
        count = *(s16 *)(table + 0x18);
        if (index < 0 || index >= count)
            value = 0;
        else
            value = *(s32 *)(((u32)index << 2) + (s32)table + 0x1C);
        func_002748e0(value, 1, 0);
    }
}

/* object 768B/window 768B, normalized_diff 30, differing offsets 102,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158; deficit 0 instructions (exact size); classification saved-register/register coloring plus narrow-load and call-argument ordering; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, EE-gcc sd/sq floor. Retail prologue saves s3/s2/s1/s0 and frame -0x40; one u8* arg0. Candidate exact size; residuals include first 74570 argument lbu ordering, D_008817EC list walk layout, second lookup slot register reuse, and tail scheduling. */
// FUN_00279780
void func_00279780(u8 *arg0)
{
    s32 func_00274570();
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
        slot = *(u8 **)(table + index * 4 + 0x1C);
    if (slot == NULL)
        func_0046d730(D_0063BE10, 0xC82);
    iGpffffb4b0 = 0x7B;
    {
        u8 p2;
        u8 p3;
        u8 p4;
        u8 p5;

        p2 = *(u8 *)(base + 0xA);
        p3 = *(u8 *)(base + 0xB);
        p4 = *(u8 *)(base + 0xC);
        p5 = *(u8 *)(base + 0xD);
        obj = (u8 *)func_00274570(
            0, 0, p2, p3, p4, p5, (u32)slot, 0);
    }
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
            value = *(s32 *)(table + index * 4 + 0x1C);
        func_002748e0(value, 1, 0);
    }
}

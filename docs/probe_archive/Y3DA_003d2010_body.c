/* object 172B, window 192B, normalized_diff 47; differing offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180; casts written: none; levers ruled out: scalar GP address spelling (iGpffffaac8), opt_propagation off, schedule-on, block-scope declarations, staged base/slot/index locals, goto branch layout, direct indexed field accesses, and declaration/order probes. */
void func_003d2010(u8 *arg0, u8 *arg1) {
    extern s32 iGpffffaac8;
    extern s32 iGpffffb6f0;
    extern u8 D_0070B150[];
    extern u8 D_0070B170[];
    u8 *base;
    u8 *gp_addr;
    s32 offset;
    u8 *slot;
    u8 *lookup;
    u8 index;
    s32 value;

    gp_addr = (u8 *)&iGpffffaac8;
    base = D_008872E0;
    *(u8 **)(arg1 + 0x10) = gp_addr;
    *(u8 **)(arg1 + 0xC) = D_0070B150;
    *(s32 *)(*(u8 **)(arg1 + 0xC) + 8) = *(s32 *)(arg0 + 0x2C);
    *(s32 *)(*(u8 **)(arg1 + 0xC) + 0xC) = 0;
    *(s32 *)(*(u8 **)(arg1 + 0xC) + 0) = 0;
    offset = iGpffffb6f0;
    slot = *(u8 **)(arg1 + 0xC);
    index = *(u8 *)(arg0 + 0x24);
    base += offset;
    value = *(s32 *)slot;
    lookup = base + index;
    value = (value & -0x100) | *(u8 *)(lookup + 0x27);
    *(s32 *)slot = value;
    if (*(s32 *)(arg0 + 0x28) == 0) {
        goto set_flag;
    }
    goto setup;
set_flag:
    slot = *(u8 **)(arg1 + 0xC);
    *(s32 *)slot |= 0x100;
setup:
    slot = *(u8 **)(arg1 + 0x10);
    *(s32 *)(slot + 4) = 0;
    slot = *(u8 **)(arg1 + 0xC);
    *(u8 **)(slot + 0x18) = D_0070B170;
    *(s32 *)(slot + 0x10) = *(s32 *)(arg0 + 0x28);
    *(s32 *)(slot + 0x14) = *(s32 *)(arg0 + 0x2C);
}

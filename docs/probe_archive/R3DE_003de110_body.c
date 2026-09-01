/* object 348B / window 352B / normalized_diff 167 / differing offsets 104,132-... / classification oversized-by-window near miss (frame exact: retail saves s0-s5, candidate saves s0-s5; retail frame 0xE0, candidate frame 0xE0); six long-lived locals and buffer[112] corrected frame; residual is common-dispatch/list scan block layout, unsigned length guard, absolute D_008873D4 load/call placement, and lb versus lbu. Tried selected dispatch local, direct callback paths, named absolute/global declarations, schedule/no_branch_likely; no floor instruction in retail (no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, custom COP1 sqrt, or rd-form mult). Callees: func_00442de8(u8*,u8*,u32). */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003de110(u8 *arg0) {
    extern void func_00442de8(u8 *arg0, u8 *arg1, u32 arg2);
    extern s32 D_008873D4[];
    extern u8 *iGpffffb750;
    s32 (**table)(u8 *arg0, s32 arg1);
    u8 *self;
    u32 index;
    u8 *node;
    u8 *cursor;
    u32 length;
    u8 *selected;
    u8 buffer[112];

    self = arg0;
    if (D_00887188[0] != 0)
        goto active;
init:
    if (D_00887194[0] != NULL)
        ((void (*)(s32))D_00887194[0])(6);
    selected = NULL;
dispatch:
    if (selected == NULL)
        return 0;
    return ((s32 (*)(u8 *arg0, u8 *arg1))(*(void **)(selected + 0x4C)))(
        selected, self);
active:
    length = ((s32 (*)(void))D_008873D4[0])();
    index = 0;
    if (length > 0)
        goto scan_setup;
    goto fallback;
scan_setup:
    table = D_008873D0;
    cursor = buffer;
scan:
    if (self[index] == 0x3A)
        goto found;
    index += 1;
    cursor += 1;
    if (index < length)
        goto scan;
fallback:
    if (iGpffffb750 == NULL)
        goto init;
    selected = iGpffffb750;
    goto dispatch;
found:
    func_00442de8(buffer, self, index + 1);
    node = (u8 *)D_00887180[0];
    cursor[1] = 0;
    if (node == NULL)
        goto scan_next;
list:
    if (table[0](buffer, *(s32 *)(node + 0xC)) == 0) {
        selected = node;
        goto dispatch;
    }
    node = *(u8 **)node;
    if (node != NULL)
        goto list;
    selected = NULL;
    goto dispatch;
scan_next:
    index += 1;
    cursor += 1;
    if (index < length)
        goto scan;
    goto fallback;
}

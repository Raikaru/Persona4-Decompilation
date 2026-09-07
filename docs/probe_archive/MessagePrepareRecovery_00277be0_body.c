/* NOT PROMOTABLE: executed 1U << index is undefined for index>=32, while
 * retail SLLV wraps. Producer/loaders and six inspected direct calls do not
 * establish a count bound. Seven embedded MSG assets only expose three
 * kind-1 records with count2; this is not the full game-resource corpus.
 * Ordinary s32 locals emit664 executable bytes/672B window, with25 resolved
 * relocations and zero executable differences; final8B is alignment.
 * Defined index&31 and unsigned modulo32 variants emit668B/89 masked words;
 * signed modulo emits688B/92. Masked O4 gives584B/151. Retain production ASM.
 * Consumers continue beyond32 with shifted-to-zero masks, so mask width
 * does not prove count<=32. Native UBSan traps unbounded32/63/64/32766;
 * masked boundary probes pass. No shipped count33 reachability is claimed.
 * Requires the existing itfMesManager.c declarations and object table. */
void func_00277be0(s32 arg0, s32 arg1)
{
    u8 *object;
    s32 flags;
    s32 index;
    s32 *text;
    s32 x;
    s32 y;
    s32 saved_font;
    u32 remaining_mask;
    u8 *base;
    s32 font;
    s32 active_flags;
    s32 mode_flags;
    s32 count;
    u32 mask;
    s32 old_font;
    u32 new_mask;
    u8 *record;
    s32 spacing;
    u8 *data;
    s32 visible_count;

    object = D_00881808[arg0].unk0;
    if (object == NULL)
        func_0046d730(D_0063BE10, 0x686);
    record = (u8 *)func_00278de0((s32)object, arg1);
    if (*(s32 *)record != 1)
        func_0046d730(D_0063BE10, 0x68A);
    base = object + 0x3C;
    old_font = *(s32 *)(object + 0x40);
    if (old_font != 0) {
        func_00271b70(old_font);
        *(s32 *)(base + 4) = 0;
    }
    data = *(u8 **)(record + 4);
    remaining_mask = *(u32 *)(base + 8);
    count = (s32)*(s16 *)(data + 0x1A);
    text = (s32 *)(data + 0x20);
    new_mask = 0;
    index = 0;
    while (index < count) {
        if (remaining_mask & 1U) {
            remaining_mask >>= 1;
        } else {
            func_002748e0(*text, 2, 0);
            if (func_00274650(8) != 0)
                new_mask |= 1U << index;
        }
        index += 1;
        text++;
    }
    mask = *(u32 *)(base + 8) | new_mask;
    *(u32 *)(base + 8) = mask;
    visible_count = func_00279fd0(*(s16 *)(data + 0x1A), mask);
    func_0027b750(arg0, 0, visible_count);
    func_0027bb60(arg0);
    x = func_0027b6e0(arg0, 0);
    y = func_0027b6e0(arg0, 1);
    spacing = func_0027b6e0(arg0, 2);
    func_00279ce0(object + 0x94);
    font = *(s32 *)(object + 8);
    if (font != 0)
        func_002738a0(font);
    saved_font = iGpffffb4b0;
    if (saved_font == 0)
        iGpffffb4b0 = 0x7B;
    *(s32 *)(base + 4) = (s32)func_0027a010(
        (u32 *)(data + 0x20),
        *(s16 *)(data + 0x1A),
        *(u32 *)(base + 8),
        x, y, *(s32 *)(object + 0xC), spacing, 0);
    iGpffffb4b0 = saved_font;
    func_0027bbc0(arg0);
    *(s16 *)(base + 0x12) = (s16)visible_count;
    flags = *(s32 *)object & ~0x38;
    *(s32 *)object = flags;
    active_flags = flags | 0x10;
    *(s32 *)object = active_flags;
    mode_flags = active_flags & ~0xC00;
    *(s32 *)object = mode_flags;
    *(s32 *)object = mode_flags | 0x400;
    *(s16 *)(base + 0xC) = 1;
    *(s32 *)base = arg1;
}

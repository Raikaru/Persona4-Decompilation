/* object 284 / window 304 / normalized_diff 117; differing offsets 0x30-0x12c; undersized 20 bytes: switch out-of-line layout and call-tail nop scheduling; classification hidden return value plus switch declaration/body order; schedule off around switch and whole-function schedule-off ruled out. */
u8 *func_00398410(u8 *arg0)
{
    s32 type;
    s32 i;
    u8 *entry;
    u8 *p;
    extern void func_003ef3a0();
    extern void func_0043f9c8(void *dst, s32 value, s32 size);

    i = 0;
    do {
        entry = arg0 + ((i & 0xFF) << 6);
        type = *(s32 *)(entry + 0x20);
        switch (type) {
        case 0:
            break;
        case 1:
            p = *(u8 **)(entry + 4);
            if (p != NULL) func_003ef3a0(p);
            p = *(u8 **)(entry + 8);
            if (p != NULL) func_003ef3a0(p);
            break;
        case 2:
            p = *(u8 **)(entry + 4);
            if (p != NULL) func_003ef3a0(p);
            break;
        case 4:
            p = *(u8 **)(entry + 0);
            if (p != NULL) func_003ef3a0(p);
            break;
        case 5:
            *(u8 **)(entry + 0) = NULL;
            *(u8 **)(entry + 4) = NULL;
            break;
        default:
            break;
        }
        i = (i + 1) & 0xFF;
    } while (i < 2);
    func_0043f9c8(arg0, 0, 0x90);
    return arg0;
}

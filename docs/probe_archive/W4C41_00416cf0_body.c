#pragma schedule on
s32 func_00416cf0(u8 *arg0, s32 arg1)
{
    extern s32 func_003df1a0();
    extern s32 func_003df240();
    extern s32 func_003df270();
    s32 *base;
    s32 *entry;
    s32 *tail;
    s32 offset;
    s32 i;
    s32 count;

    count = *(s32 *)(arg0 + 4);
    base = *(s32 **)(arg0 + 0x10);
    tail = *(s32 **)(arg0 + 0x14);
    i = 0;
    if (count > 0) {
        entry = base;
        do {
            if (func_003df1a0(arg1, entry + 1, 4) == 0) {
                return 0;
            }
            if (func_003df270(arg1, entry + 2, 0xE) == 0) {
                return 0;
            }
            offset = *entry - (s32)base;
            if (func_003df240(arg1, &offset, 4) == 0) {
                return 0;
            }
            i += 1;
            entry += 6;
        } while (i < count);
    }
    return func_003df1a0(arg1, tail, 0x18) != 0;
}
#pragma schedule off

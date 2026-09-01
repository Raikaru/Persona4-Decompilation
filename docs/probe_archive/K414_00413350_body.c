/* object_size=192B window=192B normalized_diff=120; MWCC frameless candidate. */
void func_00413350(u8 *arg0, u32 *arg1, s32 arg2, s32 arg3, u8 ***arg4) {
    u8 *entry;
    u32 count;
    u32 index;

    count = *(u32 *)(arg0 + 0);
    entry = *(u8 **)(arg0 + 0xC);
    index = 0;
    if (count != 0 && count > 0) {
        do {
            if (*(u32 *)(entry + 0) == (u32)arg1) {
                break;
            }
            index += 1;
            entry += 0x24;
            if (index >= count) {
                entry = NULL;
                break;
            }
        } while (1);
    } else {
        entry = NULL;
    }
    if (entry != NULL) {
        if (arg2 == 1) {
            *(s32 *)(entry + 4) = 1;
            *(u8 ****)(entry + 0x20) = arg4;
        }
        return;
    }
    entry = *(u8 **)(arg0 + 0xC) + count * 0x24;
    *(u32 *)(arg0 + 0) = *(u32 *)(arg0 + 0) + 1;
    *(u8 **)(entry + 0) = (u8 *)arg1;
    *(s32 *)(entry + 4) = arg2;
    *(s32 *)(entry + 8) = arg3;
    *(s32 *)(entry + 0x10) = 0;
    *(u8 **)(entry + 0x14) = (u8 *)arg0;
    *(s32 *)(entry + 0xC) = 0;
    *(s32 *)(entry + 0x18) = 0;
    *(s32 *)(entry + 0x1C) = -1;
    *(u8 ****)(entry + 0x20) = arg4;
}

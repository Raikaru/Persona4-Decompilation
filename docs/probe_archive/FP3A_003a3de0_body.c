/* Best attempted reconstruction for func_003a3de0; object 168B, retail window 176B, normalized_diff 55. Restored to INCLUDE_ASM because it did not match. */
void func_003a3de0(u8 *arg0)
{
    u32 count;
    u8 *base;
    u8 *list;
    u8 *node;

    base = *(u8 **)(arg0 + iGpffffb610);
    if ((*(s32 *)(base + 0x44) & 0x10) == 0) {
        list = *(u8 **)(base + 0x9C);
        if (*(s32 *)(list + 0xD8) != 0) {
            count = 0;
            node = list;
        loop_start:
            if (*(s32 *)(node + 0x10) != 0)
                goto do_calls;
        skip_calls:
            count++;
            node += 0x20;
            if ((u32)*(s32 *)(list + 0xE8) >= count)
                goto loop_start;
            goto done;
        do_calls:
            func_003f32d0();
            func_003f32d0();
            goto skip_calls;
        }
    done:
        ;
    }
}

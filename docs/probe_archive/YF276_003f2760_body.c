/* Final measured candidate body; archived because it remained a near-miss. */
void func_003f2760(void)
{
    s32 offset;
    s32 count;
    u16 limit;
    u16 index;
    s32 size;
    u8 *base;
    index = iGpffffb810;
    limit = iGpffffb80c;
    if (index != limit) {
        iGpffffb810 = 0;
        iGpffffb80c = 0;
        base = (u8 *)iGpffffb814;
            offset = (index & 0xffff) * 4;
            entry = *(u8 **)(base + offset);
            count = *(s32 *)(entry + 4);
            *(s32 *)(entry + 4) = 0;
            if (count > 0) {
                do {
                    size = count >= 0x10000 ? 0xffff : count;
                    func_003f34e0(*(u8 **)((u8 *)&iGpffffb814 + offset),
                                  (size << 12) | 0x42);
                    count = (count - 0x8000) - 0x7fff;
                } while (count > 0);
            }
            index = (index + 1) & 0xffff;
            if (index == *(u16 *)((u8 *)&iGpffffabd4)) {
                index = 0;
            }
        } while ((index & 0xffff) != limit);
    }
}

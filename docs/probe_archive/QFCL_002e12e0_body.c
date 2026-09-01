/* object 192B / window 208B / normalized_diff 135 / differing byte offsets (first 16) [14,17,20,21,22,23,24,27,28,30,31,32,34,35,38,39]; classification: size-deficit/register-colouring with retail preheader mask load; ruled out declaration and statement order, u8/s16/u32 pointer widths, inline/local/initializer mask forms, base temporary, and optimization_level 1 (oversized). */
s32 func_002e12e0(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 mask;
    u8 *p;
    s16 flags;

    result = 1;
    p = (u8 *)(*(int *)(iGpffffb588 + 0x24) + 4);
    i = 0;
    mask = 0xFFFF0000;
    while (i < 2) {
        if (p != arg0) {
            flags = *(s16 *)p;
            if ((flags & 1) && (flags & 8) && ((flags & 0x100) == (*(s16 *)arg0 & 0x100)) && !(flags & 0x1000)) {
                *(s16 *)p = (s16)(flags | 0x400);
                if ((*(s32 *)(p + 4) & mask) == (*(s32 *)(arg0 + 4) & mask)) {
                    *(s16 *)p = (s16)(*(s16 *)p | 0x40);
                }
                if (!(*(s16 *)p & 4)) {
                    result = 0;
                }
            }
        }
        p += 0x14;
        i++;
    }
    return result;
}

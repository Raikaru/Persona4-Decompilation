/* object 480B / window 512B / normalized_diff 334 / first differing byte offsets [30,34,37,38,40,41,43,44,47,50,51,52,54,55,56,58] (115 differing words by fndiff); classification: automatic size-deficit archive after checking the existing file-scope callee declarations against available definitions; no banned compiler-floor signature; ruled out callee-prototype mismatch, and no additional source probes were justified after residual remained in the hundreds. */
s64 func_002e1030(void *arg0)
{
    s16 *p;
    s16 *q;
    s32 i;
    s32 j;
    s64 found;
    u8 *slot;
    u8 *src;
    s32 value;
    s16 flags;

    p = (s16 *)(*(s32 *)(iGpffffb588 + 0x24) + 4);
    i = 0;
    while (i < 2) {
        if (!(*p & 1)) {
            found = (s16)i;
            break;
        }
        p += 0x14;
        i++;
    }
    if (i >= 2) {
        found = -1;
        q = (s16 *)(*(s32 *)(iGpffffb588 + 0x24) + 4);
        j = 0;
        while (j < 2) {
            flags = *q;
            if ((flags & 1) && !(flags & 2) && !(flags & 8)) {
                found = (s16)j;
                break;
            }
            q += 0x14;
            j++;
        }
    }
    if (found == -1) {
        return -1;
    }
    slot = (u8 *)(*(s32 *)(iGpffffb588 + 0x24) + (s32)found * 0x14);
    src = *(u8 **)((u8 *)arg0 + 0x14);
    *(s32 *)(slot + 8) = *(s32 *)(src + 4);
    *(s16 *)(slot + 4) = *(s16 *)src;
    *(s16 *)(slot + 0xC) = (s16)found;
    value = *(s32 *)(slot + 8);
    func_00104510(found, (s16)((value & 0xFFFF0000) >> 16), (s16)((value & 0xFF00) >> 8), (s16)(value & 0xFF));
    func_001047b0(*(s16 *)(slot + 8), 1);
    flags = (s16)(*(s16 *)(slot + 4) | 1);
    *(s16 *)(slot + 4) = flags;
    *(s16 *)(slot + 4) = (s16)(flags | 2);
    func_002e2240((int *)iGpffffb588, (int *)(iGpffffb588 + 4), (int *)arg0);
    func_00440b68((char *)(&iGpffffa890), D_0063FBB0, 0x19D);
    func_002e0ea0((u8 *)D_0063FBC8, *(s16 *)(slot + 8));
    return found;
}

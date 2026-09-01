s16 func_002e1030(void *arg0)
{
    s32 i;
    s16 *p;
    s16 idx;
    s16 j;
    s32 *v;
    s16 *out;

    p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);
    idx = -1;
    for (i = 0; i < 2; i++, p += 0xA) {
        if (!(*p & 1)) {
            idx = (s16)i;
            break;
        }
    }
    j = -1;
    if (idx == -1) {
        p = (s16 *)(*(int *)(iGpffffb588 + 0x24) + 4);
        for (i = 0; i < 2; i++, p += 0xA) {
            if ((*p & 1) && !(*p & 2) && !(*p & 8)) {
                j = (s16)i;
                break;
            }
        }
    } else {
        j = idx;
    }
    if (j != -1) {
        v = *(s32 **)((u8 *)arg0 + 0x14);
        p = (s16 *)((u8 *)(*(int *)(iGpffffb588 + 0x24) + 4) + (s32)j * 0x14);
        out = p;
        *(s32 *)((u8 *)p + 8) = v[1];
        *(s16 *)((u8 *)p + 4) = *(s16 *)v;
        *(s16 *)((u8 *)p + 0xC) = j;
        func_00104510((s64)(*(s32 *)((u8 *)p + 8) >> 16), (s16)(*(s32 *)((u8 *)p + 8) >> 8), (s16)*(s32 *)((u8 *)p + 8), (s16)j);
        func_001047b0((s64)*(s16 *)((u8 *)out + 8), 1);
        *out = (s16)(*out | 3);
        func_002e2240((int *)iGpffffb588, (int *)(iGpffffb588 + 4), (int *)arg0);
        func_00440b68(&iGpffffa890, D_0063FBB0, 413);
        func_002e0ea0((u8 *)D_0063FBC8, *(s16 *)((u8 *)out + 8));
    }
    return j;
}

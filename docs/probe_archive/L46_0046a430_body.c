/* Candidate reconstruction archived: allocator emitted a MISMATCH in scoped lverify; reverted per lane policy. */
u8 *func_0046a430(s32 arg0)
{
    s32 lock;
    u32 size;
    u32 candidate;
    u32 end;
    u32 base;
    u32 length;
    u32 finish;
    u32 i;
    u8 *entry;
    u8 *new_block;

    lock = func_0042ba20();
    size = ((u32)arg0 + 0xF) & ~0xF;
    candidate = iGpffffbb14 + iGpffffbb0c * 8;
retry:
    end = candidate + size;
    i = 0;
    while (i < iGpffffbb0c) {
        entry = (u8 *)iGpffffbb14 + i * 8;
        length = *(u32 *)(entry + 4);
        if (length != 0) {
            base = *(u32 *)entry;
            finish = base + length;
            if (candidate == base) {
                goto overlap;
            } else if (base < candidate) {
                if (candidate < finish) {
                    goto overlap;
                }
            } else if (finish < end) {
                goto overlap;
            } else if (base < end) {
                goto overlap;
            }
        }
        i++;
    }
    goto no_overlap;
overlap:
    candidate = finish;
    if (candidate + size >= iGpffffbb10) {
        func_00451b70();
        func_00440b68(D_00713078);
        func_0046d700((const char *)D_00713088, 0xFA,
                      (const char *)D_007130A0, iGpffffbb04, size,
                      func_004526e0(), D_00724BEC, D_00724BF0);
        func_0046d730(D_00713088, 0xFB);
    }
    goto retry;
no_overlap:
    i = 0;
    while (i < iGpffffbb0c) {
        entry = (u8 *)iGpffffbb14 + i * 8;
        if (*(u32 *)(entry + 4) == 0) {
            *(u32 *)entry = candidate;
            *(u32 *)(entry + 4) = size;
            iGpffffbb04 += size;
            goto allocated;
        }
        i++;
    }
    func_00440b68(D_00756758);
    func_0046d700((const char *)D_00756748, 0xB2,
                  (const char *)D_00756730, iGpffffbb04, size,
                  func_004526e0(), D_00724BEC, D_00724BF0);
    func_0046d730(D_00756720, 0xB3);
allocated:
    if (lock != 0) {
        func_0042ba70();
    }
    if (candidate + size >= iGpffffbb10) {
        func_00440b68(D_00713078);
        func_0046d700((const char *)D_00713088, 0xEC,
                      (const char *)D_007130A0, iGpffffbb04, size,
                      func_004526e0(), D_00724BEC, D_00724BF0);
    }
    return (u8 *)candidate;
}

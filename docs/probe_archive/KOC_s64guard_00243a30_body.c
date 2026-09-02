// FUN_00243A30
u16 func_00243a30(u8 *arg0, s32 *arg1)
{
    extern u32 func_00106330(s32 arg0);
    extern u32 func_003b7060(void);
    extern void func_0046d730(void *arg0, s32 arg1);
    u8 *entry;
    u16 result;
    s32 total;
    s32 count;
    s32 second_total;
    s32 i;
    u16 value;
    u8 *slot;
    u16 *field;

    if (!(*(u16 *)arg0 & 4)) {
        func_0046d730(D_00635938, 0x153F);
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x1540);
    }
    entry = iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C;
    result = 0;
    if (arg1 != 0) {
        *arg1 = 0;
    }
    if (*(u16 *)(entry + 0x34) != 0) {
        value = *(u16 *)(entry + 0x32);
        if (value != 0 && func_00106330(value) != 0 &&
            (s32)((func_003b7060() % 100U) & 0xFF) < (s32)*(u8 *)(entry + 0x36)) {
            result = *(u16 *)(entry + 0x34);
            if (arg1 != 0) {
                *arg1 = 1;
            }
        }
    }
    if (result == 0) {
        total = 0;
        i = 0;
        while ((u16)i < 4) {
            slot = entry + (u16)i * 4;
            value = *(u16 *)(slot + 0x22);
            if (value != 0 &&
                (value < 0x400 || value >= 0x500 ||
                 func_00106330(0x600 - value) == 0)) {
                total = (total + *(u8 *)(slot + 0x24)) & 0xFFFF;
            }
            i = (i + 1) & 0xFFFF;
        }
        count = total & 0xFFFF;
        if (!((s64)0 < count)) {
            goto done;
        }
        if ((s32)((func_003b7060() % 200U) & 0xFFFF) >= count) {
            goto done;
        }
        if (count == 0) {
            func_0046d730(D_00635938, 0x17);
        }
        total = func_003b7060() % (u32)count;
        second_total = 0;
        i = 0;
        while ((u16)i < 4) {
            slot = entry + (u16)i * 4;
            field = (u16 *)(slot + 0x22);
            value = *(u16 *)(slot + 0x22);
            if (value != 0 &&
                (value < 0x400 || value >= 0x500 ||
                 func_00106330(0x600 - value) == 0)) {
                second_total =
                    (second_total + *(u8 *)(slot + 0x24)) & 0xFFFF;
                if (total < second_total) {
                    result = *field;
                    goto done;
                }
            }
            i = (i + 1) & 0xFFFF;
        }
    }
done:
    return result;
}


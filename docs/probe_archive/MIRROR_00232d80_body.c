// Best body for func_00232d80 @0x00232d80 window 1312B
// probe clean_six: obj 1304/1312 nd 210 MISMATCH (six explicit blocks, honest u16/s16/s32+mask idiom, nested-if fallback)
// Status: ASM retained; archived per nd>25 gate. Leave func_002411a0 alone.
s32 func_00232d80(u8 *arg0)
{
    s32 acc;
    s32 temp_18;
    s32 var_5;
    u8 *base;
    s32 limit;
    s32 result;
    s32 found;

    acc = 0;
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1F9) {
            found = 1;
            goto done1;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1F9) {
                found = 1;
                goto done1;
            }
        }
    }
    found = 0;
done1:
    if (found != 0) {
        acc |= 1;
    }
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1FA) {
            found = 1;
            goto done2;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1FA) {
                found = 1;
                goto done2;
            }
        }
    }
    found = 0;
done2:
    if (found != 0) {
        acc |= 2;
    }
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1FB) {
            found = 1;
            goto done3;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1FB) {
                found = 1;
                goto done3;
            }
        }
    }
    found = 0;
done3:
    if (found != 0) {
        acc |= 4;
    }
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1FC) {
            found = 1;
            goto done4;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1FC) {
                found = 1;
                goto done4;
            }
        }
    }
    found = 0;
done4:
    if (found != 0) {
        acc |= 8;
    }
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1FD) {
            found = 1;
            goto done5;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1FD) {
                found = 1;
                goto done5;
            }
        }
    }
    found = 0;
done5:
    if (found != 0) {
        acc |= 0x10;
    }
    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (*(u16 *)(base + ((u16)var_5 * 2)) == 0x1FE) {
            found = 1;
            goto done6;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (func_001069a0((s16)result) == 0x1FE) {
                found = 1;
                goto done6;
            }
        }
    }
    found = 0;
done6:
    if (found != 0) {
        acc |= 0x20;
    }
    return acc;
}

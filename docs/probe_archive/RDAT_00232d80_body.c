/* object 1312 / window 1312 / normalized_diff 751 / differing offsets 0,4,8,10-... (see scoped fndiff) / exact-size but frame oversized by 16 bytes: candidate saves s3 in addition to retail s2,s1,s0; classification loop search/fallback dataflow retained a saved found/count local and shifted arg/result coloring; retail prologue frame 0x40, candidate frame 0x50. Tried direct goto, index-sentinel, block-scoped found, u8 found, inline fallback branch; no match. */
// FUN_00232D80
s32 func_00232d80(u8 *arg0)
{
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern s32 func_00106cd0(s16 arg0, s32 arg1);
    extern s32 func_001069a0(s16 arg0);
    s32 result;
    s32 count;
    u8 *table;
    s32 i;
    s32 skill;
    u8 found;

    result = 0;
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1F9) {
            found = 1;
            break;
        }
    }
    if (found != 0) result |= 1;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1F9) result |= 1;
    }
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1FA) { found = 1; break; }
    }
    if (found != 0) result |= 2;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1FA) result |= 2;
    }
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1FB) { found = 1; break; }
    }
    if (found != 0) result |= 4;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1FB) result |= 4;
    }
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1FC) { found = 1; break; }
    }
    if (found != 0) result |= 8;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1FC) result |= 8;
    }
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1FD) { found = 1; break; }
    }
    if (found != 0) result |= 0x10;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1FD) result |= 0x10;
    }
    count = func_0023e130(arg0) & 0xFFFF;
    table = func_0023e140(arg0);
    found = 0;
    for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
        if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x1FE) { found = 1; break; }
    }
    if (found != 0) result |= 0x20;
    else if (!(*(u16 *)arg0 & 4)) {
        skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
        if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x1FE) result |= 0x20;
    }
    return result;
}

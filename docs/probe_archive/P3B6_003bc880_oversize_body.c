/* object 336B/window 320B, normalized_diff 254; differing byte offsets begin 0,4,8,10-19 and continue through 332; classification object oversized, archive immediately. Integer ABI signature preserved because sibling callsites pass integer addresses: func_003bc880(s32,s32). Candidate reconstructed the found-entry count, dsll32/dsra32 s64 narrow idiom, func_003df240(result,&count,4), and func_003bc400 loop, but emitted a 0x70 frame versus retail 0x60 and diverged in saved-register/lifetime ordering. Updated file-scope func_003bc880 declaration remained s32,s32. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
s32 func_003bc880(s32 arg0, s32 arg1) {
    extern s32 func_003bc400(u8 *arg0, s32 arg1);
    s32 count;
    s32 index;
    s32 offset;
    s32 found;
    s32 result;
    s64 found64;
    u8 *work;
    u8 *entry;

    work = (u8 *)(u32)arg0;
    result = arg1;
    if (work == NULL) {
        return 0;
    }
    count = *(s32 *)work;
    if (count <= 0) {
        return 0;
    }
    found = 0;
    found64 = 0;
    index = 0;
    offset = 0;
    do {
        entry = *(u8 **)(work + 4) + offset;
        if (*(s32 *)(entry + 4) != 0) {
            found64 = (s64)(s32)found64 + 1;
            found = (s32)found64;
        }
        index += 1;
        offset += 0x10;
    } while (index < count);
    if ((s32)found64 == 0) {
        return result;
    }
    if (func_003df240(result, (s32)(u32)&found, 4) == 0) {
        return 0;
    }
    index = 0;
    offset = 0;
    do {
        entry = *(u8 **)(work + 4) + offset;
        if (*(s32 *)(entry + 4) != 0) {
            result = func_003bc400(entry, result);
        }
        index += 1;
        offset += 0x10;
    } while (index < count);
    return result;
}

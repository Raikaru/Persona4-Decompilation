/* Exact full-owner recovery: 356 executable bytes / 368B retail window.
 * All 16 relocations applied; twelve retail zero-tail bytes.
 * Requires cmmCommunity.c declarations, including s32 func_001077f0(s32).
 * The static inline clear helper emits no out-of-line symbol. */
static inline void CommunityFlags_Clear(s32 community)
{
    s32 id = community & 0xFFFF;
    s32 flag;
    if (id <= 0) {
        func_0046d730(D_005E42C8, 0x27);
    }
    for (flag = 0; flag < 13; flag++) {
        func_00106390(id + ((flag << 5) + 0x3FF), 0);
    }
}

// FUN_00106F40
void func_00106f40(s32 arg0) {
    u8 *record;
    s32 id;
    s32 rank;
    record = (u8 *)func_001070e0(arg0);
    id = arg0 & 0xFFFF;
    if (id <= 0) {
        func_0046d730(D_005E42C8, 0x48);
    }
    CommunityFlags_Clear(arg0);
    if (record == NULL) {
        return;
    }
    if (func_001077f0(arg0) != 0) {
        func_00106db0(arg0, 0);
        rank = *(u16 *)(record + 6);
        if (rank == 0xA) {
            func_00106db0(arg0, 1);
        } else {
            func_00106db0(arg0, rank + 3);
        }
    }
    if (func_00107c80(arg0) != 0) {
        func_00106db0(arg0, 2);
    }
    if (func_00107ea0(arg0) != 0) {
        func_00106db0(arg0, 3);
    }
}

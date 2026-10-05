static inline u16 *shuffleCandidateField(s32 offset, void *base)
{
    return (u16 *)((u8 *)base + offset);
}

#pragma push
#pragma opt_loop_invariants on
s32 func_0036f880(s32 arg0, u8 *arg1)
{
    u8 *list[12];
    union { u32 word; u16 skills[2]; } cand[8];
    s32 flag = arg0 & 0xFFFF;
    u16 count = func_0010b5b0();
    u8 *p;
    u16 *skills;
    u16 i;
    u16 n;
    u16 j;
    u16 nc;
    u16 m;
    u16 r;
    u8 *tbl;
    u16 first;
    u16 second;

    n = 0;
    if (count > 12) {
        func_0046d730(D_0064E790, 1207);
    }
    for (i = 0; i < count; i++) {
        if (func_0010abd0((s16)i) != 0) {
            list[n] = (u8 *)func_0010ace0((s16)i);
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    p = list[func_00231d70(n)];
    skills = datPersonaGetSkills((int)p);
    nc = 0;
    m = 0;
    tbl = iGpffffb3ec;
    for (; m < 8; m++) {
        if (skills[m] == 0) {
            continue;
        }
        j = 0;
        if (flag != 0) {
            u16 k;

            for (; skills[m] != *(u16 *)(tbl + j * 4) && *(u16 *)(tbl + j * 4) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4 + 2)) {
                    break;
                }
            }
            if (k >= 8) {
                cand[nc].skills[0] = *(u16 *)(tbl + j * 4);
                cand[nc].skills[1] = *(u16 *)(tbl + j * 4 + 2);
                nc++;
            }
        } else {
            u16 k;

            for (j = 0; skills[m] != *(u16 *)(tbl + j * 4 + 2) && *(u16 *)(tbl + j * 4 + 2) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4 + 2) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4)) {
                    break;
                }
            }
            if (k >= 8) {
                cand[nc].skills[0] = *(u16 *)(tbl + j * 4 + 2);
                cand[nc].skills[1] = *(u16 *)(tbl + j * 4);
                nc++;
            }
        }
    }
    if (nc == 0) {
        return 0;
    }
    r = func_00231d70(nc);
    second = *shuffleCandidateField(r * 4 + 2, cand);
    first = *shuffleCandidateField(r * 4, cand);
    func_0010cd70(p, (s16)first, second);
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 2);
    *(u16 *)(arg1 + 8) = first;
    *(u16 *)(arg1 + 6) = second;
    return 1;
}

#pragma pop

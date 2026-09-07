/* Full-owner exact recovery: 796 executable bytes / 800B retail window.
 * All 20 relocations resolved; one unreachable zero alignment word.
 * Requires cmmMisc.c types and helper declarations. The static GP pointer
 * binds to retail slot 0x007644C4, not a separate runtime table.
 * Natural s32 lifetimes reproduce both compiler-generated sq/lq spills. */
static u8 *iGpffffb3d4;
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern void func_0044ea90(void *, s32);

s32 func_00247900(s32 arg0, s32 arg1, s32 arg2) {
    s32 target;
    s32 threshold;
    s32 *left;
    s32 *right;
    s32 offset;
    s32 leftId;
    s32 rightId;
    s32 base;
    s32 id;
    s32 *list;
    s32 count;
    s32 capacity;
    s32 nextLevel;
    s32 nextId;
    s32 j;
    s32 i;
    s32 blocked;
    u16 flags;
    u8 level;

    target = (s8)func_00248760(arg0);
    nextLevel = 0;
    nextId = 0;
    list = 0;
    count = 0;
    capacity = 0;
    if (arg2 != -1) {
        capacity = func_00247900(arg0, arg1, -1);
        func_0044ea90(D_006359D0, 0x23A);
        list = (s32 *)D_008873F4[0](1, capacity * 4, 0x40000);
    }
    id = 1;
    threshold = arg1 & 0xFF;
    for (; id < 0x100; id++) {
        if (target == (func_00109280(id & 0xFFFF) & 0xFF)) {
            blocked = 1;
            base = (s32)iGpffffb3d4;
            offset = id * 14;
            flags = *(u16 *)((u32)base + offset);
            if (!(flags & 0x10) && !(flags & 8)) {
                blocked = 0;
            }
            if (blocked == 0 && (!(flags & 0x40) || ((func_00107ac0(arg0) & 0xFFFF) == 10))) {
                level = *(u8 *)((u32)iGpffffb3d4 + offset + 3);
                if (level <= threshold) {
                    if (list != 0) {
                        if (count >= capacity) {
                            func_0046d730(D_006359D0, 0x24A);
                        }
                        list[count] = id;
                    }
                    count++;
                } else if (nextLevel == 0 || level < nextLevel) {
                    nextLevel = level;
                    nextId = id;
                }
            }
        }
    }
    if (nextId != 0) {
        if (list != 0) {
            if (count >= capacity) {
                func_0046d730(D_006359D0, 0x25A);
            }
            list[count] = nextId;
        }
        count++;
    }
    if (list != 0) {
        for (i = 0; i < count; i++) {
            j = i + 1;
            left = &list[i];
            for (; j < count; j++) {
                base = (s32)iGpffffb3d4;
                right = &list[j];
                rightId = *right;
                leftId = *left;
                if (*(u8 *)((u32)base + leftId * 14 + 3) > *(u8 *)((u32)base + rightId * 14 + 3)) {
                    *left = rightId;
                    *right = leftId;
                }
            }
        }
        if (arg2 < count) {
            count = list[arg2];
        } else {
            count = 0;
        }
        jtbl_008873EC[0](list);
    }
    return count;
}

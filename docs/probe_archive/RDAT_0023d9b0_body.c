/* object 900 / window 992 / normalized_diff 648 / differing offsets 25-984 (first rows 25,28-46,52-984) / undersized by 92 bytes; prologue frame 0x50 and four saves matched but saved-register coloring was s3=offset/s1=arg0/s0=result vs retail s3=arg0/s0=offset/s1=result; classification control-flow/local allocation plus repeated GP mask-CSE residual; ruled-outs: direct m2c-shaped C body, swapped offset/result declaration order, block-scope callee prototypes. */
// FUN_0023D9B0
u32 func_0023d9b0(u8 *arg0, s32 arg1)
{
    extern u32 func_00231f80(u8 *arg0);
    extern u32 func_00232290(u8 *arg0);
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern s32 func_00106cd0(s16 arg0, s32 arg1);
    extern s32 func_001069a0(s16 arg0);
    extern void func_0046d730(void *arg0, s32 arg1);
    s32 offset;
    u32 result;
    s32 count;
    u8 *table;
    s32 i;
    s32 hit;

    if ((arg1 & 0xFFFF) >= 0x1B8) {
        func_0046d730(D_00635938, 0xEB4);
    }
    result = 0;
    offset = (arg1 & 0xFFFF) * 0x28;
    switch (*(u8 *)(iGpffffb3b8 + offset + 3)) {
    case 1:
        if (*(u16 *)arg0 & 4) {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xEBE);
            }
            return 0;
        }
        result = ((s32)(func_00231f80(arg0) & 0xFFFF) *
                  *(u16 *)(iGpffffb3b8 + offset + 4)) / 100;
        result += *(u16 *)(iGpffffb3b8 + offset + 6);
        count = func_0023e130(arg0) & 0xFFFF;
        table = func_0023e140(arg0);
        hit = 0;
        for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
            if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x20B) {
                hit = 1;
                break;
            }
        }
        if (hit == 0 && !(*(u16 *)arg0 & 4)) {
            s32 skill;
            skill = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
            if ((s16)skill >= 0 && func_001069a0((s16)skill) == 0x20B) {
                hit = 1;
            }
        }
        if (hit != 0) result >>= 1;
        if (result == 0) result = 1;
        break;
    case 2:
        if (*(u16 *)arg0 & 4) {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xED7);
            }
            if (*(u8 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 2) {
                return 0;
            }
        }
        if (!(*(u8 *)(iGpffffb3b8 + offset) & 0x10)) {
            result = *(u16 *)(iGpffffb3b8 + offset + 4);
            result += *(u16 *)(iGpffffb3b8 + offset + 6);
        } else {
            result = ((s32)(func_00232290(arg0) & 0xFFFF) *
                      *(u16 *)(iGpffffb3b8 + offset + 4)) / 100;
            result += *(u16 *)(iGpffffb3b8 + offset + 6);
        }
        if (result != 0) {
            count = func_0023e130(arg0) & 0xFFFF;
            table = func_0023e140(arg0);
            hit = 0;
            for (i = 0; (i & 0xFFFF) < (count & 0xFFFF); i++) {
                if (*(u16 *)(table + (i & 0xFFFF) * 2) == 0x20A) {
                    hit = 1;
                    break;
                }
            }
            if (hit == 0 && !(*(u16 *)arg0 & 4)) {
                s32 skill2;
                skill2 = func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF;
                if ((s16)skill2 >= 0 &&
                    func_001069a0((s16)skill2) == 0x20A) hit = 1;
            }
            if (hit != 0) result >>= 1;
            if (result == 0) result = 1;
        }
        break;
    }
    return result;
}

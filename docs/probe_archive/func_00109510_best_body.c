/* Best measured candidate: 688B object, 89 differing words (fndiff).
 * Retail saved-register list: $s1=arg0, $fp=arg1, $s6=arg2, $s0=table,
 * $s5=offset, $s4=span, $s3=count, $s2=outer index, $s7=skills.
 * Candidate used switch status CFG and a manual outer increment. */
extern s32 func_0010ceb0(u8 *arg0);

s32 func_00109510(u8 *arg0, s16 *arg1, s16 *arg2)
{
    u8 *table;
    s32 max;
    u8 offset;
    s32 lower;
    s32 upper;
    s32 total;
    s32 first;
    s32 haveFirst;
    s32 haveLast;
    s32 last;
    s32 i;
    u8 *entry;
    s32 n;
    s32 j;
    s32 count;
    u8 *skills;

    if (*(u16 *)(arg0 + 2) >= 0x100) {
        func_0046d730(D_005E4318, 0x132);
    }
    if (func_0010be20(arg0) != 0) {
        table = iGpffffb3e4 + (*(u16 *)(arg0 + 2) - 0xC0) * 0x26E + 4;
        max = 0x20;
        offset = 0;
        lower = *(u8 *)(arg0 + 4);
        upper = 0x63 - *(u8 *)(arg0 + 4);
    } else {
        u16 id = *(u16 *)(arg0 + 2);
        table = iGpffffb3dc + id * 0x46 + 6;
        max = 0x10;
        offset = *(u8 *)(iGpffffb3d4 + id * 0xE + 3);
        lower = *(u8 *)(arg0 + 4) - offset;
        upper = 0x63 - *(u8 *)(arg0 + 4);
    }
    total = lower + upper;
    first = 0;
    haveFirst = 0;
    haveLast = 0;
    last = 0;
    i = 0;
    for (; i < max; i++) {
        entry = table + i * 4;
        if (*(s8 *)(entry + 1) == 0) {
            break;
        }
        if (lower < *(u8 *)(entry + 0)) {
            if (haveFirst == 0) {
                haveFirst = 1;
                first = i;
                last = i;
            }
            if (total >= *(u8 *)(entry + 0)) {
                haveLast = 1;
                last = i;
            }
        }
    }
    if (haveLast != 0) {
        n = (last + 1) - first;
    } else {
        n = 0;
    }
    entry = table + first * 4;
    max = func_0010ceb0(arg0);
    count = 0;
    i = 0;
    for (; i < n;) {
        switch (*(s8 *)(entry + 1)) {
        case 1:
            j = 0;
            for (; j < max; j++) {
                if (*(u16 *)(entry + 2) == *(u16 *)(skills + j * 2)) {
                    break;
                }
            }
            if (j == max) {
                if (count >= 0x20) {
                    func_0046d730(D_005E4318, 0x17B);
                }
                arg1[count] = *(u16 *)(entry + 2);
                if (arg2 != NULL) {
                    arg2[count] = *(u8 *)(entry + 0) + offset;
                }
                count++;
            }
            break;
        default:
            break;
        }
        if (count == 0x20) {
            break;
        }
        i++;
        entry += 4;
    }
    return count & 0xFFFF;
}

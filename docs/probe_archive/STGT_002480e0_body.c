/* object 336/window 352/normalized_diff 223; differing offsets 0x0-0x15c (first 0x68); 4 instructions absent; classification undersized/register-pressure plus branch-layout; ruled out callee widths for func_00107a00/func_00108ee0 and direct scan transcription; no floor instruction observed. */
u16 func_002480e0(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 count;
    s32 i;
    s32 found;
    u16 id;
    s32 type;

    extern s32 func_00107a00(s32 idx, s32 arg1);
    extern u16 func_00108ee0(void);

    p = D_00881490[0] + 8;
    count = *(s32 *)(D_00881490[0] + 4);
    found = 0;
    i = 0;
    while (i < count) {
        if ((p[0] == arg1) && (p[1] == arg2)) {
            type = func_00107ac0(*(u16 *)(p + 2)) & 0xFFFF;
            if ((type >= *(u16 *)(p + 4)) &&
                (type <= *(u16 *)(p + 6)) &&
                ((func_00107ac0(*(u16 *)(p + 2)) & 0xFFFF) != 0xA) &&
                (func_00107a00(*(u16 *)(p + 2), 3) == 0) &&
                (*(u16 *)(p + 2) != (func_00108ee0() & 0xFFFF))) {
                found = 1;
            } else {
                found = 0;
            }
            if (found != 0) {
                if (i == arg0) {
                    id = *(u16 *)(p + 2);
                    return id;
                }
                found = 0;
            }
        }
        p += 8;
        i++;
    }
    return 0;
}

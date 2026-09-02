// FUN_0045C640 archive (wave Ko lane KoG, killed by provider rate limit mid-work; live state at cutoff, COMPILE_ERROR).
extern u8 D_008E3FD4[];
// FUN_0045C640
void func_0045c640(s16 index, s16 stream, s16 arg2, s16 arg3)
    s32 state;
    void *request;
    s32 *p;
    s32 r;

    off = index * 0x44;
    state = *(s16 *)&D_008E4090[off];
    if (state == 1) {
        request = *(void **)&D_008E40A8[off];
        if (request != 0) {
            p = (s32 *)&D_008E3FD0[stream * 0xC];
            if ((*p != 0) && (state == 1) && (request != 0) && (*p != 0)) {
                r = func_0043c5e8(*(s32 *)&D_008E40A0[off], 1, 0xA,
                                  *(s32 *)&D_008E3FD8[stream * 0xC]);
                switch (r) {
                case 0:
                case -0x12B:
                    func_0043c518(*(s32 *)&D_008E40A0[off], 2, 0xA,
                                  *(s32 *)&D_008E3FD8[stream * 0xC]);
                    break;
                default:
                    func_00440b68(D_00712458, r);
                    break;
                }
                *p = 0;
            }
            *(s16 *)&D_008E3FD4[stream * 0xC] = index;
            *p = 1;
            *(s32 *)&D_008E3FD8[stream * 0xC] = func_0043c518(
                *(s32 *)&D_008E40A0[off], 0, 0xA, (s32)arg2, (s32)arg3);
            return;
        }
        func_0046d740(D_00712470, D_00712408, 0x283);
        return;
    }
    func_0046d740(D_00712470, D_00712408, 0x286);
}
#pragma pop

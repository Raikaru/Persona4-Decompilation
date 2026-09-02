void func_0045c640(s16 index, s16 stream, s16 arg2, s16 arg3)
{
    s32 off;
    s32 state;
    void *request;
    s32 *p;
    s32 *q;
    s32 *h;
    s32 r;
    s32 soff;

    off = index * 0x44;
    state = *(s16 *)&D_008E4090[off];
    if (state != 1) {
        func_0046d740(D_00712470, D_00712408, 0x286);
        return;
    }
    request = *(void **)&D_008E40A8[off];
    if (request == 0) {
        func_0046d740(D_00712470, D_00712408, 0x283);
        return;
    }
    p = (s32 *)&D_008E3FD0[stream * 0xC];
    if ((*p != 0) && (state == 1) && (request != 0) && (*p != 0)) {
        q = (s32 *)&D_008E3FD8[stream * 0xC];
        h = (s32 *)&D_008E40A0[off];
        r = func_0043c5e8(*h, 1, 0xA, *q);
        if ((r == -0x12B) || (r == 0)) {
            func_0043c518(*h, 2, 0xA, *q);
        } else {
            func_00440b68(D_00712458, r);
        }
        *p = 0;
    }
    soff = stream * 0xC;
    *(s16 *)&D_008E3FD4[soff] = index;
    *p = 1;
    *(s32 *)&D_008E3FD8[soff] = ((s32 (*)(s32, s32, s32, s32, s32))func_0043c518)(
        *(s32 *)&D_008E40A0[off], 0, 0xA, (s32)arg2, (s32)arg3);
}

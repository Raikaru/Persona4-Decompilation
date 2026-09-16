/* BANKED floor func_00135130: obj 876B vs window 1008B (size-under), nd 227.
   See guard note in src/promoted/code1_0013.c for wins/walls/resume. */
void func_00135130(u8 *arg0, s64 arg1, s32 arg2, u8 *arg3)
{
    extern void func_002bc7a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                              s32 arg4, f32 fparg0, f32 fparg1, f32 fparg2);
    extern s32 func_001069d0();
    extern void func_0045d6e0(u8 *arg0, u8 *arg1, s32 arg2, f32 fparg0);
    s32 wbuf[4];
    f32 fa0;
    f32 fa4;
    u8 bbuf[4];
    f32 f20t;
    f32 f21v;
    f32 f23v;
    f32 f22v;
    s32 zd;
    PackedVec2f pv;

    fa0 = 5.0f + ((f32 *)&arg1)[0];
    fa4 = 27.0f + ((f32 *)&arg1)[1];
    if (*(s16 *)(arg3 + 22) == 3) {
        bbuf[0] = D_0064B2E0[0];
        bbuf[1] = D_0064B2E0[1];
        bbuf[2] = D_0064B2E0[2];
    } else {
        bbuf[0] = D_0064B2E0[0];
        bbuf[1] = D_0064B2E0[1];
        bbuf[2] = D_0064B2E0[2];
    }
    bbuf[3] = arg2;
    wbuf[0] = (s32)fa0;
    wbuf[1] = (s32)fa4;
    wbuf[2] = 470;
    wbuf[3] = 39;
    D_00887300[0](1, 0);
    func_0045d6e0(bbuf, (u8 *)wbuf, 0, 0.0f);
    f20t = 4.0f + fa0;
    f21v = 10.0f + fa4;
    func_0034f2e0(*(void **)(arg0 + 0x1548), f20t, f21v, bbuf[0], bbuf[1], bbuf[2], arg2);
    f23v = 41.0f + f21v;
    fa4 = f23v;
    func_0034f2e0(*(void **)(arg0 + 0x154C), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    f22v = 91.0f + f23v;
    func_0034f2e0(*(void **)(arg0 + 0x1550), fa0, f22v, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = (f32)0x1C9 + fa0;
    fa4 = f21v;
    func_0034f2e0(*(void **)(arg0 + 0x1554), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = 40.0f + fa0;
    fa4 = 2.0f + f23v;
    func_0034f2e0(*(void **)(arg0 + 0x1558), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = ((f32 *)&arg1)[0];
    fa4 = f20t;
    pv.packed = *(s64 *)&fa0;
    func_00135520(*(u8 **)(arg0 + 0x1560), pv, arg2, 3);
    fa0 = fa0 - 2.0f;
    fa4 = f20t;
    func_00112300(*(s64 *)&fa0, bbuf[0], (u8 *)arg3, 0.0f);
    fa0 = 128.0f + ((f32 *)&arg1)[0];
    fa4 = 32.0f + f20t;
    if ((func_00106880(*(s16 *)arg3) & 0x8000) != 0) {
        zd = 0;
    } else {
        zd = func_001069d0(*(s16 *)arg3) & 0xFFFF;
    }
    arg2 = (arg2 & 0xFF) | ~0xFF;
    func_002bc7a0(*(s32 *)(arg0 + 0x1548), arg2, 1, 6, 3,
                  (f32)(s32)fa0, (f32)(s32)fa4, 0.0f);
    fa0 = 179.0f + ((f32 *)&arg1)[0];
    fa4 = 81.0f + f20t;
    func_002bc4b0(*(s16 *)arg3, (s32)fa0, (s32)fa4, (arg2 & 0xFF) | ~0xFF, 1, 8, 0.0f);
}

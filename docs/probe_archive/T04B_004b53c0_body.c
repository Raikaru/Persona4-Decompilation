/* object 360/window 368/nd 14; differing instruction offsets [28,29,30,31,32,34,36,37,38,42,43,100,188,262]; deficit 0 instructions (8-byte zero tail remains); classification source-order/branch-layout/commutative-address residual; prologue saves s0/s1/s2, arg (u8 *); declarations: func_004b50f0 old-style block scope; setup4 and post handler pointers. */
u8 *func_004b53c0(u8 *arg0)
{
    u8 *work;
    u8 *base;
    s32 id;
    s32 off;
    s32 tex;
    s32 (*setup4)(s32, s32, s32, s32);
    void (*post)(u8 *);
    extern u8 *func_004b50f0();

    id = *(s32 *)(arg0 + 0x2C);
    base = iGpffffbba0;
    off = (base, id * 0x1C);
    if (*(s32 *)(base + off + 0xC) == 0) {
        tex = *(s32 *)(arg0 + 0x38);
        off = id & 0xFFFF;
        work = func_004b50f0(off, tex);
        if (iGpffffbba4() != 0) {
            off = (off & 0xFFFF) * 0x1C;
            base = iGpffffbba0;
            base += 4;
            base += off;
            setup4 = *(s32 (**)(s32, s32, s32, s32))base;
            if (setup4 != NULL) {
                *(s32 *)(work + 0x30) = setup4(tex, 0, 0, 0);
            }
            base = iGpffffbba0;
            base += off;
            post = *(void (**)(u8 *))base;
            if (post != NULL) {
                post(work);
            }
        }
    } else {
        work = func_004b50f0((id = id & 0xFFFF),
                             (id, *(s32 *)(arg0 + 0x38)));
        *(s32 *)(work + 0x30) =
            (*(s32 (**)(u8 *))((u8 *)((u32)(*(s32 *)(arg0 + 0x2C) * 0x1C) +
                                      (u32)iGpffffbba0 + 0xC)))(arg0);
        off = *(s32 *)(arg0 + 0x2C) * 0x1C;
        base = iGpffffbba0;
        base += off;
        post = *(void (**)(u8 *))base;
        if (post != NULL) {
            post(work);
        }
    }
    return work;
}

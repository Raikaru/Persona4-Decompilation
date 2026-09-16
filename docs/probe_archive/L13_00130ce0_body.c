/* Banked floor: object 1264B vs retail window 1488B (size-under), normalized_diff 317.
   trunc-idiom, reassign int->float, 30c30 family shapes, s64/u64 punning.
   Open: DSE-wall (dead v10/v10b), CSE-wall (fmul conv), arm-flip, s-map, union layout. */
void func_00130ce0(u8 *arg0, s64 arg1, s32 arg2, s16 *arg3)
{
    s64 a1s;
    f32 fa0;
    f32 fa4;
    union {
        f32 f;
        u8 b[8];
    } u;
    s64 t98;
    u8 c5;
    u8 c6;
    u8 c7;
    s32 tu0;
    s32 tu1;
    f32 fq;
    f32 f22;
    f32 f23;
    f32 fhi;
    f32 t204;
    f32 fa2;
    f32 fmul;
    s32 v8;
    s32 v10;
    s32 v10b;
    s32 vfin;

    a1s = arg1;
    fhi = ((f32 *)&a1s)[1];
    tu0 = *(u8 *)(arg0 + 0);
    if (tu0 >= 0) {
        fq = (f32)tu0;
    } else {
        tu0 = ((u32)tu0 >> 1) | (tu0 & 1);
        fq = (f32)tu0;
        fq += fq;
    }
    f22 = fq / 255.0f;
    u.b[4] = 0x14;
    u.b[5] = 0x14;
    u.b[6] = 0x14;
    t204 = 204.0f * f22;
    if (2147483648.0f <= t204) {
        v8 = (((s32)(t204 - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(t204) & 0xFF;
    }
    u.b[7] = v8;
    tu1 = *(u16 *)(arg0 + 0x15FE);
    if (tu1 >= 0) {
        f23 = (f32)tu1;
    } else {
        tu1 = ((u32)tu1 >> 1) | (tu1 & 1);
        f23 = (f32)tu1;
        f23 += f23;
    }
    fa0 = ((f32 *)&a1s)[0] - 1.0f;
    fa4 = 24.0f + fhi;
    if (2147483648.0f <= f23) {
        v10 = (((s32)(f23 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
    } else {
        v10 = (s32)(f23) & 0xFFFF;
    }
    c7 = u.b[7];
    c6 = u.b[6];
    c5 = u.b[5];
    func_0034f320(*(u8 **)(arg0 + 0x1BD4), fa0, fa4, 0.0f,
                  u.b[4], c5, c6, c7,
                  0x1000, 0, 0, 0.0f, 0);
    if (2147483648.0f <= f23) {
        v10b = (((s32)(f23 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
    } else {
        v10b = (s32)(f23) & 0xFFFF;
    }
    func_0034f320(*(u8 **)(arg0 + 0x1BD8), (f32)0x159 + fa0, fa4, 0.0f,
                  u.b[4], c5, c6, c7,
                  0x1000, 0, 0, 0.0f, 0);
    fa0 = 5.0f + ((f32 *)&a1s)[0] + *(f32 *)(arg0 + 0x1858);
    fa4 = 34.0f + fhi + *(f32 *)(arg0 + 0x185C);
    u.b[4] = 0x68;
    u.b[5] = 0x68;
    u.b[6] = 0x68;
    if (arg2 >= 0) {
        fa2 = (f32)arg2;
    } else {
        arg2 = ((u32)arg2 >> 1) | (arg2 & 1);
        fa2 = (f32)arg2;
        fa2 += fa2;
    }
    fmul = fa2 * f22;
    if (2147483648.0f <= fmul) {
        v8 = (((s32)(fmul - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(fmul) & 0xFF;
    }
    u.b[7] = v8;
    c7 = u.b[7];
    c6 = u.b[6];
    c5 = u.b[5];
    func_0034f2e0(*(void **)(arg0 + 0x1BCC), fa0, fa4,
                  u.b[4], c5, c6, c7);
    func_0034f2e0(*(void **)(arg0 + 0x1BD0), 330.0f + fa0, fa4,
                  u.b[4], c5, c6, c7);
    fa0 = ((f32 *)&a1s)[0];
    fa4 = fhi;
    u.b[4] = D_0064B2E8[0];
    u.b[5] = D_0064B2E8[1];
    u.b[6] = D_0064B2E8[2];
    t204 = 255.0f * f22;
    if (2147483648.0f <= t204) {
        v8 = (((s32)(t204 - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(t204) & 0xFF;
    }
    u.b[7] = v8;
    u.f = *(f32 *)&u.b[4];
    t98 = *(s64 *)&fa0;
    c7 = u.b[3];
    c6 = u.b[2];
    c5 = u.b[1];
    func_0034f2e0(*(void **)(arg0 + 0x1B60), *(f32 *)&t98,
                  *((f32 *)&t98 + 1), u.b[0], c5, c6, c7);
    func_0034f2e0(*(void **)(arg0 + 0x1B64), 340.0f + *(f32 *)&t98,
                  *((f32 *)&t98 + 1), u.b[0], c5, c6, c7);
    fa0 = fa0 - 2.0f;
    func_00112300(*(s64 *)&fa0, u.b[7], (u8 *)arg3, 0.0f);
    fa0 = 22.0f + ((f32 *)&a1s)[0];
    fa4 = 54.0f + fhi;
    if (2147483648.0f <= fmul) {
        vfin = (((s32)(fmul - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        vfin = (s32)(fmul) & 0xFF;
    }
    func_002bc4b0(*arg3, (s32)fa0, (s32)fa4, (vfin & 0xFF) | ~0xFF,
                  1, 8, 0.0f);
}

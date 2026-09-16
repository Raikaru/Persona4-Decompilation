/* BANKED floor func_00130680: obj ~1440B vs window 1456B (size-under), nd ~302.
   See guard note in src/promoted/code1_0013.c for wins/walls/resume. */
void func_00130680(u8 *arg0, s32 arg1)
{
    s16 t30;
    s32 b2;
    f32 f24g;
    s32 v23;
    s16 spd0;
    s32 spd8;
    s16 spd6;
    f32 f22;
    f32 f21;
    s32 tu0;
    f32 fq;
    f32 f23d;
    s32 t3;
    u8 *pb0;
    u8 *pb1;
    u8 *pb2;
    s32 i21;
    u8 *bb;
    f32 f20t;
    f32 f1t;
    s32 tu2;
    f32 fmul2;
    s32 mbyte;
    s32 s3v;
    u8 *pp;
    u8 *pp2;
    f32 f12t;
    f32 f13t;
    s32 dc;
    f32 s3f;
    f32 fmul3;
    s32 vfin;

    b2 = arg1 * 2;
    t30 = *(s16 *)(b2 + (s32)arg0 + 0x34);
    f24g = 1.0f;
    v23 = 0;
    func_0011fd30(&spd0);
    spd8 = 1;
    spd0 = t30;
    f22 = *(f32 *)(arg0 + 4);
    f21 = *(f32 *)(arg0 + 8);
    tu0 = *(u8 *)(arg0 + 0);
    if (tu0 >= 0) {
        fq = (f32)tu0;
    } else {
        tu0 = ((u32)tu0 >> 1) | (tu0 & 1);
        fq = (f32)tu0;
        fq += fq;
    }
    f23d = fq / 255.0f;
    t3 = *(s32 *)(arg0 + 0x14);
    if (((t3 & 0x10) != 0 && *(s16 *)(arg0 + 0x26) == arg1) || ((t3 & 0x20) != 0)) {
        v23 = 1;
        spd6 = 1;
        pb0 = D_0064B2E8;
        pb1 = &D_0064B2E8[4];
        pb2 = &D_0064B2E8[20];
    } else {
        spd6 = 0;
        pb0 = D_0064B2E0;
        pb1 = &D_0064B2E0[16];
        pb2 = &D_0064B2E0[40];
        f24g = fGpffff82cc;
    }
    i21 = arg1 * 0x30;
    bb = (u8 *)(i21 + (s32)arg0);
    f12t = 67.0f + (f22 + *(f32 *)(bb + 0x16D8));
    f20t = 75.0f * (f32)arg1;
    f13t = 24.0f + (f21 + *(f32 *)(bb + 0x16DC)) + f20t;
    tu2 = *(u8 *)(bb + 0x16E2);
    if (tu2 >= 0) {
        f1t = (f32)tu2;
    } else {
        tu2 = ((u32)tu2 >> 1) | (tu2 & 1);
        f1t = (f32)tu2;
        f1t += f1t;
    }
    fmul2 = f1t * f23d;
    if (!(2147483648.0f <= fmul2)) {
        mbyte = (s32)(fmul2) & 0xFF;
    } else {
        mbyte = ((s32)(fmul2 - 2147483648.0f)) | 0x80000000;
        mbyte &= 0xFF;
    }
    s3v = mbyte & 0xFF;
    func_0011fd50(*(s64 *)&f12t, mbyte & 0xFF, &spd0, 0, 0.0f);
    bb = (u8 *)(i21 + (s32)arg0);
    tu2 = *(u8 *)(bb + 0x1622);
    if (tu2 >= 0) {
        f1t = (f32)tu2;
    } else {
        tu2 = ((u32)tu2 >> 1) | (tu2 & 1);
        f1t = (f32)tu2;
        f1t += f1t;
    }
    fmul2 = f1t * f23d;
    if (!(2147483648.0f <= fmul2)) {
        mbyte = (s32)(fmul2) & 0xFF;
    } else {
        mbyte = ((s32)(fmul2 - 2147483648.0f)) | 0x80000000;
        mbyte &= 0xFF;
    }
    s3v = mbyte & 0xFF;
    pp = bb + 0x1618;
    f12t = 60.0f + (f22 + *(f32 *)(bb + 0x1618));
    pp2 = bb + 0x161C;
    f13t = 21.0f + (f21 + *(f32 *)(bb + 0x161C)) + f20t;
    func_0034f2e0(*(void **)(arg0 + 0x1B90), f12t, f13t,
                  pb0[0], pb0[1], pb0[2], s3v);
    if (v23 != 0) {
        f12t = 2.0f + (f22 + *(f32 *)(pp + 0));
        f13t = 27.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
        func_0034f2e0(*(void **)(arg0 + 0x1B94), f12t, f13t,
                      0x4C, 0x4C, 0x4C, s3v);
    }
    dc = func_00104c70(t30) & 0xFF;
    f12t = 43.0f + (f22 + *(f32 *)(pp + 0));
    f13t = 25.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
    if (dc < 0xA) {
        f12t = f12t - 11.0f;
    }
    while ((dc & 0xFF) > 0) {
        func_0034f2e0(*(void **)((s32)arg0 + (((dc & 0xFF) % 10) * 4) + 0x1BA4),
                      f12t, f13t, pb1[0], pb1[1], pb1[2], s3v);
        f12t = f12t - 22.0f;
        dc = ((u32)(dc & 0xFF) / 10U) & 0xFF;
    }
    f12t = 37.0f + (f22 + *(f32 *)(pp + 0));
    f13t = 53.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
    if (s3v >= 0) {
        s3f = (f32)s3v;
    } else {
        s3f = (f32)(((u32)s3v >> 1) | (s3v & 1));
        s3f += s3f;
    }
    fmul3 = s3f * f24g;
    if (!(2147483648.0f <= fmul3)) {
        vfin = (s32)(fmul3) & 0xFF;
    } else {
        vfin = ((s32)(fmul3 - 2147483648.0f)) | 0x80000000;
        vfin &= 0xFF;
    }
    func_0034f2e0(*(void **)(arg0 + 0x1BE0), f12t, f13t,
                  pb2[0], pb2[1], pb2[2], vfin);
}

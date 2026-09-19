#pragma opt_common_subs off
void func_0019c0d0(void)
{
    extern u32 func_00196610(u8 *arg0);
    extern void func_00230170(u8 *arg0);
    extern void func_0014b150(u16 arg0, u32 arg1);
    extern void func_001b70c0(u8 *arg0);
    extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
    extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
    extern void func_0047a180(void *arg0, void *arg1, s32 arg2);
    extern void func_00478e70(void *arg0);
    extern s32 func_001ee490(u8 *arg0);
    extern u32 func_0019d130(u8 *arg0);
    extern s32 func_001d72e0(s32 arg0);
    extern s16 func_001d7130(s32 arg0);
    extern void func_001d7400(s32 arg0, u8 *arg1);
    extern void func_001d7100(u8 *arg0, s16 arg1);
    extern void func_001d72c0(void *arg0, u32 arg1);
    extern void func_001d7140(u8 *arg0);
    extern f32 fGpffff81f4;
    s32 i;
    u8 *entry;
    i = 0;
    while ((u32)i < 4U) {
        entry = *(u8 **)(D_0076449C + (i * 8) + 0x17C);
        while (entry != NULL) {
            func_00196610(entry);
            func_00198380(entry);
            if (i == 2) {
                if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                    if (*(u16 *)(entry + 0x9FE) != 0) {
                        func_0014b150(*(u16 *)(entry + 0x9FE), (u32)(*(u8 *)(entry + 0xAC) == 1));
                    }
                }
            } else if (i == 1) {
                func_00230170(entry);
            }
            if ((*(s32 *)(entry + 0x98) & 2) != 0) {
                func_001b70c0(entry);
                {
                    u16 v = *(u16 *)entry;
                    if (((v & 3) == 0) || ((v & 4) != 0)) {
                        u8 t = *(u8 *)(entry + 0x37);
                        if (t != 0xFF) {
                            if (t < 0xDF) {
                                *(u8 *)(entry + 0x37) = (u8)(t + 0x20);
                            } else {
                                *(u8 *)(entry + 0x37) = 0xFF;
                            }
                            *(s32 *)(entry + 0x98) |= 4;
                        }
                    } else {
                        u8 base;
                        if ((v & 8) == 0) {
                            base = 0;
                        } else {
                            base = 0x58;
                        }
                        if ((u8)(base + 0x20) < *(u8 *)(entry + 0x37)) {
                            *(u8 *)(entry + 0x37) = (u8)(*(u8 *)(entry + 0x37) - 0x20);
                        } else {
                            *(u8 *)(entry + 0x37) = base;
                        }
                        *(s32 *)(entry + 0x98) |= 4;
                    }
                }
                if (*(u16 *)(entry + 0x4C) > 0) {
                    f32 ft;
                    f32 fdiv;
                    f32 f1;
                    u8 b48;
                    u8 b49;
                    u8 b4a;
                    ft = (f32)*(u16 *)(entry + 0x4C);
                    fdiv = ft / 8.0f;
                    b48 = *(u8 *)(entry + 0x48);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x44) - (s32)b48);
                    *(u8 *)(entry + 0x40) = (u8)((u32)b48 + (u32)f1);
                    b49 = *(u8 *)(entry + 0x49);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x45) - (s32)b49);
                    *(u8 *)(entry + 0x41) = (u8)((u32)b49 + (u32)f1);
                    b4a = *(u8 *)(entry + 0x4A);
                    f1 = fdiv * (f32)(s32)((s32)*(u8 *)(entry + 0x46) - (s32)b4a);
                    *(u8 *)(entry + 0x42) = (u8)((u32)b4a + (u32)f1);
                    *(s32 *)(entry + 0x98) |= 4;
                    *(u16 *)(entry + 0x4C) = (u16)(*(u16 *)(entry + 0x4C) - 1);
                }
                if ((*(s32 *)(entry + 0x98) & 4) != 0) {
                    f32 f14 = *(f32 *)(entry + 0x1C);
                    f32 f15 = *(f32 *)(entry + 0x20);
                    f32 f12 = *(f32 *)(entry + 0x24);
                    f32 f13 = *(f32 *)(entry + 0x28);
                    f32 xx = f14 * f14;
                    f32 yy = f15 * f15;
                    f32 zz = f12 * f12;
                    f32 yz = f15 * f12;
                    f32 zx = f12 * f14;
                    f32 xy = f14 * f15;
                    f32 wx = f13 * f14;
                    f32 wy = f13 * f15;
                    f32 wz = f13 * f12;
                    struct { struct { f32 x; f32 y; f32 z; } right; u32 flags; struct { f32 x; f32 y; f32 z; } up; u32 pad1; struct { f32 x; f32 y; f32 z; } at; u32 pad2; struct { f32 x; f32 y; f32 z; } pos; u32 pad3; } mat;
                    f32 sp[3];
                    u8 tmp[4];
                    mat.right.x = 1.0f - (yy + zz) * 2.0f;
                    mat.right.y = (xy + wz) * 2.0f;
                    mat.right.z = (zx - wy) * 2.0f;
                    mat.up.x = (xy - wz) * 2.0f;
                    mat.up.y = 1.0f - (xx + zz) * 2.0f;
                    mat.up.z = (yz + wx) * 2.0f;
                    mat.at.x = (zx + wy) * 2.0f;
                    mat.at.y = (yz - wx) * 2.0f;
                    mat.at.z = 1.0f - (xx + yy) * 2.0f;
                    mat.pos.x = 0;
                    mat.pos.y = 0;
                    mat.pos.z = 0;
                    mat.flags = 3;
                    func_0047a1c0(*(u8 **)(entry + 0xA00), &mat, 0);
                    sp[0] = sp[1] = sp[2] = *(f32 *)(entry + 0x2C);
                    func_0047a1e0(*(u8 **)(entry + 0xA00), sp, 2);
                    sp[0] = *(f32 *)(entry + 4) + *(f32 *)(entry + 0x10);
                    sp[1] = *(f32 *)(entry + 8) + *(f32 *)(entry + 0x14);
                    sp[2] = *(f32 *)(entry + 0xC) + *(f32 *)(entry + 0x18);
                    func_0047a180(*(u8 **)(entry + 0xA00), sp, 2);
                    {
                        tmp[1] = (u8)(s32)(fGpffff81f4 * (f32)*(u8 *)(entry + 0x31) * fGpffff81f4 * (f32)*(u8 *)(entry + 0x35) * 255.0f + 0.5f);
                        tmp[2] = (u8)(s32)(fGpffff81f4 * (f32)*(u8 *)(entry + 0x32) * fGpffff81f4 * (f32)*(u8 *)(entry + 0x36) * 255.0f + 0.5f);
                        tmp[3] = (u8)(s32)(fGpffff81f4 * (f32)*(u8 *)(entry + 0x33) * fGpffff81f4 * (f32)*(u8 *)(entry + 0x37) * 255.0f + 0.5f);
                        tmp[0] = (u8)(s32)(fGpffff81f4 * (f32)*(u8 *)(entry + 0x30) * fGpffff81f4 * (f32)*(u8 *)(entry + 0x34) * 255.0f + 0.5f);
                        tmp[1] = (u8)(s32)(fGpffff81f4 * (f32)tmp[1] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x3D) * 255.0f + 0.5f);
                        tmp[2] = (u8)(s32)(fGpffff81f4 * (f32)tmp[2] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x3E) * 255.0f + 0.5f);
                        tmp[3] = (u8)(s32)(fGpffff81f4 * (f32)tmp[3] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x3F) * 255.0f + 0.5f);
                        tmp[0] = (u8)(s32)(fGpffff81f4 * (f32)tmp[0] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x3C) * 255.0f + 0.5f);
                        tmp[1] = (u8)(s32)(fGpffff81f4 * (f32)tmp[1] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x41) * 255.0f + 0.5f);
                        tmp[2] = (u8)(s32)(fGpffff81f4 * (f32)tmp[2] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x42) * 255.0f + 0.5f);
                        tmp[3] = (u8)(s32)(fGpffff81f4 * (f32)tmp[3] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x43) * 255.0f + 0.5f);
                        tmp[0] = (u8)(s32)(fGpffff81f4 * (f32)tmp[0] * fGpffff81f4 * (f32)*(u8 *)(entry + 0x40) * 255.0f + 0.5f);
                    }
                    if (tmp[3] < 0xFE) {
                        if (i != 2) {
                            *(s32 *)(*(u8 **)(entry + 0xA00) + 0xE8) = 0x737FB;
                            func_0019d7a0(entry, 2);
                            func_0019d7a0(entry, 5);
                        }
                    } else {
                        tmp[3] = 0xFF;
                        *(s32 *)(*(u8 **)(entry + 0xA00) + 0xE8) = 0x737FB;
                        func_0019d990(entry, 2);
                        func_0019d990(entry, 5);
                    }
                    {
                        u8 *obj = *(u8 **)(entry + 0xA00);
                        if (*(s32 *)(obj + 0xE8) != 0x737FB) {
                            s32 j;
                            *(s32 *)(obj + 0xE8) = 0x737FB;
                            for (j = 0; j < 5; j++) {
                                u8 *objR = *(u8 **)(entry + 0xA00);
                                u8 *sub = *(u8 **)(objR + (j * 0xC) + 0x290);
                                if (sub != NULL) {
                                    *(s32 *)(sub + 0xE8) = 0x737FB;
                                }
                            }
                        }
                    }
                    *(u8 *)(entry + 0x4E) = tmp[0];
                    *(u8 *)(entry + 0x4F) = tmp[1];
                    *(u8 *)(entry + 0x50) = tmp[2];
                    *(u8 *)(entry + 0x51) = tmp[3];
                    func_0047a220(*(u8 **)(entry + 0xA00), (s32 *)tmp);
                    func_001ee490(entry);
                    *(s32 *)(entry + 0x98) &= ~4;
                }
                if ((*(s32 *)(*(u8 **)(entry + 0xA00) + 0xD8) & 4) != 0) {
                    func_00478e70(*(u8 **)(entry + 0xA00));
                }
                if ((*(s32 *)(entry + 0xA04) != 0) && (func_0019d130(entry) != 0)) {
                    u8 *p = *(u8 **)(entry + 0xA64);
                    if (p != NULL) {
                        s32 v = *(s32 *)(p + 0xC);
                        s32 hi = (s32)((((s64)(v << 12)) >> 44) & 0xFFFFFFFF);
                        s32 chk = func_001d72e0(hi >> 12);
                        s16 cur = func_001d7130(*(s32 *)(entry + 0xA04));
                        if ((s16)chk != cur) {
                            func_001d7400((u32)hi >> 12, entry + 0x48);
                            *(u8 *)(entry + 0x44) = *(u8 *)(entry + 0x40);
                            *(u8 *)(entry + 0x45) = *(u8 *)(entry + 0x41);
                            *(u8 *)(entry + 0x46) = *(u8 *)(entry + 0x42);
                            *(u8 *)(entry + 0x47) = *(u8 *)(entry + 0x43);
                            *(u16 *)(entry + 0x4C) = 8;
                            func_001d7100(*(u8 **)(entry + 0xA04), (s16)chk);
                        }
                    }
                    func_001d72c0(*(u8 **)(entry + 0xA04), *(u32 *)(entry + 0x4E));
                    func_001d7140(*(u8 **)(entry + 0xA04));
                }
            }
            entry = *(u8 **)(entry + 0xA68);
        }
        i += 1;
    }
}
#pragma opt_common_subs on

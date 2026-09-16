// func_00467bd0 (0x00467bd0-0x004680c0, 1264B) — guarded floor @277fndiff/976B (288B under).
// Wins: full case coverage (0/1/2/4 + string loops + float/tmp + case-4); w-s32-offset idiom;
// iGpffffb021/025/029 registered (array form, HI/LO relocs); if/else beq-chain; u16 counters;
// 4426e8/442088/4673c0/467880/4688d0/468940/453670/3860/3960 calls.
// Walls: CSE base-hoist (D_00800000+w into s2 + s1=base+off; 25-use respell-rotation neutral);
// D_00800000/D_008C0276 ABSOLUTE-vs-reloc phantoms (~20 rows); iGp HI/LO-vs-GPREL phantoms;
// st==2 bne (long-forward); frame -0xA0 vs -0x170 (fewer spills; tmp[64] only).
// Unattempted before (no prior note). Production stays ASM.
s32 func_00467bd0(u8 *arg0)
{
    s32 w;
    s16 st;
    u16 i;
    u16 k;
    s16 h1;
    s16 h2;
    s32 e;
    s32 v;

    w = *(s32 *)(arg0 + 56);
    st = *(s16 *)(D_00800000 + w + 3968);
    if (st == 4) {
    } else if (st == 3) {
    } else if (st == 2) {
        if ((D_008C0276 & 0x40) != 0) {
            h1 = *(s16 *)(D_00800000 + w + 3970);
            h2 = *(s16 *)(D_00800000 + w + 3972);
            e = w + (h1 + h2) * 264;
            v = *(s32 *)(e + 512);
            if (v == 1) {
                if (func_004426e8((const char *)iGpffffb021, (const char *)(e + 256)) != 0) {
                    if (func_004426e8((const char *)iGpffffb025, (const char *)(w + (h1 + h2) * 264 + 256)) == 0) {
                        *(s16 *)(D_00800000 + w + 3968) = 1;
                        return 0;
                    }
                    func_00442088((char *)w, (const char *)iGpffffb029, (char *)w, (char *)(w + (h1 + h2) * 264 + 256));
                    *(s16 *)(D_00800000 + w + 3968) = 1;
                    return 0;
                }
                i = 0;
                while (((i & 0xFFFF)) < 256) {
                    if (*(u8 *)(w + (i & 0xFFFF)) == 0) {
                        break;
                    }
                    i = (i + 1) & 0xFFFF;
                }
                k = i & 0xFFFF;
                while (((k & 0xFFFF)) >= 2) {
                    u8 *p = (u8 *)(w + (k & 0xFFFF));
                    if (*p == 47) {
                        if (*(p - 1) != 58) {
                            *(u8 *)(w + (k & 0xFFFF)) = 0;
                        } else {
                            *(p + 1) = 0;
                        }
                        break;
                    }
                    k = (k - 1) & 0xFFFF;
                }
                *(s16 *)(D_00800000 + w + 3968) = 1;
                return 0;
            }
            if (v == 0) {
                *(s32 *)(D_00800000 + w + 3976) = 1;
                func_00442088((char *)(w + 3984), (const char *)iGpffffb029, (char *)w, (char *)(w + (h1 + h2) * 264 + 256));
                *(s16 *)(D_00800000 + w + 3968) = 3;
                return 0;
            }
        } else if ((D_008C0276 & 0x10) == 0) {
            if ((D_008C0276 & 0x80) != 0) {
                {
                    f32 f1 = 48.0f;
                    f32 f2 = 248.0f;
                    *(u8 **)(D_00800000 + w + 3984) = func_00468940((s64)f1, st);
                    *(s16 *)(D_00800000 + w + 3968) = 4;
                }
            } else if ((D_008C0276 & 0x20) != 0) {
                *(s32 *)(D_00800000 + w + 3976) = 0;
                *(s16 *)(D_00800000 + w + 3968) = 3;
                return 0;
            } else {
                {
                    u8 tmp[64];
                    func_00453670(tmp, 10, *(s16 *)(D_00800000 + w + 3974), *(s16 *)(D_00800000 + w + 3970), *(s16 *)(D_00800000 + w + 3972));
                    func_00453860(tmp, 0x4000, 0x1000, 0x2000, 0x8000);
                    if (func_00453960(tmp) != 0) {
                        *(s16 *)(D_00800000 + w + 3970) = *(s16 *)(tmp + 24);
                        *(s16 *)(D_00800000 + w + 3972) = *(s16 *)(tmp + 28);
                    }
                }
            }
        }
        func_00467880((u8 *)w);
    } else if (st == 4) {
        {
            u8 flag;
            if (func_004688d0(*(u8 **)(D_00800000 + w + 3984), &flag, st) != 0) {
                if (flag == 0) {
                    *(s16 *)(D_00800000 + w + 3968) = 2;
                } else {
                    *(s32 *)(D_00800000 + w + 3976) = 1;
                    func_00442088((char *)(w + 3984), (const char *)iGpffffb029, (char *)w, &flag);
                    *(s16 *)(D_00800000 + w + 3968) = 3;
                }
            }
            func_00467880((u8 *)w);
        }
    } else if (st == 1) {
        func_004673c0((u8 *)w);
        *(s16 *)(D_00800000 + w + 3972) = 0;
        *(s16 *)(D_00800000 + w + 3970) = 0;
        *(s16 *)(D_00800000 + w + 3968) = 2;
    } else if (st == 0) {
        *(s16 *)(D_00800000 + w + 3968) = 1;
    }
    return 0;
}

// FUN_00148280
s32 func_00148280(u8 *unusedTask) {
    /* Retail returns zero at 001495E8, 00148318. */
    extern void func_00152930(u8 *arg0, u8 *arg1);
    extern void func_00152bb0(u8 *arg0, u8 *arg1);
    extern void func_00152cd0(u8 *arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, void *arg1);
    extern s32 func_00462df0(s32 arg0);
    extern s32 func_00462e80(s32 arg0);
    extern void func_00479100(void *arg0, void *arg1);
    extern u8 *mdlGetColor(s32 arg0);
    extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
    extern void func_004b11d0(void *arg0, void *arg1);
    extern void qsort(void *arg0, u32 arg1, s32 arg2, void *arg3);
    extern s32 func_0014a160(void);
    extern u8 D_005DC7D0[];
    extern u8 D_005DC824[];
    extern u8 D_005EFB00[];
    extern u8 D_00793E80[];
    extern u8 D_00793EE0[];
    extern u8 D_00793F10[];
    extern u8 D_00793F40[];
    extern u8 D_00793F70[];
    extern u8 D_007942D0[];
    extern u8 D_00794300[];
    extern u8 D_00794360[];
    extern u8 D_00794390[];
    extern u8 D_007943F0[];
    extern u8 D_007945A0[];
    extern u8 D_007945D0[];
    extern u8 D_007947E0[];
    extern u8 D_007D1F30[];
    extern u8 D_007D1FE0[];
    extern u8 D_007D2090[];
    extern u8 D_007D2140[];
    extern u8 D_007D21F0[];
    extern u8 D_007D22A0[];
    extern u8 D_007D2350[];
    extern u8 D_007D2400[];
    u8 *arrA[64];
    u8 *arrB[64];
    RwV3d pos;
    u8 *l12;
    u8 *l10;
    u8 *l11;
    u8 *l1;
    u8 *l3;
    u8 *l2;
    s32 flag;
    s32 flag2;
    s32 flag3;
    u32 n1;
    s32 n2;
    s32 dn1;
    u8 *tmp;
    u8 *e;
    u8 *ex;
    s32 t;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 nn;
    u8 *cur;

    l12 = func_001452b0(0xC);
    l10 = func_001452b0(0xA);
    l11 = func_001452b0(0xB);
    l1 = func_001452b0(1);
    l3 = func_001452b0(3);
    l2 = func_001452b0(2);
    flag = 0;
    if (D_007642E4 == 1) {
        return 0;
    }
    if (*(s32 *)iGpffff9db0 >= 0xC8) {
        flag = 1;
    }
    while (l11 != NULL) {
        if (*(s32 *)(l11 + 0x28) & 2) {
            func_004b1210(D_005DC7D0, *(void **)(l11 + 0x144));
        }
        l11 = *(u8 **)(l11 + 0x138);
    }
    while (l12 != NULL) {
        if (*(s32 *)(l12 + 0x28) & 2) {
            func_00152930(D_00793EE0, *(u8 **)(l12 + 0x1A0));
            if (flag != 0) {
                func_00152bb0(D_00793F70, *(u8 **)(l12 + 0x1A0));
                func_00152cd0(D_00793F70, *(u8 **)(l12 + 0x1A0));
            } else {
                func_00152bb0(D_00794390, *(u8 **)(l12 + 0x1A0));
                func_00152cd0(D_00794390, *(u8 **)(l12 + 0x1A0));
            }
        }
        l12 = *(u8 **)(l12 + 0x138);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D22A0;
    if (flag != 0) {
        func_00460ac0(D_00793F40, tmp);
    } else {
        func_00460ac0(D_00794360, tmp);
    }
    while (l10 != NULL) {
        t = *(s32 *)(l10 + 0x28);
        if (t & 2) {
            if (t & 0x02000000) {
                func_00479100(D_007942D0, *(void **)(l10 + 0x144));
            } else if (t & 0x01000000) {
                func_00479100(D_007947E0, *(void **)(l10 + 0x144));
            } else if (func_00462e80(*(s32 *)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    func_00479100(D_00793F10, *(void **)(l10 + 0x144));
                } else {
                    func_00479100(D_00794300, *(void **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00794300, ex);
                }
            } else if (func_00462df0(*(s32 *)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    func_00479100(D_00793F40, *(void **)(l10 + 0x144));
                } else {
                    func_00479100(D_00794360, *(void **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00794360, ex);
                }
            } else {
                func_00479100(D_00793EE0, *(void **)(l10 + 0x144));
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00793EE0, ex);
                }
            }
        }
        l10 = *(u8 **)(l10 + 0x138);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D22A0;
    if (flag != 0) {
        func_00460ac0(D_00793F40, tmp);
    } else {
        func_00460ac0(D_00794360, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    memset(arrA, 0, 0x100);
    n1 = 0;
    while (l1 != NULL) {
        if (n1 >= 0x40) {
            func_0046d730(D_005EFB00, 0x264);
        }
        arrA[n1] = l1;
        l1 = *(u8 **)(l1 + 0x138);
        n1 += 1;
    }
    if (*(s32 *)(iGpffff9db0 + 0x14) == 1) {
        qsort(arrA, n1, 4, (void *)func_00148000);
    }
    flag2 = 0;
    for (i = (s32)(n1 - 1); i >= 0; i--) {
        u8 **pp = &arrA[i];
        s32 flags = *(s32 *)(*pp + 0x28);

        if (flags & 2) {
            if (flags & 0x04000000) {
                flag2 = 1;
            } else {
                s32 j;

                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147bb0;
                *(u8 **)(tmp + 0x10) = *pp;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                if (func_0014a160() == 1 && (*(u16 *)*pp & 0x3FF) >= 100) {
                    func_00479100(D_007943F0, *(void **)(*pp + 0x164));
                } else {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(void **)(*pp + 0x164));
                }
                if (*(u8 **)(*pp + 0x228) != NULL && (*(s32 *)(*pp + 0x28) & 0x20000000)) {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*pp + 0x228));
                }
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(*pp + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(*pp + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)(mdlGetMatrix(*(s32 *)(*pp + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(s32 *)(*pp + j * 4 + 0x140), (u8 *)&pos);
                        func_004b11d0(D_005DC824, *(void **)(*pp + j * 4 + 0x140));
                    }
                }
            }
        }
    }
    if (flag2 == 1) {
        u8 *obj = func_001452b0(1);

        while (obj != NULL) {
            if (!(*(s32 *)(obj + 0x28) & 0x04000000)) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147910;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147bb0;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), *(void **)(obj + 0x164));
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147ae0;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (l3 != NULL) {
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_00147d80;
        *(u8 **)(tmp + 0x10) = NULL;
        func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    }
    memset(arrB, 0, 0x100);
    n2 = 0;
    while (l3 != NULL) {
        if (*(u8 *)(mdlGetColor(*(s32 *)(l3 + 0x164)) + 3) < 0xFF) {
            arrB[n2] = l3;
            n2 += 1;
            l3 = *(u8 **)(l3 + 0x138);
        } else {
            s32 flags = *(s32 *)(l3 + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                s32 j;

                func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(void **)(l3 + 0x164));
                if (*(u8 **)(l3 + 0x22C) != NULL && (*(s32 *)(l3 + 0x28) & 0x20000000)) {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l3 + 0x22C));
                }
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(l3 + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(l3 + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)(mdlGetMatrix(*(s32 *)(l3 + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(s32 *)(l3 + j * 4 + 0x140), (u8 *)&pos);
                        func_004b11d0(D_005DC824, *(void **)(l3 + j * 4 + 0x140));
                    }
                }
            }
            l3 = *(u8 **)(l3 + 0x138);
        }
    }
    {
        u8 *obj = func_001452b0(3);

        while (obj != NULL) {
            if (*(u8 *)(mdlGetColor(*(s32 *)(obj + 0x164)) + 3) < 0xFF) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                s32 flags = *(s32 *)(obj + 0x28);

                if ((flags & 0x10000000) && (flags & 2)) {
                    tmp = func_00460990();
                    *(void **)(tmp + 8) = (void *)func_00147e60;
                    *(u8 **)(tmp + 0x10) = obj;
                    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                    if (*(s32 *)(obj + 0x28) & 0x80000000) {
                        s32 j;

                        func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(void **)(obj + 0x164));
                        if (*(u8 **)(obj + 0x22C) != NULL && (*(s32 *)(obj + 0x28) & 0x20000000)) {
                            func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(obj + 0x22C));
                        }
                        for (j = 0; j < 2; j++) {
                            if (*(s32 *)(obj + j * 4 + 0x140) != 0) {
                                if (func_0047a6d0(*(void **)(obj + 0x164), 2, &pos) == 0) {
                                    pos = *(RwV3d *)(mdlGetMatrix(*(s32 *)(obj + 0x164)) + 0x30);
                                    pos.y += 175.0f;
                                }
                                func_004b1250(*(s32 *)(obj + j * 4 + 0x140), (u8 *)&pos);
                                func_004b11d0(D_005DC824, *(void **)(obj + j * 4 + 0x140));
                            }
                        }
                    }
                }
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    flag3 = 0;
    while (l2 != NULL) {
        s32 flags = *(s32 *)(l2 + 0x28);

        if (flags & 2) {
            if (flags & 0x04000000) {
                flag3 = 1;
                continue;
            }
            if (flags & 0x10000) {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(void **)(l2 + 0x158));
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0(D_007945A0, tmp);
                func_00479100(D_007945A0, *(void **)(l2 + 0x158));
            }
        }
        l2 = *(u8 **)(l2 + 0x138);
    }
    if (flag3 == 1) {
        u8 *obj = func_001452b0(2);

        while (obj != NULL) {
            if (!(*(s32 *)(obj + 0x28) & 0x04000000)) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147910;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), *(void **)(obj + 0x158));
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147ae0;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (*(s32 *)(iGpffff9db0 + 0x18) == 1) {
        qsort(arrB, n2, 4, (void *)func_00148140);
    }
    if (n2 != 0) {
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_00147d80;
        *(u8 **)(tmp + 0x10) = NULL;
        func_00460ac0(D_007945D0, tmp);
    }
    {
        s32 j;
        s32 k;

        for (k = n2 - 1; k >= 0; k--) {
            s32 flags = *(s32 *)(arrB[k] + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                func_00479100(D_007945D0, *(void **)(arrB[k] + 0x164));
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(arrB[k] + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(arrB[k] + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)(mdlGetMatrix(*(s32 *)(arrB[k] + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(s32 *)(arrB[k] + j * 4 + 0x140), (u8 *)&pos);
                    }
                }
            }
        }
    }
    {
        s32 j;
        s32 k;

        for (k = n2 - 1; k >= 0; k--) {
            s32 flags = *(s32 *)(arrB[k] + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && (flags & 0x80000000)) {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147e60;
                *(u8 **)(tmp + 0x10) = arrB[k];
                func_00460ac0(D_007945D0, tmp);
                func_00479100(D_007945D0, *(void **)(arrB[k] + 0x164));
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(arrB[k] + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(arrB[k] + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)(mdlGetMatrix(*(s32 *)(arrB[k] + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(s32 *)(arrB[k] + j * 4 + 0x140), (u8 *)&pos);
                    }
                }
            }
        }
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    return 0;
}

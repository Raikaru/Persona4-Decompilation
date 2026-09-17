/* func_002818e0 floor (measured 2026-09-17, source-repo): probe base 485w, fnalign 601/594/179 (+47), emitted 2376B/2416B (98.3%%). Four sweeps base wins. Residual FPU/saved coloring. See itfMsgProcedure_Window.c guard. */
s32 func_002818e0(u8 *arg0, s32 arg1)
{
    s32 ret;
    s32 *tmp;
    s32 tmpw;
    s32 *tmp3;
    s16 cnt;
    s32 cnt32;
    float f;
    float f2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 i;
    MsgProcWindowEntry *e;
    void *pv1;
    void *pv2;

    func_00278110();
    ret = 0;
    switch (arg1) {
    case 0:
        func_00278170(arg0, 0x4000000);
        func_00278170(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        if ((void *)D_00882040 == NULL) {
            func_0046d730(D_0063BFC0, 0x18F);
        }
        func_0043f9c8(D_00882040, 0, 0x18);
        tmp = func_0027be60(arg0);
        if (tmp == NULL) {
            func_0044ea90(D_0063BFC0, 0x5C0);
            pv1 = D_008873F4[0](1, 8, 0x40000);
            func_0027be90(arg0, pv1);
        }
        break;
    case 1:
        tmp = func_0027be60(arg0);
        if (tmp != NULL) {
            jtbl_008873EC[0](tmp);
            func_0027be90(arg0, NULL);
        }
        break;
    case 4:
        if (func_0027bec0(arg0) != 0) {
            if ((D_00882040[0] & 2) == 0) {
                D_00882040[0] = D_00882040[0] | 2;
                D_00882044[0] = 0;
            }
            cnt = D_00882044[0] + 1;
            D_00882044[0] = cnt;
            cnt32 = (s32)cnt;
            if (cnt32 < 5) {
                f = func_0044b7b0(iGpffff81dc + (iGpffff8084 * (float)cnt32) / 4.0f);
                f = (f + 1.0f) / 2.0f;
                a0 = (s32)((1.0f - f) * 200.0f + 70.0f);
                a1 = (s32)(47.0f - (1.0f - f) * 5.0f);
                a2 = (s32)(f * 404.0f);
                a3 = (s32)(20.0f - f * 15.0f);
                func_00366380(a0, a1, a2, a3, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            } else if (cnt32 < 11) {
                f = func_0044b7b0((iGpffff8094 * (float)(cnt32 - 4)) / 6.0f);
                a1 = (s32)((1.0f - f) * 20.0f + 27.0f);
                a3 = (s32)(f * 50.0f + 5.0f);
                func_00366380(0x46, a1, 0x194, a3, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            }
            if (cnt32 < 6) {
                f2 = func_0044b7b0((iGpffff8094 * (float)cnt32) / 5.0f);
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, f2, 1.0f, (void *)D_00796490);
            } else {
                func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            }
            if (cnt32 > 3 && cnt32 < 11) {
                tmp = func_0027be60(arg0);
                if (tmp != NULL) {
                    f = func_0044b7b0((iGpffff8094 * (float)(cnt32 - 3)) / 7.0f);
                    tmpw = func_002bd1e0(*tmp);
                    f2 = 9.0f - (1.0f - f) * 60.0f;
                    func_0025ecd0(f2, 1.0f, 0.0f, 0xFFFFFF, (u8)0xFF, 0, (void *)tmpw, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
                }
            }
            if (cnt32 > 9) {
                D_00882040[0] = D_00882040[0] & 0xFFFFFFFD;
                D_00882044[0] = 0;
                ret = 1;
            }
        }
        break;
    case 5:
        if (func_0027bec0(arg0) != 0) {
            func_00366380(0x46, 0x1B, 0x194, 0x37, 0, 0xB2, 1, 0, 0, (void *)D_00796490, 0.0f, 0.0f, 1.0f, 1.0f);
            func_0027d3c0(0x47, 0x40, 0.0f, 0x36, 0x96FF02, 0xFF, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            tmp = func_0027be60(arg0);
            if (tmp != NULL) {
                tmpw = func_002bd1e0(*tmp);
                func_0025ecd0(9.0f, 1.0f, 0.0f, 0xFFFFFF, (u8)0xFF, 0, (void *)tmpw, 1, 0, 0, 0.0f, 1.0f, 1.0f, (void *)D_00796490);
            }
        }
        ret = 1;
        break;
    case 6:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 7:
        e = NULL;
        for (i = 0; i < 8; i++) {
            e = &D_008820B0[i];
            if ((e->field0 & 1) == 0) {
                goto found;
            }
        }
        e = NULL;
found:
        if (e != NULL) {
            func_0043f9c8(e, 0, 0x18);
            e->field0 = e->field0 | 1;
            e->field8 = 0;
            e->fieldC = 0;
            e->field4 = 5;
        }
        break;
    case 8:
        pv1 = (void *)func_00278fd0(arg0);
        if (pv1 != NULL) {
            func_00272a10(pv1, 10.0f, 90.0f);
            func_002728c0(pv1, 0);
            func_00272b00(pv1, 2);
        }
        pv2 = (void *)func_00278fb0(arg0);
        if (pv2 != NULL) {
            func_00272a10(pv2, 141.0f, 25.0f);
            func_002728c0(pv2, 1);
            func_00272b50(pv2, 0, 0);
            func_00272730(pv2, 0x20);
            func_002727a0(pv2, 0);
        }
        ret = 1;
        break;
    case 9:
        ret = 1;
        break;
    case 10:
        pv1 = (void *)func_00278ff0(arg0);
        if (pv1 != NULL) {
            func_002728c0(pv1, 0);
        }
        break;
    case 11:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 13:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 16:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 17:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 18:
        func_0027bec0(arg0);
        ret = 1;
        break;
    }
    return ret;
}

/* func_002848c0 floor (measured 2026-09-17, source-repo): probe plain 189 / loop 182 WINNER, fnalign 522/519/52 (+114), emitted 2076B/2096B (99.05%%). measured loop_invariants worth 7w/2ed. Residual register/branch-form only. See itfMsgProcedure_Window.c guard. */
#pragma opt_loop_invariants on
s32 func_002848c0(void *arg0, s32 arg1)
{
    s32 ret;
    s32 v;
    void *p1;
    void *p2;
    f32 f;
    s32 i;
    MsgProcWindowEntry *e;
    s32 t;
    s32 w1;
    s32 w2;

    func_00278110();
    ret = 0;
    switch (arg1) {
    case 0:
        func_002781e0(arg0, 0x100000);
        func_00278170(arg0, 0x400000);
        func_002781e0(arg0, 0x800000);
        if (D_00882080 == NULL) {
            func_0046d730(D_0063BFC0, 399);
        }
        func_0043f9c8(&D_00882080, 0, 24);
        break;
    case 4:
        {
            MsgProcWindowWork *work = &D_00882098;
            if (func_00452380(D_0063C180) != 0) {
                if (work->field0 >= 2) {
                    v = work->field4;
                    goto lab4_chk;
                }
            } else {
                if (func_00452380(D_0063C180) == 0) {
                    func_0043f9c8(work, 0, 12);
                    func_00451fc0((void *)0, D_0063C180, 15, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
                } else {
                    goto lab4_zero;
                }
                goto lab4_zero2;
            }
lab4_zero:
lab4_zero2:
            v = 0;
lab4_chk:;
        }
        if (v != 0 && func_0027bec0(arg0) != 0) {
            if ((D_00882080[0] & 2) == 0) {
                D_00882080[0] |= 2;
                D_00882084[0] = 0;
            }
            D_00882084[0]++;
            if ((s16)D_00882084[0] >= 15) {
                D_00882080[0] &= ~2u;
                ret = 1;
            }
            if (D_00882080 == NULL) {
                func_0046d730(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)func_00283490;
                *(void **)(m + 16) = (void *)D_00882080;
                func_00460ac0(D_00796490, m);
            }
        }
        break;
    case 5:
        {
            MsgProcWindowWork *work = &D_00882098;
            if (func_00452380(D_0063C180) != 0) {
                if (work->field0 >= 2) {
                    v = work->field4;
                    goto lab5_chk;
                }
            } else {
                if (func_00452380(D_0063C180) == 0) {
                    func_0043f9c8(work, 0, 12);
                    func_00451fc0((void *)0, D_0063C180, 15, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
                }
                goto lab5_zero;
            }
lab5_zero:
            v = 0;
lab5_chk:;
        }
        if (v != 0 && func_0027bec0(arg0) != 0) {
            if ((D_00882080[0] & 2) == 0) {
                D_00882080[0] |= 2;
                D_00882084[0] = 0;
            }
            D_00882084[0]++;
            if ((s16)D_00882084[0] >= 120) {
                D_00882080[0] &= ~2u;
                D_00882084[0] = 0;
            }
            if (D_00882080 == NULL) {
                func_0046d730(D_0063BFC0, 2270);
            }
            D_00882090[0] = (u32)arg0;
            D_00882094[0] = (u32)arg1;
            {
                u8 *m = func_00460990();
                *(void **)(m + 8) = (void *)func_00283490;
                *(void **)(m + 16) = (void *)D_00882080;
                func_00460ac0(D_00796490, m);
            }
        }
        break;
    case 6:
        if (func_0027bec0(arg0) != 0) {
            ret = 1;
        }
        break;
    case 8:
        p1 = (void *)func_00278fd0(arg0);
        if (p1 != NULL) {
            func_00272a10(p1, 400.0f, 170.0f);
            func_002728c0(p1, 0);
            func_00272b00(p1, 0);
        }
        p2 = (void *)func_00278fb0(arg0);
        if (p2 != NULL) {
            func_00272a10(p2, 202.0f, (f32)281);
            func_002728c0(p2, 0);
            func_00272b50(p2, 0, 0);
            func_00272730(p2, 255);
            func_002727a0(p2, 255);
        }
        ret = 1;
        break;
    case 7:
        f = (f32)D_00882084[0];
        for (i = 0; i < 8; i++) {
            e = &D_008820B0[i];
            if ((e->field0 & 1) == 0) {
                goto lab7_found;
            }
        }
        e = NULL;
lab7_found:
        if (e != NULL) {
            func_0043f9c8(e, 0, 24);
            e->field0 |= 1;
            e->field8 = f;
            e->fieldC = 0;
            e->field4 = 4;
        }
        break;
    case 9:
        t = func_0027b6e0(arg0, 0);
        if (t == 5) {
            w1 = 0x550;
            w2 = 0xF0;
        } else {
            s32 q = (s32)(100.0f / (f32)t);
            w1 = (q >> 1) * 8 + 0x550;
            w2 = q << 3;
        }
        func_0027b750(arg0, 0, 0x460);
        func_0027b750(arg0, 1, w1);
        func_0027b750(arg0, 2, w2);
        ret = 1;
        break;
    case 11:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 12:
        func_0027bec0(arg0);
        break;
    case 13:
        func_0027bec0(arg0);
        ret = 1;
        break;
    case 16:
        if (func_0027bec0(arg0) != 0) {
            s32 ok;
            if (iGpffffb4d8 == 0 || iGpffffb4dc == 0) {
                ok = 0;
            } else {
                ok = 1;
            }
            if (ok != 0) {
                s32 c = D_00882088[0];
                if ((D_00882080[0] & 0x20) == 0) {
                    D_00882080[0] |= 0x20;
                    c = 0;
                }
                c++;
                if (c >= 5) {
                    D_00882080[0] &= ~0x20u;
                    c = 0;
                    ret = 1;
                }
                D_00882088[0] = (s16)c;
            }
        }
        break;
    case 17:
        func_0027bec0(arg0);
        break;
    case 18:
        if (func_0027bec0(arg0) != 0) {
            s32 ok2;
            if (iGpffffb4d8 == 0 || iGpffffb4dc == 0) {
                ok2 = 0;
            } else {
                ok2 = 1;
            }
            if (ok2 != 0) {
                s32 c = D_00882088[0];
                if ((D_00882080[0] & 0x80) == 0) {
                    D_00882080[0] |= 0x80;
                    c = 0;
                }
                c++;
                if (c >= 10) {
                    D_00882080[0] &= ~0x80u;
                    c = 0;
                    ret = 1;
                }
                D_00882088[0] = (s16)c;
            }
        }
        break;
    default:
        break;
    }
    return ret;
}
#pragma opt_loop_invariants off

#pragma push
#pragma opt_loop_invariants on
s32 func_0036ee60(u8 *arg0, s16 arg1, s32 arg2)
{
    s16 listC[256];
    s16 listB[256];
    s16 listA[256];
    s16 lvl;
    s16 hi;
    s16 cap;
    s16 lo;
    s16 mlvl;
    u16 nA;
    u16 nB;
    s32 i;
    s32 drawIndex;
    u16 nC;
    s32 aCount;
    s32 bCount;
    s32 cCount;
    s32 total;
    s32 k;
    u16 r1;
    u16 r2;
    s16 tmp;
    s32 nDraw;
    u16 aIdx;
    u16 bIdx;
    u16 cIdx;
    s32 e;
    s16 item;
    u32 rate = 0;

    lvl = func_00104c70(1) & 0xFF;
    if (lvl > 0 && (u32)lvl < 10) {
        hi = D_0064E76F[lvl];
        lo = 1;
    } else if (lvl >= arg1) {
        hi = arg1 - 5;
        lo = arg1 - 10;
    } else {
        hi = lvl - 5;
        lo = lvl - 10;
    }
    cap = lvl + 3;
    if (cap > 99) {
        cap = 99;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    nC = 0;
    nB = 0;
    nA = 0;
    for (i = 0; i < 256; i++) {
        u8 *rec = iGpffffb3d4;
        rec += i * 14;

        if ((*(u16 *)rec & 0xDB) != 0) {
            continue;
        }
        mlvl = rec[3];
        if (mlvl > cap) {
            continue;
        }
        if (mlvl <= lvl) {
            if (mlvl > hi) {
                continue;
            }
            if (mlvl < lo) {
                continue;
            }
        }
        if ((s16)func_0010aa80((s16)i) != -1) {
            listA[nA++] = i;
        } else if (lvl < mlvl) {
            listB[nB++] = i;
        } else {
            listC[nC++] = i;
        }
    }
    bCount = nB;
    cCount = nC;
    aCount = nA;
    total = aCount + (cCount + bCount);
    if (total == 0) {
        return 0;
    }
    if (cCount > 1) {
        for (k = 0; k < cCount; k++) {
            r1 = func_00231d70(cCount);
            r2 = func_00231d70(cCount);
            if (r1 != r2) {
                tmp = listC[r1];
                listC[r1] = listC[r2];
                listC[r2] = tmp;
            }
        }
    }
    if (bCount > 1) {
        for (k = 0; k < bCount; k++) {
            r1 = func_00231d70(nB);
            r2 = func_00231d70(nB);
            if (r1 != r2) {
                tmp = listB[r1];
                listB[r1] = listB[r2];
                listB[r2] = tmp;
            }
        }
    }
    if (aCount > 1) {
        for (k = 0; k < aCount; k++) {
            r1 = func_00231d70(nA);
            r2 = func_00231d70(nA);
            if (r1 != r2) {
                tmp = listA[r1];
                listA[r1] = listA[r2];
                listA[r2] = tmp;
            }
        }
    }
    *(s32 *)(arg0 + 0x10) = func_0036e920(arg1);
    *(s32 *)(arg0 + 0x14) = func_0036eb50(*(s32 *)(arg0 + 0x10), arg1);
    *(s32 *)(arg0 + 0xC) = func_0036ea00(*(s32 *)(arg0 + 0x10), arg1);
    nDraw = func_0036eda0(*(s32 *)(arg0 + 0xC));
    if (total < nDraw) {
        nDraw = total;
    }
    bIdx = 0;
    cIdx = 0;
    aIdx = 0;
    e = 0;
    for (drawIndex = 0; drawIndex < nDraw; drawIndex++) {
        if (func_00231d70(100) < rate && bIdx < bCount) {
            item = listB[bIdx++];
        } else if (cIdx < cCount) {
            item = listC[cIdx++];
        } else if (aIdx < aCount) {
            s32 index = aIdx;
            aIdx++;
            item = listA[index];
        } else {
            continue;
        }
        ((s16 *)arg0)[e] = item;
        e++;
    }
    if (e == 0) {
        return 0;
    }
    *(s32 *)(arg0 + 8) = e;
    if (aIdx == e && func_00231d70(100) >= 20) {
        return 0;
    }
    return 1;
}
#pragma pop

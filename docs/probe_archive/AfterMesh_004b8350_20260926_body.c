#pragma push
#pragma opt_loop_invariants on
u8 *func_004b8350(u8 *arg0, s32 arg1)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        f32 radius;
    } AfterSphere;
    AfterSphere sphere;
    u8 *cfg;
    u8 *obj;
    u8 *idx;
    u8 *col;
    f32 *uv;
    f32 *p;
    s32 nVtx;
    s32 nIdx;
    u32 flags;
    s32 n;
    s32 last;
    s32 i;
    s32 j;
    s32 v;
    u16 w;
    f32 t;
    f32 denom;
    f32 step;

    flags = 0x4A;
    if ((**(u32 **)(*(s32 *)arg0 + 4) & 1) != 0) {
        flags |= 4;
    }
    nIdx = 0;
    nVtx = 0;
    switch (*(s16 *)(arg0 + 0x38)) {
    case 0:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = (n - 1) * 2 + 1;
        nVtx = n * 2 + 1;
        break;
    case 1:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    case 2:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    }
    obj = func_003c2630(nVtx, nIdx, flags);
    idx = *(u8 **)(obj + 0x2C);
    switch (*(s16 *)(arg0 + 0x38)) {
    case 0:
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC) - 1; i++) {
            s32 next;
            s32 mid;

            v = i * 2;
            next = v + 2;
            mid = v + 1;
            func_003c2130((s32)obj, idx, v, mid, next);
            func_003c2130((s32)obj, idx + 8, mid, v + 3, next);
            idx += 0x10;
        }
        v = i * 2;
        func_003c2130((s32)obj, idx, v, v + 1, v + 2);
        break;
    case 1:
        func_003c2130((s32)obj, idx, 0, 3, 2);
        func_003c2130((s32)obj, idx + 8, 2, 4, 1);
        idx += 0x10;
        w = 2;
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
            s32 base;
            s32 next;
            s32 a;
            s32 b;

            base = w;
            next = base + 3;
            a = base + 1;
            func_003c2130((s32)obj, idx, w, a, next);
            b = base + 2;
            func_003c2130((s32)obj, idx + 8, w, next, b);
            func_003c2130((s32)obj, idx + 0x10, a, base + 4, next);
            func_003c2130((s32)obj, idx + 0x18, b, next, base + 5);
            idx += 0x20;
            w += 3;
        }
        {
            s32 base;
            s32 next;

            base = w;
            next = base + 3;
            func_003c2130((s32)obj, idx, w, base + 1, next);
            func_003c2130((s32)obj, idx + 8, w, next, base + 2);
        }
        break;
    case 2:
        func_003c2130((s32)obj, idx, 0, 3, 2);
        func_003c2130((s32)obj, idx + 8, 2, 4, 1);
        idx += 0x10;
        w = 2;
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
            s32 base;
            s32 next;
            s32 a;
            s32 b;

            base = w;
            next = base + 3;
            a = base + 1;
            func_003c2130((s32)obj, idx, w, a, next);
            b = base + 2;
            func_003c2130((s32)obj, idx + 8, w, next, b);
            func_003c2130((s32)obj, idx + 0x10, a, base + 4, next);
            func_003c2130((s32)obj, idx + 0x18, b, next, base + 5);
            idx += 0x20;
            w += 3;
        }
        {
            s32 base;
            s32 next;

            base = w;
            next = base + 3;
            func_003c2130((s32)obj, idx, w, base + 1, next);
            func_003c2130((s32)obj, idx + 8, w, next, base + 2);
        }
        break;
    }
    idx = *(u8 **)(obj + 0x2C);
    for (i = 0; i < nIdx; i++) {
        func_003c2150((s32)obj, idx, arg1);
        idx += 8;
    }
    switch (*(s16 *)(arg0 + 0x38)) {
    case 0:
        col = *(u8 **)(obj + 0x30);
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
            if (i == 0) {
                t = (f32)i / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
            } else {
                t = ((f32)i - 0.5f) / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
            }
            func_004bc540(arg0, 0, col, t);
            col += 8;
        }
        func_004bc540(arg0, 0, col, 1.0f);
        col = *(u8 **)(obj + 0x30) + 4;
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
            t = (f32)i / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
            func_004bc540(arg0, 1, col, t);
            col += 8;
        }
        break;
    case 1:
        {
            u8 *c;
            s32 k;

            c = *(u8 **)(obj + 0x30);
            for (k = 0; k < nVtx; k++) {
                c[0] = 0;
                c[1] = 0;
                c[2] = 0;
                c[3] = 0;
                c += 4;
            }
        }
        break;
    case 2:
        {
            u8 *c;
            s32 k;

            c = *(u8 **)(obj + 0x30);
            for (k = 0; k < nVtx; k++) {
                c[0] = 0;
                c[1] = 0;
                c[2] = 0;
                c[3] = 0;
                c += 4;
            }
        }
        break;
    }
    cfg = *(u8 **)arg0;
    if ((**(u32 **)(cfg + 4) & 1) != 0) {
        switch (*(s16 *)(arg0 + 0x38)) {
        case 0:
            uv = *(f32 **)(obj + 0x34);
            for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
                if (*(s32 *)(*(u8 **)arg0 + 0xC) - 1 <= 0) {
                    func_0046d730(D_007146E0, 0x226);
                }
                if (i == 0) {
                    uv[0] = (f32)i / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                } else {
                    uv[0] = ((f32)i - 0.5f) / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                }
                uv[1] = 0.0f;
                uv += 4;
            }
            uv[0] = 1.0f;
            uv[1] = 0.0f;
            uv = *(f32 **)(obj + 0x34) + 2;
            for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC); i++) {
                if (*(s32 *)(*(u8 **)arg0 + 0xC) - 1 <= 0) {
                    func_0046d730(D_007146E0, 0x234);
                }
                uv[0] = (f32)i / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                uv[1] = 1.0f;
                uv += 4;
            }
            break;
        case 1:
            uv = *(f32 **)(obj + 0x34);
            n = *(s32 *)(cfg + 0xC);
            last = n * 3 + 6;
            denom = 0.5f + (f32)n;
            uv[0] = 0.0f;
            uv[1] = 0.0f;
            uv[2] = 0.0f;
            uv[3] = 1.0f;
            uv[4] = 0.0f;
            uv[5] = 0.5f;
            p = uv + last * 2;
            p[-6] = 1.0f;
            p[-5] = 0.0f;
            p[-4] = 1.0f;
            p[-3] = 1.0f;
            p[-2] = 1.0f;
            p[-1] = 0.5f;
            {
                f32 *q;
                s32 k;
                f32 u;
                f32 h;

                u = 1.0f / denom;
                step = u;
                h = 0.5f / denom;
                q = uv + 6;
                k = 0;
                while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                    q[0] = h;
                    q[1] = 0.0f;
                    q[2] = h;
                    q[3] = 1.0f;
                    q += 6;
                    k++;
                    h += step;
                }
                q = uv + 10;
                k = 0;
                while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                    q[0] = u;
                    q[1] = 0.5f;
                    k++;
                    u += step;
                    q += 6;
                }
            }
            break;
        case 2:
            uv = *(f32 **)(obj + 0x34);
            n = *(s32 *)(cfg + 0xC);
            last = n * 3 + 6;
            denom = 0.5f + (f32)n;
            uv[0] = 0.0f;
            uv[1] = 0.0f;
            uv[2] = 0.0f;
            uv[3] = 1.0f;
            uv[4] = 0.0f;
            uv[5] = 0.5f;
            p = uv + last * 2;
            p[-6] = 1.0f;
            p[-5] = 0.0f;
            p[-4] = 1.0f;
            p[-3] = 1.0f;
            p[-2] = 1.0f;
            p[-1] = 0.5f;
            {
                f32 *q;
                s32 k;
                f32 u;
                f32 h;

                u = 1.0f / denom;
                step = u;
                h = 0.5f / denom;
                q = uv + 6;
                k = 0;
                while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                    q[0] = h;
                    q[1] = 0.0f;
                    q[2] = h;
                    q[3] = 1.0f;
                    q += 6;
                    k++;
                    h += step;
                }
                q = uv + 10;
                k = 0;
                while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                    q[0] = u;
                    q[1] = 0.5f;
                    k++;
                    u += step;
                    q += 6;
                }
            }
            break;
        }
    }
    sphere.x = 0.0f;
    sphere.y = 0.0f;
    sphere.z = 0.0f;
    sphere.radius = 1000000000;
    *(AfterSphere *)(*(u8 **)(obj + 0x5C) + 4) = sphere;
    return obj;
}
#pragma pop

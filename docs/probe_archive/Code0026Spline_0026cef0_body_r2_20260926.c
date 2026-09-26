#pragma push
#pragma opt_loop_invariants on
// FUN_0026CEF0
f32 func_0026cef0(s8 *arg0, f32 fparg0, f32 fparg1,
                  f32 *arg1, f32 *arg2)
{
    typedef struct { f32 x, y, z; } CefV3;
    typedef struct { s8 count; u8 pad[3]; CefV3 pts[1]; } CefPath;
    f32 ax0, ax1, ay0, ay1, az0, az1;
    f32 bx0, bx1, by0, by1, bz0, bz1;
    f32 cx0, cx1, cy0, cy1, cz0, cz1;
    CefV3 at;
    CefV3 delta;
    CefV3 back;
    CefV3 dir;
    CefV3 dF;
    CefV3 dL;
    CefV3 dB;
    f32 x[4];
    f32 y[4];
    f32 z[4];
    f32 dist;
    f32 t;
    f32 step;
    f32 pos;
    f32 len;
    f32 frac;
    f32 adv;
    f32 u;
    f32 sx, sy, sz;
    s32 seg;
    s32 k;
    s32 j;
    s8 n;
    s32 idx;
    CefPath *path;
    CefV3 *pts;

    path = (CefPath *)arg0;
    dist = 0.0f;
    n = path->count;
    step = (1.0f / (f32)n) / 20.0f;
    pos = dist;
    if (fparg1 <= fparg0) {
        idx = (n - 1) * 3;
        for (j = 0; j < 4; j++) {
            x[j] = path->pts[idx + j].x;
            y[j] = path->pts[idx + j].y;
            z[j] = path->pts[idx + j].z;
        }
        func_0026c960(fGpffff82d4, x, y, z, &ax0, &ay0, &az0);
        func_0026c960(1.0f, x, y, z, &ax1, &ay1, &az1);
        dF.x = ax1 - ax0;
        dF.y = ay1 - ay0;
        dF.z = az1 - az0;
        RwV3dLength((f32 *)&dF);
        at.x = ax1;
        at.y = ay1;
        at.z = az1;
        *(CefV3 *)arg1 = at;
        delta.x = at.x - ax0;
        delta.y = at.y - ay0;
        delta.z = at.z - az0;
        RwV3dNormalize((f32 *)&dir, (f32 *)&delta);
        func_0026c860((f32 *)&dir, arg2);
        return 1.0f;
    }
    for (seg = 0; seg < path->count; seg++) {
        for (j = 0; j < 4; j++) {
            pts = &path->pts[seg * 3 + j];
            x[j] = pts->x;
            y[j] = pts->y;
            z[j] = pts->z;
        }
        for (k = 0; k < 20; k++) {
            t = (f32)k * fGpffff83d0;
            func_0026c960(t, x, y, z, &bx0, &by0, &bz0);
            func_0026c960((f32)(k + 1) * fGpffff83d0, x, y, z, &bx1, &by1, &bz1);
            dL.x = bx1 - bx0;
            dL.y = by1 - by0;
            dL.z = bz1 - bz0;
            len = RwV3dLength((f32 *)&dL);
            sx = bx0;
            sy = by0;
            sz = bz0;
            at.x = bx1;
            at.y = by1;
            at.z = bz1;
            dist += len;
            if (!(dist < fparg0)) {
                frac = 1.0f - (dist - fparg0) / len;
                adv = step * frac;
                pos += adv;
                delta.x = at.x - sx;
                delta.y = at.y - sy;
                delta.z = at.z - sz;
                arg1[0] = sx + delta.x * frac;
                arg1[1] = sy + delta.y * frac;
                arg1[2] = sz + delta.z * frac;
                u = t + adv;
                func_0026c960(u, x, y, z, &cx0, &cy0, &cz0);
                func_0026c960(u - fGpffff842c, x, y, z, &cx1, &cy1, &cz1);
                dB.x = cx1 - cx0;
                dB.y = cy1 - cy0;
                dB.z = cz1 - cz0;
                RwV3dLength((f32 *)&dB);
                back.x = cx0 - cx1;
                back.y = cy0 - cy1;
                back.z = cz0 - cz1;
                RwV3dNormalize((f32 *)&dir, (f32 *)&back);
                func_0026c860((f32 *)&dir, arg2);
                return pos;
            }
            pos += step;
        }
    }
    return 0.0f;
}
#pragma pop

// FUN_0026CEF0
f32 func_0026cef0(s8 *arg0, f32 fparg0, f32 fparg1,
                  f32 *arg1, f32 *arg2)
{
    typedef struct { f32 x, y, z; } CefV3;
    typedef struct { f32 x, y, z, pad; } CefV4;
    typedef struct { s8 count; u8 pad[3]; CefV3 pts[1]; } CefPath;
    struct Cef0Frame {
        f32 z[4];
        f32 y[4];
        f32 x[4];
        u8 padB0[8];
        CefV4 dB;
        CefV4 dL;
        CefV4 dF;
        f32 dir[4];
        CefV4 back;
        CefV4 delta;
        CefV4 at;
        f32 c[6];
        f32 b[6];
        f32 a[6];
    } frame;
    f32 dist;
    f32 t;
    f32 step;
    f32 pos;
    f32 len;
    f32 frac;
    f32 adv;
    s32 seg;
    s32 k;
    s32 j;
    CefPath *path;
    CefV3 *pts;

    path = (CefPath *)arg0;
    dist = 0.0f;
    step = (1.0f / (f32)path->count) / 20.0f;
    pos = 0.0f;
    if (fparg1 <= fparg0) {
        for (j = 0; j < 4; j++) {
            pts = &path->pts[(path->count - 1) * 3 + j];
            frame.x[j] = pts->x;
            frame.y[j] = pts->y;
            frame.z[j] = pts->z;
        }
        func_0026c960(fGpffff82d4, frame.x, frame.y, frame.z, &frame.a[5], &frame.a[3], &frame.a[1]);
        func_0026c960(1.0f, frame.x, frame.y, frame.z, &frame.a[4], &frame.a[2], &frame.a[0]);
        frame.dF.x = frame.a[4] - frame.a[5];
        frame.dF.y = frame.a[2] - frame.a[3];
        frame.dF.z = frame.a[0] - frame.a[1];
        RwV3dLength((f32 *)&frame.dF);
        frame.at.x = frame.a[4];
        frame.at.y = frame.a[2];
        frame.at.z = frame.a[0];
        *(CefV3 *)arg1 = *(CefV3 *)&frame.at;
        frame.delta.x = frame.a[4] - frame.a[5];
        frame.delta.y = frame.a[2] - frame.a[3];
        frame.delta.z = frame.a[0] - frame.a[1];
        RwV3dNormalize(frame.dir, (f32 *)&frame.delta);
        func_0026c860(frame.dir, arg2);
        return 1.0f;
    }
    for (seg = 0; seg < path->count; seg++) {
        for (j = 0; j < 4; j++) {
            pts = &path->pts[seg * 3 + j];
            frame.x[j] = pts->x;
            frame.y[j] = pts->y;
            frame.z[j] = pts->z;
        }
        for (k = 0; k < 20; k++) {
            t = (f32)k * fGpffff83d0;
            func_0026c960(t, frame.x, frame.y, frame.z, &frame.b[5], &frame.b[3], &frame.b[1]);
            func_0026c960((f32)(k + 1) * fGpffff83d0, frame.x, frame.y, frame.z, &frame.b[4], &frame.b[2], &frame.b[0]);
            frame.dL.x = frame.b[4] - frame.b[5];
            frame.dL.y = frame.b[2] - frame.b[3];
            frame.dL.z = frame.b[0] - frame.b[1];
            len = RwV3dLength((f32 *)&frame.dL);
            frame.at.x = frame.b[4];
            frame.at.y = frame.b[2];
            frame.at.z = frame.b[0];
            dist += len;
            if (!(dist < fparg0)) {
                frac = 1.0f - (dist - fparg0) / len;
                adv = step * frac;
                pos += adv;
                frame.delta.x = frame.b[4] - frame.b[5];
                frame.delta.y = frame.b[2] - frame.b[3];
                frame.delta.z = frame.b[0] - frame.b[1];
                arg1[0] = frame.b[5] + frame.delta.x * frac;
                arg1[1] = frame.b[3] + frame.delta.y * frac;
                arg1[2] = frame.b[1] + frame.delta.z * frac;
                t += adv;
                func_0026c960(t, frame.x, frame.y, frame.z, &frame.c[5], &frame.c[3], &frame.c[1]);
                func_0026c960(t - fGpffff842c, frame.x, frame.y, frame.z, &frame.c[4], &frame.c[2], &frame.c[0]);
                frame.dB.x = frame.c[4] - frame.c[5];
                frame.dB.y = frame.c[2] - frame.c[3];
                frame.dB.z = frame.c[0] - frame.c[1];
                RwV3dLength((f32 *)&frame.dB);
                frame.back.x = frame.c[5] - frame.c[4];
                frame.back.y = frame.c[3] - frame.c[2];
                frame.back.z = frame.c[1] - frame.c[0];
                RwV3dNormalize(frame.dir, (f32 *)&frame.back);
                func_0026c860(frame.dir, arg2);
                return pos;
            }
            pos += step;
        }
    }
    return 0.0f;
}

typedef struct {
    s32 value[19];
} ShapeCountTable;
typedef struct {
    PrimFloat2 *value[19];
} ShapePointTable;
extern s32 D_0063A9E0[19];
extern PrimFloat2 *D_0063AA30[19];
#pragma push
#pragma opt_propagation off
// FUN_00267B20
void func_00267b20(f32 x, f32 y, f32 z, s32 rgb, s32 alpha, s32 unused, s32 shape, s32 offsetX, s32 offsetY,
                   f32 depth, f32 scaleX, f32 scaleY)
{
    struct CalendarColor { u8 r, g, b, a; } depthValue;
    struct CalendarColor depthScratch;
    PrimFloat2 points[257];
    u8 colors[256][4];
    ShapeCountTable counts;
    ShapePointTable shapes;
    Quad4 clip;
    Quad4 clipScratch;
    void (**states)(u32 state, u32 value);
    PrimFloat2 *src;
    PrimFloat2 *dst;
    PrimFloat2 *pt;
    u8 *col;
    u32 color;
    s32 count;
    s32 i;
    u8 c0;
    u8 c1;
    u32 c2;
    u8 c3;

    color = ((u32)rgb << 8) | alpha;
    counts = *(ShapeCountTable *)D_0063A9E0;
    shapes = *(ShapePointTable *)D_0063AA30;
    if (!(scaleX < 7.0f) || !(scaleY < 7.0f)) {
        return;
    }
    if (shape == 9) {
        s32 lineCount = counts.value[shape * 2];
        PrimFloat2 *line = shapes.value[shape * 2];
        s32 k = 0;
        u8 r = color >> 24;
        u8 g = color >> 16;
        u8 b = color >> 8;
        u8 a = color;

        for (; k < lineCount; k++) {
            pt = &line[k];
            dst = &points[k];
            dst->v[0] = (x + pt->v[0]) - line[0].v[0];
            dst->v[1] = (y + pt->v[1]) - line[0].v[1];
            col = colors[k];
            col[0] = r;
            col[1] = g;
            col[2] = b;
            col[3] = a;
        }
        func_00364c50();
        func_0045e6a0(colors, points, z, lineCount, 5, 1, offsetX, offsetY, depth, scaleX, scaleY);
        func_00364c70();
        return;
    }
    calendarZeroBytes(&depthScratch, sizeof(depthScratch));
    depthValue = depthScratch;
    calendarZeroBytes(&clipScratch, sizeof(clipScratch));
    clipScratch.a = 0;
    clipScratch.b = 0;
    clipScratch.c = 640;
    clipScratch.d = 480;
    clip = clipScratch;
    states = D_00887300;
    states[0](14, 0);
    states[0](12, 1);
    states[0](7, 2);
    states[0](9, 2);
    states[0](20, 1);
    states[0](6, 0);
    states[0](8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    func_00489f80();
    func_0045d6e0(&depthValue, &clip, 10.0f, 0);
    func_0048a000();

    count = counts.value[shape * 2 + 1];
    src = shapes.value[shape * 2 + 1];
    i = 0;
    c0 = color >> 24;
    c1 = color >> 16;
    c2 = (color >> 8) & 0xFF;
    c3 = color;
    for (; i < count; i++) {
        pt = &src[i];
        dst = &points[i];
        dst->v[0] = (x + pt->v[0]) - src[0].v[0];
        dst->v[1] = (y + pt->v[1]) - src[0].v[1];
        col = colors[i];
        col[0] = c0;
        col[1] = c1;
        col[2] = c2;
        col[3] = c3;
    }
    func_00364c50();
    states = D_00887300;
    states[0](6, 0);
    states[0](8, 1);
    RpSkyRenderStateSet(3, 0x30003);
    RpSkyRenderStateSet(2, 0x44);
    func_00489f80();
    func_0045e6a0(colors, points, z, count, 5, 0, offsetX, offsetY, depth, scaleX, scaleY);
    func_0048a000();
    func_00364c70();

    {
        s32 fillCount = counts.value[shape * 2];
        PrimFloat2 *fill = shapes.value[shape * 2];

        for (i = 0; i < fillCount; i++) {
            pt = &fill[i];
            dst = &points[i];
            dst->v[0] = (x + pt->v[0]) - fill[0].v[0];
            dst->v[1] = (y + pt->v[1]) - fill[0].v[1];
            col = colors[i];
            col[0] = c0;
            col[1] = c1;
            col[2] = c2;
            col[3] = c3;
        }
        if (alpha == 0xFF) {
            func_00364c50();
        }
        func_0045e6a0(colors, points, 1.0f + z, fillCount, 5, 1, offsetX, offsetY, depth, scaleX, scaleY);
        if (alpha == 0xFF) {
            func_00364c70();
        }
    }

    for (i = 1; i < count; i++) {
        pt = &src[i];
        dst = &points[i] - 1;
        dst->v[0] = (x + pt->v[0]) - src[0].v[0];
        dst->v[1] = (y + pt->v[1]) - src[0].v[1];
        col = colors[i] - 4;
        col[0] = c0;
        col[1] = c1;
        col[2] = c2;
        col[3] = c3;
    }
    if (alpha == 0xFF) {
        func_00364c50();
    }
    {
        s16 lineX = x + ((f32)offsetX - points[0].v[0]);
        s16 lineY = y + ((f32)offsetY - points[0].v[1]);

        func_0045e6a0(colors, points, z, count - 1, 4, 1, lineX, lineY, depth, scaleX, scaleY);
    }
    if (alpha == 0xFF) {
        func_00364c70();
    }
}
#pragma pop

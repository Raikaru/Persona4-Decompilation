/* object 364B / window 368B / nd 22; differing offsets 76-100 (float block); deficit 1 instruction; classification: unresolved COP1 scheduling/register-coloring residual; ruled out: aggregate-gap layout, copy-loop forms (pointer/indexed, for/do-while), struct field order, statement order, operand order, f32 helper fusion, -O1, opt_propagation off, opt_common_subs off. */
void func_0027d800(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2)
{
    struct {
        MsgProcWindowRGBA colors[10];
        u8 gap[24];
        MsgProcWindowF2 points[10];
    } work;
    MsgProcWindowU32Pair *src;
    MsgProcWindowU32Pair *dst;
    MsgProcWindowF2 *p;
    MsgProcWindowRGBA *c;
    s32 count;
    u32 lo;
    u32 hi;
    u32 i;
    u32 packed;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    f32 base;
    f32 scaled;
    f32 dx;
    f32 dy;
    extern s32 func_0045eb20();

    src = (MsgProcWindowU32Pair *)D_0063C030;
    dst = (MsgProcWindowU32Pair *)work.points;
    count = 10;
    do {
        lo = src->a;
        hi = src->b;
        src++;
        count--;
        dst->a = lo;
        dst->b = hi;
        dst++;
    } while (count > 0);

    scaled = 78.0f * f3;
    base = scaled + 5.0f;
    work.points[1].y = base;
    work.points[3].y = 2.0f + base;
    work.points[5].y = 4.0f + base;
    work.points[7].y = 5.0f + base;
    work.points[9].y = work.points[7].y;

    i = 0;
    packed = ((u32)a2 << 8) | (u32)a3;
    red = (packed >> 24) & 0xFF;
    green = (packed >> 16) & 0xFF;
    blue = (packed >> 8) & 0xFF;
    alpha = packed & 0xFF;
    dx = (f32)a0;
    dy = (f32)a1;
    for (; i < 10; i++) {
        p = &work.points[i];
        p->x += dx;
        p->y += dy;
        c = &work.colors[i];
        c->r = (u8)red;
        c->g = (u8)green;
        c->b = (u8)blue;
        c->a = (u8)alpha;
    }
    func_0045eb20(&work.colors[0], &work.points[0], 10, 4, 1, t0, t1, t2);
}

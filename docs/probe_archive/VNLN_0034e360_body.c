/* func_0034e360 -- line decoration mesh, not promoted.
 * Context: src/promoted/nLine.c, including Vec2f and the s32 declaration.
 * Object 2648B / retail window 2656B; normalized_diff 336. The differing
 * words include substantial allocation/scheduling differences, not just
 * the two absent tail words. Scalar geometry is nd339; register hints
 * do not improve either form. No padding or bound registers were added.
 *
 * Retail returns its full s32 vertex counter. Narrowing belongs to callers
 * storing at owner+0x1670, not this function's return declaration.
 * Style records have a 44-byte stride: s16 count at 0, five s32 palette
 * indices at 4, five f32 distances at 24. Palette records are four bytes.
 * Styles 1-4 emit 3 + 12*(count-1) vertices when count is positive;
 * style 5 emits six per entry, traversing entries backwards.
 *
 * Native Clang ASan/UBSan/float-cast-overflow smoke: 16,800 scenarios /
 * 120,960 vertices against an independently indexed triangle-mesh oracle.
 * Covers four edge directions, empty edges, custom rectangles for style 5,
 * nonpositive/positive counts, selected entries and alpha boundaries.
 * Camera/vertex callbacks mutate mode, selection, count, palette indices,
 * RGBA, owner alpha, depth and reciprocal inputs: entry alpha and palette
 * pointers remain captured, RGB reloads each vertex, and mode/selection/
 * count/projection retain their respective snapshots.
 * Unsupported custom-size styles 1-4 are excluded: retail leaves their
 * direction values unset. No invented initialization or input guard.
 * Callbacks are modeled boundaries; this is not EE execution. Production
 * remains INCLUDE_ASM until all instruction differences are resolved.
 */
typedef struct {
    s16 count;
    s32 colors[5];
    f32 offsets[5];
} NLineDecorationStyle;

/* Styles 1-4 require a full-width or full-height translated edge. Retail
   does not initialize directions on the custom-size path; style 5 does
   not use them. Do not invent a direction for unsupported combinations. */
s32 func_0034e360(u8 *arg0, f32 x, f32 y, f32 width, f32 height) {
    s16 mode;
    s16 index;
    Vec2f start;
    f32 depth;
    f32 reciprocal;
    s32 direction_x;
    s32 direction_y;
    u8 *vertices;

    mode = *(s16 *)(arg0 + 0x998);
    index = (s16)(mode - 1);
    if (mode == 0) {
        return 0;
    }
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    vertices = arg0 + 0x9B0;
    if (width != 640.0f && height != 448.0f) {
        start.x = x;
        start.y = y;
        x += width;
        y += height;
    } else if (x < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        x = start.x;
        y = 448.0f + y;
        direction_x = 1;
        direction_y = 0;
    } else if (!(x <= 0.0f)) {
        start.x = x;
        start.y = 448.0f + y;
        direction_x = -1;
        direction_y = 0;
    } else if (!(y <= 0.0f)) {
        start.x = x;
        start.y = y;
        x = 640.0f + x;
        direction_x = 0;
        direction_y = -1;
    } else if (y < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        direction_x = 0;
        direction_y = 1;
    } else {
        return 0;
    }
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4: {
        NLineDecorationStyle *style;
        s32 count;
        s32 selected;
        s32 i;
        s32 n;
        Vec2f center;
        Vec2f peak_offset;
        Vec2f gap_offset;
        style = (NLineDecorationStyle *)D_00752600 + index;
        count = style->count;
        selected = *(s16 *)(arg0 + 0x99A);
        i = 0;
        n = 0;
        if (count > 0) {
            center.x = (start.x + x) / 2.0f;
            center.y = (start.y + y) / 2.0f;
            peak_offset.y = 200.0f * (f32)direction_y;
            peak_offset.x = 200.0f * (f32)direction_x;
            gap_offset.x = 30.0f * (f32)direction_x;
            gap_offset.y = 30.0f * (f32)direction_y;
            while (i < count) {
                f32 distance;
                Vec2f shift;
                u8 *color;
                u32 alpha;
                u8 byte_alpha;
                distance = style->offsets[i];
                shift.x = (f32)direction_x * distance;
                shift.y = (f32)direction_y * distance;
                color = D_00749AC0 + style->colors[i] * 4;
                if (i == selected) {
                    alpha = 0;
                } else {
                    alpha = (u8)((color[3] * arg0[0x994]) / 255);
                }
                byte_alpha = (u8)alpha;
                if (i == 0) {
                    func_0034f0d0(vertices + (n++ << 6), x, y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak_offset.x + (center.x + shift.x), peak_offset.y + (center.y + shift.y), depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), start.x, start.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                } else {
                    f32 previous;
                    Vec2f previous_shift;
                    Vec2f peak;
                    Vec2f edge;
                    Vec2f inner_peak;
                    Vec2f other;
                    previous = 30.0f + style->offsets[i - 1];
                    previous_shift.x = (f32)direction_x * previous;
                    previous_shift.y = (f32)direction_y * previous;
                    shift.x += gap_offset.x;
                    shift.y += gap_offset.y;
                    func_0034f0d0(vertices + (n++ << 6), x + shift.x, y + shift.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    peak.y = peak_offset.y + (center.y + shift.y);
                    peak.x = peak_offset.x + (center.x + shift.x);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    edge.y = y + previous_shift.y;
                    edge.x = x + previous_shift.x;
                    func_0034f0d0(vertices + (n++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    inner_peak.y = peak_offset.y + (center.y + previous_shift.y);
                    inner_peak.x = peak_offset.x + (center.x + previous_shift.x);
                    func_0034f0d0(vertices + (n++ << 6), inner_peak.x, inner_peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), inner_peak.x, inner_peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    other.y = start.y + previous_shift.y;
                    other.x = start.x + previous_shift.x;
                    func_0034f0d0(vertices + (n++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                    func_0034f0d0(vertices + (n++ << 6), start.x + shift.x, start.y + shift.y, depth, reciprocal, color[0], color[1], color[2], byte_alpha);
                }
                ++i;
            }
        }
        if (n >= 0x34) {
            func_0046d730(&iGpffffa950, 0x67E);
        }
        return n;
    }
    case 5: {
        NLineDecorationStyle *style;
        s32 i;
        s32 n;
        style = (NLineDecorationStyle *)D_00752600 + index;
        i = style->count - 1;
        n = 0;
        while (i >= 0) {
            f32 distance;
            Vec2f top_left;
            Vec2f bottom_right;
            u8 *color;
            u8 alpha;
            distance = style->offsets[i];
            color = D_00749AC0 + style->colors[i] * 4;
            alpha = (u8)((color[3] * arg0[0x994]) / 255);
            top_left.y = start.y - distance;
            top_left.x = start.x - distance;
            func_0034f0d0(vertices + (n++ << 6), top_left.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottom_right.x = x + distance;
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottom_right.y = y + distance;
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), top_left.x, top_left.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), bottom_right.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            func_0034f0d0(vertices + (n++ << 6), top_left.x, bottom_right.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            --i;
        }
        if (n >= 0x34) {
            func_0046d730(&iGpffffa950, 0x6AC);
        }
        return n;
    }
    default:
        func_0046d730(&iGpffffa950, 0x6AF);
        return 0;
    }
}

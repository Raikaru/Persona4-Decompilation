/*
 * BEST candidate: object 700B, retail window 704B, normalized_diff 17 words.
 * Differing offsets (words): 408, 412, 428, 432, 436, 440, 448, 456, 468,
 * 480, 488, 516, 520, 524, 528, 532.
 * COP1 accumulator chain: reproduced with ordinary C arithmetic (6/6 ops).
 * Ruled out: initial archive body (wrong state layout/packet shape); direct
 * clamp and forward ternary (wrong branch shape/pointer coloring); precomputed
 * left/right (wrong scheduling); field-by-field scale-before-color stores;
 * untyped state array for the corrected y-at+0xc/z-at+0x8 mapping.
 * Data references D_00761470, D_008872F8, D_00887300, D_00887310 and helper
 * calls are existing, real, placeable symbols.
 */
// FUN_0038CAB0
void func_0038cab0(u8 *arg0)
{
    extern f32 D_00761470;
    extern f32 D_008872F8[];
    extern void (*D_00887300[])(u32, u32);
    extern void (*D_00887310[])(s32, void *, s32);
    extern u8 *func_00457120(void);
    extern f32 func_0044b610(f32 fparg0);
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    typedef struct {
        u16 counter;
        u16 pad;
        f32 x;
        f32 z;
        f32 y;
        f32 w;
    } State;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        u32 color[4];
        u32 tail[4];
    } Vertex;
    u8 *base;
    s32 mode;
    f32 zval;
    f32 inv_scale;
    f32 xcoord;
    f32 left;
    f32 right;
    Vertex work[4];

    {
        State *state;
        f32 fade;
        state = (State *)(arg0 + 0x1A0);
    base = *(u8 **)arg0 + 0x1F1D0;
    zval = D_008872F8[0];
    inv_scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    mode = *(u16 *)(base + 4);
    mode = (mode < 3) ? mode : 2;
    if (state->counter < 10) {
        state->counter += 1;
        fade = 1.0f -
            func_0044b610((D_00761470 * (f32)state->counter) / 10.0f);
    } else {
        fade = 1.0f;
        if (state->w == 0.0f) {
            *(u16 *)(arg0 + 4) &= 0xFFF7;
        }
    }
    state->x = state->x +
        0.25f * (107.0f * (f32)mode + 207.0f - state->x);
    state->y = state->y + fade * (state->w - state->y);
    fade = state->z;
    xcoord = state->x;
    left = xcoord - state->y / 2.0f;
    work[0].x = left;
    work[0].y = fade;
    work[0].z = zval;
    work[0].color[0] = 224;
    work[0].color[1] = 127;
    work[0].color[2] = 0;
    work[0].color[3] = 255;
    work[0].scale = inv_scale;
    right = xcoord + state->y / 2.0f;
    work[1].x = right;
    work[1].y = fade;
    work[1].z = zval;
    work[1].color[0] = 224;
    work[1].color[1] = 127;
    work[1].color[2] = 0;
    work[1].color[3] = 255;
    work[1].scale = inv_scale;
    work[2].x = work[0].x;
    work[2].y = fade + 448.0f;
    work[2].z = zval;
    work[2].color[0] = 224;
    work[2].color[1] = 127;
    work[2].color[2] = 0;
    work[2].color[3] = 255;
    work[2].scale = inv_scale;
    work[3].x = work[1].x;
    work[3].y = fade + 448.0f;
    work[3].z = zval;
    work[3].color[0] = 224;
    work[3].color[1] = 127;
    work[3].color[2] = 0;
    work[3].color[3] = 255;
    work[3].scale = inv_scale;
    }
    D_00887300[0](1, 0);
    func_00364c50();
    D_00887310[0](4, &work[0], 4);
    func_00364c70();
}

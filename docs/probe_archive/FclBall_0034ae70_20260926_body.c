/* func_0034ae70 (src/promoted/y_fclCmbBall.c) 2026-09-26 round 3: 3 differing
   words (1284B object / 1296B window, 321/321 instructions). Round 2 had
   12 edits (FclBall_0034ae70_20260925_body.c). Unit prerequisites are
   unchanged from that note: `#define FCL_COLOR_ARG u8` before
   fcl_color.h, and s32 func_00457120 / func_003315e0.
   Levers over round 2:
   - D_008872F8 is the 0x18 float of a render-state record at
     D_008872E0; D_008872FC and D_008872E0/E4/E8 are its neighbours.
     Read as a struct member, b210 treats the load as aliased by the
     vertex stores. Under `opt_loop_invariants on` only the `lui` is
     hoisted and `%lo` stays folded into the in-loop `lwc1`, which is
     retail's shape. The unsized `f32 D_008872F8[]` is treated as
     unaliased, so LI hoisted the whole load; a sized `f32[2]` goes
     gp-relative (183).
   - `(*setState)(1, *(u32 *)texture)` puts `addiu $a0, 1` before the
     `lw $a1`. The u32 load needs no conversion for the u32 parameter.
   Residual (3 words): in the vertex loop retail loads nearZ before the
   0xE14 float (`lwc1 $f1, nearZ; lwc1 $f0, e14; sub.s $f0, $f1, $f0`).
   b210 always loads the gp-less global last, even with loop invariants
   off. These were inert: a depth temp before or after the store,
   volatile, a 2-D view, `-e14 + nearZ` / `nearZ + -e14`, integer-cast
   operands (185), an `f32 *depth` pointer (185-282), and pragmas
   (common_subs off 249, peephole off 378, propagation on 270,
   optimization_level 3/4 293; the other five were inert). */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
typedef struct {
    u8 unk00[0x18];
    f32 nearZ;
    f32 farZ;
} RenderDepth;
extern RenderDepth D_008872E0;
void func_0034ae70(u8 *arg0, u8 *arg1) {
    void (**setState)(u32, u32);
    s32 texture;
    f32 scale;
    FclDrawColor color;
    FclVec2 position;
    s16 i;
    s16 slot;

    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    texture = func_003315e0();
    setState = D_00887300;
    setState[0](6, 1);
    setState[0](7, 2);
    setState[0](8, 1);
    setState[0](9, 2);
    setState[0](0xC, 1);
    setState[0](2, 3);
    setState[0](0xB, 6);
    setState[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x20) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x24) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x60) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x64) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xA0) = 0;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xA4) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xE0) = 0x3F800000;
    *(s32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xE4) = 0x3F800000;
    if (*(s8 *)(arg1 + 0xF00) == 1) {
        color = func_002b2a60(0x2D, 0x2D, 0x2D, *(u8 *)(arg1 + 0xE6E));
    } else {
        color = func_002b2a60(0, 0, 0x66, *(u8 *)(arg1 + 0xE6E));
        if (*(s16 *)(arg1 + 2) >= 3) {
            color = func_002b2a60(0xCC, 0xFF, 0xFF, (u32)*(u8 *)(arg1 + 0xE6E) >> 1);
        }
    }
    for (i = 0; i < 4; i++) {
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x18) = D_008872E0.nearZ - *(f32 *)(arg1 + 0xE14);
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x28) = scale;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x30) = color.c0;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x34) = color.c1;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x38) = color.c2;
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x3C) = color.c3;
    }
    position = *(FclVec2 *)(arg1 + 0xE38);
    slot = *(s16 *)(arg1 + 2);
    position.x += slot * 19;
    if (slot >= 3) {
        position.x += 12.0f;
    }
    *(f32 *)((slot << 8) + (u32)arg1 + 0x10) = position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x14) = position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x50) = 16.0f + position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x54) = position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x90) = position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0x94) = 16.0f + position.y;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD0) = 16.0f + position.x;
    *(f32 *)((*(s16 *)(arg1 + 2) << 8) + (u32)arg1 + 0xD4) = 16.0f + position.y;
    (*setState)(1, *(u32 *)texture);
    *(s16 *)(arg1 + 2) += 1;
}
#pragma pop

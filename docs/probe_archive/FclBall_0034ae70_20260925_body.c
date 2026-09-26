/* func_0034ae70 (src/promoted/y_fclCmbBall.c) 2026-09-25 rewrite from the retail
   listing: 322/322 instructions, fnalign 12 edits + 2 reloc-only (the guarded
   body is 366/324 instructions, 96 edits).  To reproduce, the unit needs two
   file-scope changes first (only this function uses them):
     #define FCL_COLOR_ARG u8          (before #include "fcl_color.h"; retail
                                        loads alpha after the RGB arguments and
                                        narrows alpha >> 1 with andi 0xFF)
     extern s32 func_00457120(void);  (the definitions in code1_0045.c and
     extern s32 func_003315e0(void);   code1_0033.c return s32)
   then `tools/fnalign.py src/promoted/y_fclCmbBall.c func_0034ae70
   --candidate <this>`.
   Levers: the colour is a real FclDrawColor value from func_002b2a60 (no byte
   buffer copies), `position` is a stack FclVec2 copied from arg1 + 0xE38,
   `(u32)*(u8 *)... >> 1` (srl, not sra), the UV 1.0 stores as the raw
   0x3F800000 words (retail uses lui/sw, and a float 1.0f under
   propagation-off is CSE'd with the scale numerator into $f21), and the depth
   read through an integer view of D_008872F8 (`depth = (u32)D_008872F8`),
   which gives the retail D-then-E14 load order.
   Residual: retail hoists only `lui %hi(D_008872F8)` above the loop and folds
   %lo into the lwc1, with i in $v1; this body hoists the full address (lui +
   addiu) and i lands in $a0 (8 edits).  The final call's `lw $a1, 0($s1)` is
   scheduled one slot before `addiu $a0, 1` (2 edits).  Measured without
   effect: i = 0 before the depth assignment, (*setState)() or D_00887300[0]()
   for the last call.  Worse: the direct D_008872F8[0] read (64-66: the lui
   stays in the loop, or LI hoists the whole load), an f32 *depth local (14),
   pointer-arithmetic stores (64-66). */
#pragma push
#pragma opt_propagation off
void func_0034ae70(u8 *arg0, u8 *arg1) {
    void (**setState)(u32, u32);
    s32 texture;
    f32 scale;
    FclDrawColor color;
    FclVec2 position;
    s16 i;
    s16 slot;
    u32 depth;

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
    depth = (u32)D_008872F8;
    for (i = 0; i < 4; i++) {
        *(f32 *)((u32)arg1 + (*(s16 *)(arg1 + 2) << 8) + i * 64 + 0x18) = *(f32 *)depth - *(f32 *)(arg1 + 0xE14);
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
    setState[0](1, *(s32 *)texture);
    *(s16 *)(arg1 + 2) += 1;
}
#pragma pop

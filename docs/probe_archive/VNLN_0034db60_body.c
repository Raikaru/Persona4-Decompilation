/* func_0034db60 -- timed centered rectangle, not promoted.
 * Context: src/promoted/nLine.c, including its existing addF helper.
 * Measured with the repository fndiff tool: object 652B / retail window
 * 656B, 27 reloc-masked differing words. All 26 emitted differences are COP1 register
 * fields; opcodes, constants, addresses and branches agree. The remaining
 * word is outside the emitted object. No padding or register bindings added.
 *
 * The typed direct body is 38 words. Reusing the left coordinate is 36;
 * wrapping the bottom addition with addF is 31. Inline multiplication of
 * the dimensions brings that candidate to 27 and is retained below.
 * Origin/depth/inset wrappers, aggregate dimensions and compiler controls
 * do not close the floor. Reversing multiplication helper argument order
 * also remains 27. Register hints do not improve the direct body.
 *
 * The signature matches the recovered c860 callers: root, float duration
 * scale, integer direction. Geometry uses a 640x480 rectangle centered in
 * a 640x448 space. Initial vertices snapshot position before the camera
 * callback; e360 deliberately reloads root position after all four vertex
 * callbacks. Production remains INCLUDE_ASM pending exact allocation.
 *
 * Native Clang ASan/UBSan/float-cast-overflow smoke passed with ddf0:
 * 30,960 scenarios / 123,840 vertices, including both duration scales,
 * timing boundaries, directions, easing/camera/vertex mutations, geometry
 * snapshots, post-callback position reloads and the signed e360 result.
 */
static inline f32 mulF(f32 a, f32 b) { return a * b; }
void func_0034db60(u8 *arg0, f32 fparg0, s32 arg1) {
    f32 elapsed;
    f32 height;
    f32 width;
    f32 depth;
    f32 top;
    f32 left;
    f32 right;
    f32 inset_y;
    f32 inset_x;
    f32 bottom;
    f32 reciprocal;
    f32 duration;
    f32 amount;

    duration = *(f32 *)(arg0 + 0x1688) * fparg0;
    if (*(s32 *)(arg0 + 0x1690) == 0) {
        elapsed = (f32)*(s16 *)(arg0 + 0x1684);
        if (elapsed < duration) {
            amount = func_0044b7b0((iGpffff8094 * elapsed) / duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (arg1 == 0) {
        amount = 1.0f - amount;
    }
    width = mulF(640.0f, amount);
    inset_x = (640.0f - width) / 2.0f;
    height = mulF(480.0f, amount);
    inset_y = (448.0f - height) / 2.0f;
    *(s32 *)(arg0 + 0x990) = 0;
    top = inset_y + *(f32 *)(arg0 + 0x9A0);
    left = inset_x + *(f32 *)(arg0 + 0x99C);
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    func_0034f0d0(arg0 + 0x690, left, top, depth, reciprocal, 255, 233, 44, 255);
    bottom = addF(top, height);
    func_0034f0d0(arg0 + 0x6D0, left, bottom, depth, reciprocal, 255, 233, 44, 255);
    right = addF(left, width);
    func_0034f0d0(arg0 + 0x710, right, bottom, depth, reciprocal, 255, 233, 44, 255);
    func_0034f0d0(arg0 + 0x750, right, top, depth, reciprocal, 255, 233, 44, 255);
    *(s16 *)(arg0 + 0x1670) = func_0034e360(arg0, inset_x + *(f32 *)(arg0 + 0x99C), inset_y + *(f32 *)(arg0 + 0x9A0), width, height);
    func_0034ee90(arg0, 0.0f, 0.0f, amount);
}

/* Current byte-contract floor: MWCCPS2 b210, 460B/464B. One differing
 * emitted word at +0x24: andi s2,a1,255 instead of retail's daddu s2,a1,zero.
 * The other raw fndiff word is the four-byte zero tail at +0x1CC.
 * Promoting opacity into the s32 alpha local improves the previous eight
 * emitted residuals to one. Direct byte increment replaces the unnecessary
 * inline helper and opt_common_subs pragma. The existing live caller
 * func_0020b3a0 remains exact: 500B/512B, twelve zero-tail bytes.
 * Recompiling the installed archive preserves all 115 existing MATCH bodies
 * in the current owner.
 *
 * A coherent word-opacity variant is exact for all 460 target bytes:
 * use s32 opacity and forward it directly, without the alpha local.
 * Both target definition and caller declaration must change. The actual
 * func_00201650 already takes s32 opacity and owns the low-byte truncation;
 * retail's entry daddu preserves the incoming word.
 * That change still reorders the live caller's +0x190/+0x194/+0x198:
 * lbu a1 moves before the pointer/f13 moves instead of after them.
 * Local byte/float values, redundant casts, parameter order, propagation,
 * common-subexpression settings, schedule off and explicit &0xFF do not
 * preserve the caller match. Neither variant is promoted; no conflicting
 * block-local prototype is an acceptable substitute for a coherent contract.
 *
 * Native32 actual position/depth/color/mode helpers under undefined/function
 * sanitizer traps: 524,288 byte scenarios / 7,864,320 tile emissions;
 * 2,097,152 word scenarios / 31,457,280 emissions. Covers every initial
 * counter/opacity byte, positive/negative opacity high bits, counter wrap
 * and callback mutations, row-major coordinates at two scales, white
 * colors, depth 50, callback replacement and final resets.
 *
 * D_00764564 is the byte at gp-0x4B8C, address 0x00764564. The misleading
 * iGpffffb474 name resolves to the separate battle pointer at 0x0076449C.
 * A future promotion must register D_00764564, not reuse that alias.
 * All GP and callback-table relocations have zero addends; direct calls
 * resolve to their actual retail callees. Production remains ASM. */
#pragma push
#pragma opt_propagation off
// FUN_00204B80
void func_00204b80(u8 *arg0, f32 farg0, f32 farg1, u8 opacity)
{
    extern u8 D_00764564;
    extern void (*D_00887300[])(u32, u32);
    extern void func_002012d0(u8 *, f32, f32);
    extern void func_002019e0(u8 *, f32);
    extern void func_00201820(s32);
    extern void func_00201650(u8 *, s32, s32, f32, f32, s32, s32, s32, s32);
    s32 alpha = opacity;
    s16 row;
    s16 column;
    s16 frame;
    f32 x;
    f32 y;

    {
        void (**state)(u32, u32);

        state = D_00887300;
        state[0](6, 1);
    }
    func_002012d0(arg0, 36.0f, 19.0f);
    func_002019e0(arg0, 50.0f);
    func_00201820(2);
    y = 0.0f;
    row = 0;
    while (row < 3) {
        x = 0.0f;
        column = 0;
        while (column < 5) {
            frame = D_00764564 % 4;
            D_00764564++;
            func_00201650(arg0, 15, frame, x, y, 255, 255, 255, alpha);
            x += 126.0f;
            column++;
        }
        y += 126.0f;
        row++;
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    {
        void (**state)(u32, u32);

        state = D_00887300;
        state[0](6, 0);
        state[0](1, 0);
    }
}
#pragma pop

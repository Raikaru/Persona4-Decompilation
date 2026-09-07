/* Defined byte-contract floor: object 460B / retail window 464B, nine
 * relocation-masked differing words: eight argument-setup words and one
 * zero-tail word. Actual source and position/depth/color helpers pass
 * 262,144 native32 draw-command scenarios under undefined/function sanitizers.
 * The renderer emits fifteen white sprites in a 3x5 grid with 126-unit
 * spacing. All initial counter/opacity bytes and callback counter mutations
 * are covered, including wrap, state-callback replacement and final reset.
 * Initial depth is 50.0f, not the superseded draft's 72.0f. Integer-promoted
 * byte remainder preserves the retail unsigned load and signed-remainder
 * sequence without inventing a negative-byte branch.
 *
 * A word-opacity variant matches all 460 executable bytes, but changing its
 * live caller func_0020b3a0 to the same prototype reorders three instructions.
 * That coherent ABI variant is not promotable. Keep the live byte contract;
 * do not hide incompatible declarations. Production remains ASM.
 *
 * D_00764564 is the byte at gp-0x4B8C. The misleading iGpffffb474 name
 * currently resolves to the separate battle pointer at 0x0076449C.
 * A future promotion must register D_00764564, not reuse that alias.
 * The inline update boundary retains the second byte load while allowing
 * caller CSE to share the three white color arguments. */
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
static inline void advanceDrawFrame(void)
{
    extern u8 D_00764564;
    D_00764564 = D_00764564 + 1;
}
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
            advanceDrawFrame();
            func_00201650(arg0, 15, frame, x, y, 255, 255, 255, opacity);
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

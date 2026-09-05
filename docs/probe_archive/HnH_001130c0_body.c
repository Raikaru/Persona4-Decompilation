/*
 * IDA-led safe floor: object 440B / retail window 448B / seven differing words.
 * Five emitted-word differences remain at 0x6C..0x7C: cached G/B byte loads
 * and alpha arithmetic are scheduled in the opposite order. Two zero-tail
 * words are absent. All other relocation-masked instructions match.
 * IDA: docs/ida_headstart/src/promoted/code1_0011.c:618-668. Assembly/caller
 * evidence supplies the Vec2f-by-value and independent float-scale ABI that
 * Hex-Rays misidentifies as integer values. Keep all eleven sprite arguments.
 * Real layout: 76-byte text plus four-byte Color; no fabricated padding.
 * Aggregate Color copy and narrow loop snapshots restore retail accesses.
 * Plain alpha expression keeps the seven-word floor; moving it after the
 * cache assignments gives 15. Propagation-off and declaration/loop-invariant
 * variants did not close the scheduling residual. Production remains ASM.
 * Native smoke: 1920 cases cover signed formatted values, alpha extremes,
 * reversed glyphs, cached colors, post-formatter width reads, and float order.
 */
void func_001130c0(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    typedef struct { u8 r, g, b, a; } Color;
    struct {
        s8 text[0x4C];
        Color color;
    } stack;
    s16 temp_21;
    u32 color2;
    u32 color1;
    s32 alpha_byte;
    s32 var_20;
    u8 loop_color2;
    u8 loop_color1;
    u8 *temp_2;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;
    extern s32 func_00442088(void *, const void *, ...);
    extern s32 func_00442948(const void *);

    temp_21 = *(s16 *)(arg2 + 2);
    temp_2 = D_005E4770 + (*(s16 *)(arg2 + 0x16) * 4);
    stack.color = *(Color *)temp_2;
    alpha_byte = 255 - arg1;
    color2 = stack.color.b;
    color1 = stack.color.g;
    func_0046d4c0(0, arg3, 0x47, arg0.x, 2.0f + arg0.y,
                  alpha_byte, stack.color.r, color1, color2,
                  fparg0, 0);
    func_00442088(stack.text, &iGpffff9bec, (s16)temp_21);
    arg0.x = arg0.x + (14.0f +
        *(f32 *)(D_005E4798 + (*(s16 *)(arg2 + 0x18) * 0x10)));
    var_20 = func_00442948(stack.text) - 1;
    loop_color2 = color2;
    loop_color1 = color1;
    while (var_20 >= 0) {
        func_0046d4c0(0, arg3, stack.text[var_20] - 0x27,
                      arg0.x, arg0.y, alpha_byte,
                      stack.color.r, loop_color1, loop_color2, fparg0, 0);
        arg0.x -= 14.0f;
        var_20--;
    }
}

/* func_001130c0; object 432B; retail window 448B; best normalized_diff 54 (fndiff differing words, including missing tail and relocation-owned words); visible differing offsets 0x048, 0x04C, 0x050, 0x054, 0x058, 0x05C, 0x060, 0x064, 0x06C, 0x070, 0x07C, 0x090, 0x0A8, 0x0AC, 0x11C, 0x120, 0x124, 0x128, 0x12C, 0x130, 0x134, 0x138, 0x13C, 0x140, 0x144, 0x148, 0x14C, 0x150, 0x15C, 0x160, 0x164, 0x168, 0x16C, 0x170, 0x174, 0x178, 0x17C, 0x180, 0x184, 0x188, 0x18C, 0x190, 0x194, 0x198, 0x19C, 0x1A0, 0x1A4, 0x1A8, 0x1AC; relocation-owned offsets 0x040/0x044 (D_005E4770), 0x0CC (iGpffff9bec), 0x0E0/0x0E4 (D_005E4798), and call sites; ruled out: direct table indexing (recomputes base and emits extra relocations), separate byte locals (changes frame/register saves), explicit f32 y local (adds f21 save), signed s16 intermediates (adds sign extension), alpha staging as u8 (adds mask and shifts call), alpha staging as s32 (wrong saved-register allocation), temporary pointer width changes and postincrement/indexed byte-load spellings, declaration-order permutations tried so far, and branch/goto source reshaping. Hex-Rays and Ghidra agree on stack byte staging, color table lookups, glyph loop, and width-table stride. */
void func_001130c0(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    struct {
        u8 bytes[0x50];
    } stack;
    s16 temp_21;
    u8 color2;
    u8 color1;
    s32 alpha_byte;
    s32 var_20;
    u8 *temp_2;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;

    temp_21 = *(s16 *)(arg2 + 2);
    temp_2 = D_005E4770 + (*(s16 *)(arg2 + 0x16) * 4);
    stack.bytes[0x4C] = *temp_2++;
    stack.bytes[0x4D] = *temp_2++;
    stack.bytes[0x4E] = *temp_2++;
    stack.bytes[0x4F] = *temp_2++;
    color2 = stack.bytes[0x4E];
    color1 = stack.bytes[0x4D];
    alpha_byte = 0xFFU - (arg1 & 0xFFU);
    func_0046d4c0(0, arg3, 0x47, arg0.x, 2.0f + arg0.y,
                  alpha_byte, stack.bytes[0x4C], color1, color2,
                  fparg0, 0);
    func_00442088(stack.bytes, &iGpffff9bec, (s16)temp_21);
    arg0.x = arg0.x + (14.0f +
        *(f32 *)(D_005E4798 + (*(s16 *)(arg2 + 0x18) * 0x10)));
    var_20 = func_00442948(stack.bytes) - 1;
    while (var_20 >= 0) {
        func_0046d4c0(0, arg3, ((s8 *)stack.bytes)[var_20] - 0x27,
                      arg0.x, arg0.y, alpha_byte,
                      stack.bytes[0x4C], color1, color2, fparg0, 0);
        arg0.x -= 14.0f;
        var_20--;
    }
}

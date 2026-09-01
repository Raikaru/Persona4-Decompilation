/*
 * Best plain-C reconstruction for func_0038b1c0.
 * Measured object_size=712B, retail window=720B, normalized_diff=6.
 * Differing words (reloc-masked): +0x144 (ff000624 addiu $a2,$zero,0xff
 * versus retail ff000664 daddiu $a2,$zero,0xff), +0x148
 * (be000724 addiu $a3,$zero,0xbe versus retail be000764 daddiu
 * $a3,$zero,0xbe), +0x14c (5a000824 addiu $t0,$zero,0x5a versus
 * retail 5a000864 daddiu $t0,$zero,0x5a), +0x1b4 (2b000624 addiu
 * $a2,$zero,0x2b versus retail 2b000664 daddiu $a2,$zero,0x2b),
 * +0x1b8 (26000724 addiu $a3,$zero,0x26 versus retail 26000764
 * daddiu $a3,$zero,0x26), and +0x1bc (1e000824 addiu $t0,$zero,0x1e
 * versus retail 1e000864 daddiu $t0,$zero,0x1e).
 *
 * All control flow, calls, conversions, and the two COP1 accumulator-chain
 * operations reproduced. The chain is ordinary C: the scaled color alpha is
 * split into `scaled`, leaving `alpha` in $f20 for the later madd.s chain;
 * this reproduces the retail mul.s/c.ole.s/cvt.w.s $f1 sequence and the
 * final andi $t1 result materialization.
 *
 * The six residual daddiu instructions all have $zero as their source
 * register, so they are constant-materialization daddiu and are unreachable
 * with this compiler's plain-C code generation (documented daddiu family
 * floor). A 64-bit local, 64-bit return type, ULL literal, pointer
 * difference, and propagation pragma were ruled out; only a 64-bit add with
 * a live register source can emit daddiu.
 *
 * D_0064EFB0 is a real, placeable data symbol; no string/float-pool/jump-table
 * reference was introduced. func_00373cb0 and func_0034f460 are real calls.
 */
void func_0038b1c0(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2,
                             s32 arg0);
    extern void func_0034f460(s32 arg0, s32 arg1, s64 arg2, s64 arg3,
                              s64 arg4, s64 arg5, f32 fparg0, f32 fparg1);
    extern s32 D_0064EFB0[];
    u8 *base;
    s32 palette;
    s32 i;
    u16 *counter;
    f32 alpha;
    f32 scaled;
    s64 alpha_byte;
    s64 red;
    s64 green;
    s64 blue;
    counter = (u16 *)(arg0 + 0x164);
    base = *(u8 **)arg0;
    palette = *(s32 *)(base + 0x1F2AC);
    if (*counter < 30) {
        ++*counter;
    }
    for (i = 0; i < 11; i++) {
        u8 *entry;
        entry = (u8 *)D_0064EFB0 + i * 0x14;
        if (*counter < *(s32 *)(entry + 8)) {
            alpha = 0.0f;
        } else if (*counter < *(s32 *)(entry + 0xC)) {
            alpha = func_00373cb0(
                (f32)*counter,
                (f32)*(s32 *)(entry + 8),
                (f32)*(s32 *)(entry + 0xC),
                1);
        } else {
            alpha = 1.0f;
        }
        if (i == 5) {
            func_003f6440(3, 0x71801);
            func_003f6440(2, 0x48);
        }
        if (i < 5) {
            red = 0xFF;
            green = 0xBE;
            blue = 0x5A;
            scaled = 206.0f * alpha;
            alpha_byte = (u8)scaled;
        } else {
            red = 0x2B;
            green = 0x26;
            blue = 0x1E;
            scaled = 255.0f * alpha;
            alpha_byte = (u8)scaled;
        }
        func_0034f460(
            palette,
            *(s32 *)((u8 *)D_0064EFB0 + i * 0x14 + 0x10),
            red, green, blue, alpha_byte,
            30.0f * (1.0f - alpha) +
                *(f32 *)((u8 *)D_0064EFB0 + i * 0x14) + 0.0f,
            *(f32 *)((u8 *)D_0064EFB0 + i * 0x14 + 4));
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}

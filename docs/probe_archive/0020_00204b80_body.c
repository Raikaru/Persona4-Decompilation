/* lane=0020 addr=00204b80
 * object_size=460 window=464 normalized_diff=196
 * differing words (reloc-masked): 68
 * residual offsets (notable): 0x28-0x3c (D_00887300 start call order),
 *   0x7c-0x98 (float f20/f21 init & branch order),
 *   0x9c-0xcc (iGpffffb470 load/store register and offset),
 *   0xd8-0xec (func_00201650 float argument registers),
 *   0x104-0x150 (loop counter updates: daddiu vs addiu and dsll/dsra target),
 *   0x174-0x198 (D_00887300 end calls not cached in s0).
 * levers tried:
 *   - iGpffffb470 as scalar u8 vs array[8] vs [4] (scalar best, still v0 vs retail v1)
 *   - D_00887300[0] direct, cached in void(**base) block, and top-level base (none produced s0 reuse at end)
 *   - s64 i/j with (s64)(i<<0x30)>>0x30 loops (produces daddiu; retail uses addiu+dsll32/dsra32 0x10)
 *   - s16 conditions and (s32)i+1 updates (worse, 98 diffs)
 *   - f32 f20/f21 declaration and call order swaps (call swapped to f20,f21 but increments still swapped)
 *   - #pragma peephole off (worse, 114 diffs and 520B)
 */
// FUN_00204B80
void func_00204b80(u8 *arg0, s8 arg1)
{
    extern u8 iGpffffb470;
    s64 i;
    s64 j;
    s32 var_2;
    f32 f20;
    f32 f21;

    D_00887300[0](6, 1);
    func_002012d0(arg0, 36.0f, 19.0f);
    func_002019e0(arg0, 50.0f);
    func_00201820(2);
    f20 = 0.0f;
    i = 0;
    while (((s64)(i << 0x30) >> 0x30) < 3) {
        f21 = 0.0f;
        j = 0;
        while (((s64)(j << 0x30) >> 0x30) < 5) {
            var_2 = iGpffffb470 & 3;
            if (((s32)iGpffffb470 < 0) && (var_2 != 0)) {
                var_2 -= 4;
            }
            iGpffffb470 += 1;
            func_00201650(arg0, 15, (s16)var_2, f21, f20, 255, 255, 255, arg1);
            f21 += 126.0f;
            j = (s64)((j + 1) << 0x30) >> 0x30;
        }
        f20 += 126.0f;
        i = (s64)((i + 1) << 0x30) >> 0x30;
    }
    func_00201820(0);
    func_002019e0(arg0, 0.0f);
    D_00887300[0](6, 0);
    D_00887300[0](1, 0);
}

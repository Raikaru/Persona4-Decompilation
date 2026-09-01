/* object 100B, retail window 96B, normalized_diff 64; differing word offsets 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60; classification: caller-saved versus callee-saved register coloring/frame floor; ruled out corrected three-argument callee declaration, pointer/struct-width variants, old-style/variadic declarations, goto/while/do-while shapes, O0/O1/O2/O3/O4, and opt_propagation/schedule pragmas. */
s32 func_001b0dd0(s32 arg0)
{
    s32 result;

    result = 0;
    while (func_001b0d00((s32 *)((u8 *)iGpffffb3ac + 0x29C), 0xC, arg0) == 1) {
        result = 1;
    }
    return result;
}

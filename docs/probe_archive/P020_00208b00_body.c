/* Main 2026-09-03: nd19 -> 6. var_16 and the return type are u16 (retail daddiu constants, no re-mask at
   the return, default `andi s0,a0` = (u16) of the CSE'd constant 1); the row address is `idx2 + (u32)arg1`
   with idx2 a named local (retail addu v0,v0,s1). Remaining 3 words: retail loads the iGpffffb3b8 base
   before masking/scaling the index; b210 masks first for every indexing spelling (u8*, u16[], struct[],
   assignment-expression base, named offset), and opt_propagation off / schedule on change the whole
   function (nd115+). */
/* object_size=500 window=512 normalized_diff=19 differing_offsets=0x5E,0x5F,0x98-0x9D,0xE7,0x10B,0x1D0,0x1AB,0x1D0 classification=near-miss register/codegen residual (commutative address addu operand order, global-address load ordering, daddiu-vs-addiu constant width, and default-result mask materialization); ruled_out=retail window has no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; corrected block-scope declarations func_00202e70(void)->s32, func_0023ddc0(u8*,s32)->s32, func_0023df70(s32)->s32, func_0045af60(s32,s32,s32,s32); best probe v2 retained below, source restored to INCLUDE_ASM. */
u16 func_00208b00(u8 *arg0, u8 *arg1)
{
    extern s32 func_00202e70(void);
    extern s32 func_0023ddc0(u8 *arg0, s32 arg1);
    extern s32 func_0023df70(s32 arg0);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *iGpffffb3b8;
    s32 temp_2;
    u16 var_16;
    u16 temp_16;
    s32 idx2;

    var_16 = func_00202e70() & 0xFFFF;
    switch (var_16) {
    case 2:
        idx2 = (s32)*(s16 *)(arg0 + 4) * 2;
        temp_16 = *(u16 *)(idx2 + (u32)arg1 + 0x194);
        if (func_0023ddc0(*(u8 **)(*(u8 **)(*(u8 **)(arg1 + 0x178) +
                                           0x30) + 0xA64),
                          temp_16) == 0) {
            if ((func_0023df70(temp_16) != 0) &&
                ((*(u16 *)(iGpffffb3b8 + (temp_16 & 0xFFFF) * 4 + 2) &
                  0x8000) == 0)) {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 1;
            } else {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 2;
            }
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = temp_16;
            *(s16 *)(arg1 + 0x1A) = 0;
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            var_16 = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    default:
        var_16 = 1;
        break;
    }
    return var_16;
}

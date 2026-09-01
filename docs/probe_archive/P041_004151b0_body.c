/* object 540B/window 400B, normalized_diff 413, differing offsets 0x000-0x1F8 (130 differing words; object oversized); classification: MWCC candidate with wrong frame/global declaration/statement order; archive-immediately condition reached. Retail prologue: addiu $sp,-48; beqz $a0,.L00415310; sd $ra,0($sp) in delay slot; frameless callee-save profile (no sq/sd $s save). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature. Corrected block-scope declarations for D_00887404, D_008872E0, iGpffffb3b8, iGpffffac28..ac2b, func_003df590, and func_003df4d0; no further probe after oversized residual. */
// FUN_004151B0
u8 *func_004151b0(u8 *arg0)
{
    extern s32 iGpffffb3b8;
    extern u8 iGpffffac28;
    extern u8 iGpffffac29;
    extern u8 iGpffffac2a;
    extern u8 iGpffffac2b;
    extern u8 D_008872E0[];
    extern u8 D_00887404[];
    extern s32 func_003df590(s32);
    extern void func_003df4d0(s32 *);
    u8 *base;
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    s32 fail_words;
    s32 fail_value;

    if (arg0 != NULL) {
        if (*(s32 *)D_00887404 != 3) {
            base = D_008872E0 + iGpffffb3b8;
            if (arg0 != base + 4) {
                fail_words = 1;
                fail_value = func_003df590(0x80000018);
                func_003df4d0(&fail_words);
                goto fail;
            }
            color0 = iGpffffac28;
            color1 = iGpffffac29;
            color2 = iGpffffac2a;
            color3 = iGpffffac2b;
            *(s32 *)(arg0 + 0) = 7;
            *(s32 *)(arg0 + 4) = 2;
            *(s32 *)(arg0 + 8) = 5;
            *(s32 *)(arg0 + 0xC) = 6;
            *(s32 *)(arg0 + 0x10) = 0;
            *(s32 *)(arg0 + 0x14) = 1;
            *(s32 *)(arg0 + 0x18) = 1;
            *(s32 *)(arg0 + 0x1C) = 2;
            *(u8 *)(arg0 + 0x20) = color0;
            *(u8 *)(arg0 + 0x21) = color1;
            *(u8 *)(arg0 + 0x22) = color2;
            *(u8 *)(arg0 + 0x23) = color3;
            *(s32 *)(arg0 + 0x24) = 0;
            *(u8 *)(arg0 + 0x28) = color0;
            *(u8 *)(arg0 + 0x29) = color1;
            *(u8 *)(arg0 + 0x2A) = color2;
            *(u8 *)(arg0 + 0x2B) = color3;
            return arg0;
        }
        base = D_008872E0 + iGpffffb3b8;
        *(s32 *)(arg0 + 0) = *(s32 *)(base + 4);
        *(s32 *)(arg0 + 4) = *(s32 *)(base + 8);
        *(s32 *)(arg0 + 8) = *(s32 *)(base + 0xC);
        *(s32 *)(arg0 + 0xC) = *(s32 *)(base + 0x10);
        *(s32 *)(arg0 + 0x10) = *(s32 *)(base + 0x14);
        *(s32 *)(arg0 + 0x14) = *(s32 *)(base + 0x18);
        *(s32 *)(arg0 + 0x18) = *(s32 *)(base + 0x1C);
        *(s32 *)(arg0 + 0x1C) = *(s32 *)(base + 0x20);
        *(u8 *)(arg0 + 0x20) = (u8)*(f32 *)(base + 0x24);
        *(s32 *)(arg0 + 0x24) = *(s32 *)(base + 0x28);
        *(u8 *)(arg0 + 0x28) = (u8)*(f32 *)(base + 0x2C);
        return arg0;
    }
    fail_words = 1;
    fail_value = func_003df590(0x80000016);
    func_003df4d0(&fail_words);
fail:
    return NULL;
}

/* Floor for func_002df020 (retail 0x002DF020, window 296 words/1184B).
 * Probe: 219 reloc-masked differing words, emitted 301 words/1204B.
 * Frame matches retail 0xC0 (sd $ra + sq s3/s2/s1/s0). Prior archive scored 235
 * with frame 0xE0 (wrong float order, M2C raw int ordering).
 * Levers: u64 Vec2f slots, Vec2f direct pass, (f32)0x1F1, goto order 0,1,2.
 * Residual: work $s0 vs $s1 (off 32,36, ~10 words); IROEVAL branch-around-goto
 * folds beq-over-b to bnez (6 words before L0, not 8), shifting later by 8.
 * See owner note at y_fclShopDraw.c FUN_002DF020 NONMATCHING.
 */
void func_002df020(void *arg0, s64 arg1, s32 arg2) {
    extern u8 iGpffffa890[];
    extern u8 D_0063FAA0[];
    s32 tmp;
    u8 *work;
    RGBA spBC;
    RGBA spB8;
    RGBA spB4;
    u64 spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    u64 sp88;
    u64 sp80;
    Vec2f sp78;
    u64 sp70;
    Vec2f sp68;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0x11) == 2) {
        goto L2;
    }
    if (*(s8 *)(work + 0x11) == 1) {
        goto L1;
    }
    if (*(s8 *)(work + 0x11) == 0) {
        goto L0;
    }
    goto Ljoin;
L0:
    func_002b2970(&spA0, 97.0f, 178.0f);
    func_002e0ca0(0x1A, spA0, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L1:
    tmp = func_002d4f30((s16)func_00106880((s16)arg1)) & 0xFFFF;
    func_002b2970(&sp98, 97.0f, 178.0f);
    func_002e0b20(tmp, sp98, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L2:
    func_002b2970(&sp90, 97.0f, 178.0f);
    func_002e0ca0(0x1B, sp90, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
Ljoin:
    tmp = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp88, 140.0f, 178.0f);
    sp68 = *(Vec2f *)&sp88;
    func_00275680(sp68.x, sp68.y, 13.0f, tmp, 0, 1, (const char *)func_001067f0((s32)arg1), 0, 0, D_00795E30, -1);
    tmp = func_00106a90((s16)arg1) / 5U;
    func_002b2970(&sp80, 448.0f, 185.0f);
    func_002b2a60(&spBC, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(sp80, 13.0f, spBC, 0x10, 5, (u32)tmp, 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp78, 476.0f, 187.0f);
    func_002e0b20(0x47, sp78, 13.0f, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    spA8 = *(u64 *)(iGpffffa890 - 8);
    if (*(s16 *)(work + 0x12) < 10) {
        *(f32 *)&spA8 = *(f32 *)&spA8 - 8.0f;
    }
    func_002b2a60(&spB8, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(spA8, 13.0f, spB8, 0x10, 5, *(s16 *)(work + 0x12), 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp70, (f32)0x1F1, 247.0f);
    func_002b2a60(&spB4, 0xDF, 0x6C, 0, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC8)) + 0x62));
    tmp = (s32)func_0046a770(D_0063FAA0);
    func_002cacd0(sp70, 1.0f, spB4, 0x1B, 0, arg2 & 0xFF, 0x2F, 0, tmp, (s32)func_0046a770(D_0063FAA0), 0xA9);
}

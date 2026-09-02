/* FclCombineDraw_0032c480_body.c
 * Reconstruction archive (not compiled source).
 * Target: func_0032c480 @ 0x0032c480
 * Best measured: object 480B, retail window 480B, fndiff differing words 65, normalized_diff 214.
 * Residual: retail obj=$s1/c=$s0/n=$s0 vs candidate obj=$s0/c=$s1/n=$s1 saved-register
 *   rotation; func_002e48a0(0, s16) calls emit lh-before-move-a0 in candidate
 *   (retail move-a0-first); func_00330e50 call materializes D_00796310 address
 *   before mov.s f13/f14 (retail after).
 * Levers tried: separate s32/s16/s8 temp locals; one-s16-reused; decl-swap;
 *   s8 cast for func_00331640 result; c-first-statement; schedule on/off;
 *   D_00796310/00796370 typed as u8*; 140.0f/101.0f/1.0f constants; inline-color.
 */
void func_0032c480(u8 *arg0) {
    u8 *obj;
    FclVec2 sp38;
    s32 c;
    s16 n;
    u16 index;

    obj = *(u8 **)(arg0 + 0x38);
    c = func_002b2a30(0, 0, 0, 0xFF);
    index = *(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2);
    func_00275820(c, 0, 2, iGpffffb440 + index * 0x11, 0, 0,
                  D_00796310, 0x15, 140.0f, 101.0f, 1.0f);
    n = (s16)((func_00109280(*(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2)) & 0xFF) + 0x1B);
    func_002b2970((s64 *)&sp38, 54.0f, 103.0f);
    func_00330e50(n, *(s64 *)&sp38, 1.0f, 0xFF000000, 0xFF, 1,
                  1.0f, 1.0f, D_00796310);
    n = (s16)func_00331640();
    func_00279350(-1, 1, 0, 1, n,
                  *(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2),
                  D_00796370, 54.0f, 138.0f, 1.0f);
    func_0034a640(*(s32 *)(obj + 0x254),
                  *(u16 *)(func_002e48a0(0, *(s16 *)(obj + 0x11E)) + 2), 1);
    *(s8 *)(func_0034a630((u8 *)*(s32 *)(obj + 0x254)) + 1) = 0;
    func_0011d1d0((u8 *)*(s32 *)(*(u8 **)(*(u8 **)(obj + 0x148) + 0x38) + 4),
                  64000.0f);
}

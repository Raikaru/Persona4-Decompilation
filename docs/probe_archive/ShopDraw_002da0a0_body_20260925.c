/* func_002da0a0 (y_fclShopDraw.c) draft, measured 2026-09-25 with
 * tools/fndiff.py against the unit at commit c4d2387: 4952 native bytes in
 * the 4960-byte window, 50 reloc-masked differing words, every one the same
 * saved-register swap in the five D_0063FA48-table groups (work+0xD44,
 * D4C, D50, D54, D58): retail keeps the table pointer `fa` in $s1 and the
 * func_0046d200 handle `r` in $s2; this body has them the other way round.
 * Everything else (frame 0x160, $s0-$s4 + $f20, all 24 position locals,
 * the ten colour temporaries, the inlined cursor block) is exact.
 *
 * Unit changes this body needs (each measured with the rest of the unit
 * keeping its status; reverted while the function stays INCLUDE_ASM):
 *  1. func_002d83c0's body moves into `static inline void
 *     shopSwingCursor(void *arg0)` and func_002d83c0 becomes
 *     `{ shopSwingCursor(arg0); }` (still MATCH).  Retail inlines that
 *     block here (`lw $18, 0x38($18)` re-reads the work pointer from the
 *     kept arg0).  Declaring func_002d83c0 `inline` also inlines it, but
 *     b210 then drops its out-of-line copy (NO_SYMBOL).
 *  2. `void func_002e09b0(void *, s16, f32);` (was s32): with the s32
 *     parameter the frames load is hoisted above the object load.  The
 *     callee (src/promoted/code1_002e.c) takes (u8 *, f32, s16).
 *  3. D_0063FA40/44/46 declared as arrays (`extern f32 D_0063FA40[];`,
 *     `extern s16 D_0063FA44[];`, `extern s16 D_0063FA46[];`): the scalar
 *     declarations are small data (gp-relative) and retail addresses them
 *     with lui/%lo; any D_0063FA48-relative spelling makes b210 CSE the
 *     frames address into a saved register (12 extra words).  The
 *     func_002be530 guarded body still reads them as scalars.
 *
 * Levers found: the unit's `(Vec2f *)` / `(ShopSwing *)` casts keep the
 * group bases in saved registers; `work = *(u8 **)((u32)arg0 + 0x38)` stops
 * b210 CSE-ing arg0+0x38 with the inlined re-read; the table groups pass
 * 0.0f as func_002e0940's second float (the `mtc1 $zero, $f13` after the
 * func_002e09b0 call belongs to it); the first cursor row's two y values
 * need `(f32)(s32)row` in the first and `(f32)row` in the second (the same
 * spelling twice is CSE'd across the func_002b2970 call; the cast also
 * gives retail's operand order), with `row` an s32 and the F46 index
 * `(s8)row`; the D60 object's `->0x100 = (->0x102 = 0)` chain gives
 * retail's `dsll32 $17, $0`.
 *
 * Tried without moving the fa/r swap: every tested declaration order of
 * work/base/fa/r (8), `register` on either, fa as u8 * / s32 / ShopSwing *,
 * r as void * / u8 * / s32, per-group fa variables, fa assigned before or
 * after base or before r, `fa++` between groups (505: changes code), the
 * cursor block written out sharing `r`, opt_propagation off (992), and
 * tools/permute.py for 1611 compiles (best 50).
 */
typedef struct {
    f32 angle;
    s16 delay;
    s16 frames;
} ShopSwing;

void func_002da0a0(void *arg0) {
    u8 *work;
    Vec2f *base;
    ShopSwing *fa;
    void *r;
    s16 i;
    s32 row;
    Vec2f p0;
    Vec2f p1;
    Vec2f p2;
    Vec2f p3;
    Vec2f p4;
    Vec2f p5;
    Vec2f p6;
    Vec2f p7;
    Vec2f p8;
    Vec2f p9;
    Vec2f p10;
    Vec2f p11;
    Vec2f p12;
    Vec2f p13;
    Vec2f p14;
    Vec2f p15;
    Vec2f p16;
    Vec2f p17;
    Vec2f p18;
    Vec2f p19;
    Vec2f p20;
    Vec2f p21;
    Vec2f p22;
    Vec2f p23;

    work = *(u8 **)((u32)arg0 + 0x38);
    func_002e04f0(*(void **)(work + 0xDEC), 0, 1);

    base = (Vec2f *)D_0063F5A0;
    func_002e09e0(*(void **)(work + 0xC58), 0x41, 162.0f);
    p0 = func_002b2970(base->x, base->y - 450.0f);
    p1 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xC58), *(u64 *)&p0, *(u64 *)&p1, 0, 4, 0);
    func_002e0660(*(void **)(work + 0xC58), 0, 0xCC, 0, 2, 0);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xC58)) + 0x79) = func_002b2a60(0, 0, 0, 0xFF);

    base = (Vec2f *)D_0063F5A8;
    func_002e09e0(*(void **)(work + 0xC5C), 0x41, 163.0f);
    p2 = func_002b2970(base->x, base->y - 450.0f);
    p3 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xC5C), *(u64 *)&p2, *(u64 *)&p3, 0, 4, 0);
    func_002e0660(*(void **)(work + 0xC5C), 0, 0xCC, 0, 2, 0);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xC5C)) + 0x79) = func_002b2a60(0, 0, 0, 0xFF);

    for (i = 0; i < *(s8 *)(work + 9); i++) {
        *(s16 *)(work + i * 2 + 0xF46) = 0;
        *(s16 *)(work + i * 2 + 0xF58) = 0;
        *(s8 *)(work + i + 0xF6A) = 0;
    }

    func_002e09e0(*(void **)(work + 0xED4), 0x41, 126.0f);
    row = *(s8 *)(work + 8);
    p4 = func_002b2970(47.0f, (78.0f + 35.0f * (f32)(s32)row) - 450.0f);
    p5 = func_002b2970(47.0f, 78.0f + 35.0f * (f32)row);
    func_002e0620(*(void **)(work + 0xED4), *(u64 *)&p4, *(u64 *)&p5, 0, 6, ((s16 *)(work + 0xF46))[(s8)row]);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xED4)) + 0x79) = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
    func_002e09e0(*(void **)(work + 0xED8), 0x41, 127.0f);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xED8)) + 0x79) = func_002b2a60(0xFE, 0xC6, 0x31, 0xFF);
    p6 = func_002b2970(126.0f, (78.0f + 35.0f * (f32)*(s8 *)(work + 8)) - 450.0f);
    p7 = func_002b2970(126.0f, 78.0f + 35.0f * (f32)*(s8 *)(work + 8));
    func_002e0620(*(void **)(work + 0xED8), *(u64 *)&p6, *(u64 *)&p7, 0, 6, 0);
    shopSwingCursor(arg0);

    func_002e09e0(*(void **)(work + 0xD3C), 0x41, 128.0f);
    func_002e0660(*(void **)(work + 0xD3C), 0, 0xFF, 0, 0xA, 0);

    base = (Vec2f *)D_0063F7B0;
    func_002e09e0(*(void **)(work + 0xD60), 0x41, 78.0f);
    p8 = func_002b2970(base->x, base->y - (f32)0x226);
    p9 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD60), *(u64 *)&p8, *(u64 *)&p9, 2, 4, 0);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x100) = *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x102) = 0;
    func_002e0940(*(void **)(work + 0xD60), -5.0f, fGpffff7ad4, 2, 2, 2);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD60)) + 0x79) = func_002b2a60(0xFF, 0x96, 0, 0xFF);

    base = (Vec2f *)D_0063F7B8;
    func_002e09e0(*(void **)(work + 0xD64), 0x41, 78.0f);
    p10 = func_002b2970(base->x, base->y - (f32)0x226);
    p11 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD64), *(u64 *)&p10, *(u64 *)&p11, 2, 4, 0);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x100) = -50;
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD64)) + 0x102) = -219;
    func_002e0940(*(void **)(work + 0xD64), -5.0f, fGpffff7ad4, 2, 2, 2);

    base = (Vec2f *)D_0063F8C0;
    func_002e09e0(*(void **)(work + 0xDE8), 0x41, 46.0f);
    func_002e0660(*(void **)(work + 0xDE8), 0, 0xFF, 0, 6, 0);
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDE8)) + 0x2C) = base->x;
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xDE8)) + 0x30) = base->y;

    func_002e09e0(*(void **)(work + 0xDF0), 0x41, 47.0f);
    func_002e0660(*(void **)(work + 0xDF0), 0, 0xFF, 0, 6, 0);

    r = func_0046d200(*(void **)(work + 0xF28), 0x44);
    base = (Vec2f *)D_0063F780;
    func_002e09e0(*(void **)(work + 0xD48), 0x56, 53.0f);
    p12 = func_002b2970(base->x, -130.0f);
    p13 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD48), *(u64 *)&p12, *(u64 *)&p13, 2, 5, 0);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD48)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    func_002e09b0(*(void **)(work + 0xD48), D_0063FA46[0], (f32)D_0063FA44[0]);
    func_002e0940(*(void **)(work + 0xD48), D_0063FA40[0], 0.0f, 2, D_0063FA46[0] + 5, 0);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x43);
    base = (Vec2f *)D_0063F778;
    fa = (ShopSwing *)D_0063FA48;
    func_002e09e0(*(void **)(work + 0xD44), 0x56, 54.0f);
    p14 = func_002b2970(base->x, -189.0f);
    p15 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD44), *(u64 *)&p14, *(u64 *)&p15, 2, 5, 3);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD44)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    func_002e09b0(*(void **)(work + 0xD44), fa->frames, (f32)fa->delay);
    func_002e0940(*(void **)(work + 0xD44), fa->angle, 0.0f, 2, fa->frames + 5, 3);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x45);
    base = (Vec2f *)D_0063F788;
    fa = (ShopSwing *)D_0063FA48 + 1;
    func_002e09e0(*(void **)(work + 0xD4C), 0x56, 55.0f);
    p16 = func_002b2970(base->x, -75.0f);
    p17 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD4C), *(u64 *)&p16, *(u64 *)&p17, 2, 5, 1);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD4C)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    func_002e09b0(*(void **)(work + 0xD4C), fa->frames, (f32)fa->delay);
    func_002e0940(*(void **)(work + 0xD4C), fa->angle, 0.0f, 2, fa->frames + 5, 1);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x46);
    base = (Vec2f *)D_0063F790;
    fa = (ShopSwing *)D_0063FA48 + 2;
    func_002e09e0(*(void **)(work + 0xD50), 0x56, 56.0f);
    p18 = func_002b2970(base->x, -165.0f);
    p19 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD50), *(u64 *)&p18, *(u64 *)&p19, 2, 5, 4);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD50)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD50), fa->frames, (f32)fa->delay);
    func_002e0940(*(void **)(work + 0xD50), fa->angle, 0.0f, 2, fa->frames + 5, 4);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x47);
    base = (Vec2f *)D_0063F798;
    fa = (ShopSwing *)D_0063FA48 + 3;
    func_002e09e0(*(void **)(work + 0xD54), 0x56, 57.0f);
    p20 = func_002b2970(base->x, -126.0f);
    p21 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD54), *(u64 *)&p20, *(u64 *)&p21, 2, 5, 2);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD54)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD54), fa->frames, (f32)fa->delay);
    func_002e0940(*(void **)(work + 0xD54), fa->angle, 0.0f, 1, fa->frames + 5, 2);
    func_0046d280(r);

    r = func_0046d200(*(void **)(work + 0xF28), 0x48);
    base = (Vec2f *)D_0063F7A0;
    fa = (ShopSwing *)D_0063FA48 + 4;
    func_002e09e0(*(void **)(work + 0xD58), 0x56, 58.0f);
    p22 = func_002b2970(base->x, -197.0f);
    p23 = func_002b2970(base->x, base->y);
    func_002e0620(*(void **)(work + 0xD58), *(u64 *)&p22, *(u64 *)&p23, 2, 5, 5);
    *(FclDrawColor *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x79) = func_002b2a60(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x100) = (s16)(func_0046b260(r) / 2.0f);
    *(s16 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0x102) = (s16)(func_0046b2f0(r) / 2.0f);
    *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xD58)) + 0xC4) = 0.0f;
    func_002e09b0(*(void **)(work + 0xD58), fa->frames, (f32)fa->delay);
    func_002e0940(*(void **)(work + 0xD58), fa->angle, 0.0f, 2, fa->frames + 5, 5);
    func_0046d280(r);
    *(s8 *)work = 0x14;
}

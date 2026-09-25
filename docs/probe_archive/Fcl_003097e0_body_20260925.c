/* Fcl result-state machine func_003097e0: best draft, 2026-09-25.
 *
 * Measured by splicing this whole file over func_003097e0's guarded region
 * (the `#ifdef NON_MATCHING ... #endif` block):
 *   object 6272B == retail window 6272B, 1568 == 1568 instructions,
 *   fndiff 23 differing words, fnalign 8 edit blocks. All of them are one
 *   register swap: in the two 6-iteration search loops (states 0xCC and 0xCE)
 *   retail keeps the outer counter in $t1 and the inlined search index in $t2.
 *   This draft gets them the other way round. (The old guarded draft was
 *   1293 words and 1603 instructions.)
 *
 * It needs two contract fixes elsewhere in y_fclCombine.c. Both were verified
 * to keep every other function's status:
 *   extern s8 func_00105f50(u16);          (retail passes cls with no mask)
 *   s32 func_00303a20(u8 *arg0) { ... return func_00303610(arg0, p[0x1A], buf); }
 * Once it matches, `iGpffffa8a4` (gp -0x575C = 0x00763994) must be added to
 * config/symbols_recovered.txt by running tools/recover_symbols.py.
 *
 * Levers that worked:
 * - cls is a u16 local.
 * - The slot search is a static inline that re-reads the work pointer. Retail
 *   inlines it at every use, compiled under `#pragma opt_loop_invariants on`,
 *   so the id constant and the count are hoisted.
 * - The fade tail is a second static inline. Each expansion gets its own
 *   pos[12]/colour stack slots, matching 0xE8/0xFC, 0xD8/0xF8, 0xC8/0xF4.
 * - func_003489c0 is (u8 *, u8 *, f32 x4, FclDrawColor, u16, u32), as in
 *   y_CmbCardEff.c.
 * - The zero-fill loop needs its own counter (k).
 * - v is s32.
 * - Locals are declared spA0, sp80, buf, in that order.
 *
 * Tried without fixing the $t1/$t2 swap (all still 23 words unless noted):
 * - Outer counter at function scope or block scope, declared first or last.
 * - Loop written as for, while, with an explicit (s8) cast, as an s32 counter
 *   with (s16) casts, or with a result temp.
 * - Helper with a found flag (worse).
 * - Helper taking an s32 id with an (s8) compare.
 * - Helper declaring i before w.
 * - While-form helper.
 * - Reloading the work pointer on every access (worse).
 * - One shared inline for the whole exit-check block (b210 does not inline it).
 * - tools/permute.py: 1310 compiles, no improvement.
 */
/* Membership test over the work's slot list (count at +0x2DF, entries at
   +0x2DA). Retail inlines it at every use and re-reads the work pointer. */
static inline s32 fclCombineHasEntry(u8 *task, s8 id)
{
    u8 *w = *(u8 **)(task + 0x38);
    s16 i;

    for (i = 0; i < *(s8 *)(w + 0x2DF); i++) {
        if (*(s8 *)(w + i + 0x2DA) == id) {
            return 1;
        }
    }
    return 0;
}

/* Starts the 20-frame fade used when the combine result is confirmed. */
static inline void fclCombineStartFade(u8 *task)
{
    extern u8 *func_001102f0(u8 *, s32, s32, f32);
    extern void func_003489c0(u8 *, u8 *, f32, f32, f32, f32, FclDrawColor, u16, u32);
    extern void func_00348c30(s32, s32);
    u8 *w = *(u8 **)(task + 0x38);
    u8 pos[12];
    FclDrawColor color;

    func_001102f0(pos, 0x140, 0xA5, 300.0f);
    color = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
    func_003489c0(*(u8 **)(w + 0x308), pos, 0.0f, 0.0f, 0.0f, 1.0f, color, 0, -1);
    func_00348c30(*(s32 *)(w + 0x308), 0x14);
    *(s16 *)(w + 0x2D8) = 0;
}

#pragma opt_loop_invariants on
void func_003097e0(u8 *arg0) {
    extern void func_0034a640(s32, u16, s32);
    extern s32 func_0033f690(u8 *, u16 *, s32);
    extern s32 func_003488d0(u8 *, void *, s32);
    extern s8 *func_0033fa20(s32);
    extern s32 func_00348be0(s32);
    extern s32 func_0033dc90(u8 *, s8);
    extern s16 func_00247770(s32);
    extern void func_00275980(void *, void *, s32);
    extern void func_0034a820(s32);
    extern void sprintf(void *, const char *, ...);
    extern void func_0045af60(s32, s32, s32, s32);
    extern s32 func_00311930(s32, u16 *, s32);
    extern s32 func_00311900(s32);
    extern void func_00314400(u8 *, s8);
    extern void func_00303de0(u8 *);
    extern void func_00310960(u8 *, s32, s32);
    extern u8 D_00641B50[];
    extern s32 iGpffffa8a4;
    u8 *p;
    u16 cls;
    s16 i;
    s16 j;
    s32 v;
    s16 k;
    char spA0[32];
    char sp80[32];
    u16 buf[12];

    p = *(u8 **)(arg0 + 0x38);
    cls = *(u16 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1);
    switch (p[1]) {
    case 0xC5:
        func_00106390(0x58, 0);
        func_00106390(0x59, 0);
        func_00106390(0x5A, 0);
        func_00106390(0x5B, 0);
        func_00106390(0x5C, 0);
        func_00106390(0x5D, 0);
        func_00106390(0x5E, 0);
        func_00106390(0x5F, 0);
        func_00106390(0x1450, 0);
        *(s8 *)(p + 0x26) = 0;
        *(s8 *)(p + 0x20) = 0;
        *(s16 *)(p + 0xE) = 0;
        *(s8 *)(p + 0x21) = 0;
        *(s16 *)(p + 0x2D8) = 0;
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        for (i = 0; i < 0x30C; i++) {
            func_002b68d0(i, 0, 1);
        }
        func_00303de0(arg0);
        func_0034a640(*(s32 *)(p + 0x254), cls, 0);
        *(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 0;
        for (k = 0; k < 0xC; k++) {
            buf[k] = 0;
        }
        switch (*(s8 *)(p + 0x1A)) {
        case 2:
            buf[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 1);
            break;
        case 3:
            buf[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x129)) + 1);
            buf[2] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 2);
            break;
        case 4:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 3);
            break;
        case 5:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 4);
            break;
        case 6:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            buf[5] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 5) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 5);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                buf[i] = *(u16 *)(func_002e48a0(0, i) + 1);
            }
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 6);
            break;
        }
        if (func_00105f50(cls) > 0) {
            *(s32 *)(p + 0x308) = func_003488d0(arg0, D_00641B50, 7);
        }
        p[1] = 0xC6;
        break;
    case 0xC6:
        if (*func_0033fa20(*(s32 *)(p + 0x304)) != 0 &&
            (func_00105f50(cls) <= 0 || func_00348be0(*(s32 *)(p + 0x308)) != 0)) {
            *(s32 *)(p + 0x300) = func_0033dc90(arg0, *(s8 *)(p + 0x1A) - 2);
            if (*(s8 *)(p + 0xB2) != 0) {
                func_00106390(0x5C, 1);
            }
            p[1] = 0xC7;
        }
        break;
    case 0xC7:
        if (datGetFlag(0x5B) != 0) {
            if (*(s8 *)(p + 0xB2) == 1) {
                func_00310960(arg0, 0x28, 0);
                p[1] = 0xC8;
                return;
            }
            if (*(s8 *)(p + 0xB2) == 2) {
                func_00310960(arg0, 0x29, 0);
                p[1] = 0xC8;
                return;
            }
            if (func_00303a20(arg0) == 1 && fclCombineHasEntry(arg0, 0xC) == 1) {
                p[1] = 0xCB;
                *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
                func_002badc0(*(s8 *)(p + 0xD), 0x2A);
                *func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
                return;
            }
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        }
        break;
    case 0xC8:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (func_00303a20(arg0) == 1 && fclCombineHasEntry(arg0, 0xC) == 1) {
            p[1] = 0xCB;
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002badc0(*(s8 *)(p + 0xD), 0x2A);
            *func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
            return;
        }
        if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
            p[1] = 0xCC;
            return;
        }
        *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
        sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
        func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
        func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
        p[1] = 0xCA;
        break;
    case 0xC9:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xC7;
        break;
    case 0xCA:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xCC;
        if (datGetFlag(0x5B) != 0) {
            p[1] = 0xCC;
        }
        break;
    case 0xCB:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (datGetFlag(0x5B) != 0) {
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        } else if (datGetFlag(0x5C) != 0) {
            p[1] = 0xC9;
        }
        p[1] = 0xC7;
        break;
    case 0xCC:
        if (func_00105f50(cls) == 0) {
            p[1] = 0xCF;
            if (func_00303a20(arg0) == 1) {
                if (fclCombineHasEntry(arg0, 7) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    *(s8 *)(p + 0x13C) = 1;
                    return;
                }
                if (fclCombineHasEntry(arg0, 0xD) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    *(s8 *)(p + 0x13C) = 3;
                    return;
                }
                if (fclCombineHasEntry(arg0, 0xA) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
                {
                    s16 m;
                    s32 mw;
                    s8 id;

                for (m = 0; m < 6; m++) {
                    if (fclCombineHasEntry(arg0, m + 1) == 1) {
                        func_00106390(0x59, 1);
                        *(s8 *)p = 0xC;
                        p[1] = 0xA0;
                        break;
                    }
                }
                }
                if (fclCombineHasEntry(arg0, 9) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
            }
        } else {
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(s8 *)(p + 0xD), 0,
                          iGpffffb44c + func_00109280(*(u16 *)(func_002e48a0(*(s8 *)(p + 0x2F9),
                                                                             *(s8 *)(p + 0x2FA)) + 1)) * 0x15);
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), 0x3A);
            p[1] = 0xCD;
        }
        break;
    case 0xCD:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (fclCombineHasEntry(arg0, 8) == 1) {
            v = func_00247770(iGpffffb3d4[cls * 0xE + 2]);
            *(s32 *)(p + 0x10) = func_00311930(v, func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 1);
            if (func_00303a20(arg0) == 1) {
                *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
                sprintf(spA0, (const char *)&iGpffffa8a4, func_00311900(func_00247770(iGpffffb3d4[cls * 0xE + 2])));
                func_00275980(spA0, sp80, 0x20);
                func_002bbd80(*(s8 *)(p + 0xD), 0, sp80);
                sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
                func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
                func_002badc0(*(s8 *)(p + 0xD), 0x55);
                *(s8 *)(p + 0x21) = 1;
                p[1] = 0xD0;
                return;
            }
            func_0034a820(*(s32 *)(p + 0x254));
            func_00106390(0x59, 1);
            fclCombineStartFade(arg0);
            p[1] = 0xD1;
        } else {
            v = func_00247770(iGpffffb3d4[cls * 0xE + 2]);
            *(s32 *)(p + 0x10) = func_00311930(v, func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 0);
            func_0034a820(*(s32 *)(p + 0x254));
            func_00106390(0x59, 1);
            fclCombineStartFade(arg0);
            p[1] = 0xD1;
        }
        break;
    case 0xCE:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xCF;
        if (func_00303a20(arg0) == 1) {
            if (fclCombineHasEntry(arg0, 7) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                *(s8 *)(p + 0x13C) = 1;
                return;
            }
            if (fclCombineHasEntry(arg0, 0xD) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                *(s8 *)(p + 0x13C) = 3;
                return;
            }
            if (fclCombineHasEntry(arg0, 0xA) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
            {
                s16 m;
                s32 mw;
                s8 id;

            for (m = 0; m < 6; m++) {
                if (fclCombineHasEntry(arg0, m + 1) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    break;
                }
            }
            }
            if (fclCombineHasEntry(arg0, 9) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
        }
        break;
    case 0xCF:
        func_00106390(0x59, 1);
        func_00106390(0x5D, 1);
        func_00106390(0x5F, 1);
        *(s8 *)p = 0xE;
        p[1] = 0xD2;
        func_00314400((u8 *)*(s32 *)(p + 0x148), 0);
        break;
    case 0xD0:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        func_0034a820(*(s32 *)(p + 0x254));
        func_00106390(0x59, 1);
        fclCombineStartFade(arg0);
        p[1] = 0xD1;
        break;
    case 0xD1:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x32, 0, 1);
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            func_0045af60(1, 0, 4, 5);
        }
        if (*(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 4) == 4 && *(s16 *)(p + 0x2D8) >= 0x14) {
            *(s8 *)p = 0xC;
            p[1] = 0xA0;
        }
        break;
    }
}
#pragma opt_loop_invariants reset

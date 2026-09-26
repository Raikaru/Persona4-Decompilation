/* func_002cdf80 (shop buy list: draw + input) best draft, 2026-09-26.
   fnalign: retail 3459 vs object 3459 instrs, 2 edits (+88 reloc-only), measured with
   `python3 tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002cdf80 --candidate <this file> --quiet`
   (still 2 edits after the prototypes were reconciled on 2026-09-26).
   Needs shopDrawLabel (static inline in y_fclShopDraw.c) moved above func_002cdf80.
   The only residual is the 0x43 loop test: this body tests `j < 6`, retail tests
   `i < 0x49` and keeps `j` as a dead counter. See ShopDraw_002cdf80_20260926.md. */
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    u8 pad6[0x1A];
} ShopBuySlide;
typedef struct {
    u8 state;
    u8 pad1;
    s16 cursor;
    s16 scroll;
    u8 pad6;
    s8 f7;
    u8 pad8[4];
    f32 step;
    u8 pad10;
    s8 sel;
    s16 qty;
    s8 busy;
    u8 pad15[0xC0B];
    u32 fC20;
    s8 fC24;
    u8 padC25[0x13];
    void *obj[0xB8];
    void *list[3];
    u8 padF24[4];
    void *font;
    u8 padF2C[0x10];
    s16 fF3C;
    u8 fF3E[3];
    u8 padF41;
    u8 fF42[3];
    u8 padF45[0x5B];
    ShopBuySlide slides[2][5];
    u8 pad10E0[0x88];
    s8 select[3];
    s8 scrollSave[3];
    u8 f116E;
    u8 pad116F;
    s16 f1170;
} ShopBuyWork;
#define O(off) obj[((off) - 0xC38) / 4]
#pragma push
#pragma opt_loop_invariants on
// FUN_002CDF80
void func_002cdf80(void *arg0, s8 arg1) {
    extern u8 D_0063FAA0[];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    s8 func_002e05a0(void *);
    s8 func_002e2a00(void *);
    void func_002e3560(void *, s32, s32, s8, s32);
    void func_002b3050(s32, s32, s32, s64, s32, s16 *, s16 *);
    s8 func_002d4760(void *, s8);
    void func_002d7c10(void *, s16);
    void func_002dd230(void *);
    ShopBuyWork *work;
    s32 item;
    s16 i;
    s32 textColor;
    s32 iconColor;
    s32 lineColor;
    u8 *t;
    Vec2f *b;
    s16 i3;
    s16 j;
    s8 n;
    u32 price;
    u32 digits;
    u32 flags;
    s16 start;
    s16 cur;
    s16 row;
    s32 rowY;
    u8 *e;
    FclDrawColor rowColor;
    FclDrawColor bar0;
    FclDrawColor bar1;
    FclDrawColor bar2;
    FclDrawColor white0;
    FclDrawColor white1;
    FclDrawColor c204;
    FclDrawColor c200;
    FclDrawColor c1FC;
    FclDrawColor c1F8;
    FclDrawColor c1F4;
    FclDrawColor c1F0;
    FclDrawColor c1EC;
    FclDrawColor c1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    void *r0;
    void *r1;
    void *r2;
    s16 top;

    work = *(ShopBuyWork **)((u8 *)arg0 + 0x38);
    top = func_002e2700(work->list[work->sel]);
    item = func_002e2830(work->list[work->sel], work->cursor);
    for (i = 0; i < 3; i++) {
        func_002e04f0(work->obj[i + 0x82], 0, 1);
    }
    if (func_002e2a00(work->list[work->sel]) != 0) {
        goto clear;
    }
    if (func_002e26f0(work->list[work->sel]) <= D_00748908[work->sel]) {
        func_002e09e0(work->O(0xE68), 0x57, 117.0f);
        bar0 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)func_002e04e0(work->O(0xE68));
        *(FclDrawColor *)(t + 0x79) = bar0;
        func_002e09e0(work->O(0xE6C), 0x56, 118.0f);
        bar1 = func_002b2a60(0x6B, 0x6B, 0x6B, 0xFF);
        t = (u8 *)func_002e04e0(work->O(0xE6C));
        *(FclDrawColor *)(t + 0x79) = bar1;
        func_002e09e0(work->O(0xE70), 0x56, 119.0f);
        bar2 = func_002b2a60(0x6B, 0x6B, 0x6B, 0xFF);
        t = (u8 *)func_002e04e0(work->O(0xE70));
        *(FclDrawColor *)(t + 0x79) = bar2;
        func_002e04f0(work->O(0xDCC), 0, 1);
        func_002e04f0(work->O(0xDD0), 0, 1);
        func_002e04f0(work->O(0xC8C), 0, 1);
        func_002e04f0(work->O(0xC90), 0, 1);
    } else {
        if (func_002e26f0(work->list[work->sel]) > 5) {
            if (func_002e26f0(work->list[work->sel]) > 5) {
                work->step = 104.0f / (f32)(func_002e26f0(work->list[work->sel]) - 5);
            }
            sp1C8 = func_002b2970((f32)0x221, 142.0f + work->step * (f32)(work->cursor - work->scroll));
            func_002e0b20(0x36, sp1C8, 138.0f, func_002b2a30(0xFF, 0xFE, 0xC6, 0x31), ((u8 *)func_002e04e0(work->O(0xC94)))[0x62], 0, D_00794EA0);
            func_002e04f0(work->O(0xC8C), 0, 0);
            func_002e04f0(work->O(0xC90), 0, 0);
        } else {
            func_002e04f0(work->O(0xC8C), 0, 1);
            func_002e04f0(work->O(0xC90), 0, 1);
        }
        if (work->sel == 0 && work->cursor == 0) {
            sp1C0 = func_002b2970((f32)0x24E, 61.0f);
            white0 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
            func_002cacd0(sp1C0, 1.0f, white0, 0x11, 5, work->fC20, 0x70, 0x7A,
                          (s32)func_0046a770(D_0063FAA0), (s32)func_0046a770(D_0063FAA0), 0xAA);
        } else {
            price = func_00106a90((s16)item) / 5;
            sp1B8 = func_002b2970((f32)0x24E, 61.0f);
            white1 = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
            func_002cacd0(sp1B8, 1.0f, white1, 0x11, 5, work->qty * price, 0x70, 0x7A,
                          (s32)func_0046a770(D_0063FAA0), (s32)func_0046a770(D_0063FAA0), 0xAA);
        }
        b = (Vec2f *)D_0063F888;
        if (func_002e0570(work->O(0xDCC), 1) == 0) {
            ((ShopWork *)func_002e04e0(work->O(0xDCC)))->field_30 = b->y + (f32)(work->scroll << 5);
        }
        if (func_002e0570(work->O(0xDD0), 1) == 0) {
            ((ShopWork *)func_002e04e0(work->O(0xDD0)))->field_30 = b->y + (f32)(work->scroll << 5);
        }
        func_002e04f0(work->O(0xE68), 0, 1);
        func_002e04f0(work->O(0xE6C), 0, 1);
        func_002e04f0(work->O(0xE70), 0, 1);
        n = (s8)func_002b2cb0(0, func_002e26f0(work->list[work->sel]), 5, 0, 1);
        start = work->cursor - work->scroll;
        for (cur = start, row = 0; cur < start + n; cur++, row++) {
            if (cur < func_002e26f0(work->list[work->sel])) {
                textColor = func_002b2a30(0xFF, 0xAE, 0, ((u8 *)func_002e04e0(work->O(0xC8C)))[0x62]);
                iconColor = func_002b2a30(0, 0xFF, 0xAE, 0);
                rowColor = func_002b2a60(0xFF, 0xAE, 0, ((u8 *)func_002e04e0(work->O(0xC8C)))[0x62]);
                lineColor = func_002b2a30(0, 0xFE, 0xC7, 0x31);
                if (cur == work->cursor) {
                    textColor = func_002b2a30(0x2D, 0x2D, 0x2D, ((u8 *)func_002e04e0(work->O(0xC8C)))[0x62]);
                    iconColor = func_002b2a30(0, 0x2D, 0x2D, 0x2D);
                    rowColor = func_002b2a60(0x2D, 0x2D, 0x2D, ((u8 *)func_002e04e0(work->O(0xC8C)))[0x62]);
                    lineColor = func_002b2a30(0, 0x2D, 0x2D, 0x2D);
                }
                if (work->sel == 0 && cur == 0) {
                    if (func_002e26f0(work->list[work->sel]) > 1) {
                        {
                            s16 i2;

                            for (i2 = 0; i2 < 3; i2++) {
                                func_002e0b20(0x3C, func_002b2970((f32)((i2 << 5) + 0x6F), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                                func_002e0b20(0x3C, func_002b2970((f32)((i2 << 5) + 0x1A1), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                            }
                        }
                        func_002e09e0(work->O(0xE44), 0x56, 121.0f);
                        c204 = func_002b2a60(0xFE, 0xC7, 0x31, 0xFF);
                        t = (u8 *)func_002e04e0(work->O(0xE44));
                        *(FclDrawColor *)(t + 0x79) = c204;
                        if (cur == work->cursor) {
                            c200 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            t = (u8 *)func_002e04e0(work->O(0xE44));
                            *(FclDrawColor *)(t + 0x79) = c200;
                        }
                        func_002e09e0(work->O(0xE48), 0x56, 122.0f);
                        c1FC = func_002b2a60(0xFE, 0xC7, 0x31, 0xFF);
                        t = (u8 *)func_002e04e0(work->O(0xE48));
                        *(FclDrawColor *)(t + 0x79) = c1FC;
                        if (cur == work->cursor) {
                            c1F8 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            t = (u8 *)func_002e04e0(work->O(0xE48));
                            *(FclDrawColor *)(t + 0x79) = c1F8;
                        }
                        func_002e09e0(work->O(0xE40), 0x57, 120.0f);
                        c1F4 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                        t = (u8 *)func_002e04e0(work->O(0xE40));
                        *(FclDrawColor *)(t + 0x79) = c1F4;
                        if (cur == work->cursor) {
                            c1F0 = func_002b2a60(0xFE, 0xC7, 0x31, 0xFF);
                            t = (u8 *)func_002e04e0(work->O(0xE40));
                            *(FclDrawColor *)(t + 0x79) = c1F0;
                        }
                    }
                } else {
                    b = (Vec2f *)D_0063F888;
                    rowY = row << 5;
                    sp1D8 = func_002b2970(b->x, b->y + (f32)rowY);
                    sp1E0 = func_002b2970(10.0f + sp1D8.x, 9.0f + sp1D8.y);
                    sp1D0 = func_002b2970(70.0f, 126.0f + (f32)rowY);
                    if (row == work->scroll) {
                        f32 mx = 10.0f + ((ShopWork *)func_002e04e0(work->O(0xDCC)))->field_2C;

                        sp1E0 = func_002b2970(mx, 9.0f + ((ShopWork *)func_002e04e0(work->O(0xDCC)))->field_30);
                        sp1D0 = *(Vec2f *)((u8 *)func_002e04e0(work->O(0xDCC)) + 0x2C);
                    }
                    flags = func_00106880((s16)func_002e2830(work->list[work->sel], cur));
                    if (flags & 0x81) {
                        func_002e0b20(0x14, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x102) {
                        func_002e0b20(0x15, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x204) {
                        func_002e0b20(0x16, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x408) {
                        func_002e0b20(0x17, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x810) {
                        func_002e0b20(0x18, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x1020) {
                        func_002e0b20(0x19, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x2040) {
                        func_002e0b20(0x1A, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x4000) {
                        func_002e0b20(0x1B, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x8000) {
                        func_002e0b20(0x1C, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x40000) {
                        func_002e0ca0(0x1A, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else {
                        func_002e0ca0(0x1B, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    }
                    shopDrawLabel(115.0f, func_001067f0((s16)func_002e2830(work->list[work->sel], cur)), func_002b2970(53.0f + sp1D0.x, 7.0f + sp1D0.y), textColor);
                    digits = func_00106a90((s16)func_002e2830(work->list[work->sel], cur)) / 5;
                    func_002cacd0(func_002b2970(372.0f + sp1D0.x, 16.0f + sp1D0.y), 115.0f, rowColor, 0x10, 5, digits, 9, 0x7B, (s32)func_0046a770(D_0063FB50), (s32)work->font, 0xA9);
                    func_002e0b20(0x47, func_002b2970(400.0f + sp1D0.x, 18.0f + sp1D0.y), 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    func_002cacd0(func_002b2970((f32)0x1AF + sp1D0.x, 16.0f + sp1D0.y), 115.0f, rowColor, 0x10, 5, func_00106600((s16)func_002e2830(work->list[work->sel], cur)) & 0xFF, 9, 0x7B,
                                  (s32)func_0046a770(D_0063FB50), (s32)work->font, 0xA9);
                }
            }
        }
    }
    if (arg1 != 2 && func_002e0570(work->O(0xDCC), 1) == 0 && func_002e0570(work->O(0xDD0), 1) == 0
        && func_002e05a0(work->O(0xD44)) == 0 && func_002e05a0(work->O(0xD48)) == 0
        && func_002e05a0(work->O(0xD4C)) == 0 && func_002e05a0(work->O(0xD50)) == 0
        && func_002e05a0(work->O(0xD54)) == 0 && func_002e05a0(work->O(0xD58)) == 0) {
        if ((D_008C0276[0] & 0x1000) && work->busy == 0) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel]) {
                if (arg1 == 1 && work->sel == 0 && work->cursor == 1) {
                    func_0045af60(0, 0, 0, 0);
                    work->cursor = func_002b2d00(work->cursor, 1, 0, (s16)func_002e26f0(work->list[work->sel]), 2);
                    work->scroll = func_002b2d50(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, -1);
                }
                if (work->cursor == 0) {
                    func_0045af60(0, 0, 0, 0);
                    work->cursor = top;
                    work->scroll = func_002b2cb0(0, top, 4, 0, 1);
                } else {
                    func_0045af60(0, 0, 0, 0);
                    work->cursor = func_002b2d00(work->cursor, 1, 0, (s16)func_002e26f0(work->list[work->sel]), 2);
                    work->scroll = func_002b2d50(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, -1);
                }
                work->busy = 1;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel] && (arg1 != 1 || work->sel != 0 || work->cursor != 1)) {
                if (func_002e26f0(work->list[work->sel]) > 0) {
                    if (work->cursor != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    work->cursor = func_002b2d00(work->cursor, 1, 0, 0, 1);
                    work->scroll = func_002b2d50(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, -1);
                }
                work->busy = 1;
            }
        } else if ((D_008C0276[0] & 0x4000) && work->busy == 0) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel]) {
                func_0045af60(0, 0, 0, 0);
                work->cursor = func_002b2cb0(work->cursor, 1, top, 0, 2);
                if (work->cursor == 0) {
                    work->scroll = 0;
                    if (work->sel == 0 && work->fC24 == 1) {
                        work->cursor = 1;
                        work->scroll = 1;
                    }
                } else if (top >= 5) {
                    work->scroll = func_002b2d50(work->cursor, work->scroll, top, 5, 1);
                } else {
                    work->scroll = func_002b2d50(work->cursor, work->scroll, top, func_002e26f0(work->list[work->sel]), 1);
                }
                work->busy = 1;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel]) {
                if (func_002e26f0(work->list[work->sel]) > 0) {
                    if (work->cursor != top) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    work->cursor = func_002b2cb0(work->cursor, 1, top, 0, 1);
                    if (top >= 5) {
                        work->scroll = func_002b2d50(work->cursor, work->scroll, top, 5, 1);
                    } else {
                        work->scroll = func_002b2d50(work->cursor, work->scroll, top, func_002e26f0(work->list[work->sel]), 1);
                    }
                    work->busy = 1;
                }
                return;
            }
        } else if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel]) {
                if (work->cursor != top) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                goto clear;
            }
        } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
            n = D_00748908[work->sel];
            if (n < func_002e26f0(work->list[work->sel])) {
                if (work->fC24 == 0) {
                    if (work->cursor != 0) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    func_002b2f90(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                } else {
                    if (work->cursor != n) {
                        func_0045af60(0, 0, 0, 0);
                    }
                    if (work->sel == 0) {
                        func_002b3050(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, 1, &work->cursor, &work->scroll);
                    } else {
                        func_002b2f90(work->cursor, work->scroll, func_002e26f0(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                    }
                }
                goto clear;
            }
        } else if (D_008C027A[0] & 8) {
            if (work->fC24 != 1) {
                {
                    s16 si;
                    s16 sj;

                    for (sj = 0; sj < 3; sj++) {
                        for (si = 0; si < 5; si++) {
                            work->slides[sj][si].f2 = 0;
                            work->slides[sj][si].f0 = 4;
                            work->slides[sj][si].f4 = si;
                        }
                    }
                }
                work->select[work->sel] = work->cursor;
                work->scrollSave[work->sel] = work->scroll;
                work->f116E = work->sel;
                if (func_002e26f0(work->list[work->sel]) >= 5) {
                    work->f1170 = work->slides[work->sel][4].f0 + 4;
                } else {
                    work->f1170 = work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]);
                }
                work->sel = func_002b2cb0(work->sel, 1, 2, 0, 2);
                func_002d4760(arg0, (s32)work->sel);
                func_002d7c10(arg0, work->sel);
                work->cursor = 0;
                work->scroll = 0;
                work->select[work->sel] = 0;
                work->scrollSave[work->sel] = 0;
                if (func_002e26f0(work->list[work->sel]) >= 5) {
                    work->f1170 = work->slides[work->sel][4].f0 + 4;
                } else {
                    if (work->f1170 < (s16)(work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]))) {
                        work->f1170 = work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]);
                    }
                }
                n = work->sel;
                switch (n) {
                case 0:
                    func_002e3560(work->list[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    func_002e3560(work->list[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    func_002e3560(work->list[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x33;
                func_0045af60(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C027A[0] & 4) {
            if (work->fC24 != 1) {
                {
                    s16 si;
                    s16 sj;

                    for (sj = 0; sj < 3; sj++) {
                        for (si = 0; si < 5; si++) {
                            work->slides[sj][si].f2 = 0;
                            work->slides[sj][si].f0 = 4;
                            work->slides[sj][si].f4 = si;
                        }
                    }
                }
                work->select[work->sel] = work->cursor;
                work->scrollSave[work->sel] = work->scroll;
                work->f116E = work->sel;
                if (func_002e26f0(work->list[work->sel]) >= 5) {
                    work->f1170 = work->slides[work->sel][4].f0 + 4;
                } else {
                    work->f1170 = work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]);
                }
                work->sel = func_002b2d00(work->sel, 1, 0, 2, 2);
                func_002d4760(arg0, (s32)work->sel);
                func_002d7c10(arg0, work->sel);
                work->cursor = 0;
                work->scroll = 0;
                work->select[work->sel] = 0;
                work->scrollSave[work->sel] = 0;
                if (func_002e26f0(work->list[work->sel]) >= 5) {
                    work->f1170 = work->slides[work->sel][4].f0 + 4;
                } else {
                    if (work->f1170 < (s16)(work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]))) {
                        work->f1170 = work->slides[work->sel][func_002e26f0(work->list[work->sel])].f0 + func_002e26f0(work->list[work->sel]);
                    }
                }
                n = work->sel;
                switch (n) {
                case 0:
                    func_002e3560(work->list[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    func_002e3560(work->list[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    func_002e3560(work->list[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x34;
                func_0045af60(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C024E[0] & 0x40) {
            if (func_002e26f0(work->list[work->sel]) <= D_00748908[work->sel]) {
                func_0045af60(0, 0, 0, 8);
                return;
            }
            work->qty = 1;
            if (work->sel == 0 && work->cursor - work->scroll == 0 && func_002e26f0(work->list[work->sel]) < 2) {
                func_0045af60(0, 0, 0, 8);
                return;
            }
            if (func_002e26f0(work->list[work->sel]) > 0) {
                work->fF3E[0] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x79];
                work->fF3E[1] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x7A];
                work->fF3E[2] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x7B];
                work->fF42[0] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x79];
                work->fF42[1] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x7A];
                work->fF42[2] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x7B];
                work->fF3C = 0;
                work->state = 0x25;
                func_0045af60(0, 0, 0, 1);
            }
            goto clear;
        } else if (D_008C024E[0] & 0x80) {
            if (func_002e26f0(work->list[work->sel]) > D_00748908[work->sel] && arg1 != 1) {
                if (func_002e0570(work->O(0xE38), 1) == 1 || func_002e0570(work->O(0xCC4), 1) == 1
                    || func_002e0570(work->O(0xCC0), 1) == 1) {
                    return;
                }
                if ((work->sel != 0 || work->cursor != 0) && func_002e26f0(work->list[work->sel]) > 0) {
                    work->fF3E[0] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x79];
                    work->fF3E[1] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x7A];
                    work->fF3E[2] = ((u8 *)func_002e04e0(work->O(0xDCC)))[0x7B];
                    work->fF42[0] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x79];
                    work->fF42[1] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x7A];
                    work->fF42[2] = ((u8 *)func_002e04e0(work->O(0xDD0)))[0x7B];
                    work->fF3C = 0;
                    func_002e0700(work->O(0xEC4), 3, 1.0f, fGpffff8504, 6, 0, 0);
                    func_002e0700(work->O(0xEC8), 4, 1.0f, fGpffff8504, 6, 0, 0);
                    func_002e0700(work->O(0xE38), 0x80, 1.0f, fGpffff8504, 6, 0, 0);
                    func_002e0700(work->O(0xEB4), 3, 1.0f, fGpffff8504, 6, 1, 0);
                    func_002e0700(work->O(0xEB8), 4, 1.0f, fGpffff8504, 6, 1, 0);
                    func_002e0700(work->O(0xCC4), 0x23, 1.0f, fGpffff8504, 6, 1, 0);
                    func_002e0700(work->O(0xEBC), 3, 1.0f, fGpffff8504, 6, 2, 0);
                    func_002e0700(work->O(0xEC0), 4, 1.0f, fGpffff8504, 6, 2, 0);
                    func_002e0700(work->O(0xCC0), 0x22, 1.0f, fGpffff8504, 6, 1, 0);
                    func_002e04f0(work->O(0xDDC), 0, 1);
                    func_002e04f0(work->O(0xDE4), 0, 1);
                    func_002e04f0(work->O(0xDE0), 0, 0);
                    work->state = 0x2F;
                    func_0045af60(0, 1, 0, 3);
                }
                goto clear;
            }
        } else if (D_008C024E[0] & 0x20) {
            if (arg1 != 1) {
                func_0045af60(0, 0, 0, 2);
                b = (Vec2f *)D_0063F5B8;
                func_002e0620(work->O(0xC64), func_002b2970(b->x, b->y), func_002b2970(b->x, 300.0f + b->y), 0, 0xA, 0);
                func_002e0660(work->O(0xC64), ((u8 *)func_002e04e0(work->O(0xC64)))[0x62], 0, 0, 0xA, 0);
                func_002e09e0(work->O(0xD74), 0x56, 11.0f);
                func_002e0660(work->O(0xD74), 0xFF, 0, 0, 0xA, 0);
                func_002e09e0(work->O(0xD80), 0x56, 9.0f);
                func_002e0660(work->O(0xD80), 0xFF, 0, 0, 0xA, 0);
                {
                    for (i3 = 0x43, j = 0; j < 6; i3++, j++) {
                        func_002e0620(work->obj[i3], func_002b2970(((ShopWork *)func_002e04e0(work->obj[i3]))->field_2C, ((ShopWork *)func_002e04e0(work->obj[i3]))->field_30), func_002b2970(((ShopWork *)func_002e04e0(work->obj[i3]))->field_2C, 170.0f + ((ShopWork *)func_002e04e0(work->obj[i3]))->field_30), 1, 5, 0);
                    }
                }
                func_002e0660(work->O(0xC8C), 0xFF, 0, 0, 6, 0);
                func_002e0660(work->O(0xC90), 0xFF, 0, 0, 6, 0);
                {
                    s16 k;

                    for (k = 0; k < 3; k++) {
                        func_002e04f0(work->obj[k + 0x82], 0, 1);
                    }
                }
                func_002e04f0(work->O(0xDCC), 0, 1);
                func_002e04f0(work->O(0xDD0), 0, 1);
                e = func_002e04e0(work->O(0xEC4));
                func_002e0620(work->O(0xEC4), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEC4)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEC4)))->field_30), 2, 0xF, 0);
                e = func_002e04e0(work->O(0xEC8));
                func_002e0620(work->O(0xEC8), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEC8)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEC8)))->field_30), 2, 0xF, 0);
                e = func_002e04e0(work->O(0xE38));
                func_002e0620(work->O(0xE38), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xE38)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xE38)))->field_30), 2, 0xF, 0);
                e = func_002e04e0(work->O(0xEB4));
                func_002e0620(work->O(0xEB4), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEB4)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEB4)))->field_30), 2, 0xF, 1);
                e = func_002e04e0(work->O(0xEB8));
                func_002e0620(work->O(0xEB8), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEB8)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEB8)))->field_30), 2, 0xF, 1);
                e = func_002e04e0(work->O(0xCC4));
                func_002e0620(work->O(0xCC4), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xCC4)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xCC4)))->field_30), 2, 0xF, 1);
                e = func_002e04e0(work->O(0xEBC));
                func_002e0620(work->O(0xEBC), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEBC)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEBC)))->field_30), 2, 0xF, 2);
                e = func_002e04e0(work->O(0xEC0));
                func_002e0620(work->O(0xEC0), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xEC0)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xEC0)))->field_30), 2, 0xF, 2);
                e = func_002e04e0(work->O(0xCC0));
                func_002e0620(work->O(0xCC0), *(Vec2f *)(e + 0x2C), func_002b2970(((ShopWork *)func_002e04e0(work->O(0xCC0)))->field_2C, 500.0f + ((ShopWork *)func_002e04e0(work->O(0xCC0)))->field_30), 2, 0xF, 2);
                {
                    s16 i5;

                    for (i5 = 0x8C; i5 < 0x8F; i5++) {
                        if (func_002e0570(work->obj[i5], 0) == 1) {
                            func_002e04f0(work->obj[i5], 0, 1);
                        }
                    }
                }
                {
                    s16 i6;

                    for (i6 = 0; i6 < 3; i6++) {
                        func_002e0660(work->obj[i6], 0, 0xFF, 0, 0xA, 0);
                    }
                }
                {
                    for (i3 = 0; i3 < 7; i3++) {
                        b = (Vec2f *)D_0063F560 + (i3 + 0x3A);
                        func_002e09e0(work->obj[i3 + 0x3A], 0x56, (f32)(i3 + 0x64));
                        if (i3 > 0) {
                            c1EC = func_002b2a60(0xED, 0x80, 0, 0xFF);
                            t = (u8 *)func_002e04e0(work->obj[i3 + 0x3A]);
                            *(FclDrawColor *)(t + 0x79) = c1EC;
                        }
                        func_002e0620(work->obj[i3 + 0x3A], func_002b2970(80.0f + b->x, b->y), func_002b2970(b->x, b->y), 0, 3, i3);
                        func_002e0660(work->obj[i3 + 0x3A], 0, 0xFF, 0, 3, i3);
                    }
                }
                c1E8 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                t = (u8 *)func_002e04e0(work->obj[work->f7 + 0x3B]);
                *(FclDrawColor *)(t + 0x79) = c1E8;
                func_002e0660(work->O(0xC44), 0, 0xFF, 0, 0, work->f7);
                func_002e0660(work->O(0xC48), 0, 0xFF, 0, 0, work->f7);
                {
                    s16 i8;

                    for (i8 = 0; i8 < 3; i8++) {
                        func_002e0660(work->obj[i8], 0, 0xFF, 0, 0xA, 0);
                    }
                }
                func_002e09e0(work->O(0xDE8), 0x41, 46.0f);
                func_002e0660(work->O(0xDE8), 0, 0xFF, 0, 6, 0);
                ((ShopWork *)func_002e04e0(work->O(0xDE8)))->field_2C = 198.0f;
                ((ShopWork *)func_002e04e0(work->O(0xDE8)))->field_30 = (f32)0x151;
                func_002e09e0(work->O(0xDEC), 0x41, 146.0f);
                func_002e0660(work->O(0xDEC), 0, 0xFF, 0, 6, 0);
                ((ShopWork *)func_002e04e0(work->O(0xDEC)))->field_2C = 216.0f;
                ((ShopWork *)func_002e04e0(work->O(0xDEC)))->field_30 = 368.0f;
                func_002e09e0(work->O(0xDDC), 0x41, 49.0f);
                func_002e0660(work->O(0xDDC), 0xFF, 0, 0, 0xA, 0);
                func_002e09e0(work->O(0xDF0), 0x41, 47.0f);
                func_002e0660(work->O(0xDF0), 0xFF, 0, 0, 0xA, 0);
                func_002e0620(work->O(0xDF0), func_002b2970((f32)0x103, 404.0f), func_002b2970((f32)0x103, 404.0f), 0, 0, 0);
                func_002e09e0(work->O(0xDE4), 0x41, 47.0f);
                func_002e0660(work->O(0xDE4), 0xFF, 0, 0, 0xA, 0);
                func_002e0620(work->O(0xDE4), func_002b2970(338.0f, 404.0f), func_002b2970(338.0f, 404.0f), 0, 0, 0);
                ((ShopWork *)func_002e04e0(work->O(0xDE8)))->field_2C = 198.0f;
                ((ShopWork *)func_002e04e0(work->O(0xDE8)))->field_30 = (f32)0x151;
                func_002e09e0(work->O(0xC4C), 0x40, 191.0f);
                {
                    r0 = func_0046d200(work->font, 5);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xC4C)) + 0x100) = func_0046b260(r0);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xC4C)) + 0x102) = func_0046b2f0(r0);
                    func_0046d280(r0);
                }
                func_002e0660(work->O(0xC4C), 0, 0xCC, 0, 4, 4);
                func_002e0940(work->O(0xC4C), 0.0f, fGpffff8520, 0, 4, 4);
                func_002e0620(work->O(0xC4C), func_002b2970(-240.0f, 400.0f), func_002b2970(-240.0f, 310.0f), 0, 4, 4);
                func_002e09e0(work->O(0xC50), 0x40, 192.0f);
                ((ShopWork *)func_002e04e0(work->O(0xC50)))->field_2C = 110.0f;
                ((ShopWork *)func_002e04e0(work->O(0xC50)))->field_30 = -50.0f;
                {
                    r1 = func_0046d200(work->font, 6);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xC50)) + 0x100) = func_0046b260(r1);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xC50)) + 0x102) = 0;
                    func_002e0940(work->O(0xC50), -90.0f, fGpffff8524, 0, 4, 4);
                    func_002e0660(work->O(0xC50), 0, 0xFF, 0, 4, 4);
                    func_0046d280(r1);
                }
                func_002e09e0(work->O(0xE7C), 0x40, 190.0f);
                ((ShopWork *)func_002e04e0(work->O(0xE7C)))->field_2C = 180.0f;
                ((ShopWork *)func_002e04e0(work->O(0xE7C)))->field_30 = 30.0f;
                {
                    r2 = func_0046d200(work->font, 6);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xE7C)) + 0x100) = func_0046b260(r2);
                    *(s16 *)((u8 *)func_002e04e0(work->O(0xE7C)) + 0x102) = 0;
                    func_0046d280(r2);
                }
                func_002e0940(work->O(0xE7C), -85.0f, fGpffff8528, 0, 4, 2);
                func_002e0660(work->O(0xE7C), 0, 0xFF, 0, 4, 2);
                func_002dd230(arg0);
                work->state = 0x11;
            clear:
                work->busy = 0;
            }
        } else {
            goto clear;
        }
    }
}
#pragma pop
#undef O

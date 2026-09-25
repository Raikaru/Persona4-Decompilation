/* func_0031e5b0 draft: 30 differing words reloc-masked, 1308/1308 instructions,
   frame 0x170 and every stack offset exact (fnalign: 30 edits, all register names).
   Old guarded body measured 1218 words.

   Prerequisites outside the body (all verified: the two matched callers stay MATCH):
     - file-scope prototype: extern void func_0031e5b0(u8 *, FclVec2, s32, s32, s32, s32, s32);
       retail homes arg1 at sp+0xA0 before the other parameter moves, which only
       an aggregate parameter reproduces.
     - func_0032b770 passes *(FclVec2 *)&spC8; func_0032fbc0 passes sp100.position.

   Levers that took it from 1218 to 30:
     - struct-return func_002b2970 nested in the consuming call; the moving point is
       one FclVec2 (pos) at 0x148 assigned from the constructor.
     - local s16 func_002b6c30 and s32-last-parameter func_002b69f0 externs, so the
       resource and arg2 pass raw.
     - a separate handle local per block (h0..h5, h5 shared by the last two blocks).
     - `f32 by` declared before `f32 y` (by = arg1.y in $f21, y in $f20).
     - `id = 0x193;` before `pos = arg1;` (prologue store order).

   Residual (30 words): after the switch retail puts t5 = (s8)arg5 in $s7 (h0's
   register) and h1..h5 in $s5 (arg5's register). b210 computes t5 in place in $s5
   and gives h1..h5 $s6. Measured without effect: 24 declaration permutations,
   register keyword, block scopes for h0/idB/t5, no t5 variable (CSE temp), t5 as
   s16/s32, arg5 as s8/u8/s16/s64 parameter, idB constant vs copy, default case,
   t5 placement before/after 7750/46d200, the permuter (1810 compiles) and
   pragma_sweep (all others worse). A diagnostic that keeps arg5 alive to the
   block-1 func_00331560 call gives 20 words, so retail's t5 is not coalesced with
   arg5. */
// FUN_0031E5B0
void func_0031e5b0(u8 *arg0, FclVec2 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    extern FclVec2 func_002b2970(f32, f32);
    extern void func_002b6c30(s16, FclVec2, f32, s32);
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s32);
    FclByte4 c16C;
    FclByte4 c168;
    FclByte4 c164;
    FclByte4 c160;
    FclByte4 c15C;
    FclByte4 c158;
    FclByte4 c154;
    FclVec2 pos;
    f32 by;
    f32 y;
    s16 id;
    s16 idB;
    s8 t4;
    s8 t5;
    s8 t6;
    u8 *h0;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    u8 *h5;
    u8 *p;

    (void)arg0;
    id = 0x193;
    pos = arg1;
    t4 = (s8)arg4;
    if (t4 == 1) {
        id = 0x2B4;
    }
    t6 = (s8)arg6;
    if (t6 == 3) {
        pos.x = pos.x + 1.0f;
    }
    h0 = func_0046d200(func_00331560(), 0x193);
    func_002b6c30(id, func_002b2970(pos.x, pos.y), 191.0f, 0x57);
    c16C = func_002b2a60(0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c16C;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h0) / 2.0f), func_002b2970(pos.x, pos.y), 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, func_002b2970(pos.x, pos.y), func_002b2970(pos.x, pos.y + func_0046b2f0(h0) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h0);
    switch (t6) {
    case 0:
        id = 0x19A;
        idB = id;
        pos = func_002b2970((f32)0x12D + arg1.x, arg1.y);
        if ((s8)arg5 == 1) {
            pos = func_002b2970((f32)0x11D + arg1.x, arg1.y);
        }
        break;
    case 1:
        id = 0x1A0;
        idB = id;
        pos = func_002b2970(36.0f + ((f32)0x12D + arg1.x), arg1.y);
        if ((s8)arg5 == 1) {
            pos = func_002b2970(36.0f + ((f32)0x11D + arg1.x), arg1.y);
        }
        break;
    case 2:
        id = 0x1A4;
        idB = id;
        pos = func_002b2970((f32)0x12D + arg1.x, arg1.y);
        if ((s8)arg5 == 1) {
            pos = func_002b2970((f32)0x11D + arg1.x, arg1.y);
        }
        break;
    case 3:
        id = 0x1A4;
        idB = id;
        pos = func_002b2970((f32)0x12D + arg1.x, arg1.y);
        if ((s8)arg5 == 1) {
            pos = func_002b2970((f32)0x11D + arg1.x, arg1.y);
        }
        pos.x = pos.x + 4.0f;
        break;
    }
    if (t4 == 1) {
        id = 0x2B5;
    }
    t5 = (s8)arg5;
    if (t5 == 1) {
        id = 0x28A;
    }
    func_002b7750(id, idB);
    h1 = func_0046d200(func_00331560(), idB);
    func_002b6c30(id, func_002b2970(pos.x, pos.y), 191.0f, 0x57);
    c168 = func_002b2a60(0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c168;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h1) / 2.0f), func_002b2970(pos.x, pos.y), 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, func_002b2970(pos.x, pos.y), func_002b2970(pos.x, pos.y + func_0046b2f0(h1) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h1);

    id = 0x51;
    by = arg1.y;
    y = 5.0f + by;
    pos = func_002b2970(29.0f + arg1.x, y);
    if (t4 == 1) {
        id = 0x2B6;
    }
    if (t5 == 1) {
        pos = func_002b2970(13.0f + arg1.x, y);
    }
    if (t6 == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (t6 == 1) {
        pos.x = pos.x + 3.0f;
    }
    h2 = func_0046d200(func_00331560(), 0x51);
    func_002b6c30(id, pos, 176.0f, 0x59);
    c164 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c164;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h2) / 2.0f), pos, 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, pos, func_002b2970(pos.x, pos.y + func_0046b2f0(h2) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h2);

    id = 0x52;
    pos = func_002b2970(151.0f + arg1.x, y);
    if (t4 == 1) {
        id = 0x2B7;
    }
    if (t5 == 1) {
        pos = func_002b2970(135.0f + arg1.x, y);
    }
    if (t6 == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (t6 == 1) {
        pos.x = pos.x + 3.0f;
    }
    h3 = func_0046d200(func_00331560(), 0x52);
    func_002b6c30(id, pos, 176.0f, 0x59);
    c160 = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c160;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h3) / 2.0f), pos, 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, pos, func_002b2970(pos.x, pos.y + func_0046b2f0(h3) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h3);

    id = 0x53;
    y = 6.0f + by;
    pos = func_002b2970(274.0f + arg1.x, y);
    if (t4 == 1) {
        id = 0x2B8;
    }
    if (t5 == 1) {
        pos = func_002b2970(258.0f + arg1.x, y);
    }
    if (t6 == 3) {
        pos.x = pos.x + 6.0f;
    }
    if (t6 == 1) {
        pos.x = pos.x + 3.0f;
    }
    h4 = func_0046d200(func_00331560(), 0x53);
    func_002b6c30(id, pos, 176.0f, 0x59);
    c15C = func_002b2a60(0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c15C;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h4) / 2.0f), pos, 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, pos, func_002b2970(pos.x, pos.y + func_0046b2f0(h4) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h4);

    id = 0x73;
    y = 9.0f + by;
    pos = func_002b2970(100.0f + arg1.x, y);
    if (t4 == 1) {
        id = 0x2B9;
    }
    if (t5 == 1) {
        pos = func_002b2970(84.0f + arg1.x, y);
    }
    if (t6 == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (t6 == 1) {
        pos.x = pos.x + 3.0f;
    }
    h5 = func_0046d200(func_00331560(), 0x73);
    func_002b6c30(id, pos, 175.0f, 0x59);
    c158 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c158;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h5) / 2.0f), pos, 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, pos, func_002b2970(pos.x, pos.y + func_0046b2f0(h5) / 2.0f), 0, 3, arg2);
    }

    id = 0x237;
    pos = func_002b2970(225.0f + arg1.x, y);
    if (t4 == 1) {
        id = 0x2BA;
    }
    if (t5 == 1) {
        pos = func_002b2970(209.0f + arg1.x, y);
    }
    if (t6 == 3) {
        pos.x = pos.x + 4.0f;
    }
    if (t6 == 1) {
        pos.x = pos.x + 3.0f;
    }
    func_002b6c30(id, pos, 175.0f, 0x59);
    c154 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id);
    *(FclByte4 *)(p + 0x85) = c154;
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg2);
    func_002b69f0(id, func_002b2970(pos.x, pos.y + func_0046b2f0(h5) / 2.0f), pos, 0, 3, arg2);
    if ((s8)arg3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, (s16)((s16)arg2 + 3));
        func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg2);
        func_002b69f0(id, pos, func_002b2970(pos.x, pos.y + func_0046b2f0(h5) / 2.0f), 0, 3, arg2);
    }
    func_0046d280(h5);
}

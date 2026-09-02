/* object 1188B / window 1184B / normalized_diff 200; classification: saved-register rotation + ldr/ldl-vs-ld floor.
   Differing offsets: whole function, mainly:
   - frame 0x120 vs retail 0x110 (mwcc spills e0/e1 while retail keeps them in $fp/$s0)
   - $t (obj+0x38) lands in $s5/$fp instead of retail $s7
   - inner func_002b83e0 arg1 uses `ld` at 0x28 instead of retail `ldr/ldl` pair
   - inner 0x75 reads use `lwu` instead of retail `lwr/lwl` sequence
   - u_long128 spD0/spC0 emit the correct sq/lq and dsll32/dsrl32 widening
   Levers tried:
   - s16 loops, named s16 locals, s64 source for the unaligned 83e0 arg1
   - f2 block-scope prototype for 83e0 (made object larger; ld still used)
   - *(s64 *)((u8 *)e1 + 0x28) and *(u32 *)((u8 *)e2 + 0x75) loads
   - FMA pattern fbase + fratio * fdiff emits adda.s/madd.s (matches)
   - u_long128 spills with (u_long128)(u32)ptr cast
   Ruled out: ldr/ldl for arg1 via plain s64/u64/f2 loads; schedule/order tweaks not attempted due to time.
   Note: file-scope func_0046d280 was changed to (u8 *) in the workspace to compile this body.
*/
void func_0032fbc0(u8 *arg0)
{
    extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
    extern u8 *func_0034ae50(u8 *, s8);
    extern u8 *func_002e48a0(s8, s16);
    extern u8 *func_002e4870(s8);

    u8 *t;
    f2 sp100;
    f2 spF8;
    f2 spF0;
    f2 spE8;
    f2 spE0;
    u4 sp10C;
    u4 sp108;
    u_long128 spD0;
    u_long128 spC0;
    s16 i;
    s16 j;
    u8 *p;
    u16 w;
    u8 b;
    s8 v;
    u8 *e0;
    u8 *e1;
    u8 *e2;
    u8 *e3;
    s16 n;
    u8 *s1;
    s16 m;
    f32 f20;
    f32 fbase;
    f32 fratio;
    f32 fdiff;
    f32 ffma;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&sp100, 16.0f, 104.0f);
    func_0031e5b0(arg0, *(s64 *)&sp100, 0, 1, 0, 0, 0);

    i = 0;
    while ((s32)i < (s32)(u16)func_0010b5b0()) {
        func_002b2970(&spF8, 16.0f, 128.0f);
        p = func_002e48a0(0, i);
        w = *(u16 *)(p + 2);
        p = func_002e48a0(0, i);
        b = *(u8 *)(p + 4);
        v = *(s8 *)(func_002e4870(0) + 8);
        func_003191c0(arg0, *(s64 *)&spF8, (s8)i, w, b, 0, 1, v);

        p = t + (s16)i * 4;
        j = 0;
        while ((s32)j < (s32)(u16)func_0010b5b0()) {
            e0 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e1 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e2 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e3 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spD0 = (u_long128)(u32)func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spC0 = (u_long128)(u32)func_0034ae50(*(u8 **)(p + 0x154), (s8)j);

            func_002b83e0(e0, *(s64 *)((u8 *)e1 + 0x28),
                          *(u32 *)((u8 *)e2 + 0x75), *(u32 *)((u8 *)e3 + 0x75),
                          *(u8 *)(*(u32 *)&spD0 + 0x5E), *(u8 *)(*(u32 *)&spC0 + 0x5E),
                          3, 0, 32.0f,
                          *(f32 *)(func_0034ae50(*(u8 **)(p + 0x154), (s8)j) + 4),
                          1, 0);

            j = (s16)(j + 1);
        }

        e0 = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);

        fbase = (f32)329;
        fratio = 23.0f;
        fdiff = (f32)i;
        ffma = fbase + fratio * fdiff;
        func_002b2970(&spF0, ffma, 104.0f);

        func_002b2a60(&sp10C, 0, 0, 0x99, 0xFF);
        func_002b2a60(&sp108, 0, 0, 0x99, 0xFF);

        func_002b83e0(e0, *(s64 *)&spF0, *(s32 *)&sp10C, *(s32 *)&sp108,
                      0xFF, 0xFF, 2, 0, 32.0f, 159.0f, 1, 0);

        n = (s16)((s16)i + 0x25E);
        s1 = func_0046d200(func_00331560(), 0x39);
        func_002b6a70(n, 0xFF, 0, 0, 3, 0);
        func_002b6af0(n, 0, 3, 0, 1.0f, 1.0f, 1.0f, iGpffff8504);

        m = (s16)((s16)i * 23 + 0x14E);
        f20 = (f32)m;
        func_002b2970(&spE8, f20, 110.0f);
        func_002b2970(&spE0, f20, 110.0f + func_0046b2f0(s1) / 2.0f);
        func_002b69f0(n, spE8, spE0, 0, 3, 0);
        func_0046d280(s1);

        i = (s16)(i + 1);
    }
}

/* measured: nd 126 — three interlocked register/scheduling rotations; all
   logic (jtbl switch cases, both loops, the FclByte4 chains, the tail
   adda.s/madd.s FPU-fusion store) matches. (1) p (the *(u8**)(arg0+0x38) load)
   lands in $s4 in mwcc b210 vs $s3 in retail: mwcc gives the loop's (s16)j
   normalized copy a fresh saved register ($s2) where retail reuses arg1's dead
   $s1, shifting t18->$s3/p->$s4. (2) loop 22's counter: retail keeps the raw
   counter in $s0 and normalizes into a temp per use; mwcc keeps the raw in a
   temp and the normalized copy in $s0. (3) case stores: retail stores the raw
   2cb0/2d00 result (sh $v0) BEFORE the (s16) normalize for the 2d50 arg; mwcc
   always normalizes first. Tried: declaration orders, s16/s32 r and lim (lim
   MUST be s32 — s16 adds a spurious normalize and grew nd to 243->126 cascade;
   r s32/s16 no effect), named lim local (kills the per-iteration t18+6
   recompute — big win, 414->243). Saved-register rotation + scheduling floor. */

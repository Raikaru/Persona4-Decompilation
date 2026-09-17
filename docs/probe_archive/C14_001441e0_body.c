// func_001441e0 (0x001441E0-0x00144AC0, 2272B) — guarded floor.
// Measured: object 2068B/window 2272B (204B under; 517 vs 566 instrs);
// reloc-masked nd 425 via probe_variants on actual-current owner with
// truthful s32 return (extern fixed in scratch copy).
// Retail relocs 59 (7 provider + 2 D_008C024E hi/lo + 50 func_00450050 calls);
// candidate adds 50 provisional GPREL string relocs (iGpffff9ce4..iGpffff9da0,
// 25 distinct, 17 distinct in second loop due to retail aliasing).
// Wins: truthful s32 return (retail returns 0/-1 via $v0; void prototype was
// wrong); outer kind==1/==0 dispatch with -1 early-out on D_008C024E[0]&0x800;
// init loop with four func_001060b0 calls feeding two (s8)func_00110850 and
// one func_00110c50 per iteration (state at arg0+0x38 as {s32 kind; u16 a[7];
// u16 b[7];}); two display loops with per-iteration s32/f32 pair passed as
// s64 (proven Work-pair shape from func_00467880) and descending beq-chain
// order matching retail compare order; second-loop aliasing preserved
// (0/4/0x40 share 9ce4; 0x11/0x14/0x41 share 9d10; 0x22/0x24/0x42 share 9d40;
// 0x33/0x34/0x43 share 9d70).
// Walls: s1/s2 register-color swap (state in $s1 vs retail $s2, loop counter
// in $s2 vs $s3); outer branch polarity (bne vs retail beq); ~49-instr deficit
// from scheduler/allocation cascade; provisional string symbols need small-data
// recovery (retail uses raw gp immediates 0x762DD4..0x762E90; _gp=0x7690F0).
// Levers tried: display-first (nd 425) vs init-first (nd 447, worse); switch
// rejected by inspection (retail is beq chain, not sltiu/lw/jr table).
// Production stays ASM.
s32 func_001441e0(u8 *arg0) {
    extern s16 func_001060b0(void);
    extern s64 func_00110850(s32 arg0, u32 arg1);
    extern s32 func_00110c50(s32 arg0, s32 arg1);
    extern void func_00450050(s64 arg0, const char *arg1);
    extern u16 D_008C024E[];
    extern char iGpffff9ce4;
    extern char iGpffff9ce8;
    extern char iGpffff9cf0;
    extern char iGpffff9cf8;
    extern char iGpffff9d00;
    extern char iGpffff9d08;
    extern char iGpffff9d10;
    extern char iGpffff9d18;
    extern char iGpffff9d20;
    extern char iGpffff9d28;
    extern char iGpffff9d30;
    extern char iGpffff9d38;
    extern char iGpffff9d40;
    extern char iGpffff9d48;
    extern char iGpffff9d50;
    extern char iGpffff9d58;
    extern char iGpffff9d60;
    extern char iGpffff9d68;
    extern char iGpffff9d70;
    extern char iGpffff9d78;
    extern char iGpffff9d80;
    extern char iGpffff9d88;
    extern char iGpffff9d90;
    extern char iGpffff9d98;
    extern char iGpffff9da0;
    typedef struct { s32 kind; u16 a[7]; u16 b[7]; } State441e0;
    typedef struct { s32 x; f32 y; } Pos441e0;
    State441e0 *st;
    s32 kind;
    s32 i;
    Pos441e0 pos;
    s64 pair;
    u16 v;
    s16 t0;
    s16 t1;
    s16 t2;
    s16 t3;
    s8 v0;
    s8 v1;
    st = *(State441e0 **)(arg0 + 0x38);
    kind = st->kind;
    if (kind == 1) {
        if ((D_008C024E[0] & 0x800) != 0) {
            return -1;
        }
        for (i = 0; i < 7; i++) {
            pos.x = 0x40A00000;
            pos.y = 20.0f + (f32)i;
            pair = *(s64 *)&pos.x;
            v = st->a[i];
            if (v == 0x44) { func_00450050(pair, &iGpffff9da0); }
            else if (v == 0x43) { func_00450050(pair, &iGpffff9d98); }
            else if (v == 0x42) { func_00450050(pair, &iGpffff9d90); }
            else if (v == 0x41) { func_00450050(pair, &iGpffff9d88); }
            else if (v == 0x40) { func_00450050(pair, &iGpffff9d80); }
            else if (v == 0x34) { func_00450050(pair, &iGpffff9d78); }
            else if (v == 0x33) { func_00450050(pair, &iGpffff9d70); }
            else if (v == 0x32) { func_00450050(pair, &iGpffff9d68); }
            else if (v == 0x31) { func_00450050(pair, &iGpffff9d60); }
            else if (v == 0x30) { func_00450050(pair, &iGpffff9d58); }
            else if (v == 0x24) { func_00450050(pair, &iGpffff9d50); }
            else if (v == 0x23) { func_00450050(pair, &iGpffff9d48); }
            else if (v == 0x22) { func_00450050(pair, &iGpffff9d40); }
            else if (v == 0x21) { func_00450050(pair, &iGpffff9d38); }
            else if (v == 0x20) { func_00450050(pair, &iGpffff9d30); }
            else if (v == 0x14) { func_00450050(pair, &iGpffff9d28); }
            else if (v == 0x13) { func_00450050(pair, &iGpffff9d20); }
            else if (v == 0x12) { func_00450050(pair, &iGpffff9d18); }
            else if (v == 0x11) { func_00450050(pair, &iGpffff9d10); }
            else if (v == 0x10) { func_00450050(pair, &iGpffff9d08); }
            else if (v == 4) { func_00450050(pair, &iGpffff9d00); }
            else if (v == 3) { func_00450050(pair, &iGpffff9cf8); }
            else if (v == 2) { func_00450050(pair, &iGpffff9cf0); }
            else if (v == 1) { func_00450050(pair, &iGpffff9ce8); }
            else if (v == 0) { func_00450050(pair, &iGpffff9ce4); }
        }
        for (i = 0; i < 7; i++) {
            pos.x = 0x41700000;
            pos.y = 20.0f + (f32)i;
            pair = *(s64 *)&pos.x;
            v = st->b[i];
            if (v == 0x44) { func_00450050(pair, &iGpffff9da0); }
            else if (v == 0x43) { func_00450050(pair, &iGpffff9d70); }
            else if (v == 0x42) { func_00450050(pair, &iGpffff9d40); }
            else if (v == 0x41) { func_00450050(pair, &iGpffff9d10); }
            else if (v == 0x40) { func_00450050(pair, &iGpffff9ce4); }
            else if (v == 0x34) { func_00450050(pair, &iGpffff9d70); }
            else if (v == 0x33) { func_00450050(pair, &iGpffff9d70); }
            else if (v == 0x32) { func_00450050(pair, &iGpffff9d68); }
            else if (v == 0x31) { func_00450050(pair, &iGpffff9d60); }
            else if (v == 0x30) { func_00450050(pair, &iGpffff9d58); }
            else if (v == 0x24) { func_00450050(pair, &iGpffff9d40); }
            else if (v == 0x23) { func_00450050(pair, &iGpffff9d48); }
            else if (v == 0x22) { func_00450050(pair, &iGpffff9d40); }
            else if (v == 0x21) { func_00450050(pair, &iGpffff9d38); }
            else if (v == 0x20) { func_00450050(pair, &iGpffff9d30); }
            else if (v == 0x14) { func_00450050(pair, &iGpffff9d10); }
            else if (v == 0x13) { func_00450050(pair, &iGpffff9d20); }
            else if (v == 0x12) { func_00450050(pair, &iGpffff9d18); }
            else if (v == 0x11) { func_00450050(pair, &iGpffff9d10); }
            else if (v == 0x10) { func_00450050(pair, &iGpffff9d08); }
            else if (v == 4) { func_00450050(pair, &iGpffff9ce4); }
            else if (v == 3) { func_00450050(pair, &iGpffff9cf8); }
            else if (v == 2) { func_00450050(pair, &iGpffff9cf0); }
            else if (v == 1) { func_00450050(pair, &iGpffff9ce8); }
            else if (v == 0) { func_00450050(pair, &iGpffff9ce4); }
        }
    } else if (kind == 0) {
        for (i = 0; i < 7; i++) {
            t0 = func_001060b0();
            v0 = (s8)func_00110850(i + t0, 3);
            t1 = func_001060b0();
            v1 = (s8)func_00110850(i + t1, 0);
            st->a[i] = (u16)(v0 + v1 * 0x10);
            t2 = func_001060b0();
            t3 = func_001060b0();
            st->b[i] = (u16)func_00110c50(i + t2, t3);
        }
        st->kind = 1;
    }
    return 0;
}

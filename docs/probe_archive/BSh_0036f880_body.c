// func_0036f880 (0x0036f880-0x0036fbe0, 864B) — guarded floor @139fndiff/852B (12B under).
// Wins: iGpffffb3ec direct symbol (registered, -20); u32 w1/h2 arrays; s5v-named; s32 args;
// (s16)i extend; u16 counters; switch/if-else beq-chains; all calls incl K&R-free protos; GPREL relocs.
// Walls: s-rotation (mine s5/s4/s3/s2 vs retail s4/s5/s2 + i/v s2 vs s0; decl/type/operand/counter/top-init
//   all neutral; prior s-count floor); frame -0xB0 vs -0xC0 (16B tighter: fewer stack temps; no padding per
//   Rule 7, arrays shift); inner-scan while-1-break vs beq+bnez (while-cond rewrite +38 worse); slti-at (1 row).
// Prior attempt (guard note: frame 0xD0 vs 0xC0, extra live value) hit related s-count wall. Production stays ASM.
s32 func_0036f880(s32 arg0, u8 *arg1)
{
    u32 w1[8];
    u32 h2[8];
    u16 lim;
    u16 cnt;
    u16 i;
    s16 v;
    u8 *pick;
    u32 t2;
    u8 *tbl;
    u16 s5v;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    u16 sA;
    u16 sB;

    lim = func_0010b5b0() & 0xFFFF;
    cnt = 0;
    if (lim >= 13) {
        func_0046d730(D_0064E790, 1207);
    }
    i = 0;
    while (((i & 0xFFFF)) < lim) {
        v = (s16)i;
        if (func_0010abd0(v) != 0) {
            w1[cnt] = (u32)func_0010ace0(v);
            cnt = (cnt + 1) & 0xFFFF;
        }
        i = (i + 1) & 0xFFFF;
    }
    if ((cnt & 0xFFFF) == 0) {
        return 0;
    }
    pick = (u8 *)w1[func_00231d70(cnt)];
    t2 = func_001094d0((u32)pick);
    a = 0;
    b = 0;
    tbl = iGpffffb3ec;
    s5v = arg0 & 0xFFFF;
    while (((a & 0xFFFF)) < 8) {
        {
            u16 cv = *(u16 *)(t2 + (a & 0xFFFF) * 2);
            if (cv != 0) {
                c = 0;
                if (s5v != 0) {
                    while (1) {
                        d = *(u16 *)(tbl + (c & 0xFFFF) * 4);
                        if (d == cv) {
                            break;
                        }
                        if (d == 0) {
                            break;
                        }
                        c = (c + 1) & 0xFFFF;
                    }
                    if (d != 0) {
                        e = 0;
                        while (((e & 0xFFFF)) < 8) {
                            f = *(u16 *)(t2 + (e & 0xFFFF) * 2);
                            if (f == 0 || f == *(u16 *)(tbl + (c & 0xFFFF) * 4 + 2)) {
                                break;
                            }
                            e = (e + 1) & 0xFFFF;
                        }
                        if (((e & 0xFFFF)) >= 8) {
                            h2[b] = d;
                            h2[b] = (h2[b] & 0xFFFF) | ((u32)*(u16 *)(tbl + (c & 0xFFFF) * 4 + 2) << 16);
                            b = (b + 1) & 0xFFFF;
                        }
                    }
                } else {
                    while (1) {
                        d = *(u16 *)(tbl + (c & 0xFFFF) * 4 + 2);
                        if (d == cv) {
                            break;
                        }
                        if (d == 0) {
                            break;
                        }
                        c = (c + 1) & 0xFFFF;
                    }
                    if (d != 0) {
                        e = 0;
                        while (((e & 0xFFFF)) < 8) {
                            f = *(u16 *)(t2 + (e & 0xFFFF) * 2);
                            if (f == 0 || f == *(u16 *)(tbl + (c & 0xFFFF) * 4)) {
                                break;
                            }
                            e = (e + 1) & 0xFFFF;
                        }
                        if (((e & 0xFFFF)) >= 8) {
                            h2[b] = d;
                            h2[b] = (h2[b] & 0xFFFF) | ((u32)*(u16 *)(tbl + (c & 0xFFFF) * 4) << 16);
                            b = (b + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        a = (a + 1) & 0xFFFF;
    }
    if ((b & 0xFFFF) == 0) {
        return 0;
    }
    {
        u8 *sp = (u8 *)h2 + (func_00231d70(b) & 0xFFFF) * 4;
        sA = *(u16 *)(sp + 114);
        sB = *(u16 *)(sp + 112);
        func_0010cd70(pick, (s16)sB, sA);
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(pick + 2);
    *(u16 *)(arg1 + 8) = sB;
    *(u16 *)(arg1 + 6) = sA;
    return 1;
}

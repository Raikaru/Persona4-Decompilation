// func_0047e0f0 (0x0047e0f0-0x0047e440, 848B) — measured wall @166fndiff/852B (+4B overrun: REVERTED per gate).
// Wins: (s16)t3/t21/val extends; (t3*3)*32+(t21*3)*4 via ordered o1/o2 temps; sb[c1] (write-index, not c2);
// s8 cv (lb) + neg1-holder (a1); sb[4]-last (sp+124); u16 w; e2=b+12 shape; switch beq-chain; all calls/relocs.
// Walls: full s-rotation cycle (mine s2/s1/s0/s5/s4/s3 vs retail s1/s0/s5/s4/s3/s2 — every var shifted one;
//   decl-order/type/operand-order/counter-split/reinit-split/top-init-reserve all neutral; prior nd~128 same floor);
//   n-temp (t0 vs s2); bool ==0 shape (and/move/sltiu vs and/sltu/xori); GPREL-vs-ABSOLUTE phantoms.
// Prior attempt (guard note, nd~128, no archive) hit the same rotation floor. Production stays ASM.
s32 func_0047e0f0(u8 *arg0, s32 arg1, s32 arg2, u16 arg3)
{
    s16 t3;
    s16 t21;
    u8 *entry;
    s16 h8;
    s16 val;
    u16 c1;
    u16 c2;
    s8 last;
    s8 first;
    s8 neg1;
    s32 n;
    u16 d16;
    s16 v3;
    u8 *base;
    u8 sb[4];

    t3 = (s16)arg2;
    if (t3 >= 0x1B) {
        return 0;
    }
    t21 = (s16)arg1;
    if (t21 >= 8) {
        return 0;
    }
    {
        u32 o1 = (t3 * 3) * 32;
        u32 o2 = (t21 * 3) * 4;
        entry = *(u8 **)(arg0 + 12) + o1 + o2;
    }
    h8 = *(s16 *)(entry + 8);
    if (h8 == -1) {
        return 0;
    }
    if (t21 == 0) {
        val = h8 + (arg3 & 0xFFFF);
    } else {
        val = h8 - *(s16 *)(entry - 4);
    }
    last = -1;
    first = -1;
    neg1 = -1;
    c1 = 0;
    c2 = 0;
    while (((c2 & 0xFFFF)) < 3) {
        {
            s8 cv = *(s8 *)(entry + c1);
            if (cv != neg1) {
                sb[c1] = cv;
                if (first == -1) {
                    first = sb[c1];
                }
                c1 = (c1 + 1) & 0xFFFF;
            }
        }
        c2 = (c2 + 1) & 0xFFFF;
    }
    n = c1 & 0xFFFF;
    if (n > 0) {
        d16 = *(u16 *)(*(u8 **)arg0 + 12);
        if (d16 == 1) {
            v3 = 2;
        } else {
            v3 = 3;
        }
        *(s16 *)(arg0 + 18) = v3;
        *(s16 *)(arg0 + 22) = val;
        if ((*(u16 *)(arg0 + 16) & 0x40) == 0 || first == -1) {
            *(s16 *)(arg0 + 20) = sb[func_003b7060(d16, -1, last, c2, c1) % n];
        } else {
            *(s16 *)(arg0 + 20) = first;
        }
        *(s32 *)(arg0 + 24) = **(s32 **)arg0;
    }
    {
        s32 f4 = *(s32 *)(entry + 4);
        if (f4 != -1) {
            base = *(u8 **)arg0;
            if (*(u16 *)(base + 12) == 1) {
                *(s16 *)(arg0 + 28) = (f4 & 0x20000000) == 0;
                *(s16 *)(arg0 + 30) = 11;
                *(s16 *)(arg0 + 36) = val;
                *(s16 *)(arg0 + 32) = (f4 >> 16) & 0xFFF;
                *(s16 *)(arg0 + 34) = f4;
            } else {
                if ((f4 & 0x20000000) != 0) {
                    *(s16 *)(arg0 + 28) = 0;
                } else if ((f4 & 0x40000000) != 0) {
                    *(s16 *)(arg0 + 28) = 1;
                } else if ((f4 & 0x10000000) != 0) {
                    *(s16 *)(arg0 + 28) = *(s32 *)(base + 4);
                }
                {
                    s32 sw = *(s32 *)(*(u8 **)arg0 + 4);
                    if (sw == 5) {
                        *(s16 *)(arg0 + 30) = 3;
                    } else if (sw == 4) {
                        *(s16 *)(arg0 + 30) = 2;
                    } else if (sw == 3) {
                        *(s16 *)(arg0 + 30) = 1;
                    } else {
                        *(s16 *)(arg0 + 30) = 3;
                    }
                }
                *(s16 *)(arg0 + 36) = val;
                *(s16 *)(arg0 + 32) = (f4 >> 16) & 0xFFF;
                *(s16 *)(arg0 + 34) = f4;
            }
        } else if (t21 == 0) {
            *(s16 *)(arg0 + 36) = -2;
        }
    }
    *(s16 *)(arg0 + 4) = arg2;
    return 1;
}
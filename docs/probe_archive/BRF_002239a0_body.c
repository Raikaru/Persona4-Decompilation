// func_002239a0 (0x002239a0-0x00223ed0, 1328B) — measured wall @277fndiff/1388B (+60B overrun: REVERTED per gate).
// Wins: full switch-8 coverage; sp-arg array; all calls + 25 decls (kept in TU); GPREL relocs.
// Walls: if/else dispatch vs retail jump-table (hand switch-port +2 worse: beq-chain smaller here;
//   goto-switch abandoned); sp-order neutral; frame/under context.
// Unattempted before (no prior note). Production stays ASM; decl groundwork kept.
s32 func_002239a0(s32 arg0)
{
    u8 *r;
    u8 *e;
    u32 st;
    u16 id;
    u8 *q;
    s32 v;
    u16 k;
    s32 sp[10];

    r = func_00452560();
    e = *(u8 **)(r + 60);
    *(s32 *)(r + 8) = 0;
    *(s32 *)(r + 12) = 0;
    func_00460ac0(D_00795F20, r + 8);
    st = *(u32 *)(r + 4);
    if (st > 7) {
        return 0;
    }
    if (st == 0) {
        *(s32 *)(r + 56) = 0;
        v = func_00452380(D_005E4810);
        *(s32 *)(r + 68) = v;
        if (v == 0) {
            v = func_00117780(0, 15, 4, 5, 0);
            *(s32 *)(r + 68) = v;
            if (v == 0) {
                func_0046d730(D_00629720, 116);
            }
            {
                s32 z = 0;
                f32 o = 50.0f;
                func_0011d100(*(s32 *)(r + 68), &z);
            }
            func_0011bb90(*(s32 *)(r + 68));
        }
        func_00117580(*(s32 *)(r + 68), 174);
        *(u32 *)(r + 4) = 2;
    }
    if (st == 0 || st == 1) {
        {
            u8 *base = e + 96;
            s32 i = *(s32 *)(r + 56);
            while (i < 4) {
                id = *(u16 *)(base + i * 2 + 1690);
                if (id == 0) {
                    break;
                }
                q = func_0010a900(id);
                *(s32 *)(q + 8) = *(s32 *)(q + 8) + *(s32 *)(base + *(s32 *)(r + 56) * 4 + 1700);
                if ((s32)*(u8 *)(base + *(s32 *)(r + 56) * 136 + 1716) <= 0) {
                    break;
                }
                *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
                i = *(s32 *)(r + 56);
            }
        }
        if (*(s32 *)(r + 56) != 4) {
            k = 0;
            while (((k & 0xFFFF)) < 32) {
                id = *(u16 *)(e + 96 + *(s32 *)(r + 56) * 136 + (k & 0xFFFF) * 2 + 1718);
                if (id == 0) {
                    break;
                }
                if (id == 0x112) {
                    if (func_00106330(0x1012) != 0) {
                        func_0046d730(D_00629720, 158);
                    }
                    func_00106390(0x1012, 1);
                } else if (id == 0x113) {
                    if (func_00106330(0x1013) != 0) {
                        func_0046d730(D_00629720, 163);
                    }
                    func_00106390(0x1013, 1);
                }
                k = (k + 1) & 0xFFFF;
            }
            func_0011b480(*(s32 *)(r + 68), *(u16 *)(e + 96 + *(s32 *)(r + 56) * 2 + 1690), q, 0);
            sp[0] = 27;
            sp[1] = 25;
            sp[2] = 6;
            sp[3] = 9;
            sp[4] = 10;
            sp[5] = 26;
            sp[6] = 13;
            sp[7] = 14;
            sp[8] = -1;
            sp[9] = -1;
            {
                s32 a = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 0, 0);
                s32 b = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 1, 0);
                *(s32 *)(r + 72) = func_0011f410(arg0, *(s32 *)(r + 68), e + 96 + *(s32 *)(r + 56) * 136 + 1716, a, b, sp);
            }
            id = *(u16 *)(e + 96 + *(s32 *)(r + 56) * 2 + 1690);
            if (id == 5) {
                s16 t = (func_00231d70(3) + 468) & 0xFFFF;
                func_001f86d0();
                func_001f9a50(t, 3);
            } else {
                s16 t = (func_002238f0(id) + 125) & 0xFFFF;
                s16 u = (t + func_00231d70(3)) & 0xFFFF;
                func_001f9a90();
                func_001f8690(u);
            }
            *(u16 *)r = *(u16 *)r | 2;
            *(u32 *)(r + 4) = 2;
        } else {
            *(u16 *)r = *(u16 *)r & 0xFFFE;
            *(u32 *)(r + 4) = 7;
            func_002bb4e0();
        }
        return 0;
    } else if (st == 2) {
        *(u32 *)(r + 4) = 3;
    }
    if (st == 2 || st == 3) {
        if (func_0011f560(*(s32 *)(r + 72)) != 0) {
            func_0011f580(*(s32 *)(r + 72));
            *(u32 *)(r + 4) = 4;
            *(u16 *)(r + 64) = 0;
        }
        {
            u16 t = *(u16 *)(r + 64) + 1;
            *(u16 *)(r + 64) = t;
            if (((t & 0xFFFF) >= 45) || ((D_008C024E & 0x50) != 0) || (((D_008C024C & 0x10) != 0) && ((s32)*(u16 *)(r + 64) >= 4))) {
                *(u32 *)(r + 4) = 1;
                *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
            }
        }
        return 0;
    } else if (st == 5) {
        if (func_0021de60() != 0) {
            *(u32 *)(r + 4) = 6;
            *(u16 *)r = *(u16 *)r & 0xFFFD;
            return -1;
        }
        return 0;
    }
    return 0;
}

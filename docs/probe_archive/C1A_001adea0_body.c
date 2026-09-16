// func_001adea0 (0x001adea0-0x001ae3c0, 1312B) — guarded floor @271fndiff/1108B (204B under).
// Wins: full packet-chain coverage (35 jals, sibling idioms); 0x20/0x40/default switch;
// triple-193cd0 guard; all decls (2326e0/1f6d60/202590/1f0a10/1f36e0/202740/201de0).
// Walls: frame -0x60 vs -0x80 (sp-slot layout; sp60-last neutral); arg s2-vs-s3 rotation
// (lookahead-absent); &&-guard bnez (empty-then-|| brace-risk, abandoned); u20-mask sll/srl
// vs dsll32/dsrl32 (u64-form neutral); switch bne; GPREL phantoms.
// Unattempted before (no prior note). Production stays ASM.
void func_001adea0(u8 *arg0)
{
    u8 *t18;
    s64 t16;
    u32 sw;
    s32 sp60;
    s32 sp64;
    u16 sp7E;
    s32 t2;
    u8 *pkt;

    if (func_00193cd0(0x700) == 0 && func_00193cd0(0x506) == 0 && func_00193cd0(0x507) == 0) {
        t18 = *(u8 **)(arg0 + 48);
        t16 = *(s64 *)arg0;
        sw = ((u32)func_002326e0(*(s32 *)(t18 + 2660)) << 20) >> 20;
        if (sw == 0x20) {
            func_001f0a10((u8 *)&sp60);
            sp7E = sp7E | 0x100;
            t2 = func_001f6d60(arg0);
            sp60 = t2;
            if (t2 < 0) {
                pkt = func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(pkt + 72) = 12;
                func_00194590(pkt, 1);
                pkt = func_00202740(t18);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
                pkt = func_00201de0((s32)t18, (s32)t18, -1, 0, 0, 0, 1, (u8 *)&sp60, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00202590(t18, 0, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00199ee0(*(u8 **)(arg0 + 48), -2, 0, 0, 1.0f);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 32) = 10;
                *(s16 *)(pkt + 40) = 769;
                *(s64 *)(pkt + 96) = t16;
                func_00194590(pkt, 0);
                pkt = (u8 *)func_001f7c20(10, 2, 24);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
            }
            {
                u16 f = *(u16 *)(arg0 + 108);
                if (f != 2 && f != 3 && f != 1) {
                }
            }
            func_001b0800(arg0, 32);
            return;
        } else if (sw == 0x40) {
            func_001f0a10((u8 *)&sp60);
            sp7E = sp7E | 0x100;
            t2 = func_001f6d60(arg0);
            sp64 = t2;
            if (t2 < 0) {
                pkt = func_001f36e0((s32)arg0, (s32)arg0, &sp60, 1, 1);
                *(s16 *)(pkt + 72) = 12;
                func_00194590(pkt, 1);
                pkt = func_00202740(t18);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
                pkt = func_00201de0((s32)t18, (s32)t18, -1, 0, 0, 0, 1, (u8 *)&sp60, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00202590(t18, 1, 0);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 71) = *(pkt + 71) & 0xDF;
                func_00194590(pkt, 3);
                pkt = func_00199ee0(*(u8 **)(arg0 + 48), -2, 0, 0, 1.0f);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                *(pkt + 32) = 10;
                *(s16 *)(pkt + 40) = 769;
                *(s64 *)(pkt + 96) = t16;
                func_00194590(pkt, 0);
                pkt = (u8 *)func_001f7c20(10, 2, 24);
                *(pkt + 0) = 4;
                *(s64 *)(pkt + 8) = *(s64 *)(pkt + 88);
                func_00194590(pkt, 1);
            }
            {
                u16 f = *(u16 *)(arg0 + 108);
                if (f != 2 && f != 3 && f != 1) {
                }
            }
            func_001b0800(arg0, 32);
            return;
        } else {
            u16 f = *(u16 *)(arg0 + 108);
            u16 v;
            if (f != 2 && f != 3 && f != 1) {
                v = 32;
            } else {
                v = 32;
            }
            func_001b0800(arg0, v);
        }
    }
}

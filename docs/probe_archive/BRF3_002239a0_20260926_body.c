/* func_002239a0 (src/promoted/btlResultFriendPsLvUp.c), 2026-09-26.
 * Measured with tools/fndiff.py: 58 reloc-masked differing words, object
 * 1320B in the 1328B window (retail's last 8 bytes are zero padding after
 * jr/nop, so the instruction count is exact). Previous floor was 179
 * (BRF2_002239a0_body.c).
 *
 * What closed 179 -> 58, all from reading the retail control flow:
 *  - case 1 scan is `for (; r->idx < 4; r->idx++) { if (id != 0) { ...;
 *    if (count > 0) break; } }`: the condition's idx load feeds the first
 *    lhu, the increment block is lw/addiu/sw, and `== 4` reuses that load.
 *  - the skill loop is `for (k = 0; k < 32 && (sid = ...) != 0; k++)
 *    switch (sid)` with sid as s32 (a u16 sid adds an andi); retail tests
 *    0x113 before 0x112 because it is a two-case switch, not if/else.
 *  - q->8 update loads the table word first: `v = table; q->8 += v;`.
 *  - `func_00231d70` returns u32; the extra (s16) cast on it was the
 *    dsll32/dsra32 pair retail does not have.
 *  - case 3 only falls into case 4 when func_0011f560 succeeds; otherwise
 *    it breaks.
 *  - the two late `lhu/lh 0x69A` reads are array-index form
 *    `((u16 *)(base + 0x69A))[idx]` (retail `addu v0, idx*2, base`); the
 *    early ones stay `base + idx*2 + 0x69A` (`addu v0, base, idx*2`).
 *  - case 4's `++*(u16 *)(r + 64) >= 45` gives retail's sh-before-andi.
 *
 * Residual (all 58 words): saved-register colouring only. Retail keeps
 * base = e + 96 in $s2 apart from e ($s1), which lets k reuse $s1 and puts
 * r in $s3. Here base coalesces into e's $s1, so r lands in $s2 and k in
 * $s3. Tried without effect (all 58): 40-step declaration-order hill
 * climb, six hand orders, block-scoped base or k, k initialised early,
 * e as s32 or u8 ** with base cast back, `&e[96]`, and every pragma
 * (opt_dead_assignments/loop_invariants/propagation/strength/unroll tie;
 * common_subs off, schedule, peephole and other levels are 258-340).
 * Folding base into each access (`e + 96 + ...`) drops the $s2 temp
 * entirely (249 words).
 */
s32 func_002239a0(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *r;
    u8 *e;
    u8 *base;
    u32 st;
    u8 *q;
    s32 v;
    s32 k;
    u16 id;
    s32 sp[11];
    s32 zw[2];

    r = func_00452560(arg0);
    e = *(u8 **)(r + 60);
    *(s32 *)(r + 8) = 0;
    *(s32 *)(r + 12) = 0;
    func_00460ac0(D_00795F20, r + 8);
    st = *(u32 *)(r + 4);
    switch (st) {
    case 0:
        *(s32 *)(r + 56) = 0;
        v = func_00452380(D_005E4810);
        *(s32 *)(r + 68) = v;
        if (v == 0) {
            v = func_00117780(0, 15, 4, 5, 0);
            *(s32 *)(r + 68) = v;
            if (v == 0) {
                func_0046d730(D_00629720, 116);
            }
            zw[0] = 0;
            zw[1] = 0x41980000;
            func_0011d100(*(s32 *)(r + 68), zw);
            func_0011bb90(*(s32 *)(r + 68));
        }
        func_00117580(*(s32 *)(r + 68), 174);
        *(u32 *)(r + 4) = 2;
        /* fallthrough */
    case 1:
        base = e + 96;
        for (; *(s32 *)(r + 56) < 4; (*(s32 *)(r + 56))++) {
            id = *(u16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A);
            if (id != 0) {
                q = (u8 *)func_0010a900(id);
                v = *(s32 *)(base + *(s32 *)(r + 56) * 4 + 0x6A4);
                *(s32 *)(q + 8) += v;
                if ((s32)*(u8 *)(base + *(s32 *)(r + 56) * 136 + 0x6B4) > 0) {
                    break;
                }
            }
        }
        if (*(s32 *)(r + 56) != 4) {
            s32 sid;
            for (k = 0; k < 32 && (sid = *(u16 *)(base + *(s32 *)(r + 56) * 136 + k * 2 + 0x6B6)) != 0; k++) {
                switch (sid) {
                case 0x112:
                    if (datGetFlag(0x1012) != 0) {
                        func_0046d730(D_00629720, 158);
                    }
                    func_00106390(0x1012, 1);
                    break;
                case 0x113:
                    if (datGetFlag(0x1013) != 0) {
                        func_0046d730(D_00629720, 163);
                    }
                    func_00106390(0x1013, 1);
                    break;
                }
            }
            func_0011b480(*(s32 *)(r + 68), ((u16 *)(base + 0x69A))[*(s32 *)(r + 56)], q, 0);
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
            sp[10] = -1;
            {
                s32 a = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 0, 0);
                s32 b = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 1, 0);
                *(s32 *)(r + 72) = func_0011f410(arg0, *(s32 *)(r + 68), base + *(s32 *)(r + 56) * 136 + 0x6B4, a, b, sp);
            }
            if (((s16 *)(base + 0x69A))[*(s32 *)(r + 56)] == 5) {
                s16 t = (s16)(func_00231d70(3) + 468);
                func_001f86d0();
                func_001f9a50((u16)t, 3);
            } else {
                s32 stmp = func_002238f0(*(s16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A)) + 125;
                s16 u = (s16)(stmp + func_00231d70(3));
                func_001f9a90();
                func_001f8690((u16)u);
            }
            *(u16 *)r = *(u16 *)r | 2;
            *(u32 *)(r + 4) = 2;
        } else {
            *(u16 *)r = *(u16 *)r & 0xFFFE;
            *(u32 *)(r + 4) = 7;
            func_002bb4e0();
        }
        break;
    case 2:
        *(u32 *)(r + 4) = 3;
        /* fallthrough */
    case 3:
        if (func_0011f560(*(s32 *)(r + 72)) == 0) {
            break;
        }
        func_0011f580(*(s32 *)(r + 72));
        *(u32 *)(r + 4) = 4;
        *(u16 *)(r + 64) = 0;
        /* fallthrough */
    case 4:
        {
            if ((++*(u16 *)(r + 64) >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (*(u16 *)(r + 64) >= 4))) {
                *(u32 *)(r + 4) = 1;
                *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
            }
        }
        break;
    case 5:
        if (func_0021de60() != 0) {
            *(u32 *)(r + 4) = 6;
            /* fallthrough */
        case 6:
            *(u16 *)r = *(u16 *)r & 0xFFFD;
            return -1;
        }
        break;
    case 7:
    default:
        break;
    }
    return 0;
}

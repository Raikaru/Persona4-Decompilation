/* func_00380ea0 (btlShuffleResult, window 2112B) -- best draft 2026-09-26.
 * 2112B/2112B, 3 reloc-masked differing words (owner guarded draft: 271).
 * Levers, in order of effect:
 *  - opt_propagation off around the function: the case-0 slot store address
 *    is written before the func_0010ace0 call and held in $s6 (frame 0xB0,
 *    seven saved registers) as retail does; the draft sank it (0xA0);
 *  - cnt/cur as s32 holding `(u16)call()` (u16 locals re-mask under
 *    propagation off);  `i = 0; j = 1;` before the loop;
 *  - slot table indexed as `((u8 **)(state + 0x4C))[k]` (retail adds the
 *    scaled index first);
 *  - in cases 3/4 `idx = state[1] + state[2]` computed once after the two
 *    stores and shared by both res arms; case 4 tests `res > 0` first;
 *  - case 5 is `switch (func_002bb140()) { case 0: ... case 1: ... }` and
 *    holds `&slots[sum]` (u8 **) across the calls.
 * Residual (3 words at +0x2c..+0x34): retail loads the two halves of `sum`
 * into $t0/$a3 (0x20 first) where b210 uses $v1/$v0. Flat at 3: state-based
 * operands, swapped operands, separate col/row locals (either order),
 * decl order sum/state; sum before state: 4. */
#pragma push
#pragma opt_propagation off
s32 func_00380ea0(u8 *arg0)
{
    u8 *state;
    s32 sum;
    s32 cnt;
    s32 cur;
    s32 i;
    s32 j;
    u16 *slotp;
    u16 **dst;
    u8 buf[0x30];
    s32 res;
    s32 idx;

    state = arg0 + 0x18;
    sum = *(s32 *)(arg0 + 0x1C) + *(s32 *)(arg0 + 0x20);
    switch (*(s32 *)state) {
    case 0:
        func_0010cad0(state + 0x1C, *(u16 *)(arg0 + 0x10));
        *(u8 **)(state + 0x4C) = state + 0x1C;
        cnt = (u16)func_0010b5b0();
        cur = (u16)func_0010b460();
        i = 0;
        j = 1;
        for (; i < cnt; i++) {
            dst = (u16 **)(state + j * 4 + 0x4C);
            slotp = func_0010ace0((s16)i);
            *dst = slotp;
            if (*(u16 *)((u8 *)slotp + 2) != cur) {
                j++;
            }
        }
        res = func_00117780(*(s32 *)(*(u8 **)arg0 + 0x1F290), 0x12, 2, 5, 5);
        *(s32 *)(state + 0x18) = res;
        *(s32 *)(state + 0x0C) = j;
        *(s32 *)state = 1;
        *(s32 *)(state + 0x10) = 0;
        *(s32 *)(state + 0x14) = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)state = 2;
            {
                s32 v;
                v = *(s32 *)(*(u8 **)arg0 + 0x1F298);
                {
                    func_0038d060(v);
                    func_0038d0d0(v, 4);
                }
                func_00388d20(*(s32 *)(*(u8 **)arg0 + 0x1F294));
            }
        }
        break;
    case 2:
        if (*(s32 *)(state + 0x14) == 0) {
            if (D_008C024E[0] & 0x40) {
                u8 *txt;
                txt = func_00109220(*(u16 *)(((u8 **)(state + 0x4C))[sum] + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
                func_0045af60(0, 4, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                func_0011b480(*(s32 *)(state + 0x18), 1, ((u8 **)(state + 0x4C))[sum], 0);
                func_0011bb90(*(s32 *)(state + 0x18));
                *(s32 *)state = 3;
            } else {
                func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
                func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                if (func_00453960(buf) != 0) {
                    *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                    *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                    func_0045af60(0, 4, 0, 0);
                }
            }
        }
        break;
    case 3:
        if (D_008C024E[0] & 0x40) {
            func_0011bc70(*(s32 *)(state + 0x18));
            {
                u8 *txt;
                txt = func_00109220(*(u16 *)(((u8 **)(state + 0x4C))[*(s32 *)(state + 4) + *(s32 *)(state + 8)] + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            func_0011bc70(*(s32 *)(state + 0x18));
            *(s32 *)state = 2;
            func_0045af60(0, 4, 0, 4);
        } else if (D_008C024E[0] & 0x80) {
            func_0011c630(*(s32 *)(state + 0x18));
            *(s32 *)state = 4;
        } else {
            func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
            func_00453860(buf, 8, 4, 0, 0);
            func_00453760(buf, 0);
            res = func_00453960(buf);
            if (res > 0) {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                idx = *(s32 *)(state + 4) + *(s32 *)(state + 8);
                if (res == 2) {
                    func_0011c180(*(s32 *)(state + 0x18), 1, ((u8 **)(state + 0x4C))[idx], 0);
                } else if (res == 1) {
                    func_0011c2c0(*(s32 *)(state + 0x18), 1, ((u8 **)(state + 0x4C))[idx], 0);
                }
            }
        }
        break;
    case 4:
        if ((D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x20)) {
            func_0011c6e0(*(s32 *)(state + 0x18), 1);
            *(s32 *)state = 3;
        } else if (D_008C024E[0] & 0x40) {
            func_0011bc70(*(s32 *)(state + 0x18));
            {
                u8 *txt;
                txt = func_00109220(*(u16 *)(((u8 **)(state + 0x4C))[*(s32 *)(state + 4) + *(s32 *)(state + 8)] + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
            }
        } else {
            func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
            func_00453860(buf, 8, 4, 0, 0);
            func_00453760(buf, 0);
            res = func_00453960(buf);
            if (res > 0) {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                idx = *(s32 *)(state + 4) + *(s32 *)(state + 8);
                if (res == 2) {
                    func_0011c180(*(s32 *)(state + 0x18), 1, ((u8 **)(state + 0x4C))[idx], 0);
                } else if (res == 1) {
                    func_0011c2c0(*(s32 *)(state + 0x18), 1, ((u8 **)(state + 0x4C))[idx], 0);
                }
                *(s32 *)state = 3;
            } else {
                func_0011caf0(*(s32 *)(state + 0x18));
            }
        }
        break;
    case 5:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            switch (func_002bb140()) {
            case 0:
                func_0011b360(*(s32 *)(state + 0x18));
                *(s32 *)(state + 0x18) = 0;
                func_0038d0a0(*(s32 *)(*(u8 **)arg0 + 0x1F298));
                func_00388d40(*(s32 *)(*(u8 **)arg0 + 0x1F294));
                {
                    u8 **slot;
                    u8 *txt;
                    slot = &((u8 **)(state + 0x4C))[sum];
                    txt = func_00109220(*(u16 *)(*slot + 2));
                    func_002bbd20(0, txt);
                    func_002bad10(6);
                    *(s32 *)state = 6;
                    if (sum != 0) {
                        func_0010ad80(*(u16 *)(*slot + 2));
                        func_0010b060(*(u16 *)(arg0 + 0x10));
                    }
                }
                break;
            case 1:
                func_002bb1e0(1);
                *(s32 *)state = 2;
                break;
            }
        }
        break;
    case 6:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            return 1;
        }
        break;
    default:
        func_0046d730(D_0064EC70, 0x3F4);
        break;
    }
    return 0;
}

#pragma pop

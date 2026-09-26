/* func_001dbf20 (src/Battle/btlAICommand.c) 2026-09-26 round 2: 7 differing
   words (1116B object / 1120B window, 279/279 instructions), down from the
   round-1 body's 21 edits (BtlAICommand_001dbf20_20260925_body.c).
   Levers over round 1:
   - the bubble-sort swap written field by field on entries[k] / entries[k + 1]
     (no entry pointer): retail's &entries[k + 1] comes from the loop test's
     masked k and the swap stores through &entries[k].ratio (24 words);
   - `last = num - 1` as a named s32 before the do-while: retail computes it
     ahead of the hoisted `swapped = 1` constant (7 words).
   Residual: last and k have swapped colours (retail last $t0 / k $a3, this
   body last $a3 / k $t0).  Inert: every position of `last` and of `k` in the
   declaration list, u32 last, `last > k`, s32 k in the file's masked-counter
   form ((u16)k < last with (u16)k indices), k merged with hp/maxHp/roll, last
   merged with idx/j/n/random, `while (swapped)`, `while (1) ... break`.
   Worse: k merged with m (44) or i (38), `last = num; last--` (38), k from 1
   (94), for (swapped = 1; ...) (96).  permute.py 600 s: no improvement. */
typedef struct DatUnit DatUnit;
typedef struct BtlAIHpEntry {
    u32 unit;
    f32 ratio;
} BtlAIHpEntry;
#pragma push
#pragma opt_loop_invariants on
s32 func_001dbf20(u8 *arg0, u32 arg1) {
    extern u16 func_00231f80(DatUnit *unit);
    extern u8 D_006095F0[][4];
    BtlAIHpEntry entries[12];
    BtlAIHpEntry *entry;
    s32 last;
    s32 swapped;
    u16 k;
    f32 ratio;
    u32 unit;
    u16 count;
    s32 num;
    u16 i;
    s32 j;
    s32 n;
    s32 idx;
    u16 sum;
    u16 m;
    u16 roll;
    u16 maxHp;
    u16 hp;
    s32 random;
    u32 *slot;

    if (func_001d7f10(arg0, arg0 + 0x98, *(u16 *)(arg0 + 0x6E), 0) != 0) {
        for (i = 0; i < *(u16 *)(arg0 + 0xD0); i++) {
            *(u32 *)(arg0 + i * 4 + 0x38) = *(u32 *)(arg0 + i * 4 + 0x98);
        }
        *(u16 *)(arg0 + 0x6A) = *(u16 *)(arg0 + 0xD0);
        return 1;
    }
    count = *(u16 *)(arg0 + 0xD0);
    random = 1;
    if (count == 1) {
        *(u32 *)(arg0 + 0x38) = *(u32 *)(arg0 + 0x98);
        *(u16 *)(arg0 + 0x6A) = 1;
    } else {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
            for (j = 0; (u16)j < count; j = (j + 1) & 0xFFFF) {
                if (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + (j & 0xFFFF) * 4 + 0x98) + 0x30) + 0xA2) != 0) {
                    break;
                }
            }
            if ((u16)j == count) {
                random = 0;
            }
        }
        switch (*(iGpffffb3b8 + *(u16 *)(arg0 + 0x6E) * 40 + 0x11)) {
        case 0x01:
        case 0x03:
        case 0x04:
        case 0x08:
        case 0x0A:
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x10:
            break;
        default:
            random = 1;
            break;
        }
        if (random != 0 || count > 4) {
            roll = func_00231d70(count);
            *(u32 *)(arg0 + 0x38) = ((u32 *)(arg0 + 0x98))[roll];
            *(u16 *)(arg0 + 0x6A) = 1;
        } else {
            n = 0;
            num = *(u16 *)(arg0 + 0xD0);
            for (; (u16)n < num; n = (n + 1) & 0xFFFF) {
                idx = n & 0xFFFF;
                slot = (u32 *)(arg0 + idx * 4 + 0x98);
                unit = *slot;
                maxHp = func_00231f80(*(DatUnit **)(*(u8 **)(unit + 0x30) + 0xA64));
                hp = datCalcGetHp(*(u32 *)(*(u8 **)(unit + 0x30) + 0xA64));
                entry = &entries[idx];
                entry->unit = *slot;
                entry->ratio = (f32)hp / (f32)maxHp;
            }
            last = num - 1;
            do {
                swapped = 0;
                for (k = 0; k < last; k++) {
                if (entries[k].ratio < entries[k + 1].ratio) {
                    unit = entries[k].unit;
                    ratio = entries[k].ratio;
                    entries[k].unit = entries[k + 1].unit;
                    entries[k].ratio = entries[k + 1].ratio;
                    entries[k + 1].unit = unit;
                    entries[k + 1].ratio = ratio;
                    swapped = 1;
                }
                }
            } while (swapped != 0);
            roll = func_00231d70(100);
            sum = 0;
            for (m = 0; m < count; m++) {
                sum += D_006095F0[count - 1][m];
                if (sum >= roll) {
                    break;
                }
            }
            if (num != m) {
                *(u32 *)(arg0 + 0x38) = entries[m].unit;
                *(u16 *)(arg0 + 0x6A) = 1;
            } else {
                *(u32 *)(arg0 + 0x38) = entries[func_00231d70(count)].unit;
                *(u16 *)(arg0 + 0x6A) = 1;
            }
        }
    }
    return 1;
}
#pragma pop

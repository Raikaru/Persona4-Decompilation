/* func_001dbf20 (src/Battle/btlAICommand.c) 2026-09-25 rewrite: 275/278 retail
   instructions, fnalign 21 edits + 3 reloc-only (the guarded draft measured
   247 positional words; this body's first cut was 101 edits).  Splice with
   `tools/fnalign.py src/Battle/btlAICommand.c func_001dbf20 --candidate <this>`.
   Levers, in order of effect:
   - rotated `for` loops (the draft's `while (1) { if (...) break; }` gave
     top-tested loops); separate variables per loop so only the HP loop's
     index lives in a saved register;
   - `#pragma opt_loop_invariants on`: retail hoists `num - 1`, the constant 1
     for `swapped`, and the weight-row base `D_006095F0 + count * 4`;
   - `num` as an s32 re-read of the count field (`*(u16 *)(arg0 + 0xD0)`), so
     it stays distinct from `count` (andi $s3,$s4) instead of being coalesced;
   - the HP and hit-scan loops in the file's s32 counter form
     (`(u16)n < num`, `n = (n + 1) & 0xFFFF`, body `n & 0xFFFF`): with a u16
     counter the body reuses the loop test's masked value and the saved
     registers rotate;
   - `*(u16 *)(arg0 + 0x6A) = 1` written in both final arms (retail duplicates
     it), `sum` declared before `m`, the random pick as
     `((u32 *)(arg0 + 0x98))[roll]` (index + base order), `count > 4` (slti $at).
   Residual (all in the bubble sort): retail hoists `num - 1` above the
   do-while (object hoists it only out of the inner loop), and addresses
   entries[k + 1].ratio through a second &entries[k] built from the loop test's
   masked k (`addiu $v1,$v0,0x90; lwc1 $f0,0xc($v1)`) while the swap goes
   through a fresh &entries[k] plus &entries[k].ratio ($a2/$a1).  Every
   spelling tried merges the two addresses (index form, pointer form, s32 k
   with `(u16)k` / `k & 0xFFFF` split, a separate `next` pointer, struct
   copies 51-56, `last = num - 1` 27).  Pragmas on top of loop_invariants:
   lifetimes / strength_reduction off neutral, propagation off 43,
   dead_assignments off 43, common_subs off 90, O3/O4 186/222. */
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
    f32 ratio;
    u16 count;
    s32 num;
    u16 i;
    s32 j;
    s32 n;
    u16 k;
    s32 idx;
    u16 sum;
    u16 m;
    u16 roll;
    u16 maxHp;
    u16 hp;
    s32 random;
    s32 swapped;
    u32 unit;
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
            do {
                swapped = 0;
                for (k = 0; k < num - 1; k++) {
                    entry = &entries[k];
                    ratio = entry->ratio;
                    if (ratio < entry[1].ratio) {
                        unit = entry->unit;
                        entry->unit = entry[1].unit;
                        entry->ratio = entry[1].ratio;
                        entry[1].unit = unit;
                        entry[1].ratio = ratio;
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

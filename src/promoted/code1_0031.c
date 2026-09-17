#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *);
extern s8 D_00641E60[];
extern s32 func_00246830();
extern u8 *iGpffffb3d4;
extern s16 D_006420A0[];
extern u32 D_00642EF0[];
extern u32 D_00642F00[];
extern u16 *func_0010ac10(s32 arg0);
extern u8 *func_002e4870(s8 arg0);
extern void func_002e55c0(s8 arg0, s32 arg1, s8 arg2);
extern u8 *func_002e48a0();
static inline s32 func_0031_ne(s32 value, s32 target)
{
    return value != target;
}

extern u32 func_0010c750(void *persona, u16 level);
extern s32 func_00106330(s32 arg0);
extern s32 func_00106600(s16 id);
extern u16 func_00107ac0(s32 arg0);
extern u8 D_006432B0[];
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern void func_002e7920(s32 *month, s32 *day);
extern void func_00313d20(u8 *arg0, u8 month, u8 day, s8 mode);

static inline s8 findDateEntry(u8 month, u8 day)
{
    s8 index = 0;
    u8 *entry;

    for (;;) {
        index++;
        entry = D_006432B0 + index * 0x1C;
        if (*(s8 *)entry == -1 && *(s8 *)(entry + 1) == -1) return -1;
        if (*(s8 *)entry == month && *(s8 *)(entry + 1) == day) return index;
    }
}

// FUN_00311900
void func_00311900(s64 arg0)
{
    func_00246830(arg0 & 0xFFFF);
}
/* Floor: 5 differing words over 5 fnalign edits, 149 emitted against */
/* retail's 149 (100%). Levers that moved it: u16/u8-ptr/s8 param types, */
/* scoped optimization_level 1, saved-reg audit order. U8-decl of temp_19 */
/* worsened 5->100 this session. WALL: cvt.w.s destination selection ($f1 */
/* b210 vs $f0 retail) in the (u8) conversion idiom at 0x70/0x74 and the */
/* taken-path sub at 0x88/0x8C/0x90; invariant under direct-u8 conversion, */
/* int/const-float initializers, reversed float decl order, result-domain decl. */
/* Pragma sweep 2026-09-17: schedule off, opt_propagation off, */
/* opt_common_subs off and opt_loop_invariants on each tie at 5 words / */
/* 5 edits with a byte-identical stream (probe_variants + fnalign --candidate). */
// FUN_00311930 NONMATCHING
#ifdef NON_MATCHING
/* Re-certified under scoped optimization_level 1: object 596B / window */
/* 608B, raw fndiff 8 words = five executable words and three zero-tail */
/* words. The historical normalized_diff=6 counts differing bytes, not */
/* words. Executable offsets: 0x70, 0x74, 0x88, 0x8C, 0x90; candidate */
/* cvt.w.s/mfc1 and sub.s/cvt.w.s/mfc1 use $f1 where retail uses $f0. */
/* Direct u8 conversion of the same table expression, a direct integer */
/* initializer, and a const float initializer all leave this unchanged. */
/* Preserve both lookups, the u8 conversion, and the later unsigned */
/* integer-to-float conversion. Reversed float declaration order also */
/* failed previously. Retain ASM. */
/* Independent retail review confirms low-u16 community ID, input-only */
/* persona pointer, low-s8 scaling flag and full s32 result. Correcting */
/* these parameter types preserves the five-word floor. Native semantic */
/* smoke: 42,735 scenarios / 204,435 helper calls, including independent */
/* rank snapshots, assignment-loop behavior and division before scaling. */
/* saved-register audit: retail s7=arg2, s6=temp_17 (scaled delta), s5=arg0, s4=arg1, s3=temp_19 (byte count), s2=var_18 (accumulator), s1=var_17 (then var_3), s0=temp_16 (count); this list matches exactly under optimization_level 1. No opt_propagation-off three-part recipe is needed: no parameter-derived local is materialized. */
#pragma push
#pragma optimization_level 1
s32 func_00311930(u16 arg0, u8 *arg1, s8 arg2)
{
    extern s32 func_00115890(u8 *arg0, s32 arg1);
    extern f32 D_007494D0[];
    extern f32 D_00749500[];
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    s32 temp_19;
    s32 var_18;
    s64 temp_17;
    s32 var_17;
    s32 temp_16;
    s32 var_3;
    temp_f1 = D_00749500[func_00107ac0(arg0 & 0xFFFF)];
    temp_19 = (u8)temp_f1;
    temp_f1_2 = D_00749500[func_00107ac0(arg0 & 0xFFFF)];
    var_f0 = (f32)(u32)temp_19;
    temp_17 = (s16)(10.0f * (temp_f1_2 - var_f0));
    var_18 = 0;
    var_17 = 0;
    temp_16 = temp_19 & 0xFF;
    while ((s16)(s64)var_17 < temp_16) {
        var_18 = func_00115890(arg1, (u8)var_17);
        var_17 = (s16)(var_17 + 1);
    }
    var_3 = (s16)temp_17;
    if (var_3 != 0) {
        temp_16 = func_00115890(arg1, (u8)(temp_16 - 1));
        var_18 += (s32)((s32)var_3 * 10 * ((func_00115890(arg1, temp_19) - temp_16) / 100));
    }
    if ((s8)arg2 == 0) {
        return var_18;
    }
    return (s32)((f32)var_18 * D_007494D0[func_00107ac0(arg0 & 0xFFFF)]);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311930);
#endif
/* measured: b210 -O2 with loop-invariant hoisting gives 364B/368B,
   normalized diff 0; the remaining retail word is zero tail padding.
   Entries contain a signed 10-bit value and independent bit-14 category
   and bit-15 required flags. Count/index and found/index declaration order
   preserves the two retail register pairs; the shared constant 1 is hoisted. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00311B90
s32 func_00311b90(u16 *arg0, u16 *arg1, s32 arg2, s16 *arg3)
{
    typedef struct {
        s16 value : 10;
        s16 reserved : 4;
        s16 category : 1;
        s16 required : 1;
    } SelectionEntry;
    s32 result;
    s16 count;
    s16 i;
    s32 value;
    s16 j;
    s16 found;
    s32 bit;
    s32 one;
    u16 candidate;
    u8 *base;
    u8 *table;
    SelectionEntry *entry;

    if (*arg0 == 0) {
        return 0;
    }
    count = 0;
    result = 0;
    base = (u8 *)arg0 + 4;
    i = 0;
    table = iGpffffb3d4;
    one = 1;
    for (; i < 8; i++) {
        entry = (SelectionEntry *)(base + (i * 2) + 4);
        value = entry->value;
        if (value != 0) {
            found = 0;
            for (j = 0; j < arg2; j++) {
                bit = (s32)((u32)one << j);
                if ((result & bit) == 0) {
                    if (entry->category != 0) {
                        candidate = *(u8 *)(table
                            + (*(u16 *)((u8 *)arg1 + (j * 2)) * 14) + 2);
                    } else {
                        candidate = *(u16 *)((u8 *)arg1 + (j * 2));
                    }
                    if ((candidate & 0xFFFF) == value) {
                        result |= bit;
                        count++;
                        found = 1;
                        break;
                    }
                }
            }
            if (entry->required != 0 && found == 0) {
                return 0;
            }
        }
    }
    if (arg3 != 0) {
        *arg3 = count;
    }
    return result;
}
#pragma pop
// FUN_00311D00
s64 func_00311d00(s32 arg0)
{
    s64 result;
    u16 flags = *(u16 *)(iGpffffb3d4 + ((arg0 & 0xFFFF) * 14));

    if (flags & 1) {
        result = 0;
        goto exit;
    }
    if (flags & 2) {
        result = 0;
        goto exit;
    }
    result = 1;
exit:
    return (s8)result;
}
// FUN_00311D60
s32 func_00311d60(s32 arg0)
{
    s16 temp_3;
    u32 var_18;
    s32 var_17;
    s32 value;
    u8 *temp_4;
    s32 result;

    var_17 = 1;
    var_18 = 0;
    value = arg0 & 0xFFFF;
    goto loop_test;
loop_body:
    temp_4 = (u8 *)D_006420A0 + (var_18 * 8);
    if (value != *(s16 *)(temp_4 + 4)) {
        goto block_8;
    }
    temp_3 = *(s16 *)(temp_4 + 6);
    if (temp_3 & 1) {
        if (func_00106330(*(s32 *)temp_4) == 0) {
            result = 0;
            goto done;
        }
    } else {
        if ((temp_3 & 2) == 0) {
            goto block_8;
        }
        var_17 = 0;
        if (func_00106330(*(s32 *)temp_4) == 1) {
            result = 1;
            goto done;
        }
    }
block_8:
    var_18 += 1;
loop_test:
    if (var_18 < 0x17U) {
        goto loop_body;
    }
    result = var_17;
done:
    return result;
}
/* measured: loop-invariant absolute table base requires the retail preheader. */
#pragma opt_loop_invariants on
// FUN_00311E40
s32 func_00311e40(s32 arg0)
{
    u32 i;

    i = 0;
    while (i < 0x17U) {
        if ((arg0 & 0xFFFF) == D_006420A0[i * 4 + 2]) {
            return 1;
        }
        i++;
    }
    return 0;
}
/* measured: restore the default invariant setting after this function. */
#pragma opt_loop_invariants off
// FUN_00313690
s8 func_00313690(s64 arg0)
{
    return D_00641E60[(s16)arg0];
}
// FUN_003136B0
s32 func_003136b0(u16 arg0)
{
    s32 value;
    s32 result;

    value = arg0 & 0xFFFF;
    if (value == 0x93) {
        result = (func_00106600(0x4A8) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xB9) {
        result = (func_00106600(0x4A4) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x26) {
        result = (func_00106600(0x4A6) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x53) {
        result = (func_00106600(0x4AD) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x68) {
        result = (func_00106600(0x4AF) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xA6) {
        if ((func_00107ac0(0x1E) & 0xFFFF) == 0xA) {
            result = 1;
        } else {
            result = func_00106330(0x1DD) != 0;
        }
        goto done;
    }
    result = 1;
done:
    return result;
}
/* measured: structured signed loops and declaration order give 452B/464B,
   with only three zero-tail words under loop-invariant hoisting. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00313800
void func_00313800(s8 arg0)
{
    u8 *items;
    s16 row;
    s16 item;
    s16 selected;
    s32 column;
    u8 *entry;
    u8 *table;
    s16 *value;

    selected = 0;
    row = 0;
    table = (u8 *)D_00642F00 + arg0 * 8;
    for (; row < 6; row++) {
        entry = *(u8 **)(table - 0x10) + row * 0x20;
        if (*(u16 *)entry != 0 && func_003136b0(*(u16 *)entry) == 1) {
            func_002e55c0(0, *(s16 *)entry, 0);
            items = entry + 4;
            func_002e4870(0)[0x14 + selected] = 1;
            item = 0;
            column = selected + 1;
            for (; item < arg0; item++) {
                value = (s16 *)(items + item * 2 + 4);
                func_002e55c0((s8)column, *value, 1);
                func_002e4870((s8)column)[0x14 + item] = 0;
                if (func_0010ac10(*(u16 *)value) != NULL) {
                    func_002e4870((s8)column)[0x14 + item] = 1;
                }
            }
            selected++;
        }
    }
}
#pragma pop
// FUN_003139D0
s32 func_003139d0(s64 arg0, s64 arg1)
{
    s32 i;
    s32 start;
    s64 limit;
    s32 result;

    i = 0;
    start = (s8)arg1 + 1;
    limit = (s8)arg0;
    goto loop_test;
loop_body:
    if (func_0010ac10(*(u16 *)(func_002e48a0((s8)start, i) + 2)) == 0) {
        result = 0;
        goto done;
    }
    i = (s16)(i + 1);
loop_test:
    if ((s16)i < limit) {
        goto loop_body;
    }
    result = 1;
done:
    return result;
}
// FUN_00313A80
s32 func_00313a80(s64 arg0, s64 arg1)
{
    return func_0010ac10(*(u16 *)(*(u8 **)((u8 *)D_00642EF0 + ((s8)arg0 * 8)) + ((s8)arg1 * 0x20))) != 0;
}
// FUN_00313AE0
s64 func_00313ae0(s64 arg0, s32 arg1)
{
    s32 i;
    s64 result;
    u8 *table;

    i = 0;
    arg1 = (u16)arg1;
    table = (u8 *)D_00642F00 + ((s8)arg0 * 8);
    goto loop_test;
loop_body:
    if (func_0031_ne(*(u16 *)(*(u8 **)(table - 0x10) + (i * 0x20)), arg1)) {
        goto loop_next;
    }
    result = (s8)i;
    goto done;
loop_next:
    i++;
loop_test:
    if (i < 6) {
        goto loop_body;
    }
    result = 0;
done:
    return result;
}
/* measured: shared inline lookup and loop-invariant hoisting give 464B/464B MATCH. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00313B50
void func_00313b50(u8 *arg0)
{
    s32 month;
    s32 day;
    u8 current_day;
    u8 current_month;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    current_day = func_002e78e0();
    current_month = func_002e78a0();
    *(s8 *)(work + 0x2D4) = findDateEntry(current_month, current_day);
    func_00313d20(arg0, func_002e78a0(), func_002e78e0(), 0);
    month = func_002e78a0();
    day = func_002e78e0() + 1;
    func_002e7920(&month, &day);
    *(s8 *)(work + 0x2D5) = findDateEntry((u8)month, (u8)day);
    func_00313d20(arg0, (u8)month, (u8)day, 1);
    *(u8 *)(work + 0x2D2) = month;
    *(u8 *)(work + 0x2D3) = day;
    *(u8 *)(work + 0x2D6) = 0;
}
#pragma pop
/* Floor: 129 differing words (probe_variants) over 60 fnalign edits (+4 reloc-only), 163 emitted against */
/* retail's 163 (100%). Levers that moved it: truthful (u8-ptr,u8,u8,s8) sig */
/* plus s64-return callee decl (140->138); structured while loops for the */
/* jump-to-test lowering (138->135); opt_loop_invariants on for the hoisted */
/* base-plus-offset address invariant (135->131); s8->s16 for temp_4_4/temp_11_3 */
/* (edits 64->60, words 129 neutral). Ruled out with measurement: */
/* var_17/var_18 decl swap (131->130); param-sourced x5 multiply (neutral at */
/* 130, CSE-defeated); opt_propagation off (130->138, worse); var_18 reuse for */
/* the -1 compare (neutral at 129). WALL: saved-register colour rotation plus */
/* temp-reg selection and the resulting branch-displacement cascade; loop */
/* bounds already slti-$v1 both sides (no slti-$at lever); no adjacent-const */
/* OR fold; single call site (no index mask CSE shape); no MAC block. */
/* measured 00313d20: `opt_common_subs off` inside the guard is worth 1 words (130 -> 129); retail rematerialises what b210 hoists. */
// FUN_00313D20 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
#pragma push
#pragma opt_loop_invariants on
void func_00313d20(u8 *arg0, u8 arg1, u8 arg2, s8 arg3)
{
    extern s64 func_00110a60(s32 arg0, s32 arg1);
    extern u8 D_00643D00[];
    s32 temp_16;
    s32 temp_4_5;
    s32 temp_6;
    s32 temp_11;
    s32 temp_19;
    s32 temp_4_2;
    s32 var_18;
    s32 var_17;
    s32 var_4;
    s32 var_6;
    s32 var_8;
    s16 temp_11_3;
    s8 temp_4;
    s16 temp_4_4;
    u8 *temp_11_2;
    u8 *temp_4_3;
    u8 *temp_5;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_8;

    temp_16 = *(s32 *)(arg0 + 0x38);
    var_18 = -1;
    temp_19 = (s8)arg3;
    temp_4 = *(s8 *)(temp_19 + temp_16 + 0x2D4);
    if (temp_4 == -1) {
        temp_7 = D_00643D00 + (s8)func_00110a60(arg1, arg2) * 0x14;
        var_8 = 0;
        temp_6 = temp_19 * 5;
        while ((s16)var_8 < 5) {
            temp_4_2 = (s16)var_8;
            *(s8 *)(temp_16 + temp_6 + temp_4_2 + 0x2C4) = 0;
            temp_4_3 = temp_7 + temp_4_2 * 4;
            if (*(s8 *)temp_4_3 != 0) {
                temp_4_4 = *(s8 *)(temp_4_3 + 1);
                if ((s16)var_18 < temp_4_4) {
                    var_17 = (s8)var_8;
                    var_18 = (s16)temp_4_4;
                }
            }
            var_8 = (s16)(var_8 + 1);
        }
        if ((s16)var_18 != -1) {
            *(s8 *)((s8)var_17 + temp_6 + temp_16 + 0x2C4) = 1;
        }
    } else {
        temp_5 = D_006432B0 + temp_4 * 0x1C;
        temp_8 = (u8 *)((temp_19 * 2) + temp_16);
        *(s16 *)(temp_8 + 0x2C0) = 0;
        var_4 = 0;
        while ((s16)var_4 < 3) {
            if (*(s8 *)(temp_5 + 2) != 0) {
                *(s16 *)(temp_8 + 0x2C0) = (s16)(*(s16 *)(temp_8 + 0x2C0) + 1);
            }
            var_4 = (s16)(var_4 + 1);
        }
        var_6 = 0;
        temp_4_5 = temp_19 * 5;
        while ((s16)var_6 < 5) {
            temp_11 = (s16)var_6;
            temp_7_2 = (u8 *)(temp_16 + temp_4_5 + temp_11);
            *(s8 *)(temp_7_2 + 0x2C4) = 0;
            temp_11_2 = temp_5 + temp_11 * 4;
            if (*(s8 *)(temp_11_2 + 8) != 0) {
                *(s16 *)(temp_8 + 0x2C0) = (s16)(*(s16 *)(temp_8 + 0x2C0) + 1);
                temp_11_3 = *(s8 *)(temp_11_2 + 9);
                if (temp_11_3 == 0x64) {
                    *(s8 *)(temp_7_2 + 0x2C4) = 1;
                } else if ((s16)var_18 < temp_11_3) {
                    var_17 = (s8)var_6;
                    var_18 = (s16)temp_11_3;
                }
            }
            var_6 = var_6 + 1;
        }
        if ((s16)var_18 != -1) {
            *(s8 *)((s8)var_17 + temp_4_5 + temp_16 + 0x2C4) = 1;
        }
    }
}
#pragma pop
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313d20);
#endif
// FUN_00313FB0
s32 func_00313fb0(u8 *arg0)
{
    s32 temp;

    temp = func_0010c750(arg0, (arg0[4] + 1) & 0xFFFF);
    return temp - func_0010c750(arg0, arg0[4]);
}
 
/* measured: corrected all six callee declarations from the verified definitions. */
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
extern void func_0011b9f0(int task, u32 value);
extern s32 func_0011ba00(u8 *arg0);
extern void func_0011bb90(u8 *arg0);
extern void func_0011bc70(u8 *arg0);
extern u8 func_0011d0c0(u8 *arg0);
// FUN_00314010
s32 func_00314010(u8 *arg0) {
    extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
    s32 temp_5;
    s8 temp_2;
    u8 *temp_16;
    s8 arg3;
    u32 arg2;
    s32 task_int;
    u8 *task;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s8 *)(temp_16 + 0);
    switch (temp_2) {
    case 0:
        arg3 = *(s8 *)(temp_16 + 0xC);
        arg2 = *(u32 *)(temp_16 + 8);
        task_int = 0;
        task = *(u8 **)(temp_16 + 4);
        func_0011b480(task, task_int, arg2, arg3);
        func_0011b9f0((int)*(u8 **)(temp_16 + 4), 0);
        *(s8 *)(temp_16 + 0) = 1;
        /* fallthrough */
    case 1:
        if ((func_0011d0c0(*(u8 **)(temp_16 + 4)) & 0xFF) == 0xFF) {
            *(s8 *)(temp_16 + 0) = 5;
        } else if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            func_0011bb90(*(u8 **)(temp_16 + 4));
        } else {
            *(s8 *)(temp_16 + 0) = 2;
        }
        goto block_33;
    case 2:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            *(s8 *)(temp_16 + 0) = 5;
        }
        goto block_33;
    case 3:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            func_0011bc70(*(u8 **)(temp_16 + 4));
        } else {
            *(s8 *)(temp_16 + 0) = 4;
        }
        goto block_33;
    case 4:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            *(s8 *)(temp_16 + 0) = 6;
        }
        goto block_33;
    case 8:
        func_0011b480(*(u8 **)(temp_16 + 4), 0, *(u32 *)(temp_16 + 8), *(s8 *)(temp_16 + 0xC));
        temp_5 = *(s32 *)(temp_16 + 0x10);
        if (temp_5 != 0) {
            func_0011b9f0((int)*(u8 **)(temp_16 + 4), temp_5);
        }
        *(s8 *)(temp_16 + 0) = 9;
        /* fallthrough */
    case 9:
        if ((func_0011d0c0(*(u8 **)(temp_16 + 4)) & 0xFF) == 0xFF) {
            *(s8 *)(temp_16 + 0) = 0xD;
        } else if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            func_0011bb90(*(u8 **)(temp_16 + 4));
        } else {
            *(s8 *)(temp_16 + 0) = 0xA;
        }
        goto block_33;
    case 10:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            *(s8 *)(temp_16 + 0) = 0xD;
        }
        goto block_33;
    case 11:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            func_0011bc70(*(u8 **)(temp_16 + 4));
        } else {
            *(s8 *)(temp_16 + 0) = 0xC;
        }
        goto block_33;
    case 12:
        if (func_0011ba00(*(u8 **)(temp_16 + 4)) != 1) {
            *(s8 *)(temp_16 + 0) = 0xE;
        }
        goto block_33;
    case 15:
        if (func_0011ba00((u8 *)*(s32 *)(temp_16 + 4)) != 1) {
            return -1;
        }
        goto block_33;
    case 16:
        return -1;
    default:
block_33:
        return 0;
    }
}
// FUN_003142F0
void func_003142f0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

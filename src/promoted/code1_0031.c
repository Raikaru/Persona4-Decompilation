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
extern s32 datGetFlag(s32 arg0);
extern s32 func_00106600(s16 id);
extern u16 func_00107ac0(u16 arg0);
extern u8 D_006432B0[];
extern u8 func_002e78a0(void);
extern s32 func_002e78e0(void);
extern void func_002e7920(s32 *month, s32 *day);
extern void func_00313d20(u8 *arg0, u8 month, s32 day, s8 mode);

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
/* MATCH.  Two levers, both measured on 2026-09-18:
   1. The float-to-unsigned conversion temporary is allocated out of the CSE
      table, so `optimization_level 1` / `opt_common_subs off` compile
      `(u8)temp_f1` to `cvt.w.s $f1, $f1` while retail has `cvt.w.s $f0, $f1`.
      Plain -O2 (levels 2 and 3) writes the fresh register; the pragma that
      used to sit here was the cause of the last five words, not a crutch for
      them.  Isolated with tools/micro_codegen.py on a five-line snippet.
   2. At plain -O2 b210 folded the three `func_00107ac0` argument masks into a
      ninth saved register where retail rematerialises `andi $a0, $s5, 0xffff`
      at each call.  Declaring the callee's parameter as `u16` turns the mask
      into an argument conversion instead of a common subexpression, and an
      argument conversion is re-emitted at every call site.  `arg0` is `s32`
      here so that the raw value, not the masked one, is what lives in $s5 -
      exactly retail's saved-register assignment.
   Retail review confirms the low u16 community ID, the input-only persona
   pointer, the low-s8 scaling flag and the full s32 result. */
// FUN_00311930
s32 func_00311930(s32 arg0, u8 *arg1, s8 arg2)
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
    temp_f1 = D_00749500[func_00107ac0(arg0)];
    temp_19 = (u8)temp_f1;
    temp_f1_2 = D_00749500[func_00107ac0(arg0)];
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
    return (s32)((f32)var_18 * D_007494D0[func_00107ac0(arg0)]);
}
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
        if (datGetFlag(*(s32 *)temp_4) == 0) {
            result = 0;
            goto done;
        }
    } else {
        if ((temp_3 & 2) == 0) {
            goto block_8;
        }
        var_17 = 0;
        if (datGetFlag(*(s32 *)temp_4) == 1) {
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
/* Callers pass a signed-halfword selector and narrow the returned word themselves. */
// FUN_00313690
s32 func_00313690(s16 arg0)
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
            result = datGetFlag(0x1DD) != 0;
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
s32 func_003139d0(s8 arg0, s8 arg1)
{
    s32 i;
    s32 start;
    s64 limit;
    s32 result;

    i = 0;
    start = arg1 + 1;
    limit = arg0;
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
s32 func_00313a80(s8 arg0, s8 arg1)
{
    return func_0010ac10(*(u16 *)(*(u8 **)((u8 *)D_00642EF0 + (arg0 * 8)) + (arg1 * 0x20))) != 0;
}
/* Slot of the given item in a kind's six-entry table (0 when absent).  The
   id is widened once on entry, as retail does before the table walk. */
// FUN_00313AE0
s8 func_00313ae0(s8 arg0, u16 arg1)
{
    s32 i;
    s32 id;
    u8 **table;

    i = 0;
    id = arg1;
    table = (u8 **)((u8 *)D_00642F00 + arg0 * 8);
    for (; i < 6; i++) {
        if (!func_0031_ne(*(u16 *)(table[-4] + i * 0x20), id)) {
            return i;
        }
    }
    return 0;
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
    day = (u8)func_002e78e0() + 1;
    func_002e7920(&month, &day);
    *(s8 *)(work + 0x2D5) = findDateEntry((u8)month, (u8)day);
    func_00313d20(arg0, (u8)month, (u8)day, 1);
    *(u8 *)(work + 0x2D2) = month;
    *(u8 *)(work + 0x2D3) = day;
    *(u8 *)(work + 0x2D6) = 0;
}
#pragma pop
/* Select the highest-priority enabled date entry, retaining mandatory
 * priority-100 entries and the retail repeated count-flag reads.
 * The calendar branch consumes the low day byte; the explicit-date
 * branch reuses that parameter as its signed-halfword loop index. */
typedef struct DateSelectionWork {
    u8 beforeCounts[0x2C0];
    s16 counts[2];
    u8 selectedFlags[2][5];
    u8 beforeDate[4];
    u8 nextMonth;
    u8 nextDay;
    s8 slots[2];
    u8 nextSelection;
    u8 padding;
} DateSelectionWork;
// FUN_00313D20
#pragma push
#pragma opt_loop_invariants on
void func_00313d20(u8 *task, u8 month, s32 day, s8 mode)
{
    extern s64 func_00110a60(s32 month, s32 day);
    extern u8 D_00643D00[];
    s16 best;
    DateSelectionWork *state;
    s8 selected;
    s32 savedMode;
    s8 slot;

    state = *(DateSelectionWork **)(task + 0x38);
    best = -1;
    savedMode = mode;
    slot = state->slots[mode];
    if (slot == -1) {
        u8 *fallback;
        s16 i;
        u8 *entry;
        s8 priority;
        fallback = D_00643D00 + 20 * (s8)func_00110a60(month, (u8)day);
        for (i = 0; i < 5; i++) {
            state->selectedFlags[savedMode][i] = 0;
            entry = fallback + 4 * i;
            if (*(s8 *)entry != 0) {
                priority = *((s8 *)entry + 1);
                if (best < priority) {
                    selected = i;
                    best = priority;
                }
            }
        }
        if (best != -1) state->selectedFlags[savedMode][selected] = 1;
    } else {
        u8 *date;
        s16 j;
        u8 *flag;
        u8 *entry;
        s8 priority;
        date = D_006432B0 + 28 * slot;
        state->counts[mode] = 0;
        /* Retail tests this same flag three times; the date pointer stays fixed. */
        for (j = 0; j < 3; j++) {
            if (*((s8 *)date + 2) != 0) ++state->counts[mode];
        }
        /* The calendar path consumes day; this branch reuses it as an index. */
        day = 0;
        while ((s16)day < 5) {
            flag = &state->selectedFlags[(u32)mode][(s16)day];
            *flag = 0;
            entry = date + 4 * (s16)day;
            if (*((s8 *)entry + 8) != 0) {
                ++state->counts[mode];
                priority = *((s8 *)entry + 9);
                if (priority == 100) *flag = 1;
                else if (best < priority) {
                    selected = day;
                    best = priority;
                }
            }
            day = (s16)(day + 1);
        }
        if (best != -1) state->selectedFlags[(u32)mode][selected] = 1;
    }
}
#pragma pop
// FUN_00313FB0
s32 func_00313fb0(u8 *arg0)
{
    s32 temp;

    temp = func_0010c750(arg0, (arg0[4] + 1) & 0xFFFF);
    return temp - func_0010c750(arg0, arg0[4]);
}
 
/* measured: corrected all six callee declarations from the verified definitions. */
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
extern void func_0011b9f0(int task, u32 value);
extern s32 func_0011ba00(u8 *arg0);
extern void func_0011bb90(u8 *arg0);
extern void func_0011bc70(u8 *arg0);
extern u8 func_0011d0c0(u8 *arg0);
// FUN_00314010
s32 func_00314010(u8 *arg0) {
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

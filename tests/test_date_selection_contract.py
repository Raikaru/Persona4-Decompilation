"""Run the real date selector, getters and caller against controlled providers.

The fixture extracts C from this checkout on every run. It changes no recovered
statement, type, or function signature; only target compiler pragmas are omitted.
Native pointer storage occupies the task's observed pointer slot at +0x38.
An independent byte-image oracle checks all other state and table bytes. Native
tests establish ordinary C behavior, not MIPS instruction identity or calendar
provider internals. Those are separate target-verifier and provider contracts.
"""
from __future__ import annotations

import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
SELECTOR_OWNER = "src/promoted/code1_0031.c"
GETTER_OWNER = "src/promoted/code1_002e.c"
GETTER = "func_002e78e0"

TYPES = r'''
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Import the repository scalar types. Keep its EE pointer/size aliases
   separate from host libc's aliases; extracted date functions use neither. */
#undef NULL
#define intptr_t DateFixtureTargetIntptr
#define uintptr_t DateFixtureTargetUintptr
#define size_t DateFixtureTargetSize
#include "type.h"
#undef size_t
#undef uintptr_t
#undef intptr_t
_Static_assert(sizeof(u8) == 1 && sizeof(s8) == 1, "byte widths");
_Static_assert(sizeof(u16) == 2 && sizeof(s16) == 2, "halfword widths");
_Static_assert(sizeof(u32) == 4 && sizeof(s32) == 4 && sizeof(s64) == 8, "word widths");
static unsigned scenarios;
#define CHECK(x) do { if (!(x)) { fprintf(stderr, "line %d, scenario %u: %s\n", __LINE__, scenarios, #x); exit(1); } } while (0)
'''

PROVIDERS = r'''
static u8 D_006432B0[128 * 28], D_00643D00[7 * 20];
static s32 decoder_month, decoder_day;
static s16 decoder_id;
static int leap_year, forced_weekday;
static int advance_month, advance_day, poison_advance;
static unsigned id_calls, decoder_calls, weekday_calls, advance_calls;
static s32 weekday_month[8], weekday_day[8];
static const int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
static int days_in_month(int month) {
    CHECK(month >= 1 && month <= 12);
    return month_days[month - 1] + (leap_year && month == 2);
}
static void next_date(int month, int day, int *next_month, int *next_day) {
    CHECK(day >= 1 && day <= days_in_month(month));
    if (day < days_in_month(month)) { *next_month = month; *next_day = day + 1; }
    else { *next_month = month == 12 ? 1 : month + 1; *next_day = 1; }
}
/* A deterministic controlled provider, not a reconstruction of the calendar. */
static int weekday_for(int month, int day) {
    int ordinal = day;
    CHECK(day >= 1 && day <= days_in_month(month));
    for (int m = 1; m < month; ++m) ordinal += days_in_month(m);
    return ordinal % 7;
}
s16 func_001060b0(void) { ++id_calls; return decoder_id; }
void func_001104d0(s64 id, s32 *month, s32 *day) {
    CHECK(id == decoder_id && month != day);
    ++decoder_calls;
    *month = decoder_month; *day = decoder_day;
}
s64 func_00110a60(s32 month, s32 day) {
    int weekday;
    CHECK(weekday_calls < 8 && month >= 0 && month <= 255 && day >= 0 && day <= 255);
    weekday_month[weekday_calls] = month;
    weekday_day[weekday_calls++] = day;
    weekday = forced_weekday >= 0 ? forced_weekday : weekday_for(month, day);
    /* Only the signed low-byte result is part of this selector's input. */
    return INT64_C(0x123400) + weekday;
}
void func_002e7920(s32 *month, s32 *day) {
    int m, d;
    CHECK(*month == advance_month && *day == advance_day + 1);
    ++advance_calls;
    next_date(advance_month, advance_day, &m, &d);
    /* The caller deliberately consumes byte views of these complete outputs. */
    *month = m + (poison_advance ? 0x123400 : 0);
    *day = d + (poison_advance ? 0x654300 : 0);
}
static void reset_observations(void) {
    id_calls = decoder_calls = weekday_calls = advance_calls = 0;
    memset(weekday_month, 0, sizeof weekday_month);
    memset(weekday_day, 0, sizeof weekday_day);
}
'''

BEHAVIOR = r'''
typedef struct { u8 before[16]; DateSelectionWork work; u8 after[16]; } GuardedState;
typedef struct { u8 before[0x38]; u8 *work; u8 after[32]; } Task;
_Static_assert(offsetof(Task, work) == 0x38, "native task pointer slot");
_Static_assert(offsetof(DateSelectionWork, counts) == 0x2C0, "count offset");
_Static_assert(offsetof(DateSelectionWork, selectedFlags) == 0x2C4, "flag offset");
_Static_assert(offsetof(DateSelectionWork, slots) == 0x2D4, "slot offset");
_Static_assert(sizeof(DateSelectionWork) == 0x2D8, "observed state extent");
static unsigned selector_cases, getter_cases, lookup_cases, caller_cases;
static u8 saved_dates[sizeof D_006432B0], saved_weekdays[sizeof D_00643D00];
static const u32 upper_patterns[8] = {
    0, 0x100, 0x7F00, 0xFFFF00, 0x12345600, 0x7FFFFF00, 0x80000000, 0xFFFFFF00
};
static const s16 id_patterns[4] = {-32768, -1, 0, 32767};
static const int priorities[14][5] = {
    {-128,-128,-128,-128,-128}, {-1,-1,-1,-1,-1}, {0,0,0,0,0},
    {99,99,99,99,99}, {100,100,100,100,100}, {127,127,127,127,127},
    {-128,-1,0,100,127}, {127,100,0,-1,-128}, {99,100,99,100,99},
    {100,99,100,99,100}, {1,2,3,4,5}, {5,4,3,2,1},
    {-2,0,-1,0,-128}, {101,100,126,127,127}
};
static const u8 nonzero_ids[5] = {1,128,255,127,85};
static int signed_byte(u8 byte) { return byte < 128 ? byte : (int)byte - 256; }
static s32 signed_word(u32 word) { s32 result; memcpy(&result, &word, sizeof result); return result; }
static void initialize_state(GuardedState *state, Task *task, unsigned seed) {
    u8 *bytes = (u8 *)state;
    for (unsigned n = 0; n < sizeof *state; ++n) bytes[n] = (u8)(seed + n * 37);
    state->work.counts[0] = 32767;
    state->work.counts[1] = -32768;
    memset(task, 0xA6, sizeof *task);
    task->work = (u8 *)&state->work;
    reset_observations();
}
static void save_tables(void) {
    memcpy(saved_dates, D_006432B0, sizeof saved_dates);
    memcpy(saved_weekdays, D_00643D00, sizeof saved_weekdays);
}
static void check_images(const GuardedState *got, const GuardedState *want,
                         const Task *task, const Task *old_task) {
    CHECK(memcmp(got, want, sizeof *got) == 0);
    CHECK(memcmp(task, old_task, sizeof *task) == 0);
    CHECK(memcmp(saved_dates, D_006432B0, sizeof saved_dates) == 0);
    CHECK(memcmp(saved_weekdays, D_00643D00, sizeof saved_weekdays) == 0);
}
static void fill_entries(u8 *entries, unsigned active, const int scores[5]) {
    for (int n = 0; n < 5; ++n) {
        entries[n * 4] = active & (1u << n) ? nonzero_ids[n] : 0;
        entries[n * 4 + 1] = (u8)scores[n];
        entries[n * 4 + 2] = (u8)(0xF0 + n);
        entries[n * 4 + 3] = (u8)(0xA0 + n);
    }
}
/* Compute membership independently: a winner has no higher-priority entry,
   and no equally ranked earlier entry. Header counting is a threefold
   contribution from byte +2; bytes +3 and +4 are deliberately contradictory. */
static void model_selection(GuardedState *state, int mode, int slot, int weekday) {
    const u8 *date = slot < 0 ? NULL : D_006432B0 + slot * 28;
    const u8 *entries = date ? date + 8 : D_00643D00 + weekday * 20;
    u8 *bytes = (u8 *)&state->work;
    u8 *flags = bytes + 0x2C4 + mode * 5;
    int count = date && date[2] != 0 ? 3 : 0;
    memset(flags, 0, 5);
    for (int i = 0; i < 5; ++i) {
        int score = signed_byte(entries[i * 4 + 1]);
        int winner = score >= 0;
        if (!entries[i * 4]) continue;
        ++count;
        if (date && score == 100) { flags[i] = 1; continue; }
        for (int j = 0; j < 5; ++j) {
            int other = signed_byte(entries[j * 4 + 1]);
            if (!entries[j * 4] || (date && other == 100)) continue;
            if (other > score || (other == score && j < i)) winner = 0;
        }
        flags[i] = (u8)winner;
    }
    if (date) {
        s16 value = (s16)count;
        memcpy(bytes + 0x2C0 + mode * 2, &value, sizeof value);
    }
}
static void selector_case(int mode, int slot, unsigned active, int header,
                          const int scores[5], u8 month, s32 day, int weekday) {
    GuardedState got, want;
    Task task, old_task;
    initialize_state(&got, &task, scenarios);
    got.work.slots[mode] = (s8)slot;
    memcpy(&want, &got, sizeof want); memcpy(&old_task, &task, sizeof task);
    memset(D_006432B0, 0xB6, sizeof D_006432B0);
    memset(D_00643D00, 0, sizeof D_00643D00);
    if (slot >= 0) {
        u8 *date = D_006432B0 + slot * 28;
        date[2] = (u8)header;
        date[3] = date[4] = header ? 0 : 1;
        fill_entries(date + 8, active, scores);
    } else fill_entries(D_00643D00 + weekday * 20, active, scores);
    forced_weekday = weekday;
    model_selection(&want, mode, slot, weekday);
    save_tables();
    func_00313d20((u8 *)&task, month, day, (s8)mode);
    check_images(&got, &want, &task, &old_task);
    CHECK(id_calls == 0 && decoder_calls == 0 && advance_calls == 0);
    CHECK(weekday_calls == (unsigned)(slot == -1));
    if (slot == -1) CHECK(weekday_month[0] == month && weekday_day[0] == (u8)day);
    ++selector_cases; ++scenarios;
}
static void test_selector(void) {
    const int slots[4] = {-1,0,3,126}, headers[4] = {0,1,128,255};
    for (int mode = 0; mode < 2; ++mode)
    for (int s = 0; s < 4; ++s)
    for (unsigned active = 0; active < 32; ++active)
    for (int h = 0; h < 4; ++h)
    for (unsigned p = 0; p < 14; ++p)
        selector_case(mode, slots[s], active, headers[h], priorities[p],
                      (u8)(1 + p % 12), (s32)(1 + p), (int)(p % 7));
    /* Every signed priority byte, all active-entry masks, and both branches. */
    for (int mode = 0; mode < 2; ++mode)
    for (int branch = 0; branch < 2; ++branch)
    for (unsigned active = 0; active < 32; ++active)
    for (int byte = 0; byte < 256; ++byte) {
        int score = byte < 128 ? byte : byte - 256;
        int uniform[5] = {score,score,score,score,score};
        selector_case(mode, branch ? 3 : -1, active, byte, uniform, 12, 31, byte % 7);
    }
    /* Boundary probes, distinct from valid calendar dates: the selector must
       present the low day byte to the controlled weekday provider. */
    for (int mode = 0; mode < 2; ++mode)
    for (unsigned high = 0; high < 8; ++high)
    for (u32 low = 0; low < 256; ++low)
        selector_case(mode, -1, 31, 0, priorities[6], (u8)(255 - low),
                      signed_word(upper_patterns[high] | low), (int)(low % 7));
}
static void test_getter(void) {
    for (unsigned id = 0; id < 4; ++id)
    for (unsigned high = 0; high < 8; ++high)
    for (u32 low = 0; low < 256; ++low) {
        s32 value;
        decoder_month = 0x76540C;
        decoder_day = signed_word(upper_patterns[high] | low);
        decoder_id = id_patterns[id]; reset_observations();
        value = func_002e78e0();
        CHECK(value >= 0 && value <= 255 && value == (s32)low);
        CHECK(id_calls == 1 && decoder_calls == 1 && weekday_calls == 0 && advance_calls == 0);
        ++getter_cases; ++scenarios;
    }
}
static void set_date(unsigned row, int month, int day) {
    CHECK(row < 128);
    D_006432B0[row * 28] = (u8)month;
    D_006432B0[row * 28 + 1] = (u8)day;
}
static void test_lookup(void) {
    const int indices[3] = {3,63,126};
    for (leap_year = 0; leap_year < 2; ++leap_year)
    for (int month = 1; month <= 12; ++month)
    for (int day = 1; day <= days_in_month(month); ++day) {
        for (int n = 0; n < 4; ++n) {
            int index = n < 3 ? indices[n] : -1;
            memset(D_006432B0, 0, sizeof D_006432B0);
            set_date(0, month, day); /* The scan starts at row one. */
            set_date(1, -1, day); set_date(2, month, -1);
            if (index >= 0) {
                set_date((unsigned)index, month, day);
                if (index < 126) set_date((unsigned)index + 1, month, day);
                set_date(127, -1, -1);
            } else {
                set_date(3, -1, -1); set_date(4, month, day);
            }
            save_tables();
            CHECK(findDateEntry((u8)month, (u8)day) == index);
            CHECK(memcmp(saved_dates, D_006432B0, sizeof saved_dates) == 0);
            ++lookup_cases; ++scenarios;
        }
    }
}
static void test_caller(void) {
    for (leap_year = 0; leap_year < 2; ++leap_year)
    for (int month = 1; month <= 12; ++month)
    for (int day = 1; day <= days_in_month(month); ++day)
    for (int missing = 0; missing < 4; ++missing)
    for (int poison = 0; poison < 2; ++poison) {
        GuardedState got, want;
        Task task, old_task;
        int next_month, next_day, today_slot = missing & 1 ? -1 : 3;
        int tomorrow_slot = missing & 2 ? -1 : 4;
        unsigned log = 0;
        next_date(month, day, &next_month, &next_day);
        initialize_state(&got, &task, scenarios);
        memcpy(&want, &got, sizeof want); memcpy(&old_task, &task, sizeof task);
        memset(D_006432B0, 0, sizeof D_006432B0);
        memset(D_00643D00, 0, sizeof D_00643D00);
        for (int w = 0; w < 7; ++w)
            fill_entries(D_00643D00 + w * 20, (unsigned)(13 + w), priorities[w + 6]);
        fill_entries(D_006432B0 + 3 * 28 + 8, 29, priorities[9]);
        fill_entries(D_006432B0 + 4 * 28 + 8, 23, priorities[13]);
        D_006432B0[3 * 28 + 2] = 128;
        D_006432B0[3 * 28 + 3] = D_006432B0[3 * 28 + 4] = 0;
        D_006432B0[4 * 28 + 2] = 0;
        D_006432B0[4 * 28 + 3] = D_006432B0[4 * 28 + 4] = 1;
        set_date(0, month, day); set_date(1, -1, day); set_date(2, month, -1);
        if (today_slot >= 0) { set_date(3, month, day); set_date(5, month, day); }
        if (tomorrow_slot >= 0) set_date(4, next_month, next_day);
        set_date(6, -1, -1); set_date(7, month, day); set_date(8, next_month, next_day);
        want.work.slots[0] = (s8)today_slot; want.work.slots[1] = (s8)tomorrow_slot;
        model_selection(&want, 0, today_slot, weekday_for(month, day));
        model_selection(&want, 1, tomorrow_slot, weekday_for(next_month, next_day));
        want.work.nextMonth = (u8)next_month; want.work.nextDay = (u8)next_day;
        want.work.nextSelection = 0;
        decoder_id = -123;
        decoder_month = month + (poison ? 0x123400 : 0);
        decoder_day = day + (poison ? 0x654300 : 0);
        advance_month = month; advance_day = day; poison_advance = poison; forced_weekday = -1;
        save_tables();
        func_00313b50((u8 *)&task);
        check_images(&got, &want, &task, &old_task);
        CHECK(id_calls == 6 && decoder_calls == 6 && advance_calls == 1);
        if (missing & 1) {
            CHECK(weekday_month[log] == month && weekday_day[log] == day); ++log;
        }
        if (missing & 2) {
            CHECK(weekday_month[log] == next_month && weekday_day[log] == next_day); ++log;
        }
        CHECK(weekday_calls == log);
        ++caller_cases; ++scenarios;
    }
}
int main(void) {
    test_getter(); test_selector(); test_lookup(); test_caller();
    printf("{\"getter\":%u,\"selector\":%u,\"lookup\":%u,\"caller\":%u,\"total\":%u}\n",
           getter_cases, selector_cases, lookup_cases, caller_cases, scenarios);
    return 0;
}
'''


def without_comments(source: str) -> str:
    """Preserve offsets/newlines so every audit record points into the real file."""
    return re.sub(r"""/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'""",
                  lambda m: re.sub(r"[^\n]", " ", m.group()), source, flags=re.S)


def extract_function(source: str, name: str) -> str:
    code = without_comments(source)
    match = re.search(r"(?m)^(?:static\s+inline\s+)?\w+\s+" + re.escape(name)
                      + r"\s*\([^;{}]*\)\s*\{", code)
    if match is None:
        raise AssertionError(f"Missing C definition: {name}")
    start, depth = code.index("{", match.start()), 1
    end = start + 1
    while depth and end < len(code):
        depth += (code[end] == "{") - (code[end] == "}")
        end += 1
    if depth:
        raise AssertionError(f"Unclosed C definition: {name}")
    result = source[match.start():end]
    if "INCLUDE_ASM" in result:
        raise AssertionError(f"Assembly fallback is not a runtime C fixture: {name}")
    return re.sub(r"(?m)^#pragma[^\n]*\n", "", result) + "\n"


def behavior_source(selector: str | None = None, getter: str | None = None) -> str:
    selector = selector if selector is not None else (ROOT / SELECTOR_OWNER).read_text(encoding="utf-8")
    getter = getter if getter is not None else (ROOT / GETTER_OWNER).read_text(encoding="utf-8")
    struct = re.search(r"typedef struct DateSelectionWork\s*\{.*?\}\s*DateSelectionWork;", selector, re.S)
    if struct is None:
        raise AssertionError("Missing actual DateSelectionWork definition")
    declarations = []
    for name in ("func_002e78a0", GETTER, "func_002e7920", "func_00313d20"):
        declaration = re.search(r"(?m)^extern[^\n]*\b" + name + r"\([^;]*;", selector)
        if declaration is None:
            raise AssertionError(f"Missing actual declaration: {name}")
        declarations.append(declaration.group())
    return (TYPES + PROVIDERS + "\n".join(declarations) + "\n" + struct.group() + "\n"
            + extract_function(getter, "func_002e78a0") + extract_function(getter, GETTER)
            + extract_function(selector, "findDateEntry")
            + extract_function(selector, "func_00313d20")
            + extract_function(selector, "func_00313b50") + BEHAVIOR)


def getter_consumers() -> tuple[list[dict], list[dict]]:
    """Account for every non-generated getter reference, including guarded C.

    Each ordinary consumer retains either an explicit low-byte view or a byte
    local. The only raw forwarding site is the selector's proven s32 interface.
    Unknown uses fail with a source location rather than silently losing coverage.
    """
    uses, declarations = [], []
    for path in sorted((ROOT / "src").rglob("*.c")):
        if "generated" in path.relative_to(ROOT / "src").parts:
            continue
        source = path.read_text(encoding="utf-8")
        code = without_comments(source)
        for token in re.finditer(r"\b" + GETTER + r"\b", code):
            start = token.start()
            tail = re.match(r"\s*\(\s*(?:void\s*)?\)", code[token.end():])
            line = source.count("\n", 0, start) + 1
            location = f"{path.relative_to(ROOT).as_posix()}:{line}"
            if tail is None:
                raise AssertionError(f"Unclassified getter reference at {location}")
            end = token.end() + tail.end()
            line_start = code.rfind("\n", 0, start) + 1
            before = code[line_start:start]
            if re.fullmatch(r"\s*(?:extern\s+)?s32\s+", before):
                declarations.append(dict(path=path.relative_to(ROOT).as_posix(), line=line,
                                         declaration=source[line_start:end].strip()))
                continue
            if re.search(r"\b(?:extern|u8|s8|u16|s16|s64|u32|u64)\s+$", before):
                raise AssertionError(f"Inconsistent getter declaration at {location}")
            expression = source[start:end]
            kind, statement = None, None
            cast = re.search(r"\(u8\)\s*$", code[:start])
            mask = re.match(r"\s*&\s*0x[Ff][Ff]\b", code[end:])
            local = re.search(r"\b(?:u8\s+)?(current_day|d1)\s*=\s*$", before)
            if cast:
                kind, expression = "explicit-byte-cast", source[cast.start():end]
            elif mask:
                kind, expression = "explicit-byte-mask", source[start:end + mask.end()]
            elif local:
                name = local.group(1)
                if re.search(r"\bu8\s+" + name + r"\b", code[:start]) is None:
                    raise AssertionError(f"Byte local not declared at {location}")
                kind = "byte-local"
                # Preserve the exact assignment while declaring its proven type.
                assignment = source[line_start:end].strip()
                if assignment.startswith("u8 "):
                    statement = assignment + ";"
                else:
                    statement = f"u8 {name};\n{assignment};"
                expression = name
            elif path.relative_to(ROOT).as_posix() == SELECTOR_OWNER:
                line_end = source.find("\n", end)
                call = source[line_start:line_end].strip()
                if call == "func_00313d20(arg0, func_002e78a0(), func_002e78e0(), 0);":
                    if "extern void func_00313d20(u8 *arg0, u8 month, s32 day, s8 mode);" not in source:
                        raise AssertionError("Raw getter forwarding requires the actual s32 selector declaration")
                    kind = "range-proven-s32-forwarding"
            if kind is None:
                raise AssertionError(f"Unclassified getter consumer at {location}: {source[line_start:end]}")
            markers = list(re.finditer(r"(?m)^// FUN_([0-9A-F]{8})([^\n]*)", source[:start]))
            uses.append(dict(path=path.relative_to(ROOT).as_posix(), line=line, kind=kind,
                             function=markers[-1].group(1) if markers else None,
                             guarded=bool(markers and "NONMATCHING" in markers[-1].group(2)),
                             expression=expression, statement=statement))
    if not uses or not declarations:
        raise AssertionError("Empty getter consumer audit")
    return uses, declarations


def consumer_source(uses: list[dict]) -> str:
    """Execute exact byte-view expressions; injected high bits test the views.

    The high-bit inputs deliberately exceed the real getter's proven range.
    They check byte conversions independently; the real getter is tested above.
    """
    parts = [TYPES, "static s32 injected_day;\ns32 func_002e78e0(void) { return injected_day; }\n"]
    for index, use in enumerate(uses):
        statement = use["statement"] or ""
        parts.append(f"static s32 consumer_{index}(void) {{ {statement}\nreturn {use['expression']}; }}\n")
    parts.append("int main(void) {\nconst s32 extremes[] = {INT32_MIN,-257,-256,-1,256,257,INT32_MAX};\n")
    parts.append("for (int n = 0; n < 263; ++n) { injected_day = n < 256 ? n : extremes[n - 256];\n")
    for index, use in enumerate(uses):
        expected = "injected_day" if use["kind"] == "range-proven-s32-forwarding" else "(s32)((u32)injected_day & 255)"
        parts.append(f"CHECK(consumer_{index}() == {expected}); ++scenarios;\n")
    parts.append(r'''}
printf("{\"consumer_views\":%u}\n", scenarios);
return 0;
}
''')
    return "".join(parts)


def compile_fixture(compiler: str, source: str, directory: Path, label: str, level: str) -> Path:
    fixture = directory / (label + ".c")
    executable = directory / (label + (".exe" if os.name == "nt" else ""))
    fixture.write_text(source, encoding="utf-8")
    command = [compiler, "-std=c11", "-I", str(ROOT / "include"), level, "-fno-strict-aliasing", "-ffp-contract=off",
               "-fsanitize=undefined", "-fsanitize-undefined-trap-on-error",
               "-Werror=implicit-function-declaration", "-Werror=incompatible-pointer-types",
               "-Werror=int-conversion", str(fixture), "-o", str(executable)]
    compiled = subprocess.run(command, capture_output=True, text=True, timeout=60)
    if compiled.returncode:
        raise AssertionError("Native fixture compile failed:\n" + compiled.stdout + compiled.stderr)
    return executable


class DateSelectionContractTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.compiler = shutil.which("clang")
        if cls.compiler is None:
            raise unittest.SkipTest("native Clang is required for the date-selection fixture")

    def run_fixture(self, source: str, expected: dict, label: str) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_date_contract_") as temporary:
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = compile_fixture(self.compiler, source, Path(temporary), label + level, level)
                    ran = subprocess.run([str(executable)], capture_output=True, text=True, timeout=30)
                    self.assertEqual(ran.returncode, 0, ran.stdout + ran.stderr)
                    self.assertEqual(json.loads(ran.stdout), expected)
                    print(label, level, ran.stdout.strip())

    def test_actual_selector_getters_lookup_and_caller(self) -> None:
        self.run_fixture(behavior_source(), dict(getter=8192, selector=51200, lookup=2924,
                                                caller=5848, total=68164), "actual-date")

    def test_consumer_extraction_respects_c_character_literals(self) -> None:
        source = r'''s32 sample(void) {
    char quote = '"'; char slash = '\\'; char brace = '}';
    const char *ignored = "func_002e78e0()";
    /* func_002e78e0(); } */
    return func_002e78e0();
}
'''
        stripped = without_comments(source)
        self.assertEqual(len(stripped), len(source))
        self.assertEqual(stripped.count(GETTER), 1)
        self.assertIn("return func_002e78e0();", stripped)
        self.assertEqual(extract_function(source, "sample"), source)

    def test_all_getter_consumers_keep_their_byte_view(self) -> None:
        uses, declarations = getter_consumers()
        self.assertEqual(sum(use["kind"] == "range-proven-s32-forwarding" for use in uses), 1)
        self.assertTrue(any(use["guarded"] for use in uses))
        self.assertEqual({use["path"] for use in uses} | {row["path"] for row in declarations}, {
            SELECTOR_OWNER, GETTER_OWNER, "src/promoted/code1_002b.c", "src/promoted/code1_0033.c",
            "src/Event/Fcl/y_fclCombine.c", "src/Event/Fcl/y_fclCombineDraw.c",
            "src/Event/Fcl/y_fclItemShopDraw.c", "src/Event/Fcl/y_fclShopDraw.c",
            "src/Event/Fcl/y_fclTalk.c"})
        self.run_fixture(consumer_source(uses), dict(consumer_views=263 * len(uses)), "getter-consumers")

    def test_behavior_fixture_rejects_meaningful_regressions(self) -> None:
        selector = (ROOT / SELECTOR_OWNER).read_text(encoding="utf-8")
        getter = (ROOT / GETTER_OWNER).read_text(encoding="utf-8")
        changes = [
            ("retain-old-count", "selector", "        state->counts[mode] = 0;", "        ;", 1),
            ("advance-header-pointer", "selector", "*((s8 *)date + 2)", "*((s8 *)date + 2 + j)", 1),
            ("two-header-contributions", "selector", "j < 3", "j < 2", 1),
            ("last-winner-ties", "selector", "best < priority", "best <= priority", 2),
            ("unsigned-priorities", "selector", "        s8 priority;", "        u8 priority;", 2),
            ("wrong-forced-priority", "selector", "priority == 100", "priority == 99", 1),
            ("unmasked-selector-day", "selector", "func_00110a60(month, (u8)day)", "func_00110a60(month, day)", 1),
            ("half-sentinel-terminates", "selector", "*(s8 *)entry == -1 &&", "*(s8 *)entry == -1 ||", 1),
            ("uncleared-flags", "selector", "            *flag = 0;", "            ;", 1),
            ("unmasked-getter-return", "getter", "    return (u8)sp1C;", "    return sp1C;", 1),
        ]
        with tempfile.TemporaryDirectory(prefix="p4_date_mutations_") as temporary:
            for label, owner, old, new, occurrences in changes:
                original = selector if owner == "selector" else getter
                self.assertEqual(original.count(old), occurrences, label)
                mutated = original.replace(old, new)
                source = behavior_source(mutated, getter) if owner == "selector" else behavior_source(selector, mutated)
                for level in ("-O0", "-O2"):
                    with self.subTest(mutation=label, optimization=level):
                        executable = compile_fixture(self.compiler, source, Path(temporary), label + level, level)
                        ran = subprocess.run([str(executable)], capture_output=True, text=True, timeout=30)
                        self.assertNotEqual(ran.returncode, 0, f"Fixture accepted {label} at {level}")
                        self.assertIn("scenario", ran.stderr, "Mutation must fail a behavioral assertion, not merely crash")
                        print("rejected", label, level, ran.stderr.strip())


if __name__ == "__main__":
    unittest.main()

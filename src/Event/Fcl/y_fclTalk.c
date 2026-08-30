#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclTalk.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern char D_0064A000[];
extern char D_0064A018[];
extern char D_0064A030[];
extern char D_0064A050[];
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                         void *arg5, void *arg6, u8 *arg7);
extern s8 func_002bab80(void *);
extern void func_002badc0(s8, s32);
extern void func_002bbd80(s8, s32, void *);
extern void *func_001067f0(s16);
extern void func_00275980(void *, void *, s32);
extern s32 func_00106330(s32);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_002be100(u8);
extern s32 func_002bb680(s8);
extern void func_002bbcf0(s8);
extern void func_002bb550(s8);
extern u8 D_00645240[];
extern u8 D_006450E0[];
extern u8 D_00647EE0[];
extern u32 D_0064A078[];
extern u32 D_0064A07C[];
extern u32 D_0064A080[];
extern u8 D_006450B0[];
extern s8 func_00106ac0(s16);
extern s32 func_00106b20(s16);
extern s32 func_00106b50(s16);
extern s32 func_002be160(s32, s32);
extern s32 func_002be1b0();
extern s32 func_002dfd00(u16);
extern u32 func_003b7060(void);
extern void func_00331a20();
extern void func_00331f90();
extern s32 func_00332060();
extern void func_003322a0();
extern s32 func_00332520();
extern void func_003329b0();

// FUN_00331FC0
void func_00331fc0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0xC8);
    temp_2 = D_008873F4[0](1, 2, 0x40000);
    func_00451fc0(arg0, D_0064A030, 0xF, 0, 0, (void *)func_00331a20,
                  (void *)func_00331f90, temp_2);
    *temp_2 = 0;
}
/* measured: nd 165 with a full C body (object 592B against a 576B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
// FUN_00332060
s32 func_00332060(u8 *arg0) {
    s8 *work;
    u8 *entry;
    s8 i;
    s32 level;
    s16 level_value;
    s16 min;
    s16 max;

    work = *(s8 **)(arg0 + 0x38);
    i = 0;
    level_value = (s16)(100 * (func_002be100(func_002e78a0()) & 0xFF) +
                        (func_002e78e0() & 0xFF));
    switch (*work) {
    case 0:
        goto state_zero;
    case 1:
        goto state_one;
    default:
        goto done;
    }

state_zero:
    level = level_value;
    do {
        entry = D_006450E0 + (i * 0xC);
        min = (s16)(entry[9] +
                    100 * (func_002be100(entry[8]) & 0xFF));
        max = (s16)(entry[11] +
                    100 * (func_002be100(entry[10]) & 0xFF));
        if (func_00106330(*(s32 *)(entry + 4)) != 0 ||
            *(s32 *)(entry + 4) == 0) {
            if (min > level) {
                goto scan_next;
            }
            if (max >= level) {
                work[1] = func_002bab80(D_00647EE0);
                func_002badc0(work[1], *(s16 *)entry);
                (*work)++;
                return 0;
            }
        }
scan_next:
        i++;
    } while (*(s16 *)entry != -1);
    (*work)++;
    goto done;

state_one:
    if (func_002bb680(work[1]) != 0) {
        func_002bbcf0(work[1]);
        goto done;
    }
    func_002bb550(work[1]);
    return -1;

done:
    return 0;
}
// FUN_003322A0
void func_003322a0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_003322D0
void func_003322d0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0x12D);
    temp_2 = D_008873F4[0](1, 2, 0x40000);
    func_00451fc0(arg0, D_0064A050, 0xF, 0, 0, (void *)func_00332060,
                  (void *)func_003322a0, temp_2);
    *temp_2 = 0;
}

// FUN_00332370
void func_00332370(u8 *arg0, s32 arg1, s32 arg2) {
    u8 sp40[0x20];
    s32 temp_2;
    u8 *work;
    s16 t;

    work = *(u8 **)(arg0 + 0x38);
    t = (s16)((arg2 & 0xFFF00) >> 8);
    if (arg2 == 0) {
        *(work + 1) = func_002bab80(D_00645240);
        func_002bbd80(*(work + 1), 0, func_001067f0(t));
        func_002badc0(*(work + 1), 0x1E);
        return;
    }
    *(work + 1) = func_002bab80(D_00645240);
    func_002bbd80(*(work + 1), 0, func_001067f0(t));
    temp_2 = func_002be1b0((s16)arg1);
    if (temp_2 == 0xE) {
        func_00275980((void *)D_0064A07C[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    } else if (temp_2 == 0xF) {
        func_00275980((void *)D_0064A080[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    } else {
        func_00275980((void *)D_0064A078[0], sp40, 0x20);
        func_002bbd80(*(work + 1), 1, sp40);
    }
    func_002badc0(*(work + 1), 0x1F);
}

// FUN_00332520
s32 func_00332520(u8 *arg0) {
    s8 *work;
    s32 level;
    s16 level_value;
    s8 index;
    u8 *entry;
    s32 i;
    s32 category;
    s32 selected;
    u32 offset;
    s16 min;
    s16 max;

    work = *(s8 **)(arg0 + 0x38);
    level_value = (s16)(100 * (func_002be100(func_002e78a0()) & 0xFF) +
                        (func_002e78e0() & 0xFF));
    index = 0;
    switch (*work) {
    case 0:
        goto state_zero_32520;
    case 1:
        goto state_one_32520;
    case 2:
        goto state_two_32520;
    case 3:
        goto state_three_32520;
    default:
        goto done_32520;
    }

state_zero_32520:
    level = level_value;
    do {
        entry = D_006450B0 + (index * 4);
        min = (s16)(entry[1] +
                    100 * (func_002be100(entry[0]) & 0xFF));
        max = (s16)(entry[3] +
                    100 * (func_002be100(entry[2]) & 0xFF));
        if (min > level) {
            goto state_zero_next_32520;
        }
        if (max >= level) {
            (*work)++;
            work[0x1808] = index;
            return 0;
        }
state_zero_next_32520:
        index++;
    } while (entry[0] != 0);
    return -1;

state_one_32520:
    *(s32 *)(work + 0x1804) = 0;
    for (i = 0; i < 0x600; i++) {
        *(s32 *)(work + (i * 4) + 4) = 0;
        category = func_002be1b0((s16)i);
        if (category != 0x10 && category != 0x11 && category != 0x12) {
            if (work[0x1808] == func_00106ac0((s16)i)) {
                if (func_002dfd00(
                        (u16)((func_00106b20((s16)i) & 0xFFF00) >> 8)) == 0) {
                    if (func_002be160(
                            (func_00106b20((s16)i) & 0xFFF00) >> 8,
                            func_00106b20((s16)i) & 0xFF) == 0 ||
                        func_002be160(
                            (func_00106b50((s16)i) & 0xFFF00) >> 8,
                            func_00106b50((s16)i) & 0xFF) == 0) {
                        *(s32 *)(work + (*(s32 *)(work + 0x1804) * 4) + 4) = i;
                        *(s32 *)(work + 0x1804) =
                            *(s32 *)(work + 0x1804) + 1;
                    }
                }
            }
        }
    }
    (*work)++;
    goto done_32520;

state_two_32520:
    if (*(s32 *)(work + 0x1804) == 0) {
        work[1] = func_002bab80(D_00645240);
        func_002badc0(work[1], 0x1D);
    } else {
        offset = (func_003b7060() % *(s32 *)(work + 0x1804)) * 4;
        selected = *(s32 *)(offset + (u32)work + 4);
        if (((func_00106b20((s16)selected) & 0xFFF00) >> 8) != 0x500) {
            func_00332370(arg0, selected,
                          func_00106b20((s16)selected));
        } else if (((func_00106b50((s16)selected) & 0xFFF00) >> 8) !=
                   0x500) {
            func_00332370(arg0, selected,
                          func_00106b50((s16)selected));
        }
    }
    (*work)++;
    goto done_32520;

state_three_32520:
    if (func_002bb680(work[1]) != 0) {
        func_002bbcf0(work[1]);
        goto done_32520;
    }
    func_002bb550(work[1]);
    return -1;

done_32520:
    return 0;

}
// FUN_003329B0
void func_003329b0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_003329E0
void func_003329e0(u8 *arg0) {
    u8 *temp_2;

    func_0044ea90(D_0064A018, 0x1EC);
    temp_2 = D_008873F4[0](1, 0x180C, 0x40000);
    func_00451fc0(arg0, D_0064A000, 0xF, 0, 0, (void *)func_00332520,
                  (void *)func_003329b0, temp_2);
    *temp_2 = 0;
    *(temp_2 + 0x1808) = 0;
}

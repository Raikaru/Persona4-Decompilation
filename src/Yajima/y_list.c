#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

/* gp-relative global at 0x0076467C (gp - 0x4A74): pointer to the active list. */
static u8 *iGpffffb58c;
/* Shared runtime-loaded persona records; storage is owned by cmmMisc.c. */
extern u8 *iGpffffb3d4;

extern char D_0063FC48[];
extern char D_0063FC58[];
extern u8 *D_00882F70[];
extern s32 func_00312b60(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00312b90(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);

extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern void func_0044ea90(void *msg, s32 id);
extern void func_00452080(s32 handle);


extern s32 func_002e23b0(u8 *arg0);
extern s32 func_002e2410(u8 *arg0);
extern void func_002e2470(u8 *arg0);
extern s32 func_002e4090(u8 *arg0);
extern void func_002e29a0(void);
extern s8 func_002e47b0(void);
extern void func_002e4820(s8 arg0);
extern void *memset(void *dest, s32 value, u32 size);
extern s32 func_002e6b20(const void *arg0, const void *arg1);
extern s32 func_002e6630(const void *arg0, const void *arg1);
#include "rw/std/stdlib.h"
extern u8 *func_0010fcb0(s32 arg0);
extern s32 func_0010aa80(s32 arg0);
extern u16 *func_0010ac10(s32 arg0);

extern void func_0010cad0(u8 *dest, u16 id);
extern s32 func_0010b5b0(void);
extern s32 func_0010abd0(s16 arg0);
extern u16 *func_0010ace0(s16 arg0);
extern u16 *func_0010a900(u16 arg0);
extern void func_0010ffa0(void);
extern s32 func_002e5270(u8 *arg0, u8 *arg1);
extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s64 func_00311d00(s32 id);
extern s32 func_00311d60(s32 id);
extern s32 func_00311e40(s32 id);
extern void *memcpy(void *dst, const void *src, u32 size);
extern s32 func_00106600(s16 arg0);
extern u32 func_00106880(s16 arg0);
extern u32 func_00106a60(s16 arg0);
extern u32 func_00106b20(s16 arg0);
extern u32 func_00106b50(s16 arg0);
extern u32 datGetFlag(s32 arg0);

/* 228/240 bytes; fifteen resolved relocations and twelve zero alignment bytes. */
// FUN_002E24A0
void func_002e24a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *buf;

    if (iGpffffb58c != NULL) {
        func_002e29a0();
    }
    func_0044ea90(D_0063FC48, 0x67);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    iGpffffb58c = (u8 *)(s32)func_00451de0((const void *)(D_0063FC58), 0xF, 0, 0, func_002e23b0, func_002e2470, (u8 *)(buf));
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = arg1;
    *(s8 *)(buf + 1) = arg2;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg3;
}

// FUN_002E2590
void func_002e2590(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4) {
    u8 *buf;

    func_0044ea90(D_0063FC48, 0x82);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063FC58), 0xF, 0, 0, func_002e2410, func_002e2470, (u8 *)(buf));
    *(s32 *)(buf + 4) = arg1;
    *(s32 *)(buf + 8) = arg2;
    *(s8 *)(buf + 1) = arg3;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg4;
}

// FUN_002E2670
s16 func_002e2670(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return *(s16 *)(*(u8 **)(g + 0x38) + 2);
}

// FUN_002E26A0
s32 func_002e26a0(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return func_002b2d00(*(s16 *)(*(u8 **)(g + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E26F0
s16 func_002e26f0(void *arg0) {
    return *(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2);
}

// FUN_002E2700
s32 func_002e2700(void *arg0) {
    return func_002b2d00(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E2740
s32 func_002e2740(s32 arg0) {
    u8 *g = iGpffffb58c;
    u8 *p;
    s32 count;

    if (g == NULL) {
        return -1;
    }
    p = *(u8 **)(g + 0x38);
    if (g == NULL) {
        count = -1;
    } else {
        count = *(s16 *)(p + 2);
    }
    if (count < arg0) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg0 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E2830
s32 func_002e2830(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg1 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E28F0
s16 func_002e28f0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    case 2:
        return 1;
    case 3:
        return 1;
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    default:
        return -1;
    }
}

// FUN_002E29A0
void func_002e29a0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        func_00452080((s32)g);
        iGpffffb58c = NULL;
    }
}

// FUN_002E29D0
s8 func_002e29d0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        return *(s8 *)(*(void **)(g + 0x38));
    }
    return -1;
}

// FUN_002E2A00
s8 func_002e2a00(void *arg0) {
    return *(s8 *)(*(void **)((u8 *)arg0 + 0x38));
}

/* The 0x1810-byte item work area stores either paired IDs and quantities
   or a compact ID list. Compaction reads the paired ID after each move. */
typedef struct YListItemRow {
    s16 id;
    s16 quantity;
} YListItemRow;

typedef struct YListItemWork {
    u8 enabled;
    s8 kind;
    s16 count;
    s32 filterA;
    s32 filterB;
    s8 order;
    u8 unknown0D;
    union {
        YListItemRow paired[0x600];
        s16 ids[0x600];
    } rows;
} YListItemWork;

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
static inline s32 yListAcceptsItem(u8 *owner, s16 id)
{
    u8 *filter = *(u8 **)(owner + 0x38);
    if (*(s32 *)(filter + 4) == 0 && *(s32 *)(filter + 8) == 0) {
        return 1;
    }
    if (*(s32 *)(filter + 4) == 0 && (*(s32 *)(filter + 8) & func_00106a60(id))) {
        return 1;
    }
    if (*(s32 *)(filter + 8) == 0 && (*(s32 *)(filter + 4) & func_00106880(id))) {
        return 1;
    }
    if ((*(s32 *)(filter + 4) & func_00106880(id)) &&
        (*(s32 *)(filter + 8) & func_00106a60(id))) {
        return 1;
    }
    return 0;
}

/* measured: 2888 code bytes and eight zero alignment bytes; the scoped
   common-subexpression and loop-invariant settings preserve all siblings. */
// FUN_002E2A10
void func_002e2a10(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    s32 reorder[0x600];
    s32 sortbuf[0x600];
    s32 out_count;
    s8 mode;
    s16 count;
    s16 type;
    s32 value;
    s32 ok;
    YListItemWork *p;
    u8 *g;
    g = iGpffffb58c;
    if (g == NULL) {
        return;
    }
    p = *(YListItemWork **)(g + 0x38);
    p->filterA = arg0;
    p->filterB = arg1;
    p->kind = arg2;
    p->count = 0;
    type = p->kind;
    switch (type) {
    case 1: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            p->rows.paired[i].quantity = 0;
            p->rows.paired[i].id = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                ok = yListAcceptsItem(iGpffffb58c, i);
                if ((ok == 1) && !(func_00106a60(i) & 0x2000)) {
                    p->rows.paired[p->count].id = i;
                    p->rows.paired[p->count].quantity = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    case 2: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            ok = yListAcceptsItem(iGpffffb58c, i);
            if (ok == 1) {
                type = (s16)func_002be1b0(i);
                if ((type != 0x10) && (type != 0x11) && (type != 0x12)) {
                    if (datGetFlag(0x1462) == 0) {
                        value = (s32)(func_00106b20(i) & 0xFFF00) >> 8;
                        if (func_002be160(value, func_00106b20(i) & 0xFF) == 1) {
                            value = (s32)(func_00106b50(i) & 0xFFF00) >> 8;
                            if (func_002be160(value, func_00106b50(i) & 0xFF) == 1) {
                                p->rows.paired[i].quantity = 0;
                                p->rows.paired[p->count].id = i;
                                count = func_002b2cb0(p->count, 1, 0, 0, 0);
                                p->count = count;
                            }
                        }
                    } else {
                        p->rows.paired[i].quantity = 0;
                        p->rows.paired[p->count].id = i;
                        count = func_002b2cb0(p->count, 1, 0, 0, 0);
                        p->count = count;
                    }
                } else if (datGetFlag(0x1462) == 0) {
                    if (func_002bdff0(i) == 1) {
                        p->rows.paired[i].quantity = 0;
                        p->rows.paired[p->count].id = i;
                        count = func_002b2cb0(p->count, 1, 0, 0, 0);
                        p->count = count;
                    }
                } else {
                    p->rows.paired[i].quantity = 0;
                    p->rows.paired[p->count].id = i;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    case 3: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            p->rows.ids[i] = 0;
            ok = yListAcceptsItem(iGpffffb58c, i);
            if (ok == 1) {
                p->rows.ids[p->count] = i;
                count = func_002b2cb0(p->count, 1, 0, 0, 0);
                p->count = count;
            }
        }
        break;
    }
    case 4: {
        s16 i;
        count = func_002b2cb0(p->count, 1, 0, 0, 0);
        p->count = count;
        for (i = 0; i < 0x600; i++) {
            p->rows.paired[i].quantity = 0;
            p->rows.paired[i].id = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                ok = yListAcceptsItem(iGpffffb58c, i);
                if (ok == 1) {
                    p->rows.paired[p->count].id = i;
                    p->rows.paired[p->count].quantity = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    default:
        break;
    }
    mode = (s8)arg3;
    if (mode == 1) {
        s16 fillIndex;
        s16 markIndex;
        s16 compactIndex;
        s16 copyIndex;
        out_count = 0;
        for (fillIndex = 0; fillIndex < 0x600; fillIndex++) {
            reorder[fillIndex] = -1;
        }
        for (markIndex = 0; markIndex < p->count; markIndex++) {
            if ((clndGetMoonPhase(p->rows.paired[markIndex].id) & 0xFF) & 1) {
                reorder[out_count] = p->rows.paired[markIndex].id;
                value = clndGetMoonPhase(p->rows.paired[markIndex].id);
                func_00110810(p->rows.paired[markIndex].id, (value | 2) & 0xFF);
                p->rows.paired[markIndex].id = -1;
                p->rows.paired[markIndex].quantity = 1;
                out_count++;
            }
        }
        for (compactIndex = 0; compactIndex < p->count; compactIndex++) {
            if (p->rows.paired[compactIndex].id != -1) {
                reorder[out_count] = p->rows.paired[compactIndex].id;
                p->rows.paired[compactIndex].quantity = 0;
                out_count++;
            }
        }
        for (copyIndex = 0; copyIndex < p->count; copyIndex++) {
            p->rows.paired[copyIndex].id = (s16)reorder[copyIndex];
        }
    }
    if (mode == 2) {
        s16 collectIndex;
        s16 sortedIndex;
        for (collectIndex = 0; collectIndex < p->count; collectIndex++) {
            sortbuf[collectIndex] = p->rows.paired[collectIndex].id;
        }
        qsort(sortbuf, p->count, 4, func_002b3230);
        for (sortedIndex = 0; sortedIndex < p->count; sortedIndex++) {
            p->rows.paired[sortedIndex].id = (s16)sortbuf[sortedIndex];
            p->rows.paired[sortedIndex].quantity = 0;
            if ((clndGetMoonPhase(p->rows.paired[sortedIndex].id) & 0xFF) & 1) {
                p->rows.paired[sortedIndex].quantity = 1;
                value = clndGetMoonPhase(p->rows.paired[sortedIndex].id);
                func_00110810(p->rows.paired[sortedIndex].id, (value | 2) & 0xFF);
            }
        }
    }
}

#pragma pop
#pragma opt_common_subs on

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
/* measured: all 2864 code bytes match with the same scoped settings. */
// FUN_002E3560
void func_002e3560(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4) {
    s32 reorder[0x600];
    s32 sortbuf[0x600];
    s32 out_count;
    s8 mode;
    s16 count;
    s16 type;
    s32 value;
    s32 ok;
    YListItemWork *p;
    p = *(YListItemWork **)(arg0 + 0x38);
    p->filterA = arg1;
    p->filterB = arg2;
    p->kind = arg3;
    p->count = 0;
    type = p->kind;
    switch (type) {
    case 1: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            p->rows.paired[i].quantity = 0;
            p->rows.paired[i].id = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                ok = yListAcceptsItem(arg0, i);
                if ((ok == 1) && !(func_00106a60(i) & 0x2000)) {
                    p->rows.paired[p->count].id = i;
                    p->rows.paired[p->count].quantity = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    case 2: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            ok = yListAcceptsItem(arg0, i);
            if (ok == 1) {
                type = (s16)func_002be1b0(i);
                if ((type != 0x10) && (type != 0x11) && (type != 0x12)) {
                    if (datGetFlag(0x1462) == 0) {
                        value = (s32)(func_00106b20(i) & 0xFFF00) >> 8;
                        if (func_002be160(value, func_00106b20(i) & 0xFF) == 1) {
                            value = (s32)(func_00106b50(i) & 0xFFF00) >> 8;
                            if (func_002be160(value, func_00106b50(i) & 0xFF) == 1) {
                                p->rows.paired[i].quantity = 0;
                                p->rows.paired[p->count].id = i;
                                count = func_002b2cb0(p->count, 1, 0, 0, 0);
                                p->count = count;
                            }
                        }
                    } else {
                        p->rows.paired[i].quantity = 0;
                        p->rows.paired[p->count].id = i;
                        count = func_002b2cb0(p->count, 1, 0, 0, 0);
                        p->count = count;
                    }
                } else if (datGetFlag(0x1462) == 0) {
                    if (func_002bdff0(i) == 1) {
                        p->rows.paired[i].quantity = 0;
                        p->rows.paired[p->count].id = i;
                        count = func_002b2cb0(p->count, 1, 0, 0, 0);
                        p->count = count;
                    }
                } else {
                    p->rows.paired[i].quantity = 0;
                    p->rows.paired[p->count].id = i;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    case 3: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            p->rows.ids[i] = 0;
            ok = yListAcceptsItem(arg0, i);
            if (ok == 1) {
                p->rows.ids[p->count] = i;
                count = func_002b2cb0(p->count, 1, 0, 0, 0);
                p->count = count;
            }
        }
        break;
    }
    case 4: {
        s16 i;
        count = func_002b2cb0(p->count, 1, 0, 0, 0);
        p->count = count;
        for (i = 0; i < 0x600; i++) {
            p->rows.paired[i].quantity = 0;
            p->rows.paired[i].id = 0;
            if ((func_00106600(i) & 0xFF) > 0) {
                ok = yListAcceptsItem(arg0, i);
                if (ok == 1) {
                    p->rows.paired[p->count].id = i;
                    p->rows.paired[p->count].quantity = func_00106600(i) & 0xFF;
                    count = func_002b2cb0(p->count, 1, 0, 0, 0);
                    p->count = count;
                }
            }
        }
        break;
    }
    default:
        break;
    }
    mode = (s8)arg4;
    if (mode == 1) {
        s16 fillIndex;
        s16 markIndex;
        s16 compactIndex;
        s16 copyIndex;
        out_count = 0;
        for (fillIndex = 0; fillIndex < 0x600; fillIndex++) {
            reorder[fillIndex] = -1;
        }
        for (markIndex = 0; markIndex < p->count; markIndex++) {
            if ((clndGetMoonPhase(p->rows.paired[markIndex].id) & 0xFF) & 1) {
                reorder[out_count] = p->rows.paired[markIndex].id;
                value = clndGetMoonPhase(p->rows.paired[markIndex].id);
                func_00110810(p->rows.paired[markIndex].id, (value | 2) & 0xFF);
                p->rows.paired[markIndex].id = -1;
                p->rows.paired[markIndex].quantity = 1;
                out_count++;
            }
        }
        for (compactIndex = 0; compactIndex < p->count; compactIndex++) {
            if (p->rows.paired[compactIndex].id != -1) {
                reorder[out_count] = p->rows.paired[compactIndex].id;
                p->rows.paired[compactIndex].quantity = 0;
                out_count++;
            }
        }
        for (copyIndex = 0; copyIndex < p->count; copyIndex++) {
            p->rows.paired[copyIndex].id = (s16)reorder[copyIndex];
        }
    }
    if (mode == 2) {
        s16 collectIndex;
        s16 sortedIndex;
        for (collectIndex = 0; collectIndex < p->count; collectIndex++) {
            sortbuf[collectIndex] = p->rows.paired[collectIndex].id;
        }
        qsort(sortbuf, p->count, 4, func_002b3230);
        for (sortedIndex = 0; sortedIndex < p->count; sortedIndex++) {
            p->rows.paired[sortedIndex].id = (s16)sortbuf[sortedIndex];
            p->rows.paired[sortedIndex].quantity = 0;
            if ((clndGetMoonPhase(p->rows.paired[sortedIndex].id) & 0xFF) & 1) {
                p->rows.paired[sortedIndex].quantity = 1;
                value = clndGetMoonPhase(p->rows.paired[sortedIndex].id);
                func_00110810(p->rows.paired[sortedIndex].id, (value | 2) & 0xFF);
            }
        }
    }
}

#pragma pop
#pragma opt_common_subs on

typedef struct YListPersonaRecord {
    u16 flags;
    u16 id;
    u8 data[0x2C];
} YListPersonaRecord;
typedef char YListPersonaSizeCheck[sizeof(YListPersonaRecord) == 0x30 ? 1 : -1];

/* Case 6 compares the inventory persona with its compendium record.
 * Read the copied record ID before both metadata and compendium lookup. */
// FUN_002E4090
#pragma push
#pragma opt_lifetimes on
s32 func_002e4090(u8 *arg0) {
    YListPersonaRecord registered;
    YListPersonaRecord current;
    s16 i;
    u16 *tmp;
    u8 *p;
    u32 sw;
    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)p == 1) {
        return 0;
    }
    *(s32 *)(p + 8) = 0;
    sw = *(u32 *)(p + 4);
    switch (sw) {
    case 0:
        for (i = 1; i < 0xC; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    case 1:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                memset(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                memcpy(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, func_0010ace0(i), 0x30);
                *(s32 *)(p + 8) += 1;
            }
        }
        break;
    case 2:
        for (i = 0; i < 0x100; i++) {
            if (func_0010fcb0(i) != 0) {
                memset(p + (*(s32 *)(p + 8) * 0x30) + 0x14, 0, 0x30);
                memcpy(p + (*(s32 *)(p + 8) * 0x30) + 0x14, func_0010fcb0(i), 0x30);
                *(s32 *)(p + 8) += 1;
            }
        }
        break;
    case 5:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                tmp = func_0010a900(1);
                if (tmp != func_0010ace0(i)) {
                    memset(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                    memcpy(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, func_0010ace0(i), 0x30);
                    *(s32 *)(p + 8) += 1;
                }
            }
        }
        break;
    case 6:
        for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
            if (func_0010abd0(i) == 1) {
                memcpy(&current, func_0010ace0(i), 0x30);
                if (*(u8 *)(iGpffffb3d4 + current.id * 0xE + 2) < 0x16) {
                    memcpy(&registered, func_0010fcb0(current.id), 0x30);
                    if (func_002e5270((u8 *)&current, (u8 *)&registered) == 1) {
                        memset(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, 0, 0x30);
                        memcpy(p + (*(s32 *)(p + 8) * 0x30) + 0xA4, func_0010ace0(i), 0x30);
                        *(s32 *)(p + 8) += 1;
                    }
                }
            }
        }
        break;
    case 7:
        for (i = 1; i < 0xC0; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    case 8:
        func_0010ffa0();
        for (i = 1; i < 0xC0; i++) {
            func_0010cad0(p + ((i - 1) * 0x30) + 0x14, (u16)i);
            *(s32 *)(p + 8) += 1;
        }
        break;
    default:
        break;
    }
    *p = 1;
    return 0;
}


#pragma pop
// FUN_002E45E0
void func_002e45e0(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E4610
void func_002e4610(s32 arg0, s8 arg1) {
    u8 *buf;
    u8 **slot;
    u8 *base;
    s16 i;
    s16 j;

    func_002e47b0();
    slot = &D_00882F70[arg1];
    if (*slot != NULL) {
        func_002e4820(arg1);
    }
    func_0044ea90(D_0063FC48, 0x38F);
    buf = D_008873F4[0](1, 0x3014, 0x40000);
    *slot = (u8 *)(s32)func_00451de0((const void *)(D_0063FC58), 0xF, 0, 0, func_002e4090, func_002e45e0, (u8 *)(buf));
    buf[0] = 0;
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = 0;
    switch (arg0) {
    case 1:
    case 0xA:
    case 6:
        for (i = 0; i < 0xC; i++) {
            j = 0;
            base = buf + i * 12;
            while (j < 0xC) {
                *(u8 *)(base + 0x14 + j) = 0;
                j++;
            }
        }
        break;
    default:
        break;
    }
    if (arg0 == 0xA) {
        buf[0] = 1;
    }
}
// FUN_002E47B0
s8 func_002e47b0(void) {
    s16 i = 0;
    u8 **base = D_00882F70;

    while (i < 15) {
        if (*(u8 **)((u32)base + i * 4) == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002E4820
void func_002e4820(s8 arg0) {
    u8 **p = &D_00882F70[arg0];

    if (*p != NULL) {
        func_00452080((s32)*p);
        *p = NULL;
    }
}

// FUN_002E4870
u8 *func_002e4870(s8 arg0) {
    return *(void **)(D_00882F70[arg0] + 0x38);
}

// FUN_002E48A0
u8 *func_002e48a0(s8 arg0, s16 arg1) {
    u8 *p = *(u8 **)(D_00882F70[arg0] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((arg1 * 3) * 0x10) + 0xA4;
    default:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    }
}

/* measured 2026-08-08: this reconstruction is a park at object
   348B/window 352B and nd 16.  The scheduling lever is retained: the
   dispatch operations are in retail order at 0x1C..0x28 (lw pointer,
   lw type, addiu literal 6, beq), after moving the named n3=6 assignment
   into the default loop and using the direct switch expression.  The
   remaining thirteen instruction rows are scratch-register colouring only
   ($a3 versus $t0), plus retail's final zero-padding word at 0x15C:
   0x1C lw a3,38(v1) vs lw t0,38(v1); 0x20 lw a1,4(a3) vs lw a1,4(t0);
   0x24 addiu t0,zero,6 vs addiu a3,zero,6; 0x28 beq a1,t0 vs beq a1,a3;
   0x90/0xDC/0x128 addu v1,v1,a3 vs addu v1,v1,t0;
   0x12C addiu a3,v1,14 vs addiu a2,v1,14; 0x130/0x134 lw via a3 vs a2;
   0x138 addiu a3,a3,8 vs addiu a2,a2,8; 0x13C addiu t0,t0,-1 vs
   addiu a3,a3,-1; 0x14C bgtz t0 vs bgtz a3; 0x15C retail-only nop.
   Ruled out declaration order, pointer type, assignment order, integer
   base spelling, counter-first source, operand-order changes, removal of
   the named type local, removal of the early named constant, and the
   direct switch rewrite; all retained nd 19 or worsened the object.
   Committed at nd 16. */
// FUN_002E4960
void func_002e4960(u8 *arg0, s8 arg1, s16 arg2) {
 u8 *p; u8 *p0; u8 *p1; s32 n3; u8 *src; u8 *src2; s32 n; p=*(u8 **)(D_00882F70[arg1]+0x38); switch(*(s32 *)(p+4)) {
 case 0: case 7: case 8: p0=p; src=p0; src=(u8 *)(u32)src; src=(u8 *)((s32)arg2*0x30)+(u32)src; src+=0x14; n=6; do{s32 v0=*(s32*)src;s32 v1=*(s32*)(src+4);src+=8;n--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n>0);break;
 case 1: case 10: case 5: case 6: p1=p; src=p1; src=(u8 *)(u32)src; src=(u8 *)((s32)arg2*0x30)+(u32)src; src+=0xa4; n=6; do{s32 v0=*(s32*)src;s32 v1=*(s32*)(src+4);src+=8;n--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n>0);break;
 default: src2=p; src2=(u8 *)(u32)src2; src2=(u8 *)((s32)arg2*0x30)+(u32)src2; src2+=0x14; n3=6; do{s32 v0=*(s32*)src2;s32 v1=*(s32*)(src2+4);src2+=8;n3--;*(s32*)arg0=v0;*(s32*)(arg0+4)=v1;arg0+=8;}while(n3>0);break;} }





static inline u8 *yListWork(s8 list) {
    return *(u8 **)(D_00882F70[list] + 0x38);
}

static inline u8 *yListEntryInWork(u8 *work, s16 index) {
    switch (*(u32 *)(work + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        work += index * 0x30;
        return work + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        work += index * 0x30;
        return work + 0xA4;
    default:
        work += index * 0x30;
        return work + 0x14;
    }
}

/* Build pair or triple availability for list kinds 1, 6 and 10. The mode is
 * retained before arg0 becomes the signed-byte result of each combination.
 * Triple mode also updates the corresponding destination-list matrix. */
// FUN_002E4AC0
#pragma push
#pragma opt_loop_invariants on
void func_002e4ac0(s32 arg0, s32 arg1) {
    u8 *base;
    u8 *row;
    u8 *flag;
    u8 *destination;
    u8 *mirror;
    s32 kind;
    s16 i;
    s16 j;
    s8 mode;
    s8 selected;

    base = yListWork(0);
    kind = *(s32 *)(base + 4);
    switch (kind) {
    case 1:
    case 10:
    case 6:
        i = 0;
        mode = (s8)arg0;
        selected = (s8)arg1;
        for (; i < *(s32 *)(yListWork(0) + 8); i++) {
            base[i + 0x2E4] = 0;
            j = 0;
            row = base + i * 12;
            for (; j < *(s32 *)(yListWork(0) + 8); j++) {
                flag = row + j + 0x14;
                *flag = 0;
                if (i != j) {
                    if (mode == 0) {
                        destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
                        arg0 = (s8)func_00312b60((s32)destination,
                            *(s16 *)(yListEntryInWork(yListWork(0), i) + 2),
                            *(s16 *)(yListEntryInWork(yListWork(0), j) + 2));
                    } else if (mode == 1) {
                        if (selected == i || selected == j) {
                            arg0 = 0;
                        } else {
                            destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
                            arg0 = (s8)func_00312b90((u16 *)destination,
                                yListEntryInWork(yListWork(0), selected),
                                yListEntryInWork(yListWork(0), i),
                                yListEntryInWork(yListWork(0), j));
                        }
                        /* Match the neighboring accessors' EE word-address view. */
                        mirror = (u8 *)(i * 12 +
                            (u32)*(u8 **)(D_00882F70[i + 1] + 0x38)) + j + 0x14;
                        *mirror = 0;
                        if ((s8)arg0 != 0) {
                            *mirror = 1;
                            if ((s8)arg0 == 2) {
                                *mirror = 2;
                            }
                        }
                    }
                    if ((s8)arg0 != 0) {
                        *flag = 1;
                        if ((s8)arg0 == 2) {
                            *flag = 2;
                        }
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}
#pragma pop

extern s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2);

/* Fill the availability matrix and each row's corresponding pair-result list.
 * Complete the destination lookup before reading the two source record IDs. */
// FUN_002E5000
#pragma push
#pragma opt_loop_invariants on
void func_002e5000(void) {
    u8 *base;
    u8 *row;
    u8 *flag;
    u8 *destination;
    s16 i;
    s16 j;

    base = yListWork(0);
    for (i = 0; i < *(s32 *)(yListWork(0) + 8); i++) {
        j = 0;
        row = base + i * 12;
        for (; j < *(s32 *)(yListWork(0) + 8); j++) {
            flag = row + j + 0x14;
            *flag = 0;
            destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
            if (func_003129b0(destination,
                    *(u16 *)(yListEntryInWork(yListWork(0), i) + 2),
                    *(u16 *)(yListEntryInWork(yListWork(0), j) + 2)) == 1) {
                *flag = 1;
            }
        }
    }
}
#pragma pop

// FUN_002E5270
s32 func_002e5270(u8 *arg0, u8 *arg1) {
    s16 i;
    s16 j;
    s16 k;

    if (*(u8 *)(arg0 + 4) != *(u8 *)(arg1 + 4)) {
        return 1;
    }
    for (i = 0; i < 5; i++) {
        if (*(u8 *)(arg0 + 0x1C + i) != *(u8 *)(arg1 + 0x1C + i)) {
            return 1;
        }
    }
    for (j = 0; j < 5; j++) {
        if (*(u8 *)(arg0 + 0x26 + j) != *(u8 *)(arg1 + 0x26 + j)) {
            return 1;
        }
    }
    for (k = 0; k < 8; k++) {
        if (*(u16 *)(arg0 + 0xC + k * 2) != *(u16 *)(arg1 + 0xC + k * 2)) {
            return 1;
        }
    }
    return *(u32 *)(arg0 + 8) != *(u32 *)(arg1 + 8);
}
// FUN_002E53B0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* measured: without `opt_loop_invariants on` the switch jump-table base is
   rematerialized in the loop body instead of hoisted to the preheader (nd 30+). */
s32 func_002e53b0(s8 arg0, s16 arg1) {
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;
    s16 i = 0;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return 1;
            }
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e53b0). */
#pragma opt_loop_invariants off

// FUN_002E54C0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
s16 func_002e54c0(s8 arg0, s16 arg1) {
    s16 i = 0;
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return i;
            }
        }
    }
    return -1;
}
/* measured: see the annotation above the matching `on` pragma (func_002e54c0). */
#pragma opt_loop_invariants off

/* measured: direct C reconstruction. Disabling common-subexpression
   elimination preserves retail's repeated D_00882F70[arg0] address
   materialization; explicit (u16)arg1 preserves ac10's 16-bit argument. */
#pragma opt_common_subs off
// FUN_002E55C0
void func_002e55c0(s8 arg0, s32 arg1, s8 arg2) {
    u8 **entryp;
    u8 *entry;

    entryp = &D_00882F70[arg0];
    entry = *entryp;
    if (entry != NULL) {
        if (arg2 == 0) {
            u8 *p;
            u8 *q;
            s16 index;

            p = *(u8 **)(entry + 0x38);
            index = *(s16 *)(p + 8);
            switch (*(s32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            }
            func_0010cad0(q, arg1 & 0xFFFF);
        } else if ((s16)func_0010aa80(arg1) == -1) {
            {
                u8 *p;
                u8 *q;
                s16 index;

                p = *(u8 **)(D_00882F70[arg0] + 0x38);
                index = *(s16 *)(p + 8);
                switch (*(s32 *)(p + 4)) {
                case 0:
                case 2:
                case 7:
                case 8:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    q = p + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                func_0010cad0(q, arg1 & 0xFFFF);
            }
            {
                u8 *p;
                u8 *q;
                s16 index;

                p = *(u8 **)(D_00882F70[arg0] + 0x38);
                index = *(s16 *)(p + 8);
                switch (*(s32 *)(p + 4)) {
                case 0:
                case 2:
                case 7:
                case 8:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    q = p + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    q = p + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                *(u8 *)(q + 4) = 0;
            }
        } else {
            u8 *p;
            u8 *q;
            u16 *src;
            s16 index;

            p = *(u8 **)(D_00882F70[arg0] + 0x38);
            index = *(s16 *)(p + 8);
            switch (*(s32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((index * 3) * 0x10) + 0x14;
                break;
            }
            src = func_0010ac10((u16)arg1);
            memcpy(q, src, 0x30);
        }
        (*(s32 *)(*(u8 **)(*entryp + 0x38) + 8))++;
    }
}

/* measured: restore common-subexpression elimination after func_002e55c0. */
#pragma opt_common_subs on
// FUN_002E5960
void func_002e5960(s8 arg0) {
    u8 *p;
    s16 i;
    s16 j;
    s32 type;

    if (D_00882F70[arg0] == NULL) {
        return;
    }
    p = *(u8 **)(D_00882F70[arg0] + 0x38);
    type = *(s32 *)(p + 4);
    switch (type) {
    case 0:
    case 7:
    case 8:
        for (i = 0; i < 0x100; i++) {
            memset(p + ((i * 3) * 0x10) + 0x14, 0, 0x30);
        }
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        for (j = 0; j < 0xC; j++) {
            memset(p + ((j * 3) * 0x10) + 0xA4, 0, 0x30);
            *(u8 *)(p + j + 0x2E4) = 0;
        }
        break;
    default:
        break;
    }
    *(s16 *)(p + 0xE) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s32 *)(p + 8) = 0;
}

/* measured: 1860B of 1872B, 45 resolved differing words. Signed level,
   bound and metadata-offset snapshots recover the retail spill lifetimes;
   separate membership counters preserve the initial and expanded searches.
   The remaining differences are saved-register assignments. All 35 code
   references and all four 11-entry jump tables resolve to retail; 36 matched
   siblings are unchanged. Guard and ASM fallback remain until exact.
   Proof: docs/probe_archive/YList_range_002e5ae0_20261006/README.md. */
// FUN_002E5AE0 NONMATCHING
#ifdef NON_MATCHING
extern s32 func_002e6230(u16 arg0, u16 *arg1);
void func_002e5ae0(s8 arg0, u16 *arg1, s8 arg2)
{
    u8 **slotp;
    u8 *p;
    s16 lo;
    s32 level;
    s32 hi;
    s16 i;
    s16 initialRow;
    s16 expandedRow;
    s32 found;
    u16 id;
    u8 *q;
    s16 h;
    u32 sw1;
    u32 sw2;
    u8 *dst1;
    u8 *dst2;
    s16 lo2;
    s16 hi2;
    s16 outer;
    s32 lowLimit;
    s32 highLimit2;
    s32 lowLimit2;
    s16 inner;
    slotp = &D_00882F70[arg0];
    if (*slotp == NULL) {
        return;
    }
    p = *(u8 **)(*slotp + 0x38);
    func_002e5960(arg0);
    level = (s8)arg2;
    lo = (s16)func_002b2d00(level, 10, 1, 0x63, 1);
    hi = (s16)func_002b2cb0(level, 1, 0x63, 1, 1);
    i = 0;
    lowLimit = (s16)lo;
    for (; i < 0xC0; i++) {
        s32 signedIndex = i;
        s32 metadataOffset;
        u8 *metadata;
        u8 kind;
        metadata = iGpffffb3d4;
        metadataOffset = signedIndex * 14;
        metadata += metadataOffset;
        kind = metadata[2];
        if (kind < 2 || kind >= 0x16) {
            continue;
        }
        id = (u16)i;
        if (func_00311d00(id) == 0) {
            continue;
        }
        if (func_00311d60(id) == 0) {
            continue;
        }
        if (func_002e6230(id, arg1) != 0) {
            continue;
        }
        if (*slotp != NULL) {
            for (initialRow = 0; initialRow < *(s32 *)(*(u8 **)(*slotp + 0x38) + 8); initialRow++) {
                if (signedIndex == *(u16 *)(func_002e48a0(arg0, initialRow) + 2)) {
                    found = 1;
                    goto initialSearchDone;
                }
            }
        }
        found = 0;
initialSearchDone:
        if (found != 0) {
            continue;
        }
        if (func_00311e40(id) != 0) {
            continue;
        }
        metadata = iGpffffb3d4;
        metadata += metadataOffset;
        if (hi < metadata[3] || lowLimit > metadata[3]) {
            continue;
        }
        h = *(s16 *)(p + 8);
        q = *(u8 **)(*slotp + 0x38);
        sw1 = *(u32 *)(q + 4);
        switch (sw1) {
        case 0:
        case 2:
        case 7:
        case 8:
            dst1 = q + h * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            dst1 = q + h * 0x30 + 0xA4;
            break;
        default:
            dst1 = q + h * 0x30 + 0x14;
            break;
        }
        memset(dst1, 0, 0x30);
        h = *(s16 *)(p + 8);
        q = *(u8 **)(*slotp + 0x38);
        sw2 = *(u32 *)(q + 4);
        switch (sw2) {
        case 0:
        case 2:
        case 7:
        case 8:
            dst2 = q + h * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            dst2 = q + h * 0x30 + 0xA4;
            break;
        default:
            dst2 = q + h * 0x30 + 0x14;
            break;
        }
        func_0010cad0(dst2, id);
        *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    }
    if (level >= 0x3C && *(s32 *)(p + 8) < 3) {
        func_002e5960(arg0);
    }
    if (*(s32 *)(p + 8) != 0) {
        return;
    }
    outer = 0;
    do {
        s32 expansion = outer;
        lo2 = (s16)func_002b2d00(level, expansion * 5 + 10, 1, 0x63, 1);
        hi2 = (s16)func_002b2cb0(level, expansion + 1, 0x63, 1, 1);
        func_002e5960(arg0);
        inner = 0;
        highLimit2 = (s16)hi2;
        lowLimit2 = (s16)lo2;
        for (; inner < 0xC0; inner++) {
            s32 signedIndex = inner;
            s32 metadataOffset;
            u8 *metadata;
            u8 kind;
            metadata = iGpffffb3d4;
            metadataOffset = signedIndex * 14;
            metadata += metadataOffset;
            kind = metadata[2];
            if (kind < 2 || kind >= 0x16) {
                continue;
            }
            id = (u16)inner;
            if (func_00311d00(id) == 0) {
                continue;
            }
            if (func_00311d60(id) == 0) {
                continue;
            }
            if (func_002e6230(id, arg1) != 0) {
                continue;
            }
            if (*slotp != NULL) {
                for (expandedRow = 0; expandedRow < *(s32 *)(*(u8 **)(*slotp + 0x38) + 8); expandedRow++) {
                    if (signedIndex == *(u16 *)(func_002e48a0(arg0, expandedRow) + 2)) {
                        found = 1;
                        goto expandedSearchDone;
                    }
                }
            }
            found = 0;
expandedSearchDone:
            if (found != 0) {
                continue;
            }
            if (func_00311e40(id) != 0) {
                continue;
            }
            metadata = iGpffffb3d4;
            metadata += metadataOffset;
            if (highLimit2 < metadata[3] || lowLimit2 > metadata[3]) {
                continue;
            }
            h = *(s16 *)(p + 8);
            q = *(u8 **)(*slotp + 0x38);
            sw1 = *(u32 *)(q + 4);
            switch (sw1) {
            case 0:
            case 2:
            case 7:
            case 8:
                dst1 = q + h * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                dst1 = q + h * 0x30 + 0xA4;
                break;
            default:
                dst1 = q + h * 0x30 + 0x14;
                break;
            }
            memset(dst1, 0, 0x30);
            h = *(s16 *)(p + 8);
            q = *(u8 **)(*slotp + 0x38);
            sw2 = *(u32 *)(q + 4);
            switch (sw2) {
            case 0:
            case 2:
            case 7:
            case 8:
                dst2 = q + h * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                dst2 = q + h * 0x30 + 0xA4;
                break;
            default:
                dst2 = q + h * 0x30 + 0x14;
                break;
            }
            func_0010cad0(dst2, id);
            *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
        }
        outer++;
    } while (*(s32 *)(p + 8) <= 5);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5ae0);
#endif

/* True when `id` is one of the 13 entries of `exclude`. func_002e6280 uses it
   inline; func_002e5ae0 calls the out-of-line copy. */
static inline s32 yListExcluded(u16 id, u16 *exclude)
{
    s32 j = 0;
    s32 key = id & 0xFFFF;

    while (j < 13) {
        if (exclude[j] == key) {
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_002E6230
s32 func_002e6230(u16 arg0, u16 *arg1) {
    return yListExcluded(arg0, arg1);
}

static inline u8 *yListEntry(s8 list, s16 index)
{
    u8 *p = *(u8 **)(D_00882F70[list] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((index * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((index * 3) * 0x10) + 0xA4;
    default:
        return p + ((index * 3) * 0x10) + 0x14;
    }
}

static inline s32 yListContains(s8 list, s16 id)
{
    s16 k;

    if (D_00882F70[list] != NULL) {
        for (k = 0; k < *(s32 *)(*(u8 **)(D_00882F70[list] + 0x38) + 8); k++) {
            if (id == *(u16 *)(func_002e48a0(list, k) + 2)) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
/* measured: MATCH. The exclusion, membership and entry-address steps are
   inline helpers, which gives retail's 1/0 joins and the two duplicated
   jump-table switches. The persona id passed to the u16 callees is `i`
   itself (a separate u16 local changes the saved-register order).
   measured: loop-invariant motion is required (29 words without it). */
#pragma opt_loop_invariants on
// FUN_002E6280
void func_002e6280(s8 list, u16 *exclude, s8 level)
{
    u8 *data;
    s32 limit;
    s16 i;

    if (D_00882F70[list] == NULL) {
        return;
    }
    data = *(u8 **)(D_00882F70[list] + 0x38);
    func_002e5960(list);
    limit = (s16)func_002b2cb0(level, 3, 99, 1, 1);
    for (i = 0; i < 0xC0; i++) {
        if (iGpffffb3d4[i * 0xE + 2] == 1 && (*(u16 *)&iGpffffb3d4[i * 0xE] & 8) == 0) {
            if (func_00311d00((u16)i) != 0 && func_00311d60((u16)i) != 0 && yListExcluded(i, exclude) == 0 &&
                yListContains(list, i) == 0 && func_00311e40((u16)i) == 0 &&
                limit >= iGpffffb3d4[i * 0xE + 3]) {
                memset(yListEntry(list, *(s32 *)(data + 8)), 0, 0x30);
                func_0010cad0(yListEntry(list, *(s32 *)(data + 8)), i);
                *(s32 *)(data + 8) += 1;
            }
        }
    }
}
#pragma pop

/* measured: 640B/640B, exact instructions and all 44 jump-table entries.
   Keep each signed index's byte offset across its repeated accessor pair.
   The comparator's O1 scope preserves the retail selector and key lifetimes. */
// FUN_002E6630
#pragma optimization_level 1
s32 func_002e6630(const void *arg0, const void *arg1) {
    s16 ia = *(const s16 *)arg0;
    s16 ib = *(const s16 *)arg1;
    u8 *base = *(u8 **)(D_00882F70[0] + 0x38);
    u8 *pa;
    u8 *qa;
    u8 *pb;
    u8 *qb;
    s32 offset_a;
    s32 offset_b;
    u8 *metadata;
    u16 va;
    s32 vb;
    s32 va_mask;
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0xA4;
        break;
    default:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qa = base + offset_a + 0xA4;
        break;
    default:
        qa = base + offset_a + 0x14;
        break;
    }
    metadata = iGpffffb3d4 + 2;
    va = pa[4] + 100 * metadata[14 * *(u16 *)(qa + 2)];
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0xA4;
        break;
    default:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qb = base + offset_b + 0xA4;
        break;
    default:
        qb = base + offset_b + 0x14;
        break;
    }
    vb = (u16)(pb[4] + 100 * metadata[14 * *(u16 *)(qb + 2)]);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma optimization_level 2





// FUN_002E68B0
/* measured: without `opt_loop_invariants on` MWCC keeps the loop2 switch
   jump-table base (lui/addiu) inside the dispatch instead of hoisting it
   into the preheader as retail does. */
#pragma opt_loop_invariants on
void func_002e68b0(s8 arg0) {
    u8 **slotp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 **ep;
    u8 *p2;
    s32 count2;
    s16 k;
    s16 j;
    u8 *dst;
    s16 i;
    s16 idx;
    s16 arr1[0x100];
    s16 arr2[0x100];

    entry = *slotp;
    if (entry == NULL) {
        return;
    }
    ep = (u8 **)(entry + 0x38);
    p = *(u8 **)(entry + 0x38);
    for (k = 0; k < *(s32 *)(*(u8 **)(entry + 0x38) + 8); k++) {
        arr1[k] = k;
    }
    qsort(arr1, *(u16 *)((u8 *)*ep + 8), 2, func_002e6630);
    j = 0;
    count2 = *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8);
    if (count2 > 0) {
        p2 = *(u8 **)((u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4) + 0x38);
        for (; j < count2; j++) {
            u8 *q;

            idx = arr1[j];
            switch (*(u32 *)(p2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p2 + ((idx * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            }
            arr2[j] = *(u16 *)(q + 2);
        }
    }
    for (i = 0; i < *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8); i++) {
        dst = p + ((i * 3) * 0x10) + 0x14;

        memset(dst, 0, 0x30);
        memcpy(dst, func_0010fcb0(arr2[i]), 0x30);
    }
}
/* measured: see the annotation above the matching `on` pragma (func_002e68b0). */
#pragma opt_loop_invariants off

/* measured 2026-08-12: best plain-C comparator body is archived at
   build/D2E6_002e6b20_body.c (object 360B/window 368B, normalized_diff 10;
   differing byte offsets 6,7,10,11,12,13,14,16,18,19). The direct body has
   no calls and its s16 *arg0/s16 *arg1 signature is confirmed. The remaining
   residual is the initial retail load order (lh arg0, lh arg1, then the
   global base) versus MWCCPS2's lh arg0, global base, lh arg1 schedule.
   Retained: s32 vb, s32 va_mask, opt_common_subs off. Ruled out:
   schedule-on, propagation-off, declaration-order, pointer-load,
   ordered-assignment/initializer, const/alias typed-load, optimization_level
   1, dependent-index, and split-global forms. */
/* measured: unmodified m2c candidate from src/generated, installed as a permuter seed; not a verified body. */
// FUN_002E6B20
#pragma schedule on
#pragma optimization_level 1
s32 func_002e6b20(const void *arg0, const void *arg1) {
    const s16 *arg1_p = arg1;
    const s16 *arg0_p = arg0;
    s16 ia;
    u8 *base;
    s16 ib;
    u8 *pa;
    u8 *pb;
    s32 vb;
    u16 va;
    s32 va_mask;
    ia = *arg0_p;
    ib = *arg1_p;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pa = base + ia * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pa = base + ia * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pa = base + ia * 0x30 + 0x14;
        break;
    }
    va = *(u8 *)(pa + 4);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pb = base + ib * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pb = base + ib * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pb = base + ib * 0x30 + 0x14;
        break;
    }
    vb = *(u8 *)(pb + 4);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma optimization_level 2
#pragma schedule off



/* func_002e6c90 was closed by porting the MATCHED sibling func_002e68b0: same
   declaration order, same p2 re-index spelling
   `(u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4)`, same loop2/loop3
   shapes, with func_002e6b20 as the sort comparator. That fixed the old
   "arg0 not saved to $s2" defect and the missing p2 re-index, taking the
   recorded nd 140 to 52; the remaining loop2 register rotation then cleared.
   measured: `opt_loop_invariants on` is required here — without it MWCC keeps
   the loop-invariant slot address live in the loop body instead of hoisting it
   into the preheader, which is the rotation retail does not have. */
// FUN_002E6C90
/* measured: open opt_loop_invariants scope for func_002e6c90. */
#pragma opt_loop_invariants on
void func_002e6c90(s8 arg0) {
    u8 **slotp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 **ep;
    u8 *p2;
    s32 count2;
    s16 k;
    s16 j;
    u8 *dst;
    s16 i;
    s16 idx;
    s16 arr1[0x100];
    s16 arr2[0x100];

    entry = *slotp;
    if (entry == NULL) {
        return;
    }
    ep = (u8 **)(entry + 0x38);
    p = *(u8 **)(entry + 0x38);
    for (k = 0; k < *(s32 *)(*(u8 **)(entry + 0x38) + 8); k++) {
        arr1[k] = k;
    }
    qsort(arr1, *(u16 *)((u8 *)*ep + 8), 2, func_002e6b20);
    j = 0;
    count2 = *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8);
    if (count2 > 0) {
        p2 = *(u8 **)(*(u8 **)((u8 *)D_00882F70 +
              (u32)(s8)arg0 * 4) + 0x38);
        for (; j < count2; j++) {
            u8 *q;

            idx = arr1[j];
            switch (*(u32 *)(p2 + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p2 + ((idx * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p2 + ((idx * 3) * 0x10) + 0x14;
                break;
            }
            arr2[j] = *(u16 *)(q + 2);
        }
    }
    for (i = 0; i < *(s32 *)(*(u8 **)((u8 *)*slotp + 0x38) + 8); i++) {
        dst = p + ((i * 3) * 0x10) + 0x14;

        memset(dst, 0, 0x30);
        memcpy(dst, func_0010fcb0(arr2[i]), 0x30);
    }
}
/* measured: closing the scope restores the file baseline; leaving
   `opt_loop_invariants on` open inflates the following functions. */
#pragma opt_loop_invariants off
// FUN_002E6F00
/* measured: without `opt_loop_invariants on` MWCC rematerializes the -1 store
   constant at the top of the loop body (nd 6) instead of hoisting it into the
   preheader as retail does (addiu $a1,$zero,-1 before the initial branch). */
#pragma opt_loop_invariants on
u8 *func_002e6f00(void) {
    s16 *buf;
    s16 i;
    s16 value;

    func_0044ea90(D_0063FC48, 0x649);
    buf = (s16 *)D_008873F4[0](1, 0x62, 0x40000);
    i = 0;
    value = -1;
    while (i < 0x30) {
        buf[i] = value;
        i++;
    }
    buf[0x30] = 0;
    return (u8 *)buf;
}
/* measured: see the annotation above the matching `on` pragma (func_002e6f00). */
#pragma opt_loop_invariants off

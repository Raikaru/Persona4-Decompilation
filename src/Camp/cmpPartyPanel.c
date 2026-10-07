/* Consolidated Persona 4 source units. */
/* Original translation unit cmpPartyPanel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

void func_0046d730(void* arg0, s32 arg1);
void func_0046b0d0(u8 *node);
void func_0044ea90(void* file, s32 line);

void memset(void* dest, s32 value, s32 size);
void func_00363540(u8* arg0, u8* arg1);
s32 func_00363610(u8* arg0);
void func_003640f0(u8* arg0);
s32 func_00362f00(u8* arg0);
void func_00363200(u8* arg0, s64 arg1);
void func_0034f1e0(void);
void func_0034f460(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   u8 arg2, u8 arg3, u8 arg4, u8 arg5);
u32 func_00104ce0(s16 arg0);
u16 func_00104dc0(s16 arg0);
u32 func_00104d50(s16 arg0);
u16 func_00104e30(s16 arg0);
u8* func_00457120(void);
s16 func_00353b50(s16* dst);
u8 *func_0046aea0(const char *name);
s32 sprintf(char *dst, const char *format, ...);
u32 func_0046a750(s16 *node);
void func_00460ac0(u8 *list, u8 *node);
extern u8 D_0064E2A0[];
extern u8 D_0064E2C0[];
extern u8 D_00794960[];
extern f32 D_008872F8[];
extern void (*D_00887300[])(u32, u32);
extern s32 (*D_00887310[])(s32, void*, s32);
extern u8 D_0064E290[];
extern u8 D_0064E2E0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void* ptr);

typedef struct { f32 x, y; } Vec2f;
static inline u8 *panelSlot(u32 offset, u8 *base) {
    return (u8 *)(offset + (u32)base);
}
typedef struct {
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[0xC];
    f32 f38;
    u8 pad3c[4];
    s32 c40;
    s32 c44;
    s32 c48;
    s32 c4C;
    u8 pad50[0x10];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0xC];
    f32 f78;
    u8 pad7c[4];
    s32 c80;
    s32 c84;
    s32 c88;
    s32 c8C;
    u8 pad90[0x10];
    f32 fA0;
    f32 fA4;
    f32 fA8;
    u8 padAC[0xC];
    f32 fB8;
    u8 padBC[4];
    s32 cC0;
    s32 cC4;
    s32 cC8;
    s32 cCC;
    u8 padD0[0x10];
    f32 fE0;
    f32 fE4;
    f32 fE8;
    u8 padEC[0xC];
    f32 fF8;
    u8 padFC[4];
    s32 c100;
    s32 c104;
    s32 c108;
    s32 c10C;
    u8 pad110[0x10];
} DrawPacket;
static inline f32 panelAdd(f32 left, f32 right) {
    return left + right;
}
static inline f32 panelMulForward(f32 left, f32 right) {
    return left * right;
}
static inline f32 panelMulReverse(f32 right, f32 left) {
    return right * left;
}

// FUN_00362FD0
void func_00362fd0(u8* arg0, f32* arg1, f32* arg2, s16 arg3) {
    if (arg1 == NULL) {
        *(Vec2f*)(arg0 + 0x00) = *(Vec2f*)(arg0 + 0x10);
    } else {
        *(Vec2f*)(arg0 + 0x00) = *(Vec2f*)(arg1);
    }
    if (arg2 == NULL) {
        func_0046d730(D_0064E290, 0x92);
    }
    *(Vec2f*)(arg0 + 0x08) = *(Vec2f*)(arg2);
    *(Vec2f*)(arg0 + 0x10) = *(Vec2f*)(arg0 + 0x00);
    *(s16*)(arg0 + 0x18) = 0;
    *(s16*)(arg0 + 0x1A) = arg3;
}


// FUN_00363080
void func_00363080(f32 fparg0, f32 fparg1, f32 fparg2) {
    DrawPacket packet;
    f32 z;
    f32 x;
    f32 y;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_mul;

    x = fparg0;
    y = fparg1;
    z = fparg2;
    temp_f20 = D_008872F8[0];
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f4 = panelMulForward(41.0f, z);
    temp_f2 = panelAdd(x, temp_f4);
    temp_f4 = temp_f2;
    temp_f2 = panelAdd(3.0f, temp_f4);
    temp_f4 = temp_f2;
    packet.f20 = temp_f4;
    temp_mul = 1.0f - z;
    temp_f3 = temp_mul;
    temp_f3 = panelMulForward(20.0f, temp_f3);
    temp_f3 = panelAdd(y, temp_f3);
    packet.f24 = temp_f3;
    packet.f28 = temp_f20;
    packet.c40 = 0x41A80000;
    packet.c44 = 0x41E80000;
    packet.c48 = 0x42080000;
    packet.c4C = 0x437F0000;
    packet.f38 = temp_f6;
    temp_f2 = 3.0f + (41.0f + x);
    packet.f60 = temp_f2;
    packet.f64 = y;
    packet.f68 = temp_f20;
    packet.c80 = 0x41A80000;
    packet.c84 = 0x41E80000;
    packet.c88 = 0x42080000;
    packet.c8C = 0x437F0000;
    packet.f78 = temp_f6;
    packet.fA0 = temp_f4;
    packet.fA4 = 4.0f + temp_f3;
    packet.fA8 = temp_f20;
    packet.cC0 = 0x41A80000;
    packet.cC4 = 0x41E80000;
    packet.cC8 = 0x42080000;
    packet.cCC = 0x437F0000;
    packet.fB8 = temp_f6;
    packet.fE0 = temp_f2;
    packet.fE4 = 4.0f + y;
    packet.fE8 = temp_f20;
    packet.c100 = 0x41A80000;
    packet.c104 = 0x41E80000;
    packet.c108 = 0x42080000;
    packet.c10C = 0x437F0000;
    packet.fF8 = temp_f6;
    D_00887300[0](1, 0);
    D_00887310[0](4, &packet, 4);
}


/* 820/832 bytes; sixteen resolved relocations and twelve zero alignment bytes.
 * The sprite API keeps coordinates before byte colors, as its core does.
 * Snapshot the row position and unsigned HP/SP values before drawing. */
// FUN_00363200
void func_00363200(u8* arg0, s64 arg1)
{
    s32 off = (s16)arg1 * 0x28;
    s16 id = *(s16*)((u8*)(off + (s32)arg0) + 0x34);
    s32 sprB = *(s32*)(arg0 + 0x0C);
    s32 sprA = *(s32*)((u8*)(off + (s32)arg0) + 0x2C);

    if (*(s32*)((u8*)(off + (s32)arg0) + 0x30) != 0) {
        Vec2f xy;
        f32 y;
        u32 hpCur;
        u32 hpMax;
        u32 spCur;
        u32 spMax;
        f32 ratio;
        f32 y35;
        f32 x13;
        f32 y39;

        if (sprB == 0) {
            func_0046d730(D_0064E290, 0x108);
        }
        if (sprA == 0) {
            func_0046d730(D_0064E290, 0x109);
        }
        xy = *(Vec2f*)(panelSlot(off, arg0) + 0x20);
        hpCur = func_00104ce0(id) & 0xFFFF;
        hpMax = func_00104dc0(id) & 0xFFFF;
        spCur = func_00104d50(id) & 0xFFFF;
        spMax = func_00104e30(id) & 0xFFFF;
        y = xy.y;
        func_0034f460(sprA, 0, xy.x, y, 0xFF, 0xFF, 0xFF, 0xFF);
        func_0034f460(sprB, 0, 8.0f + xy.x, 31.0f + y,
                      0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)hpCur / (f32)hpMax;
        y35 = 35.0f + y;
        x13 = 13.0f + xy.x;
        func_0034f460(sprB, 1, x13, y35, 0xFF, 0xFF, 0xFF, 0xFF);
        func_00363080(x13, y35, ratio);
        y39 = 39.0f + y;
        func_0034f460(sprB, 2, x13, y39, 0xFF, 0xFF, 0xFF, 0xFF);
        ratio = (f32)spCur / (f32)spMax;
        func_00363080(x13, y39, ratio);
    }
}

// FUN_00363540
void func_00363540(u8* arg0, u8* arg1) {
    s32 i;
    s32 j;
    u8* p;

    for (i = 0; i < *(s16*)(arg1 + 0xA); i++) {
        p = arg1 + (s16)i * 0x28;
        if (*(s32*)(p + 0x30) != 0) {
            func_00362f00(p + 0x10);
        }
    }
    if (*(u16*)(arg1 + 0) & 1) {
        func_0034f1e0();
        for (j = 0; j < *(s16*)(arg1 + 0xA); j++) {
            func_00363200(arg1, (s64)(s16)j);
        }
    }
}


/* Recovered work layout: 0x10-byte header, four 0x28-byte rows, then the
 * 0x30-byte ordering-table node. Animation fields are also read by 00362F00.
 * 00353B50 writes only the compacted live roster. The four-entry comparison
 * below intentionally retains retail's read of the unwritten stack tail,
 * as explicitly authorized for retail recovery on 2026-10-07. Do not clear
 * that tail or limit the removal scan to the compacted roster count.
 * If all four IDs compare equal after a shrink, changed reaches 4. The
 * offset-based update below then aliases the real ordering node at +0xB0
 * inside the 0xE0 allocation; it does not refer to a fifth stored party row.
 * Whole-owner configured compile: 2772 exact live bytes, 12 zero tail bytes;
 * the seven case-table entries at 007528E0 and all six siblings are exact. */
#pragma opt_loop_invariants on
typedef struct {
    Vec2f start;
    Vec2f end;
    Vec2f current;
    s16 frame;
    s16 duration;
} PartyPanelMotion;
typedef struct {
    PartyPanelMotion motion;
    u8 *sprite;
    s32 ready;
    s16 id;
} PartyPanelRow;
typedef struct {
    u32 next;
    u32 tail;
    void (*callback)(u8 *, u8 *);
    u32 unknown0c;
    void *context;
    u8 unknown14[0x1c];
} PartyPanelNode;
typedef struct {
    u16 flags;
    s32 state;
    s16 changed;
    s16 count;
    u8 *sprite;
    PartyPanelRow rows[4];
    PartyPanelNode node;
} PartyPanelWork;
typedef char PartyPanelRowSize[sizeof(PartyPanelRow)==0x28?1:-1];
typedef char PartyPanelWorkSize[sizeof(PartyPanelWork)==0xe0?1:-1];

/* Repeated row placement shares the signed roster-count contract. */
static inline void panelPosition(Vec2f *position, f32 x, s16 count, s32 index)
{
    position->x = x;
    position->y = 338.0f - 63.0f * (f32)((count - 1) - index);
}

// FUN_00363610
s32 func_00363610(u8 *task)
{
    PartyPanelWork *work = *(PartyPanelWork **)(task + 0x38);
    s16 roster[4];
    Vec2f position;
    Vec2f startPosition;
    Vec2f removedPosition;
    Vec2f shiftedPosition;
    Vec2f replacedPosition;
    PartyPanelRow removed;
    char initialName[256];
    char addedName[256];
    char replacedName[256];
    s32 ready, count;
    s16 id;
    PartyPanelRow *row;

    work->node.next = 0;
    work->node.tail = 0;
    func_00460ac0(D_00794960, (u8 *)&work->node);
    switch (work->state) {
    case 0: {
        s32 i;
        work->sprite = func_0046aea0((const char *)D_0064E2C0);
        work->count = func_00353b50(roster);
        for (i = 0; i < work->count; i++) {
            panelPosition(&position, (f32)565, work->count, i);
            id = roster[i];
            func_00362fd0((u8 *)&work->rows[i].motion, &position.x, &position.x, 0);
            work->rows[i].id = id;
            work->rows[i].ready = 0;
            if (id != 0) {
                sprintf(initialName, (const char *)D_0064E2A0, id);
                work->rows[i].sprite = func_0046aea0(initialName);
                if (work->rows[i].sprite == NULL) {
                    func_0046d730(D_0064E290, 0x166);
                }
            }
        }
        work->flags |= 1;
        work->state = 1;
        break;
    }
    case 1:
        if (func_0046a750((s16 *)work->sprite) == 0) {
            break;
        }
        work->state = 2;
        /* fallthrough */
    case 2: {
        s32 i = 0;
        ready = 0;
        for (; i < work->count; i++) {
            if (func_0046a750((s16 *)work->rows[i].sprite) != 0) {
                work->rows[i].ready = 1;
                ready++;
            }
        }
        if (ready == work->count) {
            work->state = 3;
            for (i = 0; i < work->count; i++) {
                panelPosition(&startPosition, (f32)565, work->count, i);
                func_00362fd0((u8 *)&work->rows[i].motion, NULL, &startPosition.x, 8);
            }
        }
        break;
    }
    case 3: {
        s32 i;
        if (work->flags & 2) {
            work->state = 6;
            break;
        }
        for (i = 0; i < work->count; i++) {
            if (work->rows[i].motion.frame < work->rows[i].motion.duration) {
                return 0;
            }
        }
        count = func_00353b50(roster);
        if (work->count != count) {
            if (count < work->count) {
                s32 changed;
                for (changed = 0; changed < 4; changed++) {
                    if (work->rows[changed].id != roster[changed]) {
                        break;
                    }
                }
                panelPosition(&position, 640.0f, work->count, changed);
                row = (PartyPanelRow *)(panelSlot(changed * sizeof(PartyPanelRow), (u8 *)work) + 0x10);
                row->motion.start = row->motion.current;
                row->motion.end = position;
                row->motion.current = row->motion.start;
                row->motion.frame = 0;
                row->motion.duration = 8;
                work->changed = changed;
                work->state = 4;
            } else {
                s32 changed;
                s32 j;
                for (changed = 0; changed < 4; changed++) {
                    if (work->rows[changed].id != roster[changed]) {
                        break;
                    }
                }
                for (j = work->count; changed < j; j--) {
                    work->rows[j] = work->rows[j - 1];
                }
                work->count++;
                panelPosition(&position, 640.0f, work->count, changed);
                id = roster[changed];
                func_00362fd0((u8 *)&work->rows[changed].motion, &position.x, &position.x, 0);
                work->rows[changed].id = id;
                work->rows[changed].ready = 0;
                if (id != 0) {
                    sprintf(addedName, (const char *)D_0064E2A0, id);
                    work->rows[changed].sprite = func_0046aea0(addedName);
                    if (work->rows[changed].sprite == NULL) {
                        func_0046d730(D_0064E290, 0x166);
                    }
                }
                work->state = 2;
            }
        } else {
            s32 changed;
            for (changed = 0; changed < count; changed++) {
                if (work->rows[changed].id != roster[changed]) {
                    break;
                }
            }
            if (changed < count) {
                panelPosition(&position, 640.0f, work->count, changed);
                row = (PartyPanelRow *)(panelSlot(changed * sizeof(PartyPanelRow), (u8 *)work) + 0x10);
                row->motion.start = row->motion.current;
                row->motion.end = position;
                row->motion.current = row->motion.start;
                row->motion.frame = 0;
                row->motion.duration = 8;
                work->changed = changed;
                work->state = 5;
            }
        }
        break;
    }
    case 4: {
        s32 j;
        row = &work->rows[work->changed];
        if (!(row->motion.frame < row->motion.duration)) {
            removed = *row;
            work->count--;
            for (j = work->changed; j < work->count; j++) {
                work->rows[j] = work->rows[j + 1];
            }
            work->rows[j] = removed;
            work->rows[j].id = 0;
            work->rows[j].ready = 0;
            if (work->rows[j].sprite != NULL) {
                func_0046b0d0(work->rows[j].sprite);
                work->rows[j].sprite = NULL;
            }
            removedPosition = work->rows[j].motion.current;
            func_00362fd0((u8 *)&work->rows[j].motion, &removedPosition.x, &removedPosition.x, 0);
            {
                s32 i;
                for (i = 0; i < work->count; i++) {
                    panelPosition(&shiftedPosition, (f32)565, work->count, i);
                    func_00362fd0((u8 *)&work->rows[i].motion, NULL, &shiftedPosition.x, 8);
                }
            }
            work->state = 3;
        }
        break;
    }
    case 5: {
        s32 changed;
        row = &work->rows[work->changed];
        if (!(row->motion.frame < row->motion.duration)) {
            func_00353b50(roster);
            row = &work->rows[work->changed];
            row->id = 0;
            row->ready = 0;
            if (row->sprite != NULL) {
                func_0046b0d0(row->sprite);
                row->sprite = NULL;
            }
            replacedPosition = row->motion.current;
            func_00362fd0((u8 *)&row->motion, &replacedPosition.x, &replacedPosition.x, 0);
            changed = work->changed;
            panelPosition(&position, 640.0f, work->count, changed);
            id = roster[changed];
            row = &work->rows[changed];
            func_00362fd0((u8 *)&row->motion, &position.x, &position.x, 0);
            row->id = id;
            row->ready = 0;
            if (id != 0) {
                sprintf(replacedName, (const char *)D_0064E2A0, id);
                row->sprite = func_0046aea0(replacedName);
                if (row->sprite == NULL) {
                    func_0046d730(D_0064E290, 0x166);
                }
            }
            work->state = 2;
        }
        break;
    }
    case 6:
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off


// FUN_003640F0
void func_003640f0(u8* arg0) {
    u8* obj = *(u8**)(arg0 + 0x38);
    s32 i;
    u8* p;
    u8* q;

    if (*(s32*)(obj + 0xC) != 0) {
        func_0046b0d0(*(void**)(obj + 0xC));
        *(s32*)(obj + 0xC) = 0;
    }
    for (i = 0; i < *(s16*)(obj + 0xA); i++) {
        p = obj + i * 0x28;
        q = p + 0x2C;
        if (*(s32*)(p + 0x2C) != 0) {
            func_0046b0d0(*(void**)(p + 0x2C));
            *(s32*)q = 0;
        }
    }
    (*jtbl_008873EC)(obj);
}


// FUN_003641A0
s32 func_003641a0(s32 arg0) {
    s32 r;
    u8* work;

    func_0044ea90(D_0064E290, 0x253);
    work = D_008873F4[0](1, 0xE0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064E290, 0x254);
    }
    r = (s32)func_00451fc0((void *)((s32)arg0), (const void *)(D_0064E2E0), 0xC7, 0, 0, func_00363610, func_003640f0, (u8 *)(work));
    if (r == 0) {
        func_0046d730(D_0064E290, 0x25E);
    }
    *(s32 *)(work + 0x4) = 0;
    memset(work + 0xB0, 0, 0x30);
    *(u8 **)(work + 0xB8) = (u8 *)func_00363540;
    *(u8 **)(work + 0xC0) = work;
    return r;
}

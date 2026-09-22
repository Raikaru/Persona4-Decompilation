/* Consolidated Persona 4 source units. */
/* Original translation unit cldDungeonIn.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/std/stddef.h"

extern u32 func_00452560(void *task);
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00268230(void *unused, void *task);
extern u8 D_007964F0[];
extern void func_002e1ef0(void *a);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0045a8d0(s32 a, s32 b);
extern void func_00106390(s32 a, s32 b);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *func_002e1db0(s32 a, s32 b, s32 c, s32 d);
extern void func_0045b2e0(s32 a);
extern u8 D_00638FC0[];
extern u8 D_0063B070[];

s32 func_00268870(u8 *arg0);
void func_00268920(u8 *task);

// FUN_00268920
void func_00268920(u8 *task) {
    u8 *s0 = (u8 *)func_00452560(task);
    func_002e1ef0((void *)**(s32 **)(s0 + 8));
    jtbl_008873EC[0](s0);
    func_0045a8d0(3, 0);
    func_00106390(0x1470, 0);
}

// FUN_00268870
s32 func_00268870(u8 *arg0)
{
    u8 *state;
    u8 *obj;

    state = (u8 *)func_00452560(arg0);
    obj = func_00460990();
    *(void **)(obj + 8) = (void *)func_00268230;
    *(u8 **)(obj + 0x10) = arg0;
    func_00460ac0(D_007964F0, obj);
    switch (*(s32 *)state) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        return -1;
    }
    return 0;
}
// FUN_00268990
s32 func_00268990(s32 arg0) {
    u8 *s0;
    u8 *v0;
    u8 **v1;
    s32 ret;

    func_0044ea90(D_00638FC0, 0x33D);
    s0 = D_008873F4[0](1, 0xC, 0x40000);
    *(s32 *)s0 = 0;
    v0 = func_002e1db0(0x10, 0, 0, 0);
    v1 = *(u8 ***)(v0 + 0x24);
    *v1 = v0;
    *(u8 ***)(s0 + 8) = v1;
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063B070), 0xF, 0, 0, func_00268870, func_00268920, (u8 *)(s0));
    func_0045b2e0(0x40);
    func_00106390(0x1470, 1);
    return ret;
}

typedef struct DungeonInColor { u8 r, g, b, a; } DungeonInColor;
typedef struct DungeonInRect { s32 x, y, width, height; } DungeonInRect;
typedef struct DungeonInEntry {
    u32 kind;
    f32 duration;
    u32 mode;
    f32 initial[4];
    f32 current[4];
    f32 previous[4];
    f32 target[4];
} DungeonInEntry;
typedef struct DungeonInNodeWork {
    u32 flags;
    u32 kind;
    u32 unknown08;
    u32 mode;
    f32 unknown10;
    f32 duration;
    f32 initial[4];
    f32 current[4];
    f32 previous[4];
    f32 target[4];
} DungeonInNodeWork;
typedef struct DungeonInList {
    u32 unknown00[4];
    u16 count;
} DungeonInList;
typedef struct DungeonInNode {
    u32 unknown00[5];
    DungeonInNodeWork *work;
} DungeonInNode;
typedef struct DungeonInWork {
    s32 state;
    s32 frame;
    DungeonInList **list;
} DungeonInWork;
extern void func_0045d6e0(u8 *, f32 *, f32, s32);
extern void func_001228a0(s32, s32, s32);
extern void func_00267b20(f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0025ea20(f32, f32, f32, s32, s32, s32, void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_0046a770(char *);
extern u8 *func_002e2170(u8 *, u8 *, s32);
extern void func_0046d730(const void *, s32);
extern void *func_0043f810(void *, const void *, u32);
extern void func_00267670(u8 **);
extern u8 D_005E5810[];

static inline f32 dungeonInBezier(f32 t, f32 start, f32 control1, f32 control2, f32 end)
{
    f32 u = 1.0f - t;
    f32 threeU = 3.0f * u;
    return start * (u * (u * u)) + control1 * (t * (threeU * u))
         + control2 * (t * (threeU * t)) + end * (t * (t * t));
}

/* measured: keep the entry base across the initial copy. The explicit byte
   offsets make the current-vector address a shared expression for both copies.
   Native b210 -O2 matches 1596/1600 bytes, with all 45 relocations and all 14
   owned data objects proved against retail; the remaining four bytes are zero. */
// FUN_00268230
void func_00268230(void *unused, void *task)
{
    DungeonInColor color;
    DungeonInRect rect;
    DungeonInWork *work;
    s32 alpha;
    s32 frame;
    u32 i;
    f32 t, curve;
    DungeonInEntry *entry;
    DungeonInEntry *copyEntry;
    DungeonInNodeWork *nodeWork;
    f32 *initial;
    f32 *target;
    u32 kind, mode;
    f32 duration;

    work = (DungeonInWork *)func_00452560(task);
    switch (work->state) {
    case 0:
        {
            color = (DungeonInColor){0, 0, 0, 255};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0((u8 *)&color, (f32 *)&rect, 0.0f, 1);
        }
        if (++work->frame >= 15) {
            work->frame = 0;
            work->state = 1;
            func_001228a0(196, 196, 196);
        }
        break;
    case 1:
        {
            color = (DungeonInColor){0, 0, 0, 255};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0((u8 *)&color, (f32 *)&rect, 0.0f, 1);
        }
        frame = ++work->frame;
        if (frame < 41) {
            t = (f32)frame / 40.0f;
            curve = dungeonInBezier(t, 0.0f, 0.01f, 0.1f, 1.0f);
            func_00267b20(288.0f, 222.0f, 0.0f, 0xC4C4C4, 255,
                          1, 9, 0, 0, 0.0f + -45.0f + 70.0f * curve,
                          3.0f * curve, 3.0f * curve);
        } else {
            if (frame < 133) {
                color = (DungeonInColor){196, 196, 196, 255};
            } else {
                color = (DungeonInColor){196, 196, 196, 255};
            }
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0((u8 *)&color, (f32 *)&rect, 0.0f, 1);
        }
        alpha = 0;
        if (work->frame < 36) {
            alpha = 0;
        } else if (work->frame < 66) {
            alpha = (s32)((f32)(255 * (work->frame - 35)) / 30.0f);
        } else if (work->frame < 121) {
            alpha = 255;
        } else if (work->frame < 131) {
            alpha = (s32)(255.0f * (1.0f - (f32)(work->frame - 120) / 10.0f));
        }
        func_0025ea20(28.0f, -38.0f, 0.0f, 0xFFFFFF, (u8)alpha, 75,
                      func_0046a770((char *)D_005E5810), 1, 0, 0, 0.0f,
                      15.999990f, 15.999f);
        if (work->frame == 17) {
            DungeonInEntry entries[19] = {
                {18, 30.0f, 0, {0.0f, 0.0f, 60.0f, 0.0f}, {0.0f, 0.0f, 60.0f, 0.100000001f}, {0.0f, 0.0f, 60.0f, 0.100000001f}, {0.0f, 0.0f, 60.0f, 7.0f}},
                {0, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {1, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {2, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {3, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {4, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {5, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {6, 20.0f, 0, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {7, 20.0f, 0, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {10, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {11, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {12, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {13, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {14, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {15, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {16, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {17, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {9, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {8, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}}
            };
            for (i = 0; i < 19; i++) {
                entry = &entries[i];
                mode = entry->mode;
                duration = entry->duration;
                kind = entry->kind;
                nodeWork = ((DungeonInNode *)func_002e2170((u8 *)*work->list,
                    (u8 *)(u32)((*work->list)->count + 1), 0x58))->work;
                nodeWork->flags |= 1;
                if (nodeWork == NULL) func_0046d730(D_00638FC0, 86);
                initial = entry->initial;
                if (initial == NULL) func_0046d730(D_00638FC0, 87);
                target = entry->target;
                if (target == NULL) func_0046d730(D_00638FC0, 88);
                nodeWork->kind = kind;
                nodeWork->duration = duration;
                nodeWork->mode = mode;
                copyEntry = &entries[(s32)i];
                func_0043f810(nodeWork->initial, initial, 16);
                func_0043f810(nodeWork->current,
                    (u8 *)copyEntry + offsetof(DungeonInEntry, current), 16);
                func_0043f810(nodeWork->previous,
                    (u8 *)copyEntry + offsetof(DungeonInEntry, current), 16);
                func_0043f810(nodeWork->target, target, 16);
            }
        }
        func_00267670((u8 **)work->list);
        if (work->frame >= 170) {
            work->frame = 0;
            work->state = 2;
        }
        break;
    case 2:
        t = (f32)work->frame / 20.0f;
        {
            color = (DungeonInColor){196, 196, 196, (u8)(255.0f * (1.0f - t))};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0((u8 *)&color, (f32 *)&rect, 0.0f, 1);
        }
        if (++work->frame >= 20) {
            work->state = 3;
            work->frame = 0;
        }
        break;
    case 4:
        break;
    }
}

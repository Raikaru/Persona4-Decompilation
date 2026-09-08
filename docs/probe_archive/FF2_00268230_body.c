/* Fresh complete reference; production remains ASM.
 * 1596/1600 bytes; 45 resolved relocations; 13 executable words / 46 bytes differ
 * only at +0x480..+0x4B0. Four zero alignment bytes; all 14 constant objects
 * and the full 1444-byte entry table match.
 * Owner context must use u32 func_00452560(void *task) and pass the real task
 * at its existing getter consumers. This is not a standalone translation unit.
 */
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
extern void func_0045d6e0(void *, void *, f32, s32);
extern void func_001228a0(s32, s32, s32);
extern void func_00267b20(f32, f32, f32, u32, u8, s32, s32, s32, s32, f32, f32, f32);
extern void func_0025ea20(f32, f32, f32, u32, u8, s32, void *, s32, s32, s32, f32, f32, f32);
extern void *func_0046a770(const void *);
extern DungeonInNode *func_002e2170(DungeonInList *, s32, s32);
extern void func_0046d730(const void *, s32);
extern void *func_0043f810(void *, const void *, u32);
extern void func_00267670(DungeonInList **);
extern u8 D_005E5810[];

static inline f32 dungeonInBezier(f32 t, f32 start, f32 control1, f32 control2, f32 end)
{
    f32 u = 1.0f - t;
    f32 threeU = 3.0f * u;
    return start * (u * (u * u)) + control1 * (t * (threeU * u))
         + control2 * (t * (threeU * t)) + end * (t * (t * t));
}

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
            func_0045d6e0(&color, &rect, 0.0f, 1);
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
            func_0045d6e0(&color, &rect, 0.0f, 1);
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
            func_0045d6e0(&color, &rect, 0.0f, 1);
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
                      func_0046a770(D_005E5810), 1, 0, 0, 0.0f,
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
                nodeWork = func_002e2170(*work->list, (*work->list)->count + 1, 0x58)->work;
                nodeWork->flags |= 1;
                if (nodeWork == NULL) func_0046d730(D_00638FC0, 86);
                initial = entry->initial;
                if (initial == NULL) func_0046d730(D_00638FC0, 87);
                target = entry->target;
                if (target == NULL) func_0046d730(D_00638FC0, 88);
                nodeWork->kind = kind;
                nodeWork->duration = duration;
                nodeWork->mode = mode;
                func_0043f810(nodeWork->initial, initial, 16);
                func_0043f810(nodeWork->current, entries[i].current, 16);
                func_0043f810(nodeWork->previous, entries[i].current, 16);
                func_0043f810(nodeWork->target, target, 16);
            }
        }
        func_00267670(work->list);
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
            func_0045d6e0(&color, &rect, 0.0f, 1);
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

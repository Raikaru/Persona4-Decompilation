/* measured 2026-09-26 (campaign g1 round 4): fresh rewrite, 8 words (obj 1444B + zero padding,
   window 1456B). The only residual is a saved-register swap: retail keeps the loop index in $s5
   and w->frame in $s3, and this body has them the other way round. Declaration-order sweeps,
   a masked s32 index, block-scoped index/frame and the permuter (1617 compiles) all stay at 8.
   Levers: struct copies for the 0x20/0x34/0x40 blocks, switch statements for the type/mode tests
   (cases written 0,1,0xD,6,7 emit retail's 7,6,0xD,1,0 chain), inline scale helpers, s32 count,
   and the 0.0125f/0.8f literals for fGpffff8354/fGpffff838c. See
   docs/probe_archive/Attach_001d53e0_20260926_body.c. */
typedef struct BtlAttachV3
{
    f32 x;
    f32 y;
    f32 z;
} BtlAttachV3;

typedef struct BtlAttachV4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} BtlAttachV4;

typedef struct BtlAttachEntry
{
    u8 state;      // 0x00
    u8 pad01[3];
    u32 id;        // 0x04
    u8 type;       // 0x08
    u8 pad09[5];
    u16 kind;      // 0x0E
    u32 start;     // 0x10
    u8 pad14[4];
} BtlAttachEntry; // 0x18

typedef struct BtlAttachWork
{
    u8 *owner;            // 0x00
    u8 *table;            // 0x04
    u32 flags;            // 0x08
    u32 frame;            // 0x0C
    u32 color;            // 0x10
    u8 level;             // 0x14
    u8 pad15[3];
    u8 *unit;             // 0x18
    u8 *target;           // 0x1C
    BtlAttachV3 scale;    // 0x20
    f32 radius;           // 0x2C
    f32 height;           // 0x30
    BtlAttachV3 pos;      // 0x34
    BtlAttachV4 center;   // 0x40
    f32 size;             // 0x50
    u16 count;            // 0x54
    u8 pad56[2];
    s32 *handles;         // 0x58
} BtlAttachWork;

static inline f32 btlAttachEffectScale(u8 *unit)
{
    f32 s;

    s = 0.0125f * (0.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C) + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C))));
    if (!(s <= 2.5f)) {
        s = 2.5f;
    } else if (s < 0.8f) {
        s = 0.8f;
    }
    return s;
}

static inline f32 btlAttachFieldScale(u8 *unit)
{
    f32 s;

    if (*(s32 *)(iGpffffb3ac + 0x314) == 0) {
        return 4.25f;
    }
    s = 2.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)) / 100.0f;
    if (!(s <= 5.0f)) {
        s = 5.0f;
    } else if (s < 2.0f) {
        s = 2.0f;
    }
    return s;
}

void func_001d53e0(s32 arg0)
{
    extern void func_001fc2c0(u8 *a0, u8 *a1);
    extern u32 func_00485c80(u32 a0);
    extern s32 func_004861f0(u8 *a0, f32 *a1);
    extern void func_00486330(s32 a0, u8 *a1);
    extern void func_00486400(u8 *a0, f32 a1);
    extern void (*D_00609500[])(u8 *a0, u8 *a1, u8 *a2, u8 *a3);
    s32 count;
    BtlAttachWork *w;
    u16 i;
    u32 color;
    s32 created;
    u32 frame;
    s32 *handles;
    BtlAttachEntry *entry;
    u8 *unit;
    f32 unitCenter[4];
    f32 targetCenter[4];
    f32 trans[4];
    f32 rot[4];

    w = (BtlAttachWork *)arg0;
    unit = w->unit;
    color = w->color;
    if (w->flags & 0x800) {
        return;
    }
    if ((color & 0xFF000000) == 0) {
        return;
    }
    frame = w->frame;
    if (frame == 0 || ((w->flags & 0x1000) && frame == *(u32 *)(w->owner + 0x320)) || (w->flags & 0x100)) {
        w->scale = *(BtlAttachV3 *)(unit + 0x80);
        w->radius = *(f32 *)(unit + 0x8C);
        w->height = *(f32 *)(unit + 0x90);
        w->pos = *(BtlAttachV3 *)(unit + 4);
        if (unit == w->target || (*(u32 *)(unit + 0x9C) & 0x2000)) {
            w->center = *(BtlAttachV4 *)(unit + 0x1C);
        } else if (unit[0xA2] == w->target[0xA2] && unit[0xA2] == 1) {
            w->center = *(BtlAttachV4 *)(unit + 0x1C);
        } else {
            btlUnitGetSphereWorldCenter(unit, unitCenter);
            btlUnitGetSphereWorldCenter(w->target, targetCenter);
            func_001ec1c0(&w->center, unitCenter, targetCenter);
        }
        w->size = *(f32 *)(unit + 0x2C);
    }
    func_001fc2c0(w->unit, w->target);
    handles = w->handles;
    count = w->count;
    entry = (BtlAttachEntry *)(w->table + 0x14);
    for (i = 0; i < count; i++, entry++, handles++) {
        if (!(entry->start < frame)) {
            continue;
        }
        if (entry->state == 0xFE) {
            continue;
        }
        if (*handles == 0) {
            u8 mode;

            if ((*(u16 *)(w->owner + 0x630) & 4) && entry->state != 0xFD) {
                *handles = entry->id;
                created = 0;
                entry->state = 0xFD;
            } else {
                *handles = func_00485c80(entry->id);
                created = 1;
            }
            mode = w->table[0x10];
            if (mode != 0 && unit != NULL) {
                f32 s;

                switch (entry->type) {
                case 0:
                case 1:
                case 0xD:
                case 6:
                case 7:
                    switch (mode) {
                    case 1:
                        if (!(w->flags & 0x20000)) {
                            s = btlAttachEffectScale(unit);
                        } else {
                            s = btlAttachFieldScale(unit);
                        }
                        break;
                    default:
                        s = btlAttachEffectScale(w->target);
                        break;
                    }
                    func_00486400((u8 *)*handles, s);
                    break;
                }
            }
            if (created) {
                continue;
            }
        }
        if (entry->kind == 1) {
            if (w->flags & 0x1E) {
                continue;
            }
            if (w->level < 0x32) {
                continue;
            }
        }
        if (!(w->flags & 0x20000)) {
            D_00609500[entry->type]((u8 *)w, unit, (u8 *)entry, (u8 *)trans);
        } else {
            if (*(s32 *)(iGpffffb3ac + 0x314) != 0) {
                trans[0] = *(f32 *)(unit + 4);
                trans[1] = *(f32 *)(unit + 8);
                trans[2] = *(f32 *)(unit + 0xC);
            } else {
                trans[0] = 0.0f;
                trans[1] = 0.0f;
                trans[2] = -85.0f;
            }
            trans[3] = 0.0f;
        }
        func_004861f0((u8 *)*handles, trans);
        func_001d5130((u8 *)w, unit, (u8 *)entry, (u8 *)rot);
        func_00486330(*handles, (u8 *)rot);
        func_004865c0(*handles, color);
        func_00485630(*handles);
    }
    w->frame++;
}

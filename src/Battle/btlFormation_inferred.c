#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern void btlTargetBlendVectors(void *out, void *first, void *second);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern s32 mdlComputeIndexedAttachMatrix();
extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern void func_00485870(s32 arg0);
extern s32 TnGetTableBase(void);
extern void TnSetTableBase(s32 arg0);
extern void func_004865c0(u8 *arg0, s32 arg1);
extern void func_00485630(u8 *arg0);
extern void func_001d53e0(s32 arg0);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *arg0, u8 *arg1);
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 *kwlnGetCamera();
extern void func_003e8110(u8 *arg0);
extern void func_003e8120(u8 *arg0);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();









typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d4eb0-001d5b20 */

extern s32 btlCameraFindFormationForCounts(u8 *arg0);
typedef void BtlAttachPositionCallback(u8 *work, u8 *unit, u8 *entry, f32 *position);
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
    u8 *resource;  // 0x04: template to clone, or an existing effect instance
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
    u8 **handles;         // 0x58
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
/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
// FUN_001D4EB0
void btlFormationAttachPosition(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3)
{
    struct Frame {
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6c;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 pad7c;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 pad8c;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 pad9c;
    } frame;
    u8 *temp_16;
    u8 *temp_2;
    u32 temp_4;
    f32 temp_f20;

    temp_16 = arg2 + 8;
    if ((*(u8 *)(arg2 + 0xA) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 != *(s32 *)(arg0 + 0xC))) {
        arg3[0] = *(f32 *)(arg0 + 0x5C);
        arg3[1] = *(f32 *)(arg0 + 0x60);
        arg3[2] = *(f32 *)(arg0 + 0x64);
        goto end;
    }

    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        btlUnitGetSphereWorldCenter(arg1, &frame.value90);
    } else if (mdlComputeIndexedAttachMatrix(*(u8 **)(arg1 + 0xA00),
                             *(u16 *)(temp_16 + 4),
                             &frame.value90) == 0) {
        frame.value70 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
        frame.value74 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
        frame.value78 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
        RtQuatTransformVectors(&frame.value60, &frame.value70, 1, arg0 + 0x40);
        frame.value90 = frame.value60 + *(f32 *)(arg0 + 0x34);
        frame.value94 = frame.value64 + *(f32 *)(arg0 + 0x38);
        frame.value98 = frame.value68 + *(f32 *)(arg0 + 0x3C);
    }

    arg3[0] = frame.value90;
    arg3[1] = frame.value94;
    arg3[2] = frame.value98;
    temp_4 = *(u16 *)(temp_16 + 6);
    if (temp_4 != 0) {
        if (temp_4 >= 0) {
            temp_f20 = (f32)temp_4;
        } else {
            temp_4 = (temp_4 >> 1) | (temp_4 & 1);
            temp_f20 = (f32)temp_4;
            temp_f20 = temp_f20 + temp_f20;
        }
        temp_2 = *(u8 **)(kwlnGetCamera() + 4);
        frame.value80 = *(f32 *)(temp_2 + 0x40) - frame.value90;
        frame.value84 = *(f32 *)(temp_2 + 0x44) - frame.value94;
        frame.value88 = *(f32 *)(temp_2 + 0x48) - frame.value98;
        RwV3dNormalize(&frame.value80, &frame.value80);
        arg3[0] = arg3[0] - frame.value80 * temp_f20;
        arg3[1] = arg3[1] - frame.value84 * temp_f20;
        arg3[2] = arg3[2] - frame.value88 * temp_f20;
    }

    if ((*(u8 *)(temp_16 + 2) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 == *(s32 *)(arg0 + 0xC))) {
        *(f32 *)(arg0 + 0x5C) = arg3[0];
        *(f32 *)(arg0 + 0x60) = arg3[1];
        *(f32 *)(arg0 + 0x64) = arg3[2];
    }
end:
    ;
}

// FUN_001D5130
void func_001d5130(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    struct Frame {
        f32 input[16];
        f32 output[16];
        f32 vector[4];
    } frame;
    u8 type;
    u8 *entry;
    s32 flags;
    s32 lookup;
    s32 lookup_offset;
    u8 *lookup_base;

    extern void RtQuatTransformVectors(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
    extern f32 func_0044b950(f32 arg0, f32 arg1);
    extern s32 mdlCopyIndexedMatrix(u8 *arg0, s32 arg1, f32 *arg2);
    extern void func_0048a980(f32 *arg0);
    extern void effMiscEulerToQuatVU(f32 arg0, f32 arg1, f32 arg2);

    entry = arg2 + 8;
    type = *(u8 *)(arg2 + 8);
    switch (type) {
    case 0:
        RtQuatTransformVectors(frame.vector, (f32 *)D_0060A0F0, 1, arg0 + 0x40);
        if (frame.vector[0] != 0.0f)
            goto case0_nonzero;
        if (frame.vector[2] == 0.0f)
            goto case0_zero;
case0_nonzero:
        effMiscEulerToQuatVU(0.0f,
                      func_0044b950(frame.vector[0], frame.vector[2]),
                      0.0f);
        __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
        goto case0_done;
case0_zero:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
case0_done:
        break;
    case 2:
    case 3:
    case 4:
    case 0xC:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 1:
    case 0xD:
        flags = *(s32 *)(arg1 + 0x98);
        if ((flags & 2) == 0)
            goto case1_no_flags;
        if (mdlCopyIndexedMatrix(*(u8 **)(arg1 + 0xA00),
                          *(u16 *)(entry + 4), frame.input) == 0)
            goto case1_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            func_0048a980(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
        break;
case1_failure:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
case1_no_flags:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 8:
    case 9:
        flags = *(s32 *)(arg1 + 0x98);
        if ((flags & 2) != 0) {
            lookup_offset = 12 * (type == 8);
            lookup_base = *(u8 **)(arg1 + 0xA00);
            lookup_base += 0x290;
            lookup = *(s32 *)(lookup_base + lookup_offset);
            if (lookup == 0)
                break;
            if (mdlCopyIndexedMatrix((u8 *)lookup,
                              *(u16 *)(entry + 4), frame.input) == 0)
                goto case8_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            func_0048a980(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(arg3) : "memory");
            break;
case8_failure:
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        } else {
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        }
        break;
    case 7:
    case 0xA:
    case 0xB:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg3) : "memory");
        break;
    case 5:
    case 6:
        break;
    default:
        break;
    }
}

// FUN_001D53E0
void func_001d53e0(s32 arg0)
{
    extern void func_001fc2c0(u32 a0, u32 a1);
    extern void func_004861f0(u8 *a0, f32 *a1);
    extern void func_00486330(u8 *a0, u8 *a1);
    extern void func_00486400(u8 *a0, f32 a1);
    extern BtlAttachPositionCallback *D_00609500[];
    s32 count;
    BtlAttachWork *w;
    u32 frame;
    u32 now;
    u16 i;
    u32 color;
    s32 created;
    u8 **handles;
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
            btlTargetBlendVectors(&w->center, unitCenter, targetCenter);
        }
        w->size = *(f32 *)(unit + 0x2C);
    }
    func_001fc2c0((u32)w->unit, (u32)w->target);
    now = (u32)frame;
    handles = w->handles;
    count = w->count;
    entry = (BtlAttachEntry *)(w->table + 0x14);
    for (i = 0; i < count; i++, entry++, handles++) {
        if (!(entry->start < now)) {
            continue;
        }
        if (entry->state == 0xFE) {
            continue;
        }
        if (*handles == 0) {
            u8 mode;

            if ((*(u16 *)(w->owner + 0x630) & 4) && entry->state != 0xFD) {
                *handles = entry->resource;
                created = 0;
                entry->state = 0xFD;
            } else {
                *handles = func_00485c80(entry->resource);
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
                    func_00486400(*handles, s);
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
            D_00609500[entry->type]((u8 *)w, unit, (u8 *)entry, trans);
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
        func_004861f0(*handles, trans);
        func_001d5130((u8 *)w, unit, (u8 *)entry, (u8 *)rot);
        func_00486330(*handles, (u8 *)rot);
        func_004865c0(*handles, (s32)color);
        func_00485630(*handles);
    }
    w->frame++;
}

/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: func_001d5990 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_001D5990
void func_001d5990(void)
{
    struct Frame {
        f32 sp10;
        f32 sp14;
        f32 sp18;
        s32 sp1C;
        f32 sp20;
        f32 sp24;
        f32 sp28;
        f32 pad2C;
        f32 sp30;
        f32 sp34;
        f32 sp38;
        f32 pad3C;
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 pad4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
    } frame;
    u32 *source;
    u32 *destination;
    s32 count;
    u32 first;
    u32 second;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    extern f32 fGpffff8444;
    extern f32 fGpffff8448;
    extern f32 fGpffff844c;
    extern f32 fGpffff8450;
    extern f32 fGpffff8454;
    extern f32 fGpffff8458;
    extern f32 fGpffff845c;
    extern f32 fGpffff8460;
    extern f32 fGpffff8464;
    extern f32 fGpffff8468;
    extern f32 fGpffff846c;
    extern f32 fGpffff8470;
    extern f32 fGpffff8474;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;

    func_003e8110(kwlnGetCamera());
    source = (u32 *)(*(u8 **)(kwlnGetCamera() + 4) + 0x10);
    destination = (u32 *)D_008813B0;
    count = 8;
    do {
        first = source[0];
        second = source[1];
        source += 2;
        count--;
        destination[0] = first;
        destination[1] = second;
        destination += 2;
    } while (count > 0);
    frame.sp10 = fGpffff8444;
    frame.sp14 = fGpffff8448;
    frame.sp18 = fGpffff844c;
    frame.sp20 = fGpffff8450;
    frame.sp24 = fGpffff8454;
    frame.sp28 = fGpffff8458;
    frame.sp30 = fGpffff845c;
    frame.sp34 = fGpffff8460;
    frame.sp38 = fGpffff8464;
    frame.sp40 = 0;
    frame.sp44 = 0;
    frame.sp48 = 0;
    frame.sp1C = 3;
    frame.sp50 = fGpffff8468;
    frame.sp54 = fGpffff846c;
    frame.sp58 = fGpffff8470;
    temp1 = frame.sp50;
    temp2 = frame.sp54;
    temp3 = frame.sp58;
    frame.sp40 = temp1;
    frame.sp44 = temp2;
    frame.sp48 = temp3;
    func_003e9cb0(*(s32 *)(kwlnGetCamera() + 4), (u8 *)&frame.sp10, 0);
    func_003e8120(kwlnGetCamera());
}

/* measured: restore optimization_level 2 after func_001d5990. */
/* measured: func_001d5b20 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001D5AC0
void btlFormationCameraUpdate(void) {
    func_003e8110(kwlnGetCamera());
    func_003e9cb0(*(s32 *)(kwlnGetCamera() + 4), D_008813B0, 0);
    func_003e8120(kwlnGetCamera());
}

// FUN_001D5B20
void btlFormationCameraTaskStart(u8 *arg0)
{
    s32 old_state;
    u8 **entries;
    s32 count;
    s32 index;
    u8 *task;

    if ((*(s32 *)(arg0 + 8) & 0x400) != 0) {
        return;
    }
    entries = *(u8 ***)(arg0 + 0x58);
    count = (u16)(*(u16 *)(arg0 + 0x54) & 0xFFFF);
    if ((*(s32 *)(arg0 + 8) & 0x8000) == 0) {
        index = 0;
        count = (u16)(count & 0xFFFF);
        while ((u16)index < count) {
            if (*entries != NULL) {
                func_00485870((s32)*entries);
            }
            index = (index + 1) & 0xFFFF;
            entries++;
        }
        return;
    }
    old_state = TnGetTableBase();
    TnSetTableBase((s32)D_005DC824);
    task = PrimAllocQueueNode();
    *(s32 *)(task + 0) = 0;
    *(s32 *)(task + 4) = 0;
    *(void (**)(void))(task + 8) = func_001d5990;
    *(u8 **)(task + 0x10) = iGpffffb3ac;
    PrimAppendNode(D_00794AE0, task);
    index = 0;
    count = (u16)(count & 0xFFFF);
    while ((u16)index < count) {
        if (*entries != NULL) {
            func_00485870((s32)*entries);
        }
        index = (index + 1) & 0xFFFF;
        entries++;
    }
    TnSetTableBase(old_state);
    task = PrimAllocQueueNode();
    *(s32 *)(task + 0) = 0;
    *(s32 *)(task + 4) = 0;
    *(void (**)(void))(task + 8) = btlFormationCameraUpdate;
    *(u8 **)(task + 0x10) = iGpffffb3ac;
    PrimAppendNode(D_00794C00, task);
}


#include "type.h"
#include "rw_camera_internal.h"
#include "sdk_task_registration.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
extern s32 kwlnTaskGetTaskByName();
extern u8 iGpffffa7a8;

/* Old-style declaration: the donor source called this without a prototype, and
 * several call sites below pass an argument (a0 is set by the caller), which a
 * (void) prototype would forbid. */
s32 *kwlnTaskGetWork();
extern void (*jtbl_008873EC[])(void *);

void chkmemAllocSiteTag(const void *file, s32 line);
void kAssertFail(const void *file, s32 line);
s32 kwlnTaskIsLinked(s32 target);
s32 H_Cdvd_IsFileLoaded(s32 cdvd);
void H_Cdvd_Destroy(s32 cdvd);
s32 strcmp(s32 *input, s32 secondInput);
s32 strcpy(s32 *input, s32 secondInput);
s32 evtMemAccount(s32 slot, s32 byteCount);
void func_00440b68(const void *input, const void *secondInput, s32 thirdInput);
s32 H_Cdvd_AcquireDirectory(void *path, s32 flags);
u8 *H_Cdvd_LookupRequest(void *pathAddress, u32 *slot);
s32 scrStartProcedureIndex(s32 priority, u8 *header, s32 procedureIndex);
u8 *kwlnGetColorRgb(void);
void *kwlnGetCamera(void);

s32 evtTintTaskUpdate(u8 *unusedTask);
void evtTintTaskDestroy(u8 *unusedTask);
s32 evtScriptLoadStep(u8 *unusedTask);
void evtScriptLoadDestroy(u8 *unusedTask);
void evtTintTaskKill(void);
void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
extern s32 iGpffffba48;

/* Scalars (complete types) address gp-relative; strings/arrays use absolute
 * lui/addiu addressing. D_00763898 and the D_00764Bxx bytes are GPREL16 in
 * retail, so they must stay scalar-typed; the others are absolute. */
extern s32 D_00763898;
extern s32 D_007638A0;
extern u8 D_00764B3C;
extern u8 D_00764B40;
extern u8 D_00764B44;
extern f32 D_00764B5C;
extern u8 D_00748340[];
extern u8 D_0063C638[];
extern u8 D_0063C690[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef int (*code)();
extern code DAT_008873ec_abs[];



/* Event blur records share a fixed prefix through the six signed tenths at +0x2C. */
typedef struct EvtBlurFilterRecord {
    u8 pad00[0x10];
    s16 unk10;
    u8 pad12, unk13;
    s16 unk14, unk16;
    u8 packedOptions[0x13];
    u8 unk2B;
    s16 unk2C, unk2E, unk30, unk32, unk34, unk36;
} EvtBlurFilterRecord;
/* Direct and copied filter providers keep their reference object in this common prefix. */
typedef struct EvtBlurFilter { u8 pad00[0x28]; s32 reference; } EvtBlurFilter;
/* Type-three's 44-byte template has integer endpoints and a float weight. */
typedef struct EvtBlurFilterExtra { s32 mode, first; f32 weight; u8 pad0C[0x1C]; s32 last; } EvtBlurFilterExtra;

typedef struct { f32 x, y, z; } SVec3;
/* The serialized header precedes a variable-length 3n+1 point array. */
typedef struct EvtBlurPointTable { u8 mode, count, pad02[2]; SVec3 points[1]; } EvtBlurPointTable;
typedef unsigned int EvtU128 __attribute__((mode(TI)));
u8 *effBlurFilterCreateRefObj(u16 *object, u16 slot);
extern u8 D_0063C648[];

typedef struct {
    u8 type;
    u8 pad01[3];
    u32 color0;
    u32 color1;
    u32 color2;
    f32 alpha0;
    u32 color3;
    f32 alpha1;
    u8 pad1C[8];
    s32 value24;
    s32 value28;
    f32 value2C;
    f32 value30;
    u8 pad34[4];
    f32 value38;
    f32 value3C;
    u8 pad40[0x24];
    f32 value64;
    f32 value68;
    u8 pad6C[0x24];
    f32 value90;
    f32 value94;
    u8 pad98[0x20];
    s32 valueB8;
    u8 active;
    u8 padBD[3];
} EvtFilterParams;

typedef struct {
    EvtFilterParams params;
    u8 extra[0x24];
    u8 padE4[0xC];
} EvtFilter2;

typedef struct {
    EvtFilterParams params;
    u8 extra[0x18];
    u8 padD8[4];
    s32 argument;
} EvtFilter1;

typedef struct {
    EvtFilterParams params2;
    EvtFilterParams params1;
    u8 extra2[0x24];
    u8 pad1A4[0xC];
    u8 extra1[0x18];
    u8 pad1C8[8];
    EvtFilter2 filter2;
    EvtFilter1 filter1;
} EvtFilterFrame;



// Allocates the blur filter's 0x130-byte state block once, when its slot is empty, and records it in the slot [inferred].
// FUN_0028D110
void evtBlurFilterEnsureBlock(s32 *slot) {
    s32 *work;

    if (slot[0x10] != 0) {
        return;
    }
    chkmemAllocSiteTag(D_00748340, 0x52);
    work = (s32 *)D_008873F4[0](1, 0x130, 0x40000);
    evtMemAccount(0xA, 0x130);
    slot[0x10] = (s32)work;
    if (work == 0) {
        kAssertFail(D_0063C638, 0x1068);
    }
}

/* measured: without opt_loop_invariants on, MWCC rematerializes the loop
 * comparison constant (addiu v1,zero,1) inside the body instead of the
 * preheader, shifting every temp register (nd 18). */
#pragma opt_loop_invariants on



// Copies the blur filter's point table (count = 3n+1 entries) into the destination, reversed when arg2 is 1 [inferred].
/* Point tables are packed 3n+1 triples after a four-byte byte header; preserve the vector-copy access widths. */
// FUN_0028D1B0
void evtBlurFilterCopyPoints(u8 *source, u8 *destination, s32 reverse) {
    /* Four-byte headers precede 12-byte positions; typed variable-length tables changed MWCC codegen. */
    u8 segmentCount;
    s32 pointCount;
    s32 pointIndex;

    if (source[0] != 0) {
        return;
    }
    segmentCount = source[1];
    pointCount = segmentCount * 3 + 1;
    destination[0] = segmentCount;
    pointIndex = 0;
    while (pointIndex < pointCount) {
        if (reverse == 1) {
            ((EvtBlurPointTable *)destination)->points[pointIndex] = ((EvtBlurPointTable *)source)->points[(pointCount - 1) - pointIndex];
        } else {
            ((EvtBlurPointTable *)destination)->points[pointIndex] = ((EvtBlurPointTable *)source)->points[pointIndex];
        }
        pointIndex++;
    }
}
/* measured: see annotation above (func_0028d1b0). */
#pragma opt_loop_invariants off

// Blur filter task update: advances the direct or copied blur filter and bumps its frame counter (same logic as effBlurFilterTaskUpdate).
// FUN_0028D280
s32 evtBlurFilterTaskUpdate(u8 *unusedTask) {
    s32 *work;
    s32 kind;

    work = kwlnTaskGetWork();
    kind = work[0];
    switch (kind) {
    case 0:
        effBlurFilterDirectAdvanceAndSync((u8 *)work[1]);
        work[2] = work[2] + 1;
        break;
    case 1:
        effBlurFilterCopiedAdvanceAndSync((u8 *)work[1]);
        work[2] = work[2] + 1;
        break;
    }
    return 0;
}

// Blur filter task destroy: destroys the direct or copied blur filter, then frees the work block (same logic as effBlurFilterTaskDestroy).
// FUN_0028D310
void evtBlurFilterTaskDestroy(u8 *unusedTask) {
    s32 *work;
    s32 kind;

    work = kwlnTaskGetWork();
    kind = work[0];
    switch (kind) {
    case 0:
        effBlurFilterDirectDestroy((void *)work[1]);
        break;
    case 1:
        effBlurFilterCopiedDestroy((void *)work[1]);
        break;
    }
    jtbl_008873EC[0](work);
}



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// Intent: Event command blur-filter task for types 1 and 2: builds the filter parameters from the record (mode, colours, alpha, timing) and creates the task under arg0 [inferred]
/* Only the filter reference slot at +0x28 is known here; the direct/copy filter allocation layout remains opaque. */
// FUN_0028D390
void evtCreateBlurFilterTask(s32 parentTask, s32 type, u8 *record)
{
    /* Packed RGB/options occupy +0x18..0x2B and signed halfwords +0x10/+0x2C..0x36; typed access changed MWCC allocation. */
    EvtFilterFrame frame;
    s32 mode1;
    s32 mode2;
    u8 *filter2;
    s32 *task1;
    s32 *task2;

    switch (type) {
    case 1:
        mode1 = 0;
        if (record[0x1B] & 1) {
            mode1 = 1;
            if (record[0x1B] & 2) {
                mode1 = 2;
            }
        }

        {
            u8 *clearCursor;
            s32 remaining;

            clearCursor = (u8 *)&frame.params1;
            remaining = sizeof(frame.params1);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        frame.params1.type = mode1;
        frame.params1.color0 = (record[0x1A] << 16) | 0xFF000000 |
                               (record[0x19] << 8) | record[0x18];
        frame.params1.color1 = (record[0x26] << 16) | 0xFF000000 |
                               (record[0x25] << 8) | record[0x24];
        frame.params1.color2 = (record[0x1E] << 16) | 0xFF000000 |
                               (record[0x1D] << 8) | record[0x1C];
        frame.params1.alpha0 = (f32)record[0x1F] / 100.0f;
        frame.params1.color3 = (record[0x22] << 16) | 0xFF000000 |
                               (record[0x21] << 8) | record[0x20];
        frame.params1.alpha1 = (f32)record[0x23] / 100.0f;
        frame.params1.value24 = record[0x27];
        frame.params1.value28 = record[0x1B] >> 4;
        frame.params1.value2C = (f32)record[0x28] / 100.0f;
        frame.params1.value30 = (f32)record[0x29] / 100.0f;
        frame.params1.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        frame.params1.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        frame.params1.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        frame.params1.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        frame.params1.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        frame.params1.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        frame.params1.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;

        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;

            source = (EvtU128 *)&frame.params1;
            destination = (EvtU128 *)&frame.filter1.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }

        {
            u8 *clearCursor;
            s32 remaining;

            clearCursor = frame.extra1;
            remaining = sizeof(frame.extra1);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value0;
            u32 value1;
            s32 blocks;

            source = (u32 *)frame.extra1;
            destination = (u32 *)frame.filter1.extra;
            blocks = 3;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }

        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task1 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task1[0] = 0;
        task1[1] = (s32)effBlurFilterDirectCreate(1, &frame.filter1);
        task1[3] = frame.filter1.params.valueB8;
        (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task1));
        break;

    case 2:
        mode2 = 0;
        if (record[0x1B] & 1) {
            mode2 = 1;
            if (record[0x1B] & 2) {
                mode2 = 2;
            }
        }

        {
            u8 *clearCursor;
            s32 remaining;

            clearCursor = (u8 *)&frame.params2;
            remaining = sizeof(frame.params2);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        frame.params2.type = mode2;
        frame.params2.color0 = (record[0x1A] << 16) | 0xFF000000 |
                               (record[0x19] << 8) | record[0x18];
        frame.params2.color1 = (record[0x26] << 16) | 0xFF000000 |
                               (record[0x25] << 8) | record[0x24];
        frame.params2.color2 = (record[0x1E] << 16) | 0xFF000000 |
                               (record[0x1D] << 8) | record[0x1C];
        frame.params2.alpha0 = (f32)record[0x1F] / 100.0f;
        frame.params2.color3 = (record[0x22] << 16) | 0xFF000000 |
                               (record[0x21] << 8) | record[0x20];
        frame.params2.alpha1 = (f32)record[0x23] / 100.0f;
        frame.params2.value24 = record[0x27];
        frame.params2.value28 = record[0x1B] >> 4;
        frame.params2.value2C = (f32)record[0x28] / 100.0f;
        frame.params2.value30 = (f32)record[0x29] / 100.0f;
        frame.params2.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        frame.params2.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        frame.params2.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        frame.params2.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        frame.params2.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        frame.params2.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        frame.params2.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;

        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;

            source = (EvtU128 *)&frame.params2;
            destination = (EvtU128 *)&frame.filter2.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        frame.filter2.params.active = 1;

        {
            u8 *clearCursor;
            s32 remaining;

            clearCursor = frame.extra2;
            remaining = sizeof(frame.extra2);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value;
            s32 blocks;

            source = (u32 *)frame.extra2;
            destination = (u32 *)frame.filter2.extra;
            blocks = 9;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        frame.filter1.argument = record[0x2A];

        filter2 = effBlurFilterDirectCreate(2, &frame.filter2);
        ((EvtBlurFilter *)filter2)->reference =
            (s32)effBlurFilterCreateRefObj((u16 *)&frame.filter1.argument, 4);
        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task2 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task2[0] = 0;
        if (filter2 != NULL) {
            task2[1] = (s32)filter2;
        } else {
            task2[1] = (s32)effBlurFilterDirectCreate(2, &frame.filter2);
        }
        task2[3] = frame.filter2.params.valueB8;
        (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task2));
        break;
    }
}

/* Builds blur-filter tasks for the four event-command selectors 1, 2, 3, 5.
 * All four direct evtMain callers use those constants and consume the task
 * handle. Keep the actual constructor result as the return value; selectors
 * outside that caller contract have no specified return value.
 * Measured b210 -O2: 4560/4560 bytes. The const-pointer constructor interface
 * avoids retaining integer addresses across calls. opt_lifetimes preserves
 * the independent mode/task/filter roles. The 44-byte template copy keeps
 * its two qwords, doubleword tail, and final float on advancing cursors. */
// Intent: Blur-filter task builder for event command types 1, 2, 3 and 5: fills one filter parameter block per type and creates the task under arg0 [inferred]
// FUN_0028DC30
#pragma push
#pragma opt_lifetimes on
/* Only the filter reference slot at +0x28 is known here; the direct/copy filter allocation layout remains opaque. */
s32 evtCreateBlurFilterTaskSet(s32 parentTask, s32 type, u8 *record)
{
    /* Packed RGB/options occupy +0x18..0x2B and signed halfwords +0x10/+0x2C..0x36; typed access changed MWCC allocation. */
    extern u8 D_0063C660[];
    typedef struct { EvtFilterParams params; u8 extra[0x28]; } F28;
    typedef struct { EvtFilterParams params; u8 extra[0x2C]; } F2C;
    F28 typeOneFilter;
    F2C typeTwoFilter;
    F2C typeThreeFilter;
    F28 typeFiveFilter;
    u8 typeOneExtra[0x28];
    u8 typeTwoExtra[0x2C];
    u8 typeThreeExtra[0x2C];
    u8 typeFiveExtra[0x28];
    EvtFilterParams typeOneParams;
    EvtFilterParams typeTwoParams;
    EvtFilterParams typeThreeParams;
    EvtFilterParams typeFiveParams;
    s32 referenceKind;
    s32 mode;
    s32 *task;
    u8 *filter;

    switch (type) {
    case 1:
        mode = 0;
        if (record[0x1B] & 1) {
            mode = 1;
            if (record[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = (u8 *)&typeOneParams;
            remaining = sizeof(typeOneParams);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        typeOneParams.type = mode;
        typeOneParams.color0 = (record[0x1A] << 16) | 0xFF000000 | (record[0x19] << 8) | record[0x18];
        typeOneParams.color1 = (record[0x26] << 16) | 0xFF000000 | (record[0x25] << 8) | record[0x24];
        typeOneParams.color2 = (record[0x1E] << 16) | 0xFF000000 | (record[0x1D] << 8) | record[0x1C];
        typeOneParams.alpha0 = (f32)record[0x1F] / 100.0f;
        typeOneParams.color3 = (record[0x22] << 16) | 0xFF000000 | (record[0x21] << 8) | record[0x20];
        typeOneParams.alpha1 = (f32)record[0x23] / 100.0f;
        typeOneParams.value24 = record[0x27];
        typeOneParams.value28 = record[0x1B] >> 4;
        typeOneParams.value2C = (f32)record[0x28] / 100.0f;
        typeOneParams.value30 = (f32)record[0x29] / 100.0f;
        typeOneParams.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        typeOneParams.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        typeOneParams.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        typeOneParams.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        typeOneParams.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        typeOneParams.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        typeOneParams.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&typeOneParams;
            destination = (EvtU128 *)&typeOneFilter.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = typeOneExtra;
            remaining = sizeof(typeOneExtra);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value0;
            u32 value1;
            s32 blocks;
            source = (u32 *)typeOneExtra;
            destination = (u32 *)typeOneFilter.extra;
            blocks = 5;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        task[1] = (s32)effBlurFilterCopiedCreate(1, &typeOneFilter.params);
        task[3] = typeOneFilter.params.valueB8;
        return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task));
    case 2:
        mode = 0;
        if (record[0x1B] & 1) {
            mode = 1;
            if (record[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = (u8 *)&typeTwoParams;
            remaining = sizeof(typeTwoParams);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        typeTwoParams.type = mode;
        typeTwoParams.color0 = (record[0x1A] << 16) | 0xFF000000 | (record[0x19] << 8) | record[0x18];
        typeTwoParams.color1 = (record[0x26] << 16) | 0xFF000000 | (record[0x25] << 8) | record[0x24];
        typeTwoParams.color2 = (record[0x1E] << 16) | 0xFF000000 | (record[0x1D] << 8) | record[0x1C];
        typeTwoParams.alpha0 = (f32)record[0x1F] / 100.0f;
        typeTwoParams.color3 = (record[0x22] << 16) | 0xFF000000 | (record[0x21] << 8) | record[0x20];
        typeTwoParams.alpha1 = (f32)record[0x23] / 100.0f;
        typeTwoParams.value24 = record[0x27];
        typeTwoParams.value28 = record[0x1B] >> 4;
        typeTwoParams.value2C = (f32)record[0x28] / 100.0f;
        typeTwoParams.value30 = (f32)record[0x29] / 100.0f;
        typeTwoParams.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        typeTwoParams.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        typeTwoParams.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        typeTwoParams.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        typeTwoParams.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        typeTwoParams.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        typeTwoParams.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&typeTwoParams;
            destination = (EvtU128 *)&typeTwoFilter.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        typeTwoFilter.params.active = 1;
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = typeTwoExtra;
            remaining = sizeof(typeTwoExtra);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value;
            s32 blocks;
            source = (u32 *)typeTwoExtra;
            destination = (u32 *)typeTwoFilter.extra;
            blocks = 11;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        referenceKind = record[0x2A];
        filter = effBlurFilterCopiedCreate(2, &typeTwoFilter.params);
        ((EvtBlurFilter *)filter)->reference = (s32)effBlurFilterCreateRefObj((u16 *)&referenceKind, 4);
        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (filter != NULL) {
            task[1] = (s32)filter;
        } else {
            task[1] = (s32)effBlurFilterCopiedCreate(2, &typeTwoFilter.params);
        }
        task[3] = typeTwoFilter.params.valueB8;
        return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task));
    case 3:
        mode = 0;
        if (record[0x1B] & 1) {
            mode = 1;
            if (record[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = (u8 *)&typeThreeParams;
            remaining = sizeof(typeThreeParams);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        typeThreeParams.type = mode;
        typeThreeParams.color0 = (record[0x1A] << 16) | 0xFF000000 | (record[0x19] << 8) | record[0x18];
        typeThreeParams.color1 = (record[0x26] << 16) | 0xFF000000 | (record[0x25] << 8) | record[0x24];
        typeThreeParams.color2 = (record[0x1E] << 16) | 0xFF000000 | (record[0x1D] << 8) | record[0x1C];
        typeThreeParams.alpha0 = (f32)record[0x1F] / 100.0f;
        typeThreeParams.color3 = (record[0x22] << 16) | 0xFF000000 | (record[0x21] << 8) | record[0x20];
        typeThreeParams.alpha1 = (f32)record[0x23] / 100.0f;
        typeThreeParams.value24 = record[0x27];
        typeThreeParams.value28 = record[0x1B] >> 4;
        typeThreeParams.value2C = (f32)record[0x28] / 100.0f;
        typeThreeParams.value30 = (f32)record[0x29] / 100.0f;
        typeThreeParams.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        typeThreeParams.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        typeThreeParams.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        typeThreeParams.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        typeThreeParams.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        typeThreeParams.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        typeThreeParams.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&typeThreeParams;
            destination = (EvtU128 *)&typeThreeFilter.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        typeThreeFilter.params.active = 1;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value;
            s32 blocks;
            source = (EvtU128 *)D_0063C660;
            destination = (EvtU128 *)typeThreeExtra;
            blocks = 2;
            do {
                value = source[0];
                source += 1;
                blocks--;
                destination[0] = value;
                destination += 1;
            } while (blocks > 0);
            {
                s64 *tailSource = (s64 *)source;
                s64 *tailDestination = (s64 *)destination;
                s64 lastPair = *tailSource++;
                f32 lastValue = *(f32 *)tailSource;
                *tailDestination++ = lastPair;
                *(f32 *)tailDestination = lastValue;
            }
        }
        /* This 44-byte template mixes word/float fields; its qword and tail copy shape is measured above. */
        ((EvtBlurFilterExtra *)typeThreeExtra)->mode = record[0x2B];
        ((EvtBlurFilterExtra *)typeThreeExtra)->first = ((EvtBlurFilterRecord *)record)->unk14;
        ((EvtBlurFilterExtra *)typeThreeExtra)->weight = (f32)record[0x13] / 100.0f;
        ((EvtBlurFilterExtra *)typeThreeExtra)->last = ((EvtBlurFilterRecord *)record)->unk16;
        {
            u32 *source;
            u32 *destination;
            u32 value;
            s32 blocks;
            source = (u32 *)typeThreeExtra;
            destination = (u32 *)typeThreeFilter.extra;
            blocks = 11;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        referenceKind = record[0x2A];
        filter = effBlurFilterCopiedCreate(3, &typeThreeFilter.params);
        ((EvtBlurFilter *)filter)->reference = (s32)effBlurFilterCreateRefObj((u16 *)&referenceKind, 4);
        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (filter != NULL) {
            task[1] = (s32)filter;
        } else {
            task[1] = (s32)effBlurFilterCopiedCreate(3, &typeThreeFilter.params);
        }
        task[3] = typeThreeFilter.params.valueB8;
        return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task));
    case 5:
        mode = 0;
        if (record[0x1B] & 1) {
            mode = 1;
            if (record[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = (u8 *)&typeFiveParams;
            remaining = sizeof(typeFiveParams);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        typeFiveParams.type = mode;
        typeFiveParams.color0 = (record[0x1A] << 16) | 0xFF000000 | (record[0x19] << 8) | record[0x18];
        typeFiveParams.color1 = (record[0x26] << 16) | 0xFF000000 | (record[0x25] << 8) | record[0x24];
        typeFiveParams.color2 = (record[0x1E] << 16) | 0xFF000000 | (record[0x1D] << 8) | record[0x1C];
        typeFiveParams.alpha0 = (f32)record[0x1F] / 100.0f;
        typeFiveParams.color3 = (record[0x22] << 16) | 0xFF000000 | (record[0x21] << 8) | record[0x20];
        typeFiveParams.alpha1 = (f32)record[0x23] / 100.0f;
        typeFiveParams.value24 = record[0x27];
        typeFiveParams.value28 = record[0x1B] >> 4;
        typeFiveParams.value2C = (f32)record[0x28] / 100.0f;
        typeFiveParams.value30 = (f32)record[0x29] / 100.0f;
        typeFiveParams.value38 = (f32)((EvtBlurFilterRecord *)record)->unk30 / 10.0f;
        typeFiveParams.value3C = (f32)((EvtBlurFilterRecord *)record)->unk32 / 10.0f;
        typeFiveParams.value64 = (f32)((EvtBlurFilterRecord *)record)->unk34 / 10.0f;
        typeFiveParams.value68 = (f32)((EvtBlurFilterRecord *)record)->unk36 / 10.0f;
        typeFiveParams.value90 = (f32)((EvtBlurFilterRecord *)record)->unk2C / 10.0f;
        typeFiveParams.value94 = (f32)((EvtBlurFilterRecord *)record)->unk2E / 10.0f;
        typeFiveParams.valueB8 = ((EvtBlurFilterRecord *)record)->unk10;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&typeFiveParams;
            destination = (EvtU128 *)&typeFiveFilter.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        {
            u8 *clearCursor;
            s32 remaining;
            clearCursor = typeFiveExtra;
            remaining = sizeof(typeFiveExtra);
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value0;
            u32 value1;
            s32 blocks;
            source = (u32 *)typeFiveExtra;
            destination = (u32 *)typeFiveFilter.extra;
            blocks = 5;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        referenceKind = 0;
        filter = effBlurFilterCopiedCreate(5, &typeFiveFilter.params);
        ((EvtBlurFilter *)filter)->reference = (s32)effBlurFilterCreateRefObj((u16 *)&referenceKind, 4);
        chkmemAllocSiteTag(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (filter != NULL) {
            task[1] = (s32)filter;
        } else {
            task[1] = (s32)effBlurFilterCopiedCreate(5, &typeFiveFilter.params);
        }
        task[3] = typeFiveFilter.params.valueB8;
        return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063C648), 0xF, 0, 0, evtBlurFilterTaskUpdate, evtBlurFilterTaskDestroy, (u8 *)(task));
    }
}

#pragma pop

/* 0x30-byte tint allocation; the five target words are copied from the command. */
typedef struct EvtTintWork {
    s32 frame;
    s32 flags;
    s32 targetLight, targetColor;
    f32 targetFog, targetValue;
    s32 unk18;
    s32 startLight, startColor;
    f32 startFog, startValue;
    s32 duration;
} EvtTintWork;

// Tint task update: runs the colour tint step for the task's state each frame [inferred].
// FUN_0028EE00
s32 evtTintTaskUpdate(u8 *unusedTask)
{
    /* EvtTintWork proves these word/float offsets; typed members changed retail scheduling. */
    s32 *work;
    f32 progress;
    u32 startColor;
    u32 endColor;
    u32 start;
    u32 end;
    u8 r;
    u8 g;
    u8 b;

    work = kwlnTaskGetWork();
    work[0]++;
    progress = (f32)work[0] / (f32)work[11];
    if (progress > 1.0f) {
        progress = 1.0f;
    }

    iGpffffba48 = 1;

    start = ((u32)work[7] >> 16) & 0xFF;
    end = ((u32)work[2] >> 16) & 0xFF;
    D_00764B3C = start + progress * (s32)(end - start);

    start = ((u32)work[7] >> 8) & 0xFF;
    end = ((u32)work[2] >> 8) & 0xFF;
    D_00764B40 = start + progress * (s32)(end - start);

    start = (u32)work[7] & 0xFF;
    end = (u32)work[2] & 0xFF;
    D_00764B44 = start + progress * (s32)(end - start);

    startColor = (u32)work[8];
    start = (startColor >> 16) & 0xFF;
    endColor = (u32)work[3];
    end = (endColor >> 16) & 0xFF;
    r = start + progress * (s32)(end - start);

    start = (startColor >> 8) & 0xFF;
    end = (endColor >> 8) & 0xFF;
    g = start + progress * (s32)(end - start);

    start = startColor & 0xFF;
    end = endColor & 0xFF;
    b = start + progress * (s32)(end - start);
    kwlnSetColorRgba(r, g, b, 0);

    ((RwCamera *)kwlnGetCamera())->fogPlane =
        ((EvtTintWork *)work)->startFog + progress * (((EvtTintWork *)work)->targetFog - ((EvtTintWork *)work)->startFog);
    kwlnGetCamera();
    D_00764B5C =
        ((EvtTintWork *)work)->startValue + progress * (((EvtTintWork *)work)->targetValue - ((EvtTintWork *)work)->startValue);

    if (work[0] >= work[11]) {
        if (work[1] & 1) {
            iGpffffba48 = 1;
        } else {
            iGpffffba48 = 0;
        }
        return -1;
    }
    return 0;
}

// Tint task destroy: frees the tint task's work block.
// FUN_0028F360
void evtTintTaskDestroy(u8 *unusedTask)
{
    extern s32 *kwlnTaskGetWork(void);
    int work;

    work = (s32)kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
// Creates a tint task: copies five words of tint data and takes the colour from the kwln colour record and the camera distance [inferred].
/* The five command words mix flags, colors and floats; retain the serialized word-copy cursor and its load/store order. */
// FUN_0028F3A0
void evtCreateTintTask(s32 parentTask, s32 *parameters, s32 duration) {
    s32 v;
    s32 acc;
    s32 t;
    u8 *dst;
    s32 *p;
    s32 *src;
    s32 i;

    evtTintTaskKill();
    chkmemAllocSiteTag(D_0063C638, 0x12E4);
    p = (s32 *)D_008873F4[0](1, 0x30, 0x40000);
    src = parameters;
    dst = (u8 *)p + 4;
    i = 5;
    do {
        v = *src;
        src++;
        i--;
        *(s32 *)dst = v;
        dst += 4;
    } while (i > 0);
    ((EvtTintWork *)p)->duration = duration;
    ((EvtTintWork *)p)->unk18 = 1;
    ((EvtTintWork *)p)->startLight = ((D_00764B3C << 16) | (D_00764B40 << 8)) | D_00764B44;
    acc = kwlnGetColorRgb()[0] << 16;
    acc |= kwlnGetColorRgb()[1] << 8;
    t = kwlnGetColorRgb()[2];
    ((EvtTintWork *)p)->startColor = t | acc;
    ((EvtTintWork *)p)->startFog = ((RwCamera *)kwlnGetCamera())->fogPlane;
    ((EvtTintWork *)p)->startValue = D_00764B5C;
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_00763898), 0xF, 0, 0, evtTintTaskUpdate, evtTintTaskDestroy, (u8 *)(p));
}

// Destroys the tint task by name, if it is alive.
// FUN_0028F4F0
void evtTintTaskKill(void) {
    s32 h;

    if (h = kwlnTaskGetTaskByName(&iGpffffa7a8)) {
        kwlnTaskDestroyWithHierarchy(h);
    }
}

/* Empty retail hook called for each type-3 NPC resource before its event node is allocated. */
// FUN_0028F530
void evtNpcResourceHook(u8 *resource) {
}

// Script load task step: loads the script file named by the task, starts its procedure at the requested index, and waits for it to finish [inferred].
// FUN_0028F540
s32 evtScriptLoadStep(u8 *unusedTask) {
    s32 *work;
    u32 resourceSize;
    u8 *scriptData;

    work = kwlnTaskGetWork();
    switch (work[0]) {
    case 0:
        if (work[0x43] != 0) {
            H_Cdvd_Destroy(work[0x43]);
            work[0x43] = 0;
        }
        func_00440b68(&D_007638A0, D_0063C638, 0x1344);
        work[0x43] = H_Cdvd_AcquireDirectory(&work[3], 0);
        work[0] = 1;
    case 1:
        if (H_Cdvd_IsFileLoaded(work[0x43]) != 0) {
            work[0] = 2;
        }
        break;
    case 2:
        scriptData = H_Cdvd_LookupRequest(&work[3], &resourceSize);
        if (work[0x44] != 0) {
            kAssertFail(D_0063C638, 0x134E);
        }
        work[0x44] = scrStartProcedureIndex(work[2], scriptData, work[1]);
        if (work[0x44] == 0) {
            kAssertFail(D_0063C638, 0x1350);
        }
        work[0] = 3;
    case 3:
        if (kwlnTaskIsLinked(work[0x44]) != 0) {
            break;
        }
        work[0x44] = 0;
        work[0] = 4;
        break;
    case 4:
        break;
    }
    return 0;
}

// Script load task destroy: destroys the started procedure and the file load, then frees the work block.
// FUN_0028F6C0
void evtScriptLoadDestroy(u8 *unusedTask) {
    s32 *work;

    work = kwlnTaskGetWork();
    if (work[0x44] != 0 && kwlnTaskIsLinked(work[0x44]) != 0) {
        kwlnTaskDestroyWithHierarchy(work[0x44]);
    }
    if (work[0x43] != 0) {
        if (H_Cdvd_IsFileLoaded(work[0x43]) == 0) {
            kAssertFail(D_0063C638, 0x1364);
        }
        H_Cdvd_Destroy(work[0x43]);
    }
    jtbl_008873EC[0](work);
}

// Creates a script load task with its work block in the ready state (state 4) [inferred].
// FUN_0028F770
void evtStartScriptLoad(s32 parentTask) {
    s32 *work;

    chkmemAllocSiteTag(D_0063C638, 0x1370);
    work = (s32 *)D_008873F4[0](1, 0x114, 0x40000);
    work[0] = 4;
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_0063C690), 0xF, 0, 0, evtScriptLoadStep, evtScriptLoadDestroy, (u8 *)(work));
}

// Script load request: when the task is ready, records the procedure index and file name for the next load and returns 1; otherwise returns 0 [inferred].
// FUN_0028F800
s32 evtScriptLoadRequest(s32 task, s32 procedureKind, s32 filename, s32 procedureIndex) {
    s32 *work;

    if (kwlnTaskIsLinked(task) == 0) {
        kAssertFail(D_0063C638, 0x137E);
    }
    work = kwlnTaskGetWork(task);
    if (work[0] == 4) {
        work[2] = procedureKind;
        work[1] = procedureIndex;
        if (strcmp(&work[3], filename) == 0) {
            work[0] = 2;
        } else {
            strcpy(&work[3], filename);
            work[0] = 0;
        }
        return 1;
    }
    return 0;
}

// Returns 1 when the script load task is in the ready state (state 4), else 0 [inferred].
// FUN_0028F8E0
s32 evtScriptLoadIsReady(s32 task) {
    if (kwlnTaskIsLinked(task) == 0) {
        kAssertFail(D_0063C638, 0x1393);
    }
    if (kwlnTaskGetWork(task)[0] == 4) {
        return 1;
    }
    return 0;
}


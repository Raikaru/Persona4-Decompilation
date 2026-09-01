#include "include_asm.h"
/* Source unit: src/Kosaka/k_vpad_0015f720.c */
#include "type.h"

typedef struct RuntimeVec3
{
    f32 x;
    f32 y;
    f32 z;
} RuntimeVec3;
typedef struct RuntimeMatrix
{
    f32 values[16];
} RuntimeMatrix;

extern RuntimeMatrix* func_003e0f80(void);
extern RuntimeVec3 D_005F10F8;
extern void RwMatrixRotate(RuntimeMatrix* matrix, const RuntimeVec3* axis,
                          f32 angle, u32 mode);
extern void func_003e42e0(RuntimeVec3* destination,
                          const RuntimeVec3* source, s32 count,
                          RuntimeMatrix* matrix);
extern void func_003e0f40(void* matrix);

/* Ported from P3FES src/Kosaka/k_vpad.c FUN_001E6AF0 (verified MATCH there).
 * The P3 donor builds the quad vertices with inline machine code; under MWCC
 * the plain C below compiles to the same div.s-by-2.0 sequence, so none is
 * needed. */
typedef struct RuntimeListNode RuntimeListNode;
typedef struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
    u32 completedFlags;
    u32 state;
    u32 phase;
    u32 selection;
} RuntimeWork;

extern s32 func_004b6de0(RuntimeListNode* node);
extern void func_0047a510(void* context, void* object, RuntimeMatrix* matrix);

/* Ported from P3FES src/Kosaka/k_vpad.c FUN_001EDA90 (verified MATCH there).
 * Honest C: request = work->requestFlags; offset = i * 8; inlined at both
 * call sites. Retail emits the loop's per-entry lw/sll pair load-first;
 * MWCC schedules the sll ahead of the reload - measured nd 5 (fndiff) /
 * nd 8 (verify). Accepted compiler floor. */
extern void func_004b7140(void* owner);
typedef struct RuntimeDistanceWork
{
    void** config;
    u8 reserved04[4];
    s32 count;
    u8 reserved0c[4];
    RuntimeVec3* firstVectors;
    RuntimeVec3* secondVectors;
} RuntimeDistanceWork;

extern s32 func_004b7800(const RuntimeWork* work, s32 index);
extern f32 RwV3dLength(RuntimeVec3* vector);
typedef struct RuntimeCommandWork
{
    u32 flags;
    u16* cursor;
    u8 reserved08[8];
    RuntimeWork* target;
    u32 elapsed;
    u16 delay;
    u16 reserved1a;
    u32 duration;
} RuntimeCommandWork;

extern void func_004bc4d0(f32 value, RuntimeWork* work);
extern void (*D_00887300[])(s32 state, s32 value);
extern void (*D_00887304[])(s32 state, void* value);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_003e9df0(void* object);
extern void* func_0047a2f0(void* object);
extern void func_003e9cb0(void* object, void* matrix, s32 flags);

typedef struct RuntimeVpadWork
{
    u32 reserved00;
    u8* field;
    u32 reserved08;
    u8* entries;
    u8* statuses;
} RuntimeVpadWork;

// FUN_0015F720. Build, rotate, and translate a four-vertex field quad.
void func_0015f720(RuntimeVec3* vertices, const RuntimeVec3* translation,
                   f32 width, f32 depth, f32 angle)
{
    RuntimeMatrix* matrix;
    RuntimeVec3 axis;
    s32 i;

    matrix = func_003e0f80();
    axis = D_005F10F8;
    vertices[0].x = -width / 2.0f;
    vertices[0].y = 0.0f;
    vertices[0].z = -depth / 2.0f;
    vertices[1].x = width / 2.0f;
    vertices[1].y = 0.0f;
    vertices[1].z = -depth / 2.0f;
    vertices[2].x = -width / 2.0f;
    vertices[2].y = 0.0f;
    vertices[2].z = depth / 2.0f;
    vertices[3].x = width / 2.0f;
    vertices[3].y = 0.0f;
    vertices[3].z = depth / 2.0f;

    matrix->values[10] = 1.0f;
    matrix->values[5] = 1.0f;
    matrix->values[0] = 1.0f;
    matrix->values[4] = 0.0f;
    matrix->values[2] = 0.0f;
    matrix->values[1] = 0.0f;
    matrix->values[9] = 0.0f;
    matrix->values[8] = 0.0f;
    matrix->values[6] = 0.0f;
    matrix->values[14] = 0.0f;
    matrix->values[13] = 0.0f;
    matrix->values[12] = 0.0f;
    *(u32*)&matrix->values[3] |= 0x20003;

    RwMatrixRotate(matrix, &axis, angle, 2);
    func_003e42e0(vertices, vertices, 4, matrix);
    func_003e0f40(matrix);
    for (i = 0; i < 4; i++)
    {
        vertices[i].x += translation->x;
        vertices[i].y += translation->y;
        vertices[i].z += translation->z;
    }
}


/* The loop body is executable-equivalent but MWCC b210 schedules the
   per-entry pair as `sll $s0,$s3,3` before `lw $v1,4($s4)`; retail has
   those two words reversed at fndiff offsets 84 and 88. The remaining
   differences are retail-only zero-padding words at offsets 324, 328, and
   332. While/for loop forms, local offset/request temporaries, and schedule
   pragmas were ruled out. obj 324B/window 336B, nd 5. Committed at nd 8. */
// FUN_004B5800
INCLUDE_ASM("asm/nonmatchings/k_vpad", func_004b5800);


// FUN_004B5950
INCLUDE_ASM("asm/nonmatchings/k_vpad", func_004b5950);
// FUN_004B5C20. Mark an active field runtime node for processing.
void func_004b5c20(RuntimeWork* work)
{
    if (func_004b6de0((RuntimeListNode*)work) != 0)
    {
        work->flags |= 4;
    }
}



// FUN_004B5C60
#pragma opt_propagation off
void func_004b5c60(RuntimeVpadWork* work)
{
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    u8* temp_17;
    s32 var_16;

    {
        void* base;
        base = (void*)D_00887304;
        ((void (*)(s32, void*))*(void**)base)(0x14, &sp5C);
        ((void (*)(s32, void*))*(void**)base)(0xA, &sp58);
        ((void (*)(s32, void*))*(void**)base)(0xB, &sp54);
        ((void (*)(s32, void*))*(void**)base)(8, &sp4C);
        ((void (*)(s32, void*))*(void**)base)(6, &sp50);
        ((void (*)(s32, void*))*(void**)base)(0xE, &sp48);

        base = (void*)D_00887300;
        ((void (*)(s32, s32))*(void**)base)(9, 2);
        ((void (*)(s32, s32))*(void**)base)(0x14, 1);
        ((void (*)(s32, s32))*(void**)base)(8, 0);
        ((void (*)(s32, s32))*(void**)base)(6, 1);
        ((void (*)(s32, s32))*(void**)base)(0xE, 0);
        ((void (*)(s32, s32))*(void**)base)(0xC, 1);
    }

    var_16 = 0;
    while (var_16 < *(s16*)((u8*)work->field + 4))
    {
        func_003f6440(2, 0x48);
        func_003f6440(3, 0x71801);
        temp_17 = *(u8**)(*(u8**)(work->entries + var_16 * 8) + 4);
        if ((*(s32*)(work->statuses + var_16 * 0x20) & 8) != 0)
        {
            func_003e9df0(temp_17);
        }
        else
        {
            func_003e9df0(temp_17);
            if ((~*(s32*)(*(u8**)((u8*)work->field + 0x20) + 0xD8) & 0x8000) != 0)
            {
                func_003e9cb0(temp_17, func_0047a2f0(*(u8**)((u8*)work->field + 0x20)), 0);
            }
            else
            {
                func_003e9cb0(temp_17, *(u8**)((u8*)work->field + 0x20) + 0x90, 0);
            }
        }
        {
            u8* entryBase;
            entryBase = work->entries;
            ((void (*)(u8*))*(u32*)(*(u8**)(entryBase + var_16 * 8) + 0x48))(*(u8**)(entryBase + var_16 * 8));
        }
        var_16++;
    }
    {
        void* base;
        base = (void*)D_00887300;
        ((void (*)(s32, s32))*(void**)base)(0xE, sp48);
        ((void (*)(s32, s32))*(void**)base)(0xB, sp54);
        ((void (*)(s32, s32))*(void**)base)(0xA, sp58);
        ((void (*)(s32, s32))*(void**)base)(0x14, sp5C);
        ((void (*)(s32, s32))*(void**)base)(8, sp4C);
        ((void (*)(s32, s32))*(void**)base)(6, sp50);
    }
}
#pragma opt_propagation on
// FUN_004B5F20. Activate a field runtime node and its owner.
void func_004b5f20(RuntimeWork* work)
{
    if (func_004b6de0((RuntimeListNode*)work) != 0)
    {
        work->flags |= 8;
        func_004b7140(*(void**)((u8*)(uintptr_t)work->requestFlags + 0x20));
    }
}



// FUN_004B5F70
void func_004b5f70(void)
{
}

// FUN_004B5F80. Update the render color and mark it dirty.
void func_004b5f80(RuntimeWork* work, const u8* color)
{
    typedef struct RuntimeColor
    {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } RuntimeColor;
    typedef struct RuntimeColorWork
    {
        u32 flags;
        u8 reserved[0x1c];
        RuntimeColor color;
    } RuntimeColorWork;
    RuntimeColorWork* colorWork;
    const RuntimeColor* requested;

    colorWork = (RuntimeColorWork*)work;
    requested = (const RuntimeColor*)color;
    if (func_004b6de0((RuntimeListNode*)work) == 0)
    {
        return;
    }

    if (colorWork->color.red != requested->red ||
        colorWork->color.green != requested->green ||
        colorWork->color.blue != requested->blue ||
        colorWork->color.alpha != requested->alpha)
    {
        colorWork->color = *requested;
        colorWork->flags |= 0x10;
    }
}


/* measured: opt_propagation off is required for exact COP1 tail register coloring. */
#pragma opt_propagation off
// FUN_004B7300
f32 func_004b7300(const RuntimeDistanceWork* work, s32 index)
{
    extern f32 func_003e4180(RuntimeVec3* vector);
    s32 firstIndex;
    s32 nextIndex;
    RuntimeVec3 delta;
    f32 total;
    f32 length;
    f32 sum;
    f32 zero;
    f32 result;
    firstIndex = func_004b7800((const RuntimeWork*)work, index);
    nextIndex = func_004b7800((const RuntimeWork*)work, index + 1);
    total = 0.0f;

    delta.x = work->firstVectors[nextIndex].x - work->firstVectors[firstIndex].x;
    delta.y = work->firstVectors[nextIndex].y - work->firstVectors[firstIndex].y;
    delta.z = work->firstVectors[nextIndex].z - work->firstVectors[firstIndex].z;
    total += func_003e4180(&delta);

    delta.x = work->secondVectors[nextIndex].x - work->secondVectors[firstIndex].x;
    delta.y = work->secondVectors[nextIndex].y - work->secondVectors[firstIndex].y;
    delta.z = work->secondVectors[nextIndex].z - work->secondVectors[firstIndex].z;
    length = func_003e4180(&delta);
    sum = total + length;

    zero = 0.0f;
    result = *(f32*)((u8*)work->config[0] + 0x2C);
    return sum * result + zero;
}
#pragma opt_propagation on
// FUN_004B7800
s32 func_004b7800(const RuntimeWork* work, s32 index)
{
    s32 result;

    result = (s32)work->state - 1 - index;
    if (result < 0)
    {
        result += (s32)work->completedFlags;
    }
    return result;
}



// FUN_004BAED0
void func_004baed0(RuntimeCommandWork* work, u32* unused)
{
    u16* cursor;
    u32 duration;
    u16* durationParts;
    RuntimeWork* target;
    s32 stop;

    cursor = work->cursor;
    stop = 0;
    do
    {
        switch (*cursor)
        {
        case 0:
            stop = 1;
            break;
        case 1:
            if ((~work->flags & 1) != 0)
            {
                if ((((u32)(cursor + 1) >> 1) & 1) != 0)
                {
                    durationParts = (u16*)&duration;
                    durationParts[0] = cursor[1];
                    durationParts[1] = cursor[2];
                }
                else
                {
                    duration = *(u32*)(cursor + 1);
                }
                work->flags |= 1;
                work->elapsed = 0;
            }
            else
            {
                work->elapsed++;
            }
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                duration = *(u32*)(cursor + 1);
            }
            stop = 1;
            if (work->elapsed >= duration)
            {
                cursor += 3;
                work->flags &= ~1;
                stop = 0;
            }
            break;
        case 0x100:
            work->flags |= 2;
            cursor++;
            break;
        case 0x101:
            work->flags &= ~2;
            cursor++;
            break;
        case 0x102:
            target = work->target;
            target->completedFlags = 0;
            target->state = 0;
            cursor++;
            break;
        case 0x200:
            switch (work->delay)
            {
            case 0:
                if (work->duration != 0)
                {
                    func_004bc4d0((f32)work->duration / 30.0f, work->target);
                }
                break;
            }
            cursor++;
            break;
        case 0x201:
            work->delay = (s16)cursor[1];
            cursor += 2;
            break;
        case 0x202:
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                duration = *(u32*)(cursor + 1);
            }
            work->duration = duration;
            cursor += 3;
            break;
        case 0x400:
            work->flags |= 8;
            cursor++;
            break;
        }
    } while ((u32)(stop != 0) ^ 1);
    work->cursor = cursor;
}



// FUN_004BCE30. Check whether the field resource contains any entries.
s32 func_004bce30(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    return *(u16*)(uintptr_t)work->requestFlags != 0;
}

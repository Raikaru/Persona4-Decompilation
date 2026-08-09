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
// FUN_004B5800 NONMATCHING
#ifdef NON_MATCHING
void func_004b5800(RuntimeWork* work)
{
    s32 i;
    RuntimeMatrix* firstMatrix;
    RuntimeMatrix* secondMatrix;

    if (func_004b6de0((RuntimeListNode*)work) == 0)
    {
        return;
    }

    firstMatrix = func_003e0f80();
    secondMatrix = func_003e0f80();
    i = 0;
    while (i < *(s16*)((u8*)(uintptr_t)work->requestFlags + 4))
    {
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            *(void**)((u8*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18) + i * 8),
            firstMatrix);
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            *(void**)((u8*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18) +
                      i * 8 + 4),
            secondMatrix);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2] =
            *(RuntimeVec3*)((u8*)firstMatrix + 0x30);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2 + 1] =
            *(RuntimeVec3*)((u8*)secondMatrix + 0x30);
        i++;
    }

    work->flags |= 2;
    func_003e0f40(firstMatrix);
    func_003e0f40(secondMatrix);
}
#else
INCLUDE_ASM("asm/nonmatchings/k_vpad", func_004b5800);
#endif


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
INCLUDE_ASM("asm/nonmatchings/k_vpad", func_004b5c60);
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


// FUN_004B7300
INCLUDE_ASM("asm/nonmatchings/k_vpad", func_004b7300);
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

#include "include_asm.h"
/* Source unit: src/Kosaka/k_vpad_0015f720.c */
#include "type.h"
#include "rw_atomic_layout_internal.h"
#include "member_access.h"

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

/* Config readers agree on a signed pair count at 4, a two-index table at
 * 0x18, and its model owner at 0x20. The full allocation extent is unknown. */
typedef struct RuntimeVpadPair
{
    s32 first;
    s32 second;
} RuntimeVpadPair;
typedef struct VpadConfig
{
    u16 entryCount;
    u8 pad02[2];
    s16 pairCount;
    u8 pad06[0x12];
    RuntimeVpadPair *pairs;
    u8 pad1C[4];
    u8 *model;
} VpadConfig;
typedef struct Model
{
    u8 pad00[0x90];
    RuntimeMatrix matrix;
    u8 padD0[8];
    u32 flags;
    u8 padDC[0x18];
    f32 progress;
} Model;
typedef struct RuntimeVpadEntry
{
    u8 *atomic;
    u8 *material;
} RuntimeVpadEntry;
typedef struct VpadDistanceConfig
{
    u8 pad00[0x2C];
    f32 scale;
} VpadDistanceConfig;

extern RuntimeMatrix* func_003e0f80(void);
extern RuntimeVec3 D_005F10F8;
extern void RwMatrixRotate(RuntimeMatrix* matrix, const RuntimeVec3* axis,
                          f32 angle, u32 mode);
extern void func_003e42e0(RuntimeVec3* destination,
                          const RuntimeVec3* source, s32 count,
                          RuntimeMatrix* matrix);
extern s32 func_003e0f40(void* matrix);

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

extern s32 AfPackIsActive(RuntimeListNode* node);
extern s32 mdlCopyIndexedMatrix(void* model, s32 index, RuntimeMatrix* destination);

/* Ported from P3FES src/Kosaka/k_vpad.c FUN_001EDA90 (verified MATCH there).
 * Honest C: request = work->requestFlags; offset = i * 8; inlined at both
 * call sites. Retail emits the loop's per-entry lw/sll pair load-first;
 * MWCC schedules the sll ahead of the reload - measured nd 5 (fndiff) /
 * nd 8 (verify). Accepted compiler floor. */
extern void AfPackReleaseByOwner(void* owner);
typedef struct RuntimeDistanceWork
{
    void** config;
    u8 reserved04[4];
    s32 count;
    u8 reserved0c[4];
    RuntimeVec3* firstVectors;
    RuntimeVec3* secondVectors;
} RuntimeDistanceWork;

extern s32 effAfterHistoryIndex(const RuntimeWork* work, s32 index);
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

extern void (*D_00887300[])(s32 state, s32 value);
extern void (*D_00887304[])(s32 state, void* value);
extern void RpSkyRenderStateSet(s32 state, s32 value);
extern void func_003e9df0(void* object);
extern void* mdlGetMatrix(void* model);
extern void func_003e9cb0(void* frame, void* transform, s32 combine);
extern void func_003e0960(void* matrix, const void* source);
extern void func_003e42a0(void* destination, const void* source,
                          RuntimeMatrix* matrix);
extern void effAfterQueuePush(u8* data, const RuntimeVec3* position,
                          const RuntimeVec3* normal);
extern void effMiscProgressAdvance(u8* progress, f32* elapsedStep);
extern void effAfterRebuildTrailMesh(u8* work, u32* pp);
extern void effAfterRunCommands(RuntimeCommandWork* work, u32* unused);
extern f32 iGpffff8040;

typedef struct RuntimeVpadWork
{
    u32 reserved00;
    u8* field;
    u32 reserved08;
    u8* entries;
    u8* statuses;
} RuntimeVpadWork;

// FUN_0015F720. Build, rotate, and translate a four-vertex field quad.
void Vpad_BuildRotatedQuad(RuntimeVec3* vertices, const RuntimeVec3* translation,
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


/* The input table stores two signed indices per entry. Keeping the pair
 * offset in one inlined helper preserves the owner expression while making
 * the complete pair address an explicit, natural C value. */
/* Select one signed matrix index from the configuration's two-index records. */
/* measured: site/union indexing differs by 10 bytes and a typed flat local by
 * 18 in Vpad_RefreshSelection. Byte-cursor MEMBER keeps the load/shift order;
 * eight-byte pairs contain two four-byte signed indices selected by side. */
/* Select one signed matrix index from a two-index configuration record. */
/* measured: expanding the first-index call changes eight refresh bytes; the second-index call expands without a difference. */
static inline s32 vpadPairIndex(RuntimeWork* work, s32 index, s32 side)
{
    return MEMBER(s32, (u8 *)((VpadConfig *)(uintptr_t)work->requestFlags)->pairs +
                  index * 8 + side * 4, RuntimeVpadPair, first);
}

/* 324/336 bytes; seven resolved relocations and twelve zero alignment bytes.
 * The signed pair-index helper preserves each request reload and the retail
 * load/shift order without ABI, volatile, or assembly workarounds. */
// FUN_004B5800
void Vpad_RefreshSelection(RuntimeWork* work)
{
    s32 i;
    RuntimeMatrix* firstMatrix;
    RuntimeMatrix* secondMatrix;

    if (AfPackIsActive((RuntimeListNode*)work) == 0)
    {
        return;
    }

    firstMatrix = func_003e0f80();
    secondMatrix = func_003e0f80();
    i = 0;
    while (i < ((VpadConfig*)(uintptr_t)work->requestFlags)->pairCount)
    {
        mdlCopyIndexedMatrix(
            (void*)((VpadConfig*)(uintptr_t)work->requestFlags)->model,
            vpadPairIndex(work, i, 0),
            firstMatrix);
        mdlCopyIndexedMatrix(
            (void*)((VpadConfig*)(uintptr_t)work->requestFlags)->model,
            MEMBER(s32, (u8 *)((VpadConfig *)(uintptr_t)(work)->requestFlags)->pairs + (i) * 8 + (1) * 4, RuntimeVpadPair, first),
            secondMatrix);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2] =
            *(RuntimeVec3*)&firstMatrix->values[12];
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2 + 1] =
            *(RuntimeVec3*)&secondMatrix->values[12];
        i++;
    }

    work->flags |= 2;
    func_003e0f40(firstMatrix);
    func_003e0f40(secondMatrix);
}


/* Advance trail commands, transform samples, update color, and rebuild each entry mesh. */
// FUN_004B5950
void Vpad_UpdateRenderEntries(u8* workData)
{
    typedef struct RuntimeVpadColor
    {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } RuntimeVpadColor;
    typedef struct RuntimeVpadUpdateWork
    {
        u32 flags;
        u8* field;
        u8* renderData;
        u8* entries;
        u8* commands;
        u8* vectors;
        u8 reserved18[8];
        RuntimeVpadColor color;
    } RuntimeVpadUpdateWork;
    RuntimeVpadUpdateWork* work;
    s32 i;
    s32 hasField;
    s32 vectorOffset;
    RuntimeMatrix* matrix;
    u8 red;
    u8 green;
    u8 alpha;
    u8 blue;
    typedef struct RuntimeVpadLocals
    {
        u8 position[12];
        u8 normal[20];
        RuntimeVpadColor color;
        f32 delta;
        u8 unused[4];
        u32 value;
    } RuntimeVpadLocals;
    RuntimeVpadLocals locals;
    RuntimeVec3* sample;
    u8* entry;

    work = (RuntimeVpadUpdateWork*)workData;
    hasField = 0;
    if (((Model*)((VpadConfig*)work->field)->model)->progress != 0.0f)
    {
        hasField = 1;
    }
    i = 0;
    while (i < ((VpadConfig*)work->field)->pairCount)
    {
        if (hasField != 0)
        {
            vectorOffset = i * 0x20;
            effAfterRunCommands((RuntimeCommandWork*)(work->commands + vectorOffset),
                          (u32*)locals.unused);
            if ((~work->flags & 8) != 0)
            {
                if ((((RuntimeCommandWork*)(work->commands + vectorOffset))->flags & 2) != 0)
                {
                    if ((((RuntimeCommandWork*)(work->commands + vectorOffset))->flags & 8) != 0)
                    {
                        vectorOffset = i * 3 * 8;
                        sample = (RuntimeVec3*)(work->vectors + vectorOffset);
                        effAfterQueuePush(work->renderData + i * 0x3C, sample,
                                      (RuntimeVec3*)((u8*)sample + 0xC));
                    }
                    else
                    {
                        matrix = func_003e0f80();
                        if ((~((Model*)((VpadConfig*)work->field)->model)->flags &
                             0x8000) != 0)
                        {
                            func_003e0960(matrix,
                                          mdlGetMatrix(((VpadConfig*)work->field)->model));
                        }
                        else
                        {
                            func_003e0960(matrix,
                                          &((Model*)((VpadConfig*)work->field)->model)->matrix);
                        }
                        vectorOffset = i * 3 * 8;
                        func_003e42a0(locals.position,
                                      work->vectors + vectorOffset, matrix);
                        func_003e42a0(locals.normal,
                                      work->vectors + vectorOffset + 0xC,
                                      matrix);
                        effAfterQueuePush(work->renderData + i * 0x3C,
                                      (RuntimeVec3*)locals.position,
                                      (RuntimeVec3*)locals.normal);
                        func_003e0f40(matrix);
                    }
                }
            }
        }
        if (hasField != 0)
        {
            locals.delta = iGpffff8040;
        }
        else
        {
            locals.delta = 0.0f;
        }
        if ((work->flags & 0x10) != 0)
        {
            red = work->color.red;
            green = work->color.green;
            blue = work->color.blue;
            alpha = work->color.alpha;
            locals.color.red = red;
            locals.color.green = green;
            locals.color.blue = blue;
            locals.color.alpha = alpha;
            if (locals.color.alpha == 0xFF)
            {
                locals.color.alpha = 0xFE;
            }
            entry = ((RuntimeVpadEntry*)work->entries)[i].material;
            red = locals.color.red;
            green = locals.color.green;
            blue = locals.color.blue;
            alpha = locals.color.alpha;
            entry[4] = red;
            entry[5] = green;
            entry[6] = blue;
            entry[7] = alpha;
        }
        effMiscProgressAdvance(work->renderData + i * 0x3C, &locals.delta);
        locals.value = (u32)((struct RpAtomic*)((RuntimeVpadEntry*)work->entries)[i].atomic)->geometry;
        effAfterRebuildTrailMesh(work->renderData + i * 0x3C, &locals.value);
        i++;
    }
}
// FUN_004B5C20. Mark an active field runtime node for processing.
void Vpad_MarkDirty(RuntimeWork* work)
{
    if (AfPackIsActive((RuntimeListNode*)work) != 0)
    {
        work->flags |= 4;
    }
}



/* Draw each trail atomic, selecting local/world transforms and restoring saved render states. */
// FUN_004B5C60
void Vpad_DrawEntries(RuntimeVpadWork* work)
{
    s32 savedCullMode;
    s32 savedSrcBlend;
    s32 savedDstBlend;
    s32 savedZTest;
    s32 savedZWrite;
    s32 savedFog;
    struct RwFrame* frame;
    s32 entryIndex;

    {
        void* base;
        base = (void*)D_00887304;
        ((void (*)(s32, void*))*(void**)base)(0x14, &savedCullMode);
        ((void (*)(s32, void*))*(void**)base)(0xA, &savedSrcBlend);
        ((void (*)(s32, void*))*(void**)base)(0xB, &savedDstBlend);
        ((void (*)(s32, void*))*(void**)base)(8, &savedZWrite);
        ((void (*)(s32, void*))*(void**)base)(6, &savedZTest);
        ((void (*)(s32, void*))*(void**)base)(0xE, &savedFog);

        base = (void*)D_00887300;
        ((void (*)(s32, s32))*(void**)base)(9, 2);
        ((void (*)(s32, s32))*(void**)base)(0x14, 1);
        ((void (*)(s32, s32))*(void**)base)(8, 0);
        ((void (*)(s32, s32))*(void**)base)(6, 1);
        ((void (*)(s32, s32))*(void**)base)(0xE, 0);
        ((void (*)(s32, s32))*(void**)base)(0xC, 1);
    }

    entryIndex = 0;
    while (entryIndex < ((VpadConfig*)work->field)->pairCount)
    {
        RpSkyRenderStateSet(2, 0x48);
        RpSkyRenderStateSet(3, 0x71801);
        frame = ((struct RpAtomic*)((RuntimeVpadEntry*)work->entries)[entryIndex].atomic)->frame;
        if (((s32)((RuntimeCommandWork*)(work->statuses + entryIndex * 0x20))->flags & 8) != 0)
        {
            func_003e9df0(frame);
        }
        else
        {
            func_003e9df0(frame);
            if ((~(s32)((Model*)((VpadConfig*)work->field)->model)->flags & 0x8000) != 0)
            {
                func_003e9cb0(frame, mdlGetMatrix(((VpadConfig*)work->field)->model), 0);
            }
            else
            {
                func_003e9cb0(frame, &((Model*)((VpadConfig*)work->field)->model)->matrix, 0);
            }
        }
        {
            u8* entryBase;
            entryBase = work->entries;
            ((struct RpAtomic*)((RuntimeVpadEntry*)entryBase)[entryIndex].atomic)->renderCallBack((struct RpAtomic*)((RuntimeVpadEntry*)entryBase)[entryIndex].atomic);
        }
        entryIndex++;
    }
    {
        void* base;
        base = (void*)D_00887300;
        ((void (*)(s32, s32))*(void**)base)(0xE, savedFog);
        ((void (*)(s32, s32))*(void**)base)(0xB, savedDstBlend);
        ((void (*)(s32, s32))*(void**)base)(0xA, savedSrcBlend);
        ((void (*)(s32, s32))*(void**)base)(0x14, savedCullMode);
        ((void (*)(s32, s32))*(void**)base)(8, savedZWrite);
        ((void (*)(s32, s32))*(void**)base)(6, savedZTest);
    }
}
// FUN_004B5F20. Activate a field runtime node and its owner.
void Vpad_Activate(RuntimeWork* work)
{
    if (AfPackIsActive((RuntimeListNode*)work) != 0)
    {
        work->flags |= 8;
        AfPackReleaseByOwner((void*)((VpadConfig*)(uintptr_t)work->requestFlags)->model);
    }
}



// FUN_004B5F70
void Vpad_Noop(void)
{
}

// FUN_004B5F80. Update the render color and mark it dirty.
void Vpad_SetColor(RuntimeWork* work, const u8* color)
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
    if (AfPackIsActive((RuntimeListNode*)work) == 0)
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
/* measured: baseline removal differs in 45 bytes; separate first and second edge totals; cache vector arrays with named pointers also differ. */
#pragma opt_propagation off
/* Sum both history-edge lengths and apply the configured distance scale. */
// FUN_004B7300
f32 Vpad_GetSegmentLength(const RuntimeDistanceWork* work, s32 index)
{
    extern f32 RwV3dLength(RuntimeVec3* vector);
    s32 firstIndex;
    s32 nextIndex;
    RuntimeVec3 delta;
    f32 total;
    f32 length;
    f32 sum;
    f32 zero;
    f32 result;
    firstIndex = effAfterHistoryIndex((const RuntimeWork*)work, index);
    nextIndex = effAfterHistoryIndex((const RuntimeWork*)work, index + 1);
    total = 0.0f;

    delta.x = work->firstVectors[nextIndex].x - work->firstVectors[firstIndex].x;
    delta.y = work->firstVectors[nextIndex].y - work->firstVectors[firstIndex].y;
    delta.z = work->firstVectors[nextIndex].z - work->firstVectors[firstIndex].z;
    total += RwV3dLength(&delta);

    delta.x = work->secondVectors[nextIndex].x - work->secondVectors[firstIndex].x;
    delta.y = work->secondVectors[nextIndex].y - work->secondVectors[firstIndex].y;
    delta.z = work->secondVectors[nextIndex].z - work->secondVectors[firstIndex].z;
    length = RwV3dLength(&delta);
    sum = total + length;

    zero = 0.0f;
    result = ((VpadDistanceConfig*)work->config[0])->scale;
    return sum * result + zero;
}
#pragma opt_propagation on






// FUN_004BCE30. Check whether the field resource contains any entries.
s32 Vpad_HasEntries(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    return ((VpadConfig*)(uintptr_t)work->requestFlags)->entryCount != 0;
}

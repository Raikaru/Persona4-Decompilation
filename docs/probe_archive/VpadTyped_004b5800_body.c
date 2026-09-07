/* Faithful typed floor: 324B/336B, fndiff 5 words: two executable
 * lw/sll schedule differences at +0x54/+0x58 and three zero-tail words.
 * Full-width IDs and void(u8*) are consumer-backed; no promotion.
 * Fresh request temporaries, typed table bases and accessor forms did not close it.
 * Fresh full-owner replay applies all seven call relocations: the same two
 * executable words differ. A producer-backed request layout adds two
 * commuted-addu differences (four total). An inline request-call boundary
 * gives 320B/62 executable differences, including the missing delay slot.
 * None improves this body; the twelve retail tail bytes are separate.
 * Historical W47Vpad archive remains preserved. */
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

/* The request table contains paired full-width IDs, not the allocated matrices.
 * func_0047a510 uses their low 16 bits on its indexed path, but passes all
 * 32 bits to func_00457f40 on its alternate path. */
typedef struct RuntimeVpadEntry
{
    s32 firstId;
    s32 secondId;
} RuntimeVpadEntry;

extern s32 func_004b6de0(RuntimeListNode* node);
extern RuntimeMatrix* func_003e0f80(void);
extern s32 func_0047a510(void* context, s32 objectId, void* matrix);
extern void func_003e0f40(void* matrix);

/* Isolated MWCC b210 -O2: 324B / 336B retail window, reloc-masked nd5.
 * Only executable differences: +0x54/+0x58 sll/lw reversal.
 * Remaining +0x144/+0x148/+0x14c differences are retail zero padding.
 * This is a faithful recovery floor, NOT a production exact-match candidate. */
// FUN_004B5800
void func_004b5800(u8* workData)
{
    RuntimeWork* work;
    s32 i;
    RuntimeMatrix* firstMatrix;
    RuntimeMatrix* secondMatrix;

    work = (RuntimeWork*)workData;
    if (func_004b6de0((RuntimeListNode*)work) == 0)
    {
        return;
    }

    firstMatrix = func_003e0f80();
    secondMatrix = func_003e0f80();
    i = 0;
    while (i < *(s16*)((u8*)(uintptr_t)work->requestFlags + 4))
    {
        /* Reload the request and entry table independently for each call. */
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            ((RuntimeVpadEntry*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18))[i].firstId,
            firstMatrix);
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            ((RuntimeVpadEntry*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18))[i].secondId,
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

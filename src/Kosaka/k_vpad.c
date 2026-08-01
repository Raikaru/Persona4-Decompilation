/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004B7800)
/* Source unit: src/Kosaka/k_vpad_004b7800.c */
#include "type.h"

typedef struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
    u32 completedFlags;
    u32 state;
} RuntimeWork;

// FUN_004B7800. Translate a logical sample index into the ring buffer.
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
#endif /* P4_UNIT_004B7800 */

#if defined(P4_UNIT_004BCE30)
/* Source unit: src/Kosaka/k_vpad_004bce30.c */
#include "type.h"

typedef struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
} RuntimeWork;

// FUN_004BCE30. Check whether the field resource contains any entries.
s32 func_004bce30(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    return *(u16*)(uintptr_t)work->requestFlags != 0;
}
#endif /* P4_UNIT_004BCE30 */

#if defined(P4_UNIT_004B5C20)
/* Source unit: src/Kosaka/k_vpad_004b5c20.c */
#include "type.h"

typedef struct RuntimeListNode RuntimeListNode;
typedef struct RuntimeWork
{
    u32 flags;
} RuntimeWork;

extern s32 func_004b6de0(RuntimeListNode* node);

// FUN_004B5C20. Mark an active field runtime node for processing.
void func_004b5c20(RuntimeWork* work)
{
    if (func_004b6de0((RuntimeListNode*)work) != 0)
    {
        work->flags |= 4;
    }
}
#endif /* P4_UNIT_004B5C20 */

#if defined(P4_UNIT_004B5F20)
/* Source unit: src/Kosaka/k_vpad_004b5f20.c */
#include "type.h"

typedef struct RuntimeListNode RuntimeListNode;
typedef struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
} RuntimeWork;

extern s32 func_004b6de0(RuntimeListNode* node);
extern void func_004b7140(void* owner);

// FUN_004B5F20. Activate a field runtime node and its owner.
void func_004b5f20(RuntimeWork* work)
{
    if (func_004b6de0((RuntimeListNode*)work) != 0)
    {
        work->flags |= 8;
        func_004b7140(*(void**)((u8*)(uintptr_t)work->requestFlags + 0x20));
    }
}
#endif /* P4_UNIT_004B5F20 */

#if defined(P4_UNIT_004B5F80)
/* Source unit: src/Kosaka/k_vpad_004b5f80.c */
#include "type.h"

typedef struct RuntimeListNode RuntimeListNode;
typedef struct RuntimeWork
{
    u32 flags;
} RuntimeWork;

extern s32 func_004b6de0(RuntimeListNode* node);

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
#endif /* P4_UNIT_004B5F80 */

#if defined(P4_UNIT_004BAED0)
/* Source unit: src/Kosaka/k_vpad_004baed0.c */
#include "type.h"

typedef struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
    u32 completedFlags;
    u32 state;
} RuntimeWork;
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
#endif /* P4_UNIT_004BAED0 */

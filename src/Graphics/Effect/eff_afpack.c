/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004B6DE0)
/* Source unit: src/Graphics/Effect/eff_afpack_004b6de0.c */
#include "type.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    u8 reserved[8];
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
} RuntimeListNode;

extern RuntimeListNode* D_00764CA0;

// FUN_004B6DE0
s32 func_004b6de0(RuntimeListNode* node)
{
    RuntimeListNode* current;

    current = D_00764CA0;
    while (current != NULL)
    {
        if (current == node)
        {
            break;
        }
        current = *(RuntimeListNode**)((u8*)current + 0x1c);
    }
    if (current == NULL)
    {
        return 0;
    }
    return !(node->flags & 8);
}
#endif /* P4_UNIT_004B6DE0 */

#if defined(P4_UNIT_004B6DA0)
/* Source unit: src/Graphics/Effect/eff_afpack_004b6da0.c */
#include "type.h"

typedef struct RuntimeWork RuntimeWork;

typedef struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    u8 reserved[8];
    struct RuntimeListNode* previous;
    struct RuntimeListNode* next;
} RuntimeListNode;

extern void* D_00764C9C;
extern RuntimeListNode* D_00764CA0;

// FUN_004B6DA0
void func_004b6da0(void* node)
{
    if (D_00764C9C == NULL)
    {
        *(void**)((u8*)node + 0x18) = NULL;
        *(void**)((u8*)node + 0x1c) = NULL;
        D_00764CA0 = (RuntimeListNode*)node;
        D_00764C9C = node;
        return;
    }
    else
    {
        *(void**)((u8*)node + 0x18) = D_00764C9C;
        *(void**)((u8*)node + 0x1c) = NULL;
        *(void**)((u8*)D_00764C9C + 0x1c) = node;
    }
    D_00764C9C = node;
}
#endif /* P4_UNIT_004B6DA0 */

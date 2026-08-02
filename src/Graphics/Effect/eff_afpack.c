/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "include_asm.h"

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

extern void* D_00764C98;
extern s32 D_00922DB0[];
extern s32 D_00922DB4[];
extern void func_00460ac0(void* arg0, s32* arg1);
extern void* D_00764C9C;
extern RuntimeListNode* D_00764CA0;

// FUN_004B6030
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6030);

// FUN_004B6900
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6900);

// FUN_004B6BB0
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6bb0);

// FUN_004B6C90
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6c90);

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
// FUN_004B6E40
s32 func_004b6e40(void)
{
    D_00922DB0[0] = 0;
    D_00922DB4[0] = 0;
    func_00460ac0(D_00764C98, D_00922DB0);
    return 0;
}

// FUN_004B6E80
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b6e80);

// FUN_004B7140
INCLUDE_ASM("asm/nonmatchings/eff_afpack", func_004b7140);


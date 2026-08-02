/* Consolidated Persona 4 source units. */
/* Original translation unit sdkDbprt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

typedef struct HDbText3D HDbText3D;
struct HDbText3D
{
    HDbText3D* next; // 0x00
};

static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
static HDbText3D* sText3DList;

extern void* memset(void* destination, s32 value, size_t count);
/* rwGlobals.memFuncs.RwFree slot: indirect call through data. */
extern void (*RwFree_abs[])(void* memory);



// FUN_0044F570
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044f570);

// FUN_0044F6B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = sText3DList;
    sText3DList = NULL;
    while (1)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree_abs[0](curr);
        curr = next;
    }
}
// FUN_0044F720
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044f720);

// FUN_0044FA90
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044fa90);

// FUN_00450050
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_00450050);

// FUN_004501F0
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_004501f0);

// FUN_00450340
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_00450340);


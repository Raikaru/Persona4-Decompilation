/* Consolidated Persona 4 source units. */
/* Original translation unit sdkTask.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern s32 func_003e1220(u32 a0, u32 a1, u32 a2, u32 a3, void* a4, u32 a5);
/* GP-relative scalar at gp -0x45E8 (absolute 0x00764B08). */
extern s32 iGpffffba18;
extern u32 D_008BFFB0[];

typedef struct KwlnTask KwlnTask;

extern KwlnTask* kwlnTaskGetTaskByName(const char* name);
extern u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task);



// FUN_00451CA0
void func_00451ca0(s32 arg0)
{
    iGpffffba18 = func_003e1220(0x54, arg0, 4, 1, D_008BFFB0, 0x41001);
}



// FUN_00452040
u8 kwlnTaskDestroyWithHierarchyByName(const char* name)
{
    KwlnTask* task;

    task = kwlnTaskGetTaskByName(name);
    if (task == NULL)
    {
        return 0;
    }

    return kwlnTaskDestroyWithHierarchy(task);
}



// FUN_00452540
u32 kwlnTaskGetTimer(void* task)
{
    return *(u32*)((u8*)task + 0x28);
}

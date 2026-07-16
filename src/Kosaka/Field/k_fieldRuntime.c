/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004BAEA0)
/* Source unit: src/Kosaka/Field/k_fieldRuntime_004baea0.c (1 function markers) */
#include "type.h"

typedef struct RuntimeResetWork RuntimeResetWork;
struct RuntimeResetWork
{
    u32 flags;
    u32 value;
    u32 completedFlags;
    u32 reserved;
    void* work;
};

extern void func_004bc500(void* work);

// FUN_004BAEA0
void func_004baea0(RuntimeResetWork* work)
{
    work->value = work->completedFlags;
    work->flags = 0;
    func_004bc500(work->work);
}
#endif /* P4_UNIT_004BAEA0 */

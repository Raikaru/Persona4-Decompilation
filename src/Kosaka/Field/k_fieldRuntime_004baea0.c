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

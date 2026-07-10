#include "Kosaka/k_clump_internal.h"

// FUN_00457C90
u32 func_00457c90(void* clump, const char* name)
{
    struct
    {
        u32 found;
        char copiedName[72];
    } context;

    context.found = 0;
    func_00442830(context.copiedName, name);
    func_003bff30(clump, (KClumpCallback)func_00457b60, &context);
    return context.found;
}

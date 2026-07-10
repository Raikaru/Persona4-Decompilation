#include "Kosaka/k_command_internal.h"

// FUN_00177E20
u32 func_00177e20()
{
    s32 type;
    s32 id;
    Model* mdl;

    type = func_0029cc00(0);
    id = func_0029cc00(1);

    mdl = func_00478140(type, id, 0);

    func_0029cf50((s32)mdl);

    return true;
}

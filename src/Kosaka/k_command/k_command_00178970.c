#include "Kosaka/k_command_internal.h"

// FUN_00178970
u32 func_00178970()
{
    s32 resourceId;
    s32 value;

    resourceId = func_0029cc00(0);
    value = func_0029cc00(1);

    return func_002bd360(resourceId, value) == 0;
}

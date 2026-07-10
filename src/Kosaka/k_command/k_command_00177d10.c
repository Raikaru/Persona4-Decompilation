#include "Kosaka/k_command_internal.h"

// FUN_00177D10
u32 func_00177d10()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)func_0029cc00(0);
    resourceId = 0;
    created = 0;
    if (func_004782b0(model) == true)
    {
        resourceId = (u16)func_00145ac0(func_0014b510(10), model);
        created = 1;
    }
    func_0029cf50(resourceId);

    return created;
}

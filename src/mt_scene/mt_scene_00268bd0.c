#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

// FUN_00268BD0
u32 func_00268bd0(Resrc* resource, s32 enabled)
{
    if (resource == NULL)
    {
        return 0;
    }

    if (enabled == 1)
    {
        resource->flags |= 8;
    }
    else
    {
        resource->flags &= ~8;
    }

    return 1;
}

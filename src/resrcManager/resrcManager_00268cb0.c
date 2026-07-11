#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

// FUN_00268CB0
u8 func_00268cb0(Resrc* resource)
{
    if (resource == NULL)
    {
        return 0;
    }

    return (resource->flags & 8) != 0;
}

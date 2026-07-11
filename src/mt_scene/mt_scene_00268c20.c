#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

extern Resrc* func_00145270(u16 resTypeId);

// FUN_00268C20
u32 func_00268c20(u16 resTypeId, s32 enabled)
{
    Resrc* res;

    res = func_00145270(resTypeId);
    if (res == NULL)
    {
        return 0;
    }
    else if (res == NULL)
    {
        return 0;
    }
    else
    {
        if (enabled == 1)
        {
            res->flags |= 8;
        }
        else
        {
            res->flags &= ~8;
        }

        return 1;
    }
}

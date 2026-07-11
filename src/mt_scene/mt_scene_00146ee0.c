#include "type.h"

extern u8* PTR_DAT_00762ea0;
extern s32 func_00147530(s32 resourceManager, u64 resourceId);
extern void func_00146a10(s32 resource, s32 position, s32 angles, u64 flags);

// FUN_00146EE0
void func_00146ee0(u64 resourceId, u64 angles)
{
    s32 resource;

    if (*(s32*)(PTR_DAT_00762ea0 + 8) == 0)
    {
        resource = 0;
    }
    else
    {
        resource = func_00147530(*(s32*)(PTR_DAT_00762ea0 + 8), resourceId);
    }

    if (resource != 0)
    {
        (func_00146a10)(resource, 0, 0, angles);
    }
}

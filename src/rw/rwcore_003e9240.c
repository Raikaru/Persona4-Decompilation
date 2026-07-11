#include "type.h"
#pragma optimization_level 3

typedef struct RwObjectOwnerLink RwObjectOwnerLink;
typedef struct RwObject RwObject;
struct RwObjectOwnerLink {
    u8 padding[0xa0];
    RwObject *owner;
};
struct RwObject {
    u8 padding[3];
    u8 type;
};

// FUN_003E9240
u8 func_003e9240(RwObjectOwnerLink *param_1)
{
    return param_1->owner->type & 3;
}
#pragma optimization_level 2

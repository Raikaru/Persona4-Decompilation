#ifndef MDL_ATTACHMENT_INTERNAL_H
#define MDL_ATTACHMENT_INTERNAL_H
#include "type.h"

/* mdlManager's attachedWpns start at model +0x28C, with 0x0C-byte stride.
 * Its attach/detach paths set bit 0 and own the model pointer at +4. */
typedef struct MdlWpnSlot {
    u8 flags;
    u8 pad1[3];
    void *wpnMdl;
    s32 frameID;
} MdlWpnSlot;
#endif

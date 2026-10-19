#ifndef KWLN_VIEW_INTERNAL_H
#define KWLN_VIEW_INTERNAL_H

#include "type.h"

/* kwlnGetCamera returns this view object. Event setup reads its +4 handle;
 * fade-rectangle projection takes the reciprocal of the float at +0x80.
 * The remaining view fields and the precise meaning of that float are unknown. */
typedef struct KwlnView {
    u8 pad00[4];
    s32 camera;
    u8 pad08[0x78];
    f32 unk80;
} KwlnView;

#endif

#ifndef FCL_COLOR_H
#define FCL_COLOR_H

#include "type.h"

typedef struct {
    u8 c0, c1, c2, c3;
} FclDrawColor;

/* The EE aggregate return uses the caller's four-byte output object. */
FclDrawColor func_002b2a60(s32 red, s32 green, s32 blue, s32 alpha);

static inline void fclConstructColor(FclDrawColor *out, s32 red, s32 green,
                                    s32 blue, s32 alpha)
{
    *out = func_002b2a60(red, green, blue, alpha);
}

/* Character access also supports packed colors in existing byte buffers. */
static inline void fclWriteColorBytes(void *out, s32 red, s32 green,
                                     s32 blue, s32 alpha)
{
    FclDrawColor color = func_002b2a60(red, green, blue, alpha);
    u8 *bytes = (u8 *)out;
    bytes[0] = color.c0;
    bytes[1] = color.c1;
    bytes[2] = color.c2;
    bytes[3] = color.c3;
}

#endif

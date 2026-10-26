#ifndef FCL_COLOR_H
#define FCL_COLOR_H

#include "type.h"

typedef struct {
    u8 c0, c1, c2, c3;
} FclDrawColor;

/* The EE aggregate return writes the caller's four-byte color object. */
FclDrawColor fclMakeDrawColor(u8 red, u8 green, u8 blue, u8 alpha);

static inline void fclConstructColor(FclDrawColor *out, s32 red, s32 green,
                                    s32 blue, s32 alpha)
{
    *out = fclMakeDrawColor(red, green, blue, alpha);
}

/* Character access also supports packed colors in existing byte buffers. */
static inline void fclWriteColorBytes(void *out, s32 red, s32 green,
                                     s32 blue, s32 alpha)
{
    FclDrawColor color = fclMakeDrawColor(red, green, blue, alpha);
    u8 *bytes = (u8 *)out;
    bytes[0] = color.c0;
    bytes[1] = color.c1;
    bytes[2] = color.c2;
    bytes[3] = color.c3;
}

void fclSpriteStartColorAt(s16 index, FclDrawColor start, FclDrawColor end, u8 mode, s16 duration, s32 delay);

#endif

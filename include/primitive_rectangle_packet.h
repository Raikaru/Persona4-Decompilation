#ifndef PRIMITIVE_RECTANGLE_PACKET_H
#define PRIMITIVE_RECTANGLE_PACKET_H
#include "type.h"

/* Exact value snapshot retained until the queued rectangle callback runs. */
typedef struct PrimitiveRectangleColorBytes { u8 rgba[4]; } PrimitiveRectangleColorBytes;
typedef union PrimitiveRectangleColor {
    PrimitiveRectangleColorBytes bytes;
    f32 transport;
} PrimitiveRectangleColor;
typedef struct PrimitiveRectangleTransport { f32 word[4]; } PrimitiveRectangleTransport;
typedef struct PrimitiveRectangleSignedWords { s32 word[4]; } PrimitiveRectangleSignedWords;
typedef union PrimitiveRectangleWords {
    PrimitiveRectangleTransport transport;
    PrimitiveRectangleSignedWords signedWords;
    u32 bits[4];
} PrimitiveRectangleWords;
typedef struct PrimitiveRectanglePacket {
    PrimitiveRectangleColorBytes color;
    PrimitiveRectangleWords rectangle;
    f32 depth;
    s32 saveState;
} PrimitiveRectanglePacket;
typedef char PrimitiveRectangleColorSize[sizeof(PrimitiveRectangleColor) == 4 ? 1 : -1];
typedef char PrimitiveRectangleWordsSize[sizeof(PrimitiveRectangleWords) == 16 ? 1 : -1];
typedef char PrimitiveRectanglePacketSize[sizeof(PrimitiveRectanglePacket) == 28 ? 1 : -1];

/* Inputs are four color bytes and four aligned signed/unsigned rectangle words. */
void func_0045da40(const PrimitiveRectangleColor *color, const PrimitiveRectangleWords *rectangle, f32 depth,
                  s32 saveState, void *queue);
void func_0045d890(void *unused, u8 *work);
#endif

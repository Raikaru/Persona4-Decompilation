#ifndef FR_FONT_OBJECTS_H
#define FR_FONT_OBJECTS_H

#include "type.h"

/* frFontCreateGlyphNode initializes all 0x2C bytes of this pool object.
 * Links remain integer handles because the public font API uses EE addresses. */
typedef struct FrFontGlyphData {
    u16 character;
    u16 frame;
    s32 x;
    s32 y;
    s32 advance;
    u32 color;
    u8 palette;
    u8 slot;
    u8 effect;
    u8 flags;
    u8 width;
    u8 height;
    u8 pad1A[2];
    s32 raster;
    s32 unk20;
    s32 previous;
    s32 next;
} FrFontGlyphData;

/* frFontCreateTextList clears 0x44 bytes; the draw, append, and command
 * routines establish the links, coordinates, and pending-command fields. */
typedef struct FrFontTextRun {
    u16 code;
    u8 intensity;
    s8 spacing;
    s32 x;
    s32 y;
    s32 width;
    s16 glyphWidth;
    s16 glyphHeight;
    union { f32 scale; u32 bits; } depth;
    s32 glyphCount;
    s32 firstGlyph;
    s32 lastGlyph;
    s32 previous;
    s32 next;
    s32 root;
    s32 command;
    s32 previousCommand;
    s32 commandChanged;
    s32 duration;
    s32 enabled;
} FrFontTextRun;

/* frFontBuildTextFull packs this 0x20-byte command/layout descriptor. */
typedef struct FrFontContext {
    s32 x;
    s32 y;
    u32 duration;
    s8 style;
    s8 palette;
    s8 effect;
    s8 intensity;
    s32 stream;
    s32 list;
    s32 position;
    s8 active;
    s8 pendingPosition;
    s16 height;
} FrFontContext;

/* The glyph cache's 16-byte auxiliary record is populated by
 * frFontAcquireGlyph and released by frFontListRelease. */
typedef struct FrFontGlyphRaster {
    u16 character;
    u8 pad02[2];
    u16 references;
    u8 pad06[2];
    s32 slot;
    s32 cacheEntry;
} FrFontGlyphRaster;

/* FrFontSlotLoad reads these members from the on-disc font header. */
typedef struct FrFontFileHeader {
    s32 dataOffset;
    u8 pad04[6];
    u8 blockCount;
    u8 pad0B[3];
    u16 glyphCount;
    u16 unk10;
    u16 unk12;
    u8 pad14[2];
    u8 hasMetrics;
} FrFontFileHeader;

#endif

#ifndef EVT_MOVIE_INTERNAL_H
#define EVT_MOVIE_INTERNAL_H

#include "type.h"

/* Polygon-movie section directory: 0x20-byte header, then 0x10-byte entries.
 * evtPolygonMovieBind proves the count, version, entry stride and offsets. */
typedef struct EvtMovieFileHeader {
    u8 pad00[0x10];
    s32 recordCount;
    s32 version;
    u8 pad18[8];
} EvtMovieFileHeader;

typedef struct EvtMovieSection {
    s32 code;
    s32 unk04;
    s32 count;
    s32 offset;
} EvtMovieSection;

/* evtPolygonMovieAlloc reserves and clears 0x114 bytes. The binder records
 * each section pointer and its count; unknown section roles retain offsets. */
typedef struct EvtPolygonMovieWork {
    u8 pad00[0x10];
    u8 *primary; /* +0x10 */
    u8 *primaryRecords; /* +0x14 */
    u8 *unk18; /* +0x18 */
    s32 count1C; /* +0x1C */
    u8 *unk20; /* +0x20 */
    s32 count24; /* +0x24 */
    u8 *unk28; /* +0x28 */
    u8 *unk2C; /* +0x2C */
    u8 *unk30; /* +0x30 */
    u8 *unk34; /* +0x34 */
    s32 count38; /* +0x38 */
    u8 *unk3C; /* +0x3C */
    u8 *unk40; /* +0x40 */
    s32 count44; /* +0x44 */
    u8 *unk48; /* +0x48 */
    u8 *message; /* +0x4C */
    s32 count50; /* +0x50 */
    u8 *unk54; /* +0x54 */
    s32 count58; /* +0x58 */
    u8 *unk5C; /* +0x5C */
    u8 *unk60; /* +0x60 */
    s32 count64; /* +0x64 */
    u8 pad68[0x18];
    u8 *secondary; /* +0x80 */
    u8 *secondaryRecords; /* +0x84 */
    u8 *unk88; /* +0x88 */
    s32 count8C; /* +0x8C */
    u8 *unk90; /* +0x90 */
    u8 *unk94; /* +0x94 */
    u8 *unk98; /* +0x98 */
    u8 *overlay; /* +0x9C */
    u8 *overlayRecords; /* +0xA0 */
    u8 *unkA4; /* +0xA4 */
    s32 countA8; /* +0xA8 */
    s32 countAC; /* +0xAC */
    u8 *unkB0; /* +0xB0 */
    s32 countB4; /* +0xB4 */
    u8 *unkB8; /* +0xB8 */
    s32 countBC; /* +0xBC */
    u8 *unkC0; /* +0xC0 */
    s32 countC4; /* +0xC4 */
    u8 *unkC8; /* +0xC8 */
    s32 countCC; /* +0xCC */
    u8 *unkD0; /* +0xD0 */
    s32 countD4; /* +0xD4 */
    u8 *unkD8; /* +0xD8 */
    s32 countDC; /* +0xDC */
    u8 *unkE0; /* +0xE0 */
    s32 countE4; /* +0xE4 */
    u8 *unkE8; /* +0xE8 */
    s32 countEC; /* +0xEC */
    u8 *unkF0; /* +0xF0 */
    s32 countF4; /* +0xF4 */
    u8 *unkF8; /* +0xF8 */
    s32 countFC; /* +0xFC */
    u8 *unk100; /* +0x100 */
    s32 count104; /* +0x104 */
    u8 *unk108; /* +0x108 */
    s32 count10C; /* +0x10C */
    s32 flags; /* +0x110 */
} EvtPolygonMovieWork;

#endif

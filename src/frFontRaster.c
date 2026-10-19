#include "include_asm.h"
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "fr_font_objects.h"
#include "rw_camera_internal.h"

/* The constructor allocates a 0x18-byte header followed by 0x21C-byte entries.
 * Each entry ends with its 0x200-byte packed glyph bitmap. */
typedef struct FrFontRasterEntry FrFontRasterEntry;
typedef union FrFontRasterLink {
    u32 bits;
    s32 value;
    u32 *words;
} FrFontRasterLink;
struct FrFontRasterEntry {
    u32 flags;
    u32 key;
    s16 palette;
    union { s16 value; u16 bits; } age;
    FrFontRasterLink bitmap;
    u32 references;
    u32 texture;
    FrFontRasterLink next;
    u8 pixels[0x200];
};
typedef struct FrFontRasterCache {
    s32 count;
    s32 entries;
    FrFontRasterLink activeHead;
    FrFontRasterLink activeTail;
    FrFontRasterLink freeHead;
    FrFontRasterLink freeTail;
} FrFontRasterCache;


/* Ported from P3FES frFontRaster.c (verified MATCH there), adapted to P4
 * addresses, assert lines, and callee names. */
typedef int (*code)();

/* Defined below in this file; called at line 347, above its definition. */
extern void frFontRasterUploadGlyph(int entryAddress, u8 *bitmap, int palette);

extern u8 *D_007645b8;
#define frFontRasterCacheBytes D_007645b8
#define frFontRasterCacheWords ((int *)D_007645b8)

/* Data in the P4 image (absolute, outside the gp window). */
extern char D_0063bc88[]; /* "frFontRaster.c" */
extern char D_0063bca0[];
extern char D_0063bde0[];
extern float D_0063bcc0[];
extern s16 D_0063bce0[];
extern u8 D_0063b5f0[];
extern float D_008872f8[];

/* Function-pointer slots outside the gp window. */
extern code D_008873e8_abs[]; /* RwMalloc */
extern code D_008873ec_abs[]; /* RwFree */
extern u32 DAT_00881750_abs[];
extern void (*D_00887300[])(u32 state, u32 value); /* device.setRenderState */
extern s32 (*D_00887310[])(s32, void *, s32);     /* device.fpIm2DRenderPrimitive */

/* Runtime helpers (old-style where retail passes no prototype-driven
 * zero-extension). */
extern void kAssertFail(const void *file, u32 line);
extern void chkmemAllocSiteTag(void *msg, s32 id);
extern void func_00440b68();
extern s32 kwlnGetCamera(void);
extern void *memset(void *dst, s32 value, u32 size);
extern void memcpy();
extern u32 func_003ec590(u32, u32, u32, u32);
extern int func_003ec6a0(u32 tex, s32, s32);
extern void func_003ec2a0(u32 tex);
extern u32 func_003ec3d0(u32 tex, s32);
extern void func_003ec2e0(u32 tex);
extern u8 *frFontAcquireGlyph(u8 *glyph, u32 palette);
extern s32 frFontFreeListInsert(u8 *slot);

// Ported from P3FES FUN_003b3d60 (verified MATCH there). Calls use the
// donor's implicit old-style declarations (FUN_003b3e00_raw/FUN_003b3e60_raw)
// so the arguments are passed without prototype-driven zero-extension.

/* The loop bound is the fresh expression `i < count - 1`; a named `limit`
   local is coloured first and lands in $a1 (archived at nd 8). */
/* measured: opt_loop_invariants on hoists that bound AFTER the body's
   temporaries are coloured, which is what puts the bound in $a0 and the
   next-node pointer in $a1 as retail. */
#pragma opt_loop_invariants on
/* Creates the glyph cache: count entries, each with a 0x200-byte raster buffer. */
/* measured: the remaining word-index accesses preserve b210 codegen;
 * individual member substitutions gave normalized_diff 6, 147. */
// FUN_00275A60
void frFontRasterCreateCache(s32 count)
{
    s32 i;
    s32 *node;
    s32 size;
    u32 memory;
    u32 block;
    s32 *current;

    size = count * 0x21c + 0x18;
    if (frFontRasterCacheWords != NULL) {
        kAssertFail(D_0063bc88, 0x26);
    }
    chkmemAllocSiteTag(D_0063bc88, 0x27);
    memory = D_008873e8_abs[0](size, 0x40000);
    frFontRasterCacheWords = (s32 *)memory;
    memset((void *)memory, 0, (u32)size);
    ((FrFontRasterCache *)frFontRasterCacheBytes)->count = count;
    ((FrFontRasterCache *)frFontRasterCacheBytes)->entries = (s32)(frFontRasterCacheWords + 6);
    node = (s32 *)((FrFontRasterCache *)frFontRasterCacheBytes)->entries;
    ((FrFontRasterEntry *)node)->bitmap.value = (s32)(node + 7);
    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.value = (s32)node;
    for (i = 0; i < count - 1; i++) {
        ((FrFontRasterEntry *)node)->next.value = (s32)(((FrFontRasterEntry *)node)->bitmap.value + 0x200);
        node = (s32 *)node[6];
        node[3] = (s32)(node + 7);
    }
    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value = (s32)node;
    current = (s32 *)((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.value;
    while (current != NULL) {
        block = func_003ec590(0x20, 0x20, 4, 0x4504);
        ((FrFontRasterEntry *)current)->texture = block;
        if (block == 0) {
            func_00440b68(D_0063bca0);
        } else {
            current = (s32 *)((FrFontRasterEntry *)current)->next.value;
        }
    }
}
/* measured: closes the hoisting scope after frFontRasterCreateCache. */
#pragma opt_loop_invariants off

/* Frees the glyph cache. */
// FUN_00275BD0
void frFontRasterDestroyCache(void)
{
    D_008873ec_abs[0](frFontRasterCacheBytes);
    frFontRasterCacheBytes = (u8 *)0x0;
}

/* Ages every cache entry and moves the expired ones to the free list (LRU eviction). */
/* measured: the remaining word-index accesses preserve b210 codegen;
 * individual member substitutions gave normalized_diff 72, 135, 136, 211. */
// FUN_00275C00
void frFontRasterEvictExpired(void)
{
    u32 *nextEntry;
    u32 *previousEntry;
    u32 *currentEntry;

    previousEntry = (u32 *)0x0;
    nextEntry = ((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.words;
    while (currentEntry = nextEntry, currentEntry != (u32 *)0x0) {
        if (((((FrFontRasterEntry *)currentEntry)->flags & 1) == 0) || (((FrFontRasterEntry *)currentEntry)->references == 0)) {
            ((FrFontRasterEntry *)currentEntry)->age.value =
                ((FrFontRasterEntry *)currentEntry)->age.value + -1;
        }
        if (((FrFontRasterEntry *)currentEntry)->age.value < 0) {
            if (previousEntry == (u32 *)0x0) {
                ((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.bits = ((FrFontRasterEntry *)currentEntry)->next.bits;
                if (((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.value == 0) {
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.value = 0;
                }
                if (((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value != 0) {
                    ((FrFontRasterEntry *)((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value)->next.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                } else {
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.words = currentEntry;
                }
                currentEntry[6] = 0;
                previousEntry = (u32 *)0x0;
                nextEntry = ((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.words;
            } else if (((FrFontRasterEntry *)currentEntry)->next.bits == 0) {
                ((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.words = previousEntry;
                ((FrFontRasterEntry *)previousEntry)->next.bits = 0;
                if (((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value != 0) {
                    ((FrFontRasterEntry *)((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value)->next.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                } else {
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.words = currentEntry;
                }
                currentEntry[6] = 0;
                nextEntry = (u32 *)0x0;
            } else {
                ((FrFontRasterEntry *)previousEntry)->next.bits = ((FrFontRasterEntry *)currentEntry)->next.bits;
                if (((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value != 0) {
                    ((FrFontRasterEntry *)((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.value)->next.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                } else {
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.words = currentEntry;
                    ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.words = currentEntry;
                }
                currentEntry[6] = 0;
                nextEntry = (u32 *)previousEntry[6];
            }
        } else {
            previousEntry = currentEntry;
            nextEntry = (u32 *)((FrFontRasterEntry *)currentEntry)->next.bits;
        }
    }
}

extern u8 D_0063BCC0[];
extern f32 D_008872F8[];
extern u8 D_0063BC88[];
extern s32 D_00881750;
/* Native b210 O2: 1124/1136 bytes, nineteen resolved relocations and
 * twelve zero alignment bytes. All seven siblings and data are unchanged.
 * See docs/probe_archive/Font_raster_00275d80_20260923.md. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Builds the quad for one glyph at (x, y) with the given palette and colour, and submits it. */
/* Keep byte-addressed fields here: the typed cache rewrite changed retail register
 * allocation/reloads. Cache entries are 0x21C bytes (palette +8, texture +0x14);
 * glyph +0x1C selects its 16-byte raster record (references +4, cache entry +0xC). */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 462, 476, 512, 530; retain their original address/alias expressions. */
// FUN_00275D80
s32 frFontRasterDrawGlyph(s32 x, s32 y, f32 depth, u8 *glyph,
                  s32 palette, u32 width, u32 height, u32 rgba)
{
    f32 vertices[64];
    /* Four two-coordinate texture rows, copied by their complete word view. */
    union { u32 words[8]; f32 coordinates[8]; } texture;
    f32 corners[8];
    f32 originX;
    f32 originY;
    f32 reciprocal;
    f32 depthZ;
    f32 right;
    f32 bottom;
    f32 extentX;
    f32 extentY;
    u32 opacity;
    u8 *replacement;
    u8 *raster;
    s32 vertexIndex;
    s32 redShifted;
    s32 greenShifted;
    s32 blueShifted;

    originX = (f32)x / 16.0f;
    originY = (f32)y / 8.0f;
    reciprocal = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    opacity = rgba & 0xFF;
    {
        u8 *sourceBytes = D_0063BCC0;
        u8 *destinationBytes = (u8 *)&texture;
        s32 pairs = 4;
        s32 word0;
        s32 word1;
        do {
            word0 = *(s32 *)sourceBytes;
            word1 = ((s32 *)sourceBytes)[1];
            sourceBytes += 8;
            pairs -= 1;
            *(s32 *)destinationBytes = word0;
            ((s32 *)destinationBytes)[1] = word1;
            destinationBytes += 8;
        } while (pairs > 0);
    }
    /* Preserve the original bounded byte-clear initializer, including its
     * null test, before assigning the four rectangle corners. */
    {
        u8 *clearCursor = (u8 *)corners;
        u32 byteCount = 0x20;
        if (clearCursor != NULL) {
            do {
                *clearCursor = 0;
                clearCursor++;
                byteCount -= 1;
            } while (byteCount != 0);
        }
    }
    corners[0] = originX;
    corners[1] = originY;
    extentX = (f32)(u32)width;
    right = originX + extentX;
    corners[2] = right;
    corners[3] = originY;
    corners[4] = originX;
    extentY = (f32)(u32)height;
    bottom = originY + extentY;
    corners[5] = bottom;
    corners[6] = right;
    corners[7] = bottom;
    if (*(u8 **)(glyph + 0x1C) == NULL) {
        kAssertFail(&D_0063BC88, 0x9B);
    }
    raster = (u8 *)((FrFontGlyphRaster *)*(u8 **)(glyph + 0x1C))->cacheEntry;
    if (((FrFontRasterEntry *)raster)->palette != palette) {
        replacement = frFontAcquireGlyph(glyph, ((FrFontRasterEntry *)raster)->key);
        ((FrFontGlyphRaster *)*(u8 **)(glyph + 0x1C))->references -= 1;
        {
            u8 *previous = *(u8 **)(glyph + 0x1C);
            if ((previous != NULL) && (((FrFontGlyphRaster *)previous)->references == 0)) {
                u8 *previousRaster = (u8 *)((FrFontGlyphRaster *)previous)->cacheEntry;
                if (previousRaster != NULL) {
                    ((FrFontRasterEntry *)previousRaster)->flags &= ~1;
                    ((FrFontRasterEntry *)previousRaster)->references = 0;
                }
                frFontFreeListInsert((u8 *)((FrFontGlyphRaster *)previous)->slot);
                DAT_00881750_abs[0] -= 1;
            }
        }
        ((FrFontGlyphData *)glyph)->raster = (s32)replacement;
        raster = (u8 *)((FrFontGlyphRaster *)replacement)->cacheEntry;
    }
    ((FrFontRasterEntry *)raster)->flags |= 1;
    if (opacity == 0) {
        return 0;
    }
    memset(vertices, 0, 0x100);
    depthZ = D_008872F8[0] - depth;
    /* Unpack shifted channels after initializing the iteration. Each byte
     * converts directly to float at its store; the native invariant pass
     * hoists its stable mask and conversion inputs in that order. */
    vertexIndex = 0;
    redShifted = rgba >> 24;
    greenShifted = rgba >> 16;
    blueShifted = rgba >> 8;
    while (vertexIndex < 4) {
        f32 *vertex;
        f32 *uv;
        f32 *position;
        vertex = &vertices[vertexIndex * 16];
        vertex[2] = depthZ;
        vertex[6] = reciprocal;
        uv = &texture.coordinates[vertexIndex * 2];
        vertex[4] = *uv;
        vertex[5] = *(uv + 1);
        vertex[8] = (f32)(u8)redShifted;
        vertex[9] = (f32)(u8)greenShifted;
        vertex[10] = (f32)(u8)blueShifted;
        vertex[11] = (f32)opacity;
        position = &corners[vertexIndex * 2];
        vertex[0] = *position;
        vertex[1] = *(position + 1);
        vertexIndex += 1;
    }
    D_00887300[0](1, ((FrFontRasterEntry *)raster)->texture);
    D_00887310[0](4, vertices, 4);
    return 0;
}
#pragma pop

// end FUN_00275D80

/* measured: unprototyped forward declarations keep the retail argument setup for frFontFindOrLoadEntry (prototypes gave nd 7). */
u8 *frFontRasterFindEntry();
u8 *frFontRasterAllocEntry();

/* Finds the entry for (value, count); on a miss, takes a free entry and loads 0x200 bytes from index. */
// FUN_002761F0
u8 *frFontFindOrLoadEntry(s32 key, u8 *bitmap, s32 palette)
{
    u8 *entry;

    entry = frFontRasterFindEntry(key, palette);
    if (entry == NULL) {
        entry = frFontRasterAllocEntry(key, bitmap, palette);
        if (entry == NULL)
            entry = NULL;
    }
    return entry;
}

/* Looks up a cache entry through the donor finder; returns 0 when absent. */
// FUN_00276260
u32 frFontRasterLookup(u32 key, int palette)
{
    u32 result;

    result = FUN_003b3e00_typed(key, palette);
    if (result == 0) {
        result = 0;
    }

    return result;
}

// Ported from P3FES FUN_003b3e00 (verified MATCH there). The goto shape is
// the donor's exact loop layout: test entry!=0 first, then walk entry[6].

extern u8 *D_007645b8;
#define frFontRasterCacheBytes D_007645b8

/* Finds a cached entry by key and palette, marks it used, and returns it (0 if none). */
// FUN_00276290
u8 *frFontRasterFindEntry(u32 key, int palette)
{
    u32 *entry;

    entry = ((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.words;
    goto check;
body:
    if (((FrFontRasterEntry *)entry)->key != key) {
        goto next;
    }
    if (((FrFontRasterEntry *)entry)->palette != palette) {
        goto next;
    }
    ((FrFontRasterEntry *)entry)->age.bits = 1;
    ((FrFontRasterEntry *)entry)->flags |= 1;
    goto done;
next:
    entry = (u32 *)((FrFontRasterEntry *)entry)->next.bits;
check:
    if (entry != 0) {
        goto body;
    }
    entry = 0;
done:
    return (u8 *)entry;
}

/* Takes a free entry, stores the key and a copy of the raster source, and returns it (0 if none free). */
/* measured: the remaining word-index accesses preserve b210 codegen;
 * individual member substitutions gave normalized_diff 143. */
// FUN_002762F0
u8 *frFontRasterAllocEntry(u32 key, u8 *bitmap, u32 palette)
{
    u32 *entry;

    if (bitmap == 0) {
        kAssertFail(D_0063bc88, 0x128);
    }
    entry = ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.words;
    if (entry != (u32 *)0x0) {
        ((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.bits = ((FrFontRasterEntry *)entry)->next.bits;
        if (((FrFontRasterCache *)frFontRasterCacheBytes)->freeHead.value == 0) {
            ((FrFontRasterCache *)frFontRasterCacheBytes)->freeTail.bits = 0;
        }
        entry[6] = 0;
        if (((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.value != 0) {
            ((FrFontRasterEntry *)((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.value)->next.bits = (u32)entry;
            ((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.bits = (u32)entry;
        } else {
            ((FrFontRasterCache *)frFontRasterCacheBytes)->activeTail.bits = (u32)entry;
            ((FrFontRasterCache *)frFontRasterCacheBytes)->activeHead.bits = (u32)entry;
        }
        ((FrFontRasterEntry *)entry)->references = 0;
    }
    if (entry == (u32 *)0x0) {
        return 0;
    }
    frFontRasterUploadGlyph((int)entry, (u8 *)bitmap, palette);
    ((FrFontRasterEntry *)entry)->key = key;
    ((FrFontRasterEntry *)entry)->age.bits = 1;
    ((FrFontRasterEntry *)entry)->flags = ((FrFontRasterEntry *)entry)->flags | 1;
    memcpy(((FrFontRasterEntry *)entry)->bitmap.bits, bitmap, 0x200);
    ((FrFontRasterEntry *)entry)->references = 0;
    return (u8 *)entry;
}

/* Unpacks a 4-bit 32x32 glyph source into the texture buffer and copies the palette. */
/* Keep byte-addressed fields here: the typed cache rewrite changed retail register
 * allocation/reloads. Cache entries are 0x21C bytes (palette +8, texture +0x14);
 * glyph +0x1C selects its 16-byte raster record (references +4, cache entry +0xC). */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 391, 392; retain their original address/alias expressions. */
// FUN_00276420
void frFontRasterUploadGlyph(int entryAddress, u8 *bitmap, int palette)
{
    short firstIndex;
    short secondIndex;
    u32 paletteAddress;
    short *indexSource;
    u32 column;
    u16 *indexRow;
    u32 row;
    int textureAddress;
    u32 base;
    u32 outer16;
    u32 inner16;
    u32 rowOffset;
    u8 rawByte;
    int shiftedPixel;
    int pixelIndex;
    u8 *src;
    u8 *destination;
    u16 swizzleTable[128];

    if (bitmap == (u8 *)0x0) {
        func_00440b68(D_0063bde0);
        kAssertFail(D_0063bc88, 0x17e);
        return;
    }
    indexSource = (short *)D_0063bce0;
    indexRow = swizzleTable;
    textureAddress = 0x40;
    do {
        firstIndex = *indexSource;
        secondIndex = indexSource[1];
        indexSource = indexSource + 2;
        textureAddress = textureAddress + -1;
        *indexRow = firstIndex;
        indexRow[1] = secondIndex;
        indexRow = indexRow + 2;
    } while (0 < textureAddress);
    src = bitmap;
    textureAddress = func_003ec6a0(((FrFontRasterEntry *)entryAddress)->texture, 0, 9);
    for (row = 0; (int)row < 0x20; row = row + 1) {
        column = 0;
        outer16 = row & 0xffff;
        indexRow = swizzleTable + ((int)(outer16 & 7) >> 2) * 0x40 + (outer16 & 3) * 0x10;
        base = ((int)outer16 >> 2) * 0x80;
        while ((int)column < 0x20) {
            inner16 = column & 0xffff;
            pixelIndex = (u32)indexRow[inner16 & 0xf];
            rowOffset = ((int)inner16 >> 4) * 0x20;
            rowOffset += base;
            pixelIndex = (pixelIndex + (rowOffset & 0xffffU)) & 0xffff;
            destination = (u8 *)(textureAddress + ((int)pixelIndex >> 1));
            shiftedPixel = *src >> ((column & 1) << 2);
            rawByte = shiftedPixel & 0xf;
            if ((pixelIndex & 1) == 0) {
                *destination = rawByte;
            } else {
                *destination = *destination | (u8)((rawByte << 4) & 0xf0);
            }
            if ((column & 1) != 0) {
                src = src + 1;
            }
            column = column + 1;
        }
    }
    func_003ec2a0(*(u32 *)(entryAddress + 0x14));
    paletteAddress = func_003ec3d0(*(u32 *)(entryAddress + 0x14), 1);
    if (paletteAddress == 0) {
        kAssertFail(D_0063bc88, 0x1b1);
    }
    memcpy(paletteAddress, (u32)D_0063b5f0 + palette * 0x40, 0x40);
    func_003ec2e0(*(u32 *)(entryAddress + 0x14));
    ((FrFontRasterEntry *)entryAddress)->palette = (short)palette;
}

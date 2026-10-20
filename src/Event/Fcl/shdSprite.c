/* Original translation unit shdSprite.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_sprite_loader.h"
#include "include_asm.h"


/* Pack creation copies this 0x10-byte descriptor, then its name strings and
 * optional 8-byte remap entries into one allocation. */
typedef struct ShdSpriteRemap {
    s8 spriteIndex;
    u8 pad01;
    s16 entryIndex;
    s16 x, y;
} ShdSpriteRemap;
typedef struct ShdSpriteDescriptor {
    const char **names;
    s32 spriteCount;
    ShdSpriteRemap *remap;
    s32 remapCount;
} ShdSpriteDescriptor;
typedef struct ShdSpritePack {
    s32 loadIndex;
    ShdSpriteDescriptor *descriptor;
    u8 **sprites;
    ShdSpriteRemap *remap;
    s32 remapCount;
} ShdSpritePack;

typedef int (*code)();
extern code DAT_008873ec_abs[];

typedef signed __int128 s128;
typedef void (*shd_cb)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);


// func_0046b0d0 is intentionally left undeclared (implicit old-style call,
// exactly as in the P3 donor FUN_0040e580): a typed prototype makes mwcc
// emit andi zero-extensions the retail never has.

s32 strlen(const char *text);
void chkmemAllocSiteTag(const void *msg, s32 id);
void memcpy(void *dst, const void *src, u32 size);
void memset(void *dst, s32 value, u32 size);
s32 H_Cdvd_LookupRequest(s32 pathAddress, s32 *slot);
u8 *sdkSpriteRequestLoad(const char *name);
u32 hMaestroDecodeIsReady(s16 *param);
f32 sdkSpriteEntryWidth(void *ptr, s32 index);
s32 sdkSpriteSlotHandle(u8 *ptr, s32 index);
void kAssertFail(const void *file, s32 line);

s32 sdkSpriteDrawNow(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32);
s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
s32 shdSpriteDrawQueuedEx(s32, u8, s32, s32, u8 *, s32, s16, s16, void *, f32, f32, f32, f32, f32, f32);
u32 shdSpriteDrawNumberString(f32, f32, f32, s32, u8, s32, s32, s16 *, shd_cb, u8 *);

/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern void *(*D_008873F4[])(size_t, size_t, u32);
/* Assert source file string. */
extern u8 D_00637280[];

/* Build one owned pack containing the descriptor, sprite slots, copied names, and optional remaps.
 * Byte cursors copy the variable-size allocation; pointer casts retain its existing ABI. */
/* Typed pack creation changed codegen; retain the allocation cursor and descriptor offsets.
 * ShdSpriteDescriptor is 0x10 bytes; ShdSpritePack has its copied descriptor at +4 and slots at +8. */
// FUN_0025EF20
u8 *sdkSpritePackCreate(u8 *descriptor)
{
    s32 size;
    s32 i;
    s32 totalSize;
    u8 *result;
    u8 *cursor;
    u8 *data;
    s32 j;
    s32 length;
    s32 offset;

    size = 0x10;
    i = 0;
    for (; i < *(s32 *)(descriptor + 4); i += 1) {
        offset = i * 4;
        size += strlen(
            *(const char **)((u8 *)(u32)(*(s32 *)descriptor) + offset)) + 1;
    }
    totalSize = size + (size & 1);
    i = *(s32 *)(descriptor + 4) * 8;
    i += *(s32 *)(descriptor + 0xC) * 8;
    i += 0x14;
    totalSize = (u32)((u8 *)(i) + totalSize);
    chkmemAllocSiteTag(&D_00637280, 0x7E);
    result = D_008873F4[0](1, totalSize, 0x40000);
    *(s32 *)result = 0;
    data = result + 0x14;
    *(u8 **)(result + 4) = data;
    *(u8 **)(result + 8) = data + 0x10;
    memcpy(*(void **)(result + 4), descriptor, 0x10);
    cursor = *(u8 **)(result + 8) + *(s32 *)(descriptor + 4) * 4;
    *(u8 **)(*(u8 **)(result + 4)) = cursor;
    cursor += *(s32 *)(descriptor + 4) * 4;
    j = 0;
    for (; j < *(s32 *)(descriptor + 4); j += 1) {
        offset = j * 4;
        length = strlen(
            *(const char **)((u8 *)(u32)(*(s32 *)descriptor) + offset)) + 1;
        memcpy(
            cursor,
            *(const void **)((u8 *)(u32)(*(s32 *)descriptor) + offset),
            length);
        *(u8 **)(*(u8 **)(*(u8 **)(result + 4)) + offset) = cursor;
        cursor += length;
    }
    if (((u32)cursor & 1) != 0) {
        cursor += 1;
    }
    if (*(u8 **)(descriptor + 8) != NULL) {
        memcpy(
            cursor,
            *(u8 **)(descriptor + 8),
            *(s32 *)(descriptor + 0xC) * 8);
        *(u8 **)(*(u8 **)(result + 4) + 8) = cursor;
        *(u8 **)(result + 0xC) = *(u8 **)(*(u8 **)(result + 4) + 8);
    }
    *(s32 *)(result + 0x10) = *(s32 *)(descriptor + 0xC);
    return result;
}

/* Measured exact: object 288B / window 288B / normalized_diff 0.
   A typed s32 *table preserves retail's table/index materialization order. */
/* Advance asynchronous sprite loading in descriptor order; stop at the first incomplete sprite.
 * Keep the measured integer table access: descriptor count is +4, names +0, runtime slots +8. */
// FUN_0025F110
s32 shdSpriteEnsureLoaded(u8 *pack)
{
    s32 H_Cdvd_LookupRequest(s32, s32 *);
    u8 *sdkSpriteRequestLoad(const char *);
    u32 hMaestroDecodeIsReady(s16 *);
    s32 requestState;
    s32 index;
    s32 offset;
    u8 *result;
    s32 *table;
    s32 loaded;

    table = *(s32 **)(pack + 4);
    index = *(s32 *)pack;
    if (index >= table[1]) {
        return 1;
    }
    for (;;) {
        result = *(u8 **)(pack + 8);
        offset = index * 4;
        if (*(u8 **)(result + offset) == NULL) {
            loaded = H_Cdvd_LookupRequest(
                (s32)*(u8 **)(*(u8 **)(*(u8 **)(pack + 4)) + index * 4),
                &requestState);
            if (loaded != 0) {
                *(u8 **)(*(u8 **)(pack + 8) + index * 4) =
                    sdkSpriteAdoptBlob((u32)loaded);
            } else {
                *(u8 **)(*(u8 **)(pack + 8) + index * 4) =
                    sdkSpriteRequestLoad(
                        (const char *)(*(u8 **)(*(u8 **)
                            (*(u8 **)(pack + 4)) + index * 4)));
            }
        } else {
            if (hMaestroDecodeIsReady(
                    (s16 *)*(u8 **)(result + index * 4)) == 0) {
                goto fail;
            }
            *(s32 *)pack = *(s32 *)pack + 1;
        }
        table = *(s32 **)(pack + 4);
        index = *(s32 *)pack;
        if (index >= table[1]) {
            break;
        }
    }
    return 1;
fail:
    return 0;
}
/* Release all runtime sprite handles, then free the pack allocation. */
// FUN_0025F230
void sdkSpritePackDestroy(u32 pack)
{
    int i;

    if (pack != 0) {
        for (i = 0; i < ((ShdSpritePack *)pack)->descriptor->spriteCount; i = i + 1) {
            sdkSpriteRelease((void *)(u32)((ShdSpritePack *)pack)->sprites[i]);
        }
        DAT_008873ec_abs[0](pack);
    }
}

/* Resolve a remapped or packed sprite/entry ID and return the entry width. */
// FUN_0025F2C0
s32 shdSpriteEntryWidth(s32 entryId, s32 entryOffset, u8 *pack)
{
    s32 remapAddress;
    ShdSpriteRemap *remap;
    u8 *sprite;

    remapAddress = (s32)((ShdSpritePack *)pack)->remap;
    if (remapAddress != 0) {
        remap = (ShdSpriteRemap *)(remapAddress + ((entryId & 0xFFFF) * 8));
        sprite = ((ShdSpritePack *)pack)->sprites[remap->spriteIndex];
        return (s32)sdkSpriteEntryWidth(sprite, remap->entryIndex + entryOffset);
    }
    sprite = ((ShdSpritePack *)pack)->sprites[(entryId >> 16) & 0xFFFF];
    return (s32)sdkSpriteEntryWidth(sprite, (entryId & 0xFFFF) + entryOffset);
}

/* Integer handle returned by sdkSpr, not a floating-point result.
 * Measured: 136/144 bytes, nd0, two relocations, eight zero-tail bytes. */
// FUN_0025F360
s32 shdSpriteSlotHandle(s32 entryId, s32 entryOffset, u8 *pack)
{
    s32 remapAddress;
    ShdSpriteRemap *remap;
    u8 *sprite;

    remapAddress = (s32)((ShdSpritePack *)pack)->remap;
    if (remapAddress != 0) {
        remap = (ShdSpriteRemap *)(remapAddress + ((entryId & 0xFFFF) * 8));
        sprite = ((ShdSpritePack *)pack)->sprites[remap->spriteIndex];
        return sdkSpriteSlotHandle(sprite, remap->entryIndex + entryOffset);
    }
    sprite = ((ShdSpritePack *)pack)->sprites[(entryId >> 16) & 0xFFFF];
    return sdkSpriteSlotHandle(sprite, (entryId & 0xFFFF) + entryOffset);
}

// FUN_0025F3F0
s32 shdSpriteDrawNow(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 * pack, s32 flags)
{
    shdSpriteDrawNowEx(x, y, depth, color, alpha, entryId, entryOffset, pack, flags, 0, 0, 0.0f, 1.0f, 1.0f);
    return 0;
}

/* Resolve the sprite entry, add remap position offsets, and issue an immediate draw. */
// FUN_0025F430
s32 shdSpriteDrawNowEx(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 * pack, s32 flags, s16 width, s16 height, f32 rotation, f32 scaleX, f32 scaleY)
{
    s32 remapAddress;
    ShdSpriteRemap *remap;
    u8 *sprite;

    remapAddress = (s32)((ShdSpritePack *)pack)->remap;
    if (remapAddress != 0) {
        remap = (ShdSpriteRemap *)(remapAddress + ((entryId & 0xFFFF) * 8));
        sprite = ((ShdSpritePack *)pack)->sprites[remap->spriteIndex];
        sdkSpriteDrawNow(x + (f32)remap->x, y + (f32)remap->y, depth, color, alpha, remap->entryIndex + entryOffset, sprite, flags, width, height, rotation, scaleX, scaleY);
    } else {
        sprite = ((ShdSpritePack *)pack)->sprites[(entryId >> 16) & 0xFFFF];
        sdkSpriteDrawNow(x, y, depth, color, alpha, (entryId & 0xFFFF) + entryOffset, sprite, flags, width, height, rotation, scaleX, scaleY);
    }
    return 0;
}

// FUN_0025F500
s32 shdSpriteDrawQueued(s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 *pack, s32 flags, void *drawList, f32 x, f32 y, f32 depth)
{
    shdSpriteDrawQueuedEx(color, alpha, entryId, entryOffset, pack, flags, 0, 0, drawList, x, y, depth, 0.0f, 1.0f, 1.0f);
    return 0;
}

/* Resolve the sprite entry and position offsets, then append the draw to the supplied list. */
// FUN_0025F540
s32 shdSpriteDrawQueuedEx(s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 *pack, s32 flags, s16 width, s16 height, void *drawList, f32 x, f32 y, f32 depth, f32 rotation, f32 scaleX, f32 scaleY)
{
    s32 remapAddress;
    ShdSpriteRemap *remap;
    u8 *sprite;

    remapAddress = (s32)((ShdSpritePack *)pack)->remap;
    if (remapAddress != 0) {
        remap = (ShdSpriteRemap *)(remapAddress + ((entryId & 0xFFFF) * 8));
        sprite = ((ShdSpritePack *)pack)->sprites[remap->spriteIndex];
        sdkSpriteDrawQueued(x + (f32)remap->x, y + (f32)remap->y, depth, color, alpha, remap->entryIndex + entryOffset, sprite, flags, width, height, rotation, scaleX, scaleY, drawList);
    } else {
        sprite = ((ShdSpritePack *)pack)->sprites[(entryId >> 16) & 0xFFFF];
        sdkSpriteDrawQueued(x, y, depth, color, alpha, (entryId & 0xFFFF) + entryOffset, sprite, flags, width, height, rotation, scaleX, scaleY, drawList);
    }
    return 0;
}

/* Build uniform digit advances, with a separate thousands-separator advance. */
// FUN_0025F620
void shdSpriteDrawUniformNumber(s32 color, u8 alpha, s32 text, s32 flags, s16 digitWidth, s16 separatorWidth, shd_cb cb, u8 *context, f32 x, f32 y, f32 depth)
{
    s16 advances[0xC];
    u8 *clear;
    s32 remaining;

    clear = (u8 *)advances;
    remaining = 0x18;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            remaining--;
        } while (remaining != 0);
    }
    advances[0] = digitWidth;
    advances[1] = digitWidth;
    advances[2] = digitWidth;
    advances[3] = digitWidth;
    advances[4] = digitWidth;
    advances[5] = digitWidth;
    advances[6] = digitWidth;
    advances[7] = digitWidth;
    advances[8] = digitWidth;
    advances[9] = digitWidth;
    advances[10] = separatorWidth;
    advances[11] = digitWidth;
    shdSpriteDrawNumberString(x, y, depth, color, alpha, text, flags, (s16 *)advances, cb, context);
}

/* Convert decimal text into digit indices, optionally group thousands (flag 8), and align by flags 1/2. */
// FUN_0025F6B0
u32 shdSpriteDrawNumberString(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 text, s32 flags, s16 *advances, shd_cb cb, u8 *context)
{
    s8 digits[0x20];
    s32 digitCount;
    s32 xOffset;
    u32 textIndex;
    s32 width;
    u32 textLength;
    s32 digitIndex;
    s32 groupThousands;

    xOffset = 0;
    memset(digits, 0, 0x20);
    textLength = (u32)strlen((const char *)text);
    width = 0;
    textIndex = 0;
    digitCount = 0;
    groupThousands = flags & 8;
    do {
        s8 *character;
        s8 *digit;

        character = (s8 *)text + textIndex;
        if (*character == 0x20) {
            digits[digitCount] = 0xB;
            width += (u32)advances[0xB];
            textIndex++;
        } else {
            if (groupThousands != 0 && textLength > 3 && textIndex != 0 && (textLength - textIndex) % 3 == 0) {
                digits[digitCount] = 0xA;
                width += (u32)advances[0xA];
                digitCount++;
            }
            digit = &digits[digitCount];
            *digit = (s8)(*character - 0x30);
            if ((s8)*digit < 0) {
                kAssertFail(D_00637280, 0x1B9);
            }
            if (*digit >= 0xA) {
                kAssertFail(D_00637280, 0x1BA);
            }
            width += (u32)advances[*digit];
            textIndex++;
        }
        digitCount++;
    } while (textIndex < textLength);
    if (flags & 1) {
        x -= (f32)width;
    } else if (flags & 2) {
        x -= (f32)(s32)((u32)width >> 1);
    }
    digitIndex = 0;
    while (digitIndex < digitCount) {
        if (digits[digitIndex] != 0xB) {
            cb(x + (f32)xOffset, y, depth, color, alpha, (s8 *)digits, digitIndex, digitCount, context);
        }
        xOffset += (s32)advances[digits[digitIndex]];
        digitIndex++;
    }
    return width;
}

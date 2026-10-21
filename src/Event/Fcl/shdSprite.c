/* Original translation unit shdSprite.c (from __FILE__ assert strings). */
#include "type.h"
#include "member_access.h"
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


// func_0046b0d0 is deliberately left undeclared, as in the P3 donor FUN_0040e580; a typed prototype
// adds zero-extensions that retail does not have.

s32 strlen(const char *text);
void chkmemAllocSiteTag(const void *file, s32 line);
void memcpy(void *dst, const void *src, u32 size);
void memset(void *dst, s32 value, u32 size);
s32 H_Cdvd_LookupRequest(s32 pathAddress, s32 *slot);
u8 *sdkSpriteRequestLoad(const char *name);
u32 hMaestroDecodeIsReady(s16 *state);
f32 sdkSpriteEntryWidth(void *blob, s32 index);
s32 sdkSpriteSlotHandle(u8 *pack, s32 recordIndex);
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
 * Byte cursors walk the variable-size allocation; the copied descriptor sits after the header,
 * followed by the slots. */
// FUN_0025EF20
u8 *sdkSpritePackCreate(u8 *descriptor)
{
    u8 **destinationEntry;
    const void **sourceEntry;
    const char **nameEntry;
    ShdSpriteDescriptor *descriptorFields = (ShdSpriteDescriptor *)descriptor;
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
    for (; i < ((ShdSpriteDescriptor *)descriptor)->spriteCount; i += 1) {
        offset = i * 4;
        nameEntry = (const char **)((u8 *)(u32)(MEMBER(s32, descriptor, ShdSpriteDescriptor, names)) + offset);
        size += strlen(*nameEntry) + 1;
    }
    totalSize = size + (size & 1);
    i = ((ShdSpriteDescriptor *)descriptor)->spriteCount * 8;
    i += descriptorFields->remapCount * 8;
    i += 0x14;
    totalSize = (u32)((u8 *)(i) + totalSize);
    chkmemAllocSiteTag(&D_00637280, 0x7E);
    result = D_008873F4[0](1, totalSize, 0x40000);
    ((ShdSpritePack *)result)->loadIndex = 0;
    data = result + 0x14;
    ((ShdSpritePack *)result)->descriptor = (ShdSpriteDescriptor *)data;
    ((ShdSpritePack *)result)->sprites = (u8 **)(data + 0x10);
    memcpy(((ShdSpritePack *)result)->descriptor, descriptor, 0x10);
    cursor = MEMBER(u8 *, result, ShdSpritePack, sprites) + MEMBER(s32, descriptor, ShdSpriteDescriptor, spriteCount) * 4;
    MEMBER(u8 *, MEMBER(u8 *, result, ShdSpritePack, descriptor), ShdSpriteDescriptor, names) = cursor;
    cursor += MEMBER(s32, descriptor, ShdSpriteDescriptor, spriteCount) * 4;
    j = 0;
    for (; j < MEMBER(s32, descriptor, ShdSpriteDescriptor, spriteCount); j += 1) {
        offset = j * 4;
        nameEntry = (const char **)((u8 *)(u32)(MEMBER(s32, descriptor, ShdSpriteDescriptor, names)) + offset);
        length = strlen(*nameEntry) + 1;
        sourceEntry = (const void **)((u8 *)(u32)(MEMBER(s32, descriptor, ShdSpriteDescriptor, names)) + offset);
        memcpy(
            cursor,
            *sourceEntry,
            length);
        destinationEntry = (u8 **)(MEMBER(u8 *, MEMBER(u8 *, result, ShdSpritePack, descriptor), ShdSpriteDescriptor, names) + offset);
        *destinationEntry = cursor;
        cursor += length;
    }
    if (((u32)cursor & 1) != 0) {
        cursor += 1;
    }
    if (((ShdSpriteDescriptor *)descriptor)->remap != NULL) {
        memcpy(
            cursor,
            ((ShdSpriteDescriptor *)descriptor)->remap,
            ((ShdSpriteDescriptor *)descriptor)->remapCount * 8);
        ((ShdSpritePack *)result)->descriptor->remap = (ShdSpriteRemap *)cursor;
        ((ShdSpritePack *)result)->remap = ((ShdSpritePack *)result)->descriptor->remap;
    }
    ((ShdSpritePack *)result)->remapCount = ((ShdSpriteDescriptor *)descriptor)->remapCount;
    return result;
}

/* Advance asynchronous sprite loading in descriptor order, stopping at the first incomplete sprite.
 * A typed s32 table keeps retail's table/index load order. */
// FUN_0025F110
s32 shdSpriteEnsureLoaded(u8 *pack)
{
    u8 **runtimeEntry;
    ShdSpritePack *packFields = (ShdSpritePack *)pack;
    s32 H_Cdvd_LookupRequest(s32, s32 *);
    u8 *sdkSpriteRequestLoad(const char *);
    u32 hMaestroDecodeIsReady(s16 *);
    s32 requestState;
    s32 index;
    s32 offset;
    u8 *result;
    s32 *table;
    s32 loaded;

    table = MEMBER(s32 *, pack, ShdSpritePack, descriptor);
    index = ((ShdSpritePack *)pack)->loadIndex;
    if (index >= table[1]) {
        return 1;
    }
    for (;;) {
        result = (u8 *)((ShdSpritePack *)pack)->sprites;
        offset = index * 4;
        runtimeEntry = (u8 **)(result + offset);
        if (*runtimeEntry == NULL) {
            loaded = H_Cdvd_LookupRequest(
                (s32)((u8 **)MEMBER(u8 *, MEMBER(u8 *, pack, ShdSpritePack, descriptor), ShdSpriteDescriptor, names))[index],
                &requestState);
            if (loaded != 0) {
                packFields->sprites[index] =
                    sdkSpriteAdoptBlob((u32)loaded);
            } else {
                ((u8 **)MEMBER(u8 *, pack, ShdSpritePack, sprites))[index] =
                    sdkSpriteRequestLoad(
                        (const char *)((ShdSpritePack *)pack)->descriptor->
                            names[index]);
            }
        } else {
            if (hMaestroDecodeIsReady(
                    (s16 *)((u8 **)result)[index]) == 0) {
                goto fail;
            }
            ((ShdSpritePack *)pack)->loadIndex = ((ShdSpritePack *)pack)->loadIndex + 1;
        }
        table = MEMBER(s32 *, pack, ShdSpritePack, descriptor);
        index = ((ShdSpritePack *)pack)->loadIndex;
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

/* Returns an integer sprite handle, not a floating-point result. */
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

/* Draw a sprite immediately with default size, rotation, and unit scale; returns zero. */
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

/* Queue a sprite with default size, rotation, and unit scale; returns zero. */
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

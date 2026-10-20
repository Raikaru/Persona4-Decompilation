#include "member_access.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern void mdlEffectReleaseTrackResource(u8 *resource);
extern void mdlEffectSelectResourceEntry(u8 *player, s32 entryIndex);
extern u8 *mdlEffectLoadTrackResource(s32 *source);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 TnUploadStreamTagged(s32 stream);
extern void func_003ef3a0(void *object);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00481f30-004824a0 */

/* Select a resource entry and initialize its single, paired or grouped tracks. */
// FUN_00481F30
void mdlEffectSelectResourceEntry(u8 *player, s32 entryIndex)
{
    s16 childIndex;
    s32 *childEntry;
    s32 *firstEntry;
    s32 *secondEntry;
    s32 *singleEntry;
    s32 entryOffset;
    s32 trackOffset;
    s32 flags;
    u32 hasMore;
    s32 trackIndex;
    u8 *secondTrack;
    u8 *track;
    u8 *entry;
    u8 *firstTrack;
    u8 *singleTrack;
    u8 *resource;
    u8 *child;
    u8 *children;
    u8 *payload;
    u8 *firstPayload;
    u8 *secondPayload;
    u8 *singlePayload;

    resource = (u8 *)((MdlEffectTrackInstance *)player)->resource;
    if (((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount <= entryIndex) {
        kAssertFail(D_007132F0, 0xCB);
    }
    entryOffset = entryIndex * 0x14;
    entry = MEMBER(u8 *, resource, MdlEffectTrackResource, entries) + entryOffset; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
    if (MEMBER(u32, entry, MdlEffectResourceEntry, count) != 0) { /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        if (((MdlEffectResourceEntry *)entry)->kind & 0x10000000) {
            ((MdlEffectTrackInstance *)player)->flags = 0x10000000;
            ((MdlEffectTrackInstance *)player)->entryIndex = entryIndex;
            *(u32 *)&((MdlEffectTrackInstance *)player)->trackCount = MEMBER(u32, entry, MdlEffectResourceEntry, count); /* measured: typing this field access changes MATCH to MISMATCH under b210. */
            children = ((MdlEffectTrackResource *)resource)->image + ((MdlEffectResourceEntry *)entry)->payloadOffset;
            trackIndex = 0;
            goto loop_00481f30_check;
loop_00481f30_body:
            trackOffset = trackIndex * 0x14;
            track = MEMBER(u8 *, player, MdlEffectTrackInstance, tracks) + trackOffset; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
            child = children + trackIndex * 0x18;
            childIndex = ((MdlEffectTrackChild *)child)->entryIndex;
            if (((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount <= childIndex) {
                kAssertFail(D_007132F0, 0xB0);
            }
            childEntry = (s32 *)(((MdlEffectTrackResource *)resource)->entries + childIndex * 0x14);
            payload = ((MdlEffectTrackResource *)resource)->image + *childEntry;
            *(s32 *)&((MdlEffectTrack *)track)->frame = 0;
            *(s32 *)&((MdlEffectTrack *)track)->active = ((MdlEffectTrackFrame *)payload)->delay;
            *(s32 **)&((MdlEffectTrack *)track)->resource = childEntry;
            ((MdlEffectTrack *)track)->payload = payload;
            ((MdlEffectTrack *)((u8 *)((MdlEffectTrackInstance *)player)->tracks + trackOffset))->frame =
                -(s32)((MdlEffectTrackChild *)child)->delay;
            trackIndex += 1;
loop_00481f30_check:
            hasMore = ((MdlEffectResourceEntry *)entry)->count > (u32)trackIndex;
            if (hasMore == 0) {
                goto loop_00481f30_done;
            } else {
                goto loop_00481f30_body;
            }
        } else {
            flags = ((MdlEffectResourceEntry *)entry)->flags;
            if (flags & 0xC0) {
                ((MdlEffectTrackInstance *)player)->flags = flags;
                ((MdlEffectTrackInstance *)player)->entryIndex = entryIndex;
                *(u32 *)&((MdlEffectTrackInstance *)player)->trackCount = 2U;
                firstTrack = MEMBER(u8 *, player, MdlEffectTrackInstance, tracks); /* measured: typing this field access changes MATCH to MISMATCH under b210. */
                if (((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount <= entryIndex) {
                    kAssertFail(D_007132F0, 0xB0);
                }
                firstEntry = (s32 *)(MEMBER(u8 *, resource, MdlEffectTrackResource, entries) + entryOffset); /* measured: typing this field access changes MATCH to MISMATCH under b210. */
                firstPayload = ((MdlEffectTrackResource *)resource)->image + *firstEntry;
                *(s32 *)&((MdlEffectTrack *)firstTrack)->frame = 0;
                *(s32 *)&((MdlEffectTrack *)firstTrack)->active = ((MdlEffectTrackFrame *)firstPayload)->delay;
                *(s32 **)&((MdlEffectTrack *)firstTrack)->resource = firstEntry;
                ((MdlEffectTrack *)firstTrack)->payload = firstPayload;
                secondTrack = (u8 *)((MdlEffectTrackInstance *)player)->tracks + 0x14;
                if (((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount <= (entryIndex + 1)) {
                    kAssertFail(D_007132F0, 0xB0);
                }
                secondEntry =
                    (s32 *)(((MdlEffectTrackResource *)resource)->entries + (entryIndex + 1) * 0x14);
                secondPayload = ((MdlEffectTrackResource *)resource)->image + *secondEntry;
                *(s32 *)&((MdlEffectTrack *)secondTrack)->frame = 0;
                *(s32 *)&((MdlEffectTrack *)secondTrack)->active = ((MdlEffectTrackFrame *)secondPayload)->delay;
                *(s32 **)&((MdlEffectTrack *)secondTrack)->resource = secondEntry;
                ((MdlEffectTrack *)secondTrack)->payload = secondPayload;
            } else {
                ((MdlEffectTrackInstance *)player)->flags = 0;
                ((MdlEffectTrackInstance *)player)->entryIndex = entryIndex;
                *(u32 *)&((MdlEffectTrackInstance *)player)->trackCount = 1U;
                singleTrack = (u8 *)((MdlEffectTrackInstance *)player)->tracks;
                if (((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount <= entryIndex) {
                    kAssertFail(D_007132F0, 0xB0);
                }
                singleEntry = (s32 *)(((MdlEffectTrackResource *)resource)->entries + entryOffset);
                singlePayload = ((MdlEffectTrackResource *)resource)->image + *singleEntry;
                *(s32 *)&((MdlEffectTrack *)singleTrack)->frame = 0;
                *(s32 *)&((MdlEffectTrack *)singleTrack)->active = ((MdlEffectTrackFrame *)singlePayload)->delay;
                *(s32 **)&((MdlEffectTrack *)singleTrack)->resource = singleEntry;
                ((MdlEffectTrack *)singleTrack)->payload = singlePayload;
            }
        }
loop_00481f30_done:
        ((MdlEffectTrackInstance *)player)->active = 1;
    }
}

/* measured: opt_loop_invariants on hoists the second-loop preheader constants. */
/* measured: func_00482230 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off preserves the target pointer evaluation order. */
/* measured: func_00482230 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Copy the resource image, upload streams and find its maximum simultaneous track count. */
// FUN_00482230
u8 *mdlEffectLoadTrackResource(s32 *source)
{
    u8 *resource;
    s32 *streamOffsets;
    s32 allocationSize;
    s32 streamCount;
    s32 offsetOrFlags;
    s32 streamIndex;
    s32 entryIndex;
    u8 *image;
    u8 *header;
    u8 *entry;
    s32 countOrHandle;
    u8 *scratch;
    extern void memcpy(void *dst, void *src, u32 size);
    {
        s32 offset;
        s32 *streamTable;
        offset = *(s32 *)source;
        streamTable = (s32 *)((u8 *)source + offset);
        streamCount = *streamTable;
        streamOffsets = streamTable + 1;
        allocationSize = offset + 0x1C;
        allocationSize += streamCount * 4;
    }
    chkmemAllocSiteTag(D_007132F0, 0x114);
    resource = (u8 *)jtbl_008873E8[0](allocationSize, 0x40000);
    ((MdlEffectTrackResource *)resource)->allocation = resource;
    image = resource + 0x1C;
    memcpy(image, source, *source);
    ((MdlEffectTrackResource *)resource)->image = image;
    MEMBER(u8 *, resource, MdlEffectTrackResource, entries) = image + 8; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
    *(s32 *)&((MdlEffectTrackResource *)resource)->streamCount = streamCount;
    header = ((MdlEffectTrackResource *)resource)->image;
    scratch = header + 8;
    offsetOrFlags = *(s32 *)header;
    MEMBER(u8 *, resource, MdlEffectTrackResource, streams) = /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        (u8 *)((s32)scratch + offsetOrFlags);

    streamIndex = 0;
    while (streamIndex < streamCount) {
        s32 countOrHandle;
        countOrHandle = TnUploadStreamTagged((s32)((u8 *)source + *streamOffsets));
        ((s32 *)((MdlEffectTrackResource *)resource)->streams)[streamIndex] = countOrHandle;
        streamOffsets += 1;
        streamIndex += 1;
    }
    ((MdlEffectTrackResource *)resource)->references = 1;
    MEMBER(s32, resource, MdlEffectTrackResource, trackCount) = 1; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
    countOrHandle = ((MdlEffectResourceImage *)((MdlEffectTrackResource *)resource)->image)->entryCount;
    entryIndex = 0;
    while (entryIndex < countOrHandle) {
        entry = ((MdlEffectTrackResource *)resource)->entries + (entryIndex * 0x14);
        if ((((MdlEffectResourceEntry *)entry)->kind & 0x10000000) != 0) {
            ((MdlEffectTrackResource *)resource)->trackCount = (s32)((MdlEffectResourceEntry *)entry)->count;
        } else {
            offsetOrFlags = ((MdlEffectResourceEntry *)entry)->flags;
            if ((offsetOrFlags & 0x40) != 0) {
                ((MdlEffectTrackResource *)resource)->trackCount = 2;
            } else if ((offsetOrFlags & 0x80) != 0) {
                ((MdlEffectTrackResource *)resource)->trackCount = 2;
            }
        }
        entryIndex += 1;
    }
    return resource;
}

/* measured: restore opt_propagation after func_00482230. */
/* measured: restore opt_loop_invariants after func_00482230. */
/* Release one resource reference; the last owner releases every uploaded stream and the allocation. */
// FUN_004823E0
void mdlEffectReleaseTrackResource(u8 *resource) {
    s32 references;
    s32 streamIndex;

    if ((resource == NULL) || (((MdlEffectTrackResource *)resource)->references == 0)) {
        kAssertFail(D_007132F0, 0x151);
    }
    references = ((MdlEffectTrackResource *)resource)->references - 1;
    ((MdlEffectTrackResource *)resource)->references = references;
    if (references == 0) {
        streamIndex = 0;
        goto loop_004823e0_check;
loop_004823e0_body:
        func_003ef3a0(((void **)((MdlEffectTrackResource *)resource)->streams)[streamIndex]);
        streamIndex += 1;
loop_004823e0_check:
        if (streamIndex < *(s32 *)&((MdlEffectTrackResource *)resource)->streamCount) {
            goto loop_004823e0_body;
        }
        (*jtbl_008873EC)(((MdlEffectTrackResource *)resource)->allocation);
    }
}

/* Advance a track and build its quad bounds, texture selection and normalized fixed-point UVs. */
// FUN_004824A0
void mdlEffectAdvanceTrackQuad(u8 *player, u8 *track, u8 *output)
{
    f32 height;
    f32 width;
    f32 originY;
    f32 originX;
    f32 textureWidth;
    f32 textureHeight;
    s32 flags;
    s32 delay;
    s32 frameValue;
    u32 nextFrame;
    u32 frameIndex;
    u8 **texture;
    u8 *resource;
    u8 *frame;
    u8 *payload;
    u8 *entry;

    resource = (u8 *)((MdlEffectTrackInstance *)player)->resource;
    entry = ((MdlEffectTrack *)track)->resource;
    if ((MEMBER(s32, entry, MdlEffectResourceEntry, kind) & 0x10000000) == 0) { /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        delay = MEMBER(s32, track, MdlEffectTrack, active); /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        if (delay <= 0) {
            nextFrame = MEMBER(u32, track, MdlEffectTrack, frame) + 1; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
            MEMBER(u32, track, MdlEffectTrack, frame) = nextFrame; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
            if (nextFrame >= MEMBER(u32, entry, MdlEffectResourceEntry, count)) { /* measured: typing this field access changes MATCH to MISMATCH under b210. */
                if ((((MdlEffectResourceEntry *)entry)->kind & 0x10) != 0) {
                    ((MdlEffectTrackInstance *)player)->active = 0;
                    ((MdlEffectTrack *)track)->frame = ((MdlEffectResourceEntry *)entry)->count - 1;
                } else {
                    ((MdlEffectTrack *)track)->frame = 0;
                }
            }
            payload = ((MdlEffectTrack *)track)->payload;
            frameIndex = ((MdlEffectTrack *)track)->frame;
            frame = (u8 *)(frameIndex * 0x18);
            frame = (u8 *)((u32)frame + (u32)payload);
            *(s32 *)&((MdlEffectTrack *)track)->active = ((MdlEffectTrackFrame *)frame)->delay;
        } else {
            *(s32 *)&((MdlEffectTrack *)track)->active = delay - 1;
        }
        frameIndex = ((MdlEffectTrack *)track)->frame;
        frame = ((MdlEffectTrack *)track)->payload + (frameIndex * 0x18);
        flags = MEMBER(s32, entry, MdlEffectResourceEntry, kind); /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        if ((flags & 1) != 0) {
            frameValue = ((s32 *)(((MdlEffectTrackResource *)resource)->image + *(s32 *)&((MdlEffectResourceEntry *)entry)->unk4))[frameIndex]; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
        } else {
            frameValue = -1;
        }
        ((MdlEffectTrackOutput *)output)->frameValue = frameValue;
        texture = ((u8 ***)((MdlEffectTrackResource *)resource)->streams)[((MdlEffectTrackFrame *)frame)->textureIndex];
        payload = *texture;
        textureWidth = (f32)((MdlEffectRaster *)payload)->width;
        textureHeight = (f32)((MdlEffectRaster *)payload)->height;
        flags = ((MdlEffectResourceEntry *)entry)->kind;
        if ((flags & 2) != 0) {
            ((MdlEffectTrackOutput *)output)->mode = 2;
        } else if ((flags & 4) != 0) {
            ((MdlEffectTrackOutput *)output)->mode = 3;
        } else {
            ((MdlEffectTrackOutput *)output)->mode = 1;
        }
        ((MdlEffectTrackOutput *)output)->value = ((MdlEffectTrackFrame *)frame)->value;
        originX = (f32)((MdlEffectTrackFrame *)frame)->originX;
        originY = (f32)((MdlEffectTrackFrame *)frame)->originY;
        width = (f32)((MdlEffectTrackFrame *)frame)->width;
        height = (f32)((MdlEffectTrackFrame *)frame)->height;
        ((MdlEffectTrackOutput *)output)->u0 =
            (f32)((s32)((MdlEffectTrackFrame *)frame)->left >> 4) / textureWidth;
        ((MdlEffectTrackOutput *)output)->v0 =
            (f32)((s32)((MdlEffectTrackFrame *)frame)->top >> 4) / textureHeight;
        ((MdlEffectTrackOutput *)output)->u1 =
            (f32)((s32)((MdlEffectTrackFrame *)frame)->right >> 4) / textureWidth;
        ((MdlEffectTrackOutput *)output)->v1 =
            (f32)((s32)((MdlEffectTrackFrame *)frame)->bottom >> 4) / textureHeight;
        width = width / 2.0f;
        height = height / 2.0f;
        ((MdlEffectTrackOutput *)output)->left = width - originX;
        ((MdlEffectTrackOutput *)output)->top = height - originY;
        ((MdlEffectTrackOutput *)output)->right = width;
        ((MdlEffectTrackOutput *)output)->bottom = height;
        ((MdlEffectTrackOutput *)output)->textureWidth = textureWidth;
        ((MdlEffectTrackOutput *)output)->textureHeight = textureHeight;
        ((MdlEffectTrackOutput *)output)->texture = (u8 *)texture;
    }
}

























































































































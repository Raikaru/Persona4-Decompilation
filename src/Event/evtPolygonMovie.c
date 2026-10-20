#include "include_asm.h"
/* Original translation unit evtPolygonMovie.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scene_event_internal.h"
#include "evt_movie_internal.h"

typedef signed __int128 s128;

typedef struct {
    s128 a;
    s128 b;
} s2x128;

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void kAssertFail(u8 *file, s32 line);
extern void evtMemAccount(s32, s32);
extern void memcpy(void *dst, void *src, u32 size);
extern void memset(void *dst, s32 value, u32 size);
extern void sprintf();
extern void MT_Scene_GetAngleDelta(f32 *start, f32 *end, f32 *output);
extern void MT_Scene_WrapAngles(f32 *angles);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063C6A0[];
extern u8 D_0063C7A0[];
extern u8 D_0063C7C0[];
extern u8 D_0063C7E0[];
extern u8 D_0063C800[];
extern void (*jtbl_008873EC[])(void *ptr);
extern s128 D_0063C700; /* default primary-section header, 0x20 bytes */
extern s128 D_0063C710;
extern s128 D_0063C720[]; /* default secondary section, 0x54 bytes */
extern s128 D_0063C780; /* default overlay-section header, 0x20 bytes */
extern s128 D_0063C790;

/* Without opt_loop_invariants the two lerp loops allocate the s2 value into
   $f0 (sub.s $f1,$f0,$f2, mtc1 $0,$f0 re-materialized inside the loop, madd.s
   result in $f0) vs retail's $f1 with the mtc1 hoisted to the preheader;
   expression variants (temps, product-first, (int)-cast addressing) never
   moved the allocation. measured: pragma on nd ~110 -> 0. */
#pragma opt_loop_invariants on

/* Blend pose vectors and shortest-path angles; a missing toPose copies fromPose. */
// FUN_0028F990
void evtPolygonMovieLerpPose(s32 enabled, f32 blend, f32 *fromPose, f32 *toPose, f32 *outPose)
{
    f32 fromAngles[4];
    f32 toAngles[4];
    f32 angleDelta[4];
    f32 blendedAngles[4];
    f32 *destination;
    f32 *source;

    source = fromPose;
    destination = outPose;
    if (destination == NULL) {
        kAssertFail(D_0063C6A0, 0x8F);
    }
    if (enabled == 0) {
        blend = 0.0f;
    }
    if (source != NULL) {
        if (toPose == NULL) {
            s32 pairsRemaining = 6;

            do {
                /* Copy float representations in word pairs without changing their bits. */
                s32 firstWord = *(s32 *)source;
                s32 secondWord = *(s32 *)(source + 1);

                source += 2;
                pairsRemaining -= 1;
                *(s32 *)destination = firstWord;
                *(s32 *)(destination + 1) = secondWord;
                destination += 2;
            } while (pairsRemaining > 0);
            return;
        }
        {
            s32 component;

            for (component = 0; component < 4; component++) {
                destination[component + 8] = source[component + 8] + blend * (toPose[component + 8] - source[component + 8]);
            }
        }
        {
            s32 component;

            for (component = 0; component < 4; component++) {
                destination[component] = source[component] + blend * (toPose[component] - source[component]);
            }
        }
        fromAngles[0] = source[4];
        fromAngles[1] = source[5];
        fromAngles[2] = source[6];
        toAngles[0] = toPose[4];
        toAngles[1] = toPose[5];
        toAngles[2] = toPose[6];
        MT_Scene_GetAngleDelta(&fromAngles[0], &toAngles[0], &angleDelta[0]);
        blendedAngles[0] = angleDelta[0] * blend + source[4];
        blendedAngles[1] = angleDelta[1] * blend + source[5];
        blendedAngles[2] = angleDelta[2] * blend + source[6];
        MT_Scene_WrapAngles(&blendedAngles[0]);
        destination[4] = blendedAngles[0];
        destination[5] = blendedAngles[1];
        destination[6] = blendedAngles[2];
    }
}
#pragma opt_loop_invariants off

// Intent: Allocates the 0x114-byte movie work block, accounts its memory and returns it zeroed [inferred]
// FUN_0028FB90
u8 *evtPolygonMovieAlloc(void)
{
    u8 *work;

    chkmemAllocSiteTag(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x114, 0x40000);
    evtMemAccount(1, 0x114);
    if (work == NULL) {
        kAssertFail(D_0063C6A0, 0x12D);
        return NULL;
    }
    memset(work, 0, 0x114);
    return work;
}

/* Bind the resource sections into the existing movie work object. Keep the
   work-field reloads between writes and callbacks, and stop before overlay
   setup when the secondary resource is absent.
   Measured b210: 2088/2096 bytes, 16 resolved relocations and eight zero tail
   bytes. Direct parameters with lifetime analysis preserve the retail entry
   moves; propagation-off and loop-invariant analysis preserve the traversals.
   See docs/probe_archive/evtPolygonMovie_0028fc40_167e607.md. */
// Intent: Binds the primary, secondary and overlay resource sections into the work block; opens the message window when one is bound [inferred]
/* measured: each remaining raw work access lost MATCH when typed individually;
 * member-address hoisting in the fully typed body grew code from 2088 to 2708 bytes. */
// FUN_0028FC40
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
u8 *evtPolygonMovieBind(u8 *messageContext, u8 *work, u8 *primary, u8 *secondary, u8 *overlay)
{
    s32 recordIndex;
    u8 *entry;
    s32 code;
    s32 overlayIndex;
    u8 *primaryRecords;
    u8 *secondaryRecords;
    u8 *overlayRecords;
    extern s32 evtMessageWindowOpen(u8 *, s32);
    extern s32 func_00440b68(const char *, ...);
    extern char D_0063C6C0[];
    extern char D_0063C6E0[];

    if (primary == NULL) {
        kAssertFail(D_0063C6A0, 0x155);
        return NULL;
    }
    ((EvtPolygonMovieWork *)work)->flags = 0;
    *(u8 **)(work + 0x10) = primary;
    *(u8 **)(work + 0x14) = primary + 0x20;
    ((EvtPolygonMovieWork *)work)->unk18 = NULL;
    *(s32 *)(work + 0x1C) = 0;
    ((EvtPolygonMovieWork *)work)->unk20 = NULL;
    *(s32 *)(work + 0x24) = 0;
    ((EvtPolygonMovieWork *)work)->unk28 = NULL;
    ((EvtPolygonMovieWork *)work)->unk2C = NULL;
    ((EvtPolygonMovieWork *)work)->unk30 = NULL;
    ((EvtPolygonMovieWork *)work)->unk34 = NULL;
    *(s32 *)(work + 0x38) = 0;
    ((EvtPolygonMovieWork *)work)->unk3C = NULL;
    ((EvtPolygonMovieWork *)work)->unk40 = NULL;
    *(s32 *)(work + 0x44) = 0;
    ((EvtPolygonMovieWork *)work)->unk48 = NULL;
    *(s32 *)(work + 0x50) = 0;
    *(s32 *)(work + 0x4C) = 0;
    ((EvtPolygonMovieWork *)work)->unk54 = NULL;
    *(s32 *)(work + 0x58) = 0;
    ((EvtPolygonMovieWork *)work)->unk5C = NULL;
    for (recordIndex = 0; recordIndex < ((EvtMovieFileHeader *)((EvtPolygonMovieWork *)work)->primary)->recordCount; recordIndex++) {
        primaryRecords = *(u8 **)(work + 0x14);
        entry = primaryRecords + recordIndex * 0x10;
        code = ((EvtMovieSection *)entry)->code;
        if (code == 0x1B) {
            continue;
        }
        switch (code) {
        case 2:
            *(u8 **)(work + 0x20) = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count24 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 10:
            *(u8 **)(work + 0x28) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        case 11:
            *(u8 **)(work + 0x2C) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        case 12:
            *(u8 **)(work + 0x30) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        case 3:
            *(u8 **)(work + 0x34) = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count38 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 9:
            *(u8 **)(work + 0x3C) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        case 1:
            *(u8 **)(work + 0x18) = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count1C = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 6:
            ((EvtPolygonMovieWork *)work)->message = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count50 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 7:
            *(u8 **)(work + 0x40) = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count44 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 8:
            *(u8 **)(work + 0x48) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        case 22:
            *(u8 **)(work + 0x54) = primary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count58 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->primaryRecords + recordIndex * 0x10))->count;
            break;
        case 23:
            *(u8 **)(work + 0x5C) = primary + ((EvtMovieSection *)entry)->offset;
            break;
        default:
            kAssertFail(D_0063C6A0, 0x1C3);
            break;
        }
    }
    *(u8 **)(work + 0x80) = secondary;
    if (secondary != NULL) {
        *(u8 **)(work + 0x84) = secondary + 0x20;
    } else {
        ((EvtPolygonMovieWork *)work)->secondaryRecords = NULL;
    }
    ((EvtPolygonMovieWork *)work)->unk88 = NULL;
    *(s32 *)(work + 0x8C) = 0;
    ((EvtPolygonMovieWork *)work)->unk90 = NULL;
    *(s32 *)(work + 0x94) = 0;
    *(s32 *)(work + 0xAC) = 0;
    ((EvtPolygonMovieWork *)work)->unkB0 = NULL;
    *(s32 *)(work + 0xB4) = 0;
    ((EvtPolygonMovieWork *)work)->unkB8 = NULL;
    *(s32 *)(work + 0xBC) = 0;
    ((EvtPolygonMovieWork *)work)->unkC0 = NULL;
    *(s32 *)(work + 0xC4) = 0;
    ((EvtPolygonMovieWork *)work)->unkC8 = NULL;
    *(s32 *)(work + 0xCC) = 0;
    ((EvtPolygonMovieWork *)work)->unkD0 = NULL;
    *(s32 *)(work + 0xD4) = 0;
    ((EvtPolygonMovieWork *)work)->unkD8 = NULL;
    *(s32 *)(work + 0xDC) = 0;
    ((EvtPolygonMovieWork *)work)->unkE0 = NULL;
    *(s32 *)(work + 0xE4) = 0;
    ((EvtPolygonMovieWork *)work)->unkE8 = NULL;
    *(s32 *)(work + 0xEC) = 0;
    ((EvtPolygonMovieWork *)work)->unkF0 = NULL;
    *(s32 *)(work + 0xF4) = 0;
    ((EvtPolygonMovieWork *)work)->unk100 = NULL;
    *(s32 *)(work + 0x104) = 0;
    ((EvtPolygonMovieWork *)work)->unkF8 = NULL;
    *(s32 *)(work + 0xFC) = 0;
    ((EvtPolygonMovieWork *)work)->unk108 = NULL;
    *(s32 *)(work + 0x10C) = 0;
    ((EvtPolygonMovieWork *)work)->unk60 = NULL;
    *(s32 *)(work + 0x64) = 0;
    if (secondary == NULL) {
        return work;
    }
    func_00440b68(D_0063C6C0, ((EvtMovieFileHeader *)((EvtPolygonMovieWork *)work)->secondary)->recordCount);
    for (recordIndex = 0; recordIndex < ((EvtMovieFileHeader *)*(u8 **)(work + 0x80))->recordCount; recordIndex++) {
        secondaryRecords = *(u8 **)(work + 0x84);
        entry = secondaryRecords + recordIndex * 0x10;
        code = ((EvtMovieSection *)entry)->code;
        switch (code) {
        case 0:
            *(u8 **)(work + 0x90) = secondary + ((EvtMovieSection *)entry)->offset;
            break;
        case 4:
            if (((EvtMovieFileHeader *)*(u8 **)(work + 0x80))->version == 4) {
                ((EvtPolygonMovieWork *)work)->unk94 = secondary + ((EvtMovieSection *)entry)->offset;
                ((EvtPolygonMovieWork *)work)->unk98 = NULL;
            } else {
                ((EvtPolygonMovieWork *)work)->unk98 = secondary + ((EvtMovieSection *)entry)->offset;
                ((EvtPolygonMovieWork *)work)->unk94 = NULL;
            }
            ((EvtPolygonMovieWork *)work)->countAC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 1:
            *(u8 **)(work + 0x88) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count8C = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 5:
            *(u8 **)(work + 0xB0) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countB4 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 13:
            *(u8 **)(work + 0xB8) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countBC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 14:
            *(u8 **)(work + 0xC0) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countC4 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 15:
            *(u8 **)(work + 0xC8) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countCC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 16:
            *(u8 **)(work + 0xD0) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countD4 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 17:
            *(u8 **)(work + 0xD8) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countDC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 18:
            *(u8 **)(work + 0xE0) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countE4 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 19:
            *(u8 **)(work + 0xE8) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countEC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 20:
            *(u8 **)(work + 0xF0) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countF4 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 24:
            *(u8 **)(work + 0xF8) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countFC = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 21:
            *(u8 **)(work + 0x100) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count104 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            func_00440b68(D_0063C6E0);
            break;
        case 25:
            *(u8 **)(work + 0x108) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count10C = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        case 26:
            *(u8 **)(work + 0x60) = secondary + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->count64 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->secondaryRecords + recordIndex * 0x10))->count;
            break;
        default:
            kAssertFail(D_0063C6A0, 0x24D);
            break;
        }
    }
    if (*(u8 **)(work + 0x90) != NULL) {
        if (((EvtPolygonMovieWork *)work)->message != NULL && ((EvtPolygonMovieWork *)work)->count50 > 0) {
            evtMessageWindowOpen(messageContext, (s32)((EvtPolygonMovieWork *)work)->message);
        }
    }
    *(u8 **)(work + 0x9C) = overlay;
    if (overlay != NULL) {
        *(u8 **)(work + 0xA0) = overlay + 0x20;
    } else {
        ((EvtPolygonMovieWork *)work)->overlayRecords = NULL;
    }
    ((EvtPolygonMovieWork *)work)->unkA4 = NULL;
    *(s32 *)(work + 0xA8) = 0;
    if (overlay == NULL) {
        return work;
    }
    for (overlayIndex = 0; overlayIndex < ((EvtMovieFileHeader *)((EvtPolygonMovieWork *)work)->overlay)->recordCount; overlayIndex++) {
        overlayRecords = *(u8 **)(work + 0xA0);
        entry = overlayRecords + overlayIndex * 0x10;
        code = ((EvtMovieSection *)entry)->code;
        switch (code) {
        case 4:
            *(u8 **)(work + 0xA4) = overlay + ((EvtMovieSection *)entry)->offset;
            ((EvtPolygonMovieWork *)work)->countA8 = ((EvtMovieSection *)(((EvtPolygonMovieWork *)work)->overlayRecords + overlayIndex * 0x10))->count;
            break;
        default:
            break;
        }
    }
    return work;
}
#pragma pop
// Intent: Frees the movie: closes its message window when active, then releases the block (accounts -0x114) [inferred]
// FUN_00290470
void evtPolygonMovieFree(s32 *movie, u32 *messageWindow)
{
    if (movie != NULL) {
        if (evtMessageWindowIsOpen(messageWindow) == 1) {
            evtMessageWindowClose(messageWindow);
        }
        jtbl_008873EC[0](movie);
        evtMemAccount(1, -0x114);
    }
}

/* Copy the static 0x20-byte table into outTable, charging memory account 4. */
// FUN_002904F0
s32 *evtPolygonMovieAllocTableA(s32 **outTable)
{
    s2x128 tableCopy;
    s32 *table;

    tableCopy = *(s2x128 *)&D_0063C700;
    chkmemAllocSiteTag(D_00748340, 0x52);
    table = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    evtMemAccount(4, 0x20);
    memcpy(table, &tableCopy, 0x20);
    *outTable = table;
    return table;
}

/* Copy the static 0x54-byte table into outTable, charging memory account 5. */
// FUN_002905A0
s32 *evtPolygonMovieAllocTableB(s32 **outTable)
{
    u8 tableCopy[0x54];
    s128 *src;
    s128 *dst;
    s32 count;
    s32 *table;

    src = &D_0063C720[0];
    dst = (s128 *)&tableCopy[0];
    count = 5;
    do {
        s128 chunk;

        chunk = *src;
        src++;
        count--;
        *dst = chunk;
        dst++;
    } while (count > 0);
    *(f32 *)dst = *(f32 *)src;
    chkmemAllocSiteTag(D_00748340, 0x52);
    table = (s32 *)D_008873F4[0](1, 0x54, 0x40000);
    evtMemAccount(5, 0x54);
    memcpy(table, &tableCopy[0], 0x54);
    *outTable = table;
    return table;
}

/* Copy the static 0x20-byte table into outTable, charging memory account 6. */
// FUN_00290660
s32 *evtPolygonMovieAllocTableC(s32 **outTable)
{
    s2x128 tableCopy;
    s32 *table;

    tableCopy = *(s2x128 *)&D_0063C780;
    chkmemAllocSiteTag(D_00748340, 0x52);
    table = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    evtMemAccount(6, 0x20);
    memcpy(table, &tableCopy, 0x20);
    *outTable = table;
    return table;
}

// Intent: Formats the four name strings for a frame number (rounded down to tens) with the four D_0063C7A0..7C0 formats [inferred]
// FUN_00290710
void evtPolygonMovieFormatNames(s32 frame, s32 variant, u8 *primaryName, u8 *secondaryName, u8 *overlayName, u8 *extraName)
{
    s32 frameGroup;

    if (primaryName == 0) {
        kAssertFail(D_0063C6A0, 0x36B);
    }
    if (secondaryName == 0) {
        kAssertFail(D_0063C6A0, 0x36C);
    }
    if (overlayName == 0) {
        kAssertFail(D_0063C6A0, 0x36D);
    }
    if (extraName == 0) {
        kAssertFail(D_0063C6A0, 0x36E);
    }
    frameGroup = (frame / 10) * 10;
    sprintf(primaryName, D_0063C7A0, frameGroup, frame, variant);
    sprintf(secondaryName, D_0063C7C0, frameGroup, frame, variant);
    sprintf(overlayName, D_0063C7E0, frameGroup, frame, variant);
    sprintf(extraName, D_0063C800, frameGroup, frame, variant);
}

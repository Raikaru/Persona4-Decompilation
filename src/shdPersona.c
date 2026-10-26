/* Original translation unit shdPersona.c (from __FILE__ assert strings). */
#include "type.h"
#include "member_access.h"
#include "sdk_task_registration.h"
#include "sdk_snd_internal.h"
#include "sdktask.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "shd_misc_internal.h"
#include "shdPersona_internal.h"
#include "datUnit_internal.h"
#include "shd_skill_internal.h"
#include "mdl_effect_internal.h"

/* Channel presets use a 0x14-byte stride in setup and comparison reset. */
typedef struct ShdPersonaChannelPreset {
    Vec2f position;
    u8 alpha;
    u8 pad9[3];
    f32 startFrame, endFrame;
} ShdPersonaChannelPreset;
/* The level-up caller indexes 32 halfword skills and five signed stat gains. */
typedef struct ShdPersonaLearnList {
    u16 unk0;
    u16 skills[32];
    u8 pad42[0x40];
    s8 statGains[5];
} ShdPersonaLearnList;

/* Model loader and its display interpolator share the 0x154-byte allocation. */
typedef struct ShdPersonaModelWork {
    s32 state, resourceId, handle, color;
    s32 frame, drawGauge;
    f32 depth, duration;
    Vec2f start, current, target, offset, committed;
    s32 stream, directory, loaded;
    u8 path[0x100];
} ShdPersonaModelWork;

/* Deferred stream-close tasks allocate only these first two words. */
typedef struct ShdPersonaStreamWork { s32 stream, directory; } ShdPersonaStreamWork;

/* The effect owns 24 independent frame/duration pairs, stored in parallel. */
typedef struct ShdPersonaEffect {
    u16 flags, frame, rotationFrame, pulseFrame;
    u16 particleFrames[24];
    u16 particleDurations[24];
} ShdPersonaEffect;
typedef struct ShdPersonaParticle { u16 frame, duration; } ShdPersonaParticle;
typedef struct ShdPersonaBackdrop {
    u16 frame;
    u8 pad2[2];
    u32 bonus;
    ShdPersonaParticle particles[10];
} ShdPersonaBackdrop;
typedef struct ShdPersonaAcquisition { u16 flags, frame, skill; } ShdPersonaAcquisition;
/* Renderer view of the 0x24-byte animated panels and task work; unnamed spans hold fields this
 * renderer does not use. */
typedef struct PersonaRenderChannel {
    Vec2f start;
    Vec2f target;
    Vec2f current;
    u8 startAlpha;
    u8 targetAlpha;
    u8 alpha;
    u8 unknown1b;
    f32 duration;
    f32 delay;
} PersonaRenderChannel;

typedef struct PersonaRenderRecord {
    u16 category;
    u16 id;
    u8 level;
    u8 unknown05[2];
    u8 values[5];
    u8 added[5];
    u8 unknown11[3];
    s32 affinities[7];
    u8 unknown30[8];
    u32 nextExperience;
} PersonaRenderRecord;

typedef struct PersonaRenderWork {
    s32 controllerAddress;
    s32 unk4, unk8;
    PersonaRenderRecord persona[2];
    u8 skills[0x234];
    s32 sprites[4];
    s32 backdropTexture;
    PersonaRenderChannel channels[10];
    Vec2f selectionStart, selectionTarget;
    Vec2f selectionPosition;
    u8 selectionStartAlpha, selectionTargetAlpha, selectionAlpha, unk44F;
    f32 selectionStartFrame, selectionEndFrame;
    union { u8 effect[0x68]; ShdPersonaEffect effectState; };
    ShdPersonaBackdrop backdrop;
    ShdPersonaAcquisition acquisition;
    u8 pad4F6[2];
    u8 *model;
    Vec2f origin;
    u8 startAlpha;
    u8 alpha;
    u8 targetAlpha, unk507;
    s16 openingFrame;
    u8 pad50A[2];
    s32 openDuration, closeDuration;
    s16 selectionFrame;
    s16 comparisonFrame;
    s16 skillFrame;
    s16 selectedSkill;
    f32 selectedSkillFade;
    s16 revealFrame;
    s16 revealPulseFrame, revealLabelFrame;
    s16 meterPhase;
    s32 overlayId;
    s32 state, unk530;
    s32 flags;
    s32 phase;
    f32 opacity;
    union {
        u8 drawNode[0x30];
        struct {
            s32 next, previous;
            void (*callback)(u8 *, u8 *);
            u8 padC[4];
            u8 *argument;
            u8 pad14[0x1C];
        } drawCommand;
    };
    u16 queueIndex;
    u8 pad572[2];
} PersonaRenderWork;

typedef struct KwlnTask KwlnTask;

u16 datPersonaGetRecordId(u16 partyId);

typedef unsigned int ShdByte __attribute__((mode(QI)));

void shdPersonaDispCtlSetHandle(u8 *task, s32 inputHandle);
void shdPersonaDispCtlSetPosition(u8 *task, u8 *position);
void sdkSpriteDrawOnceTinted(s32, s32, s32, f32, f32, u8, u8, u8, u8, f32, s32);
void shdPersonaDispCtlSetOffsets(u8 *task, Vec2f *inputStart, Vec2f *inputTarget);
void shdPersonaSetupChannels();
void shdPersonaBeginOpen();
void shdPersonaDispCtlSetColor(s32, s32);
void kwlnTaskDestroyHierarchyAlt(s32);
s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
void shdPersonaBeginClose();
s32 ShdSkill_MoveCursor(u8 *state, s32 force);
u16 ShdSkill_GetSlotSkillId(u8 *);
void shdPersonaDrawRowNumber(Vec2f, f32, u8, s16 *);
void shdPersonaDrawDetailPanel(Vec2f, f32, u8, s16 *);
extern char iGpffff9c0c;
extern char iGpffff9c08;

u8 *datPersonaGetRow(u16 personaId);
u8 *resourceFindByName(char *name);
void shdPersonaDrawNamePlate(s64, f32, u8, u8 *, s32 *);
void shdPersonaDrawExpRow(s64, f32, u8, u8 *, s32 *);
void shdPersonaDrawFramePair(s64, f32, u8, u8 *, s32 *);
void shdPersonaDrawArcanaBadge(s64, f32, u8, u8 *, s32 *);
void shdPersonaDrawAffinityPanel(Vec2f, f32, u8, u8 *, s32 *);
void shdPersonaDrawGaugeBar(Vec2f, f32, u8, u8, u8, s16, s32);
void PrimDrawFlatRectangle(u8 *, f32 *, f32, s32);
/* Canonical nLine order is (position, alpha, setIndex, depthOffset). Reordering
 * these calls changes evaluation/regalloc (nd 35); see docs/port/retail_argument_repairs.md. */
void nLineDrawSet(Vec2f, f32, u8, s32);
extern s32 (*D_00887300[])(s32, void *);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];

void kAssertFail(void *file, s32 line);
void memset(void *dst, s32 value, s32 size);
s32 datPersonaAddSkill(u8 *, u16);
void ShdSkill_AddActiveSkill(u16, u8 *);
void shdPersonaFillStatusBlock();
u32 datPersonaGetExpForLevel(void *persona, u16 level);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s32 datPersonaGetExp();
s32 datPersonaReplaceSkill(u8 *, s16, u16);
void ShdSkill_ReplaceActiveSkill(u16, u16, u8 *);
s32 shdPersonaDispCtlCreate(s32, s32, char *);
void H_Cdvd_Destroy();
void func_003ef3a0();
void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern char D_005E4810[];
extern char D_005E4EB0[];
extern char D_005E4F50[];
extern char D_005E4F10[];
void shdPersonaTaskInit(u8 *, s32, s32, s32);
s32 shdPersonaTaskUpdate(u8 *);
void shdPersonaDestroy(u8 *);
s32 shdPersonaLoadModelStep(u8 *);
void shdPersonaModelDestroy(u8 *);
u8 *shdPersonaModelCreate(s32, s32, f32, s32, s32);
void shdPersonaDispCtlSetDrawOffset(u8 *, Vec2f);
void shdDrawColourQuad(f32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
s32 RpSkyRenderStateSet(s32, void *);
s32 shdPersonaSkillReplaceStep(u8 *);
void shdPersonaSkillReplaceDestroy(u8 *);
extern s32 D_005E4850[];
extern char iGpffff9c20;
extern u8 D_005E4950[];
extern u8 D_005E4880[];
extern u8 D_005E4A20[];
extern u8 D_005E4AF0[];
extern u8 D_005E4BC0[];
extern u8 D_005E4C90[];
void strcpy(void *dst, s32 value);
void nmMesWindowSetCurrentString(s32 variable, void *text);
void sprintf(void *dst, void *fmt, s32 value);
s32 nmMesWindowShowCurrentRecord(s32 recordIndex);
s32 nmMesWindowSetCurrentParam(s32 recordIndex);
void nmMesWindowSetCurrentFlag(u8 cursor);
void nmMesWindowRequestRefresh(void);
u8 *func_00243840(s32 skillId);
s32 shdPersonaPickRandomSkillPair(u8 *);
void shdPersonaEndSelection(u8 *, s32);
void shdPersonaSetDisplayState(u8 *, s32, u32, s8);
void shdPersonaDrawQuadStrips(f32, s32, s32, f32, f32, s32, s32, s32);
u32 shdPersonaDispCtlIsLoaded(u8 *);
f32 sinf(f32);
f32 cosf(f32);
extern f32 D_007613EC;
extern f32 D_00761184;
s32 filerTakeCompletedRequest();
s32 func_00440b68();
extern char D_005E4ED0[];
extern char D_005E4EF0[];
void sdkSndStartChannel(s16 channelIndex, const char *path);
extern char D_005E4868[];
extern char D_005E4E20[];
extern char D_005E4E40[];
extern u8 D_00793E80[];

extern void (*jtbl_008873EC[])(void *);


// Return the EXP still needed to reach the next level after extraLevels extra levels, or 0 at max
// level.
// FUN_00115890
s32 shdPersonaCalcExpRemaining(DatPersonaRecord *persona, s32 extraLevels)
{
    u8 c = persona->level;
    s32 s17;
    s32 r;
    if (c == 0x63) {
        return 0;
    }
    s17 = c + (extraLevels & 0xFF);
    if (s17 > 0x63) {
        kAssertFail(D_005E4868, 0x65);
    }
    s17 = datPersonaGetExpForLevel(persona, (u16)(s17 + 1));
    r = s17 - datPersonaGetExp(persona);
    if (r < 0) {
        return 0;
    }
    return r;
}


/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s8 datPersonaGetLevel(DatPersonaRecord *persona);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s8 datPersonaGetStat(DatPersonaRecord *persona, s32 statIndex);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s8 datPersonaGetBuffedStat(DatPersonaRecord *persona, s32 statIndex);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s8 datPersonaGetTotalStat(DatPersonaRecord *persona, s32 statIndex);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
s32 datPersonaRunSkillSlot(u8 *persona, u16 slotIndex);
extern u16 D_007465D0[];
// Fill a persona status block with level, EXP to next level, five stats (base, buffed or total by
// mode) and seven skill slots.
// FUN_00115940
void shdPersonaFillStatusBlock(DatPersonaRecord *persona, u8 *status, s32 statMode)
{
    s32 v2;
    u8 b4;
    s32 i;

    if (persona == NULL) {
        kAssertFail(D_005E4868, 0x76);
    }
    ((PersonaRenderRecord *)status)->id = persona->id;
    *(s8 *)&((PersonaRenderRecord *)status)->level = datPersonaGetLevel(persona);
    b4 = persona->level;
    if (b4 == 0x63) {
        v2 = 0;
    } else {
        if ((s32)b4 > 0x63) {
            kAssertFail(D_005E4868, 0x65);
        }
        v2 = datPersonaGetExpForLevel(persona, (b4 + 1) & 0xFFFF) - datPersonaGetExp(persona);
        if (v2 < 0) {
            v2 = 0;
        }
    }
    *(s32 *)&((PersonaRenderRecord *)status)->nextExperience = v2;
    switch (statMode) {
    case 0:
        *(s8 *)&((PersonaRenderRecord *)status)->values[0] = datPersonaGetStat(persona, 0);
        *(s8 *)&((PersonaRenderRecord *)status)->values[1] = datPersonaGetStat(persona, 1);
        *(s8 *)&((PersonaRenderRecord *)status)->values[2] = datPersonaGetStat(persona, 2);
        *(s8 *)&((PersonaRenderRecord *)status)->values[3] = datPersonaGetStat(persona, 3);
        *(s8 *)&((PersonaRenderRecord *)status)->values[4] = datPersonaGetStat(persona, 4);
        break;
    case 1:
        *(s8 *)&((PersonaRenderRecord *)status)->values[0] = datPersonaGetBuffedStat(persona, 0);
        *(s8 *)&((PersonaRenderRecord *)status)->values[1] = datPersonaGetBuffedStat(persona, 1);
        *(s8 *)&((PersonaRenderRecord *)status)->values[2] = datPersonaGetBuffedStat(persona, 2);
        *(s8 *)&((PersonaRenderRecord *)status)->values[3] = datPersonaGetBuffedStat(persona, 3);
        *(s8 *)&((PersonaRenderRecord *)status)->values[4] = datPersonaGetBuffedStat(persona, 4);
        break;
    case 2:
        *(s8 *)&((PersonaRenderRecord *)status)->values[0] = datPersonaGetTotalStat(persona, 0);
        *(s8 *)&((PersonaRenderRecord *)status)->values[1] = datPersonaGetTotalStat(persona, 1);
        *(s8 *)&((PersonaRenderRecord *)status)->values[2] = datPersonaGetTotalStat(persona, 2);
        *(s8 *)&((PersonaRenderRecord *)status)->values[3] = datPersonaGetTotalStat(persona, 3);
        *(s8 *)&((PersonaRenderRecord *)status)->values[4] = datPersonaGetTotalStat(persona, 4);
        break;
    default:
        kAssertFail(D_005E4868, 0x96);
        break;
    }
    for (i = 0; i < 7; i++) {
        ((PersonaRenderRecord *)status)->affinities[i] = datPersonaRunSkillSlot((u8 *)persona, D_007465D0[i]);
    }
}


// Copy five stat bytes from the persona record into the status block's added stats.
// FUN_00115C00
void shdPersonaCopyStatBytes(u8 *stats, u8 *status)
{
    s32 i = 0;
    while (i < 5) {
        MEMBER(u8, status + i, PersonaRenderRecord, added[0]) = stats[i];
        i++;
    }
}


void shdPersonaDrawRowName(Vec2f, f32, u8, s16 *);

// Dispatch a persona panel draw by mode: 0 draws the row name, 1 the detail panel, 2 the row
// number.
// FUN_00115C40
void shdPersonaDrawByMode(Vec2f basePosition, u8 alpha, s16 *descriptor, f32 depth)
{
    switch (*descriptor) {
    case 0:
        shdPersonaDrawRowName(basePosition, depth, alpha, descriptor);
        break;
    case 1:
        shdPersonaDrawDetailPanel(basePosition, depth, alpha, descriptor);
        break;
    case 2:
        shdPersonaDrawRowNumber(basePosition, depth, alpha, descriptor);
        break;
    }
}


/* Draws a persona row number as formatted text; the mode selects font 6 or 7. */
// FUN_00115CB0
void shdPersonaDrawRowNumber(Vec2f basePosition, f32 depth, u8 alpha, s16 *descriptor)
{
    s8 font;
    s32 row;
    s32 color;
    u8 text[0x100];

    color = -0x100;
    color |= (u32)((alpha & 0xFF) * 0xFF) / 255U;
    row = (s32)datPersonaGetRow((u16)descriptor[5]);
    switch (descriptor[1]) {
    case 0:
        font = 6;
        sprintf(&text[0], &iGpffff9c08, row);
        break;
    case 1:
        font = 7;
        sprintf(&text[0], &iGpffff9c08, row);
        break;
    }
    frFontExDrawTextWithCharWidth((f32)(s32)basePosition.x, (f32)(s32)basePosition.y, depth, color, font, 1, (const char *)text, 0, -1);
}


u8 *datPersonaGetRow(u16 personaId);
/* The text renderer is declared with interleaved float/int parameters, and scale is set from depth
 * before the colour expression, as in retail. */


// Draw a persona row's name text, with the mode selecting font 0 or 7.
// FUN_00115DC0
void shdPersonaDrawRowName(Vec2f basePosition, f32 depth, u8 alpha, s16 *descriptor)
{
    s32 color;
    s8 font;
    s16 mode;
    s32 name;
    f32 scale;

    scale = depth;
    color = -0x100;
    color |= (u32)((alpha & 0xFF) * 0xFF) / 255U;
    mode = descriptor[1];
    switch (mode) {
    case 0:
        font = 0;
        break;
    case 1:
        font = 7;
        break;
    }
    name = (s32)datPersonaGetRow(((ShdSkillDescriptor *)descriptor)->data.fields.id);
    frFontExDrawText((f32)(s32)basePosition.x, (f32)(s32)basePosition.y, scale, color, font, 1, (void *)name, 0, 0);
}


/* measured: retail hoists the gauge coordinates out of the loops and does not reuse common
 * subexpressions in this panel draw. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// Draw the persona detail panel: name plate, Arcana badge, EXP row, affinity panel, stat gauges and
// skill slots.
// FUN_00115E90
void shdPersonaDrawDetailPanel(Vec2f basePosition, f32 depth, u8 alpha, s16 *descriptor)
{
    u32 *base;
    f32 y;
    PackedVec2f position;
    s32 resources[4];
    s32 i;
    u8 *record;

    y = basePosition.y;
    resources[0] = (s32)resourceFindByName(D_005E5810);
    resources[1] = (s32)resourceFindByName(D_005E5830);
    resources[2] = (s32)resourceFindByName(D_005E5850);
    resources[3] = (s32)resourceFindByName(D_005E57F0);
    base = (u32 *)D_00887300;
    ((s32 (**)(s32, void *))base)[0](6, (void *)0);
    ((s32 (**)(s32, void *))base)[0](7, (void *)2);
    ((s32 (**)(s32, void *))base)[0](8, (void *)0);
    ((s32 (**)(s32, void *))base)[0](9, (void *)2);
    ((s32 (**)(s32, void *))base)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))base)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))base)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))base)[0](2, (void *)4);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    position.xy.x = basePosition.x;
    position.xy.y = 43.0f + y;
    shdPersonaDrawNamePlate(position.packed, depth, alpha, (u8 *)descriptor + 8, resources);
    position.xy.x = basePosition.x - 23.0f;
    position.xy.y = 76.0f + y;
    shdPersonaDrawExpRow(position.packed, depth, alpha, (u8 *)descriptor + 8, resources);
    shdPersonaDrawFramePair(position.packed, depth, alpha, (u8 *)descriptor + 8, resources);
    shdPersonaDrawArcanaBadge(position.packed, depth, alpha, (u8 *)descriptor + 8, resources);
    position.xy.x = (f32)305 + basePosition.x;
    position.xy.y = 139.0f + y;
    shdPersonaDrawAffinityPanel(position.xy, depth, alpha, (u8 *)descriptor + 8, resources);
    i = 0;
    while (i < 5) {
        position.xy.x = 88.0f + basePosition.x;
        position.xy.y = 203.0f + y + (f32)(i * 19);
        record = (u8 *)descriptor + i;
        shdPersonaDrawGaugeBar(position.xy, 0.0f, alpha, record[0xF],
                     record[0x14], 0, resources[0]);
        i++;
    }
}
#pragma pop
u32 datPersonaNamePart1(s16 unitId);
// Draw a persona name plate: panel sprite 0x59 and the persona name text from the id lookup.
// FUN_00116190
void shdPersonaDrawNamePlate(s64 packedPosition, f32 depth, u8 opacity, u8 *status, s32 *sprites)
{
    f32 high;
    f32 x;
    f32 y;
    s32 alpha;
    s32 color;
    s32 texture;

    alpha = opacity & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    if (*(u16 *)status != 0) {
        texture = sprites[1];
        if (texture == 0) {
            kAssertFail(D_005E4868, 0x171);
        }
        high = *((f32 *)&packedPosition + 1);
        sdkSpriteDrawOnceTinted(0, texture, 0x59, 207.0f + *(f32 *)&packedPosition, high, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, depth, 0);
        x = (f32)(s32)(114.0f + *(f32 *)&packedPosition);
        y = (f32)(s32)(2.0f + high);
        frFontExDrawText(x, y, depth, color | -0x100, 8, 1, (const char *)datPersonaNamePart1(*(s16 *)status), 8, 0);
    }
}


// Draw a pair of frame sprites (0x47 and 0x41) for a persona panel.
// FUN_001162F0
void shdPersonaDrawFramePair(s64 packedPosition, f32 depth, u8 opacity, u8 *status, s32 *sprites)
{
    s32 t17;
    s32 c;
    u8 m;
    f32 hi;

    t17 = *sprites;
    if (t17 == 0) {
        kAssertFail(D_005E4868, 0x197);
    }
    m = opacity & 0xFF;
    c = 0xFF - m;
    hi = *((f32 *)&packedPosition + 1);
    sdkSpriteDrawOnceTinted(0, t17, 0x47, *(f32 *)&packedPosition, hi, c, 0x2D, 0x2D, 0x2D, depth, 0);
    sdkSpriteDrawOnceTinted(0, t17, 0x41, 126.0f + *(f32 *)&packedPosition, hi, c, 0x2D, 0x2D, 0x2D, depth, 0);
}


u8 datPersonaGetArcana(u16 personaId);
f32 sdkSpriteEntryWidth(s32, s32);
/* Draws the Arcana badge: a sprite sized by Arcana count, the persona icon sprite and the level
 * digits. The block-scope shdPersonaDrawLevelDigits prototype (s64, f32, s32, u8, s32)
 * intentionally differs from the callee's own (s64, f32, s32, u32, u32) to reproduce retail
 * argument setup. */
// FUN_001163E0
void shdPersonaDrawArcanaBadge(s64 packedPosition, f32 depth, u8 opacity, u8 *status, s32 *sprites)
{
    void shdPersonaDrawLevelDigits(s64, f32, s32, u8, s32);
    f32 high;
    f32 position[2];
    u8 color[4];
    s32 id0;
    s32 id1;
    s32 count;
    s32 width;
    high = *((f32 *)&packedPosition + 1);
    id0 = sprites[0];
    if (id0 == 0) {
        kAssertFail(D_005E4868, 0x1BF);
    }
    id1 = sprites[2];
    if (id1 == 0) {
        kAssertFail(D_005E4868, 0x1C1);
    }
    count = (s32)(datPersonaGetArcana(((PersonaRenderRecord *)status)->id) & 0xFF);
    if (count <= 0 || count >= 0x20) {
        kAssertFail(D_005E4868, 0x1E6);
    }
    position[1] = 6.0f + high;
    width = (((count & 0xFFFF) - 1) & 0xFFFF) + 0x21;
    position[0] = 80.0f + *(f32 *)&packedPosition - sdkSpriteEntryWidth(id0, width) / 2.0f;
    count = opacity & 0xFF;
    count = 0xFF - count;
    sdkSpriteDrawOnceTinted(0, id0, width, position[0], position[1], count, 0xFF, 0xFF, 0xFF, depth, 0);
    position[0] = 53.0f + *(f32 *)&packedPosition;
    position[1] = 43.0f + high;
    sdkSpriteDrawOnceTinted(0, id1, 0x2A, position[0], position[1], count, 0xFF, 0xFF, 0xFF, depth, 0);
    position[0] = 83.0f + *(f32 *)&packedPosition;
    position[1] = 36.0f + high;
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = (u8)opacity;
    shdPersonaDrawLevelDigits(*(s64 *)position, depth, *(s32 *)color, ((PersonaRenderRecord *)status)->level, id1);
}


void shdPersonaDrawDigits(Vec2f, f32, s32, u32, u32, s32);
/* Draws the EXP row: panel sprite, EXP-to-next-level digits and the persona name text. */
// FUN_00116610
void shdPersonaDrawExpRow(s64 packedPosition, f32 depth, u8 opacity, u8 *status, s32 *sprites)
{
    u8 text[0x100];
    Vec2f position;
    u8 digitColor[4];
    s32 alpha;
    s32 color;
    s32 id0;
    s32 id1;
    s32 temp;
    f32 high;

    high = *((f32 *)&packedPosition + 1);
    alpha = opacity & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    id0 = sprites[0];
    if (id0 == 0) {
        kAssertFail(D_005E4868, 0x235);
    }
    id1 = sprites[1];
    if (id1 == 0) {
        kAssertFail(D_005E4868, 0x237);
    }
    position.x = 129.0f + *(f32 *)&packedPosition;
    position.y = 39.0f + high;
    sdkSpriteDrawOnceTinted(0, id0, 0x39, position.x, position.y, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, depth, 0);
    position.x = 259.0f + *(f32 *)&packedPosition;
    position.y = 43.0f + high;
    digitColor[0] = 0x2D;
    digitColor[1] = 0x2D;
    digitColor[2] = 0x2D;
    digitColor[3] = opacity;
    shdPersonaDrawDigits(position, depth, *(s32 *)digitColor, ((PersonaRenderRecord *)status)->nextExperience, id1, 1);
    temp = (s32)datPersonaGetRow(((PersonaRenderRecord *)status)->id);
    sprintf(&text[0], (void *)&iGpffff9c0c, temp);
    frFontExDrawTextWithCharWidth((f32)((s32)*(f32 *)&packedPosition + 0x86), (f32)((s32)high + 3), depth, color | -0x100, 7, 1, (const char *)text, 0, -1);
}


/* Draw the affinity icons and five status values with their shared sprite sets. */
// FUN_00116820
void shdPersonaDrawAffinityPanel(Vec2f position, f32 depth, u8 alpha, u8 *persona, s32 *sprites)
{
    f32 baseY;
    Vec2f point;
    PackedColor4 color;
    u32 affinityIndex;
    s32 value;
    s32 panelSprites;
    s32 digitSprites;
    s32 affinitySprites;
    s32 icon;
    s32 entry;
    f32 rowY;
    f32 numberX;

    baseY = position.y;
    panelSprites = sprites[0];
    if (panelSprites == 0) {
        kAssertFail(D_005E4868, 0x298);
    }
    digitSprites = sprites[1];
    if (digitSprites == 0) {
        kAssertFail(D_005E4868, 0x29A);
    }
    affinitySprites = sprites[2];
    if (affinitySprites == 0) {
        kAssertFail(D_005E4868, 0x29C);
    }
    point.x = position.x;
    point.y = baseY;
    value = alpha & 0xFF;
    value = 0xFF - value;
    sdkSpriteDrawOnceTinted(0, panelSprites, 0x42, point.x, point.y, value, 0xFF, 0xA0, 0x0B, depth, 0);
    point.x = position.x - 273.0f;
    point.y = 3.0f + baseY;
    affinityIndex = 0;
    while (affinityIndex < 7U) {
        rowY = point.y;
        sdkSpriteDrawOnceTinted(0, affinitySprites, affinityIndex + 0x2E, point.x, rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
        sdkSpriteDrawOnceTinted(0, panelSprites, 0x43, point.x - 2.0f, 22.0f + rowY, value, 0xFF, 0xE9, 0x2C, depth, 0);
        entry = ((PersonaRenderRecord *)persona)->affinities[affinityIndex];
        if ((entry & 0x02000000) != 0) {
            icon = 0x35;
        } else if ((entry & 0x08000000) != 0) {
            icon = 0x36;
        } else if ((entry & 0x10000000) != 0) {
            icon = 0x37;
        } else if ((entry & 0x01000000) != 0) {
            icon = 0x38;
        } else if ((entry & 0x04000000) != 0) {
            icon = 0x39;
        } else {
            icon = 0x3A;
        }
        sdkSpriteDrawOnceTinted(0, affinitySprites, icon, point.x, 24.0f + rowY, value, 0xDE, 0x75, 0, depth, 0);
        if (affinityIndex == 0) {
            point.x += 51.0f;
        } else {
            point.x += 37.0f;
        }
        affinityIndex++;
    }
    color.rgba[0] = 0x2D;
    color.rgba[1] = 0x2D;
    color.rgba[2] = 0x2D;
    ((s8 *)color.rgba)[3] = (s8)alpha;
    point.x = position.x - 315.0f;
    point.y = 152.0f + baseY;
    value = (u32)alpha & 0xFFU;
    value = 0xFFU - value;
    sdkSpriteDrawOnceTinted(0, panelSprites, 0x44, point.x, point.y, value, 0xFF, 0xA0, 0x0B, depth, 0);
    point.x = position.x + 31.0f - 315.0f;
    rowY = 152.0f + (baseY - 93.0f);
    point.y = rowY;
    sdkSpriteDrawOnceTinted(0, affinitySprites, 0x2C, point.x, rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
    sdkSpriteDrawOnceTinted(0, affinitySprites, 0x2D, point.x, 57.0f + rowY, value, 0xFF, 0xFF, 0x81, depth, 0);
    value = 0;
    numberX = position.x + 65.0f - 315.0f;
    baseY = 152.0f + (baseY - 88.0f);
    while (value < 5U) {
        entry = ((u8 *)((u32)persona + value))[7];
        point.x = numberX;
        rowY = (f32)(u32)(value * 0x13);
        point.y = baseY + rowY;
        shdPersonaDrawDigits(point, depth, color.packed, entry & 0xFF, digitSprites, 0);
        value++;
    }
}


extern f32 iGpffff82fc;
/* Draw one stat gauge: meter background, remaining span and optional bonus span. The rectangle
 * provider copies four raw words before reading integer coordinates; the union describes its
 * floating-point view. */
// FUN_00116D40
/* measured: retail keeps the full color and rectangle buffers in memory instead of splitting them
 * into scalars. */
#pragma push
#pragma opt_scalarize off
void shdPersonaDrawGaugeBar(Vec2f position, f32 depth, u8 alpha, u8 filled, u8 added,
                   s16 phase, s32 resource)
{
    PackedColor4 colors[2];
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    s32 bonus;
    u8 shade;
    u8 blue;
    s32 shadeAlpha;
    f32 y;
    f32 rectangleY;
    f32 width;
    f32 rate;
    s32 left;
    u32 *stateWords;

    bonus = added & 0xFF;
    if (bonus > 0) {
        filled -= added;
        colors[1].rgba[0] = 0x2D;
        colors[1].rgba[1] = 0x2D;
        colors[1].rgba[2] = 0x2D;
        ((s8 *)colors[1].rgba)[3] = (s8)alpha;
        shade = 140;
        blue = shade;
        shadeAlpha = alpha & 0xFF;
        colors[0].rgba[0] = 0xFF;
        colors[0].rgba[1] = 0xFF;
        colors[0].rgba[2] = 0xFF;
        rate = (3.0f + cosf((iGpffff82fc * (f32)phase) / 30.0f)) / 4.0f;
        colors[0].rgba[3] = (u8)((f32)alpha * rate);
    } else {
        colors[1].rgba[0] = 0xFF;
        colors[1].rgba[1] = 0xA0;
        colors[1].rgba[2] = 0x0B;
        ((s8 *)colors[1].rgba)[3] = (s8)alpha;
        shade = 255;
        blue = 129;
        shadeAlpha = alpha & 0xFF;
        colors[0].rgba[0] = 0xFF;
        colors[0].rgba[1] = 0xFF;
        colors[0].rgba[2] = 0x81;
        ((s8 *)colors[0].rgba)[3] = (s8)alpha;
    }
    y = position.y;
    sdkSpriteDrawOnceTinted(0, resource, 0x3D, position.x, y,
                  (0xFF - colors[1].rgba[3]) & 0xFF, colors[1].rgba[0], colors[1].rgba[1], colors[1].rgba[2], depth, 0);
    sdkSpriteDrawOnceTinted(0, resource, 0x3E, 214.0f + position.x, y,
                  (0xFF - colors[1].rgba[3]) & 0xFF, colors[1].rgba[0], colors[1].rgba[1], colors[1].rgba[2], depth, 0);
    sdkSpriteDrawOnceTinted(0, resource, 0x3F, position.x, y,
                  (0xFF - (shadeAlpha & 0xFF)) & 0xFF, shade, shade, blue, depth, 0);
    width = (f32)(((filled & 0xFF) * 204) / 99 + 10);
    position.x += width;
    left = (s32)position.x;
    rectangle.integer[0] = left;
    rectangleY = position.y;
    rectangle.integer[1] = (s32)(4.0f + rectangleY);
    rectangle.integer[2] = (s32)(214.0f - width);
    rectangle.integer[3] = 9;
    stateWords = (u32 *)D_00887300;
    ((s32 (**)(s32, void *))stateWords)[0](1, 0);
    PrimDrawFlatRectangle(colors[1].rgba, rectangle.transport, depth, 0);
    if (bonus > 0) {
        f32 bonusWidth = (f32)((bonus * 204) / 99);
        rectangle.integer[0] = left;
        rectangle.integer[1] = (s32)(5.0f + rectangleY);
        rectangle.integer[2] = (s32)bonusWidth;
        rectangle.integer[3] = 7;
        ((s32 (**)(s32, void *))stateWords)[0](1, 0);
        PrimDrawFlatRectangle(colors[0].rgba, rectangle.transport, depth, 0);
        position.x += bonusWidth;
    }
    sdkSpriteDrawOnceTinted(0, resource, 0x40, position.x, position.y,
                  (0xFF - colors[0].rgba[3]) & 0xFF, colors[0].rgba[0], colors[0].rgba[1], colors[0].rgba[2], depth, 0);
}
#pragma pop


void shdPersonaDrawLevelDigits(s64, f32, s32, u32, u32);
// Draw a persona level as one or two right-aligned digits, using the sprite set given by texture.
// FUN_001171C0
void shdPersonaDrawLevelDigits(s64 packedPosition, f32 depth, s32 color, u32 level, u32 texture)
{
    s64 position;
    s32 packed;
    f32 farg;
    f32 f;
    s32 n;
    s32 id;
    u8 b2;
    u8 b1;
    s32 inv;
    s32 rem;
    f32 y;

    position = packedPosition;
    farg = depth;
    packed = color;
    n = level;
    id = texture;
    y = *((f32 *)&position + 1);
    if (id == 0) {
        kAssertFail(D_005E4868, 0x400);
    }
    rem = n & 0xFF;
    if (rem < 10) {
        f = 11.0f + *((f32 *)&position + 0);
    } else {
        f = 22.0f + *((f32 *)&position + 0);
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    inv = 0xFF;
    inv -= *((u8 *)&packed + 3);
    do {
        sdkSpriteDrawOnceTinted(0, id, (rem % 10) + 0x1D, f, y, inv,
                      (*((u8 *)&packed)), b1, b2, farg, 0);
        n = ((u32)(n & 0xFF) / 10U) & 0xFF;
        f -= 22.0f;
        rem = n;
    } while (n > 0);
}
/* measured: Vec2f coordinates, direct packed-color parameter access and unsigned locals reproduce
 * retail's prologue; scoped loop invariants keep the digit-loop setup. Draws an unsigned number as
 * right-aligned digit sprites, stepping left per digit, with optional wide spacing. */
/* Draw an unsigned number as digit sprites from the given texture, starting at the rightmost digit
 * and stepping left 16 units per digit. The start position depends on rightAligned and on the
 * number of digits. */
// FUN_00117310
/* measured: retail hoists the digit-loop setup constants out of the loop. */
#pragma push
#pragma opt_loop_invariants on
void shdPersonaDrawDigits(Vec2f basePosition, f32 depth, s32 color, u32 number, u32 texture, s32 rightAligned)
{
    f32 f;
    u32 n = number;
    u32 id = texture;
    u8 b2;
    u8 b1;
    u32 rem;
    f32 y;
    y = basePosition.y;
    if (id == 0) {
        kAssertFail(D_005E4868, 0x424);
    }
    if (rightAligned != 0) {
        f = basePosition.x;
        rem = n;
        while (rem >= 10U) {
            f += 16.0f;
            rem /= 10U;
        }
    } else if (n < 10U) {
        f = 8.0f + basePosition.x;
    } else {
        f = 16.0f + basePosition.x;
    }
    b2 = *((u8 *)&color + 2);
    b1 = *((u8 *)&color + 1);
    rightAligned = 0xFF;
    rightAligned -= *((u8 *)&color + 3);
    do {
        sdkSpriteDrawOnceTinted(0, id, (n % 10U) + 9,
                      f, y, (u8)rightAligned, *((u8 *)&color), b1, b2,
                      depth, 0);
        n /= 10U;
        f -= 16.0f;
    } while (n != 0);
}
#pragma pop
// Return eased progress in [0,1] for frame over [startFrame, endFrame), with linear, sine or cosine
// easing chosen by mode.
// FUN_001174A0
f32 shdPersonaEaseProgress(s32 frame, s32 startFrame, s32 endFrame, s32 mode)
{
    if (frame < startFrame) {
        return 0.0f;
    }
    if (frame < endFrame) {
        f32 f = (f32)(frame - startFrame) / (f32)(endFrame - startFrame);
        switch (mode) {
        case 0:
            break;
        case 1:
            f = sinf(D_00761184 * f);
            break;
        case 2:
            f = 1.0f - cosf(D_00761184 * f);
            break;
        }
        return f;
    }
    return 1.0f;
}


// Store a persona-list index in the task work block after checking it is below 216.
// FUN_00117580
void shdPersonaSetPersonaId(u8 *task, s32 personaId)
{
    u8 *b = ((SdkTask *)task)->work;
    if (!((personaId & 0xFFFF) < 0xD8)) {
        kAssertFail(D_005E4868, 0x595);
    }
    ((PersonaRenderWork *)b)->queueIndex = personaId;
}


void datRecordResetAll(u8 *record);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];
// Initialises a persona panel task: counters, child-task callbacks, texture ids and the ten channel
// rectangles.
// FUN_001175E0
void shdPersonaTaskInit(u8 *task, s32 inputState, s32 inputOpenDuration, s32 inputCloseDuration)
{
    u8 *b;
    s32 i;
    u8 *src;
    u8 *dst;
    u8 *presets;

    b = ((SdkTask *)task)->work;
    ((PersonaRenderWork *)b)->state = inputState;
    ((PersonaRenderWork *)b)->openDuration = inputOpenDuration;
    ((PersonaRenderWork *)b)->closeDuration = inputCloseDuration;
    ((PersonaRenderWork *)b)->openingFrame = 0;
    ((PersonaRenderWork *)b)->state = -1;
    ((PersonaRenderWork *)b)->phase = 0;
    ((PersonaRenderWork *)b)->flags = 0;
    memset(b + 0x540, 0, 0x30);
    ((PersonaRenderWork *)b)->drawCommand.callback = shdPersonaDrawPanels;
    ((PersonaRenderWork *)b)->drawCommand.argument = b;
    *(s16 *)&((PersonaRenderWork *)MEMBER(u8 *, task, SdkTask, work))->queueIndex = 0xB1;
    ((PersonaRenderWork *)b)->model = shdPersonaModelCreate((s32)task, 0xF, 0, 0, -0x100);
    shdPersonaSetState(task, inputState);
    ((PersonaRenderWork *)b)->sprites[0] = (s32)resourceFindByName(D_005E5810);
    ((PersonaRenderWork *)b)->sprites[1] = (s32)resourceFindByName(D_005E5830);
    ((PersonaRenderWork *)b)->sprites[2] = (s32)resourceFindByName(D_005E5850);
    ((PersonaRenderWork *)b)->sprites[3] = (s32)resourceFindByName(D_005E57F0);
    i = 0;
    presets = D_005E4880;
    for (; i < 0xA; i++) {
        src = presets + i * sizeof(ShdPersonaChannelPreset);
        dst = b + i * 0x24;
        ((PersonaRenderWork *)dst)->channels[0].current.x = ((ShdPersonaChannelPreset *)src)->position.x;
        ((PersonaRenderWork *)dst)->channels[0].current.y = ((ShdPersonaChannelPreset *)src)->position.y;
        ((PersonaRenderWork *)dst)->channels[0].alpha = ((ShdPersonaChannelPreset *)src)->alpha;
    }
    datRecordResetAll(b + 0x84);
    *(s32 *)&((PersonaRenderWork *)b)->selectionPosition.x = 0xC3E10000;
    *(s32 *)&((PersonaRenderWork *)b)->selectionPosition.y = 0x80000000;
    ((PersonaRenderWork *)b)->selectionAlpha = 0xFF;
    *(s32 *)&((PersonaRenderWork *)b)->selectionStartFrame = 0;
    *(s32 *)&((PersonaRenderWork *)b)->selectionEndFrame = 0x40A00000;
}


// Create a persona panel child task with update and destroy callbacks, then initialise it from the
// given state and durations.
// FUN_00117780
u8 *shdPersonaTaskCreate(s32 parentTask, s32 priority, s32 state, s32 openDuration, s32 closeDuration)
{
    u8 *w;
    u8 *r;

    chkmemAllocSiteTag(D_005E4868, 0x5ED);
    w = D_008873F4[0](1, 0x574, 0x40000);
    if (w == NULL) {
        kAssertFail(D_005E4868, 0x5EE);
    }
    r = (u8 *)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005E4810), priority, 0, 0, shdPersonaTaskUpdate, shdPersonaDestroy, (u8 *)(w));
    if (r == NULL) {
        kAssertFail(D_005E4868, 0x5F8);
    }
    shdPersonaTaskInit(r, state, openDuration, closeDuration);
    return r;
}


// Per-frame update of a persona panel task: copies its resource block and advances its state
// machine.
// FUN_001178A0
s32 shdPersonaTaskUpdate(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    s32 off;
    ((PersonaRenderWork *)b)->drawCommand.next = 0;
    ((PersonaRenderWork *)b)->drawCommand.previous = 0;
    off = 0x30 * ((PersonaRenderWork *)b)->queueIndex;
    PrimAppendNode(D_00793E80 + off, b + 0x540);
    switch (((PersonaRenderWork *)b)->phase) {
    case 0:
        MEMBER(s32, b, PersonaRenderWork, phase) = 1;
        /* fallthrough */
    case 1:
        if (((PersonaRenderWork *)b)->controllerAddress != 0) {
            MEMBER(s32, b, PersonaRenderWork, phase) = 2;
            ((PersonaRenderWork *)b)->flags |= 8;
        }
        break;
    case 2:
        break;
    case 3:
        if (!(((PersonaRenderWork *)b)->flags & 1)) {
            return -1;
        }
        break;
    }
    return 0;
}


extern u8 iGpffff9c10;
extern u8 iGpffff9c11;
extern u8 iGpffff9c12;
extern u8 iGpffff9c13;
extern f32 iGpffff81e0;
extern f32 iGpffff8094;
extern f32 iGpffff82fc;
extern f32 D_005E4D70;
extern f32 D_005E4D74;
extern f32 D_005E4D78;
extern f32 D_005E4D7C;
extern f32 D_005E4D80;
extern f32 D_005E4D84;
extern f32 D_005E4D88;
extern u8 D_005E4D90[];
extern s16 D_005E4D58[];
u32 RpRandom(void);
void PrimDrawPoints(u8 *, u8 *, f32, s32, s32, s32);
void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha,
                   u16 scaleX, u16 scaleY, f32 angle, s16 pivotX, s16 pivotY);
/* measured: retail keeps the draw-loop constants hoisted and rotation declared before panel scale.
 * Eases a bounded frame interval through its configured sine phase. */
static inline f32 shdPersonaSinePhase(s32 frame, s32 first, s32 last)
{
    if (frame < first) {
        return 0.0f;
    }
    if (frame < last) {
        return sinf(iGpffff8094 * ((f32)(frame - first) / (f32)(last - first)));
    }
    return 1.0f;
}

/* Return linear interval progress clamped before its start and after its end. */
static inline f32 shdPersonaLinearPhase(s32 frame, s32 first, s32 last)
{
    if (frame < first) {
        return 0.0f;
    }
    if (frame < last) {
        return (f32)(frame - first) / (f32)(last - first);
    }
    return 1.0f;
}

/* Apply five-frame sine dips following the five configured pulse keyframes. */
static inline f32 shdPersonaPulseEnvelope(u16 frame)
{
    u16 keyframes[5] = {10, 30, 35, 90, 95};
    u32 index;

    for (index = 0; index < 5; index++) {
        if (keyframes[index] < frame && frame <= keyframes[index] + 5) {
            return 1.0f - sinf(D_007613EC * (f32)(frame - keyframes[index]) / 5.0f);
        }
    }
    return 1.0f;
}

/* measured: combines normalized opacity and the effect factor before byte conversion; retail loads
 * opacity and normalizes in this order only via the wrapper. */
static inline u8 shdPersonaModulatedOpacity(u8 opacity, f32 factor)
{
    return (u8)((255.0f * factor) * ((f32)opacity / 255.0f));
}

/* Return the complement of clamped linear progress through the frame interval. */
static inline f32 shdPersonaFallingPhase(s32 frame, s32 first, s32 last)
{
    f32 progress;
    if (frame < first) {
        progress = 0.0f;
    } else if (frame < last) {
        progress = (f32)(frame - first) / (f32)(last - first);
    } else {
        progress = 1.0f;
    }
    return 1.0f - progress;
}

// Updates and draws the card-open effect: growing panel scale, 24 radial particles, four corner
// marks and a pulse ring.
// FUN_00117980
/* measured: retail hoists the draw-loop constants out of the loops. */
#pragma push
#pragma opt_loop_invariants on
void shdPersonaDrawEffect(u8 *panel)
{
    extern f32 D_007611AC;
    extern f32 D_00761288;
    u8 *b = panel;
    u8 *effect = b + 0x458;
    s8 cornerDirections[4] = {-1, 0, 1, 0};
    Vec2f drawPosition;
    u8 triangleColors[12];
    f32 trianglePoints[6];
    f32 quadrantDirections[4] = {-0.7071f, 0.7071f, 0.7071f, -0.7071f};
    f32 particleAngles[3] = {0.0f, 0.2617994f, -0.2617994f};
    Vec2f radialExtent[3] = {{42.0f, 42.0f}, {43.0f, 71.0f}, {72.0f, 41.0f}};
    u32 tblbase;

    u16 frameCount;
    u16 durationCount;
    s32 particle;
    s32 radialSlot;
    s32 quadrant;
    s32 particleColor;
    u8 baseOpacity;
    u8 alpha;
    u8 col;
    s32 opacity;
    f32 rotation;
    f32 panelScale;
    f32 fade;
    f32 particlePhase;
    f32 opacityValue;
    f32 particleRadius;
    f32 particleScale;
    f32 particleOpacity;
    f32 pulseScale;

    if ((((ShdPersonaEffect *)effect)->flags & 1) == 0) {
        baseOpacity = *(b + 0x505);
        {
            f32 fb = (f32)baseOpacity;
            opacityValue = 255.0f * (fb / 255.0f);
            opacity = (u8)opacityValue;
            col = opacity & 0xFF;
        }
        frameCount = ((ShdPersonaEffect *)effect)->frame;
        if ((s32)frameCount < 5) {
            f32 t0;
            f32 t1;
            f32 growth;
            if ((s32)frameCount < 0) {
                growth = 0.0f;
            } else if ((s32)frameCount < 4) {
                t0 = cosf(iGpffff8094 * ((f32)(s32)frameCount / 4.0f));
                growth = 1.0f - t0;
            } else {
                growth = 1.0f;
            }
            frameCount = MEMBER(u16, effect, ShdPersonaEffect, frame);
            t1 = shdPersonaSinePhase(frameCount, 4, 5);
            panelScale = D_007611AC * growth - D_00761288 * t1;
        } else {
            panelScale = 1.0f;
        }
        frameCount = MEMBER(u16, effect, ShdPersonaEffect, frame);
        fade = shdPersonaLinearPhase(frameCount, 0, 15);
        {
            f32 fc = (f32)col;
            opacityValue = fc * fade;
            opacity = (u8)opacityValue;
            alpha = opacity & 0xFF;
        }
        if (++MEMBER(u16, effect, ShdPersonaEffect, frame) >= 15) {
            ((ShdPersonaEffect *)effect)->flags = ((ShdPersonaEffect *)effect)->flags | 1;
        }
    } else if ((((ShdPersonaEffect *)effect)->flags & 2) != 0) {
        col = shdPersonaModulatedOpacity(b[0x505], shdPersonaFallingPhase(((ShdPersonaEffect *)effect)->frame, 0, 3));
        alpha = col;
        panelScale = 1.0f;
        if (++MEMBER(u16, effect, ShdPersonaEffect, frame) >= 3) {
            ((PersonaRenderWork *)b)->flags = ((PersonaRenderWork *)b)->flags & 0xFFF7FFFF;
        }
    } else {
        baseOpacity = *(b + 0x505);
        {
            f32 fb = (f32)baseOpacity;
            opacityValue = 255.0f * (fb / 255.0f);
            opacity = (u8)opacityValue;
            col = opacity & 0xFF;
            alpha = col;
        }
        panelScale = 1.0f;
    }
    *(s16 *)&((ShdPersonaEffect *)effect)->rotationFrame = (s16)(((s32)(((ShdPersonaEffect *)effect)->rotationFrame + 1)) % 400);
    frameCount = ((ShdPersonaEffect *)effect)->rotationFrame;
    rotation = (iGpffff81e0 * (f32)frameCount) / 400.0f;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    tblbase = (u32)D_00887300;
    ((s32 (**)(s32, void *))tblbase)[0](1, (void *)0);
    trianglePoints[0] = 340.0f;
    trianglePoints[1] = 0.0f;
    triangleColors[0] = 0x1D;
    triangleColors[1] = 0x1D;
    triangleColors[2] = 0xFF;
    triangleColors[3] = 0;
    trianglePoints[2] = 640.0f;
    trianglePoints[3] = 0.0f;
    triangleColors[4] = 0x1D;
    triangleColors[5] = 0x1D;
    triangleColors[6] = 0xFF;
    triangleColors[7] = alpha;
    trianglePoints[4] = 640.0f;
    trianglePoints[5] = (f32)(s32)0x125;
    triangleColors[8] = 0x1D;
    triangleColors[9] = 0x1D;
    triangleColors[10] = 0xFF;
    triangleColors[11] = 0;
    PrimDrawPoints((u8 *)triangleColors, (u8 *)trianglePoints, 0.0f, 3, 5, 0);
    particle = 0;
    while (particle < 0x18) {
        Vec2f *extent;
        const s32 styleCount = sizeof(radialExtent) / sizeof(radialExtent[0]);
        u8 *elem = effect + particle * 2;
        u16 *particleDuration = &((ShdPersonaEffect *)elem)->particleDurations[0];
        s32 duration = *particleDuration;
        u16 *particleFrame = &((ShdPersonaEffect *)elem)->particleFrames[0];
        s32 frame = ++*particleFrame;
        if (frame < 0) {
            particlePhase = 0.0f;
        } else if (frame < duration) {
            particlePhase = (f32)frame / (f32)duration;
        } else {
            particlePhase = 1.0f;
        }
        durationCount = *particleDuration;
        {
            f32 fv = (f32)durationCount;
            particleScale = fv / 30.0f;
        }
        particleColor = (particle % 3 == 0) ? (s32)0xB34DFF00 : (s32)0x1353FF00;
        quadrant = particle / 3;
        radialSlot = particle % styleCount;
        extent = &radialExtent[radialSlot];
        particleRadius = 0.5f + particleScale;
        {
            s32 qq = quadrant % 4;
            drawPosition.x = 557.0f + particleRadius * (particlePhase * (extent->x * quadrantDirections[qq]));
        }
        quadrant++;
        {
            s32 qq = quadrant % 4;
            drawPosition.y = 91.0f + particleRadius * (particlePhase * (extent->y * quadrantDirections[qq]));
        }
        particleOpacity = 255.0f * sinf(D_007613EC * particlePhase);
        {
            f32 fc = (f32)col;
            opacityValue = particleScale * ((fc * particleOpacity) / 255.0f);
            opacity = (u8)opacityValue;
        }
        {
            shdDrawRotatingQuad(drawPosition, 0.0f, particleColor | (opacity & 0xFF), 15.0f, particleAngles[radialSlot], 0);
        }
        if ((s32)(*particleFrame & 0xFFFF) >= (s32)(*particleDuration & 0xFFFF)) {
            *particleFrame = 0;
            *particleDuration = (u16)(((u32)RpRandom() % 0x14) + 0xF);
        }
        particle += 1;
    }
    particle = 0;
    while (particle < 4) {
        s32 qq = particle % 4;
        drawPosition.x = (f32)(s32)cornerDirections[qq] * 54.0f + 557.0f;
        {
            s32 next = particle + 1;
            s32 qq2 = next % 4;
            drawPosition.y = (f32)(s32)cornerDirections[qq2] * 54.0f + 91.0f;
        }
        {
            shdDrawRotatingQuad(drawPosition, 0.0f, (col & 0xFF) | 0x1353FF00, 24.0f, rotation * 4.0f, 0);
        }
        particle += 1;
    }
    {
        drawPosition.x = 557.0f;
        drawPosition.y = 91.0f;
        shdDrawRotatingQuad(drawPosition, 0.0f, (col & 0xFF) | 0xB34DFF00, 41.0f, rotation, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    *(s16 *)&((ShdPersonaEffect *)effect)->pulseFrame = (s16)(((s32)(((ShdPersonaEffect *)effect)->pulseFrame + 1)) % 100);
    drawPosition.x = 523.0f;
    drawPosition.y = 91.0f - panelScale * 30.0f;
    sdkSpriteDrawOnceScaled(((PersonaRenderWork *)b)->sprites[2], 0xB4, drawPosition.x, drawPosition.y, 0.0f, 0x2D, 0x2D, 0x2D, col, 0x1000, (u16)(panelScale * 4096.0f), 0.0f, 0, 0);
    pulseScale = panelScale * shdPersonaPulseEnvelope(MEMBER(u16, effect, ShdPersonaEffect, pulseFrame));
    drawPosition.x = 542.0f;
    drawPosition.y = (1.0f - pulseScale) * 20.0f + 76.0f;
    sdkSpriteDrawOnceScaled(MEMBER(s32, b, PersonaRenderWork, sprites[2]), 0xB5, drawPosition.x, drawPosition.y, 0.0f, 0x2D, 0x2D, 0x2D, col, 0x1000, (u16)(pulseScale * 4096.0f), 0.0f, 0, 0);
}
#pragma pop


void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha,
                   u16 scaleX, u16 scaleY, f32 angle, s16 pivotX, s16 pivotY);
/* Complete views of one eight-byte incoming panel coordinate value. */
typedef union PersonaPanelPosition {
    f32 coordinates[2];
    s64 packed;
} PersonaPanelPosition;
/* measured: propagation must stay off so the incoming coordinate object and per-call Y-offset
 * conversion are kept rather than split into scalars, as retail does. */
#pragma push
#pragma opt_propagation off
// Draw one persona panel's four sprites at a position offset from the base coordinates.
// FUN_001187B0
void shdPersonaDrawPanelSprites(u8 *work, PersonaPanelPosition position, u8 opacity,
                   s64 baseCoordinates, f32 rotation)
{
    PackedVec2f basePosition;
    f32 angle;
    f32 baseY;
    f32 originX;
    f32 originY;
    f32 offsetY;
    f32 offsetX;
    f32 baseX;
    f32 x;
    s32 resource;

    basePosition.packed = baseCoordinates;
    angle = rotation;
    offsetY = ((PersonaPanelPosition *)&position)->coordinates[1];
    baseY = basePosition.xy.y;
    resource = ((PersonaRenderWork *)work)->sprites[2];
    offsetX = ((PersonaPanelPosition *)&position)->coordinates[0];
    baseX = basePosition.xy.x;
    originX = offsetX + baseX;
    originY = offsetY + baseY;
    {
        f32 y = baseY;
        sdkSpriteDrawOnceScaled(((PersonaRenderWork *)work)->sprites[3], 0x1D, originX, originY, 0.0f,
                      0xBD, 0x29, 0, opacity, 0x1000, 0x1000, angle,
                      (s16)(baseX - originX), (s16)(y - originY));
    }
    x = 207.0f + originX;
    {
        f32 y = baseY;
        sdkSpriteDrawOnceScaled(resource, 0xB2, x, originY, 0.0f,
                      0xBD, 0x29, 0, opacity, 0x1000, 0x1000, angle,
                      (s16)(basePosition.xy.x - x), (s16)(y - originY));
    }
    x = 300.0f + originX;
    {
        f32 y = baseY;
        sdkSpriteDrawOnceScaled(resource, 0xB3, x, originY, 0.0f,
                      0xBD, 0x29, 0, opacity, 0x1000, 0x1000, angle,
                      (s16)(basePosition.xy.x - x), (s16)(y - originY));
    }
    x = 314.0f + originX;
    {
        f32 y = baseY;
        sdkSpriteDrawOnceScaled(resource, 0xB3, x, originY, 0.0f,
                      0xBD, 0x29, 0, opacity, 0x1000, 0x1000, angle,
                      (s16)(basePosition.xy.x - x), (s16)(y - originY));
    }
}
#pragma pop


void shdPersonaDrawPanelSprites(u8 *, PersonaPanelPosition, u8, s64, f32);
void PrimDrawPoints(u8 *, u8 *, f32, s32, s32, s32);
extern f32 iGpffff8364;
extern f32 iGpffff8094;
/* Draws the sliding background panels for the persona screen; their phases follow the frame
 * counter. A packed-coordinate union and three aligned color objects hold the buffers, and each
 * particle loop has its own counter. */
// FUN_00118A20
/* measured: retail hoists the loop constants out of the color loops, which needs
 * opt_loop_invariants on. */
#pragma push
#pragma opt_loop_invariants on
void shdPersonaDrawSlidingPanels(u8 *panel)
{
    void shdEnableBlendFlag(void);
    void shdDisableBlendFlag(void);
    f32 f25;
    f32 f24;
    f32 f23;
    f32 f22;
    /* Retail leaves f21 unwritten when frame < 7 and f20 unwritten when frame < 9. */
    f32 f21;
    f32 f20;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 t90;
    f32 t94;
    f32 t98;
    f32 u90;
    f32 u94;
    f32 u98;
    union {
        f32 values[4];
        PersonaPanelPosition pairs[2];
    } panelCoordinates;
    PackedColor4 colors[3] __attribute__((aligned(16)));
    f32 points[6];
    u8 b505;
    s16 v;
    f32 x;
    /* Retail initializes the four phase values only in this flag arm.
     * The two scroll values also require the frame thresholds below;
     * no default is supplied for paths that skip those assignments. */
    if ((((PersonaRenderWork *)panel)->flags & 0x10000) != 0) {
        v = ((PersonaRenderWork *)panel)->revealFrame;
        if (v < 0) {
            x = 0.0f;
        } else if (v < 6) {
            x = sinf(iGpffff8094 * ((f32)v / 6.0f));
        } else {
            x = 1.0f;
        }
        f25 = 1.0f - x;
        v = MEMBER(s16, panel, PersonaRenderWork, revealFrame);
        if (v < 3) {
            x = 0.0f;
        } else if (v < 9) {
            x = sinf(iGpffff8094 * ((f32)(v - 3) / 6.0f));
        } else {
            x = 1.0f;
        }
        f24 = 1.0f - x;
        v = MEMBER(s16, panel, PersonaRenderWork, revealFrame);
        if (v < 7) {
            x = 0.0f;
        } else if (v < 0x11) {
            x = sinf(iGpffff8094 * ((f32)(v - 7) / 10.0f));
        } else {
            x = 1.0f;
        }
        f23 = 1.0f - x;
        v = MEMBER(s16, panel, PersonaRenderWork, revealFrame);
        if (v < 9) {
            x = 0.0f;
        } else if (v < 0x13) {
            x = sinf(iGpffff8094 * ((f32)(v - 9) / 10.0f));
        } else {
            x = 1.0f;
        }
        f22 = 1.0f - x;
        if (MEMBER(s16, panel, PersonaRenderWork, revealFrame) >= 7) {
            ((PersonaRenderWork *)panel)->revealPulseFrame = ((PersonaRenderWork *)panel)->revealPulseFrame + 1;
            if (((PersonaRenderWork *)panel)->revealPulseFrame >= 0x46) {
                MEMBER(s16, panel, PersonaRenderWork, revealPulseFrame) = 0;
            }
            v = MEMBER(s16, panel, PersonaRenderWork, revealPulseFrame);
            if (v < 0) {
                f21 = 0.0f;
            } else if (v < 0x46) {
                f21 = (f32)v / 70.0f;
            } else {
                f21 = 1.0f;
            }
        }
        if (MEMBER(s16, panel, PersonaRenderWork, revealFrame) >= 9) {
            ((PersonaRenderWork *)panel)->revealLabelFrame = ((PersonaRenderWork *)panel)->revealLabelFrame + 1;
            if (((PersonaRenderWork *)panel)->revealLabelFrame >= 0x28) {
                MEMBER(s16, panel, PersonaRenderWork, revealLabelFrame) = 0;
            }
            v = MEMBER(s16, panel, PersonaRenderWork, revealLabelFrame);
            if (v < 0) {
                f20 = 0.0f;
            } else if (v < 0x28) {
                f20 = (f32)v / 40.0f;
            } else {
                f20 = 1.0f;
            }
        }
    }
    b505 = *(panel + 0x505);
    x1 = 135.0f + 516.0f * f25;
    panelCoordinates.values[2] = x1;
    panelCoordinates.values[3] = -11.0f;
    points[0] = x1;
    points[1] = panelCoordinates.values[3];
    y1 = 516.0f + x1;
    points[2] = y1;
    points[3] = panelCoordinates.values[3];
    points[4] = y1;
    points[5] = 484.0f + panelCoordinates.values[3];
    {
        s32 i;
        for (i = 0; i < 3; i++) {
            PackedColor4 *color = &colors[i];
            color->rgba[0] = 0xED;
            color->rgba[1] = 0x36;
            color->rgba[2] = 0x11;
            color->rgba[3] = b505;
        }
    }
    shdEnableBlendFlag();
    PrimDrawPoints((u8 *)colors, (u8 *)points, 0.0f, 3, 5, 0);
    shdDisableBlendFlag();
    x2 = -21.0f - 131.0f * f24;
    panelCoordinates.values[2] = x2;
    panelCoordinates.values[3] = (f32)0x151;
    points[0] = x2;
    points[1] = panelCoordinates.values[3];
    points[2] = x2;
    points[3] = 123.0f + panelCoordinates.values[3];
    points[4] = 131.0f + x2;
    points[5] = points[3];
    {
        s32 i;
        for (i = 0; i < 3; i++) {
            PackedColor4 *color = &colors[i];
            color->rgba[0] = 0xFF;
            color->rgba[1] = 0x36;
            color->rgba[2] = 0x11;
            color->rgba[3] = b505;
        }
    }
    shdEnableBlendFlag();
    PrimDrawPoints((u8 *)colors, (u8 *)points, 0.0f, 3, 5, 0);
    shdDisableBlendFlag();
    t90 = 552.0f + 461.0f * f23 - 15.0f;
    t94 = 10.0f + 413.0f * f23;
    t98 = -(400.0f * f21);
    panelCoordinates.values[0] = t90;
    panelCoordinates.values[1] = t94;
    panelCoordinates.values[2] = t98;
    panelCoordinates.values[3] = 0.0f;
    {
        s32 k;
        for (k = 0; k < 2; k++) {
            shdPersonaDrawPanelSprites(panel, panelCoordinates.pairs[1], b505, panelCoordinates.pairs[0].packed, iGpffff8364);
            panelCoordinates.values[2] = panelCoordinates.values[2] + 400.0f;
        }
    }
    u90 = 219.0f + 461.0f * f22 + 90.0f - 30.0f;
    u94 = 10.0f + 413.0f * f22;
    u98 = -(400.0f * f20);
    panelCoordinates.values[0] = u90;
    panelCoordinates.values[1] = u94;
    panelCoordinates.values[2] = u98;
    panelCoordinates.values[3] = 0.0f;
    {
        s32 k;
        for (k = 0; k < 3; k++) {
            shdPersonaDrawPanelSprites(panel, panelCoordinates.pairs[1], b505, panelCoordinates.pairs[0].packed, iGpffff8364);
            panelCoordinates.values[2] = panelCoordinates.values[2] + 400.0f;
        }
    }
}
#pragma pop


void PrimDrawPoints(u8 *, u8 *, f32, s32, s32, s32);
/* measured: retail sets up the accumulator and scale values before the quad loop starts, which
 * needs loop-invariant hoisting on. */
#pragma opt_loop_invariants on
// Draw the six-quad particle strip for a persona panel, with per-quad positions and blend alpha
// from the alpha argument.
// FUN_001190F0
void shdPersonaDrawParticleQuads(f32 *origin, u8 alpha)
{
    f32 points[12];
    u8 colors[24];
    f32 *dstf;
    u8 *dstb;
    s32 i;
    s32 x;
    s32 n2;
    s32 n;

    for (i = 0; i < 6; i++) {
        dstf = &points[2 * i];
        x = i & 1;
        if (i < 0 && (i & 1)) {
            x -= 2;
        }
        *dstf = origin[0] + 2.0f * (f32)x;
        n2 = i / 3;
        *(dstf + 1) = origin[1] + 450.0f * (f32)n2;
        dstb = &colors[4 * i];
        dstb[0] = 0x5A;
        dstb[1] = 0x5A;
        dstb[2] = 0xFF;
        n = i / 2;
        if (n == 1) {
            dstb[3] = alpha;
        } else {
            dstb[3] = 0;
        }
    }
    PrimDrawPoints((u8 *)colors, (u8 *)points, 0.0f, 6, 4, 0);
}
/* measured: restores the unit setting after shdPersonaDrawParticleQuads. */
#pragma opt_loop_invariants off


s32 cmmCommunityValueForArcana(s32);
void sdkSpriteDrawOnce(s32, s32, s32, f32, f32, u8, f32, s32);
void shdPersonaDrawParticleQuads(f32 *, u8);
extern u8 D_005E4DB0[];
extern f32 iGpffff8368;
/* Draw the blue backdrop, ten rising particles, community rank and bonus digits. Each particle's
 * table snapshot and randomized duration stay in one expression to keep retail's multiplication
 * order. */
// FUN_00119210
void shdPersonaDrawBackdrop(u8 *work)
{
    Vec2f point;
    Vec2f positions[4];
    PackedColor4 colors[4];
    union {
        struct { f32 x; u16 period; u16 reserved; } row[10];
        s32 words[20];
    } definitions;
    u8 *animation;
    u8 alpha;
    u32 alphaWord;
    s32 communityRank;
    s32 inverseAlpha;
    u32 digits;
    f32 digitX;
    f32 digitY;

    animation = work + 0x4C0;
    if (*(s32 *)&((PersonaRenderWork *)work)->backdrop.bonus == 0) {
        return;
    }
    communityRank = cmmCommunityValueForArcana(datPersonaGetArcana(((DatPersonaRecord *)*(u8 **)work)->id) & 0xFF) & 0xFF;
    alpha = *(work + 0x505);
    {
        if (++*(u16 *)animation >= 0x14) {
            *(u16 *)animation = 0;
        }
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    D_00887300[0](1, 0);
    alphaWord = (u32)alpha & 0xFFU;
    positions[0].x = -200.0f;
    positions[0].y = 0.0f;
    colors[0].rgba[0] = 0;
    colors[0].rgba[1] = 0;
    colors[0].rgba[2] = 0x96;
    colors[0].rgba[3] = 0;
    positions[1].x = 640.0f;
    positions[1].y = 0.0f;
    colors[1].rgba[0] = 0;
    colors[1].rgba[1] = 0;
    colors[1].rgba[2] = 0x96;
    colors[1].rgba[3] = (u8)(f32)(u32)alphaWord;
    positions[2].x = -200.0f;
    positions[2].y = 448.0f;
    colors[2].rgba[0] = 0;
    colors[2].rgba[1] = 0;
    colors[2].rgba[2] = 0x96;
    colors[2].rgba[3] = 0;
    positions[3].x = 640.0f;
    positions[3].y = 448.0f;
    colors[3].rgba[0] = 0;
    colors[3].rgba[1] = 0;
    colors[3].rgba[2] = 0x96;
    colors[3].rgba[3] = (u8)(f32)(u32)alphaWord;
    PrimDrawPoints((u8 *)colors, (u8 *)positions, 0.0f, 4, 4, 0);
    {
        s32 index;
        index = 0;
        while (index < 10) {
            u8 *entry = animation + index * 4;
            u8 *particle = entry + 8;
            {
                s32 *src = (s32 *)D_005E4DB0;
                s32 *dst = definitions.words;
                s32 n = 10;
                do {
                    s32 a = src[0];
                    s32 b = src[1];
                    src += 2;
                    n--;
                    dst[0] = a;
                    dst[1] = b;
                    dst += 2;
                } while (n > 0);
            }
            if (index >= 10) {
                kAssertFail(D_005E4868, 0x7FB);
            }
            {
                if (++*(u16 *)particle < ((ShdPersonaParticle *)particle)->duration) {
                    goto skip_reset;
                }
            }
            *(u16 *)particle = 0;
            MEMBER(u16, particle, ShdPersonaParticle, duration) = (u16)((f32)(u32)definitions.row[index].period *
                (1.0f + 0.5f * ((f32)(RpRandom() & 0xFFFU) / 4096.0f)));
    skip_reset:
            point.x = definitions.row[index].x;
            point.y = 448.0f - (f32)0x382 * shdPersonaEaseProgress(*(u16 *)particle, 0, MEMBER(u16, particle, ShdPersonaParticle, duration), 0);
            shdPersonaDrawParticleQuads((f32 *)&point, alpha);
            index++;
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    inverseAlpha = 0xFF - (alpha & 0xFF);
    {
        sdkSpriteDrawOnce(0, ((PersonaRenderWork *)work)->backdropTexture, 0, 322.0f, 176.0f, inverseAlpha, 0.0f, 0);
        if ((communityRank & 0xFF) == 0xA) {
            sdkSpriteDrawOnce(0, MEMBER(s32, work, PersonaRenderWork, backdropTexture), 0xC, 520.0f, 170.0f, inverseAlpha, 0.0f, 0);
        } else {
            s32 rank = communityRank & 0xFF;
            sdkSpriteDrawOnce(0, MEMBER(s32, work, PersonaRenderWork, backdropTexture), rank + 1, (f32)0x209, 173.0f, inverseAlpha, 0.0f, 0);
        }
    }
    digitX = (f32)0x232;
    digitY = 220.0f;
    digits = ((ShdPersonaBackdrop *)animation)->bonus;
    do {
        sdkSpriteDrawOnce(0, MEMBER(s32, work, PersonaRenderWork, backdropTexture), (digits % 10) + 1, digitX, digitY, inverseAlpha, 0.0f, 0);
        digitX -= 28.0f;
        digitY += 5.0f;
        digits /= 10;
    } while (digits != 0);
}


/* Draws the persona acquisition animation: rotating panel, glow phase and label. The easing maximum
 * is shared across all three phases and also supplies the completed-phase endpoints and glow
 * complement. */
// FUN_00119810
void shdPersonaDrawAcquisition(u8 *work)
{
    u8 *animation;
    f32 labelProgress;
    f32 glowProgress;
    f32 rotationProgress;
    s32 color;
    s8 mode;
    u16 flags;
    s32 frame;
    f32 progress;
    f32 maximum;
    f32 angle;

    animation = work + 0x4F0;
    if (((PersonaRenderWork *)work)->acquisition.skill == 0) {
        return;
    }
    flags = *(u16 *)animation;
    if (!(flags & 1)) {
        if (++((ShdPersonaAcquisition *)animation)->frame >= 0x28) {
            *(u16 *)animation = *(u16 *)animation | 1;
        }
        if (MEMBER(u16, animation, ShdPersonaAcquisition, frame) == 8) {
            sdkSndStartStream(1, 3, 3, 2);
        }
        frame = MEMBER(u16, animation, ShdPersonaAcquisition, frame);
        if ((s32)frame < 0) {
            progress = 0.0f;
        } else if ((s32)frame < 8) {
            progress = 1.0f - cosf(iGpffff8094 * ((f32)frame / 8.0f));
        } else {
            progress = 1.0f;
        }
        maximum = 1.0f;
        rotationProgress = maximum - progress;
        frame = MEMBER(u16, animation, ShdPersonaAcquisition, frame);
        if ((s32)frame < 8) {
            progress = 0.0f;
        } else if ((s32)frame < 0xF) {
            progress = sinf(iGpffff8094 * ((f32)(frame - 8) / 7.0f));
        } else {
            progress = maximum;
        }
        labelProgress = progress;
        frame = MEMBER(u16, animation, ShdPersonaAcquisition, frame);
        if ((s32)frame < 8) {
            progress = 0.0f;
        } else if ((s32)frame < 0x28) {
            progress = sinf(iGpffff8094 * ((f32)(frame - 8) / 32.0f));
        } else {
            progress = maximum;
        }
        glowProgress = progress;
    } else if (flags & 2) {
        rotationProgress = 0.0f;
        maximum = 1.0f;
        labelProgress = maximum;
        glowProgress = 0.0f;
        ((PersonaRenderWork *)work)->flags = ((PersonaRenderWork *)work)->flags & ~0x100000;
    } else {
        rotationProgress = 0.0f;
        maximum = 1.0f;
        labelProgress = maximum;
        glowProgress = 0.0f;
    }
    color = ((PersonaRenderWork *)work)->alpha;
    angle = 90.0f * rotationProgress;
    sdkSpriteDrawOnceScaled(((PersonaRenderWork *)work)->backdropTexture, 0xB, (f32)0x19B, 296.0f, 0.0f,
                   0xFF, 0xFF, 0xFF, color, 0x1000, 0x1000, angle, (s16)0x12E, (s16)0x21);
    if (glowProgress > 0.0f && glowProgress < maximum) {
        s32 alpha;
        f32 floatAlpha;
        f32 glowOpacity;
        u8 glowAlpha;
        alpha = MEMBER(u8, work, PersonaRenderWork, alpha);
        floatAlpha = (f32)(u32)alpha;
        glowOpacity = 0.5f * floatAlpha * (maximum - glowProgress);
        glowAlpha = (u8)glowOpacity;
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        sdkSpriteDrawOnceScaled(MEMBER(s32, work, PersonaRenderWork, backdropTexture), 0xB, (f32)0x19B, 296.0f, 0.0f,
                   0xFF, 0xFF, 0xFF, glowAlpha, 0x1000, 0x1000, angle, (s16)0x12E, (s16)0x21);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    if (((ShdSkillState *)((PersonaRenderWork *)work)->skills)->cursor == 8) {
        s32 inverseAlpha;
        mode = 8;
        inverseAlpha = 255 - MEMBER(u8, work, PersonaRenderWork, alpha);
        sdkSpriteDrawOnceTinted(0, ((PersonaRenderWork *)work)->sprites[1], 0x5C, (f32)0x1A5, (f32)0x147,
                      inverseAlpha, 0x2D, 0x2D, 0x2D, 0.0f, 0);
        sdkSpriteDrawOnceTinted(0, MEMBER(s32, work, PersonaRenderWork, sprites[1]), 0x5D, (f32)0x25B, (f32)0x147,
                      inverseAlpha, 0x2D, 0x2D, 0x2D, 0.0f, 0);
    } else {
        mode = 7;
    }
    {
        s32 alpha;
        f32 floatAlpha;
        f32 labelOpacity;
        alpha = MEMBER(u8, work, PersonaRenderWork, alpha);
        floatAlpha = (f32)(u32)alpha;
        labelOpacity = floatAlpha * labelProgress;
        color = (u8)labelOpacity;
        color = (color & 0xFF) | -0x100;
    }
    frFontExDrawText(iGpffff8368, (f32)0x145, 0.0f, color, (s8)mode, 1,
                  (const char *)func_00243840(((ShdPersonaAcquisition *)animation)->skill), 8, 0);
}
void shdPersonaTweenChannelsOpen(u8 *);
void shdPersonaTweenChannelsClose(u8 *);
void shdPersonaTweenSelectionOpen(u8 *);
void shdPersonaTweenSelectionClose(u8 *);
void shdPersonaTweenComparison(u8 *);
void shdPersonaUpdateSkillPulse(u8 *);
void shdPersonaUpdateReveal(u8 *);
void shdPersonaDrawByState(u8 *);
void shdPersonaDispCtlSetMode(u8 *, u8);
void shdPersonaDrawSmoothBar(u8 *);
void shdPersonaDrawSlidingPanels(u8 *);
void shdPersonaDrawSineQuad(u8 *);
void shdPersonaDispCtlGetPosition(u8 *, u8 *);
s32 shdPersonaDispCtlGetLoadedValue(u8 *);
u16 shdPersonaGetSelectedSkillId(u8 *);
void ShdSkill_DrawSelectionFrame(Vec2f, f32, u8, u16);
void shdPersonaDrawBackdrop(u8 *);
void shdPersonaDrawAcquisition(u8 *);
void shdPersonaDrawEffect(u8 *);
void sdkSpriteDrawFooter(Vec2f unusedPosition, f32 depth, u8 alpha, s32 style, s32 packAddress);

/* Update task counters, callbacks and independently animated Persona panels. Flags are read again
 * after callbacks because they can change draw visibility. The selection counter is intentionally
 * advanced in both update and draw. Packed coordinate snapshots keep complete two-float objects
 * across calls. */
// FUN_00119E10
void shdPersonaDrawPanels(u8 *task, u8 *argument)
{
    void ShdSkill_DrawListSlot(Vec2f, f32, u8, u8 *, u8, f32);
    void ShdSkill_DrawDetailFrame(Vec2f, f32, u8, u8 *, f32);
    void frFontExDrawText(f32, f32, f32, s32, s8, s32, const char *, s32, s32);
    PackedVec2f position;
    Vec2f modelPosition;
    PackedVec2f headerPosition;
    PackedVec2f labelPosition;
    PackedVec2f comparisonLabelPosition;
    PersonaRenderWork *work;
    u32 renderStateAddress;
    s32 flags;
    s16 counter;

    work = (PersonaRenderWork *)argument;
    flags = work->flags;
    if (((flags & 1) == 0) || ((flags & 8) == 0)) {
        return;
    }
    counter = work->meterPhase;
    work->meterPhase = counter + 1;
    if (work->controllerAddress == 0) {
        kAssertFail(D_005E4868, 0x933);
    }
    counter = work->openingFrame;
    if (counter < 0x64) {
        work->openingFrame = counter + 1;
    }
    flags = work->flags;
    if ((flags & 2) != 0) {
        shdPersonaTweenChannelsOpen((u8 *)work);
    } else if ((flags & 4) != 0) {
        shdPersonaTweenChannelsClose((u8 *)work);
    }
    if ((work->flags & 0x800) != 0) {
        counter = work->selectionFrame;
        if (counter < 0x64) {
            work->selectionFrame = counter + 1;
        }
        flags = work->flags;
        if ((flags & 0x1000) != 0) {
            shdPersonaTweenSelectionOpen((u8 *)work);
        } else if ((flags & 0x2000) != 0) {
            shdPersonaTweenSelectionClose((u8 *)work);
        }
    }
    if ((work->flags & 0x4000) != 0) {
        counter = work->comparisonFrame;
        if (counter < 0x64) {
            work->comparisonFrame = counter + 1;
        }
        shdPersonaTweenComparison((u8 *)work);
    }
    if ((work->flags & 0x8000) != 0) {
        counter = work->skillFrame;
        if (counter < 0x64) {
            work->skillFrame = counter + 1;
        }
        shdPersonaUpdateSkillPulse((u8 *)work);
    }
    if ((work->flags & 0x200) != 0) {
        counter = work->revealFrame;
        if (counter < 0x64) {
            work->revealFrame = counter + 1;
        }
        shdPersonaUpdateReveal((u8 *)work);
    }
    renderStateAddress = (u32)D_00887300;
    ((s32 (**)(s32, void *))renderStateAddress)[0](6, (void *)0);
    ((s32 (**)(s32, void *))renderStateAddress)[0](7, (void *)2);
    ((s32 (**)(s32, void *))renderStateAddress)[0](8, (void *)0);
    ((s32 (**)(s32, void *))renderStateAddress)[0](9, (void *)2);
    ((s32 (**)(s32, void *))renderStateAddress)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))renderStateAddress)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))renderStateAddress)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))renderStateAddress)[0](2, (void *)4);
    ((s32 (**)(s32, void *))renderStateAddress)[0](0xE, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    if ((work->flags & 0x10) != 0) {
        shdPersonaDrawByState((u8 *)work);
    }
    if ((work->flags & 0x400000) == 0) {
        shdPersonaDispCtlSetMode(work->model, work->alpha);
        if ((work->flags & 0x800000) != 0) {
            shdPersonaDrawSmoothBar(work->model);
        }
        if ((work->flags & 0x200) != 0) {
            shdPersonaDrawSlidingPanels((u8 *)work);
        }
        if ((work->flags & 0x200000) != 0) {
            shdPersonaDrawSineQuad(work->model);
        }
        if ((work->flags & 0x200) != 0) {
            u8 *model;
            f32 phase;
            f32 sy;
            f32 sx;
            s32 packed;
            model = work->model;
            if (((work->flags & 0x10000) != 0) && (work->revealFrame >= 0x14) && (shdPersonaDispCtlIsLoaded(model) != 0)) {
                f32 t;
                phase = shdPersonaEaseProgress(work->revealFrame, 0x17, 0x32, 2);
                shdPersonaDispCtlGetPosition(model, (u8 *)&modelPosition);
                sy = modelPosition.y;
                sx = modelPosition.x;
                t = 204.0f * (1.0f - phase);
                packed = ((u8)t & 0xFF) | 0xFF8C3200;
                shdDrawColourQuad(0.0f, packed, sx, sy, sx, sy, 512.0f, 512.0f, shdPersonaDispCtlGetLoadedValue(model), 0, 1);
                RpSkyRenderStateSet(3, (void *)0x717FB);
                RpSkyRenderStateSet(2, (void *)0x44);
            }
        }
        if ((work->flags & 0x100) != 0) {
            shdPersonaDrawBackdrop((u8 *)work);
        }
        flags = work->flags;
        if ((flags & 0x200000) != 0) {
            if ((flags & 0x80000) != 0) {
                shdPersonaDrawEffect((u8 *)work);
            } else if ((*(u16 *)work->controllerAddress & 4) != 0) {
                work->flags = flags | 0x80000;
                memset(work->effect, 0, 0x68);
            }
        }
        if ((work->flags & 0x400) != 0) {
            f32 px;
            f32 py;
            px = 16.0f + work->channels[4].current.x;
            position.xy.x = px;
            py = 17.0f + work->channels[4].current.y;
            position.xy.y = py;
            sdkSpriteDrawOnce(0, work->sprites[3], 3, px, py, (0xFF - work->channels[4].alpha) & 0xFF, 0.0f, 0);
        }
        if ((work->flags & 0x80) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            u32 color;
            s32 id;
            f32 x;
            f32 y;
            f32 headerY;
            px = work->channels[0].current.x;
            position.xy.x = px;
            py = 43.0f + work->channels[0].current.y;
            position.xy.y = py;
            alpha = work->channels[0].alpha;
            headerPosition.packed = position.packed;
            color = (u32)((alpha * 0xFF) / 255U);
            if (work->persona[0].category != 0) {
                id = work->sprites[1];
                if (id == 0) {
                    kAssertFail(D_005E4868, 0x171);
                }
                headerY = headerPosition.xy.y;
                sdkSpriteDrawOnceTinted(0, id, 0x59, 207.0f + headerPosition.xy.x, headerY, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                x = (f32)(s32)(114.0f + headerPosition.xy.x);
                y = (f32)(s32)(2.0f + headerY);
                frFontExDrawText(x, y, 0.0f, color | ~0xFF, 8, 1, (const char *)datPersonaNamePart1((s16)work->persona[0].category), 8, 0);
            }
        }
        if ((work->flags & 0x40) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            s32 id;
            s32 inv;
            f32 sy;
            px = -23.0f + work->channels[1].current.x;
            position.xy.x = px;
            py = 76.0f + work->channels[1].current.y;
            position.xy.y = py;
            shdPersonaDrawExpRow(position.packed, 0.0f, work->channels[1].alpha, (u8 *)&work->persona[0], work->sprites);
            px = -23.0f + work->channels[3].current.x;
            position.xy.x = px;
            py = 76.0f + work->channels[3].current.y;
            position.xy.y = py;
            alpha = work->channels[3].alpha;
            labelPosition.packed = position.packed;
            id = work->sprites[0];
            if (id == 0) {
                kAssertFail(D_005E4868, 0x197);
            }
            inv = 0xFF - (alpha & 0xFF);
            sy = labelPosition.xy.y;
            sdkSpriteDrawOnceTinted(0, id, 0x47, labelPosition.xy.x, sy, inv, 0x2D, 0x2D, 0x2D, 0.0f, 0);
            sdkSpriteDrawOnceTinted(0, id, 0x41, 126.0f + labelPosition.xy.x, sy, inv, 0x2D, 0x2D, 0x2D, 0.0f, 0);
            px = -23.0f + work->channels[2].current.x;
            position.xy.x = px;
            py = 76.0f + work->channels[2].current.y;
            position.xy.y = py;
            shdPersonaDrawArcanaBadge(position.packed, 0.0f, work->channels[2].alpha, (u8 *)&work->persona[0], work->sprites);
            if ((work->flags & 0x4000) != 0) {
                px = -23.0f + work->channels[7].current.x;
                position.xy.x = px;
                py = 76.0f + work->channels[7].current.y;
                position.xy.y = py;
                shdPersonaDrawExpRow(position.packed, 0.0f, work->channels[7].alpha, (u8 *)&work->persona[1], work->sprites);
                px = -23.0f + work->channels[9].current.x;
                position.xy.x = px;
                py = 76.0f + work->channels[9].current.y;
                position.xy.y = py;
                alpha = work->channels[9].alpha;
                comparisonLabelPosition.packed = position.packed;
                id = work->sprites[0];
                if (id == 0) {
                    kAssertFail(D_005E4868, 0x197);
                }
                inv = 0xFF - (alpha & 0xFF);
                sy = comparisonLabelPosition.xy.y;
                sdkSpriteDrawOnceTinted(0, id, 0x47, comparisonLabelPosition.xy.x, sy, inv, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                sdkSpriteDrawOnceTinted(0, id, 0x41, 126.0f + comparisonLabelPosition.xy.x, sy, inv, 0x2D, 0x2D, 0x2D, 0.0f, 0);
                px = -23.0f + work->channels[8].current.x;
                position.xy.x = px;
                py = 76.0f + work->channels[8].current.y;
                position.xy.y = py;
                shdPersonaDrawArcanaBadge(position.packed, 0.0f, work->channels[8].alpha, (u8 *)&work->persona[1], work->sprites);
            }
            {
                f32 qx;
                f32 qy;
                qx = (f32)0x131;
                qx = qx + work->channels[5].current.x;
                qy = 139.0f + work->channels[5].current.y;
                position.xy.x = qx;
                position.xy.y = qy;
                shdPersonaDrawAffinityPanel(position.xy, 0.0f, work->channels[5].alpha, (u8 *)&work->persona[0], work->sprites);
                {
                    s32 i;
                    for (i = 0; i < 5; i++) {
                        f32 rx;
                        f32 ry;
                        u8 *record;
                        rx = 88.0f + work->channels[5].current.x;
                        ry = 203.0f + work->channels[5].current.y + (f32)(i * 19);
                        position.xy.x = rx;
                        position.xy.y = ry;
                        record = (u8 *)work + i;
                        shdPersonaDrawGaugeBar(position.xy, 0.0f, work->channels[5].alpha, record[0x13], record[0x18], work->meterPhase, work->sprites[0]);
                    }
                }
            }
        }
        if ((work->flags & 0x800) != 0) {
            f32 px;
            f32 py;
            counter = work->selectionFrame;
            if (counter < 0x64) {
                work->selectionFrame = counter + 1;
            }
            px = 18.0f + work->selectionPosition.x;
            position.xy.x = px;
            py = 194.0f + work->selectionPosition.y;
            position.xy.y = py;
            ShdSkill_DrawSelectionFrame(position.xy, 0.0f, work->alpha, shdPersonaGetSelectedSkillId((u8 *)work));
        }
        if ((work->flags & 0x20) != 0) {
            f32 px;
            f32 py;
            u8 alpha;
            f32 fade;
            px = work->channels[6].current.x;
            position.xy.x = px;
            py = work->channels[6].current.y;
            position.xy.y = py;
            alpha = work->channels[6].alpha;
            {
                s32 j;
                for (j = 0; j < 8; j++) {
                    if (((work->flags & 0x8000) != 0) && (work->selectedSkill == j)) {
                        fade = work->selectedSkillFade;
                    } else {
                        fade = 0.0f;
                    }
                    ShdSkill_DrawListSlot(position.xy, 0.0f, alpha, work->skills, j & 0xFF, fade);
                }
                if (((work->flags & 0x8000) != 0) && (work->selectedSkill == 8)) {
                    fade = work->selectedSkillFade;
                } else {
                    fade = 0.0f;
                }
                ShdSkill_DrawDetailFrame(position.xy, 0.0f, alpha, work->skills, fade);
            }
            if ((work->flags & 0x100000) != 0) {
                shdPersonaDrawAcquisition((u8 *)work);
            }
        }
        if ((work->flags & 0x40000) != 0) {
            position.xy.x = 0.0f;
            position.xy.y = 0.0f;
            sdkSpriteDrawFooter(position.xy, 0.0f, work->alpha, work->overlayId, work->sprites[3]);
        }
    }
}


// Load the ten animated channel targets and durations from one of six preset tables (preset 0 to
// 5).
// FUN_0011AAA0
void shdPersonaSetupChannels(u8 *panel, u32 preset)
{
    u8 *p;
    f32 vf20;
    s32 i;
    u8 *t;
    u8 *d;

    p = NULL;
    for (i = 0; i < 0xA; i++) {
        t = panel + i * 0x24;
        ((PersonaRenderWork *)t)->channels[0].start.x = ((PersonaRenderWork *)t)->channels[0].current.x;
        ((PersonaRenderWork *)t)->channels[0].start.y = ((PersonaRenderWork *)t)->channels[0].current.y;
        ((PersonaRenderWork *)t)->channels[0].startAlpha = ((PersonaRenderWork *)t)->channels[0].alpha;
    }
    switch (preset) {
    case 0:
        p = D_005E4950;
        vf20 = (f32)((PersonaRenderWork *)panel)->openDuration;
        break;
    case 1:
        p = D_005E4880;
        vf20 = (f32)((PersonaRenderWork *)panel)->closeDuration;
        break;
    case 2:
        p = D_005E4A20;
        vf20 = 4.0f;
        break;
    case 3:
        p = D_005E4AF0;
        vf20 = 4.0f;
        break;
    case 4:
        p = D_005E4BC0;
        vf20 = (f32)((PersonaRenderWork *)panel)->openDuration;
        break;
    case 5:
        p = D_005E4C90;
        vf20 = (f32)((PersonaRenderWork *)panel)->closeDuration;
        break;
    default:
        kAssertFail(D_005E4868, 0xAA6);
        break;
    }
    if (p == NULL) {
        kAssertFail(D_005E4868, 0xAA9);
    }
    for (i = 0; i < 0xA; i++) {
        t = p + i * 0x14;
        d = panel + i * 0x24;
        ((PersonaRenderWork *)d)->channels[0].target.x = ((ShdPersonaChannelPreset *)t)->position.x;
        ((PersonaRenderWork *)d)->channels[0].target.y = ((ShdPersonaChannelPreset *)t)->position.y;
        ((PersonaRenderWork *)d)->channels[0].targetAlpha = ((ShdPersonaChannelPreset *)t)->alpha;
        ((PersonaRenderWork *)d)->channels[0].duration = vf20 * ((ShdPersonaChannelPreset *)t)->startFrame;
        ((PersonaRenderWork *)d)->channels[0].delay = vf20 * ((ShdPersonaChannelPreset *)t)->endFrame;
    }
}


/* Tweens the ten channels toward their targets over the opening window, then clears opening flag
 * 0x2. The real func_0044b7b0 call takes one argument. */
// FUN_0011AC70
void shdPersonaTweenChannelsOpen(u8 *panel)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 base;
    f32 delta;
    s32 i;
    s32 a;
    s32 b;
    s32 total;
    s16 raw2;

    for (i = 0; i < 0xA; i++) {
        {
            s16 raw;
            raw = ((PersonaRenderWork *)panel)->openingFrame;
            if ((f32)raw < ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration) {
                ratio = 0.0f;
            } else {
                if ((f32)raw > ((PersonaRenderWork *)(panel + i * 36))->channels[0].delay) {
                    ratio = 1.0f;
                } else {
                    ratio = sinf(iGpffff8094 * (((f32)raw - ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration) / (((PersonaRenderWork *)(panel + i * 36))->channels[0].delay - ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration)));
                }
            }
        }
        base = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].start.x;
        delta = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].target.x - base;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].current.x = base + ratio * delta;
        base = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].start.y;
        delta = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].target.y - base;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].current.y = base + ratio * delta;
        a = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].startAlpha;
        b = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].targetAlpha;
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].alpha = (u8)acc;
    }
    total = ((PersonaRenderWork *)panel)->openDuration;
    raw2 = ((PersonaRenderWork *)panel)->openingFrame;
    if (raw2 < total) {
        ((PersonaRenderWork *)panel)->alpha = ((PersonaRenderWork *)panel)->startAlpha +
            (raw2 * (((PersonaRenderWork *)panel)->targetAlpha - ((PersonaRenderWork *)panel)->startAlpha)) / total;
    } else {
        ((PersonaRenderWork *)panel)->alpha = ((PersonaRenderWork *)panel)->targetAlpha;
        ((PersonaRenderWork *)panel)->flags &= ~2;
    }
}


extern f32 iGpffff8094;
/* Tweens the ten channels toward their targets over the closing window, then clears the closing
 * flag 0x4 when done. */
// FUN_0011AE90
void shdPersonaTweenChannelsClose(u8 *panel)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 base;
    f32 delta;
    s32 i;
    s32 a;
    s32 b;
    s32 total;
    s16 raw2;

    for (i = 0; i < 0xA; i++) {
        {
            s16 raw;
            raw = ((PersonaRenderWork *)panel)->openingFrame;
            if ((f32)raw < ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration) {
                ratio = 0.0f;
            } else {
                if ((f32)raw > ((PersonaRenderWork *)(panel + i * 36))->channels[0].delay) {
                    ratio = 1.0f;
                } else {
                    ratio = sinf(iGpffff8094 * (((f32)raw - ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration) / (((PersonaRenderWork *)(panel + i * 36))->channels[0].delay - ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration)));
                }
            }
        }
        base = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].start.x;
        delta = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].target.x - base;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].current.x = base + ratio * delta;
        base = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].start.y;
        delta = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].target.y - base;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].current.y = base + ratio * delta;
        a = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].startAlpha;
        b = ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].targetAlpha;
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        ((PersonaRenderWork *)((s32)panel + i * 36))->channels[0].alpha = (u8)acc;
    }
    total = ((PersonaRenderWork *)panel)->closeDuration;
    raw2 = ((PersonaRenderWork *)panel)->openingFrame;
    if (raw2 < total) {
        ((PersonaRenderWork *)panel)->alpha = ((PersonaRenderWork *)panel)->startAlpha +
            (raw2 * (((PersonaRenderWork *)panel)->targetAlpha - ((PersonaRenderWork *)panel)->startAlpha)) / total;
    } else {
        ((PersonaRenderWork *)panel)->alpha = ((PersonaRenderWork *)panel)->targetAlpha;
        ((PersonaRenderWork *)panel)->flags &= ~4;
        ((PersonaRenderWork *)panel)->flags &= ~0x80000;
        ((PersonaRenderWork *)panel)->flags &= ~0x200000;
        ((PersonaRenderWork *)panel)->flags &= ~0x800000;
        if (((PersonaRenderWork *)panel)->alpha == 0) {
            MEMBER(s32, panel, PersonaRenderWork, flags) &= ~1;
        } else {
            MEMBER(s32, panel, PersonaRenderWork, flags) |= 0x400000;
        }
    }
}


/* Draws the panel for its current state: states 0, 2 and 4 use draw mode 0x10, state 3 uses 0x23,
 * and state 1 draws a gauge bar scaled by the panel alpha. */
// FUN_0011B110
void shdPersonaDrawByState(u8 *panel)
{
    Vec2f z;
    s32 state;
    f32 value;
    f32 norm;
    s32 work[4];
    u8 color[4];
    z.x = 0.0f;
    z.y = 0.0f;
    state = ((PersonaRenderWork *)panel)->state;
    switch (state) {
    case 0:
    case 2:
    case 4:
        /* Retail: alpha/setIndex in GP arguments, opacity in f12. */
        nLineDrawSet(z, ((PersonaRenderWork *)panel)->opacity, ((PersonaRenderWork *)panel)->alpha, 0x10);
        return;
    case 3:
        /* Retail: alpha/setIndex in GP arguments, opacity in f12. */
        nLineDrawSet(z, ((PersonaRenderWork *)panel)->opacity, ((PersonaRenderWork *)panel)->alpha, 0x23);
        return;
    case 1:
        value = (f32)(u32)((PersonaRenderWork *)panel)->alpha;
        norm = value / 255.0f;
        work[0] = 0;
        work[1] = (s32)(231.0f - 166.0f * norm);
        work[2] = 0x280;
        work[3] = (s32)(332.0f * norm);
        color[0] = 0xFF;
        color[1] = 0xE9;
        color[2] = 0x2C;
        color[3] = MEMBER(u8, panel, PersonaRenderWork, alpha);
        D_00887300[0](1, 0);
        PrimDrawFlatRectangle(color, (f32 *)work, 0.0f, 0);
        return;
    default:
        kAssertFail(D_005E4868, 0xB3D);
        return;
    }
}


// Asserts the panel state is 0 to 4, then destroys the task.
// FUN_0011B2D0
void shdPersonaDestroy(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    s32 v = ((PersonaRenderWork *)b)->state;
    if (!(v == 1 || v == 4 || v == 3 || v == 2 || v == 0)) {
        kAssertFail(D_005E4868, 0xB59);
    }
    jtbl_008873EC[0](b);
}


// Finish the panel phase: begin the close if flag 0x1 is set and the phase is 2, otherwise clear
// flag 0x1; then set the phase to 3.
// FUN_0011B360
void shdPersonaFinishPhase(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    if ((((PersonaRenderWork *)b)->flags & 1) != 0 && ((PersonaRenderWork *)b)->phase == 2) {
        shdPersonaBeginClose(task);
    } else {
        MEMBER(s32, b, PersonaRenderWork, flags) &= ~1;
    }
    ((PersonaRenderWork *)b)->phase = 3;
}


// Fills a status block from the persona record, using mode 2 for states 0 to 2 and mode 1 for
// states 3 and 4.
// FUN_0011B3D0
void shdPersonaFillStatusForState(u8 *panel, u8 *persona)
{
    s32 v = ((PersonaRenderWork *)panel)->state;
    switch (v) {
    case 0:
    case 1:
    case 2:
        shdPersonaFillStatusBlock((DatPersonaRecord *)persona, panel + 0xC, 2);
        break;
    case 3:
    case 4:
        shdPersonaFillStatusBlock((DatPersonaRecord *)persona, panel + 0xC, 1);
        break;
    default:
        kAssertFail(D_005E4868, 0xB91);
        break;
    }
}


void datPersonaFillSkillRows(s32, u8 *);
void shdPersonaDispCtlReconfigure(u8 *, s32, s32);
s32 shdPersonaDispCtlGetHandle(u8 *);
void shdPersonaLevelUpRoute(u8 *);
// Sets the display state for a target and index: reconfigures the display control, or starts the
// display transition when the target is nonzero.
// FUN_0011B480
void shdPersonaSetDisplayState(u8 *task, s32 inputCategory, u32 personaAddress, s8 cursor)
{
    u8 *work;
    s32 t17;
    s32 t4;
    s32 state;
    u16 t3_2;

    work = ((SdkTask *)task)->work;
    t17 = shdPersonaDispCtlGetHandle(((PersonaRenderWork *)work)->model);
    if (personaAddress == 0) {
        shdPersonaDispCtlReconfigure(MEMBER(u8 *, work, PersonaRenderWork, model), 0, t17);
        ((PersonaRenderWork *)work)->phase = 1;
        ((PersonaRenderWork *)work)->flags &= ~8;
        return;
    }
    *(u16 **)&((PersonaRenderWork *)work)->controllerAddress = (u16 *)personaAddress;
    state = ((PersonaRenderWork *)work)->state;
    switch (state) {
    case 0:
    case 1:
    case 2:
        shdPersonaFillStatusBlock((DatPersonaRecord *)personaAddress, work + 0xC, 2);
        break;
    case 3:
    case 4:
        shdPersonaFillStatusBlock((DatPersonaRecord *)personaAddress, work + 0xC, 1);
        break;
    default:
        kAssertFail(D_005E4868, 0xB91);
        break;
    }
    *(s16 *)&((PersonaRenderWork *)work)->persona[0].category = (s16)inputCategory;
    datPersonaFillSkillRows((s32)personaAddress, work + 0x8C);
    ((ShdSkillState *)((PersonaRenderWork *)work)->skills)->pool.markedSlots = (s8)cursor;
    memset(work + 0x4C0, 0, 0x30);
    memset(work + 0x4F0, 0, 6);
    if (!(**(u16 **)&((PersonaRenderWork *)work)->controllerAddress & 4)) {
        t4 = ((PersonaRenderWork *)work)->flags;
        if (t4 & 0x80000) {
            t3_2 = ((ShdPersonaEffect *)((PersonaRenderWork *)work)->effect)->flags;
            if (!(t3_2 & 2)) {
                if (!(t3_2 & 1)) {
                    MEMBER(s32, work, PersonaRenderWork, flags) = t4 & 0xFFF7FFFF;
                } else {
                    MEMBER(s16, work, PersonaRenderWork, effectState.frame) = 0;
                    MEMBER(u16, work, PersonaRenderWork, effectState.flags) |= 2;
                }
            }
        }
    }
    if (**(u16 **)&((PersonaRenderWork *)work)->controllerAddress & 4) {
        ((PersonaRenderWork *)work)->flags |= 0x80000;
        memset(work + 0x458, 0, 0x68);
    }
    shdPersonaDispCtlReconfigure(MEMBER(u8 *, work, PersonaRenderWork, model), ((DatPersonaRecord *)personaAddress)->id, t17);
    shdPersonaEndSelection(task, 0);
    shdPersonaLevelUpRoute(task);
}


extern char D_005E4E00[];
void shdPersonaDispCtlSetGaugeEnabled(u8 *, s32);
// Sets the persona panel state and reconfigures the panel for the new state.
// FUN_0011B6D0
s32 shdPersonaSetState(u8 *task, s32 inputState)
{
    u8 *work;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;

    work = ((SdkTask *)task)->work;
    if (((PersonaRenderWork *)work)->state != inputState) {
        MEMBER(s32, work, PersonaRenderWork, state) = inputState;
        switch (inputState) {
        case 0:
            t1 = ((PersonaRenderWork *)work)->flags | 0x40;
            ((PersonaRenderWork *)work)->flags = t1;
            t2 = t1 | 0x20;
            ((PersonaRenderWork *)work)->flags = t2;
            t3 = t2 | 0x80;
            ((PersonaRenderWork *)work)->flags = t3;
            t4 = t3 | 0x400;
            ((PersonaRenderWork *)work)->flags = t4;
            t5 = t4 | 0x40000;
            ((PersonaRenderWork *)work)->flags = t5;
            t6 = t5 | 0x200000;
            ((PersonaRenderWork *)work)->flags = t6;
            break;
        case 1:
            t1 = ((PersonaRenderWork *)work)->flags | 0x10;
            ((PersonaRenderWork *)work)->flags = t1;
            t2 = t1 | 0x40;
            ((PersonaRenderWork *)work)->flags = t2;
            t3 = t2 | 0x20;
            ((PersonaRenderWork *)work)->flags = t3;
            t4 = t3 | 0x80;
            ((PersonaRenderWork *)work)->flags = t4;
            t5 = t4 | 0x400;
            ((PersonaRenderWork *)work)->flags = t5;
            t6 = t5 | 0x40000;
            ((PersonaRenderWork *)work)->flags = t6;
            t7 = t6 | 0x200000;
            ((PersonaRenderWork *)work)->flags = t7;
            break;
        case 2:
            t1 = ((PersonaRenderWork *)work)->flags | 0x10;
            ((PersonaRenderWork *)work)->flags = t1;
            t2 = t1 | 0x40;
            ((PersonaRenderWork *)work)->flags = t2;
            t3 = t2 | 0x20;
            ((PersonaRenderWork *)work)->flags = t3;
            t4 = t3 | 0x80;
            ((PersonaRenderWork *)work)->flags = t4;
            t5 = t4 | 0x400;
            ((PersonaRenderWork *)work)->flags = t5;
            t6 = t5 | 0x40000;
            ((PersonaRenderWork *)work)->flags = t6;
            t7 = t6 | 0x200000;
            ((PersonaRenderWork *)work)->flags = t7;
            break;
        case 3:
            t1 = ((PersonaRenderWork *)work)->flags | 0x10;
            ((PersonaRenderWork *)work)->flags = t1;
            t2 = t1 | 0x40;
            ((PersonaRenderWork *)work)->flags = t2;
            t3 = t2 | 0x20;
            ((PersonaRenderWork *)work)->flags = t3;
            t4 = t3 | 0x80;
            ((PersonaRenderWork *)work)->flags = t4;
            t5 = t4 | 0x100;
            ((PersonaRenderWork *)work)->flags = t5;
            t6 = t5 | 0x200000;
            ((PersonaRenderWork *)work)->flags = t6;
            t7 = (s32)resourceFindByName(D_005E4E00);
            ((PersonaRenderWork *)work)->backdropTexture = t7;
            if (t7 == 0) {
                kAssertFail(D_005E4868, 0xC02);
            }
            break;
        case 4:
            t1 = ((PersonaRenderWork *)work)->flags | 0x10;
            ((PersonaRenderWork *)work)->flags = t1;
            t2 = t1 | 0x40;
            ((PersonaRenderWork *)work)->flags = t2;
            t3 = t2 | 0x20;
            ((PersonaRenderWork *)work)->flags = t3;
            t4 = t3 | 0x200000;
            ((PersonaRenderWork *)work)->flags = t4;
            break;
        default:
            kAssertFail(D_005E4868, 0xC0E);
            break;
        }
        shdPersonaDispCtlSetGaugeEnabled(((PersonaRenderWork *)work)->model, 1);
    }
    return 0;
}


// Fill a state block from the persona record pointer, choosing the layout by the panel state.
// FUN_0011B8F0
void shdPersonaFillStateBlock(u8 *task, u8 *stats)
{
    u8 *work;
    u16 *ptr;
    s32 state;
    s32 i;

    work = ((SdkTask *)task)->work;
    ptr = *(u16 **)&((PersonaRenderWork *)work)->controllerAddress;
    state = ((PersonaRenderWork *)work)->state;
    switch (state) {
    case 0:
    case 1:
    case 2:
        shdPersonaFillStatusBlock((DatPersonaRecord *)ptr, work + 0xC, 2);
        break;
    case 3:
    case 4:
        shdPersonaFillStatusBlock((DatPersonaRecord *)ptr, work + 0xC, 1);
        break;
    default:
        kAssertFail(D_005E4868, 0xB91);
        break;
    }
    for (i = 0; i < 5; i++) {
        *(u8 *)(work + MEMBER_OFFSET(PersonaRenderWork, persona[0].added) + i) = stats[i];
    }
}


// Stores a value in the first persona's nextExperience field in the task's work block.
// FUN_0011B9E0
void shdPersonaSetHandleValue(int task, u32 value)
{
    ((PersonaRenderWork *)((SdkTask *)task)->work)->persona[0].nextExperience = value;
}
// Stores a value in the backdrop bonus field of the task's work block. Nothing in the tree calls
// it.
// FUN_0011B9F0
void shdPersonaSetExtraValue(int task, u32 value)
{
    ((PersonaRenderWork *)((SdkTask *)task)->work)->backdrop.bonus = value;
}
// Returns whether an open (0x2) or close (0x4) transition is in progress.
// FUN_0011BA00
s32 shdPersonaIsTransitioning(u8 *task)
{
    s32 flags = ((PersonaRenderWork *)((SdkTask *)task)->work)->flags;
    if ((flags & 2) || (flags & 4)) {
        return 1;
    }
    return 0;
}


// Begins the persona open transition: sets the open and active flags and clears the close and
// selection flags.
// FUN_0011BA40
void shdPersonaBeginOpen(u8 *panel)
{
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 state;
    u16 *p;

    t1 = ((PersonaRenderWork *)panel)->flags | 1;
    ((PersonaRenderWork *)panel)->flags = t1;
    t2 = t1 | 2;
    ((PersonaRenderWork *)panel)->flags = t2;
    t3 = t2 | 0x200000;
    ((PersonaRenderWork *)panel)->flags = t3;
    t4 = t3 | 0x800000;
    ((PersonaRenderWork *)panel)->flags = t4;
    t5 = t4 & ~4;
    ((PersonaRenderWork *)panel)->flags = t5;
    t6 = t5 & ~0x4000;
    ((PersonaRenderWork *)panel)->flags = t6;
    t7 = t6 & 0xFFBFFFFF;
    ((PersonaRenderWork *)panel)->flags = t7;
    p = *(u16 **)&((PersonaRenderWork *)panel)->controllerAddress;
    if (p != NULL && (*p & 4)) {
        MEMBER(s32, panel, PersonaRenderWork, flags) |= 0x80000;
        memset(panel + 0x458, 0, 0x68);
    } else {
        MEMBER(s32, panel, PersonaRenderWork, flags) &= 0xFFF7FFFF;
    }
    state = ((PersonaRenderWork *)panel)->state;
    switch (state) {
    case 0:
    case 1:
    case 2:
        sdkSndStartStream(0, 1, 0, 3);
        return;
    default:
        kAssertFail(D_005E4868, 0xC8F);
        /* fallthrough */
    case 3:
    case 4:
        return;
    }
}


// Start the persona panel slide-in with its tween and sound.
// FUN_0011BB90
void shdPersonaStartSlideIn(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    if (!(((PersonaRenderWork *)b)->flags & 2) && ((PersonaRenderWork *)b)->alpha != 0xFF) {
        f32 t;
        f32 u;
        Vec2f src;
        Vec2f dst;
        shdPersonaBeginOpen(b);
        *(u16 *)&((PersonaRenderWork *)b)->openingFrame = 0;
        ((PersonaRenderWork *)b)->startAlpha = MEMBER(u8, b, PersonaRenderWork, alpha);
        ((PersonaRenderWork *)b)->targetAlpha = 0xFF;
        t = 131.0f + ((PersonaRenderWork *)b)->origin.x;
        src.x = t;
        u = -59.0f + ((PersonaRenderWork *)b)->origin.y;
        src.y = u;
        dst.x = 640.0f + t;
        dst.y = u;
        shdPersonaDispCtlSetOffsets(((PersonaRenderWork *)b)->model, &dst, &src);
        shdPersonaDispCtlSetPosition(MEMBER(u8 *, b, PersonaRenderWork, model), 0);
        shdPersonaSetupChannels(b, 0);
    }
}


// Begin the persona close transition: set the close flag and clear the open and selection flags.
// FUN_0011BC70
void shdPersonaBeginClose(u8 *task)
{
    u8 *work;
    s32 flags;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 state;

    work = ((SdkTask *)task)->work;
    flags = ((PersonaRenderWork *)work)->flags;
    if (((flags & 1) != 0 && (flags & 4) == 0) || (flags & 0x400000) != 0) {
        t1 = ((PersonaRenderWork *)((SdkTask *)task)->work)->flags | 4;
        ((PersonaRenderWork *)work)->flags = t1;
        t2 = t1 & ~2;
        ((PersonaRenderWork *)work)->flags = t2;
        t3 = t2 & ~0x800;
        ((PersonaRenderWork *)work)->flags = t3;
        t4 = t3 & ~0x1000;
        ((PersonaRenderWork *)work)->flags = t4;
        t5 = t4 & ~0x2000;
        ((PersonaRenderWork *)work)->flags = t5;
        t6 = t5 & ~0x4000;
        ((PersonaRenderWork *)work)->flags = t6;
        ((ShdSkillState *)((PersonaRenderWork *)work)->skills)->cursor = -1;
        *(s32 *)&((PersonaRenderWork *)work)->selectionPosition.x = 0xC3E10000;
        state = ((PersonaRenderWork *)work)->state;
        switch (state) {
        case 0:
            sdkSndStartStream(0, 1, 0, 4);
            break;
        case 1:
        case 3:
        case 2:
        case 4:
            break;
        default:
            kAssertFail(D_005E4868, 0xCCC);
            break;
        }
        ((PersonaRenderWork *)work)->openingFrame = 0;
        ((PersonaRenderWork *)work)->startAlpha = ((PersonaRenderWork *)work)->alpha;
        *(s8 *)&((PersonaRenderWork *)work)->targetAlpha = 0;
        shdPersonaSetupChannels(work, 1);
        MEMBER(s32, work, PersonaRenderWork, flags) &= 0xFF7FFFFF;
    }
}


f32 shdPersonaGetBarProgress(u8 *, Vec2f *);
void shdPersonaDispCtlCommitPosition(u8 *);
/* Starts the persona panel slide-out and hands off to the close tween. */
// FUN_0011BDC0
void shdPersonaStartSlideOut(u8 *task)
{
  u8 *baseWork;
  f32 *xField;
  Vec2f v2;
  Vec2f v;
  f32 result;
  int isZero;
    baseWork = (*((SdkTask *) task)).work;
  if (!((*((s32 *) (baseWork + 0x534))) & 2))
  {
    shdPersonaBeginOpen(baseWork);
    *((u16 *) (baseWork + 0x508)) = 0;
    *((u8 *) (baseWork + 0x504)) = *((u8 *) (baseWork + 0x505));
    *((u8 *) (baseWork + 0x506)) = 0xFF;
    shdPersonaSetupChannels(baseWork, 4);
    v.x = 131.0f + (*((f32 *) (baseWork + 0x4FC)));
    v.y = (-59.f) + (*((f32 *) (baseWork + 0x500)));
    result = shdPersonaGetBarProgress(*((u8 **) (baseWork + 0x4F8)), &v2);
    isZero = result == 0.0f;
    if (isZero || (result == 1.0f))
    {
      xField = (f32 *) (baseWork + 0x4FC);
      result = 771.0f;
      result = result + (*xField);
      v2.x = result;
        v2.y = (-59.0f) + (*((f32 *) (baseWork + 0x500)));
        shdPersonaDispCtlSetOffsets(*((u8 **) (baseWork + 0x4F8)), &v2, &v);
        shdPersonaDispCtlCommitPosition(*((u8 **) (baseWork + 0x4F8)));
    }
    else
    {
      shdPersonaDispCtlSetOffsets(*((u8 **) (0x4F8 + baseWork)), &v2, &v);
    }
    *((s32 *) (baseWork + 0x534)) |= 0x200000;
  }
}


/* Enters the persona close state once: sets the closing flag, clears the open, selection and reveal
 * flags, resets the slot to -1, sets up five channels, and repositions the display control from the
 * bar progress. */
// FUN_0011BF10
void shdPersonaEnterCloseState(u8 *task)
{
  u8 *w;
  int new_var27;
  int new_var8;
  s32 flags;
  int new_var11;
  s32 t1;
  u8 *new_var13;
  f32 *new_var12;
  s32 *new_var19;
  u16 t7;
  int new_var24;
  unsigned char new_var22;
  s32 t2;
  s32 *new_var21;
  u8 **new_var30;
  int new_var23;
  u8 *new_var2;
  float new_var9;
  s32 *new_var7;
  int new_var;
  s32 t3;
  u8 *new_var15;
  u8 *new_var20;
  u8 *new_var3;
  unsigned int t4;
  int new_var14;
  u8 *new_var4;
  int new_var26;
  u8 *new_var5;
  int new_var10;
  s32 t5;
  int new_var18;
  float new_var28;
  u8 *new_var16;
  s32 t6;
  u8 *new_var25;
  s32 state;
  s32 new_var17;
  u8 *new_var6;
  Vec2f v2;
  s32 *new_var29;
  f32 ret;
  Vec2f v;
  if ((((!new_var2) && (!new_var2)) && (!new_var2)) != 0)
  {
  }
  ret++;
  ret--;
  w = ((SdkTask *) task)->work;
  flags = *((s32 *) (w + 0x534));
  ;
  if ((((flags & 1) != 0) && ((flags & 4) == 0)) && (((state = flags) & 0x400000) == 0))
  {
    if (new_var15)
    {
    }
    t1 = (*((s32 *) (w - -0x534)) = flags | 4);
    new_var19 = (s32 *) (w + 0x52C);
    new_var15 = w - -0x534;
    *((s32 *) (w + 0x534)) = (t2 = t1 & (~2));
    t3 = (*((s32 *) new_var15) = t2 & (~0x800));
    *((s32 *) (w + 0x534)) = (t4 = t3 & (~0x1000));
    new_var21 = (s32 *) (w + 0x534);
    *new_var21 = (t5 = t4 & (~0x2000));
    t6 = (*new_var21 = t5 & (~0x4000));
    t6 = 0x88;
    new_var7 = new_var19;
    new_var10 = -1;
    *((s8 *) (w + t6)) = new_var10;
    new_var24 = 0x444 & 0xFFFFFFFF;
 goto dummy_label_194269;
 dummy_label_194269: ;
    t2 = (0, 0);
    new_var29 = &(*new_var7);
    *((s32 *) (w + new_var24)) = 0xC3E10000;
    state = *new_var29;
    switch (state)
    {
      case 0:
        if (new_var2)
      {
      }
        sdkSndStartStream(0, 1, t2 & 0xFFFFFFFFFFFFFFFF, 4);
        break;

      case 1:
        new_var17 = t1;
      {
      }

do { case 3: case 2: case 4: break; default: task++; task--; kAssertFail(D_005E4868, 0xCCC & 0xFFFFFFFFFFFFFFFF); if (1) { } break; }
 while (0 * (!new_var2));
    }

    *((u16 *) (w + 0x508)) = (t6 = 0);
    new_var2 = w;
    new_var22 = t3 & (~0x1000);
    new_var2 = w;
    new_var16 = w;
    *((u8 *) (new_var16 + 0x504)) = *((u8 *) (new_var4 = new_var16 + 0x505));
    *((u8 *) (new_var16 + 0x506)) = 0xFF & 0xFFFFFFFFu;
    t2 = 771.0f;
    new_var6 = new_var16;
    shdPersonaSetupChannels(new_var6, 5);
    new_var20 = new_var16 - -0x4FC;
    new_var5 = new_var20;
    v.x = t2 + (*((f32 *) new_var5));
    new_var27 = 0xFFFFu & 0xFFFFFFFFu;
    new_var10 = ((new_var16 && new_var16) && w) != 0U;
    if (new_var10)
    {
    }
    ;
    v.y = (new_var9 = -59.0f) + (*((f32 *) (new_var2 + 0x500)));
    new_var = 2;
    ret = shdPersonaGetBarProgress(*((u8 **) (new_var2 + 0x4F8)), &v2);
    new_var11 = ret == 0.f;
    if (new_var11 || (1.0f == ret))
    {
      new_var30 = (u8 **) (new_var2 + 0x4F8);
      new_var3 = new_var2;
      new_var13 = new_var2;
      new_var13 = new_var13 + 0x4F8;
      new_var28 = -59.0f;
      if (w != 0)
      {
 do { } while (0);
      }
      v2.x = 131.0f + (*((f32 *) (new_var2 + 0x4FC)));
      v2.y = new_var28 + (*((f32 *) (new_var3 + 0x500)));
      shdPersonaDispCtlSetOffsets(*new_var30, &v2, &v);
      shdPersonaDispCtlCommitPosition(*((u8 **) new_var13));
    }
    else
    {
      shdPersonaDispCtlSetOffsets(*((u8 **) (new_var2 + 0x4F8)), &v2, &v);
    }
    t4 = new_var22;
    flags = *((s32 *) (new_var2 + 0x534));
    if ((0x80000 & flags) != 0)
    {
      new_var14 = (!new_var2) * 0;
      t7 = *((u16 *) (new_var2 + 0x458));
      if ((t7 & new_var) == 0)
      {
        if (((unsigned int) ((new_var17 = t1) && t1)) && t1)
        {
        }
        if ((t7 & 1) == ((!new_var2) * 0))
        {
          *((s32 *) (w + 0x534)) = flags & (~0x80000);
        }
        else
        {
          new_var25 = w;
          new_var22 = t3 & (~0x1000);
          new_var18 = new_var27;
          *((0, (u16 *) (new_var25 + 0x45A))) = 0;
          new_var8 = new_var18;
          new_var26 = 0x458;
          *((u16 *) (w + new_var26)) |= 2 & new_var8;
          if ((double) (!new_var25))
          {
          }
 do { } while (new_var14);
        }
        new_var5 = new_var20;
      }
    }
  }
}


// Sets up two channels and the start position, copies the 15-word parameter block into the work
// snapshot, ends the selection, then starts the display transition.
// FUN_0011C180
void shdPersonaBeginDisplayAndEndSelection(u8 *task, s32 category, s32 personaAddress, s8 cursor)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (!(((PersonaRenderWork *)work)->flags & 0x4000)) {
        shdPersonaSetupChannels(work, 2);
        ((PersonaRenderWork *)work)->channels[3].start.x = (f32)0x28A;
        *(s32 *)&((PersonaRenderWork *)work)->channels[3].start.y = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[1].start.x = 0x42C80000;
        *(s32 *)&((PersonaRenderWork *)work)->channels[1].start.y = 0;
        ((PersonaRenderWork *)work)->channels[1].startAlpha = 0;
        ((PersonaRenderWork *)work)->channels[2].startAlpha = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[9].start.x = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[9].start.y = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[7].start.x = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[7].start.y = 0;
        ((PersonaRenderWork *)work)->channels[7].startAlpha = 0xFF;
        ((PersonaRenderWork *)work)->channels[8].startAlpha = 0xFF;
        ((PersonaRenderWork *)work)->comparisonFrame = 0;
        MEMBER(s32, work, PersonaRenderWork, flags) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    shdPersonaEndSelection(task, 0);
    shdPersonaSetDisplayState(task, category, personaAddress, cursor);
    sdkSndStartStream(0, 2, 0, 5);
}


// Snapshots the 15-word parameter block into the saved copy, sets up three channels once, then
// starts the display transition with the given target, index and flag. measured: retail code
// changes with direct fields or local object aliases, so fields are accessed through named MEMBER
// offsets.
// FUN_0011C2C0
void shdPersonaBeginDisplay(u8 *task, s32 category, s32 personaAddress, s8 cursor)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (!(((PersonaRenderWork *)work)->flags & 0x4000)) {
        shdPersonaSetupChannels(work, 3);
        *(s32 *)&((PersonaRenderWork *)work)->channels[3].start.x = 0xC3480000;
        *(s32 *)&((PersonaRenderWork *)work)->channels[3].start.y = 0;
        ((PersonaRenderWork *)work)->channels[3].startAlpha = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[1].start.x = 0xC2C80000;
        *(s32 *)&((PersonaRenderWork *)work)->channels[1].start.y = 0;
        ((PersonaRenderWork *)work)->channels[1].startAlpha = 0;
        ((PersonaRenderWork *)work)->channels[2].startAlpha = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[9].start.x = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[9].start.y = 0;
        ((PersonaRenderWork *)work)->channels[9].startAlpha = 0xFF;
        *(s32 *)&((PersonaRenderWork *)work)->channels[7].start.x = 0;
        *(s32 *)&((PersonaRenderWork *)work)->channels[7].start.y = 0;
        ((PersonaRenderWork *)work)->channels[7].startAlpha = 0xFF;
        ((PersonaRenderWork *)work)->channels[8].startAlpha = 0xFF;
        ((PersonaRenderWork *)work)->comparisonFrame = 0;
        MEMBER(s32, work, PersonaRenderWork, flags) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    shdPersonaSetDisplayState(task, category, personaAddress, cursor);
    sdkSndStartStream(0, 2, 0, 5);
}


/* measured: retail hoists loop-invariant values out of the tween loop to keep its multiply-add
 * instruction pairs. */
#pragma push
#pragma opt_loop_invariants on
// Tweens the comparison display from its start values toward its targets over the comparison
// window.

// FUN_0011C3E0
void shdPersonaTweenComparison(u8 *panel)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 lo;
    f32 hi;
    f32 base;
    f32 delta;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s16 raw;
    u8 *src;
    u8 *dst;
    f32 value;
    u8 c;

    for (i = 0; i < 10; i++) {
        /* lint: allow H001 -- retail reloads the comparison frame on every record; see the demotion
         * note above */
        raw = *(volatile s16 *)&((PersonaRenderWork *)panel)->comparisonFrame;
        lo = ((PersonaRenderWork *)(panel + i * 36))->channels[0].duration;
        ratio = (f32)raw;
        if (ratio < lo) {
            ratio = 0.0f;
        } else {
            hi = ((PersonaRenderWork *)(panel + i * 36))->channels[0].delay;
            if (ratio > hi) {
                ratio = 1.0f;
            } else {
                ratio = (ratio - lo) / (hi - lo);
            }
        }
        base = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].start.x;
        delta = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].target.x - base;
        ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].current.x = base + ratio * delta;
        base = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].start.y;
        delta = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].target.y - base;
        ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].current.y = base + ratio * delta;
        a = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].startAlpha;
        b = ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].targetAlpha;
        diff = (f32)(b - a);
        f_abs = (f32)(u32)a;
        acc = f_abs + ratio * diff;
        ((PersonaRenderWork *)((u32)panel + i * 36))->channels[0].alpha = (u8)acc;
    }
    if (!((f32)((PersonaRenderWork *)panel)->comparisonFrame <= 4.0f)) {
        ((PersonaRenderWork *)panel)->flags &= ~0x4000;
        for (j = 0; j < 10; j++) {
            src = D_005E4950 + j * 20;
            dst = panel + j * 36;
            value = *(f32 *)src;
            ((PersonaRenderWork *)dst)->channels[0].current.x = value;
            ((PersonaRenderWork *)dst)->channels[0].start.x = value;
            ((PersonaRenderWork *)dst)->channels[0].target.x = value;
            value = ((ShdPersonaChannelPreset *)src)->position.y;
            ((PersonaRenderWork *)dst)->channels[0].current.y = value;
            ((PersonaRenderWork *)dst)->channels[0].start.y = value;
            ((PersonaRenderWork *)dst)->channels[0].target.y = value;
            c = ((ShdPersonaChannelPreset *)src)->alpha;
            ((PersonaRenderWork *)dst)->channels[0].alpha = c;
            ((PersonaRenderWork *)dst)->channels[0].startAlpha = c;
            ((PersonaRenderWork *)dst)->channels[0].targetAlpha = c;
            *(s32 *)&((PersonaRenderWork *)dst)->channels[0].duration = 0;
            *(s32 *)&((PersonaRenderWork *)dst)->channels[0].delay = 0;
        }
    }
}
#pragma pop


// Returns whether the persona selection flag 0x800 is set.
// FUN_0011C610
u32 shdPersonaIsSelectionActive(u8 *task)
{
    return (((PersonaRenderWork *)((SdkTask *)task)->work)->flags & 0x800) != 0;
}


// Begins persona selection: sets the selection and selection-active flags.
// FUN_0011C630
void shdPersonaBeginSelection(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    s32 v = ((PersonaRenderWork *)b)->flags;
    if ((v & 0x20) != 0 && (v & 0x4000) == 0 && (v & 0x1000) == 0 && ((v & 0x800) == 0 || (v & 0x2000) != 0)) {
        ((PersonaRenderWork *)b)->selectionStart.x = ((PersonaRenderWork *)b)->selectionPosition.x;
        ((PersonaRenderWork *)b)->selectionStart.y = ((PersonaRenderWork *)b)->selectionPosition.y;
        *(s32 *)&((PersonaRenderWork *)b)->selectionTarget.x = 0;
        *(u16 *)&((PersonaRenderWork *)b)->selectionFrame = 0;
        *(u8 *)&((ShdSkillState *)((PersonaRenderWork *)b)->skills)->cursor = 0;
        ((PersonaRenderWork *)b)->flags |= 0x1000;
        ((PersonaRenderWork *)b)->flags |= 0x800;
        ((PersonaRenderWork *)b)->flags &= ~0x2000;
        sdkSndStartStream(0, 1, 0, 3);
    }
}


// End persona selection and set the selection-end flag 0x2000; mode selects how selection ends.
// FUN_0011C6E0
void shdPersonaEndSelection(u8 *task, s32 mode)
{
    u8 *b = ((SdkTask *)task)->work;
    s32 v = ((PersonaRenderWork *)b)->flags;
    if ((v & 0x20) != 0 && (v & 0x800) != 0 && (v & 0x2000) == 0) {
        ((PersonaRenderWork *)b)->selectionStart.x = ((PersonaRenderWork *)b)->selectionPosition.x;
        ((PersonaRenderWork *)b)->selectionStart.y = ((PersonaRenderWork *)b)->selectionPosition.y;
        *(s32 *)&((PersonaRenderWork *)b)->selectionTarget.x = 0xC3E10000;
        *(u16 *)&((PersonaRenderWork *)b)->selectionFrame = 0;
        MEMBER(s32, b, PersonaRenderWork, flags) |= 0x2000;
        MEMBER(s32, b, PersonaRenderWork, flags) &= ~0x1000;
        if (mode != 0) {
            sdkSndStartStream(0, 1, 0, 4);
        }
    }
}


/* measured: retail's prologue load order needs the optimizer setting below; plain C emits two load-
 * order words differently. */
#pragma push
/* measured: with propagation off, the prologue loads come out in retail order. */
#pragma opt_propagation off
// Tweens the persona selection panel open and clears its opening flag when done.
// FUN_0011C780
void shdPersonaTweenSelectionOpen(u8 *panel)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 lo;
    f32 hi;
    f32 base;
    f32 delta;
    s32 a;
    s32 b;
    s16 raw;
    raw = ((PersonaRenderWork *)panel)->selectionFrame;
    lo = ((PersonaRenderWork *)panel)->selectionStartFrame;
    ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f;
    else { hi = ((PersonaRenderWork *)panel)->selectionEndFrame; if (ratio > hi) ratio = 1.0f; else ratio = sinf(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = ((PersonaRenderWork *)panel)->selectionStart.x; delta = ((PersonaRenderWork *)panel)->selectionTarget.x - base; ((PersonaRenderWork *)panel)->selectionPosition.x = base + ratio * delta;
    base = ((PersonaRenderWork *)panel)->selectionStart.y; delta = ((PersonaRenderWork *)panel)->selectionTarget.y - base; ((PersonaRenderWork *)panel)->selectionPosition.y = base + ratio * delta;
    a = ((PersonaRenderWork *)panel)->selectionStartAlpha; b = ((PersonaRenderWork *)panel)->selectionTargetAlpha; diff = (f32)(b - a); f_abs = (f32)(u32)a;
    acc = f_abs + ratio * diff;
    ((PersonaRenderWork *)panel)->selectionAlpha = (u8)acc;
    if (!((f32)(s16)MEMBER(s16, panel, PersonaRenderWork, selectionFrame) <= 5.0f)) ((PersonaRenderWork *)panel)->flags &= ~0x1000;
}
#pragma pop
/* measured: retail computes ratio-first products (base + ratio delta), declares diff first, and
 * calls func_0044b7b0 inside the else-if branch. */
#pragma push
/* measured: with propagation off, the prologue loads come out in retail order. */
#pragma opt_propagation off
// Tweens the persona selection panel closed, clearing the selection flags and resetting the
// selected index.
// FUN_0011C930
void shdPersonaTweenSelectionClose(u8 *panel)
{ s32 a; s32 b; s16 raw; f32 diff; f32 f_abs; f32 acc; f32 ratio; f32 lo; f32 hi; f32 base; f32 delta;
    raw = ((PersonaRenderWork *)panel)->selectionFrame; lo = ((PersonaRenderWork *)panel)->selectionStartFrame; ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f; else { hi = ((PersonaRenderWork *)panel)->selectionEndFrame; if (ratio > hi) ratio = 1.0f; else ratio = sinf(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = ((PersonaRenderWork *)panel)->selectionStart.x; delta = ((PersonaRenderWork *)panel)->selectionTarget.x - base; ((PersonaRenderWork *)panel)->selectionPosition.x = base + ratio * delta;
    base = ((PersonaRenderWork *)panel)->selectionStart.y; delta = ((PersonaRenderWork *)panel)->selectionTarget.y - base; ((PersonaRenderWork *)panel)->selectionPosition.y = base + ratio * delta;
    a = ((PersonaRenderWork *)panel)->selectionStartAlpha; b = ((PersonaRenderWork *)panel)->selectionTargetAlpha; diff = (f32)(b - a); f_abs = (f32)(u32)a; acc = f_abs + ratio * diff;
    ((PersonaRenderWork *)panel)->selectionAlpha = (u8)acc;
    if (!((f32)(s16)MEMBER(s16, panel, PersonaRenderWork, selectionFrame) <= 5.0f)) { ((PersonaRenderWork *)panel)->flags &= ~0x800; ((PersonaRenderWork *)panel)->flags &= ~0x2000; ((ShdSkillState *)((PersonaRenderWork *)panel)->skills)->cursor = -1; }
}
#pragma pop
// Advances the persona selection cursor by one step.
// FUN_0011CAF0
void shdPersonaStepSelectionCursor(u8 *task)
{
    s32 flags;
    u8 *work;
    s32 bit800;
    s32 bit100000;

    work = ((SdkTask *)task)->work;
    flags = ((PersonaRenderWork *)work)->flags;
    bit800 = !!(flags & 0x800);
    if (bit800 == 0 || ((ShdSkillState *)((PersonaRenderWork *)work)->skills)->cursor == -1) {
        return;
    }
    bit100000 = (flags & 0x100000) != 0;
    if (ShdSkill_MoveCursor(work + 0x84, bit100000) != 0) {
        sdkSndStartStream(0, 0, 0, 0);
    }
}
// Adds a skill to the persona's skill list and returns 1 on success.
// FUN_0011CB70
s32 shdPersonaAddSkill(u8 *task, u16 skill)
{
    u8 *b = ((SdkTask *)task)->work;
    if (*(s32 *)b == 0) {
        kAssertFail(D_005E4868, 0xE21);
    }
    if (datPersonaAddSkill(*(u8 **)b, skill) != 0) {
        ShdSkill_AddActiveSkill(skill, b + 0x8C);
        return 1;
    }
    return 0;
}


// Replaces one skill in the persona's skill list with another and returns 1 on success.
// FUN_0011CC00
s32 shdPersonaReplaceSkill(u8 *task, u16 previousSkill, u16 replacement)
{
    u8 *b = ((SdkTask *)task)->work;
    if (*(s32 *)b == 0) {
        kAssertFail(D_005E4868, 0xE45);
    }
    if (datPersonaReplaceSkill(*(u8 **)b, (s16)previousSkill, replacement) != -1) {
        ShdSkill_ReplaceActiveSkill(previousSkill, replacement, b + 0x8C);
        return 1;
    }
    return 0;
}


// Returns the skill id in the selected slot, or the pending acquisition skill when flag 0x100000 is
// set and the cursor is 8.
// FUN_0011CCB0
u16 shdPersonaGetSelectedSkillId(u8 *panel)
{
    s32 v = ((PersonaRenderWork *)panel)->flags;
    if (v & 0x2000) {
        return 0;
    }
    if ((v & 0x100000) != 0 && ((ShdSkillState *)((PersonaRenderWork *)panel)->skills)->cursor == 8) {
        return ((PersonaRenderWork *)panel)->acquisition.skill;
    }
    return ShdSkill_GetSlotSkillId(panel + 0x84);
}


// Advances the skill-pulse phase and clears the pulse flag 0x8000 when the cycle ends.
// FUN_0011CD20
void shdPersonaUpdateSkillPulse(u8 *panel)
{
    f32 f1 = (f32)((PersonaRenderWork *)panel)->skillFrame;
    if (f1 > 25.0f) {
        ((PersonaRenderWork *)panel)->flags &= ~0x8000;
    } else if (f1 > 25.0f) {
        f1 = 25.0f;
    }
    ((PersonaRenderWork *)panel)->selectedSkillFade = sinf(D_007613EC * f1 / 25.0f);
}


// Sets the pending skill id and sets the queue flag 0x100000.
// FUN_0011CDD0
void shdPersonaSetPendingSkill(u8 *task, s32 inputSkill)
{
    u8 *b = ((SdkTask *)task)->work;
    ((PersonaRenderWork *)b)->flags |= 0x100000;
    memset(b + 0x4F0, 0, 6);
    ((PersonaRenderWork *)b)->acquisition.skill = inputSkill;
}


// Resets acquisition.frame and sets the armed bit 0x2 in acquisition.flags.
// FUN_0011CE30
void shdPersonaArmSkillReveal(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    ((PersonaRenderWork *)b)->acquisition.frame = 0;
    ((PersonaRenderWork *)b)->acquisition.flags |= 2;
}


// Advances the skill-reveal frame and plays the reveal sound at the cue frame.
// FUN_0011CE50
void shdPersonaUpdateReveal(u8 *panel)
{
    s32 v = ((PersonaRenderWork *)panel)->flags;
    if ((v & 0x10000) != 0) {
        if (((PersonaRenderWork *)panel)->revealFrame == 10) {
            sdkSndStartChannel(2, D_005E4E20);
        }
    } else if ((v & 0x20000) != 0) {
        if (((PersonaRenderWork *)panel)->revealFrame >= 50) {
            MEMBER(s32, panel, PersonaRenderWork, flags) &= ~0x200;
        }
    }
}


// Picks the level-up route from the number of valid party members and steps its state from 0 to 4.
// FUN_0011CEE0
void shdPersonaLevelUpRoute(u8 *task)
{
    u8 *work;
    s32 flags;
    s32 state;
    u16 t17;

    work = ((SdkTask *)task)->work;
    flags = ((PersonaRenderWork *)work)->flags;
    if (flags & 0x40000) {
        state = ((PersonaRenderWork *)work)->state;
        switch (state) {
        case 0:
            if (((PersonaRenderWork *)work)->persona[0].category == 1) {
                if ((datPersonaCountValidMembers(1, state) & 0xFFFF) == 1) {
                    ((PersonaRenderWork *)work)->overlayId = 0xD;
                    return;
                }
                ((PersonaRenderWork *)work)->overlayId = 9;
                return;
            }
            ((PersonaRenderWork *)work)->overlayId = -1;
            return;
        case 1:
            if ((datPersonaCountValidMembers(1, state) & 0xFFFF) == 1) {
                ((PersonaRenderWork *)work)->overlayId = 0xA;
                return;
            }
            t17 = ((DatPersonaRecord *)*(u8 **)&((PersonaRenderWork *)work)->controllerAddress)->id;
            if (t17 == (datPersonaGetRecordId(1) & 0xFFFF)) {
                ((PersonaRenderWork *)work)->overlayId = 0xB;
                return;
            }
            ((PersonaRenderWork *)work)->overlayId = 9;
            return;
        case 2:
            ((PersonaRenderWork *)work)->overlayId = 0xC;
            return;
        case 3:
        case 4:
            if ((datPersonaCountValidMembers(flags, state) & 0xFFFF) == 1) {
                ((PersonaRenderWork *)work)->overlayId = 0xA;
                return;
            }
            ((PersonaRenderWork *)work)->overlayId = 9;
            return;
        default:
            kAssertFail(D_005E4868, 0xF87);
            break;
        }
    }
}


// Sets bits in the persona flags word.
// FUN_0011D080
void shdPersonaSetFlags(u8 *task, s32 inputFlags)
{
    u8 *b = ((SdkTask *)task)->work;
    ((PersonaRenderWork *)b)->flags |= inputFlags;
}


// Clears bits in the persona flags word.
// FUN_0011D0A0
void shdPersonaClearFlags(u8 *task, s32 inputFlags)
{
    u8 *b = ((SdkTask *)task)->work;
    ((PersonaRenderWork *)b)->flags &= ~inputFlags;
}


// Returns the persona panel alpha.
// FUN_0011D0C0
u8 shdPersonaGetAlpha(u8 *task)
{
    return ((PersonaRenderWork *)((SdkTask *)task)->work)->alpha;
}


// Refreshes the display-control position from the child model task.
// FUN_0011D0D0
void shdPersonaRefreshDispCtlPosition(u8 *task, u8 *position)
{
    shdPersonaDispCtlSetPosition((u8 *)*(s32 *)(((SdkTask *)task)->work + 0x4F8), position);
}

// Stores a two-float origin position, or zeroes it when position is NULL.
// FUN_0011D100
void shdPersonaSetOrigin(u8 *task, f32 *position)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (position == NULL) {
        ((PersonaRenderWork *)work)->origin.x = 0.0f;
        ((PersonaRenderWork *)work)->origin.y = 0.0f;
        return;
    }
    ((PersonaRenderWork *)work)->origin.x = position[0];
    ((PersonaRenderWork *)work)->origin.y = position[1];
}


// Sets the child display-control handle value to color.
// FUN_0011D140
void shdPersonaSetChildDispCtlHandle(u8 *task, s32 color)
{
    shdPersonaDispCtlSetHandle(((PersonaRenderWork *)((SdkTask *)task)->work)->model, color);
}

// Sets the child display-control handle and colour from handle and color.
// FUN_0011D170
void shdPersonaSetChildDispCtlHandleAndColor(u8 *task, s32 handle, s32 color)
{
    shdPersonaDispCtlSetHandle(((PersonaRenderWork *)((SdkTask *)task)->work)->model, handle);
    shdPersonaDispCtlSetColor((s32)((PersonaRenderWork *)MEMBER(u8 *, task, SdkTask, work))->model, color);
}


// Stores the persona opacity value.
// FUN_0011D1D0
void shdPersonaSetOpacity(u8 *task, f32 inputOpacity)
{
    ((PersonaRenderWork *)((SdkTask *)task)->work)->opacity = inputOpacity;
}


// Returns the persona panel's child model task pointer.
// FUN_0011D1E0
s32 shdPersonaGetChildTask(u8 *task)
{
    return *(s32 *)&((PersonaRenderWork *)((SdkTask *)task)->work)->model;
}


s32 kwlnTaskGetTaskByName(void *name);
s32 H_Cdvd_IsFileLoaded(s32 cdvd);
s32 H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
s32 filerEnqueueRequest(s32, const char *, s32, s32, s32, s32, s32, s32, s32, s32);
extern char D_005E4E60[];
extern char D_005E4E90[];
extern char iGpffff9c18;
// Advances the persona model-load state machine one step and returns its status.
// FUN_0011D1F0
s32 shdPersonaLoadModelStep(u8 *task)
{
    u8 *work;
    s32 state;
    s32 directory;
    s32 completed;

    work = ((SdkTask *)task)->work;
    state = ((ShdPersonaModelWork *)work)->state;
    switch (state) {
    case 0:
        if (((ShdPersonaModelWork *)work)->resourceId != 0) {
            if (kwlnTaskGetTaskByName(D_005E4E40) != 0) {
                func_00440b68(D_005E4E60);
            } else {
                sprintf(work + 0x54, D_005E4E90, MEMBER(s32, work, ShdPersonaModelWork, resourceId));
                func_00440b68(&iGpffff9c18, D_005E4868, 0x1046);
                directory = H_Cdvd_AcquireDirectory(work + 0x54, 0);
                ((ShdPersonaModelWork *)work)->directory = directory;
                if (directory == 0) {
                    kAssertFail(D_005E4868, 0x1047);
                }
                shdPersonaDispCtlSetPosition(task, NULL);
                ((ShdPersonaModelWork *)work)->state = 1;
            }
        } else {
            ((ShdPersonaModelWork *)work)->state = 3;
        }
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded(((ShdPersonaModelWork *)work)->directory) != 0) {
            ((ShdPersonaModelWork *)work)->stream = filerEnqueueRequest(0, (const char *)(work + 0x54), 0, 0, 0, 0, 0, 0, 0, 0);
            ((ShdPersonaModelWork *)work)->state = 2;
        }
        break;
    case 2:
        ((ShdPersonaModelWork *)work)->loaded = filerTakeCompletedRequest(((ShdPersonaModelWork *)work)->stream, &completed, 0);
        if (completed != 0) {
            MEMBER(s32, work, ShdPersonaModelWork, stream) = 0;
            H_Cdvd_Destroy(((ShdPersonaModelWork *)work)->directory);
            MEMBER(s32, work, ShdPersonaModelWork, directory) = 0;
            ((ShdPersonaModelWork *)work)->state = 3;
        }
        break;
    case 3:
        break;
    }
    return 0;
}


// Destroys a persona model-load task, freeing its child and its work block.
// FUN_0011D3C0
void shdPersonaModelDestroy(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    if (((ShdPersonaModelWork *)b)->stream != 0) {
        shdPersonaDispCtlCreate(((ShdPersonaModelWork *)b)->stream, ((ShdPersonaModelWork *)b)->directory, D_005E4E40);
        MEMBER(s32, b, ShdPersonaModelWork, stream) = 0;
        MEMBER(s32, b, ShdPersonaModelWork, directory) = 0;
        ((ShdPersonaModelWork *)b)->loaded = 0;
    } else {
        if (((ShdPersonaModelWork *)b)->directory != 0) {
            H_Cdvd_Destroy(((ShdPersonaModelWork *)b)->directory);
            MEMBER(s32, b, ShdPersonaModelWork, directory) = 0;
        }
        if (((ShdPersonaModelWork *)b)->loaded != 0) {
            func_003ef3a0(((ShdPersonaModelWork *)b)->loaded);
            MEMBER(s32, b, ShdPersonaModelWork, loaded) = 0;
        }
    }
    jtbl_008873EC[0](b);
}


// Create a persona model-load child task that loads the 166.ADX stream and its model.
// FUN_0011D460
u8 *shdPersonaModelCreate(s32 parentTask, s32 priority, f32 inputDepth, s32 inputResourceId, s32 inputHandle)
{
    Vec2f v;
    u8 *r;
    u8 *w;

    chkmemAllocSiteTag(D_005E4868, 0x1090);
    w = D_008873F4[0](1, 0x154, 0x40000);
    if (w == NULL) {
        return NULL;
    }
    r = (u8 *)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005E4EB0), priority, 0, 0, shdPersonaLoadModelStep, shdPersonaModelDestroy, (u8 *)(w));
    if (r == NULL) {
        return NULL;
    }
    ((ShdPersonaModelWork *)w)->resourceId = inputResourceId;
    ((ShdPersonaModelWork *)w)->handle = inputHandle;
    ((ShdPersonaModelWork *)w)->color = (inputHandle & 0xFF) | ~0x7EFF;
    ((ShdPersonaModelWork *)w)->depth = inputDepth;
    *(s32 *)&v.x = 0x43030000;
    *(s32 *)&v.y = 0xC26C0000;
    shdPersonaDispCtlSetPosition(r, (u8 *)&v);
    *(s32 *)&v.x = 0xC1880000;
    *(s32 *)&v.y = 0x41500000;
    shdPersonaDispCtlSetDrawOffset(r, v);
    return r;
}


s32 kwlnGetCamera(void);
extern f32 D_008872F8[];
extern s32 (*D_00887310[])(s32, void *, s32);
/* Submit two adjacent four-vertex strips using the renderer's 64-byte vertex layout. */
// FUN_0011D5B0
/* measured: retail keeps the unsigned colour conversion inputs hoisted and loads the near-plane
 * address before its float load. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void shdPersonaDrawQuadStrips(f32 depth, s32 color, s32 edgeAlpha, f32 x, f32 y, s32 width, s32 height, s32 raster)
{
    union { f32 scalar[2][64]; s32 words[2][64]; } vertices;
    f32 positions[16];
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 edge;
    f32 reciprocalZ;
    f32 screenZ;
    f32 middleX;
    f32 bottomY;
    f32 rightX;
    f32 channel;
    s32 vertexIndex;
    u32 callbackTable;
    f32 *nearPlane;

    reciprocalZ = 1.0f / ((MdlEffectCamera *)(u8 *)kwlnGetCamera())->nearPlane;
    red = (s32)(((u32)(color & 0xFF000000) >> 24) & 0xFF);
    green = (s32)(((u32)(color & 0xFF0000) >> 16) & 0xFF);
    blue = (s32)(((u32)(color & 0xFF00) >> 8) & 0xFF);
    alpha = color & 0xFF;
    edge = edgeAlpha & 0xFF;
    callbackTable = (u32)D_00887300;
    ((s32 (**)(s32, void *))callbackTable)[0](6, (void *)0);
    ((s32 (**)(s32, void *))callbackTable)[0](7, (void *)2);
    ((s32 (**)(s32, void *))callbackTable)[0](8, (void *)0);
    ((s32 (**)(s32, void *))callbackTable)[0](9, (void *)2);
    ((s32 (**)(s32, void *))callbackTable)[0](0xC, (void *)1);
    ((s32 (**)(s32, void *))callbackTable)[0](0xB, (void *)6);
    ((s32 (**)(s32, void *))callbackTable)[0](0xA, (void *)5);
    ((s32 (**)(s32, void *))callbackTable)[0](2, (void *)4);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    positions[0] = x;
    positions[1] = y;
    middleX = 256.0f + x;
    positions[6] = middleX;
    bottomY = y + (f32)height;
    positions[7] = bottomY;
    positions[2] = middleX;
    positions[3] = y;
    positions[4] = x;
    positions[5] = bottomY;
    positions[8] = middleX;
    positions[9] = y;
    rightX = 256.0f + middleX;
    positions[14] = rightX;
    positions[15] = bottomY;
    positions[10] = rightX;
    positions[11] = y;
    positions[12] = middleX;
    positions[13] = bottomY;
    vertexIndex = 0;
    nearPlane = D_008872F8;
    screenZ = *nearPlane - depth;
    while (vertexIndex < 4) {
        vertices.scalar[0][vertexIndex * 16 + 2] = screenZ;
        vertices.scalar[0][vertexIndex * 16 + 6] = reciprocalZ;
        channel = (f32)(u32)red;
        vertices.scalar[0][vertexIndex * 16 + 8] = channel;
        channel = (f32)(u32)green;
        vertices.scalar[0][vertexIndex * 16 + 9] = channel;
        channel = (f32)(u32)blue;
        vertices.scalar[0][vertexIndex * 16 + 10] = channel;
        channel = (f32)(u32)alpha;
        vertices.scalar[0][vertexIndex * 16 + 11] = channel;
        vertices.scalar[0][vertexIndex * 16 + 0] = positions[vertexIndex * 2];
        vertices.scalar[0][vertexIndex * 16 + 1] = positions[vertexIndex * 2 + 1];
        vertices.scalar[1][vertexIndex * 16 + 2] = screenZ;
        vertices.scalar[1][vertexIndex * 16 + 6] = reciprocalZ;
        channel = (f32)(u32)red;
        vertices.scalar[1][vertexIndex * 16 + 8] = channel;
        channel = (f32)(u32)green;
        vertices.scalar[1][vertexIndex * 16 + 9] = channel;
        channel = (f32)(u32)blue;
        vertices.scalar[1][vertexIndex * 16 + 10] = channel;
        channel = (f32)(u32)alpha;
        vertices.scalar[1][vertexIndex * 16 + 11] = channel;
        vertices.scalar[1][vertexIndex * 16 + 0] = positions[vertexIndex * 2 + 8];
        vertices.scalar[1][vertexIndex * 16 + 1] = positions[vertexIndex * 2 + 9];
        vertexIndex += 1;
    }
    channel = (f32)(u32)red;
    vertices.scalar[0][8] = channel;
    channel = (f32)(u32)green;
    vertices.scalar[0][9] = channel;
    channel = (f32)(u32)blue;
    vertices.scalar[0][10] = channel;
    channel = (f32)(u32)edge;
    vertices.scalar[0][11] = channel;
    channel = (f32)(u32)red;
    vertices.scalar[0][40] = channel;
    channel = (f32)(u32)green;
    vertices.scalar[0][41] = channel;
    channel = (f32)(u32)blue;
    vertices.scalar[0][42] = channel;
    channel = (f32)(u32)edge;
    vertices.scalar[0][43] = channel;
    vertices.words[0][4] = 0;
    vertices.words[0][5] = 0;
    vertices.words[0][20] = 0x3F000000;
    vertices.words[0][21] = 0;
    vertices.words[0][36] = 0;
    vertices.words[0][37] = 0x3F800000;
    vertices.words[0][52] = 0x3F000000;
    vertices.words[0][53] = 0x3F800000;
    vertices.words[1][4] = 0x3F000000;
    vertices.words[1][5] = 0;
    vertices.words[1][20] = 0x3F800000;
    vertices.words[1][21] = 0;
    vertices.words[1][36] = 0x3F000000;
    vertices.words[1][37] = 0x3F800000;
    vertices.words[1][52] = 0x3F800000;
    vertices.words[1][53] = 0x3F800000;
    ((s32 (**)(s32, void *))callbackTable)[0](1, (void *)*(s32 *)raster);
    callbackTable = (u32)D_00887310;
    ((s32 (**)(s32, void *, s32))callbackTable)[0](4, vertices.scalar[0], 4);
    ((s32 (**)(s32, void *, s32))callbackTable)[0](4, vertices.scalar[1], 4);
}
#pragma pop


// Draws a quad whose vertex offset eases from the start value to the end value using a sine lerp.
// FUN_0011DC50
void shdPersonaDrawSineQuad(u8 *task)
{
    u8 *work;
    f32 f20;
    f32 t;
    f32 d;
    s32 a;

    work = ((SdkTask *)task)->work;
    if (shdPersonaDispCtlIsLoaded(task) != 0 && ((ShdPersonaModelWork *)work)->resourceId != 0) {
        t = (f32)((ShdPersonaModelWork *)work)->frame;
        if (t < 10.0f) {
            MEMBER(s32, work, ShdPersonaModelWork, frame) += 1;
            f20 = ((ShdPersonaModelWork *)work)->start.x;
            t = sinf(iGpffff8094 * (f32)MEMBER(s32, work, ShdPersonaModelWork, frame) / 10.0f);
            d = ((ShdPersonaModelWork *)work)->target.x - f20;
            ((ShdPersonaModelWork *)work)->current.x = f20 + d * t;
        } else {
            ((ShdPersonaModelWork *)work)->current.x = ((ShdPersonaModelWork *)work)->target.x;
        }
        a = ((ShdPersonaModelWork *)work)->handle;
        shdPersonaDrawQuadStrips(((ShdPersonaModelWork *)work)->depth, a, a,
                      MEMBER(f32, work, ShdPersonaModelWork, current.x), ((ShdPersonaModelWork *)work)->current.y,
                      0x200, 0x200, ((ShdPersonaModelWork *)work)->loaded);
    }
}


/* Draws the state-3 gauge bar: two lerped spans scaled by one third of the total. */
// FUN_0011DD50
void shdPersonaDrawSmoothBar(u8 *task)
{
    u8 *work;
    s32 first;

    work = ((SdkTask *)task)->work;
    if (*(s32 *)work == 3 && ((ShdPersonaModelWork *)work)->resourceId != 0 &&
        ((ShdPersonaModelWork *)work)->drawGauge != 0) {
        ((ShdPersonaModelWork *)work)->committed.x +=
            (((ShdPersonaModelWork *)work)->current.x - ((ShdPersonaModelWork *)work)->committed.x) / 3.0f;
        ((ShdPersonaModelWork *)work)->committed.y +=
            (((ShdPersonaModelWork *)work)->current.y - ((ShdPersonaModelWork *)work)->committed.y) / 3.0f;
        first = ((ShdPersonaModelWork *)work)->color;
        shdDrawColourQuad(((ShdPersonaModelWork *)work)->depth, first,
                      MEMBER(f32, work, ShdPersonaModelWork, committed.x) + ((ShdPersonaModelWork *)work)->offset.x,
                      MEMBER(f32, work, ShdPersonaModelWork, committed.y) + ((ShdPersonaModelWork *)work)->offset.y,
                      ((ShdPersonaModelWork *)work)->current.x, ((ShdPersonaModelWork *)work)->current.y,
                      512.0f, 512.0f, ((ShdPersonaModelWork *)work)->loaded, 1, 0);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
}


// Set the low byte of the display-control handle and colour words to the mode.
// FUN_0011DE40
void shdPersonaDispCtlSetMode(u8 *task, u8 mode)
{
    u8 *b = ((SdkTask *)task)->work;
    s32 v = mode;
    ((ShdPersonaModelWork *)b)->handle = (((ShdPersonaModelWork *)b)->handle & ~0xFF) | v;
    ((ShdPersonaModelWork *)b)->color = (((ShdPersonaModelWork *)b)->color & ~0xFF) | v;
}

// Returns frame divided by 10.0 as the bar progress and writes the current position to position.
// FUN_0011DE80
f32 shdPersonaGetBarProgress(u8 *task, Vec2f *position)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    *position = ((ShdPersonaModelWork *)work)->current;
    return (f32)(((ShdPersonaModelWork *)work)->frame) / 10.0f;
}


// FUN_0011DEC0
s32 shdPersonaDispCtlGetHandle(u8 *task)
{
    return ((ShdPersonaModelWork *)((SdkTask *)task)->work)->handle;
}


// Poll the display-control model load and free its resources when the load completes.
// FUN_0011DED0
s32 shdPersonaDispCtlUpdate(u8 *task)
{
    u8 *w;
    s32 out;
    s32 p4c;
    s32 r;

    w = ((SdkTask *)task)->work;
    r = filerTakeCompletedRequest(*(s32 *)w, &out, 0);
    if (out != 0) {
        p4c = ((ShdPersonaStreamWork *)w)->directory;
        if (p4c != 0) {
            func_00440b68((s32)D_005E4ED0, (s32)(p4c + 0x10));
        } else {
            func_00440b68((s32)D_005E4EF0);
        }
        if (r != 0) {
            func_003ef3a0(r);
        }
        if (MEMBER(s32, w, ShdPersonaStreamWork, directory) != 0) {
            H_Cdvd_Destroy(MEMBER(s32, w, ShdPersonaStreamWork, directory));
        }
        return -1;
    }
    return 0;
}

// Destroy a display-control task through its registered destroy callback.
// FUN_0011DF90
void shdPersonaDispCtlDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}


// Create a display-control task that loads the named resource with the given format.
// FUN_0011DFC0
s32 shdPersonaDispCtlCreate(s32 stream, s32 inputDirectory, char *taskName)
{
    s32 r;
    u8 *buf;

    chkmemAllocSiteTag(D_005E4868, 0x11B2);
    buf = D_008873F4[0](1, 8, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    r = (s32)kwlnTaskCreate((const void *)(taskName), 0xF, 0, 0, shdPersonaDispCtlUpdate, shdPersonaDispCtlDestroy, (u8 *)(buf));
    if (r == 0) {
        return 0;
    }
    if (inputDirectory != 0) {
        func_00440b68((s32)D_005E4F10, (s32)(inputDirectory + 0x10));
    }
    *(s32 *)buf = stream;
    ((ShdPersonaStreamWork *)buf)->directory = inputDirectory;
    return r;
}


s32 shdPersonaDispCtlUpdate(u8 *task);
// Reconfigures a display-control task by destroying its child and creating a new one.
// FUN_0011E0C0
void shdPersonaDispCtlReconfigure(u8 *task, s32 inputResourceId, s32 inputHandle)
{
    u8 *w = ((SdkTask *)task)->work;
    s32 p48;
    s32 p4c;
    u8 *r;

    if (((ShdPersonaModelWork *)w)->resourceId != inputResourceId || (((ShdPersonaModelWork *)w)->handle & ~0xFF) != (inputHandle & ~0xFF)) {
        p48 = ((ShdPersonaModelWork *)w)->stream;
        if (p48 != 0) {
            p4c = ((ShdPersonaModelWork *)w)->directory;
            chkmemAllocSiteTag(D_005E4868, 0x11B2);
            r = D_008873F4[0](1, 8, 0x40000);
            if (r != 0 && (s32)kwlnTaskCreate((const void *)(D_005E4E40), 0xF, 0, 0, shdPersonaDispCtlUpdate, shdPersonaDispCtlDestroy, (u8 *)(r)) != 0) {
                if (p4c != 0) {
                    func_00440b68((s32)D_005E4F10, (s32)(p4c + 0x10));
                }
                *(s32 *)r = p48;
                ((ShdPersonaStreamWork *)r)->directory = p4c;
            }
            MEMBER(s32, w, ShdPersonaModelWork, stream) = 0;
            MEMBER(s32, w, ShdPersonaModelWork, directory) = 0;
            ((ShdPersonaModelWork *)w)->loaded = 0;
        } else {
            p4c = ((ShdPersonaModelWork *)w)->directory;
            if (p4c != 0) {
                H_Cdvd_Destroy(p4c);
                MEMBER(s32, w, ShdPersonaModelWork, directory) = 0;
            }
            p4c = ((ShdPersonaModelWork *)w)->loaded;
            if (p4c != 0) {
                func_003ef3a0(p4c);
                MEMBER(s32, w, ShdPersonaModelWork, loaded) = 0;
            }
        }
        ((ShdPersonaModelWork *)w)->handle = inputHandle;
        MEMBER(s32, w, ShdPersonaModelWork, resourceId) = inputResourceId;
        ((ShdPersonaModelWork *)w)->state = 0;
    }
}
// Store a handle value in the display-control block.
// FUN_0011E230
void shdPersonaDispCtlSetHandle(u8 *task, s32 inputHandle)
{
    ((ShdPersonaModelWork *)((SdkTask *)task)->work)->handle = inputHandle;
}


// Sets the display-control target and start positions from the source position block.
// FUN_0011E240
void shdPersonaDispCtlSetPosition(u8 *task, u8 *position)
{
    u8 *b = ((SdkTask *)task)->work;
    f32 v0;
    f32 v1;
    if (position != NULL) {
        ((ShdPersonaModelWork *)b)->target.x = ((Vec2f *)position)->x;
        ((ShdPersonaModelWork *)b)->target.y = ((Vec2f *)position)->y;
    ((ShdPersonaModelWork *)b)->start.x = 640.0f + MEMBER(f32, b, ShdPersonaModelWork, target.x);
    ((ShdPersonaModelWork *)b)->start.y = ((ShdPersonaModelWork *)b)->target.y;
    }
    v0 = ((ShdPersonaModelWork *)b)->start.x;
    ((ShdPersonaModelWork *)b)->current.x = v0;
    ((ShdPersonaModelWork *)b)->committed.x = v0;
    v1 = ((ShdPersonaModelWork *)b)->start.y;
    ((ShdPersonaModelWork *)b)->current.y = v1;
    ((ShdPersonaModelWork *)b)->committed.y = v1;
    ((ShdPersonaModelWork *)b)->duration = 15.0f;
    ((ShdPersonaModelWork *)b)->frame = 0;
}


// Set the display-control start, current and target offsets from two two-float vectors.
// FUN_0011E2B0
void shdPersonaDispCtlSetOffsets(u8 *task, Vec2f *inputStart, Vec2f *inputTarget)
{
    u8 *b = ((SdkTask *)task)->work;
    if (inputStart == NULL) {
        kAssertFail(D_005E4868, 0x120A);
    }
    if (inputTarget == NULL) {
        kAssertFail(D_005E4868, 0x120B);
    }
    ((ShdPersonaModelWork *)b)->start = *inputStart;
    ((ShdPersonaModelWork *)b)->current = *inputStart;
    ((ShdPersonaModelWork *)b)->target = *inputTarget;
    ((ShdPersonaModelWork *)b)->frame = 0;
}


// FUN_0011E360
void shdPersonaDispCtlSetGaugeEnabled(u8 *task, s32 enabled)
{
    ((ShdPersonaModelWork *)((SdkTask *)task)->work)->drawGauge = enabled;
}


// Copy the current display-control position to the committed position.
// FUN_0011E370
void shdPersonaDispCtlCommitPosition(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    ((ShdPersonaModelWork *)b)->committed.x = ((ShdPersonaModelWork *)b)->current.x;
    ((ShdPersonaModelWork *)b)->committed.y = ((ShdPersonaModelWork *)b)->current.y;
}


/* Offset the model's draw position without changing its tween endpoints. */
// FUN_0011E390
void shdPersonaDispCtlSetDrawOffset(u8 *task, Vec2f offset)
{
    f32 *b = (f32 *)((SdkTask *)task)->work;
    b[0xE] = offset.x;
    b[0xF] = offset.y;
}


// Set the upper 24 bits of the display-control colour word, keeping the low byte from the handle.
// FUN_0011E3C0
void shdPersonaDispCtlSetColor(s32 taskHandle, s32 inputColor)
{
    u8 *b = ((SdkTask *)taskHandle)->work;
    ((ShdPersonaModelWork *)b)->color = (inputColor & 0xFFFFFF00) | *(u8 *)&((ShdPersonaModelWork *)b)->handle;
}


// Return whether the display-control task has finished loading (state 3).

// FUN_0011E3E0
u32 shdPersonaDispCtlIsLoaded(u8 *task)
{
    return ((ShdPersonaModelWork *)((SdkTask *)task)->work)->state == 3;
}


// Copy the current display-control position to the caller's buffer.
// FUN_0011E400
void shdPersonaDispCtlGetPosition(u8 *task, u8 *output)
{
    u8 *b = ((SdkTask *)task)->work;
    if (output == NULL) {
        kAssertFail(D_005E4868, 0x124F);
    }
    *(Vec2f *)output = ((ShdPersonaModelWork *)b)->current;
}


// Return the loaded value once the display control has reached state 3, else 0.
// FUN_0011E460
s32 shdPersonaDispCtlGetLoadedValue(u8 *task)
{
    u8 *b = ((SdkTask *)task)->work;
    if (*(s32 *)b != 3) {
        return 0;
    }
    return ((ShdPersonaModelWork *)b)->loaded;
}


u32 RpRandom(void);
u16 *datPersonaGetSkills(DatPersonaRecord *persona);
extern u16 *iGpffffb3ec;
/* measured: retail hoists loop-invariant values out of the pair-search loop, so this function needs
 * loop-invariant hoisting on. */
#pragma opt_loop_invariants on
/* measured: explicit goto joins reproduce retail's shared false tails, and separate pair values and
 * inner-loop counters keep retail's load order. Picks a random skill pair from the pair table and
 * writes its two ids into the caller's block. */
/* Choose a random entry from the skill pair table whose first skill the persona knows and whose
 * second it lacks, then store the pair as the level-up's previousSkill and replacement. Return 1 if
 * a pair was chosen and 0 otherwise. */
// FUN_0011E490
s32 shdPersonaPickRandomSkillPair(u8 *levelUp)
{
    u8 *q;
    u8 *r;
    u8 *p16;
    s32 stack[8];
    f32 f;
    s32 t;
    s32 i;
    s32 count;
    s32 found1;
    s32 found2;
    s32 j;
    s32 k;
    u16 *work;
    u16 first;
    u16 second;
    s32 idx;

    q = *(u8 **)&((ShdPersonaLevelUpWork *)levelUp)->parentTask;
    r = ((SdkTask *)q)->work;
    p16 = *(u8 **)r;
    if (!(*(u16 *)p16 & 4)) {
        return 0;
    }
    t = RpRandom() & 0x1000;
    f = (f32)(u32)t;
    f = 100.0f * f / 4096.0f;
    if (!(f < 0.0f)) {
        return 0;
    }
    work = (u16 *)datPersonaGetSkills((DatPersonaRecord *)p16);
    i = 0;
    count = 0;
    for (; (first = iGpffffb3ec[2 * i]) != 0; i++) {
        for (j = 0; j < 8; j++) {
            if (work[j] != 0 && first == work[j]) {
                found1 = 1;
                goto found1_done;
            }
        }
        found1 = 0;
    found1_done:
        if (found1 == 0) {
            continue;
        }
        second = iGpffffb3ec[2 * i + 1];
        for (k = 0; k < 8; k++) {
            if (work[k] != 0 && second == work[k]) {
                found2 = 1;
                goto found2_done;
            }
        }
        found2 = 0;
    found2_done:
        if (found2 != 0) {
            continue;
        }
        stack[count] = i;
        count++;
    }
    if (count > 0) {
        t = RpRandom() & 0xFFF;
        f = (f32)(u32)t;
        f = (f32)count * f / 4096.0f;
        idx = (s32)f;
        if (!(idx < count)) {
            kAssertFail(D_005E4868, 0x12CF);
        }
        i = stack[idx];
        ((ShdPersonaLevelUpWork *)levelUp)->previousSkill = iGpffffb3ec[2 * i];
        ((ShdPersonaLevelUpWork *)levelUp)->replacement = iGpffffb3ec[2 * i + 1];
        return 1;
    }
    return 0;
}

/* measured: restores the unit setting after shdPersonaPickRandomSkillPair. */
#pragma opt_loop_invariants off


// Advances the skill-list stage: shows the next unlocked skill name and level, otherwise moves to
// the next stage, picking a random skill pair if needed.
// FUN_0011E740
void shdPersonaAdvanceSkillList(u8 *levelUp)
{
    u8 *base;
    u8 buf[0x80];
    s32 idx;
    s32 t3;

    base = ((ShdPersonaLevelUpWork *)levelUp)->learnList;
    while ((idx = ((ShdPersonaLevelUpWork *)levelUp)->field0C) < 5 && *(u8 *)&((ShdPersonaLearnList *)base)->statGains[idx] == 0) {
        MEMBER(s32, levelUp, ShdPersonaLevelUpWork, field0C) += 1;
    }
    if (idx < 5) {
        strcpy(buf, D_005E4850[idx]);
        nmMesWindowSetCurrentString(0, buf);
        sprintf(buf, &iGpffff9c20, base[MEMBER(s32, levelUp, ShdPersonaLevelUpWork, field0C) + 0x82]);
        nmMesWindowSetCurrentString(1, buf);
        nmMesWindowShowCurrentRecord(((ShdPersonaLevelUpWork *)levelUp)->messages[2]);
        *(s16 *)&((ShdPersonaLevelUpWork *)levelUp)->cursor = 0;
        ((ShdPersonaLevelUpWork *)levelUp)->state = 3;
        return;
    }
    t3 = ((ShdPersonaLevelUpWork *)levelUp)->index;
    if (t3 < 0x20 && ((u16 *)(base + 2))[t3] != 0) {
        *(s16 *)&((ShdPersonaLevelUpWork *)levelUp)->cursor = 0;
        ((ShdPersonaLevelUpWork *)levelUp)->state = 4;
        return;
    }
    if (shdPersonaPickRandomSkillPair(levelUp) != 0) {
        nmMesWindowSetCurrentString(1, func_00243840(((ShdPersonaLevelUpWork *)levelUp)->previousSkill));
        nmMesWindowShowCurrentRecord(((ShdPersonaLevelUpWork *)levelUp)->messages[8]);
        nmMesWindowSetCurrentParam(((ShdPersonaLevelUpWork *)levelUp)->messages[0]);
        nmMesWindowSetCurrentFlag(1);
        nmMesWindowRequestRefresh();
        ((ShdPersonaLevelUpWork *)levelUp)->state = 8;
        return;
    }
    ((ShdPersonaLevelUpWork *)levelUp)->state = 0xC;
}


s32 datPersonaAddStat(u8 *, s32, s32);
s32 datPersonaCountSkills(DatPersonaRecord *);
s32 datBlockStageIsEight(u8 *);
u8 *shdPersonaSkillReplaceCreate(s32, u8 *, s32, u8 *);
u16 ShdSkill_GetPendingSkill(u8 *);
s16 ShdSkill_FindSlot(u8 *, s32);
extern u8 nmMesWindowOpenCurrent(u8 *message);
void nmMesWindowStepCurrent(s32);
s32 nmMesWindowResetCurrent(void);
s32 nmMesWindowCurrentOpenState(void);
u32 nmMesWindowCloseCurrent(s32);
s32 nmMesWindowCurrentAnimFlag(void);
u16 datPersonaRecordId(u32);
extern u16 D_008C024E[];
extern u16 D_008C024C[];
/* measured: level-up messages keep the parent task across skill lookups and reread its work before
 * changing the selection. */


/* Replace the persona skill and its active-skill entry when replacement succeeds. */
static inline s32 shdPersonaReplaceLevelSkill(SdkTask *parent, u16 previous, u16 replacement)
{
    u8 *data = parent->work;
    if (*(u8 **)data == NULL) {
        kAssertFail(D_005E4868, 0xE45);
    }
    if (datPersonaReplaceSkill(*(u8 **)data, (s16)previous, replacement) != -1) {
        ShdSkill_ReplaceActiveSkill(previous, replacement, data + 0x8C);
        return 1;
    }
    return 0;
}

// Advances the level-up skill-learn state machine one step and returns its status.
// FUN_0011E8E0
s32 shdPersonaLevelUpStep(u8 *task)
{
    u8 *e2;
    u8 *b2;
    u8 *pc;
    ShdPersonaLevelUpWork *work;
    DatPersonaRecord *first;
    u8 *base;
    s32 r;
    s32 i;
    s32 j;
    work = (ShdPersonaLevelUpWork *)((SdkTask *)task)->work;
    base = work->parentTask->work;
    first = *(DatPersonaRecord **)base;
    pc = work->learnList;
    switch (work->state) {
    case 0: {
        s32 v;
        v = ((PersonaRenderWork *)base)->flags | 0x200;
        ((PersonaRenderWork *)base)->flags = v;
        ((PersonaRenderWork *)base)->flags = v | 0x10000;
        ((PersonaRenderWork *)base)->revealFrame = 0;
        ((PersonaRenderWork *)base)->revealPulseFrame = 0;
        ((PersonaRenderWork *)base)->revealLabelFrame = 0;
        first->level = first->level + *(u8 *)pc;
        i = 0;
        while (i < 5) {
            datPersonaAddStat((u8 *)first, i & 0xFFFF, MEMBER(s8, pc + i, ShdPersonaLearnList, statGains[0]));
            i += 1;
        }
        r = shdPersonaCalcExpRemaining(first, 0);
        e2 = (u8 *)work->parentTask;
        b2 = ((SdkTask *)e2)->work;
        shdPersonaFillStatusForState(b2, *(u8 **)b2);
        shdPersonaCopyStatBytes(pc + 0x82, b2 + 0xC);
        *(s32 *)&((PersonaRenderWork *)MEMBER(u8 *, e2, SdkTask, work))->persona[0].nextExperience = r;
        work->state = 1;
    }
        /* fallthrough */
    case 1: {
        u8 *b;
        s32 fl;
        s32 isOld;
        b = work->parentTask->work;
        fl = ((PersonaRenderWork *)b)->flags;
        if ((fl & 0x10000) && (((PersonaRenderWork *)b)->revealFrame < 0x32)) {
            isOld = 0;
        } else {
            isOld = 1;
        }
        if ((isOld != 0) || (D_008C024E[0] & 0x50) || ((D_008C024C[0] & 0x10) && ((++work->frame > 4)))) {
            u16 id2;
            nmMesWindowOpenCurrent((u8 *)(work->parameter3));
            nmMesWindowSetCurrentString(0, datPersonaGetRow(datPersonaRecordId((u32)first)));
            id2 = *(s16 *)&((PersonaRenderWork *)work->parentTask->work)->persona[0].category;
            nmMesWindowSetCurrentString(1, (void *)datPersonaNamePart1(id2));
            nmMesWindowShowCurrentRecord(work->messages[1]);
            work->state = 2;
        }
        break;
    }
    case 2:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            shdPersonaAdvanceSkillList((u8 *)work);
        }
        break;
    case 3: {
        u16 c;
        c = work->cursor;
        if ((s32)c < 0xF) {
            u16 n;
            n = ++work->cursor;
            if ((n & 0xFFFF) == 0xF) {
                sdkSndStartStream(1, 3, 3, 1);
            }
        }
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            work->field0C = work->field0C + 1;
            shdPersonaAdvanceSkillList((u8 *)work);
        }
        break;
    }
    case 4: {
        u16 c;
        c = ++work->cursor;
        if ((c & 0xFFFF) < 0xA) {
            break;
        } else {
            u8 *b;
            SdkTask *parent;
            u16 vv;
            u32 selected;
            parent = work->parentTask;
            b = parent->work;
            if (((PersonaRenderWork *)b)->flags & 0x100000) {
                vv = ((PersonaRenderWork *)b)->acquisition.skill;
            } else {
                vv = ShdSkill_GetPendingSkill(b + 0x8C);
            }
            selected = vv & 0xFFFF;
            b = parent->work;
            if ((((PersonaRenderWork *)b)->flags & 0x8000) == 0) {
                s16 sv;
                MEMBER(s32, b, PersonaRenderWork, flags) = ((PersonaRenderWork *)b)->flags | 0x8000;
                *(u16 *)&((PersonaRenderWork *)b)->skillFrame = 0;
                ((PersonaRenderWork *)b)->selectedSkill = ShdSkill_FindSlot(b + 0x8C, selected);
                sv = MEMBER(s16, b, PersonaRenderWork, selectedSkill);
                if (sv < 0) {
                    kAssertFail(D_005E4868, 0xEB1);
                }
            }
            sdkSndStartStream(1, 3, 3, 2);
            work->state = 5;
            work->frame = 0;
        }
    }
        /* fallthrough */
    case 5: {
        u8 *b;
        s32 fl;
        s32 *flags;
        b = work->parentTask->work;
        flags = (s32 *)(b + 0x534);
        fl = *flags;
        if ((fl & 0x8000) == 0) {
            u16 vv;
            *flags = fl & 0xFFFF7FFF;
            b = work->parentTask->work;
            if (((PersonaRenderWork *)b)->flags & 0x100000) {
                vv = ((PersonaRenderWork *)b)->acquisition.skill;
            } else {
                vv = ShdSkill_GetPendingSkill(b + 0x8C);
            }
            if (vv != *((const u16 *)(pc + 2) + (work->index))) {
                kAssertFail(D_005E4868, 0x139A);
            }
            work->state = 6;
            nmMesWindowSetCurrentString(0, datPersonaGetRow(datPersonaRecordId((u32)first)));
            nmMesWindowSetCurrentString(1, func_00243840(vv));
            nmMesWindowShowCurrentRecord(work->messages[3]);
        } else {
            break;
        }
    }
        /* fallthrough */
    case 6: {
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            u8 *b;
            u16 vv;
            s32 idx;
            nmMesWindowCloseCurrent(1);
            b = work->parentTask->work;
            if (((PersonaRenderWork *)b)->flags & 0x100000) {
                vv = ((PersonaRenderWork *)b)->acquisition.skill;
            } else {
                vv = ShdSkill_GetPendingSkill(b + 0x8C);
            }
            switch (vv & 0xFFFF) {
            case 0x10C:
                idx = 0;
                break;
            case 0x112:
                idx = 1;
                break;
            case 0x113:
                idx = 2;
                break;
            case 0x10D:
                idx = 3;
                break;
            case 0x10E:
                idx = 4;
                break;
            case 0x114:
                idx = 5;
                break;
            case 0x10F:
                idx = 6;
                break;
            default:
                idx = -1;
                break;
            }
            if (idx >= 0) {
                nmMesWindowResetCurrent();
                if (work->parameter4 == 0) {
                    kAssertFail(D_005E4868, 0x13AD);
                }
                nmMesWindowOpenCurrent((u8 *)(work->parameter4));
                nmMesWindowShowCurrentRecord(idx);
                work->state = 0xF;
            } else if (datPersonaCountSkills(first) == 8) {
                work->state = 7;
                nmMesWindowResetCurrent();
                work->messageTask = shdPersonaSkillReplaceCreate(0, (u8 *)work->parentTask, work->parameter3, (u8 *)work->messages);
            } else {
                u16 vv2;
                u8 *bb;
                vv2 = *((const u16 *)(pc + 2) + (work->index));
                bb = work->parentTask->work;
                if (*(u8 **)bb == NULL) {
                    kAssertFail(D_005E4868, 0xE21);
                }
                if (datPersonaAddSkill(*(u8 **)bb, vv2) != 0) {
                    ShdSkill_AddActiveSkill(vv2, bb + 0x8C);
                }
                work->index = work->index + 1;
                shdPersonaAdvanceSkillList((u8 *)work);
            }
        }
        break;
    }
    case 7:
        if (datBlockStageIsEight(work->messageTask) != 0) {
            kwlnTaskDestroyHierarchyAlt((s32)work->messageTask);
            work->messageTask = NULL;
            work->index = work->index + 1;
            nmMesWindowOpenCurrent((u8 *)(work->parameter3));
            shdPersonaAdvanceSkillList((u8 *)work);
        }
        break;
    case 8:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            s32 t;
            nmMesWindowCloseCurrent(1);
            t = nmMesWindowCurrentAnimFlag();
            switch (t) {
            case 0:
                work->cursor = 0;
                work->state = 9;
                break;
            case 1:
                nmMesWindowSetCurrentString(0, datPersonaGetRow(datPersonaRecordId((u32)first)));
                nmMesWindowShowCurrentRecord(work->messages[9]);
                work->state = 0xB;
                break;
            }
        }
        break;
    case 9: {
        u16 c;
        c = ++work->cursor;
        if ((c & 0xFFFF) < 0xA) {
            break;
        } else {
            u32 highlightSkill;
            u8 *bb;
            shdPersonaReplaceLevelSkill(work->parentTask, work->previousSkill, work->replacement);
            highlightSkill = work->replacement;
            bb = work->parentTask->work;
            if ((((PersonaRenderWork *)bb)->flags & 0x8000) == 0) {
                s16 sv;
                MEMBER(s32, bb, PersonaRenderWork, flags) = ((PersonaRenderWork *)bb)->flags | 0x8000;
                *(u16 *)&((PersonaRenderWork *)bb)->skillFrame = 0;
                ((PersonaRenderWork *)bb)->selectedSkill = ShdSkill_FindSlot(bb + 0x8C, highlightSkill);
                sv = MEMBER(s16, bb, PersonaRenderWork, selectedSkill);
                if (sv < 0) {
                    kAssertFail(D_005E4868, 0xEB1);
                }
            }
            sdkSndStartStream(1, 3, 3, 3);
            work->state = 0xA;
            work->frame = 0;
        }
    }
        /* fallthrough */
    case 10: {
        u8 *b;
        s32 fl;
        s32 *flags;
        b = work->parentTask->work;
        flags = (s32 *)(b + 0x534);
        fl = *flags;
        if ((fl & 0x8000) == 0) {
            *flags = fl & 0xFFFF7FFF;
            nmMesWindowSetCurrentString(0, func_00243840(work->previousSkill));
            nmMesWindowSetCurrentString(1, func_00243840(work->replacement));
            nmMesWindowShowCurrentRecord(work->messages[10]);
            work->state = 0xB;
        } else {
            break;
        }
    }
        /* fallthrough */
    case 11:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            work->state = 0xC;
        }
        break;
    case 12:
        ((PersonaRenderWork *)base)->persona[0].unknown05[0] = 0;
        j = 0;
        while (j < 5) {
            MEMBER(u8, base + j, PersonaRenderWork, persona[0].added[0]) = 0;
            j += 1;
        }
        shdPersonaFillStatusForState(base, *(u8 **)base);
        datPersonaFillSkillRows(*(s32 *)base, base + 0x8C);
        nmMesWindowResetCurrent();
        work->cursor = 0;
        work->state = 0xD;
        /* fallthrough */
    case 13: {
        u16 c;
        c = ++work->cursor;
        if (((s32)(c & 0xFFFF) >= 0) || (D_008C024E[0] & 0x40) || ((D_008C024C[0] & 0x10) && ((s32)work->cursor >= 4))) {
            work->state = 0xE;
        }
        break;
    }
    case 0xE:
        break;
    case 15:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            u16 vv;
            u8 *bb;
            vv = *((const u16 *)(pc + 2) + (work->index));
            bb = work->parentTask->work;
            if (*(u8 **)bb == NULL) {
                kAssertFail(D_005E4868, 0xE21);
            }
            if (datPersonaAddSkill(*(u8 **)bb, vv) != 0) {
                ShdSkill_AddActiveSkill(vv, bb + 0x8C);
            }
            work->index = work->index + 1;
            nmMesWindowCloseCurrent(1);
            nmMesWindowResetCurrent();
            nmMesWindowOpenCurrent((u8 *)(work->parameter3));
            shdPersonaAdvanceSkillList((u8 *)work);
        }
        break;
    default:
        break;
    }
    return 0;
}


// Destroy a level-up task, releasing its pending message and freeing its work block.
// FUN_0011F3C0
void shdPersonaLevelUpDestroy(u8 *task)
{
    ShdPersonaLevelUpWork *b = (ShdPersonaLevelUpWork *)((SdkTask *)task)->work;
    if (b->messageTask != NULL) {
        kwlnTaskDestroyHierarchyAlt((s32)b->messageTask);
        b->messageTask = NULL;
    }
    jtbl_008873EC[0](b);
}


extern char D_005E4F30[];
s32 shdPersonaLevelUpStep(u8 *);
void shdPersonaLevelUpDestroy(u8 *);
// Create a level-up child task that copies its parameters and the skill table into its work block.

// FUN_0011F410
u8 *shdPersonaLevelUpCreate(s32 inputParentTask, s32 personaTask, u8 *inputLearnList, s32 messageResource, s32 extraMessage, s32 *messages)
{
    ShdPersonaLevelUpWork *levelUpWork;

    ShdPersonaLevelUpWork *w;
    u8 *r;
    s32 i;

    chkmemAllocSiteTag(D_005E4868, 0x1464);
    w = (ShdPersonaLevelUpWork *)D_008873F4[0](1, 0x58, 0x40000);
    if (w == NULL) {
        kAssertFail(D_005E4868, 0x1465);
    }
    r = (u8 *)kwlnTaskCreateChild((void *)(inputParentTask), (const void *)(D_005E4F30), 0xF, 0, 0, shdPersonaLevelUpStep, shdPersonaLevelUpDestroy, (u8 *)(w));
    if (r == NULL) {
        kAssertFail(D_005E4868, 0x146F);
    }
    w->parentTask = (struct SdkTask *)personaTask;
    w->learnList = inputLearnList;
    w->parameter3 = messageResource;
    w->parameter4 = extraMessage;
    for (i = 0; i < 0xB; i++) {
        (levelUpWork = w)->messages[i] = messages[i];
    }
    return r;
}


// Return whether the level-up task has reached its final state 0xE.
// FUN_0011F560
u32 shdPersonaLevelUpIsDone(u8 *task)
{
    return ((ShdPersonaLevelUpWork *)((SdkTask *)task)->work)->state == 0xE;
}


// FUN_0011F580
s32 shdPersonaDestroyTask(u8 *task)
{
    return kwlnTaskDestroyWithHierarchy((KwlnTask *)task);
}


u16 ShdSkill_GetPendingSkill(u8 *);
extern u8 nmMesWindowOpenCurrent(u8 *message);
void nmMesWindowStepCurrent(s32);
s32 nmMesWindowResetCurrent(void);
s32 nmMesWindowCurrentOpenState(void);
u32 nmMesWindowCloseCurrent(s32 release);
s32 nmMesWindowCurrentAnimFlag(void);
u16 shdPersonaGetSelectedSkillId(u8 *panel);
void ShdSkill_PopPoolEntry(u8 *pool);
u16 datPersonaRecordId(u32 recordAddress);
s16 ShdSkill_FindSlot(u8 *, s32);
extern u16 D_008C024E[];
extern u16 D_008C024C[];
void shdPersonaBeginSelection(u8 *task);
/* Advances the skill-replace state machine one step and returns its status. The replacement and
 * highlight states share pendingSkill, which each state assigns before reading. */
// FUN_0011F5A0
s32 shdPersonaSkillReplaceStep(u8 *task)
{
    u16 pendingSkill;
    ShdPersonaSkillReplaceWork *work = (ShdPersonaSkillReplaceWork *)((SdkTask *)task)->work;
    u8 *base = ((SdkTask *)work->parent)->work;
    u8 *first = *(u8 **)&((PersonaRenderWork *)base)->controllerAddress;
    u32 st = work->state;
    switch (st) {
    case 0: {
        u16 a;
        if (((PersonaRenderWork *)base)->flags & 0x100000) {
            a = ((PersonaRenderWork *)base)->acquisition.skill;
        } else {
            a = ShdSkill_GetPendingSkill(base + 0x8C);
        }
        work->original = a;
        nmMesWindowOpenCurrent((u8 *)(work->messageHandle));
        nmMesWindowShowCurrentRecord(work->messages[4]);
        work->state = 1;
    }
        /* fallthrough */
    case 1:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            work->state = 2;
            shdPersonaBeginSelection(work->parent);
        }
        break;
    case 2: {
        s32 fl = ((PersonaRenderWork *)base)->flags;
        s32 b800 = !!(fl & 0x800);
        if (b800 != 0) {
            if (((ShdSkillState *)((PersonaRenderWork *)base)->skills)->cursor != -1) {
                if (ShdSkill_MoveCursor(base + 0x84, (fl & 0x100000) != 0) != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
            }
        }
        if (D_008C024E[0] & 0x40) {
            u8 *q = ((SdkTask *)work->parent)->work;
            s32 fq = ((PersonaRenderWork *)q)->flags;
            u16 vv;
            if (fq & 0x2000) {
                vv = 0;
            } else if (((fq & 0x100000) != 0) && (((ShdSkillState *)((PersonaRenderWork *)q)->skills)->cursor == 8)) {
                vv = ((PersonaRenderWork *)q)->acquisition.skill;
            } else {
                vv = ShdSkill_GetSlotSkillId(q + 0x84) & 0xFFFF;
            }
            work->replacement = vv;
            work->state = 3;
            nmMesWindowSetCurrentString(0, func_00243840(work->replacement));
            nmMesWindowShowCurrentRecord(work->messages[5]);
            nmMesWindowSetCurrentParam(work->messages[0]);
            nmMesWindowSetCurrentFlag(1);
            nmMesWindowRequestRefresh();
            sdkSndStartStream(0, 1, 0, 1);
        }
        break;
    }
    case 3:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            s32 choice;
            nmMesWindowCloseCurrent(1);
            choice = nmMesWindowCurrentAnimFlag();
            switch (choice) {
                case 0: {
                    u8 *pp = work->parent;
                    u8 *bb = ((SdkTask *)pp)->work;
                    u8 *current;
                    u16 queuedSkill;
                    u16 previousSkill = shdPersonaGetSelectedSkillId(bb) & 0xFFFF;
                    s32 ok;
                    s32 ok2;
                    if (((PersonaRenderWork *)bb)->flags & 0x100000) {
                        queuedSkill = ((PersonaRenderWork *)bb)->acquisition.skill;
                    } else {
                        queuedSkill = ShdSkill_GetPendingSkill(bb + 0x8C);
                    }
                    pendingSkill = queuedSkill & 0xFFFF;
                    current = MEMBER(u8 *, pp, SdkTask, work);
                    if (*(u8 **)current == NULL) {
                        kAssertFail(D_005E4868, 0xE45);
                    }
                    if (datPersonaReplaceSkill(*(u8 **)current, (s16)previousSkill, pendingSkill) != -1) {
                        ShdSkill_ReplaceActiveSkill(previousSkill, pendingSkill, current + 0x8C);
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    if (ok != 0) {
                        ok2 = 1;
                    } else {
                        if ((MEMBER(s32, bb, PersonaRenderWork, flags) & 0x100000) == 0) {
                            ShdSkill_PopPoolEntry(bb + 0x8C);
                        }
                        ok2 = 0;
                    }
                    if (ok2 != 0) {
                        work->counter = 0;
                        work->state = 4;
                    } else {
                        u8 *qb2;
                        work->state = 6;
                        qb2 = first;
                        qb2 = datPersonaGetRow(datPersonaRecordId((u32)qb2));
                        nmMesWindowSetCurrentString(0, qb2);
                        nmMesWindowSetCurrentString(1, func_00243840(work->original));
                        nmMesWindowShowCurrentRecord(work->messages[6]);
                    }
                    {
                    u8 *qb = ((SdkTask *)work->parent)->work;
                    s32 fq2 = ((PersonaRenderWork *)qb)->flags;
                    if (fq2 & 0x20) {
                        if (fq2 & 0x800) {
                            if ((fq2 & 0x2000) == 0) {
                                s32 nv;
                                ((PersonaRenderWork *)qb)->selectionStart.x = ((PersonaRenderWork *)qb)->selectionPosition.x;
                                ((PersonaRenderWork *)qb)->selectionStart.y = ((PersonaRenderWork *)qb)->selectionPosition.y;
                                *(s32 *)&((PersonaRenderWork *)qb)->selectionTarget.x = 0xC3E10000;
                                *(u16 *)&((PersonaRenderWork *)qb)->selectionFrame = 0;
                                nv = MEMBER(s32, qb, PersonaRenderWork, flags) | 0x2000;
                                MEMBER(s32, qb, PersonaRenderWork, flags) = nv;
                                MEMBER(s32, qb, PersonaRenderWork, flags) = nv & ~0x1000;
                            }
                        }
                    }
                    }
                    break;
                }
                case 1:
                    work->state = 2;
                    break;
                default:
                    break;
            }
        }
        break;
    case 4: {
        if (++work->counter < 0xA) {
            break;
        } else {
            s32 selected;
            u8 *q;
            s32 fq;
            pendingSkill = work->original;
            selected = pendingSkill;
            q = ((SdkTask *)work->parent)->work;
            fq = ((PersonaRenderWork *)q)->flags;
            if ((fq & 0x8000) == 0) {
                s16 sv;
                MEMBER(s32, q, PersonaRenderWork, flags) = fq | 0x8000;
                *(u16 *)&((PersonaRenderWork *)q)->skillFrame = 0;
                ((PersonaRenderWork *)q)->selectedSkill = ShdSkill_FindSlot(q + 0x8C, selected);
                sv = MEMBER(s16, q, PersonaRenderWork, selectedSkill);
                if (sv < 0) {
                    kAssertFail(D_005E4868, 0xEB1);
                }
            }
            sdkSndStartStream(1, 3, 3, 2);
            work->state = 5;
            work->field02 = 0;
        }
    }
        /* fallthrough */
    case 5: {
        u8 *q = ((SdkTask *)work->parent)->work;
        s32 *flags = (s32 *)(q + 0x534);
        s32 fq = *flags;
        if ((fq & 0x8000) == 0) {
            *flags = fq & ~0x8000;
            work->state = 6;
            nmMesWindowSetCurrentString(0, func_00243840(work->replacement));
            nmMesWindowSetCurrentString(1, func_00243840(work->original));
            nmMesWindowShowCurrentRecord(work->messages[7]);
        /* fallthrough */
    case 6:
            nmMesWindowStepCurrent(1);
            if (nmMesWindowCurrentOpenState() == 0) {
                nmMesWindowCloseCurrent(1);
                work->state = 7;
            }
        }
        break;
    }
    case 7:
        nmMesWindowResetCurrent();
        work->state = 8;
        break;
    case 8:
        break;
    }
    return 0;
}


// Destroy a skill-replace task through its registered destroy callback.
// FUN_0011FB90
void shdPersonaSkillReplaceDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}


// Create a skill-replace child task that copies its parameters and a 0xB-word table into its work
// block.

// FUN_0011FBC0
u8 *shdPersonaSkillReplaceCreate(s32 parentTask, u8 *personaTask, s32 messageResource, u8 *messages)
{
    ShdPersonaSkillReplaceWork *replacementWork;

    ShdPersonaSkillReplaceWork *w;
    u8 *r;
    s32 i;

    chkmemAllocSiteTag(D_005E4868, 0x1551);
    w = (ShdPersonaSkillReplaceWork *)D_008873F4[0](1, 0x44, 0x40000);
    if (w == NULL) {
        kAssertFail(D_005E4868, 0x1552);
    }
    r = (u8 *)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005E4F50), 0xF, 0, 0, shdPersonaSkillReplaceStep, shdPersonaSkillReplaceDestroy, (u8 *)(w));
    if (r == NULL) {
        kAssertFail(D_005E4868, 0x155C);
    }
    w->parent = personaTask;
    w->messageHandle = messageResource;
    for (i = 0; i < 0xB; i++) {
        (replacementWork = w)->messages[i] = ((s32 *)messages)[i];
    }
    return r;
}

#include "operand_order_internal.h"
/* Original translation unit cmpSkill.c (from __FILE__ assert strings). */
#include "type.h"
#include "include_asm.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"

/* measured: retail hoists loop invariants out of the skill-menu callback loops across this unit,
 * except for the decoration function below. */
#pragma opt_loop_invariants on

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

/* The label dispatcher sets these three halfwords; the renderer reads the 12-byte payload as an ID
 * and two value words, copied without numeric conversion. */
typedef struct {
    s16 kind;
    s16 style;
    s16 flags;
    Vec3f payload;
} CmpSkillDescriptor;

typedef struct {
    u8 red, green, blue, alpha;
} CmpSkillColor;

typedef struct {
    f32 x, y;
    f32 width, height;
    s32 paletteIndex;
} CmpSkillDecoration;

void datPersonaSetLeadSlot(s16);
s32 datPersonaFillSkillCostRow(s32, struct DatPersonaRecord *, s32, void *);
void datCalcSkillOutcomeById(s32, s32, u16, s32, s32 *, s32, s32);
void radarAnimateValue(void *, s32, s32);
void sdkSpriteFreeNode(void *);
s32 nLineIsIdle(void);
u32 RpRandom(void);
s32 datCalcSkillElement(u8 *, u16);
void sdkRenderStateSetDefault(void);
void nLineDrawSet(Vec2f, s32, s32, f32);
void sdkSpriteDrawSized(u8 *, f32, f32, f32,
                   u8, u8, u8, u8,
                   u16, u16, s16, f32, s16);
void sdkSpriteDrawAt(void *, f32, f32, u8, u8, u8, u8);
void sdkSpriteDrawFooter(Vec2f unused, f32, u8, s32, s32);
void radarDrawSecondSpritePair(u8 *work, Vec2f position, PackedColor4 color);
void radarDrawSkillCard(void *, Vec2f, s32, void *);
void datRecordClearHeader(s16 *);
void datEntryDrawByKind(Vec2f, u8, void *, s32, f32);
void radarDrawEntryRowGroup(u8 *, s32, s32);
/* Two RGBA decoration colors; retail copies exactly eight bytes. */
extern u8 D_00762DC0[8];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
void *resourceFindByName(char *);
s32 sdkSpriteNewNode(void *, u8);
s16 datBuildPartyIdList(void *);
void kAssertFail(char *, s32);
void memset(void *, s32, s32);
s32 cmpSkillSetSelection(s16 *, s32, s32);
void cmpSkillStepDecorations(void *);
void cmpSkillStepScrollRows(void *);
void cmpSkillMenuDraw(u8 *);
s32 cmpSkillSetMode(u8 *, s32);
void cmpSkillBuildAbilityList(void *);
extern char D_005ED9C0[];
extern char D_005E57F0[];
extern char D_005E5830[];
extern char D_005E5850[];
extern u8 D_005ED750[];
extern u8 D_005EB5D0[];
extern u8 D_005EBA00[];
extern u8 D_005EBE30[];
extern u8 D_005EC260[];
extern u8 D_005EC690[];
extern u8 D_005ECAC0[];
extern u8 D_005ECEF0[];
extern u8 D_005ED320[];
extern u8 D_005ED790[];
extern f32 DAT_00761640;

/* Ability-list record in the work area: id, sort key and two payload words; the float members make
 * the copy go through FPU registers like retail. */
typedef struct CmpSkillRecord
{
    s16 id;
    u16 key;
    f32 a;
    f32 b;
} CmpSkillRecord;
/* One 0x30-byte entry in the menu's animation arrays. The initializer,
   transition setup and updater jointly establish these fields. */
typedef struct {
    f32 sourceX, sourceY, targetX, targetY;
    f32 x, y;
    u8 sourceAlpha, targetAlpha, alpha, flags;
    u16 sourceScaleX, targetScaleX, scaleX;
    u16 sourceScaleY, targetScaleY, scaleY;
    s32 mode, duration;
} CmpSkillAnimation;

typedef struct {
    u8 alpha;
    u8 pad01[3];
    f32 x, y;
    s32 unk0C;
    s32 background;
    s32 phase, mode;
    u32 visible;
    s16 frame, scrollFrame;
    s16 decorationFrames[28];
    s16 selectedParty;
    s16 selectedRow;
    s16 scrollRow;
    s16 selectedRecipient;
    u8 pad64[0x44];
    s16 previousSelection[4];
    u8 padB0[0x44];
    s16 partyIds[4];
    s16 partyCount;
    s16 unkFE;
    union { CmpSkillRecord fields; Vec3f copy; } skills[96];
    s16 skillCount;
    s16 footerMode;
    CmpSkillAnimation animation[68];
    void *sprites[60];
    union { void *texture; s32 handle; } footer;
} CmpSkillWork;
typedef char CmpSkillWorkSize[sizeof(CmpSkillWork) == 0x1338 ? 1 : -1];

/* Mode tables contain 38 records of 0x1C bytes. */
typedef struct {
    f32 x, y, width, height;
    u8 alpha;
    u8 pad11[3];
    s32 startFrame, endFrame;
} CmpSkillLayoutRow;

/* measured: the signed 16-bit bitfield keeps retail's sign-extending narrowing, and the s32 loop
 * counters keep its saved-register allocation. */
// FUN_00137FB0
/* measured: opt_loop_invariants on hoists the table and conversion constants like retail. */
void cmpSkillMenuInit(u8 *work)
{
    s16 selectionIndex;
    s16 motionIndex;
    s16 decorationIndex;
    s32 tabIndex;
    s32 narrowTabIndex;
    u8 *src;
    u8 *dst;
    u8 spriteId;
    f32 value;
    void *asset0;
    void *asset1;
    void *asset2;
    s32 *slot;
    s32 spriteIndex;
    struct {
        s32 half : 16;
    } narrow;

    memset(work, 0, 0x1338);
    *(s32 *)&((CmpSkillWork *)work)->x = 0;
    *(s32 *)&((CmpSkillWork *)work)->y = 0;
    *work = 0xFF;
    ((CmpSkillWork *)work)->mode = -1;

    for (selectionIndex = 0; selectionIndex < 4; selectionIndex++) {
        ((CmpSkillWork *)(work + selectionIndex * 2))->selectedParty = 0;
    }

    for (motionIndex = 0; motionIndex < 0x26; motionIndex++) {
        src = D_005EBA00 + motionIndex * 0x1C;
        dst = work + motionIndex * 0x30;
        ((CmpSkillWork *)dst)->animation[0].x = ((CmpSkillLayoutRow *)src)->x;
        ((CmpSkillWork *)dst)->animation[0].y = ((CmpSkillLayoutRow *)src)->y;
        ((CmpSkillWork *)dst)->animation[0].alpha = ((CmpSkillLayoutRow *)src)->alpha;
        value = ((CmpSkillLayoutRow *)src)->width;
        ((CmpSkillWork *)dst)->animation[0].scaleX = (u16)value;
        value = ((CmpSkillLayoutRow *)src)->height;
        ((CmpSkillWork *)dst)->animation[0].scaleY = (u16)value;
    }

    for (decorationIndex = 0; decorationIndex < 0x1C; decorationIndex++) {
        dst = work + decorationIndex * 0x30;
        *(s32 *)&((CmpSkillWork *)dst)->animation[38].x = 0;
        *(s32 *)&((CmpSkillWork *)dst)->animation[38].y = 0;
        ((CmpSkillWork *)dst)->animation[38].alpha = 0;
        ((CmpSkillWork *)dst)->animation[38].mode = 0;
        ((CmpSkillWork *)dst)->animation[38].duration = 8;
        if (decorationIndex % 0xE < 6) {
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].sourceScaleX = 0x64;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].targetScaleX = 0x64;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].sourceScaleY = 0x64;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].targetScaleY = 0x64;
            ((CmpSkillWork *)dst)->animation[38].sourceAlpha = 0;
            ((CmpSkillWork *)dst)->animation[38].targetAlpha = 0xFF;
        } else {
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].sourceScaleX = 0x64;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].targetScaleX = 0xB4;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].sourceScaleY = 0x64;
            *(s16 *)&((CmpSkillWork *)dst)->animation[38].targetScaleY = 0xB4;
            ((CmpSkillWork *)dst)->animation[38].sourceAlpha = 0;
            ((CmpSkillWork *)dst)->animation[38].targetAlpha = 0x7F;
        }
        ((CmpSkillWork *)(work + decorationIndex * 2))->decorationFrames[0] = (decorationIndex * 3) % 8;
    }

    tabIndex = 0;
    goto loop4_test;
loop4_body:
    narrow.half = tabIndex;
    narrowTabIndex = narrow.half;
    dst = work + narrowTabIndex * 0x30;
    *(s32 *)&((CmpSkillWork *)dst)->animation[66].x = 0;
    *(s32 *)&((CmpSkillWork *)dst)->animation[66].sourceX = 0;
    *(s32 *)&((CmpSkillWork *)dst)->animation[66].targetY = 0;
    *(s32 *)&((CmpSkillWork *)dst)->animation[66].sourceY = 0;
    ((CmpSkillWork *)dst)->animation[66].targetAlpha = 0;
    ((CmpSkillWork *)dst)->animation[66].sourceAlpha = 0;
    ((CmpSkillWork *)dst)->animation[66].mode = 0;
    ((CmpSkillWork *)dst)->animation[66].duration = 3;
    tabIndex = (s16)(tabIndex + 1);
loop4_test:
    if ((s16)tabIndex < 2) {
        goto loop4_body;
    }

    ((CmpSkillWork *)work)->partyCount = datBuildPartyIdList(work + 0xF4);
    ((CmpSkillWork *)work)->skillCount = 0;

    asset0 = resourceFindByName(D_005E5830);
    if (asset0 == 0) {
        kAssertFail(D_005ED9C0, 0x25F);
    }
    asset1 = resourceFindByName(D_005E5850);
    if (asset1 == 0) {
        kAssertFail(D_005ED9C0, 0x261);
    }
    ((CmpSkillWork *)work)->footer.texture = asset2 = resourceFindByName(D_005E57F0);
    if (asset2 == 0) {
        kAssertFail(D_005ED9C0, 0x263);
    }

    spriteIndex = 0;
    goto resolve_test;
resolve_body:
    if (narrow.half < 0x1B) {
        narrow.half = spriteIndex;
        slot = (s32 *)&((CmpSkillWork *)work)->sprites[narrow.half];
        spriteId = D_005ED750[narrow.half];
        *slot = sdkSpriteNewNode(asset0, spriteId);
    } else if (narrow.half < 0x3A) {
        narrow.half = spriteIndex;
        slot = (s32 *)&((CmpSkillWork *)work)->sprites[narrow.half];
        spriteId = D_005ED750[narrow.half];
        *slot = sdkSpriteNewNode(asset1, spriteId);
    } else {
        narrow.half = spriteIndex;
        slot = (s32 *)&((CmpSkillWork *)work)->sprites[narrow.half];
        spriteId = D_005ED750[narrow.half];
        *slot = sdkSpriteNewNode(asset2, spriteId);
    }
    if (*slot == 0) {
        kAssertFail(D_005ED9C0, 0x270);
    }
    narrow.half = spriteIndex + 1;
    spriteIndex = narrow.half;
resolve_test:
    narrow.half = spriteIndex;
    if (narrow.half < 0x3C) {
        goto resolve_body;
    }

    cmpSkillSetMode(work, 0);
    cmpSkillBuildAbilityList(work);
}

/* Test whether any of the eight learned skill slots contains the requested skill; inlined because
 * retail has two copies of this search. */
static inline s32 cmpSkillListContains(u16 *skills, u16 skill)
{
    s32 k;

    for (k = 0; k < 8; k++) {
        if (skills[k] == skill) {
            return 1;
        }
    }
    return 0;
}
/* Collect usable skills, keep the strongest duplicate source, sort by skill ID, and restore the
 * lead persona. */
// FUN_00138490
void cmpSkillBuildAbilityList(void *work)
{
    CmpSkillWork *menu = (CmpSkillWork *)work;
    s16 savedLeadSlot;
    s32 duplicateOuterIndex;
    CmpSkillRecord *candidateRecord;
    u8 *workBytes = (u8 *)work;
    s32 memberId;
    s32 skillCount;
    s32 duplicateInnerIndex;
    s32 sortOuterIndex;
    s32 sortInnerIndex;
    s32 personaAddress;
    s32 queryIndex;
    u8 *outerEntry;
    s32 skillSlot;
    u8 *candidateEntry;
    u8 *lastEntry;
    s32 candidateSkill;
    s32 currentSkill;
    u16 *candidateSkillPtr;
    s32 hasPassive;
    s32 firstOutcome;
    s32 secondOutcome;
    CmpSkillRecord innerTmp;
    CmpSkillRecord outerTmp;

    savedLeadSlot = -1;
    skillCount = 0;
    memberId = menu->selectedParty;
    {
        s32 off = memberId * 2;
        memberId = ((CmpSkillWork *)((u8 *)(off + (s32)work)))->partyIds[0];
    }
    if (memberId == 1) {
        savedLeadSlot = datPersonaGetLeadSlot();
        for (queryIndex = 0; queryIndex < datPersonaCountValidMembers(); queryIndex++) {
            personaAddress = (s32)datPersonaRosterSlot((s16)queryIndex);
            if (personaAddress != 0) {
                datPersonaSetLeadSlot((s16)queryIndex);
                for (skillSlot = 0; skillSlot < 8; skillSlot++) {
                    outerEntry = workBytes + skillCount * 12;
                    if (datPersonaFillSkillCostRow(1, (struct DatPersonaRecord *)personaAddress, skillSlot, outerEntry + 0x100) != 0) {
                        ((CmpSkillWork *)outerEntry)->skills[0].fields.id = (s16)queryIndex;
                        skillCount++;
                    }
                }
            }
        }
    } else {
        personaAddress = (s32)datPersonaGetRecord((u16)memberId);
        for (queryIndex = 0; queryIndex < 8; queryIndex++) {
            outerEntry = workBytes + skillCount * 12;
            if (datPersonaFillSkillCostRow(memberId, (struct DatPersonaRecord *)personaAddress, queryIndex, outerEntry + 0x100) != 0) {
                ((CmpSkillWork *)outerEntry)->skills[0].fields.id = -1;
                skillCount++;
            }
        }
    }
    for (duplicateOuterIndex = 0; duplicateOuterIndex < skillCount; duplicateOuterIndex++) {
        outerEntry = workBytes + duplicateOuterIndex * 12;
        currentSkill = ((CmpSkillWork *)outerEntry)->skills[0].fields.key;
        for (duplicateInnerIndex = duplicateOuterIndex + 1; duplicateInnerIndex < skillCount; duplicateInnerIndex++) {
            candidateEntry = workBytes + duplicateInnerIndex * 12;
            candidateSkillPtr = (u16 *)(candidateEntry + 0x102);
            candidateSkill = *candidateSkillPtr;
            if (currentSkill == candidateSkill) {
                if (currentSkill < 0x1B8 && savedLeadSlot != -1) {
                    hasPassive = cmpSkillListContains(datPersonaGetSkills(datPersonaRosterSlot(((CmpSkillWork *)outerEntry)->skills[0].fields.id)), 0x20A);
                    if (hasPassive == 0) {
                        candidateRecord = (CmpSkillRecord *)(candidateEntry + 0x100);
                        hasPassive = cmpSkillListContains(datPersonaGetSkills(datPersonaRosterSlot(((CmpSkillWork *)candidateEntry)->skills[0].fields.id)), 0x20A);
                        if (hasPassive != 0) {
                            ((CmpSkillRecord *)(outerEntry + 0x100))[0] = *candidateRecord;
                        } else {
                            datPersonaSetLeadSlot(((CmpSkillRecord *)(outerEntry + 0x100))->id);
                            datCalcSkillOutcomeById(memberId, memberId, menu->skills[duplicateOuterIndex].fields.key, 0, &firstOutcome, 0, 0);
                            datPersonaSetLeadSlot(candidateRecord->id);
                            datCalcSkillOutcomeById(memberId, memberId, *candidateSkillPtr, 0, &secondOutcome, 0, 0);
                            if (firstOutcome < secondOutcome) {
                                ((CmpSkillRecord *)(outerEntry + 0x100))[0] = *candidateRecord;
                            }
                        }
                    }
                }
                skillCount--;
                lastEntry = workBytes + skillCount * 12;
                ((CmpSkillWork *)candidateEntry)->skills[0].fields = ((CmpSkillWork *)lastEntry)->skills[0].fields;
                duplicateInnerIndex--;
                *(s32 *)&((CmpSkillWork *)lastEntry)->skills[0].fields.a = 0;
                *(s32 *)&((CmpSkillWork *)lastEntry)->skills[0].fields.b = 0;
                ((CmpSkillWork *)lastEntry)->skills[0].fields.key = 0;
                ((CmpSkillWork *)lastEntry)->skills[0].fields.id = -1;
            }
        }
    }
    menu->skillCount = (s16)skillCount;
    for (sortOuterIndex = 0; sortOuterIndex < skillCount; sortOuterIndex++) {
        u8 *outer;
        outer = workBytes + sortOuterIndex * 12;
        outerTmp = ((CmpSkillWork *)outer)->skills[0].fields;
        for (sortInnerIndex = sortOuterIndex + 1; sortInnerIndex < skillCount; sortInnerIndex++) {
            u8 *inner;
            CmpSkillRecord *ip;

            inner = workBytes + sortInnerIndex * 12;
            ip = (CmpSkillRecord *)(inner + 0x100);
            innerTmp = ((CmpSkillWork *)inner)->skills[0].fields;
            if (innerTmp.key >= 0xC0 && innerTmp.key < 0x100) {
                if (outerTmp.key >= 0xC0 && outerTmp.key < 0x100) {
                    if (innerTmp.key < outerTmp.key) {
                        ((CmpSkillRecord *)(outer + 0x100))[0] = innerTmp;
                        *ip = outerTmp;
                        outerTmp = innerTmp;
                    }
                } else {
                    ((CmpSkillRecord *)(outer + 0x100))[0] = innerTmp;
                    *ip = outerTmp;
                    outerTmp = innerTmp;
                }
            } else if (outerTmp.key < 0xC0 || outerTmp.key > 0xFF) {
                if (innerTmp.key < outerTmp.key) {
                    ((CmpSkillRecord *)(outer + 0x100))[0] = innerTmp;
                    *ip = outerTmp;
                    outerTmp = innerTmp;
                }
            }
        }
    }
    if (savedLeadSlot != -1) {
        datPersonaSetLeadSlot(savedLeadSlot);
    }
    if (menu->skillCount > 0x60) {
        kAssertFail(D_005ED9C0, 0x336);
    }
    cmpSkillSetSelection((s16 *)work, 1, 0);
    cmpSkillSetSelection((s16 *)work, 2, 0);
}

// Advances the menu state from 0 to 1; returns 1 for states 0 and 1, 0 otherwise.
// FUN_00138AD0
s32 cmpSkillStateStep(u8 *work) {
    CmpSkillWork *menu = (CmpSkillWork *)work;
    s32 phase = menu->phase;

    switch (phase) {
    case 0:
        phase += 1;
        menu->phase = phase;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

/* Advance menu transitions, decorations and scroll rows, draw the menu, and report transparency. */
// FUN_00138B20
/* Raw work-relative accesses keep retail's load/store scheduling, which a typed CmpSkillWork
 * rewrite changes. */
s32 cmpSkillMenuUpdate(u8 *work)
{
    CmpSkillWork *menu = (CmpSkillWork *)work;
    s32 i;
    s32 result = 1;
    u8 *rowBase;
    s32 frame;

    frame = menu->frame;
    if (frame < 0x64) {
        menu->frame = frame + 1;
    }
    for (i = 0; i < 0x26; i++) {
        rowBase = work + i * 0x30;
        frame = menu->frame;
        radarAnimateValue(rowBase + 0x584, frame, 0);
        if (((CmpSkillWork *)(rowBase))->animation[0].alpha != 0) {
            result = 0;
        }
    }
    cmpSkillStepDecorations(work);
    cmpSkillStepScrollRows(work);
    cmpSkillMenuDraw(work);
    return result;
}
/* Preserve the observed left/right evaluation order of the three sums. */


/* Draw the skill menu, including animated decorations, selection rows, scrolling controls and the
 * pending skill overlay. The shared position, packed color and descriptor are retail's stack
 * objects. */
// FUN_00138BF0
#pragma push
/* measured: retail keeps per-draw float constants and sprite snapshots taken before coordinate
 * math, which needs all three settings below. */
#pragma opt_lifetimes on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
void cmpSkillMenuDraw(u8 *work)
{
    extern s32 cmpSkillElementLabelId(u16 skillId);
    CmpSkillWork *menu;
    s32 rowIndex;
    f32 opacity;
    f32 originX;
    f32 originY;
    u8 spriteAlpha;
    f32 value;
    f32 offset;
    PackedColor4 color;
    Vec2f position;
    CmpSkillColor palette[2];
    CmpSkillDescriptor descriptor;
    CmpSkillColor *decorationColor;
    s32 payloadIndex;

    menu = (CmpSkillWork *)work;
    sdkRenderStateSetDefault();
    originX = menu->x;
    originY = menu->y;
    opacity = (f32)menu->alpha / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        value = 255.0f * opacity;
        spriteAlpha = (u8)value;
        nLineDrawSet(position, spriteAlpha, menu->background, 0.0f);
    }
    if ((menu->visible & 0x1000) != 0) {
        s8 *paletteSource;
        s8 *paletteBytes;
        s32 pairsRemaining;
        u8 *decorationSprite;
        paletteSource = (s8 *)D_00762DC0;
        paletteBytes = (s8 *)palette;
        pairsRemaining = 4;
        do {
            s8 b0;
            s8 b1;
            b0 = paletteSource[0];
            b1 = paletteSource[1];
            paletteSource += 2;
            pairsRemaining--;
            paletteBytes[0] = b0;
            paletteBytes[1] = b1;
            paletteBytes += 2;
        } while (pairsRemaining > 0);
        decorationSprite = menu->sprites[42];
        /* Twenty decorations are drawn from the 28-entry animation group, using a work-relative row
         * base with 0x30-byte entries. */
        for (rowIndex = 0; rowIndex < 0x14; rowIndex++) {
            u8 *animation;
            CmpSkillDecoration *layout;
            layout = (CmpSkillDecoration *)D_005ED790 + rowIndex;
            animation = work + rowIndex * 0x30;
            offset = originX + ((CmpSkillWork *)animation)->animation[38].x;
            position.x = offset + layout->x;
            offset = originY + ((CmpSkillWork *)animation)->animation[38].y;
            position.y = offset + layout->y;
            value = (f32)((CmpSkillWork *)animation)->animation[38].alpha;
            value = value * opacity;
            spriteAlpha = (u8)value;
            decorationColor = &palette[layout->paletteIndex];
            sdkSpriteDrawSized(decorationSprite, position.x, position.y, 0.0f,
                          decorationColor->red, decorationColor->green, decorationColor->blue, spriteAlpha,
                          (u16)(1.0f + ((f32)((CmpSkillWork *)animation)->animation[38].scaleX * layout->width) / 100.0f),
                          (u16)(((f32)((CmpSkillWork *)animation)->animation[38].scaleY * layout->height) / 100.0f),
                          0, 0.0f, 0);
        }
    }
    if ((menu->visible & 1) != 0) {
        position.x = 16.0f + (originX + menu->animation[0].x);
        position.y = 368.0f + (originY + menu->animation[0].y);
        value = (f32)menu->animation[0].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        sdkSpriteDrawAt(menu->sprites[58], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x200) != 0) {
        position.x = 14.0f + (originX + menu->animation[33].x);
        position.y = 405.0f + (originY + menu->animation[33].y);
        value = (f32)menu->animation[33].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        sdkSpriteDrawAt(menu->sprites[27], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x400) != 0) {
        position.x = 14.0f + (originX + menu->animation[34].x);
        position.y = 405.0f + (originY + menu->animation[34].y);
        value = (f32)menu->animation[34].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        sdkSpriteDrawAt(menu->sprites[28], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x800) != 0) {
        position.x = 71.0f + (originX + menu->animation[35].x);
        position.y = 405.0f + (originY + menu->animation[35].y);
        value = (f32)menu->animation[35].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        sdkSpriteDrawAt(menu->sprites[29], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 2) != 0) {
        for (rowIndex = 0; rowIndex < menu->partyCount; rowIndex++) {
            radarDrawEntryRowGroup(work, rowIndex, 0);
        }
    }
    if ((menu->visible & 0x20) != 0) {
        CmpSkillColor *paletteColor;
        position.x = 257.0f + (originX + menu->animation[17].x);
        position.y = 21.0f + (originY + menu->animation[17].y);
        value = (f32)menu->animation[17].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        paletteColor = (void *)D_0064B2F4;
        color.rgba[0] = paletteColor->red;
        color.rgba[1] = paletteColor->green;
        color.rgba[2] = paletteColor->blue;
        color.rgba[3] = spriteAlpha;
        radarDrawSecondSpritePair(work, position, color);
        position.x = 255.0f + (originX + menu->animation[17].x);
        position.y = 21.0f + (originY + menu->animation[17].y);
        datRecordClearHeader(&descriptor.kind);
        descriptor.kind = 1;
        descriptor.style = 4;
        descriptor.flags = 1;
        payloadIndex = (s32)menu->scrollRow + (s32)menu->selectedRow;
        descriptor.payload = menu->skills[payloadIndex].copy;
        datEntryDrawByKind(position, spriteAlpha, &descriptor.kind, 1, 0.0f);
    }
    if ((menu->visible & 0x2000) != 0) {
        f32 scrollOriginY;
        u8 scrollAlpha;
        f32 scrollOriginX;
        CmpSkillColor *paletteColor;
        f32 scrollX;
        scrollOriginX = menu->animation[67].x + (originX + menu->animation[16].x);
        scrollOriginY = menu->animation[67].y + (originY + menu->animation[16].y);
        value = (f32)menu->animation[16].alpha;
        value = value * opacity;
        scrollAlpha = (u8)value;
        scrollX = 607.0f + scrollOriginX;
        position.x = scrollX;
        position.y = 32.0f + scrollOriginY;
        sdkSpriteDrawAt(menu->sprites[11], position.x, position.y, 0xFF, 0xFF, 0xFF, scrollAlpha);
        position.x = scrollX;
        position.y = 197.0f + scrollOriginY;
        sdkSpriteDrawAt(menu->sprites[12], position.x, position.y, 0xFF, 0xFF, 0xFF, scrollAlpha);
        position.x = scrollX;
        position.y = 35.0f + scrollOriginY;
        if (menu->skillCount - 6 > 0) {
            position.y += (f32)(((menu->scrollRow * 0x42 + (s32)menu->scrollRow) * 2) / (menu->skillCount - 6));
        }
        paletteColor = (void *)D_0064B2E8;
        sdkSpriteDrawAt(menu->sprites[13], position.x, position.y, paletteColor->red, paletteColor->green,
                      paletteColor->blue, scrollAlpha);
    }
    if ((menu->visible & 8) != 0) {
        if (menu->animation[66].alpha > 0) {
            u8 *rowSprite;
            CmpSkillColor *paletteColor;
            position.x = originX + menu->animation[66].x;
            position.y = originY + menu->animation[66].y;
            paletteColor = (void *)D_0064B2E4;
            rowSprite = menu->sprites[0];
            sdkSpriteDrawSized(rowSprite, position.x, position.y, 0.0f, paletteColor->red, paletteColor->green,
                          paletteColor->blue, menu->animation[66].alpha, 0x1000, 0x1000, 0, 0.0f, 0);
        }
        /* Six visible entries use one animation group and their labels another; both have a 0x30
         * stride. */
        for (rowIndex = 0; rowIndex < 6; rowIndex++) {
            CmpSkillColor *iconColor;
            if (menu->skillCount > rowIndex + menu->scrollRow) {
                if (menu->selectedRow == rowIndex && ((menu->visible & 0x10) != 0)) {
                    if ((menu->visible & 0x80) == 0) {
                        CmpSkillColor *paletteColor;
                        iconColor = (void *)D_0064B2EC;
                        position.x = 257.0f + (originX + menu->animation[9].x);
                        value = 0.0f + menu->animation[9].y + 34.0f * (f32)menu->selectedRow;
                        value = operandOrderAddFloat(21.0f, value);
                        position.y = originY + value;
                        paletteColor = (void *)D_0064B2E8;
                        color.rgba[0] = paletteColor->red;
                        color.rgba[1] = paletteColor->green;
                        color.rgba[2] = paletteColor->blue;
                        value = (f32)menu->animation[9].alpha;
                        value = value * opacity;
                        color.rgba[3] = (u8)value;
                        radarDrawSecondSpritePair(work, position, color);
                    } else {
                        continue;
                    }
                } else {
                    u8 *rowSprite;
                    CmpSkillColor *paletteColor;
                    paletteColor = (void *)D_0064B2E4;
                    iconColor = (void *)D_0064B2E0;
                    position.x = 255.0f + (originX + ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].x);
                    value = 0.0f + (originY + ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].y) + 34.0f * (f32)rowIndex;
                    position.y = 21.0f + value;
                    value = (f32)((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].alpha;
                    value = value * opacity;
                    spriteAlpha = (u8)value;
                    rowSprite = menu->sprites[0];
                    sdkSpriteDrawSized(rowSprite, position.x, position.y, 0.0f, paletteColor->red, paletteColor->green,
                                  paletteColor->blue, spriteAlpha, 0x1000, ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].scaleY,
                                  0, 0.0f, 0);
                }
                payloadIndex = cmpSkillElementLabelId(((CmpSkillWork *)(work + (menu->scrollRow + rowIndex) * 0xC))->skills[0].fields.key);
                if (payloadIndex > 0) {
                    u8 *skillIconSprite;
                    skillIconSprite = (u8 *)((CmpSkillWork *)(work + payloadIndex * 4))->sprites[0];
                    position.x = 258.0f + (originX + ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].x);
                    value = 0.0f + (originY + ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].y) + 34.0f * (f32)rowIndex;
                    position.y = 23.0f + value;
                    value = (f32)((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].alpha;
                    value = value * opacity;
                    spriteAlpha = (u8)value;
                    sdkSpriteDrawSized(skillIconSprite, position.x, position.y, 0.0f, iconColor->red, iconColor->green,
                                  iconColor->blue, spriteAlpha, 0x1000, ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[18].scaleY, 0,
                                  0.0f, 0);
                }
                position.x = 300.0f + (originX + ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[10].x);
                offset = ((CmpSkillWork *)(work + rowIndex * 0x30))->animation[10].y;
                value = 0.0f + originY + 34.0f * (f32)rowIndex;
                value = operandOrderAddFloat(offset, value);
                position.y = 21.0f + value;
                value = (f32)((CmpSkillWork *)(work + rowIndex * 0x30))->animation[10].alpha;
                value = value * opacity;
                spriteAlpha = (u8)value;
                datRecordClearHeader(&descriptor.kind);
                descriptor.kind = 1;
                if (menu->selectedRow == rowIndex && ((menu->visible & 0x10) != 0)) {
                    descriptor.style = 3;
                } else {
                    descriptor.style = 2;
                }
                payloadIndex = (s32)menu->scrollRow + rowIndex;
                descriptor.payload = ((CmpSkillWork *)(work + payloadIndex * 0xC))->skills[0].copy;
                datEntryDrawByKind(position, spriteAlpha, &descriptor.kind, 1, 0.0f);
            }
        }
    }
    if ((menu->visible & 0x40) != 0) {
        for (rowIndex = 0; rowIndex < menu->partyCount; rowIndex++) {
            radarDrawEntryRowGroup(work, rowIndex, 3);
        }
    }
    if ((menu->visible & 0x80) != 0) {
        s32 overlayAlpha;
        position.x = 257.0f + (originX + menu->animation[9].x);
        value = 0.0f + originY + (f32)menu->selectedRow * 34.0f;
        value = operandOrderAddFloat(menu->animation[9].y, value);
        position.y = 21.0f + value;
        value = (f32)menu->animation[32].alpha;
        value = value * opacity;
        overlayAlpha = spriteAlpha = (u8)value;
        datRecordClearHeader(&descriptor.kind);
        descriptor.kind = 1;
        descriptor.style = 3;
        descriptor.flags = 1;
        payloadIndex = (s32)menu->scrollRow + (s32)menu->selectedRow;
        descriptor.payload = menu->skills[payloadIndex].copy;
        radarDrawSkillCard(work, position, overlayAlpha, &descriptor.kind);
    }
    {
        position.x = 640.0f + (originX + menu->animation[36].x);
        position.y = 400.0f + (originY + menu->animation[36].y);
        value = (f32)menu->animation[36].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        sdkSpriteDrawFooter(position, 0.0f, spriteAlpha, menu->footerMode, menu->footer.handle);
    }
}
#pragma pop

/* Save the previous selection before changing a skill-menu cursor slot. */
// FUN_0013A040
/* Halfword-indexed cursor access keeps retail's address-add order. */
s32 cmpSkillSetSelection(s16 *work, s32 slotIndex, s32 selection)
{
    work[slotIndex + 0x54] = work[slotIndex + 0x2E];
    work[slotIndex + 0x2E] = selection;
    return 1;
}

/* Cycle decoration fades and randomized positions using each cell's frame counter and transition
 * duration. Loop counters narrow to s16 late and float temporaries are named to keep retail's load
 * order. */
// FUN_0013A060
#pragma push
/* measured: retail does not hoist loop invariants in the decoration update. */
#pragma opt_loop_invariants off
/* measured: opt_common_subs off preserves the retail per-iteration address formation. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves the retail scalar and FP operand order. */
#pragma opt_propagation off
void cmpSkillStepDecorations(void *work)
{
    s32 i;
    s32 counterOffset;
    s16 *counter;
    u8 *row;
    s32 *durationPtr;
    s32 state;
    s32 count;
    s32 minimumScale;
    s32 maximumScale;
    u8 *alphaPtr;
    u8 *rowBase;
    f32 *x;
    f32 *y;
    CmpSkillDecoration *layout;
    f32 value;
    f32 divisor;
    f32 scale;
    f32 half;
    f32 dimension;
    u32 random;

    for (i = 0; i < 0x1C; i++) {
        counterOffset = i * 2;
        counter = &((CmpSkillWork *)((u8 *)work + counterOffset))->decorationFrames[0];
        count = *counter + 1;
        *counter = count;
        row = (u8 *)work + (counterOffset + i) * 0x10;
        durationPtr = &((CmpSkillWork *)row)->animation[38].duration;
        state = *durationPtr;
        count = (s16)count;
        if (state < count) {
            if (i % 0xE < 6) {
                if (state == 0xA) {
                    *(s16 *)&((CmpSkillWork *)row)->animation[38].targetScaleY =
                        *(s16 *)&((CmpSkillWork *)row)->animation[38].targetScaleX = 0x64;
                    *(s32 *)&((CmpSkillWork *)row)->animation[38].sourceX = 0;
                    *(s32 *)&((CmpSkillWork *)row)->animation[38].sourceY = 0;
                    *(s32 *)&((CmpSkillWork *)row)->animation[38].targetX = 0;
                    *(s32 *)&((CmpSkillWork *)row)->animation[38].targetY = 0;
                    *durationPtr = 6;
                }
                alphaPtr = &((CmpSkillWork *)row)->animation[38].alpha;
                if (*alphaPtr != 0) {
                    rowBase = (u8 *)work + i * 0x30;
                    ((CmpSkillWork *)rowBase)->animation[38].sourceX = ((CmpSkillWork *)rowBase)->animation[38].targetX;
                    ((CmpSkillWork *)rowBase)->animation[38].sourceY = ((CmpSkillWork *)rowBase)->animation[38].targetY;
                    *durationPtr = 0x10;
                } else {
                    rowBase = (u8 *)work + i * 0x30;
                    x = &((CmpSkillWork *)rowBase)->animation[38].sourceX;
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = &((CmpSkillWork *)rowBase)->animation[38].sourceY;
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *y = (f32)random;
                    ((CmpSkillWork *)rowBase)->animation[38].targetX = *x;
                    ((CmpSkillWork *)rowBase)->animation[38].targetY = *y;
                    *durationPtr = 8;
                }
                rowBase = (u8 *)work + i * 0x30;
                ((CmpSkillWork *)rowBase)->animation[38].targetAlpha = ((CmpSkillWork *)rowBase)->animation[38].sourceAlpha;
                ((CmpSkillWork *)rowBase)->animation[38].sourceAlpha = *alphaPtr;
            } else {
                alphaPtr = &((CmpSkillWork *)row)->animation[38].alpha;
                if (*alphaPtr != 0) {
                    if (count < state + 0xA) {
                        continue;
                    }
                    ((CmpSkillWork *)row)->animation[38].sourceX = ((CmpSkillWork *)row)->animation[38].targetX;
                    ((CmpSkillWork *)row)->animation[38].sourceY = ((CmpSkillWork *)row)->animation[38].targetY;
                    ((CmpSkillWork *)row)->animation[38].sourceScaleX = ((CmpSkillWork *)row)->animation[38].targetScaleX;
                    ((CmpSkillWork *)row)->animation[38].sourceScaleY = ((CmpSkillWork *)row)->animation[38].targetScaleY;
                    *durationPtr = 4;
                } else {
                    x = &((CmpSkillWork *)row)->animation[38].sourceX;
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = &((CmpSkillWork *)row)->animation[38].sourceY;
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *y = (f32)random;
                    layout = (CmpSkillDecoration *)(D_005ED790 + i * 0x14);
                    dimension = layout->width;
                    value =
                        (57.0f * dimension) / (divisor = 4096.0f);
                    scale = DAT_00761640;
                    value =
                        (scale * value - value) / (half = 2.0f);
                    ((CmpSkillWork *)row)->animation[38].targetX = *x - value;
                    dimension = layout->height;
                    value = (60.0f * dimension) / divisor;
                    value = (scale * value - value) / half;
                    ((CmpSkillWork *)row)->animation[38].targetY = *y - value;
                    minimumScale = 0x64;
                    *(s16 *)&((CmpSkillWork *)row)->animation[38].sourceScaleX = minimumScale;
                    maximumScale = 0xB4;
                    *(s16 *)&((CmpSkillWork *)row)->animation[38].targetScaleX = maximumScale;
                    *(s16 *)&((CmpSkillWork *)row)->animation[38].sourceScaleY = minimumScale;
                    *(s16 *)&((CmpSkillWork *)row)->animation[38].targetScaleY = maximumScale;
                    *durationPtr = 8;
                }
                rowBase = (u8 *)work + i * 0x30;
                ((CmpSkillWork *)rowBase)->animation[38].targetAlpha = ((CmpSkillWork *)rowBase)->animation[38].sourceAlpha;
                ((CmpSkillWork *)rowBase)->animation[38].sourceAlpha = *alphaPtr;
            }
            *counter = 0;
        }
        radarAnimateValue(row + 0xCA4, *counter, 1);
    }
}
#pragma pop

/* measured: with common subexpressions on, the work+0x22 address is cached in a pointer; retail
 * recomputes base+offset at each access, as in cmpPersona func_00135cf0. Advance the two scrolling
 * row transitions with a frame counter capped at 100. */
/* Advance the shared scroll frame up to a cap of 100, then animate both scrolling skill rows to
 * that frame. */
// FUN_0013A4A0
#pragma opt_common_subs off
void cmpSkillStepScrollRows(void *work)
{
    s32 i;
    u8 *motion;
    s32 frame;

    frame = ((CmpSkillWork *)((u8 *)work))->scrollFrame;
    if (frame < 0x64) {
        ((CmpSkillWork *)((u8 *)work))->scrollFrame = frame + 1;
    }
    for (i = 0; i < 2; i++) {
        motion = (u8 *)work + i * 0x30 + 0x11E4;
        radarAnimateValue(motion, ((CmpSkillWork *)((u8 *)work))->scrollFrame, 0);
    }
}
/* measured: opt_common_subs off is required for the retail base+offset access order. */
#pragma opt_common_subs on

/* measured: retail needs common-subexpression and loop-invariant optimization on here, which hoists
 * the float-conversion constants into the loop preheader. Snapshot current row poses and apply the
 * selected skill-menu layout, footer and visibility flags. */
// FUN_0013A530
s32 cmpSkillSetMode(u8 *work, s32 mode)
{
    CmpSkillWork *menu = (CmpSkillWork *)work;
    s32 i;
    s32 j;
    u8 *table;
    u8 *rowBase;
    u8 *src;
    f32 value;

    table = 0;
    if (menu->mode == mode) {
        return 0;
    }
    for (i = 0; i < 0x26; i++) {
        rowBase = work + i * 0x30;
        ((CmpSkillWork *)(rowBase))->animation[0].sourceX = ((CmpSkillWork *)(rowBase))->animation[0].x;
        ((CmpSkillWork *)(rowBase))->animation[0].sourceY = ((CmpSkillWork *)(rowBase))->animation[0].y;
        ((CmpSkillWork *)(rowBase))->animation[0].sourceScaleX = ((CmpSkillWork *)(rowBase))->animation[0].scaleX;
        ((CmpSkillWork *)(rowBase))->animation[0].sourceScaleY = ((CmpSkillWork *)(rowBase))->animation[0].scaleY;
        ((CmpSkillWork *)(rowBase))->animation[0].sourceAlpha = ((CmpSkillWork *)(rowBase))->animation[0].alpha;
    }
    switch (mode) {
    case 0:
        table = D_005EB5D0;
        *(s32 *)&menu->visible = 0x220B;
        menu->footerMode = 0;
        break;
    case 1:
        table = D_005EBA00;
        break;
    case 2:
        *(s32 *)&menu->visible = 0x220B;
        table = D_005EBE30;
        menu->footerMode = 0;
        break;
    case 3:
        *(s32 *)&menu->visible = 0x269B;
        table = D_005EC260;
        menu->footerMode = 1;
        break;
    case 4:
        *(s32 *)&menu->visible = 0x241B;
        table = D_005EC690;
        menu->footerMode = 1;
        break;
    case 5:
        table = D_005ECAC0;
        *(s32 *)&menu->visible = 0xC61;
        menu->animation[17].sourceY =
            34.0f * (f32)menu->selectedRow;
        menu->footerMode = 0;
        break;
    case 6:
        table = D_005ECAC0;
        *(s32 *)&menu->visible = 0x1861;
        menu->footerMode = 0;
        break;
    case 7:
        table = D_005ECEF0;
        *(s32 *)&menu->visible = 0xD61;
        menu->animation[17].sourceY =
            34.0f * (f32)menu->selectedRow;
        menu->footerMode = 0;
        break;
    case 8:
        table = D_005ECEF0;
        *(s32 *)&menu->visible = 0x1961;
        menu->footerMode = 0;
        break;
    case 9:
        table = D_005ED320;
        *(s32 *)&menu->visible = 0x249B;
        menu->footerMode = 2;
        break;
    case 10:
        table = D_005ED320;
        *(s32 *)&menu->visible = 0x249B;
        menu->footerMode = 2;
        break;
    default:
        kAssertFail(D_005ED9C0, 0x5C9);
        break;
    }
    if (table != 0) {
        for (j = 0; j < 0x26; j++) {
            src = table + j * 0x1C;
            rowBase = work + j * 0x30;
            ((CmpSkillWork *)(rowBase))->animation[0].targetX = ((CmpSkillLayoutRow *)(src))->x;
            ((CmpSkillWork *)(rowBase))->animation[0].targetY = ((CmpSkillLayoutRow *)(src))->y;
            ((CmpSkillWork *)(rowBase))->animation[0].targetAlpha = ((CmpSkillLayoutRow *)(src))->alpha;
            value = ((CmpSkillLayoutRow *)(src))->width;
            ((CmpSkillWork *)(rowBase))->animation[0].targetScaleX = (u16)value;
            value = ((CmpSkillLayoutRow *)(src))->height;
            ((CmpSkillWork *)(rowBase))->animation[0].targetScaleY = (u16)value;
            ((CmpSkillWork *)(rowBase))->animation[0].mode = ((CmpSkillLayoutRow *)(src))->startFrame;
            ((CmpSkillWork *)(rowBase))->animation[0].duration = ((CmpSkillLayoutRow *)(src))->endFrame;
        }
        menu->mode = mode;
        menu->frame = 0;
    }
    return 1;
}
/* measured: retail hoists the 25.0f constant out of the loop, which needs opt_loop_invariants on.
 * Offset the selected party row and its paired label horizontally by 25 pixels. */
// FUN_0013A8A0
void cmpSkillSetPartyCursorMotion(u8 *work)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *rowBase = work + i * 0x30;
        ((CmpSkillWork *)rowBase)->animation[1].sourceX = ((CmpSkillWork *)rowBase)->animation[1].x;
        ((CmpSkillWork *)rowBase)->animation[1].sourceY = ((CmpSkillWork *)rowBase)->animation[1].y;
        ((CmpSkillWork *)rowBase)->animation[1].sourceAlpha = ((CmpSkillWork *)rowBase)->animation[1].alpha;
        ((CmpSkillWork *)rowBase)->animation[5].sourceX = ((CmpSkillWork *)rowBase)->animation[5].x;
        ((CmpSkillWork *)rowBase)->animation[5].sourceY = ((CmpSkillWork *)rowBase)->animation[5].y;
        ((CmpSkillWork *)rowBase)->animation[5].sourceAlpha = ((CmpSkillWork *)rowBase)->animation[5].alpha;
        if (((CmpSkillWork *)work)->selectedParty == i) {
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[1].targetX = 0x41C80000;
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[5].targetX = 0x41C80000;
        } else {
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[1].targetX = 0;
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[5].targetX = 0;
        }
    }
    ((CmpSkillWork *)work)->frame = 0;
}
/* measured: opt_loop_invariants on is required for the retail preheader constant hoist. */
/* Place the scrolling-row overlay at the upper or lower list edge according to scroll direction. */
// FUN_0013A930
void cmpSkillLayoutScrollRows(void *work)
{
    CmpSkillWork *menu = (CmpSkillWork *)work;
    f32 rowY;
    f32 bottomY;
    *(u32 *)&menu->animation[66].sourceX = 0x437F0000;
    *(u32 *)&menu->animation[66].targetX = 0x437F0000;
    *(u32 *)&menu->animation[66].x = 0x437F0000;
    menu->animation[66].sourceAlpha = 0xFF;
    menu->animation[66].alpha = 0xFF;
    menu->animation[66].targetAlpha = 0;
    *(u32 *)&menu->animation[67].targetY = 0;
    if (menu->scrollRow > menu->previousSelection[2]) {
        rowY = 21.0f + menu->animation[18].y;
        menu->animation[66].y = rowY;
        menu->animation[66].sourceY = rowY;
        menu->animation[66].targetY = menu->animation[66].y - 10.0f;
        *(u32 *)&menu->animation[67].sourceY = 0xC1200000;
    } else {
        bottomY = 21.0f + menu->animation[23].y;
        rowY = 170.0f + bottomY;
        menu->animation[66].y = rowY;
        menu->animation[66].sourceY = rowY;
        menu->animation[66].targetY = 10.0f + menu->animation[66].y;
        *(u32 *)&menu->animation[67].sourceY = 0x41200000;
    }
    menu->scrollFrame = 0;
}

/* Offset the selected recipient row and its paired label horizontally by 25 pixels. */
// FUN_0013AA00
void cmpSkillSetScrollCursorMotion(u8 *work)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *rowBase = work + i * 0x30;
        ((CmpSkillWork *)rowBase)->animation[24].sourceX = ((CmpSkillWork *)rowBase)->animation[24].x;
        ((CmpSkillWork *)rowBase)->animation[24].sourceY = ((CmpSkillWork *)rowBase)->animation[24].y;
        ((CmpSkillWork *)rowBase)->animation[24].sourceAlpha = ((CmpSkillWork *)rowBase)->animation[24].alpha;
        ((CmpSkillWork *)rowBase)->animation[28].sourceX = ((CmpSkillWork *)rowBase)->animation[28].x;
        ((CmpSkillWork *)rowBase)->animation[28].sourceY = ((CmpSkillWork *)rowBase)->animation[28].y;
        ((CmpSkillWork *)rowBase)->animation[28].sourceAlpha = ((CmpSkillWork *)rowBase)->animation[28].alpha;
        if (((CmpSkillWork *)work)->selectedRecipient == i) {
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[24].targetX = 0x41C80000;
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[28].targetX = 0x41C80000;
        } else {
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[24].targetX = 0;
            *(s32 *)&((CmpSkillWork *)rowBase)->animation[28].targetX = 0;
        }
    }
    ((CmpSkillWork *)work)->frame = 0;
}
/* measured: retail hoists the loop's constant stores into the preheader. */

/* Randomly restart up to six decoration cells with enlarged scales and a ten-frame transition. */
// FUN_0013AA90
void cmpSkillRandomizeCellMotions(void *work)
{
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(RpRandom() & 1)) {
            u8 *rowBase = (u8 *)work + i * 0x30;
            *(s16 *)&((CmpSkillWork *)rowBase)->animation[38].targetScaleX = 0xFA;
            *(s16 *)&((CmpSkillWork *)rowBase)->animation[38].targetScaleY = 0x190;
            *(u32 *)&((CmpSkillWork *)rowBase)->animation[38].sourceX = 0xC1F00000;
            *(u32 *)&((CmpSkillWork *)rowBase)->animation[38].sourceY = 0xC1F00000;
            *(u32 *)&((CmpSkillWork *)rowBase)->animation[38].targetX = 0xC1F00000;
            *(u32 *)&((CmpSkillWork *)rowBase)->animation[38].targetY = 0xC1F00000;
            *(u32 *)&((CmpSkillWork *)rowBase)->animation[38].duration = 10;
            ((CmpSkillWork *)((u8 *)work + i * 2))->decorationFrames[0] = 0;
        }
    }
}

/* Release all 60 sprite handles and clear the menu visibility mask. */
// FUN_0013AB30
void cmpSkillFreeSprites(u8 *work)
{
    s32 i;
    s32 *slot;

    for (i = 0; i < 0x3C; i++) {
        slot = (s32 *)&((CmpSkillWork *)work)->sprites[i];
        if (*slot != 0) {
            sdkSpriteFreeNode((void *)*slot);
            *slot = 0;
        }
    }
    *(s32 *)&((CmpSkillWork *)work)->visible = 0;
}

/* Report whether every menu row reached its end frame and the shared line animation is idle. */
// FUN_0013ABB0
s32 cmpSkillRowsSettled(u8 *work)
{
    s32 result;
    s32 i;
    s32 threshold;

    /* threshold is held as s32 because an s16 local would be re-sign-extended on every iteration. */
    result = 1;
    i = 0;
    threshold = ((CmpSkillWork *)work)->frame;
    while (i < 0x26) {
        if (threshold < ((CmpSkillWork *)(work + i * 48))->animation[0].duration) {
            result = 0;
        }
        i++;
    }
    return result & nLineIsIdle();
}

/* Return the element-label ID for a skill; IDs at or above 0x1B8 use label 0x35, and missing
 * elements return -1. Case labels follow retail jump-table order because case bodies are laid out
 * in declaration order. */
// FUN_0013AC30
s32 cmpSkillElementLabelId(u16 skillId) {
    s32 elementIndex;

    if ((skillId & 0xFFFF) >= 0x1B8) {
        return 0x35;
    }
    elementIndex = (s16)datCalcSkillElement(NULL, skillId) + 1;
    switch ((u32)elementIndex) {
    case 1:
        return 0x2B;
    case 2:
        return 0x2C;
    case 3:
        return 0x2D;
    case 4:
        return 0x2E;
    case 5:
        return 0x2F;
    case 6:
        return 0x30;
    case 7:
        return 0x31;
    case 8:
        return 0x32;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        return 0x33;
    case 0:
        return -1;
    }
    kAssertFail(D_005ED9C0, 0x6B2);
    return -1;
}

#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "datPersona_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;


float scrGetParamFloat(s32 paramIdx);
s16 datCategoryRankProgress(s16 category, float scale);
s16 datCategoryRank(s16 category);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);


/* Script command: return the rank progress for the given category and float parameter. */
// FUN_0025CDD0
s32 scrCommonGetRankProgress(void) {
    s32 category;

    category = scrGetParamInt(0);
    scrSetReturnInt((s32)datCategoryRankProgress((s16)category, scrGetParamFloat(1)));
    return 1;
}

// Common script command GET_PC_PARAM (p4flow Common 0x0044): returns the player character
// parameter.
// FUN_0025CE40
s32 scrCommonGetPcParam(void) {
    scrSetReturnInt((s32)datCategoryRank((s16)scrGetParamInt(0)));
    return 1;
}

/* The third parameter stays a raw s32 so the first two arguments are masked in retail's order. */
// FUN_0025CE90
s32 scrCommonPersonaAddStat(void) {
    s32 statId;
    s32 personaId;
    s32 amount;

    personaId = scrGetParamInt(0);
    statId = scrGetParamInt(1);
    amount = scrGetParamInt(2);
    datPersonaAddStatById(personaId & 0xFFFF, statId & 0xFFFF, (s8)amount);
    return 1;
}

/* Add the script amount to the requested character bonus stat using halfword identifiers. */
// FUN_0025CF00
s32 scrCommonPersonaAddBonusStat(void) {
    s32 statId;
    s32 characterId;

    characterId = scrGetParamInt(0);
    statId = scrGetParamInt(1);
    datPersonaAddToBonusStatByPcId(characterId & 0xFFFF, statId & 0xFFFF, scrGetParamInt(2));
    return 1;
}

/* Return the requested persona total stat, narrowed to a byte. */
// FUN_0025CF70
s32 scrCommonPersonaGetTotalStat(void) {
    s32 personaId;
    s32 statId;

    personaId = scrGetParamInt(0);
    statId = scrGetParamInt(1);
    scrSetReturnInt(datPersonaGetTotalStatById(personaId & 0xFFFF, statId & 0xFFFF) & 0xFF);
    return 1;
}


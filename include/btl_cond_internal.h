#ifndef BTL_COND_INTERNAL_H
#define BTL_COND_INTERNAL_H

#include "type.h"

/* Battle condition predicates and their FR/EN wrappers. Each prototype
 * matches its definition, which is byte-exact against retail, so the
 * parameter types are the retail register use. The FR/EN wrappers pass
 * their predicate to btlEffectFindUnitMatchingCallback as a callback. */

/* Predicates defined in btlCond.c. */
s32 btlCond_MYHP(u8 *action, s32 conditionValue);
s32 btlCond_MYMP(u8 *action, s32 conditionValue);
s32 btlCond_FRHP(u8 *action, u32 conditionValue);
s32 btlCond_ENHP(u8 *action, u32 conditionValue);
s32 btlCond_ENHP_O(u8 *action, u32 conditionValue);
s32 btlCond_MYLV_O(u8 *action, u32 conditionValue);
s32 btlCond_MYBAD(u8 *task, s32 mask);
s32 btlCond_FRBAD(u8 *action, u32 conditionValue);
s32 btlCond_ENBAD(u8 *action, u32 conditionValue);
s32 btlCond_ENBAD_ALL(u8 *action, s32 conditionValue);
s32 btlCond_FRID(u8 *action, s32 conditionValue);
s32 btlCond_ENID(u8 *action, s32 conditionValue);
s32 btlCond_FRHOJO(u8 *action, s32 conditionValue);
s32 btlCond_ENHOJO(u8 *action, s32 conditionValue);
s32 btlCond_ESCAPE(u8 *action, s32 conditionValue);
s32 btlCond_SUMMON(void);
s32 btlCond_SENSEI(u8 *action);
s32 btlCond_MYHANSYA(u8 *action, s16 conditionValue);
s32 btlCond_MYKYUSYU(u8 *action, s16 conditionValue);
s32 btlCond_MYMUKOU(u8 *action, s16 conditionValue);
s32 btlCond_MYWEAK(u8 *action, s16 conditionValue);
s32 btlCond_FRHANSYA(u8 *action, u32 conditionValue);
s32 btlCond_ENHANSYA(u8 *action, u32 conditionValue);
s32 btlCond_FRKYUSYU(u8 *action, s32 conditionValue);
s32 btlCond_ENKYUSYU(u8 *action, u32 conditionValue);
s32 btlCond_FRMUKOU(u8 *action, u32 conditionValue);
s32 btlCond_ENMUKOU(u8 *action, u32 conditionValue);
s32 btlCond_FRWEAK(u8 *action, u32 conditionValue);
s32 btlCond_ENWEAK(u8 *action, u32 conditionValue);
s32 btlCond_MYUSEATTR(u8 *action, s32 conditionValue);
s32 btlCond_FRUSEATTR(u8 *action, u32 conditionValue);
s32 btlCond_ENUSEATTR(u8 *action, u32 conditionValue);
s32 btlCond_MYHREC(u8 *action);
s32 btlCond_FRHANSYA_ST(u8 *action, u32 conditionValue);
s32 btlCond_ENHANSYA_ST(u8 *action, u32 conditionValue);
s32 btlCond_FRKYUSYU_ST(u8 *action, u32 conditionValue);
s32 btlCond_ENKYUSYU_ST(u8 *action, u32 conditionValue);
s32 btlCond_FRMUKOU_ST(u8 *action, u32 conditionValue);
s32 btlCond_ENMUKOU_ST(u8 *action, u32 conditionValue);
s32 btlCond_FRWEAK_ST(u8 *action, u32 conditionValue);
s32 btlCond_ENWEAK_ST(u8 *action, u32 conditionValue);
s32 btlCond_FRALLHP(u8 *action, s32 conditionValue);
s32 btlCond_ENALLHP(u8 *action, s32 conditionValue);

/* Predicates defined in btlEffect.c. */
u8 btlCond_FRLV_O(int action, u32 conditionValue);
u8 btlCond_ENLV_O(int action, u32 conditionValue);
u8 btlCond_FRCNT(int action, u32 conditionValue);
u8 btlCond_ENCNT(int action, u32 conditionValue);
u8 btlCond_MYUSESKIL(int action, int conditionValue);
s32 btlCond_FRUSESKIL(int action, u32 conditionValue);
s32 btlCond_ENUSESKIL(int action, u32 conditionValue);
u32 btlCond_MYGROUP(int action);
s32 btlCond_FRGROUP(int action, u32 conditionValue);
s32 btlCond_ENGROUP(int action, u32 conditionValue);
u8 btlCond_TURN(int action, u32 conditionValue);
u8 btlCond_TURN_O(int action, u32 conditionValue);
u8 btlCond_MYID(int action, int conditionValue);

/* Predicates defined in btlAICommand.c and referenced from other TUs. */
s32 btlCond_MYNOMAL(u8 *formation, s32 index);
s32 btlCond_MYHOJO(u8 *action, s32 value);
s32 btlCond_MYTAISEI(u8 *action, s16 value);
s32 btlCond_ENWEAK_PAI(u8 *action, u32 value);
s32 btlCond_ENWEAK_ST_PAI(u8 *action, u32 value);
s32 btlCond_ENWEAK_DW_PAI(s32 action, u32 value);
s32 btlCond_ENNOMAL(u8 *action, u32 value);
s32 btlCond_ENNOMAL_ST(u8 *action, u32 value);
s32 btlCond_ENNOMAL_DW(s32 action, u32 value);
s32 btlCond_FRTAISEI(u8 *action, u32 value);
s32 btlCond_ENTAISEI(u8 *action, u32 value);
s32 btlCond_ENNOTNOMAL(u8 *action, u32 value);

/* Group helper in code1_001d.c, called by the btlCond_*GROUP predicates. */
u16 btlSkillClassifyTargets(u8 *action, u8 *selection, u16 skillId, u32 reverseSides);

/* Callback dispatcher in code1_001d.c. Callers pass the predicate as a (code)
 * or (code *) callback with their own argument order, so it stays unprototyped. */
int btlEffectFindUnitMatchingCallback();

#endif

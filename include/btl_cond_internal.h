#ifndef BTL_COND_INTERNAL_H
#define BTL_COND_INTERNAL_H

#include "type.h"

/* Battle condition predicates and their FR/EN wrappers. Each prototype
 * matches its definition, which is byte-exact against retail, so the
 * parameter types are the retail register use. The FR/EN wrappers pass
 * their predicate to btlEffectFindUnitMatchingCallback as a callback. */

/* Predicates defined in btlCond.c. */
s32 btlCond_MYHP(u8 *arg0, s32 arg1);
s32 btlCond_MYMP(u8 *arg0, s32 arg1);
void btlCond_FRHP(u8 *arg0, u32 arg1);
void btlCond_ENHP(u8 *arg0, u32 arg1);
void btlCond_ENHP_O(u8 *arg0, u32 arg1);
s32 btlCond_MYLV_O(u8 *arg0, u32 arg1);
s32 btlCond_MYBAD(u8 *task, s32 mask);
void btlCond_FRBAD(u8 *arg0, u32 arg1);
void btlCond_ENBAD(u8 *arg0, u32 arg1);
s32 btlCond_ENBAD_ALL(u8 *arg0, s32 arg1);
s32 btlCond_FRID(u8 *arg0, s32 arg1);
s32 btlCond_ENID(u8 *arg0, s32 arg1);
s32 btlCond_FRHOJO(u8 *arg0, s32 arg1);
s32 btlCond_ENHOJO(u8 *arg0, s32 arg1);
s32 btlCond_ESCAPE(u8 *arg0, s32 arg1);
s32 btlCond_SUMMON(void);
s32 btlCond_SENSEI(u8 *arg0);
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1);
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1);
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1);
void btlCond_FRHANSYA(u8 *arg0, u32 arg1);
void btlCond_ENHANSYA(u8 *arg0, u32 arg1);
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1);
void btlCond_ENKYUSYU(u8 *arg0, u32 arg1);
void btlCond_FRMUKOU(u8 *arg0, u32 arg1);
void btlCond_ENMUKOU(u8 *arg0, u32 arg1);
void btlCond_FRWEAK(u8 *arg0, u32 arg1);
void btlCond_ENWEAK(u8 *arg0, u32 arg1);
s32 btlCond_MYUSEATTR(u8 *arg0, s32 arg1);
void btlCond_FRUSEATTR(u8 *arg0, u32 arg1);
void btlCond_ENUSEATTR(u8 *arg0, u32 arg1);
s32 btlCond_MYHREC(u8 *arg0);
void btlCond_FRHANSYA_ST(u8 *arg0, u32 arg1);
void btlCond_ENHANSYA_ST(u8 *arg0, u32 arg1);
void btlCond_FRKYUSYU_ST(u8 *arg0, u32 arg1);
void btlCond_ENKYUSYU_ST(u8 *arg0, u32 arg1);
void btlCond_FRMUKOU_ST(u8 *arg0, u32 arg1);
void btlCond_ENMUKOU_ST(u8 *arg0, u32 arg1);
void btlCond_FRWEAK_ST(u8 *arg0, u32 arg1);
void btlCond_ENWEAK_ST(u8 *arg0, u32 arg1);
s32 btlCond_FRALLHP(u8 *arg0, s32 arg1);
s32 btlCond_ENALLHP(u8 *arg0, s32 arg1);

/* Predicates defined in btlEffect.c. */
u8 btlCond_FRLV_O(int param_1, u32 param_2);
u8 btlCond_ENLV_O(int param_1, u32 param_2);
u8 btlCond_FRCNT(int param_1, u32 param_2);
u8 btlCond_ENCNT(int param_1, u32 param_2);
u8 btlCond_MYUSESKIL(int param_1, int param_2);
void btlCond_FRUSESKIL(int param_1, u32 param_2);
void btlCond_ENUSESKIL(int param_1, u32 param_2);
u32 btlCond_MYGROUP(int param_1);
void btlCond_FRGROUP(int param_1, u32 param_2);
void btlCond_ENGROUP(int param_1, u32 param_2);
u8 btlCond_TURN(int param_1, u32 param_2);
u8 btlCond_TURN_O(int param_1, u32 param_2);
u8 btlCond_MYID(int param_1, int param_2);

/* Predicates defined in btlAICommand.c and referenced from other TUs. */
s32 btlCond_MYNOMAL(u8 *formation, s32 index);
s32 btlCond_MYHOJO(u8 *arg0, s32 arg1);
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1);

/* Group helper in code1_001d.c, called by the btlCond_*GROUP predicates. */
u16 btlSkillClassifyTargets(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3);

/* Callback dispatcher in code1_001d.c. Callers pass the predicate as a (code)
 * or (code *) callback with their own argument order, so it stays unprototyped. */
int btlEffectFindUnitMatchingCallback();

#endif

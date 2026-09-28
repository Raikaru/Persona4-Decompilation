#ifndef EFFECT_INSTANCE_INTERNAL_H
#define EFFECT_INSTANCE_INTERNAL_H

#include "type.h"

/* Primitive table entries receive a source descriptor or an existing instance
 * and return the allocated instance, or NULL for an unsupported primitive. */
typedef void *(*EffectInstanceConstructor)(void *source);

/* Resolve either a linked pointer or an offset within the source descriptor. */
void *func_00484490(void *source);
void *func_004844d0(void *source);

u8 *func_00484bb0(u8 *resource);
u8 *func_00485c80(u8 *resource);
void func_00486710(u8 *destination, u8 *source);
u8 *func_00486740(u8 *root, s32 identifier);

u8 *func_004988c0(u16 kind, u8 *parameters);
u8 *func_0049a370(u16 kind, u8 *parameters);
u8 *func_004b4cb0(s32 kind, u8 *parameters);

void *func_00484530(void *source);
void *func_00486b00(void *source);
void *func_00486fb0(void *source);
void *func_00492f20(void *source);
void *func_004933a0(void *source);
void *func_00493200(void *source);
void *func_00493530(void *source);
void *func_00498a30(void *source);
void *func_00498b20(void *source);
void *func_0049a4e0(void *source);
void *func_0049a5e0(void *source);
void *func_004a1780(void *source);
void *func_004a1950(void *source);
void *func_004a5750(void *source);
void *func_004a5910(void *source);
void *func_004a5bb0(void *source);
void *func_004a5e50(void *source);
void *func_004a6d90(void *source);
void *func_004a6e10(void *source);
void *func_004a7a90(void *source);
void *func_004a7b70(void *source);
void *func_004ab060(void *source);
void *func_004ab1c0(void *source);
void *func_004ab5a0(void *source);
void *func_004ab700(void *source);
void *func_004abe80(void *source);
void *func_004ac100(void *source);
void *func_004ac640(void *source);
void *func_004ac930(void *source);
void *func_004ad460(void *source);
void *func_004ad810(void *source);
void *func_004ae460(void *source);
void *func_004ae6d0(void *source);
void *func_004af740(void *source);
void *func_004af920(void *source);
void *func_004b16c0(void *source);
void *func_004b1950(void *source);
void *func_004b4e10(void *source);
void *func_004b4f10(void *source);
void *func_004b5200(void *source);
void *func_004b53c0(void *source);

#endif

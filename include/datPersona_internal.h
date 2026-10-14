#ifndef DATPERSONA_INTERNAL_H
#define DATPERSONA_INTERNAL_H

#include "type.h"

/* Persona table, skill table, and stat accessors defined in datPersona.c.
 * func_0010b3b0 is intentionally not declared here: its one caller keeps an
 * old-style declaration so the s64 argument is passed as measured. */
u8 *func_00109220(u16 personaId);
u8 func_00109280(u16 personaId);
u16 func_001092f0(u32 arg0);
u16 func_00109300(s32 arg0);
u16 func_00109360(u16 arg0);
u8 func_001093a0(s32 arg0);
u16 func_00109470(s32 arg0);
s32 func_00109510(u8 *persona, void *arg1, void *arg2);
void func_001097c0(u8 *arg0, s32 arg1);
u32 func_00109870(u16 arg0, s32 arg1);
u8 func_00109920(u8 *arg0, s32 arg1);
s32 func_00109980(s32 arg0, s32 arg1);
u8 func_001099f0(u8 *arg0, s32 arg1);
u8 func_00109ad0(u8 *arg0, s32 arg1);
u8 func_00109bf0(u16 arg0, s32 arg1);
s8 func_00109d20(u8 *arg0, s32 arg1);
s8 func_00109dd0(u8 *arg0, s32 arg1);
s8 func_00109e30(u8 *arg0, s32 arg1);
s32 func_0010a780(u8 *arg0, s32 arg1, s32 arg2);
s32 func_0010a840(u16 arg0, s32 arg1, s32 arg2);
u16 *func_0010a900(u16 arg0);
s32 func_0010a9b0(s32 arg0);
s32 func_0010aa80(s32 arg0);
s32 func_0010ab30(void);
s32 func_0010abd0(s16 arg0);
u16 *func_0010ac10(s32 arg0);
u16 *func_0010ace0(s16 arg0);
s32 func_0010ad80(s32 arg0);
s32 func_0010ae30(s32 arg0);
u8 *func_0010b010(u16 personaId);
u8 *func_0010b060(u16 personaId);
s32 func_0010b190(u8 *arg0);
s32 func_0010b300(s32 arg0);
u16 func_0010b460(void);
s32 func_0010b510(void);
s32 func_0010b5b0(void);
void func_0010b610(s32 arg0);
u16 func_0010b6f0(void);
void func_0010b7c0(void);
void func_0010b7f0(void);
s32 func_0010b9a0(s32 arg0, u16 arg1);
void func_0010bd90(s16 arg0);
s32 func_0010be20(u8 *arg0);
void func_0010be60(u8 *arg0, u8 *arg1, s32 arg2);
void func_0010c5a0(u8 *arg0, u8 *arg1);
u32 func_0010c750(void *persona, u16 level);
void func_0010c980(u8 *arg0, s32 arg1);
void func_0010c9e0(u8 *arg0);
void func_0010cad0(u8 *arg0, u16 arg1);
s32 func_0010cc20(u8 *arg0, u16 arg1);
s32 func_0010ccc0(u8 *arg0, u32 arg1);
s32 func_0010cd70(u8 *arg0, s16 arg1, u16 arg2);
s32 func_0010ce10(u8 *arg0, u16 arg1);
s32 func_0010ceb0(u8 *arg0);
u16 func_0010cf40(u8 *arg0, s16 arg1);
s32 func_0010cfa0(u8 *arg0, u16 arg1, u8 *arg2);
void func_0010d150(u8 *arg0);

#endif

/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004A7DA0)
#include "type.h"

extern void func_004a7c00(u8 *arg0, s32 arg1);

// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}
#endif /* P4_UNIT_004A7DA0 */

#if defined(P4_UNIT_004A7DE0)
#include "type.h"

// FUN_004A7DE0
void func_004a7de0(void) {
}
#endif /* P4_UNIT_004A7DE0 */

#if defined(P4_UNIT_004A7DF0)
#include "type.h"

extern void func_004a7c00(u8 *arg0, s32 arg1);

// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}
#endif /* P4_UNIT_004A7DF0 */

#if defined(P4_UNIT_004AC290)
#include "type.h"

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

// FUN_004AC290
void func_004ac290(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0x94), 0, 0.0f);
}
#endif /* P4_UNIT_004AC290 */

#if defined(P4_UNIT_004ACB50)
#include "type.h"

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}
#endif /* P4_UNIT_004ACB50 */

#if defined(P4_UNIT_004A7B10)
#include "type.h"

extern s32 D_00724C70;
extern s8 D_00724C58;
extern f32 D_00922D80[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);
extern void (*D_008873ec[])(void *);

// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}
#endif /* P4_UNIT_004A7B10 */

#if defined(P4_UNIT_004A7A50)
#include "type.h"

extern s32 D_00724C70;
extern s8 D_00724C58;
extern f32 D_00922D80[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);

// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}
#endif /* P4_UNIT_004A7A50 */

#if defined(P4_UNIT_004A0BB0)
#include "type.h"

extern void func_004833f0(s32 arg0);
extern void (*D_008873ec[])(void *);

// FUN_004A0BB0
void func_004a0bb0(u8 *arg0) {
    func_004833f0(*(s32 *)(arg0 + 4));
    D_008873ec[0](*(void **)(arg0 + 8));
}
#endif /* P4_UNIT_004A0BB0 */

#if defined(P4_UNIT_004A22C0)
#include "type.h"

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

// FUN_004A22C0
void func_004a22c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}
#endif /* P4_UNIT_004A22C0 */

#if defined(P4_UNIT_004A35F0)
#include "type.h"

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

// FUN_004A35F0
void func_004a35f0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}
#endif /* P4_UNIT_004A35F0 */

#if defined(P4_UNIT_004A49C0)
#include "type.h"

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

// FUN_004A49C0
void func_004a49c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}
#endif /* P4_UNIT_004A49C0 */

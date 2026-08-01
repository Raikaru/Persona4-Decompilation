/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00291B30)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_00291a60(u16 arg0);

// FUN_00291B30
s32 func_00291b30(s32 arg0, u16 *arg1) {
    return (s32)(func_00291a60(*arg1) == 0);
}
#endif /* P4_UNIT_00291B30 */

#if defined(P4_UNIT_00298220)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_0045a8d0(s64 arg0, s32 arg1);

// FUN_00298220
s32 func_00298220(s64 arg0) {
    func_0045a8d0((s16) arg0, 0);
    return 0;
}
#endif /* P4_UNIT_00298220 */

#if defined(P4_UNIT_00299170)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
s32 func_0029cc00(s32 arg0);

// FUN_00299170
s32 func_00299170(void) {
    s16 sp1C[2]; /* measured: 2-element form required for retail slot at 0x1c */

    sp1C[0] = func_0029cc00(0);
    func_001029a0(0x1D, sp1C, 2, 0xA);
    return 1;
}
#endif /* P4_UNIT_00299170 */

#if defined(P4_UNIT_002996E0)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_0029cc00(s32 arg0);
void func_004b1590(s32 arg0, s16 arg1);

// FUN_002996E0
s32 func_002996e0(void) {
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_004b1590(temp_16, func_0029cc00(1));
    return 1;
}
#endif /* P4_UNIT_002996E0 */

#if defined(P4_UNIT_00299890)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_0029cc00(s32 arg0);
s32 func_0045a3e0(s16 arg0, s32 arg1);

// FUN_00299890
s32 func_00299890(void) {
    func_0045a3e0(func_0029cc00(0), 1);
    return 1;
}
#endif /* P4_UNIT_00299890 */

#if defined(P4_UNIT_002998D0)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_0029cc00(s32 arg0);
s32 func_00459880(void);
s32 func_004598e0(s16 arg0);

// FUN_002998D0
s32 func_002998d0(void) {
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        func_00459880();
    } else {
        func_004598e0(temp_2);
    }
    return 1;
}
#endif /* P4_UNIT_002998D0 */

#if defined(P4_UNIT_00299C60)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_00104ce0(s16 arg0);
s32 func_0029cc00(s32 arg0);
void func_0029cf50(s32 arg0);

// FUN_00299C60
s32 func_00299c60(void) {
    func_0029cf50(func_00104ce0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_00299C60 */

#if defined(P4_UNIT_00299CB0)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_00104dc0(s16 arg0);
s32 func_0029cc00(s32 arg0);
void func_0029cf50(s32 arg0);

// FUN_00299CB0
s32 func_00299cb0(void) {
    func_0029cf50(func_00104dc0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_00299CB0 */

#if defined(P4_UNIT_00299D60)
/* Source unit: src/promoted/code1_0029.c */
#include "type.h"

s32 func_00104d50(s16 arg0);
s32 func_0029cc00(s32 arg0);
void func_0029cf50(s32 arg0);

// FUN_00299D60
s32 func_00299d60(void) {
    func_0029cf50(func_00104d50(func_0029cc00(0)) & 0xFFFF);
    return 1;
}
#endif /* P4_UNIT_00299D60 */

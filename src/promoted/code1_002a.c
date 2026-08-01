/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002A2310)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

// FUN_002A2310
void func_002a2310(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_002A2310 */

#if defined(P4_UNIT_002A2710)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

s32 func_00452380(void *arg0);
extern u8 D_0063E918[];

// FUN_002A2710
s32 func_002a2710(void) {
    return (s32)(func_00452380(D_0063E918) != 0);
}
#endif /* P4_UNIT_002A2710 */

#if defined(P4_UNIT_002A2740)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

s32 func_00452380(void *arg0);
void func_00452080(s32 arg0);
extern u8 D_0063E918[];

// FUN_002A2740
void func_002a2740(void) {
    s32 temp_2;

    if ((temp_2 = func_00452380(D_0063E918)) != 0) {
        func_00452080(temp_2);
    }
}
#endif /* P4_UNIT_002A2740 */

#if defined(P4_UNIT_002AAAA0)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

extern s32 D_00882F20[];

// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}
#endif /* P4_UNIT_002AAAA0 */

#if defined(P4_UNIT_002AC270)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#endif /* P4_UNIT_002AC270 */

#if defined(P4_UNIT_002ADCF0)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

// FUN_002ADCF0
s64 func_002adcf0(u8 arg0) {
    return (s64)(s8)((arg0 & 0xFF) >> 4);
}
#endif /* P4_UNIT_002ADCF0 */

#if defined(P4_UNIT_002ADD60)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

extern void (*D_00887300[])(s32 state, s32 value);

// FUN_002ADD60
void func_002add60(u8 *arg0, u8 *arg1) {
    D_00887300[0](0xE, *(s32 *)(arg1 + 0xB4));
}
#endif /* P4_UNIT_002ADD60 */

#if defined(P4_UNIT_002AFB70)
/* Source unit: src/promoted/code1_002a.c */
#include "type.h"

// FUN_002AFB70
void func_002afb70(u8 *arg0, s8 arg1) {
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x38);
    if (arg1 == 0) {
        *(s8 *)(temp_6 + 4) = 5;
    } else if (arg1 == 1) {
        *(s8 *)(temp_6 + 4) = 6;
    }
    *(s16 *)(temp_6 + 0x764) = 0;
}
#endif /* P4_UNIT_002AFB70 */

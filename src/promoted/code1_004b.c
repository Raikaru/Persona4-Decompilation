/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004B0F70)
#include "type.h"

extern void func_004b0ce0();

// FUN_004B0F70
void func_004b0f70(void *object) {
    func_004b0ce0(object, 0);
}
#endif /* P4_UNIT_004B0F70 */

#if defined(P4_UNIT_004B0FA0)
#include "type.h"

extern void func_004b0ce0();

// FUN_004B0FA0
void func_004b0fa0(void *object) {
    func_004b0ce0(object, 1);
}
#endif /* P4_UNIT_004B0FA0 */

#if defined(P4_UNIT_004B13F0)
#include "type.h"

extern void func_004865c0();

// FUN_004B13F0
void func_004b13f0(void *object, s32 *arg1) {
    func_004865c0(object, *arg1);
}
#endif /* P4_UNIT_004B13F0 */

#if defined(P4_UNIT_004B14F0)
#include "type.h"

extern u32 func_00486700(void *object);

// FUN_004B14F0
void func_004b14f0(void *object, s32 *arg1) {
    *arg1 = func_00486700(object);
}
#endif /* P4_UNIT_004B14F0 */

#if defined(P4_UNIT_004B57A0)
#include "type.h"

extern u8 *func_004b6030();
extern u8 *func_004b6900();
extern void func_004b6bb0();
extern void func_004b6da0();

// FUN_004B57A0
u8 *func_004b57a0(void *object, s32 arg1) {
    u8 *temp_2;
    u8 *temp_2_2;

    temp_2_2 = func_004b6030(object);
    *(s32 *)(temp_2_2 + 0x20) = arg1;
    temp_2 = func_004b6900(temp_2_2);
    func_004b6da0(temp_2);
    func_004b6bb0(temp_2);
    return temp_2;
}
#endif /* P4_UNIT_004B57A0 */

#if defined(P4_UNIT_004B50D0)
#include "type.h"

typedef signed __int128 s128;

// FUN_004B50D0
s128 func_004b50d0(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}
#endif /* P4_UNIT_004B50D0 */

#if defined(P4_UNIT_004B5750)
#include "type.h"

typedef signed __int128 s128;

// FUN_004B5750
s128 func_004b5750(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}
#endif /* P4_UNIT_004B5750 */

#if defined(P4_UNIT_004B5760)
#include "type.h"

typedef signed __int128 s128;

// FUN_004B5760
s128 func_004b5760(u8 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *(s128 *)(arg0 + 0x10) = temp;
    return temp;
}
#endif /* P4_UNIT_004B5760 */

#if defined(P4_UNIT_004BD750)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the load (nd 8 -> 0). */
// FUN_004BD750
#pragma schedule on
s32 func_004bd750(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}
#pragma schedule off
#endif /* P4_UNIT_004BD750 */

/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00361970)
#include "type.h"

// FUN_00361970
void func_00361970(u8 *arg0)
{
    *(s32 *)(arg0 + 0x5C4) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x32)) {
        *(f32 *)(arg0 + 0x5BC) = -10.0f;
    } else {
        *(f32 *)(arg0 + 0x5BC) = 10.0f;
    }
    *(s16 *)(arg0 + 0x26) = 0;
}
#endif /* P4_UNIT_00361970 */

#if defined(P4_UNIT_003642A0)
#include "type.h"

extern void func_003642e0(u8 *arg0, void *arg1);

// FUN_003642A0
void func_003642a0(u8 *arg0)
{
    u16 *temp = *(u16 **)(arg0 + 0x38);

    func_003642e0(arg0, NULL);
    *temp |= 2;
}
#endif /* P4_UNIT_003642A0 */

#if defined(P4_UNIT_003671D0)
#include "type.h"

extern void memset(void *dst, s32 value, s32 size);

// FUN_003671D0
void func_003671d0(s16 *arg0)
{
    memset((u8 *)arg0 + 4, 0, 0x18);
    *arg0 = 0;
}
#endif /* P4_UNIT_003671D0 */

#if defined(P4_UNIT_0036D860)
#include "type.h"

extern void func_0036b650(u8 *arg0);
extern void func_0036aa20(void);
extern void func_0036d8b0(void);

// FUN_0036D860
void func_0036d860(u8 *arg0, s32 arg1)
{
    func_0036b650(arg0);
    func_0036aa20();
    if (arg1 != 0) {
        func_0036d8b0();
    }
}
#endif /* P4_UNIT_0036D860 */

#if defined(P4_UNIT_0036D960)
#include "type.h"

extern void func_0036b750(void);
extern s32 func_0036bb60(void);

// FUN_0036D960
s32 func_0036d960(void)
{
    func_0036b750();
    return !func_0036bb60();
}
#endif /* P4_UNIT_0036D960 */

#if defined(P4_UNIT_0036DB20)
#include "type.h"

extern void func_00368be0(void);
extern void func_0036c450(void);
extern void func_0036dba0(u8 *arg0);

// FUN_0036DB20
void func_0036db20(u8 *arg0)
{
    func_00368be0();
    func_0036c450();
    func_0036dba0(arg0);
}
#endif /* P4_UNIT_0036DB20 */

#if defined(P4_UNIT_0036DDE0)
#include "type.h"

extern void func_003dc740(void *dest, void *src, s32 mode, f32 fparg0);
extern void func_0036de20(u8 *arg0, void *arg1);

// FUN_0036DDE0
void func_0036dde0(u8 *arg0, void *arg1, s32 arg2, f32 fparg0)
{
    f32 sp20[4];

    func_003dc740(sp20, arg1, arg2, fparg0);
    func_0036de20(arg0, sp20);
}
#endif /* P4_UNIT_0036DDE0 */

#if defined(P4_UNIT_0036DE70)
#include "type.h"

extern void func_0036b5e0(u8 *arg0, f32 *out);

// FUN_0036DE70
f32 func_0036de70(u8 *arg0)
{
    f32 sp10[3];

    func_0036b5e0(arg0, sp10);
    return 6.0f * sp10[0];
}
#endif /* P4_UNIT_0036DE70 */

#if defined(P4_UNIT_0036E580)
#include "type.h"

extern void func_003753f0(u8 *arg0);

// FUN_0036E580
void func_0036e580(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003753f0((u8 *)arg1 + 0x70);
    }
}
#endif /* P4_UNIT_0036E580 */

#if defined(P4_UNIT_0036E5C0)
#include "type.h"

extern void func_003757f0(u8 *arg0);

// FUN_0036E5C0
void func_0036e5c0(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003757f0((u8 *)arg1 + 0x70);
    }
}
#endif /* P4_UNIT_0036E5C0 */

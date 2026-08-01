/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002B0220)
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

// FUN_002B0220
void func_002b0220(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}
#endif /* P4_UNIT_002B0220 */

#if defined(P4_UNIT_002B2CB0)
#include "type.h"

// FUN_002B2CB0
s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 + arg1;
    }
    {
        s32 var = arg0 + arg1;
        s32 bound;
        if (arg2 < var) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}
#endif /* P4_UNIT_002B2CB0 */

#if defined(P4_UNIT_002B2D00)
#include "type.h"

// FUN_002B2D00
s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 - arg1;
    }
    {
        s32 var = arg0 - arg1;
        s32 bound;
        if (var < arg2) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}
#endif /* P4_UNIT_002B2D00 */

#if defined(P4_UNIT_002B6820)
#include "type.h"

// FUN_002B6820
s8 func_002b6820(u8 *arg0, u32 arg1) {
    u32 n = arg1 & 0xFFFF;
    return (s8)((s32)(*(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10) & ((1 << n) & 0xFFFF)) >> n);
}
#endif /* P4_UNIT_002B6820 */

#if defined(P4_UNIT_002B6A40)
#include "type.h"

extern void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5);

// FUN_002B6A40
void func_002b6a40(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg5;
    func_002b82d0(base + 0x10, arg1, arg2, arg3, arg4, ext);
}
#endif /* P4_UNIT_002B6A40 */

#if defined(P4_UNIT_002B6AC0)
#include "type.h"

extern void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

// FUN_002B6AC0
void func_002b6ac0(u8 *arg0, u32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg3;
    func_002b8300(base + 0x10, arg1, arg2, ext, fparg0, fparg1, fparg2, fparg3);
}
#endif /* P4_UNIT_002B6AC0 */

#if defined(P4_UNIT_002BBCF0)
#include "type.h"

extern void func_002bb9e0(u8 *arg0, s32 arg1);

// FUN_002BBCF0
void func_002bbcf0(u8 *arg0) {
    func_002bb9e0(arg0, 1);
}
#endif /* P4_UNIT_002BBCF0 */

#if defined(P4_UNIT_002BC0B0)
#include "type.h"

extern s32 func_002bc0e0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5);

// FUN_002BC0B0
void func_002bc0b0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    func_002bc0e0(arg0, arg1, arg2, 1, arg3, arg4);
}
#endif /* P4_UNIT_002BC0B0 */

#if defined(P4_UNIT_002BD3E0)
#include "type.h"

extern void func_002bcc60(u8 *arg0);
extern u8 *D_0072466C;

// FUN_002BD3E0
void func_002bd3e0(void) {
    func_002bcc60(D_0072466C);
}
#endif /* P4_UNIT_002BD3E0 */

#if defined(P4_UNIT_002BE160)
#include "type.h"

extern s32 clndGetMoonPhase(void);

// FUN_002BE160
s32 func_002be160(u8 *arg0, s32 arg1) {
    s32 n = arg1 & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase() & 0xFF) >= n;
}
#endif /* P4_UNIT_002BE160 */

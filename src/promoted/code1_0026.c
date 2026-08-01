/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00266A40)
#include "type.h"

extern u8 *func_00452560(void);

// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}
#endif /* P4_UNIT_00266A40 */

#if defined(P4_UNIT_00266B70)
#include "type.h"

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}
#endif /* P4_UNIT_00266B70 */

#if defined(P4_UNIT_00268E60)
#include "type.h"

typedef struct { f32 x, y, z; } SVec3;

extern u8 *func_00145270(void);

// FUN_00268E60
s32 func_00268e60(u32 unk, u8 *arg1, f32 fparg0) {
    s32 temp_4;
    u8 *temp_2 = func_00145270();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0x28) | 1;
    *(s32 *)(temp_2 + 0x28) = temp_4;
    *(s32 *)(temp_2 + 0x28) = temp_4 & ~0x40;
    *(SVec3 *)(temp_2 + 0x30) = *(SVec3 *)(temp_2 + 4);
    *(SVec3 *)(temp_2 + 0x3C) = *(SVec3 *)arg1;
    *(f32 *)(temp_2 + 0x5C) = fparg0;
    *(s8 *)(temp_2 + 0x54) = 0;
    return 1;
}
#endif /* P4_UNIT_00268E60 */

#if defined(P4_UNIT_00269000)
#include "type.h"

typedef struct { f32 x, y, z; } SVec3;

// FUN_00269000
s32 func_00269000(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s8 arg4, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;

    if (arg0 == NULL) {
        return 0;
    }
    temp_3 = *(s32 *)(arg0 + 0x28) | 0x10;
    *(s32 *)(arg0 + 0x28) = temp_3;
    temp_3_2 = temp_3 & ~1;
    *(s32 *)(arg0 + 0x28) = temp_3_2;
    temp_3_3 = temp_3_2 & ~4;
    *(s32 *)(arg0 + 0x28) = temp_3_3;
    *(s32 *)(arg0 + 0x28) = temp_3_3 & ~0x40;
    *(SVec3 *)(arg0 + 0x90) = *(SVec3 *)arg1;
    *(SVec3 *)(arg0 + 0x9C) = *(SVec3 *)arg2;
    *(f32 *)(arg0 + 0xA8) = fparg0;
    *(f32 *)(arg0 + 0xAC) = fparg1;
    *(f32 *)(arg0 + 0xB0) = fparg2;
    *(f32 *)(arg0 + 0xB4) = fparg3;
    *(f32 *)(arg0 + 0xB8) = fparg4;
    *(f32 *)(arg0 + 0xBC) = fparg5;
    *(s32 *)(arg0 + 0xC0) = arg3;
    *(s8 *)(arg0 + 0x8C) = arg4;
    *(s32 *)(arg0 + 0xC4) = 0;
    return 1;
}
#endif /* P4_UNIT_00269000 */

#if defined(P4_UNIT_00269440)
#include "type.h"

typedef struct { f32 x, y, z; } SVec3;

extern u8 *func_00145270(void);

// FUN_00269440
s32 func_00269440(u32 unk, u8 *arg1, s32 arg2) {
    u8 *temp_2 = func_00145270();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) |= 0x8000;
    *(SVec3 *)(temp_2 + 0xC8) = *(SVec3 *)(temp_2 + 0x1C);
    *(SVec3 *)(temp_2 + 0xD4) = *(SVec3 *)arg1;
    *(s32 *)(temp_2 + 0xE0) = arg2;
    *(s32 *)(temp_2 + 0xE4) = 0;
    return 1;
}
#endif /* P4_UNIT_00269440 */

#if defined(P4_UNIT_00269690)
#include "type.h"

extern u8 *func_00145270(void);

// FUN_00269690
s32 func_00269690(u32 unk, f32 fparg0, s32 arg1) {
    u8 *temp_2 = func_00145270();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    if (((*(u16 *)temp_2 & 0xFFC00) >> 0xA) != 7) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) |= 0x400;
    *(f32 *)(temp_2 + 0x104) = *(f32 *)(temp_2 + 0x140);
    *(f32 *)(temp_2 + 0x108) = fparg0;
    *(s32 *)(temp_2 + 0x10C) = arg1;
    *(s32 *)(temp_2 + 0x110) = 0;
    return 1;
}
#endif /* P4_UNIT_00269690 */

#if defined(P4_UNIT_00269C20)
#include "type.h"

extern u8 *func_00145270(void);
extern s32 func_00269bd0(u8 *arg0, s32 arg1);

// FUN_00269C20
s32 func_00269c20(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00145270();

    if (temp_2 != NULL) {
        return func_00269bd0(temp_2, arg1);
    }
    return 0;
}
#endif /* P4_UNIT_00269C20 */

#if defined(P4_UNIT_0026BD50)
#include "type.h"

extern u8 *func_00145270(void);
extern s32 func_0026bc90(u8 *arg0, s32 arg1);

// FUN_0026BD50
s32 func_0026bd50(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00145270();

    if (temp_2 != NULL) {
        return func_0026bc90(temp_2, arg1);
    }
    return 0;
}
#endif /* P4_UNIT_0026BD50 */

#if defined(P4_UNIT_0026BF20)
#include "type.h"

extern u8 *func_001452b0(s32 arg0);

// FUN_0026BF20
void func_0026bf20(void) {
    u8 *var_3 = func_001452b0(7);

    while (var_3 != NULL) {
        *(s32 *)(var_3 + 0x148) = 0;
        var_3 = *(u8 **)(var_3 + 0x138);
    }
}
#endif /* P4_UNIT_0026BF20 */

#if defined(P4_UNIT_0026E360)
#include "type.h"

extern s32 func_00106880(s16 arg0);

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}
#endif /* P4_UNIT_0026E360 */

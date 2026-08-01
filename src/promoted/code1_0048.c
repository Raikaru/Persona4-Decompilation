/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00481360)
#include "type.h"

s32 func_00464100(u8 *arg0, s32 arg1);

// FUN_00481360
void func_00481360(u8 *arg0)
{
    func_00464100(arg0, 1);
}
#endif /* P4_UNIT_00481360 */

#if defined(P4_UNIT_00481390)
#include "type.h"

s32 func_00464100(u8 *arg0, s32 arg1);
u8 *func_003ef2e0(u8 *arg0);

// FUN_00481390
void func_00481390(u8 *arg0)
{
    u8 *temp_2 = func_003ef2e0((u8 *)func_00464100(arg0, 1));
    s32 temp_4 = (*(s32 *)(temp_2 + 0x50) & ~0xFF) | 2;

    *(s32 *)(temp_2 + 0x50) = temp_4;
    *(s32 *)(temp_2 + 0x50) = (temp_4 & 0xFFFF00FF) | 0x1100;
}
#endif /* P4_UNIT_00481390 */

#if defined(P4_UNIT_00483660)
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

// FUN_00483660
void func_00483660(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}
#endif /* P4_UNIT_00483660 */

#if defined(P4_UNIT_004836B0)
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483810();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

// FUN_004836B0
void func_004836b0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}
#endif /* P4_UNIT_004836B0 */

#if defined(P4_UNIT_00484350)
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}
#endif /* P4_UNIT_00484350 */

#if defined(P4_UNIT_004843A0)
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483810();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}
#endif /* P4_UNIT_004843A0 */

#if defined(P4_UNIT_00486180)
#include "type.h"

extern u8 D_00713480[];

// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}
#endif /* P4_UNIT_00486180 */

#if defined(P4_UNIT_00487650)
#include "type.h"

void func_004833f0(s32 arg0);
s32 func_004830f0(s32 arg0, s32 arg1);

// FUN_00487650
void func_00487650(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x50);

    if (temp_4 != 0) {
        func_004833f0(temp_4);
    }
    switch (arg2) {
    case 1:
    case 4:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x20080027);
        return;
    case 2:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}
#endif /* P4_UNIT_00487650 */

#if defined(P4_UNIT_00487860)
#include "type.h"

void func_00481ee0(s32 arg0);
s32 func_00481d80(s32 *arg0);

// FUN_00487860
void func_00487860(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x44);

    if (temp_4 != 0) {
        func_00481ee0(temp_4);
    }
    *(s32 *)(arg0 + 0x44) = func_00481d80(arg1);
}
#endif /* P4_UNIT_00487860 */

#if defined(P4_UNIT_00487BA0)
#include "type.h"

void func_004829c0(s32 arg0);
s32 func_00482800(s32 *arg0);

// FUN_00487BA0
void func_00487ba0(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x48);

    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    *(s32 *)(arg0 + 0x48) = func_00482800(arg1);
}
#endif /* P4_UNIT_00487BA0 */

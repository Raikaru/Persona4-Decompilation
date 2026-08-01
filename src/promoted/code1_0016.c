/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00160180)
#include "type.h"

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);

// FUN_00160180
void func_00160180(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18DC) != 0) {
        *(s32 *)((u8 *)func_00155280() + 0x18D8) = 0;
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18DC));
        *(s32 *)((u8 *)func_00155280() + 0x18DC) = 0;
    }
}
#endif /* P4_UNIT_00160180 */

#if defined(P4_UNIT_00160440)
#include "type.h"

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);

// FUN_00160440
void func_00160440(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x1854) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x1854));
        *(s32 *)((u8 *)func_00155280() + 0x1854) = 0;
    }
}
#endif /* P4_UNIT_00160440 */

#if defined(P4_UNIT_00166B10)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_00166B10
void func_00166b10(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00166B10 */

#if defined(P4_UNIT_001673F0)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_001673F0
void func_001673f0(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_001673F0 */

#if defined(P4_UNIT_00167530)
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];

// FUN_00167530
void func_00167530(void)
{
    memset(D_007E8020, 0, 0x40);
}
#endif /* P4_UNIT_00167530 */

#if defined(P4_UNIT_00167D60)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_00167D60
void func_00167d60(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00167D60 */

#if defined(P4_UNIT_00168030)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_00168030
void func_00168030(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00168030 */

#if defined(P4_UNIT_00168470)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_00168470
void func_00168470(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_00168470 */

#if defined(P4_UNIT_0016E9F0)
#include "type.h"

typedef struct E9F0Vec3
{
    f32 x;
    f32 y;
    f32 z;
} E9F0Vec3;

// FUN_0016E9F0
void func_0016e9f0(u8 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    *(E9F0Vec3 *)(temp_3 + 0x14) = *(E9F0Vec3 *)(arg1 + 0x00);
}
#endif /* P4_UNIT_0016E9F0 */

#if defined(P4_UNIT_0016F100)
#include "type.h"

extern void (*DAT_008873EC[])(void *);

// FUN_0016F100
void func_0016f100(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
#endif /* P4_UNIT_0016F100 */

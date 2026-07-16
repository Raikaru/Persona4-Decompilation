/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001D69F0)
/* Source unit: src/Battle/btlFormation_001d69f0.c */
#include "type.h"

extern u8* DAT_0076449c;
extern char D_00609570[];
extern char D_00609588[];
extern u8 D_00763388;

void func_00442088(u64 context, const char* format, ...);

// FUN_001D69F0
void func_001d69f0(u16 value, u64 context)
{
    if ((*(u32*)(DAT_0076449c + 0x14) & 1) != 0)
    {
        func_00442088(context, D_00609570);
    }
    else
    {
        func_00442088(context, D_00609588, &D_00763388, value);
    }
}
#endif /* P4_UNIT_001D69F0 */

#if defined(P4_UNIT_001D7BB0)
/* Source unit: src/Battle/btlFormation_001d7bb0.c */
#include "type.h"

void func_001fc2e0(u32 first, u32 second, u32 third);

// FUN_001D7BB0
u32 func_001d7bb0(u32* args)
{
    func_001fc2e0(args[0], args[1], args[2]);
    return 1;
}
#endif /* P4_UNIT_001D7BB0 */

#if defined(P4_UNIT_001DB580)
/* Source unit: src/Battle/btlFormation_001db580.c */
#include "type.h"

s32 func_001db360(u64 formation, u16 index, s32 enabled);

// FUN_001DB580
void func_001db580(u64 formation, u16 index)
{
    func_001db360(formation, index, 1);
}
#endif /* P4_UNIT_001DB580 */

#if defined(P4_UNIT_001DB5B0)
/* Source unit: src/Battle/btlFormation_001db5b0.c */
#include "type.h"

s32 func_001db360(u64 formation, u16 index, s32 enabled);

// FUN_001DB5B0
void func_001db5b0(u64 formation, u16 index)
{
    func_001db360(formation, index, 0);
}
#endif /* P4_UNIT_001DB5B0 */

#if defined(P4_UNIT_001DCB50)
/* Source unit: src/Battle/btlFormation_001dcb50.c */
#include "type.h"

typedef void (*FormationCallback)(void);

void func_001dbba0(u64 formation, u32 flags, s32 arg2, s32 arg3, s32 variant, FormationCallback callback);
void func_001d9b60(void);

// FUN_001DCB50
void func_001dcb50(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 0, func_001d9b60);
}
#endif /* P4_UNIT_001DCB50 */

#if defined(P4_UNIT_001DCB90)
/* Source unit: src/Battle/btlFormation_001dcb90.c */
#include "type.h"

typedef void (*FormationCallback)(void);

void func_001dbba0(u64 formation, u32 flags, s32 arg2, s32 arg3, s32 variant, FormationCallback callback);
void func_001d9b60(void);

// FUN_001DCB90
void func_001dcb90(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 1, func_001d9b60);
}
#endif /* P4_UNIT_001DCB90 */

#if defined(P4_UNIT_002027E0)
/* Source unit: src/Battle/btlFormation_002027e0.c */
#include "type.h"

s32 func_00194470(s32 taskId, s32 arg);
u32 func_002027b0(void);

// FUN_002027E0
void func_002027e0(void)
{
    s32 task;

    task = func_00194470(0x50d, 0);
    *(u32*)(task + 0x6c) = (u32)func_002027b0;
}
#endif /* P4_UNIT_002027E0 */

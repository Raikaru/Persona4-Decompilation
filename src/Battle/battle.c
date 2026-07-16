/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00192560)
/* Source unit: src/Battle/battle_00192560.c */
#include "type.h"

static u64 iGpffffa090 = 1;

// FUN_00192560
u64 func_00192560(void)
{
    iGpffffa090++;

    if (iGpffffa090 >= 0x3FFFFFFFFFFFFFFF)
    {
        iGpffffa090 = 1;
    }

    return iGpffffa090;
}
#endif /* P4_UNIT_00192560 */

#if defined(P4_UNIT_001925B0)
/* Source unit: src/Battle/battle_001925b0.c */
#include "type.h"

extern void* func_00145270(u16 resTypeId);

static u16 iGpffffa098 = 0x100;

// FUN_001925B0
u16 func_001925b0(void)
{
    do
    {
        if (++iGpffffa098 >= 0x200)
        {
            iGpffffa098 = 0x100;
        }
    } while (func_00145270((iGpffffa098 & 0x3ff) | 0x400) != NULL);

    return iGpffffa098;
}
#endif /* P4_UNIT_001925B0 */

#if defined(P4_UNIT_00192790)
/* Source unit: src/Battle/battle_00192790.c */
#include "type.h"

extern void func_001949d0(u32 layer);
extern void func_001b6ab0(void);

// FUN_00192790
void* func_00192790(void* task)
{
    func_001949d0(3);
    func_001b6ab0();

    return 0;
}
#endif /* P4_UNIT_00192790 */

#if defined(P4_UNIT_001935F0)
/* Source unit: src/Battle/battle_001935f0.c */
#include "type.h"

extern s32 func_0029d020(void);
extern u32 func_001fc270(void);

// FUN_001935F0
u32 func_001935f0(void)
{
    if (func_0029d020() > 0)
    {
        return func_001fc270() != 0;
    }

    return 0;
}
#endif /* P4_UNIT_001935F0 */

#if defined(P4_UNIT_00193750)
/* Source unit: src/Battle/battle_00193750.c */
#include "type.h"

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};
extern Battle* iGpfffb3ac;

// FUN_00193750
u32 func_00193750(void* work)
{
    BtlBattleFlagPacket* packet;

    packet = (BtlBattleFlagPacket*)work;
    iGpfffb3ac->flags |= packet->flags;

    return 1;
}
#endif /* P4_UNIT_00193750 */

#if defined(P4_UNIT_00193770)
/* Source unit: src/Battle/battle_00193770.c */
#include "type.h"

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x6c];
    u32 (*updateFunc)(void* work);
    u8 _pad70[8];
    void* workData;
};

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_00193750(void* work);

// FUN_00193770
BtlPacket* func_00193770(u32 flags)
{
    BtlPacket* packet;

    packet = func_00194470(0xFF02, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = func_00193750;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}
#endif /* P4_UNIT_00193770 */

#if defined(P4_UNIT_001937C0)
/* Source unit: src/Battle/battle_001937c0.c */
#include "type.h"

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};
extern Battle* iGpfffb3ac;

#pragma optimization_level 1
// FUN_001937C0
u32 func_001937c0(void* work)
{
    BtlBattleFlagPacket* packet;
    Battle* btl;

    btl = iGpfffb3ac;
    packet = (BtlBattleFlagPacket*)work;
    btl->flags &= ~packet->flags;

    return 1;
}
#pragma optimization_level 2
#endif /* P4_UNIT_001937C0 */

#if defined(P4_UNIT_001937F0)
/* Source unit: src/Battle/battle_001937f0.c */
#include "type.h"

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x6c];
    u32 (*updateFunc)(void* work);
    u8 _pad70[8];
    void* workData;
};

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_001937c0(void* work);

// FUN_001937F0
BtlPacket* func_001937f0(u32 flags)
{
    BtlPacket* packet;

    packet = func_00194470(0xFF03, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = func_001937c0;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}
#endif /* P4_UNIT_001937F0 */

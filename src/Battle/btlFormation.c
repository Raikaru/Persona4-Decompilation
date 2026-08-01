/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001D69F0)
/* Source unit: src/Battle/btlFormation_001d69f0.c */
#include "type.h"

extern u8* DAT_0076449c;
extern char D_00609570[];
extern char D_00609588[];
extern u8 D_00763388;

void sprintf(u64 context, const char* format, ...);

// FUN_001D69F0
void func_001d69f0(u16 value, u64 context)
{
    if ((*(u32*)(DAT_0076449c + 0x14) & 1) != 0)
    {
        sprintf(context, D_00609570);
    }
    else
    {
        sprintf(context, D_00609588, &D_00763388, value);
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
void btlCond_MYNOMAL(u64 formation, u16 index)
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
void btlCond_MYBAD(void);

// FUN_001DCB50
void func_001dcb50(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 0, btlCond_MYBAD);
}
#endif /* P4_UNIT_001DCB50 */

#if defined(P4_UNIT_001DCB90)
/* Source unit: src/Battle/btlFormation_001dcb90.c */
#include "type.h"

typedef void (*FormationCallback)(void);

void func_001dbba0(u64 formation, u32 flags, s32 arg2, s32 arg3, s32 variant, FormationCallback callback);
void btlCond_MYBAD(void);

// FUN_001DCB90
void func_001dcb90(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 1, btlCond_MYBAD);
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

#if defined(P4_UNIT_001D1EB0)
/* Source unit: src/Battle/btlFormation_001d1eb0.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_00194470(u32 taskId, u32 size);
extern u32 func_001d1cc0(int* param_1);

// FUN_001D1EB0
void func_001d1eb0(u32 param_1, u32 param_2, float param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = func_00194470(0xb00, 0x10);
    *(code **)(packet + 0x6c) = (code *)func_001d1cc0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    *(float *)(work + 2) = param_3;
    *(u16 *)(work + 3) = param_4;
}
#endif /* P4_UNIT_001D1EB0 */

#if defined(P4_UNIT_001D2D90)
/* Source unit: src/Battle/btlFormation_001d2d90.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_00194470(u32 taskId, u32 size);
extern u32 func_001d1f30(u32 *work);

// FUN_001D2D90
void func_001d2d90(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = func_00194470(0xb01, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d1f30;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
}
#endif /* P4_UNIT_001D2D90 */

#if defined(P4_UNIT_001D3E00)
/* Source unit: src/Battle/btlFormation_001d3e00.c */
#include "type.h"

typedef struct BtlFormationState
{
    u8 padding[0x630];
    u16 flags;
    u16 counter;
    u32 value;
} BtlFormationState;

extern void func_001d3ff0(int state);
extern void (*DAT_008873EC[])(...);

// FUN_001D3E00
void func_001d3e00(u32 param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter--;
    if (((state->flags & 8) != 0) && (state->counter == 1)) {
        func_001d3ff0((int)state);
    }
    if (state->counter == 0) {
        if ((state->flags & 2) != 0) {
            func_001d3ff0((int)state);
        }
        (*DAT_008873EC)(state);
    }
}
#endif /* P4_UNIT_001D3E00 */

#if defined(P4_UNIT_001D3EA0)
/* Source unit: src/Battle/btlFormation_001d3ea0.c */
#include "type.h"

extern u64 memcpy();
extern u32 func_00485c80(u32 param_1);
extern u32 func_00484bb0(u32 param_1);

// FUN_001D3EA0
void func_001d3ea0(int destination, u32 source)
{
    u16 outer;
    u16 index;
    s32 count;
    u8* entry;
    int block;
    u8* referencedEntry;
    u32 packed;
    u32 resource;
    u32 continueLoop;

    memcpy(destination, source, 0x630);
    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = destination + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        for (index = 0; index < count; index++) {
            if (entry[0] != 0xfe) {
                if (entry[0] == 0xff) {
                    packed = *(u32 *)(entry + 4);
                    referencedEntry = (u8 *)(destination + (packed >> 5) * 0x314 +
                                             (packed & 0x1f) * 0x18 + 0x1c);
                    resource = func_00485c80(*(u32 *)(referencedEntry + 4));
                    entry[0] = referencedEntry[0];
                } else {
                    resource = func_00484bb0(source + *(u32 *)(entry + 4));
                }
                *(u32 *)(entry + 4) = resource;
            }
            entry += 0x18;
        }
        outer++;
    }
    *(u16 *)(destination + 0x630) |= 2;
}
#endif /* P4_UNIT_001D3EA0 */

#if defined(P4_UNIT_001D3FF0)
/* Source unit: src/Battle/btlFormation_001d3ff0.c */
#include "type.h"

extern u64 func_00485b20(u32 param_1);

// FUN_001D3FF0
void func_001d3ff0(int state)
{
    u16 outer;
    u16 index;
    int count;
    u8 *entry;
    int block;
    u32 continueLoop;

    outer = 0;
    while ((s32)(continueLoop = outer) < 2) {
        block = state + (outer & 0xffff) * 0x314;
        count = *(u16 *)(block + 0x10);
        entry = (u8 *)(block + 0x1c);
        index = 0;
        while (index < count) {
            if (*entry != 0xfe && *entry != 0xfd) {
                func_00485b20(*(u32 *)(entry + 4));
            }
            entry += 0x18;
            index++;
        }
        outer++;
    }
    *(u16 *)(state + 0x630) &= 0xfffd;
}
#endif /* P4_UNIT_001D3FF0 */

#if defined(P4_UNIT_001D40D0)
/* Source unit: src/Battle/btlFormation_001d40d0.c */
#include "type.h"

typedef struct BtlFormationState
{
    u8 padding[0x630];
    u16 flags;
    u16 counter;
    u32 value;
} BtlFormationState;

extern void func_001d3ea0(int destination, u32 source);

// FUN_001D40D0
void func_001d40d0(int param_1)
{
    BtlFormationState *state;

    state = (BtlFormationState *)param_1;
    state->counter++;
    if (((state->flags & 8) != 0) && (state->counter == 2)) {
        func_001d3ea0(param_1, state->value);
    }
}
#endif /* P4_UNIT_001D40D0 */

#if defined(P4_UNIT_001D4140)
/* Source unit: src/Battle/btlFormation_001d4140.c */
#include "type.h"

// FUN_001D4140
u32 func_001d4140(int param_1, u16 param_2)
{
    u32 result;

    switch (param_2) {
    case 0:
        result = *(u32 *)(param_1 + 8);
        break;
    case 1:
        result = *(u32 *)(param_1 + 0x328);
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
#endif /* P4_UNIT_001D4140 */

#if defined(P4_UNIT_001D42E0)
/* Source unit: src/Battle/btlFormation_001d42e0.c */
#include "type.h"

typedef struct BtlFormationWork
{
    u32 state;
    u32 list;
    u32 argument5;
    u8 padding0c[4];
    s32 sentinel;
    u8 random;
    u8 padding15[3];
    u32 argument3;
    u32 argument4;
    u8 padding20[0x34];
    u16 count;
    u16 padding56;
    u32 items;
} BtlFormationWork;

extern u64 func_00485b20(u32 param_1);
extern void (*DAT_008873EC[])(...);

// FUN_001D42E0
void func_001d42e0(BtlFormationWork *work)
{
    s32 count;
    u16 index;
    u32 *items;

    count = work->count;
    items = (u32 *)(uintptr_t)work->items;
    index = 0;
    while (index < count) {
        if (*items != 0) {
            func_00485b20(*items);
        }
        items++;
        index++;
    }
    (*DAT_008873EC)(work);
}
#endif /* P4_UNIT_001D42E0 */

#if defined(P4_UNIT_001D4380)
/* Source unit: src/Battle/btlFormation_001d4380.c */
#include "type.h"

// P3 counterpart fGpffff8398 (gp -0x7C68); P4 retail uses gp -0x7CAC,
// i.e. absolute 0x007690f0 - 0x7cac = 0x00761444.
extern float fGpffff8354;
// P3 counterpart fGpffff839c (gp -0x7C64); P4 retail uses gp -0x7EE4,
// i.e. absolute 0x007690f0 - 0x7ee4 = 0x0076120c.
extern float fGpffff811c;

// FUN_001D4380
float func_001d4380(int param_1)
{
    float fVar1 = 0;

    fVar1 = fGpffff8354 * ((*(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x2c) +
            *(float *)(param_1 + 0x8c) * *(float *)(param_1 + 0x2c) * 0.5f) * 0.5f);
    if (fVar1 > 2.5f) {
        fVar1 = 2.5f;
    }
    else if (fVar1 < fGpffff811c) {
        fVar1 = fGpffff811c;
    }
    return fVar1;
}
#endif /* P4_UNIT_001D4380 */

#if defined(P4_UNIT_001D6170)
/* Source unit: src/Battle/btlFormation_001d6170.c */
#include "type.h"

typedef u8 bool;

#define true 1
#define false 0

extern bool func_001d4120(int param_1);
extern u32 func_001d4190(int param_1, u16 param_2);

/* Ported from P3 donor func_002baec0. The volatile pointer locals are
   load-bearing: measured W170, removing the qualifiers loses this function
   (MATCH nd0 -> MISMATCH nd6, size 112 -> 112). */
// FUN_001D6170
bool func_001d6170(u32 *param_1)
{
    int iVar2;
    u16 index;
    u32 value;
    volatile /* Removing this function's qualifier batch loses func_001d6170 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170; ported from P3 donor func_002baec0. */ u16 *index_ptr;
    volatile /* Removing this function's qualifier batch loses func_001d6170 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170; ported from P3 donor func_002baec0. */ u32 *value_ptr;

    if (!func_001d4120(*param_1)) {
        return false;
    }
    index_ptr = (volatile u16 *)(param_1 + 3);
    value_ptr = (volatile u32 *)param_1;
    iVar2 = (index = *index_ptr,
             value = *value_ptr,
             func_001d4190(value, index));
    iVar2 <<= 1;
    if (iVar2 < 1) {
        iVar2 = 2;
    }
    return iVar2 <= (int)param_1[6];
}
#endif /* P4_UNIT_001D6170 */

#if defined(P4_UNIT_001D61E0)
/* Source unit: src/Battle/btlFormation_001d61e0.c */
#include "type.h"

extern u32 func_001d6de0(int param_1, u16 *param_2);
extern void func_001d3e00(u32 param_1);

// FUN_001D61E0
void func_001d61e0(u32 *param_1)
{
    func_001d6de0(param_1[5], (u16 *)param_1[4]);
    func_001d3e00(*(int *)param_1);
    *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + -1;
    *(u16 *)(param_1[2] + 0xa0) = *(u16 *)(param_1[2] + 0xa0) + -1;
}
#endif /* P4_UNIT_001D61E0 */

#if defined(P4_UNIT_001D3000)
/* Source unit: src/Battle/btlFormation_001d3000.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_00194470(u32 taskId, u32 size);
extern void func_001d2e00(u32 *work);
extern u32 func_001d2e20(u32 *param_1);
extern void func_001d2fe0(u32 *work);

// FUN_001D3000
void func_001d3000(u32 param_1, u32 param_2, u32 param_3, u16 param_4)
{
    u32 *work;
    u32 packet;

    packet = func_00194470(0xb02, 0x10);
    *(code **)(packet + 0x68) = (code *)func_001d2e00;
    *(code **)(packet + 0x6c) = (code *)func_001d2e20;
    *(code **)(packet + 0x70) = (code *)func_001d2fe0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
}
#endif /* P4_UNIT_001D3000 */

#if defined(P4_UNIT_001D5EB0)
/* Source unit: src/Battle/btlFormation_001d5eb0.c */
#include "type.h"

typedef void (*BtlPacketInitFunc)(void* work);
typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketInitFunc initFunc;
    BtlPacketUpdateFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 strlen();
extern u32 strcpy();
extern void func_001d5ca0(u32 *param_1);
extern u32 func_001d5d60(u32 *param_1);

// FUN_001D5EB0
u32 func_001d5eb0(u32 param_1, u32 param_2, u16 param_3)
{
    typedef struct FormationStringWork {
        u32 value;
        u32 unused;
        char *text;
        u16 field;
        u16 padding;
    } FormationStringWork;
    BtlPacket *packet;
    FormationStringWork *work;

    packet = func_00194470(0x400, strlen(param_2) + sizeof(FormationStringWork));
    packet->flags &= 0xfe;
    packet->initFunc = (BtlPacketInitFunc)func_001d5ca0;
    packet->updateFunc = (BtlPacketUpdateFunc)func_001d5d60;
    work = packet->workData;
    work->value = param_1;
    work->text = (char *)(work + 1);
    work->field = param_3;
    strcpy(work->text, param_2);
    return (u32)packet;
}
#endif /* P4_UNIT_001D5EB0 */

#if defined(P4_UNIT_001D6240)
/* Source unit: src/Battle/btlFormation_001d6240.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_00194470(u32 taskId, u32 size);
extern void func_001d5f60(u32 *param_1);
extern u32 func_001d6010(u32 *param_1);
extern u8 func_001d6170(u32 *param_1);
extern void func_001d61e0(u32 *param_1);

// FUN_001D6240
void func_001d6240(u32 param_1, u32 param_2, u32 param_3, u16 param_4, u32 param_5)
{
    u32 *work;
    u32 packet;

    packet = func_00194470(0x301, 0x20);
    *(u8 *)(packet + 0x47) = *(u8 *)(packet + 0x47) & 0xef;
    *(code *)(packet + 0x68) = (code)func_001d5f60;
    *(code *)(packet + 0x6c) = (code)func_001d6010;
    *(code *)(packet + 0x74) = (code)func_001d6170;
    *(code *)(packet + 0x70) = (code)func_001d61e0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
    *(u16 *)(work + 3) = param_4;
    work[7] = param_5;
}
#endif /* P4_UNIT_001D6240 */

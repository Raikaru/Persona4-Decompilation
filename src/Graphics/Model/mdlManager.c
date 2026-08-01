/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004711E0)
/* Source unit: src/Graphics/Model/mdlManager_004711e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003115a0 (verified MATCH there). */
#include "type.h"

extern u32 func_00397460(void);
extern void func_003e9af0(void* object, void (*callback)(void), void* data);

// FUN_004711E0
u32 func_004711e0(void* param_1, u32* param_2)
{
    u32 value;

    value = func_00397460();
    if (value != 0)
    {
        goto store_value;
    }
    func_003e9af0(param_1, (void (*)(void))func_004711e0, param_2);
    return (u32)param_1;
store_value:
    *param_2 = value;
    return 0;
}
#endif /* P4_UNIT_004711E0 */

#if defined(P4_UNIT_00471250)
/* Source unit: src/Graphics/Model/mdlManager_00471250.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00311610 (verified MATCH there). */
#include "type.h"

extern void func_003b83d0(void);

// FUN_00471250
void* func_00471250(void* param_1)
{
    func_003b83d0();
    return param_1;
}
#endif /* P4_UNIT_00471250 */

#if defined(P4_UNIT_00471280)
/* Source unit: src/Graphics/Model/mdlManager_00471280.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00311640 (verified MATCH there). */
#include "type.h"

typedef struct RtAnimAnimation RtAnimAnimation;

typedef void (*RtAnimKeyFrameBlendCallBack)(void* voidOut, void* voidIn1, void* voidIn2, f32 alpha);

typedef struct RtAnimInterpolator RtAnimInterpolator;

// 76 bytes. Layout from P3FES include/rw/rtanim.h.
struct RtAnimInterpolator
{
    RtAnimAnimation* pCurrentAnim;               // 0x00
    f32 currentTime;                             // 0x04
    void* pNextFrame;                            // 0x08
    void* pAnimCallBack;                         // 0x0c
    void* pAnimCallBackData;                     // 0x10
    f32 animCallBackTime;                        // 0x14
    void* pAnimLoopCallBack;                     // 0x18
    void* pAnimLoopCallBackData;                 // 0x1c
    s32 maxInterpKeyFrameSize;                   // 0x20
    s32 currentInterpKeyFrameSize;               // 0x24
    s32 currentAnimKeyFrameSize;                 // 0x28
    s32 numNodes;                                // 0x2c
    s32 isSubInterpoaltor;                       // 0x30
    s32 offsetInParent;                          // 0x34
    RtAnimInterpolator* parentAnimation;         // 0x38
    void* keyFrameApplyCB;                       // 0x3c
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB; // 0x40
    void* keyFrameInterpolateCB;                 // 0x44
    void* keyFrameAddCB;                         // 0x48
};

// FUN_00471280
u32 func_00471280(RtAnimInterpolator* param_2, RtAnimInterpolator* param_3,
                  RtAnimInterpolator* param_4, f32 param_1)
{
    s32 frame;
    s32 offset2;
    s32 offset3;
    s32 offset4;
    f32 alpha;
    u8* out;
    u8* in1;
    u8* in2;
    u8* in2Out;
    offset2 = param_2->offsetInParent;
    offset3 = param_3->offsetInParent;
    offset4 = param_4->offsetInParent;
    for (frame = offset2; frame < param_2->numNodes + param_2->offsetInParent; frame++)
    {
        in2 = (u8*)(param_4->currentInterpKeyFrameSize * (frame - offset4) -
                     (0u - (u32)param_4)) + 0x4c;
        out = (u8*)(param_2->currentInterpKeyFrameSize * (frame - offset2) -
                    (0u - (u32)param_2));
        in1 = (u8*)(param_3->currentInterpKeyFrameSize * (frame - offset3) -
                    (0u - (u32)param_3));
        alpha = *(f32*)(in2 + 0x30);
        param_2->keyFrameBlendCB(out + 0x4c, in1 + 0x4c, in2,
                                 param_1 * alpha);
    }
    return 1;
}
#endif /* P4_UNIT_00471280 */

#if defined(P4_UNIT_004745F0)
/* Source unit: src/Graphics/Model/mdlManager_004745f0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00313be0 (verified MATCH there). */
#include "type.h"

typedef struct MdlAnimEntry MdlAnimEntry;

// 16 bytes. Layout from P3FES include/Graphics/Model/mdlManager.h.
typedef struct MdlAnimEntryTable
{
    MdlAnimEntry* entries; // 0x00
    u16 count;             // 0x04
    u16 unk_06;            // 0x06
    u8 unkData[0x08];
} MdlAnimEntryTable;

// 8 bytes
typedef struct MdlAnimResourceEntry
{
    void* resource;
    u8 flags;
    u8 unk_05[3];
} MdlAnimResourceEntry;

extern void func_0047fa60(void* resource);
extern void (*DAT_008873ec[])(...);

// FUN_004745F0
void func_004745f0(MdlAnimEntryTable* table)
{
    u16 i;

    table->unk_06--;
    if (table->unk_06 == 0) {
        for (i = 0; i < table->count; i++) {
            MdlAnimResourceEntry* entry;

            entry = (MdlAnimResourceEntry*)table->entries;
            entry += i;

            if ((entry->resource != NULL) && ((entry->flags & 1) == 0)) {
                func_0047fa60(entry->resource);
            }
        }

        (*DAT_008873ec)(table);
    }
}
#endif /* P4_UNIT_004745F0 */

#if defined(P4_UNIT_00474970)
/* Source unit: src/Graphics/Model/mdlManager_00474970.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00313f40 (verified MATCH there). */
#include "type.h"

extern void* func_003df890(void* list);
extern void* func_003df8a0(void* list);
extern void* func_003df6e0(void* list, s32 index);

#pragma push
/* P4 port probe: removing opt_propagation off regresses 00474970 MATCH nd0 -> MISMATCH nd8 (s0/s1 coloring swap, 10 differing words) - measured. */
#pragma opt_propagation off
// FUN_00474970
int func_00474970(int param_1, void* param_2)
{
    int* piVar1;
    void* list;

    list = param_2;
    piVar1 = (int*)func_003df890(list);
    while (piVar1 != (int*)func_003df8a0(list)) {
        if (param_1 == *piVar1) {
            return param_1;
        }
        piVar1++;
    }

    *(int*)func_003df6e0(list, 0) = param_1;
    return param_1;
}
#pragma pop
#endif /* P4_UNIT_00474970 */

#if defined(P4_UNIT_00474A10)
/* Source unit: src/Graphics/Model/mdlManager_00474a10.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00313fe0 (verified MATCH there). */
#include "type.h"

extern void func_003c21e0(u32 object, u32 arg1, u32 arg2);

// FUN_00474A10
void* func_00474a10(void* param_1, u32* param_2)
{
    func_003c21e0(*(u32*)((u8*)param_1 + 0x18), *param_2, param_2[1]);
    return param_1;
}
#endif /* P4_UNIT_00474A10 */

#if defined(P4_UNIT_00474AF0)
/* Source unit: src/Graphics/Model/mdlManager_00474af0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003140c0 (verified MATCH there). */
#include "type.h"

#pragma alias func_003d5e40_typed func_003d5e40
extern void func_003d5e40_typed(f32 frame, void* interpolator);

// FUN_00474AF0
void* func_00474af0(void* param_1, u16* param_2)
{
    s16 rawIndex;
    u16 count;
    s64 lVar2;
    int* piVar1;

    rawIndex = (s16)param_2[2];
    piVar1 = *(int**)(param_2 + 0xc);
    if (piVar1 != (int*)0x0) {
        lVar2 = (s64)rawIndex;
        count = *(u16*)(piVar1 + 3);
        if ((((lVar2 < (s64)(u32)count) &&
              (*(int*)(*piVar1 + rawIndex * 8) != 0)) && ((*param_2 & 1) == 0)) &&
            ((lVar2 < (s64)(u32)count && (0 <= rawIndex)))) {
            func_003d5e40_typed(*(f32*)(*(int*)param_1 + 0xc), param_1);
            *(u8*)(param_2 + 1) = 1;
        }
    }

    return param_1;
}
#endif /* P4_UNIT_00474AF0 */

#if defined(P4_UNIT_00475090)
/* Source unit: src/Graphics/Model/mdlManager_00475090.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00314650 (verified MATCH there). */
#include "type.h"

extern u32 func_003b83f0(int object);
extern u32 func_003b8500(int object);
extern void func_00473140(int param_1);

// FUN_00475090
u32 func_00475090(u32 param_1)
{
    int iVar1;
    int iVar2;
    u32 lVar3;
    u32 uVar4;
    int iVar5;

    iVar1 = *(int*)((int)param_1 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_003b83f0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_003b8500(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    iVar2 = *(int*)(iVar1 + 0x24);
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
        func_00473140(*(u32*)(*(int*)(iVar1 + 0x20) + iVar5 * 4));
    }

    return param_1;
}
#endif /* P4_UNIT_00475090 */

#if defined(P4_UNIT_00475B10)
/* Source unit: src/Graphics/Model/mdlManager_00475b10.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00315010 (verified MATCH there). */
#include "type.h"

extern void* func_00397470(void);
extern void func_003e9af0(void* object, void (*callback)(void), void* data);

// FUN_00475B10
void* func_00475b10(void* object, void* data)
{
    if (*(void**)((u8*)data + 4) == (void*)func_00397470()) {
        *(void**)data = object;
        return NULL;
    }

    func_003e9af0(object, (void (*)(void))func_00475b10, data);
    return object;
}
#endif /* P4_UNIT_00475B10 */

#if defined(P4_UNIT_00477900)
/* Source unit: src/Graphics/Model/mdlManager_00477900.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003165e0 (verified MATCH there). */
#include "type.h"

#pragma push
/* Removing this loses FUN_00477900 (MATCH nd0 -> MISMATCH nd51) - measured W161 (ported from P3FES donor; re-probed in P4: nd0 -> nd51). */
#pragma opt_loop_invariants on
// FUN_00477900
void* func_00477900(void* param_1)
{
    int iVar1;
    u32 uVar2;
    int offset;
    int base;
    int iVar3;
    int iVar4;
    u32 uVar5;
    f32 two;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    volatile /* Removing this qualifier loses func_00477900 (MATCH nd0 -> MISMATCH nd105, size 172 -> 132) - measured W170 (ported from P3FES donor; re-probed in P4: nd0 -> nd105, size 132). */ f32 values[4];

    iVar4 = (int)param_1;
    iVar1 = *(int*)(iVar4 + 0x18);
    if (iVar1 == 0)
        goto done;

    uVar2 = *(u32*)(iVar1 + 0x18);
    uVar5 = 0;
    two = 2.0f;
    goto check;

loop:
    offset = uVar5 * 8;
    offset = offset - uVar5;
    offset = offset * 4;
    base = *(int*)(iVar1 + 0x5c);
    iVar3 = base + offset;
    values[0] = *(f32*)(iVar3 + 4);
    values[1] = *(f32*)(iVar3 + 8);
    values[2] = *(f32*)(iVar3 + 0xc);
    values[3] = two * *(f32*)(iVar3 + 0x10);
    x = values[0];
    y = values[1];
    z = values[2];
    w = values[3];
    *(f32*)(iVar3 + 4) = x;
    *(f32*)(iVar3 + 8) = y;
    *(f32*)(iVar3 + 0xc) = z;
    *(f32*)(iVar3 + 0x10) = w;
    uVar5 = uVar5 + 1;
check:
    if (uVar5 < uVar2)
        goto loop;

done:
    *(u32*)(iVar4 + 0x4c) = *(u32*)(iVar4 + 0x4c) | 2;
    return param_1;
}
#pragma pop
#endif /* P4_UNIT_00477900 */

#if defined(P4_UNIT_0047A220)
/* Source unit: src/Graphics/Model/mdlManager_0047a220.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00318ad0 mdlSetColor (verified MATCH there). */
#include "type.h"

typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;

// Model: `color` at 0xd0 (layout from P3FES include/Graphics/Model/mdlManager.h).
typedef struct Model
{
    u8 unkData0[0xd0];
    RwRGBA color; // 0xd0
    u8 unkData1[0x10];
} Model;

// FUN_0047A220
void mdlSetColor(Model* mdl, const RwRGBA* color)
{
    mdl->color = *color;
}
#endif /* P4_UNIT_0047A220 */

#if defined(P4_UNIT_0047A2A0)
/* Source unit: src/Graphics/Model/mdlManager_0047a2a0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00318b10 (verified MATCH there). */
#include "type.h"

// FUN_0047A2A0
void func_0047a2a0(u32* param_1)
{
    param_1[10] = 0x3f800000;
    param_1[5] = 0x3f800000;
    *param_1 = 0x3f800000;
    param_1[4] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[9] = 0;
    param_1[8] = 0;
    param_1[6] = 0;
    param_1[0xe] = 0;
    param_1[0xd] = 0;
    param_1[0xc] = 0;
    param_1[3] = param_1[3] | 0x20003;
    return;
}
#endif /* P4_UNIT_0047A2A0 */

#if defined(P4_UNIT_00472F30)
/* Source unit: src/Graphics/Model/mdlManager_00472f30.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00312c70 (verified MATCH there). */
#include "type.h"

typedef int (*code)(...);

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern code DAT_00922ba0;
extern s32 DAT_00922ba4;
extern s32 DAT_00922ba8;
extern float* DAT_00922bac;
#pragma alias DAT_00922ba0_abs DAT_00922ba0
#pragma alias DAT_00922ba4_abs DAT_00922ba4
#pragma alias DAT_00922ba8_abs DAT_00922ba8
#pragma alias DAT_00922bac_abs DAT_00922bac
extern code DAT_00922ba0_abs[];
extern u8 DAT_00922ba4_abs[];
extern u8 DAT_00922ba8_abs[];
extern u8 DAT_00922bac_abs[];

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

// FUN_00472F30
void func_00472f30(u8* param_1, int param_2)
{
    if (*(s32*)DAT_00922ba8_abs == param_2) {
        *(float*)(param_2 + 0x18) = *(float*)(param_2 + 0x18) * *(*(float**)DAT_00922bac_abs);
        *(float*)(param_2 + 0x1c) = *(float*)(param_2 + 0x1c) * (*(float**)DAT_00922bac_abs)[1];
        *(float*)(param_2 + 0x20) = *(float*)(param_2 + 0x20) * (*(float**)DAT_00922bac_abs)[2];
    }
    (*DAT_00922ba0_abs)(param_1, param_2);
    if (*(s32*)DAT_00922ba4_abs == param_2) {
        RwMatrixScale((void*)param_1, (const RwV3d*)*(float**)DAT_00922bac_abs, 1);
    }
    return;
}
#endif /* P4_UNIT_00472F30 */

#if defined(P4_UNIT_00473140)
/* Source unit: src/Graphics/Model/mdlManager_00473140.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00312e80 (verified MATCH there). */
#include "type.h"

extern u32 func_00399d80();
extern u32 func_0039b6e0();

// FUN_00473140
void func_00473140(int param_1)
{
    u32 uVar1;
    u32 uVar2;

    uVar2 = func_00399d80();
    switch (uVar2) {
    case 1:
        uVar1 = func_0039b6e0(0x10021);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 2:
        uVar1 = func_0039b6e0(0x10022);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 3:
        uVar1 = func_0039b6e0(0x10023);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 4:
        uVar1 = func_0039b6e0(0x10024);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 5:
        uVar1 = func_0039b6e0(0x1002a);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    case 6:
        uVar1 = func_0039b6e0(0x1002b);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    default:
        uVar1 = func_0039b6e0(0x10020);
        *(u32*)(param_1 + 8) = uVar1;
        break;
    }

    return;
}
#endif /* P4_UNIT_00473140 */

#if defined(P4_UNIT_00473250)
/* Source unit: src/Graphics/Model/mdlManager_00473250.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00312f90 (verified MATCH there). */
#include "type.h"

extern u32 func_003b83f0(int object);
extern u32 func_003b8500(int object);
extern u32 func_0039b6e0();
extern void func_00473140(int param_1);

// FUN_00473250
u32 func_00473250(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 lVar3;
    u32 uVar4;
    int iVar5;
    int iVar6;

    iVar5 = (int)param_1;
    iVar1 = *(int*)(iVar5 + 0x18);
    if (iVar1 == 0) {
        return param_1;
    }

    lVar3 = func_003b83f0(iVar1);
    if (lVar3 == 0) {
        return param_1;
    }

    uVar4 = func_003b8500(lVar3);
    if (uVar4 <= 0x40) {
        return param_1;
    }

    if (param_1 != 0) {
        uVar2 = func_0039b6e0(0x1001f);
        *(u32*)(iVar5 + 0x6c) = uVar2;
        iVar5 = *(int*)(iVar5 + 0x18);
        iVar1 = *(int*)(iVar5 + 0x24);
        for (iVar6 = 0; iVar6 < iVar1; iVar6 = iVar6 + 1) {
            func_00473140(*(u32*)(*(int*)(iVar5 + 0x20) + iVar6 * 4));
        }
        return param_1;
    }

    return param_1;
}
#endif /* P4_UNIT_00473250 */

#if defined(P4_UNIT_00474890)
/* Source unit: src/Graphics/Model/mdlManager_00474890.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00313e60 (verified MATCH there). */
#include "type.h"

extern void func_003df7f0();
extern void func_003d6230();
extern void (*DAT_008873ec[])(...);

// FUN_00474890
void func_00474890(void* param_1)
{
    void* piVar1;
    int* piVar2;
    s32 uVar3;

    piVar2 = (int*)param_1;

    *(u16*)((int)piVar2 + 0xe) = *(u16*)((int)piVar2 + 0xe) + -1;

    if (*(u16*)((int)piVar2 + 0xe) == 0) {
        if (piVar2[2] != 0) {
            func_003df7f0((void*)piVar2[2]);
        }

        if (piVar2[1] != 0) {
            func_003d6230((void*)piVar2[1]);
        }

        for (uVar3 = 0; (uVar3 & 0xffff) < *(u16*)(piVar2 + 3); uVar3 = uVar3 + 1 & 0xffff) {
            piVar1 = (void*)*piVar2;
            piVar1 = (void*)((u8*)piVar1 + (u16)uVar3 * 8);

            if ((*(int*)piVar1 != 0) &&
                ((*(u8*)((u8*)piVar1 + 4) & 1) == 0)) {
                func_003d6230(*(void**)piVar1);
            }
        }

        (*DAT_008873ec)(param_1);
    }

    return;
}
#endif /* P4_UNIT_00474890 */

#if defined(P4_UNIT_00474CE0)
/* Source unit: src/Graphics/Model/mdlManager_00474ce0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003142b0 (verified MATCH there). */
#include "type.h"

extern int func_003bcfb0();
extern void* func_003bd000(void* material, int data);
extern char* func_003bd040(void* userData);
extern int func_003bd060(void* object);
extern int func_003bd050(void* userData);
extern void* func_003bd0b0(void* object, int index);
extern int strcmp(const char* s1, const char* s2);
extern char DAT_007641c8[1];

// FUN_00474CE0
u32 func_00474ce0(void* param_1)
{
    s32 iVar2;
    s32 iVar1;
    s32 uVar3;
    char* uVar4;
    s32 lVar5;
    s32 iVar6;
    void* iVar7;

    iVar1 = func_003bcfb0();
    uVar3 = 0;
    while (uVar3 < iVar1) {
        iVar7 = func_003bd000(param_1, uVar3);
        uVar4 = func_003bd040(iVar7);
        if (strcmp(uVar4, DAT_007641c8) == 0) {
            iVar2 = func_003bd060(iVar7);
            iVar6 = 0;
            while (iVar6 < iVar2) {
                lVar5 = func_003bd050(iVar7);
                if (lVar5 == 3) {
                    return (u32)func_003bd0b0(iVar7, iVar6);
                }
                iVar6++;
            }
        }
        uVar3++;
    }
    return 0;
}
#endif /* P4_UNIT_00474CE0 */

#if defined(P4_UNIT_00474DF0)
/* Source unit: src/Graphics/Model/mdlManager_00474df0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003143c0 (verified MATCH there). */
#include "type.h"

typedef int (*code)(...);

extern u32 func_003df5d0();
extern int func_00474970(int param_1, void* param_2);
extern void func_003bff30(void* object, void (*callback)(void), void* data);
extern void* func_00474a10(void* param_1, u32* param_2);
extern void* func_003df890();
extern void* func_003df8a0();
extern u32 func_00474ce0(void* param_1);
extern int func_00442c30();
extern int func_003d8130();
extern void func_003d5990();
extern void* func_00474ba0(void* param_1, void* param_2);
extern char gp0xffff9d10;
extern u8 LAB_00474a50;
#pragma alias LAB_00474a50_abs LAB_00474a50
extern u8 LAB_00474a50_abs[];
extern u8 LAB_00474a90;
#pragma alias LAB_00474a90_abs LAB_00474a90
extern u8 LAB_00474a90_abs[];

// FUN_00474DF0
void func_00474df0(u8* param_1, void* param_2)
{
    u32 uVar1;
    u32* puVar2;
    u32* puVar3;
    u32 userData;
    u32 animation;

    struct {
        code callback;
        u32 value;
    } callbackData;

    if ((*(int*)(param_1 + 0x18) != 0) &&
        (*(u32*)(param_1 + 0xc) = 0, *(int*)(*(int*)(param_1 + 0x18) + 8) == 0)) {
        uVar1 = func_003df5d0(4, 0);

        callbackData.callback = (code)func_00474970;
        callbackData.value = uVar1;

        func_003bff30(param_2, (void (*)(void))func_00474a10, &callbackData);

        *(u32*)(*(int*)(param_1 + 0x18) + 8) = uVar1;

        for (puVar2 = (u32*)func_003df890(*(u32*)(*(int*)(param_1 + 0x18) + 8));
             puVar3 = (u32*)func_003df8a0(*(u32*)(*(int*)(param_1 + 0x18) + 8)),
             puVar2 != puVar3; puVar2 = puVar2 + 1) {
            userData = func_00474ce0((void*)*puVar2);

            if (((userData != 0) && (func_00442c30(userData, &gp0xffff9d10, 5) == 0)) &&
                (animation = func_003d8130(*puVar2, 0), animation != 0)) {
                func_003d5990(animation, func_00474ba0, 0);

                *(u8**)((int)animation + 0x40) = LAB_00474a50_abs;
                *(u8**)((int)animation + 0x44) = LAB_00474a90_abs;
            }
        }
    }

    return;
}
#endif /* P4_UNIT_00474DF0 */

#if defined(P4_UNIT_00476E10)
/* Source unit: src/Graphics/Model/mdlManager_00476e10.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00315ed0 (verified MATCH there). */
#include "type.h"

extern void func_004585c0();

// FUN_00476E10
void* func_00476e10(void* param_1)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    iVar1 = *(int*)((int)param_1 + 0x18);
    uVar2 = *(u32*)(iVar1 + 0x24);
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
        func_004585c0(((u32*)*(int*)(iVar1 + 0x20))[uVar3]);
    }

    return param_1;
}
#endif /* P4_UNIT_00476E10 */

#if defined(P4_UNIT_00477260)
/* Source unit: src/Graphics/Model/mdlManager_00477260.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00316320 (verified MATCH there). */
#include "type.h"

extern void func_003bff30(u64 object, void* callback, void* data);
extern u32 func_00476e90(void* param_1, u32* param_2);

// FUN_00477260
void func_00477260(u64 param_1, u32* param_2, u16 param_3)
{
    struct {
        u32* ptr;
        u16 value;
    } context;

    context.ptr = param_2;
    context.value = param_3;
    func_003bff30(param_1, (void*)func_00476e90, &context);
    return;
}
#endif /* P4_UNIT_00477260 */

#if defined(P4_UNIT_004772A0)
/* Source unit: src/Graphics/Model/mdlManager_004772a0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00316360 (verified MATCH there). */
#include "type.h"

extern s32 K_Clump_MatUsrDataGetInt();

// FUN_004772A0
u32 func_004772a0(void* param_1, u32* param_2)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    u32* entries;

    iVar1 = *(int*)((int)param_1 + 0x18);
    uVar2 = *(u32*)(iVar1 + 0x24);
    uVar4 = 0;
    while (uVar4 < uVar2) {
        entries = *(u32**)(iVar1 + 0x20);
        uVar3 = K_Clump_MatUsrDataGetInt(entries[uVar4], "per3modelMatColor");
        if (uVar3 >> 0x18 != 0) {
            *param_2 = 0;
            return 0;
        }
        uVar4 = uVar4 + 1;
    }
    return (u32)param_1;
}
#endif /* P4_UNIT_004772A0 */

#if defined(P4_UNIT_004789C0)
/* Source unit: src/Graphics/Model/mdlManager_004789c0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003176c0 (verified MATCH there). */
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

// Model: mat 0x00, identityMat 0x40, clump 0xdc (layout from P3FES include/Graphics/Model/mdlManager.h).
typedef struct Model
{
    RwMatrix mat;         // 0x00
    RwMatrix identityMat; // 0x40
    RwV3d scale;          // 0x80
    u8 unkData0[0x50];    // 0x8c..0xdc
    void* clump;          // 0xdc
} Model;

extern void* RwMatrixMultiply(void* dst, void* left, void* right);
extern void func_003e9cb0(void* frame, void* matrix, u32 flags);
extern void func_0047aee0(void* mdl, void* matrix);

// FUN_004789C0
void func_004789c0(Model* mdl)
{
    RwMatrix matrix;
    void* frame;

    frame = *(void**)((u8*)mdl->clump + 4);
    RwMatrixMultiply(&matrix, &mdl->identityMat, (void*)mdl);
    func_003e9cb0(frame, &matrix, 0);
    func_0047aee0(mdl, &matrix);
}
#endif /* P4_UNIT_004789C0 */

#if defined(P4_UNIT_0047A1E0)
/* Source unit: src/Graphics/Model/mdlManager_0047a1e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_00318a90 mdlScale (verified MATCH there). */
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

// Model: mat 0x00, scale 0x80 (layout from P3FES include/Graphics/Model/mdlManager.h).
typedef struct Model
{
    RwMatrix mat;         // 0x00
    RwMatrix identityMat; // 0x40
    RwV3d scale;          // 0x80
} Model;

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

// FUN_0047A1E0
void mdlScale(Model* mdl, const RwV3d* scale, int combineOp)
{
    mdl->scale = *scale;
    RwMatrixScale(&mdl->mat, scale, combineOp);
}
#endif /* P4_UNIT_0047A1E0 */

#include "include_asm.h"
/* Source unit: src/Graphics/Model/mdlManager_004711e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003115a0 (verified MATCH there). */
#include "type.h"

extern u32 func_00397460(void);
typedef void (*CallbackFn)(void);
extern void func_003e9af0(void* object, CallbackFn callback, void* data);

extern void func_003b83d0(void);

extern void func_003e0c90(void);
extern void func_003e0870(void);
extern void func_003e0e20(void);
extern f32 DAT_0076112c;
extern void func_0039a260(void* a, void* b);
extern void func_0039ab20(void* a, int b, int c, int d);
extern int func_00475b90(void* buf, void* v, u32 idx, void* obj);
extern void* func_00457f40(void* obj, void* name, u32 idx);
extern u8* func_003e9700(void* a);
extern void func_003d5840(void* a, void* b);

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
extern code DAT_00922ba0_abs[];
extern u8 DAT_00922ba4_abs[];
extern u8 DAT_00922ba8_abs[];
extern u8 DAT_00922bac_abs[];

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

extern u32 func_00399d80();
extern u32 func_0039b6e0();

extern u32 func_003b83f0(int object);
extern u32 func_003b8500(int object);
extern void func_00473140(int param_1);

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

extern void func_003df7f0();
extern void func_003d6230();

extern void* func_003df890();
extern void* func_003df8a0();
extern void* func_003df6e0(void* list, s32 index);

extern void func_003c21e0(u32 object, u32 arg1, u32 arg2);
extern void func_003d5e40_typed(f32 frame, void* interpolator);

extern int func_003bcfb0();
extern void* func_003bd000(void* material, int data);
extern char* func_003bd040(void* userData);
extern int func_003bd060(void* object);
extern int func_003bd050(void* userData);
extern void* func_003bd0b0(void* object, int index);
extern int strcmp(const char* s1, const char* s2);
extern char DAT_007641c8[1];

extern u32 func_003df5d0();
extern int func_00474970(int param_1, void* param_2);
extern void func_003bff30();
extern void* func_00477350(void*, void*);
extern void* func_00477430(void*);
extern void* func_00479880(void*);
extern void func_0047a4a0(void);
extern void func_004776c0(void);
extern void* func_00474a10(void* param_1, u32* param_2);
extern u32 func_00474ce0(void* param_1);
extern int func_00442c30();
extern int func_003d8130();
extern void func_003d5990();
extern void* func_00474ba0(void* param_1, void* param_2);
extern char gp0xffff9d10;
extern u8 LAB_00474a50;
extern u8 LAB_00474a50_abs[];
extern u8 LAB_00474a90;
extern u8 LAB_00474a90_abs[];

extern void* func_00397470(void);

extern void func_004585c0();
extern u32 func_00476e90(void* param_1, u32* param_2);
extern u32 func_004581a0(void* object, void* data);
extern u8 D_007131D8[];
extern f32 DAT_00761130;
extern u8 D_00713138[];
extern u8 D_007241d0;
extern void* D_00922BE0[];
extern void func_00440b68(void* a, void* b, int c);
extern u32 func_00454a60(void* a, int b);
extern void func_0044ea90(void* a, int b);
extern void func_0043f9c8(void* a, int b, int c);
extern void* DAT_008873e8[];
extern s64 DAT_00723cd8;
extern void func_004787e0(void);
extern void func_0048a000(void);
extern void* func_004779b0();
extern void func_004782b0(void* a);
extern void func_00478410(void* a, void* b);
extern void* func_003bfae0(void);
extern int func_003e8200(void* a, void* b);
extern void* D_008872E0[];
extern void func_0047af60(void* a);
extern void func_0047aff0(void* a, void* b);
extern void func_0047afd0(void* a, void* b);
typedef void (*FnVoidPtr)(void*);

extern s32 K_Clump_MatUsrDataGetInt();

typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;

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

// Model: mat 0x00, identityMat 0x40, scale 0x80, color 0xd0, clump 0xdc (layout from P3FES include/Graphics/Model/mdlManager.h).
typedef struct Model
{
    RwMatrix mat;         // 0x00
    RwMatrix identityMat; // 0x40
    RwV3d scale;          // 0x80
    u8 unkData0[0x44];    // 0x8c..0xd0
    RwRGBA color;         // 0xd0
    u8 unkData1[8];       // 0xd4..0xdc
    void* clump;          // 0xdc
} Model;

extern void* RwMatrixMultiply(void* dst, void* left, void* right);
extern void func_003e9cb0(void* frame, void* matrix, u32 flags);
extern void func_0047aee0(void* mdl, void* matrix);




// FUN_00470E90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00470e90);

// FUN_00471010
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471010);
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



// FUN_00471250
void* func_00471250(void* param_1)
{
    func_003b83d0();
    return param_1;
}



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

#pragma alias DAT_00922ba0_abs DAT_00922ba0
#pragma alias DAT_00922ba4_abs DAT_00922ba4
#pragma alias DAT_00922ba8_abs DAT_00922ba8
#pragma alias DAT_00922bac_abs DAT_00922bac



// FUN_00471370
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);
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




// FUN_00473000
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473000);
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




// FUN_00473350
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473350);

// FUN_00473520
void func_00473520(void* param_1)
{
    func_0043f9c8(param_1, 0, 0xA4);
    *(u8*)((u8*)param_1 + 2) = 1;
    *(s16*)((u8*)param_1 + 4) = -1;
    *(f32*)((u8*)param_1 + 8) = 1.0f;
    *(u32*)((u8*)param_1 + 0xC) = 0;
    *(s16*)((u8*)param_1 + 0x10) = -1;
    *(f32*)((u8*)param_1 + 0x1C) = 1.0f;
    *(f32*)((u8*)param_1 + 0x58) = DAT_0076112c;
    *(u32*)((u8*)param_1 + 0x64) = 0;
    *(u32*)((u8*)param_1 + 0x68) = 0;
    *(u32*)((u8*)param_1 + 0x6C) = 0;
    *(f32*)((u8*)param_1 + 0x70) = 1.0f;
    *(f32*)((u8*)param_1 + 0x5C) = 70.0f;
    *(f32*)((u8*)param_1 + 0x60) = 80.0f;
    *(u16*)((u8*)param_1 + 0x54) = 0;
    *(f32*)((u8*)param_1 + 0x84) = 1.0f;
    *(f32*)((u8*)param_1 + 0x88) = 1.0f;
    *(f32*)((u8*)param_1 + 0x8C) = 1.0f;
}

// FUN_004735B0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004735b0);

// FUN_00473710
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473710);

// FUN_00473870
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473870);

// FUN_00473B20
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473b20);

// FUN_004740C0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004740c0);
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




// FUN_004746B0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004746b0);
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
#pragma opt_propagation on



// FUN_00474A10
void* func_00474a10(void* param_1, u32* param_2)
{
    func_003c21e0(*(u32*)((u8*)param_1 + 0x18), *param_2, param_2[1]);
    return param_1;
}


#pragma alias func_003d5e40_typed func_003d5e40



// FUN_00474A50
void func_00474a50(void* param_1, void* param_2)
{
    *(float*)((u8*)param_1 + 0x8) = *(float*)((u8*)param_2 + 0x8);
    *(float*)((u8*)param_1 + 0xC) = *(float*)((u8*)param_2 + 0xC);
    *(float*)((u8*)param_1 + 0x10) = *(float*)((u8*)param_2 + 0x10);
    *(float*)((u8*)param_1 + 0x14) = *(float*)((u8*)param_2 + 0x14);
    *(float*)((u8*)param_1 + 0x18) = *(float*)((u8*)param_2 + 0x18);
    *(float*)((u8*)param_1 + 0x1C) = *(float*)((u8*)param_2 + 0x1C);
}

// FUN_00474A90
void func_00474a90(void* param_1, void* param_2)
{
    *(float*)((u8*)param_1 + 0x8) = *(float*)((u8*)param_2 + 0x8);
    *(float*)((u8*)param_1 + 0xC) = *(float*)((u8*)param_2 + 0xC);
    *(float*)((u8*)param_1 + 0x10) = *(float*)((u8*)param_2 + 0x10);
    *(float*)((u8*)param_1 + 0x14) = *(float*)((u8*)param_2 + 0x14);
    *(float*)((u8*)param_1 + 0x18) = *(float*)((u8*)param_2 + 0x18);
    *(float*)((u8*)param_1 + 0x1C) = *(float*)((u8*)param_2 + 0x1C);
}

// FUN_00474AD0
void func_00474ad0(void) {}

// FUN_00474AE0
void func_00474ae0(void) {}
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




// FUN_00474BA0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00474ba0);

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

#pragma alias LAB_00474a50_abs LAB_00474a50
#pragma alias LAB_00474a90_abs LAB_00474a90


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




// FUN_00474F40
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00474f40);
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




// FUN_00475170
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475170);

// FUN_00475350
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475350);

// FUN_00475820
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475820);
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




// FUN_00475B90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475b90);

// FUN_00475CD0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475cd0);

// FUN_00476C70
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00476c70);
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




// FUN_00476E90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00476e90);
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



// FUN_00477350
void* func_00477350(void* param_1, void* param_2)
{
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = *(void**)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        if ((func_00399d80(e) & 2) != 0) {
            func_0039a260(e, *(void**)((u8*)param_2 + 0));
        }
        i++;
    }
    return param_1;
}

// FUN_00477400
void func_00477400(void* param_1, int param_2)
{
    func_003bff30(param_1, func_00477350, &param_2);
}

// FUN_00477430
void* func_00477430(void* param_1)
{
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = *(void**)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        if ((func_00399d80(e) & 2) != 0) {
            func_0039ab20(e, 2, 3, 0x73001);
        }
        i++;
    }
    return param_1;
}

// FUN_004774E0
void func_004774e0(void* param_1)
{
    func_003bff30(param_1, func_00477430, 0);
}

// FUN_00477510
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00477510);

// FUN_00477660
void* func_00477660(void* param_1, RwV3d* param_2)
{
    void* p = *(void**)((u8*)param_1 + 0x18);
    u32 count = *(u32*)((u8*)p + 0x24);
    u32 i = 0;
    while (i < count) {
        void* e = *(void**)((u8*)*(void**)((u8*)p + 0x20) + i * 4);
        *(RwV3d*)((u8*)e + 0xC) = *param_2;
        i++;
    }
    return param_1;
}

// FUN_004776C0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004776c0);

// FUN_004777D0
void func_004777d0(void* param_1, int param_2, u8 param_3)
{
    struct {
        u8 b;
        int i;
    } s;
    s.b = param_3;
    s.i = param_2;
    func_003bff30(*(void**)((u8*)param_1 + 0xDC), func_004776c0, &s);
}

// FUN_00477810
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00477810);
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
#pragma opt_loop_invariants off




// FUN_004779B0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004779b0);

// FUN_00477C40
void* func_00477c40(u32 param_1, u32 param_2, u32 param_3)
{
    void* node = D_00922BE0[param_1 & 0xFFFF];
    u32 v1 = param_2 & 0xFFFF;
    u32 v2 = param_3 & 0xFFFF;
    while (node != 0) {
        if (*(u16*)((u8*)node + 0xD6) == v1 &&
            (v2 == 0 || (*(u32*)((u8*)node + 0xD8) & v2) != 0)) {
            break;
        }
        node = *(void**)((u8*)node + 0x308);
    }
    return node;
}

// FUN_00477CA0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00477ca0);

// FUN_00477E80
void* func_00477e80(void* param_1, void* param_2, void* param_3, u32 param_4)
{
    void* obj = func_004779b0();
    if ((param_4 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    func_0047aff0(obj, param_3);
    func_004782b0(obj);
    return obj;
}

// FUN_00477F10
void* func_00477f10(void* param_1, void* param_2, int param_3, int param_4, u32 param_5)
{
    void* obj = func_004779b0();
    if ((param_5 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    {
        int tmp[2];
        tmp[0] = param_3;
        tmp[1] = param_4;
        func_0047afd0(obj, tmp);
    }
    func_004782b0(obj);
    return obj;
}

// FUN_00477FB0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00477fb0);

// FUN_00478140
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478140);

// FUN_004782B0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004782b0);

// FUN_00478410
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478410);

// FUN_00478750
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478750);

// FUN_004787E0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004787e0);
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




// FUN_00478A30
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478a30);

// FUN_00478EA0
void func_00478ea0(void* param_1, int param_2, int param_3)
{
    *(int*)((u8*)param_1 + 0x310) = param_2;
    *(int*)((u8*)param_1 + 0x314) = param_3;
}

// FUN_00478EB0
void func_00478eb0(void* param_1, int param_2, int param_3)
{
    *(int*)((u8*)param_1 + 0x318) = param_2;
    *(int*)((u8*)param_1 + 0x31C) = param_3;
}

// FUN_00478EC0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478ec0);

// FUN_00479080
void func_00479080(void* param_1, void* param_2)
{
    u32* p = (u32*)param_2;
    if ((p[0xD8 / 4] & 0x40000) != 0) {
        DAT_00723cd8 &= ~0x80;
    }
    if ((p[0xD8 / 4] & 0x100000) != 0) {
        func_0048a000();
    }
    if (*(void**)((u8*)p + 0x318) != 0) {
        ((FnVoidPtr)*(void**)((u8*)p + 0x318))(*(void**)((u8*)p + 0x31C));
    }
}

// FUN_00479100
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479100);

// FUN_00479880
void* func_00479880(void* param_1)
{
    if ((*(u8*)((u8*)param_1 + 2) & 4) == 0) {
        return param_1;
    }
    if (*(void**)((u8*)param_1 + 0x18) != 0) {
        if (func_003e8200(D_008872E0[0], func_003bfae0()) != 0) {
            ((FnVoidPtr)*(void**)((u8*)param_1 + 0x48))(param_1);
        }
    }
    return param_1;
}

// FUN_00479910
void func_00479910(void* param_1)
{
    func_003bff30(param_1, func_00479880, 0);
}

// FUN_00479940
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479940);

// FUN_00479CA0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479ca0);

// FUN_00479D10
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479d10);

// FUN_00479DD0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479dd0);

// FUN_00479E60
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479e60);

// FUN_00479F60
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479f60);

// FUN_0047A000
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a000);

// FUN_0047A080
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a080);

// FUN_0047A0E0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a0e0);

// FUN_0047A120
void func_0047a120(void* param_1)
{
    void* p = *(void**)((u8*)param_1 + 0x120);
    if (p != 0 && *(void**)((u8*)p + 4) != 0) {
        *(u16*)((u8*)param_1 + 0xEC) |= 0x80;
    }
}

// FUN_0047A150
void func_0047a150(void* param_1)
{
    void* p = *(void**)((u8*)param_1 + 0x120);
    if (p != 0 && *(void**)((u8*)p + 4) != 0) {
        *(u16*)((u8*)param_1 + 0xEC) &= 0xFF7F;
    }
}

// FUN_0047A180
void func_0047a180(void)
{
    func_003e0c90();
}

// FUN_0047A1A0
void func_0047a1a0(void)
{
    func_003e0870();
}

// FUN_0047A1C0
void func_0047a1c0(void)
{
    func_003e0e20();
}
// FUN_0047A1E0
void mdlScale(Model* mdl, const RwV3d* scale, int combineOp)
{
    mdl->scale = *scale;
    RwMatrixScale(&mdl->mat, scale, combineOp);
}



// FUN_0047A220
void mdlSetColor(Model* mdl, const RwRGBA* color)
{
    mdl->color = *color;
}




// FUN_0047A260
void func_0047a260(void* param_1)
{
    struct {
        void* ptr;
        u16 v;
    } s;
    void* arg0 = *(void**)((u8*)param_1 + 0xDC);
    s.ptr = (u8*)param_1 + 0xD0;
    s.v = 0;
    func_003bff30(arg0, func_00476e90, &s);
}
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

// FUN_0047A320
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a320);

// FUN_0047A4A0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a4a0);

// FUN_0047A4D0
void func_0047a4d0(void* param_1, int param_2)
{
    func_003bff30(*(void**)((u8*)param_1 + 0xDC), func_0047a4a0, &param_2);
}

// FUN_0047A510
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a510);

// FUN_0047A6D0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a6d0);

// FUN_0047A7C0
u32 func_0047a7c0(void* param_1)
{
    u16* p = *(u16**)((u8*)param_1 + 0x2C8);
    if (p != 0) {
        return p[0];
    }
    return func_004581a0(*(void**)((u8*)param_1 + 0xDC), D_007131D8);
}

// FUN_0047A810
void func_0047a810(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) |= 1;
}

// FUN_0047A830
void func_0047a830(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) &= ~1;
}

// FUN_0047A850
void func_0047a850(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) |= 0x20;
}

// FUN_0047A870
void func_0047a870(void* param_1)
{
    *(u32*)((u8*)param_1 + 0xD8) &= ~0x20;
}

// FUN_0047A890
void func_0047a890(void* param_1, float param_2)
{
    *(float*)((u8*)param_1 + 0x144) = param_2;
}

// FUN_0047A8A0
void func_0047a8a0(void* param_1, float param_2, float param_3)
{
    *(float*)((u8*)param_1 + 0x148) = param_2;
    *(float*)((u8*)param_1 + 0x14C) = param_3;
}

// FUN_0047A8B0
void func_0047a8b0(void* param_1, RwV3d* param_2)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x40;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFF5F;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(RwV3d*)((u8*)param_1 + 0x17C) = *param_2;
}

// FUN_0047A900
void func_0047a900(void* param_1, RwV3d* param_2)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x20;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFF3F;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(RwV3d*)((u8*)param_1 + 0x17C) = *param_2;
}

// FUN_0047A950
void func_0047a950(void* param_1, float param_2, float param_3)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x8000;
    *(u16*)((u8*)param_1 + 0x140) &= 0xFEFF;
    *(float*)((u8*)param_1 + 0x188) = param_2;
    *(float*)((u8*)param_1 + 0x18C) = param_3;
}

// FUN_0047A980
void* func_0047a980(void* param_1)
{
    return (char*)param_1 + 0x150;
}

// FUN_0047A990
void func_0047a990(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x100;
}

// FUN_0047A9B0
void func_0047a9b0(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x140) |= 0x200;
}

// FUN_0047A9D0
int func_0047a9d0(void* param_1)
{
    return (*(u16*)((u8*)param_1 + 0x140) & 0x81E0) != 0;
}

// FUN_0047A9F0
void func_0047a9f0(void* param_1, u16 param_2)
{
    *(u16*)((u8*)param_1 + 0x140) = param_2;
}

// FUN_0047AA00
u16 func_0047aa00(void* param_1)
{
    return *(u16*)((u8*)param_1 + 0x140);
}

// FUN_0047AA10
void func_0047aa10(void* param_1, RwV3d* param_2)
{
    *(RwV3d*)((u8*)param_1 + 0x170) = *param_2;
}

// FUN_0047AA30
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047aa30);

// FUN_0047AAA0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047aaa0);

// FUN_0047AB90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047ab90);

// FUN_0047AC90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047ac90);

// FUN_0047AE10
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047ae10);

// FUN_0047AEE0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047aee0);

// FUN_0047AF60
void func_0047af60(void* param_1)
{
    void* obj;
    func_0044ea90(D_00713138, 0x1769);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(0x48, 0x40000);
    *(void**)((u8*)param_1 + 0x30C) = obj;
    func_0043f9c8(obj, 0, 0x48);
}

// FUN_0047AFD0
void func_0047afd0(void* param_1, void* param_2)
{
    void* obj = *(void**)((u8*)param_1 + 0x30C);
    *(u32*)((u8*)obj + 0x2C) = *(u32*)param_2;
    *(u32*)((u8*)obj + 0x30) = *(u32*)((u8*)param_2 + 4);
}

// FUN_0047AFF0
void func_0047aff0(void* param_1, void* param_2)
{
    void* obj = *(void**)((u8*)param_1 + 0x30C);
    func_00440b68(&D_007241d0, D_00713138, 0x1786);
    *(u32*)((u8*)obj + 0x38) = func_00454a60(param_2, 0);
    *(u32*)((u8*)obj + 0x0) = 0;
}

// FUN_0047B050
void func_0047b050(void* param_1, int param_2)
{
    *(int*)((u8*)*(void**)((u8*)param_1 + 0x30C) + 0x40) = param_2;
}

// FUN_0047B060
void func_0047b060(void* param_1)
{
    u32* m = (u32*)param_1;
    void* obj = (void*)m[0x30C / 4];
    if (*(void**)((u8*)obj + 0xC) != 0) {
        DAT_008873ec[0](*(void**)((u8*)obj + 0xC));
    }
    DAT_008873ec[0]((void*)m[0x30C / 4]);
    m[0x30C / 4] = 0;
}

// FUN_0047B0C0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047b0c0);

// FUN_0047C660
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047c660);

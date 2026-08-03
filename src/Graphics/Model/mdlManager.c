#include "include_asm.h"
/* Source unit: src/Graphics/Model/mdlManager_004711e0.c */
/* Ported from P3FES src/Graphics/Model/mdlManager.c FUN_003115a0 (verified MATCH there). */
#include "type.h"
extern f32 iGpffff8040;
extern f32 fGpffff809c;
extern u8 D_00713180[];
extern u8 D_007131A0[];
extern u8 D_007131C0[];
extern s32 func_00457a90(void* a, u8* b);
extern f32 func_004579a0(void* a, u8* b);

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
extern f32 D_00922BB0_abs[];
extern f32 D_00922BB4_abs[];
extern u8 D_00922BC0;
extern u8 D_00922BC0_abs[];

extern void RwMatrixScale(void* matrix, const RwV3d* scale, int combineOp);

extern u32 func_00399d80();
extern u32 func_0039b6e0();

extern u32 func_003b83f0(int object);
extern u32 func_003b85b0(void* object);
extern void func_003b8520(void* object, int value);
extern void func_00399b10(void* object);
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
extern void* func_004776c0(void* param_1, void* param_2);
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
extern void* func_00397470_typed(void* a);
#pragma alias func_00397470_typed func_00397470
extern void func_003e05f0(void* a, void* b, void* c);

extern void func_004585c0();
extern u8* func_00476e90(u8* a, u8** b);
extern u32 func_004578b0();
extern f32 iGpffff8044;
extern u8 D_00713160[];
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
extern void func_004787e0(u8* a0);
extern void func_0048a000(void);
extern s32 func_004782b0(u8* a);
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
extern void func_0047d840();
extern void func_0047dda0();
extern void func_0047ea70();
extern void func_0047adf0();
extern s32 iGpffffbb28;
extern f32 iGpffff80cc;
extern void* func_004779b0();
extern s32 func_00479ca0(void* a, s32 b);
extern s32 func_003971d0();
extern s32 func_00462ae0();
extern void func_0047da30();
extern void* func_003c0520();
extern void* func_0047d200();
extern void* func_0047dc30();
extern void func_0047ea40();
extern s32 func_00479d10();
extern void func_0047fe90();
extern void func_0047eb20();
extern s32 func_0047ae90();
extern void func_00475350();
extern void func_00478410(u8* a, u8* b);




/* measured: mwcc b210 rematerializes the 1.0f and 0x20003 constants inside the
   loop body; #pragma opt_loop_invariants on hoists both to function top to
   match retail (nd 54 -> 0). */
// FUN_00470E90
#pragma opt_loop_invariants on
u8* func_00470e90(u16 arg0)
{
    s32 size;
    u8* obj;
    u32 i;

    size = (s32)arg0 * 0x50 + 0x10;
    func_0044ea90(D_00713138, 0x142);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(size, 0x40000);
    func_0043f9c8(obj, 0, size);
    *(u8**)(obj + 0) = obj + 0x10;
    *(u16*)(obj + 8) = arg0;
    for (i = 0; i < *(u16*)(obj + 8); i++) {
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x28) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x14) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x00) = 0x3F800000;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x10) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x08) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x04) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x24) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x20) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x18) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x38) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x34) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x30) = 0;
        *(s32*)(*(u8**)(obj + 0) + i * 0x50 + 0x0C) |= 0x20003;
    }
    *(s16*)(obj + 0xA) = 1;
    return obj;
}
#pragma opt_loop_invariants off

/* measured: retail re-issues andi $3,$19,0xffff on (u16)i in BOTH the loop
   test (0x471188) and the loop body (0x47106c, feeding the *0x50 chain);
   mwcc b210 CSEs the mask across the loop back-edge and reuses the test's
   masked register, leaving the object exactly 1 word (4B) short of retail.
   Tried (u16) casts on s32 counter, u16-width intermediate, base-load-first
   statement order, unsigned compares; all nd ~6 with only that andi missing.
   CSE-of-mask floor family. */
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
#pragma alias D_00922BC0_abs D_00922BC0
#pragma alias D_00922BB0_abs D_00922BB0
#pragma alias D_00922BB4_abs D_00922BB4



/* measured: blocked by the same lhu+bltz u16 sign-test floor as func_00473b20/
   004740c0/00479100 (retail: lhu;bltz on the raw register at 0x372BEC; b210
   double-emits with a duplicated negative path in all 14 probed spellings).
   Not transcribed: 7104B window with a guaranteed ~6-word mismatch at the
   sign test cascading through the frame. */
// FUN_00471370
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);
extern void func_00397c40(void* a, void* b);
extern void func_00471370(void* a, void* b, void* c, void* d);
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
void func_00473000(u8* arg0, u8* arg1)
{
    u8* p5;
    u8* obj;
    u8* obj2;
    s32 count;
    s32 base;

    p5 = arg1 + 0x3C;
    obj = *(u8**)(arg0 + 0x20);
    if (obj != 0) {
        *(s32*)DAT_00922ba0_abs = *(s32*)(obj + 0x3C);
        *(s32*)(obj + 0x3C) = (s32)func_00472f30;
        obj2 = *(u8**)(arg0 + 0x20);
        count = *(s32*)(obj2 + 0x24);
        base = (s32)obj2 + 0x4C;
        *(s32*)DAT_00922ba4_abs = base;
        base = base + count * *(s32*)(p5 + 0);
        *(s32*)DAT_00922ba4_abs = base;
        if (*(f32*)(arg1 + 8) != 0.0f) {
            *(s32*)DAT_00922ba8_abs = base;
        } else {
            *(s32*)DAT_00922ba8_abs = 0;
        }
        *(float**)DAT_00922bac_abs = (float*)(p5 + 4);
        *(f32*)D_00922BB0_abs = *(f32*)(p5 + 0x10);
        *(f32*)D_00922BB4_abs = *(f32*)(p5 + 0x14);
        if ((*(u16*)(arg1 + 0x54) & 0x81E0) != 0) {
            func_00471370(arg0, arg1, arg1 + 0x54, 0);
            *(u16*)(arg1 + 0x54) |= 0x4000;
        } else {
            func_00397c40(arg0, p5);
            *(u16*)(arg1 + 0x54) &= 0xBFFF;
        }
        *(s32*)(*(u8**)(arg0 + 0x20) + 0x3C) = *(s32*)DAT_00922ba0_abs;
    }
}
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
void* func_00473350(void* arg0, u8* arg1)
{
    s16 rawIndex;
    s64 lVar2;
    u16 count;
    s32* t3;
    s32 off;
    u8* elem;
    void* p38;
    void* v;
    void* t;
    u8* p;
    f32 c;

    rawIndex = *(s16*)(arg1 + 4);
    t3 = *(s32**)(arg1 + 0x34);
    if (t3 != 0 &&
        (lVar2 = (s64)rawIndex, count = *(u16*)((u8*)t3 + 8),
         lVar2 < (s64)(u32)count) &&
        (off = rawIndex * 0x50, elem = *(u8**)(*(s32*)((u8*)t3 + 0) + 0x40 + off)) != 0 &&
        elem != D_00922BC0_abs) {
        if (!(*(u16*)(arg1 + 0) & 1)) {
            if (lVar2 < (s64)(u32)count && rawIndex >= 0) {
                t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
                func_003d5e40_typed(*(f32*)(elem + 0xC), t);
                *(u8*)(arg1 + 2) = 1;
            }
        } else {
            p38 = *(void**)(arg1 + 0x38);
            if (p38 != 0) {
                if (*(s32*)((u8*)p38 + 0x18) != 0) {
                    func_0047d840(*(s32*)((u8*)p38 + 0x18), rawIndex);
                }
                if (*(s32*)((u8*)p38 + 0x24) != 0) {
                    func_0047dda0(*(s32*)((u8*)p38 + 0x24));
                }
            }
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            func_003d5990(t, 0, 0);
            c = iGpffff8040;
            *(f32*)(arg1 + 0xC) = c * *(f32*)(arg1 + 8);
            p = (u8*)*(s32*)((u8*)*(s32**)(arg1 + 0x34) + 0);
            p += 0x4C;
            p += off;
            v = *(void**)p;
            if (v != 0) {
                *(f32*)(arg1 + 0xC) = *(f32*)(arg1 + 0xC) + c * (f32)(s32)*(s32*)v;
            }
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            func_003d5e40_typed(*(f32*)(arg1 + 0xC), t);
            t = *(void**)((u8*)*(void**)(arg1 + 0x20) + 0x20);
            func_003d5990(t, func_00473350, arg1);
        }
    } else if (*(u16*)(arg1 + 0) & 1) {
        *(f32*)(arg1 + 0xC) = 0.0f;
    }
    return arg0;
}

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

/* measured: retail allocates q=$s0, i=$s1, arg0=$s2, i*4=$s3; mwcc b210
   rotates to i*4=$s0, q=$s2, arg0=$s3 (25 words, all register names; u8*
   param typing fixed the arg0+0x38 address-CSE frame growth, nd 81 -> 25).
   Tried: q,i,idx and i,q,idx declaration orders (25/28), idx named local.
   Saved-register rotation floor. */
// FUN_004735B0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_004735b0);
/* measured: retail keeps arg0=$s0 and folds 0x20 into every reload
   (lw $a0,0x20($s0) after each call); mwcc b210 materializes arg0+0x20 into an
   s-reg (addiu $s0,$s2,0x20) and rotates the saved set (arg0 $s0->$s2,
   arg2 $s2->$s1, p4 $s1->$s0), nd 57. Tried: u8* params (78), u8** loads
   (78), s32 base locals (78), opt_propagation off (57). Address-CSE into
   s-reg floor (same family as 79e60/776c0/73000 pre-fix; u8* typing did not
   break it here). */
// FUN_00473710
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473710);

/* measured: 4 attempts, all nd 152. Structure, pointer math (3-op mult,
   base/stride/count reloads), the func_003d5bc0 2-arg call and the c.ole.s
   len2<=0 test all match. Residual: the fused mula/madda/madd.s chains (len2
   and the rotation terms) get their PRODUCT ORDER and registers permuted by
   b210 vs retail (e.g. mine mula t1*t0 where retail mula t0*t0, second chain
   mula/madda pair swapped) - same family as btlEPL func_001fceb0/001fe090
   mula/madd FP-scheduling floors; the p1 vec4 (retail swc1/lwc1 sp30-3C
   spill+reload) stays in registers; the 1.0f/0.0f constants are not hoisted
   out of the loop (opt_loop_invariants on at function scope and inline:
   no effect); everything downstream rotates by one FP register. */
// FUN_00473870
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473870);

extern void func_00473870(void* a);
extern void func_003d5e40(void* a, f32 b);
extern void func_003d5e90(void* a, void* b, void* c, f32 d);
extern void func_003d5bc0(void* a, void* b, f32 c);
extern void func_00397c40_1(void* a);
#pragma alias func_00397c40_1 func_00397c40
/* measured: nd 244 after 4 attempts; registers/decl-order/chains/calls all
   match (off16:$s0, idx:$s1, obj:$s4, arg1:$s3, arg2:$s2; dsll32/dsra32 sIdx
   materializations; func_003d5e90/5840/5bc0/5e40 sites; 0x73E74 chain2 and
   the 0x73F48 block; switch of 0x73E74 chain1+2 logic; sp[3]...). Remaining:
   (1) the u16 v18 sign test (0x73D30/0x73E18): retail emits lhu;bltz on the
   raw register; mwcc b210 emits andi 0xffff load-normalization + dsll32/
   dsra32 (s16) cast materializations, or dead bgez/beqz folds when it range-
   tracks the u16 load — probed 8 spellings (u16/u32/s32 locals, (s16)/(s32)
   casts, inline loads, <0 and >=0 forms, -O2), none give lhu;bltz (2 blocks
   x 3+ words); (2) single-use X+0x40 bases fold into the load displacement
   (lw 0x40) where retail keeps addiu;addu;lw 0 — only two-use bases (CSE'd,
   e.g. 0x73C80 chain) keep the addiu (3 sites, 1 word each); (3) the
   adda/madd block: retail loads iGpffff8040 before the value and colors the
   cvt result $f1 vs b210's value-load-first + $f2 rotation; (4) 0x73E74
   chain2 loads the base before the sll chain, b210 emits chain-first. */
// FUN_00473B20
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00473b20);
extern void* func_003d5790();
extern void func_003d59a0(void* a, void* b);
/* measured: nd 237 (object 1344B vs 1328B) after 1 attempt; registers,
   chains, calls, 0x48-block re-derivations and tail all match (temp16:$s0,
   temp20:$s4, obj:$s3, idx:$s2, a2:$s1; func_003d5790 5-arg/2-arg sites;
   entry48 two-use first derivation keeps the addiu while the 5 re-derivation
   stores fold 0x48 into the load, exactly like retail). Remaining: (1) the
   u16 sign test at 0x74508 (lhu;bltz on the raw register): b210 emits
   lhu;bltz;bltz with a duplicated negative path in every spelling — same
   store-reload u16-sign-test floor as func_00473b20 (14 probe spellings);
   (2) single-use X+C address bases fold into the load displacement (lw C)
   where retail keeps addiu;addu;lw 0 — 5 sites (else-chain v1, p4C x2,
   entry48, entry2); only the two-use base6 keeps its addiu; (3) the first
   chain's v1 load: retail computes idx*0x50 before the base load, b210 loads
   base first; (4) the 5840-1 address: retail loads base before the lh chain,
   b210 interleaves. */
/* Wave 7 ran out of turns partway through adapting this body and left it
   uncompilable (a func_003d5840 call with the wrong arity). Reverted; the
   previously measured nd 237 note for this function stands. */
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




extern void func_0047ffc0(void* a);
/* measured: u8* params fixed the param_2+0xC address-CSE (nd 106 -> 54) and
   the func_0047fd10 call needs FOUR args (e2, e, *(p2+0x14), 0.0f — the
   a1=$s0 move is deliberate, fixing it removes the shift). Residual
   (nd 54-79): the s16 t lands in $a2 vs retail $a1, the f32 alpha local lands
   in $f13 (arg reg, dead before calls) vs retail $f14 (forcing the
   mov.s $f13,$f14 in the fe90 call), and the fd10 arg materialization order
   (move/lwc1) swaps. Tried: one=1.0f local, alpha/one decl order, void*
   params. FP/integer register-allocation floor. */
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




/* measured: retail reloads t (lh) and obj (lw) at the second path and sign-
   extends t (dsll32/dsra32) BEFORE the first compare in both paths; mwcc b210
   CSEs BOTH second-path loads across the branch in every spelling (goto
   layout with inline p1 block matches retail's block order 1:1, best nd 48:
   p2 re-dances the CSE'd $a2 and keeps obj in $a1 vs retail's lh $v1/lw $v0;
   the dance is emitted lazily after the slt, retail eagerly before the count
   load; comma forms booleanize != NULL / != 0 into sltu, nd 70; volatile u8*
   param did not re-issue the loads - the (u8*) casts drop the qualifier).
   Tried: t-first comma form, obj-first m2c form, s32/s16 t, separate e/n
   locals, goto p1-inline form, volatile pointee. Load-CSE +
   sign-extension-placement floor. */
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
void* func_00474f40(void* arg0)
{
    void* obj;
    s32 count;
    s32 i;
    s32 flag;
    s32 t;

    obj = *(void**)((u8*)arg0 + 0x18);
    if (obj == 0) {
        return arg0;
    }
    flag = 0;
    count = *(s32*)((u8*)obj + 0x24);
    i = 0;
    while (i < count && flag == 0) {
        if (func_00399d80(*(void**)((u8*)*(void**)((u8*)obj + 0x20) + i * 4)) != 0) {
            flag = 1;
        }
        i++;
    }
    if (func_003b83f0((int)obj) != 0) {
        t = func_003b85b0(arg0);
        switch (t) {
        case 0:
        case 3:
            break;
        default:
        case 1:
        case 2:
            if (flag != 0) {
                func_003b8520(arg0, 2);
            } else {
                func_003b8520(arg0, 1);
            }
            break;
        }
    } else if (flag != 0) {
        func_00399b10(arg0);
    }
    return arg0;
}
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




/* measured: MATCHED this wave (nd 0) — the old note's nd 111 floor was an
   artifact of the || / if-else-if dispatch spelling. Working spelling:
   switch(func_00399d80(*it)){case 5: case 6:} reproduces retail's
   beq 6/beq 5/b-skip with the body out of line; the cb checks must compare
   and store *(void**)(obj2+0x40) against (void*)func_00474a50/00474a90
   (u32 casts also work, void* keeps mwcc from adding conversions);
   re-read arg0->0x18 fresh for `list` (retail re-issues the lw). */
// FUN_00475170
void func_00475170(u8* arg0, f32 fparg0)
{
    u32* it;
    u32 list;
    u8* obj2;

    obj2 = *(u8**)(arg0 + 0x18);
    if (obj2 != 0 && *(u32*)(obj2 + 8) != 0) {
        *(f32*)(arg0 + 0xC) = fparg0;
        *(f32*)(arg0 + 0x10) = fparg0;
        list = *(u32*)(*(u8**)(arg0 + 0x18) + 8);
        it = (u32*)func_003df890(list);
        while (it != (u32*)func_003df8a0(list)) {
            switch (func_00399d80(*it)) {
            case 5:
            case 6:
                obj2 = (u8*)func_003d8130(*it, 0);
                if (obj2 != 0) {
                    if (*(void**)(obj2 + 0x40) == (void*)func_00474a50 &&
                        *(void**)(obj2 + 0x44) == (void*)func_00474a90) {
                        func_003d5e40(obj2, fparg0);
                        *(void**)(obj2 + 0x40) = (void*)func_00474a50;
                        *(void**)(obj2 + 0x44) = (void*)func_00474a90;
                    } else {
                        func_003d5e40(obj2, fparg0);
                    }
                }
                if (*(u8*)(arg0 + 2) != 1) {
                    obj2 = (u8*)func_003d8130(*it, 1);
                    if (obj2 != 0) {
                        if (*(void**)(obj2 + 0x40) == (void*)func_00474a50 &&
                            *(void**)(obj2 + 0x44) == (void*)func_00474a90) {
                            func_003d5e40(obj2, fparg0);
                            *(void**)(obj2 + 0x40) = (void*)func_00474a50;
                            *(void**)(obj2 + 0x44) = (void*)func_00474a90;
                        } else {
                            func_003d5e40(obj2, fparg0);
                        }
                    }
                }
                break;
            }
            it++;
        }
    }
}

/* measured: 4 attempts (nd 245/253/252/248). Working spellings: the
   type==6/5 dispatch must be switch(t){case 5: case 6:} to reproduce retail's
   beq/beq/b with the body out of line (|| range-optimizes, if/else-if
   duplicates the 9a700 call); the u_long128 spA0 read must be *(s32*)&spA0
   (typed alias, wave rule 3) to keep the sq/lq at 0xA0($sp) - (s32)spA0 keeps
   it in a register; arg3 must be u16 (s16 emits a dsll32/dsra32 dance before
   the andi 0xFFFF); arg4 needs the explicit double mask `arg4 & 0xFFFF & 1`;
   the (s64)(s16)arg2 dance is right (m2c's (arg2<<0x30)>>0x30 FOLDS TO ZERO
   under b210 with narrow args - do not use). Residual: arg2 gets spilled to
   the stack slot 0xAE instead of retail's $s1 (saved-register pressure), the
   val*8 chain is re-derived per loop iteration where retail hoists
   sll $s7,$v1,3 before the loop, and a general saved-register rotation
   (mine arg0:$s5/arg1:$s0/iter:$s3/list:$s4/t:$s1/obj:$s2/t30:$s7 vs retail
   arg0:$s5/arg1:$s2/arg2:$s1/iter:$s0/list:$s6/obj:$s3/t+e2:$s4/t30:$fp).
   Saved-register-rotation + LICM floor. */
// FUN_00475350
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475350);

/* measured: 4 attempts (nd 174/173/173/174, obj 780B vs window 752B: over).
   Logic and call sequence fully transcribed and matching; retail saves 4
   s-regs ($16-19), b210 hoists the elem+0x40/0x44 STORE addresses into saved
   regs $s4/$s5 (addiu $s5,$s0,0x40; sw ($s5)) across the func_003d5e40/
   003d5990 calls where retail folds 0x40($s0) per store - the recorded
   Address-CSE-into-s-reg floor family (79e60/776c0/73710/735b0) - plus the
   type==6||type==5 dispatch compiles to a range test (addiu -5/sltiu 2) in
   the || form and to beq+bne with the work block inline in the goto/&&/switch
   forms (retail: beq 6; beq 5; b skip with the body out of line), and the
   (arg0+2)==1 branch inverts (retail branches to the out-of-line ==1 block;
   b210 inlines it under a negated skip in every if/else and switch spelling).
   Branch-placement + address-CSE floor. */
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




/* measured: retail places the x != func_00397470(obj) setup block OUT OF LINE
   (bne -> setup; fall-through b -> join, +8B); mwcc b210 inlines it under a
   negated skip (beq -> join), and the switch lever materializes the boolean
   (xor/sltiu/beqz, nd 35) instead of a branch. Loop t-regs permute too
   (count $t1<->$t0, i $v1<->$t1) with the second-path mask self-masking
   (andi $v1,$v1) vs retail re-masking the counter. Tried: if/else forms,
   empty-then, switch case 0/1, i-init order, s32 count (fixed the u16
   re-mask). Branch-placement + t-coloring floor, best nd 35. */
// FUN_00475B90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475b90);
/* measured: 1 transcription attempt (nd 889 of 0xFA0). The whole body is
   readable C (byte-adjust 0x280/281/282, alpha conversion, quaternion dot +
   acos + slerp-style polynomial interp with gp slots iGpffff8054/8058/805c/
   8060/81cc/81fc, the 0xC0 identity matrix block, D_00887300/D_00887304
   dispatch, 0x124/0x28C loops, 0x28C/0x290/0x294 slots) but the fused
   mula/madda/madd.s chains and the 40+ stack f32 locals get reordered and
   re-allocated by b210 vs retail (the same mula/madd FP-scheduling family as
   func_00473870/btlEPL func_001fceb0 - never reproduced byte-for-byte), and
   the frame/stack-slot layout diverges (retail spills the sp70-8C vec to
   fixed slots 0x70-0x8C; b210 keeps them in registers and rotates). Fixes
   verified while transcribing: func_00397c40 is 1-arg here (use
   func_00397c40_1 alias); func_0047a2f0 is called with ONE arg (alias
   func_0047a2f0_1); func_00477260's first arg wants an explicit (u64) cast;
   D_00887300[] is an array (D_00887300[0](...)). FP-scheduling +
   stack-layout floor. */
// FUN_00475CD0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00475cd0);

/* measured: the D3/7000F branch condition is (f&0x200)!=0 && (f&0x400)==0
   (the 0x400-beqz goes to the D3 part, not the 7000F). Residual: mwcc b210
   materializes param_1+0xD8 into $s0 (frame 0x40 vs 0x50, retail keeps the
   D_00887300 base in $s0) and mirrors the block layout (D3 inline + 7000F
   out-of-line vs retail's 7000F inline + D3 out-of-line). Tried: u8* params
   (94), condition flips. Address-CSE + if-placement floor. */
typedef struct MdlFlags78ec0
{
    u8 pad0[0xD0];
    void* d0;   /* 0xD0 */
    u8 pad0b[4];
    u32 d8;     /* 0xD8 */
    void* dc;   /* 0xDC */
    void* e0;   /* 0xE0 */
    u8 pad1[0xEC - 0xE4];
    u16 ec;     /* 0xEC */
    u8 pad2[0x234 - 0xEE];
    u8* p234;   /* 0x234 */
    u8 pad3[0x310 - 0x238];
    void* p310; /* 0x310 */
    s32 p314;   /* 0x314 */
} MdlFlags78ec0;
extern void func_003f6440(s32 a, s32 b);
extern void (*D_00887304[])(s32, void*);
extern void func_00479910(void* a);
extern void* func_003bfae0_1(void* a);
#pragma alias func_003bfae0_1 func_003bfae0
extern void (*D_00887300_abs[])(s32, s32);
/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (same measured fix as func_00478ec0). */
#pragma opt_propagation off

// FUN_00476C70
void func_00476c70(MdlFlags78ec0* o)
{
    void (**base)(s32, s32);
    void* node;
    void* list;
    void* elem;
    s32 sp4C;

    func_003f6440(2, 0x64);
    if (!(o->d8 & 0x200) || (o->d8 & 0x400)) {
        func_003f6440(3, 0x7000F);
    } else if (*(u8*)((u8*)o + 0xD3) > 0xC8) {
        func_003f6440(3, 0x704FD);
    } else {
        func_003f6440(3, 0x7008D);
    }
    base = D_00887300_abs;
    base[0](6, 1);
    D_00887304[0](0xE, &sp4C);
    base[0](0xE, 0);
    if (o->e0 == NULL || (o->d8 & 0x200)) {
        func_00479910(o->dc);
    } else {
        list = D_008872E0[0];
        node = *(void**)((u8*)o->e0 + 8);
        while (node != NULL) {
            if (func_003e8200(list, func_003bfae0_1(*(void**)((u8*)node + 0))) != 0) {
                elem = *(void**)((u8*)node + 0);
                ((void (*)(void*))*(void**)((u8*)elem + 0x48))(elem);
            }
            node = *(void**)((u8*)node + 0x24);
        }
    }
    base[0](0xE, sp4C);
}
#pragma opt_propagation on

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




/* measured (recipe A retest, 4 attempts nd 205/202/206/191): the per-site
   recipe spelling `s32 v = *(u8*)(p+off); u32 c = v; if (v >= 0) { f = (f32)v; }
   else { f = (f32)(s32)(c >> 1 | (c & 1)); f = f + f; }` fixes the recorded
   3-way CFG - every site now emits retail's single lbu;bltz;mtc1;cvt.s.w
   (srl/andi/or;add.s in the neg arm) byte-exactly, and the 0.5f+255.0f*x
   adda/madd chains, the mask bnez->out-of-line mov.s f4=f20, and the tail
   lbu x4/sb x4 all match. Residual nd 191: pure register allocation - (1)
   the or-result lands in $v0 and the cvt result in $f0 (retail $v1/$f1) at
   every site, cascading into the mul.s operand regs and the global lwc1
   target; (2) saved-register rotation (mine $s0=param_2/$s1=param_1/$s2=
   elem/$s3=count/$s4=obj/$s5=i vs retail $s0=elem/$s1=obj/$s2=i/$s3=param_2/
   $s4=param_1/$s5=count), decl-order swaps did not move it; (3) the 0x8C-0x8F
   byte block: retail spills each madd result byte to the stack (sb after each
   mfc1) and lbu-reloads for the tail; mwcc keeps the bytes in GPRs even with
   a byte-aliased u32 stack local (nd 191) - the t-byte sb order 0x8E/8D/8C/8F
   matches. Andi-then-bltz ordering is not an issue here (lbu;bltz direct).
   Recipe A conv-CFG floor lifted; residual is FP/GPR coloring + spill
   placement. */
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
void* func_00477510(void* arg0)
{
    void* base;
    u32 count;
    u32 i;
    void* item;
    f32 buf[3];

    base = *(void**)((u8*)arg0 + 0x18);
    count = *(u32*)((u8*)base + 0x24);
    for (i = 0; i < count; i++) {
        item = *(void**)((u8*)*(void**)((u8*)base + 0x20) + i * 4);
        if (func_00457a90(item, D_00713180) != 0 &&
            func_00457a90(item, D_007131A0) != 0 &&
            func_00457a90(item, D_007131C0) != 0) {
            buf[0] = func_004579a0(item, D_00713180);
            buf[2] = func_004579a0(item, D_007131A0);
            buf[1] = func_004579a0(item, D_007131C0);
        } else {
            buf[0] = fGpffff809c;
            buf[2] = fGpffff809c;
            buf[1] = fGpffff809c;
        }
        *(RwV3d*)((u8*)item + 0xC) = *(RwV3d*)buf;
    }
    return arg0;
}

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

/* measured: retail folds the loop-invariant address arg1+4 into the in-loop
   load (lw $a0,4($s4)); mwcc b210 hoists the address into an extra saved
   register (addiu $s7,$s4,4 before the first jal) making the frame 0xA0 vs
   retail 0x90 and shifting the stack buffer. Secondary: key/item s-regs swap
   ($s1/$s3) and loop counter lands in $s1 vs retail $s2. Tried: v4 pre-loop
   local, indexed ((void**)arg1)[1], reversed 4+ptr add, decl-order swaps,
   opt_loop_invariants off — all nd 63. Loop-invariant-address hoist floor. */
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

/* measured: retail hoists the 1.0f const (lui/mtc1 -> $f3) to function top and
   allocates inv184=$f2, inv188=$f1, product=$f5; mwcc b210 materializes the
   const at the use site into $f1 and lands the product in $f2; with
   #pragma opt_loop_invariants on the const hoists but the whole allocation
   permutes (counter $v1<->$a2, const $f4, nd 55). Integer t-regs are permuted
   in both loops regardless (p8 $t0 vs $t1, mask regs). Tried: plain C (nd 45),
   one=1.0f local (nd 45), pragma on (nd 55). Register-coloring floor. */
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




/* measured: volatile RwRGBA* color forces the four lbu color loads in source
   order (removing it rotates/reorders them, nd 9) and the K&R parameter
   definition keeps the file's heterogeneous 0-arg and void*-arg callers
   compiling. */
// FUN_004779B0
void* func_004779b0(type, id)
    u16 type;
    u16 id;
{
    u8* obj;
    u32 i;
    void** head;
    u8* prev;
    volatile RwRGBA* color;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;

    func_0044ea90(D_00713138, 0x108A);
    obj = ((void* (*)(int, int))DAT_008873e8[0])(0x320, 0x40000);
    func_0043f9c8(obj, 0, 0x320);
    *(s32*)(obj + 0xD8) = 0x10118;
    *(u8*)(obj + 0xD0) = 0xFF;
    *(u8*)(obj + 0xD1) = 0xFF;
    *(u8*)(obj + 0xD2) = 0xFF;
    *(u8*)(obj + 0xD3) = 0xFF;
    color = (RwRGBA*)(obj + 0xD0);
    red = color->red;
    green = color->green;
    blue = color->blue;
    alpha = color->alpha;
    *(u8*)(obj + 0x300) = red;
    *(u8*)(obj + 0x301) = green;
    *(u8*)(obj + 0x302) = blue;
    *(u8*)(obj + 0x303) = alpha;
    *(u16*)(obj + 0xD4) = type;
    *(u16*)(obj + 0xD6) = id;
    *(s32*)(obj + 0xE4) = 0x44;
    *(s32*)(obj + 0xE8) = 0x717FB;
    *(s32*)(obj + 0x2FC) = iGpffffbb28;
    *(s32*)(obj + 0x28) = 0x3F800000;
    *(s32*)(obj + 0x14) = 0x3F800000;
    *(s32*)(obj + 0x00) = 0x3F800000;
    *(s32*)(obj + 0x10) = 0;
    *(s32*)(obj + 0x08) = 0;
    *(s32*)(obj + 0x04) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x18) = 0;
    *(s32*)(obj + 0x38) = 0;
    *(s32*)(obj + 0x34) = 0;
    *(s32*)(obj + 0x30) = 0;
    *(s32*)(obj + 0x0C) |= 0x20003;
    *(s32*)(obj + 0x68) = 0x3F800000;
    *(s32*)(obj + 0x54) = 0x3F800000;
    *(s32*)(obj + 0x40) = 0x3F800000;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x48) = 0;
    *(s32*)(obj + 0x44) = 0;
    *(s32*)(obj + 0x64) = 0;
    *(s32*)(obj + 0x60) = 0;
    *(s32*)(obj + 0x58) = 0;
    *(s32*)(obj + 0x78) = 0;
    *(s32*)(obj + 0x74) = 0;
    *(s32*)(obj + 0x70) = 0;
    *(s32*)(obj + 0x4C) |= 0x20003;
    *(s32*)(obj + 0x80) = 0x3F800000;
    *(s32*)(obj + 0x84) = 0x3F800000;
    *(s32*)(obj + 0x88) = 0x3F800000;
    for (i = 0; i < 2; i++) {
        func_00473520(obj + i * 0xA4 + 0xEC);
    }
    *(s32*)(obj + 0x238) = 0;
    *(s8*)(obj + 0x23E) = 1;
    *(s16*)(obj + 0x240) = -1;
    *(s32*)(obj + 0x244) = 0x3F800000;
    func_0043f9c8(obj + 0x258, 0, 8);
    *(s8*)(obj + 0x25A) = 1;
    *(s32*)(obj + 0x25C) = 0x3F800000;
    *(s8*)(obj + 0x260) = 0;
    *(s32*)(obj + 0x274) = 0;
    *(s32*)(obj + 0x278) = 0;
    *(s32*)(obj + 0x27C) = 0;
    *(s8*)(obj + 0x280) = 0x70;
    *(s8*)(obj + 0x281) = 0x70;
    *(s8*)(obj + 0x282) = 0;
    func_0047ea70(obj + 0x2D0);
    for (i = 0; i < 5; i++) {
        func_0047adf0(obj, i & 0xFFFF, -1);
    }
    head = &D_00922BE0[type];
    prev = *head;
    *(void**)(obj + 0x304) = 0;
    if (prev != 0) {
        *(void**)((u8*)prev + 0x304) = obj;
        *(void**)(obj + 0x308) = prev;
    } else {
        *(void**)(obj + 0x308) = 0;
    }
    *head = obj;
    return obj;
}

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

extern void func_0047b060(void* a);
/* measured: retry disproved the old daddiu floor: u8 var k with `k = 1;` DOES
   emit daddiu $s1,$zero,1 (attempt 1), but only as a u8 loop counter, which
   makes mwcc fold every (u16)k/&0xFFFF use to 0xFF or nothing (type-based
   range fold). With an s32 counter the masks are right (test andi+slti, body
   andi, increment addiu+andi all match retail) and all register/slot/switch
   details match (entry:$s0, counter:$s1, obj:$s2; case 1/case 2 gives retail's
   2-then-1 tests; sp[3] stores in order; iGpffff80cc/fGpffff809c GPREL), but
   then the init propagates through k to plain addiu in every spelling
   (k=1;i=k; i=(u8)k; i=(u8)1) and retail's BODY-top andi $v1,$s1 is CSE'd
   with the loop-test mask (loop-test-CSE family, same as 47aa30; object lands
   exactly 1 word short). Residual also: func_003971d0 args materialize
   move-first vs retail's load-first (2 words). Best nd 76. */
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

/* measured: re-measured this wave (5 spellings, best nd 74): retail layout is
   sp9C/sp94/sp90/sp8C/sp88 five scalar slots with tmp values held in s-regs
   across calls (out in $s6); mwcc b210 coalesces the never-read slots into
   sp9C's slot pair and DSEs their stores (single tmp[2] nd 76, two tmp[2]
   arrays nd 76 — disjoint arrays merged, four scalar locals nd 88, block-
   scoped arrays nd 76, m2c-verbatim five-slot body nd 74), frame 0x90 vs
   0xA0. The earlier nd-9 body (retail stack layout, only s-reg names differ:
   retail t1=$s1/path-1 obj=$s3 vs mwcc obj=$s1/t1=$s6) is not reproducible
   from any spelling found. Slot-coalescing + saved-register-rotation floor. */
// FUN_00477FB0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00477fb0);

/* measured: loop matched only as an explicit-break while (while(node){if(D6==
   id)break;node=next;} — the && form reorders the test block) with u32 params
   and an explicit `id = arg1 & 0xFFFF` local (u16 params re-mask into extra
   s-regs, nd 80); buf[0x100] at sp+0x50 gives the 0x150 frame. The residual is
   the same branch-to-branch redirect as func_0047ac90: retail keeps
   beqz $v0,0x478240; ... ; 0x478240: b 0x47828c after the func_0047d0e0 test,
   mwcc b210 redirects the beqz straight to the join (re-measured nd 1, the
   beqz imm). Tried: result local, empty-else, if forms — identical nd 1.
   Branch-to-branch sharing floor. */
// FUN_00478140
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478140);

// FUN_004782B0
s32 func_004782b0(u8* param_1)
{
    s32 f;
    void* node;
    s32 id2;

    f = *(s32*)(param_1 + 0xD8);
    if ((f & 0x1000) != 0) {
        return 1;
    }
    if ((f & 0x2000) == 0) {
        if (func_0047ce00() == 0) {
            return 0;
        }
        if (func_0047e6f0(param_1 + 0x2D0) == 0) {
            return 0;
        }
        func_0047b060(param_1);
        func_00477ca0(param_1);
    } else {
        if (func_0047e6f0(param_1 + 0x2D0) == 0) {
            return 0;
        }
        id2 = *(u16*)(param_1 + 0xD6);
        node = D_00922BE0[*(u16*)(param_1 + 0xD4)];
        while (node != 0) {
            if (*(u16*)((u8*)node + 0xD6) == id2 &&
                (*(s32*)((u8*)node + 0xD8) & 0x1000) != 0) {
                break;
            }
            node = *(void**)((u8*)node + 0x308);
        }
        if (node == 0) {
            return 0;
        }
        func_00478410(node, param_1);
        *(s32*)(param_1 + 0xD8) &= ~0x2000;
    }
    *(s32*)(param_1 + 0xD8) |= 0x1000;
    return 1;
}

/* measured: register-allocation mismatch across the whole body: retail saves
   $16-$23 (0x90 frame; slot1/res share $s0, size and j share $s2, cnt=$s6,
   off=$s7) while mwcc b210 needs 9-11 saved regs (0xB0-0xC0 frame, extra
   $fp) in every spelling tried (locals for slot0/primary/secondary -> 0xC0
   nd 168; fully inlined pointer re-derivation + scoped slot1 + v4/r locals
   for the 971d0 call -> 0xB0 nd 190). Also the func_003971d0 arg loads
   materialize move-first vs retail's load-first. Saved-register-count floor. */
// FUN_00478410
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00478410);
// FUN_00478750
u32* func_00478750(u8* param_1)
{
    void* func_004779b0(u16, u16);
    u32* obj;

    obj = func_004779b0(*(u16*)(param_1 + 0xD4), *(u16*)(param_1 + 0xD6));
    if ((*(s32*)(param_1 + 0xD8) & 0x1000) != 0) {
        func_00478410(param_1, (u8*)obj);
        *(s32*)((u8*)obj + 0xD8) |= 0x1000;
    } else {
        *(s32*)((u8*)obj + 0xD8) |= 0x2000;
    }
    return obj;
}

// FUN_004787E0
void func_004787e0(u8* param_1)
{
    u32 i;
    void* t;

    if (*(void**)(param_1 + 0xDC) != 0) {
        func_003c0700(*(void**)(param_1 + 0xDC));
    }
    for (i = 0; i < 2; i++) {
        func_004735b0(param_1 + i * 0xA4 + 0xEC);
    }
    if (*(void**)(param_1 + 0x234) != 0) {
        func_004745f0(*(void**)(param_1 + 0x234));
        *(void**)(param_1 + 0x234) = 0;
    }
    if (*(void**)(param_1 + 0x254) != 0) {
        func_00474890(*(void**)(param_1 + 0x254));
        *(void**)(param_1 + 0x254) = 0;
    }
    t = *(void**)(param_1 + 0x2C8);
    if (t != 0) {
        *(u16*)((u8*)t + 2) = *(u16*)((u8*)t + 2) - 1;
        if (*(u16*)((u8*)t + 2) == 0) {
            DAT_008873ec[0](*(void**)((u8*)t + 4));
        }
    }
    if (*(void**)(param_1 + 0xE0) != 0) {
        func_00462bf0(*(void**)(param_1 + 0xE0));
    }
    for (i = 0; i < 5; i++) {
        if ((*(u8*)(param_1 + i * 0xC + 0x28C) & 1) != 0 &&
            *(void**)(param_1 + i * 0xC + 0x290) != 0) {
            func_0047ae10(param_1, i & 0xFFFF);
        }
    }
    func_004b7140(param_1);
    if (*(void**)(param_1 + 0x2CC) != 0) {
        func_0047d2d0(*(void**)(param_1 + 0x2CC));
    }
    func_0047eaa0(param_1 + 0x2D0);
    if (*(void**)(param_1 + 0x308) != 0) {
        *(void**)((u8*)*(void**)(param_1 + 0x308) + 0x304) = *(void**)(param_1 + 0x304);
    }
    if (*(void**)(param_1 + 0x304) != 0) {
        *(void**)((u8*)*(void**)(param_1 + 0x304) + 0x308) = *(void**)(param_1 + 0x308);
    } else {
        D_00922BE0[*(u16*)(param_1 + 0xD4)] = *(void**)(param_1 + 0x308);
    }
    DAT_008873ec[0](param_1);
}
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



extern void func_00475820(void* a, void* b);
extern u8* func_00473b20(u8* a, u8* b, s32 c);
extern void func_0047a510(void* a, s32 b, void* c);
extern s32 func_0047a2f0(void* a, void* b, void* c);
extern void func_0047dae0(u32 a);
extern void func_0047de50(u32 a);
extern void func_0047de00(u32 a, void* b);
extern void func_0047dd40(u32 a, void* b);
extern void func_0047d900(u32 a, void* b);
extern void func_0047d540(u32 a, void* b);
extern void func_0047ed60(void* a);
extern void func_0047a0e0(u8* a, s32 b, f32 c);
extern void func_0047aa10(void* a, RwV3d* b);
extern int func_0047a9d0(void* a);
/* measured: nd 16 after 4 attempts (object 1080B, window 1088B); everything
   matches: registers (arg1:$s0, obj:$s1, t18/loop1-j:$s2, i2/loops-2-3:$s3,
   slot:$s4, v:$s5), all loops/calls, p290/p294 two-use address locals, the
   8-word copy bodies. Remaining: (1) both copy-loop setups: retail hoists
   the p290 load above the s1 addiu (lw;addiu s1;addiu d1;addiu k) while b210
   emits statement order (addiu s1;lw;addiu d1;addiu k) — load-hoist
   scheduling; (2) the copy-loop counter k lands in $a3 vs retail's $a0 and
   the second loop's dest d2 in $a0 vs retail's $a1 — temp-register rotation
   (recorded family); (3) func_0047a510's args materialize move-first
   (move $a0;lw $a1) vs retail's load-first (lw $a1;move $a0). The loop-1
   counter must be a variable SEPARATE from the i2 accumulator (retail reuses
   t18's $s2 for loop 1 only; loops 2-3 reuse i2's $s3). */
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

extern void func_004746b0(void* a, void* b);
extern void func_00489f80(u32 a);
extern s64 iGpffffabe8;

/* P4 port probe: opt_propagation off prevents mwcc folding the D_00887300_abs
   array address into per-call lui/lw (measured: with it on, mid-function base
   assignment rematerializes per use). */
#pragma opt_propagation off

// FUN_00478EC0
void func_00478ec0(void* param_1, MdlFlags78ec0* o)
{
    struct {
        void* p38;
        u16 p3C;
    } ctx;
    void (**base)(s32, s32);
    s32 flag;
    void* dc;
    s32 t;

    if (o->d8 & 0x80000) {
        func_004746b0((u8*)o + 0x234, (u8*)o + 0xEC);
        o->d8 &= 0xFFF7FFFF;
    }
    dc = o->dc;
    ctx.p38 = (u8*)o + 0xD0;
    ctx.p3C = 0;
    func_003bff30(dc, (void*)func_00476e90, &ctx);
    t = (o->d8 & 8) != 0;
    base = D_00887300_abs;
    base[0](6, t);
    base[0](8, (o->d8 & 0x10) != 0);
    base[0](0xE, (o->d8 & 0x100) != 0);
    if (o->d8 & 0x40) {
        flag = 3;
    } else {
        flag = 2;
    }
    base[0](0x14, flag);
    if (o->d8 & 0x40000) {
        iGpffffabe8 |= 0x80;
    }
    if (o->d8 & 0x100000) {
        func_00489f80(o->d8);
    }
    if (o->p310 != NULL) {
        ((void (*)(void*))o->p310)((void*)o->p314);
    }
}
#pragma opt_propagation on

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

/* measured: 4 attempts (nd 432/388/388/409). The lbu+bltz+u32-neg-path byte
   conversion IS reproducible: (f32)(u32)*(u8*) emits lbu;bltz;mtc1;cvt.s.w
   (neg: srl/andi/or/doubling) exactly like retail, and iGpffff8044 must be
   declared volatile (plain f32: b210 CSEs the 8 loads into one hoisted
   lwc1). madd chain matches from `255.0f * x + 0.5f` (adda.s/madd.s). The
   sp6C[4] bytes must be one array (separate s8 locals get dead-store-ELIM'd,
   killing the w1/w2 chains). Residual at best nd 409: pre-chain register
   allocation (obj/obj2 in $a1 vs retail $v0; the flags&0x8000 test re-issued
   in $s0 instead of one beqz into the shared block; sp64/sp68/sp6C[4] stack
   slot order 0x74/0x6C/0x64 vs retail 0x64/0x68/0x6C) and the madd-chain FP
   regs (mine f1/f0/f6/f4 + 255=$f4,0.5=$f3,0.0=$f2 vs retail f2/f1/f0/f5 +
   $f5/$f4/$f3). FP-coloring + slot-order floor. */
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

/* measured: saved-register coalescing + t-reg rotation: retail keeps raw
   arg1 in $s5 and the u16 mask t20 in $s4 (both live across the 740c0 call)
   while mwcc b210 coalesces t20 into arg1's $s4 with a self-mask (all arg1
   uses are &0xFFFF so the coalesce is legal), and every following temp
   rotates ($a0/$v1 etc.) — nd 151-157 across compound-&& and comma
   spellings (the &&-inside-comma booleanization was fixed by moving
   `elem = ...) != 0 && elem != D` to top level; the 8-word copy loop and
   identity-mat blocks then match 1:1). Saved-register rotation floor. */
// FUN_00479940
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479940);
// FUN_00479CA0
s32 func_00479ca0(void* param_1, s32 param_2)
{
    u16 mask = (u16)param_2;
    s32 off;
    void* ptr;
    if (mask == 0) {
        if (*(s32*)((u8*)param_1 + 0x120) == 0 && *(s32*)((u8*)param_1 + 0x234) == 0) {
            return 0;
        }
    } else {
        off = (s32)mask * 0xA4;
        ptr = (void*)(off + (s32)param_1);
        if (*(s32*)((u8*)ptr + 0x120) == 0) {
            return 0;
        }
    }
    return 1;
}

/* measured: second block matches 100%; first block blocked by (1) retail reuses
   $a3 (the dead s64 high-half reg, then the dead mask reg) for obj and keeps the
   dsll32 idx in $t0, mwcc b210 allocates obj=$t0 / idx=$a3 (pure coloring swap;
   tried with/without mask local, inline vs local obj — identical nd) and (2)
   retail loads arr = *obj at the top of the body while mwcc sinks the load below
   the idx*0x50 multiply chain. Load-sinking floor + register-coloring residual. */
// FUN_00479D10
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479d10);

/* measured: 4 attempts (nd 33/36/36/36). Correct spellings found: the byte
   chain wants 32-bit arithmetic on a byte base - *(void**)((u8*)arr +
   idx*0x50 + 0x40) folds 0x40 into the lw (element form *0x50+0x10 emits an
   extra sll 6 chain + daddiu, nd 33; (s16) param typing emits no dance at
   all). Residual: (1) retail re-derives the s16 sign-extension (dsll32/
   dsra32) at BOTH use sites; b210 CSEs the two conversions into one pair in
   every spelling tried (s64 shifts, (s64)(s16) casts, s32 param + (s16)
   narrowing, named s32 local nd 22); (2) retail loads arr = *elem at the top
   of the flag body, b210 sinks it below the idx re-derivation + 0x50 chain
   (load-sinking, brief-confirmed); (3) the return-1 path gets its own b to
   the epilogue where retail falls through. Load-CSE +
   sign-extension-reissue floor (same family as 79d10). */
// FUN_00479DD0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479dd0);

/* measured: re-tested 4x this wave (nd 47/55/13/17; best spelling: (u16) cast
   in the final test + `param_2 & 0xFFFF` in the off chain + elem as
   `(u8*)*(void**)((u8*)arr) + (0x40 + v * 0x50)`, with opt_propagation off:
   the mask CSE then breaks exactly as retail re-masks at .L479F24). Residual
   nd 13 is the recorded p/off saved-register rotation: retail keeps off in
   $s0 and derives p in temp $a2 (re-deriving addu $a0,$s0,$s2 AFTER the
   func_003d5e40 call), mwcc b210 keeps p in $s0 across the call in every
   spelling (inline store expr, p reassignment, fresh q, decl-order swaps)
   and never rematerializes; plus the elem chain schedules addiu 0x40 before
   the lw ($a1) where retail loads first (1-3 words). Recipe B (global base
   hoist) does not apply - no global array base in this function. Saved-
   register rotation floor. */
// FUN_00479E60
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00479e60);
// FUN_00479F60
f32 func_00479f60(void* param_1, s32 param_2)
{
    f32 value;
    s32 off;
    void* ptr;
    off = (s32)(param_2 & 0xFFFF) * 0xA4;
    ptr = (void*)(off + (s32)param_1);
    if (*(s16*)((u8*)ptr + 0xF0) < 0) {
        value = 0.0f;
    } else if (*(void**)((u8*)ptr + 0x10C) == 0 ||
               *(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20) == 0) {
        value = 0.0f;
    } else if (*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20)) == 0) {
        value = 0.0f;
    } else {
        value = *(f32*)((u8*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)ptr + 0x10C) + 0x20)) + 0xC);
    }
    return value / iGpffff8040;
}

// FUN_0047A000
f32 func_0047a000(void* param_1, s32 param_2, s64 param_3)
{
    f32 value;
    u16 mask = (u16)param_2;
    s32 off;
    void* ptr;
    void* base;
    void* arr;
    void* obj;
    s32 idx;
    s32 off2;
    off = (s32)mask * 0xA4;
    ptr = (void*)(off + (s32)param_1);
    if (*(s32*)((u8*)ptr + 0x10C) == 0) {
        value = 0.0f;
    } else {
        base = *(void**)((u8*)ptr + 0x120);
        arr = *(void**)base;
        idx = (s16)param_3;
        off2 = idx * 0x50;
        obj = (void*)(off2 + (s32)arr);
        value = *(f32*)((u8*)*(void**)((u8*)obj + 0x40) + 0xC);
    }
    return value / iGpffff8040;
}

// FUN_0047A080
f32 func_0047a080(s32 arg0, s32 arg1) {
    s32 off = (arg1 & 0xFFFF) * 0xA4;
    u8 *p = (u8 *)(off + arg0);
    f32 v;

    if (*(s16 *)(p + 0xF0) < 0) {
        v = 0.0f;
    } else {
        v = *(f32 *)(p + 0xF8);
    }
    return v / iGpffff8040;
}

// FUN_0047A0E0
void func_0047a0e0(u8 *arg0, s32 arg1, f32 fparg0) {
    s32 i = arg1 & 0xFFFF;
    s32 off = i * 0xA4;

    *(f32 *)((off + (s32)arg0) + 0xF4) = fparg0;
    if (i == 0) {
        *(f32 *)(arg0 + 0x244) = fparg0;
    }
}

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

/* measured (recipe A retest, 4 attempts nd 82/67/63/6): no u16 sign-test in
   this function - recipe A does not apply. Working spellings: goto-shared
   fail (single move $v0,0 block), s32 loop counter with explicit (u16)
   casts (increment andi $s0 + re-mask andi $v0 at the test, exactly retail),
   p = arg0 + (i & 0xFFFF) * 0xC (the explicit mask keeps the andi at the
   chain), nested ifs with t2 = p + 0x290 materialized between the 0x28C and
   0x290 tests (retail's addiu $s2, $v1, 0x290 position), named mp for the
   inner ptr load (load-before-chain order). Residual nd 6 is the recorded
   outer-block schedule: [sll chain; addiu 0x40; lw ptr] vs retail [sll
   chain; lw ptr; addiu 0x40] - the chain result lands in $v0 vs retail $v1
   and the addiu applies to the chain instead of the loaded ptr; `*a + (0x40
   + idx)` avoids the fold but keeps this order, plain `*a + 0x40 + idx`
   folds 0x40 into the load (3 words, nd 84). Chain-vs-load schedule floor
   (same as recorded). */
// FUN_0047A320
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a320);

// FUN_0047A4A0
u8 *func_0047a4a0(u8 *arg0, s32 *arg1) {
    /* arg1 is reassigned rather than using a fresh local: retail reuses the
       $a1 argument register for the node pointer once the mask is loaded. */
    s32 mask = *arg1;

    arg1 = (s32 *)*(u8 **)(arg0 + 0x18);
    *(s32 *)((u8 *)arg1 + 8) &= ~mask;
    return arg0;
}

// FUN_0047A4D0
void func_0047a4d0(void* param_1, int param_2)
{
    func_003bff30(*(void**)((u8*)param_1 + 0xDC), func_0047a4a0, &param_2);
}

/* measured: same floor family as 00475B90: retail places the
   v17 != func_00397470(v18) setup block OUT OF LINE (bne -> setup, b -> join,
   +8B) while mwcc b210 inlines it under a negated skip (beq -> join, nd 84);
   the loop's t-regs rotate (t/clump/count/j/idm permutation) and the u16
   counter body-mask is CSE'd into the loop test (count as s32 + jm local
   regress to nd 92); the 8-word copy loop wants n-- before the stores
   (do {lw,lw,q+=8,n--,sw,sw,dst+=8} while(n>0) shape). Branch-placement floor. */
// FUN_0047A510
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047a510);
// FUN_0047A6D0
s32 func_0047a6d0(void* arg0, s32 arg1, void* arg2)
{
    s32 result;
    u32 lo;
    u32 hi;
    u8* src;
    u32* dst;
    s32 count;
    u32 buf[16];

    if (*(void**)((u8*)arg0 + 0x2C8) != 0) {
        result = func_00475b90(buf, *(void**)((u8*)arg0 + 0x2C8), arg1 & 0xFFFF, *(void**)((u8*)arg0 + 0xDC));
    } else {
        src = (u8*)func_00457f40(*(void**)((u8*)arg0 + 0xDC), D_007131D8, arg1);
        if (src == 0) {
            result = 0;
        } else {
            src = (u8*)func_003e9700(src);
            dst = buf;
            count = 8;
            do {
                lo = *(u32*)(src + 0);
                hi = *(u32*)(src + 4);
                src += 8;
                count -= 1;
                *(u32*)(dst + 0) = lo;
                *(u32*)(dst + 1) = hi;
                dst += 2;
            } while (count > 0);
            result = 1;
        }
    }
    if (result == 0) {
        return 0;
    }
    *(RwV3d*)((u8*)arg2) = *(RwV3d*)(buf + 12);
    return 1;
}
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

/* measured: retail masks the u16 loop counter in the loop head (andi $v1,$a3,0xffff;
   slti $v1,$v1,5) and AGAIN at the body top (andi $a2,$a3,0xffff) to derive the
   entry index; mwcc b210 value-numbers the two masks as one value, carries the
   check's masked register ($a2) across the back edge and emits a redundant
   self-mask (andi $a2,$a2,0xffff) at the body top. Tried: plain u16 loop (nd 25),
   explicit `i & 0xFFFF` body mask (nd 6), reversed mask operands (nd 6), s32
   counter with explicit masks (nd 25), separate s32 chk var while-loop (nd 25),
   separate u16 idx / s32 idx locals (nd 25). Loop-test-CSE floor. */
// FUN_0047AA30
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047aa30);

// FUN_0047AAA0
void func_0047aaa0(void* param_1, s32 param_2, void* param_3, void* param_4, void* param_5, u32 param_6)
{
    void* obj;
    s32 off;
    void* slot;
    obj = func_004779b0(param_3, param_4);
    if ((param_6 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    func_0047aff0(obj, param_5);
    func_004782b0(obj);
    off = (s32)(param_2 & 0xFFFF) * 0xC;
    slot = (void*)(off + (s32)param_1);
    *(void**)((u8*)slot + 0x290) = obj;
    *(u32*)((u8*)obj + 0xD8) |= 0x4;
    *(u32*)((u8*)*(void**)((u8*)slot + 0x290) + 0xD8) |= 0x8000;
    *(u8*)((u8*)slot + 0x28C) |= 0x1;
}

// FUN_0047AB90
void func_0047ab90(void* param_1, s32 param_2, void* param_3, void* param_4, void* param_5, void* param_6, u32 param_7)
{
    void* obj;
    s32 off;
    void* slot;

    obj = func_004779b0(param_3, param_4);
    if ((param_7 & 1) != 0) {
        *(u32*)((u8*)obj + 0xD8) |= 0x4000;
    }
    func_0047af60(obj);
    {
        int tmp[2];
        tmp[0] = (s32)param_5;
        tmp[1] = (s32)param_6;
        func_0047afd0(obj, tmp);
    }
    func_004782b0(obj);
    off = (s32)(param_2 & 0xFFFF) * 0xC;
    slot = (void*)(off + (s32)param_1);
    *(void**)((u8*)slot + 0x290) = obj;
    *(u32*)((u8*)obj + 0xD8) |= 0x4;
    *(u32*)((u8*)*(void**)((u8*)slot + 0x290) + 0xD8) |= 0x8000;
    *(u8*)((u8*)slot + 0x28C) |= 0x1;
}

/* measured: working spelling confirmed this wave — void* params 3/4 (u32
   needs casts at the func_00477e80 call), buf[0x100] at sp+0x70 for the 0x170
   frame, tail as in func_0047ab90. Retail keeps a branch-to-branch chain
   after the func_0047b050 call (beqz $v0,0x47ad38; ... ; 0x47ad38: b 0x47ad84);
   mwcc b210 redirects the beqz straight to the join (re-measured nd 2, one
   differing word, the beqz imm). Tried: if/else forms, empty-then,
   else-empty — identical nd 2. Branch-to-branch sharing floor. */
// FUN_0047AC90
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047ac90);

/* measured: retail saves THREE s-regs ($16=param_1, $18=scaled off, $17=ptr+0x290)
   and recomputes ptr = off + param_1 before the post-call byte clear; mwcc b210
   CSEs ptr into one saved register ($s1) plus $s0=ptr+0x290, giving a 0x30 frame
   vs retail's 0x40 and an addu-free recompute. Tried: ptr local, slot local,
   fully-inline off+param_1 expressions — all nd 30. Register-coloring/load-
   lifetime floor (retail keeps the addu operands alive across the call). */
// FUN_0047AE10
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047ae10);

/* measured: retail re-issues the u16 loop-counter mask in the body (andi $a3,$t3)
   while mwcc self-masks the check's register (andi $a2,$a2), and retail hoists the
   inner-loop constant 8 into $a2 at function top (copied per iteration) while mwcc
   materializes it inside the body; the 8-byte inner copy is lw,lw,sw,sw with
   loads-first in retail but mwcc interleaves or reverses the pair even with
   w0/w1 locals, and t-register allocation is permuted vs retail. Tried: plain
   pair copies, w0/w1 load locals, struct-copy probe (COMPILE ERROR via probe).
   Loop-test-CSE + load-sinking floor combination. */
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

/* measured: 1 transcription attempt (nd 1237 of 0x15A0). The whole
   switch-driven resource-loader is transcribed (cases 0x10/0x16/0x1B/0x23/
   0x2B + the 0xF0F000xx family, the 0x30C slot table, 0x254/0x234/0x2CC
   alloc blocks, the 8-word copy, 0x124/0x14/0x20 slot tables, func_004667d0
   10-arg calls with (s64)&D_0070B610). Residual: b210's switch emits a
   linear beq chain in source order with the case bodies INLINE where retail
   uses the jump-table shape with bodies out of line (the m2c's "irregular"
   switch - needs the mwccps2-switch-linear-chain-declaration-order levers),
   plus the usual saved-register rotation across the ~30 temp loads. Verified
   call shapes for retry: func_00397c40-style 1-arg sites use func_003e2ce0
   (always 1-arg); func_00463100 is (void*); func_0047f9f0 returns u32;
   func_004800d0 is (void*,void*,void*,void*); func_003d60e0 (void*,s32);
   func_0047d200/7dc30 return void* (cast to s32); jtbl_008873E8 =
   (void* (*)(int,int))DAT_008873e8[0]; D_0070B610 is an u8 extern; mwcc C89
   rejects void*+int - cast derefs to u8* first. Switch-layout +
   register-rotation floor. */
// FUN_0047B0C0
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047b0c0);

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u32 func_004669d0(u32 a, u32* b, u32* c);
extern void func_003ef260(void* a, void* b, void* c);
extern void func_003ef1b0(void* a);
extern void func_003e2e40(void* a, void* b);
extern void func_003d60e0(void* a, s32 b);
extern s32 func_004667d0();
extern u32 func_0047f9f0(void* a);
extern void func_004800d0(void* a, void* b, void* c, void* d);
extern void func_00463100(void* a);
extern u8 D_0070B610;
/* measured: nd ~409 after 4 attempts; all structure transcribed (the three
   alloc blocks, the 0xC list loop, the 0x234/0x254 slot tables, the 8-word
   copy, the func_0047d200/7dc30 calls, the sq/lq u_long128 stack slots spE0/
   spD0/spC0/spB0, the 0x667d0 10-arg call). Blocked by a 5-way saved-register
   rotation: b210 pins t17:$s0, p:$s2, obj:$s4, v20:$s5, cnt:$s6, cnt2:$s7,
   v30:$s8 in EVERY declaration order tried (incl. m2c-verbatim and inline
   size expressions) while retail is sz:$s0, t17:$s1, p:$s2, v19:$s3, v20:$s4,
   obj:$s5, cnt:$s6, cnt2:$s7, v30:$s8 — the {t17,sz} and {v19,v20,obj} groups
   rotate together (saved-register-rotation floor family). Also: the spE0
   u32->u_long128 cast emits dsll32/dsrl32 before sq where retail sq's
   directly (mixed-width u_long128 floor, cf mdlMatAnim 0x480670). */
// FUN_0047C660
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_0047c660);

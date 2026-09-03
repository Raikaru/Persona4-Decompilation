/* Source unit: src/Battle/btlMain_001b5e60.c */
#include "include_asm.h"
#include "type.h"

typedef struct BtlMain BtlMain;
struct BtlMain
{
    u8 _pad00[0xc];
    u32 flags;
};

extern u32 func_00193c70(void);
extern u32 func_001f6290(void);
extern void func_001f75b0(void);

typedef int (*code)();
typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);

extern u32 func_001b7520(float* param_1);
extern f32 fGpffff81f4; /* P4 gp -0x7e0c */

u32 func_001b7b30(void* work);
typedef struct BtlMainColorWork BtlMainColorWork;
extern u32 func_001b7e70(BtlMainColorWork* param_1); /* retail update target */
u32 func_001b87e0(void* work);
typedef struct BtlMainLerpWork
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 target0;
    f32 target1;
    f32 target2;
    f32 target3;
    u32 totalFrames;
    u32 currentFrame;
} BtlMainLerpWork;
typedef struct BtlMainColorFadeWork
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    u32 totalFrames;
    u32 currentFrame;
} BtlMainColorFadeWork;

extern f32 fGpffffb458; /* target RGBA bytes begin four bytes later */
extern u8* iGpffffb3ac;

typedef struct BtlMainSlerpResult
{
    f32 current0;
    f32 current1;
    f32 current2;
    f32 current3;
    f32 next0;
    f32 next1;
    f32 next2;
    f32 next3;
    f32 angle;
    s32 mode;
} BtlMainSlerpResult;
u32 func_001b96e0(void* work);
u32 func_001b99f0(void* work);
u32 func_001b9e50(void* work);

extern u32 func_003bb4a0(); /* old-style, matches donor call shape */

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RwV4d RwV4d;
struct RwV4d
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
extern RwV4d* func_00149ca0(void);
extern RwV4d* func_00149ce0(void);
extern void func_001496c0(void* value);

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct BtlMainColorWork
{
    RwV4d target0;
    RwV4d current0;
    RwV4d target1;
    RwV4d current1;
    RwV4d target2;
    RwV4d current2;
    u32 totalFrames;
    u32 currentFrame;
    u16 flags;
    u16 padding;
};

typedef struct BtlMainMatrix
{
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} BtlMainMatrix;

extern u_long128 D_00922C60[4];
extern f32 D_00922CA0[8];
extern s32 D_00922CC0[];
extern void func_001ba790(f32* out, f32* first, f32* second, f32 weight);
extern f32 fGpffff80c0; /* P4 gp -0x7f40 */
extern f32 fGpffff80c8; /* P4 gp -0x7f38 */

extern f32 fGpffff8434; /* P4 gp -0x7bcc */

extern void func_001bb8c0(u8* param_2, f32* param_3, f32 param_1);
extern void func_001bb790(u8* param_2, f32* param_3, f32 param_1);
extern void func_003bb5b0(void* curve, s32 mode, f32 time, RwV3d* dst, void* aux);
extern void func_003dcc70(f32* first, f32* second, BtlMainSlerpResult* result);
extern f32 fGpffff83f8;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff843c;
extern f32 fGpffff8440;
extern void func_001bb9b0(u8* param_2, f32* param_3, f32 param_1);
extern f32 fGpffff8438; /* P4 gp -0x7bc8 */



// FUN_001B5E60
u32 btlMainUpdateStateExit(void* work)
{
    BtlMain* btl;

    if (func_00193c70() == 0 && func_001f6290() == 0)
    {
        func_001f75b0();
        btl = (BtlMain*)iGpffffb3ac;
        btl->flags &= ~1;
    }

    return 0;
}



// FUN_001B7880
BtlPacket* func_001b7880(u32 param_1, u32 param_2, u32 param_3)
{
    float *color;
    int packet;
    union { u32 value; u8 bytes[4]; } packed;

    packet = (int)func_00194470(0x600, 0x68);
    *(code **)(packet + 0x6c) = (code *)func_001b7520;
    color = *(float **)(packet + 0x78);
    packed.value = param_1;
    color[0] = fGpffff81f4 * (float)packed.bytes[0];
    color[1] = fGpffff81f4 * (float)packed.bytes[1];
    color[2] = fGpffff81f4 * (float)packed.bytes[2];
    color[3] = fGpffff81f4 * (float)packed.bytes[3];
    packed.value = param_2;
    color[4] = fGpffff81f4 * (float)packed.bytes[0];
    color[5] = fGpffff81f4 * (float)packed.bytes[1];
    color[6] = fGpffff81f4 * (float)packed.bytes[2];
    color[7] = fGpffff81f4 * (float)packed.bytes[3];
    *(u32*)((u8*)color + 0x60) = param_3;
    return (BtlPacket*)packet;
}


/* measured: opt_propagation off preserves the retail grouped first-vector products. */
#pragma opt_propagation off
// FUN_001B7B30
u32 func_001b7b30(void* work)
{
    BtlMainLerpWork* lerpWork;
    u8* global;
    u32 flags;
    u32 totalFrames;
    u32 currentFrame;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    RwV4d result;

    lerpWork = (BtlMainLerpWork*)work;
    global = iGpffffb3ac;
    flags = *(u32*)(global + 0xc);
    if ((flags & 2) == 0)
    {
        return 1;
    }
    if ((flags & 0x2000000) == 0)
    {
        return 1;
    }

    if (lerpWork->currentFrame == 0)
    {
        *(RwV4d*)&lerpWork->value0 = *func_00149ca0();
        *(RwV4d*)&lerpWork->target0 = *func_00149ce0();
    }

    totalFrames = lerpWork->totalFrames;
    currentFrame = lerpWork->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;

        firstX = lerpWork->value0 * inverse;
        firstY = lerpWork->value1 * inverse;
        firstZ = lerpWork->value2 * inverse;
        firstW = lerpWork->value3 * inverse;
        global = iGpffffb3ac;
        secondX = *(f32*)(global + 0x1bc) * ratio;
        secondY = *(f32*)(global + 0x1c0) * ratio;
        secondZ = *(f32*)(global + 0x1c4) * ratio;
        secondW = *(f32*)(global + 0x1c8);
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ;
        result.w = firstW + secondW * ratio;
        *func_00149ca0() = result;

        global = iGpffffb3ac;
        result.x = lerpWork->target0 * inverse + *(f32*)(global + 0x1cc) * ratio;
        result.y = lerpWork->target1 * inverse + *(f32*)(global + 0x1d0) * ratio;
        result.z = lerpWork->target2 * inverse + *(f32*)(global + 0x1d4) * ratio;
        result.w = lerpWork->target3 * inverse + *(f32*)(global + 0x1d8) * ratio;
        *func_00149ce0() = result;

    }
    else
    {
        global = iGpffffb3ac;
        *func_00149ca0() = *(RwV4d*)(global + 0x1bc);
        global = iGpffffb3ac;
        *func_00149ce0() = *(RwV4d*)(global + 0x1cc);
        return 1;
    }

    lerpWork->currentFrame++;
    return 0;
}
/* measured: restore propagation after func_001b7b30. */
#pragma opt_propagation on
// FUN_001B7E20
void func_001b7e20(u32 value)
{
    BtlPacket* packet;

    packet = func_00194470(0x601, 0x28);
    packet->updateFunc = func_001b7b30;
    *(u32*)((u8*)packet->workData + 0x20) = value;
}



/* measured: opt_loop_invariants on hoists the unit-loop byte constants into the retail preheader registers. */
#pragma opt_loop_invariants on
// FUN_001B7E70
u32 func_001b7e70(BtlMainColorWork* work)
{
    u8* global;
    u8* unit;
    u32 globalFlags;
    u32 totalFrames;
    u32 currentFrame;
    u32 group;
    u_long128* matrixSrc;
    u_long128* matrixDst;
    s32 copyCount;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    BtlMainMatrix matrix;
    RwV4d result;

    global = iGpffffb3ac;
    globalFlags = *(u32*)(global + 0xc);
    if ((globalFlags & 2) == 0)
    {
        return 1;
    }
    if ((globalFlags & 0x2000000) == 0)
    {
        return 1;
    }

    if (work->currentFrame == 0)
    {
        work->target0.w = 1.0f;
        global = iGpffffb3ac;
        work->current0 = *(RwV4d*)(global + 0x24c);
        work->current1 = *(RwV4d*)(global + 0x1ec);
        work->current2 = *(RwV4d*)(global + 0x1fc);

        *(RwV4d*)&D_00922CA0[0] = *(RwV4d*)(global + 0x1bc);
        *(RwV4d*)&D_00922CA0[4] = *(RwV4d*)(global + 0x1cc);

        temp_f13 = *(f32*)(global + 0x1e0);
        temp_f12 = *(f32*)(global + 0x1dc);
        temp_f11 = *(f32*)(global + 0x1e4);
        temp_f4 = *(f32*)(global + 0x1e8);
        temp_f1 =
            2.0f / ((temp_f12 * temp_f12) +
                    (temp_f13 * temp_f13) +
                    (temp_f11 * temp_f11) +
                    (temp_f4 * temp_f4));
        temp_f3 = temp_f12 * temp_f1;
        temp_f2 = temp_f13 * temp_f1;
        temp_f1_2 = temp_f11 * temp_f1;
        temp_f10 = temp_f3 * temp_f4;
        temp_f9 = temp_f2 * temp_f4;
        temp_f8 = temp_f1_2 * temp_f4;
        temp_f7 = temp_f12 * temp_f3;
        temp_f6 = temp_f13 * temp_f2;
        temp_f5 = temp_f11 * temp_f1_2;
        temp_f4_2 = temp_f13 * temp_f1_2;
        temp_f3_2 = temp_f11 * temp_f3;
        temp_f2_2 = temp_f12 * temp_f2;
        matrix.right.x = 1.0f - (temp_f6 + temp_f5);
        matrix.right.y = temp_f2_2 + temp_f8;
        matrix.right.z = temp_f3_2 - temp_f9;
        matrix.up.x = temp_f2_2 - temp_f8;
        matrix.up.y = 1.0f - (temp_f5 + temp_f7);
        matrix.up.z = temp_f4_2 + temp_f10;
        matrix.at.x = temp_f3_2 + temp_f9;
        matrix.at.y = temp_f4_2 - temp_f10;
        matrix.at.z = 1.0f - (temp_f7 + temp_f6);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;

        matrixSrc = (u_long128*)&matrix;
        matrixDst = D_00922C60;
        copyCount = 4;
        do
        {
            u_long128 matrixRow = *matrixSrc;
            matrixSrc++;
            copyCount--;
            *matrixDst = matrixRow;
            matrixDst++;
        }
        while (copyCount > 0);

        D_00922CC0[0] = 1;
        if ((work->flags & 4) == 0)
        {
            group = 0;
            while (group < 4)
            {
                unit = *(u8**)(iGpffffb3ac + group * 8 + 0x178);
                while (unit != 0)
                {
                    if ((*(u32*)(unit + 0x98) & 2) != 0)
                    {
                        if ((work->flags & 1) != 0)
                        {
                            (*(u8**)(unit + 0xa00))[0x281] = 0;
                            (*(u8**)(unit + 0xa00))[0x282] = 6;
                        }
                        else
                        {
                            (*(u8**)(unit + 0xa00))[0x281] = 0x50;
                            (*(u8**)(unit + 0xa00))[0x282] = 4;
                        }
                    }
                    unit = *(u8**)(unit + 0xa6c);
                }
                group++;
            }
        }
    }

    /* measured: opt_propagation off preserves the retail grouped interpolation products. */
#pragma opt_propagation off
    totalFrames = work->totalFrames;
    currentFrame = work->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;

        firstX = work->current0.x * inverse;
        firstY = work->current0.y * inverse;
        firstZ = work->current0.z * inverse;
        secondX = work->target0.x * ratio;
        secondY = work->target0.y * ratio;
        secondZ = work->target0.z;
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ * ratio;
        result.w = 1.0f;
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x24c) = result;
        func_001496c0(&result);

        firstX = work->current1.x * inverse;
        firstY = work->current1.y * inverse;
        firstZ = work->current1.z * inverse;
        firstW = work->current1.w * inverse;
        secondX = work->target1.x * ratio;
        secondY = work->target1.y * ratio;
        secondZ = work->target1.z * ratio;
        secondW = work->target1.w;
        *(f32*)(iGpffffb3ac + 0x1ec) = firstX + secondX;
        *(f32*)(iGpffffb3ac + 0x1f0) = firstY + secondY;
        *(f32*)(iGpffffb3ac + 0x1f4) = firstZ + secondZ;
        *(f32*)(iGpffffb3ac + 0x1f8) = firstW + secondW * ratio;

        firstY = work->current2.y * inverse;
        firstZ = work->current2.z * inverse;
        firstW = work->current2.w * inverse;
        secondY = work->target2.y * ratio;
        secondZ = work->target2.z * ratio;
        secondW = work->target2.w * ratio;
        *(f32*)(iGpffffb3ac + 0x1fc) =
            work->current2.x * inverse + work->target2.x * ratio;
        *(f32*)(iGpffffb3ac + 0x200) = firstY + secondY;
        *(f32*)(iGpffffb3ac + 0x204) = firstZ + secondZ;
        *(f32*)(iGpffffb3ac + 0x208) = firstW + secondW;
    }
    else
    {
        func_001496c0(work);
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x24c) = work->target0;
        *(RwV4d*)(global + 0x1ec) = work->target1;
        *(RwV4d*)(global + 0x1fc) = work->target2;
        return 1;
    }

    work->currentFrame++;
    return 0;
}
/* measured: restore loop-invariant extraction after func_001b7e70. */
#pragma opt_loop_invariants off
/* measured: restore propagation after func_001b7e70. */
#pragma opt_propagation on
// FUN_001B83F0
BtlPacket* func_001b83f0(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5)
{
    float *pfVar1;
    int iVar2;
    union { u32 value; u8 bytes[4]; } packed;

    iVar2 = (int)func_00194470(0x602, 0x6c);
    *(code **)(iVar2 + 0x6c) = (code *)func_001b7e70;
    pfVar1 = *(float **)(iVar2 + 0x78);

    packed.value = param_1;
    pfVar1[0] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[1] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[2] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[3] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = param_2;
    pfVar1[8] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[9] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[10] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[0xb] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = param_3;
    pfVar1[0x10] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[0x11] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[0x12] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[0x13] = fGpffff81f4 * (float)packed.bytes[3];

    *(u32 *)((u8 *)pfVar1 + 0x60) = param_4;
    *(u16 *)(pfVar1 + 0x1a) = param_5;
    return (BtlPacket*)iVar2;
}



// FUN_001B87E0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b87e0);
// FUN_001B9360
void func_001b9360(s32 arg, s16 mode)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x603, 0x5c);
    packet->updateFunc = func_001b87e0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0x50) = arg;
    *(s16*)(work + 0x58) = mode;
}



// FUN_001B93C0
u8 func_001b93c0(BtlMainLerpWork* param_1)
{
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    RwV4d results;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    if (param_1->currentFrame == 0)
    {
        global = iGpffffb3ac;
        *(RwV4d*)&param_1->target0 = *(RwV4d*)(global + 0x25c);
    }

    totalFrames = param_1->totalFrames;
    currentFrame = param_1->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = param_1->target0 * inverse + param_1->value0 * ratio;
        results.y = param_1->target1 * inverse + param_1->value1 * ratio;
        results.z = param_1->target2 * inverse + param_1->value2 * ratio;
        results.w = param_1->target3 * inverse + param_1->value3 * ratio;
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x25c) = results;
    }
    else
    {
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x25c) = *(RwV4d*)&param_1->value0;
        return 1;
    }

    param_1->currentFrame++;
    return 0;
}
// FUN_001B9560
BtlPacket* func_001b9560(u32 param_1, u32 param_2)
{
    float *color;
    u32 packed;
    int packet;
    packet = (int)func_00194470(0x604, 0x28);
    *(code **)(packet + 0x6c) = (code *)func_001b93c0;
    color = *(float **)(packet + 0x78);
    packed = param_1;
    color[0] = fGpffff81f4 * (float)((u8*)&packed)[0];
    color[1] = fGpffff81f4 * (float)((u8*)&packed)[1];
    color[2] = fGpffff81f4 * (float)((u8*)&packed)[2];
    color[3] = fGpffff81f4 * (float)((u8*)&packed)[3];
    *(u32*)((u8*)color + 0x20) = param_2;
    return (BtlPacket*)packet;
}


/* measured: opt_common_subs off preserves the retail per-component scale reloads. */
#pragma opt_common_subs off
// FUN_001B96E0
u32 func_001b96e0(void* work)
{
    BtlMainColorFadeWork* colorWork;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    RwV4d results;
    RwV4d target;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    colorWork = (BtlMainColorFadeWork*)work;
    if (colorWork->currentFrame == 0)
    {
        global = iGpffffb3ac;
        *(RwV4d*)&colorWork->value0 = *(RwV4d*)(global + 0x25c);
    }

    target.x = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[4];
    target.y = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[5];
    target.z = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[6];
    target.w = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[7];
    totalFrames = colorWork->totalFrames;
    currentFrame = colorWork->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = colorWork->value0 * inverse + target.x * ratio;
        results.y = colorWork->value1 * inverse + target.y * ratio;
        results.z = colorWork->value2 * inverse + target.z * ratio;
        results.w = colorWork->value3 * inverse + target.w * ratio;
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x25c) = results;
    }
    else
    {
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x25c) = target;
        return 1;
    }

    colorWork->currentFrame++;
    return 0;
}
/* measured: restore common-subexpression optimization after func_001b96e0. */
#pragma opt_common_subs on
// FUN_001B99A0
void func_001b99a0(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x605, 0x18);
    packet->updateFunc = func_001b96e0;
    *(s32*)((u8*)packet->workData + 0x10) = arg;
}



// FUN_001B99F0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b99f0);
// FUN_001B9DE0
void func_001b9de0(s32 arg1, s16 arg2, s32 arg3)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x606, 0x10);
    packet->updateFunc = func_001b99f0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = arg1;
    *(s32*)(work + 4) = arg3;
    *(s16*)(work + 0xc) = arg2;
    *(s32*)(work + 8) = 0;
}



typedef struct BtlUnit BtlUnit;
typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;
extern void func_00194f60(BtlUnit* unit, RwRGBA col);
// FUN_001B9E50
u32 func_001b9e50(void* work)
{
    RwRGBA color;
    f32 temp_f1;
    f32 var_f0;
    f32 var_f1;
    BtlUnit *unit;
    s32 index;
    s32 result;
    s32 compareThreshold;
    u8 threshold;
    u32 current;
    u32 total;
    u8 *arg0;

    arg0 = (u8 *)work;
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x400000) != 0) &&
        ((*(u16 *)(iGpffffb3ac + 0x18) & 0x10) != 0))
    {
        return 1;
    }

    result = 1;
    total = *(u32 *)(arg0 + 0);
    current = *(u32 *)(arg0 + 4);
    if (current < total)
    {
        var_f1 = (f32)(u32)current;
        var_f0 = (f32)(u32)total;
        temp_f1 = 255.0f * (var_f1 / var_f0);
        threshold = (u8)temp_f1;
        result = 0;
    }
    else
    {
        threshold = 0xFF;
    }

    index = 0;
    compareThreshold = threshold & 0xFF;
    while ((index & 0xFFFF) < 2)
    {
        unit = *(BtlUnit **)(iGpffffb3ac + (((u16)index) * 8) + 0x178);
        while (unit != NULL)
        {
            if ((*(u16 *)((u8 *)unit + 0x9FE) != 0) &&
                ((*(s32 *)((u8 *)unit + 0x9C) & 1) == 0))
            {
                color = *(RwRGBA *)((u8 *)unit + 0x30);
                if ((s32)color.alpha < compareThreshold)
                {
                    color.alpha = threshold;
                    func_00194f60(unit, color);
                }
            }
            unit = *(BtlUnit **)((u8 *)unit + 0xA6C);
        }
        index = (index + 1) & 0xFFFF;
    }

    *(u32 *)(arg0 + 4) = *(u32 *)(arg0 + 4) + 1;
    return result;
}
// FUN_001BA090
void func_001ba090(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x607, 8);
    packet->updateFunc = func_001b9e50;
    *(s32*)packet->workData = arg;
}



// FUN_001BA9E0
u32 func_001ba9e0(u16 *param_1, f32 *param_2, f32 *param_3)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    if (param_1[0x3b] >= 4)
    {
        return 0;
    }
    index = param_1[0x3c];
    if (param_2 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 4);
        value2 = param_2[0];
        value3 = param_2[1];
        value1 = param_2[2];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value1;
        if ((*param_1 & 1) == 0)
        {
            func_003bb4a0(*(u32*)(param_1 + 0x4c), index, param_2);
        }
    }
    if (param_3 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 0x10);
        value2 = param_3[0];
        value3 = param_3[1];
        value4 = param_3[2];
        value1 = param_3[3];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value4;
        entry[3] = value1;
    }
    index++;
    if (index >= 4)
    {
        index = 0;
    }
    param_1[0x3c] = index;
    param_1[0x3b]++;
    return 1;
}



// FUN_001BAB00
void func_001bab00(u16 *param_1, f32 *param_2)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    *param_1 = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }
}



// FUN_001BAC20
void func_001bac20(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4)
{
    u16 index;
    u16 index0;
    u16 index1;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 work[7];

    *param_1 = param_4;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index0 = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index0, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index0++;
        if (index0 >= 4)
        {
            index0 = 0;
        }
        param_1[0x3c] = index0;
        param_1[0x3b]++;
    }

    func_001ba790(work, param_2, param_3, fGpffff80c0);
    if (param_1[0x3b] < 4)
    {
        index1 = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index1, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index1++;
        if (index1 >= 4)
        {
            index1 = 0;
        }
        param_1[0x3c] = index1;
        param_1[0x3b]++;
    }

    func_001ba790(work, param_2, param_3, fGpffff80c8);
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }

    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_3[0];
            value3 = param_3[1];
            value1 = param_3[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, param_3);
            }
        }
        source = param_3 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }
}



// FUN_001BAFF0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001baff0);
// FUN_001BB3D0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001bb3d0);
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_001BB790 NONMATCHING
#ifdef NON_MATCHING
extern f32 D_00881430;
extern f32 D_00881434;
extern f32 D_00881438;
void func_001bb790(u8 *arg0, f32 *arg1, f32 fparg0)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 temp_f5;
    u16 index;
    s32 i;
    u8 *p;

    f3 = 1.0f - fparg0;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = fparg0 * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = fparg0 * fparg0;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = fparg0 * f1;
    index = *(u16 *)(arg0 + 0x74);
    arg1[0] = D_00881430;
    arg1[1] = D_00881434;
    arg1[2] = D_00881438;
    i = 0;
    while ((i & 0xFFFF) < 4) {
        temp_f5 = weights[i & 0xFFFF];
        p = (u8 *)((index & 0xFFFF) * 0x1C) + (u32)arg0;
        arg1[0] += *(f32 *)(p + 4) * temp_f5;
        arg1[1] += *(f32 *)(p + 8) * temp_f5;
        arg1[2] += *(f32 *)(p + 0xC) * temp_f5;
        index = (u16)((index + 1) & 0xFFFF);
        if ((s32)index >= 4) {
            index = 0;
        }
        i = (i + 1) & 0xFFFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001bb790);
#endif
// FUN_001BB8C0
void func_001bb8c0(u8* param_2, f32* param_3, f32 param_1)
{
    u16 currentIndex;
    u16 nextIndex;
    u32 currentAddress;
    u32 nextAddress;
    f32 currentX;
    f32 currentY;
    f32 currentZ;
    f32 nextX;
    f32 nextY;
    f32 nextZ;
    f32 blend;
    f32 period;
    currentIndex = *(u16*)(param_2 + 0x74);
    period = fGpffff8434;
    while (param_1 >= period)
    {
        currentIndex++;
        param_1 -= period;
    }
    param_1 /= period;
    if (currentIndex >= 4)
    {
        currentIndex &= 3;
    }
    nextIndex = currentIndex + 1;
    if (nextIndex >= 4)
    {
        nextIndex &= 3;
    }
    blend = 1.0f - param_1;
    currentAddress = (u32)currentIndex * 0x1c;
    currentAddress = currentAddress + (u32)param_2;
    currentY = *(f32*)(currentAddress + 8);
    currentY = currentY * blend;
    currentZ = *(f32*)(currentAddress + 0xc);
    currentZ = currentZ * blend;
    nextAddress = (u32)nextIndex * 0x1c;
    nextAddress = nextAddress + (u32)param_2;
    nextY = *(f32*)(nextAddress + 8);
    nextY = nextY * param_1;
    nextZ = *(f32*)(nextAddress + 0xc);
    nextZ = nextZ * param_1;
    currentX = *(f32*)(currentAddress + 4);
    nextX = *(f32*)(nextAddress + 4);
    param_3[0] = currentX * blend + nextX * param_1;
    param_3[1] = currentY + nextY;
    param_3[2] = currentZ + nextZ;
}



// FUN_001BB9B0
void func_001bb9b0(u8* param_2, f32* param_3, f32 param_1)
{
    u16 index;
    u16 nextIndex;
    u8* currentAddress;
    u8* nextAddress;
    f32 period;
    f32 blend;
    f32 inverse;
    f32 f0;
    f32 f1;
    f32 f3;
    f32 f4;
    BtlMainSlerpResult result;

    blend = param_1;
    index = *(u16*)(param_2 + 0x74);
    period = fGpffff8434;
    while (blend >= period)
    {
        index++;
        blend -= period;
    }
    blend = blend / period;

    if (index >= 4)
        index &= 3;
    nextIndex = (u16)((index + 1) & 0xffff);
    if (nextIndex >= 4)
        nextIndex &= 3;

    nextAddress = param_2 + ((u32)nextIndex * 0x1c) + 0x10;
    currentAddress = param_2 + ((u32)index * 0x1c) + 0x10;
    func_003dcc70((f32*)currentAddress, (f32*)nextAddress, &result);

    if (blend <= 0.0f)
    {
        *(RwV4d*)param_3 = *(RwV4d*)currentAddress;
        return;
    }
    if (1.0f <= blend)
    {
        *(RwV4d*)param_3 = *(RwV4d*)nextAddress;
        return;
    }

    inverse = 1.0f - blend;
    if (result.mode == 0)
    {
        f4 = inverse * result.angle;
        f3 = f4 * f4;
        f0 = fGpffff83f8 * f3 + fGpffff8054;
        f0 = f3 * f0 + fGpffff8058;
        f0 = f3 * f0 + fGpffff8344;
        f0 = f3 * f0 + fGpffff843c;
        f1 = f3 * f0 + fGpffff8440;
        f0 = f3 * f4;
        inverse = f0 * f1 + f4;

        f4 = blend * result.angle;
        f3 = f4 * f4;
        f1 = fGpffff83f8 * f3 + fGpffff8054;
        f1 = f3 * f1 + fGpffff8058;
        f1 = f3 * f1 + fGpffff8344;
        f1 = f3 * f1 + fGpffff843c;
        f0 = f3 * f1 + fGpffff8440;
        f1 = f3 * f4;
        blend = f1 * f0 + f4;
    }

    param_3[0] = result.current0 * inverse;
    param_3[1] = result.current1 * inverse;
    param_3[2] = result.current2 * inverse;
    param_3[0] = result.next0 * blend + param_3[0];
    param_3[1] = result.next1 * blend + param_3[1];
    param_3[2] = result.next2 * blend + param_3[2];
    param_3[3] = result.current3 * inverse + result.next3 * blend;
}
// FUN_001BBC40
u32 func_001bbc40(u8* param_1, f32* param_2, f32* param_3)
{
    void* curve;
    u16 frame;
    u16 index;
    u8* entry;
    frame = *(u16*)(param_1 + 0x76);
    if (0 < frame)
    {
        goto has_frame;
    }
    return 0;
has_frame:
    if (frame < 2)
    {
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV3d *)param_2 = *(RwV3d *)(entry + 4);
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV4d *)param_3 = *(RwV4d *)(entry + 0x10);
        return 0;
    }
    if (frame < 4)
    {
        func_001bb8c0(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else if ((*(u16*)param_1 & 1) != 0)
    {
        func_001bb790(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else
    {
        curve = *(void* *)(param_1 + 0x98);
        func_003bb5b0((void*)curve, 0xa,
                     *(f32*)(param_1 + 0x7c),
                     (RwV3d *)param_2, ((void*)0));
    }
    func_001bb9b0(param_1, param_3, *(f32*)(param_1 + 0x7c));
    return 1;
}



// FUN_001BBD80
u32 func_001bbd80(u8* param_2, f32 param_1)
{
    u16 frame;
    u16 counter;
    u32 result;
    f32 value;
    frame = *(u16*)(param_2 + 0x76);
    if (frame < 2)
    {
        *(u32*)(param_2 + 0x7c) = 0;
        return 0;
    }
    value = *(f32*)(param_2 + 0x7c) + param_1;
    if (frame < 3)
    {
        if (!(value < fGpffff8434))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 1;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 1;
        }
    }
    else if (frame < 4)
    {
        if (!(value < fGpffff80c8))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 2;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 2;
        }
    }
    else if (!(value < fGpffff8438))
    {
        value = value - 1.0f;
        *(u16*)(param_2 + 0x76) = frame - 3;
        *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 3;
    }
    counter = *(u16*)(param_2 + 0x74);
    if (counter >= 4)
    {
        *(u16*)(param_2 + 0x74) = counter & 3;
    }
    *(f32*)(param_2 + 0x7c) = value;
    result = 1;
    return result;
}



// FUN_001BBEF0
void func_001bbef0(u8* work, f32 value)
{
    *(f32*)(work + 0x84) = (value * 2.0f * 60.0f) / 2.0f;
    *(u32*)(work + 0x94) = 0x3f000000;
    *(u16*)work = *(u16*)work & 0xfff5;
    *(u16*)work = *(u16*)work | 4;
}

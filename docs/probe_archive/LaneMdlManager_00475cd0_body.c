/* ModelLayoutRecovery, 2026-09-26: isolated full-TU probe, MWCC b210 -O2,
 * current mdlManager profile (schedule off). Not a production implementation.
 * Current guarded baseline: 4008/4000 bytes, fnalign 621 edits, frame 0x1E0.
 * This natural-layout candidate: 3960/4000 bytes, fnalign 571 edits,
 * plus 16 relocation-only substitutions; frame 0x1A0 as in retail.
 * Quaternion/result/cache: sp+0x70/0x80/0x90; omega/flag: +0xB0/+0xB4.
 * RtQuatSlerp interior 00475FFC..0047610F: 276 bytes (69 instructions),
 * zero relocation-masked differences. All six sine-pool words were compared
 * directly with retail and are equal. This is NOT a whole-function match.
 *
 * RtQuat/RtQuatSlerpCache and the macro definitions below are copied verbatim
 * from include/rw/inc/{rtquat.h,rtslerp.h,rwplcore.h} for isolated TU probing:
 * mdlManager currently defines its own RwV3d/RwMatrix, so including the full
 * SDK headers directly would conflict. No synthetic stack aggregate is used.
 *
 * Corrected retail behavior: distinct negate scratch/result, independent
 * slerp weights, fresh flags after getters, matrix identity initialization,
 * frame load before matrix calls, and callback-visible effect reloads.
 * Provider contract 0047DD40 now includes its unused owning-model argument,
 * proven by all three direct retail callsites. D540/D900 declarations agree
 * with their providers; AE90 uses its existing u16 slot-index contract.
 *
 * Remaining: parameter in s2 rather than retail s0, quaternion-dot load/acc
 * ordering, attached-model loop/CSE structure, and remaining register choices.
 * Do not restore incompatible prototypes to recover the lower score: omitting
 * AE90's narrow prototype yielded 3952 bytes / 516 edits but was not retained.
 * Source func_00475cd0 remains the existing guarded body plus ASM fallback.
 */
/* Historical measurements below describe the superseded synthetic-stack draft,
 * not the current candidate or current owner match counts. */
/* LaneMdlManager func_00475cd0 best: sched 4028B/4000B nd 915 (base 4524B nd 1014).
 * Retail window 4000B frame 0x1A0; candidate frame 0x1D0 (3 extra saved s5-s7).
 * First diffs sched at 0 (frame), 56 (sltu vs slt head), 64 (sb via $a2 vs direct 0x280),
 * 132+ (color alpha div/mul order), 260+ (flags CSE), 340+ (jal/addiu order).
 * Measured probe_variants (serial, isolated TU copies, source unchanged):
 *   base 1014, 77260-u64->void* 1014, noflags 1021, split-i/j/has 1014,
 *   csub_off 1057, prop_off 1024, loopinv 1014, sched_on 915 (-99, 4524->4028B),
 *   sched+csub 967, sched+prop 918, sched+nobrlikely 924, sched+loopinv 915,
 *   s32 915, u8cast 921, swap_ij 915, modellast 915, hasfirst 915, u8param 915, idx 916.
 * Floor: address-CSE (param+0x280/$a2, +0x260/s2, +0xD3/s7 saved vs retail direct),
 *   saved-coloring (param s4 vs s0, 8 vs 5 regs), branch-likely under sched (beql vs beqz),
 *   value(0x80)+result(0x90,40B) vs merged interpolation, easing two-stage vs independent curves.
 * Production remains INCLUDE_ASM; owner 126 markers, 120 MATCH/6 ASM unchanged. func_00479100 untouched (29-word floor).
 */

typedef f32 RwReal;
typedef s32 RwBool;
#define MACRO_START do
#define MACRO_STOP while(0)
typedef struct RtQuat RtQuat;
struct RtQuat
{
    RwV3d               imag;   /**< The imaginary part(s) */
    RwReal              real;   /**< The real part */
};

typedef struct RtQuatSlerpCache RtQuatSlerpCache;
struct RtQuatSlerpCache
{
    RtQuat              raFrom; /**< Scaled initial quaternion  */
    RtQuat              raTo;   /**< Scaled final quaternion */
    RwReal              omega;  /**< Angular displacement in radians */
    RwBool              nearlyZeroOm; /**< Flags near-zero angular 
                                                displacement*/
};
#define   _RW_S1      ( (float)-1.6666667163e-01 )
#define   _RW_S2      ( (float) 8.3333337680e-03 )
#define   _RW_S3      ( (float)-1.9841270114e-04 )
#define   _RW_S4      ( (float) 2.7557314297e-06 )
#define   _RW_S5      ( (float)-2.5050759689e-08 )
#define   _RW_S6      ( (float) 1.5896910177e-10 )
#define RwSinMinusPiToPiMacro(result, x)                          \
do                                                                \
{                                                                 \
    const float z = x * x;                                        \
    const float v = z * x;                                        \
    const float r = ( _RW_S2 +                                    \
                      z * (_RW_S3 +                               \
                           z * (_RW_S4 +                          \
                                z * (_RW_S5 +                     \
                                     z * _RW_S6))) );             \
    result = x + v * (_RW_S1 + z * r);                            \
}                                                                 \
while(0)                                                                  

#define RwV3dScaleMacro(o, a, s)                                \
MACRO_START                                                     \
{                                                               \
    (o)->x = (((a)->x) * ( (s)));                               \
    (o)->y = (((a)->y) * ( (s)));                               \
    (o)->z = (((a)->z) * ( (s)));                               \
}                                                               \
MACRO_STOP

#define RwV3dIncrementScaledMacro(o, a, s)                      \
MACRO_START                                                     \
{                                                               \
    (o)->x += (((a)->x) * ( (s)));                              \
    (o)->y += (((a)->y) * ( (s)));                              \
    (o)->z += (((a)->z) * ( (s)));                              \
}                                                               \
MACRO_STOP

#define RtQuatSlerpMacro(qpResult, qpFrom, qpTo, rT, sCache)            \
MACRO_START                                                             \
{                                                                       \
    if ((rT) <= ((RwReal) 0))                                           \
    {                                                                   \
        /* t is before start */                                         \
        *(qpResult) = *(qpFrom);                                        \
    }                                                                   \
    else if (((RwReal) 1) <= (rT))                                      \
    {                                                                   \
                                                                        \
        /* t is after end */                                            \
        *(qpResult) = *(qpTo);                                          \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* ... so t must be in the interior then */                     \
        /* Calc coefficients rSclFrom, rSclTo */                        \
        RwReal rSclFrom = ((RwReal) 1) - (rT);                          \
        RwReal rSclTo = (rT);                                           \
                                                                        \
        if (!((sCache)->nearlyZeroOm))                                  \
        {                                                               \
            /* Standard case: slerp */                                  \
            /* SLERPMESSAGE(("Neither nearly ZERO nor nearly PI")); */  \
                                                                        \
            rSclFrom *= (sCache)->omega;                                \
            RwSinMinusPiToPiMacro(rSclFrom, rSclFrom);                   \
            rSclTo *= (sCache)->omega;                                  \
            RwSinMinusPiToPiMacro(rSclTo, rSclTo);                       \
        }                                                               \
                                                                        \
        /* Calc final values */                                         \
        RwV3dScaleMacro(&(qpResult)->imag,                              \
                        &(sCache)->raFrom.imag, rSclFrom);              \
        RwV3dIncrementScaledMacro(&(qpResult)->imag,                    \
                             &(sCache)->raTo.imag, rSclTo);             \
        (qpResult)->real =                                              \
            ((sCache)->raFrom.real * rSclFrom) +                        \
            ((sCache)->raTo.real * rSclTo);                             \
    }                                                                   \
}                                                                       \
MACRO_STOP
#define RtQuatNegateMacro( result, q )                                     \
MACRO_START                                                                \
{                                                                          \
    (result)->real = -(q)->real;                                           \
    (result)->imag.x = -(q)->imag.x;                                       \
    (result)->imag.y = -(q)->imag.y;                                       \
    (result)->imag.z = -(q)->imag.z;                                       \
}                                                                          \
MACRO_STOP
typedef struct Mdl475State {
    RwMatrix matrix;
    RwMatrix identityMatrix;
    RwV3d scale;
    u8 unknown8c[0xD0-0x8C];
    RwRGBA color;
    u32 unknownD4;
    u32 flagsD8;
    void* clump;
    void* e0;
    u8 unknownE4[8];
    u16 animFlags;
    u8 unknownEE[2];
    s16 animIndex;
    u8 unknownF2[0x10C-0xF2];
    void* hierarchy;
    u8 unknown110[0x120-0x110];
    void* animations;
    void* effect124;
    u8 unknown128[0x140-0x128];
    u16 flags140;
    u8 unknown142[0x234-0x142];
    u8 state234[0x2C];
    u8 flags;
    u8 unknown261[3];
    RtQuat rotation;
    f32 limit;
    f32 targetLimit;
    f32 limitRate;
    u8 alpha;
    u8 targetAlpha;
    u8 alphaStep;
    u8 unknown283;
    f32 minBlend;
    f32 maxAngle;
} Mdl475State;
void func_00475cd0(Mdl475State* param_1)
{
    extern void RpSkyRenderStateSet(s32 a, s32 b);
    extern void func_00477260(void* a, u32* b, u16 c);
    extern void func_004789c0(Model* a);
    extern s32 RtQuatConvertFromMatrix(RtQuat* out, const RwMatrix* in);
    extern RwV3d* RtQuatTransformVectors(RwV3d* out, const RwV3d* in, s32 count, const RtQuat* quat);
    extern void func_003dcc70(f32* first, f32* second, void* result);
    extern f32 func_0044b920(f32 value);
    extern s32 func_004571b0(void);
    extern s32 func_004571c0(void);
    extern void func_004746b0(u8* a, u8* b);
    extern void func_00479910(void* a);
    extern void* mdlGetMatrix(void* a);
    extern s32 func_0047a510(void* a, s32 b, void* c);
    extern s32 func_0047ae90(u8* model, u16 index);
    extern void func_0047d540(u8** a, u8* b);
    extern void func_0047d900(s32* a, f32* b);
    extern void func_0047dd40(u8* a, void* model);
    extern void (*D_00887300_abs[])(s32, s32);
    extern void (*D_00887304[])(s32, void*);

    s32 current;
    s32 target;
    s32 value;
    u32 flags;
    RwRGBA color;
    s32 renderState;
    RwV3d direction;
    RwMatrix matrix1;
    RwMatrix matrix0;
    RwMatrix identity;
    RtQuatSlerpCache interpolation;
    RtQuat result;
    RtQuat quaternion;
    void (**renderStateSet)(s32, s32);
    u8* effect;
    u8* slot;
    u8* model;
    u8* animation;
    u16 i;
    u16 j;
    u16 k;
    u32 hasIndex;
    u32 hasItem;
    u32 needsReset;
    u32 copyCount;
    u32* copySource;
    u32* copyTarget;

    target = param_1->targetAlpha;
    current = param_1->alpha;
    if (current < target) {
        value = current + param_1->alphaStep;
        if (target < value) {
            param_1->alpha = (u8)target;
        } else {
            param_1->alpha = (u8)value;
        }
    } else if (target < current) {
        value = current - param_1->alphaStep;
        if (value < target) {
            param_1->alpha = (u8)target;
        } else {
            param_1->alpha = (u8)value;
        }
    } else {
        param_1->alpha = (u8)target;
    }

    color.red = 0;
    color.green = 0;
    color.blue = 0;
    color.alpha = (u8)(255.0f * ((f32)(param_1->alpha
                         * param_1->color.alpha) / (255 * 255)));

    {
    u8* material;
    flags = param_1->flags;
    if ((flags & 1) != 0 && (flags & 0x20) == 0) {
        material = *(u8**)((u8*)func_004571b0() + 4);
    } else {
        material = *(u8**)((u8*)func_004571c0() + 4);
    }

    flags = param_1->flags;
    if ((flags & 2) != 0 && (flags & 0x20) == 0) {
        if ((flags & 4) == 0) {
            RtQuatConvertFromMatrix(&quaternion, (const RwMatrix*)(material + 0x10));
        } else {
            quaternion.imag.x = 0.707107f;
            quaternion.imag.y = 0.0f;
            quaternion.imag.z = 0.0f;
            quaternion.real = quaternion.imag.x;
        }
        {
            f32 dot;
            f32 angle;
            f32 amount;
            f32 limit;
            dot = param_1->rotation.imag.x * quaternion.imag.x
                + param_1->rotation.imag.y * quaternion.imag.y
                + param_1->rotation.imag.z * quaternion.imag.z
                + param_1->rotation.real * quaternion.real;
            if (dot < 0.0f) {
                RtQuatNegateMacro(&result, &quaternion);
                dot = param_1->rotation.imag.y * result.imag.y
                    + param_1->rotation.imag.x * result.imag.x
                    + param_1->rotation.imag.z * result.imag.z
                    + param_1->rotation.real * result.real;
            }
            angle = 2.0f * func_0044b920(dot);
            limit = param_1->minBlend;
            if (limit < 1.0f) {
                f32 maximum;
                maximum = param_1->maxAngle;
                if (!(angle <= maximum)) {
                    amount = maximum / angle;
                    if (amount < limit) {
                        amount = limit;
                    }
                } else {
                    amount = limit;
                }
                func_003dcc70((f32*)&param_1->rotation, (f32*)&quaternion,
                              &interpolation);
                RtQuatSlerpMacro(&result, &param_1->rotation, &quaternion,
                                amount, &interpolation);
                *&param_1->rotation = result;
            } else {
                param_1->rotation = quaternion;
            }
        }
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &param_1->rotation);
    } else {
        u8* source = material + 0x10;
        RtQuatConvertFromMatrix(&param_1->rotation, (const RwMatrix*)source);
        direction = ((RwMatrix*)source)->at;
    }

    }

    if (color.alpha == 0) {
        if ((param_1->animFlags & 0x10) != 0) {
            func_00473000(param_1->hierarchy,
                          (u8*)&param_1->animFlags);
        } else if ((param_1->flags140 & 0x81E0) != 0) {
            func_00471370(param_1->hierarchy,
                          (u8*)&param_1->animFlags, (u8*)&param_1->flags140, 0);
        } else {
            func_00397c40(param_1->hierarchy);
        }
        if ((param_1->flagsD8 & 0x80000) != 0) {
            func_004746b0(param_1->state234, (u8*)&param_1->animFlags);
        }
        j = 0;
        while (j < 5) {
            slot = (u8*)param_1 + j * 0xC;
            if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
                *(void**)(slot + 0x290) != 0 &&
                func_0047ae90((u8*)param_1, j) != 0) {
                model = *(u8**)(slot + 0x290);
                if ((*(u32*)(model + 0xD8) & 2) == 0) {
                    if (*(s32*)(slot + 0x294) != -1) {
                        func_0047a510(param_1, *(s32*)(slot + 0x294),
                                      mdlGetMatrix(model));
                    } else {
                        copyCount = 8;
                        copySource = (u32*)param_1;
                        copyTarget = (u32*)model;
                        do {
                            copyTarget[0] = copySource[0];
                            copyTarget[1] = copySource[1];
                            copySource += 2;
                            copyTarget += 2;
                            copyCount--;
                        } while (copyCount > 0);
                    }
                    hasIndex = 0;
                    hasItem = 0;
                    needsReset = 0;
                    animation = *(u8**)(model + 0x120);
                    if (animation != 0 &&
                        *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                        hasIndex = 1;
                    }
                    if (hasIndex != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                        hasItem = 1;
                    }
                    if (hasItem != 0 &&
                        *(void**)((u8*)*(void**)animation
                                  + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                            != (void*)D_00922BC0_abs) {
                        needsReset = 1;
                    }
                    if (needsReset != 0) {
                        func_00397c40(*(void**)(model + 0x10C));
                    }
                    if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                        func_004746b0(model + 0x234, model + 0xEC);
                    }
                }
            }
            j++;
        }
        return;
    }

    if (!(direction.y < 0.0f)) {
        f32 unit;
        unit = 0.707107f;
        param_1->rotation.imag.x = unit;
        param_1->rotation.imag.y = 0.0f;
        param_1->rotation.imag.z = 0.0f;
        param_1->rotation.real = unit;
        RtQuatTransformVectors(&direction, (const RwV3d*)(D_00713138 + 0x10), 1,
                      &param_1->rotation);
    }
    if (param_1->limit !=
        param_1->targetLimit) {
        param_1->limit =
            param_1->limit
            + param_1->limitRate
              * (param_1->targetLimit
                 - param_1->limit);
    }
    {
        f32 limit;
        limit = param_1->limit;
        if (fabsf(direction.y) < limit) {
            if (direction.y < 0.0f) {
                direction.y = -limit;
            } else {
                direction.y = limit;
            }
        }
    }

    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    identity.flags |= 0x20003;
    identity.up.x = -direction.x / direction.y;
    identity.up.y = 0.01f;
    identity.up.z = -direction.z / direction.y;

    {
    void* frame = *(void**)((u8*)param_1->clump + 4);
    RwMatrixMultiply(&matrix0, &param_1->identityMatrix, param_1);
    RwMatrixMultiply(&matrix1, &matrix0, &identity);
    func_003e9cb0(frame, &matrix1, 0);
    }
    if ((param_1->flags140 & 0x4000) != 0) {
        func_00471370(param_1->hierarchy,
                      (u8*)&param_1->animFlags, (u8*)&param_1->flags140,
                      &identity);
    } else {
        func_00397c40(param_1->hierarchy);
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](6, 1);
    renderStateSet[0](8, 0);
    D_00887304[0](0xE, &renderState);
    renderStateSet[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    if ((param_1->flagsD8 & 0x80000) != 0) {
        func_004746b0(param_1->state234, (u8*)&param_1->animFlags);
    }
    func_00477260(param_1->clump, (u32*)&color,
                        (u16)((param_1->flags & 8) != 0));
    effect = (u8*)param_1->e0;
    if (effect == 0) {
        RpSkyRenderStateSet(3, 0x7C01B);
    } else if ((*(s32*)(effect + 0x10) != 0 || *(s32*)(effect + 0x1C) != 0)
               && ((param_1->flags & 0x80) == 0)) {
        RpSkyRenderStateSet(3, 0x7F06B);
    } else {
        RpSkyRenderStateSet(3, 0x7D7FB);
    }
    func_00479910(param_1->clump);
    func_004789c0((Model*)param_1);
    if ((param_1->animFlags & 0x10) != 0) {
        func_00473000(param_1->hierarchy,
                      (u8*)&param_1->animFlags);
    } else if ((param_1->flags140 & 0x81E0) != 0) {
        func_00471370(param_1->hierarchy,
                      (u8*)&param_1->animFlags, (u8*)&param_1->flags140, 0);
    } else {
        func_00397c40(param_1->hierarchy);
    }
    effect = *(u8**)((u8*)param_1 + 0x2CC);
    if (effect != 0) {
        func_0047d900((s32*)effect, (f32*)(&param_1->scale));
        func_0047d540(*(u8***)((u8*)param_1 + 0x2CC), (u8*)param_1);
    }
    {
    u8* model;
    i = 0;
    while (i < 2) {
        model = *(u8**)((u8*)param_1 + i * 0xA4 + 0x124);
        if (model != 0) {
            effect = *(u8**)(model + 0x18);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047d900((s32*)effect, (f32*)(model + 8));
                func_0047d540(*(u8***)(model + 0x18), (u8*)param_1);
            }
            effect = *(u8**)(model + 0x24);
            if (effect != 0 && *(u16*)(model + 0x30) == 0) {
                func_0047dd40(effect, param_1);
            }
            if (*(u16*)(model + 0x30) > 0) {
                *(u16*)(model + 0x30) -= 1;
            }
        }
        i++;
    }
    }
    j = 0;
    while (j < 5) {
        slot = (u8*)param_1 + j * 0xC;
        if ((*(u8*)(slot + 0x28C) & 1) != 0 &&
            *(void**)(slot + 0x290) != 0 &&
            func_0047ae90((u8*)param_1, j) != 0) {
            model = *(u8**)(slot + 0x290);
            if (*(s32*)(slot + 0x294) != -1) {
                func_0047a510(param_1, *(s32*)(slot + 0x294),
                              mdlGetMatrix(model));
            } else {
                copyCount = 8;
                copySource = (u32*)param_1;
                copyTarget = (u32*)model;
                do {
                    copyTarget[0] = copySource[0];
                    copyTarget[1] = copySource[1];
                    copySource += 2;
                    copyTarget += 2;
                    copyCount--;
                } while (copyCount > 0);
            }
            if ((*(u32*)(model + 0xD8) & 2) == 0 &&
                param_1->color.alpha != 0) {
                u8* source = *(u8**)(model + 0xDC);
                u8* material = *(u8**)(source + 4);
                RwMatrixMultiply(&matrix0, model + 0x40, model);
                RwMatrixMultiply(&matrix1, &matrix0, &identity);
                func_003e9cb0(material, &matrix1, 0);
                hasIndex = 0;
                hasItem = 0;
                needsReset = 0;
                animation = *(u8**)(model + 0x120);
                if (animation != 0 &&
                    *(s16*)(model + 0xF0) < *(u16*)(animation + 8)) {
                    hasIndex = 1;
                }
                if (hasIndex != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40) != 0) {
                    hasItem = 1;
                }
                if (hasItem != 0 &&
                    *(void**)((u8*)*(void**)animation
                              + *(s16*)(model + 0xF0) * 0x50 + 0x40)
                        != (void*)D_00922BC0_abs) {
                    needsReset = 1;
                }
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                if ((*(u32*)(model + 0xD8) & 0x80000) != 0) {
                    func_004746b0(model + 0x234, model + 0xEC);
                }
                func_00477260(source, (u32*)&color,
                                    (u16)((*(u8*)(model + 0x260) & 8) != 0));
                effect = (u8*)param_1->e0;
                if (effect == 0) {
                    RpSkyRenderStateSet(3, 0x7C01B);
                } else if (*(s32*)(effect + 0x10) != 0 ||
                           *(s32*)(effect + 0x1C) != 0) {
                    RpSkyRenderStateSet(3, 0x7F08B);
                } else {
                    RpSkyRenderStateSet(3, 0x7D7FB);
                }
                func_00479910(source);
                func_004789c0((Model*)model);
                if (needsReset != 0) {
                    func_00397c40(*(void**)(model + 0x10C));
                }
                effect = *(u8**)(model + 0x2CC);
                if (effect != 0) {
                    func_0047d900((s32*)effect, (f32*)(model + 0x80));
                    func_0047d540(*(u8***)(model + 0x2CC), model);
                }
                k = 0;
                while (k < 2) {
                    effect = *(u8**)(model + k * 0xA4 + 0x124);
                    if (effect != 0) {
                        source = *(u8**)(effect + 0x18);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047d900((s32*)source, (f32*)(effect + 8));
                            func_0047d540(*(u8***)(effect + 0x18), model);
                        }
                        source = *(u8**)(effect + 0x24);
                        if (source != 0 && *(u16*)(effect + 0x30) == 0) {
                            func_0047dd40(source, model);
                        }
                        if (*(u16*)(effect + 0x30) > 0) {
                            *(u16*)(effect + 0x30) -= 1;
                        }
                    }
                    k++;
                }
            }
        }
        j++;
    }
    renderStateSet = D_00887300_abs;
    renderStateSet[0](0xE, renderState);
    RpSkyRenderStateSet(3, 0x717FB);
    renderStateSet[0](8, 1);
}

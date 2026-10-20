#include "member_access.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_emitter_internal.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
#include "particle_spawn_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

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

extern f32 func_0044b950(f32 left, f32 right);
extern f32 fabsf(f32 value);
extern void effMiscBuildRotationVU(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 0048a980-0048b9e0 */

typedef struct EffectPackedColorKeys {
    u8 mode;
    u8 pad01[3];
    u32 startColor;
    u32 endColor;
    u32 firstMiddleColor;
    f32 firstFraction;
    u32 secondMiddleColor;
    f32 secondFraction;
} EffectPackedColorKeys;
typedef struct EffectPackedOpacityKeys {
    u32 alpha;
    u32 field04;
    f32 fadeInFraction;
    f32 fadeOutFraction;
} EffectPackedOpacityKeys;
/* Evaluate the fade-in, full-opacity plateau and fade-out portions of a color key. */
static inline f32 mdlEffectColorOpacity(s32 frame, s32 duration, s32 fadeIn, s32 fadeOut, f32 fullOpacity)
{
    if (frame < fadeIn) {
        return (f32)frame / (f32)fadeIn;
    }
    if (fadeOut < frame) {
        return (f32)(duration - frame) / (f32)(duration - fadeOut);
    }
    return fullOpacity;
}
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off keeps `alloc` live in $s1 across all three
   allocations instead of re-materialising the table address at the first use. */
/* measured: closes the propagation bracket; the file default is on. */
    /* measured: O1 probe for initial flag and aggregate register colours. */
    /* measured: closes O1 probe for initial flag and aggregate register colours. */
/* measured: opening optimization_level 1 for the parked 00486970 body. */
/* measured: closes optimization_level 1 for the parked 00486970 body. */
/* Measured with b210 -O2: keeping the trace/diagonal stages and the scaled
   root as distinct lifetimes reproduces the scalar calculation. Propagation
   and common-subexpression elimination otherwise merge the identity
   constants and discard the root copy before register coalescing. */
#pragma push
/* measured: func_0048a980 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_0048a980 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Convert the matrix rotation to a quaternion returned in VU0 VF10. */
// FUN_0048A980
void effMiscMatrixToQuatVU(f32 *matrix)
{
    /* Matrix rows and quaternion lanes retain their original byte-index arithmetic. */
    f32 *nextDiagonal;
    f32 *selectedDiagonal;
    f32 *lastDiagonal;
    f32 *selectedNext;
    f32 *nextSelected;
    f32 *selectedLast;
    f32 *lastSelected;
    f32 *nextLast;
    f32 *lastNext;

    extern f32 sqrtf(f32);
    f32 q[4] __attribute__((aligned(16)));
    f32 zz, yy, xx;
    f32 one;
    f32 traceXY, traceXYZ, trace;

    yy = matrix[5];
    xx = matrix[0];
    zz = matrix[10];
    one = 1.0f;
    traceXY = xx + yy;
    traceXYZ = zz + traceXY;
    trace = one + traceXYZ;
    if (!(trace < one)) {
        f32 s = 2.0f * sqrtf(trace);
        q[3] = -(s / 4.0f);
        q[0] = (matrix[6] - matrix[9]) / s;
        q[1] = (matrix[8] - matrix[2]) / s;
        q[2] = (matrix[1] - matrix[4]) / s;
    } else {
        u32 selected = (((xx > yy) ? 1 : 0) ^ 1) & 0xFF;
        s32 i;
        s32 j, k;
        s32 axisCount;
        s32 next;
        s32 oi, oj, ok;
        u8 *ri, *rj, *rk;
        f32 dj, delta, radicand, sum;
        f32 root;
        f32 identity;
        f32 zero;

        if (!(zz <= ((EffectVuVector *)matrix)[selected].lane[selected])) { /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            u8 third = 2;
            selected = third;
        }
        i = (u8)selected;
        next = i + 1;
        axisCount = 3;
        j = (u8)(next % axisCount);
        k = (u8)((j + 1) % axisCount);
        oj = j * 4;
        rj = (u8 *)matrix + j * 16;
        dj = *(nextDiagonal = (f32 *)(rj + oj)); /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
        oi = i * 4;
        ri = (u8 *)matrix + i * 16;
        delta = *(selectedDiagonal = (f32 *)(ri + oi)) - dj; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
        ok = k * 4;
        rk = (u8 *)matrix + k * 16;
        radicand = delta - *(lastDiagonal = (f32 *)(rk + ok)); /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
        identity = 1.0f;
        sum = identity + radicand;
        root = sqrtf(sum);
        {
            f32 scaled = 2.0f * root;
            root = scaled;
        }
        zero = 0.0f;
        if (zero != root) {
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + oi) = root / 4.0f; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + oj) = (*(selectedNext = (f32 *)(ri + oj)) + *(nextSelected = (f32 *)(rj + oi))) / root; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + ok) = (*(selectedLast = (f32 *)(ri + ok)) + *(lastSelected = (f32 *)(rk + oi))) / root; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            q[3] = -((*(nextLast = (f32 *)(rj + ok)) - *(lastNext = (f32 *)(rk + oj))) / root); /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
        } else {
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + oi) = identity; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + oj) = zero; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            *(f32 *)((u8 *)q + MEMBER_OFFSET(EffectVuVector, lane) + ok) = zero; /* measured: byte-indexed matrix/quaternion addressing preserves MATCH. */
            q[3] = zero;
        }
    }
    /* The quaternion is returned through the established VU0 vf10 ABI. */
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(q), "m"(q) : "$vf10");
}

#pragma pop
/* Interpolate the configured RGB keys in VU0 and apply the independent alpha
 * envelope. Packed RGBA returns as a sign-extended 32-bit word.
 * measured: native b210 -O2, 1044/1056 bytes, one exact resolved relocation. */
// FUN_0048ABD0
s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration) {
    const EffectPackedColorKeys *colors = (const EffectPackedColorKeys *)colorData;
    const EffectPackedOpacityKeys *opacityKeys = (const EffectPackedOpacityKeys *)opacityData;
    s32 secondColor;
    s32 firstColor;
    s32 packedRgb;
    s32 mixedColor;
    const s32 *colorSource;
    f32 normalization;
    f32 blend;
    f32 durationFloat;
    f32 scaledAlpha;
    f32 alphaFloat;
    f32 opacity;
    s32 baseAlpha;
    s32 alpha;
    s32 endColor;
    s32 startColor;
    u8 mode;
    f32 inverseBlend;
    f32 segmentSpan;
    s32 endFrame;
    s32 startFrame;

    if (duration == 0) {
        return (s32)((colors->startColor & 0xFFFFFFU) |
                     (opacityKeys->alpha << 24));
    }
    durationFloat = (f32)duration;
    mode = colors->mode;
    switch (mode) {
    case 0:
        startColor = (s32)colors->startColor;
        endColor = (s32)colors->endColor;
        blend = (f32)frame / durationFloat;
        break;
    case 1:
        endFrame = (s32)(colors->firstFraction * durationFloat);
        if (frame < endFrame) {
            startColor = (s32)colors->startColor;
            endColor = (s32)colors->firstMiddleColor;
            blend = (f32)frame / (f32)endFrame;
        } else {
            startColor = (s32)colors->firstMiddleColor;
            endColor = (s32)colors->endColor;
            blend = (segmentSpan = (f32)(duration - endFrame), (f32)(frame - endFrame) / segmentSpan);
        }
        break;
    case 2:
        startFrame = (s32)(colors->firstFraction * durationFloat);
        if (frame < startFrame) {
            startColor = (s32)colors->startColor;
            endColor = (s32)colors->firstMiddleColor;
            blend = (f32)frame / (f32)startFrame;
        } else {
            endFrame = (s32)(colors->secondFraction * durationFloat);
            if (frame < endFrame) {
                startColor = (s32)colors->firstMiddleColor;
                endColor = (s32)colors->secondMiddleColor;
                blend = (segmentSpan = (f32)(endFrame - startFrame), (f32)(frame - startFrame) / segmentSpan);
            } else {
                startColor = (s32)colors->secondMiddleColor;
                endColor = (s32)colors->endColor;
                blend = (segmentSpan = (f32)(duration - endFrame), (f32)(frame - endFrame) / segmentSpan);
            }
        }
        break;
    default:
        startColor = (s32)colors->startColor;
        endColor = (s32)colors->endColor;
        blend = 0.0f;
        break;
    }
    secondColor = endColor;
    colorSource = &secondColor;
    normalization = fGpffff8044;
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vmove.xyzw $vf11, $vf10\n"
        : : "r"(colorSource), "f"(normalization), "m"(secondColor)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    firstColor = startColor;
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : : "r"(&firstColor), "f"(normalization), "m"(firstColor)
        : "$2", "$vf2", "$vf10", "memory");
    opacity = 1.0f; /* Full alpha between the two independently configured ramps. */
    inverseBlend = opacity - blend;
    __asm__ volatile(
        "mfc1 $2, %0\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        "vadd.xyzw $vf10, $vf10, $vf11\n"
        : : "f"(inverseBlend), "f"(blend)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    {
        u32 colorWork = 0x437F0000U; /* Binary32 255.0f for the VU color scale. */
        __asm__ volatile(
            "qmtc2.ni %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packedRgb\n"
            : "+r"(colorWork), "=m"(packedRgb)
            : : "$vf2", "$vf10", "memory");
    }
    mixedColor = packedRgb;
    {
        s32 fadeIn = (s32)(opacityKeys->fadeInFraction * durationFloat);
        s32 fadeOut = (s32)(opacityKeys->fadeOutFraction * durationFloat);
        opacity = mdlEffectColorOpacity(frame, duration, fadeIn, fadeOut, opacity);
    }
    baseAlpha = (s32)opacityKeys->alpha;
    alphaFloat = (f32)(u32)baseAlpha;
    scaledAlpha = alphaFloat * opacity;
    alpha = (s32)(u32)scaledAlpha;
    return (s32)(((u32)mixedColor & 0xFFFFFFU) | ((u32)alpha << 24));
}

/* measured: opt_propagation off tested for target subtraction scheduling. */
/* measured: func_0048aff0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Interpolate scalar keys across one, two or three time segments. */
// FUN_0048AFF0
f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration)
{
    u8 mode;
    f32 from;
    f32 to;
    f32 t;
    f32 durationFloat;

    if (duration == 0) {
        return ((MdlEffectScalarKeys *)keys)->start;
    }

    durationFloat = (f32)duration;
    mode = ((MdlEffectScalarKeys *)keys)->mode;
    switch (mode) {
    case 0:
        from = ((MdlEffectScalarKeys *)keys)->start;
        to = ((MdlEffectScalarKeys *)keys)->end;
        t = (f32)frame / durationFloat;
        break;
    case 1: {
        s32 middleFrame = (s32)(((MdlEffectScalarKeys *)keys)->firstFraction * durationFloat);
        if (frame < middleFrame) {
            from = ((MdlEffectScalarKeys *)keys)->start;
            to = ((MdlEffectScalarKeys *)keys)->firstMiddle;
            t = (f32)frame / (f32)middleFrame;
        } else {
            f32 denom;
            from = ((MdlEffectScalarKeys *)keys)->firstMiddle;
            to = ((MdlEffectScalarKeys *)keys)->end;
            denom = (f32)(duration - middleFrame);
            t = (f32)(frame - middleFrame) / denom;
        }
        break;
    }
    case 2: {
        s32 firstFrame = (s32)(((MdlEffectScalarKeys *)keys)->firstFraction * durationFloat);
        if (frame < firstFrame) {
            from = ((MdlEffectScalarKeys *)keys)->start;
            to = ((MdlEffectScalarKeys *)keys)->firstMiddle;
            t = (f32)frame / (f32)firstFrame;
        } else {
            s32 secondFrame = (s32)(((MdlEffectScalarKeys *)keys)->secondFraction * durationFloat);
            if (frame < secondFrame) {
                from = ((MdlEffectScalarKeys *)keys)->firstMiddle;
                to = ((MdlEffectScalarKeys *)keys)->secondMiddle;
                {
                    f32 denom = (f32)(secondFrame - firstFrame);
                    t = (f32)(frame - firstFrame) / denom;
                }
            } else {
                f32 denom;
                from = ((MdlEffectScalarKeys *)keys)->secondMiddle;
                to = ((MdlEffectScalarKeys *)keys)->end;
                denom = (f32)(duration - secondFrame);
                t = (f32)(frame - secondFrame) / denom;
            }
        }
        break;
    }
    default:
        from = ((MdlEffectScalarKeys *)keys)->start;
        to = ((MdlEffectScalarKeys *)keys)->end;
        t = 0.0f;
        break;
    }

    return from + t * (to - from);
}

/* measured: restore opt_propagation after func_0048aff0. */
/* Sample particle color, size and angle; angle mode two derives screen-space motion direction. */
// FUN_0048B220
void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition)
{
    MdlEffectEmitterParameters *colorParameters;
    MdlEffectEmitterParameters *sizeParameters;

    s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
    f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
    f32 mdlEffectProjectAnchorDepth(void);
    u_long128 projectedDelta;
    s32 size;

    size = (colorParameters = (MdlEffectEmitterParameters *)parameters)->lifetime; /* measured: the separate typed pointer preserves MATCH under b210. */
    *(s32 *)&((SpawnParticle *)particle)->color =
        mdlEffectSamplePackedColor(parameters + 0x2C, parameters + 0x50, frame, size);
    size = (sizeParameters = (MdlEffectEmitterParameters *)parameters)->lifetime; /* measured: the separate typed pointer preserves MATCH under b210. */
    ((SpawnParticle *)particle)->size =
        mdlEffectSampleScalarKeys(parameters + 0x60, frame, size);
    if (((MdlEffectEmitterParameters *)parameters)->angleMode != 2) {
        size = ((MdlEffectEmitterParameters *)parameters)->lifetime;
        ((SpawnParticle *)particle)->angle =
            mdlEffectSampleScalarKeys(parameters + 0x8C, frame, size);
        return;
    }
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(particle) : "$vf10", "memory");
    mdlEffectProjectAnchorDepth();
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(previousPosition) : "$vf10", "memory");
    mdlEffectProjectAnchorDepth();
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&projectedDelta) : "$vf10", "memory");
    if ((((EffectVuVector *)&projectedDelta)->lane[0] != 0.0f) ||
        (((EffectVuVector *)&projectedDelta)->lane[1] != 0.0f)) {
        ((SpawnParticle *)particle)->angle =
            func_0044b950(((EffectVuVector *)&projectedDelta)->lane[1],
                          ((EffectVuVector *)&projectedDelta)->lane[0]);
        return;
    }
    ((SpawnParticle *)particle)->angle = 0.0f;
}

/* Guarded rewrite, 2026-10-07: 54 differing words (was 160). The quads copy
 * through u_long128 pointer locals, the colour packs store the named slot
 * inside the asm, and the loop bounds hoist -1 as retail does. The second
 * quad's `(u32)c4 * 32` stops the stride CSE (that also fixed the c0/stride
 * $s7/$fp swap), `c4 << 6` and integer-cast sums give retail's addu operand
 * order, and the declaration order is the regalloc model's (k, i, src1,
 * iter, clear, j, dst1, c4). Open: retail rematerialises 1.0f in the else
 * branch, but b210's codegen reuses the entry's constant temporary there
 * (already shared at codegen_entry), and the else-branch temporaries then
 * colour one register lower ($v1/$a0... instead of $a3/$v1...).
 * 2026-10-09: 54 -> 24: the else branch's last-node pointer lives in `dst1`
 * (dead after the first copy loop) instead of a block-scoped local. Under
 * opt_lifetimes on, a web is numbered with its variable.
 * 2026-10-09: 24 -> 9: body taken from the parallel cos/finish-first-party-20261009 worktree.
 * 2026-10-10: actual-owner probe confirms 1692/1696 bytes, zero structural
 * and nine register edits. That score is not a defined-input proof: the
 * constructor/first tick initialize ages, and the age-zero path below seeds
 * only history slot zero. For positive C/W without count overflow, the next
 * shift reads unproduced payloads whenever (C - 1) * W > 1. C=3,W=1 reaches
 * the unconditional color load at 0048b4ec before any history-age check.
 * See docs/probe_archive/Sprite_particle_boundaries_20261010.md.
 * 2026-10-12: the 0x150 frame and every stack slot agree (423 instructions,
 * still 9 edits). Shared SpawnParticle views tie only with the two clear-age
 * lvalues kept byte-addressed; member-address CSE otherwise adds a spill.
 * A dedicated linear anchor costs 40 edits. The captured model puts its r60
 * in $a3 only after the step-transfer temporary r91; the counter/alpha
 * transfer order also differs. Const and inline accessor forms stay at 40.
 * 2026-10-13: allocator replay of a dedicated anchor (any declaration
 * position: 40, colour $v1) gives retail's $a3 and every other colour once
 * the anchor is numbered after r91, the else loop's last asm-operand
 * variable; parse-time locals cannot be. Retail's anchor is therefore an
 * IR or codegen temporary shared by the pre-loop uses and the loop's
 * effectVuLoad10. As an expression it is CSE'd before the loop but not into
 * it: IR LICM hoists only the (u32)clear conversion (34), uncast it is
 * recomputed in the loop (34), and dropping dst1's else web swaps c0/clear
 * ($s7/$fp). An inline else-branch helper (anchor as parameter) needs
 * inline_depth and recolours the branch (57).
 * 2026-10-13 (build/v8b340, micro sh1-sh11): an order search on the block-anchor capture finds a
 * 10/10 colouring only with the anchor scanned after the loop's asm-operand and conversion temps
 * and before tmpE/tmpD/bound, a window only a codegen temp occupies; declared locals number <= 61.
 * Expression anchors split into per-region shadows at the conversion join or the loop's sqc2 store.
 * The best is `iter` assigned after the store/scale sequence (23-24), with three separate residuals:
 * the age test's own addu, the counter/transfer swap and the stride/c0 swap. Whole-else helpers
 * 40-43; opt_lifetimes 81-107; opt_common_subs off 96-112; opt_propagation on 50.
 * 2026-10-14: 9 -> 5 fnalign edits. A separate linear anchor and b210's native
 * named LQC2 operand remove the GNU operand-binding copy; the anchor now has
 * retail's $a3 lifetime. Only the loop counter / 255.0f transfer swap remains.
 * 2026-10-14: 5 -> 4: transfer the invariant 255.0f to its native GPR once.
 * All colours now agree; only MFC1 / loop-bound-zero materialisation order differs.
 * 2026-10-14: measured 4 -> 0. Native SQC2 keeps the history cursor's clear/shift/linear
 * web intact under opt_lifetimes; the shared subdivision counter's second web
 * then numbers after the compiler-generated 255.0f transfer, matching its hoist.
 */
/* Shift particle history and interpolate trail subdivisions, preserving the documented age-zero limitation. */
// FUN_0048B340
#pragma push
/* measured: split the two counter webs, but preserve the native-asm cursor. */
/* measured: func_0048b340 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_0048b340 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle)
{
    SpawnParticle *trailParticle;

    typedef struct TrailColor {
        u32 rgb : 24;
        u32 alpha : 8;
    } TrailColor;
    extern void memcpy(void *dst, void *src, u32 size);
    extern void mdlEffectCatmullRomVU(void *progress, f32 points);
    extern f32 D_00761134;
    u_long128 controlPoints[4];
    u_long128 colorVector;
    u_long128 colorStep;
    u32 k;
    u32 i;
    u8 *src1;
    u8 *iter;
    u8 *clear;
    u32 j;
    u8 *dst1;
    s32 trailWidth;
    u8 *config;
    u32 trailCount;
    u32 shiftCount;
    u32 trailLength;
    s32 age;
    f32 one;
    f32 acc;
    f32 invN;
    f32 scaleTop;
    f32 inv2;
    f32 acc2;
    f32 baseX;
    f32 diffX;
    f32 baseY;
    f32 diffY;
    u32 stride;
    f32 ftmp;
    u32 alpha;
    u32 lo;
    u8 *second;
    u32 particleIndex;

    config = ((MdlEffectEmitter *)emitter)->parameters;
    trailWidth = ((MdlEffectEmitterParameters *)config)->trailWidth;
    trailCount = ((MdlEffectEmitterParameters *)config)->trailCount.value;
    trailLength = trailCount * (u32)trailWidth;
    if (trailLength == 0) {
        return;
    }
    age = ((SpawnParticle *)particle)->age;
    particleIndex = ((u32)particle - (u32)((MdlEffectEmitter *)emitter)->particles) >> 5;
    clear = ((MdlEffectEmitter *)emitter)->particles + ((((MdlEffectEmitter *)emitter)->primaryCount.value + particleIndex * trailLength) << 5);
    if (age == 0) {
        memcpy(clear, particle, 0x20);
        src1 = clear;
        i = 0;
        goto loop0_check;
loop0_body:
        ((SpawnParticle *)src1)->age = -1;
        src1 += 0x20;
        i += 1;
loop0_check:
        if (i < trailLength) {
            goto loop0_body;
        }
        return;
    }
    (trailParticle = (SpawnParticle *)clear)->age = age - 1; /* measured: the separate typed pointer preserves MATCH under b210. */
    one = 1.0f;
    invN = one / (f32)(u32)trailLength;
    acc = 0.0f;
    scaleTop = (f32)(u32)((((SpawnParticle *)particle)->color) >> 24);
    shiftCount = trailLength - (u32)trailWidth;
    dst1 = clear + trailLength * 32 - 0x20;
    stride = (u32)(trailWidth * 32);
    src1 = dst1 - stride;
    j = 0;
    goto loop1_check;
loop1_body:
    memcpy(dst1, src1, 0x20);
    /* Retail 0048b4ec: memcpy does not initialize the source's color.
     * An invalid age does not bypass this scalar read. */
    lo = ((TrailColor *)(src1 + 0x14))->rgb;
    ftmp = scaleTop * acc;
    alpha = (u32)ftmp;
    ((SpawnParticle *)dst1)->color = lo | (alpha << 24);
    acc = acc + invN;
    dst1 -= 0x20;
    src1 -= 0x20;
    j += 1;
loop1_check:
    if (j < shiftCount) {
        goto loop1_body;
    }
    memcpy(clear, particle, 0x20);
    ((SpawnParticle *)clear)->age = -1;
    if ((trailWidth == 1) || (trailCount < 2)) {
        return;
    }
    if ((age >= 2) && (trailCount >= 3)) {
        u8 *last;
        u32 colTmpA;
        u32 colTmpB;
        u32 packedTmp;
        u32 colorTransfer;

        last = (u8 *)((u32)(trailWidth << 6) + (u32)clear);
        if (((SpawnParticle *)last)->age < 0) {
            return;
        }
        {
            u_long128 *dst = &controlPoints[0];

            *dst = *(u_long128 *)last;
            dst = &controlPoints[1];
            second = clear + (u32)trailWidth * 32;
            *dst = *(u_long128 *)second;
            dst = &controlPoints[2];
            *dst = *(u_long128 *)clear;
            dst = &controlPoints[3];
            *dst = *(u_long128 *)clear;
        }
        iter = second - 0x20;
        acc2 = 0.0f;
        inv2 = one / (f32)(u32)((u32)trailWidth + 1);
        baseX = ((SpawnParticle *)second)->size;
        diffX = ((SpawnParticle *)clear)->size - baseX;
        baseY = ((SpawnParticle *)second)->angle;
        diffY = ((SpawnParticle *)clear)->angle - baseY;
        colTmpA = ((SpawnParticle *)clear)->color;
        {
            const u32 *word = &colTmpA;
            f32 sc;

            sc = D_00761134;
            effectVuUnpackColor10V0(word, sc);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            colTmpB = ((SpawnParticle *)second)->color;
            effectVuUnpackColor10V0(&colTmpB, sc);
        }
        effectVuStore10((EffectVuVector *)&colorVector);
        __asm__ volatile(
            "vsub.xyzw $vf11, $vf11, $vf10\n"
            "vaddw.xyz $vf10, $vf0, $vf0w\n"
            "vmulx.w $vf10, $vf0, $vf0x\n" : : : "$vf10", "$vf11");
        effectVuScale10(inv2);
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        effectVuStore10((EffectVuVector *)&colorStep);
        for (k = 0; k < (u32)trailWidth - 1; iter -= 0x20, k++) {
            acc2 = acc2 + inv2;
            mdlEffectCatmullRomVU(controlPoints, acc2);
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)iter) : "r"(iter) : "memory");
            ((SpawnParticle *)iter)->size = baseX + diffX * acc2;
            ((SpawnParticle *)iter)->angle = baseY + diffY * acc2;
            effectVuLoad10((EffectVuVector *)&colorVector);
            effectVuLoad11((EffectVuVector *)&colorStep);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10((EffectVuVector *)&colorVector);
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $0, %0\n"
                "ppacb %0, $0, %0\n"
                "sw %0, packedTmp\n"
                : "=r"(colorTransfer), "=m"(packedTmp)
                : "r"(255.0f)
                : "$vf2", "$vf10");
            ((SpawnParticle *)iter)->color = packedTmp;
            ((SpawnParticle *)iter)->age = age;
        }
    } else {
        u8 *anchor;
        u32 colTmpA;
        u32 colTmpB;
        u32 packedTmp;
        u32 colorTransfer;
        f32 inv3;
        const f32 one3 = 1.0f;
        f32 acc3;
        f32 bx;
        f32 dx;
        f32 by;
        f32 dy;

        if (age <= 0) {
            return;
        }
        anchor = (u8 *)(stride + (u32)clear);
        if (((SpawnParticle *)anchor)->age < 0) {
            return;
        }
        src1 = anchor - 0x20;
        acc3 = 0.0f;
        inv3 = one3 / (f32)(u32)((u32)trailWidth + 1);
        bx = ((SpawnParticle *)anchor)->size;
        dx = ((SpawnParticle *)clear)->size - bx;
        by = ((SpawnParticle *)anchor)->angle;
        dy = ((SpawnParticle *)clear)->angle - by;
        colTmpA = ((SpawnParticle *)clear)->color;
        {
            const u32 *word = &colTmpA;
            f32 sc;

            sc = D_00761134;
            effectVuUnpackColor10V0(word, sc);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            colTmpB = ((SpawnParticle *)anchor)->color;
            effectVuUnpackColor10V0(&colTmpB, sc);
        }
        effectVuStore10((EffectVuVector *)&colorVector);
        __asm__ volatile(
            "vsub.xyzw $vf11, $vf11, $vf10\n"
            "vaddw.xyz $vf10, $vf0, $vf0w\n"
            "vmulx.w $vf10, $vf0, $vf0x\n" : : : "$vf10", "$vf11");
        effectVuScale10(inv3);
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        effectVuStore10((EffectVuVector *)&colorStep);
        for (k = 0; k < (u32)trailWidth - 1; src1 -= 0x20, k++) {
            acc3 = acc3 + inv3;
            /* Native b210 operand: read the C pointer without a GNU binding copy. */
            __asm__ volatile("lqc2 $vf10, 0(anchor)" : : : "$vf10", "memory");
            effectVuLoad11((EffectVuVector *)clear);
            __asm__ volatile(
                "qmtc2.ni %0, $vf2\n"
                "vsubx.w $vf3, $vf0, $vf2x\n"
                "vmulax.xyzw $ACC, $vf11, $vf2x\n"
                "vmaddw.xyzw $vf10, $vf10, $vf3w\n" : : "r"(acc3) : "$vf2", "$vf3", "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(src1)" : : : "memory");
            ((SpawnParticle *)src1)->size = bx + dx * acc3;
            ((SpawnParticle *)src1)->angle = by + dy * acc3;
            effectVuLoad10((EffectVuVector *)&colorVector);
            effectVuLoad11((EffectVuVector *)&colorStep);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10((EffectVuVector *)&colorVector);
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $0, %0\n"
                "ppacb %0, $0, %0\n"
                "sw %0, packedTmp\n"
                : "=r"(colorTransfer), "=m"(packedTmp)
                : "r"(255.0f)
                : "$vf2", "$vf10");
            ((SpawnParticle *)src1)->color = packedTmp;
            ((SpawnParticle *)src1)->age = age;
        }
    }
}

#pragma pop
/* Recovered Wave controller: complete position snapshots and actual live trail
 * indexing. Domain and source/compiler evidence are recorded in
 * docs/probe_archive/wave-spawn-20261005/. The existing trail provider retains
 * its separately documented initialization limitation; this caller does not
 * read its trail payload. */
// FUN_0048B9E0
#include "particle_spawn_internal.h"
/* Measured: these scoped settings preserve the recovered wave update
 * evaluation order and the complete retail 2652-byte executable body. */
#pragma push
/* measured: EffWaveUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void EffWaveUpdate(u8 *emitterData)
{
    extern f32 sinf(f32 emitterData);
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern u8 D_00713D30[];
    EffectVuVector direction;
    EffectVuVector spreadVector;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    SpawnParticle *particle;
    WaveSpawnState *state;
    WaveSpawnParameters *parameters;
    WaveSpawnEmitter *const emitter = (WaveSpawnEmitter *)emitterData;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 gravity;
    f32 zero;
    f32 one, half, two;
    f32 angleScale;
    s32 spawnBudget;
    s32 preroll;
    u32 index;
    s32 sample;
    f32 scaledValue;
    f32 sampleValue;
    s32 age;
    s32 trailCount;
    s32 trailWidth;
    s32 trailLength;
    SpawnParticle *trail;
    s32 trailIndex;
    u32 particleIndex;
    f32 a;
    f32 finalAmplitudeVariation;
    f32 b;
    f32 c;
    count = emitter->primaryCount;
    flags = emitter->flags;
    particle = emitter->particles;
    state = emitter->state;
    parameters = emitter->parameters;
    lifetime = parameters->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = parameters->emissionDuration;
    angleMode = parameters->angleMode;
    gravity = parameters->gravity;
    /* VU multiplication consumes W as well as the three spatial lanes. */
    spreadVector.lane[3] = 0.0f;
    effectVuLoad10(&parameters->rotation);
    effMiscBuildRotationVU();
    if ((emissionDuration != 0) && (emitter->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((emitter->ticks == 0) && (parameters->preroll != 0)) {
        /* Keep the byte-valued enable phase distinct from its loop flag.
         * The same narrow-to-word source form occurs in func_0048a980. */
        u8 initialPreroll = 1;
        preroll = initialPreroll;
        if (!(parameters->emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            sampleValue = (f32)emitter->primaryCount;
            spawnBudget = (s32)(sampleValue * prerollScale);
        } else {
            spawnBudget = emitter->primaryCount;
        }
        goto post_init;
    } else {
        preroll = 0;
        if (!(parameters->emissionVariation <= 0.0f)) {
            scaledValue = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            sample = parameters->emissionRate;
            sampleValue = (f32)(u32)sample;
            emitter->emissionAccumulator = emitter->emissionAccumulator + sampleValue * scaledValue;
        } else {
            sample = parameters->emissionRate;
            scaledValue = (f32)(u32)sample;
            emitter->emissionAccumulator = emitter->emissionAccumulator + scaledValue;
        }
        scaledValue = emitter->emissionAccumulator;
        scaledValue = fabsf(scaledValue);
        spawnBudget = (s32)scaledValue;
        emitter->emissionAccumulator = emitter->emissionAccumulator - (f32)spawnBudget;
        goto post_init;
    }
post_init:
    index = 0;
    zero = 0.0f;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    angleScale = fGpffff8080;
    goto main_check;
main_body:
    if (particle->age < lifetime) {
        goto skip_clear;
    }
    if (emissionDuration != 0) {
        sample = -2;
    } else {
        sample = -1;
    }
    particle->age = sample;
    trailCount = emitter->parameters->trailCount;
    trailWidth = emitter->parameters->trailWidth;
    trailLength = trailCount * trailWidth;
    if (trailLength != 0) {
        /* The live emitter base/count may differ from the loop capture. */
        particleIndex = ((u32)particle - (u32)emitter->particles) >> 5;
        trail = emitter->particles + (emitter->primaryCount + particleIndex * (u32)trailLength);
        trailIndex = 0;
        goto clear_check;
clear_body:
        trail->age = -1;
        trail += 1;
        trailIndex += 1;
clear_check:
        if (trailIndex < trailLength) {
            goto clear_body;
        }
    }
skip_clear:
    age = particle->age;
    if (age == -2) {
        goto next_iter;
    }
    if (age != -1) {
        goto else_branch;
    }
    if (spawnBudget == 0) {
        goto next_iter;
    }
    if (!((flags & 1) == 0)) {
        state->direction[0] = zero;
        state->direction[1] = one;
        state->direction[2] = zero;
    } else {
        effectVuLoad10((const EffectVuVector *)D_00713D30);
        spawnVuTransform10();
        effectVuStore10(&direction);
        state->direction[0] = direction.lane[0];
        state->direction[1] = direction.lane[1];
        state->direction[2] = direction.lane[2];
    }
    b = effMiscRandFloat(0);
    direction.lane[0] = two * (b - half);
    direction.lane[1] = zero;
    b = effMiscRandFloat(0);
    direction.lane[2] = two * (b - half);
    direction.lane[3] = zero;
    effectVuLoad10(&direction);
    spawnVuNormalize10();
    if ((flags & 1) == 0) {
        spawnVuTransform10();
    }
    effectVuStore10(&direction);
    state->waveDirection[0] = direction.lane[0];
    state->waveDirection[1] = direction.lane[1];
    state->waveDirection[2] = direction.lane[2];
    a = parameters->speedVariation;
    b = effMiscRandFloat(0);
    state->speed = parameters->speed * ((one - a) + a * b);
    a = parameters->initialAmplitudeVariation;
    b = effMiscRandFloat(0);
    c = parameters->initialAmplitude * ((one - a) + a * b);
    finalAmplitudeVariation = parameters->finalAmplitudeVariation;
    b = effMiscRandFloat(0);
    scaledValue = parameters->finalAmplitude * ((one - finalAmplitudeVariation) + finalAmplitudeVariation * b);
    state->amplitude = c;
    state->amplitudeStep = (scaledValue - c) / (f32)lifetime;
    a = parameters->phaseStepVariation;
    b = effMiscRandFloat(0);
    state->phaseStep = parameters->phaseStep * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    state->phase = angleScale * b;
    state->previousSine = sinf(state->phase);
    b = effMiscRandFloat(0);
    c = parameters->spread * (two * (b - half));
    spreadVector.lane[0] = c;
    spreadVector.lane[1] = c;
    spreadVector.lane[2] = c;
    if ((flags & 1) != 0) {
        effectVuLoad10(&direction);
        effectVuLoad11(&spreadVector);
        spawnVuMultiply10();
    } else {
        effectVuLoad10(&direction);
        effectVuLoad11(&spreadVector);
        spawnVuMultiply10();
        effectVuLoad11(&parameters->position);
        spawnVuAdd10();
    }
    effectVuStore10(&particle->position);
    a = parameters->sizeVariation;
    b = effMiscRandFloat(0);
    state->sizeScale = (one - a) + a * b;
    if (angleMode != 2) {
        a = parameters->angleVariation;
        b = effMiscRandFloat(0);
        state->angleScale = (one - a) + a * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            state->angleOffset = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                state->angleScale = state->angleScale * -1.0f;
            }
        } else {
            state->angleOffset = zero;
        }
    } else {
        state->angleOffset = zero;
        state->angleScale = one;
    }
    particle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)&particle->position;
    }
    if (preroll != 0) {
        f32 prerollElapsed;
        f32 travelled;
        f32 gravityDistance;
        f32 gravitySquaredDistance;
        sample = (u32)effMiscRand(0) % (u32)lifetime;
        prerollElapsed = (f32)(u32)sample;
        travelled = state->speed * prerollElapsed;
        gravityDistance = gravity * prerollElapsed;
        gravitySquaredDistance = prerollElapsed * gravityDistance;
        sampleValue = travelled - half * gravitySquaredDistance;
        particle->position.lane[0] = particle->position.lane[0] + state->direction[0] * sampleValue;
        particle->position.lane[1] = particle->position.lane[1] + state->direction[1] * sampleValue;
        particle->position.lane[2] = particle->position.lane[2] + state->direction[2] * sampleValue;
        state->phase = state->phase + state->phaseStep * prerollElapsed;
        state->amplitude = state->amplitude + state->amplitudeStep * prerollElapsed;
        a = sinf(state->phase);
        c = state->amplitude * a;
        particle->position.lane[0] = particle->position.lane[0] + state->waveDirection[0] * c;
        particle->position.lane[1] = particle->position.lane[1] + state->waveDirection[1] * c;
        particle->position.lane[2] = particle->position.lane[2] + state->waveDirection[2] * c;
        state->phase = state->phase + state->phaseStep;
        state->amplitude = state->amplitude + state->amplitudeStep;
        state->previousSine = a;
        particle->age = (s32)prerollElapsed;
    }
    mdlEffectSampleKeyState((u8 *)particle, (u8 *)parameters, particle->age, &previousPosition);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    if (preroll != 0) {
        trailLength = emitter->parameters->trailCount * emitter->parameters->trailWidth;
        if (trailLength != 0) {
            particleIndex = ((u32)particle - (u32)emitter->particles) >> 5;
            trail = emitter->particles + (emitter->primaryCount + particleIndex * (u32)trailLength);
            memcpy(trail, particle, sizeof(*particle));
            trail->age = -1;
        }
        particle->age = particle->age + 1;
    }
    spawnBudget -= 1;
    goto next_iter2;
else_branch:
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)&particle->position;
    }
    scaledValue = sinf(state->phase);
    sampleValue = state->amplitude * (scaledValue - state->previousSine);
    particle->position.lane[0] = particle->position.lane[0] + state->waveDirection[0] * sampleValue;
    particle->position.lane[1] = particle->position.lane[1] + state->waveDirection[1] * sampleValue;
    particle->position.lane[2] = particle->position.lane[2] + state->waveDirection[2] * sampleValue;
    sampleValue = state->speed - gravity * (f32)age;
    particle->position.lane[0] = particle->position.lane[0] + state->direction[0] * sampleValue;
    particle->position.lane[1] = particle->position.lane[1] + state->direction[1] * sampleValue;
    particle->position.lane[2] = particle->position.lane[2] + state->direction[2] * sampleValue;
    state->phase = state->phase + state->phaseStep;
    state->amplitude = state->amplitude + state->amplitudeStep;
    state->previousSine = scaledValue;
    mdlEffectSampleKeyState((u8 *)particle, (u8 *)parameters, age, &previousPosition);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    mdlEffectUpdateParticleTrail((u8 *)emitter, (u8 *)particle);
    particle->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 1;
    particle += 1;
main_check:
    if (index < count) {
        goto main_body;
    }
}



#pragma pop

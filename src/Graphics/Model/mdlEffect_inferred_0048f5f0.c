#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
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

extern f32 fabsf(f32 value);
extern void effMiscBuildRotationVU(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(u8 *arg0);
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
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Source unit: src/promoted/code1_0048.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 0048f5f0-0048f5f0 */

extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
extern void func_0048b340(u8 *arg0, u8 *arg1);
extern void EffMotionEmitterUpdate(u8 *arg0);
extern void func_0048d8c0(u8 *arg0);
extern void EffConeAngleEmitterUpdate(u8 *arg0);
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
#pragma pop
/* measured: opt_propagation off tested for target subtraction scheduling. */
/* measured: restore opt_propagation after func_0048aff0. */
#pragma push
/* measured: split the two counter webs, but preserve the native-asm cursor. */
#pragma pop
/* Measured: these scoped settings preserve the recovered wave update
 * evaluation order and the complete retail 2652-byte executable body. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Ported from the matched sibling func_0048d8c0: function-scope u8
 * initialPreroll, `!(x <= 0)` first rand-scale arms, shift-based particle
 * index, `mode9C != 2` first, snapshot pointer, stack vectors declared from
 * the highest frame slot down, and the config quads copied through $2.
 * The loop constants are assigned after the preroll in retail's hoist order.
 * b210 colours the saved FPRs from the highest-numbered local down, each
 * taking the lowest free register, and numbers locals by declaration: so
 * `a` (retail $f28) is declared first, then eF0val, eECval, `c` ($f25,
 * which also carries the v14 sample and the else-branch angle), and the
 * constants one..half ($f24-$f20). */
#pragma push
#pragma pop
/* Taken from the matched sibling EffMotionEmitterUpdate: the loop constants are
 * locals assigned after the preroll in retail's hoist order (one, orbit,
 * zero, half, two, tilt, angle, -1) and declared in its FPR order. `c`
 * carries the first, fifth and sixth scale (retail $f30) and `a` the second
 * and third ($f31). The 0x140 vector exists only for its retail w=0 store.
 * The config[0] snapshot at 0x0048D96C is an lq/sq that names $2, as in
 * func_00485630; the $2 def also frees $v0 for retail's saved20/mode9C
 * spill stores. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Bezier emitter update. The 76-byte work record separates control points,
 * offsets and scalar state; its length union keeps the hardware-Q bits.
 * Matched by applying the EffConeAngleEmitterUpdate family shape: stack objects
 * declared in retail address order, the preroll-elapsed float first among
 * the FPR locals, one `angle` local for the orbit angle, the six blends and
 * the progress fraction, (s32)/(f32) preroll in prerollScale/scale locals,
 * blend vectors loaded before the qmtc2 bridge, each speed-integral's linear
 * term formed before the half-weighted square, and the else-branch elapsed
 * declared before the clamped distance. */
#pragma push
/* measured: EffBezierEmitterUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: EffBezierEmitterUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0048F5F0
void EffBezierEmitterUpdate(u8 *arg0)
{
    typedef struct BezierParticleWork {
        f32 control0[3];
        f32 control1[3];
        f32 control2[3];
        f32 offset[3];
        f32 rotationSpeed;
        f32 travelSpeed;
        union { s32 bits; f32 value; } length;
        f32 progress;
        f32 opacity;
        f32 spin;
        f32 scale;
    } BezierParticleWork;
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void effMiscAxisAngleVU(void *arg0, f32 arg1);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8090;
    extern u8 D_00713D00[];
    f32 bez[4] __attribute__((aligned(16)));
    u8 tmp1C0[16] __attribute__((aligned(16)));
    u_long128 b220buf;
    f32 stack1A0[4] __attribute__((aligned(16)));
    f32 vecA[4] __attribute__((aligned(16)));
    u8 tmp180[16] __attribute__((aligned(16)));
    f32 tmp170[4] __attribute__((aligned(16)));
    f32 vecB2[4] __attribute__((aligned(16)));
    f32 vecB[4] __attribute__((aligned(16)));
    f32 coeff140[4] __attribute__((aligned(16)));
    f32 quad130[4] __attribute__((aligned(16)));
    f32 coeff120[4] __attribute__((aligned(16)));
    f32 quad110[4] __attribute__((aligned(16)));
    f32 ftmp1;
    f32 save30;
    f32 save29;
    f32 angle;
    f32 half, two, orbitScale, hundred, stackDC, one, zero, spinScale, negone, thousand, three;
    f32 vB;
    f32 ccB;
    f32 cc2B;
    f32 c3B;
    f32 vc2B;
    f32 b1B;
    f32 vvB;
    f32 cv2B;
    f32 b2B;
    f32 v3B;
    f32 o0B;
    f32 o1B;
    f32 o2B;
    f32 o3B;
    f32 o4B;
    f32 o5B;
    f32 p252B;
    f32 p256B;
    f32 p260B;
    f32 nf;
    f32 f1B;
    f32 f12B;
    u32 count;
    u8 *nodes;
    BezierParticleWork *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    s32 v15;
    s32 v14;
    u8 initialPreroll;
    u32 idx;
    s32 tmp;
    s32 tmp2;
    f32 ftmp2;
    f32 ftmp3;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    u32 particleIndex;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    count = *(u32 *)(parent + 4);
    nodes = *(u8 **)(parent + 24);
    out = *(BezierParticleWork **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    save29 = *(f32 *)(config + 236);
    save30 = *(f32 *)(config + 248);
    stack1A0[0] = *(f32 *)(config + 252);
    stack1A0[1] = *(f32 *)(config + 256);
    stack1A0[2] = *(f32 *)(config + 260);
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    effMiscBuildRotationVU();
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        initialPreroll = 1;
        v14 = initialPreroll;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * prerollScale);
        } else {
            v15 = *(s32 *)(parent + 4);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            f32 scale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * scale;
        } else {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    half = 0.5f;
    two = 2.0f;
    orbitScale = fGpffff8084;
    hundred = 100.0f;
    stackDC = fGpffff8090;
    one = 1.0f;
    zero = 0.0f;
    spinScale = fGpffff8080;
    negone = -1.0f;
    thousand = 1000.0f;
    three = 3.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 != 0) {
        tmp = -2;
    } else {
        tmp = -1;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
        clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    b = effMiscRandFloat(0);
    c = two * (b - half);
    angle = orbitScale * c;
    a = *(f32 *)(config + 284) * cosf(angle);
    out->offset[0] = a;
    out->offset[1] = -*(f32 *)(config + 288);
    a = *(f32 *)(config + 284) * sinf(angle);
    out->offset[2] = a;
    vecA[0] = *(f32 *)(config + 264) + out->offset[0];
    vecA[1] = *(f32 *)(config + 268) + out->offset[1];
    vecA[2] = *(f32 *)(config + 272) + out->offset[2];
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(stack1A0), "m"(*(u_long128 *)stack1A0) : "$vf12", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf11", "memory");
    {
        s16 h200 = *(s16 *)(config + 200);
        f32 f200 = (f32)h200 / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(f200) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB) : "r"(vecB) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    {
        s16 h212 = *(s16 *)(config + 212);
        f32 f212 = (f32)h212 / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(f212) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB2) : "r"(vecB2) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vaddy.x $vf2, $vf2, $vf2y \n vaddz.x $vf2, $vf2, $vf2z \n" : : : "$vf2", "$vf10", "memory");
    __asm__ volatile("vsqrt $Q, $vf2x" : : : "$Q", "$vf2", "memory");
    __asm__ volatile("vwaitq" : : : "memory");
    {
        f32 length;
        __asm__ volatile("cfc2.ni %0, $vi22\nmtc1 %0, %1" : "=r"(tmp2), "=f"(length) : : "memory");
    }
    out->length.bits = tmp2;
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n" : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp1C0) : "r"(tmp1C0) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12", "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(D_00713D00), "m"(*(u_long128 *)D_00713D00) : "$vf11", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp180) : "r"(tmp180) : "$vf10", "memory");
    {
        f32 fE0;
        b = effMiscRandFloat(0);
        c = two * (b - half);
        fE0 = (f32)*(s16 *)(config + 224) * c;
        ftmp1 = half * fE0;
        effMiscAxisAngleVU(tmp1C0, stackDC * ftmp1);
    }
    {
        angle = *(f32 *)(config + 208);
        b = effMiscRandFloat(0);
        {
            f32 blend208 = (one - angle) + angle * b;
            f32 scale204 = *(f32 *)(config + 204) * blend208;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB), "m"(*(u_long128 *)vecB) : "$vf10", "memory");
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(tmp180), "m"(*(u_long128 *)tmp180) : "$vf12", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(scale204) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            out->control0[0] = tmp170[0];
            out->control0[1] = tmp170[1];
            out->control0[2] = tmp170[2];
        }
    }
    {
        angle = *(f32 *)(config + 220);
        b = effMiscRandFloat(0);
        {
            f32 blend220 = (one - angle) + angle * b;
            f32 scale216 = *(f32 *)(config + 216) * blend220;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB2), "m"(*(u_long128 *)vecB2) : "$vf10", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(scale216) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            out->control1[0] = tmp170[0];
            out->control1[1] = tmp170[1];
            out->control1[2] = tmp170[2];
        }
    }
    angle = *(f32 *)(config + 244);
    b = effMiscRandFloat(0);
    out->travelSpeed = *(f32 *)(config + 240) * ((one - angle) + angle * b);
    angle = *(f32 *)(config + 232);
    b = effMiscRandFloat(0);
    out->rotationSpeed = *(f32 *)(config + 228) * ((one - angle) + angle * b);
    out->progress = zero;
    {
        u_long128 *origin = (u_long128 *)stack1A0;
        *(u_long128 *)nodes = *origin;
    }
    angle = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out->opacity = (one - angle) + angle * b;
    if (mode9C != 2) {
        angle = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out->scale = (one - angle) + angle * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out->spin = spinScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out->scale = out->scale * negone;
            }
        } else {
            out->spin = zero;
        }
    } else {
        out->spin = zero;
        out->scale = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        d = out->travelSpeed * ftmp1;
        d = d + half * (ftmp1 * (save30 * ftmp1));
        if (d < zero) {
            d = zero;
        }
        ftmp3 = out->rotationSpeed * ftmp1;
        ftmp3 = ftmp3 + half * (ftmp1 * (save29 * ftmp1));
        if (ftmp3 < zero) {
            ftmp3 = zero;
        }
        c = ftmp3;
        angle = d / thousand;
        if (!(angle <= one)) {
            angle = one;
        }
        if (out->progress > angle) {
            angle = out->progress;
        } else {
            out->progress = angle;
        }
        bez[0] = vecA[0];
        bez[1] = vecA[1];
        bez[2] = vecA[2];
        vB = angle;
        ccB = one - vB;
        cc2B = ccB * ccB;
        c3B = ccB * cc2B;
        coeff140[0] = c3B;
        vc2B = vB * cc2B;
        b1B = three * vc2B;
        coeff140[1] = b1B;
        vvB = vB * vB;
        cv2B = ccB * vvB;
        b2B = three * cv2B;
        coeff140[2] = b2B;
        v3B = vB * vvB;
        coeff140[3] = v3B;
        o3B = out->control1[0];
        p252B = *(f32 *)(config + 252);
        o0B = out->control0[0];
        quad130[0] = bez[0] * coeff140[3] +
            (p252B * coeff140[0] + o0B * coeff140[1] +
             o3B * coeff140[2]);
        o4B = out->control1[1];
        p256B = *(f32 *)(config + 256);
        o1B = out->control0[1];
        quad130[1] = bez[1] * coeff140[3] +
            (p256B * coeff140[0] + o1B * coeff140[1] +
             o4B * coeff140[2]);
        o5B = out->control1[2];
        p260B = *(f32 *)(config + 260);
        o2B = out->control0[2];
        quad130[2] = bez[2] * coeff140[3] +
            (p260B * coeff140[0] + o2B * coeff140[1] +
             o5B * coeff140[2]);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(quad130), "m"(*(u_long128 *)quad130) : "$vf10", "memory");
        if (zero != ftmp3) {
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            effMiscAxisAngleVU(tmp1C0, ftmp3);
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(out->length.value * angle) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out->opacity;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out->scale;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out->spin;
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
            clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    {
        nf = (f32)node10;
        f1B = out->travelSpeed * nf;
        f1B = f1B + half * (nf * (save30 * nf));
        if (f1B < zero) {
            f1B = zero;
        }
        f12B = out->rotationSpeed * nf;
        f12B = f12B + half * (nf * (save29 * nf));
        if (f12B < zero) {
            f12B = zero;
        }
        angle = f1B / thousand;
        if (!(angle <= one)) {
            angle = one;
        }
        ftmp2 = out->progress;
        if (ftmp2 > angle) {
            angle = ftmp2;
        } else {
            out->progress = angle;
        }
    }
    bez[0] = *(f32 *)(config + 264) + out->offset[0];
    bez[1] = *(f32 *)(config + 268) + out->offset[1];
    bez[2] = *(f32 *)(config + 272) + out->offset[2];
    vB = angle;
    ccB = one - vB;
    cc2B = ccB * ccB;
    c3B = ccB * cc2B;
    coeff120[0] = c3B;
    vc2B = vB * cc2B;
    b1B = three * vc2B;
    coeff120[1] = b1B;
    vvB = vB * vB;
    cv2B = ccB * vvB;
    b2B = three * cv2B;
    coeff120[2] = b2B;
    v3B = vB * vvB;
    coeff120[3] = v3B;
    o3B = out->control1[0];
    p252B = *(f32 *)(config + 252);
    o0B = out->control0[0];
    quad110[0] = bez[0] * coeff120[3] +
        (p252B * coeff120[0] + o0B * coeff120[1] +
         o3B * coeff120[2]);
    o4B = out->control1[1];
    p256B = *(f32 *)(config + 256);
    o1B = out->control0[1];
    quad110[1] = bez[1] * coeff120[3] +
        (p256B * coeff120[0] + o1B * coeff120[1] +
         o4B * coeff120[2]);
    o5B = out->control1[2];
    p260B = *(f32 *)(config + 260);
    o2B = out->control0[2];
    quad110[2] = bez[2] * coeff120[3] +
        (p260B * coeff120[0] + o2B * coeff120[1] +
         o5B * coeff120[2]);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(quad110), "m"(*(u_long128 *)quad110) : "$vf10", "memory");
    if (zero != f12B) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
        vecA[0] = out->control2[0];
        vecA[1] = out->control2[1];
        vecA[2] = out->control2[2];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(stack1A0), "m"(*(u_long128 *)stack1A0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf11", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n" : : : "$vf2", "$vf10", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(tmp1C0) : "memory");
        effMiscAxisAngleVU(tmp1C0, f12B);
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(out->length.value * angle) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out->opacity;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out->scale;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out->spin;
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 1;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}


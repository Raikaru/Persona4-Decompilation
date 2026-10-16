#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "texture_callback_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

extern void (*jtbl_008873EC[])(void *ptr);
extern void func_00492cd0(void *ptr);
extern void func_003c0700(void *arg0);
extern u8 *func_003c0520(void *ptr);
extern void kAssertFail(const char *file, s32 line);
extern char D_00714520[];
extern void *mdlEffectSetFlag40(void *object, void *data);
extern void func_00492d10(void *arg0);
extern void func_004ae0a0(void *arg0, void *arg1);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *memset(void *dest, s32 value, s32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern char D_00714508[];
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern u8 *func_003e6a90(s32 arg0);
extern void func_003ef1b0(void *arg0);
extern u8 *func_003c0f20(s32 arg0);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void K_Clump_FreeTextureNameList(void *arg0);

void ObjectParticleLoadClump(u8 *arg0, s32 arg1, s32 arg2);

void ObjectParticleShareClump(u8 *arg0, u8 *arg1);
void ObjectParticleRebuildRecords(u8 *arg0, u32 arg1, u8 *arg2);

// Creates an object particle from an effect source: sizes the record buffer from the source's count (capped at 100), copies its 0x44-byte header, rebuilds the records and loads the clump when the kind at +0x1C is 3 and the lookup returns one.
// FUN_004AE460
void *ObjectParticleCreateFromSource(void *opaqueSource)
{
    EffSourceDescriptor *desc = (EffSourceDescriptor *)opaqueSource;
    EffSourceBlock *src;
    ObjectParticleInstance *inst;
    s32 temp_2_3;
    s32 temp_3;
    u32 var_19;

    src = (EffSourceBlock *)mdlEffectResolveRelPtrA(opaqueSource);
    if (src == NULL) {
        kAssertFail(D_00714520, 0xFD);
    }
    temp_3 = src->recordCount;
    if (temp_3 == 0) {
        var_19 = src->fallbackCount * src->recordMultiplier;
    } else {
        var_19 = temp_3 * src->recordMultiplier;
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    chkmemAllocSiteTag(D_00714508, 0x171);
    inst = (ObjectParticleInstance *)jtbl_008873E8[0](0x94, 0x40000);
    memset(inst, 0, 0x94);
    if (inst == NULL) {
        kAssertFail(D_00714520, 0xC5);
    }
    inst->recordCount = var_19;
    inst->packedColour = -1;
    *(u32 *)&inst->field_0x08 = 0x3F800000;
    inst->recordStride = 0x18;
    inst->self = inst;
    if (inst == NULL) {
        kAssertFail(D_00714520, 0xFF);
    }
    memcpy((u8 *)inst + 0x10, src, 0x44);
    ObjectParticleRebuildRecords((u8 *)inst, desc->id, (u8 *)src + 0x44);
    if (*(u32 *)(inst->list + 8) == 0) {
        return inst;
    }
    temp_2_3 = (s32)mdlEffectResolveRelPtrB(opaqueSource);
    if (temp_2_3 != 0) {
        switch (desc->kind) {
        case 3:
            ObjectParticleLoadClump((u8 *)inst, temp_2_3, desc->clumpInput);
            break;
        default:
            kAssertFail(D_00714520, 0x114);
            break;
        }
        inst->kind = desc->kind;
    }
    return inst;
}

// Releases the particle's source block, clump, record table and the particle itself.
// FUN_004AE650
void ObjectParticleFree(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)arg0;

    temp_4 = (u32)inst->list;
    if (temp_4 != 0) {
        func_00492cd0((void *)temp_4);
    }
    temp_4_2 = (u32)inst->recordTable;
    if (temp_4_2 != 0) {
        jtbl_008873EC[0]((void *)temp_4_2);
    }
    temp_4_3 = inst->clump;
    if (temp_4_3 != 0) {
        func_003c0700(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}

// Creates an object particle from a parent record: sizes the record buffer from the parent's block and shares its clump; asserts the parent block exists.
// FUN_004AE6D0
void *ObjectParticleCreateFromParent(void *opaqueSource)
{
    u8 *arg0 = opaqueSource;
    u32 temp_3;
    u32 var_19;
    u8 *temp_17;
    u8 *temp_2;
    if (*(u8 **)(arg0 + 0x58) == 0) {
        kAssertFail(D_00714520, 0x148);
    }
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x58) + 0x24);
    if (temp_17 == 0) {
        kAssertFail(D_00714520, 0x14A);
    }
    temp_3 = *(u32 *)(temp_17 + 0x20);
    if (temp_3 == 0) {
        var_19 = *(u32 *)(temp_17 + 0xB8) * *(u32 *)(temp_17 + 0x24);
    } else {
        var_19 = temp_3 * *(u32 *)(temp_17 + 0x24);
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    chkmemAllocSiteTag(D_00714508, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    memset(temp_2, 0, 0x94);
    if (temp_2 == 0) {
        kAssertFail(D_00714520, 0xC5);
    }
    *(u32 *)(temp_2 + 0) = var_19;
    *(u32 *)(temp_2 + 4) = -1;
    *(u32 *)(temp_2 + 8) = 0x3F800000;
    *(u16 *)(temp_2 + 0x7C) = 0x18;
    *(u8 **)(temp_2 + 0x80) = temp_2;
    if (temp_2 == 0) {
        kAssertFail(D_00714520, 0x14C);
    }
    memcpy(temp_2 + 0x10, arg0 + 0x10, 0x44);
    ObjectParticleRebuildRecords(temp_2, *(u16 *)(*(u8 **)(arg0 + 0x58) + 0), temp_17);
    if (*(u32 *)(*(u8 **)(temp_2 + 0x58) + 8) == 0) {
        return temp_2;
    }
    ObjectParticleShareClump(temp_2, arg0);
    return temp_2;
}
// Shares the clump of arg1 with arg0 after releasing arg0's own clump; asserts that the kind at +0xC of arg1 is 3.
// FUN_004AE880
void ObjectParticleShareClump(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;
    ObjectParticleInstance *dst = (ObjectParticleInstance *)arg0;
    ObjectParticleInstance *src = (ObjectParticleInstance *)arg1;

    switch (src->kind) {
    case 3:
        if (dst->clump != 0) {
            func_003c0700(dst->clump);
        }
        temp_2 = func_003c0520(src->clump);
        dst->clump = temp_2;
        RpClumpForAllAtomics(temp_2, mdlEffectSetFlag40, 0);
        break;
    default:
        kAssertFail(D_00714520, 0x172);
        break;
    }
    dst->kind = src->kind;
}

// Rebuilds the source block for id arg1 with parameters arg2, then re-allocates the 0x18-byte record table and seeds each record through func_004ae0a0.
// FUN_004AE930
void ObjectParticleRebuildRecords(u8 *arg0, u32 arg1, u8 *arg2)
{
    u32 temp_16;
    u8 *var_19;
    u32 var_18;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492cd0(temp_4);
    }
    if (*(u32 *)(arg2 + 0xC0) != 0) {
        kAssertFail(D_00714520, 0x18B);
    }
    *(u8 **)(arg0 + 0x58) = func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
    if (*(u32 *)(arg0 + 0x60) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(arg0 + 0x60));
    }
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x58) + 8);
    chkmemAllocSiteTag(D_00714520, 0x195);
    *(u8 **)(arg0 + 0x60) = (u8 *)jtbl_008873E8[0](temp_16 * 0x18, 0x40000);
    if (*(u8 **)(arg0 + 0x60) == 0) {
        kAssertFail(D_00714520, 0x196);
    }
    var_19 = *(u8 **)(arg0 + 0x60);
    *(u8 **)(arg0 + 0x5C) = var_19;
    var_18 = 0;
    while (var_18 < temp_16) {
        func_004ae0a0(arg0, var_19);
        var_18++;
        var_19 += 0x18;
    }
}

/* measured MATCH: aggregate-stack body is object 472B in the 480B retail
   window with normalized_diff 0. The decisive source fact is unsigned
   `u32 value` in the aggregate, which flips the default-call argument
   materialization to retail's move $a0,$s2 then lw $a1,0x64($sp).
   Probed and rejected before the type fix: pointer-local body (nd 292/object
   456), initial aggregate (nd 42/object 472), stack/register variants (nd
   28, 75, 77, 79/object 472), explicit zero-dispatch forms (nd 8/object
   472), no-op/cast argument expressions, named argument assignments,
   optimization_level 1, opt_propagation off, opt_common_subs off, and
   schedule on. */
// Walks the resource records of the source until opcode 0: opcode 22 gathers the texture-name list, opcode 16 fetches the clump; the clump is stored at +0x54 with its atomic callback set.
// FUN_004AEA70
void ObjectParticleLoadClump(u8 *arg0, s32 arg1, s32 arg2) {
    struct AeaWork { s32 code; u32 value; u8 pad8[0x18]; s32 in1; s32 in2; s32 outpad; s32 out; } work;
    s32 temp18; u8 *var17; u8 *var16;
    var17 = NULL; var16 = NULL; work.out = 0;
    if (*(u8 **)(arg0 + 0x58) == NULL) kAssertFail(D_00714520, 0x1B3);
    if (*(s32 *)(*(u8 **)(arg0 + 0x58) + 8) == 0) kAssertFail(D_00714520, 0x1B4);
    work.in1 = arg1; work.in2 = arg2; temp18 = func_003e2f60(3, 1, &work.in1);
    while (func_003df3c0(temp18, &work.code) != 0) {
      if (work.code == 0) goto done;
      switch (work.code) {
      case 22:
        if (var16 == NULL) {
          var16 = func_003e6a90(temp18);
          func_003ef260((const struct RwTexDictionary *)var16, K_Clump_AppendTextureName, &work.out);
          func_003ef1b0(var16);
        }
        break;
      case 16:
        if (var17 == NULL) var17 = func_003c0f20(temp18);
        break;
      default:
        func_003e2ce0(temp18, work.value);
        break;
      }
    }
  done:
    func_003e2e40(temp18, &work.in1); if (work.out != 0) K_Clump_FreeTextureNameList((void *)work.out); if (var17 == NULL) kAssertFail(D_00714520, 0x1DF); *(u8 **)(arg0 + 0x54) = var17; RpClumpForAllAtomics(var17, mdlEffectSetFlag40, NULL);
}





// Releases the source block at +0x58 through func_00492d00 when one is set.
// FUN_004AEC50
void ObjectParticleReleaseSource(u8 *arg0)
{
    u32 temp_4;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)arg0;

    temp_4 = (u32)inst->list;
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// Advances the record table: refreshes it through func_00492d10, then re-seeds each record whose source-side word at +0x10 is zero through func_004ae0a0.
// FUN_004AEC80
void ObjectParticleUpdateRecords(u8 *arg0)
{
    s32 temp_16;
    s32 var_20;
    u8 *var_18;
    u8 *var_17;
    u8 *temp_4;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)arg0;

    func_00492d10((void *)inst->list);
    temp_4 = inst->list;
    temp_16 = *(s32 *)(temp_4 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_4 + 0x10) != 0)) {
        var_18 = *(u8 **)(temp_4 + 0x18);
        var_17 = inst->entries;
        switch (inst->kind) {
        case 3:
            var_20 = 0;
            while (var_20 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) == 0) {
                    func_004ae0a0(arg0, var_17);
                }
                var_20++;
                var_18 += 0x20;
                var_17 += 0x18;
            }
            break;
        default:
            kAssertFail(D_00714520, 0x213);
            break;
        }
    }
}

typedef struct EffObjectRGBA {
    u32 rgba;
} EffObjectRGBA;

typedef struct EffObjectMatrix {
    f32 right[3];
    u32 flags;
    f32 up[3];
    u32 pad1;
    f32 at[3];
    u32 pad2;
    f32 pos[3];
    u32 pad3;
} __attribute__((aligned(16))) EffObjectMatrix;

#define EFF_OBJECT_PACK_COLOR10(packed, scale)                          \
    do {                                                                 \
        __asm__ volatile(                                                \
            "qmtc2.ni %0, $vf2\n"                                         \
            "vmulx.xyzw $vf10, $vf10, $vf2x\n" : : "r"(scale) : "$vf2", "$vf10"); \
        __asm__ volatile(                                                \
            "vftoi0.xyzw $vf10, $vf10\n"                                  \
            "qmfc2.ni %0, $vf10\n"                                        \
            "ppach %0, $0, %0\n"                                          \
            "ppacb %0, $0, %0\n" : "=r"(packed) : : "$vf10");            \
    } while (0)

/* The pos copy is three one-element array copies: b210 treats each as an
 * aggregate store, which stops its CSE from folding the particle life reload
 * for func_004ae2f0 into the loop test, while keeping retail's lwc1/swc1
 * interleave. */
// Draws the object particle's live records through RwMatrix transforms and the VU0 colour pack path, draws the clump atomics, and invokes TnInvokeCallback; colours are set through mdlEffectSetAllColors.
// FUN_004AED70
void ObjectParticleDraw(u8 *arg0)
{
    extern u_long128 mdlEffectLoadQuadB(int param_1, u32 *param_2);
    extern u_long128 mdlEffectLoadQuadA(int param_1, u32 *param_2);
    extern void effMiscBuildRotationVU(void);
    extern void func_004ae2f0(u8 *a, u8 *b, s32 c);
    extern void *mdlEffectSetAllColors(void *object, void *data);
    extern u8 *func_003bfe90(u8 *arg0);
    extern void RwMatrixMultiply(EffObjectMatrix *dst, EffObjectMatrix *a, EffObjectMatrix *b);
    extern void RwMatrixRotate(EffObjectMatrix *m, f32 *axis, f32 angle, s32 op);
    extern void RwMatrixScale(EffObjectMatrix *m, f32 *scale, s32 op);
    extern void RwMatrixTranslate(EffObjectMatrix *m, f32 *pos, s32 op);
    extern void func_003e9cb0(void *a, EffObjectMatrix *b, s32 c);
    extern void TnInvokeCallback(void);
    extern f32 fGpffff81f4;
    extern f32 fGpffff8048;
    extern f32 D_00713D20[];
    extern f32 D_00713D24[];
    extern f32 D_00713D28[];
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    extern EffectVuVector D_00713CE0;
    EffObjectRGBA packedArg;
    u32 colorWord;
    u32 colorA;
    u32 colorB;
    EffObjectRGBA packedA;
    EffObjectRGBA packedB;
    f32 vec[3];
    f32 pos[3];
    f32 axisA[3];
    f32 axisB[3];
    EffectVuVector colorBase;
    EffectVuVector snapB;
    EffectVuVector snapA;
    EffectVuVector snap[4];
    EffObjectMatrix matB;
    EffObjectMatrix base;
    EffObjectMatrix matA;
    f32 inv;
    f32 cscale;
    f32 full;
    f32 half;
    f32 zero;
    f32 one;
    f32 gscale;
    s32 i;
    ObjectParticleInstance *self;
    u8 *list;
    s32 count;
    u8 *p18;
    u8 *p17;
    u8 *clump;

    self = (ObjectParticleInstance *)arg0;
    colorWord = self->packedColour;
    {
        const u32 *word = &colorWord;

        cscale = fGpffff81f4;
        effectVuUnpackColor10V0(word, cscale);
    }
    effectVuStore10(&colorBase);
    list = self->list;
    count = *(s32 *)(list + 8);
    if (count != 0 && *(s32 *)(list + 0x10) != 0) {
    p18 = *(u8 **)(list + 0x18);
    p17 = self->entries;
    clump = self->clump;
    {
        f32 v = self->field_0x08;

        if (v != 0.0f) {
            one = 1.0f;
            inv = one / v;
        } else {
            one = 1.0f;
            inv = one;
        }
    }
    switch (self->kind) {
    case 3:
        if ((*(s32 *)(list + 0xC) & 1) == 0) {
            mdlEffectLoadQuadB((int)list, (u32 *)&snapA);
            effectVuLoad10(&snapA);
            effMiscBuildRotationVU();
            __asm__ volatile(
                "sqc2 $vf28, 0x0(%1)\n"
                "sqc2 $vf29, 0x10(%1)\n"
                "sqc2 $vf30, 0x20(%1)\n"
                "sqc2 $vf31, 0x30(%1)\n" : "=m"(snap) : "r"(snap) : "memory");
            base.right[0] = snap[0].lane[0];
            base.right[1] = snap[0].lane[1];
            base.right[2] = snap[0].lane[2];
            base.up[0] = snap[1].lane[0];
            base.up[1] = snap[1].lane[1];
            base.up[2] = snap[1].lane[2];
            base.at[0] = snap[2].lane[0];
            base.at[1] = snap[2].lane[1];
            base.at[2] = snap[2].lane[2];
            base.pos[0] = snap[3].lane[0];
            base.pos[1] = snap[3].lane[1];
            base.pos[2] = snap[3].lane[2];
            for (i = 0; i < count; i++, p18 += 0x20, p17 += 0x18) {
                s32 life = *(s32 *)(p18 + 0x10);

                if (life >= 0) {
                    f32 f;

                    colorA = *(u32 *)(p18 + 0x14);
                    effectVuUnpackColor10V0(&colorA, cscale);
                    effectVuLoad11(&colorBase);
                    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                    if (*(s8 *)(p17 + 0x14) >= 0) {
                        func_004ae2f0((u8 *)self, p17, life);
                    }
                    __asm__ volatile(
                        "lui $2, 0x437F\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni $2, $vf10\n"
                        "ppach $2, $0, $2\n"
                        "ppacb $2, $0, $2\n"
                        "sw $2, packedA\n" : "=m"(packedA) : : "$2", "$vf2", "$vf10");
                    *(u32 *)&packedArg = *(u32 *)&packedA;
                    RpClumpForAllAtomics(clump, (KClumpCallback)mdlEffectSetAllColors, &packedArg);
                    {
                        f32 age = (f32)*(s32 *)(p18 + 0x10);

                        f = *(f32 *)(p17 + 0x10) * age;
                        f = f + 0.5f * (age * (self->ageFactor * age));
                    }
                    if (f < 0.0f) {
                        matA.right[0] = matA.up[1] = matA.at[2] = 1.0f;
                        matA.right[1] = matA.right[2] = matA.up[0] = 0.0f;
                        matA.up[2] = matA.at[0] = matA.at[1] = 0.0f;
                        matA.pos[0] = matA.pos[1] = matA.pos[2] = 0.0f;
                        matA.flags = matA.flags | 0x20003;
                    } else {
                        axisA[0] = *(f32 *)(p17 + 0);
                        axisA[1] = *(f32 *)(p17 + 4);
                        axisA[2] = *(f32 *)(p17 + 8);
                        RwMatrixRotate(&matA, axisA, fGpffff8048 * (f + *(f32 *)(p17 + 0xC)), 0);
                    }
                    RwMatrixMultiply(&matB, &matA, &base);
                    if (self->field_0x30 == 0) {
                        vec[0] = D_00713D20[0] * *(f32 *)(p18 + 0x18);
                        vec[1] = D_00713D24[0] * *(f32 *)(p18 + 0x18);
                        vec[2] = D_00713D28[0] * *(f32 *)(p18 + 0x18);
                    } else {
                        f32 s = *(f32 *)(p18 + 0x18) * inv;

                        vec[0] = D_00713D20[0] * s;
                        vec[1] = D_00713D24[0] * s;
                        vec[2] = D_00713D28[0] * s;
                    }
                    RwMatrixScale(&matB, vec, 2);
                    vec[0] = *(f32 *)(p18 + 0);
                    vec[1] = *(f32 *)(p18 + 4);
                    vec[2] = *(f32 *)(p18 + 8);
                    RwMatrixTranslate(&matB, vec, 2);
                    func_003e9cb0(*(void **)(clump + 4), &matB, 0);
                    func_003bfe90(clump);
                }
            }
        } else {
            u32 mask;

            mdlEffectLoadQuadB((int)list, (u32 *)&snapA);
            mdlEffectLoadQuadA((int)self->list, (u32 *)&snapB);
            effectVuLoad10(&snapA);
            effMiscBuildRotationVU();
            __asm__ volatile("lqc2 $vf31, 0(%0)" : : "r"(&snapB), "m"(snapB) : "$vf31");
            __asm__ volatile(
                "sqc2 $vf28, 0x0(%1)\n"
                "sqc2 $vf29, 0x10(%1)\n"
                "sqc2 $vf30, 0x20(%1)\n"
                "sqc2 $vf31, 0x30(%1)\n" : "=m"(snap) : "r"(snap) : "memory");
            i = 0;
            full = 255.0f;
            half = 0.5f;
            zero = 0.0f;
            mask = 0x20003;
            gscale = fGpffff8048;
            for (; i < count; i++, p18 += 0x20, p17 += 0x18) {
                if (*(s32 *)(p18 + 0x10) >= 0) {
                    f32 f;

                    __asm__ volatile(
                        "lqc2 $vf28, 0x0(%0)\n"
                        "lqc2 $vf29, 0x10(%0)\n"
                        "lqc2 $vf30, 0x20(%0)\n"
                        "lqc2 $vf31, 0x30(%0)\n" : : "r"(snap), "m"(snap) : "$vf28", "$vf29", "$vf30", "$vf31");
                    effectVuLoad10((EffectVuVector *)p18);
                    __asm__ volatile(
                        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                        "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                        "vmaddw.xyzw $vf10, $vf31, $vf0w\n" : : : "$vf10");
                    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                    *(f32 (*)[1])&pos[0] = *(f32 (*)[1])D_00713D10;
                    *(f32 (*)[1])&pos[1] = *(f32 (*)[1])D_00713D14;
                    *(f32 (*)[1])&pos[2] = *(f32 (*)[1])D_00713D18;
                    colorB = *(u32 *)(p18 + 0x14);
                    effectVuUnpackColor10V0(&colorB, cscale);
                    effectVuLoad11(&colorBase);
                    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                    if (*(s8 *)(p17 + 0x14) >= 0) {
                        func_004ae2f0((u8 *)self, p17, *(s32 *)(p18 + 0x10));
                    }
                    effectVuScale10(full);
                    __asm__ volatile(
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni $2, $vf10\n"
                        "ppach $2, $0, $2\n"
                        "ppacb $2, $0, $2\n"
                        "sw $2, packedB\n" : "=m"(packedB) : : "$2", "$vf10");
                    *(u32 *)&packedArg = *(u32 *)&packedB;
                    RpClumpForAllAtomics(clump, (KClumpCallback)mdlEffectSetAllColors, &packedArg);
                    {
                        f32 age = (f32)*(s32 *)(p18 + 0x10);

                        f = *(f32 *)(p17 + 0x10) * age;
                        f = f + half * (age * (self->ageFactor * age));
                    }
                    if (f < zero) {
                        matB.right[0] = matB.up[1] = matB.at[2] = one;
                        matB.right[1] = matB.right[2] = matB.up[0] = zero;
                        matB.up[2] = matB.at[0] = matB.at[1] = zero;
                        matB.pos[0] = matB.pos[1] = matB.pos[2] = zero;
                        matB.flags = matB.flags | mask;
                    } else {
                        axisB[0] = *(f32 *)(p17 + 0);
                        axisB[1] = *(f32 *)(p17 + 4);
                        axisB[2] = *(f32 *)(p17 + 8);
                        RwMatrixRotate(&matB, axisB, gscale * (f + *(f32 *)(p17 + 0xC)), 0);
                    }
                    effectVuLoad10(&D_00713CE0);
                    if (self->field_0x30 == 0) {
                        vec[0] = D_00713D20[0] * *(f32 *)(p18 + 0x18);
                        vec[1] = D_00713D24[0] * *(f32 *)(p18 + 0x18);
                        vec[2] = D_00713D28[0] * *(f32 *)(p18 + 0x18);
                    } else {
                        f32 s = *(f32 *)(p18 + 0x18) * inv;

                        vec[0] = D_00713D20[0] * s;
                        vec[1] = D_00713D24[0] * s;
                        vec[2] = D_00713D28[0] * s;
                    }
                    RwMatrixScale(&matB, vec, 2);
                    RwMatrixTranslate(&matB, pos, 2);
                    func_003e9cb0(*(void **)(clump + 4), &matB, 0);
                    func_003bfe90(clump);
                }
            }
        }
        break;
    default:
        kAssertFail(D_00714520, 0x2A2);
        break;
    }
    TnInvokeCallback();
    }
}

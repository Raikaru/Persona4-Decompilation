#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "texture_callback_internal.h"
#include "effect_vu0_internal.h"
#include "particle_spawn_internal.h"

/* The object-specific table advances 0x18 bytes; the emitter advances 0x20. */
typedef struct ObjectParticleRecord {
    f32 axis[3];
    f32 angle;
    f32 angularVelocity;
    s8 rotationMode;
    u8 pad15[3];
} ObjectParticleRecord;

typedef unsigned int u_long128 __attribute__((mode(TI)));

extern void (*jtbl_008873EC[])(void *ptr);
extern void mdlEffectFreeEmitterAllocation(void *ptr);
extern void func_003c0700(void *particle);
extern u8 *func_003c0520(void *ptr);
extern void kAssertFail(const char *file, s32 line);
extern char D_00714520[];
extern void *mdlEffectSetFlag40(void *object, void *data);
extern void mdlEffectAdvanceEmitter(void *particle);
extern void mdlEffectInitDirectionEntry(void *particle, void *sourceId);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *mdlEffectAllocateTrackPath(u16 particle, u32 sourceId, void *sourceData);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *memset(void *dest, s32 value, s32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern char D_00714508[];
extern s32 func_003e2f60(s32 particle, s32 sourceId, s32 *sourceData);
extern s32 func_003df3c0(s32 particle, s32 *sourceId);
extern s32 func_003e2e40(s32 particle, s32 *sourceId);
extern u8 *func_003e6a90(s32 particle);
extern void func_003ef1b0(void *particle);
extern u8 *func_003c0f20(s32 particle);
extern void func_003e2ce0(s32 particle, u32 sourceId);
extern void K_Clump_FreeTextureNameList(void *particle);

void ObjectParticleLoadClump(u8 *particle, s32 sourceId, s32 sourceData);

void ObjectParticleShareClump(u8 *particle, u8 *sourceId);
void ObjectParticleRebuildRecords(u8 *particle, u32 sourceId, u8 *sourceData);

// Creates an object particle from an effect source: sizes the record buffer from the source's count (capped at 100), copies its 0x44-byte header, rebuilds the records and loads the clump when the kind at +0x1C is 3 and the lookup returns one.
// FUN_004AE460
void *ObjectParticleCreateFromSource(void *opaqueSource)
{
    EffSourceDescriptor *desc = (EffSourceDescriptor *)opaqueSource;
    EffSourceBlock *src;
    ObjectParticleInstance *inst;
    s32 resourceAddress;
    s32 sourceCount;
    u32 recordCapacity;

    src = (EffSourceBlock *)mdlEffectResolveRelPtrA(opaqueSource);
    if (src == NULL) {
        kAssertFail(D_00714520, 0xFD);
    }
    sourceCount = src->recordCount;
    if (sourceCount == 0) {
        recordCapacity = src->fallbackCount * src->recordMultiplier;
    } else {
        recordCapacity = sourceCount * src->recordMultiplier;
    }
    if (recordCapacity > 0x64) {
        recordCapacity = 0x64;
    }
    chkmemAllocSiteTag(D_00714508, 0x171);
    inst = (ObjectParticleInstance *)jtbl_008873E8[0](0x94, 0x40000);
    memset(inst, 0, 0x94);
    if (inst == NULL) {
        kAssertFail(D_00714520, 0xC5);
    }
    inst->recordCount = recordCapacity;
    inst->packedColour = -1;
    *(u32 *)&inst->field_0x08 = 0x3F800000;
    inst->recordStride = 0x18;
    inst->self = inst;
    if (inst == NULL) {
        kAssertFail(D_00714520, 0xFF);
    }
    memcpy((u8 *)inst + 0x10, src, 0x44);
    ObjectParticleRebuildRecords((u8 *)inst, desc->id, (u8 *)src + 0x44);
    if (((WaveSpawnEmitter *)inst->list)->totalCount == 0) {
        return inst;
    }
    resourceAddress = (s32)mdlEffectResolveRelPtrB(opaqueSource);
    if (resourceAddress != 0) {
        switch (desc->kind) {
        case 3:
            ObjectParticleLoadClump((u8 *)inst, resourceAddress, desc->clumpInput);
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
void ObjectParticleFree(u8 *particle)
{
    u32 sourceList;
    u32 recordAllocation;
    u8 *clump;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)particle;

    sourceList = (u32)inst->list;
    if (sourceList != 0) {
        mdlEffectFreeEmitterAllocation((void *)sourceList);
    }
    recordAllocation = (u32)inst->recordTable;
    if (recordAllocation != 0) {
        jtbl_008873EC[0]((void *)recordAllocation);
    }
    clump = inst->clump;
    if (clump != 0) {
        func_003c0700(clump);
    }
    jtbl_008873EC[0](particle);
}

// Creates an object particle from a parent record: sizes the record buffer from the parent's block and shares its clump; asserts the parent block exists.
// FUN_004AE6D0
/* Typed instance/parameter accesses changed this constructor from 432 to 444
 * bytes; retain the proven +0x58 list and +0x24 parameter-chain byte accesses. */
void *ObjectParticleCreateFromParent(void *opaqueSource)
{
    u8 *particle = opaqueSource;
    u32 sourceCount;
    u32 recordCapacity;
    u8 *parameters;
    u8 *createdObject;
    if (*(u8 **)(particle + 0x58) == 0) {
        kAssertFail(D_00714520, 0x148);
    }
    parameters = *(u8 **)(*(u8 **)(particle + 0x58) + 0x24);
    if (parameters == 0) {
        kAssertFail(D_00714520, 0x14A);
    }
    sourceCount = *(u32 *)(parameters + 0x20);
    if (sourceCount == 0) {
        recordCapacity = *(u32 *)(parameters + 0xB8) * *(u32 *)(parameters + 0x24);
    } else {
        recordCapacity = sourceCount * *(u32 *)(parameters + 0x24);
    }
    if (recordCapacity > 0x64) {
        recordCapacity = 0x64;
    }
    chkmemAllocSiteTag(D_00714508, 0x171);
    createdObject = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    memset(createdObject, 0, 0x94);
    if (createdObject == 0) {
        kAssertFail(D_00714520, 0xC5);
    }
    *(u32 *)(createdObject + 0) = recordCapacity;
    *(u32 *)(createdObject + 4) = -1;
    *(u32 *)(createdObject + 8) = 0x3F800000;
    *(u16 *)(createdObject + 0x7C) = 0x18;
    *(u8 **)(createdObject + 0x80) = createdObject;
    if (createdObject == 0) {
        kAssertFail(D_00714520, 0x14C);
    }
    memcpy(createdObject + 0x10, particle + 0x10, 0x44);
    ObjectParticleRebuildRecords(createdObject, *(u16 *)(*(u8 **)(particle + 0x58) + 0), parameters);
    if (*(u32 *)(*(u8 **)(createdObject + 0x58) + 8) == 0) {
        return createdObject;
    }
    ObjectParticleShareClump(createdObject, particle);
    return createdObject;
}
// Shares the clump of arg1 with arg0 after releasing arg0's own clump; asserts that the kind at +0xC of arg1 is 3.
// FUN_004AE880
void ObjectParticleShareClump(u8 *particle, u8 *sourceParticle)
{
    u8 *createdObject;
    ObjectParticleInstance *dst = (ObjectParticleInstance *)particle;
    ObjectParticleInstance *src = (ObjectParticleInstance *)sourceParticle;

    switch (src->kind) {
    case 3:
        if (dst->clump != 0) {
            func_003c0700(dst->clump);
        }
        createdObject = func_003c0520(src->clump);
        dst->clump = createdObject;
        RpClumpForAllAtomics(createdObject, mdlEffectSetFlag40, 0);
        break;
    default:
        kAssertFail(D_00714520, 0x172);
        break;
    }
    dst->kind = src->kind;
}

// Rebuilds the source block for id arg1 with parameters arg2, then re-allocates the 0x18-byte record table and seeds each record through func_004ae0a0.
// FUN_004AE930
void ObjectParticleRebuildRecords(u8 *particle, u32 sourceId, u8 *sourceData)
{
    ObjectParticleInstance *inst = (ObjectParticleInstance *)particle;
    u32 recordCount;
    u8 *recordCursor;
    u32 recordIndex;
    u8 *sourceList;

    sourceList = inst->list;
    if (sourceList != 0) {
        mdlEffectFreeEmitterAllocation(sourceList);
    }
    if ((u32)((WaveSpawnParameters *)sourceData)->trailCount != 0) {
        kAssertFail(D_00714520, 0x18B);
    }
    inst->list = mdlEffectAllocateTrackPath(sourceId & 0xFFFF, inst->recordCount, sourceData);
    if (inst->recordTable != 0) {
        jtbl_008873EC[0](inst->recordTable);
    }
    recordCount = ((WaveSpawnEmitter *)inst->list)->totalCount;
    chkmemAllocSiteTag(D_00714520, 0x195);
    inst->recordTable = (u8 *)jtbl_008873E8[0](recordCount * 0x18, 0x40000);
    if (inst->recordTable == 0) {
        kAssertFail(D_00714520, 0x196);
    }
    recordCursor = inst->recordTable;
    inst->entries = recordCursor;
    recordIndex = 0;
    while (recordIndex < recordCount) {
        mdlEffectInitDirectionEntry(particle, recordCursor);
        recordIndex++;
        recordCursor += 0x18;
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
/* Typed +0x58/+0x54 accesses changed this 480-byte window to 484 bytes;
 * keep byte addressing for the list checks and final clump store. */
void ObjectParticleLoadClump(u8 *particle, s32 resource, s32 resourceInput) {
    struct ObjectParticleResourceWork { s32 code; u32 value; u8 pad8[0x18]; s32 in1; s32 in2; s32 outpad; s32 out; } work;
    s32 stream; u8 *clump; u8 *textureDictionary;
    clump = NULL; textureDictionary = NULL; work.out = 0;
    if (*(u8 **)(particle + 0x58) == NULL) kAssertFail(D_00714520, 0x1B3);
    if (*(s32 *)(*(u8 **)(particle + 0x58) + 8) == 0) kAssertFail(D_00714520, 0x1B4);
    work.in1 = resource; work.in2 = resourceInput; stream = func_003e2f60(3, 1, &work.in1);
    while (func_003df3c0(stream, &work.code) != 0) {
      if (work.code == 0) goto done;
      switch (work.code) {
      case 22:
        if (textureDictionary == NULL) {
          textureDictionary = func_003e6a90(stream);
          func_003ef260((const struct RwTexDictionary *)textureDictionary, K_Clump_AppendTextureName, &work.out);
          func_003ef1b0(textureDictionary);
        }
        break;
      case 16:
        if (clump == NULL) clump = func_003c0f20(stream);
        break;
      default:
        func_003e2ce0(stream, work.value);
        break;
      }
    }
  done:
    func_003e2e40(stream, &work.in1); if (work.out != 0) K_Clump_FreeTextureNameList((void *)work.out); if (clump == NULL) kAssertFail(D_00714520, 0x1DF); *(u8 **)(particle + 0x54) = clump; RpClumpForAllAtomics(clump, mdlEffectSetFlag40, NULL);
}





// Releases the source block at +0x58 through func_00492d00 when one is set.
// FUN_004AEC50
void ObjectParticleReleaseSource(u8 *particle)
{
    u32 sourceList;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)particle;

    sourceList = (u32)inst->list;
    if (sourceList != 0) {
        mdlEffectResetEmitterTicks(sourceList);
    }
}

// Advances the record table: refreshes it through func_00492d10, then re-seeds each record whose source-side word at +0x10 is zero through func_004ae0a0.
// FUN_004AEC80
void ObjectParticleUpdateRecords(u8 *particle)
{
    s32 recordCount;
    s32 entryIndex;
    u8 *sourceRecord;
    u8 *objectRecord;
    u8 *sourceList;
    ObjectParticleInstance *inst = (ObjectParticleInstance *)particle;

    mdlEffectAdvanceEmitter((void *)inst->list);
    sourceList = inst->list;
    recordCount = (s32)((WaveSpawnEmitter *)sourceList)->totalCount;
    if ((recordCount != 0) && (((WaveSpawnEmitter *)sourceList)->ticks != 0)) {
        sourceRecord = (u8 *)((WaveSpawnEmitter *)sourceList)->particles;
        objectRecord = inst->entries;
        switch (inst->kind) {
        case 3:
            entryIndex = 0;
            while (entryIndex < recordCount) {
                if (((SpawnParticle *)sourceRecord)->age == 0) {
                    mdlEffectInitDirectionEntry(particle, objectRecord);
                }
                entryIndex++;
                sourceRecord += 0x20;
                objectRecord += 0x18;
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
/* Keep the two raw +0x10 age-to-float reloads: typed access changes alias
 * analysis (1968 bytes / normalized_diff 1089 versus the matching 1964).
 * The clump's +4 frame pointer remains raw; its surrounding layout is opaque here. */
// FUN_004AED70
void ObjectParticleDraw(u8 *particle)
{
    extern u_long128 mdlEffectLoadQuadB(int emitterAddress, u32 *snapshot);
    extern u_long128 mdlEffectLoadQuadA(int emitterAddress, u32 *snapshot);
    extern void effMiscBuildRotationVU(void);
    extern void mdlEffectMultiplyPaletteColorVU(u8 *a, u8 *b, s32 c);
    extern void *mdlEffectSetAllColors(void *object, void *data);
    extern u8 *func_003bfe90(u8 *particle);
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
    u8 *sourceRecord;
    u8 *objectRecord;
    u8 *clump;

    self = (ObjectParticleInstance *)particle;
    colorWord = self->packedColour;
    {
        const u32 *word = &colorWord;

        cscale = fGpffff81f4;
        effectVuUnpackColor10V0(word, cscale);
    }
    effectVuStore10(&colorBase);
    list = self->list;
    count = (s32)((WaveSpawnEmitter *)list)->totalCount;
    if (count != 0 && ((WaveSpawnEmitter *)list)->ticks != 0) {
    sourceRecord = (u8 *)((WaveSpawnEmitter *)list)->particles;
    objectRecord = self->entries;
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
        if (((s32)((WaveSpawnEmitter *)list)->flags & 1) == 0) {
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
            for (i = 0; i < count; i++, sourceRecord += 0x20, objectRecord += 0x18) {
                s32 life = ((SpawnParticle *)sourceRecord)->age;

                if (life >= 0) {
                    f32 f;

                    colorA = ((SpawnParticle *)sourceRecord)->color;
                    effectVuUnpackColor10V0(&colorA, cscale);
                    effectVuLoad11(&colorBase);
                    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                    if (((ObjectParticleRecord *)objectRecord)->rotationMode >= 0) {
                        mdlEffectMultiplyPaletteColorVU((u8 *)self, objectRecord, life);
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
                        f32 age = (f32)*(s32 *)(sourceRecord + 0x10);

                        f = ((ObjectParticleRecord *)objectRecord)->angularVelocity * age;
                        f = f + 0.5f * (age * (self->ageFactor * age));
                    }
                    if (f < 0.0f) {
                        matA.right[0] = matA.up[1] = matA.at[2] = 1.0f;
                        matA.right[1] = matA.right[2] = matA.up[0] = 0.0f;
                        matA.up[2] = matA.at[0] = matA.at[1] = 0.0f;
                        matA.pos[0] = matA.pos[1] = matA.pos[2] = 0.0f;
                        matA.flags = matA.flags | 0x20003;
                    } else {
                        axisA[0] = ((ObjectParticleRecord *)objectRecord)->axis[0];
                        axisA[1] = ((ObjectParticleRecord *)objectRecord)->axis[1];
                        axisA[2] = ((ObjectParticleRecord *)objectRecord)->axis[2];
                        RwMatrixRotate(&matA, axisA, fGpffff8048 * (f + ((ObjectParticleRecord *)objectRecord)->angle), 0);
                    }
                    RwMatrixMultiply(&matB, &matA, &base);
                    if (self->field_0x30 == 0) {
                        vec[0] = D_00713D20[0] * ((SpawnParticle *)sourceRecord)->size;
                        vec[1] = D_00713D24[0] * ((SpawnParticle *)sourceRecord)->size;
                        vec[2] = D_00713D28[0] * ((SpawnParticle *)sourceRecord)->size;
                    } else {
                        f32 s = ((SpawnParticle *)sourceRecord)->size * inv;

                        vec[0] = D_00713D20[0] * s;
                        vec[1] = D_00713D24[0] * s;
                        vec[2] = D_00713D28[0] * s;
                    }
                    RwMatrixScale(&matB, vec, 2);
                    vec[0] = ((SpawnParticle *)sourceRecord)->position.lane[0];
                    vec[1] = ((SpawnParticle *)sourceRecord)->position.lane[1];
                    vec[2] = ((SpawnParticle *)sourceRecord)->position.lane[2];
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
            for (; i < count; i++, sourceRecord += 0x20, objectRecord += 0x18) {
                if (((SpawnParticle *)sourceRecord)->age >= 0) {
                    f32 f;

                    __asm__ volatile(
                        "lqc2 $vf28, 0x0(%0)\n"
                        "lqc2 $vf29, 0x10(%0)\n"
                        "lqc2 $vf30, 0x20(%0)\n"
                        "lqc2 $vf31, 0x30(%0)\n" : : "r"(snap), "m"(snap) : "$vf28", "$vf29", "$vf30", "$vf31");
                    effectVuLoad10((EffectVuVector *)sourceRecord);
                    __asm__ volatile(
                        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                        "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                        "vmaddw.xyzw $vf10, $vf31, $vf0w\n" : : : "$vf10");
                    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                    *(f32 (*)[1])&pos[0] = *(f32 (*)[1])D_00713D10;
                    *(f32 (*)[1])&pos[1] = *(f32 (*)[1])D_00713D14;
                    *(f32 (*)[1])&pos[2] = *(f32 (*)[1])D_00713D18;
                    colorB = ((SpawnParticle *)sourceRecord)->color;
                    effectVuUnpackColor10V0(&colorB, cscale);
                    effectVuLoad11(&colorBase);
                    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                    if (((ObjectParticleRecord *)objectRecord)->rotationMode >= 0) {
                        mdlEffectMultiplyPaletteColorVU((u8 *)self, objectRecord, ((SpawnParticle *)sourceRecord)->age);
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
                        f32 age = (f32)*(s32 *)(sourceRecord + 0x10);

                        f = ((ObjectParticleRecord *)objectRecord)->angularVelocity * age;
                        f = f + half * (age * (self->ageFactor * age));
                    }
                    if (f < zero) {
                        matB.right[0] = matB.up[1] = matB.at[2] = one;
                        matB.right[1] = matB.right[2] = matB.up[0] = zero;
                        matB.up[2] = matB.at[0] = matB.at[1] = zero;
                        matB.pos[0] = matB.pos[1] = matB.pos[2] = zero;
                        matB.flags = matB.flags | mask;
                    } else {
                        axisB[0] = ((ObjectParticleRecord *)objectRecord)->axis[0];
                        axisB[1] = ((ObjectParticleRecord *)objectRecord)->axis[1];
                        axisB[2] = ((ObjectParticleRecord *)objectRecord)->axis[2];
                        RwMatrixRotate(&matB, axisB, gscale * (f + ((ObjectParticleRecord *)objectRecord)->angle), 0);
                    }
                    effectVuLoad10(&D_00713CE0);
                    if (self->field_0x30 == 0) {
                        vec[0] = D_00713D20[0] * ((SpawnParticle *)sourceRecord)->size;
                        vec[1] = D_00713D24[0] * ((SpawnParticle *)sourceRecord)->size;
                        vec[2] = D_00713D28[0] * ((SpawnParticle *)sourceRecord)->size;
                    } else {
                        f32 s = ((SpawnParticle *)sourceRecord)->size * inv;

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

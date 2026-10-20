/* Original translation unit effPolygonTrack.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "polygon_track_internal.h"
#include "include_asm.h"
#include "member_access.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

/* Multipart geometry extends the 0x48-byte block with counts and its material table. */
typedef struct EffGeometryMultiPart {
    EffGeometryBlock base;
    u8 pad48[0xC];
    u8 *materials; /* +0x54: one material pointer per part */
} EffGeometryMultiPart;

/* Source resources concatenate the copied 0x1C-byte track record and emitter parameters. */
typedef struct EffTrackSourceRecord {
    EffTrackRecord record;
    EffTrackPathParameters parameters;
} EffTrackSourceRecord;

extern void ParticleFree(void *particle);
extern void mdlEffectDestroyGeometryPair(void *instance);
extern void mdlEffectFreeEmitterAllocation(u8 *instance);
extern void mdlEffectResetEmitterTicks(s32 instance);
extern u_long128 mdlEffectStoreQuadA(s32 instance, u32 *quadData);
extern u_long128 mdlEffectStoreQuadB(s32 instance, u32 *quadData);
extern void EffEmitterApplyScale(u16 *emitter, f32 scale);
extern void mdlSetObjectHeaderValue(void *object, u32 value);
extern void (*jtbl_008873EC[])(void *);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void kAssertFail(const void *file, s32 line);
extern void memset(void *dst, s32 value, u32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern char D_00713E20[];
extern char D_00713E30[];
extern void *ParticleCreateBlock(s32 recordCount);
extern u8 *GeometryCloneBlock(u8 *source);
extern void ParticleCopyModeFromSource(void *particle, void *source);
extern u8 *mdlEffectAllocateTrackPath(u16 kind, u32 primaryCount, void *parameters);
extern void mdlEffectInterpolateRibbonColors(void *track, void *colors);
extern u8 *TrackAllocRibbons(u16 count, u16 segments);
extern void TrackUpdateSlots(u8 *instance);
extern void TrackCopyState(u8 *destination, u8 *source);
extern void TrackLoadRecord(u8 *instance, u16 kind, u8 *record);
extern void TrackRebindPathData(u8 *instance, u16 kind, u8 *parameters);
extern void TrackApplyMode(u8 *instance, u16 mode, s32 *resource);
extern void mdlEffectLoadQuadB(void *instance, u32 *quadData);
extern void mdlEffectLoadQuadA(void *instance, u32 *quadData);
/* lint-allow: arity kept at four arguments. The definition in mdlEffect.c takes one; a one-argument call here moved the codegen of both TrackRefresh call pairs (verify MISMATCH 2). */
extern void mdlEffectApplyGeometryMatrix(void *geometry, void *position, void *rotation, f32 scale);
extern void ParticleProjectVertices(void *particle, f32 scale);
extern void mdlEffectSetGeometryPairResource(void *instance, u32 value);
extern void mdlEffectAdvanceEmitter(void *object);
extern void mdlEffectAdvanceRibbon(void *track, u16 trackIndex, void *point, f32 width);
extern void mdlEffectSetRibbonMaterialColor(void *ribbons, u16 materialIndex, void *color);
extern void mdlEffectCopyOriginAndLockGeometry(void *instance);
extern void mdlEffectUnlockGeometryPair(void *instance);
extern u8 *GeometryCreateStripGridMultiPart(u16 partCount, u16 rowCount, void *indices, s32 verticesPerRow, s32 flags);
extern u8 *GeometryCreateTableGridMultiPart(u16 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow, void *indices, s32 flags);
extern void ParticleSetMaterialSlot(u8 *particle, s32 source, s32 options);
extern void ParticleSetTextureFromHandle(u8 *particle, s32 source);
extern void ParticleSetLinkedGroup(u8 *particle, s32 *source);
extern void ParticleSetTextureById(u8 *particle, s32 source);
extern void ParticleRebuildSubtypeChain(u8 *particle, void *source);
extern void ParticleRebuildSubtypeChainAlt(u8 *particle, void *source);
extern void ParticleSetAuxResource(u8 *particle, s32 *source);
extern u8 D_00764C54[4];
extern f32 D_00761134;
extern u8 D_00922D80[];
extern u8 D_00713310[];
extern u8 D_00713420[];


typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern LineNovaColor iGpffffbb64; /* default packed material color */



// Allocates a 0x38-byte track instance with a count, unit scale and a single-entry mode word.
// FUN_00492E70
void *TrackAllocInstance(u32 count)
{
    u8 *instance;

    chkmemAllocSiteTag(&D_00713E20, 0x171);
    instance = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    memset(instance, 0, 0x38);
    if (instance == NULL) {
        kAssertFail(&D_00713E30, 0x32);
    }
    ((EffTrackInstance *)instance)->count.value = count;
    ((EffTrackInstance *)instance)->packedColor.value = -1;
    ((EffTrackInstance *)instance)->scale = 1.0f;
    ((EffTrackInstance *)instance)->active = 1;
    return instance;
}

/* measured: arg1's u16 load must be emitted before the $a0 move (retail's
   pre-jal order). On the identical call pattern in TrackCreateWithMode the plain
   read measures nd 5 (lhu/move swapped at both sites) and a shared named
   local nd 62 (spills into $s2); the volatile-anchored read applied here
   first try, nd 0. */
// Creates a track from an emitter, with the count (params times segments) capped at 100 (0x64).
// FUN_00492F20
void *TrackCreateFromEmitter(void *opaqueSource)
{
    EffTrackInstance *track;
    /* Access-site typing differed by 71 normalized bytes; typed local pointers preserve the original reload lifetimes. */
    u8 *source = opaqueSource;
    EffSourceDescriptor *descriptor = (EffSourceDescriptor *)source;
    u8 *record;
    EffTrackSourceRecord *sourceRecord;
    u32 count;
    u8 *instance;

    record = mdlEffectResolveRelPtrA(source);
    if (record == NULL) {
        kAssertFail(D_00713E30, 0x61);
    }
    sourceRecord = (EffTrackSourceRecord *)record;
    if (sourceRecord->parameters.emissionDuration.value == 0) {
        count = (u32)(sourceRecord->parameters.lifetime * sourceRecord->parameters.emissionRate);
    } else {
        count = (u32)(sourceRecord->parameters.emissionDuration.signedValue * sourceRecord->parameters.emissionRate);
    }
    if (count > 0x64) {
        count = 0x64;
    }
    chkmemAllocSiteTag(&D_00713E20, 0x171);
    instance = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    track = (EffTrackInstance *)instance;
    memset(instance, 0, 0x38);
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x32);
    }
    track->count.value = count;
    track->packedColor.value = -1;
    track->scale = 1.0f;
    track->active = 1;
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x63);
    }
    {
        u16 kind = *(volatile u16 *)&descriptor->id;

        TrackLoadRecord(instance, kind, record);
    }
    TrackRebindPathData(instance, *(volatile u16 *)&descriptor->id, record + 0x1C);
    return instance;
}

/* measured: correcting the direct effect-helper declarations and passing the
   selector as ParticleSetMaterialSlot's third argument keeps arg1&0xFFFF in $a2 across
   the dispatch; object 376B/384B, normalized_diff 0 (jump-table relocations
   are the only fndiff rows). */
// Applies a mode to the track's sub-object: dispatches on the mode value to the matching setter.
// FUN_00493080
void TrackApplyMode(u8 *instance, u16 mode, s32 *resource) {
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 242). */
    u8 *particle;

    if (track->particle.bytes == NULL) {
        particle = ParticleCreateBlock(track->count.signedValue);
        track->particle.bytes = particle;
        ((EffParticleInstance *)particle)->emitter.handle = track->path.signedValue;
    }
    switch ((u32)mode) {
    case 1:
        ParticleSetMaterialSlot(track->particle.bytes, track->count.signedValue, (s32)mode);
        ParticleSetTextureFromHandle(track->particle.bytes, (s32)resource);
        break;
    case 2:
        ParticleSetMaterialSlot(track->particle.bytes, track->count.signedValue, (s32)mode);
        ParticleSetLinkedGroup(track->particle.bytes, resource);
        break;
    case 4:
        ParticleSetMaterialSlot(track->particle.bytes, track->count.signedValue, (s32)mode);
        ParticleSetTextureById(track->particle.bytes, *(s32 *)resource);
        break;
    case 5:
        ParticleRebuildSubtypeChain(track->particle.bytes, resource);
        break;
    case 6:
        ParticleRebuildSubtypeChainAlt(track->particle.bytes, resource);
        break;
    case 7:
        ParticleSetMaterialSlot(track->particle.bytes, track->count.signedValue, (s32)mode);
        ParticleSetAuxResource(track->particle.bytes, resource);
        break;
    case 0:
    case 3:
    default:
        kAssertFail(D_00713E30, 0xA8);
        break;
    }
    ((EffParticleInstance *)track->particle.bytes)->kind = (s16)mode;
}
/* measured: same volatile-anchored arg1 read as 0x00492f20; plain reads
   swap the lhu/move order at both call sites (nd 5), local spills (nd 62). */
// Creates a track from an emitter and applies the emitter's mode when one is attached.
// FUN_00493200
void *TrackCreateWithMode(void *opaqueSource)
{
    EffTrackInstance *track;
    /* Access-site typing differed by 187 normalized bytes; typed local pointers preserve the original reload lifetimes. */
    u8 *source = opaqueSource;
    EffSourceDescriptor *descriptor = (EffSourceDescriptor *)source;
    u8 *record;
    EffTrackSourceRecord *sourceRecord;
    u8 *parameters;
    EffTrackPathParameters *parameterBlock;
    u32 count;
    u8 *instance;

    record = mdlEffectResolveRelPtrA(source);
    if (record == NULL) {
        kAssertFail(D_00713E30, 0x61);
    }
    sourceRecord = (EffTrackSourceRecord *)record;
    parameters = record + 0x1C;
    parameterBlock = (EffTrackPathParameters *)parameters;
    if (sourceRecord->parameters.emissionDuration.value == 0) {
        count = (u32)(parameterBlock->lifetime * parameterBlock->emissionRate);
    } else {
        count = (u32)(sourceRecord->parameters.emissionDuration.signedValue * parameterBlock->emissionRate);
    }
    if (count > 0x64) {
        count = 0x64;
    }
    instance = TrackAllocInstance(count);
    track = (EffTrackInstance *)instance;
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x63);
    }
    {
        u16 kind = *(volatile u16 *)&descriptor->id;

        TrackLoadRecord(instance, kind, record);
    }
    TrackRebindPathData(instance, *(volatile u16 *)&descriptor->id, record + 0x1C);
    {
        s32 *resource = (s32 *)mdlEffectResolveRelPtrB(source);

        if (resource != NULL) {
            TrackApplyMode(instance, descriptor->kind, resource);
        }
    }
    return instance;
}

// Frees a track: its ribbon sub-object, its second sub-object, its path block, then the instance.
// FUN_00493320
void TrackFreeInstance(u8 *instance)
{
    u32 particle;
    u32 ribbons;
    u8 *path;

    particle = ((EffTrackInstance *)instance)->particle.value;
    if (particle != 0) {
        ParticleFree((void *)particle);
    }
    ribbons = ((EffTrackInstance *)instance)->ribbons.value;
    if (ribbons != 0) {
        mdlEffectDestroyGeometryPair((void *)ribbons);
    }
    path = ((EffTrackInstance *)instance)->path.bytes;
    if (path != NULL) {
        mdlEffectFreeEmitterAllocation(path);
    }
    jtbl_008873EC[0](instance);
}
/* measured: same volatile-anchored arg1 read as 0x00492f20 (see its
   note); plain reads swap the lhu/move order at both call sites. */
// Creates a track from an owner's track data, with the count capped at 100 (0x64).
// FUN_004933A0
void *TrackCreateFromSource(void *opaqueSource)
{
    EffTrackInstance *track;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 237). */
    u8 *source = opaqueSource;
    EffTrackInstance *sourceTrack = (EffTrackInstance *)source;
    u8 *parameters;
    u32 count;
    u8 *instance;

    if (sourceTrack->path.bytes == NULL) {
        kAssertFail(D_00713E30, 0xE6);
    }
    parameters = ((EffTrackPath *)sourceTrack->path.bytes)->originalParameters;
    if (parameters == NULL) {
        kAssertFail(D_00713E30, 0xE8);
    }
    if (((EffTrackPathParameters *)parameters)->emissionDuration.value == 0) {
        count = (u32)(((EffTrackPathParameters *)parameters)->lifetime * ((EffTrackPathParameters *)parameters)->emissionRate);
    } else {
        count = (u32)(((EffTrackPathParameters *)parameters)->emissionDuration.signedValue * ((EffTrackPathParameters *)parameters)->emissionRate);
    }
    if (count > 0x64) {
        count = 0x64;
    }
    chkmemAllocSiteTag(&D_00713E20, 0x171);
    instance = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    track = (EffTrackInstance *)instance;
    memset(instance, 0, 0x38);
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x32);
    }
    track->count.value = count;
    track->packedColor.value = -1;
    track->scale = 1.0f;
    track->active = 1;
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0xEA);
    }
    {
        u16 kind = *(volatile u16 *)&((EffTrackPath *)sourceTrack->path.bytes)->kind;

        TrackLoadRecord(instance, kind, source + 0xC);
    }
    TrackRebindPathData(instance, *(volatile u16 *)&((EffTrackPath *)sourceTrack->path.bytes)->kind, parameters);
    return instance;
}

/* measured: same volatile-anchored arg1 read as 0x00492f20 (see its
   note); plain reads swap the lhu/move order at both call sites. */
// Creates a track from an owner source and copies the source track's state across.
// FUN_00493530
void *TrackCreateFromSourceCopy(void *opaqueSource)
{
    EffTrackInstance *track;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 249). */
    u8 *source = opaqueSource;
    EffTrackInstance *sourceTrack = (EffTrackInstance *)source;
    u8 *parameters;
    u32 count;
    u8 *instance;

    if (sourceTrack->path.bytes == NULL) {
        kAssertFail(D_00713E30, 0xFE);
    }
    parameters = ((EffTrackPath *)sourceTrack->path.bytes)->originalParameters;
    if (parameters == NULL) {
        kAssertFail(D_00713E30, 0x100);
    }
    if (((EffTrackPathParameters *)parameters)->emissionDuration.value == 0) {
        count = (u32)(((EffTrackPathParameters *)parameters)->lifetime * ((EffTrackPathParameters *)parameters)->emissionRate);
    } else {
        count = (u32)(((EffTrackPathParameters *)parameters)->emissionDuration.signedValue * ((EffTrackPathParameters *)parameters)->emissionRate);
    }
    if (count > 0x64) {
        count = 0x64;
    }
    chkmemAllocSiteTag(&D_00713E20, 0x171);
    instance = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    track = (EffTrackInstance *)instance;
    memset(instance, 0, 0x38);
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x32);
    }
    track->count.value = count;
    track->packedColor.value = -1;
    track->scale = 1.0f;
    track->active = 1;
    if (instance == NULL) {
        kAssertFail(D_00713E30, 0x102);
    }
    {
        u16 kind = *(volatile u16 *)&((EffTrackPath *)sourceTrack->path.bytes)->kind;

        TrackLoadRecord(instance, kind, source + 0xC);
    }
    TrackRebindPathData(instance, *(volatile u16 *)&((EffTrackPath *)sourceTrack->path.bytes)->kind, parameters);
    TrackCopyState(instance, source);
    return instance;
}

// Clones optional particle geometry and copies the source particle mode and kind into the destination track.
// FUN_004936D0
void TrackCopyState(u8 *destination, u8 *source)
{
    /* Nine child-link sites require byte aliasing: access-site, typed-local,
     * array and existing-union forms each changed retail instructions.
     * MEMBER retains each original base and pointer width (see culprit TSV). */
    u8 *particleOrGeometry;

    if (((EffTrackInstance *)source)->particle.value == 0) {
        kAssertFail(D_00713E30, 0x115);
    }
    if (((EffTrackInstance *)destination)->particle.value == 0) {
        particleOrGeometry = ParticleCreateBlock(((EffTrackInstance *)destination)->count.signedValue);
        MEMBER(u8 *, destination, EffTrackInstance, particle) = particleOrGeometry;
        ((EffParticleInstance *)MEMBER(u8 *, destination, EffTrackInstance, particle))->emitter.bits =
            ((EffTrackInstance *)destination)->path.value;
    }
    if (((EffParticleInstance *)MEMBER(u8 *, source, EffTrackInstance, particle))->geometry.handle != 0) {
        particleOrGeometry = GeometryCloneBlock(((EffParticleInstance *)MEMBER(u8 *, source, EffTrackInstance, particle))->geometry.bytes);
        ((EffParticleInstance *)MEMBER(u8 *, destination, EffTrackInstance, particle))->geometry.bytes = particleOrGeometry;
    }
    ParticleCopyModeFromSource(MEMBER(u8 *, destination, EffTrackInstance, particle), MEMBER(u8 *, source, EffTrackInstance, particle));
    ((EffParticleInstance *)MEMBER(u8 *, destination, EffTrackInstance, particle))->kind =
        ((EffParticleInstance *)MEMBER(u8 *, source, EffTrackInstance, particle))->kind;
}

// Copies the 0x1C source record in and rebuilds the 0x28 sub-object when the track is live.
// FUN_00493790
void TrackLoadRecord(u8 *instance, u16 kind, u8 *record)
{
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 94). */
    u8 *ribbons;

    memcpy(instance + 0xC, record, 0x1C);
    if (track->count.value != 0) {
        if (track->ribbons.value != 0) {
            mdlEffectDestroyGeometryPair((void *)track->ribbons.value);
        }
        ribbons = TrackAllocRibbons(track->count.low, *(u16 *)record);
        track->ribbons.bytes = ribbons;
        mdlEffectInterpolateRibbonColors(ribbons, record + 8);
    }
}

// Rebinds the track's path data: frees the old 0x30 block and allocates a new one for the index.
// FUN_00493820
void TrackRebindPathData(u8 *instance, u16 kind, u8 *parameters)
{
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 94). */
    if (track->path.value != 0) {
        mdlEffectFreeEmitterAllocation((u8 *)track->path.value);
    }
    if (((EffTrackPathParameters *)parameters)->trailCount != 0) {
        kAssertFail(&D_00713E30, 0x14E);
    }
    track->path.value = (u32)mdlEffectAllocateTrackPath(kind & 0xFFFF, track->count.value, parameters);
}

// Releases the track's sub-object through the sub-object release callback.
// FUN_004938B0
void TrackReleaseSubobject(u8 *instance)
{
    u32 path;

    path = ((EffTrackInstance *)instance)->path.value;
    if (path != 0) {
        mdlEffectResetEmitterTicks(path);
    }
}

/* MATCHED.  Three shapes carried it.  `opt_common_subs off` is required: with
   it on, b210 hoists the `andi $a1, $s2, 0xffff` index mask into a saved
   register and moves it to $a1 at each of the six call sites, which costs an
   extra saved register and 0x10 of frame; retail rematerialises the mask at
   every call.  Narrowing the five per-index callees above to `u16 arg1` is
   what makes the mask a parameter promotion rather than a common
   subexpression, and it also removes the double `lwc1 $f20` that
   `opt_common_subs off` alone introduced (152 words -> 98 with exact 171/171
   instruction counts).  The last four words were the `mode == -1 ||
   mode == 0` test: b210 folds it to the range trick `addiu $v0, $v1, 1;
   sltiu $at, $v0, 2; beqz $at`, while retail keeps two explicit compares
   (`addiu $v0, $zero, -1; beq; nop; bnez`), which only the goto form
   reproduces - `opt_rebuildconditionals off` does not.  The COP2 colour
   unpack follows the established idiom in src/Graphics/Effect/effBlurFilter.c;
   the `sw $2, 0x90($sp)` slot and its volatile reload are part of it. */
// Per-frame update: writes each live track sample into its owner slot, then sets the owner's colour and width.
// FUN_004938E0
void TrackUpdateSlots(u8 *instance)
{
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 479). */
    extern f32 fGpffff8044;
    extern void ParticleUpdateScaled(void *particle, f32 scale);
    s32 materialColor;
    s32 baseColor;
    s32 sampleColor;
    s32 modulatedColor;
    f32 position[3];
    u8 colorFactors[16] __attribute__((aligned(16)));
    s32 *colorWord;
    f32 scale;
    u8 *path;
    u8 *sample;
    s32 sampleIndex;
    u8 *ribbons;
    s32 count;
    s32 mode;

    if (track->count.signedValue == 0) {
        return;
    }
    mdlEffectAdvanceEmitter(track->path.pointer);
    path = track->path.bytes;
    baseColor = track->packedColor.signedValue;
    colorWord = &baseColor;
    scale = fGpffff8044;
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10    \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $2, %1           \n"
        "nop                   \n"
        "qmtc2.ni $2, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        :
        : "r"(colorWord), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(colorFactors) : "$vf10", "memory");
    sample = ((EffTrackPath *)path)->samples;
    count = track->count.signedValue;
    ribbons = track->ribbons.bytes;
    mdlEffectCopyOriginAndLockGeometry(ribbons);
    for (sampleIndex = 0; sampleIndex < count; sampleIndex++, sample += 0x20) {
        if (mdlEffectSlotIsFree(ribbons, sampleIndex) != 0) {
            continue;
        }
        mode = ((EffTrackSample *)sample)->mode;
        if (mode == -2) {
            mdlEffectAdvanceRibbon(ribbons, sampleIndex, D_00922D80, 0.0f);
            mdlEffectSetRibbonMaterialColor(ribbons, sampleIndex, &iGpffffbb64);
            mdlEffectSlotRelease(ribbons, sampleIndex);
            continue;
        }
        if (mode == -1) {
            goto clear_entry;
        }
        if (mode != 0) {
            goto draw_entry;
        }
clear_entry:
        mdlEffectAdvanceRibbon(ribbons, sampleIndex, D_00922D80, 0.0f);
        mdlEffectSetRibbonMaterialColor(ribbons, sampleIndex, &iGpffffbb64);
        mdlEffectSlotSetZero(ribbons, sampleIndex);
        continue;
draw_entry:
        position[0] = ((EffTrackSample *)sample)->position[0];
        position[1] = ((EffTrackSample *)sample)->position[1];
        position[2] = ((EffTrackSample *)sample)->position[2];
        mdlEffectAdvanceRibbon(ribbons, sampleIndex, position, ((EffTrackSample *)sample)->width);
        sampleColor = ((EffTrackSample *)sample)->packedColor;
        colorWord = &sampleColor;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            :
            : "r"(colorWord), "f"(scale)
            : "$2", "$vf2", "$vf10", "memory");
        __asm__ volatile(
            "lqc2 $vf11, 0(%0)     \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x90($sp)      \n"
            :
            : "r"(colorFactors)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        /* measured: this volatile read is the COP2 block's OUTPUT PATH, not a
           reload hack on ordinary memory.  The asm above ends in
           `sw $2, 0x90($sp)`, a hard-coded frame offset the compiler cannot
           associate with `modulatedColor`; because `modulatedColor` is a local whose address is
           never taken, b210 correctly concludes no asm can have touched it and
           the "memory" clobber does not reach it, so a plain read is folded
           away.  Three legal alternatives were measured and each LOSES the
           match (19 -> 18 MATCH, 1 MISMATCH in this file): a plain
           `materialColor = modulatedColor;`, declaring the slot as an asm output with
           `"=m"(modulatedColor)` and `sw $2, %0`, and taking the address into a local
           `s32 *slotOut = &modulatedColor;` so the clobber applies.  The cast stays. */
        materialColor = *(volatile s32 *)&modulatedColor;
        mdlEffectSetRibbonMaterialColor(ribbons, sampleIndex, &materialColor);
    }
    mdlEffectUnlockGeometryPair(ribbons);
    if (track->particle.bytes == NULL) {
        return;
    }
    if (((EffTrackPath *)track->path.bytes)->ticks.value < track->record.drawStart) {
        return;
    }
    mdlSetObjectHeaderValue(track->particle.pointer, track->packedColor.value);
    ParticleUpdateScaled(track->particle.pointer, track->record.width / 10.0f);
}
// Applies the track width to its ribbon geometry when the track has more than one sample.
// FUN_00493B90
void TrackApplyWidth(u8 *instance)
{
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 189). */
    if (track->count.value != 0) {
        s32 sampleCount = ((EffTrackPath *)track->path.bytes)->ticks.signedValue;

        if (sampleCount > 1) {
            u8 *ribbons = track->ribbons.bytes;
            u8 *parameters = ((EffTrackPath *)track->path.bytes)->parameters;

            if (((EffTrackPath *)track->path.bytes)->flags & 1) {
                u32 position[4];
                u32 rotation[4];

                mdlEffectLoadQuadB(track->path.bytes, rotation);
                mdlEffectLoadQuadA(track->path.bytes, position);
                mdlEffectApplyGeometryMatrix((void *)((EffTrackRibbons *)ribbons)->ribbon, position, rotation, 1.0f);
                mdlEffectApplyGeometryMatrix((void *)((EffTrackRibbons *)ribbons)->cap, position, rotation, 1.0f);
            }
            if (track->particle.value != 0) {
                ParticleProjectVertices(track->particle.bytes, track->record.width / 10.0f);
            }
            mdlEffectSetGeometryPairResource(ribbons, ((EffTrackPathParameters *)parameters)->unk54);
        }
    }
}

// Per-frame refresh: runs the slot update, then applies the width when the track has more than one sample.
// FUN_00493C90
void TrackRefresh(u8 *instance)
{
    EffTrackInstance *track = (EffTrackInstance *)instance;
    /* Keep instance/child byte accesses: the proven EffTrackInstance layout changed b210 codegen (instance-only normalized_diff 189). */
    TrackUpdateSlots(instance);
    if (track->count.value != 0) {
        s32 sampleCount = ((EffTrackPath *)track->path.bytes)->ticks.signedValue;

        if (sampleCount > 1) {
            u8 *ribbons = track->ribbons.bytes;
            u8 *parameters = ((EffTrackPath *)track->path.bytes)->parameters;

            if (((EffTrackPath *)track->path.bytes)->flags & 1) {
                u32 position[4];
                u32 rotation[4];

                mdlEffectLoadQuadB(track->path.bytes, rotation);
                mdlEffectLoadQuadA(track->path.bytes, position);
                mdlEffectApplyGeometryMatrix((void *)((EffTrackRibbons *)ribbons)->ribbon, position, rotation, 1.0f);
                mdlEffectApplyGeometryMatrix((void *)((EffTrackRibbons *)ribbons)->cap, position, rotation, 1.0f);
            }
            if (track->particle.value != 0) {
                ParticleProjectVertices(track->particle.bytes, track->record.width / 10.0f);
            }
            mdlEffectSetGeometryPairResource(ribbons, ((EffTrackPathParameters *)parameters)->unk54);
        }
    }
}

// Forwards a position to the track emitter.
// FUN_00493DA0
void TrackSetPosition(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(((EffTrackInstance *)instance)->path.signedValue, position);
}

// Forwards a rotation to the track emitter.
// FUN_00493DD0
void TrackSetRotation(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(((EffTrackInstance *)instance)->path.signedValue, rotation);
}

// Stores the track colour word and forwards it to the owner's colour setter.
// FUN_00493E00
void TrackSetColor(u8 *instance, u32 color)
{
    u32 particle;

    ((EffTrackInstance *)instance)->packedColor.value = color;
    particle = ((EffTrackInstance *)instance)->particle.value;
    if (particle != 0) {
        mdlSetObjectHeaderValue((void *)particle, color);
    }
}

// Stores the track scale and forwards it to the emitter's scale setter.
// FUN_00493E30
void TrackSetScale(u8 *instance, f32 scale)
{
    ((EffTrackInstance *)instance)->scale = scale;
    EffEmitterApplyScale((u16 *)((EffTrackInstance *)instance)->path.value, scale);
}

/* Measured: 620/624 bytes, 40 resolved relocations and 4 zero alignment bytes. */
// Allocates a ribbon track: count * 2 + 0x1C bytes, with ribbon and cap geometry and per-sample colours.
// FUN_00493E60
/* measured: toggle removal and direct indexed material loads both differ by 213 normalized bytes. */
#pragma push
#pragma opt_propagation off
u8 *TrackAllocRibbons(u16 count, u16 segments) {
    /* Keep ribbon/table/material byte accesses: typed ribbon fields changed b210 codegen (normalized_diff 295); alpha 0xFF is reserved. */
    s32 size;
    u8 *ribbons;
    EffTrackRibbons *allocation;
    EffGeometryMultiPart *ribbonGeometry;
    EffGeometryMultiPart *capGeometry;
    u16 ribbonCount;
    u32 ribbonIndex;
    s32 materialOffset;
    u16 *geometry;
    u16 *ribbon;
    u16 *cap;
    u8 *ribbonMaterial;
    s32 reservedAlpha;
    s32 opaqueAlpha;
    u8 *capMaterial;

    if ((u16)segments < 2) {
        kAssertFail(&D_00713E30, 0x205);
    }
    ribbonCount = count & 0xFFFF;
    size = (ribbonCount * 2) + 0x1C;
    chkmemAllocSiteTag(&D_00713E30, 0x20A);
    ribbons = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    allocation = (EffTrackRibbons *)ribbons;
    if (ribbons == NULL) {
        kAssertFail(&D_00713E30, 0x20B);
    }
    memset(ribbons, 0, size);
    allocation->counts = ribbons + 0x1C;
    geometry = (u16 *)GeometryCreateStripGridMultiPart(count, segments, (void *)D_00713310, 3, 0x48);
    allocation->ribbon = geometry;
    *geometry &= 0xFFFB;
    geometry = (u16 *)GeometryCreateTableGridMultiPart(count, 1, 6, 8, (void *)D_00713420, 0x48);
    allocation->cap = geometry;
    *geometry = *geometry & (u16)0xFFFB;
    ribbonIndex = 0;
    reservedAlpha = 0xFF;
    opaqueAlpha = 0xFE;
    for (; ribbonIndex < ribbonCount; ribbonIndex += 1) {
        ribbon = allocation->ribbon;
        ribbonGeometry = (EffGeometryMultiPart *)ribbon;
        if (iGpffffbb64.c3 != reservedAlpha) {
            materialOffset = (u16)ribbonIndex * 4;
            ribbonMaterial = ribbonGeometry->materials + materialOffset;
            ribbonMaterial = *(u8 **)ribbonMaterial;
            *(LineNovaColor *)&((RpMaterial *)ribbonMaterial)->color = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = opaqueAlpha;
            materialOffset = (u16)ribbonIndex * 4;
            ribbonMaterial = ribbonGeometry->materials + materialOffset;
            ribbonMaterial = *(u8 **)ribbonMaterial;
            *(LineNovaColor *)&((RpMaterial *)ribbonMaterial)->color = iGpffffbb64;
            iGpffffbb64.c3 = reservedAlpha;
        }
        cap = allocation->cap;
        capGeometry = (EffGeometryMultiPart *)cap;
        if (iGpffffbb64.c3 != reservedAlpha) {
            capMaterial = capGeometry->materials + materialOffset;
            capMaterial = *(u8 **)capMaterial;
            *(LineNovaColor *)&((RpMaterial *)capMaterial)->color = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = opaqueAlpha;
            capMaterial = capGeometry->materials + materialOffset;
            capMaterial = *(u8 **)capMaterial;
            *(LineNovaColor *)&((RpMaterial *)capMaterial)->color = iGpffffbb64;
            iGpffffbb64.c3 = reservedAlpha;
        }
    }
    return ribbons;
}
#pragma pop

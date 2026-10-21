#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
#include "sway_particle_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct EffRandState EffRandState;
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void kAssertFail(const void *file, s32 line);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;


#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: retail schedule needs value propagation off and loop-invariant constants hoisted. */
#pragma push
#pragma pop
/* Allocate the emitter header, primary/trail samples, two parameter copies and kind-specific state. */
// FUN_00492B20
u8 *mdlEffectAllocateTrackPath(u16 kind, s32 primaryCount, u8 *parameters)
{
    u8 *emitter;
    u8 *cursor;
    s32 totalCount;
    s32 sampleBytes;
    s32 allocationBytes;
    s32 parameterBytes;
    MdlEffectEmitter *track;

    if ((kind & 0xFFFF) >= 0xC) {
        kAssertFail(D_00713E10, 0xD66);
    }
    totalCount = primaryCount * (((MdlEffectEmitterParameters *)parameters)->trailWidth * ((MdlEffectEmitterParameters *)parameters)->trailCount.signedValue + 1);
    sampleBytes = totalCount << 5;
    allocationBytes = primaryCount * D_00713D58[(kind & 0xFFFF) * 4];
    parameterBytes = D_00713D5C[(kind & 0xFFFF) * 4];
    allocationBytes += sampleBytes + 0x30;
    allocationBytes += parameterBytes * 2;
    chkmemAllocSiteTag(D_00713E10, 0xD73);
    emitter = (u8 *)jtbl_008873E8[0](allocationBytes, 0x40000);
    if (emitter == NULL) {
        kAssertFail(D_00713E10, 0xD74);
    }
    track = (MdlEffectEmitter *)emitter;
    cursor = emitter + 0x30;
    ((MdlEffectEmitter *)emitter)->particles = cursor;
    cursor += sampleBytes;
    track->parameters = cursor;
    cursor += parameterBytes;
    ((MdlEffectEmitter *)emitter)->originalParameters = cursor;
    cursor += parameterBytes;
    ((MdlEffectEmitter *)emitter)->state.bytes = cursor;
    ((MdlEffectEmitter *)emitter)->kind = kind;
    ((MdlEffectEmitter *)emitter)->primaryCount.signedValue = primaryCount;
    ((MdlEffectEmitter *)emitter)->totalCount = totalCount;
    track->flags = 0;
    ((MdlEffectEmitter *)emitter)->ticks = 0;
    track->emissionAccumulator = 0.0f;
    ((MdlEffectEmitter *)emitter)->allocation = emitter;
    memcpy(track->parameters, parameters, parameterBytes);
    memcpy(track->originalParameters, parameters, parameterBytes);
    cursor = ((MdlEffectEmitter *)emitter)->parameters;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(cursor) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(cursor) : "memory");
    if (((MdlEffectEmitterParameters *)cursor)->unkBC != 0) {
        track->flags |= 1;
    }
    return emitter;
}


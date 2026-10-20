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

static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0049; members 00492b20-00492b20 */

#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: b210 -O2 needs independent value propagation and loop-invariant
 * constant materialization for the retail register and instruction schedule. */
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
    cursor = emitter + 0x30;
    ((MdlEffectEmitter *)emitter)->particles = cursor;
    cursor += sampleBytes;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    *(u8 **)(emitter + 0x20) = cursor;
    cursor += parameterBytes;
    ((MdlEffectEmitter *)emitter)->originalParameters = cursor;
    cursor += parameterBytes;
    ((MdlEffectEmitter *)emitter)->state.bytes = cursor;
    ((MdlEffectEmitter *)emitter)->kind = kind;
    ((MdlEffectEmitter *)emitter)->primaryCount.signedValue = primaryCount;
    ((MdlEffectEmitter *)emitter)->totalCount = totalCount;
    /* Header initialization retains the original integer-word representation of the flags, accumulator or allocation pointer. */
    *(s32 *)(emitter + 0x0C) = 0;
    ((MdlEffectEmitter *)emitter)->ticks = 0;
    /* Header initialization retains the original integer-word representation of the flags, accumulator or allocation pointer. */
    *(s32 *)(emitter + 0x14) = 0;
    ((MdlEffectEmitter *)emitter)->allocation = emitter;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    memcpy(*(void **)(emitter + 0x20), parameters, parameterBytes);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    memcpy(*(void **)(emitter + 0x24), parameters, parameterBytes);
    cursor = ((MdlEffectEmitter *)emitter)->parameters;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(cursor) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(cursor) : "memory");
    if (((MdlEffectEmitterParameters *)cursor)->unkBC != 0) {
        /* Header initialization retains the original integer-word representation of the flags, accumulator or allocation pointer. */
        *(s32 *)(emitter + 0x0C) |= 1;
    }
    return emitter;
}


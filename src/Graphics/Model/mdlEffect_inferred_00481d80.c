#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
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

extern void mdlEffectSelectResourceEntry(u8 *player, s32 entryIndex);
extern u8 *mdlEffectLoadTrackResource(s32 *source);
extern void chkmemAllocSiteTag(const void *file, s32 line);
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
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00481d80-00481e30 */

extern void mdlEffectSelectResourceEntry(u8 *player, s32 entryIndex);
extern u8 *mdlEffectLoadTrackResource(s32 *source);
/* Resolves a track resource, allocates its 0x14-byte track states, and initializes playback. */
/* Resolves a track resource and allocates initialized playback states with a 0x14-byte stride. */
// FUN_00481D80
u8 *mdlEffectCreateTrackInstance(s32 source) {
    s32 allocationSize;
    u8 *instance;
    u8 *tracks;

    tracks = NULL;
    if (source != 0) {
        tracks = mdlEffectLoadTrackResource((s32 *)(u32)source);
    }
    allocationSize = (((MdlEffectTrackResource *)tracks)->trackCount * 0x14) + 0x18;
    chkmemAllocSiteTag(D_007132F0, 0x72);
    instance = (u8 *)jtbl_008873E8[0](allocationSize, 0x40000);
    ((MdlEffectTrackInstance *)instance)->resource = (MdlEffectTrackResource *)tracks;
    ((MdlEffectTrackInstance *)instance)->tracks = (MdlEffectTrack *)(instance + 0x18);
    mdlEffectSelectResourceEntry(instance, 0);
    ((MdlEffectTrackInstance *)instance)->active = 1;
    return instance;
}

/* Shares the source track resource and creates an independently initialized playback instance. */
/* Increments the shared track resource reference count and allocates independent playback state. */
// FUN_00481E30
u8 *mdlEffectShareTrackInstance(u8 **source) {
    s32 allocationSize;
    u8 *tracks;
    u8 *instance;

    tracks = *source;
    ((MdlEffectTrackResource *)tracks)->references = ((MdlEffectTrackResource *)tracks)->references + 1;
    allocationSize = (((MdlEffectTrackResource *)tracks)->trackCount * 0x14) + 0x18;
    chkmemAllocSiteTag(D_007132F0, 0x8E);
    instance = (u8 *)jtbl_008873E8[0](allocationSize, 0x40000);
    ((MdlEffectTrackInstance *)instance)->resource = (MdlEffectTrackResource *)tracks;
    ((MdlEffectTrackInstance *)instance)->tracks = (MdlEffectTrack *)(instance + 0x18);
    mdlEffectSelectResourceEntry(instance, 0);
    ((MdlEffectTrackInstance *)instance)->active = 1;
    return instance;
}


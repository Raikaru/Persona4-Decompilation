#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void (*D_00713E70[])(u8 *object);
extern void (*D_00713E78[])(u8 *object);
extern void (*D_00713E7C[])(u8 *object);
extern void (*D_00713E80[])(u8 *object);
extern void (*D_00713F18[])(void *state);
extern void (*D_00713F10[])(u8 *object);
extern void (*D_00713F1C[])(u8 *object);
extern void (*D_00713F20[])(u8 *object);
extern void (*D_00713D54[])(u8 *emitter, f32 scale);
typedef struct EffRandState EffRandState;
extern u32 effMiscRand(EffRandState *state);
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void chkmemAllocSiteTag(const void *msg, s32 id);
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

extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

extern void func_004841c0(u8 *arg0);
extern void mdlEffectCopyCameraOrigin(u8 *arg0);

extern void func_00484280(u8 *object, s32 resource);



#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop




#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
#pragma pop



/* Expand the stored halfword index separately at each primitive lookup. */
static inline u32 track_index(u16 value)
{
    return value;
}
#pragma push
#pragma opt_loop_invariants on
/* The geometry contains left/center/right rows of three 12-byte vertices. */
typedef struct TrackVertex
{
    f32 x, y, z;
} TrackVertex;

#pragma pop


/* measured: the sibling 0049b470 body matches this routine's control-flow and
   call sequence; target entries are 0x18 bytes, so the fill stride is six words. */
#pragma opt_loop_invariants on
// FUN_0049A810
void func_0049a810(u8 *arg0)
{
    extern void func_003c22f0(void *);
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    memset((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
/* measured: closes the opt_loop_invariants scope for 0049a810 at the file baseline. */
#pragma opt_loop_invariants off

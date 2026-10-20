/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0049a810-0049a810 */

#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_drawable_internal.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_common_subs on
/* Clear wind geometry vertices and mark each six-word entry inactive before rebuilding. */
/* measured: dedicated typed aliases preserve the retail reload schedule where access-site-only typing does not. */
// FUN_0049A810
void mdlEffectWindClearGeometry(u8 *instance)
{
    EffGeometryBlock *workFields;
    extern void func_003c22f0(void *);
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((MdlEffectVectorInstance *)instance)->child;
    entry = (s32 *)((MdlEffectWindWork *)state)->entries;
    work = ((MdlEffectWindWork *)state)->geometry;
    workFields = (EffGeometryBlock *)(work);
    count = (s32)((MdlEffectWindParameters *)((MdlEffectVectorInstance *)instance)->parameters)->meshCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)(work))->atomic)->geometry, 2);
    tex = (s32 **)((RpAtomic *)workFields->atomic)->geometry->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    model = (u8 *)((RpAtomic *)workFields->atomic)->geometry;
    func_003c22f0(model);
    if (((EffGeometryBlock *)work)->kind & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
#pragma pop

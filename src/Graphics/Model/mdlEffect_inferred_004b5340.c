#include "member_access.h"
#include "mdl_effect_dispatch_internal.h"
#include "mdl_effect_drawable_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* func_004bd628, func_004bd640, func_004bd658, func_004bd670, func_004bd688 and func_004bd6a0 are
 * framed tail-jump wrappers that plain C cannot emit. */


extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *instance, s32 value);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 instance, u32 value);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

#pragma push
#pragma pop
#pragma push
#pragma pop
// Destroys a battle effect record: if the gate passes, calls the kind's handler-table callback with
// the value at +0x30, then frees the record. The table address is built through two locals because
// retail adds the sub-table offset first, then the 0x1C-strided index.
// FUN_004B5340
void EffBattleDestroy(u8 *instance) {
    s32 tbl;
    s32 idx;
    void (*fn)(s32);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 8;
        idx = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        fn = *(void (**)(s32))(tbl + idx);
        if (fn != NULL) {
            fn(((MdlEffectBattleInstance *)instance)->work);
        }
    }
    jtbl_008873EC[0](instance);
}

// Creates a battle effect from a record's kind and texture; if the kind has no fromRecord handler,
// allocates work and runs the setup and post callbacks when the gate passes.
// FUN_004B53C0
void *EffBattleCreateFromRecord(void *opaqueSource)
{
    u8 *instance = opaqueSource;
    u8 *result;
    u8 *work;
    s32 base;
    s32 id;
    s32 off;
    s32 tex;
    s32 (*setup4)(s32, s32, s32, s32);
    void (*post)(u8 *);
    extern u8 *EffBattleAllocWork();

    id = MEMBER(s32, instance, MdlEffectBattleInstance, kind);
    base = (s32)iGpffffbba0;
    off = (base, id * 0x1C);
    /* The handler entry is byte-indexed by the selected runtime table; its record-specific callback type is not uniform. */
    if (((MdlEffectKindHandlers *)(off + base))->fromRecord.value == 0) {
        tex = ((MdlEffectBattleInstance *)instance)->resource;
        off = id & 0xFFFF;
        work = EffBattleAllocWork(off, tex);
        if (iGpffffbba4() != 0) {
            off = (off & 0xFFFF) * 0x1C;
            base = (s32)iGpffffbba0;
            base += 4;
            base += off;
            setup4 = *(s32 (**)(s32, s32, s32, s32))base;
            if (setup4 != NULL) {
                ((MdlEffectBattleInstance *)work)->work = setup4(tex, 0, 0, 0);
            }
            base = (s32)iGpffffbba0;
            base += off;
            post = *(void (**)(u8 *))base;
            if (post != NULL) {
                post(work);
            }
        }
        result = work;
    } else {
        work = EffBattleAllocWork((id = id & 0xFFFF),
                             (id, ((MdlEffectBattleInstance *)instance)->resource));
        {
            s32 idx2;
            idx2 = MEMBER(s32, instance, MdlEffectBattleInstance, kind) * 0x1C;
            ((MdlEffectBattleInstance *)work)->work =
                (*(s32 (**)(u8 *))((u8 *)(idx2 + (s32)iGpffffbba0 + 0xC)))(instance);
        }
        off = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        base = (s32)iGpffffbba0;
        post = *(void (**)(u8 *))(base + off);
        if (post != NULL) {
            post(work);
        }
        result = work;
    }
    return result;
}

/* Run the kind stop callback when enabled and reset the instance age. */
// FUN_004B5530
void mdlEffectInstanceStop(u8 *instance) {
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        fn = *(void (**)(u8 *))(iGpffffbba0 + 0 + ((MdlEffectBattleInstance *)instance)->kind * 0x1C);
        if (fn != NULL) {
            fn(instance);
        }
        ((MdlEffectBattleInstance *)instance)->age = 0;
    }
}

/* Run the kind advance callback when enabled, then increment the instance age. */
// FUN_004B55A0
/* The handler-table address is built through two locals because retail adds the sub-table offset,
 * then the 0x1C-strided index, then loads at displacement 0. */
void mdlEffectInstanceAdvance(u8 *instance) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x10;
        idx = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(instance);
        }
        ((MdlEffectBattleInstance *)instance)->age += 1;
    }
}

/* Run the kind update callback when the handler gate is enabled. */
// FUN_004B5620
/* The handler-table address is built through two locals because retail adds the sub-table offset,
 * then the 0x1C-strided index, then loads at displacement 0. */
void mdlEffectInstanceUpdate(u8 *instance) {
    s32 tbl;
    s32 idx;
    void (*fn)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl = (s32)iGpffffbba0 + 0x14;
        idx = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        fn = *(void (**)(u8 *))(tbl + idx);
        if (fn != NULL) {
            fn(instance);
        }
    }
}

/* Advance and update the instance, checking the handler gate independently for each pass. */
// FUN_004B5690
void mdlEffectInstanceAdvanceAndUpdate(u8 *instance)
{
    s32 tbl1;
    s32 idx1;
    void (*fn1)(u8 *);
    s32 tbl2;
    s32 idx2;
    void (*fn2)(u8 *);

    if (iGpffffbba4() != 0) {
        tbl1 = (s32)iGpffffbba0 + 0x10;
        idx1 = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        fn1 = *(void (**)(u8 *))(tbl1 + idx1);
        if (fn1 != NULL) {
            fn1(instance);
        }
        ((MdlEffectBattleInstance *)instance)->age += 1;
    }
    if (iGpffffbba4() != 0) {
        tbl2 = (s32)iGpffffbba0 + 0x14;
        idx2 = ((MdlEffectBattleInstance *)instance)->kind * 0x1C;
        fn2 = *(void (**)(u8 *))(tbl2 + idx2);
        if (fn2 != NULL) {
            fn2(instance);
        }
    }
}


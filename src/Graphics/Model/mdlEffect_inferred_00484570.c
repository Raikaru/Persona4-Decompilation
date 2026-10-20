#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
#include "mdl_effect_resource_internal.h"
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

extern void mdlEffectReleasePrimarySource(u8 *instance);
extern void mdlEffectReleaseSecondarySource(u8 *instance);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
typedef struct MdlEffectConstructorSlot {
    EffectInstanceConstructor create;
    u8 pad4[0x3C];
} MdlEffectConstructorSlot;
typedef struct MdlEffectReleaseSlot {
    s32 (*release)(s32);
    u8 pad4[0x3C];
} MdlEffectReleaseSlot;
extern MdlEffectConstructorSlot D_00713480[];
extern u8 D_00713494[];
extern MdlEffectReleaseSlot D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484570-004846d0 */

extern void mdlEffectReleasePrimarySource(u8 *instance);
extern void mdlEffectReleaseSecondarySource(u8 *instance);
/* Allocate a primitive record and construct its kind-specific payload. */
// FUN_00484570
u8 *mdlEffectCreatePrimitiveRecord(u8 *source)
{
    u32 tag;
    u16 kind;
    u8 *record;
    MdlEffectPrimitiveRecord *primitive;

    tag = ((MdlEffectPrimitiveRecord *)source)->tag.value;
    if (tag <= 0xD2U) {
        goto code1_0048_84570_after_check;
    } else {
        kAssertFail(D_00713470, 0x2D7);
    }
code1_0048_84570_after_check:
    kind = ((MdlEffectPrimitiveRecord *)source)->kind;
    chkmemAllocSiteTag(D_00713470, 0x21);
    record = jtbl_008873E8[0](0x2C, 0x40000);
    if (record == NULL) {
        kAssertFail(D_00713470, 0x22);
    }
    memset(record, 0, 0x2C);
    primitive = (MdlEffectPrimitiveRecord *)record;
    ((MdlEffectPrimitiveRecord *)record)->tag.signedValue = 0xD2;
    primitive->kind = kind;
    ((MdlEffectPrimitiveRecord *)record)->id = ((MdlEffectPrimitiveRecord *)source)->id;
    ((MdlEffectPrimitiveRecord *)record)->sourceKind = ((MdlEffectPrimitiveRecord *)source)->sourceKind;
    if (primitive->kind >= 0x21U) {
        kAssertFail(D_00713470, 0x2DD);
    }
    if (D_00713480[primitive->kind].create == NULL) {
        kAssertFail(D_00713470, 0x2DE);
    }
    ((MdlEffectPrimitiveRecord *)record)->instance.pointer =
        D_00713480[((MdlEffectPrimitiveRecord *)record)->kind].create(
            source);
    return record;
}

/* Destroy the kind-specific payload, release source sections and free the record. */
// FUN_004846D0
void mdlEffectDestroyPrimitiveRecord(u8 *recordData) {
    s32 (*releaseCallback)(s32);
    u8 *record;
    MdlEffectPrimitiveRecord *primitive;

    record = recordData;
    primitive = (MdlEffectPrimitiveRecord *)record;
    if (primitive->instance.handle != 0) {
        releaseCallback = D_00713490[primitive->kind].release;
        if (releaseCallback == NULL) {
            kAssertFail(D_00713470, 0x2EB);
        }
        code1_0048_call(
            D_00713490[((MdlEffectPrimitiveRecord *)record)->kind].release,
            ((MdlEffectPrimitiveRecord *)record)->instance.handle);
    }
    mdlEffectReleasePrimarySource(record);
    mdlEffectReleaseSecondarySource(record);
    (*jtbl_008873EC)(record);
}












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

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
/* Each linker alias starts at its callback column in a 0x40-byte kind row. */
typedef struct MdlEffectChildConstructorSlot {
    EffectInstanceConstructor create;
    u8 pad4[0x3C];
} MdlEffectChildConstructorSlot;
typedef struct MdlEffectChildCallbackSlot {
    void (*callback)(s32);
    u8 pad4[0x3C];
} MdlEffectChildCallbackSlot;
typedef struct MdlEffectChildDataSlot {
    void (*callback)(s32, void *);
    u8 pad4[0x3C];
} MdlEffectChildDataSlot;
typedef struct MdlEffectChildScaleSlot {
    void (*callback)(s32, f32);
    u8 pad4[0x3C];
} MdlEffectChildScaleSlot;
typedef struct MdlEffectChildColorSlot {
    void (*callback)(s32, s32);
    u8 pad4[0x3C];
} MdlEffectChildColorSlot;
extern MdlEffectChildCallbackSlot D_00713488[];
extern MdlEffectChildCallbackSlot D_0071348C[];
extern u8 D_00713480[];
extern MdlEffectChildConstructorSlot D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
extern MdlEffectChildCallbackSlot D_0071349C[];
extern MdlEffectChildDataSlot D_007134A0[];
extern MdlEffectChildScaleSlot D_007134A8[];
extern MdlEffectChildColorSlot D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484830-00484ae0 */

/* Clone a primitive payload through its kind-specific child constructor. */
// FUN_00484830
u8 *mdlEffectCreateChildRecord(u8 *record)
{
    u32 tag;
    u16 kind;
    u8 *child;
    MdlEffectPrimitiveRecord *primitive;
    tag = ((MdlEffectPrimitiveRecord *)record)->tag.value;
    if (tag <= 0xD2U) {
        goto code1_0048_after_check;
    } else {
        kAssertFail(D_00713470, 0x318);
    }
code1_0048_after_check:
    kind = ((MdlEffectPrimitiveRecord *)record)->kind;
    chkmemAllocSiteTag(D_00713470, 0x21);
    child = jtbl_008873E8[0](0x2C, 0x40000);
    if (child == NULL) {
        kAssertFail(D_00713470, 0x22);
    }
    memset(child, 0, 0x2C);
    primitive = (MdlEffectPrimitiveRecord *)child;
    ((MdlEffectPrimitiveRecord *)child)->tag.signedValue = 0xD2;
    primitive->kind = kind;
    ((MdlEffectPrimitiveRecord *)child)->id = ((MdlEffectPrimitiveRecord *)record)->id;
    ((MdlEffectPrimitiveRecord *)child)->sourceKind = ((MdlEffectPrimitiveRecord *)record)->sourceKind;
    if (D_00713494[primitive->kind].create == NULL) {
        kAssertFail(D_00713470, 0x321);
    }
    ((MdlEffectPrimitiveRecord *)child)->instance.pointer =
        D_00713494[((MdlEffectPrimitiveRecord *)child)->kind].create(
            ((MdlEffectPrimitiveRecord *)record)->instance.pointer);
    return child;
}

/* Invoke the optional start callback for this primitive kind. */
// FUN_00484970
void mdlEffectStartChild(u8 *record) {
    void (*fn)(s32) = D_0071349C[((MdlEffectPrimitiveRecord *)record)->kind].callback;

    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
    }
}

/* Commit the primitive through its required kind callback. */
// FUN_004849C0
void mdlEffectCommitChild(u8 *record)
{
    void (*fn)(s32) = D_00713488[((MdlEffectPrimitiveRecord *)record)->kind].callback;
    fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
}

/* Flush the primitive through its required kind callback. */
// FUN_00484A00
void mdlEffectFlushChild(u8 *record)
{
    void (*fn)(s32) = D_0071348C[((MdlEffectPrimitiveRecord *)record)->kind].callback;
    fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
}

/* Forward data to the primitive's optional update callback. */
// FUN_00484A40
void mdlEffectUpdateChildData(u8 *record, void *data) {
    void (*fn)(s32, void *) = D_007134A0[((MdlEffectPrimitiveRecord *)record)->kind].callback;
    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, data);
    }
}

/* Forward a scalar to the primitive's optional scale callback. */
// FUN_00484A90
void mdlEffectScaleChild(u8 *record, f32 scale) {
    void (*fn)(s32, f32) = D_007134A8[((MdlEffectPrimitiveRecord *)record)->kind].callback;

    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, scale);
    }
}

/* Forward packed color to the primitive's optional color callback. */
// FUN_00484AE0
void mdlEffectSetChildColor(u8 *record, s32 packedColor) {
    void (*fn)(s32, s32) = D_007134B0[((MdlEffectPrimitiveRecord *)record)->kind].callback;
    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, packedColor);
    }
}













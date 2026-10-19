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

extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484830-00484ae0 */

/* Clone a primitive payload through its kind-specific child constructor. */
// FUN_00484830
u8 *mdlEffectCreateChildRecord(u8 *record)
{
    u32 tag;
    u16 kind;
    u8 *child;
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
    ((MdlEffectPrimitiveRecord *)child)->tag.signedValue = 0xD2;
    *(u16 *)(child + 4) = kind; /* measured: typing this field access changes MATCH to MISMATCH under b210. */
    ((MdlEffectPrimitiveRecord *)child)->id = ((MdlEffectPrimitiveRecord *)record)->id;
    ((MdlEffectPrimitiveRecord *)child)->sourceKind = ((MdlEffectPrimitiveRecord *)record)->sourceKind;
    if (*(EffectInstanceConstructor *)(D_00713494 + (*(u16 *)(child + 4) << 6)) == NULL) { /* measured: byte-based kind reloads preserve MATCH across table dispatch. */
        kAssertFail(D_00713470, 0x321);
    }
    ((MdlEffectPrimitiveRecord *)child)->instance.pointer =
        (*(EffectInstanceConstructor *)(D_00713494 + (((MdlEffectPrimitiveRecord *)child)->kind << 6)))( /* The 0x40-byte kind table has slot-specific callback signatures. */
            ((MdlEffectPrimitiveRecord *)record)->instance.pointer);
    return child;
}

/* Invoke the optional start callback for this primitive kind. */
// FUN_00484970
void mdlEffectStartChild(u8 *record) {
    void (*fn)(s32) = *(void (**)(s32))(D_0071349C + (((MdlEffectPrimitiveRecord *)record)->kind << 6));

    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
    }
}

/* Commit the primitive through its required kind callback. */
// FUN_004849C0
void mdlEffectCommitChild(u8 *record)
{
    void (*fn)(s32) = *(void (**)(s32))(D_00713488 + (((MdlEffectPrimitiveRecord *)record)->kind << 6));
    fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
}

/* Flush the primitive through its required kind callback. */
// FUN_00484A00
void mdlEffectFlushChild(u8 *record)
{
    void (*fn)(s32) = *(void (**)(s32))(D_0071348C + (((MdlEffectPrimitiveRecord *)record)->kind << 6));
    fn(((MdlEffectPrimitiveRecord *)record)->instance.handle);
}

/* Forward data to the primitive's optional update callback. */
// FUN_00484A40
void mdlEffectUpdateChildData(u8 *record, void *data) {
    void (*fn)(s32, void *) = *(void (**)(s32, void *))(D_007134A0 + (((MdlEffectPrimitiveRecord *)record)->kind << 6));
    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, data);
    }
}

/* Forward a scalar to the primitive's optional scale callback. */
// FUN_00484A90
void mdlEffectScaleChild(u8 *record, f32 scale) {
    void (*fn)(s32, f32) = *(void (**)(s32, f32))(D_007134A8 + (((MdlEffectPrimitiveRecord *)record)->kind << 6));

    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, scale);
    }
}

/* Forward packed color to the primitive's optional color callback. */
// FUN_00484AE0
void mdlEffectSetChildColor(u8 *record, s32 packedColor) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (((MdlEffectPrimitiveRecord *)record)->kind << 6));
    if (fn != NULL) {
        fn(((MdlEffectPrimitiveRecord *)record)->instance.handle, packedColor);
    }
}













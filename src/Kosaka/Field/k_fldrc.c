/* Source unit: src/Kosaka/Field/k_fldrc.c */
#include "type.h"
#include "Kosaka/k_clump_internal.h"

/*
 * Retail reaches the "%03d" / "_%03d" / ".rws" fragments of its field-path
 * format table through gp-relative addiu with the offset folded in as an
 * addend.  These dummy externs are anchored at the GP base (0x007690f0) so
 * the pointer-minus-offset expressions below materialize the string
 * addresses (0x00762ee8 / 0x00762ef0 / 0x00762ef8) exactly like the donor
 * P3 unit (gp0xffff9538 at the P3 GP base, minus 0x6ac8).
 */
extern u32 gp0xffff9df8;
extern u32 gp0xffff9e00;
extern u32 gp0xffff9e08;
extern s32 iGpffffb204;
extern char D_005efcc0[];
extern char D_005efcd0[];
extern u32 sprintf();
extern u32 strcat();
extern void* FldResource_Create(char* path);
extern void func_003c21e0();
extern void func_003ca270(void *object, void *callback, void *userdata);
extern s32 kwlnTaskDestroyWithHierarchy(void *object);
extern u8 *K_ClumpMatColorScale(u8 *arg0, u8 *arg1);
extern u8 *K_ClumpMatPropScale(u8 *material, u8 *data);
struct RpGeometry;
/* RpAtomic prefix: geometry is the pointer at 0x18 consumed by the material iterator. */
typedef struct FldRcAtomic {
    u8 pad00[0x18];
    struct RpGeometry *geometry;
} FldRcAtomic;
struct RpMaterial;
extern struct RpMaterial *FldRcMaterialSetMipmapTex(struct RpMaterial *material, void *data);
extern u8 *iGpffffb590;
extern void *RpClumpForAllAtomics(void *object, KClumpCallback callback, void *data);



/* Build the field resource path from the current root and the two numeric IDs. */
// FUN_00150890
void* FldRc_CreateResource(s16 majorId, s16 minorId)
{
    char path[40];
    char token[8];

    if (iGpffffb204 == 0)
    {
        strcpy(path, D_005efcc0);
    }
    else
    {
        strcpy(path, D_005efcd0);
    }
    sprintf(token, (const char*)&gp0xffff9df8 - 0x6208, majorId);
    strcat(path, token);
    sprintf(token, (const char*)&gp0xffff9e00 - 0x6200, minorId);
    strcat(path, token);
    strcat(path, (const char*)&gp0xffff9e08 - 0x61f8);
    return FldResource_Create(path);
}
/* Visit every material in the atomic geometry and assign its mipmap texture. */
// FUN_0018C680
void *FldRc_ReplaceGeometryTextures(void *object, void *data)
{
    u8 *atomic = object;
    func_003c21e0(((FldRcAtomic *)atomic)->geometry, FldRcMaterialSetMipmapTex, data);
    return object;
}
/* Destroy the cached field-resource task and clear its cache pointer. */
// FUN_002E7870
void FldRc_ReleaseCachedObject(void) {
    u8 *g = iGpffffb590;

    if (g != NULL) {
        kwlnTaskDestroyWithHierarchy(g);
        iGpffffb590 = NULL;
    }
}
/* Measured callback-wrapper idiom: preserve the object in s0, move userdata to a2, and call the shared iterator with the object field and callback. */
// FUN_00458C40
void *FldRc_ScaleGeometryColors(void *object, void *scale)
{
    u8 *atomic = object;
    func_003c21e0((s32)((FldRcAtomic *)atomic)->geometry, K_ClumpMatColorScale, scale);
    return object;
}
// FUN_00458C80
void FldRc_ScaleClumpColors(void *object, void *scale)
{
    RpClumpForAllAtomics(object, FldRc_ScaleGeometryColors, scale);
}
// FUN_00458CB0
void FldRc_ScaleObjectColors(void *object, void *scale)
{
    func_003ca270(object, K_ClumpMatColorScale, scale);
}
/* Apply the supplied material-property vector to every material in the atomic geometry. */
// FUN_00458F00
void *FldRc_SetGeometryVector(void *object, void *scale)
{
    u8 *atomic = object;
    func_003c21e0((s32)((FldRcAtomic *)atomic)->geometry, K_ClumpMatPropScale, scale);
    return object;
}
// FUN_00458F40
void FldRc_SetClumpVector(void *object, void *scale)
{
    RpClumpForAllAtomics(object, FldRc_SetGeometryVector, scale);
}
// FUN_00458F70
void FldRc_SetObjectVector(void *object, void *scale)
{
    func_003ca270(object, K_ClumpMatPropScale, scale);
}

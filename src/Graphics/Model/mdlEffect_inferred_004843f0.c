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

// Layout from P3FES RenderWare rwplcore.h.
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

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_003c42b0(void *geometry, s32 stream);
extern s32 TnUploadStreamTagged(s32 stream);
extern void func_003ef3a0(void *geometry);
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

/* Upload a texture stream, assign it to every material, then drop the upload reference. */
// FUN_004843F0
void mdlEffectUploadGeometryTexture(u8 *geometry, s32 stream) {
    u16 materialIndex;
    s32 texture;
    u16 index;

    texture = TnUploadStreamTagged(stream);
    materialIndex = 0;
    goto loop_004843f0_check;
loop_004843f0_body:
    index = (u16)materialIndex;
    func_003c42b0(
        ((void **)((MdlEffectMultipartGeometry *)geometry)->materials)[index],
        texture);
    materialIndex += 1;
loop_004843f0_check:
    if ((u16)materialIndex < ((MdlEffectMultipartGeometry *)geometry)->partCount.signedValue) {
        goto loop_004843f0_body;
    }
    func_003ef3a0((void *)texture);
}



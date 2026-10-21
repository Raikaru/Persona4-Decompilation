#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"


extern u8 *D_007246AC;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void btlShuffleInitWaveStrips(u8 *drawWork);
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];

extern f32 D_00761470;
extern f32 D_008872F8[];
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y,
                          f32 depth, u8 red, u8 green, u8 blue, u8 alpha,
                          u16 scaleX, u16 scaleY, f32 angle, s16 pivotX,
                          s16 pivotY);

extern void btlShuffleInitWaveStrips(u8 *drawWork);
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
/* D_00761490 holds the retail scalar 0xBD872B00, not the rounded -0.066f literal; the five-frame
 * and 300-frame reloads are retail behaviour. */
#pragma push
#pragma pop
// Allocate an effect header and relocate its string entries into copied string and data blocks.
// FUN_0038F400
extern u8 D_0064F240[];
extern void *memcpy(void *dst, const void *src, u32 size);
EffectStateHeader *edResBuildEffectHeader(const u32 *parameters)
{
    u32 size;
    u32 remainder;
    EffectStateHeader *result;
    u32 cursor;
    u32 string;
    u32 index;
    const u8 *lengths;

    size = sizeof(*result);
    size += parameters[3] * 4;
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += parameters[6];
    remainder = size & 3;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    size += parameters[2];
    chkmemAllocSiteTag(D_0064F240, 0x36);
    cursor = (u32)jtbl_008873E8[0](size, 0x40000);
    result = (EffectStateHeader *)cursor;
    cursor += sizeof(*result);
    result->entries = cursor;
    cursor += parameters[3] * 4;
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->strings = cursor;
    cursor += parameters[6];
    remainder = cursor & 3;
    if (remainder != 0) {
        cursor += 4 - remainder;
    }
    result->data = cursor;
    result->count = (u16)parameters[3];
    result->id = (u16)parameters[0];
    memcpy((void *)result->strings,
                  (const u8 *)parameters + parameters[5], parameters[6]);
    memcpy((void *)result->data,
                  (const u8 *)parameters + parameters[1], parameters[2]);
    lengths = (const u8 *)parameters + parameters[4];
    string = result->strings;
    index = 0;
    while (index < parameters[3]) {
        size = index * 4;
        ((u32 *)result->entries)[index] = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}


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
extern void btlShuffleInitWaveStrips(u8 *arg0);
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);

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
extern void sdkSpriteDrawOnceAt(s32 resource, s32 slot, f32 x, f32 y,
                          u8 r, u8 g, u8 b, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                          f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0,
                          s16 arg_sp8);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

/* Source unit: src/promoted/code1_0038.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0038.c; members 0038f400-0038f400 */

extern void btlShuffleInitWaveStrips(u8 *arg0);
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
/* measured: restore conditional rebuilding after this function. */
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
/* measured: restore loop-invariant optimization after func_00389cb0. */
/* Measured: 904/912 bytes, eleven resolved relocations and eight zero
 * alignment bytes. D_00761490 is the retail scalar 0xBD872B00, not the
 * rounded -0.066f literal; keep the five-frame and 300-frame reloads. */
#pragma push
#pragma pop
// Intent: Build an EffectStateHeader from a parameter table: entry table, string block and data block [inferred]
// FUN_0038F400
extern u8 D_0064F240[];
extern void *memcpy(void *dst, const void *src, u32 size);
/* The entry-table cursor is a byte offset: typed indexing adds a shift under b210 (404/400 bytes), so retain the word store for MATCH. */
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
        *(u32 *)(result->entries + size) = string;
        string += *lengths;
        index += 1;
        lengths += 1;
    }
    return result;
}


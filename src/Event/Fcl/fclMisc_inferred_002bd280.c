#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void kAssertFail(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern u8 *func_002e2170(u8 *arg0, s32 arg1, s32 arg2);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];



extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif










/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002bd280-002bd280 */

extern void func_002b5120(s32 arg0, u8 *arg1);
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_002BD280
s32 func_002bd280(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    s32 temp_20;
    u8 *temp_21;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_21 = (u8 *)iGpffffb57c;
    if (*(s32 *)(temp_21 + 0xC) == 0) {
        kAssertFail(&D_0063F2A0, 0x668);
    }
    temp_20 = *(s32 *)(temp_21 + 0xC);
    temp_4 = *(u8 **)(temp_21 + 0);
    temp_2 = func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0x30);
    temp_3 = *(u8 **)(temp_2 + 0x14);
    *(u8 **)(temp_3 + 0) = temp_2;
    *(s32 *)(temp_3 + 0x2C) = arg0;
    *(s32 *)(temp_3 + 0x20) = arg1;
    *(s32 *)(temp_3 + 0x24) = arg2;
    *(s32 *)(temp_3 + 0x28) = temp_20;
    *(s16 *)(temp_3 + 0xE) = arg3;
    return 0;
}


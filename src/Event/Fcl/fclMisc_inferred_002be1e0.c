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
extern void (*jtbl_008873EC[])(void *);



extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
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
extern s32 func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern u32 func_002e7a60(void);
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

extern FclVec2 fclMakeVec2(f32 x, f32 y);







extern s32 fclDecimalDigitCount(s32 arg0);


/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002be1e0-002be4a0 */

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
// FUN_002BE1E0
s32 func_002be1e0(s32 arg0)
{
    if (arg0 & 1) {
        return 0;
    }
    if (arg0 & 2) {
        return 1;
    }
    if (arg0 & 4) {
        return 2;
    }
    if (arg0 & 8) {
        return 3;
    }
    if (arg0 & 0x10) {
        return 4;
    }
    if (arg0 & 0x20) {
        return 5;
    }
    if (arg0 & 0x40) {
        return 6;
    }
    if (arg0 & 0x80) {
        return 7;
    }
    if (arg0 & 0x100) {
        return 8;
    }
    if (arg0 & 0x200) {
        return 9;
    }
    if (arg0 & 0x400) {
        return 0xA;
    }
    if (arg0 & 0x800) {
        return 0xB;
    }
    if (arg0 & 0x1000) {
        return 0xC;
    }
    if (arg0 & 0x2000) {
        return 0xD;
    }
    if (arg0 & 0x4000) {
        return 0xE;
    }
    if (arg0 & 0x8000) {
        return 0xF;
    }
    if (arg0 & 0x10000) {
        return 0x10;
    }
    if (arg0 & 0x20000) {
        return 0x11;
    }
    if (arg0 & 0x40000) {
        return 0x12;
    }
    return 0;
}

// FUN_002BE3C0
void func_002be3c0(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x7100D);
}

// FUN_002BE4A0
void func_002be4a0(void)
{
    Vec2f sp18;

    sp18 = fclMakeVec2(
                  580.0f - 21.0f * (f32)fclDecimalDigitCount(func_002e7a60()),
                  15.0f);
    func_00364320(sp18, 1.0f, 0xFF, func_002e7a60());
}


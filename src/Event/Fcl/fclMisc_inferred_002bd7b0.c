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
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void fieldSceneUnload(void);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern s32 fieldSceneLoadStep(void);
extern s32 func_0015f660(void);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern s32 func_002cb6a0(s32 arg0);
extern void func_002caa00(s32 arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
extern s32 kwlnTaskGetTaskByName(void *arg0);
extern u8 *func_00457120(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern f32 MT_Scene_GetCameraFov(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002bd7b0-002bdb10 */

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
// FUN_002BD7B0
s32 func_002bd7b0(void)
{
    u8 *p;
    s32 temp_2;

    p = (u8 *)D_00882F60;
    if (p != NULL) {
        *(s32 *)(p + 0) = -1;
        *(s8 *)(p + 4) = 0;
        *(s8 *)(p + 5) = 0;
        *(s32 *)(p + 8) = -1;
        *(s8 *)(p + 0xC) = 1;
        *(s8 *)(p + 0xD) = 1;
    }
    if (*(s32 *)(p + 0) < 0) {
        temp_2 = itfMesWindowInstall();
        *(s32 *)(p + 0) = temp_2;
        itfMesWindowSetStyle(temp_2, 1);
        return 1;
    }
    return 0;
}

// FUN_002BD840
s32 func_002bd840(s32 arg0)
{
    u8 *p;

    p = (u8 *)D_00882F60;
    if (*(s32 *)(p + 0) < 0) {
        return 0;
    }
    itfMesWindowSetStyle(*(s32 *)(p + 0), 1);
    itfMesWindowSetFlagBits(*(s32 *)(p + 0), 0x200000);
    itfMesWindowBindRecord(*(s32 *)(p + 0), arg0, 0);
    *(s8 *)(p + 4) = 1;
    itfMesWindowSetAnim(*(s32 *)(p + 0), -1);
    return 1;
}

// FUN_002BD8E0
s32 func_002bd8e0(u8 *arg0)
{
    s8 temp_3;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s8 *)(temp_16 + 0);
    switch (temp_3) {
    case 1:
        fieldSceneLoad(8, 4);
        *(s8 *)(temp_16 + 0) = 2;
    case 2:
        if ((fieldSceneLoadStep() != 0) && (func_0015f660() != 0)) {
            if (func_002cb6a0(*(s32 *)(temp_16 + 4)) == 0) {
                return 0;
            }
            sdkSndPlayCue(0x15, 1);
            temp_17 = func_00457120();
            K_View_SetFov(temp_17, MT_Scene_GetCameraFov());
            temp_17_2 = func_00457120();
            func_003e9cb0(*(s32 *)(temp_17_2 + 4), (void *)MT_Scene_GetCameraResFirst(), 0);
            *(s8 *)(temp_16 + 0) = 3;
        }
        goto block_26;
    case 3:
        func_00122640(1, 0);
        *(s8 *)(temp_16 + 0) = 4;
    case 4:
        if (func_00122720() != 0) {
            func_002caa00(*(s32 *)(temp_16 + 4), 0xD);
            *(s8 *)(temp_16 + 0) = 7;
        }
        goto block_26;
    case 5:
        func_00122520(1, 0);
        *(s8 *)(temp_16 + 0) = 6;
    case 6:
        if (func_00122720() != 0) {
            *(s8 *)(temp_16 + 0) = 0x11;
        }
        goto block_26;
    case 7:
        if (kwlnTaskGetTaskByName(&D_0063F3B0) == 0) {
            *(s8 *)(temp_16 + 0) = 5;
        }
        goto block_26;
    case 17:
        return -1;
    case 35:
        return -1;
    default:
    block_26:
        return 0;
    }
}

// FUN_002BDB10
void func_002bdb10(u8 *arg0)
{
    fieldSceneUnload();
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}


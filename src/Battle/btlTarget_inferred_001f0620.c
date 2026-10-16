#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u8 *iGpffffb3c4;
extern s32 func_0010f420(s32 arg0, s32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);

extern void memset(void *destination, s32 value, u32 size);


extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];



extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];







extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f0620-001f0a10 */

extern s32 btlActionIsPendingBit(s32 arg0);
#pragma push
/* measured: func_001f0620 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001F0620
s32 func_001f0620(u8 *arg0, s64 arg1)
{
    s32 temp_3_2;
    s64 temp_2;
    u16 temp_6;
    u8 *temp_3;
    u8 *temp_5;

    temp_6 = *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
    if ((temp_6 == 0x215) && ((s16)arg1 != 2)) {
        return 0;
    }
    temp_2 = (s16)arg1;
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return !datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 8);
    case 3:
        return !datGetFlag(0x1438);
    case 4:
        temp_3 = *(u8 **)(arg0 + 0x30);
        if (temp_3[0xA2] != 0) return 0;
        if (*(u16 *)(temp_3 + 0xA4) != 1) return 0;
        if ((func_001ef720(1, 0) & 0xFFFF) < 2) return 0;
        return !datGetFlag(0x1438);
    case 5:
        temp_5 = *(u8 **)(arg0 + 0x30);
        if (temp_5[0xA2] != 0) return 0;
        if (*(u16 *)(temp_5 + 0xA4) != 1) return 0;
        if ((*(u16 *)(arg0 + 0x18) & 0x400) == 0) return 0;
        if (datCalcChkBadStatus(*(s32 *)(temp_5 + 0xA64), 8) != 0) return 0;
        return !datGetFlag(0x1438);
    case 6:
        temp_3_2 = *(s32 *)(iGpffffb414 + ((temp_6 & 0xFFFF) * 0x18));
        if (temp_3_2 & 0x20) return 0;
        if ((temp_3_2 & 1) == 0) return 0;
        return !btlActionIsPendingBit(0);
    case 7:
    case 8:
    case 11:
    case 12:
        return 1;
    case 10:
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) return 0;
        return !datGetFlag(0x1438);
    case 13:
        return 1;
    default:
        return 0;
    }
}

#pragma pop
// FUN_001F08C0
s32 func_001f08c0(u8 *arg0)
{
    u16 temp_2;

    temp_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 0;
    case 4:
        return 0;
    case 6:
        return 0;
    case 7:
        return 1;
    case 8:
        return 1;
    default:
        return 0;
    }
}

// FUN_001F0950
s32 func_001f0950(s32 arg0, s32 arg1)
{
    if (((*(u16 *)(iGpffffb3c4 + ((arg0 & 0xFFFF) * 0x3C)) & 0x4004) == 0) &&
        (datGetFlag(0x1403) != 0)) {
        if (datGetFlag(0x1408) != 0) {
            return 1;
        }
        if (datGetFlag(0x1409) != 0) {
            return 0;
        }
    }
    return func_0010f420(arg0, arg1);
}

// FUN_001F0A10
void func_001f0a10(u8 *arg0) {
    memset(arg0, 0, 0x20);
}


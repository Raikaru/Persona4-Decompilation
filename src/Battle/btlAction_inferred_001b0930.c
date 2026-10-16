#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void memset(void *dst, s32 value, s32 size);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void func_001eb380(u8 *arg0);
extern s64 btlGetUID(void);
extern u32 datCalcRandomBelow(u32 arg0);
extern u32 iGpffffa0b8;
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001b0930-001b0cc0 */

/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
/* Retail allocates the scan as found=v1, base=v0, i=a3. The second scan walks
   a `table` copy of `base`; that copy use keeps `base` a declared local
   instead of folding into its gp load temporary. `found` declared first and
   `base` second give retail's v1/v0 pair. In the owner, the measured
   `opt_common_subs off` keeps the scan's offset and table reloads separate. */
#pragma push
#pragma pop
// FUN_001B0930
u8 *btlActionCreate(void)
{
    u32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    chkmemAllocSiteTag(&D_005F6FE8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x458, 0x40000);
    memset(temp_2, 0, 0x458);
    func_001eb380(temp_2 + 0x38);
    *(s16 *)(temp_2 + 0xE) = 0;
    *(s16 *)(temp_2 + 0x14) = 8;
    *(s64 *)temp_2 = btlGetUID();
    if (iGpffffa0b8 >= 0x0FFFFFFFU) {
        iGpffffa0b8 = 1;
    }
    temp_3 = iGpffffa0b8;
    iGpffffa0b8 = temp_3 + 1;
    *(u32 *)(temp_2 + 8) = temp_3;
    *(s32 *)(temp_2 + 0x24) = -1;
    *(s16 *)(temp_2 + 0x36) = (s16)datCalcRandomBelow(0x3C);
    *(s32 *)(temp_2 + 0x44C) = 0;
    temp_2_2 = *(u8 **)(iGpffffb3ac + 0x174);
    if (temp_2_2 != NULL) {
        *(u8 **)(temp_2_2 + 0x44C) = temp_2;
        *(u8 **)(temp_2 + 0x450) = *(u8 **)(iGpffffb3ac + 0x174);
    } else {
        *(u8 **)(temp_2 + 0x450) = NULL;
    }
    *(u8 **)(iGpffffb3ac + 0x174) = temp_2;
    *(u16 *)(temp_2 + 0x10) = *(u16 *)(temp_2 + 0xC);
    *(u16 *)(temp_2 + 0xC) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0;
    D_005F6E20[0](temp_2);
    return temp_2;
}

/* measured: compound field decrement preserves retail addiu/sh/andi order; normalized_diff 0 in the 400-byte retail window. */
// FUN_001B0A60
void btlActionListUpdate(void)
{
    u8 *var_18;
    u16 temp_3;
    u16 temp_3_3;
    u16 temp_4;
    u8 *temp_17;
    u8 *temp_3_4;
    u8 *temp_3_5;
    s32 var_16;
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    var_18 = *(u8 **)(base + 0x174);
    goto loop_check;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0x450);
    var_16 = 1;
    if (*(u16 *)(var_18 + 0xE) != 0) {
        temp_3 = *(u16 *)(var_18 + 0x12);
        if ((s32)temp_3 > 0) {
            if ((*(u16 *)(var_18 + 0x12) -= 1) != 0) goto decrement_not_zero;
            temp_3_3 = *(u16 *)(var_18 + 0xE);
            *(u16 *)(var_18 + 0x10) = *(u16 *)(var_18 + 0xC);
            *(u16 *)(var_18 + 0xC) = temp_3_3;
            *(s32 *)(var_18 + 0x1C) = 0;
            (*(void (**)(u8 *))((u8 *)D_005F6E20 + temp_3_3 * 0xC))(var_18);
            *(u16 *)(var_18 + 0xE) = 0;
            goto decrement_done;
decrement_not_zero:
            var_16 = 0;
decrement_done:
            ;
        }
    }
    if (var_16 != 0) {
        temp_4 = *(u16 *)(var_18 + 0x1A);
        if ((temp_4 & 4) == 0) {
            if ((*(u16 *)(var_18 + 0x18) & 1) != 0) {
                (*(void (**)(u8 *))((u8 *)D_005F6E20 + *(u16 *)(var_18 + 0xC) * 0xC + 4))(var_18);
                *(s32 *)(var_18 + 0x1C) += 2;
            } else if ((temp_4 & 2) != 0) {
                temp_3_4 = *(u8 **)(var_18 + 0x450);
                if (temp_3_4 != NULL) {
                    *(u8 **)(temp_3_4 + 0x44C) = *(u8 **)(var_18 + 0x44C);
                }
                temp_3_5 = *(u8 **)(var_18 + 0x44C);
                if (temp_3_5 != NULL) {
                    *(u8 **)(temp_3_5 + 0x450) = *(u8 **)(var_18 + 0x450);
                } else {
                    *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_18 + 0x450);
                }
                (*jtbl_008873EC)(var_18);
            }
        }
    }
    var_18 = temp_17;
loop_check:
    if (var_18 != NULL) goto loop_body;
}

// FUN_001B0BF0
void btlActionListDestroyAll(void)
{
    u8 *temp_16;
    u8 *temp_3;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_check;
loop_body:
    temp_16 = *(u8 **)(var_4 + 0x450);
    if (temp_16 != NULL) {
        *(u8 **)(temp_16 + 0x44C) = *(u8 **)(var_4 + 0x44C);
    }
    temp_3 = *(u8 **)(var_4 + 0x44C);
    if (temp_3 != NULL) {
        *(u8 **)(temp_3 + 0x450) = *(u8 **)(var_4 + 0x450);
    } else {
        *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(var_4 + 0x450);
    }
    (*jtbl_008873EC)(var_4);
    var_4 = temp_16;
loop_check:
    if (var_4 != NULL) goto loop_body;
}

/* measured: returning directly from the compare branch preserves retail's
   bne/branch-to-tail layout; the C object is 60B/64B with nd 0 and only the
   retail alignment nop remains. */
// FUN_001B0C80
u8 *btlActionFindByUnit(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 0x30) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}

/* measured: 0cc0 shares the pointer-chain branch shape above; only its
   compare-field displacement changes, with nd 0 in a 60B/64B object. */
// FUN_001B0CC0
u8 *btlActionFindById(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    if (*(s32 *)(p + 8) == arg0) {
        return p;
    }
    p = *(u8 **)(p + 0x450);
check:
    if (p != NULL) goto loop;
    return NULL;
}


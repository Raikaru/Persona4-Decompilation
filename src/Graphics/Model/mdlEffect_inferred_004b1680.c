#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;
extern void memcpy(void *arg0, void *arg1, s32 arg2);

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
extern s32 func_00481d80(u16 *arg0);
extern s32 TnSlotObject(u16 arg0);
extern void func_003c42b0(s32 arg0, s32 arg1);
extern s32 TlpCreate(u16 *arg0);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Source unit: src/promoted/code1_004b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004b.c; members 004b1680-004b16c0 */

// FUN_004B1680
void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3)
{
    D_00922DA0[0] = arg0;
    D_00922DA4[0] = arg1;
    D_00922DA8[0] = arg2;
    D_00922DAC[0] = arg3;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}

// FUN_004B16C0
void *func_004b16c0(void *opaqueSource) {
    u8 *arg0 = opaqueSource;
    u16 *temp_2_3;
    u16 *temp_2_4;
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;

    chkmemAllocSiteTag(&iGpffffb118, 0x1A);
    temp_2 = (u8 *)jtbl_008873E8[0](0xB0, 0x40000);
    if (temp_2 == NULL) {
        kAssertFail(&iGpffffb118, 0x1B);
    }
    memset(temp_2, 0, 0xB0);
    *(s32 *)(temp_2 + 0) = -1;
    if (arg0 == NULL) {
        return temp_2;
    }
    *(s32 *)(temp_2 + 4) = *(u16 *)(arg0 + 0xC);
    temp_2_2 = func_00484490(arg0);
    if (temp_2_2 == NULL) {
        kAssertFail(&iGpffffb118, 0x2C);
    }
    memcpy(temp_2 + 0xC, temp_2_2, 0x98);
    temp_2_3 = (u16 *)GeometryCreateTableGrid(1, 2, 4, D_00713408, 0x4C);
    *(u16 **)(temp_2 + 0xA4) = temp_2_3;
    *temp_2_3 = *temp_2_3 & 0xFFFB;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0xA4) + 0x10) + 0x18);
    temp_3 = *(u8 **)(temp_3 + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    temp_2_4 = func_004844d0(arg0);
    if (temp_2_4 != NULL) {
        temp_4 = *(u16 *)(arg0 + 0x1C);
        switch (temp_4) {
        case 1:
            GeometryBlockSetTextureFromHandle(*(u8 **)(temp_2 + 0xA4), temp_2_4);
            break;
        case 2:
            *(s32 *)(temp_2 + 0xAC) = func_00481d80(temp_2_4);
            break;
        case 4:
            func_003c42b0(*(s32 *)(*(u8 **)(temp_2 + 0xA4) + 0x14),
                          TnSlotObject(*temp_2_4));
            break;
        case 7:
            *(s32 *)(temp_2 + 0xA8) = TlpCreate(temp_2_4);
            break;
        default:
            kAssertFail(&iGpffffb118, 0x5C);
            break;
        }
    }
    return temp_2;
}


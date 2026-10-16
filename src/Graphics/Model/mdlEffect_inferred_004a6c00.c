#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern u8 *func_004a6c00(u8 *arg0);
extern u8 D_0071413C[];
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern void kAssertFail(u8 *arg0, s32 arg1);
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];



extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void memset(void *dst, s32 value, u32 size);
extern void func_003c22f0();
extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Source unit: src/promoted/code1_004a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004a6c00-004a6c00 */

/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: testing loop-invariant hoisting for the retail preheader. */
/* measured: func_004a6c00 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_004A6C00
u8 *func_004a6c00(u8 *arg0)
{
    u16 *temp_18;
    u16 *temp_2_2;
    u16 *temp_3;
    u32 var_4;
    u8 *temp_17;
    u8 *temp_2;
    u8 *var_5;

    chkmemAllocSiteTag(D_00714350, 0x78);
    temp_2 = (u8 *)jtbl_008873E8[0](0x5C, 0x40000);
    if (temp_2 == NULL) {
        kAssertFail(D_00714350, 0x79);
    }
    memset(temp_2, 0, 0x5C);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2) : "memory");
    memcpy(temp_2 + 0x18, arg0, 0x40);
    temp_2_2 = GeometryCreateTableGridMultiPart(0xD, 4, 2, 4, D_00713408, 0x4C);
    *(u16 **)(temp_2 + 0x58) = temp_2_2;
    *temp_2_2 = *temp_2_2 & 0xFFFE;
    temp_3 = *(u16 **)(temp_2 + 0x58);
    *temp_3 = *temp_3 & 0xFFFB;
    RpGeometryLock(
        *(RpGeometry **)(*(u8 **)(*(u8 **)(temp_2 + 0x58) + 0x10) + 0x18), 8);
    var_5 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x58) + 0x10) + 0x18) + 0x30);
    temp_3 = (u16 *)(s32)-1;
    var_4 = 0;
    goto loop_004a6c00_check;
loop_004a6c00_body:
    *(s32 *)(var_5 + 0) = (s32)temp_3;
    *(s32 *)(var_5 + 4) = (s32)temp_3;
    *(s32 *)(var_5 + 8) = (s32)temp_3;
    *(s32 *)(var_5 + 0xC) = (s32)temp_3;
    var_5 += 0x10;
    var_4 += 1;
loop_004a6c00_check:
    if (var_4 < 0x34U) {
        goto loop_004a6c00_body;
    }
    temp_18 = *(u16 **)(temp_2 + 0x58);
    temp_17 = *(u8 **)(*(u8 **)((u8 *)temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17, var_5);
    if ((*temp_18 & 4) != 0) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    return temp_2;
}


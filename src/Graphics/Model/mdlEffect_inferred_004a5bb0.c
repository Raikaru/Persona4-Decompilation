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
extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 TnSlotObject(u16 arg0);
extern s32 func_00481d80(u16 *arg0);
extern s32 TlpCreate(u16 *arg0);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004a5bb0-004a5bb0 */

/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
// FUN_004A5BB0
void *func_004a5bb0(void *source)
{
    u8 *arg0 = (u8 *)source;
    u16 *temp_2_4;
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_3;

    chkmemAllocSiteTag(D_007141A0, 0x1C);
    temp_2 = (u8 *)jtbl_008873E8[0](0xD4, 0x40000);
    if (temp_2 == NULL) {
        kAssertFail(D_007141A0, 0x1D);
    }
    memset(temp_2, 0, 0xD4);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(temp_2) : "memory");
    *(s32 *)(temp_2 + 0x24) = -1;
    *(f32 *)(temp_2 + 0x20) = 1.0f;
    if (arg0 == NULL) {
        return temp_2;
    }
    temp_2_2 = GeometryCreateTableGrid(1, 2, 4, D_00713408, 0x4C);
    *(u8 **)(temp_2 + 0xC8) = temp_2_2;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2_2 + 0x10) + 0x18) + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    *(s32 *)(temp_2 + 0x28) = *(u16 *)(arg0 + 0xC);
    temp_2_3 = mdlEffectResolveRelPtrA(arg0);
    if (temp_2_3 == NULL) {
        kAssertFail(D_007141A0, 0x47);
    }
    memcpy(temp_2 + 0x30, temp_2_3, 0x98);
    temp_2_4 = mdlEffectResolveRelPtrB(arg0);
    if (temp_2_4 != NULL) {
        temp_4 = *(u16 *)(arg0 + 0x1C);
        switch (temp_4) {
        case 1:
            GeometryBlockSetTextureFromHandle(*(u8 **)(temp_2 + 0xC8), temp_2_4);
            break;
        case 2:
            *(s32 *)(temp_2 + 0xD0) = func_00481d80(temp_2_4);
            break;
        case 4:
            func_003c42b0(
                *(u8 **)(*(u8 **)(temp_2 + 0xC8) + 0x14),
                TnSlotObject(*temp_2_4));
            break;
        case 7:
            *(s32 *)(temp_2 + 0xCC) = TlpCreate(temp_2_4);
            break;
        default:
            kAssertFail(D_007141A0, 0x5D);
            break;
        }
    }
    return temp_2;
}


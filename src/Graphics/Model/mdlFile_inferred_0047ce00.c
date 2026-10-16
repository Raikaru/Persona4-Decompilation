#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern void (*iGpffffbb3c)();
extern void (*jtbl_008873EC[])(void *);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];



struct MdlFlags78ec0;


/* measured: sdkLboxGetSelectedId's final `index*0xA4 + base` add emitted
 * addu $v0,$s0,$v0 where retail has addu $v0,$v0,$s0; both plain C operand
 * orders compile identically (nd 2). Routing the add through this
 * static inline helper, whose parameter order is the reverse of the
 * expression order, flips the operands and matches (nd 2 -> 0). The object
 * size is unchanged, so the helper is inlined rather than called. */
static inline s32 viewAddReverse(s32 base, s32 offset)
{
    return offset + base;
}

extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_Destroy(u8 *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);
extern void H_Cdvd_ReadSync(u8 *arg0);
extern void K_Clump_FreeTextureNameList(void *arg0);
extern s32 mdlReadAuxChunks(u8 *arg0);
extern s32 mdlPollAuxResources(u8 *arg0);
extern void func_0047e450(void **arg0, u32 arg1, u16 arg2, s32 arg3, u32 arg4);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;
static inline f32 code1_0047_mul(f32 left, f32 right)
{
    return left * right;
}
static inline f32 code1_0047_madd(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + left * right;
}
static inline f32 code1_0047_madd_reverse(f32 left, f32 right, f32 addend)
{
    return 0.0f + addend + right * left;
}

/* Source unit: src/promoted/code1_0047.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0047.c; members 0047ce00-0047d170 */

/* Advances the load state byte at +0x3C of the aux block at +0x30C: waits for the file, reads its tables, runs the material and texture steps, then frees the file. Returns 1 when done, 0 while a step is pending. */
// FUN_0047CE00
s32 mdlAdvanceAuxLoad(u8 *arg0)
{
    s32 ret;
    u8 *obj;
    u32 sp4C;

    obj = *(u8 **)(arg0 + 0x30C);
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    switch (*(u8 *)(obj + 0x3C)) {
    case 0:
        if (*(u8 **)(obj + 0x38) != NULL) {
            if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
                H_Cdvd_ReadSync(*(u8 **)(obj + 0x38));
            }
            if (H_Cdvd_IsFileLoaded(*(u8 **)(obj + 0x38)) == 0) {
                goto ret_label;
            }
            if (*(s32 *)(obj + 0x40) == 0) {
                *(s32 *)(obj + 0x2C) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x110);
                *(s32 *)(obj + 0x30) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x118);
            } else {
                *(s32 *)(obj + 0x2C) = (s32)func_00455ea0(*(u8 **)(obj + 0x38), 0, (s32 *)&sp4C);
                *(s32 *)(obj + 0x30) = sp4C;
                func_0047e450((void **)((u32)arg0 + 0x2D0), *(u16 *)(arg0 + 0xD4), *(u16 *)(arg0 + 0xD6),
                              (s32)func_00455ea0(*(u8 **)(obj + 0x38), 1, (s32 *)&sp4C), sp4C);
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
        if (*(s32 *)(obj + 0) == 0) {
            *(s32 *)(obj + 0) = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 1:
        if (*(u8 *)(obj + 0x3C) == 1) {
c660_again:
            if (mdlPollAuxResources(arg0) == 0) {
                goto ret_label;
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 2:
        if (mdlReadAuxChunks(arg0) == 0) {
            goto L_case2_fail;
        }
        *(u8 *)(obj + 0x3C) = 3;
        goto L_D8_check;
L_case2_fail:
        *(u8 *)(obj + 0x3C) = 1;
        goto c660_again;
L_D8_check:
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(obj + 0x3C) = 4;
            goto L_after_c3;
        }
    case 3:
        if (mdlPollAuxResources(arg0) == 0) {
            goto ret_label;
        }
        *(u8 *)(obj + 0x3C) = 4;
L_after_c3:
    case 4:
        if (*(s32 *)(obj + 0x34) != 0) {
            K_Clump_FreeTextureNameList(*(void **)(obj + 0x34));
        }
        func_003e2e40(*(s32 *)(obj + 0), (s32 *)(obj + 0x2C));
        if (*(u8 **)(obj + 0x38) != NULL) {
            H_Cdvd_Destroy(*(u8 **)(obj + 0x38));
        }
        *(u8 *)(obj + 0x3C) = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}

// FUN_0047D050
void mdlResetModelTable(s32 arg0)
{
    memset(D_00922BE0, 0, 0x30);
    iGpffffbb28 = arg0;
}

// FUN_0047D090
s32 mdlSetModelCallbacks(MdlNameCallback arg0, MdlTypeCallback arg1, MdlNameCallback arg2,
                 MdlSetupCallback arg3, MdlDataCallback arg4)
{
    iGpffffbb2c = arg0;
    iGpffffbb30 = arg1;
    iGpffffbb34 = arg2;
    iGpffffbb38 = arg3;
    iGpffffbb3c = (void (*)())arg4;
    return 1;
}

// FUN_0047D0B0
s32 mdlGetModelNameForId(u32 type, u16 id, char *output)
{
    return iGpffffbb2c(type, id, output);
}

// FUN_0047D0E0
s32 mdlQueryModelType(u32 type, u16 id)
{
    return iGpffffbb30(type, id);
}

// FUN_0047D110
s32 mdlBuildModelPath(u32 type, u16 id, char *output)
{
    return iGpffffbb34(type, id, output);
}

// FUN_0047D140
void mdlRunSetupCallback(void *model)
{
    iGpffffbb38(model);
}

// FUN_0047D170
void mdlRunDataCallback(void *model)
{
    iGpffffbb3c(model);
}


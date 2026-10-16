#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"

typedef struct BtlPacket BtlPacket;

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;

extern u8 *iGpffffa5f0;
extern void sdkSndResetChannel(s32 arg0, s32 arg1);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);
extern void H_Cdvd_Destroy(u8 *ptr);
extern void func_0045ac90(s32 arg0, s32 arg1, s32 arg2);
extern s32 btlBossLoadEndBgmStep(u8 *work);

extern void btlBuildNpcModelName(s32 *arg0, s32 arg1);
extern s32 btlCurrentUnitId(void);
extern s64 datGetDateIndex(void);
extern s32 datGetFlag(s32 arg0);
extern s32 func_00106cd0(s32 arg0, s32 arg1);
extern s32 calGetDayWindowFlags(s16 arg0);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void btlBossResolveNpcModelName(s32 arg0, u16 arg1);
extern u8 *H_Cdvd_LookupRequest(void *arg0, u32 *arg1);
extern char D_007636e0;
extern char D_006358D0[];
extern char D_006358F0[];
extern char D_00635910[];
extern char D_00635678[];
extern char D_00635690[];
extern char D_006356B0[];
extern char D_006356D0[];
extern char D_006356F0[];
extern char D_00635710[];
extern char D_00635730[];
extern char D_00635750[];
extern char D_00635770[];
extern char D_00635790[];
extern char D_006357B0[];
extern s32 strlen(const void *arg0);
extern char D_006357C8[];
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern void mdlAttachSlotModelFromResource(void *model, u16 slot, u32 type, u16 id,
                           void *path, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slot, u32 type, u16 id,
                          u32 flags);
extern void mdlSetAttachedSlotValue(void *arg0, s32 arg1, s32 arg2);
extern char D_006357E0[];
extern char D_00635800[];






// measured: opt_loop_invariants on hoists the two delimiter constants before the scan loop and preserves the retail register schedule.
#pragma opt_loop_invariants on
// Intent: Model path callback: writes the .pac pack path for a model id, rewriting the name's extension to "pac" under the pack directory (non-type-2 units use model/) [inferred]
// FUN_00230C00
s32 mdlResolvePacPath(u32 arg0, u16 arg1, char *arg2)
{
    char sp40[0x100];
    s32 var_2;

    if (mdlQueryModelType(arg0, arg1) == 0) {
        return mdlGetModelNameForId(arg0, arg1, arg2);
    }
    mdlGetModelNameForId(arg0, arg1, sp40);
    var_2 = strlen(sp40);
    sp40[var_2 - 3] = 'p';
    sp40[var_2 - 2] = 'a';
    sp40[var_2 - 1] = 'c';
    while (sp40[var_2] != '\\' && sp40[var_2] != '/') {
        var_2--;
    }
    switch (arg0 & 0xFFFF) {
    case 2:
        sprintf(arg2, D_006357C8, D_00635678, sp40 + var_2);
        break;
    default:
        sprintf(arg2, D_006357C8, &D_007636e0, sp40 + var_2);
        break;
    }
    return 1;
}
// measured: restore loop-invariant optimization after the matched target.
#pragma opt_loop_invariants off
// measured: optimization level 1 preserves the retail direct field loads and
// saved-register colouring for this function.
#pragma optimization_level 1
// Intent: Model setup callback: for type-2 units attaches the weapon R and L models (ids 0x1F4 and 0x1F5 in slots 0 and 1) and sets their slot values; other kinds attach slot 0 only [inferred]
// FUN_00230D30
s32 mdlAttachWeaponModelSlots(void *arg0)
{
    extern s32 func_00106cd0(s16 arg0, s16 arg1);
    extern void mdlSetAttachedSlotValue(u8 *arg0, u16 arg1, s32 arg2);
    u16 id;
    u8 sp40[0x100];
    s32 temp_18;

    if (*(u16 *)((s8 *)arg0 + 0xD4) != 1) return 0;
    id = func_00106cd0(*(s16 *)((u8 *)arg0 + 0xD6), 0);
    switch (*(u16 *)((s8 *)arg0 + 0xD6)) {
    case 2:
        if (mdlFindModelObject(7, id, 0) == 0) {
            sprintf((char *)sp40, D_006357E0,
                          (char *)&iGpffffa5f0, id & 0xFFFF);
            mdlAttachSlotModelFromResource(arg0, 0, 7, id, sp40, 0);
        } else {
            mdlAttachSlotModelFindOrCreate(arg0, 0, 7, id, 0);
        }
        temp_18 = (id & 0xFFFF) + 0x3E8;
        if (mdlFindModelObject(7, temp_18 & 0xFFFF, 0) == 0) {
            sprintf((char *)sp40, D_00635800,
                          (char *)&iGpffffa5f0, id & 0xFFFF);
            mdlAttachSlotModelFromResource(arg0, 1, 7, (u16)temp_18, sp40, 0);
        } else {
            mdlAttachSlotModelFindOrCreate(arg0, 1, 7, (u16)temp_18, 0);
        }
        break;
    case 3:
        return 0;
    default:
        mdlAttachSlotModelFindOrCreate(arg0, 0, 7, id, 0);
        goto block_13;
    }
block_13:
    mdlSetAttachedSlotValue((u8 *)arg0, 0, 0x1F4);
    mdlSetAttachedSlotValue((u8 *)arg0, 1, 0x1F5);
    return 1;
}
#pragma optimization_level 2

/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Graphics/Model/mdlManager.c); members 00230c00-00230d30 */

#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "mdl_file_internal.h"
extern u8 *iGpffffa5f0;
extern s32 datGetEquippedItemByUnit(s32 unitId, s32 slotIndex);
extern s32 sprintf(char *buf, char *fmt, ...);
extern char D_007636e0;
extern char D_00635678[];
extern s32 strlen(const void *);
extern char D_006357C8[];
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern void mdlAttachSlotModelFromResource(void *model, u16 slotIndex, u32 type, u16 id,
                           void *resource, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slotIndex, u32 type, u16 id,
                          u32 flags);
extern void mdlSetAttachedSlotValue(void *model, s32 slotIndex, s32 frameId);
extern char D_006357E0[];
extern char D_00635800[];
#pragma push
/* measured: baseline removal differs in 33 bytes; cache separator character; backward pointer path separator scan also differ. */
#pragma opt_loop_invariants on
// Intent: Model path callback: writes the .pac pack path for a model id, rewriting the name's extension to "pac" under the pack directory (non-type-2 units use model/) [inferred]
// FUN_00230C00
s32 mdlResolvePacPath(u32 type, u16 id, char *path)
{
    char modelPath[0x100];
    s32 separatorIndex;

    if (mdlQueryModelType(type, id) == 0) {
        return mdlGetModelNameForId(type, id, path);
    }
    mdlGetModelNameForId(type, id, modelPath);
    separatorIndex = strlen(modelPath);
    modelPath[separatorIndex - 3] = 'p';
    modelPath[separatorIndex - 2] = 'a';
    modelPath[separatorIndex - 1] = 'c';
    while (modelPath[separatorIndex] != '\\' && modelPath[separatorIndex] != '/') {
        separatorIndex--;
    }
    switch (type & 0xFFFF) {
    case 2:
        sprintf(path, D_006357C8, D_00635678, modelPath + separatorIndex);
        break;
    default:
        sprintf(path, D_006357C8, &D_007636e0, modelPath + separatorIndex);
        break;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
// Intent: Model setup callback: for type-2 units attaches the weapon R and L models (ids 0x1F4 and 0x1F5 in slots 0 and 1) and sets their slot values; other kinds attach slot 0 only [inferred]
// FUN_00230D30
s32 mdlAttachWeaponModelSlots(void *model)
{
    extern s32 datGetEquippedItemByUnit(s16 unitId, s16 slotIndex);
    extern void mdlSetAttachedSlotValue(u8 *model, u16 slotIndex, s32 frameId);
    u16 id;
    u8 path[0x100];
    s32 leftId;

    if (((MdlFileModel *)model)->type != 1) return 0;
    id = datGetEquippedItemByUnit((s16)((MdlFileModel *)model)->id, 0);
    switch (((MdlFileModel *)model)->id) {
    case 2:
        if (mdlFindModelObject(7, id, 0) == 0) {
            sprintf((char *)path, D_006357E0,
                          (char *)&iGpffffa5f0, id & 0xFFFF);
            mdlAttachSlotModelFromResource(model, 0, 7, id, path, 0);
        } else {
            mdlAttachSlotModelFindOrCreate(model, 0, 7, id, 0);
        }
        leftId = (id & 0xFFFF) + 0x3E8;
        if (mdlFindModelObject(7, leftId & 0xFFFF, 0) == 0) {
            sprintf((char *)path, D_00635800,
                          (char *)&iGpffffa5f0, id & 0xFFFF);
            mdlAttachSlotModelFromResource(model, 1, 7, (u16)leftId, path, 0);
        } else {
            mdlAttachSlotModelFindOrCreate(model, 1, 7, (u16)leftId, 0);
        }
        break;
    case 3:
        return 0;
    default:
        mdlAttachSlotModelFindOrCreate(model, 0, 7, id, 0);
        goto block_13;
    }
block_13:
    mdlSetAttachedSlotValue((u8 *)model, 0, 0x1F4);
    mdlSetAttachedSlotValue((u8 *)model, 1, 0x1F5);
    return 1;
}
#pragma pop

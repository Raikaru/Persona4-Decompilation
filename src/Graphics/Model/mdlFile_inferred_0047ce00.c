#include "h_cdvd_internal.h"
#include "mdl_file_internal.h"
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
extern void memset(void *model, s32 typeCallback, s32 pathCallback);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];



struct MdlFlags78ec0;



extern s32 func_003e2e40(s32 model, s32 *typeCallback);
extern s32 func_003e2f60(s32 model, s32 typeCallback, s32 *pathCallback);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern void H_Cdvd_ReadSync(u8 *cdvd);
extern void K_Clump_FreeTextureNameList(void *listHead);
extern s32 mdlReadAuxChunks(u8 *model);
extern s32 mdlPollAuxResources(u8 *model);
extern void mdlSeRequestLoad(void **owner, u32 type, u16 id, s32 source, u32 size);
extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0047; members 0047ce00-0047d170 */

/* Advances the load state byte at +0x3C of the aux block at +0x30C: waits for the file, reads its tables, runs the material and texture steps, then frees the file. Returns 1 when done, 0 while a step is pending. */
/* Advance the auxiliary resource loader through read, chunk setup, dependency polling and temporary-resource release. */
// FUN_0047CE00
s32 mdlAdvanceAuxLoad(u8 *model)
{
    s32 ret;
    u8 *obj;
    u32 entrySize;
    MdlFileAuxiliary *auxiliary;

    obj = ((MdlFileModel *)model)->auxiliary;
    auxiliary = (MdlFileAuxiliary *)obj;
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    switch (auxiliary->state) {
    case 0:
        if (auxiliary->file != NULL) {
            if ((((MdlFileModel *)model)->flags & 0x4000) != 0) {
                H_Cdvd_ReadSync(((MdlFileAuxiliary *)obj)->file);
            }
            if (H_Cdvd_IsFileLoaded((HCdvd *)auxiliary->file) == 0) {
                goto ret_label;
            }
            if (((MdlFileAuxiliary *)obj)->archived == 0) {
                ((MdlFileAuxiliary *)obj)->data = (s32)((HCdvd *)((MdlFileAuxiliary *)obj)->file)->fileMemory;
                ((MdlFileAuxiliary *)obj)->size = (s32)((HCdvd *)((MdlFileAuxiliary *)obj)->file)->fileSize;
            } else {
                ((MdlFileAuxiliary *)obj)->data = (s32)H_Cdvd_GetArchiveEntry(auxiliary->file, 0, (s32 *)&entrySize);
                ((MdlFileAuxiliary *)obj)->size = entrySize;
                mdlSeRequestLoad((void **)((u32)model + 0x2D0), ((MdlFileModel *)model)->type, ((MdlFileModel *)model)->id,
                              (s32)H_Cdvd_GetArchiveEntry(((MdlFileAuxiliary *)obj)->file, 1, (s32 *)&entrySize), entrySize);
            }
            ((MdlFileAuxiliary *)obj)->state = 2;
        }
        if (((MdlFileAuxiliary *)obj)->reader == 0) {
            ((MdlFileAuxiliary *)obj)->reader = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            ((MdlFileAuxiliary *)obj)->state = 2;
        }
    case 1:
        if (auxiliary->state == 1) {
c660_again:
            if (mdlPollAuxResources(model) == 0) {
                goto ret_label;
            }
            ((MdlFileAuxiliary *)obj)->state = 2;
        }
    case 2:
        if (mdlReadAuxChunks(model) == 0) {
            goto L_case2_fail;
        }
        auxiliary->state = 3;
        goto L_D8_check;
L_case2_fail:
        ((MdlFileAuxiliary *)obj)->state = 1;
        goto c660_again;
L_D8_check:
        if ((((MdlFileModel *)model)->flags & 0x4000) != 0) {
            ((MdlFileAuxiliary *)obj)->state = 4;
            goto L_after_c3;
        }
    case 3:
        if (mdlPollAuxResources(model) == 0) {
            goto ret_label;
        }
        ((MdlFileAuxiliary *)obj)->state = 4;
L_after_c3:
    case 4:
        if ((s32)((MdlFileAuxiliary *)obj)->textureNames != 0) {
            K_Clump_FreeTextureNameList(((MdlFileAuxiliary *)obj)->textureNames);
        }
        func_003e2e40(((MdlFileAuxiliary *)obj)->reader, (s32 *)(obj + 0x2C));
        if (((MdlFileAuxiliary *)obj)->file != NULL) {
            H_Cdvd_Destroy((HCdvd *)((MdlFileAuxiliary *)obj)->file);
        }
        ((MdlFileAuxiliary *)obj)->state = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}

/* Clear the model registry buckets and store the supplied table configuration. */
// FUN_0047D050
void mdlResetModelTable(s32 model)
{
    memset(D_00922BE0, 0, 0x30);
    iGpffffbb28 = model;
}

/* Install the name, type, path, model-setup and data callbacks used by model-file loading. */
// FUN_0047D090
s32 mdlSetModelCallbacks(MdlNameCallback model, MdlTypeCallback typeCallback, MdlNameCallback pathCallback,
                 MdlSetupCallback setupCallback, MdlDataCallback dataCallback)
{
    iGpffffbb2c = model;
    iGpffffbb30 = typeCallback;
    iGpffffbb34 = pathCallback;
    iGpffffbb38 = setupCallback;
    iGpffffbb3c = (void (*)())dataCallback;
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


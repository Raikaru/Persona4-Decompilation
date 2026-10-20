
#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "h_cdvd_request_internal.h"
#include "Kosaka/k_fldFilter_internal.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
extern s32 iGpffff9ef8;
extern s32 iGpffff9f08;
extern void strcpy(void *, const char *);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 H_Cdvd_FileExists(void *);
extern void func_00440b68(char *, const char *, s32 , ...);
extern u8 *H_Cdvd_AcquireDirectory(void *, s32 );
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern void memcpy(void *dst, void *src, u32 size);
extern void H_Cdvd_Destroy(void *);
extern s32 H_Cdvd_IsFileLoaded(u8 *);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern s32 iGpffff9f08;
/* Return the active filter entry's render type. */
// FUN_001614D0
s32 FldFilterGetEntry(void)
{
    return (s32)((FldFilterEntry *)(iGpffffb2b0 + iGpffffb2b8 * 0x124))->type;
}

/* Set the global filter intensity multiplier. */
// FUN_00161500
void FldFilterSetIndex(s32 intensity)
{
    iGpffff9ef8 = intensity;
}

/* Open the fixed enemy configuration table if it exists. */
// FUN_00161510
s32 FldEnemyOpenTable(void)
{
    char directory[0x80];
    char path[0x80];

    strcpy(directory, D_005F1218);
    sprintf(path, D_005F1230);
    if (H_Cdvd_FileExists(path) == 0) {
        return 0;
    }
    func_00440b68((char *)&iGpffff9f08, D_005F1248, 0x69);
    return (s32)H_Cdvd_AcquireDirectory(path, 0);
}

#pragma push
/* Copy the loaded enemy configuration table and expose its attack-record block. The CDVD payload
 * address keeps retail's original pointer-arithmetic form. */
// FUN_001615A0
/* measured: retail's load order needs propagation off. */
#pragma opt_propagation off
s32 FldEnemyLoadTable(u8 *file)
{
    void *src;
    u32 size;

    if (file == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded(file) == 0) {
        return 0;
    }
    iGpffffb2c8 = D_007E7B20;
    size = ((HCdvdRequest *)(file))->size;
    src = ((HCdvdRequest *)(((u8 *)file + size) - size))->data;
    memcpy(iGpffffb2c8, src, size);
    iGpffffb2cc = iGpffffb2c8 + 0x300;
    H_Cdvd_Destroy(file);
    return 1;
}
#pragma pop

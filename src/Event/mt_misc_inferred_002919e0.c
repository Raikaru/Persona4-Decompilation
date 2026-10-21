#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "scene_resource_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];


extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
// lint: allow H011 -- measured: a u16 prototype changes the wide id arguments in func_00291a60.
extern u8 *MT_Scene_GetRes(s32);
extern void MT_Scene_DestroyRes(u16);
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32, f32, f32, f32,
                          f32, s32, s32);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

extern void mtMiscCollectType1Records(u8 *);
extern void mtMiscCollectType2Records(u8 *);
/* Destroys the three icon resources (ids 0xC00 | ((i + 0x384) & 0x3FF), i = 0..2) that are still
 * loaded. */
// FUN_002919E0
void mtMiscDestroyIconResources(void) {
    s32 resourceIndex;
    u16 resourceId;

    resourceIndex = 0;
    while (resourceIndex < 3) {
        resourceId = (u16)(((resourceIndex + 0x384) & 0x3ff) | 0xc00);
        if (MT_Scene_GetRes(resourceId) != 0) {
            MT_Scene_DestroyRes(resourceId);
        }
        resourceIndex++;
    }
}

/* Return the kind-specific stored handle, or zero for an absent resource. */
// FUN_00291A60
s32 mtMiscResourceValue(s32 resourceId)
{
    s32 resourceKind;
    s32 mask;
    u8 *resource;

    resource = MT_Scene_GetRes(resourceId);
    mask = 0xFFC00;
    resourceKind = (s32)(resourceId & 0xFFFF) & mask;
    resourceKind >>= 0xA;
    switch (resourceKind) {
    case 1:
        if (resource != NULL) {
            return (s32)((SceneCharacterUpdate *)resource)->model;
        }
        break;
    case 2:
        if (resource != NULL) {
            return (s32)((SceneObjectUpdate *)resource)->model;
        }
        break;
    case 3:
        if (resource != NULL) {
            return (s32)((SceneCharacterUpdate *)resource)->model;
        }
        break;
    case 10:
        if (resource != NULL) {
            return (s32)((ResrcRecord *)resource)->slotHandle[1];
        }
        break;
    default:
        break;
    }
    return 0;
}

// FUN_00291B30
s32 mtMiscResourceValueIsZero(s32 unused, u16 *resourceId) {
    return (s32)(mtMiscResourceValue(*resourceId) == 0);
}


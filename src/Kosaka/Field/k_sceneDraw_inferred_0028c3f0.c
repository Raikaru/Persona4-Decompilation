
#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "resrc_manager_internal.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
/* The defaults lookup follows the shared 0x750-byte light snapshot prefix. */
typedef struct EvtSceneLightDefaults {
    SceneLightWork lighting;
    u8 pad750[0x50];
    s32 count;
    u8 **resources;
} EvtSceneLightDefaults;

extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern s32 MT_Scene_GetTotalResInList(s32 resType);
extern void SceneDraw_SetCustomLight(u16 resTypeId, u32 customLight);
extern void *SceneDraw_GetList5FirstColor(void);
extern void *SceneDraw_GetList5SecondColor(void);
extern void *SceneDraw_GetList5Matrix(void);
extern SceneLightMatrix *RwMatrixRotate(SceneLightMatrix *matrix, const SceneLightAxis *axis, f32 angle, s32 combine);
extern u8 D_005EFA10[];
extern u8 D_005EFA20[];
extern void evtUpdateSceneLight(u8 *workBytes, u8 *resource, u8 *defaults);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
// Update model, NPC and type-12 lights, matching resource IDs against saved defaults.
// FUN_0028C3F0
void evtUpdateSceneLights(u8 *workBytes)
{
    u32 nodes[51];
    s32 count;
    s32 i;
    s32 k;
    s32 tableCount;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node;
    u8 *match;
    u32 *slot;
    u32 id;
    u8 *t;

    count = 0;
    i = 0;
    count += MT_Scene_GetTotalResInList(3);
    count += MT_Scene_GetTotalResInList(1);
    count += MT_Scene_GetTotalResInList(0xC);
    if (count < 0x33) {
        node1 = MT_Scene_GetResListHead(3);
        while (node1 != NULL) {
            nodes[i] = (u32)node1;
            i++;
            node1 = (u8 *)((ResrcRecord *)node1)->next;
        }
        node2 = MT_Scene_GetResListHead(1);
        while (node2 != NULL) {
            nodes[i] = (u32)node2;
            i++;
            node2 = (u8 *)((ResrcRecord *)node2)->next;
        }
        node3 = MT_Scene_GetResListHead(0xC);
        while (node3 != NULL) {
            nodes[i] = (u32)node3;
            i++;
            node3 = (u8 *)((ResrcRecord *)node3)->next;
        }
        i = 0;
        while (i < count) {
            slot = &nodes[i];
            node = (u8 *)*slot;
            id = *(u16 *)node;
            tableCount = ((EvtSceneLightDefaults *)workBytes)->count;
            k = 0;
            while (k < tableCount) {
                match = ((EvtSceneLightDefaults *)workBytes)->resources[k];
                if (*(u16 *)match == id) {
                    t = match;
                    goto found;
                }
                k++;
            }
            t = NULL;
found:
            evtUpdateSceneLight(workBytes, node, t);
            i++;
        }
    }
}
#pragma pop

#pragma push
/* measured: retail's code needs copy propagation on for this function. */
#pragma opt_propagation on
/* Updates one scene light: computes its model and character matrices from the resource and its
 * defaults. The three slot searches stay independent, and defaults are restored through a shared
 * return when no slot is selected. */
// FUN_0028C580
/* measured: retail hoists loop-invariant code in this function. */
#pragma opt_loop_invariants on
void evtUpdateSceneLight(u8 *workBytes, u8 *resource, u8 *defaults)
{
    SceneLightWork *work = (SceneLightWork *)workBytes;
    SceneLightModel *model = (SceneLightModel *)resource;
    SceneLightModel *modelDefaults = (SceneLightModel *)defaults;
    SceneLightResource12 *light = (SceneLightResource12 *)resource;
    SceneLightResource12 *lightDefaults = (SceneLightResource12 *)defaults;
    SceneLightMatrix modelMatrix;
    SceneLightMatrix characterMatrix;
    SceneLightMatrix lightMatrix;
    SceneLightVector *first;
    SceneLightVector *second;
    SceneLightMatrix *matrix;
    s32 slot = -1;
    s32 updateScene = 0;
    s32 index;
    s32 defaultIndex;
    s32 anyIndex;
    f32 angleX;
    f32 angleY;

    if (resource == NULL) {
        return;
    }
    switch ((*(u16 *)resource & 0xffc00) >> 10) {
    case 3:
        SceneDraw_SetCustomLight(*(u16 *)resource, 0);
        break;
    }
    for (index = 0; index < 3; index++) {
        if (D_00882210[index].mode == 3 && D_00882210[index].resource == resource) {
            slot = index;
            if ((*(u16 *)resource & 0xffc00) >> 10 == 3) {
                SceneDraw_SetCustomLight(*(u16 *)resource, 1);
            }
            break;
        }
    }
    if (slot == -1 && ((*(u16 *)resource & 0xffc00) >> 10) != 12) {
        for (defaultIndex = 0; defaultIndex < 3; defaultIndex++) {
            if (D_00882210[defaultIndex].mode == 2) {
                slot = defaultIndex;
                break;
            }
        }
    }
    if (slot == -1) {
        for (anyIndex = 0; anyIndex < 3; anyIndex++) {
            if (D_00882210[anyIndex].mode == 1) {
                slot = anyIndex;
                break;
            }
        }
    }
    if (slot == -1) {
        if (defaults != NULL) {
            switch ((*(u16 *)resource & 0xffc00) >> 10) {
            case 3:
                model->firstColor = modelDefaults->firstColor;
                model->secondColor = modelDefaults->secondColor;
                model->matrix = modelDefaults->matrix;
                first = SceneDraw_GetList5FirstColor();
                second = SceneDraw_GetList5SecondColor();
                matrix = SceneDraw_GetList5Matrix();
                *first = work->firstColor;
                *second = work->secondColor;
                *matrix = work->matrix;
                break;
            case 1:
                model->firstColor = modelDefaults->firstColor;
                model->secondColor = modelDefaults->secondColor;
                model->matrix = modelDefaults->matrix;
                break;
            case 12:
                light->firstColor = lightDefaults->firstColor;
                light->secondColor = lightDefaults->secondColor;
                light->matrix = lightDefaults->matrix;
                break;
            }
        }
        return;
    }
    if ((D_00882210[slot].mode == 2 || D_00882210[slot].mode == 1) &&
        ((*(u16 *)resource & 0xffc00) >> 10) == 3) {
        updateScene = 1;
    }
    if (((*(u16 *)resource & 0xffc00) >> 10) == 3) {
        model->firstColor.x = D_00882210[slot].firstColor.x;
        model->firstColor.y = D_00882210[slot].firstColor.y;
        model->firstColor.z = D_00882210[slot].firstColor.z;
        model->firstColor.w = 0.0f;
        model->secondColor.x = D_00882210[slot].secondColor.x;
        model->secondColor.y = D_00882210[slot].secondColor.y;
        model->secondColor.z = D_00882210[slot].secondColor.z;
        model->secondColor.w = 0.0f;
        angleX = D_00882210[slot].angles.x;
        angleY = D_00882210[slot].angles.y;
        sceneLightIdentity(&modelMatrix);
        RwMatrixRotate(&modelMatrix, (const SceneLightAxis *)D_005EFA20, angleY, 1);
        RwMatrixRotate(&modelMatrix, (const SceneLightAxis *)D_005EFA10, angleX, 1);
        model->matrix = modelMatrix;
        if (updateScene == 1) {
            first = SceneDraw_GetList5FirstColor();
            second = SceneDraw_GetList5SecondColor();
            matrix = SceneDraw_GetList5Matrix();
            *first = model->firstColor;
            *second = model->secondColor;
            *matrix = model->matrix;
        }
    } else if (((*(u16 *)resource & 0xffc00) >> 10) == 1) {
        model->firstColor.x = D_00882210[slot].firstColor.x;
        model->firstColor.y = D_00882210[slot].firstColor.y;
        model->firstColor.z = D_00882210[slot].firstColor.z;
        model->firstColor.w = 0.0f;
        model->secondColor.x = D_00882210[slot].secondColor.x;
        model->secondColor.y = D_00882210[slot].secondColor.y;
        model->secondColor.z = D_00882210[slot].secondColor.z;
        model->secondColor.w = 0.0f;
        angleX = D_00882210[slot].angles.x;
        angleY = D_00882210[slot].angles.y;
        sceneLightIdentity(&characterMatrix);
        RwMatrixRotate(&characterMatrix, (const SceneLightAxis *)D_005EFA20, angleY, 1);
        RwMatrixRotate(&characterMatrix, (const SceneLightAxis *)D_005EFA10, angleX, 1);
        model->matrix = characterMatrix;
    } else if (((*(u16 *)resource & 0xffc00) >> 10) == 12) {
        light->firstColor.x = D_00882210[slot].firstColor.x;
        light->firstColor.y = D_00882210[slot].firstColor.y;
        light->firstColor.z = D_00882210[slot].firstColor.z;
        light->firstColor.w = 0.0f;
        light->secondColor.x = D_00882210[slot].secondColor.x;
        light->secondColor.y = D_00882210[slot].secondColor.y;
        light->secondColor.z = D_00882210[slot].secondColor.z;
        light->secondColor.w = 0.0f;
        angleX = D_00882210[slot].angles.x;
        angleY = D_00882210[slot].angles.y;
        sceneLightIdentity(&lightMatrix);
        RwMatrixRotate(&lightMatrix, (const SceneLightAxis *)D_005EFA20, angleY, 1);
        RwMatrixRotate(&lightMatrix, (const SceneLightAxis *)D_005EFA10, angleX, 1);
        light->matrix = lightMatrix;
    }
}
#pragma pop

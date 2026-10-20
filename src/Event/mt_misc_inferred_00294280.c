#include "mt_scene_internal.h"
#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "scene_resource_internal.h"
#include "scene_light_override_internal.h"
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
/* Builds the scene's fixed event nodes: resource 0x400, one node per kind-3 resource, and three
 * icon nodes. Copies the kind-5 resource's transform, two four-float vectors and the 0x40-byte
 * matrix into the event light state. */
// FUN_00294280
void mtMiscBuildSceneNodes(u8 *eventWork)
{
    ResrcHeader *firstHeader;
    typedef struct Resrc Resrc;
    typedef struct ResrcManager ResrcManager;
    extern u32 MT_Scene_GetResManager(void);
    extern Resrc *MT_Scene_GetRes(u16 resTypeId);
    extern Resrc *resrcMngGetListHead(ResrcManager *eventWork, u8);
    extern u32 resrcMngGetTotalResInList(u8 *eventWork, u8);
    extern void *evtNodeAlloc(s32 eventWork, s32);
    extern void evtNodeSetRes(s32 eventWork, s32, s32);
    extern void *evtNodeAllocWithRes(s32 eventWork, u8 *, u16, s32);
    extern void evtNpcResourceHook(u8 *resource);
    extern void func_00440b68(char *fmt, ...);
    extern f64 fptodp(f32 eventWork);
    extern void *mdlGetColor(void *model);
    extern char D_0063CAC0[];
    extern char D_0063CAD0[];
    s32 alpha;
    f64 diagnosticX;
    f64 diagnosticY;
    s32 red;
    s32 value;
    s32 blue;
    u16 *firstResource;
    u8 *firstColor;
    u8 *color;
    u8 *resource;
    u8 *sourceWords;
    u8 *destinationWords;
    s32 pairsRemaining;
    f64 firstX;
    f64 firstY;
    s32 resourceCount;
    s32 resourceIndex;
    s32 resourceManager;
    u8 *modelResource;
    s32 nodeValue;
    f32 componentFirst;
    f32 componentSecond;
    f32 componentThird;
    f32 componentFourth;

    resourceManager = MT_Scene_GetResManager();
    if (resourceManager != 0) {
        firstResource = (u16 *)MT_Scene_GetRes(0x400);
        firstHeader = (ResrcHeader *)firstResource;
        if (firstResource != NULL) {
            nodeValue = (s32)evtNodeAlloc(1, (s32)eventWork);
            evtNodeSetRes(nodeValue, 0x400, (s32)firstResource);
            ((MtMiscSceneNode *)nodeValue)->unk_08 = -1;
            componentThird = ((ResrcHeader *)firstResource)->position.x;
            componentSecond = ((ResrcHeader *)firstResource)->position.y;
            componentFirst = ((ResrcHeader *)firstResource)->position.z;
            ((MtMiscSceneNode *)nodeValue)->unk_38.x = componentThird;
            ((MtMiscSceneNode *)nodeValue)->unk_38.y = componentSecond;
            ((MtMiscSceneNode *)nodeValue)->unk_38.z = componentFirst;
            componentThird = ((ResrcHeader *)firstResource)->rotation.x;
            componentSecond = ((ResrcHeader *)firstResource)->rotation.y;
            componentFirst = ((ResrcHeader *)firstResource)->rotation.z;
            ((MtMiscSceneNode *)nodeValue)->unk_44.x = componentThird;
            ((MtMiscSceneNode *)nodeValue)->unk_44.y = componentSecond;
            ((MtMiscSceneNode *)nodeValue)->unk_44.z = componentFirst;
            firstX = fptodp(((ResrcHeader *)firstResource)->position.x);
            firstY = fptodp(firstHeader->position.y);
            func_00440b68(D_0063CAC0, firstX, firstY,
                          fptodp(firstHeader->position.z));
            firstColor = mdlGetColor(((SceneCharacterUpdate *)firstResource)->model);
            red = firstColor[0];
            value = firstColor[1];
            resourceCount = firstColor[2];
            resourceIndex = firstColor[3];
            ((MtMiscSceneNode *)nodeValue)->unk_50[0] = (u8)red;
            ((MtMiscSceneNode *)nodeValue)->unk_50[1] = (u8)value;
            ((MtMiscSceneNode *)nodeValue)->unk_50[2] = (u8)resourceCount;
            ((MtMiscSceneNode *)nodeValue)->unk_50[3] = (u8)resourceIndex;
        } else {
            evtNodeSetRes((s32)evtNodeAlloc(1, (s32)eventWork), 0x400, 0);
        }
        resourceCount = resrcMngGetTotalResInList((u8 *)resourceManager, 3);
        modelResource = (u8 *)resrcMngGetListHead((ResrcManager *)resourceManager, 3);
        func_00440b68(D_0063CAD0, resourceCount);
        resourceIndex = 0;
        while (resourceIndex < resourceCount) {
            evtNpcResourceHook(modelResource);
            nodeValue = (s32)evtNodeAllocWithRes(
                1, eventWork, *(u16 *)modelResource, (s32)modelResource);
            ((MtMiscSceneNode *)nodeValue)->unk_08 = -1;
            componentThird = ((ResrcHeader *)modelResource)->position.x;
            componentSecond = ((ResrcHeader *)modelResource)->position.y;
            componentFirst = ((ResrcHeader *)modelResource)->position.z;
            ((MtMiscSceneNode *)nodeValue)->unk_38.x = componentThird;
            ((MtMiscSceneNode *)nodeValue)->unk_38.y = componentSecond;
            ((MtMiscSceneNode *)nodeValue)->unk_38.z = componentFirst;
            componentThird = ((ResrcHeader *)modelResource)->rotation.x;
            componentSecond = ((ResrcHeader *)modelResource)->rotation.y;
            componentFirst = ((ResrcHeader *)modelResource)->rotation.z;
            ((MtMiscSceneNode *)nodeValue)->unk_44.x = componentThird;
            ((MtMiscSceneNode *)nodeValue)->unk_44.y = componentSecond;
            ((MtMiscSceneNode *)nodeValue)->unk_44.z = componentFirst;
            diagnosticX = fptodp(((ResrcHeader *)modelResource)->position.x);
            diagnosticY = fptodp(MEMBER(f32, modelResource, ResrcHeader, position.y));
            func_00440b68(D_0063CAC0, diagnosticX, diagnosticY,
                          fptodp(MEMBER(f32, modelResource, ResrcHeader, position.z)));
            color = mdlGetColor(((SceneCharacterUpdate *)modelResource)->model);
            red = color[0];
            value = color[1];
            blue = color[2];
            alpha = color[3];
            ((MtMiscSceneNode *)nodeValue)->unk_50[0] = (u8)red;
            ((MtMiscSceneNode *)nodeValue)->unk_50[1] = (u8)value;
            ((MtMiscSceneNode *)nodeValue)->unk_50[2] = (u8)blue;
            ((MtMiscSceneNode *)nodeValue)->unk_50[3] = (u8)alpha;
            resourceIndex++;
            modelResource = (u8 *)((ResrcHeader *)modelResource)->next;
        }

        nodeValue = 0;
        while (nodeValue < 3) {
            resource = evtNodeAlloc(1, (s32)eventWork);
            value = nodeValue + 0x384;
            value = (value & 0x3FF) | 0xC00;
            evtNodeSetRes((s32)resource, value & 0xFFFF, 0);
            nodeValue++;
        }

        resource = (u8 *)resrcMngGetListHead((ResrcManager *)resourceManager, 5);
        if (resource != NULL) {
            componentFirst = ((SceneLightVector *)(resource + 0x140))->x;
            componentSecond = ((SceneLightVector *)(resource + 0x140))->y;
            componentThird = ((SceneLightVector *)(resource + 0x140))->z;
            componentFourth = ((SceneLightVector *)(resource + 0x140))->w;
            ((SceneLightWork *)eventWork)->firstColor.x = componentFirst;
            ((SceneLightWork *)eventWork)->firstColor.y = componentSecond;
            ((SceneLightWork *)eventWork)->firstColor.z = componentThird;
            ((SceneLightWork *)eventWork)->firstColor.w = componentFourth;
            componentFirst = ((SceneLightVector *)(resource + 0x150))->x;
            componentSecond = ((SceneLightVector *)(resource + 0x150))->y;
            componentThird = ((SceneLightVector *)(resource + 0x150))->z;
            componentFourth = ((SceneLightVector *)(resource + 0x150))->w;
            ((SceneLightWork *)eventWork)->secondColor.x = componentFirst;
            ((SceneLightWork *)eventWork)->secondColor.y = componentSecond;
            ((SceneLightWork *)eventWork)->secondColor.z = componentThird;
            ((SceneLightWork *)eventWork)->secondColor.w = componentFourth;
            sourceWords = resource + 0x160;
            destinationWords = eventWork + 0x710;
            pairsRemaining = 8;
            do {
                /* The light matrix is copied in eight word pairs, preserving its reserved words. */
                value = *(s32 *)sourceWords;
                red = ((s32 *)sourceWords)[1];
                sourceWords += 8;
                pairsRemaining--;
                *(s32 *)destinationWords = value;
                ((s32 *)destinationWords)[1] = red;
                destinationWords += 8;
            } while (pairsRemaining > 0);
        }
    }
}


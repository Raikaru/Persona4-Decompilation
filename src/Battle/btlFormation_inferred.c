#include "model_battle_internal.h"
#include "primitive_queue_internal.h"
#include "rw_frame_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_formation_attach_internal.h"
#include "btl_unit_internal.h"
#include "btl_effect_internal.h"
typedef struct BtlPacket BtlPacket;

extern void btlTargetBlendVectors(void *rotation, void *first, void *second);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern s32 mdlComputeIndexedAttachMatrix();
extern void RtQuatTransformVectors(f32 *output, f32 *input, s32 count, u8 *rotation);
extern void mdlEffectFlushTreeFrame(s32 effect);
extern s32 TnGetTableBase(void);
extern void TnSetTableBase(s32 table);
extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
extern void mdlEffectCommitTreeFrame(u8 *effect);
extern void btlFormationUpdateAttachments(s32 work);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *list, u8 *node);
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern f32 RwV3dNormalize(f32 *output, f32 *input);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 flags);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 *kwlnGetCamera();
extern void func_003e8110(u8 *camera);
extern void func_003e8120(u8 *camera);
extern void func_003e9cb0(s32 frame, u8 *transform, s32 combine);
extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();


extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d4eb0-001d5b20 */

extern s32 btlCameraFindFormationForCounts(u8 *counts);
typedef void BtlAttachPositionCallback(u8 *work, u8 *unit, u8 *entry, f32 *position);
/* Derive attachment scale from the unit bounds and clamp it for effects. */
static inline f32 btlAttachEffectScale(u8 *unit)
{
    f32 s;

    s = 0.0125f * (0.5f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale + 0.5f * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale)));
    if (!(s <= 2.5f)) {
        s = 2.5f;
    } else if (s < 0.8f) {
        s = 0.8f;
    }
    return s;
}
/* Choose field attachment scale from battle mode and scaled unit radius. */
static inline f32 btlAttachFieldScale(u8 *unit)
{
    f32 s;

    if (((BtlBattleState *)iGpffffb3ac)->phase.singleUnit == 0) {
        return 4.25f;
    }
    s = 2.0f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale) / 100.0f;
    if (!(s <= 5.0f)) {
        s = 5.0f;
    } else if (s < 2.0f) {
        s = 2.0f;
    }
    return s;
}
/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* Resolve an attachment point from its indexed model matrix, with a cached-position mode and camera-
 * distance adjustment along the normalized camera-to-attachment direction. */
// FUN_001D4EB0
void btlFormationAttachPosition(u8 *work, u8 *unit, u8 *attachment, f32 *output)
{
    struct Frame {
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6c;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 pad7c;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 pad8c;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 pad9c;
    } frame;
    u8 *attachmentMode;
    u8 *cameraFrame;
    u32 cameraDistance;
    f32 distanceFloat;

    attachmentMode = attachment + 8;
    if ((((BtlAttachEntry *)attachment)->mode.positionMode == 1) &&
        (*(s32 *)&((BtlAttachEntry *)attachment)->start + 2 != ((BtlAttachWork *)work)->frame)) {
        output[0] = ((BtlAttachWork *)work)->cachedPosition.x;
        output[1] = ((BtlAttachWork *)work)->cachedPosition.y;
        output[2] = ((BtlAttachWork *)work)->cachedPosition.z;
        goto end;
    }

    if ((((BtlUnit *)unit)->flags2 & 2) == 0) {
        btlUnitGetSphereWorldCenter(unit, &frame.value90);
    } else if (mdlComputeIndexedAttachMatrix(((BtlUnit *)unit)->layerHandle,
                             ((BtlAttachMode *)attachmentMode)->matrixIndex,
                             &frame.value90) == 0) {
        frame.value70 = ((BtlAttachWork *)work)->scale.x * ((BtlAttachWork *)work)->size;
        frame.value74 = ((BtlAttachWork *)work)->scale.y * ((BtlAttachWork *)work)->size;
        frame.value78 = ((BtlAttachWork *)work)->scale.z * ((BtlAttachWork *)work)->size;
        RtQuatTransformVectors(&frame.value60, &frame.value70, 1, work + 0x40);
        frame.value90 = frame.value60 + ((BtlAttachWork *)work)->pos.x;
        frame.value94 = frame.value64 + ((BtlAttachWork *)work)->pos.y;
        frame.value98 = frame.value68 + ((BtlAttachWork *)work)->pos.z;
    }

    output[0] = frame.value90;
    output[1] = frame.value94;
    output[2] = frame.value98;
    cameraDistance = ((BtlAttachMode *)attachmentMode)->kind;
    if (cameraDistance != 0) {
        if (cameraDistance >= 0) {
            distanceFloat = (f32)cameraDistance;
        } else {
            cameraDistance = (cameraDistance >> 1) | (cameraDistance & 1);
            distanceFloat = (f32)cameraDistance;
            distanceFloat = distanceFloat + distanceFloat;
        }
        cameraFrame = ((RwCamera *)kwlnGetCamera())->object.object.parent;
        frame.value80 = ((RwFrame *)cameraFrame)->modelling.pos.x - frame.value90;
        frame.value84 = ((RwFrame *)cameraFrame)->modelling.pos.y - frame.value94;
        frame.value88 = ((RwFrame *)cameraFrame)->modelling.pos.z - frame.value98;
        RwV3dNormalize(&frame.value80, &frame.value80);
        output[0] = output[0] - frame.value80 * distanceFloat;
        output[1] = output[1] - frame.value84 * distanceFloat;
        output[2] = output[2] - frame.value88 * distanceFloat;
    }

    if ((((BtlAttachMode *)attachmentMode)->positionMode == 1) &&
        (*(s32 *)&((BtlAttachEntry *)attachment)->start + 2 == ((BtlAttachWork *)work)->frame)) {
        ((BtlAttachWork *)work)->cachedPosition.x = output[0];
        ((BtlAttachWork *)work)->cachedPosition.y = output[1];
        ((BtlAttachWork *)work)->cachedPosition.z = output[2];
    }
end:
    ;
}

/* Choose the attachment quaternion from the work orientation or an indexed parent/child model matrix.
 * Weapon-slot selection uses the same 0x0C-byte records as mdlManager. */
// FUN_001D5130
void btlFormationAttachRotation(u8 *work, u8 *unit, u8 *attachment, u8 *output)
{
    struct Frame {
        f32 input[16];
        f32 output[16];
        f32 vector[4];
    } frame;
    u8 type;
    u8 *entry;
    s32 flags;
    s32 lookup;
    s32 lookupOffset;
    u8 *lookupBase;

    extern void RtQuatTransformVectors(f32 *work, f32 *unit, s32 attachment, u8 *output);
    extern f32 func_0044b950(f32 left, f32 right);
    extern s32 mdlCopyIndexedMatrix(u8 *model, s32 index, f32 *destination);
    extern void effMiscMatrixToQuatVU(f32 *matrix);
    extern void effMiscEulerToQuatVU(f32 angleX, f32 angleY, f32 angleZ);

    entry = attachment + 8;
    type = ((BtlAttachEntry *)attachment)->mode.type;
    switch (type) {
    case 0:
        RtQuatTransformVectors(frame.vector, (f32 *)D_0060A0F0, 1, work + 0x40);
        if (frame.vector[0] != 0.0f)
            goto case0_nonzero;
        if (frame.vector[2] == 0.0f)
            goto case0_zero;
case0_nonzero:
        effMiscEulerToQuatVU(0.0f,
                      func_0044b950(frame.vector[0], frame.vector[2]),
                      0.0f);
        __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(output) : "memory");
        goto case0_done;
case0_zero:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
case0_done:
        break;
    case 2:
    case 3:
    case 4:
    case 0xC:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        break;
    case 1:
    case 0xD:
        flags = ((BtlUnit *)unit)->flags2;
        if ((flags & 2) == 0)
            goto case1_no_flags;
        if (mdlCopyIndexedMatrix(((BtlUnit *)unit)->layerHandle,
                          ((BtlAttachMode *)entry)->matrixIndex, frame.input) == 0)
            goto case1_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            effMiscMatrixToQuatVU(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(output) : "memory");
        break;
case1_failure:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        break;
case1_no_flags:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        break;
    case 8:
    case 9:
        flags = ((BtlUnit *)unit)->flags2;
        if ((flags & 2) != 0) {
            lookupOffset = 12 * (type == 8);
            lookupBase = ((BtlUnit *)unit)->layerHandle;
            lookupBase += 0x290;
            lookup = (s32)((MdlWpnSlot *)(lookupBase + lookupOffset - 4))->wpnMdl;
            if (lookup == 0)
                break;
            if (mdlCopyIndexedMatrix((u8 *)lookup,
                              ((BtlAttachMode *)entry)->matrixIndex, frame.input) == 0)
                goto case8_failure;
            frame.output[0] = frame.input[0];
            frame.output[1] = frame.input[1];
            frame.output[2] = frame.input[2];
            frame.output[3] = 0.0f;
            frame.output[4] = frame.input[4];
            frame.output[5] = frame.input[5];
            frame.output[6] = frame.input[6];
            frame.output[7] = 0.0f;
            frame.output[8] = frame.input[8];
            frame.output[9] = frame.input[9];
            frame.output[10] = frame.input[10];
            frame.output[11] = 0.0f;
            frame.output[12] = frame.input[12];
            frame.output[13] = frame.input[13];
            frame.output[14] = frame.input[14];
            frame.output[15] = 0.0f;
            effMiscMatrixToQuatVU(frame.output);
            __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(output) : "memory");
            break;
case8_failure:
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        } else {
            __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        }
        break;
    case 7:
    case 0xA:
    case 0xB:
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(output) : "memory");
        break;
    case 5:
    case 6:
        break;
    default:
        break;
    }
}

/* Advance active attachment entries, create effect instances, and publish position, rotation, scale
 * and color. Initial/repeat refreshes snapshot the unit scale, position and facing quaternion. */
// FUN_001D53E0
void btlFormationUpdateAttachments(s32 work)
{
    extern void mdlSetFileStatePair(u32 first, u32 second);
    extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
    extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
    extern void mdlEffectSetChildScales(u8 *effect, f32 value);
    extern BtlAttachPositionCallback *D_00609500[];
    s32 count;
    BtlAttachWork *w;
    u32 frame;
    u32 now;
    u16 i;
    u32 color;
    s32 created;
    u8 **handles;
    BtlAttachEntry *entry;
    u8 *unit;
    f32 unitCenter[4];
    f32 targetCenter[4];
    f32 trans[4];
    f32 rot[4];

    w = (BtlAttachWork *)work;
    unit = w->unit;
    color = w->color;
    if (w->flags & 0x800) {
        return;
    }
    if ((color & 0xFF000000) == 0) {
        return;
    }
    frame = w->frame;
    if (frame == 0 || ((w->flags & 0x1000) && frame == ((BtlFormationState *)w->owner)->tables[1].unk04) || (w->flags & 0x100)) {
        w->scale = *(BtlAttachV3 *)&((BtlUnit *)unit)->sphereCenter;
        w->radius = ((BtlUnit *)unit)->unk_8c;
        w->height = ((BtlUnit *)unit)->sphereRadius;
        w->pos = *(BtlAttachV3 *)&((BtlUnit *)unit)->pos;
        if (unit == w->target || (((BtlUnit *)unit)->flags3 & 0x2000)) {
            w->center = *(BtlAttachV4 *)&((BtlUnit *)unit)->rot;
        } else if (unit[0xA2] == w->target[0xA2] && unit[0xA2] == 1) {
            w->center = *(BtlAttachV4 *)&((BtlUnit *)unit)->rot;
        } else {
            btlUnitGetSphereWorldCenter(unit, unitCenter);
            btlUnitGetSphereWorldCenter(w->target, targetCenter);
            btlTargetBlendVectors(&w->center, unitCenter, targetCenter);
        }
        w->size = ((BtlUnit *)unit)->scale;
    }
    mdlSetFileStatePair((u32)w->unit, (u32)w->target);
    now = (u32)frame;
    handles = w->handles;
    count = w->count;
    entry = (BtlAttachEntry *)(w->table + 0x14);
    for (i = 0; i < count; i++, entry++, handles++) {
        if (!(entry->start < now)) {
            continue;
        }
        if (entry->state == 0xFE) {
            continue;
        }
        if (*handles == 0) {
            u8 mode;

            if ((((BtlFormationState *)w->owner)->flags & 4) && entry->state != 0xFD) {
                *handles = entry->resource;
                created = 0;
                entry->state = 0xFD;
            } else {
                *handles = mdlEffectCloneWithNodes(entry->resource);
                created = 1;
            }
            mode = ((BtlAttachTable *)w->table)->scaleMode;
            if (mode != 0 && unit != NULL) {
                f32 s;

                switch (entry->mode.type) {
                case 0:
                case 1:
                case 0xD:
                case 6:
                case 7:
                    switch (mode) {
                    case 1:
                        if (!(w->flags & 0x20000)) {
                            s = btlAttachEffectScale(unit);
                        } else {
                            s = btlAttachFieldScale(unit);
                        }
                        break;
                    default:
                        s = btlAttachEffectScale(w->target);
                        break;
                    }
                    mdlEffectSetChildScales(*handles, s);
                    break;
                }
            }
            if (created) {
                continue;
            }
        }
        if (entry->mode.kind == 1) {
            if (w->flags & 0x1E) {
                continue;
            }
            if (w->level < 0x32) {
                continue;
            }
        }
        if (!(w->flags & 0x20000)) {
            D_00609500[entry->mode.type]((u8 *)w, unit, (u8 *)entry, trans);
        } else {
            if (((BtlBattleState *)iGpffffb3ac)->phase.singleUnit != 0) {
                trans[0] = ((BtlUnit *)unit)->pos.x;
                trans[1] = ((BtlUnit *)unit)->pos.y;
                trans[2] = ((BtlUnit *)unit)->pos.z;
            } else {
                trans[0] = 0.0f;
                trans[1] = 0.0f;
                trans[2] = -85.0f;
            }
            trans[3] = 0.0f;
        }
        mdlEffectSetChildPositions(*handles, trans);
        btlFormationAttachRotation((u8 *)w, unit, (u8 *)entry, (u8 *)rot);
        mdlEffectSetChildRotations(*handles, (u8 *)rot);
        mdlEffectApplyPackedColor(*handles, (s32)color);
        mdlEffectCommitTreeFrame(*handles);
    }
    w->frame++;
}

/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: func_001d5990 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* Save the camera modelling matrix and install the formation basis and position around effect drawing. */
// FUN_001D5990
void btlFormationCameraFrame(void)
{
    struct Frame {
        f32 rightX;
        f32 rightY;
        f32 rightZ;
        s32 matrixFlags;
        f32 upX;
        f32 upY;
        f32 upZ;
        f32 pad2C;
        f32 atX;
        f32 atY;
        f32 atZ;
        f32 pad3C;
        f32 positionX;
        f32 positionY;
        f32 positionZ;
        f32 pad4C;
        f32 sourceX;
        f32 sourceY;
        f32 sourceZ;
    } frame;
    u32 *source;
    u32 *destination;
    s32 count;
    u32 first;
    u32 second;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    extern f32 fGpffff8444;
    extern f32 fGpffff8448;
    extern f32 fGpffff844c;
    extern f32 fGpffff8450;
    extern f32 fGpffff8454;
    extern f32 fGpffff8458;
    extern f32 fGpffff845c;
    extern f32 fGpffff8460;
    extern f32 fGpffff8464;
    extern f32 fGpffff8468;
    extern f32 fGpffff846c;
    extern f32 fGpffff8470;
    extern f32 fGpffff8474;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;

    func_003e8110(kwlnGetCamera());
    source = (u32 *)((u8 *)((RwCamera *)kwlnGetCamera())->object.object.parent + 0x10);
    destination = (u32 *)D_008813B0;
    count = 8;
    do {
        first = source[0];
        second = source[1];
        source += 2;
        count--;
        destination[0] = first;
        destination[1] = second;
        destination += 2;
    } while (count > 0);
    frame.rightX = fGpffff8444;
    frame.rightY = fGpffff8448;
    frame.rightZ = fGpffff844c;
    frame.upX = fGpffff8450;
    frame.upY = fGpffff8454;
    frame.upZ = fGpffff8458;
    frame.atX = fGpffff845c;
    frame.atY = fGpffff8460;
    frame.atZ = fGpffff8464;
    frame.positionX = 0;
    frame.positionY = 0;
    frame.positionZ = 0;
    frame.matrixFlags = 3;
    frame.sourceX = fGpffff8468;
    frame.sourceY = fGpffff846c;
    frame.sourceZ = fGpffff8470;
    temp1 = frame.sourceX;
    temp2 = frame.sourceY;
    temp3 = frame.sourceZ;
    frame.positionX = temp1;
    frame.positionY = temp2;
    frame.positionZ = temp3;
    func_003e9cb0((s32)((RwCamera *)kwlnGetCamera())->object.object.parent, (u8 *)&frame.rightX, 0);
    func_003e8120(kwlnGetCamera());
}

/* measured: restore optimization_level 2 after func_001d5990. */
/* measured: func_001d5b20 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* Restore the camera modelling matrix saved before formation rendering. */
// FUN_001D5AC0
void btlFormationCameraUpdate(void) {
    func_003e8110(kwlnGetCamera());
    func_003e9cb0((s32)((RwCamera *)kwlnGetCamera())->object.object.parent, D_008813B0, 0);
    func_003e8120(kwlnGetCamera());
}

/* Queue formation camera setup/restore nodes around effect rendering, or draw the instances directly.
 * Primitive-node bookkeeping is cleared before the camera callback and battle argument are installed. */
// FUN_001D5B20
void btlFormationCameraTaskStart(u8 *work)
{
    s32 oldState;
    u8 **entries;
    s32 count;
    s32 index;
    u8 *task;

    if ((((BtlAttachWork *)work)->flags & 0x400) != 0) {
        return;
    }
    entries = ((BtlAttachWork *)work)->handles;
    count = (u16)(((BtlAttachWork *)work)->count & 0xFFFF);
    if ((((BtlAttachWork *)work)->flags & 0x8000) == 0) {
        index = 0;
        count = (u16)(count & 0xFFFF);
        while ((u16)index < count) {
            if (*entries != NULL) {
                mdlEffectFlushTreeFrame((s32)*entries);
            }
            index = (index + 1) & 0xFFFF;
            entries++;
        }
        return;
    }
    oldState = TnGetTableBase();
    TnSetTableBase((s32)D_005DC824);
    task = PrimAllocQueueNode();
    ((PrimQueueNode *)task)->unk00 = 0;
    ((PrimQueueNode *)task)->unk04 = 0;
    ((PrimQueueNode *)task)->callback = (void *)btlFormationCameraFrame;
    ((PrimQueueNode *)task)->argument.data = iGpffffb3ac;
    PrimAppendNode(D_00794AE0, task);
    index = 0;
    count = (u16)(count & 0xFFFF);
    while ((u16)index < count) {
        if (*entries != NULL) {
            mdlEffectFlushTreeFrame((s32)*entries);
        }
        index = (index + 1) & 0xFFFF;
        entries++;
    }
    TnSetTableBase(oldState);
    task = PrimAllocQueueNode();
    ((PrimQueueNode *)task)->unk00 = 0;
    ((PrimQueueNode *)task)->unk04 = 0;
    ((PrimQueueNode *)task)->callback = (void *)btlFormationCameraUpdate;
    ((PrimQueueNode *)task)->argument.data = iGpffffb3ac;
    PrimAppendNode(D_00794C00, task);
}


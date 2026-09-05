/* IDA-backed probe, not a production definition.
 * Source: docs/ida_headstart/src/Graphics/Model/mdlManager.c:1542-1684.
 * Measured: 1220B/1232B, 30 fully relocated instruction differences and
 * 12 absent zero-tail bytes (reloc-masked word score 33).
 * Residual: successful-loop animation/interpolator allocation.
 * Replay in mdlManager.c context. Promotion must also preserve raw s32
 * caller arguments at the narrow setup-parameter boundary; an ANSI narrow
 * definition alone would change the now-promoted dispatch caller.
 */
typedef struct MdlSetupResource {
    MdlAnimResourceEntry *entries;
    u32 unknown04;
    s32 *objects;
    u16 count;
    u16 unknown0e;
} MdlSetupResource;
typedef struct MdlSetupState {
    u16 flags;
    u8 phase;
    u8 unknown03;
    s16 index;
    u8 unknown06[6];
    f32 time;
    f32 elapsed;
    u16 blend;
    u16 unknown16;
    MdlSetupResource *resource;
} MdlSetupState;
typedef struct MdlSetupScheme {
    s32 type;
    s32 interpSize;
    s32 frameSize;
    void *apply;
    RtAnimKeyFrameBlendCallBack blend;
    void *interpolate;
} MdlSetupScheme;
struct RtAnimAnimation {
    MdlSetupScheme *scheme;
    s32 frameCount;
    s32 flags;
    f32 duration;
    void *frames;
    void *customData;
};
extern RtAnimAnimation *func_003d6170(void *, u32);
extern s32 func_003d5750(RtAnimAnimation *);
extern void func_003d7c50(RtAnimAnimation *);
extern void func_003d7cd0(RtAnimAnimation *);
extern void func_003d8070();
extern void func_0039a700();
extern void func_00399bf0();
extern s32 iGpffffb74c;
static inline void mdlSetupDetach(u32 *object) {
    RtAnimInterpolator *interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
    if (interpolator != 0) {
        func_003d7c50(interpolator->pCurrentAnim);
        func_003d5830(interpolator);
        *(u32 *)((u8 *)*object + iGpffffb74c + 12) = 0;
    }
}
// FUN_00475350
void func_00475350(void *clump, MdlSetupState *state, s16 index, u16 blend, u16 flags)
{
    MdlSetupResource *resource;
    u32 *object;
    u32 name;
    RtAnimAnimation *animation;
    RtAnimInterpolator *interpolator;
    s32 special;
    if (state->resource != 0) {
        state->flags &= ~1u;
        state->flags |= flags & 0xffff & 1;
        state->phase = 0;
        state->elapsed = 0;
        if (blend > 0 && state->index != -1 && state->resource != 0 &&
            state->index < state->resource->count && state->resource->entries[state->index].resource != 0 &&
            state->resource != 0 && (s64)index < state->resource->count && state->resource->entries[index].resource != 0)
            state->blend = blend;
        else
            state->blend = 0;
        resource = state->resource;
        if (resource != 0 && (s64)index < resource->count && resource->entries[index].resource != 0) {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object) {
                switch (func_00399d80(*object)) {
                case 5: case 6: func_0039a700(*object, 0, 0); break;
                }
                name = func_00474ce0((void *)*object);
                if (name != 0) {
                    animation = func_003d6170(((MdlAnimResourceEntry *)addOff((s32)index * 8, (u32)state->resource->entries))->resource, name);
                    if (animation != 0) {
                        special = func_00442c30(name, &gp0xffff9d10, 5) == 0;
                        interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        if (interpolator != 0) {
                            s32 nodeCount;
                            func_003d7c50(interpolator->pCurrentAnim);
                            nodeCount = interpolator->numNodes;
                            if (nodeCount != func_003d5750(animation) || interpolator->currentInterpKeyFrameSize != animation->scheme->interpSize) {
                                func_003d5830(interpolator);
                                interpolator = 0;
                            }
                        }
                        if (interpolator != 0) {
                            func_003d5840(interpolator, animation);
                            func_003d7cd0(animation);
                        } else {
                            func_003d8070(*object, animation, 1);
                            interpolator = (RtAnimInterpolator *)func_003d8130(*object, 1);
                        }
                        if (func_003d5750(animation) == 1) func_00399bf0(*object, 5);
                        else func_00399bf0(*object, 6);
                        if (special == 1) {
                            func_003d5990(interpolator, func_00474ba0, state);
                            interpolator->keyFrameBlendCB = (RtAnimKeyFrameBlendCallBack)func_00474a50;
                            interpolator->keyFrameInterpolateCB = (void *)func_00474a90;
                        } else {
                            func_003d5990(interpolator, func_00474af0, state);
                            interpolator->keyFrameBlendCB = animation->scheme->blend;
                            interpolator->keyFrameInterpolateCB = animation->scheme->interpolate;
                        }
                    } else mdlSetupDetach(object);
                }
            }
            func_003bff30(clump, func_00475090, 0);
            func_003bff30(clump, func_00474f40, 0);
        } else {
            s32 *objects = resource->objects;
            for (object = (u32 *)func_003df890(objects); object != (u32 *)func_003df8a0(objects); ++object)
                if (func_00474ce0((void *)*object) != 0) mdlSetupDetach(object);
        }
        state->index = index;
    }
}


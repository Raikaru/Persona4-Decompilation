/* Rejected IDA-first candidate: object 1300B / window 1328B / 215 reloc-masked differing words.
 * Requirements and provenance: IDA_model_followthrough.json. Not promoted. */
#include "rw/std/stddef.h"

/* Requires the existing MdlDispatchAnimEntry/Table definitions hoisted here,
 * with unknown[12] refined to u32 unknown44; u8* blendControl;
 * s32* startFrame. No helper ABI changes are required. */
void func_004740c0(u8* layer, s32 animation, s32 blendTicks, s32 flags)
{
    u32 narrowFlags;
    MdlDispatchAnimTable* table;
    u8* animationFields;
    s32 currentIndex;
    s32 currentOffset;
    s32 nextIndex;
    s32 nextOffset;
    void* clip;
    u8* hierarchy;
    RtAnimInterpolator* base;
    s32* startFrame;
    u8* control;

    *(u16*)layer &= ~1u;
    narrowFlags = (u16)flags;
    *(u16*)layer |= narrowFlags & 1;
    layer[2] = 0;
    if ((u16)blendTicks != 0 &&
        (currentIndex = *(s16*)(layer + 4)) != -1 &&
        (table = *(MdlDispatchAnimTable**)(layer + 0x34)) != 0 &&
        currentIndex < table->count &&
        (currentOffset = currentIndex * (s32)sizeof(MdlDispatchAnimEntry),
         animationFields = (u8*)table->entries + offsetof(MdlDispatchAnimEntry, animation),
         clip = *(void**)(animationFields + currentOffset)) != 0 &&
        clip != D_00922BC0_abs &&
        *(MdlDispatchAnimTable**)(layer + 0x34) != 0 &&
        (nextIndex = (s16)animation) < table->count &&
        (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
         clip = *(void**)(animationFields + nextOffset)) != 0 &&
        clip != D_00922BC0_abs) {
        if (*(RtAnimInterpolator**)(layer + 0x24) == 0) {
            hierarchy = *(u8**)(layer + 0x20);
            base = *(RtAnimInterpolator**)(hierarchy + 0x20);
            *(RtAnimInterpolator**)(layer + 0x24) = (RtAnimInterpolator*)
                func_003d5790(*(s32*)(hierarchy + 4), base->maxInterpKeyFrameSize);
        }
        if (*(RtAnimInterpolator**)(layer + 0x28) == 0) {
            hierarchy = *(u8**)(layer + 0x20);
            base = *(RtAnimInterpolator**)(hierarchy + 0x20);
            *(RtAnimInterpolator**)(layer + 0x28) = (RtAnimInterpolator*)
                func_003d5790(*(s32*)(hierarchy + 4), base->maxInterpKeyFrameSize);
        }
        func_003d5840(*(RtAnimInterpolator**)(layer + 0x24),
            (*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].animation);
        func_003d5840(*(RtAnimInterpolator**)(layer + 0x28),
            ((MdlDispatchAnimEntry*)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries + nextOffset))->animation);
        if (*(MdlDispatchAnimTable**)(layer + 0x34) == 0 ||
            (*(MdlDispatchAnimTable**)(layer + 0x34))->unknown == 0) {
            func_003d59a0(*(RtAnimInterpolator**)(layer + 0x24),
                *(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20));
        } else {
            func_003d5e40(*(u8**)(layer + 0x24), *(f32*)(layer + 0x0c));
        }
        startFrame = *(s32**)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries +
            offsetof(MdlDispatchAnimEntry, startFrame) + nextOffset);
        if (startFrame != 0) {
            func_003d5e40(*(u8**)(layer + 0x28), iGpffff8040 * (f32)*startFrame);
        }
        *(s16*)(layer + 0x10) = *(s16*)(layer + 4);
        *(f32*)(layer + 0x14) = *(f32*)(layer + 0x0c);
        *(u16*)(layer + 0x18) = blendTicks;
        *(f32*)(layer + 0x1c) = 0.0f;
    } else {
        table = *(MdlDispatchAnimTable**)(layer + 0x34);
        if (table != 0 && (nextIndex = (s16)animation) < table->count &&
            (nextOffset = nextIndex * (s32)sizeof(MdlDispatchAnimEntry),
             clip = *(void**)((u8*)table->entries +
                 offsetof(MdlDispatchAnimEntry, animation) + nextOffset)) != 0 &&
            clip != D_00922BC0_abs) {
            func_003d5840(*(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20), clip);
            startFrame = *(s32**)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries +
                offsetof(MdlDispatchAnimEntry, startFrame) + nextOffset);
            if (startFrame == 0) {
                func_003d5e40(*(u8**)(*(u8**)(layer + 0x20) + 0x20), 0.0f);
            } else {
                func_003d5e40(*(u8**)(*(u8**)(layer + 0x20) + 0x20),
                    iGpffff8040 * (f32)*startFrame);
            }
            func_003d5990(*(RtAnimInterpolator**)(*(u8**)(layer + 0x20) + 0x20),
                func_00473350, layer);
        }
        *(u16*)(layer + 0x18) = 0;
        *(f32*)(layer + 0x1c) = 1.0f;
    }
    *(u16*)(layer + 0x54) &= ~0x800u;
    if (*(u16*)(layer + 0x54) & 0x81e0) {
        currentOffset = *(s16*)(layer + 4) * (s32)sizeof(MdlDispatchAnimEntry);
        control = *(u8**)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries +
            offsetof(MdlDispatchAnimEntry, blendControl) + currentOffset);
        if (control != 0) {
            *(f32*)(control + 0x34) = 0.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x38) = 1.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x2c) = 1.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x20) = 0.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x24) = 0.0f;
            *(f32*)((*(MdlDispatchAnimTable**)(layer + 0x34))->entries[*(s16*)(layer + 4)].blendControl + 0x28) = 0.0f;
        }
        nextOffset = (s16)animation * (s32)sizeof(MdlDispatchAnimEntry);
        control = *(u8**)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries +
            offsetof(MdlDispatchAnimEntry, blendControl) + nextOffset);
        if (control != 0) {
            *(f32*)(control + 0x34) = (f32)(u32)*(u16*)(layer + 0x18);
            *(f32*)(((MdlDispatchAnimEntry*)((u8*)(*(MdlDispatchAnimTable**)(layer + 0x34))->entries +
                nextOffset))->blendControl + 0x38) = *(f32*)(layer + 0x1c);
        }
    }
    control = *(u8**)(layer + 0x38);
    if (control != 0) {
        nextIndex = (s16)animation;
        *(void**)(control + 0x1c) = (*(void***)(control + 0x14))[nextIndex];
        if (narrowFlags & 0x20) {
            clip = 0;
        } else {
            clip = (*(void***)(control + 0x20))[nextIndex];
        }
        *(void**)(control + 0x28) = clip;
        *(s32*)(control + 0x2c) = 1;
        *(u16*)(control + 0x30) = blendTicks;
    }
    *(f32*)(layer + 0x0c) = 0.0f;
    *(s16*)(layer + 4) = animation;
}

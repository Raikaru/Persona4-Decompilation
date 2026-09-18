/* R3a blez-stack-alpha: 1908B / 1920B, 32 relocation-masked differing
 * words. Fresh relocation-aware replay finds 30 executable differences at
 * 0x48c..0x500 and three missing zero-tail words. Masking hides a jal/lw
 * mismatch at 0x4f4. Extra accumulator-zero transfers offset a shared
 * rather than duplicated draw-call branch. Not an instruction match or a
 * semantic runtime acceptance result. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* IDA mdlManager.c:2696-2870; retail 00479100-00479870.
 * Integration requirements, including attachment fields and the corrected
 * color-forwarding wrapper, are recorded in IDA_model_followthrough.json. */
/* Queue command uses k_draw.c raw offsets (obj+8/0x0C/0x10/0x14/0x18/0x1A/0x1C); no new struct. */

extern u8* func_00460990(void);
extern void func_00460ac0(void*, void*);
extern void func_00478a30(u8*, s32);
extern void func_00479030(u8*, u8*);
extern void func_0047d8a0(u8**, s32);
extern void func_0047d7e0(s32, u8**);
extern void func_0047ddd0(u8*, const u8*);
extern void func_0047dd70(u8*, u8*);
extern void func_0047a220(void*, void*);

// FUN_00479100
void func_00479100(void* queue, u8* model)
{
    u8* command;
    u8* renderCommand;
    u32 flags;
    u16 layer;
    s32 childIndex;
    RwRGBA color;
    u32 uncolored;
    u32 childUncolored;

    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x1000) == 0)
        return;
    if ((flags & 4) == 0)
        func_00478a30(model, (flags & 1) == 0);
    flags = *(u32*)(model + 0xd8);
    if ((flags & 2) != 0)
        return;
    if (((Model*)model)->color.alpha <= 0)
        return;

    if ((flags & 1) != 0 && (flags & 0x8000) == 0)
    {
        command = func_00460990();
        *(u16*)(command + 0x18) = 0x1c;
        *(void**)(command + 0x1c) = model;
        func_00460ac0(*(void**)(model + 0x2f8), command);
    }
    renderCommand = func_00460990();
    if (*(void**)(model + 0xe0) != 0)
    {
        *(void**)(renderCommand + 8) = (void*)func_00478ec0;
        *(void**)(renderCommand + 0x10) = model;
    }
    else
    {
        *(void**)(renderCommand + 8) = (void*)func_00479030;
        *(void**)(renderCommand + 0x10) = model;
    }
    *(void**)(renderCommand + 0x0C) = (void*)func_00479080;
    *(void**)(renderCommand + 0x14) = model;
    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x20) == 0 || ((Model*)model)->color.alpha == 255)
    {
        if (*(void**)(model + 0xe0) == 0)
        {
            *(u16*)(renderCommand + 0x18) = 9;
            *(void**)(renderCommand + 0x1C) = ((Model*)model)->clump;
            func_00460ac0(queue, renderCommand);
        }
        else
        {
            if ((flags & 0x18) == 0x18)
                *(u16*)(renderCommand + 0x1A) &= 0xFFFD;
            else
                *(u16*)(renderCommand + 0x1A) |= 2;
            *(u16*)(renderCommand + 0x18) = 5;
            *(void**)(renderCommand + 0x1C) = *(void**)(model + 0xe0);
            func_00460ac0(queue, renderCommand);
        }
    }
    else
    {
        *(u16*)(renderCommand + 0x18) = 0x1B;
        *(void**)(renderCommand + 0x1C) = model;
        func_00460ac0(queue, renderCommand);
    }

    if (*(void**)(model + 0x2cc) != 0)
    {
        flags = *(u32*)(model + 0xd8);
        if ((flags & 0x20000) != 0)
            goto layers;
        if ((flags & 0x8000) != 0)
        {
            void* clump = ((Model*)model)->clump;
            uncolored = 1;
            func_003bff30(clump, (KClumpCallback)func_004772a0, &uncolored);
            if (uncolored != 0)
                goto layers;
        }
        if ((*(u32*)(model + 0xd8) & 0x80) == 0)
        {
            f32 red;
            f32 green;
            f32 blue;
            f32 alpha;
            f32 modulatedAlpha;
            f32 maximum;
            f32 bias;
            red = iGpffff8044 * (f32)(u32)((Model*)model)->color.red;
            green = iGpffff8044 * (f32)(u32)((Model*)model)->color.green;
            blue = iGpffff8044 * (f32)(u32)((Model*)model)->color.blue;
            alpha = iGpffff8044 * (f32)(u32)((Model*)model)->color.alpha;
            red *= iGpffff8044 * (f32)(u32)model[0x300];
            green *= iGpffff8044 * (f32)(u32)model[0x301];
            blue *= iGpffff8044 * (f32)(u32)model[0x302];
            modulatedAlpha = alpha * (iGpffff8044 * (f32)(u32)model[0x303]);
            maximum = 255.0f;
            bias = 0.5f;
            color.red = (s32)(bias + maximum * red);
            color.green = (s32)(bias + maximum * green);
            color.blue = (s32)(bias + maximum * blue);
            color.alpha = (s32)(bias + maximum * modulatedAlpha);
            func_0047d8a0(*(u8***)(model + 0x2cc), (s32)&color);
            if (color.alpha <= 0)
                goto layers;
        }
        func_0047d7e0(*(s32*)(model + 0x2fc), *(u8***)(model + 0x2cc));
    }

layers:
    for (layer = 0; layer < 2; ++layer)
    {
        MdlCloneAttachmentTable** slot = &((MdlCloneLayerView*)(model + 0xec + layer * 0xa4))->attachments;
        MdlCloneAttachmentTable* attachments = *slot;
        if (attachments != 0 && (*(u32*)(model + 0xd8) & 0x20000) == 0)
        {
            u8* attachmentQueue;
            void* draw;
            attachments->scale = ((Model*)model)->scale;
            if ((*(u32*)(model + 0xd8) & 0x80) == 0)
                (*slot)->color = ((Model*)model)->color;
            attachments = *slot;
            attachmentQueue = *(u8**)(model + 0x2fc);
            draw = attachments->primaryDraw;
            if (draw != 0)
            {
                func_0047d8a0(draw, (s32)&attachments->color);
                func_0047d7e0((s32)attachmentQueue, attachments->primaryDraw);
            }
            draw = attachments->secondaryDraw;
            if (draw != 0)
            {
                func_0047ddd0(draw, (const u8*)&attachments->color);
                func_0047dd70(attachmentQueue, attachments->secondaryDraw);
            }
        }
    }
    for (childIndex = 0; (u16)childIndex < 5; childIndex = (u16)(childIndex + 1))
    {
        s32 index = (u16)childIndex;
        u8* childBase = model + index * sizeof(MdlWpnSlot);
        if ((childBase[0x28c] & 1) != 0)
        {
            void** child = (void**)(childBase + 0x290);
            if (*child != 0 && func_0047ae90(model, childIndex) != 0)
            {
                void* childClump = ((Model*)*child)->clump;
                childUncolored = 1;
                func_003bff30(childClump, (KClumpCallback)func_004772a0, &childUncolored);
                if (childUncolored == 0)
                    *(u32*)((u8*)*child + 0xd8) &= ~0x20000u;
                else
                    *(u32*)((u8*)*child + 0xd8) |= 0x20000;
                func_0047a220(*child, &((Model*)model)->color);
                if ((*(u32*)(model + 0xd8) & 0x20) == 0)
                    *(u32*)((u8*)*child + 0xd8) &= ~0x20u;
                else
                    *(u32*)((u8*)*child + 0xd8) |= 0x20;
                func_00479100(queue, *child);
            }
        }
    }
}

#pragma pop

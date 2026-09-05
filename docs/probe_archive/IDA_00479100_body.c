/* IDA mdlManager.c:2696-2870; retail 00479100-00479870.
 * Integration requirements, including attachment fields and the corrected
 * color-forwarding wrapper, are recorded in IDA_model_followthrough.json. */
typedef struct MdlRenderCommand {
    u8 unknown00[8];
    union {
        void (*model)(void*, MdlFlags78ec0*);
        void (*clump)(u8*, u8*);
    } before;                       /* 0x08 */
    void (*after)(void*, void*);     /* 0x0c */
    void* beforeData;                /* 0x10 */
    void* afterData;                 /* 0x14 */
    u16 operation;                  /* 0x18 */
    u16 flags;                      /* 0x1a */
    void* object;                   /* 0x1c */
} MdlRenderCommand;

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
    MdlRenderCommand* command;
    u32 flags;
    u16 layer;
    u16 childIndex;
    u32 childUncolored;
    u32 uncolored;
    RwRGBA color;

    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x1000) == 0)
        return;
    if ((flags & 4) == 0)
        func_00478a30(model, (flags & 1) == 0);
    flags = *(u32*)(model + 0xd8);
    if ((flags & 2) != 0 || ((Model*)model)->color.alpha == 0)
        return;

    if ((flags & 1) != 0 && (flags & 0x8000) == 0) {
        command = (MdlRenderCommand*)func_00460990();
        command->operation = 0x1c;
        command->object = model;
        func_00460ac0(*(void**)(model + 0x2f8), command);
    }
    command = (MdlRenderCommand*)func_00460990();
    if (*(void**)(model + 0xe0) != 0) {
        command->before.model = func_00478ec0;
        command->beforeData = model;
    } else {
        command->before.clump = func_00479030;
        command->beforeData = model;
    }
    command->after = func_00479080;
    command->afterData = model;
    flags = *(u32*)(model + 0xd8);
    if ((flags & 0x20) != 0 && ((Model*)model)->color.alpha != 255) {
        command->operation = 0x1b;
        command->object = model;
        func_00460ac0(queue, command);
    } else if (*(void**)(model + 0xe0) == 0) {
        command->operation = 9;
        command->object = ((Model*)model)->clump;
        func_00460ac0(queue, command);
    } else {
        if ((flags & 0x18) == 0x18)
            command->flags &= 0xfffd;
        else
            command->flags |= 2;
        command->operation = 5;
        command->object = *(void**)(model + 0xe0);
        func_00460ac0(queue, command);
    }

    if (*(void**)(model + 0x2cc) != 0 &&
        (*(u32*)(model + 0xd8) & 0x20000) == 0) {
        if ((*(u32*)(model + 0xd8) & 0x8000) != 0) {
            uncolored = 1;
            func_003bff30(((Model*)model)->clump, func_004772a0, &uncolored);
            if (uncolored != 0)
                goto layers;
        }
        if ((*(u32*)(model + 0xd8) & 0x80) == 0) {
            f32 red;
            f32 green;
            f32 blue;
            f32 alpha;
            red = iGpffff8044 * (f32)(u32)((Model*)model)->color.red;
            green = iGpffff8044 * (f32)(u32)((Model*)model)->color.green;
            blue = iGpffff8044 * (f32)(u32)((Model*)model)->color.blue;
            alpha = iGpffff8044 * (f32)(u32)((Model*)model)->color.alpha;
            red *= iGpffff8044 * (f32)(u32)model[0x300];
            green *= iGpffff8044 * (f32)(u32)model[0x301];
            blue *= iGpffff8044 * (f32)(u32)model[0x302];
            alpha *= iGpffff8044 * (f32)(u32)model[0x303];
            color.red = (s32)(0.5f + 255.0f * red);
            color.green = (s32)(0.5f + 255.0f * green);
            color.blue = (s32)(0.5f + 255.0f * blue);
            color.alpha = (s32)(0.5f + 255.0f * alpha);
            func_0047d8a0(*(u8***)(model + 0x2cc), (s32)&color);
            if (color.alpha == 0)
                goto layers;
        }
        func_0047d7e0(*(s32*)(model + 0x2fc), *(u8***)(model + 0x2cc));
    }

layers:
    for (layer = 0; layer < 2; ++layer) {
        MdlCloneAttachmentTable** slot =
            &((MdlCloneLayerView*)(model + 0xec + layer * 0xa4))->attachments;
        MdlCloneAttachmentTable* attachments = *slot;
        if (attachments != 0 && (*(u32*)(model + 0xd8) & 0x20000) == 0) {
            u8* attachmentQueue;
            attachments->scale = ((Model*)model)->scale;
            if ((*(u32*)(model + 0xd8) & 0x80) == 0)
                (*slot)->color = ((Model*)model)->color;
            attachments = *slot;
            attachmentQueue = *(u8**)(model + 0x2fc);
            if (attachments->primaryDraw != 0) {
                func_0047d8a0(attachments->primaryDraw, (s32)&attachments->color);
                func_0047d7e0((s32)attachmentQueue, attachments->primaryDraw);
            }
            if (attachments->secondaryDraw != 0) {
                func_0047ddd0(attachments->secondaryDraw, (const u8*)&attachments->color);
                func_0047dd70(attachmentQueue, attachments->secondaryDraw);
            }
        }
    }
    for (childIndex = 0; childIndex < 5; ++childIndex) {
        MdlWpnSlot* slot = &((Model*)model)->attachedWpns[childIndex];
        if ((slot->flags & 1) != 0) {
            if (slot->wpnMdl != 0 && func_0047ae90(model, childIndex) != 0) {
                childUncolored = 1;
                func_003bff30(((Model*)slot->wpnMdl)->clump,
                             func_004772a0, &childUncolored);
                if (childUncolored != 0)
                    *(u32*)((u8*)slot->wpnMdl + 0xd8) |= 0x20000;
                else
                    *(u32*)((u8*)slot->wpnMdl + 0xd8) &= ~0x20000u;
                func_0047a220(slot->wpnMdl, &((Model*)model)->color);
                if ((*(u32*)(model + 0xd8) & 0x20) != 0)
                    *(u32*)((u8*)slot->wpnMdl + 0xd8) |= 0x20;
                else
                    *(u32*)((u8*)slot->wpnMdl + 0xd8) &= ~0x20u;
                func_00479100(queue, slot->wpnMdl);
            }
        }
    }
}

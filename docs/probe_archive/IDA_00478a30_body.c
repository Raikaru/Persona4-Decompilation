/* IDA mdlManager.c:2548-2693; retail func_00478a30.s:1-304.
 * Requires the MdlCloneAttachmentTable refinements in IDA_model_followthrough.json.
 * Public ABI follows src/promoted/code1_0047.c. */
#pragma push
/* Retain per-phase matrix addresses instead of a function-wide cached base. */
#pragma opt_common_subs off
// FUN_00478A30
void func_00478a30(u8* mdl, s32 tick)
{
    RwMatrix matrix;
    void* frame;
    u8* previousLayer;
    u32 animationLayer;
    u32 switchLayer;
    u32 updateLayer;
    MdlCloneAttachmentTable* attachments;
    u32 child;

    if ((*(u32*)(mdl + 0xD8) & 0x1000) != 0) {
        frame = *(void**)((u8*)((Model*)mdl)->clump + 4);
        RwMatrixMultiply(&matrix, &((Model*)mdl)->identityMat, mdl);
        func_003e9cb0(frame, &matrix, 0);
        func_0047aee0((Model*)mdl, &matrix);
        previousLayer = 0;
        if (func_0047a9d0(mdl) != 0) {
            func_0047aa10(mdl, &((Model*)mdl)->scale);
        }
        for (animationLayer = 0; animationLayer < 2; animationLayer++) {
            if (func_00479ca0(mdl, (u16)animationLayer) != 0) {
                previousLayer = func_00473b20(mdl + animationLayer * 0xA4 + 0xEC,
                                             previousLayer, tick);
            }
        }
        *(u32*)(mdl + 0xD8) |= 0x80000;
        func_00475820(mdl + 0x23C, mdl + 0xEC);
        for (switchLayer = 0; switchLayer < 2; switchLayer++) {
            attachments = ((MdlCloneLayerView*)(mdl + switchLayer * 0xA4 + 0xEC))->attachments;
            if (attachments != 0) {
                if (attachments->nextPrimary != attachments->primaryDraw) {
                    if (attachments->primaryDraw != 0) {
                        func_0047dae0((u32)attachments->primaryDraw);
                    }
                    if (attachments->nextPrimary != 0) {
                        func_0047da30(attachments->nextPrimary);
                    }
                    attachments->primaryDraw = attachments->nextPrimary;
                }
                if (attachments->pendingSecondary != 0) {
                    if (attachments->secondaryDraw != 0) {
                        func_0047de50((u32)attachments->secondaryDraw);
                    }
                    if (attachments->nextSecondary != 0) {
                        func_0047de00((u32)attachments->nextSecondary, mdl);
                    }
                    attachments->secondaryDraw = attachments->nextSecondary;
                    attachments->pendingSecondary = 0;
                }
            }
        }
        if (tick != 0) {
            if (*(u32*)(mdl + 0x2CC) != 0) {
                func_0047d900(*(u32*)(mdl + 0x2CC), &((Model*)mdl)->scale);
                func_0047d540(*(u32*)(mdl + 0x2CC), mdl);
            }
            for (updateLayer = 0; updateLayer < 2; updateLayer++) {
                attachments = ((MdlCloneLayerView*)(mdl + updateLayer * 0xA4 + 0xEC))->attachments;
                if (attachments != 0) {
                    if (attachments->primaryDraw != 0 && attachments->delay == 0) {
                        func_0047d900((u32)attachments->primaryDraw, &attachments->scale);
                        func_0047d540((u32)attachments->primaryDraw, mdl);
                    }
                    if (attachments->secondaryDraw != 0 && attachments->delay == 0) {
                        func_0047dd40((u32)attachments->secondaryDraw, mdl);
                    }
                    if (attachments->delay != 0) {
                        attachments->delay--;
                    }
                }
            }
        }
        func_0047ed60(mdl + 0x2D0);
        for (child = 0; child < 5; child++) {
            u8* childBase = mdl + child * 0xC;
            if ((*(u8*)(childBase + 0x28C) & 1) != 0) {
                void** childSlot = (void**)(childBase + 0x290);
                if (*childSlot != 0 && func_0047ae90(mdl, (u16)child) != 0) {
                    ((Model*)*childSlot)->identityMat = ((Model*)mdl)->identityMat;
                    if (tick != 0) {
                        s32* frameId = (s32*)(childBase + 0x294);
                        if (*frameId != -1) {
                            void* childMatrix = func_0047a2f0(*childSlot);
                            func_0047a510(mdl, *frameId, childMatrix);
                        } else {
                            ((Model*)*childSlot)->mat = ((Model*)mdl)->mat;
                        }
                    }
                    {
                        void** updateSlot = (void**)(mdl + child * 0xC + 0x290);
                        func_0047a0e0(*updateSlot, 0, *(f32*)(mdl + 0xF4));
                        func_00478a30(*updateSlot, tick);
                    }
                }
            }
        }
    }
}
#pragma pop

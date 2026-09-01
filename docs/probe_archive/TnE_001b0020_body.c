/* object_size=564B; retail_window=576B; normalized_diff=25 words; differing_words=16; differing_offsets=0x148,0x180,0x1A4-0x1C0,0x1CC-0x1D4. Best legal plain-C body before restoration. Narrow unsigned action_id reproduces retail daddiu opcode; residual is action/source/table register coloring. Ruled out: signed/narrow mode variants, source-id width variants, declaration-order permutations, split action locals, source-pointer temporary, table-pointer forms, direct type guard, propagation pragma, integer unit alias, source pointer aliases, alternate helper declaration/call forms except retained interleaved float ABI declaration. */
void func_001b0020(u8 *arg0)
{
    extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
    extern u8 *func_001973f0(u8 *arg0, f32 *arg1, f32 arg4, s32 arg2, u32 arg3);
    extern s32 func_001b1510(void);
    extern f32 func_001ec250(f32 *arg0, f32 *arg1);
    extern s32 func_00232710(u32 arg0, u32 arg1);
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    f32 vector[3];
    s32 mode;
    u16 source_id;
    u16 action_id;
    u8 type;
    u8 *unit;
    u8 *packet;
    u8 *table;
    unit = *(u8 **)(arg0 + 0x30);
    *(s32 *)(arg0 + 0x41C) = 0;
    if (func_002428f0(*(u32 *)(unit + 0xA64), 0) != 0) {
        if ((*(s32 *)(unit + 0x9C) & 0x40) != 0) {
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x400000;
            *(u16 *)(iGpffffb3ac + 0x18) = *(u16 *)(iGpffffb3ac + 0x18) | 6;
        }
        func_001b0800(arg0, 1);
        goto done;
    }
    if (arg0 == (u8 *)func_001b1510()) {
        func_001b0800(arg0, 1);
        goto done;
    }
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x400000) == 0 ||
         (*(u16 *)(iGpffffb3ac + 0x18) & 2) == 0) &&
        func_00232710(*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180001) == 0) {
        func_00194ff0(unit, vector, NULL, NULL);
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0)
            *(s32 *)(arg0 + 0x41C) = 1;
        if (func_001ec250((f32 *)(unit + 4), vector) > 75.0f) {
            action_id = 2;
            mode = (s32)((((*(u8 *)(iGpffffb3b8 +
                (*(u16 *)(arg0 + 0x6E) * 0x28)) & 2) != 0) ^ 1) & 0xFFFF);
            source_id = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 2);
            type = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
            switch (type) {
            case 0:
                break;
            case 1:
                table = iGpffffb3cc;
                action_id = *(u16 *)(table +
                    (source_id & 0xFFFF) * 0xE8 +
                    (mode & 0xFFFF) * 4 + 0x24);
                break;
            default:
                break;
            }
            packet = func_001973f0(*(u8 **)(arg0 + 0x30), vector,
                                   D_005F6D20[action_id & 0xFFFF], 0, mode);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 1);
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    }
done:
    ;
}

/* object 568B, retail window 576B, normalized_diff 115; instruction deficit 2; classification: operand-order/helper probe regressed from best nd10; saved registers 2 (s1=arg0, s0=unit), args (u8 *arg0); declarations block scope; ruled out: missing block, phantom double, floor families, schedule pragma. */
void func_001b0020(u8 *arg0)
{
    extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
    extern u8 *func_001973f0(u8 *arg0, f32 *arg1, s32 arg2, u32 arg3, f32 arg4);
    extern s32 func_001b1510(void);
    extern f32 func_001ec250(f32 *arg0, f32 *arg1);
    extern s32 func_00232710(u32 arg0, u32 arg1);
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    f32 vector[3];
    u16 action_id;
    u32 source_id;
    u8 type;
    s32 mode;
    u8 *unit;
    u8 *packet;
    u32 table;
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
            mode = (s32)((((*(u8 *)(iGpffffb3b8 + (*(u16 *)(arg0 + 0x6E) * 0x28)) & 2) != 0) ^ 1) & 0xFFFF);
            source_id = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 2);
            type = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
            switch (type) {
            case 0:
                break;
            case 1:
                table = (u32)iGpffffb3cc;
                action_id = *(u16 *)func_001bf3a0_add((source_id & 0xFFFF) * 0xE8 + (mode & 0xFFFF) * 4 + 0x24, (u8 *)table);
                break;
            default:
                break;
            }
            packet = func_001973f0(*(u8 **)(arg0 + 0x30), vector, 0, mode, D_005F6D20[action_id & 0xFFFF]);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 1);
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    }
done:
    ;
}

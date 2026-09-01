/* object 424/window 432, normalized_diff 15; differing offsets 0x6c,0x70,0x74,0x80-0xa4; classification: global-load/address-materialization scheduling residual; undersized by 8 bytes; ruled out exact 0x60 frame/prologue and saved-register count, exact loop layout, aggregate width, callee prototype, volatile field ordering, and COP1 floor. */
s32 func_0026ba60(u16 *arg0)
{
    typedef struct {
        u64 sp40;
        f32 sp48;
        u32 pad4c;
        u8 *sp50;
        u8 *sp54;
        u8 *sp58;
    } LocalFrame;
    LocalFrame frame;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    s32 temp_2;
    s32 index;
    s32 offset;
    s32 var_17;
    u8 *temp_3;
    u8 *var_16;

    var_16 = (u8 *)func_001452b0(0x15);
    temp_3 = (u8 *)PTR_DAT_00762ea0;
    index = *(volatile s32 *)(temp_3 + 0);
    offset = *(volatile s32 *)(temp_3 + 4);
    temp_2 = *(s32 *)((u8 *)D_005F08B0 + (index * 4));
    if (temp_2 == 0) {
        return 0;
    }
    var_17 = *(u8 *)((u8 *)temp_2 + offset);
    for (; var_16 != NULL; var_16 = *(u8 **)(var_16 + 0x138)) {
        frame.sp40 = *(u64 *)D_0063B080;
        frame.sp48 = *(f32 *)D_0063B088;
        frame.sp50 = var_16 + 0x15C;
        frame.sp54 = var_16 + 0x168;
        frame.sp58 = var_16 + 0x174;
        if ((func_00168ec0(arg0, &frame.sp50, &frame.sp40) == 1) &&
            (temp_f3 = *(f32 *)(frame.sp50 + 4),
             temp_f2 = *(f32 *)((u8 *)arg0 + 4),
             (temp_f2 < (100.0f + temp_f3))) &&
            !(temp_f2 <= (temp_f3 - 100.0f))) {
            var_17 = *(s32 *)(var_16 + 0x18C);
            break;
        }
        frame.sp50 = var_16 + 0x168;
        frame.sp54 = var_16 + 0x174;
        frame.sp58 = var_16 + 0x180;
        if ((func_00168ec0(arg0, &frame.sp50, &frame.sp40) == 1) &&
            (temp_f3_2 = *(f32 *)(frame.sp50 + 4),
             temp_f2_2 = *(f32 *)((u8 *)arg0 + 4),
             (temp_f2_2 < (100.0f + temp_f3_2))) &&
            !(temp_f2_2 <= (temp_f3_2 - 100.0f))) {
            var_17 = *(s32 *)(var_16 + 0x18C);
            break;
        }
    }
    return var_17;
}

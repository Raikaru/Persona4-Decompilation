/* object_size=216 window=224 normalized_diff=120 differing_offsets=20,21,22,23,24,25,26,27,45,53,56,59,60,61,62,63 classification=undersized candidate; ruled_out=retail frame 17504 and four saved s-registers matched by sp50[0x400]/sp450[0x4010], body follows raw candidate call sequence; no compiler floor observed */
s32 func_00409d30(u8 *arg0, u8 *arg1)
{
    extern s32 func_003f24a0(u8 *arg0);
    extern void func_003f07d0(u8 *arg0, u8 *arg1, f32 arg2);
    extern s32 func_003f17e0(u8 *arg0, s32 arg1, void *arg2);
    extern void func_003f1ce0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3,
                               u8 *arg4, u8 *arg5);
    extern void func_004220d8(u8 *arg0, u8 *arg1);
    extern void func_00409150(u8 *arg0, void *arg1);
    extern void func_003f26c0(u8 *arg0);
    s32 var_18;
    s32 temp_19;
    u8 sp50[0x400];
    u8 sp450[0x4010];
    u8 *temp_16;

    var_18 = 0;
    temp_19 = 1 << *(s32 *)(arg0 + 0x14);
    if (func_003f24a0(sp450) != 0) {
        func_003f07d0(sp450, arg1, 1.0f);
        func_003f17e0(sp50, temp_19, sp450);
        temp_16 = *(u8 **)(arg0 + 4);
        func_003f1ce0(
            temp_16,
            *(s32 *)(arg0 + 0x18),
            *(s32 *)(arg0 + 0x14),
            1,
            sp450,
            arg1);
        func_004220d8(
            temp_16,
            temp_16 + (*(s32 *)(arg0 + 0x18) * *(s32 *)(arg0 + 0x10)) + 0x7f);
        func_00409150(arg0, sp50);
        func_003f26c0(sp450);
        var_18 = 1;
    }
    return var_18;
}

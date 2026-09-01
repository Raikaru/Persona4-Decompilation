#pragma opt_common_subs off
// FUN_001ACBB0
void func_001acbb0(s64 *arg0)
{
    struct {
        s32 sp80;
        u8 pad[0x10];
    } locals;
    s32 temp_19;
    s32 temp_2_4;
    s32 temp_4;
    s32 var_17;
    s64 temp_20;
    s64 temp_21;
    s64 var_2;
    s64 var_2_2;
    u16 temp_3;
    u8 *temp_16;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    extern u8 func_00106600(s16 arg0);
    extern void func_00106620(s16 arg0, s32 arg1);
    extern u8 *func_001937f0(s32 arg0);
    extern u8 *func_00194b60(void);
    extern void func_001f0a10(u8 *arg0);
    extern u8 *func_001f36e0(s32 arg0, s32 arg1, void *arg2,
                             s16 arg3, s16 arg4);
    extern u8 *func_00202400(s32 arg0, s32 arg1);
    extern u8 *func_00202590(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_00202740(u8 *arg0);
    extern u32 func_00231f80(s32 arg0);
    extern u32 func_00231ed0(s32 arg0);
    extern u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2,
                              s16 arg3, s16 arg4, s16 arg5, s16 arg6,
                              s32 arg7, u16 arg8);

    temp_16 = *(u8 **)(u8 *)func_001a_add_offset(0x30, (s32)arg0);
    *(s32 *)(temp_16 + 0x9C) = *(s32 *)(temp_16 + 0x9C) & ~0x10;
    if (func_00193cd0(0xFF03) == 0) {
        temp_4 = *(s32 *)(u8 *)func_001a_add_offset(
            0xC, (s32)iGpffffb3ac);
        if (!(temp_4 & 0x80000)) {
            *(s32 *)(u8 *)func_001a_add_offset(
                0xC, (s32)iGpffffb3ac) = temp_4 | 0x80000;
            var_17 = 1;
        } else {
            var_17 = 0;
        }
        temp_3 = *(u16 *)(u8 *)func_001a_add_offset(0x3F4, (s32)arg0);
        switch (temp_3) {
        case 0x210:
            if (temp_16[0xA2] == 0) {
                var_2 = 0x3E;
            } else {
                var_2 = 0x3F;
            }
            break;
        case 0x154:
            var_2 = 0x9B;
            break;
        case 0x231:
            var_2 = 0xB4;
            break;
        case 0x232:
            var_2 = 0xB6;
            break;
        default:
            if (temp_16[0xA2] == 0) {
                var_2 = 0x3C;
            } else {
                var_2 = 0x3D;
            }
            break;
        }
        var_2_2 = (s64)(var_2 << 0x30) >> 0x30;
        temp_2_2 = func_00202400(
            *(s32 *)(u8 *)func_001a_add_offset(0x30, (s32)arg0),
            (s16)((s64)(var_2_2 << 0x30) >> 0x30));
        *(s16 *)(temp_2_2 + 0x48) = 8;
        *(s64 *)(temp_2_2 + 0x60) = *arg0;
        func_00194590(temp_2_2, 3);
        temp_21 = *(s64 *)(temp_2_2 + 0x58);
        temp_2_3 = func_00194b60();
        *(s16 *)(temp_2_3 + 0x48) = 8;
        *(s64 *)(temp_2_3 + 0x60) = *arg0;
        func_00194590(temp_2_3, 0);
        temp_20 = *(s64 *)(temp_2_3 + 0x58);
        if (*(u16 *)(u8 *)func_001a_add_offset(0x3F4, (s32)arg0) == 0x154) {
            temp_2_4 = func_00106600(0x340) & 0xFF;
            if (temp_2_4 > 0) {
                func_00106620(0x340, (temp_2_4 - 1) & 0xFF);
            }
        }
        if (*(u16 *)(u8 *)func_001a_add_offset(0x3F4, (s32)arg0) == 0x210) {
            func_001f0a10((u8 *)&locals.sp80);
            temp_19 =
                func_00231f80(*(s32 *)(temp_16 + 0xA64)) & 0xFFFF;
            locals.sp80 = temp_19 -
                (func_00231ed0(*(s32 *)(temp_16 + 0xA64)) & 0xFFFF);
            temp_2_5 = func_001f36e0(
                (s32)arg0, (s32)arg0, &locals.sp80, 1, 1);
            *(s8 *)(temp_2_5 + 0) = 4;
            *(s64 *)(temp_2_5 + 8) = temp_20;
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
            temp_2_6 = func_00202740(temp_16);
            *(s8 *)(temp_2_6 + 0) = 4;
            *(s64 *)(temp_2_6 + 8) = temp_20;
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 1);
            temp_2_7 = func_00201de0(
                (s32)temp_16, (s32)temp_16, -1, 0, 0, 0, 1,
                (s32)&locals.sp80, 0);
            *(s8 *)(temp_2_7 + 0) = 4;
            *(s64 *)(temp_2_7 + 8) = temp_20;
            *(s64 *)(temp_2_7 + 0x60) = *arg0;
            func_00194590(temp_2_7, 3);
            temp_2_8 = func_00202590((s32)temp_16, 0, 0);
            *(s8 *)(temp_2_8 + 0) = 4;
            *(s64 *)(temp_2_8 + 8) = temp_20;
            *(s64 *)(temp_2_8 + 0x60) = *arg0;
            func_00194590(temp_2_8, 3);
        }
        if (var_17 != 0) {
            temp_2_9 = func_001937f0(0x80000);
            *(s8 *)(temp_2_9 + 0) = 4;
            *(s64 *)(temp_2_9 + 8) = temp_21;
            *(s64 *)(temp_2_9 + 0x60) = *arg0;
            func_00194590(temp_2_9, 0);
        }
        func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x430));
    }
}
/* Closest candidate archived before reverting: normalized_diff 586; retained for future work. */

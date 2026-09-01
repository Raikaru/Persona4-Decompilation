/* Best candidate for func_001a0f40; object 440B, window 448B, normalized_diff 2 words.
   Differing word offsets: 0x134 (0x1A1074), 0x140 (0x1A1080).
   Ruled out: inline table arithmetic (global load sinks after source arithmetic);
   case-local/global-pointer temporaries (wrong scheduling or extra words);
   old-style func_001973f0 declaration (oversized ABI); alternate source/mode
   expression orderings; narrow/wide offset-local types; harmless casts/wrappers.
   Best lever: float parameter moved ahead of integer parameters in the
   func_001973f0 declaration, while preserving the retail register ABI. */
// FUN_001A0F40 NONMATCHING
void func_001a0f40(s64 *arg0)
{
    extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
    extern u8 *func_001973f0(u8 *arg0, f32 *arg1, f32 arg4, s32 arg2, u32 arg3);
    extern f32 func_001ec250(f32 *arg0, f32 *arg1);
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    extern void func_001b0800(s64 *arg0, u16 arg1);
    f32 sp30[3];
    s32 temp_7;
    u16 temp_6;
    u16 var_5;
    u8 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u32 source_offset;
    u16 mode_index;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) &&
        ((*(u16 *)((u8 *)arg0 + 0x1A) & 1) != 0) &&
        (temp_16[0xA2] == 0)) {
        *(u16 *)((u8 *)arg0 + 0x14) = 9;
    }
    if (func_001b0e90(arg0) != 0) {
        func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x14));
        return;
    }
    func_00194ff0(temp_16, &sp30[0], 0, NULL);
    if (!(func_001ec250((f32 *)(temp_16 + 4), &sp30[0]) <= 75.0f)) {
        var_5 = 2;
        temp_7 = (u16)(!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2));
        temp_6 = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) + 2);
        temp_3 = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2);
        switch (temp_3) {
        case 0:
            break;
        case 1:
            source_offset = (u32)temp_6 * 0xE8;
            mode_index = (u16)temp_7;
            var_5 = *(u16 *)((u32)iGpffffb3cc + source_offset + (mode_index * 4) + 0x24);
            break;
        }
        temp_2 = func_001973f0(
            *(u8 **)((u8 *)arg0 + 0x30), &sp30[0], D_005F6D20[var_5 & 0xFFFF], 0,
            temp_7);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        return;
    }
    func_001b0800(arg0, *(u16 *)((u8 *)arg0 + 0x14));
}
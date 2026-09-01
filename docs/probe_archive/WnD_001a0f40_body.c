/* Best body retained for func_001a0f40; object 440B, window 448B, normalized_diff 2 words. */
/* Residual addus (retail versus candidate):
   0x134 / 0x1A1074: addu $v1,$v0,$a1 (scaled source offset + iGpffffb3cc)
                         versus addu $v1,$a1,$v0 (global base + scaled source offset)
   0x140 / 0x1A1080: addu $v0,$v0,$v1 (scaled mode index + table address)
                         versus addu $v0,$v1,$v0 (table address + scaled mode index)
   The first address chain consumes the large-offset +0xA64 field-derived index and
   iGpffffb3cc; the second consumes that chain and its mode index. */
/* Probes ruled out: full and scoped opt_propagation-off plus named global/table
   local; large-offset field anchoring; raw pointer/byte-offset forms; named
   scaled-index temporaries (mode_offset); pointer-typed base and nested array/
   struct indexing; inline pointer-copy assignment; source-first/mode-first
   reassociations. Best body remains the TnA float-parameter-ahead declaration. */
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
    u16 var_5;
    u16 temp_6;
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

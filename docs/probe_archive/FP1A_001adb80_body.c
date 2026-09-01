/* Archived after remeasure: object 664B, window 656B, normalized_diff 443.
   Differing word-offset ranges: 0x000-0x080, 0x088-0x098, 0x0A0-0x0A4,
   0x0AC-0x0B8, 0x0C0-0x0D0, 0x0D8-0x0E0, 0x0E8-0x0F8, 0x100-0x118,
   0x120-0x130, 0x138-0x14C, 0x154-0x164, 0x16C-0x184,
   0x18C-0x194, 0x19C, 0x1A8, 0x1B0-0x1B4, 0x1BC-0x1EC,
   0x1F4-0x20C, 0x218-0x224, 0x22C-0x24C, 0x254-0x28C.
   Ruled out: corrected block-scope hidden-return/argument prototypes for
   func_002022e0, func_001d6240, and func_001f7c20; the corrected body
   remained oversized with a hundreds-scale residual. Classification:
   oversized frame/saved-register/address-lifetime mismatch; archive immediately.
   Retail tail 0x284-0x28C is three nop words (0x00000000). */
void func_001adb80(s64 *arg0)
{
    s32 var_2;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_6;
    u8 *temp_7;

    temp_4 = *(u16 *)((u8 *)arg0 + 0x1A);
    if ((temp_4 & 1) == 0) {
        var_2 = 0;
    } else {
        temp_6 = *(u8 **)((u8 *)arg0 + 0x30);
        temp_7 = *(u8 **)(temp_6 + 0xA0C);
        if ((temp_4 & 0x10) == 0) {
            var_2 = 0;
        } else if ((*(s32 *)(temp_7 + 0x98) & 2) != 0) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
    }
    if (var_2 != 0) {
        temp_2 = func_0019b6a0(
            *(s32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA0C));
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
    }
    func_001a03b0(arg0);
    temp_2_2 = func_002022e0(
        *(u8 **)((u8 *)arg0 + 0x30),
        *(u16 *)((u8 *)arg0 + 0x6C));
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_2, 3);
    temp_2_3 = func_001bc920((u8 *)arg0, 0x1F);
    *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_3, 0);
    temp_2_4 = func_00199ee0(*(u8 **)((u8 *)arg0 + 0x30),
                             0x19, 0, 0, 1.0f);
    *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_4, 0);
    temp_2_5 = func_001f99c0((u8 *)arg0, 0x15, 0, 0, 0);
    *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_5, 1);
    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
        func_0010b300(*(u16 *)((u8 *)arg0 + 0x74));
        func_0019ef30(
            *(u8 **)((u8 *)arg0 + 0x30),
            *(u16 *)((u8 *)arg0 + 0x74));
        func_0010b7f0();
        if (func_00106330(0x3C) != 0) {
            temp_2_6 = *(u8 **)((u8 *)arg0 + 0x3F0);
            if (temp_2_6 != NULL) {
                *(s16 *)(temp_2_6 + 6) = 0;
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x3F0) + 4) = 0;
            }
        }
    }
    temp_2_7 = func_001d6240(
        *(s32 *)(D_0076449C + 0xD3C),
        *(u8 **)((u8 *)arg0 + 0x30),
        *(u8 **)((u8 *)arg0 + 0x30),
        0, 0);
    *(s16 *)(temp_2_7 + 0x48) = 0xF;
    *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_7, 2);
    temp_2_8 = func_001f7c20(0xA, 2, 6);
    *(s8 *)(temp_2_8 + 0) = 5;
    *(s64 *)(temp_2_8 + 8) = *(s64 *)(temp_2_7 + 0x58);
    *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_8, 1);
    *(s32 *)(D_0076449C + 0xC) |= 0x400000;
    *(u16 *)(D_0076449C + 0x18) |= 5;
}

/* FUNC 00104510 near-match archive: object 612B/window 608B, normalized_diff 426; first differing offsets 0x4,0x8,0xA,0xC,0xE,0x10,0x12,0x14,0x16,0x18,0x1A,0x1C,0x1E,0x20,0x24,0x28,0x2C,0x30,0x34,0x38,0x3C,0x40,0x44,0x48,0x4C,0x50,0x54,0x58,0x5C,0x60; classification saved-register coloring plus index arithmetic and aggregate/frame shape; prologue retail saved $s0-$s4 (5), incoming arguments (s64,s16,s16,s16); block-scope declarations for func_00440b68(void*,s32), func_00442088(void*,void*,s32,s32,s32), func_00442830(void*,void*); ruled out generated-body wholesale, 32/128/240-byte stack aggregates, local declaration order, s16/s32/s64 parameter-width probes, in-place/direct conversion casts, pointer-local removal, and optimization_level 1 (sibling leak); no live mismatch retained. */
void func_00104510(s64 arg0, s16 arg1, s16 arg2, s16 arg3) {
    extern void func_00440b68(void *arg0, s32 arg1);
    extern void func_00442088(void *arg0, void *arg1, s32 arg2, s32 arg3,
                               s32 arg4);
    extern void func_00442830(void *arg0, void *arg1);
    extern u8 D_005DD6A0[];
    extern u8 D_005DD6C0[];
    extern u8 D_005DD610[];
    extern u8 D_005DD61C[];
    extern u8 D_00796A60[];
    extern u8 D_00796A64[];
    extern u8 D_00796A68[];
    extern u8 D_00796A6C[];
    extern u8 D_00796704[];
    extern u8 D_00796706[];
    extern u8 D_00796708[];
    extern u8 D_0079671C[];
    extern u8 D_0079671D[];
    extern u8 D_0079671E[];
    extern u8 D_0079671F[];
    extern u8 D_00796728[];
    extern u8 D_0079672C[];
    extern u8 D_0079674C[];
    extern u8 D_00796700[];
    s32 sp60[60];
    s32 temp_19;
    s32 temp_3;
    s32 temp_7;
    s32 var_8;
    s32 var_9;
    u8 *temp_5;
    {
        s64 temp_18;
        temp_18 = (s64)(s16)arg0;
        func_00440b68(D_005DD6A0, temp_18);
        temp_19 = (s32)temp_18 * 0x370;
    }
    *(s16 *)(D_00796700 + temp_19) = 5;
    *(s32 *)(D_0079674C + temp_19) = 0;
    *(s16 *)(D_00796704 + temp_19) = (s16)arg1;
    *(s16 *)(D_00796706 + temp_19) = (s16)arg2;
    *(s16 *)(D_00796708 + temp_19) = (s16)arg3;
    func_00442088(sp60, D_005DD6C0,
                   (s32)(s16)arg1, (s32)(s16)arg2, (s32)(s16)arg3);
    func_00442830(D_00796700 + temp_19 + 0x60, sp60);
    *(s16 *)(D_00796700 + temp_19) = 6;
    *(s32 *)(D_00796A64 + temp_19) = 0;
    *(s32 *)(D_00796A68 + temp_19) = 0;
    *(s32 *)(D_00796A6C + temp_19) = 0;
    *(u8 *)(D_0079671C + temp_19) = 0xFF;
    *(u8 *)(D_0079671E + temp_19) = 0xFF;
    *(u8 *)(D_0079671D + temp_19) = 0xFF;
    *(u8 *)(D_0079671F + temp_19) = 0xFF;
    *(s32 *)(D_00796728 + temp_19) = 0x3F800000;
    *(s32 *)(D_0079672C + temp_19) = 0x3F800000;
    var_9 = 0;
    var_8 = 1;
    for (;;) {
        temp_7 = var_9 * 0x10;
        temp_5 = D_005DD610 + temp_7;
        temp_3 = *(s32 *)temp_5;
        if (temp_3 == -1) {
            break;
        }
        if ((s32)arg1 == temp_3 &&
            (s32)arg2 == *(s32 *)(temp_5 + 4) &&
            (s32)arg3 == *(s32 *)(temp_5 + 8)) {
            *(s32 *)(D_00796A60 + temp_19) =
                *(s32 *)(D_005DD61C + temp_7);
            var_8 = 0;
            break;
        }
        var_9 += 1;
    }
    if (var_8 != 0) {
        *(s32 *)(D_00796A60 + temp_19) = 0x3E;
    }
}

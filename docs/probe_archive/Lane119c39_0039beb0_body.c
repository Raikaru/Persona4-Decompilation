/* Lane119c39 2026-09-03 (cw3.0.1b119 unit): object 340B / window 336B,
   67 real differing words. Register allocation and branch polarity get
   close under `#pragma schedule on`, but the top branch remains
   `bnez $a0, main` instead of retail's `beqz $s3, default`, the
   default/continue layout is off by a word, `lhu $s0, %lo(D_008872E8)` is
   scheduled after `lw $s1, 8($a2)`, and the 64-bit cache store masks
   `temp_16` with `andi`. The copy loop also uses `a0/a1` for
   source/counter instead of retail's `a1/a0` and loads word-1 before
   word-0. Not installed. */
extern s32 D_00884AE0[];
extern s32 D_00884AEC[];
extern u16 D_008872E8[];
extern u8 D_008872E0[];
extern s32 iGpffffb604;
extern s64 iGpffffb608;
extern s32 iGpffffb600;

s32 func_0039beb0(s32 arg0, void *arg1, void *arg2) {
    u8 sp50[0x40];
    s32 var_19;
    s32 *var_18;
    s32 var_4;
    u16 temp_16;
    u8 *temp_17;
    s32 *var_5;
    u8 *temp_2;
    u8 *temp_3;

    var_19 = arg0;
    var_18 = (s32 *)arg1;
    if (var_19 == 0) {
        u8 *ptr = *(u8 **)(u8 *)D_008872E0;
        var_19 = *(s32 *)(ptr + 4);
    }
    temp_16 = D_008872E8[0];
    temp_17 = *(u8 **)((u8 *)arg2 + 8);
    if (temp_17 != iGpffffb604) {
        goto recompute;
    }
    if (var_19 != iGpffffb600) {
        goto recompute;
    }
    if ((u64)temp_16 != iGpffffb608) {
        goto recompute;
    }
    goto copy;
recompute:
    temp_2 = func_003e9700(var_19);
    if (temp_17[0] != 0xFF) {
        func_003e0960(&sp50, temp_2);
        temp_3 = func_003e9700(*(s32 *)(temp_17 + 4));
        func_003e05f0(&D_00884AE0, temp_3, &sp50);
    } else {
        func_003e0960(&D_00884AE0, temp_2);
    }
    if ((D_00884AEC[0] & 3) != 3) {
        func_003e0670(&D_00884AE0, &D_00884AE0);
    }
    iGpffffb604 = temp_17;
    iGpffffb608 = (u64)temp_16;
    iGpffffb600 = var_19;
copy:
    var_4 = 8;
    var_5 = (s32 *)D_00884AE0;
    do {
        s32 v0;
        s32 v1;
        var_4 -= 1;
        v0 = var_5[0];
        v1 = var_5[1];
        var_18[0] = v0;
        var_18[1] = v1;
        var_5 += 2;
        var_18 += 2;
    } while (var_4 > 0);
    return var_19;
}

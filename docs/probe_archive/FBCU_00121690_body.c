/* object_size=712, window=688, normalized_diff=520; differing offsets begin at 0x0000 (prologue/frame divergence). Oversized; archived immediately per lane stop rule. Corrected/verified callee declarations at file scope without sibling regressions: func_001104d0(s32,s32*,s32*), func_001060c0(void)->u8, func_00110580(s32), func_001105b0(s32), func_00110600(s32,s32), func_0045d6e0(void*,void*,s32,f32), func_00450dd0(s64,void*,s32,s32,f32), D_005E5010/D_005E5028 arrays. Prior archive note reported a different union-based candidate at nd62; this direct probe is not retained live. */
// FUN_00121690
s32 func_00121690(void)
{
    s32 sp7C;
    s32 sp78;
    s8 sp77;
    s8 sp76;
    s8 sp75;
    u8 sp74;
    f32 sp50;
    s32 temp_2;
    s32 temp_3;
    s32 var_16;
    s32 var_18;
    s32 var_19;
    u8 *temp_17;
    union {
        f32 f[2];
        s64 x;
    } pos;

    temp_17 = (u8 *)D_007242B4;
    if (temp_17 == NULL) {
        return 0;
    }
    if (*(s32 *)(temp_17 + 4) == 0) {
        return 0;
    }
    sp74 = 0x40;
    sp75 = 0x40;
    sp76 = 0x40;
    sp77 = -1;
    sp50 = 1.4e-43f;
    *(s32 *)((u8 *)&sp50 + 4) = 0x64;
    *(s32 *)((u8 *)&sp50 + 8) = 0xFA;
    *(s32 *)((u8 *)&sp50 + 12) = 0x64;
    func_0045d6e0(&sp74, &sp50, 1, 0.0f);
    func_001104d0(*(s32 *)(temp_17 + 8), &sp7C, &sp78);
    var_18 = func_00110580(func_00110600(sp7C, 1));
    temp_2 = func_00110580(*(s32 *)(temp_17 + 8));
    if (temp_2 >= var_18) {
        var_19 = 0;
    } else {
        var_19 = 0xC;
    }
    temp_3 = var_19 + (func_001105b0(*(s32 *)(temp_17 + 8)) - 1) * 0xC;
    sp74 = 0x40;
    sp75 = 0x80;
    sp76 = 0x80;
    sp77 = -1;
    sp50 = (f32)(temp_2 * 0x24 + 0x64);
    *(s32 *)((u8 *)&sp50 + 4) = temp_3 + 0x7C;
    *(s32 *)((u8 *)&sp50 + 8) = 0x24;
    *(s32 *)((u8 *)&sp50 + 12) = 0xC;
    func_0045d6e0(&sp74, &sp50, 1, 0.0f);
    pos.f[0] = 100.0f;
    pos.f[1] = 100.0f;
    func_00450dd0(pos.x, &D_005E5028, sp7C,
                  *((u8 *)(D_005E5010 + ((func_001060c0() & 0xFF) * 4))),
                  0.0f);
    pos.f[0] = pos.f[0] + 17.0f + (f32)(var_18 * 36);
    pos.f[1] = 124.0f;
    var_16 = 0;
    while (var_16 < func_001104a0(sp7C)) {
        func_00450dd0(pos.x, (void *)(D_007242B4 - 0x63AC),
                      var_16 + 1, 0, 0.0f);
        var_18++;
        if (var_18 >= 7) {
            var_18 = 0;
            pos.f[0] -= 252.0f;
            pos.f[1] += 12.0f;
        }
        pos.f[0] += 36.0f;
        var_16++;
    }
    return 0;
}

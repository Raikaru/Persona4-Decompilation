/* object 1272B / window 1248B / normalized_diff 272 (laneE s16/narrow-type rebuild)
   differing offsets: prologue frame 0x110 vs retail 0x100, arg1 spilled to 0xec
   instead of s4, arg2 in s5 instead of s3, f20/f21 load order correct but
   FclVec2 copy folded into f20/f21 (spE8/spEC slots not materialised), stack
   layout shifted spD8 0xf8/spE0 0xf0/FclByte4 0x100-0x10c, u_long128 spC0
   loaded with sq/lq at different offsets, if/else branch layout matches,
   D_007495C0/D_00749600 and 0x3D/0xF1/0xF2/0xF3 constants and 29.0f/25.0f
   correct, no __floatdisf.
   levers tried: s16 loop variables, u_long128 end local, named f20/f21,
   field-wise FclVec2 copy, direct D_ arrays, explicit s32 arithmetic for
   v21*0x3D. Remaining floor: saved-register rotation + stack-slot placement. */
void func_00329310(u8 *arg0, s32 arg1, s64 arg2)
{
    extern void func_002b2970(void *, f32, f32);
    extern void func_002b68d0(s16, s16, s8);
    extern u8 *func_002b6150(s16);
    extern void func_002b2a60(void *, s32, s32, s32, s32);
    extern void func_002b7750(s16, s16);
    extern void func_002b77d0(s64, s64, s64, s32, s64, s64, s64, s64, f32, s16, s32);
    extern s32 func_00331560(void);
    u8 *t;
    s16 var_16;
    s16 var_17;
    s16 var_17_2;
    s16 var_18;
    s32 temp_21;
    s32 v21x3;
    s32 temp_30;
    s16 temp;
    s16 temp2;
    s64 spD8;
    f32 spE8;
    f32 spEC;
    s64 spE0;
    FclByte4 spFC;
    FclByte4 spF8;
    FclByte4 spF4;
    FclByte4 spF0;
    u_long128 spC0;
    f32 f20;
    f32 f21;
    u8 *p;
    s16 v16;
    s16 v16b;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&spD8, 18.0f, 14.0f);
    spE8 = ((FclVec2 *)&spD8)->x;
    spEC = ((FclVec2 *)&spD8)->y;
    f20 = 9.0f + spEC;
    f21 = 87.0f + spE8;
    var_16 = (s8)(*(s8 *)(t + 0x122) - *(s16 *)(t + 0x120));
    for (var_17 = 0; var_17 < 0xE; var_17++) {
        func_002b68d0(var_17 + 0x13F, 0, 1);
    }
    func_002b68d0(0x2E4, 0, 1);
    spC0 = (u_long128)(s64)(var_16 + 7);
    for (var_17_2 = 0; (s64)var_16 < (s64)spC0; var_17_2++) {
        v16 = var_16;
        var_18 = (s16)(v16 + 0x13F);
        if (var_18 == 0x14B) {
            var_18 = 0x14C;
        }
        v16b = var_16;
        temp_30 = v16b * 4;
        temp_21 = (s32)var_17_2;
        func_002b2970(&spE0, f21 + (f32)(temp_21 * 0x3D) + D_007495C0[v16b], f20);
        p = func_002b6150(var_18);
        *(f32 *)(p + 0x38) = ((FclVec2 *)&spE0)->x;
        *(f32 *)(p + 0x3C) = ((FclVec2 *)&spE0)->y;
        func_002b2a60(&spFC, 0xFF, 0xFF, 0xFF, 0xFF);
        func_002b77d0(var_18, spE0, var_18, *(s32 *)&spFC, 0xBD, arg2, arg1, 3, 29.0f, 0, func_00331560());
        temp = (s16)((s16)(temp_21 * 3 + 0xF1) + 0x1F4);
        func_002b68d0(temp, 0, 1);
        func_002b7750(temp, var_18);
        func_002b2a60(&spF8, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002b77d0(temp, spE0, var_18, *(s32 *)&spF8, 0xBF, arg2, arg1, 3, 25.0f, 0, func_00331560());
        v21x3 = temp_21 * 3;
        if ((v16b >= 3) && (v16 != 0xC)) {
            func_002b2970(&spE0, ((FclVec2 *)&spE0)->x + D_00749600[v16b], 15.0f + ((FclVec2 *)&spE0)->y);
            temp = (s16)((s16)(v21x3 + 0xF2) + 0x1F4);
            func_002b7750(temp, 0x14B);
            func_002b2a60(&spF4, 0xFF, 0xFF, 0xFF, 0xFF);
            func_002b77d0(temp, spE0, 0x14B, *(s32 *)&spF4, 0xBD, arg2, arg1, 3, 29.0f, 0, func_00331560());
            temp2 = (s16)((s16)(v21x3 + 0xF3) + 0x1F4);
            func_002b7750(temp2, 0x14B);
            func_002b2a60(&spF0, 0x2D, 0x2D, 0x2D, 0xFF);
            func_002b77d0(temp2, spE0, 0x14B, *(s32 *)&spF0, 0xBF, arg2, arg1, 3, 25.0f, 0, func_00331560());
        } else {
            temp = (s16)((s16)(v21x3 + 0xF2) + 0x1F4);
            func_002b68d0(temp, 0, 1);
            temp = (s16)((s16)(v21x3 + 0xF3) + 0x1F4);
            func_002b68d0(temp, 0, 1);
        }
        var_16 = (s16)(var_16 + 1);
    }
}

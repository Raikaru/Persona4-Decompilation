/* MWCCPS2: object 416B / retail window 416B / four differing words.
 * Residual offsets 0x60, 0x64, 0x68, 0x6C: first pair load register and
 * scheduling against the second constant load. Every other word matches.
 * A complete normal union and three triangle pointers naturally occupy
 * sp+0x50 and sp+0x60 in the 0x70 frame; no explicit padding is used.
 * Top-tested iteration preserves an empty list. Both triangle calls,
 * strict Y limits, selected ID and output pointer behavior are retained.
 * Owning-unit NormalXY0014 and array globals provide the actual 8-byte XY
 * and 4-byte Z accesses. A 16-byte whole-normal copy is rejected because
 * it reads beyond those constant extents and changes retail access width.
 * Reverse stores: 7 words; propagation off: 5; aggregate temporaries: 4.
 */
u16 func_0014be50(u8 *arg0, u8 **arg1) {
    u8 *triangle[3];
    union { SVec3 vector; struct { NormalXY0014 xy; f32 z; } parts; } normal;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    u16 var_17;
    u8 *var_16;

    var_17 = 0xFFFF & 0xFFFF;
    var_16 = (u8 *)(func_001452b0(0xD));
    if (func_0014a200() == 1) {
        return 0xFFFFU;
    }
    while (var_16 != NULL) {
        normal.parts.xy = D_005EFB98[0];
        normal.parts.z = D_005EFBA0[0];
        triangle[0] = (u8 *)(var_16 + 0x15C);
        triangle[1] = (u8 *)(var_16 + 0x168);
        triangle[2] = (u8 *)(var_16 + 0x174);
        if ((func_00168ec0(arg0, &triangle[0], &normal.vector) == 1) &&
            (temp_f3 = *(f32 *)(triangle[0] + 4),
             temp_f2 = *(f32 *)(arg0 + 4),
             (temp_f2 < (100.0f + temp_f3))) &&
            !(temp_f2 <= (temp_f3 - 100.0f))) {
            var_17 = *(u16 *)var_16;
            *arg1 = var_16;
            goto done_11;
        }
        triangle[0] = (u8 *)(var_16 + 0x168);
        triangle[1] = (u8 *)(var_16 + 0x174);
        triangle[2] = (u8 *)(var_16 + 0x180);
        if ((func_00168ec0(arg0, &triangle[0], &normal.vector) == 1) &&
            (temp_f3_2 = *(f32 *)(triangle[0] + 4),
             temp_f2_2 = *(f32 *)(arg0 + 4),
             (temp_f2_2 < (100.0f + temp_f3_2))) &&
            !(temp_f2_2 <= (temp_f3_2 - 100.0f))) {
            var_17 = *(u16 *)var_16;
            *arg1 = var_16;
            goto done_11;
        }
        var_16 = *(u8 **)(var_16 + 0x138);
    }
done_11:
    return var_17;
}

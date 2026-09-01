/* Attempted reconstruction; retained for archaeology. Best probe: 352-byte object/window, normalized diff 46.
 * Residual is retail's branch layout/argument register coloring in the threshold dispatch and callback setup. */
u8 *func_00394e70(u8 *arg0, u8 *arg1, void *arg2, void *arg3)
{
    f32 vec[4];
    u8 matrix[64];
    u8 out[32];
    s32 type;
    register u8 *temp_20;
    u8 *temp_2;

    type = *(s32 *)(arg1 + 0x18);
    if (type != 5) {
        if (type != 3) {
            if (type != 1) {
                return arg0;
            }
            temp_20 = *(u8 **)(arg0 + 0x18);
            func_003e0960(matrix, func_003e9700(*(s32 *)(arg0 + 4)));
            func_003e42e0(out, arg1, 2, matrix);
            if (*(s32 *)(temp_20 + 0x18) >= 2) {
                func_003941e0(temp_20, arg0 + 0x4C, out, arg1, arg2, arg3);
            } else {
                func_00392bf0(temp_20, out, arg1, arg2, arg3);
            }
            return arg0;
        } else {
            func_00394c70(arg0, arg1, arg1, arg2, arg3);
        }
    } else {
        temp_2 = func_003bfae0(*(s32 *)arg1);
        vec[0] = *(f32 *)(temp_2 + 0);
        vec[1] = *(f32 *)(temp_2 + 4);
        vec[2] = *(f32 *)(temp_2 + 8);
        vec[3] = *(f32 *)(temp_2 + 0xC);
        func_00394c70(arg0, vec, arg1, arg2, arg3);
    }
    return arg0;
}

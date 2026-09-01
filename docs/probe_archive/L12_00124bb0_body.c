/* Closest rejected reconstruction for FUN_00124BB0.
 * Probe: object 956B / retail window 960B with #pragma opt_propagation off.
 * The prologue, pointer lookup, matrix/vector setup, flags, and call tail
 * match; residual normalized differences are the six absolute global 64-bit
 * loads emitted as ld $v1 rather than retail ld $a0, plus the final 4-byte
 * alignment nop. Restored to INCLUDE_ASM because nd != 0.
 */
typedef struct {
    u8 q[8];
    f32 f;
} Code1GlobalPair12;

#pragma opt_propagation off
void func_00124bb0(s32 arg0,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5,
                   u32 arg1, u32 arg2,
                   f32 fparg6,
                   s32 arg3, u32 *arg4)
{
    u8 color[4];
    Code1GlobalPair12 global_pair;
    u8 vec_f[0x10];
    u8 vec_e[0x10];
    u8 vec_d[0x10];
    u8 matrix[0x40];
    u8 *temp_2;
    u8 *var_16;

    *(s64 *)global_pair.q = *(s64 *)D_005E55B0;
    global_pair.f = *(f32 *)D_005E55B8;
    *(s64 *)vec_f = *(s64 *)D_005E55C0;
    *(f32 *)(vec_f + 8) = *(f32 *)D_005E55C8;
    *(s64 *)vec_e = *(s64 *)D_005E55D0;
    *(f32 *)(vec_e + 8) = *(f32 *)D_005E55D8;
    if (arg0 >= 0xF) {
        var_16 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg4);
        var_16 = temp_2 + 0x44;
        if (func_004782b0(*(u8 **)var_16) != 0) {
            var_16 = *(u8 **)var_16;
        } else {
            var_16 = NULL;
        }
    }
    if (var_16 != NULL) {
        *(s32 *)(matrix + 0x28) = 0x3F800000;
        *(s32 *)(matrix + 0x14) = 0x3F800000;
        *(s32 *)(matrix + 0x00) = 0x3F800000;
        *(s32 *)(matrix + 0x10) = 0;
        *(s32 *)(matrix + 0x08) = 0;
        *(s32 *)(matrix + 0x04) = 0;
        *(s32 *)(matrix + 0x24) = 0;
        *(s32 *)(matrix + 0x20) = 0;
        *(s32 *)(matrix + 0x18) = 0;
        *(s32 *)(matrix + 0x38) = 0;
        *(s32 *)(matrix + 0x34) = 0;
        *(s32 *)(matrix + 0x30) = 0;
        *(s32 *)(matrix + 0x0C) |= 0x20003;
        func_003e0870(matrix, &global_pair, fparg4, 0);
        *(s32 *)(vec_f + 0x00) = 0x3F800000;
        *(s32 *)(vec_f + 0x04) = 0;
        *(s32 *)(vec_f + 0x08) = 0;
        func_003e4320(vec_f, vec_f, matrix);
        func_003e0870(matrix, vec_f, fparg3, 2);
        *(s32 *)(vec_e + 0x00) = 0;
        *(s32 *)(vec_e + 0x04) = 0;
        *(s32 *)(vec_e + 0x08) = 0x3F800000;
        func_003e4320(vec_e, vec_e, matrix);
        func_003e0870(matrix, vec_e, fparg5, 2);
        *(f32 *)(vec_d + 0x00) = fparg6;
        *(f32 *)(vec_d + 0x04) = fparg6;
        *(f32 *)(vec_d + 0x08) = fparg6;
        func_003e0a90(matrix, vec_d, 2);
        *(f32 *)(vec_d + 0x00) = fparg0;
        *(f32 *)(vec_d + 0x04) = fparg1;
        *(f32 *)(vec_d + 0x08) = fparg2;
        func_003e0c90(matrix, vec_d, 2);
        func_0047a1c0(var_16, matrix, 0);
        color[0] = arg1 >> 0x18;
        color[1] = arg1 >> 0x10;
        color[2] = arg1 >> 8;
        color[3] = arg1;
        if (arg3 & 1) {
            *(s32 *)(var_16 + 0xD8) |= 8;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~8;
        }
        if (arg3 & 2) {
            *(s32 *)(var_16 + 0xD8) |= 0x10;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x10;
        }
        if (arg3 & 0x10) {
            *(s32 *)(var_16 + 0xD8) |= 0x100000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x100000;
        }
        if (arg3 & 0x40) {
            *(s32 *)(var_16 + 0xD8) |= 0x40000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x40000;
        }
        if (!(arg3 & 0x10000)) {
            func_00478e70(var_16);
        }
        func_00124970(arg0, arg2, arg3 | 2, arg4);
        func_002ab550(var_16, color);
        func_00124970(arg0, arg2, arg3 | 1, arg4);
    }
}
#pragma opt_propagation on

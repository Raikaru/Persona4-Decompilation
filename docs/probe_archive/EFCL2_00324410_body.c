/* object 616B / window 624B; normalized_diff 118; differing offsets 0x11C-0x12C plus helper-width residuals; corrected block prototypes probed: 2970(void*,f32,f32), 6150(s16), 68d0(s16,s16,s8), 6a70(s16,u32,u32,u32,u32,s32), 7750(s16,s16); s16 caller/helper width and FPU materialization residuals remain. */
// FUN_00324410 NONMATCHING
#ifdef NON_MATCHING
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
/* Target helper declarations use the verified file-scope prototypes above. */
void func_00324410(u8 *arg0, s64 arg1, s64 arg2) {
    f32 sp6C;
    f32 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    f32 temp_f20;
    s64 temp_17;
    s8 temp_4;
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x38));
    sp68 = (f32)(s32)(M2C_FIELD(temp_3, f32 *, 0x298));
    sp6C = (f32)(s32)(M2C_FIELD(temp_3, f32 *, 0x29C));
    temp_17 = (s64) (arg2 << 0x38) >> 0x38;
    temp_3_2 = (u8 *)(temp_17 + temp_3);
    temp_4 = (s8)(M2C_FIELD(temp_3_2, s8 *, 0x294));
    switch (temp_4) {                               /* irregular */
    case 0:
        if (((s64) (func_002b6970(M2C_FIELD(func_002b6150(arg1), s16 *, 0x10), 2) << 0x30) >> 0x30) != 1) {
            func_002b7750(arg1, 0x1C7);
            func_002b68d0(arg1, 0, 0);
            if (temp_17 == 0) {
                func_002b2970(&sp60, 280.0f + sp68, sp6C);
                func_002b69f0(arg1, M2C_BITWISE(s64, sp68), sp60, 0, 0x32, 0);
            } else if (temp_17 == 1) {
                temp_f20 = 20.0f + sp6C;
                func_002b2970(&sp58, 280.0f + sp68, temp_f20);
                func_002b2970(&sp50, sp68, temp_f20);
                func_002b69f0(arg1, sp58, sp50, 0, 0x32, 0);
            }
            func_002b6af0(arg1, 0, 0, 0, 0x3F800000, 0x40000000, 1.0f, 1.0f);
            func_002b6a70(arg1, 0U, 0xFFU, 1, 0x32, 0);
            M2C_FIELD(func_002b6150(arg1), s8 *, 0x73) = 1;
            M2C_FIELD(temp_3_2, s8 *, 0x294) = 1;
            return;
        }
        return;
    case 1:
        if (((s64) (func_002b6970(M2C_FIELD(func_002b6150(arg1), s16 *, 0x10), 1) << 0x30) >> 0x30) != 1) {
            M2C_FIELD(temp_3_2, s8 *, 0x294) = 0;
            return;
        }
        break;
    case 2:
        func_002b68d0(arg1, 0, 1);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324410);
#endif












// measured: nd N/A (draw-family, s64-param floor). 19x 6a70 + 19x 6150 + 19x 2970 + 17x 2a60 + 15x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.

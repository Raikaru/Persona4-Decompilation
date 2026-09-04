s32 func_003742b0(u8 *arg0) {
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
    u8 sp[0x70];
    

    s32 temp_17;
    s32 temp_17_2;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_18_2;
    s32 var_19;
    u8 *temp_3_2;
    u8 *temp_3_3;

    temp_3 = (s32)(M2C_FIELD(arg0, s32 *, 0x1F2EC));
    switch (temp_3) {                               /* irregular */
    case 0:
        if (func_004553c0(M2C_FIELD(arg0, s32 *, 0x1F2E8)) != 0) {
            var_19 = 0;
            var_18 = 0;
loop_9:
            if (var_18 < 9) {
                temp_17 = (s32)(func_00455ea0(M2C_FIELD(arg0, s32 *, 0x1F2E8), var_19, &M2C_FIELD(sp, s32 *, 0x6C)));
                func_0044ea90(&D_0064EA20, 0x101);
                temp_2 = (s32)(D_008873F4[0](1, M2C_FIELD(sp, s32 *, 0x6C), 0x40000));
                temp_3_2 = (u8 *)(arg0 + (var_18 * 4));
                M2C_FIELD(temp_3_2, s32 *, 0x1F2B8) = temp_2;
                if (temp_2 == 0) {
                    func_0046d730(&D_0064EA20, 0x102);
                }
                func_0043f810(M2C_FIELD(temp_3_2, s32 *, 0x1F2B8), temp_17, M2C_FIELD(sp, s32 *, 0x6C));
                var_18 += 1;
                var_19 += 1;
                goto loop_9;
            }
            var_17 = 0;
loop_14:
            if (var_17 < 3) {
                temp_2_2 = (s32)(func_0046af60(func_00455ea0(M2C_FIELD(arg0, s32 *, 0x1F2E8), var_19, NULL)));
                M2C_FIELD((arg0 + (var_17 * 4)), s32 *, 0x1F2AC) = temp_2_2;
                if (temp_2_2 == 0) {
                    func_0046d730(&D_0064EA20, 0x109);
                }
                var_17 += 1;
                var_19 += 1;
                goto loop_14;
            }
            var_18_2 = 0;
loop_19:
            if (var_18_2 < 3) {
                temp_17_2 = (s32)(func_00455ea0(M2C_FIELD(arg0, s32 *, 0x1F2E8), var_19, &M2C_FIELD(sp, s32 *, 0x6C)));
                func_0044ea90(&D_0064EA20, 0x10F);
                temp_2_3 = (s32)(D_008873F4[0](1, M2C_FIELD(sp, s32 *, 0x6C), 0x40000));
                temp_3_3 = (u8 *)(arg0 + (var_18_2 * 4));
                M2C_FIELD(temp_3_3, s32 *, 0x1F2DC) = temp_2_3;
                if (temp_2_3 == 0) {
                    func_0046d730(&D_0064EA20, 0x110);
                }
                func_0043f810(M2C_FIELD(temp_3_3, s32 *, 0x1F2DC), temp_17_2, M2C_FIELD(sp, s32 *, 0x6C));
                var_18_2 += 1;
                var_19 += 1;
                goto loop_19;
            }
            func_0036d230(func_00455ea0(M2C_FIELD(arg0, s32 *, 0x1F2E8), var_19, NULL));
            M2C_FIELD(arg0, s32 *, 0x1F2EC) = 1;
        case 1:
            var_17_2 = 0;
loop_26:
            if (var_17_2 >= 3) {
                func_00454bd0(M2C_FIELD(arg0, s32 *, 0x1F2E8));
                M2C_FIELD(arg0, s32 *, 0x1F2E8) = 0;
                M2C_FIELD(arg0, s32 *, 0x1F2EC) = 2;
            case 2:
                return 1;
            }
            temp_4 = (s32)(M2C_FIELD((arg0 + (var_17_2 * 4)), s32 *, 0x1F2AC));
            if ((temp_4 != 0) && (func_0046a750(temp_4) == 0)) {
                return 0;
            }
            var_17_2 += 1;
            goto loop_26;
        }
    default:
        return 0;
    }
}

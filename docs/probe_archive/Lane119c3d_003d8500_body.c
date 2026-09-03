/* archived best measured attempt: object=380 window=416 normalized_diff=100. */
#include "include_asm.h"
#include "type.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern s32 func_003e2ab0(s8 *arg0, u8 *arg1, s32 arg2);
extern void func_0043f810(void *dst, void *src, u32 size);

/* measured: switch on arg3; 4/8 cases call helper. */
// FUN_003D8500
#pragma schedule on
s32 func_003d8500(s8 *arg0, u8 *arg1, s32 arg2, u32 arg3, u8 *arg4) {
    u8 sp5F;
    s32 var_16;
    s32 var_2;
    s32 var_4;
    s32 var_6_2;
    s32 var_7;
    u8 *temp_3;
    u8 *var_3;
    u8 temp_4;
    u8 *var_6;

    if (arg3 != 4) {
        if (arg3 != 8) {
            var_4 = 0;
            var_6 = (u8 *)(M2C_FIELD(arg1, s32 *, 0x14) + (arg2 * M2C_FIELD(arg1, s32 *, 0x10)));
            if (M2C_FIELD(arg1, s32 *, 4) > 0) {
                var_3 = (u8 *)(arg4);
                do {
                    var_4 += 1;
                    M2C_FIELD(var_3, u8 *, 2) = (u8) M2C_FIELD(var_6, u8 *, 0);
                    M2C_FIELD(var_3, u8 *, 1) = (u8) M2C_FIELD(var_6, u8 *, 1);
                    M2C_FIELD(var_3, u8 *, 0) = M2C_FIELD(var_6, u8 *, 2);
                    var_6 += 4;
                    var_3 += 3;
                } while (var_4 < M2C_FIELD(arg1, s32 *, 4));
            }
            var_2 = (s32)(M2C_FIELD(arg1, s32 *, 4) * 3);
        } else {
            func_0043f810(arg4, (void *) (M2C_FIELD(arg1, s32 *, 0x14) + (arg2 * M2C_FIELD(arg1, s32 *, 0x10))), M2C_FIELD(arg1, s32 *, 4));
            var_2 = (s32)(M2C_FIELD(arg1, s32 *, 4));
        }
    } else {
        var_7 = 0;
        if (M2C_FIELD(arg1, s32 *, 4) > 0) {
            var_6_2 = 0;
            do {
                temp_3 = (u8 *)(M2C_FIELD(arg1, s32 *, 0x14) + (arg2 * M2C_FIELD(arg1, s32 *, 0x10)) + var_7);
                temp_4 = (u8)(M2C_FIELD(temp_3, u8 *, 0));
                var_7 += 2;
                arg4[var_6_2] = (temp_4 * 0x10) | M2C_FIELD(temp_3, u8 *, 1);
                var_6_2 += 1;
            } while (var_7 < M2C_FIELD(arg1, s32 *, 4));
        }
        var_2 = (s32)(M2C_FIELD(arg1, s32 *, 4) >> 1);
    }
    var_16 = var_2;
    func_003e2ab0(arg0, arg4, var_16);
    if (var_16 & 3) {
        do {
            sp5F = 0;
            func_003e2ab0(arg0, &sp5F, 1);
            var_16 += 1;
        } while (var_16 & 3);
    }
    return var_16;
}
/* measured: closes the schedule bracket. */
#pragma schedule off

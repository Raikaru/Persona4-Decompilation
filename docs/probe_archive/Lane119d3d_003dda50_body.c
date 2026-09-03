/* Lane119d3d func_003dda50 archived candidate
 * object 436, window 448, normalized_diff 274
 * status: MISMATCH
 * first differing offsets: 56, 61, 72-78, 80, 82-83, 85-89
 * levers tried: m2c candidate, #pragma schedule on, for-loop vs goto,
 *                block-scope extern for func_003ddc10(void)
 * residual: structural (branch/loop shape) and scheduling
 */
// FUN_003DDA50
#pragma schedule on
extern s32 iGpffffb754;
extern void func_00421820(s32);
extern void func_00421800(s32);
u8 *func_003dda50(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_16;
    s32 var_19;
    u8 *temp_2;
    u8 *var_17;
    u8 *(*get_0x14)();
    s32 (*cb_0x28)();
    extern s32 *func_003ddc10(void);

    var_19 = arg2;
    var_17 = NULL;
    if (arg0 != NULL) {
        func_00421820(iGpffffb754);
        for (var_16 = 0; var_16 < *(s32 *)((u8 *)arg0 + 4); var_16++) {
            get_0x14 = (u8 *(*)())(*(void **)((u8 *)arg0 + 0x14));
            temp_2 = get_0x14(arg0, var_16);
            if (*(s32 *)(temp_2 + 0x38) == 1) {
                var_17 = temp_2;
                *(s32 *)(temp_2 + 0x38) = 5;
                break;
            }
        }
        func_00421800(iGpffffb754);
        if (var_17 != NULL) {
            if (((var_19 & 0x10) != 0) || (*(s32 *)(var_17 + 0x30) != 0)) {
                *(s32 *)(var_17 + 0x40) = 2;
                *(s32 *)(var_17 + 0x48) = arg3;
                *(s32 *)(var_17 + 0x4C) = arg4;
            }
            if (*(s32 *)((u8 *)arg0 + 0x10) != 0) {
                var_19 |= 0x10;
                *(s32 *)(var_17 + 0x40) = 2;
                *(s32 *)(var_17 + 0x48) = arg3;
                *(s32 *)(var_17 + 0x4C) = arg4;
            }
            cb_0x28 = (s32 (*)())(*(void **)((u8 *)arg0 + 0x28));
            if (cb_0x28(arg0, var_17, arg1, var_19) != 1) {
                *(s32 *)(var_17 + 0x38) = 1;
                var_17 = NULL;
            }
            if (var_17 != NULL) {
                *(s32 *)(var_17 + 0x34) = 2;
                return var_17;
            }
        }
        func_003ddc10()[4] = 8;
        if (D_00887194[0] != NULL) {
            ((void (*)(s32))D_00887194[0])(8);
        }
    } else {
        if (D_00887194[0] != NULL) {
            ((void (*)(s32))D_00887194[0])(4);
        }
    }
    return NULL;
}
/* measured: closes the schedule bracket. */
#pragma schedule off

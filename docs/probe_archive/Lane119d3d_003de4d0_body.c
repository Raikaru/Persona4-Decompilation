/* Lane119d3d func_003de4d0 archived candidate
 * object 464, window 464, normalized_diff 343
 * status: MISMATCH
 * first differing offsets: 0, 4, 8, 10, 12, 14, 17, 20, 22, 25, 28, 30, 32-35
 * levers tried: m2c candidate, #pragma schedule on, local variable ordering
 * residual: structural and register allocation
 */
// FUN_003DE4D0
#pragma optimization_level 1
#pragma schedule on
u32 func_003de4d0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 arg1_p = arg1;
    u8 * arg0_p = arg0;
    s32 arg2_p = arg2;
    s32 done;
    s32 count;
    s32 temp;
    s32 temp_2;

    done = 0;
    M2C_FIELD(arg0_p, s64 *, 0x20) = M2C_FIELD(arg0_p, s64 *, 0x10);
    if (M2C_FIELD(arg0_p, s32 *, 0x30) != 0) {
        M2C_FIELD(arg0_p, s32 *, 0x40) = 5;
    }
    count = arg2_p;
    if (M2C_FIELD(arg0_p, s64 *, 0) < (s64)(u32)((s32)M2C_FIELD(arg0, s64 *, 0x10) + count)) {
        count = (s32)(M2C_FIELD(arg0_p, s64 *, 0) - M2C_FIELD(arg0_p, s64 *, 0x10));
    }
    if (count == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0_p, s32 *, 0x30) != 0) {
        if (sceRead(M2C_FIELD(arg0, s32 *, 0x60), (void *)arg1_p, count) < 0) {
            return 0;
        }
        M2C_FIELD(arg0, s64 *, 0x10) = M2C_FIELD(arg0_p, s64 *, 0x10) + (s64)count;
        M2C_FIELD(arg0_p, s32 *, 0x38) = 3;
        return (u32)count;
    }
    while (1) {
        temp_2 = M2C_FIELD(arg0_p, s32 *, 0x6C) - M2C_FIELD(arg0_p, s32 *, 0x64);
        if (temp_2 >= 1) {
            if ((u32)count < (u32)temp_2) {
                temp_2 = count;
            }
            func_0043f810((u8 *)arg1_p, (u8 *)M2C_FIELD(arg0_p, s32 *, 0x68) + M2C_FIELD(arg0, s32 *, 0x64), (u32)temp_2);
            arg1_p += temp_2;
            done = done + (temp_2);
            count = count - (temp_2);
            M2C_FIELD(arg0, s32 *, 0x64) += temp_2;
        }
        if (0 == count) {
            break;
        }
        temp = M2C_FIELD(arg0_p, s32 *, 0x6C);
        M2C_FIELD(arg0, s32 *, 0x38) = 3;
        if (count < temp) {
            M2C_FIELD(arg0, s32 *, 0x64) = count;
            sceRead(M2C_FIELD(arg0_p, s32 *, 0x60), (void *)M2C_FIELD(arg0_p, s32 *, 0x68), temp);
            func_0043f810((u8 *)arg1_p, (u8 *)M2C_FIELD(arg0, s32 *, 0x68), (u32)count);
            done += count;
            break;
        } else {
            M2C_FIELD(arg0_p, s32 *, 0x38) = 2;
            done = done + (temp);
        }
    }
    M2C_FIELD(arg0_p, s64 *, 0x10) = M2C_FIELD(arg0, s64 *, 0x10) + (s64)done;
    return (u32)done;
}
/* measured: closes the schedule bracket. */
#pragma schedule off
#pragma optimization_level 2

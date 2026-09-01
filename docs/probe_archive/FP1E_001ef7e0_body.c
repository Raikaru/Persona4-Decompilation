/* archived probe: object 224B, window 224B, normalized_diff 5 */
s32 func_001ef7e0(void)
{
    union {
        s32 address;
        s32 value;
    } temp_3;
    s32 var_3;
    u32 temp_2;
    u16 temp_16;
    u8 *temp_4;

    temp_3.address = (s32)gEncountTbl + func_001ef9a0() * 24;
    temp_4 = iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xC5A) == 0) {
        return 0;
    }
    temp_3.value = *(s32 *)temp_3.address;
    if ((temp_3.value & 2) != 0) {
        return 0;
    }
    if ((temp_3.value & 4) != 0) {
        return 1;
    }
    temp_2 = *(u32 *)(temp_4 + 0x20);
    if (temp_2 != 0) {
        goto state_nonzero;
    }
    var_3 = 0;
    goto state_done;
state_nonzero:
    if (temp_2 < 6) {
        goto state_less;
    }
    var_3 = 4;
    goto state_done;
state_less:
    var_3 = temp_2 - 1;
state_done:
    temp_16 = *(&iGpffffa9b0 + var_3);
    return (u32)func_00231d70(100) < (u32)temp_16;
}

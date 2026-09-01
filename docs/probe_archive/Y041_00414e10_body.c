/* object 244B, window 224B, normalized_diff 197; fndiff differing offsets 0x04-0x58,0x60-0xE0,0xE8-0xF0; casts written: explicit u32 alignment mask and byte-pointer field arithmetic; levers ruled out: schedule-on (204B/48), baseline typed/old-style helper declarations, and mask-local spelling. Compiler check: sq $s1/$s0 prologue => MWCCPS2 workable. */
u8 *func_00414e10(u8 **arg0, s32 arg1)
{
    s32 sp38;
    s32 sp3C;
    s32 var_6;
    u32 temp_16;
    u8 *var_5;
    u8 *temp_2;
    u8 *func_00414a30(u8 **, u32, s32);
    u8 *func_00414b50(u8 **, u8 *, u32);
    s32 func_003df590();
    void func_003df4d0(s32 *);

    var_6 = *(s32 *)((u8 *)arg0 + 0x14);
    temp_16 = (u32)(arg1 + 0x1F) & ~0x1FU;
    var_5 = *(u8 **)((u8 *)arg0 + 0xC) + ((var_6 - 1) << 3);
loop_1:
    if (*(u32 *)var_5 < temp_16) {
        var_6 -= 1;
        var_5 -= 8;
        if (var_6 != 0) {
            goto loop_1;
        }
        temp_2 = func_00414a30(arg0, temp_16, var_6);
        if (temp_2 != NULL) {
            *(s32 *)((u8 *)arg0 + 0x18) = 1;
            return func_00414b50(arg0, *(u8 **)(temp_2 + 0xC), temp_16);
        }
        sp38 = 1;
        sp3C = func_003df590(0x80000013, temp_16);
        func_003df4d0(&sp38);
        return NULL;
    }
    *(s32 *)((u8 *)arg0 + 0x18) = 1;
    return func_00414b50(arg0, var_5, temp_16);
}

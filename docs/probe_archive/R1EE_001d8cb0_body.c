/* object 312B, window 320B, normalized_diff 51; differing offsets 0x30,0x32,0x34,0x38-0x44,0x48-0x78,0x7C-0x84,0x88-0x94,0x98-0x10C; classification prologue/signature-correct but key-loop declaration/scheduling; retail saves s0/s1/s2 and f20, a0/a1 are incoming; ruled out structured/direct key-loop forms and count-local declaration orders. */
s32 func_001d8cb0(u8 *arg0, u8 *arg1)
{
    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern f32 func_001ec250(f32 *arg0, f32 *arg1);
    struct Vec4 {
        f32 x;
        f32 y;
        f32 z;
        f32 pad;
    };
    struct Vec4 sp60;
    struct Vec4 sp50;
    f32 temp_f0;
    f32 var_f20;
    s32 first;
    s32 index;
    *(u16 *)(arg1 + 0x3A) = 0;
    {
        u64 key;
        s32 key_index;
        key = *(u64 *)(arg1 + 0x30);
        if (key != 0) {
            key_index = 0;
            while ((u16)key_index < *(u16 *)(arg1 + 0x38)) {
                if (key == *(u64 *)(u8 *)(u32)*(u32 *)(arg1 + ((key_index & 0xFFFF) * 4))) {
                    *(u16 *)(arg1 + 0x3A) = (u16)key_index;
                    return 1;
                }
                key_index = (key_index + 1) & 0xFFFF;
            }
        }
    }
no_key:
    if (arg0 == NULL)
        goto return_one;
    first = 1;
    func_001958f0((u8 *)(u32)*(u32 *)(arg0 + 0x30), &sp60.x);
    index = 0;
    goto distance_test;
distance_loop:
    func_001958f0(
        (u8 *)(u32)*(u32 *)((u8 *)(u32)*(u32 *)(arg1 + ((index & 0xFFFF) * 4)) + 0x30),
        &sp50.x);
    temp_f0 = func_001ec250(&sp60.x, &sp50.x);
    if ((temp_f0 < var_f20) || (first != 0)) {
        *(u16 *)(arg1 + 0x3A) = (u16)index;
        var_f20 = temp_f0;
        first = 0;
    }
    index = (index + 1) & 0xFFFF;
distance_test:
    if ((u16)index < *(u16 *)(arg1 + 0x38))
        goto distance_loop;
return_one:
    return 1;
}

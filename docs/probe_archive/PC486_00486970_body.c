/* measured: MATCH; object_size 224, window 224, normalized_diff 0. Key lever: changed the function return type from void to u_long128 and returned the early-path qword value; final path intentionally falls through. Parameter-width/pointer probes did not improve nd 5. */
u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2)
{
    u32 flags;
    u_long128 sp40;
    u_long128 value;
    f32 var_f20;

    if (((flags = *(s32 *)(arg0 + 0x68)) & 0x60) == 0) {
        value = *(u_long128 *)(arg0 + 0x50);
        *arg2 = value;
        return value;
    }
    func_0048a2b0(arg1, (u8 *)&sp40);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        var_f20 = 0.0f;
    } else {
        var_f20 = -func_0044b920(-*(f32 *)((u8 *)&sp40 + 4));
    }
    func_004bcf20(var_f20,
                  func_0044b950(*(f32 *)((u8 *)&sp40 + 0),
                                *(f32 *)((u8 *)&sp40 + 8)),
                  0.0f);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf11, $vf10\n"
            "lqc2 $vf10, 0x50(%0)\n"
            ".set reorder\n"
            :
            : "r"(arg0)
            : "$vf10", "$vf11", "memory");
        func_004bce50();
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(arg2) : "$vf10", "memory");
}

/* func_00485630 (code1_0048.c) 2026-09-26 round 2: the round-1 propagation-off
   draft (KoD_00485630_propoff_body.c) with the goto loop rewritten as a plain
   `for` over the child list with `continue`s - same 3 words
   (564B object / 576B window), the post-call restore's $v1 where retail has
   $v0.  See SceneNodeUpdate_00485630_00485870_20260926.md. */
#pragma push
#pragma opt_propagation off
void func_00485630(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    u_long128 spA0;
    u_long128 sp70;
    u_long128 sp60;
    u_long128 sp50q;
    f32 scale;
    f32 five;
    u8 *child;
    s32 count;
    u8 *temp_4;
    void (*temp_2)(s32, void *);
    void (*temp_3)(s32, void *);
    void (*temp_4fn)(s32);
    s32 child_flags;

    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
    if ((*(s32 *)(arg0 + 0x68) & 0x60) != 0) {
        u_long128 *save_slot = &sp50q;
        *save_slot = *(u_long128 *)(arg0 + 0x50);
        func_00486970(arg0, (u8 *)&spA0, &sp60);
        func_00486330(arg0, (u8 *)&sp60);
        save_slot = &sp50q;
        *(u_long128 *)(arg0 + 0x50) = *save_slot;
    }
    count = *(s32 *)(arg0 + 0x84);
    scale = *(f32 *)(arg0 + 0x60) * *(f32 *)(arg0 + 0x74);
    child = *(u8 **)(arg0 + 0x8C);
    five = 5.0f;
    for (; child != NULL; child = *(u8 **)(child + 0xAC)) {
        if (count < *(s32 *)(child + 0x80)) {
            continue;
        }
        if ((*(s32 *)(child + 0x84) & 2) != 0) {
            continue;
        }
        if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
            func_00486840(child, (u8 *)&spA0, &sp70);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
            child_flags = *(s32 *)(child + 0x68);
            if ((child_flags & 4) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vaddx.y $vf10, $vf0, $vf2x \n"
                    :
                    : "r"(five)
                    : "$vf2", "$vf10", "memory");
            }
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&sp70) : "$vf11", "memory");
            if ((child_flags & 0x80) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    :
                    : "r"(scale)
                    : "$vf2", "$vf11", "memory");
            }
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp70) : "$vf10", "memory");
            temp_4 = *(u8 **)(child + 0x90);
            temp_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
            if (temp_2 != NULL) {
                temp_2(*(s32 *)(temp_4 + 8), &sp70);
            }
        }
        if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
            func_00486970(child, (u8 *)&spA0, &sp60);
            temp_4 = *(u8 **)(child + 0x90);
            temp_3 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
            if (temp_3 != NULL) {
                temp_3(*(s32 *)(temp_4 + 8), &sp60);
            }
        }
        temp_4 = *(u8 **)(child + 0x90);
        (*(void (**)(s32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x08))(*(s32 *)(temp_4 + 8));
    }
    *(s32 *)(arg0 + 0x68) |= 0x80000000;
    *(s32 *)(arg0 + 0x84) += 1;
}
#pragma pop

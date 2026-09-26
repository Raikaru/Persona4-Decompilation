/* func_00485870 (code1_0048.c) 2026-09-25: 616B object / 624B window, 3
   differing words - the same restore colour as func_00485630 ($v1 where
   retail has $v0).  Same levers as KoD_00485630_propoff_body.c, plus the
   save/restore written with integer `arg0 + 0x50` (arg0 is s32) - the
   `(u8 *)arg0 + 0x50` spelling under propagation-off hoists arg0+0x50 into
   $s0 across the calls (126 edits). */
#pragma push
#pragma opt_propagation off
void func_00485870(s32 arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    u_long128 spA0;
    u_long128 sp90;
    u_long128 sp80;
    u8 sp70[16] __attribute__((aligned(16)));
    f32 scale;
    f32 five;
    u8 *child;
    s32 flags;
    s32 count_minus_1;
    u32 mask;
    u8 *temp_4;
    void (*temp_2)(s32, void *);
    void (*temp_3)(s32, void *);
    void (*temp_4fn)(s32);
    s32 child_flags;

    if (*(s32 *)((u8 *)arg0 + 0x84) <= 0) {
        return;
    }
    flags = *(s32 *)((u8 *)arg0 + 0x68);
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"((u8 *)arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"((u8 *)arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
    if ((flags & 0x60) != 0) {
        if ((flags & 0x80000000) == 0) {
            u_long128 *save_slot = (u_long128 *)sp70;
            *save_slot = *(u_long128 *)(arg0 + 0x50);
            func_00486970((u8 *)arg0, (u8 *)&spA0, &sp80);
            func_00486330((u8 *)arg0, (u8 *)&sp80);
            save_slot = (u_long128 *)sp70;
            *(u_long128 *)(arg0 + 0x50) = *save_slot;
        }
    }
    count_minus_1 = *(s32 *)((u8 *)arg0 + 0x84) - 1;
    scale = *(f32 *)((u8 *)arg0 + 0x60) * *(f32 *)((u8 *)arg0 + 0x74);
    child = *(u8 **)((u8 *)arg0 + 0x8C);
    mask = 0x80000000;
    five = 5.0f;
    goto loop_00485870_check;
loop_00485870_body:
    if (count_minus_1 < *(s32 *)(child + 0x80)) {
        goto loop_00485870_next;
    }
    if ((*(s32 *)(child + 0x84) & 2) != 0) {
        goto loop_00485870_next;
    }
    if ((flags & mask) != 0) {
        goto callback_0c;
    }
    if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
        func_00486840(child, (u8 *)&spA0, &sp90);
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
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&sp90) : "$vf11", "memory");
        if ((child_flags & 0x80) != 0) {
            __asm__ volatile(
                "qmtc2.ni %0, $vf2 \n"
                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                :
                : "r"(scale)
                : "$vf2", "$vf11", "memory");
        }
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp90) : "$vf10", "memory");
        temp_4 = *(u8 **)(child + 0x90);
        temp_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_2 != NULL) {
            temp_2(*(s32 *)(temp_4 + 8), &sp90);
        }
    }
    if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
        func_00486970(child, (u8 *)&spA0, &sp80);
        temp_4 = *(u8 **)(child + 0x90);
        temp_3 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_4 + 8), &sp80);
        }
    }
callback_0c:
    temp_4 = *(u8 **)(child + 0x90);
    (*(void (**)(s32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x0C))(*(s32 *)(temp_4 + 8));
loop_00485870_next:
    child = *(u8 **)(child + 0xAC);
loop_00485870_check:
    if (child != NULL) {
        goto loop_00485870_body;
    }
    {
        u32 v = *(u32 *)((u8 *)arg0 + 0x68);
        *(u32 *)((u8 *)arg0 + 0x68) = v & 0x7fffffffU;
    }
}
#pragma pop

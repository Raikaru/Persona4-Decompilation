/* func_00485630 (code1_0048.c) 2026-09-25: 564B object / 576B window (564B code
   + 12B zero pad), 3 differing words, all in the post-call restore:
   object `addiu $v1,$sp,0x50; lq $v1,0($v1); sq $v1,0x50($s2)`, retail the same
   with $v0.  Levers that took the prior 13-edit floor to 3:
   - `#pragma opt_propagation off` (push/pop): keeps the save/restore slot
     address in a scratch register at each use instead of folding it into
     sp+0x50 or holding it in $s0 across the calls (exact size).
   - VU transfers as `qmtc2.ni %0, $vf2` with an "r"(float) operand: MWCC emits
     the mfc1 + hazard nop itself, so the asm is pure COP2 (no $2 clobber).
   - the 0x08 callback called through the table expression directly, so the
     argument load precedes the table address. */
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
    goto loop_00485630_check;
loop_00485630_body:
    if (count < *(s32 *)(child + 0x80)) {
        goto loop_00485630_next;
    }
    if ((*(s32 *)(child + 0x84) & 2) != 0) {
        goto loop_00485630_next;
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
loop_00485630_next:
    child = *(u8 **)(child + 0xAC);
loop_00485630_check:
    if (child != NULL) {
        goto loop_00485630_body;
    }
    *(s32 *)(arg0 + 0x68) |= 0x80000000;
    *(s32 *)(arg0 + 0x84) += 1;
}
#pragma pop
#pragma pop

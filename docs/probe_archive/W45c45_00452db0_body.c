/* Best measured candidate: obj 756B, window 768B, differing words 4 (one real call-argument word at offset 0x248; 3 tail padding words). */
/* Levers: opt_propagation off; opt_common_subs off; pointer-typed first/call arguments; explicit u16 pointer constants. */
void func_00452db0(s32 arg0) {
    extern void func_00453250();
    s32 temp_2_2;
    s32 temp_3;
    volatile u16 *temp_2;
    volatile u16 *temp_6;
    u16 *temp_5_4;
    u16 temp_4_2;
    u16 temp_4_3;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;

    temp_3 = arg0 * 0x4A;
    temp_6 = (u16 *)(D_008C02EC + temp_3);
    temp_2 = (u16 *)(D_008C02F6 + temp_3);
    *temp_2 = (u16)(*temp_6 & 0xF0);
    temp_5 = D_008C02FC + temp_3;
    if ((s32)*temp_5 > 0xA5) {
        *temp_2 |= 0x2000;
    }
    if ((s32)*temp_5 < 0x5B) {
        *temp_2 |= 0x8000;
    }
    temp_5_2 = D_008C02FD + temp_3;
    if ((s32)*temp_5_2 > 0xA5) {
        *temp_2 |= 0x4000;
    }
    if ((s32)*temp_5_2 < 0x5B) {
        *temp_2 |= 0x1000;
    }
    temp_5_3 = D_008C02FE + temp_3;
    if ((s32)*temp_5_3 > 0xA5) {
        *temp_2 |= 0x40;
    }
    if ((s32)*temp_5_3 < 0x5B) {
        *temp_2 |= 0x80;
    }
    temp_4 = D_008C02FF + temp_3;
    if ((s32)*temp_4 > 0xA5) {
        *temp_2 |= 0x20;
    }
    if ((s32)*temp_4 < 0x5B) {
        *temp_2 |= 0x10;
    }
    temp_2_2 = arg0 * 0x4A;
    temp_4_2 = *(u16 *)(D_008C02EC + temp_2_2);
    temp_5_4 = (u16 *)(D_008C02EE + temp_2_2);
    *temp_5_4 = (u16)(temp_4_2 & (temp_4_2 ^ *(u16 *)(D_008C02F0 + temp_2_2)));
    temp_4_3 = *(u16 *)(D_008C02F6 + temp_2_2);
    *(u16 *)(D_008C02F8 + temp_2_2) = (u16)(temp_4_3 & (temp_4_3 ^ *(u16 *)(D_008C02FA + temp_2_2)));
    *(u16 *)(D_008C02F2 + temp_2_2) = *temp_5_4;
    func_00453250((void *)arg0, (u16 *)0x1000, (u16 *)0);
    func_00453250((void *)arg0, (u16 *)0x4000, (u16 *)1);
    func_00453250((void *)arg0, (u16 *)0x8000, (u16 *)2);
    func_00453250((void *)arg0, (u16 *)0x2000, (u16 *)3);
    func_00453250((void *)arg0, (u16 *)4, (u16 *)4);
    func_00453250((void *)arg0, (u16 *)1, (u16 *)5);
    func_00453250((void *)arg0, (u16 *)8, (u16 *)6);
    func_00453250((void *)arg0, (u16 *)2, (u16 *)7);
    func_00453250((void *)arg0, (u16 *)0x40, (u16 *)8);
    func_00453250((void *)arg0, (u16 *)0x20, (u16 *)9);
    func_00453250((void *)arg0, (u16 *)0x10, (u16 *)0xA);
    func_00453250((void *)arg0, (u16 *)0x80, (u16 *)0xB);
}

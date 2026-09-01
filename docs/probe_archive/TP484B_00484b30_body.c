/* Archived twin-port body for func_00484b30.
 * Donor FUN_00324b50 also uses inline asm. The lq/sq quadword transfer is
 * required for the retail shape but triggers H009; policy requires bare asm.
 */
u32 func_00484b30(u8 *arg0)
{
    u8 *pauVar5;
    u32 source;
    func_0043f9c8(arg0, 0, 0x80);
    pauVar5 = arg0;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(pauVar5) : "memory");
    __asm__ volatile ("sqc2 vf0, 16(%0)" : : "r"(pauVar5) : "memory");
    __asm__ volatile ("sqc2 vf0, 64(%0)" : : "r"(pauVar5) : "memory");
    *(u32 *)(pauVar5 + 0x44) = 0x40a00000;
    __asm__ volatile ("sqc2 vf0, 80(%0)" : : "r"(pauVar5) : "memory");
    source = (u32)D_00713CE0;
    __asm__ volatile ("lq %0, 0(%0)\n" "sq %0, 0x20(%1)\n" : "+r"(source) : "r"(pauVar5) : "memory");
    *(u32 *)(pauVar5 + 0x60) = 0x3f800000;
    *(u32 *)(pauVar5 + 0x74) = 0x3f800000;
    *(u32 *)(pauVar5 + 0x64) = 0xffffffff;
    *(u32 *)(pauVar5 + 0x68) = 0x80;
    return source;
}

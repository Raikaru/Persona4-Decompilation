/* Main 2026-09-03: re-probed. Assigning temp_18 before temp_17 gives retail's registers (s1/s2) but
   moves the pointer arithmetic above the lh (nd4); assigning temp_17 first keeps the order and swaps
   the registers (nd8). All 120 declaration orders of the five locals: nd8. schedule on: nd148 (the
   unit is schedule-off). AST permuter 18k compiles: best 6. Allocation follows assignment order here
   and the emission order follows it too - still open. */
/* IDA-backed replay: 4 differing words (relocation masked), still ASM.
 * docs/ida_headstart/src/Battle/btlCutin.c confirms the case-local suffix
 * pointer, signed count, three-name table and resource slots. Pointer-first
 * assignment retains the known instruction-order floor with retail colors.
 * Use canonical helper types, explicit string pointers for variadic calls,
 * and 32-bit resource handles. A native smoke using retail format strings
 * and S/W, B/C/D tables passes 3,136 cases: modes, counts, suffix flags,
 * the character-11 branch, call order, resource slots and untouched bytes.
 * Ordinary register hints on either count-first local still score 8.
 */
void func_001f9cf0(u8 *arg0) {
    extern s16 func_001060b0(void);
    extern s32 func_00110d60(s32);
    extern s32 func_00442088(void *, const void *, ...);
    extern s32 func_00440b68(const void *, ...);
    extern u8 *func_00454a60(u8 *, s32);
    s32 temp_17;
    const u32 *temp_18;
    s32 temp_16;
    s32 temp_5;
    s32 var_19;
    u8 sp60[0x100];

    temp_5 = (func_00110d60(func_001060b0()) & 1) != 0;
    switch (*(u16 *)arg0) {
    case 0:
        temp_18 = (const u32 *)(&iGpffffa520 + temp_5 * 4);
        temp_17 = *(s16 *)(arg0 + 8);
        func_00442088(sp60, D_00625060, temp_17 + 1, temp_17 + 1, (const char *)*temp_18);
        func_00440b68(&iGpffffa528, D_00625090, 0x26);
        *(s32 *)(iGpffffb3ac + 0xB6C) = (u32)func_00454a60(sp60, 0);
        var_19 = 0;
        while (var_19 < temp_17) {
            temp_16 = var_19 * 4;
            func_00442088(sp60, D_006250A0, temp_17 + 1, temp_17 + 1,
                          (const char *)*(u32 *)(D_00625050 + temp_16),
                          *(s16 *)(arg0 + var_19 * 2 + 2), (const char *)*temp_18);
            func_00440b68(&iGpffffa528, D_00625090, 0x2C);
            *(s32 *)(iGpffffb3ac + temp_16 + 0xB70) = (u32)func_00454a60(sp60, 0);
            var_19++;
        }
        func_00442088(sp60, D_006250D0, temp_17 + 1, temp_17 + 1);
        func_00440b68(&iGpffffa528, D_00625090, 0x2F);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)func_00454a60(sp60, 0);
        break;
    case 2:
        func_00442088(sp60, D_00625100, *(s16 *)(arg0 + 2),
                      (const char *)*(const u32 *)(&iGpffffa520 + temp_5 * 4));
        func_00440b68(&iGpffffa528, D_00625090, 0x35);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)func_00454a60(sp60, 0);
        break;
    case 4:
        if (*(s16 *)(arg0 + 2) < 0xB) {
            func_00442088(sp60, D_00625130, *(s16 *)(arg0 + 2));
        } else {
            func_00442088(sp60, D_00625160, *(s16 *)(arg0 + 2));
        }
        func_00440b68(&iGpffffa528, D_00625090, 0x40);
        *(s32 *)(iGpffffb3ac + 0xB58) = (u32)func_00454a60(sp60, 0);
        break;
    }
    *(u16 *)(iGpffffb3ac + 0xB50) = *(u16 *)arg0;
}

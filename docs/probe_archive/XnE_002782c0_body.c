/* Re-measured 2026-09-01: baseline body object 388 bytes in a 400-byte retail window, normalized_diff 10, differing word offsets 80,84,88. Retail case 0 emits move $a0,$s1; move $a1,$s0; addiu $a2,$sp,0x30, while MWCC b210 emits the address addiu first. Retail's saved-register list is $s1=param_1 and $s0=param_2, both established before the earlier func_00442088 call; the candidate already passes those saved values and does not re-derive either argument. The $a2 value is &sp30, also used as func_00442088's first argument, not a shared scalar literal. Tested parameter aliases, shared integer/pointer address locals, a case-local pointer assigned after the earlier call, opt_propagation off aliases, and a void formatter prototype; none changed the three-word residual (the pointer-before-switch form grew the frame to 0x50 and nd77). Retail address register is $a2, confirming the three-argument func_00278450 order. Retain as argument-setup scheduling floor. */
void func_002782c0(int param_1, int param_2, int param_3, u32 param_4) {
    char sp30[16];

    switch (param_4) {
    case 0:
        func_00442088(sp30, &iGpffffa760, param_3);
        func_00278450(param_1, param_2, (int)sp30);
        break;
    case 1:
        func_002784e0(param_1, param_2, param_3);
        break;
    case 2:
        func_00278450(param_1, param_2, iGpffffb444 + param_3 * 21);
        break;
    case 3:
        func_00278450(param_1, param_2, func_002438b0(param_3 & 0xFF));
        break;
    case 4:
        func_00278450(param_1, param_2, func_0010d620((s16)param_3));
        break;
    case 5:
        func_00278450(param_1, param_2, func_001067f0((s16)param_3));
        break;
    case 6:
        func_00278450(param_1, param_2, func_00243840(param_3 & 0xFFFF));
        break;
    case 7:
        func_00278450(param_1, param_2, func_00109220(param_3 & 0xFFFF));
        break;
    }
}

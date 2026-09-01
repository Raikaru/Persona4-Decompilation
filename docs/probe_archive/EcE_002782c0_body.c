/* Re-measured by EcE: object 388 bytes, retail window 400 bytes, normalized_diff 10.
 * First differing byte offsets: 80,81,82,83,85,86,88,89,90,91
 * (word offsets 80,84,88; relocations masked).
 * The switch dispatch, all eight cases, narrow masks, table addressing, and
 * helper calls match retail. Residual is case 0 func_00278450 argument setup:
 * retail emits move $a0,$s1; move $a1,$s0; addiu $a2,$sp,0x30, while MWCC
 * b210 hoists the pure address-of addiu before the two moves. Probes ruled out
 * buffer/field types, pointer and integer casts, named argument/result locals,
 * declaration and statement order, callee prototypes, switch/case shapes, and
 * optimization/scheduling pragmas. Address-of argument setup is a codegen floor.
 */
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

// object_size 440, window 448, normalized_diff 254, differing offsets 33 38 46 50 57 61 62 63 65 66 69 70 73 80 81 82, instruction deficit 2; classification register allocation and declaration-order residual; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-saved callee register, and size deficit after frame/prototype probes.
u32 func_001d2e20(u8 *param_1)
{
    f32 output[4];
    f32 auxiliary[4];
    s16 mode;
    s32 has_unit;
    s64 category;
    u8 *unit;
    u8 *node;
    extern s64 func_00199d00();
    extern s32 func_001f1210();
    extern void func_001951f0();

    node = *(u8 **)(param_1 + 0);
    unit = *(u8 **)(*(u8 **)(param_1 + 4) + 0x30);
    mode = *(s16 *)(param_1 + 0xc);
    has_unit = *(u32 *)(param_1 + 8) != 0;
    category = (s16)func_00199d00(node, unit, (s64)mode, has_unit);
    if (func_001f1210(node, (s64)mode, has_unit) == 0) {
        switch ((s16)func_00199d00(node, unit, (s64)mode, has_unit)) {
        case 3:
        case 1:
            func_001951f0(node, unit, NULL, category, &output, &auxiliary, 1);
            break;
        case 2:
        case 0:
            func_001951f0(node, unit, NULL, category, &output, &auxiliary, 0);
            break;
        }
        func_00194f10(node, &auxiliary);
        func_00194ee0(node, &output);
    } else {
        func_001951f0(node, unit, *(u8 **)(*(u8 **)(param_1 + 8) + 0x30),
                      category, &output, &auxiliary, 2);
        func_00194f10(node, &auxiliary);
        func_00194ee0(node, &output);
    }
    return 1;
}

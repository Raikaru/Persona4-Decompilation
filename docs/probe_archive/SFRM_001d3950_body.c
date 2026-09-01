// object_size 500, window 512, normalized_diff 14, differing offsets 106 108 110 111 114 115 118 119 160 164 168 174 178 182, instruction deficit 3; classification aggregate-load register/order plus table-load FPU order; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-vs-sq callee-save floors
u32 func_001d3950(u8 **param_1)
{
    typedef union FormationPair {
        u64 whole;
        f32 values[2];
    } FormationPair;
    typedef struct FormationScratch {
        f32 delta[3];
        u32 gap0;
        FormationPair position;
        f32 position_z;
        u32 gap1;
    } FormationScratch;
    FormationScratch scratch;
    u8 *current;
    u16 index;
    f32 source2;
    f32 source1;
    f32 source0;
    extern void func_001ec6d0(s16 *arg0, s16 *arg1, f32 *arg2);
    index = 0;
    current = *(u8 **)(D_0076449C + 0x17c);
    while (current != NULL) {
        if (((*(u32 *)(current + 0x9c) & 8) != 0) &&
            (func_002428f0(*(u32 *)(current + 0xa64), 0) == 0)) {
            if (*(u8 **)(*param_1 + 0x30) == current) {
                scratch.position.whole = D_00881430[0];
                scratch.position_z = D_00881438[0];
            } else {
                source1 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 0);
                source2 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 4);
                source0 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 8);
                scratch.position.values[0] = source1;
                scratch.position.values[1] = source2;
                scratch.position_z = source0;
            }
            func_001ec6d0((s16 *)(current + 0x94), (s16 *)(current + 0x96), scratch.position.values);
            scratch.position.values[0] = (f32)((s32)*(s16 *)(current + 0x94) * 25 - 1750);
            scratch.position_z = (f32)((s32)*(s16 *)(current + 0x96) * 25 - 1750);
            if (*(u8 **)(*param_1 + 0x30) != current) {
                func_003e40b0(scratch.delta, scratch.position.values);
                {
                    f32 scale;
                    scale = *(f32 *)(D_00609458 + (index & 0xffff) * 4);
                    scratch.delta[0] *= scale;
                    scratch.delta[1] *= scale;
                    scratch.delta[2] *= scale;
                    scratch.position.values[0] += scratch.delta[0];
                    scratch.position.values[1] += scratch.delta[1];
                    scratch.position_z += scratch.delta[2];
                }
                index++;
            }
            func_00194ee0(current, scratch.position.values);
            func_00194f10(current, D_0060A110);
        }
        current = *(u8 **)(current + 0xa68);
    }
    return 1;
}

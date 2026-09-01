// object_size 500, window 512, normalized_diff 11, differing offsets 112 120 160 164 168 172 176 180; instruction deficit 3; classification aggregate default-copy z-width plus table-load FPU order; ruled out movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-vs-sq callee-save floors
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
    typedef struct FormationDefault {
        u64 whole;
        f32 z;
    } FormationDefault;
    extern void func_001ec6d0(s16 *arg0, s16 *arg1, f32 *position);
    extern u8 D_00609430[];
    extern f32 D_00609458[];
    extern f32 D_0060A110[];
    extern FormationDefault D_00881430;
    FormationScratch scratch;
    u8 *current;
    u16 index;
    f32 source2;
    f32 source1;
    f32 source0;
    index = 0;
    current = *(u8 **)(D_0076449C + 0x17c);
    while (current != NULL) {
        if (((*(u32 *)(current + 0x9c) & 8) != 0) &&
            (func_002428f0(*(u32 *)(current + 0xa64), 0) == 0)) {
            if (*(u8 **)(*param_1 + 0x30) == current) {
                *(FormationDefault *)&scratch.position = D_00881430;
            } else {
                source1 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 0);
                source2 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 4);
                source0 = *(f32 *)(D_00609430 + (index & 0xffff) * 0xc + 8);
                scratch.position.values[0] = source1;
                scratch.position.values[1] = source2;
                scratch.position_z = source0;
            }
            func_001ec6d0((s16 *)(current + 0x94),
                          (s16 *)(current + 0x96),
                          scratch.position.values);
            scratch.position.values[0] =
                (f32)((s32)*(s16 *)(current + 0x94) * 25 - 1750);
            scratch.position_z =
                (f32)((s32)*(s16 *)(current + 0x96) * 25 - 1750);
            if (*(u8 **)(*param_1 + 0x30) != current) {
                func_003e40b0(scratch.delta, scratch.position.values);
                {
                    f32 scale;
                    scale = D_00609458[index & 0xffff];
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

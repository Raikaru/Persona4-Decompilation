// object_size 500, window 512, normalized_diff 0, differing offsets none; fndiff reports three trailing zero-pad words outside the 500-byte object; closure via block-local scalar initializers under opt_propagation off; ruled out field-by-field table copy, direct packed default aggregate, scalar default assignments without block-local initialization, opt_common_subs, and pragma removal
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
    typedef struct FormationDefault
    {
        u64 whole;
        u32 z : 32;
    } __attribute__((packed)) FormationDefault;
    typedef struct FormationPosition {
        f32 x;
        f32 y;
        f32 z;
    } FormationPosition;
    extern void func_001ec6d0(s16 *arg0, s16 *arg1, f32 *position);
    extern u8 D_00609430[];
    extern f32 D_00609458[];
    extern f32 D_0060A110[];
    extern FormationDefault D_00881430;
    extern FormationPosition D_00881438;
    FormationScratch scratch;
    u8 *current;
    u16 index;
    index = 0;
    current = *(u8 **)(D_0076449C + 0x17c);
    while (current != NULL) {
        if (((*(u32 *)(current + 0x9c) & 8) != 0) &&
            (func_002428f0(*(u32 *)(current + 0xa64), 0) == 0)) {
            if (*(u8 **)(*param_1 + 0x30) == current) {
                {
                    u64 default_pair = D_00881430.whole;
                    f32 default_z = D_00881438.x;
                    scratch.position.whole = default_pair;
                    scratch.position_z = default_z;
                }
            } else {
                *(FormationPosition *)&scratch.position =
                    *(FormationPosition *)(D_00609430 +
                                           (index & 0xffff) * 0xc);
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

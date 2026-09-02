// func_001cb610 attempted body (did not reach MATCH)
// lane: D1c
// object: 224B frame matches retail (0xe0), no f20 save
// window: 848B
// differing words (reloc-masked) with this body: 172 in scratch build (object 908B)
// residuals:
//   - 200.0 constant lands in f1, result in f0; retail keeps 200.0 in f2 and uses f5/f1/f4
//   - valueC0 (B0 + D0 - B0) chain is computed x->y->z; retail interleaves y sum first
//   - 0.5f * -30.0f is constant-folded to -15.0 (lui 0xc170); retail computes it at runtime
//   - scale is stored/loaded from frame; retail keeps it in a local/stack slot without extra copies
//   - min-clamp of value34/value50 uses sw v0 (bit pattern); retail uses swc1 f0
// levers tried:
//   - struct Frame with explicit small f32 fields and u8 pad70[12] for 0x70 matrix alignment
//   - named local f200 = 200.0f for the three multiplies
//   - source written as 0.0f + valueB0.y + fGp... to match adda/madd sequence
//   - opt_propagation off and opt_common_subs off (needed for the 0xe0 frame layout)
//   - product/call argument order permutations

void func_001cb610(u8 *arg0)
{
    u8 *unit;
    u8 *self;
    struct Frame {
        f32 value30;
        f32 value34;
        f32 value38;
        f32 value3C;
        f32 value40;
        f32 value44;
        f32 scale;
        f32 value4C;
        f32 value50;
        f32 value54;
        f32 value58;
        f32 value5C;
        f32 value60;
        u8 pad70[12];
        f32 value70[4][4];
        struct Vec3P {
            f32 x;
            f32 y;
            f32 z;
            u8 pad[4];
        } valueB0, valueC0, valueD0;
    } frame;

    self = arg0;
    unit = *(u8 **)(*(u8 **)(*(u8 **)(self + 0xE0) + 0x38) + 0x30);
    func_001959d0(unit, &frame.valueB0.x);
    frame.valueB0.y = 0.0f + frame.valueB0.y + fGpffff8188 * ((*(f32 *)(unit + 0x8C)) * (*(f32 *)(unit + 0x2C)));
    frame.valueB0.y += 10.0f;
    func_003dcb40((s64 *)&frame.valueC0.x, (s64 *)D_0060A100, 1, unit + 0x1C);
    {
        f32 f200 = 200.0f;
        frame.valueD0.x = f200 * frame.valueC0.x;
        frame.valueD0.y = f200 * frame.valueC0.y;
        frame.valueD0.z = f200 * frame.valueC0.z;
    }
    frame.valueC0.x = (frame.valueB0.x + frame.valueD0.x) - frame.valueB0.x;
    frame.valueC0.y = (frame.valueB0.y + frame.valueD0.y + 10.0f) - frame.valueB0.y;
    frame.valueC0.z = (frame.valueB0.z + frame.valueD0.z) - frame.valueB0.z;
    func_003e40b0(&frame.valueC0.x, &frame.valueC0.x);
    func_003e0870((f32 *)&frame.value70, D_0060A0E0, 0.5f * -30.0f, 0);
    func_003e4320(&frame.valueD0.x, &frame.valueC0.x, (f32 *)&frame.value70);
    frame.scale = 115.0f / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(self + 0xB8)));
    frame.valueD0.x *= frame.scale;
    frame.valueD0.y *= frame.scale;
    frame.valueD0.z *= frame.scale;
    frame.value30 = frame.valueB0.x + frame.valueD0.x;
    frame.value34 = frame.valueB0.y + frame.valueD0.y;
    frame.value38 = frame.valueB0.z + frame.valueD0.z;
    func_001bd780(&frame.value3C, &frame.value30, &frame.valueB0.x, D_0060A0E0);
    func_003e0870((f32 *)&frame.value70, D_0060A0E0, 15.0f, 0);
    func_003e4320(&frame.valueD0.x, &frame.valueC0.x, (f32 *)&frame.value70);
    frame.scale = 165.0f / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(self + 0xB8)));
    frame.valueD0.x *= frame.scale;
    frame.valueD0.y *= frame.scale;
    frame.valueD0.z *= frame.scale;
    frame.value4C = frame.valueB0.x + frame.valueD0.x;
    frame.value50 = frame.valueB0.y + frame.valueD0.y;
    frame.value54 = frame.valueB0.z + frame.valueD0.z;
    func_001bd780(&frame.value58, &frame.value4C, &frame.valueB0.x, D_0060A0E0);
    if (frame.value34 < 25.0f) {
        frame.value34 = 25.0f;
    }
    if (frame.value50 < 25.0f) {
        frame.value50 = 25.0f;
    }
    func_001bcd40(*(u8 **)(self + 0xE0), NULL, NULL, 0.0f, 3);
    func_001bac20(self, &frame.value30, &frame.value4C, 1);
    func_001bbef0(self, 2.0f);
}

/*
 * LANE: code1_003e
 * ADDR: 003e7d50
 * OBJECT/WINDOW/ND: 388B / 400B / MISMATCH (65 reloc-masked differing words)
 * DIFFERING OFFSETS (reloc-masked):
 *   4, 12, 20, 24, 28, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92,
 *   96, 100, 104, 108, 112, 116, 136, 140, 144, 148, 156, 172, 176, 180, 184,
 *   188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 256, 260, 264, 268, 276,
 *   292, 300, 308, 316, 320, 324, 328, 332, 336, 340, 344, 364
 * LEVERS RULED OUT:
 *   - schedule on (needed for madd/mula chain, but prologue/register allocation
 *     still diverges)
 *   - opt_propagation off (did not fix constant/register allocation)
 *   - in-place variable reuse and matrix-first / parent-first local ordering
 *     (parent base ends up in a2/v1 instead of a3, scale/result f5 not kept
 *     in f5 for first block)
 *   - literal 0.5f / -0.5f (constants loaded into f7/f9 but lui reused $v0)
 */

#pragma opt_propagation off
#pragma schedule on
extern void func_003e03e0(u8 *, u8 *);

u8 *func_003e7d50(u8 *arg0) {
    u8 *matrix;
    u8 *parent;
    u8 *self;
    f32 f5;
    f32 f1;
    f32 f6;
    f32 f4;
    f32 f3;
    f32 f2;
    f32 f0;
    f32 dot;

    matrix = arg0 + 0x20;
    parent = *(u8 **)(arg0 + 4);
    self = arg0;

    f5 = *(f32 *)(arg0 + 0x70);
    f5 = -0.5f * f5;
    f1 = *(f32 *)(arg0 + 0x78);
    f1 = f5 * f1;
    f6 = -f1;
    f3 = *(f32 *)(parent + 0x54);
    f3 = f3 * f5;
    f2 = *(f32 *)(parent + 0x58);
    f2 = f2 * f5;
    f4 = *(f32 *)(parent + 0x50);
    f0 = *(f32 *)(parent + 0x70);
    f5 = f4 * f5 + f0 * f6;
    f1 = *(f32 *)(parent + 0x74);
    f0 = *(f32 *)(parent + 0x78);
    f4 = f3 + f1 * f6;
    f3 = f2 + f0 * f6;
    *(f32 *)(arg0 + 0x20) = f5;
    *(f32 *)(arg0 + 0x30) = f4;
    *(f32 *)(arg0 + 0x40) = f3;

    dot = *(f32 *)(parent + 0x84) * f4;
    dot += *(f32 *)(parent + 0x80) * f5;
    dot += *(f32 *)(parent + 0x88) * f3;
    dot = 0.5f - (f6 + dot);
    *(f32 *)(arg0 + 0x50) = dot;

    f5 = *(f32 *)(arg0 + 0x74);
    f5 = -0.5f * f5;
    f1 = *(f32 *)(arg0 + 0x7C);
    f1 = f5 * f1;
    f6 = f1;
    f3 = *(f32 *)(parent + 0x64);
    f3 = f3 * f5;
    f2 = *(f32 *)(parent + 0x68);
    f2 = f2 * f5;
    f4 = *(f32 *)(parent + 0x60);
    f0 = *(f32 *)(parent + 0x70);
    f5 = f4 * f5 + f0 * f6;
    f1 = *(f32 *)(parent + 0x74);
    f0 = *(f32 *)(parent + 0x78);
    f4 = f3 + f1 * f6;
    f3 = f2 + f0 * f6;
    *(f32 *)(arg0 + 0x24) = f5;
    *(f32 *)(arg0 + 0x34) = f4;
    *(f32 *)(arg0 + 0x44) = f3;

    dot = *(f32 *)(parent + 0x84) * f4;
    dot += *(f32 *)(parent + 0x80) * f5;
    dot += *(f32 *)(parent + 0x88) * f3;
    dot = 0.5f - (f6 + dot);
    *(f32 *)(arg0 + 0x54) = dot;

    *(f32 *)(arg0 + 0x28) = *(f32 *)(parent + 0x70);
    *(f32 *)(arg0 + 0x38) = *(f32 *)(parent + 0x74);
    *(f32 *)(arg0 + 0x48) = *(f32 *)(parent + 0x78);

    dot = *(f32 *)(parent + 0x84) * *(f32 *)(parent + 0x74);
    dot += *(f32 *)(parent + 0x80) * *(f32 *)(parent + 0x70);
    dot += *(f32 *)(parent + 0x88) * *(f32 *)(parent + 0x78);
    dot = -dot;
    *(f32 *)(arg0 + 0x58) = dot;

    func_003e03e0(matrix, NULL);
    return self;
}
#pragma schedule off
#pragma opt_propagation on

/* Complete visual expansion/fade candidate; production remains ASM.
 * Current canonical-owner replay: 824/800 bytes, nd500 (476 differing
 * in-window bytes plus24 overrun bytes), ten relocations. Initializing the
 * two aggregates from decoded retail literal values produces the same
 * score and size. No padding or omitted renderer argument is retained.
 * The old build/WU01_00267800.c candidate is absent; its historical nd279
 * cannot be reproduced or treated as evidence for this source.
 *
 * Required owner integration before replay:
 * typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
 * typedef struct { f32 value[19]; } Code1_00267800ScaleTable;
 * extern Code1_00267800ShapeTable D_00638FD0;
 * extern Code1_00267800ScaleTable D_00639020;
 * Replace the old s32[] declarations, not merely their uses.
 * Replace the renderer declaration with all six integer slots:
 *   void func_00267b20(s32,s32,s32,s32,s64,s64,
 *                     f32,f32,f32,f32,f32,f32);
 * Its third integer argument is real even though the provider overwrites it.
 * Use void *func_0043f810(void *, const void *, u32), the real copy provider.
 * Remove unused Code1_00267800Frame and the three target-specific inline
 * index/index90/mul helpers; retain the unrelated00263220 helpers.
 * Keep the preceding optimization_level2 restoration and00267670's existing
 * s32(u8 **,u8 *) call contract. No provider/caller code changes are needed
 * for the scratch body beyond these declaration replacements.
 *
 * Both copied tables have exactly19 words. The actual producer creates19
 * 0x4C-byte source records, whose indices cover0..18, and0x58-byte payloads.
 * It initializes the whole16-byte position at payload+0x28; its fourth float
 * is legitimately overwritten by scale. No source holes are made members.
 * Shape words:0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,2. Scale words are f32
 * data, not integers requiring conversion. Preserve original symbols.
 * Render callbacks may change the item's index; later calls reload it.
 * The three colored passes use !(scale<=threshold), including unordered
 * inputs; completion returns1 when !(scale<7), not only when scale>=7.
 * Float-to-int conversions still require finite representable operands;
 * neither a final clamp nor fabricated validation is added.
 */
s32 func_00267800(u8 **arg0, u8 *arg1)
{
    f32 position[4];
    Code1_00267800ShapeTable shapes;
    Code1_00267800ScaleTable scales;
    s32 alpha;
    s32 shape;

    func_0043f810(position, arg1 + 0x28, sizeof(position));
    position[2] += -136.0f + (150.0f * *(f32 *)((u8 *)arg0 + 4)) / 120.0f;
    position[0] += 288.0f;
    position[1] += 222.0f;

    shapes = D_00638FD0;
    scales = D_00639020;

    alpha = 0xFF;
    position[3] = *(f32 *)((u8 *)arg0 + 8) * scales.value[*(s32 *)(arg1 + 4)];
    if (position[3] < fGpffff8218) {
        alpha = (s32)((255.0f * position[3]) / fGpffff8218);
    }
    alpha = (s32)((f32)alpha * ((f32)*(s32 *)((u8 *)arg0 + 0xC) / 255.0f));

    shape = shapes.value[*(s32 *)(arg1 + 4)];
    if (shape != 9) {
        if (!(position[3] <= fGpffff8218)) {
            func_00267b20(0x76BF48, alpha, 1, shape, 0, 0,
                           position[0], position[1], 0.0f, 4.0f + position[2],
                           position[3], position[3]);
            func_00267b20(0x4883BF, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[0], position[1], 0.0f, 2.0f + position[2],
                           position[3], position[3]);
            func_00267b20(0xBF4848, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[0], position[1], 0.0f, position[2] - 2.0f,
                           position[3], position[3]);
        }
        func_00267b20(0x292929, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                       position[0], position[1], 0.0f, position[2],
                       position[3], position[3]);
    }

    if (position[3] < 7.0f) {
        return 0;
    }
    return 1;
}

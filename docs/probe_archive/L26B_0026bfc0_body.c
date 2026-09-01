/* 2026-08-14 remeasure: object 460B, window 464B, normalized_diff 9; fndiff residual words 0x70, 0x78, 0x80, 0x88, 0x8C (retail-only tail padding at 0x1CC). Corrected func_003e4320 return type from void to u8 *; the body remains nd 9. Residual classification: axis2's 12-byte SceneVecBits aggregate copy emits a second 8-byte ld/sd where retail uses lwc1/swc1, and axis3 global loads are scheduled/register-colored differently. The retail window contains the confirmed COP1 accumulator chain adda.s/msub.s, so this is archived on sight as a compiler floor. Ruled-out probes: axis2 direct-width scalar copy (nd 68), direct axis3 loads (nd 69), axis3 field-staging, separate axis3 locals, reversed axis3 source order, uniform typed component access, comma-sequenced loads, named axis3 pointer, aggregate axis3 copy, optimization_level 1 (92 differing words, 484B object), and permute.py seed 0x260812 (1817 compiles/185s, best score 9); no volatile or inline asm used. */
void func_0026bfc0(f32 *input, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 *result) {
    typedef struct SceneMatrixLocal {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixLocal;
    typedef union SceneVectorLocal {
        RwV3d value;
        struct {
            u64 xy;
            f32 z;
            u32 pad;
        } raw;
    } SceneVectorLocal;
    extern SceneVecBits D_0063B120[];
    extern f32 D_0063B128[];
    extern SceneVecBits D_0063B130[];
    extern f32 D_0063B138[];
    extern SceneVecBits D_0063B140[];
    extern f32 D_0063B148[];
    extern SceneVecBits D_0063B150[];
    extern f32 D_0063B158[];
    SceneVectorLocal axis0;
    SceneVectorLocal transformed;
    SceneVectorLocal source;
    SceneVectorLocal output;
    SceneVectorLocal axis1;
    SceneVectorLocal axis2;
    SceneVectorLocal axis3;
    SceneMatrixLocal matrix;
    u64 xy;
    f32 z;

    xy = *(u64 *)D_0063B120;
    z = *(f32 *)D_0063B128;
    axis0.raw.xy = xy;
    axis0.raw.z = z;
    xy = *(u64 *)D_0063B130;
    z = *(f32 *)D_0063B138;
    axis1.raw.xy = xy;
    axis1.raw.z = z;
    *(SceneVecBits *)&axis2.raw.xy = *(SceneVecBits *)D_0063B140;
    xy = *(u64 *)D_0063B150;
    z = *(f32 *)D_0063B158;
    axis3.raw.xy = xy;
    axis3.raw.z = z;

    matrix.at.z = 1.0f;
    matrix.up.y = 1.0f;
    matrix.right.x = 1.0f;
    matrix.up.x = 0.0f;
    matrix.right.z = 0.0f;
    matrix.right.y = 0.0f;
    matrix.at.y = 0.0f;
    matrix.at.x = 0.0f;
    matrix.up.z = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.x = 0.0f;
    matrix.flags |= 0x20003;

    func_003e0870(&matrix, &axis2.value, fparg2, 1);
    func_003e0870(&matrix, &axis1.value, fparg1, 1);
    func_003e0870(&matrix, &axis3.value, fparg3, 1);
    func_003e4320(&transformed, &axis0, &matrix);
    source.value = *(RwV3d *)input;
    output.value.x = source.value.x - transformed.value.x * fparg0;
    output.value.y = source.value.y - transformed.value.y * fparg0;
    output.value.z = source.value.z - transformed.value.z * fparg0;
    *(RwV3d *)result = output.value;
}

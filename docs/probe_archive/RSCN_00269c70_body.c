/* object 320B/window 320B, normalized_diff 31, differing offsets 0x40-0x60 and 0xF8/0x108/0x118; exact frame/prologue; classification: load-order and argument-materialization scheduling residual; ruled out: direct globals, aggregate locals, pointer temporary, declaration/frame mismatch. */
void func_00269c70(f32 *result, f32 *input, f32 angle0, f32 angle1, f32 scale)
{
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
    SceneVectorLocal transformed;
    SceneVectorLocal source;
    SceneVectorLocal axis;
    SceneMatrixLocal matrix;
    u64 xy;
    f32 z;
    SceneVectorLocal *axis_ptr;

    xy = *(u64 *)D_0063B0F0;
    z = *(f32 *)D_0063B0F8;
    source.raw.xy = xy;
    source.raw.z = z;
    axis_ptr = &axis;
    xy = *(u64 *)D_0063B100;
    z = *(f32 *)D_0063B108;
    axis.raw.xy = xy;
    axis.raw.z = z;

    func_003e0870(&matrix, axis_ptr, -angle1, 0);
    func_003e4320(&source, &source, &matrix);
    axis.value.x = 0.0f;
    axis.value.y = 1.0f;
    axis.value.z = 0.0f;
    func_003e0870(&matrix, axis_ptr, angle0, 0);
    func_003e4320(&transformed, &source, &matrix);
    func_003e40b0(&transformed, &transformed);
    transformed.value.x = transformed.value.x * scale;
    transformed.value.y = transformed.value.y * scale;
    transformed.value.z = transformed.value.z * scale;
    result[0] = input[0] + transformed.value.x;
    result[1] = input[1] + transformed.value.y;
    result[2] = input[2] + transformed.value.z;
}

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

/* LaneFldFrame candidate archive: semantic C reconstruction measured non-MATCH; reverted to INCLUDE_ASM pending register/stack-layout closure. */
s32 func_00169780(s32 collisionWorld, f32* origin,
                  f32* vector, f32 fraction)
{
    typedef struct FldFrameHitBuffer69780
    {
        RwV3d points[64];
        RwV3d vectors[64];
        f32 fractions[64];
        u8 unused[0x404];
        s32 count;
    } FldFrameHitBuffer69780;
    typedef struct FldFrameIntersection69780
    {
        f32 data[6];
        s32 type;
    } FldFrameIntersection69780;
    FldFrameHitBuffer69780 hits __attribute__((aligned(16)));
    FldFrameIntersection69780 intersection __attribute__((aligned(16)));
    RwV3d delta;
    f32 products[3];
    f32 endpoint[4];
    f32 scale;
    f32 dot;
    s32 i;
    s32 result;

    result = 0;
    endpoint[0] = origin[0] + vector[0];
    endpoint[1] = origin[1] + vector[1];
    endpoint[2] = origin[2] + vector[2];
    endpoint[3] = fraction;
    intersection.data[0] = endpoint[0];
    intersection.data[1] = endpoint[1];
    intersection.data[2] = endpoint[2];
    intersection.data[3] = endpoint[3];
    intersection.type = 3;
    for (i = 0; i < 64; i++)
    {
        func_0043f9c8(&hits.points[i], 0, 0xc);
        func_0043f9c8(&hits.vectors[i], 0, 0xc);
        hits.fractions[i] = fGpffff82b4;
    }
    hits.count = 0;
    if (collisionWorld != 0)
    {
        func_00394d70((void*)collisionWorld, &intersection,
                      func_00169320, &hits);
        for (i = 0; i < hits.count; i++)
        {
            if (hits.fractions[i] < fGpffff82b4)
            {
                delta.x = endpoint[0] - hits.points[i].x;
                delta.y = endpoint[1] - hits.points[i].y;
                delta.z = endpoint[2] - hits.points[i].z;
                func_003e40b0(&delta.x, &delta.x);
                scale = endpoint[3] - hits.fractions[i];
                products[0] = delta.x * scale;
                products[1] = delta.y * scale;
                products[2] = delta.z * scale;
                dot = vector[2] * delta.z + vector[0] * delta.x +
                      vector[1] * delta.y;
                if (dot < 0.0f)
                {
                    products[0] = delta.x * dot;
                    products[1] = delta.y * dot;
                    products[2] = delta.z * dot;
                    vector[0] -= products[0];
                    vector[1] -= products[1];
                    vector[2] -= products[2];
                    result = 1;
                }
                if (vector[0] == 0.0f && vector[1] == 0.0f &&
                    vector[2] == 0.0f)
                {
                    vector[0] += products[0];
                    vector[1] += products[1];
                    vector[2] += products[2];
                    result = 1;
                }
            }
        }
    }
    return result;
}

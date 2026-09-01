/* SKIPPED candidate for func_00169780 (src/Kosaka/Field/k_fldFrame.c).
 * object 664B / window 688B, normalized_diff 340. Residual saved-register
 * allocation / loop mapping mismatch. Not closed this session. */
s32 func_00169780(s32 collisionWorld, f32* origin,
                  f32* vector, f32 fraction)
{
    typedef struct FldFrameScratch69780
    {
        u8 pad[0x40];
        f32 endpoint[4];
        f32 intersection[8];
        f32 delta[3];
    } FldFrameScratch69780;
    FldFrameScratch69780 scratch __attribute__((aligned(16)));
    f32 productX;
    f32 productY;
    f32 productZ;
    f32 scale;
    f32 dot;
    s32 hits[705] __attribute__((aligned(16)));
    s32 result;

    result = 0;
    scratch.endpoint[0] = origin[0] + vector[0];
    scratch.endpoint[1] = origin[1] + vector[1];
    scratch.endpoint[2] = origin[2] + vector[2];
    scratch.endpoint[3] = fraction;
    ((s32*)scratch.intersection)[6] = 3;
    *(u_long128*)scratch.intersection =
        *(u_long128*)scratch.endpoint;
    {
        s32 i;
        for (i = 0; i < 64; i++)
    {
        u8* p;
        p = (u8*)hits + i * 0xc;
        func_0043f9c8(p, 0, 0xc);
        func_0043f9c8(p + 0x300, 0, 0xc);
        *(f32*)((u8*)hits + 0x600 + i * 4) = fGpffff82b4;
    }
    }
    *(s32*)((u8*)hits + 0xb04) = 0;
    if (collisionWorld != 0)
    {
        func_00394d70((s32)collisionWorld, (s32)scratch.intersection,
                      func_00169320, (s32)hits);
        {
            s32 j;
            for (j = 0; j < *(s32*)((u8*)hits + 0xb04); j++)
        {
            u8* p;
            p = (u8*)hits + j * 0xc;
            if (*(f32*)((u8*)hits + 0x600 + j * 4) < fGpffff82b4)
            {
                scratch.delta[0] = scratch.intersection[0] - *(f32*)p;
                scratch.delta[1] = scratch.intersection[1] -
                                   *(f32*)(p + 4);
                scratch.delta[2] = scratch.intersection[2] -
                                   *(f32*)(p + 8);
                func_003e40b0(&scratch.delta[0], &scratch.delta[0]);
                scale = scratch.intersection[3] -
                        *(f32*)((u8*)hits + 0x600 + j * 4);
                productX = scratch.delta[0] * scale;
                productY = scratch.delta[1] * scale;
                productZ = scratch.delta[2] * scale;
                dot = vector[2] * scratch.delta[2] +
                      vector[0] * scratch.delta[0] +
                      vector[1] * scratch.delta[1];
                if (dot < 0.0f)
                {
                    productX = scratch.delta[0] * dot;
                    productY = scratch.delta[1] * dot;
                    productZ = scratch.delta[2] * dot;
                    vector[0] -= productX;
                    vector[1] -= productY;
                    vector[2] -= productZ;
                    result = 1;
                }
                if (vector[0] == 0.0f && vector[1] == 0.0f &&
                    vector[2] == 0.0f)
                {
                    vector[0] += productX;
                    vector[1] += productY;
                    vector[2] += productZ;
                    result = 1;
                }
            }
        }
        }
    }
    return result;
}

/* Refreshed func_0045e8e0 compiler probe; retail remains assembly-backed.
 * 560B/576B; 100 fully relocated differing overlap words; all 14 relocations resolve.
 * Missing tail: four executable zero bytes, then 12 bytes of zero alignment.
 * The ordinary C product-seeded mula/madd/add chains are reproduced. This is
 * a register/allocation/scheduling residual, not a proven FPU-accumulator wall.
 * No improvement over the historical nd88 score is claimed.
 * Corrected iGpffff81d0 angle conversion, cached across both trig calls;
 * center X is s32, center Y s16. Reuses the owner's actual PrimBatch layout.
 * All five existing owner C functions (3,056 bytes) preserve bytes/relocations.
 * Compiler experiment only: no native geometry/rendering verification claimed.
 * Requires a positive count, valid color/point arrays, successful allocation,
 * representable allocation arithmetic and finite transform inputs/results.
 */
void func_0045e8e0(void *arg0, void *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, f32 fparg1, f32 fparg2, f32 fparg3, void *arg7) {
    s32 size8;
    s32 size4;
    PrimBatch *work;
    u8 *callback;
    f32 angle;
    f32 sine;
    f32 cosine;
    PrimFloat2 base;
    f32 centerX;
    f32 centerY;
    f32 x;
    f32 y;
    f32 negSine;
    PrimFloat2 *position;
    s32 i;

    func_0044ea90(D_007124C0, 0x328);
    size8 = arg2 * 8;
    size4 = arg2 * 4;
    work = (void *)D_008873F4[0](1, size4 + 0x1C + size8, 0x40000);
    work->colors = (u8 *)(work + 1);
    work->positions = work->colors + size4;
    work->scale = fparg0;
    work->count = arg2;
    work->enabled = arg4;
    work->primType = arg3;
    func_0043f810(work->positions, (void *)arg1, size8);
    func_0043f810(work->colors, (void *)arg0, size4);
    angle = iGpffff81d0 * fparg1;
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);
    base = *(PrimFloat2 *)work->positions;
    centerX = base.v[0] + (f32)arg5;
    centerY = base.v[1] + (f32)arg6;
    negSine = -sine;
    for (i = 0; i < arg2; i++) {
        position = (PrimFloat2 *)((u8 *)work->positions + i * 8);
        x = (position->v[0] - centerX) * fparg2;
        y = (position->v[1] - centerY) * fparg3;
        position->v[0] = base.v[0] + (f32)arg5 + (x * cosine + y * sine);
        ((PrimFloat2 *)work->positions)[i].v[1] = base.v[1] + (f32)arg6 + (x * negSine + y * cosine);
    }
    callback = func_00460990();
    *(void **)(callback + 8) = (void *)func_0045e310;
    *(void **)(callback + 0x10) = work;
    func_00460ac0(arg7, callback);
}

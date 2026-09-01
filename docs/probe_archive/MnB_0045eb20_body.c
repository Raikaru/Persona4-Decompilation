/*
 * func_0045eb20 best plain-C candidate (not closed).
 * object_size=568B; retail_window=576B; normalized_diff=240 (scope byte score).
 * fndiff differing_words=89; offsets below are instruction/word byte offsets.
 * differing_word_offsets=0x3c,0x40,0x44,0x5c,0x80,0x84,0x88,0x8c,0xa8,0xac,0xb0,0xb4,0xb8,0xbc,0xc0,0xc4,0xc8,0xcc,0xd0,0xd4,0xdc,0xe0,0xe4,0xe8,0xf0,0xf4,0xf8,0xfc,0x104,0x108,0x10c,0x110,0x114,0x11c,0x120,0x124,0x128,0x12c,0x130,0x164,0x168,0x16c,0x174,0x178,0x17c,0x180,0x184,0x188,0x18c,0x190,0x194,0x198,0x19c,0x1a0,0x1a4,0x1a8,0x1ac,0x1b0,0x1b4,0x1b8,0x1bc,0x1c0,0x1c4,0x1c8,0x1cc,0x1d0,0x1d4,0x1d8,0x1dc,0x1e0,0x1e4,0x1e8,0x1ec,0x1f0,0x1f4,0x1f8,0x1fc,0x200,0x204,0x208,0x20c,0x210,0x214,0x218,0x21c,0x220,0x224,0x228,0x22c,0x230,0x234.
 * Four retail COP1 accumulator operations (mula.s/madd.s in both sums) reproduced.
 * Ordinary residual: saved-register coloring (work/size8/size4 cycle), setup
 * address/load order, and resulting short object. No COP1 floor.
 * Ruled out: inline asm, intrinsics, volatile, whole-function asm, text permuter;
 * scalar/aggregate position spellings; MAC operand swaps/parenthesization;
 * split versus combined products; pointer reload/store forms; local declaration
 * permutations; permitted opt_propagation and opt_common_subs pragmas; pointer
 * aliases; signed/unsigned integer and pointer ABI-width substitutions; integer
 * versus pointer work representation; allocator return-type cast.
 * Existing sibling func_0045e8e0 archive was nd91/object560; this target's
 * residual was broader at this best initial body and did not show a shared COP1 wall.
 */
void func_0045eb20(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, f32 fparg1, f32 fparg2, f32 fparg3, void *arg7) {
    s32 size8;
    s32 size4;
    struct {
        u8 *colors;
        u8 *positions;
        f32 scale;
        s32 count;
        s32 field10;
        u8 alpha;
        u8 pad[3];
        s32 primType;
    } *work;
    u8 *callback;
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
    work->field10 = arg4;
    work->primType = arg3;
    func_0043f810(work->positions, (void *)arg1, size8);
    func_0043f810(work->colors, (void *)arg0, size4);
    sine = func_0044b7b0(D_008872F8[0] * fparg1);
    cosine = func_0044b610(D_008872F8[0] * fparg1);
    base = *(PrimFloat2 *)work->positions;
    centerX = base.v[0] + (f32)arg5;
    centerY = base.v[1] + (f32)arg6;
    negSine = -sine;
    for (i = 0; i < arg2; i++) {
        position = (PrimFloat2 *)(work->positions + i * 8);
        x = (position->v[0] - centerX) * fparg2;
        y = (position->v[1] - centerY) * fparg3;
        position->v[0] = base.v[0] + (f32)arg5 + (x * cosine + y * sine);
        position->v[1] = base.v[1] + (f32)arg6 + (x * negSine + y * cosine);
    }
    work->alpha = 1;
    callback = func_00460990();
    *(void **)(callback + 8) = (void *)func_0045e310;
    *(void **)(callback + 0x10) = work;
    func_00460ac0(arg7, callback);
}

/* object_size=664B; retail_window=672B; normalized_diff=50 words.
   differing_offsets=0x0B8,0x0F0,0x0F4,0x0F8,0x0FC,0x100,0x104,0x108,
   0x10C,0x110,0x114,0x124,0x134,0x138,0x13C,0x140,0x144,0x148,
   0x14C,0x164,0x168,0x16C,0x180,0x184,0x188,0x190,0x1A4,0x1A8,
   0x1AC,0x1C0,0x1C4,0x1C8,0x1D0,0x1D4,0x1D8,0x1E0,0x1F4,0x1F8,
   0x1FC,0x210,0x214,0x218,0x220,0x234,0x238,0x23C,0x240,0x244,
   0x248. The complete mula.s/madd.s accumulator chain reproduced from
   ordinary C (all four accumulator operations); the remaining residual is
   loop GPR coloring plus the short 8-byte object tail.

   Ruled out: direct indexed position expressions versus a position local;
   scalar output pointer versus aggregate output fields; typed pointer
   parameters; integer output-pointer parameter; explicit output-base alias;
   offset local; loop-counter signedness, declaration order, and for/while
   spelling; source field/index spelling; inline asm, intrinsics, volatile,
   whole-function asm, text permutation, pointer reloads, helper aliases, and
   FP accumulator operand swaps. No new data reference was introduced.
*/
void func_0045dd30(u8 *arg0, s32 arg1, s32 arg2, f32 f0, u32 arg3, s32 arg4, s32 arg5, f32 f1, f32 f2, f32 f3) {
    s32 i;
    f32 inv;
    f32 angle;
    f32 sine;
    f32 cosine;
    PrimFloat2 base;
    f32 centerX;
    f32 centerY;
    f32 x;
    f32 y;
    f32 negSine;
    f32 colorValue;
    f32 *out;
    u8 *color;
    s32 value;
    u32 bits;
    s32 offset;

    inv = 1.0f / *(f32 *)(func_00457120() + 0x80);
    f0 = D_008872F8[0] - f0;
    angle = iGpffff81d0 * f1;
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);
    base = *(PrimFloat2 *)arg2;
    i = 0;
    centerX = base.v[0] + (f32)arg4;
    centerY = base.v[1] + (f32)arg5;
    negSine = -sine;
    while (i < arg3) {
        offset = i * 8;
        x = (*(f32 *)((u8 *)arg2 + offset) - centerX) * f2;
        y = (*(f32 *)((u8 *)arg2 + offset + 4) - centerY) * f3;
        offset = i * 0x40;
        out = (f32 *)(arg0 + offset);
        *out = centerX + (x * cosine + y * sine);
        *(out + 1) = centerY + (x * negSine + y * cosine);
        *(out + 2) = f0;
        offset = i * 4;
        color = (u8 *)arg1 + offset;
        value = color[0];
        if (value >= 0) {
            colorValue = (f32)value;
        } else {
            bits = (u32)value;
            bits = (bits >> 1) | (bits & 1);
            colorValue = (f32)(s32)bits;
            colorValue += colorValue;
        }
        *(out + 8) = colorValue;
        value = color[1];
        if (value >= 0) {
            colorValue = (f32)value;
        } else {
            bits = (u32)value;
            bits = (bits >> 1) | (bits & 1);
            colorValue = (f32)(s32)bits;
            colorValue += colorValue;
        }
        *(out + 9) = colorValue;
        value = color[2];
        if (value >= 0) {
            colorValue = (f32)value;
        } else {
            bits = (u32)value;
            bits = (bits >> 1) | (bits & 1);
            colorValue = (f32)(s32)bits;
            colorValue += colorValue;
        }
        *(out + 10) = colorValue;
        value = color[3];
        if (value >= 0) {
            colorValue = (f32)value;
        } else {
            bits = (u32)value;
            bits = (bits >> 1) | (bits & 1);
            colorValue = (f32)(s32)bits;
            colorValue += colorValue;
        }
        *(out + 11) = colorValue;
        *(out + 6) = inv;
        i = i + 1;
    }
}

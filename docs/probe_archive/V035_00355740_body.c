/* object_size=352B; window=352B; normalized_diff=146; differing_offsets=0x48,0x94,0x9D,0xA2-0xAE (first_diffs from verify). */
/* Ordinary loop/switch reconstruction. Retail's first loop and case-0 block
   match exactly with distinct loop/pointer locals and ascending switch labels.
   The case-1 preheader and register staging remain different (49 differing
   words in fndiff); no COP1 accumulator chain or standalone MMI floor is
   present. An initial shared-loop/if-else body was 344B/352B with nd 77;
   the structured switch body below reached the exact 352-byte size but nd
   146 after adding named divisor/float preheader locals. */
void func_00355740(u8 *arg0, s64 arg1)
{
    f32 scale;
    f32 step;
    f32 three_quarters;
    s32 x;
    s32 y;
    s32 i;
    s32 i2;
    s32 j;
    s32 divisor;
    u8 *p;
    u8 *q;
    u8 *r;
    extern f32 fGpffff83d0;

    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(f32 *)(p + 0x28) = *(f32 *)(p + 0x20);
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x24);
        i += 1;
    }
    switch (arg1) {
    case 0:
        i2 = 0;
        while (i2 < 0xF) {
            q = arg0 + (i2 << 5);
            *(s32 *)(q + 0x18) = 0;
            *(s32 *)(q + 0x1C) = 0;
            *(s32 *)(q + 0x30) = 0;
            *(f32 *)(q + 0x34) = (f32)*(s16 *)(arg0 + 0xC);
            i2 += 1;
        }
        break;
    case 1:
        j = 0;
        divisor = 5;
        step = fGpffff83d0;
        three_quarters = 0.75f;
        while (j < 0xF) {
            x = (j % divisor) - 2;
            if (x < 0) {
                x = -x;
            }
            y = (j / divisor) - 1;
            if (y < 0) {
                y = -y;
            }
            scale = step * (f32)(x + y);
            r = arg0 + (j << 5);
            *(s32 *)(r + 0x18) = 0;
            *(s32 *)(r + 0x1C) = 0;
            *(f32 *)(r + 0x30) = (f32)*(s16 *)(arg0 + 0xC) * scale;
            *(f32 *)(r + 0x34) = (f32)*(s16 *)(arg0 + 0xC) * (three_quarters + scale);
            j += 1;
        }
        break;
    default:
        break;
    }
}

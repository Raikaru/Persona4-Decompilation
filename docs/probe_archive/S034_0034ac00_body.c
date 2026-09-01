/* daddiu probe (measured on this compiler, applies to offset 248):
   constant materialisation NEVER emits daddiu -- return 1, return 1LL,
   (long long)1, an s64 return type, a 64-bit local and a 64-bit store all
   emit plain addiu (24020001). The only spelling that produced daddiu was
   a 64-bit ADD WITH A REGISTER OPERAND: `long long x; return x + 1;` ->
   64820001. So offset 248 is an addition in 64-bit context, not a constant
   load; do not chase it with literal suffixes or return-type widening. */
/* object=320 window=320 normalized_diff=5 differing_offsets=[120,124,248,260,264] instruction_deficit=0 surplus=0 classification=loop-counter register/width plus float global-load order residual; fixed_words=48/52 via entry = base + ((s32)(s64)(s16)counter << 9), fixed_words=252/256 via s16 bumped split (bumped = counter + 1; counter = (s64)(s16)bumped); remaining=120/124 GP-vs-field float load order, 248 daddiu-vs-addiu, 260/264 bottom-counter destination/source; opt_propagation_off=no_effect; prologue_saved_s=4 ($s3,$s2,$s1,$s0); params=(u8*); declarations=callee prototypes block-scope, globals file-scope arrays */
// FUN_0034AC00
s32 func_0034ac00(u8 *arg0)
{
    extern f32 fGpffff8504;
    extern void func_0034a8b0(void *arg0);
    s64 counter;
    s16 bumped;
    u8 *entry;
    u8 *base;
    u8 *sub;
    u8 *entry2;
    s16 index;
    s32 offset;
    u8 *packet;

    base = *(u8 **)(arg0 + 0x38);
    func_00457120();
    counter = 0;
    while (((counter << 48) >> 48) < *(u8 *)(base + 0x1800)) {
        entry = base + ((s32)(s64)(s16)counter << 9);
        sub = entry + 0x104;
        func_0043f810(sub, func_002b89a0(sub), 0xF0);
        if (((*(s16 *)(entry + 0x104) & 1) == 1) &&
            (!(*(f32 *)(entry + 0x194) <= fGpffff8504)) &&
            (*(f32 *)(entry + 0x1A0) > fGpffff8504) &&
            (*(u8 *)(entry + 0x162) > 0)) {
            entry2 = base + ((s32)(s16)counter << 9);
            index = *(s16 *)(entry2 + 0x100);
            offset = index << 1;
            offset += index;
            offset <<= 4;
            packet = func_00461390(D_00793E80 + offset, 4, entry2, 4);
            *(void **)(packet + 8) = (void *)func_0034a8b0;
            *(u8 **)(packet + 0x10) = entry2;
        }
        bumped = counter + 1;
        counter = (s64)(s16)bumped;
    }
    return 0;
}

/* Re-opened daddiu-family probe, measured against MWCCPS2 b210:
   the archived s64 counter produced daddiu at +248 while retail uses
   addiu. Retyping the state as s32, while retaining explicit signed-16
   casts at the loop test and array-index expression, reproduces retail's
   addiu increment and both dsll32/dsra32 width pairs. */
/* BEST ATTEMPT: object=320 window=320 normalized_diff=2 differing_offsets=[120,124] instruction_deficit=0 surplus=0; fixed_words=248/252/256/260/264 by s32 counter plus `(s64)(s16)counter` loop test and `((s32)(s64)(s16)(s64)counter << 9)` entry expression. Remaining two words are the documented MWCC RHS-load-first float compare floor: candidate loads GPREL fGpffff8504 before entry+0x194, while retail loads entry+0x194 first; c.ole.s/bc1t and all other words match. Narrow-unsigned rule does not apply: u16 counter was object=324/nd74, u16 bumped object=324/nd22 and inserted 0xffff masks; s16 counter object=316/nd20; u32 counter object=328/nd68. Other ruled out probes: `(s16)counter + 1` object=324/nd23; `(s32)counter + 1` object=328/nd23; removing the outer entry cast object=320/nd5 (extra top dsll/dsra words); `(s64)counter << 48` loop test object=328/nd19 (extra width pair). The float forms `!(fGpffff8504 >= member)` changed c.ole.s/bc1t to c.olt.s/bc1f (nd7). opt_propagation off had no effect in the archived sweep. */
// FUN_0034AC00
s32 func_0034ac00(u8 *arg0)
{
    extern void func_0034a8b0(void *arg0);
    s32 counter;
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
    while ((s64)(s16)counter < *(u8 *)(base + 0x1800)) {
        entry = base + ((s32)(s64)(s16)(s64)counter << 9);
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

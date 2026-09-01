/* object 228B/window 256B, normalized_diff 97, differing offsets 0x020-0x0A0 plus 0x0AC-0x0F0 (48 differing words; object not oversized); classification: MWCC near-miss, schedule-on best measured shape but branch/load-store ordering remains wrong. Retail prologue: addiu $sp,-48; sd $ra,32($sp); sq $s1,16($sp); sq $s0,0($sp). Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; helper call was tested old-style at block scope, typed float temporaries and union aliasing were tested, schedule-on improved nd 139 to 97, optimization_level 1 regressed to object 260B/nd174, and no_branch_likely worsened the schedule probe. */
// FUN_00414930
s32 func_00414930(u32 *arg0, u32 *arg1, u8 **arg2)
{
    extern s32 *func_00414820();
    typedef union {
        u32 word;
        f32 f;
    } Word;
    s32 *slot;
    u8 *base;
    u8 *end;
    u8 *dest;
    u8 *combined;
    Word *words;
    Word *dest_words;
    s32 diff;
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;

    slot = func_00414820(arg2);
    if (slot != NULL) {
        base = (u8 *)*arg0;
        end = base + arg0[1];
        words = (Word *)base;
        words[0].word = 0;
        words[1].word = 0;
        words[2].word = 0;
        words[3].word = 0;
        dest = end - 32;
        dest_words = (Word *)dest;
        f3 = words[0].f;
        f2 = words[1].f;
        f1 = words[2].f;
        f0 = words[3].f;
        dest_words[0].f = f3;
        dest_words[1].f = f2;
        dest_words[2].f = f1;
        dest_words[3].f = f0;
        f3 = words[4].f;
        f2 = words[5].f;
        f1 = words[6].f;
        f0 = words[7].f;
        dest_words[4].f = f3;
        dest_words[5].f = f2;
        dest_words[6].f = f1;
        dest_words[7].f = f0;
        *(u8 **)(base + 4) = base + 32;
        *(u8 **)(base + 32) = base;
        *(u8 **)(base + 36) = dest;
        *(u8 **)(dest + 0) = base + 32;
        diff = (s32)((u32)dest - (u32)(base + 64));
        *(s32 *)(base + 40) = diff;
        *(s32 **)(base + 44) = slot;
        *(u8 **)((u8 *)slot + 4) = base + 32;
        if (arg1 != NULL) {
            combined = (u8 *)(arg1[0] + arg1[1]);
            *(u8 **)(combined - 28) = base;
            *(u8 **)(base + 0) = combined - 32;
        }
        return 1;
    }
    return 0;
}

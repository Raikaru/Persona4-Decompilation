// measured: object_size 152, window 160, normalized_diff 100, differing offsets 0x1,0x4-0x5,0x7-0xC,0xE-0xF,0x14-0x18; ruled out s16/s32/s64 widths, while/for/goto/trampoline loop shapes, scoped inner locals, struct fields, named outer offsets, hoisted/numeric global bases, propagation/scheduling pragmas, and integer/pointer address spellings.
void func_00103a60(void) {
    s16 outer;
    u8 *temp_5;
    outer = 0;
loop_5:
    if (outer < 2) {
        s16 inner;
        temp_5 = D_00796700 + outer * 0x370;
        *(s16 *)(temp_5 + 0) = 0;
        *(s32 *)(temp_5 + 0x50) = 0;
        inner = 0;
loop_3:
        if (inner < 2) {
            *(s32 *)(temp_5 + inner * 4 + 0x14) = 0;
            inner += 1;
            goto loop_3;
        }
        outer += 1;
        goto loop_5;
    }
}

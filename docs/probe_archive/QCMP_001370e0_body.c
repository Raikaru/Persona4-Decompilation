/* object_size=200 window=192 normalized_diff=137 differing_offsets=[24,25,26,27,28,29,30,31,32,34,35,36,37,38,39,42]; classification=OBJECT_LARGER_THAN_WINDOW; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; callee func_003b7060 already declared u32 and D_005EB590 already declared s16[]; auto-archived before reordering because candidate exceeds retail window. */

void func_001370e0(u8* arg0) {
    s16 values[25];
    s32 i;
    u8* p;

    for (i = 0; i < 25; i++) {
        values[i] = D_005EB590[i];
    }
    for (i = 0; i < 25; i++) {
        p = arg0 + values[i] * 20;
        *(s16*)(p + 2500) = 3;
        *(s16*)(p + 2502) = func_003b7060() % 25 + 15;
    }
}

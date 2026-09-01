/* object 216B/window 224B, normalized_diff 35; differing byte offsets 16-27, 84-90, 136-147, 204-211; classification near-miss. Retail logic and frame matched, but prologue saved-register/move order, signed-positive guard materialization (retail slt+beqz vs candidate blez), loop back-edge load/increment order, and jr delay-slot epilogue scheduling remained different. Corrected local declaration func_003bbea0(u8 *) and used existing function-pointer table declaration. Ruled out local-base/declaration-order variants, explicit boolean/goto guard forms, schedule on, schedule+no_branch_likely, optimization_level 1, and opt_propagation off; no movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
void func_003bbea0(u8 *arg0) {
    u8 *base;
    s32 index;
    u8 *entry;
    s32 count;
    s32 positive;

    base = arg0;
    if (*(u8 **)base != NULL) {
        jtbl_008873EC[0](*(u8 **)base);
        *(u8 **)base = NULL;
    }
    if (*(s32 *)(base + 4) == 3) {
        count = *(s32 *)(base + 8);
        entry = *(u8 **)(base + 0xC);
        positive = 0 < count;
        if (positive == 0) {
            goto inner_done;
        } else {
            void (**callbacks)(u8 *);
            index = 0;
            callbacks = jtbl_008873EC;
            do {
                if (*(u8 **)entry != NULL) {
                    (*callbacks)(*(u8 **)entry);
                }
                count = *(s32 *)(base + 8);
                index += 1;
                entry += 4;
            } while (index < count);
        }
inner_done:
        ;
    }
    if (*(u8 **)(base + 0xC) != NULL) {
        jtbl_008873EC[0](*(u8 **)(base + 0xC));
        *(u8 **)(base + 0xC) = NULL;
    }
}

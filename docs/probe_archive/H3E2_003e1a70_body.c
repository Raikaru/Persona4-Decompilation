/* object 108B, window 112B, normalized_diff 48, differing word offsets 28,29,30,31,32,33,34,35,36,37,38,39,48,50,51,52; ruled out direct GP-slot address forms, declaration-order swaps, test-first/goto loop shapes, result locals, and schedule/optimization probes. */
// FUN_003E1A70 NONMATCHING
s32 func_003e1a70(void) {
    s32 result;
    u8 *head;
    u8 *sentinel;
    s32 temp;

    head = iGpffffb778;
    sentinel = (u8 *)&iGpffffb778;
    result = 0;
    if (head != sentinel) {
        do {
            if ((temp = func_003e1740(head - 0x1C)) > 0) {
                result += temp;
            }
            head = *(u8 **)head;
        } while (head != sentinel);
    }
    return result;
}

/* object=336 window=336 normalized_diff=28 differing_offsets=[16,48,60,64,72,76,80,92,96,116,120,124,132,136,140,144,156,164,168,184,216,232,264,280,308] instruction_deficit=0 surplus=0 classification=register-colouring (retail keeps pointer in $s1 and value/reused remainder in $s0; candidate swaps saved registers and temporary destinations); ruled_out=floors movz/movn,COP1 accumulator,standalone MMI,framed tail-jump,sd-vs-sq; prologue_saved_s=2 ($s1,$s0); params=(u8*); declarations=func_003b7060 block-scope prototype; body transcription exact-size */
// FUN_0034F5D0
void func_0034f5d0(u8 *arg0)
{
    extern u32 func_003b7060(void);
    typedef struct {
        s32 value;
        u8 *ptr;
    } State;
    State state;
    s32 half;
    u32 random;
    u32 remainder;
    s32 delta;
    *(s16 *)(arg0 + 2) -= 1;
    if (*(s16 *)(arg0 + 2) > 0)
        return;

    state.value = *(s32 *)(arg0 + 0xC);
    random = func_003b7060();
    half = state.value >> 1;
    if (state.value < 0)
        half = (state.value + 1) >> 1;
    half += 1;
    remainder = random % (u32)half;
    delta = state.value - *(s32 *)(arg0 + 4) - remainder;
    if (delta < 0)
        delta = 0;
    state.ptr = arg0;

    state.value = *(s32 *)(state.ptr + 8);
    half = state.value >> 1;
    if (state.value < 0)
        half = (state.value + 1) >> 1;
    if (half >= delta) {
        state.value = 0x14 - (half << 1) - delta;
        if (state.value > 0) {
            random = func_003b7060();
            remainder = random % (u32)state.value;
            if (remainder < 9U) {
                random = 3;
                remainder %= random;
                *(s16 *)(state.ptr + 0) = remainder;
            } else {
                *(s16 *)(state.ptr + 0) = -1;
            }
        } else {
            random = func_003b7060();
            remainder = random % 3U;
            *(s16 *)(state.ptr + 0) = remainder;
        }
    } else {
        *(s16 *)(state.ptr + 0) = -1;
    }
    random = func_003b7060();
    remainder = random % 5U;
    remainder += 2;
    *(s16 *)(state.ptr + 2) = remainder;
}

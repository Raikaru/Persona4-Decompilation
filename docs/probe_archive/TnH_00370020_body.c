/*
 * Target: func_00370020
 * Best candidate before revert: object 608B, retail window 624B.
 * normalized_diff: 89 words (reloc-masked).
 * differing offsets (bytes): 24, 28, 36, 116, 128, 140, 152, 164,
 * 232, 236, 264, 268, 292, 296, 300, 304, 308, 316, 320, 324, 328,
 * 332, 336, 340, 344, 348, 352, 356, 360, 364, 368, 372, 376, 380,
 * 384, 388, 392, 396, 400, 408, 412, 416, 420, 428, 432, 436, 440,
 * 444, 448, 452, 464, 468, 472, 476, 480, 484, 488, 492, 496, 500,
 * 504, 508, 512, 516, 520, 524, 528, 532, 536, 540, 544, 548, 556,
 * 560, 564, 568, 572, 576, 580, 584, 588, 592, 596, 600, 604.
 *
 * Ruled out: signed/unsigned merged low-argument amount declarations;
 * separate low flag locals (including scoped and preinitialized variants);
 * direct low-mask expression without a key local; u16 low temporary;
 * declaration-order permutations; explicit high-key mask expression variants;
 * output-pointer temporary; signed/unsigned flag casts; count/result inlining.
 */

// FUN_00370020
s32 func_00370020(s32 arg0, u8 *arg1)
{
    u16 key;
    s16 amount;
    u16 mode;
    u16 count;
    u8 result;
    u8 *persona;

    key = (arg0 & 0xFFFF0000) >> 16;
    switch (key) {
    case 8:
        mode = 3;
        break;
    case 9:
        mode = 0;
        break;
    case 11:
        mode = 4;
        break;
    case 12:
        mode = 1;
        break;
    case 13:
        mode = 2;
        break;
    default:
        func_0046d730(D_0064E790, 0x5D6);
        break;
    }

    count = (u16)func_0010b6f0();
    persona = func_0010ace0((s16)func_00231d70(count));
    if (persona == NULL) {
        func_0046d730(D_0064E790, 0x5DC);
    }

    if ((arg0 & 0xFFFF) != 0) {
        amount = func_00231d70(3) + 1;
        result = func_001099f0(persona, mode);
        if (result >= 0x63) {
            return 0;
        }
        if (result + amount >= 100) {
            amount = 99 - result;
        }
        func_0010a780(persona, mode, (s8)amount);
    } else {
        amount = func_00231d70(1) + 1;
        result = func_00109920(persona, mode);
        if (result < 2) {
            return 0;
        }
        if (amount >= result) {
            amount = result - 1;
        }
        func_0010a780(persona, mode, (s8)-amount);
    }

    *(u16 *)(arg1 + 4) = *(u16 *)(persona + 2);
    *(s16 *)(arg1 + 8) = amount;
    return 1;
}

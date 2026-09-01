/* object 224B / window 224B / normalized_diff 89 / differing offsets 0,12,24,36,48,60,72,75,80,82,83,84,85,87,90,91 / classification exact-size near-miss; callee/global declarations unchanged; ruled out: movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor; tested switch body (256B/85), retail-order goto chain (248B/116), compact returns (256B/146), positive-guard direct returns (244B/123), schedule on (192B/90), named result pointer (228B/101), positive-guard switch (252B/121). */
// FUN_003D39A0
u8 *func_003d39a0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_3;

    if (arg0 != NULL) {
        temp_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3 != NULL) {
            if (arg1 == 5) goto block_5;
            if (arg1 == 4) goto block_4;
            if (arg1 == 3) goto block_3;
            if (arg1 == 2) goto block_2;
            if (arg1 == 1) goto block_1;
        }
    }
    goto block_null;
block_1:
    *(s32 *)(temp_3 + 0) = arg2;
    goto block_return;
block_2:
    if (arg2 == 0) goto block_null_2;
    *(s32 *)(temp_3 + 4) = arg2;
    goto block_return;
block_3:
    if (arg2 == 0) goto block_null_3;
    *(s32 *)(temp_3 + 8) = arg2;
    goto block_return;
block_4:
    if (arg2 == 0) goto block_null_4;
    *(s32 *)(temp_3 + 0xC) = arg2;
    goto block_return;
block_5:
    *(s32 *)(temp_3 + 0x10) = arg2;
    goto block_return;
block_null:
    return NULL;
block_null_2:
    return NULL;
block_null_3:
    return NULL;
block_null_4:
    return NULL;
block_return:
    return arg0;
}

/* Lane119e3e 2026-09-03 (b119, schedule on, cw119 unit): normalized_diff 8. Lane died on a provider
   rate limit before finishing; measured but not iterated further. */
// FUN_003E5110
#pragma schedule on
u8 *func_003e5110(u8 *arg0, u8 *arg1, s32 arg2) {
    f32 *dst;
    f32 first;
    f32 second;
    f32 third;
    s32 count;

    dst = (f32 *)arg0;
    first = *(f32 *)arg1;
    count = arg2 - 1;
    second = *(f32 *)(arg1 + 4);
    arg2 = count - 1;
    third = *(f32 *)(arg1 + 8);
    dst[3] = first;
    dst[4] = second;
    dst[5] = third;
    arg1 += 12;
    dst[0] = first;
    dst[1] = second;
    dst[2] = third;
    if (count == 0) {
        goto done;
    }
    goto loop;
loop:
    if (dst[3] > *(f32 *)arg1) {
        goto update3;
    }
compare4:
    if (dst[4] > *(f32 *)(arg1 + 4)) {
        goto update4;
    }
compare5:
    if (dst[5] > *(f32 *)(arg1 + 8)) {
        goto update5;
    }
compare0:
    if (dst[0] < *(f32 *)arg1) {
        goto update0;
    }
compare1:
    if (dst[1] < *(f32 *)(arg1 + 4)) {
        goto update1;
    }
compare2:
    if (dst[2] < *(f32 *)(arg1 + 8)) {
        goto update2;
    }
loop_end:
    arg1 += 12;
    if (arg2-- != 0) {
        goto loop;
    }
done:
    return arg0;
update3:
    *(f32 *)(arg0 + 12) = *(f32 *)arg1;
    goto compare4;
update4:
    *(f32 *)(arg0 + 16) = *(f32 *)(arg1 + 4);
    goto compare5;
update5:
    *(f32 *)(arg0 + 20) = *(f32 *)(arg1 + 8);
    goto compare0;
update0:
    *(f32 *)arg0 = *(f32 *)arg1;
    goto compare1;
update1:
    *(f32 *)(arg0 + 4) = *(f32 *)(arg1 + 4);
    goto compare2;
update2:
    *(f32 *)(arg0 + 8) = *(f32 *)(arg1 + 8);
    goto loop_end;
}
#pragma schedule off

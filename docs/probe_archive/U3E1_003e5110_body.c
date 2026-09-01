/* object 288B/window 272B, normalized_diff 161; 4-instruction surplus; classification control-flow/branch-delay and loop-tail placement; prologue no frame/saved registers, args (u8 *, u8 *, s32); declarations corrected to u8* ABI with f32* destination alias; ruled out schedule on (object 200B), no_branch_likely on, and missing-block/oversized-frame issues. */
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

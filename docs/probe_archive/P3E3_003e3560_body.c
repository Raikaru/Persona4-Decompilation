/* object_size=192B window=208B normalized_diff=64 differing_offsets=[64,72,104,107,112,114,115,117,119,124,125,126,127,128,129,130] classification=compiler branch-layout/epilogue near-miss; fndiff differing_words=26; schedule on + no_branch_likely on retained; ruled out plain nested-if, explicit goto, do-while, switch call-result, failure-dispatch labels, and optimization_level 1 (object 216B > 208B). */
s32 func_003e3560(s32 arg0, s32 arg1) {
    extern s32 func_003df050(s32, s32, s32 *, s32);
    extern s32 func_003deea0(s32, s32, s32 *, s32, s32);
    extern s32 func_003e2ce0(s32, s32);
    s32 remaining;
    s32 size;
    s32 diff;

    if (func_003df050(arg1, 3, &remaining, 0) == 0)
        goto fail_initial;
    if (remaining != 0)
        goto loop;
    goto success;
success:
    return arg0;
fail_initial:
    return 0;
loop:
    do {
        switch (func_003deea0(arg1, 0, &size, 0, 0)) {
        case 0:
            goto fail_dispatch;
        default:
            goto have_size;
        }
fail_dispatch:
        goto fail_loop;
have_size:
        if (func_003e2ce0(arg1, size) == 0)
            goto fail_loop;
        diff = remaining - (size + 0xC);
        remaining = diff;
    } while (diff != 0);
    goto success;
fail_loop:
    return 0;
}

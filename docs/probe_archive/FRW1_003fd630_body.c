/* object 88B / window 96B / normalized_diff 16 / differing offsets 24,32,52,54,55,56,58,59,64,66,67,68,69,72,74,75; ruled out named result local and plain-C branch/goto layout. Retail's valid-path store and common-return delay-slot layout remain different. */
s32 func_003fd630(s32 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = arg1 + iGpffffb938;
    if (*(s32 *)(arg1 + 4) == 0) {
        goto zero;
    }
    if ((arg1[0x23] & 0x80) == 0) {
        goto one;
    }
    if (temp_3 == NULL) {
        goto one;
    }
    *arg0 = ((s32)*(u8 *)(temp_3 + 0x16) >> 2) + 1;
    goto done;
one:
    *arg0 = 1;
done:
    return 1;
zero:
    return 0;
}

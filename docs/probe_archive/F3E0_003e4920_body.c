/* object_size=68B window=64B normalized_diff=46 differing_offsets=0,1,2,4,5,6,7,8,9,12,13,14,15,20,22,28; ruled out this s64-return/s64-key plain-C loop because its object exceeded the retail window and allocated the found pointer in a2. */
s64 func_003e4920(s8 *arg0, s64 arg1) {
    s8 *found;
    s8 *p;
    s8 c;

    p = arg0;
    found = NULL;
loop:
    c = *p;
    if (c == (s8)arg1) {
        found = p;
    } else {
        p += 1;
        if (c == 0) {
            goto done;
        }
        goto loop;
    }
done:
    return (s64)found;
}

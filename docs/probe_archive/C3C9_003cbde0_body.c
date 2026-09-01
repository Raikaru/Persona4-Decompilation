/* object 144 bytes, window 160 bytes, normalized_diff 86. */
s32 func_003cbde0(u8 *arg0, void (*arg1)(u8 *), u8 *arg2) {
    u8 *obj;
    s32 *p;
    s32 count;

    obj = arg0 + iGpffffb708;
    count = *(s32 *)(obj + 8);
    p = *(s32 **)(obj + 0);
    if (count > 0)
        goto loop;
    goto done;
loop:
    if (((s32 (*)(s32, s32))arg1)(*p, (s32)arg2) != 0)
        goto next;
    goto done;
next:
    count -= 1;
    p += 1;
    if (count != 0)
        goto loop;
done:
    return (s32)arg0;
}

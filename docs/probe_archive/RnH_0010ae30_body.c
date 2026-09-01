/* func_0010ae30 initial structural candidate archive
 * object/window: 204B/480B
 * normalized_diff: 117 words
 * differing offsets (fndiff): 0-12,20-112,120-168,176-476 (4-byte offsets; 117 words)
 * ruled out: none; this candidate was the wrong search-only routine and is not closed.
 */
s32 func_0010ae30(s32 arg0)
{
    s32 i;
    s32 id;
    s32 count;
    s32 found;
    u8 *base;
    count = func_0010b5b0() & 0xFFFF;
    i = 0;
    id = (s16)arg0;
    base = D_007973A0;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        if ((*(u16 *)(base + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) != 0 &&
            *(u16 *)(base + (i & 0xFFFF) * 0x30 + 0xBEE) == id) {
            found = (s16)i;
            goto done;
        }
    }
    found = -1;
done:
    if (found == -1) return 0;
    func_0010b3b0(found);
    return 1;
}

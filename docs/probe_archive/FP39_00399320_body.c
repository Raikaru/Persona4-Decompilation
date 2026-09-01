/* Best plain-C probe: object 32B, retail window 32B, normalized_diff 21.
 * Retail uses lw + movn in the return delay slot; MWCCPS2 b210 emits a
 * conditional branch for the equivalent C expression.
 */
s32 func_00399320(s32 arg0)
{
    s32 result;
    s32 value;

    result = 4;
    value = *(s32 *)(arg0 + iGpffffb5e4);
    if (value == 0) {
        result = 0;
    }
    return result;
}

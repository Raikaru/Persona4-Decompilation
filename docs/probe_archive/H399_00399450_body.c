/* object 36 / window 32 / normalized_diff 29; differing offsets 0x00,0x08,0x0C,0x10,0x14,0x18,0x1C,0x20,0x24; ruled out ternary, local-result, pointer-temp, conditional-rebuild, schedule, and optimization-level probes. */
s32 func_00399450(s32 arg0)
{
    s32 result;
    s32 value;

    result = 4;
    value = *(s32 *)(arg0 + iGpffffb5e8);
    if (value == 0) {
        result = 0;
    }
    return result;
}

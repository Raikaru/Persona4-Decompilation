/* object 132B / window 128B / normalized_diff 27 / differing byte offsets 36,48,50,51,52,54,55,56,58,68,100,108,109,110,111,112; O1 probe; ruled out O2/O3, schedule, no_branch_likely, branch/layout, boolean and pointer variants. Object exceeded window. */
#pragma optimization_level 1
s32 func_00396e80(u8 *arg0)
{
    s32 flag;
    s32 result;
    s32 value;
    u8 *base;

    base = arg0 + iGpffffb5d8;
    flag = (s32)(~*(s32 *)base != 0);
    if (flag == 0) {
        flag = (s32)(*(s32 *)(base + 4) != 0);
    }
    if (flag != 0) {
        arg0 = *(u8 **)(base + 4);
        result = 4;
        if (arg0 != NULL) {
            result = 12;
            if ((*(s32 *)arg0 & 1) == 0) {
                value = *(s32 *)(arg0 + 4);
                arg0 = (u8 *)(result + 8);
                result = value * 3 * 4 + (s32)(u32)arg0;
            }
        } else {
            result = 12;
        }
    } else {
        result = 0;
    }
    return result;
}
#pragma optimization_level 2

/* CURRENT RECHECK: object 80B/window 96B, normalized_diff 35; verify first_diffs bytes 0,2,3,6,7,10,11,14,15,16,17,18,20,21,22,26. The archived nd6 result is stale in the current TU. */
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffb680 = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    *(s32 *)D_00885A90 = value;
    if (count == 0) {
        return;
    }
    factor = 0x10DCD;
    do {
        value *= factor;
        count -= 1;
        *ptr = value;
        ptr += 1;
    } while (count != 0);
}
/*
Ruled out during this recheck: the archived schedule-on setting (it produced
object 72B/normalized_diff 44), the alternate structured store/loop body
(object 72B/normalized_diff 55), and the archived body under the current
translation-unit context (object 80B/normalized_diff 35). No source change
was retained.
*/

/* object 600B/window 512B, normalized_diff 466; first differing byte offsets 0,4,8,10,12,14,16,17,18,19,24,25,26,27,28,30 (object exceeds retail window; archive immediately). Classification: oversized plain-C reconstruction; candidate frame 0x80 vs retail 0x70 and source loop/control-flow/register lifetimes diverge. Corrected free-slot scan, realloc/copy path, entry allocation, and string-copy callbacks. Added block-scope declarations for D_008873D4, D_008873AC, jtbl_008873E8, func_0043f810, func_0043f9c8; no file-scope changes. Ruled out: no conditional-move, COP1 accumulator, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor in retail; no pragma probe performed. Restored fallback after automatic object-over-window condition. */
// FUN_003BC9C0
s32 func_003bc9c0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    extern s32 (*D_008873D4[])(u8 *arg0);
    extern void (*D_008873AC[])(void *arg0, void *arg1);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    s32 count;
    s32 index;
    s32 i;
    s32 size;
    u8 *entries;
    u8 *entry;
    u8 *new_entries;
    u8 *source;
    u8 *destination;

    count = *(s32 *)arg0;
    index = -1;
    if (count > 0) {
        entries = *(u8 **)(arg0 + 4);
        i = 0;
        while (*(s32 *)(entries + 0x0C) != 0) {
            i += 1;
            entries += 0x10;
            if (i >= count) {
                break;
            }
        }
        if (i < count && *(s32 *)(entries + 0x0C) == 0) {
            index = i;
        }
    }
    if (index < 0) {
        entries = *(u8 **)(arg0 + 4);
        if (entries != NULL) {
            new_entries = (u8 *)(*jtbl_008873E8)((u32)((count + 1) * 0x10), 0x3011F);
            if (new_entries == NULL) {
                return -1;
            }
            func_0043f810(new_entries, entries, count * 0x10);
            jtbl_008873EC[0](entries);
            *(u8 **)(arg0 + 4) = new_entries;
        } else {
            new_entries = (u8 *)(*jtbl_008873E8)((u32)((count + 1) * 0x10), 0x3011F);
            *(u8 **)(arg0 + 4) = new_entries;
            if (new_entries == NULL) {
                return -1;
            }
        }
        index = count;
        count += 1;
        *(s32 *)arg0 = count;
    }
    entry = *(u8 **)(arg0 + 4) + index * 0x10;
    size = arg3 * func_003bd110(arg2);
    *(u8 **)(entry + 0x0C) = (u8 *)(*jtbl_008873E8)((u32)size, 0x3011F);
    if (*(u8 **)(entry + 0x0C) == NULL) {
        return -1;
    }
    func_0043f9c8(*(u8 **)(entry + 0x0C), 0, arg3 * func_003bd110(arg2));
    *(u8 **)(entry + 0) = NULL;
    if (arg1 != NULL) {
        source = arg1;
        destination = (u8 *)(*jtbl_008873E8)((u32)((*D_008873D4)(source) + 1), 0x30002);
        *(u8 **)(entry + 0) = destination;
        if (destination != NULL) {
            (*D_008873AC)(destination, source);
        }
    }
    *(s32 *)(entry + 4) = arg2;
    *(s32 *)(entry + 8) = arg3;
    return index;
}

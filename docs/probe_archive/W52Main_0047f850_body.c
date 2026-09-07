/* MATCH: object 412B, retail window 416B. Direct indexed callbacks and
 * scoped opt_loop_invariants on close the former twelve register-allocation
 * differences; only the retail zero-tail word lies beyond the object.
 * The callbacks now share compatible C function types and borrowed void *
 * results. The real target-list prefix preserves the count snapshot and
 * callback-visible item-array loads. Actual source passes 262,160 native32
 * dispatcher mutation cases and 25,920 actual callback consumer cases under
 * Clang undefined/function sanitizers. Old callback definitions trap under
 * the function-type sanitizer. See docs/matching.md, Track dispatch and
 * compatible callback contracts. */
typedef struct Code47Dispatch {
    void *unused;
    void *(*blend)(u8 *left, f32 left_time, u8 *right, f32 right_time,
                   f32 ratio);
    void *(*sample)(u8 *track, f32 time, u8 *defaults, f32 ratio);
    void (*apply)(void *result, void *target);
} Code47Dispatch;

typedef struct Code47Targets {
    void **items;
    u16 count;
} Code47Targets;

extern Code47Dispatch D_00713220[4];

#pragma push
#pragma opt_loop_invariants on
void func_0047f850(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    u32 count;
    Code47Targets *targets;
    u32 kind;

    targets = *(Code47Targets **)(arg0 + 0x50);
    count = targets->count;
    for (kind = 0; kind < 4; kind++) {
        s32 offset;
        u8 *left;
        u8 *right;

        offset = kind * 0x10;
        if (D_00713220[kind].apply == NULL) {
            continue;
        }
        left = arg0 + offset;
        if (*(s32 *)(left + 0xC) == 0) {
            continue;
        }
        right = arg1 + offset;
        if (*(s32 *)(right + 0xC) != 0) {
            void *result;
            u32 target;

            result = D_00713220[kind].blend(left, fparg0, right, fparg1, fparg2);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        } else {
            void *result;
            u32 target;

            result = D_00713220[kind].sample(left, fparg0, arg0 + 0x40, fparg2);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        }
    }
}
#pragma pop

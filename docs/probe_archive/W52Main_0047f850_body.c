/* object 412B, retail window 416B, normalized_diff 13. All control flow,
 * instruction order, frame/save set, indirect calls, and argument placement
 * match. The only residual is a cyclic saved-register allocation:
 * target list/count/dispatch compile as $s2/$s1/$s0 while retail uses
 * $s1/$s0/$s2. Probed typed and raw table/list pointers, function- and
 * block-scoped locals, declaration permutations, paired pointer induction,
 * register storage, opt_lifetimes on/off, and opt_propagation off. */
typedef struct Code47Dispatch {
    void *unused;
    u8 *(*blend)(u8 *left, f32 left_time, u8 *right, f32 right_time,
                 f32 ratio);
    u8 *(*sample)(u8 *track, f32 time, u8 *defaults, f32 ratio);
    void (*apply)(u8 *result, s32 target);
} Code47Dispatch;

extern Code47Dispatch D_00713220[4];

void func_0047f850(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1,
                   f32 fparg2)
{
    u32 count;
    s32 *targets;
    u32 kind;
    Code47Dispatch *dispatch;

    targets = *(s32 **)(arg0 + 0x50);
    count = *(u16 *)(targets + 1);
    for (kind = 0; kind < 4; kind++) {
        s32 offset;
        u8 *left;
        u8 *right;

        offset = kind * 0x10;
        dispatch = &D_00713220[kind];
        if (dispatch->apply == NULL) {
            continue;
        }
        left = arg0 + offset;
        if (*(s32 *)(left + 0xC) == 0) {
            continue;
        }
        right = arg1 + offset;
        if (*(s32 *)(right + 0xC) != 0) {
            u8 *result;
            u32 target;

            result = dispatch->blend(left, fparg0, right, fparg1, fparg2);
            for (target = 0; target < count; target++) {
                dispatch->apply(result, (*(s32 **)targets)[target]);
            }
        } else {
            u8 *result;
            u32 target;

            result = dispatch->sample(left, fparg0, arg0 + 0x40, fparg2);
            for (target = 0; target < count; target++) {
                dispatch->apply(result, (*(s32 **)targets)[target]);
            }
        }
    }
}

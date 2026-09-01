/* object 352B / window 416B / normalized_diff 100; instruction deficit 16 (88 vs 104); classification: prologue/register-coloring plus stack aggregate placement and callback materialization; ruled out: COP1/MMI/COP2 floors, O1, K&R/old-style callback, explicit-gap aggregate. */
void func_00392a50(arg0, arg1, arg2, arg3, arg4)
u8 *arg0;
f32 *arg1;
s32 arg2;
s32 (*arg3)(s32, f32 *, s32, f32);
s32 arg4;
{
    typedef struct {
        u8 leading_gap[4];
        s32 callback_arg4;
        s32 (*callback)(s32, f32 *, s32, f32);
        s32 callback_arg2;
        f32 value;
        u8 gap0[8];
        f32 vector[3];
        s32 index;
        f32 *first;
        f32 *second;
        f32 *third;
        u8 gap1[4];
        f32 scalar;
    } Stack;
    extern s32 func_003d9760(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5);
    Stack stack;
    f32 *temp_16;
    f32 *temp_17;
    f32 *temp_18;
    f32 factor;
    f32 *records;
    s32 count;
    u16 *cursor;

    stack.callback_arg2 = arg2;
    factor = 1.0f / arg1[3];
    stack.callback = arg3;
    stack.callback_arg4 = arg4;
    cursor = *(u16 **)(arg0 + 0x2C);
    records = *(f32 **)(*(u8 **)(arg0 + 0x5C) + 0x14);
    count = 0;
    if (*(s32 *)(arg0 + 0x10) <= 0) {
        return;
    }
loop:
    temp_17 = records + cursor[1] * 3;
    temp_18 = records + cursor[0] * 3;
    temp_16 = records + cursor[2] * 3;
    if (func_003d9760(arg1, temp_18, temp_17, temp_16, &stack.value, &stack.scalar) == 0) {
        goto block_4;
    }
    stack.scalar *= factor;
    stack.first = temp_18;
    stack.vector[0] = temp_18[0];
    stack.second = temp_17;
    stack.vector[1] = temp_18[1];
    stack.third = temp_16;
    stack.index = count;
    stack.vector[2] = temp_18[2];
    if (stack.callback(stack.callback_arg2, &stack.value, stack.callback_arg4, stack.scalar) == 0) {
        return;
    }
block_4:
    count += 1;
    cursor += 4;
    if (count >= *(s32 *)(arg0 + 0x10)) {
        return;
    }
    goto loop;
}

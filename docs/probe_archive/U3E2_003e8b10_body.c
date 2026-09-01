/* object 372B/window 336B, normalized_diff 237; differing offsets 0x18 onward; frame 96B and five saved registers match but body is 36B oversized; prologue args s32* arg0, saved object/state/result/input; declarations D_00887404 absolute array and D_00887328 block-scope; classification call materialisation, prologue scheduling, branch/layout and return-tail residuals; ruled out explicit-gap error frame and absolute-global addressing probe. */
s32 func_003e8b10(s32 *arg0) {
    s32 *object;
    s32 *input;
    s32 result;
    s32 *state;
    struct {
        s32 sp50;
        s32 sp54;
        s32 sp58;
        s32 sp5C;
    } frame;
    extern u8 D_00887404[];
    extern u8 D_00887328[];
    extern s32 *func_00401450();

    state = (s32 *)D_00887404;
    result = (*state == 1);
    if (result == 0) {
        goto state_error;
    }
    input = arg0;
    result = ((u32)input != 0);
    if (result == 0) {
        goto input_error;
    }
    object = func_00401450();
    result = (object != NULL);
    if (result == 0) {
        goto done;
    }
    func_003e87f0(object, 4, D_008872F0, jtbl_008873E8, 0);
    if (func_003e87f0(object, 0, NULL, input, 0) == 0) {
        result = 0;
        goto update;
    }
    func_003e87f0(object, 11, D_00887328, NULL, 29);
    result = 1;
    iGpffffb7b8 += 1;
update:
    if (result != 0) {
        *state = 2;
    }
done:
    return result;
input_error:
    frame.sp58 = 1;
    frame.sp5C = func_003df590(0x80000016);
    func_003df4d0(&frame.sp58);
    goto done;
state_error:
    frame.sp50 = 1;
    frame.sp54 = func_003df590(1);
    func_003df4d0(&frame.sp50);
    goto done;
}

Closest nonmatching candidate for func_00168ec0; retained for lane archaeology. lverify: object 784B/window 832B, normalized_diff 168. Reverted to bare INCLUDE_ASM because not exact.

s32 func_00168ec0(f32 *arg0, u8 **arg1, f32 *arg2)
{
    s32 result;
    s32 selection;
    s32 prev;
    f32 abs_x;
    f32 abs_y;
    f32 abs_z;
    f32 coordinate;
    f32 current_axis;
    f32 previous_axis;
    f32 current_x;
    f32 previous_x;
    f32 intersection;

    result = 0;
    abs_x = fabsf(arg2[0]);
    abs_y = fabsf(arg2[1]);
    abs_z = fabsf(arg2[2]);
    if (abs_z > abs_y) {
        if (abs_z > abs_x) {
            selection = 2;
        } else {
            selection = 0;
        }
    } else if (abs_y > abs_x) {
        selection = 1;
    } else {
        selection = 0;
    }
    if (selection != 0x7FFFFFFF) {
        prev = 2;
        switch (selection) {
        case 0:
            selection = 0;
            coordinate = arg0[1];
            while (selection < 3) {
                current_axis = *(f32 *)(arg1[selection] + 4);
                if (((current_axis <= coordinate) &&
                     (coordinate < (previous_axis = *(f32 *)(arg1[prev] + 4)))) ||
                    (((previous_axis = *(f32 *)(arg1[prev] + 4)) <= coordinate) &&
                     (coordinate < current_axis))) {
                    current_axis = *(f32 *)(arg1[selection] + 4);
                    current_x = *(f32 *)(arg1[selection] + 8);
                    previous_x = *(f32 *)(arg1[prev] + 8);
                    intersection = current_x +
                        ((coordinate - current_axis) * (previous_x - current_x)) /
                        (previous_axis - current_axis);
                    if (arg0[2] < intersection) {
                        result = result == 0;
                    }
                }
                prev = selection;
                selection += 1;
            }
            break;
        case 1:
            selection = 0;
            coordinate = arg0[2];
            while (selection < 3) {
                current_axis = *(f32 *)(arg1[selection] + 8);
                if (((current_axis <= coordinate) &&
                     (coordinate < (previous_axis = *(f32 *)(arg1[prev] + 8)))) ||
                    (((previous_axis = *(f32 *)(arg1[prev] + 8)) <= coordinate) &&
                     (coordinate < current_axis))) {
                    current_axis = *(f32 *)(arg1[selection] + 8);
                    current_x = *(f32 *)(arg1[selection]);
                    previous_x = *(f32 *)(arg1[prev]);
                    intersection = current_x +
                        ((coordinate - current_axis) * (previous_x - current_x)) /
                        (previous_axis - current_axis);
                    if (arg0[0] < intersection) {
                        result = result == 0;
                    }
                }
                prev = selection;
                selection += 1;
            }
            break;
        case 2:
            selection = 0;
            coordinate = arg0[1];
            while (selection < 3) {
                current_axis = *(f32 *)(arg1[selection] + 4);
                if (((current_axis <= coordinate) &&
                     (coordinate < (previous_axis = *(f32 *)(arg1[prev] + 4)))) ||
                    (((previous_axis = *(f32 *)(arg1[prev] + 4)) <= coordinate) &&
                     (coordinate < current_axis))) {
                    current_axis = *(f32 *)(arg1[selection] + 4);
                    current_x = *(f32 *)(arg1[selection]);
                    previous_x = *(f32 *)(arg1[prev]);
                    intersection = current_x +
                        ((coordinate - current_axis) * (previous_x - current_x)) /
                        (previous_axis - current_axis);
                    if (arg0[0] < intersection) {
                        result = result == 0;
                    }
                }
                prev = selection;
                selection += 1;
            }
            break;
        }
    }
    return result;
}

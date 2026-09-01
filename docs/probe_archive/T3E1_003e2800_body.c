/* object 312B/window 272B, normalized_diff 223; 10-instruction surplus; oversized frame from candidate Obj pointer/local shape; classification declaration/frame, no floor; ruled out no_branch_likely mismatch, missing block, and callee signature. */
u8 *func_003e2800(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    struct Obj {
        s32 type;
        u8 *ptr;
        u8 pad[0x18];
        s32 arg;
    };
    struct Obj *obj;
    s32 error[2];
    u8 *result;
    extern s32 func_003de270(s32 arg0);
    extern u8 *func_003e2750(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_0043f810(void *arg0, void *arg1, s32 arg2);

    obj = (struct Obj *)arg0;
    result = NULL;
    if (obj == NULL) {
        return NULL;
    }
    obj->type = arg2;
    obj->ptr = arg3;
    obj->arg = arg1;
    switch (arg2) {
    case 1:
        if (func_003de270(arg4) != -1) {
            obj->arg = arg4;
            result = arg0;
        }
        break;
    case 2:
        result = func_003e2650(arg0, (s32)arg3, arg4);
        break;
    case 3:
        result = func_003e2750(arg0, (s32)arg3, arg4);
        break;
    case 4:
        func_0043f810(arg0 + 0xC, (void *)arg4, 20);
        result = arg0;
        break;
    default:
        error[0] = 1;
        error[1] = func_003df590(14);
        func_003df4d0(error);
        break;
    }
    return result;
}

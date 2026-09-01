/* object 216B / window 224B / normalized_diff 82 / differing offsets 36,48,88,96,98,99,104,105,106,107,108,109,110,111,112,113 / classification undersized near-miss; frame and Data aggregate offsets exact (display sp+0x30, callback data sp+0x50, scale sp+0x64), corrected block-scope helper declarations func_003e89c0(s32,s32), func_003e8970(s32*,s32), func_003ef6d0(void), func_003ef260(s32,void*,void*), func_003db490(s32,u8*); corrected branch spelling to `!= 0x01000000`; measured schedule+no_branch_likely, schedule moves call delay slots and reproduces float load order but remaining residual has numerator-load/mul ordering, extra/missing nops and tail placement. opt_propagation off and optimization_level 1 worsened. ruled out movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor. */
void func_003db550(u8 *arg0, u8 *arg1) {
    extern s32 func_003e89c0(s32 arg0, s32 arg1);
    extern void func_003e8970(s32 *output, s32 descriptor);
    extern s32 func_003ef6d0(void);
    extern void func_003ef260(s32 arg0, void *arg1, void *arg2);
    extern void func_003db490(s32 arg0, u8 *arg1);
    typedef struct {
        s32 zero;
        u8 *arg0;
        s32 result;
        f32 average;
        s32 count;
        f32 scale;
    } Data;
    typedef struct {
        s32 display[2];
        u8 pad[24];
        Data data;
    } Frame;
    Frame frame;
    u8 *camera;
    u8 *context;
    s32 flags;
    s32 numerator1;

    camera = arg1;
    context = arg0;
    flags = *(s32 *)(context + 8);
    if (((flags & 0x01000000) != 0x01000000) && ((flags & 0x84) != 0)) {
        func_003e8970(frame.display, func_003e89c0(0x01000000, flags));
        numerator1 = frame.display[1];
        frame.data.scale = (f32)(frame.display[0] * numerator1) /
            (2.0f * *(f32 *)(camera + 0x68) * (2.0f * *(f32 *)(camera + 0x6C)));
        frame.data.arg0 = context;
        frame.data.zero = 0;
        if (func_003ef6d0() != 0) {
            func_003ef260(func_003ef6d0(), (void *)func_003db490, &frame.data);
        }
    }
}

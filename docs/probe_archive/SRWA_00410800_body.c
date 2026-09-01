/* object 280/window 304/normalized_diff 132; differing offsets 65,68,70,73,78,92-102; 6 instructions absent; classification undersized source-shape residual; prologue frame 0x70, saved s4/s3/s2/s1/s0 (5), args (s16 arg0,s16 arg1,s16 arg2); corrected block-scope declarations for func_003df590/func_003df4d0/func_004114c0/func_004114d0/func_00414c10/func_00414e10 and iGpffffb9b0; ruled out movz/movn, COP1/MMI/COP2, framed tail-jump, sd/sq floor. */
extern s32 func_003df590();
extern void func_003df4d0();
extern s32 func_004114c0(void);
extern u8 *func_004114d0(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_00414c10(s32 arg0, u8 *arg1);
extern u8 *func_00414e10(u8 *arg0, s32 arg1);
extern s32 iGpffffb9b0;
extern s32 D_008872E0[];
s32 func_00410800(s16 arg0, s16 arg1, s16 arg2)
{
    typedef struct State {
        u8 padding_0[4];
        s32 seed;
        u8 padding_8[0x3c];
        s32 ready;
        u8 padding_48[4];
        u8 padding_4c[0x20];
        s32 field_6c;
        s32 field_70;
        s32 field_74;
        s32 field_78;
    } State;
    typedef struct Buffer {
        u8 padding_0[0x20];
        u8 *field_20;
        u8 padding_24[4];
        u8 *field_28;
        s32 field_2c;
    } Buffer;
    State *state;
    Buffer *buffer;
    u8 *samples;
    s32 result;
    s32 ready;
    s32 error[2];

    ready = (*(u32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x44) != 0);
    result = func_004114c0();
    if (ready == 0) {
        goto fail;
    }
    state = (State *)((u8 *)D_008872E0 + iGpffffb9b0);
    buffer = (Buffer *)((u8 *)state + 0x4c);
    state->field_6c = state->seed;
    state->field_70 = 3;
    state->field_74 = 0;
    state->field_78 = 3;
    buffer->field_28 = func_00414e10((u8 *)result, buffer->field_2c * 2);
    samples = buffer->field_28;
    *(s16 *)samples = arg0;
    *(s16 *)(samples + 2) = arg1;
    *(s16 *)(samples + 4) = arg2;
    if (func_004114d0(buffer->field_20, (u8 *)buffer, 0) != 0) {
        func_00414c10(result, buffer->field_28);
        return 1;
    }
    func_00414c10(result, buffer->field_28);
    goto return_zero;
return_zero:
    goto return_tail;
fail:
    error[1] = 1;
    error[0] = func_003df590(0x23);
    error[1] = error[0];
    func_003df4d0(error);
    goto return_zero;
return_tail:
    return 0;
}

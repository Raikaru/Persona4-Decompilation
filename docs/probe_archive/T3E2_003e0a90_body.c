/* object_size=500B; window=512B; normalized_diff=41; differing_offsets=0x38,0x3A-0x4C and later case-0/default words; instruction_deficit=3 (125 emitted vs 128 retail); classification=undersized scheduling/address-materialisation residual; ruled_out=movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, ee-gcc sd-$sN signature; plain-C matrix struct, switch case order, saved-register/frame shape, schedule on, no_branch_likely on, source-load interleaving, and default NULL return path measured. */
u8 *func_003e0a90(u8 *arg0, u8 *arg1, s32 arg2) {
    typedef struct {
        f32 right[3];
        u32 flags;
        f32 up[3];
        u32 pad1;
        f32 at[3];
        u32 pad2;
        f32 pos[3];
        u32 pad3;
    } Matrix003e;
    struct {
        s32 sp58;
        s32 sp5c;
    } frame;
    f32 scale0;
    f32 scale1;
    f32 scale2;
    f32 value;

    switch (arg2) {
    case 0:
        ((Matrix003e *)arg0)->at[2] = 1.0f;
        scale0 = ((Matrix003e *)arg1)->right[0];
        ((Matrix003e *)arg0)->up[1] = 1.0f;
        scale1 = ((Matrix003e *)arg1)->right[1];
        ((Matrix003e *)arg0)->right[0] = 1.0f;
        scale2 = ((Matrix003e *)arg1)->right[2];
        ((Matrix003e *)arg0)->flags |= 0x20003;
        ((Matrix003e *)arg0)->up[0] = 0.0f;
        ((Matrix003e *)arg0)->right[2] = 0.0f;
        ((Matrix003e *)arg0)->right[1] = 0.0f;
        ((Matrix003e *)arg0)->at[1] = 0.0f;
        ((Matrix003e *)arg0)->at[0] = 0.0f;
        ((Matrix003e *)arg0)->up[2] = 0.0f;
        ((Matrix003e *)arg0)->pos[2] = 0.0f;
        ((Matrix003e *)arg0)->pos[1] = 0.0f;
        ((Matrix003e *)arg0)->pos[0] = 0.0f;
        ((Matrix003e *)arg0)->right[0] = scale0;
        ((Matrix003e *)arg0)->up[1] = scale1;
        ((Matrix003e *)arg0)->at[2] = scale2;
        break;
    case 1:
        value = ((Matrix003e *)arg0)->right[0];
        scale0 = ((Matrix003e *)arg1)->right[0];
        scale1 = ((Matrix003e *)arg1)->right[1];
        scale2 = ((Matrix003e *)arg1)->right[2];
        ((Matrix003e *)arg0)->right[0] = value * scale0;
        value = ((Matrix003e *)arg0)->right[1];
        ((Matrix003e *)arg0)->right[1] = value * scale0;
        value = ((Matrix003e *)arg0)->right[2];
        ((Matrix003e *)arg0)->right[2] = value * scale0;
        value = ((Matrix003e *)arg0)->up[0];
        ((Matrix003e *)arg0)->up[0] = value * scale1;
        value = ((Matrix003e *)arg0)->up[1];
        ((Matrix003e *)arg0)->up[1] = value * scale1;
        value = ((Matrix003e *)arg0)->up[2];
        ((Matrix003e *)arg0)->up[2] = value * scale1;
        value = ((Matrix003e *)arg0)->at[0];
        ((Matrix003e *)arg0)->at[0] = value * scale2;
        value = ((Matrix003e *)arg0)->at[1];
        ((Matrix003e *)arg0)->at[1] = value * scale2;
        value = ((Matrix003e *)arg0)->at[2];
        ((Matrix003e *)arg0)->at[2] = value * scale2;
        break;
    case 2:
        value = ((Matrix003e *)arg0)->right[0];
        scale0 = ((Matrix003e *)arg1)->right[0];
        scale1 = ((Matrix003e *)arg1)->right[1];
        scale2 = ((Matrix003e *)arg1)->right[2];
        ((Matrix003e *)arg0)->right[0] = value * scale0;
        value = ((Matrix003e *)arg0)->right[1];
        ((Matrix003e *)arg0)->right[1] = value * scale0;
        value = ((Matrix003e *)arg0)->right[2];
        ((Matrix003e *)arg0)->right[2] = value * scale0;
        value = ((Matrix003e *)arg0)->up[0];
        ((Matrix003e *)arg0)->up[0] = value * scale1;
        value = ((Matrix003e *)arg0)->up[1];
        ((Matrix003e *)arg0)->up[1] = value * scale1;
        value = ((Matrix003e *)arg0)->up[2];
        ((Matrix003e *)arg0)->up[2] = value * scale1;
        value = ((Matrix003e *)arg0)->at[0];
        ((Matrix003e *)arg0)->at[0] = value * scale2;
        value = ((Matrix003e *)arg0)->at[1];
        ((Matrix003e *)arg0)->at[1] = value * scale2;
        value = ((Matrix003e *)arg0)->at[2];
        ((Matrix003e *)arg0)->at[2] = value * scale2;
        value = ((Matrix003e *)arg0)->pos[0];
        ((Matrix003e *)arg0)->pos[0] = value * scale0;
        value = ((Matrix003e *)arg0)->pos[1];
        ((Matrix003e *)arg0)->pos[1] = value * scale1;
        value = ((Matrix003e *)arg0)->pos[2];
        ((Matrix003e *)arg0)->pos[2] = value * scale2;
        break;
    default:
        frame.sp58 = 1;
        frame.sp5c = func_003df590(0x80000003, 0x006FB6F0);
        func_003df4d0(&frame.sp58);
        arg0 = NULL;
        break;
    }
    ((Matrix003e *)arg0)->flags &= 0xFFFDFFFCu;
    return arg0;
}

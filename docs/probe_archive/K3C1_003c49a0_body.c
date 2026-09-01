/* object 148B, window 160B, normalized_diff 74; differing offsets 0x20,0x2c,0x2d,0x2e,0x30,0x33,0x35,0x36,0x37,0x3c,0x3d,0x3e,0x3f,0x40,0x42,0x43. Tried typed func_003c4220 callee, declaration/order variants, straight and do/while loops, explicit cursor/index locals, callback table teardown, and schedule on; residual entry slt/beq guard, branch layout, and callback target remain. */
#pragma schedule on
u8 *func_003c49a0(u8 *arg0) {
    extern s32 func_003c4220(u8 *arg0);
    u8 **items;
    s32 index;
    u8 **cursor;
    s32 count;
    u8 *self;

    self = arg0;
    items = *(u8 ***)(self + 0);
    if (items != NULL) {
        count = *(s32 *)(self + 4);
        index = 0;
        cursor = items;
        if (count > 0) {
            do {
                func_003c4220(*cursor);
                index += 1;
                *cursor = NULL;
                cursor += 1;
            } while (index < count);
        }
        jtbl_008873EC[0](items);
        *(u8 ***)(self + 0) = NULL;
    }
    *(s32 *)(self + 4) = 0;
    *(s32 *)(self + 8) = 0;
    return self;
}
#pragma schedule off
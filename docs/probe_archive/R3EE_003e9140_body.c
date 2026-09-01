/* object 272 / window 256 / normalized_diff 37 / differing offsets 28,48,64,100,108,112,120,124,128,132,136,140,144,148,152,156,160,164,168,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268 / classification undersized? no: oversized by 16 bytes, control-flow/layout residual / ruled out prologue, saved-register count, argument count, COP1 accumulator, movz/movn, standalone MMI, framed tail-jump */
s32 *func_003e9140(s32 *arg0) {
    extern void func_003e8ed0();
    u8 *parent;
    u8 *temp;
    u8 *child;
    u8 *self;

    self = (u8 *)arg0;
    if (*(u8 **)(self + 4) != NULL) {
        temp = *(u8 **)(*(u8 **)(self + 4) + 0xA0);
        *(u8 **)(self + 0xA0) = temp;
        parent = *(u8 **)(self + 0x98);
        if (parent == NULL) {
            goto done;
        }
outer:
        *(u8 **)(parent + 0xA0) = temp;
        child = *(u8 **)(parent + 0x98);
        if (child == NULL) {
            goto child_null;
        }
inner:
        func_003e8ed0(child, temp);
        child = *(u8 **)(child + 0x9C);
        if (child != NULL) {
            goto inner;
        }
        parent = *(u8 **)(parent + 0x9C);
        goto parent_check;
done:
        return (s32 *)self;
child_null:
        parent = *(u8 **)(parent + 0x9C);
parent_check:
        if (parent != NULL) {
            goto outer;
        }
        goto done;
    } else {
        *(u8 **)(self + 0xA0) = self;
        temp = *(u8 **)(self + 0x98);
        if (temp == NULL) {
            goto done;
        }
outer_fallback:
        *(u8 **)(temp + 0xA0) = self;
        child = *(u8 **)(temp + 0x98);
        if (child == NULL) {
            goto child_null_fallback;
        }
inner_fallback:
        func_003e8ed0(child, self);
        child = *(u8 **)(child + 0x9C);
        if (child != NULL) {
            goto inner_fallback;
        }
        temp = *(u8 **)(temp + 0x9C);
        if (temp != NULL) {
            goto outer_fallback;
        }
        goto done;
child_null_fallback:
        temp = *(u8 **)(temp + 0x9C);
        if (temp != NULL) {
            goto outer_fallback;
        }
        goto done;
    }
}

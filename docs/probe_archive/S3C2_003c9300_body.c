/* func_003c9300: object 556B/window 560B/normalized_diff 234; undersized 4B but frame 0xC0 vs retail 0x50; first differing offsets 0,4-8,10-12,14-16,18,20-23; explicit labels/callback declarations tried; ASM restored. */
void func_003c9300(u8 *arg0) {
    extern void func_003e1ea0(u8 *arg0);
    extern void func_003ca9d0(u8 *arg0);
    extern void func_003ca960(u8 *arg0);
    extern void func_003e3c20(u8 *arg0, u8 *arg1);
    extern void func_003c5760(u8 *arg0);
    s32 index;
    u8 *current;
    u8 *sentinel;
    u8 *self;
    u8 *temp;

    self = arg0;
    if (*(s32 *)self == -2)
        goto state_neg2;
    if (*(s32 *)self == -1)
        goto state_neg1;
    goto state_default;
state_neg2:
    jtbl_008873EC[0]();
    goto done;
state_default:
    temp = *(u8 **)(self + 8);
    if (temp != NULL)
        func_003c9300(temp);
    *(u8 **)(self + 8) = NULL;
    temp = *(u8 **)(self + 0xC);
    if (temp != NULL)
        func_003c9300(temp);
    *(u8 **)(self + 0xC) = NULL;
    jtbl_008873EC[0](self);
    goto done;
state_neg1:
    temp = *(u8 **)(self + 0x34);
    if (temp != NULL)
        func_003e1ea0(temp);
    sentinel = self + 0x38;
    current = *(u8 **)sentinel;
    if (current != sentinel) {
        do {
            temp = current;
            current = *(u8 **)current;
            func_003ca9d0(temp);
        } while (current != sentinel);
    }
    sentinel = self + 0x40;
    current = *(u8 **)sentinel;
    if (current != sentinel) {
        do {
            temp = current;
            current = *(u8 **)current;
            func_003ca960(temp);
        } while (current != sentinel);
    }
    func_003e3c20(D_0070B040, self);
    temp = *(u8 **)(self + 8);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(self + 8) = NULL;
    }
    temp = *(u8 **)(self + 0xC);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(self + 0xC) = NULL;
    }
    temp = *(u8 **)(self + 0x30);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(self + 0x30) = NULL;
    }
    temp = *(u8 **)(self + 4);
    if (temp != NULL) {
        jtbl_008873EC[0](temp);
        *(u8 **)(self + 4) = NULL;
    }
    index = 0;
    current = self + 0x10;
    do {
        temp = *(u8 **)current;
        if (temp != NULL) {
            jtbl_008873EC[0](temp);
            *(u8 **)current = NULL;
        }
        index += 1;
        current += 4;
    } while (index < 8);
    temp = *(u8 **)(self + 0x78);
    if (temp != NULL) {
        func_003c5760(temp);
        *(u8 **)(self + 0x78) = NULL;
    }
    jtbl_008873EC[0](self);
done:
    return;
}

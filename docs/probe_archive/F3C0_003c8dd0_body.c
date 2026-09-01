/* func_003c8dd0 archive: object 232B/window 224B, normalized_diff 151, differing offsets 16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,124,128,132,136,144,148,156,160,164,168,172,176,180,184,192,196,200,204,208,212,216,224,228; ruled out stamp-local saved-register ordering and schedule-on prologue scheduling (scheduled candidate object 212B/window 224B). */
s32 func_003c8dd0(u8 *arg0) {
    extern void func_003c8ce0(void);
    extern u8 *func_003bfae0(u8 *arg0);
    extern s32 func_003e8200(u8 *arg0, u8 *arg1);
    u8 *self;
    u8 *node;
    u8 *sentinel;
    u16 *stamp;
    u8 *item;

    self = arg0;
    if (((s32 (*)(void))func_003c8ce0)() != 0) {
        node = *(u8 **)(self + 0x38);
        sentinel = self + 0x38;
        if (node != sentinel) {
            stamp = D_008872E8;
            do {
                item = *(u8 **)(node + 8);
                if ((*(u8 *)(item + 2) & 4) != 0 &&
                    *(u16 *)(item + 0x60) != stamp[0]) {
                    if (func_003e8200(D_008872E0, func_003bfae0(item)) != 0) {
                        ((void (*)(u8 *))*(void **)(item + 0x48))(item);
                    }
                    *(u16 *)(item + 0x60) = stamp[0];
                }
                node = *(u8 **)(node + 0);
            } while (node != sentinel);
        }
    }
    return self;
}

/* object 332B/window 320B, normalized_diff 187; differing offsets 0x20 onward; 12-byte surplus from loop/control-flow and callback register coloring; prologue frame 96B with five saved registers and args none; declarations iGpffffb798/iGpffffb794/iGpffffb790/D_008873F8 block-scope, old-style func_003e18c0; classification declaration/order and branch-shape residual; ruled out operand swap and goto duplicate-guard probe. */
s32 func_003e36c0(void) {
    u32 index;
    u8 *special;
    s32 offset;
    u8 *handler;
    void (**callback)(u8 *, u8 *);
    u8 *list;
    extern u8 *iGpffffb798;
    extern s32 iGpffffb794;
    extern u8 *iGpffffb790;
    extern void *D_008873F8[];
    extern u8 *func_003e18c0();
    extern void func_003e13d0();
    extern void func_003e3680();
    extern void func_003e12f0();

    if (iGpffffb798 != NULL) {
        func_003e18c0(iGpffffb798, func_003e3680, iGpffffb798);
        if ((void *)func_003e13d0 != D_008873F8[0]) {
            index = 0;
            if (iGpffffb794 != 0) {
                callback = jtbl_008873FC;
                offset = 0;
                do {
                    list = *(u8 **)(*(u8 **)(iGpffffb790 + offset) + 0x10);
                    special = NULL;
                    if (list != NULL) {
                        special = *(u8 **)(list + 0x38);
                    }
                    if (list == NULL) {
                        goto process_special;
                    }
                    do {
                        handler = *(u8 **)(list + 0x30);
                        callback[0](NULL, list);
                        list = handler;
                    } while (list != NULL);
process_special:
                    if ((special != NULL) && (*(s32 *)(special + 0x10) != 0)) {
                        *(s32 *)special = *(s32 *)(special + 4);
                        *(s32 *)(special + 0x10) = 0;
                        *(s32 *)(special + 0x14) = 0;
                    }
                    index += 1;
                    offset += 4;
                } while (index < (u32)iGpffffb794);
            }
            if (iGpffffb790 != NULL) {
                jtbl_008873EC[0](iGpffffb790);
                iGpffffb790 = NULL;
            }
        }
        func_003e12f0(iGpffffb798);
        iGpffffb798 = NULL;
    }
    return 1;
}

/* Closest attempted candidate for func_002167f0; reverted because it did not match retail. */
void func_002167f0(u8 *arg0, u8 *arg1)
{
    extern s32 func_001b1540(void);
    extern s64 func_00243e90(u8 *arg0);
    extern void func_002142b0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
    extern void func_00215c10(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
    extern void func_002161d0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
    extern void func_002019d0(s32 *arg0, f32 fparg0, f32 fparg1);
    s32 *work;
    u8 *selected;
    u8 *iter;
    u8 *old;
    s32 selectedIndex;
    s32 count;
    s32 index;
    u8 local[0x40];
    register f32 x;
    register f32 y;

    work = (s32 *)func_00452560(*(s32 *)(arg1 + 0xC));
    if ((*(s32 *)work & 1) != 0 && (*(s32 *)arg1 & 0x100) != 0) {
        func_00201350();
        selected = (u8 *)func_001b1540();
        if (selected != NULL) selected = *(u8 **)(selected + 0x30);
        else selected = *(u8 **)(arg1 + 8);
        selectedIndex = -1;
        count = 0;
        iter = *(u8 **)(iGpffffb3ac + 0x17C);
        while (iter != NULL) {
            if ((*(s32 *)(iter + 0x9C) & 8) != 0) {
                *(f32 *)(local + 0x10 + count * 8) = 485.0f;
                *(f32 *)(local + 0x14 + count * 8) = -15.0f + (f32)count * 105.0f;
                *(u8 **)(local + 0x30 + count * 4) = iter;
                if (selected == iter) selectedIndex = count;
                count += 1;
            }
            iter = *(u8 **)(iter + 0xA68);
        }
        if (selectedIndex < 0) {
            old = *(u8 **)(arg1 + 8);
            if (old != NULL) {
                s32 flags = *(s32 *)(old + 0xA10);
                flags &= ~0xC; *(s32 *)(old + 0xA10) = flags;
                flags |= 0x10; *(s32 *)(old + 0xA10) = flags;
                if ((flags & 0x40) != 0) {
                    flags &= ~0x60; *(s32 *)(old + 0xA10) = flags;
                    flags |= 0x80; *(s32 *)(old + 0xA10) = flags;
                    *(f32 *)(old + 0xA20) = 1.0f;
                }
                *(u8 **)(arg1 + 8) = NULL;
            }
        } else {
            old = *(u8 **)(arg1 + 8);
            if (old != selected) {
                if (old != NULL) {
                    s32 flags = *(s32 *)(old + 0xA10);
                    flags &= ~0xC; *(s32 *)(old + 0xA10) = flags;
                    flags |= 0x10; *(s32 *)(old + 0xA10) = flags;
                    if ((flags & 0x40) != 0) {
                        flags &= ~0x60; *(s32 *)(old + 0xA10) = flags;
                        flags |= 0x80; *(s32 *)(old + 0xA10) = flags;
                        *(f32 *)(old + 0xA20) = 1.0f;
                    }
                }
                old = selected;
                {
                    s32 flags = *(s32 *)(old + 0xA10);
                    flags |= 0xC; *(s32 *)(old + 0xA10) = flags;
                    flags &= ~0x10; *(s32 *)(old + 0xA10) = flags;
                    if ((s16)func_00243e90(*(u8 **)(old + 0xA64)) == 4) {
                        flags = *(s32 *)(old + 0xA10);
                        flags |= 0x60; *(s32 *)(old + 0xA10) = flags;
                        flags &= ~0x80; *(s32 *)(old + 0xA10) = flags;
                        *(f32 *)(old + 0xA20) = 1.0f;
                    }
                }
                *(u8 **)(arg1 + 8) = old;
            }
        }
        index = 0;
        while (index < count) {
            old = *(u8 **)(local + 0x30 + index * 4);
            x = *(f32 *)(local + 0x10 + index * 8);
            y = *(f32 *)(local + 0x14 + index * 8);
            if ((*(s32 *)(old + 0xA10) & 0x1C) != 0) func_00215c10(work, old, index & 0xFFFF, x, y);
            if ((*(s32 *)(old + 0xA10) & 0xE0) != 0) func_002161d0(work, old, index & 0xFFFF, x, y);
            index += 1;
        }
        index = 0;
        while (index < count) {
            func_002142b0(work, *(u8 **)(local + 0x30 + index * 4), index & 0xFFFF,
                          *(f32 *)(local + 0x10 + index * 8), *(f32 *)(local + 0x14 + index * 8));
            index += 1;
        }
        func_002019d0(work, 1.0f, 1.0f);
    }
}

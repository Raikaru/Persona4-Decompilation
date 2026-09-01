/* object 908B window 1008B nd 678; differing offsets begin 0,4,6,7,8,10,11,12,14,16,18,20,22,25,28,30; deficit 25 instructions; classification undersized/prologue-and-register-shape; ruled out: missing-block-only diagnosis, no floor instruction, no pragma tested */
u8 *func_003ea690(u8 *arg0, u8 *arg1)
{
    extern s32 func_003df590();
    extern void func_003df4d0(void *arg0);
    extern void func_003e3b70(u8 *arg0, u8 *arg1);
    extern void func_003e3c20(u8 *arg0, u8 *arg1);
    extern u8 *func_003ea3e0(u8 *arg0);
    extern void func_003ebac0(u8 *arg0, u8 *arg1);
    struct {
        s32 value;
        s32 error;
    } unknown_error;
    struct {
        s32 value;
        s32 error;
    } mismatch_error;
    u8 *result;
    s32 outer;
    s32 inner;
    u8 *src;
    u8 *dst;
    s32 length;
    s32 count;
    s32 type;

    if (*(s32 *)(arg0 + 4) != *(s32 *)(arg1 + 4) ||
        *(s32 *)(arg0 + 8) != *(s32 *)(arg1 + 8)) {
        mismatch_error.value = 1;
        mismatch_error.error = func_003df590(0x8000000A);
        func_003df4d0(&mismatch_error);
        return NULL;
    }

    type = *(s32 *)(arg0 + 0xc);
    switch (type) {
    case 4:
    case 8:
        result = D_008873F8[0](
            *(u8 **)((u8 *)D_008872E0 + iGpffffb7c0),
            0x30018);
        if (result != NULL) {
            *(s32 *)(result + 4) = *(s32 *)(arg0 + 4);
            *(s32 *)(result + 8) = *(s32 *)(arg0 + 8);
            *(s32 *)(result + 0xc) = type;
            *(s32 *)(result + 0x14) = 0;
            *(s32 *)(result + 0x18) = 0;
            *(s32 *)result = 0;
            func_003e3b70(D_0070B7C0, result);
        } else {
            result = NULL;
        }
        if (result == NULL) {
            return NULL;
        }
        if (func_003ea3e0(result) == NULL) {
            if ((*(s32 *)result & 1) != 0) {
                jtbl_008873EC[0](*(u8 **)(result + 0x14));
                *(u8 **)(result + 0x14) = NULL;
                *(s32 *)(result + 0x18) = 0;
                *(s32 *)result &= ~1;
            }
            func_003e3c20(D_0070B7C0, result);
            jtbl_008873FC[0](
                *(u8 **)((u8 *)D_008872E0 + iGpffffb7c0),
                result);
            return NULL;
        }
        func_003ebac0(result, arg0);
        if ((*(s32 *)arg0 & 1) != 0) {
            jtbl_008873EC[0](*(u8 **)(arg0 + 0x14));
            *(u8 **)(arg0 + 0x14) = NULL;
            *(s32 *)(arg0 + 0x18) = 0;
            *(s32 *)arg0 &= ~1;
        }
        *(s32 *)(arg0 + 0xc) = 0x20;
        func_003ea3e0(arg0);
        func_003ebac0(arg0, result);
        jtbl_008873EC[0](*(u8 **)(result + 0x14));
        *(u8 **)(result + 0x14) = NULL;
        *(s32 *)(result + 0x18) = 0;
        *(s32 *)result &= ~1;
        if ((*(s32 *)result & 1) != 0) {
            jtbl_008873EC[0](*(u8 **)(result + 0x14));
            *(u8 **)(result + 0x14) = NULL;
            *(s32 *)(result + 0x18) = 0;
            *(s32 *)result &= ~1;
        }
        func_003e3c20(D_0070B7C0, result);
        jtbl_008873FC[0](
            *(u8 **)((u8 *)D_008872E0 + iGpffffb7c0),
            result);
    case 32:
        src = *(u8 **)(arg1 + 0x14);
        dst = *(u8 **)(arg0 + 0x14);
        outer = 0;
        if (*(s32 *)(arg0 + 8) > 0) {
            type = *(s32 *)(arg1 + 0xc);
            do {
                if (type == 32) {
                    u8 *out = dst;
                    inner = 0;
                    if (*(s32 *)(arg0 + 4) > 0) {
                        do {
                            *(u8 *)(out + 3) =
                                *(u8 *)(*(u8 **)(arg1 + 0x18) +
                                        (*(u8 *)src * 4) + 3);
                            inner += 1;
                            src += 1;
                            out += 4;
                        } while (inner < *(s32 *)(arg0 + 4));
                    }
                } else if (type == 8 || type == 4) {
                    u8 *in = src;
                    inner = 0;
                    if (*(s32 *)(arg0 + 4) > 0) {
                        do {
                            *(u8 *)(dst + 3) = *(u8 *)(in + 3);
                            inner += 1;
                            in += 4;
                            dst += 4;
                        } while (inner < *(s32 *)(arg0 + 4));
                    }
                }
                outer += 1;
                src += *(s32 *)(arg1 + 0x10);
                dst += *(s32 *)(arg0 + 0x10);
            } while (outer < *(s32 *)(arg0 + 8));
        }
        return arg0;
    default:
        unknown_error.value = 1;
        unknown_error.error = func_003df590(0x80000009);
        func_003df4d0(&unknown_error);
        return NULL;
    }
}

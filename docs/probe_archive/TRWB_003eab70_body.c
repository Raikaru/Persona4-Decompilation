/* object 720B window 912B nd 523; differing offsets begin 0,24,25,26,27,28,29,30,31,36,37,38,39,40,42,44; deficit 48 instructions; classification undersized/prologue-and-register-shape; ruled out: no floor instruction, no pragma tested */
s8 *func_003eab70(s8 *arg0, s32 arg1, s32 (*arg2)(s32, s32), s32 *arg3)
{
    extern s32 func_003e50a0(void);
    extern s32 func_003df590();
    extern void func_003df4d0(void *arg0);
    extern void func_0043f810(s8 *arg0, s8 *arg1, s32 arg2);
    extern s8 *(*D_008873AC[])(s8 *arg0, s8 *arg1);
    extern s8 *(*D_008873C0[])(s8 *arg0, s32 arg1);
    extern s32 (*D_008873D4[])(s8 *arg0);
    extern s8 *(*D_008873E8[])(s32 arg0, s32 arg1);
    extern s8 *(*D_008873F0[])(s32 arg0, s32 arg1, s32 arg2);
    struct {
        s32 value;
        s32 error;
    } error_a;
    struct {
        s32 value;
        s32 error;
    } error_b;
    s8 *current;
    s8 *next;
    s8 *cache;
    s8 *cache_next;
    s32 offset;
    s32 size;
    s32 (*get_length)(s8 *arg0);
    s8 *(*find_delimiter)(s8 *arg0, s32 arg1);
    s8 *(*alloc_with_cache)(s32 arg0, s32 arg1, s32 arg2);
    s8 *(*alloc_direct)(s32 arg0, s32 arg1);
    s8 *(*copy_from_cache)(s8 *arg0, s8 *arg1);
    u8 *base;

    base = (u8 *)D_008872E0 + iGpffffb7c0;
    current = *(s8 **)(base + 4);
    if (func_003e50a0() == 0 && current != NULL && *current != 0) {
        get_length = D_008873D4[0];
        alloc_with_cache = D_008873F0[0];
        alloc_direct = D_008873E8[0];
        copy_from_cache = D_008873AC[0];
        for (;;) {
            if (current == NULL || *current == 0) {
                return arg0;
            }
            find_delimiter = D_008873C0[0];
            next = find_delimiter(current, 0x3b);
            if (next != NULL) {
                offset = next - current;
                next += 1;
            } else {
                offset = get_length(current);
            }
            size = arg1 + offset + get_length(arg0);
            if (*(s32 *)(base + 0x214) < size) {
                if (*(s32 *)(base + 0x210) != 0) {
                    cache = alloc_with_cache(
                        *(s32 *)(base + 0x210), size, 0x01040018);
                } else {
                    cache = alloc_direct(size, 0x01040018);
                }
                if (cache != NULL) {
                    *(s32 *)(base + 0x210) = (s32)cache;
                    *(s32 *)(base + 0x214) = size;
                } else {
                    error_a.value = 1;
                    error_a.error = func_003df590(0x80000013, size);
                    func_003df4d0(&error_a);
                    cache = NULL;
                }
            } else {
                cache = *(s8 **)(base + 0x210);
            }
            if (cache == NULL) {
                return NULL;
            }
            func_0043f810(cache, current, offset);
            copy_from_cache(cache + offset, arg0);
            if (arg2((s32)cache, (s32)arg3) == 0) {
                return arg0;
            }
            current = next;
        }
    }

    size = arg1 + D_008873D4[0](arg0);
    if (*(s32 *)(base + 0x214) < size) {
        if (*(s32 *)(base + 0x210) != 0) {
            cache_next = D_008873F0[0](
                *(s32 *)(base + 0x210), size, 0x01040018);
        } else {
            cache_next = D_008873E8[0](size, 0x01040018);
        }
        if (cache_next != NULL) {
            *(s8 **)(base + 0x210) = cache_next;
            *(s32 *)(base + 0x214) = size;
        } else {
            error_b.value = 1;
            error_b.error = func_003df590(0x80000013, size);
            func_003df4d0(&error_b);
            cache_next = NULL;
        }
    } else {
        cache_next = *(s8 **)(base + 0x210);
    }
    if (cache_next != NULL) {
        D_008873AC[0](cache_next, arg0);
        arg2((s32)cache_next, (s32)arg3);
        return arg0;
    }
    return NULL;
}

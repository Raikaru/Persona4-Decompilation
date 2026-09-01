/* Closest clean-C probe for FUN_001D94D0; retained as ASM because it did not match. */
typedef signed __int128 s128;
s32 func_001d94d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, code arg5)
{
    u8 *node;
    u8 *work;
    u32 options;
    s128 special_flag;
    s128 filter_flag;
    u32 mask;
    u16 node_flags;
    u8 type;
    s32 status;
    s8 result;
    code callback;

    callback = arg5;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg2 & 0xFFFF;
    options = arg4 & 0xFFFF;
    special_flag = options & 4;
    filter_flag = arg3 & 0x80000;
    while (node != NULL) {
        node_flags = *(u16 *)(node + 0x1A);
        if ((node_flags & 1) != 0 && (node_flags & 8) != 0) {
            work = *(u8 **)(node + 0x30);
            type = *(u8 *)(work + 0xA2);
            if ((mask & (1 << type)) != 0) {
                if (options == 0) {
                    goto base_filter;
                }
                if ((options & 1) != 0 &&
                    func_00232710(*(u8 **)(work + 0xA64), 0x100000) == 0) {
                    goto next_node;
                }
                if ((options & 2) != 0) {
                    status = func_0023d6e0((s8)arg1);
                    if ((status & 0xE0001) == 0) {
                        if ((status & 2) != 0) {
                            result = func_00233a90(*(u8 **)(work + 0xA64), 0x10);
                            if (result > 0) {
                                goto next_node;
                            }
                        } else {
                            if ((status & 0x40) != 0) {
                                goto special_filter;
                            }
                            result = func_00233a90(*(u8 **)(work + 0xA64), 0x11);
                            if (result > 0) {
                                goto next_node;
                            }
                        }
                    }
                }
special_filter:
                if ((options & 0xC) != 0 && type == 1 &&
                    func_001f9ce0(node, (s8)arg1) == 0 &&
                    func_0010f420(*(u16 *)(work + 0xA4), arg1 & 0xFFFF) == 0) {
                    if ((u32)special_flag == 0) {
                        return 1;
                    }
                    goto next_node;
                }
base_filter:
                if (((u32)filter_flag == 0 ||
                     func_002428f0(*(u8 **)(work + 0xA64), 0) == 0) &&
                    func_00232710(*(u8 **)(work + 0xA64), arg3) == 0 &&
                    callback(node, arg1) != 0) {
                    return 1;
                }
            }
        }
next_node:
        node = *(u8 **)(node + 0x450);
    }
    return 0;
}

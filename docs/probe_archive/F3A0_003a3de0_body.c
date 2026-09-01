/* object_size=168B window=176B normalized_diff=19; differing offsets=0x28,0x38,0x4C,0x54,0x68,0x6C,0x70,0x78,0x80,0x84,0x88,0x8C,0x90,0x94,0x98,0x9C,0xA4; best do-while/goto reconstruction with retail sltu-$at loop compare and scheduled node update; ruled out nested/while/switch/ternary layouts, O1, schedule/no_branch_likely, and opt_propagation probes.}
void func_003a3de0(u8 *arg0)
{
    u32 count;
    u8 *base;
    u8 *list;
    u8 *node;

    base = *(u8 **)(arg0 + iGpffffb610);
    if ((*(s32 *)(base + 0x44) & 0x10) != 0)
        goto cleanup;
    list = *(u8 **)(base + 0x9C);
    if (*(s32 *)(list + 0xD8) == 0)
        goto cleanup;
    count = 0;
    node = list;
    do {
        if (*(s32 *)(node + 0x10) != 0)
            goto call_body;
    loop_check:
        node += 0x20;
    } while ((u32)*(s32 *)(list + 0xE8) >= ++count);
cleanup:
    goto done;
call_body:
    func_003f32d0();
    func_003f32d0();
    goto loop_check;
done:
    return;
}

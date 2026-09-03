/* Lane119d3b measured body for func_003bb210.
 * Compiled with MWCCPS2 3.0.1 b119 inside src/promoted/code1_003b_cw119.c.
 * Best normalized_diff: 47 words (largely saved-register and branch-tail layout).
 */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003bb210(u8 *arg0) {
    s32 buf[10];
    s32 size;
    s32 field_20;
    u8 *work;
    u8 *result;
    extern u8 *func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern void (*D_008873B0[])(void *dst, void *src, s32 size);

    if (func_003e2910(arg0, buf, 0x28) != 0x28) {
        return NULL;
    }
    field_20 = buf[8];
    size = field_20 * 0xC;
    work = jtbl_008873E8[0](size, 0x10102);
    if (work == NULL) {
        goto error;
    }
    if (func_003df300(arg0, work, size) == 0) {
        return NULL;
    }
    result = func_003bbbe0(field_20, buf[9], work);
    D_008873B0[0](result + 0x18, buf, 0x20);
    *result = 0xC;
    jtbl_008873EC[0](work);
    return result;
error:
    ((s32 *)(((u8 *)buf) + 0x28))[0] = 0x102;
    ((s32 *)(((u8 *)buf) + 0x28))[1] = func_003df590(0x80000013, size);
    func_003df4d0((s32 *)(((u8 *)buf) + 0x28));
    return NULL;
}
#pragma no_branch_likely off
#pragma schedule off

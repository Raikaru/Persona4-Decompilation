/* Candidate reconstruction archived: setup/allocation body emitted a MISMATCH in scoped lverify; reverted per lane policy. */
u8 *func_0046e850(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    s32 result;
    s32 width;
    s32 height;
    s32 size;
    u8 *work;
    u8 *buffer;

    func_0044ea90(D_007130F8, 0x17B);
    work = D_008873F4[0](1, 0x560, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    result = func_00451fc0((s32)arg0, (s32)D_00713108, 0x101, 0, 0,
                           (void (*)(u8 *))func_0046d750,
                           (void (*)(u8 *))func_0046e7f0, work);
    *(s32 *)(work + 4) = 1;
    *(f32 *)(work + 0xC) = *(f32 *)(arg1 + 0);
    *(f32 *)(work + 0x10) = *(f32 *)(arg1 + 4);
    *(f32 *)(work + 0x14) = *(f32 *)(arg1 + 8);
    *(f32 *)(work + 0x18) = *(f32 *)(arg1 + 0xC);
    *(u8 *)(work + 0x1C) = *(u8 *)(arg2 + 0);
    *(u8 *)(work + 0x1D) = *(u8 *)(arg2 + 1);
    *(u8 *)(work + 0x1E) = *(u8 *)(arg2 + 2);
    *(u8 *)(work + 0x1F) = *(u8 *)(arg2 + 3);
    *(u8 *)(work + 0x20) = *(u8 *)(arg3 + 0);
    *(u8 *)(work + 0x21) = *(u8 *)(arg3 + 1);
    *(u8 *)(work + 0x22) = *(u8 *)(arg3 + 2);
    *(u8 *)(work + 0x23) = *(u8 *)(arg3 + 3);
    width = *(s32 *)(arg1 + 0);
    if (width < 0) {
        width += 7;
    }
    width >>= 3;
    height = *(s32 *)(arg1 + 4);
    if (height < 0) {
        height += 7;
    }
    height >>= 3;
    *(s32 *)(work + 0x44) = width * height + 0x20;
    func_0044ea90(D_007130F8, 0x18C);
    buffer = D_008873F4[0](1, *(s32 *)(work + 0x44), 0x40000);
    *(u8 **)(work + 0x48) = buffer;
    *(u8 **)(work + 0x4C) = buffer;
    return (u8 *)result;
}

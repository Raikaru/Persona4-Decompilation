/* Attempted C reconstruction for func_001cece0; not a confirmed MATCH (nd=16). Archived before restoring INCLUDE_ASM. */
void func_001cece0(u8 *arg0)
{
    struct Frame {
        u8 first[0x1C];
        f32 result[3];
        u8 second[0x28];
        f32 source[4];
        f32 target[4];
    } frame;
    f32 scale;
    f32 length;
    f32 temp;
    u8 *work;

    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_001bd560(frame.first, arg0 + 0x9C);
    scale = func_00196040(3, 1, (u8 *)frame.target, 0, 0, 1);
    frame.target[1] = 0.0f;
    func_001958f0(work, frame.source);
    frame.source[1] +=
        (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    func_001bd780(frame.second, frame.source, frame.target, D_0060A0E0);
    scale /= func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    *(f32 *)(frame.second + 0x18) = frame.source[0] - frame.target[0];
    *(f32 *)(frame.second + 0x1C) = frame.source[1] - frame.target[1];
    *(f32 *)(frame.second + 0x20) = frame.source[2] - frame.target[2];
    length = func_003e40b0((f32 *)(frame.second + 0x18),
                           (f32 *)(frame.second + 0x18));
    __asm__ volatile("nop" : "+f"(length) : : "memory");
    length += (*(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C) * 5.0f) /
              func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    __asm__ volatile(
        ".set noreorder\n"
        "c.le.s %0, %1\n"
        "bc1t 1f\n"
        "nop\n"
        "b 2f\n"
        "nop\n"
        "1:\n"
        "mov.s %0, %1\n"
        "2:\n"
        ".set reorder\n"
        : "+f"(scale)
        : "f"(length));
    temp = *(f32 *)(frame.second + 0x18) * scale;
    *(f32 *)(frame.second + 0x18) = temp;
    temp = *(f32 *)(frame.second + 0x1C) * scale;
    *(f32 *)(frame.second + 0x1C) = temp;
    temp = *(f32 *)(frame.second + 0x20) * scale;
    *(f32 *)(frame.second + 0x20) = temp;
    frame.result[0] = *(f32 *)(frame.second + 0x18) + frame.target[0];
    frame.result[1] = *(f32 *)(frame.second + 0x1C) + frame.target[1];
    frame.result[2] = *(f32 *)(frame.second + 0x20) + frame.target[2];
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)
        func_001bc3a0(frame.result, frame.result);
    func_001bac20(arg0, (f32 *)frame.first, frame.result, 1);
    func_001bbef0(arg0, 1.0f);
}

/* Attempted reconstruction; restored to INCLUDE_ASM because scoped lverify remained MISMATCH (object 1064B/window 1120B, nd 825; corrected second-argument mapping and O3 pragma restoration). */
s32 func_003a8840(s32 arg0, u8 **arg1)
{
    u8 local[64];
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    u8 *global;
    u8 *work;
    u8 *state;
    u8 *context;
    u8 *packet_data;
    u8 *packet;
    u8 *p;
    u8 *dst;
    s32 *entry;
    u8 *slot;
    u32 i;
    u32 count;
    u32 remainder;
    s32 cached;
    u32 value;
    u64 flags;
    u64 upper;
    u64 qword;
    f32 scale;
    u_long128 packed;

    global = D_008872E0;
    work = *arg1;
    context = *(u8 **)(global + 0x60);
    work = *(u8 **)(work + iGpffffb610);
    state = *(u8 **)(work + 0x9C);
    packet_data = work + 0x50;
    count = *(s32 *)(work + 4);
    value = *(u32 *)(*(u8 **)(state + 0xFC) + 0x10);
    i = (count - 1) / (s32)value;
    remainder = count - i * (s32)value;
    if (*(s32 *)(state + 0xDC) != 0)
    {
        p = *(u8 **)(state + 0x18 + 0x20 * *(s32 *)(state + 0xE4));
        *(s32 *)(p + 0x0) = 0x10000000;
        *(s32 *)(p + 0x8) = 0;
        p = *(u8 **)(state + 0x1C + 0x20 * *(s32 *)(state + 0xE4));
        p += (*(s32 *)(*(u8 **)(state + 0xFC) + 0x18) + 1) * 16 * i;
        *(s32 *)(p + 0x0) = 0x20000000;
        *(s32 *)(p + 0x8) = remainder | 0x04000000;
        *(u8 **)(state + 0x18 + 0x20 * *(s32 *)(state + 0xE4)) = p;
    }
    func_00421a60(0);
    p = global + 0x20;
    dst = local;
    for (i = 8; i > 0; i--)
    {
        *(u32 *)dst = *(u32 *)p;
        *(u32 *)(dst + 4) = *(u32 *)(p + 4);
        p += 8;
        dst += 8;
    }
    entry = *(s32 **)(*(u8 **)(*(u8 **)(work + 0x18) + 0x20));
    work = (u8 *)*entry;
    func_003a2ad0(packet_data, work);
    func_003a29f0(packet_data, work);
    if (func_003f3eb0(0, 0x12) == 0)
        return 0;

    packet = iGpffffb884;
    qword = 0x6C0503EB01000101ULL;
    value = 0x1000000F;
    packed = _pcpyld(qword, value);
    *(u_long128 *)packet = packed;
    sp90 = (f32)(s32)*(u8 *)(state + 0xF4);
    sp94 = (f32)(s32)*(u8 *)(state + 0xF5);
    sp98 = (f32)(s32)*(u8 *)(state + 0xF6);
    sp9C = (f32)(s32)*(u8 *)(state + 0xF7);
    packed = *(u_long128 *)&sp90;
    *(u_long128 *)(packet + 0x10) = packed;
    sp90 = *(f32 *)(packet_data + 0x68);
    sp94 = *(f32 *)(packet_data + 0x6C);
    sp98 = 2.0f * sp90;
    sp9C = 2.0f * sp94;
    packed = *(u_long128 *)&sp90;
    *(u_long128 *)(packet + 0x20) = packed;
    sp98 = (f32)(i + 1);
    sp9C = (f32)remainder;
    sp90 = (-0.25f * (f32)*(s32 *)(context + 0x0C)) * *(f32 *)(global + 0x70);
    sp94 = (-0.25f * (f32)*(s32 *)(context + 0x10)) * *(f32 *)(global + 0x74);
    packed = *(u_long128 *)&sp90;
    *(u_long128 *)(packet + 0x30) = packed;
    *(u_long128 *)(packet + 0x40) = D_0088CB90;
    *(u_long128 *)(packet + 0x50) = D_0088CBA0;
    packed = 0;
    *(u_long128 *)(packet + 0x60) = packed;
    qword = *(u64 *)*(u8 **)(state + 0xFC);
    if ((s32)work != 0)
        qword |= 0x0008000000000000ULL;
    if ((iGpffffabe8 & 0x20) != 0)
        qword |= 0x0010000000000000ULL;
    if (*(s32 *)(packet_data + 0x64) != 0)
        qword |= 0x0020000000000000ULL;
    upper = *(u64 *)(*(u8 **)(state + 0xFC) + 8);
    packed = _pcpyld(upper, qword);
    *(u_long128 *)(packet + 0x70) = packed;
    iGpffffb884 = packet + 0x80;
    scale = ((s32)work != 0) ? 0.0019700117f : 0.0039215689f;
    func_003cc560((u8 *)(entry + 1), scale);

    packet = iGpffffb884;
    packed = _pcpyld(0x5000000600000000ULL, 0);
    *(u_long128 *)(packet + 0x00) = packed;
    packed = _pcpyld(0x0E, 0x1000000000008005ULL);
    *(u_long128 *)(packet + 0x10) = packed;
    packed = _pcpyld(9, *(u64 *)(packet_data + 0xB8));
    *(u_long128 *)(packet + 0x20) = packed;
    packed = _pcpyld(9, *(u64 *)(packet_data + 0xC0));
    *(u_long128 *)(packet + 0x30) = packed;
    packed = _pcpyld(72, *(u64 *)(packet_data + 0xC8));
    *(u_long128 *)(packet + 0x40) = packed;
    packed = _pcpyld(21, *(u64 *)(packet_data + 0xD0));
    *(u_long128 *)(packet + 0x50) = packed;
    packed = _pcpyld(79, *(u64 *)((u8 *)&iGpffffb8c8 - 8));
    *(u_long128 *)(packet + 0x60) = packed;
    cached = *(s32 *)((u8 *)&iGpffffb980 + 8);
    value = *(u32 *)(state + 0xF8);
    p = packet + 0x70;
    if (cached != (s32)value)
    {
        *(s32 *)((u8 *)&iGpffffb980 + 8) = value;
        packed = _pcpyld(0, value | 0x50000000ULL);
        *(u_long128 *)p = packed;
        p += 0x10;
    }
    slot = state + 0x20 * *(s32 *)(state + 0xE4);
    *(u_long128 *)p = *(u_long128 *)slot;
    p += 0x10;
    iGpffffb884 = p;
    func_0042ba20();
    *(s32 *)(p + 0x10) += 1;
    func_0042ba70();
    count = *(s32 *)(p + 0x14);
    *(s32 *)(p + 0x14) = count + 1;
    if (count == 0)
        func_003f36a0((s32)(p + 0x10));
    return 1;
}

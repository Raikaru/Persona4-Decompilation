/* Closest plain-C probe archived before restoring INCLUDE_ASM: saved-register allocation and stack layout remained non-matching (object 888B vs retail 928B; frame 0xD0 vs 0xC0). */
void func_002ba5d0(u8 *arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4, s64 arg5, f32 fparg0)
{
    struct Float4 { f32 x; f32 y; f32 z; f32 w; } src, copy1, copy2;
    struct Float2 { f32 x; f32 y; } pos1, pos2;
    s64 field;
    u8 *object;
    s64 sp60;
    s32 sp6C;
    s32 spBC;
    s32 spB8;
    s16 value;
    s16 pair_index;
    s16 next_index;
    s8 ones;
    s8 tens;
    object = arg0;
    field = arg5;
    sp60 = arg3;
    sp6C = arg4;
    func_002b29e0((u8 *)&src, 88.0f, 17.0f);
    func_002b2970((u8 *)&pos1, *(f32 *)((u8 *)&sp60) + 284.0f, *(f32 *)((u8 *)&sp60 + 4) + 6.0f);
    value = (s16)arg2;
    if ((value == -1) || (value == 0)) { ones = 10; tens = 10; }
    else { ones = (s8)(value % 10); tens = (s8)(value / 10); }
    pair_index = (s16)((s16)arg1 * 2);
    next_index = (s16)(pair_index + 1);
    {
        u8 *digit; u8 *slot; s32 offset;
        offset = (s32)pair_index * 0x220;
        digit = D_0063F1F0 + ((s32)ones * 0x10);
        slot = *(u8 **)(object + 0x38) + offset;
        *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
        *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
        *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
        *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
        copy1 = src;
        *(f32 *)(slot + 0x12C) = pos1.x;
        *(f32 *)(slot + 0x130) = pos1.y;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        spBC = sp6C;
        *(u8 *)(slot + 0x162) = ((u8 *)&spBC)[3];
        *(u8 *)(slot + 0x179) = ((u8 *)&sp6C)[0];
        *(u8 *)(slot + 0x17A) = ((u8 *)&sp6C)[1];
        *(u8 *)(slot + 0x17B) = ((u8 *)&sp6C)[2];
        *(u8 *)(slot + 0x17C) = ((u8 *)&sp6C)[3];
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        *(f32 *)(slot + 0x204) = copy1.x;
        *(f32 *)(slot + 0x208) = copy1.y;
        *(f32 *)(slot + 0x20C) = copy1.z;
        *(f32 *)(slot + 0x210) = copy1.w;
        *(s16 *)(slot + 0x100) = field;
        *(s16 *)(slot + 0x104) = 0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    }
    if ((value >= 10) || (value == 0)) {
        u8 *digit; u8 *slot; s32 offset;
        offset = (s32)next_index * 0x220;
        digit = D_0063F1F0 + ((s32)tens * 0x10);
        slot = *(u8 **)(object + 0x38) + offset;
        *(f32 *)(slot + 0x1F4) = *(f32 *)(digit + 0);
        *(f32 *)(slot + 0x1F8) = *(f32 *)(digit + 4);
        *(f32 *)(slot + 0x1FC) = *(f32 *)(digit + 8);
        *(f32 *)(slot + 0x200) = *(f32 *)(digit + 0xC);
        func_002b2970((u8 *)&pos2, pos1.x - 18.0f, pos1.y);
        copy2 = src;
        *(f32 *)(slot + 0x12C) = pos2.x;
        *(f32 *)(slot + 0x130) = pos2.y;
        *(f32 *)(slot + 0x1A0) = 1.0f;
        *(f32 *)(slot + 0x194) = 1.0f;
        spB8 = sp6C;
        *(u8 *)(slot + 0x162) = ((u8 *)&spB8)[3];
        *(u8 *)(slot + 0x179) = ((u8 *)&sp6C)[0];
        *(u8 *)(slot + 0x17A) = ((u8 *)&sp6C)[1];
        *(u8 *)(slot + 0x17B) = ((u8 *)&sp6C)[2];
        *(u8 *)(slot + 0x17C) = ((u8 *)&sp6C)[3];
        *(s32 *)(slot + 0x1C4) = 0;
        *(f32 *)(slot + 0x108) = fparg0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
        *(f32 *)(slot + 0x204) = copy2.x;
        *(f32 *)(slot + 0x208) = copy2.y;
        *(f32 *)(slot + 0x20C) = copy2.z;
        *(f32 *)(slot + 0x210) = copy2.w;
        *(s16 *)(slot + 0x100) = field;
        *(s16 *)(slot + 0x104) = 0;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) | 1;
    } else {
        u8 *slot; s32 offset;
        offset = (s32)next_index * 0x220;
        slot = *(u8 **)(object + 0x38) + offset;
        *(s16 *)(slot + 0x104) = *(s16 *)(slot + 0x104) & ~1;
    }
}

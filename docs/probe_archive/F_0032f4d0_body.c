/* object 1372B / window 1376B / normalized_diff 921; lane F attempt 2026-09-02.
   Differing offsets: addu operand-order across first six ID stores, saved-register
   allocation (arg0 in $s1 vs retail $s2, loop counter not in $s1), loop prologue
   structure, final tail padding (missing 4B). Residual: register allocation floor
   plus addu-order + loop shape; levers tried: u8 work[0x70] output/colour layout,
   explicit s8 r for func_0032fb60 result, s16 i direct vs n=(s16)i, f20=-14.0f
   set inside 0x1306 block, block-scoped u8 *p, standard pointer arithmetic.
*/

void func_0032f4d0(u8 *arg0)
{
    u8 *obj;
    s16 i;
    f32 f20;
    u8 work[0x70];
    s8 r;

    obj = *(u8 **)(arg0 + 0x38);
    f20 = 0.0f;
    obj[0xB7] = 0;

    *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x169;
    func_002b2970((f2 *)(work + 0x50), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57));
    *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x50);
    obj[0xB7] = (s8)(obj[0xB7] + 1);

    *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x16A;
    func_002b2970((f2 *)(work + 0x48), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57));
    *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x48);
    obj[0xB7] = (s8)(obj[0xB7] + 1);

    if (func_00106330(0x1305) != 0) {
        *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x16B;
        func_002b2970((f2 *)(work + 0x40), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57));
        *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x40);
        obj[0xB7] = (s8)(obj[0xB7] + 1);

        if (func_00106330(0x1306) != 0) {
            *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x16C;
            func_002b2970((f2 *)(work + 0x38), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57 + 20.0f));
            *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x38);
            obj[0xB7] = (s8)(obj[0xB7] + 1);
            f20 = -14.0f;
        }
    }

    *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x16D;
    func_002b2970((f2 *)(work + 0x30), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57) + f20);
    *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x30);
    obj[0xB7] = (s8)(obj[0xB7] + 1);

    *(s16 *)(obj + (s8)obj[0xB7] * 2 + 0xB8) = 0x16E;
    func_002b2970((f2 *)(work + 0x28), 26.0f, (f32)((s8)obj[0xB7] * 0x22 + 0x57) + f20);
    *(f2 *)(work + (s8)obj[0xB7] * 8) = *(f2 *)(work + 0x28);
    obj[0xB7] = (s8)(obj[0xB7] + 1);

    for (i = 0; (s16)i < (s8)obj[0xB7]; i = (s16)(i + 1)) {
        func_003147e0(arg0, (s8)(i + 4), *(s64 *)(work + i * 8), *(s16 *)(obj + i * 2 + 0xB8), i * 2 + 3, 0);
    }
    func_002b2a60(work + 0x6C, 0xC6, 0xEE, 1, 0xFF);
    func_002b2a60(work + 0x68, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2a60(work + 0x64, 0x92, 0xC8, 7, 0xFF);
    r = func_0032fb60((s8)obj[0xB6]);
    func_0032fa30(arg0, r, *(u32 *)(work + 0x6C), *(u32 *)(work + 0x68), *(u32 *)(work + 0x64));

    if (func_00106330(0x1306) != 0) {
        u8 *p;

        func_002b2a60(work + 0x60, 0x29, 0x29, 0x29, 0xFF);
        p = func_002b6150(0x201);
        *(u4 *)(p + 0x85) = *(u4 *)(work + 0x60);
        p = func_002b6150(0x200);
        *(u4 *)(p + 0x85) = *(u4 *)(work + 0x60);
        func_002b2a60(work + 0x5C, 0x61, 0x61, 0x61, 0xFF);
        p = func_002b6150(0x16B);
        *(u4 *)(p + 0x85) = *(u4 *)(work + 0x5C);
        func_002b2a60(work + 0x58, 0x4A, 0x4A, 0x4A, 0xFF);
        p = func_002b6150(0x301);
        *(u4 *)(p + 0x85) = *(u4 *)(work + 0x58);
    }
}

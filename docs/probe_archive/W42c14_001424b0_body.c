// LANE W42c14, func_001424b0, best measured candidate
// object_size: 768, window: 784, normalized_diff: 199 (fndiff 64 differing words)
// differing offsets (from fndiff): prologue 36-48 (move/mov.s order),
//   68-72 (D_005EF6C8 lui/addiu missing address), 80 (func_0046d730 jal target),
//   88 (fGpffff9ce0 GP-rel imm), 160-172 (func_00356170 arg setup order),
//   544-572 (func_0034f2e0 arg order / missing dsll32/dsra32 for arg1 sign-extend),
//   584-724 (func_002751a0 argument scheduling / missing D_005EF6E0/E4 addresses)
// levers tried: 5-arg signature, explicit f32 locals, u8 arg1 parameter,
//   *(u8**) table deref, (s8)arg1 sign-extend, *255/255 for color alpha.
// unresolved: symbol addresses fGpffff9ce0, D_005EF6C8, D_005EF6E0, D_005EF6E4
//   are not in symbol_data_addrs.txt, causing 0-immediate/relocation-less code.
//   prologue move/mov.s scheduling not matching retail.

void func_001424b0(Float2_0014 pos, u8 arg1, u8 *arg2, s32 arg3, f32 fparg0)
{
    extern f32 fGpffff9ce0;
    extern s32 iGpffff9cd8;
    extern f32 D_005EF6E0[];
    extern f32 D_005EF6E4[];
    extern void func_0046d730(const void *file, s32 line);
    extern void func_00356170(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 f0, f32 f1, f32 f2);
    extern void func_0034f2e0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, f32 fparg0, f32 fparg1);
    extern u8 *func_00246980(s16 arg0, s16 arg1);
    extern s32 func_002751a0(f32 x, f32 y, f32 scale, s32 color, s32 chr, s32 id, const char *str, s32 flags, s32 out, s32 charWidth);

    f32 saved_fparg0;
    f32 pos_y;
    f32 color;
    u8 kind;
    Float2_0014 pos2;
    u8 *str;

    saved_fparg0 = fparg0;
    pos_y = pos.y;
    if (arg3 >= 5) {
        func_0046d730(&D_005EF6C8, 0x50F);
    }

    color = fGpffff9ce0;
    pos2.x = 59.0f + pos.x;
    pos2.y = 59.0f + pos_y;
    ((u8 *)&color)[3] = (u8)((*arg2 * 255) / 255);

    func_00356170(*(s64 *)&pos2, *(s32 *)&color, 0x30, 1, saved_fparg0, 59.0f, 0.0f);

    kind = ((u8 *)&iGpffff9cd8)[arg3];
    switch (kind) {
    case 0:
        pos2.x = 26.0f + pos.x;
        pos2.y = (pos_y + 36.0f) - 3.0f - 3.0f;
        break;
    case 2:
        pos2.x = 26.0f + pos.x;
        pos2.y = 36.0f + pos_y;
        break;
    case 1:
        pos2.x = 26.0f + pos.x;
        pos2.y = 36.0f + pos_y;
        break;
    case 4:
        pos2.x = 10.0f + pos.x;
        pos2.y = 36.0f + pos_y;
        break;
    case 3:
        pos2.x = 11.0f + pos.x;
        pos2.y = 36.0f + pos_y;
        break;
    default:
        func_0046d730(&D_005EF6C8, 0x539);
        break;
    }

    func_0034f2e0(*(u8 **)(arg2 + arg3 * 4 + 0x1820), 0x2D, 0x2D, 0x2D, arg1, pos2.x, pos2.y);
    str = func_00246980((s16) kind, *(s16 *)(arg2 + kind * 2 + 0x187E));
    func_002751a0(61.0f + pos.x + D_005EF6E0[arg3 * 2],
                  62.0f + pos_y + D_005EF6E4[arg3 * 2],
                  0.0f,
                  (s8) arg1,
                  8,
                  3,
                  (const char *)str,
                  8,
                  0x6E,
                  -2);
}

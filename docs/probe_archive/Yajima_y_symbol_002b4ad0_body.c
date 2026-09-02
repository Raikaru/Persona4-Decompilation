/* func_002b4ad0 best attempted body
   lane: Yajima_y_symbol
   object: 1244B, window: 1248B
   residual: ~4B (size short by 4B)
   differing words (reloc-masked): 150
   key offsets: branch targets at 108, 172, 184, 284; f12 scheduling around 428
   levers tried:
     - m2c generated body adapted to source types
     - s64 out/coord aggregate copy for func_0025ecd0
     - Vec2 v for second branch
     - goto var_3 pattern (closest: var_3 block matches first branch,
       second branch var_3 block 4B short due to missing nop)
     - m2c exact if/else var_3 pattern (caused s3 spill / 144B frame)
     - direct p[9]/p[0xA] without a/b locals (function shrank to 1220B)
*/
s32 func_002b4ad0(u8 *arg0)
{
    u8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord;
    f32 keep;
    f32 tx;
    f32 ty;
    s32 dx;
    s32 dy;
    u8 a;
    u8 b;
    s8 p8;
    s32 var_3;
    Vec2 v;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s32 *)((u8 *)&D_007E80A8 + p[0xB] * 0x168) == 1) {
        return 0;
    }
    p8 = p[8];
    if (p8 == 0) {
        b = p[0xA];
        a = p[9];
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(a, b) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        } else {
            var_3 = 1;
            goto vtest1;
        }
        var_3 = 0;
vtest1:
        if (var_3 == 1) {
            dx = (s8)(p[9] - func_002b11c0((u8 *)func_0047a2f0(D_007EFA00[0]) + 0x30));
            dy = (s8)(p[0xA] - func_002b1210((u8 *)func_0047a2f0(D_007EFA00[0]) + 0x30));
            *(f32 *)(base + 0) += 17.0f;
            *(f32 *)(base + 4) += 264.0f;
            keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                   func_002b13e0((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150, 18.0f);
            keep += func_002b1260(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            *(f32 *)&out = keep;
            keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                   func_002b1480((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150, 18.0f);
            keep += func_002b1320(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            *((f32 *)&out + 1) = keep;
            if (!(*(f32 *)&out < 1.0f) &&
                (*(f32 *)&out <= 164.0f) &&
                !(*((f32 *)&out + 1) < 248.0f) &&
                (*((f32 *)&out + 1) <= (f32)0x19B)) {
                coord = out;
                func_0025ecd0(
                    *(f32 *)&coord, *((f32 *)&coord + 1), (f32)0xEA65,
                    func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                    func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                    D_00794DB0);
            }
        }
    } else if (p8 == 1) {
        b = p[0xA];
        a = p[9];
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(a, b) == 1) {
                var_3 = 1;
                goto vtest2;
            }
        } else {
            var_3 = 1;
            goto vtest2;
        }
        var_3 = 0;
vtest2:
        if (var_3 == 1) {
            v = *(Vec2 *)p;
            func_0025ecd0(
                v.x, v.y, (f32)0xEA65,
                func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                D_00794CF0);
        }
    }
end:
    return 0;
}

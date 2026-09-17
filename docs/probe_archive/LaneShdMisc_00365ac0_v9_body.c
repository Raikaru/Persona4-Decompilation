/* Lane floor: func_00365ac0 (src/shdMisc.c, retail 00365AC0..00365F00, 1088B).
 * Banked guarded floor (// FUN_00365AC0 NONMATCHING): probe 305 differing
 * words. Reproduce: `python3 tools/probe_variants.py src/shdMisc.c
 * func_00365ac0 --candidate v9=<this body>`; replay with
 * `python3 tools/measure_guarded.py src/shdMisc.c func_00365ac0`.
 * opclass on the banked floor reports no opcode-class surplus (no dsll32,
 * lbu/lhu, cvt, div, jalr, or lui defect): the residual is register
 * coloring/scheduling only.
 *
 * What verifies: frame 0x310, saves s0-s4/f20-f27, ABI
 * (Vec2f by value + s32 color + s32 mode + f32 depth/angle/wid/hgt),
 * plain signed % reproduces the andi/bgez/beqz/addiu -8/-4 chains,
 * sibling-cast extraction, single-statement MAC fuses mula/madd,
 * 364C90-style vertex expressions fuse adda/madd/msub/madd, bltz color
 * conversions with f+f doubling, sibling alpha test, epilogue calls.
 * WALL: global integer-temp allocation (i->$t0 vs freed-$a1 reuse,
 * bits->$a3-a0 vs $t1/$t0/$a3/$a2, mod-temp shift) plus addu-grouped-early
 * int moves (retail daddu, split) plus mula f26-first (retail f25-first)
 * plus color mtc1-hoist. Nine variants tie 304-306; int decl order and
 * nesting do not move allocation; pragmas regress; swapped/sequenced MAC
 * forms do not fuse. Supersedes the nd-705 /var/tmp arch body (its
 * hand-expanded modulo idioms double the loop) and the nd-988 Singles
 * record (same cause). Production stays ASM.
 */

void func_00365ac0(Vec2f position, s32 color, s32 mode, f32 depth, f32 angle, f32 wid, f32 hgt) {
    f32 output[160];
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 pos_x;
    f32 pos_y;
    f32 cos_a;
    f32 zero;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_9;
    s32 temp_8;
    s32 temp_7;
    s32 temp_6;
    s32 i;
    u8 *camera;

    temp_f27 = angle;
    temp_f26 = wid;
    temp_f25 = hgt;
    pos_y = position.y;
    pos_x = position.x;
    temp_f26 = temp_f26 * iGpffff83d4;
    temp_f24 = D_008872F8[0] - depth;
    camera = func_00457120();
    temp_f23 = 1.0f / *(f32 *)(camera + 0x80);
    temp_19 = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    temp_18 = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    temp_17 = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    temp_16 = color & 0xFF;
    temp_f22 = func_0044b7b0(temp_f27);
    cos_a = func_0044b610(temp_f27);
    zero = 0.0f;
    i = 0;
    temp_9 = temp_19 & 1;
    temp_8 = temp_18 & 1;
    temp_7 = temp_17 & 1;
    temp_6 = temp_16 & 1;
    for (; i < 10; i++) {
        s32 mod8a = i % 8;
        s32 mod8b = (i + 6) % 8;
        f32 xh1 = (f32)(((mod8a + 1) % 4) / 2);
        f32 cf1 = (f32)(((u32)((mod8a % 4) ^ 1)) < 1);
        f32 X;
        f32 xh2 = (f32)(((mod8b + 1) % 4) / 2);
        f32 cf2 = (f32)(((u32)((mod8b % 4) ^ 1)) < 1);
        f32 Y;
        f32 *row;
        f32 hh;

        xh1 = temp_f25 * cf1 + temp_f26 * xh1;
        X = (f32)((mod8a < 4) ? 1 : -1) * xh1;
        xh2 = temp_f25 * cf2 + temp_f26 * xh2;
        Y = (f32)((mod8b < 4) ? 1 : -1) * xh2;
        row = &output[i * 16];
        row[0] = (zero + pos_x) + X * cos_a - Y * temp_f22;
        row[1] = (zero + pos_y) + Y * cos_a + X * temp_f22;
        row[2] = temp_f24;
        row[6] = temp_f23;
        if (temp_19 >= 0) {
            row[8] = (f32)(u32)temp_19;
        } else {
            hh = (f32)(((u32)temp_19 >> 1) | temp_9);
            row[8] = hh + hh;
        }
        if (temp_18 >= 0) {
            row[9] = (f32)(u32)temp_18;
        } else {
            hh = (f32)(((u32)temp_18 >> 1) | temp_8);
            row[9] = hh + hh;
        }
        if (temp_17 >= 0) {
            row[10] = (f32)(u32)temp_17;
        } else {
            hh = (f32)(((u32)temp_17 >> 1) | temp_7);
            row[10] = hh + hh;
        }
        if (temp_16 >= 0) {
            row[11] = (f32)(u32)temp_16;
        } else {
            hh = (f32)(((u32)temp_16 >> 1) | temp_6);
            row[11] = hh + hh;
        }
    }
    D_00887300[0](1, 0);
    if (mode != 0 && (temp_16 & 0xFF) == 0xFF) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, output, 10);
    if (mode != 0 && (temp_16 & 0xFF) == 0xFF) {
        iGpffffabe8 &= ~0x80;
    }
}

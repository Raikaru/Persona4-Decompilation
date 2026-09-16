/* FUN_004B2A00 floor (v10, fndiff 17, obj 1016B/window 1024B, UNDER-8B).
 * Dispatch + struct-fill, void(u8*). Frame -336 retail, saves ra+s0-s2+f20.
 * Template: MATCHED neighbor func_004b2780 (same TU) — base=D_00887300,
 * work.packet u8[0xF0]+pad, D_00887310_abs[0], opt_propagation off.
 *
 * WINS:
 * - (u8)float emits retail c.le.s/trunc.w.s/or-0x8000/andi idiom (004bc540
 *   precedent); (s32) emits cvt (wrong here).
 * - opt_common_subs off kills 1.0f-CSE into f21 (diag: 2.0f removes f21).
 * - Manual const-sharing (ck var per 437F group, 3F80 pair) restores lui
 *   reuse that pragma disables; three=3/four=4 vars give li+move / move-a2.
 * - Named u-temp in s1-repeat else defeats nested-speculative-or quirk
 *   (inline expr double-evaluates or + extra bltz; +45 segregation).
 * - Split or two-step + (u32) first step (srl, not sra).
 *
 * WALLS (pure reg-alloc, stop):
 * - or-dest v0-vs-v1 (6 sites: first-convs + 4 repeats). Single-expr, split,
 *   two-temp all give v0; retail reuses srl-dest v1. Global coloring pref.
 * - (u8) conv f-reg f1-vs-f0 (5 rows). Separate div-result var inert.
 * - Stop: three or-levers + f-reg lever inert; residuals only reg identity.
 */
// FUN_004B2A00 floor body (v10, fndiff 17, obj 1016B/window 1024B)
#pragma opt_propagation off
#pragma opt_common_subs off
void func_004b2a00(u8 *arg0) {
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 temp_f20;
    f32 temp_f1_2;
    f32 temp_f1;
    f32 temp_f0;
    f32 f2a;
    f32 f2b;
    f32 f2c;
    f32 f2d;
    s32 ck;
    s32 three;
    s32 four;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 temp_17;
    u8 *temp_18;
    void (**base)(u32, u32);

    temp_2 = *(u16 *)(arg0 + 4);
    if (temp_2 >= 0) {
        temp_f1 = (f32)temp_2;
    } else {
        s32 t2a = ((u32)temp_2 >> 1);
        t2a = t2a | (temp_2 & 1);
        temp_f1 = (f32)t2a;
        temp_f1 += temp_f1;
    }
    temp_2_2 = *(u16 *)(arg0 + 2);
    if (temp_2_2 >= 0) {
        temp_f0 = (f32)temp_2_2;
    } else {
        s32 t2b = ((u32)temp_2_2 >> 1);
        t2b = t2b | (temp_2_2 & 1);
        temp_f0 = (f32)t2b;
        temp_f0 += temp_f0;
    }
    temp_f1 = 255.0f * (1.0f - (temp_f1 / temp_f0));
    var_3 = (u8)temp_f1;
    temp_17 = var_3 & 0xFF;
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 12) + 96);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, (u32)temp_18);
    three = 3;
    base[0](three, three);
    base[0](4, 3);
    temp_f20 = *(f32 *)D_008872FC_abs;
    temp_f1_2 = 1.0f / *(f32 *)(func_00457120() + 132);
    *(s32 *)(work.packet + 0x00) = 0;
    *(s32 *)(work.packet + 0x04) = 0;
    *(f32 *)(work.packet + 0x08) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0x20) = ck;
    *(s32 *)(work.packet + 0x24) = ck;
    *(s32 *)(work.packet + 0x28) = ck;
    if (temp_17 >= 0) {
        f2a = (f32)temp_17;
    } else {
        s32 u2a = ((u32)temp_17 >> 1);
        u2a = u2a | (temp_17 & 1);
        f2a = (f32)u2a;
        f2a += f2a;
    }
    *(f32 *)(work.packet + 0x2C) = f2a;
    *(f32 *)(work.packet + 0x18) = temp_f1_2;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(s32 *)(work.packet + 0x40) = 0;
    *(s32 *)(work.packet + 0x44) = 0x43E00000;
    *(f32 *)(work.packet + 0x48) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0x60) = ck;
    *(s32 *)(work.packet + 0x64) = ck;
    *(s32 *)(work.packet + 0x68) = ck;
    if (temp_17 >= 0) {
        f2b = (f32)temp_17;
    } else {
        s32 u2b = ((u32)temp_17 >> 1);
        u2b = u2b | (temp_17 & 1);
        f2b = (f32)u2b;
        f2b += f2b;
    }
    *(f32 *)(work.packet + 0x6C) = f2b;
    *(f32 *)(work.packet + 0x58) = temp_f1_2;
    *(s32 *)(work.packet + 0x50) = 0;
    *(s32 *)(work.packet + 0x54) = 0x3F800000;
    *(s32 *)(work.packet + 0x80) = 0x44200000;
    *(s32 *)(work.packet + 0x84) = 0;
    *(f32 *)(work.packet + 0x88) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0xA0) = ck;
    *(s32 *)(work.packet + 0xA4) = ck;
    *(s32 *)(work.packet + 0xA8) = ck;
    if (temp_17 >= 0) {
        f2c = (f32)temp_17;
    } else {
        s32 u2c = ((u32)temp_17 >> 1);
        u2c = u2c | (temp_17 & 1);
        f2c = (f32)u2c;
        f2c += f2c;
    }
    *(f32 *)(work.packet + 0xAC) = f2c;
    *(f32 *)(work.packet + 0x98) = temp_f1_2;
    *(s32 *)(work.packet + 0x90) = 0x3F800000;
    *(s32 *)(work.packet + 0x94) = 0;
    *(s32 *)(work.packet + 0xC0) = 0x44200000;
    *(s32 *)(work.packet + 0xC4) = 0x43E00000;
    *(f32 *)(work.packet + 0xC8) = temp_f20;
    ck = 0x437F0000;
    *(s32 *)(work.packet + 0xE0) = ck;
    *(s32 *)(work.packet + 0xE4) = ck;
    *(s32 *)(work.packet + 0xE8) = ck;
    if (temp_17 >= 0) {
        f2d = (f32)temp_17;
    } else {
        s32 u2d = ((u32)temp_17 >> 1);
        u2d = u2d | (temp_17 & 1);
        f2d = (f32)u2d;
        f2d += f2d;
    }
    *(f32 *)(work.packet + 0xEC) = f2d;
    *(f32 *)(work.packet + 0xD8) = temp_f1_2;
    ck = 0x3F800000;
    *(s32 *)(work.packet + 0xD0) = ck;
    *(s32 *)(work.packet + 0xD4) = ck;
    four = 4;
    D_00887310_abs[0](four, work.packet, four);
    base[0](1, 0);
}
#pragma opt_common_subs on
#pragma opt_propagation on

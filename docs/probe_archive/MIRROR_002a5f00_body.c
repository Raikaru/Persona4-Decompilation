// Best body for func_002a5f00 @0x002a5f00 window 1552B
// probe v1_natural: obj 1524/1552 nd=953 MISMATCH (differing words 292, reloc-masked)
// Status: ASM retained; archived per nd>25 gate. Do NOT touch other funcs.
// Shape: func_00452560 base + 002a6b10/7710/6b60/6c30 init, 0x3AC<<16 vs 0x3B4
// compare + func_0043c6a0 + iGpffff8214/8218/821c lerps, two var<7 loops
// (range 0..0x10 with (var!=0&&var!=6)||(u16)0x3B4!=0 guard + three 002a6960 +
// -59+var*0x1A/-152+var*0x5E + 002a7920/002a9f50), 0025f3f0(0.0/131.0/0.0 then
// ints), second loop ==idx||==idx+1 guard, tail 0x3AC+1 + 0x3B8 countdown +
// 0044b7b0 scale + 002a66d0/002a7920 + 002a6e30. Honest types per lh/lhu/lwc1.
// Corrections vs m2c src/generated/code1_002a.c:2803-2892:
// - 6b10/6b60/6c30 third arg is s32 0xFF (m2c 3.57e-43f float bits); 7710 first
//   arg s32 0xFF (m2c float). Prototype ints.
// - 6960 (s32,s32,s32,s32,f32) already correct.
// - 7920 (s32,u8*,s32,s32,u8*,f32,f32,f32,f32) ints-then-floats: m2c correct,
//   kept as (0xFF,base+0x14,temp,0,base,f21,f20,0.0f,1.0f) and tail
//   (0xFF,base+0x14,*(0x3AC),1,base,19.0f,130.0f,0.0f,scale).
// - 9f50 (f32,f32,f32,s32,u8*,s32,s32,u8*) floats-first: m2c scrambled as
//   (0xFF-bits,ptr,temp,0,ptr,f21,f20,5.0-bits); corrected to
//   (f21,f20,5.0f,0xFF,base+0x14,temp,0/1,base) verified against $f12 vs $a0.
// - 5f3f0 (f32,f32,f32,s32,u8,s32,s32,s32,s32) floats-first: m2c scrambled
//   ints-first; corrected to (0.0f,131.0f,0.0f,0xFFFFFF,0xFF,0x22,0,*(0x398),1).
//   Second float is 0x43030000 = 131.0f (not 195.0f).
// - 66d0 (f32x5,s32x3) floats-first: m2c scrambled ints-first; corrected to
//   (72.0f,179.0f,0.0f,124.0f*scale,116.0f*scale,0x2D2D2D,0xFF,1).
// - Lerp else-branch: retail cvt.w.s $f0,$f1 (product) vs m2c var_3=temp_f0
//   (threshold); corrected to ftmp=(fprod<821c)? fdelta*0.5f : fprod, then
//   *(0x3B4)+(s32)ftmp. Threshold load is plain f32 (no (f32)(s32) cast).
// - Tail scale: plain f32 (no (f32)(s32)/(s16) wrappers):
//   1.0f+iGpffff8030*func_0044b7b0(D_00761174*(f32)*(0x3B8)/10.0f).
// - Second loop uses nested if (range { floats; if (==idx||==idx+1) }) to match
//   retail compute-before-equality order; m2c comma-expr collapsed.
// - Plain C float expr only, no asm. No accumulator idiom here (unlike
//   5630/7920 adda.s/madd.s family).
// Residual floor: saved-register rotation (retail p->$s0,s17->$s1,s18->$s2,
// s19->$s3,s20->$s4 + f21/f20; mwcc colors p->$s1 etc., f20/f21 swapped,
// mul operand order, s8-vs-u8 0xFF sign). First diffs at word 45 (move
// $s1 vs $s0) dominate; 292 differing words. Obj 1524 vs 1552 (-28) is codegen
// scheduling, not arity (all 18 calls + 7+7 loops verified). Rotation floor
// persists per existing mc.c note; no further probes per nd>25 gate.
s32 func_002a5f00(s32 arg0) {
    u8 *base;
    s32 shifted;
    s32 cur;
    s32 delta;
    s32 idx;
    s32 fixed;
    s32 temp;
    s32 diff;
    s32 cnt;
    s32 var;
    s32 var2;
    f32 fdelta;
    f32 fprod;
    f32 f21;
    f32 f20;
    f32 scale;
    f32 ftmp;

    (void)arg0;
    base = func_00452560();
    func_002a6b10(0, 0, 0xFF, base);
    func_002a7710(0xFF, base);
    func_002a6b60(0, 0, 0xFF, base);
    func_002a6c30(0, 0, 0xFF, base);
    shifted = *(s32 *)(base + 0x3AC) << 16;
    cur = *(s32 *)(base + 0x3B4);
    if (cur != shifted) {
        delta = shifted - cur;
        if ((f32)func_0043c6a0(delta) <= iGpffff8214 * (f32)shifted) {
            *(s32 *)(base + 0x3B4) = shifted;
        } else {
            fdelta = (f32)delta;
            fprod = iGpffff8218 * fdelta;
            if (fprod < iGpffff821c) {
                ftmp = fdelta * 0.5f;
            } else {
                ftmp = fprod;
            }
            *(s32 *)(base + 0x3B4) = *(s32 *)(base + 0x3B4) + (s32)ftmp;
        }
    }
    idx = *(s32 *)(base + 0x3B4) >> 16;
    fixed = idx << 16;
    var = 0;
    while (var < 7) {
        temp = (idx + var) - 3;
        if (temp >= 0 && temp < 0x10 && ((var != 0 && var != 6) || *(u16 *)(base + 0x3B4) != 0)) {
            func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
            func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
            func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
            diff = fixed - *(s32 *)(base + 0x3B4);
            f21 = -59.0f + (f32)(var * 0x1A) + (f32)(diff * 0x1A) / 65536.0f;
            f20 = -152.0f + (f32)(var * 0x5E) + (f32)(diff * 0x5E) / 65536.0f;
            func_002a7920(0xFF, base + 0x14, temp, 0, base, f21, f20, 0.0f, 1.0f);
            func_002a9f50(f21, f20, 5.0f, 0xFF, base + 0x14, temp, 0, base);
        }
        var++;
    }
    func_0025f3f0(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, *(s32 *)(base + 0x398), 1);
    var2 = 0;
    while (var2 < 7) {
        temp = (idx + var2) - 3;
        if (temp >= 0 && temp < 0x10) {
            diff = fixed - *(s32 *)(base + 0x3B4);
            f21 = -59.0f + (f32)(var2 * 0x1A) + (f32)(diff * 0x1A) / 65536.0f;
            f20 = -152.0f + (f32)(var2 * 0x5E) + (f32)(diff * 0x5E) / 65536.0f;
            if (temp == idx || temp == idx + 1) {
                func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
                func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
                func_002a9f50(f21, f20, 5.0f, 0xFF, base + 0x14, temp, 1, base);
            }
        }
        var2++;
    }
    if (*(s32 *)(base + 0x3AC) + 1 != 0) {
        func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
        cnt = *(s32 *)(base + 0x3B8);
        if (cnt > 0) {
            *(s32 *)(base + 0x3B8) = cnt - 1;
        }
        scale = 1.0f + iGpffff8030 * func_0044b7b0(D_00761174 * (f32)*(s32 *)(base + 0x3B8) / 10.0f);
        func_002a66d0(72.0f, 179.0f, 0.0f, 124.0f * scale, 116.0f * scale, 0x2D2D2D, 0xFF, 1);
        func_002a7920(0xFF, base + 0x14, *(s32 *)(base + 0x3AC), 1, base, 19.0f, 130.0f, 0.0f, scale);
    }
    func_002a6e30(5, -5, 0xFF, base);
    return 1;
}

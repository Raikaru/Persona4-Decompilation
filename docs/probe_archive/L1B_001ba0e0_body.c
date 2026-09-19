/* Re-derived floor 2026-09-19 from m2c (build/m2c/func_001ba0e0.c) + romwright
 * export-c/--types (u8x8 + u32x2 arg0, fGpffff81f4 scale, plain (f32)u32 casts).
 * Replaces BYTE_FLOAT/goto expansion (folded (u32)<0, doubled conversions).
 * fnalign retail 273/object 271 instrs, 31 edits +5 reloc-only, no pure
 * hole/lump >=25 (archived 268/273 with 146 hole vs 119 lump).
 * probe_variants 174 differing words (archived 215).
 * Requires #pragma opt_common_subs off + #pragma opt_propagation off in owner
 * (head match and 39->31); frame 0x20 matches. Open: start-mul $f5 vs $f4 and
 * 255/0.5 vs zero prime scheduling (FPU-color/scheduler floor, `??`-hidden).
 * Production stays ASM. */
s32 func_001ba0e0(u8 *arg0)
{
    extern f32 fGpffff81f4;
    extern u8 *func_00457130(void);
    extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u32 total;
    u32 cur;
    f32 t;
    f32 inv;
    f32 s;
    f32 e;
    f32 m;
    s32 o0;
    s32 o1;
    s32 o2;
    s32 o3;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    if (*(u32 *)(arg0 + 0xC) == 0) {
        u8 *p = func_00457130();
        b0 = p[0];
        b1 = p[1];
        b2 = p[2];
        b3 = p[3];
        arg0[4] = b0;
        arg0[5] = b1;
        arg0[6] = b2;
        arg0[7] = b3;
    }
    total = *(u32 *)(arg0 + 8);
    cur = *(u32 *)(arg0 + 0xC);
    if (cur < total) {
        t = (f32)cur / (f32)total;
        inv = 1.0f - t;
        s = fGpffff81f4 * (f32)arg0[4];
        e = fGpffff81f4 * (f32)arg0[0];
        m = s * inv + e * t;
        o0 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[5];
        e = fGpffff81f4 * (f32)arg0[1];
        m = s * inv + e * t;
        o1 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[6];
        e = fGpffff81f4 * (f32)arg0[2];
        m = s * inv + e * t;
        o2 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        s = fGpffff81f4 * (f32)arg0[7];
        e = fGpffff81f4 * (f32)arg0[3];
        m = s * inv + e * t;
        o3 = ((s32)(m * 255.0f + 0.5f)) & 0xFF;
        func_00457140(o0, o1, o2, o3);
    } else {
        func_00457140(arg0[0], arg0[1], arg0[2], arg0[3]);
        return 1;
    }
    *(u32 *)(arg0 + 0xC) += 1;
    return 0;
}

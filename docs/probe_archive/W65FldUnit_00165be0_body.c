/*
 * Probe archive for func_00165be0 (0x00165be0, window 976B).
 * Best honest candidate (2026-09-17, current tree): obj 968B, 182 differing
 * words (reloc-masked fndiff), 242 vs 241 instrs. Cold reconstruction from the
 * retail window; no usable prior body survived (the recorded nd-133 body was
 * never archived). A 152-word variant of this same body exists but reads
 * *(slot+0x110) where retail reads *(*slot+0x110) (missing lw $v1,($s3)); the
 * banked body below carries the correct double dereference at +1 instruction.
 * Killed this pass (probe_variants, reloc-masked): entry goto-shared-ret1 and
 * whole-rest nesting (189/203, block-reorder cascade); hoisted/split temp base
 * pointers (206/151, still absolute HI/LO); s32[D_007E8BE0]+2 cast-index form
 * (195, +8 kept as load displacement and an extra saved live range);
 * declaration-order reversal (162); count>>1 with lim-hoist (194);
 * scoped opt_common_subs off (199), opt_loop_invariants on (194),
 * opt_propagation off (152, neutral); schedule-on does not compile in the
 * splice harness. Sized extern shadows are rejected by the compiler
 * (int[] -> int[2] redeclaration error), so the gp-relative D_007E8BE8/BE0
 * bases remain the open wall (object uses absolute HI/LO at 6 sites).
 * Open walls: saved rotation (node/j/ptr/j4/base), gp-relative bases, entry
 * beqz+bnez-shared-ret1 polarity, scan-loop ==1 const sinking. Production
 * stays ASM.
 */
s32 func_00165be0(void)
{
    u8* node;
    s32 j;
    u8* ptr;
    s32 j4;
    u8* base;
    s32 i;
    s32 count;
    s32 k;
    s32 v;
    s32 w;
    u16 code;
    void* alc;
    f32 tmp[3];

    if (func_0014a200() == 0)
    {
        return 1;
    }
    if (func_0014a200() == 0)
    {
        return 1;
    }
    for (i = 0; i < 2; i++)
    {
        v = D_007E8BE8[i];
        if (v != 0 && func_004782b0(v) == 0)
        {
            return 0;
        }
        w = *(s32*)(D_007E8BE0 + i * 4);
        if (w != 0 && func_004553c0(w) == 0)
        {
            return 0;
        }
    }
    {
        u8* n2 = func_001452b0(0x11);
        count = 0;
        while (n2 != 0)
        {
            count++;
            n2 = *(u8**)(n2 + 0x138);
        }
    }
    if (count == 0)
    {
        return 1;
    }
    if (count == 0)
    {
        func_0046d730(D_005F1500, 0x965);
    }
    if (count % 2 != 0)
    {
        func_0046d730(D_005F1500, 0x966);
    }
    {
        extern u32 func_003b7060(void);
        j = (s32)(func_003b7060() % (u32)(count / 2));
    }
    {
        u8* sbase = D_007E8BE0;
        for (k = 0; k < 2; k++)
        {
            u8* slot = sbase + k * 16;
            if (*(s32*)slot != 1)
            {
                continue;
            }
            if (*(s32*)(slot + 8) >= 0)
            {
                continue;
            }
            *((s32*)slot + 2) = j + k;
        }
    }
    if (D_007E8BE8[0] >= 0)
    {
        j = D_007E8BE8[0];
    }
    node = func_001452b0(0x11);
    for (k = 0; k < j * 2; k++)
    {
        node = *(u8**)(node + 0x138);
    }
    for (j = 0; j < 2; j++)
    {
        j4 = j * 4;
        base = (u8*)D_007E8BE8 + j4;
        v = *(s32*)base;
        if (v == 0)
        {
            continue;
        }
        code = func_00145780((u16)((0x3FF - j) & 0xFFFF), 3, v);
        func_0014b0c0(code, 1);
        ptr = (u8*)func_00145270(code);
        *(s32*)(ptr + 0x234) = 3;
        if (*(u32*)(D_007E8BE0 + j4) != 0)
        {
            u8* slot;
            slot = D_007E8BE0 + j4;
            alc = DAT_008873F4[0](1, *(u32*)(ptr + 0x28C), 0x40000);
            *(void**)(ptr + 0x288) = alc;
            {
                u8* tp = *(u8**)slot;
                func_0043f810(alc, *(s32*)(tp + 0x110), *(s32*)(ptr + 0x28C));
            }
            func_00454bd0(*(s32*)slot);
            *(s32*)slot = 0;
        }
        {
            s32 r;
            r = func_00478750(*(s32*)(D_007E8BE0 - 0x5C));
            *(s32*)(ptr + 0x22C) = r;
            tmp[0] = tmp[1] = tmp[2] = 30.0f;
            func_0047a1e0((void*)*(s32*)(ptr + 0x22C), tmp, 2);
            func_00478e70(*(u8**)(ptr + 0x22C));
            func_0047a1a0(*(void**)(ptr + 0x164), D_00756510, *(f32*)(node + 0x14C), 2);
            func_0047a180(*(void**)(ptr + 0x164), (void*)(node + 0x140), 2);
            *(s32*)(ptr + 0x294) = func_0018bb20(*(s32*)(ptr + 0x228), ptr);
            node = *(u8**)(node + 0x138);
            *(s32*)base = 0;
        }
    }
    return 1;
}

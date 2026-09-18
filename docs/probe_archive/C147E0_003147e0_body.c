/* C147E0 lane 2026-09-17 func_003147e0 floor: 369 differing words (probe_variants) over 278 fnalign edits, retail 452 vs object 463 instrs (+11, +2.43% PASS 3% rule). First compilable body since the nd-156 body was lost (bare INCLUDE_ASM, m2c seed does not compile). Levers: 11-arg 77d0 extra-arg drop (m2c 12th M2C_ERROR removed), local extern (s16,s64,s16,s32,s64,s32,s64,s64,f32,s16,s32) for 1st/3rd s16 + 6th s32 (saves the per-call dsll32-0 extends, 469->463), v19 reuse for 14ef0 2nd arg, lia share for loop a0/a2, s16 temps for 7750, s32 colour words with lw for 77d0 4th arg, f32 spF0[4] for 29e0 16B + heap swc1 stores. Repro: python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003147e0 --candidate C147E0=docs/probe_archive/C147E0_003147e0_body.c ; python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003147e0 --candidate docs/probe_archive/C147E0_003147e0_body.c --quiet . O3 wrapper measured 389w / 417 vs 449 (-7.1% short, FAIL, not banked). Banked as guarded floor per 3% rule (whatever score). */
void func_003147e0(u8 *arg0, s8 arg1, s64 arg2, s16 arg3, s32 arg4, s32 arg5) {
    extern void func_002b77d0(s16, s64, s16, s32, s64, s32, s64, s64, f32, s16, s32);
    s32 c15C;
    s32 c158;
    s32 c154;
    s32 c150;
    s32 c14C;
    s32 c148;
    s32 c144;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    f32 spF0[4];
    s64 spE8;
    s64 c0;
    u8 *t;
    u8 *h;
    u8 *q;
    u8 *q2;
    u8 *q3;
    u8 *q4;
    u8 *q5;
    u8 **slot;
    s64 v19;
    s64 v23;
    s64 v21;
    s64 v20;
    s64 v30;
    s16 temp_16;
    s16 temp_16_2;
    s16 temp_16_3;
    f32 f20;
    f32 f21;
    s32 i;
    s64 li;
    s64 lia;

    spE8 = arg2;
    t = *(u8 **)(arg0 + 0x38);
    v19 = (s8)arg1;
    c0 = (s16)(v19 * 5 + 0x66);
    v21 = (s16)arg3;
    if (v21 == 0x16C) {
        func_002b2970(&sp128, 67.0f, 175.0f);
        func_00314ef0(arg0, v19, sp128, 0x16C, arg4, arg5);
        return;
    }
    v23 = v19 * 2;
    temp_16 = (s16)(v23 + 0x1F4);
    func_002b7750(temp_16, 0x1AC);
    v20 = (s16)c0;
    v30 = v20 + 2;
    f20 = *((f32 *)&spE8 + 1);
    func_002b2970(&sp120, *(f32 *)&spE8, f20);
    func_002b2a60(&c15C, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16, sp120, 0x1AC, c15C, (s16)v30, arg5, 3, 3, 154.0f, arg4, func_00331560());
    temp_16_2 = (s16)(v23 + 0x1F5);
    func_002b7750(temp_16_2, 0x1AF);
    func_002b2970(&sp130, 258.0f + *(f32 *)&spE8, f20);
    func_002b2a60(&c158, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16_2, sp130, 0x1AF, c158, (s16)v30, arg5, 3, 3, 154.0f, arg4, func_00331560());
    func_002b2970(&sp138, *(f32 *)&sp130 - 28.0f, *((f32 *)&sp130 + 1));
    temp_16_3 = (s16)(v19 + 0x2FB);
    func_002b7750(temp_16_3, 0x131);
    func_002b2970(&sp130, 266.0f + *(f32 *)&spE8, f20);
    func_002b2a60(&c154, 0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(temp_16_3, sp138, 0x131, c154, (s16)(v20 + 3), arg5, 3, 3, 153.0f, arg4, func_00331560());
    func_002b68d0(temp_16_3, 0xE, 0);
    h = func_0046d200(func_00331560(), 0x131);
    slot = (u8 **)(t + v19 * 4 + 0x258);
    q = func_002b81f0(*slot);
    *(f32 *)(q + 0) = *(f32 *)&sp138;
    *(f32 *)(q + 4) = *((f32 *)&sp138 + 1);
    f21 = func_0046b260(h);
    func_002b29e0((u8 *)spF0, f21, func_0046b2f0(h));
    q2 = func_002b81f0(*slot);
    *(f32 *)(q2 + 8) = spF0[0];
    *(f32 *)(q2 + 12) = spF0[1];
    *(f32 *)(q2 + 16) = spF0[2];
    *(f32 *)(q2 + 20) = spF0[3];
    q3 = func_002b81f0(*slot);
    *(s32 *)(q3 + 0x120) = (s32)v20;
    q4 = func_002b81f0(*slot);
    *(f32 *)(q4 + 0x18) = 152.0f;
    q5 = func_002b81f0(*slot);
    *(u8 *)(q5 + 0x124) = 0;
    func_0046d280(h);
    if (v21 == -1) {
        return;
    }
    if (v21 == 0x174) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + *(f32 *)&spE8;
        i = 0;
        while ((s16)i < 2) {
            li = (s64)(s16)i;
            lia = (s16)(li + 0x174);
            func_002b2970(&sp118, f20 + (f32)(li * 0x67), f21);
            func_002b2a60(&c150, 0xCC, 0xFF, 0xFF, 0xFF);
            func_002b77d0((s16)lia, sp118, (s16)lia, c150, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
            i = (s16)(i + 1);
        }
        return;
    }
    if ((func_00106330(0x1305) != 0) && (v21 == 0x160)) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + *(f32 *)&spE8;
        func_002b2970(&sp110, f20, f21);
        func_002b2a60(&c14C, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x160, sp110, 0x160, c14C, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
        func_002b7750(0x2EB, 0x16F);
        func_002b2970(&sp108, 100.0f + f20, f21);
        func_002b2a60(&c148, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x2EB, sp108, 0x16F, c148, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
        return;
    }
    func_002b2970(&sp100, 6.0f + *(f32 *)&spE8, 4.0f + f20);
    func_002b2a60(&c144, 0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0((s16)v21, sp100, (s16)v21, c144, (s16)(v20 + 4), arg5, 3, 3, 152.0f, arg4, func_00331560());
}

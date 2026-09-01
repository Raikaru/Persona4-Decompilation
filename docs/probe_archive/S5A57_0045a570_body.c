void func_0045a570(s16 arg0, void *arg1, u32 arg2, void *arg3, u32 arg4, void *arg5, u32 arg6)
{
    if (func_0045a890() != 0)
    {
        LD16(D_008D3ED2, SLOT_IDX(arg0)) = 999;
    }
    else if (D_008D3ED0[arg0].state == 3)
    {
        func_0046d730((s32)D_00712238, 713);
    }
    LD16(D_008D3EDC, SLOT_IDX(arg0)) = 1;
    LD32(D_008D3ED8, SLOT_IDX(arg0)) = 0;
    LD16(D_008D3ED4, SLOT_IDX(arg0)) = arg0;
    LD16(D_008D3ED2, SLOT_IDX(arg0)) = 999;
    D_008D3ED0[arg0].state = 2;
    LD32(D_008D3EE0, SLOT_IDX(arg0)) = (s32)arg1;
    LD32(D_008D3EE4, SLOT_IDX(arg0)) = (s32)arg3;
    LD32(D_008D3EE8, SLOT_IDX(arg0)) = (s32)arg5;
    LD32(D_008D3EEC, SLOT_IDX(arg0)) = arg2;
    LD32(D_008D3EF0, SLOT_IDX(arg0)) = arg4;
    LD32(D_008D3EF4, SLOT_IDX(arg0)) = arg6;
}
/*
Best measured candidate (re-measured 2026-09-01):
object 448B / retail window 448B; normalized_diff 41 bytes (28 differing words).
Differing word offsets: 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c,
0x70, 0x74, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4,
0xa8, 0xc4, 0xc8, 0xcc, 0xd0, 0xd4, 0xd8, 0xe8.
Ruled out: nested else (same residual); call-result local (same residual);
else-if arm inversion (35 words); explicit index local (101 words);
opt_propagation off (same residual); opt_common_subs off (134 words);
schedule off (same residual); optimization_level 1 (134 words);
optimization_level 3 (90 words); opt_rebuildconditionals off (same residual);
signed/unsigned/typed index spellings (same residual or larger); status local
(same residual). Narrow-unsigned daddiu rule does not apply: target uses signed
16-bit index and addiu constants, with no daddiu instruction.
*/

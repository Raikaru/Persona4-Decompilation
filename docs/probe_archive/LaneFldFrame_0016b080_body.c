/* LaneFldFrame candidate archive: semantic C reconstruction measured non-MATCH; reverted to INCLUDE_ASM pending register-color closure. */
s32 func_0016b080(f32* arg0, f32* arg1, f32* arg2, f32 fparg0)
{
    s32 result;
    s32 v16;
    s32 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    u16 v22;
    s32 i;
    s32 v24;
    s32 v25;
    s32 v26;

    result = 0;
    if ((*(s32*)(iGpffff9db0 + 0x28) != 0) &&
        ((*(u32*)(*(u8**)(iGpffff9db0 + 0x28)) & 1) == 0))
    {
        v16 = 0;
        if ((func_0014a200() == 1) || (func_0014a270() == 1))
        {
            v18 = (s32)func_00457120();
            v19 = (s32)func_003e9700(*(s32*)((u8*)v18 + 4));
            v20 = (s32)((*(f32*)((u8*)v19 + 0x30) + 600.0f) /
                        1200.0f);
            v21 = (s32)((*(f32*)((u8*)v19 + 0x38) + 600.0f) /
                        1200.0f);
            v22 = *(u16*)(func_00155280() + (v21 << 8) +
                          (v20 << 4) + 0x56);
            for (i = (s32)func_001452b0(0xc); i != 0;
                 i = *(s32*)((u8*)i + 0x138))
            {
                if (*(u16*)(u8*)i == v22)
                {
                    v24 = *(s32*)((u8*)i + 0x1a0);
                    v16 = *(s32*)((u8*)v24 + 0x14);
                    if (*(s32*)((u8*)v24 + 0x14) == 0)
                    {
                        v16 = *(s32*)((u8*)v24 + 8);
                    }
                    break;
                }
            }
            result = func_0016abc0((s32)v16, arg0, arg1, arg2, fparg0);
        }
        else
        {
            v25 = *(s32*)(iGpffff9db0 + 0x28);
            v26 = *(s32*)((u8*)v25 + 0x14);
            if (*(s32*)((u8*)v25 + 0x14) == 0)
            {
                v26 = *(s32*)((u8*)v25 + 8);
            }
            result = func_0016abc0(v26, arg0, arg1, arg2, fparg0);
        }
    }
    return result;
}

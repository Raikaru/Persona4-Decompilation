/* LFF2 candidate archive: semantic C reconstruction measured obj 428B/window 480B, normalized_diff 97; reverted to INCLUDE_ASM because compiler register allocation remained mismatched. */
s32 func_0016b080(f32* arg0, s64 arg1, f32* arg2, f32 fparg0)
{
    s32 result;
    s32 v16;
    s32 x;
    s32 z;
    u16 id;

    result = 0;
    if ((*(u8**)(iGpffff9db0 + 0x28) != NULL) &&
        ((*(u32*)*(u8**)(iGpffff9db0 + 0x28) & 1) == 0))
    {
        v16 = 0;
        if ((func_0014a200() == 1) || (func_0014a270() == 1))
        {
            {
                u8* map;
                map = func_003e9700(
                    *(s32*)((u8*)func_00457120() + 4));
                x = (s32)((*(f32*)(map + 0x30) + 600.0f) /
                          1200.0f);
                z = (s32)((*(f32*)(map + 0x38) + 600.0f) /
                          1200.0f);
            }
            id = *(u16*)((u8*)func_00155280() +
                         (z << 8) + (x << 4) + 0x56);
            {
                u8* entry;
                entry = func_001452b0(0xc);
                while (entry != NULL)
                {
                    if (*(u16*)entry == id)
                    {
                        v16 = *(s32*)(*(u8**)(entry + 0x1a0) + 0x14);
                        if (v16 == 0)
                        {
                            v16 = *(s32*)(*(u8**)(entry + 0x1a0) + 8);
                        }
                        break;
                    }
                    entry = *(u8**)(entry + 0x138);
                }
            }
        }
        else
        {
            v16 = *(s32*)(*(u8**)(iGpffff9db0 + 0x28) + 0x14);
            if (v16 == 0)
            {
                v16 = *(s32*)(*(u8**)(iGpffff9db0 + 0x28) + 8);
            }
        }
        result = func_0016abc0(v16, arg0, arg1, arg2, fparg0);
    }
    return result;
}

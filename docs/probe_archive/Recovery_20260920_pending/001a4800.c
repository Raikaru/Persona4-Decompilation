typedef struct {
    u8 pad0[0x1A];
    u16 kind;
    u8 pad1C[0x290 - 0x1C];
    u16 flags;
} ActionState001a4800;

#pragma opt_common_subs off
void func_001a4800(u8 *arg0)
{
    s32 temp_16;
    s32 var_16;
    s32 var_18;
    s32 var_2;
    u16 temp_2;
    u8 *temp_17;
    ActionState001a4800 *temp_4;
    if (((s32)(func_00193cd0(0x506)) == (s32)(0)) && ((s32)(func_00193cd0(0xC05)) == (s32)(0))) {
        var_18 = 0;
        while ((s32)(temp_16 = var_18 & 0xFFFF) < (s32)(*(u16 *)((u8 *)arg0 + 0x6A))) {
            temp_17 = (u8 *)((*(u8 **)((u8 *)(((s32)(arg0) + ((var_18 & 0xFFFF) * 4))) + 0x38)));
            if ((s32)(arg0) == (s32)(temp_17)) {
                goto incr;
            }
            if (!((*(u16 *)((u8 *)(temp_17) + 0x1A)) & 1)) {
                goto incr;
            }
            if (((s32)(func_002428f0((*(u8 **)((u8 *)((*(s32 *)((u8 *)(temp_17) + 0x30))) + 0xA64)), 0)) != (s32)(0))) {
                goto incr;
            }
            if ((*(u16 *)((u8 *)(temp_17) + 0xC)) != 1) {
                goto donecheck;
            }
incr:
            var_18 = (var_18 + 1) & 0xFFFF;
        }
donecheck:
        if (temp_16 == (*( u16*)((u8 *)(arg0) + 0x6A))) {
            if (!((*( u16*)((u8 *)(arg0) + 0x18)) & 4)) {
                func_001eb420((s32)(arg0) + 0x38);
            }
            (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFFD));
            var_16 = 0;
            temp_2 = (u16)((u16)((*( u16*)((u8 *)(arg0) + 0x6C))));
            switch (temp_2) {
            case 1:
            case 2:
            case 3:
                var_16 = 1;
                /* fallthrough */
            case 9:
                func_001f14f0(arg0);
                if ((*( u8*)((u8 *)(func_001a_add_offset(*(u16 *)(arg0 + 0x6E) * 0x28, (s32)iGpffffb3b8)) + 0x24)) == 5) {
                    func_001b0800(arg0, 0x20U);
                } else if ((*( s32*)((u8 *)(arg0) + 0xE8)) == 1) {
                    func_001b0800(arg0, 0x17U);
                } else if ((s32)(func_0019fc70(arg0)) != (s32)(0)) {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFEF));
                    func_001b0800(arg0, 0x10U);
                } else {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 0x10));
                    func_001b0800(arg0, 0x11U);
                }
                break;
            case 7:
            case 8:
            case 11:
                func_001b0800(arg0, 0x19U);
                break;
            case 6:
                if ((s32)((*( u8*)((*( u8**)((u8 *)(arg0) + 0x30)) + 0xA2))) == (s32)(0)) {
                    if ((s32)(func_00106330(0x38)) != (s32)(0)) {
                        var_2 = 5;
                    } else {
                        var_2 = 8;
                    }
                    if (((s32)(func_0010ce10(func_0010a900(var_2 & 0xFFFF), 0x114)) != (s32)(-1)) || ((temp_4 = (ActionState001a4800 *)iGpffffb3ac)->kind == 1 && (temp_4->flags & 2))) {
                        func_00194590(func_001f5f70(arg0, 8, 0, 0, 3), 1);
                        func_00194590(func_001bc920(arg0, 8), 0);
                        func_001b0850(arg0, 0x1D, 0xC);
                    } else {
                        func_001f5bd0(0);
                        func_00194590(func_001f5f70(arg0, 3, 0, 0, 2), 1);
                        func_00194590(func_001f3870((s64 *)arg0, 0U), 1);
                        func_00194590(func_001bc920(arg0, 1), 0);
                        if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
                            func_001b0850(arg0, 0x1B, 0xC);
                        } else {
                            func_001b0850(arg0, 0x20, 0xC);
                        }
                    }
                } else {
                    func_001b0800(arg0, 0x1DU);
                }
                break;
            case 12:
                func_001b0800(arg0, 0x1DU);
                break;
            case 5:
                func_001b0800(arg0, 0x1AU);
                break;
            case 10:
                func_001b0800(arg0, 7U);
                break;
            }
            if ((var_16 != 0) && ((s32)(func_001a0140(arg0)) != (s32)(0))) {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 8));
            } else {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFF7));
            }
            func_0022dc70(arg0);
        }
    }
}
#pragma opt_common_subs on

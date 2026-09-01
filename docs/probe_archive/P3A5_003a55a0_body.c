/* object_size=412 window=416 normalized_diff=15 differing_offsets=262,263,298,299,334,335,370,371,380,381,382,383,384,386,387 classification=register-colouring/operand-order plus shared-exit branch scheduling; ruled_out=callee declarations corrected at block scope (func_003a2bb0 s32*(one arg), func_003f4370 void), mixed parameter count checked (5 args), schedule/no_branch_likely explicit CFG probes, optimization-level probes, switch/if/goto CFG probes, integer-domain address operand-order probes; remaining body branch at offset 380 does not materialize as retail backward shared-exit branch and four address adds use opposite addu operand order */
void func_003a55a0(u8 *arg0, u8 *arg1, s32 *arg2, u8 *arg3, u32 arg4)
{
    extern s32 func_003a2bb0(s32 *arg0);
    extern void func_003f4370(void);
    u32 mask_10000000 = 0x10000000;
    s32 temp_16;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg2 + 0x4C / 4);
    temp_16 = *(s32 *)(temp_17 + 0xE4);
    if (arg4 & mask_10000000) {
        func_003a2bb0(arg2);
    }
    func_003f4370();
#pragma schedule off
    var_3 = ((arg4 & 2) == 2) || ((arg4 & 0x2000) == 0x2000);
    *(s32 *)(arg0 + 8) = var_3;
    var_3_2 = ((arg4 & 0x80) == 0x80) || ((arg4 & 0x80000) == 0x80000);
    *(s32 *)(arg0 + 4) = var_3_2;
    *(s32 *)(arg0 + 0) = 1;
    var_3_3 = ((arg4 & 4) == 4) || ((arg4 & 0x4000) == 0x4000);
    *(s32 *)(arg0 + 0xC) = var_3_3;
#pragma schedule on
    if (*(s32 *)(arg0 + 0) != 0) {
        goto block_0;
    }
dispatch_8:
    if (*(s32 *)(arg0 + 8) != 0) {
        goto block_8;
    }
dispatch_4:
    if (*(s32 *)(arg0 + 4) != 0) {
        goto block_4;
    }
dispatch_c:
    if (*(s32 *)(arg0 + 0xC) == 0) {
        goto dispatch_end;
    } else {
        goto block_c;
    }
dispatch_end:
    goto done;
block_0:
    *(s32 *)(arg0 + 0x10) =
        *(s32 *)((u8 *)((u32)temp_17 + (u32)(temp_16 * 0x24)) + 0x140);
    *(s32 *)(arg0 + 0x14) = 0x10;
    goto dispatch_8;
block_8:
    *(s32 *)(arg0 + 0x20) =
        *(s32 *)((u8 *)((u32)(temp_16 * 0x24) + (u32)temp_17) + 0x150);
    *(s32 *)(arg0 + 0x24) = 4;
    goto dispatch_4;
block_4:
    *(s32 *)(arg0 + 0x18) =
        *(s32 *)((u8 *)((u32)(temp_16 * 0x24) + (u32)temp_17) + 0x15C);
    *(s32 *)(arg0 + 0x1C) = 0x10;
    goto dispatch_c;
block_c:
    *(s32 *)(arg0 + 0x28) =
        *(s32 *)((u8 *)((u32)(temp_16 * 0x24) + (u32)temp_17) + 0x14C);
    *(s32 *)(arg0 + 0x2C) = 8;
    goto dispatch_end;
done:
    ;
}

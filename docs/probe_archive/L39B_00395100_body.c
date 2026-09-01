/* Rejected reconstruction archive: object 388B / window 400B / normalized_diff 294. */
s32 func_00395100(s32 arg0, u32 arg1, u32 arg2)
{
    s32 sp5C;
    s32 sp58;
    register s32 iVar3;
    register u32 *puVar2;
    u32 uVar1;
    s32 iVar4;
    s32 fill;

    iVar3 = arg2 * 0x14;
    iVar4 = arg1 * 8;
    puVar2 = (u32 *)(*(s32 *)(arg0 + 4) + iVar4);
    uVar1 = (u32)(*jtbl_008873E8)(iVar3, 0x30122);
    puVar2[1] = uVar1;
    if (puVar2[1] == 0) {
        sp58 = 0x122;
        sp5C = func_003df590(0x80000013, iVar3);
        func_003df4d0(&sp58);
        return 0;
    }
    func_0043f9c8((void *)puVar2[1], 0, iVar3);
    uVar1 = 0;
    if (arg2 != 0) {
        if (arg2 > 8) {
            iVar4 = 0;
            fill = -1;
            do {
                uVar1 += 8;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x10) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x24) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x38) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x4C) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x60) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x74) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x88) = fill;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x9C) = fill;
                iVar4 += 0xA0;
            } while (uVar1 < arg2 - 8);
        }
        if (uVar1 < arg2) {
            iVar4 = uVar1 * 0x14;
            fill = -1;
            do {
                uVar1 += 1;
                *(s32 *)((u8 *)puVar2[1] + iVar4 + 0x10) = fill;
                iVar4 += 0x14;
            } while (uVar1 < arg2);
        }
    }
    *puVar2 = arg2;
    return arg0;
}

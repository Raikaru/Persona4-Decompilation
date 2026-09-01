/* object 452B/window 464B, normalized_diff 39, differing offsets 292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,376; deficit 3 instructions (12B); classification loop-address CSE/allocator plus global-address materialisation; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, EE-gcc sd/sq floor. Retail prologue saves s3/s2/s1/s0 and frame -0x180; one s32 arg (u8* arg0), local copy target is 0x130 bytes at sp+0x50. Candidate has exact saved-register/frame shape and exact first loop; residual is retail's re-derived `addu $v0,$s2,$s1` / `lw 0x10($v0)` versus candidate's CSE of full slot address into $s2, plus array-global relocation tail. */
// FUN_002774D0
s32 func_002774d0(u8 *arg0)
{
    s32 sp50[0x4C];
    s32 result;
    s32 i;
    s32 found;
    s32 *old_list;
    u8 *manager;
    u8 *obj;
    u8 *slot;

    if (func_00278da0(arg0) != 1)
        func_0046d730(D_0063BE10, 0x525);
    manager = (u8 *)func_00285170(DAT_008817EC_abs);
    if (manager == NULL)
        func_0046d730(D_0063BE10, 0x529);
    result = *(s32 *)(manager + 8);
    obj = func_002776a0(arg0);
    if (manager == NULL || obj == NULL)
        func_0046d730(D_0063BE10, 0x4F4);
    i = 0;
    goto slot_test;
slot_loop:
    slot = manager + i * 4 + 0x10;
    if (*(s32 *)slot == 0) {
        *(u8 **)slot = obj;
        goto slot_done;
    }
    i++;
slot_test:
    if (i < 4)
        goto slot_loop;
    i = -1;
slot_done:
    if (i != 0)
        func_0046d730(D_0063BE10, 0x530);
    found = 0;
    if (i >= 0 || i < 4) {
        i *= 4;
        if (*(s32 *)(manager + i + 0x10) != 0) {
            old_list = *(s32 **)(manager + 0xC);
            if (old_list != NULL) {
                func_0043f810(sp50, old_list, 0x130);
                found = 1;
            }
            *(s32 **)(manager + 0xC) = *(s32 **)(manager + i + 0x10);
            if (found)
                **(s32 **)(manager + 0xC) = sp50[0];
        }
    }
    *(s32 *)DAT_008817E0_abs += 1;
    func_00440b68(D_0063BE60, *(s32 *)(obj + 0x10));
    return result;
}

/* object 324B/window 336B, normalized_diff 24, differing word offsets 36,40,112,116,208,212; best live body uses a named first-argument local and inline second-argument address expressions. Corrected-callee checks: func_003ef650 retail prologue reads $a0 first (lw 8($a0)), confirming owner/name order; existing s32,s32 declaration retained because pointer-typed variants regress. Tried first-argument locals, first-result identity/helper forms, destination locals and liveness/reuse, direct nested calls, explicit argument locals, pointer/address temporaries and struct-field forms, declaration permutations, signed/unsigned/pointer callee prototypes, old-style and variadic declarations, optimization/scheduling/lifetime/compiler-knob probes; all retained the same three addiu/move swaps or regressed the object. */
s32 func_00463100(s32 arg0, u32** arg1)
{
    u32* temp_2_3;
    u32* temp_2_4;
    u32* var_3;
    u32 temp_2_5;
    s32 call_arg0;
    u8* temp_2;
    u8* temp_2_2;

    call_arg0 = func_003ef6d0();
    temp_2 = func_003ef650(call_arg0, (s32)(arg0 + 0x10));
    if (temp_2 != NULL)
    {
        *(s32*)(temp_2 + 0x54) = *(s32*)(temp_2 + 0x54) + 1;
    }
    else
    {
        func_003ef5b0(func_003ef6d0(), arg0);
    }
    call_arg0 = func_003ef6d0();
    temp_2_2 = func_003ef650(call_arg0, arg0 + 0x10);
    func_00440b68(D_00712620, temp_2_2 + 0x10,
                  *(u8*)(temp_2_2 + 0x50), *(s32*)(temp_2_2 + 0x54));
    func_0044ea90(D_00712640, 0x97);
    temp_2_3 = (u32*)D_008873F4[0](1, 0x44, 0x40000);
    func_00442830((char*)temp_2_3, (const char*)(arg0 + 0x10));
    temp_2_4 = *arg1;
    if (temp_2_4 == NULL)
    {
        *arg1 = temp_2_3;
    }
    else
    {
        var_3 = (u32*)((u8*)temp_2_4 + 0x40);
        while ((temp_2_5 = *var_3) != 0)
        {
            var_3 = (u32*)((u8*)temp_2_5 + 0x40);
        }
        *var_3 = (u32)temp_2_3;
    }
    return arg0;
}

void func_0045a570(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    if (func_0045a890() != 0)
    {
        LD16(D_008D3ED2, SLOT_IDX(arg0)) = 999;
    }
    else
    {
        if (D_008D3ED0[arg0].state == 3)
        {
            func_0046d730((s32)D_00712238, 713);
        }
    }
    LD16(D_008D3EDC, SLOT_IDX(arg0)) = 0;
    LD32(D_008D3ED8, SLOT_IDX(arg0)) = 0;
    LD16(D_008D3ED4, SLOT_IDX(arg0)) = arg0;
    LD16(D_008D3ED2, SLOT_IDX(arg0)) = 999;
    D_008D3ED0[arg0].state = 2;
    LD32(D_008D3EE0, SLOT_IDX(arg0)) = arg1;
    LD32(D_008D3EE4, SLOT_IDX(arg0)) = arg3;
    LD32(D_008D3EE8, SLOT_IDX(arg0)) = arg5;
    LD32(D_008D3EEC, SLOT_IDX(arg0)) = arg2;
    LD32(D_008D3EF0, SLOT_IDX(arg0)) = arg4;
    LD32(D_008D3EF4, SLOT_IDX(arg0)) = arg6;
}

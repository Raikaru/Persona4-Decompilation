DatUnitEc* func_00231630(u16 encountId)
{
    u32 stride;
    u32 count;
    u16 i;
    DatUnitEc* ec;
    u16 j;
    u16 k;

    count = 0;
    i = 0;
    stride = (encountId & 0xFFFF) * 0x18;
    {
        EncountTblEntry* entry;

        entry = (EncountTblEntry*)((u8*)gEncountTbl + stride);
        for (; (u32)(i & 0xFFFF) < 5U; i++)
        {
            if (entry->enmIds[i] != 0)
            {
                count = (count + 1) & 0xFFFF;
            }
        }
    }

    func_0044ea90(D_00635928, 0x3F);
    ec = (DatUnitEc*)(*jtbl_008873E8)(0x12C, 0x40000);
    func_0043f9c8(ec, 0, 0x12C);

    ec->base.genus = UNIT_GENUS_EC;
    ec->base.count = count;
    ec->encountId = encountId;
    ec->base.unit = ec->units;

    j = 0;
    for (k = 0; (u32)(k & 0xFFFF) < 5U; k++)
    {
        if (((EncountTblEntry*)((u8*)gEncountTbl + stride))->enmIds[k] != 0)
        {
            func_00231af0(&ec->base.unit[j], UNIT_GENUS_EC, ((EncountTblEntry*)((u8*)gEncountTbl + stride))->enmIds[k]);
            j++;
        }
    }

    return ec;
}


/* object_size=368 window=368 normalized_diff=13 differing_offsets=0x1D,0x31,0x3A,0x5E,0x62,0xCA,0xDD,0xEE,0xEF,0xF2,0x136,0x13A,0x13E; ruled_out: callee census correction (func_0044ea90 const void*); iGpffffb414 GP symbol/address mode; explicit 0x18 stride and pointer preloads in both loops; integer-domain second sum; pointer operand order; declaration permutations; u16 count (372B/nd215); u32 k (360B/nd108); signed encountId (376B/nd260); O1 (384B/nd128); opt_propagation off (392B/nd318); extra pointer local (368B/nd18). Residual is the donor-proven consistent $s0/$s1 saved-register colouring floor; all six siblings remain MATCH. */
#pragma opt_loop_invariants on
DatUnitEc* func_00231630(u16 encountId)
{
    u32 count;
    EncountTblEntry* entry;
    u32 stride;
    u16 i;
    DatUnitEc* ec;
    u16 j;
    u16 k;

    count = 0;
    i = 0;
    stride = (encountId & 0xFFFF) * 0x18;
    entry = (EncountTblEntry*)((u8*)iGpffffb414 + stride);
    for (; (u32)(i & 0xFFFF) < 5U; i++)
    {
        if (entry->enmIds[i] != 0)
        {
            count = (count + 1) & 0xFFFF;
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
        entry = (EncountTblEntry*)((u8*)iGpffffb414 + stride);
        if (entry->enmIds[k] != 0)
        {
            func_00231af0(&ec->base.unit[j], UNIT_GENUS_EC, entry->enmIds[k]);
            j++;
        }
    }

    return ec;
}
#pragma opt_loop_invariants off

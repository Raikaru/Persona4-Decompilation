// FUN_00146A10
void func_00146a10(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    extern u8 D_005EF9D0[];
    extern u8 D_005EF9F0[];



    extern s64 D_005EF990;
    extern f32 D_005EF998;
    extern s64 D_005EF9A0;
    extern f32 D_005EF9A8;
    extern s64 D_005EF9B0;
    extern f32 D_005EF9B8;
    extern s64 D_005EF9C0;
    extern f32 D_005EF9C8;


    f32 spE8;
    s64 spE0;
    f32 spD8;
    s64 spD0;
    f32 spC8;
    s64 spC0;
    f32 spB8;
    s64 spB0;                                       /* compiler-managed */
    u8 sp70[0x40];
    u32 sp30;
    u8 *var_5;
    u8 *var_6;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_4;

        void func_00146f50(void *, void *, void *);
spE0 = D_005EF990;
    spE8 = D_005EF998;
    spD0 = D_005EF9A0;
    spD8 = D_005EF9A8;
    spC0 = D_005EF9B0;
    spC8 = D_005EF9B8;
    spB0 = D_005EF9C0;
    spB8 = D_005EF9C8;
    if (arg0 != NULL) {
        if (arg1 != NULL) {
            (*( f32 *)((u8 *)(arg0) + 4)) = (f32) (*( f32 *)((u8 *)(arg1) + 0));
            (*( f32 *)((u8 *)(arg0) + 8)) = (f32) (*( f32 *)((u8 *)(arg1) + 4));
            (*( f32 *)((u8 *)(arg0) + 0xC)) = (f32) (*( f32 *)((u8 *)(arg1) + 8));
        }
        if (arg2 != NULL) {
            (*( f32 *)((u8 *)(arg0) + 0x10)) = (f32) (*( f32 *)((u8 *)(arg2) + 0));
            (*( f32 *)((u8 *)(arg0) + 0x14)) = (f32) (*( f32 *)((u8 *)(arg2) + 4));
            (*( f32 *)((u8 *)(arg0) + 0x18)) = (f32) (*( f32 *)((u8 *)(arg2) + 8));
        }
        if (arg3 != NULL) {
            (*( f32 *)((u8 *)(arg0) + 0x1C)) = (f32) (*( f32 *)((u8 *)(arg3) + 0));
            (*( f32 *)((u8 *)(arg0) + 0x20)) = (f32) (*( f32 *)((u8 *)(arg3) + 4));
            (*( f32 *)((u8 *)(arg0) + 0x24)) = (f32) (*( f32 *)((u8 *)(arg3) + 8));
        }
        spB0 = (s64)(s32)((*( f32 *)((u8 *)(arg0) + 0x1C)));
        spB8 = (f32)(s32)((*( f32 *)((u8 *)(arg0) + 0x24)));
        temp_4 = (s32) ((*( u16 *)((u8 *)(arg0) + 0)) & 0xFFC00) >> 0xA;
        switch (temp_4) {                           /* irregular */
        case 1:
            temp_17 = (s32)((*( s32 *)((u8 *)(arg0) + 0x164)));
            if (temp_17 == 0) {
                func_00440b68(&D_005EF9D0);
                return;
            }
            func_0047a1a0(temp_17, &spE0, 0, (*( f32 *)((u8 *)(arg0) + 0x14)));
            func_0047a1a0(temp_17, &spD0, 1, (*( f32 *)((u8 *)(arg0) + 0x10)));
            func_0047a1a0(temp_17, &spC0, 1, (*( f32 *)((u8 *)(arg0) + 0x18)));
            func_0047a1e0(temp_17, &spB0, 2);
            func_0047a180((RwMatrix *)temp_17, (const RwV3d *)(arg0 + 4), 2);
            return;
        case 2:
            temp_17_2 = (s32)((*( s32 *)((u8 *)(arg0) + 0x158)));
            if (temp_17_2 == 0) {
                func_00440b68(&D_005EF9D0);
                return;
            }
            func_0047a1a0(temp_17_2, &spE0, 0, (*( f32 *)((u8 *)(arg0) + 0x14)));
            func_0047a1a0(temp_17_2, &spD0, 1, (*( f32 *)((u8 *)(arg0) + 0x10)));
            func_0047a1a0(temp_17_2, &spC0, 1, (*( f32 *)((u8 *)(arg0) + 0x18)));
            func_0047a1e0(temp_17_2, &spB0, 2);
            func_0047a180((RwMatrix *)temp_17_2, (const RwV3d *)(arg0 + 4), 2);
            return;
        case 3:
            temp_17_3 = (s32)((*( s32 *)((u8 *)(arg0) + 0x164)));
            if (temp_17_3 == 0) {
                func_00440b68(&D_005EF9D0);
                return;
            }
            func_0047a1a0(temp_17_3, &spE0, 0, (*( f32 *)((u8 *)(arg0) + 0x14)));
            func_0047a1a0(temp_17_3, &spD0, 1, (*( f32 *)((u8 *)(arg0) + 0x10)));
            func_0047a1a0(temp_17_3, &spC0, 1, (*( f32 *)((u8 *)(arg0) + 0x18)));
            func_0047a1e0(temp_17_3, &spB0, 2);
            func_0047a180((RwMatrix *)temp_17_3, (const RwV3d *)(arg0 + 4), 2);
            return;
        case 6:
            if ((*( s32 *)((u8 *)(arg0) + 0x144)) == 0) {
                func_00440b68(&D_005EF9F0);
                return;
            }
            func_00146f50(&sp30, arg0 + 4, arg0 + 0x10);
            var_6 = (u8 *)&sp30;
            var_5 = sp70;
            var_4 = 8;
            do {
                temp_3 = (s32)((*( s32 *)((u8 *)(var_6) + 0)));
                temp_2 = (s32)((*( s32 *)((u8 *)(var_6) + 4)));
                var_6 += 8;
                var_4 -= 1;
                (*( s32 *)((u8 *)(var_5) + 0)) = temp_3;
                (*( s32 *)((u8 *)(var_5) + 4)) = temp_2;
                var_5 += 8;
            } while (var_4 > 0);
            func_004b12e0((*( s32 *)((u8 *)(arg0) + 0x144)), (u8 *)&sp70);
            return;
        case 10:
            temp_17_4 = (s32)((*( s32 *)((u8 *)(arg0) + 0x144)));
            if (temp_17_4 == 0) {
                func_00440b68(&D_005EF9D0);
                return;
            }
            func_0047a1a0(temp_17_4, &spE0, 0, (*( f32 *)((u8 *)(arg0) + 0x14)));
            func_0047a1a0(temp_17_4, &spD0, 1, (*( f32 *)((u8 *)(arg0) + 0x10)));
            func_0047a1a0(temp_17_4, &spC0, 1, (*( f32 *)((u8 *)(arg0) + 0x18)));
            func_0047a1e0(temp_17_4, &spB0, 2);
            func_0047a180((RwMatrix *)temp_17_4, (const RwV3d *)(arg0 + 4), 2);
            break;
        }
    }

}

/* func_00473b20 DRAFT 298w/177 345/357 4.2% short. Prior nd244 not reproduced. See mdlManager.c draft note; production plain. */
// FUN_00473B20 v2 — reduce float regs, fix lhu/s16, addOff, single-store flags
u8* func_00473b20(u8* layer, u8* arg1, s32 flag)
{
    extern f32 iGpffff8040;
    extern u8 D_00922BC0_abs[];
    extern s32 func_003d5e40(u8* a, f32 b);
    extern void func_003d5e90(void* a, void* b, void* c, f32 d);
    extern void func_003d5840(void* a, void* b);
    extern s32 func_003d5bc0(void* a, f32 b);
    extern void func_00397c40();
    extern void func_00473870(u8* a);
    extern u32 func_00471280(void* a, void* b, void* c, f32 d);
    extern void func_00473000(u8* a, u8* b);
    extern void func_00471370(void* a, void* b, void* c, s32 d);
    extern u32 addOff(u32 offset, u32 base);
    s32 idx;
    u8* table;
    u8* hier;
    u8* hbase;
    f32 delta;

    idx = *(s16*)(layer + 4);
    if (idx < 0) {
        return arg1;
    }
    if (*(u8*)(layer + 2) == 1) {
        table = *(u8**)(layer + 0x34);
        if (table != 0 && idx < *(u16*)(table + 8)) {
            u8* ebase;
            void* entry;
            ebase = *(u8**)table;
            entry = *(void**)(u8*)(addOff((u32)(idx * 80), (u32)(ebase + 0x40)));
            if (entry != 0 && entry != (void*)D_00922BC0_abs) {
                if (*(u32*)(table + 4) != 0) {
                    hier = *(u8**)(layer + 0x20);
                    hbase = *(u8**)(hier + 0x20);
                    func_003d5e40(hbase, *(f32*)(layer + 0x0C) - 1.0f);
                    func_003d5e40(hbase, *(f32*)(layer + 0x0C));
                    func_00473870(layer);
                }
                func_00397c40(*(void**)(layer + 0x20));
            }
        }
        return arg1;
    }
    delta = iGpffff8040 * *(f32*)(layer + 8);
    if ((delta > 0.0f) || ((*(u16*)layer & 6) != 0)) {
        if (*(f32*)(layer + 0x1C) < 1.0f) {
            table = *(u8**)(layer + 0x34);
            if (table != 0 && idx < *(u16*)(table + 8)) {
                u8* ebase2;
                void* e1;
                void* e2;
                s32 idx2;
                ebase2 = *(u8**)table;
                ebase2 = (u8*)(addOff((u32)ebase2, 0) + 0);
                {
                    u8* ab;
                    ab = (u8*)(addOff((u32)(idx * 80), (u32)(*(u8**)table + 0x40)));
                    e1 = *(void**)ab;
                }
                if (e1 != 0 && e1 != (void*)D_00922BC0_abs) {
                    idx2 = *(s16*)(layer + 0x10);
                    if (idx2 < *(u16*)(table + 8)) {
                        {
                            u8* ab2;
                            ab2 = (u8*)(addOff((u32)(idx2 * 80), (u32)(*(u8**)table + 0x40)));
                            e2 = *(void**)ab2;
                        }
                        if (e2 != 0 && e2 != (void*)D_00922BC0_abs) {
                            hier = *(u8**)(layer + 0x20);
                            hbase = *(u8**)(hier + 0x20);
                            func_003d5e90(hbase, *(void**)(layer + 0x24), *(void**)(layer + 0x28), *(f32*)(layer + 0x1C));
                            {
                                f32 nb;
                                nb = *(f32*)(layer + 0x1C) + 1.0f / (f32)*(s16*)(layer + 0x18);
                                *(f32*)(layer + 0x1C) = nb;
                                if (nb >= 1.0f) {
                                    hier = *(u8**)(layer + 0x20);
                                    hbase = *(u8**)(hier + 0x20);
                                    func_003d5840(hbase, **(void***)(layer + 0x28));
                                    {
                                        s32* sf;
                                        sf = *(s32**)(u8*)(addOff((u32)(idx * 80), (u32)(*(u8**)table + 0x4C)));
                                        if (sf == 0) {
                                            hier = *(u8**)(layer + 0x20);
                                            hbase = *(u8**)(hier + 0x20);
                                            func_003d5e40(hbase, delta);
                                        } else {
                                            hier = *(u8**)(layer + 0x20);
                                            hbase = *(u8**)(hier + 0x20);
                                            func_003d5e40(hbase, delta + iGpffff8040 * (f32)*sf);
                                        }
                                    }
                                }
                            }
                            goto clearbit;
                        }
                    }
                }
            }
            *(f32*)(layer + 0x1C) = *(f32*)(layer + 0x1C) + 1.0f / (f32)*(s16*)(layer + 0x18);
        } else {
            table = *(u8**)(layer + 0x34);
            if (table != 0 && idx < *(u16*)(table + 8)) {
                void* e3;
                e3 = *(void**)(u8*)(addOff((u32)(idx * 80), (u32)(*(u8**)table + 0x40)));
                if (e3 != 0 && e3 != (void*)D_00922BC0_abs) {
                    hier = *(u8**)(layer + 0x20);
                    hbase = *(u8**)(hier + 0x20);
                    func_003d5bc0(hbase, delta);
                    goto clearbit;
                }
            }
            if (table == 0 || idx >= *(u16*)(table + 8) || *(void**)(u8*)(addOff((u32)(idx * 80), (u32)(*(u8**)table + 0x40))) != (void*)D_00922BC0_abs) {
                *(f32*)(layer + 0x0C) = *(f32*)(layer + 0x0C) + delta;
            }
        }
clearbit:
        *(u16*)layer &= (u16)0xFFFB;
    }
    {
        table = *(u8**)(layer + 0x34);
        if (table != 0 && idx < *(u16*)(table + 8)) {
            void* e4;
            e4 = *(void**)(u8*)(addOff((u32)(idx * 80), (u32)(*(u8**)table + 0x40)));
            if (e4 != 0 && e4 != (void*)D_00922BC0_abs) {
                if ((*(u16*)layer & 2) != 0 && arg1 != 0) {
                    hier = *(u8**)(layer + 0x20);
                    hbase = *(u8**)(hier + 0x20);
                    {
                        u8* ah;
                        ah = *(u8**)(arg1 + 0x20);
                        func_00471280(hbase, *(void**)(ah + 0x20), hbase, 1.0f);
                    }
                }
                func_00473870(layer);
                if (flag != 0) {
                    if ((*(u16*)layer & 0x10) != 0) {
                        func_00473000(*(u8**)(layer + 0x20), layer);
                    } else if ((*(u16*)(layer + 0x54) & 0x81E0) != 0) {
                        func_00471370(*(void**)(layer + 0x20), layer, layer + 0x54, 0);
                    } else {
                        func_00397c40(*(void**)(layer + 0x20));
                    }
                }
                {
                    u16 f2;
                    f2 = *(u16*)(layer + 0x54);
                    if ((f2 & 0x81E0) != 0) {
                        *(u16*)(layer + 0x54) = f2 | 0x4000;
                    } else {
                        *(u16*)(layer + 0x54) = f2 & (u16)0xBFFF;
                    }
                }
                *(f32*)(layer + 0x0C) = *(f32*)(*(u8**)(*(u8**)(layer + 0x20) + 0x20) + 4);
            }
        }
        return layer;
    }
}

/* object 380B, window 384B, normalized_diff 78; differing offsets 0x40-0x50,0x5C-0x84,0x90-0x7C,0xD8-0x118,0x144-0x15C,0x164-0x174,0x1B0-0x1F4,0x208-0x21C,0x224-0x23C; classification prologue/signature fixed (s0=count,s1=index,s2=array,s3=context), remaining loop declaration/scheduling and redundant count-mask residual; ruled out opt_propagation off (object 396/window384), pointer dereference, global-address and declaration-order probes. */
void func_001d5b20(u8 *arg0) {
    extern u8 *func_00481450(u8 *arg0);
    extern void func_00481440(void *arg0);
    extern u8 *func_00460990(void);
    extern void func_00460ac0(void *arg0, void *arg1);
    extern void func_00485870(s32 arg0);
    extern u8 D_005DC824[];
    extern u8 D_00794AE0[];
    extern u8 D_00794C00[];
    s32 flags;
    u8 *context;
    u8 *array;
    s32 count;
    s32 index;
    u8 *obj;
    flags = *(s32 *)(arg0 + 8);
    if ((flags & 0x400) != 0)
        goto done;
    array = *(u8 **)(arg0 + 0x58);
    index = *(u16 *)(arg0 + 0x54);
    if ((flags & 0x8000) == 0) {
        count = 0;
        index &= 0xFFFF;
        goto first_test;
first_loop:
        obj = *(u8 **)array;
        if (obj != NULL)
            func_00485870((s32)obj);
        count = (count + 1) & 0xFFFF;
        array += 4;
first_test:
        if ((u16)count < index)
            goto first_loop;
        goto done;
    }
    context = func_00481450(arg0);
    func_00481440(D_005DC824);
    obj = func_00460990();
    *(s32 *)(obj + 0) = 0;
    *(s32 *)(obj + 4) = 0;
    *(void (**)(void))(obj + 8) = func_001d5990;
    *(s32 *)(obj + 0x10) = (s32)iGpffffb3ac;
    func_00460ac0(D_00794AE0, obj);
    count = 0;
    index &= 0xFFFF;
    goto second_test;
second_loop:
    obj = *(u8 **)array;
    if (obj != NULL)
        func_00485870((s32)obj);
    count = (count + 1) & 0xFFFF;
    array += 4;
second_test:
    if ((u16)count < index)
        goto second_loop;
    func_00481440(context);
    obj = func_00460990();
    *(s32 *)(obj + 0) = 0;
    *(s32 *)(obj + 4) = 0;
    *(void (**)(void))(obj + 8) = func_001d5ac0;
    *(s32 *)(obj + 0x10) = (s32)iGpffffb3ac;
    func_00460ac0(D_00794C00, obj);
done:
    return;
}

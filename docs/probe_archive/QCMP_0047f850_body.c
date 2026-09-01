/* object_size=420; window=416; normalized_diff=166; differing_offsets=[56,57,58,59,60,61,62,63,78,84,105,110,112,128,144,166]; classification=OBJECT_LARGER_THAN_WINDOW; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; callee callbacks were typed at block scope as InitFunc(u8*,u8*,f32,f32,f32), InitAltFunc(u8*,u8*,f32,f32), and ApplyFunc(u8*,u32), with D_00713220 as block-scope u32[]; frame/signature matched retail at frame=0xA0, s0-s7, f20-f22, mixed args (u8*,u8*,f32,f32,f32); candidate was auto-archived before reordering because object exceeds retail window. */

void func_0047f850(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    typedef u8 *(*InitFunc)(u8 *, u8 *, f32, f32, f32);
    typedef u8 *(*InitAltFunc)(u8 *, u8 *, f32, f32);
    typedef void (*ApplyFunc)(u8 *, u32);
    extern u32 D_00713220[];
    u8 *tbl;
    u16 count;
    u32 i;
    u8 *entry;
    u8 *work;
    u32 j;
    u8 *p0;
    u8 *p1;

    tbl = *(u8 **)(arg0 + 0x50);
    count = *(u16 *)(tbl + 4);
    for (i = 0; i < 4; i++) {
        entry = (u8 *)D_00713220 + i * 0x10;
        if (*(u32 *)(entry + 0xC) != 0) {
            p0 = arg0 + i * 0x10;
            if (*(u32 *)(p0 + 0xC) != 0) {
                p1 = arg1 + i * 0x10;
                if (*(u32 *)(p1 + 0xC) != 0) {
                    work = ((InitFunc)*(u32 *)(entry + 4))(p0, p1, fparg0, fparg1, fparg2);
                    for (j = 0; j < count; j++) {
                        ((ApplyFunc)*(u32 *)(entry + 0xC))(work, *(u32 *)(*(u8 **)tbl + j * 4));
                    }
                } else {
                    work = ((InitAltFunc)*(u32 *)(entry + 8))(p0, arg0 + 0x40, fparg0, fparg2);
                    for (j = 0; j < count; j++) {
                        ((ApplyFunc)*(u32 *)(entry + 0xC))(work, *(u32 *)(*(u8 **)tbl + j * 4));
                    }
                }
            }
        }
    }
}

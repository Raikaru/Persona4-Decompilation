/* object_size=412; window=416; normalized_diff=16; differing_offsets=[74,78,105,110,166,192,193,198,214,230,262,288,289,294,310,326]; classification=MISMATCH; ruled_out=retail has no adda.s/madd.s COP1 accumulator chain, no movz/movn, no standalone MMI, no tail-jump forwarder, and no sd-saved s-register; measured exact setup/branch/loop shape with interleaved mixed signature, split branch work values, s64 callback results, integer table and dispatch addresses, and explicit u16-to-u32 count widening; residual is callee-saved register coloring and inner-index scale after the explicit count temporary. Hex-Rays and Ghidra corpora agree on the four-entry dispatch loop and callback offsets. */
void func_0047f850(u8 *arg0, f32 fparg0, u8 *arg1, f32 fparg1, f32 fparg2)
{
    typedef s64 (*InitFunc)(u8 *, f32, u8 *, f32, f32);
    typedef s64 (*InitAltFunc)(u8 *, f32, u8 *, f32);
    typedef void (*ApplyFunc)(s64, u32);
    extern u32 D_00713220[];
    u32 tbl;
    u32 i;
    u32 j;
    u32 entry;
    tbl = (u32)*(u32 **)((u8 *)arg0 + 0x50);
    {
        u32 count;
        u16 count_raw;

        count_raw = *(u16 *)((u8 *)tbl + 4);
        count = (u32)count_raw;
        i = 0;
        while (i < 4) {
            entry = (u32)D_00713220 + i * 0x10;
            if (*(u32 *)(entry + 0xC) != 0) {
                if (*(u32 *)((u8 *)arg0 + i * 0x10 + 0xC) != 0) {
                if (*(u32 *)((u8 *)arg1 + i * 0x10 + 0xC) != 0) {
                        s64 work1;
                        work1 = ((InitFunc)*(u32 *)(entry + 4))((u8 *)arg0 + i * 0x10, fparg0, (u8 *)arg1 + i * 0x10, fparg1, fparg2);
                        j = 0;
                        while (j < count) {
                            ((ApplyFunc)*(u32 *)(entry + 0xC))(work1, *(u32 *)(*(u32 **)tbl + j * 4));
                            j = (s32)j + 1;
                        }
                    } else {
                        s64 work2;
                        work2 = ((InitAltFunc)*(u32 *)(entry + 8))((u8 *)arg0 + i * 0x10, fparg0, (u8 *)arg0 + 0x40, fparg2);
                        j = 0;
                        while (j < count) {
                            ((ApplyFunc)*(u32 *)(entry + 0xC))(work2, *(u32 *)(*(u32 **)tbl + j * 4));
                            j = (s32)j + 1;
                        }
                    }
                }
            }
            i += 1;
        }
    }
}

/* object_size=292 window=288 normalized_diff=120 differing_words=0x24,0x30,0x40,0x6C-0x108,0x108-0x11C,0x120-0x120,0x128-0x120 classification=oversized/wrong statement order and vtable-address materialization; ruled_out=retail window has no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; corrected block-scope declarations func_00452560(s32)->u8*, func_003f6440(s32,s32), func_0045c870(void*,s32); entry first-touch proves two-argument callback with arg1 in $a1; object exceeded window so archived immediately without further probes.
*/
void func_0020b5b0(u8 *arg0, u8 *arg1)
{
    extern u8 *func_00452560(s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045c870(void *arg0, s32 arg1);
    void (**base)(u32, u32);
    s8 sp2C;
    s8 sp2D;
    s8 sp2E;
    s8 sp2F;

    if (((*(s32 *)func_00452560(*(s32 *)(arg1 + 0x5B0)) & 1) != 0) &&
        (*(u16 *)arg1 != 0) &&
        (*(s16 *)(arg1 + 0x5AC) == -1)) {
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](1, 0);
        sp2C = 0;
        sp2D = 0;
        sp2E = 0;
        sp2F = 0;
        func_0045c870(&sp2C, 0);
    }
}

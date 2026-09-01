/* object_size=508 window=512 normalized_diff=91 differing_offsets=0x74,0x7C-0x94,0x9C-0xD8,0xDC-0xF8,0x100-0xF8 classification=confirmed render-vtable address materialization/compiler floor; retail hoists D_00887300 address into $s1 once (lui/addiu), then each callback emits args and lw/jalr through $s1; MWCC b210 rematerializes the table address and function load per call. Probes: 3-argument ABI (unused arg0; raw first touches $a1/$a2), typed callee declarations, D_00887300 array and D_00887300_abs array aliases, cached table/function-pointer locals, and opt_propagation off inside/outside all retained the rematerialization; outer opt_propagation off produced object 492/nd340. schedule off was separately rejected after regressing 19 sibling functions. ruled_out=retail window has no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature. */
void func_0020aa70(u8 *arg0, u8 *arg1, u8 *arg2)
{
    extern u8 *func_00452560(u8 *arg0);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                               s32 arg8);
    extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1);
    extern void (*D_00887300_abs[])(u32 arg0, u32 arg1);
    u8 *temp_2;
    void (**base)(u32 arg0, u32 arg1);

    temp_2 = func_00452560(*(u8 **)(arg1 + 0x5B0));
    func_002012d0(temp_2, *(f32 *)(arg2 + 0), *(f32 *)(arg2 + 4));
    func_00201650(temp_2, 9, 0x22, 75.0f, (f32)317, 0x1B, 0x1B, 0x1B,
                  0xFF);
    base = D_00887300_abs;
    base[0](6, 1);
    func_002019e0(temp_2, 120.0f);
    func_00201650(temp_2, 9, 0x38, 30.0f, (f32)297, 0x1B, 0x1B, 0x1B,
                  0xFF);
    base[0](6, 0);
    func_002019e0(temp_2, 0.0f);
    if (func_001eb860() != 0) {
        func_00201650(temp_2, 9, 0x18, 100.0f, (f32)411, 0x1B, 0x1B,
                      0x1B, 0xFF);
        func_00201410(temp_2, 9, 0x1C, 100.0f, (f32)411);
        func_00201650(temp_2, 9, 0x1A, 119.0f, (f32)411, 0x1B, 0x1B, 
                      0x1B, 0xFF);
        func_00201410(temp_2, 9, 0x19, 119.0f, (f32)411);
    }
}

/* object 348/window 352/nd 146; differing offsets 28,40,56,92,144-148,150,152,154,156,158,160-161; instruction deficit 1; classification source-shape/register allocation; ruled-outs: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, ee-gcc sd/sq, missing-block deficit, phantom double promotion */
void func_0018a010(s32 arg0)
{
    s32 mode;
    s32 *save;
    s32 *entry;
    u16 index;
    u8 *base;
    u8 *work;

    if (*(s32 *)(func_00155280() + 0x30) != 0) {
        if (arg0 == -1) {
            mode = func_0015a160();
            if (mode == 0) {
                index = 0;
                save = (s32 *)iGpffff9db0;
                if (*save >= 0x28) {
                    base = 0;
                } else {
                    entry = (s32 *)(D_005F51E0 + *save * 4);
                    if (*entry != 0) {
                        index = *(u16 *)((u8 *)*entry + *(save + 1) * 2);
                    }
                    base = D_005F2210 + index * 0x1A;
                }
            } else {
                base = D_005F4090 + mode * 0x23;
            }
        } else {
            base = D_005F2210 + arg0 * 0x1A;
        }
        work = *(u8 **)(*(u8 **)(func_00155280() + 0x30) + 0x38);
        *(u8 **)(work + (*(s32 *)(work + 8) == 0) * 4 + 0x10) = base;
        *(s32 *)(work + (*(s32 *)(work + 8) == 0) * 4 + 0x18) =
            (s32)0xC3210000;
        *(s32 *)(work + 0xC) = 0;
    }
}

/* object_size=280 window=288 normalized_diff=99 differing_offsets=26,30,96,114,116,118,125,126,129,130,134,144,152,154,160,161 classification=register-coloring-and-loop-shape; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register */
// FUN_0036FBE0
s32 func_0036fbe0(s32 arg0)
{
    u16 flag = (u16)arg0;
    u16 r;
    s16 s;
    u16 i;

    if (flag != 0) {
        func_001056e0(1, (s16)func_00104dc0(1));
    } else {
        func_001056e0(1, 1);
    }
    i = 0;
    for (; i < 4; i++) {
        r = (u16)func_00105ee0(i);
        if (r != 0) {
            s = (s16)r;
            if (func_00105610(s) == 0) {
                if (flag != 0) {
                    func_001056e0((s16)r, (s16)func_00104dc0((s16)r));
                } else {
                    func_001056e0(s, 1);
                }
            }
        }
    }
    return 1;
}

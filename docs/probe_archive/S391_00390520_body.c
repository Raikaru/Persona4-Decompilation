/* func_00390520: object 260B / window 352B / normalized_diff 141; differing offsets 38-47, 50-56 (first reported); deficit 23 instructions; classification: undersized GP-field/store-order reconstruction; ruled out: retail frame/prologue exact at 16B, zero saved registers, four-argument func_003e8930 plus five-argument func_003c1ab0/003c8d00/003c2b70 and four-argument func_003c8d30/003c2ba0, no_branch_likely, opt_rebuildconditionals. */
/* measured: GP-field temporaries preserve retail stores before each result
   guard while keeping the single return-value local out of the frame. */
#define P4_GP_FIELD(type, offset) (*(type)((s8 *)saved_reg_gp + (offset)))
void func_00390520(void)
{
    s32 temp;
    extern u8 *saved_reg_gp;
    extern s32 func_003c1ab0();
    extern s32 func_003c2b70();
    extern s32 func_003c2ba0();
    extern s32 func_003c8d00();
    extern s32 func_003c8d30();
    extern s32 func_003e8930();
    extern void func_003901e0();
    extern void func_00390210();
    extern void func_00390230();
    extern void func_00390280();
    extern void func_00390290();
    extern void func_003902d0();
    extern void func_00390350();
    extern void func_00390500();

    temp = func_003e8930(4, 0x11D, func_003901e0, func_00390210);
    P4_GP_FIELD(s32 *, -0x4A3C) = temp;
    if (temp > 0) {
        temp = func_003c1ab0(4, 0x11D, func_00390500, 0, 0);
        P4_GP_FIELD(s32 *, -0x4A38) = temp;
        if (temp > 0) {
            temp = func_003c8d00(4, 0x11D, func_00390280, func_00390230, 0);
            P4_GP_FIELD(s32 *, -0x4A30) = temp;
            if (temp >= 0) {
                temp = func_003c8d30(0x11D, func_00390350, func_003902d0, func_00390290);
            }
            if (temp >= 0) {
                temp = func_003c2b70(4, 0x11D, func_00390280, func_00390230, 0);
                P4_GP_FIELD(s32 *, -0x4A34) = temp;
                if (temp >= 0) {
                    temp = func_003c2ba0(0x11D, func_00390350, func_003902d0, func_00390290);
                }
            }
        }
    }
}
#undef P4_GP_FIELD
